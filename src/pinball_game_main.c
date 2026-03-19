#include "global.h"
#include "agb_sram.h"
#include "main.h"
#include "m4a.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/ruby_states.h"

extern struct PinballGame gPinballGameState;

typedef void (*VoidFunc)(void);

struct BoardProcessPair
{
    void (*initFunc)(void);
    void (*updateFunc)(void);
};

extern struct BoardProcessPair CurrentBoardProcPairs_020028D8[9];
extern u8 gBoardGfxBuffer[];
extern u8 gBoardBGTileBufferAlt[];

extern const struct BoardProcessPair BoardProcPairs_086B077C[];
extern const VoidFunc gFieldInitFuncs[];
extern struct SpriteGroup *gMainFieldSpriteGroups[][60];
extern struct SpriteGroup *gBonusFieldSpriteGroups[][30];
extern const u8 gBoardActionTilesGfx[];
extern const u8 gEggModeTilesGfx[];
extern const u8 gCaptureModeTilesGfx[];
extern const u8 gCaptureScreenTilesGfx[];
extern const u8 gRubyBoardBonusGfx[];
extern const u8 gRubyBoardBonusObjPalette[];
extern const u8 gSapphireBoardBonusGfx[];
extern const u8 gSapphireBoardBonusObjPalette[];
extern const u8 gSapphireCatchTilesGfx[];
extern const u8 gHatchRevealTilesGfx[];
extern const u8 gHatchStartTilesGfx[];
extern const u8 gHatchStage2TilesGfx[];
extern const u8 gHatchStage3TilesGfx[];
extern const u8 gHatchFinalTilesGfx[];
extern const u8 gAlphabetTilesGfx[][0x40];
extern const u8 gSpaceTileGfx[0x40];
extern const u8 gDecimalDigitTilesGfx[][0x40];
extern const u8 gPokemonNameDisplayGfx[];
extern const u8 gEggPortraitTilesGfx[];
extern const u8 gMainBoardBallSave_Gfx[];
extern const u8 gMainBoardEndOfBall_Gfx[];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];
extern const s16 gCaughtTextChars[];
extern const u16 gShopCursorToItemMap[];
extern const u8 *gEvoItemAppear_GfxList[];
extern const s16 gEvoShopAnimFrames[][7];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u8 gRubyFlashingDecorationTiles[][0x300];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const u8 gRubyFlashingTiles_Secondary[][0x100];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardShop_Gfx[][0x500];
extern const u8 gHoleIndicatorTileGfx[][0x440];
extern const s16 gHoleAnimKeyframeData[][2];
extern const u8 gKecleonBonusClear_Gfx[0x2000];
extern const u8 gKyogreBonusClear_Gfx[0x2000];
extern const u8 gGroudonBoardBackgroundGfx[0x2000];
extern const u8 gGroudonBonusClear_Gfx[0x2000];
extern const u8 gRayquazaSkyBackgroundGfx[0x2800];
extern const u8 gRayquazaWindBoardGfx[0x1C00];
extern const u8 gRayquazaBonusClear_Gfx[0x2000];
extern const u8 gRayquazaSpriteSheet[0x860];
extern const u8 gSphealResultsScreenGfx[0x800];

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gDxModePikachuObjTiles[];

void ClampPortraitSpritesToOffscreen(void);
void SetBallPositionForBonusReturn(void);
void ClearBG0Tilemap(void);
static void SetupDisplayRegistersForField(void);
void InitPinballGameState(void);
void ConfigureBoardProcessesForField(void);
void UpdateButtonActionsFromJoy(void);
void ReplayButtonActionsFromRecording(void);
void SaveGameStateSnapshot(s16);
void SaveGameToSram(void);
void RestoreGameState(u16);
void RestoreFieldSpecificGraphics(void);
void RestoreMainFieldDynamicGraphics(void);
void RestoreRubyBoardTileGraphics(void);
void RestoreSapphireBoardTileGraphics(void);
void nullsub_18(void);
void RestoreDusclopsBonusGraphics(void);
void RestoreKecleonBonusGraphics(void);
void RestoreKyogreBonusGraphics(void);
void RestoreGroudonBonusGraphics(void);
void RestoreRayquazaBonusGraphics(void);
void RestoreSphealBonusGraphics(void);


void PinballGameMain(void)
{
    gPinballGameStateFuncs[gMain.subState]();
}

