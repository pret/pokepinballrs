.section .rodata


gScaleTable:: @ 0x0852D928
	.incbin "baserom.gba", 0x52D928, 0xB4

gFreqTable:: @ 0x0852D9DC
	.incbin "baserom.gba", 0x52D9DC, 0x30

gPcmSamplesPerVBlankTable:: @ 0x0852DA0C
	.incbin "baserom.gba", 0x52DA0C, 0x18

gCgbScaleTable:: @ 0x0852DA24
	.incbin "baserom.gba", 0x52DA24, 0x84

gCgbFreqTable:: @ 0x0852DAA8
	.incbin "baserom.gba", 0x52DAA8, 0x18

gNoiseTable:: @ 0x0852DAC0
	.incbin "baserom.gba", 0x52DAC0, 0x3C

gCgb3Vol:: @ 0x0852DAFC
	.incbin "baserom.gba", 0x52DAFC, 0x10

gClockTable:: @ 0x0852DB0C
	.incbin "baserom.gba", 0x52DB0C, 0x34

gPokemonCrySongTemplate:: @ 0x0852DB40
    .byte 1, 0, 0xFF, 0
    .4byte voicegroup_base_gUnknown_0852DBAC
	.4byte 0x0, 0x0
    .byte 0x00, 0xC8, 0x40, 0xB2, 0x00, 0x00, 0x00, 0x00
	.byte 0xC8, 0x50, 0xBD, 0x00, 0xBE, 0x7F, 0xCD, 0x0D
	.byte 0x00, 0x00, 0x00, 0x00, 0xCD, 0x07, 0x00, 0xBF
	.byte 0x40, 0xCF, 0x3C, 0x7F, 0xCD, 0x0C, 0x3C, 0x00
	.byte 0xCE, 0xB1, 0x00, 0x00

gXcmdTable:: @ 0x0852DB74
	.4byte ply_xxx
	.4byte ply_xwave
	.4byte ply_xtype
	.4byte ply_xxx
	.4byte ply_xatta
	.4byte ply_xdeca
	.4byte ply_xsust
	.4byte ply_xrele
	.4byte ply_xiecv
	.4byte ply_xiecl
	.4byte ply_xleng
	.4byte ply_xswee
	.4byte ply_xwait
	.4byte ply_xcmd_0D

.include "asm/macros/m4a.inc"
.include "asm/macros/music_voice.inc"

@ Note, this appears identical to rs_drumset in pokeemerald
voice_group gUnknown_0852DBAC, 36
	voice_directsound_no_resample 60, 64, gDirectSound_08535870, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535D10, 255, 0, 255, 242
	voice_directsound_no_resample 60, 64, gDirectSound_08536404, 255, 255, 255, 127
	voice_directsound_no_resample 60, 64, gDirectSound_08536C94, 255, 0, 255, 242
	voice_directsound 48, 44, gDirectSound_0853750C, 255, 210, 77, 204
	voice_directsound_no_resample 60, 79, gDirectSound_0853854C, 255, 127, 0, 188
	voice_directsound 51, 49, gDirectSound_0853750C, 255, 216, 77, 204
	voice_directsound_no_resample 60, 79, gDirectSound_0853854C, 255, 127, 0, 188
	voice_directsound 54, 59, gDirectSound_0853750C, 255, 216, 77, 204
	voice_directsound_no_resample 60, 79, gDirectSound_08538960, 255, 242, 141, 0
	voice_directsound 57, 69, gDirectSound_0853750C, 255, 210, 77, 204
	voice_directsound 60, 79, gDirectSound_0853750C, 255, 204, 77, 204
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_directsound 62, 84, gDirectSound_0853750C, 255, 204, 77, 204
	voice_directsound_no_resample 70, 49, gDirectSound_0853A6BC, 255, 165, 103, 231
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 70, 49, gDirectSound_0853A6BC, 255, 165, 103, 231
	voice_directsound_no_resample 32, 34, gDirectSound_0853B650, 255, 127, 77, 204
	voice_directsound_no_resample 60, 14, gDirectSound_0853BF04, 255, 235, 0, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 8, 0, 255, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 104, gDirectSound_0853C7E8, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 94, gDirectSound_0853CD00, 255, 0, 255, 0

gUnknown_0852DD08:: @ 0x0852DD08
	voice_directsound 60, 0, gDirectSound_0853D2C8, 255, 252, 0, 239
	voice_directsound 60, 0, gDirectSound_0853E228, 255, 250, 0, 221
	voice_directsound 60, 0, gDirectSound_0853F888, 255, 250, 0, 221
	voice_directsound 60, 0, gDirectSound_08540DE4, 255, 247, 0, 221

gUnknown_0852DD38:: @ 0x0852DD38
	voice_directsound 60, 0, gDirectSound_08541970, 255, 0, 255, 196
	voice_directsound 60, 0, gDirectSound_08544F14, 255, 0, 255, 196
	voice_directsound 60, 0, gDirectSound_08547230, 255, 0, 255, 196

gUnknown_0852DD5C:: @ 0x0852DD5C
	voice_directsound 60, 0, gDirectSound_0854A8FC, 255, 0, 193, 127
	voice_directsound 60, 0, gDirectSound_0854BC4C, 255, 0, 193, 127
	voice_directsound 60, 0, gDirectSound_0854D15C, 255, 0, 193, 127

gUnknown_0852DD80:: @ 0x0852DD80
	voice_directsound 60, 0, gDirectSound_0854E57C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0854F618, 255, 0, 255, 165

gUnknown_0852DD98:: @ 0x0852DD98
	voice_directsound 60, 0, gDirectSound_08550674, 255, 0, 224, 165
	voice_directsound 60, 0, gDirectSound_08557608, 255, 0, 218, 165

gUnknown_0852DDB0:: @ 0x0852DDB0
	voice_directsound 60, 0, gDirectSound_0853D2C8, 255, 252, 0, 252
	voice_directsound 60, 0, gDirectSound_0853E228, 255, 250, 0, 250
	voice_directsound 60, 0, gDirectSound_0853F888, 255, 250, 0, 250
	voice_directsound 60, 0, gDirectSound_08540DE4, 255, 247, 0, 247

gUnknown_0852DDE0:: @ 0x0852DDE0
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 178, 180, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 51, 235
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 0, 204
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 1, 7, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 7, 1
	voice_square_2_alt 60, 0, 3, 0, 1, 7, 1
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 7, 1
	voice_square_2_alt 60, 0, 2, 0, 1, 4, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 2
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 15, 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 29, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 22, 2, 0, 2, 0, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535870, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535D10, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08536C94, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 32, 74, gDirectSound_0853B650, 255, 127, 77, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 66, gDirectSound_0853C7E8, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 62, gDirectSound_0853CD00, 255, 0, 255, 0

gUnknown_0852E404:: @ 0x0852E404
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 1, 9, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 9, 0
	voice_square_2_alt 60, 0, 3, 0, 1, 7, 0
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08536C94, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 32, 49, gDirectSound_0853B650, 255, 127, 77, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 8, 0, 255, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 79, gDirectSound_0853C7E8, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 74, gDirectSound_0853CD00, 255, 0, 255, 0

gUnknown_0852E95C:: @ 0x0852E95C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0852EF5C:: @ 0x0852EF5C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 165, 90, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 253, 0, 188
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 2, 3, 1
	voice_square_2_alt 60, 0, 2, 0, 2, 3, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D44, 0, 7, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0852F55C:: @ 0x0852F55C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 253, 0, 188
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 51, 242
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 180, 246
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 2, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D44, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 2, 4, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0852FB5C:: @ 0x0852FB5C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 128, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 235, 128, 99
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 0, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0853015C:: @ 0x0853015C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 72, 249
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 165, 90, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 128, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 180, 246
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0853075C:: @ 0x0853075C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 3
	voice_square_2_alt 60, 0, 3, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_08530D5C:: @ 0x08530D5C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534DB4, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 235, 128, 99
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 180, 246
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_1_alt 60, 0, 0, 2, 1, 1, 4, 1
	voice_square_2_alt 60, 0, 2, 1, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D34, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0853135C:: @ 0x0853135C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 2, 0, 2, 3, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 3, 0, 1, 7, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D54, 0, 7, 15, 2
	voice_square_1 60, 0, 0, 3, 0, 1, 7, 1
	voice_square_1 60, 0, 0, 3, 0, 0, 7, 1

gUnknown_0853174C:: @ 0x0853174C
	voice_directsound 60, 0, gDirectSound_0855F22C, 255, 249, 103, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 2, 0, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 4, 0, 1
	voice_square_1_alt 60, 0, 44, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 38, 0, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 7, 0, 0
	voice_square_1_alt 60, 0, 0, 2, 2, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 2, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 1, 0, 1, 9, 0
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 226, 0, 165
	voice_square_1_alt 60, 0, 0, 2, 0, 6, 0, 1
	voice_square_1_alt 60, 0, 36, 0, 0, 2, 0, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 3, 0, 1, 0, 1
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 0, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 46, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 38, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 119, 2, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 106, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 23, 2, 0, 1, 9, 0
	voice_square_1_alt 60, 0, 21, 2, 0, 1, 9, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 47, 2, 0, 2, 6, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise 60, 0, 0, 0, 7, 15, 0
	voice_noise 60, 0, 0, 2, 7, 15, 0
	voice_noise_alt 60, 0, 0, 2, 0, 15, 0
	voice_noise_alt 60, 0, 1, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 2, 0, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 1

