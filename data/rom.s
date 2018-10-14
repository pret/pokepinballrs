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

.incbin "baserom.gba", 0x4ECF6C, 0x6BBFD0 - 0x4ECF6C

@ rom end 0x6BBFD0
