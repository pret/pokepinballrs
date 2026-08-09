@ Note: ruby_board.inc file has a shared 'bumper collision map' at 0x08252B10

gSapphireBoardPalette:: @ 0x0826EC10
	.incbin "graphics/stage/sapphire/sapphire_board.gbapal"

gSapphireBoardBG0Tilemap:: @ 0x0826EE10
	.incbin "graphics/stage/sapphire/sapphire_board_bg0_tilemap.bin"

gSapphireBoardCollisionTileDataLayer0:: @ 0x0826FE10
.incbin "data/board_data/collision/sapphire/boardtop_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer0:: @ 0x08271E10
.incbin "data/board_data/collision/sapphire/boardtop_angledata.bin"

gSapphireBoardCollisionTypeDataLayer0:: @ 0x08286A10
.incbin "data/board_data/collision/sapphire/boardtop_typedata.bin"

gSapphireBoardCollisionTileDataLayer1:: @ 0x08291010
.incbin "data/board_data/collision/sapphire/boardbottom_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer1:: @ 0x08293010
.incbin "data/board_data/collision/sapphire/boardbottom_angledata.bin"

gSapphireBoardCollisionTypeDataLayer1:: @ 0x082A5490
.incbin "data/board_data/collision/sapphire/boardbottom_typedata.bin"

gSapphireBoardBG1Tilemap:: @ 0x082AE6D0
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tilemap.bin"

gSapphireBoardCollisionTileDataLayer2:: @ 0x082AF6D0
.incbin "data/board_data/collision/sapphire/topramp_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer2:: @ 0x082B16D0
.incbin "data/board_data/collision/sapphire/topramp_angledata.bin"

gSapphireBoardCollisionTypeDataLayer2:: @ 0x082BE7D0
.incbin "data/board_data/collision/sapphire/topramp_typedata.bin"

gSapphireBoardCollisionTileDataLayer3:: @ 0x082C5050
.incbin "data/board_data/collision/sapphire/hatchexitramp_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer3:: @ 0x082C7050
.incbin "data/board_data/collision/sapphire/hatchexitramp_angledata.bin"

gSapphireBoardCollisionTypeDataLayer3:: @ 0x082CF350
.incbin "data/board_data/collision/sapphire/hatchexitramp_typedata.bin"

gSapphireBoardCompressedTiles1:: @ 0x082D34D0
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tiles.4bpp.lz"

gSapphireBoardCompressedTiles2:: @ 0x082D523C
	.incbin "graphics/stage/sapphire/sapphire_board_bgtop_tiles.4bpp.lz"

gSapphireBoardCompressedBGTileBuffer:: @ 0x082D8998
	.incbin "graphics/stage/sapphire/sapphire_board_bgbottom_tiles.4bpp.lz"



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
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
    .space 0x20

gSapphireCoinArrow_082DB640:: @ 0x082DB640
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p0.4bpp"
    .space 0x20

gSapphireCoinArrow_082DB6A0:: @ 0x082DB6A0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
    .incbin "baserom.gba", 0x2db6e0, 0x40

gSapphireCoinArrow_082DB720:: @ 0x082DB720
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
    .incbin "baserom.gba", 0x2db760, 0x20

gSapphireCoinArrow_082DB780:: @ 0x082DB780
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
    .incbin "baserom.gba", 0x2db7c0, 0x20

gSapphireCoinArrow_082DB7E0:: @ 0x082DB7E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p0.4bpp"

gSapphireCoinArrow_082DB820:: @ 0x082DB820
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
    .incbin "baserom.gba", 0x2db860, 0x20

gSapphireCoinArrow_082DB880:: @ 0x082DB880
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p0.4bpp"
    .incbin "baserom.gba", 0x2db8c0, 0x20

gSapphireCoinArrow_082DB8E0:: @ 0x082DB8E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
    .incbin "baserom.gba", 0x2db920, 0xc0

gSapphireCoinArrow_082DB9E0:: @ 0x082DB9E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p1.4bpp"

gSapphireCoinArrow_082DBA40:: @ 0x082DBA40
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p1.4bpp"

gSapphireCoinArrow_082DBAA0:: @ 0x082DBAA0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
    .incbin "baserom.gba", 0x2dbb00, 0x20

