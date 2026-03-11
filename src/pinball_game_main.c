#include "global.h"
#include "agb_sram.h"
#include "main.h"
#include "m4a.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/ruby_states.h"

extern struct PinballGame gUnknown_02000000;

typedef void (*VoidFunc)(void);

struct BoardProcessPair
{
    void (*init)(void);
    void (*update)(void);
};

extern struct BoardProcessPair CurrentBoardProcPairs_020028D8[9];
extern u8 gUnknown_0200FBB0[];
extern u8 gBgTilemapBuffer[];

extern const struct BoardProcessPair BoardProcPairs_086B077C[];
extern const VoidFunc gUnknown_086B085C[];
extern struct SpriteGroup *gMainFieldSpriteGroups[][60];
extern struct SpriteGroup *gBonusFieldSpriteGroups[][30];
extern const u8 gUnknown_08158284[];
extern const u8 gUnknown_083A704C[];
extern const u8 gUnknown_0848FD8C[];
extern const u8 gUnknown_081428D4[];
extern const u8 gUnknown_081BCAA4[];
extern const u8 gUnknown_081BE2C4[];
extern const u8 gUnknown_081BE4C4[];
extern const u8 gUnknown_081BFCE4[];
extern const u8 gUnknown_0839C78C[];
extern const u8 gUnknown_0839DDAC[];
extern const u8 gUnknown_083A07CC[];
extern const u8 gUnknown_083A29EC[];
extern const u8 gUnknown_083A340C[];
extern const u8 gUnknown_083A562C[];
extern const u8 gUnknown_083FF04C[][0x40];
extern const u8 gUnknown_083FFD4C[0x40];
extern const u8 gUnknown_08480E0C[][0x40];
extern const u8 gUnknown_084F61EC[];
extern const u8 gUnknown_084FA20C[];
extern const u8 gMainBoardBallSave_Gfx[];
extern const u8 gMainBoardEndOfBall_Gfx[];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];
extern const s16 gUnknown_086ACFE0[];
extern const u16 gUnknown_086AD2DE[];
extern const u8 *gEvoItemAppear_GfxList[];
extern const s16 gUnknown_086AD456[][7];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u8 gUnknown_083C3C2C[][0x300];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const u8 gUnknown_083C806C[][0x100];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardShop_Gfx[][0x500];
extern const u8 gUnknown_08490A4C[][0x440];
extern const s16 gUnknown_086AE5A0[][2];
extern const u8 gKecleonBonusClear_Gfx[0x2000];
extern const u8 gKyogreBonusClear_Gfx[0x2000];
extern const u8 gUnknown_0849F1CC[0x2000];
extern const u8 gGroudonBonusClear_Gfx[0x2000];
extern const u8 gUnknown_083C5A2C[0x2800];
extern const u8 gUnknown_084A856C[0x1C00];
extern const u8 gRayquazaBonusClear_Gfx[0x2000];
extern const u8 gUnknown_084AA18C[0x860];
extern const u8 gUnknown_084B77EC[0x800];

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gUnknown_084C0C6C[];

