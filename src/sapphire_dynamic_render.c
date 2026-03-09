#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 *gUnknown_086B0E6C[][2];
extern const u8 *gUnknown_086B0F9C[][3][2];
extern const u8 *gUnknown_086B12AC[][3];
extern const u8 *gUnknown_086B125C[][4];
extern const u8 *gUnknown_086B12D0[][4];
extern const u8 *gUnknown_086B14A8[][5][3];
extern const u8 *gUnknown_086B1340[][5][3];
extern const u8 *gUnknown_086B122C[][4];
extern const u8 *gUnknown_086B11FC[][4];
extern const u8 *gUnknown_086B13F4[][5][3];
extern const u8 *gUnknown_086B11CC[][4];
extern const u8 *gUnknown_086B1300[][4];
extern const u8 *gUnknown_086B1124[][7][2];
extern const u8 *gUnknown_086B0F4C[][4];
extern const u8 *gUnknown_086B1104[][2];
extern const u16 gUnknown_086B0E60[];
extern const u8 *gUnknown_086B108C[][3][5];
extern const u8 *gUnknown_086B0E9C[][4];
extern const u8 *gUnknown_086B0D6C[][5][3];
extern const u8 *gUnknown_086B0C04[][5][3];
extern const u8 *gUnknown_086B0CB8[][5][3];
extern const s16 gUnknown_086B08C4[];


void UpdateSapphireArrowLightProgress(void)
{
    if (gCurrentPinballGame->scoreMultiplierLevel > 0)
    {
        if (gCurrentPinballGame->scoreMultiplierDecayTimer < gUnknown_086B08C4[gCurrentPinballGame->scoreMultiplierLevel - 1])
        {
            gCurrentPinballGame->scoreMultiplierDecayTimer++;
        }
        else
        {
            gCurrentPinballGame->scoreMultiplierDecayTimer = 0;
            gCurrentPinballGame->scoreMultiplierLevel--;
        }
    }
}

void RenderSapphireUpperLaneArrows(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->scoreMultiplierLevel == 0)
    {
        sp0[0] = gCurrentPinballGame->spriteToggleFrame * 2;
        sp0[1] = gCurrentPinballGame->spriteToggleFrame;
        sp0[2] = 0;
    }
    else if (gCurrentPinballGame->scoreMultiplierLevel == 1)
    {
        sp0[0] = 3;
        sp0[1] = gCurrentPinballGame->spriteToggleFrame + 1;
        sp0[2] = gCurrentPinballGame->spriteToggleFrame * 2;
    }
    else if (gCurrentPinballGame->scoreMultiplierLevel == 2)
    {
        sp0[0] = 3;
        sp0[1] = 3;
        sp0[2] = gCurrentPinballGame->spriteToggleFrame + 2;
    }
    else
    {
        sp0[0] = 3;
        sp0[1] = 3;
        sp0[2] = 3;
    }

    src = gUnknown_086B0CB8[0][sp0[0]];
    dest = gUnknown_086B0CB8[0][4];
    if (gCurrentPinballGame->viewportBottomYPrev >= 42 && gCurrentPinballGame->viewportBottomYPrev < 208)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev >= 50 && gCurrentPinballGame->viewportBottomYPrev < 216)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    src = gUnknown_086B0CB8[1][sp0[1]];
    dest = gUnknown_086B0CB8[1][4];
    if (gCurrentPinballGame->viewportBottomYPrev >= 58 && gCurrentPinballGame->viewportBottomYPrev < 224)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev >= 66 && gCurrentPinballGame->viewportBottomYPrev < 232)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    src = gUnknown_086B0CB8[2][sp0[2]];
    dest = gUnknown_086B0CB8[2][4];
    if (gCurrentPinballGame->viewportBottomYPrev >= 74 && gCurrentPinballGame->viewportBottomYPrev < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev >= 82 && gCurrentPinballGame->viewportBottomYPrev < 248)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev >= 90)
    {
        DmaCopy16(3, src[2], dest[2], 0x60);
    }
}

