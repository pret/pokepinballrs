#include "global.h"
#include "variables.h"
#include "types.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/main_board.h"

void AllBoardProcess_4A_19304(void)
{
    if (gMain.selectedField >= FIELD_BONUS_START)
        BonusBoardProcess_4B_19734();
}

void DetermineFlipperBallSide(struct Vector16 arg0)
{
    s16 check;
    struct FlipperLineSegment *line;
    struct Vector16 point1, point2;

    line = &gFlipperLineGeometry[gCurrentPinballGame->flipper[0].position];
    point1.x = line->x1 + 0x53;
    point1.y = line->y1 + gBoardConfig.fieldLayout.flipperBaseY;

    point2.x = line->x2 + 0x53;
    point2.y = line->y2 + gBoardConfig.fieldLayout.flipperBaseY;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->flipper[0].ballSide = 1;
    else
        gCurrentPinballGame->flipper[0].ballSide = -1;

    line = &gFlipperLineGeometry[gCurrentPinballGame->flipper[1].position];

    point1.x = 0x9C - line->x1;
    point1.y = line->y1 + gBoardConfig.fieldLayout.flipperBaseY;

    point2.x = 0x9C - line->x2;
    point2.y = line->y2 + gBoardConfig.fieldLayout.flipperBaseY;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->flipper[1].ballSide = 1;
    else
        gCurrentPinballGame->flipper[1].ballSide = -1;
}

void MainBoardProcess_4B_19490(void)
{
    s16 i;

    if ((gMain.modeChangeFlags & MODE_CHANGE_BANNER) == 0)
        UpdateMainBoardFlipperPhysics();

    for (i = 0; i < 2; i++)
    {
        struct SpriteGroup *spriteGroup;

        if (gCurrentPinballGame->flipper[i].position > 10)
            gCurrentPinballGame->flipper[i].position = 10;
        else if (gCurrentPinballGame->flipper[i].position < 0)
            gCurrentPinballGame->flipper[i].position = 0;

        spriteGroup = &gMain.spriteGroups[10 + i];
        if (spriteGroup->available)
        {
            s8 flipperTileIndex;
            struct OamDataSimple *oamData;

            flipperTileIndex = gCurrentPinballGame->flipper[i].position / 2;
            spriteGroup->baseX = gFlipperBaseXPositions[i] - gCurrentPinballGame->cameraXOffset;
            spriteGroup->baseY = gBoardConfig.fieldLayout.flipperBaseY - gCurrentPinballGame->cameraYOffset;

            DmaCopy16(3, gFlipperTileGraphics[flipperTileIndex], OBJ_VRAM0 + i * 0x200, 0x200);

            oamData = &spriteGroup->oam[0];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
        }
    }
}

void UpdateMainBoardFlipperPhysics(void)
{
    s16 i;

    DetermineFlipperBallSide(gCurrentPinballGame->ball->positionQ0);

    for (i = 0; i < 2; i++)
    {
        s16 dir;
        struct FlipperState *flipper;
        flipper = &gCurrentPinballGame->flipper[i];

        flipper->prevPosition = flipper->position;
        flipper->collisionFrameIndex = 0;

        if (gCurrentPinballGame->heldButtonActions[i])
        {
            if (flipper->active == 0 && gCurrentPinballGame->ballCatchState == NOT_TRAPPED)
                m4aSongNumStart(SE_FLIPPER_PRESSED);

            flipper->active = 1;
            flipper->stallTicks = 0;
        }
        else
        {
            if (flipper->position == 10)
            {
                if (flipper->stallTicks > 2)
                    flipper->active = gCurrentPinballGame->heldButtonActions[i];
                flipper->stallTicks++;
            }
        }

        dir = 0;
        if (flipper->active != 0)
        {
            if (flipper->position != 10)
            {
                dir = 1;
            }
            else if (gCurrentPinballGame->flipperLaunchPending != 0)
            {
                gCurrentPinballGame->ballStates[0].velocity.x = gCurrentPinballGame->flipperLaunchVelocity.x;
                gCurrentPinballGame->ballStates[0].velocity.y = gCurrentPinballGame->flipperLaunchVelocity.y;
                gCurrentPinballGame->flipperLaunchPending = 0;
                PlayRumble(7);
            }
            flipper->collisionFrameIndex = flipper->position / 2 + 1;
            flipper->position += 4;
        }
        else
        {
            if (flipper->position != 0)
            {
                flipper->collisionFrameIndex = flipper->position / 2 + 6;
                dir = -1;
            }
            else if (gCurrentPinballGame->flipperLaunchPending != 0)
            {
                gCurrentPinballGame->ballStates[0].velocity.x = gCurrentPinballGame->flipperLaunchVelocity.x;
                gCurrentPinballGame->ballStates[0].velocity.y = gCurrentPinballGame->flipperLaunchVelocity.y;
                gCurrentPinballGame->flipperLaunchPending = 0;
                PlayRumble(7);
            }
            flipper->position -= 2;
        }
        flipper->movementDirection = flipper->movementDirection * dir;
        if (flipper->movementDirection <= 0)
            flipper->bounceApplied = 0;
        flipper->movementDirection = dir;
    }
}

