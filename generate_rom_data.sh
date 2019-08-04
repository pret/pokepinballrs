#!/bin/bash
#
# Attempt to combine all ROM data symbols into a single assembly file

# Get ROM symbols with addresses from .map file
awk --non-decimal-data '/^\s*0x\w+\s+\w+/{if ($1 > 0x8055A68) print $1 " " $2}' pokepinballrs.map |
# Sort and remove duplicates
sort -u |
# Process into asm file
awk -f \
<(cat - <<-'EOF'
BEGIN {
    prevAddress = "";
    romAddress = strtonum("0x55A84");  # addr of gWildMonLocations
}
/\w+ \w+/ {
    address = strtonum($1);
    symbol = $2;

    # Output space before
    if (prevAddress != "") {
        space = address - prevAddress;
        printf("\t.incbin \"baserom.gba\", 0x%X, 0x%X\n\n", romAddress, space);
        romAddress += space;
    }
    
    prevAddress = address;

    # Output label
    printf("%s:: @ 0x%08X\n", symbol, address);

}
EOF
)