@ Note: file has a shared 'bumper collision map' at 0x08252B10
@ All other entries in this file are ruby board specific

gRubyBoardBG0Tilemap:: @ 0x081C08E4
	.incbin "baserom.gba", 0x1C08E4, 0x1000

gRubyBoardCollisionTileDataLayer0:: @ 0x081C18E4
    .incbin "baserom.gba", 0x1C18E4, 0x2000

gRubyBoardCollisionAngleDataLayer0:: @ 0x081C38E4
    .incbin "baserom.gba", 0x1C38E4, 0x18780

gRubyBoardCollisionTypeDataLayer0:: @ 0x081DC064
    .incbin "baserom.gba", 0x1DC064, 0xC3C0

gRubyBoardCollisionTileDataLayer0Alt:: @ 0x081E8424
    .incbin "baserom.gba", 0x1E8424, 0x2000

gRubyBoardCollisionAngleDataLayer0Alt:: @ 0x081EA424
    .incbin "baserom.gba", 0x1EA424, 0x18380

gRubyBoardCollisionTypeDataLayer0Alt:: @ 0x082027A4
    .incbin "baserom.gba", 0x2027A4, 0xC1C0

gRubyBoardCollisionTileDataLayer1:: @ 0x0820E964
    .incbin "baserom.gba", 0x20E964, 0x2000

gRubyBoardCollisionAngleDataLayer1:: @ 0x08210964
    .incbin "baserom.gba", 0x210964, 0x13C80

gRubyBoardCollisionTypeDataLayer1:: @ 0x082245E4
    .incbin "baserom.gba", 0x2245E4, 0x9E40

gRubyBoardBG1Tilemap:: @ 0x0822E424
	.incbin "baserom.gba", 0x22E424, 0x1000

gRubyBoardCollisionTileDataLayer2:: @ 0x0822F424
    .incbin "baserom.gba", 0x22F424, 0x2000

gRubyBoardCollisionAngleDataLayer2:: @ 0x08231424
    .incbin "baserom.gba", 0x231424, 0x11E80

gRubyBoardCollisionTypeDataLayer2:: @ 0x082432A4
    .incbin "baserom.gba", 0x2432A4, 0x8F40

gRubyBoardCompressedTiles1:: @ 0x0824C1E4
	.incbin "baserom.gba", 0x24C1E4, 0x1B7C

gRubyBoardCompressedTiles2:: @ 0x0824DD60
	.incbin "baserom.gba", 0x24DD60, 0x2BD4

gRubyBoardCompressedBGTileBuffer:: @ 0x08250934
	.incbin "baserom.gba", 0x250934, 0x21DC

gSharedBumperCollisionMap:: @ 0x08252B10
	.incbin "baserom.gba", 0x252B10, 0x2000

gRubyAltEntity0CollisionMap:: @ 0x08254B10
	.incbin "baserom.gba", 0x254B10, 0x2880

gRubyAltEntity1CollisionMap:: @ 0x08257390
	.incbin "baserom.gba", 0x257390, 0x2880

gWhiscashCollisionMap:: @ 0x08259C10
	.incbin "baserom.gba", 0x259C10, 0x3700


@ Evo Arrows. Named this way for comprehension in folder.
@ E/V/O arrows. Second digit is '0 Top/1 Mid/2 Bottom',
@ First digit is 'variant'.
gRubyEvo_EArrow_Top0:: @ 0x0825D310
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_0.4bpp"

gRubyEvo_EArrow_Top1:: @ 0x0825D370
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_0.4bpp"

gRubyEvo_EArrow_Top2:: @ 0x0825D3D0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_0.4bpp"

gRubyEvo_VArrow_Top0:: @ 0x0825D430
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_0.4bpp"

gRubyEvo_VArrow_Top1:: @ 0x0825D490
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_0.4bpp"

gRubyEvo_VArrow_Top2:: @ 0x0825D4F0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_0.4bpp"

gRubyEvo_VArrow_Top3:: @ 0x0825D550
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_0.4bpp"

gRubyEvo_OArrow_Top0:: @ 0x0825D5B0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_0.4bpp"

gRubyEvo_OArrow_Top1:: @ 0x0825D610
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_0.4bpp"

