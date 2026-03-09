#include "global.h"
#include "variables.h"
#include "types.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

void IdlePinballGameMain(void)
{
    gIdlePinballGameStateFuncs[gMain.subState]();
}

void PinballGameIdle0_19048(void)
{
    s16 i;
    s16 demoIndex;
    s8 demoVariant;

    gMain.idleFrameCounter = 0;
    gMain.isResuming = 1;
    gDemoPlaybackFrame = 0;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gBoardConfig.eReaderBonuses[i] = gMain.eReaderBonuses[i];

    if (gMain.idleDemoIndex == 0)
        gMain.idleDemoIndex = (Random() + gMain.systemFrameCount) % 30;

    demoIndex = gMain.idleDemoIndex;
    demoVariant = demoIndex & 3;
    switch (demoVariant)
    {
    case 0:
        gBoardConfig.idleTimeoutFrames = 0xA14;
        gBoardConfig.demoInputData = &gDemoInputData0;
        gBoardConfig.initialGameState = &gDemoInitState0;
        break;
    case 1:
        gBoardConfig.idleTimeoutFrames = 0xF00;
        gBoardConfig.demoInputData = &gDemoInputData1;
        gBoardConfig.initialGameState = &gDemoInitState1;
        break;
    case 2:
        gBoardConfig.idleTimeoutFrames = 0xD20;
        gBoardConfig.demoInputData = &gDemoInputData2;
        gBoardConfig.initialGameState = &gDemoInitState2;
        break;
    case 3:
        gBoardConfig.idleTimeoutFrames = 0xE4C;
        gBoardConfig.demoInputData = &gDemoInputData3;
        gBoardConfig.initialGameState = &gDemoInitState3;
        break;
    }

    PinballGame_State0_49ED4();

    switch (demoVariant)
    {
    case 0:
        m4aSongNumStart(MUS_FIELD_RUBY);
        break;
    case 1:
        m4aSongNumStart(MUS_FIELD_SAPPHIRE);
        break;
    case 2:
        m4aSongNumStart(MUS_FIELD_RUBY);
        break;
    case 3:
        m4aSongNumStart(MUS_FIELD_SAPPHIRE);
        break;
    }

    gBoardConfig.rumbleEnabled = gMain_saveData.rumbleEnabled;
    gMain_saveData.rumbleEnabled = 0;
    gMain.idleDemoIndex++;
}

void PinballGameIdle1_19190(void)
{
    u8 gamePhase;

    gamePhase = gCurrentPinballGame->gamePhase;
    switch (gamePhase)
    {
    case 0:
        gCurrentPinballGame->gamePhase = 1;
        gMain.gameIdleState = gamePhase;
        break;
    case 1:
        if (gMain.selectedField < MAIN_FIELD_COUNT)
            RunIdleBoardFrame();
        else
            RunIdleBonusBoardFrame();

        if (gMain.idleFrameCounter++ > gBoardConfig.idleTimeoutFrames)
            gMain.gameIdleState = 1;

        if (gMain.heldKeys & JOY_EXCL_LR)
            gMain.gameIdleState = 1;

        if (gMain.gameIdleState != 0)
        {
            if (gMain.selectedField < MAIN_FIELD_COUNT)
            {
                UpdateRubyBonusFieldYPositions();
                RestoreBoardPalettesAfterMenu(0);
            }
            else if (gMain.selectedField == FIELD_KECLEON)
            {
                UpdatePointerSpritePosition();
            }

            if ((gMain.modeChangeFlags & MODE_CHANGE_PAUSE) != 0)
            {
                DmaCopy16(3, gCurrentPinballGame->savedObjPaletteForPause, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
            }

            gCurrentPinballGame->gamePhase = 2;
            if (gMain.gameIdleState == 2)
                SaveBoardStateForPause(1);
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

    gMain.updateBlendRegisters = 0;
    gMain_saveData.rumbleEnabled = gBoardConfig.rumbleEnabled;
    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gMain.eReaderBonuses[i] = gBoardConfig.eReaderBonuses[i];

    FadeOutToWhite();
    m4aMPlayAllStop();
    DisableVBlankProcessing();
    if (gMain.idleFrameCounter < gBoardConfig.idleTimeoutFrames)
        SetMainGameState(STATE_TITLE);
    else
        SetMainGameState(STATE_SCORES_IDLE);

    gMain.idleFrameCounter = 0;
}
