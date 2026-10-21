#include "global.h"
#include "agb_sram.h"
#include "main.h"
#include "m4a.h"
#include "constants/board/main_board.h"
#include "constants/board/groudon_states.h"
#include "constants/board/rayquaza_states.h"
#include "constants/board/ruby_states.h"
#include "constants/board/sapphire_states.h"
#include "constants/mem_layout/dusclops.h"
#include "constants/mem_layout/kecleon.h"
#include "constants/mem_layout/kyogre.h"
#include "constants/mem_layout/groudon.h"
#include "constants/mem_layout/rayquaza.h"
#include "constants/mem_layout/spheal.h"
#include "constants/mem_layout/ruby.h"
#include "constants/mem_layout/sapphire.h"

extern EWRAM_DATA u8 gBoardBGTileBufferAlt[32 * 0x400];
extern EWRAM_DATA u8 gBoardBGTileBuffer[];
extern EWRAM_DATA u8 gCatchSpriteGfxBuffer[3][SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES];

// Rom_1 data
EXTERN_LANG5(const u8, gDusclopsBonusClear_Gfx, [SIZE_OF_VRAM_DUSCLOPS_BANNER_TILES]);
EXTERN_LANG5(const u8, gKecleonBonusClear_Gfx, [SIZE_OF_VRAM_KECLEON_BANNER_TILES]);
EXTERN_LANG5(const u8, gKyogreBonusClear_Gfx, [SIZE_OF_VRAM_KYOGRE_BANNER_TILES]);
EXTERN_LANG5(const u8, gGroudonBonusClear_Gfx, [SIZE_OF_VRAM_GROUDON_BANNER_TILES]);
EXTERN_LANG5(const u8, gRayquazaBonusClear_Gfx, [SIZE_OF_VRAM_RAYQUAZA_BANNER_TILES]);
extern const u8 gCaptureScreenTilesGfx[SIZE_OF_VRAM_FX_MON_CATCH_CUTSCENE_TILES];
extern const u8 gRubyTravelPaint_Gfx[SIZE_OF_VRAM_FX_TRAVEL_CUTSCENE];
extern const Palette gRubyPainter_Pals;
extern const u8 gSapphireTravelPaint_Gfx[SIZE_OF_VRAM_FX_TRAVEL_CUTSCENE];
extern const Palette gSapphirePainter_Pals;
extern const u8 gPichuKickbackFx_Gfx[SIZE_OF_VRAM_PIKA_SAVER_KICKBACK_TILES];
extern const u8 gPikachuKickbackFx_Gfx[SIZE_OF_VRAM_PIKA_SAVER_KICKBACK_TILES];
extern const u8 gCatchMonAppearFx_Gfx[SIZE_OF_VRAM_FX_CATCH_REAVEAL_SEQUENTIAL_TILES];
extern const u8 gCatchTile_RevealTilesGfx[SIZE_OF_VRAM_FX_CATCH_REAVEAL_SEQUENTIAL_TILES];
extern const u8 gCatchTile_BurstStart_Gfx[SIZE_OF_VRAM_FX_CATCH_BURST_LIGHTNING_TILES];
extern const u8 gCatchTile_BurstStage2_Gfx[SIZE_OF_VRAM_FX_CATCH_BURST_TILE_OUTLINE];
extern const u8 gCatchTile_BurstStage3_Gfx[SIZE_OF_VRAM_FX_CATCH_BURST_TILE_FLIGHT];
extern const u8 gCatchTile_BurstStage4_Gfx[SIZE_OF_VRAM_FX_CATCH_BURST_TILE_ELECTRIC];
extern const u8 gAerodactlyFlight_Gfx[SIZE_OF_VRAM_AERODACTYL_EGG_DELIVERY_TILES];

extern const u8 gBallRotationTileGraphics[][SIZE_OF_VRAM_BALL_TILES];
extern const u8 gBallUpgradeFx_Gfx[][SIZE_OF_VRAM_FX_BALL_UPGRADE_TILES];
extern const u8 gRubyChikoritaEntity[][SIZE_OF_VRAM_CHIKORITA_TILES];
extern const u8 gRayquazaSkyBackgroundGfx[SIZE_OF_VRAM_RAYQUAZA_INTRO_CLOUDS_TILES];
extern const u8 gChinchouBumper_Gfx[][SIZE_OF_VRAM_RUBY_BUMPER_TILES];
extern const u8 gFlipper_Gfx[][SIZE_OF_VRAM_FLIPPER_TILES];
extern const u8 gAlphabetTilesGfx[][SIZE_OF_VRAM_LETTER_TILE];
#ifdef EUROPE
// The space tile follows the letter tiles.
#define gSpaceTileGfx gAlphabetTilesGfx[53]
#else
extern const u8 gSpaceTileGfx[SIZE_OF_VRAM_LETTER_TILE];
#endif
extern const u8 gMainStageBonusTrap_Gfx[][SIZE_OF_VRAM_FX_CENTER_HOLE_GRAVITY_TILES];
extern const u8 gRubyStageCyndaquil_Gfx[][SIZE_OF_VRAM_CYNDAQUIL_TILES];
extern const u8 gDecimalDigitTilesGfx[][SIZE_OF_VRAM_MART_PRICE_DIGIT];
extern const u8 gLocationPortraitGfx[][SIZE_OF_VRAM_PORTRAIT_TILES];
extern const u8 gTotodileEggDelivery_Gfx[SIZE_OF_VRAM_TOTODILE_EGG_DELIVERY_TILES];
extern const u8 gHatchMachineElevator_Gfx[][SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES];
extern const u8 gGroudonAttackFx_Gfx[SIZE_OF_VRAM_GROUDON_ATTACK_FX_TILES];
extern const u8 gRayquazaFlyby_Gfx[SIZE_OF_VRAM_RAYQUAZA_FLYBY_TILES];
extern const u8 gRayquazaSpriteSheet[SIZE_OF_VRAM_RAYQUAZA_TILES];
EXTERN_LANG4_ENFR(const u8, gSphealResultsScreenGfx, [SIZE_OF_VRAM_SPHEAL_SUMMARY_TILES]);
extern const u8 gChargeFillIndicator_Gfx[][SIZE_OF_VRAM_CHARGE_INDICATOR_CIRCLE_TILES];
extern const u8 gPikachuSaverTilesGfx[][SIZE_OF_VRAM_PIKA_MON_TILES];
extern const u8 gRubyBoardShopDoor_Gfx[][SIZE_OF_VRAM_RUBY_MART_DOOR_TILES];
extern const u8 gRubyBoardSharpedo_Gfx[][SIZE_OF_VRAM_SHARPEDO_TILES];
extern const u8 gMartEvoForegroundMenuUx_Gfx[SIZE_OF_VRAM_MART_EVO_FOREGROUND_UX_TILES];
#ifdef EUROPE
extern const u8 gMartEvoForegroundMenuUx_Gfx_De[SIZE_OF_VRAM_MART_EVO_FOREGROUND_UX_TILES];
#endif
EXTERN_LANG5(const u8, gRubyBoardShop_Gfx, [][SIZE_OF_VRAM_RUBY_MART_SIGN_TILES]);
extern const u8 gAreaRouletteSelectedFx_Gfx[SIZE_OF_VRAM_FX_AREA_ROULETTE_SELECTED_TILES];
extern const u8 gMainBoardPikaSpinner_Gfx[][SIZE_OF_VRAM_PIKA_CHARGE_SPINNER_TILES];
extern const u8 gRubyBoardHatchCave_Gfx[][SIZE_OF_VRAM_HATCH_CAVE_TILES];
extern const u8 gEggFrameTilesGfx[][SIZE_OF_VRAM_HATCH_EGG_TILES];
EXTERN_LANG5(const u8, gMainBoardBallSave_Gfx, [SIZE_OF_VRAM_BALL_SAVER_BANNER_AND_MON_TILES]);
EXTERN_LANG5(const u8, gMainBoardEndOfBall_Gfx, [SIZE_OF_VRAM_END_OF_BALL_BONUS_WINDOW_TILES]);
extern const u8 gSapphireBoardZigzagoonFx_Gfx[SIZE_OF_VRAM_FX_ZIGZAGZOON_ROULETTE_STOP_TILES];

// Rom_2 data
#ifdef EUROPE
extern const s16 gCaughtTextChars_En[];
extern const s16 gCaughtTextChars_Fr[];
extern const s16 gCaughtTextChars_It[];
extern const s16 gCaughtTextChars_De[];
extern const s16 gCaughtTextChars_Es[];
#else
extern const s16 gCaughtTextChars[];
#endif
extern const u16 gShopItemData[][4];
extern const u16 gShopCursorToItemMap[];
extern const u16 gEggAnimationFrameData[][4];
extern const s16 gEvoShopAnimFrames[][7];
extern const s16 gHoleAnimKeyframeData[][2];
extern const Palette *gMonPortraitGroupPals[];
extern const u8 *gMonPortraitGroupGfx[];

void SaveGameStateSnapshot(s16);

void RestoreFieldSpecificGraphics(void);
void RestoreMainFieldDynamicGraphics(void);
void RestoreRubyBoardTileGraphics(void);
void RestoreSapphireBoardTileGraphics(void);
void nullsub_18(void);
void RestoreDusclopsBonusGraphics(void);
void RestoreKecleonBonusGraphics(void);
void RestoreKyogreBonusGraphics(void);
void RestoreGroudonBonusGraphics(void);
void RestoreRayquazaBonusGraphics(void);
void RestoreSphealBonusGraphics(void);

