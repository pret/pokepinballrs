.section .rodata

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

gVoiceGroup_Inst_0852DDE0:: @ 0x0852DDE0
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

gVoiceGroup_Evolution_0852E404:: @ 0x0852E404
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

gVoiceGroup_HurryUp_0852E95C:: @ 0x0852E95C
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

gVoiceGroup_Pokedex_0852EF5C:: @ 0x0852EF5C
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

gVoiceGroup_Title_0852F55C:: @ 0x0852F55C
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

gVoiceGroup_Jirachi_0852FB5C:: @ 0x0852FB5C
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

gVoiceGroup_EggModeStart_0853015C:: @ 0x0853015C
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

gVoiceGroup_EggMode_0853075C:: @ 0x0853075C
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

gVoiceGroup_EvoMode_08530D5C:: @ 0x08530D5C
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

gVoiceGroup_UnkMus_0853135C:: @ 0x0853135C
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

gVoiceGroup_SFX_0853174C:: @ 0x0853174C
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

gVoiceGroup_SFX_08531D4C:: @ 0x08531D4C
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

gVoiceGroup_SFX_08532310:: @ 0x08532310
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
	voice_directsound 60, 0, gDirectSound_08584B2C, 255, 0, 255, 0 @ 30
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
	voice_directsound_compressed gDirectSound_se_pikachu_kickback @ 101
	voice_directsound_compressed gDirectSound_se_pika_no_kickback
	voice_directsound_compressed gDirectSound_se_pichu_kickback_enabled
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_se_pichu_kickback

gVoiceGroup_Inst_08532808:: @ 0x08532808
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

gPokemonCryToneBank0:: @ 0x08532D6C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry025_Pikachu
	voice_directsound_compressed gDirectSound_Cry026_Raichu
	voice_directsound_compressed gDirectSound_Cry027_Sandshrew
	voice_directsound_compressed gDirectSound_Cry028_Sandslash
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry037_Vulpix
	voice_directsound_compressed gDirectSound_Cry038_Ninetales
	voice_directsound_compressed gDirectSound_Cry039_Jigglypuff
	voice_directsound_compressed gDirectSound_Cry040_Wigglytuff
	voice_directsound_compressed gDirectSound_Cry041_Zubat
	voice_directsound_compressed gDirectSound_Cry042_Golbat
	voice_directsound_compressed gDirectSound_Cry043_Oddish
	voice_directsound_compressed gDirectSound_Cry044_Gloom
	voice_directsound_compressed gDirectSound_Cry045_Vileplume
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry054_Psyduck
	voice_directsound_compressed gDirectSound_Cry055_Golduck
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry063_Abra
	voice_directsound_compressed gDirectSound_Cry064_Kadabra
	voice_directsound_compressed gDirectSound_Cry065_Alakazam
	voice_directsound_compressed gDirectSound_Cry066_Machop
	voice_directsound_compressed gDirectSound_Cry067_Machoke
	voice_directsound_compressed gDirectSound_Cry068_Machamp
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry072_Tentacool
	voice_directsound_compressed gDirectSound_Cry073_Tentacruel
	voice_directsound_compressed gDirectSound_Cry074_Geodude
	voice_directsound_compressed gDirectSound_Cry075_Graveler
	voice_directsound_compressed gDirectSound_Cry076_Golem
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry081_Magnemite
	voice_directsound_compressed gDirectSound_Cry082_Magneton
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry084_Doduo
	voice_directsound_compressed gDirectSound_Cry085_Dodrio
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry088_Grimer
	voice_directsound_compressed gDirectSound_Cry089_Muk
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry100_Voltorb
	voice_directsound_compressed gDirectSound_Cry101_Electrode
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry109_Koffing
	voice_directsound_compressed gDirectSound_Cry110_Weezing
	voice_directsound_compressed gDirectSound_Cry111_Rhyhorn
	voice_directsound_compressed gDirectSound_Cry112_Rhydon
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry116_Horsea
	voice_directsound_compressed gDirectSound_Cry117_Seadra
	voice_directsound_compressed gDirectSound_Cry118_Goldeen
	voice_directsound_compressed gDirectSound_Cry119_Seaking
	voice_directsound_compressed gDirectSound_Cry120_Staryu
	voice_directsound_compressed gDirectSound_Cry121_Starmie
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry127_Pinsir
	@ note: array stops 1 early; should have a row for Tauros here

gPokemonCryToneBank1:: @ 0x08533360
	voice_directsound_compressed gDirectSound_Cry129_Magikarp
	voice_directsound_compressed gDirectSound_Cry130_Gyarados
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry142_Aerodactyl
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry152_Chikorita
	voice_directsound_compressed gDirectSound_Cry153_Bayleef
	voice_directsound_compressed gDirectSound_Cry154_Meganium
	voice_directsound_compressed gDirectSound_Cry155_Cyndaquil
	voice_directsound_compressed gDirectSound_Cry156_Quilava
	voice_directsound_compressed gDirectSound_Cry157_Typhlosion
	voice_directsound_compressed gDirectSound_Cry158_Totodile
	voice_directsound_compressed gDirectSound_Cry159_Croconaw
	voice_directsound_compressed gDirectSound_Cry160_Feraligatr
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry169_Crobat
	voice_directsound_compressed gDirectSound_Cry170_Chinchou
	voice_directsound_compressed gDirectSound_Cry171_Lanturn
	voice_directsound_compressed gDirectSound_Cry172_Pichu
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry174_Igglybuff
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry177_Natu
	voice_directsound_compressed gDirectSound_Cry178_Xatu
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry182_Bellossom
	voice_directsound_compressed gDirectSound_Cry183_Marill
	voice_directsound_compressed gDirectSound_Cry184_Azumarill
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry202_Wobbuffet
	voice_directsound_compressed gDirectSound_Cry203_Girafarig
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry214_Heracross
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry218_Slugma
	voice_directsound_compressed gDirectSound_Cry219_Magcargo
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry222_Corsola
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry227_Skarmory
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry230_Kingdra
	voice_directsound_compressed gDirectSound_Cry231_Phanpy
	voice_directsound_compressed gDirectSound_Cry232_Donphan
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry251_Celebi @Celebi
	voice_directsound_compressed gDirectSound_Cry252_Kecleon @KECLEON
	voice_directsound_compressed gDirectSound_Cry253_Roselia
	voice_directsound_compressed gDirectSound_Cry254_Torkoal
	voice_directsound_compressed gDirectSound_Cry255_Electrike
	voice_directsound_compressed gDirectSound_Cry256_Manectric

