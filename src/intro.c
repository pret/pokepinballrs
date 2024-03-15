#include "global.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"
#include "titlescreen.h"

extern void sub_10170(u8 *, u32, u32, u32);
void sub_FEB8(u32, u8 *, u32);
void sub_A628(void);
void sub_A87C(void);
void sub_AAA8(void);
void sub_ADFC(void);
extern void sub_B0E8(void);
void sub_B4A0(void);

extern StateFunc gIntroStateFuncs[15];
extern u8 gUnknown_080798C0[];

extern u8 gIntroCopyright_Gfx[];
extern u8 gIntroCopyright_Pal[];
extern u8 gIntroScene1Sprites_Gfx[];
extern u8 gIntroScene1Sprites_Pals[];

extern u8 gUnknown_080B9CC0[];
extern u8 gUnknown_080BC4C0[];
extern u8 gUnknown_080BB4C0[];
extern u8 gUnknown_080B3CA0[];
extern u8 gUnknown_080B44A0[];
extern u8 gUnknown_080BD4C0[];
extern s16 gUnknown_086A7788[0x8];

extern u16 gUnknown_0201C1C0[];
extern s16 gUnknown_0202ADA0[];
extern s16 gUnknown_0202BF10;
extern u8 gUnknown_0201C1B8;
extern u8 gUnknown_0202ADD4;
extern s16 gUnknown_0202C594;
extern s32 gUnknown_02019C30;
extern s32 gUnknown_0201C188;
extern s16 gUnknown_0202A578;
extern s32 gUnknown_0202BEF0;
extern s8 gUnknown_0202C5A8;
extern s8 gUnknown_0202C790;
extern u8 gUnknown_0202BE70[];

extern u8 gUnknown_080CBEE0[];
extern u8 gUnknown_080CC6E0[];
extern u8 gUnknown_080CBCE0[];
extern u8 gUnknown_080D0700[];
extern u8 gUnknown_080D2700[];

extern u8 gUnknown_0201B180[];

extern u8 gUnknown_080D4700[];
extern u8 gUnknown_080DE520[];
extern u8 gUnknown_080DCD20[];
extern u8 gUnknown_080D4900[];
extern u8 gUnknown_080D5900[];
extern u8 gUnknown_080D6100[];
extern u8 gUnknown_080DD520[];
extern u8 gUnknown_080DDD20[];
extern u8 gUnknown_080DF520[];

typedef void (*OtherFunc)(void);
extern OtherFunc gUnknown_080792E0[10];

struct unkStruct_0201A450
{
    u16 unk0;
    u16 unk2;
    u8 fill4[0x8 - 0x4];
    s16 unk8;
    s16 unkA;
    s8 unkC;
};

extern struct unkStruct_0201A450 gUnknown_0201A450[6];

struct UnkStruct_086A7768 {
    s16 unk0;
    s16 unk2;
};

extern struct UnkStruct_086A7768 gUnknown_086A7768[0x8];
extern struct UnkStruct_086A7768 gUnknown_086A7798[0x4];
extern struct UnkStruct_086A7768 gUnknown_086A79FC[];

void IntroMain(void) {
     gIntroStateFuncs[gMain.subState]();
}

void sub_929C(void) {
  ResetSomeGraphicsRelatedStuff();
  REG_DISPCNT = 0x80;
  REG_BG1CNT = 5;
  REG_DISPCNT |= DISPCNT_BG1_ON;

  DmaCopy16(3, gUnknown_080798C0, BG_CHAR_ADDR(0), BG_SCREEN_SIZE);
  DmaCopy16(3, gIntroCopyright_Gfx, BG_CHAR_ADDR(1), BG_SCREEN_SIZE);
  DmaCopy16(3, gIntroCopyright_Pal, BG_PLTT, BG_PLTT_SIZE);

  gMain.unk16 = REG_DISPCNT;
  gUnknown_0202BF10 = 0;
  gUnknown_0202C790 = 0;

  SetMainCallback(sub_93F8 + 1);
  sub_0CBC();
  sub_024C();
  gMain.subState++;
}

void sub_9348(void) {
    gUnknown_0202BF10++;
    if(gUnknown_0202BF10 > 0x78)
    {
        gUnknown_0202BF10 = 0;
        gMain.subState++;
    }
}

void sub_9370(void) {
    sub_FF74(NULL);
    sub_0D10();
    gMain.subState++;
}

void sub_938C(void) {
    gUnknown_080792E0[gUnknown_0202C790]();
    gUnknown_0202BF10++;
    if(gMain.newKeys & (A_BUTTON | START_BUTTON))
        gMain.subState = 4;
}

void sub_93D0(void) {
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    ResetMainCallback();
    gAutoDisplayTitlescreenMenu = 0;
    SetMainGameState(STATE_TITLE);
}

void sub_93F8(void) {
    if(REG_DISPSTAT & DISPSTAT_VBLANK_INTR)
    {
        m4aSoundMain();
        VBlankIntrWait();
        DmaCopy16(3, gOamBuffer , OAM, 0x8000200);
        REG_DISPCNT = gMain.unk16;
        REG_BG0HOFS = gMain.unk2E8[0].unk0;
        REG_BG0VOFS = gMain.unk2E8[0].unk2;
        REG_BG1HOFS = gMain.unk2E8[1].unk0;
        REG_BG1VOFS = gMain.unk2E8[1].unk2;
        REG_BG2HOFS = gMain.unk2E8[2].unk0;
        REG_BG2VOFS = gMain.unk2E8[2].unk2;
        REG_BG3HOFS = gMain.unk2E8[3].unk0;
        REG_BG3VOFS = gMain.unk2E8[3].unk2;
    }
}

