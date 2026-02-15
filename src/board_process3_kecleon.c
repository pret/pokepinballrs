#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

#define BONUS_KECLEON_COMPLETE_POINTS 30000000

extern struct SpriteGroup gMain_spriteGroups_9;
extern struct SpriteGroup gMain_spriteGroups_31;

extern void sub_35D54(void);
extern void sub_36CB4(void);
extern void sub_372B4(void);
extern void sub_3751C(void);
extern void sub_37850(void);
extern void sub_38218(void);

extern const struct SpriteSet *gUnknown_0202D880[];

struct Unk_086AE9E4
{
    u8 unk0[4];
    u16 unk4[2];
};
struct Unk_086AEA70
{
    const struct SpriteSet *unk0;
    u8 unk4;
    u8 unk5;
};

extern const u8 gKecleonBonusClear_Gfx[];
extern const u16 gUnknown_08327994[];
extern const u8 gKecleonStageKecleon_Gfx[][0x280];
extern const u8 gKecleonStageKecleonFx_Gfx[][0x100];
extern struct SongHeader se_unk_fc;
extern struct SongHeader se_unk_fd;
extern struct SongHeader se_unk_fe;
extern struct SongHeader se_unk_ff;
extern struct SongHeader se_unk_100;
extern struct SongHeader se_unk_101;
extern struct SongHeader se_unk_102;
extern struct SongHeader se_unk_103;
extern const u16 gUnknown_086AE718[][3];
extern const s16 gUnknown_086AEA60[];
extern const u16 gUnknown_086AE9C4[];
extern const u16 gUnknown_086AE9D4[];
extern const struct Unk_086AE9E4 gUnknown_086AE9E4[];
extern const struct Vector16 gUnknown_086AEA3C[];
extern const u16 *gUnknown_086AEA50[];
extern const s16 gUnknown_086AEA68[];
extern const struct Unk_086AEA70 gUnknown_086AEA70[];
extern const u16 gUnknown_086B9AB8[126][2][3];
extern const u16 gUnknown_086B9DAC[126][2][3];
extern const struct SpriteSet *gUnknown_086BB420[];

void KecleonBoardProcess_3A_35860(void)
{
    s16 i;

    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 120 * 60; // 120 seconds
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk388 = 3;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unk386 = 0;
    gCurrentPinballGame->unk3F7 = 1;
    gCurrentPinballGame->unk3DC = 0;
    gCurrentPinballGame->unk3E8 = 750;
    gCurrentPinballGame->unk3EA = 360;
    gCurrentPinballGame->unk3DF = 3;
    gCurrentPinballGame->unk385 = 0;
    gCurrentPinballGame->unk387 = 0;
    gCurrentPinballGame->unk394 = 0;
    gCurrentPinballGame->unk3DE = 0;
    gCurrentPinballGame->unk3E0 = 0;
    gCurrentPinballGame->unk3E2 = 0;
    gCurrentPinballGame->unk3E4 = 0;
    gCurrentPinballGame->unk3F4 = 0;
    gCurrentPinballGame->unk3F5 = 0;
    gCurrentPinballGame->unk3F6 = 0;
    gCurrentPinballGame->unk3F8 = 0;
    gCurrentPinballGame->unk3FA = 0;
    gCurrentPinballGame->unk3FC = 0;
    gCurrentPinballGame->unk404 = 0;
    gCurrentPinballGame->unk405 = 0;
    gCurrentPinballGame->unk406 = 0;
    gCurrentPinballGame->unk408 = 0;
    gCurrentPinballGame->unk40A = 0;
    gCurrentPinballGame->unk40C = 0;
    gCurrentPinballGame->unk40E = 0;
    gCurrentPinballGame->unk410 = 0;
    gCurrentPinballGame->unk412 = 0;
    for (i = 0; i < 4; i++)
        gCurrentPinballGame->unk41C[i] = 0;

    for (i = 0; i < 10; i++)
        gCurrentPinballGame->unk420[i] = 0;

    for (i = 0; i < 7; i++)
        gCurrentPinballGame->unk42A[i] = 0;

    gCurrentPinballGame->unk1A = 0;
    gCurrentPinballGame->unk400.y = gCurrentPinballGame->unk3EA / 10 + 58;
    sub_38218();
    gCurrentPinballGame->unk387 = 1;
    sub_35D54();
    sub_36CB4();
    m4aSongNumStart(MUS_BONUS_FIELD_KECLEON);
    sub_372B4();
    sub_3751C();
    sub_37850();
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void KecleonBoardProcess_3B_35AA4(void)
{
    sub_38218();
    switch (gCurrentPinballGame->unk13)
    {
    case 0:
        gCurrentPinballGame->unk5F7 = 1;
        if (gCurrentPinballGame->unk18 < 120)
        {
            gCurrentPinballGame->unkE6 = (gCurrentPinballGame->unk18 / 5) + 0xFFE8;
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unkE6 = 0;
            gCurrentPinballGame->unk13 = 1;
            gCurrentPinballGame->unk18 = 0;
        }

        if (gCurrentPinballGame->unk386 == 0)
        {
            gMain.blendControl = 0x1C10;
            gMain.blendAlpha = BLDALPHA_BLEND(16, 0);
        }
        break;
    case 1:
        if (gCurrentPinballGame->unk386 == 0)
        {
            if (gCurrentPinballGame->unk40E == 0)
            {
                u16 var0 = 16 - gCurrentPinballGame->unk3FA;
                u16 var1 = gCurrentPinballGame->unk3FA;
                gMain.blendControl = 0x1C10;
                gMain.blendAlpha = BLDALPHA_BLEND(var0, var1);
            }
            else
            {
                gMain.blendControl = 0x1C42;
                gMain.blendAlpha = BLDALPHA_BLEND(7, 9);
            }
        }
        break;
    case 2:
        if (gCurrentPinballGame->unk18 < 10)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk13 = 3;
            gCurrentPinballGame->unk18 = 0;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[5].available = 1;
            DmaCopy16(3, gKecleonBonusClear_Gfx, (void *)0x6015800, 0x2000);
            gCurrentPinballGame->unk394 = 0x88;
            gMain.unkF = 0x80;
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
            gCurrentPinballGame->scoreAddedInFrame = BONUS_KECLEON_COMPLETE_POINTS;
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
            gCurrentPinballGame->unk13 = 4;
            gCurrentPinballGame->numCompletedBonusStages++;
        }
        break;
    case 4:
        sub_351A8();
        gCurrentPinballGame->unk386 = 1;
        break;
    }

    sub_35D54();
    sub_36CB4();
    sub_372B4();
    sub_3751C();
    if (gCurrentPinballGame->unk294 && gCurrentPinballGame->eventTimer < 2 && gMain.unkF == 0)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL3);
        gCurrentPinballGame->unk404 = 0;
        gCurrentPinballGame->unk408 = 0;
        gCurrentPinballGame->unk406 = 0;
        gMain.unkF |= 0x40;
    }

    if (gCurrentPinballGame->unk386)
        sub_350F0();

    sub_472E4();
    sub_37850();
}

