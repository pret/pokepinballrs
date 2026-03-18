#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 *gRubyBallPowerUpLightTilePointers[][3];
extern const u16 gBallShadowTileIndices[];
extern const u8 *gRubyCatchProgressArrowTilePointers[][4];
extern const u8 *gRubyRouletteSlotTilePointers[][4];
extern const u8 *gRubyEvoArrowTilePointers[][4];
extern const u8 *gRubyCatchArrowTilePointers[][4];
extern const u8 *gRubyModeTimerTilePointers[][4];
extern const u8 *gRubyHoleIndicatorTilePointers[][4];
extern const u8 *gRubyCatchLightTilePointers[][7][2];
extern const u8 *gRubyTrapIndicatorTilePointers[][2];
extern const u8 *gRubyProgressDigitTilePointers[][2];
extern const u8 *gShopItemTilePointers[][3];
extern const s16 gRubySlingshotAnimIndices[];
extern const u8 *gRubySlingshotTilePointers[][3][5];

extern struct SongHeader se_ball_upgrade;


void UpdateRubyBoardAnimations(void)
{
    gCurrentPinballGame->hudBlinkPhase = (gCurrentPinballGame->hudAnimFrameCounter % 40) / 20;
    gCurrentPinballGame->hudAnimFrameCounter++;
    DrawRubyProgressDigits();
    if (gCurrentPinballGame->hudSpriteBaseY < 232)
    {
        AnimateRubyCatchArrow();
        AnimateRubyEvoArrow();
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 81 && gCurrentPinballGame->hudSpriteBaseY < 248)
        AnimateRubyRouletteSlot();

    AnimateRubyBallPowerUpSequence();
    if (gCurrentPinballGame->hudSpriteBaseY < 112)
        DrawRubyBallPowerUpLights();

    if (gCurrentPinballGame->hudSpriteBaseY > 112)
        AnimateRubyCatchProgressArrow();

    if (gCurrentPinballGame->hudSpriteBaseY > 104)
    {
        DrawEvoArrowProgress();
        DrawCatchArrowProgress();
    }

    if (gCurrentPinballGame->hudSpriteBaseY < 256)
        DrawCoinRewardMeter();

    UpdateCoinRewardTimer();
    if (gCurrentPinballGame->hudSpriteBaseY > 110)
        AnimateRubyTrapIndicator();

    if (gCurrentPinballGame->hudSpriteBaseY > 178)
    {
        AnimateRubyCatchLightBlink();
        AnimateRubyHoleIndicators();
        AnimateRubySlingshotTimer();
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 202)
        DrawRubyModeTimerDisplay();

    if (gCurrentPinballGame->saverTimeRemaining && gCurrentPinballGame->ballCatchState == 0)
        gCurrentPinballGame->saverTimeRemaining--;
}

void AnimateRubySlingshotTimer(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = gRubySlingshotAnimIndices[gCurrentPinballGame->slingshotHitAnimTimer];
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

    src = gRubySlingshotTilePointers[gCurrentPinballGame->slingshotSideIndex][index];
    dest = gRubySlingshotTilePointers[gCurrentPinballGame->slingshotSideIndex][2];
    DmaCopy16(3, src[0], dest[0], 0x20);
    DmaCopy16(3, src[1], dest[1], 0x40);
    DmaCopy16(3, src[2], dest[2], 0x60);
    DmaCopy16(3, src[3], dest[3], 0x60);
    DmaCopy16(3, src[4], dest[4], 0x40);
}

void LoadShopItemGraphics(s16 arg0)
{
    const u8 **src;
    const u8 **dest;

    src = gShopItemTilePointers[arg0];
    dest = gShopItemTilePointers[2];
    DmaCopy16(3, src[0], dest[0], 0xC0);
    DmaCopy16(3, src[1], dest[1], 0xC0);
    DmaCopy16(3, src[2], dest[2], 0x20);
}

