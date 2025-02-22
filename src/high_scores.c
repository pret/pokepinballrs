#include "global.h"
#include "functions.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"
#include "constants/bg_music.h"
#include "constants/fields.h"

extern StateFunc gHighScoresStateFuncs[15];
extern StateFunc gIdleHighScoresStateFuncs[15];
extern u8 gUnknown_0809DBE0[];
extern u8 gUnknown_08099FC0[];
extern u8 gUnknown_080957A0[];
extern s16 gUnknown_0202C588;
extern s8 gUnknown_0202BEB0;
extern s8 gUnknown_0201C18C;
extern s16 gUnknown_0201A4B8;
extern s8 gUnknown_0202BED4;
extern s8 gUnknown_0202C580;
extern s8 gUnknown_0201B178;
extern u8 gUnknown_0202BEBC;
extern u16 gUnknown_0201C1B0;
extern u16 gUnknown_0202C59C;
extern s8 gUnknown_0201A4BC;
extern s8 gUnknown_0202C598;
extern s8 gUnknown_0202C54C;

extern s16 gUnknown_02002880;
extern s16 gUnknown_02002882;
extern s8 gUnknown_02002884;
extern s8 gUnknown_02002885;

struct unkStruct_2002858
{
    u32 unk0;
    u32 unk4;
    s16 unk8;
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
    s8 unk24;
    u8 unk25;
    s8 unk26;
};

struct unkStruct_2002858 gUnknown_02002858;

extern struct HighScoreEntry gUnknown_0202C610[MAIN_FIELD_COUNT][NUM_HIGH_SCORES];
extern struct HighScoreEntry gUnknown_0202C550[2];
extern u8 gUnknown_0809AFC0[];
extern u8 gUnknown_080947A0[];
extern u8 gUnknown_0809DDE0[];
extern u8 gUnknown_0809DFE0[];
extern u32 gUnknown_08079870[8];
extern const struct HighScoreEntry gUnknown_08079430[2][8];

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

