#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"

extern const u32 gBallSpawnGlowTiles_Type1[][0x80];
extern const u32 gBallSpawnGlowTiles_Type2[][0x80];

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

    if (!gCurrentPinballGame->ballUpgradeTimerFrozen && gCurrentPinballGame->ballUpgradeCounter > 0)
    {
        if (--gCurrentPinballGame->ballUpgradeCounter == 0)
        {
            if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
            {
                gCurrentPinballGame->ballUpgradeType--;

                if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                    gCurrentPinballGame->ballUpgradeCounter = 3600;
            }

            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
        }
    }

    if (currentBallState->positionQ0.y >= 244)
    {
        gCurrentPinballGame->ballInLowerHalf = 1;
        gCurrentPinballGame->pondEntitySpriteFlag = 0;
    }
    else
        gCurrentPinballGame->ballInLowerHalf = 0;

    currentBallState->positionQ0.x = currentBallState->positionQ1.x / 2;
    currentBallState->positionQ0.y = currentBallState->positionQ1.y / 2;

    spriteGroup = gMain.fieldSpriteGroups[0];

    if (spriteGroup->available)
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
        DmaCopy16(3, gBallRotationTileGraphics[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)0x6010400, 0x80);

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

    spriteGroup = gMain.fieldSpriteGroups[49];

    if (spriteGroup->available)
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

        DmaCopy16(3, gBallRotationTileGraphics[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)0x6010400, 0x80);

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
            spriteGroup = gMain.fieldSpriteGroups[i + 1];

            if (spriteGroup->available)
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

        gMain.fieldSpriteGroups[1]->available = 1;
        gMain.fieldSpriteGroups[2]->available = 1;
        gMain.fieldSpriteGroups[49]->available = 1;
        gMain.fieldSpriteGroups[0]->available = 0;
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            spriteGroup = gMain.fieldSpriteGroups[i + 1];

            if (spriteGroup->available)
            {
                oam = &spriteGroup->oam[0];
                oamData = &gOamBuffer[oam->oamId];

                oamData->priority = currentBallState->oamPriority;
                oamData->x = oam->xOffset + (gCurrentPinballGame->ballTrailPosition[(i + 1) * 2].x - gCurrentPinballGame->cameraBaseX);
                oamData->y = 200;
            }
        }

        gMain.fieldSpriteGroups[1]->available = 0;
        gMain.fieldSpriteGroups[2]->available = 0;
        gMain.fieldSpriteGroups[49]->available = 0;
        gMain.fieldSpriteGroups[0]->available = 1;
    }

    spriteGroup = gMain.fieldSpriteGroups[43];

    if (spriteGroup->available)
    {
        s8 newIx;
        if (gCurrentPinballGame->ballShadowTimer < 59)
        {
            spriteGroup->baseX = gMain.fieldSpriteGroups[0]->baseX - 8;
            spriteGroup->baseY = gMain.fieldSpriteGroups[0]->baseY - 8;
        }
        else
        {
            spriteGroup->baseX = 0;
            spriteGroup->baseY = 180;
        }

        newIx = gCurrentPinballGame->ballShadowTileIndex;
        DmaCopy16(3, gBallShadowTileGraphics[newIx], (void *)0x6011EE0, 0x200);

        oam = &spriteGroup->oam[0];

        gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;

        gOamBuffer[oam->oamId].priority = currentBallState->oamPriority;

        if (gCurrentPinballGame->ballShadowTimer < 14)
            gMain.fieldSpriteGroups[43]->available = 0;
    }
}

