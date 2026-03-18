#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern u8 gCatchSpriteFrameBuffer[];
extern u8 gCatchSpritePalettes[];
extern u8 gCatchSequencePalA;
extern u8 gCatchSequencePalB;
extern u8 gCatchSequencePalC;
extern struct BoardConfig gBoardConfig;
extern u8 gCatchSpritePaletteBuffer[];


extern const u8 gSapphireCatchTilesGfx[];
extern const u8 gSapphireCatchPalette[];
extern const u8 gBallFlashPalette;
extern const u8 gBallUpgradeTilesGfx[];
extern const u8 gCaptureScreenTilesGfx[];
extern const u16 gPokeballCaptureOamFrames[][0x30];
extern const u8 gDefaultBallPalette[];
extern const u8 gBasketAnimationTilesGfx[][0x480];
extern const u8 gPikachuSaverTilesGfx[];
extern const s16 gCaptureSequenceTimings[34];
extern const u8 gCapturePalette[];
extern const s8 gCaptureShakeOffsets[];
extern u16 gRouletteWheelContents[][7];
extern const s16 gHatchSequentialFrameData[8][2];
extern const struct Vector16 gJirachiWaypoints[];
extern const s16 gHatchPieceAnimIndices[][12];
extern const u16 gJirachiStarFrameIndices[][10];
extern const s16 gHatchRevealPieceIndices[][16];
extern const s16 gHatchPieceVelocities[][2];
extern const s16 gHatchPieceAffineModes[];
extern const s16 gHatchPieceMatrixNums[6];
extern const u8 (*gMonIconPalettes[])[0x20];
extern const u16 gSapphireFloatOamFramesets[68][3][3];
extern const u16 gHatchParticleOamAttributes[][3];
extern const u16 gHatchAnimOamAttributes[][3];
extern const u16 gSapphireHatchOamFramesets[14][18];
extern const u8 (*gCatchSpriteGfxPtrs[])[0x480];

extern struct SongHeader se_evo_item_appear;
extern struct SongHeader se_roulette_tick;
extern struct SongHeader se_ball_upgrade;
extern struct SongHeader se_unk_9a;

enum HatchTileRevealStates {
    HATCH_TILE_REVEAL_NONE = 0,
    HATCH_TILE_REVEAL_ONE_AT_A_TIME = 1,
    HATCH_TILE_REVEAL_ALL_AT_ONCE = 2
};


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

void InitSequentialTileParticles(void)
{
    s16 i;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->tileParticlePos[i].x = 0;
        gCurrentPinballGame->tileParticlePos[i].y = 0;
        gCurrentPinballGame->tileParticleVel[i].x = 200 - (Random() % 400);
        gCurrentPinballGame->tileParticleVel[i].y = 80 - (Random() % 550);
        gCurrentPinballGame->tileParticleGravity[i] = 10 + (Random() % 15);
    }

    gCurrentPinballGame->particleAnimTimer = 0;
    gMain.fieldSpriteGroups[12]->available = 1;
}

void UpdateSequentialTileParticles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    struct Vector16 tempVector;

    group = gMain.fieldSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            var0 = gHatchPieceAnimIndices[i][gCurrentPinballGame->particleAnimTimer / 4];
            gCurrentPinballGame->tileParticleVel[i].y += gCurrentPinballGame->tileParticleGravity[i];
            if (gCurrentPinballGame->tileParticlePos[i].y < 14000)
            {
                gCurrentPinballGame->tileParticlePos[i].x += gCurrentPinballGame->tileParticleVel[i].x;
                gCurrentPinballGame->tileParticlePos[i].y += gCurrentPinballGame->tileParticleVel[i].y;
            }

            tempVector.x = ((gCurrentPinballGame->hatchGridCellIndex % 3) * 16 +  96u - gCurrentPinballGame->cameraXOffset) + (gCurrentPinballGame->tileParticlePos[i].x / 100);
            tempVector.y = ((gCurrentPinballGame->hatchGridCellIndex / 3) * 16 + 300u - gCurrentPinballGame->cameraYOffset) + (gCurrentPinballGame->tileParticlePos[i].y / 100);
            if (tempVector.y >= 200)
                tempVector.y = 200;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchAnimOamAttributes[var0][0];
            *dst++ = gHatchAnimOamAttributes[var0][1];
            *dst++ = gHatchAnimOamAttributes[var0][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
        }
    }

    if (gCurrentPinballGame->particleAnimTimer < 48)
    {
        gCurrentPinballGame->particleAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0x7100;
        gMain.fieldSpriteGroups[12]->available = 0;
    }
}