void PinballGame_State0_49ED4(void)
{
    s16 i, j;
    s16 numRngAdvances;
    s16 var0;

    numRngAdvances = gMain.systemFrameCount % 16;
    for (i = 0; i < numRngAdvances; i++)
        Random();

    EnableGbPlayerRumble();
    gCurrentPinballGame = &gPinballGameState;
    ResetDisplayState();
    gMain.gameExitState = 0;
    if (gMain.continueFromSave)
        var0 = 0;
    else if (gMain.tempField == gMain.selectedField)
        var0 = 1;
    else if (gMain.selectedField < MAIN_FIELD_COUNT)
        var0 = 2;
    else
        var0 = 3;

    switch (var0)
    {
    case 0:
        SetupDisplayRegistersForField();
        InitPinballGameState();
        loadIntroduction();
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);

        ConfigureBoardProcessesForField();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].initFunc();

        m4aMPlayAllStop();
        ClearBG0Tilemap();
        InitPinballGameState();
        if (gMain.mainState == STATE_GAME_IDLE)
            RestoreGameState(2);
        else
            RestoreGameState(1);

        SetupDisplayRegistersForField();
        ConfigureBoardProcessesForField();
        gFieldInitFuncs[gMain.isBonusField]();
        if (gMain.selectedField == FIELD_RUBY || gMain.selectedField == FIELD_SAPPHIRE)
            ClampPortraitSpritesToOffscreen();
        else if (gMain.selectedField == FIELD_DUSCLOPS)
            RenderBonusStageOverlaySprites();
        else if (gMain.selectedField == FIELD_KYOGRE)
            HideKyogreSplashSprite();
        else if (gMain.selectedField == FIELD_GROUDON)
            HideGroudonShockwaveSprite();
        break;
    case 1:
        SetupDisplayRegistersForField();
        InitPinballGameState();
        loadIntroduction();
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);

        ConfigureBoardProcessesForField();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].initFunc();

        ClearBG0Tilemap();
        break;
    case 2:
        SetupDisplayRegistersForField();
        SetBallPositionForBonusReturn();
        RestoreGameState(0);
        ConfigureBoardProcessesForField();
        gFieldInitFuncs[gMain.isBonusField]();
        if (gMain.selectedField == FIELD_RUBY)
            SetBoardCollisionConfig(1);

        LoadPortraitGraphics(0, 0);
        gCurrentPinballGame->portraitDisplayState = 0;
        break;
    case 3:
        SetupDisplayRegistersForField();
        InitPinballGameState();
        loadIntroduction();
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        ConfigureBoardProcessesForField();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].initFunc();

        ClearBG0Tilemap();
        break;
    }

    gBoardConfig.caughtSpeciesCount = 0;
    for (j = 0; j < NUM_SPECIES; j++)
    {
        if (gMain_saveData.pokedexFlags[j] > SPECIES_SHARED_AND_SEEN)
            gBoardConfig.caughtSpeciesCount++;
    }

    EnableVBlankInterrupts();
    FadeInScreen();
    gCurrentPinballGame->startButtonDisabled = 0;
    gMain.blendEnabled = 1;

    switch (var0)
    {
    case 0:
        if (gMain.mainState != STATE_GAME_IDLE && gCurrentPinballGame->savedBgmSongHeader && gMPlayInfo_BGM.status < 0)
            MPlayStart(&gMPlayInfo_BGM, gCurrentPinballGame->savedBgmSongHeader);
        if (gMain.selectedField < MAIN_FIELD_COUNT)
            RestoreBoardObjPalettes(gCurrentPinballGame->activePaletteIndex);
        break;
    case 1:
    case 2:
        gMain.blendControl = 0xCE;
        gMain.blendBrightness = 0;
        break;
    case 3:
        break;
    }

    gMain.subState++;
}

static void SetupDisplayRegistersForField(void)
{
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        REG_BG3CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(6) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_SAPPHIRE:
        REG_BG3CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(6) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_DUSCLOPS:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_KECLEON:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_KYOGRE:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_GROUDON:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_RAYQUAZA:
        REG_BG3CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(6) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_SPHEAL:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    }

    gMain.dispcntBackup = REG_DISPCNT;
    REG_MOSAIC = 0;
}

void InitPinballGameState(void)
{
    gMain.modeChangeFlags = MODE_CHANGE_NONE;
    gMain.debugMenuCursorIndex = 0;
    gMain.fieldFrameCount = 0;
    gMain.pendingModeChangeType = 0;
    gMain.animationTimer = 0;
    gMain.modeChangeDelayTimer = 0;
    gMain.vCount = 144;
    gMain.shopPanelActive = 0;
    gMain.shopPanelSlideOffset = 0;
    gMain.blendEnabled = 0;
    gMain.blendControl = 0;
    gMain.blendAlpha = 0;
    gMain.blendBrightness = 0;
    if (gMain.tempField == gMain.selectedField)
    {
        DmaFill16(3, 0, gCurrentPinballGame, sizeof(struct PinballGame));
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
        {
            gCurrentPinballGame->pikaChargeTarget = 168;
            gCurrentPinballGame->pikaChargeProgress = 168;
            gCurrentPinballGame->prevChargeFillValue = 13;
            gCurrentPinballGame->chargeFillValue = 13;
            gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
            gCurrentPinballGame->chargeIndicatorXOffset = 0;
            gCurrentPinballGame->chargeIndicatorYOffset = 120;
            gCurrentPinballGame->fullChargeIndicatorBlinkTimer = 60;
            DmaCopy16(3, gDxModePikachuObjTiles, (void *)OBJ_VRAM0 + 0x600, 0x180);
            gCurrentPinballGame->outLanePikaPosition = 2;
            gMain.fieldSpriteGroups[41]->available = FALSE;
            gCurrentPinballGame->pichuEntranceTimer = 1;
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
            gCurrentPinballGame->numLives = 9;
            gCurrentPinballGame->coins = 99;
        }
        else
        {
            gCurrentPinballGame->chargeIndicatorXOffset = 0;
            gCurrentPinballGame->chargeIndicatorYOffset = -4;
            gCurrentPinballGame->numLives = 2;
            gCurrentPinballGame->coins = 10;
        }
    }

    if (gMain.mainState != STATE_GAME_IDLE)
        gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

    gCurrentPinballGame->scoreAddStepSize = 40000;
    gCurrentPinballGame->fadeSubState = 0;
    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
    gCurrentPinballGame->secondaryBall = &gCurrentPinballGame->ballStates[0];
    gCurrentPinballGame->activeBallIndex = 0;
}

