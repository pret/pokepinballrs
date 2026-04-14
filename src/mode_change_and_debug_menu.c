#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"


extern s16 gGameOverLetterXOffsets[];
extern s16 gGameOverLetterAmplitudes[];
extern s16 gGameOverLetterYOffsets[];

extern const u8 gDebugTextStrings[];
extern const u8 gDebugMenuValueTemplate[];
extern u8 gDebugMenuCursorText[];
extern const u8 gMainBoardBallSave_Gfx[];
extern const u8 gMainBoardBallSaveLatios_Gfx[];
extern const u8 gMainBoardBallSaveLatiosArm_Gfx[];
extern const u8 gMainBoardEndOfBall_Gfx[];
extern const u8 gBonusSummaryCharTiles[][0x20];
extern const u8 gMainBoardGameOverText_Gfx[];
extern const u8 gBonusStagePal_Lit[];
extern const u8 gBonusStagePal_Dark[];
extern const u8 gBonusClearTextPal_Lit[];
extern const u8 gBonusClearTextPal_Dark[];
extern const s8 gBonusSummaryTextTemplates[][3][20];

// Handle debug system flags
void BonusStage_HandleModeChangeFlags(void)
{
    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        return;

    if (gMain.modeChangeFlags & MODE_CHANGE_BALL_SAVER)
    {
        // instantly reset ball
        BallSaverAnimation();
        return;
    }

    if (gMain.modeChangeFlags & MODE_CHANGE_END_OF_BALL)
    {
        // lose life, and reset ball
        EndOfBallSequence();
        return;
    }

    if (gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME)
    {
        // end game
        GameOverAnimation();
        return;
    }

    if (gMain.modeChangeFlags & MODE_CHANGE_DEBUG)
    {
        // debug tool (move ball position, and change ball speed)
        DebugMenu_RenderAndHandleInput();
        gCurrentPinballGame->debugMenuSelection = gMain.debugMenuCursorIndex + 1;
        return;
    }
}

// Debug menu that lets you move the ball's position and change ball speed.
// However, the menu text rendering is only half-implemented--the second
// menu item is for changing the ball's speed (toggling between fast and slow),
// but there is no indication of happening on-screen.
void DebugMenu_RenderAndHandleInput(void)
{
    int i;
    u8 str0[42];
    u8 str1[24];

    memcpy(str0, gDebugTextStrings, 42);
    memcpy(str1, gDebugMenuValueTemplate, 24);

    for (i = 0x340; i < 0x380; i++)
        gBG0TilemapBuffer[i] = 0;

    FormatIntToString(gCurrentPinballGame->ball->positionQ0.x, &str1[1], 3, 1);
    FormatIntToString(gCurrentPinballGame->ball->positionQ0.y, &str1[5], 3, 1);
    DrawTextToTilemap(&str1[0], 26, 9);
    FormatIntToString(gCurrentPinballGame->cameraYViewport, &str1[13], 3, 1);
    DrawTextToTilemap(&str1[12], 26, 18);
    DrawTextToTilemap(str0, 26, 0);

    if (JOY_HELD(B_BUTTON))
    {
        if (gMain.systemFrameCount & 0x8)
            DrawTextToTilemap(gDebugMenuCursorText, gMain.debugMenuCursorIndex + 26, 0);

        if (JOY_NEW(DPAD_UP) && gMain.debugMenuCursorIndex != 0)
            gMain.debugMenuCursorIndex--;

        if (JOY_NEW(DPAD_DOWN) && gMain.debugMenuCursorIndex == 0)
            gMain.debugMenuCursorIndex++;

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

        DrawTextToTilemap(gDebugMenuCursorText, gMain.debugMenuCursorIndex + 26, 0);
    }

    for (i = 0x340; i < 0x380; i++)
        gBG0TilemapBuffer[i] += 0xC100;

    DmaCopy16(3, gBG0TilemapBuffer, (void *)0x06002000, 0x800);
    if (JOY_HELD(A_BUTTON))
        ClearDebugTextDisplay();
}

