#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const u8 gUnknown_0847FD0C[][0x100];
extern const s16 gUnknown_086ADEB0[][2];
extern const u16 gUnknown_086ADEB2[][2];
extern const s16 gUnknown_086ADA6E[][5];
extern const u16 gUnknown_086B2FC0[146][18];
extern const u8 gRubyStageGulpin_Gfx[][0x180];
extern const s16 gUnknown_086ADA58[];
extern const u8 gUnknown_083C3C2C[][0x300];
extern const u8 gUnknown_083C562C[][0x100];
extern const u8 gUnknown_083C542C[][0x80];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const s16 gUnknown_086AD9FC[][2];
extern const u16 gSharpedoSpritesheetOam[42][3][3];
extern const u8 gUnknown_083C806C[][0x100];
extern const u8 gUnknown_0844928C[][0x100];
extern const u8 gUnknown_08137998[];
extern const u8 gUnknown_081379B8[];
extern const s16 gUnknown_08137968[];
extern const struct Vector16 gUnknown_086AD9DC[];
extern const s16 gWhiscashFramesetData[][4];
extern const s16 gUnknown_086AD9EC[];
extern const s16 gUnknown_0813798C[];
extern const u8 gUnknown_081379D8[];
extern const u8 gWhiscash_Gfx[][0x480];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const s16 gUnknown_086AD7C0[50][3];
extern const s16 gUnknown_086AD856[][2];
extern const u8 gRubyStageNuzleaf_Gfx[][0x280];
extern const u16 gUnknown_086B2E64[58][6];
extern const u16 gUnknown_081C00E4[];
extern const u16 gUnknown_086AD798[2];
extern const u16 gUnknown_086AD070[];
extern const u16 gUnknown_081C02E4[];
extern const s16 gUnknown_086AD79C[];

extern struct SongHeader se_unk_7a;
extern struct SongHeader se_unk_79;
extern struct SongHeader se_whiscash_splashdown;
extern struct SongHeader se_unk_142;
extern struct SongHeader se_unk_b1;
extern struct SongHeader se_unk_b3;
extern s16 gUnknown_086ADF48[100];
extern s16 gUnknown_086ADF8A[3];
extern u16 gUnknown_086ADEE0[][2];
extern s16 gUnknown_086B4922[28][12];

#define MIN_POND_SWITCHES_BEFORE_WHISCASH_AVAILABLE 3


void sub_1C7F4(s16 arg0, s16 arg1)
{
    s16 i;
    s16 var0;
    s16 sp0[16];
    s16 rgb[3];
    u16 index;
    const u16 *ptr;
    const u16 *ptr2;
    u16 index2;

    switch (arg0)
    {
    case 0:
        gCurrentPinballGame->unk6DB = 3;
        gCurrentPinballGame->unk749[arg1] = gCurrentPinballGame->unk6D9[arg1];
        DmaCopy16(3, gUnknown_0848D68C[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        index = gCurrentPinballGame->unk6D9[arg1] * 0x10;
        DmaCopy16(3, &gUnknown_081C00E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 1:
        ptr = gUnknown_086AD070;
        gCurrentPinballGame->unk749[arg1] = ptr[(gCurrentPinballGame->unk708 % 48) / 24];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 2:
        ptr = gUnknown_086AD000[gCurrentPinballGame->unk6EC[arg1]];
        gCurrentPinballGame->unk749[arg1] = ptr[0];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 3:
        gCurrentPinballGame->unk749[arg1] = gCurrentPinballGame->currentSpecies;
        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->unk749[arg1] / 15] + (gCurrentPinballGame->unk749[arg1] % 15) * 0x300,
            (void *)0x06010CA0 + arg1 * 24,
            0x300);
        DmaCopy16(
            3,
            gMonPortraitGroupPals[gCurrentPinballGame->unk749[arg1] / 15] + (gCurrentPinballGame->unk749[arg1] % 15) * 0x20,
            (void *)0x050003A0 ,
            0x20);
        DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003E0, 0x20);
        break;
    case 9:
        if (gCurrentPinballGame->unk25C > 0)
        {
            if (gMain_saveData.pokedexFlags[gCurrentPinballGame->unk59A] == SPECIES_UNSEEN)
            {
                gCurrentPinballGame->unk749[arg1] = SPECIES_NONE;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->unk749[arg1] / 15] + (gCurrentPinballGame->unk749[arg1] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
            else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->unk59A] < SPECIES_CAUGHT)
            {
                gCurrentPinballGame->unk749[arg1] = gCurrentPinballGame->unk59A;
                DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003A0, 0x20);
            }
            else
            {
                gCurrentPinballGame->unk749[arg1] = gCurrentPinballGame->unk59A;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->unk749[arg1] / 15] + (gCurrentPinballGame->unk749[arg1] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
        }
        else
        {
            gCurrentPinballGame->unk749[arg1] = gCurrentPinballGame->currentSpecies;
            DmaCopy16(
                3,
                gMonPortraitGroupPals[gCurrentPinballGame->unk749[arg1] / 15] + (gCurrentPinballGame->unk749[arg1] % 15) * 0x20,
                (void *)0x050003A0,
                0x20);
        }

        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->unk749[arg1] / 15] + (gCurrentPinballGame->unk749[arg1] % 15) * 0x300,
            (void *)0x06010CA0 + arg1 * 0x18,
            0x300);
        break;
    case 4:
        if (gCurrentPinballGame->unk17 == 2)
        {
            gCurrentPinballGame->unk749[arg1] = gUnknown_086AD000[15][(gCurrentPinballGame->unk708 % 48) / 24];
            DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);

            // !!!!! BUG: this should be multiplied by 16 !!
            index = gUnknown_086AD000[15][2];
        }
        else
        {
            gCurrentPinballGame->unk749[arg1] = gUnknown_086AD000[16][(gCurrentPinballGame->unk708 % 48) / 24];
            DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
            index = gUnknown_086AD000[16][2] * 16;
        }
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 6:
        ptr = gUnknown_086AD000[gCurrentPinballGame->unk1A7];
        gCurrentPinballGame->unk749[arg1] = ptr[0];
        index = ptr[2] * 16;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        if (gCurrentPinballGame->coins < ptr[3] ||
            (
                (gUnknown_086AD2DE[gCurrentPinballGame->unk1A6] == 3 && gCurrentPinballGame->outLanePikaPosition == 2)
                ||
                (gUnknown_086AD2DE[gCurrentPinballGame->unk1A6] == 4 && gCurrentPinballGame->unk1AF)
            ))
        {
            DmaCopy16(3, &gUnknown_081C02E4[index], sp0, 0x20);
            for (i = 0; i < 16; i++)
            {
                rgb[0] = ((sp0[i] & 0x1F) * 2) / 3;
                rgb[1] = ((sp0[i] & 0x3E0) >> 4) / 3;
                rgb[2] = ((sp0[i] & 0x7C00) >> 9) / 3;
                sp0[i] = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
            }

            DmaCopy16(3, sp0, (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        }
        else
        {
            DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        }
        break;
    case 7:
        // TODO: fake match
        ptr2 = ptr = gUnknown_086AD000[gCurrentPinballGame->unk6EC[arg1]];
        gCurrentPinballGame->unk749[arg1] = *(ptr2 += (gCurrentPinballGame->unk708 % 48) / 24);
        index = ptr[2] * 16;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 8:
        // TODO: fake match
        ptr2 = ptr = gUnknown_086AD000[gCurrentPinballGame->unk6DC];
        gCurrentPinballGame->unk749[arg1] = *(ptr2 += gUnknown_086AD79C[gCurrentPinballGame->unk6DE / 12]);
        index = ptr[2] * 16;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    }

    gCurrentPinballGame->unk747[arg1] = arg0;
    gCurrentPinballGame->unk708++;
}