void UpdateRubyBonusFieldYPositions(void);
void InitBallPosition(void);
void ClearAllBgScreenBuffer(void);
static void ConfigureDisplayForField(void);
void InitPinballGameState(void);
void ConfigureBoardProcesses(void);
void UpdateButtonActionsFromJoy(void);
void UpdateButtonActionsFromDemo(void);
void SaveBoardStateForPause(s16);
void WriteSaveStateToSram(void);
void RestoreBoardStateFromSave(u16);
void RestoreFieldGraphics(void);
void RestoreMainFieldSprites(void);
void RestoreRubyFieldTiles(void);
void RestoreSapphireFieldTiles(void);
void RestoreBonusFieldCommonGfx(void);
void RestoreDusclopsBonusFieldGfx(void);
void RestoreKecleonBonusFieldGfx(void);
void RestoreKyogreBonusFieldGfx(void);
void RestoreGroudonBonusFieldGfx(void);
void RestoreRayquazaBonusFieldGfx(void);
void RestoreSphealBonusFieldGfx(void);


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

    StartGbPlayerCommunication();
    gCurrentPinballGame = &gUnknown_02000000;
    ResetSomeGraphicsRelatedStuff();
    gMain.gameIdleState = 0;
    if (gMain.isResuming)
        var0 = 0;
    else if (gMain.currentField == gMain.selectedField)
        var0 = 1;
    else if (gMain.selectedField < MAIN_FIELD_COUNT)
        var0 = 2;
    else
        var0 = 3;

    switch (var0)
    {
    case 0:
        ConfigureDisplayForField();
        InitPinballGameState();
        loadIntroduction();
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);

        ConfigureBoardProcesses();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].init();

        m4aMPlayAllStop();
        ClearAllBgScreenBuffer();
        InitPinballGameState();
        if (gMain.mainState == STATE_GAME_IDLE)
            RestoreBoardStateFromSave(2);
        else
            RestoreBoardStateFromSave(1);

        ConfigureDisplayForField();
        ConfigureBoardProcesses();
        gUnknown_086B085C[gMain.isBonusField]();
        if (gMain.selectedField == FIELD_RUBY || gMain.selectedField == FIELD_SAPPHIRE)
            UpdateRubyBonusFieldYPositions();
        else if (gMain.selectedField == FIELD_DUSCLOPS)
            UpdatePointerSpritePosition();
        else if (gMain.selectedField == FIELD_KYOGRE)
            HideKyogreShockwaveSprite();
        else if (gMain.selectedField == FIELD_GROUDON)
            HideGroudonShockwaveSprite();
        break;
    case 1:
        ConfigureDisplayForField();
        InitPinballGameState();
        loadIntroduction();
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);

        ConfigureBoardProcesses();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].init();

        ClearAllBgScreenBuffer();
        break;
    case 2:
        ConfigureDisplayForField();
        InitBallPosition();
        RestoreBoardStateFromSave(0);
        ConfigureBoardProcesses();
        gUnknown_086B085C[gMain.isBonusField]();
        if (gMain.selectedField == FIELD_RUBY)
            SetBoardFieldCollisionData(1);

        SetBoardPortraitGraphics(0, 0);
        gCurrentPinballGame->hatchRevealState = 0;
        break;
    case 3:
        ConfigureDisplayForField();
        InitPinballGameState();
        loadIntroduction();
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        ConfigureBoardProcesses();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].init();

        ClearAllBgScreenBuffer();
        break;
    }

    gBoardConfig.demoFrameCount = 0;
    for (j = 0; j < NUM_SPECIES; j++)
    {
        if (gMain_saveData.pokedexFlags[j] > SPECIES_SHARED_AND_SEEN)
            gBoardConfig.demoFrameCount++;
    }

    EnableVBlankProcessing();
    FadeInFromWhite();
    gCurrentPinballGame->pauseInputLocked = 0;
    gMain.updateBlendRegisters = 1;

    switch (var0)
    {
    case 0:
        if (gMain.mainState != STATE_GAME_IDLE && gCurrentPinballGame->savedBgmSongHeader && gMPlayInfo_BGM.status < 0)
            MPlayStart(&gMPlayInfo_BGM, gCurrentPinballGame->savedBgmSongHeader);
        if (gMain.selectedField < MAIN_FIELD_COUNT)
            RestoreBoardPalettesAfterMenu(gCurrentPinballGame->paletteCycleIndex);
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

static void ConfigureDisplayForField(void)
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
    gMain.debugOption = 0;
    gMain.fieldFrameCount = 0;
    gMain.pendingModeChangeFlags = 0;
    gMain.stateTimer = 0;
    gMain.modeTransitionDelay = 0;
    gMain.vCount = 144;
    gMain.splitScreenEnabled = 0;
    gMain.splitScreenOffset = 0;
    gMain.updateBlendRegisters = 0;
    gMain.blendControl = 0;
    gMain.blendAlpha = 0;
    gMain.blendBrightness = 0;
    if (gMain.currentField == gMain.selectedField)
    {
        DmaFill16(3, 0, gCurrentPinballGame, sizeof(struct PinballGame));
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
        {
            gCurrentPinballGame->pikaChargeTarget = 168;
            gCurrentPinballGame->pikaChargeDisplay = 168;
            gCurrentPinballGame->pikaChargeSegmentPrev = 13;
            gCurrentPinballGame->pikaChargeSegment = 13;
            gCurrentPinballGame->pikaChargeAnimDuration = 0;
            gCurrentPinballGame->pikaChargeSpriteOffsetX = 0;
            gCurrentPinballGame->pikaChargeSpriteY = 120;
            gCurrentPinballGame->pikaChargeFullFlashTimer = 60;
            DmaCopy16(3, gUnknown_084C0C6C, (void *)OBJ_VRAM0 + 0x600, 0x180);
            gCurrentPinballGame->outLanePikaPosition = 2;
            gMain.boardSpriteGroups[41]->available = FALSE;
            gCurrentPinballGame->pikaSaverAnimTimer = 1;
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
            gCurrentPinballGame->numLives = 9;
            gCurrentPinballGame->coins = 99;
        }
        else
        {
            gCurrentPinballGame->pikaChargeSpriteOffsetX = 0;
            gCurrentPinballGame->pikaChargeSpriteY = -4;
            gCurrentPinballGame->numLives = 2;
            gCurrentPinballGame->coins = 10;
        }
    }

    if (gMain.mainState != STATE_GAME_IDLE)
        gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

    gCurrentPinballGame->scoreAddStepSize = 40000;
    gCurrentPinballGame->gamePhase = 0;
    gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
    gCurrentPinballGame->ballInstancesBase = &gCurrentPinballGame->ballInstances[0];
    gCurrentPinballGame->activeBallIndex = 0;
}

