#include "global.h"
#include "agb_sram.h"
#include "m4a.h"
#include "titlescreen.h"
#include "main.h"
#include "constants/bg_music.h"

static void TitleScreen_CheckDeleteKeyComboPressed(void);
static void CheckEReaderKeyComboPressed(void);
static void RenderTitleScreenSprites(void);

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

void TitlescreenMain(void)
{
    gTitlescreenStateFuncs[gMain.subState]();
}

void LoadTitlescreenGraphics(void)
{
    int autoDisplayMenu;

    ResetSomeGraphicsRelatedStuff();
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
        gUnknown_202BE24 = 0;
        gTitlescreen.pressStartAndFlippersVisible = FALSE;
        gTitlescreen.menuVisible = autoDisplayMenu;
        gMain.subState = SUBSTATE_3;
        EnableVBlankProcessing();
        FadeInFromWhiteWithCallback(NULL);
    }
    else
    {
        gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        EnableVBlankProcessing();
        FadeInFromWhiteWithCallback(RenderTitleScreenSprites);
    }

    m4aSongNumStart(MUS_TITLE);
}

void InitTitlescreenStates(void)
{
    int i;

    gTitlescreen.animTimer = 0;
    gTitlescreen.animKeyframe = 0;
    gTitlescreen.menuSelectionIndex = 0;
    gTitlescreen.pressStartAnimFrame = 0;
    gTitlescreen.deleteSaveSpriteIndex = 4;
    gTitlescreen.pressStartAndFlippersVisible = TRUE;
    gTitlescreen.deleteSaveWindowVisible = FALSE;
    gTitlescreen.menuOptionsSpriteIndex = 6;
    gTitlescreen.cursorSpriteIndexA = 0;
    gTitlescreen.cursorSpriteIndexB = 3;
    gTitlescreen.menuVisible = FALSE;
    gTitlescreen.cursorVisibleA = 0;
    gTitlescreen.cursorVisibleB = 0;
    gUnknown_0202C588 = 1;
    gEraseSaveDataAccessStep = 0;
    gEraseSaveDataAccessCounter = 0;
    gEReaderAccessStep = 0;
    gEReaderAccessCounter = 0;

    if (gMain.hasSavedGame == TRUE)
    {
        for (i = 0; i < 7; i++)
            gUnknown_0202BE00[i] = gUnknown_086A975C[i];

        gTitlescreen.menuCursorIndex = 1;
        gTitlescreen.useSavedGameSprites = 1;
    }
    else
    {
        for (i = 0; i < 7; i++)
            gUnknown_0201C190[i] = gUnknown_086A96F8[i];

        gTitlescreen.menuCursorIndex = 0;
        gTitlescreen.useSavedGameSprites = 0;
        gMain.isResuming = 0;
    }

    gTitlescreen.idleFramesCounter = 0;
    gTitlescreen.idleFadeoutCounter = 1;
    gUnknown_020028A4 = 0;
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
        gUnknown_020028A5 = 1;
    else
        gUnknown_020028A5 = 0;

    gUnknown_202BE24 = 0;
}

void TitleScreen1_WaitForStartButton(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        if (!gUnknown_020028A5)
        {
            gUnknown_020028A4 = 1;
            gTitlescreen.menuSelectionIndex = 9;
            gMain.subState = SUBSTATE_11;
        }
    }
    else
    {
        gUnknown_020028A5 = 0;
    }

    if (!gUnknown_020028A4)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9662[gTitlescreen.pressStartAnimFrame])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.pressStartAnimFrame > 3)
                gTitlescreen.pressStartAnimFrame = 0;
        }

        if (JOY_HELD(KEYS_MASK))
            gTitlescreen.idleFramesCounter = 0;

        if (JOY_NEW(A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animKeyframe = 0;
            gMain.subState = SUBSTATE_2;
        }

        TitleScreen_CheckDeleteKeyComboPressed();
        CheckEReaderKeyComboPressed();

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
                gTitlescreen.menuSelectionIndex = 7;
                gMain.subState = SUBSTATE_11;
            }
        }
    }

    RenderTitleScreenSprites();
}

