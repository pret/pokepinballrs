@ Note: file has a shared 'bumper collision map' at 0x08252B10
@ All other entries in this file are ruby board specific

gRubyBoardBG0Tilemap:: @ 0x081C08E4
	.incbin "graphics/stage/ruby/ruby_board_bg0_tilemap.bin"

gRubyBoardCollisionTileDataLayer0:: @ 0x081C18E4
    .incbin "data/board_data/collision/ruby/boardtop_launch_tiledata.bin"

gRubyBoardCollisionAngleDataLayer0:: @ 0x081C38E4
    .incbin "data/board_data/collision/ruby/boardtop_launch_angledata.bin"

gRubyBoardCollisionTypeDataLayer0:: @ 0x081DC064
    .incbin "data/board_data/collision/ruby/boardtop_launch_typedata.bin"

gRubyBoardCollisionTileDataLayer0Alt:: @ 0x081E8424
    .incbin "data/board_data/collision/ruby/boardtop_normal_tiledata.bin"

gRubyBoardCollisionAngleDataLayer0Alt:: @ 0x081EA424
    .incbin "data/board_data/collision/ruby/boardtop_normal_angledata.bin"

gRubyBoardCollisionTypeDataLayer0Alt:: @ 0x082027A4
    .incbin "data/board_data/collision/ruby/boardtop_normal_typedata.bin"

gRubyBoardCollisionTileDataLayer1:: @ 0x0820E964
    .incbin "data/board_data/collision/ruby/boardbottom_tiledata.bin"

gRubyBoardCollisionAngleDataLayer1:: @ 0x08210964
    .incbin "data/board_data/collision/ruby/boardbottom_angledata.bin"

gRubyBoardCollisionTypeDataLayer1:: @ 0x082245E4
    .incbin "data/board_data/collision/ruby/boardbottom_typedata.bin"

gRubyBoardBG1Tilemap:: @ 0x0822E424
	.incbin "graphics/stage/ruby/ruby_board_ramp_tilemap.bin"

gRubyBoardCollisionTileDataLayer2:: @ 0x0822F424
    .incbin "data/board_data/collision/ruby/topramps_tiledata.bin"

gRubyBoardCollisionAngleDataLayer2:: @ 0x08231424
    .incbin "data/board_data/collision/ruby/topramps_angledata.bin"

gRubyBoardCollisionTypeDataLayer2:: @ 0x082432A4
    .incbin "data/board_data/collision/ruby/topramps_typedata.bin"

gRubyBoardCompressedTiles1:: @ 0x0824C1E4
	.incbin "graphics/stage/ruby/ruby_board_bgramp_tiles.4bpp.lz"

gRubyBoardCompressedTiles2:: @ 0x0824DD60
	.incbin "graphics/stage/ruby/ruby_board_bgtop_tiles.4bpp.lz"

gRubyBoardCompressedBGTileBuffer:: @ 0x08250934
	.incbin "graphics/stage/ruby/ruby_board_bgbottom_tiles.4bpp.lz"

gSharedBumperCollisionMap:: @ 0x08252B10
	.incbin "data/board_data/collision/ruby/shared_bumper_entity_collision_64x64.bin"

gRubyLinooneLeftCollisionMap:: @ 0x08254B10
    .incbin "data/board_data/collision/ruby/linoone_left_collision_map_72x72.bin"

gRubyLinooneRightCollisionMap:: @ 0x08257390
    .incbin "data/board_data/collision/ruby/linoone_right_collision_map_72x72.bin"

gWhiscashCollisionMap:: @ 0x08259C10
	.incbin "data/board_data/collision/ruby/whiscash_entity_collision_80x88.bin"


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

    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p0.4bpp"

gRubyCoinArrow_0825DF70:: @ 0x0825DF70
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p0.4bpp"

gRubyCoinArrow_0825DFD0:: @ 0x0825DFD0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p0.4bpp"

gRubyCoinArrow_0825E030:: @ 0x0825E030
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p0.4bpp"

gRubyCoinArrow_0825E090:: @ 0x0825E090
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p0.4bpp"

gRubyCoinArrow_0825E0F0:: @ 0x0825E0F0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p0.4bpp"

gRubyCoinArrow_0825E150:: @ 0x0825E150
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p0.4bpp"

