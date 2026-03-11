#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H

// Place all external function declarations in this file

// src/gbplayer.c

void InitGameBoyPlayer(void);
void StartGbPlayerCommunication(void);
void ResetGbPlayerState(void);
int IsGbPlayerCommDone(void);
void RestoreDefaultInterrupts(void);
void PlayRumble(int arg0);
void SetGbPlayerMotorMode(int arg0);
void SetGbPlayerPaused(int arg0);
void UpdateGbPlayerRumble(void);
void InitGbPlayerSerialComm(void);
extern u32 ValidateGbPlayerResponse(u8 param_1);
extern u32 GetGbPlayerCommResult(u8 param_1);
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
void DisableVBlankProcessing(void);
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
void TitleScreen2_8010CF0(void);
void TitleScreen9_8010D84(void);
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
void FadeInFromWhite(void);
void FadeOutToWhite(void);
s16 LoadSpriteSets(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups);
void ResetSomeGraphicsRelatedStuff(void);
void ClearGraphicsMemory(void);
void ClearTilemapBuffers(void);
void ClearSprites(void);
void DrawTextToTilemap(u8 *arg0, s16 arg1, s16 arg2);
u8 *IntToDecString(int arg0, u8 *arg1, int arg2, s16 arg3);
void SetMatrixScale(s16 xScale, s16 yScale, s16 matrixNum);

// src/bonus_field_select.s

extern void BonusFieldSelectMain(void);
extern void LoadBonusFieldSelectGraphics(void);
extern void InitBonusFieldSelectState(void);
extern void BonusFieldSelect_State1_2768(void);
extern void BonusFieldSelect_State2_2990(void);
extern void RefreshBonusFieldSelectDisplay(void);

// src/ereader.c

extern void EReaderMain(void);
extern void LoadEReaderGraphics(void);
extern void InitEReaderState(void);
extern void Ereader_State1_2E40(void);
extern void Ereader_State2_2FC0(void);
extern void Ereader_State3_304C(void);
extern void Ereader_State4_3208(void);
extern void Ereader_State5_33A0(void);
extern void Ereader_State6_343C(void);
extern void Ereader_State7_33C8(void);
extern void Ereader_State8_374C(void);
extern void CopyEReaderTextBuffer(void);
extern void RevealAllEReaderText(s8);
extern void RevealNextEReaderTextTile(s8, s8);
extern void CopyEReaderTextTile(s8, u16);
extern s16 GetEReaderCardIndex(void);
extern void UpdateEReaderSprites(void);
extern void UpdateEReaderSpritesOamOnly(void);
extern void InitLinkTransferBuffers(void);
extern s32 PrepareLinkSendData(void);
extern s16 ProcessLinkReceivedData(void);

// src/field_select.s

extern void FieldSelectMain(void);
extern void LoadFieldSelectGraphics(void);
extern void FieldSelect_State1_8C7C(void);
extern void FieldSelect_State2_8F64(void);

// src/high_scores.s
extern void HighScoresMain(void);
extern void IdleHighScoresMain(void);
extern void LoadHighScoreGraphics(void);
extern void InitHighScoreState(void);
extern void HighScore_State1_D20C(void);
extern void HighScore_State2_D308(void);
extern void HighScore_State3_D4B8(void);

// asm/high_scores.s

