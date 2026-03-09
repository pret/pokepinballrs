#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"


extern s16 gUnknown_020306C0[];
extern s16 gUnknown_02030750[];
extern s16 gUnknown_02031500[];

extern const u8 gDebugTextStrings[];
extern const u8 gUnknown_08137DE8[];
extern u8 gUnknown_08137E00[];
extern const u8 gMainBoardBallSave_Gfx[];
extern const u8 gMainBoardBallSaveLatios_Gfx[];
extern const u8 gMainBoardBallSaveLatiosArm_Gfx[];
extern const u8 gMainBoardEndOfBall_Gfx[];
extern const u8 gUnknown_0850558C[][0x20];
extern const u8 gMainBoardGameOverText_Gfx[];
extern const u8 gUnknown_08514F4C[];
extern const u8 gUnknown_08514F6C[];
extern const u8 gUnknown_08521FAC[];
extern const u8 gUnknown_08521FCC[];
extern const s8 gUnknown_086B0128[][3][20];

struct FieldCollisionData
{
    const s16 *collisionTileMapData;
    u8 filler4[0xC];
    const u16 *collisionPropertyData;
    u8 filler14[0xC];
    const u8 *collisionSubtypeData;
    u8 filler24[0xC];
};
extern const struct FieldCollisionData gUnknown_086AFCB0[][2];

// Handle debug system flags
void BonusStage_HandleModeChangeFlags(void)
{
    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        return;

    if (gMain.modeChangeFlags & MODE_CHANGE_BALL_SAVER)
    {
        // instantly reset ball
        HandleBallSaverAnimation();
        return;
    }

    if (gMain.modeChangeFlags & MODE_CHANGE_END_OF_BALL)
    {
        // lose life, and reset ball
        HandleEndOfBallSequence();
        return;
    }

    if (gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME)
    {
        // end game
        HandleGameOverSequence();
        return;
    }

    if (gMain.modeChangeFlags & MODE_CHANGE_DEBUG)
    {
        // debug tool (move ball position, and change ball speed)
        DebugMenuRenderAndHandleInput();
        gCurrentPinballGame->debugMenuSelection = gMain.debugOption + 1;
        return;
    }
}

// Debug menu that lets you move the ball's position and change ball speed.
// However, the menu text rendering is only half-implemented--the second
// menu item is for changing the ball's speed (toggling between fast and slow),
// but there is no indication of happening on-screen.
void DebugMenuRenderAndHandleInput(void)
{
    int i;
    u8 str0[42];
    u8 str1[24];

    memcpy(str0, gDebugTextStrings, 42);
    memcpy(str1, gUnknown_08137DE8, 24);

    for (i = 0x340; i < 0x380; i++)
        gBgScreenBuffer[i] = 0;

    IntToDecString(gCurrentPinballGame->ball->positionQ0.x, &str1[1], 3, 1);
    IntToDecString(gCurrentPinballGame->ball->positionQ0.y, &str1[5], 3, 1);
    DrawTextToTilemap(&str1[0], 26, 9);
    IntToDecString(gCurrentPinballGame->viewportBottomY, &str1[13], 3, 1);
    DrawTextToTilemap(&str1[12], 26, 18);
    DrawTextToTilemap(str0, 26, 0);

    if (JOY_HELD(B_BUTTON))
    {
        if (gMain.systemFrameCount & 0x8)
            DrawTextToTilemap(gUnknown_08137E00, gMain.debugOption + 26, 0);

        if (JOY_NEW(DPAD_UP) && gMain.debugOption != 0)
            gMain.debugOption--;

        if (JOY_NEW(DPAD_DOWN) && gMain.debugOption == 0)
            gMain.debugOption++;

        if (gCurrentPinballGame->debugMenuSelection == 2)
            DebugToggleBallSpeed();
    }
    else
    {
        switch (gCurrentPinballGame->debugMenuSelection)
        {
        case 1:
            DebugMoveBallPosition();
            break;
        case 2:
            DebugToggleBallSpeed();
            break;
        }

        DrawTextToTilemap(gUnknown_08137E00, gMain.debugOption + 26, 0);
    }

    for (i = 0x340; i < 0x380; i++)
        gBgScreenBuffer[i] += 0xC100;

    DmaCopy16(3, gBgScreenBuffer, (void *)0x06002000, 0x800);
    if (JOY_HELD(A_BUTTON))
        ClearDebugMenuTilemap();
}

