#include "global.h"
#include "agb_sram.h"
#include "m4a.h"
#include "titlescreen.h"
#include "main.h"
#include "constants/bg_music.h"

static void TitleScreen_CheckDeleteKeyComboPressed(void);
static void CheckEReaderAccessCombo(void);
static void RenderTitlePressStartSprites(void);

// If the user doesn't press any buttons at the title screen,
// it will transition to a demo gameplay experience.
#define NUM_IDLE_FRAMES 1800

#define RESTART_GAME_BUTTONS (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)

enum
{
    SUBSTATE_LOAD_GRAPHICS,
    SUBSTATE_WAIT_FOR_START_BUTTON,
    SUBSTATE_2,
    SUBSTATE_3,
    SUBSTATE_MENU_INPUT_NO_SAVED_GAME,
    SUBSTATE_MENU_INPUT_SAVED_GAME,
    SUBSTATE_ANIM_CLOSE_MENU,
    SUBSTATE_7,
    SUBSTATE_8,
    SUBSTATE_DELETE_SAVE_GAME_CONFIRMATION,
    SUBSTATE_EXEC_MENU_SELECTION,
    SUBSTATE_11,
};

void ClearHighScoreNameEntry(void)
{
    int i;

    for (i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
        gHighScoreNameEntry[i] = 0;
}

void TitlescreenMain(void)
{
    gTitlescreenStateFuncs[gMain.subState]();
}

void LoadTitlescreenGraphics(void)
{
    int autoDisplayMenu;

    ResetDisplayState();
    REG_DISPCNT = DISPCNT_OBJ_ON| DISPCNT_FORCED_BLANK;
    REG_BG1CNT = BGCNT_256COLOR | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gTitlescreenBg_Gfx, (void *)BG_CHAR_ADDR(1), 0xA000);
    DmaCopy16(3, gTitlescreenBg_Pals, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gTitlescreenBgTilemap, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);

    SaveFile_ReadSavedGamePresent();
    if (gMain.hasSavedGame == TRUE)
    {
        DmaCopy16(3, gTitlescreenSprites_Pals, (void *)OBJ_PLTT, 0xA0);
        DmaCopy16(3, gTitlescreenSpritesSavedGame_Gfx, (void *)BG_CHAR_ADDR(4), 0x7000);
        DmaCopy16(3, gGBAButtonIcons_Pals, (void *)(OBJ_PLTT + 0xA0), 0x40);
        DmaCopy16(3, gOptionsSprites_Gfx, (void *)OBJ_VRAM0 + 0x7000, 0x400);
    }
    else
    {
        DmaCopy16(3, gTitlescreenSprites_Pals, (void *)OBJ_PLTT, 0xA0);
        DmaCopy16(3, gTitlescreenSpritesNoSavedGame_Gfx, (void *)BG_CHAR_ADDR(4), 0x7000);
        DmaCopy16(3, gGBAButtonIcons_Pals, (void *)(OBJ_PLTT + 0xA0), 0x40);
        DmaCopy16(3, gOptionsSprites_Gfx, (void *)OBJ_VRAM0 + 0x7000, 0x400);
    }

    InitTitlescreenStates();

    autoDisplayMenu = gAutoDisplayTitlescreenMenu;
    if (autoDisplayMenu == TRUE)
    {
        gTitleReturnedFromMenu = FALSE;
        gTitlescreen.pressStartAndFlippersVisible = FALSE;
        gTitlescreen.menuVisible = autoDisplayMenu;
        gMain.subState = SUBSTATE_3;
        EnableVBlankInterrupts();
        FadeInFromWhite(NULL);
    }
    else
    {
        gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        EnableVBlankInterrupts();
        FadeInFromWhite(RenderTitlePressStartSprites);
    }

    m4aSongNumStart(MUS_TITLE);
}

