#include "global.h"
#include "main.h"

void sub_10618(int a, int b, int c, int d, int e, int f)
{
    u16 i;
    u16 j;

    for (i = 0; i < f; i++)
    {
        for (j = 0; j < e; j++)
        {
          gUnknown_03005C00[d * 32 + c + i * 32 + j] = gUnknown_03005C00[b * 32 + a + i * 32 + j];
        }
    }
}

void sub_1068C(int a, int b, int c, int d, u16 e)
{
    u16 i;
    u16 j;

    for (i = 0; i < d; i++)
    {
        for (j = 0; j < c; j++)
        {
            u16 index = b * 32 + a + i * 32 + j;

            gUnknown_03005C00[index] = (gUnknown_03005C00[index] & 0xFFF) | (e << 12);
        }
    }
}

// This requires volatile parameters to match. There is no reason, *ever*, to do this.
void sub_10708(void *volatile src, void *volatile dest, s16 numTilesX, s16 numTilesY)
{
    int i;

    for (i = 0; i < numTilesY; i++)
    {
        DmaCopy16(3, (u8 *)src + 0x400 * i, (u8 *)dest + 0x400 * i, numTilesX * 32);
    }
}

void sub_10750(void *volatile src, void *volatile dest, s16 numTilesX, s16 numTilesY)
{
    int i;

    for (i = 0; i < numTilesY; i++)
    {
        DmaCopy16(3, (u8 *)src + 0x40 * i, (u8 *)dest + 0x40 * i, numTilesX * 2);
    }
}

void sub_10798(void *a, void *b, void (*func)(void))
{
    u16 i;

    DmaCopy16(3, a, gUnknown_0201A920, 0x200);
    DmaCopy16(3, b, gUnknown_0201A920 + 0x200, 0x200);
    DmaFill16(3, 0x7FFF, gUnknown_0201A920 - 0x200, 0x400);
    DmaCopy16(3, gUnknown_0201A920 - 0x200, gUnknown_0201A920 + 0x200, 0x400);
    DmaCopy16(3, gUnknown_0201A920 + 0x200, (void *)PLTT, 0x400);

    sub_1050C();
    gMain.unk16 = REG_DISPCNT;

    for (i = 0; i <= 32; i += 16)
    {
        if (func != NULL)
            func();
        sub_1001C(i);
        MainLoopIter();
        if (i == 32)
        {
            DmaCopy16(3, gUnknown_0201A920, (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201AD20, (void *)PLTT, 0x400);
        }
    }
}

void sub_10860(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void *)PLTT, gUnknown_0201A520, 0x400);
    DmaFill16(3, 0x7FFF, gUnknown_0201A520 + 0x200, 0x400);
    DmaCopy16(3, gUnknown_0201A520, gUnknown_0201A520 + 0x400, 0x400);

    for (i = 0; i <= 32; i += 16)
    {
        if (func != NULL)
            func();
        sub_1001C(i);
        MainLoopIter();
        if (i == 32)
        {
            DmaCopy16(3, gUnknown_0201A920, (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gUnknown_0201AD20, (void *)PLTT, 0x400);
        }
    }
    MainLoopIter();
}

void ClearSomeArray(void)
{
    int i;
    
    for (i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
        gUnknown_0201A500[i] = 0;
}
