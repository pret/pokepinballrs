gKecleonBoardPalette:: @ 0x0830CBD4
	.incbin "baserom.gba", 0x30CBD4, 0x200

gKecleonBoardBG1Tilemap:: @ 0x0830CDD4
	.incbin "baserom.gba", 0x30CDD4, 0x800

gKecleonBoardCollisionTileDataAllLayers:: @ 0x0830D5D4
.incbin "data/board_data/collision/kecleon/board_tiledata.bin"

gKecleonBoardCollisionAngleDataAllLayers:: @ 0x0830F5D4
.incbin "data/board_data/collision/kecleon/board_angledata.bin"

gKecleonBoardCollisionTypeDataAllLayers:: @ 0x0831F854
.incbin "data/board_data/collision/kecleon/board_typedata.bin"

gKecleonBerryOverlayTilemap:: @ 0x08327994
	.incbin "baserom.gba", 0x327994, 0x800

gKecleonOverlayTilemap1:: @ 0x08328194
    .incbin "baserom.gba", 0x328194, 0x800

gKecleonOverlayTilemap2:: @ 0x08328994
    .incbin "baserom.gba", 0x328994, 0x800

gKecleonOverlayTilemap3:: @ 0x08329194
    .incbin "baserom.gba", 0x329194, 0x800

gKecleonBoardBG0Tilemap:: @ 0x08329994
	.incbin "baserom.gba", 0x329994, 0x800

gKecleonBoardCompressedBGTiles:: @ 0x0832A194
	.incbin "baserom.gba", 0x32A194, 0x3470

gKecleonUprightCollisionMap:: @ 0x0832D604
.incbin "data/board_data/collision/kecleon/kecleon_entity_upright_collision_64x88.bin"

gKecleonKnockedDownCollisionMap:: @ 0x08330204
.incbin "data/board_data/collision/kecleon/kecleon_entity_knocked_down_collision_88x64.bin"