void DrawRubyProgressDigits(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = gCurrentPinballGame->progressLevel / 10;
    var1 = gCurrentPinballGame->progressLevel % 10;
    src = gRubyProgressDigitTilePointers[var0];
    dest = gRubyProgressDigitTilePointers[10];
    DmaCopy16(3, src[0], dest[0], 0x20);

    src = gRubyProgressDigitTilePointers[var1];
    DmaCopy16(3, src[1], dest[1], 0x20);
}

void AnimateRubyTrapIndicator(void)
{
    const u8 **src;
    const u8 **dest;

    src = gRubyTrapIndicatorTilePointers[gCurrentPinballGame->trapAnimState];
    dest = gRubyTrapIndicatorTilePointers[3];
    DmaCopy16(3, src[0], dest[0], 0x40);
    DmaCopy16(3, src[1], dest[1], 0x40);
}

void AnimateRubyCatchLightBlink(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->evoBlinkTimer)
    {
        gCurrentPinballGame->catchLights[gCurrentPinballGame->evoCatchLightSlot1] = 1 - (gCurrentPinballGame->evoBlinkTimer % 36) / 18;
        gCurrentPinballGame->catchLights[gCurrentPinballGame->evoCatchLightSlot2] = gCurrentPinballGame->catchLights[gCurrentPinballGame->evoCatchLightSlot1];
        gCurrentPinballGame->evoBlinkTimer--;
    }

    for (i = 0; i < 3; i++)
    {
        src = gRubyCatchLightTilePointers[i][gCurrentPinballGame->catchLights[i]];
        dest = gRubyCatchLightTilePointers[i][6];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
    }
}