void sub_9498(void) {
    ClearGraphicsMemory();
    sub_0518();
    ClearSprites();

    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = 0xD0 << 5;
    REG_DISPCNT |= (DISPCNT_BG0_ON);
    REG_BG1CNT = 0x5B01;
    REG_DISPCNT |= (DISPCNT_BG1_ON);
    REG_BG2CNT = 0x5d02;
    REG_DISPCNT |= (DISPCNT_BG2_ON);
    REG_BG3CNT = 0x1f03;
    REG_DISPCNT |= (DISPCNT_BG3_ON);
    
    DmaCopy16(3, gUnknown_080B9CC0, 0x0600d000, BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_080BC4C0, 0x0600d800, 0x1000);
    DmaCopy16(3, gUnknown_080BB4C0, 0x0600e800 , 0x1000);
    DmaCopy16(3, gUnknown_080B3CA0, 0x0600f800 , BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_080B44A0, BG_CHAR_ADDR(0), 0x5800);
    DmaCopy16(3, gUnknown_080BD4C0, gUnknown_0201C1C0, 0x6800);
    sub_10170(gIntroScene1Sprites_Pals, BG_PLTT, BG_PLTT_SIZE, 0x20);
    DmaCopy16(3, gIntroScene1Sprites_Gfx, BG_CHAR_ADDR(4), 0x8000);
    DmaCopy16(3, gIntroScene1Sprites_Pals, 0x05000200, BG_PLTT_SIZE);
    sub_96A8();
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[18];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[19];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[6];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[7];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[12];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[13];
    sub_0CBC();
    sub_FEB8(BG_PLTT, gIntroScene1Sprites_Pals, 0);
    DmaCopy16(3, gIntroScene1Sprites_Pals, 0x05000200, BG_PLTT_SIZE);
    DmaCopy16(3, 0, 0x05000200, 0x20);
    gUnknown_0202C790++;
}

void sub_96A8(void)
{
    gUnknown_0201A450[1].unk0 = 0x78;
    gUnknown_0201A450[1].unk2 = 0x50;
    gUnknown_0201A450[1].unk8 = 0;
    gUnknown_0201A450[1].unkC = 1;
    gUnknown_0201A450[3].unk0 = 0x9c;
    gUnknown_0201A450[3].unk2 = 0x92;
    gUnknown_0201A450[3].unkC = 0;
    gUnknown_0201A450[3].unkA = 0;
    gUnknown_0201A450[2].unk0 = 0x9d;
    gUnknown_0201A450[2].unk2 = 0x93;
    gUnknown_0201A450[2].unkC = 0;
    gUnknown_0201A450[4].unk0 = 0x80;
    gUnknown_0201A450[4].unk2 = 0x80;
    gUnknown_0201A450[4].unkC = 1;
    gUnknown_0202ADA0[0] = 0xffa8;
    gUnknown_0202ADA0[1] = 0xffca;
    gUnknown_0202ADA0[4] = 0;
    gUnknown_0202ADA0[5] = 0;
    gUnknown_0202ADA0[6] = 0x100;
    gUnknown_0202ADA0[7] = 0;
    gUnknown_0202ADA0[10] = 0;
    gUnknown_0202ADA0[18] = 0xfb;
    gUnknown_0202ADA0[19] = 0;
    gUnknown_0202ADA0[22] = 0;
    gUnknown_0202ADA0[12] = 0;
    gUnknown_0202ADA0[13] = 0;
    gUnknown_0201A450[0].unk0 = 0x78;
    gUnknown_0201A450[0].unk2 = 0x50;
    gUnknown_0201A450[0].unk8 = 0;
    gUnknown_0201A450[0].unkA = 0;
    gUnknown_0201A450[0].unkC = 1;
    gUnknown_0201C1B8 = 0;
    gUnknown_0202ADD4 = 0x10;
    gUnknown_0202C594 = 0;
    gUnknown_02019C30 = 0x100;
    gUnknown_0201C188 = 0x100;
    gUnknown_0202BF10 = 0;
    gUnknown_0202A578 = 0;
    gUnknown_0202BEF0 = 0x20;
    gUnknown_0202C5A8 = 8;
}

void sub_978C(void)
{
    sub_9CB8();
    
    if (gUnknown_0201A450[0].unk8 == 0x24) {
        gUnknown_0201A450[0].unkA++;
        
        if (0x1b < gUnknown_0201A450[0].unkA) {
            gUnknown_0201A450[0].unkA = 0;
            gUnknown_0202A578 = 0;
            gUnknown_0202C790++;
        }
    }
    else {
        gUnknown_0201A450[0].unkA++;
        
        if (1 < gUnknown_0201A450[0].unkA) {
            gUnknown_0201A450[0].unkA = 0;
            gUnknown_0201A450[0].unk8++;
        }
        
        if (gUnknown_0202BF10 >= gUnknown_086A77A8[gUnknown_0202C5A8][gUnknown_0202A578][1]) {
            m4aSongNumStart(gUnknown_086A77A8[gUnknown_0202C5A8][gUnknown_0202A578][0]);
            gUnknown_0202A578 = gUnknown_0202A578 + 1;
        }
    }
}

void sub_9830(void)
{
    gUnknown_02019C30 -= 0x10;
    gUnknown_0201C188 -= 0x10;
    gUnknown_0201A450[0].unk0--;

    if (gUnknown_02019C30 < 0x20)
    {
        gUnknown_0201A450[0].unkA = 0;
        gUnknown_0201A450[0].unk8 = 0x25;
        gUnknown_0202C790++;
    }

    sub_9D70();
}

void sub_9878(void)
{
    gUnknown_0201A450[0].unkA++;

    if (gUnknown_0201A450[0].unkA > 3)
    {
        gUnknown_0201A450[0].unkA = 0;
        gUnknown_0201A450[0].unk0 = 0x78;
        gUnknown_0201A450[0].unk2 = 0x58;
        gUnknown_0201A450[0].unkC = 1;
        m4aSongNumStart(0xD8);
        gUnknown_0202C790++;
    }
}

void sub_98B4(void)
{
    if (gUnknown_0201A450[0].unk8 == 0x2B)
    {
        gUnknown_0201A450[0].unkA++;
        if (gUnknown_0201A450[0].unkA > 1)
        {
            gUnknown_0201A450[0].unkC = 0;
            sub_10170(&gIntroScene1Sprites_Pals[0x1C0], BG_PLTT + 0xE0, 0x20, 0);
            m4aSongNumStart(0x8);
            gUnknown_0202C790++;
        }
    }
    else
    {
        gUnknown_0201A450[0].unkA++;
        if (gUnknown_0201A450[0].unkA > 1)
        {
            gUnknown_0201A450[0].unkA = 0;
            gUnknown_0201A450[0].unk8++;
        }
    }

    sub_9CB8();
}