gPokemonCryToneBank2:: @ 0x08533960
	voice_directsound_compressed gDirectSound_Cry257_Duskull
	voice_directsound_compressed gDirectSound_Cry258_Latias
	voice_directsound_compressed gDirectSound_Cry259_Wynaut
	voice_directsound_compressed gDirectSound_Cry260_Seviper
	voice_directsound_compressed gDirectSound_Cry261_Sharpedo
	voice_directsound_compressed gDirectSound_Cry262_Zangoose
	voice_directsound_compressed gDirectSound_Cry263_Azurill
	voice_directsound_compressed gDirectSound_Cry264_Swablu
	voice_directsound_compressed gDirectSound_Cry265_Altaria
	voice_directsound_compressed gDirectSound_Cry266_Unused
	voice_directsound_compressed gDirectSound_Cry267_Taillow
	voice_directsound_compressed gDirectSound_Cry268_Swellow
	voice_directsound_compressed gDirectSound_Cry269_Unused
	voice_directsound_compressed gDirectSound_Cry270_Spinda
	voice_directsound_compressed gDirectSound_Cry271_Torchic
	voice_directsound_compressed gDirectSound_Cry272_Combusken
	voice_directsound_compressed gDirectSound_Cry273_Blaziken
	voice_directsound_compressed gDirectSound_Cry274_Treecko @TREECKO
	voice_directsound_compressed gDirectSound_Cry275_Grovyle
	voice_directsound_compressed gDirectSound_Cry276_Sceptile
	voice_directsound_compressed gDirectSound_Cry277_Mudkip
	voice_directsound_compressed gDirectSound_Cry278_Marshtomp
	voice_directsound_compressed gDirectSound_Cry279_Swampert
	voice_directsound_compressed gDirectSound_Cry280_Pelipper
	voice_directsound_compressed gDirectSound_Cry281_Wingull
	voice_directsound_compressed gDirectSound_Cry282_Banette
	voice_directsound_compressed gDirectSound_Cry283_Shuppet
	voice_directsound_compressed gDirectSound_Cry284_Lotad
	voice_directsound_compressed gDirectSound_Cry285_Lombre
	voice_directsound_compressed gDirectSound_Cry286_Ludicolo
	voice_directsound_compressed gDirectSound_Cry287_Seedot
	voice_directsound_compressed gDirectSound_Cry288_Nuzleaf
	voice_directsound_compressed gDirectSound_Cry289_Shiftry
	voice_directsound_compressed gDirectSound_Cry290_Carvanha
	voice_directsound_compressed gDirectSound_Cry291_Wurmple
	voice_directsound_compressed gDirectSound_Cry292_Silcoon
	voice_directsound_compressed gDirectSound_Cry293_Beautifly
	voice_directsound_compressed gDirectSound_Cry294_Cascoon
	voice_directsound_compressed gDirectSound_Cry295_Dustox
	voice_directsound_compressed gDirectSound_Cry296_Ralts
	voice_directsound_compressed gDirectSound_Cry297_Kirlia
	voice_directsound_compressed gDirectSound_Cry298_Gardevoir
	voice_directsound_compressed gDirectSound_Cry299_Slakoth
	voice_directsound_compressed gDirectSound_Cry300_Vigoroth
	voice_directsound_compressed gDirectSound_Cry301_Slaking
	voice_directsound_compressed gDirectSound_Cry302_Nincada
	voice_directsound_compressed gDirectSound_Cry303_Ninjask
	voice_directsound_compressed gDirectSound_Cry304_Shedinja
	voice_directsound_compressed gDirectSound_Cry305_Makuhita
	voice_directsound_compressed gDirectSound_Cry306_Hariyama
	voice_directsound_compressed gDirectSound_Cry307_Nosepass
	voice_directsound_compressed gDirectSound_Cry308_Glalie
	voice_directsound_compressed gDirectSound_Cry309_Plusle
	voice_directsound_compressed gDirectSound_Cry310_Minun
	voice_directsound_compressed gDirectSound_Cry311_Surskit
	voice_directsound_compressed gDirectSound_Cry312_Masquerain
	voice_directsound_compressed gDirectSound_Cry313_Skitty
	voice_directsound_compressed gDirectSound_Cry314_Delcatty
	voice_directsound_compressed gDirectSound_Cry315_Gulpin
	voice_directsound_compressed gDirectSound_Cry316_Swalot
	voice_directsound_compressed gDirectSound_Cry317_Numel
	voice_directsound_compressed gDirectSound_Cry318_Camerupt
	voice_directsound_compressed gDirectSound_Cry319_Barboach
	voice_directsound_compressed gDirectSound_Cry320_Whiscash
	voice_directsound_compressed gDirectSound_Cry321_Corphish
	voice_directsound_compressed gDirectSound_Cry322_Crawdaunt
	voice_directsound_compressed gDirectSound_Cry323_Spoink
	voice_directsound_compressed gDirectSound_Cry324_Grumpig
	voice_directsound_compressed gDirectSound_Cry325_Trapinch
	voice_directsound_compressed gDirectSound_Cry326_Vibrava
	voice_directsound_compressed gDirectSound_Cry327_Flygon
	voice_directsound_compressed gDirectSound_Cry328_Cacnea
	voice_directsound_compressed gDirectSound_Cry329_Cacturne
	voice_directsound_compressed gDirectSound_Cry330_Baltoy
	voice_directsound_compressed gDirectSound_Cry331_Claydol
	voice_directsound_compressed gDirectSound_Cry332_Lunatone
	voice_directsound_compressed gDirectSound_Cry333_Solrock
	voice_directsound_compressed gDirectSound_Cry334_Feebas
	voice_directsound_compressed gDirectSound_Cry335_Milotic
	voice_directsound_compressed gDirectSound_Cry336_Absol
	voice_directsound_compressed gDirectSound_Cry337_Meditite
	voice_directsound_compressed gDirectSound_Cry338_Medicham
	voice_directsound_compressed gDirectSound_Cry339_Spheal
	voice_directsound_compressed gDirectSound_Cry340_Sealeo
	voice_directsound_compressed gDirectSound_Cry341_Walrein
	voice_directsound_compressed gDirectSound_Cry342_Clamperl
	voice_directsound_compressed gDirectSound_Cry343_Huntail
	voice_directsound_compressed gDirectSound_Cry344_Gorebyss
	voice_directsound_compressed gDirectSound_Cry345_Lileep
	voice_directsound_compressed gDirectSound_Cry346_Cradily
	voice_directsound_compressed gDirectSound_Cry347_Anorith
	voice_directsound_compressed gDirectSound_Cry348_Armaldo
	voice_directsound_compressed gDirectSound_Cry349_Beldum
	voice_directsound_compressed gDirectSound_Cry350_Metang
	voice_directsound_compressed gDirectSound_Cry351_Metagross
	voice_directsound_compressed gDirectSound_Cry352_Bagon
	voice_directsound_compressed gDirectSound_Cry353_Shelgon
	voice_directsound_compressed gDirectSound_Cry354_Regirock
	voice_directsound_compressed gDirectSound_Cry355_Regice
	voice_directsound_compressed gDirectSound_Cry356_Registeel
	voice_directsound_compressed gDirectSound_Cry357_Castform
	voice_directsound_compressed gDirectSound_Cry358_Volbeat
	voice_directsound_compressed gDirectSound_Cry359_Illumise
	voice_directsound_compressed gDirectSound_Cry360_Poochyena
	voice_directsound_compressed gDirectSound_Cry361_Mightyena
	voice_directsound_compressed gDirectSound_Cry362_Dusclops
	voice_directsound_compressed gDirectSound_Cry363_Sableye
	voice_directsound_compressed gDirectSound_Cry364_Mawile
	voice_directsound_compressed gDirectSound_Cry365_Aron
	voice_directsound_compressed gDirectSound_Cry366_Lairon
	voice_directsound_compressed gDirectSound_Cry367_Aggron
	voice_directsound_compressed gDirectSound_Cry368_Relicanth
	voice_directsound_compressed gDirectSound_Cry369_Luvdisc
	voice_directsound_compressed gDirectSound_Cry370_Groudon
	voice_directsound_compressed gDirectSound_Cry371_Kyogre
	voice_directsound_compressed gDirectSound_Cry372_Rayquaza
	voice_directsound_compressed gDirectSound_Cry373_Salamence
	voice_directsound_compressed gDirectSound_Cry374_Breloom
	voice_directsound_compressed gDirectSound_Cry375_Shroomish
	voice_directsound_compressed gDirectSound_Cry376_Linoone
	voice_directsound_compressed gDirectSound_Cry377_Tropius
	voice_directsound_compressed gDirectSound_Cry378_Wailmer
	voice_directsound_compressed gDirectSound_Cry379_Zigzagoon
	voice_directsound_compressed gDirectSound_Cry380_Exploud
	voice_directsound_compressed gDirectSound_Cry381_Loured
	voice_directsound_compressed gDirectSound_Cry382_Wailord
	voice_directsound_compressed gDirectSound_Cry383_Whismur
	voice_directsound_compressed gDirectSound_Cry384_Snorunt

