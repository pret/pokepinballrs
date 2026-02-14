#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const s16 gUnknown_08137D48[];
extern const u8 gRayquazaBonusClear_Gfx[];
extern const u8 gUnknown_083C5A2C[];
extern const u8 gUnknown_084A6EEC[][0x280];
extern const u8 gUnknown_084A856C[];
extern const u8 gUnknown_084AA18C[];
extern const u8 gUnknown_084AA9EC[][0x800];
extern const s16 gUnknown_086AEF28[];
extern const u16 gUnknown_086AF3CC[][3];
extern const struct Vector16 gUnknown_086AF744[32];
extern const s16 gUnknown_086AF784[];
extern const u16 gUnknown_086B5ECA[39][6][3];
extern const u16 gUnknown_086B5CC0[10][5][3];
extern const u16 gUnknown_086B5D56[20][2][3];
extern const u16 gUnknown_086B5DCE[12][7][3];
extern const u16 gUnknown_086B609E[10][3][3];
extern const u16 gUnknown_086B612E[212][3];

void RayquazaBoardProcess_3A_3E79C(void)
{
    s16 i;
    s16 frame;

    frame = gMain.systemFrameCount % 10;
    for (i = 0; i < frame; i++)
        Random();

    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 10 == 9)
        gCurrentPinballGame->unk384 = 18;
    else
        gCurrentPinballGame->unk384 = 15;

    gCurrentPinballGame->unk294 = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk388 = 3;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unkE6 = -88;
    gCurrentPinballGame->unk387 = 1;
    gCurrentPinballGame->unk6C4 = 3;
    gCurrentPinballGame->unk382 = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk385 = 0;
    gCurrentPinballGame->unk386 = 0;
    gCurrentPinballGame->unk389 = 0;
    gCurrentPinballGame->unk38A = 0;
    gCurrentPinballGame->unk38C = 0;
    gCurrentPinballGame->unk38E = 0;
    gCurrentPinballGame->unk390 = 0;
    gCurrentPinballGame->unk394 = 0;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->unk3C4[i].x = 0;
        gCurrentPinballGame->unk3C4[i].y = 0;
    }

    gCurrentPinballGame->unk3DC = 0;
    gCurrentPinballGame->unk3DD = 0;
    gCurrentPinballGame->unk3DE = 0;
    gCurrentPinballGame->unk3DF = 0;
    gCurrentPinballGame->unk3E0 = 0;
    gCurrentPinballGame->unk3E2 = 0;
    gCurrentPinballGame->unk3E1 = 0;
    gCurrentPinballGame->unk3E4 = 0;
    gCurrentPinballGame->unk3E6 = 0;
    gCurrentPinballGame->unk3E8 = 0;
    gCurrentPinballGame->unk3EA = 0;
    gCurrentPinballGame->unk3EC = 0;
    gCurrentPinballGame->unk3EE = 0;
    gCurrentPinballGame->unk3F0 = 0;
    gCurrentPinballGame->unk3F2 = 0;
    gCurrentPinballGame->unk414.x = 0;
    gCurrentPinballGame->unk414.y = 0;
    gCurrentPinballGame->unk418.x = 0;
    gCurrentPinballGame->unk418.y = 0;
    gCurrentPinballGame->unk452 = 0;

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->unk441[i] = 0;
        gCurrentPinballGame->unk443[i] = 0;
        gCurrentPinballGame->unk458[i] = 0;
        gCurrentPinballGame->unk45C[i].x = 0;
        gCurrentPinballGame->unk45C[i].y = 0;
        gCurrentPinballGame->unk464[i].x = 0;
        gCurrentPinballGame->unk464[i].y = 0;
    }

    gCurrentPinballGame->unk4C8 = 0;
    gCurrentPinballGame->unk47F = 0;
    gCurrentPinballGame->unk480 = 0;
    gCurrentPinballGame->unk486 = 0;
    gCurrentPinballGame->unk504 = 0;
    gCurrentPinballGame->unk505 = 0;
    gCurrentPinballGame->unk506 = 0;
    gCurrentPinballGame->unk507 = 0;
    gCurrentPinballGame->unk508 = 0;
    gCurrentPinballGame->unk50A = 0;
    gCurrentPinballGame->unk50C = 0;
    gCurrentPinballGame->unk50E = 0;
    gCurrentPinballGame->unk510 = 0;
    gCurrentPinballGame->unk512 = 0;
    gCurrentPinballGame->unk514 = 0;
    gCurrentPinballGame->unk516 = 0;
    gCurrentPinballGame->unk518 = 0;
    gCurrentPinballGame->unk51A = 0;
    gCurrentPinballGame->unk51C.x = 0;
    gCurrentPinballGame->unk51C.y = 0;
    gCurrentPinballGame->unk520.x = 0;
    gCurrentPinballGame->unk520.y = 0;
    gCurrentPinballGame->unk524.x = 0;
    gCurrentPinballGame->unk524.y = 0;
    gCurrentPinballGame->unk528.x = 0;
    gCurrentPinballGame->unk528.y = 0;
    gCurrentPinballGame->unk1A = 1;
    sub_423D8();
    DmaCopy16(3, gUnknown_083C5A2C, (void *)0x06015800, 0x2800);
    DmaCopy16(3, gUnknown_084AA18C, (void *)0x06011620, 0x860);
    sub_3EDF0();
    sub_3FAE0();
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void RayquazaBoardProcess_3B_3EB2C(void)
{
    switch (gCurrentPinballGame->unk13)
    {
    case 0:
        gCurrentPinballGame->unk5F7 = 1;
        if (gCurrentPinballGame->unk506 == 1)
        {
            gCurrentPinballGame->unkE6 = 0;
            gCurrentPinballGame->unk13 = 1;
            gCurrentPinballGame->unk18 = 0;
        }
        break;
    case 1:
        break;
    case 2:
        gCurrentPinballGame->unk13 = 3;
        gCurrentPinballGame->unk18 = 0;
        gMain.spriteGroups[6].available = 1;
        gMain.spriteGroups[5].available = 1;
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->unk394 = 136;
        gMain.unkF = 0x80;
        gCurrentPinballGame->unk5FA = 1;
        break;
    case 3:
        sub_351A8();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = 99999999;
        }

        if (gCurrentPinballGame->unk18 < 240)
        {
            if (gCurrentPinballGame->unk18 == 20)
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_SUCCESS3);
            }

            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk13 = 6;
            gCurrentPinballGame->numCompletedBonusStages++;
        }

        gCurrentPinballGame->unk5FA = 1;
        break;
    case 4:
        gCurrentPinballGame->unk13 = 5;
        gCurrentPinballGame->unk18 = 140;
        gMain.spriteGroups[6].available = 1;
        gMain.spriteGroups[5].available = 1;
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->unk394 = 136;
        gMain.unkF = 0x80;
        break;
    case 5:
        sub_351A8();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = 99999999;
        }

        if (gCurrentPinballGame->unk18 < 240)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk13 = 6;
            gCurrentPinballGame->numCompletedBonusStages++;
            gCurrentPinballGame->unk1AF = 0;
        }
        break;
    case 6:
        sub_351A8();
        gCurrentPinballGame->unk386 = 1;
        gCurrentPinballGame->unk5FA = 1;
        break;
    }

    sub_423D8();
    sub_40288();
    sub_3EDF0();
    sub_3FAE0();
    if (gCurrentPinballGame->unk294 && gCurrentPinballGame->eventTimer < 2 && gMain.unkF == 0)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL3);
        gMain.unkF |= 0x40;
    }

    if (gCurrentPinballGame->unk386)
    {
        gCurrentPinballGame->unk5FA = 1;
        sub_350F0();
    }

    sub_472E4();
}

