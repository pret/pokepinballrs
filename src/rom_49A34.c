#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const struct Vector16 gUnknown_08137D78[];
extern const u16 gUnknown_08137DA4[];
extern const u8 gUnknown_08510CAC[][0x20];

extern const u8 gUnknown_0850558C[][0x20];
extern const s8 gUnknown_086B0128[][3][20];
extern const u8 gUnknown_0850100C[];
extern const u8 gUnknown_085028CC[];
extern const u8 gUnknown_085038CC[];
extern const u8 gUnknown_08514F4C[];
extern const u8 gUnknown_08514F6C[];
extern const u8 gUnknown_08521FAC[];
extern const u8 gUnknown_08521FCC[];
extern const u8 gUnknown_0850398C[];
extern const u8 gUnknown_08509F4C[];
extern const u8 gUnknown_08137DBE[];
extern const u8 gUnknown_08137DE8[];
extern u8 gUnknown_08137E00[];

struct Unk_86AFCB0
{
    const s16 *unk0;
    u8 filler4[0xC];
    const u16 *unk10;
    u8 filler14[0xC];
    const u8 *unk20;
    u8 filler24[0xC];
};
extern const struct Unk_86AFCB0 gUnknown_086AFCB0[][2];
extern const s16 gUnknown_086B0010[][4];
extern const struct Unk02031520_unk14 gUnknown_086AFD70[];
extern const u8 gUnknown_081BFEE4[];
extern const u8 gUnknown_08265C10[];
extern const u8 gUnknown_0826DC10[];
extern const u8 gUnknown_0824C1E4[];
extern const u8 gUnknown_0824DD60[];
extern const u8 gUnknown_08250934[];
extern const u8 gUnknown_081C08E4[];
extern const u8 gUnknown_0822E424[];
extern const u8 gUnknown_083A8ACC[];
extern const u8 gUnknown_083A826C[];
extern const u8 gUnknown_0845A48C[];
extern const u8 gUnknown_0816C3E4[];
extern const u8 gUnknown_082E4EE0[];
extern const u8 gUnknown_082ECEE0[];
extern const u8 gUnknown_082D34D0[];
extern const u8 gUnknown_082D523C[];
extern const u8 gUnknown_082D8998[];
extern const u8 gUnknown_0826EE10[];
extern const u8 gUnknown_082AE6D0[];
extern const u8 gUnknown_0845F9EC[];
extern const u8 gUnknown_082EDEE0[];
extern const u8 gUnknown_08302700[];
extern const u8 gUnknown_08303928[];
extern const u8 gUnknown_082EE4C0[];
extern const u8 gUnknown_08301700[];
extern const u8 gUnknown_08301F00[];
extern const u8 gUnknown_08464F4C[];
extern const u8 gUnknown_0830CBD4[];
extern const u8 gUnknown_08329994[];
extern const u8 gUnknown_0830CDD4[];
extern const u8 gUnknown_08327994[];
extern const u8 gUnknown_084675EC[];
extern const u8 gUnknown_0832A194[];
extern const u8 gUnknown_0833E044[];
extern const u8 gUnknown_08333004[];
extern const u8 gUnknown_0833D844[];
extern const u8 gUnknown_0846A40C[];
extern const u8 gUnknown_08332E04[];
extern const u8 gUnknown_0826EC10[];
extern const u8 gUnknown_08352BD8[];
extern const u8 gUnknown_08353DD8[];
extern const u8 gUnknown_08352DD8[];
extern const u8 gUnknown_083535D8[];
extern const u8 gUnknown_0846D2AC[];
extern const u8 gUnknown_08363EC8[];
extern const u8 gUnknown_08370808[];
extern const u8 gUnknown_083640C8[];
extern const u8 gUnknown_0836F808[];
extern const u8 gUnknown_0836E808[];
extern const u8 gUnknown_08472A6C[];
extern const u8 gUnknown_0837A2E8[];
extern const u8 gUnknown_0838E828[];
extern const u16 gUnknown_0837A4E8[];
extern const u8 gUnknown_0838E028[];
extern const u8 gUnknown_084779EC[];
extern const s16 gUnknown_086AEED6[];
extern const u8 gUnknown_084BB16C[][0x480];
extern const u8 gUnknown_084B7FEC[][0x480];
extern const s8 gUnknown_08137D60[];
extern const u8 gUnknown_084AF9EC[][0x200];
extern const u8 gUnknown_084AFFEC[][0x180];
extern const u16 gUnknown_086AFB2C[][3];
extern const u8 gUnknown_084B046C[][0x120];
extern const u16 gUnknown_086B56D8[][4][3];
extern const u16 gUnknown_086B5D56[][2][3];
extern const u16 gUnknown_086B609E[][3][3];
extern const u16 gUnknown_086B5ECA[][6][3];
extern const u16 gUnknown_086B5DCE[][7][3];
extern const u16 gUnknown_086B5CC0[][5][3];
extern const u16 gUnknown_086AF3CC[][3];
extern const u16 gUnknown_086B612E[][3];
extern const u16 gUnknown_086AFAE2[][2];
extern const u16 gUnknown_086AFAE0[][2];
extern const u8 gUnknown_084B47EC[][0x800];
extern const u8 gUnknown_084B77EC[];
extern const s16 gUnknown_086AF784[];
extern const struct Vector16 gUnknown_086AF744[32];
extern const s16 gUnknown_086AEF28[];
extern const s16 gUnknown_08137D48[];
extern const u8 gUnknown_084A6EEC[][0x280];
extern const u8 gUnknown_084AA9EC[][0x800];
extern const u8 gUnknown_084A856C[];
extern const u8 gUnknown_084AA18C[];
extern const u8 gUnknown_081408B4[];
extern const u8 gUnknown_083C5A2C[];
extern const s16 gUnknown_086AF3B2[];
extern const s16 gUnknown_086AF3BE[];
extern const u16 gUnknown_086AF3C6[];
extern const u16 gUnknown_086B63AA[][2][3];
extern const u16 gUnknown_086B65EA[][19][3];
extern const u16 gUnknown_086B6512[][6][3];
extern const u16 gUnknown_086B63F2[][4][3];
extern const u16 gUnknown_086B8AE0[][10][3];
extern const s16 gUnknown_086AF3AC[];
extern const s16 gUnknown_086AF34C[][3];
extern const s8 gUnknown_084A11EC[][0x300];
extern const u16 gUnknown_086AF2DC[][2];
extern const struct Vector16 gUnknown_086AF2CC[];
extern const s16 gUnknown_086AEE20[];
extern const u16 gUnknown_086AF140[][2];
extern const u16 gUnknown_086AEF40[][31];
extern const u16 gUnknown_086AF0B4[];
extern const u8 gUnknown_0813E894[];

struct Unk_086AFAC0
{
    struct Vector16 *unk0;
    s16 unk4;
};
extern const struct Unk_086AFAC0 gUnknown_086AFAC0[];

extern const s16 gUnknown_086AFC16[][4];
extern struct SongHeader gUnknown_086A2EE4;
extern struct SongHeader gUnknown_086A2D94;
extern struct SongHeader gUnknown_086A2E70;
extern struct SongHeader gUnknown_086A2D28;
extern struct SongHeader gUnknown_086A2EAC;
extern struct SongHeader gUnknown_086A2E90;
extern struct SongHeader gUnknown_086A26A0;
extern struct SongHeader gUnknown_086A22D8;
extern struct SongHeader gUnknown_086A2454;
extern struct SongHeader gUnknown_086A24F0;
extern struct SongHeader gUnknown_086A2548;

extern s16 gUnknown_02030750[];
extern s16 gUnknown_02031500[];
extern s16 gUnknown_020306C0[];
extern u8 gUnknown_0200FBB0[];
extern u8 gUnknown_020030A0[];