gRubyCoinArrow_0825E1B0:: @ 0x0825E1B0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p0.4bpp"

gRubyCoinArrow_0825E210:: @ 0x0825E210
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p0.4bpp"

gRubyCoinArrow_0825E270:: @ 0x0825E270
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p0.4bpp"
    .space 0x40

gRubyCoinArrow_0825E310:: @ 0x0825E310
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p1.4bpp"

gRubyCoinArrow_0825E370:: @ 0x0825E370
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p1.4bpp"

gRubyCoinArrow_0825E3D0:: @ 0x0825E3D0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p1.4bpp"

gRubyCoinArrow_0825E430:: @ 0x0825E430
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p1.4bpp"

gRubyCoinArrow_0825E490:: @ 0x0825E490
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p1.4bpp"

gRubyCoinArrow_0825E4F0:: @ 0x0825E4F0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p1.4bpp"

gRubyCoinArrow_0825E550:: @ 0x0825E550
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p1.4bpp"

gRubyCoinArrow_0825E5B0:: @ 0x0825E5B0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p1.4bpp"

gRubyCoinArrow_0825E610:: @ 0x0825E610
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p1.4bpp"

gRubyCoinArrow_0825E670:: @ 0x0825E670
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p1.4bpp"
    .space 0x40

gRubyCoinArrow_0825E710:: @ 0x0825E710
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p2.4bpp"

gRubyCoinArrow_0825E770:: @ 0x0825E770
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p2.4bpp"

gRubyCoinArrow_0825E7D0:: @ 0x0825E7D0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p2.4bpp"

gRubyCoinArrow_0825E830:: @ 0x0825E830
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p2.4bpp"

gRubyCoinArrow_0825E890:: @ 0x0825E890
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p2.4bpp"

gRubyCoinArrow_0825E8F0:: @ 0x0825E8F0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p2.4bpp"

gRubyCoinArrow_0825E950:: @ 0x0825E950
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p2.4bpp"

gRubyCoinArrow_0825E9B0:: @ 0x0825E9B0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p2.4bpp"

gRubyCoinArrow_0825EA10:: @ 0x0825EA10
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p2.4bpp"

gRubyCoinArrow_0825EA70:: @ 0x0825EA70
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p2.4bpp"
    .space 0x40


@ Get Arrows

gRubyGetArrow_0825EB10:: @ 0x0825EB10
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_0.4bpp"

gRubyGetArrow_0825EB70:: @ 0x0825EB70
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_0.4bpp"

gRubyGetArrow_0825EBD0:: @ 0x0825EBD0
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_0.4bpp"
    .space 0x20

gRubyGetArrow_0825EC50:: @ 0x0825EC50
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_0.4bpp"
    .space 0x20

gRubyGetArrow_0825ECB0:: @ 0x0825ECB0
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_0.4bpp"
    .space 0x20

gRubyGetArrow_0825ED10:: @ 0x0825ED10
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_0.4bpp"
    .space 0x20

gRubyGetArrow_0825ED70:: @ 0x0825ED70
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_0.4bpp"
    .space 0x20

gRubyGetArrow_0825EDD0:: @ 0x0825EDD0
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_0.4bpp"
    .space 0x20

gRubyGetArrow_0825EE30:: @ 0x0825EE30
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_0.4bpp"
    .space 0x20

gRubyGetArrow_0825EE90:: @ 0x0825EE90
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_0.4bpp"
    .space 0x40

gRubyGetArrow_0825EF10:: @ 0x0825EF10
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_1.4bpp"

gRubyGetArrow_0825EF70:: @ 0x0825EF70
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_1.4bpp"

gRubyGetArrow_0825EFD0:: @ 0x0825EFD0
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_1.4bpp"
    .space 0x20

gRubyGetArrow_0825F050:: @ 0x0825F050
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_1.4bpp"
    .space 0x20

gRubyGetArrow_0825F0B0:: @ 0x0825F0B0
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_1.4bpp"
    .space 0x20

gRubyGetArrow_0825F110:: @ 0x0825F110
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_1.4bpp"
    .space 0x20

gRubyGetArrow_0825F170:: @ 0x0825F170
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_1.4bpp"

gRubyGetArrow_0825F1B0:: @ 0x0825F1B0
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_1.4bpp"

