.section .rodata
.align 2

#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/bg_music.h"
#include "gba/io_reg.h"
	.include "asm/macros.inc"

.include "data/areas/area_array.inc"

.include "data/pokemon/mon_locations.inc"

.include "data/sine_table.inc"

.include "data/graphics/empty_oam_data_block.inc"

gGbPlayerPalettes:: @ 0x08058058
	@ This one is weird because some of the colors set the unused bit, so we can't do a matching conversion
	@ from a JASC palette format. Naming it with a ".bin" suffix to prevent `make clean` from deleting it.
	.incbin "graphics/gb_player/gb_player.gbapal.bin"

gGbPlayerGfx:: @ 0x08058248
	.incbin "graphics/gb_player/gb_player.8bpp"

gGbPlayerTilemap:: @ 0x0805C248
	.incbin "graphics/gb_player/gb_player_tilemap.bin"

Sio32ConnectionData:: @ 0x0805C748
	.ascii "NINTENDO"

.include "data/field_select/bonus_field_select_functions.inc"

.include "data/ereader/ereader_functions.inc"

.include "data/pokedex/dex_info_offsets.inc"
.include "data/pokedex/dex_state_functions.inc"

.include "data/pokemon/dex_entries.inc"

.include "data/field_select/field_select_functions.inc"

.include "data/intro/functions.inc"
.include "data/high_scores/functions.inc"
.include "data/high_scores/default_scores.inc"
.include "data/high_scores/screen_element_positions.inc"

.include "data/titlescreen/menu_functions.inc"
.include "data/intro/copyright.inc"

.include "data/field_select/bonus_field_select_layout_graphics.inc"
.include "data/ereader/ereader_graphics.inc"
.include "data/pokedex/pokedex_graphics.inc"

.include "data/high_scores/high_score_tiles.inc"

.include "data/field_select/field_select_layout_graphics.inc"

.include "data/fonts/ereader_text_tiles.inc"

.include "data/intro/scene1_torchic.inc"
.include "data/intro/scene2_pikas.inc"
.include "data/intro/scene3_treecko.inc"
.include "data/intro/scene4_plusle_minun.inc"
.include "data/intro/scene5_mudkip.inc"
.include "data/intro/scene6_chinchou.inc"
.include "data/intro/scene7_parade.inc"
.include "data/intro/scene8_wailmer.inc"
.include "data/intro/scene9_ball_flight.inc"

.include "data/titlescreen/menu_graphics.inc"

gGravityDeltas_Strong:: @ 0x08137900
	.2byte 1, 1, 1, 0

gGravityDeltas_Medium:: @ 0x08137908
	.2byte 1, 0, 1, 0

gGravityDeltas_Light:: @ 0x08137910
	.2byte 1, 0, 0, 0

.include "data/idle_board/idle_state_functions.inc"

gAreaPortraitIndexes:: @ 0x08137928
	.2byte 0, 1, 2, 3, 4
	.2byte 5, 6, 7, 8, 9
	.2byte 10, 11, 12, 12

gPondBumperRetractFrames:: @ 0x08137944
	.2byte 10, 7,6,5,4,3,2,1,0,1,0,1,0,1,0,1,0,1

gPondBumperTransitionFrames:: @ 0x08137968
	.2byte 0,2,3,4,5,6,7,10,10,10,7,6,5,4,3,2,1,0

gLotadBobOffsets:: @ 0x0813798C
	.2byte 0, 10, 20, 30, 20, 10

gChinchouBumper_Pals:: @ 0x08137998
	.incbin "graphics/stage/main/chinchou_bumper.gbapal"

gLotadBumper_Pals:: @ 0x081379B8
	.incbin "graphics/stage/main/lotad_bumper.gbapal"

gWhiscash_Pals:: @ 0x081379D8
	.incbin "graphics/stage/main/whiscash.gbapal"