void sub_3EDF0(void)
{
    if (gCurrentPinballGame->unk452)
    {
        gCurrentPinballGame->unk452--;
        gCurrentPinballGame->unk389 = 1;
        if (gCurrentPinballGame->unk452 == 5)
        {
            m4aSongNumStart(SE_RAYQUAZA_HIT);
            gCurrentPinballGame->scoreAddedInFrame = 1000000;
            gCurrentPinballGame->unk385++;
            sub_11B0(7);
            if (gCurrentPinballGame->unk385 >= gCurrentPinballGame->unk384 && gCurrentPinballGame->unk3DC != 6)
                gCurrentPinballGame->unk3DC = 9;
        }

        gCurrentPinballGame->unk50C = 20;
        if (gCurrentPinballGame->unk452 == 0)
            gCurrentPinballGame->unk389 = 0;
    }

    if (gCurrentPinballGame->unk50C)
    {
        gCurrentPinballGame->unk50C--;
        gCurrentPinballGame->unk387 = 0;
    }
    else
    {
        gCurrentPinballGame->unk387 = 1;
    }

    switch (gCurrentPinballGame->unk3DC)
    {
    case 0:
        gCurrentPinballGame->unk3E8 = 1140;
        gCurrentPinballGame->unk3EA = 2400;
        gCurrentPinballGame->unk3DC = 1;
        gCurrentPinballGame->unk3E2 = 13;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3E1 = 0;
        gCurrentPinballGame->unk51A = 0;
        break;
    case 1:
        if (gCurrentPinballGame->unk516 > 530)
        {
            if (gCurrentPinballGame->unk3EA > -1200)
                gCurrentPinballGame->unk3EA -= 70;

            if (gCurrentPinballGame->unk516 == 672)
            {
                gCurrentPinballGame->unk3DC = 2;
                gCurrentPinballGame->unk3E8 = 0;
                gCurrentPinballGame->unk3EA = -640;
            }
        }

        if (gCurrentPinballGame->unk516 == 530)
            gCurrentPinballGame->unk390 = 25;
        break;
    case 2:
        if (gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 63)
                gCurrentPinballGame->unk3E2 = 13;
        }

        if (gCurrentPinballGame->unk3EA < 0)
        {
            gCurrentPinballGame->unk3EA += 18;
            if (gCurrentPinballGame->unk3EA > 0)
            {
                gCurrentPinballGame->unk3EA = 0;
                m4aSongNumStart(MUS_BONUS_FIELD_RAYQUAZA);
            }
        }

        if (gCurrentPinballGame->unk3EA == 0)
        {
            gCurrentPinballGame->unk3DC = 5;
            gCurrentPinballGame->unk3E1 = 0;
            gCurrentPinballGame->unk3DD = 6;
        }
        break;
    case 3:
        if (gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 63)
                gCurrentPinballGame->unk3E2 = 13;
        }

        if (gCurrentPinballGame->unk3EA < 0)
        {
            gCurrentPinballGame->unk3EA += 18;
            if (gCurrentPinballGame->unk3EA > 0)
                gCurrentPinballGame->unk3EA = 0;
        }

        if (gCurrentPinballGame->unk3EA == 0)
        {
            gCurrentPinballGame->unk3DC = 5;
            gCurrentPinballGame->unk3E1 = 0;
            gCurrentPinballGame->unk3DD = 6;
        }
        break;
    case 4:
        if (gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 34)
                gCurrentPinballGame->unk3E2 = 33;
        }

        if (gCurrentPinballGame->unk3E2 == 33 && gCurrentPinballGame->unk3EA > -0x300)
        {
            gCurrentPinballGame->unk3EA -= 0x18;
            if (gCurrentPinballGame->unk3EA < -0x300)
                gCurrentPinballGame->unk3EA = -0x300;
        }

        if (gCurrentPinballGame->unk3EA == -0x300)
        {
            gCurrentPinballGame->unk3E2 = 0;
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3DC = 7;
            gCurrentPinballGame->unk3E1 = 0;
        }
        break;
    case 5:
        if (gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 63)
            {
                if (gCurrentPinballGame->unk3E1 < 6)
                {
                    gCurrentPinballGame->unk3E2 = 13;
                    gCurrentPinballGame->unk3E1++;
                }
                else if (gCurrentPinballGame->unk3DD == 6)
                {
                    if (gCurrentPinballGame->unk385 >= gCurrentPinballGame->unk384 - 1)
                    {
                        gCurrentPinballGame->unk3E2 = 13;
                        gCurrentPinballGame->unk3DC = 4;
                        gCurrentPinballGame->unk3E1 = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E2 = 98;
                        gCurrentPinballGame->unk3DC = 6;
                        gCurrentPinballGame->unk3E1 = 0;
                    }
                }
                else
                {
                    gCurrentPinballGame->unk3E2 = 13;
                    gCurrentPinballGame->unk3DC = 4;
                    gCurrentPinballGame->unk3E1 = 0;
                }
            }
        }

        if (gCurrentPinballGame->unk3E1 > 1)
        {
            gCurrentPinballGame->unk512 += 0x80;
            gCurrentPinballGame->unk3E8 = ((Sin(gCurrentPinballGame->unk512) * 62) / 20000) * 10;
        }
        break;
    case 6:
        gCurrentPinballGame->unk389 = 2;
        if (gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 116 && gCurrentPinballGame->unk3E1 < 15)
            {
                gCurrentPinballGame->unk3E1++;
                gCurrentPinballGame->unk3E2 = 114;
            }

            if (gCurrentPinballGame->unk3E2 == 131)
            {
                gCurrentPinballGame->unk3E2 = 29;
                gCurrentPinballGame->unk3E1 = 0;
                gCurrentPinballGame->unk3DC = 5;
                gCurrentPinballGame->unk3DD = 4;
                gCurrentPinballGame->unk389 = 0;
            }

            if (gCurrentPinballGame->unk3E2 == 114)
            {
                if (gCurrentPinballGame->unk3E1 == 0)
                {
                    gMain.spriteGroups[17].available = 1;
                    gMain.spriteGroups[18].available = 1;
                    gMain.spriteGroups[19].available = 1;
                    gCurrentPinballGame->unk507 = 1;
                }
            }

            if (gCurrentPinballGame->unk3E2 == 120)
                gCurrentPinballGame->unk390 = 21;

            if (gCurrentPinballGame->unk3E2 == 124)
                gCurrentPinballGame->unk50A = 16;
        }
        break;
    case 7:
        if (gCurrentPinballGame->unk3E4 < 120)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3DC = 8;
            DmaCopy16(3, gUnknown_084A856C, (void *)0x06015800, 0x1C00);
            if (gCurrentPinballGame->unk504 & 1)
            {
                gMain.spriteGroups[22].available = 1;
                gMain.spriteGroups[24].available = 1;
                gMain.spriteGroups[25].available = 1;
            }
            else
            {
                gMain.spriteGroups[23].available = 1;
                gMain.spriteGroups[30].available = 1;
                gMain.spriteGroups[31].available = 1;
            }

            gCurrentPinballGame->unk504++;
            gCurrentPinballGame->unk524.x = 0;
            gCurrentPinballGame->unk524.y = 0;
            gCurrentPinballGame->unk528.x = 0;
            gCurrentPinballGame->unk528.y = 0;
            gCurrentPinballGame->unk514 = 0;
            gCurrentPinballGame->unk3E4 = 0;
            m4aSongNumStart(SE_RAYQUAZA_WIND);
        }
        break;
    case 8:
        if (gMain.spriteGroups[22].available)
        {
            if (gCurrentPinballGame->unk524.x < 4800)
                gCurrentPinballGame->unk524.x += 140;
            else
                gMain.spriteGroups[22].available = 0;

            if (gCurrentPinballGame->unk524.x > 2400)
            {
                if (gCurrentPinballGame->unk528.x < 4960)
                    gCurrentPinballGame->unk528.x += 200;

                gCurrentPinballGame->unk514++;
            }
        }
        else
        {
            if (gCurrentPinballGame->unk524.x > -4800)
                gCurrentPinballGame->unk524.x -= 140;
            else
                gMain.spriteGroups[23].available = 0;

            if (gCurrentPinballGame->unk524.x < -2400)
            {
                if (gCurrentPinballGame->unk528.x > -4960)
                    gCurrentPinballGame->unk528.x -= 200;

                gCurrentPinballGame->unk514++;
            }
        }

        if (gCurrentPinballGame->unk3E4 == 20)
            gCurrentPinballGame->unk4C8 = 60;

        gCurrentPinballGame->unk3E4++;
        if (gCurrentPinballGame->unk3E4 >= 200)
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2 = 13;
            gCurrentPinballGame->unk3DC = 3;
        }
        break;
    case 9:
        gCurrentPinballGame->unk294 = 3;
        if (gCurrentPinballGame->numCompletedBonusStages % 10 == 9)
        {
            gCurrentPinballGame->unk3DC = 14;
            gCurrentPinballGame->unk3E2 = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_RAYQUAZA;
            gCurrentPinballGame->unk38E = 0;
            gCurrentPinballGame->unk5A8 = 0;
            gCurrentPinballGame->unk5A6 = 0;
            gCurrentPinballGame->unk5A4 = 2;
        }
        else
        {
            gCurrentPinballGame->unk3DC = 10;
            gCurrentPinballGame->unk3E2 = 98;
            gMain.unkF = 0x80;
            gCurrentPinballGame->unk388 = 2;
            gCurrentPinballGame->unk392 = 0;
        }

        gCurrentPinballGame->unk3E4 = 0;
        if (gMain.spriteGroups[36].available)
            gCurrentPinballGame->unk486 = 1;
        break;
    case 10:
        if (gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 131)
            {
                gCurrentPinballGame->unk3E2 = 13;
                gCurrentPinballGame->unk3E1 = 0;
                gCurrentPinballGame->unk3DC = 11;
                gCurrentPinballGame->unk389 = 0;
            }

            if (gCurrentPinballGame->unk3E2 == 120)
                gCurrentPinballGame->unk390 = 21;
        }
        break;
    case 11:
        if (gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 34)
                gCurrentPinballGame->unk3E2 = 33;
        }
            if (gCurrentPinballGame->unk3E2 == 33)
            {
                if (gCurrentPinballGame->unk3EA > -0x300)
                {
                    gCurrentPinballGame->unk3EA -= 0x18;
                    if (gCurrentPinballGame->unk3EA < -0x300)
                        gCurrentPinballGame->unk3EA = -0x300;
                }
            }

            if (gCurrentPinballGame->unk3EA == -0x300)
            {
                gCurrentPinballGame->unk3E2 = 0;
                gCurrentPinballGame->unk3E4 = 0;
                gCurrentPinballGame->unk3DC = 12;
                gCurrentPinballGame->unk3E1 = 0;
            }

        break;
    case 12:
        DmaCopy16(3, gUnknown_084AA18C, (void *)0x06011620, 0x860);
        gCurrentPinballGame->unk3DC = 13;
        gCurrentPinballGame->unk3E8 = 1140;
        gCurrentPinballGame->unk3EA = -1200;
        gCurrentPinballGame->unk506 = 2;
        gCurrentPinballGame->unk516 = 0;
        gCurrentPinballGame->unk5FA = 1;
        gMain.unkF = 0x80;
        gMain.spriteGroups[14].available = 1;
        gCurrentPinballGame->unk3C4[0].x = 0;
        gCurrentPinballGame->unk3C4[0].y = -5000;
        gCurrentPinballGame->unk3C4[1].x = 1400;
        gCurrentPinballGame->unk3C4[1].y = -2000;
        gCurrentPinballGame->unk418.x = -200;
        gCurrentPinballGame->unk418.y = 800;
        gCurrentPinballGame->unk414.x = 24;
        gCurrentPinballGame->unk414.y = -16;
        break;
    case 13:
        if (gCurrentPinballGame->unk516 < 256)
        {
            if (gCurrentPinballGame->unk3E4 < 80)
                gCurrentPinballGame->unk3E4++;
            else if (gCurrentPinballGame->unk3EA < 2400)
                gCurrentPinballGame->unk3EA += 80;
        }
        else
        {
            gCurrentPinballGame->unk13 = 2;
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk3DC = 15;
        }
        break;
    case 14:
        gCurrentPinballGame->unk38C = 1;
        if (gCurrentPinballGame->unk38E > -500)
        {
            gCurrentPinballGame->unk38E += (-500 - gCurrentPinballGame->unk38E) / 30;
            gCurrentPinballGame->unkE6 = gCurrentPinballGame->unk38E / 10;
            if (gCurrentPinballGame->unkE6 < -38)
                gCurrentPinballGame->unkE6 = -38;
        }
        break;
    case 15:
        break;
    }

    if (gCurrentPinballGame->unk390)
    {
        gCurrentPinballGame->unk390--;
        if (gCurrentPinballGame->unk390 == 20)
            PlayCry_Normal(gSpeciesInfo[SPECIES_RAYQUAZA].mainSeriesIndexNumber, 0);

        if (gCurrentPinballGame->unk390 == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void sub_3FAE0(void)
{
    s16 i;
    s16 sp0;
    s16 varSL;
    s32 temp;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    s16 var1;
    s8 y;

    varSL = 0;
    sp0 = 0;
    group = &gMain.spriteGroups[43];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk3E8 / 10;
        group->baseY = gCurrentPinballGame->unk3EA / 10;
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            var0 = (s8)oamSimple->yOffset + group->baseY;
            if (var0 > 180 || var0 < -60)
            {
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }

    group = &gMain.spriteGroups[42];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk3E8 / 10;
        group->baseY = gCurrentPinballGame->unk3EA / 10;
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            var0 = (s8)oamSimple->yOffset + group->baseY;
            if (var0 > 180 || var0 < -60)
            {
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        if (gCurrentPinballGame->unk516 == 671)
        {
            group->available = 0;
            gMain.spriteGroups[41].available = 1;
            gMain.spriteGroups[45].available = 1;
        }
    }
    else
    {
        group = &gMain.spriteGroups[41];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->unk3E8 / 10 - (gCurrentPinballGame->unk58 - 88);
            group->baseY = gCurrentPinballGame->unk3EA / 10 - (gCurrentPinballGame->unk5A - 78);
            gCurrentPinballGame->unk288 = gCurrentPinballGame->unk3E8 / 10 + 116;
            gCurrentPinballGame->unk28A = gCurrentPinballGame->unk3EA / 10 + 60;
            if (gCurrentPinballGame->unk51A > 91)
            {
                gCurrentPinballGame->unk3F0 = (gCurrentPinballGame->unk3E8 / 10) * 2 + 172;
                gCurrentPinballGame->unk3F2 = (gCurrentPinballGame->unk3EA / 10) * 2 + 184;
            }
            else
            {
                gCurrentPinballGame->unk3F0 = 0;
                gCurrentPinballGame->unk3F2 = -160;
            }

            if (group->baseY < -70)
                group->baseY = -70;
            if (group->baseY > 180)
                group->baseY = 180;

            var1 = gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][0];
            if (gCurrentPinballGame->unk389 > 9)
            {
                sp0 = 11;
                oamSimple = &group->oam[0];
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
                gOamBuffer[oamSimple->oamId].paletteNum = sp0;
            }
            else
            {
                if (gCurrentPinballGame->unk389 == 1)
                {
                    varSL = 2;
                    sp0 = 14;
                }
                else if (gCurrentPinballGame->unk389 == 3)
                {
                    varSL = 2;
                    sp0 = 11;
                }
                else
                {
                    varSL = gCurrentPinballGame->unk3DF;
                    sp0 = 15;
                }

                if (gCurrentPinballGame->unk5A8 == 21)
                    varSL = 8;

                if (gCurrentPinballGame->unk5A8 == 22)
                    varSL = 9;

                oamSimple = &group->oam[0];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B612E[var1];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                y = gOamBuffer[oamSimple->oamId].y;
                gCurrentPinballGame->unk51A = (y + 78u) + (gCurrentPinballGame->unk3EA / 10);
                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                if (gCurrentPinballGame->unk389 < 2)
                    gOamBuffer[oamSimple->oamId].paletteNum = sp0;
                else
                    sp0 = gOamBuffer[oamSimple->oamId].paletteNum;
            }

            gCurrentPinballGame->unk3DF = gUnknown_086AF3CC[gCurrentPinballGame->unk3E2][2];
            DmaCopy16(3, gUnknown_084AA9EC[varSL], (void *)0x06011620, 0x800);
        }

        group = &gMain.spriteGroups[21];
        if (group->available)
        {
            if (varSL >= 8)
            {
                group->baseX = 0;
                group->baseY = 0;
                varSL = 0;
            }
            else if (varSL >= 6)
            {
                group->baseX = gCurrentPinballGame->unk3E8 / 10 - (gCurrentPinballGame->unk58 - 88);
                group->baseY = gCurrentPinballGame->unk3EA / 10 - gCurrentPinballGame->unk5A + 96;
                varSL -= 6;
            }
            else
            {
                group->baseX = 0;
                group->baseY = 0;
            }

            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum = varSL * 12 + i * 8 + 0x109;
                gOamBuffer[oamSimple->oamId].paletteNum = sp0;
            }
        }

        group = &gMain.spriteGroups[45];
        if (group->available)
        {
            s16 var2 = (gCurrentPinballGame->unk51A - 70) / 3 + 1;
            if (var2 < 0)
                var2 = 0;
            else if (var2 > 9)
                var2 = 9;

            if (gCurrentPinballGame->unk3DC != 14)
            {
                if (gCurrentPinballGame->unk50A > 0)
                {
                    gMain.blendControl = 0x9E;
                    gMain.blendBrightness = gCurrentPinballGame->unk50A;
                    gCurrentPinballGame->unk50A--;
                }
                else
                {
                    if ((gMain.unkF & 0xC0) == 0)
                    {
                        gMain.blendControl = 0x1E10;
                        gMain.blendAlpha = BLDALPHA_BLEND(var2, 0x10 - var2);
                    }
                }
            }

            group->baseX = gCurrentPinballGame->unk3E8 / 10 - (gCurrentPinballGame->unk58 - 88);
            group->baseY = gCurrentPinballGame->unk3EA / 10 - (gCurrentPinballGame->unk5A - 78) + 36 + var2;
            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

            if (gCurrentPinballGame->unk3DC == 12)
            {
                gMain.spriteGroups[43].available = 1;
                gMain.spriteGroups[41].available = 0;
                gMain.spriteGroups[45].available = 0;
                gMain.spriteGroups[21].available = 0;
            }

            if (gCurrentPinballGame->unk5A8 == 21)
            {
                gMain.spriteGroups[45].available = 0;
                gMain.spriteGroups[21].available = 0;
            }
        }
    }
}

