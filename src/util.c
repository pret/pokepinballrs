#include "global.h"
#include "main.h"

static u8 *sub_734(u32, u8*, u32);
static int sub_780(int, int);

void SetMainGameState(u16 mainState)
{
    gMain.mainState = mainState;
    gMain.subState = 0;
}

void sub_24C(void)
{
    u16 i;

    REG_BLDCNT = 0;
    REG_BLDY = 0x10;
    REG_BLDCNT = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8)
                | BLDCNT_EFFECT_LIGHTEN
                | BLDCNT_TGT1_BD;
    REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
    gMain.unk16 = REG_DISPCNT;

    for (i = 0; i < 32; i++)
    {
        REG_BLDY = 15 - i / 2;
        MainLoopIter();
    }

    REG_BLDCNT = 0;
}

void sub_2B4(void)
{
    u16 i;

    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_BLDCNT = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8)
                | BLDCNT_EFFECT_LIGHTEN
                | BLDCNT_TGT1_BD;

    for (i = 0; i < 16; i++)
    {
        REG_BLDY = i + 1;
        MainLoopIter();
    }

    gMain.unk16 |= DISPCNT_FORCED_BLANK;
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
    DmaFill16(3, 0, (void *)BG_VRAM, 0x18000);
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
}

s16 LoadSpriteSets(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups)
{
    u16 i, j;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *oamData = (u16 *)(&gOamBuffer[0]);
    u16 loadedCount = 0;

    DmaCopy16(3, gEmptyOamData, oamData, sizeof(gEmptyOamData));
    for (i = 0; i < numSpriteSets; i++)
    {
        spriteGroup = &spriteGroups[i];
        if (spriteGroup->available)
        {
            u16 curSpriteSetCount = spriteSets[i]->count;
            DmaCopy16(3, spriteSets[i]->oamData, &gOamBuffer[loadedCount], curSpriteSetCount * sizeof(struct OamData));
            for (j = 0; j < curSpriteSetCount; j++)
            {
                oamData = (u16 *)(&gOamBuffer[loadedCount]);
                oamSimple = &spriteGroup->oam[j];
                oamSimple->oamId = loadedCount++;
                oamSimple->xOffset = oamData[1] & 0x1FF;
                oamSimple->yOffset = oamData[0] & 0xFF;
            }
        }
    }

    return loadedCount;
}

void ResetSomeGraphicsRelatedStuff(void)
{
    gMain.unk16 |= DISPCNT_FORCED_BLANK;
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
    ClearGraphicsMemory();
    sub_518();
    ClearSprites();
    gMain.unkF = 0;
    gMain.unk10 = 0;
    gMain.unk50 = 0;
    gMain.unk11 = 0;
    gMain.unk12 = 0;
    gMain.unk14 = 0;
    gMain.vCount = 144;
    gMain.unk28 = 0;
    gMain.unk2A = 0;
    gMain.unk36 = 0;
    gMain.blendControl = 0;
    gMain.blendAlpha = 0;
    gMain.blendBrightness = 0;
    gMain.unk2C = 0;
}

void ClearGraphicsMemory(void)
{
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)PLTT, BG_PLTT_SIZE + OBJ_PLTT_SIZE);
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_DISPSTAT = 0;
    REG_BLDALPHA = 0;
}

void sub_518(void)
{
    s16 i;

    DmaFill16(3, 0, gUnknown_03005C00, sizeof(gUnknown_03005C00));
    for (i = 0; i < 4; i++)
    {
        gMain.unk2E8[i].unk0 = 0;
        gMain.unk2E8[i].unk2 = 0;
    }
}

void ClearSprites(void)
{
    u16 i, j;

    for (i = 0; i < NUM_SPRITE_GROUPS; i++)
    {
        gMain.spriteGroups[i].available = 0;
        gMain.spriteGroups[i].baseX = 0;
        gMain.spriteGroups[i].baseY = 0;
        for (j = 0; j < MAX_SPRITES_IN_GROUP; j++)
        {
            gMain.spriteGroups[i].oam[j].oamId = 0;
            gMain.spriteGroups[i].oam[j].xOffset = 0;
            gMain.spriteGroups[i].oam[j].yOffset = 0;
        }
    }

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].y = 244;
        gOamBuffer[i].affineMode = 0;
        gOamBuffer[i].objMode = 0;
        gOamBuffer[i].mosaic = 0;
        gOamBuffer[i].bpp = 0;
        gOamBuffer[i].shape = 0;
        gOamBuffer[i].x = 500;
        gOamBuffer[i].matrixNum = 0;
        gOamBuffer[i].hFlip = 0;
        gOamBuffer[i].vFlip = 0;
        gOamBuffer[i].size = 0;
        gOamBuffer[i].tileNum = 0;
        gOamBuffer[i].priority = 0;
        gOamBuffer[i].paletteNum = 0;
        gOamBuffer[i].affineParam = 0;
    }
}

void sub_678(u8 *arg0, s16 arg1, s16 arg2)
{
    // Rumble Pak related?
    s16 var0 = strlen(arg0) - 1;
    u16 *dest = &gUnknown_03005C00[arg1 * 32 + arg2];
    do
    {
        *dest = (*arg0) - 32;
        arg0++;
        dest++;
    } while (var0-- > 0);
}

u8 *sub_6CC(int arg0, u8 *arg1, int arg2, s16 arg3)
{
    if (arg0 < 0)
    {
        *arg1 = 0x2D;
        arg1++;
        arg0 = -arg0;
    }

    while (1)
    {
        if (arg2 < 2)
            break;
        
        arg2--;
        if (arg0 < sub_780(10, arg2))
        {
            *arg1 = 0x30;
            arg1++;
        }
        else
        {
            break;
        }
    }

    if (arg3)
    {
        sub_734(arg0, arg1, 10);
    }
    else
    {
        u8 *ptr = sub_734(arg0, arg1, 10);
        *ptr = 0;
    }

    return arg1;
}

static u8 *sub_734(u32 arg0, u8 *arg1, u32 arg2)
{
    u8 mod = arg0 % arg2;
    int div = arg0 / arg2;
    if (div != 0)
        arg1 = sub_734(div, arg1, arg2);

    if (mod < 10)
        *arg1 = mod + 48;
    else
        *arg1 = mod + 87;

    return arg1 + 1;
}

static int sub_780(int arg0, int arg1)
{
    int var0;
    int var1 = arg1;

    if (arg1 < 0)
        var1 = -var1;

    var0 = 1;
    while (var1)
    {
        if (var1 & 1)
            var0 *= arg0;

        arg0 *= arg0;
        var1 >>= 1;
    }

    if (arg1 >= 0)
        return var0;
    else
        return 1 / var0;
}

void SetMatrixScale(s16 xScale, s16 yScale, s16 matrixNum)
{
    vu16 a2, b2, c2, d2;
    u16 a = 0x10000 / xScale;
    u32 d = 0x10000 / yScale;
    a2 = a;
    b2 = 0;
    c2 = 0;
    // There is a delayed u16 shift here that is tricky to produce.
#ifndef NONMATCHING
    asm_unified("lsls r0, r0, #0x10\n\
                 lsrs r0, r0, #0x10");
#endif
    d2 = d;

    gOamBuffer[matrixNum * 4 ].affineParam = a2;
    gOamBuffer[matrixNum * 4 + 1].affineParam = b2;
    gOamBuffer[matrixNum * 4 + 2].affineParam = c2;
    gOamBuffer[matrixNum * 4 + 3].affineParam = d;
}