void sub_9920(void)
{
    s32 remainder;

    remainder = gUnknown_0202BF10 % 3;
    if (remainder == 0)
    {
        if (gUnknown_0202C594 < 8)
        {
            gUnknown_0202C594++;
            gUnknown_0201C1B8++;
            gUnknown_0202ADD4--;
        }
        else
        {
            sub_10708(&gUnknown_0201C1C0, (void *) 0x60036e0, 8, 8);
            gUnknown_0202C790++;
        }

        gUnknown_0201A450[1].unk8 = 1 - gUnknown_0201A450[1].unk8;
    }

    sub_9E90();
}

void sub_999C(void)
{
    if (gUnknown_0202BEF0 > 0)
    {
        gUnknown_0202BEF0 -= 2;
        if (gUnknown_0202BEF0 < 1)
        {
            gUnknown_0202BEF0 = 0;
        }
        sub_10170(gIntroScene1Sprites_Pals, BG_PLTT, 0x200, (u16) gUnknown_0202BEF0);
        sub_10170(gIntroScene1Sprites_Pals, OBJ_PLTT, 0x20, (u16) gUnknown_0202BEF0);
    }

    if (gUnknown_0202BF10 % 3 == 0)
    {
        gUnknown_0201A450[1].unk8 = 1 - gUnknown_0201A450[1].unk8;
    }

    gUnknown_0202ADA0[0]--;

    if ((gUnknown_0202BF10 % 2) == 0)
    {
        gUnknown_0202ADA0[1]--;
    }

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[1];
    gUnknown_0202ADA0[5]++;

    if (gUnknown_0202ADA0[5] > gUnknown_086A7768[gUnknown_0202ADA0[4]].unk2)
    {
        sub_10708(&gUnknown_0201C1C0[gUnknown_086A7788[gUnknown_0202ADA0[4]]], (void *) 0x60036E0, 8, 8);
        gUnknown_0202ADA0[4]++;
        if (gUnknown_0202ADA0[4] > 3)
        {
            gUnknown_0201A450[3].unkC = 1;
            gUnknown_0201A450[2].unkC = 1;
            gUnknown_0201A450[1].unkC = 0;
            gUnknown_0202ADA0[10] = 0;
            gUnknown_0202C790++;
        }
    }
    
    sub_9E90();
}

void sub_9AB8(void)
{
    gUnknown_0201A450[3].unk0 -= 0xE;
    gUnknown_0201A450[3].unk2 -= 0xD;

    gUnknown_0202ADA0[0x12] -= 0x10;
    gUnknown_0202ADA0[0x13] += 1;
    gUnknown_0202ADA0[0x6]  -= 0x10;

    gUnknown_0201A450[2].unk0 -= 0xE;
    gUnknown_0201A450[2].unk2 -= 0xD;
    gUnknown_0201A450[4].unk0 += 0xB;
    gUnknown_0201A450[4].unk2 -= 0x2;

    if (gUnknown_0202BF10 % 2 == 0)
    {
        gUnknown_0202ADA0[0x0]--;
        gUnknown_0202ADA0[0x1]--;
    }

    gUnknown_0202ADA0[0x5]++;

    if (gUnknown_0202ADA0[0x5] > gUnknown_086A7768[gUnknown_0202ADA0[0x4]].unk2)
    {
        if (gUnknown_0202ADA0[0x4] < 7)
        {
            sub_10708(&gUnknown_0201C1C0[gUnknown_086A7788[gUnknown_0202ADA0[0x4]]], (void *)0x60036e0, 8, 8);
        }
        else
        {
            sub_10708(&gUnknown_0201C1C0[gUnknown_086A7788[gUnknown_0202ADA0[0x4]]], (void *)0x60032c0, 10, 10);
        }
        gUnknown_0202ADA0[0x4]++;
    }

    gUnknown_0202ADA0[0xA]++;
    if (gUnknown_0202ADA0[0xA] > 9)
    {
        gUnknown_0202ADA0[0xA] = 0;
        gUnknown_0202C790 += 2;
    }

    sub_9E90();
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x12];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x13];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[0x7];
}

void nullsub_4(void)
{
}

void sub_9C10(void)
{
    gUnknown_0202ADA0[0xC]++;

    if (gUnknown_0202BF10 % 2 == 0)
    {
        gUnknown_0201A450[3].unk0--;
        gUnknown_0201A450[3].unk2--;
        gUnknown_0201A450[2].unk0 -= 2;
        gUnknown_0201A450[2].unk2 -= 2;
    }

    sub_9E90();

    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0xD];
    gUnknown_0201A450[3].unkA++;

    if (gUnknown_0201A450[3].unkA > 0x14)
    {
        gUnknown_0201A450[3].unkA = 0;
        gUnknown_0202C790 += 3;
    }
}

void nullsub_5(void)
{
}

void nullsub_17(void)
{
}

void sub_9C9C(void)
{
    sub_10480();
    sub_10544();
    gUnknown_0202C790++;
}

void sub_9CB8(void)
{
    s32 i;
    struct OamDataSimple *test2;
    struct SpriteGroup *puVar4;
    const struct SpriteSet *puVar6;

    puVar4 = &gUnknown_0200B3B8[4 + gUnknown_0201A450[0].unk8];
    puVar4->available = gUnknown_0201A450[0].unkC;
    LoadSpriteSets(gUnknown_086A769C, 0x31, gUnknown_0200B3B8);

    if (puVar4->available == 1)
    {
        puVar4->baseX = gUnknown_0201A450[0].unk0;
        puVar4->baseY = gUnknown_0201A450[0].unk2;

        puVar6 = gUnknown_086A769C[gUnknown_0201A450[0].unk8 + 4];
        for (i = 0; i < puVar6->count; i++)
        {
            test2 = &puVar4->oam[i];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar4->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar4->baseY;
        }
    }

    puVar4->available = 0;
}

