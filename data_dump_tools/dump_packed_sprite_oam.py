import sys
import struct

def signed(val, bits):
    sign_bit = 1 << (bits - 1)
    mask = (1 << bits) - 1
    val = val & mask
    return val - (1 << bits) if (val & sign_bit) else val

def parse_oam_entry(data):
    word, half = struct.unpack('<IH', data)
    y           = (word >> 0)  & 0xFF
    affineMode  = (word >> 8)  & 0x3
    objMode     = (word >> 10) & 0x3
    mosaic      = (word >> 12) & 0x1
    bpp         = (word >> 13) & 0x1
    shape       = (word >> 14) & 0x3
    x           = (word >> 16) & 0x1FF
    matrixNum   = (word >> 25) & 0x7
    hFlip       = (word >> 28) & 0x1
    vFlip       = (word >> 29) & 0x1
    size        = (word >> 30) & 0x3
    tileNum     = (half >> 0)  & 0x3FF
    priority    = (half >> 10) & 0x3
    paletteNum  = (half >> 12) & 0xF
    return {
        'y': signed(y, 8),
        'affineMode': affineMode,
        'objMode': objMode,
        'mosaic': mosaic,
        'bpp': bpp,
        'shape': shape,
        'x': signed(x, 9),
        'matrixNum': matrixNum,
        'hFlip': hFlip,
        'vFlip': vFlip,
        'size': size,
        'tileNum': tileNum,
        'priority': priority,
        'paletteNum': paletteNum,
    }

def hex_or_signed(val):
    if isinstance(val, int) and val < 0:
        return f"-0x{-val:X}"
    else:
        return f"0x{val:X}"

def main():
    if len(sys.argv) != 5:
        print(f"Usage: {sys.argv[0]} <file> <offset> <length> <array_pack>")
        sys.exit(1)
    filename = sys.argv[1]
    offset = int(sys.argv[2], 0)
    length = int(sys.argv[3], 0)
    array_pack = sys.argv[4]
    if array_pack == "0":
        dataSize = 6
    elif array_pack == "1":
        dataSize = 8
    else:
        print("Error: array_pack must be 0 or 1")
        sys.exit(1)
    with open(filename, 'rb') as f:
        f.seek(offset)
        data = f.read(length)
    if len(data) % dataSize != 0:
        print("Error: length must be a multiple of 6 or 8 depending on array_pack")
        sys.exit(1)
    for i in range(0, len(data), dataSize):
        e = parse_oam_entry(data[i:i+6])
        print(
            "    packed_sprite_oam x={x}, y={y}, affineMode={affineMode}, objMode={objMode}, mosaic={mosaic}, "
            "bpp={bpp}, shape={shape}, matrixNum={matrixNum}, hFlip={hFlip}, vFlip={vFlip}, size={size}, "
            "tileNum={tileNum}, priority={priority}, paletteNum={paletteNum}"
            .format(
                x=hex_or_signed(e['x']),
                y=hex_or_signed(e['y']),
                affineMode=hex(e['affineMode']),
                objMode=hex(e['objMode']),
                mosaic=hex(e['mosaic']),
                bpp=hex(e['bpp']),
                shape=hex(e['shape']),
                matrixNum=hex(e['matrixNum']),
                hFlip=hex(e['hFlip']),
                vFlip=hex(e['vFlip']),
                size=hex(e['size']),
                tileNum=hex(e['tileNum']),
                priority=hex(e['priority']),
                paletteNum=hex(e['paletteNum']),
            )
        )
        if array_pack == "1":
            print(".2byte 0")

if __name__ == "__main__":
    main()