void HandleGameOverSequence(void)
{
    int i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 var0;

    group = gMain.boardSpriteGroups[42];
    if (group->available)
    {
        group->baseX = 63;
        group->baseY = 52;
        for (i = 0; i < 8; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    var0 = gMain.systemFrameCount * 0x1000;
    for (i = 0; i < 8; i++)
    {
        gUnknown_02031500[i] = (gUnknown_02030750[i] * Cos(var0)) / 200;
        if ((gMain.systemFrameCount & 1) == 0)
        {
            gUnknown_02030750[i]++;
            if (gUnknown_02030750[i] >= 0)
                gUnknown_02030750[i] = 0;
        }
    }

    if (gMain.stateTimer == 3600)
    {
        DmaCopy16(3, gMainBoardGameOverText_Gfx, (void *)0x06015800, 0x400);
        gMain.boardSpriteGroups[42]->available = 1;
        for (i = 0; i < 8; i++)
        {
            gUnknown_02031500[i] = 0xE0C0;
            gUnknown_020306C0[i] = 0;
            gUnknown_02030750[i] = (Random() % 30) + 0xFFCE;
        }
    }

    if (gMain.stateTimer)
    {
        gMain.stateTimer--;
        if (gMain.stateTimer == 0)
            gCurrentPinballGame->gamePhase = 2;
    }

    if (JOY_NEW(A_BUTTON))
        gCurrentPinballGame->gamePhase = 2;
}

void HandleEndOfBallSequence(void)
{
    s16 i, j;
    u8 var0;

    if (gMain.stateTimer)
    {
        if (gMain.stateTimer < 21)
        {
            if (gMain.stateTimer == 20)
                m4aSongNumStart(SE_UNKNOWN_0xA4);

            if (gCurrentPinballGame->bonusPanelOffsetY < 128)
                gCurrentPinballGame->bonusPanelOffsetY += 8;
        }
        else
        {
            if (gCurrentPinballGame->bonusPanelOffsetY > 0)
                gCurrentPinballGame->bonusPanelOffsetY -= 8;
        }

        UpdateEndOfBallBonusSummary();
        gMain.stateTimer--;
        if (gMain.stateTimer == 199)
        {
            gCurrentPinballGame->bonusPanelOffsetY = 128;
            gMain.spriteGroups[9].available = 1;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[7].available = 1;
            gMain.spriteGroups[8].available = 1;
            DmaCopy16(3, gMainBoardEndOfBall_Gfx, (void *)0x6015800, 0x2800);
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gUnknown_08521FAC, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_08521FCC, (void *)0x050003C0, 0x20);
            }

            m4aSongNumStart(SE_UNKNOWN_0xA4);
            for (i = 0; i < 3; i++)
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->tallyRowDirtyFlags[i][j] = 0;
        }
        else if (gMain.stateTimer == 1)
        {
            gMain.spriteGroups[9].available = 0;
            gMain.spriteGroups[6].available = 0;
            gMain.spriteGroups[7].available = 0;
            gMain.spriteGroups[8].available = 0;
        }
    }
    else
    {
        gMain.modeChangeFlags &= ~MODE_CHANGE_END_OF_BALL;
        ClearDebugMenuTilemap();
        if (gCurrentPinballGame->numLives > 0)
        {
            gCurrentPinballGame->modeTimerFrames = 1800;
            gCurrentPinballGame->numLives--;
            gCurrentPinballGame->entryAnimTimer = 60;
            gCurrentPinballGame->hatchCompletionCount = 0;
            gCurrentPinballGame->catchCompletionCount = 0;
            gCurrentPinballGame->evolutionCompletionCount = 0;
            gCurrentPinballGame->bonusStageEntryCount = 0;
            gCurrentPinballGame->pondBonusHitCount = 0;
            gCurrentPinballGame->savedBonusMultiplier = 0;
            ResetBallToStartPosition(0);
            SetBoardFieldCollisionData(0);
            gCurrentPinballGame->rubyAbsorbZoneActive = 0;
            if (gCurrentPinballGame->boardState == 3)
            {
                var0 = gCurrentPinballGame->numCompletedBonusStages % 5;
                switch (var0)
                {
                case 0:
                case 2:
                    m4aSongNumStart(MUS_BONUS_CHANCE);
                    break;
                case 1:
                case 3:
                case 4:
                    m4aSongNumStart(MUS_BONUS_CHANCE_LEGENDARY);
                    break;
                }
            }
            else
            {
                RequestBoardTransition(1);
            }

            gCurrentPinballGame->bannerType = 0;
        }
        else
        {
            gMain.modeChangeFlags |= MODE_CHANGE_END_OF_GAME;
            gMain.stateTimer = 3600;
            m4aSongNumStart(MUS_SLOTS_PRIZE);
        }
    }
}

void HandleBallSaverAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int newX, newY;
    s16 mat3Scale;
    s16 mat4Scale;

    if (gMain.stateTimer)
    {
        group = &gMain.spriteGroups[5];
        if (group->available)
        {
            group->baseX = 88;
            group->baseY = 20 + gCurrentPinballGame->bonusBallBaseY;
            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 3;
            }
        }

        group = &gMain.spriteGroups[4];
        if (group->available)
        {
            group->baseX = 24 + gCurrentPinballGame->bonusBallPosX / 100;
            group->baseY = gCurrentPinballGame->bonusBallBaseY + 20 + gCurrentPinballGame->bonusBallPosY / 100;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 4;
        }

        group = &gMain.spriteGroups[3];
        if (group->available)
        {
            group->baseX = 56 + gCurrentPinballGame->bonusBallPosX / 100;
            group->baseY = gCurrentPinballGame->bonusBallBaseY + 52 + gCurrentPinballGame->bonusBallPosY / 100;
            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        gMain.stateTimer--;
        if (gMain.stateTimer > 70)
        {
            int var0 = (gMain.stateTimer + 20) % 0x40;
            gCurrentPinballGame->bonusBallPosY = (Sin(var0 * 0x400) * 500) / 20000;
            gCurrentPinballGame->bonusBallVelX = 10;
            gCurrentPinballGame->bonusBallVelY = 400;
        }
        else
        {
            gCurrentPinballGame->bonusBallVelX = 400;
            gCurrentPinballGame->bonusBallVelY -= 35;
            gCurrentPinballGame->bonusBallPosX += gCurrentPinballGame->bonusBallVelX;
            gCurrentPinballGame->bonusBallPosY += gCurrentPinballGame->bonusBallVelY;
        }

        if (gMain.stateTimer >= 30 && gMain.stateTimer < 60)
        {
            mat4Scale = (60 - gMain.stateTimer) * 0x100 / 30 + 0x100;
        }
        else
        {
            mat4Scale = 0x100;
            if (gMain.stateTimer < 30)
                gMain.spriteGroups[4].available = 0;
        }

        if (gMain.stateTimer < 31)
        {
            if (gMain.stateTimer > 10)
            {
                mat3Scale = ((gMain.stateTimer - 10) * 248) / 20 + 8;
            }
            else
            {
                mat3Scale = 8;
                gMain.spriteGroups[5].available = 0;
            }
        }
        else
        {
            if (gCurrentPinballGame->bonusBallBaseY > 0)
            {
                gCurrentPinballGame->bonusBallBaseY -= 8;
                if (gCurrentPinballGame->bonusBallBaseY < 0)
                    gCurrentPinballGame->bonusBallBaseY = 0;
            }

            mat3Scale = 0x100;
        }

        if (gMain.stateTimer < 203)
        {
            if (gMain.stateTimer > 55)
            {
                gCurrentPinballGame->bonusBallDropVelX = gCurrentPinballGame->bonusBallVelX;
                gCurrentPinballGame->bonusBallDropVelY = gCurrentPinballGame->bonusBallVelY - 90;
                gCurrentPinballGame->bonusBallDropPosX = gCurrentPinballGame->bonusBallPosX;
                gCurrentPinballGame->bonusBallDropPosY = gCurrentPinballGame->bonusBallPosY;
                if (gMain.stateTimer == 56)
                    m4aSongNumStart(SE_UNKNOWN_0x95);

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->bonusBallDropPosX / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->bonusBallBaseY + 372 + gCurrentPinballGame->bonusBallDropPosY / 100) << 8;
            }
            else if (gMain.stateTimer > 31)
            {
                gCurrentPinballGame->bonusBallDropVelY += 6;
                gCurrentPinballGame->bonusBallDropPosX += gCurrentPinballGame->bonusBallDropVelX;
                gCurrentPinballGame->bonusBallDropPosY += gCurrentPinballGame->bonusBallDropVelY;
                gMain.spriteGroups[3].available = 0;
                if (gMain.stateTimer == 32)
                {
                    gCurrentPinballGame->bossActive = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x96);
                    PlayRumble(6);
                }

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->bonusBallDropPosX / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->bonusBallBaseY + 372 + gCurrentPinballGame->bonusBallDropPosY / 100) << 8;
            }
            else
            {
                gCurrentPinballGame->bonusBallDropVelX = 0;
                gCurrentPinballGame->bonusBallDropVelY += 20;
                gCurrentPinballGame->bonusBallDropPosX += gCurrentPinballGame->bonusBallDropVelX;
                gCurrentPinballGame->bonusBallDropPosY += gCurrentPinballGame->bonusBallDropVelY;
                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->bonusBallDropPosX / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->bonusBallBaseY + 372 + gCurrentPinballGame->bonusBallDropPosY / 100) << 8;
                if (gCurrentPinballGame->ball->positionQ8.y > 0x17100)
                    gCurrentPinballGame->ball->positionQ8.y = 0x17100;
            }

            gCurrentPinballGame->ball->oamPriority = 0;
            gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;

            newX = gCurrentPinballGame->ball->positionQ8.x;
            if (newX < 0)
                newX += 0x7F;
            gCurrentPinballGame->ball->positionQ1.x = newX >> 7;

            newY = gCurrentPinballGame->ball->positionQ8.y;
            if (newY < 0)
                newY += 0x7F;
            gCurrentPinballGame->ball->positionQ1.y = newY >> 7;

            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        SetMatrixScale(0x100, mat3Scale, 3);
        SetMatrixScale(mat4Scale, mat4Scale, 4);

        if (gMain.stateTimer == 203)
        {
            gCurrentPinballGame->bonusBallPosX = 0;
            gCurrentPinballGame->bonusBallPosY = 0;
            gCurrentPinballGame->bonusBallVelX = 0;
            gCurrentPinballGame->bonusBallVelY = 0;
            gCurrentPinballGame->bonusBallBaseY = 100;
            gMain.spriteGroups[5].available = 1;
            gMain.spriteGroups[4].available = 1;
            gMain.spriteGroups[3].available = 1;
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gMainBoardBallSave_Gfx, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gMainBoardBallSaveLatios_Gfx, (void *)0x06016800, 0x800);
                DmaCopy16(3, gMainBoardBallSaveLatiosArm_Gfx, (void *)0x06017000, 0xC0);
                DmaCopy16(3, gUnknown_08514F4C, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gMainBoardBallSave_Gfx, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_08514F6C, (void *)0x050003C0, 0x20);
            }

            gCurrentPinballGame->ballLockState = 2;
            gCurrentPinballGame->bossActive = 1;
            gCurrentPinballGame->ballLocked = 1;
            gCurrentPinballGame->pauseInputLocked = 1;
            m4aSongNumStart(SE_UNKNOWN_0x94);
        }
        else if (gMain.stateTimer == 0)
        {
            gMain.spriteGroups[5].available = 0;
            gMain.spriteGroups[4].available = 0;
        }
    }
    else
    {
        gMain.modeChangeFlags &= ~MODE_CHANGE_BALL_SAVER;
        gCurrentPinballGame->entryAnimTimer = 60;
        ResetBallToStartPosition(0);
        gCurrentPinballGame->ballLockState = 0;
        SetBoardFieldCollisionData(0);
        gCurrentPinballGame->rubyAbsorbZoneActive = 0;
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->ball->oamPriority = 3;
        else
            gCurrentPinballGame->ball->oamPriority = 1;

        gCurrentPinballGame->ballLocked = 0;
        gCurrentPinballGame->bannerType = 0;
        gCurrentPinballGame->pauseInputLocked = 0;
    }
}