void SetBallPositionForBonusReturn(void)
{
    switch (gCurrentPinballGame->bonusReturnState)
    {
    case 0:
        gCurrentPinballGame->ball->positionQ0.x = 119;
        gCurrentPinballGame->ball->positionQ0.y = 279;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->ballHidden = 1;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->trapAnimState = 0;
        gCurrentPinballGame->modeAnimTimer = 120;
        gCurrentPinballGame->ballCatchState = TRAP_CENTER_HOLE;
        if (gMain.selectedField == FIELD_RUBY)
            UpdateRubyCatchModeAnimation();
        else
            UpdateSapphireCatchModeAnimation();

        gCurrentPinballGame->cameraBaseX = 0;
        gCurrentPinballGame->cameraBaseY = 215;
        break;
    case 1:
        gCurrentPinballGame->ball->positionQ0.x = 140;
        gCurrentPinballGame->ball->positionQ0.y = 183;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->ballHidden = 1;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->trapAnimState = 0;
        gCurrentPinballGame->whiscashState = WHISCASH_STATE_INIT_RETURN_FROM_BONUS;
        gCurrentPinballGame->cameraBaseX = 0;
        gCurrentPinballGame->cameraBaseY = 118;
        break;
    case 2:
        gCurrentPinballGame->ball->positionQ0.x = -28;
        gCurrentPinballGame->ball->positionQ0.y = -10;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->ballHidden = 1;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->trapAnimState = 0;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        gCurrentPinballGame->pelipperState = 7;
        gCurrentPinballGame->cameraBaseX = 0;
        gCurrentPinballGame->cameraBaseY = 0;
        break;
    }

    gCurrentPinballGame->cameraScrollOffset = 0;
    gCurrentPinballGame->cameraScrollTarget = 0;
    gCurrentPinballGame->cameraScrollEnabled = 0;
    gCurrentPinballGame->cameraYQ8 = gCurrentPinballGame->cameraBaseY << 8;
    gCurrentPinballGame->cameraXOffset = gCurrentPinballGame->cameraBaseX;
    gCurrentPinballGame->cameraYOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->cameraScrollOffset;

    gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraBaseX;
    gMain.bgOffsets[2].yOffset = gCurrentPinballGame->cameraBaseY;
    gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraBaseX;
    gMain.bgOffsets[3].yOffset = gCurrentPinballGame->cameraBaseY;
    gMain.bgOffsets[1].xOffset = gCurrentPinballGame->cameraBaseX;
    gMain.bgOffsets[1].yOffset = gCurrentPinballGame->cameraBaseY;
    gMain.bgOffsets[0].yOffset = 80;

    gCurrentPinballGame->scrollEffectY = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->ballLaunchSpeed = gMain.bgOffsets[3].yOffset / 8;
}

void ConfigureBoardProcessesForField(void)
{
    CurrentBoardProcPairs_020028D8[1] = BoardProcPairs_086B077C[0];
    CurrentBoardProcPairs_020028D8[8] = BoardProcPairs_086B077C[18];
    CurrentBoardProcPairs_020028D8[6] = BoardProcPairs_086B077C[15];
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[3];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[16];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[19];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[11];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[1];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[13];
        gMain.fieldSpriteGroups = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_SAPPHIRE:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[4];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[16];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[20];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[11];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[1];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[13];
        gMain.fieldSpriteGroups = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_DUSCLOPS:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[5];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[21];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KECLEON:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[6];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[22];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KYOGRE:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[7];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[23];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_GROUDON:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[8];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[24];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_RAYQUAZA:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[9];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[25];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_SPHEAL:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[10];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[26];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    }
}

void PinballGame_State1_4AAD8(void)
{
    switch (gCurrentPinballGame->fadeSubState)
    {
    case 0:
        gCurrentPinballGame->fadeSubState = 1;
        gMain.gameExitState = 0;
        break;
    case 1:
        gFieldInitFuncs[gMain.isBonusField]();
        if (JOY_HELD(A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON) == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
            gMain.gameExitState = 1;

        if (gMain.gameExitState)
        {
            if (gMain.selectedField < MAIN_FIELD_COUNT)
            {
                ClampPortraitSpritesToOffscreen();
                RestoreBoardObjPalettes(0);
            }
            else if (gMain.selectedField == FIELD_DUSCLOPS)
            {
                RenderBonusStageOverlaySprites();
            }
            else if (gMain.selectedField == FIELD_KYOGRE)
            {
                HideKyogreSplashSprite();
            }
            else if (gMain.selectedField == FIELD_GROUDON)
            {
                HideGroudonShockwaveSprite();
            }

            if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
                DmaCopy16(3, gCurrentPinballGame->pauseObjPalette, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);

            gCurrentPinballGame->fadeSubState = 2;
            if (gMain.gameExitState == 2)
                SaveGameStateSnapshot(1);
        }
        break;
    case 2:
        gMain.subState++;
        break;
    }

    ProcessRumbleFrame();
}

//Note: Used by both the main game mode and the idle game mode
//gMain.subState = 2 in both.
void PinballGame_State2_4ABC8(void)
{
    DisableGbPlayerRumble();
    if (IsGbPlayerReady())
    {
        RestoreDefaultInterrupts();
        gMain.subState++;
    }
}

void MainGameFrameUpdate(void)
{
    s16 i;

    UpdateButtonActionsFromJoy();
    CurrentBoardProcPairs_020028D8[1].updateFunc();
    if (gMain.gameExitState == 0 && !(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[2].updateFunc();
        CurrentBoardProcPairs_020028D8[0].updateFunc();
        CurrentBoardProcPairs_020028D8[3].updateFunc();
        CurrentBoardProcPairs_020028D8[4].updateFunc();
        if (gMain.modeChangeFlags)
        {
            if (!gCurrentPinballGame->ballFrozenState)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs_020028D8[6].updateFunc();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->globalAnimFrameCounter++;
            if (gCurrentPinballGame->ballFrozenState)
            {
                if (gCurrentPinballGame->ballFrozenState != 2)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->gravityStrengthIndex = i;
                        CurrentBoardProcPairs_020028D8[5].updateFunc();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs_020028D8[5].updateFunc();
                    CurrentBoardProcPairs_020028D8[6].updateFunc();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].updateFunc();
        CurrentBoardProcPairs_020028D8[8].updateFunc();
    }

    UpdateScrollingBackgroundTiles();
}

void IdleGameFrameUpdate(void)
{
    s16 i;

    ReplayButtonActionsFromRecording();
    CurrentBoardProcPairs_020028D8[1].updateFunc();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[2].updateFunc();
        CurrentBoardProcPairs_020028D8[0].updateFunc();
        CurrentBoardProcPairs_020028D8[3].updateFunc();
        CurrentBoardProcPairs_020028D8[4].updateFunc();
        if (gMain.modeChangeFlags)
        {
            if (!gCurrentPinballGame->ballFrozenState)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs_020028D8[6].updateFunc();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->globalAnimFrameCounter++;
            if (gCurrentPinballGame->ballFrozenState)
            {
                if (gCurrentPinballGame->ballFrozenState != 2)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->gravityStrengthIndex = i;
                        CurrentBoardProcPairs_020028D8[5].updateFunc();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs_020028D8[5].updateFunc();
                    CurrentBoardProcPairs_020028D8[6].updateFunc();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].updateFunc();
        CurrentBoardProcPairs_020028D8[8].updateFunc();
    }

    UpdateScrollingBackgroundTiles();
    if ((gMain.systemFrameCount % 32) / 16 > 0)
    {
        for (i = 0; i < 10; i++)
            gBG0TilemapBuffer[0x34A + i] = 0xC156 + i;
    }
    else
    {
        for (i = 0; i < 10; i++)
            gBG0TilemapBuffer[0x34A + i] = 0x1FF;
    }

    DmaCopy16(3, &gBG0TilemapBuffer[0x340], (void *)0x6002680, 0x40);
}

void BonusFieldFrameUpdate(void)
{
    s16 i;

    UpdateButtonActionsFromJoy();
    CurrentBoardProcPairs_020028D8[1].updateFunc();
    if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
        return;

    CurrentBoardProcPairs_020028D8[0].updateFunc();
    CurrentBoardProcPairs_020028D8[2].updateFunc();
    CurrentBoardProcPairs_020028D8[3].updateFunc();
    CurrentBoardProcPairs_020028D8[4].updateFunc();
    if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
    {
        if (!gCurrentPinballGame->ballFrozenState)
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->activeBallIndex = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                gCurrentPinballGame->gravityStrengthIndex = i;
                CurrentBoardProcPairs_020028D8[6].updateFunc();
            }
        }
    }
    else
    {
        gMain.fieldFrameCount++;
        gCurrentPinballGame->globalAnimFrameCounter++;
        if (gCurrentPinballGame->ballFrozenState)
        {
            if (gCurrentPinballGame->ballFrozenState == 2)
            {
                gCurrentPinballGame->activeBallIndex = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                gCurrentPinballGame->gravityStrengthIndex = 0;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs_020028D8[5].updateFunc();
                }
            }
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->activeBallIndex = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                gCurrentPinballGame->gravityStrengthIndex = i;
                CurrentBoardProcPairs_020028D8[5].updateFunc();
                CurrentBoardProcPairs_020028D8[6].updateFunc();
            }
        }
    }

    CurrentBoardProcPairs_020028D8[7].updateFunc();
    CurrentBoardProcPairs_020028D8[8].updateFunc();
}

