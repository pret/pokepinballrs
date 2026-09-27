#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/board/ruby_states.h"
#include "constants/board/sapphire_states.h"
#include "constants/mem_layout/intro.h"

extern struct PinballGame gPinballGameState;

typedef void (*VoidFunc)(void);

struct BoardProcessPair
{
    void (*initFunc)(void);
    void (*updateFunc)(void);
};

/* Per frame core processing functions for the current board
 0 - Load sprites; manage default sprite group visibility
 1 - Pause check/display
 2 - Camera, Tilt, Drained Ball
 3 - Main board/entity logic
 4 - Flippers
 5 - Ball Movement (Not if processing a mode change, or 'manual' ball physics active)
 6 - Collision logic (Only when ball physics is normal)
 7 - Draw ball
 8 - Hud update: Timer, lives, score, mon caught.

 Initial load (first frame on board) goes in order.
 After that, step 0 (sprite loading) moves after step 1 for Bonus Board, and after step 2 for main boards
 */
extern struct BoardProcessPair CurrentBoardProcPairs[PER_FRAME_PROCESS_PHASE_COUNT];

extern const struct BoardProcessPair gBoardProcPairs[];
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
    enum {
        LOAD_MODE_CONTINUE_FROM_SAVE = 0,
        LOAD_MODE_1 = 1, // ?? TODO: Needs conditions identified to name this state. E-reader stage select?
        LOAD_MODE_MAIN_FIELD = 2,
        LOAD_MODE_BONUS_FIELD = 3
    };

    s16 i, j;
    s16 numRngAdvances;
    s16 loadMode;

    numRngAdvances = gMain.systemFrameCount % 16;
    for (i = 0; i < numRngAdvances; i++)
        Random();

    EnableGbPlayerRumble();
    gCurrentPinballGame = &gPinballGameState;
    ResetDisplayState();
    gMain.gameExitState = 0;
    if (gMain.continueFromSave)
        loadMode = LOAD_MODE_CONTINUE_FROM_SAVE;
    else if (gMain.tempField == gMain.selectedField)
        loadMode = LOAD_MODE_1;
    else if (gMain.selectedField < MAIN_FIELD_COUNT)
        loadMode = LOAD_MODE_MAIN_FIELD;
    else
        loadMode = LOAD_MODE_BONUS_FIELD;

    switch (loadMode)
    {
    case LOAD_MODE_CONTINUE_FROM_SAVE:
        SetupDisplayRegistersForField();
        InitPinballGameState();
        loadFieldBoardGraphics();
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[LIGHTING_PAL_IX_NORMAL][PAL_IX_DIMMING_BASE_0],
            OBJ_PLTT,
            OBJ_PLTT_SIZE);

        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);

        ConfigureBoardProcessesForField();
        for (i = 0; i < PER_FRAME_PROCESS_PHASE_COUNT; i++)
            CurrentBoardProcPairs[i].initFunc();

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
            HideDusclopsSprites();
        else if (gMain.selectedField == FIELD_KYOGRE)
            HideKyogreSplashSprite();
        else if (gMain.selectedField == FIELD_GROUDON)
            HideGroudonShockwaveSprite();
        break;
    case LOAD_MODE_1:
        SetupDisplayRegistersForField();
        InitPinballGameState();
        loadFieldBoardGraphics();
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[LIGHTING_PAL_IX_NORMAL][PAL_IX_DIMMING_BASE_0],
            OBJ_PLTT,
            OBJ_PLTT_SIZE);

        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);

        ConfigureBoardProcessesForField();
        for (i = 0; i < PER_FRAME_PROCESS_PHASE_COUNT; i++)
            CurrentBoardProcPairs[i].initFunc();

        ClearBG0Tilemap();
        break;
    case LOAD_MODE_MAIN_FIELD:
        SetupDisplayRegistersForField();
        SetBallPositionForBonusReturn();
        RestoreGameState(0);
        ConfigureBoardProcessesForField();
        gFieldInitFuncs[gMain.isBonusField]();
        if (gMain.selectedField == FIELD_RUBY)
            SetBoardCollisionConfig(1);

        LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
        gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
        break;
    case LOAD_MODE_BONUS_FIELD:
        SetupDisplayRegistersForField();
        InitPinballGameState();
        loadFieldBoardGraphics();
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[LIGHTING_PAL_IX_NORMAL][PAL_IX_DIMMING_BASE_0],
            OBJ_PLTT,
            OBJ_PLTT_SIZE);
        ConfigureBoardProcessesForField();
        for (i = 0; i < PER_FRAME_PROCESS_PHASE_COUNT; i++)
            CurrentBoardProcPairs[i].initFunc();

        ClearBG0Tilemap();
        break;
    }

    gBoardConfig.caughtSpeciesCount = 0;
    for (j = 0; j < NUM_SPECIES; j++)
    {
        if (gMain_saveData.pokedexFlags[j] > SPECIES_DEX_SHARED_AND_SEEN)
            gBoardConfig.caughtSpeciesCount++;
    }

    EnableVBlankInterrupts();
    FadeInScreen();
    gCurrentPinballGame->startButtonDisabled = FALSE;
    gMain.blendEnabled = TRUE;

    switch (loadMode)
    {
    case LOAD_MODE_CONTINUE_FROM_SAVE:
        if (gMain.mainState != STATE_GAME_IDLE && gCurrentPinballGame->savedBgmSongHeader && gMPlayInfo_BGM.status < 0)
            MPlayStart(&gMPlayInfo_BGM, gCurrentPinballGame->savedBgmSongHeader);
        if (gMain.selectedField < MAIN_FIELD_COUNT)
            RestoreBoardObjPalettes(gCurrentPinballGame->paletteDimmingIx);
        break;
    case LOAD_MODE_1:
    case LOAD_MODE_MAIN_FIELD:
        gMain.blendControl = 0xCE;
        gMain.blendBrightness = 0;
        break;
    case LOAD_MODE_BONUS_FIELD:
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
    gMain.pendingModeChangeType = MODE_CHANGE_NONE;
    gMain.animationTimer = 0;
    gMain.modeChangeDelayTimer = 0;
    gMain.vCount = 144;
    gMain.shopPanelActive = FALSE;
    gMain.shopPanelSlideOffset = 0;
    gMain.blendEnabled = FALSE;
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
            DmaCopy16(3, gDxModePikachuObjTiles, OBJ_VRAM_ADDR_PIKA_MON_AT_RIGHT_SIDE_TILES, SIZE_OF_VRAM_PIKA_MON_TILES);
            gCurrentPinballGame->outLanePikaPosition = PIKA_BOTH_SIDES;
            gMain.fieldSpriteGroups[FIELD_SG_HATCH_MON_ENTITY]->active = FALSE;
            gCurrentPinballGame->pichuEntranceTimer = 1;
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeTimer = TICKS_FOR_TIME(1,0);
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

    gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_DEFAULT;
    gCurrentPinballGame->fadeSubState = 0;
    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
    gCurrentPinballGame->cameraBall = &gCurrentPinballGame->ballStates[0];
    gCurrentPinballGame->activeBallIndex = 0;
}