void sub_CFD4(void)
{
    int i, j, k;
    for(i = 0; i < MAIN_FIELD_COUNT; i++)
    {
        for(j = 0; j < NUM_HIGH_SCORES; j++) 
        {
            for(k = 0; k < HIGH_SCORE_NAME_LENGTH + 2; k++) // ? use an array count instead?
                gUnknown_0202C610[i][j].data.raw[k] = gMain_saveData.highScores[i][j].data.raw[k];
        }
    }
    for(i = 0; i < MAIN_FIELD_COUNT; i++)
    {
        for(j = 0; j <  HIGH_SCORE_NAME_LENGTH + 2; j++)
        {
            gUnknown_0202C550[i].data.raw[j] = gUnknown_0202C610[i][0].data.raw[j];
        }
    }
    gUnknown_02002858.unk10 = 0;
    gUnknown_02002858.unk12 = 0;
    gUnknown_02002858.unk14 = 0;
    gUnknown_02002858.unk18 = 0;
    gUnknown_02002858.unk1A = 0;
    gUnknown_02002858.unk1E = 0;
    gUnknown_02002858.unk1C = 0;
    gUnknown_02002858.unk20 = 0;
    gUnknown_02002858.unk22 = 0;
    gUnknown_02002858.unk25 = 0;
    gUnknown_02002858.unk26 = 1;
    gUnknown_0201B178 = 0;
    gUnknown_0202BEBC = 1;
    gUnknown_0201C18C = 0;
    gUnknown_02002884 = 0;
    gUnknown_02002885 = 0;
    if(gUnknown_0202C588 == 1)
    {
        gUnknown_02002858.unk0 = gMain.unk5C;
        gUnknown_02002858.unk4 = gMain.unk58;
        if(gMain.selectedField == FIELD_SAPPHIRE)
        {
            gUnknown_02002858.unkB = 1;
            gUnknown_02002882 = 0xF0;
            gUnknown_02002880 = 1;
        }
        else
        {
            gUnknown_02002858.unkB = 0;
            gUnknown_02002882 = 0;
            gUnknown_02002880 = -1;
        }
        gUnknown_02002858.unkC = GetNewHighScoreIndex(gUnknown_02002858.unk0, gUnknown_02002858.unk4, gUnknown_02002858.unkB);
        if(gUnknown_02002858.unkC != -1)
        {
            sub_F434(gUnknown_02002858.unk0, gUnknown_02002858.unk4, gUnknown_02002858.unkB, gUnknown_02002858.unkC);
            for(i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
            {
                gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[i] = gUnknown_0201A500[i];
            }
            gUnknown_02002858.unk16 = gUnknown_0201A500[0];
        }
        if(sub_FD20() == 1)
        {
            if(gUnknown_0202BEB0 == 0)
            {
                gUnknown_0201C18C = 1;
                gUnknown_0201A4B8 = 0xB8;
                gUnknown_0202C580 = 0;
                gUnknown_0202BED4 = 0;
                gUnknown_02002858.unkA = 1;
            }
            else
            {
                gUnknown_0201C18C = 0;
                gUnknown_02002858.unkA = 2;
            }
        }
        else
        {
            gUnknown_0202BEB0 = 0;
            gUnknown_02002858.unkA = 2;
        }
    }
    else
    {
        gUnknown_02002858.unkB = 0;
        gUnknown_02002882 = 0;
        gUnknown_02002880 = -1;
        sub_E464();
        gUnknown_02002858.unkA = 3;
    }
    gMain.bgOffsets[3].xOffset = gUnknown_02002882;
    gMain.bgOffsets[2].xOffset = gUnknown_02002882;
}

void sub_D20C(void)
{
    u16 temp;
    switch(gUnknown_0202BED4)
    {
        case 0:
            if(gUnknown_02002858.unk18 == 3)
            {
                m4aSongNumStart(MUS_SUCCESS);
                gUnknown_0202BED4++;
            }
            break;
        case 1:
            gUnknown_0201A4B8 -= 1;

            // TODO: FAKEMATCH - Seth
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
            if(JOY_NEW(A_BUTTON | B_BUTTON))
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
            m4aSongNumStart(SE_UNKNOWN_0x14A);
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
            m4aSongNumStart(SE_UNKNOWN_0x14B);
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
    if(JOY_NEW(DPAD_LEFT))
    {
         if(gUnknown_02002880 != -1)
         {
             gUnknown_02002880 = -1;
         }
    }
    else if(JOY_NEW(DPAD_RIGHT))
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
    if(JOY_NEW(A_BUTTON | B_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x66);
        gMain.subState = 0xb;
    }
    if(JOY_NEW(START_BUTTON))
    {
        if(gUnknown_02002882 == 0 || (gUnknown_02002882 == 0xF0))
        {
            m4aSongNumStart(SE_UNKNOWN_0x68);
            gUnknown_0201B178 = 1;
            gUnknown_0202BEBC = 0;
            gMain.subState = 5;
        }
    }

    if(JOY_HELD(L_BUTTON | DPAD_LEFT) == (L_BUTTON | DPAD_LEFT))
    {
        if(JOY_NEW(R_BUTTON))
        {
            if(gUnknown_02002882 == 0 || gUnknown_02002882 == 0xF0)
            {
                gUnknown_02002884 = 0x28;
                gUnknown_02002885++;
                if(gUnknown_02002885 == 3)
                {
                    gUnknown_02002885 = 0;
                    gUnknown_02002884 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x68);
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

    gMain.bgOffsets[3].xOffset = gUnknown_02002882;
    gMain.bgOffsets[2].xOffset = gUnknown_02002882;
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

    if (JOY_HELD(DPAD_DOWN))
    {
        if (gUnknown_02002858.unk20 == 0)
        {
            m4aSongNumStart(SE_UNKNOWN_0x6B);
            if (--gUnknown_02002858.unk16 < 0)
                gUnknown_02002858.unk16 = 41;

            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_02002858.unk20 = 9;
        }
    }
    else if (JOY_HELD(DPAD_UP))
    {
        if (gUnknown_02002858.unk20 == 0)
        {
            m4aSongNumStart(SE_UNKNOWN_0x6B);
            if (++gUnknown_02002858.unk16 > 41)
                gUnknown_02002858.unk16 = 0;

            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_02002858.unk20 = 9;
        }
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (gUnknown_02002858.unk10 == HIGH_SCORE_NAME_LENGTH - 1)
        {
            m4aSongNumStart(SE_FAILURE);
        }
        else
        {
            m4aSongNumStart(SE_SELECT);
            gUnknown_02002858.unk12 = 1;
            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10] = gUnknown_02002858.unk16;
            gUnknown_02002858.unk10++;
            gUnknown_02002858.unk16 = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10];
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gUnknown_02002858.unk10 == 0)
        {
            m4aSongNumStart(SE_FAILURE);
        }
        else
        {
            m4aSongNumStart(SE_SELECT);
            gUnknown_02002858.unk12 = 1;
            sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
            gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10] = gUnknown_02002858.unk16;
            gUnknown_02002858.unk10--;
            gUnknown_02002858.unk16 = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10];
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        gUnknown_02002858.unk12 = 1;
        sub_F670(gUnknown_02002858.unk16, gUnknown_02002858.unkC, gUnknown_02002858.unk10, gUnknown_02002858.unkB);
        gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10] = gUnknown_02002858.unk16;
        if (gUnknown_02002858.unk10 == HIGH_SCORE_NAME_LENGTH - 1)
        {
            m4aSongNumStart(SE_UNKNOWN_0x65);
            sub_FAE8(gUnknown_02002858.unkB, gUnknown_02002858.unkC, gUnknown_02002858.unk1C);
            for (i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
                gUnknown_0201A500[i] = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[i];

            for (i = 0; i < MAIN_FIELD_COUNT; i++)
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
            m4aSongNumStart(SE_UNKNOWN_0x6A);
            gUnknown_02002858.unk10++;
            gUnknown_02002858.unk16 = gUnknown_0202C610[gUnknown_02002858.unkB][gUnknown_02002858.unkC].data.parts.name[gUnknown_02002858.unk10];
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if (gUnknown_02002858.unk10 == 0)
        {
            m4aSongNumStart(SE_FAILURE);
        }
        else
        {
            m4aSongNumStart(SE_UNKNOWN_0x6A);
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
    if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x66);
        gUnknown_0201B178 = 0;
        gUnknown_0202BEBC = 0;
        sub_2568();
        gMain.subState = 3;
    }
    else
    {
        gUnknown_0202ADD0 = LinkMain1(&gUnknown_0202BEC8, gUnknown_0202C5F0, gUnknown_0201A4D0);
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
                    m4aSongNumStart(SE_FAILURE);
                }
            }

            gUnknown_0201A510++;
            if ((gUnknown_0202ADD0 & 0x7f0000) != 0 && gUnknown_0202ADE4 == -1 && ++gUnknown_0201A444 > 180)
            {
                gUnknown_0202BEBC = 2;
                gMain.subState = 7;
                m4aSongNumStart(SE_FAILURE);
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
        DisableSerial();
        for (i = 0; i < MAIN_FIELD_COUNT; i++)
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

void sub_DBF4(void)
{
    int i, j, k;

    sub_E464();
    switch (gUnknown_02002858.unk22)
    {
    case 4:
        sub_2568();
        DisableSerial();
        break;
    case 130:
        gUnknown_0202BEBC = 3;
        m4aSongNumStart(SE_UNKNOWN_0x65);
        break;
    case 250:
        gUnknown_02002858.unk22 = 0;
        gUnknown_0201B178 = 0;
        gUnknown_0202BEBC = 0;
        gUnknown_0202BED8 = sub_F4FC(0);
        gUnknown_0201B170 = sub_F4FC(1);
        for (i = 0; i < MAIN_FIELD_COUNT; i++)
        {
            for (j = 0; j < NUM_HIGH_SCORES; j++)
            {
                for (k = 0; k < 6; k++)
                {
                    gMain_saveData.highScores[i][j].data.raw[k] = gUnknown_0202C610[i][j].data.raw[k];
                }
            }
        }
        SaveFile_WriteToSram();
        sub_02B4();
        m4aMPlayAllStop();
        sub_0D10();
        gMain.subState = 12;
        break;
    }

    gUnknown_02002858.unk22++;
}

void sub_DCF0(void)
{
    sub_E464();
    if (JOY_NEW(A_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x65);
        SetDefaultHighScores();
        SaveFile_WriteToSram();
        sub_02B4();
        m4aMPlayAllStop();
        sub_0D10();
        gMain.subState = 0;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x66);
        gUnknown_0201B178 = 0;
        gUnknown_0202BEBC = 0;
        gMain.subState = 3;
    }
}

void sub_DD4C(void)
{
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(STATE_TITLE);
}

void sub_DD70(void)
{
    ResetSomeGraphicsRelatedStuff();
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_FORCED_BLANK;
    REG_BG2CNT = 0x4006;
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = 0x420F;
    REG_DISPCNT |= DISPCNT_BG3_ON;
    gMain.unk16 = REG_DISPCNT;
    DmaCopy16(3, gUnknown_0809DBE0, (void*) PLTT, 0x200);
    DmaCopy16(3, gUnknown_080957A0, (void*) BG_VRAM + 0x4000, 0x4800);
    DmaCopy16(3, gUnknown_0809AFC0, (void *)BG_VRAM + 0xC000, 0x2C00);
    DmaCopy16(3, gUnknown_080947A0, gUnknown_03005C00, 0x1000);
    DmaCopy16(3, gUnknown_08099FC0, (void *)BG_SCREEN_ADDR(2), 0x1000);
    DmaCopy16(3, gUnknown_0809DDE0, (void *)OBJ_PLTT, 0x20);
    DmaCopy16(3, gUnknown_0809DFE0, (void *)OBJ_VRAM0, 0x4420);
    sub_DEB4();
    sub_EE64();
    DmaCopy16(3, gUnknown_03005C00,0x6000000, 0x1000);
    m4aSongNumStart(MUS_HI_SCORE);
    sub_0CBC();
    sub_024C();
    gMain.subState++;
}

void sub_DEB4(void)
{
    int i, j, k;

    for (i = 0; i < MAIN_FIELD_COUNT; i++)
    {
        for (j = 0; j < NUM_HIGH_SCORES; j++)
        {
            for (k = 0; k < 6; k++)
            {
                gUnknown_0202C610[i][j].data.raw[k] = gMain_saveData.highScores[i][j].data.raw[k];
            }
        }
    }

    gUnknown_02002858.unk8 = 0;
    gUnknown_02002858.unk1E = 0;
    gUnknown_02002858.unk1C = 0;
    gUnknown_02002858.unkB = 0;
    gUnknown_02002882 = 0;
    gUnknown_02002880 = -1;
    gUnknown_02002858.unk24 = STATE_INTRO;
    gUnknown_02002858.unkA = 0;
    gMain.bgOffsets[3].xOffset = gUnknown_02002882;
    gMain.bgOffsets[2].xOffset = gUnknown_02002882;
}

void sub_DF68(void)
{
    switch (gUnknown_02002858.unkA)
    {
    case 0:
        if (++gUnknown_02002858.unk1E > 8)
        {
            gUnknown_02002858.unk1E = 0;
            sub_F8B0(0, 0, gUnknown_02002858.unk1C);
            if (++gUnknown_02002858.unk1C > 2)
                gUnknown_02002858.unk1C = 0;
        }
        if (gUnknown_02002858.unk8 > 600)
        {
            gUnknown_02002858.unk8 = 0;
            gUnknown_02002858.unk1E = 0;
            gUnknown_02002858.unk1C = 0;
            gUnknown_02002858.unkA = 1;
        }
        break;
    case 1:
        gUnknown_02002882 += 8;
        if (gUnknown_02002882 >= 240)
        {
            gUnknown_02002858.unk8 = 0;
            gUnknown_02002858.unkA = 2;
        }
        gMain.bgOffsets[3].xOffset = gUnknown_02002882;
        gMain.bgOffsets[2].xOffset = gUnknown_02002882;
        break;
    case 2:
        if (++gUnknown_02002858.unk1E > 8)
        {
            gUnknown_02002858.unk1E = 0;
            sub_F8B0(1, 0, gUnknown_02002858.unk1C);
            if (++gUnknown_02002858.unk1C > 2)
                gUnknown_02002858.unk1C = 0;
        }
        if (gUnknown_02002858.unk8 > 600)
        {
            gUnknown_02002858.unk8 = 0;
            gUnknown_02002858.unk24 = STATE_INTRO;
            gMain.subState++;
        }
        break;
    }

    gUnknown_02002858.unk8++;
    DmaCopy16(3, gUnknown_03005C00, 0x6000000, 0x1000);

    if (JOY_NEW(START_BUTTON | A_BUTTON | B_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x66);
        gUnknown_02002858.unk24 = STATE_TITLE;
        gMain.subState++;
    }
}

void sub_E0C4(void)
{
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    SetMainGameState(gUnknown_02002858.unk24);
}

void sub_E0EC(void)
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
    DmaCopy16(3, gUnknown_0809DDE0, (void *)OBJ_PLTT, 0x20);
    DmaCopy16(3, gUnknown_0809DFE0, (void *)OBJ_VRAM0, 0x4420);
    sub_DEB4();
    sub_EE64();
    DmaCopy16(3, gUnknown_03005C00,0x6000000, 0x1000);
    m4aSongNumStart(MUS_HI_SCORE);
    sub_0CBC();
    sub_024C();
    gMain.subState++;
}

void sub_E230(void)
{
    switch (gUnknown_02002858.unkA)
    {
    case 0:
        if (gUnknown_0202BED8 != -1)
        {
            if (++gUnknown_02002858.unk1E > 8)
            {
                gUnknown_02002858.unk1E = 0;
                sub_F8B0(0, gUnknown_0202BED8, gUnknown_02002858.unk1C);
                if (++gUnknown_02002858.unk1C > 2)
                    gUnknown_02002858.unk1C = 0;
            }
        }
        if (gUnknown_02002858.unk8 > 120)
        {
            gUnknown_02002858.unk8 = 0;
            gUnknown_02002858.unk1E = 0;
            gUnknown_02002858.unk1C = 0;
            gUnknown_02002858.unkA = 1;
        }
        break;
    case 1:
        gUnknown_02002882 += 8;
        if (gUnknown_02002882 >= 240)
        {
            gUnknown_02002858.unk8 = 0;
            gUnknown_02002858.unkA = 2;
        }
        gMain.bgOffsets[3].xOffset = gUnknown_02002882;
        gMain.bgOffsets[2].xOffset = gUnknown_02002882;
        break;
    case 2:
        if (gUnknown_0201B170 != -1)
        {
            if (++gUnknown_02002858.unk1E > 8)
            {
                gUnknown_02002858.unk1E = 0;
                sub_F8B0(1, gUnknown_0201B170, gUnknown_02002858.unk1C);
                if (++gUnknown_02002858.unk1C > 2)
                    gUnknown_02002858.unk1C = 0;
            }
        }
        if (gUnknown_02002858.unk8 > 120)
        {
            gUnknown_02002858.unk8 = 0;
            gMain.subState++;
        }
        break;
    }

    gUnknown_02002858.unk8++;
    DmaCopy16(3, gUnknown_03005C00, 0x6000000, 0x1000);

    if (JOY_NEW(START_BUTTON | A_BUTTON | B_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x66);
        gMain.subState++;
    }
}

void sub_E390(void)
{
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    SetMainGameState(STATE_SCORES_MAIN);
}

void sub_E3A8(void)
{
    int i;
    struct SpriteGroup *spriteGroup;

    spriteGroup = &gUnknown_0200B3B8[gUnknown_02002858.unk12];
    spriteGroup->available = TRUE;
    LoadSpriteSets(gUnknown_086A7DA8, 2, gUnknown_0200B3B8);

    spriteGroup->baseX = gUnknown_080797F0[gUnknown_02002858.unkB][gUnknown_02002858.unkC].x + gUnknown_02002858.unk10 * 8;
    spriteGroup->baseY = gUnknown_080797F0[gUnknown_02002858.unkB][gUnknown_02002858.unkC].y;
    for (i = 0; i < 2; i++)
    {
        gOamBuffer[spriteGroup->oam[i].oamId].x = spriteGroup->oam[i].xOffset + spriteGroup->baseX;
        gOamBuffer[spriteGroup->oam[i].oamId].y = spriteGroup->oam[i].yOffset + spriteGroup->baseY;
    }

    spriteGroup->available = FALSE;
}

extern s8 gUnknown_0200287D;


#ifdef NONMATCHING
static inline void sub_E464_HELPER(int x, struct SpriteGroup *spriteGroup, struct SpriteGroup *spriteGroup4, struct SpriteGroup *spriteGroup3)
{
    int i;
    const struct SpriteSet *spriteSet;
    register struct OamDataSimple *oamData asm("r4");
    spriteGroup->baseX = x;
    spriteGroup->baseY = 144;
    oamData = &spriteGroup->oam[0];
    gOamBuffer[oamData->oamId].tileNum = gUnknown_02002858.unk1A * 2 + 2;
    gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
    gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
}

// This one is tough. I think there might be an inline function used for the shared logic
// of the two main if statements.
void sub_E464(void)
{
    int i;
    int count;
    register struct SpriteGroup *spriteGroups asm("r6");
    register struct SpriteGroup *spriteGroup1 asm("r4");
    struct SpriteGroup *spriteGroup2;
    struct SpriteGroup *spriteGroup3;
    struct SpriteGroup *spriteGroup4;
    struct SpriteGroup *spriteGroup5;
    register struct unkStruct_2002858 *var1_02002858 asm("r9");
    const struct SpriteSet *spriteSet;
    struct OamDataSimple *oamData;

    spriteGroups = gUnknown_0200B3B8;
    spriteGroup1 = spriteGroups;
    spriteGroup2 = &spriteGroups[1];
    spriteGroup3 = &spriteGroups[(s8)gUnknown_0202BEBC + 2];
    var1_02002858 = &gUnknown_02002858;
    spriteGroup4 = &spriteGroups[gUnknown_0200287D + 7];

    if (gUnknown_02002882 == 0)
    {
        spriteGroups->available = TRUE;
        spriteGroup2->available = FALSE;
        spriteGroup3->available = gUnknown_0201B178;
        spriteGroup4->available = var1_02002858->unk26;
        LoadSpriteSets(gUnknown_086A7DB0, 9, spriteGroups);
        sub_E464_HELPER(220, spriteGroup1, spriteGroup4, spriteGroup3);
        if (spriteGroup4->available == 1)
        {
            spriteGroup4->baseX = 84;
            spriteGroup4->baseY = 150;
            spriteSet = gUnknown_086A7DB0[gUnknown_0200287D + 7];
            for (i = 0; i < spriteSet->count; i++)
            {
                oamData = &spriteGroup4->oam[i];
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup4->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup4->baseY;
            }
        }
        if (spriteGroup3->available == 1)
        {
            switch ((s8)gUnknown_0202BEBC)
            {
            case 0:
            case 4:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 100;
                break;
            default:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 80;
                break;
            }
            spriteSet = gUnknown_086A7DB0[(s8)gUnknown_0202BEBC + 2];
            for (i = 0; i < spriteSet->count; i++)
            {
                oamData = &spriteGroup3->oam[i];
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup3->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup3->baseY;
            }
        }
    }
    else if (gUnknown_02002882 == 240)
    {
        spriteGroup1->available = FALSE;
        spriteGroup2->available = TRUE;
        spriteGroup3->available = gUnknown_0201B178;
        spriteGroup4->available = var1_02002858->unk26;
        LoadSpriteSets(gUnknown_086A7DB0, 2, gUnknown_0200B3B8);
        sub_E464_HELPER(4, spriteGroup2, spriteGroup4, spriteGroup3);
        if (spriteGroup4->available == 1)
    {
        spriteGroup4->baseX = 84;
        spriteGroup4->baseY = 150;
        spriteSet = gUnknown_086A7DB0[gUnknown_0200287D + 7];
        for (i = 0; i < spriteSet->count; i++)
        {
            oamData = &spriteGroup4->oam[i];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup4->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup4->baseY;
        }
    }
    if (spriteGroup3->available == 1)
    {
        switch ((s8)gUnknown_0202BEBC)
        {
        case 0:
        case 4:
            spriteGroup3->baseX = 120;
            spriteGroup3->baseY = 100;
            break;
        default:
            spriteGroup3->baseX = 120;
            spriteGroup3->baseY = 80;
            break;
        }
        spriteSet = gUnknown_086A7DB0[(s8)gUnknown_0202BEBC + 2];
        for (i = 0; i < spriteSet->count; i++)
        {
            oamData = &spriteGroup3->oam[i];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup3->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup3->baseY;
        }
    }
    }
    else
    {
        spriteGroup1->available = FALSE;
        spriteGroup2->available = FALSE;
        LoadSpriteSets(gUnknown_086A7DB0, 9, gUnknown_0200B3B8);
    }

    spriteGroup3->available = FALSE;
    spriteGroup4->available = FALSE;
}
#else
NAKED
void sub_E464(void)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r6, _0800E5CC @ =gUnknown_0200B3B8\n\
	adds r4, r6, #0\n\
	movs r0, #0xb8\n\
	adds r0, r0, r6\n\
	mov sl, r0\n\
	mov r5, sl\n\
	ldr r0, _0800E5D0 @ =gUnknown_0202BEBC\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	movs r2, #0xb8\n\
	adds r1, r0, #0\n\
	muls r1, r2, r1\n\
	movs r3, #0xb8\n\
	lsls r3, r3, #1\n\
	adds r0, r6, r3\n\
	adds r7, r1, r0\n\
	ldr r0, _0800E5D4 @ =gUnknown_02002858\n\
	mov sb, r0\n\
	ldr r1, _0800E5D8 @ =gUnknown_0200287D\n\
	movs r0, #0\n\
	ldrsb r0, [r1, r0]\n\
	adds r1, r0, #0\n\
	muls r1, r2, r1\n\
	movs r2, #0xa1\n\
	lsls r2, r2, #3\n\
	adds r0, r6, r2\n\
	adds r1, r1, r0\n\
	mov r8, r1\n\
	ldr r0, _0800E5DC @ =gUnknown_02002882\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	cmp r1, #0\n\
	beq _0800E4B4\n\
	b _0800E674\n\
_0800E4B4:\n\
	movs r0, #1\n\
	strh r0, [r6]\n\
	strh r1, [r5]\n\
	ldr r0, _0800E5E0 @ =gUnknown_0201B178\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	strh r0, [r7]\n\
	mov r0, sb\n\
	adds r0, #0x26\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
	ldr r0, _0800E5E4 @ =gUnknown_086A7DB0\n\
	movs r1, #9\n\
	adds r2, r6, #0\n\
	bl LoadSpriteSets\n\
	movs r0, #0xdc\n\
	strh r0, [r6, #2]\n\
	movs r0, #0x90\n\
	strh r0, [r6, #4]\n\
	adds r4, #8\n\
	ldr r2, _0800E5E8 @ =gOamBuffer\n\
	mov sl, r2\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, sl\n\
	mov r3, sb\n\
	movs r5, #0x1a\n\
	ldrsh r1, [r3, r5]\n\
	lsls r1, r1, #1\n\
	adds r1, #2\n\
	ldr r3, _0800E5EC @ =0x000003FF\n\
	adds r0, r3, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #4]\n\
	ldr r0, _0800E5F0 @ =0xFFFFFC00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #4]\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, sl\n\
	movs r5, #2\n\
	ldrsh r1, [r4, r5]\n\
	movs r3, #2\n\
	ldrsh r0, [r6, r3]\n\
	adds r1, r1, r0\n\
	ldr r5, _0800E5F4 @ =0x000001FF\n\
	adds r0, r5, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #2]\n\
	ldr r0, _0800E5F8 @ =0xFFFFFE00\n\
	mov ip, r0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sl\n\
	ldrb r0, [r6, #4]\n\
	ldrb r4, [r4, #4]\n\
	adds r0, r0, r4\n\
	strb r0, [r1]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _0800E5AA\n\
	movs r0, #0x54\n\
	strh r0, [r1, #2]\n\
	movs r0, #0x96\n\
	strh r0, [r1, #4]\n\
	ldr r2, _0800E5D8 @ =gUnknown_0200287D\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #7\n\
	lsls r0, r0, #2\n\
	ldr r3, _0800E5E4 @ =gUnknown_086A7DB0\n\
	adds r0, r0, r3\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	bge _0800E5AA\n\
	mov sb, sl\n\
	mov sl, ip\n\
	mov r4, r8\n\
	adds r4, #8\n\
_0800E56A:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r2, #2\n\
	ldrsh r1, [r4, r2]\n\
	mov ip, r1\n\
	mov r1, r8\n\
	movs r2, #2\n\
	ldrsh r0, [r1, r2]\n\
	mov r2, ip\n\
	adds r1, r2, r0\n\
	ldr r2, _0800E5F4 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	mov r3, r8\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r3, [r6]\n\
	cmp r5, r3\n\
	blt _0800E56A\n\
_0800E5AA:\n\
	ldrh r0, [r7]\n\
	cmp r0, #1\n\
	beq _0800E5B2\n\
	b _0800E846\n\
_0800E5B2:\n\
	ldr r0, _0800E5D0 @ =gUnknown_0202BEBC\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	adds r2, r0, #0\n\
	cmp r1, #0\n\
	beq _0800E5C2\n\
	cmp r1, #4\n\
	bne _0800E5FC\n\
_0800E5C2:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x64\n\
	b _0800E602\n\
	.align 2, 0\n\
_0800E5CC: .4byte gUnknown_0200B3B8\n\
_0800E5D0: .4byte gUnknown_0202BEBC\n\
_0800E5D4: .4byte gUnknown_02002858\n\
_0800E5D8: .4byte gUnknown_0200287D\n\
_0800E5DC: .4byte gUnknown_02002882\n\
_0800E5E0: .4byte gUnknown_0201B178\n\
_0800E5E4: .4byte gUnknown_086A7DB0\n\
_0800E5E8: .4byte gOamBuffer\n\
_0800E5EC: .4byte 0x000003FF\n\
_0800E5F0: .4byte 0xFFFFFC00\n\
_0800E5F4: .4byte 0x000001FF\n\
_0800E5F8: .4byte 0xFFFFFE00\n\
_0800E5FC:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x50\n\
_0800E602:\n\
	strh r0, [r7, #4]\n\
	ldr r1, _0800E664 @ =gUnknown_086A7DB0\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #2\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	blt _0800E61C\n\
	b _0800E846\n\
_0800E61C:\n\
	ldr r1, _0800E668 @ =gOamBuffer\n\
	mov sb, r1\n\
	ldr r2, _0800E66C @ =0xFFFFFE00\n\
	mov sl, r2\n\
	adds r4, r7, #0\n\
	adds r4, #8\n\
_0800E628:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	movs r2, #2\n\
	ldrsh r0, [r7, r2]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800E670 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	ldrb r0, [r7, #4]\n\
	ldrb r3, [r4, #4]\n\
	adds r0, r0, r3\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	blt _0800E628\n\
	b _0800E846\n\
	.align 2, 0\n\
_0800E664: .4byte gUnknown_086A7DB0\n\
_0800E668: .4byte gOamBuffer\n\
_0800E66C: .4byte 0xFFFFFE00\n\
_0800E670: .4byte 0x000001FF\n\
_0800E674:\n\
	cmp r1, #0xf0\n\
	beq _0800E67A\n\
	b _0800E834\n\
_0800E67A:\n\
	movs r0, #0\n\
	strh r0, [r6]\n\
	movs r0, #1\n\
	mov r1, sl\n\
	strh r0, [r1]\n\
	ldr r0, _0800E79C @ =gUnknown_0201B178\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	strh r0, [r7]\n\
	mov r0, sb\n\
	adds r0, #0x26\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	ldr r0, _0800E7A0 @ =gUnknown_086A7DB0\n\
	movs r1, #9\n\
	adds r2, r6, #0\n\
	bl LoadSpriteSets\n\
	movs r0, #4\n\
	mov r3, sl\n\
	strh r0, [r3, #2]\n\
	movs r0, #0x90\n\
	strh r0, [r3, #4]\n\
	adds r4, r5, #0\n\
	adds r4, #8\n\
	ldr r5, _0800E7A4 @ =gOamBuffer\n\
	mov ip, r5\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, ip\n\
	mov r0, sb\n\
	movs r3, #0x1a\n\
	ldrsh r1, [r0, r3]\n\
	lsls r1, r1, #1\n\
	adds r1, #2\n\
	ldr r5, _0800E7A8 @ =0x000003FF\n\
	adds r0, r5, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #4]\n\
	ldr r0, _0800E7AC @ =0xFFFFFC00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #4]\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, ip\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	mov r3, sl\n\
	movs r5, #2\n\
	ldrsh r0, [r3, r5]\n\
	adds r1, r1, r0\n\
	ldr r3, _0800E7B0 @ =0x000001FF\n\
	adds r0, r3, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #2]\n\
	ldr r0, _0800E7B4 @ =0xFFFFFE00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, ip\n\
	mov r5, sl\n\
	ldrb r0, [r5, #4]\n\
	ldrb r4, [r4, #4]\n\
	adds r0, r0, r4\n\
	strb r0, [r1]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _0800E77C\n\
	movs r0, #0x54\n\
	strh r0, [r1, #2]\n\
	movs r0, #0x96\n\
	strh r0, [r1, #4]\n\
	ldr r2, _0800E7B8 @ =gUnknown_0200287D\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #7\n\
	lsls r0, r0, #2\n\
	ldr r3, _0800E7A0 @ =gUnknown_086A7DB0\n\
	adds r0, r0, r3\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	bge _0800E77C\n\
	mov sb, ip\n\
	ldr r1, _0800E7B4 @ =0xFFFFFE00\n\
	mov sl, r1\n\
	mov r4, r8\n\
	adds r4, #8\n\
_0800E73C:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r0, #2\n\
	ldrsh r2, [r4, r0]\n\
	mov ip, r2\n\
	mov r1, r8\n\
	movs r2, #2\n\
	ldrsh r0, [r1, r2]\n\
	mov r2, ip\n\
	adds r1, r2, r0\n\
	ldr r2, _0800E7B0 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	mov r3, r8\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r3, [r6]\n\
	cmp r5, r3\n\
	blt _0800E73C\n\
_0800E77C:\n\
	ldrh r0, [r7]\n\
	cmp r0, #1\n\
	bne _0800E846\n\
	ldr r0, _0800E7BC @ =gUnknown_0202BEBC\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	adds r2, r0, #0\n\
	cmp r1, #0\n\
	beq _0800E792\n\
	cmp r1, #4\n\
	bne _0800E7C0\n\
_0800E792:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x64\n\
	b _0800E7C6\n\
	.align 2, 0\n\
_0800E79C: .4byte gUnknown_0201B178\n\
_0800E7A0: .4byte gUnknown_086A7DB0\n\
_0800E7A4: .4byte gOamBuffer\n\
_0800E7A8: .4byte 0x000003FF\n\
_0800E7AC: .4byte 0xFFFFFC00\n\
_0800E7B0: .4byte 0x000001FF\n\
_0800E7B4: .4byte 0xFFFFFE00\n\
_0800E7B8: .4byte gUnknown_0200287D\n\
_0800E7BC: .4byte gUnknown_0202BEBC\n\
_0800E7C0:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x50\n\
_0800E7C6:\n\
	strh r0, [r7, #4]\n\
	ldr r1, _0800E824 @ =gUnknown_086A7DB0\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #2\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	bge _0800E846\n\
	ldr r1, _0800E828 @ =gOamBuffer\n\
	mov sb, r1\n\
	ldr r2, _0800E82C @ =0xFFFFFE00\n\
	mov sl, r2\n\
	adds r4, r7, #0\n\
	adds r4, #8\n\
_0800E7EA:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	movs r2, #2\n\
	ldrsh r0, [r7, r2]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800E830 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	ldrb r0, [r7, #4]\n\
	ldrb r3, [r4, #4]\n\
	adds r0, r0, r3\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	blt _0800E7EA\n\
	b _0800E846\n\
	.align 2, 0\n\
_0800E824: .4byte gUnknown_086A7DB0\n\
_0800E828: .4byte gOamBuffer\n\
_0800E82C: .4byte 0xFFFFFE00\n\
_0800E830: .4byte 0x000001FF\n\
_0800E834:\n\
	movs r0, #0\n\
	strh r0, [r6]\n\
	mov r1, sl\n\
	strh r0, [r1]\n\
	ldr r0, _0800E85C @ =gUnknown_086A7DB0\n\
	movs r1, #9\n\
	adds r2, r6, #0\n\
	bl LoadSpriteSets\n\
_0800E846:\n\
	movs r0, #0\n\
	strh r0, [r7]\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800E85C: .4byte gUnknown_086A7DB0\n\
    ");
}
#endif

void sub_E860(void)
{
    int i;
    struct SpriteGroup *spriteGroup;

    spriteGroup = &gUnknown_0200B3B8[gUnknown_0202C580];
    spriteGroup->available = gUnknown_0201C18C;
    LoadSpriteSets(gUnknown_086A7DD4, 5, gUnknown_0200B3B8);
    if (spriteGroup->available == 1)
    {
        spriteGroup->baseX = 120;
        spriteGroup->baseY = gUnknown_0201A4B8;
        for (i = 0; i < 4; i++)
        {
            gOamBuffer[spriteGroup->oam[i].oamId].x = spriteGroup->oam[i].xOffset + spriteGroup->baseX;
            gOamBuffer[spriteGroup->oam[i].oamId].y = spriteGroup->oam[i].yOffset + spriteGroup->baseY;
        }
    }

    spriteGroup->available = FALSE;
}

void sub_E908(void)
{
    gUnknown_0202C5F0[0] = 0xCFCF;
    gUnknown_0201C1B0 = 1;
    gUnknown_0202C59C = 1;
    gUnknown_0202ADE4 = 0;
    gUnknown_0201A4BC = 0;
    gUnknown_0202C598 = 0;
    gUnknown_0202C54C = 0;
}

s16 sub_E94C(void)
{
    s16 result;
    if (gLink.isMaster)
        result = sub_EBEC();
    else
        result = sub_ED28();

    return result;
}

s16 sub_E970(void)
{
    s16 result;
    if (gLink.isMaster)
        result = sub_E994();
    else
        result = sub_EAC0();

    return result;
}

s16 sub_E994(void)
{
    int i;
    struct HighScoreEntry *topScore;

    if (gUnknown_0202ADE4 == 0)
    {
        switch (gUnknown_0201A4BC)
        {
        case 0:
            if (JOY_NEW(A_BUTTON))
            {
                gUnknown_0202C5F0[0] = 0xDEDE;
            }
            else
            {
                for (i = 0; i < 8; i++)
                    gUnknown_0202C5F0[i] = 0;
            }
            break;
        case 1:
            gUnknown_0202C5F0[0] = 0xEDED;
            break;
        }
    }
    else
    {
        if (gUnknown_0202C59C < 8)
        {
            for (i = 0; i < 8; i++)
                gUnknown_0202C5F0[i] = 0xCFCF;
        }
        else if (gUnknown_0202C59C < 10)
        {
            u16 field = gUnknown_0202C59C - 8;
            gUnknown_0202C5F0[0] = gUnknown_0202C59C;
            gUnknown_0202C5F0[1] = (gUnknown_0202C610[field][0].data.parts.name[0] << 8) |
                                    gUnknown_0202C610[field][0].data.parts.name[1];
            gUnknown_0202C5F0[2] = (gUnknown_0202C610[field][0].data.parts.name[2] << 8) |
                                    gUnknown_0202C610[field][0].data.parts.name[3];
            gUnknown_0202C5F0[3] = gUnknown_0202C610[field][0].data.parts.scoreHi >> 16;
            gUnknown_0202C5F0[4] = gUnknown_0202C610[field][0].data.parts.scoreHi;
            gUnknown_0202C5F0[5] = gUnknown_0202C610[field][0].data.parts.scoreLo >> 16;
            gUnknown_0202C5F0[6] = gUnknown_0202C610[field][0].data.parts.scoreLo;
            gUnknown_0202C5F0[7] = 0;
        }
        else
        {
            for (i = 0; i < 8; i++)
                gUnknown_0202C5F0[i] = 0;
        }

        gUnknown_0202C59C++;
    }

    return 0;
}

s16 sub_EAC0(void)
{
    int i;
    struct HighScoreEntry *topScore;

    if (gUnknown_0202ADE4 == 0)
    {
        switch (gUnknown_0202C598)
        {
        case 0:
            if (JOY_NEW(A_BUTTON))
            {
                gUnknown_0202C5F0[0] = 0xDEDE;
            }
            else
            {
                for (i = 0; i < 8; i++)
                    gUnknown_0202C5F0[i] = 0;
            }
            break;
        case 1:
            gUnknown_0202C5F0[0] = 0xEDED;
            break;
        }
    }
    else
    {
        if (gUnknown_0202C59C < 8)
        {
            for (i = 0; i < 8; i++)
                gUnknown_0202C5F0[i] = 0xCFCF;
        }
        else if (gUnknown_0202C59C < 10)
        {
            u16 field = gUnknown_0202C59C - 8;
            gUnknown_0202C5F0[0] = gUnknown_0202C59C;
            gUnknown_0202C5F0[1] = (gUnknown_0202C610[field][0].data.parts.name[0] << 8) |
                                    gUnknown_0202C610[field][0].data.parts.name[1];
            gUnknown_0202C5F0[2] = (gUnknown_0202C610[field][0].data.parts.name[2] << 8) |
                                    gUnknown_0202C610[field][0].data.parts.name[3];
            gUnknown_0202C5F0[3] = gUnknown_0202C610[field][0].data.parts.scoreHi >> 16;
            gUnknown_0202C5F0[4] = gUnknown_0202C610[field][0].data.parts.scoreHi;
            gUnknown_0202C5F0[5] = gUnknown_0202C610[field][0].data.parts.scoreLo >> 16;
            gUnknown_0202C5F0[6] = gUnknown_0202C610[field][0].data.parts.scoreLo;
            gUnknown_0202C5F0[7] = 0;
        }
        else
        {
            for (i = 0; i < 8; i++)
                gUnknown_0202C5F0[i] = 0;
        }

        gUnknown_0202C59C++;
    }

    return 0;
}

s16 sub_EBEC(void)
{
    int i, j;
    struct HighScoreEntry *topScore;
    u16 field;

    if (gUnknown_0202ADE4 == 0)
    {
        switch (gUnknown_0201A4BC)
        {
        case 0:
            if (gUnknown_0201A4D0[0][0] == 0xDEDE || gUnknown_0201A4D0[0][1] == 0xDEDE)
                gUnknown_0201A4BC = 1;
            break;
        case 1:
            if (gUnknown_0201A4D0[0][0] == 0xEDED && gUnknown_0201A4D0[0][1] == 0xEDED)
            {
                gUnknown_0202ADE4 = -1;
                gUnknown_0202BEBC = 1;
                gUnknown_0202C59C = 1;
            }
            else
            {
                if (++gUnknown_0202C54C > 10)
                    return 1;
            }
            break;
        }
    }
    else
    {
        field = gUnknown_0201A4D0[0][1] - 8;
        if (field > 1)
            return 0;

        gUnknown_0201C1B0 = gUnknown_0201A4D0[0][1];
        gUnknown_0202C550[field].data.parts.name[0] = (gUnknown_0201A4D0[1][1] >> 8) & 0xFF;
        gUnknown_0202C550[field].data.parts.name[1] = gUnknown_0201A4D0[1][1] & 0xFF;
        gUnknown_0202C550[field].data.parts.name[2] = (gUnknown_0201A4D0[2][1] >> 8) & 0xFF;
        gUnknown_0202C550[field].data.parts.name[3] = gUnknown_0201A4D0[2][1] & 0xFF;
        gUnknown_0202C550[field].data.parts.scoreHi = (gUnknown_0201A4D0[3][1] << 16) |
                                                        gUnknown_0201A4D0[4][1];
        gUnknown_0202C550[field].data.parts.scoreLo = (gUnknown_0201A4D0[5][1] << 16) |
                                                                gUnknown_0201A4D0[6][1];
        if (gUnknown_0201C1B0 == 9)
            return -1;
    }

    for (i = 0; i < 8; i++)
        for (j = 0; j < 2; j++)
            gUnknown_0201A4D0[i][j] = 0;

    return 0;
}

s16 sub_ED28(void)
{
    int i, j;
    struct HighScoreEntry *topScore;
    u16 field;

    if (gUnknown_0202ADE4 == 0)
    {
        switch (gUnknown_0202C598)
        {
        case 0:
            if (gUnknown_0201A4D0[0][0] == 0xDEDE || gUnknown_0201A4D0[0][1] == 0xDEDE)
                gUnknown_0202C598 = 1;
            break;
        case 1:
            if (gUnknown_0201A4D0[0][0] == 0xEDED && gUnknown_0201A4D0[0][1] == 0xEDED)
            {
                gUnknown_0202ADE4 = -1;
                gUnknown_0202BEBC = 1;
                gUnknown_0202C59C = 1;
            }
            else
            {
                if (++gUnknown_0202C54C > 10)
                    return 1;
            }
            break;
        }
    }
    else
    {
        field = gUnknown_0201A4D0[0][0] - 8;
        if (field > 1)
            return 0;

        gUnknown_0201C1B0 = gUnknown_0201A4D0[0][0];
        gUnknown_0202C550[field].data.parts.name[0] = (gUnknown_0201A4D0[1][0] >> 8) & 0xFF;
        gUnknown_0202C550[field].data.parts.name[1] = gUnknown_0201A4D0[1][0] & 0xFF;
        gUnknown_0202C550[field].data.parts.name[2] = (gUnknown_0201A4D0[2][0] >> 8) & 0xFF;
        gUnknown_0202C550[field].data.parts.name[3] = gUnknown_0201A4D0[2][0] & 0xFF;
        gUnknown_0202C550[field].data.parts.scoreHi = (gUnknown_0201A4D0[3][0] << 16) |
                                                        gUnknown_0201A4D0[4][0];
        gUnknown_0202C550[field].data.parts.scoreLo = (gUnknown_0201A4D0[5][0] << 16) |
                                                                gUnknown_0201A4D0[6][0];
        if (gUnknown_0201C1B0 == 9)
            return -1;
    }

    for (i = 0; i < 8; i++)
        for (j = 0; j < 2; j++)
            gUnknown_0201A4D0[i][j] = 0;

    return 0;
}

void sub_EE64(void)
{
    int i, j;

    // Ruby Field Top name
    for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
    {
        PrintChar(gUnknown_086A7FAC[gUnknown_0202C610[FIELD_RUBY][0].data.parts.name[j]] + 0x80, 8, j + 6, 3, 1, 1);
    }

    // Ruby Field 2nd-8th names
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
        {
            PrintChar(gUnknown_086A7FAC[gUnknown_0202C610[FIELD_RUBY][i].data.parts.name[j]] + 0xA0, 8, j + 6, i * 2 + 3, 1, 2);
        }
    }

    // Ruby Field Top score
    sub_F21C(gUnknown_0202C610[FIELD_RUBY][0].data.parts.scoreHi, gUnknown_0202C610[FIELD_RUBY][0].data.parts.scoreLo);
    for (j = 0; j < 14; j++)
    {
        if ((j + 1) % 3 == 0)
            PrintChar(gUnknown_0202C5C0[j] + 0x120, 9, j + 12, 2, 1, 2); // Thousands separator?
        else
            PrintChar(gUnknown_0202C5C0[j] + 0xE0, 9, j + 12, 2, 1, 2);
    }
    PrintChar(gUnknown_0202C5C0[14] + 0xE0, 9, 26, 2, 1, 2);
    // Ruby Field 2nd-8th scores
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        sub_F21C(gUnknown_0202C610[FIELD_RUBY][i].data.parts.scoreHi, gUnknown_0202C610[FIELD_RUBY][i].data.parts.scoreLo);
        for (j = 0; j < 14; j++)
        {
            if ((j + 1) % 3 == 0)
                PrintChar(gUnknown_0202C5C0[j] + 0x1A0, 9, j + 12, i * 2 + 3, 1, 2); // Thousands separator?
            else
                PrintChar(gUnknown_0202C5C0[j] + 0x160, 9, j + 12, i * 2 + 3, 1, 2);
        }

        PrintChar(gUnknown_0202C5C0[14] + 0x160, 9, 26, 3 + i * 2, 1, 2);
    }

    // Sapphire Field Top name
    for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
    {
        PrintChar(gUnknown_086A7FAC[gUnknown_0202C610[FIELD_SAPPHIRE][0].data.parts.name[j]] + 0x80, 8, j + 4, 35, 1, 1);
    }

    // Sapphire Field 2nd-8th names
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
        {
            PrintChar(gUnknown_086A7FAC[gUnknown_0202C610[FIELD_SAPPHIRE][i].data.parts.name[j]] + 0xA0, 8, j + 4, i * 2 + 35, 1, 2);
        }
    }
    sub_F21C(gUnknown_0202C610[FIELD_SAPPHIRE][0].data.parts.scoreHi, gUnknown_0202C610[FIELD_SAPPHIRE][0].data.parts.scoreLo);
    // Sapphire Field Top score
    for (j = 0; j < 14; j++)
    {
        if ((j + 1) % 3 == 0)
            PrintChar(gUnknown_0202C5C0[j] + 0x120, 9, j + 10, 34, 1, 2); // Thousands separator?
        else
            PrintChar(gUnknown_0202C5C0[j] + 0xE0, 9, j + 10, 34, 1, 2);
    }

    PrintChar(gUnknown_0202C5C0[j] + 0xE0, 9, 24, 34, 1, 2);
    // Sapphire Field 2nd-8th scores
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        sub_F21C(gUnknown_0202C610[FIELD_SAPPHIRE][i].data.parts.scoreHi, gUnknown_0202C610[FIELD_SAPPHIRE][i].data.parts.scoreLo);
        for (j = 0; j < 14; j++)
        {
            if ((j + 1) % 3 == 0)
                PrintChar(gUnknown_0202C5C0[j] + 0x1A0, 9, j + 10, i * 2 + 35, 1, 2); // Thousands separator?s
            else
                PrintChar(gUnknown_0202C5C0[j] + 0x160, 9, j + 10, i * 2 + 35, 1, 2);
        }

        PrintChar(gUnknown_0202C5C0[j] + 0x160, 9, 24, i * 2 + 35, 1, 2);
    }
}

void sub_F21C(u32 scoreHi, u32 scoreLo)
{
    int i;
    u32 var0;
    u32 var1;
    u16 *arr;

    if (scoreHi == 0 && scoreLo == 0)
    {
        for (i = 0; i < 14; i++)
            gUnknown_0202C5C0[i] = 10;

        gUnknown_0202C5C0[14] = 0;
    }
    else
    {
        if (scoreHi > 9999999)
        {
            scoreHi = 9999999;
            scoreLo = 99999999;
        }
        else if (scoreLo > 99999999)
        {
            scoreLo = 99999999;
        }

        arr = gUnknown_0202C5C0;

        var0 = scoreHi / 1000000;
        arr[0] = var0;
        scoreHi %= 1000000;
        arr[1] = scoreHi / 100000;
        scoreHi %= 100000;
        arr[2] = scoreHi / 10000;
        scoreHi %= 10000;
        arr[3] = scoreHi / 1000;
        scoreHi %= 1000;
        arr[4] = scoreHi / 100;
        scoreHi %= 100;
        arr[5] = scoreHi / 10;
        arr[6] = scoreHi %= 10;

        arr[7] = scoreLo / 10000000;
        var1 = scoreLo % 10000000;
        arr[8] = var1 / 1000000;
        var1 %= 1000000;
        arr[9] = var1 / 100000;
        var1 %= 100000;
        arr[10] = var1 / 10000;
        var1 %= 10000;
        arr[11] = var1 / 1000;
        var1 %= 1000;
        arr[12] = var1 / 100;
        var1 %= 100;
        arr[13] = var1 / 10;
        arr[14] = var1 %= 10;

        if ((s16)var0 == 0)
        {
            for (i = 0; i < 15 && gUnknown_0202C5C0[i] == 0; i++)
                gUnknown_0202C5C0[i] = 10;
        }
    }
}

int CompareScores(u32 scoreHiA, u32 scoreLoA, u32 scoreHiB, u32 scoreLoB)
{
    if (scoreHiA > scoreHiB)
        return 1;
    if (scoreHiA < scoreHiB)
        return -1;
    if (scoreLoA > scoreLoB)
        return 1;
    if (scoreLoA < scoreLoB)
        return -1;

    return 0;
}

int GetNewHighScoreIndex(u32 scoreHi, u32 scoreLo, u32 field)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        int comparisonResult = CompareScores(
            scoreHi,
            scoreLo,
            gUnknown_0202C610[field][i].data.parts.scoreHi,
            gUnknown_0202C610[field][i].data.parts.scoreLo
        );
        if (comparisonResult >= 0)
            return i;
    }

    return -1;
}

void sub_F434(u32 scoreHi, u32 scoreLo, u32 field, int newHighScoreIndex)
{
    int i;

    for (i = 7; i > newHighScoreIndex; i--)
    {
        gUnknown_0202C610[field][i].data.parts.name[0] = gUnknown_0202C610[field][i-1].data.parts.name[0];
        gUnknown_0202C610[field][i].data.parts.name[1] = gUnknown_0202C610[field][i-1].data.parts.name[1];
        gUnknown_0202C610[field][i].data.parts.name[2] = gUnknown_0202C610[field][i-1].data.parts.name[2];
        gUnknown_0202C610[field][i].data.parts.name[3] = gUnknown_0202C610[field][i-1].data.parts.name[3];
        gUnknown_0202C610[field][i].data.parts.scoreHi = gUnknown_0202C610[field][i-1].data.parts.scoreHi;
        gUnknown_0202C610[field][i].data.parts.scoreLo = gUnknown_0202C610[field][i-1].data.parts.scoreLo;
    }

    gUnknown_0202C610[field][i].data.parts.name[0] = 0;
    gUnknown_0202C610[field][i].data.parts.name[1] = 0;
    gUnknown_0202C610[field][i].data.parts.name[2] = 0;
    gUnknown_0202C610[field][i].data.parts.name[3] = 0;
    gUnknown_0202C610[field][i].data.parts.scoreHi = scoreHi;
    gUnknown_0202C610[field][i].data.parts.scoreLo = scoreLo;
}

u32 sub_F4FC(u32 field)
{
    int i, j;
    int newHighScoreIndex;
    int comparisonResult;

    newHighScoreIndex = GetNewHighScoreIndex(gUnknown_0202C550[field].data.parts.scoreHi, gUnknown_0202C550[field].data.parts.scoreLo, field);
    comparisonResult = CompareScores(
        gUnknown_0202C610[field][newHighScoreIndex].data.parts.scoreHi,
        gUnknown_0202C610[field][newHighScoreIndex].data.parts.scoreLo,
        gUnknown_0202C550[field].data.parts.scoreHi,
        gUnknown_0202C550[field].data.parts.scoreLo
    );
    if (comparisonResult == 0 &&
        gUnknown_0202C610[field][newHighScoreIndex].data.parts.name[0] == gUnknown_0202C550[field].data.parts.name[0] &&
        gUnknown_0202C610[field][newHighScoreIndex].data.parts.name[1] == gUnknown_0202C550[field].data.parts.name[1] &&
        gUnknown_0202C610[field][newHighScoreIndex].data.parts.name[2] == gUnknown_0202C550[field].data.parts.name[2] &&
        gUnknown_0202C610[field][newHighScoreIndex].data.parts.name[3] == gUnknown_0202C550[field].data.parts.name[3])
    {
        return newHighScoreIndex;
    }

    if (newHighScoreIndex == -1)
    {
        return -1;
    }

    for (i = 7; i > newHighScoreIndex; i--)
    {
        for (j = 0; j < 6; j++)
        {
            gUnknown_0202C610[field][i].data.raw[j] = gUnknown_0202C610[field][i-1].data.raw[j];
        }
    }

    gUnknown_0202C610[field][i].data.parts.name[0] = gUnknown_0202C550[field].data.parts.name[0];
    gUnknown_0202C610[field][i].data.parts.name[1] = gUnknown_0202C550[field].data.parts.name[1];
    gUnknown_0202C610[field][i].data.parts.name[2] = gUnknown_0202C550[field].data.parts.name[2];
    gUnknown_0202C610[field][i].data.parts.name[3] = gUnknown_0202C550[field].data.parts.name[3];
    gUnknown_0202C610[field][i].data.parts.scoreHi = gUnknown_0202C550[field].data.parts.scoreHi;
    gUnknown_0202C610[field][i].data.parts.scoreLo = gUnknown_0202C550[field].data.parts.scoreLo;
    return newHighScoreIndex;
}

void sub_F670(u32 arg0, u32 arg1, s16 arg2, u32 arg3)
{
    arg0 = gUnknown_086A7FAC[arg0];
    PrintChar(
        gUnknown_08079730[arg3][arg1].unk8 * 32 + 0x80 + arg0,
        8,
        gUnknown_08079730[arg3][arg1].unk0 + arg2,
        gUnknown_08079730[arg3][arg1].unk4,
        1,
        gUnknown_08079730[arg3][arg1].unk8 + 1
    );
}

void SetDefaultHighScores(void)
{
    int field, highScoreIndex, i;

    gUnknown_0202BEB0 = 0;
    for (field = 0; field < 2; field++)
        for (highScoreIndex = 0; highScoreIndex < 8; highScoreIndex++)
            for (i = 0; i < 6; i++)
                gMain_saveData.highScores[field][highScoreIndex].data.raw[i] = gUnknown_08079430[field][highScoreIndex].data.raw[i];
}

void sub_F74C(void)
{
    int field, highScoreIndex, k;
    u8 letter;
    u32 scoreHi, scoreLo;

    for (field = 0; field < MAIN_FIELD_COUNT; field++)
    {
        letter = Random() % 42;
        gMain_saveData.highScores[field][0].data.parts.name[0] = letter;
        for (k = 1; k < 4; k++)
        {
            if ((u8)(Random() % 10) < 8)
                letter = Random() % 42;

            gMain_saveData.highScores[field][0].data.parts.name[k] = letter;
        }

        scoreHi = Random();
        scoreLo = Random();
        gMain_saveData.highScores[field][0].data.parts.scoreHi = scoreHi;
        gMain_saveData.highScores[field][0].data.parts.scoreLo = scoreLo;
        for (highScoreIndex = 1; highScoreIndex < 8; highScoreIndex++)
        {
            letter = Random() % 42;
            gMain_saveData.highScores[field][highScoreIndex].data.parts.name[0] = letter;
            for (k = 1; k < 4; k++)
            {
                if ((u8)(Random() % 10) < 8)
                    letter = Random() % 42;

                gMain_saveData.highScores[field][highScoreIndex].data.parts.name[k] = letter;
            }

            scoreHi = Random() % scoreHi;
            if (scoreHi != 0)
                scoreLo = Random();
            else
                scoreLo = Random() % scoreLo;

            gMain_saveData.highScores[field][highScoreIndex].data.parts.scoreHi = scoreHi;
            gMain_saveData.highScores[field][highScoreIndex].data.parts.scoreLo = scoreLo;
        }
    }
}

void sub_F8B0(u32 arg0, u32 arg1, s16 arg2)
{
    int i;
    u32 r3;
    if(arg0 == 0)
    {
        if(arg1 == 0) 
        {
            r3 = (0 * 2 + 2) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x90EA && gUnknown_03005C00[r3 + i] != 0x912A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x910A && gUnknown_03005C00[r3 + i] != 0x914A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x916A && gUnknown_03005C00[r3 + i] != 0x91AA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x918A && gUnknown_03005C00[r3 + i] != 0x91CA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
        }
    }
    else
    {
        if(arg1 == 0) 
        {
            r3 = (0 * 2 + 2) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x90EA && gUnknown_03005C00[r3 + i] != 0x912A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x910A && gUnknown_03005C00[r3 + i] != 0x914A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x916A && gUnknown_03005C00[r3 + i] != 0x91AA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x918A && gUnknown_03005C00[r3 + i] != 0x91CA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA4[arg2];
                }
            }
        }
    }
}

void sub_FAE8(u32 arg0, u32 arg1, s16 arg2)
{
    int i;
    u32 r3;
    if(arg0 == 0)
    {
        if(arg1 == 0) 
        {
            r3 = (0 * 2 + 2) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x90EA && gUnknown_03005C00[r3 + i] != 0x912A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x910A && gUnknown_03005C00[r3 + i] != 0x914A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x916A && gUnknown_03005C00[r3 + i] != 0x91AA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x918A && gUnknown_03005C00[r3 + i] != 0x91CA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
        }
    }
    else
    {
        if(arg1 == 0) 
        {
            r3 = (0 * 2 + 2) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x90EA && gUnknown_03005C00[r3 + i] != 0x912A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x910A && gUnknown_03005C00[r3 + i] != 0x914A)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x916A && gUnknown_03005C00[r3 + i] != 0x91AA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gUnknown_03005C00[r3 + i] != 0x918A && gUnknown_03005C00[r3 + i] != 0x91CA)
                {
                    gUnknown_03005C00[r3 + i] += gUnknown_086A7FA8[arg2];
                }
            }
        }
    }
}

s8 sub_FD20(void)
{
    int i;
    s16 sp0[NUM_SPECIES];
    
    for(i = 0; i < NUM_SPECIES; i++)
        sp0[i] = gMain_saveData.pokedexFlags[i];

    for(i = 0; i < BONUS_SPECIES_START; i++) // TODO: add a proper count for non bonus
    {
        if(sp0[i] != 4)
            return 0;
    }
    return 1;
}

void sub_FD5C(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void*)PLTT, gUnknown_0201A520[1], PLTT_SIZE);
    DmaFill16(3, 0x7FFF, gUnknown_0201A520[0], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[0], gUnknown_0201A520[2], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[2], (void*)PLTT, PLTT_SIZE);
    
    sub_1050C();

    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        sub_1001C(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gUnknown_0201A520[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201A520[2], (void *)PLTT, 0x400);
        }
    }
}

void sub_FE04(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void*)PLTT, gUnknown_0201A520[0], PLTT_SIZE);
    DmaFill16(3, 0x7FFF, gUnknown_0201A520[1], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[0], gUnknown_0201A520[2], PLTT_SIZE);

    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        sub_1001C(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gUnknown_0201A520[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201A520[2], (void *)PLTT, 0x400);
        }
    }
    sub_10528();
    MainLoopIter();
    ClearGraphicsMemory();
}

void sub_FEB8(u8 * arg0, u8 * arg1, void (*func)(void))
{
    u16 i;

    DmaCopy16(3, arg0, gUnknown_0201A520[1], 0x200);
    DmaCopy16(3, arg1, gUnknown_0201A520[2], 0x200);
    DmaFill16(3, 0, gUnknown_0201A520[0], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[0], gUnknown_0201A520[2], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[2], (void*)PLTT, PLTT_SIZE);

    sub_1050C();
    gMain.unk16 = REG_DISPCNT;
    
    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        sub_1001C(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gUnknown_0201A520[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201A520[2], (void *)PLTT, 0x400);
        }
    }
}

void sub_FF74(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void*)PLTT, gUnknown_0201A520[0], PLTT_SIZE);
    DmaFill16(3, 0, gUnknown_0201A520[1], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[0], gUnknown_0201A520[2], PLTT_SIZE);

    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        sub_1001C(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gUnknown_0201A520[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201A520[2], (void *)PLTT, 0x400);
        }
    }
    MainLoopIter();
}