gRubyGetArrow_0825F210:: @ 0x0825F210
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_1.4bpp"

gRubyGetArrow_0825F270:: @ 0x0825F270
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_1.4bpp"
    .space 0x40

gRubyGetArrow_0825F310:: @ 0x0825F310
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_2.4bpp"

gRubyGetArrow_0825F370:: @ 0x0825F370
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_2.4bpp"

gRubyGetArrow_0825F3D0:: @ 0x0825F3D0
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_2.4bpp"

gRubyGetArrow_0825F430:: @ 0x0825F430
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_2.4bpp"

gRubyGetArrow_0825F490:: @ 0x0825F490
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_2.4bpp"

gRubyGetArrow_0825F4F0:: @ 0x0825F4F0
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_2.4bpp"

gRubyGetArrow_0825F550:: @ 0x0825F550
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_2.4bpp"

gRubyGetArrow_0825F5B0:: @ 0x0825F5B0
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_2.4bpp"

gRubyGetArrow_0825F610:: @ 0x0825F610
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_2.4bpp"

gRubyGetArrow_0825F670:: @ 0x0825F670
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_2.4bpp"
	.space 0x40
	.fill 0x20, 1, 0x22


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

gRubyCatchLightState0Top:: @ 0x0825FAB0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state0_top.4bpp"

gRubyCatchLightState1Top:: @ 0x0825FAF0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state1_top.4bpp"
    .space 0x380

gRubyCatchLightState0Bot:: @ 0x0825FEB0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state0_bot.4bpp"

gRubyCatchLightState1Bot:: @ 0x0825FEF0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state1_bot.4bpp"

gRubyTrapIndicatorState0Top:: @ 0x0825FF30
    .incbin "graphics/stage/ruby/trap_indicator/trap_state0_top.4bpp"

gRubyTrapIndicatorState1Top:: @ 0x0825FF70
    .incbin "graphics/stage/ruby/trap_indicator/trap_state1_top.4bpp"

gRubyTrapIndicatorState2Top:: @ 0x0825FFB0
    .incbin "graphics/stage/ruby/trap_indicator/trap_state2_top.4bpp"

gRubyCatchLightSlot0State2Top:: @ 0x0825FFF0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_top.4bpp"

gRubyCatchLightSlot0State3Top:: @ 0x08260030
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_top.4bpp"

gRubyCatchLightSlot1State2Top:: @ 0x08260070
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_top.4bpp"

gRubyCatchLightSlot1State3Top:: @ 0x082600B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_top.4bpp"

gRubyCatchLightSlot2State2Top:: @ 0x082600F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_top.4bpp"

gRubyCatchLightSlot2State3Top:: @ 0x08260130
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_top.4bpp"

gRubyCatchLightSlot0State4Top:: @ 0x08260170
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_top.4bpp"

gRubyCatchLightSlot0State5Top:: @ 0x082601B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_top.4bpp"

gRubyCatchLightSlot1State4Top:: @ 0x082601F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_top.4bpp"

gRubyCatchLightSlot1State5Top:: @ 0x08260230
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_top.4bpp"

gRubyCatchLightSlot2State4Top:: @ 0x08260270
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_top.4bpp"

gRubyCatchLightSlot2State5Top:: @ 0x082602B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_top.4bpp"
	.space 0x40

gRubyTrapIndicatorState0Bot:: @ 0x08260330
    .incbin "graphics/stage/ruby/trap_indicator/trap_state0_bot.4bpp"

gRubyTrapIndicatorState1Bot:: @ 0x08260370
    .incbin "graphics/stage/ruby/trap_indicator/trap_state1_bot.4bpp"

gRubyTrapIndicatorState2Bot:: @ 0x082603B0
    .incbin "graphics/stage/ruby/trap_indicator/trap_state2_bot.4bpp"

gRubyCatchLightSlot0State2Bot:: @ 0x082603F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_bot.4bpp"

gRubyCatchLightSlot0State3Bot:: @ 0x08260430
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_bot.4bpp"

gRubyCatchLightSlot1State2Bot:: @ 0x08260470
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_bot.4bpp"

gRubyCatchLightSlot1State3Bot:: @ 0x082604B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_bot.4bpp"

