#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"

extern u8 gCatchSpriteFrameBuffer[];

extern struct BoardConfig gBoardConfig;
extern u8 gCatchSpritePaletteBuffer[];
extern u8 gCatchSpritePalettes[];

extern const u8 gCatchMonAppearFx_Gfx[];
extern const u8 gCatchMonAppearFx_Pal[];
extern const u8 gDefaultTimerPalette[];
extern const u8 gJirachiFx_Gfx[][0x480];
extern const u8 gCapturePalette[];
extern const s16 gCatchMonRevealFrameData[8][2];
extern const struct Vector16 gJirachiWaypoints[];
extern const u16 gJirachiStarFrameIndices[][10];

extern const u8 (*gMonIconPalettes[])[0x20];
extern const u16 gJirachiFloatOamFramesets[68][3][3];
extern const u16 gCatchMonRevealOamFramesets[14][18];
extern const u8 (*gCatchSpriteGfxPtrs[])[0x480];

extern struct SongHeader se_evo_item_appear;

enum catchTileRevealStates {
    CATCH_TILE_REVEAL_NONE = 0,
    CATCH_TILE_REVEAL_ONE_AT_A_TIME = 1,
    CATCH_TILE_REVEAL_ALL_AT_ONCE = 2
};

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

void CleanupCatchEmState(void)
{
    s16 i;

    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
    gMain.fieldSpriteGroups[FIELD_SG_18]->active = FALSE;
    gMain.fieldSpriteGroups[FIELD_SG_MAIN_TILE_BREAK]->active = FALSE;
    gCurrentPinballGame->catchMonCollisionEnabled = FALSE;
    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION,
        PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
    ResetEventState();
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->catchTilePalette[i] = 13;

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

    gCurrentPinballGame->boardSubState = CATCH_EM_SUBSTATE_BUILD_WEIGHTS;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_CATCH_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->creatureHitCooldown = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
    gCurrentPinballGame->catchTilesBoardAcknowledged = 0;
    gCurrentPinballGame->catchSequentialTilesRevealed = 0;
    gCurrentPinballGame->catchTilesBumperAcknowledgedCount = 0;
    gCurrentPinballGame->catchTileRevealFrameAnimTimer = 0;
    gCurrentPinballGame->catchRevealFrameId = 0;
    gCurrentPinballGame->catchArrowProgress = 0;
    gCurrentPinballGame->catchProgressFlashing = FALSE;

    if (gCurrentPinballGame->catchEmModeStartCount == 0)
    {
        gCurrentPinballGame->saverTimeRemaining = 6000;
    }
    else
    {
        gCurrentPinballGame->saverTimeRemaining = 4200;
    }
    gCurrentPinballGame->catchEmModeStartCount++;

    DmaCopy16(3, gDefaultTimerPalette, (void *)PLTT + 0x180, 0x20);

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->catchTileShufflePool[i] = i;
    }

    gCurrentPinballGame->catchGridCellIndex = gMain.systemFrameCount % 6;
    gCurrentPinballGame->catchTilesRemaining = 5;

    for (j = gCurrentPinballGame->catchGridCellIndex; j < gCurrentPinballGame->catchTilesRemaining; j++)
    {
        gCurrentPinballGame->catchTileShufflePool[j] = gCurrentPinballGame->catchTileShufflePool[j+1];
    }
}