void sub_35D54(void)
{
    const u16 VECTORSCALEDOWN = 20000;
    int deltaX;
    int deltaY;
    struct Vector32 tempVec;
    struct Vector32 deltaVec;
    u16 angle;
    int xx, yy;
    int deltaMagSquared;

    switch (gCurrentPinballGame->unk3DC)
    {
    case 0:
        gCurrentPinballGame->unk3DC = 1;
        gCurrentPinballGame->unk3E2 = 3;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3E8 = 750;
        gCurrentPinballGame->unk3EA = 360;
        gCurrentPinballGame->unk3F4 = gUnknown_086AE9E4[10].unk0[(Random() * gMain.systemFrameCount) & 0x3];
        break;
    case 1:
        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            if (++gCurrentPinballGame->unk3E2 == 9)
                gCurrentPinballGame->unk3E2 = 3;
        }

        if (gCurrentPinballGame->unk3E8 > 0)
        {
            gCurrentPinballGame->unk3E8 -= 6;
        }
        else
        {
            gCurrentPinballGame->unk3DC = 2;
            gCurrentPinballGame->unk3E2 = 59;
            gCurrentPinballGame->unk3E4 = 0;
        }

        if (gCurrentPinballGame->unk392 > 2)
            gCurrentPinballGame->unk392--;
        break;
    case 2:
        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            if (++gCurrentPinballGame->unk3E2 == 66)
            {
                gCurrentPinballGame->unk3E2 = 65;
                if (gCurrentPinballGame->unk40E < 8)
                {
                    gCurrentPinballGame->unk3DC = 3;
                }
                else
                {
                    int rand, mask;

                    if (gCurrentPinballGame->unk3F5)
                    {
                        gCurrentPinballGame->unk3E4 = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E4 = 0;
                        gCurrentPinballGame->unk3F5 = 1;
                    }

                    gCurrentPinballGame->unk3DC = 5;

                    rand = Random() + gMain.systemFrameCount;
                    mask = 0x3;
                    gCurrentPinballGame->unk3F4 = gUnknown_086AE9E4[gCurrentPinballGame->unk3F4].unk0[rand & mask];
                }
            }

            if (gCurrentPinballGame->unk3E2 == 60 || gCurrentPinballGame->unk3E2 == 61)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_fc);
        }

        if (gCurrentPinballGame->unk3E2 == 64)
        {
            gCurrentPinballGame->unk3FA = gCurrentPinballGame->unk3E4 / 2;
            if (gCurrentPinballGame->unk3E4 == 4)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_fd);
        }
        break;
    case 3:
        gCurrentPinballGame->unk3EC = gUnknown_086AE9E4[gCurrentPinballGame->unk3F4].unk4[0];
        gCurrentPinballGame->unk3EE = gUnknown_086AE9E4[gCurrentPinballGame->unk3F4].unk4[1];
        deltaVec.x = gCurrentPinballGame->unk3EC - gCurrentPinballGame->unk3E8;
        deltaVec.y = gCurrentPinballGame->unk3EE - gCurrentPinballGame->unk3EA;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        gCurrentPinballGame->unk3DE = gUnknown_086AE9C4[angle / 0x2000];
        gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3DC = 4;
        break;
    case 4:
        deltaVec.x = gCurrentPinballGame->unk3EC - gCurrentPinballGame->unk3E8;
        deltaVec.y = gCurrentPinballGame->unk3EE - gCurrentPinballGame->unk3EA;
        xx = deltaVec.x * deltaVec.x;
        yy = deltaVec.y * deltaVec.y;
        deltaMagSquared = xx + yy;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        tempVec.x = 6 * Cos(angle) / VECTORSCALEDOWN;
        tempVec.y = -6 * Sin(angle) / VECTORSCALEDOWN;
        gCurrentPinballGame->unk3E8 += tempVec.x;
        gCurrentPinballGame->unk3EA += tempVec.y;
        if (deltaMagSquared < 2500)
        {
            gCurrentPinballGame->unk3DC = 8;
            if (gCurrentPinballGame->unk3DE == 3)
            {
                gCurrentPinballGame->unk3DE = 66;
                gCurrentPinballGame->unk3E2 = 66;
            }
            else
            {
                gCurrentPinballGame->unk3DE = 69;
                gCurrentPinballGame->unk3E2 = 69;
            }

            gCurrentPinballGame->unk3E4 = 0;
        }

        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 6)
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE;
        }
        break;
    case 5:
        if (gCurrentPinballGame->unk3E4 < 18)
        {
            if (gCurrentPinballGame->unk3E4 == 0)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_fe);

            gCurrentPinballGame->unk3E4++;
            if (gCurrentPinballGame->unk3DE == 66)
                gCurrentPinballGame->unk3E2 = 37;
            else
                gCurrentPinballGame->unk3E2 = 48;
        }
        else
        {
            gCurrentPinballGame->unk3EC = gUnknown_086AE9E4[gCurrentPinballGame->unk3F4].unk4[0];
            gCurrentPinballGame->unk3EE = gUnknown_086AE9E4[gCurrentPinballGame->unk3F4].unk4[1];
            deltaVec.x = gCurrentPinballGame->unk3EC - gCurrentPinballGame->unk3E8;
            deltaVec.y = gCurrentPinballGame->unk3EE - gCurrentPinballGame->unk3EA;
            angle = ArcTan2(deltaVec.x, -deltaVec.y);
            gCurrentPinballGame->unk3DE = gUnknown_086AE9D4[angle / 0x2000];
            gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE;
            gCurrentPinballGame->unk3DC = 6;
        }
        break;
    case 6:
        deltaVec.x = gCurrentPinballGame->unk3EC - gCurrentPinballGame->unk3E8;
        deltaVec.y = gCurrentPinballGame->unk3EE - gCurrentPinballGame->unk3EA;
        xx = deltaVec.x * deltaVec.x;
        yy = deltaVec.y * deltaVec.y;
        deltaMagSquared = xx + yy;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        tempVec.x = 10 * Cos(angle) / VECTORSCALEDOWN;
        tempVec.y = -10 * Sin(angle) / VECTORSCALEDOWN;
        gCurrentPinballGame->unk3E8 += tempVec.x;
        gCurrentPinballGame->unk3EA += tempVec.y;
        if (deltaMagSquared < 2500)
        {
            if (gCurrentPinballGame->unk385 > 9)
            {
                if (gCurrentPinballGame->unk3DE == 66)
                {
                    gCurrentPinballGame->unk3DE = 75;
                    gCurrentPinballGame->unk3E8 += 240;
                }
                else
                {
                    gCurrentPinballGame->unk3DE = 95;
                    gCurrentPinballGame->unk3E8 -= 240;
                }

                gCurrentPinballGame->unk3DC = 14;
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE;
            }
            else
            {
                if (gCurrentPinballGame->unk3FA < 16)
                {
                    gCurrentPinballGame->unk3DC = 2;
                    gCurrentPinballGame->unk3E2 = 62;
                    gCurrentPinballGame->unk3E4 = 0;
                }
                else
                {
                    gCurrentPinballGame->unk3DC = 7;
                    if (gCurrentPinballGame->unk3DE == 38)
                    {
                        gCurrentPinballGame->unk3DE = 42;
                        gCurrentPinballGame->unk3E2 = 42;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3DE = 53;
                        gCurrentPinballGame->unk3E2 = 53;
                    }

                    gCurrentPinballGame->unk3E4 = 0;
                }
            }
        }

        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 4)
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE;

            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 1)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_ff);
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 3)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_ff);
        }
        break;
    case 7:
        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 6)
            {
                int rand, mask;

                if (gCurrentPinballGame->unk40E < 8)
                {
                    gCurrentPinballGame->unk3DC = 3;
                }
                else
                {
                    if (gCurrentPinballGame->unk3F5)
                    {
                        gCurrentPinballGame->unk3E4 = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E4 = 0;
                        gCurrentPinballGame->unk3F5 = 1;
                    }

                    gCurrentPinballGame->unk3DC = 5;
                }

                rand = Random() + gMain.systemFrameCount;
                mask = 0x3;
                gCurrentPinballGame->unk3F4 = gUnknown_086AE9E4[gCurrentPinballGame->unk3F4].unk0[rand & mask];
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 5;
            }
        }
        break;
    case 8:
        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            int rand, mask;

            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 2)
            {
                if (gCurrentPinballGame->unk40E < 8)
                {
                    gCurrentPinballGame->unk3DC = 3;
                }
                else
                {
                    if (gCurrentPinballGame->unk3F5)
                    {
                        gCurrentPinballGame->unk3E4 = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E4 = 0;
                        gCurrentPinballGame->unk3F5 = 1;
                    }

                    gCurrentPinballGame->unk3DC = 5;
                }

                rand = Random() + gMain.systemFrameCount;
                mask = 0x3;
                gCurrentPinballGame->unk3F4 = gUnknown_086AE9E4[gCurrentPinballGame->unk3F4].unk0[rand & mask];
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 1;
            }
        }
        break;
    case 9:
        gCurrentPinballGame->unk3DC = 10;
        if (gMain.systemFrameCount & 1)
        {
            if (gCurrentPinballGame->unk3E8 < -640)
            {
                gCurrentPinballGame->unk3F6 = 1;
                gCurrentPinballGame->unk3DE = 32;
            }
            else
            {
                gCurrentPinballGame->unk3F6 = 0;
                gCurrentPinballGame->unk3DE = 27;
            }
        }
        else
        {
            if (gCurrentPinballGame->unk3E8 > 640)
            {
                gCurrentPinballGame->unk3F6 = 0;
                gCurrentPinballGame->unk3DE = 27;
            }
            else
            {
                gCurrentPinballGame->unk3F6 = 1;
                gCurrentPinballGame->unk3DE = 32;
            }
        }

        if (gCurrentPinballGame->unk3FA < 16)
            gCurrentPinballGame->unk3FA = 0;

        gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE;
        gCurrentPinballGame->unk3E4 = 0;
        MPlayStart(&gMPlayInfo_SE1, &se_unk_100);
        break;
    case 10:
        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 1)
                gCurrentPinballGame->unk3FC = 23;

            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 2)
            {
                gCurrentPinballGame->unk3DC = 13;
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 1;
            }
        }
        break;
    case 11:
        gCurrentPinballGame->unk3DC = 12;
        gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 2;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3FA = 0;
        gCurrentPinballGame->scoreAddedInFrame = 500000;
        gCurrentPinballGame->unk385++;
        MPlayStart(&gMPlayInfo_SE1, &se_unk_101);
        sub_11B0(7);
        break;
    case 12:
        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 4)
            {
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 3;
                if (gCurrentPinballGame->unk385 < 10)
                {
                    gCurrentPinballGame->unk3DC = 13;
                }
                else
                {
                    gCurrentPinballGame->unk294 = 3;
                    gMain.unkF = 0x80;
                    gCurrentPinballGame->unk388 = 2;
                    gCurrentPinballGame->unk392 = 0;
                    gCurrentPinballGame->unk3DC = 13;
                    gCurrentPinballGame->unk404 = 0;
                    gCurrentPinballGame->unk408 = 0;
                    gCurrentPinballGame->unk406 = 0;
                    gCurrentPinballGame->unk387 = 0;
                }
            }
        }
        break;
    case 13:
        gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 4;
        if (gCurrentPinballGame->unk3E4 < 8)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            if (gCurrentPinballGame->unk385 > 9)
            {
                if (gCurrentPinballGame->unk3F6 == 0)
                {
                    gCurrentPinballGame->unk3E2 = 72;
                    gCurrentPinballGame->unk3E8 -= 240;
                }
                else
                {
                    gCurrentPinballGame->unk3E2 = 73;
                    gCurrentPinballGame->unk3E8 += 240;
                }

                gCurrentPinballGame->unk3DC = 5;
                gCurrentPinballGame->unk3E4 = 20;
                gCurrentPinballGame->unk3F4 = 3 + ((Random() * gMain.systemFrameCount) & 0x3);
            }
            else
            {
                if (gCurrentPinballGame->unk3FA < 16)
                {
                    if (gCurrentPinballGame->unk3F6 == 0)
                    {
                        gCurrentPinballGame->unk3E2 = 72;
                        gCurrentPinballGame->unk3E8 -= 240;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E2 = 73;
                        gCurrentPinballGame->unk3E8 += 240;
                    }

                    gCurrentPinballGame->unk3DC = 5;
                    gCurrentPinballGame->unk3E4 = 20;
                    gCurrentPinballGame->unk3F4 = 3 + ((Random() * gMain.systemFrameCount) & 0x3);
                }
                else
                {
                    if (gCurrentPinballGame->unk3F6 == 0)
                    {
                        gCurrentPinballGame->unk3E2 = 72;
                        gCurrentPinballGame->unk3E8 -= 240;
                    }
                    else
                    {
                        gCurrentPinballGame->unk3E2 = 73;
                        gCurrentPinballGame->unk3E8 += 240;
                    }

                    gCurrentPinballGame->unk3E4 = 0;
                    if (gCurrentPinballGame->unk40E < 8)
                    {
                        gCurrentPinballGame->unk3DC = 3;
                    }
                    else
                    {
                        if (gCurrentPinballGame->unk3F5)
                        {
                            gCurrentPinballGame->unk3E4 = 20;
                        }
                        else
                        {
                            gCurrentPinballGame->unk3E4 = 0;
                            gCurrentPinballGame->unk3F5 = 1;
                        }

                        gCurrentPinballGame->unk3DC = 5;
                    }
                }
            }
        }
        break;
    case 14:
        gCurrentPinballGame->unk3FA = 0;
        if (gUnknown_086AE718[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {
            gCurrentPinballGame->unk3E4++;
        }
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 19)
            {
                gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 18;
                gCurrentPinballGame->unk3DC = 15;
            }

            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 6)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_102);

            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 8)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_103);
        }
        break;
    case 15:
        if (gCurrentPinballGame->unk3E4 < 100)
        {
            if (gCurrentPinballGame->unk3E4 == 0)
            {
                gCurrentPinballGame->unk13 = 2;
                gCurrentPinballGame->unk18 = 0;
            }

            gCurrentPinballGame->unk3E4++;
        }

        gCurrentPinballGame->unk3E2 = gCurrentPinballGame->unk3DE + 15;
        break;
    }
}

