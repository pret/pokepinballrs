    .include "asm/macros.inc"

    .section iwram

.space 0x7400

ds SoundMainRAM_Buffer @ 0x3007400
	.space 0x800

