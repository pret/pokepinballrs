#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"

extern const u32 gBallSpawnGlowTiles_Type1[][0x80];
extern const u32 gBallSpawnGlowTiles_Type2[][0x80];

//Called once per frame; 7th process, Draws the ball & related graphics
void MainBoardProcess_7B_12524(void)
{
    s16 i;
    struct OamDataSimple *oam;
    struct OamData *oamData;
    struct BallState *currentBallState;
    struct SpriteGroup *spriteGroup;
    s16 r8;

    currentBallState = gCurrentPinballGame->ball;
    r8 = currentBallState->spinAngle >> 12;

    if (currentBallState->positionQ0.y == 340 && (currentBallState->positionQ0.x == 90 || currentBallState->positionQ0.x == 149))
        currentBallState->spinAngle = currentBallState->prevSpinAngle;

    currentBallState->prevSpinAngle = currentBallState->spinAngle;

    if (!gCurrentPinballGame->ballUpgradeTimerPaused && gCurrentPinballGame->ballUpgradeTimer > 0)
    {
        if (--gCurrentPinballGame->ballUpgradeTimer == 0)
        {
            if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
            {
                gCurrentPinballGame->ballUpgradeType--;

                if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                    gCurrentPinballGame->ballUpgradeTimer = TICKS_FOR_TIME(1,0);
            }

            DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(1), PLTT_SLOT_SIZE);
        }
    }

    if (currentBallState->positionQ0.y >= 244)
    {
        gCurrentPinballGame->ballInLowerHalf = TRUE;
        gCurrentPinballGame->pondEntitySpriteFlag = 0;
    }
    else
        gCurrentPinballGame->ballInLowerHalf = FALSE;

    currentBallState->positionQ0.x = currentBallState->positionQ1.x / 2;
    currentBallState->positionQ0.y = currentBallState->positionQ1.y / 2;

    spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_BALL];

    if (spriteGroup->active)
    {
        SetMatrixScale(currentBallState->scale, currentBallState->scale, 0);

        spriteGroup->baseX = -(gCurrentPinballGame->cameraBaseX + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->screenShakeX;
        spriteGroup->baseY = -(gCurrentPinballGame->cameraBaseY + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->cameraScrollOffset - gCurrentPinballGame->cameraYAdjust + gCurrentPinballGame->spoinkPullbackYDistance;

        currentBallState->screenPosition.x = spriteGroup->baseX;
        currentBallState->screenPosition.y = spriteGroup->baseY;

        oam = &spriteGroup->oam[0];
        oamData = &gOamBuffer[oam->oamId];

        if (currentBallState->oamPriority == 3)
        {
            if (currentBallState->positionQ0.y > 248)
                oamData->priority = 2;
            else
                oamData->priority = 3;
        }
        else
            oamData->priority = currentBallState->oamPriority;

        r8 = r8; // this fools the compiler into thinking r8 holds something that could need sign extending/truncation
        DmaCopy16(3, gBallRotationTileGraphics[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)OBJ_VRAM0 + 0x400, 0x80);

        if (spriteGroup->baseY > 200)
            spriteGroup->baseY = 200;

        if (spriteGroup->baseY < -20)
            spriteGroup->baseY = -20;

        oamData->x = oam->xOffset + spriteGroup->baseX;

        if (currentBallState->ballHidden)
            oamData->y = 200;
        else
            oamData->y = oam->yOffset + spriteGroup->baseY;
    }

    spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_OVERRIDE];

    if (spriteGroup->active)
    {
        SetMatrixScale(currentBallState->scale, currentBallState->scale, 0);

        spriteGroup->baseX = -(gCurrentPinballGame->cameraBaseX + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->screenShakeX;
        spriteGroup->baseY = -(gCurrentPinballGame->cameraBaseY + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->cameraScrollOffset - gCurrentPinballGame->cameraYAdjust + gCurrentPinballGame->spoinkPullbackYDistance;

        currentBallState->screenPosition.x = spriteGroup->baseX;
        currentBallState->screenPosition.y = spriteGroup->baseY;

        oam = &spriteGroup->oam[0];
        oamData = &gOamBuffer[oam->oamId];

        if (currentBallState->oamPriority == 3)
        {
            if (currentBallState->positionQ0.y > 248)
                oamData->priority = 2;
            else
                oamData->priority = 3;
        }
        else
            oamData->priority = currentBallState->oamPriority;

        DmaCopy16(3, gBallRotationTileGraphics[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)OBJ_VRAM0 + 0x400, 0x80);

        if (spriteGroup->baseY > 200)
            spriteGroup->baseY = 200;

        if (spriteGroup->baseY < -20)
            spriteGroup->baseY = -20;

        oamData->x = oam->xOffset + spriteGroup->baseX;

        if (currentBallState->ballHidden)
            oamData->y = 200;
        else
            oamData->y = oam->yOffset + spriteGroup->baseY;
    }

    for (i = 4; i > 0; i--)
    {
        gCurrentPinballGame->ballTrailPosition[i].x = gCurrentPinballGame->ballTrailPosition[(i - 1)].x;
        gCurrentPinballGame->ballTrailPosition[i].y = gCurrentPinballGame->ballTrailPosition[(i - 1)].y;
    }

    gCurrentPinballGame->ballTrailPosition[0].x = currentBallState->positionQ0.x - 7;
    gCurrentPinballGame->ballTrailPosition[0].y = currentBallState->positionQ0.y - 7;

    if (gCurrentPinballGame->ballTrailEnabled)
    {
        for (i = 0; i < 2; i++)
        {
            spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_TRAIL_BASE + i];

            if (spriteGroup->active)
            {
                oam = &spriteGroup->oam[0];
                oamData = &gOamBuffer[oam->oamId];

                oamData->priority = currentBallState->oamPriority;
                oamData->x = oam->xOffset + (gCurrentPinballGame->ballTrailPosition[(i + 1) * 2].x - gCurrentPinballGame->cameraBaseX);

                if (i == 0)
                    oamData->y = gCurrentPinballGame->ballTrailPosition[2].y - gCurrentPinballGame->cameraBaseY + oam->yOffset;
                else if (i == 1)
                {
                    if (gMain.systemFrameCount % 2 == 0)
                        oamData->y = gCurrentPinballGame->ballTrailPosition[4].y - gCurrentPinballGame->cameraBaseY + oam->yOffset;
                    else
                        oamData->y = 200;
                }
            }
        }

        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_TRAIL_0]->active = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_TRAIL_1]->active = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_OVERRIDE]->active = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = FALSE;
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_TRAIL_BASE + i];

            if (spriteGroup->active)
            {
                oam = &spriteGroup->oam[0];
                oamData = &gOamBuffer[oam->oamId];

                oamData->priority = currentBallState->oamPriority;
                oamData->x = oam->xOffset + (gCurrentPinballGame->ballTrailPosition[(i + 1) * 2].x - gCurrentPinballGame->cameraBaseX);
                oamData->y = 200;
            }
        }

        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_TRAIL_0]->active = FALSE;
        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_TRAIL_1]->active = FALSE;
        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_BALL_OVERRIDE]->active = FALSE;
        gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = TRUE;
    }

    spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_BALL_UPGRADE_FX];

    if (spriteGroup->active)
    {
        s8 newIx;
        if (gCurrentPinballGame->gBallUpgradeFxTimer < 59)
        {
            spriteGroup->baseX = gMain.fieldSpriteGroups[FIELD_SG_BALL]->baseX - 8;
            spriteGroup->baseY = gMain.fieldSpriteGroups[FIELD_SG_BALL]->baseY - 8;
        }
        else
        {
            spriteGroup->baseX = 0;
            spriteGroup->baseY = 180;
        }

        newIx = gCurrentPinballGame->ballUpgradeFxTileIndex;
        DmaCopy16(3, gBallUpgradeFx_Gfx[newIx], (void *)0x6011EE0, 0x200);

        oam = &spriteGroup->oam[0];

        gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;

        gOamBuffer[oam->oamId].priority = currentBallState->oamPriority;

        if (gCurrentPinballGame->gBallUpgradeFxTimer < 14)
            gMain.fieldSpriteGroups[FIELD_SG_BALL_UPGRADE_FX]->active = FALSE;
    }
}

