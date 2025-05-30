#include "global.h"
#include "variables.h"

void sub_18A4C(u16* vector2, u16* upperStore, u8* nibbleStore)
{
    s16 deltaX;
    s16 deltaY;
    u16 resultFromArray;
    u16 maskedResult;
    u16 lowerNibble;

    if (gCurrentPinballGame->unk387 != 1)
        return;
    if (*nibbleStore & 0xF)
        return;

    deltaX = vector2[0] - gCurrentPinballGame->unk3F0;
    deltaY = vector2[1] - gCurrentPinballGame->unk3F2;

    if ((u16)deltaX >= 0x80 || (u16)deltaY >= 0x80)
        return;

    resultFromArray = gUnknown_083722E8[(deltaY << 7) + deltaX];
    maskedResult = resultFromArray & 0xFFF0;
    lowerNibble = resultFromArray & 0xF;
    if (lowerNibble == 0)
        return;

    gCurrentPinballGame->unk452 = 9;
    *upperStore = maskedResult;
    *nibbleStore = lowerNibble;
}

void sub_18AE0(u8 unknown_enum)
{
    // input presumed to be an enum due to this switch case below
    // something told the compiler to make 15 cases not 0 based
    switch (unknown_enum)
    {
    case 4:
        gCurrentPinballGame->unk3DC = 6;
        gCurrentPinballGame->unk1F = 1;
        break;
    case 1:
    case 2:
    case 3:
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