void SaveGameStateSnapshot(s16 arg0)
{
    s16 i;

    if (gMPlayInfo_BGM.status >= 0)
    {
        gCurrentPinballGame->savedBgmSongHeader = gMPlayInfo_BGM.songHeader;
        m4aMPlayStop(&gMPlayInfo_BGM);
    }
    else
    {
        gCurrentPinballGame->savedBgmSongHeader = NULL;
    }

    for (i = 0; i < 100; i++)
        gCurrentPinballGame->savedSpriteAvailability[gMain.isBonusField][i] = gMain.spriteGroups[i].active;

    DmaCopy16(3, OBJ_PLTT, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], OBJ_PLTT_SIZE);
    DmaCopy16(3, BG_PLTT, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], BG_PLTT_SIZE);
    if (!arg0)
        return;

    gCurrentPinballGame->bgOffsets0 = gMain.bgOffsets[0];
    gCurrentPinballGame->bgOffsets1 = gMain.bgOffsets[1];
    gCurrentPinballGame->bgOffsets2 = gMain.bgOffsets[2];
    gCurrentPinballGame->bgOffsets3 = gMain.bgOffsets[3];
    gCurrentPinballGame->savedField = gMain.selectedField;
    gCurrentPinballGame->savedTempField = gMain.tempField;
    gCurrentPinballGame->savedIsBonusField = gMain.isBonusField;
    gCurrentPinballGame->savedModeChangeFlags = gMain.modeChangeFlags;
    gCurrentPinballGame->savedDebugMenuCursorIndex = gMain.debugMenuCursorIndex;
    gCurrentPinballGame->savedPendingModeChangeType = gMain.pendingModeChangeType;
    gCurrentPinballGame->savedAnimationTimer = gMain.animationTimer;
    gCurrentPinballGame->savedModeChangeDelayTimer = gMain.modeChangeDelayTimer;
    gCurrentPinballGame->savedShopPanelActive = gMain.shopPanelActive;
    gCurrentPinballGame->savedShopPanelSlideOffset = gMain.shopPanelSlideOffset;
    gCurrentPinballGame->savedBlendControl = gCurrentPinballGame->pauseBlendControl;
    gCurrentPinballGame->savedBlendAlpha = gCurrentPinballGame->pauseBlendAlpha;
    gCurrentPinballGame->savedBlendBrightness = gCurrentPinballGame->pauseBlendBrightness;
    gCurrentPinballGame->savedcutsceneBackdropBarActive = gCurrentPinballGame->pauseCutsceneBackdropBarActive;
    gCurrentPinballGame->savedVCount = gCurrentPinballGame->pauseVCount;
    gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gCurrentPinballGame->eReaderBonuses[i] = gMain.eReaderBonuses[i];
#ifdef EUROPE
    gCurrentPinballGame->savedLanguage = gMain_saveData.language;
#endif
}

void SaveGameToSram(void)
{
    gCurrentPinballGame->saveDataValid = TRUE;
    WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(*gCurrentPinballGame));
}

/// @brief
/// @param arg0 1 = restore game SRAM, 2 = load demo, 0 = ?
void RestoreGameState(u16 arg0)
{
    s16 i, j;
    s16 var0, scrollYTileIx;

    if (arg0 == 1)
    {
        ReadSramFast((void *)SRAM + 0x544, (u8 *)gCurrentPinballGame, sizeof(*gCurrentPinballGame));
    }
    else if (arg0 == 2)
    {
        DmaCopy16(3, gBoardConfig.pinballGame, gCurrentPinballGame, sizeof(*gCurrentPinballGame));
        gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
        gCurrentPinballGame->cameraBall = &gCurrentPinballGame->ballStates[0];

        if ((gMain.idleDemoVariant % 4) == 1)
        {
            gCurrentPinballGame->pikaSpinMomentum = 0;
            gCurrentPinballGame->kickbackAnimFrameTimer = 0;
            gCurrentPinballGame->kickbackFrameId = 0;
            gCurrentPinballGame->pikaChargeTarget = 0;
            gCurrentPinballGame->pikaChargeProgress = 0;
            gCurrentPinballGame->prevChargeFillValue = 0;
            gCurrentPinballGame->chargeFillValue = 0;
            gCurrentPinballGame->chargeIndicatorXOffset = 0;
            gCurrentPinballGame->chargeIndicatorYOffset = -4;
            gCurrentPinballGame->chargeIndicatorScaleX = 256;
            gCurrentPinballGame->chargeIndicatorScaleY = 256;
            gCurrentPinballGame->chargeFillAnimTimer = 0;
            gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
        }
    }

    if (arg0 != 0)
    {
        gMain.selectedField = gCurrentPinballGame->savedField;
        gMain.tempField = gCurrentPinballGame->savedTempField;
        gMain.isBonusField = gCurrentPinballGame->savedIsBonusField;
        gMain.modeChangeFlags = gCurrentPinballGame->savedModeChangeFlags;
        gMain.debugMenuCursorIndex = gCurrentPinballGame->savedDebugMenuCursorIndex;
        gMain.pendingModeChangeType = gCurrentPinballGame->savedPendingModeChangeType;
        gMain.animationTimer = gCurrentPinballGame->savedAnimationTimer;
        gMain.modeChangeDelayTimer = gCurrentPinballGame->savedModeChangeDelayTimer;
        gMain.shopPanelActive = gCurrentPinballGame->savedShopPanelActive;
        gMain.shopPanelSlideOffset = gCurrentPinballGame->savedShopPanelSlideOffset;
        gMain.blendControl = gCurrentPinballGame->savedBlendControl;
        gMain.blendAlpha = gCurrentPinballGame->savedBlendAlpha;
        gMain.blendBrightness = gCurrentPinballGame->savedBlendBrightness;
        gMain.cutsceneBackdropBarActive = gCurrentPinballGame->savedcutsceneBackdropBarActive;
        gMain.vCount = gCurrentPinballGame->savedVCount;
        gMain.bgOffsets[0] = gCurrentPinballGame->bgOffsets0;
        gMain.bgOffsets[1] = gCurrentPinballGame->bgOffsets1;
        gMain.bgOffsets[2] = gCurrentPinballGame->bgOffsets2;
        gMain.bgOffsets[3] = gCurrentPinballGame->bgOffsets3;
        for (i = 0; i < NUM_EREADER_CARDS; i++)
            gMain.eReaderBonuses[i] = gCurrentPinballGame->eReaderBonuses[i];

        gCurrentPinballGame->startButtonDisabled = TRUE;
#ifdef EUROPE
        if (arg0 == 1)
        {
            if (gMain.selectedField < MAIN_FIELD_COUNT)
            {
                gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->cameraBaseY +
                                             gCurrentPinballGame->tiltYOffset +
                                             gCurrentPinballGame->cameraScrollOffset +
                                             gCurrentPinballGame->cameraYAdjust;
            }
            // A saved game keeps the language it was played in.
            gMain_saveData.language = gCurrentPinballGame->savedLanguage;
        }
#else
        if (arg0 == 1 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->cameraBaseY +
                                         gCurrentPinballGame->tiltYOffset +
                                         gCurrentPinballGame->cameraScrollOffset +
                                         gCurrentPinballGame->cameraYAdjust;
        }
#endif
    }
    else
    {
        gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->hudSpriteBaseY;
    }

    gCurrentPinballGame->fadeSubState = 0;
    gMain.continueFromSave = FALSE;
    loadFieldBoardGraphics();
    if (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->boardCollisionConfigChanged)
        SetBoardCollisionConfig(1);

    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        for (i = 0; i < 22; i++)
        {
            var0 = i + gCurrentPinballGame->prevScrollYTileIx;
            scrollYTileIx = (i + 10 + gCurrentPinballGame->prevScrollYTileIx) % 22;
            if (var0 < 32)
            {
                DmaCopy16(3, &gBoardBGTileBuffer[var0 * 0x400], (void *) BG_VRAM_ADDR_MAIN_SCROLL_SEGMENT_TILES + scrollYTileIx * MEM_SIZE_OF_TILE_ROW, MEM_SIZE_OF_TILE_ROW);
            }
            else
            {
                var0 -= 32;
                DmaCopy16(3, &gBoardBGTileBufferAlt[var0 * 0x400], (void *)BG_VRAM_ADDR_MAIN_SCROLL_SEGMENT_TILES + scrollYTileIx * MEM_SIZE_OF_TILE_ROW, MEM_SIZE_OF_TILE_ROW);
            }
        }
    }

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gBG0TilemapBuffer, BG_VRAM_ADDR_ALL_BOARDS_LAYER_0_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
    if (gMain.cutsceneBackdropBarActive)
    {
        if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EVO_MODE)
        {
            for (j = 0; j <= gCurrentPinballGame->cutsceneTilemapColumn; j++)
            {
                for (i = 2; i < 12; i++)
                    gBG0TilemapBuffer[(i + 15) * 0x20 + j] = 0xC100;
            }
        }
        else
        {
            for (j = 0; j <= gCurrentPinballGame->cutsceneTilemapColumn; j++)
            {
                for (i = 1; i < 11; i++)
                    gBG0TilemapBuffer[(i + 15) * 0x20 + j] = 0xC100;
            }
        }

        DmaCopy16(3, gBG0TilemapBuffer, BG_VRAM_ADDR_WAS_CAUGHT_BACKDROP_TILEMAP, SIZE_OF_VRAM_WAS_CAUGHT_BACKDROP_TILEMAP);
    }

    DmaCopy16(3, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);
    RestoreFieldSpecificGraphics();
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        InitFrameProcess0_DefaultSpriteState_RubyBoard();
        LoadShopItemGraphics(gCurrentPinballGame->evolutionShopActive);
        break;
    case FIELD_SAPPHIRE:
        InitFrameProcess0_DefaultSpriteState_SapphireBoard();
        break;
    case FIELD_DUSCLOPS:
        InitFrameProcess0_DefaultSpriteState_DusclopsBoard();
        break;
    case FIELD_KECLEON:
        InitFrameProcess0_DefaultSpriteState_KecleonBoard();
        break;
    case FIELD_KYOGRE:
        InitFrameProcess0_DefaultSpriteState_KyogreBoard();
        break;
    case FIELD_GROUDON:
        InitFrameProcess0_DefaultSpriteState_GroudonBoard();
        break;
    case FIELD_RAYQUAZA:
        InitFrameProcess0_DefaultSpriteState_RayquazaBoard();
        break;
    case FIELD_SPHEAL:
        InitFrameProcess0_DefaultSpriteState_SphealBoard();
        break;
    }

    for (i = 0; i < 100; i++)
        gMain.spriteGroups[i].active = gCurrentPinballGame->savedSpriteAvailability[gMain.isBonusField][i];

    if (arg0 == 1)
    {
        gCurrentPinballGame->saveDataValid = FALSE;
        WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(gCurrentPinballGame->saveDataValid));
    }
}

#define RESTORE_SPECIES_NAME_TILES(...)                                                                  \
    for (i = 0; i < 10; i++)                                                                              \
    {                                                                                                     \
        if (SPECIES_NAME(__VA_ARGS__)[i] == ' ')                                                          \
        {                                                                                                 \
            DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);   \
        }                                                                                                 \
        else                                                                                              \
        {                                                                                                 \
            int letterTileIx = SPECIES_NAME(__VA_ARGS__)[i] - 'A';                                        \
            DmaCopy16(3, gAlphabetTilesGfx[letterTileIx], OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE); \
        }                                                                                                 \
    }

