#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const s16 gUnknown_086AE45A[];
extern const s16 gUnknown_086AE3DC[][3];
extern const s8 gUnknown_08137CBC[][2];
extern const u8 gUnknown_084BB16C[][0x480];
extern const u16 gUnknown_086B3EF6[20][4][3];
extern const s16 gUnknown_086AE462[][2];
extern const u8 gSapphireBoardWailmer_Gfx[][0x300];
extern const u16 gWailmerSpritesheetOam[26][2][3];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];
extern const s16 gUnknown_086AE496[][3];
extern const u8 gSapphireBoardZigzagoon_Gfx[][0x380];
extern const u16 gSapphireBoardZigzagoonSpritesheetOam[42][3][3];
extern const u16 gUnknown_086B3B7E[14][7][3];
extern const u8 gUnknown_084ED6CC[][0x200];
extern const s16 gUnknown_086AE4FC[][2];
extern const s16 gUnknown_08137CD6[];
extern const u8 gUnknown_0847A40C[][0x300];
extern const u8 gUnknown_0847D10C[][0x200];
extern const u8 gUnknown_084C1E6C[][0x300];
extern const u8 gUnknown_084C4B6C[][0x200];
extern const u8 gSapphireBoardShopShockWall_Gfx[][0x80];
extern const u8 gUnknown_0845690C[][0x200];
extern const u8 gUnknown_08483D8C[][0x480];
extern const u8 gUnknown_08488A0C[][0x480];
extern const u8 gUnknown_081BCAA4[];
extern const u8 gUnknown_081BE2C4[];
extern const u8 gUnknown_081BE4C4[];
extern const u8 gUnknown_081BFCE4[];
extern const s16 gUnknown_086AE394[][3];
extern const s16 gUnknown_08137928[];
extern const s16 gUnknown_08055A68[][7];
extern u16 gUnknown_086B3FE6[][18];
extern struct SongHeader se_unk_e3;
extern const s16 gUnknown_086AE0D0[];
extern const u16 gUnknown_086B4E62[22][12];
extern const u8 gUnknown_08158284[];
extern const u8 gUnknown_0815A6A4[];
extern const u16 gUnknown_086B4112[20][12];
extern const u8 gUnknown_083A562C[];
extern const u8 gUnknown_083A6E4C[];
extern const s16 gUnknown_086AE344[][2];
extern const u8 gUnknown_083C076C[][0x1C0];
extern const u8 gUnknown_08455E8C[][0x200];
extern const u8 gUnknown_0845648C[][0x40];
extern const u8 gUnknown_086AE324[];

extern struct SongHeader se_unk_fc;
extern struct SongHeader se_unk_7a;

extern u8 gUnknown_020028A8[][3];


void sub_2CA9C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    s16 var1;
    s16 index;
    s16 scale;

    var0 = 0;
    group = gMain.unk44[50];
    if (group->available)
    {
        group->baseX = 202;
        if (gCurrentPinballGame->unk286 > 48)
        {
            var1 = gCurrentPinballGame->unk286 - 48;
            if (var1 >= 34)
            {
                group->baseY = 146 - (42 - var1) * 2;
                index = 0;
            }
            else if (var1 >= 24)
            {
                group->baseY = 130;
                index = 1;
                var0 = -9;
            }
            else if (var1 > 7)
            {
                group->baseY = 130;
                index = 2;
                var0 = -4;
            }
            else
            {
                group->baseY = 146 - var1 * 2;
                index = 0;
            }

            DmaCopy16(3, gUnknown_08455E8C[index], (void *)0x060152A0, 0x200);
        }
        else
        {
            group->baseY = 180;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

        if (gCurrentPinballGame->unk286 > 56)
        {
            scale = 0x100;
        }
        else
        {
            var1 = gCurrentPinballGame->unk286 - 36;
            if (var1 >= 0)
            {
                scale = (var1 * 0x80) / 20 + 0x80;
                group->baseY = 130;
                var0 = -2;
            }
            else
            {
                scale = 0x80;
                group->baseY = 180;
                var0 = 0;
            }
        }

        oamSimple = &group->oam[1];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + var0;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_NORMAL;
        gOamBuffer[oamSimple->oamId].matrixNum = 6;
        SetMatrixScale(scale, scale, 6);

        if (gCurrentPinballGame->unk286 < 58)
        {
            index = gCurrentPinballGame->numLives - 1 + (((gCurrentPinballGame->unk286 % 16) / 8) * 9);
            DmaCopy16(3, gUnknown_0845648C[index], (void *)0x06015520, 0x40);
            oamSimple = &group->oam[2];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 216;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset - 112;
        }
        else
        {
            oamSimple = &group->oam[2];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 216;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset - 76;
        }
    }

    if (gCurrentPinballGame->unk286)
    {
        if (gCurrentPinballGame->unk286 == 90)
        {
            group->available = 1;
            DmaCopy16(3, gUnknown_086AE324, (void *)0x05000380, 0x20);
        }

        if (gCurrentPinballGame->unk286 == 85)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_fc);

        if (gCurrentPinballGame->unk286 == 58)
        {
            MPlayStart(&gMPlayInfo_SE1, &se_unk_7a);
            if (gCurrentPinballGame->numLives < 9)
                gCurrentPinballGame->numLives++;
        }

        gCurrentPinballGame->unk286--;
        if (gCurrentPinballGame->unk286 == 0)
            group->available = 0;
    }
}