gRubyEvo_OArrow_Top2:: @ 0x0825D670
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_0.4bpp"
	.space 0x40

gRubyEvo_EArrow_Mid0:: @ 0x0825D710
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_1.4bpp"

gRubyEvo_EArrow_Mid1:: @ 0x0825D770
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_1.4bpp"

gRubyEvo_EArrow_Mid2:: @ 0x0825D7D0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_1.4bpp"

gRubyEvo_VArrow_Mid0:: @ 0x0825D830
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_1.4bpp"

gRubyEvo_VArrow_Mid1:: @ 0x0825D890
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_1.4bpp"

gRubyEvo_VArrow_Mid2:: @ 0x0825D8F0
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_1.4bpp"

gRubyEvo_VArrow_Mid3:: @ 0x0825D950
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_1.4bpp"

gRubyEvo_OArrow_Mid0:: @ 0x0825D9B0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_1.4bpp"

gRubyEvo_OArrow_Mid1:: @ 0x0825DA10
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_1.4bpp"

gRubyEvo_OArrow_Mid2:: @ 0x0825DA70
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_1.4bpp"
	.space 0x40

gRubyEvo_EArrow_Bot0:: @ 0x0825DB10
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_2.4bpp"

gRubyEvo_EArrow_Bot1:: @ 0x0825DB70
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_2.4bpp"

gRubyEvo_EArrow_Bot2:: @ 0x0825DBD0
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_2.4bpp"

gRubyEvo_VArrow_Bot0:: @ 0x0825DC30
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_2.4bpp"

gRubyEvo_VArrow_Bot1:: @ 0x0825DC90
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_2.4bpp"

gRubyEvo_VArrow_Bot2:: @ 0x0825DCF0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_2.4bpp"

gRubyEvo_VArrow_Bot3:: @ 0x0825DD50
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_2.4bpp"

gRubyEvo_OArrow_Bot0:: @ 0x0825DDB0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_2.4bpp"

gRubyEvo_OArrow_Bot1:: @ 0x0825DE10
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_2.4bpp"

gRubyEvo_OArrow_Bot2:: @ 0x0825DE70
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_2.4bpp"
	.space 0x40


@ Coin Arrows

gRubyCoinArrow_0825DF10:: @ 0x0825DF10
	@.incbin "graphics/stage/ruby/ruby_coin_arrows.4bpp"

    .incbin "baserom.gba", 0x25DF10, 0x60

gRubyCoinArrow_0825DF70:: @ 0x0825DF70
    .incbin "baserom.gba", 0x25DF70, 0x60

gRubyCoinArrow_0825DFD0:: @ 0x0825DFD0
    .incbin "baserom.gba", 0x25DFD0, 0x60

gRubyCoinArrow_0825E030:: @ 0x0825E030
    .incbin "baserom.gba", 0x25E030, 0x60

gRubyCoinArrow_0825E090:: @ 0x0825E090
    .incbin "baserom.gba", 0x25E090, 0x60

gRubyCoinArrow_0825E0F0:: @ 0x0825E0F0
    .incbin "baserom.gba", 0x25E0F0, 0x60

gRubyCoinArrow_0825E150:: @ 0x0825E150
    .incbin "baserom.gba", 0x25E150, 0x60

gRubyCoinArrow_0825E1B0:: @ 0x0825E1B0
    .incbin "baserom.gba", 0x25E1B0, 0x60

gRubyCoinArrow_0825E210:: @ 0x0825E210
    .incbin "baserom.gba", 0x25E210, 0x60

gRubyCoinArrow_0825E270:: @ 0x0825E270
    .incbin "baserom.gba", 0x25E270, 0xA0

gRubyCoinArrow_0825E310:: @ 0x0825E310
    .incbin "baserom.gba", 0x25E310, 0x60

gRubyCoinArrow_0825E370:: @ 0x0825E370
    .incbin "baserom.gba", 0x25E370, 0x60

gRubyCoinArrow_0825E3D0:: @ 0x0825E3D0
    .incbin "baserom.gba", 0x25E3D0, 0x60

gRubyCoinArrow_0825E430:: @ 0x0825E430
    .incbin "baserom.gba", 0x25E430, 0x60

gRubyCoinArrow_0825E490:: @ 0x0825E490
    .incbin "baserom.gba", 0x25E490, 0x60

