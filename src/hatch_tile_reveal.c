#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern u8 gUnknown_0202C7A0[];
extern u8 gUnknown_020306D0[];
extern u8 gUnknown_020306F0;
extern u8 gUnknown_02030710;
extern u8 gUnknown_02030730;
extern struct BoardConfig gBoardConfig;
extern u8 gUnknown_020315D0[];


extern const u8 gUnknown_0839C78C[];
extern const u8 gUnknown_0839DBAC[];
extern const u8 gUnknown_08137F14;
extern const u8 gUnknown_08138014[];
extern const u8 gUnknown_081428D4[];
extern const u16 gUnknown_081B0FE4[][0x30];
extern const u8 gUnknown_081C0064[];
extern const u8 gUnknown_0844AA0C[][0x480];
extern const u8 gUnknown_084C156C[];
extern const s16 gUnknown_086ACF38[34];
extern const u8 gUnknown_086ACF80[];
extern const s8 gUnknown_086ACFF4[];
extern u16 gUnknown_086AD180[][7];
extern const s16 gUnknown_086AD436[8][2];
extern const struct Vector16 gUnknown_086AE124[];
extern const s16 gUnknown_086AE1A4[][12];
extern const u16 gUnknown_086AE154[][10];
extern const s16 gUnknown_086AE234[][16];
extern const s16 gUnknown_086AE2F4[][2];
extern const s16 gUnknown_086AE30C[];
extern const s16 gUnknown_086AE318[6];
extern const u8 (*gUnknown_086B15B4[])[0x20];
extern const u16 gUnknown_086B263C[68][3][3];
extern const u16 gUnknown_086B4E3E[][3];
extern const u16 gUnknown_086B53B4[][3];
extern const u16 gUnknown_086B55DC[14][18];
extern const u8 (*gUnknown_086BB6F4[])[0x480];

extern struct SongHeader se_unk_84;
extern struct SongHeader se_unk_81;
extern struct SongHeader se_unk_87;
extern struct SongHeader se_unk_9a;

enum HatchTileRevealStates {
    HATCH_TILE_REVEAL_NONE = 0,
    HATCH_TILE_REVEAL_ONE_AT_A_TIME = 1,
    HATCH_TILE_REVEAL_ALL_AT_ONCE = 2
};


void RunCatchEmModeStateMachine(void)
{
    s16 i;

    if (gCurrentPinballGame->entityActivePhase && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 10)
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
        LoadCatchModePokemonSpritesheets();
        gCurrentPinballGame->catchModeArrows = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        SetBoardPortraitGraphics(3, 0);
        gCurrentPinballGame->hatchTileRevealState = HATCH_TILE_REVEAL_NONE;
        gCurrentPinballGame->hatchTileAnimPhase = 0;
        gCurrentPinballGame->boardSubState++;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->pondEntityPaletteIds[i] = 15;
        break;
    case 4: // init hatch mode
        if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->sequenceTimer == 94)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->sequenceTimer == 93)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->scrollDelayFrames = 0;
                    gCurrentPinballGame->scrollHoldFrames = 120;
                    gCurrentPinballGame->scrollTargetBottomY = 0;
                    gCurrentPinballGame->fieldScrollOffsetY = 0;
                    gCurrentPinballGame->fieldScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxVariant = 2;
                    gCurrentPinballGame->scrollOverrideActive = 1;
                    gCurrentPinballGame->scrollFromBottom = 1;
                    gCurrentPinballGame->fieldEntryAnimTimer = 80;
                    gCurrentPinballGame->bannerScrollPosQ10 = -2500;
                    gCurrentPinballGame->bannerAnimPhase = 50;
                    gCurrentPinballGame->bannerScrollVelocity = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->sequenceTimer == 73)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE);
                }
                else if (gCurrentPinballGame->sequenceTimer < 17)
                {
                    gCurrentPinballGame->entityActivePhase = 2;
                    gCurrentPinballGame->boardSubState++;
                }
            }
            else // Sapphire board
            {
                if (gCurrentPinballGame->sequenceTimer == 68)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->sequenceTimer == 67)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->scrollDelayFrames = 0;
                    gCurrentPinballGame->scrollHoldFrames = 120;
                    gCurrentPinballGame->scrollTargetBottomY = 0;
                    gCurrentPinballGame->fieldScrollOffsetY = 0;
                    gCurrentPinballGame->fieldScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxVariant = 2;
                    gCurrentPinballGame->scrollOverrideActive = 1;
                    gCurrentPinballGame->scrollFromBottom = 1;
                    gCurrentPinballGame->fieldEntryAnimTimer = 80;
                    gCurrentPinballGame->bannerScrollPosQ10 = -2500;
                    gCurrentPinballGame->bannerAnimPhase = 50;
                    gCurrentPinballGame->bannerScrollVelocity = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->sequenceTimer == 47)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE2);
                }
                else if (gCurrentPinballGame->sequenceTimer == 0)
                {
                    gCurrentPinballGame->entityActivePhase = 2;
                    gCurrentPinballGame->boardSubState++;
                }
            }
        }

        CheckHatchTileRevealState();
        return;
    case 5: // hatch mode running
        gCurrentPinballGame->hatchModeBlinkActive = 1;
        CheckHatchTileRevealState();
        gCurrentPinballGame->stageTimer = 0;
        return;
    case 6:
        gCurrentPinballGame->hatchModeBlinkActive = 0;
        if (gCurrentPinballGame->stageTimer == 0)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->bannerType = 10;
            DmaCopy16(3, gUnknown_0839C78C, (void *)0x06015800, 0x1400);
            DmaCopy16(3, gUnknown_0839DBAC, (void *)0x050003C0, 0x20);
            m4aSongNumStart(SE_UNKNOWN_0xA7);
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 7:
        AnimateEggHatchSequence();
        return;
    case 8:
        ResetHatchAnimationState();
        DmaCopy16(3, gUnknown_086ACF80, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gUnknown_020306D0, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->entityCenterX = 118;
        gCurrentPinballGame->entityCenterY = 264;
        gCurrentPinballGame->bumperFlashAnimTimer = 0;
        gCurrentPinballGame->bumperHitTimers[0] = 2;
        gCurrentPinballGame->bumperHitTimers[1] = 2;
        gCurrentPinballGame->bumperHitTimers[2] = 2;
        DrawCatchModePokemonSprite();
        gCurrentPinballGame->catchCollisionActive = 1;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->bgmVolumeRestoreTimer = 140;
        PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].mainSeriesIndexNumber, 0);
        gCurrentPinballGame->stageTimer = 0;
        return;
    case 9:
        if (gCurrentPinballGame->stageTimer == 0)
        {
            gCurrentPinballGame->scrollHoldFrames = 0;
            gCurrentPinballGame->stageTimer++;
        }
        DrawCatchModePokemonSprite();
        if (gCurrentPinballGame->catchHitInvulnTimer)
            gCurrentPinballGame->catchHitInvulnTimer--;
        break;
    case 10:
        HideCatchModePokemonSprite();
        HideHatchRevealSprites();
        gCurrentPinballGame->boardSubState++;
        break;
    case 11:
        CleanupAfterCatchHatchMode();
        gCurrentPinballGame->boardSubState++;
        break;
    case 12:
        gCurrentPinballGame->hatchModeBlinkActive = 0;
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->bumperHitTimers[2] == 1)
                RequestBoardTransition(3);
            else
                RequestBoardTransition(1);

            gCurrentPinballGame->boardSubState = 0;
        }
        break;
    }
}