void RenderSapphireLeftEvoArrows(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->savedEvoHitCount == 0)
        {
            sp0[0] = gCurrentPinballGame->spriteToggleFrame * 2;
            sp0[1] = 0;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->savedEvoHitCount == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->spriteToggleFrame + 1;
            sp0[2] = gCurrentPinballGame->spriteToggleFrame * 2;
        }
        else if (gCurrentPinballGame->savedEvoHitCount == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = gCurrentPinballGame->spriteToggleFrame + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->prevCatchArrowGfxState[0];
        sp0[1] = gCurrentPinballGame->prevCatchArrowGfxState[1];
        sp0[2] = gCurrentPinballGame->prevCatchArrowGfxState[2];
    }

    src = gUnknown_086B0C04[0][sp0[0]];
    dest = gUnknown_086B0C04[0][4];
    if (gCurrentPinballGame->viewportBottomYPrev < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->viewportBottomYPrev > 120)
    {
        src = gUnknown_086B0C04[1][sp0[1]];
        dest = gUnknown_086B0C04[1][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 136)
    {
        src = gUnknown_086B0C04[2][sp0[2]];
        dest = gUnknown_086B0C04[2][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }
}

void RenderSapphireLeftCatchArrows(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->savedCatchArrows == 0)
        {
            sp0[0] = gCurrentPinballGame->spriteToggleFrame * 2;
            sp0[1] = 0;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->savedCatchArrows == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->spriteToggleFrame + 1;
            sp0[2] = gCurrentPinballGame->spriteToggleFrame * 2;
        }
        else if (gCurrentPinballGame->savedCatchArrows == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = (s16) gCurrentPinballGame->spriteToggleFrame + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->catchArrowGfxState[0];
        sp0[1] = gCurrentPinballGame->catchArrowGfxState[1];
        sp0[2] = gCurrentPinballGame->catchArrowGfxState[2];
    }

    src = gUnknown_086B0D6C[0][sp0[0]];
    dest = gUnknown_086B0D6C[0][4];
    if (gCurrentPinballGame->viewportBottomYPrev < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->viewportBottomYPrev > 120)
    {
        src = gUnknown_086B0D6C[1][sp0[1]];
        dest = gUnknown_086B0D6C[1][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 136)
    {
        src = gUnknown_086B0D6C[2][sp0[2]];
        dest = gUnknown_086B0D6C[2][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }
}

void RenderBoardDynamicEntities(void)
{

    gCurrentPinballGame->spriteToggleFrame = (gCurrentPinballGame->renderAnimCounter % 40) / 20;
    gCurrentPinballGame->renderAnimCounter++;
    RenderSapphireTargetHitIndicators();
    if (gCurrentPinballGame->viewportBottomYPrev > 83)
        RenderSapphireLeftLoopFlasher();

    if (gCurrentPinballGame->viewportBottomYPrev > 18)
        RenderSapphireRightLoopFlasher();

    if (gCurrentPinballGame->viewportBottomYPrev >= 56 && gCurrentPinballGame->viewportBottomYPrev < 243)
        RenderSapphireTrapIndicator();

    UpdateBallPowerUpAnimation();
    if (gCurrentPinballGame->viewportBottomYPrev < 112)
        RenderSapphireBallPowerUpLights();

    if (gCurrentPinballGame->viewportBottomYPrev >= 64 && gCurrentPinballGame->viewportBottomYPrev < 254)
        RenderSapphireCatchReadyFlasher();

    if (gCurrentPinballGame->viewportBottomYPrev >= 27 && gCurrentPinballGame->viewportBottomYPrev < 211)
    {
        RenderSapphireAnimatedDecoration();
        RenderSapphireTimerDigits();
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 104)
    {
        RenderSapphireRightEvoArrows();
        RenderSapphireRightCatchArrows();
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 72)
        RenderSapphireRightLaneArrows();

    UpdateSapphireArrowLightProgress();
    if (gCurrentPinballGame->viewportBottomYPrev > 110)
        RenderSapphireBallVariantTiles();

    if (gCurrentPinballGame->viewportBottomYPrev > 178)
    {
        RenderSapphireBumperHitTiles();
        RenderSapphireHoleIndicatorTiles();
        RenderSapphireSlingshotBumper();
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 202)
        RenderSapphireBallSaverIndicator();

    if (gCurrentPinballGame->viewportBottomYPrev >= 8 && gCurrentPinballGame->viewportBottomYPrev < 182)
        RenderSapphireBumperBonusFlasher();

    if (gCurrentPinballGame->modeTimerFrames && gCurrentPinballGame->boardEntryMode == 0)
        gCurrentPinballGame->modeTimerFrames--;
}

void RenderSapphireTimerDigits(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = gCurrentPinballGame->bonusMultiplier / 10;
    var1 = gCurrentPinballGame->bonusMultiplier % 10;
    if (gCurrentPinballGame->viewportBottomYPrev > 36)
    {
        src = gUnknown_086B0E9C[var0];
        dest = gUnknown_086B0E9C[10];
        DmaCopy16(3, src[0], dest[0], 0x20);
        DmaCopy16(3, src[1], dest[1], 0x20);

        src = gUnknown_086B0E9C[var1];
        DmaCopy16(3, src[2], dest[2], 0x20);
        DmaCopy16(3, src[3], dest[3], 0x20);
    }
}

void RenderSapphireSlingshotBumper(void)
{
    s16 var0;
    const u8 **src;
    const u8 **dest;

    var0 = gUnknown_086B0E60[gCurrentPinballGame->slingshotHitAnimTimer];
    if (gCurrentPinballGame->slingshotHitAnimTimer)
    {
        gCurrentPinballGame->slingshotHitAnimTimer--;
        if (gCurrentPinballGame->slingshotHitAnimTimer == 3)
        {
            m4aSongNumStart(SE_SLINGSHOT_HIT);
            gCurrentPinballGame->scoreAddedInFrame = 500;
            PlayRumble(7);
        }
    }

    src = gUnknown_086B108C[gCurrentPinballGame->slingshotSide][var0];
    dest = gUnknown_086B108C[gCurrentPinballGame->slingshotSide][2];
    DmaCopy16(3, src[0], dest[0], 0x20);
    DmaCopy16(3, src[1], dest[1], 0x40);
    DmaCopy16(3, src[2], dest[2], 0x60);
    DmaCopy16(3, src[3], dest[3], 0x60);
    DmaCopy16(3, src[4], dest[4], 0x40);
}

void RenderSapphireBallVariantTiles(void)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B1104[gCurrentPinballGame->ballSpriteVariant];
    dest = gUnknown_086B1104[3];
    DmaCopy16(3, src[0], dest[0], 0x40);
    DmaCopy16(3, src[1], dest[1], 0x40);
}

void RenderSapphireAnimatedDecoration(void)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B0F4C[(gMain.systemFrameCount % 64) / 16];
    dest = gUnknown_086B0F4C[4];
    if (gCurrentPinballGame->viewportBottomYPrev < 192)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->viewportBottomYPrev < 200)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->viewportBottomYPrev < 208)
    {
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    DmaCopy16(3, src[3], dest[3], 0x60);
}

