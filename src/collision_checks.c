#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/dusclops_states.h"
#include "constants/ruby_states.h"

extern const u16 gUnknown_08254B10[];
extern const u16 gUnknown_08257390[];
extern const u16 gUnknown_08259C10[];

extern struct SongHeader se_unk_99;
extern u16 gUnknown_086ACE70[];


s16 COLLISION_CHECK_RUBY_14E08(struct Vector16 *arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 tileIndex;
    s32 mapSection;
    s32 mapBaseIndex;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    mapSection = vec1.y / 64;
    mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
    vec1.y %= 64;

    tileIndex = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckRubyPondBumperCollision(arg0, &sp00, &sp02);

    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum-1) {
    case 0:
    case 3:
    case 5:
        gCurrentPinballGame->collisionSubType = (switch_enum - 1);
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00;

        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballStartX - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballStartY - 8)
            {

                if (gCurrentPinballGame->ball->spin > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spin != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0x28;
                        gCurrentPinballGame->ball->spin = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0xFFD8;
                        gCurrentPinballGame->ball->spin = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 1:
    case 2:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;

        break;
    case 4:
        gCurrentPinballGame->whiscashState = WHISCASH_STATE_ABSORB_ZONE_HIT;
        gCurrentPinballGame->ballLockState = 1;
        some_enum = 0;
        break;
    }
    CheckRubyAbsorbZoneHit((s32) some_enum, &return_val, arg1);

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

    if (gCurrentPinballGame->ballCollisionDisabled == 0)
    {
        if (gCurrentPinballGame->collisionMapIndex != 0)
            return;

        if (gCurrentPinballGame->shouldProcessWhiscash)
        {
            if (gCurrentPinballGame->whiscashVulnerable == 0)
                return;

            deltaX = arg0->x + gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
            deltaY = arg0->y + gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

            if (deltaX > 79U)
                return;

            if (deltaY > 87U)
                return;

            maskedResult = 0xFFF0 & gUnknown_08259C10[(deltaY * 80) + deltaX];
            lowerNibble = 0xF & gUnknown_08259C10[(deltaY * 80) + deltaX];

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
            maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
            lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];

            if (lowerNibble != 0)
                ix = 0;
        }

        if (lowerNibble == 0)
        {
            deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[1].x + arg0->x;
            deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[1].y + arg0->y;

            if (deltaX <= 63U && deltaY <= 63U)
            {
                maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                if (lowerNibble != 0)
                    ix = 1;
            }

            if (lowerNibble == 0)
            {
                deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[2].x + arg0->x;
                deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[2].y + arg0->y;

                if (deltaX <= 63U && deltaY <= 63U)
                {
                    maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];

                    if (lowerNibble == 0)
                        return;

                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }

        if (!gCurrentPinballGame->rubyPondContentsChanging)
            gCurrentPinballGame->pondBumperAnimState[ix] = 107;

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
            if (gCurrentPinballGame->pondGateAnimPhase[0] > 0)
            {
                s16 deltaY_alt;
                deltaX = 2 * (-24 -gCurrentPinballGame->pondGateSpriteOffset[0]) + arg0->x;
                deltaY_alt = arg0->y -580;

                if (deltaX <= 71U && deltaY_alt <= 71U)
                {
                    *arg1 = 0xFFF0 & gUnknown_08254B10[(deltaY_alt * 72) + deltaX];
                    *arg2 = 0xF & gUnknown_08254B10[(deltaY_alt * 72) + deltaX];

                    if (*arg2 & 1)
                    {
                        gCurrentPinballGame->pondGateHitSide = 1;
                        *arg2 = 6;
                    }
                }
            }

            if (gCurrentPinballGame->pondGateAnimPhase[1] > 0)
            {
                deltaX = ((gCurrentPinballGame->pondGateSpriteOffset[1] - 180) * 2) + arg0->x;
                deltaY = arg0->y -580;

                if (deltaX <= 71U && deltaY <= 71U)
                {
                    *arg1 = 0xFFF0 & gUnknown_08257390[(deltaY * 72) + deltaX];
                    *arg2 = 0xF & gUnknown_08257390[(deltaY * 72) + deltaX];

                    if (*arg2 & 1)
                    {
                        gCurrentPinballGame->pondGateHitSide = 2;
                        *arg2 = 6;
                        return;
                    }
                }
            }
        }
    }
}