void InitBurstTileParticles(void)
{
    s16 i;
    const struct Vector16 *var0;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->tileParticlePos[i].x = ((i % 3) * 16 - 24) * 100;
        gCurrentPinballGame->tileParticlePos[i].y = ((i / 3) * 16 - 28) * 100;
        gCurrentPinballGame->tileParticleVel[i].x = gHatchPieceVelocities[i][0] - ((Random() % 200) - 60);
        gCurrentPinballGame->tileParticleVel[i].y = gHatchPieceVelocities[i][1] - ((Random() % 200) - 60);
        gCurrentPinballGame->tileParticleGravity[i] = (Random() % 4) + 1;
    }

    gCurrentPinballGame->tileParticlePos[0].x = -5600;
    gCurrentPinballGame->tileParticlePos[0].y = -6000;
    gCurrentPinballGame->tileParticleGravity[0] = 3;
    gCurrentPinballGame->tileParticlePos[4].x = -4000;
    gCurrentPinballGame->tileParticlePos[4].y = -4400;
    gCurrentPinballGame->tileParticleGravity[4] = 3;
    gCurrentPinballGame->particleAnimTimer = 0;
    gMain.fieldSpriteGroups[12]->available = 1;
}

void UpdateBurstTileParticles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 index;
    struct Vector16 tempVector;
    s16 sp0[6];
    s16 scale;

    group = gMain.fieldSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            index = gCurrentPinballGame->particleAnimTimer / 5;
            sp0[i] = gHatchRevealPieceIndices[i][index];
            if (gCurrentPinballGame->particleAnimTimer > 4)
            {
                gCurrentPinballGame->tileParticleVel[i].y += gCurrentPinballGame->tileParticleGravity[i];
                if (i == 4)
                    gCurrentPinballGame->tileParticleVel[i].x += gCurrentPinballGame->tileParticleGravity[4] * 4;

                gCurrentPinballGame->tileParticlePos[i].x += gCurrentPinballGame->tileParticleVel[i].x;
                gCurrentPinballGame->tileParticlePos[i].y += gCurrentPinballGame->tileParticleVel[i].y;
            }

            tempVector.x = (gCurrentPinballGame->tileParticlePos[i].x / 100) +  96u - gCurrentPinballGame->cameraXOffset;
            tempVector.y = (gCurrentPinballGame->tileParticlePos[i].y / 100) + 304u - gCurrentPinballGame->cameraYOffset;
            if (tempVector.y >= 160)
                tempVector.y = 160;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchParticleOamAttributes[sp0[i]][0];
            *dst++ = gHatchParticleOamAttributes[sp0[i]][1];
            *dst++ = gHatchParticleOamAttributes[sp0[i]][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
            gOamBuffer[oamSimple->oamId].affineMode = gHatchPieceAffineModes[i];
            gOamBuffer[oamSimple->oamId].matrixNum = gHatchPieceMatrixNums[i];
        }
    }

    scale = ((gCurrentPinballGame->particleAnimTimer * gCurrentPinballGame->particleAnimTimer * 0xD0) / 0x510) + 0x80;
    if (sp0[0] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 2);

    scale = 0x80;
    if (sp0[1] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 3);

    scale = ((gCurrentPinballGame->particleAnimTimer * gCurrentPinballGame->particleAnimTimer * 0x100) / 0x510) + 0x80;
    if (sp0[3] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 4);

    scale = ((gCurrentPinballGame->particleAnimTimer * gCurrentPinballGame->particleAnimTimer * 0x1C0) / 0x510) + 0x40;
    if (sp0[4]== 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 5);

    if (gCurrentPinballGame->particleAnimTimer < 47)
    {
        gCurrentPinballGame->particleAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0x7100;
        gMain.fieldSpriteGroups[12]->available = 0;
    }
}

void InitRouletteWheel(void)
{
    s16 i;

    gMain.fieldSpriteGroups[23]->available = 1;
    gMain.fieldSpriteGroups[20]->available = 1;
    gMain.fieldSpriteGroups[21]->available = 1;
    gMain.blendControl = 0x1C10;
    gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
    gCurrentPinballGame->rouletteStopRequested = 0;
    gCurrentPinballGame->rouletteRotationPeriod = 8;
    gCurrentPinballGame->rouletteSpinSpeed = 0;
    gCurrentPinballGame->rouletteSubOffset = 0;
    if (gCurrentPinballGame->rouletteLevel == 25)
        gCurrentPinballGame->rouletteLevel = 10;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->rouletteSlotValues[i] = gRouletteWheelContents[gCurrentPinballGame->rouletteLevel][i];
        if (gCurrentPinballGame->rouletteSlotValues[i] == 41)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->rouletteSlotValues[i] = 42;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->rouletteSlotValues[i] = 44;
                    break;
                case 4:
                    gCurrentPinballGame->rouletteSlotValues[i] = 45;
                    break;
                }
            }
            else
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->rouletteSlotValues[i] = 41;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->rouletteSlotValues[i] = 43;
                    break;
                case 4:
                    gCurrentPinballGame->rouletteSlotValues[i] = 45;
                    break;
                }
            }
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == 10)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->rouletteSlotValues[i] = gCurrentPinballGame->ballUpgradeType + 10;
            else
                gCurrentPinballGame->rouletteSlotValues[i] = 12;
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == 3)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
            {
                if (gMain.systemFrameCount & 1)
                {
                    if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                        gCurrentPinballGame->rouletteSlotValues[i] = gCurrentPinballGame->ballUpgradeType + 10;
                    else
                        gCurrentPinballGame->rouletteSlotValues[i] = 12;
                }
                else
                {
                    gCurrentPinballGame->rouletteSlotValues[i] = 1;
                }
            }
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == 9)
        {
            if (gCurrentPinballGame->evolvablePartySize <= 0)
                gCurrentPinballGame->rouletteSlotValues[i] = 8;
        }
    }

    gCurrentPinballGame->roulettePortraitId = 21;
    if (gCurrentPinballGame->rouletteLevel < 25)
        gCurrentPinballGame->rouletteLevel++;

    gCurrentPinballGame->rouletteSlotCount = 5;
    if ((gCurrentPinballGame->jirachiActivationFlags & 0xF0) == 0 && gCurrentPinballGame->area > AREA_WILDERNESS)
        gCurrentPinballGame->rouletteSlotCount++;

    gCurrentPinballGame->rouletteSlotCursor = 1;
    gCurrentPinballGame->modeOutcomeValues[0] = gCurrentPinballGame->rouletteSlotValues[0];
    gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->rouletteSlotValues[1];
    LoadPortraitGraphics(2, 0);
    LoadPortraitGraphics(2, 1);
}