void sub_36CB4(void)
{
    s16 i;
    struct SpriteGroup *spriteGroup;
    s16 sp0;
    s16 sp4;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    int var0;
    int var1;
    int baseX = 104;
    int baseY = 28;

    spriteGroup = &gMain_spriteGroups[gUnknown_02031590[23]];
    if (!spriteGroup->available)
        return;

    sp0 = gCurrentPinballGame->unk3DF;
    gCurrentPinballGame->unk3DF = gUnknown_086AE718[gCurrentPinballGame->unk3E2][2];
    DmaCopy16(3, gKecleonStageKecleon_Gfx[sp0], (void *)0x6010920, 0x280);
    sp4 = gUnknown_086AE718[gCurrentPinballGame->unk3E2][0];
    spriteGroup->baseX = gCurrentPinballGame->unk3E8 / 10 + baseX - gCurrentPinballGame->unk58;
    spriteGroup->baseY = gCurrentPinballGame->unk3EA / 10 + baseY - gCurrentPinballGame->unk5A;
    if (gCurrentPinballGame->unk3E2 >= 28 && gCurrentPinballGame->unk3E2 < 31)
    {
        gCurrentPinballGame->unk3F0 = 2 * (gCurrentPinballGame->unk3E8 / 10) + 144;
        gCurrentPinballGame->unk3F2 = 2 * (gCurrentPinballGame->unk3EA / 10) + 84;
        if (gCurrentPinballGame->unk385 < 10)
            gCurrentPinballGame->unk387 = 2;
    }
    else if (gCurrentPinballGame->unk3E2 >= 33 && gCurrentPinballGame->unk3E2 < 36)
    {
        gCurrentPinballGame->unk3F0 = 2 * (gCurrentPinballGame->unk3E8 / 10) + 240;
        gCurrentPinballGame->unk3F2 = 2 * (gCurrentPinballGame->unk3EA / 10) + 84;
        if (gCurrentPinballGame->unk385 < 10)
            gCurrentPinballGame->unk387 = 2;
    }
    else
    {
        gCurrentPinballGame->unk3F0 = 2 * (gCurrentPinballGame->unk3E8 / 10) + 208;
        gCurrentPinballGame->unk3F2 = 2 * (gCurrentPinballGame->unk3EA / 10) + 56;
        if (gCurrentPinballGame->unk385 < 10)
            gCurrentPinballGame->unk387 = 1;
    }

    gCurrentPinballGame->unk400.x = (gCurrentPinballGame->unk3E8 / 10) + 120;
    gCurrentPinballGame->unk400.y = (gCurrentPinballGame->unk3EA / 10) + 58;
    if (gCurrentPinballGame->unk40E > 7)
        gCurrentPinballGame->unk3F7 = 1;
    else if (gCurrentPinballGame->unk3FA > 15)
        gCurrentPinballGame->unk3F7 = 0;
    else
        gCurrentPinballGame->unk3F7 = 1;

    for (i = 0; i < 2; i++)
    {
        oamSimple = &spriteGroup->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B9DAC[sp4][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        if (gCurrentPinballGame->unk3F7)
        {
            gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
            gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            if (gCurrentPinballGame->unk3DF == 20) {
                if(gCurrentPinballGame->unk3E4 < 10)
                    gOamBuffer[oamSimple->oamId].paletteNum = 10;
                else
                    gOamBuffer[oamSimple->oamId].paletteNum = 2;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].paletteNum = 2;
            }
        }
        else
        {
            gOamBuffer[oamSimple->oamId].x = 240;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    baseX = 104;
    baseY = 60;
    spriteGroup = &gMain_spriteGroups_31;
    spriteGroup->baseX = gCurrentPinballGame->unk3E8 / 10 + baseX - gCurrentPinballGame->unk58;
    spriteGroup->baseY = gCurrentPinballGame->unk3EA / 10 + baseY - gCurrentPinballGame->unk5A;

    for (i = 0; i < 2; i++)
    {
        oamSimple = &spriteGroup->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B9AB8[sp4][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        if (gCurrentPinballGame->unk3F7)
        {
            gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
            gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            if (sp0 == 20)
            {
                if (gCurrentPinballGame->unk3E4 < 10)
                    gOamBuffer[oamSimple->oamId].paletteNum = 11;
                else
                    gOamBuffer[oamSimple->oamId].paletteNum = 4;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].paletteNum = 4;
            }
        }
        else
        {
            gOamBuffer[oamSimple->oamId].x = 240;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    baseX = 104;
    baseY = 26;
    spriteGroup = &gMain_spriteGroups_9;
    var0 = gCurrentPinballGame->unk3F8 * 3;
    var1 = gCurrentPinballGame->unk3FC / 8 - 2;

    DmaCopy16(3, gKecleonStageKecleonFx_Gfx[var0 - var1], (void *)0x6010BA0, 0x100);
    if (gCurrentPinballGame->unk3FC > 0)
    {
        gCurrentPinballGame->unk3FC--;
        spriteGroup->baseX = gCurrentPinballGame->unk3E8 / 10 + baseX - gCurrentPinballGame->unk58;
        spriteGroup->baseY = gCurrentPinballGame->unk3EA / 10 + - gCurrentPinballGame->unk5A + baseY;
    }
    else
    {
        spriteGroup->baseX = 0;
        spriteGroup->baseY = 180;
    }

    oamSimple = &spriteGroup->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
    if (gCurrentPinballGame->unk3F6 == 0)
        gOamBuffer[oamSimple->oamId].hFlip = 0;
    else
        gOamBuffer[oamSimple->oamId].hFlip = 1;
}


void sub_372B4(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct Vector32 tempVector;
    int xx, yy;
    int squaredMagnitude;

    group = &gMain.spriteGroups[24];
    if (!group->available)
        return;

    if (gCurrentPinballGame->unk404)
    {
        if (gCurrentPinballGame->unk40A == 0)
        {
            gCurrentPinballGame->unk405 = (Random() * gMain.systemFrameCount) % 5;
            gCurrentPinballGame->unk414.y = 0;
            gCurrentPinballGame->unk418.y = 0;
        }

        if (gCurrentPinballGame->unk40A < 40)
            gCurrentPinballGame->unk40A++;

        if (gCurrentPinballGame->unk40A == 20)
            m4aMPlayStop(&gMPlayInfo_SE2);

        if (gCurrentPinballGame->unk40A == 22)
            m4aSongNumStart(SE_KECLEON_SCOPE_FALL);

        if (gCurrentPinballGame->unk40A > 20)
        {
            gCurrentPinballGame->unk414.x = 4;
            gCurrentPinballGame->unk414.y += 3;
            gCurrentPinballGame->unk418.x = gUnknown_086AEA3C[gCurrentPinballGame->unk405].x;
            gCurrentPinballGame->unk418.y += gCurrentPinballGame->unk414.y;
            if (gCurrentPinballGame->unk418.y > gUnknown_086AEA3C[gCurrentPinballGame->unk405].y)
            {
                gCurrentPinballGame->unk418.y = gUnknown_086AEA3C[gCurrentPinballGame->unk405].y;
                gCurrentPinballGame->unk414.y = -(gCurrentPinballGame->unk414.y / 6);
            }

            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->unk418.x / 10 + 8);
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->unk418.y / 10 + 8);
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (squaredMagnitude <= 120)
            {
                gCurrentPinballGame->unk404 = 0;
                gCurrentPinballGame->unk406 = 1;
                gCurrentPinballGame->unk408 = 0;
                gCurrentPinballGame->scoreAddedInFrame = 10000;
                m4aSongNumStart(SE_KECLEON_SCOPE_ACTIVATED);
            }

            group->baseX = -gCurrentPinballGame->unk58 + gCurrentPinballGame->unk418.x / 10;
            group->baseY = -gCurrentPinballGame->unk5A + gCurrentPinballGame->unk418.y / 10;
        }
        else
        {
            group->baseX = 0;
            group->baseY = 180;
        }
    }
    else
    {
        group->baseX = 0;
        group->baseY = 180;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
}


void sub_3751C(void)
{
    s16 i, j;
    s16 var0;
    s16 var1;
    s16 var2;
    s16 index;
    s16 var3;
    const u16 *ptr;

    if (gCurrentPinballGame->unk406)
    {
        if (gCurrentPinballGame->unk408 < 600)
        {
            gCurrentPinballGame->unk408++;
        }
        else
        {
            gCurrentPinballGame->unk408 = 0;
            gCurrentPinballGame->unk406 = 0;
        }
    }

    if (gCurrentPinballGame->unk406)
    {
        if (gCurrentPinballGame->unk40E < 10)
            gCurrentPinballGame->unk40E++;
    }
    else
    {
        if (gCurrentPinballGame->unk40E)
            gCurrentPinballGame->unk40E--;
        else
            gCurrentPinballGame->unk3F5 = 0;
    }

    gMain.unk2E = gCurrentPinballGame->unk40E * 16;
    var0 = gCurrentPinballGame->unk40E * 64;
    var1 = (20 - gCurrentPinballGame->unk40E * 2) * 32;
    index = (gCurrentPinballGame->unk408 % 36) / 9;
    var3 = gUnknown_086AEA60[index];
    ptr = gUnknown_086AEA50[index];
    for (j = 0; j < var0; j++)
        gUnknown_03005C00[0x400 + j] = ptr[var1 + j];
    for (j = var0; j < 0x280; j++)
        gUnknown_03005C00[0x400 + j] = 0x3FF;

    index = gCurrentPinballGame->unk408 % 150;
    if (index >= 10 && index < 80)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 4; j++)
            {
                gUnknown_03005C00[0x408 + ((i + 6) * 0x20) + j] = gUnknown_08327994[((i + 21) * 0x20) + (j + var3 * 4)];
            }
        }

        var2 = index / 10;
        if (var2 > 5)
            var2 = 5;

        for (j = 0; j < var2; j++)
        {
            gUnknown_03005C00[0x4C3 + j] = gUnknown_08327994[0x2EC + j];
        }
    }

    if (index >= 80 && index < 150)
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 6; j++)
            {
                gUnknown_03005C00[0x411 + ((i + 14) * 0x20) + j] = gUnknown_08327994[((i + 21) * 0x20) + (j + 0xC + var3 * 6)];
            }
        }

        var2 = (index - 70) / 10;
        if (var2 > 5)
            var2 = 5;

        for (j = 0; j < var2; j++)
        {
            gUnknown_03005C00[0x5F7 + j] = gUnknown_08327994[0x2EC + j];
        }
    }

    DmaCopy16(3, &gUnknown_03005C00[0x400], (void *)0x06001000, 0x500);
}