gRubyCoinArrow_0825E4F0:: @ 0x0825E4F0
    .incbin "baserom.gba", 0x25E4F0, 0x60

gRubyCoinArrow_0825E550:: @ 0x0825E550
    .incbin "baserom.gba", 0x25E550, 0x60

gRubyCoinArrow_0825E5B0:: @ 0x0825E5B0
    .incbin "baserom.gba", 0x25E5B0, 0x60

gRubyCoinArrow_0825E610:: @ 0x0825E610
    .incbin "baserom.gba", 0x25E610, 0x60

gRubyCoinArrow_0825E670:: @ 0x0825E670
    .incbin "baserom.gba", 0x25E670, 0xA0

gRubyCoinArrow_0825E710:: @ 0x0825E710
    .incbin "baserom.gba", 0x25E710, 0x60

gRubyCoinArrow_0825E770:: @ 0x0825E770
    .incbin "baserom.gba", 0x25E770, 0x60

gRubyCoinArrow_0825E7D0:: @ 0x0825E7D0
    .incbin "baserom.gba", 0x25E7D0, 0x60

gRubyCoinArrow_0825E830:: @ 0x0825E830
    .incbin "baserom.gba", 0x25E830, 0x60

gRubyCoinArrow_0825E890:: @ 0x0825E890
    .incbin "baserom.gba", 0x25E890, 0x60

gRubyCoinArrow_0825E8F0:: @ 0x0825E8F0
    .incbin "baserom.gba", 0x25E8F0, 0x60

gRubyCoinArrow_0825E950:: @ 0x0825E950
    .incbin "baserom.gba", 0x25E950, 0x60

gRubyCoinArrow_0825E9B0:: @ 0x0825E9B0
    .incbin "baserom.gba", 0x25E9B0, 0x60

gRubyCoinArrow_0825EA10:: @ 0x0825EA10
    .incbin "baserom.gba", 0x25EA10, 0x60

gRubyCoinArrow_0825EA70:: @ 0x0825EA70
    .incbin "baserom.gba", 0x25EA70, 0xA0


@ Get Arrows

gRubyGetArrow_0825EB10:: @ 0x0825EB10
    .incbin "baserom.gba", 0x25EB10, 0x60

gRubyGetArrow_0825EB70:: @ 0x0825EB70
    .incbin "baserom.gba", 0x25EB70, 0x60

gRubyGetArrow_0825EBD0:: @ 0x0825EBD0
    .incbin "baserom.gba", 0x25EBD0, 0x80

gRubyGetArrow_0825EC50:: @ 0x0825EC50
    .incbin "baserom.gba", 0x25EC50, 0x60

gRubyGetArrow_0825ECB0:: @ 0x0825ECB0
    .incbin "baserom.gba", 0x25ECB0, 0x60

gRubyGetArrow_0825ED10:: @ 0x0825ED10
    .incbin "baserom.gba", 0x25ED10, 0x60

gRubyGetArrow_0825ED70:: @ 0x0825ED70
    .incbin "baserom.gba", 0x25ED70, 0x60

gRubyGetArrow_0825EDD0:: @ 0x0825EDD0
    .incbin "baserom.gba", 0x25EDD0, 0x60

gRubyGetArrow_0825EE30:: @ 0x0825EE30
    .incbin "baserom.gba", 0x25EE30, 0x60

gRubyGetArrow_0825EE90:: @ 0x0825EE90
    .incbin "baserom.gba", 0x25EE90, 0x80

gRubyGetArrow_0825EF10:: @ 0x0825EF10
    .incbin "baserom.gba", 0x25EF10, 0x60

gRubyGetArrow_0825EF70:: @ 0x0825EF70
    .incbin "baserom.gba", 0x25EF70, 0x60

gRubyGetArrow_0825EFD0:: @ 0x0825EFD0
    .incbin "baserom.gba", 0x25EFD0, 0x80

gRubyGetArrow_0825F050:: @ 0x0825F050
    .incbin "baserom.gba", 0x25F050, 0x60

gRubyGetArrow_0825F0B0:: @ 0x0825F0B0
    .incbin "baserom.gba", 0x25F0B0, 0x60