extern void HighScore_State4_D664(void);
extern void HighScore_State5_D9F8(void);
//extern ? HighScore_State9_DB4C();
//extern ? HighScore_State7_DB70();
//extern ? HighScore_State8_DBF4();
//extern ? HighScore_State10_DCF0();
//extern ? HighScore_State11_DD4C();
//extern ? IdleHighScore_State0_DD70();
extern void InitIdleHighScoreState(void);
//extern ? IdleHighScore_State2_E0C4();
//extern ? HighScore_State12_E0EC();
//extern ? HighScore_State13_E230();
//extern ? HighScore_State14_E390();
extern void UpdateNameEntryCursorSprite(void);
extern void UpdateHighScoreDisplay(void);
extern void UpdateNewHighScoreAnnouncementSprite(void);
extern void InitHighScoreLinkTransferState(void);
extern s16 ProcessHighScoreLinkExchange(void);
extern s16 SendHighScoreLinkData(void);
extern s16 SendHighScoreLinkDataAsMaster();
extern s16 SendHighScoreLinkDataAsClient();
extern s16 ReceiveHighScoreLinkDataAsMaster(void);
extern s16 ReceiveHighScoreLinkDataAsClient(void);
extern void RenderHighScoreNamesAndScores(void);
extern void ConvertScoreToDigitArray(u32, u32);
extern int CompareScores(u32, u32, u32, u32);
extern s32 GetNewHighScoreIndex(u32, u32, u32);
extern void InsertNewHighScoreEntry(u32, u32, u32, int);
extern u32 MergeReceivedHighScore(u32);
extern void PrintHighScoreCharacter(u32, u32, s16, u32);
extern void SetDefaultHighScores(void);
extern void AdjustHighScoreTilemap(u32, u32, s16);
extern void ResetHighScoreTilemapPalette(u32, u32, s16);
extern s8 CheckAllPokemonCaught(void);
extern void FadeInFromWhiteWithCallback(void (*func)(void));
extern void FadeOutToWhiteWithCallback(void (*func)(void));
extern void CustomPaletteFadeTransition(u8 *, u8 *, void (*func)(void));
extern void FadeOutToBlackWithCallback(void (*func)(void));
extern void InterpolatePaletteFade(u16);
extern void ApplyPaletteFadeEffect(u8 *, u8 *, u16, u16); // Very much subject to change
extern void ApplyPaletteWhitenEffect(u8 *, u8 *, u16, u16);
extern void FadeInWithBlend(void);
extern void FadeOutAndClearScreen(void);
extern void UnblankLCD(void);
extern void ForceBlankLDC(void);
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
extern void InitIntroScene1(void);
extern void InitIntroScene1State(void);

// asm/intro.s

