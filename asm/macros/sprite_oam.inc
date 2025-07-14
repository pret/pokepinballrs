    .macro packed_sprite_oam x, y, affineMode, objMode, mosaic, bpp, shape, matrixNum, hFlip, vFlip, size, tileNum, priority, paletteNum
    .4byte ( ((\y) & 0xFF) | (((\affineMode) & 0x3) << 8) | (((\objMode) & 0x3) << 10) | (((\mosaic) & 0x1) << 12) | (((\bpp) & 0x1) << 13) | (((\shape) & 0x3) << 14) | (((\x) & 0x1FF) << 16) | (((\matrixNum) & 0x7) << 25) | (((\hFlip) & 0x1) << 28) | (((\vFlip) & 0x1) << 29) | (((\size) & 0x3) << 30) )
    .2byte ( ((\tileNum) & 0x3FF) | (((\priority) & 0x3) << 10) | (((\paletteNum) & 0xF) << 12) )
    .endm
