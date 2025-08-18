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
    s16 unk30;
    s8 unk30LowerBits;

    gMain.unk54 = 0;
    gMain.unkD = 1;
    gUnknown_02031510 = 0;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gUnknown_02031520.eReaderBonuses[i] = gMain.eReaderBonuses[i];

    if (gMain.unk30 == 0)
        gMain.unk30 = (Random() + gMain.systemFrameCount) % 30;

    unk30 = gMain.unk30;
    unk30LowerBits = unk30 & 3;
    switch (unk30LowerBits)
    {
    case 0:
        gUnknown_02031520.unk6 = 0xA14;
        gUnknown_02031520.unk10 = &gUnknown_081450F4;
        gUnknown_02031520.unkC = &gUnknown_081531F4;
        break;
    case 1:
        gUnknown_02031520.unk6 = 0xF00;
        gUnknown_02031520.unk10 = &gUnknown_0814F9B4;
        gUnknown_02031520.unkC = &gUnknown_08156E60;
        break;
    case 2:
        gUnknown_02031520.unk6 = 0xD20;
        gUnknown_02031520.unk10 = &gUnknown_08148934;
        gUnknown_02031520.unkC = &gUnknown_08154618;
        break;
    case 3:
        gUnknown_02031520.unk6 = 0xE4C;
        gUnknown_02031520.unk10 = &gUnknown_0814C174;
        gUnknown_02031520.unkC = &gUnknown_08155A3C;
        break;
    }

    PinballGame_State0_49ED4();

    switch (unk30LowerBits)
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

    gUnknown_02031520.rumbleEnabled = gMain_saveData.rumbleEnabled;
    gMain_saveData.rumbleEnabled = 0;
    gMain.unk30++;
}

void PinballGameIdle1_19190(void)
{
    u8 unk1D;

    unk1D = gCurrentPinballGame->unk1D;
    switch (unk1D)
    {
    case 0:
        gCurrentPinballGame->unk1D = 1;
        gMain.unkE = unk1D;
        break;
    case 1:
        if (gMain.selectedField < MAIN_FIELD_COUNT)
            sub_4ACF0();
        else
            sub_4B000();

        if (gMain.unk54++ > gUnknown_02031520.unk6)
            gMain.unkE = 1;

        if (gMain.heldKeys & JOY_EXCL_LR)
            gMain.unkE = 1;

        if (gMain.unkE != 0)
        {
            if (gMain.selectedField < MAIN_FIELD_COUNT)
            {
                sub_1D4D0();
                sub_31BE8(0);
            }
            else if (gMain.selectedField == FIELD_KECLEON)
            {
                sub_356A0();
            }

            if ((gMain.unkF & 2) != 0)
            {
                DmaCopy16(3, gCurrentPinballGame->unk111A, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
            }

            gCurrentPinballGame->unk1D = 2;
            if (gMain.unkE == 2)
                sub_4B408(1);
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

    gMain.unk36 = 0;
    gMain_saveData.rumbleEnabled = gUnknown_02031520.rumbleEnabled;
    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gMain.eReaderBonuses[i] = gUnknown_02031520.eReaderBonuses[i];

    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    if (gMain.unk54 < gUnknown_02031520.unk6)
        SetMainGameState(STATE_TITLE);
    else
        SetMainGameState(STATE_SCORES_IDLE);

    gMain.unk54 = 0;
}