gPokemonCryToneBank3:: @ 0x08533F60
	voice_directsound_compressed gDirectSound_Cry385_Latios
	voice_directsound_compressed gDirectSound_Cry386_Jirachi
	voice_directsound_compressed gDirectSound_Cry387_Deoxys
	voice_directsound_compressed gDirectSound_Cry388_Chimecho
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_Cry142_Aerodactyl
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_Cry152_Chikorita
	voice_directsound_compressed_reverse gDirectSound_Cry153_Bayleef
	voice_directsound_compressed_reverse gDirectSound_Cry154_Meganium
	voice_directsound_compressed_reverse gDirectSound_Cry155_Cyndaquil
	voice_directsound_compressed_reverse gDirectSound_Cry156_Quilava
	voice_directsound_compressed_reverse gDirectSound_Cry157_Typhlosion
	voice_directsound_compressed_reverse gDirectSound_Cry158_Totodile
	voice_directsound_compressed_reverse gDirectSound_Cry159_Croconaw
	voice_directsound_compressed_reverse gDirectSound_Cry160_Feraligatr
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_Cry251_Celebi
	voice_directsound_compressed_reverse gDirectSound_Cry252_Kecleon
	voice_directsound_compressed_reverse gDirectSound_Cry253_Roselia
	voice_directsound_compressed_reverse gDirectSound_Cry254_Torkoal
	voice_directsound_compressed_reverse gDirectSound_Cry255_Electrike
	voice_directsound_compressed_reverse gDirectSound_Cry256_Manectric
	voice_directsound_compressed_reverse gDirectSound_Cry257_Duskull
	voice_directsound_compressed_reverse gDirectSound_Cry258_Latias
	voice_directsound_compressed_reverse gDirectSound_Cry259_Wynaut
	voice_directsound_compressed_reverse gDirectSound_Cry260_Seviper
	voice_directsound_compressed_reverse gDirectSound_Cry261_Sharpedo
	voice_directsound_compressed_reverse gDirectSound_Cry262_Zangoose
	voice_directsound_compressed_reverse gDirectSound_Cry263_Azurill
	voice_directsound_compressed_reverse gDirectSound_Cry264_Swablu
	voice_directsound_compressed_reverse gDirectSound_Cry265_Altaria
	voice_directsound_compressed_reverse gDirectSound_Cry266_Unused
	voice_directsound_compressed_reverse gDirectSound_Cry267_Taillow
	voice_directsound_compressed_reverse gDirectSound_Cry268_Swellow
	voice_directsound_compressed_reverse gDirectSound_Cry269_Unused
	voice_directsound_compressed_reverse gDirectSound_Cry270_Spinda
	voice_directsound_compressed_reverse gDirectSound_Cry271_Torchic
	voice_directsound_compressed_reverse gDirectSound_Cry272_Combusken
	voice_directsound_compressed_reverse gDirectSound_Cry273_Blaziken
	voice_directsound_compressed_reverse gDirectSound_Cry274_Treecko
	voice_directsound_compressed_reverse gDirectSound_Cry275_Grovyle
	voice_directsound_compressed_reverse gDirectSound_Cry276_Sceptile
	voice_directsound_compressed_reverse gDirectSound_Cry277_Mudkip
	voice_directsound_compressed_reverse gDirectSound_Cry278_Marshtomp
	voice_directsound_compressed_reverse gDirectSound_Cry279_Swampert
	voice_directsound_compressed_reverse gDirectSound_Cry280_Pelipper
	voice_directsound_compressed_reverse gDirectSound_Cry281_Wingull
	voice_directsound_compressed_reverse gDirectSound_Cry282_Banette
	voice_directsound_compressed_reverse gDirectSound_Cry283_Shuppet
	voice_directsound_compressed_reverse gDirectSound_Cry284_Lotad
	voice_directsound_compressed_reverse gDirectSound_Cry285_Lombre
	voice_directsound_compressed_reverse gDirectSound_Cry286_Ludicolo
	voice_directsound_compressed_reverse gDirectSound_Cry287_Seedot
	voice_directsound_compressed_reverse gDirectSound_Cry288_Nuzleaf
	voice_directsound_compressed_reverse gDirectSound_Cry289_Shiftry
	voice_directsound_compressed_reverse gDirectSound_Cry290_Carvanha
	voice_directsound_compressed_reverse gDirectSound_Cry291_Wurmple
	voice_directsound_compressed_reverse gDirectSound_Cry292_Silcoon
	voice_directsound_compressed_reverse gDirectSound_Cry293_Beautifly
	voice_directsound_compressed_reverse gDirectSound_Cry294_Cascoon
	voice_directsound_compressed_reverse gDirectSound_Cry295_Dustox
	voice_directsound_compressed_reverse gDirectSound_Cry296_Ralts
	voice_directsound_compressed_reverse gDirectSound_Cry297_Kirlia
	voice_directsound_compressed_reverse gDirectSound_Cry298_Gardevoir
	voice_directsound_compressed_reverse gDirectSound_Cry299_Slakoth
	voice_directsound_compressed_reverse gDirectSound_Cry300_Vigoroth
	voice_directsound_compressed_reverse gDirectSound_Cry301_Slaking
	voice_directsound_compressed_reverse gDirectSound_Cry302_Nincada
	voice_directsound_compressed_reverse gDirectSound_Cry303_Ninjask
	voice_directsound_compressed_reverse gDirectSound_Cry304_Shedinja
	voice_directsound_compressed_reverse gDirectSound_Cry305_Makuhita
	voice_directsound_compressed_reverse gDirectSound_Cry306_Hariyama
	voice_directsound_compressed_reverse gDirectSound_Cry307_Nosepass
	voice_directsound_compressed_reverse gDirectSound_Cry308_Glalie
	voice_directsound_compressed_reverse gDirectSound_Cry309_Plusle
	voice_directsound_compressed_reverse gDirectSound_Cry310_Minun
	voice_directsound_compressed_reverse gDirectSound_Cry311_Surskit
	voice_directsound_compressed_reverse gDirectSound_Cry312_Masquerain
	voice_directsound_compressed_reverse gDirectSound_Cry313_Skitty
	voice_directsound_compressed_reverse gDirectSound_Cry314_Delcatty
	voice_directsound_compressed_reverse gDirectSound_Cry315_Gulpin
	voice_directsound_compressed_reverse gDirectSound_Cry316_Swalot
	voice_directsound_compressed_reverse gDirectSound_Cry317_Numel
	voice_directsound_compressed_reverse gDirectSound_Cry318_Camerupt
	voice_directsound_compressed_reverse gDirectSound_Cry319_Barboach
	voice_directsound_compressed_reverse gDirectSound_Cry320_Whiscash
	voice_directsound_compressed_reverse gDirectSound_Cry321_Corphish
	voice_directsound_compressed_reverse gDirectSound_Cry322_Crawdaunt
	voice_directsound_compressed_reverse gDirectSound_Cry323_Spoink
	voice_directsound_compressed_reverse gDirectSound_Cry324_Grumpig
	voice_directsound_compressed_reverse gDirectSound_Cry325_Trapinch
	voice_directsound_compressed_reverse gDirectSound_Cry326_Vibrava
	voice_directsound_compressed_reverse gDirectSound_Cry327_Flygon
	voice_directsound_compressed_reverse gDirectSound_Cry328_Cacnea
	voice_directsound_compressed_reverse gDirectSound_Cry329_Cacturne
	voice_directsound_compressed_reverse gDirectSound_Cry330_Baltoy
	voice_directsound_compressed_reverse gDirectSound_Cry331_Claydol
	voice_directsound_compressed_reverse gDirectSound_Cry332_Lunatone
	voice_directsound_compressed_reverse gDirectSound_Cry333_Solrock
	voice_directsound_compressed_reverse gDirectSound_Cry334_Feebas
	voice_directsound_compressed_reverse gDirectSound_Cry335_Milotic
	voice_directsound_compressed_reverse gDirectSound_Cry336_Absol
	voice_directsound_compressed_reverse gDirectSound_Cry337_Meditite
	voice_directsound_compressed_reverse gDirectSound_Cry338_Medicham
	voice_directsound_compressed_reverse gDirectSound_Cry339_Spheal
	voice_directsound_compressed_reverse gDirectSound_Cry340_Sealeo
	voice_directsound_compressed_reverse gDirectSound_Cry341_Walrein
	voice_directsound_compressed_reverse gDirectSound_Cry342_Clamperl
	voice_directsound_compressed_reverse gDirectSound_Cry343_Huntail
	voice_directsound_compressed_reverse gDirectSound_Cry344_Gorebyss
	voice_directsound_compressed_reverse gDirectSound_Cry345_Lileep
	voice_directsound_compressed_reverse gDirectSound_Cry346_Cradily
	voice_directsound_compressed_reverse gDirectSound_Cry347_Anorith
	voice_directsound_compressed_reverse gDirectSound_Cry348_Armaldo
	voice_directsound_compressed_reverse gDirectSound_Cry349_Beldum
	voice_directsound_compressed_reverse gDirectSound_Cry350_Metang
	voice_directsound_compressed_reverse gDirectSound_Cry351_Metagross
	voice_directsound_compressed_reverse gDirectSound_Cry352_Bagon
	voice_directsound_compressed_reverse gDirectSound_Cry353_Shelgon
	voice_directsound_compressed_reverse gDirectSound_Cry354_Regirock
	voice_directsound_compressed_reverse gDirectSound_Cry355_Regice
	voice_directsound_compressed_reverse gDirectSound_Cry356_Registeel
	voice_directsound_compressed_reverse gDirectSound_Cry357_Castform
	voice_directsound_compressed_reverse gDirectSound_Cry358_Volbeat
	voice_directsound_compressed_reverse gDirectSound_Cry359_Illumise
	voice_directsound_compressed_reverse gDirectSound_Cry360_Poochyena
	voice_directsound_compressed_reverse gDirectSound_Cry361_Mightyena
	voice_directsound_compressed_reverse gDirectSound_Cry362_Dusclops
	voice_directsound_compressed_reverse gDirectSound_Cry363_Sableye
	voice_directsound_compressed_reverse gDirectSound_Cry364_Mawile
	voice_directsound_compressed_reverse gDirectSound_Cry365_Aron
	voice_directsound_compressed_reverse gDirectSound_Cry366_Lairon
	voice_directsound_compressed_reverse gDirectSound_Cry367_Aggron
	voice_directsound_compressed_reverse gDirectSound_Cry368_Relicanth
	voice_directsound_compressed_reverse gDirectSound_Cry369_Luvdisc
	voice_directsound_compressed_reverse gDirectSound_Cry370_Groudon
	voice_directsound_compressed_reverse gDirectSound_Cry371_Kyogre
	voice_directsound_compressed_reverse gDirectSound_Cry372_Rayquaza
	voice_directsound_compressed_reverse gDirectSound_Cry373_Salamence
	voice_directsound_compressed_reverse gDirectSound_Cry374_Breloom
	voice_directsound_compressed_reverse gDirectSound_Cry375_Shroomish
	voice_directsound_compressed_reverse gDirectSound_Cry376_Linoone
	voice_directsound_compressed_reverse gDirectSound_Cry377_Tropius
	voice_directsound_compressed_reverse gDirectSound_Cry378_Wailmer
	voice_directsound_compressed_reverse gDirectSound_Cry379_Zigzagoon
	voice_directsound_compressed_reverse gDirectSound_Cry380_Exploud
	voice_directsound_compressed_reverse gDirectSound_Cry381_Loured
	voice_directsound_compressed_reverse gDirectSound_Cry382_Wailord
	voice_directsound_compressed_reverse gDirectSound_Cry383_Whismur
	voice_directsound_compressed_reverse gDirectSound_Cry384_Snorunt
	voice_directsound_compressed_reverse gDirectSound_Cry385_Latios
	voice_directsound_compressed_reverse gDirectSound_Cry386_Jirachi
	voice_directsound_compressed_reverse gDirectSound_Cry387_Deoxys
	voice_directsound_compressed_reverse gDirectSound_Cry388_Chimecho

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
gDirectSound_se_pikachu_kickback:: @ 0x0858E078
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pikachu_kickback.bin"

	.align 2