gRubyGetArrow_0825F110:: @ 0x0825F110
    .incbin "baserom.gba", 0x25F110, 0x60

gRubyGetArrow_0825F170:: @ 0x0825F170
    .incbin "baserom.gba", 0x25F170, 0x40

gRubyGetArrow_0825F1B0:: @ 0x0825F1B0
    .incbin "baserom.gba", 0x25F1B0, 0x60

gRubyGetArrow_0825F210:: @ 0x0825F210
    .incbin "baserom.gba", 0x25F210, 0x60

gRubyGetArrow_0825F270:: @ 0x0825F270
    .incbin "baserom.gba", 0x25F270, 0xA0

gRubyGetArrow_0825F310:: @ 0x0825F310
    .incbin "baserom.gba", 0x25F310, 0x60

gRubyGetArrow_0825F370:: @ 0x0825F370
    .incbin "baserom.gba", 0x25F370, 0x60

gRubyGetArrow_0825F3D0:: @ 0x0825F3D0
    .incbin "baserom.gba", 0x25F3D0, 0x60

gRubyGetArrow_0825F430:: @ 0x0825F430
    .incbin "baserom.gba", 0x25F430, 0x60

gRubyGetArrow_0825F490:: @ 0x0825F490
    .incbin "baserom.gba", 0x25F490, 0x60

gRubyGetArrow_0825F4F0:: @ 0x0825F4F0
    .incbin "baserom.gba", 0x25F4F0, 0x60

gRubyGetArrow_0825F550:: @ 0x0825F550
    .incbin "baserom.gba", 0x25F550, 0x60

gRubyGetArrow_0825F5B0:: @ 0x0825F5B0
    .incbin "baserom.gba", 0x25F5B0, 0x60

gRubyGetArrow_0825F610:: @ 0x0825F610
    .incbin "baserom.gba", 0x25F610, 0x60

gRubyGetArrow_0825F670:: @ 0x0825F670
    .incbin "baserom.gba", 0x25F670, 0xC0


@ Ball power up lights

gRubyBallPowerUpLight0off:: @ 0x0825F730
	.incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_0_off.4bpp"

gRubyBallPowerUpLight0on:: @ 0x0825F770
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_0_on.4bpp"

gRubyBallPowerUpLight1off:: @ 0x0825F7B0
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_1_off.4bpp"

gRubyBallPowerUpLight1on:: @ 0x0825F7F0
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_1_on.4bpp"

gRubyBallPowerUpLight2off:: @ 0x0825F830
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_2_off.4bpp"

gRubyBallPowerUpLight2on:: @ 0x0825F870
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_2_on.4bpp"


@ 'H' 'o' 'l' 'e' Lights

gRubyHoleLightH_Off:: @ 0x0825F8B0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_off.4bpp"

gRubyHoleLightH_On:: @ 0x0825F8F0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_on.4bpp"

gRubyHoleLightO_Off:: @ 0x0825F930
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_off.4bpp"

gRubyHoleLightO_On:: @ 0x0825F970
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_on.4bpp"

gRubyHoleLightL_Off:: @ 0x0825F9B0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_off.4bpp"

gRubyHoleLightL_On:: @ 0x0825F9F0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_on.4bpp"

gRubyHoleLightE_Off:: @ 0x0825FA30
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_off.4bpp"

gRubyHoleLightE_On:: @ 0x0825FA70
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_on.4bpp"



@ Catch light arrows : 3 balls / CATCH! / EVO

gRubyCatchLight_0825FAB0:: @ 0x0825FAB0
    .incbin "baserom.gba", 0x25FAB0, 0x40

gRubyCatchLight_0825FAF0:: @ 0x0825FAF0
    .incbin "baserom.gba", 0x25FAF0, 0x40
    .space 0x380

gRubyCatchLight_0825FEB0:: @ 0x0825FEB0
    .incbin "baserom.gba", 0x25FEB0, 0x40

gRubyCatchLight_0825FEF0:: @ 0x0825FEF0
    .incbin "baserom.gba", 0x25FEF0, 0x40

gRubyTrapTile_0825FF30:: @ 0x0825FF30
    .incbin "baserom.gba", 0x25FF30, 0x40

