#include "global.h"
#include "agb_sram.h"
#include "m4a.h"
#include "titlescreen.h"
#include "main.h"

static void sub_114FC(void);
static void sub_1157C(void);
static void sub_11640(void);

// If the user doesn't press any buttons at the title screen,
// it will transition to a demo gameplay experience.
#define NUM_IDLE_FRAMES 1800

enum
{
    SUBSTATE_LOAD_GRAPHICS = 0,
    SUBSTATE_WAIT_FOR_START_BUTTON = 1,
    SUBSTATE_MENU_INPUT_NO_SAVED_GAME = 4,
    SUBSTATE_MENU_INPUT_SAVED_GAME = 5,
    SUBSTATE_ANIM_CLOSE_MENU = 6,
    SUBSTATE_EXEC_MENU_SELECTION = 10
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

    sub_10AC0();

    autoDisplayMenu = gAutoDisplayTitlescreenMenu;
    if (autoDisplayMenu == 1)
    {
        gUnknown_202BE24 = 0;
        gTitlescreen.unk9 = 0;
        gTitlescreen.unkB = autoDisplayMenu;
        gMain.subState = 3;
        sub_CBC();
        sub_FD5C(NULL);
    }
    else
    {
        gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        sub_CBC();
        sub_FD5C(sub_11640);
    }

    m4aSongNumStart(1);
}

void sub_10AC0(void)
{
    int i;

    gTitlescreen.animTimer = 0;
    gTitlescreen.unk2 = 0;
    gTitlescreen.unk6 = 0;
    gTitlescreen.unk8 = 0;
    gTitlescreen.unk10 = 4;
    gTitlescreen.unk9 = 1;
    gTitlescreen.unk11 = 0;
    gTitlescreen.unkA = 6;
    gTitlescreen.unkC = 0;
    gTitlescreen.unkE = 3;
    gTitlescreen.unkB = 0;
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
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
        gUnknown_020028A5 = 1;
    else
        gUnknown_020028A5 = 0;

    gUnknown_202BE24 = 0;
}

void TitleScreen1_WaitForStartButton(void)
{
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
    {
        if (!gUnknown_020028A5)
        {
            gUnknown_020028A4 = 1;
            gTitlescreen.unk6 = 9;
            gMain.subState = 11;
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

        if (gMain.heldKeys & KEYS_MASK)
            gTitlescreen.idleFramesCounter = 0;

        if (gMain.newKeys & (A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(0x65);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 0;
            gMain.subState = 2;
        }

        sub_114FC();
        sub_1157C();

        gTitlescreen.idleFramesCounter++;
        if (gTitlescreen.idleFramesCounter > NUM_IDLE_FRAMES)
        {
            if (gTitlescreen.idleFramesCounter % 10 == 0)
            {
                gTitlescreen.idleFadeoutCounter++;
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100 / gTitlescreen.idleFadeoutCounter);
            }

            if (gTitlescreen.idleFadeoutCounter > 9)
            {
                gTitlescreen.idleFramesCounter = 0;
                gTitlescreen.unk6 = 7;
                gMain.subState = 11;
            }
        }
    }

    sub_11640();
}

void TitleScreen2_Unknown(void)
{
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = 11;
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
                gTitlescreen.unk9 = 0;
                gTitlescreen.unkB = 1;
                gMain.subState = 3;
            }
        }
    }

    sub_11640();
}

void TitleScreen9_Unknown(void)
{
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
    }

    if (!gUnknown_020028A4)
    {
        if (gMain.newKeys & A_BUTTON)
        {
            m4aSongNumStart(0x65);
            sub_11B74();
            sub_2B4();
            m4aMPlayAllStop();
            sub_D10();
            gMain.subState = SUBSTATE_LOAD_GRAPHICS;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            m4aSongNumStart(0x66);
            gTitlescreen.unk11 = 0;
            gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
        }
    }

    sub_11640();
}

void TitleScreen3_Unknown(void)
{
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = 11;
    }

    if (!gUnknown_020028A4)
    {
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
}