void sub_1001C(u16 arg0)
{
    u16 var0;
    u16 var1;
    u16 b[2];
    u16 g[2];
    u16 r[2];
    u16 spC[4];

    spC[0] = 0;
    spC[1] = 2;
    spC[2] = 1;
    spC[3] = 3;
    var0 = spC[arg0 & 3] * 128;
    var1 = var0 + 128;

    arg0 &= ~3;
    arg0 += 4;
    
    while(var0 < var1)
    {
        r[0] = gUnknown_0201A520[0][var0] & 0x1F;
        g[0] = (gUnknown_0201A520[0][var0] & 0x3E0) >> 5;
        b[0] = (gUnknown_0201A520[0][var0] & 0x7C00) >> 10;
        
        r[1] = gUnknown_0201A520[1][var0] & 0x1F;
        g[1] = (gUnknown_0201A520[1][var0] & 0x3E0) >> 5;
        b[1] = (gUnknown_0201A520[1][var0] & 0x7C00) >> 10;

        if(b[0] < b[1])
            b[0] += ((b[1] - b[0]) * arg0) >> 5;
        else
            b[0] -= ((b[0] - b[1]) * arg0) >> 5;

        if(g[0] < g[1])
            g[0] += ((g[1] - g[0]) * arg0) >> 5;
        else
            g[0] -= ((g[0] - g[1]) * arg0) >> 5;

        if(r[0] < r[1])
            r[0] += ((r[1] - r[0]) * arg0) >> 5;
        else
            r[0] -= ((r[0] - r[1]) * arg0) >> 5;
        
        gUnknown_0201A520[2][var0] = (b[0] << 10) | (g[0] << 5) | r[0];
        var0++;
    }
}

