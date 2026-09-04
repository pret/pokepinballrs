#!/usr/bin/env python3
import struct
import sys
from typing import Dict, Iterator, Tuple

ENTRY_SIZE = 6
ARRAY_PACK_1_ENTRY_SIZE = 8
ARRAY_PACK_2_ENTRY_SIZE = ENTRY_SIZE

SPRITE_SIZES = {
    (0, 0): "SPRITE_SIZE_8x8",
    (0, 1): "SPRITE_SIZE_16x16",
    (0, 2): "SPRITE_SIZE_32x32",
    (0, 3): "SPRITE_SIZE_64x64",
    (1, 0): "SPRITE_SIZE_16x8",
    (1, 1): "SPRITE_SIZE_32x8",
    (1, 2): "SPRITE_SIZE_32x16",
    (1, 3): "SPRITE_SIZE_64x32",
    (2, 0): "SPRITE_SIZE_8x16",
    (2, 1): "SPRITE_SIZE_8x32",
    (2, 2): "SPRITE_SIZE_16x32",
    (2, 3): "SPRITE_SIZE_32x64",
}

AFFINE_MODES = {
    0: "ST_OAM_AFFINE_OFF",
    1: "ST_OAM_AFFINE_NORMAL",
    2: "ST_OAM_AFFINE_ERASE",
    3: "ST_OAM_AFFINE_DOUBLE",
}

OBJ_MODES = {
    0: "ST_OAM_OBJ_NORMAL",
    1: "ST_OAM_OBJ_BLEND",
    2: "ST_OAM_OBJ_WINDOW",
}

FIELD_CONSTANTS = {
    "affineMode": AFFINE_MODES,
    "objMode": OBJ_MODES,
}

DEFAULTED_FIELDS = (
    "affineMode",
    "objMode",
    "mosaic",
    "bpp",
    "matrixNum",
    "hFlip",
    "vFlip",
    "priority",
)


def signed(value: int, bits: int) -> int:
    sign_bit = 1 << (bits - 1)
    mask = (1 << bits) - 1
    value &= mask
    return value - (1 << bits) if value & sign_bit else value


def parse_oam_entry(data: bytes) -> Dict[str, int]:
    if len(data) != ENTRY_SIZE:
        raise ValueError(f"OAM entry must be {ENTRY_SIZE} bytes, got {len(data)}")

    word, half = struct.unpack("<IH", data)
    return {
        "y": signed((word >> 0) & 0xFF, 8),
        "affineMode": (word >> 8) & 0x3,
        "objMode": (word >> 10) & 0x3,
        "mosaic": (word >> 12) & 0x1,
        "bpp": (word >> 13) & 0x1,
        "shape": (word >> 14) & 0x3,
        "x": signed((word >> 16) & 0x1FF, 9),
        "matrixNum": (word >> 25) & 0x7,
        "hFlip": (word >> 28) & 0x1,
        "vFlip": (word >> 29) & 0x1,
        "size": (word >> 30) & 0x3,
        "tileNum": (half >> 0) & 0x3FF,
        "priority": (half >> 10) & 0x3,
        "paletteNum": (half >> 12) & 0xF,
    }


def hex_or_signed(value: int) -> str:
    return f"-0x{-value:X}" if value < 0 else f"0x{value:X}"


def format_oam_entry(entry: Dict[str, int], packVariant: str) -> str:
    parts = [
        f"x={hex_or_signed(entry['x'])}",
        f"y={hex_or_signed(entry['y'])}",
    ]

    for field in DEFAULTED_FIELDS:
        value = entry[field]

        if value == 0:
            continue

        constants = FIELD_CONSTANTS.get(field)
        formatted_value = (
            constants.get(value, f"0x{value:X}")
            if constants is not None
            else f"0x{value:X}"
        )

        parts.append(f"{field}={formatted_value}")

    sprite_size = SPRITE_SIZES.get((entry["shape"], entry["size"]))
    if sprite_size is not None:
        parts.append(f"spriteSize={sprite_size}")
    else:
        # Shape 3 is prohibited/reserved on GBA OAM, so retain the raw fields
        # rather than inventing a SpriteSize constant.
        parts.append(f"shape=0x{entry['shape']:X}")
        parts.append(f"size=0x{entry['size']:X}")

    parts.append(f"tileNum=0x{entry['tileNum']:X}")
    parts.append(f"paletteNum=0x{entry['paletteNum']:X}")

    return f"    {packVariant} " + ", ".join(parts)