void UpdateCatchEmMode(void)
{
    s16 i;

    if (gCurrentPinballGame->eventTimerType
        && gCurrentPinballGame->eventTimer < 2
        && gCurrentPinballGame->boardSubState < CATCH_EM_SUBSTATE_END_CATCH_HIT_PHASE)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->stageTimer = 200;
        gCurrentPinballGame->boardSubState = CATCH_EM_SUBSTATE_END_CATCH_HIT_PHASE;
    }

    switch (gCurrentPinballGame->boardSubState)
    {
    case CATCH_EM_SUBSTATE_BUILD_WEIGHTS:
        BuildSpeciesWeightsForCatchEmMode();
        gCurrentPinballGame->boardSubState++;
        break;
    case CATCH_EM_SUBSTATE_SELECT_SPECIES:
        PickSpeciesForCatchEmMode();
        if (gMain.mainState != STATE_GAME_IDLE)
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);

        gCurrentPinballGame->boardSubState++;
        break;
    case CATCH_EM_SUBSTATE_LOAD_MON_GRAPHICS:
        LoadCatchSpriteGraphics();
        gCurrentPinballGame->catchModeArrows = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case CATCH_EM_SUBSTATE_SETUP_TILE_OVERLAY:
        LoadPortraitGraphics(PORTRAIT_STATE_POKEMON_DISPLAY,
            PORTRAIT_MAIN_SLOT);
        gCurrentPinballGame->catchTileRevealState = CATCH_TILE_REVEAL_NONE;
        gCurrentPinballGame->hatchRevealPhase = 0;
        gCurrentPinballGame->boardSubState++;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->catchTilePalette[i] = 15;
        break;
    case CATCH_EM_SUBSTATE_START_MODE_BANNER:
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
                    gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_CATCH_EM;
                    gCurrentPinballGame->bannerActive = TRUE;
                    gCurrentPinballGame->holdCameraLockAfterBanner = TRUE;
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
                    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_RUNNING;
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
                    gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_CATCH_EM;
                    gCurrentPinballGame->bannerActive = TRUE;
                    gCurrentPinballGame->holdCameraLockAfterBanner = TRUE;
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
                    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_RUNNING;
                    gCurrentPinballGame->boardSubState++;
                }
            }
        }

        CheckCatchTileRevealState();
        return;
    case CATCH_EM_SUBSTATE_AWAITING_BUMPER_HITS:
        gCurrentPinballGame->evoArrowPaletteActive = TRUE;
        CheckCatchTileRevealState();
        gCurrentPinballGame->stageTimer = 0;
        return;
    case CATCH_EM_SUBSTATE_LOAD_MON_SPRITE:
        gCurrentPinballGame->evoArrowPaletteActive = FALSE;
        if (gCurrentPinballGame->stageTimer == 0)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->activePortraitType = 10;
            DmaCopy16(3, gCatchMonAppearFx_Gfx, (void *)0x06015800, 0x1400);
            DmaCopy16(3, gCatchMonAppearFx_Pal, (void *)0x050003C0, 0x20);
            m4aSongNumStart(SE_CATCH_MON_ENTITY_APPEARS);
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case CATCH_EM_SUBSTATE_ANIMATE_MON_APPEAR:
        PlayCatchMonAppearsAnimation();
        return;
    case CATCH_EM_SUBSTATE_SETUP_CATCH_HIT_COUNT:
        ResetCatchFrameState();
        DmaCopy16(3, gCapturePalette, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gCatchSpritePalettes, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->catchTargetX = 118;
        gCurrentPinballGame->catchTargetY = 264;
        gCurrentPinballGame->evoBlinkTimer = 0;
        gCurrentPinballGame->catchLights[0] = 2;
        gCurrentPinballGame->catchLights[1] = 2;
        gCurrentPinballGame->catchLights[2] = 2;
        DrawCatchMonBoardSprite();
        gCurrentPinballGame->catchMonCollisionEnabled = TRUE;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->bgmFadeTimer = 140;
        PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].speciesIdRS, 0);
        gCurrentPinballGame->stageTimer = 0;
        return;
    case CATCH_EM_SUBSTATE_CATCH_HIT_PHASE:
        if (gCurrentPinballGame->stageTimer == 0)
        {
            gCurrentPinballGame->bannerDisplayTimer = 0;
            gCurrentPinballGame->stageTimer++;
        }
        DrawCatchMonBoardSprite();
        if (gCurrentPinballGame->creatureHitCooldown)
            gCurrentPinballGame->creatureHitCooldown--;
        break;
    case CATCH_EM_SUBSTATE_END_CATCH_HIT_PHASE:
        CleanupCatchMonBoardSprite();
        DisableCatchTileDisplay();
        gCurrentPinballGame->boardSubState++;
        break;
    case CATCH_EM_SUBSTATE_BOARD_STATE_CLEANUP:
        CleanupCatchEmState();
        gCurrentPinballGame->boardSubState++;
        break;
    case CATCH_EM_SUBSTATE_PREPARE_NEXT_BOARD_MODE:
        gCurrentPinballGame->evoArrowPaletteActive = FALSE;
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->catchLights[2] == 1)
                RequestBoardStateTransition(MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE);
            else
                RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);

            gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
        }
        break;
    }
}