void sub_3B49C(void)
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
            DmaCopy16(3, gUnknown_0813E894, (void *)0x06015800, 0x2000);
            gCurrentPinballGame->unk394 = 136;
            gMain.unkF = 0x80;
            gCurrentPinballGame->unk5FA = 1;
        }
        break;
    case 3:
        sub_351A8();
        if (gCurrentPinballGame->unk1C)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180)
        {
            gCurrentPinballGame->unk1C = 1;
            gCurrentPinballGame->unk38 = 400000;
            gCurrentPinballGame->unk3C = 50000000;
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
        DmaCopy16(3, gUnknown_0813E894, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->unk394 = 136;
        gMain.unkF = 0x80;
        break;
    case 5:
        sub_351A8();
        if (gCurrentPinballGame->unk1C)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180)
        {
            gCurrentPinballGame->unk1C = 1;
            gCurrentPinballGame->unk38 = 400000;
            gCurrentPinballGame->unk3C = 50000000;
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
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A22D8);
            gCurrentPinballGame->unk3C = 500000;
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
                    m4aSongNumStart(SE_UNKNOWN_0x119);
                    sub_11B0(8);
                }

                if (gCurrentPinballGame->unk3E4 == 160 || gCurrentPinballGame->unk3E4 == 380)
                {
                    gCurrentPinballGame->unk4CA = 31;
                    gCurrentPinballGame->unk4C9 = gCurrentPinballGame->unk3E4 / 110;
                    m4aSongNumStart(SE_UNKNOWN_0x119);
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
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2454);
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
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A24F0);
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
                    MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2548);
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
                    MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2454);
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
                    m4aSongNumStart(SE_UNKNOWN_0x119);
                    sub_11B0(8);
                }
            }

            if (gCurrentPinballGame->unk3E2 == 14)
            {
                if (gCurrentPinballGame->unk3E4 == 0)
                {
                    gCurrentPinballGame->unk4CA = 31;
                    gCurrentPinballGame->unk4C9 = 5;
                    m4aSongNumStart(SE_UNKNOWN_0x119);
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
                    MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A26A0);
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
                        m4aSongNumStart(SE_UNKNOWN_0x121);
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
                        m4aSongNumStart(SE_UNKNOWN_0x121);
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
                        m4aSongNumStart(SE_UNKNOWN_0x121);
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
                        m4aSongNumStart(SE_UNKNOWN_0x121);
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
                        m4aSongNumStart(SE_UNKNOWN_0x123);
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
                        m4aSongNumStart(SE_UNKNOWN_0x123);
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
                        m4aSongNumStart(SE_UNKNOWN_0x123);
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

                        m4aSongNumStart(SE_UNKNOWN_0x123);
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
            m4aSongNumStart(SE_UNKNOWN_0x122);

        if (gCurrentPinballGame->unk4C4 == 24)
            m4aSongNumStart(SE_UNKNOWN_0x122);

        if (gCurrentPinballGame->unk4C4 == 12)
            m4aSongNumStart(SE_UNKNOWN_0x122);

        if (gCurrentPinballGame->unk4C4 == 0)
            m4aSongNumStart(SE_UNKNOWN_0x122);
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

void sub_3E79C(void)
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

void sub_3EB2C(void)
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
        DmaCopy16(3, gUnknown_081408B4, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->unk394 = 136;
        gMain.unkF = 0x80;
        gCurrentPinballGame->unk5FA = 1;
        break;
    case 3:
        sub_351A8();
        if (gCurrentPinballGame->unk1C)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180)
        {
            gCurrentPinballGame->unk1C = 1;
            gCurrentPinballGame->unk38 = 400000;
            gCurrentPinballGame->unk3C = 99999999;
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
        DmaCopy16(3, gUnknown_081408B4, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->unk394 = 136;
        gMain.unkF = 0x80;
        break;
    case 5:
        sub_351A8();
        if (gCurrentPinballGame->unk1C)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180)
        {
            gCurrentPinballGame->unk1C = 1;
            gCurrentPinballGame->unk38 = 400000;
            gCurrentPinballGame->unk3C = 99999999;
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
            m4aSongNumStart(SE_UNKNOWN_0x126);
            gCurrentPinballGame->unk3C = 1000000;
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
            m4aSongNumStart(SE_UNKNOWN_0x127);
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
            m4aSongNumStart(SE_UNKNOWN_0x129);
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
        gCurrentPinballGame->ball->unk1 = 1;
    else
        gCurrentPinballGame->ball->unk1 = 2;

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
                    m4aSongNumStart(SE_UNKNOWN_0x12E);

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

void sub_42E48(void)
{
    s16 i;
    s16 frame;

    frame = gMain.systemFrameCount % 16;
    for (i = 0; i < frame; i++)
        Random();

    gMain.rngValue = gMain.systemFrameCount;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 7200;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk388 = 0;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unk1F = 1;
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->unk6 = 0;
    gCurrentPinballGame->unk386 = 0;
    gCurrentPinballGame->unk53A = 0;
    gCurrentPinballGame->unk542 = 0;
    gCurrentPinballGame->unk544 = 0;
    gCurrentPinballGame->unk54A = 0;
    gCurrentPinballGame->unk394 = 0;
    gCurrentPinballGame->unk590 = 0;
    gCurrentPinballGame->unk591 = 0;
    gCurrentPinballGame->unk592 = 0;
    gCurrentPinballGame->unk594 = 0;
    gCurrentPinballGame->unk596 = 0;
    gCurrentPinballGame->unk7E = 1;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->unk3A0[i] = 0;
        gCurrentPinballGame->unk3A3[i] = 0;
        gCurrentPinballGame->unk3B0[i] = 0;
    }

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->unk530[i] = 0;
        gCurrentPinballGame->unk533[i] = 0;
        gCurrentPinballGame->unk536[i] = 0;
        gCurrentPinballGame->unk53C[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->unk52C[i] = 0;
        gCurrentPinballGame->unk52E[i] = 0;
        gCurrentPinballGame->unk548[i] = 0;
        gCurrentPinballGame->unk54B[i] = 0;
        gCurrentPinballGame->unk54D[i] = 0;
        gCurrentPinballGame->unk54F[i] = 0;
        gCurrentPinballGame->unk551[i] = 0;
        gCurrentPinballGame->unk553[i] = 0;
        gCurrentPinballGame->unk555[i] = 0;
        gCurrentPinballGame->unk557[i] = 0;
        gCurrentPinballGame->unk559[i] = 0;
        gCurrentPinballGame->unk55B[i] = 0;
        gCurrentPinballGame->unk55D[i] = 0;
        gCurrentPinballGame->unk55F[i] = 0;
        gCurrentPinballGame->unk562[i] = 0;
        gCurrentPinballGame->unk566[i] = 0;
        gCurrentPinballGame->unk56A[i] = 0;
        gCurrentPinballGame->unk570[i].x = 0;
        gCurrentPinballGame->unk570[i].y = 0;
        gCurrentPinballGame->unk578[i].x = 0;
        gCurrentPinballGame->unk578[i].y = 0;
        gCurrentPinballGame->unk580[i].x = 0;
        gCurrentPinballGame->unk580[i].y = 0;
    }

    gCurrentPinballGame->unk1A = 0;
    sub_4387C();
    sub_43500();
    sub_44D58();
    sub_45E08();

    for (i = 0; i < 0x800; i++)
        gUnknown_03005C00[0x400 + i] = 0x200;

    DmaCopy16(3, &gUnknown_03005C00[0x400], (void *)0x06001000, 0x1000);

    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        u16 var0 = i - ((i / 0x20) * 0x20) - 2;
        if (var0 < 28)
           gUnknown_03005C00[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gUnknown_03005C00[0x800], (void *)0x06001140, 0x280);
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)0x05000220, 0x20);
    m4aSongNumStart(MUS_BONUS_FIELD_SPHEAL);
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void sub_43228(void)
{
    switch (gCurrentPinballGame->unk13)
    {
    case 0:
        gCurrentPinballGame->unk5F7 = 1;
        if (gCurrentPinballGame->unk18 < 340)
        {
            if (gCurrentPinballGame->unk18 < 321)
                gCurrentPinballGame->unkE6 = (gCurrentPinballGame->unk18 / 5) + 0xFFC0;

            if (gCurrentPinballGame->unk18 == 325)
                gCurrentPinballGame->unk294 = 2;

            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unkE6 = 0;
            gCurrentPinballGame->unk13 = 1;
            gCurrentPinballGame->unk18 = 0;
        }
        break;
    case 1:
        if (gCurrentPinballGame->eventTimer == 0)
        {
            gCurrentPinballGame->unk294 = 3;
            if (gCurrentPinballGame->unk18 == 0)
            {
                m4aMPlayAllStop();
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2E90);
                gMain.unkF = 0x80;
                gCurrentPinballGame->unk388 = 2;
                gCurrentPinballGame->unk392 = 0;
            }

            if (gCurrentPinballGame->unk18 < 60)
            {
                gCurrentPinballGame->unk18++;
            }
            else
            {
                gCurrentPinballGame->unk13 = 2;
                gCurrentPinballGame->unk18 = 0;
            }
        }
        break;
    case 2:
        if (gCurrentPinballGame->unk18 == 0)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_SUCCESS3);
        }

        if (gCurrentPinballGame->unk18 < 20)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk13 = 3;
            gCurrentPinballGame->unk18 = 0;
            gMain.spriteGroups[7].available = 1;
            gMain.spriteGroups[8].available = 1;
            gMain.spriteGroups[9].available = 1;
            gMain.spriteGroups[10].available = 1;
            DmaCopy16(3, gUnknown_084B77EC, (void *)0x06015800, 0x800);
            gCurrentPinballGame->unk394 = -126;
            gCurrentPinballGame->unk5FA = 1;
        }
        break;
    case 3:
        sub_45E90();
        if (gCurrentPinballGame->unk1C)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180 && gCurrentPinballGame->unk544 != 0)
        {
            gCurrentPinballGame->unk1C = 1;
            gCurrentPinballGame->unk38 = 400000;
            gCurrentPinballGame->unk3C = gCurrentPinballGame->unk544;
        }

        if (gCurrentPinballGame->unk18 > 189 && JOY_NEW(A_BUTTON))
            gCurrentPinballGame->unk18 = 540;

        if (gCurrentPinballGame->unk18 < 540)
        {
            if (gCurrentPinballGame->unk18 == 4)
                m4aSongNumStart(SE_UNKNOWN_0xA4);

            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk13 = 4;
        }

        gCurrentPinballGame->unk5FA = 1;
        break;
    case 4:
        sub_45E90();
        if (gCurrentPinballGame->unk18 < 30)
        {
            gCurrentPinballGame->unk18++;
            if (gCurrentPinballGame->unk18 == 2)
                m4aSongNumStart(SE_UNKNOWN_0xA4);
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk13 = 5;
        }
        break;
    case 5:
        sub_45E90();
        gCurrentPinballGame->unk386 = 1;
        gCurrentPinballGame->unk5FA = 1;
        break;
    }

    sub_4387C();
    sub_43500();
    sub_44D58();
    sub_45E08();
    if (gCurrentPinballGame->unk386)
    {
        gCurrentPinballGame->unk5FA = 1;
        sub_350F0();
    }

    sub_472E4();
}

