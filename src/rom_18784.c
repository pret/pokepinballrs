#include "global.h"
#include "variables.h"
#include "types.h"
#include "main.h"

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
    gCurrentPinballGame->unk132c->unk4 = 0;

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

    switch (switch_enum) {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010) {
            if (gCurrentPinballGame->unk132c->unk10.x < (gUnknown_02031520.unk26 - 8) || gCurrentPinballGame->unk132c->unk10.y < gUnknown_02031520.unk28 - 8)
            {
                if (gCurrentPinballGame->unk132c->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->unk132c->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->unk132c->unk4 = 40;
                        gCurrentPinballGame->unk132c->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->unk132c->unk4 = -40;
                        gCurrentPinballGame->unk132c->unk6 = -1;
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