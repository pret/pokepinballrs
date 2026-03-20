#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern u8 gCatchSpriteFrameBuffer[];

extern struct BoardConfig gBoardConfig;
extern u8 gCatchSpritePaletteBuffer[];
extern u8 gCatchSpritePalettes[];

extern const u8 gSapphireCatchTilesGfx[];
extern const u8 gSapphireCatchPalette[];
extern const u8 gDefaultBallPalette[];
extern const u8 gBasketAnimationTilesGfx[][0x480];
extern const u8 gCapturePalette[];
extern const s16 gHatchSequentialFrameData[8][2];
extern const struct Vector16 gJirachiWaypoints[];
extern const u16 gJirachiStarFrameIndices[][10];

extern const u8 (*gMonIconPalettes[])[0x20];
extern const u16 gSapphireFloatOamFramesets[68][3][3];
extern const u16 gSapphireHatchOamFramesets[14][18];
extern const u8 (*gCatchSpriteGfxPtrs[])[0x480];

extern struct SongHeader se_evo_item_appear;

enum HatchTileRevealStates {
    HATCH_TILE_REVEAL_NONE = 0,
    HATCH_TILE_REVEAL_ONE_AT_A_TIME = 1,
    HATCH_TILE_REVEAL_ALL_AT_ONCE = 2
};

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

void CleanupCatchEmState(void)
{
    s16 i;

    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
    gMain.fieldSpriteGroups[18]->available = 0;
    gMain.fieldSpriteGroups[12]->available = 0;
    gCurrentPinballGame->jirachiCollisionEnabled = 0;
    LoadPortraitGraphics(0, 0);
    gCurrentPinballGame->portraitDisplayState = 0;
    ResetEventState();
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->hatchTilePalette[i] = 13;

    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->evoItemCount)
            gCurrentPinballGame->catchLights[i] = 1;
        else
            gCurrentPinballGame->catchLights[i] = 0;
    }
}

void InitCatchEmMode(void)
{
    s16 i, j;

    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardModeType = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_CATCH_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->creatureHitCooldown = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
    gCurrentPinballGame->hatchFrameId = 0;
    gCurrentPinballGame->catchArrowProgress = 0;
    gCurrentPinballGame->catchProgressFlashing = 0;

    if (gCurrentPinballGame->catchEmModeStartCount == 0)
    {
        gCurrentPinballGame->saverTimeRemaining = 6000;
    }
    else
    {
        gCurrentPinballGame->saverTimeRemaining = 4200;
    }
    gCurrentPinballGame->catchEmModeStartCount++;

    DmaCopy16(3, gDefaultBallPalette, (void *)PLTT + 0x180, 0x20);

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->hatchTileShufflePool[i] = i;
    }

    gCurrentPinballGame->hatchGridCellIndex = gMain.systemFrameCount % 6;
    gCurrentPinballGame->hatchTilesRemaining = 5;

    for (j = gCurrentPinballGame->hatchGridCellIndex; j < gCurrentPinballGame->hatchTilesRemaining; j++)
    {
        gCurrentPinballGame->hatchTileShufflePool[j] = gCurrentPinballGame->hatchTileShufflePool[j+1];
    }
}

