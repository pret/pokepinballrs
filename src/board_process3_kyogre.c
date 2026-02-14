#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gKyogreBonusClear_Gfx[];
extern const u8 gUnknown_081B0DE4[][0x20];
extern const u16 gUnknown_08333004[];
extern const u8 gUnknown_0833FF58[][0x20];
extern const u8 gUnknown_083529D8[][0x20];
extern const u8 gUnknown_083C13AC[][0xC0];
extern const u8 gUnknown_083C1A6C[][0x3C0];
extern const u8 gUnknown_0849664C[][0x580];
extern const u8 gUnknown_0849B8CC[][0x4C0];
extern const u8 gUnknown_084FF90C[][0x200];
extern struct SongHeader se_unk_10a;
extern struct SongHeader se_unk_10b;
extern struct SongHeader se_unk_10c;
extern struct SongHeader se_unk_10d;
extern struct SongHeader se_unk_10e;
extern struct SongHeader se_unk_10f;
extern const u8 *gUnknown_086AEAE0[];
extern const u16 gUnknown_086AEAF8[][3];
extern const s16 gUnknown_086AEDA4[];
extern const s16 gUnknown_086AEDCC[];
extern const struct Vector16 gUnknown_086AEDE8[];
extern const s16 gUnknown_086AEE20[];
extern const s16 gUnknown_086AEE5E[][3];
extern const s16 gUnknown_086AEED6[];
extern const s16 gUnknown_086AEEDE[];
extern const s16 gUnknown_086AEEE6[];
extern const u16 gUnknown_086AEEFE[];
extern const s16 gUnknown_086AEF04[];
extern const u16 gUnknown_086B91AC[28][4][3];
extern const u16 gUnknown_086B92FC[66][10][3];


void KyogreBoardProcess_3A_383E4(void)
{
    s16 i;

    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    gCurrentPinballGame->unk294 = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        gCurrentPinballGame->unk384 = 18;
    else
        gCurrentPinballGame->unk384 = 15;

    gCurrentPinballGame->unk390 = 0;
    gCurrentPinballGame->unk389 = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk382 = 0;
    gCurrentPinballGame->unk388 = 3;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unk386 = 0;
    gCurrentPinballGame->unk394 = 0;
    gCurrentPinballGame->unk38E = 0;
    gCurrentPinballGame->unk385 = 0;
    gCurrentPinballGame->unk387 = 0;
    gCurrentPinballGame->unk6C4 = 3;
    gCurrentPinballGame->unk3DF = 14;
    gCurrentPinballGame->unk3DC = 0;
    gCurrentPinballGame->unk3E8 = 0;
    gCurrentPinballGame->unk3EA = 0;
    gCurrentPinballGame->unk3DE = 0;
    gCurrentPinballGame->unk3E0 = 0;
    gCurrentPinballGame->unk3E2 = 0;
    gCurrentPinballGame->unk3E4 = 0;
    gCurrentPinballGame->unk440 = 0;
    gCurrentPinballGame->unk445 = 0;
    gCurrentPinballGame->unk446 = 0;
    gCurrentPinballGame->unk447 = 0;
    gCurrentPinballGame->unk448 = 0;
    gCurrentPinballGame->unk449 = 0;
    gCurrentPinballGame->unk44A = 0;
    gCurrentPinballGame->unk44E = 0;
    gCurrentPinballGame->unk452 = 0;
    gCurrentPinballGame->unk454 = 0;
    gCurrentPinballGame->unk456 = 0;
    gCurrentPinballGame->unk450 = 0;

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

    for (i = 0; i < 4; i ++)
    {
        gCurrentPinballGame->unk46C[i].x = 0;
        gCurrentPinballGame->unk46C[i].y = 0;
    }

    gCurrentPinballGame->unk1A = 1;
    sub_38A20();
    sub_395D8();
    sub_39A40();
    sub_3AE14();
    m4aSongNumStart(MUS_BONUS_FIELD_KYOGRE);
    DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
    DmaCopy16(3, &gUnknown_086AEAE0[0][0], (void *)0x05000000, 0x100);
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void KyogreBoardProcess_3B_3869C(void)
{
    switch (gCurrentPinballGame->unk13)
    {
    case 0:
        gCurrentPinballGame->unk5F7 = 1;
        if (gCurrentPinballGame->unk18 < 500)
        {
            gCurrentPinballGame->unkE6 = -64;
            gCurrentPinballGame->unk18++;
        }
        else if (gCurrentPinballGame->unk18 < 820)
        {
            gCurrentPinballGame->unkE6 = (gCurrentPinballGame->unk18 - 500) / 5 - 64;
            gCurrentPinballGame->unk382 = (gCurrentPinballGame->unk18 - 500) / 24;
            if (gCurrentPinballGame->unk382 > 5)
                gCurrentPinballGame->unk382 = 5;

            gCurrentPinballGame->unk18++;
            DmaCopy16(3, &gUnknown_086AEAE0[gCurrentPinballGame->unk382][0], (void *)0x05000000, 0x60);
            DmaCopy16(3, &gUnknown_086AEAE0[gCurrentPinballGame->unk382][0x80], (void *)0x05000080, 0x80);
            if (gCurrentPinballGame->unkE6 >= -32)
                gCurrentPinballGame->unk1A = 0;
        } else
        {
            gCurrentPinballGame->unkE6 = 0;
            gCurrentPinballGame->unk13 = 1;
            gCurrentPinballGame->unk18 = 0;
        }
        break;
    case 2:
        if (gCurrentPinballGame->unk18 < 120)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk13 = 3;
            gCurrentPinballGame->unk18 = 0;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[5].available = 1;
            DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x06015800, 0x2000);
            gCurrentPinballGame->unk394 = 136;
            gMain.unkF = 0x80;
            gCurrentPinballGame->unk5FA = 1;
        }
        break;
    case 3:
        sub_351A8();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = 50000000;
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
        DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
            gCurrentPinballGame->scoreAddedInFrame = 50000000;
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
        }
        break;
    case 6:
        sub_351A8();
        gCurrentPinballGame->unk386 = 1;
        gCurrentPinballGame->unk5FA = 1;
    }

    sub_39A40();
    sub_38A20();
    sub_395D8();
    sub_3AE14();
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

