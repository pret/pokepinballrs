#include "global.h"
#include "variables.h"
#include "types.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

void sub_18784(u8 arg0)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->unk3DC = 6;
        gCurrentPinballGame->unk1F = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

//One known callsite is 080145D2 during the rayquaza bonus stage
s16 sub_187F4(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 unk1;
        s32 unk2;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        unk1 = vec1.y / 64;
        unk2 = gCurrentPinballGame->unk24;
        vec1.y %= 64;
        r2 = gUnknown_02031520.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
        sp00 = gUnknown_02031520.unk48[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gUnknown_02031520.unk58[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    sub_18A4C(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gUnknown_02031520.unk26 - 8) || gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk28 - 8)
            {
                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 40;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = -40;
                        gCurrentPinballGame->ball->unk6 = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    sub_18AE0(some_enum, &return_val, arg1);
    return return_val;
}

void sub_18A4C(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 resultFromArray;
    u16 maskedResult;
    u16 lowerNibble;

    if (gCurrentPinballGame->unk387 != 1)
        return;
    if (*arg2 & 0xF)
        return;

    deltaX = arg0->x - gCurrentPinballGame->unk3F0;
    deltaY = arg0->y - gCurrentPinballGame->unk3F2;

    if ((u16)deltaX >= 0x80 || (u16)deltaY >= 0x80)
        return;

    resultFromArray = gUnknown_083722E8[(deltaY << 7) + deltaX];
    maskedResult = resultFromArray & 0xFFF0;
    lowerNibble = resultFromArray & 0xF;
    if (lowerNibble == 0)
        return;

    gCurrentPinballGame->unk452 = 9;
    *arg1 = maskedResult;
    *arg2 = lowerNibble;
}

void sub_18AE0(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->unk3DC = 6;
        gCurrentPinballGame->unk1F = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

s16 sub_18B50(struct Vector16 *arg0, u16 *arg1)
{
    u16 sp0;
    u8 sp2;
    u16 sp4_return;

    struct Vector16 div_result;
    struct Vector16 div_remainder;
    s32 unk1;
    s32 unk2;
    s16 unk3;
    u8 enum1, enum2;

    sp4_return = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    div_result.x = arg0->x / 8;
    div_result.y = arg0->y / 8;
    div_remainder.x = arg0->x % 8;
    div_remainder.y = arg0->y % 8;
    unk1 = div_result.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    div_result.y %= 64;

    unk3 = gUnknown_02031520.unk38[unk2 + unk1][div_result.y * 64 + div_result.x];
    sp0 = gUnknown_02031520.unk48[unk2 + unk1][unk3 * 64 + div_remainder.y * 8 + div_remainder.x];
    sp2 = gUnknown_02031520.unk58[unk2 + unk1][unk3 * 64 + div_remainder.y * 8 + div_remainder.x];

    sub_18DAC(arg0, &sp0, &sp2);

    enum1 = sp2 & 0xF;
    enum2 = sp2 >> 4;
    switch (enum1)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = enum1 - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp0;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gUnknown_02031520.unk26 - 8) ||
                gCurrentPinballGame->ball->positionQ0.y < (gUnknown_02031520.unk28 - 8))
            {
                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 40;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = -40;
                        gCurrentPinballGame->ball->unk6 = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        sp4_return = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = 0;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp0 & 0x0000FFF0;

        if (gCurrentPinballGame->ball->positionQ0.x < 120)
            gCurrentPinballGame->unk548 = 24;
        else
            gCurrentPinballGame->unk549 = 24;

        sp4_return = 1;
        break;
    case 5:
        enum2 = 4;
        break;
    }

    sub_18F38(enum2, &sp4_return, arg1);
    return sp4_return;
}

void sub_18DAC(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 i;
    s16 deltaX, deltaY;
    u16 lowerReadFromRom;
    u16 upperReadFromRom;
    for (i = 0; i < 2; i++)
    {

        if (gCurrentPinballGame->unk54F[i] == 1)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->unk570[i].x;
            deltaY = arg0->y - gCurrentPinballGame->unk570[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gUnknown_08393A4C[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gUnknown_08393A4C[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            if (gCurrentPinballGame->unk388 != 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            gCurrentPinballGame->unk553[i] = 4;
        }
        else if (gCurrentPinballGame->unk54F[i] != 0)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->unk570[i].x;
            deltaY = arg0->y - gCurrentPinballGame->unk570[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gUnknown_08391A4C[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gUnknown_08391A4C[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            if (gCurrentPinballGame->unk54F[i] == 2)
            {
                gCurrentPinballGame->unk553[i] = 4;
            }
            else
            {
                gCurrentPinballGame->unk54D[i] = 24;
            }
        }
    }
}

void sub_18F38(u8 arg0_enum, u16 *arg1, u16 *arg2)
{
    switch (arg0_enum)
    {
    case 2:
        gCurrentPinballGame->unk532 = 0;
        gCurrentPinballGame->unk538 = 2;
        break;
    case 3:
        gCurrentPinballGame->unk532 = 1;
        gCurrentPinballGame->unk538 = 2;
        break;
    case 8:
        gCurrentPinballGame->unk532 = 0;
        gCurrentPinballGame->unk538 = 1;
        gCurrentPinballGame->unk540 = 100;
        break;
    case 9:
        gCurrentPinballGame->unk532 = 1;
        gCurrentPinballGame->unk538 = 1;
        gCurrentPinballGame->unk540 = 100;
        break;
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

void IdlePinballGameMain(void)
{
    gIdlePinballGameStateFuncs[gMain.subState]();
}

void sub_19048(void)
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

    sub_49ED4();

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

void sub_19190()
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

void sub_19288(void)
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

void sub_19304(void)
{
    if (gMain.selectedField >= FIELD_BONUS_START)
        sub_19734();
}

void sub_1931C(struct Vector16 arg0)
{
    s16 check;
    struct Unk086ACE8C *line;
    struct Vector16 point1, point2;

    line = &gUnknown_086ACE8C[gCurrentPinballGame->unk13BC[0].unk0];
    point1.x = line->unk0 + 0x53;
    point1.y = line->unk2 + gUnknown_02031520.unk1C;

    point2.x = line->unk4 + 0x53;
    point2.y = line->unk6 + gUnknown_02031520.unk1C;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->unk13BC[0].unk8 = 1;
    else
        gCurrentPinballGame->unk13BC[0].unk8 = -1;

    line = &gUnknown_086ACE8C[gCurrentPinballGame->unk13BC[1].unk0];

    point1.x = 0x9C - line->unk0;
    point1.y = line->unk2 + gUnknown_02031520.unk1C;

    point2.x = 0x9C - line->unk4;
    point2.y = line->unk6 + gUnknown_02031520.unk1C;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->unk13BC[1].unk8 = 1;
    else
        gCurrentPinballGame->unk13BC[1].unk8 = -1;
}

void sub_19490(void)
{
    s16 i;

    if ((gMain.unkF & 1) == 0)
        sub_195C4();

    for (i = 0; i < 2; i++)
    {
        struct SpriteGroup *spriteGroup;

        if (gCurrentPinballGame->unk13BC[i].unk0 > 10)
        {
            gCurrentPinballGame->unk13BC[i].unk0 = 10;
        }
        else if (gCurrentPinballGame->unk13BC[i].unk0 < 0)
        {
            gCurrentPinballGame->unk13BC[i].unk0 = 0;
        }

        spriteGroup = &gMain.spriteGroups[10 + i];
        if (spriteGroup->available)
        {
            s8 unk0Signed;
            struct OamDataSimple *oamData;

            unk0Signed = gCurrentPinballGame->unk13BC[i].unk0 / 2;
            spriteGroup->baseX = gUnknown_086ACEF4[i] - gCurrentPinballGame->unk58;
            spriteGroup->baseY = gUnknown_02031520.unk1C - gCurrentPinballGame->unk5A;

            DmaCopy16(3, &gUnknown_083FE44C[unk0Signed * TILE_OFFSET_4BPP(16)], OBJ_VRAM0 + i * TILE_OFFSET_4BPP(16), TILE_SIZE_4BPP * 16);
            
            oamData = &spriteGroup->oam[0];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
        }
    }
}