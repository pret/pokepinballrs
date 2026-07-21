
gRayquazaBoardPalette:: @ 0x08363EC8
	.incbin "baserom.gba", 0x363EC8, 0x200

gRayquazaBoardBG0Tilemap:: @ 0x083640C8
	.incbin "baserom.gba", 0x3640C8, 0x1000

gRayquazaBoardCollisionTileDataAllLayers:: @ 0x083650C8
.incbin "data/board_data/collision/rayquaza/board_tiledata.bin"

gRayquazaBoardCollisionAngleDataAllLayers:: @ 0x083670C8
.incbin "data/board_data/collision/rayquaza/board_angledata.bin"

gRayquazaBoardCollisionTypeDataAllLayers:: @ 0x0836C048
.incbin "data/board_data/collision/rayquaza/board_typedata.bin"

gRayquazaBoardBGScrollTilemap:: @ 0x0836E808
	.incbin "baserom.gba", 0x36E808, 0x1000

gRayquazaBoardBG1Tilemap:: @ 0x0836F808
	.incbin "baserom.gba", 0x36F808, 0x1000

gRayquazaBoardCompressedBGTiles:: @ 0x08370808
	.incbin "baserom.gba", 0x370808, 0x1AE0

gRayquazaBodyCollisionMap:: @ 0x083722E8
	.incbin "data/board_data/collision/rayquaza/rayquaza_entity_collision_128x128.bin"