gBoardArrowAnimFrames:: @ 0x08137AB8
	.2byte 0,1,2,3,2,1,0,3,0,3

	@ Outside range used by the bumperAnimFrames.
	.2byte 0,0,0,0,0,0,0,0,0,0
	.2byte 0,0,0,0,0,0,0,0,0,0
	.2byte 0,0,0,1,0,0,0,1,0,0
	.2byte 0,1,0,1,0,1,0,1,0,1
	.2byte 0,1,1,1,0,1,1,1,0,1
	.2byte 1,1,1,1,1,1

gFieldVariant_Pals:: @ 0x08137B3C
	.incbin "graphics/stage/main/field_variants.gbapal"

gPelipperFlyAnimTable:: @ 0x08137CBC
	@ frameId, yOffset
	.byte 9, -4
	.byte 9, -4
	.byte 9, -4
	.byte 9, -4
	.byte 10, -2
	.byte 10, -2
	.byte 11, 0
	.byte 11, 0
	.byte 11, 0
	.byte 12, -2
	.byte 12, -2
	.byte 12, -2
	.byte 12, -2

gBumperMosaicValues:: @ 0x08137CD6
	.2byte 0,4,2,0,4,2

gShopSignLoopFrames:: @ 0x08137CE2
	@2 sets of 5
	.2byte 0,1,2,2,1
	.2byte 7,8,9,8,0

gShopSignIntroFrames:: @ 0x08137CF6
	@2 sets of 4
	.2byte 3,0,3,0
	.2byte 6,7,6,7

gShopSignTransitionFrames:: @ 0x08137D06
	@2 sets of 14
	.2byte 6,7,6,4,4,5,5,4,4,5,5,3,0,3
	.2byte 3,0,3,4,4,5,5,4,4,5,5,6,7,6
	.space 2, 0

gDusclopsBossGuardReadyTileOffsets:: @ 0x08137D40
	.2byte 12,13,12,14

gLightningGrabAnimFrameIndices:: @ 0x08137D48
	.2byte 0,1,2,3,4,7,2,1,7,5,6,0

gSphealScoreDigitSpriteIndices:: @ 0x08137D60
	.byte 0,2,2,2,2,2,0,0,0,0
	.byte 2,2,2,2,2,1,1,1,1,1
	.byte 1,1,0,0

.include "data/pause_and_debug/pause_menu.inc"
.include "data/pause_and_debug/debug_menu.inc"

gPinballGameStateFuncs:: @ 0x08137E04
	.4byte PinballGame_State0_49ED4 @ called once upon loading the field
	.4byte PinballGame_State1_4AAD8 @ called once every frame while playing
	.4byte PinballGame_State2_4ABC8 @ called once on game over (losing all balls)
	.4byte PinballGame_State3_4B20C @ called once after game over?

.include"data/ball/ball_palettes.inc"

gCaptureBallTilesGfx:: @ 0x08138014
	.incbin "graphics/stage/main/ball_open_to_catch.4bpp"
	.space 0x20

gDusclopsBonusClear_Gfx:: @ 0x08138834
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear.4bpp"
	.space 0x20

gKecleonBonusClear_Gfx:: @ 0x0813A854
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear.4bpp"
	.space 0x20

gKyogreBonusClear_Gfx:: @ 0x0813C874
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear.4bpp"
	.space 0x20

gGroudonBonusClear_Gfx:: @ 0x0813E894
	.incbin "graphics/stage/groudon/groudon_bonus_clear.4bpp"
	.space 0x20

gRayquazaBonusClear_Gfx:: @ 0x081408B4
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear.4bpp"
	.space 0x20

gCaptureScreenTilesGfx:: @ 0x081428D4
	.incbin "graphics/stage/main/capture_screen.4bpp"

.include "data/pokemon/mon_hatch_sprites_pals.inc"

.include "data/idle_board/attract_demo_sequences.inc"

gEvolutionCutsceneTilesGfx:: @ 0x08158284
	.incbin "graphics/stage/main/board_action.4bpp"
	.space 0x3E0

gBoardActionObj_Pals:: @ 0x0815A6A4
	.incbin "graphics/stage/main/board_action_obj.gbapal"

.include "data/graphics/board_pickups.inc"


