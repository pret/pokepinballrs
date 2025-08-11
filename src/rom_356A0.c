#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

#define BONUS_KECLEON_COMPLETE_POINTS 30000000

extern struct SpriteGroup gMain_spriteGroups_9;
extern struct SpriteGroup gMain_spriteGroups_12;
extern struct SpriteGroup gMain_spriteGroups_14;
extern struct SpriteGroup gMain_spriteGroups_31;

extern void sub_35D54(void);
extern void sub_36CB4(void);
extern void sub_372B4(void);
extern void sub_3751C(void);
extern void sub_37850(void);
extern void sub_38218(void);

extern const u8 gUnknown_0813A854[0x2000];

struct Unk_086AE9E4
{
    u8 unk0[4];
    u16 unk4[2];
};

extern const struct Unk_086AE9E4 gUnknown_086AE9E4[];

extern const u16 gUnknown_086AE718[][3];
extern struct SongHeader gUnknown_086A1ABC;
extern struct SongHeader gUnknown_086A1B9C;
extern struct SongHeader gUnknown_086A1BC8;
extern struct SongHeader gUnknown_086A1C00;
extern struct SongHeader gUnknown_086A1C64;
extern struct SongHeader gUnknown_086A1C88;
extern struct SongHeader gUnknown_086A1CCC;
extern struct SongHeader gUnknown_086A1D64;
extern const u16 gUnknown_086AE9C4[];
extern const u16 gUnknown_086AE9D4[];
extern const u8 gUnknown_0844F98C[][0x280];
extern const u16 gUnknown_086B9DAC[][2][3];
extern const u16 gUnknown_086B9AB8[][2][3];
extern const u8 gUnknown_0845588C[][0x100];


void sub_356A0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain_spriteGroups_14;
    switch (gCurrentPinballGame->unk3DC)
    {
    case 0:
    case 1:
    case 8:
        if (!group->available)
            break;

        group->baseX = 240;
        group->baseY = 160;
        
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 240;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case 2:
        if (gCurrentPinballGame->unk3E6 <= 0)
            break;

        if (!group->available)
            break;

        group->baseX = 240;
        group->baseY = 160;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 240;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }

    group = &gMain_spriteGroups_12;
    if (!group->available)
        return;

    group->baseX = 240;
    group->baseY = 160;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_357B8(void)
{
    u8 temp;

    m4aMPlayAllStop();
    sub_0D10();

    temp = gMain.unk5;
    gMain.unk5 = gMain.selectedField;
    gMain.selectedField = temp;
    gMain.unk6 = 0;
    gMain.unkF = 0;
    gCurrentPinballGame->eventTimer = 0;
    gCurrentPinballGame->unk294 = 0;
    if (gCurrentPinballGame->numCompletedBonusStages > 4)
        gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD] = 1;

    gMain.subState = 0;
    gCurrentPinballGame->unk15 = 3;
    gCurrentPinballGame->unk13 = 1;
    gCurrentPinballGame->unk16 = 0;
    gCurrentPinballGame->unk5FA = 0;
    gCurrentPinballGame->unkE6 = 0;
    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    if (gCurrentPinballGame->unk714)
        gCurrentPinballGame->unk6EE = 120;
}

void sub_35860(void)
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

void sub_35AA4(void)
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
            DmaCopy16(3, gUnknown_0813A854, (void *)0x6015800, 0x2000);
            gCurrentPinballGame->unk394 = 0x88;
            gMain.unkF = 0x80;
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
            gCurrentPinballGame->unk3C = BONUS_KECLEON_COMPLETE_POINTS;
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
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1ABC);
        }

        if (gCurrentPinballGame->unk3E2 == 64)
        {
            gCurrentPinballGame->unk3FA = gCurrentPinballGame->unk3E4 / 2;
            if (gCurrentPinballGame->unk3E4 == 4)
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1B9C);
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
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1BC8);

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
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1C00);
            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 3)
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1C00);
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
        MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1C64);
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
        gCurrentPinballGame->unk3C = 500000;
        gCurrentPinballGame->unk385++;
        MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1C88);
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
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1CCC);

            if (gCurrentPinballGame->unk3E2 == gCurrentPinballGame->unk3DE + 8)
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1D64);
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
    DmaCopy16(3, gUnknown_0844F98C[sp0], (void *)0x6010920, 0x280);
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

    DmaCopy16(3, gUnknown_0845588C[var0 - var1], (void *)0x6010BA0, 0x100);
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