void InitBallPosition(void)
{
    switch (gCurrentPinballGame->ballReturnMode)
    {
    case 0:
        gCurrentPinballGame->ball->positionQ0.x = 119;
        gCurrentPinballGame->ball->positionQ0.y = 279;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->isGrabbed = 1;
        gCurrentPinballGame->ballLockState = 1;
        gCurrentPinballGame->ballSpriteVariant = 0;
        gCurrentPinballGame->sequenceTimer = 120;
        gCurrentPinballGame->boardEntryMode = 4;
        if (gMain.selectedField == FIELD_RUBY)
            UpdateBoardEntryHole();
        else
            UpdateSapphireBoardEntryMode();

        gCurrentPinballGame->cameraScrollX = 0;
        gCurrentPinballGame->cameraScrollY = 215;
        break;
    case 1:
        gCurrentPinballGame->ball->positionQ0.x = 140;
        gCurrentPinballGame->ball->positionQ0.y = 183;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->isGrabbed = 1;
        gCurrentPinballGame->ballLockState = 1;
        gCurrentPinballGame->ballSpriteVariant = 0;
        gCurrentPinballGame->whiscashState = WHISCASH_STATE_INIT_RETURN_FROM_BONUS;
        gCurrentPinballGame->cameraScrollX = 0;
        gCurrentPinballGame->cameraScrollY = 118;
        break;
    case 2:
        gCurrentPinballGame->ball->positionQ0.x = -28;
        gCurrentPinballGame->ball->positionQ0.y = -10;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->isGrabbed = 1;
        gCurrentPinballGame->ballLockState = 1;
        gCurrentPinballGame->ballSpriteVariant = 0;
        gCurrentPinballGame->entityMovementTimer = 0;
        gCurrentPinballGame->pelipperState = 7;
        gCurrentPinballGame->cameraScrollX = 0;
        gCurrentPinballGame->cameraScrollY = 0;
        break;
    }

    gCurrentPinballGame->scrollNudgeY = 0;
    gCurrentPinballGame->scrollNudgeTargetY = 0;
    gCurrentPinballGame->scrollNudgeActive = 0;
    gCurrentPinballGame->cameraScrollYQ8 = gCurrentPinballGame->cameraScrollY << 8;
    gCurrentPinballGame->bgScrollXCopy = gCurrentPinballGame->cameraScrollX;
    gCurrentPinballGame->bgScrollYWithOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->scrollNudgeY;

    gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraScrollX;
    gMain.bgOffsets[2].yOffset = gCurrentPinballGame->cameraScrollY;
    gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraScrollX;
    gMain.bgOffsets[3].yOffset = gCurrentPinballGame->cameraScrollY;
    gMain.bgOffsets[1].xOffset = gCurrentPinballGame->cameraScrollX;
    gMain.bgOffsets[1].yOffset = gCurrentPinballGame->cameraScrollY;
    gMain.bgOffsets[0].yOffset = 80;

    gCurrentPinballGame->bgTargetScrollY = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->tilemapRowIndex = gMain.bgOffsets[3].yOffset / 8;
}

void ConfigureBoardProcesses(void)
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
        gMain.boardSpriteGroups = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_SAPPHIRE:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[4];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[16];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[20];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[11];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[1];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[13];
        gMain.boardSpriteGroups = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_DUSCLOPS:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[5];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[21];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.boardSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KECLEON:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[6];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[22];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.boardSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KYOGRE:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[7];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[23];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.boardSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_GROUDON:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[8];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[24];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.boardSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_RAYQUAZA:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[9];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[25];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.boardSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_SPHEAL:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[10];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[26];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.boardSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    }
}

void PinballGame_State1_4AAD8(void)
{
    switch (gCurrentPinballGame->gamePhase)
    {
    case 0:
        gCurrentPinballGame->gamePhase = 1;
        gMain.gameIdleState = 0;
        break;
    case 1:
        gUnknown_086B085C[gMain.isBonusField]();
        if (JOY_HELD(A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON) == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
            gMain.gameIdleState = 1;

        if (gMain.gameIdleState)
        {
            if (gMain.selectedField < MAIN_FIELD_COUNT)
            {
                UpdateRubyBonusFieldYPositions();
                RestoreBoardPalettesAfterMenu(0);
            }
            else if (gMain.selectedField == FIELD_DUSCLOPS)
            {
                UpdatePointerSpritePosition();
            }
            else if (gMain.selectedField == FIELD_KYOGRE)
            {
                HideKyogreShockwaveSprite();
            }
            else if (gMain.selectedField == FIELD_GROUDON)
            {
                HideGroudonShockwaveSprite();
            }

            if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
                DmaCopy16(3, gCurrentPinballGame->savedObjPaletteForPause, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);

            gCurrentPinballGame->gamePhase = 2;
            if (gMain.gameIdleState == 2)
                SaveBoardStateForPause(1);
        }
        break;
    case 2:
        gMain.subState++;
        break;
    }

    UpdateGbPlayerRumble();
}

//Note: Used by both the main game mode and the idle game mode
//gMain.subState = 2 in both.
void PinballGame_State2_4ABC8(void)
{
    ResetGbPlayerState();
    if (IsGbPlayerCommDone())
    {
        RestoreDefaultInterrupts();
        gMain.subState++;
    }
}

void RunMainBoardFrame(void)
{
    s16 i;

    UpdateButtonActionsFromJoy();
    CurrentBoardProcPairs_020028D8[1].update();
    if (gMain.gameIdleState == 0 && !(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[2].update();
        CurrentBoardProcPairs_020028D8[0].update();
        CurrentBoardProcPairs_020028D8[3].update();
        CurrentBoardProcPairs_020028D8[4].update();
        if (gMain.modeChangeFlags)
        {
            if (!gCurrentPinballGame->ballLockState)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->currentProcessPass = i;
                    CurrentBoardProcPairs_020028D8[6].update();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->gameFrameCount++;
            if (gCurrentPinballGame->ballLockState)
            {
                if (gCurrentPinballGame->ballLockState != 2)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->currentProcessPass = i;
                        CurrentBoardProcPairs_020028D8[5].update();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->currentProcessPass = i;
                    CurrentBoardProcPairs_020028D8[5].update();
                    CurrentBoardProcPairs_020028D8[6].update();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].update();
        CurrentBoardProcPairs_020028D8[8].update();
    }

    UpdateBgTilemapOnScroll();
}

void RunIdleBoardFrame(void)
{
    s16 i;

    UpdateButtonActionsFromDemo();
    CurrentBoardProcPairs_020028D8[1].update();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[2].update();
        CurrentBoardProcPairs_020028D8[0].update();
        CurrentBoardProcPairs_020028D8[3].update();
        CurrentBoardProcPairs_020028D8[4].update();
        if (gMain.modeChangeFlags)
        {
            if (!gCurrentPinballGame->ballLockState)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->currentProcessPass = i;
                    CurrentBoardProcPairs_020028D8[6].update();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->gameFrameCount++;
            if (gCurrentPinballGame->ballLockState)
            {
                if (gCurrentPinballGame->ballLockState != 2)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->currentProcessPass = i;
                        CurrentBoardProcPairs_020028D8[5].update();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->currentProcessPass = i;
                    CurrentBoardProcPairs_020028D8[5].update();
                    CurrentBoardProcPairs_020028D8[6].update();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].update();
        CurrentBoardProcPairs_020028D8[8].update();
    }

    UpdateBgTilemapOnScroll();
    if ((gMain.systemFrameCount % 32) / 16 > 0)
    {
        for (i = 0; i < 10; i++)
            gBgScreenBuffer[0x34A + i] = 0xC156 + i;
    }
    else
    {
        for (i = 0; i < 10; i++)
            gBgScreenBuffer[0x34A + i] = 0x1FF;
    }

    DmaCopy16(3, &gBgScreenBuffer[0x340], (void *)0x6002680, 0x40);
}

void RunBonusBoardFrame(void)
{
    s16 i;

    UpdateButtonActionsFromJoy();
    CurrentBoardProcPairs_020028D8[1].update();
    if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
        return;

    CurrentBoardProcPairs_020028D8[0].update();
    CurrentBoardProcPairs_020028D8[2].update();
    CurrentBoardProcPairs_020028D8[3].update();
    CurrentBoardProcPairs_020028D8[4].update();
    if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
    {
        if (!gCurrentPinballGame->ballLockState)
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->activeBallIndex = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                gCurrentPinballGame->currentProcessPass = i;
                CurrentBoardProcPairs_020028D8[6].update();
            }
        }
    }
    else
    {
        gMain.fieldFrameCount++;
        gCurrentPinballGame->gameFrameCount++;
        if (gCurrentPinballGame->ballLockState)
        {
            if (gCurrentPinballGame->ballLockState == 2)
            {
                gCurrentPinballGame->activeBallIndex = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                gCurrentPinballGame->currentProcessPass = 0;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                    gCurrentPinballGame->currentProcessPass = i;
                    CurrentBoardProcPairs_020028D8[5].update();
                }
            }
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->activeBallIndex = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                gCurrentPinballGame->currentProcessPass = i;
                CurrentBoardProcPairs_020028D8[5].update();
                CurrentBoardProcPairs_020028D8[6].update();
            }
        }
    }

    CurrentBoardProcPairs_020028D8[7].update();
    CurrentBoardProcPairs_020028D8[8].update();
}

