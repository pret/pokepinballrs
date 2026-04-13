@ Note: ruby_board.inc file has a shared 'bumper collision map' at 0x08252B10

gSapphireBoardPalette:: @ 0x0826EC10
	.incbin "baserom.gba", 0x26EC10, 0x200

gSapphireBoardBG0Tilemap:: @ 0x0826EE10
	.incbin "baserom.gba", 0x26EE10, 0x1000

gSapphireBoardCollisionTileDataLayer0:: @ 0x0826FE10
    .incbin "baserom.gba", 0x26FE10, 0x2000

gSapphireBoardCollisionAngleDataLayer0:: @ 0x08271E10
    .incbin "baserom.gba", 0x271E10, 0x14C00

gSapphireBoardCollisionTypeDataLayer0:: @ 0x08286A10
    .incbin "baserom.gba", 0x286A10, 0xA600

gSapphireBoardCollisionTileDataLayer1:: @ 0x08291010
    .incbin "baserom.gba", 0x291010, 0x2000

gSapphireBoardCollisionAngleDataLayer1:: @ 0x08293010
    .incbin "baserom.gba", 0x293010, 0x12480

gSapphireBoardCollisionTypeDataLayer1:: @ 0x082A5490
    .incbin "baserom.gba", 0x2A5490, 0x9240

gSapphireBoardBG1Tilemap:: @ 0x082AE6D0
	.incbin "baserom.gba", 0x2AE6D0, 0x1000

gSapphireBoardCollisionTileDataLayer2:: @ 0x082AF6D0
    .incbin "baserom.gba", 0x2AF6D0, 0x2000

gSapphireBoardCollisionAngleDataLayer2:: @ 0x082B16D0
    .incbin "baserom.gba", 0x2B16D0, 0xD100

gSapphireBoardCollisionTypeDataLayer2:: @ 0x082BE7D0
    .incbin "baserom.gba", 0x2BE7D0, 0x6880

gSapphireBoardCollisionTileDataLayer3:: @ 0x082C5050
    .incbin "baserom.gba", 0x2C5050, 0x2000

gSapphireBoardCollisionAngleDataLayer3:: @ 0x082C7050
    .incbin "baserom.gba", 0x2C7050, 0x8300

gSapphireBoardCollisionTypeDataLayer3:: @ 0x082CF350
    .incbin "baserom.gba", 0x2CF350, 0x4180

gSapphireBoardCompressedTiles1:: @ 0x082D34D0
	.incbin "baserom.gba", 0x2D34D0, 0x1D6C

gSapphireBoardCompressedTiles2:: @ 0x082D523C
	.incbin "baserom.gba", 0x2D523C, 0x375C

gSapphireBoardCompressedBGTileBuffer:: @ 0x082D8998
	.incbin "baserom.gba", 0x2D8998, 0x2048



@ Evo Arrows. Named this way for comprehension in folder.
@ E/V/O arrows. Second digit is '0 Top/1 Mid/2 Bottom',
@ First digit is 'variant'.
gSapphireEvo_EArrow_Top0:: @ 0x082DA9E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_0.4bpp"

gSapphireEvo_EArrow_Top1:: @ 0x082DAA40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_0.4bpp"

gSapphireEvo_EArrow_Top2:: @ 0x082DAAA0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_0.4bpp"

gSapphireEvo_VArrow_Top0:: @ 0x082DAB00
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_0.4bpp"

gSapphireEvo_VArrow_Top1:: @ 0x082DAB60
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_0.4bpp"

gSapphireEvo_VArrow_Top2:: @ 0x082DABC0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_0.4bpp"

gSapphireEvo_VArrow_Top3:: @ 0x082DAC20
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_0.4bpp"

gSapphireEvo_OArrow_Top0:: @ 0x082DAC80
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_0.4bpp"

gSapphireEvo_OArrow_Top1:: @ 0x082DACE0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_0.4bpp"

gSapphireEvo_OArrow_Top2:: @ 0x082DAD40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_0.4bpp"
	.space 0x40

gSapphireEvo_EArrow_Mid0:: @ 0x082DADE0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_1.4bpp"

gSapphireEvo_EArrow_Mid1:: @ 0x082DAE40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_1.4bpp"

gSapphireEvo_EArrow_Mid2:: @ 0x082DAEA0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_1.4bpp"

gSapphireEvo_VArrow_Mid0:: @ 0x082DAF00
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_1.4bpp"

gSapphireEvo_VArrow_Mid1:: @ 0x082DAF60
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_1.4bpp"

gSapphireEvo_VArrow_Mid2:: @ 0x082DAFC0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_1.4bpp"

gSapphireEvo_VArrow_Mid3:: @ 0x082DB020
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_1.4bpp"

gSapphireEvo_OArrow_Mid0:: @ 0x082DB080
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_1.4bpp"

gSapphireEvo_OArrow_Mid1:: @ 0x082DB0E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_1.4bpp"

gSapphireEvo_OArrow_Mid2:: @ 0x082DB140
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_1.4bpp"
	.space 0x40

gSapphireEvo_EArrow_Bot0:: @ 0x082DB1E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_2.4bpp"

gSapphireEvo_EArrow_Bot1:: @ 0x082DB240
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_2.4bpp"

gSapphireEvo_EArrow_Bot2:: @ 0x082DB2A0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_2.4bpp"

gSapphireEvo_VArrow_Bot0:: @ 0x082DB300
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_2.4bpp"

gSapphireEvo_VArrow_Bot1:: @ 0x082DB360
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_2.4bpp"

gSapphireEvo_VArrow_Bot2:: @ 0x082DB3C0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_2.4bpp"

gSapphireEvo_VArrow_Bot3:: @ 0x082DB420
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_2.4bpp"
	.space 0x20

