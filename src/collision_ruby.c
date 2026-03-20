#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const u16 gRubyAltEntity0CollisionMap[];
extern const u16 gRubyAltEntity1CollisionMap[];
extern const u16 gWhiscashCollisionMap[];

extern struct SongHeader se_unk_99;

s16 CollisionCheck_Ruby(struct Vector16 *arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinAcceleration = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    tileMapPage = vec1.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    vec1.y %= 64;

    collisionTileIndex = gBoardConfig.fieldLayout.collisionTileMap[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collisionAngleMap[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collisionTypeMap[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckRubyPondBumperCollision(arg0, &sp00, &sp02);

    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum-1) {
    case 0:
    case 3:
    case 5:
        gCurrentPinballGame->collisionSurfaceType = (switch_enum - 1);
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp00;

        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballSpawnX - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
            {

                if (gCurrentPinballGame->ball->spinSpeed > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spinSpeed != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinAcceleration = 0x28;
                        gCurrentPinballGame->ball->spinSpeed = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinAcceleration = 0xFFD8;
                        gCurrentPinballGame->ball->spinSpeed = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 1:
    case 2:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;

        break;
    case 4:
        gCurrentPinballGame->whiscashState = WHISCASH_STATE_ABSORB_ZONE_HIT;
        gCurrentPinballGame->ballFrozenState = 1;
        some_enum = 0;
        break;
    }
    ProcessRubyCollisionEvent((s32) some_enum, &return_val, arg1);

    return return_val;
}


void CheckRubyPondBumperCollision(struct Vector16* arg0, u16* arg1, u8* arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    s32 ix;

    maskedResult = 0;
    lowerNibble = 0;
    ix = 0;

    if (gCurrentPinballGame->ballInLowerHalf == 0)
    {
        if (gCurrentPinballGame->boardLayerDepth != 0)
            return;

        if (gCurrentPinballGame->shouldProcessWhiscash)
        {
            if (gCurrentPinballGame->whiscashInvulnerable == 0)
                return;

            deltaX = arg0->x + gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
            deltaY = arg0->y + gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

            if (deltaX > 79U)
                return;

            if (deltaY > 87U)
                return;

            maskedResult = 0xFFF0 & gWhiscashCollisionMap[(deltaY * 80) + deltaX];
            lowerNibble = 0xF & gWhiscashCollisionMap[(deltaY * 80) + deltaX];

            if (lowerNibble == 0)
                return;

            *arg1 = maskedResult;

            // if hit, while in its base mode, processes as a hit.
            // A Ball in the area being sucked in, or already hitting it won't affect it.
            if (gCurrentPinballGame->whiscashState <= WHISCASH_STATE_SITTING)
            {
                *arg2 = lowerNibble;
                gCurrentPinballGame->whiscashState = WHISCASH_STATE_HIT;
                return;
            }

            *arg2 = 1;
            return;
        }

        if (0xF & *arg2)
            return;

        deltaX = arg0->x + (u16) gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
        deltaY = arg0->y + (u16) gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

        if (deltaX <= 63U && deltaY <= 63U)
        {
            maskedResult = 0xFFF0 & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
            lowerNibble = 0xF & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];

            if (lowerNibble != 0)
                ix = 0;
        }

        if (lowerNibble == 0)
        {
            deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[1].x + arg0->x;
            deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[1].y + arg0->y;

            if (deltaX <= 63U && deltaY <= 63U)
            {
                maskedResult = 0xFFF0 & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
                lowerNibble = 0xF & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
                if (lowerNibble != 0)
                    ix = 1;
            }

            if (lowerNibble == 0)
            {
                deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[2].x + arg0->x;
                deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[2].y + arg0->y;

                if (deltaX <= 63U && deltaY <= 63U)
                {
                    maskedResult = 0xFFF0 & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
                    lowerNibble = 0xF & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];

                    if (lowerNibble == 0)
                        return;

                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }

        if (!gCurrentPinballGame->rubyPondContentsChanging)
            gCurrentPinballGame->pondBumperStates[ix] = 107;

        *arg1 = maskedResult;
        *arg2 = lowerNibble;

        if (gCurrentPinballGame->bumperHitCountdown > 0)
            return;

        gCurrentPinballGame->bumperHitCountdown = 2;
    }
    else
    {
        if ((*arg2 & 0xF) == 0)
        {
            if (gCurrentPinballGame->sideBumperAnimPhase[0] > 0)
            {
                s16 deltaY_alt;
                deltaX = 2 * (-24 -gCurrentPinballGame->sideBumperShakeOffset[0]) + arg0->x;
                deltaY_alt = arg0->y -580;

                if (deltaX <= 71U && deltaY_alt <= 71U)
                {
                    *arg1 = 0xFFF0 & gRubyAltEntity0CollisionMap[(deltaY_alt * 72) + deltaX];
                    *arg2 = 0xF & gRubyAltEntity0CollisionMap[(deltaY_alt * 72) + deltaX];

                    if (*arg2 & 1)
                    {
                        gCurrentPinballGame->sideBumperHitFlag = 1;
                        *arg2 = 6;
                    }
                }
            }

            if (gCurrentPinballGame->sideBumperAnimPhase[1] > 0)
            {
                deltaX = ((gCurrentPinballGame->sideBumperShakeOffset[1] - 180) * 2) + arg0->x;
                deltaY = arg0->y -580;

                if (deltaX <= 71U && deltaY <= 71U)
                {
                    *arg1 = 0xFFF0 & gRubyAltEntity1CollisionMap[(deltaY * 72) + deltaX];
                    *arg2 = 0xF & gRubyAltEntity1CollisionMap[(deltaY * 72) + deltaX];

                    if (*arg2 & 1)
                    {
                        gCurrentPinballGame->sideBumperHitFlag = 2;
                        *arg2 = 6;
                        return;
                    }
                }
            }
        }
    }
}

void ProcessRubyCollisionEvent(s32 arg0, s16* arg1, u16* arg2)
{
    s16 absVelY;

    switch ((u8)arg0 - 1)
    {
    case 0:
        if (gCurrentPinballGame->collisionCooldownTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ1.x > 359)
            {
                if (gCurrentPinballGame->ball->positionQ1.y > 199)
                    gCurrentPinballGame->ballCatchState = 1;
                else
                    gCurrentPinballGame->ballCatchState = 3;
            }
            else
                gCurrentPinballGame->ballCatchState= 2;

            DispatchRubyCatchModeInit();
            gCurrentPinballGame->collisionResponseType = 7;
            *arg1 = 1;
            return;
        }
    default:
        return;
    case 1:
        if (gCurrentPinballGame->boardLayerDepth == 0)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->boardLayerDepth = 2;
            break;
        }

        if (gCurrentPinballGame->boardLayerDepth == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->boardLayerDepth = 3;
        }

        break;
    case 2:
        if (gCurrentPinballGame->boardLayerDepth == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 3;
            gCurrentPinballGame->boardLayerDepth = 0;
        }
        else if (gCurrentPinballGame->boardLayerDepth == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->boardLayerDepth = 2;
        }

        if (gCurrentPinballGame->nuzleafAnimState == 6)
            gCurrentPinballGame->nuzleafAnimState = 7;

        if (gCurrentPinballGame->shopDoorTargetFrame & 0xF0 )
            gCurrentPinballGame->shopDoorTargetFrame = 0;

        if (gCurrentPinballGame->shopDoorOpenLevel & 0xF0)
            gCurrentPinballGame->shopDoorOpenLevel = 0;

        break;
    case 3:
        if (gCurrentPinballGame->mainBoardCountdownTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 131)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;

                if (gCurrentPinballGame->progressLevel <= 98)
                    gCurrentPinballGame->progressLevel++;
            }
            else if (gCurrentPinballGame->ball->positionQ0.x > 91)
            {
                gCurrentPinballGame->scoreAddedInFrame = 2000;
                gCurrentPinballGame->rubyPondChangeTimer = 0;
                gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            }
            else
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;

                if (gCurrentPinballGame->chikoritaFlashActive == 0)
                {
                    gCurrentPinballGame->chikoritaFlashActive = 1;
                    gCurrentPinballGame->chikoritaFlashTimer = 0;
                }
            }
            gCurrentPinballGame->mainBoardCountdownTimer = 45;

            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
        }
        break;
    case 4:
        gCurrentPinballGame->ballInLaunchChute = 1;
        gCurrentPinballGame->ballTouchingSpoink = 1;
        gCurrentPinballGame->ballCollisionZone = 0;
        return;
    case 5:
        if (gCurrentPinballGame->ballInLowerHalf == 0)
        {
            SetBoardCollisionConfig(1);
            gCurrentPinballGame->boardCollisionConfigChanged = 1;
        }
        break;
    case 6:
        if (gCurrentPinballGame->ball->positionQ0.x < 50)
        {
            if (gCurrentPinballGame->nuzleafHitFlag == 0)
            {
                gCurrentPinballGame->nuzleafHitFlag = 1;
                gCurrentPinballGame->nuzleafAnimState = 1;
                gCurrentPinballGame->collisionSurfaceType = 0;
                gCurrentPinballGame->collisionResponseType = 2;
                *arg2 = 0xB000;
                *arg1 = 1;
            }
        }
        else if (gCurrentPinballGame->nuzleafHitFlag == 1)
        {
            gCurrentPinballGame->nuzleafHitFlag = 2;
            gCurrentPinballGame->nuzleafAnimState = 3;
            gCurrentPinballGame->collisionSurfaceType = 0;
            gCurrentPinballGame->collisionResponseType = 2;
            *arg2 = 0xA000;
            *arg1 = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;

            memcpy(&gCurrentPinballGame->ballStates[1], gCurrentPinballGame->ballStates, 0x44U);

            gCurrentPinballGame->secondaryBall = &gCurrentPinballGame->ballStates[1];
            gCurrentPinballGame->ballLaunchTimer = 120;
        }

        gCurrentPinballGame->ballCollisionZone = 14;
        return;
    case 7:
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            if (gCurrentPinballGame->ballCollisionZone == 8)
            {
                if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->evoArrowProgress <= 2)
                {
                    if (gCurrentPinballGame->evoArrowProgress == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->evoArrowProgress == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->evoArrowProgress++;

                    m4aSongNumStart(SE_UNKNOWN_0x99);
                }

                gCurrentPinballGame->travelRouletteSlotHitType = 1;
            }
            gCurrentPinballGame->ballCollisionZone = 2;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            if (gCurrentPinballGame->ballCollisionZone == 7)
            {
                gCurrentPinballGame->coinRewardAmount = 10;

                if(gCurrentPinballGame->coinRewardLevel <= 2)
                {
                    if(gCurrentPinballGame->coinRewardLevel == 0)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                        gCurrentPinballGame->coinRewardAmount = 1;
                    }
                    else if(gCurrentPinballGame->coinRewardLevel == 1)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                        gCurrentPinballGame->coinRewardAmount = 5;
                    }
                    else
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 10000;
                        gCurrentPinballGame->coinRewardAmount = 10;
                    }
                    gCurrentPinballGame->coinRewardLevel++;
                }

                gCurrentPinballGame->coinRewardTimer = 0;
                gCurrentPinballGame->coinRewardLevelTimer = 0;
            }

            gCurrentPinballGame->ballCollisionZone = 1;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 126)
        {
            if (gCurrentPinballGame->ballPowerUpLight[0] == 0)
                gCurrentPinballGame->scoreAddedInFrame = 1000;

            gCurrentPinballGame->ballPowerUpLight[0] = 1;
            gCurrentPinballGame->ballCollisionZone = 3;

            if (gCurrentPinballGame->ballPowerUpAnimActive == 0)
            {
                if (!(gCurrentPinballGame->ballPowerUpLight[1] &
                      gCurrentPinballGame->ballPowerUpLight[2]))
                    return;

                gCurrentPinballGame->ballPowerUpAnimActive = 1;
                gCurrentPinballGame->ballShadowTimer = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }
        }
        else
        {
            if (gCurrentPinballGame->ball->positionQ0.x <= 148)
            {
                if (gCurrentPinballGame->ballPowerUpLight[1] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;

                gCurrentPinballGame->ballPowerUpLight[1] = 1;
                gCurrentPinballGame->ballCollisionZone = 4;

                if (gCurrentPinballGame->ballPowerUpAnimActive != 0)
                    return;

                if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                      gCurrentPinballGame->ballPowerUpLight[2]))
                    return;

                gCurrentPinballGame->ballPowerUpAnimActive = 1;
                gCurrentPinballGame->ballShadowTimer = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }

            if (gCurrentPinballGame->ball->positionQ0.x <= 172)
            {
                if (gCurrentPinballGame->ballPowerUpLight[2] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;

                gCurrentPinballGame->ballPowerUpLight[2] = 1;
                gCurrentPinballGame->ballCollisionZone = 5;

                if (gCurrentPinballGame->ballPowerUpAnimActive != 0)
                    return;

                if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                      gCurrentPinballGame->ballPowerUpLight[1]))
                    return;

                gCurrentPinballGame->ballPowerUpAnimActive = 1;
                gCurrentPinballGame->ballShadowTimer = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }

            if (gCurrentPinballGame->ballCollisionZone == 9)
            {
                if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->catchArrowProgress <= 2)
                {
                    if (gCurrentPinballGame->catchArrowProgress == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->catchArrowProgress == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->catchArrowProgress++;

                    MPlayStart(&gMPlayInfo_SE1, &se_unk_99);

                    if (gCurrentPinballGame->catchArrowProgress > 1)
                        gCurrentPinballGame->catchProgressFlashing = 1;
                }

                gCurrentPinballGame->travelRouletteSlotHitType = 2;
            }

            gCurrentPinballGame->ballCollisionZone = 6;
            return;
        }
        break;
    case 8:
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            gCurrentPinballGame->ballCollisionZone = 8;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            gCurrentPinballGame->ballCollisionZone = 7;
            return;
        }

        gCurrentPinballGame->ballCollisionZone = 9;
        return;
    case 9:
        if (gCurrentPinballGame->ball->positionQ0.x <= 46)
        {
            gCurrentPinballGame->ballCollisionZone = 10;

            if (gCurrentPinballGame->holeIndicators[0] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[0] = 1;

            if (gCurrentPinballGame->allHolesLit != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesLit = 1;
            gCurrentPinballGame->allHolesLitBlinkTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 120)
        {
            gCurrentPinballGame->ballCollisionZone = 11;

            if (gCurrentPinballGame->holeIndicators[1] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[1] = 1;

            if (gCurrentPinballGame->allHolesLit != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesLit = 1;
            gCurrentPinballGame->allHolesLitBlinkTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 193)
        {
            gCurrentPinballGame->ballCollisionZone = 12;

            if (gCurrentPinballGame->holeIndicators[2] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[2] = 1;

            if (gCurrentPinballGame->allHolesLit != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesLit = 1;
            gCurrentPinballGame->allHolesLitBlinkTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        gCurrentPinballGame->ballCollisionZone = 13;

        if (gCurrentPinballGame->holeIndicators[3] != 0)
            return;

        gCurrentPinballGame->scoreAddedInFrame = 1000;
        gCurrentPinballGame->holeIndicators[3] = 1;

        if (gCurrentPinballGame->allHolesLit != 0)
            return;

        if (!(gCurrentPinballGame->holeIndicators[0] &
              gCurrentPinballGame->holeIndicators[1] &
              gCurrentPinballGame->holeIndicators[2]))
            return;

        gCurrentPinballGame->allHolesLit = 1;
        gCurrentPinballGame->allHolesLitBlinkTimer = 126;
        gCurrentPinballGame->scoreAddedInFrame = 4000;
        return;
    case 10:
        if (gCurrentPinballGame->ballInLowerHalf == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 170)
            {
                if (gCurrentPinballGame->shopDoorTargetFrame > 2U)
                    return;

                gCurrentPinballGame->collisionSurfaceType = 0;
                gCurrentPinballGame->collisionResponseType = 2;
                *arg2 = 0xB000;
                *arg1 = 1;

                if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->shopDoorOpenLevel <= 2)
                {
                    gCurrentPinballGame->shopDoorOpenLevel = 3;
                    gCurrentPinballGame->shopDoorAnimDelay = 5;
                }

                gCurrentPinballGame->scoreAddedInFrame = 50000;
                return;
            }

            if (gCurrentPinballGame->nuzleafAnimState <= 4)
            {
                gCurrentPinballGame->collisionSurfaceType = 0;
                gCurrentPinballGame->collisionResponseType = 2;
                *arg2 = 0xF800;
                *arg1 = 1;
            }

            if (gCurrentPinballGame->nuzleafAnimState == 5)
                gCurrentPinballGame->nuzleafAnimState = 6;

            if (gCurrentPinballGame->rampPrizeType == 0)
                return;

            if (gCurrentPinballGame->rampPrizeType == 1)
                gCurrentPinballGame->oneUpAnimTimer = 90;
            else
            {
                gCurrentPinballGame->ballPowerUpOverride = 1;
                gCurrentPinballGame->ballPowerUpAnimActive = 1;
                gCurrentPinballGame->ballShadowTimer = 60;
                m4aSongNumStart(SE_UNKNOWN_0xD8);
            }

            gCurrentPinballGame->rampPrizeType = 0;
            gCurrentPinballGame->rampPrizeRespawnTimer = 600;
            return;
        }

        if (gCurrentPinballGame->pikaKickbackTimer != 0)
            return;

        if (gCurrentPinballGame->ball->positionQ0.x <= 120)
            gCurrentPinballGame->outLaneSide = 1;
        else
            gCurrentPinballGame->outLaneSide = 2;

        if (gCurrentPinballGame->outLanePikaPosition <= 1)
        {
            if (gCurrentPinballGame->outLanePikaPosition != gCurrentPinballGame->outLaneSide - 1)
                return;
            else
                gCurrentPinballGame->pikaKickbackTimer = 120;
            return;
        }

        gCurrentPinballGame->pikaKickbackTimer = 120;
        return;

    case 11:
        if (gCurrentPinballGame->pikaSpinCooldownTimer != 0)
            return;

        absVelY = gCurrentPinballGame->ball->velocity.y;
        gCurrentPinballGame->pikaSpinMomentum = gCurrentPinballGame->ball->velocity.y;

        if (absVelY < 0) {
            absVelY = -absVelY;
        }

        gCurrentPinballGame->pikaChargeTarget += (absVelY) / 3;

        if (gCurrentPinballGame->pikaChargeTarget > 168)
            gCurrentPinballGame->pikaChargeTarget = 168;

        gCurrentPinballGame->pikaSpinCooldownTimer = 20;
        return;
    case 12:
        if (gCurrentPinballGame->cyndaquilCollisionEnabled == 0)
            return;

        if (gCurrentPinballGame->collisionCooldownTimer != 0)
            return;

        if (gCurrentPinballGame->eggCaveState != 0)
            return;

        gCurrentPinballGame->eggCaveState++;

        gCurrentPinballGame->cyndaquilCollisionEnabled = 0;
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 2;

        *arg2 = 0xD000;
        *arg1 = 1;
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        PlayRumble(7);
        return;
    case 13:
        if (gCurrentPinballGame->cyndaquilCollisionEnabled == 0)
            return;

        if (gCurrentPinballGame->collisionCooldownTimer != 0)
            return;

        if (gCurrentPinballGame->eggCaveState != 1)
            return;

        gCurrentPinballGame->eggCaveState++;
        gCurrentPinballGame->cyndaquilCollisionEnabled = 0;
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg2 = 0xCC00;
        *arg1 = 1;

        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        PlayRumble(7);
        return;
    case 14:
        if ((gCurrentPinballGame->boardState > 2) && (gCurrentPinballGame->boardState != 5))
        {
            if (gCurrentPinballGame->eggCaveExitDelayTimer == 0)
            {
                if (gCurrentPinballGame->eggCaveState == 2)
                {
                    gCurrentPinballGame->collisionSurfaceType = 0;
                    gCurrentPinballGame->collisionResponseType = 2;
                    *arg2 = 0xC800;
                    *arg1 = 1;
                    gCurrentPinballGame->eggCaveState++;

                    m4aSongNumStart(SE_UNKNOWN_0xB7);
                    gCurrentPinballGame->scoreAddedInFrame = 5000;
                    PlayRumble(7);
                    return;
                }
                else if (gCurrentPinballGame->eggCaveState == 3)
                {
                    gCurrentPinballGame->collisionSurfaceType = 0;
                    gCurrentPinballGame->collisionResponseType = 2;
                    *arg2 = 0xC800;
                    *arg1 = 1;

                    m4aSongNumStart(SE_UNKNOWN_0xB7);
                    gCurrentPinballGame->eggCaveReEntryFlag = 1;
                    PlayRumble(7);
                    return;
                }
            }
        }
        else if (gCurrentPinballGame->cyndaquilCollisionEnabled != 0 && gCurrentPinballGame->eggCaveState == 2)
        {
            gCurrentPinballGame->eggCaveState++;
            gCurrentPinballGame->cyndaquilCollisionEnabled = 0;
            gCurrentPinballGame->collisionSurfaceType = 0;
            gCurrentPinballGame->collisionResponseType = 2;
            *arg2 = 0xC800;
            *arg1 = 1;

            m4aSongNumStart(SE_UNKNOWN_0xB7);
            gCurrentPinballGame->scoreAddedInFrame = 5000;
            PlayRumble(7);
        }

        break;
    }
}