#define RESTORE_CAUGHT_TEXT_TILES(text)                                                                   \
    for (i = 0; i < CAUGHT_TEXT_LENGTH; i++)                                                              \
    {                                                                                                     \
        if (text[i] == ' ')                                                                               \
        {                                                                                                 \
            DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_WAS_CAUGHT_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE); \
        }                                                                                                 \
        else                                                                                              \
        {                                                                                                 \
            int letterTileIx = text[i] - 'A';                                                             \
            DmaCopy16(3, gAlphabetTilesGfx[letterTileIx], OBJ_VRAM_ADDR_WAS_CAUGHT_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE); \
        }                                                                                                 \
    }

#ifdef EUROPE
#define SPECIES_NAME(lang) gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[lang]
#define RESTORE_SPECIES_NAME_TILES_LANG()                          \
    switch (gMain_saveData.language)                               \
    {                                                              \
    case LANGUAGE_ENGLISH:                                         \
    case LANGUAGE_ITALIAN:                                         \
    case LANGUAGE_SPANISH:                                         \
        RESTORE_SPECIES_NAME_TILES(SPECIES_NAME_INTERNATIONAL)     \
        break;                                                     \
    case LANGUAGE_FRENCH:                                          \
        RESTORE_SPECIES_NAME_TILES(SPECIES_NAME_FRENCH)            \
        break;                                                     \
    case LANGUAGE_GERMAN:                                          \
        RESTORE_SPECIES_NAME_TILES(SPECIES_NAME_GERMAN)            \
        break;                                                     \
    }
#define RESTORE_CAUGHT_TEXT_TILES_LANG()                           \
    switch (gMain_saveData.language)                               \
    {                                                              \
    case LANGUAGE_ENGLISH:                                         \
        RESTORE_CAUGHT_TEXT_TILES(gCaughtTextChars_En)             \
        break;                                                     \
    case LANGUAGE_FRENCH:                                          \
        RESTORE_CAUGHT_TEXT_TILES(gCaughtTextChars_Fr)             \
        break;                                                     \
    case LANGUAGE_GERMAN:                                          \
        RESTORE_CAUGHT_TEXT_TILES(gCaughtTextChars_De)             \
        break;                                                     \
    case LANGUAGE_ITALIAN:                                         \
        RESTORE_CAUGHT_TEXT_TILES(gCaughtTextChars_It)             \
        break;                                                     \
    case LANGUAGE_SPANISH:                                         \
        RESTORE_CAUGHT_TEXT_TILES(gCaughtTextChars_Es)             \
        break;                                                     \
    }
#define DMA_MART_EVO_FOREGROUND_UX()                                                                                         \
    switch (gMain_saveData.language)                                                                                         \
    {                                                                                                                        \
    case LANGUAGE_ENGLISH:                                                                                                   \
    case LANGUAGE_FRENCH:                                                                                                    \
    case LANGUAGE_ITALIAN:                                                                                                   \
    case LANGUAGE_SPANISH:                                                                                                   \
        DmaCopy16(3, gMartEvoForegroundMenuUx_Gfx, OBJ_VRAM_ADDR_MART_EVO_FOREGROUND_UX_TILES, SIZE_OF_VRAM_MART_EVO_FOREGROUND_UX_TILES);    \
        break;                                                                                                               \
    case LANGUAGE_GERMAN:                                                                                                    \
        DmaCopy16(3, gMartEvoForegroundMenuUx_Gfx_De, OBJ_VRAM_ADDR_MART_EVO_FOREGROUND_UX_TILES, SIZE_OF_VRAM_MART_EVO_FOREGROUND_UX_TILES); \
        break;                                                                                                               \
    }
#else
#define SPECIES_NAME() gSpeciesInfo[gCurrentPinballGame->currentSpecies].name
#define RESTORE_SPECIES_NAME_TILES_LANG() RESTORE_SPECIES_NAME_TILES()
#define RESTORE_CAUGHT_TEXT_TILES_LANG() RESTORE_CAUGHT_TEXT_TILES(gCaughtTextChars)
#define DMA_MART_EVO_FOREGROUND_UX() \
    DmaCopy16(3, gMartEvoForegroundMenuUx_Gfx, OBJ_VRAM_ADDR_MART_EVO_FOREGROUND_UX_TILES, SIZE_OF_VRAM_MART_EVO_FOREGROUND_UX_TILES)
#endif

void RestoreFieldSpecificGraphics(void)
{
    s16 i;
    struct PokemonSpecies *species;
    const u16 *var1;
    s16 var2, var3;

    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        RestoreMainFieldDynamicGraphics();
        RestoreRubyBoardTileGraphics();
        break;
    case FIELD_SAPPHIRE:
        RestoreMainFieldDynamicGraphics();
        RestoreSapphireBoardTileGraphics();
        break;
    case FIELD_DUSCLOPS:
        nullsub_18();
        RestoreDusclopsBonusGraphics();
        break;
    case FIELD_KECLEON:
        nullsub_18();
        RestoreKecleonBonusGraphics();
        break;
    case FIELD_KYOGRE:
        nullsub_18();
        RestoreKyogreBonusGraphics();
        break;
    case FIELD_GROUDON:
        nullsub_18();
        RestoreGroudonBonusGraphics();
        break;
    case FIELD_RAYQUAZA:
        nullsub_18();
        RestoreRayquazaBonusGraphics();
        break;
    case FIELD_SPHEAL:
        nullsub_18();
        RestoreSphealBonusGraphics();
        break;
    }

    switch (gCurrentPinballGame->activeFxType)
    {
    case FX_PIKA_KICKBACK_FIRING:
        if (gCurrentPinballGame->outLanePikaPosition == PIKA_BOTH_SIDES
            && gCurrentPinballGame->outLaneSide == OUTLANE_RIGHT)
        {
            DmaCopy16(3, gPichuKickbackFx_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_PIKA_SAVER_KICKBACK_TILES);
        }
        else
        {
            DmaCopy16(3, gPikachuKickbackFx_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_PIKA_SAVER_KICKBACK_TILES);
        }
        break;
    case FX_AERODACTYL_EGG_DELIVERY:
        DmaCopy16(3, gAerodactlyFlight_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_AERODACTYL_EGG_DELIVERY_TILES);
        break;
    case FX_TOTODILE_EGG_DELIVERY:
        DmaCopy16(3, gTotodileEggDelivery_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_TOTODILE_EGG_DELIVERY_TILES);
        break;
    case FX_MODE_START_BANNER:
        DMA_MODE_BANNER_TILEMAP(gCurrentPinballGame->bannerGfxIndex, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_MODE_TRAVEL_BANNER_TILES);
        break;
    case FX_CATCH_TILE_BURST_1:
        DmaCopy16(3, gCatchTile_BurstStart_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_CATCH_BURST_LIGHTNING_TILES);
        break;
    case FX_CATCH_TILE_BURST_2:
        DmaCopy16(3, gCatchTile_BurstStage2_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_CATCH_BURST_TILE_OUTLINE);
        break;
    case FX_CATCH_TILE_BURST_3:
        DmaCopy16(3, gCatchTile_BurstStage3_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_CATCH_BURST_TILE_FLIGHT);
        break;
    case FX_CATCH_TILE_BURST_4:
        DmaCopy16(3, gCatchTile_BurstStage4_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_CATCH_BURST_TILE_ELECTRIC);
        break;
    case FX_CAPTURE_MON_ABSORB:
        DmaCopy16(3, gCaptureScreenTilesGfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_MON_CATCH_CUTSCENE_TILES);
        break;
    case FX_CATCH_MON_REVEAL_PUFF:
        DmaCopy16(3, gCatchMonAppearFx_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_MON_APPEAR_CLOUD_BURST_TILES);
        break;
    case FX_SEQUENTIAL_CATCH_TILE:
        DmaCopy16(3, gCatchTile_RevealTilesGfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_CATCH_REAVEAL_SEQUENTIAL_TILES);
        break;
    case FX_FIRST_AREA_SELECTION:
        DmaCopy16(3, gAreaRouletteSelectedFx_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_AREA_ROULETTE_SELECTED_TILES);
        break;
    case FX_MON_SELECTION_NAME:
        RESTORE_SPECIES_NAME_TILES_LANG();
        DMA_MART_EVO_FOREGROUND_UX();
        break;
    case FX_MON_WAS_CAUGHT_CUTSCENE:
        RESTORE_SPECIES_NAME_TILES_LANG();

        RESTORE_CAUGHT_TEXT_TILES_LANG();
        break;
    case FX_EVO_ITEM_SPAWN:
        DMA_EVO_ITEM_APPEAR_GFX(gCurrentPinballGame->evoItemGfxIndex, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_EVO_ITEM_SPAWN_TILES);
        break;
    case FX_EVOLUTION_CUTSCENE:
        DMA_EVOLUTION_CUTSCENE_TILES(OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_EVO_CUTSCENE_TILES);
        break;
    case FX_END_OF_EVO_LIGHTNING:
        DmaCopy16(3, gCatchTile_BurstStage4_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_CATCH_BURST_TILE_ELECTRIC);
        break;
    case FX_SHOP_EVO_SELECTION:
        DMA_MART_EVO_FOREGROUND_UX();
        if (!gCurrentPinballGame->evolutionShopActive)
        {
            var1 = gShopItemData[gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor]];
            var2 = LEAD_DIGIT_10S(var1[3]);
            DmaCopy16(3, gDecimalDigitTilesGfx[var2], OBJ_VRAM_ADDR_MART_PRICE_TENS_DIGIT_TILES, SIZE_OF_VRAM_MART_PRICE_DIGIT);
            var3 = DIGIT_1S(var1[3]);
            DmaCopy16(3, gDecimalDigitTilesGfx[var3], OBJ_VRAM_ADDR_MART_PRICE_ONES_DIGIT_TILES, SIZE_OF_VRAM_MART_PRICE_DIGIT);
        }
        break;
    case FX_BALL_SAVED_CUTSCENE:
        DMA_LANG5(gMainBoardBallSave_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_BALL_SAVER_BANNER_AND_MON_TILES);
        break;
    case FX_END_OF_BALL_SUMMARY:
        DMA_LANG5(gMainBoardEndOfBall_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_END_OF_BALL_BONUS_WINDOW_TILES);
        break;
    case FX_TRAVEL_PAINTER_CUTSCENE:
        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gRubyTravelPaint_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_TRAVEL_CUTSCENE);
            DmaCopy16(3, gRubyPainter_Pals, OBJ_PLTT_SLOT(PAL_IX_TRAVEL_PAINTER), PLTT_SLOT_SIZE);
        }
        else
        {
            DmaCopy16(3, gSapphireTravelPaint_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_TRAVEL_CUTSCENE);
            DmaCopy16(3, gSapphirePainter_Pals, OBJ_PLTT_SLOT(PAL_IX_TRAVEL_PAINTER), PLTT_SLOT_SIZE);
        }
        break;
    case FX_ZIGZAGOON_ROULETTE_STOP:
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_ZIGZAGZOON_ROULETTE_STOP_TILES);
        break;
    }
}

