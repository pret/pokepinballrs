#include "global.h"
#include "constants/bg_music.h"
#include "constants/ereader.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "titlescreen.h"

extern StateFunc gEReaderStateFuncs[11];
extern s8 gUnknown_0202C604;
extern s8 gUnknown_0202A580;
extern s8 gUnknown_0202C5A4;
extern s8 gUnknown_0202AD90;

extern s8 gUnknown_0202A58C;
extern u8 gUnknown_0202C584;
extern u8 gUnknown_0202BEC0;
extern s8 gUnknown_0201B174;
extern s16 gUnknown_0202C5A0;
extern s16 gUnknown_0201A44C;
extern u8 gUnknown_0200282C;
extern u8 gUnknown_0200282D;
extern s8 gUnknown_0202BEF8;
extern u8 gUnknown_0201B124;
extern u32 gUnknown_0202ADD0;
extern u32 gUnknown_0202BEC8;
extern u32 gUnknown_0202C5F0;
extern u32 gUnknown_0201A4D0;
extern u32 gUnknown_0202BDF0;
extern u8 gUnknown_0201C1AC;
extern u8 gUnknown_0202ADDC;
extern s16 gEReaderCardIndex;
extern s16 gUnknown_0201A444;

extern s8 gUnknown_086A551A[10];
extern s8 gUnknown_086A5528[10];
extern u8 gUnknown_086A5536[NUM_EREADER_CARDS + 1];
extern u8 gUnknown_08089B60[];
extern u8 gUnknown_08081D20[];
extern u8 gUnknown_0807DD00[];
extern u8 gUnknown_0807D000[];
extern u8 gUnknown_08089960[];
extern u8 gUnknown_08089B60[];
extern u8 gUnknown_03000000[];
extern u8 gUnknown_08080500[];
extern u8 gUnknown_080897E0[];
extern u8 gUnknown_0807FD00[];
extern s16 gUnknown_086A550C[];

s32 sub_1B04(u32 *, u32 *, u32 *);

void EReaderMain(void)
{
    gEReaderStateFuncs[gMain.subState]();
}