void sub_43500(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->unk13 < 2 && gMain.unkF == 0)
        sub_455D0();

    if (gCurrentPinballGame->unk13 < 2 && gMain.unkF == 0)
    {
        for (i = 0; i < 2; i++)
        {
            if (gCurrentPinballGame->unk548[i] == 23)
            {
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2EAC);
                gCurrentPinballGame->unk3C = 5000;
                sub_11B0(8);
            }

            switch (gCurrentPinballGame->unk3A0[i])
            {
            case 0:
                gCurrentPinballGame->unk3B0[i] = 0;
                gCurrentPinballGame->unk3A3[i] = 4;
                gCurrentPinballGame->unk3A0[i] = 1;
                break;
            case 1:
                if (gCurrentPinballGame->unk548[i] > 0)
                {
                    gCurrentPinballGame->unk548[i]--;
                }
                else
                {
                    if (gUnknown_086AFAE2[gCurrentPinballGame->unk3A3[i]][0] > gCurrentPinballGame->unk3B0[i])
                    {
                        gCurrentPinballGame->unk3B0[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3B0[i] = 0;
                        gCurrentPinballGame->unk3A3[i]++;
                        if (gCurrentPinballGame->unk3A3[i] == 6)
                            gCurrentPinballGame->unk3A3[i] = 4;
                    }
                }
                break;
            case 2:
                if (gCurrentPinballGame->unk548[i] > 0)
                {
                    gCurrentPinballGame->unk548[i]--;
                }
                else
                {
                    if (gCurrentPinballGame->unk3B0[i] != 0)
                    {
                        gCurrentPinballGame->unk3B0[i]--;
                        gCurrentPinballGame->unk3A3[i] = 8;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3A3[i] = 7;
                    }
                }
                break;
            case 3:
                if (gCurrentPinballGame->unk548[i] > 0)
                {
                    gCurrentPinballGame->unk548[i]--;
                }
                else
                {
                    if (gUnknown_086AFAE2[gCurrentPinballGame->unk3A3[i]][0] > gCurrentPinballGame->unk3B0[i])
                    {
                        gCurrentPinballGame->unk3B0[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3B0[i] = 0;
                        gCurrentPinballGame->unk3A3[i]++;
                        if (gCurrentPinballGame->unk3A3[i] > 14)
                        {
                            gCurrentPinballGame->unk3A3[i] = 4;
                            gCurrentPinballGame->unk3A0[i] = 1;
                        }
                    }
                }
                break;
            }
        }
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        group->baseX = 100 - gCurrentPinballGame->unk58;
        group->baseY = 94 - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk548[0] > 0)
            var0 = 0;
        else
            var0 = gUnknown_086AFAE0[gCurrentPinballGame->unk3A3[0]][0];

        DmaCopy16(3, gUnknown_084B47EC[var0], (void *)0x060114A0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[21];
    if (group->available)
    {
        group->baseX = 140 - gCurrentPinballGame->unk58;
        group->baseY = 94 - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk548[1] > 0)
            var0 = 0;
        else
            var0 = gUnknown_086AFAE0[gCurrentPinballGame->unk3A3[1]][0];

        DmaCopy16(3, gUnknown_084B47EC[var0], (void *)0x06010CA0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_4387C(void)
{
    s16 i;
    s16 j;
    s16 var1;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 sp4;
    s16 var2;
    u16 *dst;
    const u16 *src;
    int var3;
    s16 var4;
    const struct Unk_086AFAC0 *var5;

    if (gCurrentPinballGame->unk13 == 1 && gMain.unkF == 0)
    {
        for (i = 0; i < 2; i++)
        {
            switch (gCurrentPinballGame->unk553[i])
            {
            case 0:
                gCurrentPinballGame->unk553[i] = 1;
                gCurrentPinballGame->unk55B[i] = 0;
                gCurrentPinballGame->unk562[i] = 0;
                gCurrentPinballGame->unk54F[i] = 0;
                gCurrentPinballGame->unk557[i] = -1;
                break;
            case 1:
                if (gCurrentPinballGame->unk562[i] < i * 30 + 120)
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    u16 var0 = gMain.systemFrameCount + Random();
                    gCurrentPinballGame->unk557[i] = var0 % 6;
                    if (gCurrentPinballGame->unk557[0] == gCurrentPinballGame->unk557[1])
                        gCurrentPinballGame->unk557[i] = (gCurrentPinballGame->unk557[i] + 2) % 6;

                    if (gCurrentPinballGame->unk557[i] < 2)
                    {
                        if (gCurrentPinballGame->unk557[i] == 0)
                        {
                            gCurrentPinballGame->unk580[i].x = 0x4900;
                            gCurrentPinballGame->unk580[i].y = 0xAB00;
                            gCurrentPinballGame->unk551[i] = 0;
                        }
                        else
                        {
                            gCurrentPinballGame->unk580[i].x = 0xA700;
                            gCurrentPinballGame->unk580[i].y = 0xAC00;
                            gCurrentPinballGame->unk551[i] = 1;
                        }

                        gCurrentPinballGame->unk55B[i] = 9;
                        gCurrentPinballGame->unk553[i] = 7;
                    }
                    else
                    {
                        gCurrentPinballGame->unk551[i] = (gMain.systemFrameCount + Random()) % 2;
                        if (gCurrentPinballGame->unk551[i])
                        {
                            if (gCurrentPinballGame->unk557[i] == 5)
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 5) + 80) << 8;
                            else
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 2) + 50) << 8;
                        }
                        else
                        {
                            if (gCurrentPinballGame->unk557[i] == 5)
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 5) + 140) << 8;
                            else
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 2) + 140) << 8;
                        }

                        gCurrentPinballGame->unk580[i].y = 0xAF00 + ((gCurrentPinballGame->unk557[i] - 2) * 0xA00);

                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk553[i] = 2;
                    }

                    gCurrentPinballGame->unk562[i] = 0;
                }

                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 2:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 3)
                    {
                        gCurrentPinballGame->unk55B[i] = 3;
                        gCurrentPinballGame->unk553[i] = 3;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 1)
                        m4aSongNumStart(SE_UNKNOWN_0x134);
                }

                gCurrentPinballGame->unk56A[i] = 0;
                gCurrentPinballGame->unk54F[i] = 1;
                break;
            case 3:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 5)
                        gCurrentPinballGame->unk55B[i] = 3;
                }

                if (gCurrentPinballGame->unk56A[i] < 400)
                {
                    gCurrentPinballGame->unk56A[i]++;
                    if (gCurrentPinballGame->unk551[i])
                        gCurrentPinballGame->unk580[i].x += 35;
                    else
                        gCurrentPinballGame->unk580[i].x -= 35;
                }
                else
                {
                    gCurrentPinballGame->unk55B[i] = 6;
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk553[i] = 6;
                }

                gCurrentPinballGame->unk54F[i] = 1;
                break;
            case 4:
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2D28);
                if (gCurrentPinballGame->unk54F[i] == 1)
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i] = 5;
                    gCurrentPinballGame->unk553[i] = 5;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].y + (gCurrentPinballGame->unk55F[i] << 8) < gCurrentPinballGame->ball->positionQ8.y)
                    {
                        gCurrentPinballGame->unk553[i] = 10;
                    }
                    else
                    {
                        gCurrentPinballGame->unk562[i] = 0xAC - (gCurrentPinballGame->unk562[i] * 12) / 0xA0;
                        gCurrentPinballGame->unk553[i] = 8;
                    }
                }

                sub_11B0(7);
                gCurrentPinballGame->unk54F[i] = 0;
                gCurrentPinballGame->unk3C = 3000;
                break;
            case 5:
                if (gCurrentPinballGame->unk562[i] < 10)
                {
                    gCurrentPinballGame->unk562[i]++;
                    gCurrentPinballGame->unk55B[i] = 5;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk553[i] = 6;
                }
                break;
            case 6:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 9)
                    {
                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk553[i] = 0;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 7)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }
                
                gCurrentPinballGame->unk54F[i] = 0;
                
                break;
            case 7:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 14)
                    {
                        gCurrentPinballGame->unk553[i] = 8;
                        gCurrentPinballGame->unk580[i].x += gCurrentPinballGame->unk55D[i] << 8;
                        gCurrentPinballGame->unk580[i].y += gCurrentPinballGame->unk55F[i] << 8;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 10)
                        m4aSongNumStart(SE_UNKNOWN_0x140);

                }
                gCurrentPinballGame->unk54F[i] = 2;
                
                break;
            case 8:
                if (gCurrentPinballGame->unk562[i] < 184)
                {
                    if (gCurrentPinballGame->unk562[i] < 160)
                    {
                        if (gCurrentPinballGame->unk551[i] == 0)
                            gCurrentPinballGame->unk580[i].x -= 0x10;
                        else
                            gCurrentPinballGame->unk580[i].x += 0x10;

                        if (gCurrentPinballGame->unk562[i] & 1)
                            gCurrentPinballGame->unk580[i].y -= 0x10;
                        else
                            gCurrentPinballGame->unk580[i].y -= 0x20;

                        if (gCurrentPinballGame->unk562[i] % 19 < 10)
                            gCurrentPinballGame->unk55B[i] = 14;
                        else
                            gCurrentPinballGame->unk55B[i] = 15;
                    }
                    else
                    {
                        if (gCurrentPinballGame->unk551[i] == 0)
                            gCurrentPinballGame->unk580[i].x += 0x140;
                        else
                            gCurrentPinballGame->unk580[i].x -= 0x140;

                        if (gCurrentPinballGame->unk562[i] & 1)
                            gCurrentPinballGame->unk580[i].y += 0x140;
                        else
                            gCurrentPinballGame->unk580[i].y += 0x1E0;

                        gCurrentPinballGame->unk55B[i] = 15;
                    }

                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk553[i] = 9;
                    gCurrentPinballGame->unk55B[i] = 16;
                    gCurrentPinballGame->unk562[i] = 0;
                    if (gCurrentPinballGame->unk551[i] == 0)
                        gCurrentPinballGame->unk580[i].x += 0xF0;
                    else
                        gCurrentPinballGame->unk580[i].x -= 0xF0;
                }
                break;
            case 9:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 20)
                    {
                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk553[i] = 0;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 17)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }
                break;
            case 10: {
                s16 len;
                if (gCurrentPinballGame->unk551[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                len = gUnknown_086AFAC0[var1].unk4;
                for (j = 0; j < len; j++)
                {
                    if (gUnknown_086AFAC0[var1].unk0[j].y <= gCurrentPinballGame->unk566[i])
                        break;
                }

                gCurrentPinballGame->unk559[i] = j;
                gCurrentPinballGame->unk553[i] = 11;
                gCurrentPinballGame->unk55B[i] = 29;
                gCurrentPinballGame->unk562[i] = 0;
                
                gCurrentPinballGame->unk580[i].x = gUnknown_086AFAC0[var1].unk0[gCurrentPinballGame->unk559[i]].x << 8;
                gCurrentPinballGame->unk580[i].y = gUnknown_086AFAC0[var1].unk0[gCurrentPinballGame->unk559[i]].y << 8;
                
                gCurrentPinballGame->unk559[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            }
            case 11:
                if (gCurrentPinballGame->unk551[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                var4 = gCurrentPinballGame->unk559[i];
                var5 = gUnknown_086AFAC0;
                if (var4 < var5[var1].unk4)
                {
                    gCurrentPinballGame->unk580[i].x = var5[var1].unk0[gCurrentPinballGame->unk559[i]].x << 8;
                    gCurrentPinballGame->unk580[i].y = var5[var1].unk0[gCurrentPinballGame->unk559[i]].y << 8;
                    gCurrentPinballGame->unk559[i]++;
                    if (gCurrentPinballGame->unk559[i] == var5[var1].unk4)
                    {
                        gCurrentPinballGame->unk553[i] = 12;
                        gCurrentPinballGame->unk530[i] = gCurrentPinballGame->unk551[i];
                        gCurrentPinballGame->unk536[i] = 2;
                        if (gCurrentPinballGame->unk551[i] == 0)
                            gCurrentPinballGame->unk578[i].x = 0x140;
                        else
                            gCurrentPinballGame->unk578[i].x = -0x140;

                        gCurrentPinballGame->unk578[i].y = 0x1D0;
                    }
                }

                gCurrentPinballGame->unk55B[i] = ((gCurrentPinballGame->unk562[i] % 32) / 4) + 30;
                gCurrentPinballGame->unk562[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 12:
                gCurrentPinballGame->unk580[i].x += gCurrentPinballGame->unk578[i].x;
                gCurrentPinballGame->unk580[i].y += gCurrentPinballGame->unk578[i].y;
                gCurrentPinballGame->unk55B[i] = ((gCurrentPinballGame->unk562[i] % 32) / 4) + 30;
                gCurrentPinballGame->unk562[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 13:
                gCurrentPinballGame->unk580[i].x += gCurrentPinballGame->unk578[i].x;
                gCurrentPinballGame->unk580[i].y += gCurrentPinballGame->unk578[i].y;
                gCurrentPinballGame->unk55B[i] = ((gCurrentPinballGame->unk562[i] % 32) / 8) + 26;
                gCurrentPinballGame->unk562[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 14:
                gCurrentPinballGame->unk557[i] = -1;
                if (gCurrentPinballGame->unk54D[i] > 0)
                {
                    gCurrentPinballGame->unk54D[i]--;
                    gCurrentPinballGame->unk55B[i] = 38;
                    gCurrentPinballGame->unk54B[i] = 1;
                }
                else
                {
                    if (gCurrentPinballGame->unk562[i] < 334)
                    {
                        if (gCurrentPinballGame->unk562[i] < 16)
                        {
                            gCurrentPinballGame->unk55B[i] = 21;
                            if (gCurrentPinballGame->unk562[i] == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x13E);

                            gCurrentPinballGame->unk54F[i] = 3;
                        }
                        else if (gCurrentPinballGame->unk562[i] < 316)
                        {
                            if (gCurrentPinballGame->unk54B[i] == 0)
                            {
                                gCurrentPinballGame->unk580[i].y += 0x40;
                                if (gCurrentPinballGame->unk562[i] % 19 < 10)
                                    gCurrentPinballGame->unk55B[i] = 22;
                                else
                                    gCurrentPinballGame->unk55B[i] = 23;
                            }
                            else
                            {
                                gCurrentPinballGame->unk580[i].y += 0x80;
                                if (gCurrentPinballGame->unk562[i] % 10 < 5)
                                    gCurrentPinballGame->unk55B[i] = 22;
                                else
                                    gCurrentPinballGame->unk55B[i] = 23;
                            }

                            if (gCurrentPinballGame->unk580[i].y > 0xAC00)
                                gCurrentPinballGame->unk562[i] = 316;

                            gCurrentPinballGame->unk54F[i] = 3;
                        }
                        else
                        {
                            s16 var20;
                            gCurrentPinballGame->unk580[i].y += 0x30;
                            var20 = gCurrentPinballGame->unk562[i] - 316;
                            if (var20 < 10)
                                gCurrentPinballGame->unk55B[i] = 24;
                            else
                                gCurrentPinballGame->unk55B[i] = 25;

                            if (var20 == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x136);

                            gCurrentPinballGame->unk54F[i] = 0;
                        }

                        gCurrentPinballGame->unk562[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->unk553[i] = 0;
                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk562[i] = 0;
                    }
                }
                break;
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[14 + i];
        if (group->available)
        {
            sp4 = gCurrentPinballGame->unk555[i];
            gCurrentPinballGame->unk555[i] = gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][2] + (1 - gCurrentPinballGame->unk551[i]) * 30 ;
            var2 = gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][0];
            
            group->baseX = (gCurrentPinballGame->unk580[i].x / 256) - (gCurrentPinballGame->unk58 + 12);
            group->baseY = (gCurrentPinballGame->unk580[i].y / 256) - (gCurrentPinballGame->unk5A + 14);

            DmaCopy16(3, gUnknown_084B046C[sp4], (void *)0x06011CA0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B56D8[var2][j];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                if (gCurrentPinballGame->unk551[i] == 0)
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->unk55D[i] = -gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->unk55F[i] = gOamBuffer[oamSimple->oamId].y;
                    }
    
                    gOamBuffer[oamSimple->oamId].x += group->baseX + gCurrentPinballGame->unk55D[i] * 2;
                }
                else
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->unk55D[i] = gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->unk55F[i] = gOamBuffer[oamSimple->oamId].y;
                    }
    
                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                }
    
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum += i * 9;
            }

            var3 = 0x10;
            gCurrentPinballGame->unk570[i].x = ((gCurrentPinballGame->unk580[i].x / 256) + (gCurrentPinballGame->unk55D[i] - var3)) * 2;
    
            var3 = 0x12;
            gCurrentPinballGame->unk570[i].y = ((gCurrentPinballGame->unk580[i].y / 256) + (gCurrentPinballGame->unk55F[i] - var3)) * 2;
    
            gCurrentPinballGame->unk566[i] = gCurrentPinballGame->unk580[i].y / 256 + gCurrentPinballGame->unk55F[i];
    
            group = &gMain.spriteGroups[16 + i];
            if (sp4 == 12 || sp4 == 42)
            {
                if (gCurrentPinballGame->unk55B[i] == 11)
                    sp4 = 8;
                else
                    sp4 = 9;
            }
            else
            {
                sp4 = 0;
            }
    
            group->baseX = (gCurrentPinballGame->unk580[i].x / 256) - (gCurrentPinballGame->unk58 + 12);
            group->baseY = (gCurrentPinballGame->unk580[i].y / 256) - (gCurrentPinballGame->unk5A + 14);
    
            DmaCopy16(3, gUnknown_084B046C[sp4], (void *)0x06011EE0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void sub_44D58(void)
{
    s16 i;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = 0;
    group = &gMain.spriteGroups[18];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->unk58;
        group->baseY = 86 - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk542 < 22)
            var0 = gUnknown_08137D60[gCurrentPinballGame->unk542];

        DmaCopy16(3, gUnknown_084AF9EC[var0], (void *)0x06010920, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[11];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->unk58;
        group->baseY = 94 - gCurrentPinballGame->unk5A;
        DmaCopy16(3, gUnknown_084AFFEC[var0], (void *)0x06010B20, 0x180);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->unk13 == 1)
        gMain.spriteGroups[11].available = 1;

    if (gCurrentPinballGame->unk13 < 2 && gMain.unkF == 0 && gCurrentPinballGame->unk542)
    {
        if (gCurrentPinballGame->unk542 == 21)
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2D94);

        gCurrentPinballGame->unk542--;
        if (gCurrentPinballGame->unk542 == 0)
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2E70);
    }

    if (gCurrentPinballGame->unk7E)
    {
        if (gMain.unk5 == 0)
            sub_44F3C();
        else
            sub_45164();
    }
}

void sub_44F3C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const u16 *offsets;
    s16 var0;

    group = &gMain.spriteGroups[19];
    if (group->available)
    {
        offsets = gUnknown_086AFC16[gCurrentPinballGame->unk591];
        group->baseX = 134 + offsets[2] - gCurrentPinballGame->unk58;
        group->baseY = 154 + offsets[3] - gCurrentPinballGame->unk5A;
        var0 = offsets[0];
        DmaCopy16(3, gUnknown_084B7FEC[var0], (void *)0x06012120, 0x460);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gUnknown_086AFC16[gCurrentPinballGame->unk591][1] > gCurrentPinballGame->unk592)
    {
        gCurrentPinballGame->unk592++;
    }
    else
    {
        gCurrentPinballGame->unk592 = 0;
        gCurrentPinballGame->unk591++;
        if (gCurrentPinballGame->unk591 == 1)
            gMain.spriteGroups[19].available = 1;

        if (gCurrentPinballGame->unk591 == 19)
        {
            gCurrentPinballGame->unk591 = 18;
            gMain.spriteGroups[19].available = 0;
            gCurrentPinballGame->unk7E = 0;
        }

        if (gCurrentPinballGame->unk591 == 9)
        {
            gCurrentPinballGame->ball->unkA -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8D00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC800;
            gCurrentPinballGame->ball->velocity.x = -0x60;
            gCurrentPinballGame->ball->velocity.y = 0x54;
            gCurrentPinballGame->ball->unk1 = 3;
            sub_11B0(7);
        }

        if (gCurrentPinballGame->unk591 == 2)
            m4aSongNumStart(SE_UNKNOWN_0xD3);

        if (gCurrentPinballGame->unk591 == 15)
            m4aSongNumStart(SE_UNKNOWN_0xD4);

        if (gCurrentPinballGame->unk591 == 8)
        {
            m4aSongNumStart(SE_UNKNOWN_0xD6);
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->ball->unkA -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8F00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC300;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        if (gCurrentPinballGame->unk591 == 10)
            gCurrentPinballGame->unk1F = 0;
    }
}

void sub_45164(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[20];
    if (group->available)
    {
        group->baseX = (gCurrentPinballGame->unk320 / 10) - (gCurrentPinballGame->unk58 - 146);
        group->baseY = (gCurrentPinballGame->unk322 / 10) - (gCurrentPinballGame->unk5A - 110) + (gCurrentPinballGame->unk30E / 10);
        index = gCurrentPinballGame->unk591;
        DmaCopy16(3, gUnknown_084BB16C[index], (void *)0x060125A0, 0x480);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->unk592 <= 250)
    {
        if (gCurrentPinballGame->unk592 == 250)
        {
            gCurrentPinballGame->unk320 = 920;
            gCurrentPinballGame->unk322 = -100;
            gCurrentPinballGame->unk31C = -82;
            gCurrentPinballGame->unk31E = 0;
            gCurrentPinballGame->unk30C = 0;
            gCurrentPinballGame->unk306 = 8;
            gCurrentPinballGame->unk591 = 13;
            gMain.spriteGroups[20].available = 1;
            gCurrentPinballGame->unk5FA = 1;
        }
    }
    else
    {
        gCurrentPinballGame->unk591 = (gCurrentPinballGame->unk30C % 24) / 6 + 13;
        gCurrentPinballGame->unk30E = (Sin(gCurrentPinballGame->unk30C * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->unk30C == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->unk30C < 40)
        {
            gCurrentPinballGame->unk320 += gCurrentPinballGame->unk31C;
            gCurrentPinballGame->unk322 += gCurrentPinballGame->unk31E;
        }
        else
        {
            gMain.spriteGroups[20].available = 0;
        }

        if (gCurrentPinballGame->unk30C == 13)
        {
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk314 = -10;
            gCurrentPinballGame->unk316 = -25;
            gCurrentPinballGame->unk318 = ((gCurrentPinballGame->unk320 / 10) + 157) * 10;
            gCurrentPinballGame->unk31A = ((gCurrentPinballGame->unk322 / 10) + 134) * 10;
            gCurrentPinballGame->ball->unk1 = 1;
        }

        if (gCurrentPinballGame->unk1F)
        {
            if (gCurrentPinballGame->unk30C < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = (gCurrentPinballGame->unk320 / 10) + 157;
                gCurrentPinballGame->ball->positionQ0.y = (gCurrentPinballGame->unk322 / 10) + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->unk316 += 2;
                gCurrentPinballGame->unk318 += gCurrentPinballGame->unk314;
                gCurrentPinballGame->unk31A += gCurrentPinballGame->unk316;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->unk318 / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->unk31A / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 181)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 181;
                    gCurrentPinballGame->unk5F7 = 0;
                    gCurrentPinballGame->unk1F = 0;
                    gCurrentPinballGame->ball->velocity.x = -10;
                    gCurrentPinballGame->ball->velocity.y = 0;
                    gCurrentPinballGame->unk5FA = 0;
                    gCurrentPinballGame->ball->unk1 = 3;
                    gCurrentPinballGame->unk24 = 0;
                    gCurrentPinballGame->unk7E = 0;
                    m4aSongNumStart(SE_UNKNOWN_0xE5);
                    sub_11B0(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        gCurrentPinballGame->unk30C++;
    }

    gCurrentPinballGame->unk592++;
}

void sub_455D0(void)
{
    s16 i;
    s16 var0;

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->unk536[i])
        {
        case 0:
            gCurrentPinballGame->unk530[i] = 0;
            break;
        case 1:
            var0 = gCurrentPinballGame->unk530[i];
            gCurrentPinballGame->unk3A0[var0] = 2;
            gCurrentPinballGame->unk3B0[var0] = 0;
            gCurrentPinballGame->unk3A3[var0] = 7;
            if (gCurrentPinballGame->unk53C[i])
            {
                gCurrentPinballGame->unk53C[i]--;
                if (gCurrentPinballGame->unk53C[i] == 0)
                {
                    gCurrentPinballGame->unk536[i] = 0;
                    gCurrentPinballGame->unk3A0[var0] = 1;
                    gCurrentPinballGame->unk3B0[var0] = 0;
                    gCurrentPinballGame->unk3A3[var0] = 4;
                }
            }
            break;
        case 2:
            var0 = gCurrentPinballGame->unk530[i];
            if (i == 2)
            {
                gCurrentPinballGame->unk1F = 1;
                gCurrentPinballGame->ball->velocity.x += 5 - var0 * 10;
            }

            gCurrentPinballGame->unk536[i] = 3;
            gCurrentPinballGame->unk533[i] = 0;
            gCurrentPinballGame->unk3A0[var0] = 2;
            gCurrentPinballGame->unk3B0[var0] = 0;
            gCurrentPinballGame->unk3A3[var0] = 7;
            break;
        case 3:
            var0 = gCurrentPinballGame->unk530[i];
            if (i < 2)
            {
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->unk580[i].x >= 0x5600)
                        gCurrentPinballGame->unk578[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].x <= 0x9C00)
                        gCurrentPinballGame->unk578[i].x = 0;

                }

                gCurrentPinballGame->unk578[i].y += 12;
                if (gCurrentPinballGame->unk548[var0] > 0)
                {
                    if (gCurrentPinballGame->unk580[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->unk533[i] = 0;
                        gCurrentPinballGame->unk536[i] = 5;
                        gCurrentPinballGame->unk3A0[var0] = 3;
                        gCurrentPinballGame->unk3A3[var0] = 15;
                        gCurrentPinballGame->unk3B0[var0] = 0;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->unk533[i]++;
                        MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2EE4);
                        if (gCurrentPinballGame->unk533[i] < 3)
                        {
                            gCurrentPinballGame->unk580[i].y = 0x6600;
                            gCurrentPinballGame->unk578[i].y = 0xFED4;
                            gCurrentPinballGame->unk553[i] = 13;
                            gCurrentPinballGame->unk3A0[var0] = 2;
                            gCurrentPinballGame->unk3A3[var0] = 8;
                            gCurrentPinballGame->unk3B0[var0] = 12;
                        }
                        else
                        {
                            gCurrentPinballGame->unk578[i].x = (30 - var0 * 60) * 4;
                            gCurrentPinballGame->unk578[i].y = 0xFE70;
                            gCurrentPinballGame->unk533[i] = 0;
                            gCurrentPinballGame->unk536[i] = 4;
                            gCurrentPinballGame->unk3A0[var0] = 3;
                            gCurrentPinballGame->unk3A3[var0] = 11;
                            gCurrentPinballGame->unk3B0[var0] = 0;
                            gCurrentPinballGame->unk542 = 100;
                            gCurrentPinballGame->unk52C[0]++;
                        }
                    }
                }
            }
            else
            {
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x5600)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x9C00)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                gCurrentPinballGame->ball->velocity.y += 3;
                if (gCurrentPinballGame->ball->positionQ8.y >= 0x6500)
                {
                    gCurrentPinballGame->unk533[i]++;
                    MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A2EE4);
                    sub_11B0(7);
                    if (gCurrentPinballGame->unk533[i] < 3)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x6500;
                        gCurrentPinballGame->ball->velocity.y = -0x5A;
                        gCurrentPinballGame->unk3A0[var0] = 2;
                        gCurrentPinballGame->unk3A3[var0] = 8;
                        gCurrentPinballGame->unk3B0[var0] = 12;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.x = 28 - var0 * 56;
                        gCurrentPinballGame->ball->velocity.y = -0x78;
                        gCurrentPinballGame->unk533[i] = 0;
                        gCurrentPinballGame->unk536[i] = 4;
                        gCurrentPinballGame->unk3A0[var0] = 3;
                        gCurrentPinballGame->unk3A3[var0] = 11;
                        gCurrentPinballGame->unk3B0[var0] = 0;
                        gCurrentPinballGame->unk542 = 106;
                        gCurrentPinballGame->unk52C[1]++;
                    }
                }
            }
            break;
        case 4:
            var0 = gCurrentPinballGame->unk530[i];
            if (i < 2)
            {
                gCurrentPinballGame->unk578[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->unk580[i].x >= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].x <= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }

                if (gCurrentPinballGame->unk580[i].y >= 0x8400)
                {
                    gCurrentPinballGame->unk536[i] = 0;
                    gCurrentPinballGame->unk553[i] = 14;
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk54B[i] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->velocity.y += 3;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8400)
                {
                    gCurrentPinballGame->unk533[i]++;
                    if (gCurrentPinballGame->unk533[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8400;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                        if (gCurrentPinballGame->unk533[i] == 1)
                            sub_11B0(7);
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->unk1F = 0;
                        gCurrentPinballGame->unk536[i] = 0;
                    }
                }
            }
            break;
        case 5:
            var0 = gCurrentPinballGame->unk530[i];
            if (i < 2)
            {
                gCurrentPinballGame->unk578[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->unk580[i].x >= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].x <= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }

                if (gCurrentPinballGame->unk580[i].y >= 0x8E00)
                {
                    gCurrentPinballGame->unk536[i] = 0;
                    gCurrentPinballGame->unk553[i] = 14;
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk54B[i] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->velocity.y += 3;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8E00)
                {
                    gCurrentPinballGame->unk533[i]++;
                    if (gCurrentPinballGame->unk533[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8E00;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->unk1F = 0;
                        gCurrentPinballGame->unk536[i] = 0;
                    }
                }
            }
            break;
        }
    }
}