void sub_40288(void)
{
    s16 sp0;
    s16 sp4;
    s16 sp8;
    s16 i, j;
    struct SpriteGroup *group;
    struct Vector32 tempVector2;
    struct Vector32 tempVector;
    s16 var0;
    int x, y;
    int xx, yy;
    int squaredMagnitude;
    u16 *dst;
    const u16 *src;
    struct OamDataSimple *oamSimple;

    sp8 = 0;
    sp4 = 0;
    var0 = 0;
    sp0 = 0;
    group = &gMain.spriteGroups[10];
    if (group->available)
    {
        if (gCurrentPinballGame->unk6C4 == 3)
        {
            group->baseX = 240;
            group->baseY = 180;
        }
        else
        {
            group->baseX = 96;
            group->baseY = 55;
        }

        gCurrentPinballGame->unk6E4.x = group->baseX;
        gCurrentPinballGame->unk6E4.y = group->baseY;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].paletteNum = 13;
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->unk6DB;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[9];
        group->baseX = gCurrentPinballGame->unk6E4.x - 8;
        group->baseY = gCurrentPinballGame->unk6E4.y - 8;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->unk6DB;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    sub_41580();
    switch (gCurrentPinballGame->unk507)
    {
    case 0:
        gCurrentPinballGame->unk510 = 0;
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        break;
    case 1:
        if (gCurrentPinballGame->unk510 == 0)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->unk510 == 8)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->unk510 == 24)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->unk510 == 36)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->unk510 == 50)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->unk510 == 56)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->unk510 < 14)
            var0 = gCurrentPinballGame->unk510 / 2;
        else if (gCurrentPinballGame->unk510 < 42)
            var0 = 7;
        else if (gCurrentPinballGame->unk510 < 56)
            var0 = (gCurrentPinballGame->unk510 - 42) / 2;
        else if (gCurrentPinballGame->unk510 < 61)
            var0 = 7;
        else
            var0 = (gCurrentPinballGame->unk510 - 61) / 2;

        if (gCurrentPinballGame->unk510 < 8)
            sp4 = gCurrentPinballGame->unk510 / 2;
        else if (gCurrentPinballGame->unk510 < 48)
            sp4 = 12;
        else if (gCurrentPinballGame->unk510 < 64)
            sp4 = (gCurrentPinballGame->unk510 - 48) / 2 + 4;
        else
            sp4 = 12;

        sp8 = 5;
        gCurrentPinballGame->unk510++;
        if (gCurrentPinballGame->unk510 == 75)
        {
            gCurrentPinballGame->unk510 = 0;
            gCurrentPinballGame->unk507 = 2;
        }
        break;
    case 2:
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        if (gCurrentPinballGame->unk510 < 34)
        {
            gCurrentPinballGame->unk510++;
            if (gCurrentPinballGame->unk510 == 28)
            {
                if (gCurrentPinballGame->unk388)
                {
                    gCurrentPinballGame->unk51C.x = 200 - (Random() % 160);
                    gCurrentPinballGame->unk51C.y = gCurrentPinballGame->ball->positionQ0.y - 347 - (Random() % 80);
                }
                else
                {
                    gCurrentPinballGame->unk51C.x = gCurrentPinballGame->ball->positionQ0.x - 13;
                    gCurrentPinballGame->unk51C.y = gCurrentPinballGame->ball->positionQ0.y - 347;
                }
            }
        }
        else
        {
            gCurrentPinballGame->unk510 = 0;
            gCurrentPinballGame->unk507 = 3;
            m4aSongNumStart(SE_RAYQUAZA_FLYBY);
        }
        break;
    case 3:
        var0 = 7;
        sp4 = 12;
        if (gCurrentPinballGame->unk510 < 2)
        {
            sp8 = gCurrentPinballGame->unk510;
        }
        else if (gCurrentPinballGame->unk510 < 10)
        {
            sp8 = (gCurrentPinballGame->unk510 - 2) / 2 + 2;
            gCurrentPinballGame->unk508 = sp4;
            if (sp8 == 2)
            {
                int a = 13;
                int b = 347;
                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - a - gCurrentPinballGame->unk51C.x;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - b - gCurrentPinballGame->unk51C.y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;

                sub_11B0(8);
                if (gCurrentPinballGame->unk441[0] < 3 && gCurrentPinballGame->unk441[1] < 3 &&
                    gCurrentPinballGame->unk388 == 0 && squaredMagnitude < 200)
                {
                    gMain.spriteGroups[36].available = 1;
                    gCurrentPinballGame->unk486 = 600;
                    m4aSongNumStart(SE_UNKNOWN_0x12A);
                    sub_11B0(9);
                }
            }
        }
        else
        {
            sp8 = 5;
            gCurrentPinballGame->unk507 = 4;
        }

        gCurrentPinballGame->unk510++;
        break;
    case 4:
        gCurrentPinballGame->unk510 = 0;
        gCurrentPinballGame->unk507 = 0;
        break;
    }

    group = &gMain.spriteGroups[17];
    if (group->available)
    {
        // ! odd behavior in the assembly with the addition and subtraction
        group->baseX = gCurrentPinballGame->unk3E8 / 10 - (gCurrentPinballGame->unk58 - 88);
        group->baseY = gCurrentPinballGame->unk3EA / 10 - gCurrentPinballGame->unk5A + 96;
        for (j = 0; j < 3; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B609E[var0][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->unk507 == 4)
            gMain.spriteGroups[17].available = 0;
    }

    group = &gMain.spriteGroups[18];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk3E8 / 10 - (gCurrentPinballGame->unk58 - 88);
        group->baseY = gCurrentPinballGame->unk3EA / 10 - gCurrentPinballGame->unk5A + 96;
        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B5ECA[sp4][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->unk507 == 4)
            gMain.spriteGroups[18].available = 0;
    }

    group = &gMain.spriteGroups[19];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk51C.x - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk51C.y - gCurrentPinballGame->unk5A;
        for (j = 0; j < 7; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B5DCE[sp8][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            if ((s8)gOamBuffer[oamSimple->oamId].y + group->baseY < -300)
            {
                gOamBuffer[oamSimple->oamId].x = 0;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->unk507 == 4)
            gMain.spriteGroups[19].available = 0;
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk524.x / 10 - (gCurrentPinballGame->unk58 + 120);
        group->baseY = gCurrentPinballGame->unk524.y / 10 - (gCurrentPinballGame->unk5A - 128);
        for (j = 0; j < 18; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[23];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk524.x / 10 - (gCurrentPinballGame->unk58 - 360);
        group->baseY = gCurrentPinballGame->unk524.y / 10 - (gCurrentPinballGame->unk5A - 128);
        for (j = 0; j < 18; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->unk38C > 0)
        gCurrentPinballGame->ball->oamPriority = 1;
    else
        gCurrentPinballGame->ball->oamPriority = 2;

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[15 + i];
        switch (gCurrentPinballGame->unk441[i])
        {
        case 0:
            sp0 = 0;
            gCurrentPinballGame->unk45C[i].x = 0;
            gCurrentPinballGame->unk45C[i].y = 0;
            break;
        case 1:
            sp0 = gCurrentPinballGame->unk458[i] / 5 + 1;
            if (gCurrentPinballGame->unk458[i] < 14)
            {
                gCurrentPinballGame->unk458[i]++;
            }
            else
            {
                gCurrentPinballGame->unk458[i] = 0;
                gCurrentPinballGame->unk441[i] = 2;
            }
            break;
        case 2:
            sp0 = gCurrentPinballGame->unk458[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            if (gCurrentPinballGame->unk441[i] < 3)
            {

                s16 angle = (((gMain.systemFrameCount + 120 * i) % 240) << 0x10) / 240;
                gCurrentPinballGame->unk45C[i].x = gCurrentPinballGame->unk464[i].x + (Cos(angle) * 4) / 2000;
                gCurrentPinballGame->unk45C[i].y = gCurrentPinballGame->unk464[i].y + (Sin(angle) * 4) / 2000;

                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->unk45C[i].x / 10) - 16;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->unk45C[i].y / 10) - 32;;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;
                if (gCurrentPinballGame->unk383 == 0 && gCurrentPinballGame->unk388 == 0 &&
                    gCurrentPinballGame->unk385 < gCurrentPinballGame->unk384 &&
                    gCurrentPinballGame->unk452 == 0 && squaredMagnitude < 300)
                {
                    gCurrentPinballGame->unk486 = 6;
                    gCurrentPinballGame->unk1F = 1;
                    gCurrentPinballGame->unk458[i] = 0;
                    gCurrentPinballGame->unk441[i] = 3;
                    gCurrentPinballGame->unk5FA = 1;

                    tempVector2.x = gCurrentPinballGame->unk45C[i].x / 10 + 16;
                    tempVector2.y = gCurrentPinballGame->unk45C[i].y / 10 + 32;
                    tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                    tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                    gCurrentPinballGame->unk5AC = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                    gCurrentPinballGame->unk5AC = Sqrt(gCurrentPinballGame->unk5AC * 4) / 2;
                    gCurrentPinballGame->unk5B0 = ArcTan2(-tempVector.x, tempVector.y);

                    gCurrentPinballGame->unk505 = i + 1;
                    gCurrentPinballGame->unk520.x = gCurrentPinballGame->unk45C[i].x;
                    gCurrentPinballGame->unk520.y = gCurrentPinballGame->unk45C[i].y;
                    m4aSongNumStart(SE_UNKNOWN_0x12B);
                    sub_11B0(13);
                }
            }

            if (gCurrentPinballGame->unk458[i] < 840)
            {
                gCurrentPinballGame->unk458[i]++;
            }
            else
            {
                gCurrentPinballGame->unk458[i] = 0;
                gCurrentPinballGame->unk441[i] = 5;
            }
            break;
        case 3: {
            s16 var4;
            int var5;

            sp0 = gCurrentPinballGame->unk458[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            var4 = 29 - gCurrentPinballGame->unk458[i];
            if (var4 < 10)
                var4 = 10;

            gCurrentPinballGame->unk5B0 -= ((0x2000 - (var4 * 0x2000) / 30) * 2) / 5;
            gCurrentPinballGame->ball->unkA -= 0x2000;
            var5 = (gCurrentPinballGame->unk5AC * var4) / 30;
            tempVector2.x = gCurrentPinballGame->unk45C[i].x / 10 + 16;
            tempVector2.y = gCurrentPinballGame->unk45C[i].y / 10 + 32;
            gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->unk5B0) * var5) / 20000);
            gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->unk5B0) * var5) / 20000);
            gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
            gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

            if (gCurrentPinballGame->unk38C < 1800)
            {
                gCurrentPinballGame->unk38A = 0;
                gCurrentPinballGame->unk38C += 32;
            }

            if (gCurrentPinballGame->unk458[i] < 180)
            {
                gCurrentPinballGame->unk458[i]++;
            }
            else
            {
                gCurrentPinballGame->unk458[i] = 0;
                gCurrentPinballGame->unk441[i] = 4;
                gCurrentPinballGame->unk5AC /= 2;
                gCurrentPinballGame->ball->positionQ8.y = 0xA500;
            }
            break;
        }
        case 4:
            if (gCurrentPinballGame->unk458[i] < 130)
            {
                if (gCurrentPinballGame->unk458[i] == 10)
                    m4aSongNumStart(SE_UNKNOWN_0x12C);

                gCurrentPinballGame->unk38A--;
                gCurrentPinballGame->unk38C += gCurrentPinballGame->unk38A;
                if (gCurrentPinballGame->unk38C <= 0)
                {
                    gCurrentPinballGame->unk38C = 0;
                    gCurrentPinballGame->ball->velocity.y = -((gCurrentPinballGame->unk38A * 0x80) / 10) / 2;
                    gCurrentPinballGame->unk1F = 0;
                    gCurrentPinballGame->unk458[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = 0;
                    gCurrentPinballGame->unk441[i] = 0;
                    gCurrentPinballGame->unk5FA = 0;
                    sub_11B0(8);
                }

                gCurrentPinballGame->unk458[i]++;
            }
            break;
        case 5:
            sp0 = gCurrentPinballGame->unk458[i] / 6 + 7;
            if (gCurrentPinballGame->unk458[i] < 11)
            {
                gCurrentPinballGame->unk458[i]++;
            }
            else
            {
                gCurrentPinballGame->unk458[i] = 0;
                gCurrentPinballGame->unk441[i] = 0;
            }
            break;
        }

        if (group->available)
        {
            DmaCopy16(3, gUnknown_084A6EEC[sp0], (void *)0x06011EA0, 0x280);
            group->baseX = gCurrentPinballGame->unk45C[i].x / 10 - gCurrentPinballGame->unk58;
            group->baseY = gCurrentPinballGame->unk45C[i].y / 10 - gCurrentPinballGame->unk5A;
            for (j = 0; j < 2; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->unk441[i] == 0)
                group->available = 0;

            if (gCurrentPinballGame->unk505 && i == (gCurrentPinballGame->unk505 - 1))
                group->available = 0;
        }
    }

    sub_417F8();
    group = &gMain.spriteGroups[20];
    if (group->available)
    {
        s16 a;
        group->baseX = gCurrentPinballGame->unk520.x / 10 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk520.y / 10 - gCurrentPinballGame->unk5A;
        a = gCurrentPinballGame->unk50E / 5;
        for (j = 0; j < 5; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B5CC0[a][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->unk50E < 25)
        {
            gCurrentPinballGame->unk50E++;
            if (gCurrentPinballGame->unk50E == 25)
                group->available = 0;
        }
    }

    if (gCurrentPinballGame->unk505)
    {
        gCurrentPinballGame->unk505 = 0;
        gCurrentPinballGame->unk50E = 0;
        group->available = 1;
    }
}

