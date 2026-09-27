#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H

// Place all external function declarations in this file

// src/gbplayer.c

void InitGameBoyPlayer(void);
void EnableGbPlayerRumble(void);
void DisableGbPlayerRumble(void);
int IsGbPlayerReady(void);
void RestoreDefaultInterrupts(void);
void PlayRumble(int arg0);
void SetRumbleMode(int arg0);
void SetRumblePaused(int arg0);
void ProcessRumbleFrame(void);
void InitSio32Hardware(void);
extern u32 Sio32ValidateResponse(u8 param_1);
extern u32 Sio32BuildCommand(u8 param_1);
void Sio32IDIntr(void);

// src/main.c

void AgbMain(void);
void Main_09BC(void);
void VBlankIntr(void);
void VCountIntr(void);
void SerialIntr(void);
void Timer3Intr(void);
void IntrDummy(void);
s16 Sin(u16 arg0);
s16 Cos(u16 arg0);

// sin table produces values from 0 - 20000
#define TRIG_SCALE 20000

/* Multiply value by sin(angle).

   Works in most cases; compiles differently with some values, like -100, where the negative
   plus optimizer pre-reduction causes it to fall in a different position.
   Use the MulNegSinSpecial for those cases */
#define MulSin(value, angle) (((value) * (Sin(angle))) / TRIG_SCALE)

/* Multiply value by cos(angle).*/
#define MulCos(value, angle) (((value) * (Cos(angle))) / TRIG_SCALE)

// Multiply -value by sin(angle). (used in cases where compile optimization order matters)
#define MulNegSinSpecial(value, angle) (-((Sin(angle)) * (value)) / TRIG_SCALE)

void DisableVBlankInterrupts(void);
void MainLoopIter(void);
void DefaultMainCallback(void);

// src/rom_3219C.c

void PickSpeciesForCatchEmMode(void);

// src/rom_850.c

u16 IsInVblank(void);
void SetMainCallback(void (*func)(void));
void ResetMainCallback(void);
void SetVBlankIntrFunc(void (*func)(void));
void ResetVBlankIntrFunc(void);
void SetVCountIntrFunc(void (*func)(void));
void ResetVCountIntrFunc(void);

// src/titlescreen.c

void TitlescreenMain(void);
void LoadTitlescreenGraphics(void);
void InitTitlescreenStates(void);
void TitleScreen1_WaitForStartButton(void);
void TitleScreen2_AnimatePressStartSelected(void);
void TitleScreen9_DeleteSaveConfirmation(void);
void TitleScreen3_AnimateMenuSlideIn(void);
void TitleScreen4_MenuInputNoSavedGame(void);
void TitleScreen7_ProcessMenuItemSelected_NoSavedGame(void);
void TitleScreen5_MenuInputSavedGame(void);
void TitleScreen8_ProcessMenuItemSelected_SavedGame(void);
void TitleScreen6_AnimCloseMenu(void);
void TitleScreen10_ExecMenuSelection(void);
void TitleScreen11_FadeToAction(void);

// src/util.c

void SetMainGameState(u16 mainState);
void FadeInScreen(void);
void FadeOutScreen(void);
s16 LoadSpriteSets(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups);
void ResetDisplayState(void);
void ClearGraphicsMemory(void);
void ClearBgTilemapAndOffsets(void);
void ClearSprites(void);
void DrawTextToTilemap(u8 *arg0, s16 arg1, s16 arg2);
u8 *FormatIntToString(int arg0, u8 *arg1, int arg2, s16 arg3);
void SetMatrixScale(s16 xScale, s16 yScale, s16 matrixNum);

// src/bonus_field_select.s

extern void BonusFieldSelectMain(void);
extern void LoadBonusFieldSelectGraphics(void);
extern void InitBonusFieldSelectState(void);
extern void BonusFieldSelect_Menu(void);
extern void BonusFieldSelect_FadeToSelection(void);
extern void RenderBonusFieldSelectSprites(void);

// src/ereader.c

extern void EReaderMain(void);
extern void LoadEReaderGraphics(void);
extern void InitEReaderTextState(void);
extern void Ereader_ShowInstructions(void);
extern void Ereader_AnimateLinkCable(void);
extern void Ereader_Communicating(void);
extern void Ereader_ShowLinkTimeout(void);
extern void Ereader_CloseSuccessfulTransmission(void);
extern void Ereader_ShowSuccessPopup(void);
extern void Ereader_ShowPrizeText(void);
extern void Ereader_FadeScreenToMenu(void);
extern void ClearEReaderTextRows(void);
extern void DrawEReaderTextPage(s8);
extern void DrawEReaderTextCharacter(s8, s8);
extern void BlinkEReaderTextCursor(s8, u16);
extern s16 GetEReaderCardIndex(void);
extern void UpdateEReaderSprites(void);
extern void UpdateEReaderSpritesViaOam(void);
extern void InitEReaderLinkBuffers(void);
extern s32 PrepareEReaderLinkSendCmd(void);
extern s16 ProcessEReaderLinkReceive(void);

