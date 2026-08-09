#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"

#define BALL_NORMAL_LAUNCH_SAVER_TIME TICKS_FOR_TIME(0,30)
#define BONUS_SCORE_TALLY_STEP (200 * SCORE_K)

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

    group = gMain.fieldSpriteGroups[FIELD_SG_GAME_OVER_TEXT];
    if (group->active)
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
        gMain.fieldSpriteGroups[FIELD_SG_GAME_OVER_TEXT]->active = TRUE;
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

    if (gMain.animationTimer)
    {
        if (gMain.animationTimer < 21)
        {
            if (gMain.animationTimer == 20)
                m4aSongNumStart(SE_BONUS_PANEL_SLIDE);

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
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_BANNER].active = TRUE;
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_TEXT_LINE_0].active = TRUE;
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_TEXT_LINE_1].active = TRUE;
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_TEXT_LINE_2].active = TRUE;
            DmaCopy16(3, gMainBoardEndOfBall_Gfx, (void *)0x6015800, 0x2800);
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gBonusClearTextPal_Lit, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gBonusClearTextPal_Dark, (void *)0x050003C0, 0x20);
            }

            m4aSongNumStart(SE_BONUS_PANEL_SLIDE);
            for (i = 0; i < 3; i++)
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[i][j] = FALSE;
        }
        else if (gMain.animationTimer == 1)
        {
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_BANNER].active = FALSE;
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_TEXT_LINE_0].active = FALSE;
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_TEXT_LINE_1].active = FALSE;
            gMain.spriteGroups[SG_END_OF_BALL_BONUS_TEXT_LINE_2].active = FALSE;
        }
    }
    else
    {
        gMain.modeChangeFlags &= ~MODE_CHANGE_END_OF_BALL;
        ClearDebugTextDisplay();
        if (gCurrentPinballGame->numLives > 0)
        {
            gCurrentPinballGame->saverTimeRemaining = BALL_NORMAL_LAUNCH_SAVER_TIME;
            gCurrentPinballGame->numLives--;
            gCurrentPinballGame->collisionCooldownTimer = 60;
            gCurrentPinballGame->bonusCatchCount = 0;
            gCurrentPinballGame->bonusMonEvoCount = 0;
            gCurrentPinballGame->travelModeCompletionCount = 0;
            gCurrentPinballGame->slotsPlayedCount = 0;
            gCurrentPinballGame->bonusPikaSaverCount = 0;
            gCurrentPinballGame->bonusMultiplier = 0;
            InitBallState(0);
            SetBoardCollisionConfig(0);
            gCurrentPinballGame->boardCollisionConfigChanged = FALSE;
            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
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
                RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);
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
        group = &gMain.spriteGroups[SG_BALL_SAVE_BANNER];
        if (group->active)
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

        group = &gMain.spriteGroups[SG_BALL_SAVE_LATI];
        if (group->active)
        {
            group->baseX = 24 + gCurrentPinballGame->ballSaverPosX / 100;
            group->baseY = gCurrentPinballGame->ballSaverSlideY + 20 + gCurrentPinballGame->ballSaverPosY / 100;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 4;
        }

        group = &gMain.spriteGroups[SG_BALL_SAVE_LATI_ARM];
        if (group->active)
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
                gMain.spriteGroups[SG_BALL_SAVE_LATI].active = FALSE;
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
                gMain.spriteGroups[SG_BALL_SAVE_BANNER].active = FALSE;
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
                gMain.spriteGroups[SG_BALL_SAVE_LATI_ARM].active = FALSE;
                if (gMain.animationTimer == 32)
                {
                    gCurrentPinballGame->cameraLocked = FALSE;
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
            gMain.spriteGroups[SG_BALL_SAVE_BANNER].active = TRUE;
            gMain.spriteGroups[SG_BALL_SAVE_LATI].active = TRUE;
            gMain.spriteGroups[SG_BALL_SAVE_LATI_ARM].active = TRUE;
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

            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_FROZEN;
            gCurrentPinballGame->cameraLocked = TRUE;
            gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
            gCurrentPinballGame->startButtonDisabled = TRUE;
            m4aSongNumStart(SE_BALL_SAVED);
        }
        else if (gMain.animationTimer == 0)
        {
            gMain.spriteGroups[SG_BALL_SAVE_BANNER].active = FALSE;
            gMain.spriteGroups[SG_BALL_SAVE_LATI].active = FALSE;
        }
    }
    else
    {
        gMain.modeChangeFlags &= ~MODE_CHANGE_BALL_SAVER;
        gCurrentPinballGame->collisionCooldownTimer = 60;
        InitBallState(0);
        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
        SetBoardCollisionConfig(0);
        gCurrentPinballGame->boardCollisionConfigChanged = FALSE;
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->ball->oamPriority = 3;
        else
            gCurrentPinballGame->ball->oamPriority = 1;

        gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;
        gCurrentPinballGame->activePortraitType = 0;
        gCurrentPinballGame->startButtonDisabled = FALSE;
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
    s16 textRevealTimer;
    int lineRevealSegment;
    int value;
    int scoreHi; // multiples of 100M
    int multiplier;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s8 scoreDigit[16];
    s16 subtotalSlideYPos;
    s16 userScoreDisplayAdvance;
    s16 playTextProgressSound;

    const int DIGIT_TILE_BASE_IX = 27;
    const u8 DIGIT_TILE_WITH_COMMA_OFFSET = 10;

    textRevealTimer = 212 - gCurrentPinballGame->bonusSummaryTimer;
    subtotalSlideYPos = 0;
    userScoreDisplayAdvance = FALSE;
    playTextProgressSound = FALSE;

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
                textRevealTimer = 100;
                gCurrentPinballGame->bonusSummaryPhase = 6;
                gCurrentPinballGame->bonusSubtotal =
                    gCurrentPinballGame->bonusCatchCount * SCORE_BONUS_PER_CATCH +
                    gCurrentPinballGame->bonusMonEvoCount * SCORE_BONUS_PER_EVO +
                    gCurrentPinballGame->travelModeCompletionCount * SCORE_BONUS_PER_TRAVEL +
                    gCurrentPinballGame->slotsPlayedCount * SCORE_BONUS_PER_SLOTS_PLAYED +
                    gCurrentPinballGame->bonusPikaSaverCount * SCORE_BONUS_PER_PIKA_SAVER;

                gCurrentPinballGame->bonusCategoryScore = 0;
                gMain.animationTimer = 150;

                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[0][j] = TRUE;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[1][j] = TRUE;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[2][j] = TRUE;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];

                userScoreDisplayAdvance = TRUE;
            }
            else
            {
                gCurrentPinballGame->bonusSummaryTimer = 1;
                gMain.animationTimer = 51;
                textRevealTimer = 100;
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
            if (textRevealTimer < 89)
            {
                lineRevealSegment = textRevealTimer / 24;
                if (lineRevealSegment > 2)
                    lineRevealSegment = 2;

                for (i = 0; i <= lineRevealSegment; i++)
                {
                    j = ((textRevealTimer - i * 24) % 40) / 2;
                    if (gCurrentPinballGame->bonusSummaryPhase == 0 || i != 2)
                    {
                        if (!gCurrentPinballGame->bonusTextRevealMask[i][j]
                            && gCurrentPinballGame->bonusTextContent[i][j] != 95)
                        {
                            playTextProgressSound = TRUE;
                        }
                    }

                    gCurrentPinballGame->bonusTextRevealMask[i][j] = TRUE;
                }
            }
            else if (textRevealTimer >= 148)
            {
                textRevealTimer = textRevealTimer - 148;
                lineRevealSegment = textRevealTimer / 24;
                if (lineRevealSegment > 1)
                    lineRevealSegment = 1;

                for (i = 0; i <= lineRevealSegment; i++)
                {
                    j = ((textRevealTimer - i * 24) % 40) / 2;
                    gCurrentPinballGame->bonusTextRevealMask[i][j] = FALSE;
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
            if (textRevealTimer < 17)
            {
                subtotalSlideYPos = -textRevealTimer * 2;
                if (textRevealTimer == 2)
                    m4aSongNumStart(SE_BALL_SUMMARY_PAGE_SWIPE);
            }
            else
            {
                subtotalSlideYPos = 0;
                gCurrentPinballGame->bonusSummaryTimer = 212;
                gCurrentPinballGame->bonusSummaryPhase++;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[0][j] = TRUE;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[1][j] = FALSE;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->bonusTextRevealMask[2][j] = FALSE;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];
            }
        }
        else
        {
            if (textRevealTimer < 89)
            {
                lineRevealSegment = textRevealTimer / 24;
                if (lineRevealSegment > 2)
                    lineRevealSegment = 2;

                for (i = 0; i <= lineRevealSegment; i++)
                {
                    j = ((textRevealTimer - i * 24) % 40) / 2;
                    if (i != 0)
                    {
                        if (!gCurrentPinballGame->bonusTextRevealMask[i][j]
                            && gCurrentPinballGame->bonusTextContent[i][j] != 95)
                        {
                            playTextProgressSound = TRUE;
                        }
                    }

                    gCurrentPinballGame->bonusTextRevealMask[i][j] = TRUE;
                }
            }
        }

        if (playTextProgressSound)
            m4aSongNumStart(SE_BALL_SUMMARY_TEXT_PROGRESS);
    }

    value = 0;
    multiplier = 0;
    if (gCurrentPinballGame->bonusSummaryTimer == 212 || userScoreDisplayAdvance != FALSE)
    {
        switch (gCurrentPinballGame->bonusSummaryPhase)
        {
        case 0:
            value = gCurrentPinballGame->bonusCatchCount;
            multiplier = SCORE_BONUS_PER_CATCH;
            break;
        case 1:
            value = gCurrentPinballGame->bonusMonEvoCount;
            multiplier = SCORE_BONUS_PER_EVO;
            break;
        case 2:
            value = gCurrentPinballGame->travelModeCompletionCount;
            multiplier = SCORE_BONUS_PER_TRAVEL;
            break;
        case 3:
            value = gCurrentPinballGame->slotsPlayedCount;
            multiplier = SCORE_BONUS_PER_SLOTS_PLAYED;
            break;
        case 4:
            value = gCurrentPinballGame->bonusPikaSaverCount;
            multiplier = SCORE_BONUS_PER_PIKA_SAVER;
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
            // Line 0 score display: category count
            for (i = 0; i < 10; i++)
                scoreDigit[i] = 0;
            scoreDigit[2] = LEAD_DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 2; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[0][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;

            // Line 1 score display: category bonus
            for (i = 0; i < 10; i++)
                scoreDigit[i] = 0;
            value = value * multiplier;
            gCurrentPinballGame->bonusCategoryScore = value;
            scoreDigit[7] = LEAD_DIGIT_10M(value);
            scoreDigit[6] = DIGIT_1M(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 7; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[1][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;

            // Line 2 score display: subtotal
            for (i = 0; i < 10; i++)
                scoreDigit[i] = 0;

            value = gCurrentPinballGame->bonusSubtotal;
            scoreDigit[8] = LEAD_DIGIT_100M(value);
            scoreDigit[7] = DIGIT_10M(value);
            scoreDigit[6] = DIGIT_1M(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 8; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[2][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;
        }
        else if (gCurrentPinballGame->bonusSummaryPhase == 5)
        {
            // Subtotal line (moving up to first row)
            for (i = 0; i < 10; i++)
                scoreDigit[i] = 0;
            value = gCurrentPinballGame->bonusSubtotal;
            scoreDigit[8] = LEAD_DIGIT_100M(value);
            scoreDigit[7] = DIGIT_10M(value);
            scoreDigit[6] = DIGIT_1M(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 8; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[2][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;
        }
        else
        {
            // Line 0 score display: subtotal
            for (i = 0; i < 10; i++)
                scoreDigit[i] = 0;
            value = gCurrentPinballGame->bonusSubtotal;
            scoreDigit[8] = LEAD_DIGIT_100M(value);
            scoreDigit[7] = DIGIT_10M(value);
            scoreDigit[6] = DIGIT_1M(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 8; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[0][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;

            // Line 1 score display: bonus multiplier
            for (i = 0; i < 10; i++)
                scoreDigit[i] = 0;
            value = gCurrentPinballGame->bonusMultiplier;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 5; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[1][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;

            // Line 2 score display: Total
            for (i = 0; i < 11; i++)
                scoreDigit[i] = 0;
            value = 0;
            scoreHi = 0;
            while (gCurrentPinballGame->bonusMultiplier != 0)
            {
                // Note: tallied in a loop, rather than a base multiplication to prevent integer overflow.
                value += gCurrentPinballGame->bonusSubtotal;
                if (value / (2 * SCORE_HI_STEP) > 0)
                {
                    value -= (2 * SCORE_HI_STEP);
                    scoreHi += 2;
                }
                gCurrentPinballGame->bonusMultiplier--;
            }

            if (value / SCORE_HI_STEP > 0)
            {
                value -= SCORE_HI_STEP;
                scoreHi++;
            }

            gCurrentPinballGame->bonusTotalScoreHi = scoreHi;
            gCurrentPinballGame->bonusTotalScoreLo = value;
            scoreDigit[10] = DIGIT_100S(scoreHi);
            scoreDigit[9] = DIGIT_10S(scoreHi) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[8] = DIGIT_1S(scoreHi);
            scoreDigit[7] = DIGIT_10M(value);
            scoreDigit[6] = DIGIT_1M(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 10; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[2][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;
        }
    }

    if (textRevealTimer >= 90 && textRevealTimer <= 140)
    {
        // Tally section score
        if (gCurrentPinballGame->bonusSummaryPhase < 5)
        {
            // Tally Category score into subtotal

            //While score is still tallying; don't advance the display advance timer.
            if (gCurrentPinballGame->bonusCategoryScore != 0)
                gCurrentPinballGame->bonusSummaryTimer = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->bonusCategoryScore >= BONUS_SCORE_TALLY_STEP)
                {
                    gCurrentPinballGame->bonusCategoryScore -= BONUS_SCORE_TALLY_STEP;
                    gCurrentPinballGame->bonusSubtotal += BONUS_SCORE_TALLY_STEP;
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
            scoreDigit[8] = LEAD_DIGIT_100M(value);
            scoreDigit[7] = DIGIT_10M(value);
            scoreDigit[6] = DIGIT_1M(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            for (i = 8; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[2][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;
        }
        else if (gCurrentPinballGame->bonusSummaryPhase == 6)
        {
            // Tally total bonus score into main score
            gCurrentPinballGame->bonusSummaryComplete = 1;

            //While score is still tallying; don't advance the display advance timer.
            if (gCurrentPinballGame->bonusTotalScoreLo || gCurrentPinballGame->bonusTotalScoreHi)
                gCurrentPinballGame->bonusSummaryTimer = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->bonusTotalScoreLo >= BONUS_SCORE_TALLY_STEP)
                {
                    gCurrentPinballGame->bonusTotalScoreLo -= BONUS_SCORE_TALLY_STEP;
                    gCurrentPinballGame->scoreLo += BONUS_SCORE_TALLY_STEP;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
                else if (gCurrentPinballGame->bonusTotalScoreHi != 0)
                {
                    gCurrentPinballGame->bonusTotalScoreHi--;
                    gCurrentPinballGame->bonusTotalScoreLo += (SCORE_HI_STEP - BONUS_SCORE_TALLY_STEP);
                    gCurrentPinballGame->scoreLo += BONUS_SCORE_TALLY_STEP;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
                else if (gCurrentPinballGame->bonusTotalScoreLo != 0)
                {
                    gCurrentPinballGame->scoreLo += gCurrentPinballGame->bonusTotalScoreLo;
                    gCurrentPinballGame->bonusTotalScoreLo = 0;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
            }

            // Display remaining bonus score total (line 2)
            for (i = 0; i < 11; i++)
                scoreDigit[i] = 0;
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->bonusTextContent[2][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][2][j];

            scoreHi = gCurrentPinballGame->bonusTotalScoreHi;
            value = gCurrentPinballGame->bonusTotalScoreLo;
            scoreDigit[10] = DIGIT_100S(scoreHi);
            scoreDigit[9] = DIGIT_10S(scoreHi) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[8] = DIGIT_1S(scoreHi);
            scoreDigit[7] = DIGIT_10M(value);
            scoreDigit[6] = DIGIT_1M(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[5] = DIGIT_100K(value);
            scoreDigit[4] = DIGIT_10K(value);
            scoreDigit[3] = DIGIT_1K(value) + DIGIT_TILE_WITH_COMMA_OFFSET;
            scoreDigit[2] = DIGIT_100S(value);
            scoreDigit[1] = DIGIT_10S(value);
            scoreDigit[0] = DIGIT_1S(value);
            // No display for leading 0s
            for (i = 10; i > 0 && (scoreDigit[i] <= 0 || scoreDigit[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->bonusTextContent[2][19 - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;
        }
    }

    if (gCurrentPinballGame->bonusSummaryTimer)
        gCurrentPinballGame->bonusSummaryTimer--;

    group = &gMain.spriteGroups[SG_END_OF_BALL_BONUS_BANNER];
    if (group->active)
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
            group = &gMain.spriteGroups[SG_END_OF_BALL_BONUS_TEXT_BASE + i];
            group->baseX = 104;
            group->baseY = 64 + i * 16 + gCurrentPinballGame->bonusSummarySlideY + subtotalSlideYPos;
            for (j = 0; j < 5; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}
