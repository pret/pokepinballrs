#include "global.h"
#include "constants/bg_music.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"

extern StateFunc gHighScoresStateFuncs[15];
extern StateFunc gIdleHighScoresStateFuncs[15];
extern u8 gUnknown_0809DBE0[];
extern u8 gUnknown_08099FC0[];
extern u8 gUnknown_080957A0[];
extern s16 gUnknown_0202C588;
extern u8 gUnknown_0202BEB0;
extern u8 gUnknown_0201C18C;
extern s16 gUnknown_0201A4B8;
extern s8 gUnknown_0202BED4;
extern s8 gUnknown_0202C580;
extern u8 gUnknown_0201B178;
extern u8 gUnknown_0202BEBC;

extern s16 gUnknown_02002880;
extern s16 gUnknown_02002882;
extern s8 gUnknown_02002884;
extern s8 gUnknown_02002885;

struct unkStruct_2002858
{
    u32 unk0;
    u32 unk4;
    u8 fill8[2];
    u8 unkA;
    u8 unkB;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26;
};

struct unkStruct_2002858 gUnknown_02002858;

extern struct HighScoreEntry gUnknown_0202C610[2][NUM_HIGH_SCORES];
extern struct HighScoreEntry gUnknown_0202C550[2];
extern u8 gUnknown_0809AFC0[];
extern u8 gUnknown_080947A0[];
extern u8 gUnknown_0809DDE0[];
extern u8 gUnknown_0809DFE0[];
extern u32 gUnknown_08079870[8];

void HighScoresMain(void)
{
    gHighScoresStateFuncs[gMain.subState]();
}

void IdleHighScoresMain(void)
{
    gIdleHighScoresStateFuncs[gMain.subState]();
}

void LoadHighScoreGraphics(void)
{
  ResetSomeGraphicsRelatedStuff();
  REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_FORCED_BLANK;
  REG_BG2CNT = 0x4006;
  REG_DISPCNT |= DISPCNT_BG2_ON;
  REG_BG3CNT = 0x420f;
  REG_DISPCNT |= DISPCNT_BG3_ON;
  gMain.unk16 = REG_DISPCNT;

  DmaCopy16(3, gUnknown_0809DBE0, (void*) PLTT, 0x200);
  DmaCopy16(3, gUnknown_080957A0, (void*) BG_VRAM + 0x4000, 0x4800);
  DmaCopy16(3, gUnknown_0809AFC0, (void *)BG_VRAM + 0xC000, 0x2C00);
  DmaCopy16(3, gUnknown_080947A0, gUnknown_03005C00, 0x1000);
  DmaCopy16(3, gUnknown_08099FC0, (void *)BG_SCREEN_ADDR(2), 0x1000);
  DmaCopy16(3, gUnknown_0809DDE0, (void *)OBJ_PLTT, 0x100);
  DmaCopy16(3, gUnknown_0809DFE0, (void *)OBJ_VRAM0, 0x4420);
  sub_CFD4();
  sub_EE64();
  DmaCopy16(3, gUnknown_03005C00,0x6000000, 0x1000);
  if(gUnknown_0202C588 == 0)
      m4aSongNumStart(MUS_HI_SCORE);

  gUnknown_0202C588 = 0;
  sub_0CBC();
  sub_024C();
  gMain.subState = gUnknown_02002858.unkA;
}