void IdleBonusFieldFrameUpdate(void)
{
    s16 i;

    ReplayButtonActionsFromRecording();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[0].updateFunc();
        CurrentBoardProcPairs_020028D8[2].updateFunc();
        CurrentBoardProcPairs_020028D8[3].updateFunc();
        CurrentBoardProcPairs_020028D8[4].updateFunc();
        if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
        {
            if (!gCurrentPinballGame->ballFrozenState)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs_020028D8[6].updateFunc();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->globalAnimFrameCounter++;
            if (gCurrentPinballGame->ballFrozenState)
            {
                if (gCurrentPinballGame->ballFrozenState == 2)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                    gCurrentPinballGame->gravityStrengthIndex = 0;
                }
                else
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->activeBallIndex = 0;
                        gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                        gCurrentPinballGame->gravityStrengthIndex = i;
                        CurrentBoardProcPairs_020028D8[5].updateFunc();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs_020028D8[5].updateFunc();
                    CurrentBoardProcPairs_020028D8[6].updateFunc();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].updateFunc();
        CurrentBoardProcPairs_020028D8[8].updateFunc();
    }

    if ((gMain.systemFrameCount % 32) / 16 > 0)
    {
        for (i = 0; i < 9; i++)
            gBG0TilemapBuffer[0x32B + i] = 0xC156 + i;
    }
    else
    {
        for (i = 0; i < 9; i++)
            gBG0TilemapBuffer[0x32B + i] = 0x1FF;
    }

    DmaCopy16(3, &gBG0TilemapBuffer[0x320], (void *)0x6002640, 0x40);
}

void PinballGame_State3_4B20C(void)
{
    gMain.blendEnabled = 0;
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gMain.finalScoreLo = gCurrentPinballGame->scoreLo;
    gMain.finalScoreHi = gCurrentPinballGame->scoreHi;
    if (gMain.gameExitState == 2)
        SaveGameToSram();

    if (gMain.gameExitState == 0)
    {
        if (gMain.selectedField >= MAIN_FIELD_COUNT)
        {
            SetMainGameState(STATE_BONUS_FIELD_SELECT);
            return;
        }
        else if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD] || gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
        {
            SetMainGameState(STATE_INTRO);
            return;
        }
    }
    else
    {
        SetMainGameState(STATE_INTRO);
        return;
    }

    SetMainGameState(STATE_SCORES_MAIN);
}

void nullsub_19(void)
{
}

void UpdateButtonActionsFromJoy(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gCurrentPinballGame->newButtonActions[i] = 0;
        gCurrentPinballGame->releasedButtonActions[i] = 0;
    }

    if (gMain.modeChangeFlags)
        return;

    for (i =  0; i < 5; i++)
    {
        int buttonConfigKeyMask = (gMain.buttonConfigs[i][0] | gMain.buttonConfigs[i][1]) & KEYS_MASK;
        if (buttonConfigKeyMask == JOY_HELD(buttonConfigKeyMask))
        {
            if (gCurrentPinballGame->heldButtonActions[i] == 0)
                gCurrentPinballGame->newButtonActions[i] = 1;

            gCurrentPinballGame->heldButtonActions[i] = 1;
        }
        else
        {
            if (gCurrentPinballGame->heldButtonActions[i])
                gCurrentPinballGame->releasedButtonActions[i] = 1;

            gCurrentPinballGame->heldButtonActions[i] = 0;
        }
    }
}

