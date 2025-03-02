#include "global.h"
#include "agb_sram.h"
#include "m4a.h"
#include "titlescreen.h"
#include "main.h"
#include "constants/bg_music.h"

static void sub_114FC(void);
static void sub_1157C(void);
static void sub_11640(void);

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
    SUBSTATE_9,
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
    gMain.unk16 = REG_DISPCNT;

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
        sub_0CBC();
        sub_FD5C(NULL);
    }
    else
    {
        gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        sub_0CBC();
        sub_FD5C(sub_11640);
    }

    m4aSongNumStart(MUS_TITLE);
}

void InitTitlescreenStates(void)
{
    int i;

    gTitlescreen.animTimer = 0;
    gTitlescreen.unk2 = 0;
    gTitlescreen.unk6 = 0;
    gTitlescreen.unk8 = 0;
    gTitlescreen.unk10 = 4;
    gTitlescreen.pressStartAndFlippersVisible = TRUE;
    gTitlescreen.deleteSaveWindowVisible = FALSE;
    gTitlescreen.unkA = 6;
    gTitlescreen.unkC = 0;
    gTitlescreen.unkE = 3;
    gTitlescreen.menuVisible = FALSE;
    gTitlescreen.unkD = 0;
    gTitlescreen.unkF = 0;
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
        gTitlescreen.unk7 = 1;
    }
    else
    {
        for (i = 0; i < 7; i++)
            gUnknown_0201C190[i] = gUnknown_086A96F8[i];

        gTitlescreen.menuCursorIndex = 0;
        gTitlescreen.unk7 = 0;
        gMain.unkD = 0;
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
            gTitlescreen.unk6 = 9;
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
        if (gTitlescreen.animTimer >= gUnknown_086A9662[gTitlescreen.unk8])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.unk8 > 3)
                gTitlescreen.unk8 = 0;
        }

        if (JOY_HELD(KEYS_MASK))
            gTitlescreen.idleFramesCounter = 0;

        if (JOY_NEW(A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x65);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 0;
            gMain.subState = SUBSTATE_2;
        }

        sub_114FC();
        sub_1157C();

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
                gTitlescreen.unk6 = 7;
                gMain.subState = SUBSTATE_11;
            }
        }
    }

    sub_11640();
}

void TitleScreen2_8010CF0(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gUnknown_020028A4)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9666[gTitlescreen.unk2][1])
        {
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk8 = gUnknown_086A9666[gTitlescreen.unk2][0];
            if (++gTitlescreen.unk2 > 5)
            {
                gTitlescreen.unk2 = 0;
                gUnknown_202BE24 = 0;
                gTitlescreen.pressStartAndFlippersVisible = FALSE;
                gTitlescreen.menuVisible = TRUE;
                gMain.subState = SUBSTATE_3;
            }
        }
    }

    sub_11640();
}

void TitleScreen9_8010D84(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gUnknown_020028A4)
    {
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x65);
            sub_11B74();
            sub_02B4();
            m4aMPlayAllStop();
            sub_0D10();
            gMain.subState = SUBSTATE_LOAD_GRAPHICS;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x66);
            gTitlescreen.deleteSaveWindowVisible = FALSE;
            gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        }
    }

    sub_11640();
}

void TitleScreen3_8010E00(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_11;
    }
    
    if (gUnknown_020028A4)
        return;

    if (!gTitlescreen.unk7)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.unk2])
        {
            gTitlescreen.animTimer = 0;
            gUnknown_0201C190[6] = gUnknown_086A9714[gTitlescreen.unk2];
            if (++gTitlescreen.unk2 > 11)
            {
                gTitlescreen.unk2 = 0;
                gTitlescreen.unkD = 1;
                gTitlescreen.unkF = 1;
                gMain.subState = SUBSTATE_MENU_INPUT_NO_SAVED_GAME;
            }
        }

        sub_1175C();
    }
    else
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.unk2])
        {
            gTitlescreen.animTimer = 0;
            gUnknown_0202BE00[6] = gUnknown_086A9778[gTitlescreen.unk2];
            if (++gTitlescreen.unk2 > 11)
            {
                gTitlescreen.unk2 = 0;
                gTitlescreen.unkD = 1;
                gTitlescreen.unkF = 1;
                gMain.subState = SUBSTATE_MENU_INPUT_SAVED_GAME;
            }
        }

        sub_11968();
    }
}

void TitleScreen4_MenuInputNoSavedGame(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gUnknown_020028A4)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9672[gTitlescreen.unk2][1])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.unk2 > 6)
                gTitlescreen.unk2 = 0;

            gTitlescreen.unkC = gUnknown_086A9672[gTitlescreen.unk2][0];
            gTitlescreen.unkE = gUnknown_086A9672[gTitlescreen.unk2][0] + 3;
        }

        if (JOY_NEW(DPAD_UP))
        {
            m4aSongNumStart(SE_SELECT);
            if (--gTitlescreen.menuCursorIndex < 0)
                gTitlescreen.menuCursorIndex = 3;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            m4aSongNumStart(SE_SELECT);
            if (++gTitlescreen.menuCursorIndex > 3)
                gTitlescreen.menuCursorIndex = 0;
        }

        if (JOY_NEW(A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x65);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 0;
            gMain.subState = SUBSTATE_7;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x66);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 12;
            gTitlescreen.unkD = 0;
            gTitlescreen.unkF = 0;
            gMain.subState = SUBSTATE_ANIM_CLOSE_MENU;
        }

        sub_1157C();
    }

    sub_1175C();
}