void InitCatchEmMode(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->entityActivePhase = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 1800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->catchModeHitCount = 0;
    gCurrentPinballGame->catchHitInvulnTimer = 0;
    gCurrentPinballGame->catchHitReactionTimer = 0;
    gCurrentPinballGame->jirachiWaypointTimer = 0;
    gCurrentPinballGame->jirachiPosX = 900;
    gCurrentPinballGame->jirachiPosY = -1400;
    gCurrentPinballGame->jirachiWaypointIndex = 0;
    gCurrentPinballGame->jirachiTargetX = 0;
    gCurrentPinballGame->jirachiTargetY = 0;
    gCurrentPinballGame->jirachiRenderX = 0;
    gCurrentPinballGame->jirachiRenderY = 0;
    gCurrentPinballGame->jirachiSpriteX = 0;
    gCurrentPinballGame->jirachiSpriteY = 0;
    gCurrentPinballGame->savedCatchArrows = 0;
    gCurrentPinballGame->catchArrowIndicatorBlink = 0;
    gCurrentPinballGame->starParticleTimers[0] = 0;
    gCurrentPinballGame->starParticleTimers[1] = 10;
    gCurrentPinballGame->starParticleTimers[2] = 20;
    gCurrentPinballGame->starParticleTimers[3] = 30;
    gCurrentPinballGame->modeTimerFrames = 3240;
    gCurrentPinballGame->allHolesCompleted = 0;
    gCurrentPinballGame->holeIndicators[0] = 0;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
}

void RunJirachiModeStateMachine(void)
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
        LoadCatchModePokemonSpritesheets();
        gCurrentPinballGame->boardSubState++;
        return;
    case 1:
        if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->sequenceTimer == 94)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->sequenceTimer == 93)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->scrollDelayFrames = 0;
                    gCurrentPinballGame->scrollHoldFrames = 120;
                    gCurrentPinballGame->scrollTargetBottomY = 0;
                    gCurrentPinballGame->fieldScrollOffsetY = 0;
                    gCurrentPinballGame->fieldScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxVariant = 5;
                    gCurrentPinballGame->scrollOverrideActive = 1;
                    gCurrentPinballGame->scrollFromBottom = 1;
                    gCurrentPinballGame->fieldEntryAnimTimer = 80;
                    gCurrentPinballGame->bannerScrollPosQ10 = -2500;
                    gCurrentPinballGame->bannerAnimPhase = 50;
                    gCurrentPinballGame->bannerScrollVelocity = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[5], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[5], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->sequenceTimer == 73)
                {
                    m4aSongNumStart(MUS_JIRACHI);
                }
                else if (gCurrentPinballGame->sequenceTimer == 40)
                {
                    gCurrentPinballGame->boardSubState++;
                }
            }
            else
            {
                if (gCurrentPinballGame->sequenceTimer == 68)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->sequenceTimer == 67)
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->scrollDelayFrames = 0;
                    gCurrentPinballGame->scrollHoldFrames = 120;
                    gCurrentPinballGame->scrollTargetBottomY = 0;
                    gCurrentPinballGame->fieldScrollOffsetY = 0;
                    gCurrentPinballGame->fieldScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxVariant = 5;
                    gCurrentPinballGame->scrollOverrideActive = 1;
                    gCurrentPinballGame->scrollFromBottom = 1;
                    gCurrentPinballGame->fieldEntryAnimTimer = 80;
                    gCurrentPinballGame->bannerScrollPosQ10 = -2500;
                    gCurrentPinballGame->bannerAnimPhase = 50;
                    gCurrentPinballGame->bannerScrollVelocity = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[5], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[5], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                    return;
                }
                else if (gCurrentPinballGame->sequenceTimer == 47)
                {
                    m4aSongNumStart(MUS_JIRACHI);
                    return;
                }
                else if (gCurrentPinballGame->sequenceTimer == 40)
                {
                    gCurrentPinballGame->boardSubState++;
                }
            }
        }
        else if ((gMain.modeChangeFlags & MODE_CHANGE_BANNER) && gCurrentPinballGame->bannerAnimPhase == 1)
        {
            gCurrentPinballGame->hatchRevealState = 3;
            return;
        }
        break;
    case 2:
        DmaCopy16(3, gUnknown_086ACF80, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gUnknown_020306D0, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->bumperFlashAnimTimer = 0;
        gCurrentPinballGame->bumperHitTimers[0] = 2;
        gCurrentPinballGame->bumperHitTimers[1] = 2;
        gCurrentPinballGame->bumperHitTimers[2] = 2;
        gCurrentPinballGame->catchCollisionActive = 1;
        gMain.boardSpriteGroups[33]->available = 1;
        DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
        gCurrentPinballGame->sequenceTimer = 40;
        gCurrentPinballGame->jirachiPosX = 900;
        gCurrentPinballGame->jirachiPosY = -1400;
        gCurrentPinballGame->jirachiWaypointIndex = 0;
        gCurrentPinballGame->jirachiTargetX = gUnknown_086AE124[gCurrentPinballGame->jirachiWaypointIndex].x;
        gCurrentPinballGame->jirachiTargetY = gUnknown_086AE124[gCurrentPinballGame->jirachiWaypointIndex].y;
        gCurrentPinballGame->stageTimer = 0;
        m4aSongNumStart(SE_JIRACHI_MOVE);
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->jirachiRenderX = gCurrentPinballGame->jirachiPosX;
        gCurrentPinballGame->jirachiRenderY = gCurrentPinballGame->jirachiPosY;
        return;
    case 3:
        if (gCurrentPinballGame->catchModeHitPhase == 2)
        {
            gCurrentPinballGame->entityCenterX = gCurrentPinballGame->jirachiRenderX / 10 + 118;
            gCurrentPinballGame->entityCenterY = gCurrentPinballGame->jirachiRenderY / 10 + 272;
        }
        else
        {
            deltaVec.x = gCurrentPinballGame->jirachiTargetX - gCurrentPinballGame->jirachiPosX;
            deltaVec.y = gCurrentPinballGame->jirachiTargetY - gCurrentPinballGame->jirachiPosY;
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
                    if (gCurrentPinballGame->jirachiWaypointIndex < 11)
                        gCurrentPinballGame->jirachiWaypointIndex++;
                    else
                        gCurrentPinballGame->jirachiWaypointIndex = 0;

                    m4aSongNumStart(SE_JIRACHI_MOVE);
                    gCurrentPinballGame->jirachiTargetX = gUnknown_086AE124[gCurrentPinballGame->jirachiWaypointIndex].x;
                    gCurrentPinballGame->jirachiTargetY = gUnknown_086AE124[gCurrentPinballGame->jirachiWaypointIndex].y;
                }
            }
            else
            {
                tempVec.x = (Cos(angle) *  7) / 20000;
                tempVec.y = (Sin(angle) * -7) / 20000;
            }

            gCurrentPinballGame->jirachiPosX += tempVec.x;
            gCurrentPinballGame->jirachiPosY += tempVec.y;
            var0 = ((gCurrentPinballGame->stageTimer % 80) << 0x10) / 80;
            gCurrentPinballGame->jirachiRenderX = gCurrentPinballGame->jirachiPosX;
            gCurrentPinballGame->jirachiRenderY = gCurrentPinballGame->jirachiPosY + (Sin(var0) * 60) / 20000;
        }

        if (gCurrentPinballGame->stageTimer < 500)
        {
            gCurrentPinballGame->sequenceTimer = 40;
            if (gCurrentPinballGame->stageTimer == 499)
                gCurrentPinballGame->entityActivePhase = 2;
        }

        gCurrentPinballGame->stageTimer++;
        DrawJirachiModePokemonAndStars();
        if (gCurrentPinballGame->catchHitInvulnTimer)
            gCurrentPinballGame->catchHitInvulnTimer--;

        if (gCurrentPinballGame->entityActivePhase && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 5)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_END_OF_BALL2);
            gCurrentPinballGame->boardSubState = 4;
            gCurrentPinballGame->stageTimer = 150;
            gCurrentPinballGame->catchCollisionActive = 0;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_84);
        }
        return;
    case 4:
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer--;
        else
            gCurrentPinballGame->boardSubState = 5;

        DrawJirachiModePokemonAndStars();
        if (gCurrentPinballGame->catchHitInvulnTimer)
            gCurrentPinballGame->catchHitInvulnTimer--;
        break;
    case 5:
        DrawJirachiModePokemonAndStars();
        HideJirachiModeSprites();
        CleanupAfterCatchHatchMode();
        gCurrentPinballGame->hatchModeFlags = 240;
        gCurrentPinballGame->boardSubState = 6;
        gCurrentPinballGame->stageTimer = 0;
        return;
    case 6:
        gCurrentPinballGame->hatchModeBlinkActive = 0;
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->bumperHitTimers[2] == 1)
                RequestBoardTransition(3);
            else
                RequestBoardTransition(1);

            gCurrentPinballGame->boardSubState = 0;
        }
    }
}