void ReplayButtonActionsFromRecording(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gCurrentPinballGame->newButtonActions[i] = 0;
        gCurrentPinballGame->releasedButtonActions[i] = 0;
    }

    if (gMain.modeChangeFlags)
        return;

    if (gReplayFrameCounter < 60 * 60)
    {
        for (i =  0; i < 5; i++)
        {
            gCurrentPinballGame->newButtonActions[i] = (gBoardConfig.replayInputData[gReplayFrameCounter].newButtonBits >> i) & 0x1;
            gCurrentPinballGame->releasedButtonActions[i] = (gBoardConfig.replayInputData[gReplayFrameCounter].releasedButtonBits >> i) & 0x1;
            gCurrentPinballGame->heldButtonActions[i] = (gBoardConfig.replayInputData[gReplayFrameCounter].heldButtonBits >> i) & 0x1;
        }

        gReplayFrameCounter++;
    }

    if (gCurrentPinballGame->newButtonActions[1])
        gMain.newKeys = A_BUTTON;
}

void SaveGameStateSnapshot(s16 arg0)
{
    s16 i;
    u16 *var0;

    if (gMPlayInfo_BGM.status >= 0)
    {
        gCurrentPinballGame->savedBgmSongHeader = gMPlayInfo_BGM.songHeader;
        m4aMPlayStop(&gMPlayInfo_BGM);
    }
    else
    {
        gCurrentPinballGame->savedBgmSongHeader = NULL;
    }

    for (i = 0; i < 100; i++)
        gCurrentPinballGame->savedSpriteAvailability[gMain.isBonusField][i] = gMain.spriteGroups[i].available;

    DmaCopy16(3, (void *)OBJ_PLTT, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], OBJ_PLTT_SIZE);
    DmaCopy16(3, (void *)BG_PLTT, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], BG_PLTT_SIZE);
    if (!arg0)
        return;

    gCurrentPinballGame->bgOffsets0 = gMain.bgOffsets[0];
    gCurrentPinballGame->bgOffsets1 = gMain.bgOffsets[1];
    gCurrentPinballGame->bgOffsets2 = gMain.bgOffsets[2];
    gCurrentPinballGame->bgOffsets3 = gMain.bgOffsets[3];
    gCurrentPinballGame->savedField = gMain.selectedField;
    gCurrentPinballGame->savedTempField = gMain.tempField;
    gCurrentPinballGame->savedIsBonusField = gMain.isBonusField;
    gCurrentPinballGame->savedModeChangeFlags = gMain.modeChangeFlags;
    gCurrentPinballGame->savedDebugMenuCursorIndex = gMain.debugMenuCursorIndex;
    gCurrentPinballGame->savedPendingModeChangeType = gMain.pendingModeChangeType;
    gCurrentPinballGame->savedAnimationTimer = gMain.animationTimer;
    gCurrentPinballGame->savedModeChangeDelayTimer = gMain.modeChangeDelayTimer;
    gCurrentPinballGame->savedShopPanelActive = gMain.shopPanelActive;
    gCurrentPinballGame->savedShopPanelSlideOffset = gMain.shopPanelSlideOffset;
    gCurrentPinballGame->savedBlendControl = gCurrentPinballGame->pauseBlendControl;
    gCurrentPinballGame->savedBlendAlpha = gCurrentPinballGame->pauseBlendAlpha;
    gCurrentPinballGame->savedBlendBrightness = gCurrentPinballGame->pauseBlendBrightness;
    gCurrentPinballGame->savedScoreOverlayActive = gCurrentPinballGame->pauseScoreOverlayActive;
    gCurrentPinballGame->savedVCount = gCurrentPinballGame->pauseVCount;
    gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gCurrentPinballGame->eReaderBonuses[i] = gMain.eReaderBonuses[i];
}

void SaveGameToSram(void)
{
    gCurrentPinballGame->saveDataValid = 1;
    WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(*gCurrentPinballGame));
}