void TitleScreen7_8011020(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gUnknown_020028A4)
    {
        u16 animTimer = gTitlescreen.animTimer;
        u16 mask = 0x3;
        if (!(animTimer & mask))
        {
            if (!gTitlescreen.unk2)
            {
                gTitlescreen.unk2 = 1;
                sub_10708((void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), gUnknown_03000000, 8, 2);
                sub_10708((void *)(OBJ_VRAM0 + 0x61E0), (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
            else
            {
                gTitlescreen.unk2 = 0;
                sub_10708(gUnknown_03000000, (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
        }

        if (gTitlescreen.animTimer > 20)
        {
            gMain.unkD = 0;
            gTitlescreen.unk6 = gUnknown_086A96A4[gTitlescreen.menuCursorIndex];
            gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }

        gTitlescreen.animTimer++;
    }

    sub_1175C();
}

void TitleScreen5_MenuInputSavedGame(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gUnknown_020028A4)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9672[gTitlescreen.unk2][1])
        {
            gTitlescreen.animTimer = 0;
            if (++gTitlescreen.unk2 > 6)
                gTitlescreen.unk2 = 0;

            gTitlescreen.unkC = gUnknown_086A9672[gTitlescreen.unk2][0];
            gTitlescreen.unkE = gUnknown_086A9672[gTitlescreen.unk2][0] + 3;
        }

        if (JOY_NEW(DPAD_UP))
        {
            m4aSongNumStart(SE_SELECT);
            if (--gTitlescreen.menuCursorIndex < 0)
                gTitlescreen.menuCursorIndex = 4;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            m4aSongNumStart(SE_SELECT);
            if (++gTitlescreen.menuCursorIndex > 4)
                gTitlescreen.menuCursorIndex = 0;
        }

        if (JOY_NEW(A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x65);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 0;
            gMain.subState = SUBSTATE_8;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x66);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 12;
            gTitlescreen.unkD = 0;
            gTitlescreen.unkF = 0;
            gMain.subState = SUBSTATE_ANIM_CLOSE_MENU;
        }

        sub_1157C();
    }

    sub_11968();
}

void TitleScreen8_8011228(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (!gUnknown_020028A4)
    {
        u16 animTimer = gTitlescreen.animTimer;
        u16 mask = 0x3;

        // Blink menu item
        if (!(animTimer & mask))
        {
            if (!gTitlescreen.unk2)
            {
                gTitlescreen.unk2 = 1;
                sub_10708((void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), gUnknown_03000000, 8, 2);
                sub_10708((void *)(OBJ_VRAM0 + 0x61E0), (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
            else
            {
                gTitlescreen.unk2 = 0;
                sub_10708(gUnknown_03000000, (void *)(OBJ_VRAM0 + 0x1E0 + gTitlescreen.menuCursorIndex * 0x800), 8, 2);
            }
        }

        if (gTitlescreen.animTimer > 20)
        {
            if (gTitlescreen.menuCursorIndex == 1)
                gMain.unkD = 1;
            else
                gMain.unkD = 0;

            gTitlescreen.unk6 = gUnknown_086A96D4[gTitlescreen.menuCursorIndex];
            gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }

        gTitlescreen.animTimer++;
    }

    sub_11968();
}

void TitleScreen6_AnimCloseMenu(void)
{
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_11;
    }

    if (gUnknown_020028A4)
        return;

    if (!gTitlescreen.unk7)
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.unk2])
        {
            gTitlescreen.animTimer = 0;
            if (--gTitlescreen.unk2 < 0)
            {
                gTitlescreen.unk2 = 0;
                gTitlescreen.menuCursorIndex = 0;
                gUnknown_202BE24 = 1;
                gTitlescreen.pressStartAndFlippersVisible = TRUE;
                gTitlescreen.menuVisible = FALSE;
                gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
            }

            gUnknown_0201C190[6] = gUnknown_086A9714[gTitlescreen.unk2];
        }

        sub_1175C();
    }
    else
    {
        gTitlescreen.animTimer++;
        if (gTitlescreen.animTimer >= gUnknown_086A9748[gTitlescreen.unk2])
        {
            gTitlescreen.animTimer = 0;
            if (--gTitlescreen.unk2 < 0)
            {
                gTitlescreen.unk2 = 0;
                gTitlescreen.menuCursorIndex = 1;
                gUnknown_202BE24 = 1;
                gTitlescreen.pressStartAndFlippersVisible = TRUE;
                gTitlescreen.menuVisible = FALSE;
                gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
            }

            gUnknown_0202BE00[6] = gUnknown_086A9778[gTitlescreen.unk2];
        }

        sub_11968();
    }
}