gSapphireEvo_OArrow_Bot0:: @ 0x082DB4A0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_2.4bpp"
	.space 0x20

gSapphireEvo_OArrow_Bot1:: @ 0x082DB500
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_2.4bpp"
	.space 0x20

gSapphireEvo_OArrow_Bot2:: @ 0x082DB560
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_2.4bpp"
	.space 0x40


@ Coin Arrows


gSapphireCoinArrow_082DB5E0:: @ 0x082DB5E0
    .incbin "baserom.gba", 0x2DB5E0, 0x60

gSapphireCoinArrow_082DB640:: @ 0x082DB640
    .incbin "baserom.gba", 0x2DB640, 0x60

gSapphireCoinArrow_082DB6A0:: @ 0x082DB6A0
    .incbin "baserom.gba", 0x2DB6A0, 0x80

gSapphireCoinArrow_082DB720:: @ 0x082DB720
    .incbin "baserom.gba", 0x2DB720, 0x60

gSapphireCoinArrow_082DB780:: @ 0x082DB780
    .incbin "baserom.gba", 0x2DB780, 0x60

gSapphireCoinArrow_082DB7E0:: @ 0x082DB7E0
    .incbin "baserom.gba", 0x2DB7E0, 0x40

gSapphireCoinArrow_082DB820:: @ 0x082DB820
    .incbin "baserom.gba", 0x2DB820, 0x60

gSapphireCoinArrow_082DB880:: @ 0x082DB880
    .incbin "baserom.gba", 0x2DB880, 0x60

gSapphireCoinArrow_082DB8E0:: @ 0x082DB8E0
    .incbin "baserom.gba", 0x2DB8E0, 0x100

gSapphireCoinArrow_082DB9E0:: @ 0x082DB9E0
    .incbin "baserom.gba", 0x2DB9E0, 0x60

gSapphireCoinArrow_082DBA40:: @ 0x082DBA40
    .incbin "baserom.gba", 0x2DBA40, 0x60

gSapphireCoinArrow_082DBAA0:: @ 0x082DBAA0
    .incbin "baserom.gba", 0x2DBAA0, 0x80

gSapphireCoinArrow_082DBB20:: @ 0x082DBB20
    .incbin "baserom.gba", 0x2DBB20, 0x60

gSapphireCoinArrow_082DBB80:: @ 0x082DBB80
    .incbin "baserom.gba", 0x2DBB80, 0x60

gSapphireCoinArrow_082DBBE0:: @ 0x082DBBE0
    .incbin "baserom.gba", 0x2DBBE0, 0x40

gSapphireCoinArrow_082DBC20:: @ 0x082DBC20
    .incbin "baserom.gba", 0x2DBC20, 0x60

gSapphireCoinArrow_082DBC80:: @ 0x082DBC80
    .incbin "baserom.gba", 0x2DBC80, 0x60

gSapphireCoinArrow_082DBCE0:: @ 0x082DBCE0
    .incbin "baserom.gba", 0x2DBCE0, 0x100

gSapphireCoinArrow_082DBDE0:: @ 0x082DBDE0
    .incbin "baserom.gba", 0x2DBDE0, 0x60

gSapphireCoinArrow_082DBE40:: @ 0x082DBE40
    .incbin "baserom.gba", 0x2DBE40, 0x60

gSapphireCoinArrow_082DBEA0:: @ 0x082DBEA0
    .incbin "baserom.gba", 0x2DBEA0, 0x80

gSapphireCoinArrow_082DBF20:: @ 0x082DBF20
    .incbin "baserom.gba", 0x2DBF20, 0x60

gSapphireCoinArrow_082DBF80:: @ 0x082DBF80
    .incbin "baserom.gba", 0x2DBF80, 0x60

gSapphireCoinArrow_082DBFE0:: @ 0x082DBFE0
    .incbin "baserom.gba", 0x2DBFE0, 0x40

gSapphireCoinArrow_082DC020:: @ 0x082DC020
    .incbin "baserom.gba", 0x2DC020, 0x60

gSapphireCoinArrow_082DC080:: @ 0x082DC080
    .incbin "baserom.gba", 0x2DC080, 0x60

gSapphireCoinArrow_082DC0E0:: @ 0x082DC0E0
    .incbin "baserom.gba", 0x2DC0E0, 0x100


@ Get Arrows

gSapphireGetArrow_082DC1E0:: @ 0x082DC1E0
    .incbin "baserom.gba", 0x2DC1E0, 0x60

gSapphireGetArrow_082DC240:: @ 0x082DC240
    .incbin "baserom.gba", 0x2DC240, 0x60

gSapphireGetArrow_082DC2A0:: @ 0x082DC2A0
    .incbin "baserom.gba", 0x2DC2A0, 0x80

gSapphireGetArrow_082DC320:: @ 0x082DC320
    .incbin "baserom.gba", 0x2DC320, 0x60

gSapphireGetArrow_082DC380:: @ 0x082DC380
    .incbin "baserom.gba", 0x2DC380, 0x60

gSapphireGetArrow_082DC3E0:: @ 0x082DC3E0
    .incbin "baserom.gba", 0x2DC3E0, 0x60

gSapphireGetArrow_082DC440:: @ 0x082DC440
    .incbin "baserom.gba", 0x2DC440, 0x60

gSapphireGetArrow_082DC4A0:: @ 0x082DC4A0
    .incbin "baserom.gba", 0x2DC4A0, 0x60

gSapphireGetArrow_082DC500:: @ 0x082DC500
    .incbin "baserom.gba", 0x2DC500, 0x60

gSapphireGetArrow_082DC560:: @ 0x082DC560
    .incbin "baserom.gba", 0x2DC560, 0x80