NAKED
void sub_CFD4(void)
{
    asm_unified(
	"\tpush {r4, r5, r6, r7, lr}\n"
	"\tmov r7, sl\n"
	"\tmov r6, sb\n"
	"\tmov r5, r8\n"
	"\tpush {r5, r6, r7}\n"
	"\tmovs r7, #0\n"
	"\tldr r0, _0800D0B0 @ =gUnknown_02002858\n"
	"\tmov r8, r0\n"
	"\tldr r1, _0800D0B4 @ =gUnknown_0202C610\n"
	"\tmov sl, r1\n"
	"\tldr r2, _0800D0B8 @ =gMain+0x74\n"
	"\tmov sb, r2\n"
	"\tmovs r3, #0\n"
	"\tmov ip, r3\n"
"_0800CFF0:\n"
	"\tmovs r3, #0\n"
	"\tmov r4, ip\n"
	"\tmovs r6, #0\n"
"_0800CFF6:\n"
	"\tadds r0, r4, #0\n"
	"\tadds r0, #0xe4\n"
	"\tadds r0, r6, r0\n"
	"\tmov r1, sb\n"
	"\tadds r5, r0, r1\n"
	"\tadds r0, r6, r4\n"
	"\tmov r1, sl\n"
	"\tadds r2, r0, r1\n"
	"\tmovs r1, #5\n"
"_0800D008:\n"
	"\tldm r5!, {r0}\n"
	"\tstm r2!, {r0}\n"
	"\tsubs r1, #1\n"
	"\tcmp r1, #0\n"
	"\tbge _0800D008\n"
	"\tadds r6, #0x18\n"
	"\tadds r3, #1\n"
	"\tcmp r3, #7\n"
	"\tble _0800CFF6\n"
	"\tmovs r2, #0xc0\n"
	"\tadd ip, r2\n"
	"\tadds r7, #1\n"
	"\tcmp r7, #1\n"
	"\tble _0800CFF0\n"
	"\tmovs r7, #0\n"
	"\tldr r6, _0800D0BC @ =gUnknown_0202C550\n"
	"\tldr r5, _0800D0B4 @ =gUnknown_0202C610\n"
"_0800D02A:\n"
	"\tlsls r0, r7, #1\n"
	"\tadds r4, r7, #1\n"
	"\tadds r0, r0, r7\n"
	"\tlsls r1, r0, #3\n"
	"\tlsls r0, r0, #6\n"
	"\tadds r2, r0, r5\n"
	"\tadds r1, r1, r6\n"
	"\tmovs r3, #5\n"
"_0800D03A:\n"
	"\tldm r2!, {r0}\n"
	"\tstm r1!, {r0}\n"
	"\tsubs r3, #1\n"
	"\tcmp r3, #0\n"
	"\tbge _0800D03A\n"
	"\tadds r7, r4, #0\n"
	"\tcmp r7, #1\n"
	"\tble _0800D02A\n"
	"\tmovs r3, #0\n"
	"\tmovs r2, #0\n"
	"\tmov r4, r8\n"
	"\tstrh r2, [r4, #0x10]\n"
	"\tstrh r2, [r4, #0x12]\n"
	"\tstrh r2, [r4, #0x14]\n"
	"\tstrh r2, [r4, #0x18]\n"
	"\tstrh r2, [r4, #0x1a]\n"
	"\tstrh r2, [r4, #0x1e]\n"
	"\tstrh r2, [r4, #0x1c]\n"
	"\tstrh r2, [r4, #0x20]\n"
	"\tstrh r2, [r4, #0x22]\n"
	"\tmov r0, r8\n"
	"\tadds r0, #0x25\n"
	"\tstrb r3, [r0]\n"
	"\tmov r1, r8\n"
	"\tadds r1, #0x26\n"
	"\tmovs r0, #1\n"
	"\tstrb r0, [r1]\n"
	"\tldr r1, _0800D0C0 @ =gUnknown_0201B178\n"
	"\tstrb r3, [r1]\n"
	"\tldr r4, _0800D0C4 @ =gUnknown_0202BEBC\n"
	"\tstrb r0, [r4]\n"
	"\tldr r0, _0800D0C8 @ =gUnknown_0201C18C\n"
	"\tstrb r3, [r0]\n"
	"\tldr r1, _0800D0CC @ =gUnknown_02002884\n"
	"\tstrb r3, [r1]\n"
	"\tldr r4, _0800D0D0 @ =gUnknown_02002885\n"
	"\tstrb r3, [r4]\n"
	"\tldr r1, _0800D0D4 @ =gUnknown_0202C588\n"
	"\tmovs r4, #0\n"
	"\tldrsh r0, [r1, r4]\n"
	"\tcmp r0, #1\n"
	"\tbeq _0800D090\n"
	"\tb _0800D1C0\n"
"_0800D090:\n"
	"\tldr r0, _0800D0D8 @ =gMain\n"
	"\tldr r1, [r0, #0x5c]\n"
	"\tmov r4, r8\n"
	"\tstr r1, [r4]\n"
	"\tldr r1, [r0, #0x58]\n"
	"\tstr r1, [r4, #4]\n"
	"\tldrb r1, [r0, #4]\n"
	"\tcmp r1, #1\n"
	"\tbne _0800D0E4\n"
	"\tstrb r1, [r4, #0xb]\n"
	"\tmovs r0, #0xf0\n"
	"\tldr r2, _0800D0DC @ =gUnknown_02002882\n"
	"\tstrh r0, [r2]\n"
	"\tldr r3, _0800D0E0 @ =gUnknown_02002880\n"
	"\tstrh r1, [r3]\n"
	"\tb _0800D0F6\n"
	"\t.align 2, 0\n"
"_0800D0B0: .4byte gUnknown_02002858\n"
"_0800D0B4: .4byte gUnknown_0202C610\n"
"_0800D0B8: .4byte gMain+0x74\n"
"_0800D0BC: .4byte gUnknown_0202C550\n"
"_0800D0C0: .4byte gUnknown_0201B178\n"
"_0800D0C4: .4byte gUnknown_0202BEBC\n"
"_0800D0C8: .4byte gUnknown_0201C18C\n"
"_0800D0CC: .4byte gUnknown_02002884\n"
"_0800D0D0: .4byte gUnknown_02002885\n"
"_0800D0D4: .4byte gUnknown_0202C588\n"
"_0800D0D8: .4byte gMain\n"
"_0800D0DC: .4byte gUnknown_02002882\n"
"_0800D0E0: .4byte gUnknown_02002880\n"
"_0800D0E4:\n"
	"\tmov r4, r8\n"
	"\tstrb r3, [r4, #0xb]\n"
	"\tldr r0, _0800D178 @ =gUnknown_02002882\n"
	"\tstrh r2, [r0]\n"
	"\tmovs r1, #1\n"
	"\trsbs r1, r1, #0\n"
	"\tadds r0, r1, #0\n"
	"\tldr r2, _0800D17C @ =gUnknown_02002880\n"
	"\tstrh r0, [r2]\n"
"_0800D0F6:\n"
	"\tldr r4, _0800D180 @ =gUnknown_02002858\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, [r4, #4]\n"
	"\tldrb r2, [r4, #0xb]\n"
	"\tbl sub_F3DC\n"
	"\tadds r3, r0, #0\n"
	"\tstr r3, [r4, #0xc]\n"
	"\tmovs r0, #1\n"
	"\trsbs r0, r0, #0\n"
	"\tcmp r3, r0\n"
	"\tbeq _0800D14A\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, [r4, #4]\n"
	"\tldrb r2, [r4, #0xb]\n"
	"\tbl sub_F434\n"
	"\tmovs r7, #0\n"
	"\tldr r5, _0800D184 @ =gUnknown_0202C610\n"
	"\tadds r3, r4, #0\n"
	"\tldr r6, _0800D188 @ =gUnknown_0201A500\n"
	"\tadds r4, r6, #0\n"
"_0800D122:\n"
	"\tlsls r2, r7, #2\n"
	"\tldr r1, [r3, #0xc]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #3\n"
	"\tadds r2, r2, r0\n"
	"\tldrb r1, [r3, #0xb]\n"
	"\tlsls r0, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #6\n"
	"\tadds r2, r2, r0\n"
	"\tadds r2, r2, r5\n"
	"\tldm r4!, {r0}\n"
	"\tstr r0, [r2]\n"
	"\tadds r7, #1\n"
	"\tcmp r7, #3\n"
	"\tble _0800D122\n"
	"\tldr r1, _0800D180 @ =gUnknown_02002858\n"
	"\tldr r0, [r6]\n"
	"\tstrh r0, [r1, #0x16]\n"
"_0800D14A:\n"
	"\tbl sub_FD20\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r3, r0, #0x18\n"
	"\tcmp r3, #1\n"
	"\tbne _0800D1A8\n"
	"\tldr r0, _0800D18C @ =gUnknown_0202BEB0\n"
	"\tmovs r2, #0\n"
	"\tldrsb r2, [r0, r2]\n"
	"\tcmp r2, #0\n"
	"\tbne _0800D1A0\n"
	"\tldr r0, _0800D190 @ =gUnknown_0201C18C\n"
	"\tstrb r3, [r0]\n"
	"\tldr r1, _0800D194 @ =gUnknown_0201A4B8\n"
	"\tmovs r0, #0xb8\n"
	"\tstrh r0, [r1]\n"
	"\tldr r0, _0800D198 @ =gUnknown_0202C580\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, _0800D19C @ =gUnknown_0202BED4\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, _0800D180 @ =gUnknown_02002858\n"
	"\tstrb r3, [r0, #0xa]\n"
	"\tb _0800D1DA\n"
	"\t.align 2, 0\n"
"_0800D178: .4byte gUnknown_02002882\n"
"_0800D17C: .4byte gUnknown_02002880\n"
"_0800D180: .4byte gUnknown_02002858\n"
"_0800D184: .4byte gUnknown_0202C610\n"
"_0800D188: .4byte gUnknown_0201A500\n"
"_0800D18C: .4byte gUnknown_0202BEB0\n"
"_0800D190: .4byte gUnknown_0201C18C\n"
"_0800D194: .4byte gUnknown_0201A4B8\n"
"_0800D198: .4byte gUnknown_0202C580\n"
"_0800D19C: .4byte gUnknown_0202BED4\n"
"_0800D1A0:\n"
	"\tldr r1, _0800D1A4 @ =gUnknown_0201C18C\n"
	"\tb _0800D1AA\n"
	"\t.align 2, 0\n"
"_0800D1A4: .4byte gUnknown_0201C18C\n"
"_0800D1A8:\n"
	"\tldr r1, _0800D1B8 @ =gUnknown_0202BEB0\n"
"_0800D1AA:\n"
	"\tmovs r0, #0\n"
	"\tstrb r0, [r1]\n"
	"\tldr r1, _0800D1BC @ =gUnknown_02002858\n"
	"\tmovs r0, #2\n"
	"\tstrb r0, [r1, #0xa]\n"
	"\tb _0800D1DA\n"
	"\t.align 2, 0\n"
"_0800D1B8: .4byte gUnknown_0202BEB0\n"
"_0800D1BC: .4byte gUnknown_02002858\n"
"_0800D1C0:\n"
	"\tmov r4, r8\n"
	"\tstrb r3, [r4, #0xb]\n"
	"\tldr r0, _0800D200 @ =gUnknown_02002882\n"
	"\tstrh r2, [r0]\n"
	"\tmovs r1, #1\n"
	"\trsbs r1, r1, #0\n"
	"\tadds r0, r1, #0\n"
	"\tldr r2, _0800D204 @ =gUnknown_02002880\n"
	"\tstrh r0, [r2]\n"
	"\tbl sub_E464\n"
	"\tmovs r0, #3\n"
	"\tstrb r0, [r4, #0xa]\n"
"_0800D1DA:\n"
	"\tldr r2, _0800D208 @ =gMain\n"
	"\tldr r0, _0800D200 @ =gUnknown_02002882\n"
	"\tldrh r1, [r0]\n"
	"\tmovs r3, #0xbd\n"
	"\tlsls r3, r3, #2\n"
	"\tadds r0, r2, r3\n"
	"\tstrh r1, [r0]\n"
	"\tmovs r4, #0xbc\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r0, r2, r4\n"
	"\tstrh r1, [r0]\n"
	"\tpop {r3, r4, r5}\n"
	"\tmov r8, r3\n"
	"\tmov sb, r4\n"
	"\tmov sl, r5\n"
	"\tpop {r4, r5, r6, r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0800D200: .4byte gUnknown_02002882\n"
"_0800D204: .4byte gUnknown_02002880\n"
"_0800D208: .4byte gMain");
}

