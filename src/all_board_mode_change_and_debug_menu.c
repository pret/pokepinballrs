#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"
#include "constants/mem_layout/shared.h"
#include "constants/mem_layout/ruby.h"

#define BALL_NORMAL_LAUNCH_SAVER_TIME TICKS_FOR_TIME(0,30)
#define BONUS_SCORE_TALLY_STEP (200 * SCORE_K)

EWRAM_DATA s16 gGameOverLetterXOffsets[8];
EWRAM_DATA s16 gGameOverLetterAmplitudes[8];
EWRAM_DATA s16 gGameOverLetterYOffsets[8];

// Rom_1 data
extern const u8 gDebugTextStrings[];
extern const u8 gDebugMenuValueTemplate[];
extern const u8 gDebugMenuCursorText[];
EXTERN_LANG5(const u8, gMainBoardBallSave_Gfx, [SIZE_OF_VRAM_BALL_SAVER_BANNER_AND_MON_TILES]);
extern const u8 gMainBoardBallSaveLatios_Gfx[SIZE_OF_VRAM_LATIOS_BALL_SAVER_TILES];
extern const u8 gMainBoardBallSaveLatiosArm_Gfx[SIZE_OF_VRAM_LATIOS_ARM_TILES];
EXTERN_LANG5(const u8, gMainBoardEndOfBall_Gfx, [SIZE_OF_VRAM_END_OF_BALL_BONUS_WINDOW_TILES]);
extern const u8 gEobBonusSummaryCharTiles[][SIZE_OF_VRAM_END_OF_BALL_BONUS_SUMMARY_TEXT_CHAR_TILES];
#ifdef EUROPE
extern const u8 gMainBoardGameOverText_Gfx_EnFrDeIt[SIZE_OF_VRAM_GAME_OVER_TEXT_TILES];
extern const u8 gMainBoardGameOverText_Gfx_Es[SIZE_OF_VRAM_GAME_OVER_TEXT_TILES];
#else
extern const u8 gMainBoardGameOverText_Gfx[SIZE_OF_VRAM_GAME_OVER_TEXT_TILES];
#endif
extern const Palette gBallSaver_Ruby_Pal;
extern const Palette gBallSaver_Sapphire_Pal;
extern const Palette gEndOfBallBonus_Ruby_Pal;
extern const Palette gEndOfBallBonus_Sapphire_Pal;

// Rom_2 data
extern const s8 gBonusSummaryTextTemplates[][EOB_SUMMARY_LINES][EOB_SUMMARY_CHARS_PER_LINE];

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

        if (gCurrentPinballGame->debugMenuSelection == DEBUG_MODE_TOGGLE_BALL_SPEED)
            DebugToggleBallSpeed();
    }
    else
    {
        switch (gCurrentPinballGame->debugMenuSelection)
        {
        case DEBUG_MODE_MOVE_BALL:
            DebugMoveBallPosition();
            break;
        case DEBUG_MODE_TOGGLE_BALL_SPEED:
            DebugToggleBallSpeed();
            break;
        }

        DrawTextToTilemap(gDebugMenuCursorText, gMain.debugMenuCursorIndex + 26, 0);
    }

    for (i = 0x340; i < 0x380; i++)
        gBG0TilemapBuffer[i] += 0xC100;

    DmaCopy16(3, gBG0TilemapBuffer, BG_VRAM_ADDR_ALL_BOARDS_DEBUG_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
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
#ifdef EUROPE
        // The letters are placed 16 pixels apart; the Spanish text has no gap between the two words.
        switch (gMain_saveData.language)
        {
        case LANGUAGE_ENGLISH:
        case LANGUAGE_FRENCH:
        case LANGUAGE_GERMAN:
        case LANGUAGE_ITALIAN:
            group->baseX = 59;
            group->baseY = 52;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + i * 16 - 4;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
            for (i = 4; i < 8; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + i * 16 + 4;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
            break;
        case LANGUAGE_SPANISH:
            group->baseX = 55;
            group->baseY = 52;
            for (i = 0; i < 8; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + i * 16;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
            break;
        }
#else
        group->baseX = 63;
        group->baseY = 52;
        for (i = 0; i < 8; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
#endif
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
#ifdef EUROPE
        switch (gMain_saveData.language)
        {
        case LANGUAGE_ENGLISH:
        case LANGUAGE_FRENCH:
        case LANGUAGE_GERMAN:
        case LANGUAGE_ITALIAN:
            DmaCopy16(3, gMainBoardGameOverText_Gfx_EnFrDeIt, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_GAME_OVER_TEXT_TILES);
            break;
        case LANGUAGE_SPANISH:
            DmaCopy16(3, gMainBoardGameOverText_Gfx_Es, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_GAME_OVER_TEXT_TILES);
            break;
        }
#else
        DmaCopy16(3, gMainBoardGameOverText_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_GAME_OVER_TEXT_TILES);
#endif
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
            DMA_LANG5(gMainBoardEndOfBall_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_END_OF_BALL_BONUS_WINDOW_TILES);
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gEndOfBallBonus_Ruby_Pal, OBJ_PLTT_SLOT(PAL_IX_BANNER), PLTT_SLOT_SIZE);
            }
            else
            {
                DmaCopy16(3, gEndOfBallBonus_Sapphire_Pal, OBJ_PLTT_SLOT(PAL_IX_BANNER), PLTT_SLOT_SIZE);
            }

            m4aSongNumStart(SE_BONUS_PANEL_SLIDE);
            for (i = 0; i < EOB_SUMMARY_LINES; i++)
                for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
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
            gCurrentPinballGame->endOfBallBonusMultiplier = 0;
            InitBallState(0);
            SetBoardCollisionConfig(0);
            gCurrentPinballGame->boardCollisionConfigChanged = FALSE;
            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % BONUS_STAGE_LOOP_COUNT)
                {
                case BONUS_STAGE_LOOP_START:
                case BONUS_STAGE_LOOP_FIRST_BOSS_CLEARED:
                    m4aSongNumStart(MUS_BONUS_CHANCE);
                    break;
                case BONUS_STAGE_LOOP_FIRST_SIMPLE_CLEARED:
                case BONUS_STAGE_LOOP_SECOND_SIMPLE_CLEARED:
                case BONUS_STAGE_LOOP_SECOND_BOSS_CLEARED:
                    m4aSongNumStart(MUS_BONUS_CHANCE_LEGENDARY);
                    break;
                }
            }
            else
            {
                RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);
            }

            gCurrentPinballGame->activeFxType = FX_NONE;
        }
        else
        {
            gMain.modeChangeFlags |= MODE_CHANGE_END_OF_GAME;
            gMain.animationTimer = 3600;
            m4aSongNumStart(MUS_SLOTS_PRIZE);
        }
    }
}

// Only the Ruby board loads the separate Latios sprites.
#define LOAD_BALL_SAVER_GFX(bannerGfx)                                                                                  \
    if (gMain.selectedField == FIELD_RUBY)                                                                              \
    {                                                                                                                   \
        DmaCopy16(3, bannerGfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_BALL_SAVER_BANNER_AND_MON_TILES);                    \
        DmaCopy16(3, gMainBoardBallSaveLatios_Gfx, OBJ_VRAM_ADDR_LATIOS_BALL_SAVER_TILES, SIZE_OF_VRAM_LATIOS_BALL_SAVER_TILES); \
        DmaCopy16(3, gMainBoardBallSaveLatiosArm_Gfx, OBJ_VRAM_ADDR_LATIOS_ARM_TILES, SIZE_OF_VRAM_LATIOS_ARM_TILES);   \
        DmaCopy16(3, gBallSaver_Ruby_Pal, OBJ_PLTT_SLOT(PAL_IX_LATI_BALL_SAVER), PLTT_SLOT_SIZE);                       \
    }                                                                                                                   \
    else                                                                                                                \
    {                                                                                                                   \
        DmaCopy16(3, bannerGfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_BALL_SAVER_BANNER_AND_MON_TILES);                    \
        DmaCopy16(3, gBallSaver_Sapphire_Pal, OBJ_PLTT_SLOT(PAL_IX_LATI_BALL_SAVER), PLTT_SLOT_SIZE);                   \
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
            gCurrentPinballGame->ballSaverPosY = MulSin(500, (var0 * 0x400));
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
#ifdef EUROPE
            switch (gMain_saveData.language)
            {
            case LANGUAGE_ENGLISH:
                LOAD_BALL_SAVER_GFX(gMainBoardBallSave_Gfx_En);
                break;
            case LANGUAGE_FRENCH:
                LOAD_BALL_SAVER_GFX(gMainBoardBallSave_Gfx_Fr);
                break;
            case LANGUAGE_GERMAN:
                LOAD_BALL_SAVER_GFX(gMainBoardBallSave_Gfx_De);
                break;
            case LANGUAGE_ITALIAN:
                LOAD_BALL_SAVER_GFX(gMainBoardBallSave_Gfx_It);
                break;
            case LANGUAGE_SPANISH:
                LOAD_BALL_SAVER_GFX(gMainBoardBallSave_Gfx_Es);
                break;
            }
#else
            LOAD_BALL_SAVER_GFX(gMainBoardBallSave_Gfx);
#endif

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
        gCurrentPinballGame->activeFxType = FX_NONE;
        gCurrentPinballGame->startButtonDisabled = FALSE;
    }
}