gSapphireGetArrow_082DC5E0:: @ 0x082DC5E0
    .incbin "baserom.gba", 0x2DC5E0, 0x60

gSapphireGetArrow_082DC640:: @ 0x082DC640
    .incbin "baserom.gba", 0x2DC640, 0x60

gSapphireGetArrow_082DC6A0:: @ 0x082DC6A0
    .incbin "baserom.gba", 0x2DC6A0, 0x80

gSapphireGetArrow_082DC720:: @ 0x082DC720
    .incbin "baserom.gba", 0x2DC720, 0x60

gSapphireGetArrow_082DC780:: @ 0x082DC780
    .incbin "baserom.gba", 0x2DC780, 0x60

gSapphireGetArrow_082DC7E0:: @ 0x082DC7E0
    .incbin "baserom.gba", 0x2DC7E0, 0x60

gSapphireGetArrow_082DC840:: @ 0x082DC840
    .incbin "baserom.gba", 0x2DC840, 0x40

gSapphireGetArrow_082DC880:: @ 0x082DC880
    .incbin "baserom.gba", 0x2DC880, 0x60

gSapphireGetArrow_082DC8E0:: @ 0x082DC8E0
    .incbin "baserom.gba", 0x2DC8E0, 0x60

gSapphireGetArrow_082DC940:: @ 0x082DC940
    .incbin "baserom.gba", 0x2DC940, 0xA0

gSapphireGetArrow_082DC9E0:: @ 0x082DC9E0
    .incbin "baserom.gba", 0x2DC9E0, 0x60

gSapphireGetArrow_082DCA40:: @ 0x082DCA40
    .incbin "baserom.gba", 0x2DCA40, 0x60

gSapphireGetArrow_082DCAA0:: @ 0x082DCAA0
    .incbin "baserom.gba", 0x2DCAA0, 0x60

gSapphireGetArrow_082DCB00:: @ 0x082DCB00
    .incbin "baserom.gba", 0x2DCB00, 0x60

gSapphireGetArrow_082DCB60:: @ 0x082DCB60
    .incbin "baserom.gba", 0x2DCB60, 0x60

gSapphireGetArrow_082DCBC0:: @ 0x082DCBC0
    .incbin "baserom.gba", 0x2DCBC0, 0x60

gSapphireGetArrow_082DCC20:: @ 0x082DCC20
    .incbin "baserom.gba", 0x2DCC20, 0x60

gSapphireGetArrow_082DCC80:: @ 0x082DCC80
    .incbin "baserom.gba", 0x2DCC80, 0x60

gSapphireGetArrow_082DCCE0:: @ 0x082DCCE0
    .incbin "baserom.gba", 0x2DCCE0, 0x60

gSapphireGetArrow_082DCD40:: @ 0x082DCD40
    .incbin "baserom.gba", 0x2DCD40, 0xC0


@ Arrow for bonus multiplier left/right top/bottom digits

gSapphireBonusArrow_00_Top:: @ 0x082DCE00
    .incbin "baserom.gba", 0x2DCE00, 0x20

gSapphireBonusArrow_10_Top:: @ 0x082DCE20
    .incbin "baserom.gba", 0x2DCE20, 0x20

gSapphireBonusArrow_20_Top:: @ 0x082DCE40
    .incbin "baserom.gba", 0x2DCE40, 0x20

gSapphireBonusArrow_30_Top:: @ 0x082DCE60
    .incbin "baserom.gba", 0x2DCE60, 0x20

gSapphireBonusArrow_40_Top:: @ 0x082DCE80
    .incbin "baserom.gba", 0x2DCE80, 0x20

gSapphireBonusArrow_50_Top:: @ 0x082DCEA0
    .incbin "baserom.gba", 0x2DCEA0, 0x20

gSapphireBonusArrow_60_Top:: @ 0x082DCEC0
    .incbin "baserom.gba", 0x2DCEC0, 0x20

gSapphireBonusArrow_70_Top:: @ 0x082DCEE0
    .incbin "baserom.gba", 0x2DCEE0, 0x20

gSapphireBonusArrow_80_Top:: @ 0x082DCF00
    .incbin "baserom.gba", 0x2DCF00, 0x20

gSapphireBonusArrow_90_Top:: @ 0x082DCF20
    .incbin "baserom.gba", 0x2DCF20, 0x20

gSapphireBonusArrow_0_Top:: @ 0x082DCF40
    .incbin "baserom.gba", 0x2DCF40, 0x20

gSapphireBonusArrow_1_Top:: @ 0x082DCF60
    .incbin "baserom.gba", 0x2DCF60, 0x20

gSapphireBonusArrow_2_Top:: @ 0x082DCF80
    .incbin "baserom.gba", 0x2DCF80, 0x20

gSapphireBonusArrow_3_Top:: @ 0x082DCFA0
    .incbin "baserom.gba", 0x2DCFA0, 0x20

gSapphireBonusArrow_4_Top:: @ 0x082DCFC0
    .incbin "baserom.gba", 0x2DCFC0, 0x20

gSapphireBonusArrow_5_Top:: @ 0x082DCFE0
    .incbin "baserom.gba", 0x2DCFE0, 0x20

gSapphireBonusArrow_6_Top:: @ 0x082DD000
    .incbin "baserom.gba", 0x2DD000, 0x20

gSapphireBonusArrow_7_Top:: @ 0x082DD020
    .incbin "baserom.gba", 0x2DD020, 0x20

gSapphireBonusArrow_8_Top:: @ 0x082DD040
    .incbin "baserom.gba", 0x2DD040, 0x20

gSapphireBonusArrow_9_Top:: @ 0x082DD060
    .incbin "baserom.gba", 0x2DD060, 0x20
    .space 0x180

