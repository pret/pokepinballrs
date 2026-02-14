#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"


extern const u8 gGroudonBonusClear_Gfx[];
extern const u8 gUnknown_08352BD8[];
extern const u8 gUnknown_0849F1CC[];
extern const s8 gUnknown_084A11EC[][0x300];
extern struct SongHeader se_unk_118;
extern struct SongHeader se_unk_11b;
extern struct SongHeader se_unk_11c;
extern struct SongHeader se_unk_11d;
extern struct SongHeader se_unk_11f;
extern const s16 gUnknown_086AEE20[];
extern const s16 gUnknown_086AEF28[];
extern const u16 gUnknown_086AEF40[][31];
extern const u16 gUnknown_086AF0B4[];
extern const u16 gUnknown_086AF140[][2];
extern const struct Vector16 gUnknown_086AF2CC[];
extern const u16 gUnknown_086AF2DC[][2];
extern const s16 gUnknown_086AF34C[][3];
extern const s16 gUnknown_086AF3AC[];
extern const s16 gUnknown_086AF3B2[];
extern const s16 gUnknown_086AF3BE[];
extern const u16 gUnknown_086AF3C6[];
extern const u16 gUnknown_086B63AA[12][2][3];
extern const u16 gUnknown_086B63F2[24][4][3];
extern const u16 gUnknown_086B6512[12][6][3];
extern const u16 gUnknown_086B65EA[166][19][3];
extern const u16 gUnknown_086B8AE0[58][10][3];


void GroudonBoardProcess_3A_3B120(void)
{
    s16 i;

    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        gCurrentPinballGame->unk384 = 18;
    else
        gCurrentPinballGame->unk384 = 15;

    gCurrentPinballGame->unk294 = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk388 = 3;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unk386 = 0;
    gCurrentPinballGame->unk387 = 1;
    gCurrentPinballGame->unk6C4 = 3;
    gCurrentPinballGame->unk382 = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk385 = 0;
    gCurrentPinballGame->unk389 = 0;
    gCurrentPinballGame->unk38E = 0;
    gCurrentPinballGame->unk390 = 0;
    gCurrentPinballGame->unk394 = 0;
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
    gCurrentPinballGame->unk452 = 0;
    gCurrentPinballGame->unk456 = 0;
    gCurrentPinballGame->unk47C = 0;
    gCurrentPinballGame->unk47D = 0;
    gCurrentPinballGame->unk47E = 0;
    gCurrentPinballGame->unk47F = 0;
    gCurrentPinballGame->unk480 = 0;
    gCurrentPinballGame->unk482 = 0;
    gCurrentPinballGame->unk484 = 0;
    gCurrentPinballGame->unk486 = 0;
    gCurrentPinballGame->unk488.x = 0;
    gCurrentPinballGame->unk488.y = 0;
    gCurrentPinballGame->unk4C4 = 0;
    gCurrentPinballGame->unk4C6 = 0;
    gCurrentPinballGame->unk4C8 = 0;
    gCurrentPinballGame->unk4CA = 0;
    gCurrentPinballGame->unk4C9 = 0;

    for (i = 0; i < 4; i++)
    {
        gCurrentPinballGame->unk46C[i].x = 0;
        gCurrentPinballGame->unk46C[i].y = 0;
        gCurrentPinballGame->unk48C[i] = 0;
        gCurrentPinballGame->unk490[i] = 0;
        gCurrentPinballGame->unk494[i] = 0;
        gCurrentPinballGame->unk498[i] = 0;
        gCurrentPinballGame->unk49C[i] = 0;
        gCurrentPinballGame->unk4A0[i] = 0;
        gCurrentPinballGame->unk4A4[i] = 0;
        gCurrentPinballGame->unk4AC[i] = 0;
        gCurrentPinballGame->unk4B4[i].x = 0;
        gCurrentPinballGame->unk4B4[i].y = 0;
    }

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->unk4CC[i] = 0;
        gCurrentPinballGame->unk4CF[i] = 0;
        gCurrentPinballGame->unk4D2[i] = 0;
        gCurrentPinballGame->unk4D5[i] = 0;
        gCurrentPinballGame->unk4D8[i] = 0;
        gCurrentPinballGame->unk4DE[i] = 0;
        gCurrentPinballGame->unk4E4[i] = 0;
        gCurrentPinballGame->unk4EC[i].x = 0;
        gCurrentPinballGame->unk4EC[i].y = 0;
        gCurrentPinballGame->unk4F8[i].x = 0;
        gCurrentPinballGame->unk4F8[i].y = 0;
    }

    gCurrentPinballGame->unk1A = 1;
    sub_3CBC4();
    sub_3B7C4();
    sub_3C6E0();
    DmaCopy16(3, gUnknown_0849F1CC, (void *)0x06015800, 0x2000);
    sub_3E644();
    m4aSongNumStart(MUS_BONUS_FIELD_GROUDON);
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void GroudonBoardProcess_3B_3B49C(void)
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
            gCurrentPinballGame->unk18++;;
            if (gCurrentPinballGame->unkE6 >= -32)
                gCurrentPinballGame->unk1A = 0;

            if (gCurrentPinballGame->unk18 == 650)
                gCurrentPinballGame->unk294 = 1;
        }
        else
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
            DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
        break;
    }

    sub_3CBC4();
    sub_3B7C4();
    sub_3C6E0();
    sub_3E644();
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

