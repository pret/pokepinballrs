#include "global.h"
#include "m4a.h"
#include "main.h"
#include "functions.h"

extern void (*const gUnknown_0805C750[])(void);
extern const u16 gUnknown_0807C2E0[];
extern const u8 gUnknown_0807C4E0[];
extern const u8 gUnknown_0807AAE0[];
extern const u8 gUnknown_0807B2E0[];
extern const u8 gUnknown_0807BAE0[];

void sub_2710(void);
void sub_29C8(void);

void BonusFieldSelectMain(void)
{
    gUnknown_0805C750[gMain.subState]();
}

void sub_25C4(void)
{
    ResetSomeGraphicsRelatedStuff();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(2) | BGCNT_PRIORITY(3) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;

    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gUnknown_0807C2E0, (void *)PLTT, 0x200);
    DmaCopy16(3, gFieldSelectWindow_Gfx, (void *)(VRAM + 0x4000), 0x4000);
    DmaCopy16(3, gUnknown_0807C4E0, (void *)(VRAM + 0x8000), 0x1800);
    DmaCopy16(3, gUnknown_0807AAE0, (void *)VRAM, 0x800);
    DmaCopy16(3, gUnknown_0807B2E0, (void *)(VRAM + 0x800), 0x800);
    DmaCopy16(3, gUnknown_0807BAE0, (void *)(VRAM + 0x1000), 0x800);
    DmaCopy16(3, gFieldSelectSpritePals, (void *)(PLTT + 0x200), 0x60);
    DmaCopy16(3, gFieldSelectSpriteGfx, (void *)(VRAM + 0x10000), 0x4020);

    sub_CBC();
    sub_2710();
    sub_FD5C(sub_29C8);
    m4aSongNumStart(0x3);

    gMain.subState++;
}