void InitTitlescreenStates(void)
{
    int i;

    gTitlescreen.animTimer = 0;
    gTitlescreen.animPhase = 0;
    gTitlescreen.menuAction = 0;
    gTitlescreen.pressStartAnimSpriteGroupId = SG_TITLE_SCREEN_FLIPPER_AND_START_BASE;
    gTitlescreen.deleteSaveSpriteGroupId = SG_DELETE_SAVE_CONFIRMATION_PANE;
    gTitlescreen.pressStartAndFlippersVisible = TRUE;
    gTitlescreen.deleteSaveWindowVisible = FALSE;
    gTitlescreen.menuSpriteGroupId = SG_MENU_PANEL;
    gTitlescreen.titleScreenLeftFlipperSpriteGroup = SG_TITLE_SCREEN_LEFT_FLIPPER_BASE;
    gTitlescreen.titleScreenRightFlipperSpriteGroup = SG_TITLE_SCREEN_RIGHT_FLIPPER_BASE;
    gTitlescreen.menuVisible = FALSE;
    gTitlescreen.leftFlipperCursorVisible = FALSE;
    gTitlescreen.rightFlipperCursorVisible = FALSE;
    gHighScoreEntrySource = 1;
    gEraseSaveDataAccessStep = 0;
    gEraseSaveDataAccessCounter = 0;
    gEReaderAccessStep = 0;
    gEReaderAccessCounter = 0;

    if (gMain.hasSavedGame == TRUE)
    {
        for (i = 0; i < 7; i++)
            gTitleSavedMenuSpriteSets[i] = gTitleSavedDefaultSprites[i];

        gTitlescreen.menuCursorIndex = 1;
        gTitlescreen.hasSavedGame = TRUE;
    }
    else
    {
        for (i = 0; i < 7; i++)
            gTitleNoSaveMenuSpriteSets[i] = gTitleNoSaveDefaultSprites[i];

        gTitlescreen.menuCursorIndex = 0;
        gTitlescreen.hasSavedGame = FALSE;
        gMain.continueFromSave = FALSE;
    }

    gTitlescreen.idleFramesCounter = 0;
    gTitlescreen.idleFadeoutCounter = 1;
    gTitleTransitionActive = FALSE;
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
        gTitleRestartDebounce = TRUE;
    else
        gTitleRestartDebounce = FALSE;

    gTitleReturnedFromMenu = FALSE;
}

void TitleScreen1_WaitForStartButton(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        if (!gTitleRestartDebounce)
        {
            gTitleTransitionActive = TRUE;
            gTitlescreen.menuAction = 9;
            gMain.subState = SUBSTATE_11;
        }
    }
    else
    {
        gTitleRestartDebounce = FALSE;
    }

    if (!gTitleTransitionActive)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitlePressStartAnimDurations[gTitlescreen.pressStartAnimSpriteGroupId])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.pressStartAnimSpriteGroupId > SG_TITLE_SCREEN_FLIPPER_AND_START_ANIM_MAX)
                gTitlescreen.pressStartAnimSpriteGroupId = SG_TITLE_SCREEN_FLIPPER_AND_START_BASE;
        }

        if (JOY_HELD(KEYS_MASK))
            gTitlescreen.idleFramesCounter = 0;

        if (JOY_NEW(A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animPhase = 0;
            gMain.subState = SUBSTATE_2;
        }

        TitleScreen_CheckDeleteKeyComboPressed();
        CheckEReaderAccessCombo();

        gTitlescreen.idleFramesCounter++;
        if (gTitlescreen.idleFramesCounter > NUM_IDLE_FRAMES)
        {
            if (gTitlescreen.idleFramesCounter % 10 == 0)
            {
                gTitlescreen.idleFadeoutCounter++;
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100 / gTitlescreen.idleFadeoutCounter);
            }

            if (gTitlescreen.idleFadeoutCounter > 9)
            {
                gTitlescreen.idleFramesCounter = 0;
                gTitlescreen.menuAction = 7;
                gMain.subState = SUBSTATE_11;
            }
        }
    }

    RenderTitlePressStartSprites();
}

void TitleScreen2_AnimOpenMenu(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gTitleTransitionActive)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitleMenuSlideInAnimData[gTitlescreen.animPhase][1])
        {
            gTitlescreen.animTimer = 0;
            gTitlescreen.pressStartAnimSpriteGroupId = gTitleMenuSlideInAnimData[gTitlescreen.animPhase][0];
            if (++gTitlescreen.animPhase > 5)
            {
                gTitlescreen.animPhase = 0;
                gTitleReturnedFromMenu = FALSE;
                gTitlescreen.pressStartAndFlippersVisible = FALSE;
                gTitlescreen.menuVisible = TRUE;
                gMain.subState = SUBSTATE_3;
            }
        }
    }

    RenderTitlePressStartSprites();
}