void TitleScreen4_MenuInputNoSavedGame(void)
{
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
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

        if (gMain.newKeys & DPAD_UP)
        {
            m4aSongNumStart(0x67);
            if (--gTitlescreen.menuCursorIndex < 0)
                gTitlescreen.menuCursorIndex = 3;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            m4aSongNumStart(0x67);
            if (++gTitlescreen.menuCursorIndex > 3)
                gTitlescreen.menuCursorIndex = 0;
        }

        if (gMain.newKeys & (A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(0x65);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 0;
            gMain.subState = 7;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            m4aSongNumStart(0x66);
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

void TitleScreen7_Unknown(void)
{
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = 11;
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
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
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

        if (gMain.newKeys & DPAD_UP)
        {
            m4aSongNumStart(0x67);
            if (--gTitlescreen.menuCursorIndex < 0)
                gTitlescreen.menuCursorIndex = 4;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            m4aSongNumStart(0x67);
            if (++gTitlescreen.menuCursorIndex > 4)
                gTitlescreen.menuCursorIndex = 0;
        }

        if (gMain.newKeys & (A_BUTTON | START_BUTTON))
        {
            m4aSongNumStart(0x65);
            gTitlescreen.animTimer = 0;
            gTitlescreen.unk2 = 0;
            gMain.subState = 8;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            m4aSongNumStart(0x66);
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

void TitleScreen8_Unknown(void)
{
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = 11;
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
    if ((gMain.heldKeys & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
                       == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
    {
        gUnknown_020028A4 = 1;
        gTitlescreen.unk6 = 9;
        gMain.subState = 11;
    }

    if (!gUnknown_020028A4)
    {
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
                    gTitlescreen.unk9 = 1;
                    gTitlescreen.unkB = 0;
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
                    gTitlescreen.unk9 = 1;
                    gTitlescreen.unkB = 0;
                    gMain.subState = SUBSTATE_WAIT_FOR_START_BUTTON;
                }

                gUnknown_0202BE00[6] = gUnknown_086A9778[gTitlescreen.unk2];
            }

            sub_11968();
        }
    }
}

void TitleScreen10_ExecMenuSelection(void)
{
    if (!gTitlescreen.unk7)
        sub_FE04(sub_1175C);
    else
        sub_FE04(sub_11968);

    m4aMPlayAllStop();
    sub_D10();

    if (gUnknown_086A964C[gTitlescreen.unk6] == 8)
        gUnknown_0202C588 = 0;
    else
        gUnknown_0202C588 = 1;

    gAutoDisplayTitlescreenMenu = 0;
    SetMainGameState(gUnknown_086A964C[gTitlescreen.unk6]);
}

void TitleScreen11_Unknown(void)
{
    sub_FE04(sub_11640);
    m4aMPlayAllStop();
    sub_D10();
    gUnknown_0202C588 = 1;
    gAutoDisplayTitlescreenMenu = 0;
    SetMainGameState(gUnknown_086A964C[gTitlescreen.unk6]);
}

static void sub_114FC(void)
{
    // To delete save file, press R_BUTTON 3 times while holding L_BUTTON And DPAD_LEFT.
    if ((gMain.heldKeys & (L_BUTTON | DPAD_LEFT)) == (L_BUTTON | DPAD_LEFT))
    {
        if (gMain.newKeys & R_BUTTON)
        {
            gEraseSaveDataAccessCounter = 40;
            if (++gEraseSaveDataAccessStep == 3)
            {
                gEraseSaveDataAccessStep = 0;
                gEraseSaveDataAccessCounter = 0;
                m4aSongNumStart(0x68);
                gTitlescreen.unk11 = 1;
                gMain.subState = 9;
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
    if (gMain.heldKeys & DPAD_RIGHT && (gMain.newKeys & buttonMask) == buttonMask)
    {
        gEReaderAccessCounter = 40;
        gEReaderAccessStep++;
        if (gEReaderAccessButtonSequence[gEReaderAccessStep] == -1)
        {
            gEReaderAccessStep = 0;
            gEReaderAccessCounter = 0;
            m4aSongNumStart(0x65);
            gTitlescreen.unk6 = 5;
            if (gMain.subState == SUBSTATE_WAIT_FOR_START_BUTTON)
                gMain.subState = 11;
            else
                gMain.subState = SUBSTATE_EXEC_MENU_SELECTION;
        }
    }

    if (gMain.newKeys & (KEYS_MASK & ~buttonMask))
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
    struct SpriteGroup *group1 = &gTitlescreen.unk8[gUnknown_0200B3B8];
    struct SpriteGroup *group2 = &gTitlescreen.unk10[gUnknown_0200B3B8];

    group1->available = gTitlescreen.unk9;
    group2->available = gTitlescreen.unk11;

    LoadSpriteSets(gUnknown_086A96E4, 5, gUnknown_0200B3B8);

    if (group1->available == 1)
    {
        group1->baseX = 120;
        group1->baseY = 102;
        spriteSet = gUnknown_086A96E4[gTitlescreen.unk8];
        for (i = 0; i < spriteSet->count; i++)
        {
            gOamBuffer[group1->oam[i].oamId].x = group1->oam[i].xOffset + group1->baseX;
            gOamBuffer[group1->oam[i].oamId].y = group1->oam[i].yOffset + group1->baseY;

            asm("");  // needed to match
        }
    }

    if (group2->available == 1)
    {
        group2->baseX = 120;
        group2->baseY = 80;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[group2->oam[i].oamId].x = group2->oam[i].xOffset + group2->baseX;
            gOamBuffer[group2->oam[i].oamId].y = group2->oam[i].yOffset + group2->baseY;

            asm("");  // needed to match
        }
    }

    group1->available = 0;
    group2->available = 0;
}

struct UnknownStruct1
{
    u16 count;
    u8 filler2[6];
};

void sub_1175C(void)
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

    r10->available = gTitlescreen.unkB;
    r9->available = gTitlescreen.unkD;
    r8->available = gTitlescreen.unkF;

    LoadSpriteSets((const struct SpriteSet *const *)gUnknown_0201C190, 7, gMain.spriteGroups);

    if (r10->available == 1)
    {
        r10->baseX = 0x78;
        r10->baseY = 0x66;
        r12 = (const struct UnknownStruct1 *)gUnknown_0201C190[6];
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

    r10->available = 0;
    r9->available = 0;
    r8->available = 0;
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

    r10->available = gTitlescreen.unkB;
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

    r10->available = 0;
    r9->available = 0;
    r8->available = 0;
}

void sub_11B74(void)
{
    sub_52C64();
    SaveFile_WriteToSram();
    gMain.hasSavedGame = FALSE;
    WriteAndVerifySramFast((const u8 *)&gMain.hasSavedGame, (void *)0x0E000544, sizeof(gMain.hasSavedGame));
}