void RenderSapphireBumperHitTiles(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->bumperFlashAnimTimer)
    {
        gCurrentPinballGame->bumperHitTimers[gCurrentPinballGame->bumperFlashTargetA] = 1 - (gCurrentPinballGame->bumperFlashAnimTimer % 36) / 18;
        gCurrentPinballGame->bumperHitTimers[gCurrentPinballGame->bumperFlashTargetB] = gCurrentPinballGame->bumperHitTimers[gCurrentPinballGame->bumperFlashTargetA];
        gCurrentPinballGame->bumperFlashAnimTimer--;
    }

    for (i = 0; i < 3; i++)
    {
        src = gUnknown_086B1124[i][gCurrentPinballGame->bumperHitTimers[i]];
        dest = gUnknown_086B1124[i][6];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
    }
}

void RenderSapphireHoleIndicatorTiles(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->allHolesCompleted)
    {
        if (gCurrentPinballGame->holeCompletionFlashTimer)
        {
            gCurrentPinballGame->holeIndicators[0] = (gCurrentPinballGame->holeCompletionFlashTimer % 36) / 18;
            gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeCompletionFlashTimer--;
        }
        else
        {
            gCurrentPinballGame->holeIndicators[0] = 1;
            gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        }
    }

    for (i = 0; i < 4; i++)
    {
        src = &gUnknown_086B1300[i][gCurrentPinballGame->holeIndicators[i]];
        dest = &gUnknown_086B1300[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void RenderSapphireBallSaverIndicator(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->modeTimerFrames > 300)
    {
        gCurrentPinballGame->timerIndicatorVisible = 1;
    }
    else if (gCurrentPinballGame->modeTimerFrames)
    {
        if (gCurrentPinballGame->boardEntryMode)
            gCurrentPinballGame->timerIndicatorVisible = 1;
        else
            gCurrentPinballGame->timerIndicatorVisible = (gMain.fieldFrameCount & 0xF) / 8;
    }
    else
    {
        gCurrentPinballGame->timerIndicatorVisible = 0;
    }

    src = gUnknown_086B11CC[gCurrentPinballGame->timerIndicatorVisible];
    dest = gUnknown_086B11CC[2];
    DmaCopy16(3, src[0], dest[0], 0xE0);
    DmaCopy16(3, src[1], dest[1], 0xE0);
    if (gCurrentPinballGame->viewportBottomYPrev > 215)
    {
        DmaCopy16(3, src[2], dest[2], 0xC0);
        DmaCopy16(3, src[3], dest[3], 0x40);
    }
}

void RenderSapphireRightLaneArrows(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->scoreMultiplierLevel == 0)
    {
        sp0[0] = gCurrentPinballGame->spriteToggleFrame;
        sp0[1] = 0;
        sp0[2] = 0;
    }
    else if (gCurrentPinballGame->scoreMultiplierLevel == 1)
    {
        sp0[0] = 1;
        sp0[1] = gCurrentPinballGame->spriteToggleFrame;
        sp0[2] = gCurrentPinballGame->spriteToggleFrame;
    }
    else if (gCurrentPinballGame->scoreMultiplierLevel == 2)
    {
        sp0[0] = 2;
        sp0[1] = 2;
        sp0[2] = gCurrentPinballGame->spriteToggleFrame + 1;
    }
    else
    {
        sp0[0] = 2;
        sp0[1] = 2;
        sp0[2] = 2;
    }

    src = gUnknown_086B13F4[0][sp0[0]];
    dest = gUnknown_086B13F4[0][3];
    if (gCurrentPinballGame->viewportBottomYPrev < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->viewportBottomYPrev < 248)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 88)
    {
        src = gUnknown_086B13F4[1][sp0[1]];
        dest = gUnknown_086B13F4[1][3];
        if (gCurrentPinballGame->viewportBottomYPrev < 254)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }
        if (gCurrentPinballGame->viewportBottomYPrev < 262)
        {
            DmaCopy16(3, src[1], dest[1], 0x40);
        }
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 96)
    {
        src = gUnknown_086B13F4[2][sp0[2]];
        dest = gUnknown_086B13F4[2][3];
        if (gCurrentPinballGame->viewportBottomYPrev < 264)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }

        DmaCopy16(3, src[1], dest[1], 0x40);
        if (gCurrentPinballGame->viewportBottomYPrev > 104)
        {
            DmaCopy16(3, src[2], dest[2], 0x40);
        }
    }
}

