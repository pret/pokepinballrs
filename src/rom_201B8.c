#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gUnknown_0847FD0C[][0x100];
extern const s16 gUnknown_086ADEB0[][2];
extern const u16 gUnknown_086ADEB2[][2];
extern const s16 gUnknown_086ADA6E[][5];
extern const u16 gUnknown_086B2FC0[][18];
extern const u8 gUnknown_08447A8C[][0x180];
extern const s16 gUnknown_086ADA58[];
extern const u8 gUnknown_083C3C2C[][0x300];
extern const u8 gUnknown_083C562C[][0x100];
extern const u8 gUnknown_083C542C[][0x80];


void sub_1F698(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;
    s16 var0;

    index = 0;
    group = &gMain.spriteGroups[14];
    if (gCurrentPinballGame->unk2BC < 60)
    {
        if (gCurrentPinballGame->unk2BC >= 27 && gCurrentPinballGame->unk2BC < 47)
        {
            index = (gCurrentPinballGame->unk2BC - 27) / 5;
            DmaCopy16(3, gUnknown_083C562C[index], (void *)0x06014280, 0x100);
            group->baseX = 176 - gCurrentPinballGame->unk58;
        }
        else
        {
            group->available = 0;
            group->baseX = 176 - gCurrentPinballGame->unk58;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk2BC >= 100 && gCurrentPinballGame->unk2BC < 120)
        {
            index = (gCurrentPinballGame->unk2BC - 100) / 5;
            DmaCopy16(3, gUnknown_083C562C[index], (void *)0x06014280, 0x100);
            group->baseX = 32 - gCurrentPinballGame->unk58;
        }
        else
        {
            group->available = 0;
            group->baseX = 32 - gCurrentPinballGame->unk58;
        }

    }

    if (group->available)
    {
        group->baseY = 296 - gCurrentPinballGame->unk5A;
        if (group->baseY > 180)
            group->baseY = 180;

        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[13];
    if (group->available)
    {
        if (gCurrentPinballGame->unk2BC < 120)
        {
            if (gCurrentPinballGame->unk2BC % 8 == 0)
                m4aSongNumStart(SE_UNKNOWN_0xC6);

            index = (gCurrentPinballGame->unk2BC % 16) / 4;
            DmaCopy16(3, gUnknown_083C542C[index], (void *)0x06014200, 0x80);
            var0 = (gCurrentPinballGame->unk2BC << 0x10) / 90;
            gCurrentPinballGame->unk2B8 -= 2;
            gCurrentPinballGame->unk2B4 += gCurrentPinballGame->unk2B8;
            if (gCurrentPinballGame->unk2BC < 30)
                gCurrentPinballGame->unk2B6 = gCurrentPinballGame->unk2BC + (Sin(var0) * 24) / 20000;
            else
                gCurrentPinballGame->unk2B6 = 30 + (Sin(var0) * 24) / 20000;

            gCurrentPinballGame->unk2BC++;
            if (gCurrentPinballGame->unk2BC == 27)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->unk2E3[1] > 0)
                {
                    gCurrentPinballGame->unk2E3[1]++;
                }
                else
                {
                    gCurrentPinballGame->unk2E3[1] = 2;
                    gCurrentPinballGame->unk2E8[1] = 190;
                }
            }

            if (gCurrentPinballGame->unk2BC == 100)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->unk2E3[0] > 0)
                {
                    gCurrentPinballGame->unk2E3[0]++;
                }
                else
                {
                    gCurrentPinballGame->unk2E3[0] = 2;
                    gCurrentPinballGame->unk2E8[0] = 190;
                }
            }
        }
        else
        {
            gCurrentPinballGame->unk2BC = 0;
            gCurrentPinballGame->unk2B4 = 0;
            gCurrentPinballGame->unk2B6 = 190;
            gCurrentPinballGame->unk2B8 = 100;
            gCurrentPinballGame->unk2BA = 0;
            group->available = 0;
        }

        group->baseX = (gCurrentPinballGame->unk2B4 / 20) + 71u - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk2B6 + 248u - gCurrentPinballGame->unk5A;
        if (group->baseY > 190)
            group->baseY = 190;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_1FA48(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[53];
    if (gCurrentPinballGame->unk2B2)
    {
        index = gUnknown_086ADA58[gCurrentPinballGame->unk2B0 / 5];
        if (gCurrentPinballGame->unk2B0 == 40)
        {
            gCurrentPinballGame->unk2BC = 0;
            gCurrentPinballGame->unk2B4 = 0;
            gCurrentPinballGame->unk2B6 = 0;
            gCurrentPinballGame->unk2B8 = 100;
            gCurrentPinballGame->unk2BA = 0;
            gMain.spriteGroups[13].available = 1;
        }

        if (gCurrentPinballGame->unk2B0 < 54)
            gCurrentPinballGame->unk2B0++;
        else
            gCurrentPinballGame->unk2B2 = 0;

        DmaCopy16(3, gUnknown_083C3C2C[index], (void *)0x06012720, 0x300);
    }
    else
    {
        index = (gMain.systemFrameCount % 50) / 25;
        if (gCurrentPinballGame->unk1BC == 1)
        {
            DmaCopy16(3, gUnknown_083C3C2C[index], (void *)0x06012720, 0x300);
        }
    }

    group->baseX = 55 - gCurrentPinballGame->unk58;
    group->baseY = 221 - gCurrentPinballGame->unk5A;
    i = 0;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_1FBC4(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const s16 *var0;
    s16 index;

    var0 = gUnknown_086ADA6E[gCurrentPinballGame->unk2C2];
    group = &gMain.spriteGroups[57];
    group->baseX = 9 - gCurrentPinballGame->unk58;
    group->baseY = 288 - gCurrentPinballGame->unk5A;
    if (gCurrentPinballGame->unk2BE > gCurrentPinballGame->unk6BD)
    {
        if (gCurrentPinballGame->unk6BE)
        {
            if (gCurrentPinballGame->unk6C0 == 0)
            {
                gCurrentPinballGame->unk2C2 = 59;
                gCurrentPinballGame->unk2C0 = 0;
                gCurrentPinballGame->unk6C0++;
            }

            if (var0[1] > gCurrentPinballGame->unk2C0)
            {
                gCurrentPinballGame->unk2C0++;
            }
            else
            {
                gCurrentPinballGame->unk2C0 = 1;
                gCurrentPinballGame->unk2C2++;
                if (gCurrentPinballGame->unk2C2 == 84)
                {
                    gCurrentPinballGame->unk2C2 = 0;
                    gCurrentPinballGame->unk6BE = 0;
                    gCurrentPinballGame->unk6C0 = 0;
                    gCurrentPinballGame->unk2BE = 0;
                }

                if (gCurrentPinballGame->unk2C2 == 60 || gCurrentPinballGame->unk2C2 == 69 || gCurrentPinballGame->unk2C2 == 78)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
    }
    else if (gCurrentPinballGame->unk2BE < gCurrentPinballGame->unk6BD)
    {
        if (var0[1] <= gCurrentPinballGame->unk2C0)
        {
            gCurrentPinballGame->unk2C0 = 1;
            gCurrentPinballGame->unk2C2++;
            if (gCurrentPinballGame->unk6BD == 1)
            {
                if (gCurrentPinballGame->unk2C2 == 9)
                {
                    gCurrentPinballGame->unk2BE = 1;
                    gCurrentPinballGame->unk2C2 = 84;
                }

                if (gCurrentPinballGame->unk2C2 == 6)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->unk6BD == 2)
            {
                if (gCurrentPinballGame->unk2C2 == 23)
                {
                    gCurrentPinballGame->unk2BE = 2;
                    gCurrentPinballGame->unk2C2 = 95;
                }

                if (gCurrentPinballGame->unk2C2 == 20)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->unk6BD == 3)
            {
                if (gCurrentPinballGame->unk2C2 == 35)
                {
                    gCurrentPinballGame->unk2BE = 3;
                    gCurrentPinballGame->unk2C2 = 35;
                    sub_19B64(7);
                }

                if (gCurrentPinballGame->unk2C2 == 32)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
        else
        {
            gCurrentPinballGame->unk2C0++;
        }
    }
    else if (gCurrentPinballGame->unk6BD)
    {
        if (var0[1] > gCurrentPinballGame->unk2C0)
        {
            gCurrentPinballGame->unk2C0++;
        }
        else
        {
            gCurrentPinballGame->unk2C0 = 1;
            gCurrentPinballGame->unk2C2++;
            if (gCurrentPinballGame->unk6BD == 1)
            {
                if (gCurrentPinballGame->unk2C2 == 95)
                    gCurrentPinballGame->unk2C2 = 84;
            }
            else if (gCurrentPinballGame->unk6BD == 2)
            {
                if (gCurrentPinballGame->unk2C2 == 109)
                    gCurrentPinballGame->unk2C2 = 95;
            }
            else if (gCurrentPinballGame->unk6BD == 3)
            {
                if (gCurrentPinballGame->unk2C2 == 60)
                    gCurrentPinballGame->unk2C2 = 35;
            }
        }
    }

    index = var0[0];
    DmaCopy16(3, gUnknown_08447A8C[var0[2]], (void *)0x06013B80, 0x180);
    DmaCopy16(3, gUnknown_08447A8C[var0[3]], (void *)0x06013A00, 0x180);
    DmaCopy16(3, gUnknown_08447A8C[var0[4]], (void *)0x06013880, 0x180);
    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gUnknown_086B2FC0[index][i * 3 + 0];
        *dst++ = gUnknown_086B2FC0[index][i * 3 + 1];
        *dst++ = gUnknown_086B2FC0[index][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void sub_1FF0C(void)
{
    s16 i;

    for (i = 0; i < 2; i++)
    {
        if (gCurrentPinballGame->unk2E3[i] > 0)
        {
            if (gUnknown_086ADEB2[gCurrentPinballGame->unk2E5[i]][0] > gCurrentPinballGame->unk2E8[i])
            {
                gCurrentPinballGame->unk2E8[i]++;
            }
            else
            {
                gCurrentPinballGame->unk2E8[i] = 0;
                gCurrentPinballGame->unk2E5[i]++;
                if (gCurrentPinballGame->unk2E5[i] > 11)
                {
                    gCurrentPinballGame->unk2E5[i] = 0;
                    gCurrentPinballGame->unk2E3[i]--;
                }
            }

            if (gCurrentPinballGame->unk2E5[i] == 1)
                gCurrentPinballGame->unk2EC[i] = gCurrentPinballGame->unk2E8[i] / 2;

            if (gCurrentPinballGame->unk2E5[i] == 11)
                gCurrentPinballGame->unk2EC[i] = 14 - gCurrentPinballGame->unk2E8[i] / 2;

            if (gCurrentPinballGame->unk2EC[i] < 3)
                gCurrentPinballGame->unk2EC[i] = 3;
        }
    }

    if (gCurrentPinballGame->unk2E2)
    {
        if (gCurrentPinballGame->unk2E2 == 1)
        {
            if (gCurrentPinballGame->unk13 != 7)
            {
                if (gCurrentPinballGame->unk13 < 3) {
                    if (gCurrentPinballGame->unk6BD < 3)
                    {
                        gCurrentPinballGame->unk6BD++;
                        if (gCurrentPinballGame->unk6BD == 1)
                        {
                            gCurrentPinballGame->unk2C2 = 0;
                            gCurrentPinballGame->unk2C0 = 0;
                        }
                        else if (gCurrentPinballGame->unk6BD == 2)
                        {
                            gCurrentPinballGame->unk2C2 = 12;
                            gCurrentPinballGame->unk2C0 = 0;
                        }
                        else if (gCurrentPinballGame->unk6BD == 3)
                        {
                            gCurrentPinballGame->unk2C2 = 24;
                            gCurrentPinballGame->unk2C0 = 0;
                            gCurrentPinballGame->unk6C2 = 1;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->unk6BD < 2)
                    {
                        gCurrentPinballGame->unk6BD++;
                        if (gCurrentPinballGame->unk6BD == 1)
                        {
                            gCurrentPinballGame->unk2C2 = 0;
                            gCurrentPinballGame->unk2C0 = 0;
                        }
                        else if (gCurrentPinballGame->unk6BD == 2)
                        {
                            gCurrentPinballGame->unk2C2 = 12;
                            gCurrentPinballGame->unk2C0 = 0;
                        }
                    }
                }
            }
        }
        else
        {
            if (gCurrentPinballGame->unk300 == 0)
                gCurrentPinballGame->unk300 = 1;
            else
                gCurrentPinballGame->unk300 = 0;
        }

        gCurrentPinballGame->unk2E3[0] = 0;
        gCurrentPinballGame->unk2E3[1] = 0;
        gCurrentPinballGame->unk2E2 = 0;
        sub_11B0(7);
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->unk3C = 3000;
        gCurrentPinballGame->unk2E5[0] = 0;
        gCurrentPinballGame->unk2E5[1] = 0;
        gCurrentPinballGame->unk2E8[0] = 0;
        gCurrentPinballGame->unk2E8[1] = 0;
        gCurrentPinballGame->unk2EC[0] = 3;
        gCurrentPinballGame->unk2EC[1] = 3;
    }
}

void sub_201B8(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    for (i = 0; i < 2; i++)
    {
        index = gUnknown_086ADEB0[gCurrentPinballGame->unk2E5[i]][0];
        DmaCopy16(3, gUnknown_0847FD0C[index], (void *)0x06012A20 + i * 0x100, 0x100);
        group = &gMain.spriteGroups[59 + i];
        if (group->available)
        {
            int var0 = i * 120 - (gCurrentPinballGame->unk58 - 48);
            group->baseX = var0 + ((1 - (i * 2)) * (gCurrentPinballGame->unk2EC[i] - 14));
            group->baseY = 301 - gCurrentPinballGame->unk5A;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }

    if (gCurrentPinballGame->unk6C2)
    {
        gCurrentPinballGame->unk6C2--;
        if (gCurrentPinballGame->unk6C2 == 0)
        {
            if (gCurrentPinballGame->unkE4)
                gCurrentPinballGame->unk6C2 = 1;
            else
                gCurrentPinballGame->unkE4 = 4;

            if (gCurrentPinballGame->unk6C2 == 0)
            {
                gMain.unkF |= 0x1;
                gCurrentPinballGame->unkEA = 70;
                gCurrentPinballGame->unkEC = 160;
                gCurrentPinballGame->unkE8 = 0;
                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unkEE = 0;
                gCurrentPinballGame->unkF2 = 4;
                gCurrentPinballGame->unkFA = 1;
                gCurrentPinballGame->unkFB = 0;
                gCurrentPinballGame->unkF4 = 120;
                gCurrentPinballGame->unkF6 = 0;
                gCurrentPinballGame->unkF0 = 50;
                gCurrentPinballGame->unkF8 = 0;
                DmaCopy16(3, gUnknown_086ACEF8[4], (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_086ACF18[4], (void *)0x050003C0, 0x20);
                gMain.blendControl = 0xCE;
            }
        }
    }
}