gSapphireBonusArrow_00_Bot:: @ 0x082DD200
    .incbin "baserom.gba", 0x2DD200, 0x20

gSapphireBonusArrow_10_Bot:: @ 0x082DD220
    .incbin "baserom.gba", 0x2DD220, 0x20

gSapphireBonusArrow_20_Bot:: @ 0x082DD240
    .incbin "baserom.gba", 0x2DD240, 0x20

gSapphireBonusArrow_30_Bot:: @ 0x082DD260
    .incbin "baserom.gba", 0x2DD260, 0x20

gSapphireBonusArrow_40_Bot:: @ 0x082DD280
    .incbin "baserom.gba", 0x2DD280, 0x20

gSapphireBonusArrow_50_Bot:: @ 0x082DD2A0
    .incbin "baserom.gba", 0x2DD2A0, 0x20

gSapphireBonusArrow_60_Bot:: @ 0x082DD2C0
    .incbin "baserom.gba", 0x2DD2C0, 0x20

gSapphireBonusArrow_70_Bot:: @ 0x082DD2E0
    .incbin "baserom.gba", 0x2DD2E0, 0x20

gSapphireBonusArrow_80_Bot:: @ 0x082DD300
    .incbin "baserom.gba", 0x2DD300, 0x20

gSapphireBonusArrow_90_Bot:: @ 0x082DD320
    .incbin "baserom.gba", 0x2DD320, 0x20

gSapphireBonusArrow_0_Bot:: @ 0x082DD340
    .incbin "baserom.gba", 0x2DD340, 0x20

gSapphireBonusArrow_1_Bot:: @ 0x082DD360
    .incbin "baserom.gba", 0x2DD360, 0x20

gSapphireBonusArrow_2_Bot:: @ 0x082DD380
    .incbin "baserom.gba", 0x2DD380, 0x20

gSapphireBonusArrow_3_Bot:: @ 0x082DD3A0
    .incbin "baserom.gba", 0x2DD3A0, 0x20

gSapphireBonusArrow_4_Bot:: @ 0x082DD3C0
    .incbin "baserom.gba", 0x2DD3C0, 0x20

gSapphireBonusArrow_5_Bot:: @ 0x082DD3E0
    .incbin "baserom.gba", 0x2DD3E0, 0x20

gSapphireBonusArrow_6_Bot:: @ 0x082DD400
    .incbin "baserom.gba", 0x2DD400, 0x20

gSapphireBonusArrow_7_Bot:: @ 0x082DD420
    .incbin "baserom.gba", 0x2DD420, 0x20

gSapphireBonusArrow_8_Bot:: @ 0x082DD440
    .incbin "baserom.gba", 0x2DD440, 0x20

gSapphireBonusArrow_9_Bot:: @ 0x082DD460
    .incbin "baserom.gba", 0x2DD460, 0x20
    .space 0x1A0


@ Ball power up lights

gSapphireBallPowerUpLight0off:: @ 0x082DD620
    .incbin "baserom.gba", 0x2DD620, 0x40

gSapphireBallPowerUpLight0on:: @ 0x082DD660
    .incbin "baserom.gba", 0x2DD660, 0x40

gSapphireBallPowerUpLight1off:: @ 0x082DD6A0
    .incbin "baserom.gba", 0x2DD6A0, 0x40

gSapphireBallPowerUpLight1on:: @ 0x082DD6E0
    .incbin "baserom.gba", 0x2DD6E0, 0x40

gSapphireBallPowerUpLight2off:: @ 0x082DD720
    .incbin "baserom.gba", 0x2DD720, 0x40

gSapphireBallPowerUpLight2on:: @ 0x082DD760
    .incbin "baserom.gba", 0x2DD760, 0x40


@ 'H' 'o' 'l' 'e' Lights

gSapphireHoleLightH_Off:: @ 0x082DD7A0
    .incbin "baserom.gba", 0x2DD7A0, 0x40

gSapphireHoleLightH_On:: @ 0x082DD7E0
    .incbin "baserom.gba", 0x2DD7E0, 0x40

gSapphireHoleLightO_Off:: @ 0x082DD820
    .incbin "baserom.gba", 0x2DD820, 0x40

gSapphireHoleLightO_On:: @ 0x082DD860
    .incbin "baserom.gba", 0x2DD860, 0x40

gSapphireHoleLightL_Off:: @ 0x082DD8A0
    .incbin "baserom.gba", 0x2DD8A0, 0x40

gSapphireHoleLightL_On:: @ 0x082DD8E0
    .incbin "baserom.gba", 0x2DD8E0, 0x40

gSapphireHoleLightE_Off:: @ 0x082DD920
    .incbin "baserom.gba", 0x2DD920, 0x40

gSapphireHoleLightE_On:: @ 0x082DD960
    .incbin "baserom.gba", 0x2DD960, 0x40



@ Catch light arrows / Center trap / hatch machine / P square indicator
@ Data is mostly separate... but cuts across rows into an otherwise blank



gSapphireCatchLight_082DD9A0:: @ 0x082DD9A0
    .incbin "baserom.gba", 0x2DD9A0, 0x40

gSapphireCatchLight_082DD9E0:: @ 0x082DD9E0
    .incbin "baserom.gba", 0x2DD9E0, 0x40
	.space 0x380

gSapphireCatchLight_082DDDA0:: @ 0x082DDDA0
    .incbin "baserom.gba", 0x2DDDA0, 0x40

gSapphireCatchLight_082DDDE0:: @ 0x082DDDE0
    .incbin "baserom.gba", 0x2DDDE0, 0x40

gSapphireCenterTrap_082DDE20:: @ 0x082DDE20
    .incbin "baserom.gba", 0x2DDE20, 0x40