gUnknown_08531D4C:: @ 0x08531D4C
	voice_directsound_no_resample 60, 0, gDirectSound_08562D1C, 255, 249, 0, 165
	voice_directsound_alt 60, 0, gDirectSound_08562D1C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0855F22C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 242, 0, 127
	voice_noise_alt 60, 0, 0, 0, 1, 0, 1
	voice_noise_alt 60, 0, 1, 0, 1, 0, 1
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 255, 165
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 1
	voice_directsound 60, 0, gDirectSound_08564D20, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_085661E4, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08566920, 255, 0, 255, 127
	voice_noise_alt 60, 0, 1, 0, 2, 0, 0
	voice_square_1 60, 0, 103, 3, 2, 7, 0, 0
	voice_square_2 60, 0, 3, 2, 7, 0, 0
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 226, 0, 127
	voice_directsound 60, 0, gDirectSound_08568510, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 204, 0, 127
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 1
	voice_directsound 60, 0, gDirectSound_085698C4, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 0, 255, 127
	voice_square_1 60, 0, 103, 0, 0, 7, 0, 0
	voice_directsound 60, 0, gDirectSound_08536C94, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0856BF48, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0856D18C, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08535D10, 255, 0, 255, 127
	voice_noise_alt 60, 0, 0, 0, 7, 15, 1
	voice_directsound 60, 0, gDirectSound_0856E19C, 255, 0, 255, 127
	voice_noise_alt 60, 0, 1, 0, 7, 15, 1
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 246, 0, 127
	voice_directsound 60, 0, gDirectSound_0856F4A4, 255, 0, 255, 127
	voice_square_1_alt 60, 0, 19, 2, 0, 2, 0, 0
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 0, 255, 127
	voice_square_1 60, 0, 103, 0, 0, 0, 15, 0
	voice_directsound_alt 60, 0, gDirectSound_0856F4A4, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08574158, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08574DCC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 242, 0, 0
	voice_directsound 60, 0, gDirectSound_08576FDC, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 165, 90, 216
	voice_directsound 60, 0, gDirectSound_0853854C, 255, 127, 0, 188
	voice_directsound 60, 0, gDirectSound_08579118, 255, 249, 0, 165
	voice_square_1 60, 0, 0, 0, 4, 6, 0, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 13, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085777A8, 13, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0857B0C8, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 252, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 0, 4, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 188, 0, 0
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 226, 0, 127
	voice_directsound 60, 0, gDirectSound_08539790, 26, 0, 255, 127
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 0, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 252, 0, 127
	voice_square_1_alt 60, 0, 0, 1, 0, 2, 0, 0
	voice_directsound 60, 0, gDirectSound_085661E4, 255, 127, 0, 127
	voice_noise_alt 60, 0, 0, 1, 6, 0, 0
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08536404, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08580744, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08557608, 11, 242, 0, 127
	voice_square_1_alt 60, 0, 0, 2, 4, 6, 0, 0
	voice_directsound 60, 0, gDirectSound_08582284, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0853750C, 255, 0, 255, 165
	voice_noise_alt 60, 0, 0, 5, 7, 15, 1
	voice_directsound 60, 0, gDirectSound_0855FC38, 128, 242, 0, 165
	voice_directsound 60, 0, gDirectSound_08544F14, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 0, 1, 5, 0, 0
	voice_noise_alt 60, 0, 0, 6, 6, 0, 1
	voice_noise_alt 60, 0, 0, 3, 6, 0, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_085715B0, 15, 127, 231, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08583F1C, 255, 0, 255, 165

gUnknown_08532310:: @ 0x08532310
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 1, 0, 15, 0
	voice_noise_alt 60, 0, 0, 1, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 31, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 31, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 55, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 21, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 0, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 63, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 103, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 1, 0, 15, 0
	voice_square_1_alt 60, 0, 103, 0, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08584B2C, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_08588238, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_08588C10, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_0856BF48, 64, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_0858AA14, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_0858E078
	voice_directsound_compressed gDirectSound_08595C7C
	voice_directsound_compressed gDirectSound_08597170
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_0859BD58

gUnknown_08532808:: @ 0x08532808
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_keysplit gUnknown_0852DDB0, keysplit_gUnknown_08534BC0
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_directsound 60, 0, gDirectSound_085A37F4, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 210
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 51, 235
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 51, 235
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_directsound 60, 0, gDirectSound_085A4FE4, 255, 241, 0, 210
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 216, 90, 242
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 149
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 248, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 210, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 253, 0, 149
	voice_directsound 60, 0, gDirectSound_085A611C, 255, 253, 0, 149
	voice_directsound 60, 0, gDirectSound_085A7D6C, 255, 253, 0, 127
	voice_directsound 60, 0, gDirectSound_085A7D6C, 255, 253, 0, 127
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 235, 128, 115
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 178, 180, 165
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_directsound 60, 0, gDirectSound_085A7EDC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A7EDC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8470, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8470, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_directsound 60, 0, gDirectSound_085661E4, 255, 216, 0, 165
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 0, 204
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_directsound 60, 0, gDirectSound_085A9EA4, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_directsound 60, 0, gDirectSound_085A9EA4, 255, 210, 0, 127
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA274, 128, 0, 255, 127
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_085ABE38, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_085AA274, 128, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 0, gDirectSound_08539790, 255, 249, 0, 249
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 0, gDirectSound_0853854C, 255, 89, 0, 89

gUnknown_08532D6C:: @ 0x08532D6C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085ABF3C
	voice_directsound_compressed gDirectSound_085ACFE4
	voice_directsound_compressed gDirectSound_085AE7A4
	voice_directsound_compressed gDirectSound_085AF0F8
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085AFE88
	voice_directsound_compressed gDirectSound_085B1658
	voice_directsound_compressed gDirectSound_085B2EC4
	voice_directsound_compressed gDirectSound_085B3428
	voice_directsound_compressed gDirectSound_085B3AF0
	voice_directsound_compressed gDirectSound_085B4E5C
	voice_directsound_compressed gDirectSound_085B61C0
	voice_directsound_compressed gDirectSound_085B705C
	voice_directsound_compressed gDirectSound_085B7CD8
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085B9674
	voice_directsound_compressed gDirectSound_085BA39C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085BAEE4
	voice_directsound_compressed gDirectSound_085BC648
	voice_directsound_compressed gDirectSound_085BE130
	voice_directsound_compressed gDirectSound_085C00CC
	voice_directsound_compressed gDirectSound_085C0E30
	voice_directsound_compressed gDirectSound_085C1BC0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085C2C48
	voice_directsound_compressed gDirectSound_085C3C38
	voice_directsound_compressed gDirectSound_085C5334
	voice_directsound_compressed gDirectSound_085C6AE8
	voice_directsound_compressed gDirectSound_085C86D0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085C94FC
	voice_directsound_compressed gDirectSound_085CA840
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085CC028
	voice_directsound_compressed gDirectSound_085CD36C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085CE6E4
	voice_directsound_compressed gDirectSound_085CF16C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085D002C
	voice_directsound_compressed gDirectSound_085D18F0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085D3228
	voice_directsound_compressed gDirectSound_085D4684
	voice_directsound_compressed gDirectSound_085D5C30
	voice_directsound_compressed gDirectSound_085D6F9C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085D8408
	voice_directsound_compressed gDirectSound_085D8D84
	voice_directsound_compressed gDirectSound_085D95F0
	voice_directsound_compressed gDirectSound_085D9FC8
	voice_directsound_compressed gDirectSound_085DB320
	voice_directsound_compressed gDirectSound_085DC708
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085DDBE4

gUnknown_08533360:: @ 0x08533360
	voice_directsound_compressed gDirectSound_085DE840
	voice_directsound_compressed gDirectSound_085DFB48
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085E0F7C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085E27D8
	voice_directsound_compressed gDirectSound_085E2D18
	voice_directsound_compressed gDirectSound_085E35E4
	voice_directsound_compressed gDirectSound_085E461C
	voice_directsound_compressed gDirectSound_085E4D20
	voice_directsound_compressed gDirectSound_085E5908
	voice_directsound_compressed gDirectSound_085E7F18
	voice_directsound_compressed gDirectSound_085E9170
	voice_directsound_compressed gDirectSound_085EA5AC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085EBF30
	voice_directsound_compressed gDirectSound_085ED660
	voice_directsound_compressed gDirectSound_085EE310
	voice_directsound_compressed gDirectSound_085EED9C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085EF4F0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085EFBEC
	voice_directsound_compressed gDirectSound_085F067C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085F1548
	voice_directsound_compressed gDirectSound_085F2360
	voice_directsound_compressed gDirectSound_085F3074
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085F4160
	voice_directsound_compressed gDirectSound_085F55FC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085F64B0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085F7704
	voice_directsound_compressed gDirectSound_085F881C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085F9D24
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085FAA04
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085FC20C
	voice_directsound_compressed gDirectSound_085FCFE4
	voice_directsound_compressed gDirectSound_085FDB34
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_085FEC58
	voice_directsound_compressed gDirectSound_085FFAD0
	voice_directsound_compressed gDirectSound_08600330
	voice_directsound_compressed gDirectSound_08600DF0
	voice_directsound_compressed gDirectSound_0860173C
	voice_directsound_compressed gDirectSound_08602398