void sub_37850(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct OamData *oamData;
    struct Vector16 tempVector;
    s16 var0;
    s16 var1;
    s16 var2;

    tempVector.x = gCurrentPinballGame->unk400.x * 2;
    tempVector.y = gCurrentPinballGame->unk400.y * 2;
    sub_17C1C(&tempVector);

    group = &gMain.spriteGroups[gUnknown_02031590[16]];
    group->baseX = 120 - gCurrentPinballGame->unk58;
    group->baseY = -gCurrentPinballGame->unk5A - 128;
    for (j = 0; j < 4; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[gUnknown_02031590[17]];
    group->baseX = 120 - gCurrentPinballGame->unk58;
    group->baseY = -gCurrentPinballGame->unk5A - 128;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[7];
    var0 = 5 - gCurrentPinballGame->unk40C % 10;
    if (gCurrentPinballGame->unk40C > 30)
        var1 = 20;
    else if (gCurrentPinballGame->unk40C > 10)
        var1 = 10;
    else
        var1 = 5;

    if (gCurrentPinballGame->unk40C == 40)
    {
        m4aSongNumStart(SE_KECLEON_TREE_HIT);
        sub_11B0(7);
    }

    if (var0 < 0)
        var0 = -var0;

    group->baseX = (var1 * (5 - var0)) / 10 + 120u - gCurrentPinballGame->unk58;
    group->baseY = -gCurrentPinballGame->unk5A - 128;
    for  (j = 0; j < 5; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->unk40C)
        gCurrentPinballGame->unk40C--;

    for (i = 0; i < 6; i++)
    {
        group = &gMain.spriteGroups[gUnknown_02031590[10 + i]];
        group->baseX = 120 - gCurrentPinballGame->unk58;
        group->baseY = -gCurrentPinballGame->unk5A - 128;
        var2 = 0;
        if (gCurrentPinballGame->unk420[i])
        {
            var2 = gUnknown_086AEA68[(gCurrentPinballGame->unk420[i] % 24) / 6];
            gCurrentPinballGame->unk420[i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0xD2 + var2 * 12 + j * 8;
        }
    }

    for (i = 6; i < 10; i++)
    {
        group = &gMain.spriteGroups[gUnknown_02031590[12 + i]];
        group->baseX = 120 - gCurrentPinballGame->unk58;
        group->baseY = -gCurrentPinballGame->unk5A - 128;
        var2 = 0;
        if (gCurrentPinballGame->unk420[i])
        {
            var2 = gUnknown_086AEA68[(gCurrentPinballGame->unk420[i] % 24) / 6];
            gCurrentPinballGame->unk420[i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0xD2 + var2 * 12 + j * 8;
        }
    }

    group = &gMain.spriteGroups[25];
    group->baseX = 120 - gCurrentPinballGame->unk58;
    group->baseY = -gCurrentPinballGame->unk5A - 128;
    var2 = 0;
    if (gCurrentPinballGame->unk41C[0])
    {
        var2 = gUnknown_086AEA68[(gCurrentPinballGame->unk41C[0] % 24) / 6];
        gCurrentPinballGame->unk41C[0]--;
    }

    for (j = 0; j < 3; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0xF6 + var2 * 8 + (j * 4 - (j / 2) * 2);
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[26 + i];
        group->baseX = 120 - gCurrentPinballGame->unk58;
        group->baseY = -gCurrentPinballGame->unk5A - 128;

        var2 = 0;
        if (gCurrentPinballGame->unk41C[1 + i])
        {
            var2 = gUnknown_086AEA68[(gCurrentPinballGame->unk41C[1 + i] % 24) / 6];
            gCurrentPinballGame->unk41C[1 + i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0x10E + var2 * 12 + j * 8;
        }
    }

    group = &gMain.spriteGroups[28];
    group->baseX = 120 - gCurrentPinballGame->unk58;
    group->baseY = -gCurrentPinballGame->unk5A - 128;
    var2 = 0;
    if (gCurrentPinballGame->unk41C[3])
    {
        var2 = gUnknown_086AEA68[(gCurrentPinballGame->unk41C[3] % 24) / 6];
        gCurrentPinballGame->unk41C[3]--;
    }

    for (j = 0; j < 2; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x132 + var2 * 12 + j * 8;
    }

    group = &gMain.spriteGroups[32];
    group->baseX = gCurrentPinballGame->ball->screenPosition.x;
    group->baseY = gCurrentPinballGame->ball->screenPosition.y + 14;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    if (gCurrentPinballGame->ball->unk0)
        gOamBuffer[oamSimple->oamId].y = 200;
    else
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[29];
    if (gCurrentPinballGame->unk410 < 12)
        gCurrentPinballGame->unk410++;
    else
        gCurrentPinballGame->unk410 = 0;

    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->unk42A[i])
        {
            var2 = 2 - gCurrentPinballGame->unk42A[i] / 4;
            gCurrentPinballGame->unk42A[i]--;
            group->baseX = gCurrentPinballGame->unkD0[i].x - gCurrentPinballGame->unk4C + 4;
            group->baseY = gCurrentPinballGame->unkD0[i].y - gCurrentPinballGame->unk4E- gCurrentPinballGame->unk5FC - gCurrentPinballGame->unkE6 + 4;
        }
        else
        {
            group->baseX = 240;
            group->baseY = 180;
        }

        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x16E + var2;
    }

    group = &gMain.spriteGroups[30];
    if (gCurrentPinballGame->unk412 < 24)
        gCurrentPinballGame->unk412++;
    else
        gCurrentPinballGame->unk412 = 0;

    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->unk42A[4 + i])
        {
            var2 = 2 - gCurrentPinballGame->unk42A[4 + i] / 6;
            gCurrentPinballGame->unk42A[4 + i]--;
            group->baseX = gCurrentPinballGame->unk434[i].x - gCurrentPinballGame->unk58 - 4;
            group->baseY = gCurrentPinballGame->unk434[i].y - gCurrentPinballGame->unk5A + 2;
        }
        else
        {
            group->baseX = 240;
            group->baseY = 180;
        }

        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x16E + var2;
    }
}