void CheckRubyAbsorbZoneHit(s32 arg0, s16* arg1, u16* arg2)
{
    s16 absVelY;

    switch ((u8)arg0 - 1)
    {
    case 0:
        if (gCurrentPinballGame->entryAnimTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ1.x > 359)
            {
                if (gCurrentPinballGame->ball->positionQ1.y > 199)
                    gCurrentPinballGame->boardEntryMode = 1;
                else
                    gCurrentPinballGame->boardEntryMode = 3;
            }
            else
                gCurrentPinballGame->boardEntryMode= 2;

            InitBoardEntryHole();
            gCurrentPinballGame->collisionType = 7;
            *arg1 = 1;
            return;
        }
    default:
        return;
    case 1:
        if (gCurrentPinballGame->collisionMapIndex == 0)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->collisionMapIndex = 2;
            break;
        }

        if (gCurrentPinballGame->collisionMapIndex == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->collisionMapIndex = 3;
        }

        break;
    case 2:
        if (gCurrentPinballGame->collisionMapIndex == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 3;
            gCurrentPinballGame->collisionMapIndex = 0;
        }
        else if (gCurrentPinballGame->collisionMapIndex == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->collisionMapIndex = 2;
        }

        if (gCurrentPinballGame->nuzleafAnimState == 6)
            gCurrentPinballGame->nuzleafAnimState = 7;

        if (gCurrentPinballGame->shopDoorTargetFrame & 0xF0 )
            gCurrentPinballGame->shopDoorTargetFrame = 0;

        if (gCurrentPinballGame->holeEntryState & 0xF0)
            gCurrentPinballGame->holeEntryState = 0;

        break;
    case 3:
        if (gCurrentPinballGame->triggerButtonCooldown == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 131)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;

                if (gCurrentPinballGame->bonusMultiplier <= 98)
                    gCurrentPinballGame->bonusMultiplier++;
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

                if (gCurrentPinballGame->coinAnimActive == 0)
                {
                    gCurrentPinballGame->coinAnimActive = 1;
                    gCurrentPinballGame->coinAnimFrame = 0;
                }
            }
            gCurrentPinballGame->triggerButtonCooldown = 45;

            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
        }
        break;
    case 4:
        gCurrentPinballGame->tiltDetected = 1;
        gCurrentPinballGame->hitFlashActive = 1;
        gCurrentPinballGame->boardTargetState = 0;
        return;
    case 5:
        if (gCurrentPinballGame->ballCollisionDisabled == 0)
        {
            SetBoardFieldCollisionData(1);
            gCurrentPinballGame->rubyAbsorbZoneActive = 1;
        }
        break;
    case 6:
        if (gCurrentPinballGame->ball->positionQ0.x < 50)
        {
            if (gCurrentPinballGame->nuzleafHitPhase == 0)
            {
                gCurrentPinballGame->nuzleafHitPhase = 1;
                gCurrentPinballGame->nuzleafAnimState = 1;
                gCurrentPinballGame->collisionSubType = 0;
                gCurrentPinballGame->collisionType = 2;
                *arg2 = 0xB000;
                *arg1 = 1;
            }
        }
        else if (gCurrentPinballGame->nuzleafHitPhase == 1)
        {
            gCurrentPinballGame->nuzleafHitPhase = 2;
            gCurrentPinballGame->nuzleafAnimState = 3;
            gCurrentPinballGame->collisionSubType = 0;
            gCurrentPinballGame->collisionType = 2;
            *arg2 = 0xA000;
            *arg1 = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;

            memcpy(&gCurrentPinballGame->boardState34[1], gCurrentPinballGame->boardState34, 0x44U);

            gCurrentPinballGame->boardState30 = &gCurrentPinballGame->boardState34[1];
            gCurrentPinballGame->boardState28 = 120;
        }

        gCurrentPinballGame->boardTargetState = 14;
        return;
    case 7:
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            if (gCurrentPinballGame->boardTargetState == 8)
            {
                if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->savedEvoHitCount <= 2)
                {
                    if (gCurrentPinballGame->savedEvoHitCount == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->savedEvoHitCount == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->savedEvoHitCount++;

                    m4aSongNumStart(SE_UNKNOWN_0x99);
                }

                gCurrentPinballGame->travelModeProgress = 1;
            }
            gCurrentPinballGame->boardTargetState = 2;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            if (gCurrentPinballGame->boardTargetState == 7)
            {
                gCurrentPinballGame->coinsTotalToCollect = 10;

                if(gCurrentPinballGame->scoreMultiplierLevel <= 2)
                {
                    if(gCurrentPinballGame->scoreMultiplierLevel == 0)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                        gCurrentPinballGame->coinsTotalToCollect = 1;
                    }
                    else if(gCurrentPinballGame->scoreMultiplierLevel == 1)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                        gCurrentPinballGame->coinsTotalToCollect = 5;
                    }
                    else
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 10000;
                        gCurrentPinballGame->coinsTotalToCollect = 10;
                    }
                    gCurrentPinballGame->scoreMultiplierLevel++;
                }

                gCurrentPinballGame->coinAnimFrameCounter = 0;
                gCurrentPinballGame->scoreMultiplierDecayTimer = 0;
            }

            gCurrentPinballGame->boardTargetState = 1;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 126)
        {
            if (gCurrentPinballGame->ballPowerUpLight[0] == 0)
                gCurrentPinballGame->scoreAddedInFrame = 1000;

            gCurrentPinballGame->ballPowerUpLight[0] = 1;
            gCurrentPinballGame->boardTargetState = 3;

            if (gCurrentPinballGame->ballUpgradeTriggered == 0)
            {
                if (!(gCurrentPinballGame->ballPowerUpLight[1] &
                      gCurrentPinballGame->ballPowerUpLight[2]))
                    return;

                gCurrentPinballGame->ballUpgradeTriggered = 1;
                gCurrentPinballGame->ballUpgradeAnimTimer = 60;
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
                gCurrentPinballGame->boardTargetState = 4;

                if (gCurrentPinballGame->ballUpgradeTriggered != 0)
                    return;

                if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                      gCurrentPinballGame->ballPowerUpLight[2]))
                    return;

                gCurrentPinballGame->ballUpgradeTriggered = 1;
                gCurrentPinballGame->ballUpgradeAnimTimer = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }

            if (gCurrentPinballGame->ball->positionQ0.x <= 172)
            {
                if (gCurrentPinballGame->ballPowerUpLight[2] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;

                gCurrentPinballGame->ballPowerUpLight[2] = 1;
                gCurrentPinballGame->boardTargetState = 5;

                if (gCurrentPinballGame->ballUpgradeTriggered != 0)
                    return;

                if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                      gCurrentPinballGame->ballPowerUpLight[1]))
                    return;

                gCurrentPinballGame->ballUpgradeTriggered = 1;
                gCurrentPinballGame->ballUpgradeAnimTimer = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }

            if (gCurrentPinballGame->boardTargetState == 9)
            {
                if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->savedCatchArrows <= 2)
                {
                    if (gCurrentPinballGame->savedCatchArrows == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->savedCatchArrows == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->savedCatchArrows++;

                    MPlayStart(&gMPlayInfo_SE1, &se_unk_99);

                    if (gCurrentPinballGame->savedCatchArrows > 1)
                        gCurrentPinballGame->catchArrowIndicatorBlink = 1;
                }

                gCurrentPinballGame->travelModeProgress = 2;
            }

            gCurrentPinballGame->boardTargetState = 6;
            return;
        }
        break;
    case 8:
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            gCurrentPinballGame->boardTargetState = 8;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            gCurrentPinballGame->boardTargetState = 7;
            return;
        }

        gCurrentPinballGame->boardTargetState = 9;
        return;
    case 9:
        if (gCurrentPinballGame->ball->positionQ0.x <= 46)
        {
            gCurrentPinballGame->boardTargetState = 10;

            if (gCurrentPinballGame->holeIndicators[0] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[0] = 1;

            if (gCurrentPinballGame->allHolesCompleted != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesCompleted = 1;
            gCurrentPinballGame->holeCompletionFlashTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 120)
        {
            gCurrentPinballGame->boardTargetState = 11;

            if (gCurrentPinballGame->holeIndicators[1] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[1] = 1;

            if (gCurrentPinballGame->allHolesCompleted != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesCompleted = 1;
            gCurrentPinballGame->holeCompletionFlashTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 193)
        {
            gCurrentPinballGame->boardTargetState = 12;

            if (gCurrentPinballGame->holeIndicators[2] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[2] = 1;

            if (gCurrentPinballGame->allHolesCompleted != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesCompleted = 1;
            gCurrentPinballGame->holeCompletionFlashTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        gCurrentPinballGame->boardTargetState = 13;

        if (gCurrentPinballGame->holeIndicators[3] != 0)
            return;

        gCurrentPinballGame->scoreAddedInFrame = 1000;
        gCurrentPinballGame->holeIndicators[3] = 1;

        if (gCurrentPinballGame->allHolesCompleted != 0)
            return;

        if (!(gCurrentPinballGame->holeIndicators[0] &
              gCurrentPinballGame->holeIndicators[1] &
              gCurrentPinballGame->holeIndicators[2]))
            return;

        gCurrentPinballGame->allHolesCompleted = 1;
        gCurrentPinballGame->holeCompletionFlashTimer = 126;
        gCurrentPinballGame->scoreAddedInFrame = 4000;
        return;
    case 10:
        if (gCurrentPinballGame->ballCollisionDisabled == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 170)
            {
                if (gCurrentPinballGame->shopDoorTargetFrame > 2U)
                    return;

                gCurrentPinballGame->collisionSubType = 0;
                gCurrentPinballGame->collisionType = 2;
                *arg2 = 0xB000;
                *arg1 = 1;

                if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->holeEntryState <= 2)
                {
                    gCurrentPinballGame->holeEntryState = 3;
                    gCurrentPinballGame->shopDoorTransitionDelay = 5;
                }

                gCurrentPinballGame->scoreAddedInFrame = 50000;
                return;
            }

            if (gCurrentPinballGame->nuzleafAnimState <= 4)
            {
                gCurrentPinballGame->collisionSubType = 0;
                gCurrentPinballGame->collisionType = 2;
                *arg2 = 0xF800;
                *arg1 = 1;
            }

            if (gCurrentPinballGame->nuzleafAnimState == 5)
                gCurrentPinballGame->nuzleafAnimState = 6;

            if (gCurrentPinballGame->rampPrizeType == 0)
                return;

            if (gCurrentPinballGame->rampPrizeType == 1)
                gCurrentPinballGame->extraLifeAnimTimer = 90;
            else
            {
                gCurrentPinballGame->rampUpgradeFromPrize = 1;
                gCurrentPinballGame->ballUpgradeTriggered = 1;
                gCurrentPinballGame->ballUpgradeAnimTimer = 60;
                m4aSongNumStart(SE_UNKNOWN_0xD8);
            }

            gCurrentPinballGame->rampPrizeType = 0;
            gCurrentPinballGame->rampPrizeCooldown = 600;
            return;
        }

        if (gCurrentPinballGame->outLaneSaverTimer != 0)
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
                gCurrentPinballGame->outLaneSaverTimer = 120;
            return;
        }

        gCurrentPinballGame->outLaneSaverTimer = 120;
        return;

    case 11:
        if (gCurrentPinballGame->impactVelocitySampleCooldown != 0)
            return;

        absVelY = gCurrentPinballGame->ball->velocity.y;
        gCurrentPinballGame->lastBallImpactVelocityY = gCurrentPinballGame->ball->velocity.y;

        if (absVelY < 0) {
            absVelY = -absVelY;
        }

        gCurrentPinballGame->pikaChargeTarget += (absVelY) / 3;

        if (gCurrentPinballGame->pikaChargeTarget > 168)
            gCurrentPinballGame->pikaChargeTarget = 168;

        gCurrentPinballGame->impactVelocitySampleCooldown = 20;
        return;
    case 12:
        if (gCurrentPinballGame->hatchCaveCollisionReady == 0)
            return;

        if (gCurrentPinballGame->entryAnimTimer != 0)
            return;

        if (gCurrentPinballGame->hatchCaveState != 0)
            return;

        gCurrentPinballGame->hatchCaveState++;

        gCurrentPinballGame->hatchCaveCollisionReady = 0;
        gCurrentPinballGame->collisionSubType = 0;
        gCurrentPinballGame->collisionType = 2;

        *arg2 = 0xD000;
        *arg1 = 1;
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        PlayRumble(7);
        return;
    case 13:
        if (gCurrentPinballGame->hatchCaveCollisionReady == 0)
            return;

        if (gCurrentPinballGame->entryAnimTimer != 0)
            return;

        if (gCurrentPinballGame->hatchCaveState != 1)
            return;

        gCurrentPinballGame->hatchCaveState++;
        gCurrentPinballGame->hatchCaveCollisionReady = 0;
        gCurrentPinballGame->collisionSubType = 0;
        gCurrentPinballGame->collisionType = 2;
        *arg2 = 0xCC00;
        *arg1 = 1;

        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        PlayRumble(7);
        return;
    case 14:
        if ((gCurrentPinballGame->boardState > 2) && (gCurrentPinballGame->boardState != 5))
        {
            if (gCurrentPinballGame->cyndaquilRiseHoldTimer == 0)
            {
                if (gCurrentPinballGame->hatchCaveState == 2)
                {
                    gCurrentPinballGame->collisionSubType = 0;
                    gCurrentPinballGame->collisionType = 2;
                    *arg2 = 0xC800;
                    *arg1 = 1;
                    gCurrentPinballGame->hatchCaveState++;

                    m4aSongNumStart(SE_UNKNOWN_0xB7);
                    gCurrentPinballGame->scoreAddedInFrame = 5000;
                    PlayRumble(7);
                    return;
                }
                else if (gCurrentPinballGame->hatchCaveState == 3)
                {
                    gCurrentPinballGame->collisionSubType = 0;
                    gCurrentPinballGame->collisionType = 2;
                    *arg2 = 0xC800;
                    *arg1 = 1;

                    m4aSongNumStart(SE_UNKNOWN_0xB7);
                    gCurrentPinballGame->hatchCaveHitPending = 1;
                    PlayRumble(7);
                    return;
                }
            }
        }
        else if (gCurrentPinballGame->hatchCaveCollisionReady != 0 && gCurrentPinballGame->hatchCaveState == 2)
        {
            gCurrentPinballGame->hatchCaveState++;
            gCurrentPinballGame->hatchCaveCollisionReady = 0;
            gCurrentPinballGame->collisionSubType = 0;
            gCurrentPinballGame->collisionType = 2;
            *arg2 = 0xC800;
            *arg1 = 1;

            m4aSongNumStart(SE_UNKNOWN_0xB7);
            gCurrentPinballGame->scoreAddedInFrame = 5000;
            PlayRumble(7);
        }

        break;
    }
}


s16 COLLISION_CHECK_SAPPHIRE_16090(struct Vector16 *arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 tileIndex;
    s32 mapSection;
    s32 mapBaseIndex;

    u32 some_enum;
    u8 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    mapSection = vec1.y / 64;
    mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
    vec1.y %= 64;

    tileIndex = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckSapphireBumperCollision(arg0, &sp00, &sp02);

    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballStartX - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballStartY - 8)
            {

                if (gCurrentPinballGame->ball->spin > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spin != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0x28;
                        gCurrentPinballGame->ball->spin = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0xFFD8;
                        gCurrentPinballGame->ball->spin = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }

            }
        }
        return_val = 1;
        break;
    case 3:
    case 2:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    }

    CheckSapphireAbsorbZoneHit((s32) some_enum, &return_val, arg1);
    return return_val;
}

