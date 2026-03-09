#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const s16 gUnknown_086AE45A[];
extern const s16 gUnknown_086AE3DC[][3];
extern const s8 gUnknown_08137CBC[][2];
extern const u8 gPelliper_Gfx[][0x480];
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


void UpdateSapphirePokeballSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    s16 var1;
    s16 index;
    s16 scale;

    var0 = 0;
    group = gMain.boardSpriteGroups[50];
    if (group->available)
    {
        group->baseX = 202;
        if (gCurrentPinballGame->extraLifeAnimTimer > 48)
        {
            var1 = gCurrentPinballGame->extraLifeAnimTimer - 48;
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

        if (gCurrentPinballGame->extraLifeAnimTimer > 56)
        {
            scale = 0x100;
        }
        else
        {
            var1 = gCurrentPinballGame->extraLifeAnimTimer - 36;
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

        if (gCurrentPinballGame->extraLifeAnimTimer < 58)
        {
            index = gCurrentPinballGame->numLives - 1 + (((gCurrentPinballGame->extraLifeAnimTimer % 16) / 8) * 9);
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

    if (gCurrentPinballGame->extraLifeAnimTimer)
    {
        if (gCurrentPinballGame->extraLifeAnimTimer == 90)
        {
            group->available = 1;
            DmaCopy16(3, gUnknown_086AE324, (void *)0x05000380, 0x20);
        }

        if (gCurrentPinballGame->extraLifeAnimTimer == 85)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_fc);

        if (gCurrentPinballGame->extraLifeAnimTimer == 58)
        {
            MPlayStart(&gMPlayInfo_SE1, &se_unk_7a);
            if (gCurrentPinballGame->numLives < 9)
                gCurrentPinballGame->numLives++;
        }

        gCurrentPinballGame->extraLifeAnimTimer--;
        if (gCurrentPinballGame->extraLifeAnimTimer == 0)
            group->available = 0;
    }
}

void UpdateSapphireBannerSlideSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.boardSpriteGroups[10];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->fieldBannerSpriteX;
        group->baseY = 44;
        for (i = 0; i < 7; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->fieldEntryAnimTimer > 0)
    {
        if (gCurrentPinballGame->fieldEntryAnimTimer == 120)
            gMain.boardSpriteGroups[10]->available = 1;

        gCurrentPinballGame->fieldBannerSpriteX = 270 - ((120 - gCurrentPinballGame->fieldEntryAnimTimer) * 3);
        if (gCurrentPinballGame->fieldEntryAnimTimer == 1)
            gMain.boardSpriteGroups[10]->available = 0;
    }
}

void UpdateSapphireChimechoAnimState(void)
{
    if (gCurrentPinballGame->viewportBottomY < 170)
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][gCurrentPinballGame->paletteCycleIndex * 2], (void *)OBJ_PLTT + 0x160, 0x20);
    }
    else
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][gCurrentPinballGame->paletteCycleIndex * 2 + 1], (void *)OBJ_PLTT + 0x160, 0x20);
    }

    switch (gCurrentPinballGame->peliAnimState)
    {
    case 0:
        gCurrentPinballGame->peliAnimFrame = 0;
        gCurrentPinballGame->peliAnimSubTimer = 0;
        if (gCurrentPinballGame->hitFlashActive)
            gCurrentPinballGame->hitFlashOffsetY = (gCurrentPinballGame->gameFrameCount % 30) / 15;
        else
            gCurrentPinballGame->hitFlashOffsetY = 0;

        gCurrentPinballGame->hitFlashActive = 0;
        break;
    case 1:
        if (gCurrentPinballGame->peliAnimSubTimer < 5)
        {
            if (gCurrentPinballGame->peliAnimSubTimer < 2)
            {
                gCurrentPinballGame->peliAnimFrame = 2;
                gCurrentPinballGame->hitFlashOffsetY = 3;
            }
            else
            {
                gCurrentPinballGame->peliAnimFrame = 3;
                gCurrentPinballGame->hitFlashOffsetY = 5;
            }

            if (gCurrentPinballGame->peliAnimSubTimer == 0)
                m4aSongNumStart(SE_UNKNOWN_0xCC);

            gCurrentPinballGame->peliAnimSubTimer++;
        }
        else
        {
            gCurrentPinballGame->peliAnimState = 2;
            gCurrentPinballGame->peliAnimFrame = 4;
            gCurrentPinballGame->peliAnimSubTimer = 0;
        }
        break;
    case 2:
        if (gUnknown_086AE344[gCurrentPinballGame->peliAnimFrame][1] <= gCurrentPinballGame->peliAnimSubTimer)
        {
            gCurrentPinballGame->peliAnimSubTimer = 0;
            gCurrentPinballGame->peliAnimFrame++;
            if (gCurrentPinballGame->peliAnimFrame > 7)
                gCurrentPinballGame->peliAnimFrame = 4;
        }
        else
        {
            gCurrentPinballGame->peliAnimSubTimer++;
        }
        break;
    case 3:
        gCurrentPinballGame->peliAnimFrame = 8;
        gCurrentPinballGame->peliAnimSubTimer = 0;
        gCurrentPinballGame->peliAnimState = 4;
        gCurrentPinballGame->hitFlashOffsetY = 0;
        break;
    case 4:
        if (gUnknown_086AE344[gCurrentPinballGame->peliAnimFrame][1] > gCurrentPinballGame->peliAnimSubTimer)
        {
            gCurrentPinballGame->peliAnimSubTimer++;
        }
        else
        {
            gCurrentPinballGame->peliAnimSubTimer = 0;
            gCurrentPinballGame->peliAnimFrame++;
            if (gCurrentPinballGame->peliAnimFrame > 0x13)
            {
                gCurrentPinballGame->peliAnimFrame = 0;
                gCurrentPinballGame->peliAnimState = 0;
            }
        }
        break;
    }
}

void DrawSapphireChimechoSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = gMain.boardSpriteGroups[44];
    if (group->available)
    {
        if (gCurrentPinballGame->peliAnimFrame == 0)
            index = (gCurrentPinballGame->gameFrameCount % 30) / 15;
        else
            index = gUnknown_086AE344[gCurrentPinballGame->peliAnimFrame][0];

        DmaCopy16(3, gUnknown_083C076C[index], (void *)0x060120E0, 0x1C0);
        group->baseX = 231 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 376 - gCurrentPinballGame->bgScrollYWithOffset;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void RunEvolutionCutsceneAnimation(void)
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

    if (gCurrentPinballGame->stageTimer <= 360)
    {
        if (gCurrentPinballGame->stageTimer == 0)
        {
            m4aMPlayAllStop();
            DmaCopy16(3, (void *)0x05000200, gCurrentPinballGame->savedObjPaletteForPause, 0x200);
            gCurrentPinballGame->spriteLayerPriority = 0;
            gCurrentPinballGame->bossActive = 0;
        }

        if (gCurrentPinballGame->stageTimer == 10)
        {
            gCurrentPinballGame->bannerType = 16;
            DmaCopy16(3, gUnknown_08158284, (void *)0x06015800, 0x2400);
            DmaCopy16(3, gUnknown_0815A6A4, (void *)0x050003C0, 0x20);
            gMain.boardSpriteGroups[24]->available = 1;
            gMain.boardSpriteGroups[25]->available = 1;
            gMain.boardSpriteGroups[26]->available = 1;
            gMain.boardSpriteGroups[27]->available = 1;
            gMain.boardSpriteGroups[28]->available = 1;
            gMain.boardSpriteGroups[15]->available = 1;
        }

        if (gCurrentPinballGame->bgTargetScrollY < 236)
            gCurrentPinballGame->fieldScrollOffsetY = gCurrentPinballGame->stageTimer / 2;;

        if (gCurrentPinballGame->stageTimer > 35)
        {
            if (gCurrentPinballGame->stageTimer < 68)
            {
                var0 = gCurrentPinballGame->stageTimer - 36;
                for (j = 0; j <= var0; j++)
                {
                    for (i = 1; i < 11; i++)
                        gBgScreenBuffer[(i + 15) * 0x20 + j] = 0xC100;
                }

                DmaCopy16(3, gBgScreenBuffer, (void *)0x06002000, 0x800);
                if (var0 == 30)
                    m4aSongNumStart(MUS_EVOLUTION);

                if (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->stageTimer == 67)
                    gCurrentPinballGame->zigzagoonBaseOffsetY = 120;
            }
            else if (gCurrentPinballGame->stageTimer <= 344)
            {
                for (j = 0; j <= 30; j++)
                {
                    for (i = 1; i < 11; i++)
                        gBgScreenBuffer[(i + 15) * 32 + j] = 0xC100;
                }

                DmaCopy16(3, gBgScreenBuffer, (void *)0x06002000, 0x800);
            }
        }

        if (gCurrentPinballGame->stageTimer - 270 >= 0 && gCurrentPinballGame->stageTimer - 270 <= 30)
        {
            var0 = gCurrentPinballGame->stageTimer - 270;
            if (var0 == 0)
            {
                for (i = 0; i < 16; i++)
                {
                    gUnknown_020028A8[i][0] = gCurrentPinballGame->savedObjPaletteForPause[13][i] & 0x1F;
                    gUnknown_020028A8[i][1] = (gCurrentPinballGame->savedObjPaletteForPause[13][i] & 0x3E0) >> 5;
                    gUnknown_020028A8[i][2] = (gCurrentPinballGame->savedObjPaletteForPause[13][i] & 0x7C00) >> 10;
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

        var0 = gCurrentPinballGame->stageTimer - 300;
        if (var0 >= 0 && var0 <= 16)
        {
            gCurrentPinballGame->pauseInputLocked = 1;
            var0 = gCurrentPinballGame->stageTimer - 300;
            gMain.blendControl = 0x9F;
            gMain.blendBrightness = var0;
        }

        if (gCurrentPinballGame->stageTimer > 10)
        {
            group = gMain.boardSpriteGroups[24];
            var0 = -120 + gCurrentPinballGame->stageTimer;
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

            group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 308 - gCurrentPinballGame->bgScrollYWithOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            var0 = -60 + gCurrentPinballGame->stageTimer;
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

            group = gMain.boardSpriteGroups[25];
            group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 308 - gCurrentPinballGame->bgScrollYWithOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.boardSpriteGroups[26];
            var0 = -100 + gCurrentPinballGame->stageTimer;
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

            group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 308 - gCurrentPinballGame->bgScrollYWithOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.boardSpriteGroups[27];
            var0 = -80 + gCurrentPinballGame->stageTimer;
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

            group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 308 - gCurrentPinballGame->bgScrollYWithOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            var0 = -90 + gCurrentPinballGame->stageTimer;
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

            group = gMain.boardSpriteGroups[28];
            group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 308 - gCurrentPinballGame->bgScrollYWithOffset;
            for (i = 0; i < 8; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.boardSpriteGroups[15];
            group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 308 - gCurrentPinballGame->bgScrollYWithOffset;
            var0 = -120 + gCurrentPinballGame->stageTimer;
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

        if (gCurrentPinballGame->stageTimer == 350)
        {
            for (i = 0x1E0; i < 0x340; i++)
                gBgScreenBuffer[i] = 0x1FF;

            DmaCopy16(3, gBgScreenBuffer, (void *)0x06002000, 0x800);
            if (gMain.selectedField == FIELD_SAPPHIRE)
                gCurrentPinballGame->zigzagoonBaseOffsetY = 0;
        }

        if (gCurrentPinballGame->stageTimer == 360)
        {
            gMain.boardSpriteGroups[24]->available = 0;
            gMain.boardSpriteGroups[25]->available = 0;
            gMain.boardSpriteGroups[26]->available = 0;
            gMain.boardSpriteGroups[27]->available = 0;
            gMain.boardSpriteGroups[28]->available = 0;
            gMain.boardSpriteGroups[15]->available = 0;
            gCurrentPinballGame->currentSpecies = gCurrentPinballGame->savedHatchSpecies;
            SetBoardPortraitGraphics(3, 0);
            gCurrentPinballGame->bannerType = 17;
            DmaCopy16(3, gUnknown_083A562C, (void *)0x06015800, 0x1800);
            DmaCopy16(3, gUnknown_083A6E4C, (void *)0x050003C0, 0x20);
            gCurrentPinballGame->spriteLayerPriority = 3;
        }
    }
    else
    {
        var0 = gCurrentPinballGame->stageTimer - 360;
        if (var0 <= 64)
        {
            if (var0 == 1)
                m4aMPlayStop(&gMPlayInfo_BGM);

            gMain.blendControl = 0x9F;
            gMain.blendBrightness = 16 - (var0  / 4);
            if (var0 == 32)
            {
                gCurrentPinballGame->bgmVolumeRestoreTimer = 140;
                PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].mainSeriesIndexNumber, 0);
            }

            if (var0 == 64)
            {
                gCurrentPinballGame->hatchTileAnimTimer = 0;
                gCurrentPinballGame->hatchRevealKeyframe = 0;
                gMain.boardSpriteGroups[37]->available = 1;
            }
        }
        else
        {
            gCurrentPinballGame->pauseInputLocked = 0;
            if (gUnknown_086AE0D0[gCurrentPinballGame->hatchRevealKeyframe] > gCurrentPinballGame->hatchTileAnimTimer)
            {
                gCurrentPinballGame->hatchTileAnimTimer++;
            }
            else
            {
                gCurrentPinballGame->hatchTileAnimTimer = 0;
                gCurrentPinballGame->hatchRevealKeyframe++;
                if (gCurrentPinballGame->hatchRevealKeyframe > 10)
                {
                    gMain.boardSpriteGroups[37]->available = 0;
                    gCurrentPinballGame->hatchRevealKeyframe = 10;
                    gCurrentPinballGame->stageTimer = 0;
                    gCurrentPinballGame->boardSubState++;
                    DmaCopy16(3, gCurrentPinballGame->savedObjPaletteForPause, (void *)0x05000200, 0x180);
                    gCurrentPinballGame->bannerType = 0;
                }
            }

            index = gCurrentPinballGame->hatchRevealKeyframe;
            group = gMain.boardSpriteGroups[37];
            group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 300 - gCurrentPinballGame->bgScrollYWithOffset;
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

void RunSapphirePelliperFlybyAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 index;
    s16 var0;

    index = 0;
    if (gCurrentPinballGame->stageTimer == 0)
    {
        gMain.boardSpriteGroups[16]->available = 1;
        gCurrentPinballGame->travelSpriteX = 1400;
        gCurrentPinballGame->travelSpriteY = -600;
        gCurrentPinballGame->bannerType = 21;
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
        if (gCurrentPinballGame->stageTimer < 60)
        {
            u16 angle = (gCurrentPinballGame->stageTimer * 0x4000) / 60;
            gCurrentPinballGame->travelSpriteX = (Cos(angle) * 900) / 20000 + 487;
            gCurrentPinballGame->travelSpriteY = (Sin(angle) * 600) / 20000 - 629;
            gCurrentPinballGame->travelSpriteVelX = -17;
            gCurrentPinballGame->travelSpriteVelY = -30;
            index = (gCurrentPinballGame->stageTimer % 4) / 2;
            if (gCurrentPinballGame->stageTimer % 10 == 0)
                m4aSongNumStart(SE_UNKNOWN_0x97);
        }
        else if (gCurrentPinballGame->stageTimer < 90)
        {
            var0 = gCurrentPinballGame->stageTimer - 60;
            if (var0 < 12)
            {
                index = (var0 % 12) / 2 + 2;
            }
            else
            {
                var0 -= 12;
                index = (var0 % 18) / 3 + 2;
            }

            gCurrentPinballGame->travelSpriteVelY += 2;
            gCurrentPinballGame->travelSpriteX += gCurrentPinballGame->travelSpriteVelX;
            gCurrentPinballGame->travelSpriteY += gCurrentPinballGame->travelSpriteVelY;
            gCurrentPinballGame->travelIntroSegmentIndex = 0;
            gCurrentPinballGame->travelIntroSubFrame = 0;
        }
        else if (gCurrentPinballGame->stageTimer < 190)
        {
            if (gUnknown_086AE394[gCurrentPinballGame->travelIntroSegmentIndex][2] > gCurrentPinballGame->travelIntroSubFrame)
            {
                gCurrentPinballGame->travelIntroSubFrame++;
            }
            else
            {
                gCurrentPinballGame->travelIntroSubFrame = 0;
                gCurrentPinballGame->travelIntroSegmentIndex++;
                if (gCurrentPinballGame->travelIntroSegmentIndex == 7)
                {
                    gCurrentPinballGame->area =  gUnknown_08055A68[gMain.selectedField][gCurrentPinballGame->areaRotationIndex];
                    gCurrentPinballGame->portraitAreaLookupIds[0] = gUnknown_08137928[gCurrentPinballGame->area];
                    SetBoardPortraitGraphics(0, 0);
                }

                if (gCurrentPinballGame->travelIntroSegmentIndex == 11)
                    gCurrentPinballGame->stageTimer = 189;
            }

            index = gUnknown_086AE394[gCurrentPinballGame->travelIntroSegmentIndex][1];
            if (gUnknown_086AE394[gCurrentPinballGame->travelIntroSegmentIndex][2] == 5 && gCurrentPinballGame->travelIntroSubFrame == 1)
                m4aSongNumStart(SE_UNKNOWN_0x98);

            if (index == 16)
                gCurrentPinballGame->travelSpriteX = -80;
            else
                gCurrentPinballGame->travelSpriteX = 0;

            gCurrentPinballGame->travelSpriteVelX = -24;
            gCurrentPinballGame->travelSpriteVelY = 14;
        }
        else if (gCurrentPinballGame->stageTimer < 430)
        {
            var0 = gCurrentPinballGame->stageTimer - 190;
            if (var0 < 24)
            {
                gCurrentPinballGame->travelSpriteX = var0 * -14;
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
        else if (gCurrentPinballGame->stageTimer < 490)
        {
                index = (gCurrentPinballGame->stageTimer % 4) / 2;
                gCurrentPinballGame->travelSpriteVelY--;
                gCurrentPinballGame->travelSpriteX += gCurrentPinballGame->travelSpriteVelX;
                gCurrentPinballGame->travelSpriteY += gCurrentPinballGame->travelSpriteVelY;
                if (gCurrentPinballGame->stageTimer % 10 == 0)
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

        index = gUnknown_086AE394[gCurrentPinballGame->travelIntroSegmentIndex][0];
        group = gMain.boardSpriteGroups[16];
        group->baseX = gCurrentPinballGame->travelSpriteX / 10 + 96u - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->travelSpriteY / 10 + 300u - gCurrentPinballGame->bgScrollYWithOffset;

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

    if (gCurrentPinballGame->stageTimer == 489)
    {
        gMain.boardSpriteGroups[16]->available = 0;
        gCurrentPinballGame->bannerType = 0;
    }
}

void UpdateSapphirePondEntityCooldown(void)
{
    if (gCurrentPinballGame->pelipperState == 1)
    {
        if (gCurrentPinballGame->entityMovementTimer)
            gCurrentPinballGame->entityMovementTimer--;
        else
            gCurrentPinballGame->pelipperState = 0;
    }
}

//Sapphire pond - Pelliper
void RunSapphirePondPelliperStateMachine(void)
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
    switch (gCurrentPinballGame->pelipperState)
    {
    case 0:
        gCurrentPinballGame->pelipperBobOffsetY = 0;
        var_sl = (gCurrentPinballGame->gameFrameCount % 50) / 25;
        gCurrentPinballGame->pelipperPosXQ10 = 0;
        gCurrentPinballGame->pelipperPosYQ10 = 0;
        break;
    case 1:
        var_sl = gUnknown_086AE45A[(gCurrentPinballGame->gameFrameCount % 40) / 10];
        gCurrentPinballGame->pelipperPosXQ10 = 0;
        gCurrentPinballGame->pelipperPosYQ10 = 0;
        gCurrentPinballGame->pelipperAnimKeyframe = 0;
        gCurrentPinballGame->pelipperAnimSubframe = 0;
        if (gCurrentPinballGame->boardState > 2)
        {
            gCurrentPinballGame->pelipperState = 0;
            var_sl = 0;
        }
        break;
    case 2:
        var_sl = 4;
        break;
    case 3:
        if (gCurrentPinballGame->entityMovementTimer < 3)
        {
            if (gCurrentPinballGame->entityMovementTimer == 0)
            {
                gCurrentPinballGame->ballLocked = 1;
                gCurrentPinballGame->ballLockState = 1;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
                gCurrentPinballGame->ball->spin = 0;
                m4aSongNumStart(SE_UNKNOWN_0xE2);
                PlayRumble(7);
                gCurrentPinballGame->scoreAddedInFrame = 100000;
            }

            gCurrentPinballGame->ball->positionQ0.x = 156;
            gCurrentPinballGame->ball->positionQ0.y = 121 + gCurrentPinballGame->entityMovementTimer * 2;
            var_sl = 4;
        }
        else if (gCurrentPinballGame->entityMovementTimer < 23)
        {
            gCurrentPinballGame->ball->positionQ0.x = 157;
            gCurrentPinballGame->ball->positionQ0.y = 134;
            gCurrentPinballGame->ball->isGrabbed = 1;
            var_sl = 5;
        }
        else
        {
            gCurrentPinballGame->pelipperState = 4;
            gCurrentPinballGame->entityMovementTimer = 0;
            var_sl = 2;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->entityMovementTimer++;
        gCurrentPinballGame->pelipperFlapsoundTimer = 0;
        break;
    case 4:
        if (gUnknown_086AE3DC[gCurrentPinballGame->pelipperAnimKeyframe][2] > gCurrentPinballGame->pelipperAnimSubframe)
        {
            gCurrentPinballGame->pelipperAnimSubframe++;
        }
        else
        {
            gCurrentPinballGame->pelipperAnimSubframe = 0;
            gCurrentPinballGame->pelipperAnimKeyframe++;
            if (gCurrentPinballGame->pelipperAnimKeyframe == 21)
            {
                gCurrentPinballGame->pelipperAnimKeyframe = 20;
                gCurrentPinballGame->pelipperState = 5;
                gCurrentPinballGame->entityMovementTimer = 0;
            }

            if (gCurrentPinballGame->pelipperAnimKeyframe == 1)
                m4aSongNumStart(SE_UNKNOWN_0xE3);
        }

        sp0 = gUnknown_086AE3DC[gCurrentPinballGame->pelipperAnimKeyframe][0];
        var_sl = gUnknown_086AE3DC[gCurrentPinballGame->pelipperAnimKeyframe][1];
        if (gCurrentPinballGame->pelipperFlapsoundTimer++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 5:
        if (gCurrentPinballGame->entityMovementTimer == 0)
        {
            gCurrentPinballGame->pelipperPosXQ10 = -360;
            gCurrentPinballGame->pelipperPosYQ10 = -200;
        }

        index = (gCurrentPinballGame->entityMovementTimer % 26) / 2;
        var_sl = gUnknown_08137CBC[index][0];
        gCurrentPinballGame->pelipperBobOffsetY = gUnknown_08137CBC[index][1] * 10;
        gCurrentPinballGame->pelipperVelX = -12;
        gCurrentPinballGame->pelipperVelY = -10;
        gCurrentPinballGame->pelipperPosXQ10 += gCurrentPinballGame->pelipperVelX;
        gCurrentPinballGame->pelipperPosYQ10 += gCurrentPinballGame->pelipperVelY;
        gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperPosXQ10 / 10 + 157;
        gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperPosYQ10 / 10 + 134;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->entityMovementTimer++;
        if (gCurrentPinballGame->ball->positionQ0.y < -12)
        {
            if (gCurrentPinballGame->bumperHitsSinceReset > 99)
            {
                gCurrentPinballGame->bumperHitsSinceReset = 0;
                gCurrentPinballGame->pelipperState = 6;
                gCurrentPinballGame->entityMovementTimer = 65;
                m4aMPlayAllStop();
            }
            else
            {
                gCurrentPinballGame->entityMovementTimer = 0;
                gCurrentPinballGame->pelipperState = 7;
            }
        }

        if (gCurrentPinballGame->pelipperFlapsoundTimer++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 6:
        gCurrentPinballGame->pauseInputLocked = 1;
        var_sl = gUnknown_08137CBC[0][0];
        if (gCurrentPinballGame->entityMovementTimer == 65)
        {
            m4aSongNumStart(SE_WARP);
            gMain.blendControl = 0x9E;
        }

        if (gCurrentPinballGame->entityMovementTimer)
        {
            gCurrentPinballGame->entityMovementTimer--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->entityMovementTimer / 4;
            if (gCurrentPinballGame->entityMovementTimer == 0)
            {
                gCurrentPinballGame->pendingBonusFieldId = FIELD_SPHEAL;
                gCurrentPinballGame->ballReturnMode = 2;
                gCurrentPinballGame->activeEvoHitCount = gCurrentPinballGame->savedEvoHitCount;
                gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->savedCatchArrows;
                TransitionToBonusField();
            }
        }
        break;
    case 7:
        gCurrentPinballGame->pelipperPosXQ10 = -1880;
        gCurrentPinballGame->pelipperPosYQ10 = -800;
        gCurrentPinballGame->pelipperVelX = 82;
        gCurrentPinballGame->pelipperVelY = 0;
        gCurrentPinballGame->entityMovementTimer = 0;
        gCurrentPinballGame->pelipperState = 8;
        var_sl = 13;
        sp0 = 9;
        break;
    case 8:
        var_sl = (gCurrentPinballGame->entityMovementTimer % 24) / 6 + 13;
        gCurrentPinballGame->pelipperBobOffsetY = (Sin(gCurrentPinballGame->entityMovementTimer * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->entityMovementTimer == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->entityMovementTimer < 40)
        {
            gCurrentPinballGame->pelipperPosXQ10 += gCurrentPinballGame->pelipperVelX;
            gCurrentPinballGame->pelipperPosYQ10 += gCurrentPinballGame->pelipperVelY;
        }
        else if (gCurrentPinballGame->entityMovementTimer >= 70)
        {
            gCurrentPinballGame->entityMovementTimer = 0;
            gCurrentPinballGame->pelipperState = 9;
            gCurrentPinballGame->pelipperPosXQ10 = 1200;
            gCurrentPinballGame->pelipperPosYQ10 = -1000;
            m4aSongNumStart(SE_UNKNOWN_0xE3);
            gCurrentPinballGame->pelipperFlapsoundTimer = 0;
        }

        if (gCurrentPinballGame->entityMovementTimer == 13)
        {
            gCurrentPinballGame->ball->isGrabbed = 0;
            gCurrentPinballGame->pelipperDropVelX = 5;
            gCurrentPinballGame->pelipperDropVelY = -25;
            gCurrentPinballGame->pelipperDropBallPosX = (gCurrentPinballGame->pelipperPosXQ10 / 10 + 157) * 10;
            gCurrentPinballGame->pelipperDropBallPosY = (gCurrentPinballGame->pelipperPosYQ10 / 10 + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->ballLockState)
        {
            if (gCurrentPinballGame->entityMovementTimer < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperPosXQ10 / 10 + 157;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperPosYQ10 / 10 + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->pelipperDropVelY += 2;
                gCurrentPinballGame->pelipperDropBallPosX += gCurrentPinballGame->pelipperDropVelX;
                gCurrentPinballGame->pelipperDropBallPosY += gCurrentPinballGame->pelipperDropVelY;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperDropBallPosX / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperDropBallPosY / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 91)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 91;
                    gCurrentPinballGame->ballLocked = 0;
                    gCurrentPinballGame->ballLockState = 0;
                    gCurrentPinballGame->ball->velocity.x = 128;
                    gCurrentPinballGame->ball->velocity.y = 256;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->collisionMapIndex = 0;
                    m4aSongNumStart(SE_UNKNOWN_0xE5);
                    PlayRumble(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        sp0 = 9;
        gCurrentPinballGame->entityMovementTimer++;
        break;
    case 9:
        index = (gCurrentPinballGame->entityMovementTimer % 26) / 2;
        var_sl = gUnknown_08137CBC[index][0] + 4;
        gCurrentPinballGame->pelipperBobOffsetY = gUnknown_08137CBC[index][1];
        gCurrentPinballGame->pelipperVelX = -12;
        gCurrentPinballGame->pelipperVelY = 10;
        if (gCurrentPinballGame->entityMovementTimer < 100)
        {
            gCurrentPinballGame->pelipperPosXQ10 += gCurrentPinballGame->pelipperVelX;
            gCurrentPinballGame->pelipperPosYQ10 += gCurrentPinballGame->pelipperVelY;
        }
        else
        {
            gCurrentPinballGame->entityMovementTimer = 0;
            gCurrentPinballGame->pelipperState = 10;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);
        }

        if (gCurrentPinballGame->pelipperFlapsoundTimer++ % 35 == 34)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);

        gCurrentPinballGame->entityMovementTimer++;
        break;
    case 10:
        gCurrentPinballGame->pelipperBobOffsetY = 0;
        gCurrentPinballGame->pelipperState = 0;
        gCurrentPinballGame->entityMovementTimer = 0;
        var_sl = 0;
        break;
    }

    if (group->available)
    {
        DmaCopy16(3, gPelliper_Gfx[var_sl], (void *)0x060122A0, 0x480);
        group->baseX = gCurrentPinballGame->pelipperPosXQ10 / 10 + 146 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->pelipperPosYQ10 / 10 + 110 - gCurrentPinballGame->bgScrollYWithOffset + gCurrentPinballGame->pelipperBobOffsetY / 10;
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

void DrawSapphirePondWailmerSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 var0;

    index = (gCurrentPinballGame->gameFrameCount % 32) / 16;
    group = &gMain.spriteGroups[75];
    if (gCurrentPinballGame->pokemonActionFrame)
        index = gCurrentPinballGame->pokemonActionFrame;

    var0 = gUnknown_086AE462[index][0];
    index = gUnknown_086AE462[index][1];
    group->baseX = 164 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 166 - gCurrentPinballGame->bgScrollYWithOffset;
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

void UpdateSapphireZigzagoonKickState(void)
{
    s16 var0;

    switch (gCurrentPinballGame->zigzagoonKickState)
    {
    case 0:
        gCurrentPinballGame->zigzagoonBodyFrame = (gCurrentPinballGame->gameFrameCount % 50) / 25 + 2;
        gCurrentPinballGame->zigzagoonHeadFrame = gCurrentPinballGame->zigzagoonBodyFrame + 1;
        gCurrentPinballGame->zigzagoonKickReady = 0;
        break;
    case 1:
        var0 = gCurrentPinballGame->gameFrameCount % 33;
        if (var0 < 13)
        {
            gCurrentPinballGame->zigzagoonBodyFrame = 0;
            gCurrentPinballGame->zigzagoonHeadFrame = 0;
        }
        else if (var0 < 20)
        {
            gCurrentPinballGame->zigzagoonBodyFrame = 9;
            gCurrentPinballGame->zigzagoonHeadFrame = 1;
        }
        else if (var0 < 26)
        {
            gCurrentPinballGame->zigzagoonBodyFrame = 1;
            gCurrentPinballGame->zigzagoonHeadFrame = 2;
        }
        else
        {
            gCurrentPinballGame->zigzagoonBodyFrame = 9;
            gCurrentPinballGame->zigzagoonHeadFrame = 1;
        }

        if (gCurrentPinballGame->boardEntryMode != 4)
            gCurrentPinballGame->zigzagoonKickReady = 0;
        break;
    case 2:
        gCurrentPinballGame->zigzagoonKickReady = 0;
        gCurrentPinballGame->zigzagoonKickKeyframe = 0;
        gCurrentPinballGame->zigzagoonKickSubframe = 0;
        gCurrentPinballGame->zigzagoonKickState = 3;
        gCurrentPinballGame->zigzagoonFxFrame = 0;
        gMain.spriteGroups[27].available = 1;
        gCurrentPinballGame->bannerType = 22;
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x06015800, 0xC00);
        m4aSongNumStart(SE_UNKNOWN_0xEC);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        break;
    case 3:
        if (gUnknown_086AE496[gCurrentPinballGame->zigzagoonKickKeyframe][1] > gCurrentPinballGame->zigzagoonKickSubframe)
        {
            gCurrentPinballGame->zigzagoonKickSubframe++;
        }
        else
        {
            gCurrentPinballGame->zigzagoonKickKeyframe++;
            gCurrentPinballGame->zigzagoonKickSubframe = 0;
            if (gCurrentPinballGame->zigzagoonKickKeyframe > 16)
            {
                gCurrentPinballGame->zigzagoonKickKeyframe = 16;
                gCurrentPinballGame->zigzagoonKickState = 4;
            }
        }

        gCurrentPinballGame->zigzagoonHeadFrame = gUnknown_086AE496[gCurrentPinballGame->zigzagoonKickKeyframe][0];
        gCurrentPinballGame->zigzagoonBodyFrame = gUnknown_086AE496[gCurrentPinballGame->zigzagoonKickKeyframe][2];
        if (gCurrentPinballGame->zigzagoonKickKeyframe < 6)
            gCurrentPinballGame->zigzagoonFxFrame = gCurrentPinballGame->zigzagoonKickKeyframe + 1;
        else
            gCurrentPinballGame->zigzagoonFxFrame = 0;
        break;
    case 4:
        gCurrentPinballGame->bannerType = 0;
        gMain.spriteGroups[27].available = 0;
        gCurrentPinballGame->zigzagoonKickState = 0;
        break;
    }
}

void DrawSapphireZigzagoonSprites(void)
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
        group->baseX = 198 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->zigzagoonBaseOffsetY + 284 - gCurrentPinballGame->bgScrollYWithOffset;
        index = gCurrentPinballGame->zigzagoonBodyFrame;
        DmaCopy16(3, gSapphireBoardZigzagoon_Gfx[index], (void *)0x06012A20, 0x380);
        index = gCurrentPinballGame->zigzagoonHeadFrame;
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
        group->baseX = 198 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 284 - gCurrentPinballGame->bgScrollYWithOffset;
        index = gCurrentPinballGame->zigzagoonFxFrame;
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
        group->baseX = 206 - gCurrentPinballGame->bgScrollXCopy;
        if (gCurrentPinballGame->zigzagoonKickReady)
        {
            group->baseY = 260 - gCurrentPinballGame->bgScrollYWithOffset;
            index = (gCurrentPinballGame->gameFrameCount % 50) / 25;
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

void UpdateSapphireShockWallState(void)
{
    s16 i;
    u32 mosaicVal;

    for (i = 0; i < 2; i++)
    {
        switch (gCurrentPinballGame->targetAnimPhase[i])
        {
        case 0:
            if (gUnknown_086AE4FC[gCurrentPinballGame->targetHitCountdown[i]][1] > gCurrentPinballGame->targetAnimSubframe[i])
            {
                gCurrentPinballGame->targetAnimSubframe[i]++;
            }
            else
            {
                gCurrentPinballGame->targetHitCountdown[i]++;
                gCurrentPinballGame->targetAnimSubframe[i] = 0;
                if (gCurrentPinballGame->targetHitCountdown[i] > 3)
                    gCurrentPinballGame->targetHitCountdown[i] = 0;
            }

            if (gCurrentPinballGame->targetBounceTimer[i] < 152)
                gCurrentPinballGame->targetBounceTimer[i]++;
            else
                gCurrentPinballGame->targetBounceTimer[i] = 0;
            break;
        case 1:
            if (gUnknown_086AE4FC[gCurrentPinballGame->targetHitCountdown[i]][1] > gCurrentPinballGame->targetAnimSubframe[i])
            {
                gCurrentPinballGame->targetAnimSubframe[i]++;
            }
            else
            {
                gCurrentPinballGame->targetHitCountdown[i]++;
                gCurrentPinballGame->targetAnimSubframe[i] = 0;
                if (gCurrentPinballGame->targetHitCountdown[i] == 5)
                {
                    m4aSongNumStart(SE_UNKNOWN_0xE6);
                    gCurrentPinballGame->scoreAddedInFrame = 2000;
                }
            }

            if (gCurrentPinballGame->targetHitCountdown[i] == 6)
            {
                if (gCurrentPinballGame->evoTargetCooldown)
                {
                    if (gCurrentPinballGame->evoTargetCooldown == 1)
                    {
                        gCurrentPinballGame->targetHitCountdown[i] = 7;
                        gCurrentPinballGame->targetAnimPhase[i] = 2;
                    }
                }

                gCurrentPinballGame->targetAnimSubframe[i] = 0;
            }

            gCurrentPinballGame->targetBounceTimer[i] = 20;
            break;
        case 2:
            if (gUnknown_086AE4FC[gCurrentPinballGame->targetHitCountdown[i]][1] > gCurrentPinballGame->targetAnimSubframe[i])
            {
                gCurrentPinballGame->targetAnimSubframe[i]++;
            }
            else
            {
                gCurrentPinballGame->targetHitCountdown[i]++;
                gCurrentPinballGame->targetAnimSubframe[i] = 0;
                if (gCurrentPinballGame->targetHitCountdown[i] == 8)
                    m4aSongNumStart(SE_UNKNOWN_0xE7);

                if (gCurrentPinballGame->targetHitCountdown[i] > 8)
                {
                    gCurrentPinballGame->targetHitCountdown[i] = 0;
                    gCurrentPinballGame->targetAnimPhase[i] = 0;
                }
            }

            gCurrentPinballGame->targetBounceTimer[i] = 20;
            break;
        case 3:
            gCurrentPinballGame->targetHitCountdown[i] = 9;
            gCurrentPinballGame->targetAnimSubframe[i] = 0;
            gCurrentPinballGame->targetAnimPhase[i] = 4;
            gCurrentPinballGame->targetBounceTimer[i] = 20;
            break;
        case 4:
            if (gUnknown_086AE4FC[gCurrentPinballGame->targetHitCountdown[i]][1] > gCurrentPinballGame->targetAnimSubframe[i])
            {
                gCurrentPinballGame->targetAnimSubframe[i]++;
            }
            else
            {
                gCurrentPinballGame->targetHitCountdown[i]++;
                gCurrentPinballGame->targetAnimSubframe[i] = 0;
                if (gCurrentPinballGame->targetHitCountdown[i] > 17)
                {
                    if (gCurrentPinballGame->boardState == 6)
                    {
                        gCurrentPinballGame->targetHitCountdown[i] = 0;
                        gCurrentPinballGame->targetAnimPhase[i] = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->targetHitCountdown[i] = 9;
                    }
                }
            }

            gCurrentPinballGame->targetBounceTimer[i] = 20;
            break;
        case 5:
            if (gUnknown_086AE4FC[gCurrentPinballGame->targetHitCountdown[i]][1] > gCurrentPinballGame->targetAnimSubframe[i])
            {
                gCurrentPinballGame->targetAnimSubframe[i]++;
            }
            else
            {
                gCurrentPinballGame->targetHitCountdown[i]++;
                gCurrentPinballGame->targetAnimSubframe[i] = 0;
                if (gCurrentPinballGame->targetHitCountdown[i] > 17)
                {
                    gCurrentPinballGame->targetAnimPhase[i] = 0;
                    gCurrentPinballGame->targetHitCountdown[i] = 0;
                }
            }

            gCurrentPinballGame->targetBounceTimer[i] = 20;
            break;
        }
    }

    if (gCurrentPinballGame->boardEntryMode != 3)
    {
        if (gCurrentPinballGame->evoTargetCooldown)
            gCurrentPinballGame->evoTargetCooldown--;
    }

    if (gCurrentPinballGame->boardState28)
    {
        gCurrentPinballGame->boardState28--;
        if (gCurrentPinballGame->boardState28 == 0)
            gCurrentPinballGame->boardState30 = gCurrentPinballGame->boardState34;
    }

    if (gCurrentPinballGame->mosaicShakeTimer)
    {
        if (gCurrentPinballGame->mosaicShakeTimer == 17)
        {
            m4aSongNumStart(SE_UNKNOWN_0xE8);
            gCurrentPinballGame->scoreAddedInFrame = 10;
            PlayRumble(13);
        }

        mosaicVal = gUnknown_08137CD6[gCurrentPinballGame->mosaicShakeTimer / 3];
        REG_MOSAIC = (mosaicVal << 12) | (mosaicVal << 8) | (mosaicVal << 4) | (mosaicVal << 0);
        gCurrentPinballGame->mosaicShakeTimer--;
    }

    if (gCurrentPinballGame->boardState > 2)
    {
        if (gCurrentPinballGame->boardState != 6)
        {
            for (i = 0; i < 2; i++)
            {
                if (gCurrentPinballGame->targetAnimPhase[i])
                {
                    gCurrentPinballGame->targetAnimPhase[i] = 0;
                    gCurrentPinballGame->targetHitCountdown[i] = 0;
                    gCurrentPinballGame->targetAnimSubframe[i] = 0;
                }
            }
        }
    }
    else if (gCurrentPinballGame->savedEvoHitCount > 2)
    {
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->targetAnimPhase[0] < 3)
            {
                gCurrentPinballGame->targetAnimPhase[0] = 3;
                gCurrentPinballGame->targetAnimPhase[1] = 3;
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->targetAnimPhase[0] > 2)
        {
            gCurrentPinballGame->targetAnimPhase[0] = 0;
            gCurrentPinballGame->targetHitCountdown[0] = 0;
            gCurrentPinballGame->targetAnimPhase[1] = 0;
            gCurrentPinballGame->targetHitCountdown[1] = 0;
        }
    }
}

void DrawSapphireShockWallSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[61];
    if (!group->available)
        return;

    group->baseX = 68 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 144 - gCurrentPinballGame->bgScrollYWithOffset;
    index = gUnknown_086AE4FC[gCurrentPinballGame->targetHitCountdown[0]][0];
    DmaCopy16(3, &gUnknown_0847A40C[index], (void *)0x06012DA0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[58];
    group->baseX = 68 - gCurrentPinballGame->bgScrollXCopy;
    if (gCurrentPinballGame->targetBounceTimer[0] < 14)
    {
        group->baseY = 144 - gCurrentPinballGame->bgScrollYWithOffset;
        index = gCurrentPinballGame->targetBounceTimer[0] / 2;
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
    group->baseX = 36 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 163 - gCurrentPinballGame->bgScrollYWithOffset;
    index = gUnknown_086AE4FC[gCurrentPinballGame->targetHitCountdown[1]][0];
    DmaCopy16(3, &gUnknown_084C1E6C[index], (void *)0x060130A0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[59];
    group->baseX = 36 - gCurrentPinballGame->bgScrollXCopy;
    if (gCurrentPinballGame->targetBounceTimer[1] < 14)
    {
        group->baseY = 163 - gCurrentPinballGame->bgScrollYWithOffset;
        index = gCurrentPinballGame->targetBounceTimer[1] / 2;
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
    group->baseX = 61 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 186 - gCurrentPinballGame->bgScrollYWithOffset;
    if (gCurrentPinballGame->catchModeForceOpen)
    {
        gCurrentPinballGame->trapDoorGfxState = 3;
    }
    else if (gCurrentPinballGame->targetAnimPhase[0])
    {
        if (gCurrentPinballGame->targetAnimPhase[1])
            gCurrentPinballGame->trapDoorGfxState = 3;
        else
            gCurrentPinballGame->trapDoorGfxState = 2;
    }
    else if (gCurrentPinballGame->targetAnimPhase[1])
    {
        gCurrentPinballGame->trapDoorGfxState = 1;
    }
    else
    {
        gCurrentPinballGame->trapDoorGfxState = 0;
    }

    if (gCurrentPinballGame->trapDoorGfxState < 3)
        index = gCurrentPinballGame->trapDoorGfxState * 3 + (gCurrentPinballGame->gameFrameCount % 30) / 10;
    else
        index = 9;

    DmaCopy16(3, &gSapphireBoardShopShockWall_Gfx[index], (void *)0x060146A0, 0x80);
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
}

void UpdateSapphireBumperOscillation(void)
{
    gCurrentPinballGame->rubyBumperLogicPosition[0].x = 920;
    gCurrentPinballGame->rubyBumperLogicPosition[0].y = (133 - (gCurrentPinballGame->gameFrameCount % 60) / 30) * 10;
    gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1260;
    gCurrentPinballGame->rubyBumperLogicPosition[1].y = (131 - ((gCurrentPinballGame->gameFrameCount + 10) % 60) / 30) * 10;
    gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1080;
    gCurrentPinballGame->rubyBumperLogicPosition[2].y = (161 - ((gCurrentPinballGame->gameFrameCount + 20) % 60) / 30) * 10;
}

void HandleSapphireBumperHitAndDraw(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[63];
    if (gCurrentPinballGame->bumperHitCountdown > 0)
    {
        if (gCurrentPinballGame->bumperHitCountdown == 2)
        {
            gCurrentPinballGame->scoreAddedInFrame = 500;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 5)
            {
                if (gCurrentPinballGame->hatchTilesBumperAcknowledged < 6)
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
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->scrollDelayFrames = 50;
                            gCurrentPinballGame->scrollHoldFrames = 600;
                            gCurrentPinballGame->scrollTargetBottomY = 0xEC;
                            gCurrentPinballGame->fieldScrollOffsetY = 0;
                            gCurrentPinballGame->fieldScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxVariant = 7;
                            gCurrentPinballGame->scrollOverrideActive = 1;
                            gCurrentPinballGame->scrollFromBottom = 0;
                            gCurrentPinballGame->fieldEntryAnimTimer = 80;
                            gCurrentPinballGame->bannerScrollPosQ10 = -2500;
                            gCurrentPinballGame->bannerAnimPhase = 50;
                            gCurrentPinballGame->bannerScrollVelocity = 0;
                            DmaCopy16(3, gUnknown_086ACEF8[7], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gUnknown_086ACF18[7], (void *)0x050003C0, 0x20);
                            gMain.blendControl = 0xCE;
                        }
                    }
                }
            }

            gCurrentPinballGame->bumperHitCount++;
            gCurrentPinballGame->bumperHitsSinceReset++;
            if (gCurrentPinballGame->bumperHitsSinceReset == 100)
                gCurrentPinballGame->scoreAddedInFrame = 50000;
        }

        gCurrentPinballGame->bumperHitCountdown--;
    }

    if (group->available)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperAnimState[i] > 0)
            {
                if (gCurrentPinballGame->pondBumperAnimState[i] < 0)
                    gCurrentPinballGame->pondBumperAnimState[i] += 3;

                index = gCurrentPinballGame->pondBumperAnimState[i] / 4 + 2;
                gCurrentPinballGame->pondBumperAnimState[i]--;
            }
            else
            {
                index = ((gCurrentPinballGame->gameFrameCount + (i * 10)) % 30) / 15;
            }

            DmaCopy16(3, &gUnknown_0845690C[index], (void *)0x060133A0 + i * 0x200, 0x200);

            group->baseX = gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10 - gCurrentPinballGame->bgScrollXCopy - 8;
            group->baseY = gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10 - gCurrentPinballGame->bgScrollYWithOffset - 10;
            gCurrentPinballGame->rubyBumperCollisionPosition[i].x = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10) + 8) * 2;
            gCurrentPinballGame->rubyBumperCollisionPosition[i].y = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10) + 3) * 2;

            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}
