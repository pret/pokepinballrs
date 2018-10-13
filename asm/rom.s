    .section rom, "aw", %progbits

.incbin "baserom.gba", 0x55A68, 0x666568