void sub_1D128(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 baseX;
    s16 var1;
    s16 var2;

    if (gCurrentPinballGame->unk6C4 == 3)
    {
        baseX = 0;
        var1 = 180;
        var2 = 180;
    }
    else if (gCurrentPinballGame->unk6C4 == 2)
    {
        if (gMain.unk2A < 20)
        {
            var1 = 180;
            var2 = 180;
        }
        else
        {
            var1 = 88 + gCurrentPinballGame->unk6E0;
            var2 = 88;
        }

        baseX = 48;
    }
    else
    {
        baseX = 96 - gCurrentPinballGame->unk58;
        var1 = gCurrentPinballGame->unk6E0 + 300u - gCurrentPinballGame->unk5A;
        var2 = 300 - gCurrentPinballGame->unk5A;
    }

    group = gMain.unk44[22];
    group->baseX = baseX;
    group->baseY = var1;
    gCurrentPinballGame->unk6E4.x = baseX;
    gCurrentPinballGame->unk6E4.y = group->baseY;
    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].paletteNum = gCurrentPinballGame->unk6D3[i];
        gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->unk6DB;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->unk6C4 == 1)
    {
        group = gMain.unk44[23];
        group->baseX = baseX;
        group->baseY = var1 - 0x20;
        if (group->baseY >= 180)
            group->baseY = 180;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].paletteNum = 12;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.unk44[20];
        group->baseX = baseX;
        group->baseY = 267 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.unk44[21];
        group->baseX = baseX;
        group->baseY = 333 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = gMain.unk44[19];
    group->baseX = baseX - 8;
    group->baseY = var2 - 8;
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