void RunIdleBonusBoardFrame(void)
{
    s16 i;

    UpdateButtonActionsFromDemo();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[0].update();
        CurrentBoardProcPairs_020028D8[2].update();
        CurrentBoardProcPairs_020028D8[3].update();
        CurrentBoardProcPairs_020028D8[4].update();
        if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
        {
            if (!gCurrentPinballGame->ballLockState)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                    gCurrentPinballGame->currentProcessPass = i;
                    CurrentBoardProcPairs_020028D8[6].update();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->gameFrameCount++;
            if (gCurrentPinballGame->ballLockState)
            {
                if (gCurrentPinballGame->ballLockState == 2)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                    gCurrentPinballGame->currentProcessPass = 0;
                }
                else
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->activeBallIndex = 0;
                        gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                        gCurrentPinballGame->currentProcessPass = i;
                        CurrentBoardProcPairs_020028D8[5].update();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
                    gCurrentPinballGame->currentProcessPass = i;
                    CurrentBoardProcPairs_020028D8[5].update();
                    CurrentBoardProcPairs_020028D8[6].update();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].update();
        CurrentBoardProcPairs_020028D8[8].update();
    }

    if ((gMain.systemFrameCount % 32) / 16 > 0)
    {
        for (i = 0; i < 9; i++)
            gBgScreenBuffer[0x32B + i] = 0xC156 + i;
    }
    else
    {
        for (i = 0; i < 9; i++)
            gBgScreenBuffer[0x32B + i] = 0x1FF;
    }

    DmaCopy16(3, &gBgScreenBuffer[0x320], (void *)0x6002640, 0x40);
}

void PinballGame_State3_4B20C(void)
{
    gMain.updateBlendRegisters = 0;
    FadeOutToWhite();
    m4aMPlayAllStop();
    DisableVBlankProcessing();
    gMain.finalScoreLo = gCurrentPinballGame->scoreLo;
    gMain.finalScoreHi = gCurrentPinballGame->scoreHi;
    if (gMain.gameIdleState == 2)
        WriteSaveStateToSram();

    if (gMain.gameIdleState == 0)
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

void PinballGameState_NoOp(void)
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

void UpdateButtonActionsFromDemo(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gCurrentPinballGame->newButtonActions[i] = 0;
        gCurrentPinballGame->releasedButtonActions[i] = 0;
    }

    if (gMain.modeChangeFlags)
        return;

    if (gDemoPlaybackFrame < 60 * 60)
    {
        for (i =  0; i < 5; i++)
        {
            gCurrentPinballGame->newButtonActions[i] = (gBoardConfig.demoInputData[gDemoPlaybackFrame].newPresses >> i) & 0x1;
            gCurrentPinballGame->releasedButtonActions[i] = (gBoardConfig.demoInputData[gDemoPlaybackFrame].releases >> i) & 0x1;
            gCurrentPinballGame->heldButtonActions[i] = (gBoardConfig.demoInputData[gDemoPlaybackFrame].held >> i) & 0x1;
        }

        gDemoPlaybackFrame++;
    }

    if (gCurrentPinballGame->newButtonActions[1])
        gMain.newKeys = A_BUTTON;
}