gFlipperCollisionData:: @ 0x0816C3E4
@ Flipper data has 13 sets of 96*96 u16 data (2 unused at the end)
	.incbin "data/board_data/collision/flipper_collision_all_96x96.bin"

gDebugAsciiFont:: @ 0x081A6BE4
@ 8x8 font, one tile per character.
	.incbin "graphics/debug_ascii_font.4bpp"
	.space 0x7800   @ 960 unused tiles, all zero

	.include "data/pokemon/mon_catch_sprites_pals.inc"

gKyogreWaterAnimFrame_Pals:: @ 0x081B0DE4
	.incbin "graphics/stage/kyogre/water_anim_frames.gbapal"

.include "data/graphics/framesets/pokeball_capture_frames.inc"

.include "data/graphics/board_palettes.inc"

.include "data/graphics/evo_mart_background.inc"

.include "data/graphics/travel_painter.inc"

gTimer_Default_Pal:: @ 0x081C0064
	.incbin "graphics/stage/main/default_timer.gbapal"

.include "data/areas/area_palettes.inc"

.include "data/slots/slot_palettes.inc"
.include "data/board_data/ruby_board.inc"
.include "data/board_data/sapphire_board.inc"
.include "data/board_data/dusclops_board.inc"
.include "data/board_data/kecleon_board.inc"
.include "data/board_data/kyogre_board.inc"
.include "data/board_data/groudon_board.inc"
.include "data/board_data/rayquaza_board.inc"
.include "data/board_data/spheal_board.inc"

gPichuKickbackFx_Gfx:: @ 0x08395A4C
	.incbin "graphics/stage/main/pichu_saver_kickback.4bpp"
	.space 0x20

gPikachuKickbackFx_Gfx:: @ 0x08397E6C
	.incbin "graphics/stage/main/pikachu_saver_kickback.4bpp"
	.space 0x20

gCatchTargetCollisionBitmap:: @ 0x0839A28C
	.incbin "data/board_data/collision/catch_target_collision_48x48_typeless.bin"

.include "data/pokemon/mon_portraits_pals.inc"

.include "data/graphics/catch_mode_fx.inc"

gAerodactlyFlight_Gfx:: @ 0x083A704C
	.incbin "graphics/stage/ruby/aerodactyl_flight.4bpp"
	.space 0x500
	.incbin "graphics/stage/ruby/aerodactyl_flight_cap.4bpp"

gAerodactlyFlight_Pal:: @ 0x083A806C
	.incbin "graphics/stage/ruby/aerodactyl_flight.gbapal"

gTotodile_Pal:: @ 0x083A808C
	.incbin "graphics/stage/ruby/totodile.gbapal"

gBoardHudTiles_B:: @ 0x083A826C
	.incbin "graphics/stage/main/board_hud_tiles_b.4bpp"
	.space 0x20

gRubyShopSign_Pal:: @ 0x083A8A8C
	.incbin "graphics/stage/ruby/shopsign.gbapal"

gTravelPortrait_Pal:: @ 0x083A8AAC
	.incbin "graphics/stage/main/travel_portrait.gbapal"

gBoardHudTiles_A:: @ 0x083A8ACC
	.incbin "graphics/stage/main/board_hud_tiles_a.4bpp"
	.space 0x20

.include "data/slots/slot_graphics.inc"

.include "data/ball/ball_rotation_graphics.inc"
.include "data/ball/ball_fx_graphics.inc"


gSpoinkEntity_Gfx:: @ 0x083C076C
	.incbin "graphics/stage/main/spoink_launcher.4bpp"

gKyogreSurfacingFx_Gfx:: @ 0x083C13AC
	.incbin "graphics/stage/kyogre/surfacing_fx_frames.4bpp"

gKyogreFreeze_Gfx:: @ 0x083C1A6C
	.incbin "graphics/stage/kyogre/freeze_trap_frames.4bpp"

gRubyChikoritaEntity:: @ 0x083C3C2C
	.incbin "graphics/stage/ruby/chikorita_frames.4bpp"

gChikoritaProjectileTiles:: @ 0x083C542C
	.incbin "graphics/stage/ruby/chikorita_projectile.4bpp"