void LoadCatchModePokemonSpritesheets(void)
{
    s16 i;
    s16 catchIndex;
    const u8 *sp0[3];
    const u8 *spC[3];

    catchIndex = gSpeciesInfo[gCurrentPinballGame->currentSpecies].catchIndex;
    for (i = 0; i < 3; i++)
    {
        sp0[i] = gUnknown_086BB6F4[catchIndex / 5][(i + (catchIndex % 5) * 3)];
        spC[i] = gUnknown_086B15B4[catchIndex / 5][i * 5 + catchIndex % 5];
    }

    for (i = 0; i < 3; i++)
    {
        DmaCopy16(3, sp0[i], &gUnknown_02030760[i * 0x480], 0x480);
        DmaCopy16(3, spC[i], &gUnknown_020306D0[i * 0x20], 0x20);
    }

    DmaCopy16(3, gUnknown_086B15B4[0][15], &gUnknown_020306D0[0x60], 0x20);
}

void LoadHatchModePokemonSpritesheets(void)
{
    s16 eggIndex;
    const u8 *src0;
    const u8 *src1;

    eggIndex= gSpeciesInfo[gCurrentPinballGame->currentSpecies].eggIndex;
    src0 = gMonHatchSpriteGroupGfx[eggIndex / 6][eggIndex % 6];
    src1 = gMonHatchSpriteGroupPals[eggIndex / 6][eggIndex % 6];
    DmaCopy16(3, src0, gUnknown_0202C7A0, 0x10E0);
    DmaCopy16(3, src1, gUnknown_020315D0, 0x20);
}

void DrawCatchModePokemonSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 index;

    index = (gMain.fieldFrameCount % 50) / 25;
    group = gMain.boardSpriteGroups[33];
    if (!group->available)
        return;

    gCurrentPinballGame->jirachiSpriteX = 96;
    gCurrentPinballGame->jirachiSpriteY = 288;
    group->baseX =  96 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 288 - gCurrentPinballGame->bgScrollYWithOffset;
    if (gCurrentPinballGame->catchHitReactionTimer > 4)
    {
        if (gCurrentPinballGame->catchHitReactionTimer == 20 || gCurrentPinballGame->catchHitReactionTimer == 200)
        {
            DmaCopy16(3, gUnknown_02031060, (void *)0x06010CA0, 0x480);
        }

        if (gCurrentPinballGame->catchHitReactionTimer == 24)
        {
            DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
        }

        gCurrentPinballGame->catchHitReactionTimer--;;
    }
    else if (gCurrentPinballGame->spriteUpdateSlot == 5)
    {
        DmaCopy16(3, &gUnknown_02030760[index * 0x480], (void *)0x06010CA0, 0x480);
    }

    if (gCurrentPinballGame->captureSequencePhase < 13)
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

void HideCatchModePokemonSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.boardSpriteGroups[33];
    if (group->available)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.boardSpriteGroups[33]->available = 0;
}

void DrawJirachiModePokemonAndStars(void)
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
    group = gMain.boardSpriteGroups[33];
    if (group->available)
    {
        gCurrentPinballGame->jirachiSpriteX = gCurrentPinballGame->jirachiRenderX / 10 + 96;
        gCurrentPinballGame->jirachiSpriteY = gCurrentPinballGame->jirachiRenderY / 10 + 288;
        group->baseX = gCurrentPinballGame->jirachiRenderX / 10 + 96u - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->jirachiRenderY / 10 + 288u - gCurrentPinballGame->bgScrollYWithOffset;
        if (gCurrentPinballGame->boardSubState > 3)
        {
            if (gCurrentPinballGame->stageTimer >= 90)
            {
                index = (150 - gCurrentPinballGame->stageTimer) / 4;
                DmaCopy16(3, &gUnknown_0844AA0C[index], (void *)0x06010CA0, 0x480);
            }
            else
            {
                group->baseY = 190;
            }
        }
        else if (gCurrentPinballGame->catchHitReactionTimer > 4)
        {
            if (gCurrentPinballGame->catchHitReactionTimer == 20 || gCurrentPinballGame->catchHitReactionTimer == 200)
            {
                DmaCopy16(3, gUnknown_02031060, (void *)0x06010CA0, 0x480);
            }

            if (gCurrentPinballGame->catchHitReactionTimer == 24)
            {
                DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
            }

            gCurrentPinballGame->catchHitReactionTimer--;
        }
        else if (gCurrentPinballGame->spriteUpdateSlot == 5)
        {
            DmaCopy16(3, &gUnknown_02030760[index * 0x480], (void *)0x06010CA0, 0x480);
        }

        if (gCurrentPinballGame->catchModeHitPhase != 2)
        {
            priority = 1;
        }
        else
        {
            if (gCurrentPinballGame->captureSequencePhase < 13)
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

        group = gMain.boardSpriteGroups[45 + j];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->starParticlePositions[j].x - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = gCurrentPinballGame->starParticlePositions[j].y - gCurrentPinballGame->bgScrollYWithOffset;
            var1 = gUnknown_086AE154[j][9 - gCurrentPinballGame->starParticleTimers[j] / 4];
            if (group->baseY >= 200)
                group->baseY = 200;
            else if (group->baseY < -60)
                group->baseY = -60;

            for (i = 0; i < 3; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B263C[var1][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->catchModeHitPhase != 2 &&  gCurrentPinballGame->boardSubState < 4)
        {
            if (gCurrentPinballGame->starParticleTimers[j] == 0)
            {
                gCurrentPinballGame->starParticleTimers[j] = 40;
                gCurrentPinballGame->starParticlePositions[j].x = gCurrentPinballGame->jirachiSpriteX;
                gCurrentPinballGame->starParticlePositions[j].y = gCurrentPinballGame->jirachiSpriteY + 16;
                gMain.boardSpriteGroups[45 + j]->available = 1;
            }
        }

        if (gCurrentPinballGame->starParticleTimers[j])
        {
            gCurrentPinballGame->starParticleTimers[j]--;
            if (gCurrentPinballGame->starParticleTimers[j] == 0)
                gMain.boardSpriteGroups[45 + j]->available = 0;
        }
    }
}

void HideJirachiModeSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.boardSpriteGroups[33];
    if (group->available)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.boardSpriteGroups[33]->available = 0;
    for (i = 0; i < 4; i++)
        gMain.boardSpriteGroups[45 + i]->available = 0;
}

