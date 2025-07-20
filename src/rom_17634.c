#include "global.h"

void sub_17634(u8 arg0)
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
        gCurrentPinballGame->unk387 = 0;
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

s16 sub_176B0(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 unk0;
    s32 unk1;
    s32 unk2;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    unk1 = vec1.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    vec1.y %= 64;
    unk0 = gUnknown_02031520.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
    sp00 = gUnknown_02031520.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    sp02 = gUnknown_02031520.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];

    sub_17898(arg0, &sp00, &sp02);
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
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = 0;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        if (gCurrentPinballGame->unk404 == 0)
        {
            s32 unk3 = gCurrentPinballGame->unk406;
            if (unk3 == 0)
            {
                gCurrentPinballGame->unk404 = 1;
                gCurrentPinballGame->unk40A = unk3;
            }
        }
        gCurrentPinballGame->unk40C = 40;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    sub_179D0(some_enum, &return_val, arg1);
    return return_val;
}

void sub_17898(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;

    if (gCurrentPinballGame->unk387 == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->unk3F0;
        deltaY = arg0->y - gCurrentPinballGame->unk3F2;

        if ((deltaX < 0 || deltaX > 0x3F) || (deltaY < 0 || deltaY > 0x57))
            return;

        arrayValue = (u8)(gUnknown_0832D604[(deltaY * 0x40) + deltaX]) & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->unk0 != 0)
            return;
        if (gCurrentPinballGame->unk3DC > 8)
            return;

        gCurrentPinballGame->unk3DC = 9;
    }
    else if (gCurrentPinballGame->unk387 == 2)
    {
        u16 maskedResult;

        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->unk3F0;
        deltaY = arg0->y - gCurrentPinballGame->unk3F2;

        if ((deltaX < 0 || deltaX > 0x57) || (deltaY < 0 || deltaY > 0x3F))
            return;

        maskedResult = gUnknown_08330204[(deltaY * 0x58) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_08330204[(deltaY * 0x58) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->unk0 != 0)
            return;
        if (gCurrentPinballGame->unk3DC == 12)
            return;

        gCurrentPinballGame->unk3DC = 11;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void sub_179D0(u8 arg0, u16 *arg1, u16 *arg2)
{
    s16 x, y;
    x = gCurrentPinballGame->ball->positionQ0.x;
    y = gCurrentPinballGame->ball->positionQ0.y;

    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 13:
    case 14:
    case 15:
        return;
    case 8:
        if (x <= 0x72)
        {
            if (y <= 0x38)
            {
                if (gCurrentPinballGame->unk41C[0] <= 0)
                    gCurrentPinballGame->unk41C[0] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk41C[1] <= 0)
                    gCurrentPinballGame->unk41C[1] = 0x18;
            }
        }
        else if (y <= 0x63)
        {
            if (gCurrentPinballGame->unk41C[3] <= 0)
                gCurrentPinballGame->unk41C[3] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk41C[2] <= 0)
                gCurrentPinballGame->unk41C[2] = 0x18;
        }
        break;
    case 9:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->unk420[7] <= 0)
                    gCurrentPinballGame->unk420[7] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk420[5] <= 0)
                    gCurrentPinballGame->unk420[5] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->unk420[8] <= 0)
                gCurrentPinballGame->unk420[8] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[0] <= 0)
                gCurrentPinballGame->unk420[0] = 0x18;
        }
        break;
    case 10:
        if (gCurrentPinballGame->unk410 == 0)
        {
            gCurrentPinballGame->unk42A[0] = 0xB;
            gCurrentPinballGame->unkD0[0].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[0].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->unk410 == 3)
        {
            gCurrentPinballGame->unk42A[1] = 0xB;
            gCurrentPinballGame->unkD0[1].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[1].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->unk410 == 6)
        {
            gCurrentPinballGame->unk42A[2] = 0xB;
            gCurrentPinballGame->unkD0[2].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[2].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->unk410 == 9)
        {
            gCurrentPinballGame->unk42A[3] = 0xB;
            gCurrentPinballGame->unkD0[3].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[3].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        break;
    case 11:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->unk420[9] <= 0)
                    gCurrentPinballGame->unk420[9] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk420[2] <= 0)
                    gCurrentPinballGame->unk420[2] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->unk420[6] <= 0)
                gCurrentPinballGame->unk420[6] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[1] <= 0)
                gCurrentPinballGame->unk420[1] = 0x18;
        }
        break;
    case 12:
        if (x <= 0x72)
        {
            if (gCurrentPinballGame->unk420[4] <= 0)
                gCurrentPinballGame->unk420[4] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[3] <= 0)
                gCurrentPinballGame->unk420[3] = 0x18;
        }
        break;
    }
}