void RestoreGameState(u16 arg0)
{
    s16 i, j;
    s16 var0, var1;
    int var2;

    if (arg0 == 1)
    {
        ReadSramFast((void *)SRAM + 0x544, (u8 *)gCurrentPinballGame, sizeof(*gCurrentPinballGame));
    }
    else if (arg0 == 2)
    {
        DmaCopy16(3, gBoardConfig.pinballGame, gCurrentPinballGame, sizeof(*gCurrentPinballGame));
        gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
        gCurrentPinballGame->secondaryBall = &gCurrentPinballGame->ballStates[0];
        var2 = gMain.idleDemoVariant;
        if ((var2 & 0x3) == 1)
        {
            gCurrentPinballGame->pikaSpinMomentum = 0;
            gCurrentPinballGame->kickbackAnimFrameTimer = 0;
            gCurrentPinballGame->kickbackFrameId = 0;
            gCurrentPinballGame->pikaChargeTarget = 0;
            gCurrentPinballGame->pikaChargeProgress = 0;
            gCurrentPinballGame->prevChargeFillValue = 0;
            gCurrentPinballGame->chargeFillValue = 0;
            gCurrentPinballGame->chargeIndicatorXOffset = 0;
            gCurrentPinballGame->chargeIndicatorYOffset = -4;
            gCurrentPinballGame->chargeIndicatorScaleX = 256;
            gCurrentPinballGame->chargeIndicatorScaleY = 256;
            gCurrentPinballGame->chargeFillAnimTimer = 0;
            gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
        }
    }

    if (arg0 != 0)
    {
        gMain.selectedField = gCurrentPinballGame->savedField;
        gMain.tempField = gCurrentPinballGame->savedTempField;
        gMain.isBonusField = gCurrentPinballGame->savedIsBonusField;
        gMain.modeChangeFlags = gCurrentPinballGame->savedModeChangeFlags;
        gMain.debugMenuCursorIndex = gCurrentPinballGame->savedDebugMenuCursorIndex;
        gMain.pendingModeChangeType = gCurrentPinballGame->savedPendingModeChangeType;
        gMain.animationTimer = gCurrentPinballGame->savedAnimationTimer;
        gMain.modeChangeDelayTimer = gCurrentPinballGame->savedModeChangeDelayTimer;
        gMain.shopPanelActive = gCurrentPinballGame->savedShopPanelActive;
        gMain.shopPanelSlideOffset = gCurrentPinballGame->savedShopPanelSlideOffset;
        gMain.blendControl = gCurrentPinballGame->savedBlendControl;
        gMain.blendAlpha = gCurrentPinballGame->savedBlendAlpha;
        gMain.blendBrightness = gCurrentPinballGame->savedBlendBrightness;
        gMain.scoreOverlayActive = gCurrentPinballGame->savedScoreOverlayActive;
        gMain.vCount = gCurrentPinballGame->savedVCount;
        gMain.bgOffsets[0] = gCurrentPinballGame->bgOffsets0;
        gMain.bgOffsets[1] = gCurrentPinballGame->bgOffsets1;
        gMain.bgOffsets[2] = gCurrentPinballGame->bgOffsets2;
        gMain.bgOffsets[3] = gCurrentPinballGame->bgOffsets3;
        for (i = 0; i < NUM_EREADER_CARDS; i++)
            gMain.eReaderBonuses[i] = gCurrentPinballGame->eReaderBonuses[i];

        gCurrentPinballGame->startButtonDisabled = 1;
        if (arg0 == 1 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->cameraBaseY +
                                         gCurrentPinballGame->tiltYOffset +
                                         gCurrentPinballGame->cameraScrollOffset +
                                         gCurrentPinballGame->cameraYAdjust;
        }
    }
    else
    {
        gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->hudSpriteBaseY;
    }

    gCurrentPinballGame->fadeSubState = 0;
    gMain.continueFromSave = 0;
    loadIntroduction();
    if (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->boardCollisionConfigChanged)
        SetBoardCollisionConfig(1);

    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        for (i = 0; i < 22; i++)
        {
            var0 = i + gCurrentPinballGame->ballLaunchSpeed;
            var1 = (i + 10 + gCurrentPinballGame->ballLaunchSpeed) % 22;
            if (var0 < 32)
            {
                DmaCopy16(3, &gBoardGfxBuffer[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
            else
            {
                var0 -= 32;
                DmaCopy16(3, &gBoardBGTileBufferAlt[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
        }
    }

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gBG0TilemapBuffer, (void *)0x6002000, 0x1000);
    if (gMain.scoreOverlayActive)
    {
        if (gCurrentPinballGame->boardState == 6)
        {
            for (j = 0; j <= gCurrentPinballGame->cutsceneTilemapColumn; j++)
            {
                for (i = 2; i < 12; i++)
                    gBG0TilemapBuffer[(i + 15) * 0x20 + j] = 0xC100;
            }
        }
        else
        {
            for (j = 0; j <= gCurrentPinballGame->cutsceneTilemapColumn; j++)
            {
                for (i = 1; i < 11; i++)
                    gBG0TilemapBuffer[(i + 15) * 0x20 + j] = 0xC100;
            }
        }

        DmaCopy16(3, gBG0TilemapBuffer, (void *)0x6002000, 0x800);
    }

    DmaCopy16(3, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    RestoreFieldSpecificGraphics();
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        RubyBoardProcess_0A_50848();
        LoadShopItemGraphics(gCurrentPinballGame->evolutionShopActive);
        break;
    case FIELD_SAPPHIRE:
        SapphireBoardProcess_0A_50AD4();
        break;
    case FIELD_DUSCLOPS:
        DusclopsBoardProcess_0A_50D48();
        break;
    case FIELD_KECLEON:
        KecleonBoardProcess_0A_50DE0();
        break;
    case FIELD_KYOGRE:
        KyogreBoardProcess_0A_50F04();
        break;
    case FIELD_GROUDON:
        GroudonBoardProcess_0A_50FD4();
        break;
    case FIELD_RAYQUAZA:
        RayquazaBoardProcess_0A_51090();
        break;
    case FIELD_SPHEAL:
        SphealBoardProcess_0A_51150();
        break;
    }

    for (i = 0; i < 100; i++)
        gMain.spriteGroups[i].available = gCurrentPinballGame->savedSpriteAvailability[gMain.isBonusField][i];

    if (arg0 == 1)
    {
        gCurrentPinballGame->saveDataValid = 0;
        WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(gCurrentPinballGame->saveDataValid));
    }
}

void RestoreFieldSpecificGraphics(void)
{
    s16 i;
    struct PokemonSpecies *species;
    const u16 *var1;
    s16 var2, var3;

    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        RestoreMainFieldDynamicGraphics();
        RestoreRubyBoardTileGraphics();
        break;
    case FIELD_SAPPHIRE:
        RestoreMainFieldDynamicGraphics();
        RestoreSapphireBoardTileGraphics();
        break;
    case FIELD_DUSCLOPS:
        nullsub_18();
        RestoreDusclopsBonusGraphics();
        break;
    case FIELD_KECLEON:
        nullsub_18();
        RestoreKecleonBonusGraphics();
        break;
    case FIELD_KYOGRE:
        nullsub_18();
        RestoreKyogreBonusGraphics();
        break;
    case FIELD_GROUDON:
        nullsub_18();
        RestoreGroudonBonusGraphics();
        break;
    case FIELD_RAYQUAZA:
        nullsub_18();
        RestoreRayquazaBonusGraphics();
        break;
    case FIELD_SPHEAL:
        nullsub_18();
        RestoreSphealBonusGraphics();
        break;
    }

    switch (gCurrentPinballGame->activePortraitType - 1)
    {
    case 0:
        if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->outLaneSide == 2)
        {
            DmaCopy16(3, gPikaSaverFullCoverageGfx, (void *)0x6015800, 0x2400);
        }
        else
        {
            DmaCopy16(3, gPikaSaverPartialCoverageGfx, (void *)0x6015800, 0x2400);
        }
        break;
    case 1:
        DmaCopy16(3, gEggModeTilesGfx, (void *)0x6015800, 0x1000);
        break;
    case 2:
        DmaCopy16(3, gCaptureModeTilesGfx, (void *)0x6015800, 0xCA0);
        break;
    case 3:
        DmaCopy16(3, gModeBannerTilemaps[gCurrentPinballGame->bannerGfxIndex], (void *)0x6015800, 0x25E0);
        break;
    case 4:
        DmaCopy16(3, gHatchStartTilesGfx, (void *)0x6015800, 0x2000);
        break;
    case 5:
        DmaCopy16(3, gHatchStage2TilesGfx, (void *)0x6015800, 0x800);
        break;
    case 6:
        DmaCopy16(3, gHatchStage3TilesGfx, (void *)0x6015800, 0x2000);
        break;
    case 7:
        DmaCopy16(3, gHatchFinalTilesGfx, (void *)0x6015800, 0x1800);
        break;
    case 8:
        DmaCopy16(3, gCaptureScreenTilesGfx, (void *)0x6015800, 0x1C00);
        break;
    case 9:
        DmaCopy16(3, gSapphireCatchTilesGfx, (void *)0x6015800, 0x1400);
        break;
    case 10:
        DmaCopy16(3, gHatchRevealTilesGfx, (void *)0x6015800, 0x2800);
        break;
    case 11:
        DmaCopy16(3, gEggPortraitTilesGfx, (void *)0x6015800, 0x280);
        break;
    case 13:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }
        DmaCopy16(3, gPokemonNameDisplayGfx, (void *)0x6015C00, 0x940);
        break;
    case 12:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }

        for (i = 0; i < 10; i++)
        {
            if (gCaughtTextChars[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
            else
            {
                int var0 = gCaughtTextChars[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[var0], (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
        }
        break;
    case 14:
        DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->evoItemGfxIndex], (void *)0x6015800, 0x1C00);
        break;
    case 15:
        DmaCopy16(3, gBoardActionTilesGfx, (void *)0x6015800, 0x2400);
        break;
    case 16:
        DmaCopy16(3, gHatchFinalTilesGfx, (void *)0x6015800, 0x1800);
        break;
    case 17:
        DmaCopy16(3, gPokemonNameDisplayGfx, (void *)0x6015C00, 0x940);
        if (gCurrentPinballGame->evolutionShopActive == 0)
        {
            var1 = gShopItemData[gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor]];
            var2 = var1[3] / 10;
            DmaCopy16(3, gDecimalDigitTilesGfx[var2], (void *)0x6015DA0, 0x40);
            var3 = var1[3] % 10;
            DmaCopy16(3, gDecimalDigitTilesGfx[var3], (void *)0x6015E60, 0x40);
        }
        break;
    case 18:
        DmaCopy16(3, gMainBoardBallSave_Gfx, (void *)0x6015800, 0x2400);
        break;
    case 19:
        DmaCopy16(3, gMainBoardEndOfBall_Gfx, (void *)0x6015800, 0x2800);
        break;
    case 20:
        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gRubyBoardBonusGfx, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gRubyBoardBonusObjPalette, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        else
        {
            DmaCopy16(3, gSapphireBoardBonusGfx, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gSapphireBoardBonusObjPalette, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        break;
    case 21:
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x6015800, 0xC00);
        break;
    }
}

void RestoreMainFieldDynamicGraphics(void)
{
    s16 i;
    s16 var0;

    LoadCatchSpriteGraphics();
    LoadEggSpriteGraphics();

    for (i = 0; i <= 1; i++)
    {
        var0 = gCurrentPinballGame->flipper[i].position / 2;
        DmaCopy16(3, gFlipperTileGraphics[var0], ((i * 0x200) + 0x06010000), 0x200);
    }

    var0 = gCurrentPinballGame->ball->spinAngle / 0x1000;
    DmaCopy16(3, gBallRotationTileGraphics[var0], 0x06010400, 0x80);

    for (i = 0; i <= 1; i++)
    {
        DmaCopy16(3, gPikaSaverTilesGfx + ((var0 =gCurrentPinballGame->pikaSaverTileIndex[i]) * 0x180), 0x06010480 + (i * 0x180), 0x180);
    }

    var0 = gCurrentPinballGame->pikachuSpinFrame;
    DmaCopy16(3, gMainBoardPikaSpinner_Gfx[var0 = gCurrentPinballGame->pikachuSpinFrame], 0x06010780, 0x120);
    var0 = gCurrentPinballGame->chargeFillValue;
    DmaCopy16(3, gChargeFillIndicator_Gfx[var0], 0x06010AE0, 0x80);

    for (i = 0; i <= 1; i++)
    {
        switch (gCurrentPinballGame->portraitRenderMode[i])
        {
        case 0:
            DmaCopy16(3, gPortraitGenericGraphics[gCurrentPinballGame->portraitGfxIndex[i]], 0x06010CA0 + (i * 0x300), 0x300);
            gCurrentPinballGame->ball += 0; //TODO: Dumb match is still a match...
            break;
        case 9:
            if (gCurrentPinballGame->evoChainPosition > 0)
            {
                if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == 0)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = 205;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
                else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] <= 3)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, 0x050003A0, 0x20);
                }
                else
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
            }
            else
            {
                gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->currentSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15] + ((gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x20), 0x050003A0, 0x20);
            }
        case 3:
            DmaCopy16(3, gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x300, 0x06010CA0 + (i * 0x18), 0x300);
            break;
        case 1:
        case 2:
        case 4:
        case 6:
        case 7:
        case 8:
            DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[i]], 0x06010CA0 + (i * 0x300), 0x300);
            break;
        }
    }

    if (gCurrentPinballGame->boardState == 4)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case 7:
        case 8:
            if ((u32) gCurrentPinballGame->captureFlashTimer > 4)
            {
                DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
            }
            break;
        case 9:
            if (gCurrentPinballGame->captureSequenceTimer <= 31)
            {
                if (gCurrentPinballGame->captureFlashTimer > 4)
                {
                    DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
                }
            }
            break;
        }
    }

    if (gCurrentPinballGame->boardState == 8)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case 2:
            if (gCurrentPinballGame->captureFlashTimer > 4U)
            {
                DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
            }
            break;
        case 3:
            if (gCurrentPinballGame->captureSequenceTimer <= 31)
            {
                if (gCurrentPinballGame->captureFlashTimer > 4U)
                {
                    DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
                }
            }
            break;
        }
    }

    DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->bonusTrapAnimFrame], 0x060113C0, 0x300);
    DmaCopy16(3, gEvoItemTilesGfxPtrs[gCurrentPinballGame->evoItemGfxIndex] +  var0 * 0x200, 0x060116C0, 0x200);
    DmaCopy16(3, gEggFrameTilesGfx[(s16)gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3]], 0x06011CE0, 0x200);
    DmaCopy16(3, gBallShadowTileGraphics[gCurrentPinballGame->ballShadowTileIndex], 0x06011EE0, 0x200);
    return;
}