@ Used when the leaf blade hits one of the linoone
gChikoritaExplosionTiles:: @ 0x083C562C
	.incbin "graphics/stage/ruby/chikorita_projectile_fx.4bpp"

@ Clouds from the intro sequence
gRayquazaSkyBackgroundGfx:: @ 0x083C5A2C
	.incbin "graphics/stage/rayquaza/sky_background.4bpp"

gChinchouBumper_Gfx:: @ 0x083C806C
	.incbin "graphics/stage/main/chinchou_bumper.4bpp"

.include "data/pokemon/mon_hatch_sprites.inc"

.include "data/graphics/evo_item_rotation.inc"

gFlipper_Gfx:: @ 0x083FE44C
	.incbin "graphics/stage/main/flipper_frames.4bpp"

.include "data/fonts/mon_name_text_tiles.inc"

gSapphireBoardWailmer_Gfx:: @ 0x083FFD8C
	.incbin "graphics/stage/sapphire/wailmer.4bpp";

	.include "data/pokemon/mon_catch_sprites.inc"

gRubyStageGulpin_Gfx:: @ 0x08447A8C
	.incbin "graphics/stage/ruby/gulpin.4bpp"

gMainStageBonusTrap_Gfx:: @ 0x0844838C
	.incbin "graphics/stage/main/bonus_trap.4bpp"

gLotadBumper_Gfx:: @ 0x0844928C
	.incbin "graphics/stage/main/lotad_bumper.4bpp"

gRubyStageCyndaquil_Gfx:: @ 0x08449D8C
	.incbin "graphics/stage/ruby/cyndaquil.4bpp"

gJirachiFx_Gfx:: @ 0x0844AA0C
	.incbin "graphics/stage/main/jirachi_fx.4bpp"

gSapphireStageBasket_Gfx:: @ 0x0844F20C
	.incbin "graphics/stage/sapphire/seedot_basket.4bpp"

gKecleonStageKecleon_Gfx:: @ 0x0844F98C
	.incbin "graphics/stage/kecleon/kecleon.4bpp"

gKecleonStageKecleonFx_Gfx:: @ 0x0845588C
	.incbin "graphics/stage/kecleon/kecleon_fx.4bpp"

gOneUpTreeckoSprite_Gfx:: @ 0x08455E8C
	.incbin "graphics/stage/misc/treecko_1_up_deliverer.4bpp"

.include "data/fonts/life_count_digit_tiles.inc"

gShroomishBumperHit_Gfx:: @ 0x0845690C
	.incbin "graphics/stage/sapphire/shroomish_bumper_hit.4bpp"

gRubyStageNuzleaf_Gfx:: @ 0x0845710C
	.incbin "graphics/stage/ruby/nuzleaf.4bpp"

gHatchMachineSparkleFx_Gfx:: @ 0x0845A08C
	.incbin "graphics/stage/sapphire/hatch_machine_spark_fx.4bpp"

gRubyIntroSprites_Gfx:: @ 0x0845A48C
	.incbin "graphics/stage/ruby/intro_sprite.4bpp"

gSapphireIntroSprites_Gfx:: @ 0x0845F9EC
	.incbin "graphics/stage/sapphire/intro_sprite.4bpp"

gDusclopsIntroSprite_Gfx:: @ 0x08464F4C
	.incbin "graphics/stage/dusclops/intro_sprite.4bpp";

gKecleonIntroSprite_Gfx:: @ 0x084675EC
	.incbin "graphics/stage/kecleon/intro_sprite.4bpp";

gKyogreIntroSprite_Gfx:: @ 0x0846A40C
	.incbin "graphics/stage/kyogre/intro_sprite.4bpp"

gGroudonIntroSprite_Gfx:: @ 0x0846D2AC
	.incbin "graphics/stage/groudon/intro_sprite.4bpp"

gRayquazaIntroSprite_Gfx:: @ 0x08472A6C
	.incbin "graphics/stage/rayquaza/intro_sprite.4bpp"

gSphealIntroSprites_Gfx:: @ 0x084779EC
	.incbin "graphics/stage/spheal/intro_sprite.4bpp"