void CheckHatchTileRevealState(void)
{
    // Cross vertical threshold, check completion
    if (gCurrentPinballGame->viewportBottomY > 138)
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

void AnimateEggHatchSequence(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;

    if (gUnknown_086AD436[gCurrentPinballGame->hatchFrameId][1] > gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer)
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
        gCurrentPinballGame->hatchRevealState = 3;
        gMain.boardSpriteGroups[33]->available = 1;
    }

    if (gCurrentPinballGame->hatchFrameId > 2)
    {
        DmaCopy16(3, gUnknown_020306D0, (void *)0x050003A0, 0x20);
        DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
        DrawCatchModePokemonSprite();
    }

    group = gMain.boardSpriteGroups[18];
    if (group->available)
    {
        group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 296 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B55DC[gUnknown_086AD436[gCurrentPinballGame->hatchFrameId][0]][i*3+0];
            *dst++ = gUnknown_086B55DC[gUnknown_086AD436[gCurrentPinballGame->hatchFrameId][0]][i*3+1];
            *dst++ = gUnknown_086B55DC[gUnknown_086AD436[gCurrentPinballGame->hatchFrameId][0]][i*3+2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gMain.boardSpriteGroups[18]->available = 1;
    if (gCurrentPinballGame->hatchFrameId > 6)
    {
        gCurrentPinballGame->boardSubState++;
        gMain.boardSpriteGroups[18]->available = 0;
        gCurrentPinballGame->bannerType = 0;
    }
}

void ResetHatchAnimationState(void)
{
    s16 i;

    gCurrentPinballGame->hatchFrameId = 0;
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->pondEntityPaletteIds[i] = 13;
}

void InitHatchTileExplodeParticles(void)
{
    s16 i;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->hatchShardPosition[i].x = 0;
        gCurrentPinballGame->hatchShardPosition[i].y = 0;
        gCurrentPinballGame->hatchShardVelocity[i].x = 200 - (Random() % 400);
        gCurrentPinballGame->hatchShardVelocity[i].y = 80 - (Random() % 550);
        gCurrentPinballGame->hatchShardGravity[i] = 10 + (Random() % 15);
    }

    gCurrentPinballGame->hatchParticleFrame = 0;
    gMain.boardSpriteGroups[12]->available = 1;
}

void AnimateHatchTileExplodeParticles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    struct Vector16 tempVector;

    group = gMain.boardSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            var0 = gUnknown_086AE1A4[i][gCurrentPinballGame->hatchParticleFrame / 4];
            gCurrentPinballGame->hatchShardVelocity[i].y += gCurrentPinballGame->hatchShardGravity[i];
            if (gCurrentPinballGame->hatchShardPosition[i].y < 14000)
            {
                gCurrentPinballGame->hatchShardPosition[i].x += gCurrentPinballGame->hatchShardVelocity[i].x;
                gCurrentPinballGame->hatchShardPosition[i].y += gCurrentPinballGame->hatchShardVelocity[i].y;
            }

            tempVector.x = ((gCurrentPinballGame->selectedHatchTileIndex % 3) * 16 +  96u - gCurrentPinballGame->bgScrollXCopy) + (gCurrentPinballGame->hatchShardPosition[i].x / 100);
            tempVector.y = ((gCurrentPinballGame->selectedHatchTileIndex / 3) * 16 + 300u - gCurrentPinballGame->bgScrollYWithOffset) + (gCurrentPinballGame->hatchShardPosition[i].y / 100);
            if (tempVector.y >= 200)
                tempVector.y = 200;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B53B4[var0][0];
            *dst++ = gUnknown_086B53B4[var0][1];
            *dst++ = gUnknown_086B53B4[var0][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
        }
    }

    if (gCurrentPinballGame->hatchParticleFrame < 48)
    {
        gCurrentPinballGame->hatchParticleFrame++;
    }
    else
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0x7100;
        gMain.boardSpriteGroups[12]->available = 0;
    }
}

void InitHatchTileRevealAllParticles(void)
{
    s16 i;
    const struct Vector16 *var0;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->hatchShardPosition[i].x = ((i % 3) * 16 - 24) * 100;
        gCurrentPinballGame->hatchShardPosition[i].y = ((i / 3) * 16 - 28) * 100;
        gCurrentPinballGame->hatchShardVelocity[i].x = gUnknown_086AE2F4[i][0] - ((Random() % 200) - 60);
        gCurrentPinballGame->hatchShardVelocity[i].y = gUnknown_086AE2F4[i][1] - ((Random() % 200) - 60);
        gCurrentPinballGame->hatchShardGravity[i] = (Random() % 4) + 1;
    }

    gCurrentPinballGame->hatchShardPosition[0].x = -5600;
    gCurrentPinballGame->hatchShardPosition[0].y = -6000;
    gCurrentPinballGame->hatchShardGravity[0] = 3;
    gCurrentPinballGame->hatchShardPosition[4].x = -4000;
    gCurrentPinballGame->hatchShardPosition[4].y = -4400;
    gCurrentPinballGame->hatchShardGravity[4] = 3;
    gCurrentPinballGame->hatchParticleFrame = 0;
    gMain.boardSpriteGroups[12]->available = 1;
}

void AnimateHatchTileRevealAllParticles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 index;
    struct Vector16 tempVector;
    s16 sp0[6];
    s16 scale;

    group = gMain.boardSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            index = gCurrentPinballGame->hatchParticleFrame / 5;
            sp0[i] = gUnknown_086AE234[i][index];
            if (gCurrentPinballGame->hatchParticleFrame > 4)
            {
                gCurrentPinballGame->hatchShardVelocity[i].y += gCurrentPinballGame->hatchShardGravity[i];
                if (i == 4)
                    gCurrentPinballGame->hatchShardVelocity[i].x += gCurrentPinballGame->hatchShardGravity[4] * 4;

                gCurrentPinballGame->hatchShardPosition[i].x += gCurrentPinballGame->hatchShardVelocity[i].x;
                gCurrentPinballGame->hatchShardPosition[i].y += gCurrentPinballGame->hatchShardVelocity[i].y;
            }

            tempVector.x = (gCurrentPinballGame->hatchShardPosition[i].x / 100) +  96u - gCurrentPinballGame->bgScrollXCopy;
            tempVector.y = (gCurrentPinballGame->hatchShardPosition[i].y / 100) + 304u - gCurrentPinballGame->bgScrollYWithOffset;
            if (tempVector.y >= 160)
                tempVector.y = 160;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4E3E[sp0[i]][0];
            *dst++ = gUnknown_086B4E3E[sp0[i]][1];
            *dst++ = gUnknown_086B4E3E[sp0[i]][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
            gOamBuffer[oamSimple->oamId].affineMode = gUnknown_086AE30C[i];
            gOamBuffer[oamSimple->oamId].matrixNum = gUnknown_086AE318[i];
        }
    }

    scale = ((gCurrentPinballGame->hatchParticleFrame * gCurrentPinballGame->hatchParticleFrame * 0xD0) / 0x510) + 0x80;
    if (sp0[0] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 2);

    scale = 0x80;
    if (sp0[1] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 3);

    scale = ((gCurrentPinballGame->hatchParticleFrame * gCurrentPinballGame->hatchParticleFrame * 0x100) / 0x510) + 0x80;
    if (sp0[3] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 4);

    scale = ((gCurrentPinballGame->hatchParticleFrame * gCurrentPinballGame->hatchParticleFrame * 0x1C0) / 0x510) + 0x40;
    if (sp0[4]== 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 5);

    if (gCurrentPinballGame->hatchParticleFrame < 47)
    {
        gCurrentPinballGame->hatchParticleFrame++;
    }
    else
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0x7100;
        gMain.boardSpriteGroups[12]->available = 0;
    }
}

void InitSlotReelDisplay(void)
{
    s16 i;

    gMain.boardSpriteGroups[23]->available = 1;
    gMain.boardSpriteGroups[20]->available = 1;
    gMain.boardSpriteGroups[21]->available = 1;
    gMain.blendControl = 0x1C10;
    gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
    gCurrentPinballGame->slotReelHalted = 0;
    gCurrentPinballGame->slotReelFramesPerCycle = 8;
    gCurrentPinballGame->slotReelDecelerationTimer = 0;
    gCurrentPinballGame->slotReelVisualFrame = 0;
    if (gCurrentPinballGame->slotReelRound == 25)
        gCurrentPinballGame->slotReelRound = 10;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->slotReelEntries[i] = gUnknown_086AD180[gCurrentPinballGame->slotReelRound][i];
        if (gCurrentPinballGame->slotReelEntries[i] == 41)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->slotReelEntries[i] = 42;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->slotReelEntries[i] = 44;
                    break;
                case 4:
                    gCurrentPinballGame->slotReelEntries[i] = 45;
                    break;
                }
            }
            else
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->slotReelEntries[i] = 41;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->slotReelEntries[i] = 43;
                    break;
                case 4:
                    gCurrentPinballGame->slotReelEntries[i] = 45;
                    break;
                }
            }
        }
        else if (gCurrentPinballGame->slotReelEntries[i] == 10)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->slotReelEntries[i] = gCurrentPinballGame->ballUpgradeType + 10;
            else
                gCurrentPinballGame->slotReelEntries[i] = 12;
        }
        else if (gCurrentPinballGame->slotReelEntries[i] == 3)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
            {
                if (gMain.systemFrameCount & 1)
                {
                    if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                        gCurrentPinballGame->slotReelEntries[i] = gCurrentPinballGame->ballUpgradeType + 10;
                    else
                        gCurrentPinballGame->slotReelEntries[i] = 12;
                }
                else
                {
                    gCurrentPinballGame->slotReelEntries[i] = 1;
                }
            }
        }
        else if (gCurrentPinballGame->slotReelEntries[i] == 9)
        {
            if (gCurrentPinballGame->evolvablePartySize <= 0)
                gCurrentPinballGame->slotReelEntries[i] = 8;
        }
    }

    gCurrentPinballGame->slotReelStartPosition = 21;
    if (gCurrentPinballGame->slotReelRound < 25)
        gCurrentPinballGame->slotReelRound++;

    gCurrentPinballGame->slotReelEntryPoolSize = 5;
    if ((gCurrentPinballGame->hatchModeFlags & 0xF0) == 0 && gCurrentPinballGame->area > AREA_WILDERNESS)
        gCurrentPinballGame->slotReelEntryPoolSize++;

    gCurrentPinballGame->slotReelCurrentEntryIndex = 1;
    gCurrentPinballGame->slotReelResultPair[0] = gCurrentPinballGame->slotReelEntries[0];
    gCurrentPinballGame->slotReelResultPair[1] = gCurrentPinballGame->slotReelEntries[1];
    SetBoardPortraitGraphics(2, 0);
    SetBoardPortraitGraphics(2, 1);
}

