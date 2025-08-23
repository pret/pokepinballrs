#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const s16 gUnknown_086AE45A[];
extern const s16 gUnknown_086AE3DC[][3];
extern const s8 gUnknown_08137CBC[][2];
extern const u8 gUnknown_084BB16C[][0x480];
extern const u16 gUnknown_086B3EF6[][4][3];
extern const s16 gUnknown_086AE462[][2];
extern const u8 gUnknown_083FFD8C[][0x300];
extern const u16 gUnknown_086B4A72[][2][3];
extern const u8 gUnknown_08526DCC[];
extern const s16 gUnknown_086AE496[][3];
extern const u8 gUnknown_08512C4C[][0x380];
extern const u16 gUnknown_086B3CA4[][3][3];
extern const u16 gUnknown_086B3B7E[][7][3];
extern const u8 gUnknown_084ED6CC[][0x200];
extern const s16 gUnknown_086AE4FC[][2];
extern const s16 gUnknown_08137CD6[];

extern struct SongHeader gUnknown_086A11A4;


void sub_2E67C(void)
{
    if (gCurrentPinballGame->unk306 == 1)
    {
        if (gCurrentPinballGame->unk30C)
            gCurrentPinballGame->unk30C--;
        else
            gCurrentPinballGame->unk306 = 0;
    }
}

