#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

#define BONUS_KECLEON_COMPLETE_POINTS 30000000

extern struct SpriteGroup gMain_spriteGroups_9;
extern struct SpriteGroup gMain_spriteGroups_31;

extern void UpdateKecleonStateMachine(void);
extern void RenderKecleonSprite(void);
extern void UpdateFallingItemProjectile(void);
extern void UpdateKecleonVisibilityTilemap(void);
extern void RenderKecleonBoardDecorations(void);
extern void DepthSortAndLoadSprites(void);

extern const struct SpriteSet *gUnknown_0202D880[];

struct KecleonWaypointNode
{
    u8 adjacentNodes[4];
    u16 position[2];
};
struct KecleonDepthLayer
{
    const struct SpriteSet *spriteSet;
    u8 depthThresholdY;
    u8 spriteSlotOffset;
};

extern const u8 gKecleonBonusClear_Gfx[];
extern const u16 gUnknown_08327994[];
extern const u8 gKecleonStageKecleon_Gfx[][0x280];
extern const u8 gKecleonStageKecleonFx_Gfx[][0x100];
extern struct SongHeader se_unk_fc;
extern struct SongHeader se_unk_fd;
extern struct SongHeader se_unk_fe;
extern struct SongHeader se_unk_ff;
extern struct SongHeader se_unk_100;
extern struct SongHeader se_unk_101;
extern struct SongHeader se_unk_102;
extern struct SongHeader se_unk_103;
extern const u16 gUnknown_086AE718[][3];
extern const s16 gUnknown_086AEA60[];
extern const u16 gUnknown_086AE9C4[];
extern const u16 gUnknown_086AE9D4[];
extern const struct KecleonWaypointNode gUnknown_086AE9E4[];
extern const struct Vector16 gUnknown_086AEA3C[];
extern const u16 *gUnknown_086AEA50[];
extern const s16 gUnknown_086AEA68[];
extern const struct KecleonDepthLayer gUnknown_086AEA70[];
extern const u16 gUnknown_086B9AB8[126][2][3];
extern const u16 gUnknown_086B9DAC[126][2][3];
extern const struct SpriteSet *gUnknown_086BB420[];

void KecleonBoardProcess_3A_35860(void)
{
    s16 i;

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->boardState = 0;
    gCurrentPinballGame->entityActivePhase = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 120 * 60; // 120 seconds
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->bossGrabbedBall = 0;
    gCurrentPinballGame->bonusCaptureState = 3;
    gCurrentPinballGame->bonusSequenceTimer = 0;
    gCurrentPinballGame->ball->isGrabbed = 1;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->kecleonSpriteVisible = 1;
    gCurrentPinballGame->entityState = 0;
    gCurrentPinballGame->entityPosXQ10 = 750;
    gCurrentPinballGame->entityPosYQ10 = 360;
    gCurrentPinballGame->entitySpriteFrame = 3;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->boardEntityCollisionMode = 0;
    gCurrentPinballGame->bonusScrollOffsetY = 0;
    gCurrentPinballGame->entityDirection = 0;
    gCurrentPinballGame->entityWalkCycleCount = 0;
    gCurrentPinballGame->entityAnimIndex = 0;
    gCurrentPinballGame->entityAnimTimer = 0;
    gCurrentPinballGame->kecleonWaypointIndex = 0;
    gCurrentPinballGame->kecleonHasAppeared = 0;
    gCurrentPinballGame->kecleonFacingRight = 0;
    gCurrentPinballGame->kecleonAttackFxSlot = 0;
    gCurrentPinballGame->kecleonBlendAlpha = 0;
    gCurrentPinballGame->kecleonAttackFxTimer = 0;
    gCurrentPinballGame->kecleonScopeDropActive = 0;
    gCurrentPinballGame->kecleonDropSlotIndex = 0;
    gCurrentPinballGame->kecleonScopeHitFlag = 0;
    gCurrentPinballGame->kecleonScopeAnimTimer = 0;
    gCurrentPinballGame->kecleonScopeDropTimer = 0;
    gCurrentPinballGame->kecleonBallHitFlashTimer = 0;
    gCurrentPinballGame->kecleonInvisBlend = 0;
    gCurrentPinballGame->kecleonTileAnimFrame = 0;
    gCurrentPinballGame->kecleonWallAnimFrame = 0;
    for (i = 0; i < 4; i++)
        gCurrentPinballGame->kecleonBumperHitTimers[i] = 0;

    for (i = 0; i < 10; i++)
        gCurrentPinballGame->hitFlashTimers[i] = 0;

    for (i = 0; i < 7; i++)
        gCurrentPinballGame->kecleonTargetHitTimers[i] = 0;

    gCurrentPinballGame->fieldEntryInProgress = 0;
    gCurrentPinballGame->kecleonScreenPos.y = gCurrentPinballGame->entityPosYQ10 / 10 + 58;
    DepthSortAndLoadSprites();
    gCurrentPinballGame->boardEntityCollisionMode = 1;
    UpdateKecleonStateMachine();
    RenderKecleonSprite();
    m4aSongNumStart(MUS_BONUS_FIELD_KECLEON);
    UpdateFallingItemProjectile();
    UpdateKecleonVisibilityTilemap();
    RenderKecleonBoardDecorations();
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void KecleonBoardProcess_3B_35AA4(void)
{
    DepthSortAndLoadSprites();
    switch (gCurrentPinballGame->boardState)
    {
    case 0:
        gCurrentPinballGame->ballLocked = 1;
        if (gCurrentPinballGame->stageTimer < 120)
        {
            gCurrentPinballGame->fieldScrollOffsetY = (gCurrentPinballGame->stageTimer / 5) + 0xFFE8;
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->fieldScrollOffsetY = 0;
            gCurrentPinballGame->boardState = 1;
            gCurrentPinballGame->stageTimer = 0;
        }

        if (gCurrentPinballGame->returnToMainBoardFlag == 0)
        {
            gMain.blendControl = 0x1C10;
            gMain.blendAlpha = BLDALPHA_BLEND(16, 0);
        }
        break;
    case 1:
        if (gCurrentPinballGame->returnToMainBoardFlag == 0)
        {
            if (gCurrentPinballGame->kecleonInvisBlend == 0)
            {
                u16 var0 = 16 - gCurrentPinballGame->kecleonBlendAlpha;
                u16 var1 = gCurrentPinballGame->kecleonBlendAlpha;
                gMain.blendControl = 0x1C10;
                gMain.blendAlpha = BLDALPHA_BLEND(var0, var1);
            }
            else
            {
                gMain.blendControl = 0x1C42;
                gMain.blendAlpha = BLDALPHA_BLEND(7, 9);
            }
        }
        break;
    case 2:
        if (gCurrentPinballGame->stageTimer < 10)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->boardState = 3;
            gCurrentPinballGame->stageTimer = 0;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[5].available = 1;
            DmaCopy16(3, gKecleonBonusClear_Gfx, (void *)0x6015800, 0x2000);
            gCurrentPinballGame->bonusScrollOffsetY = 0x88;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        }
        break;
    case 3:
        ProceessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = BONUS_KECLEON_COMPLETE_POINTS;
        }

        if (gCurrentPinballGame->stageTimer < 240)
        {
            if (gCurrentPinballGame->stageTimer == 20)
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_SUCCESS3);
            }

            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = 4;
            gCurrentPinballGame->numCompletedBonusStages++;
        }
        break;
    case 4:
        ProceessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        break;
    }

    UpdateKecleonStateMachine();
    RenderKecleonSprite();
    UpdateFallingItemProjectile();
    UpdateKecleonVisibilityTilemap();
    if (gCurrentPinballGame->entityActivePhase && gCurrentPinballGame->eventTimer < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL3);
        gCurrentPinballGame->kecleonScopeDropActive = 0;
        gCurrentPinballGame->kecleonScopeAnimTimer = 0;
        gCurrentPinballGame->kecleonScopeHitFlag = 0;
        gMain.modeChangeFlags |= MODE_CHANGE_EXPIRED_BONUS;
    }

    if (gCurrentPinballGame->returnToMainBoardFlag)
        FadeToMainBoard();

    BonusStage_HandleModeChangeFlags();
    RenderKecleonBoardDecorations();
}