void sub_1D4D0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    if (gCurrentPinballGame->unk6C4 == 1)
    {
        group = gMain.unk44[22];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.unk44[23];
        group->baseY = 300 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 180)
            group->baseY = 180;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.unk44[20];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.unk44[21];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_1D5D8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 * dst;
    s16 var0;
    s16 var1;

    group = &gMain.spriteGroups[71];
    var0 = 0;
    var1 = 0;
    switch (gCurrentPinballGame->unk2FB)
    {
    case 0:
        var0 = (gMain.systemFrameCount % 36) / 18;
        var1 = var0;
        break;
    case 1:
        gCurrentPinballGame->unk2FE = 0;
        gCurrentPinballGame->unk2FD = 0;
        gCurrentPinballGame->unk2FB = 2;
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 50000;
        break;
    case 2:
        if (gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][1] > gCurrentPinballGame->unk2FE)
        {
            gCurrentPinballGame->unk2FE++;
        }
        else
        {
            gCurrentPinballGame->unk2FE = 0;
            gCurrentPinballGame->unk2FD++;
            if (gCurrentPinballGame->unk2FD == 7)
            {
                gCurrentPinballGame->unk2FB = 0;
                gCurrentPinballGame->unk2FD = 0;
                gCurrentPinballGame->unk2F9 = 1;
            }
        }
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][2];
        break;
    case 3:
        gCurrentPinballGame->unk2FE = 0;
        gCurrentPinballGame->unk2FD = 7;
        gCurrentPinballGame->unk2FB = 4;
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 100000;
        break;
    case 4:
        if (gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][1] > gCurrentPinballGame->unk2FE)
        {
            gCurrentPinballGame->unk2FE++;
        }
        else
        {
            gCurrentPinballGame->unk2FE = 0;
            gCurrentPinballGame->unk2FD++;
            if (gCurrentPinballGame->unk2FD == 18)
            {
                gCurrentPinballGame->unk2FB = 5;
                m4aSongNumStart(SE_UNKNOWN_0xD1);
            }
        }

        if (gCurrentPinballGame->unk2FE == 6)
            m4aSongNumStart(SE_UNKNOWN_0xD0);

        var1 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][2];
        break;
    case 5:
    case 6:
        if (gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][1] > gCurrentPinballGame->unk2FE)
        {
            gCurrentPinballGame->unk2FE++;
        }
        else
        {
            gCurrentPinballGame->unk2FE = 0;
            gCurrentPinballGame->unk2FD++;
            if (gCurrentPinballGame->unk2FD == 24)
                gCurrentPinballGame->unk2FD = 18;
        }

        var1 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][2];
        break;
    case 7:
        gCurrentPinballGame->unk2FA = 0;
        gCurrentPinballGame->unk2F9 = 0;
        gCurrentPinballGame->unk2FE = 0;
        gCurrentPinballGame->unk2FD = 0;
        gCurrentPinballGame->unk2FB = 0;
        gCurrentPinballGame->unk2FD = 24;
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->unk2FD][2];
        break;
    }

    if (group->available)
    {
        group->baseX = gUnknown_086AD856[gCurrentPinballGame->unk2F9][0] - gCurrentPinballGame->unk58;
        group->baseY = gUnknown_086AD856[gCurrentPinballGame->unk2F9][1] - gCurrentPinballGame->unk5A;
        DmaCopy16(3, gRubyStageNuzleaf_Gfx[gCurrentPinballGame->unk2FC], (void *)0x06014380, 0x260);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B2E64[var1][i * 3 + 0];
            *dst++ = gUnknown_086B2E64[var1][i * 3 + 1];
            *dst++ = gUnknown_086B2E64[var1][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gCurrentPinballGame->unk2FC = var0;
}

void sub_1DA74(void)
{
    if (gCurrentPinballGame->unk25 != 3)
    {
        if (gCurrentPinballGame->unk13 < 3)
        {
            if (gCurrentPinballGame->unk1A5 == 0)
                gCurrentPinballGame->unk2F0 = gCurrentPinballGame->unk1AB & 0xF;
            else
                gCurrentPinballGame->unk2F0 = 3;
        }
        else if (gCurrentPinballGame->unk13 != 6)
        {
            gCurrentPinballGame->unk2F0 = 0;
        }
    }
}

void sub_1DAD8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;

    group = &gMain.spriteGroups[65];
    if ((gCurrentPinballGame->unk2F0 & 0xF) != gCurrentPinballGame->unk2F1)
    {
        if (gCurrentPinballGame->unk2F2)
        {
            if (gCurrentPinballGame->unk2F2 == 5)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->unkEA = 0;
                gCurrentPinballGame->unkEC = 3;
                gCurrentPinballGame->unkE8 = 0;
                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unkEE = 0;
                gCurrentPinballGame->unkF2 = 0;
                gCurrentPinballGame->unkFA = 1;
                gCurrentPinballGame->unkFB = 0;
                m4aSongNumStart(SE_UNKNOWN_0xBD);
            }

            gCurrentPinballGame->unk2F2--;
        }
        else
        {
            if (gCurrentPinballGame->unk2F1 > (gCurrentPinballGame->unk2F0 & 0xF))
            {
                gCurrentPinballGame->unk2F1--;
                gCurrentPinballGame->unk2F2 = 4;
            }
            else
            {
                gCurrentPinballGame->unk2F1++;
                gCurrentPinballGame->unk2F2 = 4;
            }

            DmaCopy16(3, gRubyBoardShopDoor_Gfx[gCurrentPinballGame->unk2F1], (void *)0x06013180, 0x180);
        }
    }

    if (gCurrentPinballGame->unk2F1 < 3)
        priority = 3;
    else
        priority = 2;

    group->baseX = 208 - gCurrentPinballGame->unk58;
    group->baseY = 80 - gCurrentPinballGame->unk5A;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &gMain.spriteGroups[65].oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void DrawWhiscash(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    const s16 *var1;

    group = &gMain.spriteGroups[63];
    var1 = gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx];
    if (group->available)
    {
        var0 = var1[0];
        DmaCopy16(3, gUnknown_081379D8 + gCurrentPinballGame->unk6F * 0x60, (void *)0x05000320, 0x20);
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06014680, 0x460);
        gCurrentPinballGame->rubyBumperCollisionPosition[0].x = -248;
        gCurrentPinballGame->rubyBumperCollisionPosition[0].y = -316;
        group->baseX = var1[2] + 124u - gCurrentPinballGame->unk58;
        group->baseY = var1[3] + 150u - gCurrentPinballGame->unk5A;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (var0 == 4 || var0 == 10)
            gCurrentPinballGame->unk2A3 = 0;
        else
            gCurrentPinballGame->unk2A3 = 1;
    }
}