void sub_D20C(void)
{
    u16 temp;
    switch(gUnknown_0202BED4)
    {
        case 0:
            if(gUnknown_02002858.unk18 == 3)
            {
                m4aSongNumStart(0x11);
                gUnknown_0202BED4++;
            }
            break;
        case 1:
            gUnknown_0201A4B8 -= 1;

            // NOTE: FAKEMATCH - Seth
            temp = gUnknown_02002858.unk18;
            if((gUnknown_02002858.unk18 & 3) == 0)
            {
                gUnknown_0202C580++;
                if(gUnknown_0202C580 > 4)
                {
                    gUnknown_0202C580 = 0;
                }
            }
            if(gUnknown_0201A4B8 == 0x50)
            {
                gUnknown_0202C580 = 0;
                gUnknown_0202BED4++;
            }
            break;
        case 2:
            if(gMain.newKeys & (A_BUTTON | B_BUTTON))
            {
                gUnknown_0202C580 = 0;
                gUnknown_0202BED4++;
            }
            break;
        case 3:
            gUnknown_0201A4B8 -= 4;         
            if(gUnknown_0201A4B8 < -0x18)
            {
                gUnknown_02002858.unk18 = 0;
                gUnknown_0202BEB0 = 1;
                gUnknown_0201C18C = 0;
                gMain.subState = 2;
            }
            break;
    }

    gUnknown_02002858.unk18 += 1;
    sub_E860();
}

