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

void AllBoardProcess_4A_19304(void)
{
    if (gMain.selectedField >= FIELD_BONUS_START)
        BonusBoardProcess_4B_19734();
}

void sub_1931C(struct Vector16 arg0)
{
    s16 check;
    struct Unk086ACE8C *line;
    struct Vector16 point1, point2;

    line = &gUnknown_086ACE8C[gCurrentPinballGame->unk13BC[0].unk0];
    point1.x = line->unk0 + 0x53;
    point1.y = line->unk2 + gUnknown_02031520.unk14.unk1C;

    point2.x = line->unk4 + 0x53;
    point2.y = line->unk6 + gUnknown_02031520.unk14.unk1C;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->unk13BC[0].unk8 = 1;
    else
        gCurrentPinballGame->unk13BC[0].unk8 = -1;

    line = &gUnknown_086ACE8C[gCurrentPinballGame->unk13BC[1].unk0];

    point1.x = 0x9C - line->unk0;
    point1.y = line->unk2 + gUnknown_02031520.unk14.unk1C;

    point2.x = 0x9C - line->unk4;
    point2.y = line->unk6 + gUnknown_02031520.unk14.unk1C;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->unk13BC[1].unk8 = 1;
    else
        gCurrentPinballGame->unk13BC[1].unk8 = -1;
}

void MainBoardProcess_4B_19490(void)
{
    s16 i;

    if ((gMain.unkF & 1) == 0)
        sub_195C4();

    for (i = 0; i < 2; i++)
    {
        struct SpriteGroup *spriteGroup;

        if (gCurrentPinballGame->unk13BC[i].unk0 > 10)
            gCurrentPinballGame->unk13BC[i].unk0 = 10;
        else if (gCurrentPinballGame->unk13BC[i].unk0 < 0)
            gCurrentPinballGame->unk13BC[i].unk0 = 0;

        spriteGroup = &gMain.spriteGroups[10 + i];
        if (spriteGroup->available)
        {
            s8 unk0;
            struct OamDataSimple *oamData;

            unk0 = gCurrentPinballGame->unk13BC[i].unk0 / 2;
            spriteGroup->baseX = gUnknown_086ACEF4[i] - gCurrentPinballGame->unk58;
            spriteGroup->baseY = gUnknown_02031520.unk14.unk1C - gCurrentPinballGame->unk5A;

            DmaCopy16(3, gUnknown_083FE44C[unk0], OBJ_VRAM0 + i * 0x200, 0x200);

            oamData = &spriteGroup->oam[0];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
        }
    }
}

void sub_195C4(void)
{
    s16 i;

    sub_1931C(gCurrentPinballGame->ball->positionQ0);

    for (i = 0; i < 2; i++)
    {
        s16 dir;
        struct UnkPinballGame13BC *unk13BC;
        unk13BC = &gCurrentPinballGame->unk13BC[i];

        unk13BC->unk1 = unk13BC->unk0;
        unk13BC->unk2 = 0;

        if (gCurrentPinballGame->heldButtonActions[i])
        {
            if (unk13BC->unk6 == 0 && gCurrentPinballGame->unk25 == 0)
                m4aSongNumStart(SE_UNKNOWN_0x72);

            unk13BC->unk6 = 1;
            unk13BC->unk7 = 0;
        }
        else
        {
            if (unk13BC->unk0 == 10)
            {
                if (unk13BC->unk7 > 2)
                    unk13BC->unk6 = gCurrentPinballGame->heldButtonActions[i];
                unk13BC->unk7++;
            }
        }

        dir = 0;
        if (unk13BC->unk6 != 0)
        {
            if (unk13BC->unk0 != 10)
            {
                dir = 1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk2 = unk13BC->unk0 / 2 + 1;
            unk13BC->unk0 += 4;
        }
        else
        {
            if (unk13BC->unk0 != 0)
            {
                unk13BC->unk2 = unk13BC->unk0 / 2 + 6;
                dir = -1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk0 -= 2;
        }
        unk13BC->unk3 = unk13BC->unk3 * dir;
        if (unk13BC->unk3 <= 0)
            unk13BC->unk4 = 0;
        unk13BC->unk3 = dir;
    }
}

void BonusBoardProcess_4B_19734(void)
{
    s16 i;
    s16 priority = 1;

    if ((gMain.unkF & 1) == 0)
    {
        sub_19894();
        gMain.unkF = gMain.unkF;
    }
    for (i = 0; i < 2; i++)
    {
        struct SpriteGroup *spriteGroup;

        if (gCurrentPinballGame->unk13BC[i].unk0 > 10)
            gCurrentPinballGame->unk13BC[i].unk0 = 10;
        else if (gCurrentPinballGame->unk13BC[i].unk0 < 0)
            gCurrentPinballGame->unk13BC[i].unk0 = 0;

        spriteGroup = &gMain.spriteGroups[3 + i];
        if (spriteGroup->available)
        {
            s8 unk0;
            struct OamDataSimple *oamData;

            unk0 = gCurrentPinballGame->unk13BC[i].unk0 / 2;
            spriteGroup->baseX = gUnknown_086ACEF4[i] - gCurrentPinballGame->unk58;
            spriteGroup->baseY = gUnknown_02031520.unk14.unk1C - gCurrentPinballGame->unk5A;

            DmaCopy16(3, gUnknown_083FE44C[unk0], OBJ_VRAM0 + i * 0x200, 0x200);

            if (spriteGroup->baseY > 180)
                spriteGroup->baseY = 180;

            oamData = &spriteGroup->oam[0];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
            gOamBuffer[oamData->oamId].priority = priority;
        }
    }
}

void sub_19894(void)
{
    s16 i;

    sub_1931C(gCurrentPinballGame->ball->positionQ0);

    for (i = 0; i < 2; i++)
    {
        s16 dir;
        struct UnkPinballGame13BC *unk13BC;
        unk13BC = &gCurrentPinballGame->unk13BC[i];

        unk13BC->unk1 = unk13BC->unk0;
        unk13BC->unk2 = 0;

        if (gCurrentPinballGame->heldButtonActions[i] && gMain.unkF == 0)
        {
            if (unk13BC->unk6 == 0 && gCurrentPinballGame->unk25 == 0 && gCurrentPinballGame->unk1A == 0)
            {
                m4aSongNumStart(SE_UNKNOWN_0x72);
            }
            unk13BC->unk6 = 1;
            unk13BC->unk7 = 0;
        }
        else
        {
            if (unk13BC->unk0 == 10)
            {
                if (unk13BC->unk7 > 2)
                    unk13BC->unk6 = 0;
                unk13BC->unk7++;
            }
        }

        dir = 0;
        if (unk13BC->unk6 != 0)
        {
            if (unk13BC->unk0 != 10)
            {
                dir = 1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk2 = unk13BC->unk0 / 2 + 1;
            unk13BC->unk0 += 4;
        }
        else
        {
            if (unk13BC->unk0 != 0)
            {
                unk13BC->unk2 = unk13BC->unk0 / 2 + 6;
                dir = -1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk0 -= 2;
        }
        unk13BC->unk3 = unk13BC->unk3 * dir;
        if (unk13BC->unk3 <= 0)
            unk13BC->unk4 = 0;
        unk13BC->unk3 = dir;
    }
}