gUnknown_08533960:: @ 0x08533960
	voice_directsound_compressed gDirectSound_086038A0
	voice_directsound_compressed gDirectSound_08604338
	voice_directsound_compressed gDirectSound_08604F68
	voice_directsound_compressed gDirectSound_08605D48
	voice_directsound_compressed gDirectSound_086068E8
	voice_directsound_compressed gDirectSound_08607FF4
	voice_directsound_compressed gDirectSound_08608984
	voice_directsound_compressed gDirectSound_086093EC
	voice_directsound_compressed gDirectSound_08609984
	voice_directsound_compressed gDirectSound_0860A4A0
	voice_directsound_compressed gDirectSound_0860ADF4
	voice_directsound_compressed gDirectSound_0860B3F4
	voice_directsound_compressed gDirectSound_0860BCF8
	voice_directsound_compressed gDirectSound_0860CEA8
	voice_directsound_compressed gDirectSound_0860DB14
	voice_directsound_compressed gDirectSound_0860E4BC
	voice_directsound_compressed gDirectSound_08610190
	voice_directsound_compressed gDirectSound_08612110
	voice_directsound_compressed gDirectSound_08612CB8
	voice_directsound_compressed gDirectSound_0861412C
	voice_directsound_compressed gDirectSound_08615B48
	voice_directsound_compressed gDirectSound_086162CC
	voice_directsound_compressed gDirectSound_086173D0
	voice_directsound_compressed gDirectSound_08618A50
	voice_directsound_compressed gDirectSound_08619618
	voice_directsound_compressed gDirectSound_0861A258
	voice_directsound_compressed gDirectSound_0861AF00
	voice_directsound_compressed gDirectSound_0861B740
	voice_directsound_compressed gDirectSound_0861BBA8
	voice_directsound_compressed gDirectSound_0861CA3C
	voice_directsound_compressed gDirectSound_0861DB0C
	voice_directsound_compressed gDirectSound_0861E338
	voice_directsound_compressed gDirectSound_0861EEA0
	voice_directsound_compressed gDirectSound_08620264
	voice_directsound_compressed gDirectSound_08620C78
	voice_directsound_compressed gDirectSound_08621544
	voice_directsound_compressed gDirectSound_08622570
	voice_directsound_compressed gDirectSound_08622DA8
	voice_directsound_compressed gDirectSound_08623DEC
	voice_directsound_compressed gDirectSound_08624A98
	voice_directsound_compressed gDirectSound_086254B4
	voice_directsound_compressed gDirectSound_086260E4
	voice_directsound_compressed gDirectSound_08627948
	voice_directsound_compressed gDirectSound_086281CC
	voice_directsound_compressed gDirectSound_08629024
	voice_directsound_compressed gDirectSound_08629A10
	voice_directsound_compressed gDirectSound_0862A080
	voice_directsound_compressed gDirectSound_0862ACA8
	voice_directsound_compressed gDirectSound_0862B460
	voice_directsound_compressed gDirectSound_0862BBBC
	voice_directsound_compressed gDirectSound_0862CC74
	voice_directsound_compressed gDirectSound_0862D9D8
	voice_directsound_compressed gDirectSound_0862EEBC
	voice_directsound_compressed gDirectSound_0862F7B8
	voice_directsound_compressed gDirectSound_086307C0
	voice_directsound_compressed gDirectSound_08631240
	voice_directsound_compressed gDirectSound_086325F4
	voice_directsound_compressed gDirectSound_08632D08
	voice_directsound_compressed gDirectSound_08634220
	voice_directsound_compressed gDirectSound_08634A24
	voice_directsound_compressed gDirectSound_08635B84
	voice_directsound_compressed gDirectSound_086364D0
	voice_directsound_compressed gDirectSound_08637BF0
	voice_directsound_compressed gDirectSound_0863852C
	voice_directsound_compressed gDirectSound_08639628
	voice_directsound_compressed gDirectSound_0863A22C
	voice_directsound_compressed gDirectSound_0863BAE4
	voice_directsound_compressed gDirectSound_0863C224
	voice_directsound_compressed gDirectSound_0863CEC4
	voice_directsound_compressed gDirectSound_0863D8E8
	voice_directsound_compressed gDirectSound_0863E6EC
	voice_directsound_compressed gDirectSound_086400F4
	voice_directsound_compressed gDirectSound_086409E4
	voice_directsound_compressed gDirectSound_08642094
	voice_directsound_compressed gDirectSound_08642D18
	voice_directsound_compressed gDirectSound_08644078
	voice_directsound_compressed gDirectSound_08645874
	voice_directsound_compressed gDirectSound_086468A0
	voice_directsound_compressed gDirectSound_08647074
	voice_directsound_compressed gDirectSound_086497B8
	voice_directsound_compressed gDirectSound_0864A234
	voice_directsound_compressed gDirectSound_0864AA54
	voice_directsound_compressed gDirectSound_0864BAD8
	voice_directsound_compressed gDirectSound_0864C08C
	voice_directsound_compressed gDirectSound_0864CC64
	voice_directsound_compressed gDirectSound_0864F0B0
	voice_directsound_compressed gDirectSound_08650300
	voice_directsound_compressed gDirectSound_086512E8
	voice_directsound_compressed gDirectSound_08652954
	voice_directsound_compressed gDirectSound_086532FC
	voice_directsound_compressed gDirectSound_0865502C
	voice_directsound_compressed gDirectSound_08655BE4
	voice_directsound_compressed gDirectSound_086572B8
	voice_directsound_compressed gDirectSound_08657C58
	voice_directsound_compressed gDirectSound_08658F2C
	voice_directsound_compressed gDirectSound_0865B6A4
	voice_directsound_compressed gDirectSound_0865BE78
	voice_directsound_compressed gDirectSound_0865D280
	voice_directsound_compressed gDirectSound_0865F25C
	voice_directsound_compressed gDirectSound_0866125C
	voice_directsound_compressed gDirectSound_08662960
	voice_directsound_compressed gDirectSound_086635F8
	voice_directsound_compressed gDirectSound_08664180
	voice_directsound_compressed gDirectSound_08665298
	voice_directsound_compressed gDirectSound_08665BE0
	voice_directsound_compressed gDirectSound_08666F6C
	voice_directsound_compressed gDirectSound_08667D24
	voice_directsound_compressed gDirectSound_086688C8
	voice_directsound_compressed gDirectSound_08669448
	voice_directsound_compressed gDirectSound_08669D74
	voice_directsound_compressed gDirectSound_0866B24C
	voice_directsound_compressed gDirectSound_0866CBF0
	voice_directsound_compressed gDirectSound_0866E020
	voice_directsound_compressed gDirectSound_0866E4FC
	voice_directsound_compressed gDirectSound_08670A08
	voice_directsound_compressed gDirectSound_08672DC0
	voice_directsound_compressed gDirectSound_08674AEC
	voice_directsound_compressed gDirectSound_08676408
	voice_directsound_compressed gDirectSound_086770C8
	voice_directsound_compressed gDirectSound_086779A0
	voice_directsound_compressed gDirectSound_0867983C
	voice_directsound_compressed gDirectSound_0867B900
	voice_directsound_compressed gDirectSound_0867D560
	voice_directsound_compressed gDirectSound_0867E0F0
	voice_directsound_compressed gDirectSound_0867FD38
	voice_directsound_compressed gDirectSound_08680A60
	voice_directsound_compressed gDirectSound_08683470
	voice_directsound_compressed gDirectSound_08683C94

gUnknown_08533F60:: @ 0x08533F60
	voice_directsound_compressed gDirectSound_08684D9C
	voice_directsound_compressed gDirectSound_08686394
	voice_directsound_compressed gDirectSound_08687118
	voice_directsound_compressed gDirectSound_086885EC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_085E0F7C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_085E27D8
	voice_directsound_compressed_reverse gDirectSound_085E2D18
	voice_directsound_compressed_reverse gDirectSound_085E35E4
	voice_directsound_compressed_reverse gDirectSound_085E461C
	voice_directsound_compressed_reverse gDirectSound_085E4D20
	voice_directsound_compressed_reverse gDirectSound_085E5908
	voice_directsound_compressed_reverse gDirectSound_085E7F18
	voice_directsound_compressed_reverse gDirectSound_085E9170
	voice_directsound_compressed_reverse gDirectSound_085EA5AC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_085FEC58
	voice_directsound_compressed_reverse gDirectSound_085FFAD0
	voice_directsound_compressed_reverse gDirectSound_08600330
	voice_directsound_compressed_reverse gDirectSound_08600DF0
	voice_directsound_compressed_reverse gDirectSound_0860173C
	voice_directsound_compressed_reverse gDirectSound_08602398
	voice_directsound_compressed_reverse gDirectSound_086038A0
	voice_directsound_compressed_reverse gDirectSound_08604338
	voice_directsound_compressed_reverse gDirectSound_08604F68
	voice_directsound_compressed_reverse gDirectSound_08605D48
	voice_directsound_compressed_reverse gDirectSound_086068E8
	voice_directsound_compressed_reverse gDirectSound_08607FF4
	voice_directsound_compressed_reverse gDirectSound_08608984
	voice_directsound_compressed_reverse gDirectSound_086093EC
	voice_directsound_compressed_reverse gDirectSound_08609984
	voice_directsound_compressed_reverse gDirectSound_0860A4A0
	voice_directsound_compressed_reverse gDirectSound_0860ADF4
	voice_directsound_compressed_reverse gDirectSound_0860B3F4
	voice_directsound_compressed_reverse gDirectSound_0860BCF8
	voice_directsound_compressed_reverse gDirectSound_0860CEA8
	voice_directsound_compressed_reverse gDirectSound_0860DB14
	voice_directsound_compressed_reverse gDirectSound_0860E4BC
	voice_directsound_compressed_reverse gDirectSound_08610190
	voice_directsound_compressed_reverse gDirectSound_08612110
	voice_directsound_compressed_reverse gDirectSound_08612CB8
	voice_directsound_compressed_reverse gDirectSound_0861412C
	voice_directsound_compressed_reverse gDirectSound_08615B48
	voice_directsound_compressed_reverse gDirectSound_086162CC
	voice_directsound_compressed_reverse gDirectSound_086173D0
	voice_directsound_compressed_reverse gDirectSound_08618A50
	voice_directsound_compressed_reverse gDirectSound_08619618
	voice_directsound_compressed_reverse gDirectSound_0861A258
	voice_directsound_compressed_reverse gDirectSound_0861AF00
	voice_directsound_compressed_reverse gDirectSound_0861B740
	voice_directsound_compressed_reverse gDirectSound_0861BBA8
	voice_directsound_compressed_reverse gDirectSound_0861CA3C
	voice_directsound_compressed_reverse gDirectSound_0861DB0C
	voice_directsound_compressed_reverse gDirectSound_0861E338
	voice_directsound_compressed_reverse gDirectSound_0861EEA0
	voice_directsound_compressed_reverse gDirectSound_08620264
	voice_directsound_compressed_reverse gDirectSound_08620C78
	voice_directsound_compressed_reverse gDirectSound_08621544
	voice_directsound_compressed_reverse gDirectSound_08622570
	voice_directsound_compressed_reverse gDirectSound_08622DA8
	voice_directsound_compressed_reverse gDirectSound_08623DEC
	voice_directsound_compressed_reverse gDirectSound_08624A98
	voice_directsound_compressed_reverse gDirectSound_086254B4
	voice_directsound_compressed_reverse gDirectSound_086260E4
	voice_directsound_compressed_reverse gDirectSound_08627948
	voice_directsound_compressed_reverse gDirectSound_086281CC
	voice_directsound_compressed_reverse gDirectSound_08629024
	voice_directsound_compressed_reverse gDirectSound_08629A10
	voice_directsound_compressed_reverse gDirectSound_0862A080
	voice_directsound_compressed_reverse gDirectSound_0862ACA8
	voice_directsound_compressed_reverse gDirectSound_0862B460
	voice_directsound_compressed_reverse gDirectSound_0862BBBC
	voice_directsound_compressed_reverse gDirectSound_0862CC74
	voice_directsound_compressed_reverse gDirectSound_0862D9D8
	voice_directsound_compressed_reverse gDirectSound_0862EEBC
	voice_directsound_compressed_reverse gDirectSound_0862F7B8
	voice_directsound_compressed_reverse gDirectSound_086307C0
	voice_directsound_compressed_reverse gDirectSound_08631240
	voice_directsound_compressed_reverse gDirectSound_086325F4
	voice_directsound_compressed_reverse gDirectSound_08632D08
	voice_directsound_compressed_reverse gDirectSound_08634220
	voice_directsound_compressed_reverse gDirectSound_08634A24
	voice_directsound_compressed_reverse gDirectSound_08635B84
	voice_directsound_compressed_reverse gDirectSound_086364D0
	voice_directsound_compressed_reverse gDirectSound_08637BF0
	voice_directsound_compressed_reverse gDirectSound_0863852C
	voice_directsound_compressed_reverse gDirectSound_08639628
	voice_directsound_compressed_reverse gDirectSound_0863A22C
	voice_directsound_compressed_reverse gDirectSound_0863BAE4
	voice_directsound_compressed_reverse gDirectSound_0863C224
	voice_directsound_compressed_reverse gDirectSound_0863CEC4
	voice_directsound_compressed_reverse gDirectSound_0863D8E8
	voice_directsound_compressed_reverse gDirectSound_0863E6EC
	voice_directsound_compressed_reverse gDirectSound_086400F4
	voice_directsound_compressed_reverse gDirectSound_086409E4
	voice_directsound_compressed_reverse gDirectSound_08642094
	voice_directsound_compressed_reverse gDirectSound_08642D18
	voice_directsound_compressed_reverse gDirectSound_08644078
	voice_directsound_compressed_reverse gDirectSound_08645874
	voice_directsound_compressed_reverse gDirectSound_086468A0
	voice_directsound_compressed_reverse gDirectSound_08647074
	voice_directsound_compressed_reverse gDirectSound_086497B8
	voice_directsound_compressed_reverse gDirectSound_0864A234
	voice_directsound_compressed_reverse gDirectSound_0864AA54
	voice_directsound_compressed_reverse gDirectSound_0864BAD8
	voice_directsound_compressed_reverse gDirectSound_0864C08C
	voice_directsound_compressed_reverse gDirectSound_0864CC64
	voice_directsound_compressed_reverse gDirectSound_0864F0B0
	voice_directsound_compressed_reverse gDirectSound_08650300
	voice_directsound_compressed_reverse gDirectSound_086512E8
	voice_directsound_compressed_reverse gDirectSound_08652954
	voice_directsound_compressed_reverse gDirectSound_086532FC
	voice_directsound_compressed_reverse gDirectSound_0865502C
	voice_directsound_compressed_reverse gDirectSound_08655BE4
	voice_directsound_compressed_reverse gDirectSound_086572B8
	voice_directsound_compressed_reverse gDirectSound_08657C58
	voice_directsound_compressed_reverse gDirectSound_08658F2C
	voice_directsound_compressed_reverse gDirectSound_0865B6A4
	voice_directsound_compressed_reverse gDirectSound_0865BE78
	voice_directsound_compressed_reverse gDirectSound_0865D280
	voice_directsound_compressed_reverse gDirectSound_0865F25C
	voice_directsound_compressed_reverse gDirectSound_0866125C
	voice_directsound_compressed_reverse gDirectSound_08662960
	voice_directsound_compressed_reverse gDirectSound_086635F8
	voice_directsound_compressed_reverse gDirectSound_08664180
	voice_directsound_compressed_reverse gDirectSound_08665298
	voice_directsound_compressed_reverse gDirectSound_08665BE0
	voice_directsound_compressed_reverse gDirectSound_08666F6C
	voice_directsound_compressed_reverse gDirectSound_08667D24
	voice_directsound_compressed_reverse gDirectSound_086688C8
	voice_directsound_compressed_reverse gDirectSound_08669448
	voice_directsound_compressed_reverse gDirectSound_08669D74
	voice_directsound_compressed_reverse gDirectSound_0866B24C
	voice_directsound_compressed_reverse gDirectSound_0866CBF0
	voice_directsound_compressed_reverse gDirectSound_0866E020
	voice_directsound_compressed_reverse gDirectSound_0866E4FC
	voice_directsound_compressed_reverse gDirectSound_08670A08
	voice_directsound_compressed_reverse gDirectSound_08672DC0
	voice_directsound_compressed_reverse gDirectSound_08674AEC
	voice_directsound_compressed_reverse gDirectSound_08676408
	voice_directsound_compressed_reverse gDirectSound_086770C8
	voice_directsound_compressed_reverse gDirectSound_086779A0
	voice_directsound_compressed_reverse gDirectSound_0867983C
	voice_directsound_compressed_reverse gDirectSound_0867B900
	voice_directsound_compressed_reverse gDirectSound_0867D560
	voice_directsound_compressed_reverse gDirectSound_0867E0F0
	voice_directsound_compressed_reverse gDirectSound_0867FD38
	voice_directsound_compressed_reverse gDirectSound_08680A60
	voice_directsound_compressed_reverse gDirectSound_08683470
	voice_directsound_compressed_reverse gDirectSound_08683C94
	voice_directsound_compressed_reverse gDirectSound_08684D9C
	voice_directsound_compressed_reverse gDirectSound_08686394
	voice_directsound_compressed_reverse gDirectSound_08687118
	voice_directsound_compressed_reverse gDirectSound_086885EC

