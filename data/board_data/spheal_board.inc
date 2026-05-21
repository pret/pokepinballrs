
gSphealBoardPalette:: @ 0x0837A2E8
	.incbin "baserom.gba", 0x37A2E8, 0x200

gSphealWaterBackgroundTilemap:: @ 0x0837A4E8
	.incbin "baserom.gba", 0x37A4E8, 0x800

gSphealBoardCollisionTileDataAllLayers:: @ 0x0837ACE8
.incbin "data/board_data/collision/spheal/tiledata.bin"

gSphealBoardCollisionAngleDataAllLayers:: @ 0x0837CCE8
.incbin "data/board_data/collision/spheal/angledata.bin"

gSphealBoardCollisionTypeDataAllLayers:: @ 0x08388468
.incbin "data/board_data/collision/spheal/typedata.bin"

gSphealBoardBG1Tilemap:: @ 0x0838E028
	.incbin "baserom.gba", 0x38E028, 0x800

gSphealBoardCompressedBGTiles:: @ 0x0838E828
	.incbin "baserom.gba", 0x38E828, 0x3224

gSphealRampCollisionMap:: @ 0x08391A4C
	.incbin "baserom.gba", 0x391A4C, 0x2000

gSphealFrozenIceCollisionMap:: @ 0x08393A4C
	.incbin "baserom.gba", 0x393A4C, 0x2000