void TitleScreen10_ExecMenuSelection(void)
{
    if (!gTitlescreen.unk7)
        sub_FE04(sub_1175C);
    else
        sub_FE04(sub_11968);

    m4aMPlayAllStop();
    sub_0D10();

    if (gUnknown_086A964C[gTitlescreen.unk6] == STATE_SCORES_MAIN)
        gUnknown_0202C588 = 0;
    else
        gUnknown_0202C588 = 1;

    gAutoDisplayTitlescreenMenu = FALSE;
    SetMainGameState(gUnknown_086A964C[gTitlescreen.unk6]);
}

void TitleScreen11_80114B4(void)
{
    sub_FE04(sub_11640);
    m4aMPlayAllStop();
    sub_0D10();
    gUnknown_0202C588 = 1;
    gAutoDisplayTitlescreenMenu = FALSE;
    SetMainGameState(gUnknown_086A964C[gTitlescreen.unk6]);
}

static void sub_114FC(void)
{
    // To delete save file, press R_BUTTON 3 times while holding L_BUTTON And DPAD_LEFT.
    if (JOY_HELD(L_BUTTON | DPAD_LEFT) == (L_BUTTON | DPAD_LEFT))
    {
        if (JOY_NEW(R_BUTTON))
        {
            gEraseSaveDataAccessCounter = 40;
            if (++gEraseSaveDataAccessStep == 3)
            {
                gEraseSaveDataAccessStep = 0;
                gEraseSaveDataAccessCounter = 0;
                m4aSongNumStart(SE_UNKNOWN_0x68);
                gTitlescreen.deleteSaveWindowVisible = TRUE;
                gMain.subState = SUBSTATE_9;
            }
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

static void sub_1157C(void)
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
            m4aSongNumStart(SE_UNKNOWN_0x65);
            gTitlescreen.unk6 = 5;
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

static void sub_11640(void)
{
    int i;
    const struct SpriteSet *spriteSet;
    struct SpriteGroup *startAndFlippersGroup = &gUnknown_0200B3B8[gTitlescreen.unk8];
    struct SpriteGroup *deleteMenuGroup = &gUnknown_0200B3B8[gTitlescreen.unk10];

    startAndFlippersGroup->available = gTitlescreen.pressStartAndFlippersVisible;
    deleteMenuGroup->available = gTitlescreen.deleteSaveWindowVisible;

    LoadSpriteSets(gUnknown_086A96E4, 5, gUnknown_0200B3B8);

    if (startAndFlippersGroup->available == TRUE)
    {
        startAndFlippersGroup->baseX = 120;
        startAndFlippersGroup->baseY = 102;
        spriteSet = gUnknown_086A96E4[gTitlescreen.unk8];
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

struct UnknownStruct1
{
    u16 count;
    u8 filler2[6];
};

void sub_1175C(void)
{
    struct SpriteGroup *menuSpriteGroup;
    struct SpriteGroup *r9;
    struct SpriteGroup *r8;
    const struct UnknownStruct1 *r12;
    int sp0;

    gMain.blendControl = 0x210;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    menuSpriteGroup = &gMain.spriteGroups[gTitlescreen.unkA];
    r9 = &gMain.spriteGroups[gTitlescreen.unkC];
    r8 = &gMain.spriteGroups[gTitlescreen.unkE];

    menuSpriteGroup->available = gTitlescreen.menuVisible;
    r9->available = gTitlescreen.unkD;
    r8->available = gTitlescreen.unkF;

    LoadSpriteSets((const struct SpriteSet *const *)gUnknown_0201C190, 7, gMain.spriteGroups);

    if (menuSpriteGroup->available == 1)
    {
        menuSpriteGroup->baseX = 0x78;
        menuSpriteGroup->baseY = 0x66;
        r12 = (const struct UnknownStruct1 *)gUnknown_0201C190[6];
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

void sub_11968(void)
{
    struct SpriteGroup *r10;
    struct SpriteGroup *r9;
    struct SpriteGroup *r8;
    const struct UnknownStruct1 *r12;
    int sp0;

    gMain.blendControl = 0x210;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    r10 = &gMain.spriteGroups[gTitlescreen.unkA];
    r9 = &gMain.spriteGroups[gTitlescreen.unkC];
    r8 = &gMain.spriteGroups[gTitlescreen.unkE];

    r10->available = gTitlescreen.menuVisible;
    r9->available = gTitlescreen.unkD;
    r8->available = gTitlescreen.unkF;

    LoadSpriteSets((const struct SpriteSet *const *)gUnknown_0202BE00, 7, gMain.spriteGroups);

    if (r10->available == 1)
    {
        r10->baseX = 0x78;
        r10->baseY = 0x66;
        r12 = (const struct UnknownStruct1 *)gUnknown_0202BE00[6];
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

void sub_11B74(void)
{
    sub_52C64();
    SaveFile_WriteToSram();
    gMain.hasSavedGame = FALSE;
    WriteAndVerifySramFast((const u8 *)&gMain.hasSavedGame, (void *)0x0E000544, sizeof(gMain.hasSavedGame));
}