void RestoreRubyBoardTileGraphics(void)
{
    s16 i;
    s16 var0;

    var0 = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][2];
    DmaCopy16(3, gRubyBoardHatchCave_Gfx[var0], (void *)0x60122A0, 0x480);
    var0 = (gMain.systemFrameCount % 50) / 25;
    DmaCopy16(3, gRubyFlashingDecorationTiles[var0], (void *)0x6012720, 0x300);
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->catchHoleTileVariant], (void *)0x6012C20, 0x260);
    for (i = 0; i < 2; i++)
        DmaCopy16(3, gRubyFlashingTiles_Secondary[var0], (void *)0x6010000 + (0x174 + i * 8) * 0x20, 0x100);

    var0 = gCurrentPinballGame->shopDoorCurrentFrame & 0xF;
    DmaCopy16(3, gRubyBoardShopDoor_Gfx[var0], (void *)0x6013180, 0x180);
    if (gCurrentPinballGame->eggCaveState < 3)
        gCurrentPinballGame->cyndaquilFrame = 0;
    else
        gCurrentPinballGame->cyndaquilFrame = 1;

    DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilFrame], (void *)0x6013300, 0x280);
    var0 = gEvoShopAnimFrames[gCurrentPinballGame->evolutionShopActive][(gCurrentPinballGame->shopAnimTimer % 42) / 6];
    DmaCopy16(3, gRubyBoardShop_Gfx[var0], (void *)0x6013D00, 0x500);
}