void ClearDebugMenuTilemap(void)
{
    int i;
    for (i = 0x340; i < 0x380; i++)
        gBgScreenBuffer[i] = 0x1FF;

    DmaCopy16(3, gBgScreenBuffer, (void *)0x6002000, 0x800);
}

void DebugMoveBallPosition(void)
{
    int newX, newY;

    if (JOY_HELD(A_BUTTON))
    {
        if (JOY_HELD(DPAD_UP))
            gCurrentPinballGame->ball->positionQ8.y -= 0x80;
        if (JOY_HELD(DPAD_DOWN))
            gCurrentPinballGame->ball->positionQ8.y += 0x80;
        if (JOY_HELD(DPAD_LEFT))
            gCurrentPinballGame->ball->positionQ8.x -= 0x80;
        if (JOY_HELD(DPAD_RIGHT))
            gCurrentPinballGame->ball->positionQ8.x += 0x80;
    }
    else
    {
        if (JOY_HELD(DPAD_UP))
            gCurrentPinballGame->ball->positionQ8.y -= 0x200;
        if (JOY_HELD(DPAD_DOWN))
            gCurrentPinballGame->ball->positionQ8.y += 0x200;
        if (JOY_HELD(DPAD_LEFT))
            gCurrentPinballGame->ball->positionQ8.x -= 0x200;
        if (JOY_HELD(DPAD_RIGHT))
            gCurrentPinballGame->ball->positionQ8.x += 0x200;
    }

    gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
    newX = gCurrentPinballGame->ball->positionQ8.x;
    if (newX < 0)
        newX += 0x7F;
    gCurrentPinballGame->ball->positionQ1.x = newX >> 7;

    newY = gCurrentPinballGame->ball->positionQ8.y;
    if (newY < 0)
        newY += 0x7F;
    gCurrentPinballGame->ball->positionQ1.y = newY >> 7;

    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
}