void RunRouletteWheel(void)
{
    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        if (gCurrentPinballGame->rouletteStopRequested == 0)
        {
            if ((gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON)) && gCurrentPinballGame->zigzagoonShockWallActive)
            {
                gCurrentPinballGame->zigzagoonState = 2;
                if (gCurrentPinballGame->rouletteSubOffset < 17)
                    gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->modeOutcomeValues[0];

                gCurrentPinballGame->rouletteStopRequested = 1;
                gCurrentPinballGame->rouletteRotationPeriod = 40;
                gCurrentPinballGame->rouletteFrameIndex = 39;
            }
        }
    }

    if (gCurrentPinballGame->rouletteStopRequested == 0)
    {
        gCurrentPinballGame->portraitDisplayState = 1;
        gCurrentPinballGame->rouletteFrameIndex++;
        if (gCurrentPinballGame->rouletteSpinSpeed)
        {
            gCurrentPinballGame->rouletteSpinSpeed--;
            if (gCurrentPinballGame->rouletteSpinSpeed == 0)
            {
                gCurrentPinballGame->rouletteStopRequested = 1;
            }
            else
            {
                if (gCurrentPinballGame->rouletteFrameIndex == gCurrentPinballGame->rouletteRotationPeriod)
                {
                    gCurrentPinballGame->rouletteRotationPeriod = 40 - (gCurrentPinballGame->rouletteSpinSpeed * 34) / gCurrentPinballGame->rouletteInitialSpeed;
                    gCurrentPinballGame->rouletteFrameIndex = 0;
                }
            }
        }
        else if (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON))
        {
            gCurrentPinballGame->rouletteSpinSpeed = (Random() % 200) + 100;
            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                if (gCurrentPinballGame->zigzagoonState == 1)
                {
                    gCurrentPinballGame->rouletteSpinSpeed = 320;
                    gCurrentPinballGame->zigzagoonShockWallActive = 1;
                }
            }

            gCurrentPinballGame->rouletteInitialSpeed = gCurrentPinballGame->rouletteSpinSpeed;
        }

        gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
    }
    else
    {
        gCurrentPinballGame->rouletteFrameIndex++;
        gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
        if (gCurrentPinballGame->rouletteFrameIndex == 0)
        {
            gCurrentPinballGame->modeAnimTimer = 140;
            gMain.fieldSpriteGroups[23]->available = 0;
            gMain.fieldSpriteGroups[20]->available = 0;
            gMain.fieldSpriteGroups[21]->available = 0;
            gCurrentPinballGame->rouletteSubOffset = 0;
            gCurrentPinballGame->portraitDisplayState = 0;
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->shopPurchaseConfirmed = 1;
            gCurrentPinballGame->outcomeFrameCounter = 0;
        }
    }

    if (gCurrentPinballGame->rouletteFrameIndex == 0)
    {
        gCurrentPinballGame->modeOutcomeValues[0] = gCurrentPinballGame->modeOutcomeValues[1];
        LoadPortraitGraphics(2, 0);
        gCurrentPinballGame->rouletteOutcomeId = gCurrentPinballGame->modeOutcomeValues[0];
    }

    if (gCurrentPinballGame->rouletteFrameIndex == 1)
    {
        if (gCurrentPinballGame->rouletteSlotCursor < gCurrentPinballGame->rouletteSlotCount)
            gCurrentPinballGame->rouletteSlotCursor++;
        else
            gCurrentPinballGame->rouletteSlotCursor = 0;

        gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->rouletteSlotValues[gCurrentPinballGame->rouletteSlotCursor];
        LoadPortraitGraphics(2, 1);
        MPlayStart(&gMPlayInfo_SE1, &se_roulette_tick);
    }
}

