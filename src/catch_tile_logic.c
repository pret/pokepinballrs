#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const s16 gHatchSequentialTileFramesetData[][2];
extern const u16 gHatchSequentialTileBreakSpritesheetOam[28][18];
extern const s16 gHatchRevealSparkleTimings[];
extern const u16 gHatchRevealOamFramesets[16][18];
extern const u8 gHatchRevealPalette[];
extern const u16 gHatchFullRevealOamFramesets[18][18];
extern const u8 gHatchRevealTilesGfx[];
extern const s16 gHatchRevealFinalTimings[];
extern const u8 gHatchFinalTilesGfx[];
extern const u8 gHatchFinalPalette[];
extern const u16 gHatchSequentialOamFramesets[22][12];

extern const u8 gHatchStartTilesGfx[];
extern const u8 gHatchStartPalette[];
extern const u8 gHatchStage2TilesGfx[];
extern const u8 gHatchStage2Palette[];
extern const u8 gHatchStage3TilesGfx[];
extern const u8 gHatchStage3Palette[];


void DisableHatchTileDisplay(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[18];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.fieldSpriteGroups[18]->available = 0;
    group = gMain.fieldSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.fieldSpriteGroups[12]->available = 0;
    gCurrentPinballGame->activePortraitType = 0;
}