void sub_38A20(void)
{
    s16 i;
    s16 index;

    if (gCurrentPinballGame->unk452)
    {
        gCurrentPinballGame->unk452--;
        if (gCurrentPinballGame->unk3DC != 8)
        {
            gCurrentPinballGame->unk389 = 1;
            if (gCurrentPinballGame->unk452 == 4)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10a);
                sub_11B0(7);
                gCurrentPinballGame->scoreAddedInFrame = 500000;
                gCurrentPinballGame->unk385++;
                if (gCurrentPinballGame->unk385 >= gCurrentPinballGame->unk384 && gCurrentPinballGame->unk387 == 1)
                    gCurrentPinballGame->unk3DC = 7;
            }
        }

        if (gCurrentPinballGame->unk452 == 0)
            gCurrentPinballGame->unk389 = 0;
    }

    switch (gCurrentPinballGame->unk3DC)
    {
    case 0:
        gCurrentPinballGame->unk3DC = 1;
        gCurrentPinballGame->unk3E2 = 12;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3E8 = 0;
        gCurrentPinballGame->unk3EA = 0;
        gCurrentPinballGame->unk450 = 0;
        break;
    case 1:
        index = gUnknown_086AEDA4[(gCurrentPinballGame->unk450 % 280) / 14];
        DmaCopy16(3, gUnknown_081B0DE4[index], (void *)0x050003E0, 0x20);
        gCurrentPinballGame->unk450++;
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 34)
            {
                gCurrentPinballGame->unk3E2 = 0;
                gCurrentPinballGame->unk3DC = 4;
                gCurrentPinballGame->unk3DD = 6;
                gCurrentPinballGame->unk3E1 = 0;
                gCurrentPinballGame->unk390 = 60;
                DmaCopy16(3, &gUnknown_081B0DE4[5], (void *)0x050003E0, 0x20);
            }

            if (gCurrentPinballGame->unk3E2 == 32)
                gCurrentPinballGame->unk294 = 1;

            if (gCurrentPinballGame->unk3E2 == 33)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
                gCurrentPinballGame->unk387 = 1;
            }
        }

        if (gCurrentPinballGame->unk392 > 2)
            gCurrentPinballGame->unk392--;
        break;
    case 2:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 12)
            {
                gCurrentPinballGame->unk3E2 = 0;
                gCurrentPinballGame->unk3DC = 4;
                gCurrentPinballGame->unk3DD = 6;
                gCurrentPinballGame->unk3E1 = 2;
            }

            if (gCurrentPinballGame->unk3E2 == 11)
            {
                gCurrentPinballGame->unk387 = 1;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
            }
        }
        break;
    case 3:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 8)
            {
                gCurrentPinballGame->unk3E2 = 8;
                gCurrentPinballGame->unk3DC = 11;
                gCurrentPinballGame->unk3E1 = 0;
            }

            if (gCurrentPinballGame->unk3E2 == 5)
            {
                gCurrentPinballGame->unk387 = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10c);
            }
        }
        break;
    case 4:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 4)
            {
                if (gCurrentPinballGame->unk3E1 < 3)
                {
                    gCurrentPinballGame->unk3E2 = 0;
                    gCurrentPinballGame->unk3E1++;
                }
                else
                {
                    if (gCurrentPinballGame->unk3DD == 3)
                    {
                        if (gCurrentPinballGame->unk385 >= gCurrentPinballGame->unk384)
                        {
                            gCurrentPinballGame->unk3E2 = 0;
                            gCurrentPinballGame->unk3DC = 4;
                            gCurrentPinballGame->unk3E1 = 0;
                            gCurrentPinballGame->unk3DD = 6;
                        }
                        else
                        {
                            gCurrentPinballGame->unk3E2 = 4;
                            gCurrentPinballGame->unk3DC = gCurrentPinballGame->unk3DD;
                        }
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E2 = 34;
                        gCurrentPinballGame->unk3DC = gCurrentPinballGame->unk3DD;
                        gCurrentPinballGame->unk440 = 0;
                        gCurrentPinballGame->unk3E1 = 0;
                    }
                }
            }
        }
        break;
    case 5:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 67)
            {
                if (gCurrentPinballGame->unk3E1 <= 0)
                {
                    gCurrentPinballGame->unk3E2 = 45;
                    gCurrentPinballGame->unk3E1++;
                }
                else
                {
                    gCurrentPinballGame->unk3E2 = 0;
                    gCurrentPinballGame->unk3DC = 4;
                    gCurrentPinballGame->unk3E1 = 1;
                    gCurrentPinballGame->unk3DD = 3;
                }
            }

            if (gCurrentPinballGame->unk3E2 == 52)
            {
                gCurrentPinballGame->unk458[gCurrentPinballGame->unk3E1] = 0;
                gCurrentPinballGame->unk441[gCurrentPinballGame->unk3E1] = 1;
            }

            if (gCurrentPinballGame->unk3E2 == 50 || gCurrentPinballGame->unk3E2 == 56 || gCurrentPinballGame->unk3E2 == 62)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10d);
        }
        break;
    case 6:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 40)
            {
                if (gCurrentPinballGame->unk3E1 <= 0)
                {
                    gCurrentPinballGame->unk3E2 = 34;
                    gCurrentPinballGame->unk3E1++;
                }
            }

            if (gCurrentPinballGame->unk3E2 == 45)
            {
                gCurrentPinballGame->unk3E2 = 45;
                gCurrentPinballGame->unk3DC = 5;
                gCurrentPinballGame->unk3E1 = 0;
            }

            if (gCurrentPinballGame->unk440 == 0 && gCurrentPinballGame->unk3E2 == 42)
            {
                gMain.spriteGroups[24].available = 1;
                gCurrentPinballGame->unk456 = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10e);
            }
        }

        if (gCurrentPinballGame->unk452 > 6)
            gCurrentPinballGame->unk440 = 1;
        break;
    case 7:
        gCurrentPinballGame->unk294 = 3;
        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            gCurrentPinballGame->unk3DC = 10;
            gCurrentPinballGame->unk3E2 = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_KYOGRE;
            gCurrentPinballGame->unk38E = 0;
            gCurrentPinballGame->unk5A8 = 0;
            gCurrentPinballGame->unk5A6 = 0;
            gCurrentPinballGame->unk5A4 = 2;
        }
        else
        {
            gCurrentPinballGame->unk3DC = 9;
            gCurrentPinballGame->unk3E2 = 79;
            gMain.unkF = 0x80;
            gCurrentPinballGame->unk388 = 2;
            gCurrentPinballGame->unk392 = 0;
        }

        if (gMain.spriteGroups[16].available)
        {
            gCurrentPinballGame->unk445 = 7;
            gCurrentPinballGame->unk44E = 1;
        }

        gCurrentPinballGame->unk3E4 = 0;
        break;
    case 8:
        break;
    case 9:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 108)
            {
                gCurrentPinballGame->unk3E2 = 107;
                gCurrentPinballGame->unk3DC = 13;
                gCurrentPinballGame->unk13 = 2;
                gCurrentPinballGame->unk18 = 0;
            }

            if (gCurrentPinballGame->unk3E2 == 97)
            {
                gCurrentPinballGame->unk387 = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10f);
            }
        }
        break;
    case 10:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 4)
                gCurrentPinballGame->unk3E2 = 0;
        }

        if (gCurrentPinballGame->unk38E > -500)
        {
            gCurrentPinballGame->unk38E += (-500 - gCurrentPinballGame->unk38E) / 30;
            gCurrentPinballGame->unkE6 = gCurrentPinballGame->unk38E / 10;
            if (gCurrentPinballGame->unkE6 < -50)
                gCurrentPinballGame->unkE6 = -50;
        }

        if (gCurrentPinballGame->unk5A8 == 21)
            gCurrentPinballGame->unk3E2 = 114;

        if (gCurrentPinballGame->unk5A8 == 22)
            gCurrentPinballGame->unk3E2 = 115;
        break;
    case 11:
        if (gCurrentPinballGame->unk3E4 < 300)
        {
            gCurrentPinballGame->unk3E4++;
            if (gCurrentPinballGame->unk3E4 == 218)
            {
                gCurrentPinballGame->unk456 = 0;
                gCurrentPinballGame->unk3E8 = 500 - (Random() % 100) * 10;
                gCurrentPinballGame->unk3EA = 200 + (Random() % 100) * 4;
            }

            if (gCurrentPinballGame->unk3E4 == 260)
            {
                for (i = 0; i < 2; i++)
                {
                    if (gCurrentPinballGame->unk441[i] == 3)
                    {
                        gCurrentPinballGame->unk458[i] = 0;
                        gCurrentPinballGame->unk441[i] = 4;
                        gCurrentPinballGame->unk5AC /= 2;
                    }

                    if (gCurrentPinballGame->unk441[i] == 2)
                    {
                        gCurrentPinballGame->unk458[i] = 0;
                        gCurrentPinballGame->unk441[i] = 5;
                    }
                }
            }
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2 = 67;
            gCurrentPinballGame->unk3DC = 12;
            gCurrentPinballGame->unk387 = 2;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
            sub_11B0(8);
        }
        break;
    case 12:
        if (gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 79)
            {
                if (gCurrentPinballGame->unk3E1 <= 0)
                {
                    gCurrentPinballGame->unk3E2 = 78;
                    gCurrentPinballGame->unk3DC = 11;
                    gCurrentPinballGame->unk3E1++;
                }
                else
                {
                    gCurrentPinballGame->unk3E1 = 0;
                    gCurrentPinballGame->unk3E2 = 8;
                    gCurrentPinballGame->unk3DC = 2;
                    gCurrentPinballGame->unk3E8 = 0;
                    gCurrentPinballGame->unk3EA = 0;
                }
            }

            if (gCurrentPinballGame->unk3E2 == 70)
                gCurrentPinballGame->unk387 = 3;

            if (gCurrentPinballGame->unk3E2 == 73)
                gCurrentPinballGame->unk387 = 0;

            if (gCurrentPinballGame->unk3E2 == 72)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10c);
                sub_11B0(8);
            }
        }
        break;
    case 13:
        break;
    }

    if (gCurrentPinballGame->unk390)
    {
        gCurrentPinballGame->unk390--;
        if (gCurrentPinballGame->unk390 == 20)
            PlayCry_Normal(gSpeciesInfo[SPECIES_KYOGRE].mainSeriesIndexNumber, 0);

        if (gCurrentPinballGame->unk390 == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void sub_395D8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var2;
    s16 index;
    s16 palette;

    group = &gMain.spriteGroups[21];
    if (group->available)
    {
        index = gCurrentPinballGame->unk3DF;
        gCurrentPinballGame->unk3DF = gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][2];
        var2 = gUnknown_086AEAF8[gCurrentPinballGame->unk3E2][0];
        if (index < 15)
        {
            DmaCopy16(3, gUnknown_0849664C[index], (void *)0x06010FA0, 0x580);
        }
        else
        {
            index -= 15;
            DmaCopy16(3, gUnknown_0849B8CC[index], (void *)0x06010FA0, 0x4C0);
        }

        group->baseX = gCurrentPinballGame->unk3E8 / 10 + 72u - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk3EA / 10 + 66u - gCurrentPinballGame->unk5A;
        gCurrentPinballGame->unk288 = gCurrentPinballGame->unk3E8 / 10 + 120;
        gCurrentPinballGame->unk28A = gCurrentPinballGame->unk3EA / 10 + 50;
        if (gCurrentPinballGame->unk387 == 2)
        {
            gCurrentPinballGame->unk3F0 = (gCurrentPinballGame->unk3E8 / 10) * 2 + 192;
            gCurrentPinballGame->unk3F2 = (gCurrentPinballGame->unk3EA / 10) * 2 + 134;
        }
        else if (gCurrentPinballGame->unk387 == 3)
        {
            gCurrentPinballGame->unk3F0 = (gCurrentPinballGame->unk3E8 / 10) * 2 + 192;
            gCurrentPinballGame->unk3F2 = (gCurrentPinballGame->unk3EA / 10) * 2 + 150;
        }
        else
        {
            gCurrentPinballGame->unk3F0 = (gCurrentPinballGame->unk3E8 / 10) * 2 + 180;
            gCurrentPinballGame->unk3F2 = (gCurrentPinballGame->unk3EA / 10) * 2 + 116;
        }

        if (gCurrentPinballGame->unk389 > 9)
        {
            palette = 11;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else
        {
            if (gCurrentPinballGame->unk389 == 1)
                palette = 14;
            else if (gCurrentPinballGame->unk389 == 3)
                palette = 11;
            else if (var2 == 20)
                palette = 4;
            else if (var2 == 21)
                palette = 3;
            else
                palette = 15;

            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B92FC[var2][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
    }

    group = &gMain.spriteGroups[26];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk3E8 / 10 + 108 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk3EA / 10 +  82 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        index = gUnknown_086AEDCC[(gCurrentPinballGame->unk456 % 84) / 6];
        DmaCopy16(3, gUnknown_083C13AC[index], (void *)0x06012420, 0xC0);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->unk456 < 83)
        {
            gCurrentPinballGame->unk456++;
        }
        else
        {
            gCurrentPinballGame->unk456 = 0;
            gMain.spriteGroups[26].available = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk3DC == 11 && gCurrentPinballGame->unk3E4 == 218)
            group->available = 1;
    }
}

void sub_39A40(void)
{
    s16 i, j;
    s16 var4;
    int var5;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    int xx, yy;
    u16 angle;
    int squaredMagnitude;
    struct Vector32 tempVector2;
    struct Vector32 tempVector;
    struct Vector32 tempVector3;

    index = 0;
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

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
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

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->unk6DB;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[16];
    if (group->available)
    {
        switch (gCurrentPinballGame->unk445)
        {
        case 0:
            gCurrentPinballGame->unk449 = 0;
            gCurrentPinballGame->unk446 = 5;
            gCurrentPinballGame->unk447 = 1;
            gCurrentPinballGame->unk44A = 0;
            gCurrentPinballGame->unk44E = 0;
            if (gCurrentPinballGame->unk448 == 2)
            {
                int a; // force addition of 8 instead of offsetting the global constant
                DmaCopy16(3, &gUnknown_08137E14[a = gCurrentPinballGame->ballUpgradeType + 8], (void *)0x05000220, 0x20);
            }
            break;
        case 1:
            gCurrentPinballGame->unk44A = 4;
            gCurrentPinballGame->unk44E = 90;
            gCurrentPinballGame->unk445 = 2;
            break;
        case 2:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->unk44E -= 90;
                if (gCurrentPinballGame->unk44E < 0)
                    gCurrentPinballGame->unk44E = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->unk449 = 5;
            gCurrentPinballGame->unk446 = 9;
            gCurrentPinballGame->unk447 = 3;
            break;
        case 3:
            gCurrentPinballGame->unk44A = 4;
            gCurrentPinballGame->unk44E = 90;
            gCurrentPinballGame->unk445 = 4;
            break;
        case 4:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->unk44E -= 90;
                if (gCurrentPinballGame->unk44E < 0)
                    gCurrentPinballGame->unk44E = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->unk449 = 9;
            gCurrentPinballGame->unk446 = 13;
            gCurrentPinballGame->unk447 = 5;
            break;
        case 5:
            gCurrentPinballGame->unk44A = 0;
            gCurrentPinballGame->unk44E = 90;
            gCurrentPinballGame->unk445 = 6;
            break;
        case 6:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->unk44E -= 90;
                if (gCurrentPinballGame->unk44E < 0)
                    gCurrentPinballGame->unk44E = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->unk449 = 13;
            gCurrentPinballGame->unk446 = 19;
            gCurrentPinballGame->unk447 = 7;
            break;
        case 7:
            gMain.spriteGroups[16].available = 0;
            break;
        }

        if (gCurrentPinballGame->unk44E > 0)
        {
            gCurrentPinballGame->unk44E--;
            if (gCurrentPinballGame->unk44E == 0)
                m4aSongNumStart(SE_UNKNOWN_0x111);
        }
        else
        {
            if (gUnknown_086AEE5E[gCurrentPinballGame->unk448][1] > gCurrentPinballGame->unk454)
            {
                gCurrentPinballGame->unk454++;
            }
            else
            {
                gCurrentPinballGame->unk454 = 0;
                gCurrentPinballGame->unk448++;
                if (gCurrentPinballGame->unk448 == gCurrentPinballGame->unk446)
                {
                    if (gCurrentPinballGame->unk44A > 0)
                    {
                        gCurrentPinballGame->unk448 = gCurrentPinballGame->unk449;
                        gCurrentPinballGame->unk44A--;
                    }
                    else
                    {
                        gCurrentPinballGame->unk448 = gCurrentPinballGame->unk446 - 1;
                        gCurrentPinballGame->unk445 = gCurrentPinballGame->unk447;
                    }

                    gCurrentPinballGame->unk44E = 90;
                }

                if (gCurrentPinballGame->unk448 == 1)
                    m4aSongNumStart(SE_UNKNOWN_0x110);

                if (gCurrentPinballGame->unk448 == 15)
                {
                    DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
                    m4aSongNumStart(SE_UNKNOWN_0x112);
                }
            }
        }

        if (gCurrentPinballGame->unk448 < 18)
        {
            gCurrentPinballGame->unk383 = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->unk6 = 0;
        }
        else
        {
            gCurrentPinballGame->unk383 = 0;
        }

        group->baseX = gCurrentPinballGame->ball->screenPosition.x;
        group->baseY = gCurrentPinballGame->ball->screenPosition.y;
        if (group->baseY >= 200)
            group->baseY = 200;

        index = gUnknown_086AEE5E[gCurrentPinballGame->unk448][2];
        DmaCopy16(3, gUnknown_083C1A6C[index], (void *)0x060124E0, 0x3C0);
        var0 = gUnknown_086AEE5E[gCurrentPinballGame->unk448][0];
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B91AC[var0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[22 + i];
        if ((gMain.unkF & 0x80) == 0)
        {
            switch (gCurrentPinballGame->unk441[i]) {
            case 0:
                index = 0;
                gCurrentPinballGame->unk45C[i].x = 0;
                gCurrentPinballGame->unk45C[i].y = 0;
                break;
            case 1:
                index = gCurrentPinballGame->unk458[i] / 9;
                if (gCurrentPinballGame->unk458[i] < 98)
                {
                    gCurrentPinballGame->unk458[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk458[i] = 0;
                    gCurrentPinballGame->unk441[i] = 2;
                    gCurrentPinballGame->unk443[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->unk464[i].x = gUnknown_086AEDE8[gCurrentPinballGame->unk443[i]].x;
                    gCurrentPinballGame->unk464[i].y = gUnknown_086AEDE8[gCurrentPinballGame->unk443[i]].y;
                }

                gCurrentPinballGame->unk45C[i].x = 0;
                gCurrentPinballGame->unk45C[i].y = 0;
                break;
            case 2:
                index = ((gCurrentPinballGame->unk458[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->unk441[0] < 3 && gCurrentPinballGame->unk441[1] < 3)
                {
                    int xoff = 120;
                    int yoff = 144;
                    tempVector.x = (gCurrentPinballGame->ball->positionQ0.x - xoff) - (gCurrentPinballGame->unk45C[i].x / 10);
                    tempVector.y = (gCurrentPinballGame->ball->positionQ0.y - yoff) - (gCurrentPinballGame->unk45C[i].y / 10);
                    xx = tempVector.x * tempVector.x;
                    yy = tempVector.y * tempVector.y;
                    squaredMagnitude = xx + yy;
                    if (gCurrentPinballGame->unk383 == 0 && gCurrentPinballGame->unk388 == 0 &&
                        gCurrentPinballGame->unk385 < gCurrentPinballGame->unk384 &&
                        gCurrentPinballGame->unk452 == 0 && squaredMagnitude < 400)
                    {
                        m4aSongNumStart(SE_UNKNOWN_0x113);
                        sub_11B0(12);
                        gCurrentPinballGame->unk1F = 1;
                        gCurrentPinballGame->unk458[i] = 0;
                        gCurrentPinballGame->unk441[i] = 3;
                        gCurrentPinballGame->unk5FA = 1;
                        tempVector2.x = gCurrentPinballGame->unk45C[i].x / 10 + 120;
                        tempVector2.y = gCurrentPinballGame->unk45C[i].y / 10 + 144;
                        tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                        tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                        gCurrentPinballGame->unk5AC = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                        gCurrentPinballGame->unk5AC = Sqrt(gCurrentPinballGame->unk5AC * 4) / 2;
                        gCurrentPinballGame->unk5B0 = ArcTan2(-tempVector.x, tempVector.y);
                    }
                }

                if (gCurrentPinballGame->unk458[i] < 900)
                {
                    gCurrentPinballGame->unk458[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk458[i] = 0;
                    gCurrentPinballGame->unk441[i] = 5;
                }
                break;
            case 3:
                index = ((gCurrentPinballGame->unk458[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
                    gCurrentPinballGame->unk458[i] += 8;

                var4 = 29 - gCurrentPinballGame->unk458[i];
                if (var4 < 10)
                    var4 = 10;

                gCurrentPinballGame->unk5B0 -= ((0x2000 - (var4 * 0x2000) / 30) * 2) / 5;
                gCurrentPinballGame->ball->unkA -= 0x2000;
                var5 = (gCurrentPinballGame->unk5AC * var4) / 30;
                tempVector2.x = gCurrentPinballGame->unk45C[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->unk45C[i].y / 10 + 144;
                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->unk5B0) * var5) / 20000);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->unk5B0) * var5) / 20000);
                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->unk458[i] < 480)
                {
                    gCurrentPinballGame->unk458[i]++;
                    if (gCurrentPinballGame->unk458[i] % 9 == 0)
                        sub_11B0(12);
                }
                else
                {
                    gCurrentPinballGame->unk458[i] = 0;
                    gCurrentPinballGame->unk441[i] = 4;
                    gCurrentPinballGame->unk5AC /= 2;
                }
                break;
            case 4:
                index = 5 - gCurrentPinballGame->unk458[i] / 8;
                var4 = 47 - gCurrentPinballGame->unk458[i];
                gCurrentPinballGame->unk5B0 -= ((0x2000 - (var4 * 0x1000) / 47) * 2) / 5;
                gCurrentPinballGame->ball->unkA -= 0x2000;
                var5 = (gCurrentPinballGame->unk5AC * var4) / 47;
                tempVector2.x = gCurrentPinballGame->unk45C[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->unk45C[i].y / 10 + 144;
                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->unk5B0) * var5) / 20000);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->unk5B0) * var5) / 20000);
                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->unk458[i] < 47)
                {
                    gCurrentPinballGame->unk458[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk458[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = -150 + (gMain.systemFrameCount % 2) * 300;
                    gCurrentPinballGame->ball->velocity.y = 300;
                    gCurrentPinballGame->unk1F = 0;
                    gCurrentPinballGame->unk441[i] = 0;
                    gCurrentPinballGame->unk5FA = 0;
                }
                break;
            case 5:
                index = 5 - gCurrentPinballGame->unk458[i] / 6;
                if (gCurrentPinballGame->unk458[i] < 36)
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

            if (gCurrentPinballGame->unk441[i] >= 2 && gCurrentPinballGame->unk441[i] < 4)
            {
                tempVector.x = gCurrentPinballGame->unk464[i].x - gCurrentPinballGame->unk45C[i].x;
                tempVector.y = gCurrentPinballGame->unk464[i].y - gCurrentPinballGame->unk45C[i].y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;
                angle = ArcTan2(tempVector.x, -tempVector.y);
                tempVector3.x =  (Cos(angle) * 4) / 20000;
                tempVector3.y = -(Sin(angle) * 4) / 20000;
                gCurrentPinballGame->unk45C[i].x += tempVector3.x;
                gCurrentPinballGame->unk45C[i].y += tempVector3.y;
                if (squaredMagnitude < 2500)
                {
                    gCurrentPinballGame->unk443[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->unk464[i].x = gUnknown_086AEDE8[gCurrentPinballGame->unk443[i]].x;
                    gCurrentPinballGame->unk464[i].y = gUnknown_086AEDE8[gCurrentPinballGame->unk443[i]].y;
                }
            }
        }

        DmaCopy16(3, gUnknown_084FF90C[index], (void *)0x06011520 + i * 0x200, 0x200);
        if (group->available)
        {
            if (gCurrentPinballGame->unk441[i] > 0)
            {
                group->baseX = gCurrentPinballGame->unk45C[i].x / 10 - (gCurrentPinballGame->unk58 - 104u);
                group->baseY = gCurrentPinballGame->unk45C[i].y / 10 - (gCurrentPinballGame->unk5A - 128u);
            }
            else
            {
                group->baseX = 240;
                group->baseY = 180;
            }

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        s16 scale;
        s16 var6;

        if (gCurrentPinballGame->unk456 < 36)
        {
            scale = (gCurrentPinballGame->unk456 * 0x200) / 35 + 0x10;
            if (scale > 0x200)
                scale = 0x200;

            SetMatrixScale(scale, scale, 1);
            SetMatrixScale(-scale, scale, 2);
            SetMatrixScale(scale, -scale, 3);
            SetMatrixScale(-scale, -scale, 4);
            if (gCurrentPinballGame->unk456 > 30)
                var6 = 12 - ((gCurrentPinballGame->unk456 - 30) * 11) / 5;
            else
                var6 = 16 - (gCurrentPinballGame->unk456 * 4) / 30;

            gCurrentPinballGame->unk456++;
        }
        else
        {
            scale = 0x100;
            var6 = 0;
            group->available = 0;
        }

        gCurrentPinballGame->unk46C[0].x = 0x20 - scale / 8;
        gCurrentPinballGame->unk46C[1].x = 0x20 + scale / 8;
        gCurrentPinballGame->unk46C[2].x = 0x20 - scale / 8;
        gCurrentPinballGame->unk46C[3].x = 0x20 + scale / 8;
        gCurrentPinballGame->unk46C[0].y = 0x20 - scale / 8;
        gCurrentPinballGame->unk46C[1].y = 0x20 - scale / 8;
        gCurrentPinballGame->unk46C[2].y = 0x20 + scale / 8;
        gCurrentPinballGame->unk46C[3].y = 0x20 + scale / 8;

        if ((gMain.unkF & 0xC0) == 0)
        {
            gMain.blendControl = 0x1E10;
            gMain.blendAlpha = BLDALPHA_BLEND(var6, 16 - var6);
        }

        if (group->available)
        {
            group->baseX = 23 - gCurrentPinballGame->unk58;
            group->baseY = 30 - gCurrentPinballGame->unk5A;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gCurrentPinballGame->unk46C[i].x;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gCurrentPinballGame->unk46C[i].y;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 1 + i;
            }
        }

        if (gCurrentPinballGame->unk456 < 30)
        {
            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - 119;
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - 127;
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (gCurrentPinballGame->unk388 == 0 && squaredMagnitude < gUnknown_086AEE20[gCurrentPinballGame->unk456])
            {
                gCurrentPinballGame->unk445 = 0;
                gCurrentPinballGame->unk448 = 0;
                gCurrentPinballGame->unk454 = 0;
                if (!gMain.spriteGroups[16].available)
                    sub_11B0(8);

                gMain.spriteGroups[16].available = 1;
            }
        }

        if (gMain.unkF & 0xC0)
            gMain.spriteGroups[24].available = 0;
    }
}

void sub_3ADA0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        group->baseX = 240;
        group->baseY = 160;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_3AE14(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    s16 index;

    if (gCurrentPinballGame->unk13 == 0 && gCurrentPinballGame->unk18 < 600)
    {
        index = gUnknown_086AEF04[(gCurrentPinballGame->unk18 % 240) / 24];
        DmaCopy16(3, gUnknown_083529D8[index], (void *)0x05000340, 0x20);
        DmaCopy16(3, gUnknown_0833FF58[index], (void *)0x050002A0, 0x20);
        var0 = 2;
        index = 0;
        gCurrentPinballGame->unk44C = index;
    }
    else
    {
        var0 = gUnknown_086AEEE6[(gCurrentPinballGame->unk44C % 96) / 24];
        gCurrentPinballGame->unk44C++;
    }

    index = gUnknown_086AEED6[(gCurrentPinballGame->unk290 % 96) / 24];
    for (i = 0; i < 0x400; i++)
        gUnknown_03005C00[0x800 + i] = gUnknown_08333004[i] + index * 4;

    DmaCopy16(3, &gUnknown_03005C00[0x800], (void *)0x06000000, 0x800);
    index = gUnknown_086AEEDE[(gMain.systemFrameCount % 96) / 24];
    DmaCopy16(3, &gUnknown_086AEAE0[gCurrentPinballGame->unk382][index * 0x20], (void *)0x05000060, 0x20);

    for (j = 0; j < 4; j++)
    {
        group = &gMain.spriteGroups[11 + j];
        group->baseX = 120 - gCurrentPinballGame->unk58;
        group->baseY = 128 - gCurrentPinballGame->unk5A;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = gUnknown_086AEEFE[i] + var0 * 8;
        }
    }

    group = &gMain.spriteGroups[15];
    if (group->available)
    {
        group->baseX = 120 - gCurrentPinballGame->unk58;
        group->baseY = 128 - gCurrentPinballGame->unk5A;
        for (i = 0; i < 8; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->unk18 == 480)
            gMain.spriteGroups[15].available = 0;
    }
}