void ProcessRouletteOutcome(void)
{
    if (gCurrentPinballGame->outcomeFrameCounter < 180)
    {
        if (gCurrentPinballGame->outcomeFrameCounter == 4)
            m4aSongNumStart(MUS_UNKNOWN_0x14);

        if (gCurrentPinballGame->rouletteOutcomeId == 3)
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 120)
                m4aSongNumStart(SE_UNKNOWN_0xB2);
        }

        gCurrentPinballGame->outcomeFrameCounter++;
        if (gCurrentPinballGame->outcomeFrameCounter < 80)
            LoadPortraitGraphics(8, 0);
    }

    switch (gCurrentPinballGame->rouletteOutcomeId)
    {
    case 0:
    case 1:
    case 2:
        gCurrentPinballGame->saverTimeRemaining = (gCurrentPinballGame->rouletteOutcomeId + 1) * 1800;
        break;
    case 3:
        if (gCurrentPinballGame->ballCatchState == 3)
        {
            if (gCurrentPinballGame->outcomeFrameCounter > 124)
            {
                if (gCurrentPinballGame->shopOutcomeRepeatCount < 100)
                {
                    gCurrentPinballGame->shopOutcomeRepeatCount++;
                    gCurrentPinballGame->outcomeFrameCounter = 124;
                }
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 4)
            {
                gCurrentPinballGame->pikaChargeTarget = 168;
                gCurrentPinballGame->pikaChargeProgress = 168;
                gCurrentPinballGame->prevChargeFillValue = 13;
                gCurrentPinballGame->chargeFillValue = 13;
                gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                gCurrentPinballGame->chargeIndicatorYOffset = 120;
                gCurrentPinballGame->fullChargeIndicatorBlinkTimer = 60;
                DmaCopy16(3, gPikachuSaverTilesGfx, (void *)0x06010600, 0x180);
                gCurrentPinballGame->outLanePikaPosition = 2;
                gMain.fieldSpriteGroups[41]->available = 0;
                gCurrentPinballGame->pichuEntranceTimer = 1;
            }
        }
        else
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 120)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 0;
                gCurrentPinballGame->bannerDisplayTimer = 250;
                gCurrentPinballGame->cameraYScrollTarget = 272;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 2;
                gCurrentPinballGame->bannerGfxIndex = 0;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                gCurrentPinballGame->pichuWalkMode = 1;
                gCurrentPinballGame->pichuEntranceTimer = 800;
                gCurrentPinballGame->outLanePikaPosition = 0;
                gCurrentPinballGame->pikaChargeTarget = 168;
                gCurrentPinballGame->pikaChargeProgress = 168;
                gCurrentPinballGame->prevChargeFillValue = 13;
                gCurrentPinballGame->chargeFillValue = 13;
                gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                gCurrentPinballGame->chargeIndicatorYOffset = 120;
                gCurrentPinballGame->fullChargeIndicatorBlinkTimer = 60;
            }

            if (gCurrentPinballGame->pichuEntranceTimer)
            {
                if (gCurrentPinballGame->outcomeFrameCounter >= 176)
                    gCurrentPinballGame->outcomeFrameCounter = 176;
            }
        }
        break;
    case 4:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
            gCurrentPinballGame->oneUpAnimTimer = 90;
        break;
    case 5:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 3) + 33;
        }
        break;
    case 6:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            if (gCurrentPinballGame->rouletteLevel < 6)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 3) + 24;
            else if ((s32) gCurrentPinballGame->rouletteLevel <= 0xA)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 5) + 24;
            else if (gCurrentPinballGame->rouletteLevel % 5 == 0)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 5) + 28;
            else
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 7) + 24;
        }
        break;
    case 7:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            if (gCurrentPinballGame->rouletteLevel < 10)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 3) + 36;
            else
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 5) + 36;
        }
        break;
    case 8:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            RequestBoardStateTransition(4);
            gCurrentPinballGame->modeAnimTimer = 100;
        }
        break;
    case 9:
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 149)
            {
                gCurrentPinballGame->shopEntryTimer = 180;
                gCurrentPinballGame->portraitDisplayState = 3;
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 150)
            {
                gCurrentPinballGame->outcomeFrameCounter = 149;
                gCurrentPinballGame->evolutionShopActive = 1;
                UpdateShopEntryAnimation(1);
                gCurrentPinballGame->sapphireBumperState[0] = 3;
                gCurrentPinballGame->sapphireBumperState[1] = 3;
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 170)
            {
                gCurrentPinballGame->shopDoorTargetFrame = 0;
                gCurrentPinballGame->evolutionShopActive = 0;
                RequestBoardStateTransition(6);
            }
        }
        break;
    case 10:
    case 11:
    case 12:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 13:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 17:
    case 18:
    case 19:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            gCurrentPinballGame->coinRewardLevel = 1;
            gCurrentPinballGame->coinRewardAmount = (gCurrentPinballGame->rouletteOutcomeId - 17) * 20 + 10;
            gCurrentPinballGame->coinRewardTimer = 0;
        }

        if (gCurrentPinballGame->outcomeFrameCounter == 140)
            gCurrentPinballGame->outcomeFrameCounter = 139;
        break;
    case 20:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
            gCurrentPinballGame->timerBonus = 1800;
        break;
    case 21:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            gCurrentPinballGame->modeAnimTimer = 100;
            gCurrentPinballGame->jirachiActivationFlags = 15;
            RequestBoardStateTransition(8);
        }
        break;
    case 22:
        if (gCurrentPinballGame->outcomeFrameCounter == 150 && gCurrentPinballGame->shouldProcessWhiscash == 0)
        {
            gCurrentPinballGame->rubyPondChangeTimer = 0;
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            gCurrentPinballGame->forcePondToWhiscash = TRUE;
        }
        break;
    case 23:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            gCurrentPinballGame->bumperHitsSinceReset = 100;
            gCurrentPinballGame->pelipperFrameTimer = 1800;
            gCurrentPinballGame->pelipperState = 1;
        }
        break;
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->outcomeFrameCounter = 81;

        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->rouletteOutcomeId - 23) * 1000000;
        }
        break;
    case 33:
        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = 100;
        }
        break;
    case 34:
        if (gCurrentPinballGame->outcomeFrameCounter == 70) {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = 500;
        }
        break;
    case 35:
        if (gCurrentPinballGame->outcomeFrameCounter == 70) {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = 900;
        }
        break;
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            gCurrentPinballGame->progressLevel += gCurrentPinballGame->rouletteOutcomeId + 221;
            if (gCurrentPinballGame->progressLevel > 99)
                gCurrentPinballGame->progressLevel = 99;
        }
        break;
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
            RequestBoardStateTransition(3);
        break;
    }
}