gRubyTrapTile_0825FF70:: @ 0x0825FF70
    .incbin "baserom.gba", 0x25FF70, 0x40

gRubyTrapTile_0825FFB0:: @ 0x0825FFB0
    .incbin "baserom.gba", 0x25FFB0, 0x40

gRubyCatchLight_0825FFF0:: @ 0x0825FFF0
    .incbin "baserom.gba", 0x25FFF0, 0x40

gRubyCatchLight_08260030:: @ 0x08260030
    .incbin "baserom.gba", 0x260030, 0x40

gRubyCatchLight_08260070:: @ 0x08260070
    .incbin "baserom.gba", 0x260070, 0x40

gRubyCatchLight_082600B0:: @ 0x082600B0
    .incbin "baserom.gba", 0x2600B0, 0x40

gRubyCatchLight_082600F0:: @ 0x082600F0
    .incbin "baserom.gba", 0x2600F0, 0x40

gRubyCatchLight_08260130:: @ 0x08260130
    .incbin "baserom.gba", 0x260130, 0x40

gRubyCatchLight_08260170:: @ 0x08260170
    .incbin "baserom.gba", 0x260170, 0x40

gRubyCatchLight_082601B0:: @ 0x082601B0
    .incbin "baserom.gba", 0x2601B0, 0x40

gRubyCatchLight_082601F0:: @ 0x082601F0
    .incbin "baserom.gba", 0x2601F0, 0x40

gRubyCatchLight_08260230:: @ 0x08260230
    .incbin "baserom.gba", 0x260230, 0x40

gRubyCatchLight_08260270:: @ 0x08260270
    .incbin "baserom.gba", 0x260270, 0x40

gRubyCatchLight_082602B0:: @ 0x082602B0
    .incbin "baserom.gba", 0x2602B0, 0x80

gRubyTrapTile_08260330:: @ 0x08260330
    .incbin "baserom.gba", 0x260330, 0x40

gRubyTrapTile_08260370:: @ 0x08260370
    .incbin "baserom.gba", 0x260370, 0x40

gRubyTrapTile_082603B0:: @ 0x082603B0
    .incbin "baserom.gba", 0x2603B0, 0x40

gRubyCatchLight_082603F0:: @ 0x082603F0
    .incbin "baserom.gba", 0x2603F0, 0x40

gRubyCatchLight_08260430:: @ 0x08260430
    .incbin "baserom.gba", 0x260430, 0x40

gRubyCatchLight_08260470:: @ 0x08260470
    .incbin "baserom.gba", 0x260470, 0x40

gRubyCatchLight_082604B0:: @ 0x082604B0
    .incbin "baserom.gba", 0x2604B0, 0x40

gRubyCatchLight_082604F0:: @ 0x082604F0
    .incbin "baserom.gba", 0x2604F0, 0x40

gRubyCatchLight_08260530:: @ 0x08260530
    .incbin "baserom.gba", 0x260530, 0x40

gRubyCatchLight_08260570:: @ 0x08260570
    .incbin "baserom.gba", 0x260570, 0x40

gRubyCatchLight_082605B0:: @ 0x082605B0
    .incbin "baserom.gba", 0x2605B0, 0x40

gRubyCatchLight_082605F0:: @ 0x082605F0
    .incbin "baserom.gba", 0x2605F0, 0x40

gRubyCatchLight_08260630:: @ 0x08260630
    .incbin "baserom.gba", 0x260630, 0x40

gRubyCatchLight_08260670:: @ 0x08260670
    .incbin "baserom.gba", 0x260670, 0x40

gRubyCatchLight_082606B0:: @ 0x082606B0
    .incbin "baserom.gba", 0x2606B0, 0xC0


@ Ruby Saver indicator

gRubySaverRow0Tile_Off:: @ 0x08260770
    .incbin "baserom.gba", 0x260770, 0x100

gRubySaverRow0Tile_On:: @ 0x08260870
    .incbin "baserom.gba", 0x260870, 0x300

gRubySaverRow1Tile_Off:: @ 0x08260B70
    .incbin "baserom.gba", 0x260B70, 0x100

gRubySaverRow1Tile_On:: @ 0x08260C70
    .incbin "baserom.gba", 0x260C70, 0x320

gRubySaverRow2Tile_Off:: @ 0x08260F90
    .incbin "baserom.gba", 0x260F90, 0x100

