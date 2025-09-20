#!/usr/bin/env python3
from pathlib import Path
import argparse
import sys

TILE_SIZE = 0x20  # 32 bytes per 4bpp tile

def split_4bpp(infile: Path, suffix: str, skip_tiles: int, take_tiles: int) -> Path:
    if skip_tiles < 0:
        raise ValueError("skip must be >= 0")
    if take_tiles <= 0:
        raise ValueError("take must be > 0")

    if not infile.exists():
        raise FileNotFoundError(f"Input file not found: {infile}")

    # Build output path in the same directory as the input
    out_name = f"{infile.stem}_{suffix}.4bpp"
    outfile = infile.with_name(out_name)

    file_size = infile.stat().st_size
    if file_size % TILE_SIZE != 0:
        print(f"Warning: input size ({file_size} bytes) is not a multiple of {TILE_SIZE}.", file=sys.stderr)

    offset = skip_tiles * TILE_SIZE
    length = take_tiles * TILE_SIZE

    if offset >= file_size:
        raise ValueError(
            f"Skip offset ({offset} bytes) is beyond end of file ({file_size} bytes). "
            f"Nothing to extract."
        )

    with infile.open("rb") as f:
        f.seek(offset)
        data = f.read(length)

    if not data:
        raise ValueError("No data read; check your skip/take parameters.")

    # If the file ended early, we’ll write what we got and let you know.
    if len(data) < length:
        tiles_read = len(data) // TILE_SIZE
        print(
            f"Note: requested {take_tiles} tiles but only {tiles_read} were available from the offset.",
            file=sys.stderr
        )

    with outfile.open("wb") as out:
        out.write(data)

    return outfile

def main():
    p = argparse.ArgumentParser(
        description="Extract a subrange of 4bpp tiles from a .4bpp file (tile size = 0x20 bytes)."
    )
    p.add_argument("infile", type=Path, help="Path to input .4bpp file")
    p.add_argument("suffix", help="Suffix for output name (produces {stem}_{suffix}.4bpp)")
    p.add_argument("skip", type=int, help="Number of tiles to skip from start")
    p.add_argument("take", type=int, help="Number of tiles to copy")
    args = p.parse_args()

    outpath = split_4bpp(args.infile, args.suffix, args.skip, args.take)
    print(f"Wrote: {outpath}")

if __name__ == "__main__":
    main()
