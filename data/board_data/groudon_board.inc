@ note: base collision data for kyogre/groudon boards are shared.
@ that is in the kyogre_board.inc file at 0x08333804, 0x08335804, 0x0833AD84

gGroudonLavaPaletteCycleData:: @ 0x08352BD8
	.incbin "baserom.gba", 0x352BD8, 0x200

gGroudonBoardBG0Tilemap:: @ 0x08352DD8
	.incbin "baserom.gba", 0x352DD8, 0x800

gGroudonBoardBG1Tilemap:: @ 0x083535D8
	.incbin "baserom.gba", 0x3535D8, 0x800

gGroudonBoardCompressedBGTiles:: @ 0x08353DD8
	.incbin "baserom.gba", 0x353DD8, 0x3BF0

gGroudonBodyCollisionMap:: @ 0x083579C8
	.incbin "baserom.gba", 0x3579C8, 0x7000

gGroudonProjectileCollisionMap:: @ 0x0835E9C8
	.incbin "baserom.gba", 0x35E9C8, 0x5500