gSapphireCenterTrap_082DDE60:: @ 0x082DDE60
    .incbin "baserom.gba", 0x2DDE60, 0x40

gSapphireCenterTrap_082DDEA0:: @ 0x082DDEA0
    .incbin "baserom.gba", 0x2DDEA0, 0x40

gSapphireCatchLight_082DDEE0:: @ 0x082DDEE0
    .incbin "baserom.gba", 0x2DDEE0, 0x40

gSapphireCatchLight_082DDF20:: @ 0x082DDF20
    .incbin "baserom.gba", 0x2DDF20, 0x40

gSapphireCatchLight_082DDF60:: @ 0x082DDF60
    .incbin "baserom.gba", 0x2DDF60, 0x40

gSapphireCatchLight_082DDFA0:: @ 0x082DDFA0
    .incbin "baserom.gba", 0x2DDFA0, 0x40

gSapphireCatchLight_082DDFE0:: @ 0x082DDFE0
    .incbin "baserom.gba", 0x2DDFE0, 0x40

gSapphireCatchLight_082DE020:: @ 0x082DE020
    .incbin "baserom.gba", 0x2DE020, 0x40

gSapphireCatchLight_082DE060:: @ 0x082DE060
    .incbin "baserom.gba", 0x2DE060, 0x40

gSapphireCatchLight_082DE0A0:: @ 0x082DE0A0
    .incbin "baserom.gba", 0x2DE0A0, 0x40

gSapphireCatchLight_082DE0E0:: @ 0x082DE0E0
    .incbin "baserom.gba", 0x2DE0E0, 0x40

gSapphireCatchLight_082DE120:: @ 0x082DE120
    .incbin "baserom.gba", 0x2DE120, 0x40

gSapphireCatchLight_082DE160:: @ 0x082DE160
    .incbin "baserom.gba", 0x2DE160, 0x40

gSapphireCatchLight_082DE1A0:: @ 0x082DE1A0
    .incbin "baserom.gba", 0x2DE1A0, 0x40

gHatchMachine_082DE1E0:: @ 0x082DE1E0
    .incbin "baserom.gba", 0x2DE1E0, 0x40

gSapphireCenterTrap_082DE220:: @ 0x082DE220
    .incbin "baserom.gba", 0x2DE220, 0x40

gSapphireCenterTrap_082DE260:: @ 0x082DE260
    .incbin "baserom.gba", 0x2DE260, 0x40

gSapphireCenterTrap_082DE2A0:: @ 0x082DE2A0
    .incbin "baserom.gba", 0x2DE2A0, 0x40

gSapphireCatchLight_082DE2E0:: @ 0x082DE2E0
    .incbin "baserom.gba", 0x2DE2E0, 0x40

gSapphireCatchLight_082DE320:: @ 0x082DE320
    .incbin "baserom.gba", 0x2DE320, 0x40

gSapphireCatchLight_082DE360:: @ 0x082DE360
    .incbin "baserom.gba", 0x2DE360, 0x40

gSapphireCatchLight_082DE3A0:: @ 0x082DE3A0
    .incbin "baserom.gba", 0x2DE3A0, 0x40

gSapphireCatchLight_082DE3E0:: @ 0x082DE3E0
    .incbin "baserom.gba", 0x2DE3E0, 0x40

gSapphireCatchLight_082DE420:: @ 0x082DE420
    .incbin "baserom.gba", 0x2DE420, 0x40

gSapphireCatchLight_082DE460:: @ 0x082DE460
    .incbin "baserom.gba", 0x2DE460, 0x40

gSapphireCatchLight_082DE4A0:: @ 0x082DE4A0
    .incbin "baserom.gba", 0x2DE4A0, 0x40

gSapphireCatchLight_082DE4E0:: @ 0x082DE4E0
    .incbin "baserom.gba", 0x2DE4E0, 0x40

gSapphireCatchLight_082DE520:: @ 0x082DE520
    .incbin "baserom.gba", 0x2DE520, 0x40

gSapphireCatchLight_082DE560:: @ 0x082DE560
    .incbin "baserom.gba", 0x2DE560, 0x40

gSapphireCatchLight_082DE5A0:: @ 0x082DE5A0
    .incbin "baserom.gba", 0x2DE5A0, 0x40




gHatchMachine_082DE5E0:: @ 0x082DE5E0
    .incbin "baserom.gba", 0x2DE5E0, 0x40

gHatchMachine_082DE620:: @ 0x082DE620
    .incbin "baserom.gba", 0x2DE620, 0x40

gHatchMachine_082DE660:: @ 0x082DE660
    .incbin "baserom.gba", 0x2DE660, 0x40

gHatchMachine_082DE6A0:: @ 0x082DE6A0
    .incbin "baserom.gba", 0x2DE6A0, 0x40

gHatchMachine_082DE6E0:: @ 0x082DE6E0
    .incbin "baserom.gba", 0x2DE6E0, 0x40

gHatchMachine_082DE720:: @ 0x082DE720
    .incbin "baserom.gba", 0x2DE720, 0x40
    .space 0x80

gHatchMachine_082DE7E0:: @ 0x082DE7E0
    .incbin "baserom.gba", 0x2DE7E0, 0x40

gHatchMachine_082DE820:: @ 0x082DE820
    .incbin "baserom.gba", 0x2DE820, 0x40

gHatchMachine_082DE860:: @ 0x082DE860
    .incbin "baserom.gba", 0x2DE860, 0x40

gHatchMachine_082DE8A0:: @ 0x082DE8A0
    .incbin "baserom.gba", 0x2DE8A0, 0x40