gSapphireCoinArrow_082DBB20:: @ 0x082DBB20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
    .incbin "baserom.gba", 0x2dbb60, 0x20

gSapphireCoinArrow_082DBB80:: @ 0x082DBB80
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
    .incbin "baserom.gba", 0x2dbbc0, 0x20

gSapphireCoinArrow_082DBBE0:: @ 0x082DBBE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p1.4bpp"

gSapphireCoinArrow_082DBC20:: @ 0x082DBC20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
    .incbin "baserom.gba", 0x2dbc60, 0x20

gSapphireCoinArrow_082DBC80:: @ 0x082DBC80
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1.4bpp"
    .incbin "baserom.gba", 0x2dbcc0, 0x20

gSapphireCoinArrow_082DBCE0:: @ 0x082DBCE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
    .incbin "baserom.gba", 0x2dbd20, 0xc0

gSapphireCoinArrow_082DBDE0:: @ 0x082DBDE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p2.4bpp"

gSapphireCoinArrow_082DBE40:: @ 0x082DBE40
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p2.4bpp"

gSapphireCoinArrow_082DBEA0:: @ 0x082DBEA0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p2.4bpp"

gSapphireCoinArrow_082DBF20:: @ 0x082DBF20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p2.4bpp"

gSapphireCoinArrow_082DBF80:: @ 0x082DBF80
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p2.4bpp"

gSapphireCoinArrow_082DBFE0:: @ 0x082DBFE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p2.4bpp"

gSapphireCoinArrow_082DC020:: @ 0x082DC020
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
    .incbin "baserom.gba", 0x2dc060, 0x20

gSapphireCoinArrow_082DC080:: @ 0x082DC080
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2.4bpp"
    .incbin "baserom.gba", 0x2dc0c0, 0x20

gSapphireCoinArrow_082DC0E0:: @ 0x082DC0E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
    .incbin "baserom.gba", 0x2dc120, 0xc0


@ Get Arrows

gSapphireGetArrow_082DC1E0:: @ 0x082DC1E0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_0.4bpp"

gSapphireGetArrow_082DC240:: @ 0x082DC240
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_0.4bpp"

gSapphireGetArrow_082DC2A0:: @ 0x082DC2A0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_0.4bpp"
    .space 0x20

gSapphireGetArrow_082DC320:: @ 0x082DC320
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_0.4bpp"
    .space 0x20

gSapphireGetArrow_082DC380:: @ 0x082DC380
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_0.4bpp"
    .space 0x20

gSapphireGetArrow_082DC3E0:: @ 0x082DC3E0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_0.4bpp"
    .space 0x20

gSapphireGetArrow_082DC440:: @ 0x082DC440
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_0.4bpp"
    .incbin "baserom.gba", 0x2dc480, 0x20

gSapphireGetArrow_082DC4A0:: @ 0x082DC4A0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_0.4bpp"
    .incbin "baserom.gba", 0x2dc4e0, 0x20

gSapphireGetArrow_082DC500:: @ 0x082DC500
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_0.4bpp"
    .incbin "baserom.gba", 0x2dc540, 0x20

gSapphireGetArrow_082DC560:: @ 0x082DC560
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_0.4bpp"
    .space 0x40

gSapphireGetArrow_082DC5E0:: @ 0x082DC5E0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_1.4bpp"

gSapphireGetArrow_082DC640:: @ 0x082DC640
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_1.4bpp"

gSapphireGetArrow_082DC6A0:: @ 0x082DC6A0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1.4bpp"
    .incbin "baserom.gba", 0x2dc700, 0x20

gSapphireGetArrow_082DC720:: @ 0x082DC720
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1.4bpp"
    .incbin "baserom.gba", 0x2dc760, 0x20

gSapphireGetArrow_082DC780:: @ 0x082DC780
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1.4bpp"
    .incbin "baserom.gba", 0x2dc7c0, 0x20

gSapphireGetArrow_082DC7E0:: @ 0x082DC7E0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1.4bpp"
    .incbin "baserom.gba", 0x2dc820, 0x20

gSapphireGetArrow_082DC840:: @ 0x082DC840
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_1.4bpp"

