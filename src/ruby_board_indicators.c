#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"

extern const struct SongHeader se_ball_upgrade;

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

// Rom_2 data
extern const s16 gCoinRewardLevelTimerThresholds[];
extern const s16 gRubySlingshotAnimIndices[];
extern const u8 *gRubySlingshotTilePointers[2][3][5];
#ifdef EUROPE
// Each row starts with an extra label used by the translated signs.
EXTERN_LANG5(const u8 *, gRubyShopSignTilePointers, [][4]);
#else
extern const u8 *gRubyShopSignTilePointers[][3];
#endif
extern const u8 *gRubyProgressDigitTilePointers[][2];
extern const u8 *gRubyTrapIndicatorTilePointers[][2];
EXTERN_LANG5(const u8 *, gRubyCatchLightTilePointers, [][7][2]);
EXTERN_LANG4_ENDE(const u8 *, gRubySaverTilePointers, [][4]);
EXTERN_LANG5(const u8 *, gRubyHatchArrowTilePointer, [][4]);
EXTERN_LANG5(const u8 *, gRubyBumperArrowTilePointer, [][4]);
EXTERN_LANG5(const u8 *, gRubyShopRampArrowTilePointsers, [][4]);
extern const u8 *gRubyBallPowerUpLightTilePointers[][3];
EXTERN_LANG5(const u8 *, gRubyCatchArrowTilePointer, [][4]);
EXTERN_LANG5(const u8 *, gRubyHoleIndicatorTilePointers, [][4]);
#ifdef EUROPE
extern const u8 *gRubyEvoArrowTilePtrs_EnFrItEs[][5][3];
extern const u8 *gRubyEvoArrowTilePtrs_De[][5][3];
#else
extern const u8 *gRubyEvoArrowTilePtrs[][5][3];
#endif
extern const u8 *gRubyCoinRewardTilePtrs[][5][3];
EXTERN_LANG5(const u8 *, gRubyGetArrowTilePtrs, [][5][3]);
extern const u16 gBallUpgradeFx_TileIndicies[];

void UpdateRubyBoardAnimations(void)
{
    gCurrentPinballGame->hudBlinkPhase = (gCurrentPinballGame->hudAnimFrameCounter % 40) / 20;
    gCurrentPinballGame->hudAnimFrameCounter++;
    DrawRubyProgressDigits();
#ifdef EUROPE
    if (gCurrentPinballGame->hudSpriteBaseY <= 60)
        UpdateRubyShopSignLabel();
#endif
    if (gCurrentPinballGame->hudSpriteBaseY < 232)
    {
        AnimateRubyCatchArrowPalette();
        AnimateRubyEvoArrowPalette();
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 81 && gCurrentPinballGame->hudSpriteBaseY < 248)
        AnimateRubyShopRampArrow();

    AnimateRubyBallPowerUpSequence();
    if (gCurrentPinballGame->hudSpriteBaseY < 112)
        DrawRubyBallPowerUpLights();

    if (gCurrentPinballGame->hudSpriteBaseY > 112)
        AnimateRubyCatchProgressArrow();

    if (gCurrentPinballGame->hudSpriteBaseY > 104)
    {
        DrawRubyEvoArrowProgress();
        DrawRubyCatchArrowProgress();
    }

    if (gCurrentPinballGame->hudSpriteBaseY < 256)
        DrawRubyCoinRewardMeter();

    UpdateCoinRewardTimer();
    if (gCurrentPinballGame->hudSpriteBaseY > 110)
        AnimateRubyTrapIndicator();

    if (gCurrentPinballGame->hudSpriteBaseY > 178)
    {
        AnimateRubyCatchLightBlink();
        AnimateRubyHoleIndicators();
        AnimateRubySlingshotHit();
    }

    if (gCurrentPinballGame->hudSpriteBaseY > 202)
        DrawRubyModeTimerDisplay();

    if (gCurrentPinballGame->saverTimeRemaining
        && gCurrentPinballGame->ballCatchState == NOT_TRAPPED)
        gCurrentPinballGame->saverTimeRemaining--;
}

