#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/sapphire_states.h"

// Rom_2 data
extern const u16 gSapphireSlingshotHitFrameIndices[];
#ifdef EUROPE
extern const u8 *gSapphirePSquareIndicator_EnDeItEs[][2];
extern const u8 *gSapphirePSquareIndicator_Fr[][2];
#else
extern const u8 *gSapphirePSquareIndicator[][2];
#endif
extern const u8 *gSapphireProgressDigitTilePtrs[][4];
extern const u8 *gWailmerWaterTilePtrs[][4];
extern const u8 *gHatchMachineDrawSegment[][3][2];
extern const u8 *gSapphireSlingshotTilePtrs[][3][5];
extern const u8 *gSapphireTrapIndicatorTilePtrs[][2];
EXTERN_LANG5(const u8 *, gSapphireCatchLightTilePtrs, [][7][2]);
EXTERN_LANG4_ENDE(const u8 *, gSapphireSaverDisplayTilePtrs, [][4]);
EXTERN_LANG5(const u8 *, gSapphireHatchArrowTilePtrs, [][4]);
EXTERN_LANG5(const u8 *, gSapphireBumperArrowTilePtrs, [][4]);
EXTERN_LANG5(const u8 *, gSapphireShopArrowTilePtrs, [][4]);
extern const u8 *gSapphireBallPowerUpLightTilePtrs[][3];
EXTERN_LANG5(const u8 *, gSapphireCatchArrowTilePtrs, [][4]);
EXTERN_LANG5(const u8 *, gSapphireHoleIndicatorTilePtrs, [][4]);
#ifdef EUROPE
extern const u8 *gSapphireEvoArrowTilePtrs_EnFrItEs[][5][3];
extern const u8 *gSapphireEvoArrowTilePtrs_De[][5][3];
#else
extern const u8 *gSapphireEvoArrowTilePtrs[][5][3];
#endif
extern const u8 *gSapphireCoinRewardTilePtrs[][5][3];
EXTERN_LANG5(const u8 *, gSapphireGetArrowTilePtrs, [][5][3]);

// The European release initializes the pointers, since a language switch picks the table.
#ifdef EUROPE
#define TILE_PTRS_SRC_DEST_DECL \
    const u8 *const *src = NULL; \
    const u8 *const *dest = NULL
#else
#define TILE_PTRS_SRC_DEST_DECL \
    const u8 **src;             \
    const u8 **dest
#endif

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

    if (gCurrentPinballGame->saverTimeRemaining
        && gCurrentPinballGame->ballCatchState == NOT_TRAPPED)
        gCurrentPinballGame->saverTimeRemaining--;
}

void DrawSapphireProgressDigits(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = LEAD_DIGIT_10S(gCurrentPinballGame->bonusMultTracker);
    var1 = DIGIT_1S(gCurrentPinballGame->bonusMultTracker);
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

    var0 = gSapphireSlingshotHitFrameIndices[gCurrentPinballGame->slingshotHitAnimTimer];
    if (gCurrentPinballGame->slingshotHitAnimTimer)
    {
        gCurrentPinballGame->slingshotHitAnimTimer--;
        if (gCurrentPinballGame->slingshotHitAnimTimer == 3)
        {
            m4aSongNumStart(SE_SLINGSHOT_HIT);
            gCurrentPinballGame->scoreAddedInFrame = SCORE_SLINGSHOT_HIT;
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

    src = gWailmerWaterTilePtrs[(gMain.systemFrameCount % 64) / 16];
    dest = gWailmerWaterTilePtrs[4];
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

    if (gCurrentPinballGame->modeProgressBlinkTimer)
    {
        gCurrentPinballGame->modeProgressLights[gCurrentPinballGame->evoCatchLightSlot1] = MODE_PROGRESS_LAMP_BALL_LIT - (gCurrentPinballGame->modeProgressBlinkTimer % 36) / 18;
        gCurrentPinballGame->modeProgressLights[gCurrentPinballGame->evoCatchLightSlot2] = gCurrentPinballGame->modeProgressLights[gCurrentPinballGame->evoCatchLightSlot1];
        gCurrentPinballGame->modeProgressBlinkTimer--;
    }

#define CATCH_LIGHT_TILES(lang)                                                                     \
    for (i = 0; i < 3; i++)                                                                         \
    {                                                                                               \
        src = gSapphireCatchLightTilePtrs##lang[i][gCurrentPinballGame->modeProgressLights[i]];     \
        dest = gSapphireCatchLightTilePtrs##lang[i][6];                                             \
        DmaCopy16(3, src[0], dest[0], 0x40);                                                        \
        DmaCopy16(3, src[1], dest[1], 0x40);                                                        \
    }
    LANG5_SWITCH(CATCH_LIGHT_TILES)
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
            gCurrentPinballGame->holeIndicators[0] = TRUE;
            gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        }
    }

#define HOLE_INDICATOR_TILES(lang)                                                                  \
    for (i = 0; i < 4; i++)                                                                         \
    {                                                                                               \
        src = &gSapphireHoleIndicatorTilePtrs##lang[i][gCurrentPinballGame->holeIndicators[i]];     \
        dest = &gSapphireHoleIndicatorTilePtrs##lang[i][2];                                         \
        DmaCopy16(3, *src, *dest, 0x40);                                                            \
    }
    LANG5_SWITCH(HOLE_INDICATOR_TILES)
}

