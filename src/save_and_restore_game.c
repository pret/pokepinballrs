#include "global.h"
#include "agb_sram.h"
#include "main.h"
#include "m4a.h"

extern u8 gBoardGfxBuffer[];
extern u8 gBoardBGTileBufferAlt[];
extern const u8 gMainBoardBallSave_Gfx[];
extern const u8 gMainBoardEndOfBall_Gfx[];
extern const u8 gBoardActionTilesGfx[];

extern const u8 gEggModeTilesGfx[];
extern const u8 gAreaRouletteSelectedFx_Gfx[];

extern const u8 gCaptureModeTilesGfx[];
extern const u8 gCaptureScreenTilesGfx[];

extern const u8 gHatchRevealTilesGfx[];
extern const u8 gHatchStartTilesGfx[];
extern const u8 gHatchStage2TilesGfx[];
extern const u8 gHatchStage3TilesGfx[];
extern const u8 gHatchFinalTilesGfx[];

extern const u8 *gEvoItemAppear_GfxList[];
extern const s16 gEvoShopAnimFrames[][7];
extern const u16 gShopCursorToItemMap[];

extern const u8 gRubyBoardBonusGfx[];
extern const u8 gRubyBoardBonusObjPalette[];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u8 gRubyFlashingDecorationTiles[][0x300];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const u8 gRubyFlashingTiles_Secondary[][0x100];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardShop_Gfx[][0x500];

extern const u8 gSapphireBoardBonusGfx[];
extern const u8 gSapphireBoardBonusObjPalette[];
extern const u8 gSapphireCatchTilesGfx[];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];

extern const u8 gAlphabetTilesGfx[][0x40];
extern const u8 gSpaceTileGfx[0x40];
extern const u8 gDecimalDigitTilesGfx[][0x40];
extern const u8 gPokemonNameDisplayGfx[];
extern const s16 gCaughtTextChars[];

extern const u8 gHoleIndicatorTileGfx[][0x440];
extern const s16 gHoleAnimKeyframeData[][2];

extern const u8 gKecleonBonusClear_Gfx[0x2000];
extern const u8 gKyogreBonusClear_Gfx[0x2000];
extern const u8 gGroudonBoardBackgroundGfx[0x2000];
extern const u8 gGroudonBonusClear_Gfx[0x2000];
extern const u8 gRayquazaSkyBackgroundGfx[0x2800];
extern const u8 gRayquazaWindBoardGfx[0x1C00];
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
    u16 *var0;

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
        gCurrentPinballGame->savedSpriteAvailability[gMain.isBonusField][i] = gMain.spriteGroups[i].available;

    DmaCopy16(3, (void *)OBJ_PLTT, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], OBJ_PLTT_SIZE);
    DmaCopy16(3, (void *)BG_PLTT, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], BG_PLTT_SIZE);
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
    gCurrentPinballGame->savedScoreOverlayActive = gCurrentPinballGame->pauseScoreOverlayActive;
    gCurrentPinballGame->savedVCount = gCurrentPinballGame->pauseVCount;
    gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gCurrentPinballGame->eReaderBonuses[i] = gMain.eReaderBonuses[i];
}

void SaveGameToSram(void)
{
    gCurrentPinballGame->saveDataValid = 1;
    WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(*gCurrentPinballGame));
}