@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (keysplit_piano), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

keysplit gUnknown_08534BC0, 36
	split 0, 55
	split 1, 70
	split 2, 91
	split 3, 108

keysplit gUnknown_08534C08, 36
	split 0, 69
	split 1, 81
	split 2, 108

keysplit gUnknown_08534C50, 36
	split 0, 66
	split 1, 84
	split 2, 108

keysplit gUnknown_08534C98, 24
	split 0, 42
	split 1, 108

keysplit gUnknown_08534CEC, 36
	split 0, 66
	split 1, 108

gUnknown_08534D34:: @ 0x08534D34
	.incbin "sound/programmable_wave_samples/gUnknown_08534D34.pcm"

gUnknown_08534D44:: @ 0x08534D44
	.incbin "sound/programmable_wave_samples/gUnknown_08534D44.pcm"

gUnknown_08534D54:: @ 0x08534D54
	.incbin "sound/programmable_wave_samples/gUnknown_08534D54.pcm"

gUnknown_08534D64:: @ 0x08534D64
	.incbin "sound/programmable_wave_samples/gUnknown_08534D64.pcm"

gUnknown_08534D74:: @ 0x08534D74
	.incbin "sound/programmable_wave_samples/gUnknown_08534D74.pcm"

gUnknown_08534D84:: @ 0x08534D84
	.incbin "sound/programmable_wave_samples/gUnknown_08534D84.pcm"

gUnknown_08534D94:: @ 0x08534D94
	.incbin "sound/programmable_wave_samples/gUnknown_08534D94.pcm"

gUnknown_08534DA4:: @ 0x08534DA4
	.incbin "sound/programmable_wave_samples/gUnknown_08534DA4.pcm"

gUnknown_08534DB4:: @ 0x08534DB4
	.incbin "sound/programmable_wave_samples/gUnknown_08534DB4.pcm"

gUnknown_08534DC4:: @ 0x08534DC4
	.incbin "sound/programmable_wave_samples/gUnknown_08534DC4.pcm"


	.equiv NUM_TRACKS_BGM, 10
	.equiv NUM_TRACKS_SE1, 3
	.equiv NUM_TRACKS_SE2, 3
	.equiv NUM_TRACKS_SE3, 2

	.align 2
gMPlayTable:: @ 0x08534DD4
	music_player gMPlayInfo_BGM, gMPlayTrack_BGM, NUM_TRACKS_BGM, 0
	music_player gMPlayInfo_SE1, gMPlayTrack_SE1, NUM_TRACKS_SE1, 0
	music_player gMPlayInfo_SE2, gMPlayTrack_SE2, NUM_TRACKS_SE2, 0
	music_player gMPlayInfo_SE3, gMPlayTrack_SE3, NUM_TRACKS_SE3, 0

.include "sound/song_table.inc"

.include "sound/songs/mus_dummy.s"

	.align 2
gDirectSound_08535870:: @ 0x08535870
	.incbin "sound/direct_sound_samples/gDirectSound_08535870.bin"

	.align 2
gDirectSound_08535D10:: @ 0x08535D10
	.incbin "sound/direct_sound_samples/gDirectSound_08535D10.bin"

	.align 2
gDirectSound_08536404:: @ 0x08536404
	.incbin "sound/direct_sound_samples/gDirectSound_08536404.bin"

	.align 2
gDirectSound_08536C94:: @ 0x08536C94
	.incbin "sound/direct_sound_samples/gDirectSound_08536C94.bin"

	.align 2
gDirectSound_0853750C:: @ 0x0853750C
	.incbin "sound/direct_sound_samples/gDirectSound_0853750C.bin"

	.align 2
gDirectSound_0853854C:: @ 0x0853854C
	.incbin "sound/direct_sound_samples/gDirectSound_0853854C.bin"

	.align 2
gDirectSound_08538960:: @ 0x08538960
	.incbin "sound/direct_sound_samples/gDirectSound_08538960.bin"

	.align 2
gDirectSound_08539790:: @ 0x08539790
	.incbin "sound/direct_sound_samples/gDirectSound_08539790.bin"

	.align 2
gDirectSound_0853A6BC:: @ 0x0853A6BC
	.incbin "sound/direct_sound_samples/gDirectSound_0853A6BC.bin"

	.align 2
gDirectSound_0853B650:: @ 0x0853B650
	.incbin "sound/direct_sound_samples/gDirectSound_0853B650.bin"

	.align 2
gDirectSound_0853BF04:: @ 0x0853BF04
	.incbin "sound/direct_sound_samples/gDirectSound_0853BF04.bin"

	.align 2
gDirectSound_0853C7E8:: @ 0x0853C7E8
	.incbin "sound/direct_sound_samples/gDirectSound_0853C7E8.bin"

	.align 2
gDirectSound_0853CD00:: @ 0x0853CD00
	.incbin "sound/direct_sound_samples/gDirectSound_0853CD00.bin"

	.align 2
gDirectSound_0853D2C8:: @ 0x0853D2C8
	.incbin "sound/direct_sound_samples/gDirectSound_0853D2C8.bin"

	.align 2
gDirectSound_0853E228:: @ 0x0853E228
	.incbin "sound/direct_sound_samples/gDirectSound_0853E228.bin"

	.align 2
gDirectSound_0853F888:: @ 0x0853F888
	.incbin "sound/direct_sound_samples/gDirectSound_0853F888.bin"

	.align 2
gDirectSound_08540DE4:: @ 0x08540DE4
	.incbin "sound/direct_sound_samples/gDirectSound_08540DE4.bin"

	.align 2
gDirectSound_08541970:: @ 0x08541970
	.incbin "sound/direct_sound_samples/gDirectSound_08541970.bin"

	.align 2
gDirectSound_08544F14:: @ 0x08544F14
	.incbin "sound/direct_sound_samples/gDirectSound_08544F14.bin"

	.align 2
gDirectSound_08547230:: @ 0x08547230
	.incbin "sound/direct_sound_samples/gDirectSound_08547230.bin"

	.align 2
gDirectSound_0854A8FC:: @ 0x0854A8FC
	.incbin "sound/direct_sound_samples/gDirectSound_0854A8FC.bin"

	.align 2
gDirectSound_0854BC4C:: @ 0x0854BC4C
	.incbin "sound/direct_sound_samples/gDirectSound_0854BC4C.bin"

	.align 2
gDirectSound_0854D15C:: @ 0x0854D15C
	.incbin "sound/direct_sound_samples/gDirectSound_0854D15C.bin"

	.align 2
gDirectSound_0854E57C:: @ 0x0854E57C
	.incbin "sound/direct_sound_samples/gDirectSound_0854E57C.bin"

	.align 2