void sub_45E08(void)
{
    s16 i;
    s16 var0;

    var0 = gUnknown_086AEED6[(gMain.systemFrameCount % 96) / 24];
    for (i = 0x100; i < 0x400; i++)
        gUnknown_03005C00[0x800 + i] = gUnknown_0837A4E8[i] + var0 * 4;

    DmaCopy16(3, &gUnknown_03005C00[0x800], (void *)0x06000000, 0x800);
}

void sub_45E90(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int value;
    s16 sp0[12];
    s16 sp18[12];

    if (gCurrentPinballGame->unk13 > 3)
    {
        if (gCurrentPinballGame->unk394 > -126)
        {
            gCurrentPinballGame->unk394 -= 6;
            gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->unk394 + 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk394 < 0)
        {
            gCurrentPinballGame->unk394 += 6;
            if (gCurrentPinballGame->unk394 > 0)
                gCurrentPinballGame->unk394 = 0;
        }

        gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->unk394 + 4;
    }

    if (gCurrentPinballGame->unk13 < 5)
    {
        gMain.blendControl = 0x1C42;
        gMain.blendAlpha = 0xC04;
    }

    if (gCurrentPinballGame->unk13 == 3)
    {
        if (gCurrentPinballGame->unk18)
            gCurrentPinballGame->unk18 += 0;
    }

    if (gCurrentPinballGame->unk53A > 100 && gCurrentPinballGame->unk53A < 450)
    {
        if (gCurrentPinballGame->unk52E[0] != gCurrentPinballGame->unk52C[0])
        {
            if ((gCurrentPinballGame->unk53A % 3) == 0)
            {
                gCurrentPinballGame->unk52E[0]++;
                m4aSongNumStart(SE_UNKNOWN_0x91);
            }
        }
        else
        {
            gCurrentPinballGame->unk53A = 490;
        }
    }

    if (gCurrentPinballGame->unk53A > 500 && gCurrentPinballGame->unk53A < 800)
    {
        if (gCurrentPinballGame->unk52E[1] != gCurrentPinballGame->unk52C[1])
        {
            if ((gCurrentPinballGame->unk53A % 3) == 0)
            {
                gCurrentPinballGame->unk52E[1]++;
                m4aSongNumStart(SE_UNKNOWN_0x91);
            }
        }
        else
        {
            gCurrentPinballGame->unk53A = 800;
        }
    }

    if (gCurrentPinballGame->unk53A < 800 && gCurrentPinballGame->unk18 > 160)
        gCurrentPinballGame->unk18 = 160;

    gCurrentPinballGame->unk53A++;

    group = &gMain.spriteGroups[7];
    if (!group->available)
        return;

    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 22; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    value = gCurrentPinballGame->unk52E[0] * 5000000;
    sp0[0] = value / 10000000;
    sp0[1] = (value % 10000000) / 1000000;
    sp0[2] = 10;
    sp0[3] = (value % 1000000) / 100000;
    sp0[4] = (value % 100000) / 10000;
    sp0[5] = (value % 10000) / 1000;
    sp0[6] = 10;
    sp0[7] = (value % 1000) / 100;
    sp0[8] = (value % 100) / 10;
    sp0[9] = value % 10;
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->unk52E[0];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[8];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->unk52E[1] * 1000000;
    sp0[0] = value / 10000000;
    sp0[1] = (value % 10000000) / 1000000;
    sp0[2] = 10;
    sp0[3] = (value % 1000000) / 100000;
    sp0[4] = (value % 100000) / 10000;
    sp0[5] = (value % 10000) / 1000;
    sp0[6] = 10;
    sp0[7] = (value % 1000) / 100;
    sp0[8] = (value % 100) / 10;
    sp0[9] = value % 10;
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->unk52E[1];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[9];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->unk52E[0] * 5000000
          + gCurrentPinballGame->unk52E[1] * 1000000;
    gCurrentPinballGame->unk544 = value;
    sp0[0] = value / 100000000;
    sp0[1] = (value % 100000000) / 10000000;
    sp0[2] = (value % 10000000) / 1000000;
    sp0[3] = 10;
    sp0[4] = (value % 1000000) / 100000;
    sp0[5] = (value % 100000) / 10000;
    sp0[6] = (value % 10000) / 1000;
    sp0[7] = 10;
    sp0[8] = (value % 1000) / 100;
    sp0[9] = (value % 100) / 10;
    sp0[10] = value % 10;
    for (i = 0; i < 10; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;
    sp18[10] = sp0[10] * 2 + 0x2D0;
    value = gCurrentPinballGame->unk5F6 + 1;
    sp0[0] = value;
    sp18[11] = sp0[0] * 2 + 0x2D0;

    group = &gMain.spriteGroups[10];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }
}