void TitleScreen9_DeleteSaveConfirmation(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gTitleTransitionActive)
    {
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            DeleteSaveFile();
            FadeOutScreen();
            m4aMPlayAllStop();
            DisableVBlankInterrupts();
            gMain.subState = SUBSTATE_LOAD_GRAPHICS;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gTitlescreen.deleteSaveWindowVisible = FALSE;
            gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        }
    }

    RenderTitlePressStartSprites();
}

void TitleScreen3_8010E00(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (gTitleTransitionActive)
        return;

    if (!gTitlescreen.hasSavedGame)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitleMenuRetractDurations[gTitlescreen.animPhase])
        {
            gTitlescreen.animTimer = 0;
            gTitleNoSaveMenuSpriteSets[6] = gTitleNoSaveAnimSprites[gTitlescreen.animPhase];
            if (++gTitlescreen.animPhase > 11)
            {
                gTitlescreen.animPhase = 0;
                gTitlescreen.leftFlipperCursorVisible = TRUE;
                gTitlescreen.rightFlipperCursorVisible = TRUE;
                gMain.subState = SUBSTATE_MENU_INPUT_NO_SAVED_GAME;
            }
        }

        RenderTitleMenuNoSavedGame();
    }
    else
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitleMenuRetractDurations[gTitlescreen.animPhase])
        {
            gTitlescreen.animTimer = 0;
            gTitleSavedMenuSpriteSets[6] = gTitleSavedAnimSprites[gTitlescreen.animPhase];
            if (++gTitlescreen.animPhase > 11)
            {
                gTitlescreen.animPhase = 0;
                gTitlescreen.leftFlipperCursorVisible = TRUE;
                gTitlescreen.rightFlipperCursorVisible = TRUE;
                gMain.subState = SUBSTATE_MENU_INPUT_SAVED_GAME;
            }
        }

        RenderTitleMenuSavedGame();
    }
}

void TitleScreen4_MenuInputNoSavedGame(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gTitleTransitionActive)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitleMenuSlideOutAnimSpriteGroupData[gTitlescreen.animPhase][1])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.animPhase > 6)
                gTitlescreen.animPhase = 0;

            gTitlescreen.titleScreenLeftFlipperSpriteGroup = gTitleMenuSlideOutAnimSpriteGroupData[gTitlescreen.animPhase][0];
            gTitlescreen.titleScreenRightFlipperSpriteGroup = gTitleMenuSlideOutAnimSpriteGroupData[gTitlescreen.animPhase][0] + 3;
        }

        if (JOY_NEW(DPAD_UP))
        {
            m4aSongNumStart(SE_MENU_MOVE);
            if (--gTitlescreen.menuCursorIndex < 0)
                gTitlescreen.menuCursorIndex = 3;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            m4aSongNumStart(SE_MENU_MOVE);
            if (++gTitlescreen.menuCursorIndex > 3)
                gTitlescreen.menuCursorIndex = 0;
        }

        if (JOY_NEW(A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animPhase = 0;
            gMain.subState = SUBSTATE_7;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animPhase = 12;
            gTitlescreen.leftFlipperCursorVisible = FALSE;
            gTitlescreen.rightFlipperCursorVisible = FALSE;
            gMain.subState = SUBSTATE_ANIM_CLOSE_MENU;
        }

        CheckEReaderAccessCombo();
    }

    RenderTitleMenuNoSavedGame();
}