void ClearDebugTextDisplay(void)
{
    int i;
    for (i = 0x340; i < 0x380; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gBG0TilemapBuffer, BG_VRAM_ADDR_ALL_BOARDS_DEBUG_TILEMAP, MEM_SIZE_OF_TILEMAP_256_BY_256);
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
#if defined(EUROPE) && !defined(NONMATCHING)
// The European build differs in register allocation / cross-jumping; use the original code.
NAKED
void EndOfBallBonusSummary(void)
{
    asm_unified(
	"\tpush {r4, r5, r6, r7, lr}\n"
	"\tmov r7, sl\n"
	"\tmov r6, sb\n"
	"\tmov r5, r8\n"
	"\tpush {r5, r6, r7}\n"
	"\tsub sp, #0x30\n"
	"\tldr r2, _0804CC98\n"
	"\tldr r0, [r2]\n"
	"\tldr r1, _0804CC9C\n"
	"\tadds r0, r0, r1\n"
	"\tldrh r1, [r0]\n"
	"\tmovs r0, #0xD4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r0, r0, #0x10\n"
	"\tlsrs r0, r0, #0x10\n"
	"\tstr r0, [sp, #0x10]\n"
	"\tmovs r3, #0\n"
	"\tstr r3, [sp, #0x14]\n"
	"\tmovs r4, #0\n"
	"\tstr r4, [sp, #0x18]\n"
	"\tmovs r6, #0\n"
	"\tstr r6, [sp, #0x1C]\n"
	"\tmovs r7, #0\n"
	"\tstr r7, [sp, #0x20]\n"
	"\tldr r0, _0804CCA0\n"
	"\tadds r0, #0xCD\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #4\n"
	"\tbhi _0804CCD8\n"
	"\tlsls r0, r0, #2\n"
	"\tldr r1, _0804CCA4\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"_0804CC98:\t.4byte gCurrentPinballGame\n"
	"_0804CC9C:\t.4byte 0x63A\n"
	"_0804CCA0:\t.4byte gMain + 0x74\n"
	"_0804CCA4:\t.4byte _0804CCA8\n"
	"_0804CCA8:\t.4byte _0804CCBC @ case 0\n"
	"\t.4byte _0804CCC2 @ case 1\n"
	"\t.4byte _0804CCC8 @ case 2\n"
	"\t.4byte _0804CCCE @ case 3\n"
	"\t.4byte _0804CCD4 @ case 4\n"
	"_0804CCBC:\tmovs r0, #0\n"
	"\tstr r0, [sp, #0x20]\n"
	"\tb _0804CCD8\n"
	"_0804CCC2:\tmovs r1, #1\n"
	"\tstr r1, [sp, #0x20]\n"
	"\tb _0804CCD8\n"
	"_0804CCC8:\tmovs r2, #3\n"
	"\tstr r2, [sp, #0x20]\n"
	"\tb _0804CCD8\n"
	"_0804CCCE:\tmovs r3, #2\n"
	"\tstr r3, [sp, #0x20]\n"
	"\tb _0804CCD8\n"
	"_0804CCD4:\tmovs r4, #4\n"
	"\tstr r4, [sp, #0x20]\n"
	"_0804CCD8:\tmovs r4, #0\n"
	"\tldr r7, _0804CD14\n"
	"\tldr r0, [r7]\n"
	"\tldr r2, _0804CD18\n"
	"\tmovs r6, #0xCF\n"
	"\tlsls r6, r6, #3\n"
	"\tadds r6, r6, r0\n"
	"\tmov r8, r6\n"
	"_0804CCE8:\tlsls r0, r4, #2\n"
	"\tadds r1, r4, #1\n"
	"\tmov ip, r1\n"
	"\tadds r0, r0, r4\n"
	"\tmovs r1, #0x16\n"
	"\tmuls r1, r4, r1\n"
	"\tadds r1, #0xE0\n"
	"\tlsls r4, r0, #2\n"
	"\tmovs r5, #0x13\n"
	"\tlsls r3, r1, #5\n"
	"_0804CCFC:\tmov r6, r8\n"
	"\tadds r0, r6, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #0x10\n"
	"\tlsrs r1, r0, #0x10\n"
	"\tasrs r0, r0, #0x10\n"
	"\tcmp r0, #0x13\n"
	"\tbgt _0804CD1C\n"
	"\tadds r0, #0x1B\n"
	"\tb _0804CD72\n"
	"_0804CD14:\t.4byte gCurrentPinballGame\n"
	"_0804CD18:\t.4byte 0x40000D4\n"
	"_0804CD1C:\tcmp r0, #0x5F\n"
	"\tbne _0804CD24\n"
	"\tmovs r1, #0x38\n"
	"\tb _0804CD76\n"
	"_0804CD24:\tcmp r0, #0x5E\n"
	"\tbne _0804CD2C\n"
	"\tmovs r1, #0x2F\n"
	"\tb _0804CD76\n"
	"_0804CD2C:\tcmp r0, #0x2D\n"
	"\tbne _0804CD34\n"
	"\tmovs r1, #0x30\n"
	"\tb _0804CD76\n"
	"_0804CD34:\tcmp r0, #0x61\n"
	"\tbne _0804CD3C\n"
	"\tmovs r1, #0x31\n"
	"\tb _0804CD76\n"
	"_0804CD3C:\tcmp r0, #0x31\n"
	"\tbne _0804CD44\n"
	"\tmovs r1, #0x32\n"
	"\tb _0804CD76\n"
	"_0804CD44:\tcmp r0, #0x32\n"
	"\tbne _0804CD4C\n"
	"\tmovs r1, #0x33\n"
	"\tb _0804CD76\n"
	"_0804CD4C:\tcmp r0, #0x33\n"
	"\tbne _0804CD54\n"
	"\tmovs r1, #0x34\n"
	"\tb _0804CD76\n"
	"_0804CD54:\tcmp r0, #0x2E\n"
	"\tbne _0804CD5C\n"
	"\tmovs r1, #0x35\n"
	"\tb _0804CD76\n"
	"_0804CD5C:\tcmp r0, #0x3A\n"
	"\tbne _0804CD64\n"
	"\tmovs r1, #0x36\n"
	"\tb _0804CD76\n"
	"_0804CD64:\tcmp r0, #0x73\n"
	"\tbne _0804CD6C\n"
	"\tmovs r1, #0x37\n"
	"\tb _0804CD76\n"
	"_0804CD6C:\tcmp r0, #0x2E\n"
	"\tble _0804CD76\n"
	"\tsubs r0, #0x41\n"
	"_0804CD72:\tlsls r0, r0, #0x10\n"
	"\tlsrs r1, r0, #0x10\n"
	"_0804CD76:\tldr r0, [r7]\n"
	"\tldr r6, _0804CD98\n"
	"\tadds r0, r0, r6\n"
	"\tadds r0, r0, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804CDA4\n"
	"\tlsls r0, r1, #0x10\n"
	"\tasrs r0, r0, #0xB\n"
	"\tldr r1, _0804CD9C\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tldr r1, _0804CDA0\n"
	"\tadds r0, r3, r1\n"
	"\tb _0804CDAC\n"
	"_0804CD98:\t.4byte 0x63C\n"
	"_0804CD9C:\t.4byte gEobBonusSummaryCharTiles\n"
	"_0804CDA0:\t.4byte 0x6015800\n"
	"_0804CDA4:\tldr r0, _0804CF18\n"
	"\tstr r0, [r2]\n"
	"\tldr r6, _0804CF1C\n"
	"\tadds r0, r3, r6\n"
	"_0804CDAC:\tstr r0, [r2, #4]\n"
	"\tldr r0, _0804CF20\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tadds r3, #0x20\n"
	"\tadds r4, #1\n"
	"\tsubs r5, #1\n"
	"\tcmp r5, #0\n"
	"\tbge _0804CCFC\n"
	"\tmov r4, ip\n"
	"\tcmp r4, #2\n"
	"\tble _0804CCE8\n"
	"\tldr r7, _0804CF24\n"
	"\tldrh r0, [r7, #0x12]\n"
	"\tcmp r0, #0xB3\n"
	"\tbls _0804CDCE\n"
	"\tb _0804CF96\n"
	"_0804CDCE:\tcmp r0, #0x32\n"
	"\tbhi _0804CDD4\n"
	"\tb _0804CF96\n"
	"_0804CDD4:\tldrh r1, [r7, #0x18]\n"
	"\tmovs r2, #1\n"
	"\tadds r0, r2, #0\n"
	"\tands r0, r1\n"
	"\tcmp r0, #0\n"
	"\tbne _0804CDE2\n"
	"\tb _0804CF96\n"
	"_0804CDE2:\tldr r0, _0804CF28\n"
	"\tldr r3, [r0]\n"
	"\tldr r1, _0804CF2C\n"
	"\tadds r0, r3, r1\n"
	"\tmovs r6, #0\n"
	"\tldrsb r6, [r0, r6]\n"
	"\tcmp r6, #0\n"
	"\tbeq _0804CDF4\n"
	"\tb _0804CF50\n"
	"_0804CDF4:\tldr r2, _0804CF30\n"
	"\tadds r1, r3, r2\n"
	"\tmovs r0, #0x64\n"
	"\tstrh r0, [r1]\n"
	"\tmovs r4, #0x64\n"
	"\tstr r4, [sp, #0x10]\n"
	"\tmovs r7, #0xC7\n"
	"\tlsls r7, r7, #3\n"
	"\tadds r1, r3, r7\n"
	"\tmovs r0, #6\n"
	"\tstrb r0, [r1]\n"
	"\tldr r0, _0804CF28\n"
	"\tldr r4, [r0]\n"
	"\tmovs r1, #0xC6\n"
	"\tlsls r1, r1, #3\n"
	"\tadds r5, r4, r1\n"
	"\tsubs r2, #0x10\n"
	"\tadds r0, r4, r2\n"
	"\tldrb r1, [r0]\n"
	"\tlsls r0, r1, #5\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r2, r0, #6\n"
	"\tsubs r2, r2, r0\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r2, r2, r1\n"
	"\tlsls r2, r2, #5\n"
	"\tldr r3, _0804CF34\n"
	"\tadds r0, r4, r3\n"
	"\tldrb r1, [r0]\n"
	"\tldr r0, _0804CF38\n"
	"\tmuls r0, r1, r0\n"
	"\tadds r2, r2, r0\n"
	"\tsubs r7, #0xC\n"
	"\tadds r0, r4, r7\n"
	"\tldrb r3, [r0]\n"
	"\tlsls r1, r3, #5\n"
	"\tsubs r1, r1, r3\n"
	"\tlsls r0, r1, #6\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r0, r0, #3\n"
	"\tadds r0, r0, r3\n"
	"\tlsls r0, r0, #5\n"
	"\tadds r2, r2, r0\n"
	"\tldr r1, _0804CF3C\n"
	"\tadds r0, r4, r1\n"
	"\tldrb r0, [r0]\n"
	"\tldr r1, _0804CF40\n"
	"\tmuls r0, r1, r0\n"
	"\tadds r2, r2, r0\n"
	"\tldr r3, _0804CF44\n"
	"\tadds r0, r4, r3\n"
	"\tldrb r0, [r0]\n"
	"\tmuls r0, r1, r0\n"
	"\tadds r2, r2, r0\n"
	"\tstr r2, [r5]\n"
	"\tadds r7, #8\n"
	"\tadds r4, r4, r7\n"
	"\tstr r6, [r4]\n"
	"\tmovs r0, #0x96\n"
	"\tldr r1, _0804CF24\n"
	"\tstrh r0, [r1, #0x12]\n"
	"\tmovs r5, #0\n"
	"\tldr r2, [sp, #0x20]\n"
	"\tlsls r6, r2, #0x10\n"
	"\tldr r2, _0804CF28\n"
	"\tadds r7, #8\n"
	"\tmovs r3, #1\n"
	"_0804CE7A:\tldr r0, [r2]\n"
	"\tadds r0, r0, r7\n"
	"\tadds r0, r0, r5\n"
	"\tstrb r3, [r0]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804CE7A\n"
	"\tmovs r5, #0\n"
	"\tldr r3, _0804CF28\n"
	"\tmovs r2, #0xCA\n"
	"\tlsls r2, r2, #3\n"
	"\tmovs r1, #1\n"
	"_0804CE92:\tldr r0, [r3]\n"
	"\tadds r0, r0, r2\n"
	"\tadds r0, r0, r5\n"
	"\tstrb r1, [r0]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804CE92\n"
	"\tmovs r5, #0\n"
	"\tldr r3, _0804CF28\n"
	"\tldr r2, _0804CF48\n"
	"\tmovs r1, #1\n"
	"_0804CEA8:\tldr r0, [r3]\n"
	"\tadds r0, r0, r2\n"
	"\tadds r0, r0, r5\n"
	"\tstrb r1, [r0]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804CEA8\n"
	"\tmovs r4, #0\n"
	"\tldr r3, _0804CF4C\n"
	"\tmov sl, r3\n"
	"\tasrs r0, r6, #0x10\n"
	"\tlsls r1, r0, #3\n"
	"\tsubs r1, r1, r0\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r6, r0, #2\n"
	"\tldr r7, _0804CF28\n"
	"\tmov sb, r7\n"
	"\tmovs r0, #0xCF\n"
	"\tlsls r0, r0, #3\n"
	"\tmov r8, r0\n"
	"\tmovs r7, #0xC7\n"
	"\tlsls r7, r7, #3\n"
	"_0804CED6:\tmovs r5, #0\n"
	"\tlsls r0, r4, #2\n"
	"\tadds r1, r4, #1\n"
	"\tmov ip, r1\n"
	"\tadds r0, r0, r4\n"
	"\tlsls r4, r0, #2\n"
	"_0804CEE2:\tmov r2, sb\n"
	"\tldr r0, [r2]\n"
	"\tadds r2, r5, r4\n"
	"\tmov r1, r8\n"
	"\tadds r3, r0, r1\n"
	"\tadds r3, r3, r2\n"
	"\tadds r0, r0, r7\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r2, r2, r0\n"
	"\tadds r2, r2, r6\n"
	"\tadd r2, sl\n"
	"\tldrb r0, [r2]\n"
	"\tstrb r0, [r3]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804CEE2\n"
	"\tmov r4, ip\n"
	"\tcmp r4, #2\n"
	"\tble _0804CED6\n"
	"\tmovs r2, #1\n"
	"\tstr r2, [sp, #0x18]\n"
	"\tb _0804CF96\n"
	"\tmovs r0, r0\n"
	"_0804CF18:\t.4byte gEobBonusSummaryCharTiles + 0x700\n"
	"_0804CF1C:\t.4byte 0x6015800\n"
	"_0804CF20:\t.4byte 0x80000010\n"
	"_0804CF24:\t.4byte gMain\n"
	"_0804CF28:\t.4byte gCurrentPinballGame\n"
	"_0804CF2C:\t.4byte 0x639\n"
	"_0804CF30:\t.4byte 0x63A\n"
	"_0804CF34:\t.4byte 0x62B\n"
	"_0804CF38:\t.4byte 0xB71B0\n"
	"_0804CF3C:\t.4byte 0x62D\n"
	"_0804CF40:\t.4byte 0x186A0\n"
	"_0804CF44:\t.4byte 0x62E\n"
	"_0804CF48:\t.4byte 0x664\n"
	"_0804CF4C:\t.4byte gBonusSummaryTextTemplates\n"
	"_0804CF50:\tldr r4, _0804D0F8\n"
	"\tadds r0, r3, r4\n"
	"\tmovs r5, #0\n"
	"\tstrh r2, [r0]\n"
	"\tmovs r0, #0x33\n"
	"\tldr r6, _0804D0FC\n"
	"\tstrh r0, [r6, #0x12]\n"
	"\tmovs r7, #0x64\n"
	"\tstr r7, [sp, #0x10]\n"
	"\tldr r0, _0804D100\n"
	"\tadds r4, r3, r0\n"
	"\tldr r1, [r4]\n"
	"\tcmp r1, #0\n"
	"\tbne _0804CF78\n"
	"\tmovs r2, #0xD7\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r0, r3, r2\n"
	"\tldr r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804CF96\n"
	"_0804CF78:\tldr r0, [r3, #0x44]\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r3, #0x44]\n"
	"\tmovs r6, #0xD7\n"
	"\tlsls r6, r6, #3\n"
	"\tadds r2, r3, r6\n"
	"\tldr r0, [r3, #0x48]\n"
	"\tldr r1, [r2]\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r3, #0x48]\n"
	"\tstr r5, [r4]\n"
	"\tstr r5, [r2]\n"
	"\tmovs r0, #0x91\n"
	"\tbl m4aSongNumStart\n"
	"_0804CF96:\tldr r0, _0804D0FC\n"
	"\tldrh r1, [r0, #0x12]\n"
	"\tldr r7, [sp, #0x10]\n"
	"\tlsls r7, r7, #0x10\n"
	"\tstr r7, [sp, #0x24]\n"
	"\tcmp r1, #0xB9\n"
	"\tbne _0804D02E\n"
	"\tldr r1, _0804D104\n"
	"\tldr r0, [r1]\n"
	"\tldr r2, _0804D108\n"
	"\tadds r0, r0, r2\n"
	"\tmovs r3, #0\n"
	"\tstrb r3, [r0]\n"
	"\tldr r1, [r1]\n"
	"\tldr r4, _0804D0F8\n"
	"\tadds r2, r1, r4\n"
	"\tmovs r4, #0\n"
	"\tmovs r0, #0xD4\n"
	"\tstrh r0, [r2]\n"
	"\tmovs r2, #0xC7\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r1, r1, r2\n"
	"\tstrb r4, [r1]\n"
	"\tldr r6, _0804D104\n"
	"\tldr r0, [r6]\n"
	"\tmovs r7, #0xC6\n"
	"\tlsls r7, r7, #3\n"
	"\tadds r1, r0, r7\n"
	"\tstr r3, [r1]\n"
	"\tldr r1, _0804D10C\n"
	"\tadds r0, r0, r1\n"
	"\tstr r3, [r0]\n"
	"\tmovs r4, #0\n"
	"\tldr r3, _0804D110\n"
	"\tmov sl, r3\n"
	"\tldr r6, [sp, #0x20]\n"
	"\tlsls r1, r6, #3\n"
	"\tsubs r1, r1, r6\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r6, r0, #2\n"
	"\tldr r7, _0804D104\n"
	"\tmov sb, r7\n"
	"\tmovs r0, #0xCF\n"
	"\tlsls r0, r0, #3\n"
	"\tmov r8, r0\n"
	"\tadds r7, r2, #0\n"
	"_0804CFF4:\tmovs r5, #0\n"
	"\tlsls r0, r4, #2\n"
	"\tadds r1, r4, #1\n"
	"\tmov ip, r1\n"
	"\tadds r0, r0, r4\n"
	"\tlsls r4, r0, #2\n"
	"_0804D000:\tmov r2, sb\n"
	"\tldr r0, [r2]\n"
	"\tadds r2, r5, r4\n"
	"\tmov r1, r8\n"
	"\tadds r3, r0, r1\n"
	"\tadds r3, r3, r2\n"
	"\tadds r0, r0, r7\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r2, r2, r0\n"
	"\tadds r2, r2, r6\n"
	"\tadd r2, sl\n"
	"\tldrb r0, [r2]\n"
	"\tstrb r0, [r3]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804D000\n"
	"\tmov r4, ip\n"
	"\tcmp r4, #2\n"
	"\tble _0804CFF4\n"
	"_0804D02E:\tldr r2, _0804D104\n"
	"\tldr r0, [r2]\n"
	"\tldr r4, _0804D0F8\n"
	"\tadds r0, r0, r4\n"
	"\tldrh r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbne _0804D03E\n"
	"\tb _0804D36E\n"
	"_0804D03E:\tldr r3, _0804D0FC\n"
	"\tldrh r0, [r3, #0x12]\n"
	"\tcmp r0, #0x95\n"
	"\tbhi _0804D04A\n"
	"\tadds r0, #1\n"
	"\tstrh r0, [r3, #0x12]\n"
	"_0804D04A:\tldr r6, _0804D104\n"
	"\tldr r1, [r6]\n"
	"\tmovs r7, #0xC7\n"
	"\tlsls r7, r7, #3\n"
	"\tadds r3, r1, r7\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tcmp r0, #4\n"
	"\tble _0804D05E\n"
	"\tb _0804D1F4\n"
	"_0804D05E:\tldr r1, [sp, #0x24]\n"
	"\tasrs r0, r1, #0x10\n"
	"\tcmp r0, #0x58\n"
	"\tbgt _0804D118\n"
	"\tmovs r1, #0x18\n"
	"\tbl __divsi3\n"
	"\tlsls r0, r0, #0x10\n"
	"\tasrs r7, r0, #0x10\n"
	"\tcmp r7, #2\n"
	"\tble _0804D076\n"
	"\tmovs r7, #2\n"
	"_0804D076:\tmovs r4, #0\n"
	"\tcmp r4, r7\n"
	"\tbgt _0804D16C\n"
	"\tmovs r6, #0\n"
	"\tmovs r3, #0\n"
	"_0804D080:\tldr r2, [sp, #0x24]\n"
	"\tasrs r0, r2, #0x10\n"
	"\tsubs r0, r0, r3\n"
	"\tmovs r1, #0x28\n"
	"\tstr r3, [sp, #0x2C]\n"
	"\tbl __modsi3\n"
	"\tlsrs r1, r0, #0x1F\n"
	"\tadds r0, r0, r1\n"
	"\tasrs r5, r0, #1\n"
	"\tldr r0, _0804D104\n"
	"\tldr r1, [r0]\n"
	"\tmovs r2, #0xC7\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r0, r1, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tldr r3, [sp, #0x2C]\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804D0AE\n"
	"\tcmp r4, #2\n"
	"\tbeq _0804D0DA\n"
	"_0804D0AE:\tadds r2, r5, r6\n"
	"\tldr r0, _0804D114\n"
	"\tadds r0, r0, r1\n"
	"\tmov r8, r0\n"
	"\tadd r8, r2\n"
	"\tmov r0, r8\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbne _0804D0DA\n"
	"\tmovs r0, #0xCF\n"
	"\tlsls r0, r0, #3\n"
	"\tadds r1, r1, r0\n"
	"\tadds r0, r1, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0x5F\n"
	"\tbeq _0804D0DA\n"
	"\tmovs r1, #1\n"
	"\tstr r1, [sp, #0x1C]\n"
	"_0804D0DA:\tldr r2, _0804D104\n"
	"\tldr r0, [r2]\n"
	"\tadds r1, r5, r6\n"
	"\tldr r2, _0804D114\n"
	"\tadds r0, r0, r2\n"
	"\tadds r0, r0, r1\n"
	"\tmovs r1, #1\n"
	"\tstrb r1, [r0]\n"
	"\tadds r6, #0x14\n"
	"\tadds r3, #0x18\n"
	"\tadds r4, #1\n"
	"\tcmp r4, r7\n"
	"\tble _0804D080\n"
	"\tb _0804D16C\n"
	"\tmovs r0, r0\n"
	"_0804D0F8:\t.4byte 0x63A\n"
	"_0804D0FC:\t.4byte gMain\n"
	"_0804D100:\t.4byte 0x6B4\n"
	"_0804D104:\t.4byte gCurrentPinballGame\n"
	"_0804D108:\t.4byte 0x639\n"
	"_0804D10C:\t.4byte 0x634\n"
	"_0804D110:\t.4byte gBonusSummaryTextTemplates\n"
	"_0804D114:\t.4byte 0x63C\n"
	"_0804D118:\tcmp r0, #0x93\n"
	"\tble _0804D16C\n"
	"\tsubs r0, #0x94\n"
	"\tlsls r4, r0, #0x10\n"
	"\tasrs r5, r4, #0x10\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0x18\n"
	"\tbl __divsi3\n"
	"\tlsls r0, r0, #0x10\n"
	"\tasrs r7, r0, #0x10\n"
	"\tcmp r7, #1\n"
	"\tble _0804D134\n"
	"\tmovs r7, #1\n"
	"_0804D134:\tstr r4, [sp, #0x24]\n"
	"\tcmp r7, #0\n"
	"\tblt _0804D16C\n"
	"\tmovs r2, #0\n"
	"\tadds r6, r5, #0\n"
	"\tadds r4, r7, #1\n"
	"_0804D140:\tadds r0, r6, #0\n"
	"\tmovs r1, #0x28\n"
	"\tstr r2, [sp, #0x28]\n"
	"\tbl __modsi3\n"
	"\tlsrs r1, r0, #0x1F\n"
	"\tadds r0, r0, r1\n"
	"\tasrs r5, r0, #1\n"
	"\tldr r3, _0804D1E4\n"
	"\tldr r1, [r3]\n"
	"\tldr r2, [sp, #0x28]\n"
	"\tadds r0, r5, r2\n"
	"\tldr r7, _0804D1E8\n"
	"\tadds r1, r1, r7\n"
	"\tadds r1, r1, r0\n"
	"\tmovs r0, #0\n"
	"\tstrb r0, [r1]\n"
	"\tadds r2, #0x14\n"
	"\tsubs r6, #0x18\n"
	"\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tbne _0804D140\n"
	"_0804D16C:\tldr r0, _0804D1E4\n"
	"\tldr r1, [r0]\n"
	"\tldr r3, _0804D1EC\n"
	"\tadds r2, r1, r3\n"
	"\tldrh r0, [r2]\n"
	"\tcmp r0, #1\n"
	"\tbeq _0804D17C\n"
	"\tb _0804D362\n"
	"_0804D17C:\tmovs r0, #0xD4\n"
	"\tstrh r0, [r2]\n"
	"\tmovs r2, #0xC7\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r1, r1, r2\n"
	"\tldrb r0, [r1]\n"
	"\tadds r0, #1\n"
	"\tstrb r0, [r1]\n"
	"\tmovs r4, #0\n"
	"\tldr r6, [sp, #0x20]\n"
	"\tlsls r1, r6, #3\n"
	"\tsubs r1, r1, r6\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r6, r0, #2\n"
	"\tldr r7, _0804D1E4\n"
	"\tmov sl, r7\n"
	"\tmovs r0, #0xCF\n"
	"\tlsls r0, r0, #3\n"
	"\tmov sb, r0\n"
	"\tmov r8, r2\n"
	"_0804D1A6:\tmovs r5, #0\n"
	"\tlsls r0, r4, #2\n"
	"\tadds r1, r4, #1\n"
	"\tmov ip, r1\n"
	"\tadds r0, r0, r4\n"
	"\tlsls r7, r0, #2\n"
	"_0804D1B2:\tmov r2, sl\n"
	"\tldr r0, [r2]\n"
	"\tadds r2, r5, r7\n"
	"\tmov r4, sb\n"
	"\tadds r3, r0, r4\n"
	"\tadds r3, r3, r2\n"
	"\tadd r0, r8\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r2, r2, r0\n"
	"\tadds r2, r2, r6\n"
	"\tldr r0, _0804D1F0\n"
	"\tadds r2, r2, r0\n"
	"\tldrb r0, [r2]\n"
	"\tstrb r0, [r3]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804D1B2\n"
	"\tmov r4, ip\n"
	"\tcmp r4, #2\n"
	"\tble _0804D1A6\n"
	"\tb _0804D362\n"
	"_0804D1E4:\t.4byte gCurrentPinballGame\n"
	"_0804D1E8:\t.4byte 0x63C\n"
	"_0804D1EC:\t.4byte 0x63A\n"
	"_0804D1F0:\t.4byte gBonusSummaryTextTemplates\n"
	"_0804D1F4:\tcmp r0, #5\n"
	"\tbne _0804D2DC\n"
	"\tldr r6, [sp, #0x24]\n"
	"\tasrs r2, r6, #0x10\n"
	"\tcmp r2, #0x10\n"
	"\tbgt _0804D216\n"
	"\trsbs r0, r2, #0\n"
	"\tlsls r0, r0, #0x11\n"
	"\tlsrs r0, r0, #0x10\n"
	"\tstr r0, [sp, #0x14]\n"
	"\tcmp r2, #2\n"
	"\tbeq _0804D20E\n"
	"\tb _0804D362\n"
	"_0804D20E:\tmovs r0, #0xA2\n"
	"\tbl m4aSongNumStart\n"
	"\tb _0804D362\n"
	"_0804D216:\tmovs r7, #0\n"
	"\tstr r7, [sp, #0x14]\n"
	"\tadds r1, r1, r4\n"
	"\tmovs r0, #0xD4\n"
	"\tstrh r0, [r1]\n"
	"\tldrb r0, [r3]\n"
	"\tadds r0, #1\n"
	"\tstrb r0, [r3]\n"
	"\tmovs r5, #0\n"
	"\tldr r0, [sp, #0x20]\n"
	"\tlsls r6, r0, #0x10\n"
	"\tldr r2, _0804D2CC\n"
	"\tldr r7, _0804D2D0\n"
	"\tmovs r3, #1\n"
	"_0804D232:\tldr r0, [r2]\n"
	"\tadds r0, r0, r7\n"
	"\tadds r0, r0, r5\n"
	"\tstrb r3, [r0]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804D232\n"
	"\tmovs r5, #0\n"
	"\tldr r3, _0804D2CC\n"
	"\tmovs r2, #0xCA\n"
	"\tlsls r2, r2, #3\n"
	"\tmovs r1, #0\n"
	"_0804D24A:\tldr r0, [r3]\n"
	"\tadds r0, r0, r2\n"
	"\tadds r0, r0, r5\n"
	"\tstrb r1, [r0]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804D24A\n"
	"\tmovs r5, #0\n"
	"\tldr r3, _0804D2CC\n"
	"\tldr r2, _0804D2D4\n"
	"\tmovs r1, #0\n"
	"_0804D260:\tldr r0, [r3]\n"
	"\tadds r0, r0, r2\n"
	"\tadds r0, r0, r5\n"
	"\tstrb r1, [r0]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804D260\n"
	"\tmovs r4, #0\n"
	"\tldr r1, _0804D2D8\n"
	"\tmov sl, r1\n"
	"\tasrs r0, r6, #0x10\n"
	"\tlsls r1, r0, #3\n"
	"\tsubs r1, r1, r0\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r6, r0, #2\n"
	"\tldr r2, _0804D2CC\n"
	"\tmov sb, r2\n"
	"\tmovs r3, #0xCF\n"
	"\tlsls r3, r3, #3\n"
	"\tmov r8, r3\n"
	"\tmovs r7, #0xC7\n"
	"\tlsls r7, r7, #3\n"
	"_0804D28E:\tmovs r5, #0\n"
	"\tlsls r0, r4, #2\n"
	"\tadds r1, r4, #1\n"
	"\tmov ip, r1\n"
	"\tadds r0, r0, r4\n"
	"\tlsls r4, r0, #2\n"
	"_0804D29A:\tmov r2, sb\n"
	"\tldr r0, [r2]\n"
	"\tadds r2, r5, r4\n"
	"\tmov r1, r8\n"
	"\tadds r3, r0, r1\n"
	"\tadds r3, r3, r2\n"
	"\tadds r0, r0, r7\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r2, r2, r0\n"
	"\tadds r2, r2, r6\n"
	"\tadd r2, sl\n"
	"\tldrb r0, [r2]\n"
	"\tstrb r0, [r3]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804D29A\n"
	"\tmov r4, ip\n"
	"\tcmp r4, #2\n"
	"\tble _0804D28E\n"
	"\tb _0804D362\n"
	"\tmovs r0, r0\n"
	"_0804D2CC:\t.4byte gCurrentPinballGame\n"
	"_0804D2D0:\t.4byte 0x63C\n"
	"_0804D2D4:\t.4byte 0x664\n"
	"_0804D2D8:\t.4byte gBonusSummaryTextTemplates\n"
	"_0804D2DC:\tldr r2, [sp, #0x24]\n"
	"\tasrs r0, r2, #0x10\n"
	"\tcmp r0, #0x58\n"
	"\tbgt _0804D362\n"
	"\tmovs r1, #0x18\n"
	"\tbl __divsi3\n"
	"\tlsls r0, r0, #0x10\n"
	"\tasrs r7, r0, #0x10\n"
	"\tcmp r7, #2\n"
	"\tble _0804D2F4\n"
	"\tmovs r7, #2\n"
	"_0804D2F4:\tmovs r4, #0\n"
	"\tcmp r4, r7\n"
	"\tbgt _0804D362\n"
	"\tmovs r6, #0\n"
	"\tmovs r3, #0\n"
	"_0804D2FE:\tldr r1, [sp, #0x24]\n"
	"\tasrs r0, r1, #0x10\n"
	"\tsubs r0, r0, r3\n"
	"\tmovs r1, #0x28\n"
	"\tstr r3, [sp, #0x2C]\n"
	"\tbl __modsi3\n"
	"\tlsrs r1, r0, #0x1F\n"
	"\tadds r0, r0, r1\n"
	"\tasrs r5, r0, #1\n"
	"\tldr r3, [sp, #0x2C]\n"
	"\tcmp r4, #0\n"
	"\tbeq _0804D348\n"
	"\tldr r2, _0804D3A4\n"
	"\tldr r1, [r2]\n"
	"\tadds r2, r5, r6\n"
	"\tldr r0, _0804D3A8\n"
	"\tadds r0, r0, r1\n"
	"\tmov r8, r0\n"
	"\tadd r8, r2\n"
	"\tmov r0, r8\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbne _0804D348\n"
	"\tmovs r0, #0xCF\n"
	"\tlsls r0, r0, #3\n"
	"\tadds r1, r1, r0\n"
	"\tadds r0, r1, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0x5F\n"
	"\tbeq _0804D348\n"
	"\tmovs r1, #1\n"
	"\tstr r1, [sp, #0x1C]\n"
	"_0804D348:\tldr r2, _0804D3A4\n"
	"\tldr r0, [r2]\n"
	"\tadds r1, r5, r6\n"
	"\tldr r2, _0804D3A8\n"
	"\tadds r0, r0, r2\n"
	"\tadds r0, r0, r1\n"
	"\tmovs r1, #1\n"
	"\tstrb r1, [r0]\n"
	"\tadds r6, #0x14\n"
	"\tadds r3, #0x18\n"
	"\tadds r4, #1\n"
	"\tcmp r4, r7\n"
	"\tble _0804D2FE\n"
	"_0804D362:\tldr r3, [sp, #0x1C]\n"
	"\tcmp r3, #0\n"
	"\tbeq _0804D36E\n"
	"\tmovs r0, #0xA1\n"
	"\tbl m4aSongNumStart\n"
	"_0804D36E:\tmovs r7, #0\n"
	"\tmovs r3, #0\n"
	"\tldr r0, _0804D3A4\n"
	"\tldr r5, [r0]\n"
	"\tldr r4, _0804D3AC\n"
	"\tadds r1, r5, r4\n"
	"\tldrh r1, [r1]\n"
	"\tcmp r1, #0xD4\n"
	"\tbeq _0804D38A\n"
	"\tldr r6, [sp, #0x18]\n"
	"\tcmp r6, #0\n"
	"\tbne _0804D38A\n"
	"\tbl 0x804DC3C\n"
	"_0804D38A:\tmovs r1, #0xC7\n"
	"\tlsls r1, r1, #3\n"
	"\tadds r0, r5, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #6\n"
	"\tbhi _0804D450\n"
	"\tlsls r0, r0, #2\n"
	"\tldr r1, _0804D3B0\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"_0804D3A4:\t.4byte gCurrentPinballGame\n"
	"_0804D3A8:\t.4byte 0x63C\n"
	"_0804D3AC:\t.4byte 0x63A\n"
	"_0804D3B0:\t.4byte _0804D3B4\n"
	"_0804D3B4:\t.4byte _0804D3D0 @ case 0\n"
	"\t.4byte _0804D3E4 @ case 1\n"
	"\t.4byte _0804D400 @ case 2\n"
	"\t.4byte _0804D41C @ case 3\n"
	"\t.4byte _0804D430 @ case 4\n"
	"\t.4byte _0804D44C @ case 5\n"
	"\t.4byte _0804D450 @ case 6\n"
	"_0804D3D0:\tldr r2, _0804D3DC\n"
	"\tldr r0, [r2]\n"
	"\tldr r3, _0804D3E0\n"
	"\tadds r0, r0, r3\n"
	"\tb _0804D408\n"
	"\tmovs r0, r0\n"
	"_0804D3DC:\t.4byte gCurrentPinballGame\n"
	"_0804D3E0:\t.4byte 0x62A\n"
	"_0804D3E4:\tldr r4, _0804D3F4\n"
	"\tldr r0, [r4]\n"
	"\tldr r6, _0804D3F8\n"
	"\tadds r0, r0, r6\n"
	"\tldrb r7, [r0]\n"
	"\tldr r3, _0804D3FC\n"
	"\tb _0804D450\n"
	"\tmovs r0, r0\n"
	"_0804D3F4:\t.4byte gCurrentPinballGame\n"
	"_0804D3F8:\t.4byte 0x62B\n"
	"_0804D3FC:\t.4byte 0xB71B0\n"
	"_0804D400:\tldr r7, _0804D410\n"
	"\tldr r0, [r7]\n"
	"\tldr r1, _0804D414\n"
	"\tadds r0, r0, r1\n"
	"_0804D408:\tldrb r7, [r0]\n"
	"\tldr r3, _0804D418\n"
	"\tb _0804D450\n"
	"\tmovs r0, r0\n"
	"_0804D410:\t.4byte gCurrentPinballGame\n"
	"_0804D414:\t.4byte 0x62C\n"
	"_0804D418:\t.4byte 0x7A120\n"
	"_0804D41C:\tldr r2, _0804D428\n"
	"\tldr r0, [r2]\n"
	"\tldr r3, _0804D42C\n"
	"\tadds r0, r0, r3\n"
	"\tb _0804D438\n"
	"\tmovs r0, r0\n"
	"_0804D428:\t.4byte gCurrentPinballGame\n"
	"_0804D42C:\t.4byte 0x62D\n"
	"_0804D430:\tldr r4, _0804D440\n"
	"\tldr r0, [r4]\n"
	"\tldr r6, _0804D444\n"
	"\tadds r0, r0, r6\n"
	"_0804D438:\tldrb r7, [r0]\n"
	"\tldr r3, _0804D448\n"
	"\tb _0804D450\n"
	"\tmovs r0, r0\n"
	"_0804D440:\t.4byte gCurrentPinballGame\n"
	"_0804D444:\t.4byte 0x62E\n"
	"_0804D448:\t.4byte 0x186A0\n"
	"_0804D44C:\tmovs r7, #0\n"
	"\tmovs r3, #0\n"
	"_0804D450:\tldr r1, _0804D4BC\n"
	"\tldr r0, [r1]\n"
	"\tmovs r2, #0xC7\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #4\n"
	"\tble _0804D466\n"
	"\tb _0804D734\n"
	"_0804D466:\tmov r5, sp\n"
	"\tadds r5, #2\n"
	"\tadds r4, r7, #0\n"
	"\tmuls r4, r3, r4\n"
	"\tmov r8, r4\n"
	"\tmovs r6, #7\n"
	"\tadd r6, sp\n"
	"\tmov sl, r6\n"
	"\tadd r0, sp, #8\n"
	"\tmov sb, r0\n"
	"\tmovs r1, #0\n"
	"\tmov r0, sp\n"
	"\tadds r0, #9\n"
	"_0804D480:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804D480\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #2\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r5, r0]\n"
	"\tb _0804D4D0\n"
	"\tmovs r0, r0\n"
	"_0804D4BC:\t.4byte gCurrentPinballGame\n"
	"_0804D4C0:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804D4D8\n"
	"\tmov r1, sp\n"
	"\tadds r0, r1, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804D4D0:\tcmp r0, #0\n"
	"\tble _0804D4C0\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804D4C0\n"
	"_0804D4D8:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tbgt _0804D4FC\n"
	"\tldr r6, _0804D5B4\n"
	"\tmovs r3, #0x13\n"
	"\tmovs r2, #0xCF\n"
	"\tlsls r2, r2, #3\n"
	"_0804D4E6:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804D4E6\n"
	"_0804D4FC:\tmovs r1, #0\n"
	"\tmov r0, sp\n"
	"\tadds r0, #9\n"
	"_0804D502:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804D502\n"
	"\tmov r7, r8\n"
	"\tldr r1, _0804D5B4\n"
	"\tldr r0, [r1]\n"
	"\tldr r2, _0804D5B8\n"
	"\tadds r0, r0, r2\n"
	"\tstr r7, [r0]\n"
	"\tmov r5, sp\n"
	"\tldr r4, _0804D5BC\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #7]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D5C0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #6]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D5C4\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D5C8\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r4, #0xFA\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #7\n"
	"\tmov r3, sl\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tb _0804D5DC\n"
	"_0804D5B4:\t.4byte gCurrentPinballGame\n"
	"_0804D5B8:\t.4byte 0x634\n"
	"_0804D5BC:\t.4byte 0x989680\n"
	"_0804D5C0:\t.4byte 0xF4240\n"
	"_0804D5C4:\t.4byte 0x186A0\n"
	"_0804D5C8:\t.4byte 0x2710\n"
	"_0804D5CC:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804D5E4\n"
	"\tmov r6, sp\n"
	"\tadds r0, r6, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804D5DC:\tcmp r0, #0\n"
	"\tble _0804D5CC\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804D5CC\n"
	"_0804D5E4:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tbgt _0804D606\n"
	"\tldr r6, _0804D6D4\n"
	"\tmovs r3, #0x13\n"
	"\tldr r2, _0804D6D8\n"
	"_0804D5F0:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804D5F0\n"
	"_0804D606:\tmovs r1, #0\n"
	"\tmov r0, sp\n"
	"\tadds r0, #9\n"
	"_0804D60C:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804D60C\n"
	"\tldr r1, _0804D6D4\n"
	"\tldr r0, [r1]\n"
	"\tmovs r2, #0xC6\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r0, r0, r2\n"
	"\tldr r7, [r0]\n"
	"\tmov r5, sp\n"
	"\tldr r4, _0804D6DC\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #8]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D6E0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #7]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D6E4\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #6]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D6E8\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D6EC\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r4, #0xFA\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #8\n"
	"\tmov r3, sb\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tb _0804D700\n"
	"\tmovs r0, r0\n"
	"_0804D6D4:\t.4byte gCurrentPinballGame\n"
	"_0804D6D8:\t.4byte 0x68C\n"
	"_0804D6DC:\t.4byte 0x5F5E100\n"
	"_0804D6E0:\t.4byte 0x989680\n"
	"_0804D6E4:\t.4byte 0xF4240\n"
	"_0804D6E8:\t.4byte 0x186A0\n"
	"_0804D6EC:\t.4byte 0x2710\n"
	"_0804D6F0:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804D708\n"
	"\tmov r6, sp\n"
	"\tadds r0, r6, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804D700:\tcmp r0, #0\n"
	"\tble _0804D6F0\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804D6F0\n"
	"_0804D708:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tble _0804D710\n"
	"\tb _0804DC3C\n"
	"_0804D710:\tldr r6, _0804D730\n"
	"\tmovs r3, #0x13\n"
	"\tmovs r2, #0xD4\n"
	"\tlsls r2, r2, #3\n"
	"_0804D718:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804D718\n"
	"\tb _0804DC3C\n"
	"_0804D730:\t.4byte gCurrentPinballGame\n"
	"_0804D734:\tcmp r0, #5\n"
	"\tbeq _0804D73A\n"
	"\tb _0804D868\n"
	"_0804D73A:\tadd r0, sp, #8\n"
	"\tmov sb, r0\n"
	"\tmovs r1, #0\n"
	"\tmov r0, sp\n"
	"\tadds r0, #9\n"
	"_0804D744:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804D744\n"
	"\tldr r1, _0804D80C\n"
	"\tldr r0, [r1]\n"
	"\tmovs r2, #0xC6\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r0, r0, r2\n"
	"\tldr r7, [r0]\n"
	"\tmov r5, sp\n"
	"\tldr r4, _0804D810\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #8]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D814\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #7]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D818\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #6]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D81C\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D820\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r4, #0xFA\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #8\n"
	"\tmov r3, sb\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tb _0804D834\n"
	"\tmovs r0, r0\n"
	"_0804D80C:\t.4byte gCurrentPinballGame\n"
	"_0804D810:\t.4byte 0x5F5E100\n"
	"_0804D814:\t.4byte 0x989680\n"
	"_0804D818:\t.4byte 0xF4240\n"
	"_0804D81C:\t.4byte 0x186A0\n"
	"_0804D820:\t.4byte 0x2710\n"
	"_0804D824:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804D83C\n"
	"\tmov r6, sp\n"
	"\tadds r0, r6, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804D834:\tcmp r0, #0\n"
	"\tble _0804D824\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804D824\n"
	"_0804D83C:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tble _0804D844\n"
	"\tb _0804DC3C\n"
	"_0804D844:\tldr r6, _0804D864\n"
	"\tmovs r3, #0x13\n"
	"\tmovs r2, #0xD4\n"
	"\tlsls r2, r2, #3\n"
	"_0804D84C:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804D84C\n"
	"\tb _0804DC3C\n"
	"_0804D864:\t.4byte gCurrentPinballGame\n"
	"_0804D868:\tadd r0, sp, #8\n"
	"\tmov sb, r0\n"
	"\tmovs r1, #5\n"
	"\tadd r1, sp\n"
	"\tmov r8, r1\n"
	"\tmovs r2, #0xA\n"
	"\tadd r2, sp\n"
	"\tmov sl, r2\n"
	"\tmovs r1, #0\n"
	"\tmov r0, sp\n"
	"\tadds r0, #9\n"
	"_0804D87E:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804D87E\n"
	"\tldr r3, _0804D944\n"
	"\tldr r0, [r3]\n"
	"\tmovs r4, #0xC6\n"
	"\tlsls r4, r4, #3\n"
	"\tadds r0, r0, r4\n"
	"\tldr r7, [r0]\n"
	"\tmov r5, sp\n"
	"\tldr r4, _0804D948\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #8]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D94C\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #7]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D950\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #6]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D954\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804D958\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r4, #0xFA\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #8\n"
	"\tmov r6, sb\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r6, r0]\n"
	"\tb _0804D96C\n"
	"_0804D944:\t.4byte gCurrentPinballGame\n"
	"_0804D948:\t.4byte 0x5F5E100\n"
	"_0804D94C:\t.4byte 0x989680\n"
	"_0804D950:\t.4byte 0xF4240\n"
	"_0804D954:\t.4byte 0x186A0\n"
	"_0804D958:\t.4byte 0x2710\n"
	"_0804D95C:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804D974\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804D96C:\tcmp r0, #0\n"
	"\tble _0804D95C\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804D95C\n"
	"_0804D974:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tbgt _0804D998\n"
	"\tldr r6, _0804DA2C\n"
	"\tmovs r3, #0x13\n"
	"\tmovs r2, #0xCF\n"
	"\tlsls r2, r2, #3\n"
	"_0804D982:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804D982\n"
	"_0804D998:\tmovs r1, #0\n"
	"\tmov r0, sp\n"
	"\tadds r0, #9\n"
	"_0804D99E:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804D99E\n"
	"\tldr r1, _0804DA2C\n"
	"\tldr r0, [r1]\n"
	"\tldr r2, _0804DA30\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r7, [r0]\n"
	"\tmov r5, sp\n"
	"\tldr r1, _0804DA34\n"
	"\tadds r0, r7, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DA38\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DA3C\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r4, #0xFA\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #5\n"
	"\tmov r3, r8\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tb _0804DA50\n"
	"\tmovs r0, r0\n"
	"_0804DA2C:\t.4byte gCurrentPinballGame\n"
	"_0804DA30:\t.4byte 0x62F\n"
	"_0804DA34:\t.4byte 0xF4240\n"
	"_0804DA38:\t.4byte 0x186A0\n"
	"_0804DA3C:\t.4byte 0x2710\n"
	"_0804DA40:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804DA58\n"
	"\tmov r6, sp\n"
	"\tadds r0, r6, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804DA50:\tcmp r0, #0\n"
	"\tble _0804DA40\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804DA40\n"
	"_0804DA58:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tbgt _0804DA7A\n"
	"\tldr r6, _0804DBD0\n"
	"\tmovs r3, #0x13\n"
	"\tldr r2, _0804DBD4\n"
	"_0804DA64:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804DA64\n"
	"_0804DA7A:\tmovs r1, #0\n"
	"\tmov r0, sp\n"
	"\tadds r0, #0xA\n"
	"_0804DA80:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804DA80\n"
	"\tmovs r7, #0\n"
	"\tmovs r5, #0\n"
	"\tldr r1, _0804DBD0\n"
	"\tldr r0, [r1]\n"
	"\tldr r1, _0804DBD8\n"
	"\tadds r0, r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804DAD2\n"
	"\tldr r2, _0804DBD0\n"
	"\tadds r6, r1, #0\n"
	"_0804DA9E:\tldr r4, [r2]\n"
	"\tmovs r3, #0xC6\n"
	"\tlsls r3, r3, #3\n"
	"\tadds r0, r4, r3\n"
	"\tldr r0, [r0]\n"
	"\tadds r7, r7, r0\n"
	"\tadds r0, r7, #0\n"
	"\tldr r1, _0804DBDC\n"
	"\tstr r2, [sp, #0x28]\n"
	"\tbl __divsi3\n"
	"\tldr r2, [sp, #0x28]\n"
	"\tcmp r0, #0\n"
	"\tble _0804DAC0\n"
	"\tldr r0, _0804DBE0\n"
	"\tadds r7, r7, r0\n"
	"\tadds r5, #2\n"
	"_0804DAC0:\tadds r1, r4, r6\n"
	"\tldrb r0, [r1]\n"
	"\tsubs r0, #1\n"
	"\tstrb r0, [r1]\n"
	"\tldr r0, [r2]\n"
	"\tadds r0, r0, r6\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbne _0804DA9E\n"
	"_0804DAD2:\tldr r1, _0804DBE4\n"
	"\tmov r8, r1\n"
	"\tadds r0, r7, #0\n"
	"\tbl __divsi3\n"
	"\tcmp r0, #0\n"
	"\tble _0804DAE6\n"
	"\tldr r2, _0804DBE8\n"
	"\tadds r7, r7, r2\n"
	"\tadds r5, #1\n"
	"_0804DAE6:\tldr r3, _0804DBD0\n"
	"\tldr r0, [r3]\n"
	"\tmovs r4, #0xD7\n"
	"\tlsls r4, r4, #3\n"
	"\tadds r1, r0, r4\n"
	"\tstr r5, [r1]\n"
	"\tldr r6, _0804DBEC\n"
	"\tadds r0, r0, r6\n"
	"\tstr r7, [r0]\n"
	"\tmov r4, sp\n"
	"\tmovs r6, #0xFA\n"
	"\tlsls r6, r6, #2\n"
	"\tadds r0, r5, #0\n"
	"\tadds r1, r6, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #0xA]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r4, #9]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4, #8]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmov r1, r8\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DBF0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #7]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DBF4\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #6]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DBF8\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DBFC\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tadds r1, r6, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r6, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #0xA\n"
	"\tmov r7, sl\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r7, r0]\n"
	"\tb _0804DC10\n"
	"\tmovs r0, r0\n"
	"_0804DBD0:\t.4byte gCurrentPinballGame\n"
	"_0804DBD4:\t.4byte 0x68C\n"
	"_0804DBD8:\t.4byte 0x62F\n"
	"_0804DBDC:\t.4byte 0xBEBC200\n"
	"_0804DBE0:\t.4byte 0xF4143E00\n"
	"_0804DBE4:\t.4byte 0x5F5E100\n"
	"_0804DBE8:\t.4byte 0xFA0A1F00\n"
	"_0804DBEC:\t.4byte 0x6B4\n"
	"_0804DBF0:\t.4byte 0x989680\n"
	"_0804DBF4:\t.4byte 0xF4240\n"
	"_0804DBF8:\t.4byte 0x186A0\n"
	"_0804DBFC:\t.4byte 0x2710\n"
	"_0804DC00:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804DC18\n"
	"\tmov r1, sp\n"
	"\tadds r0, r1, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804DC10:\tcmp r0, #0\n"
	"\tble _0804DC00\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804DC00\n"
	"_0804DC18:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tbgt _0804DC3C\n"
	"\tldr r6, _0804DCA8\n"
	"\tmovs r3, #0x13\n"
	"\tmovs r2, #0xD4\n"
	"\tlsls r2, r2, #3\n"
	"_0804DC26:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804DC26\n"
	"_0804DC3C:\tldr r1, [sp, #0x24]\n"
	"\tldr r2, _0804DCAC\n"
	"\tadds r0, r1, r2\n"
	"\tlsrs r0, r0, #0x10\n"
	"\tcmp r0, #0x32\n"
	"\tbls _0804DC4A\n"
	"\tb _0804E050\n"
	"_0804DC4A:\tldr r3, _0804DCA8\n"
	"\tldr r1, [r3]\n"
	"\tmovs r4, #0xC7\n"
	"\tlsls r4, r4, #3\n"
	"\tadds r0, r1, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #4\n"
	"\tble _0804DC60\n"
	"\tb _0804DDF8\n"
	"_0804DC60:\tldr r3, _0804DCB0\n"
	"\tadds r0, r1, r3\n"
	"\tldr r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804DC72\n"
	"\tldr r6, _0804DCB4\n"
	"\tadds r1, r1, r6\n"
	"\tmovs r0, #0x64\n"
	"\tstrh r0, [r1]\n"
	"_0804DC72:\tldr r0, _0804DCB8\n"
	"\tldr r2, [r0, #0x4C]\n"
	"\tmovs r0, #1\n"
	"\tands r2, r0\n"
	"\tcmp r2, #0\n"
	"\tbne _0804DCE0\n"
	"\tldr r7, _0804DCA8\n"
	"\tldr r1, [r7]\n"
	"\tadds r4, r1, r3\n"
	"\tldr r3, [r4]\n"
	"\tldr r0, _0804DCBC\n"
	"\tcmp r3, r0\n"
	"\tbls _0804DCC8\n"
	"\tldr r2, _0804DCC0\n"
	"\tadds r0, r3, r2\n"
	"\tstr r0, [r4]\n"
	"\tmovs r3, #0xC6\n"
	"\tlsls r3, r3, #3\n"
	"\tadds r1, r1, r3\n"
	"\tldr r0, [r1]\n"
	"\tldr r4, _0804DCC4\n"
	"\tadds r0, r0, r4\n"
	"\tstr r0, [r1]\n"
	"\tmovs r0, #0x91\n"
	"\tbl m4aSongNumStart\n"
	"\tb _0804DCE0\n"
	"_0804DCA8:\t.4byte gCurrentPinballGame\n"
	"_0804DCAC:\t.4byte 0xFFA60000\n"
	"_0804DCB0:\t.4byte 0x634\n"
	"_0804DCB4:\t.4byte 0x63A\n"
	"_0804DCB8:\t.4byte gMain\n"
	"_0804DCBC:\t.4byte 0x30D3F\n"
	"_0804DCC0:\t.4byte 0xFFFCF2C0\n"
	"_0804DCC4:\t.4byte 0x30D40\n"
	"_0804DCC8:\tcmp r3, #0\n"
	"\tbeq _0804DCE0\n"
	"\tmovs r6, #0xC6\n"
	"\tlsls r6, r6, #3\n"
	"\tadds r1, r1, r6\n"
	"\tldr r0, [r1]\n"
	"\tadds r0, r0, r3\n"
	"\tstr r0, [r1]\n"
	"\tstr r2, [r4]\n"
	"\tmovs r0, #0x91\n"
	"\tbl m4aSongNumStart\n"
	"_0804DCE0:\tldr r6, _0804DD9C\n"
	"\tldr r0, [r6]\n"
	"\tmovs r7, #0xC6\n"
	"\tlsls r7, r7, #3\n"
	"\tadds r0, r0, r7\n"
	"\tldr r7, [r0]\n"
	"\tmov r5, sp\n"
	"\tldr r4, _0804DDA0\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #8]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DDA4\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #7]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DDA8\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #6]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DDAC\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804DDB0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r4, #0xFA\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #8\n"
	"\tadd r0, sp, #8\n"
	"\tb _0804DDBE\n"
	"\tmovs r0, r0\n"
	"_0804DD9C:\t.4byte gCurrentPinballGame\n"
	"_0804DDA0:\t.4byte 0x5F5E100\n"
	"_0804DDA4:\t.4byte 0x989680\n"
	"_0804DDA8:\t.4byte 0xF4240\n"
	"_0804DDAC:\t.4byte 0x186A0\n"
	"_0804DDB0:\t.4byte 0x2710\n"
	"_0804DDB4:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804DDCC\n"
	"\tmov r1, sp\n"
	"\tadds r0, r1, r4\n"
	"_0804DDBE:\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tble _0804DDB4\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804DDB4\n"
	"_0804DDCC:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tble _0804DDD4\n"
	"\tb _0804E050\n"
	"_0804DDD4:\tldr r6, _0804DDF4\n"
	"\tmovs r3, #0x13\n"
	"\tmovs r2, #0xD4\n"
	"\tlsls r2, r2, #3\n"
	"_0804DDDC:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804DDDC\n"
	"\tb _0804E050\n"
	"_0804DDF4:\t.4byte gCurrentPinballGame\n"
	"_0804DDF8:\tcmp r0, #6\n"
	"\tbeq _0804DDFE\n"
	"\tb _0804E050\n"
	"_0804DDFE:\tldr r0, _0804DE54\n"
	"\tadds r1, r1, r0\n"
	"\tmovs r0, #1\n"
	"\tstrb r0, [r1]\n"
	"\tldr r2, _0804DE58\n"
	"\tldr r1, [r2]\n"
	"\tldr r3, _0804DE5C\n"
	"\tadds r0, r1, r3\n"
	"\tldr r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbne _0804DE20\n"
	"\tmovs r4, #0xD7\n"
	"\tlsls r4, r4, #3\n"
	"\tadds r0, r1, r4\n"
	"\tldr r0, [r0]\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804DE28\n"
	"_0804DE20:\tldr r6, _0804DE60\n"
	"\tadds r1, r1, r6\n"
	"\tmovs r0, #0x64\n"
	"\tstrh r0, [r1]\n"
	"_0804DE28:\tldr r0, _0804DE64\n"
	"\tldr r0, [r0, #0x4C]\n"
	"\tmovs r1, #1\n"
	"\tands r0, r1\n"
	"\tcmp r0, #0\n"
	"\tbne _0804DEB6\n"
	"\tldr r0, _0804DE58\n"
	"\tldr r2, [r0]\n"
	"\tldr r7, _0804DE5C\n"
	"\tadds r5, r2, r7\n"
	"\tldr r3, [r5]\n"
	"\tldr r0, _0804DE68\n"
	"\tcmp r3, r0\n"
	"\tbls _0804DE74\n"
	"\tldr r1, _0804DE6C\n"
	"\tadds r0, r3, r1\n"
	"\tstr r0, [r5]\n"
	"\tldr r0, [r2, #0x44]\n"
	"\tldr r3, _0804DE70\n"
	"\tadds r0, r0, r3\n"
	"\tb _0804DE92\n"
	"\tmovs r0, r0\n"
	"_0804DE54:\t.4byte 0x639\n"
	"_0804DE58:\t.4byte gCurrentPinballGame\n"
	"_0804DE5C:\t.4byte 0x6B4\n"
	"_0804DE60:\t.4byte 0x63A\n"
	"_0804DE64:\t.4byte gMain\n"
	"_0804DE68:\t.4byte 0x30D3F\n"
	"_0804DE6C:\t.4byte 0xFFFCF2C0\n"
	"_0804DE70:\t.4byte 0x30D40\n"
	"_0804DE74:\tmovs r6, #0xD7\n"
	"\tlsls r6, r6, #3\n"
	"\tadds r4, r2, r6\n"
	"\tldr r1, [r4]\n"
	"\tcmp r1, #0\n"
	"\tbeq _0804DEA4\n"
	"\tsubs r0, r1, #1\n"
	"\tstr r0, [r4]\n"
	"\tldr r0, [r5]\n"
	"\tldr r7, _0804DE9C\n"
	"\tadds r0, r0, r7\n"
	"\tstr r0, [r5]\n"
	"\tldr r0, [r2, #0x44]\n"
	"\tldr r1, _0804DEA0\n"
	"\tadds r0, r0, r1\n"
	"_0804DE92:\tstr r0, [r2, #0x44]\n"
	"\tmovs r0, #0x91\n"
	"\tbl m4aSongNumStart\n"
	"\tb _0804DEB6\n"
	"_0804DE9C:\t.4byte 0x5F2D3C0\n"
	"_0804DEA0:\t.4byte 0x30D40\n"
	"_0804DEA4:\tcmp r3, #0\n"
	"\tbeq _0804DEB6\n"
	"\tldr r0, [r2, #0x44]\n"
	"\tadds r0, r0, r3\n"
	"\tstr r0, [r2, #0x44]\n"
	"\tstr r1, [r5]\n"
	"\tmovs r0, #0x91\n"
	"\tbl m4aSongNumStart\n"
	"_0804DEB6:\tldr r2, [sp, #0x20]\n"
	"\tlsls r6, r2, #0x10\n"
	"\tmovs r3, #0xA\n"
	"\tadd r3, sp\n"
	"\tmov sl, r3\n"
	"\tmovs r1, #0\n"
	"\tmov r0, sl\n"
	"_0804DEC4:\tstrb r1, [r0]\n"
	"\tsubs r0, #1\n"
	"\tcmp r0, sp\n"
	"\tbge _0804DEC4\n"
	"\tmovs r5, #0\n"
	"\tasrs r0, r6, #0x10\n"
	"\tlsls r1, r0, #3\n"
	"\tsubs r1, r1, r0\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r3, r0, #2\n"
	"\tldr r4, _0804DFF4\n"
	"\tmov r8, r4\n"
	"\tldr r7, _0804DFF8\n"
	"\tmovs r6, #0xD4\n"
	"\tlsls r6, r6, #3\n"
	"\tmovs r4, #0xC7\n"
	"\tlsls r4, r4, #3\n"
	"_0804DEE8:\tldr r0, [r7]\n"
	"\tadds r2, r0, r6\n"
	"\tadds r2, r2, r5\n"
	"\tadds r0, r0, r4\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #4\n"
	"\tsubs r0, r0, r1\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r0, r5, r0\n"
	"\tadds r0, r0, r3\n"
	"\tadd r0, r8\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r2]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, #0x13\n"
	"\tble _0804DEE8\n"
	"\tldr r6, _0804DFF8\n"
	"\tldr r0, [r6]\n"
	"\tmovs r7, #0xD7\n"
	"\tlsls r7, r7, #3\n"
	"\tadds r1, r0, r7\n"
	"\tldr r5, [r1]\n"
	"\tldr r1, _0804DFFC\n"
	"\tadds r0, r0, r1\n"
	"\tldr r7, [r0]\n"
	"\tmov r4, sp\n"
	"\tmovs r6, #0xFA\n"
	"\tlsls r6, r6, #2\n"
	"\tadds r0, r5, #0\n"
	"\tadds r1, r6, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #0xA]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r4, #9]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r5, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4, #8]\n"
	"\tmov r5, sp\n"
	"\tldr r1, _0804E000\n"
	"\tadds r0, r7, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804E004\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #7]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804E008\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #6]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804E00C\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #5]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tldr r4, _0804E010\n"
	"\tadds r1, r4, #0\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r5, #4]\n"
	"\tmov r5, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r4, #0\n"
	"\tbl __modsi3\n"
	"\tadds r1, r6, #0\n"
	"\tbl __divsi3\n"
	"\tadds r0, #0xA\n"
	"\tstrb r0, [r5, #3]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tadds r1, r6, #0\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0x64\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #2]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0x64\n"
	"\tbl __modsi3\n"
	"\tmovs r1, #0xA\n"
	"\tbl __divsi3\n"
	"\tstrb r0, [r4, #1]\n"
	"\tmov r4, sp\n"
	"\tadds r0, r7, #0\n"
	"\tmovs r1, #0xA\n"
	"\tbl __modsi3\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r4, #0xA\n"
	"\tmov r2, sl\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r2, r0]\n"
	"\tb _0804E024\n"
	"\tmovs r0, r0\n"
	"_0804DFF4:\t.4byte gBonusSummaryTextTemplates + 0x28\n"
	"_0804DFF8:\t.4byte gCurrentPinballGame\n"
	"_0804DFFC:\t.4byte 0x6B4\n"
	"_0804E000:\t.4byte 0x5F5E100\n"
	"_0804E004:\t.4byte 0x989680\n"
	"_0804E008:\t.4byte 0xF4240\n"
	"_0804E00C:\t.4byte 0x186A0\n"
	"_0804E010:\t.4byte 0x2710\n"
	"_0804E014:\tsubs r4, #1\n"
	"\tcmp r4, #0\n"
	"\tble _0804E02C\n"
	"\tmov r3, sp\n"
	"\tadds r0, r3, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"_0804E024:\tcmp r0, #0\n"
	"\tble _0804E014\n"
	"\tcmp r0, #0xA\n"
	"\tbeq _0804E014\n"
	"_0804E02C:\tmovs r5, #0\n"
	"\tcmp r5, r4\n"
	"\tbgt _0804E050\n"
	"\tldr r6, _0804E148\n"
	"\tmovs r3, #0x13\n"
	"\tmovs r2, #0xD4\n"
	"\tlsls r2, r2, #3\n"
	"_0804E03A:\tldr r1, [r6]\n"
	"\tsubs r0, r3, r5\n"
	"\tadds r1, r1, r2\n"
	"\tadds r1, r1, r0\n"
	"\tmov r7, sp\n"
	"\tadds r0, r7, r5\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r1]\n"
	"\tadds r5, #1\n"
	"\tcmp r5, r4\n"
	"\tble _0804E03A\n"
	"_0804E050:\tldr r1, _0804E148\n"
	"\tldr r0, [r1]\n"
	"\tldr r2, _0804E14C\n"
	"\tadds r1, r0, r2\n"
	"\tldrh r0, [r1]\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804E062\n"
	"\tsubs r0, #1\n"
	"\tstrh r0, [r1]\n"
	"_0804E062:\tldr r6, _0804E150\n"
	"\tldrh r0, [r6]\n"
	"\tcmp r0, #0\n"
	"\tbeq _0804E138\n"
	"\tmovs r0, #0x78\n"
	"\tstrh r0, [r6, #2]\n"
	"\tldr r3, _0804E148\n"
	"\tldr r0, [r3]\n"
	"\tadds r0, #0xFC\n"
	"\tldrh r0, [r0]\n"
	"\tadds r0, #0x26\n"
	"\tstrh r0, [r6, #4]\n"
	"\tldr r4, [sp, #0x14]\n"
	"\tlsls r4, r4, #0x10\n"
	"\tmov r8, r4\n"
	"\tldr r7, _0804E154\n"
	"\tldr r0, _0804E158\n"
	"\tmov sl, r0\n"
	"\tadds r4, r6, #0\n"
	"\tadds r4, #8\n"
	"\tldr r1, _0804E15C\n"
	"\tmov sb, r1\n"
	"\tmovs r5, #0xD\n"
	"_0804E090:\tldrh r3, [r4]\n"
	"\tlsls r3, r3, #3\n"
	"\tadds r3, r3, r7\n"
	"\tmovs r2, #2\n"
	"\tldrsh r1, [r4, r2]\n"
	"\tmovs r2, #2\n"
	"\tldrsh r0, [r6, r2]\n"
	"\tadds r1, r1, r0\n"
	"\tmov r0, sb\n"
	"\tands r1, r0\n"
	"\tldrh r2, [r3, #2]\n"
	"\tmov r0, sl\n"
	"\tands r0, r2\n"
	"\torrs r0, r1\n"
	"\tstrh r0, [r3, #2]\n"
	"\tldrh r1, [r4]\n"
	"\tlsls r1, r1, #3\n"
	"\tadds r1, r1, r7\n"
	"\tldrb r0, [r6, #4]\n"
	"\tldrb r2, [r4, #4]\n"
	"\tadds r0, r0, r2\n"
	"\tstrb r0, [r1]\n"
	"\tadds r4, #8\n"
	"\tsubs r5, #1\n"
	"\tcmp r5, #0\n"
	"\tbge _0804E090\n"
	"\tmovs r4, #0\n"
	"\tmov r3, r8\n"
	"\tasrs r3, r3, #0x10\n"
	"\tmov sl, r3\n"
	"\tldr r7, _0804E154\n"
	"\tldr r6, _0804E158\n"
	"\tmov sb, r6\n"
	"\tldr r0, _0804E15C\n"
	"\tmov r8, r0\n"
	"_0804E0D6:\tmovs r0, #0xB8\n"
	"\tmuls r0, r4, r0\n"
	"\tldr r1, _0804E160\n"
	"\tadds r6, r0, r1\n"
	"\tmovs r0, #0x68\n"
	"\tstrh r0, [r6, #2]\n"
	"\tlsls r1, r4, #4\n"
	"\tldr r2, _0804E148\n"
	"\tldr r0, [r2]\n"
	"\tadds r0, #0xFC\n"
	"\tldrh r0, [r0]\n"
	"\tadds r0, #0x40\n"
	"\tadds r1, r1, r0\n"
	"\tadd r1, sl\n"
	"\tstrh r1, [r6, #4]\n"
	"\tadds r4, #1\n"
	"\tmov ip, r4\n"
	"\tadds r4, r6, #0\n"
	"\tadds r4, #8\n"
	"\tmovs r5, #4\n"
	"_0804E0FE:\tldrh r2, [r4]\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r2, r2, r7\n"
	"\tmovs r3, #2\n"
	"\tldrsh r1, [r4, r3]\n"
	"\tmovs r3, #2\n"
	"\tldrsh r0, [r6, r3]\n"
	"\tadds r1, r1, r0\n"
	"\tmov r0, r8\n"
	"\tands r1, r0\n"
	"\tldrh r3, [r2, #2]\n"
	"\tmov r0, sb\n"
	"\tands r0, r3\n"
	"\torrs r0, r1\n"
	"\tstrh r0, [r2, #2]\n"
	"\tldrh r1, [r4]\n"
	"\tlsls r1, r1, #3\n"
	"\tadds r1, r1, r7\n"
	"\tldrb r0, [r6, #4]\n"
	"\tldrb r2, [r4, #4]\n"
	"\tadds r0, r0, r2\n"
	"\tstrb r0, [r1]\n"
	"\tadds r4, #8\n"
	"\tsubs r5, #1\n"
	"\tcmp r5, #0\n"
	"\tbge _0804E0FE\n"
	"\tmov r4, ip\n"
	"\tcmp r4, #2\n"
	"\tble _0804E0D6\n"
	"_0804E138:\tadd sp, #0x30\n"
	"\tpop {r3, r4, r5}\n"
	"\tmov r8, r3\n"
	"\tmov sb, r4\n"
	"\tmov sl, r5\n"
	"\tpop {r4, r5, r6, r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"_0804E148:\t.4byte gCurrentPinballGame\n"
	"_0804E14C:\t.4byte 0x63A\n"
	"_0804E150:\t.4byte gMain_spriteGroups_9\n"
	"_0804E154:\t.4byte gOamBuffer\n"
	"_0804E158:\t.4byte 0xFFFFFE00\n"
	"_0804E15C:\t.4byte 0x1FF\n"
	"_0804E160:\t.4byte gMain_spriteGroups_6\n"
    );
}
#else
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

    for (i = 0; i < EOB_SUMMARY_LINES; i++)
    {
        for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
        {
            s16 charix;
            s16 var1 = gCurrentPinballGame->bonusTextContent[i][j];
            if (var1 == 95)
                var1 = 48;
            else if (var1 == 94)
                var1 = 47;
            else if (var1 > 46)
                var1 -= 65;

            if (gCurrentPinballGame->bonusTextRevealMask[i][j])
            {
                DmaCopy16(3, gEobBonusSummaryCharTiles[var1], OBJ_VRAM_ADDR_END_OF_BALL_BONUS_SUMMARY_TEXT(i,j), SIZE_OF_VRAM_END_OF_BALL_BONUS_SUMMARY_TEXT_CHAR_TILES);
            }
            else
            {
                DmaCopy16(3, gEobBonusSummaryCharTiles[48], OBJ_VRAM_ADDR_END_OF_BALL_BONUS_SUMMARY_TEXT(i,j), SIZE_OF_VRAM_END_OF_BALL_BONUS_SUMMARY_TEXT_CHAR_TILES);
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
                gCurrentPinballGame->bonusSummaryPhase = EOB_BONUS_PHASE_ADD_TO_SCORE;
                gCurrentPinballGame->bonusSubtotal =
                    gCurrentPinballGame->bonusCatchCount * SCORE_BONUS_PER_CATCH +
                    gCurrentPinballGame->bonusMonEvoCount * SCORE_BONUS_PER_EVO +
                    gCurrentPinballGame->travelModeCompletionCount * SCORE_BONUS_PER_TRAVEL +
                    gCurrentPinballGame->slotsPlayedCount * SCORE_BONUS_PER_SLOTS_PLAYED +
                    gCurrentPinballGame->bonusPikaSaverCount * SCORE_BONUS_PER_PIKA_SAVER;

                gCurrentPinballGame->bonusCategoryScore = 0;
                gMain.animationTimer = 150;

                for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                    gCurrentPinballGame->bonusTextRevealMask[0][j] = TRUE;
                for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                    gCurrentPinballGame->bonusTextRevealMask[1][j] = TRUE;
                for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                    gCurrentPinballGame->bonusTextRevealMask[2][j] = TRUE;

                for (i = 0; i < EOB_SUMMARY_LINES; i++)
                    for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
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
        gCurrentPinballGame->bonusSummaryPhase = EOB_BONUS_PHASE_MONS_CAUGHT;
        gCurrentPinballGame->bonusSubtotal = 0;
        gCurrentPinballGame->bonusCategoryScore = 0;
        for (i = 0; i < EOB_SUMMARY_LINES; i++)
            for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];
    }

    if (gCurrentPinballGame->bonusSummaryTimer != 0)
    {
        if (gMain.animationTimer < 150)
            gMain.animationTimer++;

        if (gCurrentPinballGame->bonusSummaryPhase < EOB_BONUS_PHASE_SUBTOTAL_SLIDES_UP)
        {
            if (textRevealTimer < 89)
            {
                lineRevealSegment = textRevealTimer / 24;
                if (lineRevealSegment > 2)
                    lineRevealSegment = 2;

                for (i = 0; i <= lineRevealSegment; i++)
                {
                    j = ((textRevealTimer - i * 24) % 40) / 2;
                    if (gCurrentPinballGame->bonusSummaryPhase == EOB_BONUS_PHASE_MONS_CAUGHT || i != 2)
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
                for (i = 0; i < EOB_SUMMARY_LINES; i++)
                    for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                        gCurrentPinballGame->bonusTextContent[i][j] = gBonusSummaryTextTemplates[gCurrentPinballGame->bonusSummaryPhase][i][j];
            }
        }
        else if (gCurrentPinballGame->bonusSummaryPhase == EOB_BONUS_PHASE_SUBTOTAL_SLIDES_UP)
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
                for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                    gCurrentPinballGame->bonusTextRevealMask[0][j] = TRUE;
                for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                    gCurrentPinballGame->bonusTextRevealMask[1][j] = FALSE;
                for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
                    gCurrentPinballGame->bonusTextRevealMask[2][j] = FALSE;

                for (i = 0; i < EOB_SUMMARY_LINES; i++)
                    for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
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
        case EOB_BONUS_PHASE_MONS_CAUGHT:
            value = gCurrentPinballGame->bonusCatchCount;
            multiplier = SCORE_BONUS_PER_CATCH;
            break;
        case EOB_BONUS_PHASE_MONS_EVOLVED:
            value = gCurrentPinballGame->bonusMonEvoCount;
            multiplier = SCORE_BONUS_PER_EVO;
            break;
        case EOB_BONUS_PHASE_TRAVELED_AREAS:
            value = gCurrentPinballGame->travelModeCompletionCount;
            multiplier = SCORE_BONUS_PER_TRAVEL;
            break;
        case EOB_BONUS_PHASE_SLOTS_PLAYED:
            value = gCurrentPinballGame->slotsPlayedCount;
            multiplier = SCORE_BONUS_PER_SLOTS_PLAYED;
            break;
        case EOB_BONUS_PHASE_PIKA_SAVER:
            value = gCurrentPinballGame->bonusPikaSaverCount;
            multiplier = SCORE_BONUS_PER_PIKA_SAVER;
            break;
        case EOB_BONUS_PHASE_SUBTOTAL_SLIDES_UP:
            value = 0;
            multiplier = 0;
            break;
        case EOB_BONUS_PHASE_ADD_TO_SCORE:
            break;
        }

        if (gCurrentPinballGame->bonusSummaryPhase < EOB_BONUS_PHASE_SUBTOTAL_SLIDES_UP)
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
        else if (gCurrentPinballGame->bonusSummaryPhase == EOB_BONUS_PHASE_SUBTOTAL_SLIDES_UP)
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
            value = gCurrentPinballGame->endOfBallBonusMultiplier;
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
            while (gCurrentPinballGame->endOfBallBonusMultiplier != 0)
            {
                // Note: tallied in a loop, rather than a base multiplication to prevent integer overflow.
                value += gCurrentPinballGame->bonusSubtotal;
                if (value / (2 * SCORE_HI_STEP) > 0)
                {
                    value -= (2 * SCORE_HI_STEP);
                    scoreHi += 2;
                }
                gCurrentPinballGame->endOfBallBonusMultiplier--;
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
        if (gCurrentPinballGame->bonusSummaryPhase < EOB_BONUS_PHASE_SUBTOTAL_SLIDES_UP)
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
        else if (gCurrentPinballGame->bonusSummaryPhase == EOB_BONUS_PHASE_ADD_TO_SCORE)
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
            for (j = 0; j < EOB_SUMMARY_CHARS_PER_LINE; j++)
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
                gCurrentPinballGame->bonusTextContent[2][(EOB_SUMMARY_CHARS_PER_LINE -1) - j] = scoreDigit[j] + DIGIT_TILE_BASE_IX;
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
#endif