void sub_2CD98(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.unk44[10];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->unk16A;
        group->baseY = 44;
        for (i = 0; i < 7; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->unkF4 > 0)
    {
        if (gCurrentPinballGame->unkF4 == 120)
            gMain.unk44[10]->available = 1;

        gCurrentPinballGame->unk16A = 270 - ((120 - gCurrentPinballGame->unkF4) * 3);
        if (gCurrentPinballGame->unkF4 == 1)
            gMain.unk44[10]->available = 0;
    }
}

void sub_2CE80(void)
{
    if (gCurrentPinballGame->unk68 < 170)
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][gCurrentPinballGame->unk6F * 2], (void *)OBJ_PLTT + 0x160, 0x20);
    }
    else
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][gCurrentPinballGame->unk6F * 2 + 1], (void *)OBJ_PLTT + 0x160, 0x20);
    }

    switch (gCurrentPinballGame->unk163)
    {
    case 0:
        gCurrentPinballGame->unk164 = 0;
        gCurrentPinballGame->unk168 = 0;
        if (gCurrentPinballGame->unk165)
            gCurrentPinballGame->unk166 = (gCurrentPinballGame->unk290 % 30) / 15;
        else
            gCurrentPinballGame->unk166 = 0;

        gCurrentPinballGame->unk165 = 0;
        break;
    case 1:
        if (gCurrentPinballGame->unk168 < 5)
        {
            if (gCurrentPinballGame->unk168 < 2)
            {
                gCurrentPinballGame->unk164 = 2;
                gCurrentPinballGame->unk166 = 3;
            }
            else
            {
                gCurrentPinballGame->unk164 = 3;
                gCurrentPinballGame->unk166 = 5;
            }

            if (gCurrentPinballGame->unk168 == 0)
                m4aSongNumStart(SE_UNKNOWN_0xCC);

            gCurrentPinballGame->unk168++;
        }
        else
        {
            gCurrentPinballGame->unk163 = 2;
            gCurrentPinballGame->unk164 = 4;
            gCurrentPinballGame->unk168 = 0;
        }
        break;
    case 2:
        if (gUnknown_086AE344[gCurrentPinballGame->unk164][1] <= gCurrentPinballGame->unk168)
        {
            gCurrentPinballGame->unk168 = 0;
            gCurrentPinballGame->unk164++;
            if (gCurrentPinballGame->unk164 > 7)
                gCurrentPinballGame->unk164 = 4;
        }
        else
        {
            gCurrentPinballGame->unk168++;
        }
        break;
    case 3:
        gCurrentPinballGame->unk164 = 8;
        gCurrentPinballGame->unk168 = 0;
        gCurrentPinballGame->unk163 = 4;
        gCurrentPinballGame->unk166 = 0;
        break;
    case 4:
        if (gUnknown_086AE344[gCurrentPinballGame->unk164][1] > gCurrentPinballGame->unk168)
        {
            gCurrentPinballGame->unk168++;
        }
        else
        {
            gCurrentPinballGame->unk168 = 0;
            gCurrentPinballGame->unk164++;
            if (gCurrentPinballGame->unk164 > 0x13)
            {
                gCurrentPinballGame->unk164 = 0;
                gCurrentPinballGame->unk163 = 0;
            }
        }
        break;
    }
}