gHatchMachine_082DE8E0:: @ 0x082DE8E0
    .incbin "baserom.gba", 0x2DE8E0, 0x40

gHatchMachine_082DE920:: @ 0x082DE920
    .incbin "baserom.gba", 0x2DE920, 0x40

gHatchMachine_082DE960:: @ 0x082DE960
    .incbin "baserom.gba", 0x2DE960, 0x40

gHatchMachine_082DE9A0:: @ 0x082DE9A0
    .incbin "baserom.gba", 0x2DE9A0, 0x40

gHatchMachine_082DE9E0:: @ 0x082DE9E0
    .incbin "baserom.gba", 0x2DE9E0, 0x40

gHatchMachine_082DEA20:: @ 0x082DEA20
    .incbin "baserom.gba", 0x2DEA20, 0x40

gHatchMachine_082DEA60:: @ 0x082DEA60
    .incbin "baserom.gba", 0x2DEA60, 0x40

gHatchMachine_082DEAA0:: @ 0x082DEAA0
    .incbin "baserom.gba", 0x2DEAA0, 0x40

gHatchMachine_082DEAE0:: @ 0x082DEAE0
    .incbin "baserom.gba", 0x2DEAE0, 0x40

gHatchMachine_082DEB20:: @ 0x082DEB20
    .incbin "baserom.gba", 0x2DEB20, 0x40

gHatchMachine_082DEB60:: @ 0x082DEB60
    .incbin "baserom.gba", 0x2DEB60, 0x40

gHatchMachine_082DEBA0:: @ 0x082DEBA0
    .incbin "baserom.gba", 0x2DEBA0, 0x40

gHatchMachine_082DEBE0:: @ 0x082DEBE0
    .incbin "baserom.gba", 0x2DEBE0, 0x40

gHatchMachine_082DEC20:: @ 0x082DEC20
    .incbin "baserom.gba", 0x2DEC20, 0x40

gHatchMachine_082DEC60:: @ 0x082DEC60
    .incbin "baserom.gba", 0x2DEC60, 0x40

gHatchMachine_082DECA0:: @ 0x082DECA0
    .incbin "baserom.gba", 0x2DECA0, 0x40

gHatchMachine_082DECE0:: @ 0x082DECE0
    .incbin "baserom.gba", 0x2DECE0, 0x40

gHatchMachine_082DED20:: @ 0x082DED20
    .incbin "baserom.gba", 0x2DED20, 0x40

gHatchMachine_082DED60:: @ 0x082DED60
    .incbin "baserom.gba", 0x2DED60, 0x40

gHatchMachine_082DEDA0:: @ 0x082DEDA0
    .incbin "baserom.gba", 0x2DEDA0, 0x40

gHatchMachine_082DEDE0:: @ 0x082DEDE0
    .incbin "baserom.gba", 0x2DEDE0, 0x40

gHatchMachine_082DEE20:: @ 0x082DEE20
    .incbin "baserom.gba", 0x2DEE20, 0x40

gHatchMachine_082DEE60:: @ 0x082DEE60
    .incbin "baserom.gba", 0x2DEE60, 0x40

gHatchMachine_082DEEA0:: @ 0x082DEEA0
    .incbin "baserom.gba", 0x2DEEA0, 0x40



gSapphirePIndicator_082DEEE0:: @ 0x082DEEE0
    .incbin "baserom.gba", 0x2DEEE0, 0x40

gSapphirePIndicator_082DEF20:: @ 0x082DEF20
    .incbin "baserom.gba", 0x2DEF20, 0x40

gSapphirePIndicator_082DEF60:: @ 0x082DEF60
    .incbin "baserom.gba", 0x2DEF60, 0x40

gSapphirePIndicator_082DEFA0:: @ 0x082DEFA0
    .incbin "baserom.gba", 0x2DEFA0, 0x40

gSapphirePIndicator_082DEFE0:: @ 0x082DEFE0
    .incbin "baserom.gba", 0x2DEFE0, 0x40
    .space 0x200

gHatchMachine_082DF220:: @ 0x082DF220
    .incbin "baserom.gba", 0x2DF220, 0x40

gHatchMachine_082DF260:: @ 0x082DF260
    .incbin "baserom.gba", 0x2DF260, 0x40

gHatchMachine_082DF2A0:: @ 0x082DF2A0
    .incbin "baserom.gba", 0x2DF2A0, 0x40



gSapphirePIndicator_082DF2E0:: @ 0x082DF2E0
    .incbin "baserom.gba", 0x2DF2E0, 0x40

gSapphirePIndicator_082DF320:: @ 0x082DF320
    .incbin "baserom.gba", 0x2DF320, 0x40

gSapphirePIndicator_082DF360:: @ 0x082DF360
    .incbin "baserom.gba", 0x2DF360, 0x40

gSapphirePIndicator_082DF3A0:: @ 0x082DF3A0
    .incbin "baserom.gba", 0x2DF3A0, 0x40

gSapphirePIndicator_082DF3E0:: @ 0x082DF3E0
    .incbin "baserom.gba", 0x2DF3E0, 0x40
	.space 0x220



@ Saver light space. Area has more tiles than are actually used.
@ Actual usage is 2 rows of 7 tiles, one row of 6 tiles, one row 2 tiles
@ Data in memory has those as rectangles, and a different offset.
@ Leaving as is, without carving out the 'space' and separate carved zones for the junk data.

	.incbin "baserom.gba", 0x2DF640, 0x20
gSapphireSaver_082DF660:: @ 0x082DF660
    .incbin "baserom.gba", 0x2DF660, 0x100

gSapphireSaver_082DF760:: @ 0x082DF760
    .incbin "baserom.gba", 0x2DF760, 0x300

gSapphireSaver_082DFA60:: @ 0x082DFA60
    .incbin "baserom.gba", 0x2DFA60, 0x100

