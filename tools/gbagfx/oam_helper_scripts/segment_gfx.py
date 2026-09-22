#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import shlex
import subprocess
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional


# =========================
# CONSTANTS TO EDIT:
# =========================
SPLIT_GFX_PY = Path("../pokepinballrs/tools/gbagfx/oam_helper_scripts/split_gfx.py")
GBAGFX_BIN   = Path("../pokepinballrs/tools/gbagfx/gbagfx")
JSON_FILENAME = "gfx_segments.json"
PYTHON_TOOL = "python3"
# =========================


class ParamParseError(Exception):
    pass


def die(msg: str, code: int = 2) -> None:
    print(f"ERROR: {msg}", file=sys.stderr)
    raise SystemExit(code)


def prompt(text: str, default: Optional[str] = None) -> str:
    if default is None:
        return input(text).strip()
    return (input(f"{text} [{default}]: ").strip() or default)


def prompt_yes_no(text: str, default_yes: bool = True) -> bool:
    default = "Y/n" if default_yes else "y/N"
    while True:
        ans = input(f"{text} ({default}): ").strip().lower()
        if not ans:
            return default_yes
        if ans in ("y", "yes"):
            return True
        if ans in ("n", "no"):
            return False
        print("Please answer y or n.")


def load_json(path: Path) -> Any:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except FileNotFoundError:
        return None
    except json.JSONDecodeError as e:
        die(f"Failed to parse JSON: {path}\n{e}")


def save_json(path: Path, data: Any) -> None:
    tmp = path.with_suffix(path.suffix + ".tmp")
    tmp.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    tmp.replace(path)


def sanitize_segment_name(name: str) -> str:
    name = name.strip()
    if not name:
        raise ValueError("empty name")

    name = name.replace(" ", "_")
    name = re.sub(r"[^A-Za-z0-9._-]+", "", name)
    name = name.strip("._-")
    if not name:
        raise ValueError("name becomes empty after sanitizing")
    return name


def parse_params_line(line: str, workdir: Path) -> tuple[List[str], Dict[str, Any], bool]:
    """
    Accepts shorthand:
      -o  -> -oam
      -w  -> -width
      -mh -> -mheight
      -mw -> -mwidth
      -p  -> -palette
      -s  -> -oamshape

    Also accepts the long form.
    Outputs:
      (gbagfx_args_long, json_fields)
    """
    tokens = shlex.split(line)
    if not tokens:
        return [], {}

    palette_was_selected = False
    
    flag_map = {
        "-o": "-oam",
        "-oam": "-oam",
        "-w": "-width",
        "-width": "-width",
        "-mh": "-mheight",
        "-mheight": "-mheight",
        "-mw": "-mwidth",
        "-mwidth": "-mwidth",

        "-p": "-palette",
        "-palette": "-palette",
        "-s": "-oamshape",
        "-oamshape": "-oamshape",
    }

    int_flags = {"-width", "-mheight", "-mwidth"}

    out_args: List[str] = []
    json_fields: Dict[str, Any] = {}

    i = 0
    while i < len(tokens):
        t = tokens[i]
        if t not in flag_map:
            raise ParamParseError(f"Unrecognized token: {t}")

        long_flag = flag_map[t]

        # boolean
        if long_flag == "-oam":
            out_args.append("-oam")
            json_fields["oam"] = True
            i += 1
            continue

        # int-valued flags
        if long_flag in int_flags:
            if i + 1 >= len(tokens):
                raise ParamParseError(f"Missing value after {t}")
            v = tokens[i + 1]
            try:
                v_int = int(v, 10)
            except ValueError:
                raise ParamParseError(f"Value for {t} must be an integer, got: {v}")

            out_args.extend([long_flag, str(v_int)])
            if long_flag == "-width":
                json_fields["width"] = v_int
            elif long_flag == "-mheight":
                json_fields["mheight"] = v_int
            elif long_flag == "-mwidth":
                json_fields["mwidth"] = v_int

            i += 2
            continue

        # palette (string; may be omitted → choose)
        if long_flag == "-palette":
            palette_value: Optional[str] = None

            # If next token exists AND is not another recognized flag, treat it as the palette filename.
            if i + 1 < len(tokens) and tokens[i + 1] not in flag_map:
                palette_value = tokens[i + 1]
                i += 2
            else:
                # No value provided (or next token is another flag) → prompt selection
                chosen = choose_palette_in_dir(workdir)
                palette_value = chosen.name
                palette_was_selected = True
                i += 1

            out_args.extend(["-palette", palette_value])
            json_fields["palette"] = palette_value
            continue
            
        if long_flag == "-oamshape":
            shape_file: str = None
            if i + 1 < len(tokens) and tokens[i + 1] not in flag_map:
                shape_file = tokens[i + 1]
                i += 2
            else:
                raise ParamParseError(f"Missing value after {t}")
            
            out_args.extend([long_flag, shape_file])
            json_fields["oamshape"] = shape_file
            continue

        raise ParamParseError(f"Unhandled flag: {t}")


    return out_args, json_fields, palette_was_selected


