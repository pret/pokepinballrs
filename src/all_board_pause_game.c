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
    Palette objPalettes[PALETTES_PER_BANK];
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
    m4aSongNumStart(SE_PAUSING);
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
    DmaCopy16(3, OBJ_PLTT, gCurrentPinballGame->pauseObjPalette, OBJ_PLTT_SIZE);
    for (i = 0; i < PALETTES_PER_BANK; i++)
    {
        for (j = 0; j < COLORS_PER_PALETTE; j++)
        {
            //Palette 9, color 12 is used for the white text in the pause screen
            if (i != 9 || j != 12)
            {
                rgb[0] = (RGB5_GET_R(gCurrentPinballGame->pauseObjPalette[i][j]) * 2) / 5;
                rgb[1] = (RGB5_GET_G(gCurrentPinballGame->pauseObjPalette[i][j]) * 2) / 5;
                rgb[2] = (RGB5_GET_B(gCurrentPinballGame->pauseObjPalette[i][j]) * 2) / 5;
                objPalettes[i][j] = RGB5(rgb[0],rgb[1],rgb[2]);
            }
            else
            {
                objPalettes[i][j] = RGB_WHITE;
            }
        }
    }

    DmaCopy16(3, objPalettes, OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gMain.selectedField < MAIN_FIELD_COUNT)
        ClampPortraitSpritesToOffscreen();
    else if (gMain.selectedField == FIELD_DUSCLOPS)
        HideDusclopsSprites();
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
    DmaCopy16(3, gCurrentPinballGame->pauseObjPalette, OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gCurrentPinballGame->savedBgmSongHeader)
        m4aMPlayContinue(&gMPlayInfo_BGM);

    m4aSongNumStart(SE_UNPAUSING);
    SetRumblePaused(0);
}

void PositionPauseMenuSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[SG_PAUSE_PANEL];
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

    group = &gMain.spriteGroups[SG_PAUSE_TOP_BORDER];
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    }

    group = &gMain.spriteGroups[SG_PAUSE_BOTTOM_BORDER];
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
    s16 saveLabelYOffset;
    s16 cancelLabelYOffset;
    s16 yScale = 8;

    if (gCurrentPinballGame->pauseAnimTimer == 0)
    {
        gMain.blendControl = 0xCF;
        gMain.blendBrightness = 0xA;
        gMain.scoreOverlayActive = FALSE;
        gMain.vCount = 144;
    }

    if (gCurrentPinballGame->pauseAnimTimer < 16)
    {
        xOffset = 160 - gCurrentPinballGame->pauseAnimTimer * 10;
        yOffset = 24;
        saveLabelYOffset = -1;
        cancelLabelYOffset = -1;
        yScale = 16;
    }
    else if (gCurrentPinballGame->pauseAnimTimer < 24)
    {
        xOffset = 0;
        yOffset = 24 - (gCurrentPinballGame->pauseAnimTimer - 15) * 3;
        if (gCurrentPinballGame->pauseAnimTimer < 18)
        {
            saveLabelYOffset = -1;
            cancelLabelYOffset = -1;
            yScale = 8;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 18)
        {
            saveLabelYOffset = 9;
            cancelLabelYOffset = -10;
            yScale = 16;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 19)
        {
            saveLabelYOffset = 9;
            cancelLabelYOffset = -9;
            yScale = 128;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 20)
        {
            saveLabelYOffset = 7;
            cancelLabelYOffset = -8;
            yScale = 160;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 21)
        {
            saveLabelYOffset = 6;
            cancelLabelYOffset = -7;
            yScale = 192;
        }
        else if (gCurrentPinballGame->pauseAnimTimer == 22)
        {
            saveLabelYOffset = 4;
            cancelLabelYOffset = -5;
            yScale = 224;
        }
        else
        {
            saveLabelYOffset = 4;
            cancelLabelYOffset = -4;
            yScale = 256;
        }
    }
    else
    {
        xOffset = 0;
        yOffset = 0;
        saveLabelYOffset = 4;
        cancelLabelYOffset = -4;
        yScale = 256;
    }

    group = &gMain.spriteGroups[SG_PAUSE_PANEL];
    if (saveLabelYOffset >= 0)
    {
        s16 index;

        group->baseX = 100;
        group->baseY = 80 + saveLabelYOffset;
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
        group->baseY = 80 + saveLabelYOffset;
        for (i = 1; i < 5; i++)
        {
            // Characters in the word 'SAVE'
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }

        group->baseX = 100;
        group->baseY = 88 + cancelLabelYOffset;
        for (i = 5; i < 11; i++)
        {
            // Characters in the word 'CANCEL'
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }
    }

    SetMatrixScale(0x100, yScale, 5);

    group = &gMain.spriteGroups[SG_PAUSE_TOP_BORDER];
    group->baseX = 100 - xOffset;
    group->baseY = 80 + yOffset;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[SG_PAUSE_BOTTOM_BORDER];
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