void TitleScreen2_8010CF0(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gUnknown_020028A4)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9666[gTitlescreen.animKeyframe][1])
        {
            gTitlescreen.animTimer = 0;
            gTitlescreen.pressStartAnimFrame = gUnknown_086A9666[gTitlescreen.animKeyframe][0];
            if (++gTitlescreen.animKeyframe > 5)
            {
                gTitlescreen.animKeyframe = 0;
                gUnknown_202BE24 = 0;
                gTitlescreen.pressStartAndFlippersVisible = FALSE;
                gTitlescreen.menuVisible = TRUE;
                gMain.subState = SUBSTATE_3;
            }
        }
    }

    RenderTitleScreenSprites();
}

void TitleScreen9_8010D84(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gUnknown_020028A4)
    {
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            EraseSaveData();
            FadeOutToWhite();
            m4aMPlayAllStop();
            DisableVBlankProcessing();
            gMain.subState = SUBSTATE_LOAD_GRAPHICS;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gTitlescreen.deleteSaveWindowVisible = FALSE;
            gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        }
    }

    RenderTitleScreenSprites();
}

void TitleScreen3_8010E00(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (gUnknown_020028A4)
        return;

    if (!gTitlescreen.useSavedGameSprites)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.animKeyframe])
        {
            gTitlescreen.animTimer = 0;
            gUnknown_0201C190[6] = gUnknown_086A9714[gTitlescreen.animKeyframe];
            if (++gTitlescreen.animKeyframe > 11)
            {
                gTitlescreen.animKeyframe = 0;
                gTitlescreen.cursorVisibleA = 1;
                gTitlescreen.cursorVisibleB = 1;
                gMain.subState = SUBSTATE_MENU_INPUT_NO_SAVED_GAME;
            }
        }

        RenderTitleMenu0Sprites();
    }
    else
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.animKeyframe])
        {
            gTitlescreen.animTimer = 0;
            gUnknown_0202BE00[6] = gUnknown_086A9778[gTitlescreen.animKeyframe];
            if (++gTitlescreen.animKeyframe > 11)
            {
                gTitlescreen.animKeyframe = 0;
                gTitlescreen.cursorVisibleA = 1;
                gTitlescreen.cursorVisibleB = 1;
                gMain.subState = SUBSTATE_MENU_INPUT_SAVED_GAME;
            }
        }

        RenderTitleMenu1Sprites();
    }
}

void TitleScreen4_MenuInputNoSavedGame(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gUnknown_020028A4)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9672[gTitlescreen.animKeyframe][1])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.animKeyframe > 6)
                gTitlescreen.animKeyframe = 0;

            gTitlescreen.cursorSpriteIndexA = gUnknown_086A9672[gTitlescreen.animKeyframe][0];
            gTitlescreen.cursorSpriteIndexB = gUnknown_086A9672[gTitlescreen.animKeyframe][0] + 3;
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
            gTitlescreen.animKeyframe = 0;
            gMain.subState = SUBSTATE_7;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animKeyframe = 12;
            gTitlescreen.cursorVisibleA = 0;
            gTitlescreen.cursorVisibleB = 0;
            gMain.subState = SUBSTATE_ANIM_CLOSE_MENU;
        }

        CheckEReaderKeyComboPressed();
    }

    RenderTitleMenu0Sprites();
}