void GameOverAnimation(void)
{
    int i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 var0;

    group = gMain.fieldSpriteGroups[42];
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
        gGameOverLetterYOffsets[i] = (gGameOverLetterAmplitudes[i] * Cos(var0)) / 200;
        if ((gMain.systemFrameCount & 1) == 0)
        {
            gGameOverLetterAmplitudes[i]++;
            if (gGameOverLetterAmplitudes[i] >= 0)
                gGameOverLetterAmplitudes[i] = 0;
        }
    }

    if (gMain.animationTimer == 3600)
    {
        DmaCopy16(3, gMainBoardGameOverText_Gfx, (void *)0x06015800, 0x400);
        gMain.fieldSpriteGroups[42]->available = 1;
        for (i = 0; i < 8; i++)
        {
            gGameOverLetterYOffsets[i] = 0xE0C0;
            gGameOverLetterXOffsets[i] = 0;
            gGameOverLetterAmplitudes[i] = (Random() % 30) + 0xFFCE;
        }
    }

    if (gMain.animationTimer)
    {
        gMain.animationTimer--;
        if (gMain.animationTimer == 0)
            gCurrentPinballGame->fadeSubState = 2;
    }

    if (JOY_NEW(A_BUTTON))
        gCurrentPinballGame->fadeSubState = 2;
}

void EndOfBallSequence(void)
{
    s16 i, j;
    u8 var0;

    if (gMain.animationTimer)
    {
        if (gMain.animationTimer < 21)
        {
            if (gMain.animationTimer == 20)
                m4aSongNumStart(SE_UNKNOWN_0xA4);

            if (gCurrentPinballGame->bonusSummarySlideY < 128)
                gCurrentPinballGame->bonusSummarySlideY += 8;
        }
        else
        {
            if (gCurrentPinballGame->bonusSummarySlideY > 0)
                gCurrentPinballGame->bonusSummarySlideY -= 8;
        }

        EndOfBallBonusSummary();
        gMain.animationTimer--;
        if (gMain.animationTimer == 199)
        {
            gCurrentPinballGame->bonusSummarySlideY = 128;
            gMain.spriteGroups[9].available = 1;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[7].available = 1;
            gMain.spriteGroups[8].available = 1;
            DmaCopy16(3, gMainBoardEndOfBall_Gfx, (void *)0x6015800, 0x2800);
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gBonusClearTextPal_Lit, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gBonusClearTextPal_Dark, (void *)0x050003C0, 0x20);
            }

            m4aSongNumStart(SE_UNKNOWN_0xA4);
            for (i = 0; i < 3; i++)
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[i][j] = 0;
        }
        else if (gMain.animationTimer == 1)
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
        ClearDebugTextDisplay();
        if (gCurrentPinballGame->numLives > 0)
        {
            gCurrentPinballGame->saverTimeRemaining = 1800;
            gCurrentPinballGame->numLives--;
            gCurrentPinballGame->collisionCooldownTimer = 60;
            gCurrentPinballGame->bonusCatchCount = 0;
            gCurrentPinballGame->bonusMonCatchCount = 0;
            gCurrentPinballGame->travelModeCompletionCount = 0;
            gCurrentPinballGame->catchTriggerCompletionCount = 0;
            gCurrentPinballGame->bonusPikaSaverCount = 0;
            gCurrentPinballGame->bonusMultiplier = 0;
            InitBallState(0);
            SetBoardCollisionConfig(0);
            gCurrentPinballGame->boardCollisionConfigChanged = 0;
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
                RequestBoardStateTransition(1);
            }

            gCurrentPinballGame->activePortraitType = 0;
        }
        else
        {
            gMain.modeChangeFlags |= MODE_CHANGE_END_OF_GAME;
            gMain.animationTimer = 3600;
            m4aSongNumStart(MUS_SLOTS_PRIZE);
        }
    }
}

void BallSaverAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int newX, newY;
    s16 mat3Scale;
    s16 mat4Scale;

    if (gMain.animationTimer)
    {
        group = &gMain.spriteGroups[5];
        if (group->available)
        {
            group->baseX = 88;
            group->baseY = 20 + gCurrentPinballGame->ballSaverSlideY;
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
            group->baseX = 24 + gCurrentPinballGame->ballSaverPosX / 100;
            group->baseY = gCurrentPinballGame->ballSaverSlideY + 20 + gCurrentPinballGame->ballSaverPosY / 100;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 4;
        }

        group = &gMain.spriteGroups[3];
        if (group->available)
        {
            group->baseX = 56 + gCurrentPinballGame->ballSaverPosX / 100;
            group->baseY = gCurrentPinballGame->ballSaverSlideY + 52 + gCurrentPinballGame->ballSaverPosY / 100;
            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        gMain.animationTimer--;
        if (gMain.animationTimer > 70)
        {
            int var0 = (gMain.animationTimer + 20) % 0x40;
            gCurrentPinballGame->ballSaverPosY = (Sin(var0 * 0x400) * 500) / 20000;
            gCurrentPinballGame->ballSaverVelX = 10;
            gCurrentPinballGame->ballSaverVelY = 400;
        }
        else
        {
            gCurrentPinballGame->ballSaverVelX = 400;
            gCurrentPinballGame->ballSaverVelY -= 35;
            gCurrentPinballGame->ballSaverPosX += gCurrentPinballGame->ballSaverVelX;
            gCurrentPinballGame->ballSaverPosY += gCurrentPinballGame->ballSaverVelY;
        }

        if (gMain.animationTimer >= 30 && gMain.animationTimer < 60)
        {
            mat4Scale = (60 - gMain.animationTimer) * 0x100 / 30 + 0x100;
        }
        else
        {
            mat4Scale = 0x100;
            if (gMain.animationTimer < 30)
                gMain.spriteGroups[4].available = 0;
        }

        if (gMain.animationTimer < 31)
        {
            if (gMain.animationTimer > 10)
            {
                mat3Scale = ((gMain.animationTimer - 10) * 248) / 20 + 8;
            }
            else
            {
                mat3Scale = 8;
                gMain.spriteGroups[5].available = 0;
            }
        }
        else
        {
            if (gCurrentPinballGame->ballSaverSlideY > 0)
            {
                gCurrentPinballGame->ballSaverSlideY -= 8;
                if (gCurrentPinballGame->ballSaverSlideY < 0)
                    gCurrentPinballGame->ballSaverSlideY = 0;
            }

            mat3Scale = 0x100;
        }

        if (gMain.animationTimer < 203)
        {
            if (gMain.animationTimer > 55)
            {
                gCurrentPinballGame->ballSaverBallVelX = gCurrentPinballGame->ballSaverVelX;
                gCurrentPinballGame->ballSaverBallVelY = gCurrentPinballGame->ballSaverVelY - 90;
                gCurrentPinballGame->ballSaverBallPosX = gCurrentPinballGame->ballSaverPosX;
                gCurrentPinballGame->ballSaverBallPosY = gCurrentPinballGame->ballSaverPosY;
                if (gMain.animationTimer == 56)
                    m4aSongNumStart(SE_LATI_DELIVERY);

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->ballSaverBallPosX / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->ballSaverSlideY + 372 + gCurrentPinballGame->ballSaverBallPosY / 100) << 8;
            }
            else if (gMain.animationTimer > 31)
            {
                gCurrentPinballGame->ballSaverBallVelY += 6;
                gCurrentPinballGame->ballSaverBallPosX += gCurrentPinballGame->ballSaverBallVelX;
                gCurrentPinballGame->ballSaverBallPosY += gCurrentPinballGame->ballSaverBallVelY;
                gMain.spriteGroups[3].available = 0;
                if (gMain.animationTimer == 32)
                {
                    gCurrentPinballGame->boardEntityActive = 0;
                    m4aSongNumStart(SE_SAVER_PLUNGER_DROP);
                    PlayRumble(6);
                }

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->ballSaverBallPosX / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->ballSaverSlideY + 372 + gCurrentPinballGame->ballSaverBallPosY / 100) << 8;
            }
            else
            {
                gCurrentPinballGame->ballSaverBallVelX = 0;
                gCurrentPinballGame->ballSaverBallVelY += 20;
                gCurrentPinballGame->ballSaverBallPosX += gCurrentPinballGame->ballSaverBallVelX;
                gCurrentPinballGame->ballSaverBallPosY += gCurrentPinballGame->ballSaverBallVelY;
                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->ballSaverBallPosX / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->ballSaverSlideY + 372 + gCurrentPinballGame->ballSaverBallPosY / 100) << 8;
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

        if (gMain.animationTimer == 203)
        {
            gCurrentPinballGame->ballSaverPosX = 0;
            gCurrentPinballGame->ballSaverPosY = 0;
            gCurrentPinballGame->ballSaverVelX = 0;
            gCurrentPinballGame->ballSaverVelY = 0;
            gCurrentPinballGame->ballSaverSlideY = 100;
            gMain.spriteGroups[5].available = 1;
            gMain.spriteGroups[4].available = 1;
            gMain.spriteGroups[3].available = 1;
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gMainBoardBallSave_Gfx, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gMainBoardBallSaveLatios_Gfx, (void *)0x06016800, 0x800);
                DmaCopy16(3, gMainBoardBallSaveLatiosArm_Gfx, (void *)0x06017000, 0xC0);
                DmaCopy16(3, gBonusStagePal_Lit, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gMainBoardBallSave_Gfx, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gBonusStagePal_Dark, (void *)0x050003C0, 0x20);
            }

            gCurrentPinballGame->ballFrozenState = 2;
            gCurrentPinballGame->boardEntityActive = 1;
            gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
            gCurrentPinballGame->startButtonDisabled = 1;
            m4aSongNumStart(SE_BALL_SAVED);
        }
        else if (gMain.animationTimer == 0)
        {
            gMain.spriteGroups[5].available = 0;
            gMain.spriteGroups[4].available = 0;
        }
    }
    else
    {
        gMain.modeChangeFlags &= ~MODE_CHANGE_BALL_SAVER;
        gCurrentPinballGame->collisionCooldownTimer = 60;
        InitBallState(0);
        gCurrentPinballGame->ballFrozenState = 0;
        SetBoardCollisionConfig(0);
        gCurrentPinballGame->boardCollisionConfigChanged = 0;
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->ball->oamPriority = 3;
        else
            gCurrentPinballGame->ball->oamPriority = 1;

        gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
        gCurrentPinballGame->activePortraitType = 0;
        gCurrentPinballGame->startButtonDisabled = 0;
    }
}