//jirachi.c starts here
void InitJirachiBonus(void)
{
    gCurrentPinballGame->boardSubState = JIRACHI_CATCH_SUBSTATE_LOAD_MON_SPRITE;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;
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
    gCurrentPinballGame->catchProgressFlashing = FALSE;
    gCurrentPinballGame->jirachiTagTimer[0] = 0;
    gCurrentPinballGame->jirachiTagTimer[1] = 10;
    gCurrentPinballGame->jirachiTagTimer[2] = 20;
    gCurrentPinballGame->jirachiTagTimer[3] = 30;
    gCurrentPinballGame->saverTimeRemaining = 3240;
    gCurrentPinballGame->allHolesLit = FALSE;
    gCurrentPinballGame->holeIndicators[0] = FALSE;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    DmaCopy16(3, gDefaultTimerPalette, (void *)0x05000180, 0x20);
}

void UpdateJirachiBonus(void)
{
    struct Vector32 tempVec;
    struct Vector32 deltaVec;
    u16 angle;
    int xx, yy;
    int squaredDistance;
    u16 var0;

    switch (gCurrentPinballGame->boardSubState)
    {
    case JIRACHI_CATCH_SUBSTATE_LOAD_MON_SPRITE:
        gCurrentPinballGame->currentSpecies = SPECIES_JIRACHI;
        LoadCatchSpriteGraphics();
        gCurrentPinballGame->boardSubState++;
        return;
    case JIRACHI_CATCH_SUBSTATE_START_MODE_BANNER:
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
                    gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_JIRACHI;
                    gCurrentPinballGame->bannerActive = TRUE;
                    gCurrentPinballGame->holdCameraLockAfterBanner = TRUE;
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
                    gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_JIRACHI;
                    gCurrentPinballGame->bannerActive = TRUE;
                    gCurrentPinballGame->holdCameraLockAfterBanner = TRUE;
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
            gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
            return;
        }
        break;
    case JIRACHI_CATCH_SUBSTATE_SETUP_CATCH_HIT_COUNT:
        DmaCopy16(3, gCapturePalette, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gCatchSpritePalettes, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->evoBlinkTimer = 0;
        gCurrentPinballGame->catchLights[0] = 2;
        gCurrentPinballGame->catchLights[1] = 2;
        gCurrentPinballGame->catchLights[2] = 2;
        gCurrentPinballGame->catchMonCollisionEnabled = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY]->active = TRUE;
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
    case JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE:
        if (gCurrentPinballGame->captureState == MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE)
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
            squaredDistance = xx + yy;
            angle = ArcTan2(deltaVec.x, -deltaVec.y);
            if (squaredDistance < 2500)
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
                gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_RUNNING;
        }

        gCurrentPinballGame->stageTimer++;
        DrawJirachiSprites();
        if (gCurrentPinballGame->creatureHitCooldown)
            gCurrentPinballGame->creatureHitCooldown--;

        if (gCurrentPinballGame->eventTimerType
            && gCurrentPinballGame->eventTimer < 2
            && gCurrentPinballGame->boardSubState < JIRACHI_CATCH_SUBSTATE_BOARD_STATE_CLEANUP)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_END_OF_BALL2);
            gCurrentPinballGame->boardSubState = JIRACHI_CATCH_SUBSTATE_ESCAPING;
            gCurrentPinballGame->stageTimer = 150;
            gCurrentPinballGame->catchMonCollisionEnabled = FALSE;
            MPlayStart(&gMPlayInfo_SE1, &se_evo_item_appear);
        }
        return;
    case JIRACHI_CATCH_SUBSTATE_ESCAPING:
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer--;
        else
            gCurrentPinballGame->boardSubState = JIRACHI_CATCH_SUBSTATE_BOARD_STATE_CLEANUP;

        DrawJirachiSprites();
        if (gCurrentPinballGame->creatureHitCooldown)
            gCurrentPinballGame->creatureHitCooldown--;
        break;
    case JIRACHI_CATCH_SUBSTATE_BOARD_STATE_CLEANUP:
        DrawJirachiSprites();
        CleanupJirachiSprites();
        CleanupCatchEmState();
        gCurrentPinballGame->jirachiActivationFlags = 240;
        gCurrentPinballGame->boardSubState = JIRACHI_CATCH_SUBSTATE_PREPARE_NEXT_BOARD_MODE;
        gCurrentPinballGame->stageTimer = 0;
        return;
    case JIRACHI_CATCH_SUBSTATE_PREPARE_NEXT_BOARD_MODE:
        gCurrentPinballGame->evoArrowPaletteActive = FALSE;
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->catchLights[2] == 1)
                RequestBoardStateTransition(MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE);
            else
                RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);

            gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
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

