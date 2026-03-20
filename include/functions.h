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
void TitleScreen2_AnimOpenMenu(void);
void TitleScreen9_DeleteSaveConfirmation(void);
void TitleScreen3_8010E00(void);
void TitleScreen4_MenuInputNoSavedGame(void);
void TitleScreen7_8011020(void);
void TitleScreen5_MenuInputSavedGame(void);
void TitleScreen8_8011228(void);
void TitleScreen6_AnimCloseMenu(void);
void TitleScreen10_ExecMenuSelection(void);
void TitleScreen11_80114B4(void);

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
extern void BonusFieldSelect_State1_2768(void);
extern void BonusFieldSelect_State2_2990(void);
extern void RenderBonusFieldSelectSprites(void);

// src/ereader.c

extern void EReaderMain(void);
extern void LoadEReaderGraphics(void);
extern void InitEReaderTextState(void);
extern void Ereader_State1_2E40(void);
extern void Ereader_State2_2FC0(void);
extern void Ereader_State3_304C(void);
extern void Ereader_State4_3208(void);
extern void Ereader_State5_33A0(void);
extern void Ereader_State6_343C(void);
extern void Ereader_State7_33C8(void);
extern void Ereader_State8_374C(void);
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
extern void FadeInWithCustomPalettes(u8 *, u8 *, void (*func)(void));
extern void FadeOutToBlack(void (*func)(void));
extern void InterpolatePaletteStep(u16);
extern void DarkenPalette(u8 *, u8 *, u16, u16); // Very much subject to change
extern void BrightenPalette(u8 *, u8 *, u16, u16);
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
extern void IntroScene1_LoadGraphics(void);
extern void IntroScene1_InitVars(void);

// asm/intro.s

extern void IntroScene1_AnimateTitleReveal(void);
extern void IntroScene1_ZoomOutTitle(void);
extern void IntroScene1_ResetAfterZoom(void);
extern void IntroScene1_AnimateSecondReveal(void);
extern void IntroScene1_FadeInOverlay(void);
extern void IntroScene1_ScrollAndFade(void);
extern void IntroScene1_ParallaxScroll(void);
extern void nullsub_4(void);
//extern ? IntroScene1_FinalScroll();
//extern ? nullsub_5();
//extern ? nullsub_17();
//extern ? IntroScene1_BeginFadeOut();
extern void IntroScene1_RenderTitleSprite(void);
extern void IntroScene1_RenderScaledTitle(void);
extern void IntroScene1_RenderAllSprites(void);
//extern ? IntroScene1_ClearGraphics();
//extern ? IntroScene2_LoadGraphics();
extern void IntroScene2_InitVars(void);
//extern ? nullsub_6();
//extern ? IntroScene2_ScrollBGs();
//extern ? nullsub_7();
//extern ? IntroScene2_FinalScrollAndFade();
//extern ? IntroScene2_ClearGraphics();
//extern ? IntroScene3_LoadGraphics();
//extern ? IntroScene3_InitVars();
//extern ? IntroScene3_ScrollIn();
//extern ? IntroScene3_AnimateAndSwapBG();
//extern ? nullsub_8();
//extern ? IntroScene3_BeginFadeOut();
//extern ? IntroScene3_RenderPokeball();
//extern ? IntroScene3_ClearGraphics();
//extern ? IntroScene4_LoadGraphics();
//extern ? IntroScene4_InitVars();
//extern ? nullsub_9();
//extern ? IntroScene4_ScrollBGs();
//extern ? nullsub_10();
//extern ? IntroScene4_FinalScrollAndFade();
//extern ? IntroScene4_ClearGraphics();
//extern ? IntroScene5_LoadGraphics();
//extern ? IntroScene5_InitVars();
//extern ? IntroScene5_ScrollIn();
//extern ? IntroScene5_AnimateEntities();
//extern ? nullsub_11();
//extern ? IntroScene5_FadeOutAndClearOAM();
//extern ? IntroScene5_RenderAllSprites();
//extern ? IntroScene5_ClearGraphics();
//extern ? IntroScene6_LoadGraphics();
//extern ? IntroScene6_InitVars();
//extern ? IntroScene6_AnimateStarsScrollIn();
//extern ? IntroScene6_ContinueBounce();
//extern ? IntroScene6_FadeOutAndClearOAM();
//extern ? IntroScene6_RenderStarSprites();
//extern ? IntroScene6_AdvanceIndex();
//extern ? IntroScene7_LoadGraphics();
//extern ? IntroScene7_InitVars();
//extern ? IntroScene7_ScrollWaves1();
//extern ? IntroScene7_ScrollWaves2();
//extern ? IntroScene7_ScrollWaves3();
//extern ? IntroScene7_WailmerAndAllWaves();
//extern ? IntroScene7_WailmerShakeAndShrink();
//extern ? IntroScene7_BeginFadeOut();
//extern ? IntroScene7_RenderWailmer();
//extern ? IntroScene7_ClearGraphics();
//extern ? IntroScene8a_LoadGraphics();
//extern ? IntroScene8a_InitVars();
//extern ? IntroScene8a_WaitForExplosion();
//extern ? IntroScene8a_ExplodeAndLaunch();
//extern ? IntroScene8a_DriftAndFade();
//extern ? nullsub_12();
//extern ? nullsub_13();
//extern ? IntroScene8a_FadeOutAndClearOAM();
//extern ? IntroScene8a_RenderAllSprites();
//extern ? IntroScene8a_ClearAndResetOAM();
//extern ? IntroScene8b_LoadGraphics();
//extern ? IntroScene8b_InitVars();
//extern ? IntroScene8b_BallFlyIn();
//extern ? IntroScene8b_ScrollClouds();
//extern ? IntroScene8b_CloudSpriteAndWhiteFlash();
//extern ? nullsub_14();
//extern ? IntroScene8b_FadeOutMusic();
//extern ? IntroScene8b_EndIntro();

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

