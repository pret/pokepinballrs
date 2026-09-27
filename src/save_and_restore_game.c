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

extern u8 gBoardBGTileBuffer[];
extern u8 gBoardBGTileBufferAlt[];
extern const u8 gMainBoardBallSave_Gfx[];
extern const u8 gMainBoardEndOfBall_Gfx[];
extern const u8 gEvolutionCutsceneTilesGfx[];

extern const u8 gAerodactlyFlight_Gfx[];
extern const u8 gAreaRouletteSelectedFx_Gfx[];

extern const u8 gTotodileEggDelivery_Gfx[];
extern const u8 gCaptureScreenTilesGfx[];

extern const u8 gCatchTile_RevealTilesGfx[];
extern const u8 gCatchTile_BurstStart_Gfx[];
extern const u8 gCatchTile_BurstStage2_Gfx[];
extern const u8 gCatchTile_BurstStage3_Gfx[];
extern const u8 gCatchTile_BurstStage4_Gfx[];

extern const u8 *gEvoItemAppear_GfxList[];
extern const s16 gEvoShopAnimFrames[][7];
extern const u16 gShopCursorToItemMap[];

extern const u8 gRubyTravelPaint_Gfx[];
extern const Palette gRubyPainter_Pals;
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u8 gRubyChikoritaEntity[][0x300];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const u8 gChinchouBumper_Gfx[][0x100];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardShop_Gfx[][0x500];

extern const u8 gSapphireTravelPaint_Gfx[];
extern const Palette gSapphirePainter_Pals;
extern const u8 gCatchMonAppearFx_Gfx[];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];

extern const u8 gAlphabetTilesGfx[][0x40];
extern const u8 gSpaceTileGfx[0x40];
extern const u8 gDecimalDigitTilesGfx[][0x40];
extern const u8 gMartEvoForegroundMenuUx_Gfx[];
extern const s16 gCaughtTextChars[];

extern const u8 gHatchMachineElevator_Gfx[][0x440];
extern const s16 gHoleAnimKeyframeData[][2];