//Ruby Pond
void RubyPond_EntityLogic(void)
{
    s16 i;
    u16 angle;
    u16 angle2;
    s16 var1;
    s16 frameDecidedNextPondState;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    int squaredMagnitude;

    if (gCurrentPinballGame->shouldProcessWhiscash)
    {
        // If board is currently in one of the modes (catch/etc) force reset to the 3 chinchou
        if (gCurrentPinballGame->unk13 > 2)
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;

        // Don't immediately force change state if Wishcash is actively doing something
        if (gCurrentPinballGame->rubyPondContentsChanging)
        {
            if (gCurrentPinballGame->whiscashState < WHISCASH_STATE_ABSORB_ZONE_HIT)
            {
                gCurrentPinballGame->whiscashState = WHISCASH_STATE_LEAVING;
                gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_LEAVING-1;
                gCurrentPinballGame->whiscashStateTimer = 0;
            }

            gCurrentPinballGame->rubyPondContentsChanging = FALSE;
        }

        switch (gCurrentPinballGame->whiscashState)
        {
        case WHISCASH_STATE_ARRIVAL:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SITTING)
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_SITTING;

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPLASH)
                    m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);
            }
            break;
        case WHISCASH_STATE_SITTING:
            // Alternates between frame 4 and 5
            gCurrentPinballGame->whiscashFrameIx = (gCurrentPinballGame->whiscashStateTimer % 44) / 22 + 4;
            gCurrentPinballGame->whiscashStateTimer++;
            break;
        case WHISCASH_STATE_ABSORB_ZONE_HIT:
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_ABSORB_BALL_START;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ABSORBING;
            gCurrentPinballGame->ball->oamPriority = 0;
            gCurrentPinballGame->scoreAddedInFrame = 5000;
            m4aSongNumStart(SE_WHISCASH_CATCH_BALL);
            PlayRumble(7);
            break;
        case WHISCASH_STATE_ABSORBING:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_BALL_HELD_SUNK+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_BALL_HELD_SUNK;
                    gCurrentPinballGame->whiscashStateTimer = 65;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_TO_SPHEAL_BOARD;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START)
            {
                gCurrentPinballGame->ball->unkA += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8900;
                gCurrentPinballGame->ball->positionQ8.y = 0xBD00;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+1)
            {
                gCurrentPinballGame->ball->unkA += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8C00;
                gCurrentPinballGame->ball->positionQ8.y = 0xB700;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+2)
                gCurrentPinballGame->ball->unk0 = 1;
            break;
        case WHISCASH_STATE_TO_SPHEAL_BOARD:
            gCurrentPinballGame->unk1100 = 1;
            if (gCurrentPinballGame->whiscashStateTimer == 65)
            {
                m4aSongNumStart(SE_WARP);
                gMain.blendControl = 0x9E;
            }

            if (gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer--;
                gMain.blendBrightness = 16 - gCurrentPinballGame->whiscashStateTimer / 4;
                if (gCurrentPinballGame->whiscashStateTimer == 0)
                {
                    gCurrentPinballGame->unk284 = FIELD_SPHEAL;
                    gCurrentPinballGame->unk282 = 1;
                    gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
                    gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
                    sub_1C73C();
                }
            }
            break;
        case WHISCASH_STATE_INIT_RETURN_FROM_BONUS: //from board initialization
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_DELIVER_BALL_START;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_RISE_SPIT_LEAVE;
            gCurrentPinballGame->ball->oamPriority = 0;
            break;
        case WHISCASH_STATE_RISE_SPIT_LEAVE:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_DELIVER_BALL_END+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL + 1)
                {
                    gCurrentPinballGame->ball->unkA -= 64;
                    gCurrentPinballGame->ball->positionQ8.x = 0x8300;
                    gCurrentPinballGame->ball->positionQ8.y = 0xC700;
                    gCurrentPinballGame->ball->velocity.x = -120;
                    gCurrentPinballGame->ball->velocity.y = 210;
                    gCurrentPinballGame->ball->oamPriority = 3;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_EMERGING)
                    m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL + 7) {
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
                }
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL)
                {
                    m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
                }
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL)
            {
                gCurrentPinballGame->ball->unk0 = 0;
                gCurrentPinballGame->ball->unkA -= 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8500;
                gCurrentPinballGame->ball->positionQ8.y = 0xC000;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL+2)
                gCurrentPinballGame->unk1F = 0;
            break;
        case WHISCASH_STATE_HIT:
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_HIT;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ANGRY;
            gCurrentPinballGame->scoreAddedInFrame = 10;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->unk724)
                gCurrentPinballGame->unk724 = 1;
            break;
        case WHISCASH_STATE_ANGRY:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING_AFTER_HIT)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_HIT+2)
                    m4aSongNumStart(SE_WHISCASH_EARTHQUAKE);
            }

            // Heavy shaking starts
            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT)
            {
                gCurrentPinballGame->unk2AA = gUnknown_086AD9EC[gCurrentPinballGame->whiscashStateTimer % 8];
                if (gCurrentPinballGame->whiscashStateTimer % 4 == 0)
                    MPlayStart(&gMPlayInfo_SE3, &se_whiscash_splashdown);

                if (gCurrentPinballGame->whiscashStateTimer % 10 == 0)
                    PlayRumble(12);
            }
            break;
        case WHISCASH_STATE_LEAVING: //Early Exit (mode started)
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_BALL_HELD_SUNK+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
            }
            break;
        case WHISCASH_STATE_CLEANUP:
            gCurrentPinballGame->shouldProcessWhiscash = FALSE;
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            gCurrentPinballGame->rubyPondChangeTimer = 64;
            gCurrentPinballGame->unk2AA = 0;
            break;
        }
    }
    else
    {
        if (gCurrentPinballGame->rubyPondContentsChanging)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 144)
            {
                gCurrentPinballGame->unk170[0] = gUnknown_08137968[gCurrentPinballGame->rubyPondChangeTimer / 8];
                gCurrentPinballGame->unk170[1] = gCurrentPinballGame->unk170[0];
                gCurrentPinballGame->unk170[2] = gCurrentPinballGame->unk170[0];
            }
            else
            {
                gCurrentPinballGame->rubyPondContentsChanging = FALSE;
            }

            if (gCurrentPinballGame->unk170[0] == 10)
            {
                if (gCurrentPinballGame->rubyPondChangeTimer % 8 == 0 && gCurrentPinballGame->rubyPondChangeTimer / 8 == 8)
                {
                    // Can't switch to Whiscash if in a catch/hatch/etc state, or if it hasn't yet hit a threshold
                    // of pond states first.
                    gCurrentPinballGame->pondSwitchesSinceLastWhiscash++;
                    if (gCurrentPinballGame->pondSwitchesSinceLastWhiscash < MIN_POND_SWITCHES_BEFORE_WHISCASH_AVAILABLE ||
                        gCurrentPinballGame->unk13 > 2)
                    {
                        frameDecidedNextPondState = (gMain.systemFrameCount % 5) + 1;
                        if (gCurrentPinballGame->rubyPondState == frameDecidedNextPondState)
                            gCurrentPinballGame->rubyPondState = ((gMain.systemFrameCount + 1) % 5) + 1;
                        else
                            gCurrentPinballGame->rubyPondState = frameDecidedNextPondState;
                    }
                    else
                    {
                        frameDecidedNextPondState = (gMain.systemFrameCount % 6) + 1;
                        if (gCurrentPinballGame->rubyPondState == frameDecidedNextPondState)
                            gCurrentPinballGame->rubyPondState = ((gMain.systemFrameCount + 1) % 6) + 1;
                        else
                            gCurrentPinballGame->rubyPondState = frameDecidedNextPondState;
                    }

                    if (gCurrentPinballGame->forcePondToWhiscash)
                    {
                        gCurrentPinballGame->forcePondToWhiscash = FALSE;
                        gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_WHISCASH;
                    }

                    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_WHISCASH)
                    {
                        gCurrentPinballGame->shouldProcessWhiscash = TRUE;
                        gCurrentPinballGame->whiscashState = WHISCASH_STATE_ARRIVAL;
                        gCurrentPinballGame->whiscashStateTimer = 0;
                        gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                        gCurrentPinballGame->rubyPondContentsChanging = FALSE;
                        gCurrentPinballGame->pondSwitchesSinceLastWhiscash = 0;
                    }

                    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE)
                    {
                        gCurrentPinballGame->rubyBumperLogicPosition[0].x = gUnknown_086AD9DC[0].x * 10;
                        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gUnknown_086AD9DC[0].y * 10;
                    }
                }
            }

            gCurrentPinballGame->rubyPondChangeTimer++;
            if (gCurrentPinballGame->rubyPondChangeTimer == 32)
                m4aSongNumStart(SE_RUBY_BUMPER_LEAVES);

            switch (gCurrentPinballGame->rubyPondState)
            {
            case RUBY_POND_STATE_CHINCHOU_STAGGERED:
            case RUBY_POND_STATE_CHINCHOU_CLOCKWISE:
            case RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE:
            case RUBY_POND_STATE_CHINCHOU_ROWS:
                if (gCurrentPinballGame->rubyPondChangeTimer == 102)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 116)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 130)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            case RUBY_POND_STATE_LOTAD:
                if (gCurrentPinballGame->rubyPondChangeTimer == 102)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 118)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 134)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            case RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE:
                if (gCurrentPinballGame->rubyPondChangeTimer == 104)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            }
        }
    }

    switch (gCurrentPinballGame->rubyPondState)
    {
    case RUBY_POND_STATE_CHINCHOU_STAGGERED:
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1250;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = 1270;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1600;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = 1360;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = 1610;
        break;
    case RUBY_POND_STATE_CHINCHOU_CLOCKWISE:
        for (i = 0; i < 3; i++)
        {
            angle = (gCurrentPinballGame->unk290 & 0x7F) * 0x200 + i * 0x5555;
            var1 = (gCurrentPinballGame->unk290 % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->unk190 = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->unk190 * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->unk190 * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE:
        for (i = 0; i < 3; i++)
        {
            angle = 10000 - ((gCurrentPinballGame->unk290 & 0x7F) * 0x200 + i * 0x5555);
            var1 = (gCurrentPinballGame->unk290 % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->unk190 = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->unk190 * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->unk190 * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_ROWS:
        for (i = 0; i < 2; i++)
        {
            var1 = 23 - (gCurrentPinballGame->unk290 % 46);
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].x = (i * 33 + 121) * 10;
            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].y = var1 * 5 + 1340;
        }

        var1 = 23 - (gCurrentPinballGame->unk290 + 23) % 46;
        if (var1 < 0)
            var1 = 0-var1;

        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = var1 * 5 + 1620;
        break;
    case RUBY_POND_STATE_LOTAD:
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1210;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gUnknown_0813798C[(gCurrentPinballGame->unk290 % 60) / 10] + 1300;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1600;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = gUnknown_0813798C[((gCurrentPinballGame->unk290 + 20) % 60) / 10] + 1410;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = gUnknown_0813798C[((gCurrentPinballGame->unk290 + 40) % 60) / 10] + 1660;
        break;
    case RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE:
        tempVec.x = gUnknown_086AD9DC[gCurrentPinballGame->unk16E].x * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].x;
        tempVec.y = gUnknown_086AD9DC[gCurrentPinballGame->unk16E].y * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].y;
        squaredMagnitude = (tempVec.x * tempVec.x) + (tempVec.y * tempVec.y);
        angle2 = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle2) * 7) / 20000;
        tempVec2.y = (Sin(angle2) * -7) / 20000;
        gCurrentPinballGame->rubyBumperLogicPosition[0].x += tempVec2.x;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y += tempVec2.y;
        if (squaredMagnitude < 2500)
            gCurrentPinballGame->unk16E = Random() % 4;

        // moved off screen
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = -300;
        break;
    case RUBY_POND_STATE_WHISCASH:
        // moved off screen
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = -300;
        break;
    }
}

