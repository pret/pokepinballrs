#!/usr/bin/env python3
import argparse, json, shlex, subprocess, sys
from pathlib import Path
from fnmatch import fnmatch

def posix(s: str) -> str:
    return s.replace("\\", "/")

def load_cfg(path: Path) -> dict:
    with open(path, "r", encoding="utf-8") as f:
        cfg = json.load(f)
    if cfg.get("kind") != "gfx-config":
        raise SystemExit(f"{path} is not a gfx-config (missing kind: 'gfx-config').")
    cfg.setdefault("defaults", {})
    cfg.setdefault("rules", [])
    cfg.setdefault("files", [])
    return cfg

# REPLACE your effective_opts() with this version
def effective_opts(cfg: dict, fbase: str, overlay: dict | None = None) -> dict:
    """Layer defaults -> matching rules -> exact file entry -> optional overlay.
       Special rule applies at file level and overlay level:
       - if the object sets 'mwidth' but not 'width', drop any inherited 'width'.
    """
    # 1) start with defaults
    opts = dict(cfg.get("defaults", {}))

    # 2) apply matching rules in order
    from fnmatch import fnmatch
    for r in cfg.get("rules", []):
        hit = ("glob" in r and fnmatch(fbase, r["glob"])) or ("prefix" in r and fbase.startswith(r["prefix"]))
        if hit:
            for k, v in r.items():
                if k not in ("glob", "prefix"):
                    opts[k] = v

    # 3) apply exact file entry (capture presence of keys)
    file_entry = None
    for e in cfg.get("files", []):
        if e.get("gfx_filename") == fbase:
            file_entry = e
            for k, v in e.items():
                if k != "gfx_filename":
                    opts[k] = v
            break

    # 4) file-level special case
    if file_entry is not None and ("mwidth" in file_entry) and ("width" not in file_entry):
        opts.pop("width", None)

    # 5) segment/overlay overrides (if any)
    if overlay:
        for k, v in overlay.items():
            opts[k] = v
        # overlay-level special case
        if ("mwidth" in overlay) and ("width" not in overlay):
            opts.pop("width", None)

    return opts

def build_cmd(tool: Path, fbase: str, direction: str, opts: dict):
    f4 = fbase + ".4bpp"
    fp = fbase + ".png"
    if direction == "to-png":
        src, dst = f4, fp
    else:
        src, dst = fp, f4

    cmd = [str(tool), src, dst]

    mwidth  = int(opts.get("mwidth", 0) or 0)
    mheight = int(opts.get("mheight", 0) or 0)
    oam     = bool(opts.get("oam", False))
    width   = int(opts.get("width", 0) or 0)
    palette = str(opts.get("palette", "") or "").strip()

    if mwidth:  cmd += ["-mwidth", str(mwidth)]
    if mheight: cmd += ["-mheight", str(mheight)]
    if oam:     cmd += ["-oam"]

    if direction == "to-png":
        if width:   cmd += ["-width", str(width)]
        if palette: cmd += ["-palette", palette]

    return cmd, src, dst

def main():
    ap = argparse.ArgumentParser(description="Run gfx converter over files listed in a gfx JSON.")
    ap.add_argument("tool", help="Path to the conversion tool (same as $(GFX) in your Makefile)")
    ap.add_argument("config", help="Path to a gfx JSON (kind: gfx-config)")
    ap.add_argument("--direction", choices=["to-png","to-4bpp"], default="to-png",
                    help="Conversion direction (default: to-png = .4bpp -> .png)")
    ap.add_argument("--only", action="append", default=[],
                    help="Limit to specific base path(s) (repeatable). Example: graphics/ui/healthbar")
    ap.add_argument("--dry-run", action="store_true", help="Print commands without executing")
    ap.add_argument("--fail-fast", action="store_true", help="Stop on first error")
    args = ap.parse_args()

    tool = Path(args.tool)
    cfg_path = Path(args.config)
    cfg = load_cfg(cfg_path)
    io_base = cfg_path.parent


    # build worklist (supports per-file segments)
    work = []  # each item: (target_id, fbase_for_io, opts)
    for e in cfg["files"]:
        if "gfx_filename" not in e:
            continue
        f = posix(e["gfx_filename"])
        segs = e.get("segments")
        if isinstance(segs, list) and segs:
            for seg in segs:
                if not isinstance(seg, dict):
                    continue
                sid = seg.get("segfile")
                if not sid:
                    continue
                f_aug = f"{f}_{sid}"
                overlay = {k: v for k, v in seg.items() if k != "segfile"}
                opts = effective_opts(cfg, f, overlay=overlay)
                f_aug = f"{io_base}/{f_aug}"
                work.append((f_aug, f_aug, opts))
        else:
            opts = effective_opts(cfg, f)
            f = f"{io_base}/{f}"
            work.append((f, f, opts))

    # optional --only filter (now matches the augmented id like graphics/foo_a)
    if args.only:
        only = set(posix(s) for s in args.only)
        work = [item for item in work if item[0] in only]

    if not work:
        print("No files to process.", file=sys.stderr)
        return 1

    failures = 0
    for _, fbase_eff, opts in work:
        cmd, src, dst = build_cmd(tool, fbase_eff, args.direction, opts)

        print("$", " ".join(shlex.quote(c) for c in cmd))
        if args.dry_run:
            continue

        if not Path(src).exists():
            print(f"!! Missing source: {src}", file=sys.stderr)
            failures += 1
            if args.fail-fast: break
            continue

        try:
            subprocess.run(cmd, check=True)
        except subprocess.CalledProcessError as ex:
            print(f"!! Command failed ({ex.returncode}): {' '.join(cmd)}", file=sys.stderr)
            failures += 1
            if args.fail-fast: break

    return 0 if failures == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
