#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/dusclops_states.h"
#include "constants/ruby_states.h"

extern const u16 gRubyAltEntity0CollisionMap[];
extern const u16 gRubyAltEntity1CollisionMap[];
extern const u16 gWhiscashCollisionMap[];

extern struct SongHeader se_unk_99;
extern u16 gSapphireTargetBumperIndexMap[];


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
                    gCurrentPinballGame->ballCatchState = TRAP_CATCH_HOLE;
                else
                    gCurrentPinballGame->ballCatchState = TRAP_EVO_SHOP_HOLE;
            }
            else
                gCurrentPinballGame->ballCatchState= TRAP_EGG_HOLE;

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
        gCurrentPinballGame->sapphireEntityCollisionFlag = 1;
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


s16 CollisionCheck_Sapphire(struct Vector16 *arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;

    u32 some_enum;
    u8 switch_enum;

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

    CheckSapphireBumperCollision(arg0, &sp00, &sp02);

    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
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
    case 3:
    case 2:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    }

    ProcessSapphireCollisionEvent((s32) some_enum, &return_val, arg1);
    return return_val;
}

void CheckSapphireBumperCollision(struct Vector16 *arg0, s16 *arg1, u8 *arg2) {

    s16 deltaX;
    s16 deltaY;
    u16 maskedResult = 0;
    u8 lowerNibble = 0;
    s32 ix = 0;

    if (gCurrentPinballGame->ballInLowerHalf == 0)
    {
        if (gCurrentPinballGame->boardLayerDepth != 0)
            return;

        deltaX = arg0->x + gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
        deltaY = arg0->y + gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

        if (deltaX <= 63U && deltaY <= 63U)
        {
            maskedResult = 0xFFF0 & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
            lowerNibble = 0xF & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
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
                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }
        gCurrentPinballGame->pondBumperStates[ix] = 6;

        *arg1 = maskedResult;
        *arg2 = lowerNibble;

        if (gCurrentPinballGame->bumperHitCountdown <= 0)
            gCurrentPinballGame->bumperHitCountdown = 2;
    }
}