// src/field_select.s

extern void FieldSelectMain(void);
extern void LoadFieldSelectGraphics(void);
extern void FieldSelect_State1_8C7C(void);
extern void FieldSelect_State2_8F64(void);

// src/high_scores.s
extern void HighScoresMain(void);
extern void IdleHighScoresMain(void);
extern void LoadHighScoreGraphics(void);
extern void InitHighScoreData(void);
extern void HighScore_ShowCompletionBanner(void);
extern void HighScore_FlashNewEntry(void);
extern void HighScore_BrowseScores(void);

// asm/high_scores.s

extern void HighScore_NameEntry(void);
extern void HighScore_InitLinkExchange(void);
//extern ? HighScore_LinkRetryWait();
//extern ? HighScore_LinkError();
//extern ? HighScore_LinkSuccess();
//extern ? HighScore_ResetConfirmation();
//extern ? HighScore_ExitToTitle();
//extern ? IdleHighScore_LoadGraphics();
extern void InitIdleHighScoreData(void);
//extern ? IdleHighScore_Exit();
//extern ? HighScore_ReloadAfterLink();
//extern ? HighScore_ShowMergedScores();
//extern ? HighScore_ReturnToMain();
extern void UpdateNameEntryCursor(void);
extern void RenderHighScoreSprites(void);
extern void RenderCompletionBanner(void);
extern void InitLinkExchangeBuffers(void);
extern s16 HighScore_ProcessLinkExchange(void);
extern s16 ProcessLinkSendData(void);
extern s16 MasterSendHighScores();
extern s16 SlaveSendHighScores();
extern s16 MasterReceiveHighScores(void);
extern s16 SlaveReceiveHighScores(void);
extern void DrawAllHighScoreText(void);
extern void FormatScoreDigits(u32, u32);
extern int CompareScores(u32, u32, u32, u32);
extern s32 GetNewHighScoreIndex(u32, u32, u32);
extern void InsertNewHighScore(u32, u32, u32, int);
extern u32 MergeReceivedTopScore(u32);
extern void PrintHighScoreNameChar(u32, u32, s16, u32);
extern void SetDefaultHighScores(void);
extern void AnimateScoreTilemapPalette(u32, u32, s16);
extern void ResetScoreTilemapPalette(u32, u32, s16);
extern s8 CheckAllPokemonCaught(void);
extern void FadeInFromWhite(void (*func)(void));
extern void FadeOutToWhite(void (*func)(void));
extern void FadeInWithCustomPalettes(u8 *, const Palette *, void (*func)(void));
extern void FadeOutToBlack(void (*func)(void));
extern void InterpolatePaletteStep(u16);
extern void DarkenPalette(const Palette *, u8 *, u16, u16); // Very much subject to change
extern void BrightenPalette(const Palette *, u8 *, u16, u16);
extern void FlashWhiteTransitionIn(void);
extern void FlashWhiteTransitionOut(void);
extern void UnblankLCD(void);
extern void ForceBlankLCD(void);
extern void DisableDisplayInterrupts(void);
extern void PrintString(u16 glyph, u16 color, int x, int y, int arg4, int arg5);

// src/intro.c
extern void IntroMain(void);
extern void Intro_State0_929C(void);
extern void Intro_State1_9348(void);
extern void Intro_State2_9370(void);
extern void Intro_State3_938C(void);
extern void Intro_State4_93D0(void);
extern void IntroVBlankCallback(void);
extern void IntroScene1_00_LoadTitleLettersAndTorchicScene(void);
extern void IntroScene1Torchic_InitVars(void);

// asm/intro.s