void RenderSapphireLeftLoopFlasher(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->catchModeBlinkActive > 0)
        index = 1 - gCurrentPinballGame->spriteToggleFrame;

    src = gUnknown_086B11FC[index];
    dest = gUnknown_086B11FC[2];
    if (gCurrentPinballGame->viewportBottomYPrev < 256)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->viewportBottomYPrev >= 97 && gCurrentPinballGame->viewportBottomYPrev < 264)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 0x67)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void RenderSapphireRightLoopFlasher(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->hatchModeBlinkActive > 0)
        index = 1 - gCurrentPinballGame->spriteToggleFrame;

    src = gUnknown_086B122C[index];
    dest = gUnknown_086B122C[2];
    if (gCurrentPinballGame->viewportBottomYPrev < 195)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 30)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 38)
    {
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void RenderSapphireRightEvoArrows(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->savedEvoHitCount == 0)
        {
            sp0[0] = gCurrentPinballGame->spriteToggleFrame * 2;
            sp0[1] = gCurrentPinballGame->spriteToggleFrame;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->savedEvoHitCount == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->spriteToggleFrame + 1;
            sp0[2] = gCurrentPinballGame->spriteToggleFrame * 2;
        }
        else if (gCurrentPinballGame->savedEvoHitCount == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = gCurrentPinballGame->spriteToggleFrame + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->prevCatchArrowGfxState[0];
        sp0[1] = gCurrentPinballGame->prevCatchArrowGfxState[1];
        sp0[2] = gCurrentPinballGame->prevCatchArrowGfxState[2];
    }


    src = gUnknown_086B1340[0][sp0[0]];
    dest = gUnknown_086B1340[0][4];
    if (gCurrentPinballGame->viewportBottomYPrev < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }
    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->viewportBottomYPrev > 120)
    {
        src = gUnknown_086B1340[1][sp0[1]];
        dest = gUnknown_086B1340[1][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 136) {
        src = gUnknown_086B1340[2][sp0[2]];
        dest = gUnknown_086B1340[2][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x40);
    }
}