gSapphireSaver_082DFB60:: @ 0x082DFB60
    .incbin "baserom.gba", 0x2DFB60, 0x320

gSapphireSaver_082DFE80:: @ 0x082DFE80
    .incbin "baserom.gba", 0x2DFE80, 0x100

gSapphireSaver_082DFF80:: @ 0x082DFF80
    .incbin "baserom.gba", 0x2DFF80, 0x360

gSapphireSaver_082E02E0:: @ 0x082E02E0
    .incbin "baserom.gba", 0x2E02E0, 0x100

gSapphireSaver_082E03E0:: @ 0x082E03E0
    .incbin "baserom.gba", 0x2E03E0, 0x2C0


@ Hatch arrow, Catch arrow, Bumper arrow


gSapphireHatchArrow_082E06A0:: @ 0x082E06A0
    .incbin "baserom.gba", 0x2E06A0, 0x80

gSapphireHatchArrow_082E0720:: @ 0x082E0720
    .incbin "baserom.gba", 0x2E0720, 0x60

gSapphireCatchArrow_082E0780:: @ 0x082E0780
    .incbin "baserom.gba", 0x2E0780, 0x80

gSapphireCatchArrow_082E0800:: @ 0x082E0800
    .incbin "baserom.gba", 0x2E0800, 0x60

gSapphireBumperArrow_082E0860:: @ 0x082E0860
    .space 0x80 @ reference, not actually used
	@.incbin "baserom.gba", 0x2E0860, 0x80

gSapphireBumperArrow_082E08E0:: @ 0x082E08E0
	.space 0x80 @ reference, not actually used
	.space 0x100

gSapphireHatchArrow_082E0A60:: @ 0x082E0A60
    .incbin "baserom.gba", 0x2E0A60, 0x80

gSapphireHatchArrow_082E0AE0:: @ 0x082E0AE0
    .incbin "baserom.gba", 0x2E0AE0, 0x80

gSapphireCatchArrow_082E0B60:: @ 0x082E0B60
    .incbin "baserom.gba", 0x2E0B60, 0x80

gSapphireCatchArrow_082E0BE0:: @ 0x082E0BE0
    .incbin "baserom.gba", 0x2E0BE0, 0x80

gSapphireBumperArrow_082E0C60:: @ 0x082E0C60
    .incbin "baserom.gba", 0x2E0C60, 0x80

gSapphireBumperArrow_082E0CE0:: @ 0x082E0CE0
    .incbin "baserom.gba", 0x2E0CE0, 0x80
    .space 0x100

gSapphireHatchArrow_082E0E60:: @ 0x082E0E60
    .incbin "baserom.gba", 0x2E0E60, 0x80

gSapphireHatchArrow_082E0EE0:: @ 0x082E0EE0
    .incbin "baserom.gba", 0x2E0EE0, 0x80

gSapphireCatchArrow_082E0F60:: @ 0x082E0F60
    .incbin "baserom.gba", 0x2E0F60, 0x80

gSapphireCatchArrow_082E0FE0:: @ 0x082E0FE0
    .incbin "baserom.gba", 0x2E0FE0, 0x80

gSapphireBumperArrow_082E1060:: @ 0x082E1060
    .incbin "baserom.gba", 0x2E1060, 0x80

gSapphireBumperArrow_082E10E0:: @ 0x082E10E0
    .incbin "baserom.gba", 0x2E10E0, 0x80
    .space 0x100

gSapphireHatchArrow_082E1260:: @ 0x082E1260
    .incbin "baserom.gba", 0x2E1260, 0x80

gSapphireHatchArrow_082E12E0:: @ 0x082E12E0
    .incbin "baserom.gba", 0x2E12E0, 0x80

gSapphireCatchArrow_082E1360:: @ 0x082E1360
    .incbin "baserom.gba", 0x2E1360, 0x80

gSapphireCatchArrow_082E13E0:: @ 0x082E13E0
    .incbin "baserom.gba", 0x2E13E0, 0x80

gSapphireBumperArrow_082E1460:: @ 0x082E1460
    .incbin "baserom.gba", 0x2E1460, 0x80

gSapphireBumperArrow_082E14E0:: @ 0x082E14E0
    .incbin "baserom.gba", 0x2E14E0, 0x80
    .space 0x120



@ arrow for ramp leading to shop: mart/evo

gSapphireMartArrow_082E1680:: @ 0x082E1680
    .incbin "baserom.gba", 0x2E1680, 0x80

gSapphireMartArrow_082E1700:: @ 0x082E1700
    .incbin "baserom.gba", 0x2E1700, 0x80

gSapphireEvoArrow_082E1780:: @ 0x082E1780
    .incbin "baserom.gba", 0x2E1780, 0x80

gSapphireEvoArrow_082E1800:: @ 0x082E1800
    .incbin "baserom.gba", 0x2E1800, 0x80
	.space 0x200

gSapphireMartArrow_082E1A80:: @ 0x082E1A80
    .incbin "baserom.gba", 0x2E1A80, 0x80

gSapphireMartArrow_082E1B00:: @ 0x082E1B00
    .incbin "baserom.gba", 0x2E1B00, 0x80

gSapphireEvoArrow_082E1B80:: @ 0x082E1B80
    .incbin "baserom.gba", 0x2E1B80, 0x80

gSapphireEvoArrow_082E1C00:: @ 0x082E1C00
    .incbin "baserom.gba", 0x2E1C00, 0x80
	.space 0x200

gSapphireMartArrow_082E1E80:: @ 0x082E1E80
    .incbin "baserom.gba", 0x2E1E80, 0x80

