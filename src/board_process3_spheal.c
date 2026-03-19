#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

struct SphealFlightPath
{
    struct Vector16 *pathWaypoints;
    s16 pathLength;
};
extern const struct SphealFlightPath gSphealFlightPathData[];

extern const s16 gSphealWhiscashAnimFrameset[][4];
extern struct SongHeader se_unk_137;
extern struct SongHeader se_unk_138;
extern struct SongHeader se_unk_139;
extern struct SongHeader se_unk_13b;
extern struct SongHeader se_unk_13c;
extern struct SongHeader se_unk_13d;

extern const s8 gSphealScoreDigitSpriteIndices[];
extern const u16 gSphealWaterBackgroundTilemap[];
extern const u8 gSphealScoreCounterDigitSprites[][0x200];
extern const u8 gSphealExtendedScoreSprites[][0x180];
extern const u8 gSphealFlyingEnemyVariantSprites[][0x120];
extern const u8 gSphealMinionBodySprites[][0x800];
extern const u8 gSphealResultsScreenGfx[];
extern const u8 gWhiscash_Gfx[][0x480];
extern const u8 gPelipper_Gfx[][0x480];
extern const s16 gWaterTilePaletteCycle[];
extern const u16 gSphealFramesetToSpriteMap[][2];
extern const u16 gSphealAnimTimingTable[][2];
extern const u16 gSphealFlyingEnemyFramesetTable[][3];
extern const u16 gSphealFlyingEnemyOamData[126][4][3];


void SphealBoardProcess_3A_42E48(void)
{
    s16 i;
    s16 frame;

    frame = gMain.systemFrameCount % 16;
    for (i = 0; i < frame; i++)
        Random();

    gMain.rngValue = gMain.systemFrameCount;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->boardState = 0;
    gCurrentPinballGame->boardModeType = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 7200;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ballGrabbed = 0;
    gCurrentPinballGame->ballRespawnState = 0;
    gCurrentPinballGame->ball->ballHidden = 1;
    gCurrentPinballGame->ballFrozenState = 1;
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->spinSpeed = 0;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->resultsAnimTimer = 0;
    gCurrentPinballGame->scoreCountdownTimer = 0;
    gCurrentPinballGame->totalBonusScore = 0;
    gCurrentPinballGame->unk54A = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->unk590 = 0;
    gCurrentPinballGame->deliveryAnimFrameIndex = 0;
    gCurrentPinballGame->deliveryAnimTimer = 0;
    gCurrentPinballGame->unk594 = 0;
    gCurrentPinballGame->unk596 = 0;
    gCurrentPinballGame->ballDeliveryActive = 1;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->minionState[i] = 0;
        gCurrentPinballGame->minionFramesetIx[i] = 0;
        gCurrentPinballGame->minionStateTimer[i] = 0;
    }

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->knockdownTargetIndex[i] = 0;
        gCurrentPinballGame->knockdownBounceCount[i] = 0;
        gCurrentPinballGame->knockdownPhase[i] = 0;
        gCurrentPinballGame->knockdownStunTimer[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->sphealKnockdownCount[i] = 0;
        gCurrentPinballGame->sphealKnockdownDisplayCount[i] = 0;
        gCurrentPinballGame->minionHitFlashTimer[i] = 0;
        gCurrentPinballGame->flyingEnemySinkSpeed[i] = 0;
        gCurrentPinballGame->flyingEnemyHitCooldown[i] = 0;
        gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
        gCurrentPinballGame->flyingEnemyDirection[i] = 0;
        gCurrentPinballGame->flyingEnemyState[i] = 0;
        gCurrentPinballGame->flyingEnemyPrevSpriteIndex[i] = 0;
        gCurrentPinballGame->flyingEnemySpawnVariant[i] = 0;
        gCurrentPinballGame->flyingEnemyPathIndex[i] = 0;
        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 0;
        gCurrentPinballGame->flyingEnemyOamXOffset[i] = 0;
        gCurrentPinballGame->flyingEnemyOamYOffset[i] = 0;
        gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
        gCurrentPinballGame->flyingEnemyScreenY[i] = 0;
        gCurrentPinballGame->flyingEnemyFlyTimer[i] = 0;
        gCurrentPinballGame->flyingEnemyCollisionPos[i].x = 0;
        gCurrentPinballGame->flyingEnemyCollisionPos[i].y = 0;
        gCurrentPinballGame->flyingEnemyVelocity[i].x = 0;
        gCurrentPinballGame->flyingEnemyVelocity[i].y = 0;
        gCurrentPinballGame->flyingEnemyPositionQ8[i].x = 0;
        gCurrentPinballGame->flyingEnemyPositionQ8[i].y = 0;
    }

    gCurrentPinballGame->flippersDisabled = 0;
    UpdateSphealEntityLogic();
    UpdateSealeoEntityLogic();
    UpdateSphealScoreAndDelivery();
    AnimateSphealBackground();

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[0x400 + i] = 0x200;

    DmaCopy16(3, &gBG0TilemapBuffer[0x400], (void *)0x06001000, 0x1000);

    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        u16 var0 = i - ((i / 0x20) * 0x20) - 2;
        if (var0 < 28)
           gBG0TilemapBuffer[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gBG0TilemapBuffer[0x800], (void *)0x06001140, 0x280);
    DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
    m4aSongNumStart(MUS_BONUS_FIELD_SPHEAL);
    DmaCopy16(3, gBonusStageObjPal, (void *)0x05000320, 0x20);
}