void RestoreGameState(u16 arg0)
{
    s16 i, j;
    s16 var0, var1;
    int var2;

    if (arg0 == 1)
    {
        ReadSramFast((void *)SRAM + 0x544, (u8 *)gCurrentPinballGame, sizeof(*gCurrentPinballGame));
    }
    else if (arg0 == 2)
    {
        DmaCopy16(3, gBoardConfig.pinballGame, gCurrentPinballGame, sizeof(*gCurrentPinballGame));
        gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
        gCurrentPinballGame->secondaryBall = &gCurrentPinballGame->ballStates[0];
        var2 = gMain.idleDemoVariant;
        if ((var2 & 0x3) == 1)
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
        gMain.scoreOverlayActive = gCurrentPinballGame->savedScoreOverlayActive;
        gMain.vCount = gCurrentPinballGame->savedVCount;
        gMain.bgOffsets[0] = gCurrentPinballGame->bgOffsets0;
        gMain.bgOffsets[1] = gCurrentPinballGame->bgOffsets1;
        gMain.bgOffsets[2] = gCurrentPinballGame->bgOffsets2;
        gMain.bgOffsets[3] = gCurrentPinballGame->bgOffsets3;
        for (i = 0; i < NUM_EREADER_CARDS; i++)
            gMain.eReaderBonuses[i] = gCurrentPinballGame->eReaderBonuses[i];

        gCurrentPinballGame->startButtonDisabled = 1;
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
    gMain.continueFromSave = 0;
    loadFieldBoardGraphics();
    if (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->boardCollisionConfigChanged)
        SetBoardCollisionConfig(1);

    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        for (i = 0; i < 22; i++)
        {
            var0 = i + gCurrentPinballGame->ballLaunchSpeed;
            var1 = (i + 10 + gCurrentPinballGame->ballLaunchSpeed) % 22;
            if (var0 < 32)
            {
                DmaCopy16(3, &gBoardGfxBuffer[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
            else
            {
                var0 -= 32;
                DmaCopy16(3, &gBoardBGTileBufferAlt[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
        }
    }

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gBG0TilemapBuffer, (void *)0x6002000, 0x1000);
    if (gMain.scoreOverlayActive)
    {
        if (gCurrentPinballGame->boardState == 6)
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

        DmaCopy16(3, gBG0TilemapBuffer, (void *)0x6002000, 0x800);
    }

    DmaCopy16(3, gCurrentPinballGame->savedObjPalette[gMain.isBonusField], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gCurrentPinballGame->savedBgPalette[gMain.isBonusField], (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    RestoreFieldSpecificGraphics();
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        RubyBoardProcess_0A_50848();
        LoadShopItemGraphics(gCurrentPinballGame->evolutionShopActive);
        break;
    case FIELD_SAPPHIRE:
        SapphireBoardProcess_0A_50AD4();
        break;
    case FIELD_DUSCLOPS:
        DusclopsBoardProcess_0A_50D48();
        break;
    case FIELD_KECLEON:
        KecleonBoardProcess_0A_50DE0();
        break;
    case FIELD_KYOGRE:
        KyogreBoardProcess_0A_50F04();
        break;
    case FIELD_GROUDON:
        GroudonBoardProcess_0A_50FD4();
        break;
    case FIELD_RAYQUAZA:
        RayquazaBoardProcess_0A_51090();
        break;
    case FIELD_SPHEAL:
        SphealBoardProcess_0A_51150();
        break;
    }

    for (i = 0; i < 100; i++)
        gMain.spriteGroups[i].available = gCurrentPinballGame->savedSpriteAvailability[gMain.isBonusField][i];

    if (arg0 == 1)
    {
        gCurrentPinballGame->saveDataValid = 0;
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

    switch (gCurrentPinballGame->activePortraitType - 1)
    {
    case 0:
        if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->outLaneSide == 2)
        {
            DmaCopy16(3, gPikaSaverFullCoverageGfx, (void *)0x6015800, 0x2400);
        }
        else
        {
            DmaCopy16(3, gPikaSaverPartialCoverageGfx, (void *)0x6015800, 0x2400);
        }
        break;
    case 1:
        DmaCopy16(3, gEggModeTilesGfx, (void *)0x6015800, 0x1000);
        break;
    case 2:
        DmaCopy16(3, gCaptureModeTilesGfx, (void *)0x6015800, 0xCA0);
        break;
    case 3:
        DmaCopy16(3, gModeBannerTilemaps[gCurrentPinballGame->bannerGfxIndex], (void *)0x6015800, 0x25E0);
        break;
    case 4:
        DmaCopy16(3, gHatchStartTilesGfx, (void *)0x6015800, 0x2000);
        break;
    case 5:
        DmaCopy16(3, gHatchStage2TilesGfx, (void *)0x6015800, 0x800);
        break;
    case 6:
        DmaCopy16(3, gHatchStage3TilesGfx, (void *)0x6015800, 0x2000);
        break;
    case 7:
        DmaCopy16(3, gHatchFinalTilesGfx, (void *)0x6015800, 0x1800);
        break;
    case 8:
        DmaCopy16(3, gCaptureScreenTilesGfx, (void *)0x6015800, 0x1C00);
        break;
    case 9:
        DmaCopy16(3, gSapphireCatchTilesGfx, (void *)0x6015800, 0x1400);
        break;
    case 10:
        DmaCopy16(3, gHatchRevealTilesGfx, (void *)0x6015800, 0x2800);
        break;
    case 11:
        DmaCopy16(3, gAreaRouletteSelectedFx_Gfx, (void *)0x6015800, 0x280);
        break;
    case 13:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }
        DmaCopy16(3, gPokemonNameDisplayGfx, (void *)0x6015C00, 0x940);
        break;
    case 12:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }

        for (i = 0; i < 10; i++)
        {
            if (gCaughtTextChars[i] == ' ')
            {
                DmaCopy16(3, gSpaceTileGfx, (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
            else
            {
                int var0 = gCaughtTextChars[i] - 'A';
                DmaCopy16(3, gAlphabetTilesGfx[var0], (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
        }
        break;
    case 14:
        DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->evoItemGfxIndex], (void *)0x6015800, 0x1C00);
        break;
    case 15:
        DmaCopy16(3, gBoardActionTilesGfx, (void *)0x6015800, 0x2400);
        break;
    case 16:
        DmaCopy16(3, gHatchFinalTilesGfx, (void *)0x6015800, 0x1800);
        break;
    case 17:
        DmaCopy16(3, gPokemonNameDisplayGfx, (void *)0x6015C00, 0x940);
        if (gCurrentPinballGame->evolutionShopActive == 0)
        {
            var1 = gShopItemData[gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor]];
            var2 = var1[3] / 10;
            DmaCopy16(3, gDecimalDigitTilesGfx[var2], (void *)0x6015DA0, 0x40);
            var3 = var1[3] % 10;
            DmaCopy16(3, gDecimalDigitTilesGfx[var3], (void *)0x6015E60, 0x40);
        }
        break;
    case 18:
        DmaCopy16(3, gMainBoardBallSave_Gfx, (void *)0x6015800, 0x2400);
        break;
    case 19:
        DmaCopy16(3, gMainBoardEndOfBall_Gfx, (void *)0x6015800, 0x2800);
        break;
    case 20:
        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gRubyBoardBonusGfx, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gRubyBoardBonusObjPalette, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        else
        {
            DmaCopy16(3, gSapphireBoardBonusGfx, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gSapphireBoardBonusObjPalette, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        break;
    case 21:
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x6015800, 0xC00);
        break;
    }
}

void RestoreMainFieldDynamicGraphics(void)
{
    s16 i;
    s16 var0;

    LoadCatchSpriteGraphics();
    LoadEggSpriteGraphics();

    for (i = 0; i <= 1; i++)
    {
        var0 = gCurrentPinballGame->flipper[i].position / 2;
        DmaCopy16(3, gFlipperTileGraphics[var0], ((i * 0x200) + 0x06010000), 0x200);
    }

    var0 = gCurrentPinballGame->ball->spinAngle / 0x1000;
    DmaCopy16(3, gBallRotationTileGraphics[var0], 0x06010400, 0x80);

    for (i = 0; i <= 1; i++)
    {
        DmaCopy16(3, gPikaSaverTilesGfx + ((var0 =gCurrentPinballGame->pikaSaverTileIndex[i]) * 0x180), 0x06010480 + (i * 0x180), 0x180);
    }

    var0 = gCurrentPinballGame->pikachuSpinFrame;
    DmaCopy16(3, gMainBoardPikaSpinner_Gfx[var0 = gCurrentPinballGame->pikachuSpinFrame], 0x06010780, 0x120);
    var0 = gCurrentPinballGame->chargeFillValue;
    DmaCopy16(3, gChargeFillIndicator_Gfx[var0], 0x06010AE0, 0x80);

    for (i = 0; i <= 1; i++)
    {
        switch (gCurrentPinballGame->portraitRenderMode[i])
        {
        case 0:
            DmaCopy16(3, gPortraitGenericGraphics[gCurrentPinballGame->portraitGfxIndex[i]], 0x06010CA0 + (i * 0x300), 0x300);
            gCurrentPinballGame->ball += 0; //TODO: Dumb match is still a match...
            break;
        case 9:
            if (gCurrentPinballGame->evoChainPosition > 0)
            {
                if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == 0)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = 205;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
                else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] <= 3)
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, 0x050003A0, 0x20);
                }
                else
                {
                    gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->evoTargetSpecies;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
            }
            else
            {
                gCurrentPinballGame->portraitGfxIndex[i] = gCurrentPinballGame->currentSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[i] / 15] + ((gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x20), 0x050003A0, 0x20);
            }
        case 3:
            DmaCopy16(3, gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[i] / 15] + (gCurrentPinballGame->portraitGfxIndex[i] % 15) * 0x300, 0x06010CA0 + (i * 0x18), 0x300);
            break;
        case 1:
        case 2:
        case 4:
        case 6:
        case 7:
        case 8:
            DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[i]], 0x06010CA0 + (i * 0x300), 0x300);
            break;
        }
    }

    if (gCurrentPinballGame->boardState == 4)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case 7:
        case 8:
            if ((u32) gCurrentPinballGame->captureFlashTimer > 4)
            {
                DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
            }
            break;
        case 9:
            if (gCurrentPinballGame->captureSequenceTimer <= 31)
            {
                if (gCurrentPinballGame->captureFlashTimer > 4)
                {
                    DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
                }
            }
            break;
        }
    }

    if (gCurrentPinballGame->boardState == 8)
    {
        switch (gCurrentPinballGame->boardSubState)
        {
        case 2:
            if (gCurrentPinballGame->captureFlashTimer > 4U)
            {
                DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
            }
            break;
        case 3:
            if (gCurrentPinballGame->captureSequenceTimer <= 31)
            {
                if (gCurrentPinballGame->captureFlashTimer > 4U)
                {
                    DmaCopy16(3, gCatchSpriteFlashGfx, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gCatchSpriteGfxBuffer, 0x06010CA0, 0x480);
                }
            }
            break;
        }
    }

    DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->bonusTrapAnimFrame], 0x060113C0, 0x300);
    DmaCopy16(3, gEvoItemTilesGfxPtrs[gCurrentPinballGame->evoItemGfxIndex] +  var0 * 0x200, 0x060116C0, 0x200);
    DmaCopy16(3, gEggFrameTilesGfx[(s16)gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3]], 0x06011CE0, 0x200);
    DmaCopy16(3, gBallShadowTileGraphics[gCurrentPinballGame->ballShadowTileIndex], 0x06011EE0, 0x200);
    return;
}