void sub_467F4(void)
{
    struct Unk02031520 *dest = &gUnknown_02031520;
    const struct Unk02031520_unk14 *src = gUnknown_086AFD70;
    memcpy(&dest->unk14, &src[gMain.selectedField], sizeof(dest->unk14));

    switch (gMain.selectedField)
    {
	case FIELD_RUBY:
        DmaCopy16(3, gUnknown_081BFEE4, (void *)BG_PLTT, BG_PLTT_SIZE);
        DmaCopy16(3, gUnknown_08265C10, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_0826DC10, (void *)0x06003000, 0x1000);
        LZ77UnCompWram(gUnknown_0824C1E4, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0824DD60, gUnknown_0200FBB0);
        LZ77UnCompWram(gUnknown_08250934, gUnknown_020030A0);
        DmaCopy16(3, &gUnknown_0200FBB0[0xC00], (void *)0x0600B400, 0x2400);
        DmaCopy16(3, &gUnknown_0200FBB0[0x3000], (void *)0x06008000, 0x3400);
        DmaCopy16(3, gUnknown_081C08E4, (void *)BG_VRAM, 0x1000);
        DmaCopy16(3, gUnknown_0822E424, (void *)0x06001000, 0x1000);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_0845A48C, (void *)0x06010000, 0x8000);
        break;
	case FIELD_SAPPHIRE:
        DmaCopy16(3, gUnknown_0826EC10, (void *)BG_PLTT, BG_PLTT_SIZE);
        DmaCopy16(3, gUnknown_082E4EE0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_082ECEE0, (void *)0x06003000, 0x1000);
        LZ77UnCompWram(gUnknown_082D34D0, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_082D523C, gUnknown_0200FBB0);
        LZ77UnCompWram(gUnknown_082D8998, gUnknown_020030A0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x0600A800, 0x3000);
        DmaCopy16(3, &gUnknown_0200FBB0[0x3000], (void *)0x06008000, 0x2800);
        DmaCopy16(3, gUnknown_0826EE10, (void *)BG_VRAM, 0x1000);
        DmaCopy16(3, gUnknown_082AE6D0, (void *)0x06001000, 0x1000);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_0845F9EC, (void *)0x06010000, 0x8000);
        break;
	case FIELD_DUSCLOPS:
        DmaCopy16(3, gUnknown_082EDEE0, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_08303928, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_082EE4C0, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_08301700, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_08301F00, (void *)0x06001000, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_08464F4C, (void *)0x06010000, 0x8000);
        break;
	case FIELD_KECLEON:
        DmaCopy16(3, gUnknown_0830CBD4, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0832A194, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_08329994, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_0830CDD4, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_08327994, (void *)0x06001000, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_084675EC, (void *)0x06010000, 0x8000);
        break;
	case FIELD_KYOGRE:
        DmaCopy16(3, gUnknown_08332E04, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0833E044, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_08333004, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_0833D844, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_0846A40C, (void *)0x06010000, 0x8000);
        break;
	case FIELD_GROUDON:
        DmaCopy16(3, gUnknown_08352BD8, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_08353DD8, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_08352DD8, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_083535D8, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_0846D2AC, (void *)0x06010000, 0x8000);
        break;
	case FIELD_RAYQUAZA:
        DmaCopy16(3, gUnknown_08363EC8, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_08370808, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_083640C8, (void *)0x06000000, 0x1000);
        DmaCopy16(3, gUnknown_0836F808, (void *)0x06001000, 0x1000);
        DmaCopy16(3, gUnknown_0836E808, (void *)0x06003000, 0x1000);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_08472A6C, (void *)0x06010000, 0x8000);
        break;
	case FIELD_SPHEAL:
        DmaCopy16(3, gUnknown_0837A2E8, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0838E828, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_0837A4E8, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_0838E028, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_084779EC, (void *)0x06010000, 0x8000);
        break;
    }

    gUnknown_02031520.unk68 = gUnknown_0816C3E4;
}

