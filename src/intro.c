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

void sub_9D70(void)
{
    s32 i;
    struct SpriteGroup *puVar4;
    struct OamDataSimple *puVar2;

    puVar4 = &gUnknown_0200B3B8[0x28];
    puVar4->available = gUnknown_0201A450.unkC;
    LoadSpriteSets(gUnknown_086A769C, 0x31, gUnknown_0200B3B8);

    if (puVar4->available == 1)
    {
        SetMatrixScale(gUnknown_02019C30, gUnknown_0201C188, 0);
        puVar4->baseX = gUnknown_0201A450.unk0;
        puVar4->baseY = gUnknown_0201A450.unk2;

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

// TODO see https://decomp.me/scratch/9Nuw9
NAKED
void sub_9E90(void)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	ldr r3, _0800A12C @ =gMain\n\
	ldrh r0, [r3, #0x38]\n\
	movs r0, #0xf1\n\
	lsls r0, r0, #4\n\
	strh r0, [r3, #0x38]\n\
	ldr r0, _0800A130 @ =gUnknown_0201C1B8\n\
	ldrb r1, [r0]\n\
	ldr r0, _0800A134 @ =gUnknown_0202ADD4\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r3, #0x3a]\n\
	strh r1, [r3, #0x3a]\n\
	ldr r1, _0800A138 @ =0x04000050\n\
	ldrh r0, [r3, #0x38]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldrh r0, [r3, #0x3a]\n\
	strh r0, [r1]\n\
	ldr r4, _0800A13C @ =gUnknown_0201A450\n\
	movs r0, #0x18\n\
	ldrsh r1, [r4, r0]\n\
	movs r0, #0xb8\n\
	muls r0, r1, r0\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #2\n\
	adds r2, r3, r1\n\
	adds r0, r0, r2\n\
	mov r8, r0\n\
	movs r6, #0xa4\n\
	lsls r6, r6, #3\n\
	adds r6, r6, r3\n\
	mov sb, r6\n\
	movs r7, #0x8d\n\
	lsls r7, r7, #3\n\
	adds r7, r7, r3\n\
	mov sl, r7\n\
	movs r0, #0x1c\n\
	ldrsb r0, [r4, r0]\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x2c\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	strh r0, [r6]\n\
	adds r0, r4, #0\n\
	adds r0, #0x3c\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	strh r0, [r7]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	ldr r6, _0800A140 @ =gUnknown_0200D638\n\
	strh r0, [r6]\n\
	ldr r5, _0800A144 @ =gUnknown_086A769C\n\
	adds r0, r5, #0\n\
	movs r1, #0x31\n\
	bl LoadSpriteSets\n\
	mov r7, r8\n\
	ldrh r0, [r7]\n\
	cmp r0, #1\n\
	bne _08009F9E\n\
	ldrh r0, [r4, #0x10]\n\
	strh r0, [r7, #2]\n\
	ldrh r0, [r4, #0x12]\n\
	strh r0, [r7, #4]\n\
	movs r1, #0x18\n\
	ldrsh r0, [r4, r1]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	ldr r0, [r0]\n\
	str r0, [sp]\n\
	movs r5, #0\n\
	ldrh r2, [r0]\n\
	cmp r5, r2\n\
	bge _08009F9E\n\
	ldr r7, _0800A148 @ =gOamBuffer\n\
	ldr r6, _0800A14C @ =0xFFFFFE00\n\
	mov ip, r6\n\
	mov r4, r8\n\
	adds r4, #8\n\
_08009F4C:\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	adds r2, r2, r7\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	adds r3, r3, r7\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	mov r2, r8\n\
	movs r6, #2\n\
	ldrsh r0, [r2, r6]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800A150 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, ip\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r7\n\
	mov r6, r8\n\
	ldrb r0, [r6, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldr r6, [sp]\n\
	ldrh r6, [r6]\n\
	cmp r5, r6\n\
	blt _08009F4C\n\
_08009F9E:\n\
	mov r7, sb\n\
	ldrh r0, [r7]\n\
	cmp r0, #1\n\
	bne _0800A01C\n\
	ldr r0, _0800A13C @ =gUnknown_0201A450\n\
	ldrh r1, [r0, #0x20]\n\
	strh r1, [r7, #2]\n\
	ldrh r0, [r0, #0x22]\n\
	strh r0, [r7, #4]\n\
	ldr r6, _0800A148 @ =gOamBuffer\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	mov ip, r0\n\
	mov r4, sb\n\
	adds r4, #8\n\
	movs r5, #3\n\
_08009FBE:\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	ldrb r2, [r1, #1]\n\
	mov r0, ip\n\
	ands r0, r2\n\
	movs r2, #4\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	ldrb r2, [r1, #5]\n\
	mov r0, ip\n\
	ands r0, r2\n\
	movs r7, #4\n\
	orrs r0, r7\n\
	strb r0, [r1, #5]\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	adds r3, r3, r6\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	mov r2, sb\n\
	movs r7, #2\n\
	ldrsh r0, [r2, r7]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800A150 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	ldr r0, _0800A14C @ =0xFFFFFE00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	mov r7, sb\n\
	ldrb r0, [r7, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bge _08009FBE\n\
_0800A01C:\n\
	mov r6, sl\n\
	ldrh r0, [r6]\n\
	cmp r0, #1\n\
	bne _0800A098\n\
	ldr r0, _0800A13C @ =gUnknown_0201A450\n\
	ldrh r1, [r0, #0x30]\n\
	strh r1, [r6, #2]\n\
	ldrh r0, [r0, #0x32]\n\
	strh r0, [r6, #4]\n\
	ldr r6, _0800A148 @ =gOamBuffer\n\
	ldr r7, _0800A14C @ =0xFFFFFE00\n\
	mov ip, r7\n\
	mov r4, sl\n\
	adds r4, #8\n\
	movs r5, #3\n\
_0800A03A:\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	strb r0, [r1, #1]\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	adds r2, r2, r6\n\
	ldrb r1, [r2, #5]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #5]\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	adds r3, r3, r6\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	mov r2, sl\n\
	movs r7, #2\n\
	ldrsh r0, [r2, r7]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800A150 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, ip\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	mov r7, sl\n\
	ldrb r0, [r7, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bge _0800A03A\n\
_0800A098:\n\
	ldr r6, _0800A140 @ =gUnknown_0200D638\n\
	ldrh r0, [r6]\n\
	cmp r0, #1\n\
	bne _0800A10A\n\
	ldr r0, _0800A13C @ =gUnknown_0201A450\n\
	adds r1, r0, #0\n\
	adds r1, #0x40\n\
	ldrh r1, [r1]\n\
	strh r1, [r6, #2]\n\
	adds r0, #0x42\n\
	ldrh r0, [r0]\n\
	strh r0, [r6, #4]\n\
	ldr r6, _0800A148 @ =gOamBuffer\n\
	movs r7, #0xd\n\
	rsbs r7, r7, #0\n\
	mov ip, r7\n\
	ldr r4, _0800A140 @ =gUnknown_0200D638\n\
	adds r4, #8\n\
	movs r5, #7\n\
_0800A0BE:\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	adds r2, r2, r6\n\
	ldrb r1, [r2, #5]\n\
	mov r0, ip\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2, #5]\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	adds r3, r3, r6\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	ldr r2, _0800A140 @ =gUnknown_0200D638\n\
	movs r7, #2\n\
	ldrsh r0, [r2, r7]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800A150 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	ldr r0, _0800A14C @ =0xFFFFFE00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	ldr r7, _0800A140 @ =gUnknown_0200D638\n\
	ldrb r0, [r7, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bge _0800A0BE\n\
_0800A10A:\n\
	movs r0, #0\n\
	mov r6, r8\n\
	strh r0, [r6]\n\
	mov r7, sb\n\
	strh r0, [r7]\n\
	mov r1, sl\n\
	strh r0, [r1]\n\
	ldr r2, _0800A140 @ =gUnknown_0200D638\n\
	strh r0, [r2]\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800A12C: .4byte gMain\n\
_0800A130: .4byte gUnknown_0201C1B8\n\
_0800A134: .4byte gUnknown_0202ADD4\n\
_0800A138: .4byte 0x04000050\n\
_0800A13C: .4byte gUnknown_0201A450\n\
_0800A140: .4byte gUnknown_0200D638\n\
_0800A144: .4byte gUnknown_086A769C\n\
_0800A148: .4byte gOamBuffer\n\
_0800A14C: .4byte 0xFFFFFE00\n\
_0800A150: .4byte 0x000001FF");
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
    
    gUnknown_0201A450.unk0 = 0xFFD4;
    gUnknown_0201A450.unk2 = 0x72;

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

    gUnknown_0201A450.unk0 += 0x11;
    gUnknown_0201A450.unk2 -= 0xA;

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
        gUnknown_0201A450.unk0 += 2;
        gUnknown_0201A450.unk2 -= 2;
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
        puVar4->baseX = gUnknown_0201A450.unk0;
        puVar4->baseY = gUnknown_0201A450.unk2;

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
    gUnknown_0201A450.unk10 = 0xB4;
    gUnknown_0201A450.unk12 = 0xFFBC;
    gUnknown_0201A450.unk0 = 0xB4;
    gUnknown_0201A450.unk2 = 0xFFBC;
    gUnknown_0201A450.unk20 = 0x80;
    gUnknown_0201A450.unk22 = 0x88;

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
    gUnknown_0201A450.unk10 -= 0x10;
    gUnknown_0201A450.unk12 += 0xA;
    gUnknown_0201A450.unk0 -= 0x10;
    gUnknown_0201A450.unk2 += 0xA;
    gUnknown_0201A450.unk20 += 0x5;
    gUnknown_0201A450.unk22 -= 0x3;

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
        gUnknown_0201A450.unk10--;
        gUnknown_0201A450.unk12++;
        gUnknown_0201A450.unk0 -= 2;
        gUnknown_0201A450.unk2 += 2;
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