void RunBallCaptureSequence(void)
{
    s16 i;
    s16 j;
    s16 temp_r0;
    s16 temp_r3;
    struct Vector16 tempVector;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    if (gCurrentPinballGame->gravityStrengthIndex != 0)
        return;

    // Handle counter increment logic
    if (gCurrentPinballGame->captureSequenceFrame < gCaptureSequenceTimings[gCurrentPinballGame->captureSequenceTimer])
    {
        gCurrentPinballGame->captureSequenceFrame++;

        if (gCurrentPinballGame->captureSequenceFrame >= gCaptureSequenceTimings[gCurrentPinballGame->captureSequenceTimer])
        {
            gCurrentPinballGame->captureSequenceFrame = 0;

            if (gCurrentPinballGame->captureSequenceTimer <= 34)
                gCurrentPinballGame->captureSequenceTimer++;
        }
    }

    switch (gCurrentPinballGame->captureSequenceTimer)
    {
    case 0:
        gMain.blendControl = 0xCE;

        if (gMain.selectedField < MAIN_FIELD_COUNT && (gCurrentPinballGame->boardState == 4 || gCurrentPinballGame->boardState == 8))
            gCurrentPinballGame->boardModeType = 1;

        gCurrentPinballGame->ballFrozenState = 1;

        gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
        gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        gCurrentPinballGame->activePortraitType = 9;
        DmaCopy16(3, gCaptureScreenTilesGfx, 0x06015800, 0x1C00);
        DmaCopy16(3, &gBallUpgradeTilesGfx[gCurrentPinballGame->ballUpgradeType << 9], 0x060164C0, 0x80);
        DmaCopy16(3, &gBallUpgradeTilesGfx[((gCurrentPinballGame->ballUpgradeType * 8 + 4) << 6)], 0x06016760, 0x80);

        gCurrentPinballGame->ballUpgradeTimerFrozen = 1;

        if (gCurrentPinballGame->captureSequenceFrame == 1)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->ballTrailEnabled = 1;
        }

        break;

    case 1:
        if (gCurrentPinballGame->boardState == 4)
        {
            gCurrentPinballGame->evoBlinkTimer = 0;
            gCurrentPinballGame->catchLights[0] = 2;
            gCurrentPinballGame->catchLights[1] = 2;
            gCurrentPinballGame->catchLights[2] = 2;
        }

        gCurrentPinballGame->ball->oamPriority = 0;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        if (gCurrentPinballGame->captureSequenceFrame == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_9a);

        break;

    case 2:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gMain.blendBrightness = 4;

        if (gCurrentPinballGame->captureSequenceFrame > 1)
        {
            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->activePaletteIndex = 1;
            gCurrentPinballGame->paletteSwapActive = 1;
        }
        break;

    case 3:
        gMain.blendBrightness = 7;

        if (gCurrentPinballGame->captureSequenceFrame > 1)
        {
            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->activePaletteIndex = 2;
            gCurrentPinballGame->paletteSwapActive = 1;
        }

        DmaCopy16(3, &gBallFlashPalette, 0x05000220, 0x20);
        break;

    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        temp_r3 = gCurrentPinballGame->captureSequenceTimer - 4;

        if (temp_r3 == 0 || temp_r3 == 6)
        {
            if (gMain.selectedField <= 3 &&
                (
                    (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3)
                ))
            {
                DmaCopy16(3, &gCatchSequencePalB, 0x050003A0, 0x20);
            }

            DmaCopy16(3, &gBallFlashPalette, 0x05000220, 0x20);
            gMain.blendBrightness = 6;
        }
        else
        {
            //TODO: fakematch; unused i. Here for the +4 to parse correctly;
            DmaCopy16(3, gBallPalettes[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
            gMain.blendBrightness = 7;
        }

        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            if (gCurrentPinballGame->boardState == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        gMain.fieldSpriteGroups[3]->available = 1;

        if (gCurrentPinballGame->captureSequenceTimer == 10 && gCurrentPinballGame->captureSequenceFrame == 3)
            gMain.fieldSpriteGroups[3]->available = 0;
        break;
    case 11:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);

        tempVector.x = (gCurrentPinballGame->catchTargetX << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->catchTargetY << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);

        gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
        gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);

        if (gMain.selectedField > 3)
        {
            gCurrentPinballGame->legendaryFlashState = 0;
        }
        else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                 (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
        {
            DmaCopy16(3, &gCatchSpritePalettes, 0x050003A0, 0x20);
        }

        for (i = 0; i < 4; i++)
        {
            gCurrentPinballGame->ball->prevPositionsQ0[i].x = gCurrentPinballGame->ball->positionQ0.x;
            gCurrentPinballGame->ball->prevPositionsQ0[i].y = gCurrentPinballGame->ball->positionQ0.y;
        }
        break;
    case 12:
        temp_r0 = 99 - gCurrentPinballGame->captureSequenceFrame;
        gCurrentPinballGame->trapAngleQ16 -= (temp_r0 * 0x2000) / 100 - 0x2000;
        gCurrentPinballGame->ball->spinAngle -= 0x2000;

        temp_r0 -= 20;

        if (temp_r0 < 0)
        {
            temp_r0 = 0;
            gCurrentPinballGame->ball->ballHidden = 0;
        }

        {
            s32 var_3 = (gCurrentPinballGame->trapSpinRadius * temp_r0) / 80;

            gCurrentPinballGame->ball->positionQ8.x =
                (gCurrentPinballGame->catchTargetX << 8) + Cos(gCurrentPinballGame->trapAngleQ16) * var_3 / 20000;
            gCurrentPinballGame->ball->positionQ8.y =
                (gCurrentPinballGame->catchTargetY << 8) - Sin(gCurrentPinballGame->trapAngleQ16) * var_3 / 20000;
        }
        break;

    case 13:
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ballTrailEnabled = 0;
        gCurrentPinballGame->ball->spinAngle -= 0x2000;
        break;

    case 14:
        DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle -= 0x2000;
        break;

    case 15:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i= gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle -= 0x2000;
        break;

    case 16:
        if (gCurrentPinballGame->captureSequenceFrame == 0)
            m4aSongNumStart(0x9B);

        DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle = 0x7000;
        break;

    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            gCurrentPinballGame->ball->ballHidden = 1;
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;
            temp_r3 = gCaptureShakeOffsets[gCurrentPinballGame->captureSequenceTimer - 17] + 7;

            if (gCurrentPinballGame->boardState == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }
        gMain.fieldSpriteGroups[3]->available = 1;

        if (gCurrentPinballGame->captureSequenceTimer == 18 || gCurrentPinballGame->captureSequenceTimer == 20 || gCurrentPinballGame->captureSequenceTimer == 21)
        {
            gCurrentPinballGame->captureFlashTimer = 200;

            if (gMain.selectedField > 3)
                gCurrentPinballGame->legendaryFlashState = 1;
            else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
                DmaCopy16(3, &gCatchSequencePalA, 0x050003A0, 0x20);
        }
        else if (gCurrentPinballGame->captureSequenceTimer == 19 || gCurrentPinballGame->captureSequenceTimer == 22)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->legendaryFlashState = 3;
            else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
                DmaCopy16(3, &gCatchSequencePalC, 0x050003A0, 0x20);
        }

        if (gCurrentPinballGame->captureSequenceTimer == 23)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->legendaryFlashState = 10;
            else
            {
                if (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9)
                {
                    CleanupCaughtPokemonSprite();
                    gCurrentPinballGame->jirachiCollisionEnabled = 0;
                    m4aMPlayAllStop();
                }

                if (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3)
                {
                    CleanupJirachiSprites();
                    gCurrentPinballGame->jirachiCollisionEnabled = 0;
                    m4aMPlayAllStop();
                }
            }
        }

        if (gCurrentPinballGame->captureSequenceTimer == 28)
        {
            if (gCurrentPinballGame->captureSequenceFrame == 0)
            {
                m4aMPlayAllStop();
                PlayRumble(8);
            }

            if (gCurrentPinballGame->captureSequenceFrame == 2)
                m4aSongNumStart(0x9C);
        }
        break;

    case 26:
        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            temp_r3 = gCaptureShakeOffsets[gCurrentPinballGame->captureSequenceTimer - 17] + 7;

            if (gCurrentPinballGame->boardState == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        break;

    case 29:
        gMain.blendBrightness = 4;
        DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);

        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            for (i = 0; i <= 21; i++)
            {
                oamSimple = &spriteGroup->oam[i];
                gOamBuffer[oamSimple->oamId].y = 190;
            }
        }

        gMain.fieldSpriteGroups[3]->available = 0;
        gCurrentPinballGame->ball->ballHidden = 0;
        gCurrentPinballGame->ball->velocity.y = -256;
        gCurrentPinballGame->ball->velocity.x = 40;
        gCurrentPinballGame->ball->spinSpeed = 256;

        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->activePortraitType = 0;

        break;

    case 30:
        if (gCurrentPinballGame->captureSequenceFrame <= 7)
        {
            if (gCurrentPinballGame->captureSequenceFrame <= 3)
            {
                if (gCurrentPinballGame->captureSequenceFrame == 0)
                {
                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, 0x05000340, 0x60);
                    gCurrentPinballGame->activePaletteIndex = 1;
                    gCurrentPinballGame->paletteSwapActive = 1;
                }
            }
            else
            {
                gMain.blendBrightness = 0;

                if (gCurrentPinballGame->captureSequenceFrame > 4)
                {
                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x140, 0x05000340, 0x60);

                    gCurrentPinballGame->activePaletteIndex = 0;
                    gCurrentPinballGame->paletteSwapActive = 1;
                }
            }
        }

        if (gCurrentPinballGame->boardState == 5 || gCurrentPinballGame->boardState == 8)
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += ((118 << 8) - gCurrentPinballGame->ball->positionQ8.x) / 30;

            if (gCurrentPinballGame->ball->positionQ8.y >= 314 << 8)
            {
                if (gCurrentPinballGame->ball->velocity.y > 49)
                    m4aSongNumStart(0x9D);

                if (gCurrentPinballGame->ball->velocity.y <= -50)
                    m4aSongNumStart(0x9D);

                gCurrentPinballGame->ball->positionQ8.y = 314 << 8;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * -45) / 100;
                gCurrentPinballGame->ball->spinSpeed = (gCurrentPinballGame->ball->spinSpeed * 7) / 10;

                if (gCurrentPinballGame->ball->spinSpeed > 0)
                    gCurrentPinballGame->ball->spinSpeed = -gCurrentPinballGame->ball->spinSpeed;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }

            {
                s16 var_4 = gCurrentPinballGame->ball->velocity.y;

                if (var_4 < 0)
                    var_4 = -var_4;

                if (var_4 > 256)
                    gCurrentPinballGame->captureSequenceFrame--;
            }
        }
        else
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;

            if (gCurrentPinballGame->ball->positionQ8.y >= (gCurrentPinballGame->catchTargetY + 50) << 8)
            {
                m4aSongNumStart(0x9D);
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->catchTargetY + 50) << 8;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * -45) / 100;
                gCurrentPinballGame->ball->spinSpeed = (gCurrentPinballGame->ball->spinSpeed * 7) / 10;

                if (gCurrentPinballGame->ball->spinSpeed > 0)
                    gCurrentPinballGame->ball->spinSpeed = -gCurrentPinballGame->ball->spinSpeed;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }
        }

        gCurrentPinballGame->trapAngleQ16 = 0;
        break;

    case 31:
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        break;

    case 32:
        temp_r0 = 237 - gCurrentPinballGame->captureSequenceFrame;

        if (temp_r0 <= 191)
        {
            if (temp_r0 > 183)
            {
                if (temp_r0 == 185)
                    PlayRumble(6);

                if (temp_r0 == 184)
                    m4aSongNumStart(158);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->spinAngle -= 0x400;
            }
            else if (temp_r0 > 175)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->spinAngle += 0x400;
            }
            else if (temp_r0 > 167)
            {
                if (temp_r0 == 169)
                    PlayRumble(6);

                if (temp_r0 == 168)
                    m4aSongNumStart(0x9E);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->spinAngle -= 0x400;
            }
            else if (temp_r0 > 159)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->spinAngle += 0x400;
            }
            else if (temp_r0 <= 123)
            {
                if (temp_r0 > 115)
                {
                    if (temp_r0 == 117)
                        PlayRumble(6);

                    if (temp_r0 == 116)
                        m4aSongNumStart(0x9E);

                    gCurrentPinballGame->ball->positionQ8.x -= 96;
                    gCurrentPinballGame->ball->spinAngle -= 0x400;
                }
                else if (temp_r0 > 107)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->spinAngle += 0x400;
                }
                else if (temp_r0 > 99)
                {
                    if (temp_r0 == 101)
                        PlayRumble(6);

                    if (temp_r0 == 100)
                        m4aSongNumStart(0x9E);

                    gCurrentPinballGame->ball->positionQ8.x -= 96;
                    gCurrentPinballGame->ball->spinAngle -= 0x400;
                }
                else if (temp_r0 > 91)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->spinAngle += 0x400;
                }
            }
        }

        if (temp_r0 == 0)
        {
            m4aSongNumStart(0x11);
            InitEvolutionSuccessDisplay();
        }

        break;

    case 33:
        gCurrentPinballGame->ball->oamPriority = 3;
        AnimateEvolutionSuccessScreen();

        if (gCurrentPinballGame->captureSequenceFrame <= 229 && gCurrentPinballGame->nameRevealAnimFrame == 150)
            gCurrentPinballGame->nameRevealAnimFrame--;

        if (gCurrentPinballGame->captureSequenceFrame == 270 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            LoadPortraitGraphics(0, 0);
            gCurrentPinballGame->portraitDisplayState = 0;
        }

        if (gCurrentPinballGame->captureSequenceFrame <= 29)
        {
            gMain.scoreOverlayActive = 1;
            temp_r0 = gCurrentPinballGame->captureSequenceFrame;
            gCurrentPinballGame->cutsceneTilemapColumn = temp_r0;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gBG0TilemapBuffer[(i + 15) * 32 + j] = 0xC100;
                }
            }

            DmaCopy16(3, &gBG0TilemapBuffer, 0x06002000, 0x800);
        }

        if (gCurrentPinballGame->captureSequenceFrame >= 240 && gCurrentPinballGame->captureSequenceFrame <= 269)
        {
            temp_r0 = gCurrentPinballGame->captureSequenceFrame - 240;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gBG0TilemapBuffer[(i + 15) * 32 + j] = 511;
                }
            }

            DmaCopy16(3, &gBG0TilemapBuffer, 0x06002000, 0x800);

            if (gCurrentPinballGame->captureSequenceFrame == 269)
            {
                gMain.scoreOverlayActive = 0;

                if (gMain.selectedField < MAIN_FIELD_COUNT)
                {
                    gMain.blendControl = 0;
                    gMain.blendBrightness = 0;
                    gMain.blendAlpha = 0;
                }
            }
        }
        
        if (gCurrentPinballGame->scoreCounterAnimationEnabled) 
            gCurrentPinballGame->captureSequenceFrame = 181;

        if (gCurrentPinballGame->captureSequenceFrame == 180)
        {
            if (gCurrentPinballGame->boardState == 4 || gCurrentPinballGame->boardState == 8)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                
                switch (gCurrentPinballGame->currentSpecies) 
                {
                case 59:
                case 114:
                case 132:
                case 134:
                case 139:
                case 141:
                case 144:
                case 151:
                case 160:
                    gCurrentPinballGame->scoreAddStepSize = 80000;
                    gCurrentPinballGame->scoreAddedInFrame = 5000000;
                    break;
                case 195:
                case 196:
                    gCurrentPinballGame->scoreAddStepSize = 140000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                    break;
                default:
                    gCurrentPinballGame->scoreAddedInFrame = 1000000;
                    break;
                }
            }

            if (gCurrentPinballGame->boardState == 5)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            
                if (gCurrentPinballGame->currentSpecies == SPECIES_PICHU)
                {
                    gCurrentPinballGame->scoreAddStepSize = 140000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                }
                else
                    gCurrentPinballGame->scoreAddedInFrame = 3000000;
            }

            if (gMain.selectedField > MAIN_FIELD_COUNT)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                
                if (gMain.selectedField == FIELD_RAYQUAZA)
                {
                    gCurrentPinballGame->scoreAddStepSize = 400000;
                    gCurrentPinballGame->scoreAddedInFrame = 30000000;
                }
                else
                {
                    gCurrentPinballGame->scoreAddStepSize = 400000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                }
            }
        }

        break;

    case 34:
        gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
        gCurrentPinballGame->ball->oamPriority = 3;
        gCurrentPinballGame->captureState = 0;
        gCurrentPinballGame->captureSequenceFrame = 0;
        gCurrentPinballGame->captureSequenceTimer = 0;

        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->ballFrozenState = 0;
            gCurrentPinballGame->ball->velocity.y = -10;
            gCurrentPinballGame->ball->velocity.x = 20;

            for (i = 0; i <= 2; i++)
            {
                if (i < gCurrentPinballGame->evoItemCount)
                    gCurrentPinballGame->catchLights[i] = 1;
                else
                    gCurrentPinballGame->catchLights[i] = 0;
            }

            if (gCurrentPinballGame->evoItemCount <= 2)
            {
                gCurrentPinballGame->evoCatchLightSlot1 = gCurrentPinballGame->evoItemCount;
                gCurrentPinballGame->evoCatchLightSlot2 = gCurrentPinballGame->evoItemCount;
                gCurrentPinballGame->catchLights[gCurrentPinballGame->evoCatchLightSlot1] = 1;
                gCurrentPinballGame->evoBlinkTimer = 120;
                gCurrentPinballGame->evoItemCount++;
            }

            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->oneUpAnimTimer = 90;

            if (gCurrentPinballGame->bonusCatchCount <= 98)
                gCurrentPinballGame->bonusCatchCount++;

            if (gCurrentPinballGame->boardState == 4)
                gCurrentPinballGame->boardSubState = 10;

            if (gCurrentPinballGame->boardState == 8)
                gCurrentPinballGame->boardSubState = 5;

            if (gCurrentPinballGame->boardState == 5)
                gCurrentPinballGame->boardSubState = 6;

        }
        else
        {
            gCurrentPinballGame->ballFrozenState = 1;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->portraitDisplayState = 3;
            gCurrentPinballGame->boardState = 4;
            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->oneUpAnimTimer = 91;
        }
        RegisterCaptureOrEvolution(0);
        break;
    }

    gCurrentPinballGame->ball->prevPositionsQ0[0].x = gCurrentPinballGame->ball->positionQ0.x;
    gCurrentPinballGame->ball->prevPositionsQ0[0].y = gCurrentPinballGame->ball->positionQ0.y;

    for (i = 2; i >= 0; i--)
    {
        gCurrentPinballGame->ball->prevPositionsQ0[i + 1].x = gCurrentPinballGame->ball->prevPositionsQ0[i].x;
        gCurrentPinballGame->ball->prevPositionsQ0[i + 1].y = gCurrentPinballGame->ball->prevPositionsQ0[i].y;
    }
}