void AnimateRubySlingshotHit(void)
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
            gCurrentPinballGame->scoreAddedInFrame = SCORE_SLINGSHOT_HIT;
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

#ifdef EUROPE
#define RUBY_SHOP_SIGN_LABEL(lang)                                                  \
    if (!gCurrentPinballGame->shopTransitionActive)                                 \
    {                                                                               \
        src = gRubyShopSignTilePointers##lang[gCurrentPinballGame->evolutionShopActive]; \
        dest = gRubyShopSignTilePointers##lang[2];                                  \
        DmaCopy16(3, src[0], dest[0], 0xA0);                                        \
    }

// The translated shop signs have a label showing which shop (Mart or Evo) is open.
void UpdateRubyShopSignLabel(void)
{
    const u8 *const *src;
    const u8 *const *dest;

    switch (gMain_saveData.language)
    {
    case LANGUAGE_ENGLISH:
        break;
    case LANGUAGE_FRENCH:
        RUBY_SHOP_SIGN_LABEL(_Fr);
        break;
    case LANGUAGE_GERMAN:
        RUBY_SHOP_SIGN_LABEL(_De);
        break;
    case LANGUAGE_ITALIAN:
        RUBY_SHOP_SIGN_LABEL(_It);
        break;
    case LANGUAGE_SPANISH:
        RUBY_SHOP_SIGN_LABEL(_Es);
        break;
    }
}

#define LOAD_SHOP_ITEM_GRAPHICS(table)       \
    src = table[arg0];                       \
    dest = table[2];                         \
    DmaCopy16(3, src[1], dest[1], 0xC0);     \
    DmaCopy16(3, src[2], dest[2], 0xC0);     \
    DmaCopy16(3, src[3], dest[3], 0x20);

void LoadShopItemGraphics(s16 arg0)
{
    const u8 *const *src;
    const u8 *const *dest;

    switch (gMain_saveData.language)
    {
    case LANGUAGE_ENGLISH:
        LOAD_SHOP_ITEM_GRAPHICS(gRubyShopSignTilePointers_En)
        break;
    case LANGUAGE_FRENCH:
        LOAD_SHOP_ITEM_GRAPHICS(gRubyShopSignTilePointers_Fr)
        break;
    case LANGUAGE_GERMAN:
        LOAD_SHOP_ITEM_GRAPHICS(gRubyShopSignTilePointers_De)
        break;
    case LANGUAGE_ITALIAN:
        LOAD_SHOP_ITEM_GRAPHICS(gRubyShopSignTilePointers_It)
        break;
    case LANGUAGE_SPANISH:
        LOAD_SHOP_ITEM_GRAPHICS(gRubyShopSignTilePointers_Es)
        break;
    }
}
#else
void LoadShopItemGraphics(s16 arg0)
{
    const u8 **src;
    const u8 **dest;

    src = gRubyShopSignTilePointers[arg0];
    dest = gRubyShopSignTilePointers[2];
    DmaCopy16(3, src[0], dest[0], 0xC0);
    DmaCopy16(3, src[1], dest[1], 0xC0);
    DmaCopy16(3, src[2], dest[2], 0x20);
}
#endif

void DrawRubyProgressDigits(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = LEAD_DIGIT_10S(gCurrentPinballGame->bonusMultTracker);
    var1 = DIGIT_1S(gCurrentPinballGame->bonusMultTracker);

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

//This is the section that sits under the picture, showing mons till next bonus, "Catch!", and "EVO"
void AnimateRubyCatchLightBlink(void)
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
        src = gRubyCatchLightTilePointers##lang[i][gCurrentPinballGame->modeProgressLights[i]];     \
        dest = gRubyCatchLightTilePointers##lang[i][6];                                             \
        DmaCopy16(3, src[0], dest[0], 0x40);                                                        \
        DmaCopy16(3, src[1], dest[1], 0x40);                                                        \
    }
    LANG5_SWITCH(CATCH_LIGHT_TILES)
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
            gCurrentPinballGame->holeIndicators[0] = TRUE;
            gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        }
    }