gRubySaverRow2Tile_On:: @ 0x08261090
    .incbin "baserom.gba", 0x261090, 0x360

gRubySaverRow3Tile_Off:: @ 0x082613F0
    .incbin "baserom.gba", 0x2613F0, 0x100

gRubySaverRow3Tile_On:: @ 0x082614F0
    .incbin "baserom.gba", 0x2614F0, 0x280

gRubyHatchArrowRow0Tile_Off:: @ 0x08261770
    .incbin "baserom.gba", 0x261770, 0x80

gRubyHatchArrowRow0Tile_On:: @ 0x082617F0
    .incbin "baserom.gba", 0x2617F0, 0xC0

gRubyCatchArrowRow0Tile_Off:: @ 0x082618B0
    .incbin "baserom.gba", 0x2618B0, 0x80

gRubyCatchArrowRow0Tile_On:: @ 0x08261930
    .incbin "baserom.gba", 0x261930, 0x80

gRubyBumperArrowRow0Tile_Off:: @ 0x082619B0
    .incbin "baserom.gba", 0x2619B0, 0x80

gRubyBumperArrowRow0Tile_On:: @ 0x08261A30
    .incbin "baserom.gba", 0x261A30, 0x140

gRubyHatchArrowRow1Tile_Off:: @ 0x08261B70
    .incbin "baserom.gba", 0x261B70, 0x80

gRubyHatchArrowRow1Tile_On:: @ 0x08261BF0
    .incbin "baserom.gba", 0x261BF0, 0x80

gRubyCatchArrowRow1Tile_Off:: @ 0x08261C70
    .incbin "baserom.gba", 0x261C70, 0x80

gRubyCatchArrowRow1Tile_On:: @ 0x08261CF0
    .incbin "baserom.gba", 0x261CF0, 0x80

gRubyBumperArrowRow1Tile_Off:: @ 0x08261D70
    .incbin "baserom.gba", 0x261D70, 0x80

gRubyBumperArrowRow1Tile_On:: @ 0x08261DF0
    .incbin "baserom.gba", 0x261DF0, 0x180

gRubyHatchArrowRow2Tile_Off:: @ 0x08261F70
    .incbin "baserom.gba", 0x261F70, 0x80

gRubyHatchArrowRow2Tile_On:: @ 0x08261FF0
    .incbin "baserom.gba", 0x261FF0, 0x80

gRubyCatchArrowRow2Tile_Off:: @ 0x08262070
    .incbin "baserom.gba", 0x262070, 0x80

gRubyCatchArrowRow2Tile_On:: @ 0x082620F0
    .incbin "baserom.gba", 0x2620F0, 0x80

gRubyBumperArrowRow2Tile_Off:: @ 0x08262170
    .incbin "baserom.gba", 0x262170, 0x80

gRubyBumperArrowRow2Tile_On:: @ 0x082621F0
    .incbin "baserom.gba", 0x2621F0, 0x180

gRubyHatchArrowRow3Tile_Off:: @ 0x08262370
    .incbin "baserom.gba", 0x262370, 0x80

gRubyHatchArrowRow3Tile_On:: @ 0x082623F0
    .incbin "baserom.gba", 0x2623F0, 0x80

gRubyCatchArrowRow3Tile_Off:: @ 0x08262470
    .incbin "baserom.gba", 0x262470, 0x80

gRubyCatchArrowRow3Tile_On:: @ 0x082624F0
    .incbin "baserom.gba", 0x2624F0, 0x80

gRubyBumperArrowRow3Tile_Off:: @ 0x08262570
    .incbin "baserom.gba", 0x262570, 0x80

gRubyBumperArrowRow3Tile_On:: @ 0x082625F0
    .incbin "baserom.gba", 0x2625F0, 0x1A0


@ Sign for bonus multiplier left/right digits

gRubyBonusMultDigit_08262790:: @ 0x08262790
    .incbin "baserom.gba", 0x262790, 0x20

gRubyBonusMultDigit_082627B0:: @ 0x082627B0
    .incbin "baserom.gba", 0x2627B0, 0x20

gRubyBonusMultDigit_082627D0:: @ 0x082627D0
    .incbin "baserom.gba", 0x2627D0, 0x20

