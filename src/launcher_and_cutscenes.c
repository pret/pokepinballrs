#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gRubyTravelVolbeat_Gfx[][0x480];
extern const u8 gSapphireTravelIllumise_Gfx[][0x480];
extern const u8 gRubyBoardBonusGfx[];
extern const u8 gRubyBoardBonusObjPalette[];
extern const u8 gSapphireBoardBonusGfx[];
extern const u8 gSapphireBoardBonusObjPalette[];
extern const s16 gTravelEventAnimData[][3];
extern const s16 gAreaToSpeciesTable[];
extern const s16 gAreaRouletteTable[][7];
extern u16 gTravelEventSpritesheetOam[][18];
extern const s16 gHatchRevealFinalTimings[];
extern const u16 gHatchSequentialOamFramesets[22][12];
extern const u8 gBoardActionTilesGfx[];
extern const u8 gBoardActionObjPal[];
extern const u16 gEvolutionSparkleSpritesheetOam[20][12];
extern const u8 gHatchFinalTilesGfx[];
extern const u8 gHatchFinalPalette[];
extern const s16 gSpoinkAnimFrameset[][2];
extern const u8 gSpoinkEntity_Gfx[][0x1C0];
extern const u8 gOneUpBannerSprite_Gfx[][0x200];
extern const u8 gLifeCountDigit_Gfx[][0x40];
extern const u8 gOneUpSpritePalette[];

extern struct SongHeader se_unk_fc;
extern struct SongHeader se_pika_full_charge_1_up;

extern u8 gPaletteFadeRGBCache[][3];

void AnimateOneUpSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    s16 var1;
    s16 index;
    s16 scale;

    var0 = 0;
    group = gMain.fieldSpriteGroups[50];
    if (group->available)
    {
        group->baseX = 202;
        if (gCurrentPinballGame->oneUpAnimTimer > 48)
        {
            var1 = gCurrentPinballGame->oneUpAnimTimer - 48;
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

            DmaCopy16(3, gOneUpBannerSprite_Gfx[index], (void *)0x060152A0, 0x200);
        }
        else
        {
            group->baseY = 180;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

        if (gCurrentPinballGame->oneUpAnimTimer > 56)
        {
            scale = 0x100;
        }
        else
        {
            var1 = gCurrentPinballGame->oneUpAnimTimer - 36;
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

        if (gCurrentPinballGame->oneUpAnimTimer < 58)
        {
            index = gCurrentPinballGame->numLives - 1 + (((gCurrentPinballGame->oneUpAnimTimer % 16) / 8) * 9);
            DmaCopy16(3, gLifeCountDigit_Gfx[index], (void *)0x06015520, 0x40);
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

    if (gCurrentPinballGame->oneUpAnimTimer)
    {
        if (gCurrentPinballGame->oneUpAnimTimer == 90)
        {
            group->available = 1;
            DmaCopy16(3, gOneUpSpritePalette, (void *)0x05000380, 0x20);
        }

        if (gCurrentPinballGame->oneUpAnimTimer == 85)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_fc);

        if (gCurrentPinballGame->oneUpAnimTimer == 58)
        {
            MPlayStart(&gMPlayInfo_SE1, &se_pika_full_charge_1_up);
            if (gCurrentPinballGame->numLives < 9)
                gCurrentPinballGame->numLives++;
        }

        gCurrentPinballGame->oneUpAnimTimer--;
        if (gCurrentPinballGame->oneUpAnimTimer == 0)
            group->available = 0;
    }
}

void AnimateBannerSlide(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[10];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->bannerSlideX;
        group->baseY = 44;
        for (i = 0; i < 7; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->bannerDisplayDuration > 0)
    {
        if (gCurrentPinballGame->bannerDisplayDuration == 120)
            gMain.fieldSpriteGroups[10]->available = 1;

        gCurrentPinballGame->bannerSlideX = 270 - ((120 - gCurrentPinballGame->bannerDisplayDuration) * 3);
        if (gCurrentPinballGame->bannerDisplayDuration == 1)
            gMain.fieldSpriteGroups[10]->available = 0;
    }
}

void UpdateSpoinkAnimation(void)
{
    if (gCurrentPinballGame->cameraYViewport < 170)
    {
        DmaCopy16(3, gFieldPaletteVariants[gMain.selectedField][gCurrentPinballGame->activePaletteIndex * 2], (void *)OBJ_PLTT + 0x160, 0x20);
    }
    else
    {
        DmaCopy16(3, gFieldPaletteVariants[gMain.selectedField][gCurrentPinballGame->activePaletteIndex * 2 + 1], (void *)OBJ_PLTT + 0x160, 0x20);
    }

    switch (gCurrentPinballGame->spoinkEntityState)
    {
    case 0:
        gCurrentPinballGame->spoinkAnimFrameIx = 0;
        gCurrentPinballGame->spoinkAnimFrameTimer = 0;
        if (gCurrentPinballGame->ballTouchingSpoink)
            gCurrentPinballGame->spoinkPullbackYDistance = (gCurrentPinballGame->globalAnimFrameCounter % 30) / 15;
        else
            gCurrentPinballGame->spoinkPullbackYDistance = 0;

        gCurrentPinballGame->ballTouchingSpoink = 0;
        break;
    case 1:
        if (gCurrentPinballGame->spoinkAnimFrameTimer < 5)
        {
            if (gCurrentPinballGame->spoinkAnimFrameTimer < 2)
            {
                gCurrentPinballGame->spoinkAnimFrameIx = 2;
                gCurrentPinballGame->spoinkPullbackYDistance = 3;
            }
            else
            {
                gCurrentPinballGame->spoinkAnimFrameIx = 3;
                gCurrentPinballGame->spoinkPullbackYDistance = 5;
            }

            if (gCurrentPinballGame->spoinkAnimFrameTimer == 0)
                m4aSongNumStart(SE_UNKNOWN_0xCC);

            gCurrentPinballGame->spoinkAnimFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->spoinkEntityState = 2;
            gCurrentPinballGame->spoinkAnimFrameIx = 4;
            gCurrentPinballGame->spoinkAnimFrameTimer = 0;
        }
        break;
    case 2:
        if (gSpoinkAnimFrameset[gCurrentPinballGame->spoinkAnimFrameIx][1] <= gCurrentPinballGame->spoinkAnimFrameTimer)
        {
            gCurrentPinballGame->spoinkAnimFrameTimer = 0;
            gCurrentPinballGame->spoinkAnimFrameIx++;
            if (gCurrentPinballGame->spoinkAnimFrameIx > 7)
                gCurrentPinballGame->spoinkAnimFrameIx = 4;
        }
        else
        {
            gCurrentPinballGame->spoinkAnimFrameTimer++;
        }
        break;
    case 3:
        gCurrentPinballGame->spoinkAnimFrameIx = 8;
        gCurrentPinballGame->spoinkAnimFrameTimer = 0;
        gCurrentPinballGame->spoinkEntityState = 4;
        gCurrentPinballGame->spoinkPullbackYDistance = 0;
        break;
    case 4:
        if (gSpoinkAnimFrameset[gCurrentPinballGame->spoinkAnimFrameIx][1] > gCurrentPinballGame->spoinkAnimFrameTimer)
        {
            gCurrentPinballGame->spoinkAnimFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->spoinkAnimFrameTimer = 0;
            gCurrentPinballGame->spoinkAnimFrameIx++;
            if (gCurrentPinballGame->spoinkAnimFrameIx > 0x13)
            {
                gCurrentPinballGame->spoinkAnimFrameIx = 0;
                gCurrentPinballGame->spoinkEntityState = 0;
            }
        }
        break;
    }
}

void DrawSpoinkSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = gMain.fieldSpriteGroups[44];
    if (group->available)
    {
        if (gCurrentPinballGame->spoinkAnimFrameIx == 0)
            index = (gCurrentPinballGame->globalAnimFrameCounter % 30) / 15;
        else
            index = gSpoinkAnimFrameset[gCurrentPinballGame->spoinkAnimFrameIx][0];

        DmaCopy16(3, gSpoinkEntity_Gfx[index], (void *)0x060120E0, 0x1C0);
        group->baseX = 231 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 376 - gCurrentPinballGame->cameraYOffset;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void RunEvolutionCutscene(void)
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
            DmaCopy16(3, (void *)0x05000200, gCurrentPinballGame->pauseObjPalette, 0x200);
            gCurrentPinballGame->creatureOamPriority = 0;
            gCurrentPinballGame->boardEntityActive = 0;
        }

        if (gCurrentPinballGame->stageTimer == 10)
        {
            gCurrentPinballGame->activePortraitType = 16;
            DmaCopy16(3, gBoardActionTilesGfx, (void *)0x06015800, 0x2400);
            DmaCopy16(3, gBoardActionObjPal, (void *)0x050003C0, 0x20);
            gMain.fieldSpriteGroups[24]->available = 1;
            gMain.fieldSpriteGroups[25]->available = 1;
            gMain.fieldSpriteGroups[26]->available = 1;
            gMain.fieldSpriteGroups[27]->available = 1;
            gMain.fieldSpriteGroups[28]->available = 1;
            gMain.fieldSpriteGroups[15]->available = 1;
        }

        if (gCurrentPinballGame->scrollEffectY < 236)
            gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->stageTimer / 2;;

        if (gCurrentPinballGame->stageTimer > 35)
        {
            if (gCurrentPinballGame->stageTimer < 68)
            {
                var0 = gCurrentPinballGame->stageTimer - 36;
                for (j = 0; j <= var0; j++)
                {
                    for (i = 1; i < 11; i++)
                        gBG0TilemapBuffer[(i + 15) * 0x20 + j] = 0xC100;
                }

                DmaCopy16(3, gBG0TilemapBuffer, (void *)0x06002000, 0x800);
                if (var0 == 30)
                    m4aSongNumStart(MUS_EVOLUTION);

                if (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->stageTimer == 67)
                    gCurrentPinballGame->sapphireBumperTimer = 120;
            }
            else if (gCurrentPinballGame->stageTimer <= 344)
            {
                for (j = 0; j <= 30; j++)
                {
                    for (i = 1; i < 11; i++)
                        gBG0TilemapBuffer[(i + 15) * 32 + j] = 0xC100;
                }

                DmaCopy16(3, gBG0TilemapBuffer, (void *)0x06002000, 0x800);
            }
        }

        if (gCurrentPinballGame->stageTimer - 270 >= 0 && gCurrentPinballGame->stageTimer - 270 <= 30)
        {
            var0 = gCurrentPinballGame->stageTimer - 270;
            if (var0 == 0)
            {
                for (i = 0; i < 16; i++)
                {
                    gPaletteFadeRGBCache[i][0] = gCurrentPinballGame->pauseObjPalette[13][i] & 0x1F;
                    gPaletteFadeRGBCache[i][1] = (gCurrentPinballGame->pauseObjPalette[13][i] & 0x3E0) >> 5;
                    gPaletteFadeRGBCache[i][2] = (gCurrentPinballGame->pauseObjPalette[13][i] & 0x7C00) >> 10;
                }
            }
            else
            {
                u16 *destColor;
                for (i = 0; i < 16; i++)
                {
                    destColor = sp1B0;
                    sp210[0] = gPaletteFadeRGBCache[i][0] + ((0x1F - gPaletteFadeRGBCache[i][0]) * var0) / 30;
                    sp210[1] = gPaletteFadeRGBCache[i][1] + ((0x1F - gPaletteFadeRGBCache[i][1]) * var0) / 30;
                    sp210[2] = gPaletteFadeRGBCache[i][2] + ((0x1F - gPaletteFadeRGBCache[i][2]) * var0) / 30;
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
            gCurrentPinballGame->startButtonDisabled = 1;
            var0 = gCurrentPinballGame->stageTimer - 300;
            gMain.blendControl = 0x9F;
            gMain.blendBrightness = var0;
        }

        if (gCurrentPinballGame->stageTimer > 10)
        {
            group = gMain.fieldSpriteGroups[24];
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

            group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 308 - gCurrentPinballGame->cameraYOffset;
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

            group = gMain.fieldSpriteGroups[25];
            group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 308 - gCurrentPinballGame->cameraYOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.fieldSpriteGroups[26];
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

            group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 308 - gCurrentPinballGame->cameraYOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.fieldSpriteGroups[27];
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

            group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 308 - gCurrentPinballGame->cameraYOffset;
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

            group = gMain.fieldSpriteGroups[28];
            group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 308 - gCurrentPinballGame->cameraYOffset;
            for (i = 0; i < 8; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = group->baseX + sp0[i];
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.fieldSpriteGroups[15];
            group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 308 - gCurrentPinballGame->cameraYOffset;
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
                *dst++ = gEvolutionSparkleSpritesheetOam[index][i * 3 + 0];
                *dst++ = gEvolutionSparkleSpritesheetOam[index][i * 3 + 1];
                *dst++ = gEvolutionSparkleSpritesheetOam[index][i * 3 + 2];
                gOamBuffer[oamSimple->oamId].x += group->baseX + sp0[0];
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->stageTimer == 350)
        {
            for (i = 0x1E0; i < 0x340; i++)
                gBG0TilemapBuffer[i] = 0x1FF;

            DmaCopy16(3, gBG0TilemapBuffer, (void *)0x06002000, 0x800);
            if (gMain.selectedField == FIELD_SAPPHIRE)
                gCurrentPinballGame->sapphireBumperTimer = 0;
        }

        if (gCurrentPinballGame->stageTimer == 360)
        {
            gMain.fieldSpriteGroups[24]->available = 0;
            gMain.fieldSpriteGroups[25]->available = 0;
            gMain.fieldSpriteGroups[26]->available = 0;
            gMain.fieldSpriteGroups[27]->available = 0;
            gMain.fieldSpriteGroups[28]->available = 0;
            gMain.fieldSpriteGroups[15]->available = 0;
            gCurrentPinballGame->currentSpecies = gCurrentPinballGame->postEvoSpecies;
            LoadPortraitGraphics(3, 0);
            gCurrentPinballGame->activePortraitType = 17;
            DmaCopy16(3, gHatchFinalTilesGfx, (void *)0x06015800, 0x1800);
            DmaCopy16(3, gHatchFinalPalette, (void *)0x050003C0, 0x20);
            gCurrentPinballGame->creatureOamPriority = 3;
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
                gCurrentPinballGame->bgmFadeTimer = 140;
                PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].speciesIdRS, 0);
            }

            if (var0 == 64)
            {
                gCurrentPinballGame->revealAnimFrameCounter = 0;
                gCurrentPinballGame->revealFramesetIndex = 0;
                gMain.fieldSpriteGroups[37]->available = 1;
            }
        }
        else
        {
            gCurrentPinballGame->startButtonDisabled = 0;
            if (gHatchRevealFinalTimings[gCurrentPinballGame->revealFramesetIndex] > gCurrentPinballGame->revealAnimFrameCounter)
            {
                gCurrentPinballGame->revealAnimFrameCounter++;
            }
            else
            {
                gCurrentPinballGame->revealAnimFrameCounter = 0;
                gCurrentPinballGame->revealFramesetIndex++;
                if (gCurrentPinballGame->revealFramesetIndex > 10)
                {
                    gMain.fieldSpriteGroups[37]->available = 0;
                    gCurrentPinballGame->revealFramesetIndex = 10;
                    gCurrentPinballGame->stageTimer = 0;
                    gCurrentPinballGame->boardSubState++;
                    DmaCopy16(3, gCurrentPinballGame->pauseObjPalette, (void *)0x05000200, 0x180);
                    gCurrentPinballGame->activePortraitType = 0;
                }
            }

            index = gCurrentPinballGame->revealFramesetIndex;
            group = gMain.fieldSpriteGroups[37];
            group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
            if (group->baseY >= 200)
                group->baseY = 200;

            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                *dst++ = gHatchSequentialOamFramesets[index][i * 3 + 0];
                *dst++ = gHatchSequentialOamFramesets[index][i * 3 + 1];
                *dst++ = gHatchSequentialOamFramesets[index][i * 3 + 2];
                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }
    }
}

