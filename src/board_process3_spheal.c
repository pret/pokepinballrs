#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

struct EntityPathData
{
    struct Vector16 *waypoints;
    s16 waypointCount;
};
extern const struct EntityPathData gUnknown_086AFAC0[];

extern const s16 gUnknown_086AFC16[][4];
extern struct SongHeader se_unk_137;
extern struct SongHeader se_unk_138;
extern struct SongHeader se_unk_139;
extern struct SongHeader se_unk_13b;
extern struct SongHeader se_unk_13c;
extern struct SongHeader se_unk_13d;

extern const s8 gUnknown_08137D60[];
extern const u16 gUnknown_0837A4E8[];
extern const u8 gUnknown_084AF9EC[][0x200];
extern const u8 gUnknown_084AFFEC[][0x180];
extern const u8 gUnknown_084B046C[][0x120];
extern const u8 gUnknown_084B47EC[][0x800];
extern const u8 gUnknown_084B77EC[];
extern const u8 gWhiscash_Gfx[][0x480];
extern const u8 gPelliper_Gfx[][0x480];
extern const s16 gUnknown_086AEED6[];
extern const u16 gUnknown_086AFAE0[][2];
extern const u16 gUnknown_086AFAE2[][2];
extern const u16 gUnknown_086AFB2C[][3];
extern const u16 gUnknown_086B56D8[126][4][3];


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
    gCurrentPinballGame->entityActivePhase = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 7200;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->bonusSequenceTimer = 0;
    gCurrentPinballGame->bossGrabbedBall = 0;
    gCurrentPinballGame->bonusCaptureState = 0;
    gCurrentPinballGame->ball->isGrabbed = 1;
    gCurrentPinballGame->ballLockState = 1;
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->spin = 0;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->sealStageProgressTimer = 0;
    gCurrentPinballGame->sealSplashTimer = 0;
    gCurrentPinballGame->sealBonusScoreValue = 0;
    gCurrentPinballGame->unk54A = 0;
    gCurrentPinballGame->bonusScrollOffsetY = 0;
    gCurrentPinballGame->unk590 = 0;
    gCurrentPinballGame->sealSplashAnimIndex = 0;
    gCurrentPinballGame->sealSplashSubTimer = 0;
    gCurrentPinballGame->unk594 = 0;
    gCurrentPinballGame->unk596 = 0;
    gCurrentPinballGame->sphealBallDeliveryActive = 1;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->minionState[i] = 0;
        gCurrentPinballGame->minionFramesetIx[i] = 0;
        gCurrentPinballGame->minionStateTimer[i] = 0;
    }

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->sealBounceActiveSide[i] = 0;
        gCurrentPinballGame->sealBounceSubCount[i] = 0;
        gCurrentPinballGame->sealBounceAnimState[i] = 0;
        gCurrentPinballGame->sealBounceInvulnTimer[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->sealBounceHitCount[i] = 0;
        gCurrentPinballGame->sealBounceDisplayCount[i] = 0;
        gCurrentPinballGame->sealHitStunTimer[i] = 0;
        gCurrentPinballGame->entityReturnedFlag[i] = 0;
        gCurrentPinballGame->entityHitCooldown[i] = 0;
        gCurrentPinballGame->entityMovePhase[i] = 0;
        gCurrentPinballGame->entitySideChoice[i] = 0;
        gCurrentPinballGame->entityAIState[i] = 0;
        gCurrentPinballGame->entitySpriteBaseFrame[i] = 0;
        gCurrentPinballGame->entitySpawnLane[i] = 0;
        gCurrentPinballGame->entityPathWaypointIndex[i] = 0;
        gCurrentPinballGame->entityActionIndex[i] = 0;
        gCurrentPinballGame->entityOamOffsetX[i] = 0;
        gCurrentPinballGame->entityOamOffsetY[i] = 0;
        gCurrentPinballGame->entityActionTimer[i] = 0;
        gCurrentPinballGame->entityScreenY[i] = 0;
        gCurrentPinballGame->entityScreenX[i] = 0;
        gCurrentPinballGame->entityLogicPos[i].x = 0;
        gCurrentPinballGame->entityLogicPos[i].y = 0;
        gCurrentPinballGame->entityCollisionPos[i].x = 0;
        gCurrentPinballGame->entityCollisionPos[i].y = 0;
        gCurrentPinballGame->entitySpawnPositions[i].x = 0;
        gCurrentPinballGame->entitySpawnPositions[i].y = 0;
    }

    gCurrentPinballGame->fieldEntryInProgress = 0;
    UpdateWhiscashPelliperEntity();
    UpdateSphealMinions();
    RenderIceBlockAndDeliverBall();
    AnimateSphealWaterPalette();

    for (i = 0; i < 0x800; i++)
        gBgScreenBuffer[0x400 + i] = 0x200;

    DmaCopy16(3, &gBgScreenBuffer[0x400], (void *)0x06001000, 0x1000);

    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        u16 var0 = i - ((i / 0x20) * 0x20) - 2;
        if (var0 < 28)
           gBgScreenBuffer[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gBgScreenBuffer[0x800], (void *)0x06001140, 0x280);
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
    m4aSongNumStart(MUS_BONUS_FIELD_SPHEAL);
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void SphealBoardProcess_3B_43228(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case 0:
        gCurrentPinballGame->ballLocked = 1;
        if (gCurrentPinballGame->stageTimer < 340)
        {
            if (gCurrentPinballGame->stageTimer < 321)
                gCurrentPinballGame->fieldScrollOffsetY = (gCurrentPinballGame->stageTimer / 5) + 0xFFC0;

            if (gCurrentPinballGame->stageTimer == 325)
                gCurrentPinballGame->entityActivePhase = 2;

            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->fieldScrollOffsetY = 0;
            gCurrentPinballGame->boardState = 1;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 1:
        if (gCurrentPinballGame->eventTimer == 0)
        {
            gCurrentPinballGame->entityActivePhase = 3;
            if (gCurrentPinballGame->stageTimer == 0)
            {
                m4aMPlayAllStop();
                MPlayStart(&gMPlayInfo_SE1, &se_unk_13b);
                gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
                gCurrentPinballGame->bonusCaptureState = 2;
                gCurrentPinballGame->bonusSequenceTimer = 0;
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
            DmaCopy16(3, gUnknown_084B77EC, (void *)0x06015800, 0x800);
            gCurrentPinballGame->bonusScrollOffsetY = -126;
            gCurrentPinballGame->bossActive = 1;
        }
        break;
    case 3:
        RenderBonusResultsScreen();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180 && gCurrentPinballGame->sealBonusScoreValue != 0)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = gCurrentPinballGame->sealBonusScoreValue;
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

        gCurrentPinballGame->bossActive = 1;
        break;
    case 4:
        RenderBonusResultsScreen();
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
        RenderBonusResultsScreen();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        gCurrentPinballGame->bossActive = 1;
        break;
    }

    UpdateWhiscashPelliperEntity();
    UpdateSphealMinions();
    RenderIceBlockAndDeliverBall();
    AnimateSphealWaterPalette();
    if (gCurrentPinballGame->returnToMainBoardFlag)
    {
        gCurrentPinballGame->bossActive = 1;
        FadeToMainBoard();
    }

    BonusStage_HandleModeChangeFlags();
}