void sub_D308(void)
{
    if(!gUnknown_02002858.unk1A)
    {
        if(gUnknown_02002858.unkC == 0)
        {
            m4aSongNumStart(0x14A);
            gUnknown_02002858.unk18 = 0xA0;
        }
        else if(gUnknown_02002858.unkC == -1)
        {
            gUnknown_02002858.unk18 = 999;
            gUnknown_02002858.unk1A = 0;
            m4aSongNumStart(MUS_HI_SCORE);
            gMain.subState = 3;
        }
        else
        {
            m4aSongNumStart(0x14b);
            gUnknown_02002858.unk18 = 0x5A;
        }
    }
    gUnknown_02002858.unk14++;
    if(gUnknown_02002858.unk14 > 8)
    {
        gUnknown_02002858.unk14 = 0;
        if(!gUnknown_02002858.unk12)
        {
            gUnknown_02002858.unk12 = 1;
            sub_10618(6 - (gUnknown_02002858.unkB << 1), gUnknown_08079870[gUnknown_02002858.unkC] + (gUnknown_02002858.unkB << 5), 0, 0x15, 4, 2);
            sub_10618(0, 0x17, 6 - (gUnknown_02002858.unkB << 1), gUnknown_08079870[gUnknown_02002858.unkC] + (gUnknown_02002858.unkB << 5), 4, 2);
        }
        else
        {
            gUnknown_02002858.unk12 = 0;
            sub_10618(0, 0x15, 6 - (gUnknown_02002858.unkB << 1), gUnknown_08079870[gUnknown_02002858.unkC] + (gUnknown_02002858.unkB << 5), 4, 2);
        }
    }
    gUnknown_02002858.unk1E++;
    if(gUnknown_02002858.unk1E > 8)
    {
        gUnknown_02002858.unk1E = 0;
        sub_F8B0(gUnknown_02002858.unkB, gUnknown_02002858.unkC, gUnknown_02002858.unk1C);
        gUnknown_02002858.unk1C++;
        if( gUnknown_02002858.unk1C > 2)
        {
            gUnknown_02002858.unk1C = 0;
        }
    }

    gUnknown_02002858.unk1A++;
    if(gUnknown_02002858.unk1A > gUnknown_02002858.unk18)
    {
        gUnknown_02002858.unk1A = 0;
        if(gUnknown_02002858.unk12 == 1)
        {
            gUnknown_02002858.unk12 = 0;
            gUnknown_02002858.unk14 = 0;
            sub_10618(0, 0x15, 6 - (gUnknown_02002858.unkB << 1), gUnknown_08079870[gUnknown_02002858.unkC] +(gUnknown_02002858.unkB << 5), 4, 2);
        }
        m4aSongNumStart(MUS_HI_SCORE);
        gMain.subState = 4;
    }

    DmaCopy16(3, gUnknown_03005C00, 0x6000000, 0x1000);
}