void sub_9D70(void)
{
    s32 i;
    struct SpriteGroup *puVar4;
    struct OamDataSimple *puVar2;

    puVar4 = &gUnknown_0200B3B8[0x28];
    puVar4->available = gUnknown_0201A450[0].unkC;
    LoadSpriteSets(gUnknown_086A769C, 0x31, gUnknown_0200B3B8);

    if (puVar4->available == 1)
    {
        SetMatrixScale(gUnknown_02019C30, gUnknown_0201C188, 0);
        puVar4->baseX = gUnknown_0201A450[0].unk0;
        puVar4->baseY = gUnknown_0201A450[0].unk2;

        for (i = 0; i < 4; i++)
        {
            puVar2 = &puVar4->oam[i];
            gOamBuffer[puVar2->oamId].x = gUnknown_086A7798[i].unk0 * gUnknown_02019C30 / 0x100 + puVar4->baseX;
            gOamBuffer[puVar2->oamId].y = gUnknown_086A7798[i].unk2 * gUnknown_0201C188 / 0x100 + puVar4->baseY;

            gOamBuffer[puVar2->oamId].affineMode = 1;
            gOamBuffer[puVar2->oamId].matrixNum = 0;
        }
    }
    puVar4->available = 0;
}

void sub_9E90(void)
{
    struct OamDataSimple *puVar5;
    struct SpriteGroup *puVar1;
    struct SpriteGroup *mainSg3;
    struct SpriteGroup *mainSg2;
    struct SpriteGroup *otherSg;
    int i;
    const u16 *p; // TODO Fakematch

    gMain.blendControl = 0xF10;
    gMain.blendAlpha = gUnknown_0201C1B8 | (gUnknown_0202ADD4 << 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    puVar1 = &gMain.spriteGroups[gUnknown_0201A450[1].unk8];
    mainSg3 = &gMain.spriteGroups[3];
    mainSg2 = &gMain.spriteGroups[2];
    otherSg = &gUnknown_0200D638;

    puVar1->available = gUnknown_0201A450[1].unkC;
    mainSg3->available = gUnknown_0201A450[2].unkC;
    mainSg2->available = gUnknown_0201A450[3].unkC;
    otherSg->available = gUnknown_0201A450[4].unkC;
    LoadSpriteSets(gUnknown_086A769C, 0x31, gMain.spriteGroups);

    if (puVar1->available == 1)
    {
        puVar1->baseX = gUnknown_0201A450[1].unk0;
        puVar1->baseY = gUnknown_0201A450[1].unk2;
        p = &gUnknown_086A769C[gUnknown_0201A450[1].unk8]->count;
        
        for (i = 0;
            i < *p;
            i++)
        {
            puVar5 = &puVar1->oam[i];
            gOamBuffer[puVar5->oamId].objMode = 1;
            gOamBuffer[puVar5->oamId].x = puVar1->oam[i].xOffset + puVar1->baseX;
            gOamBuffer[puVar5->oamId].y = puVar1->oam[i].yOffset + puVar1->baseY;
        }
    }
    if (mainSg3->available == 1)
    {
        mainSg3->baseX = gUnknown_0201A450[2].unk0;
        mainSg3->baseY = gUnknown_0201A450[2].unk2;

        for (i = 0; i < 4; i++)
        {
            puVar5 = &mainSg3->oam[i];
            gOamBuffer[puVar5->oamId].objMode = 1;
            gOamBuffer[puVar5->oamId].priority = 1;
            gOamBuffer[puVar5->oamId].x = mainSg3->oam[i].xOffset + mainSg3->baseX;
            gOamBuffer[puVar5->oamId].y = mainSg3->oam[i].yOffset + mainSg3->baseY;
        }
    }
    if (mainSg2->available == 1)
    {
        mainSg2->baseX = gUnknown_0201A450[3].unk0;
        mainSg2->baseY = gUnknown_0201A450[3].unk2;

        for (i = 0; i < 4; i++)
        {
            puVar5 = &mainSg2->oam[i];
            gOamBuffer[puVar5->oamId].objMode = 0;
            gOamBuffer[puVar5->oamId].priority = 1;
            gOamBuffer[puVar5->oamId].x = mainSg2->oam[i].xOffset + mainSg2->baseX;
            gOamBuffer[puVar5->oamId].y = mainSg2->oam[i].yOffset + mainSg2->baseY;
        }
    }
    if (otherSg->available == 1)
    {
        otherSg->baseX = gUnknown_0201A450[4].unk0;
        otherSg->baseY = gUnknown_0201A450[4].unk2;

        for (i = 0; i < 8; i++)
        {
            puVar5 = &otherSg->oam[i];
            gOamBuffer[puVar5->oamId].priority = 2;
            gOamBuffer[puVar5->oamId].x = otherSg->oam[i].xOffset + otherSg->baseX;
            gOamBuffer[puVar5->oamId].y = otherSg->oam[i].yOffset + otherSg->baseY;
        }
    }

    puVar1->available = 0;
    mainSg3->available = 0;
    mainSg2->available = 0;
    otherSg->available = 0; // TODO Possible Bug?
}

void sub_A154(void)
{
    sub_0518();
    gUnknown_0202C790++;
}

void sub_A16C(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0;
    REG_BG0CNT = 0xCC00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0xDA01;
    REG_DISPCNT |= 0x200;
    REG_BG3CNT = 0x1E03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gUnknown_080D0700, (void*) 0x06006000, 0x2000);
    DmaCopy16(3, gUnknown_080D2700, (void*) 0x0600D000, 0x2000);
    DmaCopy16(3, gUnknown_080CBEE0, (void*) 0x0600F000, 0x800);
    DmaCopy16(3, gUnknown_080CC6E0, (void*) 0x06000000, 0x3C00);
    DmaCopy16(3, gUnknown_080CBCE0, (void*) PLTT, 0x80);
    sub_A2A8();
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0xD];
    sub_0CBC();
    sub_10424();
    gUnknown_0202C790 += 2;
}