void sub_10170(u8 * pal, u8 * dest, u16 arg2, u16 arg3)
{
    u16 i;
    u16 b[2];
    u16 g[2];
    u16 r[2];   
    DmaCopy16(3, pal, gUnknown_0201A520[0], arg2);
    DmaFill16(3, 0, gUnknown_0201A520[1], arg2);
    
    for(i = 0; i < arg2; i++)
    {
        r[0] = gUnknown_0201A520[0][i] & 0x1F;
        g[0] = (gUnknown_0201A520[0][i] & 0x3E0) >> 5;
        b[0] = (gUnknown_0201A520[0][i] & 0x7C00) >> 10;
        
        r[1] = gUnknown_0201A520[1][i] & 0x1F;
        g[1] = (gUnknown_0201A520[1][i] & 0x3E0) >> 5;
        b[1] = (gUnknown_0201A520[1][i] & 0x7C00) >> 10;

        if(b[0] > b[1])
            b[0] -= (b[0] * arg3) >> 5;
        else
            b[0] = b[1]; 

        if(g[0] > g[1])
            g[0] -= (g[0] * arg3) >> 5;
        else
            g[0] = g[1]; 

        if(r[0] > r[1])
            r[0] -= (r[0] * arg3) >> 5;
        else
            r[0] = r[1]; 
        
        gUnknown_0201A520[2][i] = (b[0] << 10) | (g[0] << 5) | r[0];
    }
    DmaCopy16(3, gUnknown_0201A520[2], dest, arg2);
}