void BonusBoardProcess_7B_12BF8()
{
    s16 i;
    s16 r5;
    struct SpriteGroup *spriteGroup;
    struct OamData *oamData;
    struct OamDataSimple *oam;
    struct BallState *primaryBall;

    gCurrentPinballGame->secondaryBall = gCurrentPinballGame->ballStates;
    gCurrentPinballGame->ball = gCurrentPinballGame->ballStates;

    primaryBall = &gCurrentPinballGame->ballStates[0];

    switch (gMain.selectedField)
    {
    case FIELD_KECLEON:
        primaryBall->oamPriority = 2;
        spriteGroup = &gMain_spriteGroups[gKecleonSpriteOrderMap[22]];
        break;
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_SPHEAL:
        primaryBall->oamPriority = 1;
        spriteGroup = gMain.fieldSpriteGroups[0];
        break;
    case FIELD_RAYQUAZA:
        if (primaryBall->oamPriority > 2)
            primaryBall->oamPriority = 2;
        spriteGroup = gMain.fieldSpriteGroups[0];
        break;
    default:
        primaryBall->oamPriority = 3;
        spriteGroup = gMain.fieldSpriteGroups[0];
        break;
    }

    r5 = gCurrentPinballGame->ball->spinAngle >> 12;
    DmaCopy16(3, &gBallRotationTileGraphics[r5 + gCurrentPinballGame->ballUpgradeType * 17], (void *)VRAM + 0x10400, 0x80);

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
        - (gCurrentPinballGame->bossRenderOffsetY / 10);

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
        spriteGroup = gMain.fieldSpriteGroups[1];
        if (spriteGroup->available)
        {
            spriteGroup->baseX = primaryBall->screenPosition.x - 8;
            spriteGroup->baseY = primaryBall->screenPosition.y - 8;
            oam = &spriteGroup->oam[0];
            gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
            gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;
        }

        if (gCurrentPinballGame->ballRespawnState == 1 || gCurrentPinballGame->ballRespawnState == 3)
        {
            if (gCurrentPinballGame->ballRespawnTimer == 0)
            {
                gCurrentPinballGame->ballFrozenState = 1;
                primaryBall->velocity.x = 0;
                primaryBall->velocity.y = 0;
                primaryBall->spinSpeed = 0;
            }

            if (gCurrentPinballGame->ballRespawnTimer == 150)
                spriteGroup->available = TRUE;

            if (gCurrentPinballGame->ballRespawnTimer == 154)
                m4aSongNumStart(SE_UNKNOWN_0xF9);

            if (gCurrentPinballGame->ballRespawnTimer > 149)
            {
                r5 = ((gCurrentPinballGame->ballRespawnTimer - 150) % 66) / 6;
                DmaCopy16(3, &gBallSpawnGlowTiles_Type1[r5], (void *)VRAM + 0x10720, 0x200);
                primaryBall->spinSpeed -= 40;
            }

            if ((gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS) == 0) 
            {
                gCurrentPinballGame->ballRespawnTimer++;
                if (r5 >= 7 && r5 <= 10)
                {
                    DmaCopy16(3, &gBallPalettes[(s16) (gCurrentPinballGame->ballUpgradeType + 4)], (void *)PLTT + 0x220, 0x20);
                }
            }

            if (gCurrentPinballGame->ballRespawnTimer == 186)
                primaryBall->ballHidden = 0;

            if (gCurrentPinballGame->ballRespawnTimer > 215)
            {
                if (gCurrentPinballGame->ballRespawnState == 3)
                    gCurrentPinballGame->boardModeType = 2;

                gCurrentPinballGame->ballRespawnState = 0;
                spriteGroup->available = FALSE;
                gCurrentPinballGame->ballFrozenState = 0;
                DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
            }
        }
        else
        {
            if (gCurrentPinballGame->ballRespawnTimer == 0)
            {
                gCurrentPinballGame->ballFrozenState = 1;
                primaryBall->velocity.x = 0;
                primaryBall->velocity.y = 0;
                primaryBall->spinSpeed = 0;
            }

            if (gCurrentPinballGame->ballRespawnTimer == 5)
                spriteGroup->available = TRUE;

            if (gCurrentPinballGame->ballRespawnTimer > 4)
            {
                r5 = ((gCurrentPinballGame->ballRespawnTimer - 5) % 63 / 7);
                DmaCopy16(3, &gBallSpawnGlowTiles_Type2[r5], (void *)VRAM + 0x10720, 0x200);
                primaryBall->spinSpeed -= 20;
            }

            if ((gMain.modeChangeFlags & ~MODE_CHANGE_BONUS_BANNER) == 0)
                gCurrentPinballGame->ballRespawnTimer++;

            if (gCurrentPinballGame->ballRespawnTimer == 23)
                m4aSongNumStart(SE_UNKNOWN_0xF9);

            if (gCurrentPinballGame->ballRespawnTimer == 20)
                primaryBall->ballHidden = 1;

            if (gCurrentPinballGame->ballRespawnTimer > 67)
            {
                gCurrentPinballGame->ballRespawnState = 0;
                spriteGroup->available = FALSE;
                DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->ballUpgradeTimerFrozen == 0 && gCurrentPinballGame->ballUpgradeCounter != 0)
        {
            gCurrentPinballGame->ballUpgradeCounter--;
            if (gCurrentPinballGame->ballUpgradeCounter == 0)
            {
                if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                {
                    gCurrentPinballGame->ballUpgradeType--;
                    if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                    {
                        gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
                    }
                }
                DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
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
                spriteGroup = gMain.fieldSpriteGroups[i + 6];
                if (spriteGroup->available)
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
            gMain.fieldSpriteGroups[6]->available = TRUE;
            gMain.fieldSpriteGroups[7]->available = TRUE;
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                spriteGroup = gMain.fieldSpriteGroups[i + 6];
                if (spriteGroup->available)
                {
                    oam = &spriteGroup->oam[0];
                    oamData = &gOamBuffer[oam->oamId];
                    oamData->priority = primaryBall->oamPriority;
                    oamData->x = oam->xOffset
                        + (gCurrentPinballGame->ballTrailPosition[(i + 1) * 2].x - gCurrentPinballGame->cameraBaseX);
                    oamData->y = 200;
                }
            }
            gMain.fieldSpriteGroups[6]->available = FALSE;
            gMain.fieldSpriteGroups[7]->available = FALSE;
        }
    }
}