void sub_3B7C4(void)
{
    s16 i;
    struct Vector32 tempVector;

    if (gCurrentPinballGame->unk452)
    {
        gCurrentPinballGame->unk452--;
        gCurrentPinballGame->unk389 = 1;
        if (gCurrentPinballGame->unk452 == 35)
        {
            MPlayStart(&gMPlayInfo_SE1, &se_unk_118);
            gCurrentPinballGame->scoreAddedInFrame = 500000;
            sub_11B0(7);
            gCurrentPinballGame->unk385++;
            if (gCurrentPinballGame->unk385 >= gCurrentPinballGame->unk384)
                gCurrentPinballGame->unk3DC = 6;
        }

        if (gCurrentPinballGame->unk452 < 31)
            gCurrentPinballGame->unk389 = 0;
    }

    switch (gCurrentPinballGame->unk3DC)
    {
    case 0:
        gCurrentPinballGame->unk3DC = 1;
        gCurrentPinballGame->unk3E2 = 22;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3E1 = 0;
        gCurrentPinballGame->unk3E8 = 0;
        gCurrentPinballGame->unk3EA = -1200;
        gCurrentPinballGame->unk4C6 = 0;
        break;
    case 1:
        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 36)
            {
                if (gCurrentPinballGame->unk3E1 < 18)
                {
                    gCurrentPinballGame->unk3E2 = 34;
                    gCurrentPinballGame->unk3E1++;
                }
                else
                {
                    gCurrentPinballGame->unk3E2 = 0;
                    gCurrentPinballGame->unk3DC = 2;
                    gCurrentPinballGame->unk3DD = 4;
                    gCurrentPinballGame->unk3E1 = 9;
                }
            }
        }

        if (gCurrentPinballGame->unk3E2 == 22)
        {
            if (gCurrentPinballGame->unk3E4 < 500)
            {
                if (gCurrentPinballGame->unk3E4 == 50 || gCurrentPinballGame->unk3E4 == 270)
                {
                    gCurrentPinballGame->unk4CA = 31;
                    gCurrentPinballGame->unk4C9 = gCurrentPinballGame->unk3E4 / 110;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    sub_11B0(8);
                }

                if (gCurrentPinballGame->unk3E4 == 160 || gCurrentPinballGame->unk3E4 == 380)
                {
                    gCurrentPinballGame->unk4CA = 31;
                    gCurrentPinballGame->unk4C9 = gCurrentPinballGame->unk3E4 / 110;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    sub_11B0(8);
                }

                if (gCurrentPinballGame->unk3E4 == 490)
                {
                    gCurrentPinballGame->unk4CA = 31;
                    gCurrentPinballGame->unk4C9 = 4;
                    m4aSongNumStart(SE_UNKNOWN_0x11A);
                    sub_11B0(8);
                }
            }

            if (gCurrentPinballGame->unk3E4 >= 630)
            {
                if (gCurrentPinballGame->unk3EA < 0)
                {
                    gCurrentPinballGame->unk4C6 += 4;
                    gCurrentPinballGame->unk3EA += gCurrentPinballGame->unk4C6;
                    if (gCurrentPinballGame->unk3EA > 0)
                        gCurrentPinballGame->unk3EA = 0;
                }
            }

            if (gCurrentPinballGame->unk3EA >= 0)
            {
                gCurrentPinballGame->unk4C8 = 60;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_11b);
                sub_11B0(13);
            }
        }

        if (gCurrentPinballGame->unk3E2 == 33)
        {
            if (gCurrentPinballGame->unk3E4 == 0)
                gCurrentPinballGame->unk390 = 41;
        }

        if (gCurrentPinballGame->unk392 > 120)
            gCurrentPinballGame->unk392--;
        break;
    case 2:
        if (gCurrentPinballGame->unk452 > 30)
        {
            gCurrentPinballGame->unk3E2 = 21;
            gCurrentPinballGame->unk3E4 = 0;
            break;
        }

        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 2)
            {
                if (gCurrentPinballGame->unk3E1 < 12)
                {
                    gCurrentPinballGame->unk3E2 = 0;
                    gCurrentPinballGame->unk3E1++;
                    if (gCurrentPinballGame->unk3E1 == 12 && gCurrentPinballGame->unk3DD == 4)
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (gCurrentPinballGame->unk48C[i] < 9)
                                gCurrentPinballGame->unk48C[i] = 9;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->unk3DD == 4)
                    {
                        gCurrentPinballGame->unk3E2 = 36;
                        gCurrentPinballGame->unk3DC = 4;
                        gCurrentPinballGame->unk3E1 = 0;
                    }
                    else if (gCurrentPinballGame->unk3DD == 3)
                    {
                        gCurrentPinballGame->unk3E2 = 76;
                        gCurrentPinballGame->unk3DC = 3;
                        gCurrentPinballGame->unk3E1 = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E2 = 58;
                        gCurrentPinballGame->unk3DC = 5;
                        gCurrentPinballGame->unk3E1 = 0;
                    }
                }
            }
        }

        if (gCurrentPinballGame->unk3E2 == 21)
            gCurrentPinballGame->unk3E2 = 0;
        break;
    case 3:
        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            s16 varZZ;
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 93 || gCurrentPinballGame->unk3E2 == 96 || gCurrentPinballGame->unk3E2 == 99)
            {
                gCurrentPinballGame->unk3E2 = 0;
                gCurrentPinballGame->unk3DC = 2;

                if (gCurrentPinballGame->unk47C & 1)
                {
                    gCurrentPinballGame->unk3DD = 4;
                    gCurrentPinballGame->unk3E1 = 8;
                }
                else
                {
                    gCurrentPinballGame->unk3DD = 5;
                    gCurrentPinballGame->unk3E1 = 8;
                }

                gCurrentPinballGame->unk47C++;
            }

            if (gCurrentPinballGame->unk3E2 == 90)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_11c);
                gCurrentPinballGame->unk47E = 8;
                gCurrentPinballGame->unk482 = 35;
                gMain.spriteGroups[22].available = 1;
                gCurrentPinballGame->unk488.x = 1200;
                gCurrentPinballGame->unk488.y = 1240;
                tempVector.x = gCurrentPinballGame->unk488.x / 10 - gCurrentPinballGame->ball->positionQ0.x;
                tempVector.y = gCurrentPinballGame->unk488.y / 10 - gCurrentPinballGame->ball->positionQ0.y;
                gCurrentPinballGame->unk484 = ArcTan2(-tempVector.x, tempVector.y);
                if (gCurrentPinballGame->unk388)
                    gCurrentPinballGame->unk484 = (((Random() * gMain.systemFrameCount) % 100) * 0x5000) / 100 + 0x9800;

                if (gCurrentPinballGame->unk484 < 0x4000)
                {
                    gCurrentPinballGame->unk484 = 0xE800;
                    gCurrentPinballGame->unk47D = 2;
                    gCurrentPinballGame->unk488.x = 1340;
                }
                else if (gCurrentPinballGame->unk484 < 0x9800)
                {
                    gCurrentPinballGame->unk484 = 0x9800;
                    gCurrentPinballGame->unk47D = 1;
                    gCurrentPinballGame->unk488.x = 1060;
                }
                else if (gCurrentPinballGame->unk484 < 0xB000)
                {
                    gCurrentPinballGame->unk47D = 1;
                    gCurrentPinballGame->unk488.x = 1060;
                }
                else if (gCurrentPinballGame->unk484 < 0xD000)
                {
                    gCurrentPinballGame->unk47D = 0;
                }
                else if (gCurrentPinballGame->unk484 < 0xE800)
                {
                    gCurrentPinballGame->unk47D = 2;
                    gCurrentPinballGame->unk488.x = 1340;
                }
                else
                {
                    gCurrentPinballGame->unk484 = 0xE800;
                    gCurrentPinballGame->unk47D = 2;
                    gCurrentPinballGame->unk488.x = 1340;
                }

                gCurrentPinballGame->unk3E2 += gCurrentPinballGame->unk47D * 3;
                if (gCurrentPinballGame->unk388)
                    gCurrentPinballGame->unk388 -= 0;
            }
        }
        break;
    case 4:
        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 56)
            {
                if (gCurrentPinballGame->unk3E1 < 6)
                {
                    gCurrentPinballGame->unk3E2 = 54;
                    gCurrentPinballGame->unk3E1++;
                }
                else
                {
                    gCurrentPinballGame->unk3E2 = 0;
                    gCurrentPinballGame->unk3DC = 2;
                    gCurrentPinballGame->unk3DD = 3;
                    gCurrentPinballGame->unk3E1 = 6;
                }
            }

            if (gCurrentPinballGame->unk3E2 == 50)
            {
                if (gCurrentPinballGame->unk3E4 == 0)
                {
                    gMain.spriteGroups[30].available = 1;
                    gCurrentPinballGame->unk456 = 0;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11d);
                }
            }
        }
        break;
    case 5:
        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 74)
            {
                gCurrentPinballGame->unk3E2 = 0;
                gCurrentPinballGame->unk3DC = 2;
                gCurrentPinballGame->unk3DD = 3;
                gCurrentPinballGame->unk3E1 = 8;
            }

            if (gCurrentPinballGame->unk3E2 == 71)
            {
                if (gCurrentPinballGame->unk3E4 == 0)
                {
                    gCurrentPinballGame->unk129 = 0;
                    gCurrentPinballGame->unk128 = 1;
                    gCurrentPinballGame->unk4C8 = 60;
                    sub_11B0(13);
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11b);
                }
            }
        }
        break;
    case 6:
        gCurrentPinballGame->unk294 = 3;
        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            gCurrentPinballGame->unk3DC = 9;
            gCurrentPinballGame->unk3E2 = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_GROUDON;
            gCurrentPinballGame->unk38E = 0;
            gCurrentPinballGame->unk5A8 = 0;
            gCurrentPinballGame->unk5A6 = 0;
            gCurrentPinballGame->unk5A4 = 2;
        }
        else
        {
            gCurrentPinballGame->unk3DC = 7;
            gCurrentPinballGame->unk3E2 = 32;
            gCurrentPinballGame->unk387 = 0;
            gMain.unkF = 0x80;
            gCurrentPinballGame->unk388 = 2;
            gCurrentPinballGame->unk392 = 0;
        }

        gCurrentPinballGame->unk3E1 = 0;
        gCurrentPinballGame->unk3E4 = 0;
        if (gMain.spriteGroups[24].available)
            gCurrentPinballGame->unk486 = 1;
        break;
    case 7:
        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 36)
            {
                if (gCurrentPinballGame->unk3E1 < 18)
                {
                    gCurrentPinballGame->unk3E2 = 34;
                    gCurrentPinballGame->unk3E1++;
                }
                else
                {
                    gCurrentPinballGame->unk3E2 = 2;
                    gCurrentPinballGame->unk3DC = 8;
                    gCurrentPinballGame->unk3E1 = 0;
                }
            }
        }

        if (gCurrentPinballGame->unk3E2 == 33)
        {
            if (gCurrentPinballGame->unk3E4 == 0)
                gCurrentPinballGame->unk390 = 41;
        }
        break;
    case 8:
        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 20)
            {
                if (gCurrentPinballGame->unk3E1 < 7)
                {
                    gCurrentPinballGame->unk3E2 = 3;
                    gCurrentPinballGame->unk3E1++;
                }
                else
                {
                    gCurrentPinballGame->unk3E2 = 3;
                    gCurrentPinballGame->unk3DC = 10;
                    gCurrentPinballGame->unk13 = 2;
                    gCurrentPinballGame->unk18 = 0;
                }
            }

            if (gCurrentPinballGame->unk3E2 == 3 || gCurrentPinballGame->unk3E2 == 12)
                gCurrentPinballGame->unk3EA -= 10;

            if ((gCurrentPinballGame->unk3E2 >= 4 && gCurrentPinballGame->unk3E2 < 6) ||
                gCurrentPinballGame->unk3E2 == 13 || gCurrentPinballGame->unk3E2 == 14)
            {
                gCurrentPinballGame->unk3EA -= 20;
            }

            if (gCurrentPinballGame->unk3E2 == 5)
            {
                if (gCurrentPinballGame->unk3E4 == 0)
                {
                    gCurrentPinballGame->unk4CA = 31;
                    gCurrentPinballGame->unk4C9 = 6;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    sub_11B0(8);
                }
            }

            if (gCurrentPinballGame->unk3E2 == 14)
            {
                if (gCurrentPinballGame->unk3E4 == 0)
                {
                    gCurrentPinballGame->unk4CA = 31;
                    gCurrentPinballGame->unk4C9 = 5;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    sub_11B0(8);
                }
            }
        }
        break;
    case 9:
        if (gUnknown_086AF140[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == 2)
                gCurrentPinballGame->unk3E2 = 0;
        }

        if (gCurrentPinballGame->unk38E > -500)
        {
            gCurrentPinballGame->unk38E += (-500 - gCurrentPinballGame->unk38E) / 30;
            gCurrentPinballGame->unkE6 = gCurrentPinballGame->unk38E / 10;
            if (gCurrentPinballGame->unkE6 < -38)
                gCurrentPinballGame->unkE6 = -38;
        }

        if (gCurrentPinballGame->unk5A8 == 21)
            gCurrentPinballGame->unk3E2 = 74;

        if (gCurrentPinballGame->unk5A8 == 22)
            gCurrentPinballGame->unk3E2 = 75;
        break;
    case 10:
        break;
    }

    if (gCurrentPinballGame->unk4C8 > 0)
    {
        gCurrentPinballGame->unk4C8--;
        if (gCurrentPinballGame->unk4C8 < 20)
            gCurrentPinballGame->unk2AC = gUnknown_086AEF28[gCurrentPinballGame->unk4C8 % 12] * 2;
        else
            gCurrentPinballGame->unk2AC = gUnknown_086AEF28[gCurrentPinballGame->unk4C8 % 12] * 4;

        if (gCurrentPinballGame->unk4C8 == 0)
            gCurrentPinballGame->unk2AC = 0;

        if (gCurrentPinballGame->unk4C8 == 8)
        {
            i = 0;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->unk4CF[i] = 0;
            gCurrentPinballGame->unk4D2[i] = 0;
            gCurrentPinballGame->unk4D8[i] = 0;
        }

        if (gCurrentPinballGame->unk4C8 == 20)
        {
            i = 1;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->unk4CF[i] = 0;
            gCurrentPinballGame->unk4D2[i] = 13;
            gCurrentPinballGame->unk4D8[i] = 0;
        }

        if (gCurrentPinballGame->unk4C8 == 53)
        {
            i = 2;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->unk4CF[i] = 0;
            gCurrentPinballGame->unk4D2[i] = 22;
            gCurrentPinballGame->unk4D8[i] = 0;
        }
    }

    if (gCurrentPinballGame->unk4CA)
    {
        gCurrentPinballGame->unk4CA--;
        if (gCurrentPinballGame->unk4C9 < 6)
        {
            gCurrentPinballGame->unk2AC = gUnknown_086AEF40[gCurrentPinballGame->unk4C9][30 - gCurrentPinballGame->unk4CA % 31];
        }
        else
        {
            gCurrentPinballGame->unk2AC = gUnknown_086AF0B4[69 - gCurrentPinballGame->unk4CA % 70];
        }

        if (gCurrentPinballGame->unk4CA == 0)
            gCurrentPinballGame->unk2AC = 0;
    }

    if (gCurrentPinballGame->unk390)
    {
        gCurrentPinballGame->unk390--;
        if (gCurrentPinballGame->unk390 == 20)
        {
            PlayCry_Normal(gSpeciesInfo[SPECIES_GROUDON].mainSeriesIndexNumber, 0);
            gCurrentPinballGame->unk4CA = 70;
            gCurrentPinballGame->unk4C9 = 6;
        }

        if (gCurrentPinballGame->unk390 == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void sub_3C6E0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    int palette;

    group = &gMain.spriteGroups[29];
    if (group->available)
    {
        var0 = gUnknown_086AF140[gCurrentPinballGame->unk3E2][0];
        group->baseX = gCurrentPinballGame->unk3E8 / 10 + 100u - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk3EA / 10 +  84u - gCurrentPinballGame->unk5A;
        gCurrentPinballGame->unk288 = gCurrentPinballGame->unk3E8 / 10 + 118;
        gCurrentPinballGame->unk28A = gCurrentPinballGame->unk3EA / 10 + 60;
        gCurrentPinballGame->unk3F0 = (gCurrentPinballGame->unk3E8 / 10) * 2 + 184;
        gCurrentPinballGame->unk3F2 = (gCurrentPinballGame->unk3EA / 10) * 2 + 156;
        if (group->baseY < -60)
            group->baseY = -60;
        if (group->baseY > 180)
            group->baseY = 180;

        if (gCurrentPinballGame->unk389 > 9)
        {
            palette = 11;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else if (gCurrentPinballGame->unk389 == 1)
        {
            palette = 14;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B65EA[var0][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else if (gCurrentPinballGame->unk389 == 3)
        {
            palette = 11;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B65EA[var0][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else
        {
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B65EA[var0][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }
    }

    group = &gMain.spriteGroups[23];
    if (group->available)
    {
        if (gCurrentPinballGame->unk47E > 0)
        {
            gCurrentPinballGame->unk47E--;
            if (gCurrentPinballGame->unk47E == 0)
                group->available = 0;
        }

        var0 = gCurrentPinballGame->unk47D * 2 - (gCurrentPinballGame->unk47E / 4 - 1);
        group->baseX = gCurrentPinballGame->unk3E8 / 10 + 100u - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk3EA / 10 +  84u - gCurrentPinballGame->unk5A;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B6512[var0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->unk5A4 == 2)
        {
            gMain.spriteGroups[23].available = 0;
            gCurrentPinballGame->unk47E = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk47E == 8)
            group->available = 1;
    }
}

void sub_3CBC4(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 varSL;
    int xx, yy;
    int squaredMagnitude;
    struct Vector32 tempVector;
    s8 var0;

    varSL = 0;
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

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        gCurrentPinballGame->unk486--;
        if (gCurrentPinballGame->unk486 >= 600)
        {
            varSL = 0;
        }
        else if (gCurrentPinballGame->unk486 >= 6)
        {
            varSL = (gCurrentPinballGame->unk486 % 15) / 5 + 1;
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
            else if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->unk486 = gCurrentPinballGame->unk486 - 30;
                if (gCurrentPinballGame->unk486 < 5)
                    gCurrentPinballGame->unk486 = 5;

                gCurrentPinballGame->unk47F = 7;
                m4aSongNumStart(SE_UNKNOWN_0x11E);
            }

            if (gCurrentPinballGame->unk480)
            {
                gCurrentPinballGame->unk480--;
                if (gCurrentPinballGame->unk480 > 50)
                    varSL = 4;
                else if (gCurrentPinballGame->unk480 > 40)
                    varSL = 5;
            }
            else if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->unk480 = 60;
            }
        }
        else
        {
            varSL = 4;
        }

        if (gCurrentPinballGame->unk486 == 0)
        {
            gMain.spriteGroups[24].available = 0;
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
        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B63AA[varSL][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        tempVector.x = gCurrentPinballGame->unk488.x / 10 - gCurrentPinballGame->ball->positionQ0.x;
        tempVector.y = gCurrentPinballGame->unk488.y / 10 - gCurrentPinballGame->ball->positionQ0.y;
        xx = tempVector.x * tempVector.x;
        yy = tempVector.y * tempVector.y;
        squaredMagnitude = xx + yy;
        if (gCurrentPinballGame->unk482)
        {
            gCurrentPinballGame->unk482--;
            if (gCurrentPinballGame->unk482 >= 10)
            {
                varSL = (gCurrentPinballGame->unk482 % 8) / 4 + gCurrentPinballGame->unk47D * 2;
                if (squaredMagnitude <= 240 && gCurrentPinballGame->unk388 == 0 && gCurrentPinballGame->unk486 < 600)
                {
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11f);
                    gCurrentPinballGame->unk482 = 10;
                    gMain.spriteGroups[24].available = 1;
                    gCurrentPinballGame->unk486 = 612;
                    sub_11B0(9);
                }

                gCurrentPinballGame->unk488.x += (Cos(gCurrentPinballGame->unk484) *  40) / 20000;
                gCurrentPinballGame->unk488.y += (Sin(gCurrentPinballGame->unk484) * -40) / 20000;

            }
            else
            {
                varSL = (gCurrentPinballGame->unk47D * 2) - ((gCurrentPinballGame->unk482 / 5) - 7);
                if (gCurrentPinballGame->unk482 == 9)
                {
                    if (squaredMagnitude <= 240)
                    {
                        gCurrentPinballGame->unk488.x = (gCurrentPinballGame->ball->positionQ0.x + 4) * 10;
                        gCurrentPinballGame->unk488.y = (gCurrentPinballGame->ball->positionQ0.y + 14) * 10;
                    }
                    else
                    {
                        if (gCurrentPinballGame->unk47D == 0)
                        {
                            gCurrentPinballGame->unk488.x += 0;
                            gCurrentPinballGame->unk488.y += 240;
                        }
                        else if (gCurrentPinballGame->unk47D == 1)
                        {
                            gCurrentPinballGame->unk488.x -= 120;
                            gCurrentPinballGame->unk488.y += 240;
                        }
                        else
                        {
                            gCurrentPinballGame->unk488.x += 120;
                            gCurrentPinballGame->unk488.y += 240;
                        }
                    }

                    m4aSongNumStart(SE_UNKNOWN_0x120);
                }
            }

            if (gCurrentPinballGame->unk482 == 0)
                gMain.spriteGroups[22].available = 0;
        }

        group->baseX = gCurrentPinballGame->unk488.x / 10 - gCurrentPinballGame->unk58 - 12;
        group->baseY = gCurrentPinballGame->unk488.y / 10 - gCurrentPinballGame->unk5A - 22;
        for (j = 0; j < 4; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B63F2[varSL][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->unk5A4 == 2)
        {
            gMain.spriteGroups[22].available = 0;
            gCurrentPinballGame->unk482 = 0;
        }
    }

    for (i = 0; i < 3; i++)
    {
        group = &gMain.spriteGroups[15 + i];
        if (group->available)
        {
            switch (gCurrentPinballGame->unk4CF[i])
            {
            case 0:
                gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i];
                gCurrentPinballGame->unk4EC[i].x = (((Random() % 101) * 145) / 100 + 30) * 10;
                gCurrentPinballGame->unk4CC[i] = Random() % 16;
                if (gCurrentPinballGame->unk4CC[i] == gCurrentPinballGame->unk4CC[(i + 1) % 3])
                    gCurrentPinballGame->unk4CC[i] = (gCurrentPinballGame->unk4CC[i] + 1) % 16;

                if (gCurrentPinballGame->unk4CC[i] == gCurrentPinballGame->unk4CC[(i + 2) % 3])
                    gCurrentPinballGame->unk4CC[i] = (gCurrentPinballGame->unk4CC[i] + 1) % 16;

                gCurrentPinballGame->unk4EC[i].x = gUnknown_086AF34C[gCurrentPinballGame->unk4CC[i]][0] * 10;
                gCurrentPinballGame->unk4EC[i].y = gUnknown_086AF34C[gCurrentPinballGame->unk4CC[i]][1] * 10;
                gCurrentPinballGame->unk4E4[i] = -1200;
                gCurrentPinballGame->unk4DE[i] = 0;
                gCurrentPinballGame->unk4CF[i] = 1;
                gCurrentPinballGame->unk4F8[i].x = 0;
                gCurrentPinballGame->unk4F8[i].y = 0;
                gCurrentPinballGame->unk4D5[i] = 0;
                break;
            case 1:
                if (gCurrentPinballGame->unk4E4[i] < 0) {
                    gCurrentPinballGame->unk4DE[i] += 3;
                    gCurrentPinballGame->unk4E4[i] += gCurrentPinballGame->unk4DE[i];
                    if (gCurrentPinballGame->unk4E4[i] > 0) {
                        gCurrentPinballGame->unk4E4[i] = 0;
                    }
                }

                if (gCurrentPinballGame->unk4E4[i] >= 0)
                {
                    if (gCurrentPinballGame->unk4D8[i] == 0)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        sub_11B0(7);
                    }

                    if (gCurrentPinballGame->unk4D8[i] < 5)
                    {
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 1;
                    }
                    else if (gCurrentPinballGame->unk4D8[i] < 10)
                    {
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 2;
                    }
                    else
                    {
                        gCurrentPinballGame->unk4D8[i] = 0;
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i];
                        gCurrentPinballGame->unk4CF[i] = 2;
                    }

                    gCurrentPinballGame->unk4D8[i]++;
                }

                gCurrentPinballGame->unk4F8[i].x = 0;
                gCurrentPinballGame->unk4F8[i].y = 0;
                break;
            case 2:
                gCurrentPinballGame->unk4F8[i].x = (gCurrentPinballGame->unk4EC[i].x / 10) * 2;
                gCurrentPinballGame->unk4F8[i].y = (gCurrentPinballGame->unk4EC[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->unk4D5[i])
                {
                    if (gCurrentPinballGame->unk4D8[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        sub_11B0(7);
                    }

                    if (gCurrentPinballGame->unk4D8[i] < 5)
                    {
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 3;
                    }
                    else if (gCurrentPinballGame->unk4D8[i] < 10)
                    {
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 4;
                    }
                    else
                    {
                        gCurrentPinballGame->unk4D8[i] = 0;
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 5;
                        gCurrentPinballGame->unk4CF[i] = 3;
                        gCurrentPinballGame->unk4D5[i] = 0;
                    }

                    gCurrentPinballGame->unk4D8[i]++;
                }
                break;
            case 3:
                gCurrentPinballGame->unk4F8[i].x = (gCurrentPinballGame->unk4EC[i].x / 10) * 2;
                gCurrentPinballGame->unk4F8[i].y = (gCurrentPinballGame->unk4EC[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->unk4D5[i])
                {
                    if (gCurrentPinballGame->unk4D8[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        sub_11B0(7);
                    }

                    if (gCurrentPinballGame->unk4D8[i] < 5)
                    {
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 6;
                    }
                    else if (gCurrentPinballGame->unk4D8[i] < 10)
                    {
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 7;
                    }
                    else
                    {
                        gCurrentPinballGame->unk4D8[i] = 0;
                        gCurrentPinballGame->unk4D2[i] = gUnknown_086AF3AC[i] + 8;
                        gCurrentPinballGame->unk4CF[i] = 4;
                        gCurrentPinballGame->unk4D5[i] = 0;
                    }

                    gCurrentPinballGame->unk4D8[i]++;
                }
                break;
            case 4:
                gCurrentPinballGame->unk4F8[i].x = (gCurrentPinballGame->unk4EC[i].x / 10) * 2;
                gCurrentPinballGame->unk4F8[i].y = (gCurrentPinballGame->unk4EC[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->unk4D5[i])
                {
                    if (gCurrentPinballGame->unk4D8[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        sub_11B0(7);
                    }

                    if (gCurrentPinballGame->unk4D8[i] < 3)
                    {
                        gCurrentPinballGame->unk4D2[i] = 9;
                    }
                    else if (gCurrentPinballGame->unk4D8[i] < 8)
                    {
                        gCurrentPinballGame->unk4D2[i] = 10;
                    }
                    else if (gCurrentPinballGame->unk4D8[i] < 14)
                    {
                        gCurrentPinballGame->unk4D2[i] = 11;
                    }
                    else if (gCurrentPinballGame->unk4D8[i] < 23)
                    {
                        gCurrentPinballGame->unk4D2[i] = 12;
                    }
                    else
                    {
                        gCurrentPinballGame->unk4D8[i] = 0;
                        gCurrentPinballGame->unk4D2[i] = 12;
                        gCurrentPinballGame->unk4CF[i] = 5;
                        gCurrentPinballGame->unk4D5[i] = 0;
                    }

                    gCurrentPinballGame->unk4D8[i]++;
                }
                break;
            case 5:
                gCurrentPinballGame->unk4F8[i].x = 0;
                gCurrentPinballGame->unk4F8[i].y = 0;
                gMain.spriteGroups[15 + i].available = 0;
                break;
            }

            var0 = gCurrentPinballGame->unk4D2[i];
            DmaCopy16(3, gUnknown_084A11EC[var0], (void *)0x06010FA0 + i * 0x300, 0x300);

            group->baseX = (gCurrentPinballGame->unk4EC[i].x / 10) + i - gCurrentPinballGame->unk58;
            group->baseY = (gCurrentPinballGame->unk4E4[i] / 10) + (gCurrentPinballGame->unk4EC[i].y / 10) - gCurrentPinballGame->unk5A;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->unk4CF[i] >= 2 && gCurrentPinballGame->unk4CF[i] < 5)
            {
                if (gUnknown_086AF34C[gCurrentPinballGame->unk4CC[i]][2] == gCurrentPinballGame->unk456)
                {
                    gCurrentPinballGame->unk4CF[i] = 4;
                    gCurrentPinballGame->unk4D5[i] = 1;
                    gCurrentPinballGame->unk4D8[i] = 0;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[18 + i];
        if (group->available)
        {
            switch(gCurrentPinballGame->unk48C[i])
            {
            case 0:
                gCurrentPinballGame->unk49C[i] = 0;
                gCurrentPinballGame->unk490[i] = 8;
                gCurrentPinballGame->unk494[i] = 1;
                gCurrentPinballGame->unk4A0[i] = 0;
                break;
            case 1:
                gCurrentPinballGame->unk49C[i] = 8;
                gCurrentPinballGame->unk490[i] = 12;
                gCurrentPinballGame->unk494[i] = 3;
                gCurrentPinballGame->unk4A0[i] = 14;
                gCurrentPinballGame->unk48C[i] = 2;
                break;
            case 2:
                if (gCurrentPinballGame->unk4A4[i] > 0)
                {
                    gCurrentPinballGame->unk4A4[i]--;
                    if (gCurrentPinballGame->unk4A4[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->unk48C[i] = 3;
                        sub_11B0(7);
                    }
                }
                break;
            case 3:
                gCurrentPinballGame->unk49C[i] = 12;
                gCurrentPinballGame->unk490[i] = 16;
                gCurrentPinballGame->unk494[i] = 5;
                gCurrentPinballGame->unk4A0[i] = 14;
                gCurrentPinballGame->unk48C[i] = 4;
                break;
            case 4:
                if (gCurrentPinballGame->unk4A4[i] > 0)
                {
                    gCurrentPinballGame->unk4A4[i]--;
                    if (gCurrentPinballGame->unk4A4[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->unk48C[i] = 5;
                        sub_11B0(7);
                    }
                }
                break;
            case 5:
                gCurrentPinballGame->unk49C[i] = 16;
                gCurrentPinballGame->unk490[i] = 20;
                gCurrentPinballGame->unk494[i] = 7;
                gCurrentPinballGame->unk4A0[i] = 14;
                gCurrentPinballGame->unk48C[i] = 6;
                break;
            case 6:
                if (gCurrentPinballGame->unk4A4[i] > 0)
                {
                    gCurrentPinballGame->unk4A4[i]--;
                    if (gCurrentPinballGame->unk4A4[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->unk48C[i] = 7;
                        sub_11B0(7);
                    }
                }
                break;
            case 7:
                gCurrentPinballGame->unk49C[i] = 20;
                gCurrentPinballGame->unk490[i] = 24;
                gCurrentPinballGame->unk494[i] = 9;
                gCurrentPinballGame->unk4A0[i] = 14;
                gCurrentPinballGame->unk48C[i] = 8;
                gCurrentPinballGame->unk4A8[i] = 0;
                break;
            case 8:
                if (gCurrentPinballGame->unk4A4[i] > 0)
                {
                    gCurrentPinballGame->unk4A4[i]--;
                    if (gCurrentPinballGame->unk4A4[i] == 7)
                    {
                        if (gCurrentPinballGame->unk4A8[i] <= 0)
                        {
                            gCurrentPinballGame->unk4A8[i]++;
                        }
                        else
                        {
                            gCurrentPinballGame->unk4A8[i] = 0;
                            gCurrentPinballGame->unk48C[i] = 9;
                        }

                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        sub_11B0(7);
                    }
                }
                break;
            case 9:
                gCurrentPinballGame->unk49C[i] = 24;
                gCurrentPinballGame->unk490[i] = 27;
                gCurrentPinballGame->unk494[i] = 10;
                gCurrentPinballGame->unk4A0[i] = 0;
                break;
            case 10:
                gMain.spriteGroups[18 + i].available = 0;
                break;
            }

            if (gUnknown_086AF2DC[gCurrentPinballGame->unk498[i]][1] > gCurrentPinballGame->unk4AC[i])
            {
                gCurrentPinballGame->unk4AC[i]++;
            }
            else
            {
                gCurrentPinballGame->unk4AC[i] = 0;
                gCurrentPinballGame->unk498[i]++;
                if (gCurrentPinballGame->unk498[i] == gCurrentPinballGame->unk490[i])
                {
                    if (gCurrentPinballGame->unk4A0[i] > 0)
                    {
                        gCurrentPinballGame->unk498[i] = gCurrentPinballGame->unk49C[i];
                        gCurrentPinballGame->unk4A0[i]--;
                    }
                    else
                    {
                        gCurrentPinballGame->unk498[i] = gCurrentPinballGame->unk490[i] - 1;
                        gCurrentPinballGame->unk48C[i] = gCurrentPinballGame->unk494[i];
                    }
                }
            }

            varSL = gUnknown_086AF2DC[gCurrentPinballGame->unk498[i]][0];
            // Unsigned integers for matching
            group->baseX = gUnknown_086AF2CC[i].x + 65u - gCurrentPinballGame->unk58;
            group->baseY = gUnknown_086AF2CC[i].y + 60u - gCurrentPinballGame->unk5A;
            if (gCurrentPinballGame->unk48C[i] < 9)
            {
                gCurrentPinballGame->unk4B4[i].x = (gUnknown_086AF2CC[i].x + 61) * 2;
                gCurrentPinballGame->unk4B4[i].y = (gUnknown_086AF2CC[i].y + 96) * 2;
            }

            if (gCurrentPinballGame->unk4A4[i] > 0)
            {
                for (j = 0; j < 10; j++)
                {
                    oamSimple = &group->oam[j];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    src = gUnknown_086B8AE0[varSL][j];
                    *dst++ = *src++;
                    *dst++ = *src++;
                    *dst++ = *src++;

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                    gOamBuffer[oamSimple->oamId].y += group->baseY;
                    gOamBuffer[oamSimple->oamId].paletteNum = 2;
                }
            }
            else
            {
                for (j = 0; j < 10; j++)
                {
                    oamSimple = &group->oam[j];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    src = gUnknown_086B8AE0[varSL][j];
                    *dst++ = *src++;
                    *dst++ = *src++;
                    *dst++ = *src++;

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                    gOamBuffer[oamSimple->oamId].y += group->baseY;
                }
            }
        }
        else
        {
            gCurrentPinballGame->unk4B4[i].x = 0;
            gCurrentPinballGame->unk4B4[i].y = 0;
        }
    }

    if (gCurrentPinballGame->unk4C4)
    {
        gCurrentPinballGame->unk4C4--;
        if (gCurrentPinballGame->unk4C4 == 36)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->unk4C4 == 24)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->unk4C4 == 12)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->unk4C4 == 0)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);
    }

    group = &gMain.spriteGroups[30];
    if (group->available)
    {
        s16 scale;
        s16 var6;
        if (gCurrentPinballGame->unk456 <= 35)
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

        if (gCurrentPinballGame->unk456 == 34)
        {
            for (i = 0; i < 4; i++)
            {
                gMain.spriteGroups[i + 18].available = 1;
                gCurrentPinballGame->unk48C[i] = 0;
                gCurrentPinballGame->unk498[i] = 0;
                gCurrentPinballGame->unk4AC[i] = 0;
            }

            gCurrentPinballGame->unk4C4 = 37;
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
            group->baseY = 50 - gCurrentPinballGame->unk5A;
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gCurrentPinballGame->unk46C[j].x;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gCurrentPinballGame->unk46C[j].y;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 1 + j;
            }
        }

        if (gCurrentPinballGame->unk456 < 30)
        {
            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - 119;
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - 147;
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (gCurrentPinballGame->unk388 == 0 && squaredMagnitude < gUnknown_086AEE20[gCurrentPinballGame->unk456])
            {
                gCurrentPinballGame->unk5B0 = ArcTan2(-tempVector.x, tempVector.y);
                gCurrentPinballGame->ball->velocity.x = (Cos(gCurrentPinballGame->unk5B0) * -400) / 20000;
                gCurrentPinballGame->ball->velocity.y = (Sin(gCurrentPinballGame->unk5B0) *  400) / 20000;
                sub_11B0(9);
            }
        }

        if ((gMain.unkF & 0xC0) != 0)
            gMain.spriteGroups[30].available = 0;
    }
}

void sub_3E5D0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[30];
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

void sub_3E644(void)
{
    s16 i, j;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = gUnknown_086AF3B2[(gMain.systemFrameCount % 144) / 24];
    DmaCopy16(3, &gUnknown_08352BD8[var0 * 0x20], (void *)0x05000000, 0x20);
    DmaCopy16(3, &gUnknown_08352BD8[(var0 + 4) * 0x20], (void *)0x05000080, 0x20);

    var0 = gUnknown_086AF3BE[(gMain.systemFrameCount % 96) / 24];
    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[11 + i];
        group->baseX = 120 - gCurrentPinballGame->unk58;
        group->baseY = 128 - gCurrentPinballGame->unk5A;
        for (j = 0; j < 3; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = gUnknown_086AF3C6[j] + var0 * 8;
        }
    }
}