void LoadMonFieldSpriteGraphics(void)
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

void DrawCatchMonBoardSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 index;

    index = (gMain.fieldFrameCount % 50) / 25;
    group = gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY];
    if (!group->active)
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

void CleanupCatchMonBoardSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY];
    if (group->active)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY]->active = FALSE;
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
    group = gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY];
    if (group->active)
    {
        gCurrentPinballGame->jirachiCenterX = gCurrentPinballGame->jirachiDisplayX / 10 + 96;
        gCurrentPinballGame->jirachiCenterY = gCurrentPinballGame->jirachiDisplayY / 10 + 288;
        group->baseX = gCurrentPinballGame->jirachiDisplayX / 10 + 96u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->jirachiDisplayY / 10 + 288u - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->boardSubState > JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE)
        {
            if (gCurrentPinballGame->stageTimer >= 90)
            {
                index = (150 - gCurrentPinballGame->stageTimer) / 4;
                DmaCopy16(3, &gJirachiFx_Gfx[index], (void *)0x06010CA0, 0x480);
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

        if (gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE)
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

        group = gMain.fieldSpriteGroups[FIELD_SG_JIRACHI_STAR_TRAIL_FX_BASE + j];
        if (group->active)
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
                src = gJirachiFloatOamFramesets[var1][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE
            && gCurrentPinballGame->boardSubState < JIRACHI_CATCH_SUBSTATE_ESCAPING)
        {
            if (gCurrentPinballGame->jirachiTagTimer[j] == 0)
            {
                gCurrentPinballGame->jirachiTagTimer[j] = 40;
                gCurrentPinballGame->jirachiStarTagPos[j].x = gCurrentPinballGame->jirachiCenterX;
                gCurrentPinballGame->jirachiStarTagPos[j].y = gCurrentPinballGame->jirachiCenterY + 16;
                gMain.fieldSpriteGroups[FIELD_SG_JIRACHI_STAR_TRAIL_FX_BASE + j]->active = TRUE;
            }
        }

        if (gCurrentPinballGame->jirachiTagTimer[j])
        {
            gCurrentPinballGame->jirachiTagTimer[j]--;
            if (gCurrentPinballGame->jirachiTagTimer[j] == 0)
                gMain.fieldSpriteGroups[FIELD_SG_JIRACHI_STAR_TRAIL_FX_BASE + j]->active = FALSE;
        }
    }
}

void CleanupJirachiSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY];
    if (group->active)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY]->active = FALSE;
    for (i = 0; i < 4; i++)
        gMain.fieldSpriteGroups[FIELD_SG_JIRACHI_STAR_TRAIL_FX_BASE + i]->active = FALSE;
}

//draw_catch_tiles
void CheckCatchTileRevealState(void)
{
    // Cross vertical threshold, check completion
    if (gCurrentPinballGame->cameraYViewport > 138)
    {
        if (gCurrentPinballGame->catchTileRevealState == CATCH_TILE_REVEAL_NONE && gCurrentPinballGame->catchTilesBumperAcknowledgedCount > 0)
        {
            // Reveal all at once, if the bumpers have been hit enough in one trip up to reveal all tiles
            // This will be in 'banner' mode at this point, scrolling down, and records points mid sequence
            if (gCurrentPinballGame->catchTilesBoardAcknowledged + 6 == gCurrentPinballGame->catchTilesBumperAcknowledgedCount)
            {
                gCurrentPinballGame->catchTileRevealState = CATCH_TILE_REVEAL_ALL_AT_ONCE;
                gCurrentPinballGame->scoreAddedInFrame = 300000;
            }
            else
            {
                gCurrentPinballGame->catchTileRevealState = CATCH_TILE_REVEAL_ONE_AT_A_TIME;
            }
        }

        gCurrentPinballGame->catchTilesBoardAcknowledged = gCurrentPinballGame->catchTilesBumperAcknowledgedCount;
    }

    if (gCurrentPinballGame->catchTileRevealState == CATCH_TILE_REVEAL_ALL_AT_ONCE)
        RevealCatchTilesBurst();
    else if (gCurrentPinballGame->catchTileRevealState == CATCH_TILE_REVEAL_ONE_AT_A_TIME)
        RevealCatchTilesSequential();
}

void PlayCatchMonAppearsAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;

    if (gCatchMonRevealFrameData[gCurrentPinballGame->catchRevealFrameId][1] > gCurrentPinballGame->catchTileRevealFrameAnimTimer)
    {
        gCurrentPinballGame->catchTileRevealFrameAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->catchTileRevealFrameAnimTimer = 0;
        gCurrentPinballGame->catchRevealFrameId++;
    }

    if (gCurrentPinballGame->catchRevealFrameId == 2 && gCurrentPinballGame->catchTileRevealFrameAnimTimer > 3)
    {
        gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
        gMain.fieldSpriteGroups[FIELD_SG_CATCH_MON_ENTITY]->active = TRUE;
    }

    if (gCurrentPinballGame->catchRevealFrameId > 2)
    {
        DmaCopy16(3, gCatchSpritePalettes, (void *)0x050003A0, 0x20);
        DmaCopy16(3, gCatchSpriteGfxBuffer, (void *)0x06010CA0, 0x480);
        DrawCatchMonBoardSprite();
    }

    group = gMain.fieldSpriteGroups[FIELD_SG_18];
    if (group->active)
    {
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 296 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gCatchMonRevealOamFramesets[gCatchMonRevealFrameData[gCurrentPinballGame->catchRevealFrameId][0]][i*3+0];
            *dst++ = gCatchMonRevealOamFramesets[gCatchMonRevealFrameData[gCurrentPinballGame->catchRevealFrameId][0]][i*3+1];
            *dst++ = gCatchMonRevealOamFramesets[gCatchMonRevealFrameData[gCurrentPinballGame->catchRevealFrameId][0]][i*3+2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gMain.fieldSpriteGroups[FIELD_SG_18]->active = TRUE;
    if (gCurrentPinballGame->catchRevealFrameId > 6)
    {
        gCurrentPinballGame->boardSubState++;
        gMain.fieldSpriteGroups[FIELD_SG_18]->active = FALSE;
        gCurrentPinballGame->activePortraitType = 0;
    }
}

void ResetCatchFrameState(void)
{
    s16 i;

    gCurrentPinballGame->catchRevealFrameId = 0;
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->catchTilePalette[i] = 13;
}