void sub_2D104(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = gMain.unk44[44];
    if (group->available)
    {
        if (gCurrentPinballGame->unk164 == 0)
            index = (gCurrentPinballGame->unk290 % 30) / 15;
        else
            index = gUnknown_086AE344[gCurrentPinballGame->unk164][0];

        DmaCopy16(3, gUnknown_083C076C[index], (void *)0x060120E0, 0x1C0);
        group->baseX = 231 - gCurrentPinballGame->unk58;
        group->baseY = 376 - gCurrentPinballGame->unk5A;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_2D204(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;
    s16 index;
    s16 sp0[0xD8];
    s16 sp1B0[0x30];
    u8 sp210[3];

    if (gCurrentPinballGame->unk18 <= 360)
    {
        if (gCurrentPinballGame->unk18 == 0)
        {
            m4aMPlayAllStop();
            DmaCopy16(3, (void *)0x05000200, gCurrentPinballGame->unk111A, 0x200);
            gCurrentPinballGame->unk6DB = 0;
            gCurrentPinballGame->unk5FA = 0;
        }

        if (gCurrentPinballGame->unk18 == 10)
        {
            gCurrentPinballGame->unkE4 = 16;
            DmaCopy16(3, gUnknown_08158284, (void *)0x06015800, 0x2400);
            DmaCopy16(3, gUnknown_0815A6A4, (void *)0x050003C0, 0x20);
            gMain.unk44[24]->available = 1;
            gMain.unk44[25]->available = 1;
            gMain.unk44[26]->available = 1;
            gMain.unk44[27]->available = 1;
            gMain.unk44[28]->available = 1;
            gMain.unk44[15]->available = 1;
        }

        if (gCurrentPinballGame->unkCC < 236)
            gCurrentPinballGame->unkE6 = gCurrentPinballGame->unk18 / 2;;

        if (gCurrentPinballGame->unk18 > 35)
        {
            if (gCurrentPinballGame->unk18 < 68)
            {
                var0 = gCurrentPinballGame->unk18 - 36;
                for (j = 0; j <= var0; j++)
                {
                    for (i = 1; i < 11; i++)
                        gUnknown_03005C00[(i + 15) * 0x20 + j] = 0xC100;
                }

                DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x800);
                if (var0 == 30)
                    m4aSongNumStart(MUS_EVOLUTION);

                if (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->unk18 == 67)
                    gCurrentPinballGame->unk380 = 120;
            }
            else if (gCurrentPinballGame->unk18 <= 344)
            {
                for (j = 0; j <= 30; j++)
                {
                    for (i = 1; i < 11; i++)
                        gUnknown_03005C00[(i + 15) * 32 + j] = 0xC100;
                }

                DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x800);
            }
        }

        if (gCurrentPinballGame->unk18 - 270 >= 0 && gCurrentPinballGame->unk18 - 270 <= 30)
        {
            var0 = gCurrentPinballGame->unk18 - 270;
            if (var0 == 0)
            {
                for (i = 0; i < 16; i++)
                {
                    gUnknown_020028A8[i][0] = gCurrentPinballGame->unk111A[13][i] & 0x1F;
                    gUnknown_020028A8[i][1] = (gCurrentPinballGame->unk111A[13][i] & 0x3E0) >> 5;
                    gUnknown_020028A8[i][2] = (gCurrentPinballGame->unk111A[13][i] & 0x7C00) >> 10;
                }
            }
            else
            {
                u16 *destColor;
                for (i = 0; i < 16; i++)
                {
                    destColor = sp1B0;
                    sp210[0] = gUnknown_020028A8[i][0] + ((0x1F - gUnknown_020028A8[i][0]) * var0) / 30;
                    sp210[1] = gUnknown_020028A8[i][1] + ((0x1F - gUnknown_020028A8[i][1]) * var0) / 30;
                    sp210[2] = gUnknown_020028A8[i][2] + ((0x1F - gUnknown_020028A8[i][2]) * var0) / 30;
                    destColor[i] = sp210[0] | (sp210[1] << 5) | (sp210[2] << 0xA);
                }

                DmaCopy16(3, destColor, (void *)0x050003A0, 0x20);
            }

            if (var0 == 10)
                m4aSongNumStart(SE_UNKNOWN_0xB0);
        }

        var0 = gCurrentPinballGame->unk18 - 300;
        if (var0 >= 0 && var0 <= 16)
        {
            gCurrentPinballGame->unk1100 = 1;
            var0 = gCurrentPinballGame->unk18 - 300;
            gMain.blendControl = 0x9F;
            gMain.blendBrightness = var0;
        }

        if (gCurrentPinballGame->unk18 > 10)
        {
            group = gMain.unk44[24];
            var0 = -120 + gCurrentPinballGame->unk18;
            if (var0 >= 22)
                sp0[0] = ((var0 - 22) % 102) * 3 - 160;
            else
                sp0[0] = -162;

            if (var0 >= 0)
                sp0[1] = (var0 % 102) * 3 - 162;
            else
                sp0[1] = -162;

            if (var0 >= 72)
                sp0[2] = ((var0 - 72) % 102) * 3 - 162;
            else
                sp0[2] = -162;

            if (var0 >= 51)
                sp0[3] = ((var0 - 51) % 102) * 3 - 161;
            else
                sp0[3] = -161;

            group->baseX = 96 - gCurrentPinballGame->unk58;
            group->baseY = 308 - gCurrentPinballGame->unk5A;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            var0 = -60 + gCurrentPinballGame->unk18;
            if (var0 >= 22)
                sp0[0] = ((var0 - 22) % 102) * 3 - 160;
            else
                sp0[0] = -162;

            if (var0 >= 0)
                sp0[1] = (var0 % 102) * 3 - 162;
            else
                sp0[1] = -162;

            if (var0 >= 72)
                sp0[2] = ((var0 - 72) % 102) * 3 - 162;
            else
                sp0[2] = -162;

            if (var0 >= 51)
                sp0[3] = ((var0 - 51) % 102) * 3 - 161;
            else
                sp0[3] = -161;

            group = gMain.unk44[25];
            group->baseX = 96 - gCurrentPinballGame->unk58;
            group->baseY = 308 - gCurrentPinballGame->unk5A;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.unk44[26];
            var0 = -100 + gCurrentPinballGame->unk18;
            if (var0 >= 0)
                sp0[0] = (var0 % 152) * 2 - 160;
            else
                sp0[0] = -160;

            if (var0 >= 38)
                sp0[1] = ((var0 - 38) % 152) * 2 - 160;
            else
                sp0[1] = -160;

            if (var0 >= 76)
                sp0[2] = ((var0 - 76) % 152) * 2 - 160;
            else
                sp0[2] = -160;

            if (var0 >= 114)
                sp0[3] = ((var0 - 114) % 152) * 2 - 160;
            else
                sp0[3] = -160;

            group->baseX = 96 - gCurrentPinballGame->unk58;
            group->baseY = 308 - gCurrentPinballGame->unk5A;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.unk44[27];
            var0 = -80 + gCurrentPinballGame->unk18;
            if (var0 >= 0)
                sp0[0] = (var0 % 152) * 2 - 160;
            else
                sp0[0] = -160;

            if (var0 >= 38)
                sp0[1] = ((var0 - 38) % 152) * 2 - 160;
            else
                sp0[1] = -160;

            if (var0 >= 76)
                sp0[2] = ((var0 - 76) % 152) * 2 - 160;
            else
                sp0[2] = -160;

            if (var0 >= 114)
                sp0[3] = ((var0 - 114) % 152) * 2 - 160;
            else
                sp0[3] = -160;

            group->baseX = 96 - gCurrentPinballGame->unk58;
            group->baseY = 308 - gCurrentPinballGame->unk5A;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            var0 = -90 + gCurrentPinballGame->unk18;
            if (var0 >= 236)
                sp0[0] = (var0 - 236) % 272 - 128;
            else
                sp0[0] = -128;

            if (var0 >= 204)
                sp0[1] = (var0 - 204) % 272 - 128;
            else
                sp0[1] = -128;

            if (var0 >= 168)
                sp0[2] = (var0 - 168) % 272 - 128;
            else
                sp0[2] = -128;

            if (var0 >= 136)
                sp0[3] = (var0 - 136) % 272 - 128;
            else
                sp0[3] = -128;

            if (var0 >= 100)
                sp0[4] = (var0 - 100) % 272 - 128;
            else
                sp0[4] = -128;

            if (var0 >= 68)
                sp0[5] = (var0 - 68) % 272 - 128;
            else
                sp0[5] = -128;

            if (var0 >= 32)
                sp0[6] = (var0 - 32) % 272 - 128;
            else
                sp0[6] = -128;

            if (var0 >= 0)
                sp0[7] = (var0 % 272) - 128;
            else
                sp0[7] = -128;

            group = gMain.unk44[28];
            group->baseX = 96 - gCurrentPinballGame->unk58;
            group->baseY = 308 - gCurrentPinballGame->unk5A;
            for (i = 0; i < 8; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.unk44[15];
            group->baseX = 96 - gCurrentPinballGame->unk58;
            group->baseY = 308 - gCurrentPinballGame->unk5A;
            var0 = -120 + gCurrentPinballGame->unk18;
            if (var0 > 0)
            {
                sp0[0] = 0;
                index = (var0 % 70) / 7;
            }
            else
            {
                sp0[0] = -160;
                index = 0;
            }

            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                *dst++ = gUnknown_086B4112[index][i * 3 + 0];
                *dst++ = gUnknown_086B4112[index][i * 3 + 1];
                *dst++ = gUnknown_086B4112[index][i * 3 + 2];
                gOamBuffer[oamSimple->oamId].x += group->baseX + sp0[0];
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->unk18 == 350)
        {
            for (i = 0x1E0; i < 0x340; i++)
                gUnknown_03005C00[i] = 0x1FF;

            DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x800);
            if (gMain.selectedField == FIELD_SAPPHIRE)
                gCurrentPinballGame->unk380 = 0;
        }

        if (gCurrentPinballGame->unk18 == 360)
        {
            gMain.unk44[24]->available = 0;
            gMain.unk44[25]->available = 0;
            gMain.unk44[26]->available = 0;
            gMain.unk44[27]->available = 0;
            gMain.unk44[28]->available = 0;
            gMain.unk44[15]->available = 0;
            gCurrentPinballGame->currentSpecies = gCurrentPinballGame->unk5A2;
            sub_1C7F4(3, 0);
            gCurrentPinballGame->unkE4 = 17;
            DmaCopy16(3, gUnknown_083A562C, (void *)0x06015800, 0x1800);
            DmaCopy16(3, gUnknown_083A6E4C, (void *)0x050003C0, 0x20);
            gCurrentPinballGame->unk6DB = 3;
        }
    }
    else
    {
        var0 = gCurrentPinballGame->unk18 - 360;
        if (var0 <= 64)
        {
            if (var0 == 1)
                m4aMPlayStop(&gMPlayInfo_BGM);

            gMain.blendControl = 0x9F;
            gMain.blendBrightness = 16 - (var0  / 4);
            if (var0 == 32)
            {
                gCurrentPinballGame->unk29C = 140;
                PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].mainSeriesIndexNumber, 0);
            }

            if (var0 == 64)
            {
                gCurrentPinballGame->unk604 = 0;
                gCurrentPinballGame->unk603 = 0;
                gMain.unk44[37]->available = 1;
            }
        }
        else
        {
            gCurrentPinballGame->unk1100 = 0;
            if (gUnknown_086AE0D0[gCurrentPinballGame->unk603] > gCurrentPinballGame->unk604)
            {
                gCurrentPinballGame->unk604++;
            }
            else
            {
                gCurrentPinballGame->unk604 = 0;
                gCurrentPinballGame->unk603++;
                if (gCurrentPinballGame->unk603 > 10)
                {
                    gMain.unk44[37]->available = 0;
                    gCurrentPinballGame->unk603 = 10;
                    gCurrentPinballGame->unk18 = 0;
                    gCurrentPinballGame->unk17++;
                    DmaCopy16(3, gCurrentPinballGame->unk111A, (void *)0x05000200, 0x180);
                    gCurrentPinballGame->unkE4 = 0;
                }
            }

            index = gCurrentPinballGame->unk603;
            group = gMain.unk44[37];
            group->baseX = 96 - gCurrentPinballGame->unk58;
            group->baseY = 300 - gCurrentPinballGame->unk5A;
            if (group->baseY >= 200)
                group->baseY = 200;

            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                *dst++ = gUnknown_086B4E62[index][i * 3 + 0];
                *dst++ = gUnknown_086B4E62[index][i * 3 + 1];
                *dst++ = gUnknown_086B4E62[index][i * 3 + 2];
                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }
    }
}