void SetBallPositionForBonusReturn(void)
{
    switch (gCurrentPinballGame->bonusReturnState)
    {
    case BONUS_RETURN_LOCATION_CENTER_KICKOUT:
        gCurrentPinballGame->ball->positionQ0.x = 119;
        gCurrentPinballGame->ball->positionQ0.y = 279;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->ballHidden = TRUE;
        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
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
    case BONUS_RETURN_LOCATION_WHISCASH:
        gCurrentPinballGame->ball->positionQ0.x = 140;
        gCurrentPinballGame->ball->positionQ0.y = 183;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->ballHidden = TRUE;
        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
        gCurrentPinballGame->trapAnimState = 0;
        gCurrentPinballGame->whiscashState = WHISCASH_STATE_INIT_RETURN_FROM_BONUS;
        gCurrentPinballGame->cameraBaseX = 0;
        gCurrentPinballGame->cameraBaseY = 118;
        break;
    case BONUS_RETURN_LOCATION_PELIPPER:
        gCurrentPinballGame->ball->positionQ0.x = -28;
        gCurrentPinballGame->ball->positionQ0.y = -10;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->ballHidden = TRUE;
        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
        gCurrentPinballGame->trapAnimState = 0;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        gCurrentPinballGame->pelipperState = PELIPPER_STATE_SET_SWOOP_FROM_TOP_LEFT;
        gCurrentPinballGame->cameraBaseX = 0;
        gCurrentPinballGame->cameraBaseY = 0;
        break;
    }

    gCurrentPinballGame->cameraScrollOffset = 0;
    gCurrentPinballGame->cameraScrollTarget = 0;
    gCurrentPinballGame->cameraScrollEnabled = FALSE;
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

    gCurrentPinballGame->scrollEffectYpx = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->prevScrollYTileIx = gMain.bgOffsets[3].yOffset / 8;
}