// TODO: fakematch.
#if defined(EUROPE) && !defined(NONMATCHING)
// The European build differs in register allocation / cross-jumping; use the original code.
NAKED
void RestoreMainFieldDynamicGraphics(void)
{
    asm_unified(
	"\tpush {r4, r5, r6, r7, lr}\n"
	"\tmov r7, sl\n"
	"\tmov r6, sb\n"
	"\tmov r5, r8\n"
	"\tpush {r5, r6, r7}\n"
	"\tsub sp, #8\n"
	"\tbl LoadCatchSpriteGraphics\n"
	"\tbl LoadMonFieldSpriteGraphics\n"
	"\tmovs r1, #0\n"
	"\tldr r0, _0805194C\n"
	"\tldr r4, [r0]\n"
	"\tldr r3, _08051950\n"
	"\tmov sb, r0\n"
	"_0805183E:\tlsls r2, r1, #0x10\n"
	"\tasrs r2, r2, #0x10\n"
	"\tlsls r0, r2, #1\n"
	"\tadds r0, r0, r2\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r0, r4, r0\n"
	"\tldr r1, _08051954\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsrs r1, r0, #0x1F\n"
	"\tadds r0, r0, r1\n"
	"\tasrs r0, r0, #1\n"
	"\tlsls r0, r0, #9\n"
	"\tldr r1, _08051958\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r3]\n"
	"\tlsls r0, r2, #9\n"
	"\tldr r5, _0805195C\n"
	"\tadds r0, r0, r5\n"
	"\tstr r0, [r3, #4]\n"
	"\tldr r0, _08051960\n"
	"\tstr r0, [r3, #8]\n"
	"\tldr r0, [r3, #8]\n"
	"\tadds r2, #1\n"
	"\tlsls r2, r2, #0x10\n"
	"\tlsrs r1, r2, #0x10\n"
	"\tasrs r2, r2, #0x10\n"
	"\tcmp r2, #1\n"
	"\tble _0805183E\n"
	"\tmov r1, sb\n"
	"\tldr r0, [r1]\n"
	"\tldr r2, _08051964\n"
	"\tadds r0, r0, r2\n"
	"\tldr r0, [r0]\n"
	"\tldrh r0, [r0, #0xA]\n"
	"\tldr r2, _08051950\n"
	"\tlsrs r0, r0, #0xC\n"
	"\tlsls r0, r0, #7\n"
	"\tldr r1, _08051968\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _0805196C\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08051970\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tmovs r1, #0\n"
	"\tldr r5, _08051974\n"
	"\tldr r6, _08051978\n"
	"\tldr r7, _0805197C\n"
	"\tldr r3, _08051980\n"
	"\tmov sl, r3\n"
	"\tadds r3, r2, #0\n"
	"\tmov r2, sb\n"
	"\tldr r0, [r2]\n"
	"\tldr r2, _08051984\n"
	"\tadds r4, r0, r2\n"
	"_080518B4:\tlsls r2, r1, #0x10\n"
	"\tasrs r2, r2, #0x10\n"
	"\tadds r0, r4, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #7\n"
	"\tadds r0, r0, r5\n"
	"\tstr r0, [r3]\n"
	"\tlsls r0, r2, #1\n"
	"\tadds r0, r0, r2\n"
	"\tlsls r0, r0, #7\n"
	"\tldr r1, _08051988\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r3, #4]\n"
	"\tldr r0, _0805198C\n"
	"\tstr r0, [r3, #8]\n"
	"\tldr r0, [r3, #8]\n"
	"\tadds r2, #1\n"
	"\tlsls r2, r2, #0x10\n"
	"\tlsrs r1, r2, #0x10\n"
	"\tasrs r2, r2, #0x10\n"
	"\tcmp r2, #1\n"
	"\tble _080518B4\n"
	"\tmov r2, sb\n"
	"\tldr r0, [r2]\n"
	"\tldr r3, _08051990\n"
	"\tadds r0, r0, r3\n"
	"\tldr r2, _08051950\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #3\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #5\n"
	"\tadds r0, r0, r6\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _08051994\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08051998\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tmovs r1, #0xE5\n"
	"\tlsls r1, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tldrh r3, [r0]\n"
	"\tstr r3, [sp]\n"
	"\tmovs r5, #0\n"
	"\tldrsh r0, [r0, r5]\n"
	"\tlsls r0, r0, #7\n"
	"\tadds r0, r0, r7\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _0805199C\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08051970\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tmovs r1, #0\n"
	"_0805192A:\tmov r2, sb\n"
	"\tldr r0, [r2]\n"
	"\tlsls r2, r1, #0x10\n"
	"\tasrs r1, r2, #0x10\n"
	"\tldr r3, _080519A0\n"
	"\tadds r0, r0, r3\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tadds r7, r2, #0\n"
	"\tcmp r0, #9\n"
	"\tbls _08051942\n"
	"\tb _08052066\n"
	"_08051942:\tlsls r0, r0, #2\n"
	"\tldr r1, _080519A4\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"_0805194C:\t.4byte gCurrentPinballGame\n"
	"_08051950:\t.4byte 0x40000D4\n"
	"_08051954:\t.4byte 0x13BC\n"
	"_08051958:\t.4byte gFlipper_Gfx\n"
	"_0805195C:\t.4byte 0x6010000\n"
	"_08051960:\t.4byte 0x80000100\n"
	"_08051964:\t.4byte 0x132C\n"
	"_08051968:\t.4byte gBallRotationTileGraphics\n"
	"_0805196C:\t.4byte 0x6010400\n"
	"_08051970:\t.4byte 0x80000040\n"
	"_08051974:\t.4byte gPikachuSaverTilesGfx\n"
	"_08051978:\t.4byte gMainBoardPikaSpinner_Gfx\n"
	"_0805197C:\t.4byte gChargeFillIndicator_Gfx\n"
	"_08051980:\t.4byte gMain + 0x74\n"
	"_08051984:\t.4byte 0x744\n"
	"_08051988:\t.4byte 0x6010480\n"
	"_0805198C:\t.4byte 0x800000C0\n"
	"_08051990:\t.4byte 0x1E5\n"
	"_08051994:\t.4byte 0x6010780\n"
	"_08051998:\t.4byte 0x80000090\n"
	"_0805199C:\t.4byte 0x6010AE0\n"
	"_080519A0:\t.4byte 0x747\n"
	"_080519A4:\t.4byte _080519A8\n"
	"_080519A8:\t.4byte _080519D0 @ case 0\n"
	"\t.4byte _080519F8 @ case 1\n"
	"\t.4byte _08051AC8 @ case 2\n"
	"\t.4byte _08051C86 @ case 3\n"
	"\t.4byte _08051CFC @ case 4\n"
	"\t.4byte _08052066 @ case 5\n"
	"\t.4byte _08051DCC @ case 6\n"
	"\t.4byte _08051E9C @ case 7\n"
	"\t.4byte _08051F6C @ case 8\n"
	"\t.4byte _08051B98 @ case 9\n"
	"_080519D0:\tldr r3, _080519EC\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _080519F0\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _080519F4\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_080519EC:\t.4byte 0x40000D4\n"
	"_080519F0:\t.4byte 0x749\n"
	"_080519F4:\t.4byte gLocationPortraitGfx\n"
	"_080519F8:\tmov r0, sl\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _08051A04\n"
	"\tb _08052066\n"
	"_08051A04:\tlsls r0, r0, #2\n"
	"\tldr r1, _08051A10\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\tmovs r0, r0\n"
	"_08051A10:\t.4byte _08051A14\n"
	"_08051A14:\t.4byte _08051A28 @ case 0\n"
	"\t.4byte _08051A50 @ case 1\n"
	"\t.4byte _08051A78 @ case 2\n"
	"\t.4byte _08051AA0 @ case 3\n"
	"\t.4byte _08052038 @ case 4\n"
	"_08051A28:\tldr r3, _08051A44\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051A48\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051A4C\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051A44:\t.4byte 0x40000D4\n"
	"_08051A48:\t.4byte 0x749\n"
	"_08051A4C:\t.4byte gPortraitAnimFrameGraphics_En\n"
	"_08051A50:\tldr r3, _08051A6C\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051A70\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051A74\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051A6C:\t.4byte 0x40000D4\n"
	"_08051A70:\t.4byte 0x749\n"
	"_08051A74:\t.4byte gPortraitAnimFrameGraphics_Fr\n"
	"_08051A78:\tldr r3, _08051A94\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051A98\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051A9C\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051A94:\t.4byte 0x40000D4\n"
	"_08051A98:\t.4byte 0x749\n"
	"_08051A9C:\t.4byte gPortraitAnimFrameGraphics_De\n"
	"_08051AA0:\tldr r3, _08051ABC\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051AC0\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051AC4\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051ABC:\t.4byte 0x40000D4\n"
	"_08051AC0:\t.4byte 0x749\n"
	"_08051AC4:\t.4byte gPortraitAnimFrameGraphics_It\n"
	"_08051AC8:\tmov r0, sl\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _08051AD4\n"
	"\tb _08052066\n"
	"_08051AD4:\tlsls r0, r0, #2\n"
	"\tldr r1, _08051AE0\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\tmovs r0, r0\n"
	"_08051AE0:\t.4byte _08051AE4\n"
	"_08051AE4:\t.4byte _08051AF8 @ case 0\n"
	"\t.4byte _08051B20 @ case 1\n"
	"\t.4byte _08051B48 @ case 2\n"
	"\t.4byte _08051B70 @ case 3\n"
	"\t.4byte _08052038 @ case 4\n"
	"_08051AF8:\tldr r3, _08051B14\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051B18\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051B1C\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051B14:\t.4byte 0x40000D4\n"
	"_08051B18:\t.4byte 0x749\n"
	"_08051B1C:\t.4byte gPortraitAnimFrameGraphics_En\n"
	"_08051B20:\tldr r3, _08051B3C\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051B40\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051B44\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051B3C:\t.4byte 0x40000D4\n"
	"_08051B40:\t.4byte 0x749\n"
	"_08051B44:\t.4byte gPortraitAnimFrameGraphics_Fr\n"
	"_08051B48:\tldr r3, _08051B64\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051B68\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051B6C\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051B64:\t.4byte 0x40000D4\n"
	"_08051B68:\t.4byte 0x749\n"
	"_08051B6C:\t.4byte gPortraitAnimFrameGraphics_De\n"
	"_08051B70:\tldr r3, _08051B8C\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051B90\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051B94\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051B8C:\t.4byte 0x40000D4\n"
	"_08051B90:\t.4byte 0x749\n"
	"_08051B94:\t.4byte gPortraitAnimFrameGraphics_It\n"
	"_08051B98:\tmov r5, sb\n"
	"\tldr r4, [r5]\n"
	"\tmovs r1, #0x97\n"
	"\tlsls r1, r1, #2\n"
	"\tadds r0, r4, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tble _08051C38\n"
	"\tldr r2, _08051BCC\n"
	"\tadds r0, r4, r2\n"
	"\tldrh r3, [r0]\n"
	"\tmov r5, sl\n"
	"\tadds r0, r3, r5\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbne _08051BD4\n"
	"\tasrs r3, r7, #0x10\n"
	"\tldr r2, _08051BD0\n"
	"\tadds r0, r4, r2\n"
	"\tadds r0, r0, r3\n"
	"\tmovs r1, #0xCD\n"
	"\tstrb r1, [r0]\n"
	"\tb _08051C4A\n"
	"\tmovs r0, r0\n"
	"_08051BCC:\t.4byte 0x59A\n"
	"_08051BD0:\t.4byte 0x749\n"
	"_08051BD4:\tcmp r0, #3\n"
	"\tbhi _08051C10\n"
	"\tasrs r1, r7, #0x10\n"
	"\tldr r2, _08051BFC\n"
	"\tadds r0, r4, r2\n"
	"\tadds r0, r0, r1\n"
	"\tstrb r3, [r0]\n"
	"\tldr r1, _08051C00\n"
	"\tldr r0, _08051C04\n"
	"\tldr r0, [r0]\n"
	"\tmovs r3, #0xF0\n"
	"\tlsls r3, r3, #1\n"
	"\tadds r0, r0, r3\n"
	"\tstr r0, [r1]\n"
	"\tldr r0, _08051C08\n"
	"\tstr r0, [r1, #4]\n"
	"\tldr r0, _08051C0C\n"
	"\tstr r0, [r1, #8]\n"
	"\tldr r0, [r1, #8]\n"
	"\tb _08051C86\n"
	"_08051BFC:\t.4byte 0x749\n"
	"_08051C00:\t.4byte 0x40000D4\n"
	"_08051C04:\t.4byte gMonPortraitGroupPals\n"
	"_08051C08:\t.4byte 0x50003A0\n"
	"_08051C0C:\t.4byte 0x80000010\n"
	"_08051C10:\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051C2C\n"
	"\tadds r0, r4, r1\n"
	"\tadds r0, r0, r2\n"
	"\tstrb r3, [r0]\n"
	"\tldr r6, _08051C30\n"
	"\tldr r5, _08051C34\n"
	"\tmov r8, r5\n"
	"\tmov r3, sb\n"
	"\tldr r0, [r3]\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tb _08051C58\n"
	"\tmovs r0, r0\n"
	"_08051C2C:\t.4byte 0x749\n"
	"_08051C30:\t.4byte 0x40000D4\n"
	"_08051C34:\t.4byte gMonPortraitGroupPals\n"
	"_08051C38:\tasrs r3, r7, #0x10\n"
	"\tldr r2, _08051CDC\n"
	"\tadds r1, r4, r2\n"
	"\tadds r1, r1, r3\n"
	"\tmovs r5, #0xB3\n"
	"\tlsls r5, r5, #3\n"
	"\tadds r0, r4, r5\n"
	"\tldrh r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"_08051C4A:\tldr r6, _08051CE0\n"
	"\tldr r0, _08051CE4\n"
	"\tmov r8, r0\n"
	"\tmov r1, sb\n"
	"\tldr r0, [r1]\n"
	"\tadds r0, r0, r2\n"
	"\tadds r0, r0, r3\n"
	"_08051C58:\tldrb r5, [r0]\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0xF\n"
	"\tbl __udivsi3\n"
	"\tadds r4, r0, #0\n"
	"\tlsls r4, r4, #0x18\n"
	"\tlsrs r4, r4, #0x16\n"
	"\tadd r4, r8\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0xF\n"
	"\tbl __umodsi3\n"
	"\tlsls r0, r0, #0x18\n"
	"\tlsrs r0, r0, #0x13\n"
	"\tldr r1, [r4]\n"
	"\tadds r1, r1, r0\n"
	"\tstr r1, [r6]\n"
	"\tldr r0, _08051CE8\n"
	"\tstr r0, [r6, #4]\n"
	"\tldr r0, _08051CEC\n"
	"\tstr r0, [r6, #8]\n"
	"\tldr r0, [r6, #8]\n"
	"_08051C86:\tldr r2, _08051CE0\n"
	"\tldr r3, _08051CF0\n"
	"\tmov r8, r3\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r6, r7, #0x10\n"
	"\tldr r1, _08051CDC\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r6\n"
	"\tldrb r5, [r0]\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0xF\n"
	"\tstr r2, [sp, #4]\n"
	"\tbl __udivsi3\n"
	"\tadds r4, r0, #0\n"
	"\tlsls r4, r4, #0x18\n"
	"\tlsrs r4, r4, #0x16\n"
	"\tadd r4, r8\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0xF\n"
	"\tbl __umodsi3\n"
	"\tlsls r0, r0, #0x18\n"
	"\tlsrs r0, r0, #0x18\n"
	"\tlsls r1, r0, #1\n"
	"\tadds r1, r1, r0\n"
	"\tlsls r1, r1, #8\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, r0, r1\n"
	"\tldr r2, [sp, #4]\n"
	"\tstr r0, [r2]\n"
	"\tlsls r0, r6, #1\n"
	"\tadds r0, r0, r6\n"
	"\tlsls r0, r0, #3\n"
	"\tldr r3, _08051CF4\n"
	"\tadds r0, r0, r3\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08051CF8\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tb _08052066\n"
	"\tmovs r0, r0\n"
	"_08051CDC:\t.4byte 0x749\n"
	"_08051CE0:\t.4byte 0x40000D4\n"
	"_08051CE4:\t.4byte gMonPortraitGroupPals\n"
	"_08051CE8:\t.4byte 0x50003A0\n"
	"_08051CEC:\t.4byte 0x80000010\n"
	"_08051CF0:\t.4byte gMonPortraitGroupGfx\n"
	"_08051CF4:\t.4byte 0x6010CA0\n"
	"_08051CF8:\t.4byte 0x80000180\n"
	"_08051CFC:\tmov r0, sl\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _08051D08\n"
	"\tb _08052066\n"
	"_08051D08:\tlsls r0, r0, #2\n"
	"\tldr r1, _08051D14\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\tmovs r0, r0\n"
	"_08051D14:\t.4byte _08051D18\n"
	"_08051D18:\t.4byte _08051D2C @ case 0\n"
	"\t.4byte _08051D54 @ case 1\n"
	"\t.4byte _08051D7C @ case 2\n"
	"\t.4byte _08051DA4 @ case 3\n"
	"\t.4byte _08052038 @ case 4\n"
	"_08051D2C:\tldr r3, _08051D48\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051D4C\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051D50\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051D48:\t.4byte 0x40000D4\n"
	"_08051D4C:\t.4byte 0x749\n"
	"_08051D50:\t.4byte gPortraitAnimFrameGraphics_En\n"
	"_08051D54:\tldr r3, _08051D70\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051D74\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051D78\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051D70:\t.4byte 0x40000D4\n"
	"_08051D74:\t.4byte 0x749\n"
	"_08051D78:\t.4byte gPortraitAnimFrameGraphics_Fr\n"
	"_08051D7C:\tldr r3, _08051D98\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051D9C\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051DA0\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051D98:\t.4byte 0x40000D4\n"
	"_08051D9C:\t.4byte 0x749\n"
	"_08051DA0:\t.4byte gPortraitAnimFrameGraphics_De\n"
	"_08051DA4:\tldr r3, _08051DC0\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051DC4\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051DC8\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051DC0:\t.4byte 0x40000D4\n"
	"_08051DC4:\t.4byte 0x749\n"
	"_08051DC8:\t.4byte gPortraitAnimFrameGraphics_It\n"
	"_08051DCC:\tmov r0, sl\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _08051DD8\n"
	"\tb _08052066\n"
	"_08051DD8:\tlsls r0, r0, #2\n"
	"\tldr r1, _08051DE4\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\tmovs r0, r0\n"
	"_08051DE4:\t.4byte _08051DE8\n"
	"_08051DE8:\t.4byte _08051DFC @ case 0\n"
	"\t.4byte _08051E24 @ case 1\n"
	"\t.4byte _08051E4C @ case 2\n"
	"\t.4byte _08051E74 @ case 3\n"
	"\t.4byte _08052038 @ case 4\n"
	"_08051DFC:\tldr r3, _08051E18\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051E1C\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051E20\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051E18:\t.4byte 0x40000D4\n"
	"_08051E1C:\t.4byte 0x749\n"
	"_08051E20:\t.4byte gPortraitAnimFrameGraphics_En\n"
	"_08051E24:\tldr r3, _08051E40\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051E44\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051E48\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051E40:\t.4byte 0x40000D4\n"
	"_08051E44:\t.4byte 0x749\n"
	"_08051E48:\t.4byte gPortraitAnimFrameGraphics_Fr\n"
	"_08051E4C:\tldr r3, _08051E68\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051E6C\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051E70\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051E68:\t.4byte 0x40000D4\n"
	"_08051E6C:\t.4byte 0x749\n"
	"_08051E70:\t.4byte gPortraitAnimFrameGraphics_De\n"
	"_08051E74:\tldr r3, _08051E90\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051E94\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051E98\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051E90:\t.4byte 0x40000D4\n"
	"_08051E94:\t.4byte 0x749\n"
	"_08051E98:\t.4byte gPortraitAnimFrameGraphics_It\n"
	"_08051E9C:\tmov r0, sl\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _08051EA8\n"
	"\tb _08052066\n"
	"_08051EA8:\tlsls r0, r0, #2\n"
	"\tldr r1, _08051EB4\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\tmovs r0, r0\n"
	"_08051EB4:\t.4byte _08051EB8\n"
	"_08051EB8:\t.4byte _08051ECC @ case 0\n"
	"\t.4byte _08051EF4 @ case 1\n"
	"\t.4byte _08051F1C @ case 2\n"
	"\t.4byte _08051F44 @ case 3\n"
	"\t.4byte _08052038 @ case 4\n"
	"_08051ECC:\tldr r3, _08051EE8\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051EEC\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051EF0\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051EE8:\t.4byte 0x40000D4\n"
	"_08051EEC:\t.4byte 0x749\n"
	"_08051EF0:\t.4byte gPortraitAnimFrameGraphics_En\n"
	"_08051EF4:\tldr r3, _08051F10\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051F14\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051F18\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051F10:\t.4byte 0x40000D4\n"
	"_08051F14:\t.4byte 0x749\n"
	"_08051F18:\t.4byte gPortraitAnimFrameGraphics_Fr\n"
	"_08051F1C:\tldr r3, _08051F38\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051F3C\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051F40\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051F38:\t.4byte 0x40000D4\n"
	"_08051F3C:\t.4byte 0x749\n"
	"_08051F40:\t.4byte gPortraitAnimFrameGraphics_De\n"
	"_08051F44:\tldr r3, _08051F60\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051F64\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051F68\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051F60:\t.4byte 0x40000D4\n"
	"_08051F64:\t.4byte 0x749\n"
	"_08051F68:\t.4byte gPortraitAnimFrameGraphics_It\n"
	"_08051F6C:\tmov r0, sl\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbhi _08052066\n"
	"\tlsls r0, r0, #2\n"
	"\tldr r1, _08051F80\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"_08051F80:\t.4byte _08051F84\n"
	"_08051F84:\t.4byte _08051F98 @ case 0\n"
	"\t.4byte _08051FC0 @ case 1\n"
	"\t.4byte _08051FE8 @ case 2\n"
	"\t.4byte _08052010 @ case 3\n"
	"\t.4byte _08052038 @ case 4\n"
	"_08051F98:\tldr r3, _08051FB4\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051FB8\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051FBC\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051FB4:\t.4byte 0x40000D4\n"
	"_08051FB8:\t.4byte 0x749\n"
	"_08051FBC:\t.4byte gPortraitAnimFrameGraphics_En\n"
	"_08051FC0:\tldr r3, _08051FDC\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08051FE0\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08051FE4\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08051FDC:\t.4byte 0x40000D4\n"
	"_08051FE0:\t.4byte 0x749\n"
	"_08051FE4:\t.4byte gPortraitAnimFrameGraphics_Fr\n"
	"_08051FE8:\tldr r3, _08052004\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08052008\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _0805200C\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_08052004:\t.4byte 0x40000D4\n"
	"_08052008:\t.4byte 0x749\n"
	"_0805200C:\t.4byte gPortraitAnimFrameGraphics_De\n"
	"_08052010:\tldr r3, _0805202C\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08052030\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08052034\n"
	"\tb _08052050\n"
	"\tmovs r0, r0\n"
	"_0805202C:\t.4byte 0x40000D4\n"
	"_08052030:\t.4byte 0x749\n"
	"_08052034:\t.4byte gPortraitAnimFrameGraphics_It\n"
	"_08052038:\tldr r3, _08052094\n"
	"\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tasrs r2, r7, #0x10\n"
	"\tldr r1, _08052098\n"
	"\tadds r0, r0, r1\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _0805209C\n"
	"_08052050:\tadds r0, r0, r1\n"
	"\tstr r0, [r3]\n"
	"\tlsls r0, r2, #1\n"
	"\tadds r0, r0, r2\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r2, _080520A0\n"
	"\tadds r0, r0, r2\n"
	"\tstr r0, [r3, #4]\n"
	"\tldr r0, _080520A4\n"
	"\tstr r0, [r3, #8]\n"
	"\tldr r0, [r3, #8]\n"
	"_08052066:\tmovs r3, #0x80\n"
	"\tlsls r3, r3, #9\n"
	"\tadds r0, r7, r3\n"
	"\tlsrs r1, r0, #0x10\n"
	"\tasrs r0, r0, #0x10\n"
	"\tcmp r0, #1\n"
	"\tbgt _08052076\n"
	"\tb _0805192A\n"
	"_08052076:\tmov r5, sb\n"
	"\tldr r1, [r5]\n"
	"\tmovs r0, #0x13\n"
	"\tldrsb r0, [r1, r0]\n"
	"\tcmp r0, #4\n"
	"\tbne _08052100\n"
	"\tmovs r0, #0x17\n"
	"\tldrsb r0, [r1, r0]\n"
	"\tcmp r0, #7\n"
	"\tblt _08052100\n"
	"\tcmp r0, #8\n"
	"\tble _080520A8\n"
	"\tcmp r0, #9\n"
	"\tbeq _080520C4\n"
	"\tb _08052100\n"
	"_08052094:\t.4byte 0x40000D4\n"
	"_08052098:\t.4byte 0x749\n"
	"_0805209C:\t.4byte gPortraitAnimFrameGraphics_Es\n"
	"_080520A0:\t.4byte 0x6010CA0\n"
	"_080520A4:\t.4byte 0x80000180\n"
	"_080520A8:\tldr r2, _080520B8\n"
	"\tadds r0, r1, r2\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _080520F0\n"
	"\tldr r1, _080520BC\n"
	"\tldr r0, _080520C0\n"
	"\tb _080520F4\n"
	"_080520B8:\t.4byte 0x5A9\n"
	"_080520BC:\t.4byte 0x40000D4\n"
	"_080520C0:\t.4byte gCatchSpriteGfxBuffer + 0x900\n"
	"_080520C4:\tmovs r3, #0xB5\n"
	"\tlsls r3, r3, #3\n"
	"\tadds r0, r1, r3\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0x1F\n"
	"\tbgt _08052100\n"
	"\tldr r5, _080520E4\n"
	"\tadds r0, r1, r5\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _080520F0\n"
	"\tldr r1, _080520E8\n"
	"\tldr r0, _080520EC\n"
	"\tb _080520F4\n"
	"_080520E4:\t.4byte 0x5A9\n"
	"_080520E8:\t.4byte 0x40000D4\n"
	"_080520EC:\t.4byte gCatchSpriteGfxBuffer + 0x900\n"
	"_080520F0:\tldr r1, _0805211C\n"
	"\tldr r0, _08052120\n"
	"_080520F4:\tstr r0, [r1]\n"
	"\tldr r0, _08052124\n"
	"\tstr r0, [r1, #4]\n"
	"\tldr r0, _08052128\n"
	"\tstr r0, [r1, #8]\n"
	"\tldr r0, [r1, #8]\n"
	"_08052100:\tmov r0, sb\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, #0x13\n"
	"\tldrsb r0, [r1, r0]\n"
	"\tcmp r0, #8\n"
	"\tbne _08052184\n"
	"\tmovs r0, #0x17\n"
	"\tldrsb r0, [r1, r0]\n"
	"\tcmp r0, #2\n"
	"\tbeq _0805212C\n"
	"\tcmp r0, #3\n"
	"\tbeq _08052148\n"
	"\tb _08052184\n"
	"\tmovs r0, r0\n"
	"_0805211C:\t.4byte 0x40000D4\n"
	"_08052120:\t.4byte gCatchSpriteGfxBuffer\n"
	"_08052124:\t.4byte 0x6010CA0\n"
	"_08052128:\t.4byte 0x80000240\n"
	"_0805212C:\tldr r2, _0805213C\n"
	"\tadds r0, r1, r2\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _08052174\n"
	"\tldr r1, _08052140\n"
	"\tldr r0, _08052144\n"
	"\tb _08052178\n"
	"_0805213C:\t.4byte 0x5A9\n"
	"_08052140:\t.4byte 0x40000D4\n"
	"_08052144:\t.4byte gCatchSpriteGfxBuffer + 0x900\n"
	"_08052148:\tmovs r3, #0xB5\n"
	"\tlsls r3, r3, #3\n"
	"\tadds r0, r1, r3\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0x1F\n"
	"\tbgt _08052184\n"
	"\tldr r5, _08052168\n"
	"\tadds r0, r1, r5\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbls _08052174\n"
	"\tldr r1, _0805216C\n"
	"\tldr r0, _08052170\n"
	"\tb _08052178\n"
	"_08052168:\t.4byte 0x5A9\n"
	"_0805216C:\t.4byte 0x40000D4\n"
	"_08052170:\t.4byte gCatchSpriteGfxBuffer + 0x900\n"
	"_08052174:\tldr r1, _080521BC\n"
	"\tldr r0, _080521C0\n"
	"_08052178:\tstr r0, [r1]\n"
	"\tldr r0, _080521C4\n"
	"\tstr r0, [r1, #4]\n"
	"\tldr r0, _080521C8\n"
	"\tstr r0, [r1, #8]\n"
	"\tldr r0, [r1, #8]\n"
	"_08052184:\tldr r2, _080521BC\n"
	"\tmov r1, sb\n"
	"\tldr r0, [r1]\n"
	"\tldr r3, _080521CC\n"
	"\tadds r0, r0, r3\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r5, _080521D0\n"
	"\tadds r0, r0, r5\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _080521D4\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _080521D8\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tmov r0, sl\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbhi _08052280\n"
	"\tlsls r0, r0, #2\n"
	"\tldr r1, _080521DC\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"_080521BC:\t.4byte 0x40000D4\n"
	"_080521C0:\t.4byte gCatchSpriteGfxBuffer\n"
	"_080521C4:\t.4byte 0x6010CA0\n"
	"_080521C8:\t.4byte 0x80000240\n"
	"_080521CC:\t.4byte 0x20B\n"
	"_080521D0:\t.4byte gMainStageBonusTrap_Gfx\n"
	"_080521D4:\t.4byte 0x60113C0\n"
	"_080521D8:\t.4byte 0x80000180\n"
	"_080521DC:\t.4byte _080521E0\n"
	"_080521E0:\t.4byte _080521F4 @ case 0\n"
	"\t.4byte _080521F4 @ case 1\n"
	"\t.4byte _0805221C @ case 2\n"
	"\t.4byte _0805222C @ case 3\n"
	"\t.4byte _08052254 @ case 4\n"
	"_080521F4:\tldr r2, _08052210\n"
	"\tldr r1, _08052214\n"
	"\tmov r3, sb\n"
	"\tldr r0, [r3]\n"
	"\tldr r5, _08052218\n"
	"\tadds r0, r0, r5\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r0, r0, r1\n"
	"\tldr r3, [sp]\n"
	"\tlsls r1, r3, #0x10\n"
	"\tb _0805226E\n"
	"_08052210:\t.4byte 0x40000D4\n"
	"_08052214:\t.4byte gEvoItemTilesGfxPtrs_EnFr\n"
	"_08052218:\t.4byte 0x25F\n"
	"_0805221C:\tldr r2, _08052224\n"
	"\tldr r1, _08052228\n"
	"\tb _08052258\n"
	"\tmovs r0, r0\n"
	"_08052224:\t.4byte 0x40000D4\n"
	"_08052228:\t.4byte gEvoItemTilesGfxPtrs_De\n"
	"_0805222C:\tldr r2, _08052248\n"
	"\tldr r1, _0805224C\n"
	"\tmov r3, sb\n"
	"\tldr r0, [r3]\n"
	"\tldr r5, _08052250\n"
	"\tadds r0, r0, r5\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r0, r0, r1\n"
	"\tldr r3, [sp]\n"
	"\tlsls r1, r3, #0x10\n"
	"\tb _0805226E\n"
	"_08052248:\t.4byte 0x40000D4\n"
	"_0805224C:\t.4byte gEvoItemTilesGfxPtrs_It\n"
	"_08052250:\t.4byte 0x25F\n"
	"_08052254:\tldr r2, _080522DC\n"
	"\tldr r1, _080522E0\n"
	"_08052258:\tmov r5, sb\n"
	"\tldr r0, [r5]\n"
	"\tldr r3, _080522E4\n"
	"\tadds r0, r0, r3\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r0, r0, r1\n"
	"\tldr r5, [sp]\n"
	"\tlsls r1, r5, #0x10\n"
	"_0805226E:\tasrs r1, r1, #7\n"
	"\tldr r0, [r0]\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _080522E8\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _080522EC\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"_08052280:\tmov r1, sb\n"
	"\tldr r0, [r1]\n"
	"\tldr r2, _080522F0\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #3\n"
	"\tldr r1, _080522F4\n"
	"\tadds r1, #6\n"
	"\tadds r0, r0, r1\n"
	"\tldr r1, _080522DC\n"
	"\tmovs r3, #0\n"
	"\tldrsh r0, [r0, r3]\n"
	"\tlsls r0, r0, #9\n"
	"\tldr r5, _080522F8\n"
	"\tadds r0, r0, r5\n"
	"\tstr r0, [r1]\n"
	"\tldr r0, _080522FC\n"
	"\tstr r0, [r1, #4]\n"
	"\tldr r2, _080522EC\n"
	"\tstr r2, [r1, #8]\n"
	"\tldr r0, [r1, #8]\n"
	"\tmov r3, sb\n"
	"\tldr r0, [r3]\n"
	"\tadds r0, #0x6E\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #9\n"
	"\tldr r5, _08052300\n"
	"\tadds r0, r0, r5\n"
	"\tstr r0, [r1]\n"
	"\tldr r0, _08052304\n"
	"\tstr r0, [r1, #4]\n"
	"\tstr r2, [r1, #8]\n"
	"\tldr r0, [r1, #8]\n"
	"\tadd sp, #8\n"
	"\tpop {r3, r4, r5}\n"
	"\tmov r8, r3\n"
	"\tmov sb, r4\n"
	"\tmov sl, r5\n"
	"\tpop {r4, r5, r6, r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\tmovs r0, r0\n"
	"_080522DC:\t.4byte 0x40000D4\n"
	"_080522E0:\t.4byte gEvoItemTilesGfxPtrs_Es\n"
	"_080522E4:\t.4byte 0x25F\n"
	"_080522E8:\t.4byte 0x60116C0\n"
	"_080522EC:\t.4byte 0x80000100\n"
	"_080522F0:\t.4byte 0x1ED\n"
	"_080522F4:\t.4byte gEggAnimationFrameData\n"
	"_080522F8:\t.4byte gEggFrameTilesGfx\n"
	"_080522FC:\t.4byte 0x6011CE0\n"
	"_08052300:\t.4byte gBallUpgradeFx_Gfx\n"
	"_08052304:\t.4byte 0x6011EE0\n"
    );
}
#else
void RestoreMainFieldDynamicGraphics(void)
{
    s16 i;
    s16 var0;

    LoadCatchSpriteGraphics();
    LoadMonFieldSpriteGraphics();

    for (i = 0; i < SIDE_COUNT; i++)
    {
        var0 = gCurrentPinballGame->flipper[i].position / 2;
        DmaCopy16(3, gFlipper_Gfx[var0], OBJ_VRAM_ADDR_FLIPPER_LEFT_TILES + i * SIZE_OF_VRAM_FLIPPER_TILES, SIZE_OF_VRAM_FLIPPER_TILES);
    }

    var0 = gCurrentPinballGame->ball->spinAngle / 0x1000;
    DmaCopy16(3, gBallRotationTileGraphics[var0], OBJ_VRAM_ADDR_BALL_TILES, SIZE_OF_VRAM_BALL_TILES);

    for (i = 0; i <= 1; i++)
    {
        DmaCopy16(3, gPikachuSaverTilesGfx[var0 =gCurrentPinballGame->pikaSaverTileIndex[i]], OBJ_VRAM_ADDR_PIKA_MON_AT_LEFT_SIDE_TILES + i * SIZE_OF_VRAM_PIKA_MON_TILES, SIZE_OF_VRAM_PIKA_MON_TILES);
    }

    var0 = gCurrentPinballGame->pikachuSpinFrame;
    DmaCopy16(3, gMainBoardPikaSpinner_Gfx[var0 = gCurrentPinballGame->pikachuSpinFrame], OBJ_VRAM_ADDR_PIKA_CHARGE_SPINNER_TILES, SIZE_OF_VRAM_PIKA_CHARGE_SPINNER_TILES);
    var0 = gCurrentPinballGame->chargeFillValue;
    DmaCopy16(3, gChargeFillIndicator_Gfx[var0], OBJ_VRAM_ADDR_CHARGE_INDICATOR_CIRCLE_TILES, SIZE_OF_VRAM_CHARGE_INDICATOR_CIRCLE_TILES);

    for (i = 0; i <= 1; i++)
    {
#ifdef EUROPE
        switch (gCurrentPinballGame->portraitRenderMode[i])
        {
        case PORTRAIT_STATE_CURRENT_LOCATION:
            DmaCopy16(3, gLocationPortraitGfx[gCurrentPinballGame->portraitGfxIndex[i]], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES, SIZE_OF_VRAM_PORTRAIT_TILES);
            gCurrentPinballGame->ball += 0; //TODO: Dumb match is still a match...
            break;
        case PORTRAIT_STATE_SLOT_START_CARD:
            DMA_PORTRAIT_ANIM_FRAME(gCurrentPinballGame->portraitGfxIndex[i], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        case PORTRAIT_STATE_ROULETTE_WHEEL:
            DMA_PORTRAIT_ANIM_FRAME(gCurrentPinballGame->portraitGfxIndex[i], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        case PORTRAIT_STATE_EVO_PREVIEW:
            if (gCurrentPinballGame->evoChainPosition > 0)
            {
                if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == SPECIES_DEX_UNSEEN)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = 205;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15][gCurrentPinballGame->portraitGfxIndex[i] % 15], OBJ_PLTT_SLOT(PAL_IX_MON_PORTRAIT), PLTT_SLOT_SIZE);
                }
                else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] < SPECIES_DEX_CAUGHT)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[0][15], OBJ_PLTT_SLOT(PAL_IX_MON_PORTRAIT), PLTT_SLOT_SIZE);
                }
                else
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15][gCurrentPinballGame->portraitGfxIndex[i] % 15], OBJ_PLTT_SLOT(PAL_IX_MON_PORTRAIT), PLTT_SLOT_SIZE);
                }
            }
            else
            {
                gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->currentSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15][gCurrentPinballGame->portraitGfxIndex[i] % 15], OBJ_PLTT_SLOT(PAL_IX_LOCATION_PORTRAIT), PLTT_SLOT_SIZE);
            }
        case PORTRAIT_STATE_POKEMON_DISPLAY:
            // Bug: missing the * 0x20; but not a problem since only portrait 0 gets displayed
            DmaCopy16(3, gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x300, OBJ_VRAM_ADDR_PORTRAIT0_TILES + (i * 0x18), SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        case PORTRAIT_STATE_TRAVEL_RAMP_INDICATOR:
            DMA_PORTRAIT_ANIM_FRAME(gCurrentPinballGame->portraitGfxIndex[i], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        case PORTRAIT_STATE_SHOP_SELECTOR:
            DMA_PORTRAIT_ANIM_FRAME(gCurrentPinballGame->portraitGfxIndex[i], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        case PORTRAIT_STATE_CONFIRMATION_PROMPT:
            DMA_PORTRAIT_ANIM_FRAME(gCurrentPinballGame->portraitGfxIndex[i], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        case PORTRAIT_STATE_ROULETTE_OUTCOME:
            DMA_PORTRAIT_ANIM_FRAME(gCurrentPinballGame->portraitGfxIndex[i], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        }
#else
        switch (gCurrentPinballGame->portraitRenderMode[i])
        {
        case PORTRAIT_STATE_CURRENT_LOCATION:
            DmaCopy16(3, gLocationPortraitGfx[gCurrentPinballGame->portraitGfxIndex[i]], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES, SIZE_OF_VRAM_PORTRAIT_TILES);
            gCurrentPinballGame->ball += 0; //TODO: Dumb match is still a match...
            break;
        case PORTRAIT_STATE_EVO_PREVIEW:
            if (gCurrentPinballGame->evoChainPosition > 0)
            {
                if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == SPECIES_DEX_UNSEEN)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = 205;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15][gCurrentPinballGame->portraitGfxIndex[i] % 15], OBJ_PLTT_SLOT(PAL_IX_MON_PORTRAIT), PLTT_SLOT_SIZE);
                }
                else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] < SPECIES_DEX_CAUGHT)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[0][15], OBJ_PLTT_SLOT(PAL_IX_MON_PORTRAIT), PLTT_SLOT_SIZE);
                }
                else
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15][gCurrentPinballGame->portraitGfxIndex[i] % 15], OBJ_PLTT_SLOT(PAL_IX_MON_PORTRAIT), PLTT_SLOT_SIZE);
                }
            }
            else
            {
                gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->currentSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15][gCurrentPinballGame->portraitGfxIndex[i] % 15], OBJ_PLTT_SLOT(PAL_IX_LOCATION_PORTRAIT), PLTT_SLOT_SIZE);
            }
        case PORTRAIT_STATE_POKEMON_DISPLAY:
            // Bug: missing the * 0x20; but not a problem since only portrait 0 gets displayed
            DmaCopy16(3, gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x300, OBJ_VRAM_ADDR_PORTRAIT0_TILES + (i * 0x18), SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        case PORTRAIT_STATE_SLOT_START_CARD:
        case PORTRAIT_STATE_ROULETTE_WHEEL:
        case PORTRAIT_STATE_TRAVEL_RAMP_INDICATOR:
        case PORTRAIT_STATE_SHOP_SELECTOR:
        case PORTRAIT_STATE_CONFIRMATION_PROMPT:
        case PORTRAIT_STATE_ROULETTE_OUTCOME:
            DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[i]], OBJ_VRAM_ADDR_PORTRAIT0_TILES + i * SIZE_OF_VRAM_PORTRAIT_TILES, SIZE_OF_VRAM_PORTRAIT_TILES);
            break;
        }