void SaveBoardStateForPause(s16 arg0)
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
        gCurrentPinballGame->savedSpriteGroupAvailable[gMain.isBonusField][i] = gMain.spriteGroups[i].available;

    DmaCopy16(3, (void *)OBJ_PLTT, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], OBJ_PLTT_SIZE);
    DmaCopy16(3, (void *)BG_PLTT, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], BG_PLTT_SIZE);
    if (!arg0)
        return;

    gCurrentPinballGame->bgOffsets0 = gMain.bgOffsets[0];
    gCurrentPinballGame->bgOffsets1 = gMain.bgOffsets[1];
    gCurrentPinballGame->bgOffsets2 = gMain.bgOffsets[2];
    gCurrentPinballGame->bgOffsets3 = gMain.bgOffsets[3];
    gCurrentPinballGame->field = gMain.selectedField;
    gCurrentPinballGame->savedCurrentField = gMain.currentField;
    gCurrentPinballGame->savedIsBonusField = gMain.isBonusField;
    gCurrentPinballGame->savedModeChangeFlags = gMain.modeChangeFlags;
    gCurrentPinballGame->savedDebugOption = gMain.debugOption;
    gCurrentPinballGame->savedPendingModeChangeFlags = gMain.pendingModeChangeFlags;
    gCurrentPinballGame->unk1320 = gMain.stateTimer;
    gCurrentPinballGame->unk1322 = gMain.modeTransitionDelay;
    gCurrentPinballGame->unk1324 = gMain.splitScreenEnabled;
    gCurrentPinballGame->unk1326 = gMain.splitScreenOffset;
    gCurrentPinballGame->savedBlendControlForRestore = gCurrentPinballGame->savedBlendControl;
    gCurrentPinballGame->savedBlendAlphaForRestore = gCurrentPinballGame->savedBlendAlpha;
    gCurrentPinballGame->savedBlendBrightnessForRestore = gCurrentPinballGame->savedBlendBrightness;
    gCurrentPinballGame->savedBlendScanlineEnabledForRestore = gCurrentPinballGame->savedBlendScanlineEnabled;
    gCurrentPinballGame->savedVCountForRestore = gCurrentPinballGame->savedVCount;
    gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gCurrentPinballGame->eReaderBonuses[i] = gMain.eReaderBonuses[i];
}

void WriteSaveStateToSram(void)
{
    gCurrentPinballGame->hasSavedState = 1;
    WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(*gCurrentPinballGame));
}

