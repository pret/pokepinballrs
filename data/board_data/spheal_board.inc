
gSphealBoardPalette:: @ 0x0837A2E8
	.incbin "baserom.gba", 0x37A2E8, 0x200

gSphealWaterBackgroundTilemap:: @ 0x0837A4E8
	.incbin "baserom.gba", 0x37A4E8, 0x800

gSphealBoardCollisionTileDataAllLayers:: @ 0x0837ACE8
.incbin "data/board_data/collision/spheal/board_tiledata.bin"

gSphealBoardCollisionAngleDataAllLayers:: @ 0x0837CCE8
.incbin "data/board_data/collision/spheal/board_angledata.bin"

gSphealBoardCollisionTypeDataAllLayers:: @ 0x08388468
.incbin "data/board_data/collision/spheal/board_typedata.bin"

gSphealBoardBG1Tilemap:: @ 0x0838E028
	.incbin "baserom.gba", 0x38E028, 0x800

gSphealBoardCompressedBGTiles:: @ 0x0838E828
	.incbin "baserom.gba", 0x38E828, 0x3224

gSphealRampCollisionMap:: @ 0x08391A4C
	.incbin "data/board_data/collision/spheal/spheal_ramp_entity_collision_64x64.bin"

gSphealFrozenIceCollisionMap:: @ 0x08393A4C
	.incbin "data/board_data/collision/spheal/spheal_ice_water_entity_collision_64x64.bin"