void UpdateSlotReelSpin(void)
{
    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        if (gCurrentPinballGame->slotReelHalted == 0)
        {
            if ((gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON)) && gCurrentPinballGame->zigzagoonKickReady)
            {
                gCurrentPinballGame->zigzagoonKickState = 2;
                if (gCurrentPinballGame->slotReelVisualFrame < 17)
                    gCurrentPinballGame->slotReelResultPair[1] = gCurrentPinballGame->slotReelResultPair[0];

                gCurrentPinballGame->slotReelHalted = 1;
                gCurrentPinballGame->slotReelFramesPerCycle = 40;
                gCurrentPinballGame->slotReelSpinPosition = 39;
            }
        }
    }

    if (gCurrentPinballGame->slotReelHalted == 0)
    {
        gCurrentPinballGame->hatchRevealState = 1;
        gCurrentPinballGame->slotReelSpinPosition++;
        if (gCurrentPinballGame->slotReelDecelerationTimer)
        {
            gCurrentPinballGame->slotReelDecelerationTimer--;
            if (gCurrentPinballGame->slotReelDecelerationTimer == 0)
            {
                gCurrentPinballGame->slotReelHalted = 1;
            }
            else
            {
                if (gCurrentPinballGame->slotReelSpinPosition == gCurrentPinballGame->slotReelFramesPerCycle)
                {
                    gCurrentPinballGame->slotReelFramesPerCycle = 40 - (gCurrentPinballGame->slotReelDecelerationTimer * 34) / gCurrentPinballGame->slotReelDecelerationTotal;
                    gCurrentPinballGame->slotReelSpinPosition = 0;
                }
            }
        }
        else if (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON))
        {
            gCurrentPinballGame->slotReelDecelerationTimer = (Random() % 200) + 100;
            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                if (gCurrentPinballGame->zigzagoonKickState == 1)
                {
                    gCurrentPinballGame->slotReelDecelerationTimer = 320;
                    gCurrentPinballGame->zigzagoonKickReady = 1;
                }
            }

            gCurrentPinballGame->slotReelDecelerationTotal = gCurrentPinballGame->slotReelDecelerationTimer;
        }

        gCurrentPinballGame->slotReelSpinPosition %= gCurrentPinballGame->slotReelFramesPerCycle;
        gCurrentPinballGame->slotReelVisualFrame = (gCurrentPinballGame->slotReelSpinPosition * 32) / gCurrentPinballGame->slotReelFramesPerCycle;
    }
    else
    {
        gCurrentPinballGame->slotReelSpinPosition++;
        gCurrentPinballGame->slotReelSpinPosition %= gCurrentPinballGame->slotReelFramesPerCycle;
        gCurrentPinballGame->slotReelVisualFrame = (gCurrentPinballGame->slotReelSpinPosition * 32) / gCurrentPinballGame->slotReelFramesPerCycle;
        if (gCurrentPinballGame->slotReelSpinPosition == 0)
        {
            gCurrentPinballGame->sequenceTimer = 140;
            gMain.boardSpriteGroups[23]->available = 0;
            gMain.boardSpriteGroups[20]->available = 0;
            gMain.boardSpriteGroups[21]->available = 0;
            gCurrentPinballGame->slotReelVisualFrame = 0;
            gCurrentPinballGame->hatchRevealState = 0;
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->slotReelConfirmed = 1;
            gCurrentPinballGame->plungerAnimFrame = 0;
        }
    }

    if (gCurrentPinballGame->slotReelSpinPosition == 0)
    {
        gCurrentPinballGame->slotReelResultPair[0] = gCurrentPinballGame->slotReelResultPair[1];
        SetBoardPortraitGraphics(2, 0);
        gCurrentPinballGame->slotReelResult = gCurrentPinballGame->slotReelResultPair[0];
    }

    if (gCurrentPinballGame->slotReelSpinPosition == 1)
    {
        if (gCurrentPinballGame->slotReelCurrentEntryIndex < gCurrentPinballGame->slotReelEntryPoolSize)
            gCurrentPinballGame->slotReelCurrentEntryIndex++;
        else
            gCurrentPinballGame->slotReelCurrentEntryIndex = 0;

        gCurrentPinballGame->slotReelResultPair[1] = gCurrentPinballGame->slotReelEntries[gCurrentPinballGame->slotReelCurrentEntryIndex];
        SetBoardPortraitGraphics(2, 1);
        MPlayStart(&gMPlayInfo_SE1, &se_unk_81);
    }
}