gRubyCatchLightSlot2State2Bot:: @ 0x082604F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_bot.4bpp"

gRubyCatchLightSlot2State3Bot:: @ 0x08260530
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_bot.4bpp"

gRubyCatchLightSlot0State4Bot:: @ 0x08260570
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_bot.4bpp"

gRubyCatchLightSlot0State5Bot:: @ 0x082605B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_bot.4bpp"

gRubyCatchLightSlot1State4Bot:: @ 0x082605F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_bot.4bpp"

gRubyCatchLightSlot1State5Bot:: @ 0x08260630
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_bot.4bpp"

gRubyCatchLightSlot2State4Bot:: @ 0x08260670
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_bot.4bpp"

gRubyCatchLightSlot2State5Bot:: @ 0x082606B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot.4bpp"
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_filler.4bpp"


@ Ruby Saver indicator

gRubySaverRow0Tile_Off:: @ 0x08260770
    .incbin "graphics/stage/ruby/saver/saver_off_row0.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row0_filler.4bpp"

gRubySaverRow0Tile_On:: @ 0x08260870
    .incbin "graphics/stage/ruby/saver/saver_on_row0.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_on_row0_filler.4bpp"

gRubySaverRow1Tile_Off:: @ 0x08260B70
    .incbin "graphics/stage/ruby/saver/saver_off_row1.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row1_filler.4bpp"

gRubySaverRow1Tile_On:: @ 0x08260C70
    .incbin "graphics/stage/ruby/saver/saver_on_row1.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_on_row1_filler.4bpp"

gRubySaverRow2Tile_Off:: @ 0x08260F90
    .incbin "graphics/stage/ruby/saver/saver_off_row2.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row2_filler.4bpp"

gRubySaverRow2Tile_On:: @ 0x08261090
    .incbin "graphics/stage/ruby/saver/saver_on_row2.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x200
	.fill 0xA0, 1, 0x11

gRubySaverRow3Tile_Off:: @ 0x082613F0
    .incbin "graphics/stage/ruby/saver/saver_off_row3.4bpp"
	.fill 0xC0, 1, 0x11

gRubySaverRow3Tile_On:: @ 0x082614F0
    .incbin "graphics/stage/ruby/saver/saver_on_row3.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x220

gRubyHatchArrowRow0Tile_Off:: @ 0x08261770
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row0.4bpp"

gRubyHatchArrowRow0Tile_On:: @ 0x082617F0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0.4bpp"
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_filler.4bpp"

gRubyCatchArrowRow0Tile_Off:: @ 0x082618B0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0.4bpp"
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_filler.4bpp"

gRubyCatchArrowRow0Tile_On:: @ 0x08261930
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0.4bpp"
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_filler.4bpp"

gRubyBumperArrowRow0Tile_Off:: @ 0x082619B0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_filler.4bpp"

gRubyBumperArrowRow0Tile_On:: @ 0x08261A30
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row0.4bpp"
    .space 0x100

gRubyHatchArrowRow1Tile_Off:: @ 0x08261B70
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row1.4bpp"

gRubyHatchArrowRow1Tile_On:: @ 0x08261BF0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row1.4bpp"

gRubyCatchArrowRow1Tile_Off:: @ 0x08261C70
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row1.4bpp"

gRubyCatchArrowRow1Tile_On:: @ 0x08261CF0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row1.4bpp"

gRubyBumperArrowRow1Tile_Off:: @ 0x08261D70
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row1.4bpp"

gRubyBumperArrowRow1Tile_On:: @ 0x08261DF0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row1.4bpp"
    .space 0x100

gRubyHatchArrowRow2Tile_Off:: @ 0x08261F70
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row2.4bpp"

gRubyHatchArrowRow2Tile_On:: @ 0x08261FF0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row2.4bpp"

gRubyCatchArrowRow2Tile_Off:: @ 0x08262070
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row2.4bpp"

gRubyCatchArrowRow2Tile_On:: @ 0x082620F0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row2.4bpp"

gRubyBumperArrowRow2Tile_Off:: @ 0x08262170
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row2.4bpp"

gRubyBumperArrowRow2Tile_On:: @ 0x082621F0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row2.4bpp"
    .space 0x100

gRubyHatchArrowRow3Tile_Off:: @ 0x08262370
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row3.4bpp"