void sub_102A8(u8 * pal, u8 * dest, u16 arg2, u16 arg3)
{
    u16 i;
    u16 b[2];
    u16 g[2];
    u16 r[2];   
    DmaCopy16(3, pal, gUnknown_0201A520[0], arg2);
    DmaFill16(3, 0x7FFF, gUnknown_0201A520[1], arg2);
    
    for(i = 0; i < arg2; i++)
    {
        r[0] = gUnknown_0201A520[0][i] & 0x1F;
        g[0] = (gUnknown_0201A520[0][i] & 0x3E0) >> 5;
        b[0] = (gUnknown_0201A520[0][i] & 0x7C00) >> 10;
        
        r[1] = gUnknown_0201A520[1][i] & 0x1F;
        g[1] = (gUnknown_0201A520[1][i] & 0x3E0) >> 5;
        b[1] = (gUnknown_0201A520[1][i] & 0x7C00) >> 10;

        if(b[0] < b[1])
            b[0] += ((b[1] - b[0]) * arg3) >> 5;
        else
            b[0] -= ((b[0] - b[1]) * arg3) >> 5;

        if(g[0] < g[1])
            g[0] += ((g[1] - g[0]) * arg3) >> 5;
        else
            g[0] -= ((g[0] - g[1]) * arg3) >> 5;

        if(r[0] < r[1])
            r[0] += ((r[1] - r[0]) * arg3) >> 5;
        else
            r[0] -= ((r[0] - r[1]) * arg3) >> 5;
        
        gUnknown_0201A520[2][i] = (b[0] << 10) | (g[0] << 5) | r[0];
    }
    DmaCopy16(3, gUnknown_0201A520[2], dest, arg2);
}

