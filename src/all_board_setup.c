#include "global.h"
#include "main.h"
#include "constants/mem_layout/dusclops.h"
#include "constants/mem_layout/groudon.h"
#include "constants/mem_layout/kecleon.h"
#include "constants/mem_layout/kyogre.h"
#include "constants/mem_layout/rayquaza.h"
#include "constants/mem_layout/ruby.h"
#include "constants/mem_layout/sapphire.h"
#include "constants/mem_layout/spheal.h"

extern const s16 gScrollTileUpdateTable[][4];

extern const struct BoardCollisionDataSet gBoardCollisionDataSets[][2];

extern u8 gBoardBGTileBufferAlt[];
extern u8 gBoardGfxBuffer[];

extern const u16 gFlipperCollisionData[11][0x2400]; // 96 x 96 pixel area
extern const u8 gRubyBoardBG3Tilemap[];
extern const Palette gRubyBoard_Pals[];
extern const u8 gRubyBoardBG2Tilemap[];
extern const u8 gRubyBoardCompressedTiles1[];
extern const u8 gRubyBoardCompressedTiles2[];
extern const u8 gRubyBoardCompressedBGTileBuffer[];
extern const u8 gRubyBoardBG1Tiles[];
extern const u8 gRubyBoardBG1Tilemap[];
extern const Palette gSapphireBoardPalette[];
extern const u8 gSapphireBoardBG3Tilemap[];
extern const u8 gSapphireBoardBG2Tilemap[];
extern const u8 gSapphireBoardCompressedTiles1[];
extern const u8 gSapphireBoardBG1Tiles[];
extern const u8 gSapphireBoardCompressedTiles2[];
extern const u8 gSapphireBoardCompressedBGTileBuffer[];
extern const u8 gSapphireBoardBG1Tilemap[];
extern const Palette gDusclopsBoardPalette[];
extern const u8 gDusclopsBoardBG3Tilemap[];


extern const u8 gDusclopsBoardBG2Tilemap[];
extern const u8 gDusclopsBoardBG1Tilemap[];
extern const u8 gBonusFieldCompressedBaseTiles[];
extern const u8 gDusclopsBoardCompressedBGTiles[];
extern const Palette gKecleonBoardPalette[];
extern const u8 gKecleonBoardBG2Tilemap[];
extern const u16 gKecleonScopeOverlayTilemap[];
extern const u8 gKecleonBoardBG3Tilemap[];
extern const u8 gKecleonBoardCompressedBGTiles[];
extern const Palette gKyogreBoardPalette[];
extern const u16 gKyogreWaterBackgroundTilemap[];
extern const u8 gKyogreBoardBG2Tilemap[];
extern const u8 gKyogreBoardCompressedBGTiles[];
extern const u8 gGroudonBoardBG3Tilemap[];
extern const u8 gGroudonBoardBG2Tilemap[];
extern const u8 gGroudonBoardCompressedBGTiles[];
extern const Palette gRayquazaBoardPalette[];
extern const u8 gRayquazaBoardBG3Tilemap[];
extern const u8 gRayquazaBoardBGScrollTilemap[];
extern const u8 gRayquazaBoardBG2Tilemap[];
extern const u8 gRayquazaBoardCompressedBGTiles[];
extern const Palette gSphealBoardPalette[];
extern const u16 gSphealWaterBackgroundTilemap[];
extern const u8 gSphealBoardBG2Tilemap[];
extern const u8 gSphealBoardCompressedBGTiles[];
extern const u8 gBoardHudTiles_B[];
extern const u8 gBoardHudTiles_A[];

extern const u8 gRubyIntroSprites_Gfx[];
extern const u8 gSapphireIntroSprites_Gfx[];
extern const u8 gDusclopsIntroSprite_Gfx[];
extern const u8 gKecleonIntroSprite_Gfx[];
extern const u8 gKyogreIntroSprite_Gfx[];
extern const u8 gGroudonIntroSprite_Gfx[];
extern const u8 gRayquazaIntroSprite_Gfx[];
extern const u8 gSphealIntroSprites_Gfx[];

