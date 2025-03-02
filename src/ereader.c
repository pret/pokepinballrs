#include "global.h"
#include "constants/bg_music.h"
#include "constants/ereader.h"
#include "functions.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "titlescreen.h"
#include "variables.h"

extern StateFunc gEReaderStateFuncs[11];
extern s8 gUnknown_0202C604;
extern s8 gUnknown_0202A580;
extern s8 gUnknown_0202C5A4;
extern s8 gUnknown_0202AD90;

extern s8 gUnknown_0202A58C;
extern s8 gUnknown_0202C584;
extern s8 gUnknown_0202BEC0;
extern s8 gUnknown_0201B174;
extern s16 gUnknown_0202C5A0;
extern s16 gUnknown_0201A44C;
extern u8 gUnknown_0200282C;
extern u8 gUnknown_0200282D;
extern s8 gUnknown_0202BEF8;
extern u8 gUnknown_0201B124;
extern u32 gUnknown_0202ADD0;
extern s16 gUnknown_0202C5F0[];
extern u16 gUnknown_0201A4D0[][2];
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
extern u16 gUnknown_03000000[];
extern u8 gUnknown_08080500[];
extern u8 gUnknown_080897E0[];
extern u8 gUnknown_0807FD00[];
extern s16 gUnknown_086A550C[];

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

    gMain.bgOffsets[0].xOffset = 0xffe8;
    gMain.bgOffsets[0].yOffset = (0xffe8 - 0x48);
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
    m4aSongNumStart(MUS_UNKNOWN_0x5);
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
    if (JOY_NEW(A_BUTTON)) {
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
    else if (JOY_NEW(B_BUTTON)) {
        m4aSongNumStart(SE_UNKNOWN_0x66);
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
            m4aSongNumStart(SE_UNKNOWN_0x76);
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
    if (JOY_NEW(B_BUTTON)) {
        sub_2568();
        DisableSerial();
        sub_02B4();
        m4aMPlayAllStop();
        sub_0D10();
        gMain.subState = 0;
    }
    gUnknown_0202ADD0 = LinkMain1(&gUnknown_0202BEC8, gUnknown_0202C5F0, gUnknown_0201A4D0);
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
                    gMain.eReaderBonuses[index] = 0;
                }
                gMain.eReaderBonuses[gEReaderCardIndex] = 1;
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
                m4aSongNumStart(SE_FAILURE);
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
                m4aSongNumStart(SE_FAILURE);
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
    if (JOY_NEW(A_BUTTON)) {
        if (gUnknown_0202C604 <= gUnknown_086A551A[gUnknown_0202AD90]) {
            sub_37B4(gUnknown_0202AD90);
            gUnknown_0202C604 = gUnknown_086A551A[gUnknown_0202AD90] + 1;
        }
        else if (gUnknown_086A5528[gUnknown_0202AD90] == 0) {
            sub_2568();
            DisableSerial();
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
            DisableSerial();
            break;
        case 0x96:
            gUnknown_0202A58C = 3;
            m4aSongNumStart(SE_UNKNOWN_0x65);
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

    gMain.bgOffsets[0].xOffset = 0xffe8;
    gMain.bgOffsets[0].yOffset = (0xffe8 - 0x48);
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
    m4aSongNumStart(MUS_UNKNOWN_0x5);
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
    if (JOY_NEW(A_BUTTON)) {
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
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(gUnknown_0202BEF8);
}

void sub_377C(void)
{
    s32 iVar2;
    s32 iVar4;

    for(iVar2 = 0; iVar2 < 3; iVar2++)
    {
        for(iVar4 = 0; iVar4 < 0x18; iVar4++)
        {
            sub_10708(gUnknown_080ACC60, &gUnknown_03001800[iVar2][iVar4*0x20], 1, 2);
        }
    }
}

void sub_37B4(s8 arg0)
{
    s32 iVar4;
    s32 iVar3;

    for (iVar4 = 0; iVar4 < 3; iVar4++)
    {
        for (iVar3 = 0; iVar3 < 0x18; iVar3++)
        {
            sub_10708(gUnknown_080ACC60 + (gUnknown_086A4CF8[arg0][iVar4*0x18 + iVar3] & 0xFFF0), &gUnknown_03001800[iVar4][iVar3*0x20], 1, 2);
        }
    }
}

void sub_3828(s8 arg0, s8 arg1)
{
    s32 quotient = arg1 / 0x18;
    s32 remainder = arg1 % 0x18;

    sub_10708(gUnknown_080ACC60 + (gUnknown_086A4CF8[arg0][quotient*0x18 + remainder] & 0xFFF0), &gUnknown_03001800[quotient][remainder*0x20], 1, 2);
}

void sub_38A0(s8 arg0, u16 arg1)
{
    s32 quotient = arg0 / 0x18;
    s32 remainder = arg0 % 0x18;

    sub_10708(gUnknown_080ACC60 + arg1, &gUnknown_03001800[quotient][remainder*0x20], 1, 2);
}

s16 GetEReaderCardIndex(void)
{
    s32 uVar1;

    if (gUnknown_0202BEEC == 0x1f52)
    {
        return 0;
    }
    else if (gUnknown_0202BEEC == 0x3e1a)
    {
        return 1;
    }
    else if (gUnknown_0202BEEC == 0x25af)
    {
        return 2;
    }
    else if (gUnknown_0202BEEC == 0x4a09)
    {
        return 3;
    }
    else if (gUnknown_0202BEEC == 0x6b12)
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

void sub_394C(void)
{
    struct SpriteGroup *puVar9;
    struct SpriteGroup *puVar5;
    s32 iVar7;
    const struct SpriteSet *puVar8;
    struct OamDataSimple *test2;

    puVar9 = &gUnknown_0200B3B8[gUnknown_0202A58C];
    puVar5 = &gUnknown_0200B3B8[gUnknown_0202BEC0];
    puVar9->available = gUnknown_0202C584;
    puVar5->available = TRUE;
    LoadSpriteSets(gUnknown_086A54D8, 13, gUnknown_0200B3B8);

    if (puVar9->available == 1)
    {
        if (gUnknown_0202A58C == 0)
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 100;
        }
        else
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 0x50;
        }

        puVar8 = gUnknown_086A54D8[gUnknown_0202A58C];

        for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
        {
            test2 = &puVar9->oam[iVar7];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar9->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar9->baseY;
        }
    }

    puVar5->baseX = 0x78;
    puVar5->baseY = 0x18;
    puVar8 = gUnknown_086A54D8[gUnknown_0202BEC0];

    for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
    {
        test2 = &puVar5->oam[iVar7];
        gOamBuffer[test2->oamId].x = test2->xOffset + puVar5->baseX;
        gOamBuffer[test2->oamId].y = test2->yOffset + puVar5->baseY;
    }

    puVar9->available = FALSE;
    puVar5->available = FALSE;
}

void sub_3AB4(void) {
    struct SpriteGroup *puVar9;
    struct SpriteGroup *puVar5;
    s32 iVar7;
    const struct SpriteSet *puVar8;
    struct OamDataSimple *test2;

    puVar9 = &gUnknown_0200B3B8[gUnknown_0202A58C];
    puVar5 = &gUnknown_0200B3B8[gUnknown_0202BEC0];
    puVar9->available = gUnknown_0202C584;
    puVar5->available = TRUE;
    sub_2414(gUnknown_086A54D8, 13, gUnknown_0200B3B8);

    if (puVar9->available == 1)
    {
        if (gUnknown_0202A58C == 0)
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 100;
        }
        else
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 0x50;
        }

        puVar8 = gUnknown_086A54D8[gUnknown_0202A58C];

        for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
        {
            test2 = &puVar9->oam[iVar7];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar9->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar9->baseY;
        }
    }

    puVar5->baseX = 0x78;
    puVar5->baseY = 0x18;
    puVar8 = gUnknown_086A54D8[gUnknown_0202BEC0];

    for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
    {
        test2 = &puVar5->oam[iVar7];
        gOamBuffer[test2->oamId].x = test2->xOffset + puVar5->baseX;
        gOamBuffer[test2->oamId].y = test2->yOffset + puVar5->baseY;
    }

    puVar9->available = FALSE;
    puVar5->available = FALSE;
}