void ConfigureBoardProcessesForField(void)
{
    CurrentBoardProcPairs[PER_FRAME_PROCESS_PAUSE_LOGIC] = gBoardProcPairs[0];
    CurrentBoardProcPairs[PER_FRAME_PROCESS_HUD_UPDATE] = gBoardProcPairs[18];
    CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION] = gBoardProcPairs[15];
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[3];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[16];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[19];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[11];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[1];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[13];
        gMain.fieldSpriteGroups = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_SAPPHIRE:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[4];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[16];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[20];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[11];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[1];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[13];
        gMain.fieldSpriteGroups = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_DUSCLOPS:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[5];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[17];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[21];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[12];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[2];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_BONUS_START];
        break;
    case FIELD_KECLEON:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[6];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[17];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[22];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[12];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[2];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_BONUS_START];
        break;
    case FIELD_KYOGRE:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[7];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[17];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[23];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[12];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[2];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_BONUS_START];
        break;
    case FIELD_GROUDON:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[8];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[17];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[24];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[12];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[2];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_BONUS_START];
        break;
    case FIELD_RAYQUAZA:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[9];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[17];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[25];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[12];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[2];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_BONUS_START];
        break;
    case FIELD_SPHEAL:
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC] = gBoardProcPairs[10];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL] = gBoardProcPairs[17];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES] = gBoardProcPairs[26];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC] = gBoardProcPairs[12];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN] = gBoardProcPairs[2];
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT] = gBoardProcPairs[14];
        gMain.fieldSpriteGroups = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_BONUS_START];
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
        if (JOY_HELD(RESTART_GAME_BUTTONS) == (RESTART_GAME_BUTTONS))
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
                HideDusclopsSprites();
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
                DmaCopy16(3, gCurrentPinballGame->pauseObjPalette, OBJ_PLTT, OBJ_PLTT_SIZE);

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
    CurrentBoardProcPairs[PER_FRAME_PROCESS_PAUSE_LOGIC].updateFunc();
    if (gMain.gameExitState == 0 && !(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC].updateFunc();
        if (gMain.modeChangeFlags)
        {
            if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->globalAnimFrameCounter++;
            if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_NORMAL)
            {
                if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_FROZEN)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->gravityStrengthIndex = i;
                        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
                }
            }
        }

        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_HUD_UPDATE].updateFunc();
    }

    UpdateScrollingBackgroundTiles();
}

void IdleGameFrameUpdate(void)
{
    s16 i;

    ReplayButtonActionsFromRecording();
    CurrentBoardProcPairs[PER_FRAME_PROCESS_PAUSE_LOGIC].updateFunc();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC].updateFunc();
        if (gMain.modeChangeFlags)
        {
            if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->globalAnimFrameCounter++;
            if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_NORMAL)
            {
                if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_FROZEN)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->gravityStrengthIndex = i;
                        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
                }
            }
        }

        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_HUD_UPDATE].updateFunc();
    }

    UpdateScrollingBackgroundTiles();

    //Tilemap update for the blinking 'Press Start' data
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

    DmaCopy16(3, &gBG0TilemapBuffer[0x340], BG_VRAM_ADDR_IDLE_PRESS_START_TILEMAP, MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW);
}

void BonusFieldFrameUpdate(void)
{
    s16 i;

    UpdateButtonActionsFromJoy();
    CurrentBoardProcPairs[PER_FRAME_PROCESS_PAUSE_LOGIC].updateFunc();
    if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
        return;

    CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES].updateFunc();
    CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN].updateFunc();
    CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC].updateFunc();
    CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC].updateFunc();
    if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
    {
        if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->activeBallIndex = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                gCurrentPinballGame->gravityStrengthIndex = i;
                CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
            }
        }
    }
    else
    {
        gMain.fieldFrameCount++;
        gCurrentPinballGame->globalAnimFrameCounter++;
        if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_NORMAL)
        {
            if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_FROZEN)
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
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
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
                CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
                CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
            }
        }
    }

    CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL].updateFunc();
    CurrentBoardProcPairs[PER_FRAME_PROCESS_HUD_UPDATE].updateFunc();
}

