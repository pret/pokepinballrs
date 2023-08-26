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

extern s16 gUnknown_0201A448;
extern s16 gUnknown_0202BF00;
extern s16 gUnknown_0202A57C;
extern s16 gUnknown_0201A4F0;
extern s16 gUnknown_0202BE20;
extern s16 gUnknown_0202C58C;
extern s8 gUnknown_02019C24;
extern s16 gUnknown_0202BF0C;
extern s16 gUnknown_0201A440;
extern s16 gUnknown_0202BEF4;
extern s16 gUnknown_0202A588;
extern s16 gUnknown_0202A55C;
extern s16 gUnknown_0202A568[2];
extern s16 gUnknown_0202C5E8;
extern s16 gUnknown_0202A558;
extern s8 gUnknown_0202BEE0;
extern s8 gUnknown_0202BF04;
extern s16 gUnknown_0202BF14;
extern s8 gUnknown_0202C590;
extern s16 gUnknown_0201B120;
extern s8 gUnknown_0202BEC4;
extern s8 gUnknown_0202BEFC;
extern s8 gUnknown_02002830;
extern s8 gUnknown_02002831;
extern s8 gUnknown_0202C794;
extern s8 gUnknown_0201C1B4;
extern s8 gUnknown_0202C5AC;
extern s8 gUnknown_02019C28;
extern s16 gUnknown_0202A1C0[];
extern s16 gUnknown_0202A390[];
extern s16 gUnknown_0202A574;

void sub_88E4(void);
s8 sub_FD20(void);

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

void sub_3FAC(void) {
    s32 i;
    
    gUnknown_0202ADE0 = 0;
    gUnknown_0202C5B0 = 0;
    gUnknown_0201A448 = 0;
    gUnknown_0202BF00 = 0;
    gUnknown_0202A57C = 0;
    gUnknown_0201A4F0 = 0;
    gUnknown_0202BE20 = 0;
    gUnknown_0202C58C = 0;
    gUnknown_02019C24 = 0;
    gUnknown_0202BF0C = 0;
    gUnknown_0201A440 = 0;
    gUnknown_0202C5E8 = 0;
    gUnknown_0202BEF4 = 0;
    gUnknown_0202A588 = 1;
    gUnknown_0202A55C = 1;
    
    gUnknown_0202A568[0] = 0;
    gUnknown_0202A568[1] = 0;
    
    gUnknown_0202BF14 = 0;
    gUnknown_0202A558 = 0;
    gUnknown_0202BEE0 = 0;
    gUnknown_0202BF04 = 1;

    sub_88E4();
    if (sub_FD20() == 1)
    {
        gUnknown_0202C590 = 1;
    }
    else
    {
        gUnknown_0202C590 = 0;
    }

    gUnknown_0202BEC4 = 0;
    gUnknown_0202BEFC = 0;
    gUnknown_0201B120 = 0;
    gUnknown_02002830 = 0;
    gUnknown_02002831 = 0;
    gUnknown_0202C794 = 0;
    gUnknown_0201C1B4 = 0;
    gUnknown_0202C5AC = 0;
    gUnknown_02019C28 = 0;

    for (i = 0; i < 0xE1; i++)
    {
        gUnknown_0202A390[i] = gUnknown_0202A1C0[i];
    }

    if (gUnknown_0202A1C0[SPECIES_AERODACTYL])
    {
        gUnknown_0202A574 = SPECIES_AERODACTYL + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_TOTODILE])
    {
        gUnknown_0202A574 = SPECIES_TOTODILE + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_CYNDAQUIL])
    {
        gUnknown_0202A574 = SPECIES_CYNDAQUIL + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_CHIKORITA])
    {
        gUnknown_0202A574 = SPECIES_CHIKORITA + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_JIRACHI])
    {
        gUnknown_0202A574 = SPECIES_JIRACHI + 1;
    }
    else
    {
        gUnknown_0202A574 = SPECIES_RAYQUAZA + 1;
    }
}
