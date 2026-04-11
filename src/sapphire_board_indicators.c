#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 *gSapphirePSquareIndicator[][2];
extern const u8 *gHatchMachineDrawSegment[][3][2];
extern const u8 *gSapphireBallPowerUpLightTilePtrs[][3];
extern const u8 *gSapphireShopArrowTilePtrs[][4];
extern const u8 *gSapphireCatchArrowTilePtrs[][4];
extern const u8 *gSapphireGetArrowTilePtrs[][5][3];
extern const u8 *gSapphireEvoArrowTilePtrs[][5][3];
extern const u8 *gSapphireBumperArrowTilePtrs[][4];
extern const u8 *gSapphireHatchArrowTilePtrs[][4];
extern const u8 *gSapphireCoinRewardTilePtrs[][5][3];
extern const u8 *gSapphireSaverDisplayTilePtrs[][4];
extern const u8 *gSapphireHoleIndicatorTilePtrs[][4];
extern const u8 *gSapphireCatchLightTilePtrs[][7][2];
extern const u8 *gRotatingBackgroundTilePtrs[][4];
extern const u8 *gSapphireTrapIndicatorTilePtrs[][2];
extern const u16 gSlingshotHitFrameIndices[];
extern const u8 *gSapphireSlingshotTilePtrs[][3][5];
extern const u8 *gSapphireProgressDigitTilePtrs[][4];


void UpdateSapphireBoardAnimations(void)
{

    gCurrentPinballGame->hudBlinkPhase = (gCurrentPinballGame->hudAnimFrameCounter % 40) / 20;
    gCurrentPinballGame->hudAnimFrameCounter++;
    AnimateHatchMachineSpinner();
    if (gCurrentPinballGame->hudSpriteBaseY > 83)
        AnimateSapphireHatchArrow();

    if (gCurrentPinballGame->hudSpriteBaseY > 18)
        AnimateSapphireBumperArrowPalette();

    if (gCurrentPinballGame->hudSpriteBaseY >= 56 && gCurrentPinballGame->hudSpriteBaseY < 243)
        AnimateSapphireShopArrow();

    AnimateRubyBallPowerUpSequence();
    if (gCurrentPinballGame->hudSpriteBaseY < 112)
        DrawSapphireBallPowerUpLights();

    if (gCurrentPinballGame->hudSpriteBaseY >= 64 && gCurrentPinballGame->hudSpriteBaseY < 254)
        AnimateSapphireHatchArrowFlash();

    if (gCurrentPinballGame->hudSpriteBaseY >= 27 && gCurrentPinballGame->hudSpriteBaseY < 211)
    {
        AnimateRotatingBackground();
        DrawSapphireProgressDigits();
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 104)
    {
        DrawSapphireEvoArrowProgress();
        DrawSapphireCatchArrowProgress();
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 72)
        DrawSapphireCoinRewardMeter();

    UpdateCoinRewardTimer();
    if (gCurrentPinballGame->hudSpriteBaseY > 110)
        AnimateSapphireTrapIndicator();

    if (gCurrentPinballGame->hudSpriteBaseY > 178)
    {
        AnimateSapphireCatchLightBlink();
        AnimateSapphireHoleIndicators();
        AnimateSapphireSlingshotHit();
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 202)
        DrawSapphireModeTimerDisplay();

    if (gCurrentPinballGame->hudSpriteBaseY >= 8 && gCurrentPinballGame->hudSpriteBaseY < 182)
        AnimatePelipperBumper();

    if (gCurrentPinballGame->saverTimeRemaining && gCurrentPinballGame->ballCatchState == 0)
        gCurrentPinballGame->saverTimeRemaining--;
}