gDirectSound_se_pika_no_kickback:: @ 0x08595C7C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pika_no_kickback.bin"

	.align 2
gDirectSound_se_pichu_kickback_enabled:: @ 0x08597170
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pichu_kickback_enabled.bin"

	.align 2
gDirectSound_se_pichu_kickback:: @ 0x0859BD58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pichu_kickback.bin"

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
gDirectSound_Cry025_Pikachu:: @ 0x085ABF3C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry025_Pikachu.bin"

	.align 2
gDirectSound_Cry026_Raichu:: @ 0x085ACFE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry026_Raichu.bin"

	.align 2
gDirectSound_Cry027_Sandshrew:: @ 0x085AE7A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry027_Sandshrew.bin"

	.align 2
gDirectSound_Cry028_Sandslash:: @ 0x085AF0F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry028_Sandslash.bin"

	.align 2
gDirectSound_Cry037_Vulpix:: @ 0x085AFE88
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry037_Vulpix.bin"

	.align 2
gDirectSound_Cry038_Ninetales:: @ 0x085B1658
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry038_Ninetales.bin"

	.align 2
gDirectSound_Cry039_Jigglypuff:: @ 0x085B2EC4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry039_Jigglypuff.bin"

	.align 2
gDirectSound_Cry040_Wigglytuff:: @ 0x085B3428
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry040_Wigglytuff.bin"

	.align 2
gDirectSound_Cry041_Zubat:: @ 0x085B3AF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry041_Zubat.bin"

	.align 2
gDirectSound_Cry042_Golbat:: @ 0x085B4E5C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry042_Golbat.bin"

	.align 2
gDirectSound_Cry043_Oddish:: @ 0x085B61C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry043_Oddish.bin"

	.align 2
gDirectSound_Cry044_Gloom:: @ 0x085B705C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry044_Gloom.bin"

	.align 2
gDirectSound_Cry045_Vileplume:: @ 0x085B7CD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry045_Vileplume.bin"

	.align 2
gDirectSound_Cry054_Psyduck:: @ 0x085B9674
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry054_Psyduck.bin"

	.align 2
gDirectSound_Cry055_Golduck:: @ 0x085BA39C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry055_Golduck.bin"

	.align 2
gDirectSound_Cry063_Abra:: @ 0x085BAEE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry063_Abra.bin"

	.align 2
gDirectSound_Cry064_Kadabra:: @ 0x085BC648
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry064_Kadabra.bin"

	.align 2
gDirectSound_Cry065_Alakazam:: @ 0x085BE130
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry065_Alakazam.bin"

	.align 2
gDirectSound_Cry066_Machop:: @ 0x085C00CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry066_Machop.bin"

	.align 2
gDirectSound_Cry067_Machoke:: @ 0x085C0E30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry067_Machoke.bin"

	.align 2
gDirectSound_Cry068_Machamp:: @ 0x085C1BC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry068_Machamp.bin"

	.align 2
gDirectSound_Cry072_Tentacool:: @ 0x085C2C48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry072_Tentacool.bin"

	.align 2
gDirectSound_Cry073_Tentacruel:: @ 0x085C3C38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry073_Tentacruel.bin"

	.align 2
gDirectSound_Cry074_Geodude:: @ 0x085C5334
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry074_Geodude.bin"

	.align 2
gDirectSound_Cry075_Graveler:: @ 0x085C6AE8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry075_Graveler.bin"

	.align 2
gDirectSound_Cry076_Golem:: @ 0x085C86D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry076_Golem.bin"

	.align 2
gDirectSound_Cry081_Magnemite:: @ 0x085C94FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry081_Magnemite.bin"

	.align 2
gDirectSound_Cry082_Magneton:: @ 0x085CA840
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry082_Magneton.bin"

	.align 2
gDirectSound_Cry084_Doduo:: @ 0x085CC028
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry084_Doduo.bin"

	.align 2
gDirectSound_Cry085_Dodrio:: @ 0x085CD36C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry085_Dodrio.bin"

	.align 2
gDirectSound_Cry088_Grimer:: @ 0x085CE6E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry088_Grimer.bin"

	.align 2
gDirectSound_Cry089_Muk:: @ 0x085CF16C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry089_Muk.bin"

	.align 2
gDirectSound_Cry100_Voltorb:: @ 0x085D002C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry100_Voltorb.bin"

	.align 2
gDirectSound_Cry101_Electrode:: @ 0x085D18F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry101_Electrode.bin"

	.align 2
gDirectSound_Cry109_Koffing:: @ 0x085D3228
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry109_Koffing.bin"

	.align 2
gDirectSound_Cry110_Weezing:: @ 0x085D4684
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry110_Weezing.bin"

	.align 2
gDirectSound_Cry111_Rhyhorn:: @ 0x085D5C30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry111_Rhyhorn.bin"

	.align 2
gDirectSound_Cry112_Rhydon:: @ 0x085D6F9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry112_Rhydon.bin"

	.align 2
gDirectSound_Cry116_Horsea:: @ 0x085D8408
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry116_Horsea.bin"

	.align 2
gDirectSound_Cry117_Seadra:: @ 0x085D8D84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry117_Seadra.bin"

	.align 2
