#include "global.h"
#include "main.h"

void sub_4E598(void)
{
    gCurrentPinballGame->unk18 = 10199;

    if (gCurrentPinballGame->unk13 == 2)
        gCurrentPinballGame->unk17 = 5;
    if (gCurrentPinballGame->unk13 == 7)
        gCurrentPinballGame->unk17 = 6;
    if (gCurrentPinballGame->unk13 == 4)
        gCurrentPinballGame->unk17 = 10;
    if (gCurrentPinballGame->unk13 == 5)
        gCurrentPinballGame->unk17 = 6;
    if (gCurrentPinballGame->unk13 == 6)
        gCurrentPinballGame->unk17 = 8;

    gCurrentPinballGame->unk714 = 0;
    gCurrentPinballGame->unk710 = 0;
    gCurrentPinballGame->unk711 = gCurrentPinballGame->unk710;
    gCurrentPinballGame->unk712 = gCurrentPinballGame->unk710;
    gCurrentPinballGame->unk713 = gCurrentPinballGame->unk710;
    gCurrentPinballGame->unk614 = 0;
    gCurrentPinballGame->unk208 = 0;
    gCurrentPinballGame->unk20A = 0;
    if (gCurrentPinballGame->unk1E2 != 2 || !gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->unk1C6 = 0;
        gCurrentPinballGame->unk1C8 = 0;
        gCurrentPinballGame->unk1CC = 0;
        gCurrentPinballGame->unk1CA = 0;
        gCurrentPinballGame->unk1D4 = 0;
        gCurrentPinballGame->unk1D6 = -4;
        gCurrentPinballGame->unk1D8 = 0x100;
        gCurrentPinballGame->unk1DA = 0x100;
        gCurrentPinballGame->unk1CE = 0;
        gCurrentPinballGame->unk1D0 = 0;
    }

    gCurrentPinballGame->unk718 = 0;
    gCurrentPinballGame->unk719 = gCurrentPinballGame->unk718;
    gCurrentPinballGame->unk71A = gCurrentPinballGame->unk718;
    gCurrentPinballGame->unk308 = 0;
    if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->unk5F6 = 3;
        gCurrentPinballGame->unk5F8 = 60 * 60;
        DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)OBJ_PLTT + 0x20, 0x20);
    }
    else
    {
        gCurrentPinballGame->unk5F6 = 0;
        gCurrentPinballGame->unk5F8 = 0;
    }

    gCurrentPinballGame->unk5F7 = 0;
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)OBJ_PLTT + 0x20, 0x20);
    gCurrentPinballGame->unk62F = gCurrentPinballGame->unk70E;
    gCurrentPinballGame->unk70E = 1;
    if (gCurrentPinballGame->unk2A5 == 45)
    {
        gCurrentPinballGame->unk2A4 = 0;
        gCurrentPinballGame->unk2A5 = 0;
        gCurrentPinballGame->unk2A6 = 0;
        gCurrentPinballGame->unk16F = 1;
        gCurrentPinballGame->unk174 = 0x40;
        gCurrentPinballGame->unk2AA = 0;
  
    }

    gCurrentPinballGame->unk300 = 0;
}