gSapphireMinun_Gfx:: @ 0x0847A40C
	.incbin "graphics/stage/sapphire/bumper_minun.4bpp"

gSapphireMinunHeadElectricity_Gfx:: @ 0x0847D10C
	.incbin "graphics/stage/sapphire/bumper_minun_fx.4bpp"

gRubyMakuhitaGfx:: @ 0x0847DF0C
	.incbin "graphics/stage/ruby/makuhita.4bpp"

gLinooneBumperGfx:: @ 0x0847FD0C
	.incbin "graphics/stage/ruby/linoone_side_bumper.4bpp"

@ Shop selection change sheen, and "SOLD OUT" banner.
gShopPortraitOverlayGfx:: @ 0x0847FF0C
	.incbin "graphics/stage/main/shop_portrait_overlay.4bpp"

.include "data/fonts/mart_price_digit_tiles.inc"

gSapphireShopSignTileGfx:: @ 0x0848108C
	.incbin "graphics/stage/sapphire/shop_sign_tiles.4bpp"

gRubyTravelVolbeat_Gfx:: @ 0x08483D8C
	.incbin "graphics/stage/ruby/travel_volbeat.4bpp"

gSapphireTravelIllumise_Gfx:: @ 0x08488A0C
	.incbin "graphics/stage/sapphire/travel_illumise.4bpp"

.include "data/areas/area_portraits.inc"

@ Includes the rope tiles, totodile, and egg
gTotodileEggDelivery_Gfx:: @ 0x0848FD8C
	.incbin "graphics/stage/ruby/totodile.4bpp"

gHatchMachineElevator_Gfx:: @ 0x08490A4C
	.incbin "graphics/stage/sapphire/hatch_machine_elevator.4bpp"

gDusclopsBoardDusclopsAppearFx_Gfx:: @ 0x08494E4C
	.incbin "graphics/stage/dusclops/dusclops_appear_fx.4bpp";

gKyogreTopPosition_Gfx:: @ 0x0849664C
	.incbin "graphics/stage/kyogre/kyogre_top.4bpp"

gKyogreBreach_Gfx:: @ 0x0849B8CC
	.incbin "graphics/stage/kyogre/kyogre_breach.4bpp"

gGroudonAttackFx_Gfx:: @ 0x0849F1CC
	.incbin "graphics/stage/groudon/board_fx.4bpp"
	.space 0x20

gGroudonBoardBoulders_Gfx:: @ 0x084A11EC
	.incbin "graphics/stage/groudon/boulders.4bpp";

gRayquazaTornadoGfx:: @ 0x084A6EEC
	.incbin "graphics/stage/rayquaza/tornado_frames.4bpp"

gRayquazaFlyby_Gfx:: @ 0x084A856C
	.incbin "graphics/stage/rayquaza/wind_board.4bpp"
	.space 0x20

gRayquazaSpriteSheet:: @ 0x084AA18C
	.incbin "graphics/stage/rayquaza/entity_flying.4bpp"

gRayquazaBodyVariantTiles:: @ 0x084AA9EC
	.incbin "graphics/stage/rayquaza/body_variants.4bpp"

gSphealNetGfx:: @ 0x084AF9EC
	.incbin "graphics/stage/spheal/spheal_net.4bpp"

gSphealNetFrontGfx:: @ 0x084AFFEC
	.incbin "graphics/stage/spheal/spheal_net_front.4bpp"

gSphealFlyingEnemyVariantSprites:: @ 0x084B046C
	.incbin "graphics/stage/spheal/spheal.4bpp"

gSphealMinionBodySprites:: @ 0x084B47EC
	.incbin "graphics/stage/spheal/sealeo.4bpp"

gSphealResultsScreenGfx:: @ 0x084B77EC
	.incbin "graphics/stage/spheal/spheal_results.4bpp"

gWhiscash_Gfx:: @ 0x084B7FEC
	.incbin "graphics/stage/ruby/whiscash.4bpp"

gPelipper_Gfx:: @ 0x084BB16C
	.incbin "graphics/stage/sapphire/pelipper.4bpp"
	.incbin "graphics/stage/sapphire/charger.4bpp"

