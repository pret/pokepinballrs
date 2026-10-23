@ Unused copy of the options sprite data (not referenced by the code): a sprite set,
@ animations, the end of a cut sprite set, sprite sets and the same animations again.
@ eu_range 0x0895A03C 0x0895A180

.2byte 1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x94, paletteNum=PAL_IX_1

	@ animations: frame count, then (frame, duration) pairs
	.2byte 2
	.2byte 10, 8, 11, 8
	.2byte 1
	.2byte 0, 4
	.2byte 2
	.2byte 23, 24, 24, 8
	.2byte 1
	.2byte 12, 4
	.2byte 2
	.2byte 25, 9, 26, 9
	.2byte 2
	.2byte 28, 18, 29, 18
	.2byte 13
	.2byte 30, 2, 31, 1, 32, 2, 31, 1, 30, 2, 31, 1, 32, 2, 31, 1
	.2byte 30, 2, 31, 1, 32, 2, 31, 1, 29, 30
	.2byte 2
	.2byte 33, 18, 34, 18

	@ two entries of a sprite set whose count is not in the copy
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_32x32, tileNum=0x40, paletteNum=PAL_IX_2
    packed_sprite_oam x=0x0, y=0x20, spriteSize=SPRITE_SIZE_32x16, tileNum=0xC0, paletteNum=PAL_IX_2

.2byte 2
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_32x32, tileNum=0x44, paletteNum=PAL_IX_2
    packed_sprite_oam x=0x0, y=0x20, spriteSize=SPRITE_SIZE_32x16, tileNum=0xC4, paletteNum=PAL_IX_2

.2byte 2
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_32x32, tileNum=0x48, paletteNum=PAL_IX_2
    packed_sprite_oam x=0x0, y=0x20, spriteSize=SPRITE_SIZE_32x16, tileNum=0xC8, paletteNum=PAL_IX_2

.2byte 2
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_32x32, tileNum=0x4C, paletteNum=PAL_IX_2
    packed_sprite_oam x=0x0, y=0x20, spriteSize=SPRITE_SIZE_32x16, tileNum=0xCC, paletteNum=PAL_IX_2

.2byte 2
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_32x32, tileNum=0x50, paletteNum=PAL_IX_2
    packed_sprite_oam x=0x0, y=0x20, spriteSize=SPRITE_SIZE_32x16, tileNum=0xD0, paletteNum=PAL_IX_2

.2byte 1
    packed_sprite_oam x=-0x1, y=-0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x54, paletteNum=PAL_IX_1

.2byte 1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x94, paletteNum=PAL_IX_1

	@ animations: frame count, then (frame, duration) pairs
	.2byte 2
	.2byte 10, 8, 11, 8
	.2byte 1
	.2byte 0, 4
	.2byte 2
	.2byte 23, 24, 24, 8
	.2byte 1
	.2byte 12, 4
	.2byte 2
	.2byte 25, 9, 26, 9
	.2byte 2
	.2byte 28, 18, 29, 18
	.2byte 13
	.2byte 30, 2, 31, 1, 32, 2, 31, 1, 30, 2, 31, 1, 32, 2, 31, 1
	.2byte 30, 2, 31, 1, 32, 2, 31, 1, 29, 30
	.2byte 2
	.2byte 33, 18, 34, 18