#define HOLE_INDICATOR_TILES(lang)                                                                  \
    for (i = 0; i < 4; i++)                                                                         \
    {                                                                                               \
        src = &gRubyHoleIndicatorTilePointers##lang[i][gCurrentPinballGame->holeIndicators[i]];     \
        dest = &gRubyHoleIndicatorTilePointers##lang[i][2];                                         \
        DmaCopy16(3, *src, *dest, 0x40);                                                            \
    }
    LANG5_SWITCH(HOLE_INDICATOR_TILES)
}

#if defined(EUROPE) && !defined(NONMATCHING)
// The European build differs in register allocation / cross-jumping; use the original code.
NAKED
void DrawRubyModeTimerDisplay(void)
{
    asm_unified(
	"\tpush {r4, r5, lr}\n"
	"\tldr r0, _08055014\n"
	"\tldr r3, [r0]\n"
	"\tldr r2, _08055018\n"
	"\tadds r1, r3, r2\n"
	"\tldrh r2, [r1]\n"
	"\tmovs r1, #0x96\n"
	"\tlsls r1, r1, #1\n"
	"\tadds r5, r0, #0\n"
	"\tcmp r2, r1\n"
	"\tbls _08055020\n"
	"\tldr r0, _0805501C\n"
	"\tadds r1, r3, r0\n"
	"\tb _08055036\n"
	"_08055014:\t.4byte gCurrentPinballGame\n"
	"_08055018:\t.4byte 0x724\n"
	"_0805501C:\t.4byte 0x726\n"
	"_08055020:\tcmp r2, #0\n"
	"\tbeq _0805505C\n"
	"\tadds r0, r3, #0\n"
	"\tadds r0, #0x25\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbeq _08055040\n"
	"\tldr r2, _0805503C\n"
	"\tadds r1, r3, r2\n"
	"_08055036:\tmovs r0, #1\n"
	"\tstrb r0, [r1]\n"
	"\tb _08055062\n"
	"_0805503C:\t.4byte 0x726\n"
	"_08055040:\tldr r0, _08055054\n"
	"\tldr r0, [r0, #0x50]\n"
	"\tmovs r1, #0xF\n"
	"\tands r0, r1\n"
	"\tlsrs r0, r0, #3\n"
	"\tldr r2, _08055058\n"
	"\tadds r1, r3, r2\n"
	"\tstrb r0, [r1]\n"
	"\tb _08055062\n"
	"\tmovs r0, r0\n"
	"_08055054:\t.4byte gMain\n"
	"_08055058:\t.4byte 0x726\n"
	"_0805505C:\tldr r1, _08055078\n"
	"\tadds r0, r3, r1\n"
	"\tstrb r2, [r0]\n"
	"_08055062:\tldr r0, _0805507C\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _0805506E\n"
	"\tb _08055188\n"
	"_0805506E:\tlsls r0, r0, #2\n"
	"\tldr r1, _08055080\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"_08055078:\t.4byte 0x726\n"
	"_0805507C:\t.4byte gMain + 0x74\n"
	"_08055080:\t.4byte _08055084\n"
	"_08055084:\t.4byte _08055098 @ case 0\n"
	"\t.4byte _080550F8 @ case 1\n"
	"\t.4byte _08055098 @ case 2\n"
	"\t.4byte _08055114 @ case 3\n"
	"\t.4byte _08055130 @ case 4\n"
	"_08055098:\tldr r0, [r5]\n"
	"\tldr r2, _080550E4\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _080550E8\n"
	"\tadds r3, r0, r1\n"
	"\tadds r4, r1, #0\n"
	"\tadds r4, #0x20\n"
	"\tldr r2, _080550EC\n"
	"\tldr r0, [r3]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r1, #0x20]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r1, _080550F0\n"
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
	"\tble _08055188\n"
	"\tldr r0, [r3, #8]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #8]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _080550F4\n"
	"\tstr r0, [r2, #8]\n"
	"\tb _08055178\n"
	"_080550E4:\t.4byte 0x726\n"
	"_080550E8:\t.4byte gRubySaverTilePointers_EnDe\n"
	"_080550EC:\t.4byte 0x40000D4\n"
	"_080550F0:\t.4byte 0x80000060\n"
	"_080550F4:\t.4byte 0x80000050\n"
	"_080550F8:\tldr r0, [r5]\n"
	"\tldr r1, _0805510C\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _08055110\n"
	"\tb _08055140\n"
	"\tmovs r0, r0\n"
	"_0805510C:\t.4byte 0x726\n"
	"_08055110:\t.4byte gRubySaverTilePointers_Fr\n"
	"_08055114:\tldr r0, [r5]\n"
	"\tldr r1, _08055128\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _0805512C\n"
	"\tb _08055140\n"
	"\tmovs r0, r0\n"
	"_08055128:\t.4byte 0x726\n"
	"_0805512C:\t.4byte gRubySaverTilePointers_It\n"
	"_08055130:\tldr r0, [r5]\n"
	"\tldr r1, _08055190\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #4\n"
	"\tldr r1, _08055194\n"
	"_08055140:\tadds r3, r0, r1\n"
	"\tadds r4, r1, #0\n"
	"\tadds r4, #0x20\n"
	"\tldr r2, _08055198\n"
	"\tldr r0, [r3]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r1, #0x20]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r1, _0805519C\n"
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
	"\tble _08055188\n"
	"\tldr r0, [r3, #8]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #8]\n"
	"\tstr r0, [r2, #4]\n"
	"\tstr r1, [r2, #8]\n"
	"_08055178:\tldr r0, [r2, #8]\n"
	"\tldr r0, [r3, #0xC]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, [r4, #0xC]\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _080551A0\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"_08055188:\tpop {r4, r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\tmovs r0, r0\n"
	"_08055190:\t.4byte 0x726\n"
	"_08055194:\t.4byte gRubySaverTilePointers_Es\n"
	"_08055198:\t.4byte 0x40000D4\n"
	"_0805519C:\t.4byte 0x80000060\n"
	"_080551A0:\t.4byte 0x80000020\n"
    );
}
#else
void DrawRubyModeTimerDisplay(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->saverTimeRemaining > SAVER_WARNING_FLASH_TIME)
    {
        gCurrentPinballGame->saverLit = TRUE;
    }
    else
    {
        if (gCurrentPinballGame->saverTimeRemaining)
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
    }

#define SAVER_TILES(lang)                                           \
    src = gRubySaverTilePointers##lang[gCurrentPinballGame->saverLit]; \
    dest = gRubySaverTilePointers##lang[2];                         \
    DmaCopy16(3, src[0], dest[0], 0xC0);                            \
    DmaCopy16(3, src[1], dest[1], 0xC0);                            \
    if (gCurrentPinballGame->hudSpriteBaseY >= 216)                 \
    {                                                               \
        DmaCopy16(3, src[2], dest[2], 0xA0);                        \
        DmaCopy16(3, src[3], dest[3], 0x40);                        \
    }
    LANG4_SWITCH_ENDE(SAVER_TILES)
}
#endif