void BonusBoardProcess_4B_19734(void)
{
    s16 i;
    s16 priority = 1;

    if ((gMain.modeChangeFlags & MODE_CHANGE_BANNER) == 0)
    {
        UpdateBonusBoardFlipperPhysics();
        gMain.modeChangeFlags = gMain.modeChangeFlags;
    }
    for (i = 0; i < 2; i++)
    {
        struct SpriteGroup *spriteGroup;

        if (gCurrentPinballGame->flipper[i].position > 10)
            gCurrentPinballGame->flipper[i].position = 10;
        else if (gCurrentPinballGame->flipper[i].position < 0)
            gCurrentPinballGame->flipper[i].position = 0;

        spriteGroup = &gMain.spriteGroups[3 + i];
        if (spriteGroup->available)
        {
            s8 flipperTileIndex;
            struct OamDataSimple *oamData;

            flipperTileIndex = gCurrentPinballGame->flipper[i].position / 2;
            spriteGroup->baseX = gFlipperBaseXPositions[i] - gCurrentPinballGame->cameraXOffset;
            spriteGroup->baseY = gBoardConfig.fieldLayout.flipperBaseY - gCurrentPinballGame->cameraYOffset;

            DmaCopy16(3, gFlipperTileGraphics[flipperTileIndex], OBJ_VRAM0 + i * 0x200, 0x200);

            if (spriteGroup->baseY > 180)
                spriteGroup->baseY = 180;

            oamData = &spriteGroup->oam[0];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
            gOamBuffer[oamData->oamId].priority = priority;
        }
    }
}

void UpdateBonusBoardFlipperPhysics(void)
{
    s16 i;

    DetermineFlipperBallSide(gCurrentPinballGame->ball->positionQ0);

    for (i = 0; i < 2; i++)
    {
        s16 dir;
        struct FlipperState *flipper;
        flipper = &gCurrentPinballGame->flipper[i];

        flipper->prevPosition = flipper->position;
        flipper->collisionFrameIndex = 0;

        if (gCurrentPinballGame->heldButtonActions[i] && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            if (flipper->active == 0 &&
                gCurrentPinballGame->ballCatchState == NOT_TRAPPED &&
                gCurrentPinballGame->flippersDisabled == 0)
            {
                m4aSongNumStart(SE_FLIPPER_PRESSED);
            }
            flipper->active = 1;
            flipper->stallTicks = 0;
        }
        else
        {
            if (flipper->position == 10)
            {
                if (flipper->stallTicks > 2)
                    flipper->active = 0;
                flipper->stallTicks++;
            }
        }

        dir = 0;
        if (flipper->active != 0)
        {
            if (flipper->position != 10)
            {
                dir = 1;
            }
            else if (gCurrentPinballGame->flipperLaunchPending != 0)
            {
                gCurrentPinballGame->ballStates[0].velocity.x = gCurrentPinballGame->flipperLaunchVelocity.x;
                gCurrentPinballGame->ballStates[0].velocity.y = gCurrentPinballGame->flipperLaunchVelocity.y;
                gCurrentPinballGame->flipperLaunchPending = 0;
                PlayRumble(7);
            }
            flipper->collisionFrameIndex = flipper->position / 2 + 1;
            flipper->position += 4;
        }
        else
        {
            if (flipper->position != 0)
            {
                flipper->collisionFrameIndex = flipper->position / 2 + 6;
                dir = -1;
            }
            else if (gCurrentPinballGame->flipperLaunchPending != 0)
            {
                gCurrentPinballGame->ballStates[0].velocity.x = gCurrentPinballGame->flipperLaunchVelocity.x;
                gCurrentPinballGame->ballStates[0].velocity.y = gCurrentPinballGame->flipperLaunchVelocity.y;
                gCurrentPinballGame->flipperLaunchPending = 0;
                PlayRumble(7);
            }
            flipper->position -= 2;
        }
        flipper->movementDirection = flipper->movementDirection * dir;
        if (flipper->movementDirection <= 0)
            flipper->bounceApplied = 0;
        flipper->movementDirection = dir;
    }
}