void TitleScreen7_8011020(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gTitleTransitionActive)
    {
        u16 animTimer = gTitlescreen.animTimer;
        u16 mask = 0x3;
        if (!(animTimer & mask))
        {
            if (!gTitlescreen.animPhase)
            {
                gTitlescreen.animPhase = 1;
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), gTempGfxBuffer, 8, 2);
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x61E0), (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
            else
            {
                gTitlescreen.animPhase = 0;
                CopyBgTilesRect(gTempGfxBuffer, (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
        }

        if (gTitlescreen.animTimer > 20)
        {
            gMain.continueFromSave = FALSE;
            gTitlescreen.menuAction = gTitleNoSaveMenuActions[gTitlescreen.menuCursorIndex];
            gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }

        gTitlescreen.animTimer++;
    }

    RenderTitleMenuNoSavedGame();
}

void TitleScreen5_MenuInputSavedGame(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gTitleTransitionActive)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitleMenuSlideOutAnimSpriteGroupData[gTitlescreen.animPhase][1])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.animPhase > 6)
                gTitlescreen.animPhase = 0;

            gTitlescreen.titleScreenLeftFlipperSpriteGroup = gTitleMenuSlideOutAnimSpriteGroupData[gTitlescreen.animPhase][0];
            gTitlescreen.titleScreenRightFlipperSpriteGroup = gTitleMenuSlideOutAnimSpriteGroupData[gTitlescreen.animPhase][0] + 3;
        }

        if (JOY_NEW(DPAD_UP))
        {
            m4aSongNumStart(SE_MENU_MOVE);
            if (--gTitlescreen.menuCursorIndex < 0)
                gTitlescreen.menuCursorIndex = 4;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            m4aSongNumStart(SE_MENU_MOVE);
            if (++gTitlescreen.menuCursorIndex > 4)
                gTitlescreen.menuCursorIndex = 0;
        }

        if (JOY_NEW(A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animPhase = 0;
            gMain.subState = SUBSTATE_8;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animPhase = 12;
            gTitlescreen.leftFlipperCursorVisible = FALSE;
            gTitlescreen.rightFlipperCursorVisible = FALSE;
            gMain.subState = SUBSTATE_ANIM_CLOSE_MENU;
        }

        CheckEReaderAccessCombo();
    }

    RenderTitleMenuSavedGame();
}

void TitleScreen8_8011228(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gTitleTransitionActive)
    {
        u16 animTimer = gTitlescreen.animTimer;
        u16 mask = 0x3;

        // Blink menu item
        if (!(animTimer & mask))
        {
            if (!gTitlescreen.animPhase)
            {
                gTitlescreen.animPhase = 1;
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), gTempGfxBuffer, 8, 2);
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x61E0), (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
            else
            {
                gTitlescreen.animPhase = 0;
                CopyBgTilesRect(gTempGfxBuffer, (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
        }

        if (gTitlescreen.animTimer > 20)
        {
            if (gTitlescreen.menuCursorIndex == 1)
                gMain.continueFromSave = TRUE;
            else
                gMain.continueFromSave = FALSE;

            gTitlescreen.menuAction = gTitleSavedMenuActions[gTitlescreen.menuCursorIndex];
            gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }

        gTitlescreen.animTimer++;
    }

    RenderTitleMenuSavedGame();
}

void TitleScreen6_AnimCloseMenu(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gTitleTransitionActive = TRUE;
        gTitlescreen.menuAction = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (gTitleTransitionActive)
        return;

    if (!gTitlescreen.hasSavedGame)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitleMenuRetractDurations[gTitlescreen.animPhase])
        {
            gTitlescreen.animTimer = 0;
            if (--gTitlescreen.animPhase < 0)
            {
                gTitlescreen.animPhase = 0;
                gTitlescreen.menuCursorIndex = 0;
                gTitleReturnedFromMenu = TRUE;
                gTitlescreen.pressStartAndFlippersVisible = TRUE;
                gTitlescreen.menuVisible = FALSE;
                gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
            }

            gTitleNoSaveMenuSpriteSets[6] = gTitleNoSaveAnimSprites[gTitlescreen.animPhase];
        }

        RenderTitleMenuNoSavedGame();
    }
    else
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gTitleMenuRetractDurations[gTitlescreen.animPhase])
        {
            gTitlescreen.animTimer = 0;
            if (--gTitlescreen.animPhase < 0)
            {
                gTitlescreen.animPhase = 0;
                gTitlescreen.menuCursorIndex = 1;
                gTitleReturnedFromMenu = TRUE;
                gTitlescreen.pressStartAndFlippersVisible = TRUE;
                gTitlescreen.menuVisible = FALSE;
                gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
            }

            gTitleSavedMenuSpriteSets[6] = gTitleSavedAnimSprites[gTitlescreen.animPhase];
        }

        RenderTitleMenuSavedGame();
    }
}