void sub_A2A8(void)
{
    gUnknown_0202ADA0[0x0] = 0x1C;
    gUnknown_0202ADA0[0x1] = 0xFF2C;
    gUnknown_0202ADA0[0x2] = 0;
    gUnknown_0202ADA0[0x3] = 0xE;
    gUnknown_0202ADA0[0x6] = 0xFF5C;
    gUnknown_0202ADA0[0x7] = 0xFF08;
    gUnknown_0202ADA0[0x8] = 0;
    gUnknown_0202ADA0[0x9] = 0x10;
    gUnknown_0202ADA0[0xC] = 0;
    gUnknown_0202ADA0[0xD] = 0;
    gUnknown_0202ADA0[0x10] = 0;
    gUnknown_0202BF10 = 0;
    gUnknown_0202A578 = 0;
}

void nullsub_6(void)
{
}

void sub_A2F0(void)
{
    gUnknown_0202ADA0[0x1] += gUnknown_0202ADA0[0x3];
    gUnknown_0202ADA0[0x7] += gUnknown_0202ADA0[0x9];
    gUnknown_0202ADA0[0xC]--;
    gUnknown_0202ADA0[0xD]--;
    gUnknown_0202ADA0[0x0]--;
    gUnknown_0202ADA0[0x6]++;

    if (gUnknown_0202BF10 % 2 == 0)
    {
        gUnknown_0202ADA0[0x3]--;
        gUnknown_0202ADA0[0x9]--;
    }

    // TODO same as sub_A16C - possible inline function?
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0xD];

    gUnknown_0202ADA0[0x10]++;
    if (gUnknown_0202ADA0[0x10] > 0x27)
    {
        gUnknown_0202ADA0[0x10] = 0;
        gUnknown_0202C790 += 2;
    }
}

void nullsub_7(void)
{
}

void sub_A39C(void)
{
    gUnknown_0202ADA0[0x1]++;
    gUnknown_0202ADA0[0x7]++;
    gUnknown_0202ADA0[0xC]--;
    gUnknown_0202ADA0[0xD]--;
    gUnknown_0202ADA0[0x0]--;
    gUnknown_0202ADA0[0x6]++;

    // TODO same as sub_A2F0 - possible inline function?
    if (gUnknown_0202BF10 % 2 == 0)
    {
        gUnknown_0202ADA0[0x3]--;
        gUnknown_0202ADA0[0x9]--;
    }

    // TODO same as sub_A16C - possible inline function?
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0xD];

    sub_10480();
    sub_10544();
    gUnknown_0202C790++;
}

void sub_A43C(void)
{
    sub_0518();
    gUnknown_0202C790++;
}

void sub_A454(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0x1000;
    REG_BG0CNT = 0x5A00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0x1C01;
    REG_DISPCNT |= 0x200;
    REG_BG2CNT = 0x5D02;
    REG_DISPCNT |= 0x400;
    REG_BG3CNT = 0x1F03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gUnknown_080DE520, (void*) 0x0600D000, 0x1000);
    DmaCopy16(3, gUnknown_080DCD20, (void*) 0x0600E000, 0x800);
    DmaCopy16(3, gUnknown_080D4900, (void*) 0x0600E800, 0x1000);
    DmaCopy16(3, gUnknown_080D5900, (void*) 0x0600F800, 0x800);
    DmaCopy16(3, gUnknown_080DD520, gUnknown_03005C00, 0x800);
    DmaCopy16(3, gUnknown_080DDD20, gUnknown_0201B180, 0x800);
    DmaCopy16(3, gUnknown_080D6100, (void*) 0x06000000, 0x6C00);
    DmaCopy16(3, gUnknown_080D4700, (void*) PLTT, 0xE0);
    DmaCopy16(3, gUnknown_080DF520, (void*) 0x06010000, 0x2000);
    DmaCopy16(3, gUnknown_080D4700, (void*) OBJ_PLTT, 0xE0);

    sub_A628();
    sub_A87C();

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[0xD];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0x12];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0x13];

    sub_0CBC();
    sub_10424();
    gUnknown_0202C790++;
}

void sub_A628(void)
{
    gUnknown_0202ADA0[0x0] = 0x2C;
    gUnknown_0202ADA0[0x1] = 0xFF8E;
    
    gUnknown_0201A450[0].unk0 = 0xFFD4;
    gUnknown_0201A450[0].unk2 = 0x72;

    gUnknown_0202ADA0[0x6] = 0xFFCE;
    gUnknown_0202ADA0[0x7] = 0x1E;
    gUnknown_0202ADA0[0xC] = 0;
    gUnknown_0202ADA0[0xD] = 0;
    gUnknown_0202ADA0[0x10] = 0;
    gUnknown_0202ADA0[0x12] = 0;
    gUnknown_0202ADA0[0x13] = 0;

    gUnknown_0202BF10 = 0;
    gUnknown_0202A578 = 0;
}

void sub_A674(void)
{
    gUnknown_0202ADA0[0x0] -= 0x11;
    gUnknown_0202ADA0[0x1] += 0xA;

    gUnknown_0201A450[0].unk0 += 0x11;
    gUnknown_0201A450[0].unk2 -= 0xA;

    gUnknown_0202ADA0[0xC] += 0x10;
    gUnknown_0202ADA0[0x6] += 0x4;
    gUnknown_0202ADA0[0x7] -= 0x8;
    gUnknown_0202ADA0[0x10]++;

    if (gUnknown_0202ADA0[0x10] > 9)
    {
        gUnknown_0202ADA0[0x10] = 0;
        gUnknown_0202C790++;
    }

    sub_A87C();
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[0xD];
}