//extern ? Options_Main();
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

//extern ? AllBoardProcess_5A_11B9C();
extern void InitBallState(s16);
//extern ? MainBoardProcess_5B_11C98();
extern void AllBoardProcess_6A_4CEA8();
extern void AllBoardProcess_6B_1333C();
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
void CheckRubyPondBumperCollision(struct Vector16*, u16*, u8*);
void ProcessRubyCollisionEvent(s32, s16*, u16*);
//extern ? CollisionCheck_Sapphire();
extern void CheckSapphireBumperCollision(struct Vector16 *arg0, s16* arg1, u8* arg2);
extern void ProcessSapphireCollisionEvent(u8, u16*, u16*);
//extern ? CollisionCheck_Dusclops();
extern void CheckDusclopsEntitiesCollision(struct Vector16 *arg0, s16* arg1, u8* arg2);
extern void CheckDusclopsAbsorbZoneHit(u8, u16*, u16*);
//extern ? CollisionCheck_Kecleon();
extern void CheckKecleonEntityCollision(struct Vector16 *, u16 *, u8 *);
extern void ProcessKecleonCollisionEvent(u8, u16 *, u16 *);
extern void CheckKecleonProjectileCollision(struct Vector16 *);
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
extern void IdlePinballGameMain();
extern void PinballGameIdle0_19048(void);//gMain.subState = 0
extern void PinballGameIdle1_19190(void);//gMain.subState = 1
extern void PinballGame_State2_4ABC8(void);//gMain.subState = 2
extern void PinballGameIdle3_19288(void);//gMain.subState = 3
//extern ? AllBoardProcess_4A_19304();
extern void DetermineFlipperBallSide(struct Vector16 arg0);
//extern ? MainBoardProcess_4B_19490();
extern void UpdateMainBoardFlipperPhysics(void);
extern void BonusBoardProcess_4B_19734(void);
extern void UpdateBonusBoardFlipperPhysics(void);
//extern ? RubyBoardProcess_3A_19A20();
//extern ? RubyBoardProcess_3B_19B10();
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
//extern ? UpdateEvolutionShopSprite();
extern void RenderEvolutionUI(s16);
extern void AnimateCoinReward();
extern void InitTotodileEggDelivery();
//extern ? AnimateTotodileEggDelivery();
//extern ? InitAerodactylEggDelivery();
//extern ? AnimateAerodactylEggDelivery();
extern void LoadPokemonNameGraphics();
extern void UpdatePokemonNamePosition();
extern void HidePokemonNameDisplay();
extern void InitEvolutionSuccessDisplay(void);
extern void AnimateEvolutionSuccessScreen(void);
extern void InitRubyEggModeAnimation(void);
//extern ? UpdateEggModeAnimation();
//extern ? UpdateHatchCave();
extern void CleanupEggModeState(void);
//extern ? InitEggMode();
//extern ? UpdateEggMode();
extern void DisableHatchTileDisplay(void);
extern void RevealSequentialHatchTiles(void);
extern void RevealAllHatchTilesAtOnce(void);
//extern ? InitAreaRoulette();
//extern ? UpdateAreaRoulette();
extern void UpdateRouletteAnimState(void);
extern void SetRouletteActiveState(s16);
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
extern void LoadEggSpriteGraphics(void);
extern void DrawCaughtPokemonSprite(void);
extern void CleanupCaughtPokemonSprite(void);
extern void DrawJirachiSprites(void);
extern void CleanupJirachiSprites(void);
extern void CheckHatchTileRevealState(void);
extern void PlayEggCrackAnimation(void);
extern void ResetHatchFrameState(void);
extern void InitSequentialTileParticles(void);
extern void UpdateSequentialTileParticles(void);
extern void InitBurstTileParticles(void);
extern void UpdateBurstTileParticles(void);
extern void InitRouletteWheel(void);
extern void RunRouletteWheel(void);
extern void ProcessRouletteOutcome();
//extern ? sub_2C518();
//extern ? UpdateRubyRampPrizeGate();
//extern ? DrawRubyNuzleafPlatformSprite();
extern void AnimateOneUpSprite();
extern void AnimateBannerSlide(void);
extern void UpdateSpoinkAnimation();
extern void DrawSpoinkSprite();
extern void RunEvolutionCutscene(void);
//extern ? sub_2DE54();
extern void RunTravelEventCutscene(void);
extern void DecrementPelipperTimer();
extern void UpdatePelipperPondEntity();
extern void AnimateWailmerEntity();
extern void UpdateZigzagoonEntity();
extern void DrawZigzagoonAndRouletteStopPrompt();
extern void UpdateSapphireBumperLogic();
extern void DrawSapphireBumperSprites();
extern void CalculateRubyBumperBounce();
extern void HandleRubyBumperHit();
extern void InitSapphireEggHatchState();
extern void UpdateSapphireEggHatchAnimation();
extern void UpdateSapphireSeedotCollection();
extern void DrawSapphireSeedotAndBasketSprites();
extern void UpdateSapphireShopSignAnimation();
extern void DrawSapphireShopSignSprite(void);
extern void UpdateSapphireEggMachine();
extern void DrawBoardEdgeBanner(void);
extern void RestoreBoardObjPalettes(s16);
extern void RegisterCaptureOrEvolution(s16);

