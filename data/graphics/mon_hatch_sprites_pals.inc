@ Each group is a 16-palette block, but LoadMonFieldSpriteGraphics and the pokedex both
@ index it as eggIndex % 6, so only the first six are ever read. The rest is unused grey
@ filler with nothing in the ROM pointing at it, so it goes in as raw palette data.

gMonHatchSpriteGroup0_Pals:: @ 0x1444F4
	.incbin "graphics/mon_hatch_sprites/wurmple_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/lotad_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/seedot_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/ralts_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/surskit_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/shroomish_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/mon_hatch_group0_unused.gbapal.bin"

gMonHatchSpriteGroup1_Pals:: @ 0x1446F4
	.incbin "graphics/mon_hatch_sprites/whismur_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/azurill_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/skitty_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/zubat_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/aron_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/plusle_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/mon_hatch_group1_unused.gbapal.bin"

gMonHatchSpriteGroup2_Pals:: @ 0x1448F4
	.incbin "graphics/mon_hatch_sprites/minun_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/oddish_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/gulpin_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/spoink_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/sandshrew_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/spinda_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/mon_hatch_group2_unused.gbapal.bin"

gMonHatchSpriteGroup3_Pals:: @ 0x144AF4
	.incbin "graphics/mon_hatch_sprites/trapinch_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/igglybuff_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/shuppet_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/chimecho_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/pichu_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/wynaut_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/mon_hatch_group3_unused.gbapal.bin"

gMonHatchSpriteGroup4_Pals:: @ 0x144CF4
	.incbin "graphics/mon_hatch_sprites/natu_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/phanpy_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/snorunt_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/spheal_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/corsola_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/chinchou_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/mon_hatch_group4_unused.gbapal.bin"

gMonHatchSpriteGroup5_Pals:: @ 0x144EF4
	.incbin "graphics/mon_hatch_sprites/horsea_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/bagon_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/pichu_2_hatch.gbapal"
	.incbin "graphics/mon_hatch_sprites/mon_hatch_group5_unused.gbapal.bin"