void sub_A710(void)
{
    gUnknown_0202ADA0[0x12]--;

    if (gUnknown_0202BF10 % 2 == 0)
    {
        gUnknown_0202ADA0[0x0]--;
        gUnknown_0202ADA0[0x1]++;
        gUnknown_0201A450[0].unk0 += 2;
        gUnknown_0201A450[0].unk2 -= 2;
    }
    if (gUnknown_0202BF10 % 3 == 0)
    {
        DmaCopy16(3, (void *) 0x05000000, gUnknown_0202BE70, 0x20);
        DmaCopy16(3, (void *) 0x05000040, 0x05000000, 0x20);
        DmaCopy16(3, (void *) gUnknown_0202BE70, 0x05000040, 0x20);
    }

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0x12];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0x13];
    sub_A87C();

    if (gUnknown_0202ADA0[0x10] == 2)
    {
        DmaCopy16(3, gUnknown_03005C00, (void*) 0x0600E000, 0x800);
        gUnknown_0202ADA0[0x6] = 0;
        gUnknown_0202ADA0[0x7] = 0;
        gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
        gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    }
    else if (gUnknown_0202ADA0[0x10] == 4)
    {
        DmaCopy16(3, gUnknown_0201B180, (void*) 0x0600E000, 0x800);
        gUnknown_0202ADA0[0x6] = 0;
        gUnknown_0202ADA0[0x7] = 0;
        gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
        gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    }

    gUnknown_0202ADA0[0x10]++;
    if (gUnknown_0202ADA0[0x10] > 0x1D)
    {
        gUnknown_0202ADA0[0x10] = 0;
        gUnknown_0202C790 += 2;
    }
}

void nullsub_8(void)
{
}

void sub_A860(void)
{
    sub_10480();
    sub_10544();
    gUnknown_0202C790++;
}

void sub_A87C(void)
{
    s32 i;
    struct SpriteGroup *puVar4;
    struct OamDataSimple *puVar2;

    gMain.blendControl = 0x1F50;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    puVar4 = &gMain.spriteGroups[0];
    puVar4->available = 1;
    LoadSpriteSets(gUnknown_086A795C, 0x1, puVar4);

    if (puVar4->available == 1)
    {
        puVar4->baseX = gUnknown_0201A450[0].unk0;
        puVar4->baseY = gUnknown_0201A450[0].unk2;

        for (i = 0; i < 4; i++)
        {
            puVar2 = &puVar4->oam[i];
            gOamBuffer[puVar2->oamId].priority = 1;
            gOamBuffer[puVar2->oamId].x = puVar2->xOffset + puVar4->baseX;
            gOamBuffer[puVar2->oamId].y = puVar2->yOffset + puVar4->baseY;
        }
    }
    puVar4->available = 0;
}

void sub_A950(void)
{
    sub_0518();
    gUnknown_0202C790++;
}

void sub_A968(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0;
    REG_BG0CNT = 0xCC00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0xDA01;
    REG_DISPCNT |= 0x200;
    REG_BG3CNT = 0x1E03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gUnknown_080E5F60, (void *) 0x6006000, 0x2000);
    DmaCopy16(3, gUnknown_080E7F60, (void *) 0x600D000, 0x2000);
    DmaCopy16(3, gUnknown_080E1740, (void *) 0x600F000, 0x800);
    DmaCopy16(3, gUnknown_080E1F40, (void *) 0x6000000, 0x4000);
    DmaCopy16(3, gUnknown_080E1540, PLTT, 0x60);
    gMain.unk16 = REG_DISPCNT;
    
    sub_AAA8();
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0xD];

    sub_0CBC();
    sub_10424();
    gUnknown_0202C790 += 2;
}

void sub_AAA8(void)
{
    gUnknown_0202ADA0[0x0] = 0x1C;
    gUnknown_0202ADA0[0x1] = 0xFF20;
    gUnknown_0202ADA0[0x2] = 0;
    gUnknown_0202ADA0[0x3] = 0xF;
    gUnknown_0202ADA0[0x6] = 0xFF64;
    gUnknown_0202ADA0[0x7] = 0xE0;
    gUnknown_0202ADA0[0x8] = 0;
    gUnknown_0202ADA0[0x9] = 0xFFF1;
    gUnknown_0202ADA0[0xC] = 0;
    gUnknown_0202ADA0[0xD] = 0;
    gUnknown_0202ADA0[0x10] = 0;

    gUnknown_0202BF10 = 0;
    gUnknown_0202A578 = 0;
}

void nullsub_9(void)
{
}

void sub_AAF4(void)
{
    gUnknown_0202ADA0[0x1] += gUnknown_0202ADA0[0x3];
    gUnknown_0202ADA0[0x7] += gUnknown_0202ADA0[0x9];
    gUnknown_0202ADA0[0xC]--;
    gUnknown_0202ADA0[0x0]--;
    gUnknown_0202ADA0[0x6]++;

    if (gUnknown_0202BF10 % 2 == 0)
    {
        gUnknown_0202ADA0[0x3]--;
        gUnknown_0202ADA0[0x9]++;
    }

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];

    gUnknown_0202ADA0[0x10]++;
    if (0x27 < gUnknown_0202ADA0[0x10])
    {
        gUnknown_0202ADA0[0x10] = 0;
        gUnknown_0202C790 += 2;
    }
}

void nullsub_10(void)
{
}

void sub_AB90(void)
{
    // TODO Near duplicate of sub_AAF4
    gUnknown_0202ADA0[0x1] += gUnknown_0202ADA0[0x3];
    gUnknown_0202ADA0[0x7] += gUnknown_0202ADA0[0x9];
    gUnknown_0202ADA0[0xC]--;
    gUnknown_0202ADA0[0x0]--;
    gUnknown_0202ADA0[0x6]++;

    if (gUnknown_0202BF10 % 2 == 0)
    {
        gUnknown_0202ADA0[0x3]--;
        gUnknown_0202ADA0[0x9]++;
    }

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];

    sub_10480();
    sub_10544();
    gUnknown_0202C790++;
}

void sub_AC20(void)
{
    // TODO Duplicate of sub_A950?
    sub_0518();
    gUnknown_0202C790++;
}