gRubyBonusMultDigit_082627F0:: @ 0x082627F0
    .incbin "baserom.gba", 0x2627F0, 0x20

gRubyBonusMultDigit_08262810:: @ 0x08262810
    .incbin "baserom.gba", 0x262810, 0x20

gRubyBonusMultDigit_08262830:: @ 0x08262830
    .incbin "baserom.gba", 0x262830, 0x20

gRubyBonusMultDigit_08262850:: @ 0x08262850
    .incbin "baserom.gba", 0x262850, 0x20

gRubyBonusMultDigit_08262870:: @ 0x08262870
    .incbin "baserom.gba", 0x262870, 0x20

gRubyBonusMultDigit_08262890:: @ 0x08262890
    .incbin "baserom.gba", 0x262890, 0x20

gRubyBonusMultDigit_082628B0:: @ 0x082628B0
    .incbin "baserom.gba", 0x2628B0, 0x20

gRubyBonusMultDigit_082628D0:: @ 0x082628D0
    .incbin "baserom.gba", 0x2628D0, 0x20

gRubyBonusMultDigit_082628F0:: @ 0x082628F0
    .incbin "baserom.gba", 0x2628F0, 0x20

gRubyBonusMultDigit_08262910:: @ 0x08262910
    .incbin "baserom.gba", 0x262910, 0x20

gRubyBonusMultDigit_08262930:: @ 0x08262930
    .incbin "baserom.gba", 0x262930, 0x20

gRubyBonusMultDigit_08262950:: @ 0x08262950
    .incbin "baserom.gba", 0x262950, 0x20

gRubyBonusMultDigit_08262970:: @ 0x08262970
    .incbin "baserom.gba", 0x262970, 0x20

gRubyBonusMultDigit_08262990:: @ 0x08262990
    .incbin "baserom.gba", 0x262990, 0x20

gRubyBonusMultDigit_082629B0:: @ 0x082629B0
    .incbin "baserom.gba", 0x2629B0, 0x20

gRubyBonusMultDigit_082629D0:: @ 0x082629D0
    .incbin "baserom.gba", 0x2629D0, 0x20

gRubyBonusMultDigit_082629F0:: @ 0x082629F0
    .incbin "baserom.gba", 0x2629F0, 0x20

.space 0x1A0


@ Text for sign over Ruby shop entrance

gStoreSignText_08262BB0:: @ 0x08262BB0
    .incbin "baserom.gba", 0x262BB0, 0xC0

gStoreSignText_08262C70:: @ 0x08262C70
    .incbin "baserom.gba", 0x262C70, 0xC0
	.space 0x280

gStoreSignText_08262FB0:: @ 0x08262FB0
    .incbin "baserom.gba", 0x262FB0, 0xC0

gStoreSignText_08263070:: @ 0x08263070
    .incbin "baserom.gba", 0x263070, 0xC0
	.space 0x300

gStoreSignText_08263430:: @ 0x08263430
    .incbin "baserom.gba", 0x263430, 0x20
	.space 0xA0

gStoreSignText_082634F0:: @ 0x082634F0
    .incbin "baserom.gba", 0x2634F0, 0x20
	.space 0x2C0



@ arrow for ramp leading to shop: mart/evo

gRubyEvoArrow_R0_Off:: @ 0x082637D0
    .incbin "baserom.gba", 0x2637D0, 0xA0

gRubyEvoArrow_R0_On:: @ 0x08263870
    .incbin "baserom.gba", 0x263870, 0xA0

gRubyMartArrow_R0_Off:: @ 0x08263910
    .incbin "baserom.gba", 0x263910, 0xA0

gRubyMartArrow_R0_On:: @ 0x082639B0
    .incbin "baserom.gba", 0x2639B0, 0xA0
	.space 0x180

gRubyEvoArrow_R1_Off:: @ 0x08263BD0
    .incbin "baserom.gba", 0x263BD0, 0xA0

gRubyEvoArrow_R1_On:: @ 0x08263C70
    .incbin "baserom.gba", 0x263C70, 0xA0

gRubyMartArrow_R1_Off:: @ 0x08263D10
    .incbin "baserom.gba", 0x263D10, 0xA0