void sub_38218(void)
{
    s16 i, j;
    struct Unk_086AEA70 sp0[14];

    for (i = 0; i < 33; i++)
        gUnknown_0202D880[i] = gUnknown_086BB420[i];

    sp0[12] = gUnknown_086AEA70[12];
    sp0[12].unk4 = gCurrentPinballGame->ball->positionQ0.y;
    for (i = 0; i < 12; i++)
    {
        if (gUnknown_086AEA70[i].unk4 < gCurrentPinballGame->ball->positionQ0.y)
        {
            for (j = 11; j >= i; j--)
                sp0[j + 1] = gUnknown_086AEA70[j];

            sp0[i] = gUnknown_086AEA70[12];
            sp0[i].unk4 = gCurrentPinballGame->ball->positionQ0.y;
            break;
        }
        else
        {
            sp0[i] = gUnknown_086AEA70[i];
        }
    }

    sp0[13] = gUnknown_086AEA70[13];
    for (i = 0; i < 13; i++)
    {
        if (sp0[i].unk4 < gCurrentPinballGame->unk400.y)
        {
            for (j = 12; j >= i; j--)
                sp0[j + 1] = sp0[j];

            sp0[i] = gUnknown_086AEA70[13];
            sp0[i].unk4 = gCurrentPinballGame->unk400.y;
            break;
        }
    }

    for (i = 0; i < 14; i++)
    {
        gUnknown_02031590[sp0[i].unk5 + 10] = i + 10;
        gUnknown_0202D880[i + 10] = sp0[i].unk0;
    }

    LoadSpriteSets(gUnknown_0202D880, 33, gMain.spriteGroups);
}