void UpdateCatchEmMode(void)
{
    s16 i;

    if (gCurrentPinballGame->boardModeType && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 10)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->stageTimer = 200;
        gCurrentPinballGame->boardSubState = 10;
    }

    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        BuildSpeciesWeightsForCatchEmMode();
        gCurrentPinballGame->boardSubState++;
        break;
    case 1:
        PickSpeciesForCatchEmMode();
        if (gMain.mainState != STATE_GAME_IDLE)
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);

        gCurrentPinballGame->boardSubState++;
        break;
    case 2:
        LoadCatchSpriteGraphics();
        gCurrentPinballGame->catchModeArrows = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        LoadPortraitGraphics(3, 0);
        gCurrentPinballGame->hatchTileRevealState = HATCH_TILE_REVEAL_NONE;
        gCurrentPinballGame->hatchRevealPhase = 0;
        gCurrentPinballGame->boardSubState++;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->hatchTilePalette[i] = 15;
        break;
    case 4: // init hatch mode
        if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->modeAnimTimer == 94)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->modeAnimTimer == 93)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->bannerDelayTimer = 0;
                    gCurrentPinballGame->bannerDisplayTimer = 120;
                    gCurrentPinballGame->cameraYScrollTarget = 0;
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->cameraYScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxIndex = 2;
                    gCurrentPinballGame->bannerActive = 1;
                    gCurrentPinballGame->bannerPreserveBallState = 1;
                    gCurrentPinballGame->bannerDisplayDuration = 80;
                    gCurrentPinballGame->bannerSlidePosition = -2500;
                    gCurrentPinballGame->bannerSlideTimer = 50;
                    gCurrentPinballGame->bannerSlideVelocity = 0;
                    DmaCopy16(3, gModeBannerTilemaps[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gModeBannerPalettes[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->modeAnimTimer == 73)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE);
                }
                else if (gCurrentPinballGame->modeAnimTimer < 17)
                {
                    gCurrentPinballGame->boardModeType = 2;
                    gCurrentPinballGame->boardSubState++;
                }
            }
            else // Sapphire board
            {
                if (gCurrentPinballGame->modeAnimTimer == 68)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->modeAnimTimer == 67)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->bannerDelayTimer = 0;
                    gCurrentPinballGame->bannerDisplayTimer = 120;
                    gCurrentPinballGame->cameraYScrollTarget = 0;
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->cameraYScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxIndex = 2;
                    gCurrentPinballGame->bannerActive = 1;
                    gCurrentPinballGame->bannerPreserveBallState = 1;
                    gCurrentPinballGame->bannerDisplayDuration = 80;
                    gCurrentPinballGame->bannerSlidePosition = -2500;
                    gCurrentPinballGame->bannerSlideTimer = 50;
                    gCurrentPinballGame->bannerSlideVelocity = 0;
                    DmaCopy16(3, gModeBannerTilemaps[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gModeBannerPalettes[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->modeAnimTimer == 47)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE2);
                }
                else if (gCurrentPinballGame->modeAnimTimer == 0)
                {
                    gCurrentPinballGame->boardModeType = 2;
                    gCurrentPinballGame->boardSubState++;
                }
            }
        }

        CheckHatchTileRevealState();
        return;
    case 5: // hatch mode running
        gCurrentPinballGame->evoArrowPaletteActive = 1;
        CheckHatchTileRevealState();
        gCurrentPinballGame->stageTimer = 0;
        return;
    case 6:
        gCurrentPinballGame->evoArrowPaletteActive = 0;
        if (gCurrentPinballGame->stageTimer == 0)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->activePortraitType = 10;
            DmaCopy16(3, gSapphireCatchTilesGfx, (void *)0x06015800, 0x1400);
            DmaCopy16(3, gSapphireCatchPalette, (void *)0x050003C0, 0x20);
            m4aSongNumStart(SE_UNKNOWN_0xA7);
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 7:
        PlayEggCrackAnimation();
        return;
    case 8:
        ResetHatchFrameState();
        DmaCopy16(3, gCapturePalette, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gCatchSpritePalettes, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->catchTargetX = 118;
        gCurrentPinballGame->catchTargetY = 264;
        gCurrentPinballGame->evoBlinkTimer = 0;
        gCurrentPinballGame->catchLights[0] = 2;
        gCurrentPinballGame->catchLights[1] = 2;
        gCurrentPinballGame->catchLights[2] = 2;
        DrawCaughtPokemonSprite();
        gCurrentPinballGame->jirachiCollisionEnabled = 1;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->bgmFadeTimer = 140;
        PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].speciesIdRS, 0);
        gCurrentPinballGame->stageTimer = 0;
        return;
    case 9:
        if (gCurrentPinballGame->stageTimer == 0)
        {
            gCurrentPinballGame->bannerDisplayTimer = 0;
            gCurrentPinballGame->stageTimer++;
        }
        DrawCaughtPokemonSprite();
        if (gCurrentPinballGame->creatureHitCooldown)
            gCurrentPinballGame->creatureHitCooldown--;
        break;
    case 10:
        CleanupCaughtPokemonSprite();
        DisableHatchTileDisplay();
        gCurrentPinballGame->boardSubState++;
        break;
    case 11:
        CleanupCatchEmState();
        gCurrentPinballGame->boardSubState++;
        break;
    case 12:
        gCurrentPinballGame->evoArrowPaletteActive = 0;
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->catchLights[2] == 1)
                RequestBoardStateTransition(3);
            else
                RequestBoardStateTransition(1);

            gCurrentPinballGame->boardSubState = 0;
        }
        break;
    }
}

