#include "global.h"
#include "main.h"

extern const s16 gScrollTileUpdateTable[][4];

extern const struct BoardCollisionDataSet gBoardCollisionDataSets[][2];

extern u8 gBoardBGTileBufferAlt[];
extern u8 gBoardGfxBuffer[];

extern const u16 gFlipperCollisionData[11][0x2400]; // 96 x 96 pixel area
extern const u8 gRubyBoardBG0Tilemap[];
extern const Palette gRubyBoard_Pals[];
extern const u8 gRubyBoardBG1Tilemap[];
extern const u8 gRubyBoardCompressedTiles1[];
extern const u8 gRubyBoardCompressedTiles2[];
extern const u8 gRubyBoardCompressedBGTileBuffer[];
extern const u8 gRubyBoardBGTiles[];
extern const u8 gRubyBoardBGTilemap[];
extern const Palette gSapphireBoardPalette[];
extern const u8 gSapphireBoardBG0Tilemap[];
extern const u8 gSapphireBoardBG1Tilemap[];
extern const u8 gSapphireBoardCompressedTiles1[];
extern const u8 gSapphireBoardBGTiles[];
extern const u8 gSapphireBoardCompressedTiles2[];
extern const u8 gSapphireBoardCompressedBGTileBuffer[];
extern const u8 gSapphireBoardBGTilemap[];
extern const Palette gDusclopsBoardPalette[];
extern const u8 gDusclopsBoardBG0Tilemap[];