void TitleScreen10_ExecMenuSelection(void)
{
    if (!gTitlescreen.hasSavedGame)
        FadeOutToWhite(RenderTitleMenuNoSavedGame);
    else
        FadeOutToWhite(RenderTitleMenuSavedGame);

    m4aMPlayAllStop();
    DisableVBlankInterrupts();

    if (gTitleMenuStateTable[gTitlescreen.menuAction] == STATE_SCORES_MAIN)
        gHighScoreEntrySource = 0;
    else
        gHighScoreEntrySource = 1;

    gAutoDisplayTitlescreenMenu = FALSE;
    SetMainGameState(gTitleMenuStateTable[gTitlescreen.menuAction]);
}

void TitleScreen11_80114B4(void)
{
    FadeOutToWhite(RenderTitlePressStartSprites);
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gHighScoreEntrySource = 1;
    gAutoDisplayTitlescreenMenu = FALSE;
    SetMainGameState(gTitleMenuStateTable[gTitlescreen.menuAction]);
}

static void TitleScreen_CheckDeleteKeyComboPressed(void)
{
    // To delete save file, press R_BUTTON 3 times while holding L_BUTTON And DPAD_LEFT.
    if (JOY_HELD(L_BUTTON | DPAD_LEFT) == (L_BUTTON | DPAD_LEFT) && JOY_NEW(R_BUTTON))
    {
        gEraseSaveDataAccessCounter = 40;
        if (++gEraseSaveDataAccessStep == 3)
        {
            gEraseSaveDataAccessStep = 0;
            gEraseSaveDataAccessCounter = 0;
            m4aSongNumStart(SE_MENU_POPUP_OPEN);
            gTitlescreen.deleteSaveWindowVisible = TRUE;
            gMain.subState = SUBSTATE_DELETE_SAVE_GAME_CONFIRMATION;
        }
    }

    if (gEraseSaveDataAccessCounter > 0)
    {
        if (--gEraseSaveDataAccessCounter <= 0)
        {
            gEraseSaveDataAccessCounter = 0;
            gEraseSaveDataAccessStep = 0;
        }
    }
}

static void CheckEReaderAccessCombo(void)
{
    // To access the e-reader screen, alternate pressing R_BUTTON and L_BUTTON 6 times while holding DPAD_RIGHT.
    s16 buttonMask = gEReaderAccessButtonSequence[gEReaderAccessStep];
    if (JOY_HELD(DPAD_RIGHT) && JOY_NEW(buttonMask) == buttonMask)
    {
        gEReaderAccessCounter = 40;
        gEReaderAccessStep++;
        if (gEReaderAccessButtonSequence[gEReaderAccessStep] == -1)
        {
            gEReaderAccessStep = 0;
            gEReaderAccessCounter = 0;
            m4aSongNumStart(SE_MENU_SELECT);
            gTitlescreen.menuAction = 5;
            if (gMain.subState == SUBSTATE_WAIT_FOR_START_BUTTON)
                gMain.subState = SUBSTATE_11;
            else
                gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }
    }

    if (JOY_NEW(KEYS_MASK & ~buttonMask))
    {
        gEReaderAccessCounter = 0;
        gEReaderAccessStep = 0;
    }

    if (gEReaderAccessCounter > 0)
    {
        if (--gEReaderAccessCounter <= 0)
        {
            gEReaderAccessCounter = 0;
            gEReaderAccessStep = 0;
        }
    }
}