void sub_AC38(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0x1000;
    REG_BG0CNT = 0xC00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0x4E01;
    REG_DISPCNT |= 0x200;
    REG_BG2CNT = 0x5C02;
    REG_DISPCNT |= 0x400;
    REG_BG3CNT = 0x1E03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gUnknown_080F1980, (void *) 0x6006000, 0x800);
    DmaCopy16(3, gUnknown_080EB160, (void *) 0x6007000, 0x1000);
    DmaCopy16(3, gUnknown_080EA160, (void *) 0x600E000, 0x1000);
    DmaCopy16(3, gUnknown_080EC160, (void *) 0x600F000, 0x800);
    DmaCopy16(3, gUnknown_080EC960, (void *) 0x6000000, 0x2800);
    DmaCopy16(3, gUnknown_080BD4C0, gUnknown_03000000, 0x4000);
    DmaCopy16(3, gUnknown_080E9F60, (void *) 0x5000000, 0x180);
    DmaCopy16(3, gUnknown_080F2180, (void *) 0x6010000, 0x3000);
    DmaCopy16(3, gUnknown_080E9F60, OBJ_PLTT, 0x180);

    sub_ADFC();
    sub_B0E8();

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[0xD];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0x12];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0x13];

    sub_0CBC();
    sub_10424();
    gUnknown_0202C790++;
}

void sub_ADFC(void)
{
    gUnknown_0201A450[1].unk0 = 0xB4;
    gUnknown_0201A450[1].unk2 = 0xFFBC;
    gUnknown_0201A450[0].unk0 = 0xB4;
    gUnknown_0201A450[0].unk2 = 0xFFBC;
    gUnknown_0201A450[2].unk0 = 0x80;
    gUnknown_0201A450[2].unk2 = 0x88;

    gUnknown_0202ADA0[0x0] = 0xFF58;
    gUnknown_0202ADA0[0x1] = 0xFF98;
    gUnknown_0202ADA0[0x4] = 0;
    gUnknown_0202ADA0[0x5] = 0;
    gUnknown_0202ADA0[0x2] = 0;

    sub_10708(&gUnknown_03002300, (void *) 0x6002ee0, 8, 8);

    gUnknown_0202ADA0[0x6] = 0xA5;
    gUnknown_0202ADA0[0x7] = 0;
    gUnknown_0202ADA0[0xA] = 0;
    gUnknown_0202ADA0[0xC] = 0xA0;
    gUnknown_0202ADA0[0xD] = 0;
    gUnknown_0202ADA0[0x10] = 0;
    gUnknown_0202ADA0[0x12] = 0;
    gUnknown_0202ADA0[0x13] = 0;

    gUnknown_0202BF10 = 0;
    gUnknown_0202A578 = 0;
}

void sub_AE74(void)
{
    gUnknown_0201A450[1].unk0 -= 0x10;
    gUnknown_0201A450[1].unk2 += 0xA;
    gUnknown_0201A450[0].unk0 -= 0x10;
    gUnknown_0201A450[0].unk2 += 0xA;
    gUnknown_0201A450[2].unk0 += 0x5;
    gUnknown_0201A450[2].unk2 -= 0x3;

    gUnknown_0202ADA0[0x6] -= 0x10;
    gUnknown_0202ADA0[0x7]++;
    gUnknown_0202ADA0[0xC] -= 0x10;
    gUnknown_0202ADA0[0x0] += gUnknown_0202ADA0[0x2];
    gUnknown_0202ADA0[0x1] += 0x9;
    gUnknown_0202ADA0[0x2]++;
    gUnknown_0202ADA0[0x5]++;

    if (gUnknown_0202ADA0[0x5] > gUnknown_086A79FC[gUnknown_0202ADA0[0x4]].unk2)
    {
        gUnknown_0202ADA0[0x4]++;
        sub_10708(&gUnknown_03000000[gUnknown_086A7A1C[gUnknown_0202ADA0[0x4]]], (void *) 0x6002EE0, 8, 8);
    }

    sub_B0E8();
    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[0xD];
    
    gUnknown_0202ADA0[0x10]++;
    if (9 < gUnknown_0202ADA0[0x10])
    {
        gUnknown_0202ADA0[0x10] = 0;
        gUnknown_0202C790++;
    }
}

void sub_AF80(void)
{
    gUnknown_0202ADA0[0x5]++;

    if (gUnknown_0202ADA0[0x5] > gUnknown_086A79FC[gUnknown_0202ADA0[0x4]].unk2)
    {
        if (gUnknown_0202ADA0[0x04] < 7)
        {
            gUnknown_0202ADA0[0x4]++;
            sub_10708(&gUnknown_03000000[gUnknown_086A7A1C[gUnknown_0202ADA0[0x4]]], (void *) 0x6002EE0, 8, 8);
        }
    }

    sub_B0E8();
    gUnknown_0202ADA0[0x12]++;
    if ((gUnknown_0202BF10 % 2) == 0)
    {
        gUnknown_0201A450[1].unk0--;
        gUnknown_0201A450[1].unk2++;
        gUnknown_0201A450[0].unk0 -= 2;
        gUnknown_0201A450[0].unk2 += 2;
    }

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[0xD];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0x12];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0x13];

    gUnknown_0202ADA0[0x16]++;
    if (0x1D < gUnknown_0202ADA0[0x16])
    {
        gUnknown_0202ADA0[0x16] = 0;
        gUnknown_0202C790 += 2;
    }
}

void nullsub_11(void)
{
}

void sub_B090(void)
{
    sub_10480();
    ClearSprites();

    DmaFill32(3, 0, OAM, 0x400);
    DmaFill16(3, 0, OBJ_VRAM0, 0x5000);

    sub_10544();
    gUnknown_0202C790++;
}

