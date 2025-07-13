import struct

ENTRY_SIZE = 0x23C
NUM_ENTRIES = 205

# Partially filled glyph dictionary
glyph_lookup = {
    # Space
    0x0000: ' ',
    
    # Male, Female, Numbers, Dash
    0x2826: '-', 0x2846: '♀', 0x2866: '♂',
    0x2886: '0', 0x28A3: '1', 0x28C6: '2', 0x28E6: '3',
    0x2906: '4', 0x2926: '5', 0x2946: '6', 0x2966: '7',
    0x2986: '8', 0x29A6: '9', 0x29C6: '—',
    
    # Uppercase A–Z
    0x29E6: 'A', 0x2A06: 'B', 0x2A26: 'C', 0x2A46: 'D',
    0x2A66: 'E', 0x2A86: 'F', 0x2AA6: 'G', 0x2AC6: 'H',
    0x2AE2: 'I', 0x2B06: 'J', 0x2B26: 'K', 0x2B46: 'L',
    0x2B66: 'M', 0x2B86: 'N', 0x2BA6: 'O', 0x2BC6: 'P',
    0x2BE6: 'Q', 0x3006: 'R', 0x3026: 'S', 0x3046: 'T',
    0x3066: 'U', 0x3086: 'V', 0x30A6: 'W', 0x30C6: 'X',
    0x30E6: 'Y', 0x3106: 'Z',

    # Lowercase a–z
    0x3126: 'a', 0x3146: 'b', 0x3166: 'c', 0x3186: 'd',
    0x31A6: 'e', 0x31C6: 'f', 0x31E6: 'g', 0x3206: 'h',
    0x3222: 'i', 0x3246: 'j', 0x3266: 'k', 0x3283: 'l',
    0x32A6: 'm', 0x32C5: 'n', 0x32E6: 'o', 0x3306: 'p',
    0x3326: 'q', 0x3345: 'r', 0x3366: 's', 0x3386: 't',
    0x33A6: 'u', 0x33C6: 'v', 0x33E6: 'w', 0x3806: 'x',
    0x3826: 'y', 0x3846: 'z',
    
    # Extra symbols
    0x3866: 'ˎ', 0x3886: '˳', 0x38A6: '╔', 0x38C6: '╝',
    0x38E6: '×', 0x3926: '“', 0x3906: '”', 0x3942: '!',
    0x3968: '?', 0x3984: ':', 0x39A4: ';', 0x39C4: ',',
    0x39E4: '.', 0x3A04: '•', 0x3A26: '(', 0x3A46: ')',
    0x3A68: '~', 0x3A88: '▼', 0x3AA6: 'é', 0x3AC3: '`',
    0x3AE4: '´', 0x3B06: '#',
}

# Set to track unknown glyphs
unknown_glyphs = set()

def decode_glyphs(data, max_len=None):
    text = ""
    count = 0
    for i in range(0, len(data), 2):
        raw = struct.unpack_from('<H', data, i)[0]
        
        char = glyph_lookup.get(raw)
        if char is None:
            char = '?'  # fallback
            unknown_glyphs.add(raw)
        text += char
        count += 1
        if max_len and count >= max_len:
            break
    return text.rstrip()

def decode_description(data):
    lines = []
    for i in range(6):  # 6 lines total
        offset = i * 42 * 2  # 42 u16s per line
        line_data = data[offset:offset + 42 * 2]
        line_text = decode_glyphs(line_data)
        lines.append(line_text)
    return lines

def extract_low_nibbles(data):
    return [x & 0xF for x in struct.unpack('<' + 'H' * (len(data) // 2), data)]

def process_entry(index, data):
    dex_num = extract_low_nibbles(data[0x00:0x06])
    height_weight = extract_low_nibbles(data[0x06:0x18])
    name = decode_glyphs(data[0x18:0x2C])
    category = decode_glyphs(data[0x2C:0x42])
    description = decode_description(data[0x42:])

    output = []
    output.append(f"dexEntry{index+1}:")
    line = "    .2byte " + ', '.join(str(x) if x < 10 else f"0x{x:X}" for x in dex_num + height_weight)

    output.append(line)
    output.append(f'    .dexName "{name}"')
    output.append(f'    .dexCategory "{category.lstrip()}"')
    for desc_line in description:
        output.append(f'    .dexText "{desc_line}"')
    return "\n".join(output)

def main():
    output_lines = []
    with open('pokedex.bin', 'rb') as f:
        binary = f.read()

    for i in range(NUM_ENTRIES):
        offset = i * ENTRY_SIZE
        entry_data = binary[offset:offset + ENTRY_SIZE]
        entry_output = process_entry(i, entry_data)
        output_lines.append(entry_output)

    # Write to output file
    with open("dex.inc", "w", encoding="utf-8") as out_file:
        out_file.write("\n\n".join(output_lines))

    if unknown_glyphs:
        print("Unknown glyphs encountered:")
        for glyph in sorted(unknown_glyphs):
            print(f"  0x{glyph:04X}")
        print(f"\nTotal unknown glyphs: {len(unknown_glyphs)}")
    else:
        print("✅ All glyphs matched successfully!")

if __name__ == '__main__':
    main()