extern void IntroScene1TitleText_01_TitleLetterBounceReveal(void);
extern void IntroScene1TitleText_02_TitleRecedeToBackground(void);
extern void IntroScene1TitleText_03_1PxText(void);
extern void IntroScene1Torchic_04_LargeSparkle(void);
extern void IntroScene1Torchic_05_SpeedLineFadeIn(void);
extern void IntroScene1Torchic_06_BrightenPokeballFlyTowardsScreen(void);
extern void IntroScene1Torchic_07_TorchicRiseAndBGSplit(void);
extern void nullsub_4(void);
//extern ? IntroScene1Torchic_09_OrangeTextScrolls();
//extern ? nullsub_5();
//extern ? nullsub_17();
//extern ? IntroScene1Torchic_12_FlashWhite();
extern void IntroScene1Torchic_RenderTitleSprite(void);
extern void IntroScene1Torchic_RenderScaledTitle(void);
extern void IntroScene1Torchic_RenderAllSprites(void);
//extern ? IntroScene1Torchic_13_ResetTilemap();
//extern ? IntroScene2Pikas_14_LoadPinkYellowBackground();
extern void IntroScene2Pikas_InitVars(void);
//extern ? nullsub_6();
//extern ? IntroScene2Pikas_16_PikaPairRising();
//extern ? nullsub_7();
//extern ? IntroScene2Pikas_18_FlashWhite();
//extern ? IntroScene2Pikas_19_ResetTilemap();
//extern ? IntroScene3Treecko_20_LoadTreeckoFlipperBall();
//extern ? IntroScene3Treecko_InitVars();
//extern ? IntroScene3Treecko_21_MoveTreeckoFlipperBallAndSplit();
//extern ? IntroScene3Treecko_22_FlipperHitTextScroll();
//extern ? nullsub_8();
//extern ? IntroScene3Treecko_24_FlashWhite();
//extern ? IntroScene3Treecko_RenderPokeball();
//extern ? IntroScene3Treecko_25_ResetTilemap();
//extern ? IntroScene4PlusleMinun_26_LoadTealWhiteBackground();
//extern ? IntroScene4PlusleMinun_InitVars();
//extern ? nullsub_9();
//extern ? IntroScene4PlusleMinun_28_PlusleMinunTextScroll();
//extern ? nullsub_10();
//extern ? IntroScene4PlusleMinun_30_FlashWhite();
//extern ? IntroScene4PlusleMinun_31_ResetTilemap();
//extern ? IntroScene5Mudkip_32_LoadMudkipBallScene();
//extern ? IntroScene5Mudkip_InitVars();
//extern ? IntroScene5Mudkip_33_MoveMudkipBallSplit();
//extern ? IntroScene5Mudkip_34_MoveMudkipBallTextScroll();
//extern ? nullsub_11();
//extern ? IntroScene5Mudkip_36_FlashWhite();
//extern ? IntroScene5Mudkip_RenderAllSprites();
//extern ? IntroScene5Mudkip_37_ResetTilemap();
//extern ? IntroScene6Chinchou_38_LoadChinchou();
//extern ? IntroScene6Chinchou_InitVars();
//extern ? IntroScene6Chinchou_39_MoveChinchouBallAndStars();
//extern ? IntroScene6Chinchou_40_MoveChinchouAndStars();
//extern ? IntroScene6Chinchou_41_FlashWhiteClearSprites();
//extern ? IntroScene6Chinchou_RenderStarSprites();
//extern ? IntroScene6Chinchou_42_FrameAdvance();
//extern ? IntroScene7Parade_43_LoadPinkYellowBackground();
//extern ? IntroScene7Parade_InitVars();
//extern ? IntroScene7Parade_44_MoveMakuhita();
//extern ? IntroScene7Parade_45_MoveMakuhitaAndSpoink();
//extern ? IntroScene7Parade_46_MoveMakuhitaPelipperAndSpoink();
//extern ? IntroScene7Parade_47_MoveMakuhitaPelipperWailmerAndSpoink();
//extern ? IntroScene7Parade_48_MoveWailmerShake();
//extern ? IntroScene7Parade_49_FlashWhite();
//extern ? IntroScene7Parade_RenderWailmer();
//extern ? IntroScene7Parade_50_ResetTilemap();
//extern ? IntroScene8WailmerLaunch_51_LoadWailmerBlastBackground();
//extern ? IntroScene8WailmerLaunch_InitVars();
//extern ? IntroScene8WailmerLaunch_52_BallAppearTimer();
//extern ? IntroScene8WailmerLaunch_53_MoveBallStarsAndWailmer();
//extern ? IntroScene8WailmerLaunch_54_MoveStarsAndWailmer();
//extern ? nullsub_12();
//extern ? nullsub_13();
//extern ? IntroScene8WailmerLaunch_57_FlashWhiteClearSprites();
//extern ? IntroScene8WailmerLaunch_RenderAllSprites();
//extern ? IntroScene8WailmerLaunch_58_ResetTilemap();
//extern ? IntroScene9BallFlight_59_LoadSkySpeedOrbs();
//extern ? IntroScene9BallFlight_InitVars();
//extern ? IntroScene9BallFlight_60_MoveBallAndSky();
//extern ? IntroScene9BallFlight_61_MoveSky();
//extern ? IntroScene9BallFlight_62_MoveBallSkyFadeWhite();
//extern ? nullsub_14();
//extern ? IntroSceneX_64_HoldWhitescreen();
//extern ? IntroSceneX_64_EndIntro();

// asm/libagbsyscall.s

