#!/usr/bin/env python3
import sys
import shutil
from pathlib import Path

TILE_SIZE = 0x20  # 32 bytes per tile

def parse_int_auto(s: str) -> int:
    try:
        return int(s, 0)  # accepts "16" or "0x10"
    except ValueError:
        raise SystemExit(f"Invalid tilecount '{s}' (use decimal or 0xHEX)")

def copy_prefix(src: Path, dst: Path, nbytes: int) -> None:
    """Copy the first nbytes from src -> dst (overwrites dst)."""
    bufsize = 1024 * 1024
    with src.open("rb") as fsrc, dst.open("wb") as fdst:
        remaining = nbytes
        while remaining > 0:
            chunk = fsrc.read(min(bufsize, remaining))
            if not chunk:
                break
            fdst.write(chunk)
            remaining -= len(chunk)
    if remaining != 0:
        raise SystemExit(f"error: source ended unexpectedly while copying {nbytes} bytes")

def main():
    if len(sys.argv) != 3:
        print("usage: prune <file> <tilecount>", file=sys.stderr)
        print("example: prune graphics/foo.4bpp 8", file=sys.stderr)
        sys.exit(2)

    file_path = Path(sys.argv[1])
    backup_path = Path(str(file_path) + "_orig")
    tilecount = parse_int_auto(sys.argv[2])
    if tilecount < 0:
        print("error: tilecount must be >= 0", file=sys.stderr)
        sys.exit(1)

    # If backup doesn't exist, we need the current file to seed it.
    if not backup_path.exists():
        if not file_path.exists() or not file_path.is_file():
            print(f"error: neither {file_path} nor backup {backup_path} exists to seed from.", file=sys.stderr)
            sys.exit(1)
        try:
            shutil.copy2(file_path, backup_path)
            print(f"backup created: {backup_path}")
        except Exception as ex:
            print(f"error: failed to create backup: {ex}", file=sys.stderr)
            sys.exit(1)
    else:
        print(f"using existing backup as baseline: {backup_path}")

    # Always start from the backup (original) content
    try:
        orig_size = backup_path.stat().st_size
    except Exception as ex:
        print(f"error: cannot stat backup: {ex}", file=sys.stderr)
        sys.exit(1)

    prune_bytes = TILE_SIZE * tilecount
    if prune_bytes > orig_size:
        print(
            f"error: cannot prune {prune_bytes} bytes ({tilecount} tiles) "
            f"from original size {orig_size} bytes.",
            file=sys.stderr,
        )
        sys.exit(1)

    new_size = orig_size - prune_bytes

    # Write pruned content back to the working file
    try:
        copy_prefix(backup_path, file_path, new_size)
    except Exception as ex:
        print(f"error: failed to write pruned file: {ex}", file=sys.stderr)
        sys.exit(1)

    print(
        f"pruned {prune_bytes} bytes ({tilecount} tile{'s' if tilecount != 1 else ''}) "
        f"from {backup_path.name}; wrote {file_path.name} size {orig_size} -> {new_size} bytes"
    )
    sys.exit(0)

if __name__ == "__main__":
    main()