gRubyHatchArrowRow3Tile_On:: @ 0x082623F0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row3.4bpp"

gRubyCatchArrowRow3Tile_Off:: @ 0x08262470
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row3.4bpp"

gRubyCatchArrowRow3Tile_On:: @ 0x082624F0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row3.4bpp"

gRubyBumperArrowRow3Tile_Off:: @ 0x08262570
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_filler.4bpp"

gRubyBumperArrowRow3Tile_On:: @ 0x082625F0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_filler.4bpp"


@ Sign for bonus multiplier left/right digits

gRubyProgressDigit0_Tens:: @ 0x08262790
    .incbin "graphics/stage/ruby/progress_digits/digit0_tens.4bpp"

gRubyProgressDigit1_Tens:: @ 0x082627B0
    .incbin "graphics/stage/ruby/progress_digits/digit1_tens.4bpp"

gRubyProgressDigit2_Tens:: @ 0x082627D0
    .incbin "graphics/stage/ruby/progress_digits/digit2_tens.4bpp"

gRubyProgressDigit3_Tens:: @ 0x082627F0
    .incbin "graphics/stage/ruby/progress_digits/digit3_tens.4bpp"

gRubyProgressDigit4_Tens:: @ 0x08262810
    .incbin "graphics/stage/ruby/progress_digits/digit4_tens.4bpp"

gRubyProgressDigit5_Tens:: @ 0x08262830
    .incbin "graphics/stage/ruby/progress_digits/digit5_tens.4bpp"

gRubyProgressDigit6_Tens:: @ 0x08262850
    .incbin "graphics/stage/ruby/progress_digits/digit6_tens.4bpp"

gRubyProgressDigit7_Tens:: @ 0x08262870
    .incbin "graphics/stage/ruby/progress_digits/digit7_tens.4bpp"

gRubyProgressDigit8_Tens:: @ 0x08262890
    .incbin "graphics/stage/ruby/progress_digits/digit8_tens.4bpp"

gRubyProgressDigit9_Tens:: @ 0x082628B0
    .incbin "graphics/stage/ruby/progress_digits/digit9_tens.4bpp"

gRubyProgressDigit0_Ones:: @ 0x082628D0
    .incbin "graphics/stage/ruby/progress_digits/digit0_ones.4bpp"

gRubyProgressDigit1_Ones:: @ 0x082628F0
    .incbin "graphics/stage/ruby/progress_digits/digit1_ones.4bpp"

gRubyProgressDigit2_Ones:: @ 0x08262910
    .incbin "graphics/stage/ruby/progress_digits/digit2_ones.4bpp"

gRubyProgressDigit3_Ones:: @ 0x08262930
    .incbin "graphics/stage/ruby/progress_digits/digit3_ones.4bpp"

gRubyProgressDigit4_Ones:: @ 0x08262950
    .incbin "graphics/stage/ruby/progress_digits/digit4_ones.4bpp"

gRubyProgressDigit5_Ones:: @ 0x08262970
    .incbin "graphics/stage/ruby/progress_digits/digit5_ones.4bpp"

gRubyProgressDigit6_Ones:: @ 0x08262990
    .incbin "graphics/stage/ruby/progress_digits/digit6_ones.4bpp"

gRubyProgressDigit7_Ones:: @ 0x082629B0
    .incbin "graphics/stage/ruby/progress_digits/digit7_ones.4bpp"

gRubyProgressDigit8_Ones:: @ 0x082629D0
    .incbin "graphics/stage/ruby/progress_digits/digit8_ones.4bpp"

gRubyProgressDigit9_Ones:: @ 0x082629F0
    .incbin "graphics/stage/ruby/progress_digits/digit9_ones.4bpp"

.space 0x1A0


@ Text for sign over Ruby shop entrance

gRubyShopSignMartPiece0:: @ 0x08262BB0
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece0.4bpp"

gRubyShopSignCenterPiece0:: @ 0x08262C70
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece0.4bpp"
	.space 0x280

gRubyShopSignMartPiece1:: @ 0x08262FB0
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece1.4bpp"

gRubyShopSignCenterPiece1:: @ 0x08263070
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece1.4bpp"
	.space 0x300