gRubyMartArrow_R1_On:: @ 0x08263DB0
    .incbin "baserom.gba", 0x263DB0, 0xA0
	.space 0x180

gRubyEvoArrow_R2_Off:: @ 0x08263FD0
    .incbin "baserom.gba", 0x263FD0, 0xA0

gRubyEvoArrow_R2_On:: @ 0x08264070
    .incbin "baserom.gba", 0x264070, 0xA0

gRubyMartArrow_R2_Off:: @ 0x08264110
    .incbin "baserom.gba", 0x264110, 0xA0

gRubyMartArrow_R2_On:: @ 0x082641B0
    .incbin "baserom.gba", 0x2641B0, 0xA0
	.space 0x180

gRubyEvoArrow_R3_Off:: @ 0x082643D0
    .incbin "baserom.gba", 0x2643D0, 0xA0

gRubyEvoArrow_R3_On:: @ 0x08264470
    .incbin "baserom.gba", 0x264470, 0xA0

gRubyMartArrow_R3_Off:: @ 0x08264510
    .incbin "baserom.gba", 0x264510, 0xA0

gRubyMartArrow_R3_On:: @ 0x082645B0
    .incbin "baserom.gba", 0x2645B0, 0xA0
	.space 0x1A0



@ Slingshot wedge lights

gRuby_LSlingshot_Off_R0:: @ 0x082647F0
    .incbin "baserom.gba", 0x2647F0, 0x60

gRuby_LSlingshot_On_R0:: @ 0x08264850
    .incbin "baserom.gba", 0x264850, 0xA0

gRuby_RSlingshot_Off_R0:: @ 0x082648F0
    .incbin "baserom.gba", 0x2648F0, 0x60

gRuby_RSlingshot_On_R0:: @ 0x08264950
    .incbin "baserom.gba", 0x264950, 0x2A0

gRuby_LSlingshot_Off_R1:: @ 0x08264BF0
    .incbin "baserom.gba", 0x264BF0, 0x60

gRuby_LSlingshot_On_R1:: @ 0x08264C50
    .incbin "baserom.gba", 0x264C50, 0x80

gRuby_RSlingshot_Off_R1:: @ 0x08264CD0
    .incbin "baserom.gba", 0x264CD0, 0x60

gRuby_RSlingshot_On_R1:: @ 0x08264D30
    .incbin "baserom.gba", 0x264D30, 0x2C0

gRuby_LSlingshot_Off_R2:: @ 0x08264FF0
    .incbin "baserom.gba", 0x264FF0, 0x60

gRuby_LSlingshot_On_R2:: @ 0x08265050
    .incbin "baserom.gba", 0x265050, 0x60

gRuby_RSlingshot_Off_R2:: @ 0x082650B0
    .incbin "baserom.gba", 0x2650B0, 0x60

gRuby_RSlingshot_On_R2:: @ 0x08265110
    .incbin "baserom.gba", 0x265110, 0x2E0

gRuby_LSlingshot_Off_R3:: @ 0x082653F0
    .incbin "baserom.gba", 0x2653F0, 0x60

gRuby_LSlingshot_On_R3:: @ 0x08265450
    .incbin "baserom.gba", 0x265450, 0x60

gRuby_RSlingshot_Off_R3:: @ 0x082654B0
    .incbin "baserom.gba", 0x2654B0, 0x60

gRuby_RSlingshot_On_R3:: @ 0x08265510
    .incbin "baserom.gba", 0x265510, 0x300

gRuby_LSlingshot_Off_R4:: @ 0x08265810
    .incbin "baserom.gba", 0x265810, 0x60

gRuby_LSlingshot_On_R4:: @ 0x08265870
    .incbin "baserom.gba", 0x265870, 0x40

gRuby_RSlingshot_Off_R4:: @ 0x082658B0
    .incbin "baserom.gba", 0x2658B0, 0x60

gRuby_RSlingshot_On_R4:: @ 0x08265910
    .incbin "baserom.gba", 0x265910, 0x300



gRubyBoardBGTiles:: @ 0x08265C10
	.incbin "baserom.gba", 0x265C10, 0x8000

gRubyBoardBGTilemap:: @ 0x0826DC10
	.incbin "baserom.gba", 0x26DC10, 0x1000
