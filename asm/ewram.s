	.include "asm/macros.inc"

    .section ewram

.space 0x3060

ds gIntrTable @ 0x2003060

.space 0x8060

ds gUnknown_0200B0C0 @ 0x200B0C0