void UpdateKecleonStateMachine(void)
{
    const u16 VECTORSCALEDOWN = 20000;
    int deltaX;
    int deltaY;
    struct Vector32 tempVec;
    struct Vector32 deltaVec;
    u16 angle;
    int xx, yy;
    int deltaMagSquared;

    switch (gCurrentPinballGame->entityState)
    {
    case 0:
        gCurrentPinballGame->entityState = 1;
        gCurrentPinballGame->entityAnimIndex = 3;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entityPosXQ10 = 750;
        gCurrentPinballGame->entityPosYQ10 = 360;
        gCurrentPinballGame->kecleonWaypointIndex = gUnknown_086AE9E4[10].adjacentNodes[(Random() * gMain.systemFrameCount) & 0x3];
        break;
    case 1:
        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            if (++gCurrentPinballGame->entityAnimIndex == 9)
                gCurrentPinballGame->entityAnimIndex = 3;
        }

        if (gCurrentPinballGame->entityPosXQ10 > 0)
        {
            gCurrentPinballGame->entityPosXQ10 -= 6;
        }
        else
        {
            gCurrentPinballGame->entityState = 2;
            gCurrentPinballGame->entityAnimIndex = 59;
            gCurrentPinballGame->entityAnimTimer = 0;
        }

        if (gCurrentPinballGame->bonusSequenceTimer > 2)
            gCurrentPinballGame->bonusSequenceTimer--;
        break;
    case 2:
        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            if (++gCurrentPinballGame->entityAnimIndex == 66)
            {
                gCurrentPinballGame->entityAnimIndex = 65;
                if (gCurrentPinballGame->kecleonInvisBlend < 8)
                {
                    gCurrentPinballGame->entityState = 3;
                }
                else
                {
                    int rand, mask;

                    if (gCurrentPinballGame->kecleonHasAppeared)
                    {
                        gCurrentPinballGame->entityAnimTimer = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimTimer = 0;
                        gCurrentPinballGame->kecleonHasAppeared = 1;
                    }

                    gCurrentPinballGame->entityState = 5;

                    rand = Random() + gMain.systemFrameCount;
                    mask = 0x3;
                    gCurrentPinballGame->kecleonWaypointIndex = gUnknown_086AE9E4[gCurrentPinballGame->kecleonWaypointIndex].adjacentNodes[rand & mask];
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 60 || gCurrentPinballGame->entityAnimIndex == 61)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_fc);
        }

        if (gCurrentPinballGame->entityAnimIndex == 64)
        {
            gCurrentPinballGame->kecleonBlendAlpha = gCurrentPinballGame->entityAnimTimer / 2;
            if (gCurrentPinballGame->entityAnimTimer == 4)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_fd);
        }
        break;
    case 3:
        gCurrentPinballGame->entityTargetPosX = gUnknown_086AE9E4[gCurrentPinballGame->kecleonWaypointIndex].position[0];
        gCurrentPinballGame->entityTargetPosY = gUnknown_086AE9E4[gCurrentPinballGame->kecleonWaypointIndex].position[1];
        deltaVec.x = gCurrentPinballGame->entityTargetPosX - gCurrentPinballGame->entityPosXQ10;
        deltaVec.y = gCurrentPinballGame->entityTargetPosY - gCurrentPinballGame->entityPosYQ10;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        gCurrentPinballGame->entityDirection = gUnknown_086AE9C4[angle / 0x2000];
        gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entityState = 4;
        break;
    case 4:
        deltaVec.x = gCurrentPinballGame->entityTargetPosX - gCurrentPinballGame->entityPosXQ10;
        deltaVec.y = gCurrentPinballGame->entityTargetPosY - gCurrentPinballGame->entityPosYQ10;
        xx = deltaVec.x * deltaVec.x;
        yy = deltaVec.y * deltaVec.y;
        deltaMagSquared = xx + yy;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        tempVec.x = 6 * Cos(angle) / VECTORSCALEDOWN;
        tempVec.y = -6 * Sin(angle) / VECTORSCALEDOWN;
        gCurrentPinballGame->entityPosXQ10 += tempVec.x;
        gCurrentPinballGame->entityPosYQ10 += tempVec.y;
        if (deltaMagSquared < 2500)
        {
            gCurrentPinballGame->entityState = 8;
            if (gCurrentPinballGame->entityDirection == 3)
            {
                gCurrentPinballGame->entityDirection = 66;
                gCurrentPinballGame->entityAnimIndex = 66;
            }
            else
            {
                gCurrentPinballGame->entityDirection = 69;
                gCurrentPinballGame->entityAnimIndex = 69;
            }

            gCurrentPinballGame->entityAnimTimer = 0;
        }

        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 6)
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection;
        }
        break;
    case 5:
        if (gCurrentPinballGame->entityAnimTimer < 18)
        {
            if (gCurrentPinballGame->entityAnimTimer == 0)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_fe);

            gCurrentPinballGame->entityAnimTimer++;
            if (gCurrentPinballGame->entityDirection == 66)
                gCurrentPinballGame->entityAnimIndex = 37;
            else
                gCurrentPinballGame->entityAnimIndex = 48;
        }
        else
        {
            gCurrentPinballGame->entityTargetPosX = gUnknown_086AE9E4[gCurrentPinballGame->kecleonWaypointIndex].position[0];
            gCurrentPinballGame->entityTargetPosY = gUnknown_086AE9E4[gCurrentPinballGame->kecleonWaypointIndex].position[1];
            deltaVec.x = gCurrentPinballGame->entityTargetPosX - gCurrentPinballGame->entityPosXQ10;
            deltaVec.y = gCurrentPinballGame->entityTargetPosY - gCurrentPinballGame->entityPosYQ10;
            angle = ArcTan2(deltaVec.x, -deltaVec.y);
            gCurrentPinballGame->entityDirection = gUnknown_086AE9D4[angle / 0x2000];
            gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection;
            gCurrentPinballGame->entityState = 6;
        }
        break;
    case 6:
        deltaVec.x = gCurrentPinballGame->entityTargetPosX - gCurrentPinballGame->entityPosXQ10;
        deltaVec.y = gCurrentPinballGame->entityTargetPosY - gCurrentPinballGame->entityPosYQ10;
        xx = deltaVec.x * deltaVec.x;
        yy = deltaVec.y * deltaVec.y;
        deltaMagSquared = xx + yy;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        tempVec.x = 10 * Cos(angle) / VECTORSCALEDOWN;
        tempVec.y = -10 * Sin(angle) / VECTORSCALEDOWN;
        gCurrentPinballGame->entityPosXQ10 += tempVec.x;
        gCurrentPinballGame->entityPosYQ10 += tempVec.y;
        if (deltaMagSquared < 2500)
        {
            if (gCurrentPinballGame->bonusModeHitCount > 9)
            {
                if (gCurrentPinballGame->entityDirection == 66)
                {
                    gCurrentPinballGame->entityDirection = 75;
                    gCurrentPinballGame->entityPosXQ10 += 240;
                }
                else
                {
                    gCurrentPinballGame->entityDirection = 95;
                    gCurrentPinballGame->entityPosXQ10 -= 240;
                }

                gCurrentPinballGame->entityState = 14;
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBlendAlpha < 16)
                {
                    gCurrentPinballGame->entityState = 2;
                    gCurrentPinballGame->entityAnimIndex = 62;
                    gCurrentPinballGame->entityAnimTimer = 0;
                }
                else
                {
                    gCurrentPinballGame->entityState = 7;
                    if (gCurrentPinballGame->entityDirection == 38)
                    {
                        gCurrentPinballGame->entityDirection = 42;
                        gCurrentPinballGame->entityAnimIndex = 42;
                    }
                    else
                    {
                        gCurrentPinballGame->entityDirection = 53;
                        gCurrentPinballGame->entityAnimIndex = 53;
                    }

                    gCurrentPinballGame->entityAnimTimer = 0;
                }
            }
        }

        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 4)
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection;

            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 1)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_ff);
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 3)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_ff);
        }
        break;
    case 7:
        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 6)
            {
                int rand, mask;

                if (gCurrentPinballGame->kecleonInvisBlend < 8)
                {
                    gCurrentPinballGame->entityState = 3;
                }
                else
                {
                    if (gCurrentPinballGame->kecleonHasAppeared)
                    {
                        gCurrentPinballGame->entityAnimTimer = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimTimer = 0;
                        gCurrentPinballGame->kecleonHasAppeared = 1;
                    }

                    gCurrentPinballGame->entityState = 5;
                }

                rand = Random() + gMain.systemFrameCount;
                mask = 0x3;
                gCurrentPinballGame->kecleonWaypointIndex = gUnknown_086AE9E4[gCurrentPinballGame->kecleonWaypointIndex].adjacentNodes[rand & mask];
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 5;
            }
        }
        break;
    case 8:
        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            int rand, mask;

            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 2)
            {
                if (gCurrentPinballGame->kecleonInvisBlend < 8)
                {
                    gCurrentPinballGame->entityState = 3;
                }
                else
                {
                    if (gCurrentPinballGame->kecleonHasAppeared)
                    {
                        gCurrentPinballGame->entityAnimTimer = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimTimer = 0;
                        gCurrentPinballGame->kecleonHasAppeared = 1;
                    }

                    gCurrentPinballGame->entityState = 5;
                }

                rand = Random() + gMain.systemFrameCount;
                mask = 0x3;
                gCurrentPinballGame->kecleonWaypointIndex = gUnknown_086AE9E4[gCurrentPinballGame->kecleonWaypointIndex].adjacentNodes[rand & mask];
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 1;
            }
        }
        break;
    case 9:
        gCurrentPinballGame->entityState = 10;
        if (gMain.systemFrameCount & 1)
        {
            if (gCurrentPinballGame->entityPosXQ10 < -640)
            {
                gCurrentPinballGame->kecleonFacingRight = 1;
                gCurrentPinballGame->entityDirection = 32;
            }
            else
            {
                gCurrentPinballGame->kecleonFacingRight = 0;
                gCurrentPinballGame->entityDirection = 27;
            }
        }
        else
        {
            if (gCurrentPinballGame->entityPosXQ10 > 640)
            {
                gCurrentPinballGame->kecleonFacingRight = 0;
                gCurrentPinballGame->entityDirection = 27;
            }
            else
            {
                gCurrentPinballGame->kecleonFacingRight = 1;
                gCurrentPinballGame->entityDirection = 32;
            }
        }

        if (gCurrentPinballGame->kecleonBlendAlpha < 16)
            gCurrentPinballGame->kecleonBlendAlpha = 0;

        gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection;
        gCurrentPinballGame->entityAnimTimer = 0;
        MPlayStart(&gMPlayInfo_SE1, &se_unk_100);
        break;
    case 10:
        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 1)
                gCurrentPinballGame->kecleonAttackFxTimer = 23;

            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 2)
            {
                gCurrentPinballGame->entityState = 13;
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 1;
            }
        }
        break;
    case 11:
        gCurrentPinballGame->entityState = 12;
        gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 2;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->kecleonBlendAlpha = 0;
        gCurrentPinballGame->scoreAddedInFrame = 500000;
        gCurrentPinballGame->bonusModeHitCount++;
        MPlayStart(&gMPlayInfo_SE1, &se_unk_101);
        PlayRumble(7);
        break;
    case 12:
        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 4)
            {
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 3;
                if (gCurrentPinballGame->bonusModeHitCount < 10)
                {
                    gCurrentPinballGame->entityState = 13;
                }
                else
                {
                    gCurrentPinballGame->entityActivePhase = 3;
                    gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
                    gCurrentPinballGame->bonusCaptureState = 2;
                    gCurrentPinballGame->bonusSequenceTimer = 0;
                    gCurrentPinballGame->entityState = 13;
                    gCurrentPinballGame->kecleonScopeDropActive = 0;
                    gCurrentPinballGame->kecleonScopeAnimTimer = 0;
                    gCurrentPinballGame->kecleonScopeHitFlag = 0;
                    gCurrentPinballGame->boardEntityCollisionMode = 0;
                }
            }
        }
        break;
    case 13:
        gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 4;
        if (gCurrentPinballGame->entityAnimTimer < 8)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            if (gCurrentPinballGame->bonusModeHitCount > 9)
            {
                if (gCurrentPinballGame->kecleonFacingRight == 0)
                {
                    gCurrentPinballGame->entityAnimIndex = 72;
                    gCurrentPinballGame->entityPosXQ10 -= 240;
                }
                else
                {
                    gCurrentPinballGame->entityAnimIndex = 73;
                    gCurrentPinballGame->entityPosXQ10 += 240;
                }

                gCurrentPinballGame->entityState = 5;
                gCurrentPinballGame->entityAnimTimer = 20;
                gCurrentPinballGame->kecleonWaypointIndex = 3 + ((Random() * gMain.systemFrameCount) & 0x3);
            }
            else
            {
                if (gCurrentPinballGame->kecleonBlendAlpha < 16)
                {
                    if (gCurrentPinballGame->kecleonFacingRight == 0)
                    {
                        gCurrentPinballGame->entityAnimIndex = 72;
                        gCurrentPinballGame->entityPosXQ10 -= 240;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimIndex = 73;
                        gCurrentPinballGame->entityPosXQ10 += 240;
                    }

                    gCurrentPinballGame->entityState = 5;
                    gCurrentPinballGame->entityAnimTimer = 20;
                    gCurrentPinballGame->kecleonWaypointIndex = 3 + ((Random() * gMain.systemFrameCount) & 0x3);
                }
                else
                {
                    if (gCurrentPinballGame->kecleonFacingRight == 0)
                    {
                        gCurrentPinballGame->entityAnimIndex = 72;
                        gCurrentPinballGame->entityPosXQ10 -= 240;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimIndex = 73;
                        gCurrentPinballGame->entityPosXQ10 += 240;
                    }

                    gCurrentPinballGame->entityAnimTimer = 0;
                    if (gCurrentPinballGame->kecleonInvisBlend < 8)
                    {
                        gCurrentPinballGame->entityState = 3;
                    }
                    else
                    {
                        if (gCurrentPinballGame->kecleonHasAppeared)
                        {
                            gCurrentPinballGame->entityAnimTimer = 20;
                        }
                        else
                        {
                            gCurrentPinballGame->entityAnimTimer = 0;
                            gCurrentPinballGame->kecleonHasAppeared = 1;
                        }

                        gCurrentPinballGame->entityState = 5;
                    }
                }
            }
        }
        break;
    case 14:
        gCurrentPinballGame->kecleonBlendAlpha = 0;
        if (gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 19)
            {
                gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 18;
                gCurrentPinballGame->entityState = 15;
            }

            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 6)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_102);

            if (gCurrentPinballGame->entityAnimIndex == gCurrentPinballGame->entityDirection + 8)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_103);
        }
        break;
    case 15:
        if (gCurrentPinballGame->entityAnimTimer < 100)
        {
            if (gCurrentPinballGame->entityAnimTimer == 0)
            {
                gCurrentPinballGame->boardState = 2;
                gCurrentPinballGame->stageTimer = 0;
            }

            gCurrentPinballGame->entityAnimTimer++;
        }

        gCurrentPinballGame->entityAnimIndex = gCurrentPinballGame->entityDirection + 15;
        break;
    }
}