//extern ? CpuSet();
//extern ? LZ77UnCompWram();
//extern ? RegisterRamReset();
//extern ? Sqrt();
//extern ? VBlankIntrWait();

// asm/m4a_1.s

//extern ? umul3232H32();
//extern ? SoundMain();
//extern ? SoundMainRAM();
//extern ? SoundMainBTM();
//extern ? RealClearChain();
//extern ? ply_fine();
//extern ? MPlayJumpTableCopy();
//extern ? ld_r3_tp_adr_i();
//extern ? ply_goto();
//extern ? ply_patt();
//extern ? ply_pend();
//extern ? ply_rept();
//extern ? ply_prio();
//extern ? ply_tempo();
//extern ? ply_keysh();
//extern ? ply_voice();
//extern ? ply_vol();
//extern ? ply_pan();
//extern ? ply_bend();
//extern ? ply_bendr();
//extern ? ply_lfodl();
//extern ? ply_modt();
//extern ? ply_tune();
//extern ? ply_port();
//extern ? m4aSoundVSync();
//extern ? MPlayMain();
//extern ? TrackStop();
//extern ? ChnVolSetAsm();
//extern ? ply_note();
//extern ? ply_endtie();
//extern ? clear_modM();
//extern ? ld_r3_tp_adr_i();
//extern ? ply_lfos();
//extern ? ply_mod();

// asm/m4a_3.s

//extern ? CgbSound();

// asm/options.s

extern void Options_Main();
//extern ? Options_LoadGraphics();
extern void Options_InitStates(void);
//extern ? Options_HandleInput();
//extern ? Options_State2_51C3C();
//extern ? Options_State3_51C60();
extern void UpdateOptionsSpritePositions(void);
extern void CaptureButtonConfigInput(void);
extern void InitCustomButtonConfigDisplay(void);
extern void SetButtonConfigInputs(s8);

// asm/pokedex.s

extern void PokedexMain(void);
//extern ? LoadPokedexGraphics();
extern void InitPokedexState(void);
//extern ? Pokedex_HandleListInput();
//extern ? Pokedex_PostScrollRefresh();
//extern ? Pokedex_InfoWindowSlideIn();
//extern ? Pokedex_DetailViewInput();
//extern ? Pokedex_InfoWindowSlideOut();
//extern ? Pokedex_LinkSetup();
//extern ? Pokedex_LinkTransferLoop();
//extern ? Pokedex_LinkRetryDelay();
//extern ? Pokedex_LinkErrorTimeout();
//extern ? Pokedex_LinkSuccessSequence();
//extern ? Pokedex_DeleteConfirmation();
//extern ? Pokedex_ReturnToTitle();
//extern ? BlitGlyphToTileBuffer();
extern void LoadMonAnimationSprite(s16);
extern s16 CheckMonHasAnimation(s16);
extern void ResetPokedex(void);

// asm/rom_1068C.s

extern void CopyString(int, int, int, int, int, int);
void SetStringPalette(int, int, int, int, u16);
extern void CopyBgTilesRect(void *volatile, void *volatile, s16, s16);
//extern ? FadeOutToWhite();
extern void ClearHighScoreNameEntry(void);

// asm/rom_11B9C.s