void sub_46FD4(s16 arg0)
{
    gUnknown_02031520.unk14.unk38[0] = gUnknown_086AFCB0[gMain.selectedField][arg0].unk0;
    gUnknown_02031520.unk14.unk48[0] = gUnknown_086AFCB0[gMain.selectedField][arg0].unk10;
    gUnknown_02031520.unk14.unk58[0] = gUnknown_086AFCB0[gMain.selectedField][arg0].unk20;
}

void sub_47030(void)
{
    s16 r4;
    const s16 *r3;

    r4 = gMain.bgOffsets[3].yOffset / 8;
    r3 = gUnknown_086B0010[r4];
    if (r4 == gCurrentPinballGame->unk64)
        return;

    if (r4 > gCurrentPinballGame->unk64)
    {
        if (r3[0] > 31)
        {
            DmaCopy16(3, &gUnknown_020030A0[(r3[0] - 32) * 0x400], (void *)0x06008000 + r3[1] * 0x400, 0x400);
        }
        else
        {
            DmaCopy16(3, &gUnknown_0200FBB0[r3[0] * 0x400], (void *)0x06008000 + r3[1] * 0x400, 0x400);
        }
    }
    else
    {
        if (r3[2] > 31)
        {
            DmaCopy16(3, &gUnknown_020030A0[(r3[2] - 32) * 0x400], (void *)0x06008000 + r3[3] * 0x400, 0x400);
        }
        else
        {
            DmaCopy16(3, &gUnknown_0200FBB0[r3[2] * 0x400], (void *)0x06008000 + r3[3] * 0x400, 0x400);
        }
    }

    gCurrentPinballGame->unk64 = r4;
}

void sub_47100(void)
{
    gCurrentPinballGame->unkFC = 128;
}

void sub_47110(void)
{
    s16 i;

    for (i = 0; i < 0x800; i++)
        gUnknown_03005C00[i] = 0x1FF;

    DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x1000);
}

void sub_47160(void)
{
    if (JOY_NEW(START_BUTTON) && gMain.mainState != STATE_GAME_IDLE && gCurrentPinballGame->unk1100 == 0)
    {
        if (gMain.unkF & 0x2)
        {
            gMain.unkF &= ~0x2;
            sub_497BC();
        }
        else if ((gMain.unkF & 0x20) == 0)
        {
            gMain.unkF |= 0x2;
            sub_495A0();
        }
    }

    if (gMain.unkF & 0x2)
    {
        if (JOY_NEW(DPAD_UP))
        {
            gCurrentPinballGame->unk1104 ^= 1;
            m4aSongNumStart(SE_UNKNOWN_0xA3);
        }

        if (JOY_NEW(DPAD_DOWN))
        {
            gCurrentPinballGame->unk1104 ^= 1;
            m4aSongNumStart(SE_UNKNOWN_0xA3);
        }

        if (JOY_NEW(A_BUTTON) && !JOY_HELD(B_BUTTON | SELECT_BUTTON | START_BUTTON))
        {
            if (gCurrentPinballGame->unk1104 == 0)
            {
                gMain.unkE = 2;
                sub_49850();
            }

            gMain.unkF &= ~0x2;
            sub_497BC();
            gMain.newKeys &= ~A_BUTTON;
        }

        if (JOY_NEW(B_BUTTON))
        {
            gMain.unkF &= ~0x2;
            sub_497BC();
            gMain.newKeys &= ~B_BUTTON;
        }

        if (gMain.unkF & 0x2)
            sub_49A34();
    }

    if (gMain.unkF == 0x0)
    {
        gCurrentPinballGame->unk740 = 0;
        if (gMain.unk14 != 0)
        {
            gMain.unk14--;
            if (gMain.unk14 == 1)
            {
                if (gCurrentPinballGame->unkE4)
                    gMain.unk14 = 10;
                else if (gMain.unk11 == 0x8)
                    gCurrentPinballGame->unkE4 = 19;
                else
                    gCurrentPinballGame->unkE4 = 20;
            }

            if (gMain.unk14 == 0)
                gMain.unkF = gMain.unk11;
        }
    }
}

// Handle debug system flags
void sub_472E4(void)
{
    if (gMain.unkF == 0x0)
        return;

    if (gMain.unkF & 0x8)
    {
        // instantly reset ball
        sub_478D8();
        return;
    }

    if (gMain.unkF & 0x10)
    {
        // lose life, and reset ball
        sub_47670();
        return;
    }

    if (gMain.unkF & 0x20)
    {
        // end game
        sub_474F4();
        return;
    }

    if (gMain.unkF & 0x4)
    {
        // debug tool (move ball position, and change ball speed)
        sub_47344();
        gCurrentPinballGame->unk740 = gMain.unk10 + 1;
        return;
    }
}

// Debug menu that lets you move the ball's position and change ball speed.
// However, the menu text rendering is only half-implemented--the second
// menu item is for changing the ball's speed (toggling between fast and slow),
// but there is no indication of happening on-screen.
void sub_47344(void)
{
    int i;
    u8 str0[42];
    u8 str1[24];

    memcpy(str0, gUnknown_08137DBE, 42);
    memcpy(str1, gUnknown_08137DE8, 24);

    for (i = 0x340; i < 0x380; i++)
        gUnknown_03005C00[i] = 0;

    sub_06CC(gCurrentPinballGame->ball->positionQ0.x, &str1[1], 3, 1);
    sub_06CC(gCurrentPinballGame->ball->positionQ0.y, &str1[5], 3, 1);
    sub_0678(&str1[0], 26, 9);
    sub_06CC(gCurrentPinballGame->unk68, &str1[13], 3, 1);
    sub_0678(&str1[12], 26, 18);
    sub_0678(str0, 26, 0);

    if (JOY_HELD(B_BUTTON))
    {
        if (gMain.systemFrameCount & 0x8)
            sub_0678(gUnknown_08137E00, gMain.unk10 + 26, 0);

        if (JOY_NEW(DPAD_UP) && gMain.unk10 != 0)
            gMain.unk10--;

        if (JOY_NEW(DPAD_DOWN) && gMain.unk10 == 0)
            gMain.unk10++;

        if (gCurrentPinballGame->unk740 == 2)
            sub_48124();
    }
    else
    {
        switch (gCurrentPinballGame->unk740)
        {
        case 1:
            sub_47FF8();
            break;
        case 2:
            sub_48124();
            break;
        }

        sub_0678(gUnknown_08137E00, gMain.unk10 + 26, 0);
    }

    for (i = 0x340; i < 0x380; i++)
        gUnknown_03005C00[i] += 0xC100;

    DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x800);
    if (JOY_HELD(A_BUTTON))
        sub_47FBC();
}

void sub_474F4(void)
{
    int i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 var0;

    group = gMain.unk44[42];
    if (group->available)
    {
        group->baseX = 63;
        group->baseY = 52;
        for (i = 0; i < 8; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    var0 = gMain.systemFrameCount * 0x1000;
    for (i = 0; i < 8; i++)
    {
        gUnknown_02031500[i] = (gUnknown_02030750[i] * Cos(var0)) / 200;
        if ((gMain.systemFrameCount & 1) == 0)
        {
            gUnknown_02030750[i]++;
            if (gUnknown_02030750[i] >= 0)
                gUnknown_02030750[i] = 0;
        }
    }

    if (gMain.unk12 == 3600)
    {
        DmaCopy16(3, gUnknown_08509F4C, (void *)0x06015800, 0x400);
        gMain.unk44[42]->available = 1;
        for (i = 0; i < 8; i++)
        {
            gUnknown_02031500[i] = 0xE0C0;
            gUnknown_020306C0[i] = 0;
            gUnknown_02030750[i] = (Random() % 30) + 0xFFCE;
        }
    }

    if (gMain.unk12)
    {
        gMain.unk12--;
        if (gMain.unk12 == 0)
            gCurrentPinballGame->unk1D = 2;
    }

    if (JOY_NEW(A_BUTTON))
        gCurrentPinballGame->unk1D = 2;
}

void sub_47670(void)
{
    s16 i, j;
    u8 var0;

    if (gMain.unk12)
    {
        if (gMain.unk12 < 21)
        {
            if (gMain.unk12 == 20)
                m4aSongNumStart(SE_UNKNOWN_0xA4);

            if (gCurrentPinballGame->unkFC < 128)
                gCurrentPinballGame->unkFC += 8;
        }
        else
        {
            if (gCurrentPinballGame->unkFC > 0)
                gCurrentPinballGame->unkFC -= 8;
        }

        sub_48190();
        gMain.unk12--;
        if (gMain.unk12 == 199)
        {
            gCurrentPinballGame->unkFC = 128;
            gMain.spriteGroups[9].available = 1;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[7].available = 1;
            gMain.spriteGroups[8].available = 1;
            DmaCopy16(3, gUnknown_0850398C, (void *)0x6015800, 0x2800);
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gUnknown_08521FAC, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_08521FCC, (void *)0x050003C0, 0x20);
            }

            m4aSongNumStart(SE_UNKNOWN_0xA4);
            for (i = 0; i < 3; i++)
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[i][j] = 0;            
        }
        else if (gMain.unk12 == 1)
        {
            gMain.spriteGroups[9].available = 0;
            gMain.spriteGroups[6].available = 0;
            gMain.spriteGroups[7].available = 0;
            gMain.spriteGroups[8].available = 0;
        }
    }
    else
    {
        gMain.unkF &= 0xEF;
        sub_47FBC();
        if (gCurrentPinballGame->numLives > 0)
        {
            gCurrentPinballGame->unk724 = 1800;
            gCurrentPinballGame->numLives--;
            gCurrentPinballGame->unk26 = 60;
            gCurrentPinballGame->unk62A = 0;
            gCurrentPinballGame->unk62B = 0;
            gCurrentPinballGame->unk62C = 0;
            gCurrentPinballGame->unk62D = 0;
            gCurrentPinballGame->unk62E = 0;
            gCurrentPinballGame->unk62F = 0;
            sub_11C14(0);
            sub_46FD4(0);
            gCurrentPinballGame->unk29E = 0;
            if (gCurrentPinballGame->unk13 == 3)
            {
                var0 = gCurrentPinballGame->numCompletedBonusStages % 5;
                switch (var0)
                {
                case 0:
                case 2:
                    m4aSongNumStart(MUS_BONUS_CHANCE);
                    break;
                case 1:
                case 3:
                case 4:
                    m4aSongNumStart(MUS_BONUS_CHANCE_LEGENDARY);
                    break;
                }
            }
            else
            {
                sub_19B64(1);
            }

            gCurrentPinballGame->unkE4 = 0;
        }
        else
        {
            gMain.unkF |= 0x20;
            gMain.unk12 = 3600;
            m4aSongNumStart(MUS_GAME_OVER);
        }
    }
}