void RenderKecleonSprite(void)
{
    s16 i;
    struct SpriteGroup *spriteGroup;
    s16 sp0;
    s16 sp4;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    int var0;
    int var1;
    int baseX = 104;
    int baseY = 28;

    spriteGroup = &gMain_spriteGroups[gSpriteSlotMap[23]];
    if (!spriteGroup->available)
        return;

    sp0 = gCurrentPinballGame->entitySpriteFrame;
    gCurrentPinballGame->entitySpriteFrame = gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][2];
    DmaCopy16(3, gKecleonStageKecleon_Gfx[sp0], (void *)0x6010920, 0x280);
    sp4 = gUnknown_086AE718[gCurrentPinballGame->entityAnimIndex][0];
    spriteGroup->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + baseX - gCurrentPinballGame->bgScrollXCopy;
    spriteGroup->baseY = gCurrentPinballGame->entityPosYQ10 / 10 + baseY - gCurrentPinballGame->bgScrollYWithOffset;
    if (gCurrentPinballGame->entityAnimIndex >= 28 && gCurrentPinballGame->entityAnimIndex < 31)
    {
        gCurrentPinballGame->entityCollisionOriginX = 2 * (gCurrentPinballGame->entityPosXQ10 / 10) + 144;
        gCurrentPinballGame->entityCollisionOriginY = 2 * (gCurrentPinballGame->entityPosYQ10 / 10) + 84;
        if (gCurrentPinballGame->bonusModeHitCount < 10)
            gCurrentPinballGame->boardEntityCollisionMode = 2;
    }
    else if (gCurrentPinballGame->entityAnimIndex >= 33 && gCurrentPinballGame->entityAnimIndex < 36)
    {
        gCurrentPinballGame->entityCollisionOriginX = 2 * (gCurrentPinballGame->entityPosXQ10 / 10) + 240;
        gCurrentPinballGame->entityCollisionOriginY = 2 * (gCurrentPinballGame->entityPosYQ10 / 10) + 84;
        if (gCurrentPinballGame->bonusModeHitCount < 10)
            gCurrentPinballGame->boardEntityCollisionMode = 2;
    }
    else
    {
        gCurrentPinballGame->entityCollisionOriginX = 2 * (gCurrentPinballGame->entityPosXQ10 / 10) + 208;
        gCurrentPinballGame->entityCollisionOriginY = 2 * (gCurrentPinballGame->entityPosYQ10 / 10) + 56;
        if (gCurrentPinballGame->bonusModeHitCount < 10)
            gCurrentPinballGame->boardEntityCollisionMode = 1;
    }

    gCurrentPinballGame->kecleonScreenPos.x = (gCurrentPinballGame->entityPosXQ10 / 10) + 120;
    gCurrentPinballGame->kecleonScreenPos.y = (gCurrentPinballGame->entityPosYQ10 / 10) + 58;
    if (gCurrentPinballGame->kecleonInvisBlend > 7)
        gCurrentPinballGame->kecleonSpriteVisible = 1;
    else if (gCurrentPinballGame->kecleonBlendAlpha > 15)
        gCurrentPinballGame->kecleonSpriteVisible = 0;
    else
        gCurrentPinballGame->kecleonSpriteVisible = 1;

    for (i = 0; i < 2; i++)
    {
        oamSimple = &spriteGroup->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B9DAC[sp4][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        if (gCurrentPinballGame->kecleonSpriteVisible)
        {
            gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
            gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            if (gCurrentPinballGame->entitySpriteFrame == 20) {
                if(gCurrentPinballGame->entityAnimTimer < 10)
                    gOamBuffer[oamSimple->oamId].paletteNum = 10;
                else
                    gOamBuffer[oamSimple->oamId].paletteNum = 2;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].paletteNum = 2;
            }
        }
        else
        {
            gOamBuffer[oamSimple->oamId].x = 240;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    baseX = 104;
    baseY = 60;
    spriteGroup = &gMain_spriteGroups_31;
    spriteGroup->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + baseX - gCurrentPinballGame->bgScrollXCopy;
    spriteGroup->baseY = gCurrentPinballGame->entityPosYQ10 / 10 + baseY - gCurrentPinballGame->bgScrollYWithOffset;

    for (i = 0; i < 2; i++)
    {
        oamSimple = &spriteGroup->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B9AB8[sp4][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        if (gCurrentPinballGame->kecleonSpriteVisible)
        {
            gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
            gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            if (sp0 == 20)
            {
                if (gCurrentPinballGame->entityAnimTimer < 10)
                    gOamBuffer[oamSimple->oamId].paletteNum = 11;
                else
                    gOamBuffer[oamSimple->oamId].paletteNum = 4;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].paletteNum = 4;
            }
        }
        else
        {
            gOamBuffer[oamSimple->oamId].x = 240;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    baseX = 104;
    baseY = 26;
    spriteGroup = &gMain_spriteGroups_9;
    var0 = gCurrentPinballGame->kecleonAttackFxSlot * 3;
    var1 = gCurrentPinballGame->kecleonAttackFxTimer / 8 - 2;

    DmaCopy16(3, gKecleonStageKecleonFx_Gfx[var0 - var1], (void *)0x6010BA0, 0x100);
    if (gCurrentPinballGame->kecleonAttackFxTimer > 0)
    {
        gCurrentPinballGame->kecleonAttackFxTimer--;
        spriteGroup->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + baseX - gCurrentPinballGame->bgScrollXCopy;
        spriteGroup->baseY = gCurrentPinballGame->entityPosYQ10 / 10 + - gCurrentPinballGame->bgScrollYWithOffset + baseY;
    }
    else
    {
        spriteGroup->baseX = 0;
        spriteGroup->baseY = 180;
    }

    oamSimple = &spriteGroup->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
    if (gCurrentPinballGame->kecleonFacingRight == 0)
        gOamBuffer[oamSimple->oamId].hFlip = 0;
    else
        gOamBuffer[oamSimple->oamId].hFlip = 1;
}


void UpdateFallingItemProjectile(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct Vector32 tempVector;
    int xx, yy;
    int squaredMagnitude;

    group = &gMain.spriteGroups[24];
    if (!group->available)
        return;

    if (gCurrentPinballGame->kecleonScopeDropActive)
    {
        if (gCurrentPinballGame->kecleonScopeDropTimer == 0)
        {
            gCurrentPinballGame->kecleonDropSlotIndex = (Random() * gMain.systemFrameCount) % 5;
            gCurrentPinballGame->scopeVelocity.y = 0;
            gCurrentPinballGame->scopePositionQ10.y = 0;
        }

        if (gCurrentPinballGame->kecleonScopeDropTimer < 40)
            gCurrentPinballGame->kecleonScopeDropTimer++;

        if (gCurrentPinballGame->kecleonScopeDropTimer == 20)
            m4aMPlayStop(&gMPlayInfo_SE2);

        if (gCurrentPinballGame->kecleonScopeDropTimer == 22)
            m4aSongNumStart(SE_KECLEON_SCOPE_FALL);

        if (gCurrentPinballGame->kecleonScopeDropTimer > 20)
        {
            gCurrentPinballGame->scopeVelocity.x = 4;
            gCurrentPinballGame->scopeVelocity.y += 3;
            gCurrentPinballGame->scopePositionQ10.x = gUnknown_086AEA3C[gCurrentPinballGame->kecleonDropSlotIndex].x;
            gCurrentPinballGame->scopePositionQ10.y += gCurrentPinballGame->scopeVelocity.y;
            if (gCurrentPinballGame->scopePositionQ10.y > gUnknown_086AEA3C[gCurrentPinballGame->kecleonDropSlotIndex].y)
            {
                gCurrentPinballGame->scopePositionQ10.y = gUnknown_086AEA3C[gCurrentPinballGame->kecleonDropSlotIndex].y;
                gCurrentPinballGame->scopeVelocity.y = -(gCurrentPinballGame->scopeVelocity.y / 6);
            }

            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->scopePositionQ10.x / 10 + 8);
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->scopePositionQ10.y / 10 + 8);
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (squaredMagnitude <= 120)
            {
                gCurrentPinballGame->kecleonScopeDropActive = 0;
                gCurrentPinballGame->kecleonScopeHitFlag = 1;
                gCurrentPinballGame->kecleonScopeAnimTimer = 0;
                gCurrentPinballGame->scoreAddedInFrame = 10000;
                m4aSongNumStart(SE_KECLEON_SCOPE_ACTIVATED);
            }

            group->baseX = -gCurrentPinballGame->bgScrollXCopy + gCurrentPinballGame->scopePositionQ10.x / 10;
            group->baseY = -gCurrentPinballGame->bgScrollYWithOffset + gCurrentPinballGame->scopePositionQ10.y / 10;
        }
        else
        {
            group->baseX = 0;
            group->baseY = 180;
        }
    }
    else
    {
        group->baseX = 0;
        group->baseY = 180;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
}


void UpdateKecleonVisibilityTilemap(void)
{
    s16 i, j;
    s16 var0;
    s16 var1;
    s16 var2;
    s16 index;
    s16 var3;
    const u16 *ptr;

    if (gCurrentPinballGame->kecleonScopeHitFlag)
    {
        if (gCurrentPinballGame->kecleonScopeAnimTimer < 600)
        {
            gCurrentPinballGame->kecleonScopeAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->kecleonScopeAnimTimer = 0;
            gCurrentPinballGame->kecleonScopeHitFlag = 0;
        }
    }

    if (gCurrentPinballGame->kecleonScopeHitFlag)
    {
        if (gCurrentPinballGame->kecleonInvisBlend < 10)
            gCurrentPinballGame->kecleonInvisBlend++;
    }
    else
    {
        if (gCurrentPinballGame->kecleonInvisBlend)
            gCurrentPinballGame->kecleonInvisBlend--;
        else
            gCurrentPinballGame->kecleonHasAppeared = 0;
    }

    gMain.blendScanlineAlpha = gCurrentPinballGame->kecleonInvisBlend * 16;
    var0 = gCurrentPinballGame->kecleonInvisBlend * 64;
    var1 = (20 - gCurrentPinballGame->kecleonInvisBlend * 2) * 32;
    index = (gCurrentPinballGame->kecleonScopeAnimTimer % 36) / 9;
    var3 = gUnknown_086AEA60[index];
    ptr = gUnknown_086AEA50[index];
    for (j = 0; j < var0; j++)
        gBgScreenBuffer[0x400 + j] = ptr[var1 + j];
    for (j = var0; j < 0x280; j++)
        gBgScreenBuffer[0x400 + j] = 0x3FF;

    index = gCurrentPinballGame->kecleonScopeAnimTimer % 150;
    if (index >= 10 && index < 80)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 4; j++)
            {
                gBgScreenBuffer[0x408 + ((i + 6) * 0x20) + j] = gUnknown_08327994[((i + 21) * 0x20) + (j + var3 * 4)];
            }
        }

        var2 = index / 10;
        if (var2 > 5)
            var2 = 5;

        for (j = 0; j < var2; j++)
        {
            gBgScreenBuffer[0x4C3 + j] = gUnknown_08327994[0x2EC + j];
        }
    }

    if (index >= 80 && index < 150)
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 6; j++)
            {
                gBgScreenBuffer[0x411 + ((i + 14) * 0x20) + j] = gUnknown_08327994[((i + 21) * 0x20) + (j + 0xC + var3 * 6)];
            }
        }

        var2 = (index - 70) / 10;
        if (var2 > 5)
            var2 = 5;

        for (j = 0; j < var2; j++)
        {
            gBgScreenBuffer[0x5F7 + j] = gUnknown_08327994[0x2EC + j];
        }
    }

    DmaCopy16(3, &gBgScreenBuffer[0x400], (void *)0x06001000, 0x500);
}

