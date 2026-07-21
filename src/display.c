#include "global.h"
#include "main.h"

void FadeInFromWhite(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void*)PLTT, gPaletteFadeBuffers[1], PLTT_SIZE);
    DmaFill16(3, 0x7FFF, gPaletteFadeBuffers[0], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[0], gPaletteFadeBuffers[2], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[2], (void*)PLTT, PLTT_SIZE);

    UnblankLCD();

    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        InterpolatePaletteStep(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gPaletteFadeBuffers[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gPaletteFadeBuffers[2], (void *)PLTT, 0x400);
        }
    }
}

void FadeOutToWhite(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void*)PLTT, gPaletteFadeBuffers[0], PLTT_SIZE);
    DmaFill16(3, 0x7FFF, gPaletteFadeBuffers[1], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[0], gPaletteFadeBuffers[2], PLTT_SIZE);

    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        InterpolatePaletteStep(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gPaletteFadeBuffers[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gPaletteFadeBuffers[2], (void *)PLTT, 0x400);
        }
    }
    ForceBlankLCD();
    MainLoopIter();
    ClearGraphicsMemory();
}

void FadeInWithCustomPalettes(u8 * arg0, u8 * arg1, void (*func)(void))
{
    u16 i;

    DmaCopy16(3, arg0, gPaletteFadeBuffers[1], 0x200);
    DmaCopy16(3, arg1, gPaletteFadeBuffers[2], 0x200);
    DmaFill16(3, 0, gPaletteFadeBuffers[0], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[0], gPaletteFadeBuffers[2], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[2], (void*)PLTT, PLTT_SIZE);

    UnblankLCD();
    gMain.dispcntBackup = REG_DISPCNT;

    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        InterpolatePaletteStep(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gPaletteFadeBuffers[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gPaletteFadeBuffers[2], (void *)PLTT, 0x400);
        }
    }
}

void FadeOutToBlack(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void*)PLTT, gPaletteFadeBuffers[0], PLTT_SIZE);
    DmaFill16(3, 0, gPaletteFadeBuffers[1], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[0], gPaletteFadeBuffers[2], PLTT_SIZE);

    for (i = 0; i < 32; i++)
    {
        if (func != NULL)
            func();
        InterpolatePaletteStep(i);
        MainLoopIter();
        if (i == 31)
        {
            DmaCopy16(3, gPaletteFadeBuffers[1], (void *)PLTT, 0x400);
        }
        else
        {
            DmaCopy16(3, gPaletteFadeBuffers[2], (void *)PLTT, 0x400);
        }
    }
    MainLoopIter();
}

void InterpolatePaletteStep(u16 arg0)
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
        r[0] = gPaletteFadeBuffers[0][var0] & 0x1F;
        g[0] = (gPaletteFadeBuffers[0][var0] & 0x3E0) >> 5;
        b[0] = (gPaletteFadeBuffers[0][var0] & 0x7C00) >> 10;

        r[1] = gPaletteFadeBuffers[1][var0] & 0x1F;
        g[1] = (gPaletteFadeBuffers[1][var0] & 0x3E0) >> 5;
        b[1] = (gPaletteFadeBuffers[1][var0] & 0x7C00) >> 10;

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

        gPaletteFadeBuffers[2][var0] = (b[0] << 10) | (g[0] << 5) | r[0];
        var0++;
    }
}

void DarkenPalette(u8 * pal, u8 * dest, u16 arg2, u16 arg3)
{
    u16 i;
    u16 b[2];
    u16 g[2];
    u16 r[2];
    DmaCopy16(3, pal, gPaletteFadeBuffers[0], arg2);
    DmaFill16(3, 0, gPaletteFadeBuffers[1], arg2);

    for(i = 0; i < arg2; i++)
    {
        r[0] = gPaletteFadeBuffers[0][i] & 0x1F;
        g[0] = (gPaletteFadeBuffers[0][i] & 0x3E0) >> 5;
        b[0] = (gPaletteFadeBuffers[0][i] & 0x7C00) >> 10;

        r[1] = gPaletteFadeBuffers[1][i] & 0x1F;
        g[1] = (gPaletteFadeBuffers[1][i] & 0x3E0) >> 5;
        b[1] = (gPaletteFadeBuffers[1][i] & 0x7C00) >> 10;

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

        gPaletteFadeBuffers[2][i] = (b[0] << 10) | (g[0] << 5) | r[0];
    }
    DmaCopy16(3, gPaletteFadeBuffers[2], dest, arg2);
}

