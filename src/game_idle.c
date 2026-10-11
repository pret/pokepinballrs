#include "global.h"
#include "variables.h"
#include "types.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern EWRAM_DATA u32 gReplayFrameCounter;

// Rom_1 data
extern const StateFunc gIdlePinballGameStateFuncs[];
extern const struct ReplayInputFrame gIdleBoardConfig0;
extern const struct ReplayInputFrame gIdleBoardConfig2;
extern const struct ReplayInputFrame gIdleBoardConfig3;
extern const struct ReplayInputFrame gIdleBoardConfig1;
extern const struct PinballGame gIdleBoardGameState0;
extern const struct PinballGame gIdleBoardGameState2;
extern const struct PinballGame gIdleBoardGameState3;
extern const struct PinballGame gIdleBoardGameState1;


void IdlePinballGameMain(void)
{
    gIdlePinballGameStateFuncs[gMain.subState]();
}

void PinballGameIdle0_19048(void)
{
    enum DemoVariant{
        DEMO_VARIANT_0 = 0,
        DEMO_VARIANT_1 = 1,
        DEMO_VARIANT_2 = 2,
        DEMO_VARIANT_3 = 3
    };

    s16 i;
    u16 demoVariant;
    s8 demoFieldVariant;

    gMain.idleFrameCounter = 0;
    gMain.continueFromSave = TRUE;
    gReplayFrameCounter = 0;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gBoardConfig.eReaderBonuses[i] = gMain.eReaderBonuses[i];

    if (gMain.idleDemoVariant == 0)
        gMain.idleDemoVariant = (Random() + gMain.systemFrameCount) % 30;

    demoVariant = gMain.idleDemoVariant;
    demoFieldVariant = demoVariant % 4;
    switch (demoFieldVariant)
    {
    case DEMO_VARIANT_0:
        gBoardConfig.idleDemoDuration = 0xA14;
        gBoardConfig.replayInputData = &gIdleBoardConfig0;
        gBoardConfig.pinballGame = &gIdleBoardGameState0;
        break;
    case DEMO_VARIANT_1:
        gBoardConfig.idleDemoDuration = 0xF00;
        gBoardConfig.replayInputData = &gIdleBoardConfig1;
        gBoardConfig.pinballGame = &gIdleBoardGameState1;
        break;
    case DEMO_VARIANT_2:
        gBoardConfig.idleDemoDuration = 0xD20;
        gBoardConfig.replayInputData = &gIdleBoardConfig2;
        gBoardConfig.pinballGame = &gIdleBoardGameState2;
        break;
    case DEMO_VARIANT_3:
        gBoardConfig.idleDemoDuration = 0xE4C;
        gBoardConfig.replayInputData = &gIdleBoardConfig3;
        gBoardConfig.pinballGame = &gIdleBoardGameState3;
        break;
    }

    PinballGame_State0_49ED4();

    switch (demoFieldVariant)
    {
    case DEMO_VARIANT_0:
        m4aSongNumStart(MUS_FIELD_RUBY);
        break;
    case DEMO_VARIANT_1:
        m4aSongNumStart(MUS_FIELD_SAPPHIRE);
        break;
    case DEMO_VARIANT_2:
        m4aSongNumStart(MUS_FIELD_RUBY);
        break;
    case DEMO_VARIANT_3:
        m4aSongNumStart(MUS_FIELD_SAPPHIRE);
        break;
    }

    gBoardConfig.rumbleEnabled = gMain_saveData.rumbleEnabled;
    gMain_saveData.rumbleEnabled = 0;
    gMain.idleDemoVariant++;
}

void PinballGameIdle1_19190(void)
{
    u8 fadeSubState;

    fadeSubState = gCurrentPinballGame->fadeSubState;
    switch (fadeSubState)
    {
    case 0:
        gCurrentPinballGame->fadeSubState = 1;
        gMain.gameExitState = fadeSubState;
        break;
    case 1:
        if (gMain.selectedField < MAIN_FIELD_COUNT)
            IdleGameFrameUpdate();
        else
            IdleBonusFieldFrameUpdate();

        if (gMain.idleFrameCounter++ > gBoardConfig.idleDemoDuration)
            gMain.gameExitState = 1;

        if (gMain.heldKeys & JOY_EXCL_LR)
            gMain.gameExitState = 1;

        if (gMain.gameExitState != 0)
        {
            if (gMain.selectedField < MAIN_FIELD_COUNT)
            {
                ClampPortraitSpritesToOffscreen();
                RestoreBoardObjPalettes(0);
            }
            else if (gMain.selectedField == FIELD_KECLEON) // bug? other references are Dusclops
            {
                HideDusclopsSprites();
            }

            if ((gMain.modeChangeFlags & MODE_CHANGE_PAUSE) != 0)
            {
                DmaCopy16(3, gCurrentPinballGame->pauseObjPalette, OBJ_PLTT, OBJ_PLTT_SIZE);
            }

            gCurrentPinballGame->fadeSubState = 2;
            if (gMain.gameExitState == 2)
                SaveGameStateSnapshot(1);
        }
        break;
    case 2:
        gMain.subState++;
        break;
    }
}

void PinballGameIdle3_19288(void)
{
    s16 i;

    gMain.blendEnabled = FALSE;
    gMain_saveData.rumbleEnabled = gBoardConfig.rumbleEnabled;
    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gMain.eReaderBonuses[i] = gBoardConfig.eReaderBonuses[i];

    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    if (gMain.idleFrameCounter < gBoardConfig.idleDemoDuration)
        SetMainGameState(STATE_TITLE);
    else
        SetMainGameState(STATE_SCORES_IDLE);

    gMain.idleFrameCounter = 0;
}