void TitleScreen7_8011020(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gUnknown_020028A4)
    {
        u16 animTimer = gTitlescreen.animTimer;
        u16 mask = 0x3;
        if (!(animTimer & mask))
        {
            if (!gTitlescreen.animKeyframe)
            {
                gTitlescreen.animKeyframe = 1;
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), gTempGfxBuffer, 8, 2);
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x61E0), (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
            else
            {
                gTitlescreen.animKeyframe = 0;
                CopyBgTilesRect(gTempGfxBuffer, (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
        }

        if (gTitlescreen.animTimer > 20)
        {
            gMain.isResuming = 0;
            gTitlescreen.menuSelectionIndex = gUnknown_086A96A4[gTitlescreen.menuCursorIndex];
            gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }

        gTitlescreen.animTimer++;
    }

    RenderTitleMenu0Sprites();
}

void TitleScreen5_MenuInputSavedGame(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gUnknown_020028A4)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9672[gTitlescreen.animKeyframe][1])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.animKeyframe > 6)
                gTitlescreen.animKeyframe = 0;

            gTitlescreen.cursorSpriteIndexA = gUnknown_086A9672[gTitlescreen.animKeyframe][0];
            gTitlescreen.cursorSpriteIndexB = gUnknown_086A9672[gTitlescreen.animKeyframe][0] + 3;
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
            gTitlescreen.animKeyframe = 0;
            gMain.subState = SUBSTATE_8;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gTitlescreen.animTimer = 0;
            gTitlescreen.animKeyframe = 12;
            gTitlescreen.cursorVisibleA = 0;
            gTitlescreen.cursorVisibleB = 0;
            gMain.subState = SUBSTATE_ANIM_CLOSE_MENU;
        }

        CheckEReaderKeyComboPressed();
    }

    RenderTitleMenu1Sprites();
}

void TitleScreen8_8011228(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gUnknown_020028A4)
    {
        u16 animTimer = gTitlescreen.animTimer;
        u16 mask = 0x3;

        // Blink menu item
        if (!(animTimer & mask))
        {
            if (!gTitlescreen.animKeyframe)
            {
                gTitlescreen.animKeyframe = 1;
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), gTempGfxBuffer, 8, 2);
                CopyBgTilesRect((void *)(OBJ_VRAM0 + 0x61E0), (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
            else
            {
                gTitlescreen.animKeyframe = 0;
                CopyBgTilesRect(gTempGfxBuffer, (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
        }

        if (gTitlescreen.animTimer > 20)
        {
            if (gTitlescreen.menuCursorIndex == 1)
                gMain.isResuming = 1;
            else
                gMain.isResuming = 0;

            gTitlescreen.menuSelectionIndex = gUnknown_086A96D4[gTitlescreen.menuCursorIndex];
            gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }

        gTitlescreen.animTimer++;
    }

    RenderTitleMenu1Sprites();
}

void TitleScreen6_AnimCloseMenu(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.menuSelectionIndex = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (gUnknown_020028A4)
        return;

    if (!gTitlescreen.useSavedGameSprites)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.animKeyframe])
        {
            gTitlescreen.animTimer = 0;
            if (--gTitlescreen.animKeyframe < 0)
            {
                gTitlescreen.animKeyframe = 0;
                gTitlescreen.menuCursorIndex = 0;
                gUnknown_202BE24 = 1;
                gTitlescreen.pressStartAndFlippersVisible = TRUE;
                gTitlescreen.menuVisible = FALSE;
                gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
            }

            gUnknown_0201C190[6] = gUnknown_086A9714[gTitlescreen.animKeyframe];
        }

        RenderTitleMenu0Sprites();
    }
    else
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.animKeyframe])
        {
            gTitlescreen.animTimer = 0;
            if (--gTitlescreen.animKeyframe < 0)
            {
                gTitlescreen.animKeyframe = 0;
                gTitlescreen.menuCursorIndex = 1;
                gUnknown_202BE24 = 1;
                gTitlescreen.pressStartAndFlippersVisible = TRUE;
                gTitlescreen.menuVisible = FALSE;
                gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
            }

            gUnknown_0202BE00[6] = gUnknown_086A9778[gTitlescreen.animKeyframe];
        }

        RenderTitleMenu1Sprites();
    }
}