gSapphireGetArrow_082DC880:: @ 0x082DC880
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_1.4bpp"

gSapphireGetArrow_082DC8E0:: @ 0x082DC8E0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_1.4bpp"

gSapphireGetArrow_082DC940:: @ 0x082DC940
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_1.4bpp"
    .space 0x40

gSapphireGetArrow_082DC9E0:: @ 0x082DC9E0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_2.4bpp"

gSapphireGetArrow_082DCA40:: @ 0x082DCA40
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_2.4bpp"

gSapphireGetArrow_082DCAA0:: @ 0x082DCAA0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_2.4bpp"

gSapphireGetArrow_082DCB00:: @ 0x082DCB00
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_2.4bpp"

gSapphireGetArrow_082DCB60:: @ 0x082DCB60
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_2.4bpp"

gSapphireGetArrow_082DCBC0:: @ 0x082DCBC0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_2.4bpp"

gSapphireGetArrow_082DCC20:: @ 0x082DCC20
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_2.4bpp"

gSapphireGetArrow_082DCC80:: @ 0x082DCC80
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_2.4bpp"
    .space 0x20

gSapphireGetArrow_082DCCE0:: @ 0x082DCCE0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_2.4bpp"
    .space 0x20

gSapphireGetArrow_082DCD40:: @ 0x082DCD40
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_2.4bpp"
    .space 0x80


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
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_0_off.4bpp"

gSapphireBallPowerUpLight0on:: @ 0x082DD660
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_0_on.4bpp"

gSapphireBallPowerUpLight1off:: @ 0x082DD6A0
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_1_off.4bpp"

gSapphireBallPowerUpLight1on:: @ 0x082DD6E0
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_1_on.4bpp"

gSapphireBallPowerUpLight2off:: @ 0x082DD720
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_2_off.4bpp"

gSapphireBallPowerUpLight2on:: @ 0x082DD760
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_2_on.4bpp"


@ 'H' 'o' 'l' 'e' Lights

gSapphireHoleLightH_Off:: @ 0x082DD7A0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_off.4bpp"

gSapphireHoleLightH_On:: @ 0x082DD7E0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_on.4bpp"

gSapphireHoleLightO_Off:: @ 0x082DD820
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_off.4bpp"

gSapphireHoleLightO_On:: @ 0x082DD860
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_on.4bpp"

gSapphireHoleLightL_Off:: @ 0x082DD8A0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_off.4bpp"

gSapphireHoleLightL_On:: @ 0x082DD8E0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_on.4bpp"

gSapphireHoleLightE_Off:: @ 0x082DD920
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_off.4bpp"

gSapphireHoleLightE_On:: @ 0x082DD960
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_on.4bpp"



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

gHatchMachineSeg0IdleA:: @ 0x082DE1E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_a.4bpp"

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




gHatchMachineSeg0IdleB:: @ 0x082DE5E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_b.4bpp"

gHatchMachineSeg0HitA:: @ 0x082DE620
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_a.4bpp"

gHatchMachineSeg1IdleA:: @ 0x082DE660
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_a.4bpp"

gHatchMachineSeg1HitA:: @ 0x082DE6A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_a.4bpp"

gHatchMachineSeg2IdleA:: @ 0x082DE6E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_a.4bpp"

gHatchMachineSeg2HitA:: @ 0x082DE720
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_a.4bpp"
    .space 0x80

gHatchMachineSeg4IdleA:: @ 0x082DE7E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_a.4bpp"

gHatchMachineSeg4HitA:: @ 0x082DE820
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_a.4bpp"

gHatchMachineSeg5IdleA:: @ 0x082DE860
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_a.4bpp"

gHatchMachineSeg5HitA:: @ 0x082DE8A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_a.4bpp"

gHatchMachineSeg6IdleA:: @ 0x082DE8E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_a.4bpp"

gHatchMachineSeg6HitA:: @ 0x082DE920
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_a.4bpp"

gHatchMachineSeg7IdleA:: @ 0x082DE960
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_a.4bpp"

gHatchMachineSeg7HitA:: @ 0x082DE9A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_a.4bpp"