void DrawSapphireProgressDigits(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = gCurrentPinballGame->progressLevel / 10;
    var1 = gCurrentPinballGame->progressLevel % 10;
    if (gCurrentPinballGame->hudSpriteBaseY > 36)
    {
        src = gSapphireProgressDigitTilePtrs[var0];
        dest = gSapphireProgressDigitTilePtrs[10];
        DmaCopy16(3, src[0], dest[0], 0x20);
        DmaCopy16(3, src[1], dest[1], 0x20);

        src = gSapphireProgressDigitTilePtrs[var1];
        DmaCopy16(3, src[2], dest[2], 0x20);
        DmaCopy16(3, src[3], dest[3], 0x20);
    }
}

void AnimateSapphireSlingshotHit(void)
{
    s16 var0;
    const u8 **src;
    const u8 **dest;

    var0 = gSlingshotHitFrameIndices[gCurrentPinballGame->slingshotHitAnimTimer];
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

    src = gSapphireSlingshotTilePtrs[gCurrentPinballGame->slingshotSideIndex][var0];
    dest = gSapphireSlingshotTilePtrs[gCurrentPinballGame->slingshotSideIndex][2];
    DmaCopy16(3, src[0], dest[0], 0x20);
    DmaCopy16(3, src[1], dest[1], 0x40);
    DmaCopy16(3, src[2], dest[2], 0x60);
    DmaCopy16(3, src[3], dest[3], 0x60);
    DmaCopy16(3, src[4], dest[4], 0x40);
}

void AnimateSapphireTrapIndicator(void)
{
    const u8 **src;
    const u8 **dest;

    src = gSapphireTrapIndicatorTilePtrs[gCurrentPinballGame->trapAnimState];
    dest = gSapphireTrapIndicatorTilePtrs[3];
    DmaCopy16(3, src[0], dest[0], 0x40);
    DmaCopy16(3, src[1], dest[1], 0x40);
}

// This is the moving water under the wailmer
void AnimateRotatingBackground(void)
{
    const u8 **src;
    const u8 **dest;

    src = gRotatingBackgroundTilePtrs[(gMain.systemFrameCount % 64) / 16];
    dest = gRotatingBackgroundTilePtrs[4];
    if (gCurrentPinballGame->hudSpriteBaseY < 192)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->hudSpriteBaseY < 200)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->hudSpriteBaseY < 208)
    {
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    DmaCopy16(3, src[3], dest[3], 0x60);
}

void AnimateSapphireCatchLightBlink(void)
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
        src = gSapphireCatchLightTilePtrs[i][gCurrentPinballGame->catchLights[i]];
        dest = gSapphireCatchLightTilePtrs[i][6];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
    }
}

void AnimateSapphireHoleIndicators(void)
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
        src = &gSapphireHoleIndicatorTilePtrs[i][gCurrentPinballGame->holeIndicators[i]];
        dest = &gSapphireHoleIndicatorTilePtrs[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void DrawSapphireModeTimerDisplay(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->saverTimeRemaining > 300)
    {
        gCurrentPinballGame->saverLit = 1;
    }
    else if (gCurrentPinballGame->saverTimeRemaining)
    {
        if (gCurrentPinballGame->ballCatchState)
            gCurrentPinballGame->saverLit = 1;
        else
            gCurrentPinballGame->saverLit = (gMain.fieldFrameCount & 0xF) / 8;
    }
    else
    {
        gCurrentPinballGame->saverLit = 0;
    }

    src = gSapphireSaverDisplayTilePtrs[gCurrentPinballGame->saverLit];
    dest = gSapphireSaverDisplayTilePtrs[2];
    DmaCopy16(3, src[0], dest[0], 0xE0);
    DmaCopy16(3, src[1], dest[1], 0xE0);
    if (gCurrentPinballGame->hudSpriteBaseY > 215)
    {
        DmaCopy16(3, src[2], dest[2], 0xC0);
        DmaCopy16(3, src[3], dest[3], 0x40);
    }
}