void RestoreRubyBoardTileGraphics(void)
{
    s16 i;
    s16 var0;

    var0 = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][2];
    DmaCopy16(3, gRubyBoardHatchCave_Gfx[var0], (void *)0x60122A0, 0x480);
    var0 = (gMain.systemFrameCount % 50) / 25;
    DmaCopy16(3, gRubyFlashingDecorationTiles[var0], (void *)0x6012720, 0x300);
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->catchHoleTileVariant], (void *)0x6012C20, 0x260);
    for (i = 0; i < 2; i++)
        DmaCopy16(3, gRubyFlashingTiles_Secondary[var0], (void *)0x6010000 + (0x174 + i * 8) * 0x20, 0x100);

    var0 = gCurrentPinballGame->shopDoorCurrentFrame & 0xF;
    DmaCopy16(3, gRubyBoardShopDoor_Gfx[var0], (void *)0x6013180, 0x180);
    if (gCurrentPinballGame->eggCaveState < 3)
        gCurrentPinballGame->cyndaquilFrame = 0;
    else
        gCurrentPinballGame->cyndaquilFrame = 1;

    DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilFrame], (void *)0x6013300, 0x280);
    var0 = gEvoShopAnimFrames[gCurrentPinballGame->evolutionShopActive][(gCurrentPinballGame->shopAnimTimer % 42) / 6];
    DmaCopy16(3, gRubyBoardShop_Gfx[var0], (void *)0x6013D00, 0x500);
}