#if defined(EUROPE) && !defined(NONMATCHING)
// The European build differs in register allocation / cross-jumping; use the original code.
NAKED
void DrawSapphireModeTimerDisplay(void)
{
    asm_unified(
	"\tpush {r4, r5, lr}\n"
	"\tldr r0, _0805676C\n"
	"\tldr r3, [r0]\n"
	"\tldr r2, _08056770\n"
	"\tadds r1, r3, r2\n"
	"\tldrh r2, [r1]\n"
	"\tmovs r1, #0x96\n"
	"\tlsls r1, r1, #1\n"
	"\tadds r5, r0, #0\n"
	"\tcmp r2, r1\n"
	"\tbls _08056778\n"
	"\tldr r0, _08056774\n"
	"\tadds r1, r3, r0\n"
	"\tb _0805678E\n"
	"_0805676C:\t.4byte gCurrentPinballGame\n"
	"_08056770:\t.4byte 0x724\n"
	"_08056774:\t.4byte 0x726\n"
	"_08056778:\tcmp r2, #0\n"
	"\tbeq _080567B4\n"
	"\tadds r0, r3, #0\n"
	"\tadds r0, #0x25\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbeq _08056798\n"
	"\tldr r2, _08056794\n"
	"\tadds r1, r3, r2\n"
	"_0805678E:\tmovs r0, #1\n"
	"\tstrb r0, [r1]\n"
	"\tb _080567BA\n"
	"_08056794:\t.4byte 0x726\n"
	"_08056798:\tldr r0, _080567AC\n"
	"\tldr r0, [r0, #0x50]\n"
	"\tmovs r1, #0xF\n"
	"\tands r0, r1\n"
	"\tlsrs r0, r0, #3\n"
	"\tldr r2, _080567B0\n"
	"\tadds r1, r3, r2\n"
	"\tstrb r0, [r1]\n"
	"\tb _080567BA\n"
	"\tmovs r0, r0\n"
	"_080567AC:\t.4byte gMain\n"
	"_080567B0:\t.4byte 0x726\n"
	"_080567B4:\tldr r1, _080567D0\n"
	"\tadds r0, r3, r1\n"
	"\tstrb r2, [r0]\n"
	"_080567BA:\tldr r0, _080567D4\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _080567C6\n"
	"\tb _0805691E\n"
	"_080567C6:\tlsls r0, r0, #2\n"
	"\tldr r1, _080567D8\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"_080567D0:\t.4byte 0x726\n"
	"_080567D4:\t.4byte gMain + 0x74\n"
	"_080567D8:\t.4byte _080567DC\n"
	"_080567DC:\t.4byte _080567F0 @ case 0\n"
	"\t.4byte _0805680C @ case 1\n"
	"\t.4byte _080567F0 @ case 2\n"
	"\t.4byte _08056868 @ case 3\n"
	"\t.4byte _080568C4 @ case 4\n"
	"_080567F0:\tldr r0, [r5]\n"
	"\tldr r2, _08056804\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _08056808\n"
	"\tb _080568D4\n"
	"\tmovs r0, r0\n"
	"_08056804:\t.4byte 0x726\n"
	"_08056808:\t.4byte gSapphireSaverDisplayTilePtrs_EnDe\n"
	"_0805680C:\tldr r0, [r5]\n"
	"\tldr r1, _08056858\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _0805685C\n"
	"\tadds r3, r0, r1\n"
	"\tadds r4, r1, #0\n"
	"\tadds r4, #0x20\n"
	"\tldr r2, _08056860\n"
	"\tldr r0, [r3]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r1, #0x20]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r1, _08056864\n"
	"\tstr r1, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tldr r0, [r3, #4]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #4]\n"
	"\tstr r0, [r2, #4]\n"
	"\tstr r1, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, #0x6A\n"
	"\tmovs r5, #0\n"
	"\tldrsh r0, [r0, r5]\n"
	"\tcmp r0, #0xD7\n"
	"\tble _0805691E\n"
	"\tldr r0, [r3, #8]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #8]\n"
	"\tstr r0, [r2, #4]\n"
	"\tstr r1, [r2, #8]\n"
	"\tb _0805690E\n"
	"\tmovs r0, r0\n"
	"_08056858:\t.4byte 0x726\n"
	"_0805685C:\t.4byte gSapphireSaverDisplayTilePtrs_Fr\n"
	"_08056860:\t.4byte 0x40000D4\n"
	"_08056864:\t.4byte 0x80000070\n"
	"_08056868:\tldr r0, [r5]\n"
	"\tldr r1, _080568B4\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _080568B8\n"
	"\tadds r3, r0, r1\n"
	"\tadds r4, r1, #0\n"
	"\tadds r4, #0x20\n"
	"\tldr r2, _080568BC\n"
	"\tldr r0, [r3]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r1, #0x20]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r1, _080568C0\n"
	"\tstr r1, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tldr r0, [r3, #4]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #4]\n"
	"\tstr r0, [r2, #4]\n"
	"\tstr r1, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, #0x6A\n"
	"\tmovs r5, #0\n"
	"\tldrsh r0, [r0, r5]\n"
	"\tcmp r0, #0xD7\n"
	"\tble _0805691E\n"
	"\tldr r0, [r3, #8]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #8]\n"
	"\tstr r0, [r2, #4]\n"
	"\tstr r1, [r2, #8]\n"
	"\tb _0805690E\n"
	"\tmovs r0, r0\n"
	"_080568B4:\t.4byte 0x726\n"
	"_080568B8:\t.4byte gSapphireSaverDisplayTilePtrs_It\n"
	"_080568BC:\t.4byte 0x40000D4\n"
	"_080568C0:\t.4byte 0x80000070\n"
	"_080568C4:\tldr r0, [r5]\n"
	"\tldr r1, _08056924\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _08056928\n"
	"_080568D4:\tadds r3, r0, r1\n"
	"\tadds r4, r1, #0\n"
	"\tadds r4, #0x20\n"
	"\tldr r2, _0805692C\n"
	"\tldr r0, [r3]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r1, #0x20]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r1, _08056930\n"
	"\tstr r1, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tldr r0, [r3, #4]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #4]\n"
	"\tstr r0, [r2, #4]\n"
	"\tstr r1, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, #0x6A\n"
	"\tmovs r5, #0\n"
	"\tldrsh r0, [r0, r5]\n"
	"\tcmp r0, #0xD7\n"
	"\tble _0805691E\n"
	"\tldr r0, [r3, #8]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #8]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08056934\n"
	"\tstr r0, [r2, #8]\n"
	"_0805690E:\tldr r0, [r2, #8]\n"
	"\tldr r0, [r3, #0xC]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #0xC]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08056938\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"_0805691E:\tpop {r4, r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"_08056924:\t.4byte 0x726\n"
	"_08056928:\t.4byte gSapphireSaverDisplayTilePtrs_Es\n"
	"_0805692C:\t.4byte 0x40000D4\n"
	"_08056930:\t.4byte 0x80000070\n"
	"_08056934:\t.4byte 0x80000060\n"
	"_08056938:\t.4byte 0x80000020\n"
    );
}
#else
void DrawSapphireModeTimerDisplay(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->saverTimeRemaining > SAVER_WARNING_FLASH_TIME)
    {
        gCurrentPinballGame->saverLit = TRUE;
    }
    else if (gCurrentPinballGame->saverTimeRemaining)
    {
        if (gCurrentPinballGame->ballCatchState)
            gCurrentPinballGame->saverLit = TRUE;
        else
            gCurrentPinballGame->saverLit = (gMain.fieldFrameCount % 16) / 8;
    }
    else
    {
        gCurrentPinballGame->saverLit = FALSE;
    }

#define SAVER_TILES(lang)                                                   \
    src = gSapphireSaverDisplayTilePtrs##lang[gCurrentPinballGame->saverLit]; \
    dest = gSapphireSaverDisplayTilePtrs##lang[2];                          \
    DmaCopy16(3, src[0], dest[0], 0xE0);                                    \
    DmaCopy16(3, src[1], dest[1], 0xE0);                                    \
    if (gCurrentPinballGame->hudSpriteBaseY > 215)                          \
    {                                                                       \
        DmaCopy16(3, src[2], dest[2], 0xC0);                                \
        DmaCopy16(3, src[3], dest[3], 0x40);                                \
    }
    LANG4_SWITCH_ENDE(SAVER_TILES)
}
#endif

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
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    if (gCurrentPinballGame->catchArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    LANG5_SET_SRC_DEST(gSapphireHatchArrowTilePtrs, index, 2);
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
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    if (gCurrentPinballGame->evoArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    LANG5_SET_SRC_DEST(gSapphireBumperArrowTilePtrs, index, 2);
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

#define EVO_ARROW_TILES(lang) \
    src = gSapphireEvoArrowTilePtrs##lang[0][sp0[0]]; \
    dest = gSapphireEvoArrowTilePtrs##lang[0][4]; \
    if (gCurrentPinballGame->hudSpriteBaseY < 264) \
    { \
        DmaCopy16(3, src[0], dest[0], 0x60); \
    } \
    DmaCopy16(3, src[1], dest[1], 0x60); \
    DmaCopy16(3, src[2], dest[2], 0x60); \
 \
    if (gCurrentPinballGame->hudSpriteBaseY > 120) \
    { \
        src = gSapphireEvoArrowTilePtrs##lang[1][sp0[1]]; \
        dest = gSapphireEvoArrowTilePtrs##lang[1][4]; \
        DmaCopy16(3, src[0], dest[0], 0x60); \
        DmaCopy16(3, src[1], dest[1], 0x60); \
        DmaCopy16(3, src[2], dest[2], 0x60); \
    } \
 \
    if (gCurrentPinballGame->hudSpriteBaseY > 136) { \
        src = gSapphireEvoArrowTilePtrs##lang[2][sp0[2]]; \
        dest = gSapphireEvoArrowTilePtrs##lang[2][4]; \
        DmaCopy16(3, src[0], dest[0], 0x60); \
        DmaCopy16(3, src[1], dest[1], 0x60); \
        DmaCopy16(3, src[2], dest[2], 0x40); \
    }

void DrawSapphireEvoArrowProgress(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (BoardNotInActivityMode)
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


#ifdef EUROPE
    switch (gMain_saveData.language)
    {
    case LANGUAGE_ENGLISH:
    case LANGUAGE_FRENCH:
    case LANGUAGE_ITALIAN:
    case LANGUAGE_SPANISH:
        EVO_ARROW_TILES(_EnFrItEs)
        break;
    case LANGUAGE_GERMAN:
        EVO_ARROW_TILES(_De)
        break;
    }
#else
    EVO_ARROW_TILES()
#endif
}

#define GET_ARROW_TILES(lang) \
    src = gSapphireGetArrowTilePtrs##lang[0][sp0[0]]; \
    dest = gSapphireGetArrowTilePtrs##lang[0][4]; \
    if (gCurrentPinballGame->hudSpriteBaseY < 264) \
    { \
        DmaCopy16(3, src[0], dest[0], 0x60); \
    } \
 \
    DmaCopy16(3, src[1], dest[1], 0x60); \
    DmaCopy16(3, src[2], dest[2], 0x60); \
 \
    if (gCurrentPinballGame->hudSpriteBaseY > 120) \
    { \
        src = gSapphireGetArrowTilePtrs##lang[1][sp0[1]]; \
        dest = gSapphireGetArrowTilePtrs##lang[1][4]; \
        DmaCopy16(3, src[0], dest[0], 0x40); \
        DmaCopy16(3, src[1], dest[1], 0x40); \
        DmaCopy16(3, src[2], dest[2], 0x60); \
    } \
 \
    if (gCurrentPinballGame->hudSpriteBaseY > 136) \
    { \
        src = gSapphireGetArrowTilePtrs##lang[2][sp0[2]]; \
        dest = gSapphireGetArrowTilePtrs##lang[2][4]; \
        DmaCopy16(3, src[0], dest[0], 0x40); \
        DmaCopy16(3, src[1], dest[1], 0x60); \
        DmaCopy16(3, src[2], dest[2], 0x40); \
    }

void DrawSapphireCatchArrowProgress(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (BoardNotInActivityMode)
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

    LANG5_SWITCH(GET_ARROW_TILES)
}

void AnimateSapphireHatchArrowFlash(void)
{
    s16 index;
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    gCurrentPinballGame->catchProgressFlashing = FALSE;
    if (gCurrentPinballGame->catchArrowProgress > 1
        && BoardNotInActivityMode)
        gCurrentPinballGame->catchProgressFlashing = TRUE;

    if (gCurrentPinballGame->catchProgressFlashing > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;


    LANG5_SET_SRC_DEST(gSapphireCatchArrowTilePtrs, index, 2);
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
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    if (gCurrentPinballGame->shopShockWallAnimState == SHOCK_WALL_ANIM_STATE_NONE)
        gCurrentPinballGame->shopArrowActive = TRUE;
    else if (gCurrentPinballGame->boardState != MAIN_BOARD_STATE_BOARD_INTRO)
        gCurrentPinballGame->shopArrowActive = FALSE;

    if (gCurrentPinballGame->shopArrowActive > 0)
        index = gCurrentPinballGame->evolutionShopActive * 2 + 1 - gCurrentPinballGame->hudBlinkPhase;
    else
        index = gCurrentPinballGame->evolutionShopActive * 2;


    LANG5_SET_SRC_DEST(gSapphireShopArrowTilePtrs, index, 4);
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

    if (gCurrentPinballGame->sapphireHatchMachineState != HATCH_MACHINE_STATE_ELEVATOR_DECENDS)
    {
        for (i = 0; i < 10; i++)
        {
            if (gCurrentPinballGame->targetBumperAnimTimers[i] > 0)
            {
                if (gCurrentPinballGame->targetBumperAnimTimers[i] == 10)
                    m4aSongNumStart(SE_HATCH_MACHINE_SPINNER_TRIGGER);

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
    TILE_PTRS_SRC_DEST_DECL;

#ifdef EUROPE
    if (gCurrentPinballGame->bumperHitsSinceReset >= 100)
        index = (gCurrentPinballGame->hudAnimFrameCounter % 20) / 4;
    else
        index = 0;
#else
    index = 0;
    if (gCurrentPinballGame->bumperHitsSinceReset >= 100)
        index = (gCurrentPinballGame->hudAnimFrameCounter % 20) / 4;
#endif

#ifdef EUROPE
    // Only the French board has a different "P" square.
    switch (gMain_saveData.language)
    {
    case LANGUAGE_ENGLISH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_ITALIAN:
    case LANGUAGE_SPANISH:
        src = gSapphirePSquareIndicator_EnDeItEs[index];
        dest = gSapphirePSquareIndicator_EnDeItEs[5];
        break;
    case LANGUAGE_FRENCH:
        src = gSapphirePSquareIndicator_Fr[index];
        dest = gSapphirePSquareIndicator_Fr[5];
        break;
    }
#else
    src = gSapphirePSquareIndicator[index];
    dest = gSapphirePSquareIndicator[5];
#endif
    if (gCurrentPinballGame->hudSpriteBaseY < 176)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    DmaCopy16(3, src[1], dest[1], 0x40);
}