gHatchMachineSeg8IdleA:: @ 0x082DE9E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_a.4bpp"

gHatchMachineSeg0HitB:: @ 0x082DEA20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_b.4bpp"

gHatchMachineSeg1IdleB:: @ 0x082DEA60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_b.4bpp"

gHatchMachineSeg1HitB:: @ 0x082DEAA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_b.4bpp"

gHatchMachineSeg2IdleB:: @ 0x082DEAE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_b.4bpp"

gHatchMachineSeg2HitB:: @ 0x082DEB20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_b.4bpp"

gHatchMachineSeg3Idle:: @ 0x082DEB60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_idle.4bpp"

gHatchMachineSeg3Hit:: @ 0x082DEBA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_hit.4bpp"

gHatchMachineSeg4IdleB:: @ 0x082DEBE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_b.4bpp"

gHatchMachineSeg4HitB:: @ 0x082DEC20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_b.4bpp"

gHatchMachineSeg5IdleB:: @ 0x082DEC60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_b.4bpp"

gHatchMachineSeg5HitB:: @ 0x082DECA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_b.4bpp"

gHatchMachineSeg6IdleB:: @ 0x082DECE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_b.4bpp"

gHatchMachineSeg6HitB:: @ 0x082DED20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_b.4bpp"

gHatchMachineSeg7IdleB:: @ 0x082DED60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_b.4bpp"

gHatchMachineSeg7HitB:: @ 0x082DEDA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_b.4bpp"

gHatchMachineSeg8IdleB:: @ 0x082DEDE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_b.4bpp"

gHatchMachineSeg8HitA:: @ 0x082DEE20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_a.4bpp"

gHatchMachineSeg9IdleA:: @ 0x082DEE60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_a.4bpp"

gHatchMachineSeg9HitA:: @ 0x082DEEA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_a.4bpp"



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

gHatchMachineSeg8HitB:: @ 0x082DF220
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_b.4bpp"

gHatchMachineSeg9IdleB:: @ 0x082DF260
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_b.4bpp"

gHatchMachineSeg9HitB:: @ 0x082DF2A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_b.4bpp"



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
gSapphireSaverRow0Tile_Off:: @ 0x082DF660
    .incbin "graphics/stage/sapphire/saver/saver_off_row0.4bpp"
    .incbin "baserom.gba", 0x2DF740, 0x20

gSapphireSaverRow0Tile_On:: @ 0x082DF760
    .incbin "graphics/stage/sapphire/saver/saver_on_row0.4bpp"
    .incbin "baserom.gba", 0x2DF840, 0x220

gSapphireSaverRow1Tile_Off:: @ 0x082DFA60
    .incbin "graphics/stage/sapphire/saver/saver_off_row1.4bpp"
    .incbin "baserom.gba", 0x2DFB40, 0x20

gSapphireSaverRow1Tile_On:: @ 0x082DFB60
    .incbin "graphics/stage/sapphire/saver/saver_on_row1.4bpp"
    .incbin "baserom.gba", 0x2DFC40, 0x240

gSapphireSaverRow2Tile_Off:: @ 0x082DFE80
    .incbin "graphics/stage/sapphire/saver/saver_off_row2.4bpp"
    .incbin "baserom.gba", 0x2DFF40, 0x40

gSapphireSaverRow2Tile_On:: @ 0x082DFF80
    .incbin "graphics/stage/sapphire/saver/saver_on_row2.4bpp"
    .incbin "baserom.gba", 0x2E0040, 0x2A0

gSapphireSaverRow3Tile_Off:: @ 0x082E02E0
    .incbin "graphics/stage/sapphire/saver/saver_off_row3.4bpp"
    .incbin "baserom.gba", 0x2E0320, 0xC0

gSapphireSaverRow3Tile_On:: @ 0x082E03E0
    .incbin "graphics/stage/sapphire/saver/saver_on_row3.4bpp"
    .incbin "baserom.gba", 0x2E0420, 0x280


@ Hatch arrow, Catch arrow, Bumper arrow


gSapphireHatchArrow_082E06A0:: @ 0x082E06A0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row0.4bpp"
    .space 0x40