void RestoreSapphireBoardTileGraphics(void)
{
    s16 index;

    switch (gCurrentPinballGame->sapphireHatchMachineState)
    {
    case 0:
    case 1:
    case 2:
        index = gCurrentPinballGame->sapphireHatchMachineFrameIx;
        DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        break;
    case 3:
    case 4:
        index = 15;
        DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        break;
    case 5:
        index = gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][0];
        DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        break;
    case 6:
        break;
    }
}

void RestoreDusclopsBonusGraphics(void)
{
    DmaCopy16(3, gDusclopsBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void RestoreKecleonBonusGraphics(void)
{
    DmaCopy16(3, gKecleonBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void RestoreKyogreBonusGraphics(void)
{
    DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x6015800, 0x2000);
    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreGroudonBonusGraphics(void)
{
    if (gCurrentPinballGame->boardState < 2)
    {
        DmaCopy16(3, gGroudonBoardBackgroundGfx, (void *)0x6015800, 0x2000);
    }
    else
    {
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreRayquazaBonusGraphics(void)
{
    u8 var0;

    if (gCurrentPinballGame->boardState == 0)
    {
        DmaCopy16(3, gRayquazaSkyBackgroundGfx, (void *)0x6015800, 0x2800);
    }
    else if (gCurrentPinballGame->boardState == 1)
    {
        DmaCopy16(3, gRayquazaWindBoardGfx, (void *)0x6015800, 0x1C00);
    }
    else
    {
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    var0 = gCurrentPinballGame->bossEntityState - 2;
    if (var0 > 9)
    {
        DmaCopy16(3, gRayquazaSpriteSheet, (void *)0x6011620, 0x860);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[0] / 15] + (gCurrentPinballGame->portraitGfxIndex[0] % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void RestoreSphealBonusGraphics(void)
{
    s16 i;
    int var0;
    u16 var1;

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[0x400 + i] = 0x200;

    DmaCopy16(3, &gBG0TilemapBuffer[0x400], (void *)0x6001000, 0x1000);
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
    DmaCopy16(3, &gBG0TilemapBuffer[0x800], (void *)0x6001140, 0x280);
    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gSphealResultsScreenGfx, (void *)0x6015800, 0x800);
}

void nullsub_18(void)
{
}