def iter_array_pack_0(data: bytes) -> Iterator[Tuple[int, bytes]]:
    if len(data) % ENTRY_SIZE != 0:
        raise ValueError(
            f"array_pack 0 length must be a multiple of {ENTRY_SIZE}; got {len(data)}"
        )
    for pos in range(0, len(data), ENTRY_SIZE):
        yield pos, data[pos : pos + ENTRY_SIZE]


def dump_array_pack_0(data: bytes) -> None:
    for _, raw_entry in iter_array_pack_0(data):
        print(format_oam_entry(parse_oam_entry(raw_entry), "packed_sprite_oam"))


def dump_array_pack_1(data: bytes) -> None:
    dump_counted_array(data, ARRAY_PACK_1_ENTRY_SIZE, "packed_sprite_oaml")


def dump_counted_array(data: bytes, entry_size: int, pack_variant: str) -> None:
    pos = 0
    cluster_index = 0

    while pos < len(data):
        cluster_index += 1
        if pos + 2 > len(data):
            raise ValueError(
                f"cluster {cluster_index} at relative offset 0x{pos:X} has a truncated count"
            )

        count = struct.unpack_from("<H", data, pos)[0]
        print(f".2byte {count}")
        pos += 2

        cluster_bytes = count * entry_size
        if pos + cluster_bytes > len(data):
            available = len(data) - pos
            raise ValueError(
                f"cluster {cluster_index} declares {count} entries "
                f"({cluster_bytes} bytes), but only {available} bytes remain"
            )

        for _ in range(count):
            raw_entry = data[pos : pos + ENTRY_SIZE]
            line = format_oam_entry(parse_oam_entry(raw_entry), pack_variant)

            if entry_size > ENTRY_SIZE:
                trailing_value = struct.unpack_from("<H", data, pos + ENTRY_SIZE)[0]
                if trailing_value != 0:
                    line += f", unkFlag=0x{trailing_value:X}"

            print(line)
            pos += entry_size

        print("")


def dump_array_pack_2(data: bytes) -> None:
    dump_counted_array(data, ARRAY_PACK_2_ENTRY_SIZE, "packed_sprite_oam")


def main() -> int:
    if len(sys.argv) not in {4, 5}:
        print(
            f"Usage: {sys.argv[0]} <file> <offset> [length] <array_pack>"
        )
        return 1

    filename = sys.argv[1]
    try:
        offset = int(sys.argv[2], 0)
        if len(sys.argv) == 5:
            length = int(sys.argv[3], 0)
            array_pack = sys.argv[4]
        else:
            length = None
            array_pack = sys.argv[3]
    except ValueError as exc:
        print(f"Error: offset and length must be integers: {exc}", file=sys.stderr)
        return 1

    if array_pack not in {"0", "1", "2"}:
        print("Error: array_pack must be 0, 1, or 2", file=sys.stderr)
        return 1
    if offset < 0 or (length is not None and length < 0):
        print("Error: offset and length must be non-negative", file=sys.stderr)
        return 1

    try:
        with open(filename, "rb") as source:
            source.seek(0, 2)
            file_size = source.tell()
            if offset > file_size:
                raise ValueError(
                    f"offset 0x{offset:X} is beyond end of file (0x{file_size:X})"
                )

            source.seek(offset)
            data = source.read() if length is None else source.read(length)

        if length is not None and len(data) != length:
            raise ValueError(
                f"requested {length} bytes at offset 0x{offset:X}, but read {len(data)}"
            )

        if array_pack == "0":
            dump_array_pack_0(data)
        elif array_pack == "1":
            dump_array_pack_1(data)
        else:
            dump_array_pack_2(data)
    except (OSError, ValueError, struct.error) as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