void AnimateRubyCatchArrowPalette(void)
{
    s16 index;
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    if (gCurrentPinballGame->catchArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    LANG5_SET_SRC_DEST(gRubyHatchArrowTilePointer, index, 2);
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

void AnimateRubyEvoArrowPalette(void)
{
    s16 index;
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    if (gCurrentPinballGame->evoArrowPaletteActive > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    LANG5_SET_SRC_DEST(gRubyBumperArrowTilePointer, index, 2);
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

void AnimateRubyShopRampArrow(void)
{
    s16 index;
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    if (gCurrentPinballGame->shopDoorTargetFrame > 2)
        gCurrentPinballGame->shopArrowActive = TRUE;
    else if (gCurrentPinballGame->boardState != MAIN_BOARD_STATE_BOARD_INTRO)
        gCurrentPinballGame->shopArrowActive = FALSE;

    if (gCurrentPinballGame->shopArrowActive > 0)
        index = gCurrentPinballGame->evolutionShopActive * 2 + 1 - gCurrentPinballGame->hudBlinkPhase;
    else
        index = gCurrentPinballGame->evolutionShopActive * 2;

    LANG5_SET_SRC_DEST(gRubyShopRampArrowTilePointsers, index, 4);
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
    TILE_PTRS_SRC_DEST_DECL;

    index = 0;
    gCurrentPinballGame->catchProgressFlashing = FALSE;
    if (gCurrentPinballGame->catchArrowProgress > 1
        && BoardNotInActivityMode)
        gCurrentPinballGame->catchProgressFlashing = TRUE;

    if (gCurrentPinballGame->catchProgressFlashing > 0)
        index = 1 - gCurrentPinballGame->hudBlinkPhase;

    LANG5_SET_SRC_DEST(gRubyCatchArrowTilePointer, index, 2);
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
    if (!gCurrentPinballGame->ballPowerUpAnimActive)
        return;

    if (gCurrentPinballGame->gBallUpgradeFxTimer)
    {
        if (!gCurrentPinballGame->ballPowerUpOverride)
        {
            gCurrentPinballGame->ballPowerUpLight[0] = (gMain.fieldFrameCount % 20) / 10;
            gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
            gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
        }

        if (gCurrentPinballGame->gBallUpgradeFxTimer == 28)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeTimer = TICKS_FOR_TIME(1,0);
            DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);
        }

        if (gCurrentPinballGame->gBallUpgradeFxTimer == 40)
        MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);

        if (gCurrentPinballGame->gBallUpgradeFxTimer == 60)
            gMain.fieldSpriteGroups[FIELD_SG_BALL_UPGRADE_FX]->active = TRUE;

        gCurrentPinballGame->ballUpgradeFxTileIndex = gBallUpgradeFx_TileIndicies[30 - gCurrentPinballGame->gBallUpgradeFxTimer / 2];
        gCurrentPinballGame->gBallUpgradeFxTimer--;
    }
    else
    {
        gCurrentPinballGame->ballPowerUpAnimActive = FALSE;
        if (!gCurrentPinballGame->ballPowerUpOverride)
        {
            gCurrentPinballGame->ballPowerUpLight[0] =
                gCurrentPinballGame->ballPowerUpLight[1] =
                gCurrentPinballGame->ballPowerUpLight[2] = FALSE;
        }

        gCurrentPinballGame->ballPowerUpOverride = FALSE;
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

void UpdateCoinRewardTimer(void)
{
    if (gCurrentPinballGame->coinRewardLevel > 0)
    {
        if (gCurrentPinballGame->coinRewardLevelTimer < gCoinRewardLevelTimerThresholds[gCurrentPinballGame->coinRewardLevel - 1])
        {
            gCurrentPinballGame->coinRewardLevelTimer++;
        }
        else
        {
            gCurrentPinballGame->coinRewardLevelTimer = 0;
            gCurrentPinballGame->coinRewardLevel--;
        }
    }
}

void DrawRubyCoinRewardMeter(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->coinRewardLevel == 0)
    {
        sp0[0] = gCurrentPinballGame->hudBlinkPhase * 2;
        sp0[1] = gCurrentPinballGame->hudBlinkPhase;
        sp0[2] = 0;
    }
    else if (gCurrentPinballGame->coinRewardLevel == 1)
    {
        sp0[0] = 3;
        sp0[1] = gCurrentPinballGame->hudBlinkPhase + 1;
        sp0[2] = gCurrentPinballGame->hudBlinkPhase * 2;
    }
    else if (gCurrentPinballGame->coinRewardLevel == 2)
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

    src = gRubyCoinRewardTilePtrs[0][sp0[0]];
    dest = gRubyCoinRewardTilePtrs[0][4];
    if (gCurrentPinballGame->hudSpriteBaseY >= 42 && gCurrentPinballGame->hudSpriteBaseY < 208)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 50 && gCurrentPinballGame->hudSpriteBaseY < 216)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    src = gRubyCoinRewardTilePtrs[1][sp0[1]];
    dest = gRubyCoinRewardTilePtrs[1][4];
    if (gCurrentPinballGame->hudSpriteBaseY >= 58 && gCurrentPinballGame->hudSpriteBaseY < 224)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 66 && gCurrentPinballGame->hudSpriteBaseY < 232)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    src = gRubyCoinRewardTilePtrs[2][sp0[2]];
    dest = gRubyCoinRewardTilePtrs[2][4];
    if (gCurrentPinballGame->hudSpriteBaseY >= 74 && gCurrentPinballGame->hudSpriteBaseY < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 82 && gCurrentPinballGame->hudSpriteBaseY < 248)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    if (gCurrentPinballGame->hudSpriteBaseY >= 90)
    {
        DmaCopy16(3, src[2], dest[2], 0x60);
    }
}