void sub_2E094(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 index;
    s16 var0;

    index = 0;
    if (gCurrentPinballGame->unk18 == 0)
    {
        gMain.unk44[16]->available = 1;
        gCurrentPinballGame->unk60C = 1400;
        gCurrentPinballGame->unk60E = -600;
        gCurrentPinballGame->unkE4 = 21;
        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gUnknown_081BCAA4, (void *)0x06015800, 0x1800);
            DmaCopy16(3, gUnknown_081BE2C4, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gUnknown_08483D8C, (void *)0x06015800, 0x480);
        }
        else
        {
            DmaCopy16(3, gUnknown_081BE4C4, (void *)0x06015800, 0x1800);
            DmaCopy16(3, gUnknown_081BFCE4, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gUnknown_08488A0C, (void *)0x06015800, 0x480);
        }
    }
    else
    {
        if (gCurrentPinballGame->unk18 < 60)
        {
            u16 angle = (gCurrentPinballGame->unk18 * 0x4000) / 60;
            gCurrentPinballGame->unk60C = (Cos(angle) * 900) / 20000 + 487;
            gCurrentPinballGame->unk60E = (Sin(angle) * 600) / 20000 - 629;
            gCurrentPinballGame->unk610 = -17;
            gCurrentPinballGame->unk612 = -30;
            index = (gCurrentPinballGame->unk18 % 4) / 2;
            if (gCurrentPinballGame->unk18 % 10 == 0)
                m4aSongNumStart(SE_UNKNOWN_0x97);
        }
        else if (gCurrentPinballGame->unk18 < 90)
        {
            var0 = gCurrentPinballGame->unk18 - 60;
            if (var0 < 12)
            {
                index = (var0 % 12) / 2 + 2;
            }
            else
            {
                var0 -= 12;
                index = (var0 % 18) / 3 + 2;
            }

            gCurrentPinballGame->unk612 += 2;
            gCurrentPinballGame->unk60C += gCurrentPinballGame->unk610;
            gCurrentPinballGame->unk60E += gCurrentPinballGame->unk612;
            gCurrentPinballGame->unk60A = 0;
            gCurrentPinballGame->unk608 = 0;
        }
        else if (gCurrentPinballGame->unk18 < 190)
        {
            if (gUnknown_086AE394[gCurrentPinballGame->unk60A][2] > gCurrentPinballGame->unk608)
            {
                gCurrentPinballGame->unk608++;
            }
            else
            {
                gCurrentPinballGame->unk608 = 0;
                gCurrentPinballGame->unk60A++;
                if (gCurrentPinballGame->unk60A == 7)
                {
                    gCurrentPinballGame->area =  gUnknown_08055A68[gMain.selectedField][gCurrentPinballGame->unk32];
                    gCurrentPinballGame->unk6D9[0] = gUnknown_08137928[gCurrentPinballGame->area];
                    sub_1C7F4(0, 0);
                }

                if (gCurrentPinballGame->unk60A == 11)
                    gCurrentPinballGame->unk18 = 189;
            }

            index = gUnknown_086AE394[gCurrentPinballGame->unk60A][1];
            if (gUnknown_086AE394[gCurrentPinballGame->unk60A][2] == 5 && gCurrentPinballGame->unk608 == 1)
                m4aSongNumStart(SE_UNKNOWN_0x98);

            if (index == 16)
                gCurrentPinballGame->unk60C = -80;
            else
                gCurrentPinballGame->unk60C = 0;

            gCurrentPinballGame->unk610 = -24;
            gCurrentPinballGame->unk612 = 14;
        }
        else if (gCurrentPinballGame->unk18 < 430)
        {
            var0 = gCurrentPinballGame->unk18 - 190;
            if (var0 < 24)
            {
                gCurrentPinballGame->unk60C = var0 * -14;
                index = (var0 % 24) / 4 + 2;
            }
            else if (var0 < 30)
            {
                index = 12;
                if (var0 == 24)
                    m4aSongNumStart(MUS_SUCCESS);
            }
            else if (var0 < 42)
            {
                var0 -= 30;
                index = (var0 % 12) / 6 + 13;
            }
            else
            {
                index = 15;
            }
        }
        else if (gCurrentPinballGame->unk18 < 490)
        {
                index = (gCurrentPinballGame->unk18 % 4) / 2;
                gCurrentPinballGame->unk612--;
                gCurrentPinballGame->unk60C += gCurrentPinballGame->unk610;
                gCurrentPinballGame->unk60E += gCurrentPinballGame->unk612;
                if (gCurrentPinballGame->unk18 % 10 == 0)
                    m4aSongNumStart(SE_UNKNOWN_0x97);
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gUnknown_08483D8C[index], (void *) 0x06015800, 0x480);
        }
        else
        {
            DmaCopy16(3, gUnknown_08488A0C[index], (void *) 0x06015800, 0x480);
        }

        index = gUnknown_086AE394[gCurrentPinballGame->unk60A][0];
        group = gMain.unk44[16];
        group->baseX = gCurrentPinballGame->unk60C / 10 + 96u - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk60E / 10 + 300u - gCurrentPinballGame->unk5A;

        for( i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst =(u16*) &gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B3FE6[index][i * 3 + 0];
            *dst++ = gUnknown_086B3FE6[index][i * 3 + 1];
            *dst++ = gUnknown_086B3FE6[index][i * 3 + 2];
            gOamBuffer[oamSimple->oamId].x +=  group->baseX;
            gOamBuffer[oamSimple->oamId].y +=  group->baseY;
        }
    }

    if (gCurrentPinballGame->unk18 == 489)
    {
        gMain.unk44[16]->available = 0;
        gCurrentPinballGame->unkE4 = 0;
    }
}

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
                gCurrentPinballGame->scoreAddedInFrame = 100000;
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
                gCurrentPinballGame->unk284 = FIELD_SPHEAL;
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
            gCurrentPinballGame->ball->oamPriority = 1;
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
                    gCurrentPinballGame->ball->oamPriority = 3;
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
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);
        }

        if (gCurrentPinballGame->unk310++ % 35 == 34)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);

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
    DmaCopy16(3, gSapphireBoardWailmer_Gfx[index], (void *)0x06012720, 0x300);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gWailmerSpritesheetOam[var0][i];
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
        break;
    case 2:
        gCurrentPinballGame->unk37C = 0;
        gCurrentPinballGame->unk37D = 0;
        gCurrentPinballGame->unk37E = 0;
        gCurrentPinballGame->unk378 = 3;
        gCurrentPinballGame->unk37B = 0;
        gMain.spriteGroups[27].available = 1;
        gCurrentPinballGame->unkE4 = 22;
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x06015800, 0xC00);
        m4aSongNumStart(SE_UNKNOWN_0xEC);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
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
        DmaCopy16(3, gSapphireBoardZigzagoon_Gfx[index], (void *)0x06012A20, 0x380);
        index = gCurrentPinballGame->unk37A;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gSapphireBoardZigzagoonSpritesheetOam[index][i];
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
                    gCurrentPinballGame->scoreAddedInFrame = 2000;
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
            gCurrentPinballGame->scoreAddedInFrame = 10;
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