gDirectSound_0854F618:: @ 0x0854F618
	.incbin "sound/direct_sound_samples/gDirectSound_0854F618.bin"

	.align 2
gDirectSound_08550674:: @ 0x08550674
	.incbin "sound/direct_sound_samples/gDirectSound_08550674.bin"

	.align 2
gDirectSound_08557608:: @ 0x08557608
	.incbin "sound/direct_sound_samples/gDirectSound_08557608.bin"

	.align 2
gDirectSound_0855BB8C:: @ 0x0855BB8C
	.incbin "sound/direct_sound_samples/gDirectSound_0855BB8C.bin"

	.align 2
gDirectSound_0855C2F0:: @ 0x0855C2F0
	.incbin "sound/direct_sound_samples/gDirectSound_0855C2F0.bin"

	.align 2
gDirectSound_0855CAE8:: @ 0x0855CAE8
	.incbin "sound/direct_sound_samples/gDirectSound_0855CAE8.bin"

	.align 2
gDirectSound_0855EA58:: @ 0x0855EA58
	.incbin "sound/direct_sound_samples/gDirectSound_0855EA58.bin"

	.align 2
gDirectSound_0855F22C:: @ 0x0855F22C
	.incbin "sound/direct_sound_samples/gDirectSound_0855F22C.bin"

	.align 2
gDirectSound_0855FC38:: @ 0x0855FC38
	.incbin "sound/direct_sound_samples/gDirectSound_0855FC38.bin"

	.align 2
gDirectSound_0856184C:: @ 0x0856184C
	.incbin "sound/direct_sound_samples/gDirectSound_0856184C.bin"

	.align 2
gDirectSound_08562D1C:: @ 0x08562D1C
	.incbin "sound/direct_sound_samples/gDirectSound_08562D1C.bin"

	.align 2
gDirectSound_0856467C:: @ 0x0856467C
	.incbin "sound/direct_sound_samples/gDirectSound_0856467C.bin"

	.align 2
gDirectSound_08564D20:: @ 0x08564D20
	.incbin "sound/direct_sound_samples/gDirectSound_08564D20.bin"

	.align 2
gDirectSound_085661E4:: @ 0x085661E4
	.incbin "sound/direct_sound_samples/gDirectSound_085661E4.bin"

	.align 2
gDirectSound_08566920:: @ 0x08566920
	.incbin "sound/direct_sound_samples/gDirectSound_08566920.bin"

	.align 2
gDirectSound_08568510:: @ 0x08568510
	.incbin "sound/direct_sound_samples/gDirectSound_08568510.bin"

	.align 2
gDirectSound_085698C4:: @ 0x085698C4
	.incbin "sound/direct_sound_samples/gDirectSound_085698C4.bin"

	.align 2
gDirectSound_0856BF48:: @ 0x0856BF48
	.incbin "sound/direct_sound_samples/gDirectSound_0856BF48.bin"

	.align 2
gDirectSound_0856D18C:: @ 0x0856D18C
	.incbin "sound/direct_sound_samples/gDirectSound_0856D18C.bin"

	.align 2
gDirectSound_0856E19C:: @ 0x0856E19C
	.incbin "sound/direct_sound_samples/gDirectSound_0856E19C.bin"

	.align 2
gDirectSound_0856F4A4:: @ 0x0856F4A4
	.incbin "sound/direct_sound_samples/gDirectSound_0856F4A4.bin"

	.align 2
gDirectSound_085715B0:: @ 0x085715B0
	.incbin "sound/direct_sound_samples/gDirectSound_085715B0.bin"

	.align 2
gDirectSound_0857358C:: @ 0x0857358C
	.incbin "sound/direct_sound_samples/gDirectSound_0857358C.bin"

	.align 2
gDirectSound_08574158:: @ 0x08574158
	.incbin "sound/direct_sound_samples/gDirectSound_08574158.bin"

	.align 2
gDirectSound_08574DCC:: @ 0x08574DCC
	.incbin "sound/direct_sound_samples/gDirectSound_08574DCC.bin"

	.align 2
gDirectSound_08576FDC:: @ 0x08576FDC
	.incbin "sound/direct_sound_samples/gDirectSound_08576FDC.bin"

	.align 2
gDirectSound_085777A8:: @ 0x085777A8
	.incbin "sound/direct_sound_samples/gDirectSound_085777A8.bin"

	.align 2
gDirectSound_08579118:: @ 0x08579118
	.incbin "sound/direct_sound_samples/gDirectSound_08579118.bin"

	.align 2
gDirectSound_0857B0C8:: @ 0x0857B0C8
	.incbin "sound/direct_sound_samples/gDirectSound_0857B0C8.bin"

	.align 2
gDirectSound_0857E3A8:: @ 0x0857E3A8
	.incbin "sound/direct_sound_samples/gDirectSound_0857E3A8.bin"

	.align 2
gDirectSound_0857EDD8:: @ 0x0857EDD8
	.incbin "sound/direct_sound_samples/gDirectSound_0857EDD8.bin"

	.align 2
gDirectSound_0857F80C:: @ 0x0857F80C
	.incbin "sound/direct_sound_samples/gDirectSound_0857F80C.bin"

	.align 2
gDirectSound_08580744:: @ 0x08580744
	.incbin "sound/direct_sound_samples/gDirectSound_08580744.bin"

	.align 2
gDirectSound_08582284:: @ 0x08582284
	.incbin "sound/direct_sound_samples/gDirectSound_08582284.bin"

	.align 2
gDirectSound_08582B4C:: @ 0x08582B4C
	.incbin "sound/direct_sound_samples/gDirectSound_08582B4C.bin"

	.align 2
gDirectSound_08583F1C:: @ 0x08583F1C
	.incbin "sound/direct_sound_samples/gDirectSound_08583F1C.bin"

	.align 2
gDirectSound_08584B2C:: @ 0x08584B2C
	.incbin "sound/direct_sound_samples/gDirectSound_08584B2C.bin"

	.align 2
gDirectSound_08588238:: @ 0x08588238
	.incbin "sound/direct_sound_samples/gDirectSound_08588238.bin"

	.align 2
gDirectSound_08588C10:: @ 0x08588C10
	.incbin "sound/direct_sound_samples/gDirectSound_08588C10.bin"

	.align 2
gDirectSound_0858AA14:: @ 0x0858AA14
	.incbin "sound/direct_sound_samples/gDirectSound_0858AA14.bin"

	.align 2
gDirectSound_0858E078:: @ 0x0858E078
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0858E078.bin"

	.align 2
gDirectSound_08595C7C:: @ 0x08595C7C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08595C7C.bin"

	.align 2
gDirectSound_08597170:: @ 0x08597170
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08597170.bin"

	.align 2
gDirectSound_0859BD58:: @ 0x0859BD58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0859BD58.bin"

	.align 2
gDirectSound_085A37F4:: @ 0x085A37F4
	.incbin "sound/direct_sound_samples/gDirectSound_085A37F4.bin"

	.align 2
gDirectSound_085A3DF4:: @ 0x085A3DF4
	.incbin "sound/direct_sound_samples/gDirectSound_085A3DF4.bin"

	.align 2
gDirectSound_085A45E0:: @ 0x085A45E0
	.incbin "sound/direct_sound_samples/gDirectSound_085A45E0.bin"

	.align 2
gDirectSound_085A4FE4:: @ 0x085A4FE4
	.incbin "sound/direct_sound_samples/gDirectSound_085A4FE4.bin"

	.align 2
gDirectSound_085A5934:: @ 0x085A5934
	.incbin "sound/direct_sound_samples/gDirectSound_085A5934.bin"

	.align 2
gDirectSound_085A5A74:: @ 0x085A5A74
	.incbin "sound/direct_sound_samples/gDirectSound_085A5A74.bin"

	.align 2
gDirectSound_085A611C:: @ 0x085A611C
	.incbin "sound/direct_sound_samples/gDirectSound_085A611C.bin"

	.align 2
gDirectSound_085A7D6C:: @ 0x085A7D6C
	.incbin "sound/direct_sound_samples/gDirectSound_085A7D6C.bin"

	.align 2
gDirectSound_085A7EDC:: @ 0x085A7EDC
	.incbin "sound/direct_sound_samples/gDirectSound_085A7EDC.bin"

	.align 2
gDirectSound_085A8470:: @ 0x085A8470
	.incbin "sound/direct_sound_samples/gDirectSound_085A8470.bin"

	.align 2
gDirectSound_085A8788:: @ 0x085A8788
	.incbin "sound/direct_sound_samples/gDirectSound_085A8788.bin"

	.align 2
gDirectSound_085A9C78:: @ 0x085A9C78
	.incbin "sound/direct_sound_samples/gDirectSound_085A9C78.bin"

	.align 2
gDirectSound_085A9EA4:: @ 0x085A9EA4
	.incbin "sound/direct_sound_samples/gDirectSound_085A9EA4.bin"

	.align 2
gDirectSound_085AA074:: @ 0x085AA074
	.incbin "sound/direct_sound_samples/gDirectSound_085AA074.bin"

	.align 2
gDirectSound_085AA274:: @ 0x085AA274
	.incbin "sound/direct_sound_samples/gDirectSound_085AA274.bin"

	.align 2
gDirectSound_085ABE38:: @ 0x085ABE38
	.incbin "sound/direct_sound_samples/gDirectSound_085ABE38.bin"

	.align 2
gDirectSound_085ABF3C:: @ 0x085ABF3C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085ABF3C.bin"

	.align 2
gDirectSound_085ACFE4:: @ 0x085ACFE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085ACFE4.bin"

	.align 2
gDirectSound_085AE7A4:: @ 0x085AE7A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085AE7A4.bin"

	.align 2
gDirectSound_085AF0F8:: @ 0x085AF0F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085AF0F8.bin"

	.align 2
gDirectSound_085AFE88:: @ 0x085AFE88
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085AFE88.bin"

	.align 2
gDirectSound_085B1658:: @ 0x085B1658
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B1658.bin"

	.align 2
gDirectSound_085B2EC4:: @ 0x085B2EC4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B2EC4.bin"

	.align 2
gDirectSound_085B3428:: @ 0x085B3428
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B3428.bin"

	.align 2
gDirectSound_085B3AF0:: @ 0x085B3AF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B3AF0.bin"

	.align 2
gDirectSound_085B4E5C:: @ 0x085B4E5C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B4E5C.bin"

	.align 2
gDirectSound_085B61C0:: @ 0x085B61C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B61C0.bin"

	.align 2
gDirectSound_085B705C:: @ 0x085B705C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B705C.bin"

	.align 2
gDirectSound_085B7CD8:: @ 0x085B7CD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B7CD8.bin"

	.align 2