extern void IntroScene1_AnimateTitleReveal(void);
extern void IntroScene1_ShrinkTitle(void);
extern void IntroScene1_PauseBeforeBallOpen(void);
extern void IntroScene1_AnimateBallOpen(void);
extern void IntroScene1_RevealBallGlow(void);
extern void IntroScene1_ScrollWithBallAnimation(void);
extern void IntroScene1_PanAndZoomOut(void);
extern void IntroScene1_NoOp1(void);
//extern ? IntroScene1_ScrollStarsOverlay();
//extern ? IntroScene1_NoOp2();
//extern ? IntroScene1_NoOp3();
//extern ? IntroScene1_FadeOutAndDisable();
extern void RenderIntroScene1TitleSprite(void);
extern void RenderIntroScene1ScaledTitleSprite(void);
extern void RenderIntroScene4Sprites(void);
//extern ? IntroScene2_ClearTilemaps();
//extern ? InitIntroScene2();
extern void InitIntroScene2State(void);
//extern ? IntroScene2_NoOp1();
//extern ? IntroScene2_ScrollBgLayers();
//extern ? IntroScene2_NoOp2();
//extern ? IntroScene2_FinalScrollAndFadeOut();
//extern ? IntroScene3_ClearTilemaps();
//extern ? InitIntroScene3();
//extern ? InitIntroScene3State();
//extern ? IntroScene3_PanToTreecko();
//extern ? IntroScene3_TreeckoAnimation();
//extern ? IntroScene3_NoOp();
//extern ? IntroScene3_FadeOutAndDisable();
//extern ? RenderIntroScene3Sprites();
//extern ? IntroScene4_ClearTilemaps();
//extern ? InitIntroScene4();
//extern ? InitIntroScene4State();
//extern ? IntroScene4_NoOp1();
//extern ? IntroScene4_ScrollBgLayers();
//extern ? IntroScene4_NoOp2();
//extern ? IntroScene4_FinalScrollAndFadeOut();
//extern ? IntroScene5_ClearTilemaps();
//extern ? InitIntroScene5();
//extern ? InitIntroScene5State();
//extern ? IntroScene5_PanWithBallReveal();
//extern ? IntroScene5_ContinueBallAndScroll();
//extern ? IntroScene5_NoOp();
//extern ? IntroScene5_FadeOutAndClearOam();
//extern ? RenderIntroScene5Sprites();
//extern ? IntroScene6_ClearTilemaps();
//extern ? InitIntroScene6();
//extern ? InitIntroScene6State();
//extern ? IntroScene6_AnimateStarsEntering();
//extern ? IntroScene6_StarsHoldAndBounce();
//extern ? IntroScene6_FadeOutAndClearOam();
//extern ? RenderIntroScene5PokemonSprites();
//extern ? IntroScene7a_AdvanceIndex();
//extern ? InitIntroScene7a();
//extern ? InitIntroScene7aState();
//extern ? IntroScene7a_ScrollWavesLayer();
//extern ? IntroScene7a_ScrollTwoWaveLayers();
//extern ? IntroScene7a_ScrollAllThreeLayers();
//extern ? IntroScene7a_WailmerAppears();
//extern ? IntroScene7a_WailmerShrinksAndExit();
//extern ? IntroScene7a_FadeOutAndDisable();
//extern ? RenderIntroScene7aPokemonSprite();
//extern ? IntroScene7b_ClearTilemaps();
//extern ? InitIntroScene7b();
//extern ? InitIntroScene7bState();
//extern ? IntroScene7b_WaitThenShowDebris();
//extern ? IntroScene7b_ExplosionAndDebrisFly();
//extern ? IntroScene7b_ExplosionLinger();
//extern ? IntroScene7b_NoOp1();
//extern ? IntroScene7b_NoOp2();
//extern ? IntroScene7b_FadeOutAndClearOam();
//extern ? UpdateIntroScene7Sprites();
//extern ? IntroScene8_ClearAndResetSprites();
//extern ? InitIntroScene8();
//extern ? InitIntroScene8State();
//extern ? IntroScene8_BallFliesIn();
//extern ? IntroScene8_ContinueBgScroll();
//extern ? IntroScene8_LatiasFlyInAndFadeOut();
//extern ? IntroScene8_NoOp();
//extern ? IntroScene8_FadeOutMusic();
//extern ? IntroScene8_EndIntro();

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
extern void RenderOptionsScreenSprites(void);
extern void DetectButtonConfigInput(void);
extern void ConvertCustomButtonConfigToIndices(void);
extern void SetButtonConfigInputs(s8);

// asm/pokedex.s

extern void PokedexMain(void);
//extern ? LoadPokedexGraphics();
extern void InitPokedexState(void);
//extern ? Pokedex_HandleListInput();
//extern ? Pokedex_State2_43D4();
//extern ? Pokedex_State3_4428();
//extern ? Pokedex_State5_45A4();
//extern ? Pokedex_State4_4860();
//extern ? Pokedex_LinkSetup();
//extern ? Pokedex_State7_49D0();
//extern ? Pokedex_State10_4B10();
//extern ? Pokedex_State8_4B34();
//extern ? Pokedex_State9_4BB4();
//extern ? Pokedex_DeleteConfirmation();
//extern ? Pokedex_ReturnToTitle();
//extern ? PlacePokedexTextGlyph();
extern void RenderAnimatedPokemonPortrait(s16);
extern s16 CheckPokemonHasAnimation(s16);
extern void ResetPokedex(void);

// asm/rom_1068C.s

extern void CopyString(int, int, int, int, int, int);
void SetStringPalette(int, int, int, int, u16);
extern void CopyBgTilesRect(void *volatile, void *volatile, s16, s16);
//extern ? FadeOutToWhiteWithCallback_unused();
extern void ClearHighScoreNameEntry(void);

