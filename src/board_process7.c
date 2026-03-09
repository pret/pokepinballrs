#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"

extern const u32 gUnknown_083BF16C[][0x80];
extern const u32 gUnknown_083BDF6C[][0x80];

void MainBoardProcess_7B_12524(void)
{
    s16 i;
    struct OamDataSimple *oam;
    struct OamData *oamData;
    struct BallState *currentBallState;
    struct SpriteGroup *spriteGroup;
    s16 r8;

    currentBallState = gCurrentPinballGame->ball;
    r8 = currentBallState->rotation >> 12;

    if (currentBallState->positionQ0.y == 340 && (currentBallState->positionQ0.x == 90 || currentBallState->positionQ0.x == 149))
        currentBallState->rotation = currentBallState->prevRotation;

    currentBallState->prevRotation = currentBallState->rotation;

    if (!gCurrentPinballGame->ballLocked && gCurrentPinballGame->ballUpgradeCounter > 0)
    {
        if (--gCurrentPinballGame->ballUpgradeCounter == 0)
        {
            if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
            {
                gCurrentPinballGame->ballUpgradeType--;

                if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                    gCurrentPinballGame->ballUpgradeCounter = 3600;
            }

            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
        }
    }

    if (currentBallState->positionQ0.y >= 244)
    {
        gCurrentPinballGame->ballCollisionDisabled = 1;
        gCurrentPinballGame->bumperHitCount = 0;
    }
    else
        gCurrentPinballGame->ballCollisionDisabled = 0;

    currentBallState->positionQ0.x = currentBallState->positionQ1.x / 2;
    currentBallState->positionQ0.y = currentBallState->positionQ1.y / 2;

    spriteGroup = gMain.boardSpriteGroups[0];

    if (spriteGroup->available)
    {
        SetMatrixScale(currentBallState->scale, currentBallState->scale, 0);

        spriteGroup->baseX = -(gCurrentPinballGame->cameraScrollX + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->bossShakeOffsetX;
        spriteGroup->baseY = -(gCurrentPinballGame->cameraScrollY + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->scrollNudgeY - gCurrentPinballGame->fieldScrollOffsetY + gCurrentPinballGame->hitFlashOffsetY;

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
        DmaCopy16(3, gUnknown_083BB16C[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)0x6010400, 0x80);

        if (spriteGroup->baseY > 200)
            spriteGroup->baseY = 200;

        if (spriteGroup->baseY < -20)
            spriteGroup->baseY = -20;

        oamData->x = oam->xOffset + spriteGroup->baseX;

        if (currentBallState->isGrabbed)
            oamData->y = 200;
        else
            oamData->y = oam->yOffset + spriteGroup->baseY;
    }

    spriteGroup = gMain.boardSpriteGroups[49];

    if (spriteGroup->available)
    {
        SetMatrixScale(currentBallState->scale, currentBallState->scale, 0);

        spriteGroup->baseX = -(gCurrentPinballGame->cameraScrollX + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->bossShakeOffsetX;
        spriteGroup->baseY = -(gCurrentPinballGame->cameraScrollY + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->scrollNudgeY - gCurrentPinballGame->fieldScrollOffsetY + gCurrentPinballGame->hitFlashOffsetY;

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

        DmaCopy16(3, gUnknown_083BB16C[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)0x6010400, 0x80);

        if (spriteGroup->baseY > 200)
            spriteGroup->baseY = 200;

        if (spriteGroup->baseY < -20)
            spriteGroup->baseY = -20;

        oamData->x = oam->xOffset + spriteGroup->baseX;

        if (currentBallState->isGrabbed)
            oamData->y = 200;
        else
            oamData->y = oam->yOffset + spriteGroup->baseY;
    }

    for (i = 4; i > 0; i--)
    {
        gCurrentPinballGame->ballTrailPositions[i].x = gCurrentPinballGame->ballTrailPositions[(i - 1)].x;
        gCurrentPinballGame->ballTrailPositions[i].y = gCurrentPinballGame->ballTrailPositions[(i - 1)].y;
    }

    gCurrentPinballGame->ballTrailPositions[0].x = currentBallState->positionQ0.x - 7;
    gCurrentPinballGame->ballTrailPositions[0].y = currentBallState->positionQ0.y - 7;

    if (gCurrentPinballGame->ballTrailRenderFlag)
    {
        for (i = 0; i < 2; i++)
        {
            spriteGroup = gMain.boardSpriteGroups[i + 1];

            if (spriteGroup->available)
            {
                oam = &spriteGroup->oam[0];
                oamData = &gOamBuffer[oam->oamId];

                oamData->priority = currentBallState->oamPriority;
                oamData->x = oam->xOffset + (gCurrentPinballGame->ballTrailPositions[(i + 1) * 2].x - gCurrentPinballGame->cameraScrollX);

                if (i == 0)
                    oamData->y = gCurrentPinballGame->ballTrailPositions[2].y - gCurrentPinballGame->cameraScrollY + oam->yOffset;
                else if (i == 1)
                {
                    if (gMain.systemFrameCount % 2 == 0)
                        oamData->y = gCurrentPinballGame->ballTrailPositions[4].y - gCurrentPinballGame->cameraScrollY + oam->yOffset;
                    else
                        oamData->y = 200;
                }
            }
        }

        gMain.boardSpriteGroups[1]->available = 1;
        gMain.boardSpriteGroups[2]->available = 1;
        gMain.boardSpriteGroups[49]->available = 1;
        gMain.boardSpriteGroups[0]->available = 0;
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            spriteGroup = gMain.boardSpriteGroups[i + 1];

            if (spriteGroup->available)
            {
                oam = &spriteGroup->oam[0];
                oamData = &gOamBuffer[oam->oamId];

                oamData->priority = currentBallState->oamPriority;
                oamData->x = oam->xOffset + (gCurrentPinballGame->ballTrailPositions[(i + 1) * 2].x - gCurrentPinballGame->cameraScrollX);
                oamData->y = 200;
            }
        }

        gMain.boardSpriteGroups[1]->available = 0;
        gMain.boardSpriteGroups[2]->available = 0;
        gMain.boardSpriteGroups[49]->available = 0;
        gMain.boardSpriteGroups[0]->available = 1;
    }

    spriteGroup = gMain.boardSpriteGroups[43];

    if (spriteGroup->available)
    {
        s8 newIx;
        if (gCurrentPinballGame->ballUpgradeAnimTimer < 59)
        {
            spriteGroup->baseX = gMain.boardSpriteGroups[0]->baseX - 8;
            spriteGroup->baseY = gMain.boardSpriteGroups[0]->baseY - 8;
        }
        else
        {
            spriteGroup->baseX = 0;
            spriteGroup->baseY = 180;
        }

        newIx = gCurrentPinballGame->ballUpgradeGfxFrame;
        DmaCopy16(3, gUnknown_083BD36C[newIx], (void *)0x6011EE0, 0x200);

        oam = &spriteGroup->oam[0];

        gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;

        gOamBuffer[oam->oamId].priority = currentBallState->oamPriority;

        if (gCurrentPinballGame->ballUpgradeAnimTimer < 14)
            gMain.boardSpriteGroups[43]->available = 0;
    }
}

void BonusBoardProcess_7B_12BF8()
{
    s16 i;
    s16 r5;
    struct SpriteGroup *spriteGroup;
    struct OamData *oamData;
    struct OamDataSimple *oam;
    struct BallState *unk1334_0;

    gCurrentPinballGame->ballInstancesBase = gCurrentPinballGame->ballInstances;
    gCurrentPinballGame->ball = gCurrentPinballGame->ballInstances;

    unk1334_0 = &gCurrentPinballGame->ballInstances[0];

    switch (gMain.selectedField)
    {
    case FIELD_KECLEON:
        unk1334_0->oamPriority = 2;
        spriteGroup = &gMain_spriteGroups[gSpriteSlotMap[22]];
        break;
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_SPHEAL:
        unk1334_0->oamPriority = 1;
        spriteGroup = gMain.boardSpriteGroups[0];
        break;
    case FIELD_RAYQUAZA:
        if (unk1334_0->oamPriority > 2)
            unk1334_0->oamPriority = 2;
        spriteGroup = gMain.boardSpriteGroups[0];
        break;
    default:
        unk1334_0->oamPriority = 3;
        spriteGroup = gMain.boardSpriteGroups[0];
        break;
    }

    r5 = gCurrentPinballGame->ball->rotation >> 12;
    DmaCopy16(3, &gUnknown_083BB16C[r5 + gCurrentPinballGame->ballUpgradeType * 17], (void *)VRAM + 0x10400, 0x80);

    unk1334_0->positionQ0.x = unk1334_0->positionQ1.x / 2;
    unk1334_0->positionQ0.y = unk1334_0->positionQ1.y / 2;

    spriteGroup->baseX = unk1334_0->positionQ0.x
        - (gCurrentPinballGame->cameraScrollX + 7)
        - gCurrentPinballGame->bossShakeOffsetX;
    spriteGroup->baseY = unk1334_0->positionQ0.y
        - 7
        - gCurrentPinballGame->cameraScrollY
        - gCurrentPinballGame->scrollNudgeY
        - gCurrentPinballGame->fieldScrollOffsetY
        - gCurrentPinballGame->bossShakeOffsetY
        - (gCurrentPinballGame->rayquazaSegmentAltitude / 10);

    if (spriteGroup->baseY < -60)
        spriteGroup->baseY = -60;

    if (spriteGroup->baseY > 180)
        spriteGroup->baseY = 180;

    unk1334_0->screenPosition.x = spriteGroup->baseX;
    unk1334_0->screenPosition.y = spriteGroup->baseY;

    oam = &spriteGroup->oam[0];
    oamData = &gOamBuffer[oam->oamId];
    oamData->priority = unk1334_0->oamPriority;
    oamData->x = oam->xOffset + spriteGroup->baseX;

    if (unk1334_0->isGrabbed)
        oamData->y = 200;
    else
        oamData->y = oam->yOffset + spriteGroup->baseY;

    if (gCurrentPinballGame->bonusCaptureState)
    {
        spriteGroup = gMain.boardSpriteGroups[1];
        if (spriteGroup->available)
        {
            spriteGroup->baseX = unk1334_0->screenPosition.x - 8;
            spriteGroup->baseY = unk1334_0->screenPosition.y - 8;
            oam = &spriteGroup->oam[0];
            gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
            gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;
        }

        if (gCurrentPinballGame->bonusCaptureState == 1 || gCurrentPinballGame->bonusCaptureState == 3)
        {
            if (gCurrentPinballGame->bonusSequenceTimer == 0)
            {
                gCurrentPinballGame->ballLockState = 1;
                unk1334_0->velocity.x = 0;
                unk1334_0->velocity.y = 0;
                unk1334_0->spin = 0;
            }

            if (gCurrentPinballGame->bonusSequenceTimer == 150)
                spriteGroup->available = TRUE;

            if (gCurrentPinballGame->bonusSequenceTimer == 154)
                m4aSongNumStart(SE_UNKNOWN_0xF9);

            if (gCurrentPinballGame->bonusSequenceTimer > 149)
            {
                r5 = ((gCurrentPinballGame->bonusSequenceTimer - 150) % 66) / 6;
                DmaCopy16(3, &gUnknown_083BF16C[r5], (void *)VRAM + 0x10720, 0x200);
                unk1334_0->spin -= 40;
            }

            if ((gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS) == 0) 
            {
                gCurrentPinballGame->bonusSequenceTimer++;
                if (r5 >= 7 && r5 <= 10)
                {
                    DmaCopy16(3, &gUnknown_08137E14[(s16) (gCurrentPinballGame->ballUpgradeType + 4)], (void *)PLTT + 0x220, 0x20);
                }
            }

            if (gCurrentPinballGame->bonusSequenceTimer == 186)
                unk1334_0->isGrabbed = 0;

            if (gCurrentPinballGame->bonusSequenceTimer > 215)
            {
                if (gCurrentPinballGame->bonusCaptureState == 3)
                    gCurrentPinballGame->entityActivePhase = 2;

                gCurrentPinballGame->bonusCaptureState = 0;
                spriteGroup->available = FALSE;
                gCurrentPinballGame->ballLockState = 0;
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
            }
        }
        else
        {
            if (gCurrentPinballGame->bonusSequenceTimer == 0)
            {
                gCurrentPinballGame->ballLockState = 1;
                unk1334_0->velocity.x = 0;
                unk1334_0->velocity.y = 0;
                unk1334_0->spin = 0;
            }

            if (gCurrentPinballGame->bonusSequenceTimer == 5)
                spriteGroup->available = TRUE;

            if (gCurrentPinballGame->bonusSequenceTimer > 4)
            {
                r5 = ((gCurrentPinballGame->bonusSequenceTimer - 5) % 63 / 7);
                DmaCopy16(3, &gUnknown_083BDF6C[r5], (void *)VRAM + 0x10720, 0x200);
                unk1334_0->spin -= 20;
            }

            if ((gMain.modeChangeFlags & ~MODE_CHANGE_BONUS_BANNER) == 0)
                gCurrentPinballGame->bonusSequenceTimer++;

            if (gCurrentPinballGame->bonusSequenceTimer == 23)
                m4aSongNumStart(SE_UNKNOWN_0xF9);

            if (gCurrentPinballGame->bonusSequenceTimer == 20)
                unk1334_0->isGrabbed = 1;

            if (gCurrentPinballGame->bonusSequenceTimer > 67)
            {
                gCurrentPinballGame->bonusCaptureState = 0;
                spriteGroup->available = FALSE;
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->ballLocked == 0 && gCurrentPinballGame->ballUpgradeCounter != 0)
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
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
            }
        }
    }

    switch (gMain.selectedField) {
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_RAYQUAZA:
        if (gCurrentPinballGame->ballTrailRenderFlag)
        {
            for (i = 4; i > 0; i--)
            {
                gCurrentPinballGame->ballTrailPositions[i].x = gCurrentPinballGame->ballTrailPositions[i - 1].x;
                gCurrentPinballGame->ballTrailPositions[i].y = gCurrentPinballGame->ballTrailPositions[i - 1].y;
            }
            gCurrentPinballGame->ballTrailPositions[0].x = unk1334_0->positionQ0.x - 7;
            gCurrentPinballGame->ballTrailPositions[0].y = unk1334_0->positionQ0.y - 7;

            for (i = 0; i < 2; i++)
            {
                spriteGroup = gMain.boardSpriteGroups[i + 6];
                if (spriteGroup->available)
                {
                    oam = &spriteGroup->oam[0];
                    oamData = &gOamBuffer[oam->oamId];
                    oamData->priority = unk1334_0->oamPriority;
                    oamData->x = oam->xOffset
                        + (gCurrentPinballGame->ballTrailPositions[(i + 1) * 2].x
                        - gCurrentPinballGame->cameraScrollX);

                    if (i == 0)
                    {
                        oamData->y = oam->yOffset
                            + (gCurrentPinballGame->ballTrailPositions[2].y
                            - gCurrentPinballGame->cameraScrollY
                            - gCurrentPinballGame->fieldScrollOffsetY);
                    }
                    else if (i == 1)
                    {
                        if ((gMain.systemFrameCount & i) == 0)
                        {
                            oamData->y = oam->yOffset
                                + (gCurrentPinballGame->ballTrailPositions[4].y
                                - gCurrentPinballGame->cameraScrollY
                                - gCurrentPinballGame->fieldScrollOffsetY);
                        }
                        else
                        {
                            oamData->y = 200;
                        }
                    }
                }
            }
            gMain.boardSpriteGroups[6]->available = TRUE;
            gMain.boardSpriteGroups[7]->available = TRUE;
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                spriteGroup = gMain.boardSpriteGroups[i + 6];
                if (spriteGroup->available)
                {
                    oam = &spriteGroup->oam[0];
                    oamData = &gOamBuffer[oam->oamId];
                    oamData->priority = unk1334_0->oamPriority;
                    oamData->x = oam->xOffset
                        + (gCurrentPinballGame->ballTrailPositions[(i + 1) * 2].x - gCurrentPinballGame->cameraScrollX);
                    oamData->y = 200;
                }
            }
            gMain.boardSpriteGroups[6]->available = FALSE;
            gMain.boardSpriteGroups[7]->available = FALSE;
        }
    }
}