def run_cmd_safe(cmd: List[str], cwd: Path, label: str) -> bool:
    """
    Runs a command. If it fails, prints stdout/stderr and returns False (so caller can retry).
    """
    try:
        p = subprocess.run(
            cmd,
            cwd=str(cwd),
            check=False,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
    except FileNotFoundError as e:
        print(f"\n[{label}] ERROR: executable not found: {e}")
        return False
    except Exception as e:
        print(f"\n[{label}] ERROR: {e}")
        return False

    if p.returncode == 0:
        return True

    print(f"\n[{label}] Command failed with exit code {p.returncode}.")

    if p.stdout.strip():
        print(f"\n[{label}] stdout:\n{p.stdout.rstrip()}")
    if p.stderr.strip():
        print(f"\n[{label}] stderr:\n{p.stderr.rstrip()}")

    return False

def remove_args_palette(args: List[str], fields: Dict[str, Any]) -> None:
    fields.pop("palette", None)
    i = 0
    while i < len(args):
        if args[i] == "-palette":
            # remove "-palette" and its value if present
            del args[i:i+2]
            return
        i += 1

def set_args_palette(args: List[str], fields: Dict[str, Any], palette_name: str) -> None:
    fields["palette"] = palette_name
    i = 0
    while i < len(args):
        if args[i] == "-palette":
            if i + 1 < len(args):
                args[i + 1] = palette_name
            else:
                args.extend([palette_name])
            return
        i += 1
    args.extend(["-palette", palette_name])

def ensure_files_entry(root: Dict[str, Any], gfx_filename_base: str) -> Dict[str, Any]:
    files = root.get("files")
    if files is None:
        root["files"] = []
        files = root["files"]
    if not isinstance(files, list):
        die('"files" must be a list in JSON.')

    for entry in files:
        if isinstance(entry, dict) and entry.get("gfx_filename") == gfx_filename_base:
            entry.setdefault("segments", [])
            if not isinstance(entry["segments"], list):
                die(f'Entry for gfx_filename "{gfx_filename_base}" has non-list "segments".')
            return entry

    new_entry = {"gfx_filename": gfx_filename_base, "segments": []}
    files.append(new_entry)
    return new_entry


def reset_json_barebones(existing: Optional[Dict[str, Any]], base_name: str) -> Dict[str, Any]:
    """
    Reset JSON to required base structure with header and empty segments.
    """

    # Default header structure
    root: Dict[str, Any] = {
        "kind": "gfx-config",
        "version": 1,
        "defaults": {
            "mwidth": 0,
            "mheight": 0,
            "oam": False,
            "width": 16,
            "palette": ""
        },
        "files": [
            {
                "gfx_filename": base_name,
                "segments": []
            }
        ]
    }

    # preserve selected fields
    if isinstance(existing, dict):
        preserve_keys = ["version", "defaults"]

        for key in preserve_keys:
            if key in existing:
                root[key] = existing[key]
            
    return root


def choose_4bpp_in_dir(workdir: Path) -> Path:
    candidates = sorted(workdir.glob("*.4bpp"))
    if not candidates:
        die(f"No .4bpp files found in working folder: {workdir}")

    if len(candidates) == 1:
        print(f"Found one .4bpp: {candidates[0].name}")
        return candidates[0]

    print("Select a .4bpp file:")
    for idx, p in enumerate(candidates, start=1):
        print(f"  {idx}) {p.name}")
    while True:
        s = prompt("Selection? ")
        try:
            n = int(s, 10)
        except ValueError:
            print("Please enter a number.")
            continue
        if 1 <= n <= len(candidates):
            return candidates[n - 1]
        print("Out of range.")

def choose_palette_in_dir(workdir: Path) -> Path:
    candidates = sorted(workdir.glob("*.gbapal")) + sorted(workdir.glob("*.pal"))
    if not candidates:
        die(f"No palette files (*.gbapal or *.pal) found in working folder: {workdir}")

    if len(candidates) == 1:
        print(f"Found one palette: {candidates[0].name}")
        return candidates[0]
    
    def palette_sort_key(p: Path):
        """
        Sort by trailing _number if present.
        e.g. foo_12.gbapal → 12
        If not present, sort alphabetically after numbered ones.
        """
        stem = p.stem  # filename without extension
        m = re.search(r"_(\d+)$", stem)
        if m:
            return (0, int(m.group(1)))  # numbered files first, sorted numerically
        return (1, stem.lower())         # then non-numbered, alphabetical

    candidates.sort(key=palette_sort_key)

    print("Select a palette file:")
    for idx, p in enumerate(candidates, start=0):
        print(f"  {idx}) {p.name}")

    while True:
        s = prompt("Selection? ")
        try:
            n = int(s, 10)
        except ValueError:
            print("Please enter a number.")
            continue
        if 0 <= n <= len(candidates)-1:
            return candidates[n]
        print("Out of range.")

def main() -> None:
    ap = argparse.ArgumentParser(
        description="Interactive tool: split a .4bpp tileset into named PNG segments and record them into a fixed JSON file in the working folder."
    )
    ap.add_argument("--workdir", "-d", type=str, default=".", help="Working folder (default: current directory).")
    ap.add_argument("--input", "-i", type=str, default=None, help="Optional: specify the .4bpp file; otherwise pick from workdir.")
    ap.add_argument("--unique-start", type=int, default=1, help="Initial unique number (default: 1).")
    args = ap.parse_args()

    workdir = Path(args.workdir).expanduser().resolve()
    if not workdir.exists() or not workdir.is_dir():
        die(f"Working folder not found: {workdir}")

    # Validate constants
    if not SPLIT_GFX_PY.exists():
        die(f"SPLIT_GFX_PY not found: {SPLIT_GFX_PY}")
    if not GBAGFX_BIN.exists():
        die(f"GBAGFX_BIN not found: {GBAGFX_BIN}")

    base_4bpp = Path(args.input).expanduser().resolve() if args.input else choose_4bpp_in_dir(workdir)
    if not base_4bpp.exists():
        die(f"Input .4bpp not found: {base_4bpp}")

    base_name = base_4bpp.stem  # "*base*"
    json_path = workdir / JSON_FILENAME

    existing = load_json(json_path)
    if existing is None:
        print(f"\nJSON does not exist yet: {json_path.name}")
        root = reset_json_barebones(None, base_name)
        save_json(json_path, root)
        print("Created new bare-bones JSON.")
    else:
        print(f"\nUsing JSON file: {json_path.name}")
        if prompt_yes_no("Continue using the current JSON contents?", default_yes=True):
            if not isinstance(existing, dict):
                die("Existing JSON must be a top-level object/dict.")
            root = existing
        else:
            root = reset_json_barebones(existing if isinstance(existing, dict) else None, base_name)
            save_json(json_path, root)
            print("Wiped JSON down to bare-bones structure.")

    file_entry = ensure_files_entry(root, base_name)

    unique = args.unique_start
    suggested_skip = 0
    last_take = 9999
    last_params = "-w 32"

    print("\n--- Interactive segmenting ---")
    print(f"Workdir: {workdir}")
    print(f"Base:    {base_name}")
    print(f"Input:   {base_4bpp.name}")
    print(f"JSON:    {json_path.name}")
    print("Parameter Shorthand:\n -o (-oam), -mh (-mheight), -mw (-mwidth), -w (-width), -p (-palette), -s (-oamshape)")
    print("Tip: Press Enter at skip_count to use the suggested next base.")
    print("     Use -p without a file to see available options.\n")

    while True:
        # Step 1 - Parameter entry
        skip_in = prompt("Skip Tiles", default=str(suggested_skip))
        try:
            skip_count = int(skip_in, 10)
        except ValueError:
            print("Skip must be an integer.\n")
            continue

        take_in = prompt("Take", default=str(last_take))
        try:
            take_count = int(take_in, 10)
            last_take = take_count
        except ValueError:
            print("Take must be an integer.\n")
            continue

        param_line = prompt("gbagfx parameters", default=str(last_params))
        try:
            gbagfx_args, json_fields, palette_selected = parse_params_line(param_line, workdir)
            last_params = param_line
        except ParamParseError as e:
            print(f"Bad parameters: {e}\n")
            continue

        # Step 2 - Process graphic using params
        seg_stub_unique = f"{base_name}_{unique}"
        out_4bpp_unique = workdir / f"{seg_stub_unique}.4bpp"
        out_png_unique = workdir / f"{seg_stub_unique}.png"

        ok_split = run_cmd_safe(
            [PYTHON_TOOL, str(SPLIT_GFX_PY), str(base_4bpp), str(unique), str(skip_count), str(take_count)],
            cwd=workdir,
            label="split",
        )
        
        if not ok_split:
            print("\nReturning to step 1.\n")
            continue

        # Step 3 - Convert/check, with Step 4 palette selection loop
        while True:
            ok_gfx = run_cmd_safe(
                [str(GBAGFX_BIN), str(out_4bpp_unique), str(out_png_unique), *gbagfx_args],
                cwd=workdir,
                label="gbagfx",
            )
            if not ok_gfx:
                print("\nReturning to step 1.\n")
                break  # breaks convert loop -> then outer continues (see below)

            print(f"\nWrote: {out_png_unique.name}")

            if palette_selected:
                print("Verify output: [y]=accept  [n]=retry-from-scratch  [r]=retry with different palette [x]=convert without palette")
                choice = input("Choice: ").strip().lower()

                if choice == "y":
                    # accept -> proceed to naming/JSON steps
                    accepted = True
                    break
                elif choice == "r":
                    # retry gbagfx with different palette (chooser)
                    pal = choose_palette_in_dir(workdir).name
                    set_args_palette(gbagfx_args, json_fields, pal)
                    continue
                elif choice == "x":
                    # convert without palette. (gray scale) 
                    remove_args_palette(gbagfx_args, json_fields)
                    ok_gfx = run_cmd_safe(
                        [str(GBAGFX_BIN), str(out_4bpp_unique), str(out_png_unique), *gbagfx_args],
                        cwd=workdir,
                        label="gbagfx",
                    )
                    accepted = True
                    break
                else:
                    # blank or anything else -> from scratch
                    accepted = False
                    break
            else:
                # normal behavior: yes/no. If no -> from scratch
                ok = prompt_yes_no("Does the output look good?", default_yes=True)
                if ok:
                    accepted = True
                    break
                accepted = False
                break
            
        # cleanup .4bpp file 
        if out_4bpp_unique.exists():
            try:
                out_4bpp_unique.unlink()
            except Exception as e:
                print(f"Warning: failed to remove intermediate file: {e}")
        
        if "accepted" not in locals() or not accepted:
            # Retry from scratch -> keep unique
            continue

        # Accepted: proceed to naming/JSON steps...
        # Step 5 - prompt name entry/rename
        while True:
            raw_name = prompt("What is it? (filename):")
            try:
                seg_name = sanitize_segment_name(raw_name)
            except ValueError as e:
                print(f"Invalid name: {e}\n")
                continue

            seg_stub_named = f"{base_name}_{seg_name}"
            out_png_named = workdir / f"{seg_stub_named}.png"

            if out_png_named.exists():
                overwrite = prompt_yes_no(
                    f"{seg_stub_named}.png already exists. Overwrite?",
                    default_yes=False,
                )
                if not overwrite:
                    print("Enter a different name.\n")
                    continue

                # user chose to overwrite
                try:
                    out_png_named.unlink()
                except Exception as e:
                    print(f"Failed to remove existing file: {e}")
                    continue

            # If we get here, name is valid and either:
            # - file doesn't exist
            # - or user approved overwrite
            break

        out_png_unique.replace(out_png_named)

        # Step 6 - update json file
        seg_entry: Dict[str, Any] = {"segfile": seg_stub_named, **json_fields}
        file_entry["segments"].append(seg_entry)
        save_json(json_path, root)

        # Step 7 - prompt next segment, with precalculated next skip.
        suggested_skip = skip_count + take_count
        print(f"\nSaved segment: {seg_stub_named}. Next suggested base (skip_count): {suggested_skip}\n")

        unique += 1
        if not prompt_yes_no("Continue with another segment?", default_yes=True):
            print("Done.")
            return


if __name__ == "__main__":
    main()