// asm/rom_11B9C.s

//extern ? AllBoardProcess_5A_11B9C();
extern void ResetBallToStartPosition(s16);
//extern ? MainBoardProcess_5B_11C98();
extern void AllBoardProcess_6A_4CEA8();
extern void AllBoardProcess_6B_1333C();
extern u16 TraceBallMovementCollision(struct Vector16*);
extern void ProcessFlipperCollision(struct Vector16*, struct Vector16*, s16);
extern void ComputeCollisionVelocity(u16, struct Vector16*, struct Vector16*);
extern void ApplyCollisionSubtypeVelocity(u16, struct Vector32*, u16);
extern u16 StepTraceCollision(struct Vector16*, struct Vector16);
extern u16 CheckFlipperCollision(struct Vector16*, u16*);
extern u16 CheckPokemonCatchCollision(struct Vector16*, u16*);
extern void ProcessCenterHoleAttraction(void);
extern u16 TestFlipperTileCollision(struct Vector16 r0, s16 r1, u16 *r2, s16 r3);
//extern ? ComputeFlipperLaunchVelocity();
//extern ? COLLISION_CHECK_RUBY_14E08();
void CheckRubyPondBumperCollision(struct Vector16*, u16*, u8*);
void CheckRubyAbsorbZoneHit(s32, s16*, u16*);
//extern ? COLLISION_CHECK_SAPPHIRE_16090();
extern void CheckSapphireBumperCollision(struct Vector16 *arg0, s16* arg1, u8* arg2);
extern void CheckSapphireAbsorbZoneHit(u8, u16*, u16*);
//extern ? COLLISION_CHECK_DUSCLOPS_171C8();
extern void CheckDusclopsEntitiesCollision(struct Vector16 *arg0, s16* arg1, u8* arg2);
extern void CheckDusclopsAbzorbZoneHit(u8, u16*, u16*);
//extern ? COLLISION_CHECK_KECLEON_176B0();
extern void CheckKecleonEntitiesCollision(struct Vector16 *, u16 *, u8 *);
extern void CheckKecleonAbsorbZoneHit(u8, u16 *, u16 *);
extern void ProcessKecleonBoardCollisionFlash(struct Vector16 *);
//extern ? COLLISION_CHECK_KYOGRE_17F28();
extern void CheckKyogreEntitiesCollision(struct Vector16 *, u16 *, u8 *);
extern void CheckKyogreAbsorbZoneHit(u8, u16 *, u16 *);
//extern ? COLLISION_CHECK_GROUDON_18324();
extern void CheckGroudonEntitiesCollision(struct Vector16 *, u16 *, u8 *);
extern void CheckGroudonAbsorbZoneHit(u8, u16 *, u16 *);
extern s16 COLLISION_CHECK_RAYQUAZA_187F4(struct Vector16*, u16*);
extern void CheckRayquazaEntitiesCollision(struct Vector16*, u16*, u8*);
extern void CheckRayquazaAbsorbZoneHit(u8, u16*, u16*);
extern s16 COLLISION_CHECK_SPHEAL_18B50(struct Vector16*, u16*);
extern void CheckSphealEntitiesCollision(struct Vector16*, u16*, u8*);
extern void CheckSphealAbsorbZoneHit(u8, u16*, u16*);
extern void IdlePinballGameMain();
extern void PinballGameIdle0_19048(void);//gMain.subState = 0
extern void PinballGameIdle1_19190(void);//gMain.subState = 1
extern void PinballGame_State2_4ABC8(void);//gMain.subState = 2
extern void PinballGameIdle3_19288(void);//gMain.subState = 3
//extern ? AllBoardProcess_4A_19304();
extern void DetermineFlipperBallSide(struct Vector16 arg0);
//extern ? MainBoardProcess_4B_19490();
extern void UpdateMainBoardFlippers(void);
extern void BonusBoardProcess_4B_19734(void);
extern void UpdateBonusBoardFlippers(void);
//extern ? RubyBoardProcess_3A_19A20();
//extern ? RubyBoardProcess_3B_19B10();
extern void RequestBoardTransition(u8);
extern void ProcessBoardStateTransition(void);
//extern ? SelectFieldMusic();
//extern ? CheckBonusStageReturnTimer();
//extern ? RestoreSavedProgressOnTransition();
//extern ? UpdateRubyBoardVisuals();
//extern ? UpdateRubyBoardEntityLogic();
//extern ? RotateRubyHoleIndicators();
extern void UpdateBannerScrolling(void);
//extern ? RenderBannerScrollSprites();