void sub_2FCD0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[61];
    if (!group->available)
        return;

    group->baseX = 68 - gCurrentPinballGame->unk58;
    group->baseY = 144 - gCurrentPinballGame->unk5A;
    index = gUnknown_086AE4FC[gCurrentPinballGame->unk36C[0]][0];
    DmaCopy16(3, &gUnknown_0847A40C[index], (void *)0x06012DA0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[58];
    group->baseX = 68 - gCurrentPinballGame->unk58;
    if (gCurrentPinballGame->unk372[0] < 14)
    {
        group->baseY = 144 - gCurrentPinballGame->unk5A;
        index = gCurrentPinballGame->unk372[0] / 2;
        DmaCopy16(3, &gUnknown_0847D10C[index], (void *)0x06014720, 0x180);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[62];
    group->baseX = 36 - gCurrentPinballGame->unk58;
    group->baseY = 163 - gCurrentPinballGame->unk5A;
    index = gUnknown_086AE4FC[gCurrentPinballGame->unk36C[1]][0];
    DmaCopy16(3, &gUnknown_084C1E6C[index], (void *)0x060130A0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[59];
    group->baseX = 36 - gCurrentPinballGame->unk58;
    if (gCurrentPinballGame->unk372[1] < 14)
    {
        group->baseY = 163 - gCurrentPinballGame->unk5A;
        index = gCurrentPinballGame->unk372[1] / 2;
        DmaCopy16(3, &gUnknown_084C4B6C[index], (void *)0x06014920, 0x180);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[76];
    group->baseX = 61 - gCurrentPinballGame->unk58;
    group->baseY = 186 - gCurrentPinballGame->unk5A;
    if (gCurrentPinballGame->unk367)
    {
        gCurrentPinballGame->unk366 = 3;
    }
    else if (gCurrentPinballGame->unk36A[0])
    {
        if (gCurrentPinballGame->unk36A[1])
            gCurrentPinballGame->unk366 = 3;
        else
            gCurrentPinballGame->unk366 = 2;
    }
    else if (gCurrentPinballGame->unk36A[1])
    {
        gCurrentPinballGame->unk366 = 1;
    }
    else
    {
        gCurrentPinballGame->unk366 = 0;
    }

    if (gCurrentPinballGame->unk366 < 3)
        index = gCurrentPinballGame->unk366 * 3 + (gCurrentPinballGame->unk290 % 30) / 10;
    else
        index = 9;

    DmaCopy16(3, &gSapphireBoardShopShockWall_Gfx[index], (void *)0x060146A0, 0x80);
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
}

void sub_300D8(void)
{
    gCurrentPinballGame->unk178[0].x = 920;
    gCurrentPinballGame->unk178[0].y = (133 - (gCurrentPinballGame->unk290 % 60) / 30) * 10;
    gCurrentPinballGame->unk178[1].x = 1260;
    gCurrentPinballGame->unk178[1].y = (131 - ((gCurrentPinballGame->unk290 + 10) % 60) / 30) * 10;
    gCurrentPinballGame->unk178[2].x = 1080;
    gCurrentPinballGame->unk178[2].y = (161 - ((gCurrentPinballGame->unk290 + 20) % 60) / 30) * 10;
}

void sub_30178(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[63];
    if (gCurrentPinballGame->unk624 > 0)
    {
        if (gCurrentPinballGame->unk624 == 2)
        {
            gCurrentPinballGame->scoreAddedInFrame = 500;
            m4aSongNumStart(SE_UNKNOWN_0xB6);
            sub_11B0(7);
            if (gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 5)
            {
                if (gCurrentPinballGame->unk625 < 6)
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
                            gMain.unkF |= 0x1;
                            gCurrentPinballGame->unkEA = 50;
                            gCurrentPinballGame->unkEC = 600;
                            gCurrentPinballGame->unkE8 = 0xEC;
                            gCurrentPinballGame->unkE6 = 0;
                            gCurrentPinballGame->unkEE = 4;
                            gCurrentPinballGame->unkF2 = 7;
                            gCurrentPinballGame->unkFA = 1;
                            gCurrentPinballGame->unkFB = 0;
                            gCurrentPinballGame->unkF4 = 80;
                            gCurrentPinballGame->unkF6 = -2500;
                            gCurrentPinballGame->unkF0 = 50;
                            gCurrentPinballGame->unkF8 = 0;
                            DmaCopy16(3, gUnknown_086ACEF8[7], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gUnknown_086ACF18[7], (void *)0x050003C0, 0x20);
                            gMain.blendControl = 0xCE;
                        }
                    }
                }
            }

            gCurrentPinballGame->unk176++;
            gCurrentPinballGame->unk308++;
            if (gCurrentPinballGame->unk308 == 100)
                gCurrentPinballGame->scoreAddedInFrame = 50000;
        }

        gCurrentPinballGame->unk624--;
    }

    if (group->available)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->unk170[i] > 0)
            {
                if (gCurrentPinballGame->unk170[i] < 0)
                    gCurrentPinballGame->unk170[i] += 3;

                index = gCurrentPinballGame->unk170[i] / 4 + 2;
                gCurrentPinballGame->unk170[i]--;
            }
            else
            {
                index = ((gCurrentPinballGame->unk290 + (i * 10)) % 30) / 15;
            }

            DmaCopy16(3, &gUnknown_0845690C[index], (void *)0x060133A0 + i * 0x200, 0x200);

            group->baseX = gCurrentPinballGame->unk178[i].x / 10 - gCurrentPinballGame->unk58 - 8;
            group->baseY = gCurrentPinballGame->unk178[i].y / 10 - gCurrentPinballGame->unk5A - 10;
            gCurrentPinballGame->unk184[i].x = (-(gCurrentPinballGame->unk178[i].x / 10) + 8) * 2;
            gCurrentPinballGame->unk184[i].y = (-(gCurrentPinballGame->unk178[i].y / 10) + 3) * 2;

            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}