void sub_478D8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int newX, newY;
    s16 mat3Scale;
    s16 mat4Scale;

    if (gMain.unk12)
    {
        group = &gMain.spriteGroups[5];
        if (group->available)
        {
            group->baseX = 88;
            group->baseY = 20 + gCurrentPinballGame->unkFE;
            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 3;
            }
        }

        group = &gMain.spriteGroups[4];
        if (group->available)
        {
            group->baseX = 24 + gCurrentPinballGame->unk100 / 100;
            group->baseY = gCurrentPinballGame->unkFE + 20 + gCurrentPinballGame->unk104 / 100;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 4;
        }

        group = &gMain.spriteGroups[3];
        if (group->available)
        {
            group->baseX = 56 + gCurrentPinballGame->unk100 / 100;
            group->baseY = gCurrentPinballGame->unkFE + 52 + gCurrentPinballGame->unk104 / 100;
            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        gMain.unk12--;
        if (gMain.unk12 > 70)
        {
            int var0 = (gMain.unk12 + 20) % 0x40;
            gCurrentPinballGame->unk104 = (Sin(var0 * 0x400) * 500) / 20000;
            gCurrentPinballGame->unk108 = 10;
            gCurrentPinballGame->unk10A = 400;
        }
        else
        {
            gCurrentPinballGame->unk108 = 400;
            gCurrentPinballGame->unk10A -= 35;
            gCurrentPinballGame->unk100 += gCurrentPinballGame->unk108;
            gCurrentPinballGame->unk104 += gCurrentPinballGame->unk10A;
        }

        if (gMain.unk12 >= 30 && gMain.unk12 < 60)
        {
            mat4Scale = (60 - gMain.unk12) * 0x100 / 30 + 0x100;
        }
        else
        {
            mat4Scale = 0x100;
            if (gMain.unk12 < 30)
                gMain.spriteGroups[4].available = 0;
        }

        if (gMain.unk12 < 31)
        {
            if (gMain.unk12 > 10)
            {
                mat3Scale = ((gMain.unk12 - 10) * 248) / 20 + 8;
            }
            else
            {
                mat3Scale = 8;
                gMain.spriteGroups[5].available = 0;
            }
        }
        else
        {
            if (gCurrentPinballGame->unkFE > 0)
            {
                gCurrentPinballGame->unkFE -= 8;
                if (gCurrentPinballGame->unkFE < 0)
                    gCurrentPinballGame->unkFE = 0;
            }

            mat3Scale = 0x100;
        }

        if (gMain.unk12 < 203)
        {
            if (gMain.unk12 > 55)
            {
                gCurrentPinballGame->unk10C = gCurrentPinballGame->unk108;
                gCurrentPinballGame->unk10E = gCurrentPinballGame->unk10A - 90;
                gCurrentPinballGame->unk110 = gCurrentPinballGame->unk100;
                gCurrentPinballGame->unk114 = gCurrentPinballGame->unk104;
                if (gMain.unk12 == 56)
                    m4aSongNumStart(SE_UNKNOWN_0x95);

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->unk110 / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unkFE + 372 + gCurrentPinballGame->unk114 / 100) << 8;
            }
            else if (gMain.unk12 > 31)
            {
                gCurrentPinballGame->unk10E += 6;
                gCurrentPinballGame->unk110 += gCurrentPinballGame->unk10C;
                gCurrentPinballGame->unk114 += gCurrentPinballGame->unk10E;
                gMain.spriteGroups[3].available = 0;
                if (gMain.unk12 == 32)
                {
                    gCurrentPinballGame->unk5FA = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x96);
                    sub_11B0(6);
                }

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->unk110 / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unkFE + 372 + gCurrentPinballGame->unk114 / 100) << 8;
            }
            else
            {
                gCurrentPinballGame->unk10C = 0;
                gCurrentPinballGame->unk10E += 20;
                gCurrentPinballGame->unk110 += gCurrentPinballGame->unk10C;
                gCurrentPinballGame->unk114 += gCurrentPinballGame->unk10E;
                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->unk110 / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unkFE + 372 + gCurrentPinballGame->unk114 / 100) << 8;
                if (gCurrentPinballGame->ball->positionQ8.y > 0x17100)
                    gCurrentPinballGame->ball->positionQ8.y = 0x17100;
            }

            gCurrentPinballGame->ball->unk1 = 0;
            gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;

            newX = gCurrentPinballGame->ball->positionQ8.x;
            if (newX < 0)
                newX += 0x7F;
            gCurrentPinballGame->ball->positionQ1.x = newX >> 7;

            newY = gCurrentPinballGame->ball->positionQ8.y;
            if (newY < 0)
                newY += 0x7F;
            gCurrentPinballGame->ball->positionQ1.y = newY >> 7;

            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        SetMatrixScale(0x100, mat3Scale, 3);
        SetMatrixScale(mat4Scale, mat4Scale, 4);

        if (gMain.unk12 == 203)
        {
            gCurrentPinballGame->unk100 = 0;
            gCurrentPinballGame->unk104 = 0;
            gCurrentPinballGame->unk108 = 0;
            gCurrentPinballGame->unk10A = 0;
            gCurrentPinballGame->unkFE = 100;
            gMain.spriteGroups[5].available = 1;
            gMain.spriteGroups[4].available = 1;
            gMain.spriteGroups[3].available = 1;
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gUnknown_0850100C, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_085028CC, (void *)0x06016800, 0x800);
                DmaCopy16(3, gUnknown_085038CC, (void *)0x06017000, 0xC0);
                DmaCopy16(3, gUnknown_08514F4C, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_0850100C, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_08514F6C, (void *)0x050003C0, 0x20);
            }

            gCurrentPinballGame->unk1F = 2;
            gCurrentPinballGame->unk5FA = 1;
            gCurrentPinballGame->unk5F7 = 1;
            gCurrentPinballGame->unk1100 = 1;
            m4aSongNumStart(SE_UNKNOWN_0x94);
        }
        else if (gMain.unk12 == 0)
        {
            gMain.spriteGroups[5].available = 0;
            gMain.spriteGroups[4].available = 0;
        }
    }
    else
    {
        gMain.unkF &= 0xF7;
        gCurrentPinballGame->unk26 = 60;
        sub_11C14(0);
        gCurrentPinballGame->unk1F = 0;
        sub_46FD4(0);
        gCurrentPinballGame->unk29E = 0;
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->ball->unk1 = 3;
        else
            gCurrentPinballGame->ball->unk1 = 1;

        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->unkE4 = 0;
        gCurrentPinballGame->unk1100 = 0;
    }
}

void sub_47FBC(void)
{
    int i;
    for (i = 0x340; i < 0x380; i++)
        gUnknown_03005C00[i] = 0x1FF;

    DmaCopy16(3, gUnknown_03005C00, (void *)0x6002000, 0x800);
}

void sub_47FF8(void)
{
    int newX, newY;

    if (JOY_HELD(A_BUTTON))
    {
        if (JOY_HELD(DPAD_UP))
            gCurrentPinballGame->ball->positionQ8.y -= 0x80;
        if (JOY_HELD(DPAD_DOWN))
            gCurrentPinballGame->ball->positionQ8.y += 0x80;
        if (JOY_HELD(DPAD_LEFT))
            gCurrentPinballGame->ball->positionQ8.x -= 0x80;
        if (JOY_HELD(DPAD_RIGHT))
            gCurrentPinballGame->ball->positionQ8.x += 0x80;
    }
    else
    {
        if (JOY_HELD(DPAD_UP))
            gCurrentPinballGame->ball->positionQ8.y -= 0x200;
        if (JOY_HELD(DPAD_DOWN))
            gCurrentPinballGame->ball->positionQ8.y += 0x200;
        if (JOY_HELD(DPAD_LEFT))
            gCurrentPinballGame->ball->positionQ8.x -= 0x200;
        if (JOY_HELD(DPAD_RIGHT))
            gCurrentPinballGame->ball->positionQ8.x += 0x200;
    }

    gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
    newX = gCurrentPinballGame->ball->positionQ8.x;
    if (newX < 0)
        newX += 0x7F;
    gCurrentPinballGame->ball->positionQ1.x = newX >> 7;

    newY = gCurrentPinballGame->ball->positionQ8.y;
    if (newY < 0)
        newY += 0x7F;
    gCurrentPinballGame->ball->positionQ1.y = newY >> 7;

    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
}

void sub_48124(void)
{
    if (JOY_NEW(DPAD_UP))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_DOWN))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_RIGHT))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_LEFT))
        gCurrentPinballGame->ballSpeed^= 1;
}