void TitleScreen10_ExecMenuSelection(void)
{
    if (!gTitlescreen.useSavedGameSprites)
        FadeOutToWhiteWithCallback(RenderTitleMenu0Sprites);
    else
        FadeOutToWhiteWithCallback(RenderTitleMenu1Sprites);

    m4aMPlayAllStop();
    DisableVBlankProcessing();

    if (gUnknown_086A964C[gTitlescreen.menuSelectionIndex] == STATE_SCORES_MAIN)
        gUnknown_0202C588 = 0;
    else
        gUnknown_0202C588 = 1;

    gAutoDisplayTitlescreenMenu = FALSE;
    SetMainGameState(gUnknown_086A964C[gTitlescreen.menuSelectionIndex]);
}

void TitleScreen11_80114B4(void)
{
    FadeOutToWhiteWithCallback(RenderTitleScreenSprites);
    m4aMPlayAllStop();
    DisableVBlankProcessing();
    gUnknown_0202C588 = 1;
    gAutoDisplayTitlescreenMenu = FALSE;
    SetMainGameState(gUnknown_086A964C[gTitlescreen.menuSelectionIndex]);
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

static void CheckEReaderKeyComboPressed(void)
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
            gTitlescreen.menuSelectionIndex = 5;
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

static void RenderTitleScreenSprites(void)
{
    int i;
    const struct SpriteSet *spriteSet;
    struct SpriteGroup *startAndFlippersGroup = &gMain_spriteGroups[gTitlescreen.pressStartAnimFrame];
    struct SpriteGroup *deleteMenuGroup = &gMain_spriteGroups[gTitlescreen.deleteSaveSpriteIndex];

    startAndFlippersGroup->available = gTitlescreen.pressStartAndFlippersVisible;
    deleteMenuGroup->available = gTitlescreen.deleteSaveWindowVisible;

    LoadSpriteSets(gUnknown_086A96E4, 5, gMain_spriteGroups);

    if (startAndFlippersGroup->available == TRUE)
    {
        startAndFlippersGroup->baseX = 120;
        startAndFlippersGroup->baseY = 102;
        spriteSet = gUnknown_086A96E4[gTitlescreen.pressStartAnimFrame];
        for (i = 0; i < spriteSet->count; i++)
        {
            gOamBuffer[startAndFlippersGroup->oam[i].oamId].x = startAndFlippersGroup->oam[i].xOffset + startAndFlippersGroup->baseX;
            gOamBuffer[startAndFlippersGroup->oam[i].oamId].y = startAndFlippersGroup->oam[i].yOffset + startAndFlippersGroup->baseY;

            asm("");  // needed to match
        }
    }

    if (deleteMenuGroup->available == TRUE)
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

    startAndFlippersGroup->available = FALSE;
    deleteMenuGroup->available = FALSE;
}

struct SpriteSetHeader
{
    u16 count;
    u8 filler2[6];
};

void RenderTitleMenu0Sprites(void)
{
    struct SpriteGroup *menuSpriteGroup;
    struct SpriteGroup *r9;
    struct SpriteGroup *r8;
    const struct SpriteSetHeader *r12;
    int sp0;

    gMain.blendControl = 0x210;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    menuSpriteGroup = &gMain.spriteGroups[gTitlescreen.menuOptionsSpriteIndex];
    r9 = &gMain.spriteGroups[gTitlescreen.cursorSpriteIndexA];
    r8 = &gMain.spriteGroups[gTitlescreen.cursorSpriteIndexB];

    menuSpriteGroup->available = gTitlescreen.menuVisible;
    r9->available = gTitlescreen.cursorVisibleA;
    r8->available = gTitlescreen.cursorVisibleB;

    LoadSpriteSets((const struct SpriteSet *const *)gUnknown_0201C190, 7, gMain.spriteGroups);

    if (menuSpriteGroup->available == 1)
    {
        menuSpriteGroup->baseX = 0x78;
        menuSpriteGroup->baseY = 0x66;
        r12 = (const struct SpriteSetHeader *)gUnknown_0201C190[6];
        for (sp0 = 0; sp0 < r12->count; sp0++)
        {
            struct OamDataSimple *r4 = &menuSpriteGroup->oam[sp0];
            if (r12[sp0 + 1].count == 1)  // dunno. wtf?
                gOamBuffer[r4->oamId].objMode = 1;
            else
                gOamBuffer[r4->oamId].objMode = 0;
            gOamBuffer[r4->oamId].x = r4->xOffset + menuSpriteGroup->baseX;
            gOamBuffer[r4->oamId].y = r4->yOffset + menuSpriteGroup->baseY;
        }
    }

    if (r9->available == 1)
    {
        struct OamDataSimple *r5;

        r9->baseX = gUnknown_086A9684[gTitlescreen.menuCursorIndex].x;
        r9->baseY = gUnknown_086A9684[gTitlescreen.menuCursorIndex].y;

        r5 = &r9->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + r9->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + r9->baseY;
    }

    if (r8->available == 1)
    {
        struct OamDataSimple *r5;

        r8->baseX = gUnknown_086A9694[gTitlescreen.menuCursorIndex].x;
        r8->baseY = gUnknown_086A9694[gTitlescreen.menuCursorIndex].y;

        r5 = &r8->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + r8->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + r8->baseY;
    }

    menuSpriteGroup->available = FALSE;
    r9->available = FALSE;
    r8->available = FALSE;
}

void RenderTitleMenu1Sprites(void)
{
    struct SpriteGroup *r10;
    struct SpriteGroup *r9;
    struct SpriteGroup *r8;
    const struct SpriteSetHeader *r12;
    int sp0;

    gMain.blendControl = 0x210;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    r10 = &gMain.spriteGroups[gTitlescreen.menuOptionsSpriteIndex];
    r9 = &gMain.spriteGroups[gTitlescreen.cursorSpriteIndexA];
    r8 = &gMain.spriteGroups[gTitlescreen.cursorSpriteIndexB];

    r10->available = gTitlescreen.menuVisible;
    r9->available = gTitlescreen.cursorVisibleA;
    r8->available = gTitlescreen.cursorVisibleB;

    LoadSpriteSets((const struct SpriteSet *const *)gUnknown_0202BE00, 7, gMain.spriteGroups);

    if (r10->available == 1)
    {
        r10->baseX = 0x78;
        r10->baseY = 0x66;
        r12 = (const struct SpriteSetHeader *)gUnknown_0202BE00[6];
        for (sp0 = 0; sp0 < r12->count; sp0++)
        {
            struct OamDataSimple *r4 = &r10->oam[sp0];
            if (r12[sp0 + 1].count == 1)  // dunno. wtf?
                gOamBuffer[r4->oamId].objMode = 1;
            else
                gOamBuffer[r4->oamId].objMode = 0;
            gOamBuffer[r4->oamId].x = r4->xOffset + r10->baseX;
            gOamBuffer[r4->oamId].y = r4->yOffset + r10->baseY;
        }
    }

    if (r9->available == 1)
    {
        struct OamDataSimple *r5;

        r9->baseX = gUnknown_086A96AC[gTitlescreen.menuCursorIndex].x;
        r9->baseY = gUnknown_086A96AC[gTitlescreen.menuCursorIndex].y;

        r5 = &r9->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + r9->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + r9->baseY;
    }

    if (r8->available == 1)
    {
        struct OamDataSimple *r5;

        r8->baseX = gUnknown_086A96C0[gTitlescreen.menuCursorIndex].x;
        r8->baseY = gUnknown_086A96C0[gTitlescreen.menuCursorIndex].y;

        r5 = &r8->oam[0];

        gOamBuffer[r5->oamId].x = r5->xOffset + r8->baseX;
        gOamBuffer[r5->oamId].y = r5->yOffset + r8->baseY;
    }

    r10->available = FALSE;
    r9->available = FALSE;
    r8->available = FALSE;
}

void EraseSaveData(void)
{
    ResetSaveFile();
    SaveFile_WriteToSram();
    gMain.hasSavedGame = FALSE;
    WriteAndVerifySramFast((const u8 *)&gMain.hasSavedGame, (void *)0x0E000544, sizeof(gMain.hasSavedGame));
}
