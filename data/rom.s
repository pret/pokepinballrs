    .section .rodata

.incbin "baserom.gba", 0x55A68, 0x7A0C0 - 0x55A68

gIntroCopyright_Gfx:: @ 0x0807A0C0
    .incbin "graphics/intro/copyright.4bpp"

.incbin "baserom.gba", 0x7A8C0, 0x20

gIntroCopyright_Pal:: @ 0x0807A8E0
    .incbin "graphics/intro/copyright.gbapal"

.incbin "baserom.gba", 0x7AAE0, 0x6BBFD0 - 0x7AAE0

@ rom end 0x6BBFD0