void SphealBoardProcess_3B_43228(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case 0:
        gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
        if (gCurrentPinballGame->stageTimer < 340)
        {
            if (gCurrentPinballGame->stageTimer < 321)
                gCurrentPinballGame->cameraYAdjust = (gCurrentPinballGame->stageTimer / 5) + 0xFFC0;

            if (gCurrentPinballGame->stageTimer == 325)
                gCurrentPinballGame->boardModeType = 2;

            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->cameraYAdjust = 0;
            gCurrentPinballGame->boardState = 1;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 1:
        if (gCurrentPinballGame->eventTimer == 0)
        {
            gCurrentPinballGame->boardModeType = 3;
            if (gCurrentPinballGame->stageTimer == 0)
            {
                m4aMPlayAllStop();
                MPlayStart(&gMPlayInfo_SE1, &se_unk_13b);
                gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
                gCurrentPinballGame->ballRespawnState = 2;
                gCurrentPinballGame->ballRespawnTimer = 0;
            }

            if (gCurrentPinballGame->stageTimer < 60)
            {
                gCurrentPinballGame->stageTimer++;
            }
            else
            {
                gCurrentPinballGame->boardState = 2;
                gCurrentPinballGame->stageTimer = 0;
            }
        }
        break;
    case 2:
        if (gCurrentPinballGame->stageTimer == 0)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_SUCCESS3);
        }

        if (gCurrentPinballGame->stageTimer < 20)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->boardState = 3;
            gCurrentPinballGame->stageTimer = 0;
            gMain.spriteGroups[7].available = 1;
            gMain.spriteGroups[8].available = 1;
            gMain.spriteGroups[9].available = 1;
            gMain.spriteGroups[10].available = 1;
            DmaCopy16(3, gSphealResultsScreenGfx, (void *)0x06015800, 0x800);
            gCurrentPinballGame->bannerSlideYOffset = -126;
            gCurrentPinballGame->boardEntityActive = 1;
        }
        break;
    case 3:
        UpdateSphealResultsScreen();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180 && gCurrentPinballGame->totalBonusScore != 0)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = gCurrentPinballGame->totalBonusScore;
        }

        if (gCurrentPinballGame->stageTimer > 189 && JOY_NEW(A_BUTTON))
            gCurrentPinballGame->stageTimer = 540;

        if (gCurrentPinballGame->stageTimer < 540)
        {
            if (gCurrentPinballGame->stageTimer == 4)
                m4aSongNumStart(SE_UNKNOWN_0xA4);

            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = 4;
        }

        gCurrentPinballGame->boardEntityActive = 1;
        break;
    case 4:
        UpdateSphealResultsScreen();
        if (gCurrentPinballGame->stageTimer < 30)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer == 2)
                m4aSongNumStart(SE_UNKNOWN_0xA4);
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = 5;
        }
        break;
    case 5:
        UpdateSphealResultsScreen();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        gCurrentPinballGame->boardEntityActive = 1;
        break;
    }

    UpdateSphealEntityLogic();
    UpdateSealeoEntityLogic();
    UpdateSphealScoreAndDelivery();
    AnimateSphealBackground();
    if (gCurrentPinballGame->returnToMainBoardFlag)
    {
        gCurrentPinballGame->boardEntityActive = 1;
        FadeToMainBoard();
    }

    BonusStage_HandleModeChangeFlags();
}