void RenderKecleonBoardDecorations(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct OamData *oamData;
    struct Vector16 tempVector;
    s16 var0;
    s16 var1;
    s16 var2;

    tempVector.x = gCurrentPinballGame->kecleonScreenPos.x * 2;
    tempVector.y = gCurrentPinballGame->kecleonScreenPos.y * 2;
    ProcessKecleonBoardCollisionFlash(&tempVector);

    group = &gMain.spriteGroups[gSpriteSlotMap[16]];
    group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;
    for (j = 0; j < 4; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[gSpriteSlotMap[17]];
    group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[7];
    var0 = 5 - gCurrentPinballGame->kecleonBallHitFlashTimer % 10;
    if (gCurrentPinballGame->kecleonBallHitFlashTimer > 30)
        var1 = 20;
    else if (gCurrentPinballGame->kecleonBallHitFlashTimer > 10)
        var1 = 10;
    else
        var1 = 5;

    if (gCurrentPinballGame->kecleonBallHitFlashTimer == 40)
    {
        m4aSongNumStart(SE_KECLEON_TREE_HIT);
        PlayRumble(7);
    }

    if (var0 < 0)
        var0 = -var0;

    group->baseX = (var1 * (5 - var0)) / 10 + 120u - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;
    for  (j = 0; j < 5; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->kecleonBallHitFlashTimer)
        gCurrentPinballGame->kecleonBallHitFlashTimer--;

    for (i = 0; i < 6; i++)
    {
        group = &gMain.spriteGroups[gSpriteSlotMap[10 + i]];
        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;
        var2 = 0;
        if (gCurrentPinballGame->hitFlashTimers[i])
        {
            var2 = gUnknown_086AEA68[(gCurrentPinballGame->hitFlashTimers[i] % 24) / 6];
            gCurrentPinballGame->hitFlashTimers[i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0xD2 + var2 * 12 + j * 8;
        }
    }

    for (i = 6; i < 10; i++)
    {
        group = &gMain.spriteGroups[gSpriteSlotMap[12 + i]];
        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;
        var2 = 0;
        if (gCurrentPinballGame->hitFlashTimers[i])
        {
            var2 = gUnknown_086AEA68[(gCurrentPinballGame->hitFlashTimers[i] % 24) / 6];
            gCurrentPinballGame->hitFlashTimers[i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0xD2 + var2 * 12 + j * 8;
        }
    }

    group = &gMain.spriteGroups[25];
    group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;
    var2 = 0;
    if (gCurrentPinballGame->kecleonBumperHitTimers[0])
    {
        var2 = gUnknown_086AEA68[(gCurrentPinballGame->kecleonBumperHitTimers[0] % 24) / 6];
        gCurrentPinballGame->kecleonBumperHitTimers[0]--;
    }

    for (j = 0; j < 3; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0xF6 + var2 * 8 + (j * 4 - (j / 2) * 2);
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[26 + i];
        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;

        var2 = 0;
        if (gCurrentPinballGame->kecleonBumperHitTimers[1 + i])
        {
            var2 = gUnknown_086AEA68[(gCurrentPinballGame->kecleonBumperHitTimers[1 + i] % 24) / 6];
            gCurrentPinballGame->kecleonBumperHitTimers[1 + i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0x10E + var2 * 12 + j * 8;
        }
    }

    group = &gMain.spriteGroups[28];
    group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = -gCurrentPinballGame->bgScrollYWithOffset - 128;
    var2 = 0;
    if (gCurrentPinballGame->kecleonBumperHitTimers[3])
    {
        var2 = gUnknown_086AEA68[(gCurrentPinballGame->kecleonBumperHitTimers[3] % 24) / 6];
        gCurrentPinballGame->kecleonBumperHitTimers[3]--;
    }

    for (j = 0; j < 2; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x132 + var2 * 12 + j * 8;
    }

    group = &gMain.spriteGroups[32];
    group->baseX = gCurrentPinballGame->ball->screenPosition.x;
    group->baseY = gCurrentPinballGame->ball->screenPosition.y + 14;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    if (gCurrentPinballGame->ball->isGrabbed)
        gOamBuffer[oamSimple->oamId].y = 200;
    else
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[29];
    if (gCurrentPinballGame->kecleonTileAnimFrame < 12)
        gCurrentPinballGame->kecleonTileAnimFrame++;
    else
        gCurrentPinballGame->kecleonTileAnimFrame = 0;

    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->kecleonTargetHitTimers[i])
        {
            var2 = 2 - gCurrentPinballGame->kecleonTargetHitTimers[i] / 4;
            gCurrentPinballGame->kecleonTargetHitTimers[i]--;
            group->baseX = gCurrentPinballGame->ballTrailPositions[i].x - gCurrentPinballGame->cameraScrollX + 4;
            group->baseY = gCurrentPinballGame->ballTrailPositions[i].y - gCurrentPinballGame->cameraScrollY- gCurrentPinballGame->scrollNudgeY - gCurrentPinballGame->fieldScrollOffsetY + 4;
        }
        else
        {
            group->baseX = 240;
            group->baseY = 180;
        }

        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x16E + var2;
    }

    group = &gMain.spriteGroups[30];
    if (gCurrentPinballGame->kecleonWallAnimFrame < 24)
        gCurrentPinballGame->kecleonWallAnimFrame++;
    else
        gCurrentPinballGame->kecleonWallAnimFrame = 0;

    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->kecleonTargetHitTimers[4 + i])
        {
            var2 = 2 - gCurrentPinballGame->kecleonTargetHitTimers[4 + i] / 6;
            gCurrentPinballGame->kecleonTargetHitTimers[4 + i]--;
            group->baseX = gCurrentPinballGame->kecleonPrevBallHitPos[i].x - gCurrentPinballGame->bgScrollXCopy - 4;
            group->baseY = gCurrentPinballGame->kecleonPrevBallHitPos[i].y - gCurrentPinballGame->bgScrollYWithOffset + 2;
        }
        else
        {
            group->baseX = 240;
            group->baseY = 180;
        }

        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x16E + var2;
    }
}

