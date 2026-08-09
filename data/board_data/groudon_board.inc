@ note: base collision data for kyogre/groudon boards are shared.
@ that is in the kyogre_board.inc file at 0x08333804, 0x08335804, 0x0833AD84

gGroudonLavaPaletteCycleData:: @ 0x08352BD8
	.incbin "graphics/stage/groudon/groudon_lava.gbapal"

gGroudonBoardBG0Tilemap:: @ 0x08352DD8
	.incbin "graphics/stage/groudon/groudon_board_bg0_tilemap.bin"

gGroudonBoardBG1Tilemap:: @ 0x083535D8
	.incbin "graphics/stage/groudon/groudon_board_bg1_tilemap.bin"

gGroudonBoardCompressedBGTiles:: @ 0x08353DD8
    .incbin "graphics/stage/groudon/groudon_board_bg_tiles.4bpp.lz"

gGroudonBodyCollisionMap:: @ 0x083579C8
	.incbin "data/board_data/collision/groudon/groudon_entity_collision_112x128.bin"

gGroudonProjectileCollisionMap:: @ 0x0835E9C8
	.incbin "data/board_data/collision/groudon/groudon_projectile_collision_80x80.bin"
	.incbin "data/board_data/collision/groudon/groudon_projectile_collision2_80x56.bin"