void ProcessSapphireCollisionEvent(u8 arg0, u16* arg1, u16* arg2)
{
    s16 absVelY;
    s16 x0Position;
    s16 modRes;
    s16 index;
    u16 angle;
    int squaredMagnitude;

    switch (arg0)
    {
    case 1:
        if (gCurrentPinballGame->collisionCooldownTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ1.x >= 200)
                gCurrentPinballGame->ballCatchState = TRAP_CATCH_HOLE;
            else
                gCurrentPinballGame->ballCatchState = TRAP_EVO_SHOP_HOLE;

            DispatchSapphireCatchModeInit();
            gCurrentPinballGame->collisionResponseType = 7;
            *arg1 = 1;
        }
        break;
    case 2:
        if (gCurrentPinballGame->boardLayerDepth == 0)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->boardLayerDepth = 2;
        }
        else if (gCurrentPinballGame->boardLayerDepth == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->boardLayerDepth = 3;
        }
        else if (gCurrentPinballGame->boardLayerDepth == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 1;
        }
        break;
    case 3:
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
        break;
    case 4:
        if (gCurrentPinballGame->mainBoardCountdownTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.y < 260)
            {
                if (gCurrentPinballGame->ball->positionQ0.x < 74)
                {
                    if (gCurrentPinballGame->boardState < 3 && gCurrentPinballGame->sapphireBumperState[1] < 3)
                    {
                        if (gCurrentPinballGame->sapphireBumperState[1] == 1)
                            gCurrentPinballGame->sapphireBumperAnimKeyframe[1] = 6;
                        else
                            gCurrentPinballGame->sapphireBumperAnimKeyframe[1] = 4;

                        gCurrentPinballGame->sapphireBumperAnimSubTimer[1] = 0;
                        gCurrentPinballGame->sapphireBumperState[1] = 1;
                        PlayRumble(7);

                        gCurrentPinballGame->ball->velocity.x /= 2;
                        gCurrentPinballGame->ball->velocity.y /= 2;

                        memcpy(&gCurrentPinballGame->ballStates[1], &gCurrentPinballGame->ballStates[0], sizeof(*gCurrentPinballGame->ballStates));

                        gCurrentPinballGame->secondaryBall = &gCurrentPinballGame->ballStates[1];
                        gCurrentPinballGame->ballLaunchTimer = 25;
                    }
                }
                else if (gCurrentPinballGame->ball->positionQ0.x < 116)
                {
                    if (gCurrentPinballGame->boardState < 3 && gCurrentPinballGame->sapphireBumperState[0] < 3)
                    {
                        if (gCurrentPinballGame->sapphireBumperState[0] == 1)
                            gCurrentPinballGame->sapphireBumperAnimKeyframe[0] = 6;
                        else
                            gCurrentPinballGame->sapphireBumperAnimKeyframe[0] = 4;

                        gCurrentPinballGame->sapphireBumperAnimSubTimer[0] = 0;
                        gCurrentPinballGame->sapphireBumperState[0] = 1;

                        PlayRumble(7);

                        gCurrentPinballGame->ball->velocity.x /= 2;
                        gCurrentPinballGame->ball->velocity.y /= 2;

                        memcpy(&gCurrentPinballGame->ballStates[1], &gCurrentPinballGame->ballStates[0], sizeof(*gCurrentPinballGame->ballStates));

                        gCurrentPinballGame->secondaryBall = &gCurrentPinballGame->ballStates[1];
                        gCurrentPinballGame->ballLaunchTimer = 25;
                    }
                }
                else
                {
                    gCurrentPinballGame->pelipperFrameTimer = 1800;
                    gCurrentPinballGame->pelipperState = 1;

                    if (gCurrentPinballGame->progressLevel < 99)
                        gCurrentPinballGame->progressLevel++;

                    gCurrentPinballGame->scoreAddedInFrame = 5000;
                }
            }
            else
            {
                if (gCurrentPinballGame->ball->positionQ0.x < 110)
                {
                    gCurrentPinballGame->seedotCollisionTrigger = 1;
                    gCurrentPinballGame->ball->velocity.y /= 2;
                }
                else
                {
                    if (gCurrentPinballGame->zigzagoonState == 0)
                        gCurrentPinballGame->zigzagoonState = 1;
                    else
                        gCurrentPinballGame->zigzagoonState = 0;

                    gCurrentPinballGame->ball->velocity.y /=2;
                    gCurrentPinballGame->scoreAddedInFrame = 3000;
                }
            }

            gCurrentPinballGame->mainBoardCountdownTimer = 45;
            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
        }
        break;
    case 5:
        gCurrentPinballGame->sapphireEntityCollisionFlag = 1;
        gCurrentPinballGame->ballInLaunchChute = 1;
        gCurrentPinballGame->ballCollisionZone = 0;
        gCurrentPinballGame->sapphireDiverterActive = 0;
        break;
    case 6:
        if (gCurrentPinballGame->ball->positionQ0.x < 120)
        {
            if (gCurrentPinballGame->ball->velocity.y > 0)
            {
                angle = 0xDA00;
                squaredMagnitude =
                    gCurrentPinballGame->ball->velocity.x * gCurrentPinballGame->ball->velocity.x +
                    gCurrentPinballGame->ball->velocity.y * gCurrentPinballGame->ball->velocity.y;

                squaredMagnitude = Sqrt(squaredMagnitude * 4) / 2;
                gCurrentPinballGame->ball->velocity.x = squaredMagnitude * Cos(angle) / 20000;
                gCurrentPinballGame->ball->velocity.y = -squaredMagnitude * Sin(angle) / 20000;
            }
        }
        else
            gCurrentPinballGame->sapphireDiverterActive = 1;
        break;
    case 7:
        if (gCurrentPinballGame->shopShockWallAnimState != 3)
        {
            gCurrentPinballGame->shopBumperHitTimer = 17;
            gCurrentPinballGame->collisionSurfaceType = 0;
            gCurrentPinballGame->collisionResponseType = 2;
            *arg2 = 0xD800;
            *arg1 = 1;
        }
        break;
    case 8:
        x0Position = gCurrentPinballGame->ball->positionQ0.x;
        if (gCurrentPinballGame->boardLayerDepth > 0)
        {
            if (gCurrentPinballGame->ballCollisionZone == 7)
            {
                gCurrentPinballGame->coinRewardAmount = 10;
                if (gCurrentPinballGame->coinRewardLevel < 3)
                {
                    if (gCurrentPinballGame->coinRewardLevel == 0)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                        gCurrentPinballGame->coinRewardAmount = 1;
                    }
                    else if (gCurrentPinballGame->coinRewardLevel == 1)
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
        }
        else
        {
            if (x0Position <= 72)
            {
                if (gCurrentPinballGame->ballCollisionZone == 8)
                {
                    if (gCurrentPinballGame->boardState < 3 && gCurrentPinballGame->evoArrowProgress < 3)
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
            }
            else if (x0Position <= 98)
            {
                if (gCurrentPinballGame->ballPowerUpLight[0] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[0] = 1;
                gCurrentPinballGame->ballCollisionZone = 3;

                if (gCurrentPinballGame->ballPowerUpAnimActive == 0 && (gCurrentPinballGame->ballPowerUpLight[1] & gCurrentPinballGame->ballPowerUpLight[2]))
                {
                    gCurrentPinballGame->ballPowerUpAnimActive = 1;
                    gCurrentPinballGame->ballShadowTimer = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else if (x0Position <= 118)
            {
                if (gCurrentPinballGame->ballPowerUpLight[1] == 0) 
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[1] = 1;
                gCurrentPinballGame->ballCollisionZone = 4;

                if (gCurrentPinballGame->ballPowerUpAnimActive == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[2]))
                {
                    gCurrentPinballGame->ballPowerUpAnimActive = 1;
                    gCurrentPinballGame->ballShadowTimer = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else if (x0Position <= 146)
            {
                if (gCurrentPinballGame->ballPowerUpLight[2] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[2] = 1;
                gCurrentPinballGame->ballCollisionZone = 5;

                if (gCurrentPinballGame->ballPowerUpAnimActive == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[1]))
                {
                    gCurrentPinballGame->ballPowerUpAnimActive = 1;
                    gCurrentPinballGame->ballShadowTimer = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else
            {
                if (gCurrentPinballGame->ballCollisionZone == 9)
                {
                    if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->catchArrowProgress < 3)
                    {
                        if (gCurrentPinballGame->catchArrowProgress == 0)
                            gCurrentPinballGame->scoreAddedInFrame = 2000;
                        else if (gCurrentPinballGame->catchArrowProgress == 1)
                            gCurrentPinballGame->scoreAddedInFrame = 5000;
                        else
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        
                        gCurrentPinballGame->catchArrowProgress++;

                        if (gCurrentPinballGame->chargeFillValue == 13)
                            m4aSongNumStart(SE_UNKNOWN_0x99);

                        if (gCurrentPinballGame->catchArrowProgress > 1)
                            gCurrentPinballGame->catchProgressFlashing = 1;
                    }

                    gCurrentPinballGame->travelRouletteSlotHitType = 2;
                }

                gCurrentPinballGame->ballCollisionZone = 6;
            }
        }
        break;
    case 9:
        x0Position = gCurrentPinballGame->ball->positionQ0.x;
        if (gCurrentPinballGame->boardLayerDepth > 0)
            gCurrentPinballGame->ballCollisionZone = 7;
        else if (x0Position <= 50)
            gCurrentPinballGame->ballCollisionZone = 8;
        else
            gCurrentPinballGame->ballCollisionZone = 9;
        break;
    case 10:
        if (gCurrentPinballGame->ball->positionQ0.x <= 46)
        {
            gCurrentPinballGame->ballCollisionZone = 10;
            if (gCurrentPinballGame->holeIndicators[0] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[0] = 1;
                if (gCurrentPinballGame->allHolesLit == 0 && (
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[2] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->allHolesLit = 1;
                    gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 120)
        {
            gCurrentPinballGame->ballCollisionZone = 11;

            if (gCurrentPinballGame->holeIndicators[1] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[1] = 1; 
                if (gCurrentPinballGame->allHolesLit == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[2] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->allHolesLit = 1;
                    gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 193)
        {
            gCurrentPinballGame->ballCollisionZone = 12;
            if (gCurrentPinballGame->holeIndicators[2] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[2] = 1;

                if (gCurrentPinballGame->allHolesLit == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->allHolesLit = 1;
                    gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else
        {
            gCurrentPinballGame->ballCollisionZone = 13;
            if (gCurrentPinballGame->holeIndicators[3] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[3] = 1;
                if (gCurrentPinballGame->allHolesLit == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[2]))
                {
                    gCurrentPinballGame->allHolesLit = 1;
                    gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        break;
    case 11:
        if (gCurrentPinballGame->pikaKickbackTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x <= 120)
                gCurrentPinballGame->outLaneSide = 1;
            else
                gCurrentPinballGame->outLaneSide = 2;

            if (gCurrentPinballGame->outLanePikaPosition < 2)
            {
                if (gCurrentPinballGame->outLanePikaPosition == gCurrentPinballGame->outLaneSide - 1)
                    gCurrentPinballGame->pikaKickbackTimer = 120;
            }
            else
            {
                gCurrentPinballGame->pikaKickbackTimer = 120;
            }
        }
        break;
    case 12:
        if (gCurrentPinballGame->pikaSpinCooldownTimer == 0)
        {
            absVelY = gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->pikaSpinMomentum = absVelY;
            if (absVelY < 0)
                absVelY = -absVelY;

            gCurrentPinballGame->pikaChargeTarget = gCurrentPinballGame->pikaChargeTarget + (absVelY / 3);
            if (gCurrentPinballGame->pikaChargeTarget > 168)
                gCurrentPinballGame->pikaChargeTarget = 168;

            gCurrentPinballGame->pikaSpinCooldownTimer = 20;
        }
        break;
    case 13:
        if (gCurrentPinballGame->ballCollisionZone != 14)
        {
            gCurrentPinballGame->ballCollisionZone = 14;
            index = gSapphireTargetBumperIndexMap[gCurrentPinballGame->targetBumperHitCounter];
            gCurrentPinballGame->targetBumperAnimTimers[index] = 10;
            gCurrentPinballGame->targetBumperHitCounter++;
            if (gCurrentPinballGame->targetBumperHitCounter == 3)
            {
                memcpy(&gCurrentPinballGame->ballStates[1], &gCurrentPinballGame->ballStates[0], sizeof(*gCurrentPinballGame->ballStates));
                gCurrentPinballGame->secondaryBall = &gCurrentPinballGame->ballStates[1];
                if (gCurrentPinballGame->sapphireDiverterActive)
                    gCurrentPinballGame->holeLetterNewHit = 1;
            }

            if (gCurrentPinballGame->targetBumperHitCounter == 11)
                gCurrentPinballGame->secondaryBall = gCurrentPinballGame->ballStates;

            modRes = (gCurrentPinballGame->targetBumperHitCounter - 1) % 4;
            gMain.spriteGroups[modRes + 47].available = 1;
            gCurrentPinballGame->splashEffectFrameIndex[modRes] = 0;
            gCurrentPinballGame->splashEffectFrameTimer[modRes] = 0;
            gCurrentPinballGame->splashEffectPositionIndex[modRes] = gCurrentPinballGame->targetBumperHitCounter - 1;

            if (gCurrentPinballGame->targetBumperHitCounter > 12)
                gCurrentPinballGame->targetBumperHitCounter = 0;

            if (index == 0 && gCurrentPinballGame->ball->velocity.y > -120)
                gCurrentPinballGame->ball->velocity.y = -120;

            if (index == 2 && gCurrentPinballGame->ball->velocity.y > -180)
                gCurrentPinballGame->ball->velocity.y = -180;
        }
        break;
    case 14:
        if (gCurrentPinballGame->ballCollisionZone != 15)
        {
            gCurrentPinballGame->ballCollisionZone = 15;
            index = gSapphireTargetBumperIndexMap[gCurrentPinballGame->targetBumperHitCounter];
            gCurrentPinballGame->targetBumperAnimTimers[index] = 10;
            gCurrentPinballGame->targetBumperHitCounter++;

            modRes = (gCurrentPinballGame->targetBumperHitCounter -1) % 4;
            gMain.spriteGroups[modRes + 47].available = 1;
            gCurrentPinballGame->splashEffectFrameIndex[modRes] = 0;
            gCurrentPinballGame->splashEffectFrameTimer[modRes] = 0;
            gCurrentPinballGame->splashEffectPositionIndex[modRes] = gCurrentPinballGame->targetBumperHitCounter - 1;
            if (index == 1 && gCurrentPinballGame->ball->velocity.y > -150)
                gCurrentPinballGame->ball->velocity.y = -150;
        }
        break;
    case 15:
        if (gCurrentPinballGame->ball->positionQ0.y < 80)
        {
            if (gCurrentPinballGame->pelipperState == 1)
                gCurrentPinballGame->pelipperState = 2;
        }
        else
        {
            if (gCurrentPinballGame->pelipperState == 2)
            {
                gCurrentPinballGame->pelipperState = 3;
                gCurrentPinballGame->pelipperFrameTimer = 0;
            }
        }

        break;
    }
}

s16 CollisionCheck_Dusclops(struct Vector16* arg0, u16* arg1) {
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

    CheckDusclopsEntitiesCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
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
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    CheckDusclopsAbsorbZoneHit(some_enum, &return_val, arg1);
    return return_val;
}

void CheckDusclopsEntitiesCollision(struct Vector16 *arg0, s16* arg1, u8* arg2) {
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    u8 temp;

    maskedResult = 0;
    lowerNibble = 0;

    if(gCurrentPinballGame->boardEntityCollisionMode == DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS)
    {
        if (*arg2 != 0)
            return;

        deltaX = arg0->x -gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y -gCurrentPinballGame->bossCollisionY;

        if (deltaX > 95U || deltaY > 119U)
            return;

        maskedResult = 0xFFF0 & gDusclopsBodyCollisionMap[(deltaY * 96 ) + deltaX];
        lowerNibble = 0xF & gDusclopsBodyCollisionMap[(deltaY * 96 ) + deltaX];

        if (lowerNibble == 0)
            return;

        //Can be hit when ready to absorb (2) or when walking (3)
        temp = gCurrentPinballGame->bossEntityState -3;
        if (temp <= 1U)
            *arg2 = 1;
        else
            *arg2 = lowerNibble;

        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_HIT;
        *arg1 = maskedResult;

        return;
    }

    if(gCurrentPinballGame->boardEntityCollisionMode == DUSCLOPS_ENTITY_COLLISION_MODE_DUSKULL)
    {
        if (*arg2 != 0)
            return;

        if (gCurrentPinballGame->minionCanCollide[0] )
        {
            deltaX = arg0->x - gCurrentPinballGame->minionCollisionPosition[0].x;
            deltaY = arg0->y - gCurrentPinballGame->minionCollisionPosition[0].y;

            if (deltaX < 64U && deltaY < 64U)
            {
                maskedResult = 0xFFF0 & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                lowerNibble = 0xF & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                if (lowerNibble != 0)
                    gCurrentPinballGame->minionState[0] = DUSKULL_ENTITY_STATE_HIT;
            }
        }

        if (lowerNibble == 0)
        {
            if (gCurrentPinballGame->minionCanCollide[1] )
            {
                deltaX = arg0->x - gCurrentPinballGame->minionCollisionPosition[1].x;
                deltaY = arg0->y - gCurrentPinballGame->minionCollisionPosition[1].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = 0xFFF0 & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                        gCurrentPinballGame->minionState[1] = DUSKULL_ENTITY_STATE_HIT;
                }
            }
        }

        if (lowerNibble == 0)
        {
            if ( gCurrentPinballGame->minionCanCollide[2] )
            {
                deltaX = arg0->x - gCurrentPinballGame->minionCollisionPosition[2].x;
                deltaY = arg0->y - gCurrentPinballGame->minionCollisionPosition[2].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = 0xFFF0 & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                    {
                        gCurrentPinballGame->minionState[2] = DUSKULL_ENTITY_STATE_HIT;
                    }
                }
            }
        }

        if (lowerNibble != 0)
        {
            *arg1 = maskedResult;
            *arg2 = 6;
        }
        return;
    }
}

void CheckDusclopsAbsorbZoneHit(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_HIT_ABSORB_ZONE;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

s16 CollisionCheck_Kecleon(struct Vector16 *arg0, u16 *arg1)
{
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

    CheckKecleonEntityCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp00;
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        if (gCurrentPinballGame->kecleonBoardHitState == 0)
        {
            s32 kecleonActive = gCurrentPinballGame->kecleonTargetActive;
            if (kecleonActive == 0)
            {
                gCurrentPinballGame->kecleonBoardHitState = 1;
                gCurrentPinballGame->kecleonCollisionX = kecleonActive;
            }
        }
        gCurrentPinballGame->kecleonCollisionY = 40;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    ProcessKecleonCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

void CheckKecleonEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;

    if (gCurrentPinballGame->boardEntityCollisionMode == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX > 0x3F) || (deltaY < 0 || deltaY > 0x57))
            return;

        arrayValue = (u8)(gKecleonTongueCollisionMap[(deltaY * 0x40) + deltaX]) & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->ballHidden != 0)
            return;
        if (gCurrentPinballGame->bossEntityState > 8)
            return;

        gCurrentPinballGame->bossEntityState = 9;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 2)
    {
        u16 maskedResult;

        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX > 0x57) || (deltaY < 0 || deltaY > 0x3F))
            return;

        maskedResult = gKecleonBodyCollisionMap[(deltaY * 0x58) + deltaX] & 0xFFF0;
        arrayValue = gKecleonBodyCollisionMap[(deltaY * 0x58) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->ballHidden != 0)
            return;
        if (gCurrentPinballGame->bossEntityState == 12)
            return;

        gCurrentPinballGame->bossEntityState = 11;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void ProcessKecleonCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
{
    s16 x, y;
    x = gCurrentPinballGame->ball->positionQ0.x;
    y = gCurrentPinballGame->ball->positionQ0.y;

    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 13:
    case 14:
    case 15:
        return;
    case 8:
        if (x <= 0x72)
        {
            if (y <= 0x38)
            {
                if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[0] <= 0)
                    gCurrentPinballGame->kecleonBerryLargeFlashTimer[0] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[1] <= 0)
                    gCurrentPinballGame->kecleonBerryLargeFlashTimer[1] = 0x18;
            }
        }
        else if (y <= 0x63)
        {
            if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[3] <= 0)
                gCurrentPinballGame->kecleonBerryLargeFlashTimer[3] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[2] <= 0)
                gCurrentPinballGame->kecleonBerryLargeFlashTimer[2] = 0x18;
        }
        break;
    case 9:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[7] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[7] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[5] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[5] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[8] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[8] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[0] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[0] = 0x18;
        }
        break;
    case 10:
        if (gCurrentPinballGame->kecleonHitboxX == 0)
        {
            gCurrentPinballGame->kecleonHitSparkTimer[0] = 0xB;
            gCurrentPinballGame->ballTrailPosition[0].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPosition[0].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->kecleonHitboxX == 3)
        {
            gCurrentPinballGame->kecleonHitSparkTimer[1] = 0xB;
            gCurrentPinballGame->ballTrailPosition[1].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPosition[1].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->kecleonHitboxX == 6)
        {
            gCurrentPinballGame->kecleonHitSparkTimer[2] = 0xB;
            gCurrentPinballGame->ballTrailPosition[2].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPosition[2].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->kecleonHitboxX == 9)
        {
            gCurrentPinballGame->kecleonHitSparkTimer[3] = 0xB;
            gCurrentPinballGame->ballTrailPosition[3].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPosition[3].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        break;
    case 11:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[9] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[9] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[2] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[2] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[6] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[6] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[1] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[1] = 0x18;
        }
        break;
    case 12:
        if (x <= 0x72)
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[4] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[4] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[3] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[3] = 0x18;
        }
        break;
    }
}

void CheckKecleonProjectileCollision(struct Vector16 *arg0)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    s16 x, y;
    u16 sp00;
    u8 sp02;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;
    u32 some_enum;

    gCurrentPinballGame->kecleonCollisionEnabled = 1;
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

    some_enum = (sp02 >> 2) >> 2;

    x = gCurrentPinballGame->kecleonCollisionPos.x;
    y = gCurrentPinballGame->kecleonCollisionPos.y;

    switch (some_enum)
    {
    case 8:
        if (x <= 0x72)
        {
            if (y <= 0x38)
            {
                if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[0] <= 0)
                    gCurrentPinballGame->kecleonBerryLargeFlashTimer[0] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[1] <= 0)
                    gCurrentPinballGame->kecleonBerryLargeFlashTimer[1] = 0x18;
            }
        }
        else if (y <= 0x63)
        {
            if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[3] <= 0)
                gCurrentPinballGame->kecleonBerryLargeFlashTimer[3] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerryLargeFlashTimer[2] <= 0)
                gCurrentPinballGame->kecleonBerryLargeFlashTimer[2] = 0x18;
        }
        break;
    case 9:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[7] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[7] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[5] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[5] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[8] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[8] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[0] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[0] = 0x18;
        }
        break;
    case 10:
        gCurrentPinballGame->kecleonCollisionEnabled = 0;
        if (gCurrentPinballGame->kecleonHitboxY == 0)
        {
            if (gCurrentPinballGame->kecleonCollisionPos.x != gCurrentPinballGame->kecleonBerryHitPosition[0].x || gCurrentPinballGame->kecleonCollisionPos.y != gCurrentPinballGame->kecleonBerryHitPosition[0].y)
            {
                gCurrentPinballGame->kecleonHitSparkTimer[4] = 0x11;
                gCurrentPinballGame->kecleonBerryHitPosition[0].x = gCurrentPinballGame->kecleonCollisionPos.x;
                gCurrentPinballGame->kecleonBerryHitPosition[0].y = gCurrentPinballGame->kecleonCollisionPos.y;
            }
        }
        else if (gCurrentPinballGame->kecleonHitboxY == 8)
        {
            if (gCurrentPinballGame->kecleonCollisionPos.x != gCurrentPinballGame->kecleonBerryHitPosition[1].x || gCurrentPinballGame->kecleonCollisionPos.y != gCurrentPinballGame->kecleonBerryHitPosition[1].y)
            {
                gCurrentPinballGame->kecleonHitSparkTimer[5] = 0x11;
                gCurrentPinballGame->kecleonBerryHitPosition[1].x = gCurrentPinballGame->kecleonCollisionPos.x;
                gCurrentPinballGame->kecleonBerryHitPosition[1].y = gCurrentPinballGame->kecleonCollisionPos.y;
            }
        }
        else if (gCurrentPinballGame->kecleonHitboxY == 16)
        {
            if (gCurrentPinballGame->kecleonCollisionPos.x != gCurrentPinballGame->kecleonBerryHitPosition[2].x || gCurrentPinballGame->kecleonCollisionPos.y != gCurrentPinballGame->kecleonBerryHitPosition[2].y)
            {
                gCurrentPinballGame->kecleonHitSparkTimer[6] = 0x11;
                gCurrentPinballGame->kecleonBerryHitPosition[2].x = gCurrentPinballGame->kecleonCollisionPos.x;
                gCurrentPinballGame->kecleonBerryHitPosition[2].y = gCurrentPinballGame->kecleonCollisionPos.y;
            }
        }
        break;
    case 11:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[9] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[9] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[2] <= 0)
                    gCurrentPinballGame->kecleonBerrySmallFlashTimer[2] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[6] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[6] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[1] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[1] = 0x18;
        }
        break;
    case 12:
        if (x <= 0x72)
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[4] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[4] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBerrySmallFlashTimer[3] <= 0)
                gCurrentPinballGame->kecleonBerrySmallFlashTimer[3] = 0x18;
        }
        break;
    }
}

