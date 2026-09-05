#!/usr/bin/env python3
from pathlib import Path
import argparse
import sys

TILE_SIZE = 0x20  # 32 bytes per 4bpp tile
MAX_PAL_ALLOWED = 16

def split_4bpp(infile: Path):
    
    if not infile.exists():
        raise FileNotFoundError(f"Input file not found: {infile}")

    file_size = infile.stat().st_size
    if file_size % TILE_SIZE != 0:
        raise ValueError(f"Warning: input size ({file_size} bytes) is not a multiple of {TILE_SIZE}.")

    to_convert = file_size // TILE_SIZE
    
    if to_convert > MAX_PAL_ALLOWED:
        raise ValueError(f"Splitting only allows for up to {MAX_PAL_ALLOWED} enties. This file has {to_convert}.") 
    
    for block in range(to_convert):
        # Build output path in the same directory as the input
        out_name = f"{infile.stem}_{block}.gbapal"
        outfile = infile.with_name(out_name)

        offset = block * TILE_SIZE
        
        with infile.open("rb") as f:
            f.seek(offset)
            data = f.read(TILE_SIZE)

        if not data:
            raise ValueError("No data read.")

        with outfile.open("wb") as out:
            out.write(data)

    return

def main():
    p = argparse.ArgumentParser(
        description="Extract a set of gbapal files from a .4bpp file (pal size = 0x20 bytes)."
    )
    p.add_argument("infile", type=Path, help="Path to input .4bpp file")
    args = p.parse_args()

    split_4bpp(args.infile)

if __name__ == "__main__":
    main()
