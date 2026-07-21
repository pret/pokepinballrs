@ Translate human readable oam definition into full definition during compilation.
@ Use packed_sprite_oaml if needing a trailing spacer when in a packed spriteSet.
    .macro packed_sprite_oam x, y, affineMode=0x0, objMode=0x0, mosaic=0x0, bpp=0x0, shape=-1, matrixNum=0x0, hFlip=0x0, vFlip=0x0, size=-1, tileNum, priority=0x0, paletteNum, spriteSize=
    .set __shape, (\shape)
    .set __size,  (\size)

    /* If spriteSize text is provided, derive shape/size from it */
    .ifnb \spriteSize
        .set __shape, ((\spriteSize) & 0x3)
        .set __size,  (((\spriteSize) >> 2) & 0x3)
    .endif

    .4byte ( ((\y) & 0xFF) | (((\affineMode) & 0x3) << 8) | (((\objMode) & 0x3) << 10) | (((\mosaic) & 0x1) << 12) | (((\bpp) & 0x1) << 13) | (((__shape) & 0x3) << 14) | (((\x) & 0x1FF) << 16) | (((\matrixNum) & 0x7) << 25) | (((\hFlip) & 0x1) << 28) | (((\vFlip) & 0x1) << 29) | (((__size) & 0x3) << 30) )
    .2byte ( ((\tileNum) & 0x3FF) | (((\priority) & 0x3) << 10) | (((\paletteNum) & 0xF) << 12) )
    .endm

@ Variant of packed_sprite_oam that includes extra padding (l for "List")
    .macro packed_sprite_oaml x, y, affineMode=0x0, objMode=0x0, mosaic=0x0, bpp=0x0, shape=-1, matrixNum=0x0, hFlip=0x0, vFlip=0x0, size=-1, tileNum, priority=0x0, paletteNum, spriteSize=, unkFlag=0x0
        packed_sprite_oam x=\x, y=\y, affineMode=\affineMode, objMode=\objMode, mosaic=\mosaic, bpp=\bpp, shape=\shape, matrixNum=\matrixNum, hFlip=\hFlip, vFlip=\vFlip, size=\size, tileNum=\tileNum, priority=\priority, paletteNum=\paletteNum, spriteSize=\spriteSize
        .2byte \unkFlag
    .endm


@ for generating sprite addresses in Rom based on indexes.
@ Takes in a comma separated list of indexes.
    .macro spriteGroupAddrs indexes:vararg
        .irp idx,\indexes
            .set __addr, gMain_spriteGroups + ((\idx) * 0xB8)
            .4byte (__addr)
        .endr
    .endm