void DebugToggleBallSpeed(void)
{
    if (JOY_NEW(DPAD_UP))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_DOWN))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_RIGHT))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_LEFT))
        gCurrentPinballGame->ballSpeed^= 1;
}

// This function updates/draws the "End of Ball Bonus" summary
void UpdateEndOfBallBonusSummary(void)
{
    int i, j;
    s16 var0;
    int var2;
    int value;
    int var4;
    int multiplier;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s8 sp0[16];
    s16 sp10;
    s16 sp14;
    s16 sp18;

    var0 = 212 - gCurrentPinballGame->tallyScrollPosition;
    sp10 = 0;
    sp14 = 0;
    sp18 = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            s16 var1 = gCurrentPinballGame->tallyRowTileIds[i][j];
            if (var1 == 95)
                var1 = 48;
            else if (var1 == 94)
                var1 = 47;
            else if (var1 > 46)
                var1 -= 65;

            if (gCurrentPinballGame->tallyRowDirtyFlags[i][j])
            {
                DmaCopy16(3, gUnknown_0850558C[var1], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_0850558C[48], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
        }
    }

    if (gMain.stateTimer < 180)
    {
        if (gMain.stateTimer > 50 && JOY_NEW(A_BUTTON))
        {
            if (gCurrentPinballGame->tallyCalculationDone == 0)
            {
                gCurrentPinballGame->tallyScrollPosition = 100;
                var0 = 100;
                gCurrentPinballGame->tallyReelPhase = 6;
                gCurrentPinballGame->endBallBonusScoreLo =
                    gCurrentPinballGame->hatchCompletionCount * 500000 +
                    gCurrentPinballGame->catchCompletionCount * 750000 +
                    gCurrentPinballGame->evolutionCompletionCount * 500000 +
                    gCurrentPinballGame->bonusStageEntryCount * 100000 +
                    gCurrentPinballGame->pondBonusHitCount * 100000;

                gCurrentPinballGame->endBallBonusScoreHi = 0;
                gMain.stateTimer = 150;

                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->tallyRowDirtyFlags[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->tallyRowDirtyFlags[1][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->tallyRowDirtyFlags[2][j] = 1;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->tallyRowTileIds[i][j] = gUnknown_086B0128[gCurrentPinballGame->tallyReelPhase][i][j];

                sp14 = 1;
            }
            else
            {
                gCurrentPinballGame->tallyScrollPosition = 1;
                gMain.stateTimer = 51;
                var0 = 100;
                if (gCurrentPinballGame->pendingBonusScoreLo || gCurrentPinballGame->pendingBonusScoreHi)
                {
                    gCurrentPinballGame->scoreLo += gCurrentPinballGame->pendingBonusScoreLo;
                    gCurrentPinballGame->scoreHi += gCurrentPinballGame->pendingBonusScoreHi;
                    gCurrentPinballGame->pendingBonusScoreLo = 0;
                    gCurrentPinballGame->pendingBonusScoreHi = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

        }
    }

    if (gMain.stateTimer == 185)
    {
        gCurrentPinballGame->tallyCalculationDone = 0;
        gCurrentPinballGame->tallyScrollPosition = 212;
        gCurrentPinballGame->tallyReelPhase = 0;
        gCurrentPinballGame->endBallBonusScoreLo = 0;
        gCurrentPinballGame->endBallBonusScoreHi = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->tallyRowTileIds[i][j] = gUnknown_086B0128[gCurrentPinballGame->tallyReelPhase][i][j];
    }

    if (gCurrentPinballGame->tallyScrollPosition != 0)
    {
        if (gMain.stateTimer < 150)
            gMain.stateTimer++;

        if (gCurrentPinballGame->tallyReelPhase < 5)
        {
            if (var0 < 89)
            {
                var2 = var0 / 24;
                if (var2 > 2)
                    var2 = 2;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    if (gCurrentPinballGame->tallyReelPhase == 0 || i != 2)
                    {
                        if (gCurrentPinballGame->tallyRowDirtyFlags[i][j] == 0 && gCurrentPinballGame->tallyRowTileIds[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->tallyRowDirtyFlags[i][j] = 1;
                }
            }
            else if (var0 >= 148)
            {
                var0 = var0 - 148;
                var2 = var0 / 24;
                if (var2 > 1)
                    var2 = 1;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    gCurrentPinballGame->tallyRowDirtyFlags[i][j] = 0;
                }
            }

            if (gCurrentPinballGame->tallyScrollPosition == 1)
            {
                gCurrentPinballGame->tallyScrollPosition = 212;
                gCurrentPinballGame->tallyReelPhase++;
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->tallyRowTileIds[i][j] = gUnknown_086B0128[gCurrentPinballGame->tallyReelPhase][i][j];
            }
        }
        else if (gCurrentPinballGame->tallyReelPhase == 5)
        {
            if (var0 < 17)
            {
                sp10 = -var0 * 2;
                if (var0 == 2)
                    m4aSongNumStart(SE_UNKNOWN_0xA2);
            }
            else
            {
                sp10 = 0;
                gCurrentPinballGame->tallyScrollPosition = 212;
                gCurrentPinballGame->tallyReelPhase++;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->tallyRowDirtyFlags[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->tallyRowDirtyFlags[1][j] = 0;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->tallyRowDirtyFlags[2][j] = 0;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->tallyRowTileIds[i][j] = gUnknown_086B0128[gCurrentPinballGame->tallyReelPhase][i][j];
            }
        }
        else
        {
            if (var0 < 89)
            {
                var2 = var0 / 24;
                if (var2 > 2)
                    var2 = 2;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    if (i != 0)
                    {
                        if (gCurrentPinballGame->tallyRowDirtyFlags[i][j] == 0 && gCurrentPinballGame->tallyRowTileIds[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->tallyRowDirtyFlags[i][j] = 1;
                }
            }
        }

        if (sp18)
            m4aSongNumStart(SE_UNKNOWN_0xA1);
    }

    value = 0;
    multiplier = 0;
    if (gCurrentPinballGame->tallyScrollPosition == 212 || sp14 != 0)
    {
        switch (gCurrentPinballGame->tallyReelPhase)
        {
        case 0:
            value = gCurrentPinballGame->hatchCompletionCount;
            multiplier = 500000;
            break;
        case 1:
            value = gCurrentPinballGame->catchCompletionCount;
            multiplier = 750000;
            break;
        case 2:
            value = gCurrentPinballGame->evolutionCompletionCount;
            multiplier = 500000;
            break;
        case 3:
            value = gCurrentPinballGame->bonusStageEntryCount;
            multiplier = 100000;
            break;
        case 4:
            value = gCurrentPinballGame->pondBonusHitCount;
            multiplier = 100000;
            break;
        case 5:
            value = 0;
            multiplier = 0;
            break;
        case 6:
            break;
        }

        if (gCurrentPinballGame->tallyReelPhase < 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            sp0[2] = value / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 2; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = value * multiplier;
            gCurrentPinballGame->endBallBonusScoreHi = value;
            sp0[7] = value / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 7; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->endBallBonusScoreLo;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->tallyReelPhase == 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->endBallBonusScoreLo;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[2][19 - j] = sp0[j] + 27;
        }
        else
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->endBallBonusScoreLo;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->savedBonusMultiplier;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 5; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            value = 0;
            var4 = 0;
            while (gCurrentPinballGame->savedBonusMultiplier != 0)
            {
                value += gCurrentPinballGame->endBallBonusScoreLo;
                if (value / 200000000 > 0)
                {
                    value -= 200000000;
                    var4 += 2;
                }
                gCurrentPinballGame->savedBonusMultiplier--;
            }

            if (value / 100000000 > 0)
            {
                value -= 100000000;
                var4++;
            }

            gCurrentPinballGame->pendingBonusScoreHi = var4;
            gCurrentPinballGame->pendingBonusScoreLo = value;
            sp0[10] = (var4 % 1000) / 100;
            sp0[9] = ((var4 % 100) / 10) + 10;
            sp0[8] = var4 % 10;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 10; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[2][19 - j] = sp0[j] + 27;
        }
    }

    if (var0 >= 90 && var0 <= 140)
    {
        if (gCurrentPinballGame->tallyReelPhase < 5)
        {
            if (gCurrentPinballGame->endBallBonusScoreHi != 0)
                gCurrentPinballGame->tallyScrollPosition = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->endBallBonusScoreHi >= 200000)
                {
                    gCurrentPinballGame->endBallBonusScoreHi -= 200000;
                    gCurrentPinballGame->endBallBonusScoreLo += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->endBallBonusScoreHi != 0)
                {
                    gCurrentPinballGame->endBallBonusScoreLo += gCurrentPinballGame->endBallBonusScoreHi;
                    gCurrentPinballGame->endBallBonusScoreHi = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

            value = gCurrentPinballGame->endBallBonusScoreLo;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->tallyReelPhase == 6)
        {
            gCurrentPinballGame->tallyCalculationDone = 1;
            if (gCurrentPinballGame->pendingBonusScoreLo || gCurrentPinballGame->pendingBonusScoreHi)
                gCurrentPinballGame->tallyScrollPosition = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->pendingBonusScoreLo >= 200000)
                {
                    gCurrentPinballGame->pendingBonusScoreLo -= 200000;
                    gCurrentPinballGame->scoreLo += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->pendingBonusScoreHi != 0)
                {
                    gCurrentPinballGame->pendingBonusScoreHi--;
                    gCurrentPinballGame->pendingBonusScoreLo += 99800000;
                    gCurrentPinballGame->scoreLo += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->pendingBonusScoreLo != 0)
                {
                    gCurrentPinballGame->scoreLo += gCurrentPinballGame->pendingBonusScoreLo;
                    gCurrentPinballGame->pendingBonusScoreLo = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->tallyRowTileIds[2][j] = gUnknown_086B0128[gCurrentPinballGame->tallyReelPhase][2][j];

            var4 = gCurrentPinballGame->pendingBonusScoreHi;
            value = gCurrentPinballGame->pendingBonusScoreLo;
            sp0[10] = (var4 % 1000) / 100;
            sp0[9] = ((var4 % 100) / 10) + 10;
            sp0[8] = var4 % 10;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 10; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->tallyRowTileIds[2][19 - j] = sp0[j] + 27;
        }
    }

    if (gCurrentPinballGame->tallyScrollPosition)
        gCurrentPinballGame->tallyScrollPosition--;

    group = &gMain.spriteGroups[9];
    if (group->available)
    {
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->bonusPanelOffsetY + 38;
        for (j = 0; j < 14; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        for (i = 0; i < 3; i++)
        {
            group = &gMain.spriteGroups[6 + i];
            group->baseX = 104;
            group->baseY = 64 + i * 16 + gCurrentPinballGame->bonusPanelOffsetY + sp10;
            for (j = 0; j < 5; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}