//extern ? InitFrameProcess5_BallMovement_AllBoards();
extern void InitBallState(s16);
//extern ? UpdateFrameProcess5_BallMovement_MainBoards();
extern void InitFrameProcess6_Collision_AllBoards();
extern void UpdateFrameProcess6_Collision_AllBoards();
extern u16 DetectBallCollision(struct Vector16*);
extern void ComputeFlipperBounce(struct Vector16*, struct Vector16*, s16);
extern void ComputeWallReflection(u16, struct Vector16*, struct Vector16*);
extern void ApplyBounceBackForce(u16, struct Vector32*, u16);
extern u16 PixelWalkCollisionDetection(struct Vector16*, struct Vector16);
extern u16 CheckFlipperCollision(struct Vector16*, u16*);
extern u16 CheckCatchTargetCollision(struct Vector16*, u16*);
extern void ProcessBonusTrapPhysics(void);
extern u16 LookupFlipperCollisionMap(struct Vector16 r0, s16 r1, u16 *r2, s16 r3);
//extern ? ComputeFlipperLaunchVelocity();
//extern ? CollisionCheck_Ruby();
void CheckRubyBoardCollision(struct Vector16*, u16*, u8*);
void ProcessRubyCollisionEvent(u8, s16*, u16*);
//extern ? CollisionCheck_Sapphire();
extern void CheckSapphireBumperCollision(struct Vector16 *arg0, s16* arg1, u8* arg2);
extern void ProcessSapphireCollisionEvent(u8, u16*, u16*);
//extern ? CollisionCheck_Dusclops();
extern void CheckDusclopsEntitiesCollision(struct Vector16 *arg0, s16* arg1, u8* arg2);
extern void CheckDusclopsAbsorbZoneHit(u8, u16*, u16*);
//extern ? CollisionCheck_Kecleon();
extern void CheckKecleonEntityCollision(struct Vector16 *, u16 *, u8 *);
extern void ProcessKecleonBallDisturbanceCollisionEvent(u8, u16 *, u16 *);
extern void ProcessKecleonSkulkingDisturbanceCollisionEvent(struct Vector16 *);
//extern ? CollisionCheck_Kyogre();
extern void CheckKyogreEntityCollision(struct Vector16 *, u16 *, u8 *);
extern void ProcessKyogreCollisionEvent(u8, u16 *, u16 *);
//extern ? CollisionCheck_Groudon();
extern void CheckGroudonEntityCollision(struct Vector16 *, u16 *, u8 *);
extern void ProcessGroudonCollisionEvent(u8, u16 *, u16 *);
extern s16 CollisionCheck_Rayquaza(struct Vector16*, u16*);
extern void CheckRayquazaEntityCollision(struct Vector16*, u16*, u8*);
extern void ProcessRayquazaCollisionEvent(u8, u16*, u16*);
extern s16 CollisionCheck_Spheal(struct Vector16*, u16*);
extern void CheckSphealEntityCollision(struct Vector16*, u16*, u8*);
extern void ProcessSphealCollisionEvent(u8, u16*, u16*);
extern void PinballGameMain();
extern void IdlePinballGameMain();
extern void PinballGameIdle0_19048(void);//gMain.subState = 0
extern void PinballGameIdle1_19190(void);//gMain.subState = 1
extern void PinballGame_State2_4ABC8(void);//gMain.subState = 2
extern void PinballGameIdle3_19288(void);//gMain.subState = 3
//extern ? InitFrameProcess4_FlipperLogic_AllBoards();
extern void DetermineFlipperBallSide(struct Vector16 arg0);
//extern ? UpdateFrameProcess4_FlipperLogic_MainBoards();
extern void UpdateMainBoardFlipperPhysics(void);
extern void UpdateFrameProcess4_FlipperLogic_BonusBoards(void);
extern void UpdateBonusBoardFlipperPhysics(void);
//extern ? InitFrameProcess3_BoardLogic_RubyBoard();
//extern ? UpdateFrameProcess3_BoardLogic_RubyBoard();
extern void RequestBoardStateTransition(u8);
extern void BoardStateDispatcher(void);
//extern ? InitFieldIdle();
//extern ? UpdateFieldIdle();
//extern ? HandleBoardStateTransitionTeardown();
//extern ? UpdateRubyBoardEntityRendering();
//extern ? UpdateRubyBoardEntityLogic();
//extern ? HandleRubyFlipperButtonInput();
extern void ProcessBannerCameraTransition(void);
//extern ? RenderBannerSlideAnimation();