void CheckSapphireBumperCollision(struct Vector16 *arg0, s16 *arg1, u8 *arg2) {

    s16 deltaX;
    s16 deltaY;
    u16 maskedResult = 0;
    u8 lowerNibble = 0;
    s32 ix = 0;

    if (gCurrentPinballGame->ballCollisionDisabled == 0)
    {
        if (gCurrentPinballGame->collisionMapIndex != 0)
            return;

        deltaX = arg0->x + gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
        deltaY = arg0->y + gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

        if (deltaX <= 63U && deltaY <= 63U)
        {
            maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
            lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
            ix = 0;
        }
         if (lowerNibble == 0)
        {
            deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[1].x + arg0->x;
            deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[1].y + arg0->y;

            if (deltaX <= 63U && deltaY <= 63U)
            {
                maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                ix = 1;
            }

            if (lowerNibble == 0)
            {
                deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[2].x + arg0->x;
                deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[2].y + arg0->y;

                if (deltaX <= 63U && deltaY <= 63U)
                {
                    maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }
        gCurrentPinballGame->pondBumperAnimState[ix] = 6;

        *arg1 = maskedResult;
        *arg2 = lowerNibble;

        if (gCurrentPinballGame->bumperHitCountdown <= 0)
            gCurrentPinballGame->bumperHitCountdown = 2;
    }
}


void CheckSapphireAbsorbZoneHit(u8 arg0, u16* arg1, u16* arg2)
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
        if (gCurrentPinballGame->entryAnimTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ1.x >= 200)
                gCurrentPinballGame->boardEntryMode = 1;
            else
                gCurrentPinballGame->boardEntryMode = 3;

            InitSapphireBoardEntryMode();
            gCurrentPinballGame->collisionType = 7;
            *arg1 = 1;
        }
        break;
    case 2:
        if (gCurrentPinballGame->collisionMapIndex == 0)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->collisionMapIndex = 2;
        }
        else if (gCurrentPinballGame->collisionMapIndex == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->collisionMapIndex = 3;
        }
        else if (gCurrentPinballGame->collisionMapIndex == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 1;
        }
        break;
    case 3:
        if (gCurrentPinballGame->collisionMapIndex == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 3;
            gCurrentPinballGame->collisionMapIndex = 0;
        }
        else if (gCurrentPinballGame->collisionMapIndex == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->collisionMapIndex = 2;
        }
        break;
    case 4:
        if (gCurrentPinballGame->triggerButtonCooldown == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.y < 260)
            {
                if (gCurrentPinballGame->ball->positionQ0.x < 74)
                {
                    if (gCurrentPinballGame->boardState < 3 && gCurrentPinballGame->targetAnimPhase[1] < 3)
                    {
                        if (gCurrentPinballGame->targetAnimPhase[1] == 1)
                            gCurrentPinballGame->targetHitCountdown[1] = 6;
                        else
                            gCurrentPinballGame->targetHitCountdown[1] = 4;

                        gCurrentPinballGame->targetAnimSubframe[1] = 0;
                        gCurrentPinballGame->targetAnimPhase[1] = 1;
                        PlayRumble(7);

                        gCurrentPinballGame->ball->velocity.x /= 2;
                        gCurrentPinballGame->ball->velocity.y /= 2;

                        memcpy(&gCurrentPinballGame->boardState34[1], &gCurrentPinballGame->boardState34[0], sizeof(*gCurrentPinballGame->boardState34));

                        gCurrentPinballGame->boardState30 = &gCurrentPinballGame->boardState34[1];
                        gCurrentPinballGame->boardState28 = 25;
                    }
                }
                else if (gCurrentPinballGame->ball->positionQ0.x < 116)
                {
                    if (gCurrentPinballGame->boardState < 3 && gCurrentPinballGame->targetAnimPhase[0] < 3)
                    {
                        if (gCurrentPinballGame->targetAnimPhase[0] == 1)
                            gCurrentPinballGame->targetHitCountdown[0] = 6;
                        else
                            gCurrentPinballGame->targetHitCountdown[0] = 4;

                        gCurrentPinballGame->targetAnimSubframe[0] = 0;
                        gCurrentPinballGame->targetAnimPhase[0] = 1;

                        PlayRumble(7);

                        gCurrentPinballGame->ball->velocity.x /= 2;
                        gCurrentPinballGame->ball->velocity.y /= 2;

                        memcpy(&gCurrentPinballGame->boardState34[1], &gCurrentPinballGame->boardState34[0], sizeof(*gCurrentPinballGame->boardState34));

                        gCurrentPinballGame->boardState30 = &gCurrentPinballGame->boardState34[1];
                        gCurrentPinballGame->boardState28 = 25;
                    }
                }
                else
                {
                    gCurrentPinballGame->entityMovementTimer = 1800;
                    gCurrentPinballGame->pelipperState = 1;

                    if (gCurrentPinballGame->bonusMultiplier < 99)
                        gCurrentPinballGame->bonusMultiplier++;

                    gCurrentPinballGame->scoreAddedInFrame = 5000;
                }
            }
            else
            {
                if (gCurrentPinballGame->ball->positionQ0.x < 110)
                {
                    gCurrentPinballGame->seedotHitFlag = 1;
                    gCurrentPinballGame->ball->velocity.y /= 2;
                }
                else
                {
                    if (gCurrentPinballGame->zigzagoonKickState == 0)
                        gCurrentPinballGame->zigzagoonKickState = 1;
                    else
                        gCurrentPinballGame->zigzagoonKickState = 0;

                    gCurrentPinballGame->ball->velocity.y /=2;
                    gCurrentPinballGame->scoreAddedInFrame = 3000;
                }
            }

            gCurrentPinballGame->triggerButtonCooldown = 45;
            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
        }
        break;
    case 5:
        gCurrentPinballGame->hitFlashActive = 1;
        gCurrentPinballGame->tiltDetected = 1;
        gCurrentPinballGame->boardTargetState = 0;
        gCurrentPinballGame->edgeBallSideFlag = 0;
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
            gCurrentPinballGame->edgeBallSideFlag = 1;
        break;
    case 7:
        if (gCurrentPinballGame->trapDoorGfxState != 3)
        {
            gCurrentPinballGame->mosaicShakeTimer = 17;
            gCurrentPinballGame->collisionSubType = 0;
            gCurrentPinballGame->collisionType = 2;
            *arg2 = 0xD800;
            *arg1 = 1;
        }
        break;
    case 8:
        x0Position = gCurrentPinballGame->ball->positionQ0.x;
        if (gCurrentPinballGame->collisionMapIndex > 0)
        {
            if (gCurrentPinballGame->boardTargetState == 7)
            {
                gCurrentPinballGame->coinsTotalToCollect = 10;
                if (gCurrentPinballGame->scoreMultiplierLevel < 3)
                {
                    if (gCurrentPinballGame->scoreMultiplierLevel == 0)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                        gCurrentPinballGame->coinsTotalToCollect = 1;
                    }
                    else if (gCurrentPinballGame->scoreMultiplierLevel == 1)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                        gCurrentPinballGame->coinsTotalToCollect = 5;
                    }
                    else
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 10000;
                        gCurrentPinballGame->coinsTotalToCollect = 10;
                    }

                    gCurrentPinballGame->scoreMultiplierLevel++;
                }

                gCurrentPinballGame->coinAnimFrameCounter = 0;
                gCurrentPinballGame->scoreMultiplierDecayTimer = 0;
            }

            gCurrentPinballGame->boardTargetState = 1;
        }
        else
        {
            if (x0Position <= 72)
            {
                if (gCurrentPinballGame->boardTargetState == 8)
                {
                    if (gCurrentPinballGame->boardState < 3 && gCurrentPinballGame->savedEvoHitCount < 3)
                    {
                        if (gCurrentPinballGame->savedEvoHitCount == 0)
                            gCurrentPinballGame->scoreAddedInFrame = 2000;
                        else if (gCurrentPinballGame->savedEvoHitCount == 1)
                            gCurrentPinballGame->scoreAddedInFrame = 5000;
                        else
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        
                        gCurrentPinballGame->savedEvoHitCount++;
                        m4aSongNumStart(SE_UNKNOWN_0x99);
                    }

                    gCurrentPinballGame->travelModeProgress = 1;
                }

                gCurrentPinballGame->boardTargetState = 2;
            }
            else if (x0Position <= 98)
            {
                if (gCurrentPinballGame->ballPowerUpLight[0] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[0] = 1;
                gCurrentPinballGame->boardTargetState = 3;

                if (gCurrentPinballGame->ballUpgradeTriggered == 0 && (gCurrentPinballGame->ballPowerUpLight[1] & gCurrentPinballGame->ballPowerUpLight[2]))
                {
                    gCurrentPinballGame->ballUpgradeTriggered = 1;
                    gCurrentPinballGame->ballUpgradeAnimTimer = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else if (x0Position <= 118)
            {
                if (gCurrentPinballGame->ballPowerUpLight[1] == 0) 
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[1] = 1;
                gCurrentPinballGame->boardTargetState = 4;

                if (gCurrentPinballGame->ballUpgradeTriggered == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[2]))
                {
                    gCurrentPinballGame->ballUpgradeTriggered = 1;
                    gCurrentPinballGame->ballUpgradeAnimTimer = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else if (x0Position <= 146)
            {
                if (gCurrentPinballGame->ballPowerUpLight[2] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[2] = 1;
                gCurrentPinballGame->boardTargetState = 5;

                if (gCurrentPinballGame->ballUpgradeTriggered == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[1]))
                {
                    gCurrentPinballGame->ballUpgradeTriggered = 1;
                    gCurrentPinballGame->ballUpgradeAnimTimer = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else
            {
                if (gCurrentPinballGame->boardTargetState == 9)
                {
                    if (gCurrentPinballGame->boardState <= 2 && gCurrentPinballGame->savedCatchArrows < 3)
                    {
                        if (gCurrentPinballGame->savedCatchArrows == 0)
                            gCurrentPinballGame->scoreAddedInFrame = 2000;
                        else if (gCurrentPinballGame->savedCatchArrows == 1)
                            gCurrentPinballGame->scoreAddedInFrame = 5000;
                        else
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        
                        gCurrentPinballGame->savedCatchArrows++;

                        if (gCurrentPinballGame->pikaChargeSegment == 13)
                            m4aSongNumStart(SE_UNKNOWN_0x99);

                        if (gCurrentPinballGame->savedCatchArrows > 1)
                            gCurrentPinballGame->catchArrowIndicatorBlink = 1;
                    }

                    gCurrentPinballGame->travelModeProgress = 2;
                }

                gCurrentPinballGame->boardTargetState = 6;
            }
        }
        break;
    case 9:
        x0Position = gCurrentPinballGame->ball->positionQ0.x;
        if (gCurrentPinballGame->collisionMapIndex > 0)
            gCurrentPinballGame->boardTargetState = 7;
        else if (x0Position <= 50)
            gCurrentPinballGame->boardTargetState = 8;
        else
            gCurrentPinballGame->boardTargetState = 9;
        break;
    case 10:
        if (gCurrentPinballGame->ball->positionQ0.x <= 46)
        {
            gCurrentPinballGame->boardTargetState = 10;
            if (gCurrentPinballGame->holeIndicators[0] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[0] = 1;
                if (gCurrentPinballGame->allHolesCompleted == 0 && (
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[2] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->allHolesCompleted = 1;
                    gCurrentPinballGame->holeCompletionFlashTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 120)
        {
            gCurrentPinballGame->boardTargetState = 11;

            if (gCurrentPinballGame->holeIndicators[1] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[1] = 1; 
                if (gCurrentPinballGame->allHolesCompleted == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[2] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->allHolesCompleted = 1;
                    gCurrentPinballGame->holeCompletionFlashTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 193)
        {
            gCurrentPinballGame->boardTargetState = 12;
            if (gCurrentPinballGame->holeIndicators[2] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[2] = 1;

                if (gCurrentPinballGame->allHolesCompleted == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->allHolesCompleted = 1;
                    gCurrentPinballGame->holeCompletionFlashTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else
        {
            gCurrentPinballGame->boardTargetState = 13;
            if (gCurrentPinballGame->holeIndicators[3] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[3] = 1;
                if (gCurrentPinballGame->allHolesCompleted == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[2]))
                {
                    gCurrentPinballGame->allHolesCompleted = 1;
                    gCurrentPinballGame->holeCompletionFlashTimer = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        break;
    case 11:
        if (gCurrentPinballGame->outLaneSaverTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x <= 120)
                gCurrentPinballGame->outLaneSide = 1;
            else
                gCurrentPinballGame->outLaneSide = 2;

            if (gCurrentPinballGame->outLanePikaPosition < 2)
            {
                if (gCurrentPinballGame->outLanePikaPosition == gCurrentPinballGame->outLaneSide - 1)
                    gCurrentPinballGame->outLaneSaverTimer = 120;
            }
            else
            {
                gCurrentPinballGame->outLaneSaverTimer = 120;
            }
        }
        break;
    case 12:
        if (gCurrentPinballGame->impactVelocitySampleCooldown == 0)
        {
            absVelY = gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->lastBallImpactVelocityY = absVelY;
            if (absVelY < 0)
                absVelY = -absVelY;

            gCurrentPinballGame->pikaChargeTarget = gCurrentPinballGame->pikaChargeTarget + (absVelY / 3);
            if (gCurrentPinballGame->pikaChargeTarget > 168)
                gCurrentPinballGame->pikaChargeTarget = 168;

            gCurrentPinballGame->impactVelocitySampleCooldown = 20;
        }
        break;
    case 13:
        if (gCurrentPinballGame->boardTargetState != 14)
        {
            gCurrentPinballGame->boardTargetState = 14;
            index = gUnknown_086ACE70[gCurrentPinballGame->edgeTargetHitIndex];
            gCurrentPinballGame->edgeTargetFlashTimers[index] = 10;
            gCurrentPinballGame->edgeTargetHitIndex++;
            if (gCurrentPinballGame->edgeTargetHitIndex == 3)
            {
                memcpy(&gCurrentPinballGame->boardState34[1], &gCurrentPinballGame->boardState34[0], sizeof(*gCurrentPinballGame->boardState34));
                gCurrentPinballGame->boardState30 = &gCurrentPinballGame->boardState34[1];
                if (gCurrentPinballGame->edgeBallSideFlag)
                    gCurrentPinballGame->cyndaquilHitPending = 1;
            }

            if (gCurrentPinballGame->edgeTargetHitIndex == 11)
                gCurrentPinballGame->boardState30 = gCurrentPinballGame->boardState34;

            modRes = (gCurrentPinballGame->edgeTargetHitIndex - 1) % 4;
            gMain.spriteGroups[modRes + 47].available = 1;
            gCurrentPinballGame->edgeHitFxAnimFrame[modRes] = 0;
            gCurrentPinballGame->edgeHitFxSubframe[modRes] = 0;
            gCurrentPinballGame->edgeHitFxTargetIndex[modRes] = gCurrentPinballGame->edgeTargetHitIndex - 1;

            if (gCurrentPinballGame->edgeTargetHitIndex > 12)
                gCurrentPinballGame->edgeTargetHitIndex = 0;

            if (index == 0 && gCurrentPinballGame->ball->velocity.y > -120)
                gCurrentPinballGame->ball->velocity.y = -120;

            if (index == 2 && gCurrentPinballGame->ball->velocity.y > -180)
                gCurrentPinballGame->ball->velocity.y = -180;
        }
        break;
    case 14:
        if (gCurrentPinballGame->boardTargetState != 15)
        {
            gCurrentPinballGame->boardTargetState = 15;
            index = gUnknown_086ACE70[gCurrentPinballGame->edgeTargetHitIndex];
            gCurrentPinballGame->edgeTargetFlashTimers[index] = 10;
            gCurrentPinballGame->edgeTargetHitIndex++;

            modRes = (gCurrentPinballGame->edgeTargetHitIndex -1) % 4;
            gMain.spriteGroups[modRes + 47].available = 1;
            gCurrentPinballGame->edgeHitFxAnimFrame[modRes] = 0;
            gCurrentPinballGame->edgeHitFxSubframe[modRes] = 0;
            gCurrentPinballGame->edgeHitFxTargetIndex[modRes] = gCurrentPinballGame->edgeTargetHitIndex - 1;
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
                gCurrentPinballGame->entityMovementTimer = 0;
            }
        }

        break;
    }
}

s16 COLLISION_CHECK_DUSCLOPS_171C8(struct Vector16* arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 tileIndex;
    s32 mapSection;
    s32 mapBaseIndex;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    mapSection = vec1.y / 64;
    mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
    vec1.y %= 64;
    tileIndex = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckDusclopsEntitiesCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballStartX - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballStartY - 8)
            {

                if (gCurrentPinballGame->ball->spin > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spin != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0x28;
                        gCurrentPinballGame->ball->spin = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0xFFD8;
                        gCurrentPinballGame->ball->spin = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }

            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    CheckDusclopsAbzorbZoneHit(some_enum, &return_val, arg1);
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

        deltaX = arg0->x -gCurrentPinballGame->entityCollisionOriginX;
        deltaY = arg0->y -gCurrentPinballGame->entityCollisionOriginY;

        if (deltaX > 95U || deltaY > 119U)
            return;

        maskedResult = 0xFFF0 & gUnknown_083071D4[(deltaY * 96 ) + deltaX];
        lowerNibble = 0xF & gUnknown_083071D4[(deltaY * 96 ) + deltaX];

        if (lowerNibble == 0)
            return;

        //Can be hit when ready to absorb (2) or when walking (3)
        temp = gCurrentPinballGame->entityState -3;
        if (temp <= 1U)
            *arg2 = 1;
        else
            *arg2 = lowerNibble;

        gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_HIT;
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
                maskedResult = 0xFFF0 & gUnknown_08252B10[deltaY * 64 + deltaX];
                lowerNibble = 0xF & gUnknown_08252B10[deltaY * 64 + deltaX];

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
                    maskedResult = 0xFFF0 & gUnknown_08252B10[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[deltaY * 64 + deltaX];

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
                    maskedResult = 0xFFF0 & gUnknown_08252B10[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[deltaY * 64 + deltaX];

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

void CheckDusclopsAbzorbZoneHit(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_HIT_ABSORB_ZONE;
        gCurrentPinballGame->ballLockState = 1;
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

s16 COLLISION_CHECK_KECLEON_176B0(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 tileIndex;
    s32 mapSection;
    s32 mapBaseIndex;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    mapSection = vec1.y / 64;
    mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
    vec1.y %= 64;
    tileIndex = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckKecleonEntitiesCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00;
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSubType = 0;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        if (gCurrentPinballGame->kecleonScopeDropActive == 0)
        {
            s32 scopeHitFlag = gCurrentPinballGame->kecleonScopeHitFlag;
            if (scopeHitFlag == 0)
            {
                gCurrentPinballGame->kecleonScopeDropActive = 1;
                gCurrentPinballGame->kecleonScopeDropTimer = scopeHitFlag;
            }
        }
        gCurrentPinballGame->kecleonBallHitFlashTimer = 40;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    CheckKecleonAbsorbZoneHit(some_enum, &return_val, arg1);
    return return_val;
}

void CheckKecleonEntitiesCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;

    if (gCurrentPinballGame->boardEntityCollisionMode == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->entityCollisionOriginX;
        deltaY = arg0->y - gCurrentPinballGame->entityCollisionOriginY;

        if ((deltaX < 0 || deltaX > 0x3F) || (deltaY < 0 || deltaY > 0x57))
            return;

        arrayValue = (u8)(gUnknown_0832D604[(deltaY * 0x40) + deltaX]) & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->isGrabbed != 0)
            return;
        if (gCurrentPinballGame->entityState > 8)
            return;

        gCurrentPinballGame->entityState = 9;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 2)
    {
        u16 maskedResult;

        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->entityCollisionOriginX;
        deltaY = arg0->y - gCurrentPinballGame->entityCollisionOriginY;

        if ((deltaX < 0 || deltaX > 0x57) || (deltaY < 0 || deltaY > 0x3F))
            return;

        maskedResult = gUnknown_08330204[(deltaY * 0x58) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_08330204[(deltaY * 0x58) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->isGrabbed != 0)
            return;
        if (gCurrentPinballGame->entityState == 12)
            return;

        gCurrentPinballGame->entityState = 11;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void CheckKecleonAbsorbZoneHit(u8 arg0, u16 *arg1, u16 *arg2)
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
                if (gCurrentPinballGame->kecleonBumperHitTimers[0] <= 0)
                    gCurrentPinballGame->kecleonBumperHitTimers[0] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBumperHitTimers[1] <= 0)
                    gCurrentPinballGame->kecleonBumperHitTimers[1] = 0x18;
            }
        }
        else if (y <= 0x63)
        {
            if (gCurrentPinballGame->kecleonBumperHitTimers[3] <= 0)
                gCurrentPinballGame->kecleonBumperHitTimers[3] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBumperHitTimers[2] <= 0)
                gCurrentPinballGame->kecleonBumperHitTimers[2] = 0x18;
        }
        break;
    case 9:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->hitFlashTimers[7] <= 0)
                    gCurrentPinballGame->hitFlashTimers[7] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->hitFlashTimers[5] <= 0)
                    gCurrentPinballGame->hitFlashTimers[5] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->hitFlashTimers[8] <= 0)
                gCurrentPinballGame->hitFlashTimers[8] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->hitFlashTimers[0] <= 0)
                gCurrentPinballGame->hitFlashTimers[0] = 0x18;
        }
        break;
    case 10:
        if (gCurrentPinballGame->kecleonTileAnimFrame == 0)
        {
            gCurrentPinballGame->kecleonTargetHitTimers[0] = 0xB;
            gCurrentPinballGame->ballTrailPositions[0].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPositions[0].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->kecleonTileAnimFrame == 3)
        {
            gCurrentPinballGame->kecleonTargetHitTimers[1] = 0xB;
            gCurrentPinballGame->ballTrailPositions[1].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPositions[1].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->kecleonTileAnimFrame == 6)
        {
            gCurrentPinballGame->kecleonTargetHitTimers[2] = 0xB;
            gCurrentPinballGame->ballTrailPositions[2].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPositions[2].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->kecleonTileAnimFrame == 9)
        {
            gCurrentPinballGame->kecleonTargetHitTimers[3] = 0xB;
            gCurrentPinballGame->ballTrailPositions[3].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPositions[3].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        break;
    case 11:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->hitFlashTimers[9] <= 0)
                    gCurrentPinballGame->hitFlashTimers[9] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->hitFlashTimers[2] <= 0)
                    gCurrentPinballGame->hitFlashTimers[2] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->hitFlashTimers[6] <= 0)
                gCurrentPinballGame->hitFlashTimers[6] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->hitFlashTimers[1] <= 0)
                gCurrentPinballGame->hitFlashTimers[1] = 0x18;
        }
        break;
    case 12:
        if (x <= 0x72)
        {
            if (gCurrentPinballGame->hitFlashTimers[4] <= 0)
                gCurrentPinballGame->hitFlashTimers[4] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->hitFlashTimers[3] <= 0)
                gCurrentPinballGame->hitFlashTimers[3] = 0x18;
        }
        break;
    }
}

void ProcessKecleonBoardCollisionFlash(struct Vector16 *arg0)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    s16 x, y;
    u16 sp00;
    u8 sp02;
    s16 tileIndex;
    s32 mapSection;
    s32 mapBaseIndex;
    u32 some_enum;

    gCurrentPinballGame->kecleonAttackFxSlot = 1;
    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    mapSection = vec1.y / 64;
    mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
    vec1.y %= 64;
    tileIndex = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];

    some_enum = (sp02 >> 2) >> 2;

    x = gCurrentPinballGame->kecleonScreenPos.x;
    y = gCurrentPinballGame->kecleonScreenPos.y;

    switch (some_enum)
    {
    case 8:
        if (x <= 0x72)
        {
            if (y <= 0x38)
            {
                if (gCurrentPinballGame->kecleonBumperHitTimers[0] <= 0)
                    gCurrentPinballGame->kecleonBumperHitTimers[0] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBumperHitTimers[1] <= 0)
                    gCurrentPinballGame->kecleonBumperHitTimers[1] = 0x18;
            }
        }
        else if (y <= 0x63)
        {
            if (gCurrentPinballGame->kecleonBumperHitTimers[3] <= 0)
                gCurrentPinballGame->kecleonBumperHitTimers[3] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->kecleonBumperHitTimers[2] <= 0)
                gCurrentPinballGame->kecleonBumperHitTimers[2] = 0x18;
        }
        break;
    case 9:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->hitFlashTimers[7] <= 0)
                    gCurrentPinballGame->hitFlashTimers[7] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->hitFlashTimers[5] <= 0)
                    gCurrentPinballGame->hitFlashTimers[5] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->hitFlashTimers[8] <= 0)
                gCurrentPinballGame->hitFlashTimers[8] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->hitFlashTimers[0] <= 0)
                gCurrentPinballGame->hitFlashTimers[0] = 0x18;
        }
        break;
    case 10:
        gCurrentPinballGame->kecleonAttackFxSlot = 0;
        if (gCurrentPinballGame->kecleonWallAnimFrame == 0)
        {
            if (gCurrentPinballGame->kecleonScreenPos.x != gCurrentPinballGame->kecleonPrevBallHitPos[0].x || gCurrentPinballGame->kecleonScreenPos.y != gCurrentPinballGame->kecleonPrevBallHitPos[0].y)
            {
                gCurrentPinballGame->kecleonTargetHitTimers[4] = 0x11;
                gCurrentPinballGame->kecleonPrevBallHitPos[0].x = gCurrentPinballGame->kecleonScreenPos.x;
                gCurrentPinballGame->kecleonPrevBallHitPos[0].y = gCurrentPinballGame->kecleonScreenPos.y;
            }
        }
        else if (gCurrentPinballGame->kecleonWallAnimFrame == 8)
        {
            if (gCurrentPinballGame->kecleonScreenPos.x != gCurrentPinballGame->kecleonPrevBallHitPos[1].x || gCurrentPinballGame->kecleonScreenPos.y != gCurrentPinballGame->kecleonPrevBallHitPos[1].y)
            {
                gCurrentPinballGame->kecleonTargetHitTimers[5] = 0x11;
                gCurrentPinballGame->kecleonPrevBallHitPos[1].x = gCurrentPinballGame->kecleonScreenPos.x;
                gCurrentPinballGame->kecleonPrevBallHitPos[1].y = gCurrentPinballGame->kecleonScreenPos.y;
            }
        }
        else if (gCurrentPinballGame->kecleonWallAnimFrame == 16)
        {
            if (gCurrentPinballGame->kecleonScreenPos.x != gCurrentPinballGame->kecleonPrevBallHitPos[2].x || gCurrentPinballGame->kecleonScreenPos.y != gCurrentPinballGame->kecleonPrevBallHitPos[2].y)
            {
                gCurrentPinballGame->kecleonTargetHitTimers[6] = 0x11;
                gCurrentPinballGame->kecleonPrevBallHitPos[2].x = gCurrentPinballGame->kecleonScreenPos.x;
                gCurrentPinballGame->kecleonPrevBallHitPos[2].y = gCurrentPinballGame->kecleonScreenPos.y;
            }
        }
        break;
    case 11:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->hitFlashTimers[9] <= 0)
                    gCurrentPinballGame->hitFlashTimers[9] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->hitFlashTimers[2] <= 0)
                    gCurrentPinballGame->hitFlashTimers[2] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->hitFlashTimers[6] <= 0)
                gCurrentPinballGame->hitFlashTimers[6] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->hitFlashTimers[1] <= 0)
                gCurrentPinballGame->hitFlashTimers[1] = 0x18;
        }
        break;
    case 12:
        if (x <= 0x72)
        {
            if (gCurrentPinballGame->hitFlashTimers[4] <= 0)
                gCurrentPinballGame->hitFlashTimers[4] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->hitFlashTimers[3] <= 0)
                gCurrentPinballGame->hitFlashTimers[3] = 0x18;
        }
        break;
    }
}