extern const u8 gDusclopsBoardBG1Tilemap[];
extern const u8 gDusclopsBoardBG2Tilemap[];
extern const u8 gBonusFieldCompressedBaseTiles[];
extern const u8 gDusclopsBoardCompressedBGTiles[];
extern const Palette gKecleonBoardPalette[];
extern const u8 gKecleonBoardBG1Tilemap[];
extern const u16 gKecleonBerryOverlayTilemap[];
extern const u8 gKecleonBoardBG0Tilemap[];
extern const u8 gKecleonBoardCompressedBGTiles[];
extern const Palette gKyogreBoardPalette[];
extern const u16 gKyogreWaterBackgroundTilemap[];
extern const u8 gKyogreBoardBG1Tilemap[];
extern const u8 gKyogreBoardCompressedBGTiles[];
extern const u8 gGroudonBoardBG0Tilemap[];
extern const u8 gGroudonBoardBG1Tilemap[];
extern const u8 gGroudonBoardCompressedBGTiles[];
extern const Palette gRayquazaBoardPalette[];
extern const u8 gRayquazaBoardBG0Tilemap[];
extern const u8 gRayquazaBoardBGScrollTilemap[];
extern const u8 gRayquazaBoardBG1Tilemap[];
extern const u8 gRayquazaBoardCompressedBGTiles[];
extern const Palette gSphealBoardPalette[];
extern const u16 gSphealWaterBackgroundTilemap[];
extern const u8 gSphealBoardBG1Tilemap[];
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
        DmaCopy16(3, gRubyBoardBGTiles, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gRubyBoardBGTilemap, BG_CHAR_SCREEN_ADDR(0,6), 2*BG_SCREEN_SIZE);
        LZ77UnCompWram(gRubyBoardCompressedTiles1, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gRubyBoardCompressedTiles2, gBoardGfxBuffer);
        LZ77UnCompWram(gRubyBoardCompressedBGTileBuffer, gBoardBGTileBufferAlt);
        DmaCopy16(3, &gBoardGfxBuffer[0xC00], (void *)0x0600B400, 0x2400);
        DmaCopy16(3, &gBoardGfxBuffer[0x3000], BG_CHAR_SCREEN_ADDR(2,0), 0x3400);
        DmaCopy16(3, gRubyBoardBG0Tilemap, BG_CHAR_SCREEN_ADDR(0,0), 2*BG_SCREEN_SIZE);
        DmaCopy16(3, gRubyBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,2), 2*BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gRubyIntroSprites_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_SAPPHIRE:
        DmaCopy16(3, gSapphireBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        DmaCopy16(3, gSapphireBoardBGTiles, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gSapphireBoardBGTilemap, BG_CHAR_SCREEN_ADDR(0,6), 2*BG_SCREEN_SIZE);
        LZ77UnCompWram(gSapphireBoardCompressedTiles1, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gSapphireBoardCompressedTiles2, gBoardGfxBuffer);
        LZ77UnCompWram(gSapphireBoardCompressedBGTileBuffer, gBoardBGTileBufferAlt);
        DmaCopy16(3, gBoardGfxBuffer, (void *)0x0600A800, 0x3000);
        DmaCopy16(3, &gBoardGfxBuffer[0x3000], BG_CHAR_SCREEN_ADDR(2,0), 0x2800);
        DmaCopy16(3, gSapphireBoardBG0Tilemap, BG_CHAR_SCREEN_ADDR(0,0), 2*BG_SCREEN_SIZE);
        DmaCopy16(3, gSapphireBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,2), 2*BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gSapphireIntroSprites_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_DUSCLOPS:
        DmaCopy16(3, gDusclopsBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gDusclopsBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gDusclopsBoardBG0Tilemap, BG_CHAR_SCREEN_ADDR(0,0), BG_SCREEN_SIZE);
        DmaCopy16(3, gDusclopsBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,1), BG_SCREEN_SIZE);
        DmaCopy16(3, gDusclopsBoardBG2Tilemap, BG_CHAR_SCREEN_ADDR(0,2), BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gDusclopsIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_KECLEON:
        DmaCopy16(3, gKecleonBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gKecleonBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gKecleonBoardBG0Tilemap, BG_CHAR_SCREEN_ADDR(0,0), BG_SCREEN_SIZE);
        DmaCopy16(3, gKecleonBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,1), BG_SCREEN_SIZE);
        DmaCopy16(3, gKecleonBerryOverlayTilemap, BG_CHAR_SCREEN_ADDR(0,2), BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gKecleonIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_KYOGRE:
        DmaCopy16(3, gKyogreBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gKyogreBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gKyogreWaterBackgroundTilemap, BG_CHAR_SCREEN_ADDR(0,0), BG_SCREEN_SIZE);
        DmaCopy16(3, gKyogreBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,1), BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gKyogreIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_GROUDON:
        DmaCopy16(3, gGroudonLavaPaletteCycleData, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gGroudonBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gGroudonBoardBG0Tilemap, BG_CHAR_SCREEN_ADDR(0,0), BG_SCREEN_SIZE);
        DmaCopy16(3, gGroudonBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,1), BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gGroudonIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_RAYQUAZA:
        DmaCopy16(3, gRayquazaBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gRayquazaBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gRayquazaBoardBG0Tilemap, BG_CHAR_SCREEN_ADDR(0,0), 2*BG_SCREEN_SIZE);
        DmaCopy16(3, gRayquazaBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,2), 2*BG_SCREEN_SIZE);
        DmaCopy16(3, gRayquazaBoardBGScrollTilemap, BG_CHAR_SCREEN_ADDR(0,6), 2*BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gRayquazaIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_SPHEAL:
        DmaCopy16(3, gSphealBoardPalette, BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(1,0), BG_CHAR_SIZE);
        LZ77UnCompWram(gSphealBoardCompressedBGTiles, gBoardGfxBuffer);
        DmaCopy16(3, gBoardGfxBuffer, BG_CHAR_SCREEN_ADDR(2,0), 2*BG_CHAR_SIZE);
        DmaCopy16(3, gSphealWaterBackgroundTilemap, BG_CHAR_SCREEN_ADDR(0,0), BG_SCREEN_SIZE);
        DmaCopy16(3, gSphealBoardBG1Tilemap, BG_CHAR_SCREEN_ADDR(0,1), BG_SCREEN_SIZE);
        DmaCopy16(3, gBoardHudTiles_A, (void *)0x06006800, 0x400);
        DmaCopy16(3, gBoardHudTiles_B, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gSphealIntroSprites_Gfx, (void *)0x06010000, 0x8000);
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
            DmaCopy16(3, &gBoardBGTileBufferAlt[(r3[0] - 32) * 0x400], BG_CHAR_SCREEN_ADDR(2,0) + r3[1] * 0x400, 0x400);
        }
        else
        {
            DmaCopy16(3, &gBoardGfxBuffer[r3[0] * 0x400], BG_CHAR_SCREEN_ADDR(2,0) + r3[1] * 0x400, 0x400);
        }
    }
    else
    {
        if (r3[2] > 31)
        {
            DmaCopy16(3, &gBoardBGTileBufferAlt[(r3[2] - 32) * 0x400], BG_CHAR_SCREEN_ADDR(2,0) + r3[3] * 0x400, 0x400);
        }
        else
        {
            DmaCopy16(3, &gBoardGfxBuffer[r3[2] * 0x400], BG_CHAR_SCREEN_ADDR(2,0) + r3[3] * 0x400, 0x400);
        }
    }

    gCurrentPinballGame->ballLaunchSpeed = r4;
}