#endif
    }

    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case CATCH_EM_SUBSTATE_ANIMATE_MON_APPEAR:
        case CATCH_EM_SUBSTATE_SETUP_CATCH_HIT_COUNT:
            if ((u32) gCurrentPinballGame->captureFlashTimer > 4)
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer[2], OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
            }
            else
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
            }
            break;
        case CATCH_EM_SUBSTATE_CATCH_HIT_PHASE:
            if (gCurrentPinballGame->captureSequenceTimer <= 31)
            {
                if (gCurrentPinballGame->captureFlashTimer > 4)
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer[2], OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
                }
                else
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
                }
            }
            break;
        }
    }

    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case JIRACHI_CATCH_SUBSTATE_SETUP_CATCH_HIT_COUNT:
            if (gCurrentPinballGame->captureFlashTimer > 4U)
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer[2], OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
            }
            else
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
            }
            break;
        case JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE:
            if (gCurrentPinballGame->captureSequenceTimer <= 31)
            {
                if (gCurrentPinballGame->captureFlashTimer > 4U)
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer[2], OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
                }
                else
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
                }
            }
            break;
        }
    }

    DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->bonusTrapAnimFrame], OBJ_VRAM_ADDR_FX_CENTER_HOLE_GRAVITY_TILES, SIZE_OF_VRAM_FX_CENTER_HOLE_GRAVITY_TILES);
    DMA_EVO_ITEM_TILES(gCurrentPinballGame->evoItemGfxIndex, var0 * SIZE_OF_VRAM_EVO_ITEM_STABLE_TILE, OBJ_VRAM_ADDR_EVO_ITEM_STABLE_TILE, SIZE_OF_VRAM_EVO_ITEM_STABLE_TILE);
    DmaCopy16(3, gEggFrameTilesGfx[(s16)gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3]], OBJ_VRAM_ADDR_HATCH_EGG_TILES, SIZE_OF_VRAM_HATCH_EGG_TILES);
    DmaCopy16(3, gBallUpgradeFx_Gfx[gCurrentPinballGame->ballUpgradeFxTileIndex], OBJ_VRAM_ADDR_FX_BALL_UPGRADE_TILES_MAIN_BOARD, SIZE_OF_VRAM_FX_BALL_UPGRADE_TILES);
    return;
}
#endif

