#include "global.h"
#include "main.h"

void sub_4E468(void)
{
    struct BallState *unk1334;

    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
    unk1334 = &gCurrentPinballGame->unk1334[0];

    if (unk1334->positionQ0.y >= gUnknown_02031520.unk14.unk2A)
    {
        unk1334->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        if (gMain.unkF & 0x40)
        {
            gCurrentPinballGame->unk386 = 1;
            gMain.unkF = 0x80;
            gCurrentPinballGame->ball->positionQ0.y = gUnknown_02031520.unk14.unk2A - 10;
        }
        else
        {
            gCurrentPinballGame->ball->unk0 = 1;
            gCurrentPinballGame->unk388 = 1;
            gCurrentPinballGame->unk392 = 0;
            gCurrentPinballGame->ball->positionQ0.x = gUnknown_02031520.unk14.unk26;
            gCurrentPinballGame->ball->positionQ0.y = gUnknown_02031520.unk14.unk28;
            if (gCurrentPinballGame->unk5F6 > 0)
                gCurrentPinballGame->unk5F6--;

            gCurrentPinballGame->unk5F8 = 3600;
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)0x05000220, 0x20);
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
    }
}

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
    gCurrentPinballGame->holeIndicators[0] = 0;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->unk614 = 0;
    gCurrentPinballGame->unk208 = 0;
    gCurrentPinballGame->unk20A = 0;
    if (gCurrentPinballGame->outLanePikaPosition != 2 || !gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
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

    gCurrentPinballGame->ballPowerUpLight[0] = 0;
    gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
    gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
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