void RunTravelEventCutscene(void)
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
        gMain.fieldSpriteGroups[16]->available = 1;
        gCurrentPinballGame->travelPainterPosX = 1400;
        gCurrentPinballGame->travelPainterPosY = -600;
        gCurrentPinballGame->activePortraitType = 21;
        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gRubyBoardBonusGfx, (void *)0x06015800, 0x1800);
            DmaCopy16(3, gRubyBoardBonusObjPalette, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gRubyTravelVolbeat_Gfx, (void *)0x06015800, 0x480);
        }
        else
        {
            DmaCopy16(3, gSapphireBoardBonusGfx, (void *)0x06015800, 0x1800);
            DmaCopy16(3, gSapphireBoardBonusObjPalette, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gSapphireTravelIllumise_Gfx, (void *)0x06015800, 0x480);
        }
    }
    else
    {
        if (gCurrentPinballGame->stageTimer < 60)
        {
            u16 angle = (gCurrentPinballGame->stageTimer * 0x4000) / 60;
            gCurrentPinballGame->travelPainterPosX = (Cos(angle) * 900) / 20000 + 487;
            gCurrentPinballGame->travelPainterPosY = (Sin(angle) * 600) / 20000 - 629;
            gCurrentPinballGame->travelPainterVelX = -17;
            gCurrentPinballGame->travelPainterVelY = -30;
            index = (gCurrentPinballGame->stageTimer % 4) / 2;
            if (gCurrentPinballGame->stageTimer % 10 == 0)
                m4aSongNumStart(SE_TRAVEL_PAINTER_FLIGHT);
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

            gCurrentPinballGame->travelPainterVelY += 2;
            gCurrentPinballGame->travelPainterPosX += gCurrentPinballGame->travelPainterVelX;
            gCurrentPinballGame->travelPainterPosY += gCurrentPinballGame->travelPainterVelY;
            gCurrentPinballGame->travelAnimKeyframeIndex = 0;
            gCurrentPinballGame->travelAnimSubTimer = 0;
        }
        else if (gCurrentPinballGame->stageTimer < 190)
        {
            if (gTravelEventAnimData[gCurrentPinballGame->travelAnimKeyframeIndex][2] > gCurrentPinballGame->travelAnimSubTimer)
            {
                gCurrentPinballGame->travelAnimSubTimer++;
            }
            else
            {
                gCurrentPinballGame->travelAnimSubTimer = 0;
                gCurrentPinballGame->travelAnimKeyframeIndex++;
                if (gCurrentPinballGame->travelAnimKeyframeIndex == 7)
                {
                    gCurrentPinballGame->area =  gAreaRouletteTable[gMain.selectedField][gCurrentPinballGame->areaRouletteSlotIndex];
                    gCurrentPinballGame->rouletteAreaIndex[0] = gAreaToSpeciesTable[gCurrentPinballGame->area];
                    LoadPortraitGraphics(0, 0);
                }

                if (gCurrentPinballGame->travelAnimKeyframeIndex == 11)
                    gCurrentPinballGame->stageTimer = 189;
            }

            index = gTravelEventAnimData[gCurrentPinballGame->travelAnimKeyframeIndex][1];
            if (gTravelEventAnimData[gCurrentPinballGame->travelAnimKeyframeIndex][2] == 5 && gCurrentPinballGame->travelAnimSubTimer == 1)
                m4aSongNumStart(SE_TRAVEL_PAINTER_PAINTS);

            if (index == 16)
                gCurrentPinballGame->travelPainterPosX = -80;
            else
                gCurrentPinballGame->travelPainterPosX = 0;

            gCurrentPinballGame->travelPainterVelX = -24;
            gCurrentPinballGame->travelPainterVelY = 14;
        }
        else if (gCurrentPinballGame->stageTimer < 430)
        {
            var0 = gCurrentPinballGame->stageTimer - 190;
            if (var0 < 24)
            {
                gCurrentPinballGame->travelPainterPosX = var0 * -14;
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
                gCurrentPinballGame->travelPainterVelY--;
                gCurrentPinballGame->travelPainterPosX += gCurrentPinballGame->travelPainterVelX;
                gCurrentPinballGame->travelPainterPosY += gCurrentPinballGame->travelPainterVelY;
                if (gCurrentPinballGame->stageTimer % 10 == 0)
                    m4aSongNumStart(SE_TRAVEL_PAINTER_FLIGHT);
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gRubyTravelVolbeat_Gfx[index], (void *) 0x06015800, 0x480);
        }
        else
        {
            DmaCopy16(3, gSapphireTravelIllumise_Gfx[index], (void *) 0x06015800, 0x480);
        }

        index = gTravelEventAnimData[gCurrentPinballGame->travelAnimKeyframeIndex][0];
        group = gMain.fieldSpriteGroups[16];
        group->baseX = gCurrentPinballGame->travelPainterPosX / 10 + 96u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->travelPainterPosY / 10 + 300u - gCurrentPinballGame->cameraYOffset;

        for( i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst =(u16*) &gOamBuffer[oamSimple->oamId];
            *dst++ = gTravelEventSpritesheetOam[index][i * 3 + 0];
            *dst++ = gTravelEventSpritesheetOam[index][i * 3 + 1];
            *dst++ = gTravelEventSpritesheetOam[index][i * 3 + 2];
            gOamBuffer[oamSimple->oamId].x +=  group->baseX;
            gOamBuffer[oamSimple->oamId].y +=  group->baseY;
        }
    }

    if (gCurrentPinballGame->stageTimer == 489)
    {
        gMain.fieldSpriteGroups[16]->available = 0;
        gCurrentPinballGame->activePortraitType = 0;
    }
}