void sub_41580(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    u16 *dst;
    const u16 *src;

    group = &gMain.spriteGroups[36];
    if (!group->available)
        return;

    gCurrentPinballGame->unk486--;
    if (gCurrentPinballGame->unk486 > 5)
    {
        var0 = gUnknown_08137D48[(gCurrentPinballGame->unk486 % 33) / 3];
        if (gCurrentPinballGame->unk47F > 0)
        {
            if (gCurrentPinballGame->unk47F == 7)
                gCurrentPinballGame->ball->positionQ8.x += 0x100;
            else if (gCurrentPinballGame->unk47F == 4)
                gCurrentPinballGame->ball->positionQ8.x -= 0x200;
            else if (gCurrentPinballGame->unk47F == 1)
                gCurrentPinballGame->ball->positionQ8.x += 0x100;

            gCurrentPinballGame->unk47F--;
        }
        else
        {
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->unk486 -= 30;
                if (gCurrentPinballGame->unk486 < 5)
                    gCurrentPinballGame->unk486 = 5;

                gCurrentPinballGame->unk47F = 7;
                m4aSongNumStart(SE_UNKNOWN_0x12A);
            }
        }

        if (gCurrentPinballGame->unk480)
        {
            gCurrentPinballGame->unk480--;
            if (gCurrentPinballGame->unk480 > 52)
                var0 = 8;
            else if (gCurrentPinballGame->unk480 > 42)
                var0 = 9;
        }
        else
        {
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
                gCurrentPinballGame->unk480 = 60;
        }

    }
    else
    {
        var0 = 8;
    }

    if (gCurrentPinballGame->unk486 == 0)
    {
        gMain.spriteGroups[36].available = 0;
        gCurrentPinballGame->unk480 = 0;
        gCurrentPinballGame->unk383 = 0;
    }
    else
    {
        gCurrentPinballGame->unk383 = 1;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->unk6 = 0;
    }

    group->baseX = gCurrentPinballGame->ball->positionQ0.x - gCurrentPinballGame->unk58 - 8;
    group->baseY = gCurrentPinballGame->ball->positionQ0.y - gCurrentPinballGame->unk5A - 8;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B5D56[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void sub_417F8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u32 rand;
    u16 var0;

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 + 128);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[25];
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 + 128);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[26];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 + 128);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[27];
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 + 128);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 9; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[28];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 + 128);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[29];
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 + 128);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 12; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[30];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 - 368);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[31];
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 - 368);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[32];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 - 368);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[33];
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 - 368);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 9; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[34];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 - 368);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[35];
        group->baseX = gCurrentPinballGame->unk528.x / 10 - (gCurrentPinballGame->unk58 - 368);
        group->baseY = gCurrentPinballGame->unk528.y / 10 - (gCurrentPinballGame->unk5A - 90);
        for (i = 0; i < 12; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gMain.spriteGroups[22].available)
    {
        if (gCurrentPinballGame->unk514 == 6)
        {
            gMain.spriteGroups[24].available = 0;
            gMain.spriteGroups[25].available = 0;
            gMain.spriteGroups[26].available = 1;
            gMain.spriteGroups[27].available = 1;
            if (gCurrentPinballGame->unk441[0] < 3 && gCurrentPinballGame->unk441[1] < 3 && gCurrentPinballGame->unk388 == 0)
            {
                gCurrentPinballGame->ball->velocity.x += 500;
                sub_11B0(13);
            }
        }

        if (gCurrentPinballGame->unk514 == 11)
        {
            gMain.spriteGroups[26].available = 0;
            gMain.spriteGroups[27].available = 0;
            gMain.spriteGroups[28].available = 1;
            gMain.spriteGroups[29].available = 1;
        }

        if (gCurrentPinballGame->unk514 == 14)
        {
            gMain.spriteGroups[28].available = 0;
            gMain.spriteGroups[29].available = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk514 == 6)
        {
            gMain.spriteGroups[30].available = 0;
            gMain.spriteGroups[31].available = 0;
            gMain.spriteGroups[32].available = 1;
            gMain.spriteGroups[33].available = 1;
            if (gCurrentPinballGame->unk441[0] < 3 && gCurrentPinballGame->unk441[1] < 3 && gCurrentPinballGame->unk388 == 0)
            {
                gCurrentPinballGame->ball->velocity.x -= 500;
                sub_11B0(13);
            }
        }

        if (gCurrentPinballGame->unk514 == 11)
        {
            gMain.spriteGroups[32].available = 0;
            gMain.spriteGroups[33].available = 0;
            gMain.spriteGroups[34].available = 1;
            gMain.spriteGroups[35].available = 1;
        }

        if (gCurrentPinballGame->unk514 == 14)
        {
            gMain.spriteGroups[34].available = 0;
            gMain.spriteGroups[35].available = 0;
        }
    }

    if (gCurrentPinballGame->unk514 == 10)
    {
        if (gCurrentPinballGame->unk441[0] < 3)
        {
            gCurrentPinballGame->unk458[0] = 0;
            gCurrentPinballGame->unk441[0] = 1;
            gMain.spriteGroups[15].available = 1;
            rand = Random() % 8;
            var0 = ((gMain.systemFrameCount % 240) << 0x10) / 240;
            gCurrentPinballGame->unk464[0].x = gUnknown_086AF744[rand].x;
            gCurrentPinballGame->unk464[0].y = gUnknown_086AF744[rand].y;
            gCurrentPinballGame->unk45C[0].x = gCurrentPinballGame->unk464[0].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->unk45C[0].y = gCurrentPinballGame->unk464[0].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_UNKNOWN_0x12D);
        }
    }

    if (gCurrentPinballGame->unk514 == 16)
    {
        if (gCurrentPinballGame->unk441[1] < 3)
        {
            gCurrentPinballGame->unk458[1] = 0;
            gCurrentPinballGame->unk441[1] = 1;
            gMain.spriteGroups[16].available = 1;
            rand = (Random() % 8 + 8) % 32; // Force 8 to be added to r1
            var0 = (((gMain.systemFrameCount + 120) % 240) << 0x10) / 240;
            gCurrentPinballGame->unk464[1].x = gUnknown_086AF744[rand].x;
            gCurrentPinballGame->unk464[1].y = gUnknown_086AF744[rand].y;
            gCurrentPinballGame->unk45C[1].x = gCurrentPinballGame->unk464[1].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->unk45C[1].y = gCurrentPinballGame->unk464[1].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_UNKNOWN_0x12D);
        }
    }

    if (gCurrentPinballGame->unk4C8 > 0)
    {
        gCurrentPinballGame->unk4C8--;
        if (gCurrentPinballGame->unk4C8 < 12)
            gCurrentPinballGame->unk2AC = gUnknown_086AEF28[gCurrentPinballGame->unk4C8 % 12];
        else if (gCurrentPinballGame->unk4C8 < 24)
            gCurrentPinballGame->unk2AC = gUnknown_086AEF28[gCurrentPinballGame->unk4C8 % 12] * 2;
        else if (gCurrentPinballGame->unk4C8 < 36)
            gCurrentPinballGame->unk2AC = gUnknown_086AEF28[gCurrentPinballGame->unk4C8 % 12] * 4;
        else if (gCurrentPinballGame->unk4C8 < 48)
            gCurrentPinballGame->unk2AC = gUnknown_086AEF28[gCurrentPinballGame->unk4C8 % 12] * 2;
        else
            gCurrentPinballGame->unk2AC = gUnknown_086AEF28[gCurrentPinballGame->unk4C8 % 12];

        if (gCurrentPinballGame->unk4C8 == 0)
            gCurrentPinballGame->unk2AC = 0;
    }

    if (gCurrentPinballGame->unk508 > 0)
    {
        s16 var0 = gCurrentPinballGame->unk508 % 4;
        if (var0 / 2 != 0)
            gCurrentPinballGame->unk2AA = 2;
        else
            gCurrentPinballGame->unk2AA = -2;

        gCurrentPinballGame->unk508--;
        if (gCurrentPinballGame->unk508 == 0)
            gCurrentPinballGame->unk2AA = 0;
    }
}