void UpdateSphealMinions(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->boardState < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        ProcessSealBounceCollisions();

    if (gCurrentPinballGame->boardState < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            if (gCurrentPinballGame->sealHitStunTimer[i] == 23)
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
                if (gCurrentPinballGame->sealHitStunTimer[i] > 0)
                {
                    gCurrentPinballGame->sealHitStunTimer[i]--;
                }
                else
                {
                    if (gUnknown_086AFAE2[gCurrentPinballGame->minionFramesetIx[i]][0] > gCurrentPinballGame->minionStateTimer[i])
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
                if (gCurrentPinballGame->sealHitStunTimer[i] > 0)
                {
                    gCurrentPinballGame->sealHitStunTimer[i]--;
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
                if (gCurrentPinballGame->sealHitStunTimer[i] > 0)
                {
                    gCurrentPinballGame->sealHitStunTimer[i]--;
                }
                else
                {
                    if (gUnknown_086AFAE2[gCurrentPinballGame->minionFramesetIx[i]][0] > gCurrentPinballGame->minionStateTimer[i])
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
        group->baseX = 100 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 94 - gCurrentPinballGame->bgScrollYWithOffset;
        if (gCurrentPinballGame->sealHitStunTimer[0] > 0)
            var0 = 0;
        else
            var0 = gUnknown_086AFAE0[gCurrentPinballGame->minionFramesetIx[0]][0];

        DmaCopy16(3, gUnknown_084B47EC[var0], (void *)0x060114A0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[21];
    if (group->available)
    {
        group->baseX = 140 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 94 - gCurrentPinballGame->bgScrollYWithOffset;
        if (gCurrentPinballGame->sealHitStunTimer[1] > 0)
            var0 = 0;
        else
            var0 = gUnknown_086AFAE0[gCurrentPinballGame->minionFramesetIx[1]][0];

        DmaCopy16(3, gUnknown_084B47EC[var0], (void *)0x06010CA0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateWhiscashPelliperEntity(void)
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
    const struct EntityPathData *var5;

    if (gCurrentPinballGame->boardState == 1 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            switch (gCurrentPinballGame->entityAIState[i])
            {
            case 0:
                gCurrentPinballGame->entityAIState[i] = 1;
                gCurrentPinballGame->entityActionIndex[i] = 0;
                gCurrentPinballGame->entityActionTimer[i] = 0;
                gCurrentPinballGame->entityMovePhase[i] = 0;
                gCurrentPinballGame->entitySpawnLane[i] = -1;
                break;
            case 1:
                if (gCurrentPinballGame->entityActionTimer[i] < i * 30 + 120)
                {
                    gCurrentPinballGame->entityActionTimer[i]++;
                }
                else
                {
                    u16 var0 = gMain.systemFrameCount + Random();
                    gCurrentPinballGame->entitySpawnLane[i] = var0 % 6;
                    if (gCurrentPinballGame->entitySpawnLane[0] == gCurrentPinballGame->entitySpawnLane[1])
                        gCurrentPinballGame->entitySpawnLane[i] = (gCurrentPinballGame->entitySpawnLane[i] + 2) % 6;

                    if (gCurrentPinballGame->entitySpawnLane[i] < 2)
                    {
                        if (gCurrentPinballGame->entitySpawnLane[i] == 0)
                        {
                            gCurrentPinballGame->entitySpawnPositions[i].x = 0x4900;
                            gCurrentPinballGame->entitySpawnPositions[i].y = 0xAB00;
                            gCurrentPinballGame->entitySideChoice[i] = 0;
                        }
                        else
                        {
                            gCurrentPinballGame->entitySpawnPositions[i].x = 0xA700;
                            gCurrentPinballGame->entitySpawnPositions[i].y = 0xAC00;
                            gCurrentPinballGame->entitySideChoice[i] = 1;
                        }

                        gCurrentPinballGame->entityActionIndex[i] = 9;
                        gCurrentPinballGame->entityAIState[i] = 7;
                    }
                    else
                    {
                        gCurrentPinballGame->entitySideChoice[i] = (gMain.systemFrameCount + Random()) % 2;
                        if (gCurrentPinballGame->entitySideChoice[i])
                        {
                            if (gCurrentPinballGame->entitySpawnLane[i] == 5)
                                gCurrentPinballGame->entitySpawnPositions[i].x = (((Random() % 101) / 5) + 80) << 8;
                            else
                                gCurrentPinballGame->entitySpawnPositions[i].x = (((Random() % 101) / 2) + 50) << 8;
                        }
                        else
                        {
                            if (gCurrentPinballGame->entitySpawnLane[i] == 5)
                                gCurrentPinballGame->entitySpawnPositions[i].x = (((Random() % 101) / 5) + 140) << 8;
                            else
                                gCurrentPinballGame->entitySpawnPositions[i].x = (((Random() % 101) / 2) + 140) << 8;
                        }

                        gCurrentPinballGame->entitySpawnPositions[i].y = 0xAF00 + ((gCurrentPinballGame->entitySpawnLane[i] - 2) * 0xA00);

                        gCurrentPinballGame->entityActionIndex[i] = 0;
                        gCurrentPinballGame->entityAIState[i] = 2;
                    }

                    gCurrentPinballGame->entityActionTimer[i] = 0;
                }

                gCurrentPinballGame->entityMovePhase[i] = 0;
                break;
            case 2:
                if (gUnknown_086AFB2C[gCurrentPinballGame->entityActionIndex[i]][1] > gCurrentPinballGame->entityActionTimer[i])
                {
                    gCurrentPinballGame->entityActionTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityActionIndex[i]++;
                    if (gCurrentPinballGame->entityActionIndex[i] == 3)
                    {
                        gCurrentPinballGame->entityActionIndex[i] = 3;
                        gCurrentPinballGame->entityAIState[i] = 3;
                    }

                    if (gCurrentPinballGame->entityActionIndex[i] == 1)
                        m4aSongNumStart(SE_UNKNOWN_0x134);
                }

                gCurrentPinballGame->entityScreenX[i] = 0;
                gCurrentPinballGame->entityMovePhase[i] = 1;
                break;
            case 3:
                if (gUnknown_086AFB2C[gCurrentPinballGame->entityActionIndex[i]][1] > gCurrentPinballGame->entityActionTimer[i])
                {
                    gCurrentPinballGame->entityActionTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityActionIndex[i]++;
                    if (gCurrentPinballGame->entityActionIndex[i] == 5)
                        gCurrentPinballGame->entityActionIndex[i] = 3;
                }

                if (gCurrentPinballGame->entityScreenX[i] < 400)
                {
                    gCurrentPinballGame->entityScreenX[i]++;
                    if (gCurrentPinballGame->entitySideChoice[i])
                        gCurrentPinballGame->entitySpawnPositions[i].x += 35;
                    else
                        gCurrentPinballGame->entitySpawnPositions[i].x -= 35;
                }
                else
                {
                    gCurrentPinballGame->entityActionIndex[i] = 6;
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityAIState[i] = 6;
                }

                gCurrentPinballGame->entityMovePhase[i] = 1;
                break;
            case 4:
                MPlayStart(&gMPlayInfo_SE1, &se_unk_137);
                if (gCurrentPinballGame->entityMovePhase[i] == 1)
                {
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityActionIndex[i] = 5;
                    gCurrentPinballGame->entityAIState[i] = 5;
                }
                else
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].y + (gCurrentPinballGame->entityOamOffsetY[i] << 8) < gCurrentPinballGame->ball->positionQ8.y)
                    {
                        gCurrentPinballGame->entityAIState[i] = 10;
                    }
                    else
                    {
                        gCurrentPinballGame->entityActionTimer[i] = 0xAC - (gCurrentPinballGame->entityActionTimer[i] * 12) / 0xA0;
                        gCurrentPinballGame->entityAIState[i] = 8;
                    }
                }

                PlayRumble(7);
                gCurrentPinballGame->entityMovePhase[i] = 0;
                gCurrentPinballGame->scoreAddedInFrame = 3000;
                break;
            case 5:
                if (gCurrentPinballGame->entityActionTimer[i] < 10)
                {
                    gCurrentPinballGame->entityActionTimer[i]++;
                    gCurrentPinballGame->entityActionIndex[i] = 5;
                }
                else
                {
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityAIState[i] = 6;
                }
                break;
            case 6:
                if (gUnknown_086AFB2C[gCurrentPinballGame->entityActionIndex[i]][1] > gCurrentPinballGame->entityActionTimer[i])
                {
                    gCurrentPinballGame->entityActionTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityActionIndex[i]++;
                    if (gCurrentPinballGame->entityActionIndex[i] == 9)
                    {
                        gCurrentPinballGame->entityActionIndex[i] = 0;
                        gCurrentPinballGame->entityAIState[i] = 0;
                    }

                    if (gCurrentPinballGame->entityActionIndex[i] == 7)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }

                gCurrentPinballGame->entityMovePhase[i] = 0;

                break;
            case 7:
                if (gUnknown_086AFB2C[gCurrentPinballGame->entityActionIndex[i]][1] > gCurrentPinballGame->entityActionTimer[i])
                {
                    gCurrentPinballGame->entityActionTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityActionIndex[i]++;
                    if (gCurrentPinballGame->entityActionIndex[i] == 14)
                    {
                        gCurrentPinballGame->entityAIState[i] = 8;
                        gCurrentPinballGame->entitySpawnPositions[i].x += gCurrentPinballGame->entityOamOffsetX[i] << 8;
                        gCurrentPinballGame->entitySpawnPositions[i].y += gCurrentPinballGame->entityOamOffsetY[i] << 8;
                    }

                    if (gCurrentPinballGame->entityActionIndex[i] == 10)
                        m4aSongNumStart(SE_UNKNOWN_0x140);

                }
                gCurrentPinballGame->entityMovePhase[i] = 2;

                break;
            case 8:
                if (gCurrentPinballGame->entityActionTimer[i] < 184)
                {
                    if (gCurrentPinballGame->entityActionTimer[i] < 160)
                    {
                        if (gCurrentPinballGame->entitySideChoice[i] == 0)
                            gCurrentPinballGame->entitySpawnPositions[i].x -= 0x10;
                        else
                            gCurrentPinballGame->entitySpawnPositions[i].x += 0x10;

                        if (gCurrentPinballGame->entityActionTimer[i] & 1)
                            gCurrentPinballGame->entitySpawnPositions[i].y -= 0x10;
                        else
                            gCurrentPinballGame->entitySpawnPositions[i].y -= 0x20;

                        if (gCurrentPinballGame->entityActionTimer[i] % 19 < 10)
                            gCurrentPinballGame->entityActionIndex[i] = 14;
                        else
                            gCurrentPinballGame->entityActionIndex[i] = 15;
                    }
                    else
                    {
                        if (gCurrentPinballGame->entitySideChoice[i] == 0)
                            gCurrentPinballGame->entitySpawnPositions[i].x += 0x140;
                        else
                            gCurrentPinballGame->entitySpawnPositions[i].x -= 0x140;

                        if (gCurrentPinballGame->entityActionTimer[i] & 1)
                            gCurrentPinballGame->entitySpawnPositions[i].y += 0x140;
                        else
                            gCurrentPinballGame->entitySpawnPositions[i].y += 0x1E0;

                        gCurrentPinballGame->entityActionIndex[i] = 15;
                    }

                    gCurrentPinballGame->entityActionTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->entityAIState[i] = 9;
                    gCurrentPinballGame->entityActionIndex[i] = 16;
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    if (gCurrentPinballGame->entitySideChoice[i] == 0)
                        gCurrentPinballGame->entitySpawnPositions[i].x += 0xF0;
                    else
                        gCurrentPinballGame->entitySpawnPositions[i].x -= 0xF0;
                }
                break;
            case 9:
                if (gUnknown_086AFB2C[gCurrentPinballGame->entityActionIndex[i]][1] > gCurrentPinballGame->entityActionTimer[i])
                {
                    gCurrentPinballGame->entityActionTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityActionIndex[i]++;
                    if (gCurrentPinballGame->entityActionIndex[i] == 20)
                    {
                        gCurrentPinballGame->entityActionIndex[i] = 0;
                        gCurrentPinballGame->entityAIState[i] = 0;
                    }

                    if (gCurrentPinballGame->entityActionIndex[i] == 17)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }
                break;
            case 10: {
                s16 len;
                if (gCurrentPinballGame->entitySideChoice[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                len = gUnknown_086AFAC0[var1].waypointCount;
                for (j = 0; j < len; j++)
                {
                    if (gUnknown_086AFAC0[var1].waypoints[j].y <= gCurrentPinballGame->entityScreenY[i])
                        break;
                }

                gCurrentPinballGame->entityPathWaypointIndex[i] = j;
                gCurrentPinballGame->entityAIState[i] = 11;
                gCurrentPinballGame->entityActionIndex[i] = 29;
                gCurrentPinballGame->entityActionTimer[i] = 0;

                gCurrentPinballGame->entitySpawnPositions[i].x = gUnknown_086AFAC0[var1].waypoints[gCurrentPinballGame->entityPathWaypointIndex[i]].x << 8;
                gCurrentPinballGame->entitySpawnPositions[i].y = gUnknown_086AFAC0[var1].waypoints[gCurrentPinballGame->entityPathWaypointIndex[i]].y << 8;

                gCurrentPinballGame->entityPathWaypointIndex[i]++;
                gCurrentPinballGame->entityMovePhase[i] = 0;
                break;
            }
            case 11:
                if (gCurrentPinballGame->entitySideChoice[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                var4 = gCurrentPinballGame->entityPathWaypointIndex[i];
                var5 = gUnknown_086AFAC0;
                if (var4 < var5[var1].waypointCount)
                {
                    gCurrentPinballGame->entitySpawnPositions[i].x = var5[var1].waypoints[gCurrentPinballGame->entityPathWaypointIndex[i]].x << 8;
                    gCurrentPinballGame->entitySpawnPositions[i].y = var5[var1].waypoints[gCurrentPinballGame->entityPathWaypointIndex[i]].y << 8;
                    gCurrentPinballGame->entityPathWaypointIndex[i]++;
                    if (gCurrentPinballGame->entityPathWaypointIndex[i] == var5[var1].waypointCount)
                    {
                        gCurrentPinballGame->entityAIState[i] = 12;
                        gCurrentPinballGame->sealBounceActiveSide[i] = gCurrentPinballGame->entitySideChoice[i];
                        gCurrentPinballGame->sealBounceAnimState[i] = 2;
                        if (gCurrentPinballGame->entitySideChoice[i] == 0)
                            gCurrentPinballGame->entityCollisionPos[i].x = 0x140;
                        else
                            gCurrentPinballGame->entityCollisionPos[i].x = -0x140;

                        gCurrentPinballGame->entityCollisionPos[i].y = 0x1D0;
                    }
                }

                gCurrentPinballGame->entityActionIndex[i] = ((gCurrentPinballGame->entityActionTimer[i] % 32) / 4) + 30;
                gCurrentPinballGame->entityActionTimer[i]++;
                gCurrentPinballGame->entityMovePhase[i] = 0;
                break;
            case 12:
                gCurrentPinballGame->entitySpawnPositions[i].x += gCurrentPinballGame->entityCollisionPos[i].x;
                gCurrentPinballGame->entitySpawnPositions[i].y += gCurrentPinballGame->entityCollisionPos[i].y;
                gCurrentPinballGame->entityActionIndex[i] = ((gCurrentPinballGame->entityActionTimer[i] % 32) / 4) + 30;
                gCurrentPinballGame->entityActionTimer[i]++;
                gCurrentPinballGame->entityMovePhase[i] = 0;
                break;
            case 13:
                gCurrentPinballGame->entitySpawnPositions[i].x += gCurrentPinballGame->entityCollisionPos[i].x;
                gCurrentPinballGame->entitySpawnPositions[i].y += gCurrentPinballGame->entityCollisionPos[i].y;
                gCurrentPinballGame->entityActionIndex[i] = ((gCurrentPinballGame->entityActionTimer[i] % 32) / 8) + 26;
                gCurrentPinballGame->entityActionTimer[i]++;
                gCurrentPinballGame->entityMovePhase[i] = 0;
                break;
            case 14:
                gCurrentPinballGame->entitySpawnLane[i] = -1;
                if (gCurrentPinballGame->entityHitCooldown[i] > 0)
                {
                    gCurrentPinballGame->entityHitCooldown[i]--;
                    gCurrentPinballGame->entityActionIndex[i] = 38;
                    gCurrentPinballGame->entityReturnedFlag[i] = 1;
                }
                else
                {
                    if (gCurrentPinballGame->entityActionTimer[i] < 334)
                    {
                        if (gCurrentPinballGame->entityActionTimer[i] < 16)
                        {
                            gCurrentPinballGame->entityActionIndex[i] = 21;
                            if (gCurrentPinballGame->entityActionTimer[i] == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x13E);

                            gCurrentPinballGame->entityMovePhase[i] = 3;
                        }
                        else if (gCurrentPinballGame->entityActionTimer[i] < 316)
                        {
                            if (gCurrentPinballGame->entityReturnedFlag[i] == 0)
                            {
                                gCurrentPinballGame->entitySpawnPositions[i].y += 0x40;
                                if (gCurrentPinballGame->entityActionTimer[i] % 19 < 10)
                                    gCurrentPinballGame->entityActionIndex[i] = 22;
                                else
                                    gCurrentPinballGame->entityActionIndex[i] = 23;
                            }
                            else
                            {
                                gCurrentPinballGame->entitySpawnPositions[i].y += 0x80;
                                if (gCurrentPinballGame->entityActionTimer[i] % 10 < 5)
                                    gCurrentPinballGame->entityActionIndex[i] = 22;
                                else
                                    gCurrentPinballGame->entityActionIndex[i] = 23;
                            }

                            if (gCurrentPinballGame->entitySpawnPositions[i].y > 0xAC00)
                                gCurrentPinballGame->entityActionTimer[i] = 316;

                            gCurrentPinballGame->entityMovePhase[i] = 3;
                        }
                        else
                        {
                            s16 var20;
                            gCurrentPinballGame->entitySpawnPositions[i].y += 0x30;
                            var20 = gCurrentPinballGame->entityActionTimer[i] - 316;
                            if (var20 < 10)
                                gCurrentPinballGame->entityActionIndex[i] = 24;
                            else
                                gCurrentPinballGame->entityActionIndex[i] = 25;

                            if (var20 == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x136);

                            gCurrentPinballGame->entityMovePhase[i] = 0;
                        }

                        gCurrentPinballGame->entityActionTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAIState[i] = 0;
                        gCurrentPinballGame->entityActionIndex[i] = 0;
                        gCurrentPinballGame->entityActionTimer[i] = 0;
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
            sp4 = gCurrentPinballGame->entitySpriteBaseFrame[i];
            gCurrentPinballGame->entitySpriteBaseFrame[i] = gUnknown_086AFB2C[gCurrentPinballGame->entityActionIndex[i]][2] + (1 - gCurrentPinballGame->entitySideChoice[i]) * 30 ;
            var2 = gUnknown_086AFB2C[gCurrentPinballGame->entityActionIndex[i]][0];

            group->baseX = (gCurrentPinballGame->entitySpawnPositions[i].x / 256) - (gCurrentPinballGame->bgScrollXCopy + 12);
            group->baseY = (gCurrentPinballGame->entitySpawnPositions[i].y / 256) - (gCurrentPinballGame->bgScrollYWithOffset + 14);

            DmaCopy16(3, gUnknown_084B046C[sp4], (void *)0x06011CA0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B56D8[var2][j];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                if (gCurrentPinballGame->entitySideChoice[i] == 0)
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->entityOamOffsetX[i] = -gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->entityOamOffsetY[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX + gCurrentPinballGame->entityOamOffsetX[i] * 2;
                }
                else
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->entityOamOffsetX[i] = gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->entityOamOffsetY[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                }

                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum += i * 9;
            }

            var3 = 0x10;
            gCurrentPinballGame->entityLogicPos[i].x = ((gCurrentPinballGame->entitySpawnPositions[i].x / 256) + (gCurrentPinballGame->entityOamOffsetX[i] - var3)) * 2;

            var3 = 0x12;
            gCurrentPinballGame->entityLogicPos[i].y = ((gCurrentPinballGame->entitySpawnPositions[i].y / 256) + (gCurrentPinballGame->entityOamOffsetY[i] - var3)) * 2;

            gCurrentPinballGame->entityScreenY[i] = gCurrentPinballGame->entitySpawnPositions[i].y / 256 + gCurrentPinballGame->entityOamOffsetY[i];

            group = &gMain.spriteGroups[16 + i];
            if (sp4 == 12 || sp4 == 42)
            {
                if (gCurrentPinballGame->entityActionIndex[i] == 11)
                    sp4 = 8;
                else
                    sp4 = 9;
            }
            else
            {
                sp4 = 0;
            }

            group->baseX = (gCurrentPinballGame->entitySpawnPositions[i].x / 256) - (gCurrentPinballGame->bgScrollXCopy + 12);
            group->baseY = (gCurrentPinballGame->entitySpawnPositions[i].y / 256) - (gCurrentPinballGame->bgScrollYWithOffset + 14);

            DmaCopy16(3, gUnknown_084B046C[sp4], (void *)0x06011EE0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void RenderIceBlockAndDeliverBall(void)
{
    s16 i;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = 0;
    group = &gMain.spriteGroups[18];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 86 - gCurrentPinballGame->bgScrollYWithOffset;
        if (gCurrentPinballGame->sealSplashTimer < 22)
            var0 = gUnknown_08137D60[gCurrentPinballGame->sealSplashTimer];

        DmaCopy16(3, gUnknown_084AF9EC[var0], (void *)0x06010920, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[11];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 94 - gCurrentPinballGame->bgScrollYWithOffset;
        DmaCopy16(3, gUnknown_084AFFEC[var0], (void *)0x06010B20, 0x180);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->boardState == 1)
        gMain.spriteGroups[11].available = 1;

    if (gCurrentPinballGame->boardState < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->sealSplashTimer)
    {
        if (gCurrentPinballGame->sealSplashTimer == 21)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_138);

        gCurrentPinballGame->sealSplashTimer--;
        if (gCurrentPinballGame->sealSplashTimer == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_139);
    }

    if (gCurrentPinballGame->sphealBallDeliveryActive)
    {
        if (gMain.currentField == FIELD_RUBY)
            SphealBoard_WhiscashDeliversBall();
        else
            SphealBoard_PelliperDeliversBall();
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
        offsets = gUnknown_086AFC16[gCurrentPinballGame->sealSplashAnimIndex];
        group->baseX = 134 + offsets[2] - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 154 + offsets[3] - gCurrentPinballGame->bgScrollYWithOffset;
        var0 = offsets[0];
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06012120, 0x460);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gUnknown_086AFC16[gCurrentPinballGame->sealSplashAnimIndex][1] > gCurrentPinballGame->sealSplashSubTimer)
    {
        gCurrentPinballGame->sealSplashSubTimer++;
    }
    else
    {
        gCurrentPinballGame->sealSplashSubTimer = 0;
        gCurrentPinballGame->sealSplashAnimIndex++;
        if (gCurrentPinballGame->sealSplashAnimIndex == 1)
            gMain.spriteGroups[19].available = 1;

        if (gCurrentPinballGame->sealSplashAnimIndex == 19)
        {
            gCurrentPinballGame->sealSplashAnimIndex = 18;
            gMain.spriteGroups[19].available = 0;
            gCurrentPinballGame->sphealBallDeliveryActive = 0;
        }

        if (gCurrentPinballGame->sealSplashAnimIndex == 9)
        {
            gCurrentPinballGame->ball->rotation -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8D00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC800;
            gCurrentPinballGame->ball->velocity.x = -0x60;
            gCurrentPinballGame->ball->velocity.y = 0x54;
            gCurrentPinballGame->ball->oamPriority = 3;
            PlayRumble(7);
        }

        if (gCurrentPinballGame->sealSplashAnimIndex == 2)
            m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);

        if (gCurrentPinballGame->sealSplashAnimIndex == 15)
            m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);

        if (gCurrentPinballGame->sealSplashAnimIndex == 8)
        {
            m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
            gCurrentPinballGame->ball->isGrabbed = 0;
            gCurrentPinballGame->ball->rotation -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8F00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC300;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        if (gCurrentPinballGame->sealSplashAnimIndex == 10)
            gCurrentPinballGame->ballLockState = 0;
    }
}

void SphealBoard_PelliperDeliversBall(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[20];
    if (group->available)
    {
        group->baseX = (gCurrentPinballGame->pelipperPosXQ10 / 10) - (gCurrentPinballGame->bgScrollXCopy - 146);
        group->baseY = (gCurrentPinballGame->pelipperPosYQ10 / 10) - (gCurrentPinballGame->bgScrollYWithOffset - 110) + (gCurrentPinballGame->pelipperBobOffsetY / 10);
        index = gCurrentPinballGame->sealSplashAnimIndex;
        DmaCopy16(3, gPelliper_Gfx[index], (void *)0x060125A0, 0x480);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->sealSplashSubTimer <= 250)
    {
        if (gCurrentPinballGame->sealSplashSubTimer == 250)
        {
            gCurrentPinballGame->pelipperPosXQ10 = 920;
            gCurrentPinballGame->pelipperPosYQ10 = -100;
            gCurrentPinballGame->pelipperVelX = -82;
            gCurrentPinballGame->pelipperVelY = 0;
            gCurrentPinballGame->entityMovementTimer = 0;
            gCurrentPinballGame->pelipperState = 8;
            gCurrentPinballGame->sealSplashAnimIndex = 13;
            gMain.spriteGroups[20].available = 1;
            gCurrentPinballGame->bossActive = 1;
        }
    }
    else
    {
        gCurrentPinballGame->sealSplashAnimIndex = (gCurrentPinballGame->entityMovementTimer % 24) / 6 + 13;
        gCurrentPinballGame->pelipperBobOffsetY = (Sin(gCurrentPinballGame->entityMovementTimer * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->entityMovementTimer == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->entityMovementTimer < 40)
        {
            gCurrentPinballGame->pelipperPosXQ10 += gCurrentPinballGame->pelipperVelX;
            gCurrentPinballGame->pelipperPosYQ10 += gCurrentPinballGame->pelipperVelY;
        }
        else
        {
            gMain.spriteGroups[20].available = 0;
        }

        if (gCurrentPinballGame->entityMovementTimer == 13)
        {
            gCurrentPinballGame->ball->isGrabbed = 0;
            gCurrentPinballGame->pelipperDropVelX = -10;
            gCurrentPinballGame->pelipperDropVelY = -25;
            gCurrentPinballGame->pelipperDropBallPosX = ((gCurrentPinballGame->pelipperPosXQ10 / 10) + 157) * 10;
            gCurrentPinballGame->pelipperDropBallPosY = ((gCurrentPinballGame->pelipperPosYQ10 / 10) + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->ballLockState)
        {
            if (gCurrentPinballGame->entityMovementTimer < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = (gCurrentPinballGame->pelipperPosXQ10 / 10) + 157;
                gCurrentPinballGame->ball->positionQ0.y = (gCurrentPinballGame->pelipperPosYQ10 / 10) + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->pelipperDropVelY += 2;
                gCurrentPinballGame->pelipperDropBallPosX += gCurrentPinballGame->pelipperDropVelX;
                gCurrentPinballGame->pelipperDropBallPosY += gCurrentPinballGame->pelipperDropVelY;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperDropBallPosX / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperDropBallPosY / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 181)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 181;
                    gCurrentPinballGame->ballLocked = 0;
                    gCurrentPinballGame->ballLockState = 0;
                    gCurrentPinballGame->ball->velocity.x = -10;
                    gCurrentPinballGame->ball->velocity.y = 0;
                    gCurrentPinballGame->bossActive = 0;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->collisionMapIndex = 0;
                    gCurrentPinballGame->sphealBallDeliveryActive = 0;
                    m4aSongNumStart(SE_UNKNOWN_0xE5);
                    PlayRumble(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        gCurrentPinballGame->entityMovementTimer++;
    }

    gCurrentPinballGame->sealSplashSubTimer++;
}

void ProcessSealBounceCollisions(void)
{
    s16 i;
    s16 var0;

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->sealBounceAnimState[i])
        {
        case 0:
            gCurrentPinballGame->sealBounceActiveSide[i] = 0;
            break;
        case 1:
            var0 = gCurrentPinballGame->sealBounceActiveSide[i];
            gCurrentPinballGame->minionState[var0] = 2;
            gCurrentPinballGame->minionStateTimer[var0] = 0;
            gCurrentPinballGame->minionFramesetIx[var0] = 7;
            if (gCurrentPinballGame->sealBounceInvulnTimer[i])
            {
                gCurrentPinballGame->sealBounceInvulnTimer[i]--;
                if (gCurrentPinballGame->sealBounceInvulnTimer[i] == 0)
                {
                    gCurrentPinballGame->sealBounceAnimState[i] = 0;
                    gCurrentPinballGame->minionState[var0] = 1;
                    gCurrentPinballGame->minionStateTimer[var0] = 0;
                    gCurrentPinballGame->minionFramesetIx[var0] = 4;
                }
            }
            break;
        case 2:
            var0 = gCurrentPinballGame->sealBounceActiveSide[i];
            if (i == 2)
            {
                gCurrentPinballGame->ballLockState = 1;
                gCurrentPinballGame->ball->velocity.x += 5 - var0 * 10;
            }

            gCurrentPinballGame->sealBounceAnimState[i] = 3;
            gCurrentPinballGame->sealBounceSubCount[i] = 0;
            gCurrentPinballGame->minionState[var0] = 2;
            gCurrentPinballGame->minionStateTimer[var0] = 0;
            gCurrentPinballGame->minionFramesetIx[var0] = 7;
            break;
        case 3:
            var0 = gCurrentPinballGame->sealBounceActiveSide[i];
            if (i < 2)
            {
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].x >= 0x5600)
                        gCurrentPinballGame->entityCollisionPos[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].x <= 0x9C00)
                        gCurrentPinballGame->entityCollisionPos[i].x = 0;

                }

                gCurrentPinballGame->entityCollisionPos[i].y += 12;
                if (gCurrentPinballGame->sealHitStunTimer[var0] > 0)
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->sealBounceSubCount[i] = 0;
                        gCurrentPinballGame->sealBounceAnimState[i] = 5;
                        gCurrentPinballGame->minionState[var0] = 3;
                        gCurrentPinballGame->minionFramesetIx[var0] = 15;
                        gCurrentPinballGame->minionStateTimer[var0] = 0;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->sealBounceSubCount[i]++;
                        MPlayStart(&gMPlayInfo_SE1, &se_unk_13d);
                        if (gCurrentPinballGame->sealBounceSubCount[i] < 3)
                        {
                            gCurrentPinballGame->entitySpawnPositions[i].y = 0x6600;
                            gCurrentPinballGame->entityCollisionPos[i].y = 0xFED4;
                            gCurrentPinballGame->entityAIState[i] = 13;
                            gCurrentPinballGame->minionState[var0] = 2;
                            gCurrentPinballGame->minionFramesetIx[var0] = 8;
                            gCurrentPinballGame->minionStateTimer[var0] = 12;
                        }
                        else
                        {
                            gCurrentPinballGame->entityCollisionPos[i].x = (30 - var0 * 60) * 4;
                            gCurrentPinballGame->entityCollisionPos[i].y = 0xFE70;
                            gCurrentPinballGame->sealBounceSubCount[i] = 0;
                            gCurrentPinballGame->sealBounceAnimState[i] = 4;
                            gCurrentPinballGame->minionState[var0] = 3;
                            gCurrentPinballGame->minionFramesetIx[var0] = 11;
                            gCurrentPinballGame->minionStateTimer[var0] = 0;
                            gCurrentPinballGame->sealSplashTimer = 100;
                            gCurrentPinballGame->sealBounceHitCount[0]++;
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
                    gCurrentPinballGame->sealBounceSubCount[i]++;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_13d);
                    PlayRumble(7);
                    if (gCurrentPinballGame->sealBounceSubCount[i] < 3)
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
                        gCurrentPinballGame->sealBounceSubCount[i] = 0;
                        gCurrentPinballGame->sealBounceAnimState[i] = 4;
                        gCurrentPinballGame->minionState[var0] = 3;
                        gCurrentPinballGame->minionFramesetIx[var0] = 11;
                        gCurrentPinballGame->minionStateTimer[var0] = 0;
                        gCurrentPinballGame->sealSplashTimer = 106;
                        gCurrentPinballGame->sealBounceHitCount[1]++;
                    }
                }
            }
            break;
        case 4:
            var0 = gCurrentPinballGame->sealBounceActiveSide[i];
            if (i < 2)
            {
                gCurrentPinballGame->entityCollisionPos[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].x >= 0x7800)
                        gCurrentPinballGame->entityCollisionPos[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].x <= 0x7800)
                        gCurrentPinballGame->entityCollisionPos[i].x = 0;
                }

                if (gCurrentPinballGame->entitySpawnPositions[i].y >= 0x8400)
                {
                    gCurrentPinballGame->sealBounceAnimState[i] = 0;
                    gCurrentPinballGame->entityAIState[i] = 14;
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityReturnedFlag[i] = 0;
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
                    gCurrentPinballGame->sealBounceSubCount[i]++;
                    if (gCurrentPinballGame->sealBounceSubCount[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8400;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                        if (gCurrentPinballGame->sealBounceSubCount[i] == 1)
                            PlayRumble(7);
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->ballLockState = 0;
                        gCurrentPinballGame->sealBounceAnimState[i] = 0;
                    }
                }
            }
            break;
        case 5:
            var0 = gCurrentPinballGame->sealBounceActiveSide[i];
            if (i < 2)
            {
                gCurrentPinballGame->entityCollisionPos[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].x >= 0x7800)
                        gCurrentPinballGame->entityCollisionPos[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->entitySpawnPositions[i].x <= 0x7800)
                        gCurrentPinballGame->entityCollisionPos[i].x = 0;
                }

                if (gCurrentPinballGame->entitySpawnPositions[i].y >= 0x8E00)
                {
                    gCurrentPinballGame->sealBounceAnimState[i] = 0;
                    gCurrentPinballGame->entityAIState[i] = 14;
                    gCurrentPinballGame->entityActionTimer[i] = 0;
                    gCurrentPinballGame->entityReturnedFlag[i] = 0;
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
                    gCurrentPinballGame->sealBounceSubCount[i]++;
                    if (gCurrentPinballGame->sealBounceSubCount[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8E00;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->ballLockState = 0;
                        gCurrentPinballGame->sealBounceAnimState[i] = 0;
                    }
                }
            }
            break;
        }
    }
}

void AnimateSphealWaterPalette(void)
{
    s16 i;
    s16 var0;

    var0 = gUnknown_086AEED6[(gMain.systemFrameCount % 96) / 24];
    for (i = 0x100; i < 0x400; i++)
        gBgScreenBuffer[0x800 + i] = gUnknown_0837A4E8[i] + var0 * 4;

    DmaCopy16(3, &gBgScreenBuffer[0x800], (void *)0x06000000, 0x800);
}

void RenderBonusResultsScreen(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int value;
    s16 sp0[12];
    s16 sp18[12];

    if (gCurrentPinballGame->boardState > 3)
    {
        if (gCurrentPinballGame->bonusScrollOffsetY > -126)
        {
            gCurrentPinballGame->bonusScrollOffsetY -= 6;
            gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->bonusScrollOffsetY + 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->bonusScrollOffsetY < 0)
        {
            gCurrentPinballGame->bonusScrollOffsetY += 6;
            if (gCurrentPinballGame->bonusScrollOffsetY > 0)
                gCurrentPinballGame->bonusScrollOffsetY = 0;
        }

        gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->bonusScrollOffsetY + 4;
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

    if (gCurrentPinballGame->sealStageProgressTimer > 100 && gCurrentPinballGame->sealStageProgressTimer < 450)
    {
        if (gCurrentPinballGame->sealBounceDisplayCount[0] != gCurrentPinballGame->sealBounceHitCount[0])
        {
            if ((gCurrentPinballGame->sealStageProgressTimer % 3) == 0)
            {
                gCurrentPinballGame->sealBounceDisplayCount[0]++;
                m4aSongNumStart(SE_UNKNOWN_0x91);
            }
        }
        else
        {
            gCurrentPinballGame->sealStageProgressTimer = 490;
        }
    }

    if (gCurrentPinballGame->sealStageProgressTimer > 500 && gCurrentPinballGame->sealStageProgressTimer < 800)
    {
        if (gCurrentPinballGame->sealBounceDisplayCount[1] != gCurrentPinballGame->sealBounceHitCount[1])
        {
            if ((gCurrentPinballGame->sealStageProgressTimer % 3) == 0)
            {
                gCurrentPinballGame->sealBounceDisplayCount[1]++;
                m4aSongNumStart(SE_UNKNOWN_0x91);
            }
        }
        else
        {
            gCurrentPinballGame->sealStageProgressTimer = 800;
        }
    }

    if (gCurrentPinballGame->sealStageProgressTimer < 800 && gCurrentPinballGame->stageTimer > 160)
        gCurrentPinballGame->stageTimer = 160;

    gCurrentPinballGame->sealStageProgressTimer++;

    group = &gMain.spriteGroups[7];
    if (!group->available)
        return;

    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bonusScrollOffsetY;
    for (i = 0; i < 22; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    value = gCurrentPinballGame->sealBounceDisplayCount[0] * 5000000;
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

    value = gCurrentPinballGame->sealBounceDisplayCount[0];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[8];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bonusScrollOffsetY;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->sealBounceDisplayCount[1] * 1000000;
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

    value = gCurrentPinballGame->sealBounceDisplayCount[1];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[9];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bonusScrollOffsetY;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->sealBounceDisplayCount[0] * 5000000
          + gCurrentPinballGame->sealBounceDisplayCount[1] * 1000000;
    gCurrentPinballGame->sealBonusScoreValue = value;
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
    group->baseY = 60 + gCurrentPinballGame->bonusScrollOffsetY;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }
}