extern void DispatchRubyCatchModeInit();
extern void UpdateRubyCatchModeAnimation(void);
//extern ? InitSharpedoCatchMode();
extern void AnimateSharpedoCatchSequence();
extern void InitRubyEggHatchMode(void);
//extern ? AnimateEggHatchSequence();
//extern ? InitRubyEvolutionShopMode();
//extern ? AnimateRubyEvolutionShopSequence();
extern void UpdateShopEntryAnimation(s16);
extern void InitCenterTrapMode(void);
extern void AnimateCenterTrapSequence(void);
extern void TransitionToBonusField(void);
extern void LoadPortraitGraphics(s16, s16);
extern void UpdatePortraitSpritePositions(void);
extern void ClampPortraitSpritesToOffscreen(void);
//extern ? UpdateNuzleafEntity();
//extern ? SelectShopDoorState();
//extern ? AnimateShopDoor();
//extern ? DrawWhiscash();
//extern ? RubyPond_EntityLogic();
//extern ? RubyPondTriBumperHandleHitAndDraw();
//extern ? AnimateSharpedoEntity();
extern void UpdatePikachuChargeCounter();
extern void DrawPikachuSpinner();
//extern ? UpdateChikoritaAttackAnimation();
//extern ? AnimateChikoritaSprite();
//extern ? UpdateGulpinBossState();
//extern ? UpdateSideBumperAnimation();
//extern ? DrawSideBumperSprites();
extern void UpdateKickbackLogic();
extern void PichuArrivalSequence();
extern void ResetCatchState(s16);
//extern ? InitCatchTrigger();
//extern ? UpdateCatchTrigger();
extern void FullCatchStateCleanup(void);
//extern ? InitBonusStageSelect();
//extern ? UpdateBonusStageSelect();
extern void ShowBonusTrapSprite(void);
extern void AnimateBonusTrapSprite(void);
extern void ProcessChargeIndicator();
//extern ? UpdateRubyEvolutionShopSignSprite();
extern void RenderMartUI(s16);
extern void AnimateCoinReward();
extern void InitTotodileEggDelivery();
//extern ? AnimateTotodileEggDelivery();
//extern ? InitAerodactylEggDelivery();
//extern ? AnimateAerodactylEggDelivery();
extern void LoadPokemonNameGraphics();
extern void UpdatePokemonNamePosition();
extern void HidePokemonNameDisplay();
extern void InitWasCaughtBanner(void);
extern void AnimateWasCaughtBanner(void);
extern void InitRubyEggHatchAnimation(void);
//extern ? UpdateRubyEggHatchAnimation();
//extern ? UpdateHatchCave();
extern void CleanupEggModeState(void);
//extern ? InitEggMode();
//extern ? UpdateEggMode();
extern void DisableCatchTileDisplay(void);
extern void RevealCatchTilesSequential(void);
extern void RevealCatchTilesBurst(void);
//extern ? InitBoardIntroMode();
//extern ? UpdateBoardIntroMode();
extern void UpdateBoardArrowAnimState(void);
extern void SetBoardArrowState(s16);
extern void CleanupTravelModeState(void);
//extern ? InitTravelMode();
//extern ? UpdateTravelMode();
extern void CleanupEvolutionModeState(void);
//extern ? InitEvolutionMode();
//extern ? UpdateEvolutionMode();
extern void UpdateEvolutionItemAnimation(void);
extern void CleanupCatchEmState(void);
//extern ? InitCatchEmMode();
//extern ? UpdateCatchEmMode();
//extern ? InitJirachiBonus();
//extern ? UpdateJirachiBonus();
extern void LoadCatchSpriteGraphics(void);
extern void LoadMonFieldSpriteGraphics(void);
extern void DrawCatchMonBoardSprite(void);
extern void CleanupCatchMonBoardSprite(void);
extern void DrawJirachiSprites(void);
extern void CleanupJirachiSprites(void);
extern void CheckCatchTileRevealState(void);
extern void PlayCatchMonAppearsAnimation(void);
extern void ResetCatchFrameState(void);
extern void InitSequentialTileParticles(void);
extern void UpdateSequentialTileParticles(void);
extern void InitBurstTileParticles(void);
extern void UpdateBurstTileParticles(void);
extern void InitRouletteWheel(void);
extern void RunRouletteWheel(void);
extern void GivePrize();
//extern ? sub_2C518();
//extern ? UpdateMakuhitaEntity();
//extern ? DrawRubyRampPrize();
extern void AnimateOneUpSprite();
extern void AnimateBannerSlide(void);
extern void UpdateSpoinkAnimation();
extern void DrawSpoinkSprite();
extern void RunEvolutionCutscene(void);
//extern ? sub_2DE54();
extern void RunTravelPaintEventCutscene(void);
extern void DecrementPelipperTimer();
extern void UpdatePelipperPondEntity();
extern void AnimateWailmerEntity();
extern void UpdateZigzagoonEntity();
extern void DrawZigzagoonAndRouletteStopPrompt();
extern void UpdateSapphireShopGateLogic();
extern void DrawSapphireShopGuards();
extern void CalculateRubyBumperBounce();
extern void HandleSapphireBumperHit();
extern void InitSapphireEggHatchAnimation();
extern void UpdateSapphireEggHatchAnimation();
extern void UpdateSapphireSeedotCollection();
extern void DrawSapphireSeedotAndBasketSprites();
extern void UpdateSapphireShopSignAnimation();
extern void DrawSapphireShopSignSprite(void);
extern void UpdateSapphireHatchMachine();
extern void DrawBoardEdgeBanner(void);
extern void RestoreBoardObjPalettes(s16);
extern void RegisterCaptureOrEvolution(s16);

extern void BuildSpeciesWeightsForCatchEmMode(void);

// asm/rom_3219C.s