extern const struct FieldBoardLayout gFieldBoardConfigs[];

void loadFieldBoardGraphics(void)
{
    struct BoardConfig *dest = &gBoardConfig;
    const struct FieldBoardLayout *src = gFieldBoardConfigs;
    memcpy(&dest->fieldLayout, &src[gMain.selectedField], sizeof(dest->fieldLayout));

    switch (gMain.selectedField)
    {
	case FIELD_RUBY:
        DmaCopy16(3, gRubyBoard_Pals, BG_PLTT, BG_PLTT_SIZE);
        DmaCopy16(3, gRubyBoardBG1Tiles, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gRubyBoardBG1Tilemap, BG_VRAM_ADDR_RUBY_LAYER_1_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        LZ77UnCompWram(gRubyBoardCompressedTiles1, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gRubyBoardCompressedTiles2, gBoardGfxBuffer);
        LZ77UnCompWram(gRubyBoardCompressedBGTileBuffer, gBoardBGTileBufferAlt);

        // Initialize section with the board's 'Tile wrap' logic
        DmaCopy16(3, &gBoardGfxBuffer[0xC00], BG_ADDR_FOR_BOARD_WRAP(2, 0), 0x2400);
        DmaCopy16(3, &gBoardGfxBuffer[0x3000], BG_TILE_ADDR(TILE_INDEX(2,0,0)), 0x3400);

        DmaCopy16(3, gRubyBoardBG3Tilemap, BG_VRAM_ADDR_RUBY_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        DmaCopy16(3, gRubyBoardBG2Tilemap, BG_VRAM_ADDR_RUBY_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gRubyIntroSprites_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
	case FIELD_SAPPHIRE:
        DmaCopy16(3, gSapphireBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        DmaCopy16(3, gSapphireBoardBG1Tiles, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gSapphireBoardBG1Tilemap, BG_VRAM_ADDR_SAPPHIRE_LAYER_1_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        LZ77UnCompWram(gSapphireBoardCompressedTiles1, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gSapphireBoardCompressedTiles2, gBoardGfxBuffer);
        LZ77UnCompWram(gSapphireBoardCompressedBGTileBuffer, gBoardBGTileBufferAlt);

        // Initialize section with the board's 'Tile wrap' logic
        DmaCopy16(3, gBoardGfxBuffer, BG_ADDR_FOR_BOARD_WRAP(-1, 0), 0x3000);
        DmaCopy16(3, &gBoardGfxBuffer[0x3000], BG_TILE_ADDR(TILE_INDEX(2,0,0)), 0x2800);

        DmaCopy16(3, gSapphireBoardBG3Tilemap, BG_VRAM_ADDR_SAPPHIRE_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        DmaCopy16(3, gSapphireBoardBG2Tilemap, BG_VRAM_ADDR_SAPPHIRE_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gSapphireIntroSprites_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
	case FIELD_DUSCLOPS:
        DmaCopy16(3, gDusclopsBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gDusclopsBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gDusclopsBoardBG3Tilemap, BG_VRAM_ADDR_DUSCLOPS_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gDusclopsBoardBG2Tilemap, BG_VRAM_ADDR_DUSCLOPS_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gDusclopsBoardBG1Tilemap, BG_VRAM_ADDR_DUSCLOPS_LAYER_1_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gDusclopsIntroSprite_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
	case FIELD_KECLEON:
        DmaCopy16(3, gKecleonBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gKecleonBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gKecleonBoardBG3Tilemap, BG_VRAM_ADDR_KECLEON_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gKecleonBoardBG2Tilemap, BG_VRAM_ADDR_KECLEON_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gKecleonScopeOverlayTilemap, BG_VRAM_ADDR_KECLEON_LAYER_1_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gKecleonIntroSprite_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
	case FIELD_KYOGRE:
        DmaCopy16(3, gKyogreBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gKyogreBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gKyogreWaterBackgroundTilemap, BG_VRAM_ADDR_KYOGRE_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gKyogreBoardBG2Tilemap, BG_VRAM_ADDR_KYOGRE_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gKyogreIntroSprite_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
	case FIELD_GROUDON:
        DmaCopy16(3, gGroudonLavaPaletteCycleData, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gGroudonBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gGroudonBoardBG3Tilemap, BG_VRAM_ADDR_GROUDON_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gGroudonBoardBG2Tilemap, BG_VRAM_ADDR_GROUDON_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gGroudonIntroSprite_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
	case FIELD_RAYQUAZA:
        DmaCopy16(3, gRayquazaBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gRayquazaBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gRayquazaBoardBG3Tilemap, BG_VRAM_ADDR_RAYQUAZA_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        DmaCopy16(3, gRayquazaBoardBG2Tilemap, BG_VRAM_ADDR_RAYQUAZA_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        DmaCopy16(3, gRayquazaBoardBGScrollTilemap, BG_VRAM_ADDR_RAYQUAZA_LAYER_1_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_512);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gRayquazaIntroSprite_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
	case FIELD_SPHEAL:
        DmaCopy16(3, gSphealBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(1,0,0)), BG_CHAR_SIZE);
        LZ77UnCompWram(gSphealBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_TILE_ADDR(TILE_INDEX(2,0,0)), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gSphealWaterBackgroundTilemap, BG_VRAM_ADDR_SPHEAL_LAYER_3_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gSphealBoardBG2Tilemap, BG_VRAM_ADDR_SPHEAL_LAYER_2_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
        DmaCopy16(3, gBoardHudTiles_A, BG_VRAM_ADDR_HUD_TILES_A, SIZE_OF_VRAM_HUD_TILES_A);
        DmaCopy16(3, gBoardHudTiles_B, BG_VRAM_ADDR_HUD_TILES_B, SIZE_OF_VRAM_HUD_TILES_B);
        DmaCopy16(3, gSphealIntroSprites_Gfx, OBJ_TILE_ADDR(TILE_INDEX(0,0,0)), OBJ_VRAM_FULL_SIZE);
        break;
    }

    gBoardConfig.flipperCollisionData = gFlipperCollisionData;
}

void SetBoardCollisionConfig(s16 arg0)
{
    gBoardConfig.fieldLayout.collision.tileData[0] = gBoardCollisionDataSets[gMain.selectedField][arg0].tileData[0];
    gBoardConfig.fieldLayout.collision.angleData[0] = gBoardCollisionDataSets[gMain.selectedField][arg0].angleData[0];
    gBoardConfig.fieldLayout.collision.typeData[0] = gBoardCollisionDataSets[gMain.selectedField][arg0].typeData[0];
}

void UpdateScrollingBackgroundTiles(void)
{
    s16 r4;
    const s16 *r3;

    r4 = gMain.bgOffsets[3].yOffset / 8;
    r3 = gScrollTileUpdateTable[r4];
    if (r4 == gCurrentPinballGame->ballLaunchSpeed)
        return;

    if (r4 > gCurrentPinballGame->ballLaunchSpeed)
    {
        if (r3[0] > 31)
        {
            DmaCopy16(3, &gBoardBGTileBufferAlt[(r3[0] - 32) * 0x400], BG_TILE_ADDR(TILE_INDEX(2,r3[1],0)), 0x400);
        }
        else
        {
            DmaCopy16(3, &gBoardGfxBuffer[r3[0] * 0x400], BG_TILE_ADDR(TILE_INDEX(2,r3[1],0)), 0x400);
        }
    }
    else
    {
        if (r3[2] > 31)
        {
            DmaCopy16(3, &gBoardBGTileBufferAlt[(r3[2] - 32) * 0x400], BG_TILE_ADDR(TILE_INDEX(2,r3[3],0)), 0x400);
        }
        else
        {
            DmaCopy16(3, &gBoardGfxBuffer[r3[2] * 0x400], BG_TILE_ADDR(TILE_INDEX(2,r3[3],0)), 0x400);
        }
    }

    gCurrentPinballGame->ballLaunchSpeed = r4;
}