gSapphireHatchArrow_082E0720:: @ 0x082E0720
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row0.4bpp"
    .incbin "baserom.gba", 0x2e0760, 0x20

gSapphireCatchArrow_082E0780:: @ 0x082E0780
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row0.4bpp"
    .incbin "baserom.gba", 0x2e07e0, 0x20

gSapphireCatchArrow_082E0800:: @ 0x082E0800
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row0.4bpp"

gSapphireBumperArrow_082E0860:: @ 0x082E0860
    .space 0x80 @ reference, not actually used
	@.incbin "baserom.gba", 0x2E0860, 0x80

gSapphireBumperArrow_082E08E0:: @ 0x082E08E0
	.space 0x80 @ reference, not actually used
	.space 0x100

gSapphireHatchArrow_082E0A60:: @ 0x082E0A60
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row1.4bpp"

gSapphireHatchArrow_082E0AE0:: @ 0x082E0AE0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row1.4bpp"

gSapphireCatchArrow_082E0B60:: @ 0x082E0B60
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row1.4bpp"

gSapphireCatchArrow_082E0BE0:: @ 0x082E0BE0
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row1.4bpp"

gSapphireBumperArrow_082E0C60:: @ 0x082E0C60
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row1.4bpp"

gSapphireBumperArrow_082E0CE0:: @ 0x082E0CE0
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row1.4bpp"
    .space 0x100

gSapphireHatchArrow_082E0E60:: @ 0x082E0E60
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row2.4bpp"

gSapphireHatchArrow_082E0EE0:: @ 0x082E0EE0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row2.4bpp"

gSapphireCatchArrow_082E0F60:: @ 0x082E0F60
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row2.4bpp"

gSapphireCatchArrow_082E0FE0:: @ 0x082E0FE0
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row2.4bpp"

gSapphireBumperArrow_082E1060:: @ 0x082E1060
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row2.4bpp"

gSapphireBumperArrow_082E10E0:: @ 0x082E10E0
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row2.4bpp"
    .space 0x100

gSapphireHatchArrow_082E1260:: @ 0x082E1260
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row3.4bpp"

gSapphireHatchArrow_082E12E0:: @ 0x082E12E0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row3.4bpp"

gSapphireCatchArrow_082E1360:: @ 0x082E1360
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row3.4bpp"
    .space 0x20

gSapphireCatchArrow_082E13E0:: @ 0x082E13E0
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row3.4bpp"
    .space 0x20

gSapphireBumperArrow_082E1460:: @ 0x082E1460
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row3.4bpp"

gSapphireBumperArrow_082E14E0:: @ 0x082E14E0
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row3.4bpp"
    .space 0x120



@ arrow for ramp leading to shop: mart/evo

gSapphireMartArrow_082E1680:: @ 0x082E1680
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row0.4bpp"

gSapphireMartArrow_082E1700:: @ 0x082E1700
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row0.4bpp"

gSapphireEvoArrow_082E1780:: @ 0x082E1780
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row0.4bpp"

gSapphireEvoArrow_082E1800:: @ 0x082E1800
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row0.4bpp"
	.space 0x200

gSapphireMartArrow_082E1A80:: @ 0x082E1A80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row1.4bpp"

gSapphireMartArrow_082E1B00:: @ 0x082E1B00
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row1.4bpp"

gSapphireEvoArrow_082E1B80:: @ 0x082E1B80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row1.4bpp"

gSapphireEvoArrow_082E1C00:: @ 0x082E1C00
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row1.4bpp"
	.space 0x200

gSapphireMartArrow_082E1E80:: @ 0x082E1E80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row2.4bpp"

gSapphireMartArrow_082E1F00:: @ 0x082E1F00
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row2.4bpp"

gSapphireEvoArrow_082E1F80:: @ 0x082E1F80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row2.4bpp"

gSapphireEvoArrow_082E2000:: @ 0x082E2000
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row2.4bpp"
	.space 0x200

gSapphireMartArrow_082E2280:: @ 0x082E2280
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3.4bpp"
    .incbin "baserom.gba", 0x2e22e0, 0x20

gSapphireMartArrow_082E2300:: @ 0x082E2300
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3.4bpp"
    .incbin "baserom.gba", 0x2e2360, 0x20

