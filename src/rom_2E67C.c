#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/main_board.h"

extern const s16 gPelipperIdleFrameIndices[];
extern const s16 gPelipperSwallowAnimData[][3];
extern const s8 gPelipperFlyAnimTable[][2];
extern const u8 gPelipper_Gfx[][0x480];
extern const u16 gPelipperPondSpritesheetOam[20][4][3];
extern const s16 gWailmerAnimFrameMap[][2];
extern const u8 gSapphireBoardWailmer_Gfx[][0x300];
extern const u16 gWailmerSpritesheetOam[26][2][3];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];
extern const s16 gZigzagoonAnimKeyframes[][3];
extern const u8 gSapphireBoardZigzagoon_Gfx[][0x380];
extern const u16 gSapphireBoardZigzagoonSpritesheetOam[42][3][3];
extern const u16 gZigzagoonFxSpritesheetOam[14][7][3];
extern const u8 gZigzagoonShockWallIndicator_Gfx[][0x200];
extern const s16 gSapphireBumperAnimFrames[][2];
extern const s16 gBumperMosaicValues[];
extern const u8 gSapphireBumperLeft_Gfx[][0x300];
extern const u8 gSapphireBumperLeftHit_Gfx[][0x200];
extern const u8 gSapphireBumperRight_Gfx[][0x300];
extern const u8 gSapphireBumperRightHit_Gfx[][0x200];
extern const u8 gSapphireBoardShopShockWall_Gfx[][0x80];
extern const u8 gPondBumper_Gfx[][0x200];
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
extern struct SongHeader se_unk_e3;
extern const s16 gHatchRevealFinalTimings[];
extern const u16 gHatchSequentialOamFramesets[22][12];
extern const u8 gBoardActionTilesGfx[];
extern const u8 gBoardActionObjPal[];
extern const u16 gEvolutionSparkleSpritesheetOam[20][12];
extern const u8 gHatchFinalTilesGfx[];
extern const u8 gHatchFinalPalette[];
extern const s16 gSapphirePondAnimFramesets[][2];
extern const u8 gSapphirePondEntity_Gfx[][0x1C0];
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

    switch (gCurrentPinballGame->sapphirePondFlag)
    {
    case 0:
        gCurrentPinballGame->pondAnimFrameIndex = 0;
        gCurrentPinballGame->pondAnimSubTimer = 0;
        if (gCurrentPinballGame->sapphireEntityCollisionFlag)
            gCurrentPinballGame->sapphireSpriteTimer = (gCurrentPinballGame->globalAnimFrameCounter % 30) / 15;
        else
            gCurrentPinballGame->sapphireSpriteTimer = 0;

        gCurrentPinballGame->sapphireEntityCollisionFlag = 0;
        break;
    case 1:
        if (gCurrentPinballGame->pondAnimSubTimer < 5)
        {
            if (gCurrentPinballGame->pondAnimSubTimer < 2)
            {
                gCurrentPinballGame->pondAnimFrameIndex = 2;
                gCurrentPinballGame->sapphireSpriteTimer = 3;
            }
            else
            {
                gCurrentPinballGame->pondAnimFrameIndex = 3;
                gCurrentPinballGame->sapphireSpriteTimer = 5;
            }

            if (gCurrentPinballGame->pondAnimSubTimer == 0)
                m4aSongNumStart(SE_UNKNOWN_0xCC);

            gCurrentPinballGame->pondAnimSubTimer++;
        }
        else
        {
            gCurrentPinballGame->sapphirePondFlag = 2;
            gCurrentPinballGame->pondAnimFrameIndex = 4;
            gCurrentPinballGame->pondAnimSubTimer = 0;
        }
        break;
    case 2:
        if (gSapphirePondAnimFramesets[gCurrentPinballGame->pondAnimFrameIndex][1] <= gCurrentPinballGame->pondAnimSubTimer)
        {
            gCurrentPinballGame->pondAnimSubTimer = 0;
            gCurrentPinballGame->pondAnimFrameIndex++;
            if (gCurrentPinballGame->pondAnimFrameIndex > 7)
                gCurrentPinballGame->pondAnimFrameIndex = 4;
        }
        else
        {
            gCurrentPinballGame->pondAnimSubTimer++;
        }
        break;
    case 3:
        gCurrentPinballGame->pondAnimFrameIndex = 8;
        gCurrentPinballGame->pondAnimSubTimer = 0;
        gCurrentPinballGame->sapphirePondFlag = 4;
        gCurrentPinballGame->sapphireSpriteTimer = 0;
        break;
    case 4:
        if (gSapphirePondAnimFramesets[gCurrentPinballGame->pondAnimFrameIndex][1] > gCurrentPinballGame->pondAnimSubTimer)
        {
            gCurrentPinballGame->pondAnimSubTimer++;
        }
        else
        {
            gCurrentPinballGame->pondAnimSubTimer = 0;
            gCurrentPinballGame->pondAnimFrameIndex++;
            if (gCurrentPinballGame->pondAnimFrameIndex > 0x13)
            {
                gCurrentPinballGame->pondAnimFrameIndex = 0;
                gCurrentPinballGame->sapphirePondFlag = 0;
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
        if (gCurrentPinballGame->pondAnimFrameIndex == 0)
            index = (gCurrentPinballGame->globalAnimFrameCounter % 30) / 15;
        else
            index = gSapphirePondAnimFramesets[gCurrentPinballGame->pondAnimFrameIndex][0];

        DmaCopy16(3, gSapphirePondEntity_Gfx[index], (void *)0x060120E0, 0x1C0);
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

void DecrementFieldTimer(void)
{
    if (gCurrentPinballGame->pelipperState == 1)
    {
        if (gCurrentPinballGame->pelipperFrameTimer)
            gCurrentPinballGame->pelipperFrameTimer--;
        else
            gCurrentPinballGame->pelipperState = 0;
    }
}

//Sapphire pond - Pelipper
void UpdatePelipperPondEntity(void)
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
        gCurrentPinballGame->pelipperYBobOffset = 0;
        var_sl = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
        gCurrentPinballGame->pelipperPosX = 0;
        gCurrentPinballGame->pelipperPosY = 0;
        break;
    case 1:
        var_sl = gPelipperIdleFrameIndices[(gCurrentPinballGame->globalAnimFrameCounter % 40) / 10];
        gCurrentPinballGame->pelipperPosX = 0;
        gCurrentPinballGame->pelipperPosY = 0;
        gCurrentPinballGame->pelipperSwallowAnimIndex = 0;
        gCurrentPinballGame->pelipperSwallowSubTimer = 0;
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
        if (gCurrentPinballGame->pelipperFrameTimer < 3)
        {
            if (gCurrentPinballGame->pelipperFrameTimer == 0)
            {
                gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
                gCurrentPinballGame->ballFrozenState = 1;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
                gCurrentPinballGame->ball->spinSpeed = 0;
                m4aSongNumStart(SE_UNKNOWN_0xE2);
                PlayRumble(7);
                gCurrentPinballGame->scoreAddedInFrame = 100000;
            }

            gCurrentPinballGame->ball->positionQ0.x = 156;
            gCurrentPinballGame->ball->positionQ0.y = 121 + gCurrentPinballGame->pelipperFrameTimer * 2;
            var_sl = 4;
        }
        else if (gCurrentPinballGame->pelipperFrameTimer < 23)
        {
            gCurrentPinballGame->ball->positionQ0.x = 157;
            gCurrentPinballGame->ball->positionQ0.y = 134;
            gCurrentPinballGame->ball->ballHidden = 1;
            var_sl = 5;
        }
        else
        {
            gCurrentPinballGame->pelipperState = 4;
            gCurrentPinballGame->pelipperFrameTimer = 0;
            var_sl = 2;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->pelipperFrameTimer++;
        gCurrentPinballGame->pelipperSfxTimer = 0;
        break;
    case 4:
        if (gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][2] > gCurrentPinballGame->pelipperSwallowSubTimer)
        {
            gCurrentPinballGame->pelipperSwallowSubTimer++;
        }
        else
        {
            gCurrentPinballGame->pelipperSwallowSubTimer = 0;
            gCurrentPinballGame->pelipperSwallowAnimIndex++;
            if (gCurrentPinballGame->pelipperSwallowAnimIndex == 21)
            {
                gCurrentPinballGame->pelipperSwallowAnimIndex = 20;
                gCurrentPinballGame->pelipperState = 5;
                gCurrentPinballGame->pelipperFrameTimer = 0;
            }

            if (gCurrentPinballGame->pelipperSwallowAnimIndex == 1)
                m4aSongNumStart(SE_UNKNOWN_0xE3);
        }

        sp0 = gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][0];
        var_sl = gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][1];
        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 5:
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
        {
            gCurrentPinballGame->pelipperPosX = -360;
            gCurrentPinballGame->pelipperPosY = -200;
        }

        index = (gCurrentPinballGame->pelipperFrameTimer % 26) / 2;
        var_sl = gPelipperFlyAnimTable[index][0];
        gCurrentPinballGame->pelipperYBobOffset = gPelipperFlyAnimTable[index][1] * 10;
        gCurrentPinballGame->pelipperFlyVelX = -12;
        gCurrentPinballGame->pelipperFlyVelY = -10;
        gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
        gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperPosX / 10 + 157;
        gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperPosY / 10 + 134;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->pelipperFrameTimer++;
        if (gCurrentPinballGame->ball->positionQ0.y < -12)
        {
            if (gCurrentPinballGame->bumperHitsSinceReset > 99)
            {
                gCurrentPinballGame->bumperHitsSinceReset = 0;
                gCurrentPinballGame->pelipperState = 6;
                gCurrentPinballGame->pelipperFrameTimer = 65;
                m4aMPlayAllStop();
            }
            else
            {
                gCurrentPinballGame->pelipperFrameTimer = 0;
                gCurrentPinballGame->pelipperState = 7;
            }
        }

        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 6:
        gCurrentPinballGame->startButtonDisabled = 1;
        var_sl = gPelipperFlyAnimTable[0][0];
        if (gCurrentPinballGame->pelipperFrameTimer == 65)
        {
            m4aSongNumStart(SE_WARP);
            gMain.blendControl = 0x9E;
        }

        if (gCurrentPinballGame->pelipperFrameTimer)
        {
            gCurrentPinballGame->pelipperFrameTimer--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->pelipperFrameTimer / 4;
            if (gCurrentPinballGame->pelipperFrameTimer == 0)
            {
                gCurrentPinballGame->nextBonusField = FIELD_SPHEAL;
                gCurrentPinballGame->bonusReturnState = 2;
                gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
                gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
                TransitionToBonusField();
            }
        }
        break;
    case 7:
        gCurrentPinballGame->pelipperPosX = -1880;
        gCurrentPinballGame->pelipperPosY = -800;
        gCurrentPinballGame->pelipperFlyVelX = 82;
        gCurrentPinballGame->pelipperFlyVelY = 0;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        gCurrentPinballGame->pelipperState = 8;
        var_sl = 13;
        sp0 = 9;
        break;
    case 8:
        var_sl = (gCurrentPinballGame->pelipperFrameTimer % 24) / 6 + 13;
        gCurrentPinballGame->pelipperYBobOffset = (Sin(gCurrentPinballGame->pelipperFrameTimer * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->pelipperFrameTimer < 40)
        {
            gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
            gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        }
        else if (gCurrentPinballGame->pelipperFrameTimer >= 70)
        {
            gCurrentPinballGame->pelipperFrameTimer = 0;
            gCurrentPinballGame->pelipperState = 9;
            gCurrentPinballGame->pelipperPosX = 1200;
            gCurrentPinballGame->pelipperPosY = -1000;
            m4aSongNumStart(SE_UNKNOWN_0xE3);
            gCurrentPinballGame->pelipperSfxTimer = 0;
        }

        if (gCurrentPinballGame->pelipperFrameTimer == 13)
        {
            gCurrentPinballGame->ball->ballHidden = 0;
            gCurrentPinballGame->pelipperBallDropVelX = 5;
            gCurrentPinballGame->pelipperBallDropVelY = -25;
            gCurrentPinballGame->pelipperBallDropPosX = (gCurrentPinballGame->pelipperPosX / 10 + 157) * 10;
            gCurrentPinballGame->pelipperBallDropPosY = (gCurrentPinballGame->pelipperPosY / 10 + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->ballFrozenState)
        {
            if (gCurrentPinballGame->pelipperFrameTimer < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperPosX / 10 + 157;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperPosY / 10 + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->pelipperBallDropVelY += 2;
                gCurrentPinballGame->pelipperBallDropPosX += gCurrentPinballGame->pelipperBallDropVelX;
                gCurrentPinballGame->pelipperBallDropPosY += gCurrentPinballGame->pelipperBallDropVelY;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperBallDropPosX / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperBallDropPosY / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 91)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 91;
                    gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
                    gCurrentPinballGame->ballFrozenState = 0;
                    gCurrentPinballGame->ball->velocity.x = 128;
                    gCurrentPinballGame->ball->velocity.y = 256;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->boardLayerDepth = 0;
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
        gCurrentPinballGame->pelipperFrameTimer++;
        break;
    case 9:
        index = (gCurrentPinballGame->pelipperFrameTimer % 26) / 2;
        var_sl = gPelipperFlyAnimTable[index][0] + 4;
        gCurrentPinballGame->pelipperYBobOffset = gPelipperFlyAnimTable[index][1];
        gCurrentPinballGame->pelipperFlyVelX = -12;
        gCurrentPinballGame->pelipperFlyVelY = 10;
        if (gCurrentPinballGame->pelipperFrameTimer < 100)
        {
            gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
            gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        }
        else
        {
            gCurrentPinballGame->pelipperFrameTimer = 0;
            gCurrentPinballGame->pelipperState = 10;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);
        }

        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);

        gCurrentPinballGame->pelipperFrameTimer++;
        break;
    case 10:
        gCurrentPinballGame->pelipperYBobOffset = 0;
        gCurrentPinballGame->pelipperState = 0;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        var_sl = 0;
        break;
    }

    if (group->available)
    {
        DmaCopy16(3, gPelipper_Gfx[var_sl], (void *)0x060122A0, 0x480);
        group->baseX = gCurrentPinballGame->pelipperPosX / 10 + 146 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->pelipperPosY / 10 + 110 - gCurrentPinballGame->cameraYOffset + gCurrentPinballGame->pelipperYBobOffset / 10;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gPelipperPondSpritesheetOam[sp0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }
}

void AnimateWailmerEntity(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 var0;

    index = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 16;
    group = &gMain.spriteGroups[75];
    if (gCurrentPinballGame->catchHoleAnimFrame)
        index = gCurrentPinballGame->catchHoleAnimFrame;

    var0 = gWailmerAnimFrameMap[index][0];
    index = gWailmerAnimFrameMap[index][1];
    group->baseX = 164 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 166 - gCurrentPinballGame->cameraYOffset;
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

void UpdateZigzagoonEntity(void)
{
    s16 var0;

    switch (gCurrentPinballGame->zigzagoonState)
    {
    case 0:
        gCurrentPinballGame->zigzagoonGfxFrame = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25 + 2;
        gCurrentPinballGame->zigzagoonOamFrame = gCurrentPinballGame->zigzagoonGfxFrame + 1;
        gCurrentPinballGame->zigzagoonShockWallActive = 0;
        break;
    case 1:
        var0 = gCurrentPinballGame->globalAnimFrameCounter % 33;
        if (var0 < 13)
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 0;
            gCurrentPinballGame->zigzagoonOamFrame = 0;
        }
        else if (var0 < 20)
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 9;
            gCurrentPinballGame->zigzagoonOamFrame = 1;
        }
        else if (var0 < 26)
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 1;
            gCurrentPinballGame->zigzagoonOamFrame = 2;
        }
        else
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 9;
            gCurrentPinballGame->zigzagoonOamFrame = 1;
        }

        if (gCurrentPinballGame->ballCatchState != TRAP_CENTER_HOLE)
            gCurrentPinballGame->zigzagoonShockWallActive = 0;
        break;
    case 2:
        gCurrentPinballGame->zigzagoonShockWallActive = 0;
        gCurrentPinballGame->zigzagoonAnimKeyframeIndex = 0;
        gCurrentPinballGame->sapphireBumperAnimFrame = 0;
        gCurrentPinballGame->zigzagoonState = 3;
        gCurrentPinballGame->zigzagoonFxFrame = 0;
        gMain.spriteGroups[27].available = 1;
        gCurrentPinballGame->activePortraitType = 22;
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x06015800, 0xC00);
        m4aSongNumStart(SE_UNKNOWN_0xEC);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        break;
    case 3:
        if (gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][1] > gCurrentPinballGame->sapphireBumperAnimFrame)
        {
            gCurrentPinballGame->sapphireBumperAnimFrame++;
        }
        else
        {
            gCurrentPinballGame->zigzagoonAnimKeyframeIndex++;
            gCurrentPinballGame->sapphireBumperAnimFrame = 0;
            if (gCurrentPinballGame->zigzagoonAnimKeyframeIndex > 16)
            {
                gCurrentPinballGame->zigzagoonAnimKeyframeIndex = 16;
                gCurrentPinballGame->zigzagoonState = 4;
            }
        }

        gCurrentPinballGame->zigzagoonOamFrame = gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][0];
        gCurrentPinballGame->zigzagoonGfxFrame = gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][2];
        if (gCurrentPinballGame->zigzagoonAnimKeyframeIndex < 6)
            gCurrentPinballGame->zigzagoonFxFrame = gCurrentPinballGame->zigzagoonAnimKeyframeIndex + 1;
        else
            gCurrentPinballGame->zigzagoonFxFrame = 0;
        break;
    case 4:
        gCurrentPinballGame->activePortraitType = 0;
        gMain.spriteGroups[27].available = 0;
        gCurrentPinballGame->zigzagoonState = 0;
        break;
    }
}