gDirectSound_085B9674:: @ 0x085B9674
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B9674.bin"

	.align 2
gDirectSound_085BA39C:: @ 0x085BA39C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BA39C.bin"

	.align 2
gDirectSound_085BAEE4:: @ 0x085BAEE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BAEE4.bin"

	.align 2
gDirectSound_085BC648:: @ 0x085BC648
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BC648.bin"

	.align 2
gDirectSound_085BE130:: @ 0x085BE130
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BE130.bin"

	.align 2
gDirectSound_085C00CC:: @ 0x085C00CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C00CC.bin"

	.align 2
gDirectSound_085C0E30:: @ 0x085C0E30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C0E30.bin"

	.align 2
gDirectSound_085C1BC0:: @ 0x085C1BC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C1BC0.bin"

	.align 2
gDirectSound_085C2C48:: @ 0x085C2C48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C2C48.bin"

	.align 2
gDirectSound_085C3C38:: @ 0x085C3C38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C3C38.bin"

	.align 2
gDirectSound_085C5334:: @ 0x085C5334
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C5334.bin"

	.align 2
gDirectSound_085C6AE8:: @ 0x085C6AE8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C6AE8.bin"

	.align 2
gDirectSound_085C86D0:: @ 0x085C86D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C86D0.bin"

	.align 2
gDirectSound_085C94FC:: @ 0x085C94FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C94FC.bin"

	.align 2
gDirectSound_085CA840:: @ 0x085CA840
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CA840.bin"

	.align 2
gDirectSound_085CC028:: @ 0x085CC028
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CC028.bin"

	.align 2
gDirectSound_085CD36C:: @ 0x085CD36C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CD36C.bin"

	.align 2
gDirectSound_085CE6E4:: @ 0x085CE6E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CE6E4.bin"

	.align 2
gDirectSound_085CF16C:: @ 0x085CF16C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CF16C.bin"

	.align 2
gDirectSound_085D002C:: @ 0x085D002C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D002C.bin"

	.align 2
gDirectSound_085D18F0:: @ 0x085D18F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D18F0.bin"

	.align 2
gDirectSound_085D3228:: @ 0x085D3228
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D3228.bin"

	.align 2
gDirectSound_085D4684:: @ 0x085D4684
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D4684.bin"

	.align 2
gDirectSound_085D5C30:: @ 0x085D5C30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D5C30.bin"

	.align 2
gDirectSound_085D6F9C:: @ 0x085D6F9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D6F9C.bin"

	.align 2
gDirectSound_085D8408:: @ 0x085D8408
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D8408.bin"

	.align 2
gDirectSound_085D8D84:: @ 0x085D8D84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D8D84.bin"

	.align 2
gDirectSound_085D95F0:: @ 0x085D95F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D95F0.bin"

	.align 2
gDirectSound_085D9FC8:: @ 0x085D9FC8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D9FC8.bin"

	.align 2
gDirectSound_085DB320:: @ 0x085DB320
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DB320.bin"

	.align 2
gDirectSound_085DC708:: @ 0x085DC708
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DC708.bin"

	.align 2
gDirectSound_085DDBE4:: @ 0x085DDBE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DDBE4.bin"

	.align 2
gDirectSound_085DE840:: @ 0x085DE840
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DE840.bin"

	.align 2
gDirectSound_085DFB48:: @ 0x085DFB48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DFB48.bin"

	.align 2
gDirectSound_085E0F7C:: @ 0x085E0F7C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E0F7C.bin"

	.align 2
gDirectSound_085E27D8:: @ 0x085E27D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E27D8.bin"

	.align 2
gDirectSound_085E2D18:: @ 0x085E2D18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E2D18.bin"

	.align 2
gDirectSound_085E35E4:: @ 0x085E35E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E35E4.bin"

	.align 2
gDirectSound_085E461C:: @ 0x085E461C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E461C.bin"

	.align 2
gDirectSound_085E4D20:: @ 0x085E4D20
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E4D20.bin"

	.align 2
gDirectSound_085E5908:: @ 0x085E5908
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E5908.bin"

	.align 2
gDirectSound_085E7F18:: @ 0x085E7F18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E7F18.bin"

	.align 2
gDirectSound_085E9170:: @ 0x085E9170
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E9170.bin"

	.align 2
gDirectSound_085EA5AC:: @ 0x085EA5AC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EA5AC.bin"

	.align 2
gDirectSound_085EBF30:: @ 0x085EBF30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EBF30.bin"

	.align 2
gDirectSound_085ED660:: @ 0x085ED660
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085ED660.bin"

	.align 2
gDirectSound_085EE310:: @ 0x085EE310
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EE310.bin"

	.align 2
gDirectSound_085EED9C:: @ 0x085EED9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EED9C.bin"

	.align 2
gDirectSound_085EF4F0:: @ 0x085EF4F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EF4F0.bin"

	.align 2
gDirectSound_085EFBEC:: @ 0x085EFBEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EFBEC.bin"

	.align 2
gDirectSound_085F067C:: @ 0x085F067C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F067C.bin"

	.align 2
gDirectSound_085F1548:: @ 0x085F1548
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F1548.bin"

	.align 2
gDirectSound_085F2360:: @ 0x085F2360
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F2360.bin"

	.align 2
gDirectSound_085F3074:: @ 0x085F3074
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F3074.bin"

	.align 2
gDirectSound_085F4160:: @ 0x085F4160
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F4160.bin"

	.align 2
gDirectSound_085F55FC:: @ 0x085F55FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F55FC.bin"

	.align 2
gDirectSound_085F64B0:: @ 0x085F64B0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F64B0.bin"

	.align 2
gDirectSound_085F7704:: @ 0x085F7704
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F7704.bin"

	.align 2
gDirectSound_085F881C:: @ 0x085F881C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F881C.bin"

	.align 2
gDirectSound_085F9D24:: @ 0x085F9D24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F9D24.bin"

	.align 2
gDirectSound_085FAA04:: @ 0x085FAA04
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FAA04.bin"

	.align 2
gDirectSound_085FC20C:: @ 0x085FC20C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FC20C.bin"

	.align 2
gDirectSound_085FCFE4:: @ 0x085FCFE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FCFE4.bin"

	.align 2
gDirectSound_085FDB34:: @ 0x085FDB34
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FDB34.bin"

	.align 2
gDirectSound_085FEC58:: @ 0x085FEC58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FEC58.bin"

	.align 2
gDirectSound_085FFAD0:: @ 0x085FFAD0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FFAD0.bin"

	.align 2
gDirectSound_08600330:: @ 0x08600330
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08600330.bin"

	.align 2
gDirectSound_08600DF0:: @ 0x08600DF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08600DF0.bin"

	.align 2
gDirectSound_0860173C:: @ 0x0860173C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860173C.bin"

	.align 2
gDirectSound_08602398:: @ 0x08602398
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08602398.bin"

	.align 2
gDirectSound_086038A0:: @ 0x086038A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086038A0.bin"

	.align 2
gDirectSound_08604338:: @ 0x08604338
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08604338.bin"

	.align 2
gDirectSound_08604F68:: @ 0x08604F68
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08604F68.bin"

	.align 2
gDirectSound_08605D48:: @ 0x08605D48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08605D48.bin"

	.align 2
gDirectSound_086068E8:: @ 0x086068E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086068E8.bin"

	.align 2
gDirectSound_08607FF4:: @ 0x08607FF4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08607FF4.bin"

	.align 2
gDirectSound_08608984:: @ 0x08608984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08608984.bin"

	.align 2
gDirectSound_086093EC:: @ 0x086093EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086093EC.bin"

	.align 2
gDirectSound_08609984:: @ 0x08609984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08609984.bin"

	.align 2
gDirectSound_0860A4A0:: @ 0x0860A4A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860A4A0.bin"

	.align 2
gDirectSound_0860ADF4:: @ 0x0860ADF4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860ADF4.bin"

	.align 2
gDirectSound_0860B3F4:: @ 0x0860B3F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860B3F4.bin"

	.align 2
gDirectSound_0860BCF8:: @ 0x0860BCF8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860BCF8.bin"

	.align 2
gDirectSound_0860CEA8:: @ 0x0860CEA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860CEA8.bin"

	.align 2
gDirectSound_0860DB14:: @ 0x0860DB14
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860DB14.bin"

	.align 2
gDirectSound_0860E4BC:: @ 0x0860E4BC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860E4BC.bin"

	.align 2
gDirectSound_08610190:: @ 0x08610190
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08610190.bin"

	.align 2
gDirectSound_08612110:: @ 0x08612110
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08612110.bin"

	.align 2
gDirectSound_08612CB8:: @ 0x08612CB8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08612CB8.bin"

	.align 2
gDirectSound_0861412C:: @ 0x0861412C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861412C.bin"

	.align 2
gDirectSound_08615B48:: @ 0x08615B48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08615B48.bin"

	.align 2
gDirectSound_086162CC:: @ 0x086162CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086162CC.bin"

	.align 2
gDirectSound_086173D0:: @ 0x086173D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086173D0.bin"

	.align 2
gDirectSound_08618A50:: @ 0x08618A50
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08618A50.bin"

	.align 2
gDirectSound_08619618:: @ 0x08619618
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08619618.bin"

	.align 2
gDirectSound_0861A258:: @ 0x0861A258
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861A258.bin"

	.align 2
gDirectSound_0861AF00:: @ 0x0861AF00
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861AF00.bin"

	.align 2
gDirectSound_0861B740:: @ 0x0861B740
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861B740.bin"

	.align 2
gDirectSound_0861BBA8:: @ 0x0861BBA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861BBA8.bin"

	.align 2
gDirectSound_0861CA3C:: @ 0x0861CA3C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861CA3C.bin"

	.align 2
gDirectSound_0861DB0C:: @ 0x0861DB0C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861DB0C.bin"

	.align 2
gDirectSound_0861E338:: @ 0x0861E338
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861E338.bin"

	.align 2
gDirectSound_0861EEA0:: @ 0x0861EEA0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861EEA0.bin"

	.align 2
gDirectSound_08620264:: @ 0x08620264
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08620264.bin"

	.align 2
gDirectSound_08620C78:: @ 0x08620C78
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08620C78.bin"

	.align 2
gDirectSound_08621544:: @ 0x08621544
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08621544.bin"

	.align 2
gDirectSound_08622570:: @ 0x08622570
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08622570.bin"

	.align 2
gDirectSound_08622DA8:: @ 0x08622DA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08622DA8.bin"

	.align 2
gDirectSound_08623DEC:: @ 0x08623DEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08623DEC.bin"

	.align 2
gDirectSound_08624A98:: @ 0x08624A98
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08624A98.bin"

	.align 2