gSapphireEvoArrow_082E2380:: @ 0x082E2380
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3.4bpp"
    .incbin "baserom.gba", 0x2e23e0, 0x20

gSapphireEvoArrow_082E2400:: @ 0x082E2400
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3.4bpp"
    .incbin "baserom.gba", 0x2e2460, 0x20
	.space 0x620


@ Slingshot wedge lights

gSapphire_LSlingshot_Off_R0:: @ 0x082E2AA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row0.4bpp"
	.space 0x40

gSapphire_LSlingshot_On_R0:: @ 0x082E2B00
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row0.4bpp"
	.space 0x80

gSapphire_RSlingshot_Off_R0:: @ 0x082E2BA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row0.4bpp"
	.space 0x40

gSapphire_RSlingshot_On_R0:: @ 0x082E2C00
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row0.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R1:: @ 0x082E2EA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row1.4bpp"
	.space 0x20

gSapphire_LSlingshot_On_R1:: @ 0x082E2F00
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row1.4bpp"
	.space 0x40

gSapphire_RSlingshot_Off_R1:: @ 0x082E2F80
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row1.4bpp"
	.space 0x20

gSapphire_RSlingshot_On_R1:: @ 0x082E2FE0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row1.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R2:: @ 0x082E32A0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row2.4bpp"

gSapphire_LSlingshot_On_R2:: @ 0x082E3300
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row2.4bpp"

gSapphire_RSlingshot_Off_R2:: @ 0x082E3360
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row2.4bpp"

gSapphire_RSlingshot_On_R2:: @ 0x082E33C0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row2.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R3:: @ 0x082E36A0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row3.4bpp"

gSapphire_LSlingshot_On_R3:: @ 0x082E3700
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row3.4bpp"

gSapphire_RSlingshot_Off_R3:: @ 0x082E3760
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row3.4bpp"

gSapphire_RSlingshot_On_R3:: @ 0x082E37C0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row3.4bpp"
	.space 0x2A0

gSapphire_LSlingshot_Off_R4:: @ 0x082E3AC0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row4.4bpp"
	.space 0x20

gSapphire_LSlingshot_On_R4:: @ 0x082E3B20
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row4.4bpp"

gSapphire_RSlingshot_Off_R4:: @ 0x082E3B60
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row4.4bpp"
	.space 0x20

gSapphire_RSlingshot_On_R4:: @ 0x082E3BC0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row4.4bpp"
	.space 0x2C0


gWailmerWaterFrame0Row0:: @ 0x082E3EC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row0.4bpp"
	.space 0x40

gWailmerWaterFrame1Row0:: @ 0x082E3F40
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row0.4bpp"
	.space 0x40

gWailmerWaterFrame2Row0:: @ 0x082E3FC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row0.4bpp"
	.space 0x2C0

gWailmerWaterFrame0Row1:: @ 0x082E42C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row1.4bpp"

gWailmerWaterFrame1Row1:: @ 0x082E4340
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row1.4bpp"

gWailmerWaterFrame2Row1:: @ 0x082E43C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row1.4bpp"
	.space 0x280

gWailmerWaterFrame0Row2:: @ 0x082E46C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row2.4bpp"
	.space 0x20

gWailmerWaterFrame1Row2:: @ 0x082E4740
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row2.4bpp"
	.space 0x20

gWailmerWaterFrame2Row2:: @ 0x082E47C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row2.4bpp"
	.space 0x2A0

gWailmerWaterFrame0Row3:: @ 0x082E4AC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row3.4bpp"
	.space 0x20

gWailmerWaterFrame1Row3:: @ 0x082E4B40
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row3.4bpp"
	.space 0x20

gWailmerWaterFrame2Row3:: @ 0x082E4BC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row3.4bpp"
	.space 0x2C0

gSapphireBoardBGTiles:: @ 0x082E4EE0
	@ loaded to charblock 2; tiles 0-703 are overwritten by the scroll ring
	.incbin "graphics/stage/sapphire/sapphire_board_bg_tiles.4bpp"

gSapphireBoardBGTilemap:: @ 0x082ECEE0
	.incbin "graphics/stage/sapphire/sapphire_board_bg_tilemap.bin"
