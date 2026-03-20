#include "global.h"
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

extern const struct BoardProcessPair BoardProcPairs_086B077C[];
extern const VoidFunc gFieldInitFuncs[];
extern struct SpriteGroup *gMainFieldSpriteGroups[][60];
extern struct SpriteGroup *gBonusFieldSpriteGroups[][30];

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gDxModePikachuObjTiles[];

extern void SaveGameToSram(void);
extern void RestoreGameState(u16);

void ClampPortraitSpritesToOffscreen(void);
void SetBallPositionForBonusReturn(void);
void ClearBG0Tilemap(void);
static void SetupDisplayRegistersForField(void);
void InitPinballGameState(void);
void ConfigureBoardProcessesForField(void);
void UpdateButtonActionsFromJoy(void);
void ReplayButtonActionsFromRecording(void);

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
        loadFieldBoardGraphics();
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
        loadFieldBoardGraphics();
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
        loadFieldBoardGraphics();
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