void RestoreSapphireBoardTileGraphics(void)
{
    s16 index;

    switch (gCurrentPinballGame->holeLetterSystemState)
    {
    case 0:
    case 1:
    case 2:
        index = gCurrentPinballGame->holeLetterCount;
        DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        break;
    case 3:
    case 4:
        index = 15;
        DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        break;
    case 5:
        index = gHoleAnimKeyframeData[gCurrentPinballGame->holeLetterCount][0];
        DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        break;
    case 6:
        break;
    }
}

void RestoreDusclopsBonusGraphics(void)
{
    DmaCopy16(3, gDusclopsBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void RestoreKecleonBonusGraphics(void)
{
    DmaCopy16(3, gKecleonBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void RestoreKyogreBonusGraphics(void)
{
    DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x6015800, 0x2000);
    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreGroudonBonusGraphics(void)
{
    if (gCurrentPinballGame->boardState < 2)
    {
        DmaCopy16(3, gGroudonBoardBackgroundGfx, (void *)0x6015800, 0x2000);
    }
    else
    {
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreRayquazaBonusGraphics(void)
{
    u8 var0;

    if (gCurrentPinballGame->boardState == 0)
    {
        DmaCopy16(3, gRayquazaSkyBackgroundGfx, (void *)0x6015800, 0x2800);
    }
    else if (gCurrentPinballGame->boardState == 1)
    {
        DmaCopy16(3, gRayquazaWindBoardGfx, (void *)0x6015800, 0x1C00);
    }
    else
    {
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    var0 = gCurrentPinballGame->bossEntityState - 2;
    if (var0 > 9)
    {
        DmaCopy16(3, gRayquazaSpriteSheet, (void *)0x6011620, 0x860);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreSphealBonusGraphics(void)
{
    s16 i;
    int var0;
    u16 var1;

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[0x400 + i] = 0x200;

    DmaCopy16(3, &gBG0TilemapBuffer[0x400], (void *)0x6001000, 0x1000);
    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        var0 = i;
        if (i < 0)
            var0 += 31;

        var0 = (var0 >> 5) << 5;
        var1 = i - var0 - 2;
        if (var1 < 28)
            gBG0TilemapBuffer[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].xOffset = 8;
    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gBG0TilemapBuffer[0x800], (void *)0x6001140, 0x280);
    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gSphealResultsScreenGfx, (void *)0x6015800, 0x800);
}

void nullsub_18(void)
{
}