void sub_10424(void)
{
    REG_BLDY = 0x10;
    REG_BLDCNT = ((REG_DISPCNT & (DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON)) >> 8) | BLDCNT_EFFECT_LIGHTEN | BLDCNT_TGT1_BD;
    REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
    gMain.unk16 = REG_DISPCNT;
    REG_BLDY = 0x10;
    MainLoopIter();
    REG_BLDY = 0x8;
    MainLoopIter();
    REG_BLDY = 0;
    MainLoopIter();
    REG_BLDCNT = 0;
}

void sub_10480(void)
{
    REG_BLDY = 0;
    REG_BLDCNT = ((REG_DISPCNT & (DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON)) >> 8) | BLDCNT_EFFECT_LIGHTEN | BLDCNT_TGT1_BD;
    REG_BLDY = 0;
    MainLoopIter();
    REG_BLDY = 0x8;
    MainLoopIter();
    REG_BLDY = 0x10;
    MainLoopIter();
    DmaFill16(3, 0, (void*)VRAM, VRAM_SIZE);
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    MainLoopIter();
}

void sub_1050C(void)
{
    REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
    gMain.unk16 = REG_DISPCNT;
}

void sub_10528(void)
{
    gMain.unk16 |= DISPCNT_FORCED_BLANK;
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
}

void sub_10544(void)
{
    REG_DISPSTAT &= ~DISPSTAT_VBLANK_INTR;
    REG_DISPSTAT &= ~DISPSTAT_VCOUNT_INTR;
    REG_IE &= 0x3FFF;
    REG_IE &= 0x3FFE;
    if(REG_IE == 0)
        REG_IME = 0;
    REG_IF |= 1;
}

// Print char? (also used by the Pokédex)
void PrintChar(u16 glyph, u16 color, int x, int y, int arg4, int arg5)
{
    u16 i, j;
    for(i = 0; i < arg5; i++)
    {
        for(j = 0; j < arg4; j++)
        {
            gUnknown_03005C00[y * 32 + x + i * 32 + j] = (glyph + i * 32 + j) | (color << 12);
        }
    }
}
