#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const struct Vector16 gPauseMenuSpriteOffsets[];
extern const u16 gPauseMenuTextAnimFrames[];
extern const u8 gPauseMenuText_Gfx[][0x20];


// Pauses the game and saves the blend settings
// Also stops the BGM if it was playing before
// Sets the blend settings to a dimmed state
void PauseGame(void)
{
    s16 i, j;
    u16 objPalettes[OBJ_PLTT_SIZE / 0x20][0x10];
    u8 rgb[3];

    gCurrentPinballGame->pauseMenuCursorIndex = 1;
    gCurrentPinballGame->pauseAnimTimer = 0;
    if (gMPlayInfo_BGM.status >= 0)
    {
        gCurrentPinballGame->savedBgmSongHeader = gMPlayInfo_BGM.songHeader;
        m4aMPlayStop(&gMPlayInfo_BGM);
    }
    else
    {
        gCurrentPinballGame->savedBgmSongHeader = NULL;
    }

    m4aMPlayAllStop();
    m4aSongNumStart(SE_UNKNOWN_0xA5);
    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        gCurrentPinballGame->hudSpriteBaseY = gCurrentPinballGame->cameraYViewport;
        if (gMain.selectedField == FIELD_RUBY)
            UpdateRubyBoardAnimations();
        else if (gMain.selectedField == FIELD_SAPPHIRE)
            UpdateSapphireBoardAnimations();
    }

    gCurrentPinballGame->pauseBlendControl = gMain.blendControl;
    gCurrentPinballGame->pauseBlendAlpha = gMain.blendAlpha;
    gCurrentPinballGame->pauseBlendBrightness = gMain.blendBrightness;
    gCurrentPinballGame->pauseScoreOverlayActive = gMain.scoreOverlayActive;
    gCurrentPinballGame->pauseVCount = gMain.vCount;
    DmaCopy16(3, (void *)OBJ_PLTT, gCurrentPinballGame->pauseObjPalette, OBJ_PLTT_SIZE);
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
        {
            if (i != 9 || j != 12)
            {
                rgb[0] = (((gCurrentPinballGame->pauseObjPalette[i][j] & 0x001F) >>  0) * 2) / 5;
                rgb[1] = (((gCurrentPinballGame->pauseObjPalette[i][j] & 0x03E0) >>  5) * 2) / 5;
                rgb[2] = (((gCurrentPinballGame->pauseObjPalette[i][j] & 0x7C00) >> 10) * 2) / 5;
                objPalettes[i][j] = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
            }
            else
            {
                objPalettes[i][j] = 0x7FFF;
            }
        }
    }

    DmaCopy16(3, objPalettes, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gMain.selectedField < MAIN_FIELD_COUNT)
        ClampPortraitSpritesToOffscreen();
    else if (gMain.selectedField == FIELD_DUSCLOPS)
        RenderBonusStageOverlaySprites();
    else if (gMain.selectedField == FIELD_KYOGRE)
        HideKyogreSplashSprite();
    else if (gMain.selectedField == FIELD_GROUDON)
        HideGroudonShockwaveSprite();

    SetRumblePaused(1);
}

//Unpauses the game and restores the blend settings
//Also starts the BGM if it was playing before
void UnpauseGame(void)
{
    gMain.blendControl = gCurrentPinballGame->pauseBlendControl;
    gMain.blendAlpha = gCurrentPinballGame->pauseBlendAlpha;
    gMain.blendBrightness = gCurrentPinballGame->pauseBlendBrightness;
    gMain.scoreOverlayActive = gCurrentPinballGame->pauseScoreOverlayActive;
    gMain.vCount = gCurrentPinballGame->pauseVCount;
    DmaCopy16(3, gCurrentPinballGame->pauseObjPalette, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gCurrentPinballGame->savedBgmSongHeader)
        m4aMPlayContinue(&gMPlayInfo_BGM);

    m4aSongNumStart(SE_UNKNOWN_0xA6);
    SetRumblePaused(0);
}

void PositionPauseMenuSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[SG_0];
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
    gOamBuffer[oamSimple->oamId].matrixNum = 0;

    for (i = 1; i < 5; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
        gOamBuffer[oamSimple->oamId].matrixNum = 0;
    }

    for (i = 5; i < 11; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
        gOamBuffer[oamSimple->oamId].matrixNum = 0;
    }

    group = &gMain.spriteGroups[SG_1];
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    }

    group = &gMain.spriteGroups[SG_2];
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    }
}

void AnimatePauseMenuOverlay(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const struct Vector16 *offsets;
    s16 xOffset;
    s16 yOffset;
    s16 var0;
    s16 sb;
    s16 yScale = 8;

    if (gCurrentPinballGame->pauseAnimTimer == 0)
    {
        gMain.blendControl = 0xCF;
        gMain.blendBrightness = 0xA;
        gMain.scoreOverlayActive = 0;
        gMain.vCount = 144;
    }

    if (gCurrentPinballGame->pauseAnimTimer < 16)
    {
        xOffset = 160 - gCurrentPinballGame->pauseAnimTimer * 10;
        yOffset = 24;
        var0 = -1;
        sb = -1;
        yScale = 16;
    }
    else if (gCurrentPinballGame->pauseAnimTimer < 24)
    {
        xOffset = 0;
        yOffset = 24 - (gCurrentPinballGame->pauseAnimTimer - 15) * 3;
        if (gCurrentPinballGame->pauseAnimTimer < 18)
        {
            var0 = -1;
            sb = -1;
            yScale = 8;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 18)
        {
            var0 = 9;
            sb = -10;
            yScale = 16;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 19)
        {
            var0 = 9;
            sb = -9;
            yScale = 128;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 20)
        {
            var0 = 7;
            sb = -8;
            yScale = 160;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 21)
        {
            var0 = 6;
            sb = -7;
            yScale = 192;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 22)
        {
            var0 = 4;
            sb = -5;
            yScale = 224;
        }
        else
        {
            var0 = 4;
            sb = -4;
            yScale = 256;
        }
    }
    else
    {
        xOffset = 0;
        yOffset = 0;
        var0 = 4;
        sb = -4;
        yScale = 256;
    }

    group = &gMain.spriteGroups[SG_0];
    if (var0 >= 0)
    {
        s16 index;

        group->baseX = 100;
        group->baseY = 80 + var0;
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gPauseMenuSpriteOffsets[0].x;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gPauseMenuSpriteOffsets[0].y + gCurrentPinballGame->pauseMenuCursorIndex * 12;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
        gOamBuffer[oamSimple->oamId].matrixNum = 5;

        index = gPauseMenuTextAnimFrames[(gMain.systemFrameCount % 65) / 5];
        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            DmaCopy16(3, gPauseMenuText_Gfx[index], (void *)0x060118C0, 0x20);
        }
        else
        {
            DmaCopy16(3, gPauseMenuText_Gfx[index], (void *)0x06010480, 0x20);
        }

        offsets = gPauseMenuSpriteOffsets;
        group->baseX = 100;
        group->baseY = 80 + var0;
        for (i = 1; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }

        group->baseX = 100;
        group->baseY = 88 + sb;
        for (i = 5; i < 11; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }
    }

    SetMatrixScale(0x100, yScale, 5);

    group = &gMain.spriteGroups[SG_1];
    group->baseX = 100 - xOffset;
    group->baseY = 80 + yOffset;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[SG_2];
    group->baseX = 68 + xOffset;
    group->baseY = 108 - yOffset;
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    gCurrentPinballGame->pauseAnimTimer++;
}