void ProcessSlotReelPrize(void)
{
    if (gCurrentPinballGame->plungerAnimFrame < 180)
    {
        if (gCurrentPinballGame->plungerAnimFrame == 4)
            m4aSongNumStart(MUS_UNKNOWN_0x14);

        if (gCurrentPinballGame->slotReelResult == 3)
        {
            if (gCurrentPinballGame->plungerAnimFrame == 120)
                m4aSongNumStart(SE_UNKNOWN_0xB2);
        }

        gCurrentPinballGame->plungerAnimFrame++;
        if (gCurrentPinballGame->plungerAnimFrame < 80)
            SetBoardPortraitGraphics(8, 0);
    }

    switch (gCurrentPinballGame->slotReelResult)
    {
    case 0:
    case 1:
    case 2:
        gCurrentPinballGame->modeTimerFrames = (gCurrentPinballGame->slotReelResult + 1) * 1800;
        break;
    case 3:
        if (gCurrentPinballGame->boardEntryMode == 3)
        {
            if (gCurrentPinballGame->plungerAnimFrame > 124)
            {
                if (gCurrentPinballGame->plungerLoopCount < 100)
                {
                    gCurrentPinballGame->plungerLoopCount++;
                    gCurrentPinballGame->plungerAnimFrame = 124;
                }
            }

            if (gCurrentPinballGame->plungerAnimFrame == 4)
            {
                gCurrentPinballGame->pikaChargeTarget = 168;
                gCurrentPinballGame->pikaChargeDisplay = 168;
                gCurrentPinballGame->pikaChargeSegmentPrev = 13;
                gCurrentPinballGame->pikaChargeSegment = 13;
                gCurrentPinballGame->pikaChargeAnimDuration = 0;
                gCurrentPinballGame->pikaChargeSpriteY = 120;
                gCurrentPinballGame->pikaChargeFullFlashTimer = 60;
                DmaCopy16(3, gUnknown_084C156C, (void *)0x06010600, 0x180);
                gCurrentPinballGame->outLanePikaPosition = 2;
                gMain.boardSpriteGroups[41]->available = 0;
                gCurrentPinballGame->pikaSaverAnimTimer = 1;
            }
        }
        else
        {
            if (gCurrentPinballGame->plungerAnimFrame == 120)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->scrollDelayFrames = 0;
                gCurrentPinballGame->scrollHoldFrames = 250;
                gCurrentPinballGame->scrollTargetBottomY = 272;
                gCurrentPinballGame->fieldScrollOffsetY = 0;
                gCurrentPinballGame->fieldScrollSpeed = 2;
                gCurrentPinballGame->bannerGfxVariant = 0;
                gCurrentPinballGame->scrollOverrideActive = 1;
                gCurrentPinballGame->scrollFromBottom = 0;
                gCurrentPinballGame->pikaSaverLossType = 1;
                gCurrentPinballGame->pikaSaverAnimTimer = 800;
                gCurrentPinballGame->outLanePikaPosition = 0;
                gCurrentPinballGame->pikaChargeTarget = 168;
                gCurrentPinballGame->pikaChargeDisplay = 168;
                gCurrentPinballGame->pikaChargeSegmentPrev = 13;
                gCurrentPinballGame->pikaChargeSegment = 13;
                gCurrentPinballGame->pikaChargeAnimDuration = 0;
                gCurrentPinballGame->pikaChargeSpriteY = 120;
                gCurrentPinballGame->pikaChargeFullFlashTimer = 60;
            }

            if (gCurrentPinballGame->pikaSaverAnimTimer)
            {
                if (gCurrentPinballGame->plungerAnimFrame >= 176)
                    gCurrentPinballGame->plungerAnimFrame = 176;
            }
        }
        break;
    case 4:
        if (gCurrentPinballGame->plungerAnimFrame == 130)
            gCurrentPinballGame->extraLifeAnimTimer = 90;
        break;
    case 5:
        if (gCurrentPinballGame->plungerAnimFrame == 95)
        {
            gCurrentPinballGame->plungerAnimFrame = 12;
            gCurrentPinballGame->slotReelResult = (gMain.systemFrameCount % 3) + 33;
        }
        break;
    case 6:
        if (gCurrentPinballGame->plungerAnimFrame == 95)
        {
            gCurrentPinballGame->plungerAnimFrame = 12;
            if (gCurrentPinballGame->slotReelRound < 6)
                gCurrentPinballGame->slotReelResult = (gMain.systemFrameCount % 3) + 24;
            else if ((s32) gCurrentPinballGame->slotReelRound <= 0xA)
                gCurrentPinballGame->slotReelResult = (gMain.systemFrameCount % 5) + 24;
            else if (gCurrentPinballGame->slotReelRound % 5 == 0)
                gCurrentPinballGame->slotReelResult = (gMain.systemFrameCount % 5) + 28;
            else
                gCurrentPinballGame->slotReelResult = (gMain.systemFrameCount % 7) + 24;
        }
        break;
    case 7:
        if (gCurrentPinballGame->plungerAnimFrame == 95)
        {
            gCurrentPinballGame->plungerAnimFrame = 12;
            if (gCurrentPinballGame->slotReelRound < 10)
                gCurrentPinballGame->slotReelResult = (gMain.systemFrameCount % 3) + 36;
            else
                gCurrentPinballGame->slotReelResult = (gMain.systemFrameCount % 5) + 36;
        }
        break;
    case 8:
        if (gCurrentPinballGame->plungerAnimFrame == 150)
        {
            RequestBoardTransition(4);
            gCurrentPinballGame->sequenceTimer = 100;
        }
        break;
    case 9:
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->plungerAnimFrame == 149)
            {
                gCurrentPinballGame->entrySequenceTimer = 180;
                gCurrentPinballGame->hatchRevealState = 3;
            }

            if (gCurrentPinballGame->plungerAnimFrame == 150)
            {
                gCurrentPinballGame->plungerAnimFrame = 149;
                gCurrentPinballGame->trapDisplayState = 1;
                UpdateMartEvoSelectionUI(1);
                gCurrentPinballGame->targetAnimPhase[0] = 3;
                gCurrentPinballGame->targetAnimPhase[1] = 3;
            }

            if (gCurrentPinballGame->plungerAnimFrame == 170)
            {
                gCurrentPinballGame->shopDoorTargetFrame = 0;
                gCurrentPinballGame->trapDisplayState = 0;
                RequestBoardTransition(6);
            }
        }
        break;
    case 10:
    case 11:
    case 12:
        if (gCurrentPinballGame->plungerAnimFrame == 130)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_87);
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 13:
        if (gCurrentPinballGame->plungerAnimFrame == 130)
        {
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_87);
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 17:
    case 18:
    case 19:
        if (gCurrentPinballGame->plungerAnimFrame == 130)
        {
            gCurrentPinballGame->scoreMultiplierLevel = 1;
            gCurrentPinballGame->coinsTotalToCollect = (gCurrentPinballGame->slotReelResult - 17) * 20 + 10;
            gCurrentPinballGame->coinAnimFrameCounter = 0;
        }

        if (gCurrentPinballGame->plungerAnimFrame == 140)
            gCurrentPinballGame->plungerAnimFrame = 139;
        break;
    case 20:
        if (gCurrentPinballGame->plungerAnimFrame == 130)
            gCurrentPinballGame->timerBonus = 1800;
        break;
    case 21:
        if (gCurrentPinballGame->plungerAnimFrame == 150)
        {
            gCurrentPinballGame->sequenceTimer = 100;
            gCurrentPinballGame->hatchModeFlags = 15;
            RequestBoardTransition(8);
        }
        break;
    case 22:
        if (gCurrentPinballGame->plungerAnimFrame == 150 && gCurrentPinballGame->shouldProcessWhiscash == 0)
        {
            gCurrentPinballGame->rubyPondChangeTimer = 0;
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            gCurrentPinballGame->forcePondToWhiscash = TRUE;
        }
        break;
    case 23:
        if (gCurrentPinballGame->plungerAnimFrame == 150)
        {
            gCurrentPinballGame->bumperHitsSinceReset = 100;
            gCurrentPinballGame->entityMovementTimer = 1800;
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
            gCurrentPinballGame->plungerAnimFrame = 81;

        if (gCurrentPinballGame->plungerAnimFrame == 70)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->slotReelResult - 23) * 1000000;
        }
        break;
    case 33:
        if (gCurrentPinballGame->plungerAnimFrame == 70)
        {
            m4aSongNumStart(SE_UNKNOWN_0x91);
            gCurrentPinballGame->scoreAddedInFrame = 100;
        }
        break;
    case 34:
        if (gCurrentPinballGame->plungerAnimFrame == 70) {
            m4aSongNumStart(SE_UNKNOWN_0x91);
            gCurrentPinballGame->scoreAddedInFrame = 500;
        }
        break;
    case 35:
        if (gCurrentPinballGame->plungerAnimFrame == 70) {
            m4aSongNumStart(SE_UNKNOWN_0x91);
            gCurrentPinballGame->scoreAddedInFrame = 900;
        }
        break;
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
        if (gCurrentPinballGame->plungerAnimFrame == 70)
        {
            gCurrentPinballGame->bonusMultiplier += gCurrentPinballGame->slotReelResult + 221;
            if (gCurrentPinballGame->bonusMultiplier > 99)
                gCurrentPinballGame->bonusMultiplier = 99;
        }
        break;
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
        if (gCurrentPinballGame->plungerAnimFrame == 150)
            RequestBoardTransition(3);
        break;
    }
}