void RestoreBoardStateFromSave(u16 arg0)
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
        DmaCopy16(3, gBoardConfig.initialGameState, gCurrentPinballGame, sizeof(*gCurrentPinballGame));
        gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
        gCurrentPinballGame->ballInstancesBase = &gCurrentPinballGame->ballInstances[0];
        var2 = gMain.idleDemoIndex;
        if ((var2 & 0x3) == 1)
        {
            gCurrentPinballGame->lastBallImpactVelocityY = 0;
            gCurrentPinballGame->outLanePikaAnimSubFrame = 0;
            gCurrentPinballGame->outLanePikaAnimKeyframe = 0;
            gCurrentPinballGame->pikaChargeTarget = 0;
            gCurrentPinballGame->pikaChargeDisplay = 0;
            gCurrentPinballGame->pikaChargeSegmentPrev = 0;
            gCurrentPinballGame->pikaChargeSegment = 0;
            gCurrentPinballGame->pikaChargeSpriteOffsetX = 0;
            gCurrentPinballGame->pikaChargeSpriteY = -4;
            gCurrentPinballGame->pikaChargeSpriteScaleX = 256;
            gCurrentPinballGame->pikaChargeSpriteScaleY = 256;
            gCurrentPinballGame->pikaChargeFlashTimer = 0;
            gCurrentPinballGame->pikaChargeAnimDuration = 0;
        }
    }

    if (arg0 != 0)
    {
        gMain.selectedField = gCurrentPinballGame->field;
        gMain.currentField = gCurrentPinballGame->savedCurrentField;
        gMain.isBonusField = gCurrentPinballGame->savedIsBonusField;
        gMain.modeChangeFlags = gCurrentPinballGame->savedModeChangeFlags;
        gMain.debugOption = gCurrentPinballGame->savedDebugOption;
        gMain.pendingModeChangeFlags = gCurrentPinballGame->savedPendingModeChangeFlags;
        gMain.stateTimer = gCurrentPinballGame->unk1320;
        gMain.modeTransitionDelay = gCurrentPinballGame->unk1322;
        gMain.splitScreenEnabled = gCurrentPinballGame->unk1324;
        gMain.splitScreenOffset = gCurrentPinballGame->unk1326;
        gMain.blendControl = gCurrentPinballGame->savedBlendControlForRestore;
        gMain.blendAlpha = gCurrentPinballGame->savedBlendAlphaForRestore;
        gMain.blendBrightness = gCurrentPinballGame->savedBlendBrightnessForRestore;
        gMain.blendScanlineEnabled = gCurrentPinballGame->savedBlendScanlineEnabledForRestore;
        gMain.vCount = gCurrentPinballGame->savedVCountForRestore;
        gMain.bgOffsets[0] = gCurrentPinballGame->bgOffsets0;
        gMain.bgOffsets[1] = gCurrentPinballGame->bgOffsets1;
        gMain.bgOffsets[2] = gCurrentPinballGame->bgOffsets2;
        gMain.bgOffsets[3] = gCurrentPinballGame->bgOffsets3;
        for (i = 0; i < NUM_EREADER_CARDS; i++)
            gMain.eReaderBonuses[i] = gCurrentPinballGame->eReaderBonuses[i];

        gCurrentPinballGame->pauseInputLocked = 1;
        if (arg0 == 1 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->viewportBottomY = gCurrentPinballGame->cameraScrollY +
                                         gCurrentPinballGame->shakeOffsetY +
                                         gCurrentPinballGame->scrollNudgeY +
                                         gCurrentPinballGame->fieldScrollOffsetY;
        }
    }
    else
    {
        gCurrentPinballGame->viewportBottomY = gCurrentPinballGame->viewportBottomYPrev;
    }

    gCurrentPinballGame->gamePhase = 0;
    gMain.isResuming = 0;
    loadIntroduction();
    if (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->rubyAbsorbZoneActive)
        SetBoardFieldCollisionData(1);

    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        for (i = 0; i < 22; i++)
        {
            var0 = i + gCurrentPinballGame->tilemapRowIndex;
            var1 = (i + 10 + gCurrentPinballGame->tilemapRowIndex) % 22;
            if (var0 < 32)
            {
                DmaCopy16(3, &gUnknown_0200FBB0[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
            else
            {
                var0 -= 32;
                DmaCopy16(3, &gBgTilemapBuffer[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
        }
    }

    for (i = 0; i < 0x800; i++)
        gBgScreenBuffer[i] = 0x1FF;

    DmaCopy16(3, gBgScreenBuffer, (void *)0x6002000, 0x1000);
    if (gMain.blendScanlineEnabled)
    {
        if (gCurrentPinballGame->boardState == 6)
        {
            for (j = 0; j <= gCurrentPinballGame->blendScanlineWidth; j++)
            {
                for (i = 2; i < 12; i++)
                    gBgScreenBuffer[(i + 15) * 0x20 + j] = 0xC100;
            }
        }
        else
        {
            for (j = 0; j <= gCurrentPinballGame->blendScanlineWidth; j++)
            {
                for (i = 1; i < 11; i++)
                    gBgScreenBuffer[(i + 15) * 0x20 + j] = 0xC100;
            }
        }

        DmaCopy16(3, gBgScreenBuffer, (void *)0x6002000, 0x800);
    }

    DmaCopy16(3, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    RestoreFieldGraphics();
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        RubyBoardProcess_0A_50848();
        CopyRubyTrapGfxToVram(gCurrentPinballGame->trapDisplayState);
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
        gMain.spriteGroups[i].available = gCurrentPinballGame->savedSpriteGroupAvailable[gMain.isBonusField][i];

    if (arg0 == 1)
    {
        gCurrentPinballGame->hasSavedState = 0;
        WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(gCurrentPinballGame->hasSavedState));
    }
}

void RestoreFieldGraphics(void)
{
    s16 i;
    struct PokemonSpecies *species;
    const u16 *var1;
    s16 var2, var3;

    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        RestoreMainFieldSprites();
        RestoreRubyFieldTiles();
        break;
    case FIELD_SAPPHIRE:
        RestoreMainFieldSprites();
        RestoreSapphireFieldTiles();
        break;
    case FIELD_DUSCLOPS:
        RestoreBonusFieldCommonGfx();
        RestoreDusclopsBonusFieldGfx();
        break;
    case FIELD_KECLEON:
        RestoreBonusFieldCommonGfx();
        RestoreKecleonBonusFieldGfx();
        break;
    case FIELD_KYOGRE:
        RestoreBonusFieldCommonGfx();
        RestoreKyogreBonusFieldGfx();
        break;
    case FIELD_GROUDON:
        RestoreBonusFieldCommonGfx();
        RestoreGroudonBonusFieldGfx();
        break;
    case FIELD_RAYQUAZA:
        RestoreBonusFieldCommonGfx();
        RestoreRayquazaBonusFieldGfx();
        break;
    case FIELD_SPHEAL:
        RestoreBonusFieldCommonGfx();
        RestoreSphealBonusFieldGfx();
        break;
    }

    switch (gCurrentPinballGame->bannerType - 1)
    {
    case 0:
        if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->outLaneSide == 2)
        {
            DmaCopy16(3, gUnknown_08395A4C, (void *)0x6015800, 0x2400);
        }
        else
        {
            DmaCopy16(3, gUnknown_08397E6C, (void *)0x6015800, 0x2400);
        }
        break;
    case 1:
        DmaCopy16(3, gUnknown_083A704C, (void *)0x6015800, 0x1000);
        break;
    case 2:
        DmaCopy16(3, gUnknown_0848FD8C, (void *)0x6015800, 0xCA0);
        break;
    case 3:
        DmaCopy16(3, gUnknown_086ACEF8[gCurrentPinballGame->bannerGfxVariant], (void *)0x6015800, 0x25E0);
        break;
    case 4:
        DmaCopy16(3, gUnknown_083A07CC, (void *)0x6015800, 0x2000);
        break;
    case 5:
        DmaCopy16(3, gUnknown_083A29EC, (void *)0x6015800, 0x800);
        break;
    case 6:
        DmaCopy16(3, gUnknown_083A340C, (void *)0x6015800, 0x2000);
        break;
    case 7:
        DmaCopy16(3, gUnknown_083A562C, (void *)0x6015800, 0x1800);
        break;
    case 8:
        DmaCopy16(3, gUnknown_081428D4, (void *)0x6015800, 0x1C00);
        break;
    case 9:
        DmaCopy16(3, gUnknown_0839C78C, (void *)0x6015800, 0x1400);
        break;
    case 10:
        DmaCopy16(3, gUnknown_0839DDAC, (void *)0x6015800, 0x2800);
        break;
    case 11:
        DmaCopy16(3, gUnknown_084FA20C, (void *)0x6015800, 0x280);
        break;
    case 13:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gUnknown_083FFD4C, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gUnknown_083FF04C[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }
        DmaCopy16(3, gUnknown_084F61EC, (void *)0x6015C00, 0x940);
        break;
    case 12:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gUnknown_083FFD4C, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gUnknown_083FF04C[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }

        for (i = 0; i < 10; i++)
        {
            if (gUnknown_086ACFE0[i] == ' ')
            {
                DmaCopy16(3, gUnknown_083FFD4C, (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
            else
            {
                int var0 = gUnknown_086ACFE0[i] - 'A';
                DmaCopy16(3, gUnknown_083FF04C[var0], (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
        }
        break;
    case 14:
        DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->evoItemType], (void *)0x6015800, 0x1C00);
        break;
    case 15:
        DmaCopy16(3, gUnknown_08158284, (void *)0x6015800, 0x2400);
        break;
    case 16:
        DmaCopy16(3, gUnknown_083A562C, (void *)0x6015800, 0x1800);
        break;
    case 17:
        DmaCopy16(3, gUnknown_084F61EC, (void *)0x6015C00, 0x940);
        if (gCurrentPinballGame->trapDisplayState == 0)
        {
            var1 = gUnknown_086AD000[gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor]];
            var2 = var1[3] / 10;
            DmaCopy16(3, gUnknown_08480E0C[var2], (void *)0x6015DA0, 0x40);
            var3 = var1[3] % 10;
            DmaCopy16(3, gUnknown_08480E0C[var3], (void *)0x6015E60, 0x40);
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
            DmaCopy16(3, gUnknown_081BCAA4, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gUnknown_081BE2C4, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        else
        {
            DmaCopy16(3, gUnknown_081BE4C4, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gUnknown_081BFCE4, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        break;
    case 21:
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x6015800, 0xC00);
        break;
    }
}

void RestoreMainFieldSprites(void)
{
    s16 i;
    s16 var0;

    LoadCatchModePokemonSpritesheets();
    LoadHatchModePokemonSpritesheets();

    for (i = 0; i <= 1; i++)
    {
        var0 = gCurrentPinballGame->flipper[i].position / 2;
        DmaCopy16(3, gUnknown_083FE44C[var0], ((i * 0x200) + 0x06010000), 0x200);
    }

    var0 = gCurrentPinballGame->ball->rotation / 0x1000;
    DmaCopy16(3, gUnknown_083BB16C[var0], 0x06010400, 0x80);

    for (i = 0; i <= 1; i++)
    {
        DmaCopy16(3, gUnknown_084C07EC + ((var0 =gCurrentPinballGame->pondEntitySpriteFrame[i]) * 0x180), 0x06010480 + (i * 0x180), 0x180);
    }

    var0 = gCurrentPinballGame->pikaSpinnerFrame;
    DmaCopy16(3, gMainBoardPikaSpinner_Gfx[var0 = gCurrentPinballGame->pikaSpinnerFrame], 0x06010780, 0x120);
    var0 = gCurrentPinballGame->pikaChargeSegment;
    DmaCopy16(3, gUnknown_084C00EC[var0], 0x06010AE0, 0x80);

    for (i = 0; i <= 1; i++)
    {
        switch (gCurrentPinballGame->portraitRenderMode[i])
        {
        case 0:
            DmaCopy16(3, gUnknown_0848D68C[gCurrentPinballGame->portraitSpeciesId[i]], 0x06010CA0 + (i * 0x300), 0x300);
            gCurrentPinballGame->ball += 0; //TODO: Dumb match is still a match...
            break;
        case 9:
            if (gCurrentPinballGame->evoStageSelection > 0)
            {
                if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == 0)
                {
                    gCurrentPinballGame->portraitSpeciesId[i] = 205;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitSpeciesId[i] / 15] + (gCurrentPinballGame->portraitSpeciesId[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
                else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] <= 3)
                {
                    gCurrentPinballGame->portraitSpeciesId[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, 0x050003A0, 0x20);
                }
                else
                {
                    gCurrentPinballGame->portraitSpeciesId[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitSpeciesId[i] / 15] + (gCurrentPinballGame->portraitSpeciesId[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
            }
            else
            {
                gCurrentPinballGame->portraitSpeciesId[i] = gCurrentPinballGame->currentSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitSpeciesId[i] / 15] + ((gCurrentPinballGame->portraitSpeciesId[i] % 15) * 0x20), 0x050003A0, 0x20);
            }
        case 3:
            DmaCopy16(3, gMonPortraitGroupGfx[gCurrentPinballGame->portraitSpeciesId[i] / 15] + (gCurrentPinballGame->portraitSpeciesId[i] % 15) * 0x300, 0x06010CA0 + (i * 0x18), 0x300);
            break;
        case 1:
        case 2:
        case 4:
        case 6:
        case 7:
        case 8:
            DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[i]], 0x06010CA0 + (i * 0x300), 0x300);
            break;
        }
    }

    if (gCurrentPinballGame->boardState == 4)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case 7:
        case 8:
            if ((u32) gCurrentPinballGame->catchHitReactionTimer > 4)
            {
                DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
            }
            break;
        case 9:
            if (gCurrentPinballGame->captureSequencePhase <= 31)
            {
                if (gCurrentPinballGame->catchHitReactionTimer > 4)
                {
                    DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
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
            if (gCurrentPinballGame->catchHitReactionTimer > 4U)
            {
                DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
            }
            break;
        case 3:
            if (gCurrentPinballGame->captureSequencePhase <= 31)
            {
                if (gCurrentPinballGame->catchHitReactionTimer > 4U)
                {
                    DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
                }
            }
            break;
        }
    }

    DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->trapSpriteAnimFrame], 0x060113C0, 0x300);
    DmaCopy16(3, gUnknown_086AD49C[gCurrentPinballGame->evoItemType] +  var0 * 0x200, 0x060116C0, 0x200);
    DmaCopy16(3, gUnknown_084FD18C[(s16)gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][3]], 0x06011CE0, 0x200);
    DmaCopy16(3, gUnknown_083BD36C[gCurrentPinballGame->ballUpgradeGfxFrame], 0x06011EE0, 0x200);
    return;
}


void RestoreRubyFieldTiles(void)
{
    s16 i;
    s16 var0;

    var0 = gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][2];
    DmaCopy16(3, gRubyBoardHatchCave_Gfx[var0], (void *)0x60122A0, 0x480);
    var0 = (gMain.systemFrameCount % 50) / 25;
    DmaCopy16(3, gUnknown_083C3C2C[var0], (void *)0x6012720, 0x300);
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->sharpedoGfxVariant], (void *)0x6012C20, 0x260);
    for (i = 0; i < 2; i++)
        DmaCopy16(3, gUnknown_083C806C[var0], (void *)0x6010000 + (0x174 + i * 8) * 0x20, 0x100);

    var0 = gCurrentPinballGame->shopDoorCurrentFrame & 0xF;
    DmaCopy16(3, gRubyBoardShopDoor_Gfx[var0], (void *)0x6013180, 0x180);
    if (gCurrentPinballGame->hatchCaveState < 3)
        gCurrentPinballGame->cyndaquilGfxFrame = 0;
    else
        gCurrentPinballGame->cyndaquilGfxFrame = 1;

    DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilGfxFrame], (void *)0x6013300, 0x280);
    var0 = gUnknown_086AD456[gCurrentPinballGame->trapDisplayState][(gCurrentPinballGame->slotReelFrame % 42) / 6];
    DmaCopy16(3, gRubyBoardShop_Gfx[var0], (void *)0x6013D00, 0x500);
}