void BrightenPalette(u8 * pal, u8 * dest, u16 arg2, u16 arg3)
{
    u16 i;
    u16 b[2];
    u16 g[2];
    u16 r[2];
    DmaCopy16(3, pal, gPaletteFadeBuffers[0], arg2);
    DmaFill16(3, 0x7FFF, gPaletteFadeBuffers[1], arg2);

    for(i = 0; i < arg2; i++)
    {
        r[0] = gPaletteFadeBuffers[0][i] & 0x1F;
        g[0] = (gPaletteFadeBuffers[0][i] & 0x3E0) >> 5;
        b[0] = (gPaletteFadeBuffers[0][i] & 0x7C00) >> 10;

        r[1] = gPaletteFadeBuffers[1][i] & 0x1F;
        g[1] = (gPaletteFadeBuffers[1][i] & 0x3E0) >> 5;
        b[1] = (gPaletteFadeBuffers[1][i] & 0x7C00) >> 10;

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

        gPaletteFadeBuffers[2][i] = (b[0] << 10) | (g[0] << 5) | r[0];
    }
    DmaCopy16(3, gPaletteFadeBuffers[2], dest, arg2);
}

void FlashWhiteTransitionIn(void)
{
    REG_BLDY = 0x10;
    REG_BLDCNT = ((REG_DISPCNT & (DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON)) >> 8) | BLDCNT_EFFECT_LIGHTEN | BLDCNT_TGT1_BD;
    REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
    gMain.dispcntBackup = REG_DISPCNT;
    REG_BLDY = 0x10;
    MainLoopIter();
    REG_BLDY = 0x8;
    MainLoopIter();
    REG_BLDY = 0;
    MainLoopIter();
    REG_BLDCNT = 0;
}

void FlashWhiteTransitionOut(void)
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

void UnblankLCD(void)
{
    REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
    gMain.dispcntBackup = REG_DISPCNT;
}

void ForceBlankLCD(void)
{
    gMain.dispcntBackup |= DISPCNT_FORCED_BLANK;
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
}

void DisableDisplayInterrupts(void)
{
    REG_DISPSTAT &= ~DISPSTAT_VBLANK_INTR;
    REG_DISPSTAT &= ~DISPSTAT_VCOUNT_INTR;
    REG_IE &= 0x3FFF;
    REG_IE &= 0x3FFE;
    if(REG_IE == 0)
        REG_IME = 0;
    REG_IF |= 1;
}

void PrintString(u16 glyph, u16 palette, int x, int y, int width, int height)
{
    u16 i, j;

    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++)
            gBG0TilemapBuffer[y * 0x20 + x + j * 0x20 + i] = (glyph + j * 0x20 + i) | (palette << 12);
}

void CopyString(int srcX, int srcY, int destX, int destY, int width, int height)
{
    u16 i, j;

    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++)
            gBG0TilemapBuffer[destY * 0x20 + destX + j * 0x20 + i] = gBG0TilemapBuffer[srcY * 0x20 + srcX + j * 0x20 + i];
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
            gBG0TilemapBuffer[index] = (gBG0TilemapBuffer[index] & 0xFFF) | (palette << 12);
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
void CopyPixelCanvasRect(void *volatile src, void *volatile dest, s16 width, s16 height)
{
    int j;

    for (j = 0; j < height; j++)
    {
        DmaCopy16(3, (u8 *)src + 0x40 * j, (u8 *)dest + 0x40 * j, width * 2);
    }
}

// This function is unused.
void Unused_FadeInWithCustomPalettes(void *src1, void *src2, void (*func)(void))
{
    u16 i;

    DmaCopy16(3, src1, gPaletteFadeBuffers[1], BG_PLTT_SIZE);
    DmaCopy16(3, src2, gPaletteFadeBuffers[2], BG_PLTT_SIZE);
    DmaFill16(3, RGB_WHITE, gPaletteFadeBuffers, PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[0], gPaletteFadeBuffers[2], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[2], (void *)PLTT, PLTT_SIZE);

    UnblankLCD();
    gMain.dispcntBackup = REG_DISPCNT;

    for (i = 0; i <= 0x20; i += 0x10)
    {
        if (func != NULL)
            func();

        InterpolatePaletteStep(i);
        MainLoopIter();
        if (i == 0x20)
        {
            DmaCopy16(3, gPaletteFadeBuffers[1], (void *)PLTT, PLTT_SIZE);
        }
        else
        {
            DmaCopy16(3, gPaletteFadeBuffers[2], (void *)PLTT, PLTT_SIZE);
        }
    }
}

// This function is unused.
void Unused_FadeOutToWhite(void (*func)(void))
{
    u16 i;

    DmaCopy16(3, (void *)PLTT, gPaletteFadeBuffers[0], PLTT_SIZE);
    DmaFill16(3, RGB_WHITE, gPaletteFadeBuffers[1], PLTT_SIZE);
    DmaCopy16(3, gPaletteFadeBuffers[0], gPaletteFadeBuffers[2], PLTT_SIZE);

    for (i = 0; i <= 0x20; i += 0x10)
    {
        if (func != NULL)
            func();
        InterpolatePaletteStep(i);
        MainLoopIter();
        if (i == 0x20)
        {
            DmaCopy16(3, gPaletteFadeBuffers[1], (void *)PLTT, PLTT_SIZE);
        }
        else
        {
            DmaCopy16(3, gPaletteFadeBuffers[2], (void *)PLTT, PLTT_SIZE);
        }
    }
    MainLoopIter();
}