void sub_B0E8(void)
{
    struct OamDataSimple *puVar1;
    struct SpriteGroup *mainSg1;
    struct SpriteGroup *mainSg0;
    struct SpriteGroup *mainSg2;
    int i;
    
    gMain.blendControl = 0xF10;
    gMain.blendAlpha = BLDALPHA_BLEND(8, 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    mainSg1 = &gMain.spriteGroups[1];
    mainSg0 = &gMain.spriteGroups[0];
    mainSg2 = &gMain.spriteGroups[2];

    mainSg1->available = 1;
    mainSg0->available = 1;
    mainSg2->available = 1;
    LoadSpriteSets(gUnknown_086A79EC, 0x3, gMain.spriteGroups);

    if (mainSg1->available == 1)
    {
        mainSg1->baseX = gUnknown_0201A450[0].unk0;
        mainSg1->baseY = gUnknown_0201A450[0].unk2;

        for (i = 0; i < 4; i++)
        {
            puVar1 = &mainSg1->oam[i];
            gOamBuffer[puVar1->oamId].objMode = 1;
            gOamBuffer[puVar1->oamId].priority = 1;
            gOamBuffer[puVar1->oamId].x = mainSg1->oam[i].xOffset + mainSg1->baseX;
            gOamBuffer[puVar1->oamId].y = mainSg1->oam[i].yOffset + mainSg1->baseY;
        }
    }
    if (mainSg0->available == 1)
    {
        mainSg0->baseX = gUnknown_0201A450[1].unk0;
        mainSg0->baseY = gUnknown_0201A450[1].unk2;

        for (i = 0; i < 4; i++)
        {
            puVar1 = &mainSg0->oam[i];
            gOamBuffer[puVar1->oamId].objMode = 0;
            gOamBuffer[puVar1->oamId].priority = 1;
            gOamBuffer[puVar1->oamId].x = mainSg0->oam[i].xOffset + mainSg0->baseX;
            gOamBuffer[puVar1->oamId].y = mainSg0->oam[i].yOffset + mainSg0->baseY;
        }
    }
    if (mainSg2->available == 1)
    {
        mainSg2->baseX = gUnknown_0201A450[2].unk0;
        mainSg2->baseY = gUnknown_0201A450[2].unk2;

        for (i = 0; i < 8; i++)
        {
            puVar1 = &mainSg2->oam[i];
            gOamBuffer[puVar1->oamId].priority = 2;
            gOamBuffer[puVar1->oamId].x = mainSg2->oam[i].xOffset + mainSg2->baseX;
            gOamBuffer[puVar1->oamId].y = mainSg2->oam[i].yOffset + mainSg2->baseY;
        }
    }

    mainSg1->available = 0;
    mainSg0->available = 0;
    mainSg2->available = 0;
}

void sub_B2E0(void)
{
    sub_0518();
    gUnknown_0202C790++;
}

void sub_B2F8(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = 0xF00;
    REG_DISPCNT |= (DISPCNT_BG0_ON);
    REG_BG1CNT = 0xDA01;
    REG_DISPCNT |= (DISPCNT_BG1_ON);
    REG_BG2CNT = 0x1E02;
    REG_DISPCNT |= (DISPCNT_BG2_ON);
    REG_BG3CNT = 0x1f03;
    REG_DISPCNT |= (DISPCNT_BG3_ON);

    DmaCopy16(3, gUnknown_080FD7C0, 0x06007800, 0x800);
    DmaCopy16(3, gUnknown_080FDFC0, 0x0600D000, 0x2000);
    DmaCopy16(3, gUnknown_080FCFC0, 0x0600F000, 0x800);
    DmaCopy16(3, gUnknown_080F63A0, 0x0600F800, 0x800);
    DmaCopy16(3, gUnknown_080F6BA0, 0x06000000, 0x6400);
    DmaCopy16(3, gUnknown_080F61A0, 0x05000000, 0x80);
    DmaCopy16(3, gUnknown_080FFFC0, 0x06010000, 0x1000);
    DmaCopy16(3, gUnknown_080F61A0, 0x05000200, 0x80);

    sub_B4A0();

    gMain.unk2E8[0].unk0 = gUnknown_0202ADA0[0x0];
    gMain.unk2E8[0].unk2 = gUnknown_0202ADA0[0x1];
    gMain.unk2E8[1].unk0 = gUnknown_0202ADA0[0x6];
    gMain.unk2E8[1].unk2 = gUnknown_0202ADA0[0x7];
    gMain.unk2E8[2].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[2].unk2 = gUnknown_0202ADA0[0xD];
    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0x12];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0x13];

    sub_0CBC();
    sub_10424();
    gUnknown_0202C790++;
}

void sub_B4A0(void)
{
    int i;

    gUnknown_0202ADA0[0x6] = 0x1E;
    gUnknown_0202ADA0[0x7] = 0xFF6A;
    gUnknown_0202ADA0[0xA] = 0x1;
    gUnknown_0202ADA0[0x0] = 0xFFFE;
    gUnknown_0202ADA0[0x1] = 0xFFFB;
    gUnknown_0202ADA0[0x2] = 0x0;
    gUnknown_0202ADA0[0x3] = 0x8;
    gUnknown_0202ADA0[0xC] = 0xFF90;
    gUnknown_0202ADA0[0xD] = 0xFFD4;
    gUnknown_0202ADA0[0xE] = 0x8;
    gUnknown_0202ADA0[0xF] = 0x0;
    gUnknown_0202ADA0[0x12] = 0x0;
    gUnknown_0202ADA0[0x13] = 0x0;

    gUnknown_0201A450[0].unk0 = 0x32;
    gUnknown_0201A450[0].unk2 = 0x3C;
    gUnknown_0201A450[1].unk0 = 0x50;
    gUnknown_0201A450[1].unk2 = 0x3C;
    gUnknown_0201A450[2].unk0 = 0x8C;
    gUnknown_0201A450[2].unk2 = 0x64;
    gUnknown_0201A450[3].unk0 = 0xC8;
    gUnknown_0201A450[3].unk2 = 0x5A;
    gUnknown_0201A450[4].unk0 = 0x3C;
    gUnknown_0201A450[4].unk2 = 0x1E;
    gUnknown_0201A450[5].unk0 = 0x96;
    gUnknown_0201A450[5].unk2 = 0x64;

    for (i = 0; i < 6; i++)
    {
        gUnknown_0201A450[i].unk8 = 0;
        gUnknown_0201A450[i].unkA = 0;
        gUnknown_0201A450[i].unkC = 0;
    }

    gUnknown_0202C548 = 0;
    gUnknown_0202BF10 = 0;
    gUnknown_0202A578 = 0;
    gUnknown_0202BEB4 = 0;
}