void RestoreRubyBoardTileGraphics(void)
{
    s16 i;
    s16 var0;

    var0 = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][2];
    DmaCopy16(3, gRubyBoardHatchCave_Gfx[var0], OBJ_VRAM_ADDR_HATCH_CAVE_TILES, SIZE_OF_VRAM_HATCH_CAVE_TILES);
    var0 = (gMain.systemFrameCount % 50) / 25;
    DmaCopy16(3, gRubyChikoritaEntity[var0], OBJ_VRAM_ADDR_CHIKORITA_TILES, SIZE_OF_VRAM_CHIKORITA_TILES);
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->sharpedoNextTileIx], OBJ_VRAM_ADDR_SHARPEDO_TILES, SIZE_OF_VRAM_SHARPEDO_TILES);
    for (i = 0; i < 2; i++)
        DmaCopy16(3, gChinchouBumper_Gfx[var0], OBJ_VRAM_ADDR_RUBY_BUMPER(i), SIZE_OF_VRAM_RUBY_BUMPER_TILES);

    var0 = gCurrentPinballGame->shopDoorCurrentFrame & 0xF;
    DmaCopy16(3, gRubyBoardShopDoor_Gfx[var0], OBJ_VRAM_ADDR_RUBY_MART_DOOR_TILES, SIZE_OF_VRAM_RUBY_MART_DOOR_TILES);
    if (gCurrentPinballGame->cyndaquilPosition < CYNDAQUIL_POSITION_CAVE_ENTRANCE)
        gCurrentPinballGame->cyndaquilFrame = 0;
    else
        gCurrentPinballGame->cyndaquilFrame = 1;

    DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilFrame], OBJ_VRAM_ADDR_CYNDAQUIL_TILES, SIZE_OF_VRAM_CYNDAQUIL_TILES);
    var0 = gEvoShopAnimFrames[gCurrentPinballGame->evolutionShopActive][(gCurrentPinballGame->shopAnimTimer % 42) / 6];
    DMA_LANG5_AT(gRubyBoardShop_Gfx, var0, OBJ_VRAM_ADDR_RUBY_MART_SIGN_TILES, SIZE_OF_VRAM_RUBY_MART_SIGN_TILES);
}