void sub_D4B8(void)
{
    sub_E464();
    if(!(gMain.systemFrameCount % 0xC))
    {
        gUnknown_02002858.unk1A = 1 - gUnknown_02002858.unk1A;
        gUnknown_02002858.unk25 = 1 - gUnknown_02002858.unk25;
    }
    if(gMain.newKeys & DPAD_LEFT)
    {
         if(gUnknown_02002880 != -1)
         {
             gUnknown_02002880 = -1;
         }
    }
    else if(gMain.newKeys & DPAD_RIGHT)
    {
        if(gUnknown_02002880 != 1)
         {
             gUnknown_02002880 = 1;
         }
    }
    if(gUnknown_02002880 > 0)
    {
        if(gUnknown_02002882 < 0xF0)
            gUnknown_02002882 += 8;
    }
    else if(gUnknown_02002880 < 0)
    {
        if(gUnknown_02002882 > 0)
            gUnknown_02002882 -= 8; 
    }
    if(gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        m4aSongNumStart(0x66);
        gMain.subState = 0xb;
    }
    if(gMain.newKeys & START_BUTTON)
    {
        if(gUnknown_02002882 == 0 || (gUnknown_02002882 == 0xF0))
        {
            m4aSongNumStart(0x68);
            gUnknown_0201B178 = 1;
            gUnknown_0202BEBC = 0;
            gMain.subState = 5;
        }
    }

    if((gMain.heldKeys & (L_BUTTON | DPAD_LEFT)) == (L_BUTTON | DPAD_LEFT))
    {
        if(gMain.newKeys & R_BUTTON)
        {
            if(gUnknown_02002882 == 0 || gUnknown_02002882 == 0xF0)
            {
                gUnknown_02002884 = 0x28;
                gUnknown_02002885++;
                if(gUnknown_02002885 == 3)
                {
                    gUnknown_02002885 = 0;
                    gUnknown_02002884 = 0;
                    m4aSongNumStart(0x68);
                    gUnknown_0201B178 = 1;
                    gUnknown_0202BEBC = 4;
                    gMain.subState = 0xA;
                }
            }
            if(gUnknown_02002884 > 0)
            {
                gUnknown_02002884--;  
                if(gUnknown_02002884 <= 0)
                {
                    gUnknown_02002884 = 0;
                    gUnknown_02002885 = 0;
                }
            }  
        }
    }
    else if(gUnknown_02002884 > 0)
    {
        gUnknown_02002884--;  
        if(gUnknown_02002884 <= 0)
        {
            gUnknown_02002884 = 0;
            gUnknown_02002885 = 0;
        }
    }        

    gMain.unk2E8[3].unk0 = gUnknown_02002882;
    gMain.unk2E8[2].unk0 = gUnknown_02002882;
}