gDirectSound_Cry118_Goldeen:: @ 0x085D95F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry118_Goldeen.bin"

	.align 2
gDirectSound_Cry119_Seaking:: @ 0x085D9FC8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry119_Seaking.bin"

	.align 2
gDirectSound_Cry120_Staryu:: @ 0x085DB320
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry120_Staryu.bin"

	.align 2
gDirectSound_Cry121_Starmie:: @ 0x085DC708
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry121_Starmie.bin"

	.align 2
gDirectSound_Cry127_Pinsir:: @ 0x085DDBE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry127_Pinsir.bin"

	.align 2
gDirectSound_Cry129_Magikarp:: @ 0x085DE840
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry129_Magikarp.bin"

	.align 2
gDirectSound_Cry130_Gyarados:: @ 0x085DFB48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry130_Gyarados.bin"

	.align 2
gDirectSound_Cry142_Aerodactyl:: @ 0x085E0F7C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry142_Aerodactyl.bin"

	.align 2
gDirectSound_Cry152_Chikorita:: @ 0x085E27D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry152_Chikorita.bin"

	.align 2
gDirectSound_Cry153_Bayleef:: @ 0x085E2D18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry153_Bayleef.bin"

	.align 2
gDirectSound_Cry154_Meganium:: @ 0x085E35E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry154_Meganium.bin"

	.align 2
gDirectSound_Cry155_Cyndaquil:: @ 0x085E461C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry155_Cyndaquil.bin"

	.align 2
gDirectSound_Cry156_Quilava:: @ 0x085E4D20
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry156_Quilava.bin"

	.align 2
gDirectSound_Cry157_Typhlosion:: @ 0x085E5908
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry157_Typhlosion.bin"

	.align 2
gDirectSound_Cry158_Totodile:: @ 0x085E7F18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry158_Totodile.bin"

	.align 2
gDirectSound_Cry159_Croconaw:: @ 0x085E9170
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry159_Croconaw.bin"

	.align 2
gDirectSound_Cry160_Feraligatr:: @ 0x085EA5AC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry160_Feraligatr.bin"

	.align 2
gDirectSound_Cry169_Crobat:: @ 0x085EBF30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry169_Crobat.bin"

	.align 2
gDirectSound_Cry170_Chinchou:: @ 0x085ED660
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry170_Chinchou.bin"

	.align 2
gDirectSound_Cry171_Lanturn:: @ 0x085EE310
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry171_Lanturn.bin"

	.align 2
gDirectSound_Cry172_Pichu:: @ 0x085EED9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry172_Pichu.bin"

	.align 2
gDirectSound_Cry174_Igglybuff:: @ 0x085EF4F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry174_Igglybuff.bin"

	.align 2
gDirectSound_Cry177_Natu:: @ 0x085EFBEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry177_Natu.bin"

	.align 2
gDirectSound_Cry178_Xatu:: @ 0x085F067C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry178_Xatu.bin"

	.align 2
gDirectSound_Cry182_Bellossom:: @ 0x085F1548
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry182_Bellossom.bin"

	.align 2
gDirectSound_Cry183_Marill:: @ 0x085F2360
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry183_Marill.bin"

	.align 2
gDirectSound_Cry184_Azumarill:: @ 0x085F3074
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry184_Azumarill.bin"

	.align 2
gDirectSound_Cry202_Wobbuffet:: @ 0x085F4160
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry202_Wobbuffet.bin"

	.align 2
gDirectSound_Cry203_Girafarig:: @ 0x085F55FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry203_Girafarig.bin"

	.align 2
gDirectSound_Cry214_Heracross:: @ 0x085F64B0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry214_Heracross.bin"

	.align 2
gDirectSound_Cry218_Slugma:: @ 0x085F7704
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry218_Slugma.bin"

	.align 2
gDirectSound_Cry219_Magcargo:: @ 0x085F881C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry219_Magcargo.bin"

	.align 2
gDirectSound_Cry222_Corsola:: @ 0x085F9D24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry222_Corsola.bin"

	.align 2
gDirectSound_Cry227_Skarmory:: @ 0x085FAA04
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry227_Skarmory.bin"

	.align 2
gDirectSound_Cry230_Kingdra:: @ 0x085FC20C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry230_Kingdra.bin"

	.align 2
gDirectSound_Cry231_Phanpy:: @ 0x085FCFE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry231_Phanpy.bin"

	.align 2
gDirectSound_Cry232_Donphan:: @ 0x085FDB34
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry232_Donphan.bin"

	.align 2
gDirectSound_Cry251_Celebi:: @ 0x085FEC58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry251_Celebi.bin"

	.align 2
gDirectSound_Cry252_Kecleon:: @ 0x085FFAD0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry252_Kecleon.bin"

	.align 2
gDirectSound_Cry253_Roselia:: @ 0x08600330
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry253_Roselia.bin"

	.align 2
gDirectSound_Cry254_Torkoal:: @ 0x08600DF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry254_Torkoal.bin"

	.align 2
gDirectSound_Cry255_Electrike:: @ 0x0860173C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry255_Electrike.bin"

	.align 2
gDirectSound_Cry256_Manectric:: @ 0x08602398
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry256_Manectric.bin"

	.align 2
gDirectSound_Cry257_Duskull:: @ 0x086038A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry257_Duskull.bin"

	.align 2
gDirectSound_Cry258_Latias:: @ 0x08604338
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry258_Latias.bin"

	.align 2
gDirectSound_Cry259_Wynaut:: @ 0x08604F68
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry259_Wynaut.bin"

	.align 2
gDirectSound_Cry260_Seviper:: @ 0x08605D48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry260_Seviper.bin"

	.align 2
gDirectSound_Cry261_Sharpedo:: @ 0x086068E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry261_Sharpedo.bin"

	.align 2
gDirectSound_Cry262_Zangoose:: @ 0x08607FF4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry262_Zangoose.bin"

	.align 2
gDirectSound_Cry263_Azurill:: @ 0x08608984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry263_Azurill.bin"

	.align 2
gDirectSound_Cry264_Swablu:: @ 0x086093EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry264_Swablu.bin"

	.align 2
gDirectSound_Cry265_Altaria:: @ 0x08609984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry265_Altaria.bin"

	.align 2
gDirectSound_Cry266_Unused:: @ 0x0860A4A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry266_Unused.bin"

	.align 2
gDirectSound_Cry267_Taillow:: @ 0x0860ADF4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry267_Taillow.bin"

	.align 2
gDirectSound_Cry268_Swellow:: @ 0x0860B3F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry268_Swellow.bin"

	.align 2
gDirectSound_Cry269_Unused:: @ 0x0860BCF8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry269_Unused.bin"

	.align 2
gDirectSound_Cry270_Spinda:: @ 0x0860CEA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry270_Spinda.bin"

	.align 2
gDirectSound_Cry271_Torchic:: @ 0x0860DB14
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry271_Torchic.bin"

	.align 2
gDirectSound_Cry272_Combusken:: @ 0x0860E4BC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry272_Combusken.bin"

	.align 2
gDirectSound_Cry273_Blaziken:: @ 0x08610190
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry273_Blaziken.bin"

	.align 2
gDirectSound_Cry274_Treecko:: @ 0x08612110
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry274_Treecko.bin"

	.align 2
gDirectSound_Cry275_Grovyle:: @ 0x08612CB8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry275_Grovyle.bin"

	.align 2
gDirectSound_Cry276_Sceptile:: @ 0x0861412C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry276_Sceptile.bin"

	.align 2
gDirectSound_Cry277_Mudkip:: @ 0x08615B48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry277_Mudkip.bin"

	.align 2
gDirectSound_Cry278_Marshtomp:: @ 0x086162CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry278_Marshtomp.bin"

	.align 2
gDirectSound_Cry279_Swampert:: @ 0x086173D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry279_Swampert.bin"

	.align 2
gDirectSound_Cry280_Pelipper:: @ 0x08618A50
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry280_Pelipper.bin"

	.align 2
gDirectSound_Cry281_Wingull:: @ 0x08619618
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry281_Wingull.bin"

	.align 2