extern void BuildSpeciesWeightsForCatchEmMode(void);

// asm/rom_3219C.s

extern void BuildSpeciesWeightsForEggMode(void);
extern void PickSpeciesForEggMode(void);
//extern ? SapphireBoardProcess_3A_326F4();
//extern ? SapphireBoardProcess_3B_3276C();
extern void UpdateSapphireBoardEntityRendering();
extern void UpdateSapphireBoardEntityLogic();
extern void DispatchSapphireCatchModeInit();
extern void UpdateSapphireCatchModeAnimation();
extern void InitSapphireEvolutionShopCatch();
extern void UpdateSapphireEvolutionShopSequence();
extern void InitSapphireWailmerCatch();
extern void UpdateSapphireWailmerCatchSequence();
//extern ? DuskullBonus_Setup();
//extern ? DusclopsBoardProcess_3B_33130();
extern void SwapDuskullEntityIndex(s16 index1, s16 index2);
extern void DuskullPhase_ProcessEntityLogic();
extern void DuskullPhase_ProcessGraphics();
extern void DusclopsPhase_ProcessEntityLogicAndGraphics();
extern void FadeToMainBoard();
extern void ProcessBonusBannerAndScoring();
extern void RenderBonusStageOverlaySprites();
extern void TransitionFromBonusToMainBoard(void);
//extern ? KecleonBoardProcess_3A_35860();
//extern ? KecleonBoardProcess_3B_35AA4();
//extern ? UpdateKecleonEntityLogic();
//extern ? UpdateKecleonScopeItem();
//extern ? UpdateKecleonScopeVision();
//extern ? RenderKecleonBoardElements();
//extern ? SortKecleonSpritesByY();
//extern ? KyogreBoardProcess_3A_383E4();
//extern ? KyogreBoardProcess_3B_3869C();
extern void UpdateKyogreEntityLogic(void);
extern void RenderKyogreSprites(void);
extern void UpdateKyogreFieldEntities(void);
//extern ? sub_3A150();
extern void HideKyogreSplashSprite(void);
extern void AnimateKyogreBackground(void);
//extern ? GroudonBoardProcess_3A_3B120();
//extern ? GroudonBoardProcess_3B_3B49C();
extern void UpdateGroudonEntityLogic(void);
extern void RenderGroudonSprites(void);
extern void UpdateGroudonFieldEntities(void);
extern void HideGroudonShockwaveSprite(void);
extern void AnimateGroudonBackground(void);
//extern ? RayquazaBoardProcess_3A_3E79C();
//extern ? RayquazaBoardProcess_3B_3EB2C();
extern void UpdateRayquazaEntityLogic(void);
extern void RenderRayquazaSprites(void);
extern void UpdateRayquazaMinionsAndEffects(void);
extern void UpdateWhirlwindGrabEntity(void);
extern void RenderWindCloudSprites(void);
extern void UpdateRayquazaIntroSequence(void);
//extern ? SphealBoardProcess_3A_42E48();
//extern ? SphealBoardProcess_3B_43228();
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
//extern ? AllBoardProcess_1A_47100();
//extern ? AllBoardProcess_1B_47160();
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
//extern ? AllBoardProcess_8A_4CEA8();
extern void AllBoardProcess_8B_4CEB4(void);
extern void PinballGame_State0_49ED4(void);
extern void ProcessEventTimer(void);
extern void ResetEventState(void);
//extern ? AllBoardProcess_2A_4D6C4();
//extern ? MainBoardProcess_2B_4D960();
//extern ? BonusBoardProcess_2B_4DBFC();
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
extern void AnimateRubyRouletteSlot(void);
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
extern void AnimateSapphireCatchArrowPalette(void);
extern void AnimateSapphireEvoArrowPalette(void);
extern void DrawSapphireEvoArrowProgress(void);
extern void DrawSapphireCatchArrowProgress(void);
extern void AnimateSapphireCatchArrowPaletteFlash(void);
extern void AnimateSapphireRouletteSlot(void);
extern void DrawSapphireBallPowerUpLights(void);
extern void AnimateHatchMachineSpinner(void);
extern void AnimatePelliperBumper(void);
extern void RubyBoardProcess_0A_50848(void);
//extern ? RubyBoardProcess_0B_50918();
extern void SapphireBoardProcess_0A_50AD4(void);
//extern ? SapphireBoardProcess_0B_50B80();
extern void DusclopsBoardProcess_0A_50D48(void);
//extern ? DusclopsBoardProcess_0B_50DB8();
extern void KecleonBoardProcess_0A_50DE0(void);
//extern ? nullsub_20();
extern void KyogreBoardProcess_0A_50F04(void);
//extern ? KyogreBoardProcess_0B_50FAC();
extern void GroudonBoardProcess_0A_50FD4(void);
//extern ? GroudonBoardProcess_0B_51068();
extern void RayquazaBoardProcess_0A_51090(void);
//extern ? RayquazaBoardProcess_0B_51128();
extern void SphealBoardProcess_0A_51150(void);
//extern ? SphealBoardProcess_0B_511F8();

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