void sub_D664(void)
{
    int i, j, k;

    sub_E3A8();
    if (++gUnknown_02002858.unk14 > 12)
    {
        gUnknown_02002858.unk14 = 0;
        gUnknown_02002858.unk12 = 1 - gUnknown_02002858.unk12;
    }

    if (++gUnknown_02002858.unk1E > 8)
    {
        gUnknown_02002858.unk1E = 0;
        sub_F8B0(gUnknown_02002858.unkB, gUnknown_02002858.unkC, gUnknown_02002858.unk1C);
        if (++gUnknown_02002858.unk1C > 2)
            gUnknown_02002858.unk1C = 0;
    }

    if (gMain.heldKeys & DPAD_DOWN)
    {
        if (gUnknown_02002858.unk20 == 0)
        {
            m4aSongNumStart(0x6B);
            if (--gUnknown_02002858.unk16 < 0)
                gUnknown_02002858.unk16 = 41;
            
            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_02002858.unk20 = 9;
        }
    }
    else if (gMain.heldKeys & DPAD_UP)
    {
        if (gUnknown_02002858.unk20 == 0)
        {
            m4aSongNumStart(0x6B);
            if (++gUnknown_02002858.unk16 > 41)
                gUnknown_02002858.unk16 = 0;
            
            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_02002858.unk20 = 9;
        }
    }

    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (gUnknown_02002858.unk10 == HIGH_SCORE_NAME_LENGTH - 1)
        {
            m4aSongNumStart(0x8A);
        }
        else
        {
            m4aSongNumStart(0x67);
            gUnknown_02002858.unk12 = 1;
            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10] = gUnknown_02002858.unk16;
            gUnknown_02002858.unk10++;
            gUnknown_02002858.unk16 = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10];
        }
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        if (gUnknown_02002858.unk10 == 0)
        {
            m4aSongNumStart(0x8A);
        }
        else
        {
            m4aSongNumStart(0x67);
            gUnknown_02002858.unk12 = 1;
            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10] = gUnknown_02002858.unk16;
            gUnknown_02002858.unk10--;
            gUnknown_02002858.unk16 = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10];
        }
    }

    if (gMain.newKeys & A_BUTTON)
    {
        gUnknown_02002858.unk12 = 1;
        sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
        gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10] = gUnknown_02002858.unk16;
        if (gUnknown_02002858.unk10 == HIGH_SCORE_NAME_LENGTH - 1)
        {
            m4aSongNumStart(0x65);
            sub_FAE8(gUnknown_02002858.unkB, gUnknown_02002858.unkC, gUnknown_02002858.unk1C);
            for (i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
                gUnknown_0201A500[i] = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[i];

            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < NUM_HIGH_SCORES; j++)
                {
                    for (k = 0; k < 6; k++)
                        gMain_saveData.highScores[i][j].data.raw[k] = gUnknown_0202C610[i][j].data.raw[k];
                }
            }

            SaveFile_WriteToSram();
            gMain.subState = 3;
        }
        else
        {
            m4aSongNumStart(0x6A);
            gUnknown_02002858.unk10++;
            gUnknown_02002858.unk16 = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10];
        }
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        if (gUnknown_02002858.unk10 == 0)
        {
            m4aSongNumStart(0x8A);
        }
        else
        {
            m4aSongNumStart(0x6A);
            gUnknown_02002858.unk12 = 1;
            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10] = gUnknown_02002858.unk16;
            gUnknown_02002858.unk10--;
            gUnknown_02002858.unk16 = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10];
        }
    }

    DmaCopy16(3, gUnknown_03005C00, 0x6000000, 0x1000);
    if (gUnknown_02002858.unk20 > 0)
        gUnknown_02002858.unk20--;
}