void DepthSortAndLoadSprites(void)
{
    s16 i, j;
    struct KecleonDepthLayer sp0[14];

    for (i = 0; i < 33; i++)
        gUnknown_0202D880[i] = gUnknown_086BB420[i];

    sp0[12] = gUnknown_086AEA70[12];
    sp0[12].depthThresholdY = gCurrentPinballGame->ball->positionQ0.y;
    for (i = 0; i < 12; i++)
    {
        if (gUnknown_086AEA70[i].depthThresholdY < gCurrentPinballGame->ball->positionQ0.y)
        {
            for (j = 11; j >= i; j--)
                sp0[j + 1] = gUnknown_086AEA70[j];

            sp0[i] = gUnknown_086AEA70[12];
            sp0[i].depthThresholdY = gCurrentPinballGame->ball->positionQ0.y;
            break;
        }
        else
        {
            sp0[i] = gUnknown_086AEA70[i];
        }
    }

    sp0[13] = gUnknown_086AEA70[13];
    for (i = 0; i < 13; i++)
    {
        if (sp0[i].depthThresholdY < gCurrentPinballGame->kecleonScreenPos.y)
        {
            for (j = 12; j >= i; j--)
                sp0[j + 1] = sp0[j];

            sp0[i] = gUnknown_086AEA70[13];
            sp0[i].depthThresholdY = gCurrentPinballGame->kecleonScreenPos.y;
            break;
        }
    }

    for (i = 0; i < 14; i++)
    {
        gSpriteSlotMap[sp0[i].spriteSlotOffset + 10] = i + 10;
        gUnknown_0202D880[i + 10] = sp0[i].spriteSet;
    }

    LoadSpriteSets(gUnknown_0202D880, 33, gMain.spriteGroups);
}
