#include "global.h"
#include "main.h"

void PrintString(u16 glyph, u16 palette, int x, int y, int width, int height)
{
    u16 i, j;

    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++)
            gUnknown_03005C00[y * 0x20 + x + j * 0x20 + i] = (glyph + j * 0x20 + i) | (palette << 12);
}

void CopyString(int srcX, int srcY, int destX, int destY, int width, int height)
{
    u16 i, j;

    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++)
            gUnknown_03005C00[destY * 0x20 + destX + j * 0x20 + i] = gUnknown_03005C00[srcY * 0x20 + srcX + j * 0x20 + i];
}

void SetStringPalette(int x, int y, int width, int height, u16 palette)
{
    u16 i, j;
    u16 index;

    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            index = y * 0x20 + x + j * 0x20 + i;
            gUnknown_03005C00[index] = (gUnknown_03005C00[index] & 0xFFF) | (palette << 12);
        }
    }
}

// This requires volatile parameters to match. There is no reason, *ever*, to do this.
void CopyBgTilesRect(void *volatile src, void *volatile dest, s16 width, s16 height)
{
    int j;

    for (j = 0; j < height; j++)
    {
        DmaCopy16(3, (u8 *)src + 0x400 * j, (u8 *)dest + 0x400 * j, width * 0x20);
    }
}

// This function is unused. It appears to operates on a pixel canvas where each "tile" is represented by
// 2 bytes.
void sub_10750(void *volatile src, void *volatile dest, s16 width, s16 height)
{
    int j;

    for (j = 0; j < height; j++)
    {
        DmaCopy16(3, (u8 *)src + 0x40 * j, (u8 *)dest + 0x40 * j, width * 2);
    }
}

// This function is unused.
void sub_10798(void *src1, void *src2, void (*func)(void))
{
    u16 i;

    DmaCopy16(3, src1, gUnknown_0201A520[1], BG_PLTT_SIZE);
    DmaCopy16(3, src2, gUnknown_0201A520[2], BG_PLTT_SIZE);
    DmaFill16(3, RGB_WHITE, gUnknown_0201A520, PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[0], gUnknown_0201A520[2], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[2], (void *)PLTT, PLTT_SIZE);

    UnblankLCD();
    gMain.dispcntBackup = REG_DISPCNT;

    for (i = 0; i <= 0x20; i += 0x10)
    {
        if (func != NULL)
            func();

        sub_1001C(i);
        MainLoopIter();
        if (i == 0x20)
        {
            DmaCopy16(3, gUnknown_0201A520[1], (void *)PLTT, PLTT_SIZE);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201A520[2], (void *)PLTT, PLTT_SIZE);
        }
    }
}

// This function is unused.
void sub_10860(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void *)PLTT, gUnknown_0201A520[0], PLTT_SIZE);
    DmaFill16(3, RGB_WHITE, gUnknown_0201A520[1], PLTT_SIZE);
    DmaCopy16(3, gUnknown_0201A520[0], gUnknown_0201A520[2], PLTT_SIZE);

    for (i = 0; i <= 0x20; i += 0x10)
    {
        if (func != NULL)
            func();
        sub_1001C(i);
        MainLoopIter();
        if (i == 0x20)
        {
            DmaCopy16(3, gUnknown_0201A520[1], (void *)PLTT, PLTT_SIZE);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201A520[2], (void *)PLTT, PLTT_SIZE);
        }
    }
    MainLoopIter();
}

void ClearHighScoreNameEntry(void)
{
    int i;

    for (i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
        gHighScoreNameEntry[i] = 0;
}