// This function updates/draws the "End of Ball Bonus" summary
void sub_48190(void)
{
    int i, j;
    s16 var0;
    int var2;
    int value;
    int var4;
    int multiplier;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s8 sp0[16];
    s16 sp10;
    s16 sp14;
    s16 sp18;

    var0 = 212 - gCurrentPinballGame->unk63A;
    sp10 = 0;
    sp14 = 0;
    sp18 = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            s16 var1 = gCurrentPinballGame->unk678[i][j];
            if (var1 == 95)
                var1 = 48;
            else if (var1 == 94)
                var1 = 47;
            else if (var1 > 46)
                var1 -= 65;

            if (gCurrentPinballGame->unk63C[i][j])
            {
                DmaCopy16(3, gUnknown_0850558C[var1], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_0850558C[48], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
        }
    }

    if (gMain.unk12 < 180)
    {
        if (gMain.unk12 > 50 && JOY_NEW(A_BUTTON))
        {
            if (gCurrentPinballGame->unk639 == 0)
            {
                gCurrentPinballGame->unk63A = 100;
                var0 = 100;
                gCurrentPinballGame->unk638 = 6;
                gCurrentPinballGame->unk630 =
                    gCurrentPinballGame->unk62A * 500000 +
                    gCurrentPinballGame->unk62B * 750000 +
                    gCurrentPinballGame->unk62C * 500000 +
                    gCurrentPinballGame->unk62D * 100000 +
                    gCurrentPinballGame->unk62E * 100000;
                
                gCurrentPinballGame->unk634 = 0;
                gMain.unk12 = 150;
    
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[1][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[2][j] = 1;
    
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
    
                sp14 = 1;
            }
            else
            {
                gCurrentPinballGame->unk63A = 1;
                gMain.unk12 = 51;
                var0 = 100;
                if (gCurrentPinballGame->unk6B4 || gCurrentPinballGame->unk6B8)
                {
                    gCurrentPinballGame->unk44 += gCurrentPinballGame->unk6B4;
                    gCurrentPinballGame->unk48 += gCurrentPinballGame->unk6B8;
                    gCurrentPinballGame->unk6B4 = 0;
                    gCurrentPinballGame->unk6B8 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

        }
    }

    if (gMain.unk12 == 185)
    {
        gCurrentPinballGame->unk639 = 0;
        gCurrentPinballGame->unk63A = 212;
        gCurrentPinballGame->unk638 = 0;
        gCurrentPinballGame->unk630 = 0;
        gCurrentPinballGame->unk634 = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
    }

    if (gCurrentPinballGame->unk63A != 0)
    {
        if (gMain.unk12 < 150)
            gMain.unk12++;

        if (gCurrentPinballGame->unk638 < 5)
        {
            if (var0 < 89)
            {
                var2 = var0 / 24;
                if (var2 > 2)
                    var2 = 2;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    if (gCurrentPinballGame->unk638 == 0 || i != 2)
                    {
                        if (gCurrentPinballGame->unk63C[i][j] == 0 && gCurrentPinballGame->unk678[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->unk63C[i][j] = 1;
                }
            }
            else if (var0 >= 148)
            {
                var0 = var0 - 148;
                var2 = var0 / 24;
                if (var2 > 1)
                    var2 = 1;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    gCurrentPinballGame->unk63C[i][j] = 0;
                }
            }

            if (gCurrentPinballGame->unk63A == 1)
            {
                gCurrentPinballGame->unk63A = 212;
                gCurrentPinballGame->unk638++;
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
            }
        }
        else if (gCurrentPinballGame->unk638 == 5)
        {
            if (var0 < 17)
            {
                sp10 = -var0 * 2;
                if (var0 == 2)
                    m4aSongNumStart(SE_UNKNOWN_0xA2);
            }
            else
            {
                sp10 = 0;
                gCurrentPinballGame->unk63A = 212;
                gCurrentPinballGame->unk638++;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[1][j] = 0;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[2][j] = 0;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
            }
        }
        else
        {
            if (var0 < 89)
            {
                var2 = var0 / 24;
                if (var2 > 2)
                    var2 = 2;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    if (i != 0)
                    {
                        if (gCurrentPinballGame->unk63C[i][j] == 0 && gCurrentPinballGame->unk678[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->unk63C[i][j] = 1;
                }
            }
        }

        if (sp18)
            m4aSongNumStart(SE_UNKNOWN_0xA1);
    }

    value = 0;
    multiplier = 0;
    if (gCurrentPinballGame->unk63A == 212 || sp14 != 0)
    {   
        switch (gCurrentPinballGame->unk638)
        {
        case 0:
            value = gCurrentPinballGame->unk62A;
            multiplier = 500000;
            break;
        case 1:
            value = gCurrentPinballGame->unk62B;
            multiplier = 750000;
            break;
        case 2:
            value = gCurrentPinballGame->unk62C;
            multiplier = 500000;
            break;
        case 3:
            value = gCurrentPinballGame->unk62D;
            multiplier = 100000;
            break;
        case 4:
            value = gCurrentPinballGame->unk62E;
            multiplier = 100000;
            break;
        case 5:
            value = 0;
            multiplier = 0;
            break;
        case 6:
            break;
        }

        if (gCurrentPinballGame->unk638 < 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            sp0[2] = value / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 2; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = value * multiplier;
            gCurrentPinballGame->unk634 = value;
            sp0[7] = value / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 7; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->unk638 == 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
        else
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk62F;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 5; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            value = 0;
            var4 = 0;
            while (gCurrentPinballGame->unk62F != 0)
            {
                value += gCurrentPinballGame->unk630;
                if (value / 200000000 > 0)
                {
                    value -= 200000000;
                    var4 += 2;
                }
                gCurrentPinballGame->unk62F--;
            }

            if (value / 100000000 > 0)
            {
                value -= 100000000;
                var4 += 1;
            }

            gCurrentPinballGame->unk6B8 = var4;
            gCurrentPinballGame->unk6B4 = value;
            sp0[10] = (var4 % 1000) / 100;
            sp0[9] = ((var4 % 100) / 10) + 10;
            sp0[8] = var4 % 10;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 10; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
    }

    if (var0 >= 90 && var0 <= 140)
    {
        if (gCurrentPinballGame->unk638 < 5)
        {
            if (gCurrentPinballGame->unk634 != 0)
                gCurrentPinballGame->unk63A = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->unk634 >= 200000)
                {
                    gCurrentPinballGame->unk634 -= 200000;
                    gCurrentPinballGame->unk630 += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->unk634 != 0)
                {
                    gCurrentPinballGame->unk630 += gCurrentPinballGame->unk634;
                    gCurrentPinballGame->unk634 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->unk638 == 6)
        {
            gCurrentPinballGame->unk639 = 1;
            if (gCurrentPinballGame->unk6B4 || gCurrentPinballGame->unk6B8)
                gCurrentPinballGame->unk63A = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->unk6B4 >= 200000)
                {
                    gCurrentPinballGame->unk6B4 -= 200000;
                    gCurrentPinballGame->unk44 += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->unk6B8 != 0)
                {
                    gCurrentPinballGame->unk6B8--;
                    gCurrentPinballGame->unk6B4 += 99800000;
                    gCurrentPinballGame->unk44 += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->unk6B4 != 0)
                {
                    gCurrentPinballGame->unk44 += gCurrentPinballGame->unk6B4;
                    gCurrentPinballGame->unk6B4 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->unk678[2][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][2][j];
            
            var4 = gCurrentPinballGame->unk6B8;
            value = gCurrentPinballGame->unk6B4;
            sp0[10] = (var4 % 1000) / 100;
            sp0[9] = ((var4 % 100) / 10) + 10;
            sp0[8] = var4 % 10;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 10; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
    }

    if (gCurrentPinballGame->unk63A)
        gCurrentPinballGame->unk63A--;

    group = &gMain.spriteGroups[9];
    if (group->available)
    {
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->unkFC + 38;
        for (j = 0; j < 14; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        for (i = 0; i < 3; i++)
        {
            group = &gMain.spriteGroups[6 + i];
            group->baseX = 104;
            group->baseY = 64 + i * 16 + gCurrentPinballGame->unkFC + sp10;
            for (j = 0; j < 5; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void sub_495A0(void)
{
    s16 i, j;
    u16 objPalettes[OBJ_PLTT_SIZE / 0x20][0x10];
    u8 rgb[3];

    gCurrentPinballGame->unk1104 = 1;
    gCurrentPinballGame->unk131C = 0;
    if (gMPlayInfo_BGM.status >= 0)
    {
        gCurrentPinballGame->unkF4C = gMPlayInfo_BGM.songHeader;
        m4aMPlayStop(&gMPlayInfo_BGM);
    }
    else
    {
        gCurrentPinballGame->unkF4C = NULL;
    }

    m4aMPlayAllStop();
    m4aSongNumStart(SE_UNKNOWN_0xA5);
    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        gCurrentPinballGame->unk6A = gCurrentPinballGame->unk68;
        if (gMain.selectedField == FIELD_RUBY)
            sub_4E814();
        else if (gMain.selectedField == FIELD_SAPPHIRE)
            sub_4F814();
    }

    gCurrentPinballGame->unk1106 = gMain.blendControl;
    gCurrentPinballGame->unk1108 = gMain.blendAlpha;
    gCurrentPinballGame->unk110A = gMain.blendBrightness;
    gCurrentPinballGame->unk110C = gMain.unk2C;
    gCurrentPinballGame->unk110E = gMain.vCount;
    DmaCopy16(3, (void *)OBJ_PLTT, gCurrentPinballGame->unk111A, OBJ_PLTT_SIZE);
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
        {
            if (i != 9 || j != 12)
            {
                rgb[0] = (((gCurrentPinballGame->unk111A[i][j] & 0x001F) >>  0) * 2) / 5;
                rgb[1] = (((gCurrentPinballGame->unk111A[i][j] & 0x03E0) >>  5) * 2) / 5;
                rgb[2] = (((gCurrentPinballGame->unk111A[i][j] & 0x7C00) >> 10) * 2) / 5;
                objPalettes[i][j] = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
            }
            else
            {
                objPalettes[i][j] = 0x7FFF;
            }
        }
    }

    DmaCopy16(3, objPalettes, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gMain.selectedField < MAIN_FIELD_COUNT)
        sub_1D4D0();
    else if (gMain.selectedField == FIELD_DUSCLOPS)
        sub_356A0();
    else if (gMain.selectedField == FIELD_KYOGRE)
        sub_3ADA0();
    else if (gMain.selectedField == FIELD_GROUDON)
        sub_3E5D0();

    sub_11F0(1);
}

void sub_497BC(void)
{
    gMain.blendControl = gCurrentPinballGame->unk1106;
    gMain.blendAlpha = gCurrentPinballGame->unk1108;
    gMain.blendBrightness = gCurrentPinballGame->unk110A;
    gMain.unk2C = gCurrentPinballGame->unk110C;
    gMain.vCount = gCurrentPinballGame->unk110E;
    DmaCopy16(3, gCurrentPinballGame->unk111A, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gCurrentPinballGame->unkF4C)
        m4aMPlayContinue(&gMPlayInfo_BGM);

    m4aSongNumStart(SE_UNKNOWN_0xA6);
    sub_11F0(0);
}

void sub_49850(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[0];
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
    gOamBuffer[oamSimple->oamId].matrixNum = 0;

    for (i = 1; i < 5; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
        gOamBuffer[oamSimple->oamId].matrixNum = 0;
    }

    for (i = 5; i < 11; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
        gOamBuffer[oamSimple->oamId].matrixNum = 0;
    }

    group = &gMain.spriteGroups[1];
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    }

    group = &gMain.spriteGroups[2];
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    }
}

void sub_49A34(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const struct Vector16 *offsets;
    s16 xOffset;
    s16 yOffset;
    s16 var0;
    s16 sb;
    s16 yScale = 8;

    if (gCurrentPinballGame->unk131C == 0)
    {
        gMain.blendControl = 0xCF;
        gMain.blendBrightness = 0xA;
        gMain.unk2C = 0;
        gMain.vCount = 144;
    }

    if (gCurrentPinballGame->unk131C < 16)
    {
        xOffset = 160 - gCurrentPinballGame->unk131C * 10;
        yOffset = 24;
        var0 = -1;
        sb = -1;
        yScale = 16;
    }
    else if (gCurrentPinballGame->unk131C < 24)
    {
        xOffset = 0;
        yOffset = 24 - (gCurrentPinballGame->unk131C - 15) * 3;
        if (gCurrentPinballGame->unk131C < 18)
        {
            var0 = -1;
            sb = -1;
            yScale = 8;
        }
        else if (gCurrentPinballGame->unk131C == 18)
        {
            var0 = 9;
            sb = -10;
            yScale = 16;
        }
        else if (gCurrentPinballGame->unk131C == 19)
        {
            var0 = 9;
            sb = -9;
            yScale = 128;
        }
        else if (gCurrentPinballGame->unk131C == 20)
        {
            var0 = 7;
            sb = -8;
            yScale = 160;
        }
        else if (gCurrentPinballGame->unk131C == 21)
        {
            var0 = 6;
            sb = -7;
            yScale = 192;
        }
        else if (gCurrentPinballGame->unk131C == 22)
        {
            var0 = 4;
            sb = -5;
            yScale = 224;
        }
        else
        {
            var0 = 4;
            sb = -4;
            yScale = 256;
        }
    }
    else
    {
        xOffset = 0;
        yOffset = 0;
        var0 = 4;
        sb = -4;
        yScale = 256;
    }

    group = &gMain.spriteGroups[0];
    if (var0 >= 0)
    {
        s16 index;

        group->baseX = 100;
        group->baseY = 80 + var0;
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gUnknown_08137D78[0].x;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gUnknown_08137D78[0].y + gCurrentPinballGame->unk1104 * 12;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
        gOamBuffer[oamSimple->oamId].matrixNum = 5;

        index = gUnknown_08137DA4[(gMain.systemFrameCount % 65) / 5];
        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            DmaCopy16(3, gUnknown_08510CAC[index], (void *)0x060118C0, 0x20);
        }
        else
        {
            DmaCopy16(3, gUnknown_08510CAC[index], (void *)0x06010480, 0x20);
        }

        offsets = gUnknown_08137D78;
        group->baseX = 100;
        group->baseY = 80 + var0;
        for (i = 1; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }

        group->baseX = 100;
        group->baseY = 88 + sb;
        for (i = 5; i < 11; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }
    }

    SetMatrixScale(0x100, yScale, 5);

    group = &gMain.spriteGroups[1];
    group->baseX = 100 - xOffset;
    group->baseY = 80 + yOffset;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[2];
    group->baseX = 68 + xOffset;
    group->baseY = 108 - yOffset;
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    gCurrentPinballGame->unk131C++;
}