s16 COLLISION_CHECK_KYOGRE_17F28(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 tileIndex;
    s32 mapSection;
    s32 mapBaseIndex;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;
    if (arg0->y < 0x200)
    {
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        mapSection = vec1.y / 64;
        mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
        vec1.y %= 64;
        tileIndex = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
        sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];
        sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][tileIndex * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckKyogreEntitiesCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballStartX - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballStartY - 8)
            {

                if (gCurrentPinballGame->ball->spin > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spin != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0x28;
                        gCurrentPinballGame->ball->spin = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinImpulse = 0xFFD8;
                        gCurrentPinballGame->ball->spin = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }

            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    CheckKyogreAbsorbZoneHit(some_enum, &return_val, arg1);
    return return_val;
}

void CheckKyogreEntitiesCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;
    u16 maskedResult;

    if (gCurrentPinballGame->boardEntityCollisionMode == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->entityCollisionOriginX;
        deltaY = arg0->y - gCurrentPinballGame->entityCollisionOriginY;

        if ((deltaX < 0 || deltaX >= 0x78) || (deltaY < 0 || deltaY >= 0x98))
            return;

        maskedResult = gUnknown_08340B58[(deltaY * 0x78) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_08340B58[(deltaY * 0x78) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitReactionTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 2)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->entityCollisionOriginX;
        deltaY = arg0->y - gCurrentPinballGame->entityCollisionOriginY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x58))
            return;

        maskedResult = gUnknown_083499D8[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_083499D8[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitReactionTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 3)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->entityCollisionOriginX;
        deltaY = arg0->y - gCurrentPinballGame->entityCollisionOriginY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x68))
            return;

        maskedResult = gUnknown_0834DBD8[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_0834DBD8[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitReactionTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void CheckKyogreAbsorbZoneHit(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->entityState = 6;
        gCurrentPinballGame->ballLockState = 1;
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

s16 COLLISION_CHECK_GROUDON_18324(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 mapSection;
        s32 mapBaseIndex;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        mapSection = vec1.y / 64;
        mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
        vec1.y %= 64;
        r2 = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
        sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckGroudonEntitiesCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballStartX - 8) || gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballStartY - 8)
            {
                if (gCurrentPinballGame->ball->spin > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spin != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinImpulse = 40;
                        gCurrentPinballGame->ball->spin = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinImpulse = -40;
                        gCurrentPinballGame->ball->spin = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    CheckGroudonAbsorbZoneHit(some_enum, &return_val, arg1);
    return return_val;
}

void CheckGroudonEntitiesCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
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
            deltaX = arg0->x - gCurrentPinballGame->entityCollisionOriginX;
            deltaY = arg0->y - gCurrentPinballGame->entityCollisionOriginY;

            if ((deltaX >= 0 && deltaX < 0x70) && (deltaY >= 0 && deltaY < 0x80))
            {
                resultFromArray = gUnknown_083579C8[(deltaY * 0x70) + deltaX];
                maskedResult = resultFromArray & 0xFFF0;
                lowerNibble = resultFromArray & 0xF;
                if (lowerNibble != 0)
                {
                    if (gCurrentPinballGame->bossHitReactionTimer == 0)
                        gCurrentPinballGame->bossHitReactionTimer = 0x27;

                    *arg1 = maskedResult;
                    *arg2 = lowerNibble;
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->fireRockCollisionPos[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->fireRockCollisionPos[i].x;
        deltaY = arg0->y - gCurrentPinballGame->fireRockCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->fireRockBallHitFlag[i] = 1;
    }
    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->rockCollisionPos[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->rockCollisionPos[i].x;
        deltaY = arg0->y - gCurrentPinballGame->rockCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->rockHitReactionTimer[i] = 8;
    }
}

void CheckGroudonAbsorbZoneHit(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->entityState = 6;
        gCurrentPinballGame->ballLockState = 1;
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
s16 COLLISION_CHECK_RAYQUAZA_187F4(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 mapSection;
        s32 mapBaseIndex;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        mapSection = vec1.y / 64;
        mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
        vec1.y %= 64;
        r2 = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][vec1.y * 64 + vec1.x];
        sp00 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckRayquazaEntitiesCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballStartX - 8) || gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballStartY - 8)
            {
                if (gCurrentPinballGame->ball->spin > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spin != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinImpulse = 40;
                        gCurrentPinballGame->ball->spin = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinImpulse = -40;
                        gCurrentPinballGame->ball->spin = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSubType = switch_enum - 1;
        gCurrentPinballGame->collisionType = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    CheckRayquazaAbsorbZoneHit(some_enum, &return_val, arg1);
    return return_val;
}

void CheckRayquazaEntitiesCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u16 lowerNibble;

    if (gCurrentPinballGame->boardEntityCollisionMode != 1)
        return;
    if (*arg2 & 0xF)
        return;

    deltaX = arg0->x - gCurrentPinballGame->entityCollisionOriginX;
    deltaY = arg0->y - gCurrentPinballGame->entityCollisionOriginY;

    if ((deltaX < 0 || deltaX >= 0x80) || (deltaY < 0 || deltaY >= 0x80))
        return;

    maskedResult = gUnknown_083722E8[(deltaY * 0x80) + deltaX] & 0xFFF0;
    lowerNibble = gUnknown_083722E8[(deltaY * 0x80) + deltaX] & 0xF;

    if (lowerNibble == 0)
        return;

    gCurrentPinballGame->bossHitReactionTimer = 9;
    *arg1 = maskedResult;
    *arg2 = lowerNibble;
}

void CheckRayquazaAbsorbZoneHit(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->entityState = 6;
        gCurrentPinballGame->ballLockState = 1;
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

s16 COLLISION_CHECK_SPHEAL_18B50(struct Vector16 *arg0, u16 *arg1)
{
    u16 sp0;
    u8 sp2;
    u16 sp4_return;

    struct Vector16 div_result;
    struct Vector16 div_remainder;
    s32 mapSection;
    s32 mapBaseIndex;
    s16 tileIndex2;
    u8 enum1, enum2;

    sp4_return = 0;
    gCurrentPinballGame->ball->spinImpulse = 0;

    div_result.x = arg0->x / 8;
    div_result.y = arg0->y / 8;
    div_remainder.x = arg0->x % 8;
    div_remainder.y = arg0->y % 8;
    mapSection = div_result.y / 64;
    mapBaseIndex = gCurrentPinballGame->collisionMapIndex;
    div_result.y %= 64;

    tileIndex2 = gBoardConfig.fieldLayout.collisionTileMap[mapBaseIndex + mapSection][div_result.y * 64 + div_result.x];
    sp0 = gBoardConfig.fieldLayout.collisionPropertyMap[mapBaseIndex + mapSection][tileIndex2 * 64 + div_remainder.y * 8 + div_remainder.x];
    sp2 = gBoardConfig.fieldLayout.collisionSubtypeMap[mapBaseIndex + mapSection][tileIndex2 * 64 + div_remainder.y * 8 + div_remainder.x];

    CheckSphealEntitiesCollision(arg0, &sp0, &sp2);

    enum1 = sp2 & 0xF;
    enum2 = sp2 >> 4;
    switch (enum1)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSubType = enum1 - 1;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp0;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballStartX - 8) ||
                gCurrentPinballGame->ball->positionQ0.y < (gBoardConfig.fieldLayout.ballStartY - 8))
            {
                if (gCurrentPinballGame->ball->spin > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spin != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinImpulse = 40;
                        gCurrentPinballGame->ball->spin = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinImpulse = -40;
                        gCurrentPinballGame->ball->spin = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        sp4_return = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSubType = 0;
        gCurrentPinballGame->collisionType = 1;
        *arg1 = sp0 & 0x0000FFF0;

        if (gCurrentPinballGame->ball->positionQ0.x < 120)
            gCurrentPinballGame->sealHitStunTimer[0] = 24;
        else
            gCurrentPinballGame->sealHitStunTimer[1] = 24;

        sp4_return = 1;
        break;
    case 5:
        enum2 = 4;
        break;
    }

    CheckSphealAbsorbZoneHit(enum2, &sp4_return, arg1);
    return sp4_return;
}

void CheckSphealEntitiesCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 i;
    s16 deltaX, deltaY;
    u16 lowerReadFromRom;
    u16 upperReadFromRom;
    for (i = 0; i < 2; i++)
    {

        if (gCurrentPinballGame->entityMovePhase[i] == 1)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->entityLogicPos[i].x;
            deltaY = arg0->y - gCurrentPinballGame->entityLogicPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gUnknown_08393A4C[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gUnknown_08393A4C[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            if (gCurrentPinballGame->bonusCaptureState != 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            gCurrentPinballGame->entityAIState[i] = 4;
        }
        else if (gCurrentPinballGame->entityMovePhase[i] != 0)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->entityLogicPos[i].x;
            deltaY = arg0->y - gCurrentPinballGame->entityLogicPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gUnknown_08391A4C[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gUnknown_08391A4C[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            if (gCurrentPinballGame->entityMovePhase[i] == 2)
            {
                gCurrentPinballGame->entityAIState[i] = 4;
            }
            else
            {
                gCurrentPinballGame->entityHitCooldown[i] = 24;
            }
        }
    }
}

void CheckSphealAbsorbZoneHit(u8 arg0_enum, u16 *arg1, u16 *arg2)
{
    switch (arg0_enum)
    {
    case 2:
        gCurrentPinballGame->sealBounceActiveSide[2] = 0;
        gCurrentPinballGame->sealBounceAnimState[2] = 2;
        break;
    case 3:
        gCurrentPinballGame->sealBounceActiveSide[2] = 1;
        gCurrentPinballGame->sealBounceAnimState[2] = 2;
        break;
    case 8:
        gCurrentPinballGame->sealBounceActiveSide[2] = 0;
        gCurrentPinballGame->sealBounceAnimState[2] = 1;
        gCurrentPinballGame->sealBounceInvulnTimer[2] = 100;
        break;
    case 9:
        gCurrentPinballGame->sealBounceActiveSide[2] = 1;
        gCurrentPinballGame->sealBounceAnimState[2] = 1;
        gCurrentPinballGame->sealBounceInvulnTimer[2] = 100;
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