//jirachi.c starts here
void InitJirachiBonus(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardModeType = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 1800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->creatureHitCooldown = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
    gCurrentPinballGame->jirachiWaypointTimer = 0;
    gCurrentPinballGame->jirachiLogicX = 900;
    gCurrentPinballGame->jirachiLogicY = -1400;
    gCurrentPinballGame->jirachiWaypoint = 0;
    gCurrentPinballGame->jirachiTargetX = 0;
    gCurrentPinballGame->jirachiTargetY = 0;
    gCurrentPinballGame->jirachiDisplayX = 0;
    gCurrentPinballGame->jirachiDisplayY = 0;
    gCurrentPinballGame->jirachiCenterX = 0;
    gCurrentPinballGame->jirachiCenterY = 0;
    gCurrentPinballGame->catchArrowProgress = 0;
    gCurrentPinballGame->catchProgressFlashing = 0;
    gCurrentPinballGame->jirachiTagTimer[0] = 0;
    gCurrentPinballGame->jirachiTagTimer[1] = 10;
    gCurrentPinballGame->jirachiTagTimer[2] = 20;
    gCurrentPinballGame->jirachiTagTimer[3] = 30;
    gCurrentPinballGame->saverTimeRemaining = 3240;
    gCurrentPinballGame->allHolesLit = 0;
    gCurrentPinballGame->holeIndicators[0] = 0;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    DmaCopy16(3, gDefaultBallPalette, (void *)0x05000180, 0x20);
}