extern void BuildSpeciesWeightsForEggMode(void);
extern void PickSpeciesForEggMode(void);
//extern ? InitFrameProcess3_BoardLogic_SapphireBoard();
//extern ? UpdateFrameProcess3_BoardLogic_SapphireBoard();
extern void UpdateSapphireBoardEntityRendering();
extern void UpdateSapphireBoardEntityLogic();
extern void DispatchSapphireCatchModeInit();
extern void UpdateSapphireCatchModeAnimation();
extern void InitSapphireEvolutionShopCatch();
extern void UpdateSapphireEvolutionShopSequence();
extern void InitSapphireWailmerCatch();
extern void UpdateSapphireWailmerCatchSequence();
//extern ? InitFrameProcess3_BoardLogic_DusclopsBoard();
//extern ? UpdateFrameProcess3_BoardLogic_DusclopsBoard();
extern void SwapDuskullEntityIndex(s16 index1, s16 index2);
extern void DuskullPhase_ProcessEntityLogic();
extern void DuskullPhase_ProcessGraphics();
extern void DusclopsPhase_ProcessEntityLogicAndGraphics();
extern void FadeToMainBoard();
extern void ProcessBonusBannerAndScoring();
extern void HideDusclopsSprites();
extern void TransitionFromBonusToMainBoard(void);
//extern ? InitFrameProcess3_BoardLogic_KecleonBoard();
//extern ? UpdateFrameProcess3_BoardLogic_KecleonBoard();
//extern ? UpdateKecleonEntityLogic();
//extern ? UpdateKecleonScopeItem();
//extern ? UpdateKecleonScopeVision();
//extern ? RenderKecleonBoardElements();
//extern ? SortKecleonSpritesByY();
//extern ? InitFrameProcess3_BoardLogic_KyogreBoard();
//extern ? UpdateFrameProcess3_BoardLogic_KyogreBoard();
extern void UpdateKyogreEntityLogic(void);
extern void RenderKyogreSprites(void);
extern void UpdateKyogreFieldEntities(void);
//extern ? sub_3A150();
extern void HideKyogreSplashSprite(void);
extern void AnimateKyogreBackground(void);
//extern ? InitFrameProcess3_BoardLogic_GroudonBoard();
//extern ? UpdateFrameProcess3_BoardLogic_GroudonBoard();
extern void UpdateGroudonEntityLogic(void);
extern void RenderGroudonSprites(void);
extern void UpdateGroudonFieldEntities(void);
extern void HideGroudonShockwaveSprite(void);
extern void AnimateGroudonBackground(void);
//extern ? InitFrameProcess3_BoardLogic_RayquazaBoard();
//extern ? UpdateFrameProcess3_BoardLogic_RayquazaBoard();
extern void UpdateRayquazaEntityLogic(void);
extern void RenderRayquazaSprites(void);
extern void UpdateRayquazaMinionsAndEffects(void);
extern void UpdateLightningGrabEntity(void);
extern void RenderWindCloudSprites(void);
extern void UpdateRayquazaIntroSequence(void);
//extern ? InitFrameProcess3_BoardLogic_SphealBoard();
//extern ? UpdateFrameProcess3_BoardLogic_SphealBoard();
extern void UpdateSealeoEntityLogic(void);
extern void UpdateSphealEntityLogic(void);
extern void UpdateSphealScoreAndDelivery(void);
extern void SphealBoard_WhiscashDeliversBall(void);
extern void SphealBoard_PelipperDeliversBall(void);
extern void UpdateSealeoKnockdownPhysics(void);
extern void AnimateSphealBackground(void);
extern void UpdateSphealResultsScreen(void);
extern void loadFieldBoardGraphics(void);
extern void SetBoardCollisionConfig(s16);
extern void UpdateScrollingBackgroundTiles(void);
//extern ? InitFrameProcess1_PauseLogic_AllBoards();
//extern ? UpdateFrameProcess1_PauseLogic_AllBoards();
extern void BonusStage_HandleModeChangeFlags();
extern void DebugMenu_RenderAndHandleInput(void);
extern void GameOverAnimation(void);
extern void EndOfBallSequence(void);
extern void BallSaverAnimation(void);
extern void ClearDebugTextDisplay(void);
extern void DebugMoveBallPosition(void);
extern void DebugToggleBallSpeed(void);
extern void EndOfBallBonusSummary(void);
extern void PauseGame(void);
extern void UnpauseGame(void);
extern void PositionPauseMenuSprites(void);
extern void AnimatePauseMenuOverlay(void);
extern void IdleGameFrameUpdate();
extern void IdleBonusFieldFrameUpdate();
extern void SaveGameStateSnapshot(s16);
//extern ? InitFrameProcess8_HudUpdate_AllBoards();
extern void UpdateFrameProcess8_HudUpdate_AllBoards(void);
extern void PinballGame_State0_49ED4(void);
extern void ProcessEventTimer(void);
extern void ResetEventState(void);
//extern ? InitFrameProcess2_CameraShakeDrain_AllBoards();
//extern ? UpdateFrameProcess2_CameraShakeDrain_MainBoards();
//extern ? UpdateFrameProcess2_CameraShakeDrain_BonusBoards();
extern void ProcessTiltInput(void);
extern void ProcessMainBoardBallDrainAndLaunch(void);
extern void ProcessBonusBoardBallDrain(void);
extern void ResetBoardStateOnDeath(void);
extern void UpdateRubyBoardAnimations(void);
extern void AnimateRubySlingshotHit(void);
extern void LoadShopItemGraphics(s16);
extern void DrawRubyProgressDigits(void);
extern void AnimateRubyTrapIndicator(void);
extern void AnimateRubyCatchLightBlink(void);
extern void AnimateRubyHoleIndicators(void);
extern void DrawRubyModeTimerDisplay(void);
extern void AnimateRubyCatchArrowPalette(void);
extern void AnimateRubyEvoArrowPalette(void);
extern void AnimateRubyShopRampArrow(void);
extern void AnimateRubyCatchProgressArrow(void);
extern void AnimateRubyBallPowerUpSequence(void);
extern void DrawRubyBallPowerUpLights(void);
extern void UpdateCoinRewardTimer(void);
extern void DrawRubyCoinRewardMeter(void);
extern void DrawRubyEvoArrowProgress(void);
extern void DrawRubyCatchArrowProgress(void);
extern void UpdateSapphireBoardAnimations(void);
extern void DrawSapphireProgressDigits(void);
extern void AnimateSapphireSlingshotHit(void);
extern void AnimateSapphireTrapIndicator(void);
extern void AnimateRotatingBackground(void);
extern void AnimateSapphireCatchLightBlink(void);
extern void AnimateSapphireHoleIndicators(void);
extern void DrawSapphireModeTimerDisplay(void);
extern void DrawSapphireCoinRewardMeter(void);
extern void AnimateSapphireHatchArrow(void);
extern void AnimateSapphireBumperArrowPalette(void);
extern void DrawSapphireEvoArrowProgress(void);
extern void DrawSapphireCatchArrowProgress(void);
extern void AnimateSapphireHatchArrowFlash(void);
extern void AnimateSapphireShopArrow(void);
extern void DrawSapphireBallPowerUpLights(void);
extern void AnimateHatchMachineSpinner(void);
extern void AnimatePelipperBumper(void);
extern void InitFrameProcess0_DefaultSpriteState_RubyBoard(void);
//extern ? UpdateFrameProcess0_DefaultSpriteState_RubyBoard();
extern void InitFrameProcess0_DefaultSpriteState_SapphireBoard(void);
//extern ? UpdateFrameProcess0_DefaultSpriteState_SapphireBoard();
extern void InitFrameProcess0_DefaultSpriteState_DusclopsBoard(void);
//extern ? UpdateFrameProcess0_DefaultSpriteState_DusclopsBoard();
extern void InitFrameProcess0_DefaultSpriteState_KecleonBoard(void);
//extern ? nullsub_20();
extern void InitFrameProcess0_DefaultSpriteState_KyogreBoard(void);
//extern ? UpdateFrameProcess0_DefaultSpriteState_KyogreBoard();
extern void InitFrameProcess0_DefaultSpriteState_GroudonBoard(void);
//extern ? UpdateFrameProcess0_DefaultSpriteState_GroudonBoard();
extern void InitFrameProcess0_DefaultSpriteState_RayquazaBoard(void);
//extern ? UpdateFrameProcess0_DefaultSpriteState_RayquazaBoard();
extern void InitFrameProcess0_DefaultSpriteState_SphealBoard(void);
//extern ? UpdateFrameProcess0_DefaultSpriteState_SphealBoard();

