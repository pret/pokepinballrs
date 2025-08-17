#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern u8 gUnknown_020306D0[];

extern const u8 gUnknown_0839C78C[];
extern const u8 gUnknown_0839DBAC[];
extern const u8 gUnknown_086ACF80[];


void sub_27F94(void)
{
    s16 i;

    if (gCurrentPinballGame->unk294 && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->unk17 < 10)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->unk18 = 200;
        gCurrentPinballGame->unk17 = 10;
    }

    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        BuildSpeciesWeightsForCatchEmMode();
        gCurrentPinballGame->unk17++;
        break;
    case 1:
        PickSpeciesForCatchEmMode();
        if (gMain.mainState != 3)
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);

        gCurrentPinballGame->unk17++;
        break;
    case 2:
        sub_28AE0();
        gCurrentPinballGame->catchModeArrows = 0;
        gCurrentPinballGame->unk17++;
        break;
    case 3:
        sub_1C7F4(3, 0);
        gCurrentPinballGame->unk6C5 = 0;
        gCurrentPinballGame->unk602 = 0;
        gCurrentPinballGame->unk17++;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->unk6D3[i] = 15;
        break;
    case 4:
        if (gMain.unkF == 0)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->unk28 == 0x5E)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->unk28 == 0x5D)
                {
                    gMain.unkF |= 1;
                    gCurrentPinballGame->unkEA = 0;
                    gCurrentPinballGame->unkEC = 120;
                    gCurrentPinballGame->unkE8 = 0;
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unkEE = 0;
                    gCurrentPinballGame->unkF2 = 2;
                    gCurrentPinballGame->unkFA = 1;
                    gCurrentPinballGame->unkFB = 1;
                    gCurrentPinballGame->unkF4 = 80;
                    gCurrentPinballGame->unkF6 = -2500;
                    gCurrentPinballGame->unkF0 = 50;
                    gCurrentPinballGame->unkF8 = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->unk28 == 0x49)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE);
                }
                else if (gCurrentPinballGame->unk28 < 17)
                {
                    gCurrentPinballGame->unk294 = 2;
                    gCurrentPinballGame->unk17++;
                }
            }
            else
            {
                if (gCurrentPinballGame->unk28 == 0x44)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->unk28 == 0x43)
                {
                    gMain.unkF |= 1;
                    gCurrentPinballGame->unkEA = 0;
                    gCurrentPinballGame->unkEC = 120;
                    gCurrentPinballGame->unkE8 = 0;
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unkEE = 0;
                    gCurrentPinballGame->unkF2 = 2;
                    gCurrentPinballGame->unkFA = 1;
                    gCurrentPinballGame->unkFB = 1;
                    gCurrentPinballGame->unkF4 = 80;
                    gCurrentPinballGame->unkF6 = -2500;
                    gCurrentPinballGame->unkF0 = 50;
                    gCurrentPinballGame->unkF8 = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->unk28 == 0x2F)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE2);
                }
                else if (gCurrentPinballGame->unk28 == 0)
                {
                    gCurrentPinballGame->unk294 = 2;
                    gCurrentPinballGame->unk17++;
                }
            }
        }

        sub_29334();
        return;
    case 5:
        gCurrentPinballGame->unk729 = 1;
        sub_29334();
        gCurrentPinballGame->unk18 = 0;
        return;
    case 6:
        gCurrentPinballGame->unk729 = 0;
        if (gCurrentPinballGame->unk18 == 0)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unkE4 = 10;
            DmaCopy16(3, gUnknown_0839C78C, (void *)0x06015800, 0x1400);
            DmaCopy16(3, gUnknown_0839DBAC, (void *)0x050003C0, 0x20);
            m4aSongNumStart(SE_UNKNOWN_0xA7);
            gCurrentPinballGame->unk17++;
            gCurrentPinballGame->unk18 = 0;
        }
        break;
    case 7:
        sub_293D8();
        return;
    case 8:
        sub_29624();
        DmaCopy16(3, gUnknown_086ACF80, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gUnknown_020306D0, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->unk288 = 118;
        gCurrentPinballGame->unk28A = 264;
        gCurrentPinballGame->unk720 = 0;
        gCurrentPinballGame->unk71D[0] = 2;
        gCurrentPinballGame->unk71D[1] = 2;
        gCurrentPinballGame->unk71D[2] = 2;
        sub_28C90();
        gCurrentPinballGame->unk5F2 = 1;
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unk29C = 140;
        PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].mainSeriesIndexNumber, 0);
        gCurrentPinballGame->unk18 = 0;
        return;
    case 9:
        if (gCurrentPinballGame->unk18 == 0)
        {
            gCurrentPinballGame->unkEC = 0;
            gCurrentPinballGame->unk18++;
        }
        sub_28C90();
        if (gCurrentPinballGame->unk5AA)
            gCurrentPinballGame->unk5AA--;
        break;
    case 10:
        sub_28E2C();
        sub_2530C();
        gCurrentPinballGame->unk17++;
        break;
    case 11:
        sub_27D44();
        gCurrentPinballGame->unk17++;
        break;
    case 12:
        gCurrentPinballGame->unk729 = 0;
        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk18--;
        }
        else
        {
            if (gCurrentPinballGame->unk71D[2] == 1)
                sub_19B64(3);
            else
                sub_19B64(1);

            gCurrentPinballGame->unk17 = 0;
        }
        break;
    }
}
