#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"

extern const s16 gCatchTile_SequentialFramesetData[][2];
extern const u16 gCatchTile_SequentialBreakSpritesheetOam[28][18];
extern const s16 gCatchTile_RevealSparkleTimings[];
extern const u16 gCatchTile_RevealOamFramesets[16][18];
extern const u8 gCatchTile_RevealTilesGfx[];
extern const Palette gCatchTile_Reveal_Pal;
extern const u16 gCatchTile_BurstRevealOamFramesets0[18][18];
extern const u16 gCatchTile_BurstRevealOamFramesets1[22][12];
extern const s16 gCatchTile_RevealFinalTimings[];

extern const u8 gCatchTile_BurstStart_Gfx[];
extern const Palette gCatchTile_BurstStart_Pal;
extern const u8 gCatchTile_BurstStage2_Gfx[];
extern const Palette gCatchTile_BurstStage2_Pal;
extern const u8 gCatchTile_BurstStage3_Gfx[];
extern const Palette gCatchTile_BurstStage3_Pal;
extern const u8 gCatchTile_BurstStage4_Gfx[];
extern const Palette gCatchTile_BurstStage4_Pal;


void DisableCatchTileDisplay(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[FIELD_SG_18];
    if (group->active)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.fieldSpriteGroups[FIELD_SG_18]->active = FALSE;
    group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_TILE_BREAK];
    if (group->active)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.fieldSpriteGroups[FIELD_SG_MAIN_TILE_BREAK]->active = FALSE;
    gCurrentPinballGame->activeFxType = FX_NONE;
}