void sub_D9F8(void)
{
    sub_19B4();
    sub_E908();
    gUnknown_0201B124 = 0;
    sub_E464();
    gMain.subState = 6;
}

void sub_DA20(void)
{
    sub_E464();
    if (gMain.newKeys & B_BUTTON)
    {
        m4aSongNumStart(0x66);
        gUnknown_0201B178 = 0;
        gUnknown_0202BEBC = 0;
        sub_2568();
        gMain.subState = 3;
    }
    else
    {
        gUnknown_0202ADD0 = sub_1B04(&gUnknown_0202BEC8, gUnknown_0202C5F0, gUnknown_0201A4D0);
        gUnknown_0202BDF0 = gUnknown_0202ADD0 & 3;
        gUnknown_0201C1AC = (gUnknown_0202ADD0 & 0x1c) >> 2;
        gUnknown_0202ADDC = (gUnknown_0202ADD0 & 0xe00) >> 9;
        if (((gUnknown_0202ADD0 & 0x40) != 0) && gUnknown_0202BDF0 < 2)
        {
            sub_E970();
            if ((gUnknown_0202ADD0 & 0x100) == 0)
            {
                s16 var0 = sub_E94C();
                if (var0 == -1)
                {
                    gMain.subState = 8;
                }
                else if (var0 == 1)
                {
                    gUnknown_0202BEBC = 2;
                    gMain.subState = 7;
                    m4aSongNumStart(0x8A);
                }
            }

            gUnknown_0201A510++;
            if ((gUnknown_0202ADD0 & 0x7f0000) != 0 && gUnknown_0202ADE4 == -1 && ++gUnknown_0201A444 > 180)
            {
                gUnknown_0202BEBC = 2;
                gMain.subState = 7;
                m4aSongNumStart(0x8A);
            }
        }
    }
}

void sub_DB4C(void)
{
    if (++gUnknown_0201A444 > 2)
    {
        gUnknown_0201A444 = 0;
        gMain.subState = 5;
    }
}

void sub_DB70(void)
{
    int i, j;

    sub_E464();
    if (++gUnknown_02002858.unk22 > 90)
    {
        gUnknown_02002858.unk22 = 0;
        gUnknown_0201B178 = 0;
        gUnknown_0202BEBC = 0;
        sub_2568();
        sub_1AA4();
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 6; j++)
            {
                gUnknown_0202C550[i].data.raw[j] = gUnknown_0202C610[i][0].data.raw[j];
            }
        }
        sub_02B4();
        m4aMPlayAllStop();
        sub_0D10();
        gMain.subState = 0;
    }
}