void IdleBonusFieldFrameUpdate(void)
{
    s16 i;

    ReplayButtonActionsFromRecording();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs[PER_FRAME_PROCESS_DEFAULT_SPRITE_STATES].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_CAMERA_SHAKE_AND_DRAIN].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_BOARD_LOGIC].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_FLIPPER_LOGIC].updateFunc();
        if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
        {
            if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->activeBallIndex = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
                    gCurrentPinballGame->gravityStrengthIndex = i;
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->globalAnimFrameCounter++;
            if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_NORMAL)
            {
                if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_FROZEN)
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
                        CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
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
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_BALL_MOVEMENT].updateFunc();
                    CurrentBoardProcPairs[PER_FRAME_PROCESS_COLLISION].updateFunc();
                }
            }
        }

        CurrentBoardProcPairs[PER_FRAME_PROCESS_DRAW_BALL].updateFunc();
        CurrentBoardProcPairs[PER_FRAME_PROCESS_HUD_UPDATE].updateFunc();
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

    DmaCopy16(3, &gBG0TilemapBuffer[0x320], BG_VRAM_ADDR_IDLE_TBD_TILEMAP, MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW);
}

void PinballGame_State3_4B20C(void)
{
    gMain.blendEnabled = FALSE;
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gMain.finalScoreLo = gCurrentPinballGame->scoreLo;
    gMain.finalScoreHi = gCurrentPinballGame->scoreHi;
    if (gMain.gameExitState == 2)
        SaveGameToSram();

    if (gMain.gameExitState == 0)
    {
        if (gMain.selectedField >= FIELD_BONUS_START)
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

    for (i = 0; i < NUM_PINBALL_INPUTS; i++)
    {
        gCurrentPinballGame->newButtonActions[i] = FALSE;
        gCurrentPinballGame->releasedButtonActions[i] = FALSE;
    }

    if (gMain.modeChangeFlags)
        return;

    for (i =  0; i < NUM_PINBALL_INPUTS; i++)
    {
        int buttonConfigKeyMask = (gMain.buttonConfigs[i][0] | gMain.buttonConfigs[i][1]) & KEYS_MASK;
        if (buttonConfigKeyMask == JOY_HELD(buttonConfigKeyMask))
        {
            if (gCurrentPinballGame->heldButtonActions[i] == FALSE)
                gCurrentPinballGame->newButtonActions[i] = TRUE;

            gCurrentPinballGame->heldButtonActions[i] = TRUE;
        }
        else
        {
            if (gCurrentPinballGame->heldButtonActions[i])
                gCurrentPinballGame->releasedButtonActions[i] = TRUE;

            gCurrentPinballGame->heldButtonActions[i] = FALSE;
        }
    }
}

void ReplayButtonActionsFromRecording(void)
{
    u16 i;

    for (i = 0; i < NUM_PINBALL_INPUTS; i++)
    {
        gCurrentPinballGame->newButtonActions[i] = FALSE;
        gCurrentPinballGame->releasedButtonActions[i] = FALSE;
    }

    if (gMain.modeChangeFlags)
        return;

    if (gReplayFrameCounter < 60 * 60)
    {
        for (i =  0; i < NUM_PINBALL_INPUTS; i++)
        {
            gCurrentPinballGame->newButtonActions[i] = (gBoardConfig.replayInputData[gReplayFrameCounter].newButtonBits >> i) & 0x1;
            gCurrentPinballGame->releasedButtonActions[i] = (gBoardConfig.replayInputData[gReplayFrameCounter].releasedButtonBits >> i) & 0x1;
            gCurrentPinballGame->heldButtonActions[i] = (gBoardConfig.replayInputData[gReplayFrameCounter].heldButtonBits >> i) & 0x1;
        }

        gReplayFrameCounter++;
    }

    if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
        gMain.newKeys = A_BUTTON;
}