gDirectSound_Cry282_Banette:: @ 0x0861A258
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry282_Banette.bin"

	.align 2
gDirectSound_Cry283_Shuppet:: @ 0x0861AF00
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry283_Shuppet.bin"

	.align 2
gDirectSound_Cry284_Lotad:: @ 0x0861B740
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry284_Lotad.bin"

	.align 2
gDirectSound_Cry285_Lombre:: @ 0x0861BBA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry285_Lombre.bin"

	.align 2
gDirectSound_Cry286_Ludicolo:: @ 0x0861CA3C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry286_Ludicolo.bin"

	.align 2
gDirectSound_Cry287_Seedot:: @ 0x0861DB0C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry287_Seedot.bin"

	.align 2
gDirectSound_Cry288_Nuzleaf:: @ 0x0861E338
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry288_Nuzleaf.bin"

	.align 2
gDirectSound_Cry289_Shiftry:: @ 0x0861EEA0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry289_Shiftry.bin"

	.align 2
gDirectSound_Cry290_Carvanha:: @ 0x08620264
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry290_Carvanha.bin"

	.align 2
gDirectSound_Cry291_Wurmple:: @ 0x08620C78
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry291_Wurmple.bin"

	.align 2
gDirectSound_Cry292_Silcoon:: @ 0x08621544
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry292_Silcoon.bin"

	.align 2
gDirectSound_Cry293_Beautifly:: @ 0x08622570
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry293_Beautifly.bin"

	.align 2
gDirectSound_Cry294_Cascoon:: @ 0x08622DA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry294_Cascoon.bin"

	.align 2
gDirectSound_Cry295_Dustox:: @ 0x08623DEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry295_Dustox.bin"

	.align 2
gDirectSound_Cry296_Ralts:: @ 0x08624A98
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry296_Ralts.bin"

	.align 2
gDirectSound_Cry297_Kirlia:: @ 0x086254B4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry297_Kirlia.bin"

	.align 2
gDirectSound_Cry298_Gardevoir:: @ 0x086260E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry298_Gardevoir.bin"

	.align 2
gDirectSound_Cry299_Slakoth:: @ 0x08627948
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry299_Slakoth.bin"

	.align 2
gDirectSound_Cry300_Vigoroth:: @ 0x086281CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry300_Vigoroth.bin"

	.align 2
gDirectSound_Cry301_Slaking:: @ 0x08629024
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry301_Slaking.bin"

	.align 2
gDirectSound_Cry302_Nincada:: @ 0x08629A10
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry302_Nincada.bin"

	.align 2
gDirectSound_Cry303_Ninjask:: @ 0x0862A080
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry303_Ninjask.bin"

	.align 2
gDirectSound_Cry304_Shedinja:: @ 0x0862ACA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry304_Shedinja.bin"

	.align 2
gDirectSound_Cry305_Makuhita:: @ 0x0862B460
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry305_Makuhita.bin"

	.align 2
gDirectSound_Cry306_Hariyama:: @ 0x0862BBBC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry306_Hariyama.bin"

	.align 2
gDirectSound_Cry307_Nosepass:: @ 0x0862CC74
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry307_Nosepass.bin"

	.align 2
gDirectSound_Cry308_Glalie:: @ 0x0862D9D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry308_Glalie.bin"

	.align 2
gDirectSound_Cry309_Plusle:: @ 0x0862EEBC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry309_Plusle.bin"

	.align 2
gDirectSound_Cry310_Minun:: @ 0x0862F7B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry310_Minun.bin"

	.align 2
gDirectSound_Cry311_Surskit:: @ 0x086307C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry311_Surskit.bin"

	.align 2
gDirectSound_Cry312_Masquerain:: @ 0x08631240
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry312_Masquerain.bin"

	.align 2
gDirectSound_Cry313_Skitty:: @ 0x086325F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry313_Skitty.bin"

	.align 2
gDirectSound_Cry314_Delcatty:: @ 0x08632D08
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry314_Delcatty.bin"

	.align 2
gDirectSound_Cry315_Gulpin:: @ 0x08634220
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry315_Gulpin.bin"

	.align 2
gDirectSound_Cry316_Swalot:: @ 0x08634A24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry316_Swalot.bin"

	.align 2
gDirectSound_Cry317_Numel:: @ 0x08635B84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry317_Numel.bin"

	.align 2
gDirectSound_Cry318_Camerupt:: @ 0x086364D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry318_Camerupt.bin"

	.align 2
gDirectSound_Cry319_Barboach:: @ 0x08637BF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry319_Barboach.bin"

	.align 2
gDirectSound_Cry320_Whiscash:: @ 0x0863852C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry320_Whiscash.bin"

	.align 2
gDirectSound_Cry321_Corphish:: @ 0x08639628
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry321_Corphish.bin"

	.align 2
gDirectSound_Cry322_Crawdaunt:: @ 0x0863A22C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry322_Crawdaunt.bin"

	.align 2
gDirectSound_Cry323_Spoink:: @ 0x0863BAE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry323_Spoink.bin"

	.align 2
gDirectSound_Cry324_Grumpig:: @ 0x0863C224
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry324_Grumpig.bin"

	.align 2
gDirectSound_Cry325_Trapinch:: @ 0x0863CEC4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry325_Trapinch.bin"

	.align 2
gDirectSound_Cry326_Vibrava:: @ 0x0863D8E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry326_Vibrava.bin"

	.align 2
gDirectSound_Cry327_Flygon:: @ 0x0863E6EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry327_Flygon.bin"

	.align 2
gDirectSound_Cry328_Cacnea:: @ 0x086400F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry328_Cacnea.bin"

	.align 2
gDirectSound_Cry329_Cacturne:: @ 0x086409E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry329_Cacturne.bin"

	.align 2
gDirectSound_Cry330_Baltoy:: @ 0x08642094
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry330_Baltoy.bin"

	.align 2
gDirectSound_Cry331_Claydol:: @ 0x08642D18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry331_Claydol.bin"

	.align 2
gDirectSound_Cry332_Lunatone:: @ 0x08644078
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry332_Lunatone.bin"

	.align 2
gDirectSound_Cry333_Solrock:: @ 0x08645874
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry333_Solrock.bin"

	.align 2
gDirectSound_Cry334_Feebas:: @ 0x086468A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry334_Feebas.bin"

	.align 2
gDirectSound_Cry335_Milotic:: @ 0x08647074
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry335_Milotic.bin"

	.align 2
gDirectSound_Cry336_Absol:: @ 0x086497B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry336_Absol.bin"

	.align 2
gDirectSound_Cry337_Meditite:: @ 0x0864A234
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry337_Meditite.bin"

	.align 2
gDirectSound_Cry338_Medicham:: @ 0x0864AA54
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry338_Medicham.bin"

	.align 2
gDirectSound_Cry339_Spheal:: @ 0x0864BAD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry339_Spheal.bin"

	.align 2
gDirectSound_Cry340_Sealeo:: @ 0x0864C08C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry340_Sealeo.bin"

	.align 2
gDirectSound_Cry341_Walrein:: @ 0x0864CC64
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry341_Walrein.bin"

	.align 2
gDirectSound_Cry342_Clamperl:: @ 0x0864F0B0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry342_Clamperl.bin"

	.align 2
gDirectSound_Cry343_Huntail:: @ 0x08650300
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry343_Huntail.bin"

	.align 2
gDirectSound_Cry344_Gorebyss:: @ 0x086512E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry344_Gorebyss.bin"

	.align 2
gDirectSound_Cry345_Lileep:: @ 0x08652954
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry345_Lileep.bin"

	.align 2
gDirectSound_Cry346_Cradily:: @ 0x086532FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry346_Cradily.bin"

	.align 2
gDirectSound_Cry347_Anorith:: @ 0x0865502C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry347_Anorith.bin"

	.align 2
gDirectSound_Cry348_Armaldo:: @ 0x08655BE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry348_Armaldo.bin"

	.align 2
gDirectSound_Cry349_Beldum:: @ 0x086572B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry349_Beldum.bin"

	.align 2
gDirectSound_Cry350_Metang:: @ 0x08657C58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry350_Metang.bin"

	.align 2