//Called once per frame; 7th process, Draws the ball & related graphics
void BonusBoardProcess_7B_12BF8()
{
    s16 i;
    s16 r5;
    struct SpriteGroup *spriteGroup;
    struct OamData *oamData;
    struct OamDataSimple *oam;
    struct BallState *primaryBall;

    gCurrentPinballGame->cameraBall = gCurrentPinballGame->ballStates;
    gCurrentPinballGame->ball = gCurrentPinballGame->ballStates;

    primaryBall = &gCurrentPinballGame->ballStates[0];

    switch (gMain.selectedField)
    {
    case FIELD_KECLEON:
        primaryBall->oamPriority = 2;
        spriteGroup = &gMain.spriteGroups[gKecleonSpriteGroupOrderMap[22]];
        break;
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_SPHEAL:
        primaryBall->oamPriority = 1;
        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_BALL];
        break;
    case FIELD_RAYQUAZA:
        if (primaryBall->oamPriority > 2)
            primaryBall->oamPriority = 2;
        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_BALL];
        break;
    default:
        primaryBall->oamPriority = 3;
        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_BALL];
        break;
    }

    r5 = gCurrentPinballGame->ball->spinAngle >> 12;
    DmaCopy16(3, &gBallRotationTileGraphics[r5 + gCurrentPinballGame->ballUpgradeType * 17], (void *)OBJ_VRAM0 + 0x400, 0x80);

    primaryBall->positionQ0.x = primaryBall->positionQ1.x / 2;
    primaryBall->positionQ0.y = primaryBall->positionQ1.y / 2;

    spriteGroup->baseX = primaryBall->positionQ0.x
        - (gCurrentPinballGame->cameraBaseX + 7)
        - gCurrentPinballGame->screenShakeX;
    spriteGroup->baseY = primaryBall->positionQ0.y
        - 7
        - gCurrentPinballGame->cameraBaseY
        - gCurrentPinballGame->cameraScrollOffset
        - gCurrentPinballGame->cameraYAdjust
        - gCurrentPinballGame->screenShakeY
        - (gCurrentPinballGame->ballWhirlwindLiftY / 10);

    if (spriteGroup->baseY < -60)
        spriteGroup->baseY = -60;

    if (spriteGroup->baseY > 180)
        spriteGroup->baseY = 180;

    primaryBall->screenPosition.x = spriteGroup->baseX;
    primaryBall->screenPosition.y = spriteGroup->baseY;

    oam = &spriteGroup->oam[0];
    oamData = &gOamBuffer[oam->oamId];
    oamData->priority = primaryBall->oamPriority;
    oamData->x = oam->xOffset + spriteGroup->baseX;

    if (primaryBall->ballHidden)
        oamData->y = 200;
    else
        oamData->y = oam->yOffset + spriteGroup->baseY;

    if (gCurrentPinballGame->ballRespawnState)
    {
        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_BONUS_BOARD_BALL_RESPAWN_FX];
        if (spriteGroup->active)
        {
            spriteGroup->baseX = primaryBall->screenPosition.x - 8;
            spriteGroup->baseY = primaryBall->screenPosition.y - 8;
            oam = &spriteGroup->oam[0];
            gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
            gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;
        }

        if (gCurrentPinballGame->ballRespawnState == BALL_SPAWN_STATE_RESPAWN
            || gCurrentPinballGame->ballRespawnState == BALL_SPAWN_STATE_INITIAL_SPAWN)
        {
            if (gCurrentPinballGame->ballRespawnTimer == 0)
            {
                gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
                primaryBall->velocity.x = 0;
                primaryBall->velocity.y = 0;
                primaryBall->spinSpeed = 0;
            }

            if (gCurrentPinballGame->ballRespawnTimer == 150)
                spriteGroup->active = TRUE;

            if (gCurrentPinballGame->ballRespawnTimer == 154)
                m4aSongNumStart(SE_BONUS_BOARD_BALL_SPAWN);

            if (gCurrentPinballGame->ballRespawnTimer > 149)
            {
                r5 = ((gCurrentPinballGame->ballRespawnTimer - 150) % 66) / 6;
                DmaCopy16(3, &gBallSpawnGlowTiles_Type1[r5], (void *)OBJ_VRAM0 + 0x720, 0x200);
                primaryBall->spinSpeed -= 40;
            }

            if ((gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS) == 0) 
            {
                gCurrentPinballGame->ballRespawnTimer++;
                if (r5 >= 7 && r5 <= 10)
                {
                    DmaCopy16(3, gBall_Pals[(s16) (gCurrentPinballGame->ballUpgradeType + 4)], OBJ_PLTT_SLOT(1), PLTT_SLOT_SIZE);
                }
            }

            if (gCurrentPinballGame->ballRespawnTimer == 186)
                primaryBall->ballHidden = FALSE;

            if (gCurrentPinballGame->ballRespawnTimer > 215)
            {
                if (gCurrentPinballGame->ballRespawnState == BALL_SPAWN_STATE_INITIAL_SPAWN)
                    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_RUNNING;

                gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_LIVE_BALL;
                spriteGroup->active = FALSE;
                gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(1), PLTT_SLOT_SIZE);
            }
        }
        else
        {
            if (gCurrentPinballGame->ballRespawnTimer == 0)
            {
                gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
                primaryBall->velocity.x = 0;
                primaryBall->velocity.y = 0;
                primaryBall->spinSpeed = 0;
            }

            if (gCurrentPinballGame->ballRespawnTimer == 5)
                spriteGroup->active = TRUE;

            if (gCurrentPinballGame->ballRespawnTimer > 4)
            {
                r5 = ((gCurrentPinballGame->ballRespawnTimer - 5) % 63 / 7);
                DmaCopy16(3, &gBallSpawnGlowTiles_Type2[r5], (void *)OBJ_VRAM0 + 0x720, 0x200);
                primaryBall->spinSpeed -= 20;
            }

            if ((gMain.modeChangeFlags & ~MODE_CHANGE_BONUS_BANNER) == 0)
                gCurrentPinballGame->ballRespawnTimer++;

            if (gCurrentPinballGame->ballRespawnTimer == 23)
                m4aSongNumStart(SE_BONUS_BOARD_BALL_SPAWN);

            if (gCurrentPinballGame->ballRespawnTimer == 20)
                primaryBall->ballHidden = TRUE;

            if (gCurrentPinballGame->ballRespawnTimer > 67)
            {
                gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_LIVE_BALL;
                spriteGroup->active = FALSE;
                DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(1), PLTT_SLOT_SIZE);
            }
        }
    }
    else
    {
        if (!gCurrentPinballGame->ballUpgradeTimerPaused && gCurrentPinballGame->ballUpgradeTimer != 0)
        {
            gCurrentPinballGame->ballUpgradeTimer--;
            if (gCurrentPinballGame->ballUpgradeTimer == 0)
            {
                if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                {
                    gCurrentPinballGame->ballUpgradeType--;
                    if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                    {
                        gCurrentPinballGame->ballUpgradeTimer = TICKS_FOR_TIME(1,0);
                    }
                }
                DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(1), PLTT_SLOT_SIZE);
            }
        }
    }

    switch (gMain.selectedField) {
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_RAYQUAZA:
        if (gCurrentPinballGame->ballTrailEnabled)
        {
            for (i = 4; i > 0; i--)
            {
                gCurrentPinballGame->ballTrailPosition[i].x = gCurrentPinballGame->ballTrailPosition[i - 1].x;
                gCurrentPinballGame->ballTrailPosition[i].y = gCurrentPinballGame->ballTrailPosition[i - 1].y;
            }
            gCurrentPinballGame->ballTrailPosition[0].x = primaryBall->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPosition[0].y = primaryBall->positionQ0.y - 7;

            for (i = 0; i < 2; i++)
            {
                spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_BONUS_BOARD_BALL_TRAIL_BASE + i];
                if (spriteGroup->active)
                {
                    oam = &spriteGroup->oam[0];
                    oamData = &gOamBuffer[oam->oamId];
                    oamData->priority = primaryBall->oamPriority;
                    oamData->x = oam->xOffset
                        + (gCurrentPinballGame->ballTrailPosition[(i + 1) * 2].x
                        - gCurrentPinballGame->cameraBaseX);

                    if (i == 0)
                    {
                        oamData->y = oam->yOffset
                            + (gCurrentPinballGame->ballTrailPosition[2].y
                            - gCurrentPinballGame->cameraBaseY
                            - gCurrentPinballGame->cameraYAdjust);
                    }
                    else if (i == 1)
                    {
                        if ((gMain.systemFrameCount & i) == 0)
                        {
                            oamData->y = oam->yOffset
                                + (gCurrentPinballGame->ballTrailPosition[4].y
                                - gCurrentPinballGame->cameraBaseY
                                - gCurrentPinballGame->cameraYAdjust);
                        }
                        else
                        {
                            oamData->y = 200;
                        }
                    }
                }
            }
            gMain.fieldSpriteGroups[FIELD_SG_BONUS_BOARD_BALL_TRAIL_0]->active = TRUE;
            gMain.fieldSpriteGroups[FIELD_SG_BONUS_BOARD_BALL_TRAIL_1]->active = TRUE;
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                spriteGroup = gMain.fieldSpriteGroups[i + 6];
                if (spriteGroup->active)
                {
                    oam = &spriteGroup->oam[0];
                    oamData = &gOamBuffer[oam->oamId];
                    oamData->priority = primaryBall->oamPriority;
                    oamData->x = oam->xOffset
                        + (gCurrentPinballGame->ballTrailPosition[(i + 1) * 2].x - gCurrentPinballGame->cameraBaseX);
                    oamData->y = 200;
                }
            }
            gMain.fieldSpriteGroups[FIELD_SG_BONUS_BOARD_BALL_TRAIL_0]->active = FALSE;
            gMain.fieldSpriteGroups[FIELD_SG_BONUS_BOARD_BALL_TRAIL_1]->active = FALSE;
        }
    }
}