void DrawZigzagoonAndShockWall(void)
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
        group->baseX = 198 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->sapphireBumperTimer + 284 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->zigzagoonGfxFrame;
        DmaCopy16(3, gSapphireBoardZigzagoon_Gfx[index], (void *)0x06012A20, 0x380);
        index = gCurrentPinballGame->zigzagoonOamFrame;
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
        group->baseX = 198 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 284 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->zigzagoonFxFrame;
        for (i = 0; i < 7; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gZigzagoonFxSpritesheetOam[index][i];
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
        group->baseX = 206 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->zigzagoonShockWallActive)
        {
            group->baseY = 260 - gCurrentPinballGame->cameraYOffset;
            index = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
            DmaCopy16(3, &gZigzagoonShockWallIndicator_Gfx[index], (void *)0x06014FA0, 0x200);
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

void UpdateSapphireBumperLogic(void)
{
    s16 i;
    u32 mosaicVal;

    for (i = 0; i < 2; i++)
    {
        switch (gCurrentPinballGame->sapphireBumperState[i])
        {
        case 0:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 3)
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
            }

            if (gCurrentPinballGame->sapphireBumperHitFxTimer[i] < 152)
                gCurrentPinballGame->sapphireBumperHitFxTimer[i]++;
            else
                gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 0;
            break;
        case 1:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] == 5)
                {
                    m4aSongNumStart(SE_UNKNOWN_0xE6);
                    gCurrentPinballGame->scoreAddedInFrame = 2000;
                }
            }

            if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] == 6)
            {
                if (gCurrentPinballGame->sapphireBumperLitCountdown)
                {
                    if (gCurrentPinballGame->sapphireBumperLitCountdown == 1)
                    {
                        gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 7;
                        gCurrentPinballGame->sapphireBumperState[i] = 2;
                    }
                }

                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 2:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] == 8)
                    m4aSongNumStart(SE_UNKNOWN_0xE7);

                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 8)
                {
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                    gCurrentPinballGame->sapphireBumperState[i] = 0;
                }
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 3:
            gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 9;
            gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
            gCurrentPinballGame->sapphireBumperState[i] = 4;
            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 4:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 17)
                {
                    if (gCurrentPinballGame->boardState == 6)
                    {
                        gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                        gCurrentPinballGame->sapphireBumperState[i] = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 9;
                    }
                }
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 5:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 17)
                {
                    gCurrentPinballGame->sapphireBumperState[i] = 0;
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                }
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        }
    }

    if (gCurrentPinballGame->ballCatchState != TRAP_EVO_SHOP_HOLE)
    {
        if (gCurrentPinballGame->sapphireBumperLitCountdown)
            gCurrentPinballGame->sapphireBumperLitCountdown--;
    }

    if (gCurrentPinballGame->ballLaunchTimer)
    {
        gCurrentPinballGame->ballLaunchTimer--;
        if (gCurrentPinballGame->ballLaunchTimer == 0)
            gCurrentPinballGame->secondaryBall = gCurrentPinballGame->ballStates;
    }

    if (gCurrentPinballGame->shopBumperHitTimer)
    {
        if (gCurrentPinballGame->shopBumperHitTimer == 17)
        {
            m4aSongNumStart(SE_UNKNOWN_0xE8);
            gCurrentPinballGame->scoreAddedInFrame = 10;
            PlayRumble(13);
        }

        mosaicVal = gBumperMosaicValues[gCurrentPinballGame->shopBumperHitTimer / 3];
        REG_MOSAIC = (mosaicVal << 12) | (mosaicVal << 8) | (mosaicVal << 4) | (mosaicVal << 0);
        gCurrentPinballGame->shopBumperHitTimer--;
    }

    if (gCurrentPinballGame->boardState > 2)
    {
        if (gCurrentPinballGame->boardState != 6)
        {
            for (i = 0; i < 2; i++)
            {
                if (gCurrentPinballGame->sapphireBumperState[i])
                {
                    gCurrentPinballGame->sapphireBumperState[i] = 0;
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                    gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                }
            }
        }
    }
    else if (gCurrentPinballGame->evoArrowProgress > 2)
    {
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->sapphireBumperState[0] < 3)
            {
                gCurrentPinballGame->sapphireBumperState[0] = 3;
                gCurrentPinballGame->sapphireBumperState[1] = 3;
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->sapphireBumperState[0] > 2)
        {
            gCurrentPinballGame->sapphireBumperState[0] = 0;
            gCurrentPinballGame->sapphireBumperAnimKeyframe[0] = 0;
            gCurrentPinballGame->sapphireBumperState[1] = 0;
            gCurrentPinballGame->sapphireBumperAnimKeyframe[1] = 0;
        }
    }
}

void DrawSapphireBumperSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[61];
    if (!group->available)
        return;

    group->baseX = 68 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 144 - gCurrentPinballGame->cameraYOffset;
    index = gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[0]][0];
    DmaCopy16(3, &gSapphireBumperLeft_Gfx[index], (void *)0x06012DA0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[58];
    group->baseX = 68 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->sapphireBumperHitFxTimer[0] < 14)
    {
        group->baseY = 144 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->sapphireBumperHitFxTimer[0] / 2;
        DmaCopy16(3, &gSapphireBumperLeftHit_Gfx[index], (void *)0x06014720, 0x180);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[62];
    group->baseX = 36 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 163 - gCurrentPinballGame->cameraYOffset;
    index = gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[1]][0];
    DmaCopy16(3, &gSapphireBumperRight_Gfx[index], (void *)0x060130A0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[59];
    group->baseX = 36 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->sapphireBumperHitFxTimer[1] < 14)
    {
        group->baseY = 163 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->sapphireBumperHitFxTimer[1] / 2;
        DmaCopy16(3, &gSapphireBumperRightHit_Gfx[index], (void *)0x06014920, 0x180);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[76];
    group->baseX = 61 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 186 - gCurrentPinballGame->cameraYOffset;
    if (gCurrentPinballGame->eggHatchShockWallOverride)
    {
        gCurrentPinballGame->shopShockWallAnimState = 3;
    }
    else if (gCurrentPinballGame->sapphireBumperState[0])
    {
        if (gCurrentPinballGame->sapphireBumperState[1])
            gCurrentPinballGame->shopShockWallAnimState = 3;
        else
            gCurrentPinballGame->shopShockWallAnimState = 2;
    }
    else if (gCurrentPinballGame->sapphireBumperState[1])
    {
        gCurrentPinballGame->shopShockWallAnimState = 1;
    }
    else
    {
        gCurrentPinballGame->shopShockWallAnimState = 0;
    }

    if (gCurrentPinballGame->shopShockWallAnimState < 3)
        index = gCurrentPinballGame->shopShockWallAnimState * 3 + (gCurrentPinballGame->globalAnimFrameCounter % 30) / 10;
    else
        index = 9;

    DmaCopy16(3, &gSapphireBoardShopShockWall_Gfx[index], (void *)0x060146A0, 0x80);
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
}

