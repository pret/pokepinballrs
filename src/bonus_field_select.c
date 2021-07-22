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

EWRAM_DATA u16 gUnknown_0201A4F4 = 0;
EWRAM_DATA s8 gUnknown_0201A4F8 = 0;
EWRAM_DATA u8 gUnknown_0201A4B0 = 0;
EWRAM_DATA u8 gUnknown_0201A4C0 = 0;
EWRAM_DATA s16 gUnknown_0202A560 = 0;
EWRAM_DATA s16 gUnknown_0202BE1C = 0;
EWRAM_DATA s8 gUnknown_0202BED0 = 0;
EWRAM_DATA u8 gUnknown_0202BEE4 = 0;
EWRAM_DATA u8 gUnknown_0202BEE8 = 0;

extern const u8 gUnknown_086A4CF0[];

void sub_2710(void)
{
    gUnknown_0201A4F8 = 0;
    gUnknown_0202BED0 = 0;
    gUnknown_0202A560 = 0;
    gUnknown_0202BE1C = 0;
    gUnknown_0202BEE8 = 0;
    gUnknown_0201A4F4 = 0;
    gUnknown_0201A4B0 = 0;
    gUnknown_0202BEE4 = 0;
    gUnknown_0201A4C0 = gMain_saveData.ballSpeed;
}

void sub_2768(void)
{
    sub_29C8();
    switch (gUnknown_0202BED0)
    {
    case 0:
        if (gMain.newKeys & DPAD_LEFT)
        {
            if (gUnknown_0201A4F8 != 0 && gUnknown_0201A4F8 != 3)
            {
                m4aSongNumStart(0x6D);
                gUnknown_0201A4F8--;
            }
        }
        else if (gMain.newKeys & DPAD_RIGHT)
        {
            if (gUnknown_0201A4F8 != 2 && gUnknown_0201A4F8 != 5)
            {
                m4aSongNumStart(0x6D);
                gUnknown_0201A4F8++;
            }
        }
        if (gMain.newKeys & DPAD_UP)
        {
            if (gUnknown_0201A4F8 > 2)
            {
                m4aSongNumStart(0x6D);
                gUnknown_0201A4F8 -= 3;
            }
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (gUnknown_0201A4F8 < 3)
            {
                m4aSongNumStart(0x6D);
                gUnknown_0201A4F8 += 3;
            }
        }
        if (gMain.newKeys & A_BUTTON)
        {
            m4aSongNumStart(0x65);
            gUnknown_0202BED0 = 1;
            gUnknown_0201A4B0 = 1;
            gUnknown_0202A560 = 0;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            m4aSongNumStart(0x66);
            gUnknown_0202BEE4 = 1;
            gMain.subState++;
        }
        break;
    case 1:
        if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
        {
            m4aSongNumStart(0x67);
            gUnknown_0201A4C0 = 1 - gUnknown_0201A4C0;
        }
        if (gMain.newKeys & A_BUTTON)
        {
            m4aSongNumStart(0x65);
            gUnknown_0202A560 = 0;
            gUnknown_0202BE1C = 0;
            gMain.saveData.ballSpeed = gUnknown_0201A4C0;
            SaveFile_WriteToSram();
            gUnknown_0202BED0 = 2;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            m4aSongNumStart(0x66);
            gUnknown_0201A4B0 = 0;
            gUnknown_0202BED0 = 0;
        }
        gUnknown_0202A560++;
        if (gUnknown_0202A560 > 4)
        {
            gUnknown_0202A560 = 0;
            gUnknown_0201A4F4 = 1 - gUnknown_0201A4F4;
        }
        break;
    case 2:
        gUnknown_0202A560++;
        if (gUnknown_0202A560 > 5)
        {
            gUnknown_0202A560 = 0;
            gUnknown_0202BEE8 = 2 - gUnknown_0202BEE8;
            gUnknown_0202BE1C++;
            if (gUnknown_0202BE1C > 5)
            {
                gMain.unkD = 0;
                gMain.unk5 = gMain.unk4 = gUnknown_086A4CF0[gUnknown_0201A4F8];
                gMain.unk6 = 1;
                gUnknown_0202BEE4 = 2;
                gMain.subState++;
            }
        }
        break;
    }
}