gDirectSound_086254B4:: @ 0x086254B4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086254B4.bin"

	.align 2
gDirectSound_086260E4:: @ 0x086260E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086260E4.bin"

	.align 2
gDirectSound_08627948:: @ 0x08627948
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08627948.bin"

	.align 2
gDirectSound_086281CC:: @ 0x086281CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086281CC.bin"

	.align 2
gDirectSound_08629024:: @ 0x08629024
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08629024.bin"

	.align 2
gDirectSound_08629A10:: @ 0x08629A10
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08629A10.bin"

	.align 2
gDirectSound_0862A080:: @ 0x0862A080
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862A080.bin"

	.align 2
gDirectSound_0862ACA8:: @ 0x0862ACA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862ACA8.bin"

	.align 2
gDirectSound_0862B460:: @ 0x0862B460
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862B460.bin"

	.align 2
gDirectSound_0862BBBC:: @ 0x0862BBBC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862BBBC.bin"

	.align 2
gDirectSound_0862CC74:: @ 0x0862CC74
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862CC74.bin"

	.align 2
gDirectSound_0862D9D8:: @ 0x0862D9D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862D9D8.bin"

	.align 2
gDirectSound_0862EEBC:: @ 0x0862EEBC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862EEBC.bin"

	.align 2
gDirectSound_0862F7B8:: @ 0x0862F7B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862F7B8.bin"

	.align 2
gDirectSound_086307C0:: @ 0x086307C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086307C0.bin"

	.align 2
gDirectSound_08631240:: @ 0x08631240
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08631240.bin"

	.align 2
gDirectSound_086325F4:: @ 0x086325F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086325F4.bin"

	.align 2
gDirectSound_08632D08:: @ 0x08632D08
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08632D08.bin"

	.align 2
gDirectSound_08634220:: @ 0x08634220
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08634220.bin"

	.align 2
gDirectSound_08634A24:: @ 0x08634A24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08634A24.bin"

	.align 2
gDirectSound_08635B84:: @ 0x08635B84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08635B84.bin"

	.align 2
gDirectSound_086364D0:: @ 0x086364D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086364D0.bin"

	.align 2
gDirectSound_08637BF0:: @ 0x08637BF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08637BF0.bin"

	.align 2
gDirectSound_0863852C:: @ 0x0863852C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863852C.bin"

	.align 2
gDirectSound_08639628:: @ 0x08639628
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08639628.bin"

	.align 2
gDirectSound_0863A22C:: @ 0x0863A22C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863A22C.bin"

	.align 2
gDirectSound_0863BAE4:: @ 0x0863BAE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863BAE4.bin"

	.align 2
gDirectSound_0863C224:: @ 0x0863C224
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863C224.bin"

	.align 2
gDirectSound_0863CEC4:: @ 0x0863CEC4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863CEC4.bin"

	.align 2
gDirectSound_0863D8E8:: @ 0x0863D8E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863D8E8.bin"

	.align 2
gDirectSound_0863E6EC:: @ 0x0863E6EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863E6EC.bin"

	.align 2
gDirectSound_086400F4:: @ 0x086400F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086400F4.bin"

	.align 2
gDirectSound_086409E4:: @ 0x086409E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086409E4.bin"

	.align 2
gDirectSound_08642094:: @ 0x08642094
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08642094.bin"

	.align 2
gDirectSound_08642D18:: @ 0x08642D18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08642D18.bin"

	.align 2
gDirectSound_08644078:: @ 0x08644078
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08644078.bin"

	.align 2
gDirectSound_08645874:: @ 0x08645874
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08645874.bin"

	.align 2
gDirectSound_086468A0:: @ 0x086468A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086468A0.bin"

	.align 2
gDirectSound_08647074:: @ 0x08647074
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08647074.bin"

	.align 2
gDirectSound_086497B8:: @ 0x086497B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086497B8.bin"

	.align 2
gDirectSound_0864A234:: @ 0x0864A234
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864A234.bin"

	.align 2
gDirectSound_0864AA54:: @ 0x0864AA54
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864AA54.bin"

	.align 2
gDirectSound_0864BAD8:: @ 0x0864BAD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864BAD8.bin"

	.align 2
gDirectSound_0864C08C:: @ 0x0864C08C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864C08C.bin"

	.align 2
gDirectSound_0864CC64:: @ 0x0864CC64
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864CC64.bin"

	.align 2
gDirectSound_0864F0B0:: @ 0x0864F0B0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864F0B0.bin"

	.align 2
gDirectSound_08650300:: @ 0x08650300
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08650300.bin"

	.align 2
gDirectSound_086512E8:: @ 0x086512E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086512E8.bin"

	.align 2
gDirectSound_08652954:: @ 0x08652954
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08652954.bin"

	.align 2
gDirectSound_086532FC:: @ 0x086532FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086532FC.bin"

	.align 2
gDirectSound_0865502C:: @ 0x0865502C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865502C.bin"

	.align 2
gDirectSound_08655BE4:: @ 0x08655BE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08655BE4.bin"

	.align 2
gDirectSound_086572B8:: @ 0x086572B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086572B8.bin"

	.align 2
gDirectSound_08657C58:: @ 0x08657C58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08657C58.bin"

	.align 2
gDirectSound_08658F2C:: @ 0x08658F2C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08658F2C.bin"

	.align 2
gDirectSound_0865B6A4:: @ 0x0865B6A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865B6A4.bin"

	.align 2
gDirectSound_0865BE78:: @ 0x0865BE78
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865BE78.bin"

	.align 2
gDirectSound_0865D280:: @ 0x0865D280
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865D280.bin"

	.align 2
gDirectSound_0865F25C:: @ 0x0865F25C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865F25C.bin"

	.align 2
gDirectSound_0866125C:: @ 0x0866125C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866125C.bin"

	.align 2
gDirectSound_08662960:: @ 0x08662960
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08662960.bin"

	.align 2
gDirectSound_086635F8:: @ 0x086635F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086635F8.bin"

	.align 2
gDirectSound_08664180:: @ 0x08664180
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08664180.bin"

	.align 2
gDirectSound_08665298:: @ 0x08665298
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08665298.bin"

	.align 2
gDirectSound_08665BE0:: @ 0x08665BE0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08665BE0.bin"

	.align 2
gDirectSound_08666F6C:: @ 0x08666F6C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08666F6C.bin"

	.align 2
gDirectSound_08667D24:: @ 0x08667D24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08667D24.bin"

	.align 2
gDirectSound_086688C8:: @ 0x086688C8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086688C8.bin"

	.align 2
gDirectSound_08669448:: @ 0x08669448
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08669448.bin"

	.align 2
gDirectSound_08669D74:: @ 0x08669D74
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08669D74.bin"

	.align 2
gDirectSound_0866B24C:: @ 0x0866B24C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866B24C.bin"

	.align 2
gDirectSound_0866CBF0:: @ 0x0866CBF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866CBF0.bin"

	.align 2
gDirectSound_0866E020:: @ 0x0866E020
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866E020.bin"

	.align 2
gDirectSound_0866E4FC:: @ 0x0866E4FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866E4FC.bin"

	.align 2
gDirectSound_08670A08:: @ 0x08670A08
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08670A08.bin"

	.align 2
gDirectSound_08672DC0:: @ 0x08672DC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08672DC0.bin"

	.align 2
gDirectSound_08674AEC:: @ 0x08674AEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08674AEC.bin"

	.align 2
gDirectSound_08676408:: @ 0x08676408
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08676408.bin"

	.align 2
gDirectSound_086770C8:: @ 0x086770C8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086770C8.bin"

	.align 2
gDirectSound_086779A0:: @ 0x086779A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086779A0.bin"

	.align 2
gDirectSound_0867983C:: @ 0x0867983C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867983C.bin"

	.align 2
gDirectSound_0867B900:: @ 0x0867B900
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867B900.bin"

	.align 2
gDirectSound_0867D560:: @ 0x0867D560
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867D560.bin"

	.align 2
gDirectSound_0867E0F0:: @ 0x0867E0F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867E0F0.bin"

	.align 2
gDirectSound_0867FD38:: @ 0x0867FD38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867FD38.bin"

	.align 2
gDirectSound_08680A60:: @ 0x08680A60
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08680A60.bin"

	.align 2
gDirectSound_08683470:: @ 0x08683470
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08683470.bin"

	.align 2
gDirectSound_08683C94:: @ 0x08683C94
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08683C94.bin"

	.align 2
gDirectSound_08684D9C:: @ 0x08684D9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08684D9C.bin"

	.align 2
gDirectSound_08686394:: @ 0x08686394
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08686394.bin"

	.align 2
gDirectSound_08687118:: @ 0x08687118
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08687118.bin"

	.align 2
gDirectSound_086885EC:: @ 0x086885EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086885EC.bin"