gChargeFillIndicator_Gfx:: @ 0x084C00EC
	.incbin "graphics/stage/main/charge_fill_indicator.4bpp"

gPikachuSaverTilesGfx:: @ 0x084C07EC
	.incbin "graphics/stage/main/pikachu_saver_tiles.4bpp"

gDxModePikachuObjTiles:: @ 0x084C0C6C
	.incbin "graphics/stage/main/dx_mode_pikachu_obj_tiles.4bpp"

gPichuSaverTilesGfx:: @ 0x084C156C
	.incbin "graphics/stage/main/pichu_saver_tiles.4bpp"

gSapphirePlusle_Gfx:: @ 0x084C1E6C
	.incbin "graphics/stage/sapphire/bumper_plusle.4bpp"

gSapphirePlusleHeadElectricity_Gfx:: @ 0x084C4B6C
	.incbin "graphics/stage/sapphire/bumper_plusle_fx.4bpp"

.include "data/pokemon/mon_portraits.inc"

gCompressedNumbers_Gfx:: @ 0x084ECF6C
	.incbin "graphics/stage/sapphire/compressed_numbers.4bpp"

gRubyBoardShopDoor_Gfx:: @ 0x084ED0CC
	.incbin "graphics/stage/ruby/shop_door.4bpp";

gZigzagoonShockWallIndicator_Gfx:: @ 0x084ED6CC
	.incbin "graphics/stage/sapphire/zigzagoon_press_button_indicator.4bpp";

gDusclopsBoardDusclops_Gfx:: @ 0x084EDACC
	.incbin "graphics/stage/dusclops/dusclops.4bpp";

gRubyBoardSharpedo_Gfx:: @ 0x084F5ACC
	.incbin "graphics/stage/ruby/sharpedo.4bpp";

gMartEvoForegroundMenuUx_Gfx:: @ 0x084F61EC
	.incbin "graphics/stage/main/mart_evo_menu_foreground.4bpp";

gRubyBoardShop_Gfx:: @ 0x084F6B0C
	.incbin "graphics/stage/ruby/shop.4bpp";

gAreaRouletteSelectedFx_Gfx:: @ 0x084FA20C
	.incbin "graphics/stage/main/area_roulette_selected_fx.4bpp";

gMainBoardPikaSpinner_Gfx:: @ 0x084FA48C
	.incbin "graphics/stage/main/pika_spinner.4bpp";

gRubyBoardHatchCave_Gfx:: @ 0x084FB68C
	.incbin "graphics/stage/ruby/hatch_cave.4bpp";

gEggFrameTilesGfx:: @ 0x084FD18C
	.incbin "graphics/stage/main/egg.4bpp";

gSapphireBoardSeedot_Gfx:: @ 0x084FDF8C
	.incbin "graphics/stage/sapphire/seedot.4bpp";

gSapphireBoardShopShockWall_Gfx:: @ 0x084FEA0C
	.incbin "graphics/stage/sapphire/shop_shock_wall.4bpp";

gRubyBoardRampPrize_Gfx:: @ 0x084FEF0C
	.incbin "graphics/stage/ruby/ramp_prize.4bpp";

gDusclopsBoardDusclopsBallGrabSwirl_Gfx:: @ 0x084FF30C
	.incbin "graphics/stage/dusclops/dusclops_ball_grab.4bpp";

gKyogreWhirlpoolTrap_Gfx:: @ 0x084FF90C
	.incbin "graphics/stage/kyogre/whirlpool_trap.4bpp"

gMainBoardBallSave_Gfx:: @ 0x0850100C
	.incbin "graphics/stage/main/ball_save.4bpp";

gMainBoardBallSaveLatios_Gfx:: @ 0x085028CC
	.incbin "graphics/stage/main/latios.4bpp";

gMainBoardBallSaveLatiosArm_Gfx:: @ 0x085038CC
	.incbin "graphics/stage/main/latios_arm.4bpp";

gMainBoardEndOfBall_Gfx:: @ 0x0850398C
	.incbin "graphics/stage/main/end_of_ball.4bpp";