static void RenderTitlePressStartSprites(void)
{
    int i;
    const struct SpriteSet *spriteSet;
    struct SpriteGroup *startAndFlippersGroup = &gMain.spriteGroups[gTitlescreen.pressStartAnimSpriteGroupId];
    struct SpriteGroup *deleteMenuGroup = &gMain.spriteGroups[gTitlescreen.deleteSaveSpriteGroupId];

    startAndFlippersGroup->active = gTitlescreen.pressStartAndFlippersVisible;
    deleteMenuGroup->active = gTitlescreen.deleteSaveWindowVisible;

    LoadSpriteSets(gTitlePressStartSpriteSets, 5, gMain.spriteGroups);

    if (startAndFlippersGroup->active == TRUE)
    {
        startAndFlippersGroup->baseX = 120;
        startAndFlippersGroup->baseY = 102;
        spriteSet = gTitlePressStartSpriteSets[gTitlescreen.pressStartAnimSpriteGroupId];
        for (i = 0; i < spriteSet->count; i++)
        {
            gOamBuffer[startAndFlippersGroup->oam[i].oamId].x = startAndFlippersGroup->oam[i].xOffset + startAndFlippersGroup->baseX;
            gOamBuffer[startAndFlippersGroup->oam[i].oamId].y = startAndFlippersGroup->oam[i].yOffset + startAndFlippersGroup->baseY;

            asm("");  // needed to match
        }
    }

    if (deleteMenuGroup->active == TRUE)
    {
        deleteMenuGroup->baseX = 120;
        deleteMenuGroup->baseY = 80;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[deleteMenuGroup->oam[i].oamId].x = deleteMenuGroup->oam[i].xOffset + deleteMenuGroup->baseX;
            gOamBuffer[deleteMenuGroup->oam[i].oamId].y = deleteMenuGroup->oam[i].yOffset + deleteMenuGroup->baseY;

            asm("");  // needed to match
        }
    }

    startAndFlippersGroup->active = FALSE;
    deleteMenuGroup->active = FALSE;
}

struct UnknownStruct1
{
    u16 count;
    u8 filler2[6];
};

void RenderTitleMenuNoSavedGame(void)
{
    struct SpriteGroup *menuPanel_SG;
    struct SpriteGroup *leftFlipper_SG;
    struct SpriteGroup *rightFlipper_SG;
    const struct UnknownStruct1 *r12;
    int sp0;

    gMain.blendControl = 0x210;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    menuPanel_SG = &gMain.spriteGroups[gTitlescreen.menuSpriteGroupId];
    leftFlipper_SG = &gMain.spriteGroups[gTitlescreen.titleScreenLeftFlipperSpriteGroup];
    rightFlipper_SG = &gMain.spriteGroups[gTitlescreen.titleScreenRightFlipperSpriteGroup];

    menuPanel_SG->active = gTitlescreen.menuVisible;
    leftFlipper_SG->active = gTitlescreen.leftFlipperCursorVisible;
    rightFlipper_SG->active = gTitlescreen.rightFlipperCursorVisible;

    LoadSpriteSets((const struct SpriteSet *const *)gTitleNoSaveMenuSpriteSets, 7, gMain.spriteGroups);

    if (menuPanel_SG->active == TRUE)
    {
        menuPanel_SG->baseX = 0x78;
        menuPanel_SG->baseY = 0x66;
        r12 = (const struct UnknownStruct1 *)gTitleNoSaveMenuSpriteSets[6];
        for (sp0 = 0; sp0 < r12->count; sp0++)
        {
            struct OamDataSimple *r4 = &menuPanel_SG->oam[sp0];
            if (r12[sp0 + 1].count == 1)  // dunno. wtf?
                gOamBuffer[r4->oamId].objMode = ST_OAM_OBJ_BLEND;
            else
                gOamBuffer[r4->oamId].objMode = ST_OAM_OBJ_NORMAL;
            gOamBuffer[r4->oamId].x = r4->xOffset + menuPanel_SG->baseX;
            gOamBuffer[r4->oamId].y = r4->yOffset + menuPanel_SG->baseY;
        }
    }

    if (leftFlipper_SG->active == TRUE)
    {
        struct OamDataSimple *r5;

        leftFlipper_SG->baseX = gTitleNoSaveArrowPositions[gTitlescreen.menuCursorIndex].x;
        leftFlipper_SG->baseY = gTitleNoSaveArrowPositions[gTitlescreen.menuCursorIndex].y;

        r5 = &leftFlipper_SG->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + leftFlipper_SG->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + leftFlipper_SG->baseY;
    }

    if (rightFlipper_SG->active == TRUE)
    {
        struct OamDataSimple *r5;

        rightFlipper_SG->baseX = gTitleNoSaveSelectorPositions[gTitlescreen.menuCursorIndex].x;
        rightFlipper_SG->baseY = gTitleNoSaveSelectorPositions[gTitlescreen.menuCursorIndex].y;

        r5 = &rightFlipper_SG->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + rightFlipper_SG->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + rightFlipper_SG->baseY;
    }

    menuPanel_SG->active = FALSE;
    leftFlipper_SG->active = FALSE;
    rightFlipper_SG->active = FALSE;
}