void UpdateJirachiBonus(void)
{
    struct Vector32 tempVec;
    struct Vector32 deltaVec;
    u16 angle;
    int xx, yy;
    int deltaMagSquared;
    u16 var0;

    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        gCurrentPinballGame->currentSpecies = SPECIES_JIRACHI;
        LoadCatchSpriteGraphics();
        gCurrentPinballGame->boardSubState++;
        return;
    case 1:
        if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->modeAnimTimer == 94)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->modeAnimTimer == 93)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->bannerDelayTimer = 0;
                    gCurrentPinballGame->bannerDisplayTimer = 120;
                    gCurrentPinballGame->cameraYScrollTarget = 0;
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->cameraYScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxIndex = 5;
                    gCurrentPinballGame->bannerActive = 1;
                    gCurrentPinballGame->bannerPreserveBallState = 1;
                    gCurrentPinballGame->bannerDisplayDuration = 80;
                    gCurrentPinballGame->bannerSlidePosition = -2500;
                    gCurrentPinballGame->bannerSlideTimer = 50;
                    gCurrentPinballGame->bannerSlideVelocity = 0;
                    DmaCopy16(3, gModeBannerTilemaps[5], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gModeBannerPalettes[5], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->modeAnimTimer == 73)
                {
                    m4aSongNumStart(MUS_JIRACHI);
                }
                else if (gCurrentPinballGame->modeAnimTimer == 40)
                {
                    gCurrentPinballGame->boardSubState++;
                }
            }
            else
            {
                if (gCurrentPinballGame->modeAnimTimer == 68)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->modeAnimTimer == 67)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->bannerDelayTimer = 0;
                    gCurrentPinballGame->bannerDisplayTimer = 120;
                    gCurrentPinballGame->cameraYScrollTarget = 0;
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->cameraYScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxIndex = 5;
                    gCurrentPinballGame->bannerActive = 1;
                    gCurrentPinballGame->bannerPreserveBallState = 1;
                    gCurrentPinballGame->bannerDisplayDuration = 80;
                    gCurrentPinballGame->bannerSlidePosition = -2500;
                    gCurrentPinballGame->bannerSlideTimer = 50;
                    gCurrentPinballGame->bannerSlideVelocity = 0;
                    DmaCopy16(3, gModeBannerTilemaps[5], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gModeBannerPalettes[5], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                    return;
                }
                else if (gCurrentPinballGame->modeAnimTimer == 47)
                {
                    m4aSongNumStart(MUS_JIRACHI);
                    return;
                }
                else if (gCurrentPinballGame->modeAnimTimer == 40)
                {
                    gCurrentPinballGame->boardSubState++;
                }
            }
        }
        else if ((gMain.modeChangeFlags & MODE_CHANGE_BANNER) && gCurrentPinballGame->bannerSlideTimer == 1)
        {
            gCurrentPinballGame->portraitDisplayState = 3;
            return;
        }
        break;
    case 2:
        DmaCopy16(3, gCapturePalette, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gCatchSpritePalettes, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->evoBlinkTimer = 0;
        gCurrentPinballGame->catchLights[0] = 2;
        gCurrentPinballGame->catchLights[1] = 2;
        gCurrentPinballGame->catchLights[2] = 2;
        gCurrentPinballGame->jirachiCollisionEnabled = 1;
        gMain.fieldSpriteGroups[33]->available = 1;
        DmaCopy16(3, gCatchSpriteGfxBuffer, (void *)0x06010CA0, 0x480);
        gCurrentPinballGame->modeAnimTimer = 40;
        gCurrentPinballGame->jirachiLogicX = 900;
        gCurrentPinballGame->jirachiLogicY = -1400;
        gCurrentPinballGame->jirachiWaypoint = 0;
        gCurrentPinballGame->jirachiTargetX = gJirachiWaypoints[gCurrentPinballGame->jirachiWaypoint].x;
        gCurrentPinballGame->jirachiTargetY = gJirachiWaypoints[gCurrentPinballGame->jirachiWaypoint].y;
        gCurrentPinballGame->stageTimer = 0;
        m4aSongNumStart(SE_JIRACHI_MOVE);
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->jirachiDisplayX = gCurrentPinballGame->jirachiLogicX;
        gCurrentPinballGame->jirachiDisplayY = gCurrentPinballGame->jirachiLogicY;
        return;
    case 3:
        if (gCurrentPinballGame->captureState == 2)
        {
            gCurrentPinballGame->catchTargetX = gCurrentPinballGame->jirachiDisplayX / 10 + 118;
            gCurrentPinballGame->catchTargetY = gCurrentPinballGame->jirachiDisplayY / 10 + 272;
        }
        else
        {
            deltaVec.x = gCurrentPinballGame->jirachiTargetX - gCurrentPinballGame->jirachiLogicX;
            deltaVec.y = gCurrentPinballGame->jirachiTargetY - gCurrentPinballGame->jirachiLogicY;
            xx = deltaVec.x * deltaVec.x;
            yy = deltaVec.y * deltaVec.y;
            deltaMagSquared = xx + yy;
            angle = ArcTan2(deltaVec.x, -deltaVec.y);
            if (deltaMagSquared < 2500)
            {
                tempVec.x = 0;
                tempVec.y = 0;
                if (gCurrentPinballGame->jirachiWaypointTimer < 200)
                {
                    gCurrentPinballGame->jirachiWaypointTimer++;
                }
                else
                {
                    gCurrentPinballGame->jirachiWaypointTimer = 0;
                    if (gCurrentPinballGame->jirachiWaypoint < 11)
                        gCurrentPinballGame->jirachiWaypoint++;
                    else
                        gCurrentPinballGame->jirachiWaypoint = 0;

                    m4aSongNumStart(SE_JIRACHI_MOVE);
                    gCurrentPinballGame->jirachiTargetX = gJirachiWaypoints[gCurrentPinballGame->jirachiWaypoint].x;
                    gCurrentPinballGame->jirachiTargetY = gJirachiWaypoints[gCurrentPinballGame->jirachiWaypoint].y;
                }
            }
            else
            {
                tempVec.x = (Cos(angle) *  7) / 20000;
                tempVec.y = (Sin(angle) * -7) / 20000;
            }

            gCurrentPinballGame->jirachiLogicX += tempVec.x;
            gCurrentPinballGame->jirachiLogicY += tempVec.y;
            var0 = ((gCurrentPinballGame->stageTimer % 80) << 0x10) / 80;
            gCurrentPinballGame->jirachiDisplayX = gCurrentPinballGame->jirachiLogicX;
            gCurrentPinballGame->jirachiDisplayY = gCurrentPinballGame->jirachiLogicY + (Sin(var0) * 60) / 20000;
        }

        if (gCurrentPinballGame->stageTimer < 500)
        {
            gCurrentPinballGame->modeAnimTimer = 40;
            if (gCurrentPinballGame->stageTimer == 499)
                gCurrentPinballGame->boardModeType = 2;
        }

        gCurrentPinballGame->stageTimer++;
        DrawJirachiSprites();
        if (gCurrentPinballGame->creatureHitCooldown)
            gCurrentPinballGame->creatureHitCooldown--;

        if (gCurrentPinballGame->boardModeType && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 5)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_END_OF_BALL2);
            gCurrentPinballGame->boardSubState = 4;
            gCurrentPinballGame->stageTimer = 150;
            gCurrentPinballGame->jirachiCollisionEnabled = 0;
            MPlayStart(&gMPlayInfo_SE1, &se_evo_item_appear);
        }
        return;
    case 4:
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer--;
        else
            gCurrentPinballGame->boardSubState = 5;

        DrawJirachiSprites();
        if (gCurrentPinballGame->creatureHitCooldown)
            gCurrentPinballGame->creatureHitCooldown--;
        break;
    case 5:
        DrawJirachiSprites();
        CleanupJirachiSprites();
        CleanupCatchEmState();
        gCurrentPinballGame->jirachiActivationFlags = 240;
        gCurrentPinballGame->boardSubState = 6;
        gCurrentPinballGame->stageTimer = 0;
        return;
    case 6:
        gCurrentPinballGame->evoArrowPaletteActive = 0;
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->catchLights[2] == 1)
                RequestBoardStateTransition(3);
            else
                RequestBoardStateTransition(1);

            gCurrentPinballGame->boardSubState = 0;
        }
    }
}