#define EVO_ARROW_TILES(lang) \
    src = gRubyEvoArrowTilePtrs##lang[0][sp0[0]]; \
    dest = gRubyEvoArrowTilePtrs##lang[0][4]; \
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
        src = gRubyEvoArrowTilePtrs##lang[1][sp0[1]]; \
        dest = gRubyEvoArrowTilePtrs##lang[1][4]; \
        DmaCopy16(3, src[0], dest[0], 0x60); \
        DmaCopy16(3, src[1], dest[1], 0x60); \
        DmaCopy16(3, src[2], dest[2], 0x60); \
    } \
 \
    if (gCurrentPinballGame->hudSpriteBaseY > 136) \
    { \
        src = gRubyEvoArrowTilePtrs##lang[2][sp0[2]]; \
        dest = gRubyEvoArrowTilePtrs##lang[2][4]; \
        DmaCopy16(3, src[0], dest[0], 0x60); \
        DmaCopy16(3, src[1], dest[1], 0x60); \
        DmaCopy16(3, src[2], dest[2], 0x60); \
    }

void DrawRubyEvoArrowProgress(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (BoardNotInActivityMode)
    {
        if (gCurrentPinballGame->evoArrowProgress == 0)
        {
            sp0[0] = gCurrentPinballGame->hudBlinkPhase * 2;
            sp0[1] = 0;
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
    src = gRubyGetArrowTilePtrs##lang[0][sp0[0]]; \
    dest = gRubyGetArrowTilePtrs##lang[0][4]; \
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
        src = gRubyGetArrowTilePtrs##lang[1][sp0[1]]; \
        dest = gRubyGetArrowTilePtrs##lang[1][4]; \
        DmaCopy16(3, src[0], dest[0], 0x40); \
        DmaCopy16(3, src[1], dest[1], 0x40); \
        DmaCopy16(3, src[2], dest[2], 0x60); \
    } \
 \
    if (gCurrentPinballGame->hudSpriteBaseY > 136) \
    { \
        src = gRubyGetArrowTilePtrs##lang[2][sp0[2]]; \
        dest = gRubyGetArrowTilePtrs##lang[2][4]; \
        DmaCopy16(3, src[0], dest[0], 0x40); \
        DmaCopy16(3, src[1], dest[1], 0x60); \
        DmaCopy16(3, src[2], dest[2], 0x60); \
    }

void DrawRubyCatchArrowProgress(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    // Note: since these overlap, and the lower tiles are drawn later, this shortcuts some of the
    // needed on/off pairs. EG: with one catch arrow, this uses the 'both on' for the G, and uses
    // the blinking variant of the E, overwriting the lit bit when the E blinks off.
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
