#include "global.h"
#include "constants/bg_music.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"

extern u16 gUnknown_02019C40[];
extern s16 gUnknown_0201A514;
extern s16 gUnknown_0202ADE0;
extern s16 gUnknown_0202BEB8;
extern s16 gUnknown_0202C5B0;

extern StateFunc gPokedexStateFuncs[];
extern u16 gUnknown_08081F20[];
extern u16 gUnknown_08082720[];
extern u16 gUnknown_08087340[];
extern u16 gUnknown_08087B40[];
extern u16 gUnknown_08088F60[];
extern u16 gUnknown_08089760[];
extern u16 gUnknown_08089960[];
extern u16 gUnknown_08089B60[];

void PokedexMain(void)
{
    gPokedexStateFuncs[gMain.subState]();
}

void LoadPokedexGraphics(void)
{
    ResetSomeGraphicsRelatedStuff();
    
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    REG_BG1CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(0) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG3_ON;
    
    gMain.unk16 = REG_DISPCNT;
    
    DmaCopy16(3, gUnknown_08082720, (void *)BG_CHAR_ADDR(1), 0x4400);
    DmaCopy16(3, gUnknown_08087B40, (void *)BG_CHAR_ADDR(3), 0x1400);
    DmaCopy16(3, gUnknown_08089760, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gUnknown_08081F20, gUnknown_03005C00, BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08087340, gUnknown_02019C40, BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08088F60, (void *)BG_SCREEN_ADDR(2), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08089960, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gUnknown_08089B60, (void *)OBJ_VRAM0, 0x6C20);
    
    sub_3FAC();
    sub_6BEC(gUnknown_0202BEB8, gUnknown_0201A514);
    sub_681C(gUnknown_0202ADE0);
    sub_6CA0(gUnknown_0202C5B0);
    sub_6F30(gUnknown_0202C5B0);
    sub_6F78(gUnknown_0202ADE0);
    sub_8974(gUnknown_0202ADE0);
    sub_8A78(gUnknown_0202ADE0);
    
    gUnknown_02019C40[0x134] = 0x59;
    
    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_02019C40, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    
    sub_51FC();
    sub_0CBC();
    sub_024C();
    
    // Must be `= 1` to match, cannot be `++`
    gMain.subState = 1;
    
    m4aSongNumStart(MUS_POKEDEX);
}