// Ruby pond bumpers Handle Hit and draw
void RubyPondTriBumperHandleHitAndDraw(void)
{
    s16 i;
    s16 j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->bumperHitCountdown > 0)
    {
        if (gCurrentPinballGame->bumperHitCountdown == 2)
        {
            gCurrentPinballGame->scoreAddedInFrame = 500;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 5 && gCurrentPinballGame->hatchTilesBumperAcknowledged < 6)
            {
                if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 0)
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 1;
                else if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 1)
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 3;
                else
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 6;

                if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 6)
                {
                    if (gCurrentPinballGame->hatchTilesBoardAcknowledged == 0)
                    {
                        if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
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
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
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
            gCurrentPinballGame->bumperHitsSinceReset++;
        }

        gCurrentPinballGame->bumperHitCountdown--;
    }

    group = &gMain.spriteGroups[62];
    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
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
    else // chinchou
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

    // Draw Bumpers: Lotad/chinchou
    for (i = 0; i < 3; i++)
    {
        group->baseX = gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10 - gCurrentPinballGame->unk58 - 8;
        group->baseY = gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10 - gCurrentPinballGame->unk5A - 4;
        gCurrentPinballGame->rubyBumperCollisionPosition[i].x = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10) + 8) * 2;
        gCurrentPinballGame->rubyBumperCollisionPosition[i].y = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10) + 7) * 2;
        if (group->baseY < -40)
            group->baseY = -40;

        //sprites have a left/right half.
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
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->unk2F5], (void *)0x06012C20, 0x260);
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
        src = gSharpedoSpritesheetOam[var0][i];
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
            m4aSongNumStart(SE_PIKA_CHARGE_DO + offset);
        }

        if (gCurrentPinballGame->unk1C6 <= gCurrentPinballGame->unk1C8)
        {
            gCurrentPinballGame->unk1C8 = gCurrentPinballGame->unk1C6;
            if (gCurrentPinballGame->unk1C8 >= 168)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_7a);
                gCurrentPinballGame->scoreAddedInFrame = 3000;
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
            MPlayStart(&gMPlayInfo_SE3, &se_unk_79);
            gCurrentPinballGame->scoreAddedInFrame = 100;
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
                MPlayStart(&gMPlayInfo_SE3, &se_unk_79);
                gCurrentPinballGame->scoreAddedInFrame = 100;
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
        DmaCopy16(3, gMainBoardPikaSpinner_Gfx[index], (void *)0x06010780, 0x120);
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
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[2]], (void *)0x06013B80, 0x180);
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[3]], (void *)0x06013A00, 0x180);
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[4]], (void *)0x06013880, 0x180);
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
        PlayRumble(7);
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->scoreAddedInFrame = 3000;
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
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
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