void RestoreSapphireFieldTiles(void)
{
    s16 index;

    switch (gCurrentPinballGame->cyndaquilAnimPhase)
    {
    case 0:
    case 1:
    case 2:
        index = gCurrentPinballGame->cyndaquilAnimFrame;
        DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        break;
    case 3:
    case 4:
        index = 15;
        DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        break;
    case 5:
        index = gUnknown_086AE5A0[gCurrentPinballGame->cyndaquilAnimFrame][0];
        DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        break;
    case 6:
        break;
    }
}

void RestoreDusclopsBonusFieldGfx(void)
{
    DmaCopy16(3, gDusclopsBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void RestoreKecleonBonusFieldGfx(void)
{
    DmaCopy16(3, gKecleonBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void RestoreKyogreBonusFieldGfx(void)
{
    DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x6015800, 0x2000);
    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitSpeciesId[0] / 15] + (gCurrentPinballGame->portraitSpeciesId[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreGroudonBonusFieldGfx(void)
{
    if (gCurrentPinballGame->boardState < 2)
    {
        DmaCopy16(3, gUnknown_0849F1CC, (void *)0x6015800, 0x2000);
    }
    else
    {
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitSpeciesId[0] / 15] + (gCurrentPinballGame->portraitSpeciesId[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreRayquazaBonusFieldGfx(void)
{
    u8 var0;

    if (gCurrentPinballGame->boardState == 0)
    {
        DmaCopy16(3, gUnknown_083C5A2C, (void *)0x6015800, 0x2800);
    }
    else if (gCurrentPinballGame->boardState == 1)
    {
        DmaCopy16(3, gUnknown_084A856C, (void *)0x6015800, 0x1C00);
    }
    else
    {
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    var0 = gCurrentPinballGame->entityState - 2;
    if (var0 > 9)
    {
        DmaCopy16(3, gUnknown_084AA18C, (void *)0x6011620, 0x860);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitSpeciesId[0] / 15] + (gCurrentPinballGame->portraitSpeciesId[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreSphealBonusFieldGfx(void)
{
    s16 i;
    int var0;
    u16 var1;

    for (i = 0; i < 0x800; i++)
        gBgScreenBuffer[0x400 + i] = 0x200;

    DmaCopy16(3, &gBgScreenBuffer[0x400], (void *)0x6001000, 0x1000);
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
            gBgScreenBuffer[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].xOffset = 8;
    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gBgScreenBuffer[0x800], (void *)0x6001140, 0x280);
    for (i = 0; i < 0x800; i++)
        gBgScreenBuffer[i] = 0x1FF;

    DmaCopy16(3, gUnknown_084B77EC, (void *)0x6015800, 0x800);
}

void RestoreBonusFieldCommonGfx(void)
{
}