void RunPokemonCaptureAnimation(void)
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

    if (gCurrentPinballGame->currentProcessPass != 0)
        return;

    // Handle counter increment logic
    if (gCurrentPinballGame->entityCaptureTimer < gUnknown_086ACF38[gCurrentPinballGame->captureSequencePhase])
    {
        gCurrentPinballGame->entityCaptureTimer++;

        if (gCurrentPinballGame->entityCaptureTimer >= gUnknown_086ACF38[gCurrentPinballGame->captureSequencePhase])
        {
            gCurrentPinballGame->entityCaptureTimer = 0;

            if (gCurrentPinballGame->captureSequencePhase <= 34)
                gCurrentPinballGame->captureSequencePhase++;
        }
    }

    switch (gCurrentPinballGame->captureSequencePhase)
    {
    case 0:
        gMain.blendControl = 0xCE;

        if (gMain.selectedField < MAIN_FIELD_COUNT && (gCurrentPinballGame->boardState == 4 || gCurrentPinballGame->boardState == 8))
            gCurrentPinballGame->entityActivePhase = 1;

        gCurrentPinballGame->ballLockState = 1;

        gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
        gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        gCurrentPinballGame->bannerType = 9;
        DmaCopy16(3, gUnknown_081428D4, 0x06015800, 0x1C00);
        DmaCopy16(3, &gUnknown_08138014[gCurrentPinballGame->ballUpgradeType << 9], 0x060164C0, 0x80);
        DmaCopy16(3, &gUnknown_08138014[((gCurrentPinballGame->ballUpgradeType * 8 + 4) << 6)], 0x06016760, 0x80);

        gCurrentPinballGame->ballLocked = 1;

        if (gCurrentPinballGame->entityCaptureTimer == 1)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->ballTrailRenderFlag = 1;
        }

        break;

    case 1:
        if (gCurrentPinballGame->boardState == 4)
        {
            gCurrentPinballGame->bumperFlashAnimTimer = 0;
            gCurrentPinballGame->bumperHitTimers[0] = 2;
            gCurrentPinballGame->bumperHitTimers[1] = 2;
            gCurrentPinballGame->bumperHitTimers[2] = 2;
        }

        gCurrentPinballGame->ball->oamPriority = 0;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        if (gCurrentPinballGame->entityCaptureTimer == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_9a);

        break;

    case 2:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gUnknown_08137E14[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gMain.blendBrightness = 4;

        if (gCurrentPinballGame->entityCaptureTimer > 1)
        {
            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->paletteCycleIndex = 1;
            gCurrentPinballGame->fieldScrollState = 1;
        }
        break;

    case 3:
        gMain.blendBrightness = 7;

        if (gCurrentPinballGame->entityCaptureTimer > 1)
        {
            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->paletteCycleIndex = 2;
            gCurrentPinballGame->fieldScrollState = 1;
        }

        DmaCopy16(3, &gUnknown_08137F14, 0x05000220, 0x20);
        break;

    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        temp_r3 = gCurrentPinballGame->captureSequencePhase - 4;

        if (temp_r3 == 0 || temp_r3 == 6)
        {
            if (gMain.selectedField <= 3 &&
                (
                    (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3)
                ))
            {
                DmaCopy16(3, &gUnknown_02030710, 0x050003A0, 0x20);
            }

            DmaCopy16(3, &gUnknown_08137F14, 0x05000220, 0x20);
            gMain.blendBrightness = 6;
        }
        else
        {
            //TODO: fakematch; unused i. Here for the +4 to parse correctly;
            DmaCopy16(3, gUnknown_08137E14[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
            gMain.blendBrightness = 7;
        }

        spriteGroup = gMain.boardSpriteGroups[3];

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
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

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
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        gMain.boardSpriteGroups[3]->available = 1;

        if (gCurrentPinballGame->captureSequencePhase == 10 && gCurrentPinballGame->entityCaptureTimer == 3)
            gMain.boardSpriteGroups[3]->available = 0;
        break;
    case 11:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gUnknown_08137E14[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);

        tempVector.x = (gCurrentPinballGame->entityCenterX << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->entityCenterY << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->captureArcRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);

        gCurrentPinballGame->captureArcRadius = Sqrt(gCurrentPinballGame->captureArcRadius * 4) / 2;
        gCurrentPinballGame->captureArcAngle = ArcTan2(-tempVector.x, tempVector.y);

        if (gMain.selectedField > 3)
        {
            gCurrentPinballGame->bossHitPaletteState = 0;
        }
        else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                 (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
        {
            DmaCopy16(3, &gUnknown_020306D0, 0x050003A0, 0x20);
        }

        for (i = 0; i < 4; i++)
        {
            gCurrentPinballGame->ball->prevPositionsQ0[i].x = gCurrentPinballGame->ball->positionQ0.x;
            gCurrentPinballGame->ball->prevPositionsQ0[i].y = gCurrentPinballGame->ball->positionQ0.y;
        }
        break;
    case 12:
        temp_r0 = 99 - gCurrentPinballGame->entityCaptureTimer;
        gCurrentPinballGame->captureArcAngle -= (temp_r0 * 0x2000) / 100 - 0x2000;
        gCurrentPinballGame->ball->rotation -= 0x2000;

        temp_r0 -= 20;

        if (temp_r0 < 0)
        {
            temp_r0 = 0;
            gCurrentPinballGame->ball->isGrabbed = 0;
        }

        {
            s32 var_3 = (gCurrentPinballGame->captureArcRadius * temp_r0) / 80;

            gCurrentPinballGame->ball->positionQ8.x =
                (gCurrentPinballGame->entityCenterX << 8) + Cos(gCurrentPinballGame->captureArcAngle) * var_3 / 20000;
            gCurrentPinballGame->ball->positionQ8.y =
                (gCurrentPinballGame->entityCenterY << 8) - Sin(gCurrentPinballGame->captureArcAngle) * var_3 / 20000;
        }
        break;

    case 13:
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ballTrailRenderFlag = 0;
        gCurrentPinballGame->ball->rotation -= 0x2000;
        break;

    case 14:
        DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->rotation -= 0x2000;
        break;

    case 15:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gUnknown_08137E14[i= gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gCurrentPinballGame->ball->rotation -= 0x2000;
        break;

    case 16:
        if (gCurrentPinballGame->entityCaptureTimer == 0)
            m4aSongNumStart(0x9B);

        DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->rotation = 0x7000;
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
        spriteGroup = gMain.boardSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            gCurrentPinballGame->ball->isGrabbed = 1;
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;
            temp_r3 = gUnknown_086ACFF4[gCurrentPinballGame->captureSequencePhase - 17] + 7;

            if (gCurrentPinballGame->boardState == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

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
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }
        gMain.boardSpriteGroups[3]->available = 1;

        if (gCurrentPinballGame->captureSequencePhase == 18 || gCurrentPinballGame->captureSequencePhase == 20 || gCurrentPinballGame->captureSequencePhase == 21)
        {
            gCurrentPinballGame->catchHitReactionTimer = 200;

            if (gMain.selectedField > 3)
                gCurrentPinballGame->bossHitPaletteState = 1;
            else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
                DmaCopy16(3, &gUnknown_020306F0, 0x050003A0, 0x20);
        }
        else if (gCurrentPinballGame->captureSequencePhase == 19 || gCurrentPinballGame->captureSequencePhase == 22)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->bossHitPaletteState = 3;
            else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
                DmaCopy16(3, &gUnknown_02030730, 0x050003A0, 0x20);
        }

        if (gCurrentPinballGame->captureSequencePhase == 23)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->bossHitPaletteState = 10;
            else
            {
                if (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9)
                {
                    HideCatchModePokemonSprite();
                    gCurrentPinballGame->catchCollisionActive = 0;
                    m4aMPlayAllStop();
                }

                if (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3)
                {
                    HideJirachiModeSprites();
                    gCurrentPinballGame->catchCollisionActive = 0;
                    m4aMPlayAllStop();
                }
            }
        }

        if (gCurrentPinballGame->captureSequencePhase == 28)
        {
            if (gCurrentPinballGame->entityCaptureTimer == 0)
            {
                m4aMPlayAllStop();
                PlayRumble(8);
            }

            if (gCurrentPinballGame->entityCaptureTimer == 2)
                m4aSongNumStart(0x9C);
        }
        break;

    case 26:
        spriteGroup = gMain.boardSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            temp_r3 = gUnknown_086ACFF4[gCurrentPinballGame->captureSequencePhase - 17] + 7;

            if (gCurrentPinballGame->boardState == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

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
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        break;

    case 29:
        gMain.blendBrightness = 4;
        DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);

        spriteGroup = gMain.boardSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            for (i = 0; i <= 21; i++)
            {
                oamSimple = &spriteGroup->oam[i];
                gOamBuffer[oamSimple->oamId].y = 190;
            }
        }

        gMain.boardSpriteGroups[3]->available = 0;
        gCurrentPinballGame->ball->isGrabbed = 0;
        gCurrentPinballGame->ball->velocity.y = -256;
        gCurrentPinballGame->ball->velocity.x = 40;
        gCurrentPinballGame->ball->spin = 256;

        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->bannerType = 0;

        break;

    case 30:
        if (gCurrentPinballGame->entityCaptureTimer <= 7)
        {
            if (gCurrentPinballGame->entityCaptureTimer <= 3)
            {
                if (gCurrentPinballGame->entityCaptureTimer == 0)
                {
                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x140, 0x05000340, 0x60);
                    gCurrentPinballGame->paletteCycleIndex = 1;
                    gCurrentPinballGame->fieldScrollState = 1;
                }
            }
            else
            {
                gMain.blendBrightness = 0;

                if (gCurrentPinballGame->entityCaptureTimer > 4)
                {
                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x140, 0x05000340, 0x60);

                    gCurrentPinballGame->paletteCycleIndex = 0;
                    gCurrentPinballGame->fieldScrollState = 1;
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
                gCurrentPinballGame->ball->spin = (gCurrentPinballGame->ball->spin * 7) / 10;

                if (gCurrentPinballGame->ball->spin > 0)
                    gCurrentPinballGame->ball->spin = -gCurrentPinballGame->ball->spin;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }

            {
                s16 var_4 = gCurrentPinballGame->ball->velocity.y;

                if (var_4 < 0)
                    var_4 = -var_4;

                if (var_4 > 256)
                    gCurrentPinballGame->entityCaptureTimer--;
            }
        }
        else
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;

            if (gCurrentPinballGame->ball->positionQ8.y >= (gCurrentPinballGame->entityCenterY + 50) << 8)
            {
                m4aSongNumStart(0x9D);
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->entityCenterY + 50) << 8;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * -45) / 100;
                gCurrentPinballGame->ball->spin = (gCurrentPinballGame->ball->spin * 7) / 10;

                if (gCurrentPinballGame->ball->spin > 0)
                    gCurrentPinballGame->ball->spin = -gCurrentPinballGame->ball->spin;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }
        }

        gCurrentPinballGame->captureArcAngle = 0;
        break;

    case 31:
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spin = 0;
        break;

    case 32:
        temp_r0 = 237 - gCurrentPinballGame->entityCaptureTimer;

        if (temp_r0 <= 191)
        {
            if (temp_r0 > 183)
            {
                if (temp_r0 == 185)
                    PlayRumble(6);

                if (temp_r0 == 184)
                    m4aSongNumStart(158);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->rotation -= 0x400;
            }
            else if (temp_r0 > 175)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->rotation += 0x400;
            }
            else if (temp_r0 > 167)
            {
                if (temp_r0 == 169)
                    PlayRumble(6);

                if (temp_r0 == 168)
                    m4aSongNumStart(0x9E);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->rotation -= 0x400;
            }
            else if (temp_r0 > 159)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->rotation += 0x400;
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
                    gCurrentPinballGame->ball->rotation -= 0x400;
                }
                else if (temp_r0 > 107)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->rotation += 0x400;
                }
                else if (temp_r0 > 99)
                {
                    if (temp_r0 == 101)
                        PlayRumble(6);

                    if (temp_r0 == 100)
                        m4aSongNumStart(0x9E);

                    gCurrentPinballGame->ball->positionQ8.x -= 96;
                    gCurrentPinballGame->ball->rotation -= 0x400;
                }
                else if (temp_r0 > 91)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->rotation += 0x400;
                }
            }
        }

        if (temp_r0 == 0)
        {
            m4aSongNumStart(0x11);
            InitEvolutionNameRevealBanner();
        }

        break;

    case 33:
        gCurrentPinballGame->ball->oamPriority = 3;
        UpdateEvolutionNameRevealBanner();

        if (gCurrentPinballGame->entityCaptureTimer <= 229 && gCurrentPinballGame->nameRevealScrollProgress == 150)
            gCurrentPinballGame->nameRevealScrollProgress--;

        if (gCurrentPinballGame->entityCaptureTimer == 270 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            SetBoardPortraitGraphics(0, 0);
            gCurrentPinballGame->hatchRevealState = 0;
        }

        if (gCurrentPinballGame->entityCaptureTimer <= 29)
        {
            gMain.blendScanlineEnabled = 1;
            temp_r0 = gCurrentPinballGame->entityCaptureTimer;
            gCurrentPinballGame->blendScanlineWidth = temp_r0;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gBgScreenBuffer[(i + 15) * 32 + j] = 0xC100;
                }
            }

            DmaCopy16(3, &gBgScreenBuffer, 0x06002000, 0x800);
        }

        if (gCurrentPinballGame->entityCaptureTimer >= 240 && gCurrentPinballGame->entityCaptureTimer <= 269)
        {
            temp_r0 = gCurrentPinballGame->entityCaptureTimer - 240;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gBgScreenBuffer[(i + 15) * 32 + j] = 511;
                }
            }

            DmaCopy16(3, &gBgScreenBuffer, 0x06002000, 0x800);

            if (gCurrentPinballGame->entityCaptureTimer == 269)
            {
                gMain.blendScanlineEnabled = 0;

                if (gMain.selectedField < MAIN_FIELD_COUNT)
                {
                    gMain.blendControl = 0;
                    gMain.blendBrightness = 0;
                    gMain.blendAlpha = 0;
                }
            }
        }
        
        if (gCurrentPinballGame->scoreCounterAnimationEnabled) 
            gCurrentPinballGame->entityCaptureTimer = 181;

        if (gCurrentPinballGame->entityCaptureTimer == 180)
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
        gCurrentPinballGame->ballLocked = 0;
        gCurrentPinballGame->ball->oamPriority = 3;
        gCurrentPinballGame->catchModeHitPhase = 0;
        gCurrentPinballGame->entityCaptureTimer = 0;
        gCurrentPinballGame->captureSequencePhase = 0;

        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->ballLockState = 0;
            gCurrentPinballGame->ball->velocity.y = -10;
            gCurrentPinballGame->ball->velocity.x = 20;

            for (i = 0; i <= 2; i++)
            {
                if (i < gCurrentPinballGame->activatedBumperCount)
                    gCurrentPinballGame->bumperHitTimers[i] = 1;
                else
                    gCurrentPinballGame->bumperHitTimers[i] = 0;
            }

            if (gCurrentPinballGame->activatedBumperCount <= 2)
            {
                gCurrentPinballGame->bumperFlashTargetA = gCurrentPinballGame->activatedBumperCount;
                gCurrentPinballGame->bumperFlashTargetB = gCurrentPinballGame->activatedBumperCount;
                gCurrentPinballGame->bumperHitTimers[gCurrentPinballGame->bumperFlashTargetA] = 1;
                gCurrentPinballGame->bumperFlashAnimTimer = 120;
                gCurrentPinballGame->activatedBumperCount++;
            }

            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->extraLifeAnimTimer = 90;

            if (gCurrentPinballGame->hatchCompletionCount <= 98)
                gCurrentPinballGame->hatchCompletionCount++;

            if (gCurrentPinballGame->boardState == 4)
                gCurrentPinballGame->boardSubState = 10;

            if (gCurrentPinballGame->boardState == 8)
                gCurrentPinballGame->boardSubState = 5;

            if (gCurrentPinballGame->boardState == 5)
                gCurrentPinballGame->boardSubState = 6;

        }
        else
        {
            gCurrentPinballGame->ballLockState = 1;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->hatchRevealState = 3;
            gCurrentPinballGame->boardState = 4;
            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->extraLifeAnimTimer = 91;
        }
        RegisterCapturedOrEvolvedPokemon(0);
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