void sub_2E6AC(void)
{
    s16 i;
    struct SpriteGroup *group = &gMain.spriteGroups[60];
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var_sl;
    s16 sp0;
    s16 index;

    var_sl = 0;
    sp0 = 0;
    switch (gCurrentPinballGame->unk306)
    {
    case 0:
        gCurrentPinballGame->unk30E = 0;
        var_sl = (gCurrentPinballGame->unk290 % 50) / 25;
        gCurrentPinballGame->unk320 = 0;
        gCurrentPinballGame->unk322 = 0;
        break;
    case 1:
        var_sl = gUnknown_086AE45A[(gCurrentPinballGame->unk290 % 40) / 10];
        gCurrentPinballGame->unk320 = 0;
        gCurrentPinballGame->unk322 = 0;
        gCurrentPinballGame->unk307 = 0;
        gCurrentPinballGame->unk30A = 0;
        if (gCurrentPinballGame->unk13 > 2)
        {
            gCurrentPinballGame->unk306 = 0;
            var_sl = 0;
        }
        break;
    case 2:
        var_sl = 4;
        break;
    case 3:
        if (gCurrentPinballGame->unk30C < 3)
        {
            if (gCurrentPinballGame->unk30C == 0)
            {
                gCurrentPinballGame->unk5F7 = 1;
                gCurrentPinballGame->unk1F = 1;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
                gCurrentPinballGame->ball->unk6 = 0;
                m4aSongNumStart(SE_UNKNOWN_0xE2);
                sub_11B0(7);
                gCurrentPinballGame->unk3C = 100000;
            }

            gCurrentPinballGame->ball->positionQ0.x = 156;
            gCurrentPinballGame->ball->positionQ0.y = 121 + gCurrentPinballGame->unk30C * 2;
            var_sl = 4;
        }
        else if (gCurrentPinballGame->unk30C < 23)
        {
            gCurrentPinballGame->ball->positionQ0.x = 157;
            gCurrentPinballGame->ball->positionQ0.y = 134;
            gCurrentPinballGame->ball->unk0 = 1;
            var_sl = 5;
        }
        else
        {
            gCurrentPinballGame->unk306 = 4;
            gCurrentPinballGame->unk30C = 0;
            var_sl = 2;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->unk30C++;
        gCurrentPinballGame->unk310 = 0;
        break;
    case 4:
        if (gUnknown_086AE3DC[gCurrentPinballGame->unk307][2] > gCurrentPinballGame->unk30A)
        {
            gCurrentPinballGame->unk30A++;
        }
        else
        {
            gCurrentPinballGame->unk30A = 0;
            gCurrentPinballGame->unk307++;
            if (gCurrentPinballGame->unk307 == 21)
            {
                gCurrentPinballGame->unk307 = 20;
                gCurrentPinballGame->unk306 = 5;
                gCurrentPinballGame->unk30C = 0;
            }

            if (gCurrentPinballGame->unk307 == 1)
                m4aSongNumStart(SE_UNKNOWN_0xE3);
        }

        sp0 = gUnknown_086AE3DC[gCurrentPinballGame->unk307][0];
        var_sl = gUnknown_086AE3DC[gCurrentPinballGame->unk307][1];
        if (gCurrentPinballGame->unk310++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 5:
        if (gCurrentPinballGame->unk30C == 0)
        {
            gCurrentPinballGame->unk320 = -360;
            gCurrentPinballGame->unk322 = -200;
        }

        index = (gCurrentPinballGame->unk30C % 26) / 2;
        var_sl = gUnknown_08137CBC[index][0];
        gCurrentPinballGame->unk30E = gUnknown_08137CBC[index][1] * 10;
        gCurrentPinballGame->unk31C = -12;
        gCurrentPinballGame->unk31E = -10;
        gCurrentPinballGame->unk320 += gCurrentPinballGame->unk31C;
        gCurrentPinballGame->unk322 += gCurrentPinballGame->unk31E;
        gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->unk320 / 10 + 157;
        gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->unk322 / 10 + 134;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->unk30C++;
        if (gCurrentPinballGame->ball->positionQ0.y < -12)
        {
            if (gCurrentPinballGame->unk308 > 99)
            {
                gCurrentPinballGame->unk308 = 0;
                gCurrentPinballGame->unk306 = 6;
                gCurrentPinballGame->unk30C = 65;
                m4aMPlayAllStop();
            }
            else
            {
                gCurrentPinballGame->unk30C = 0;
                gCurrentPinballGame->unk306 = 7;
            }
        }

        if (gCurrentPinballGame->unk310++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 6:
        gCurrentPinballGame->unk1100 = 1;
        var_sl = gUnknown_08137CBC[0][0];
        if (gCurrentPinballGame->unk30C == 65)
        {
            m4aSongNumStart(SE_UNKNOWN_0x9F);
            gMain.blendControl = 0x9E;
        }

        if (gCurrentPinballGame->unk30C)
        {
            gCurrentPinballGame->unk30C--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->unk30C / 4;
            if (gCurrentPinballGame->unk30C == 0)
            {
                gCurrentPinballGame->unk284 = 7;
                gCurrentPinballGame->unk282 = 2;
                gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
                gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
                sub_1C73C();
            }
        }
        break;
    case 7:
        gCurrentPinballGame->unk320 = -1880;
        gCurrentPinballGame->unk322 = -800;
        gCurrentPinballGame->unk31C = 82;
        gCurrentPinballGame->unk31E = 0;
        gCurrentPinballGame->unk30C = 0;
        gCurrentPinballGame->unk306 = 8;
        var_sl = 13;
        sp0 = 9;
        break;
    case 8:
        var_sl = (gCurrentPinballGame->unk30C % 24) / 6 + 13;
        gCurrentPinballGame->unk30E = (Sin(gCurrentPinballGame->unk30C * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->unk30C == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->unk30C < 40)
        {
            gCurrentPinballGame->unk320 += gCurrentPinballGame->unk31C;
            gCurrentPinballGame->unk322 += gCurrentPinballGame->unk31E;
        }
        else if (gCurrentPinballGame->unk30C >= 70)
        {
            gCurrentPinballGame->unk30C = 0;
            gCurrentPinballGame->unk306 = 9;
            gCurrentPinballGame->unk320 = 1200;
            gCurrentPinballGame->unk322 = -1000;
            m4aSongNumStart(SE_UNKNOWN_0xE3);
            gCurrentPinballGame->unk310 = 0;
        }

        if (gCurrentPinballGame->unk30C == 13)
        {
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk314 = 5;
            gCurrentPinballGame->unk316 = -25;
            gCurrentPinballGame->unk318 = (gCurrentPinballGame->unk320 / 10 + 157) * 10;
            gCurrentPinballGame->unk31A = (gCurrentPinballGame->unk322 / 10 + 134) * 10;
            gCurrentPinballGame->ball->unk1 = 1;
        }

        if (gCurrentPinballGame->unk1F)
        {
            if (gCurrentPinballGame->unk30C < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->unk320 / 10 + 157;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->unk322 / 10 + 134;
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
                if (gCurrentPinballGame->ball->positionQ0.y >= 91)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 91;
                    gCurrentPinballGame->unk5F7 = 0;
                    gCurrentPinballGame->unk1F = 0;
                    gCurrentPinballGame->ball->velocity.x = 128;
                    gCurrentPinballGame->ball->velocity.y = 256;
                    gCurrentPinballGame->ball->unk1 = 3;
                    gCurrentPinballGame->unk24 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0xE5);
                    sub_11B0(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        sp0 = 9;
        gCurrentPinballGame->unk30C++;
        break;
    case 9:
        index = (gCurrentPinballGame->unk30C % 26) / 2;
        var_sl = gUnknown_08137CBC[index][0] + 4;
        gCurrentPinballGame->unk30E = gUnknown_08137CBC[index][1];
        gCurrentPinballGame->unk31C = -12;
        gCurrentPinballGame->unk31E = 10;
        if (gCurrentPinballGame->unk30C < 100)
        {
            gCurrentPinballGame->unk320 += gCurrentPinballGame->unk31C;
            gCurrentPinballGame->unk322 += gCurrentPinballGame->unk31E;
        }
        else
        {
            gCurrentPinballGame->unk30C = 0;
            gCurrentPinballGame->unk306 = 10;
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A11A4);
        }

        if (gCurrentPinballGame->unk310++ % 35 == 34)
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A11A4);

        gCurrentPinballGame->unk30C++;
        break;
    case 10:
        gCurrentPinballGame->unk30E = 0;
        gCurrentPinballGame->unk306 = 0;
        gCurrentPinballGame->unk30C = 0;
        var_sl = 0;
        break;
    }

    if (group->available)
    {
        DmaCopy16(3, gUnknown_084BB16C[var_sl], (void *)0x060122A0, 0x480);
        group->baseX = gCurrentPinballGame->unk320 / 10 + 146 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk322 / 10 + 110 - gCurrentPinballGame->unk5A + gCurrentPinballGame->unk30E / 10;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B3EF6[sp0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }
}

void sub_2F140(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 var0;

    index = (gCurrentPinballGame->unk290 % 32) / 16;
    group = &gMain.spriteGroups[75];
    if (gCurrentPinballGame->unk2F4)
        index = gCurrentPinballGame->unk2F4;

    var0 = gUnknown_086AE462[index][0];
    index = gUnknown_086AE462[index][1];
    group->baseX = 164 - gCurrentPinballGame->unk58;
    group->baseY = 166 - gCurrentPinballGame->unk5A;
    DmaCopy16(3, gUnknown_083FFD8C[index], (void *)0x06012720, 0x300);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B4A72[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void sub_2F26C(void)
{
    s16 var0;

    switch (gCurrentPinballGame->unk378)
    {
    case 0:
        gCurrentPinballGame->unk379 = (gCurrentPinballGame->unk290 % 50) / 25 + 2;
        gCurrentPinballGame->unk37A = gCurrentPinballGame->unk379 + 1;
        gCurrentPinballGame->unk37C = 0;
        break;
    case 1:
        var0 = gCurrentPinballGame->unk290 % 33;
        if (var0 < 13)
        {
            gCurrentPinballGame->unk379 = 0;
            gCurrentPinballGame->unk37A = 0;
        }
        else if (var0 < 20)
        {
            gCurrentPinballGame->unk379 = 9;
            gCurrentPinballGame->unk37A = 1;
        }
        else if (var0 < 26)
        {
            gCurrentPinballGame->unk379 = 1;
            gCurrentPinballGame->unk37A = 2;
        }
        else
        {
            gCurrentPinballGame->unk379 = 9;
            gCurrentPinballGame->unk37A = 1;
        }

        if (gCurrentPinballGame->unk25 != 4)
            gCurrentPinballGame->unk37C = 0;
        return;
    case 2:
        gCurrentPinballGame->unk37C = 0;
        gCurrentPinballGame->unk37D = 0;
        gCurrentPinballGame->unk37E = 0;
        gCurrentPinballGame->unk378 = 3;
        gCurrentPinballGame->unk37B = 0;
        gMain.spriteGroups[27].available = 1;
        gCurrentPinballGame->unkE4 = 22;
        DmaCopy16(3, gUnknown_08526DCC, (void *)0x06015800, 0xC00);
        m4aSongNumStart(SE_UNKNOWN_0xEC);
        gCurrentPinballGame->unk3C = 5000;
        break;
    case 3:
        if (gUnknown_086AE496[gCurrentPinballGame->unk37D][1] > gCurrentPinballGame->unk37E)
        {
            gCurrentPinballGame->unk37E++;
        }
        else
        {
            gCurrentPinballGame->unk37D++;
            gCurrentPinballGame->unk37E = 0;
            if (gCurrentPinballGame->unk37D > 16)
            {
                gCurrentPinballGame->unk37D = 16;
                gCurrentPinballGame->unk378 = 4;
            }
        }

        gCurrentPinballGame->unk37A = gUnknown_086AE496[gCurrentPinballGame->unk37D][0];
        gCurrentPinballGame->unk379 = gUnknown_086AE496[gCurrentPinballGame->unk37D][2];
        if (gCurrentPinballGame->unk37D < 6)
            gCurrentPinballGame->unk37B = gCurrentPinballGame->unk37D + 1;
        else
            gCurrentPinballGame->unk37B = 0;
        break;
    case 4:
        gCurrentPinballGame->unkE4 = 0;
        gMain.spriteGroups[27].available = 0;
        gCurrentPinballGame->unk378 = 0;
        break;
    }
}

void sub_2F504(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    
    group = &gMain.spriteGroups[26];
    if (group->available)
    {
        group->baseX = 198 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk380 + 284 - gCurrentPinballGame->unk5A;
        index = gCurrentPinballGame->unk379;
        DmaCopy16(3, gUnknown_08512C4C[index], (void *)0x06012A20, 0x380);
        index = gCurrentPinballGame->unk37A;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B3CA4[index][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = &gMain.spriteGroups[27];
    if (group->available)
    {
        group->baseX = 198 - gCurrentPinballGame->unk58;
        group->baseY = 284 - gCurrentPinballGame->unk5A;
        index = gCurrentPinballGame->unk37B;
        for (i = 0; i < 7; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B3B7E[index][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = &gMain.spriteGroups[70];
    if (group->available)
    {
        group->baseX = 206 - gCurrentPinballGame->unk58;
        if (gCurrentPinballGame->unk37C)
        {
            group->baseY = 260 - gCurrentPinballGame->unk5A;
            index = (gCurrentPinballGame->unk290 % 50) / 25;
            DmaCopy16(3, &gUnknown_084ED6CC[index], (void *)0x06014FA0, 0x200);
        }
        else
        {
            group->baseY = 200;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_2F79C(void)
{
    s16 i;
    u32 mosaicVal;

    for (i = 0; i < 2; i++)
    {
        switch (gCurrentPinballGame->unk36A[i])
        {
        case 0:
            if (gUnknown_086AE4FC[gCurrentPinballGame->unk36C[i]][1] > gCurrentPinballGame->unk36E[i])
            {
                gCurrentPinballGame->unk36E[i]++;
            }
            else
            {
                gCurrentPinballGame->unk36C[i]++;
                gCurrentPinballGame->unk36E[i] = 0;
                if (gCurrentPinballGame->unk36C[i] > 3)
                    gCurrentPinballGame->unk36C[i] = 0;
            }

            if (gCurrentPinballGame->unk372[i] < 152)
                gCurrentPinballGame->unk372[i]++;
            else
                gCurrentPinballGame->unk372[i] = 0;
            break;
        case 1:
            if (gUnknown_086AE4FC[gCurrentPinballGame->unk36C[i]][1] > gCurrentPinballGame->unk36E[i])
            {
                gCurrentPinballGame->unk36E[i]++;
            }
            else
            {
                gCurrentPinballGame->unk36C[i]++;
                gCurrentPinballGame->unk36E[i] = 0;
                if (gCurrentPinballGame->unk36C[i] == 5)
                {
                    m4aSongNumStart(SE_UNKNOWN_0xE6);
                    gCurrentPinballGame->unk3C = 2000;
                }
            }

            if (gCurrentPinballGame->unk36C[i] == 6)
            {
                if (gCurrentPinballGame->unk376)
                {
                    if (gCurrentPinballGame->unk376 == 1)
                    {
                        gCurrentPinballGame->unk36C[i] = 7;
                        gCurrentPinballGame->unk36A[i] = 2;
                    }
                }

                gCurrentPinballGame->unk36E[i] = 0;
            }

            gCurrentPinballGame->unk372[i] = 20;
            break;
        case 2:
            if (gUnknown_086AE4FC[gCurrentPinballGame->unk36C[i]][1] > gCurrentPinballGame->unk36E[i])
            {
                gCurrentPinballGame->unk36E[i]++;
            }
            else
            {
                gCurrentPinballGame->unk36C[i]++;
                gCurrentPinballGame->unk36E[i] = 0;
                if (gCurrentPinballGame->unk36C[i] == 8)
                    m4aSongNumStart(SE_UNKNOWN_0xE7);

                if (gCurrentPinballGame->unk36C[i] > 8)
                {
                    gCurrentPinballGame->unk36C[i] = 0;
                    gCurrentPinballGame->unk36A[i] = 0;
                }
            }

            gCurrentPinballGame->unk372[i] = 20;
            break;
        case 3:
            gCurrentPinballGame->unk36C[i] = 9;
            gCurrentPinballGame->unk36E[i] = 0;
            gCurrentPinballGame->unk36A[i] = 4;
            gCurrentPinballGame->unk372[i] = 20;
            break;
        case 4:
            if (gUnknown_086AE4FC[gCurrentPinballGame->unk36C[i]][1] > gCurrentPinballGame->unk36E[i])
            {
                gCurrentPinballGame->unk36E[i]++;
            }
            else
            {
                gCurrentPinballGame->unk36C[i]++;
                gCurrentPinballGame->unk36E[i] = 0;
                if (gCurrentPinballGame->unk36C[i] > 17)
                {
                    if (gCurrentPinballGame->unk13 == 6)
                    {
                        gCurrentPinballGame->unk36C[i] = 0;
                        gCurrentPinballGame->unk36A[i] = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->unk36C[i] = 9;
                    }
                }
            }

            gCurrentPinballGame->unk372[i] = 20;
            break;
        case 5:
            if (gUnknown_086AE4FC[gCurrentPinballGame->unk36C[i]][1] > gCurrentPinballGame->unk36E[i])
            {
                gCurrentPinballGame->unk36E[i]++;
            }
            else
            {
                gCurrentPinballGame->unk36C[i]++;
                gCurrentPinballGame->unk36E[i] = 0;
                if (gCurrentPinballGame->unk36C[i] > 17)
                {
                    gCurrentPinballGame->unk36A[i] = 0;
                    gCurrentPinballGame->unk36C[i] = 0;
                }
            }

            gCurrentPinballGame->unk372[i] = 20;
            break;
        }
    }

    if (gCurrentPinballGame->unk25 != 3)
    {
        if (gCurrentPinballGame->unk376)
            gCurrentPinballGame->unk376--;
    }

    if (gCurrentPinballGame->unk1328)
    {
        gCurrentPinballGame->unk1328--;
        if (gCurrentPinballGame->unk1328 == 0)
            gCurrentPinballGame->unk1330 = gCurrentPinballGame->unk1334;
    }

    if (gCurrentPinballGame->unk368)
    {
        if (gCurrentPinballGame->unk368 == 17)
        {
            m4aSongNumStart(SE_UNKNOWN_0xE8);
            gCurrentPinballGame->unk3C = 10;
            sub_11B0(13);
        }

        mosaicVal = gUnknown_08137CD6[gCurrentPinballGame->unk368 / 3];
        REG_MOSAIC = (mosaicVal << 12) | (mosaicVal << 8) | (mosaicVal << 4) | (mosaicVal << 0);
        gCurrentPinballGame->unk368--;
    }

    if (gCurrentPinballGame->unk13 > 2)
    {
        if (gCurrentPinballGame->unk13 != 6)
        {
            for (i = 0; i < 2; i++)
            {
                if (gCurrentPinballGame->unk36A[i])
                {
                    gCurrentPinballGame->unk36A[i] = 0;
                    gCurrentPinballGame->unk36C[i] = 0;
                    gCurrentPinballGame->unk36E[i] = 0;
                }
            }
        }
    }
    else if (gCurrentPinballGame->unk72E > 2)
    {
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->unk36A[0] < 3)
            {
                gCurrentPinballGame->unk36A[0] = 3;
                gCurrentPinballGame->unk36A[1] = 3;
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->unk36A[0] > 2)
        {
            gCurrentPinballGame->unk36A[0] = 0;
            gCurrentPinballGame->unk36C[0] = 0;
            gCurrentPinballGame->unk36A[1] = 0;
            gCurrentPinballGame->unk36C[1] = 0;
        }
    }
}
