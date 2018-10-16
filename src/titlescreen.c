#include "global.h"
#include "titlescreen.h"
#include "m4a.h"
#include "main.h"

extern StateFunc gTitlescreenStateFuncs[];
extern const u8 gTitlescreenBg_Gfx[];
extern const u16 gTitlescreenBg_Pals[];
extern const u8 gTitlescreenBgTilemap[];
extern const u16 gTitlescreenSprites_Pals[];
extern const u8 gTitlescreenSpritesSavedGame_Gfx[];
extern const u8 gTitlescreenSpritesNoSavedGame_Gfx[];
extern const u8 gGBAButtonIcons_Pals[];
extern const u8 gOptionsSprites_Gfx[];

extern void sub_438(void);
extern void sub_CBC(void);
extern void sub_FD5C(void (*func)(void));
extern void sub_11640(void);
extern void sub_52C44(void);

extern void sub_10AC0(void);


void TitlescreenMain(void)
{
    gTitlescreenStateFuncs[gMain.subState]();
}

void LoadTitlescreenGraphics(void)
{
    int autoDisplayMenu;

    sub_438();
    REG_DISPCNT = DISPCNT_OBJ_ON| DISPCNT_FORCED_BLANK;
    REG_BG1CNT = BGCNT_256COLOR | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gTitlescreenBg_Gfx, (void *)BG_CHAR_ADDR(1), 0xA000);
    DmaCopy16(3, gTitlescreenBg_Pals, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gTitlescreenBgTilemap, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);

    sub_52C44();
    if (gMain.unk40 == 1)
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
        gUnknown_2002888.unk9 = 0;
        gUnknown_2002888.unkB = autoDisplayMenu;
        gMain.subState = 3;
        sub_CBC();
        sub_FD5C(NULL);
    }
    else
    {
        gMain.subState = 1;
        sub_CBC();
        sub_FD5C(sub_11640);
    }

    m4aSongNumStart(1);
}