void AnimateRubyHoleIndicators(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->allHolesLit)
    {
        if (gCurrentPinballGame->allHolesLitBlinkTimer)
        {
            gCurrentPinballGame->holeIndicators[0] = (gCurrentPinballGame->allHolesLitBlinkTimer % 36) / 18;
            gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->allHolesLitBlinkTimer--;
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
        src = &gRubyHoleIndicatorTilePointers[i][gCurrentPinballGame->holeIndicators[i]];
        dest = &gRubyHoleIndicatorTilePointers[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void DrawRubyModeTimerDisplay(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->saverTimeRemaining > 300)
    {
        gCurrentPinballGame->saverLit = 1;
    }
    else
    {
        if (gCurrentPinballGame->saverTimeRemaining)
        {
            if (gCurrentPinballGame->ballCatchState)
                gCurrentPinballGame->saverLit = 1;
            else
                gCurrentPinballGame->saverLit = (gMain.fieldFrameCount % 16) / 8;
        }
        else
        {
            gCurrentPinballGame->saverLit = 0;
        }
    }

    src = gRubyModeTimerTilePointers[gCurrentPinballGame->saverLit];
    dest = gRubyModeTimerTilePointers[2];
    DmaCopy16(3, src[0], dest[0], 0xC0);
    DmaCopy16(3, src[1], dest[1], 0xC0);
    if (gCurrentPinballGame->hudSpriteBaseY >= 216)
    {
        DmaCopy16(3, src[2], dest[2], 0xA0);
        DmaCopy16(3, src[3], dest[3], 0x40);
    }
}

void AnimateRubyCatchArrow(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->catchArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    src = gRubyCatchArrowTilePointers[index];
    dest = gRubyCatchArrowTilePointers[2];
    if (gCurrentPinballGame->hudSpriteBaseY > 48)
    {
        if (gCurrentPinballGame->hudSpriteBaseY < 216)
        {
            DmaCopy16(3, src[0], dest[0], 0x80);
        }

        if (gCurrentPinballGame->hudSpriteBaseY < 224)
        {
            DmaCopy16(3, src[1], dest[1], 0x80);
        }
    }
    if (gCurrentPinballGame->hudSpriteBaseY > 64)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void AnimateRubyEvoArrow(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->evoArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    src = gRubyEvoArrowTilePointers[index];
    dest = gRubyEvoArrowTilePointers[2];
    if (gCurrentPinballGame->hudSpriteBaseY > 40)
    {
        if (gCurrentPinballGame->hudSpriteBaseY < 208)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }

        if (gCurrentPinballGame->hudSpriteBaseY < 216)
        {
            DmaCopy16(3, src[1], dest[1], 0x80);
        }
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 56)
    {
        if (gCurrentPinballGame->hudSpriteBaseY < 224)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void AnimateRubyRouletteSlot(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->shopDoorTargetFrame > 2)
        gCurrentPinballGame->rouletteSlotActive = 1;
    else if (gCurrentPinballGame->boardState)
        gCurrentPinballGame->rouletteSlotActive = 0;

    if (gCurrentPinballGame->rouletteSlotActive > 0)
        index = gCurrentPinballGame->evolutionShopActive * 2 + 1 - gCurrentPinballGame->hudBlinkPhase;
    else
        index = gCurrentPinballGame->evolutionShopActive * 2;

    src = gRubyRouletteSlotTilePointers[index];
    dest = gRubyRouletteSlotTilePointers[4];
    if (gCurrentPinballGame->hudSpriteBaseY < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0xA0);
    }

    DmaCopy16(3, src[1], dest[1], 0xA0);
    DmaCopy16(3, src[2], dest[2], 0xA0);
    if (gCurrentPinballGame->hudSpriteBaseY > 88)
    {
        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void AnimateRubyCatchProgressArrow(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    gCurrentPinballGame->catchProgressFlashing = 0;
    if (gCurrentPinballGame->catchArrowProgress > 1 && gCurrentPinballGame->boardState < 3)
        gCurrentPinballGame->catchProgressFlashing = 1;

    if (gCurrentPinballGame->catchProgressFlashing > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    src = gRubyCatchProgressArrowTilePointers[index];
    dest = gRubyCatchProgressArrowTilePointers[2];
    if (gCurrentPinballGame->hudSpriteBaseY < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }
    DmaCopy16(3, src[1], dest[1], 0x80);
    DmaCopy16(3, src[2], dest[2], 0x80);
    DmaCopy16(3, src[3], dest[3], 0x80);
}

void AnimateRubyBallPowerUpSequence(void)
{
    if (gCurrentPinballGame->ballPowerUpAnimActive == 0)
        return;

    if (gCurrentPinballGame->ballShadowTimer)
    {
        if (gCurrentPinballGame->ballPowerUpOverride == 0)
        {
            gCurrentPinballGame->ballPowerUpLight[0] = (gMain.fieldFrameCount % 20) / 10;
            gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
            gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
        }

        if (gCurrentPinballGame->ballShadowTimer == 28)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }

        if (gCurrentPinballGame->ballShadowTimer == 40)
        MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);

        if (gCurrentPinballGame->ballShadowTimer == 60)
            gMain.fieldSpriteGroups[43]->available = 1;

        gCurrentPinballGame->ballShadowTileIndex = gBallShadowTileIndices[30 - gCurrentPinballGame->ballShadowTimer / 2];
        gCurrentPinballGame->ballShadowTimer--;
    }
    else
    {
        gCurrentPinballGame->ballPowerUpAnimActive = 0;
        if (gCurrentPinballGame->ballPowerUpOverride == 0)
        {
            gCurrentPinballGame->ballPowerUpLight[0] =
                gCurrentPinballGame->ballPowerUpLight[1] =
                gCurrentPinballGame->ballPowerUpLight[2] = 0;
        }

        gCurrentPinballGame->ballPowerUpOverride = 0;
    }
}

void DrawRubyBallPowerUpLights(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    for (i = 0; i < 3; i++) {
        src = &gRubyBallPowerUpLightTilePointers[i][gCurrentPinballGame->ballPowerUpLight[i]];
        dest = &gRubyBallPowerUpLightTilePointers[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}