void sub_3C1C(void)
{
    s32 i;
    s32 j;

    gUnknown_0202A564 = 0;
    gUnknown_02019C20 = 0;
    gUnknown_0202ADE8 = 0;

    for (i = 0; i < 0x8; i++)
    {
        gUnknown_0202C5F0[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 8; j++)
        {
            gUnknown_0201A4D0[j][i] = 0;
        }
    }
}

s32 sub_3C78(void)
{
    s32 i;

    if (gUnknown_02019C20)
    {
        gUnknown_0202C5F0[0] = 0xDFDF;
    }
    else
    {
        if (gUnknown_0202ADE8 == -1)
        {
            gUnknown_0202C5F0[0] = 0xCDFE;
            gUnknown_0202ADE8 = 0;
        }
        else
        {
            for (i = 0; i < 8; i++)
            {
                gUnknown_0202C5F0[i] = 0;
            }
        }
    }

    return 0;
}

s16 sub_3CD8(void)
{
    s32 i;
    s32 j;

    if (!(JOY_NEW(A_BUTTON)))
    {
        // TODO I can buy goto end being the actual label, but there is no way they wrote this segment like this
        goto fakematch;
    }
    if (gUnknown_0202A564 == 0)
    {
        gUnknown_0202A564 = -1;
        gUnknown_0202ADE8 = -1;
        gUnknown_0202A58C = 1;

        fakematch:
        if (gUnknown_0202A564 == 0) {
            goto end;
        }
    }

    if (gUnknown_02019C20 == 0)
    {
        if (gUnknown_0201A4D0[0][0] == 0xFEDC)
        {
            gUnknown_0202BEEC = gUnknown_0201A4D0[1][0];
            gUnknown_02019C20 = -1;
        }
        else if (gUnknown_0201A4D0[0][1] == 0xFEDC)
        {
            gUnknown_0202BEEC = gUnknown_0201A4D0[1][1];
            gUnknown_02019C20 = -1;
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            if (gUnknown_0201A4D0[0][i] == 0xDFDF)
            {
                return -1;
            }
        }
    }

    end:
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 8; j++)
        {
            gUnknown_0201A4D0[j][i] = 0;
        }
    }
    return 0;
}