void RenderTitleMenuSavedGame(void)
{
    struct SpriteGroup *menuPanel_SG;
    struct SpriteGroup *leftFlipper_SG;
    struct SpriteGroup *rightFlipper_SG;
    const struct UnknownStruct1 *r12;
    int sp0;

    gMain.blendControl = 0x210;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    menuPanel_SG = &gMain.spriteGroups[gTitlescreen.menuSpriteGroupId];
    leftFlipper_SG = &gMain.spriteGroups[gTitlescreen.titleScreenLeftFlipperSpriteGroup];
    rightFlipper_SG = &gMain.spriteGroups[gTitlescreen.titleScreenRightFlipperSpriteGroup];

    menuPanel_SG->active = gTitlescreen.menuVisible;
    leftFlipper_SG->active = gTitlescreen.leftFlipperCursorVisible;
    rightFlipper_SG->active = gTitlescreen.rightFlipperCursorVisible;

    LoadSpriteSets((const struct SpriteSet *const *)gTitleSavedMenuSpriteSets, 7, gMain.spriteGroups);

    if (menuPanel_SG->active == TRUE)
    {
        menuPanel_SG->baseX = 0x78;
        menuPanel_SG->baseY = 0x66;
        r12 = (const struct UnknownStruct1 *)gTitleSavedMenuSpriteSets[6];
        for (sp0 = 0; sp0 < r12->count; sp0++)
        {
            struct OamDataSimple *r4 = &menuPanel_SG->oam[sp0];
            if (r12[sp0 + 1].count == 1)  // dunno. wtf?
                gOamBuffer[r4->oamId].objMode = ST_OAM_OBJ_BLEND;
            else
                gOamBuffer[r4->oamId].objMode = ST_OAM_OBJ_NORMAL;
            gOamBuffer[r4->oamId].x = r4->xOffset + menuPanel_SG->baseX;
            gOamBuffer[r4->oamId].y = r4->yOffset + menuPanel_SG->baseY;
        }
    }

    if (leftFlipper_SG->active == TRUE)
    {
        struct OamDataSimple *r5;

        leftFlipper_SG->baseX = gTitleSavedArrowPositions[gTitlescreen.menuCursorIndex].x;
        leftFlipper_SG->baseY = gTitleSavedArrowPositions[gTitlescreen.menuCursorIndex].y;

        r5 = &leftFlipper_SG->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + leftFlipper_SG->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + leftFlipper_SG->baseY;
    }

    if (rightFlipper_SG->active == TRUE)
    {
        struct OamDataSimple *r5;

        rightFlipper_SG->baseX = gTitleSavedSelectorPositions[gTitlescreen.menuCursorIndex].x;
        rightFlipper_SG->baseY = gTitleSavedSelectorPositions[gTitlescreen.menuCursorIndex].y;

        r5 = &rightFlipper_SG->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + rightFlipper_SG->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + rightFlipper_SG->baseY;
    }

    menuPanel_SG->active = FALSE;
    leftFlipper_SG->active = FALSE;
    rightFlipper_SG->active = FALSE;
}

void DeleteSaveFile(void)
{
    ResetSaveFile();
    SaveFile_WriteToSram();
    gMain.hasSavedGame = FALSE;
    WriteAndVerifySramFast((const u8 *)&gMain.hasSavedGame, (void *)0x0E000544, sizeof(gMain.hasSavedGame));
}
