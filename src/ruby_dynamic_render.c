#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 *gUnknown_086B0B70[][3];
extern const u16 gUnknown_086B0E20[];
extern const u8 *gUnknown_086B0B94[][4];
extern const u8 *gUnknown_086B0B20[][4];
extern const u8 *gUnknown_086B0AF0[][4];
extern const u8 *gUnknown_086B0AC0[][4];
extern const u8 *gUnknown_086B0A90[][4];
extern const u8 *gUnknown_086B0BC4[][4];
extern const u8 *gUnknown_086B09E8[][7][2];
extern const u8 *gUnknown_086B09C8[][2];
extern const u8 *gUnknown_086B0970[][2];
extern const u8 *gUnknown_086B094C[][3];
extern const s16 gUnknown_086B08CA[];
extern const u8 *gUnknown_086B08D4[][3][5];

extern struct SongHeader se_unk_87;


void RenderRubyBoardDynamicEntities(void)
{
    gCurrentPinballGame->spriteToggleFrame = (gCurrentPinballGame->renderAnimCounter % 40) / 20;
    gCurrentPinballGame->renderAnimCounter++;
    RenderRubyTimerDigits();
    if (gCurrentPinballGame->viewportBottomYPrev < 232)
    {
        RenderRubyLeftLoopFlasher();
        RenderRubyRightLoopFlasher();
    }

    if (gCurrentPinballGame->viewportBottomYPrev >= 81 && gCurrentPinballGame->viewportBottomYPrev < 248)
        RenderRubyTrapIndicator();

    UpdateBallPowerUpAnimation();
    if (gCurrentPinballGame->viewportBottomYPrev < 112)
        RenderRubyBallPowerUpLights();

    if (gCurrentPinballGame->viewportBottomYPrev > 112)
        RenderRubyCatchReadyFlasher();

    if (gCurrentPinballGame->viewportBottomYPrev > 104)
    {
        RenderSapphireLeftEvoArrows();
        RenderSapphireLeftCatchArrows();
    }

    if (gCurrentPinballGame->viewportBottomYPrev < 256)
        RenderSapphireUpperLaneArrows();

    UpdateSapphireArrowLightProgress();
    if (gCurrentPinballGame->viewportBottomYPrev > 110)
        RenderRubyBallVariantTiles();

    if (gCurrentPinballGame->viewportBottomYPrev > 178)
    {
        RenderRubyBumperHitTiles();
        RenderRubyHoleIndicatorTiles();
        RenderRubySlingshotBumper();
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 202)
        RenderRubyBallSaverIndicator();

    if (gCurrentPinballGame->modeTimerFrames && gCurrentPinballGame->boardEntryMode == 0)
        gCurrentPinballGame->modeTimerFrames--;
}

void RenderRubySlingshotBumper(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = gUnknown_086B08CA[gCurrentPinballGame->slingshotHitAnimTimer];
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

    src = gUnknown_086B08D4[gCurrentPinballGame->slingshotSide][index];
    dest = gUnknown_086B08D4[gCurrentPinballGame->slingshotSide][2];
    DmaCopy16(3, src[0], dest[0], 0x20);
    DmaCopy16(3, src[1], dest[1], 0x40);
    DmaCopy16(3, src[2], dest[2], 0x60);
    DmaCopy16(3, src[3], dest[3], 0x60);
    DmaCopy16(3, src[4], dest[4], 0x40);
}

void CopyRubyTrapGfxToVram(s16 arg0)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B094C[arg0];
    dest = gUnknown_086B094C[2];
    DmaCopy16(3, src[0], dest[0], 0xC0);
    DmaCopy16(3, src[1], dest[1], 0xC0);
    DmaCopy16(3, src[2], dest[2], 0x20);
}

void RenderRubyTimerDigits(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = gCurrentPinballGame->bonusMultiplier / 10;
    var1 = gCurrentPinballGame->bonusMultiplier % 10;
    src = gUnknown_086B0970[var0];
    dest = gUnknown_086B0970[10];
    DmaCopy16(3, src[0], dest[0], 0x20);

    src = gUnknown_086B0970[var1];
    DmaCopy16(3, src[1], dest[1], 0x20);
}

void RenderRubyBallVariantTiles(void)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B09C8[gCurrentPinballGame->ballSpriteVariant];
    dest = gUnknown_086B09C8[3];
    DmaCopy16(3, src[0], dest[0], 0x40);
    DmaCopy16(3, src[1], dest[1], 0x40);
}

void RenderRubyBumperHitTiles(void)
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
        src = gUnknown_086B09E8[i][gCurrentPinballGame->bumperHitTimers[i]];
        dest = gUnknown_086B09E8[i][6];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
    }
}

