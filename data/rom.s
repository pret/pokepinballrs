    .section .rodata

.incbin "baserom.gba", 0x55A68, 0x7A0C0 - 0x55A68

gIntroCopyright_Gfx:: @ 0x0807A0C0
    .incbin "graphics/intro/copyright.4bpp"

.incbin "baserom.gba", 0x7A8C0, 0x20

gIntroCopyright_Pal:: @ 0x0807A8E0
    .incbin "graphics/intro/copyright.gbapal"

.incbin "baserom.gba", 0x7AAE0, 0x39AB8C - 0x7AAE0

.include "data/graphics/mon_portraits_pals.inc"

.incbin "baserom.gba", 0x39C78C, 0x4C596C - 0x39C78C

.include "data/graphics/mon_portraits.inc"

.incbin "baserom.gba", 0x4ECF6C, 0x6BB6A4 - 0x4ECF6C

gMonPortraitGroupPals:: @ 0x086BB6A4
	.4byte gMonPortraitsGroup0_Pals
	.4byte gMonPortraitsGroup1_Pals
	.4byte gMonPortraitsGroup2_Pals
	.4byte gMonPortraitsGroup3_Pals
	.4byte gMonPortraitsGroup4_Pals
	.4byte gMonPortraitsGroup5_Pals
	.4byte gMonPortraitsGroup6_Pals
	.4byte gMonPortraitsGroup7_Pals
	.4byte gMonPortraitsGroup8_Pals
	.4byte gMonPortraitsGroup9_Pals
	.4byte gMonPortraitsGroup10_Pals
	.4byte gMonPortraitsGroup11_Pals
	.4byte gMonPortraitsGroup12_Pals
	.4byte gMonPortraitsGroup13_Pals

.incbin "baserom.gba", 0x6BB6DC, 0x6BB738 - 0x6BB6DC

gMonPortraitGroupGfx:: @ 0x086BB738
	.4byte gMonPortraitsGroup0_Gfx
	.4byte gMonPortraitsGroup1_Gfx
	.4byte gMonPortraitsGroup2_Gfx
	.4byte gMonPortraitsGroup3_Gfx
	.4byte gMonPortraitsGroup4_Gfx
	.4byte gMonPortraitsGroup5_Gfx
	.4byte gMonPortraitsGroup6_Gfx
	.4byte gMonPortraitsGroup7_Gfx
	.4byte gMonPortraitsGroup8_Gfx
	.4byte gMonPortraitsGroup9_Gfx
	.4byte gMonPortraitsGroup10_Gfx
	.4byte gMonPortraitsGroup11_Gfx
	.4byte gMonPortraitsGroup12_Gfx
	.4byte gMonPortraitsGroup13_Gfx

.incbin "baserom.gba", 0x6BB770, 0x6BBFD0 - 0x6BB770

@ rom end 0x6BBFD0