void UpdateSealeoEntityLogic(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->boardState < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        UpdateSealeoKnockdownPhysics();

    if (gCurrentPinballGame->boardState < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            if (gCurrentPinballGame->minionHitFlashTimer[i] == 23)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_13c);
                gCurrentPinballGame->scoreAddedInFrame = 5000;
                PlayRumble(8);
            }

            switch (gCurrentPinballGame->minionState[i])
            {
            case 0:
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionFramesetIx[i] = 4;
                gCurrentPinballGame->minionState[i] = 1;
                break;
            case 1:
                if (gCurrentPinballGame->minionHitFlashTimer[i] > 0)
                {
                    gCurrentPinballGame->minionHitFlashTimer[i]--;
                }
                else
                {
                    if (gSphealAnimTimingTable[gCurrentPinballGame->minionFramesetIx[i]][0] > gCurrentPinballGame->minionStateTimer[i])
                    {
                        gCurrentPinballGame->minionStateTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->minionStateTimer[i] = 0;
                        gCurrentPinballGame->minionFramesetIx[i]++;
                        if (gCurrentPinballGame->minionFramesetIx[i] == 6)
                            gCurrentPinballGame->minionFramesetIx[i] = 4;
                    }
                }
                break;
            case 2:
                if (gCurrentPinballGame->minionHitFlashTimer[i] > 0)
                {
                    gCurrentPinballGame->minionHitFlashTimer[i]--;
                }
                else
                {
                    if (gCurrentPinballGame->minionStateTimer[i] != 0)
                    {
                        gCurrentPinballGame->minionStateTimer[i]--;
                        gCurrentPinballGame->minionFramesetIx[i] = 8;
                    }
                    else
                    {
                        gCurrentPinballGame->minionFramesetIx[i] = 7;
                    }
                }
                break;
            case 3:
                if (gCurrentPinballGame->minionHitFlashTimer[i] > 0)
                {
                    gCurrentPinballGame->minionHitFlashTimer[i]--;
                }
                else
                {
                    if (gSphealAnimTimingTable[gCurrentPinballGame->minionFramesetIx[i]][0] > gCurrentPinballGame->minionStateTimer[i])
                    {
                        gCurrentPinballGame->minionStateTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->minionStateTimer[i] = 0;
                        gCurrentPinballGame->minionFramesetIx[i]++;
                        if (gCurrentPinballGame->minionFramesetIx[i] > 14)
                        {
                            gCurrentPinballGame->minionFramesetIx[i] = 4;
                            gCurrentPinballGame->minionState[i] = 1;
                        }
                    }
                }
                break;
            }
        }
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        group->baseX = 100 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 94 - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->minionHitFlashTimer[0] > 0)
            var0 = 0;
        else
            var0 = gSphealFramesetToSpriteMap[gCurrentPinballGame->minionFramesetIx[0]][0];

        DmaCopy16(3, gSphealMinionBodySprites[var0], (void *)0x060114A0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[21];
    if (group->available)
    {
        group->baseX = 140 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 94 - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->minionHitFlashTimer[1] > 0)
            var0 = 0;
        else
            var0 = gSphealFramesetToSpriteMap[gCurrentPinballGame->minionFramesetIx[1]][0];

        DmaCopy16(3, gSphealMinionBodySprites[var0], (void *)0x06010CA0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateSphealEntityLogic(void)
{
    s16 i;
    s16 j;
    s16 var1;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 sp4;
    s16 var2;
    u16 *dst;
    const u16 *src;
    int var3;
    s16 var4;
    const struct SphealFlightPath *var5;

    if (gCurrentPinballGame->boardState == 1 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            switch (gCurrentPinballGame->flyingEnemyState[i])
            {
            case 0:
                gCurrentPinballGame->flyingEnemyState[i] = 1;
                gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 0;
                gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                gCurrentPinballGame->flyingEnemySpawnVariant[i] = -1;
                break;
            case 1:
                if (gCurrentPinballGame->flyingEnemyAnimTimer[i] < i * 30 + 120)
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                }
                else
                {
                    u16 var0 = gMain.systemFrameCount + Random();
                    gCurrentPinballGame->flyingEnemySpawnVariant[i] = var0 % 6;
                    if (gCurrentPinballGame->flyingEnemySpawnVariant[0] == gCurrentPinballGame->flyingEnemySpawnVariant[1])
                        gCurrentPinballGame->flyingEnemySpawnVariant[i] = (gCurrentPinballGame->flyingEnemySpawnVariant[i] + 2) % 6;

                    if (gCurrentPinballGame->flyingEnemySpawnVariant[i] < 2)
                    {
                        if (gCurrentPinballGame->flyingEnemySpawnVariant[i] == 0)
                        {
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].x = 0x4900;
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y = 0xAB00;
                            gCurrentPinballGame->flyingEnemyDirection[i] = 0;
                        }
                        else
                        {
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].x = 0xA700;
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y = 0xAC00;
                            gCurrentPinballGame->flyingEnemyDirection[i] = 1;
                        }

                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 9;
                        gCurrentPinballGame->flyingEnemyState[i] = 7;
                    }
                    else
                    {
                        gCurrentPinballGame->flyingEnemyDirection[i] = (gMain.systemFrameCount + Random()) % 2;
                        if (gCurrentPinballGame->flyingEnemyDirection[i])
                        {
                            if (gCurrentPinballGame->flyingEnemySpawnVariant[i] == 5)
                                gCurrentPinballGame->flyingEnemyPositionQ8[i].x = (((Random() % 101) / 5) + 80) << 8;
                            else
                                gCurrentPinballGame->flyingEnemyPositionQ8[i].x = (((Random() % 101) / 2) + 50) << 8;
                        }
                        else
                        {
                            if (gCurrentPinballGame->flyingEnemySpawnVariant[i] == 5)
                                gCurrentPinballGame->flyingEnemyPositionQ8[i].x = (((Random() % 101) / 5) + 140) << 8;
                            else
                                gCurrentPinballGame->flyingEnemyPositionQ8[i].x = (((Random() % 101) / 2) + 140) << 8;
                        }

                        gCurrentPinballGame->flyingEnemyPositionQ8[i].y = 0xAF00 + ((gCurrentPinballGame->flyingEnemySpawnVariant[i] - 2) * 0xA00);

                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 0;
                        gCurrentPinballGame->flyingEnemyState[i] = 2;
                    }

                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                }

                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                break;
            case 2:
                if (gSphealFlyingEnemyFramesetTable[gCurrentPinballGame->flyingEnemyFramesetIndex[i]][1] > gCurrentPinballGame->flyingEnemyAnimTimer[i])
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i]++;
                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 3)
                    {
                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 3;
                        gCurrentPinballGame->flyingEnemyState[i] = 3;
                    }

                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 1)
                        m4aSongNumStart(SE_UNKNOWN_0x134);
                }

                gCurrentPinballGame->flyingEnemyFlyTimer[i] = 0;
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 1;
                break;
            case 3:
                if (gSphealFlyingEnemyFramesetTable[gCurrentPinballGame->flyingEnemyFramesetIndex[i]][1] > gCurrentPinballGame->flyingEnemyAnimTimer[i])
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i]++;
                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 5)
                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 3;
                }

                if (gCurrentPinballGame->flyingEnemyFlyTimer[i] < 400)
                {
                    gCurrentPinballGame->flyingEnemyFlyTimer[i]++;
                    if (gCurrentPinballGame->flyingEnemyDirection[i])
                        gCurrentPinballGame->flyingEnemyPositionQ8[i].x += 35;
                    else
                        gCurrentPinballGame->flyingEnemyPositionQ8[i].x -= 35;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 6;
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyState[i] = 6;
                }

                gCurrentPinballGame->flyingEnemyCollisionType[i] = 1;
                break;
            case 4:
                MPlayStart(&gMPlayInfo_SE1, &se_unk_137);
                if (gCurrentPinballGame->flyingEnemyCollisionType[i] == 1)
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 5;
                    gCurrentPinballGame->flyingEnemyState[i] = 5;
                }
                else
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].y + (gCurrentPinballGame->flyingEnemyOamYOffset[i] << 8) < gCurrentPinballGame->ball->positionQ8.y)
                    {
                        gCurrentPinballGame->flyingEnemyState[i] = 10;
                    }
                    else
                    {
                        gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0xAC - (gCurrentPinballGame->flyingEnemyAnimTimer[i] * 12) / 0xA0;
                        gCurrentPinballGame->flyingEnemyState[i] = 8;
                    }
                }

                PlayRumble(7);
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                gCurrentPinballGame->scoreAddedInFrame = 3000;
                break;
            case 5:
                if (gCurrentPinballGame->flyingEnemyAnimTimer[i] < 10)
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 5;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyState[i] = 6;
                }
                break;
            case 6:
                if (gSphealFlyingEnemyFramesetTable[gCurrentPinballGame->flyingEnemyFramesetIndex[i]][1] > gCurrentPinballGame->flyingEnemyAnimTimer[i])
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i]++;
                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 9)
                    {
                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 0;
                        gCurrentPinballGame->flyingEnemyState[i] = 0;
                    }

                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 7)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }

                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;

                break;
            case 7:
                if (gSphealFlyingEnemyFramesetTable[gCurrentPinballGame->flyingEnemyFramesetIndex[i]][1] > gCurrentPinballGame->flyingEnemyAnimTimer[i])
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i]++;
                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 14)
                    {
                        gCurrentPinballGame->flyingEnemyState[i] = 8;
                        gCurrentPinballGame->flyingEnemyPositionQ8[i].x += gCurrentPinballGame->flyingEnemyOamXOffset[i] << 8;
                        gCurrentPinballGame->flyingEnemyPositionQ8[i].y += gCurrentPinballGame->flyingEnemyOamYOffset[i] << 8;
                    }

                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 10)
                        m4aSongNumStart(SE_UNKNOWN_0x140);

                }
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 2;

                break;
            case 8:
                if (gCurrentPinballGame->flyingEnemyAnimTimer[i] < 184)
                {
                    if (gCurrentPinballGame->flyingEnemyAnimTimer[i] < 160)
                    {
                        if (gCurrentPinballGame->flyingEnemyDirection[i] == 0)
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].x -= 0x10;
                        else
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].x += 0x10;

                        if (gCurrentPinballGame->flyingEnemyAnimTimer[i] & 1)
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y -= 0x10;
                        else
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y -= 0x20;

                        if (gCurrentPinballGame->flyingEnemyAnimTimer[i] % 19 < 10)
                            gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 14;
                        else
                            gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 15;
                    }
                    else
                    {
                        if (gCurrentPinballGame->flyingEnemyDirection[i] == 0)
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].x += 0x140;
                        else
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].x -= 0x140;

                        if (gCurrentPinballGame->flyingEnemyAnimTimer[i] & 1)
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y += 0x140;
                        else
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y += 0x1E0;

                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 15;
                    }

                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyState[i] = 9;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 16;
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    if (gCurrentPinballGame->flyingEnemyDirection[i] == 0)
                        gCurrentPinballGame->flyingEnemyPositionQ8[i].x += 0xF0;
                    else
                        gCurrentPinballGame->flyingEnemyPositionQ8[i].x -= 0xF0;
                }
                break;
            case 9:
                if (gSphealFlyingEnemyFramesetTable[gCurrentPinballGame->flyingEnemyFramesetIndex[i]][1] > gCurrentPinballGame->flyingEnemyAnimTimer[i])
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i]++;
                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 20)
                    {
                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 0;
                        gCurrentPinballGame->flyingEnemyState[i] = 0;
                    }

                    if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 17)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }
                break;
            case 10: {
                s16 len;
                if (gCurrentPinballGame->flyingEnemyDirection[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                len = gSphealFlightPathData[var1].pathLength;
                for (j = 0; j < len; j++)
                {
                    if (gSphealFlightPathData[var1].pathWaypoints[j].y <= gCurrentPinballGame->flyingEnemyScreenY[i])
                        break;
                }

                gCurrentPinballGame->flyingEnemyPathIndex[i] = j;
                gCurrentPinballGame->flyingEnemyState[i] = 11;
                gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 29;
                gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;

                gCurrentPinballGame->flyingEnemyPositionQ8[i].x = gSphealFlightPathData[var1].pathWaypoints[gCurrentPinballGame->flyingEnemyPathIndex[i]].x << 8;
                gCurrentPinballGame->flyingEnemyPositionQ8[i].y = gSphealFlightPathData[var1].pathWaypoints[gCurrentPinballGame->flyingEnemyPathIndex[i]].y << 8;

                gCurrentPinballGame->flyingEnemyPathIndex[i]++;
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                break;
            }
            case 11:
                if (gCurrentPinballGame->flyingEnemyDirection[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                var4 = gCurrentPinballGame->flyingEnemyPathIndex[i];
                var5 = gSphealFlightPathData;
                if (var4 < var5[var1].pathLength)
                {
                    gCurrentPinballGame->flyingEnemyPositionQ8[i].x = var5[var1].pathWaypoints[gCurrentPinballGame->flyingEnemyPathIndex[i]].x << 8;
                    gCurrentPinballGame->flyingEnemyPositionQ8[i].y = var5[var1].pathWaypoints[gCurrentPinballGame->flyingEnemyPathIndex[i]].y << 8;
                    gCurrentPinballGame->flyingEnemyPathIndex[i]++;
                    if (gCurrentPinballGame->flyingEnemyPathIndex[i] == var5[var1].pathLength)
                    {
                        gCurrentPinballGame->flyingEnemyState[i] = 12;
                        gCurrentPinballGame->knockdownTargetIndex[i] = gCurrentPinballGame->flyingEnemyDirection[i];
                        gCurrentPinballGame->knockdownPhase[i] = 2;
                        if (gCurrentPinballGame->flyingEnemyDirection[i] == 0)
                            gCurrentPinballGame->flyingEnemyVelocity[i].x = 0x140;
                        else
                            gCurrentPinballGame->flyingEnemyVelocity[i].x = -0x140;

                        gCurrentPinballGame->flyingEnemyVelocity[i].y = 0x1D0;
                    }
                }

                gCurrentPinballGame->flyingEnemyFramesetIndex[i] = ((gCurrentPinballGame->flyingEnemyAnimTimer[i] % 32) / 4) + 30;
                gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                break;
            case 12:
                gCurrentPinballGame->flyingEnemyPositionQ8[i].x += gCurrentPinballGame->flyingEnemyVelocity[i].x;
                gCurrentPinballGame->flyingEnemyPositionQ8[i].y += gCurrentPinballGame->flyingEnemyVelocity[i].y;
                gCurrentPinballGame->flyingEnemyFramesetIndex[i] = ((gCurrentPinballGame->flyingEnemyAnimTimer[i] % 32) / 4) + 30;
                gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                break;
            case 13:
                gCurrentPinballGame->flyingEnemyPositionQ8[i].x += gCurrentPinballGame->flyingEnemyVelocity[i].x;
                gCurrentPinballGame->flyingEnemyPositionQ8[i].y += gCurrentPinballGame->flyingEnemyVelocity[i].y;
                gCurrentPinballGame->flyingEnemyFramesetIndex[i] = ((gCurrentPinballGame->flyingEnemyAnimTimer[i] % 32) / 8) + 26;
                gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                break;
            case 14:
                gCurrentPinballGame->flyingEnemySpawnVariant[i] = -1;
                if (gCurrentPinballGame->flyingEnemyHitCooldown[i] > 0)
                {
                    gCurrentPinballGame->flyingEnemyHitCooldown[i]--;
                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 38;
                    gCurrentPinballGame->flyingEnemySinkSpeed[i] = 1;
                }
                else
                {
                    if (gCurrentPinballGame->flyingEnemyAnimTimer[i] < 334)
                    {
                        if (gCurrentPinballGame->flyingEnemyAnimTimer[i] < 16)
                        {
                            gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 21;
                            if (gCurrentPinballGame->flyingEnemyAnimTimer[i] == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x13E);

                            gCurrentPinballGame->flyingEnemyCollisionType[i] = 3;
                        }
                        else if (gCurrentPinballGame->flyingEnemyAnimTimer[i] < 316)
                        {
                            if (gCurrentPinballGame->flyingEnemySinkSpeed[i] == 0)
                            {
                                gCurrentPinballGame->flyingEnemyPositionQ8[i].y += 0x40;
                                if (gCurrentPinballGame->flyingEnemyAnimTimer[i] % 19 < 10)
                                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 22;
                                else
                                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 23;
                            }
                            else
                            {
                                gCurrentPinballGame->flyingEnemyPositionQ8[i].y += 0x80;
                                if (gCurrentPinballGame->flyingEnemyAnimTimer[i] % 10 < 5)
                                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 22;
                                else
                                    gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 23;
                            }

                            if (gCurrentPinballGame->flyingEnemyPositionQ8[i].y > 0xAC00)
                                gCurrentPinballGame->flyingEnemyAnimTimer[i] = 316;

                            gCurrentPinballGame->flyingEnemyCollisionType[i] = 3;
                        }
                        else
                        {
                            s16 var20;
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y += 0x30;
                            var20 = gCurrentPinballGame->flyingEnemyAnimTimer[i] - 316;
                            if (var20 < 10)
                                gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 24;
                            else
                                gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 25;

                            if (var20 == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x136);

                            gCurrentPinballGame->flyingEnemyCollisionType[i] = 0;
                        }

                        gCurrentPinballGame->flyingEnemyAnimTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->flyingEnemyState[i] = 0;
                        gCurrentPinballGame->flyingEnemyFramesetIndex[i] = 0;
                        gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    }
                }
                break;
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[14 + i];
        if (group->available)
        {
            sp4 = gCurrentPinballGame->flyingEnemyPrevSpriteIndex[i];
            gCurrentPinballGame->flyingEnemyPrevSpriteIndex[i] = gSphealFlyingEnemyFramesetTable[gCurrentPinballGame->flyingEnemyFramesetIndex[i]][2] + (1 - gCurrentPinballGame->flyingEnemyDirection[i]) * 30 ;
            var2 = gSphealFlyingEnemyFramesetTable[gCurrentPinballGame->flyingEnemyFramesetIndex[i]][0];

            group->baseX = (gCurrentPinballGame->flyingEnemyPositionQ8[i].x / 256) - (gCurrentPinballGame->cameraXOffset + 12);
            group->baseY = (gCurrentPinballGame->flyingEnemyPositionQ8[i].y / 256) - (gCurrentPinballGame->cameraYOffset + 14);

            DmaCopy16(3, gSphealFlyingEnemyVariantSprites[sp4], (void *)0x06011CA0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gSphealFlyingEnemyOamData[var2][j];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                if (gCurrentPinballGame->flyingEnemyDirection[i] == 0)
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->flyingEnemyOamXOffset[i] = -gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->flyingEnemyOamYOffset[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX + gCurrentPinballGame->flyingEnemyOamXOffset[i] * 2;
                }
                else
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->flyingEnemyOamXOffset[i] = gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->flyingEnemyOamYOffset[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                }

                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum += i * 9;
            }

            var3 = 0x10;
            gCurrentPinballGame->flyingEnemyCollisionPos[i].x = ((gCurrentPinballGame->flyingEnemyPositionQ8[i].x / 256) + (gCurrentPinballGame->flyingEnemyOamXOffset[i] - var3)) * 2;

            var3 = 0x12;
            gCurrentPinballGame->flyingEnemyCollisionPos[i].y = ((gCurrentPinballGame->flyingEnemyPositionQ8[i].y / 256) + (gCurrentPinballGame->flyingEnemyOamYOffset[i] - var3)) * 2;

            gCurrentPinballGame->flyingEnemyScreenY[i] = gCurrentPinballGame->flyingEnemyPositionQ8[i].y / 256 + gCurrentPinballGame->flyingEnemyOamYOffset[i];

            group = &gMain.spriteGroups[16 + i];
            if (sp4 == 12 || sp4 == 42)
            {
                if (gCurrentPinballGame->flyingEnemyFramesetIndex[i] == 11)
                    sp4 = 8;
                else
                    sp4 = 9;
            }
            else
            {
                sp4 = 0;
            }

            group->baseX = (gCurrentPinballGame->flyingEnemyPositionQ8[i].x / 256) - (gCurrentPinballGame->cameraXOffset + 12);
            group->baseY = (gCurrentPinballGame->flyingEnemyPositionQ8[i].y / 256) - (gCurrentPinballGame->cameraYOffset + 14);

            DmaCopy16(3, gSphealFlyingEnemyVariantSprites[sp4], (void *)0x06011EE0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void UpdateSphealScoreAndDelivery(void)
{
    s16 i;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = 0;
    group = &gMain.spriteGroups[18];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 86 - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->scoreCountdownTimer < 22)
            var0 = gSphealScoreDigitSpriteIndices[gCurrentPinballGame->scoreCountdownTimer];

        DmaCopy16(3, gSphealScoreCounterDigitSprites[var0], (void *)0x06010920, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[11];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 94 - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gSphealExtendedScoreSprites[var0], (void *)0x06010B20, 0x180);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->boardState == 1)
        gMain.spriteGroups[11].available = 1;

    if (gCurrentPinballGame->boardState < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->scoreCountdownTimer)
    {
        if (gCurrentPinballGame->scoreCountdownTimer == 21)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_138);

        gCurrentPinballGame->scoreCountdownTimer--;
        if (gCurrentPinballGame->scoreCountdownTimer == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_139);
    }

    if (gCurrentPinballGame->ballDeliveryActive)
    {
        if (gMain.tempField == FIELD_RUBY)
            SphealBoard_WhiscashDeliversBall();
        else
            SphealBoard_PelipperDeliversBall();
    }
}

void SphealBoard_WhiscashDeliversBall(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const u16 *offsets;
    s16 var0;

    group = &gMain.spriteGroups[19];
    if (group->available)
    {
        offsets = gSphealWhiscashAnimFrameset[gCurrentPinballGame->deliveryAnimFrameIndex];
        group->baseX = 134 + offsets[2] - gCurrentPinballGame->cameraXOffset;
        group->baseY = 154 + offsets[3] - gCurrentPinballGame->cameraYOffset;
        var0 = offsets[0];
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06012120, 0x460);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gSphealWhiscashAnimFrameset[gCurrentPinballGame->deliveryAnimFrameIndex][1] > gCurrentPinballGame->deliveryAnimTimer)
    {
        gCurrentPinballGame->deliveryAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->deliveryAnimTimer = 0;
        gCurrentPinballGame->deliveryAnimFrameIndex++;
        if (gCurrentPinballGame->deliveryAnimFrameIndex == 1)
            gMain.spriteGroups[19].available = 1;

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 19)
        {
            gCurrentPinballGame->deliveryAnimFrameIndex = 18;
            gMain.spriteGroups[19].available = 0;
            gCurrentPinballGame->ballDeliveryActive = 0;
        }

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 9)
        {
            gCurrentPinballGame->ball->spinAngle -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8D00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC800;
            gCurrentPinballGame->ball->velocity.x = -0x60;
            gCurrentPinballGame->ball->velocity.y = 0x54;
            gCurrentPinballGame->ball->oamPriority = 3;
            PlayRumble(7);
        }

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 2)
            m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 15)
            m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 8)
        {
            m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
            gCurrentPinballGame->ball->ballHidden = 0;
            gCurrentPinballGame->ball->spinAngle -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8F00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC300;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 10)
            gCurrentPinballGame->ballFrozenState = 0;
    }
}