gDirectSound_Cry351_Metagross:: @ 0x08658F2C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry351_Metagross.bin"

	.align 2
gDirectSound_Cry352_Bagon:: @ 0x0865B6A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry352_Bagon.bin"

	.align 2
gDirectSound_Cry353_Shelgon:: @ 0x0865BE78
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry353_Shelgon.bin"

	.align 2
gDirectSound_Cry354_Regirock:: @ 0x0865D280
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry354_Regirock.bin"

	.align 2
gDirectSound_Cry355_Regice:: @ 0x0865F25C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry355_Regice.bin"

	.align 2
gDirectSound_Cry356_Registeel:: @ 0x0866125C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry356_Registeel.bin"

	.align 2
gDirectSound_Cry357_Castform:: @ 0x08662960
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry357_Castform.bin"

	.align 2
gDirectSound_Cry358_Volbeat:: @ 0x086635F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry358_Volbeat.bin"

	.align 2
gDirectSound_Cry359_Illumise:: @ 0x08664180
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry359_Illumise.bin"

	.align 2
gDirectSound_Cry360_Poochyena:: @ 0x08665298
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry360_Poochyena.bin"

	.align 2
gDirectSound_Cry361_Mightyena:: @ 0x08665BE0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry361_Mightyena.bin"

	.align 2
gDirectSound_Cry362_Dusclops:: @ 0x08666F6C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry362_Dusclops.bin"

	.align 2
gDirectSound_Cry363_Sableye:: @ 0x08667D24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry363_Sableye.bin"

	.align 2
gDirectSound_Cry364_Mawile:: @ 0x086688C8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry364_Mawile.bin"

	.align 2
gDirectSound_Cry365_Aron:: @ 0x08669448
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry365_Aron.bin"

	.align 2
gDirectSound_Cry366_Lairon:: @ 0x08669D74
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry366_Lairon.bin"

	.align 2
gDirectSound_Cry367_Aggron:: @ 0x0866B24C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry367_Aggron.bin"

	.align 2
gDirectSound_Cry368_Relicanth:: @ 0x0866CBF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry368_Relicanth.bin"

	.align 2
gDirectSound_Cry369_Luvdisc:: @ 0x0866E020
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry369_Luvdisc.bin"

	.align 2
gDirectSound_Cry370_Groudon:: @ 0x0866E4FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry370_Groudon.bin"

	.align 2
gDirectSound_Cry371_Kyogre:: @ 0x08670A08
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry371_Kyogre.bin"

	.align 2
gDirectSound_Cry372_Rayquaza:: @ 0x08672DC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry372_Rayquaza.bin"

	.align 2
gDirectSound_Cry373_Salamence:: @ 0x08674AEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry373_Salamence.bin"

	.align 2
gDirectSound_Cry374_Breloom:: @ 0x08676408
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry374_Breloom.bin"

	.align 2
gDirectSound_Cry375_Shroomish:: @ 0x086770C8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry375_Shroomish.bin"

	.align 2
gDirectSound_Cry376_Linoone:: @ 0x086779A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry376_Linoone.bin"

	.align 2
gDirectSound_Cry377_Tropius:: @ 0x0867983C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry377_Tropius.bin"

	.align 2
gDirectSound_Cry378_Wailmer:: @ 0x0867B900
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry378_Wailmer.bin"

	.align 2
gDirectSound_Cry379_Zigzagoon:: @ 0x0867D560
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry379_Zigzagoon.bin"

	.align 2
gDirectSound_Cry380_Exploud:: @ 0x0867E0F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry380_Exploud.bin"

	.align 2
gDirectSound_Cry381_Loured:: @ 0x0867FD38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry381_Loured.bin"

	.align 2
gDirectSound_Cry382_Wailord:: @ 0x08680A60
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry382_Wailord.bin"

	.align 2
gDirectSound_Cry383_Whismur:: @ 0x08683470
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry383_Whismur.bin"

	.align 2
gDirectSound_Cry384_Snorunt:: @ 0x08683C94
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry384_Snorunt.bin"

	.align 2
gDirectSound_Cry385_Latios:: @ 0x08684D9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry385_Latios.bin"

	.align 2
gDirectSound_Cry386_Jirachi:: @ 0x08686394
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry386_Jirachi.bin"

	.align 2
gDirectSound_Cry387_Deoxys:: @ 0x08687118
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry387_Deoxys.bin"

	.align 2
gDirectSound_Cry388_Chimecho:: @ 0x086885EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry388_Chimecho.bin"