.include "sound/songs/mus_title.s"
.include "sound/songs/mus_table_select.s"
.include "sound/songs/mus_unk_5.s"
.include "sound/songs/mus_unk_6.s"
.include "sound/songs/mus_opening.s"
.include "sound/songs/mus_high_score.s"
.include "sound/songs/mus_shop.s"
.include "sound/songs/mus_slots_prize.s"
.include "sound/songs/mus_end_of_ball.s"
.include "sound/songs/mus_bonus_chance.s"
.include "sound/songs/mus_bonus_chance_legendary.s"
.include "sound/songs/mus_travel_mode_start.s"
.include "sound/songs/mus_success.s"
.include "sound/songs/mus_success2.s"
.include "sound/songs/mus_end_of_ball2.s"
.include "sound/songs/mus_unk_14.s"
.include "sound/songs/mus_egg_mode.s"
.include "sound/songs/mus_egg_mode_start.s"
.include "sound/songs/mus_travel_mode.s"
.include "sound/songs/mus_unk_18.s"
.include "sound/songs/mus_hurry_up.s"
.include "sound/songs/mus_evolution.s"
.include "sound/songs/mus_field_ruby.s"
.include "sound/songs/mus_catch_em_mode.s"
.include "sound/songs/mus_evo_mode.s"
.include "sound/songs/mus_field_sapphire.s"
.include "sound/songs/mus_catch_em_mode2.s"
.include "sound/songs/mus_evo_mode2.s"
.include "sound/songs/mus_bonus_field_kecleon.s"
.include "sound/songs/mus_bonus_field_duskull.s"
.include "sound/songs/mus_bonus_field_dusclops.s"
.include "sound/songs/mus_bonus_field_spheal.s"
.include "sound/songs/mus_bonus_field_groudon.s"
.include "sound/songs/mus_bonus_field_kyogre.s"
.include "sound/songs/mus_bonus_field_rayquaza.s"
.include "sound/songs/mus_success3.s"
.include "sound/songs/mus_end_of_ball3.s"
.include "sound/songs/mus_pokedex.s"
.include "sound/songs/mus_jirachi.s"
.include "sound/songs/mus_field_ruby2.s"
.include "sound/songs/mus_field_sapphire2.s"
.include "sound/songs/mus_unk_5d.s"
.include "sound/songs/se_menu_select.s"
.include "sound/songs/se_menu_cancel.s"
.include "sound/songs/se_menu_move.s"
.include "sound/songs/se_menu_popup_open.s"
.include "sound/songs/se_menu_popup_close.s"
.include "sound/songs/se_score_entry_a_b_move.s"
.include "sound/songs/se_score_entry_letter_change.s"
.include "sound/songs/se_unk_6c.s"
.include "sound/songs/se_unk_6d.s"
.include "sound/songs/se_unk_6e.s"
.include "sound/songs/se_unk_6f.s"
.include "sound/songs/se_unk_71.s"
.include "sound/songs/se_flipper_pressed.s"
.include "sound/songs/se_slingshot_hit.s"
.include "sound/songs/se_pokemon_catch_hit.s"
.include "sound/songs/se_unk_75.s"
.include "sound/songs/se_trigger_button_hit.s"
.include "sound/songs/se_wall_hit.s"
.include "sound/songs/se_tilt_triggered.s"
.include "sound/songs/se_unk_79.s"
.include "sound/songs/se_unk_7a.s"
.include "sound/songs/se_unk_7b.s"
.include "sound/songs/se_unk_7c.s"
.include "sound/songs/se_unk_7d.s"
.include "sound/songs/se_unk_7e.s"
.include "sound/songs/se_unk_7f.s"
.include "sound/songs/se_unk_80.s"
.include "sound/songs/se_unk_81.s"
.include "sound/songs/se_evo_selection_move.s"
.include "sound/songs/se_evo_selection_confirm.s"
.include "sound/songs/se_unk_84.s"
.include "sound/songs/se_unk_85.s"
.include "sound/songs/se_unk_86.s"
.include "sound/songs/se_unk_87.s"
.include "sound/songs/se_unk_88.s"
.include "sound/songs/se_unk_89.s"
.include "sound/songs/se_failure.s"
.include "sound/songs/se_unk_8b.s"
.include "sound/songs/se_unk_8c.s"
.include "sound/songs/se_unk_8d.s"
.include "sound/songs/se_unk_8e.s"
.include "sound/songs/se_unk_8f.s"
.include "sound/songs/se_unk_91.s"
.include "sound/songs/se_unk_92.s"
.include "sound/songs/se_unk_93.s"
.include "sound/songs/se_unk_94.s"
.include "sound/songs/se_unk_95.s"
.include "sound/songs/se_unk_96.s"
.include "sound/songs/se_unk_97.s"
.include "sound/songs/se_unk_98.s"
.include "sound/songs/se_unk_99.s"
.include "sound/songs/se_unk_9a.s"
.include "sound/songs/se_unk_9b.s"
.include "sound/songs/se_unk_9c.s"
.include "sound/songs/se_unk_9d.s"
.include "sound/songs/se_unk_9e.s"
.include "sound/songs/se_unk_9f.s"
.include "sound/songs/se_unk_a0.s"
.include "sound/songs/se_unk_a1.s"
.include "sound/songs/se_unk_a2.s"
.include "sound/songs/se_unk_a3.s"
.include "sound/songs/se_unk_a4.s"
.include "sound/songs/se_unk_a5.s"
.include "sound/songs/se_unk_a6.s"
.include "sound/songs/se_unk_a7.s"
.include "sound/songs/se_pika_charge_do.s"
.include "sound/songs/se_pika_charge_re.s"
.include "sound/songs/se_pika_charge_mi.s"
.include "sound/songs/se_pika_charge_fa.s"
.include "sound/songs/se_pika_charge_so.s"
.include "sound/songs/se_pika_charge_la.s"
.include "sound/songs/se_pika_charge_ti.s"
.include "sound/songs/se_pika_charge_high_do.s"
.include "sound/songs/se_unk_b0.s"
.include "sound/songs/se_unk_b1.s"
.include "sound/songs/se_unk_b2.s"
.include "sound/songs/se_unk_b3.s"
.include "sound/songs/se_unk_b4.s"
.include "sound/songs/se_unk_b6.s"
.include "sound/songs/se_unk_b7.s"
.include "sound/songs/se_unk_b8.s"
.include "sound/songs/se_unk_b9.s"
.include "sound/songs/se_unk_ba.s"
.include "sound/songs/se_unk_bb.s"
.include "sound/songs/se_unk_bc.s"
.include "sound/songs/se_unk_bd.s"
.include "sound/songs/se_unk_be.s"
.include "sound/songs/se_unk_bf.s"
.include "sound/songs/se_unk_c0.s"
.include "sound/songs/se_unk_c1.s"
.include "sound/songs/se_unk_c2.s"
.include "sound/songs/se_unk_c3.s"
.include "sound/songs/se_unk_c4.s"
.include "sound/songs/se_unk_c5.s"
.include "sound/songs/se_unk_c6.s"
.include "sound/songs/se_unk_c7.s"
.include "sound/songs/se_unk_c8.s"
.include "sound/songs/se_unk_c9.s"
.include "sound/songs/se_unk_ca.s"
.include "sound/songs/se_unk_cb.s"
.include "sound/songs/se_unk_cc.s"
.include "sound/songs/se_unk_cd.s"
.include "sound/songs/se_unk_ce.s"
.include "sound/songs/se_unk_cf.s"
.include "sound/songs/se_unk_d0.s"
.include "sound/songs/se_unk_d1.s"
.include "sound/songs/se_unk_d2.s"
.include "sound/songs/se_unk_d3.s"
.include "sound/songs/se_unk_d4.s"
.include "sound/songs/se_unk_d5.s"
.include "sound/songs/se_unk_d6.s"
.include "sound/songs/se_unk_d7.s"
.include "sound/songs/se_unk_d8.s"
.include "sound/songs/se_unk_dc.s"
.include "sound/songs/se_unk_dd.s"
.include "sound/songs/se_unk_de.s"
.include "sound/songs/se_unk_df.s"
.include "sound/songs/se_unk_e0.s"
.include "sound/songs/se_unk_e1.s"
.include "sound/songs/se_unk_e2.s"
.include "sound/songs/se_unk_e3.s"
.include "sound/songs/se_unk_e4.s"
.include "sound/songs/se_unk_e5.s"
.include "sound/songs/se_unk_e6.s"
.include "sound/songs/se_unk_e7.s"
.include "sound/songs/se_unk_e8.s"
.include "sound/songs/se_unk_e9.s"
.include "sound/songs/se_unk_ea.s"
.include "sound/songs/se_unk_eb.s"
.include "sound/songs/se_unk_ec.s"
.include "sound/songs/se_unk_f1.s"
.include "sound/songs/se_unk_f2.s"
.include "sound/songs/se_dusclops_depart_incomplete.s"
.include "sound/songs/se_dusclops_move.s"
.include "sound/songs/se_dusclops_appear.s"
.include "sound/songs/se_dusclops_hit.s"
.include "sound/songs/se_dusclops_ball_absorb.s"
.include "sound/songs/se_dusclops_ball_launch.s"
.include "sound/songs/se_unk_f9.s"
.include "sound/songs/se_unk_fa.s"
.include "sound/songs/se_unk_fc.s"
.include "sound/songs/se_unk_fd.s"
.include "sound/songs/se_unk_fe.s"
.include "sound/songs/se_unk_ff.s"
.include "sound/songs/se_unk_100.s"
.include "sound/songs/se_unk_101.s"
.include "sound/songs/se_unk_102.s"
.include "sound/songs/se_unk_103.s"
.include "sound/songs/se_kecleon_tree_hit.s"
.include "sound/songs/se_kecleon_scope_fall.s"
.include "sound/songs/se_kecleon_scope_activated.s"
.include "sound/songs/se_unk_10a.s"
.include "sound/songs/se_unk_10b.s"
.include "sound/songs/se_unk_10c.s"
.include "sound/songs/se_unk_10d.s"
.include "sound/songs/se_unk_10e.s"
.include "sound/songs/se_unk_10f.s"
.include "sound/songs/se_unk_110.s"
.include "sound/songs/se_unk_111.s"
.include "sound/songs/se_unk_112.s"
.include "sound/songs/se_unk_113.s"
.include "sound/songs/se_unk_118.s"
.include "sound/songs/se_unk_119.s"
.include "sound/songs/se_unk_11a.s"
.include "sound/songs/se_unk_11b.s"
.include "sound/songs/se_unk_11c.s"
.include "sound/songs/se_unk_11d.s"
.include "sound/songs/se_unk_11e.s"
.include "sound/songs/se_unk_11f.s"
.include "sound/songs/se_unk_120.s"
.include "sound/songs/se_groudon_boulder_land.s"
.include "sound/songs/se_groudon_dustorm_lift.s"
.include "sound/songs/se_groudon_ball_hit_fire.s"
.include "sound/songs/se_rayquaza_hit.s"
.include "sound/songs/se_rayquaza_wind.s"
.include "sound/songs/se_unk_128.s"
.include "sound/songs/se_rayquaza_flyby.s"
.include "sound/songs/se_unk_12a.s"
.include "sound/songs/se_unk_12b.s"
.include "sound/songs/se_unk_12c.s"
.include "sound/songs/se_unk_12d.s"
.include "sound/songs/se_rayquaza_stage_wind.s"
.include "sound/songs/se_unk_134.s"
.include "sound/songs/se_unk_135.s"
.include "sound/songs/se_unk_136.s"
.include "sound/songs/se_unk_137.s"
.include "sound/songs/se_unk_138.s"
.include "sound/songs/se_unk_139.s"
.include "sound/songs/se_unk_13b.s"
.include "sound/songs/se_unk_13c.s"
.include "sound/songs/se_unk_13d.s"
.include "sound/songs/se_unk_13e.s"
.include "sound/songs/se_unk_13f.s"
.include "sound/songs/se_unk_140.s"
.include "sound/songs/se_unk_142.s"
.include "sound/songs/se_jirachi_move.s"
.include "sound/songs/se_jirachi_hit.s"
.include "sound/songs/se_unk_146.s"
.include "sound/songs/se_unk_147.s"
.include "sound/songs/se_unk_148.s"
.include "sound/songs/se_unk_149.s"
.include "sound/songs/se_high_score_earned.s"
.include "sound/songs/se_unk_14b.s"
.include "sound/songs/se_unk_14c.s"

@ This is not sound data below. It's some kind of save file descriptor (SRAM_F_V102).
.incbin "baserom.gba", 0x6A369C, 0x6A3700 - 0x6A369C