gSapphireMartArrow_082E1F00:: @ 0x082E1F00
    .incbin "baserom.gba", 0x2E1F00, 0x80

gSapphireEvoArrow_082E1F80:: @ 0x082E1F80
    .incbin "baserom.gba", 0x2E1F80, 0x80

gSapphireEvoArrow_082E2000:: @ 0x082E2000
    .incbin "baserom.gba", 0x2E2000, 0x80
	.space 0x200

gSapphireMartArrow_082E2280:: @ 0x082E2280
    .incbin "baserom.gba", 0x2E2280, 0x80

gSapphireMartArrow_082E2300:: @ 0x082E2300
    .incbin "baserom.gba", 0x2E2300, 0x80

gSapphireEvoArrow_082E2380:: @ 0x082E2380
    .incbin "baserom.gba", 0x2E2380, 0x80

gSapphireEvoArrow_082E2400:: @ 0x082E2400
    .incbin "baserom.gba", 0x2E2400, 0x80
	.space 0x620


@ Slingshot wedge lights

gSapphireSlingshot_082E2AA0:: @ 0x082E2AA0
    .incbin "baserom.gba", 0x2E2AA0, 0x60

gSapphireSlingshot_082E2B00:: @ 0x082E2B00
    .incbin "baserom.gba", 0x2E2B00, 0xA0

gSapphireSlingshot_082E2BA0:: @ 0x082E2BA0
    .incbin "baserom.gba", 0x2E2BA0, 0x60

gSapphireSlingshot_082E2C00:: @ 0x082E2C00
    .incbin "baserom.gba", 0x2E2C00, 0x2A0

gSapphireSlingshot_082E2EA0:: @ 0x082E2EA0
    .incbin "baserom.gba", 0x2E2EA0, 0x60

gSapphireSlingshot_082E2F00:: @ 0x082E2F00
    .incbin "baserom.gba", 0x2E2F00, 0x80

gSapphireSlingshot_082E2F80:: @ 0x082E2F80
    .incbin "baserom.gba", 0x2E2F80, 0x60

gSapphireSlingshot_082E2FE0:: @ 0x082E2FE0
    .incbin "baserom.gba", 0x2E2FE0, 0x2C0

gSapphireSlingshot_082E32A0:: @ 0x082E32A0
    .incbin "baserom.gba", 0x2E32A0, 0x60

gSapphireSlingshot_082E3300:: @ 0x082E3300
    .incbin "baserom.gba", 0x2E3300, 0x60

gSapphireSlingshot_082E3360:: @ 0x082E3360
    .incbin "baserom.gba", 0x2E3360, 0x60

gSapphireSlingshot_082E33C0:: @ 0x082E33C0
    .incbin "baserom.gba", 0x2E33C0, 0x2E0

gSapphireSlingshot_082E36A0:: @ 0x082E36A0
    .incbin "baserom.gba", 0x2E36A0, 0x60

gSapphireSlingshot_082E3700:: @ 0x082E3700
    .incbin "baserom.gba", 0x2E3700, 0x60

gSapphireSlingshot_082E3760:: @ 0x082E3760
    .incbin "baserom.gba", 0x2E3760, 0x60

gSapphireSlingshot_082E37C0:: @ 0x082E37C0
    .incbin "baserom.gba", 0x2E37C0, 0x300

gSapphireSlingshot_082E3AC0:: @ 0x082E3AC0
    .incbin "baserom.gba", 0x2E3AC0, 0x60

gSapphireSlingshot_082E3B20:: @ 0x082E3B20
    .incbin "baserom.gba", 0x2E3B20, 0x40

gSapphireSlingshot_082E3B60:: @ 0x082E3B60
    .incbin "baserom.gba", 0x2E3B60, 0x60

gSapphireSlingshot_082E3BC0:: @ 0x082E3BC0
    .incbin "baserom.gba", 0x2E3BC0, 0x300


gWailmerWater_082E3EC0:: @ 0x082E3EC0
    .incbin "baserom.gba", 0x2E3EC0, 0x80

gWailmerWater_082E3F40:: @ 0x082E3F40
    .incbin "baserom.gba", 0x2E3F40, 0x80

gWailmerWater_082E3FC0:: @ 0x082E3FC0
    .incbin "baserom.gba", 0x2E3FC0, 0x300

gWailmerWater_082E42C0:: @ 0x082E42C0
    .incbin "baserom.gba", 0x2E42C0, 0x80

gWailmerWater_082E4340:: @ 0x082E4340
    .incbin "baserom.gba", 0x2E4340, 0x80

gWailmerWater_082E43C0:: @ 0x082E43C0
    .incbin "baserom.gba", 0x2E43C0, 0x300

gWailmerWater_082E46C0:: @ 0x082E46C0
    .incbin "baserom.gba", 0x2E46C0, 0x80

gWailmerWater_082E4740:: @ 0x082E4740
    .incbin "baserom.gba", 0x2E4740, 0x80

gWailmerWater_082E47C0:: @ 0x082E47C0
    .incbin "baserom.gba", 0x2E47C0, 0x300

gWailmerWater_082E4AC0:: @ 0x082E4AC0
    .incbin "baserom.gba", 0x2E4AC0, 0x80

gWailmerWater_082E4B40:: @ 0x082E4B40
    .incbin "baserom.gba", 0x2E4B40, 0x80

gWailmerWater_082E4BC0:: @ 0x082E4BC0
    .incbin "baserom.gba", 0x2E4BC0, 0x320

gSapphireBoardBGTiles:: @ 0x082E4EE0
	.incbin "baserom.gba", 0x2E4EE0, 0x8000

gSapphireBoardBGTilemap:: @ 0x082ECEE0
	.incbin "baserom.gba", 0x2ECEE0, 0x1000