//sprite graphics starts here
void LoadCatchSpriteGraphics(void)
{
    s16 i;
    s16 catchIndex;
    const u8 *sp0[3];
    const u8 *spC[3];

    catchIndex = gSpeciesInfo[gCurrentPinballGame->currentSpecies].catchIndex;
    for (i = 0; i < 3; i++)
    {
        sp0[i] = gCatchSpriteGfxPtrs[catchIndex / 5][(i + (catchIndex % 5) * 3)];
        spC[i] = gMonIconPalettes[catchIndex / 5][i * 5 + catchIndex % 5];
    }

    for (i = 0; i < 3; i++)
    {
        DmaCopy16(3, sp0[i], &gCatchSpriteGfxBuffer[i * 0x480], 0x480);
        DmaCopy16(3, spC[i], &gCatchSpritePalettes[i * 0x20], 0x20);
    }

    DmaCopy16(3, gMonIconPalettes[0][15], &gCatchSpritePalettes[0x60], 0x20);
}

void LoadEggSpriteGraphics(void)
{
    s16 eggIndex;
    const u8 *src0;
    const u8 *src1;

    eggIndex= gSpeciesInfo[gCurrentPinballGame->currentSpecies].eggIndex;
    src0 = gMonHatchSpriteGroupGfx[eggIndex / 6][eggIndex % 6];
    src1 = gMonHatchSpriteGroupPals[eggIndex / 6][eggIndex % 6];
    DmaCopy16(3, src0, gCatchSpriteFrameBuffer, 0x10E0);
    DmaCopy16(3, src1, gCatchSpritePaletteBuffer, 0x20);
}

void DrawCaughtPokemonSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 index;

    index = (gMain.fieldFrameCount % 50) / 25;
    group = gMain.fieldSpriteGroups[33];
    if (!group->available)
        return;

    gCurrentPinballGame->jirachiCenterX = 96;
    gCurrentPinballGame->jirachiCenterY = 288;
    group->baseX =  96 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 288 - gCurrentPinballGame->cameraYOffset;
    if (gCurrentPinballGame->captureFlashTimer > 4)
    {
        if (gCurrentPinballGame->captureFlashTimer == 20 || gCurrentPinballGame->captureFlashTimer == 200)
        {
            DmaCopy16(3, gCatchSpriteFlashGfx, (void *)0x06010CA0, 0x480);
        }

        if (gCurrentPinballGame->captureFlashTimer == 24)
        {
            DmaCopy16(3, gCatchSpriteGfxBuffer, (void *)0x06010CA0, 0x480);
        }

        gCurrentPinballGame->captureFlashTimer--;;
    }
    else if (gCurrentPinballGame->randomSpriteVariantSeed == 5)
    {
        DmaCopy16(3, &gCatchSpriteGfxBuffer[index * 0x480], (void *)0x06010CA0, 0x480);
    }

    if (gCurrentPinballGame->captureSequenceTimer < 13)
        priority = 2;
    else
        priority = 1;

    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 4; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].priority = priority;
    }
}

void CleanupCaughtPokemonSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[33];
    if (group->available)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.fieldSpriteGroups[33]->available = 0;
}

void DrawJirachiSprites(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 priority;
    s16 var1;

    index = (gMain.fieldFrameCount % 50) / 25;
    group = gMain.fieldSpriteGroups[33];
    if (group->available)
    {
        gCurrentPinballGame->jirachiCenterX = gCurrentPinballGame->jirachiDisplayX / 10 + 96;
        gCurrentPinballGame->jirachiCenterY = gCurrentPinballGame->jirachiDisplayY / 10 + 288;
        group->baseX = gCurrentPinballGame->jirachiDisplayX / 10 + 96u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->jirachiDisplayY / 10 + 288u - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->boardSubState > 3)
        {
            if (gCurrentPinballGame->stageTimer >= 90)
            {
                index = (150 - gCurrentPinballGame->stageTimer) / 4;
                DmaCopy16(3, &gBasketAnimationTilesGfx[index], (void *)0x06010CA0, 0x480);
            }
            else
            {
                group->baseY = 190;
            }
        }
        else if (gCurrentPinballGame->captureFlashTimer > 4)
        {
            if (gCurrentPinballGame->captureFlashTimer == 20 || gCurrentPinballGame->captureFlashTimer == 200)
            {
                DmaCopy16(3, gCatchSpriteFlashGfx, (void *)0x06010CA0, 0x480);
            }

            if (gCurrentPinballGame->captureFlashTimer == 24)
            {
                DmaCopy16(3, gCatchSpriteGfxBuffer, (void *)0x06010CA0, 0x480);
            }

            gCurrentPinballGame->captureFlashTimer--;
        }
        else if (gCurrentPinballGame->randomSpriteVariantSeed == 5)
        {
            DmaCopy16(3, &gCatchSpriteGfxBuffer[index * 0x480], (void *)0x06010CA0, 0x480);
        }

        if (gCurrentPinballGame->captureState != 2)
        {
            priority = 1;
        }
        else
        {
            if (gCurrentPinballGame->captureSequenceTimer < 13)
                priority = 2;
            else
                priority = 1;
        }

        if (group->baseY >= 200)
            group->baseY = 200;
        else if (group->baseY < -60)
            group->baseY = -60;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].priority = priority;
        }
    }

    for (j = 0; j < 4; j++)
    {

        group = gMain.fieldSpriteGroups[45 + j];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->jirachiStarTagPos[j].x - gCurrentPinballGame->cameraXOffset;
            group->baseY = gCurrentPinballGame->jirachiStarTagPos[j].y - gCurrentPinballGame->cameraYOffset;
            var1 = gJirachiStarFrameIndices[j][9 - gCurrentPinballGame->jirachiTagTimer[j] / 4];
            if (group->baseY >= 200)
                group->baseY = 200;
            else if (group->baseY < -60)
                group->baseY = -60;

            for (i = 0; i < 3; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gSapphireFloatOamFramesets[var1][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->captureState != 2 &&  gCurrentPinballGame->boardSubState < 4)
        {
            if (gCurrentPinballGame->jirachiTagTimer[j] == 0)
            {
                gCurrentPinballGame->jirachiTagTimer[j] = 40;
                gCurrentPinballGame->jirachiStarTagPos[j].x = gCurrentPinballGame->jirachiCenterX;
                gCurrentPinballGame->jirachiStarTagPos[j].y = gCurrentPinballGame->jirachiCenterY + 16;
                gMain.fieldSpriteGroups[45 + j]->available = 1;
            }
        }

        if (gCurrentPinballGame->jirachiTagTimer[j])
        {
            gCurrentPinballGame->jirachiTagTimer[j]--;
            if (gCurrentPinballGame->jirachiTagTimer[j] == 0)
                gMain.fieldSpriteGroups[45 + j]->available = 0;
        }
    }
}

void CleanupJirachiSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[33];
    if (group->available)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.fieldSpriteGroups[33]->available = 0;
    for (i = 0; i < 4; i++)
        gMain.fieldSpriteGroups[45 + i]->available = 0;
}

//draw_catch_tiles
void CheckHatchTileRevealState(void)
{
    // Cross vertical threshold, check completion
    if (gCurrentPinballGame->cameraYViewport > 138)
    {
        if (gCurrentPinballGame->hatchTileRevealState == HATCH_TILE_REVEAL_NONE && gCurrentPinballGame->hatchTilesBumperAcknowledged > 0)
        {
            // Reveal all at once, if the bumpers have been hit enough in one trip up to reveal all tiles
            // This will be in 'banner' mode at this point, scrolling down, and records points mid sequence
            if (gCurrentPinballGame->hatchTilesBoardAcknowledged + 6 == gCurrentPinballGame->hatchTilesBumperAcknowledged)
            {
                gCurrentPinballGame->hatchTileRevealState = HATCH_TILE_REVEAL_ALL_AT_ONCE;
                gCurrentPinballGame->scoreAddedInFrame = 300000;
            }
            else
            {
                gCurrentPinballGame->hatchTileRevealState = HATCH_TILE_REVEAL_ONE_AT_A_TIME;
            }
        }

        gCurrentPinballGame->hatchTilesBoardAcknowledged = gCurrentPinballGame->hatchTilesBumperAcknowledged;
    }

    if (gCurrentPinballGame->hatchTileRevealState == HATCH_TILE_REVEAL_ALL_AT_ONCE)
        RevealAllHatchTilesAtOnce();
    else if (gCurrentPinballGame->hatchTileRevealState == HATCH_TILE_REVEAL_ONE_AT_A_TIME)
        RevealSequentialHatchTiles();
}

void PlayEggCrackAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;

    if (gHatchSequentialFrameData[gCurrentPinballGame->hatchFrameId][1] > gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer)
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
        gCurrentPinballGame->hatchFrameId++;
    }

    if (gCurrentPinballGame->hatchFrameId == 2 && gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer > 3)
    {
        gCurrentPinballGame->portraitDisplayState = 3;
        gMain.fieldSpriteGroups[33]->available = 1;
    }

    if (gCurrentPinballGame->hatchFrameId > 2)
    {
        DmaCopy16(3, gCatchSpritePalettes, (void *)0x050003A0, 0x20);
        DmaCopy16(3, gCatchSpriteGfxBuffer, (void *)0x06010CA0, 0x480);
        DrawCaughtPokemonSprite();
    }

    group = gMain.fieldSpriteGroups[18];
    if (group->available)
    {
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 296 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gSapphireHatchOamFramesets[gHatchSequentialFrameData[gCurrentPinballGame->hatchFrameId][0]][i*3+0];
            *dst++ = gSapphireHatchOamFramesets[gHatchSequentialFrameData[gCurrentPinballGame->hatchFrameId][0]][i*3+1];
            *dst++ = gSapphireHatchOamFramesets[gHatchSequentialFrameData[gCurrentPinballGame->hatchFrameId][0]][i*3+2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gMain.fieldSpriteGroups[18]->available = 1;
    if (gCurrentPinballGame->hatchFrameId > 6)
    {
        gCurrentPinballGame->boardSubState++;
        gMain.fieldSpriteGroups[18]->available = 0;
        gCurrentPinballGame->activePortraitType = 0;
    }
}

void ResetHatchFrameState(void)
{
    s16 i;

    gCurrentPinballGame->hatchFrameId = 0;
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->hatchTilePalette[i] = 13;
}