void RenderSapphireRightCatchArrows(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->savedCatchArrows == 0)
        {
            sp0[0] = gCurrentPinballGame->spriteToggleFrame * 2;
            sp0[1] = 0;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->savedCatchArrows == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->spriteToggleFrame + 1;
            sp0[2] = gCurrentPinballGame->spriteToggleFrame * 2;
        }
        else if (gCurrentPinballGame->savedCatchArrows == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = (s16) gCurrentPinballGame->spriteToggleFrame + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->catchArrowGfxState[0];
        sp0[1] = gCurrentPinballGame->catchArrowGfxState[1];
        sp0[2] = gCurrentPinballGame->catchArrowGfxState[2];
    }

    src = gUnknown_086B14A8[0][sp0[0]];
    dest = gUnknown_086B14A8[0][4];
    if (gCurrentPinballGame->viewportBottomYPrev < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->viewportBottomYPrev > 120)
    {
        src = gUnknown_086B14A8[1][sp0[1]];
        dest = gUnknown_086B14A8[1][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 136)
    {
        src = gUnknown_086B14A8[2][sp0[2]];
        dest = gUnknown_086B14A8[2][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x40);
    }
}

void RenderSapphireCatchReadyFlasher(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    gCurrentPinballGame->catchArrowIndicatorBlink = 0;
    if (gCurrentPinballGame->savedCatchArrows > 1 && gCurrentPinballGame->boardState < 3)
        gCurrentPinballGame->catchArrowIndicatorBlink = 1;

    if (gCurrentPinballGame->catchArrowIndicatorBlink > 0)
        index = 1 - gCurrentPinballGame->spriteToggleFrame;


    src = gUnknown_086B12D0[index];
    dest = gUnknown_086B12D0[2];
    if (gCurrentPinballGame->viewportBottomYPrev < 232)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->viewportBottomYPrev < 240)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->viewportBottomYPrev >= 80)
    {
        if (gCurrentPinballGame->viewportBottomYPrev < 248)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void RenderSapphireTrapIndicator(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->trapDoorGfxState == 3)
        gCurrentPinballGame->trapDisplayBlinkActive = 1;
    else if (gCurrentPinballGame->boardState)
        gCurrentPinballGame->trapDisplayBlinkActive = 0;

    if (gCurrentPinballGame->trapDisplayBlinkActive > 0)
        index = gCurrentPinballGame->trapDisplayState * 2 + 1 - gCurrentPinballGame->spriteToggleFrame;
    else
        index = gCurrentPinballGame->trapDisplayState * 2;


    src = gUnknown_086B125C[index];
    dest = gUnknown_086B125C[4];
    if (gCurrentPinballGame->viewportBottomYPrev < 224)
    {
        DmaCopy16(3, src[0], dest[0], 0x80);
    }

    if (gCurrentPinballGame->viewportBottomYPrev < 232)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 71)
    {
        if (gCurrentPinballGame->viewportBottomYPrev < 240)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void RenderSapphireBallPowerUpLights(void)
{
    s16 i;

    for (i = 0; i < 3; i++)
    {
        const u8 **src = &gUnknown_086B12AC[i][gCurrentPinballGame->ballPowerUpLight[i]];
        const u8 **dest = &gUnknown_086B12AC[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void RenderSapphireTargetHitIndicators(void)
{
    s16 i;
    s16 srcIndex;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->cyndaquilAnimPhase != 3)
    {
        for (i = 0; i < 10; i++)
        {
            if (gCurrentPinballGame->edgeTargetFlashTimers[i] > 0)
            {
                if (gCurrentPinballGame->edgeTargetFlashTimers[i] == 10)
                    m4aSongNumStart(SE_UNKNOWN_0xDC);

                gCurrentPinballGame->edgeTargetFlashTimers[i]--;
                srcIndex = 1;
            }
            else
            {
                srcIndex = 0;
            }

            src = gUnknown_086B0F9C[i][srcIndex];
            dest = gUnknown_086B0F9C[i][2];
            DmaCopy16(3, src[0], dest[0], 0x40);
            DmaCopy16(3, src[1], dest[1], 0x40);
        }
    }
}

void RenderSapphireBumperBonusFlasher(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->bumperHitsSinceReset >= 100)
        index = (gCurrentPinballGame->renderAnimCounter % 20) / 4;

    src = gUnknown_086B0E6C[index];
    dest = gUnknown_086B0E6C[5];
    if (gCurrentPinballGame->viewportBottomYPrev < 176)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    DmaCopy16(3, src[1], dest[1], 0x40);
}