extern void InitBoardEntryHole();
extern void UpdateBoardEntryHole(void);
//extern ? InitCatchHoleEntry();
extern void UpdateCatchHoleAnimation();
extern void InitHatchHoleEntry(void);
//extern ? UpdateHatchHoleAnimation();
//extern ? InitMartEvoHoleEntry();
//extern ? UpdateMartEvoHoleAnimation();
extern void UpdateMartEvoSelectionUI(s16);
extern void InitCenterHoleEntry(void);
extern void UpdateCenterHoleAnimation(void);
extern void TransitionToBonusField(void);
extern void SetBoardPortraitGraphics(s16, s16);
extern void DrawBoardPortraitSprites(void);
extern void UpdateRubyBonusFieldYPositions(void);
//extern ? UpdateRubyNuzleafAnimation();
//extern ? UpdateRubyShopDoorState();
//extern ? AnimateRubyShopDoor();
//extern ? DrawWhiscash();
//extern ? RubyPond_EntityLogic();
//extern ? RubyPondTriBumperHandleHitAndDraw();
//extern ? DrawRubySharpedoSprite();
extern void UpdatePikachuChargeProgress();
extern void UpdatePikaSpinnerGraphics();
//extern ? AnimateRubyGulpinProjectile();
//extern ? UpdateRubyGulpinBodySprite();
//extern ? DrawRubyPondGulpinPlatforms();
//extern ? UpdateRubyPondGateHitLogic();
//extern ? DrawRubyPondGateSprites();
extern void RunPikachuThunderboltSequence();
extern void UpdateHatchedMonFlyingAnimation();
extern void ResetBonusStageIndicators(s16);
//extern ? InitHatchCatchCountdownMode();
//extern ? UpdateHatchCatchCountdownMode();
extern void ResetBonusModeDisplayState(void);
//extern ? InitBonusStageLegendaryMode();
//extern ? UpdateBonusStageLegendaryMode();
extern void EnableBonusTrapSprite(void);
extern void UpdateBonusTrapSprite(void);
extern void UpdatePikachuChargeAnimation();
//extern ? UpdateEvolutionShopIcon();
extern void UpdatePikachuAttackDisplay(s16);
extern void UpdateCoinCollectionAnimation();
extern void InitLotadBonusCelebration();
//extern ? UpdateLotadBonusCelebration();
//extern ? InitStandardHoleBonusCelebration();
//extern ? UpdateStandardHoleBonusCelebration();
extern void ShowSpeciesNameBanner();
extern void UpdateSpeciesNameBannerPosition();
extern void HideSpeciesNameBanner();
extern void InitEvolutionNameRevealBanner(void);
extern void UpdateEvolutionNameRevealBanner(void);
extern void ResetHatchCaveAnimationState(void);
//extern ? UpdateHatchCaveAnimation();
//extern ? UpdateCyndaquilHatchCaveSprite();
extern void CleanupAfterCatchMode(void);
//extern ? InitEggHatchMode();
//extern ? UpdateEggHatchMode();
extern void HideHatchRevealSprites(void);
extern void RevealSequentialHatchTiles(void);
extern void RevealAllHatchTilesAtOnce(void);
//extern ? InitAreaRouletteMode();
//extern ? UpdateAreaRouletteMode();
extern void UpdateRouletteBoardIndicatorPulse(void);
extern void SetRouletteIndicatorState(s16);
extern void ResetTravelModeState(void);
//extern ? InitTravelMode();
//extern ? UpdateTravelMode();
extern void CleanupAfterEvolutionMode(void);
//extern ? InitEvolutionMode();
//extern ? UpdateEvolutionMode();
extern void UpdateEvolutionItemSprite(void);
extern void CleanupAfterCatchHatchMode(void);
//extern ? InitCatchMode();
//extern ? RunCatchEmModeStateMachine();
//extern ? InitCatchEmMode();
//extern ? RunJirachiModeStateMachine();
extern void LoadCatchModePokemonSpritesheets(void);
extern void LoadHatchModePokemonSpritesheets(void);
extern void DrawCatchModePokemonSprite(void);
extern void HideCatchModePokemonSprite(void);
extern void DrawJirachiModePokemonAndStars(void);
extern void HideJirachiModeSprites(void);
extern void CheckHatchTileRevealState(void);
extern void AnimateEggHatchSequence(void);
extern void ResetHatchAnimationState(void);
extern void InitHatchTileExplodeParticles(void);
extern void AnimateHatchTileExplodeParticles(void);
extern void InitHatchTileRevealAllParticles(void);
extern void AnimateHatchTileRevealAllParticles(void);
extern void InitSlotReelDisplay(void);
extern void UpdateSlotReelSpin(void);
extern void ProcessSlotReelPrize();
//extern ? sub_2C518();
//extern ? UpdateRubyRampGulpinEntity();
//extern ? DrawRubyRampPrizeIndicator();
extern void UpdateSapphirePokeballSprite();
extern void UpdateSapphireBannerSlideSprite(void);
extern void UpdateSapphireChimechoAnimState();
extern void DrawSapphireChimechoSprite();
extern void RunEvolutionCutsceneAnimation(void);
//extern ? sub_2DE54();
extern void RunSapphirePelliperFlybyAnimation(void);
extern void UpdateSapphirePondEntityCooldown();
extern void RunSapphirePondPelliperStateMachine();
extern void DrawSapphirePondWailmerSprite();
extern void UpdateSapphireZigzagoonKickState();
extern void DrawSapphireZigzagoonSprites();
extern void UpdateSapphireShockWallState();
extern void DrawSapphireShockWallSprites();
extern void UpdateSapphireBumperOscillation();
extern void HandleSapphireBumperHitAndDraw();
extern void InitSapphirePondState();
extern void UpdateAndDrawSapphirePondAnimation();
extern void UpdateSapphireSeedotCollectionLogic();
extern void DrawSapphireSeedotSprites();
extern void UpdateSapphireTrapDoorAnimation();
extern void DrawSapphireTrapDoorSprite(void);
extern void UpdateCyndaquilEruptionStateMachine();
extern void UpdateEdgeIndicatorSprite(void);
extern void RestoreBoardPalettesAfterMenu(s16);
extern void RegisterCapturedOrEvolvedPokemon(s16);