void DrawSapphireCoinRewardMeter(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->coinRewardLevel == 0)
    {
        sp0[0] = gCurrentPinballGame->hudBlinkPhase;
        sp0[1] = 0;
        sp0[2] = 0;
    }
    else if (gCurrentPinballGame->coinRewardLevel == 1)
    {
        sp0[0] = 1;
        sp0[1] = gCurrentPinballGame->hudBlinkPhase;
        sp0[2] = gCurrentPinballGame->hudBlinkPhase;
    }
    else if (gCurrentPinballGame->coinRewardLevel == 2)
    {
        sp0[0] = 2;
        sp0[1] = 2;
        sp0[2] = gCurrentPinballGame->hudBlinkPhase + 1;
    }
    else
    {
        sp0[0] = 2;
        sp0[1] = 2;
        sp0[2] = 2;
    }

    src = gSapphireCoinRewardTilePtrs[0][sp0[0]];
    dest = gSapphireCoinRewardTilePtrs[0][3];
    if (gCurrentPinballGame->hudSpriteBaseY < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->hudSpriteBaseY < 248)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 88)
    {
        src = gSapphireCoinRewardTilePtrs[1][sp0[1]];
        dest = gSapphireCoinRewardTilePtrs[1][3];
        if (gCurrentPinballGame->hudSpriteBaseY < 254)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }
        if (gCurrentPinballGame->hudSpriteBaseY < 262)
        {
            DmaCopy16(3, src[1], dest[1], 0x40);
        }
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 96)
    {
        src = gSapphireCoinRewardTilePtrs[2][sp0[2]];
        dest = gSapphireCoinRewardTilePtrs[2][3];
        if (gCurrentPinballGame->hudSpriteBaseY < 264)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }

        DmaCopy16(3, src[1], dest[1], 0x40);
        if (gCurrentPinballGame->hudSpriteBaseY > 104)
        {
            DmaCopy16(3, src[2], dest[2], 0x40);
        }
    }
}

void AnimateSapphireHatchArrow(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->catchArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    src = gSapphireHatchArrowTilePtrs[index];
    dest = gSapphireHatchArrowTilePtrs[2];
    if (gCurrentPinballGame->hudSpriteBaseY < 256)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 97 && gCurrentPinballGame->hudSpriteBaseY < 264)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 0x67)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void AnimateSapphireBumperArrowPalette(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->evoArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    src = gSapphireBumperArrowTilePtrs[index];
    dest = gSapphireBumperArrowTilePtrs[2];
    if (gCurrentPinballGame->hudSpriteBaseY < 195)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 30)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 38)
    {
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void DrawSapphireEvoArrowProgress(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->evoArrowProgress == 0)
        {
            sp0[0] = gCurrentPinballGame->hudBlinkPhase * 2;
            sp0[1] = gCurrentPinballGame->hudBlinkPhase;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->evoArrowProgress == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->hudBlinkPhase + 1;
            sp0[2] = gCurrentPinballGame->hudBlinkPhase * 2;
        }
        else if (gCurrentPinballGame->evoArrowProgress == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = gCurrentPinballGame->hudBlinkPhase + 2;
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
        sp0[0] = gCurrentPinballGame->prevTravelArrowTiles[0];
        sp0[1] = gCurrentPinballGame->prevTravelArrowTiles[1];
        sp0[2] = gCurrentPinballGame->prevTravelArrowTiles[2];
    }


    src = gSapphireEvoArrowTilePtrs[0][sp0[0]];
    dest = gSapphireEvoArrowTilePtrs[0][4];
    if (gCurrentPinballGame->hudSpriteBaseY < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }
    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->hudSpriteBaseY > 120)
    {
        src = gSapphireEvoArrowTilePtrs[1][sp0[1]];
        dest = gSapphireEvoArrowTilePtrs[1][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 136) {
        src = gSapphireEvoArrowTilePtrs[2][sp0[2]];
        dest = gSapphireEvoArrowTilePtrs[2][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x40);
    }
}