void SphealBoard_PelipperDeliversBall(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[20];
    if (group->available)
    {
        group->baseX = (gCurrentPinballGame->pelipperPosX / 10) - (gCurrentPinballGame->cameraXOffset - 146);
        group->baseY = (gCurrentPinballGame->pelipperPosY / 10) - (gCurrentPinballGame->cameraYOffset - 110) + (gCurrentPinballGame->pelipperYBobOffset / 10);
        index = gCurrentPinballGame->deliveryAnimFrameIndex;
        DmaCopy16(3, gPelipper_Gfx[index], (void *)0x060125A0, 0x480);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->deliveryAnimTimer <= 250)
    {
        if (gCurrentPinballGame->deliveryAnimTimer == 250)
        {
            gCurrentPinballGame->pelipperPosX = 920;
            gCurrentPinballGame->pelipperPosY = -100;
            gCurrentPinballGame->pelipperFlyVelX = -82;
            gCurrentPinballGame->pelipperFlyVelY = 0;
            gCurrentPinballGame->pelipperFrameTimer = 0;
            gCurrentPinballGame->pelipperState = 8;
            gCurrentPinballGame->deliveryAnimFrameIndex = 13;
            gMain.spriteGroups[20].available = 1;
            gCurrentPinballGame->boardEntityActive = 1;
        }
    }
    else
    {
        gCurrentPinballGame->deliveryAnimFrameIndex = (gCurrentPinballGame->pelipperFrameTimer % 24) / 6 + 13;
        gCurrentPinballGame->pelipperYBobOffset = (Sin(gCurrentPinballGame->pelipperFrameTimer * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->pelipperFrameTimer < 40)
        {
            gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
            gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        }
        else
        {
            gMain.spriteGroups[20].available = 0;
        }

        if (gCurrentPinballGame->pelipperFrameTimer == 13)
        {
            gCurrentPinballGame->ball->ballHidden = 0;
            gCurrentPinballGame->pelipperBallDropVelX = -10;
            gCurrentPinballGame->pelipperBallDropVelY = -25;
            gCurrentPinballGame->pelipperBallDropPosX = ((gCurrentPinballGame->pelipperPosX / 10) + 157) * 10;
            gCurrentPinballGame->pelipperBallDropPosY = ((gCurrentPinballGame->pelipperPosY / 10) + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->ballFrozenState)
        {
            if (gCurrentPinballGame->pelipperFrameTimer < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = (gCurrentPinballGame->pelipperPosX / 10) + 157;
                gCurrentPinballGame->ball->positionQ0.y = (gCurrentPinballGame->pelipperPosY / 10) + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->pelipperBallDropVelY += 2;
                gCurrentPinballGame->pelipperBallDropPosX += gCurrentPinballGame->pelipperBallDropVelX;
                gCurrentPinballGame->pelipperBallDropPosY += gCurrentPinballGame->pelipperBallDropVelY;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperBallDropPosX / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperBallDropPosY / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 181)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 181;
                    gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
                    gCurrentPinballGame->ballFrozenState = 0;
                    gCurrentPinballGame->ball->velocity.x = -10;
                    gCurrentPinballGame->ball->velocity.y = 0;
                    gCurrentPinballGame->boardEntityActive = 0;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->boardLayerDepth = 0;
                    gCurrentPinballGame->ballDeliveryActive = 0;
                    m4aSongNumStart(SE_UNKNOWN_0xE5);
                    PlayRumble(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        gCurrentPinballGame->pelipperFrameTimer++;
    }

    gCurrentPinballGame->deliveryAnimTimer++;
}

void UpdateSealeoKnockdownPhysics(void)
{
    s16 i;
    s16 var0;

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->knockdownPhase[i])
        {
        case 0:
            gCurrentPinballGame->knockdownTargetIndex[i] = 0;
            break;
        case 1:
            var0 = gCurrentPinballGame->knockdownTargetIndex[i];
            gCurrentPinballGame->minionState[var0] = 2;
            gCurrentPinballGame->minionStateTimer[var0] = 0;
            gCurrentPinballGame->minionFramesetIx[var0] = 7;
            if (gCurrentPinballGame->knockdownStunTimer[i])
            {
                gCurrentPinballGame->knockdownStunTimer[i]--;
                if (gCurrentPinballGame->knockdownStunTimer[i] == 0)
                {
                    gCurrentPinballGame->knockdownPhase[i] = 0;
                    gCurrentPinballGame->minionState[var0] = 1;
                    gCurrentPinballGame->minionStateTimer[var0] = 0;
                    gCurrentPinballGame->minionFramesetIx[var0] = 4;
                }
            }
            break;
        case 2:
            var0 = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i == 2)
            {
                gCurrentPinballGame->ballFrozenState = 1;
                gCurrentPinballGame->ball->velocity.x += 5 - var0 * 10;
            }

            gCurrentPinballGame->knockdownPhase[i] = 3;
            gCurrentPinballGame->knockdownBounceCount[i] = 0;
            gCurrentPinballGame->minionState[var0] = 2;
            gCurrentPinballGame->minionStateTimer[var0] = 0;
            gCurrentPinballGame->minionFramesetIx[var0] = 7;
            break;
        case 3:
            var0 = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i < 2)
            {
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].x >= 0x5600)
                        gCurrentPinballGame->flyingEnemyVelocity[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].x <= 0x9C00)
                        gCurrentPinballGame->flyingEnemyVelocity[i].x = 0;

                }

                gCurrentPinballGame->flyingEnemyVelocity[i].y += 12;
                if (gCurrentPinballGame->minionHitFlashTimer[var0] > 0)
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->knockdownBounceCount[i] = 0;
                        gCurrentPinballGame->knockdownPhase[i] = 5;
                        gCurrentPinballGame->minionState[var0] = 3;
                        gCurrentPinballGame->minionFramesetIx[var0] = 15;
                        gCurrentPinballGame->minionStateTimer[var0] = 0;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->knockdownBounceCount[i]++;
                        MPlayStart(&gMPlayInfo_SE1, &se_unk_13d);
                        if (gCurrentPinballGame->knockdownBounceCount[i] < 3)
                        {
                            gCurrentPinballGame->flyingEnemyPositionQ8[i].y = 0x6600;
                            gCurrentPinballGame->flyingEnemyVelocity[i].y = 0xFED4;
                            gCurrentPinballGame->flyingEnemyState[i] = 13;
                            gCurrentPinballGame->minionState[var0] = 2;
                            gCurrentPinballGame->minionFramesetIx[var0] = 8;
                            gCurrentPinballGame->minionStateTimer[var0] = 12;
                        }
                        else
                        {
                            gCurrentPinballGame->flyingEnemyVelocity[i].x = (30 - var0 * 60) * 4;
                            gCurrentPinballGame->flyingEnemyVelocity[i].y = 0xFE70;
                            gCurrentPinballGame->knockdownBounceCount[i] = 0;
                            gCurrentPinballGame->knockdownPhase[i] = 4;
                            gCurrentPinballGame->minionState[var0] = 3;
                            gCurrentPinballGame->minionFramesetIx[var0] = 11;
                            gCurrentPinballGame->minionStateTimer[var0] = 0;
                            gCurrentPinballGame->scoreCountdownTimer = 100;
                            gCurrentPinballGame->sphealKnockdownCount[0]++;
                        }
                    }
                }
            }
            else
            {
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x5600)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x9C00)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                gCurrentPinballGame->ball->velocity.y += 3;
                if (gCurrentPinballGame->ball->positionQ8.y >= 0x6500)
                {
                    gCurrentPinballGame->knockdownBounceCount[i]++;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_13d);
                    PlayRumble(7);
                    if (gCurrentPinballGame->knockdownBounceCount[i] < 3)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x6500;
                        gCurrentPinballGame->ball->velocity.y = -0x5A;
                        gCurrentPinballGame->minionState[var0] = 2;
                        gCurrentPinballGame->minionFramesetIx[var0] = 8;
                        gCurrentPinballGame->minionStateTimer[var0] = 12;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.x = 28 - var0 * 56;
                        gCurrentPinballGame->ball->velocity.y = -0x78;
                        gCurrentPinballGame->knockdownBounceCount[i] = 0;
                        gCurrentPinballGame->knockdownPhase[i] = 4;
                        gCurrentPinballGame->minionState[var0] = 3;
                        gCurrentPinballGame->minionFramesetIx[var0] = 11;
                        gCurrentPinballGame->minionStateTimer[var0] = 0;
                        gCurrentPinballGame->scoreCountdownTimer = 106;
                        gCurrentPinballGame->sphealKnockdownCount[1]++;
                    }
                }
            }
            break;
        case 4:
            var0 = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i < 2)
            {
                gCurrentPinballGame->flyingEnemyVelocity[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].x >= 0x7800)
                        gCurrentPinballGame->flyingEnemyVelocity[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].x <= 0x7800)
                        gCurrentPinballGame->flyingEnemyVelocity[i].x = 0;
                }

                if (gCurrentPinballGame->flyingEnemyPositionQ8[i].y >= 0x8400)
                {
                    gCurrentPinballGame->knockdownPhase[i] = 0;
                    gCurrentPinballGame->flyingEnemyState[i] = 14;
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemySinkSpeed[i] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->velocity.y += 3;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8400)
                {
                    gCurrentPinballGame->knockdownBounceCount[i]++;
                    if (gCurrentPinballGame->knockdownBounceCount[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8400;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                        if (gCurrentPinballGame->knockdownBounceCount[i] == 1)
                            PlayRumble(7);
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->ballFrozenState = 0;
                        gCurrentPinballGame->knockdownPhase[i] = 0;
                    }
                }
            }
            break;
        case 5:
            var0 = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i < 2)
            {
                gCurrentPinballGame->flyingEnemyVelocity[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].x >= 0x7800)
                        gCurrentPinballGame->flyingEnemyVelocity[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->flyingEnemyPositionQ8[i].x <= 0x7800)
                        gCurrentPinballGame->flyingEnemyVelocity[i].x = 0;
                }

                if (gCurrentPinballGame->flyingEnemyPositionQ8[i].y >= 0x8E00)
                {
                    gCurrentPinballGame->knockdownPhase[i] = 0;
                    gCurrentPinballGame->flyingEnemyState[i] = 14;
                    gCurrentPinballGame->flyingEnemyAnimTimer[i] = 0;
                    gCurrentPinballGame->flyingEnemySinkSpeed[i] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->velocity.y += 3;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8E00)
                {
                    gCurrentPinballGame->knockdownBounceCount[i]++;
                    if (gCurrentPinballGame->knockdownBounceCount[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8E00;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->ballFrozenState = 0;
                        gCurrentPinballGame->knockdownPhase[i] = 0;
                    }
                }
            }
            break;
        }
    }
}