void RevealSequentialHatchTiles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;
    int var1;

    var1 = 1;
    gMain.fieldSpriteGroups[18]->available = 1;
    if (gCurrentPinballGame->hatchFrameId > 0)
        UpdateSequentialTileParticles();

    if (gCurrentPinballGame->hatchSequentialTilesRevealed < gCurrentPinballGame->hatchTilesBoardAcknowledged)
    {
        if (gCurrentPinballGame->hatchFrameId == 0 && gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer == 0)
        {
            gCurrentPinballGame->activePortraitType = 11;
            DmaCopy16(3, gHatchRevealPalette, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gHatchRevealTilesGfx, (void *)0x06015800, 0x2800);
        }

        if (gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][1] > gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer)
        {
            gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
            gCurrentPinballGame->hatchFrameId++;
            if (gCurrentPinballGame->hatchFrameId > 12)
            {
                gCurrentPinballGame->hatchSequentialTilesRevealed++;
                gCurrentPinballGame->hatchFrameId = 0;
                var1 = 0;
                gCurrentPinballGame->hatchTilesRemaining--;
                if (gCurrentPinballGame->hatchSequentialTilesRevealed == gCurrentPinballGame->hatchTilesBoardAcknowledged)
                {
                    if (gCurrentPinballGame->hatchTilesRemaining >= 0)
                        gCurrentPinballGame->activePortraitType = 0;
                }

                if (gCurrentPinballGame->hatchTilesRemaining < 0)
                {
                    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                    for (i = 0; i < 6; i++)
                        gCurrentPinballGame->hatchTileShufflePool[i] = i;

                    var0 = gMain.systemFrameCount % 6;
                    gCurrentPinballGame->hatchTilesRemaining = 5;
                    gCurrentPinballGame->boardSubState++;
                    gMain.fieldSpriteGroups[18]->available = 0;
                }
                else if (gCurrentPinballGame->hatchTilesRemaining == 0)
                {
                    var0 = 0;
                }
                else
                {
                    var0 = gMain.systemFrameCount % gCurrentPinballGame->hatchTilesRemaining;
                }

                gCurrentPinballGame->hatchGridCellIndex = gCurrentPinballGame->hatchTileShufflePool[var0];
                for (i = var0; i < gCurrentPinballGame->hatchTilesRemaining; i++)
                    gCurrentPinballGame->hatchTileShufflePool[i] = gCurrentPinballGame->hatchTileShufflePool[i + 1];
            }
            else
            {
                if (gCurrentPinballGame->hatchFrameId == 1)
                    gCurrentPinballGame->hatchTilePalette[gCurrentPinballGame->hatchGridCellIndex] = 13;
            }
        }
    }
    else
    {
        var1 = 0;
    }

    if (gCurrentPinballGame->hatchFrameId == 1)
    {
        m4aSongNumStart(SE_CATCH_TILE_REVEAL);
        InitSequentialTileParticles();
    }

    if (gCurrentPinballGame->hatchFrameId == 12)
        var1 = 0;

    group = gMain.fieldSpriteGroups[18];
    if (var1)
    {
        group->baseX = (gCurrentPinballGame->hatchGridCellIndex % 3) * 16 - (gCurrentPinballGame->cameraXOffset - 96);
        group->baseY = (gCurrentPinballGame->hatchGridCellIndex / 3) * 16 - (gCurrentPinballGame->cameraYOffset - 300);
    }
    else
    {
        group->baseY = 200;
    }

    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 0];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 1];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].priority = 3;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void RevealAllHatchTilesAtOnce(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    switch (gCurrentPinballGame->hatchRevealPhase)
    {
    case 0:
        if (gCurrentPinballGame->revealAnimFrameCounter < 60)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->hatchRevealPhase++;
            gCurrentPinballGame->revealAnimFrameCounter = 0;
        }
        gMain.blendControl = 0xCE;
        break;
    case 1:
        gCurrentPinballGame->activePortraitType = 5;
        DmaCopy16(3, gHatchStartTilesGfx, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gHatchStartPalette, (void *)0x050003C0, 0x20);
        gMain.fieldSpriteGroups[35]->available = 1;
        m4aSongNumStart(SE_CATCH_ALL_REVEAL_LIGHTNING);
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->revealAnimFrameCounter = 0;
        gCurrentPinballGame->revealFramesetIndex = 0;
        break;
    case 2:
        if (gHatchRevealSparkleTimings[gCurrentPinballGame->revealFramesetIndex] > gCurrentPinballGame->revealAnimFrameCounter)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex++;
            if (gCurrentPinballGame->revealFramesetIndex > 7)
            {
                gCurrentPinballGame->revealFramesetIndex = 7;
                gCurrentPinballGame->hatchRevealPhase++;
                gMain.fieldSpriteGroups[35]->available = 0;
            }
        }

        var0 = gCurrentPinballGame->revealFramesetIndex;
        group = gMain.fieldSpriteGroups[35];
        group->baseX = 124 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 244 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchRevealOamFramesets[var0][i * 3 + 0];
            *dst++ = gHatchRevealOamFramesets[var0][i * 3 + 1];
            *dst++ = gHatchRevealOamFramesets[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 3:
        gCurrentPinballGame->activePortraitType = 6;
        DmaCopy16(3, gHatchStage2TilesGfx, (void *)0x06015800, 0x800);
        DmaCopy16(3, gHatchStage2Palette, (void *)0x050003C0, 0x20);
        gMain.fieldSpriteGroups[36]->available = 1;
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->revealAnimFrameCounter = 0;
        gCurrentPinballGame->startButtonDisabled = 1;
        break;
    case 4:
        var0 = gCurrentPinballGame->revealAnimFrameCounter / 2;
        if (gCurrentPinballGame->revealAnimFrameCounter < 15)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gMain.fieldSpriteGroups[36]->available = 0;
            gCurrentPinballGame->hatchRevealPhase++;
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex = 0;
        }

        group = gMain.fieldSpriteGroups[36];
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchFullRevealOamFramesets[var0][i * 3 + 0];
            *dst++ = gHatchFullRevealOamFramesets[var0][i * 3 + 1];
            *dst++ = gHatchFullRevealOamFramesets[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 5:
        gCurrentPinballGame->activePortraitType = 7;
        DmaCopy16(3, gHatchStage3TilesGfx, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gHatchStage3Palette, (void *)0x050003C0, 0x20);
        gCurrentPinballGame->hatchRevealPhase++;
        InitBurstTileParticles();
        m4aSongNumStart(SE_CATCH_ALL_REVEAL_SHATTER);
        break;
    case 6:
        gMain.blendBrightness = 0;
        gMain.blendControl = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8) | 0xA0;
        if (gCurrentPinballGame->revealAnimFrameCounter < 73)
        {
            s16 var1;
            if (gCurrentPinballGame->revealAnimFrameCounter < 8)
            {
                gMain.blendBrightness = 16;
            }
            else
            {
                for (i = 0; i < 6; i++)
                    gCurrentPinballGame->hatchTilePalette[i] = 13;

                gMain.blendBrightness = ((8 - gCurrentPinballGame->revealAnimFrameCounter) / 4) + 16;
            }
        }

        if (gCurrentPinballGame->revealAnimFrameCounter < 72)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->hatchRevealPhase++;
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex = 0;
        }

        if (gCurrentPinballGame->revealAnimFrameCounter > 8U)
        {
            if (gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer < 0x7000)
                UpdateBurstTileParticles();
        }
        break;
    case 7:
        gCurrentPinballGame->activePortraitType = 8;
        DmaCopy16(3, gHatchFinalTilesGfx, (void *)0x06015800, 0x1800);
        DmaCopy16(3, gHatchFinalPalette, (void *)0x050003C0, 0x20);
        gMain.fieldSpriteGroups[37]->available = 1;
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->startButtonDisabled = 0;
        break;
    case 8:
        if (gHatchRevealFinalTimings[gCurrentPinballGame->revealFramesetIndex] > gCurrentPinballGame->revealAnimFrameCounter)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex++;
            if (gCurrentPinballGame->revealFramesetIndex > 10)
            {
                gCurrentPinballGame->boardSubState++;
                gMain.fieldSpriteGroups[37]->available = 0;
                gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                gMain.blendControl = 0xCE;
                gMain.blendBrightness = 0;
                gMain.fieldSpriteGroups[37]->available = 0;
                gCurrentPinballGame->revealFramesetIndex = 10;
                gCurrentPinballGame->activePortraitType = 0;
            }
        }

        var0 = gCurrentPinballGame->revealFramesetIndex;
        group = gMain.fieldSpriteGroups[37];
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchSequentialOamFramesets[var0][i * 3 + 0];
            *dst++ = gHatchSequentialOamFramesets[var0][i * 3 + 1];
            *dst++ = gHatchSequentialOamFramesets[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    }
}