void RenderRubyHoleIndicatorTiles(void)
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
        src = &gUnknown_086B0BC4[i][gCurrentPinballGame->holeIndicators[i]];
        dest = &gUnknown_086B0BC4[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void RenderRubyBallSaverIndicator(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->modeTimerFrames > 300)
    {
        gCurrentPinballGame->timerIndicatorVisible = 1;
    }
    else
    {
        if (gCurrentPinballGame->modeTimerFrames)
        {
            if (gCurrentPinballGame->boardEntryMode)
                gCurrentPinballGame->timerIndicatorVisible = 1;
            else
                gCurrentPinballGame->timerIndicatorVisible = (gMain.fieldFrameCount % 16) / 8;
        }
        else
        {
            gCurrentPinballGame->timerIndicatorVisible = 0;
        }
    }

    src = gUnknown_086B0A90[gCurrentPinballGame->timerIndicatorVisible];
    dest = gUnknown_086B0A90[2];
    DmaCopy16(3, src[0], dest[0], 0xC0);
    DmaCopy16(3, src[1], dest[1], 0xC0);
    if (gCurrentPinballGame->viewportBottomYPrev >= 216)
    {
        DmaCopy16(3, src[2], dest[2], 0xA0);
        DmaCopy16(3, src[3], dest[3], 0x40);
    }
}

void RenderRubyLeftLoopFlasher(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->catchModeBlinkActive > 0)
        index = 1 - gCurrentPinballGame->spriteToggleFrame;

    src = gUnknown_086B0AC0[index];
    dest = gUnknown_086B0AC0[2];
    if (gCurrentPinballGame->viewportBottomYPrev > 48)
    {
        if (gCurrentPinballGame->viewportBottomYPrev < 216)
        {
            DmaCopy16(3, src[0], dest[0], 0x80);
        }

        if (gCurrentPinballGame->viewportBottomYPrev < 224)
        {
            DmaCopy16(3, src[1], dest[1], 0x80);
        }
    }
    if (gCurrentPinballGame->viewportBottomYPrev > 64)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void RenderRubyRightLoopFlasher(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->hatchModeBlinkActive > 0)
        index = 1 - gCurrentPinballGame->spriteToggleFrame;

    src = gUnknown_086B0AF0[index];
    dest = gUnknown_086B0AF0[2];
    if (gCurrentPinballGame->viewportBottomYPrev > 40)
    {
        if (gCurrentPinballGame->viewportBottomYPrev < 208)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }

        if (gCurrentPinballGame->viewportBottomYPrev < 216)
        {
            DmaCopy16(3, src[1], dest[1], 0x80);
        }
    }

    if (gCurrentPinballGame->viewportBottomYPrev > 56)
    {
        if (gCurrentPinballGame->viewportBottomYPrev < 224)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void RenderRubyTrapIndicator(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->shopDoorTargetFrame > 2)
        gCurrentPinballGame->trapDisplayBlinkActive = 1;
    else if (gCurrentPinballGame->boardState)
        gCurrentPinballGame->trapDisplayBlinkActive = 0;

    if (gCurrentPinballGame->trapDisplayBlinkActive > 0)
        index = gCurrentPinballGame->trapDisplayState * 2 + 1 - gCurrentPinballGame->spriteToggleFrame;
    else
        index = gCurrentPinballGame->trapDisplayState * 2;

    src = gUnknown_086B0B20[index];
    dest = gUnknown_086B0B20[4];
    if (gCurrentPinballGame->viewportBottomYPrev < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0xA0);
    }

    DmaCopy16(3, src[1], dest[1], 0xA0);
    DmaCopy16(3, src[2], dest[2], 0xA0);
    if (gCurrentPinballGame->viewportBottomYPrev > 88)
    {
        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void RenderRubyCatchReadyFlasher(void)
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

    src = gUnknown_086B0B94[index];
    dest = gUnknown_086B0B94[2];
    if (gCurrentPinballGame->viewportBottomYPrev < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }
    DmaCopy16(3, src[1], dest[1], 0x80);
    DmaCopy16(3, src[2], dest[2], 0x80);
    DmaCopy16(3, src[3], dest[3], 0x80);
}

void UpdateBallPowerUpAnimation(void)
{
    if (gCurrentPinballGame->ballUpgradeTriggered == 0)
        return;

    if (gCurrentPinballGame->ballUpgradeAnimTimer)
    {
        if (gCurrentPinballGame->rampUpgradeFromPrize == 0)
        {
            gCurrentPinballGame->ballPowerUpLight[0] = (gMain.fieldFrameCount % 20) / 10;
            gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
            gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
        }

        if (gCurrentPinballGame->ballUpgradeAnimTimer == 28)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }

        if (gCurrentPinballGame->ballUpgradeAnimTimer == 40)
        MPlayStart(&gMPlayInfo_SE1, &se_unk_87);

        if (gCurrentPinballGame->ballUpgradeAnimTimer == 60)
            gMain.boardSpriteGroups[43]->available = 1;

        gCurrentPinballGame->ballUpgradeGfxFrame = gUnknown_086B0E20[30 - gCurrentPinballGame->ballUpgradeAnimTimer / 2];
        gCurrentPinballGame->ballUpgradeAnimTimer--;
    }
    else
    {
        gCurrentPinballGame->ballUpgradeTriggered = 0;
        if (gCurrentPinballGame->rampUpgradeFromPrize == 0)
        {
            gCurrentPinballGame->ballPowerUpLight[0] =
                gCurrentPinballGame->ballPowerUpLight[1] =
                gCurrentPinballGame->ballPowerUpLight[2] = 0;
        }

        gCurrentPinballGame->rampUpgradeFromPrize = 0;
    }
}

void RenderRubyBallPowerUpLights(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    for (i = 0; i < 3; i++) {
        src = &gUnknown_086B0B70[i][gCurrentPinballGame->ballPowerUpLight[i]];
        dest = &gUnknown_086B0B70[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}