void sub_203CC(void)
{
    s16 i;
    s16 j;
    s16 r5;
    s16 tempY;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    sub_20EC0();

    if (gCurrentPinballGame->unk1C6 > 167)
    {
        gCurrentPinballGame->unk744[0] = gUnknown_086ADF48[(gMain.fieldFrameCount % 160) / 5];
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->unk744[1] = gCurrentPinballGame->unk744[0] + 6;
        else
            gCurrentPinballGame->unk744[1] = gCurrentPinballGame->unk744[0];
    }
    else
    {
        gCurrentPinballGame->unk744[0] = (gMain.fieldFrameCount % 50) / 25;
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->unk744[1] = gCurrentPinballGame->unk744[0] + 9;
        else
            gCurrentPinballGame->unk744[1] = gCurrentPinballGame->unk744[0];
    }

    if (gCurrentPinballGame->outLanePikaPosition == 2)
    {
        gCurrentPinballGame->unk1E3[0] = 1;
        gCurrentPinballGame->unk1E3[1] = 1;
    }
    else
    {
        gCurrentPinballGame->unk1E3[0 + gCurrentPinballGame->outLanePikaPosition] = 1;
        gCurrentPinballGame->unk1E3[1 - gCurrentPinballGame->outLanePikaPosition] = 0;
    }

    if (gCurrentPinballGame->unk1C4 != 0)
    {
        if (gCurrentPinballGame->unk1C4 == 120)
        {
            // gCurrentPinballGame->unk1C2 + gCurrentPinballGame->unk1E2
            // Note: this can be && chained off of the previous if, once we have this line deciphered.
            if (gCurrentPinballGame->unk1E3[gCurrentPinballGame->unk1C2 - 1] != 0)
            {
                if (gCurrentPinballGame->unk1C6 > 167)
                {
                    gCurrentPinballGame->unk1F = 1;
                    gCurrentPinballGame->unk61C = 1;
                    gCurrentPinballGame->unk1DE = 120;
                    gCurrentPinballGame->unk1E0 = 120;
                    gCurrentPinballGame->unk61E = gCurrentPinballGame->unk1DE;
                    gCurrentPinballGame->unk5F7 = 1;
                    gCurrentPinballGame->unk208 = 0;
                    gCurrentPinballGame->unk20A = 0;

                    if (gCurrentPinballGame->outLanePikaPosition != 2)
                    {
                        gCurrentPinballGame->unk1C6 = 0;
                        gCurrentPinballGame->unk1C8 = 0;
                        gCurrentPinballGame->unk1CC = 0;
                        gCurrentPinballGame->unk1CA = 0;
                        gCurrentPinballGame->unk1D4 = 0;
                        gCurrentPinballGame->unk1D6 = -4;
                        gCurrentPinballGame->unk1D8 = 256;
                        gCurrentPinballGame->unk1DA = 256;
                        gCurrentPinballGame->unk1CE = 0;
                        gCurrentPinballGame->unk1D0 = 0;
                    }

                    gCurrentPinballGame->unk620 = gCurrentPinballGame->ball->positionQ1;
                    gCurrentPinballGame->scoreAddedInFrame = 30000;

                    if (gCurrentPinballGame->unk62E <= 98)
                        gCurrentPinballGame->unk62E++;
                }
                else
                {
                    gCurrentPinballGame->unk1C4 = 60;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_142);
                }

                i = gCurrentPinballGame->unk1C2 - 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2)
                    gCurrentPinballGame->unk744[i] = (i) * 7 + 2;
                else
                    gCurrentPinballGame->unk744[i] = 2;

                DmaCopy16(3, gUnknown_084C07EC + (gCurrentPinballGame->unk744[i] * 0x180), 0x06010480 + ((i) * 0x180), 0x180);
            }
        }

        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->unk744[gCurrentPinballGame->unk1C2 - 1] = (gCurrentPinballGame->unk1C2 - 1) * 7 + 2;
        else
            gCurrentPinballGame->unk744[gCurrentPinballGame->unk1C2 - 1] = 2;

        gCurrentPinballGame->unk1C4--;
    }

    if (gCurrentPinballGame->unk61C != 0)
    {
        if (gCurrentPinballGame->unk61E > 1)
        {
            r5 = (gCurrentPinballGame->unk1DE * 0x10000) / 10;
            gCurrentPinballGame->unk61E--;
            if (gCurrentPinballGame->unk1DE != 0)
            {
                gCurrentPinballGame->unk1DE--;
                if (gCurrentPinballGame->unk1DE == 40 && gCurrentPinballGame->unk61E > 40)
                {
                    gCurrentPinballGame->unk1DE = 60;
                }
            }
            if (gCurrentPinballGame->unk61E == 116)
            {
                if (gCurrentPinballGame->unkE4)
                    gCurrentPinballGame->unk61E = 120;
                else
                {
                    gCurrentPinballGame->unkE4 = 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                    {
                        if (gCurrentPinballGame->unk1C2 == 1)
                            MPlayStart(&gMPlayInfo_SE1, &se_unk_b1);
                        else
                            MPlayStart(&gMPlayInfo_SE1, &se_unk_b3);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                    else
                    {
                        MPlayStart(&gMPlayInfo_SE1, &se_unk_b1);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                }
            }
            if (gCurrentPinballGame->unk61E == 115 && gCurrentPinballGame->unkE4 == 1)
                m4aMPlayVolumeControl(&gMPlayInfo_SE1, 0xFFFF, 0x200);

            gCurrentPinballGame->ball->positionQ1.x =
                gCurrentPinballGame->unk620.x + ((Sin(r5) * 6) / 20000) +
                ((gUnknown_086ADF8A[gCurrentPinballGame->unk1C2 - 1] * 2 - gCurrentPinballGame->unk620.x) * (gCurrentPinballGame->unk1E0 - gCurrentPinballGame->unk1DE)) / gCurrentPinballGame->unk1E0;

            tempY = ((gCurrentPinballGame->unk1E0 - gCurrentPinballGame->unk1DE) * 40) / gCurrentPinballGame->unk1E0;
            gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->unk620.y - tempY;

            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
        }
        else if (gCurrentPinballGame->unk61E == 1)
        {
            gCurrentPinballGame->ball->positionQ1.x = gUnknown_086ADF8A[gCurrentPinballGame->unk1C2 - 1] * 2;
            gCurrentPinballGame->ball->positionQ1.y = 702;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
            gCurrentPinballGame->ball->velocity.x = 0;
            // fly me to the moon
            gCurrentPinballGame->ball->velocity.y = -300;
            m4aSongNumStart(SE_UNKNOWN_0x7C);
            gCurrentPinballGame->unk61E = 0;
            gCurrentPinballGame->unk1F = 0;
            gCurrentPinballGame->unk5F7 = 0;
            gCurrentPinballGame->holeIndicators[(gCurrentPinballGame->unk1C2 - 1) * 3] = 1;

            if (gCurrentPinballGame->unk714 == 0 &&
                (gCurrentPinballGame->holeIndicators[0] &
                 gCurrentPinballGame->holeIndicators[1] &
                 gCurrentPinballGame->holeIndicators[2] &
                 gCurrentPinballGame->holeIndicators[3]))
            {
                gCurrentPinballGame->unk714 = 1;
                gCurrentPinballGame->unk715 = 126;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
            }

            PlayRumble(11);
        }

        if (gCurrentPinballGame->unk61E >= 100)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->unk744[gCurrentPinballGame->unk1C2 - 1] = (gCurrentPinballGame->unk1C2 - 1) * 7 + 2;
            else
                gCurrentPinballGame->unk744[gCurrentPinballGame->unk1C2 - 1] = 2;

            if (gCurrentPinballGame->unk61E == 100)
            {
                gMain.unk44[38]->available = 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->unk1C2 == 2)
                {
                    DmaCopy16(3, gUnknown_08395A4C, 0x06015800, 0x2400);
                }
                else
                {
                    DmaCopy16(3, gUnknown_08397E6C, 0x06015800, 0x2400);
                }
            }
        }
        else
        {
            if (gUnknown_086ADEE0[gCurrentPinballGame->unk20A][1] > gCurrentPinballGame->unk208)
                gCurrentPinballGame->unk208++;
            else
            {
                gCurrentPinballGame->unk208 = 0;
                gCurrentPinballGame->unk20A++;

                if (gCurrentPinballGame->unk20A == 23)
                {
                    m4aSongNumStop(SE_UNKNOWN_0x7C);
                    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
                }

                if (gCurrentPinballGame->unk20A > 25)
                {
                    gCurrentPinballGame->unk20A = 25;
                    gCurrentPinballGame->unk61C = 0;
                    gMain.unk44[38]->available = 0;
                    gCurrentPinballGame->unkE4 = 0;

                    i = gCurrentPinballGame->unk1C2 - 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                        gCurrentPinballGame->unk744[i] = i * 9;
                    else
                        gCurrentPinballGame->unk744[i] = 0;

                    DmaCopy16(3, gUnknown_084C07EC + (gCurrentPinballGame->unk744[i] * 0x180), 0x06010480 + (i * 0x180), 0x180);
                }
            }

            if (gCurrentPinballGame->unk20A >= 17 && gCurrentPinballGame->unk20A <= 23)
            {
                if ((gMain.systemFrameCount & 3) >> 1)
                    gCurrentPinballGame->unk4C = -3;
                else
                    gCurrentPinballGame->unk4C = 3;
            }

            r5 = gUnknown_086ADEE0[gCurrentPinballGame->unk20A][0];
            i = gCurrentPinballGame->unk1C2 - 1;

            spriteGroup = gMain.unk44[38];
            spriteGroup->baseX = (i * 177) - (gCurrentPinballGame->unk58 - 16);
            if (gCurrentPinballGame->unk61C)
            {
                spriteGroup->baseY = 380 - gCurrentPinballGame->unk5A;
                gCurrentPinballGame->unk1E3[i] = 0;
            }
            else
            {
                spriteGroup->baseY = 180;
                gCurrentPinballGame->unk1E3[i] = 1;
            }

            for (j = 0; j < 4; j++)
            {
                oamSimple = &spriteGroup->oam[j];
                dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                *dst++ = gUnknown_086B4922[r5][j * 3 + 0];
                *dst++ = gUnknown_086B4922[r5][j * 3 + 1];
                *dst++ = gUnknown_086B4922[r5][j * 3 + 2];

                gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            }
        }
    }
    spriteGroup = gMain.unk44[29];

    if (spriteGroup->available)
    {
        for (i = 0; i <= 1; i++)
        {
            spriteGroup = gMain.unk44[29 + i];
            spriteGroup->baseX = (i * 177) - (gCurrentPinballGame->unk58 - 16);
            if (gCurrentPinballGame->unk1E3[i])
            {
                if ((gMain.fieldFrameCount % 5) == 0)
                {
                    DmaCopy16(3, gUnknown_084C07EC + (gCurrentPinballGame->unk744[i] * 0x180), 0x06010480 + (i * 0x180), 0x180);
                }

                tempY = 380 - gCurrentPinballGame->unk5A;
                spriteGroup->baseY = tempY;
            }
            else
                spriteGroup->baseY = 200;

            for (j = 0; j <= 1; j++)
            {
                oamSimple = &spriteGroup->oam[j];

                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
            }
        }
    }
}