s16 CollisionCheck_Kyogre(struct Vector16 *arg0, u16 *arg1)
{
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
    if (arg0->y < 0x200)
    {
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
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckKyogreEntityCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
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
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    ProcessKyogreCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

void CheckKyogreEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;
    u16 maskedResult;

    if (gCurrentPinballGame->boardEntityCollisionMode == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x78) || (deltaY < 0 || deltaY >= 0x98))
            return;

        maskedResult = gKyogreForm1CollisionMap[(deltaY * 0x78) + deltaX] & 0xFFF0;
        arrayValue = gKyogreForm1CollisionMap[(deltaY * 0x78) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 2)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x58))
            return;

        maskedResult = gKyogreForm2CollisionMap[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gKyogreForm2CollisionMap[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 3)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x68))
            return;

        maskedResult = gKyogreForm3CollisionMap[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gKyogreForm3CollisionMap[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void ProcessKyogreCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->bossEntityState = 6;
        gCurrentPinballGame->ballFrozenState = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

s16 CollisionCheck_Groudon(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinAcceleration = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 tileMapPage;
        s32 boardLayer;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        tileMapPage = vec1.y / 64;
        boardLayer = gCurrentPinballGame->boardLayerDepth;
        vec1.y %= 64;
        r2 = gBoardConfig.fieldLayout.collisionTileMap[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
        sp00 = gBoardConfig.fieldLayout.collisionAngleMap[boardLayer + tileMapPage][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gBoardConfig.fieldLayout.collisionTypeMap[boardLayer + tileMapPage][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckGroudonEntityCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballSpawnX - 8) || gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
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
                        gCurrentPinballGame->ball->spinAcceleration = 40;
                        gCurrentPinballGame->ball->spinSpeed = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinAcceleration = -40;
                        gCurrentPinballGame->ball->spinSpeed = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    ProcessGroudonCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

void CheckGroudonEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 resultFromArray;
    u16 maskedResult;
    u16 lowerNibble;
    s16 i;

    if (gCurrentPinballGame->boardEntityCollisionMode == 1)
    {
        if ((*arg2 & 0xF) == 0)
        {
            deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
            deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

            if ((deltaX >= 0 && deltaX < 0x70) && (deltaY >= 0 && deltaY < 0x80))
            {
                resultFromArray = gGroudonBodyCollisionMap[(deltaY * 0x70) + deltaX];
                maskedResult = resultFromArray & 0xFFF0;
                lowerNibble = resultFromArray & 0xF;
                if (lowerNibble != 0)
                {
                    if (gCurrentPinballGame->bossHitFlashTimer == 0)
                        gCurrentPinballGame->bossHitFlashTimer = 0x27;

                    *arg1 = maskedResult;
                    *arg2 = lowerNibble;
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->boulderCollisionPos[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->boulderCollisionPos[i].x;
        deltaY = arg0->y - gCurrentPinballGame->boulderCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->boulderHitFlag[i] = 1;
    }
    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->firePillarCollisionPos[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->firePillarCollisionPos[i].x;
        deltaY = arg0->y - gCurrentPinballGame->firePillarCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->firePillarHitTimer[i] = 8;
    }
}

void ProcessGroudonCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->bossEntityState = 6;
        gCurrentPinballGame->ballFrozenState = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

//One known callsite is 080145D2 during the rayquaza bonus stage
s16 CollisionCheck_Rayquaza(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinAcceleration = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 tileMapPage;
        s32 boardLayer;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        tileMapPage = vec1.y / 64;
        boardLayer = gCurrentPinballGame->boardLayerDepth;
        vec1.y %= 64;
        r2 = gBoardConfig.fieldLayout.collisionTileMap[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
        sp00 = gBoardConfig.fieldLayout.collisionAngleMap[boardLayer + tileMapPage][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gBoardConfig.fieldLayout.collisionTypeMap[boardLayer + tileMapPage][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckRayquazaEntityCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballSpawnX - 8) || gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
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
                        gCurrentPinballGame->ball->spinAcceleration = 40;
                        gCurrentPinballGame->ball->spinSpeed = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinAcceleration = -40;
                        gCurrentPinballGame->ball->spinSpeed = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    ProcessRayquazaCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

void CheckRayquazaEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u16 lowerNibble;

    if (gCurrentPinballGame->boardEntityCollisionMode != 1)
        return;
    if (*arg2 & 0xF)
        return;

    deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
    deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

    if ((deltaX < 0 || deltaX >= 0x80) || (deltaY < 0 || deltaY >= 0x80))
        return;

    maskedResult = gRayquazaBodyCollisionMap[(deltaY * 0x80) + deltaX] & 0xFFF0;
    lowerNibble = gRayquazaBodyCollisionMap[(deltaY * 0x80) + deltaX] & 0xF;

    if (lowerNibble == 0)
        return;

    gCurrentPinballGame->bossHitFlashTimer = 9;
    *arg1 = maskedResult;
    *arg2 = lowerNibble;
}

void ProcessRayquazaCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->bossEntityState = 6;
        gCurrentPinballGame->ballFrozenState = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

s16 CollisionCheck_Spheal(struct Vector16 *arg0, u16 *arg1)
{
    u16 sp0;
    u8 sp2;
    u16 sp4_return;

    struct Vector16 div_result;
    struct Vector16 div_remainder;
    s32 tileMapPage;
    s32 boardLayer;
    s16 collisionTileIndex;
    u8 enum1, enum2;

    sp4_return = 0;
    gCurrentPinballGame->ball->spinAcceleration = 0;

    div_result.x = arg0->x / 8;
    div_result.y = arg0->y / 8;
    div_remainder.x = arg0->x % 8;
    div_remainder.y = arg0->y % 8;
    tileMapPage = div_result.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    div_result.y %= 64;

    collisionTileIndex = gBoardConfig.fieldLayout.collisionTileMap[boardLayer + tileMapPage][div_result.y * 64 + div_result.x];
    sp0 = gBoardConfig.fieldLayout.collisionAngleMap[boardLayer + tileMapPage][collisionTileIndex * 64 + div_remainder.y * 8 + div_remainder.x];
    sp2 = gBoardConfig.fieldLayout.collisionTypeMap[boardLayer + tileMapPage][collisionTileIndex * 64 + div_remainder.y * 8 + div_remainder.x];

    CheckSphealEntityCollision(arg0, &sp0, &sp2);

    enum1 = sp2 & 0xF;
    enum2 = sp2 >> 4;
    switch (enum1)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = enum1 - 1;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp0;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballSpawnX - 8) ||
                gCurrentPinballGame->ball->positionQ0.y < (gBoardConfig.fieldLayout.ballSpawnY - 8))
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
                        gCurrentPinballGame->ball->spinAcceleration = 40;
                        gCurrentPinballGame->ball->spinSpeed = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinAcceleration = -40;
                        gCurrentPinballGame->ball->spinSpeed = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        sp4_return = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp0 & 0x0000FFF0;

        if (gCurrentPinballGame->ball->positionQ0.x < 120)
            gCurrentPinballGame->minionHitFlashTimer[0] = 24;
        else
            gCurrentPinballGame->minionHitFlashTimer[1] = 24;

        sp4_return = 1;
        break;
    case 5:
        enum2 = 4;
        break;
    }

    ProcessSphealCollisionEvent(enum2, &sp4_return, arg1);
    return sp4_return;
}

void CheckSphealEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 i;
    s16 deltaX, deltaY;
    u16 lowerReadFromRom;
    u16 upperReadFromRom;
    for (i = 0; i < 2; i++)
    {

        if (gCurrentPinballGame->flyingEnemyCollisionType[i] == 1)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->flyingEnemyCollisionPos[i].x;
            deltaY = arg0->y - gCurrentPinballGame->flyingEnemyCollisionPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gSphealFrozenIceCollisionMap[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gSphealFrozenIceCollisionMap[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            if (gCurrentPinballGame->ballRespawnState != 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            gCurrentPinballGame->flyingEnemyState[i] = 4;
        }
        else if (gCurrentPinballGame->flyingEnemyCollisionType[i] != 0)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->flyingEnemyCollisionPos[i].x;
            deltaY = arg0->y - gCurrentPinballGame->flyingEnemyCollisionPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gSphealCrackedIceCollisionMap[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gSphealCrackedIceCollisionMap[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            if (gCurrentPinballGame->flyingEnemyCollisionType[i] == 2)
            {
                gCurrentPinballGame->flyingEnemyState[i] = 4;
            }
            else
            {
                gCurrentPinballGame->flyingEnemyHitCooldown[i] = 24;
            }
        }
    }
}

void ProcessSphealCollisionEvent(u8 arg0_enum, u16 *arg1, u16 *arg2)
{
    switch (arg0_enum)
    {
    case 2:
        gCurrentPinballGame->knockdownTargetIndex[2] = 0;
        gCurrentPinballGame->knockdownPhase[2] = 2;
        break;
    case 3:
        gCurrentPinballGame->knockdownTargetIndex[2] = 1;
        gCurrentPinballGame->knockdownPhase[2] = 2;
        break;
    case 8:
        gCurrentPinballGame->knockdownTargetIndex[2] = 0;
        gCurrentPinballGame->knockdownPhase[2] = 1;
        gCurrentPinballGame->knockdownStunTimer[2] = 100;
        break;
    case 9:
        gCurrentPinballGame->knockdownTargetIndex[2] = 1;
        gCurrentPinballGame->knockdownPhase[2] = 1;
        gCurrentPinballGame->knockdownStunTimer[2] = 100;
        break;
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}