void LoadEReaderGraphics(void)
{
    ResetSomeGraphicsRelatedStuff();
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK;
    REG_BG0CNT = BGCNT_CHARBASE(1);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;

    gMain.unk2E8[0].unk0 = 0xffe8;
    gMain.unk2E8[0].unk2 = (0xffe8 - 0x48);
    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gUnknown_08081D20,   (void*) PLTT,              0x40);
    DmaCopy16(3, gUnknown_080897E0,   (void*) PLTT + 0x40,       0x20);
    DmaCopy16(3, gUnknown_08080500,   gUnknown_03000000,         0x3000);
    DmaCopy16(3, gUnknown_0807DD00,   (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_0807FD00,   (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08089960,   (void *)OBJ_PLTT,          0xC0);
    DmaCopy16(3, gUnknown_08089B60,   (void *)OBJ_VRAM0,         0x6C20);

    sub_2DF0();
    gUnknown_0202C604 = 0;
    gUnknown_0202A580 = 0;
    gUnknown_0202C5A4 = 0;
    gUnknown_0202AD90 = 0;
    sub_377C();

    DmaCopy16(3, gUnknown_03000000, (void *)VRAM + 0x4000, 0x3000);

    sub_394C();
    m4aSongNumStart(MUS_UNKNOWN_SONG_1);
    sub_0CBC();
    sub_024C();
    gMain.subState = 1;
}

void sub_2DF0(void)
{
    gUnknown_0202A58C = 0;
    gUnknown_0202C584 = 0;
    gUnknown_0202BEC0 = 4;
    gUnknown_0201B174 = 0;
    gUnknown_0202C5A0 = 0;
    gUnknown_0201A44C = 0;
    gUnknown_0202BEF8 = STATE_INTRO;
    gUnknown_0200282C = 0;
    gUnknown_0200282D = 0;
}

void sub_2E40(void)
{
    if (gUnknown_0202C604 <= gUnknown_086A551A[gUnknown_0202AD90]) {
        gUnknown_0202A580++;
        if (2 < gUnknown_0202A580) {
            gUnknown_0202A580 = 0;
            sub_3828(gUnknown_0202AD90,gUnknown_0202C604);
            gUnknown_0202C604++;
        }
    }
    else {
        gUnknown_0202A580++;
        if (6 < gUnknown_0202A580) {
            gUnknown_0202A580 = 0;
            if (gUnknown_0202C5A4 == 0) {
                sub_38A0(gUnknown_086A551A[gUnknown_0202AD90],0x3a80);
            }
            else {
                sub_38A0(gUnknown_086A551A[gUnknown_0202AD90],0);
            }
            gUnknown_0202C5A4 = 1 - gUnknown_0202C5A4;
        }
    }
    if (gMain.newKeys & A_BUTTON) {
        if (gUnknown_0202C604 <= gUnknown_086A551A[gUnknown_0202AD90]) {
            sub_37B4(gUnknown_0202AD90);
            gUnknown_0202C604 = gUnknown_086A551A[gUnknown_0202AD90] + 1;
        }
        else if (gUnknown_086A5528[gUnknown_0202AD90] == 0) {
            gMain.subState = 2;
        }
        else {
            sub_377C();
            gUnknown_0202C604 = 0;
            gUnknown_0202A580 = 0;
            gUnknown_0202C5A4 = 0;
            gUnknown_0202AD90++;
        }
    }
    else if (gMain.newKeys & B_BUTTON) {
        m4aSongNumStart(0x66);
        gUnknown_0202BEF8 = STATE_TITLE;
        gMain.subState = 8;
    }
    sub_394C();
    DmaCopy16(3, gUnknown_03000000, (void*) VRAM + 0x4000, 0x3000);
}

void sub_2FC0(void)
{
    gUnknown_0202C5A0++;
    if (gUnknown_0202C5A0 > gUnknown_086A550C[gUnknown_0201B174]) {
        gUnknown_0202C5A0 = 0;
        gUnknown_0201B174++;
        if (gUnknown_0201B174 == 6) {
            sub_19B4();
            sub_3C1C();
            gUnknown_0201B124 = 0;
            gUnknown_0202C584 = 1;
            m4aSongNumStart(0x76);
            gMain.subState = 3;
        }
    }
    gUnknown_0202A58C = 0;
    gUnknown_0202BEC0 = gUnknown_0201B174 + 4;
    sub_3AB4();
}

void sub_304C(void)
{
    s32 index;
    u16 temp;

    sub_3AB4();
    if (gMain.newKeys & B_BUTTON) {
        sub_2568();
        sub_1AA4();
        sub_02B4();
        m4aMPlayAllStop();
        sub_0D10();
        gMain.subState = 0;
    }
    gUnknown_0202ADD0 = sub_1B04(&gUnknown_0202BEC8, &gUnknown_0202C5F0, &gUnknown_0201A4D0);
    gUnknown_0202BDF0 = gUnknown_0202ADD0 & 3;
    gUnknown_0201C1AC = ((gUnknown_0202ADD0 & 0x1c) >> 2);
    gUnknown_0202ADDC = ((gUnknown_0202ADD0 & 0xe00) >> 9);
    if (((gUnknown_0202ADD0 & 0x40) != 0) && (gUnknown_0202BDF0 < 2)) {
        sub_3C78();
        if (((gUnknown_0202ADD0 & 0x100) == 0) && (sub_3CD8() == -1)) {
            gEReaderCardIndex = GetEReaderCardIndex();
            if ((gEReaderCardIndex != -1) && (NUM_EREADER_CARDS > gEReaderCardIndex)) {
                for(index = 0; index < NUM_EREADER_CARDS; index++)
                {
                    gMain.eReaderBonus[index] = 0;
                }
                gMain.eReaderBonus[gEReaderCardIndex] = 1;
                gUnknown_0201A44C = 0;
                gMain.subState = 5;
            }
            else {
                gUnknown_0201A44C = 0;
                gUnknown_0202A58C = 2;
                gUnknown_0202BEC0 = 10;
                gUnknown_0202C604 = 0;
                gUnknown_0202C5A4 = 0;
                gUnknown_0202AD90 = 13;
                sub_377C();
                gMain.subState = 4;
                m4aSongNumStart(0x8a);
            }
        }
        if (gUnknown_0202A58C == 1) {
            gUnknown_0201A44C++;
            temp = gUnknown_0201A44C; // TODO: FAKEMATCH
            if ((gUnknown_0201A44C & 7) == 0) {
                gUnknown_0202BEC0 = 21 - gUnknown_0202BEC0;
            }
            if (((gUnknown_0202ADD0 & 0x7f0000) != 0) &&
                (gUnknown_0201A444++, 0xb4 < gUnknown_0201A444)) {
                gUnknown_0201A44C = 0;
                gUnknown_0202A58C = 2;
                gUnknown_0202BEC0 = 10;
                gUnknown_0202C604 = 0;
                gUnknown_0202C5A4 = 0;
                gUnknown_0202AD90 = 13;
                sub_377C();
                gMain.subState = 4;
                m4aSongNumStart(0x8a);
            }
        }
    }
}

void sub_3208(void)
{ 
    gUnknown_0201A44C++;
    if (8 < gUnknown_0201A44C) {
        gUnknown_0201A44C = 0;
        gUnknown_0202BEC0 = 22 - gUnknown_0202BEC0;
    }
    if (gUnknown_0202C604 <= gUnknown_086A551A[gUnknown_0202AD90]) {
        gUnknown_0202A580++;
        if (2 < gUnknown_0202A580) {
            gUnknown_0202A580 = 0;
            sub_3828(gUnknown_0202AD90,gUnknown_0202C604);
            gUnknown_0202C604++;
        }
    }
    else {
        gUnknown_0202A580++;
        if (6 < gUnknown_0202A580) {
            gUnknown_0202A580 = 0;
            if (gUnknown_0202C5A4 == 0) {
                sub_38A0(gUnknown_086A551A[gUnknown_0202AD90],0x3a80);
            }
            else {
                sub_38A0(gUnknown_086A551A[gUnknown_0202AD90],0);
            }
            gUnknown_0202C5A4 = 1 - gUnknown_0202C5A4;
        }
    }
    if (gMain.newKeys & A_BUTTON) {
        if (gUnknown_0202C604 <= gUnknown_086A551A[gUnknown_0202AD90]) {
            sub_37B4(gUnknown_0202AD90);
            gUnknown_0202C604 = gUnknown_086A551A[gUnknown_0202AD90] + 1;
        }
        else if (gUnknown_086A5528[gUnknown_0202AD90] == 0) {
            sub_2568();
            sub_1AA4();
            sub_02B4();
            m4aMPlayAllStop();
            sub_0D10();
            gMain.subState = 0;
        }
        else {
            sub_377C();
            gUnknown_0202C604 = 0;
            gUnknown_0202A580 = 0;
            gUnknown_0202C5A4 = 0;
            gUnknown_0202AD90++;
        }
    }
    sub_394C();
    DmaCopy16(3, gUnknown_03000000, (void*) VRAM + 0x4000, 0x3000);
}

void sub_33A0(void)
{
    u16 temp;
    sub_3AB4();

    switch(gUnknown_0201A44C)
    {
        case 4:
            sub_2568();
            sub_1AA4();
            break;
        case 0x96:
            gUnknown_0202A58C = 3;
            m4aSongNumStart(0x65);
            break;
        case 0x10e:
            gUnknown_0201A44C = 0;
            sub_02B4();
            m4aMPlayAllStop();
            sub_0D10();
            gMain.subState = 6;
            break;
    }

    if ((gUnknown_0202A58C == 1) && ((temp = gUnknown_0201A44C, gUnknown_0201A44C & 7) == 0)) {
        gUnknown_0202BEC0 = 21 - gUnknown_0202BEC0;
    }
    gUnknown_0201A44C++;
}

void sub_343C(void)
{
    ResetSomeGraphicsRelatedStuff();
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK;
    REG_BG0CNT = BGCNT_CHARBASE(1);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;

    gMain.unk2E8[0].unk0 = 0xffe8;
    gMain.unk2E8[0].unk2 = (0xffe8 - 0x48);
    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gUnknown_08081D20,   (void*) PLTT,              0x40);
    DmaCopy16(3, gUnknown_080897E0,   (void*) PLTT + 0x40,       0x20);
    DmaCopy16(3, gUnknown_08080500,   gUnknown_03000000,         0x3000);
    DmaCopy16(3, gUnknown_0807DD00,   (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_0807FD00,   (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08089960,   (void *)OBJ_PLTT,          0xC0);
    DmaCopy16(3, gUnknown_08089B60,   (void *)OBJ_VRAM0,         0x6C20);

    sub_2DF0();
    gUnknown_0202C604 = 0;
    gUnknown_0202A580 = 0;
    gUnknown_0202C5A4 = 0;
    gUnknown_0202AD90 = gUnknown_086A5536[gEReaderCardIndex];
    sub_377C();

    DmaCopy16(3, gUnknown_03000000, (void *)VRAM + 0x4000, 0x3000);

    sub_394C();
    m4aSongNumStart(MUS_UNKNOWN_SONG_1);
    sub_0CBC();
    sub_024C();
    gMain.subState = 7;
}

void sub_35C8(void)
{
    if (gUnknown_0202C604 <= gUnknown_086A551A[gUnknown_0202AD90]) {
        gUnknown_0202A580++;
        if (2 < gUnknown_0202A580) {
            gUnknown_0202A580 = 0;
            sub_3828(gUnknown_0202AD90, gUnknown_0202C604);
            gUnknown_0202C604++;
        }
    }
    else {
        gUnknown_0202A580++;
        if (6 < gUnknown_0202A580) {
            gUnknown_0202A580 = 0;
            if (gUnknown_0202C5A4 == 0) {
                sub_38A0(gUnknown_086A551A[gUnknown_0202AD90], 0x3a80);
            }
            else {
                sub_38A0(gUnknown_086A551A[gUnknown_0202AD90], 0);
            }
            gUnknown_0202C5A4 = 1 - gUnknown_0202C5A4;
        }
    }
    if (gMain.newKeys & A_BUTTON) {
        if (gUnknown_0202C604 <= gUnknown_086A551A[gUnknown_0202AD90]) {
            sub_37B4(gUnknown_0202AD90);
            gUnknown_0202C604 = gUnknown_086A551A[gUnknown_0202AD90] + 1;
        }
        else if (gUnknown_086A5528[gUnknown_0202AD90] == 0) {
            if (gEReaderCardIndex == EREADER_BONUS_STAGE_CARD) {
                gUnknown_0202BEF8 = STATE_BONUS_FIELD_SELECT;
            }
            else {
                gUnknown_0202BEF8 = STATE_TITLE;
            }
            gMain.subState = 8;
        }
        else {
            sub_377C();
            gUnknown_0202C604 = 0;
            gUnknown_0202A580 = 0;
            gUnknown_0202C5A4 = 0;
            gUnknown_0202AD90++;
        }
    }
    sub_394C();
    DmaCopy16(3, gUnknown_03000000, (void*) VRAM + 0x4000, 0x3000);
}

void sub_374C(void)
{
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    gAutoDisplayTitlescreenMenu = 1;
    SetMainGameState(gUnknown_0202BEF8);
}