void RevealCatchTilesSequential(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 selectedTileIx;
    int var1;

    var1 = TRUE;
    gMain.fieldSpriteGroups[FIELD_SG_18]->active = TRUE;
    if (gCurrentPinballGame->catchRevealFrameId > 0)
        UpdateSequentialTileParticles();

    if (gCurrentPinballGame->catchSequentialTilesRevealed < gCurrentPinballGame->catchTilesBoardAcknowledged)
    {
        if (gCurrentPinballGame->catchRevealFrameId == 0 && gCurrentPinballGame->catchTileRevealFrameAnimTimer == 0)
        {
            gCurrentPinballGame->activeFxType = FX_SEQUENTIAL_CATCH_TILE;
            DmaCopy16(3, gCatchTile_Reveal_Pal, OBJ_PLTT_SLOT(PAL_IX_CATCH_TILE_FX), PLTT_SLOT_SIZE);
            DmaCopy16(3, gCatchTile_RevealTilesGfx, (void *)0x06015800, 0x2800);
        }

        if (gCatchTile_SequentialFramesetData[gCurrentPinballGame->catchRevealFrameId][1] > gCurrentPinballGame->catchTileRevealFrameAnimTimer)
        {
            gCurrentPinballGame->catchTileRevealFrameAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->catchTileRevealFrameAnimTimer = 0;
            gCurrentPinballGame->catchRevealFrameId++;
            if (gCurrentPinballGame->catchRevealFrameId > 12)
            {
                gCurrentPinballGame->catchSequentialTilesRevealed++;
                gCurrentPinballGame->catchRevealFrameId = 0;
                var1 = FALSE;
                gCurrentPinballGame->catchTilesRemaining--;
                if (gCurrentPinballGame->catchSequentialTilesRevealed == gCurrentPinballGame->catchTilesBoardAcknowledged)
                {
                    if (gCurrentPinballGame->catchTilesRemaining >= 0)
                        gCurrentPinballGame->activeFxType = FX_NONE;
                }

                if (gCurrentPinballGame->catchTilesRemaining < 0)
                {
                    gCurrentPinballGame->catchTilesBoardAcknowledged = 0;
                    gCurrentPinballGame->catchSequentialTilesRevealed = 0;
                    gCurrentPinballGame->catchTilesBumperAcknowledgedCount = 0;
                    for (i = 0; i < 6; i++)
                        gCurrentPinballGame->catchTileShufflePool[i] = i;

                    selectedTileIx = gMain.systemFrameCount % 6;
                    gCurrentPinballGame->catchTilesRemaining = 5;
                    gCurrentPinballGame->boardSubState++; //Move to next Catch phase
                    gMain.fieldSpriteGroups[FIELD_SG_18]->active = FALSE;
                }
                else if (gCurrentPinballGame->catchTilesRemaining == 0)
                {
                    selectedTileIx = 0;
                }
                else
                {
                    selectedTileIx = gMain.systemFrameCount % gCurrentPinballGame->catchTilesRemaining;
                }

                gCurrentPinballGame->catchGridCellIndex = gCurrentPinballGame->catchTileShufflePool[selectedTileIx];
                for (i = selectedTileIx; i < gCurrentPinballGame->catchTilesRemaining; i++)
                    gCurrentPinballGame->catchTileShufflePool[i] = gCurrentPinballGame->catchTileShufflePool[i + 1];
            }
            else
            {
                if (gCurrentPinballGame->catchRevealFrameId == 1)
                    gCurrentPinballGame->catchTilePalette[gCurrentPinballGame->catchGridCellIndex] = 13;
            }
        }
    }
    else
    {
        var1 = FALSE;
    }

    if (gCurrentPinballGame->catchRevealFrameId == 1)
    {
        m4aSongNumStart(SE_CATCH_TILE_REVEAL);
        InitSequentialTileParticles();
    }

    if (gCurrentPinballGame->catchRevealFrameId == 12)
        var1 = FALSE;

    group = gMain.fieldSpriteGroups[FIELD_SG_18];
    if (var1)
    {
        group->baseX = (gCurrentPinballGame->catchGridCellIndex % 3) * 16 - (gCurrentPinballGame->cameraXOffset - 96);
        group->baseY = (gCurrentPinballGame->catchGridCellIndex / 3) * 16 - (gCurrentPinballGame->cameraYOffset - 300);
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
        *dst++ = gCatchTile_SequentialBreakSpritesheetOam[gCatchTile_SequentialFramesetData[gCurrentPinballGame->catchRevealFrameId][0]][i * 3 + 0];
        *dst++ = gCatchTile_SequentialBreakSpritesheetOam[gCatchTile_SequentialFramesetData[gCurrentPinballGame->catchRevealFrameId][0]][i * 3 + 1];
        *dst++ = gCatchTile_SequentialBreakSpritesheetOam[gCatchTile_SequentialFramesetData[gCurrentPinballGame->catchRevealFrameId][0]][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].priority = 3;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void RevealCatchTilesBurst(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 tileFrameIx;

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
        gCurrentPinballGame->activeFxType = FX_CATCH_TILE_BURST_1;
        DmaCopy16(3, gCatchTile_BurstStart_Gfx, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gCatchTile_BurstStart_Pal, OBJ_PLTT_SLOT(PAL_IX_CATCH_TILE_FX), PLTT_SLOT_SIZE);
        gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_LIGHTNING_STRIKE]->active = TRUE;
        m4aSongNumStart(SE_CATCH_ALL_REVEAL_LIGHTNING);
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->revealAnimFrameCounter = 0;
        gCurrentPinballGame->revealFramesetIndex = 0;
        break;
    case 2:
        if (gCatchTile_RevealSparkleTimings[gCurrentPinballGame->revealFramesetIndex] > gCurrentPinballGame->revealAnimFrameCounter)
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
                gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_LIGHTNING_STRIKE]->active = FALSE;
            }
        }

        tileFrameIx = gCurrentPinballGame->revealFramesetIndex;
        group = gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_LIGHTNING_STRIKE];
        group->baseX = 124 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 244 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gCatchTile_RevealOamFramesets[tileFrameIx][i * 3 + 0];
            *dst++ = gCatchTile_RevealOamFramesets[tileFrameIx][i * 3 + 1];
            *dst++ = gCatchTile_RevealOamFramesets[tileFrameIx][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 3:
        gCurrentPinballGame->activeFxType = FX_CATCH_TILE_BURST_2;
        DmaCopy16(3, gCatchTile_BurstStage2_Gfx, (void *)0x06015800, 0x800);
        DmaCopy16(3, gCatchTile_BurstStage2_Pal, OBJ_PLTT_SLOT(PAL_IX_CATCH_TILE_FX), PLTT_SLOT_SIZE);
        gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_TILE_FLASH_FX]->active = TRUE;
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->revealAnimFrameCounter = 0;
        gCurrentPinballGame->startButtonDisabled = TRUE;
        break;
    case 4:
        tileFrameIx = gCurrentPinballGame->revealAnimFrameCounter / 2;
        if (gCurrentPinballGame->revealAnimFrameCounter < 15)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_TILE_FLASH_FX]->active = FALSE;
            gCurrentPinballGame->hatchRevealPhase++;
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex = 0;
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_TILE_FLASH_FX];
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gCatchTile_BurstRevealOamFramesets0[tileFrameIx][i * 3 + 0];
            *dst++ = gCatchTile_BurstRevealOamFramesets0[tileFrameIx][i * 3 + 1];
            *dst++ = gCatchTile_BurstRevealOamFramesets0[tileFrameIx][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 5:
        gCurrentPinballGame->activeFxType = FX_CATCH_TILE_BURST_3;
        DmaCopy16(3, gCatchTile_BurstStage3_Gfx, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gCatchTile_BurstStage3_Pal, OBJ_PLTT_SLOT(PAL_IX_CATCH_TILE_FX), PLTT_SLOT_SIZE);
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
                    gCurrentPinballGame->catchTilePalette[i] = PAL_IX_MON_PORTRAIT;

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
            if (gCurrentPinballGame->catchTileRevealFrameAnimTimer < 0x7000)
                UpdateBurstTileParticles();
        }
        break;
    case 7:
        gCurrentPinballGame->activeFxType = FX_CATCH_TILE_BURST_4;
        DmaCopy16(3, gCatchTile_BurstStage4_Gfx, (void *)0x06015800, 0x1800);
        DmaCopy16(3, gCatchTile_BurstStage4_Pal, OBJ_PLTT_SLOT(PAL_IX_CATCH_TILE_FX), PLTT_SLOT_SIZE);
        gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_PANEL_ELECTRIFY_FX]->active = TRUE;
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->startButtonDisabled = FALSE;
        break;
    case 8:
        if (gCatchTile_RevealFinalTimings[gCurrentPinballGame->revealFramesetIndex] > gCurrentPinballGame->revealAnimFrameCounter)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex++;
            if (gCurrentPinballGame->revealFramesetIndex > 10)
            {
                gCurrentPinballGame->boardSubState++; //Move to next Catch phase
                gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_PANEL_ELECTRIFY_FX]->active = FALSE;
                gCurrentPinballGame->catchTilesBoardAcknowledged = 0;
                gCurrentPinballGame->catchSequentialTilesRevealed = 0;
                gCurrentPinballGame->catchTilesBumperAcknowledgedCount = 0;
                gMain.blendControl = 0xCE;
                gMain.blendBrightness = 0;
                gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_PANEL_ELECTRIFY_FX]->active = FALSE;
                gCurrentPinballGame->revealFramesetIndex = 10;
                gCurrentPinballGame->activeFxType = FX_NONE;
            }
        }

        tileFrameIx = gCurrentPinballGame->revealFramesetIndex;
        group = gMain.fieldSpriteGroups[FIELD_SG_CATCH_BURST_PANEL_ELECTRIFY_FX];
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gCatchTile_BurstRevealOamFramesets1[tileFrameIx][i * 3 + 0];
            *dst++ = gCatchTile_BurstRevealOamFramesets1[tileFrameIx][i * 3 + 1];
            *dst++ = gCatchTile_BurstRevealOamFramesets1[tileFrameIx][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    }
}