// asm/rom_528AC.s

//extern ? SpeciesRSToCryId();
void PlayCry_Normal(u16, s8);
extern void PlayCry_NormalNoDucking(u16, s8, s8, u8);
//extern ? PlayCryInternal();
extern void SaveFile_LoadGameData(void);
//extern ? LoadSaveDataFromSram();
extern void SaveFile_WriteToSram(void);
extern void SaveFile_SetPokedexFlags(s16, u8);
extern void SaveFile_ReadSavedGamePresent(void);
extern void ResetSaveFile(void);

// asm/rom_9BC.s

//extern void sub_13FC(void); // dead declaration — no definition or call sites
//extern ? Sio32EncodePacket();
//extern ? Sio32ValidateResponse();
//extern ? Sio32VerifyChecksum();
//extern ? Sio32BuildCommand();
//extern ? EncodeRumbleCommand();
extern void Sio32TimeoutIntr(void);
extern s16 LoadSpriteSetsWithCpuCopy(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups);
//extern ? nullsub_16();
extern void ResetSerialIO(void);
extern void SetupDefaultInterrupts(void);
extern void ResetLinkState(void);
extern void ResetSerialAndInterrupts(void);

// asm/start.s


// asm/titlescreen.s

//extern ? RenderTitlePressStartSprites();
extern void RenderTitleMenuNoSavedGame(void);
extern void RenderTitleMenuSavedGame(void);
extern void DeleteSaveFile(void);

#endif  // GUARD_FUNCTIONS_H