extern void BuildSpeciesWeightsForCatchEmMode(void);

// asm/rom_3219C.s

extern void BuildSpeciesWeightsForEggMode(void);
extern void PickSpeciesForEggMode(void);
//extern ? SapphireBoardProcess_3A_326F4();
//extern ? SapphireBoardProcess_3B_3276C();
extern void UpdateSapphireBoardVisuals();
extern void UpdateSapphireBoardState();
extern void InitSapphireBoardEntryMode();
extern void UpdateSapphireBoardEntryMode();
extern void InitSapphireTrapHoleEntry();
extern void UpdateSapphireTrapHoleSequence();
extern void InitSapphireWhiscashCatchEntry();
extern void UpdateSapphireWhiscashCatchSequence();
//extern ? DuskullBonus_Setup();
//extern ? DusclopsBoardProcess_3B_33130();
extern void SwapDuskullEntityIndex(s16 index1, s16 index2);
extern void DuskullPhase_ProcessEntityLogic();
extern void DuskullPhase_ProcessGraphics();
extern void DusclopsPhase_ProcessEntityLogicAndGraphics();
extern void FadeToMainBoard();
extern void ProceessBonusBannerAndScoring();
extern void UpdatePointerSpritePosition();
extern void TransitionBackToMainBoard(void);
//extern ? KecleonBoardProcess_3A_35860();
//extern ? KecleonBoardProcess_3B_35AA4();
//extern ? UpdateKecleonStateMachine();
//extern ? UpdateFallingItemProjectile();
//extern ? UpdateKecleonVisibilityTilemap();
//extern ? RenderKecleonBoardDecorations();
//extern ? DepthSortAndLoadSprites();
//extern ? KyogreBoardProcess_3A_383E4();
//extern ? KyogreBoardProcess_3B_3869C();
extern void UpdateKyogreStateMachine(void);
extern void RenderKyogreSprite(void);
extern void RenderKyogreAttackSprites(void);
//extern ? sub_3A150();
extern void HideKyogreShockwaveSprite(void);
extern void AnimateWaterBackground(void);
//extern ? GroudonBoardProcess_3A_3B120();
//extern ? GroudonBoardProcess_3B_3B49C();
extern void UpdateGroudonStateMachine(void);
extern void RenderGroudonSprite(void);
extern void RenderGroudonAttackSprites(void);
extern void HideGroudonShockwaveSprite(void);
extern void AnimateLavaBackground(void);
//extern ? RayquazaBoardProcess_3A_3E79C();
//extern ? RayquazaBoardProcess_3B_3EB2C();
extern void UpdateRayquazaStateMachine(void);
extern void RenderRayquazaSprite(void);
extern void RenderRayquazaAttackSprites(void);
extern void UpdateElectricBallGrab(void);
extern void RenderWindCloudMinions(void);
extern void UpdateRayquazaIntroOutroSequence(void);
//extern ? SphealBoardProcess_3A_42E48();
//extern ? SphealBoardProcess_3B_43228();
extern void UpdateSphealMinions(void);
extern void UpdateWhiscashPelliperEntity(void);
extern void RenderIceBlockAndDeliverBall(void);
extern void SphealBoard_WhiscashDeliversBall(void);
extern void SphealBoard_PelliperDeliversBall(void);
extern void ProcessSealBounceCollisions(void);
extern void AnimateSphealWaterPalette(void);
extern void RenderBonusResultsScreen(void);
extern void loadIntroduction(void);
extern void SetBoardFieldCollisionData(s16);
extern void UpdateBgTilemapOnScroll(void);
//extern ? AllBoardProcess_1A_47100();
//extern ? AllBoardProcess_1B_47160();
extern void BonusStage_HandleModeChangeFlags();
extern void DebugMenuRenderAndHandleInput(void);
extern void HandleGameOverSequence(void);
extern void HandleEndOfBallSequence(void);
extern void HandleBallSaverAnimation(void);
extern void ClearDebugMenuTilemap(void);
extern void DebugMoveBallPosition(void);
extern void DebugToggleBallSpeed(void);
extern void UpdateEndOfBallBonusSummary(void);
extern void PauseGame(void);
extern void UnpauseGame(void);
extern void SetupGameEndSprites(void);
extern void DrawPauseMenuOverlay(void);
extern void RunIdleBoardFrame();
extern void RunIdleBonusBoardFrame();
extern void SaveBoardStateForPause(s16);
//extern ? AllBoardProcess_8A_4CEA8();
extern void AllBoardProcess_8B_4CEB4(void);
extern void PinballGame_State0_49ED4(void);
extern void UpdateEventTimerDisplay(void);
extern void ClearEventIndicatorDisplay(void);
//extern ? AllBoardProcess_2A_4D6C4();
//extern ? MainBoardProcess_2B_4D960();
//extern ? BonusBoardProcess_2B_4DBFC();
extern void ProcessBoardTiltShake(void);
extern void CheckMainBoardBallOutOfBounds(void);
extern void CheckBonusBoardBallOutOfBounds(void);
extern void ResetBoardStateAfterBallLoss(void);
extern void RenderRubyBoardDynamicEntities(void);
extern void RenderRubySlingshotBumper(void);
extern void CopyRubyTrapGfxToVram(s16);
extern void RenderRubyTimerDigits(void);
extern void RenderRubyBallVariantTiles(void);
extern void RenderRubyBumperHitTiles(void);
extern void RenderRubyHoleIndicatorTiles(void);
extern void RenderRubyBallSaverIndicator(void);
extern void RenderRubyLeftLoopFlasher(void);
extern void RenderRubyRightLoopFlasher(void);
extern void RenderRubyTrapIndicator(void);
extern void RenderRubyCatchReadyFlasher(void);
extern void UpdateBallPowerUpAnimation(void);
extern void RenderRubyBallPowerUpLights(void);
extern void UpdateSapphireArrowLightProgress(void);
extern void RenderSapphireUpperLaneArrows(void);
extern void RenderSapphireLeftEvoArrows(void);
extern void RenderSapphireLeftCatchArrows(void);
extern void RenderBoardDynamicEntities(void);
extern void RenderSapphireTimerDigits(void);
extern void RenderSapphireSlingshotBumper(void);
extern void RenderSapphireBallVariantTiles(void);
extern void RenderSapphireAnimatedDecoration(void);
extern void RenderSapphireBumperHitTiles(void);
extern void RenderSapphireHoleIndicatorTiles(void);
extern void RenderSapphireBallSaverIndicator(void);
extern void RenderSapphireRightLaneArrows(void);
extern void RenderSapphireLeftLoopFlasher(void);
extern void RenderSapphireRightLoopFlasher(void);
extern void RenderSapphireRightEvoArrows(void);
extern void RenderSapphireRightCatchArrows(void);
extern void RenderSapphireCatchReadyFlasher(void);
extern void RenderSapphireTrapIndicator(void);
extern void RenderSapphireBallPowerUpLights(void);
extern void RenderSapphireTargetHitIndicators(void);
extern void RenderSapphireBumperBonusFlasher(void);
extern void RubyBoardProcess_0A_50848(void);
//extern ? RubyBoardProcess_0B_50918();
extern void SapphireBoardProcess_0A_50AD4(void);
//extern ? SapphireBoardProcess_0B_50B80();
extern void DusclopsBoardProcess_0A_50D48(void);
//extern ? DusclopsBoardProcess_0B_50DB8();
extern void KecleonBoardProcess_0A_50DE0(void);
//extern ? BoardProcess0_NoOp();
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

extern void sub_13FC(void);
//extern ? EncodeGbPlayerPacket();
//extern ? ValidateGbPlayerResponse();
//extern ? VerifyGbPlayerChecksum();
//extern ? GetGbPlayerCommResult();
//extern ? ShiftRumbleByCommandState();
extern void GbPlayerTimeoutIntr(void);
extern s16 InitOamFromSpriteSets(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups);
//extern ? SystemInit_NoOp();
extern void ResetSerialIO(void);
extern void SetBasicInterrupts(void);
extern void ResetLinkVariables(void);
extern void ResetDisplayAndCallbacks(void);

// asm/start.s


// asm/titlescreen.s

//extern ? RenderTitleScreenSprites();
extern void RenderTitleMenu0Sprites(void);
extern void RenderTitleMenu1Sprites(void);
extern void EraseSaveData(void);

#endif  // GUARD_FUNCTIONS_H