.include "sound/songs/mus_title.s"
.include "sound/songs/mus_table_select.s"
.include "sound/songs/mus_ereader.s"
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
.include "sound/songs/mus_prize_awarded.s"
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
.include "sound/songs/se_unused_0x6c.s"
.include "sound/songs/se_dex_info_field_select_move.s"
.include "sound/songs/se_unused_0x6e.s"
.include "sound/songs/se_unused_0x6f.s"
.include "sound/songs/se_unk_71.s"
.include "sound/songs/se_flipper_pressed.s"
.include "sound/songs/se_slingshot_hit.s"
.include "sound/songs/se_pokemon_catch_hit.s"
.include "sound/songs/se_pichu_in_position_chirp.s"
.include "sound/songs/se_trigger_button_hit.s"
.include "sound/songs/se_wall_hit.s"
.include "sound/songs/se_tilt_triggered.s"
.include "sound/songs/se_pika_spinner_clack.s"
.include "sound/songs/se_pika_full_charge_1_up.s"
.include "sound/songs/se_unk_7b.s"
.include "sound/songs/se_kickback_thunderwave.s"
.include "sound/songs/se_unused_0x7d.s"
.include "sound/songs/se_coin_collected.s"
.include "sound/songs/se_unused_0x7f.s"
.include "sound/songs/se_center_hole_eject.s"
.include "sound/songs/se_roulette_tick.s"
.include "sound/songs/se_evo_selection_move.s"
.include "sound/songs/se_evo_selection_confirm.s"
.include "sound/songs/se_evo_item_appear.s"
.include "sound/songs/se_evo_item_finish_appear.s"
.include "sound/songs/se_evo_item_collected.s"
.include "sound/songs/se_ball_upgrade.s"
.include "sound/songs/se_unused_0x88.s"
.include "sound/songs/se_unused_0x89.s"
.include "sound/songs/se_failure.s"
.include "sound/songs/se_catch_evo_banner.s"
.include "sound/songs/se_catch_tile_reveal.s"
.include "sound/songs/se_catch_all_reveal_lightning.s"
.include "sound/songs/se_catch_all_reveal_shatter.s"
.include "sound/songs/se_shop_list_reveal.s"
.include "sound/songs/se_bonus_score_tallied.s"
.include "sound/songs/se_hatch_flourish.s"
.include "sound/songs/se_area_roulette_selected.s"
.include "sound/songs/se_ball_saved.s"
.include "sound/songs/se_lati_delivery.s"
.include "sound/songs/se_saver_plunger_drop.s"
.include "sound/songs/se_travel_painter_flight.s"
.include "sound/songs/se_travel_painter_paints.s"
.include "sound/songs/se_evo_get_arrow_earned.s"
.include "sound/songs/se_mon_catch_ball_woosh.s"
.include "sound/songs/se_mon_catch_energy_beam.s"
.include "sound/songs/se_mon_catch_ball_close.s"
.include "sound/songs/se_mon_catch_ball_hit_ground.s"
.include "sound/songs/se_mon_catch_ball_shake.s"
.include "sound/songs/se_warp.s"
.include "sound/songs/se_unused_0xa0.s"
.include "sound/songs/se_ball_summary_text_progress.s"
.include "sound/songs/se_ball_summary_page_swipe.s"
.include "sound/songs/se_pause_cursor_move.s"
.include "sound/songs/se_bonus_panel_slide.s"
.include "sound/songs/se_pausing.s"
.include "sound/songs/se_unpausing.s"
.include "sound/songs/se_catch_mon_entity_appears.s"
.include "sound/songs/se_pika_charge_do.s"
.include "sound/songs/se_pika_charge_re.s"
.include "sound/songs/se_pika_charge_mi.s"
.include "sound/songs/se_pika_charge_fa.s"
.include "sound/songs/se_pika_charge_so.s"
.include "sound/songs/se_pika_charge_la.s"
.include "sound/songs/se_pika_charge_ti.s"
.include "sound/songs/se_pika_charge_high_do.s"
.include "sound/songs/se_evo_cutscene_mon_portrait_change.s"
.include "sound/songs/se_pikachu_kickback.s"
.include "sound/songs/se_pichu_kickback_enabled.s"
.include "sound/songs/se_pichu_kickback.s"
.include "sound/songs/se_unused_0xb4.s"
.include "sound/songs/se_ruby_bumper_hit.s"
.include "sound/songs/se_cyndaquil_egg_guard_hit.s"
.include "sound/songs/se_aerodactyl_egg_flight.s"
.include "sound/songs/se_cyndaquil_ball_eject_after_egg_arrival.s"
.include "sound/songs/se_unused_0xba.s"
.include "sound/songs/se_unused_0xbb.s"
.include "sound/songs/se_unused_0xbc.s"
.include "sound/songs/se_ruby_mart_gate_open.s"
.include "sound/songs/se_unused_0xbe.s"
.include "sound/songs/se_unused_0xbf.s"
.include "sound/songs/se_unused_0xc0.s"
.include "sound/songs/se_unused_0xc1.s"
.include "sound/songs/se_sharpedo_ball_eject.s"
.include "sound/songs/se_shop_eject.s"
.include "sound/songs/se_unused_0xc4.s"
.include "sound/songs/se_makuhita_punch.s"
.include "sound/songs/se_chikorita_leaf_blade.s"
.include "sound/songs/se_zigzagoon_emerge.s"
.include "sound/songs/se_ruby_bumper_emerges.s"
.include "sound/songs/se_ruby_bumper_leaves.s"
.include "sound/songs/se_ruby_mart_sign_changed.s"
.include "sound/songs/se_unused_0xcb.s"
.include "sound/songs/se_spoink_launcher_charged.s"
.include "sound/songs/se_spoink_launcher_fired.s"
.include "sound/songs/se_sharpedo_bite.s"
.include "sound/songs/se_nuzleaf_hit.s"
.include "sound/songs/se_nuzleaf_teetering.s"
.include "sound/songs/se_nuzleaf_forms_bridge.s"
.include "sound/songs/se_gulpin_lands_or_leaves.s"
.include "sound/songs/se_whiscash_emerge_splash.s"
.include "sound/songs/se_whiscash_leave_burble.s"
.include "sound/songs/se_whiscash_catch_ball.s"
.include "sound/songs/se_whiscash_spit_ball.s"
.include "sound/songs/se_whiscash_splashdown.s"
.include "sound/songs/se_ramp_prize_collected.s"
.include "sound/songs/se_hatch_machine_spinner_trigger.s"
.include "sound/songs/se_mon_lands_on_hatch_machine_top.s"
.include "sound/songs/se_hatch_machine_stage_advance.s"
.include "sound/songs/se_hatch_machine_egg_hatch.s"
.include "sound/songs/se_hatch_machine_elevator.s"
.include "sound/songs/se_hatch_machine_elevator_top.s"
.include "sound/songs/se_pelipper_ball_grab.s"
.include "sound/songs/se_pelipper_wing_flap.s"
.include "sound/songs/se_pelipper_swoosh.s"
.include "sound/songs/se_pelipper_ball_drop_lands.s"
.include "sound/songs/se_sapphire_mart_gate_trigger.s"
.include "sound/songs/se_sapphire_mart_gate_replaced.s"
.include "sound/songs/se_sapphire_mart_gate_hit.s"
.include "sound/songs/se_seedot_falling.s"
.include "sound/songs/se_seedot_lands.s"
.include "sound/songs/se_seedot_leaves.s"
.include "sound/songs/se_zigzagoon_roulette_stop.s"
.include "sound/songs/se_duskull_appear.s"
.include "sound/songs/se_duskull_death_cry.s"
.include "sound/songs/se_dusclops_depart_incomplete.s"
.include "sound/songs/se_dusclops_move.s"
.include "sound/songs/se_dusclops_appear.s"
.include "sound/songs/se_dusclops_hit.s"
.include "sound/songs/se_dusclops_ball_absorb.s"
.include "sound/songs/se_dusclops_ball_launch.s"
.include "sound/songs/se_bonus_board_ball_spawn.s"
.include "sound/songs/se_unused_0xfa.s"
.include "sound/songs/se_kecleon_side_look.s"
.include "sound/songs/se_kecleon_vanish.s"
.include "sound/songs/se_kecleon_startled.s"
.include "sound/songs/se_kecleon_running.s"
.include "sound/songs/se_kecleon_knocked_over.s"
.include "sound/songs/se_kecleon_hit_damaged.s"
.include "sound/songs/se_kecleon_hits_ground_defeated.s"
.include "sound/songs/se_kecleon_seeing_stars.s"
.include "sound/songs/se_kecleon_tree_hit.s"
.include "sound/songs/se_kecleon_scope_fall.s"
.include "sound/songs/se_kecleon_scope_activated.s"
.include "sound/songs/se_kyogre_hit.s"
.include "sound/songs/se_kyogre_breach_surface.s"
.include "sound/songs/se_kyogre_dive.s"
.include "sound/songs/se_kyogre_spawn_whirlpool.s"
.include "sound/songs/se_kyogre_freeze_ring.s"
.include "sound/songs/se_kyogre_departs.s"
.include "sound/songs/se_kyogre_freeze_hits_ball.s"
.include "sound/songs/se_kyogre_freeze_crack.s"
.include "sound/songs/se_kyogre_freeze_escaped.s"
.include "sound/songs/se_kyogre_whirlpool_grabs_ball.s"
.include "sound/songs/se_groudon_hit.s"
.include "sound/songs/se_groudon_step.s"
.include "sound/songs/se_groudon_intro_leap.s"
.include "sound/songs/se_groudon_lands.s"
.include "sound/songs/se_groudon_spits_fire.s"
.include "sound/songs/se_groudon_fire_ring.s"
.include "sound/songs/se_groudon_fire_grab_resist.s"
.include "sound/songs/se_groudon_fire_grab.s"
.include "sound/songs/se_groudon_fireball_connects.s"
.include "sound/songs/se_groudon_boulder_land.s"
.include "sound/songs/se_groudon_dustorm_lift.s"
.include "sound/songs/se_groudon_ball_hit_fire.s"
.include "sound/songs/se_rayquaza_hit.s"
.include "sound/songs/se_rayquaza_wind.s"
.include "sound/songs/se_rayquaza_lightning_charge.s"
.include "sound/songs/se_rayquaza_flyby.s"
.include "sound/songs/se_rayquaza_lightning_trap.s"
.include "sound/songs/se_rayquaza_whirlwind_ball_launch.s"
.include "sound/songs/se_rayquaza_whirlwind_ball_land.s"
.include "sound/songs/se_rayquaza_sonic_boom.s"
.include "sound/songs/se_rayquaza_stage_wind.s"
.include "sound/songs/se_spheal_surfacing.s"
.include "sound/songs/se_spheal_submerging.s"
.include "sound/songs/se_spheal_submerging_after_scoring.s"
.include "sound/songs/se_spheal_hit.s"
.include "sound/songs/se_spheal_net_swoosh.s"
.include "sound/songs/se_spheal_crowd_cheer.s"
.include "sound/songs/se_spheal_end_whistle.s"
.include "sound/songs/se_sealeo_hit_thud.s"
.include "sound/songs/se_sealeo_nose_bounce.s"
.include "sound/songs/se_spheal_land_under_net.s"
.include "sound/songs/se_unused_0x13f.s"
.include "sound/songs/se_spheal_surface_at_ramp.s"
.include "sound/songs/se_pika_no_kickback.s"
.include "sound/songs/se_jirachi_move.s"
.include "sound/songs/se_jirachi_hit.s"
.include "sound/songs/se_totodile_lowers_rope.s"
.include "sound/songs/se_totodile_slides_down.s"
.include "sound/songs/se_totodile_places_egg.s"
.include "sound/songs/se_totodile_climbs_rope.s"
.include "sound/songs/se_highest_score_earned.s"
.include "sound/songs/se_high_score_earned.s"
.include "sound/songs/se_whiscash_earthquake.s"
