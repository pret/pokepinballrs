#include "global.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"
#include "titlescreen.h"

extern void sub_10170(u8 *, u32, u32, u32);
void sub_FEB8(u32, u8 *, u32);

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
extern u32 gUnknown_0201C188;
extern s16 gUnknown_0202A578;
extern s32 gUnknown_0202BEF0;
extern s8 gUnknown_0202C5A8;
extern s8 gUnknown_0202C790;

typedef void (*OtherFunc)(void);
extern OtherFunc gUnknown_080792E0[10];

struct unkStruct_201A450
{
    u16 unk0;
    u16 unk2;
    u8 fill4[0x8 - 4];
    s16 unk8;
    s16 unkA;
    s8 unkC;
    u8 fillD[0x10 - 0xD];
    u16 unk10;
    u16 unk12;
    u8 fill14[0x18 - 0x14];
    u16 unk18;
    u16 fill1A;
    u8 unk1C;
    u8 fill1D[0x20 - 0x1D];
    u16 unk20;
    u16 unk22;
    u8 fill24[0x2C - 0x24];
    u8 unk2C;
    u8 fill2D[0x30 - 0x2D];
    u16 unk30;
    u16 unk32;
    u8 fill34[0x3A - 0x34];
    s16 unk3A;
    u8 unk3C;
    u8 fill3D[0x40 - 0x3D];
    u16 unk40;
    u16 unk42;
    u8 fill44[0x4C - 0x44];
    u8 unk4C;
};

extern struct unkStruct_201A450 gUnknown_0201A450;

struct UnkStruct_086A7768 {
    s16 unk0;
    s16 unk2;
};

extern struct UnkStruct_086A7768 gUnknown_086A7768[0x8];

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
    gUnknown_0201A450.unk10 = 0x78;
    gUnknown_0201A450.unk12 = 0x50;
    gUnknown_0201A450.unk18 = 0;
    gUnknown_0201A450.unk1C = 1;
    gUnknown_0201A450.unk30 = 0x9c;
    gUnknown_0201A450.unk32 = 0x92;
    gUnknown_0201A450.unk3C = 0;
    gUnknown_0201A450.unk3A = 0;
    gUnknown_0201A450.unk20 = 0x9d;
    gUnknown_0201A450.unk22 = 0x93;
    gUnknown_0201A450.unk2C = 0;
    gUnknown_0201A450.unk40 = 0x80;
    gUnknown_0201A450.unk42 = 0x80;
    gUnknown_0201A450.unk4C = 1;
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
    gUnknown_0201A450.unk0 = 0x78;
    gUnknown_0201A450.unk2 = 0x50;
    gUnknown_0201A450.unk8 = 0;
    gUnknown_0201A450.unkA = 0;
    gUnknown_0201A450.unkC = 1;
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
    
    if (gUnknown_0201A450.unk8 == 0x24) {
        gUnknown_0201A450.unkA = gUnknown_0201A450.unkA + 1;
        
        if (0x1b < gUnknown_0201A450.unkA) {
            gUnknown_0201A450.unkA = 0;
            gUnknown_0202A578 = 0;
            gUnknown_0202C790++;
        }
    }
    else {
        gUnknown_0201A450.unkA = gUnknown_0201A450.unkA + 1;
        
        if (1 < gUnknown_0201A450.unkA) {
            gUnknown_0201A450.unkA = 0;
            gUnknown_0201A450.unk8 = gUnknown_0201A450.unk8 + 1;
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
    gUnknown_0201A450.unk0--;

    if (gUnknown_02019C30 < 0x20)
    {
        gUnknown_0201A450.unkA = 0;
        gUnknown_0201A450.unk8 = 0x25;
        gUnknown_0202C790++;
    }

    sub_9D70();
}

void sub_9878(void)
{
    gUnknown_0201A450.unkA++;

    if (gUnknown_0201A450.unkA > 3)
    {
        gUnknown_0201A450.unkA = 0;
        gUnknown_0201A450.unk0 = 0x78;
        gUnknown_0201A450.unk2 = 0x58;
        gUnknown_0201A450.unkC = 1;
        m4aSongNumStart(0xD8);
        gUnknown_0202C790++;
    }
}

void sub_98B4(void)
{
    if (gUnknown_0201A450.unk8 == 0x2B)
    {
        gUnknown_0201A450.unkA++;
        if (gUnknown_0201A450.unkA > 1)
        {
            gUnknown_0201A450.unkC = 0;
            sub_10170(&gIntroScene1Sprites_Pals[0x1C0], BG_PLTT + 0xE0, 0x20, 0);
            m4aSongNumStart(0x8);
            gUnknown_0202C790++;
        }
    }
    else
    {
        gUnknown_0201A450.unkA++;
        if (gUnknown_0201A450.unkA > 1)
        {
            gUnknown_0201A450.unkA = 0;
            gUnknown_0201A450.unk8++;
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

        gUnknown_0201A450.unk18 = 1 - gUnknown_0201A450.unk18;
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
        gUnknown_0201A450.unk18 = 1 - gUnknown_0201A450.unk18;
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
            gUnknown_0201A450.unk3C = 1;
            gUnknown_0201A450.unk2C = 1;
            gUnknown_0201A450.unk1C = 0;
            gUnknown_0202ADA0[10] = 0;
            gUnknown_0202C790++;
        }
    }
    
    sub_9E90();
}

void sub_9AB8(void)
{
    gUnknown_0201A450.unk30 -= 0xE;
    gUnknown_0201A450.unk32 -= 0xD;

    gUnknown_0202ADA0[0x12] -= 0x10;
    gUnknown_0202ADA0[0x13] += 1;
    gUnknown_0202ADA0[0x6]  -= 0x10;

    gUnknown_0201A450.unk20 -= 0xE;
    gUnknown_0201A450.unk22 -= 0xD;
    gUnknown_0201A450.unk40 += 0xB;
    gUnknown_0201A450.unk42 -= 0x2;

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
        gUnknown_0201A450.unk30--;
        gUnknown_0201A450.unk32--;
        gUnknown_0201A450.unk20 -= 2;
        gUnknown_0201A450.unk22 -= 2;
    }

    sub_9E90();

    gMain.unk2E8[3].unk0 = gUnknown_0202ADA0[0xC];
    gMain.unk2E8[3].unk2 = gUnknown_0202ADA0[0xD];
    gUnknown_0201A450.unk3A++;

    if (gUnknown_0201A450.unk3A > 0x14)
    {
        gUnknown_0201A450.unk3A = 0;
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

    puVar4 = &gUnknown_0200B3B8[4 + gUnknown_0201A450.unk8];
    puVar4->available = gUnknown_0201A450.unkC;
    LoadSpriteSets(gUnknown_086A769C, 0x31, gUnknown_0200B3B8);

    if (puVar4->available == 1)
    {
        puVar4->baseX = gUnknown_0201A450.unk0;
        puVar4->baseY = gUnknown_0201A450.unk2;

        puVar6 = gUnknown_086A769C[gUnknown_0201A450.unk8 + 4];
        for (i = 0; i < puVar6->count; i++)
        {
            test2 = &puVar4->oam[i];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar4->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar4->baseY;
        }
    }

    puVar4->available = 0;
}