gRubyShopSignMartPiece2:: @ 0x08263430
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece2.4bpp"
	.space 0xA0

gRubyShopSignCenterPiece2:: @ 0x082634F0
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece2.4bpp"
	.space 0x2C0



@ arrow for ramp leading to shop: mart/evo

gRubyEvoArrow_R0_Off:: @ 0x082637D0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row0.4bpp"

gRubyEvoArrow_R0_On:: @ 0x08263870
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row0.4bpp"

gRubyMartArrow_R0_Off:: @ 0x08263910
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row0.4bpp"

gRubyMartArrow_R0_On:: @ 0x082639B0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row0.4bpp"
	.space 0x180

gRubyEvoArrow_R1_Off:: @ 0x08263BD0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row1.4bpp"

gRubyEvoArrow_R1_On:: @ 0x08263C70
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row1.4bpp"

gRubyMartArrow_R1_Off:: @ 0x08263D10
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row1.4bpp"

gRubyMartArrow_R1_On:: @ 0x08263DB0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row1.4bpp"
	.space 0x180

gRubyEvoArrow_R2_Off:: @ 0x08263FD0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row2.4bpp"

gRubyEvoArrow_R2_On:: @ 0x08264070
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row2.4bpp"

gRubyMartArrow_R2_Off:: @ 0x08264110
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row2.4bpp"

gRubyMartArrow_R2_On:: @ 0x082641B0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row2.4bpp"
	.space 0x180

gRubyEvoArrow_R3_Off:: @ 0x082643D0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_filler.4bpp"

gRubyEvoArrow_R3_On:: @ 0x08264470
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_filler.4bpp"

gRubyMartArrow_R3_Off:: @ 0x08264510
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_filler.4bpp"

gRubyMartArrow_R3_On:: @ 0x082645B0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_filler.4bpp"
	.space 0x1A0



@ Slingshot wedge lights

gRuby_LSlingshot_Off_R0:: @ 0x082647F0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row0.4bpp"
	.space 0x40

gRuby_LSlingshot_On_R0:: @ 0x08264850
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row0.4bpp"
	.space 0x80

gRuby_RSlingshot_Off_R0:: @ 0x082648F0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row0.4bpp"
	.space 0x40

gRuby_RSlingshot_On_R0:: @ 0x08264950
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row0.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R1:: @ 0x08264BF0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row1.4bpp"
	.space 0x20

gRuby_LSlingshot_On_R1:: @ 0x08264C50
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row1.4bpp"
	.space 0x40

gRuby_RSlingshot_Off_R1:: @ 0x08264CD0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row1.4bpp"
	.space 0x20

gRuby_RSlingshot_On_R1:: @ 0x08264D30
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row1.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R2:: @ 0x08264FF0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row2.4bpp"

gRuby_LSlingshot_On_R2:: @ 0x08265050
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row2.4bpp"

gRuby_RSlingshot_Off_R2:: @ 0x082650B0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row2.4bpp"

gRuby_RSlingshot_On_R2:: @ 0x08265110
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row2.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R3:: @ 0x082653F0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row3.4bpp"

gRuby_LSlingshot_On_R3:: @ 0x08265450
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row3.4bpp"

gRuby_RSlingshot_Off_R3:: @ 0x082654B0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row3.4bpp"

gRuby_RSlingshot_On_R3:: @ 0x08265510
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row3.4bpp"
	.space 0x2A0

gRuby_LSlingshot_Off_R4:: @ 0x08265810
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row4.4bpp"
	.space 0x20

gRuby_LSlingshot_On_R4:: @ 0x08265870
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row4.4bpp"

gRuby_RSlingshot_Off_R4:: @ 0x082658B0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row4.4bpp"
	.space 0x20

gRuby_RSlingshot_On_R4:: @ 0x08265910
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row4.4bpp"
	.space 0x2C0



gRubyBoardBGTiles:: @ 0x08265C10
	@ loaded to charblock 2; tiles 0-703 are blank because all_board_setup.c
	@ later overwrites that region with the decompressed bgtop tiles
	.incbin "graphics/stage/ruby/ruby_board_bg_tiles.4bpp"

gRubyBoardBGTilemap:: @ 0x0826DC10
	.incbin "graphics/stage/ruby/ruby_board_bg_tilemap.bin"
