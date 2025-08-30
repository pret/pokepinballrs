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
extern const u8 gUnknown_084FA48C[][0x120];
extern const u8 gUnknown_084F5ACC[][0x260];
extern const s16 gUnknown_086AD9FC[][2];
extern const u16 gUnknown_086B3A04[][3][3];
extern const u8 gUnknown_083C806C[][0x100];
extern const u8 gUnknown_0844928C[][0x100];
extern const u8 gUnknown_08137998[];
extern const u8 gUnknown_081379B8[];

extern struct SongHeader gUnknown_0869F2A0;
extern struct SongHeader gUnknown_0869F240;


void sub_1EC48(void)
{
    s16 i;
    s16 j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->unk624 > 0)
    {
        if (gCurrentPinballGame->unk624 == 2)
        {
            gCurrentPinballGame->unk3C = 500;
            m4aSongNumStart(SE_UNKNOWN_0xB6);
            sub_11B0(7);
            if (gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 5 && gCurrentPinballGame->unk625 < 6)
            {
                if (gCurrentPinballGame->unk625 == 0)
                    gCurrentPinballGame->unk625 = 1;
                else if (gCurrentPinballGame->unk625 == 1)
                    gCurrentPinballGame->unk625 = 3;
                else
                    gCurrentPinballGame->unk625 = 6;

                if (gCurrentPinballGame->unk625 == 6)
                {
                    if (gCurrentPinballGame->unk6C6 == 0)
                    {
                        if (gCurrentPinballGame->unk16C == 4)
                        {
                            gMain.unkF |= 0x1;
                            gCurrentPinballGame->unkEA = 50;
                            gCurrentPinballGame->unkEC = 600;
                            gCurrentPinballGame->unkE8 = 236;
                            gCurrentPinballGame->unkE6 = 0;
                            gCurrentPinballGame->unkEE = 4;
                            gCurrentPinballGame->unkF2 = 6;
                            gCurrentPinballGame->unkFA = 1;
                            gCurrentPinballGame->unkFB = 0;
                            gCurrentPinballGame->unkF4 = 80;
                            gCurrentPinballGame->unkF6 = -2500;
                            gCurrentPinballGame->unkF0 = 50;
                            gCurrentPinballGame->unkF8 = 0;
                            DmaCopy16(3, gUnknown_086ACEF8[6], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gUnknown_086ACF18[6], (void *)0x050003C0, 0x20);
                        }
                        else
                        {
                            gMain.unkF |= 0x1;
                            gCurrentPinballGame->unkEA = 50;
                            gCurrentPinballGame->unkEC = 600;
                            gCurrentPinballGame->unkE8 = 236;
                            gCurrentPinballGame->unkE6 = 0;
                            gCurrentPinballGame->unkEE = 4;
                            gCurrentPinballGame->unkF2 = 1;
                            gCurrentPinballGame->unkFA = 1;
                            gCurrentPinballGame->unkFB = 0;
                            gCurrentPinballGame->unkF4 = 80;
                            gCurrentPinballGame->unkF6 = -2500;
                            gCurrentPinballGame->unkF0 = 50;
                            gCurrentPinballGame->unkF8 = 0;
                            DmaCopy16(3, gUnknown_086ACEF8[1], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gUnknown_086ACF18[1], (void *)0x050003C0, 0x20);
                        }

                        gMain.blendControl = 0xCE;
                    }
                }
            }

            gCurrentPinballGame->unk176++;
            gCurrentPinballGame->unk308++;
        }

        gCurrentPinballGame->unk624--;
    }

    group = &gMain.spriteGroups[62];
    if (gCurrentPinballGame->unk16C == 4)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->unk170[i])
            {
                if (gCurrentPinballGame->unk170[i] > 100)
                {
                    gCurrentPinballGame->unk170[i]--;
                    if (gCurrentPinballGame->unk170[i] == 100)
                        gCurrentPinballGame->unk170[i] = 0;

                    var0 = 8;
                }
                else
                {
                    var0 = gCurrentPinballGame->unk170[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->unk290 % 50) / 25;
            }

            DmaCopy16(3, gUnknown_0844928C[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gUnknown_081379B8 + gCurrentPinballGame->unk6F * 0x60, (void *)0x05000320, 0x20);
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->unk170[i])
            {
                if (gCurrentPinballGame->unk170[i] > 100)
                {
                    var0 = 9 - gCurrentPinballGame->unk170[i] / 105;
                    gCurrentPinballGame->unk170[i]--;
                    if (gCurrentPinballGame->unk170[i] == 100)
                        gCurrentPinballGame->unk170[i] = 0;
                }
                else
                {
                    var0 = gCurrentPinballGame->unk170[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->unk290 % 50) / 25;
            }

            DmaCopy16(3, gUnknown_083C806C[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gUnknown_08137998 + gCurrentPinballGame->unk6F * 0x60, (void *)0x05000320, 0x20);
    }

    for (i = 0; i < 3; i++)
    {
        group->baseX = gCurrentPinballGame->unk178[i].x / 10 - gCurrentPinballGame->unk58 - 8;
        group->baseY = gCurrentPinballGame->unk178[i].y / 10 - gCurrentPinballGame->unk5A - 4;
        gCurrentPinballGame->unk184[i].x = (-(gCurrentPinballGame->unk178[i].x / 10) + 8) * 2;
        gCurrentPinballGame->unk184[i].y = (-(gCurrentPinballGame->unk178[i].y / 10) + 7) * 2;
        if (group->baseY < -40)
            group->baseY = -40;
        
        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j + i * 2];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_1F158(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 * dst;
    const u16 * src;
    s16 index;
    s16 var0;

    index = (gMain.systemFrameCount % 55) / 11;
    group = &gMain.spriteGroups[61];
    DmaCopy16(3, gUnknown_084F5ACC[gCurrentPinballGame->unk2F5], (void *)0x06012C20, 0x260);
    if (gCurrentPinballGame->unk2F4)
        index = gCurrentPinballGame->unk2F4;

    var0 = gUnknown_086AD9FC[index][0];
    gCurrentPinballGame->unk2F5 = gUnknown_086AD9FC[index][1];
    group->baseX = 179 - gCurrentPinballGame->unk58;
    group->baseY = 174 - gCurrentPinballGame->unk5A;
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B3A04[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void sub_1F2A4(void)
{
    if (gCurrentPinballGame->unk1C6 != gCurrentPinballGame->unk1C8)
    {
        gCurrentPinballGame->unk1C8 += 2;
        gCurrentPinballGame->unk1CA = gCurrentPinballGame->unk1C8 / 14;
        gCurrentPinballGame->unk1D0 = 80;
        gCurrentPinballGame->unk1D8 = 256;
        gCurrentPinballGame->unk1DA = 256;
        if (gCurrentPinballGame->unk1CA == 11)
            gCurrentPinballGame->unk1CE = 120;

        if (gCurrentPinballGame->unk1CA > 11)
        {
            gCurrentPinballGame->unk1CA = 12;
            gCurrentPinballGame->unk1D0 = 120;
            gCurrentPinballGame->unk1D8 = 256;
            gCurrentPinballGame->unk1DA = 256;
        }

        if (gCurrentPinballGame->unk1C8 < 168 && gCurrentPinballGame->unk1C8 % 8 == 0)
        {
            s8 offset = gCurrentPinballGame->unk1C8 / 21;
            m4aSongNumStart(SE_UNKNOWN_0xA8 + offset);
        }

        if (gCurrentPinballGame->unk1C6 <= gCurrentPinballGame->unk1C8)
        {
            gCurrentPinballGame->unk1C8 = gCurrentPinballGame->unk1C6;
            if (gCurrentPinballGame->unk1C8 >= 168)
            {
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F2A0);
                gCurrentPinballGame->unk3C = 3000;
            }
        }
    }

    if (gCurrentPinballGame->unk616)
        gCurrentPinballGame->unk616--;

    if (gCurrentPinballGame->unk614 > 0)
    {
        gCurrentPinballGame->unk614 -= 3;
        if (gCurrentPinballGame->unk614 < 0)
            gCurrentPinballGame->unk614 = 0;

        if (gCurrentPinballGame->unk618 < gCurrentPinballGame->unk61A - 1)
        {
            gCurrentPinballGame->unk618++;
        }
        else
        {
            gCurrentPinballGame->unk618 = 0;
            MPlayStart(&gUnknown_02032FB0, &gUnknown_0869F240);
            gCurrentPinballGame->unk3C = 100;
            if (gCurrentPinballGame->unk1CA < 12 && gCurrentPinballGame->unk61C == 0)
            {
                gCurrentPinballGame->unk1D0 = 80;
                gCurrentPinballGame->unk1D8 = 256;
                gCurrentPinballGame->unk1DA = 256;
            }
        }

        gCurrentPinballGame->unk61A = (450 - gCurrentPinballGame->unk614) / 10;
        if (gCurrentPinballGame->unk61A < 5)
            gCurrentPinballGame->unk61A = 5;

        gCurrentPinballGame->unk1E5 = (gCurrentPinballGame->unk618 * 16) / gCurrentPinballGame->unk61A;
    }
    else
    {
        if (gCurrentPinballGame->unk614 < 0)
        {
            gCurrentPinballGame->unk614 += 3;
            if (gCurrentPinballGame->unk614 > 0)
                gCurrentPinballGame->unk614 = 0;

            if (gCurrentPinballGame->unk618 < gCurrentPinballGame->unk61A - 1)
            {
                gCurrentPinballGame->unk618++;
            }
            else
            {
                gCurrentPinballGame->unk618 = 0;
                MPlayStart(&gUnknown_02032FB0, &gUnknown_0869F240);
                gCurrentPinballGame->unk3C = 100;
                if (gCurrentPinballGame->unk1CA < 12 && gCurrentPinballGame->unk61C == 0)
                {
                    gCurrentPinballGame->unk1D0 = 80;
                    gCurrentPinballGame->unk1D8 = 256;
                    gCurrentPinballGame->unk1DA = 256;
                }
            }

            gCurrentPinballGame->unk61A = (450 + gCurrentPinballGame->unk614) / 10;
            if (gCurrentPinballGame->unk61A < 5)
                gCurrentPinballGame->unk61A = 5;

            gCurrentPinballGame->unk1E5 = (gCurrentPinballGame->unk618 * 16) / gCurrentPinballGame->unk61A;
        }
        else
        {
            if (gCurrentPinballGame->unk1E5 > 0)
            {
                gCurrentPinballGame->unk618++;
                gCurrentPinballGame->unk618 %= 40;
                gCurrentPinballGame->unk1E5 = (gCurrentPinballGame->unk618 * 16) / 40;
            }
        }
    }
}

void sub_1F59C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    index = gCurrentPinballGame->unk1E5;
    group = gMain.unk44[31];
    group->baseX = 206 - gCurrentPinballGame->unk58;
    if (gMain.selectedField == FIELD_RUBY)
        group->baseY = 174 - gCurrentPinballGame->unk5A;
    else
        group->baseY = 154 - gCurrentPinballGame->unk5A;

    if (gCurrentPinballGame->unk1E5 != gCurrentPinballGame->unk1E6)
    {
        gCurrentPinballGame->unk1E6 = gCurrentPinballGame->unk1E5;
        DmaCopy16(3, gUnknown_084FA48C[index], (void *)0x06010780, 0x120);
    }

    for (i = 0; i < 4; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

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