void AnimateSphealBackground(void)
{
    s16 i;
    s16 var0;

    var0 = gWaterTilePaletteCycle[(gMain.systemFrameCount % 96) / 24];
    for (i = 0x100; i < 0x400; i++)
        gBG0TilemapBuffer[0x800 + i] = gSphealWaterBackgroundTilemap[i] + var0 * 4;

    DmaCopy16(3, &gBG0TilemapBuffer[0x800], (void *)0x06000000, 0x800);
}

void UpdateSphealResultsScreen(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int value;
    s16 sp0[12];
    s16 sp18[12];

    if (gCurrentPinballGame->boardState > 3)
    {
        if (gCurrentPinballGame->bannerSlideYOffset > -126)
        {
            gCurrentPinballGame->bannerSlideYOffset -= 6;
            gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->bannerSlideYOffset + 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->bannerSlideYOffset < 0)
        {
            gCurrentPinballGame->bannerSlideYOffset += 6;
            if (gCurrentPinballGame->bannerSlideYOffset > 0)
                gCurrentPinballGame->bannerSlideYOffset = 0;
        }

        gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->bannerSlideYOffset + 4;
    }

    if (gCurrentPinballGame->boardState < 5)
    {
        gMain.blendControl = 0x1C42;
        gMain.blendAlpha = 0xC04;
    }

    if (gCurrentPinballGame->boardState == 3)
    {
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer += 0;
    }

    if (gCurrentPinballGame->resultsAnimTimer > 100 && gCurrentPinballGame->resultsAnimTimer < 450)
    {
        if (gCurrentPinballGame->sphealKnockdownDisplayCount[0] != gCurrentPinballGame->sphealKnockdownCount[0])
        {
            if ((gCurrentPinballGame->resultsAnimTimer % 3) == 0)
            {
                gCurrentPinballGame->sphealKnockdownDisplayCount[0]++;
                m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            }
        }
        else
        {
            gCurrentPinballGame->resultsAnimTimer = 490;
        }
    }

    if (gCurrentPinballGame->resultsAnimTimer > 500 && gCurrentPinballGame->resultsAnimTimer < 800)
    {
        if (gCurrentPinballGame->sphealKnockdownDisplayCount[1] != gCurrentPinballGame->sphealKnockdownCount[1])
        {
            if ((gCurrentPinballGame->resultsAnimTimer % 3) == 0)
            {
                gCurrentPinballGame->sphealKnockdownDisplayCount[1]++;
                m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            }
        }
        else
        {
            gCurrentPinballGame->resultsAnimTimer = 800;
        }
    }

    if (gCurrentPinballGame->resultsAnimTimer < 800 && gCurrentPinballGame->stageTimer > 160)
        gCurrentPinballGame->stageTimer = 160;

    gCurrentPinballGame->resultsAnimTimer++;

    group = &gMain.spriteGroups[7];
    if (!group->available)
        return;

    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 22; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[0] * 5000000;
    sp0[0] = value / 10000000;
    sp0[1] = (value % 10000000) / 1000000;
    sp0[2] = 10;
    sp0[3] = (value % 1000000) / 100000;
    sp0[4] = (value % 100000) / 10000;
    sp0[5] = (value % 10000) / 1000;
    sp0[6] = 10;
    sp0[7] = (value % 1000) / 100;
    sp0[8] = (value % 100) / 10;
    sp0[9] = value % 10;
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[0];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[8];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[1] * 1000000;
    sp0[0] = value / 10000000;
    sp0[1] = (value % 10000000) / 1000000;
    sp0[2] = 10;
    sp0[3] = (value % 1000000) / 100000;
    sp0[4] = (value % 100000) / 10000;
    sp0[5] = (value % 10000) / 1000;
    sp0[6] = 10;
    sp0[7] = (value % 1000) / 100;
    sp0[8] = (value % 100) / 10;
    sp0[9] = value % 10;
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[1];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[9];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[0] * 5000000
          + gCurrentPinballGame->sphealKnockdownDisplayCount[1] * 1000000;
    gCurrentPinballGame->totalBonusScore = value;
    sp0[0] = value / 100000000;
    sp0[1] = (value % 100000000) / 10000000;
    sp0[2] = (value % 10000000) / 1000000;
    sp0[3] = 10;
    sp0[4] = (value % 1000000) / 100000;
    sp0[5] = (value % 100000) / 10000;
    sp0[6] = (value % 10000) / 1000;
    sp0[7] = 10;
    sp0[8] = (value % 1000) / 100;
    sp0[9] = (value % 100) / 10;
    sp0[10] = value % 10;
    for (i = 0; i < 10; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;
    sp18[10] = sp0[10] * 2 + 0x2D0;
    value = gCurrentPinballGame->ballUpgradeType + 1;
    sp0[0] = value;
    sp18[11] = sp0[0] * 2 + 0x2D0;

    group = &gMain.spriteGroups[10];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }
}