extern const u8 gKecleonBonusClear_Gfx[0x2000];
extern const u8 gKyogreBonusClear_Gfx[0x2000];
extern const u8 gGroudonAttackFx_Gfx[0x2000];
extern const u8 gGroudonBonusClear_Gfx[0x2000];
extern const u8 gRayquazaSkyBackgroundGfx[0x2800];
extern const u8 gRayquazaFlyby_Gfx[0x1C00];
extern const u8 gRayquazaBonusClear_Gfx[0x2000];
extern const u8 gRayquazaSpriteSheet[0x860];
extern const u8 gSphealResultsScreenGfx[0x800];


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
        if (arg0 == 1 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->cameraBaseY +
                                         gCurrentPinballGame->tiltYOffset +
                                         gCurrentPinballGame->cameraScrollOffset +
                                         gCurrentPinballGame->cameraYAdjust;
        }
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
        DmaCopy16(3, gModeBannerTilemaps[gCurrentPinballGame->bannerGfxIndex], OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_MODE_TRAVEL_BANNER_TILES);
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
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            }
            else
            {
                int letterTileIx = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[letterTileIx], OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            }
        }
        DmaCopy16(3, gMartEvoForegroundMenuUx_Gfx, OBJ_VRAM_ADDR_MART_EVO_FOREGROUND_UX_TILES, SIZE_OF_VRAM_MART_EVO_FOREGROUND_UX_TILES);
        break;
    case FX_MON_WAS_CAUGHT_CUTSCENE:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            }
            else
            {
                int letterTileIx = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[letterTileIx], OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            }
        }

        for (i = 0; i < 10; i++)
        {
            if (gCaughtTextChars[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_WAS_CAUGHT_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            }
            else
            {
                int letterTileIx = gCaughtTextChars[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[letterTileIx], OBJ_VRAM_ADDR_WAS_CAUGHT_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            }
        }
        break;
    case FX_EVO_ITEM_SPAWN:
        DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->evoItemGfxIndex], OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_EVO_ITEM_SPAWN_TILES);
        break;
    case FX_EVOLUTION_CUTSCENE:
        DmaCopy16(3, gEvolutionCutsceneTilesGfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_EVO_CUTSCENE_TILES);
        break;
    case FX_END_OF_EVO_LIGHTNING:
        DmaCopy16(3, gCatchTile_BurstStage4_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_CATCH_BURST_TILE_ELECTRIC);
        break;
    case FX_SHOP_EVO_SELECTION:
        DmaCopy16(3, gMartEvoForegroundMenuUx_Gfx, OBJ_VRAM_ADDR_MART_EVO_FOREGROUND_UX_TILES, SIZE_OF_VRAM_MART_EVO_FOREGROUND_UX_TILES);
        if (!gCurrentPinballGame->evolutionShopActive)
        {
            var1 = gShopItemData[gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor]];
            var2 = LEAD_DIGIT_10S(var1[3]);
            DmaCopy16(3, gDecimalDigitTilesGfx[var2], OBJ_VRAM_ADDR_MART_PRICE_TENS_DIGIT_TILES, SIZE_OF_VRAM_LETTER_TILE);
            var3 = DIGIT_1S(var1[3]);
            DmaCopy16(3, gDecimalDigitTilesGfx[var3], OBJ_VRAM_ADDR_MART_PRICE_ONES_DIGIT_TILES, SIZE_OF_VRAM_LETTER_TILE);
        }
        break;
    case FX_BALL_SAVED_CUTSCENE:
        DmaCopy16(3, gMainBoardBallSave_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_BALL_SAVER_BANNER_AND_MON_TILES);
        break;
    case FX_END_OF_BALL_SUMMARY:
        DmaCopy16(3, gMainBoardEndOfBall_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_END_OF_BALL_BONUS_WINDOW_TILES);
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
        DmaCopy16(3, gPikachuSaverTilesGfx + ((var0 =gCurrentPinballGame->pikaSaverTileIndex[i]) * SIZE_OF_VRAM_PIKA_MON_TILES), OBJ_VRAM_ADDR_PIKA_MON_AT_LEFT_SIDE_TILES + i * SIZE_OF_VRAM_PIKA_MON_TILES, SIZE_OF_VRAM_PIKA_MON_TILES);
    }

    var0 = gCurrentPinballGame->pikachuSpinFrame;
    DmaCopy16(3, gMainBoardPikaSpinner_Gfx[var0 = gCurrentPinballGame->pikachuSpinFrame], OBJ_VRAM_ADDR_PIKA_CHARGE_SPINNER_TILES, SIZE_OF_VRAM_PIKA_CHARGE_SPINNER_TILES);
    var0 = gCurrentPinballGame->chargeFillValue;
    DmaCopy16(3, gChargeFillIndicator_Gfx[var0], OBJ_VRAM_ADDR_CHARGE_INDICATOR_CIRCLE_TILES, SIZE_OF_VRAM_CHARGE_INDICATOR_CIRCLE_TILES);

    for (i = 0; i <= 1; i++)
    {
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
    }

    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case CATCH_EM_SUBSTATE_ANIMATE_MON_APPEAR:
        case CATCH_EM_SUBSTATE_SETUP_CATCH_HIT_COUNT:
            if ((u32) gCurrentPinballGame->captureFlashTimer > 4)
            {
                DmaCopy16(3, gCatchSpriteFlashGfx, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
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
                    DmaCopy16(3, gCatchSpriteFlashGfx, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
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
                DmaCopy16(3, gCatchSpriteFlashGfx, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
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
                    DmaCopy16(3, gCatchSpriteFlashGfx, OBJ_VRAM_ADDR_CATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_CATCH_MON_ENTITY_TILES);
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
    DmaCopy16(3, gEvoItemTilesGfxPtrs[gCurrentPinballGame->evoItemGfxIndex] +  var0 * SIZE_OF_VRAM_EVO_ITEM_STABLE_TILE, OBJ_VRAM_ADDR_EVO_ITEM_STABLE_TILE, SIZE_OF_VRAM_EVO_ITEM_STABLE_TILE);
    DmaCopy16(3, gEggFrameTilesGfx[(s16)gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3]], OBJ_VRAM_ADDR_HATCH_EGG_TILES, SIZE_OF_VRAM_HATCH_EGG_TILES);
    DmaCopy16(3, gBallUpgradeFx_Gfx[gCurrentPinballGame->ballUpgradeFxTileIndex], OBJ_VRAM_ADDR_FX_BALL_UPGRADE_TILES_MAIN_BOARD, SIZE_OF_VRAM_FX_BALL_UPGRADE_TILES);
    return;
}

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
    DmaCopy16(3, gRubyBoardShop_Gfx[var0], OBJ_VRAM_ADDR_RUBY_MART_SIGN_TILES, SIZE_OF_VRAM_RUBY_MART_SIGN_TILES);
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
    DmaCopy16(3, gDusclopsBonusClear_Gfx, OBJ_VRAM_ADDR_DUSCLOPS_BANNER_TILES, SIZE_OF_VRAM_DUSCLOPS_BANNER_TILES);
}

void RestoreKecleonBonusGraphics(void)
{
    DmaCopy16(3, gKecleonBonusClear_Gfx, OBJ_VRAM_ADDR_KECLEON_BANNER_TILES, SIZE_OF_VRAM_KECLEON_BANNER_TILES);
}

void RestoreKyogreBonusGraphics(void)
{
    DmaCopy16(3, gKyogreBonusClear_Gfx, OBJ_VRAM_ADDR_KYOGRE_BANNER_TILES, SIZE_OF_VRAM_KYOGRE_BANNER_TILES);
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
        DmaCopy16(3, gGroudonBonusClear_Gfx, OBJ_VRAM_ADDR_GROUDON_BANNER_TILES, SIZE_OF_VRAM_GROUDON_BANNER_TILES);
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
        DmaCopy16(3, gRayquazaBonusClear_Gfx, OBJ_VRAM_ADDR_RAYQUAZA_BANNER_TILES, SIZE_OF_VRAM_RAYQUAZA_BANNER_TILES);
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

    DmaCopy16(3, gSphealResultsScreenGfx, OBJ_VRAM_ADDR_SPHEAL_SUMMARY_TILES, SIZE_OF_VRAM_SPHEAL_SUMMARY_TILES);
}

void nullsub_18(void)
{
}
