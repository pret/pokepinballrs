@ note: base collision data for kyogre/groudon boards are shared.
@ that is in this file at 0x08333804, 0x08335804, 0x0833AD84
@ other data is kyogre specific

gKyogreBoardPalette:: @ 0x08332E04
	.incbin "baserom.gba", 0x332E04, 0x200

gKyogreWaterBackgroundTilemap:: @ 0x08333004
	.incbin "baserom.gba", 0x333004, 0x800

gKyrGrouBoardCollisionTileDataAllLayers:: @ 0x08333804
    .incbin "baserom.gba", 0x333804, 0x2000

gKyrGrouBoardCollisionAngleDataAllLayers:: @ 0x08335804
    .incbin "baserom.gba", 0x335804, 0x5580

gKyrGrouBoardCollisionTypeDataAllLayers:: @ 0x0833AD84
    .incbin "baserom.gba", 0x33AD84, 0x2AC0

gKyogreBoardBG1Tilemap:: @ 0x0833D844
	.incbin "baserom.gba", 0x33D844, 0x800

gKyogreBoardCompressedBGTiles:: @ 0x0833E044
	.incbin "baserom.gba", 0x33E044, 0x1F14

gKyogreIntroShorePalette:: @ 0x0833FF58
	.incbin "baserom.gba", 0x33FF58, 0x200

gKyogreFadeInPaletteStep4:: @ 0x08340158
    .incbin "baserom.gba", 0x340158, 0x200

gKyogreFadeInPaletteStep3:: @ 0x08340358
    .incbin "baserom.gba", 0x340358, 0x200

gKyogreFadeInPaletteStep2:: @ 0x08340558
    .incbin "baserom.gba", 0x340558, 0x200

gKyogreFadeInPaletteStep1:: @ 0x08340758
    .incbin "baserom.gba", 0x340758, 0x200

gKyogreFadeInPaletteStep0:: @ 0x08340958
    .incbin "baserom.gba", 0x340958, 0x200

gKyogreForm1CollisionMap:: @ 0x08340B58
	.incbin "baserom.gba", 0x340B58, 0x8E80

gKyogreForm2CollisionMap:: @ 0x083499D8
	.incbin "baserom.gba", 0x3499D8, 0x4200

gKyogreForm3CollisionMap:: @ 0x0834DBD8
	.incbin "baserom.gba", 0x34DBD8, 0x4E00

gKyogreIntroIcePalette:: @ 0x083529D8
	.incbin "baserom.gba", 0x3529D8, 0x200