void DrawSapphireCatchArrowProgress(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->catchArrowProgress == 0)
        {
            sp0[0] = gCurrentPinballGame->hudBlinkPhase * 2;
            sp0[1] = 0;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->catchArrowProgress == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->hudBlinkPhase + 1;
            sp0[2] = gCurrentPinballGame->hudBlinkPhase * 2;
        }
        else if (gCurrentPinballGame->catchArrowProgress == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = (s16) gCurrentPinballGame->hudBlinkPhase + 2;
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
        sp0[0] = gCurrentPinballGame->travelArrowTiles[0];
        sp0[1] = gCurrentPinballGame->travelArrowTiles[1];
        sp0[2] = gCurrentPinballGame->travelArrowTiles[2];
    }

    src = gSapphireGetArrowTilePtrs[0][sp0[0]];
    dest = gSapphireGetArrowTilePtrs[0][4];
    if (gCurrentPinballGame->hudSpriteBaseY < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->hudSpriteBaseY > 120)
    {
        src = gSapphireGetArrowTilePtrs[1][sp0[1]];
        dest = gSapphireGetArrowTilePtrs[1][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 136)
    {
        src = gSapphireGetArrowTilePtrs[2][sp0[2]];
        dest = gSapphireGetArrowTilePtrs[2][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x40);
    }
}

void AnimateSapphireHatchArrowFlash(void)
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


    src = gSapphireCatchArrowTilePtrs[index];
    dest = gSapphireCatchArrowTilePtrs[2];
    if (gCurrentPinballGame->hudSpriteBaseY < 232)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY < 240)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 80)
    {
        if (gCurrentPinballGame->hudSpriteBaseY < 248)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void AnimateSapphireShopArrow(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->shopShockWallAnimState == 3)
        gCurrentPinballGame->shopArrowActive = 1;
    else if (gCurrentPinballGame->boardState)
        gCurrentPinballGame->shopArrowActive = 0;

    if (gCurrentPinballGame->shopArrowActive > 0)
        index = gCurrentPinballGame->evolutionShopActive * 2 + 1 - gCurrentPinballGame->hudBlinkPhase;
    else
        index = gCurrentPinballGame->evolutionShopActive * 2;


    src = gSapphireShopArrowTilePtrs[index];
    dest = gSapphireShopArrowTilePtrs[4];
    if (gCurrentPinballGame->hudSpriteBaseY < 224)
    {
        DmaCopy16(3, src[0], dest[0], 0x80);
    }

    if (gCurrentPinballGame->hudSpriteBaseY < 232)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 71)
    {
        if (gCurrentPinballGame->hudSpriteBaseY < 240)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void DrawSapphireBallPowerUpLights(void)
{
    s16 i;

    for (i = 0; i < 3; i++)
    {
        const u8 **src = &gSapphireBallPowerUpLightTilePtrs[i][gCurrentPinballGame->ballPowerUpLight[i]];
        const u8 **dest = &gSapphireBallPowerUpLightTilePtrs[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void AnimateHatchMachineSpinner(void)
{
    s16 i;
    s16 srcIndex;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->sapphireHatchMachineState != 3)
    {
        for (i = 0; i < 10; i++)
        {
            if (gCurrentPinballGame->targetBumperAnimTimers[i] > 0)
            {
                if (gCurrentPinballGame->targetBumperAnimTimers[i] == 10)
                    m4aSongNumStart(SE_UNKNOWN_0xDC);

                gCurrentPinballGame->targetBumperAnimTimers[i]--;
                srcIndex = 1;
            }
            else
            {
                srcIndex = 0;
            }

            src = gHatchMachineDrawSegment[i][srcIndex];
            dest = gHatchMachineDrawSegment[i][2];
            DmaCopy16(3, src[0], dest[0], 0x40);
            DmaCopy16(3, src[1], dest[1], 0x40);
        }
    }
}

void AnimatePelipperBumper(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->bumperHitsSinceReset >= 100)
        index = (gCurrentPinballGame->hudAnimFrameCounter % 20) / 4;

    src = gSapphirePSquareIndicator[index];
    dest = gSapphirePSquareIndicator[5];
    if (gCurrentPinballGame->hudSpriteBaseY < 176)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    DmaCopy16(3, src[1], dest[1], 0x40);
}