void CalculateRubyBumperBounce(void)
{
    gCurrentPinballGame->rubyBumperLogicPosition[0].x = 920;
    gCurrentPinballGame->rubyBumperLogicPosition[0].y = (133 - (gCurrentPinballGame->globalAnimFrameCounter % 60) / 30) * 10;
    gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1260;
    gCurrentPinballGame->rubyBumperLogicPosition[1].y = (131 - ((gCurrentPinballGame->globalAnimFrameCounter + 10) % 60) / 30) * 10;
    gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1080;
    gCurrentPinballGame->rubyBumperLogicPosition[2].y = (161 - ((gCurrentPinballGame->globalAnimFrameCounter + 20) % 60) / 30) * 10;
}

void HandleRubyBumperHit(void)
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
                            gCurrentPinballGame->bannerDelayTimer = 50;
                            gCurrentPinballGame->bannerDisplayTimer = 600;
                            gCurrentPinballGame->cameraYScrollTarget = 0xEC;
                            gCurrentPinballGame->cameraYAdjust = 0;
                            gCurrentPinballGame->cameraYScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxIndex = 7;
                            gCurrentPinballGame->bannerActive = 1;
                            gCurrentPinballGame->bannerPreserveBallState = 0;
                            gCurrentPinballGame->bannerDisplayDuration = 80;
                            gCurrentPinballGame->bannerSlidePosition = -2500;
                            gCurrentPinballGame->bannerSlideTimer = 50;
                            gCurrentPinballGame->bannerSlideVelocity = 0;
                            DmaCopy16(3, gModeBannerTilemaps[7], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gModeBannerPalettes[7], (void *)0x050003C0, 0x20);
                            gMain.blendControl = 0xCE;
                        }
                    }
                }
            }

            gCurrentPinballGame->pondEntitySpriteFlag++;
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
            if (gCurrentPinballGame->pondBumperStates[i] > 0)
            {
                if (gCurrentPinballGame->pondBumperStates[i] < 0)
                    gCurrentPinballGame->pondBumperStates[i] += 3;

                index = gCurrentPinballGame->pondBumperStates[i] / 4 + 2;
                gCurrentPinballGame->pondBumperStates[i]--;
            }
            else
            {
                index = ((gCurrentPinballGame->globalAnimFrameCounter + (i * 10)) % 30) / 15;
            }

            DmaCopy16(3, &gPondBumper_Gfx[index], (void *)0x060133A0 + i * 0x200, 0x200);

            group->baseX = gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10 - gCurrentPinballGame->cameraXOffset - 8;
            group->baseY = gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10 - gCurrentPinballGame->cameraYOffset - 10;
            gCurrentPinballGame->rubyBumperCollisionPosition[i].x = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10) + 8) * 2;
            gCurrentPinballGame->rubyBumperCollisionPosition[i].y = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10) + 3) * 2;

            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}