.include "data/fonts/end_of_ball_bonus_summary_text_tiles.inc"

gMainBoardEvoBanner_Gfx:: @ 0x08505BCC
	.incbin "graphics/stage/main/evo_banner.4bpp";

gMainBoardGameOverText_Gfx:: @ 0x08509F4C
	.incbin "graphics/stage/main/game_over_text.4bpp";

gMainBoardJirachiBanner_Gfx:: @ 0x0850A34C
	.incbin "graphics/stage/main/jirachi_banner.4bpp";

gMainBoardTravel_Gfx:: @ 0x0850E6CC
	.incbin "graphics/stage/main/travel.4bpp";

gPauseMenuText_Gfx:: @ 0x08510CAC
	.incbin "graphics/stage/main/pause_menu_text.4bpp";

gDusclopsBoardDuskull_Gfx:: @ 0x08510E4C
	.incbin "graphics/stage/dusclops/duskull.4bpp";

gSapphireBoardZigzagoon_Gfx:: @ 0x08512C4C
	.incbin "graphics/stage/sapphire/zigzagoon.4bpp";

gBallSaver_Ruby_Pal:: @ 0x08514F4C
	.incbin "graphics/stage/ruby/ball_saver.gbapal"

gBallSaver_Sapphire_Pal:: @ 0x08514F6C
	.incbin "graphics/stage/sapphire/ball_saver.gbapal"

gRubyChinchouCatchBurstBanner_Gfx:: @ 0x0851514C
	.incbin "graphics/stage/ruby/chinchou_catch_burst_banner.4bpp"
	.space 0xA0

gRubyChinchouCatchBurstBanner_Pal:: @ 0x0851956C
	.incbin "graphics/stage/ruby/chinchou_catch_burst_banner.gbapal"

gRubyLotadCatchBurstBanner_Pal:: @ 0x0851958C
	.incbin "graphics/stage/ruby/lotad_catch_burst_banner.gbapal"

gSapphireShroomishCatchBurstBanner_Pal:: @ 0x085195AC
	.incbin "graphics/stage/sapphire/shroomish_catch_burst_banner.gbapal"

gRubyLotadCatchBurstBanner_Gfx:: @ 0x0851976C
	.incbin "graphics/stage/ruby/lotad_catch_burst_banner.4bpp"
	.space 0xA0

gSapphireShroomishCatchBurstBanner_Gfx:: @ 0x0851DB8C
	.incbin "graphics/stage/sapphire/shroomish_catch_burst_banner.4bpp"
	.space 0xA0

gEndOfBallBonus_Ruby_Pal:: @ 0x08521FAC
	.incbin "graphics/stage/ruby/end_of_ball_bonus.gbapal"

gEndOfBallBonus_Sapphire_Pal:: @ 0x08521FCC
	.incbin "graphics/stage/sapphire/end_of_ball_bonus.gbapal"

gMainBoardEvoBanner_Pal:: @ 0x085221AC
    .incbin "graphics/stage/main/evo_banner.gbapal"

gMainCatchModeBanner_Gfx:: @ 0x085223AC
	.incbin "graphics/stage/main/catch_mode_banner.4bpp"
	.space 0xA0

gMainCatchModeBanner_Pal:: @ 0x085267CC
    .incbin "graphics/stage/main/catch_mode_banner.gbapal"

gMainBoardJirachiBanner_Pal:: @ 0x085269CC
    .incbin "graphics/stage/main/jirachi_banner.gbapal"

gMainBoardTravel_Pal:: @ 0x08526BCC
    .incbin "graphics/stage/main/travel.gbapal"

gSapphireBoardZigzagoonFx_Gfx:: @ 0x08526DCC
	.incbin "graphics/stage/sapphire/zigzagoon_fx.4bpp";

@ Unreferenced blob, most likely a leftover tilemap. This has mostly ascending id values with runs of repeats.
gUnknown_085279CC:: @ 0x085279CC
	.incbin "graphics/stage/unknown_085279CC.bin"

.include "data/options_screen/options_screen_layout.inc"
