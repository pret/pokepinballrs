gHighScoreScoreTable_Tilemap:: @ 0x080947A0
	.incbin "graphics/high_score/high_score_table_text_tilemap.bin"

gHighScoreText_Gfx:: @ 0x080957A0
	.incbin "graphics/high_score/text.4bpp"
	.space 0x20

gHighScoreBallWatermark_Tilemap:: @ 0x08099FC0
	.incbin "graphics/high_score/high_score_ball_watermark_tilemap.bin"

gHighScoreBallWatermark_Gfx:: @ 0x0809AFC0
	.incbin "graphics/high_score/ball_watermark_tiles.4bpp"
	.space 0x20

gHighScoreBG_Pals:: @ 0x0809DBE0
	.incbin "graphics/high_score/bg.gbapal"

gHighScoreSprite_Pals:: @ 0x0809DDE0
	.incbin "graphics/high_score/sprites.gbapal"

gHighScoreDialogs_Gfx:: @ 0x0809DFE0
	@ sheet includes transmission windows, and the
	@ pokedex completion certificate, with latios/latias
	.incbin "graphics/high_score/dialogs.4bpp"
	.space 0x20