void ClearDebugTextDisplay(void)
{
    int i;
    for (i = 0x340; i < 0x380; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gBG0TilemapBuffer, (void *)0x6002000, 0x800);
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
void EndOfBallBonusSummary(void)
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

    var0 = 212 - gCurrentPinballGame->bonusSummaryTimer;
    sp10 = 0;
    sp14 = 0;
    sp18 = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            s16 var1 = gCurrentPinballGame->bonusTextContent[i][j];
            if (var1 == 95)
                var1 = 48;
            else if (var1 == 94)
                var1 = 47;
            else if (var1 > 46)
                var1 -= 65;

            if (gCurrentPinballGame->bonusTextRevealMask[i][j])
            {
                DmaCopy16(3, gBonusSummaryCharTiles[var1], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
            else
            {
                DmaCopy16(3, gBonusSummaryCharTiles[48], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
        }
    }

    if (gMain.animationTimer < 180)
    {
        if (gMain.animationTimer > 50 && JOY_NEW(A_BUTTON))
        {
            if (gCurrentPinballGame->bonusSummaryComplete == 0)
            {
                gCurrentPinballGame->bonusSummaryTimer = 100;
                var0 = 100;
                gCurrentPinballGame->bonusSummaryPhase = 6;
                gCurrentPinballGame->bonusSubtotal =
                    gCurrentPinballGame->bonusCatchCount * 500000 +
                    gCurrentPinballGame->bonusMonCatchCount * 750000 +
                    gCurrentPinballGame->travelModeCompletionCount * 500000 +
                    gCurrentPinballGame->catchTriggerCompletionCount * 100000 +
                    gCurrentPinballGame->bonusPikaSaverCount * 100000;

                gCurrentPinballGame->bonusCategoryScore = 0;
                gMain.animationTimer = 150;

                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[1][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[2][j] = 1;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];

                sp14 = 1;
            }
            else
            {
                gCurrentPinballGame->bonusSummaryTimer = 1;
                gMain.animationTimer = 51;
                var0 = 100;
                if (gCurrentPinballGame->bonusTotalScoreLo || gCurrentPinballGame->bonusTotalScoreHi)
                {
                    gCurrentPinballGame->scoreLo += gCurrentPinballGame->bonusTotalScoreLo;
                    gCurrentPinballGame->scoreHi += gCurrentPinballGame->bonusTotalScoreHi;
                    gCurrentPinballGame->bonusTotalScoreLo = 0;
                    gCurrentPinballGame->bonusTotalScoreHi = 0;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
            }

        }
    }

    if (gMain.animationTimer == 185)
    {
        gCurrentPinballGame->bonusSummaryComplete = 0;
        gCurrentPinballGame->bonusSummaryTimer = 212;
        gCurrentPinballGame->bonusSummaryPhase = 0;
        gCurrentPinballGame->bonusSubtotal = 0;
        gCurrentPinballGame->bonusCategoryScore = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];
    }

    if (gCurrentPinballGame->bonusSummaryTimer != 0)
    {
        if (gMain.animationTimer < 150)
            gMain.animationTimer++;

        if (gCurrentPinballGame->bonusSummaryPhase < 5)
        {
            if (var0 < 89)
            {
                var2 = var0 / 24;
                if (var2 > 2)
                    var2 = 2;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    if (gCurrentPinballGame->bonusSummaryPhase == 0 || i != 2)
                    {
                        if (gCurrentPinballGame->bonusTextRevealMask[i][j] == 0 && gCurrentPinballGame->bonusTextContent[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->bonusTextRevealMask[i][j] = 1;
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
                    gCurrentPinballGame->bonusTextRevealMask[i][j] = 0;
                }
            }

            if (gCurrentPinballGame->bonusSummaryTimer == 1)
            {
                gCurrentPinballGame->bonusSummaryTimer = 212;
                gCurrentPinballGame->bonusSummaryPhase++;
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];
            }
        }
        else if (gCurrentPinballGame->bonusSummaryPhase == 5)
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
                gCurrentPinballGame->bonusSummaryTimer = 212;
                gCurrentPinballGame->bonusSummaryPhase++;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[1][j] = 0;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[2][j] = 0;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];
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
                        if (gCurrentPinballGame->bonusTextRevealMask[i][j] == 0 && gCurrentPinballGame->bonusTextContent[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->bonusTextRevealMask[i][j] = 1;
                }
            }
        }

        if (sp18)
            m4aSongNumStart(SE_UNKNOWN_0xA1);
    }

    value = 0;
    multiplier = 0;
    if (gCurrentPinballGame->bonusSummaryTimer == 212 || sp14 != 0)
    {
        switch (gCurrentPinballGame->bonusSummaryPhase)
        {
        case 0:
            value = gCurrentPinballGame->bonusCatchCount;
            multiplier = 500000;
            break;
        case 1:
            value = gCurrentPinballGame->bonusMonCatchCount;
            multiplier = 750000;
            break;
        case 2:
            value = gCurrentPinballGame->travelModeCompletionCount;
            multiplier = 500000;
            break;
        case 3:
            value = gCurrentPinballGame->catchTriggerCompletionCount;
            multiplier = 100000;
            break;
        case 4:
            value = gCurrentPinballGame->bonusPikaSaverCount;
            multiplier = 100000;
            break;
        case 5:
            value = 0;
            multiplier = 0;
            break;
        case 6:
            break;
        }

        if (gCurrentPinballGame->bonusSummaryPhase < 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            sp0[2] = value / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 2; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = value * multiplier;
            gCurrentPinballGame->bonusCategoryScore = value;
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
                gCurrentPinballGame->bonusTextContent[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->bonusSubtotal;
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
                gCurrentPinballGame->bonusTextContent[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->bonusSummaryPhase == 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->bonusSubtotal;
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
                gCurrentPinballGame->bonusTextContent[2][19 - j] = sp0[j] + 27;
        }
        else
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->bonusSubtotal;
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
                gCurrentPinballGame->bonusTextContent[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->bonusMultiplier;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 5; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            value = 0;
            var4 = 0;
            while (gCurrentPinballGame->bonusMultiplier != 0)
            {
                value += gCurrentPinballGame->bonusSubtotal;
                if (value / 200000000 > 0)
                {
                    value -= 200000000;
                    var4 += 2;
                }
                gCurrentPinballGame->bonusMultiplier--;
            }

            if (value / 100000000 > 0)
            {
                value -= 100000000;
                var4++;
            }

            gCurrentPinballGame->bonusTotalScoreHi = var4;
            gCurrentPinballGame->bonusTotalScoreLo = value;
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
                gCurrentPinballGame->bonusTextContent[2][19 - j] = sp0[j] + 27;
        }
    }

    if (var0 >= 90 && var0 <= 140)
    {
        if (gCurrentPinballGame->bonusSummaryPhase < 5)
        {
            if (gCurrentPinballGame->bonusCategoryScore != 0)
                gCurrentPinballGame->bonusSummaryTimer = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->bonusCategoryScore >= 200000)
                {
                    gCurrentPinballGame->bonusCategoryScore -= 200000;
                    gCurrentPinballGame->bonusSubtotal += 200000;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
                else if (gCurrentPinballGame->bonusCategoryScore != 0)
                {
                    gCurrentPinballGame->bonusSubtotal += gCurrentPinballGame->bonusCategoryScore;
                    gCurrentPinballGame->bonusCategoryScore = 0;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
            }

            value = gCurrentPinballGame->bonusSubtotal;
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
                gCurrentPinballGame->bonusTextContent[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->bonusSummaryPhase == 6)
        {
            gCurrentPinballGame->bonusSummaryComplete = 1;
            if (gCurrentPinballGame->bonusTotalScoreLo || gCurrentPinballGame->bonusTotalScoreHi)
                gCurrentPinballGame->bonusSummaryTimer = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->bonusTotalScoreLo >= 200000)
                {
                    gCurrentPinballGame->bonusTotalScoreLo -= 200000;
                    gCurrentPinballGame->scoreLo += 200000;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
                else if (gCurrentPinballGame->bonusTotalScoreHi != 0)
                {
                    gCurrentPinballGame->bonusTotalScoreHi--;
                    gCurrentPinballGame->bonusTotalScoreLo += 99800000;
                    gCurrentPinballGame->scoreLo += 200000;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
                else if (gCurrentPinballGame->bonusTotalScoreLo != 0)
                {
                    gCurrentPinballGame->scoreLo += gCurrentPinballGame->bonusTotalScoreLo;
                    gCurrentPinballGame->bonusTotalScoreLo = 0;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
            }

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->bonusTextContent[2][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][2][j];

            var4 = gCurrentPinballGame->bonusTotalScoreHi;
            value = gCurrentPinballGame->bonusTotalScoreLo;
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
                gCurrentPinballGame->bonusTextContent[2][19 - j] = sp0[j] + 27;
        }
    }

    if (gCurrentPinballGame->bonusSummaryTimer)
        gCurrentPinballGame->bonusSummaryTimer--;

    group = &gMain.spriteGroups[9];
    if (group->available)
    {
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->bonusSummarySlideY + 38;
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
            group->baseY = 64 + i * 16 + gCurrentPinballGame->bonusSummarySlideY + sp10;
            for (j = 0; j < 5; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}