void sub_423D8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->unk506 == 0)
    {
        if (gCurrentPinballGame->unk516 < 689)
        {
            if (gCurrentPinballGame->unk516 < 569)
            {
                if (gCurrentPinballGame->unk516 % 160 == 20)
                    m4aMPlayVolumeControl(&gMPlayInfo_SE1, TRACKS_ALL, 0x80);

                if (gCurrentPinballGame->unk516 % 160 == 90)
                    m4aMPlayFadeOutTemporarily(&gMPlayInfo_SE1, 5);

                if (gCurrentPinballGame->unk516 % 160 == 1)
                    m4aSongNumStart(SE_RAYQUAZA_STAGE_WIND);

                if (gCurrentPinballGame->unk516 % 160 == 2)
                    m4aMPlayVolumeControl(&gMPlayInfo_SE1, TRACKS_ALL, 0x33);
            }

            if (gCurrentPinballGame->unk516 >= 512)
                gCurrentPinballGame->unkE6 = (gCurrentPinballGame->unk516 - 512) / 2 - 88;

            if (gCurrentPinballGame->unk516 == 624)
                gCurrentPinballGame->unk294 = 1;

            if (gCurrentPinballGame->unk516 < 513)
                gCurrentPinballGame->unk518 = gCurrentPinballGame->unk516 / 2;

            if (gCurrentPinballGame->unk516 == 688)
                gCurrentPinballGame->unk506 = 1;

            gCurrentPinballGame->unk516++;
            if (gCurrentPinballGame->unk516 <= 568 && gCurrentPinballGame->unk392 > 5)
                gCurrentPinballGame->unk392--;

            if (gCurrentPinballGame->unk516 == 1)
            {
                gCurrentPinballGame->unk3C4[0].x = 300;
                gCurrentPinballGame->unk3C4[0].y = 1200;
                gCurrentPinballGame->unk3C4[1].x = 1200;
                gCurrentPinballGame->unk3C4[1].y = 400;
                gCurrentPinballGame->unk3C4[2].x = 1000;
                gCurrentPinballGame->unk3C4[2].y = 2500;
            }

            if (gCurrentPinballGame->unk516 == 88)
            {
                gCurrentPinballGame->unk3C4[0].x = 1600;
                gCurrentPinballGame->unk3C4[0].y = 1800;
            }

            if (gCurrentPinballGame->unk516 == 120)
            {
                gCurrentPinballGame->unk3C4[1].x = 600;
                gCurrentPinballGame->unk3C4[1].y = 1800;
            }

            if (gCurrentPinballGame->unk516 == 170)
            {
                gCurrentPinballGame->unk3C4[2].x = 1800;
                gCurrentPinballGame->unk3C4[2].y = 2000;
            }

            if (gCurrentPinballGame->unk516 == 215)
            {
                gCurrentPinballGame->unk3C4[0].x = 0;
                gCurrentPinballGame->unk3C4[0].y = 2000;
            }

            if (gCurrentPinballGame->unk516 == 305)
            {
                gCurrentPinballGame->unk3C4[1].x = 1800;
                gCurrentPinballGame->unk3C4[1].y = 1800;
            }

            if (gCurrentPinballGame->unk516 == 315)
            {
                gCurrentPinballGame->unk3C4[2].x = 300;
                gCurrentPinballGame->unk3C4[2].y = 1800;
            }

            group = &gMain.spriteGroups[11];
            if (group->available)
            {
                group->baseX = gCurrentPinballGame->unk3C4[0].x / 10;
                group->baseY = gCurrentPinballGame->unk3C4[0].y / 10;
                if (group->baseY <= -60)
                    group->baseY = -60;
                else
                    gCurrentPinballGame->unk3C4[0].y -= 20;

                if (group->baseY > 200)
                    group->baseY = 180;

                for (i = 0; i < 4; i++)
                {
                    oamSimple = &group->oam[i];
                    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                }
            }

            group = &gMain.spriteGroups[12];
            if (group->available)
            {
                group->baseX = gCurrentPinballGame->unk3C4[1].x / 10;
                group->baseY = gCurrentPinballGame->unk3C4[1].y / 10;
                if (group->baseY <= -60)
                    group->baseY = -60;
                else
                    gCurrentPinballGame->unk3C4[1].y -= 12;

                if (group->baseY > 200)
                    group->baseY = 180;

                for (i = 0; i < 6; i++)
                {
                    oamSimple = &group->oam[i];
                    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                }
            }

            group = &gMain.spriteGroups[13];
            if (group->available)
            {
                group->baseX = gCurrentPinballGame->unk3C4[2].x / 10;
                group->baseY = gCurrentPinballGame->unk3C4[2].y / 10;
                if (group->baseY <= -60)
                    group->baseY = -60;
                else
                    gCurrentPinballGame->unk3C4[2].y -= 18;

                if (group->baseY > 200)
                    group->baseY = 180;

                for (i = 0; i < 5; i++)
                {
                    oamSimple = &group->oam[i];
                    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                }
            }

            if (gCurrentPinballGame->unk516 == 660)
            {
                gMain.spriteGroups[11].available = 0;
                gMain.spriteGroups[12].available = 0;
                gMain.spriteGroups[13].available = 0;
            }

            group = &gMain.spriteGroups[14];
            if (group->available)
            {
                if (gCurrentPinballGame->unk516 >= 195 && gCurrentPinballGame->unk516 < 205)
                    var0 = gUnknown_086AF784[(gCurrentPinballGame->unk516 - 195) / 2];
                else
                    var0 = (gCurrentPinballGame->unk516 % 4) / 2;

                group->baseX = gCurrentPinballGame->unk418.x / 10;
                group->baseY = gCurrentPinballGame->unk418.y / 10;

                if (group->baseY < -60)
                    group->baseY = -60;
                if (group->baseY > 180)
                    group->baseY = 180;

                oamSimple = &group->oam[0];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum = 0x7D + var0 * 4;
            }

            if (gCurrentPinballGame->unk516 == 150)
            {
                gMain.spriteGroups[14].available = 1;
                gCurrentPinballGame->unk418.x = 1600;
                gCurrentPinballGame->unk418.y = -100;
                gCurrentPinballGame->unk414.x = -21;
                gCurrentPinballGame->unk414.y = 14;
            }

            if (gCurrentPinballGame->unk516 > 205)
            {
                gCurrentPinballGame->unk414.y++;
                gCurrentPinballGame->unk418.x += gCurrentPinballGame->unk414.x;
                gCurrentPinballGame->unk418.y += gCurrentPinballGame->unk414.y;
            }
            else if (gCurrentPinballGame->unk516 > 150)
            {
                gCurrentPinballGame->unk418.x += gCurrentPinballGame->unk414.x;
                gCurrentPinballGame->unk418.y += gCurrentPinballGame->unk414.y;
            }

            if (gCurrentPinballGame->unk516 == 350)
                gMain.spriteGroups[14].available = 0;
        }
    }

    if (gCurrentPinballGame->unk506 == 2)
    {
        if (gCurrentPinballGame->unk516 < 256)
        {
            gCurrentPinballGame->unkE6 = gCurrentPinballGame->unk516 / -2;
            gCurrentPinballGame->unk516++;
        }

        group = &gMain.spriteGroups[11];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->unk3C4[0].x / 10;
            group->baseY = gCurrentPinballGame->unk3C4[0].y / 10;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (gCurrentPinballGame->unk516 < 256)
                gCurrentPinballGame->unk3C4[0].y += 20;

            if (group->baseY < -60)
                group->baseY = -60;

            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        group = &gMain.spriteGroups[12];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->unk3C4[1].x / 10;
            group->baseY = gCurrentPinballGame->unk3C4[1].y / 10;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (gCurrentPinballGame->unk516 < 256)
                gCurrentPinballGame->unk3C4[1].y += 10;

            if (group->baseY < -60)
                group->baseY = -60;

            for (i = 0; i < 6; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        group = &gMain.spriteGroups[14];
        if (group->available)
        {
            if (gCurrentPinballGame->unk516 >= 190 && gCurrentPinballGame->unk516 < 200)
                var0 = gUnknown_086AF784[(gCurrentPinballGame->unk516 - 190) / 2];
            else
                var0 = (gCurrentPinballGame->unk516 % 4) / 2;

            group->baseX = gCurrentPinballGame->unk418.x / 10;
            group->baseY = gCurrentPinballGame->unk418.y / 10;

            if (group->baseY < -60)
                group->baseY = -60;
            if (group->baseY > 180)
                group->baseY = 180;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0x7D + var0 * 4;

            if (gCurrentPinballGame->unk516 > 160)
            {
                gCurrentPinballGame->unk418.x += gCurrentPinballGame->unk414.x;
                gCurrentPinballGame->unk418.y += gCurrentPinballGame->unk414.y;
            }
        }
    }

    if (gCurrentPinballGame->unkE6 >= -0x20)
        gCurrentPinballGame->unk1A = 0;
    else
        gCurrentPinballGame->unk1A = 1;

    gMain.bgOffsets[2].yOffset += gCurrentPinballGame->unk518;
    gMain.bgOffsets[1].yOffset += gCurrentPinballGame->unk518;
    gMain.bgOffsets[3].yOffset += gCurrentPinballGame->unk518 / 4 + 224;
}