void RestoreSapphireBoardTileGraphics(void)
{
    s16 index;

    switch (gCurrentPinballGame->sapphireHatchMachineState)
    {
    case HATCH_MACHINE_STATE_INCUBATION_LIGHTS:
    case HATCH_MACHINE_STATE_ACTIVATED_LIGHT_CROSS:
    case HATCH_MACHINE_STATE_MON_HATCHED:
        index = gCurrentPinballGame->sapphireHatchMachineFrameIx;
        DmaCopy16(3, gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
        break;
    case HATCH_MACHINE_STATE_ELEVATOR_DECENDS:
    case HATCH_MACHINE_STATE_EMPTY:
        index = 15;
        DmaCopy16(3, gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
        break;
    case HATCH_MACHINE_STATE_EGG_RISING:
        index = gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][0];
        DmaCopy16(3, gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
        break;
    case HATCH_MACHINE_STATE_RESET:
        break;
    }
}

void RestoreDusclopsBonusGraphics(void)
{
    DMA_LANG5(gDusclopsBonusClear_Gfx, OBJ_VRAM_ADDR_DUSCLOPS_BANNER_TILES, SIZE_OF_VRAM_DUSCLOPS_BANNER_TILES);
}

void RestoreKecleonBonusGraphics(void)
{
    DMA_LANG5(gKecleonBonusClear_Gfx, OBJ_VRAM_ADDR_KECLEON_BANNER_TILES, SIZE_OF_VRAM_KECLEON_BANNER_TILES);
}

void RestoreKyogreBonusGraphics(void)
{
    DMA_LANG5(gKyogreBonusClear_Gfx, OBJ_VRAM_ADDR_KYOGRE_BANNER_TILES, SIZE_OF_VRAM_KYOGRE_BANNER_TILES);
    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * SIZE_OF_VRAM_PORTRAIT_TILES,
        OBJ_VRAM_ADDR_PORTRAIT0_TILES,
        SIZE_OF_VRAM_PORTRAIT_TILES
    );
}

void RestoreGroudonBonusGraphics(void)
{
    if (gCurrentPinballGame->boardState <= LEGENDARY_BOARD_STATE_BATTLE_PHASE)
    {
        DmaCopy16(3, gGroudonAttackFx_Gfx, OBJ_VRAM_ADDR_GROUDON_ATTACK_FX_TILES, SIZE_OF_VRAM_GROUDON_ATTACK_FX_TILES);
    }
    else
    {
        DMA_LANG5(gGroudonBonusClear_Gfx, OBJ_VRAM_ADDR_GROUDON_BANNER_TILES, SIZE_OF_VRAM_GROUDON_BANNER_TILES);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * SIZE_OF_VRAM_PORTRAIT_TILES,
        OBJ_VRAM_ADDR_PORTRAIT0_TILES,
        SIZE_OF_VRAM_PORTRAIT_TILES
    );
}

void RestoreRayquazaBonusGraphics(void)
{
    u8 var0;

    if (gCurrentPinballGame->boardState == LEGENDARY_BOARD_STATE_INTRO)
    {
        DmaCopy16(3, gRayquazaSkyBackgroundGfx, OBJ_VRAM_ADDR_RAYQUAZA_INTRO_CLOUDS_TILES, SIZE_OF_VRAM_RAYQUAZA_INTRO_CLOUDS_TILES);
    }
    else if (gCurrentPinballGame->boardState == LEGENDARY_BOARD_STATE_BATTLE_PHASE)
    {
        DmaCopy16(3, gRayquazaFlyby_Gfx, OBJ_VRAM_ADDR_RAYQUAZA_FLYBY_TILES, SIZE_OF_VRAM_RAYQUAZA_FLYBY_TILES);
    }
    else
    {
        DMA_LANG5(gRayquazaBonusClear_Gfx, OBJ_VRAM_ADDR_RAYQUAZA_BANNER_TILES, SIZE_OF_VRAM_RAYQUAZA_BANNER_TILES);
    }

    var0 = gCurrentPinballGame->bossEntityState - 2;
    if (var0 > 9) // bossEntityState > RAYQUAZA_ENTITY_STATE_DEPARTS
    {
        DmaCopy16(3, gRayquazaSpriteSheet, OBJ_VRAM_ADDR_RAYQUAZA_TILES, SIZE_OF_VRAM_RAYQUAZA_TILES);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * SIZE_OF_VRAM_PORTRAIT_TILES,
        OBJ_VRAM_ADDR_PORTRAIT0_TILES,
        SIZE_OF_VRAM_PORTRAIT_TILES
    );
}

void RestoreSphealBonusGraphics(void)
{
    s16 i;
    int var0;
    u16 var1;

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[0x400 + i] = 0x200;

    DmaCopy16(3, &gBG0TilemapBuffer[0x400], BG_VRAM_ADDR_SPHEAL_LAYER_1_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        var0 = i;
        if (i < 0)
            var0 += 31;

        var0 = (var0 >> 5) << 5;
        var1 = i - var0 - 2;
        if (var1 < 28)
            gBG0TilemapBuffer[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].xOffset = 8;
    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gBG0TilemapBuffer[0x800], BG_VRAM_ADDR_SPHEAL_TBD_TILEMAP, SIZE_OF_VRAM_SPHEAL_TBD_TILEMAP);
    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DMA_LANG4_ENFR(gSphealResultsScreenGfx, OBJ_VRAM_ADDR_SPHEAL_SUMMARY_TILES, SIZE_OF_VRAM_SPHEAL_SUMMARY_TILES);
}

void nullsub_18(void)
{
}
