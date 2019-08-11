#include "global.h"
#include "main.h"
#include "m4a.h"
#include "titlescreen.h"

extern void (*gUnknown_080792C0[])(void);

extern u16 gFieldSelectBGPals[];
extern u8 gFieldSelectWindow_Gfx[];
extern u8 gFieldSelectMiniFields_Gfx[];
extern u8 gUnknown_080A2400[];
extern u8 gFieldSelectFrameShadowTilemap[];
extern u8 gFieldSelectWindowTilemap[];
extern u16 gFieldSelectSpritePals[];
extern u8 gFieldSelectSpriteGfx[];
extern s8 gUnknown_02002850;

extern void sub_8F94(void);
extern void sub_8C38(void);

struct FieldSelectData
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    s16 unkC;
    s16 unkE;
    u8 unk10;
    s16 unk12;
    s8 unk14;
    u16 unk16;
};

extern struct FieldSelectData gUnknown_02002838;

void FieldSelectMain(void)
{
    gUnknown_080792C0[gMain.subState]();
}

void LoadFieldSelectGraphics(void)
{
    sub_438();

    REG_DISPCNT = 0x1080;
    REG_BG0CNT = 4;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0x105;
    REG_DISPCNT |= 0x200;
    REG_BG2CNT = 0x20A;
    REG_DISPCNT |= 0x400;

    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gFieldSelectBGPals,             (void *)PLTT, 0x200);
    DmaCopy16(3, gFieldSelectWindow_Gfx,         (void *)(VRAM + 0x4000), 0x1400);
    DmaCopy16(3, gFieldSelectMiniFields_Gfx,     (void *)(VRAM + 0x8000), 0x3800);
    DmaCopy16(3, gUnknown_080A2400,              (void *)(VRAM), 0x800);
    DmaCopy16(3, gFieldSelectFrameShadowTilemap, (void *)(VRAM + 0x800), 0x800);
    DmaCopy16(3, gFieldSelectWindowTilemap,      (void *)(VRAM + 0x1000), 0x800);
    DmaCopy16(3, gFieldSelectSpritePals,         (void *)(PLTT + 0x200), 0x200);
    DmaCopy16(3, gFieldSelectSpriteGfx,          (void *)(VRAM + 0x10000), 0x4020);

    sub_CBC();
    sub_8C38();
    sub_FD5C(sub_8F94);
    gMain.subState++;
    m4aSongNumStart(3);
}

void sub_8C38(void)
{
    gUnknown_02002838.unk0 = 2;
    gUnknown_02002838.unk2 = 3;
    gUnknown_02002838.unk4 = 0;
    gUnknown_02002838.unk6 = 1;
    gUnknown_02002838.unk8 = 0;
    gUnknown_02002838.unkA = 0;
    gUnknown_02002838.unkC = 0;
    gUnknown_02002838.unkE = 0;
    gUnknown_02002838.unk16 = 0;
    gUnknown_02002838.unk12 = 0;
    gUnknown_02002838.unk14 = 0;

    gUnknown_02002838.unk10 = gMain_saveData.unk142;
    gMain.unk4 = 0;
    gUnknown_02002850 = 0;
}

extern struct {u16 unk0[5]; u16 unkA[5];} gUnknown_086A6B14;

void sub_8C7C(void)
{
    sub_8F94();
    if ((gMain.heldKeys & 0xF) == 0xF)
    {
        gUnknown_02002850 = 1;
        gUnknown_02002838.unk16 = 0;
        gMain.subState++;
    }
    if (gUnknown_02002850 == 0)
    {
        switch (gUnknown_02002838.unkA)
        {
        case 0:
            if (gMain.newKeys & 0x20)
            {
                if (gUnknown_02002838.unk8 == 1)
                {
                    m4aSongNumStart(0x6D);
                    gUnknown_02002838.unk8 = 0;
                    gUnknown_02002838.unk4 = 0;
                    gUnknown_02002838.unk6 = 1;
                    gUnknown_02002838.unkA = 1;
                }
            }
            else if (gMain.newKeys & 0x10)
            {
                if (gUnknown_02002838.unk8 == 0)
                {
                    m4aSongNumStart(0x6D);
                    gUnknown_02002838.unk8 = 1;
                    gUnknown_02002838.unk4 = 1;
                    gUnknown_02002838.unk6 = 0;
                    gUnknown_02002838.unkA = 1;
                }
            }
            if (gMain.newKeys & 1)
            {
                m4aSongNumStart(0x65);
                gUnknown_02002838.unkA = 2;
                gUnknown_02002838.unk14 = 1;
                gUnknown_02002838.unkE = 0;
                if (gUnknown_02002838.unk8 == 0)
                {
                    gUnknown_02002838.unk4 = 0;
                    gUnknown_02002838.unk6 = 1;
                    gUnknown_02002838.unk0 = 2;
                    gUnknown_02002838.unk2 = 3;
                    gUnknown_02002838.unkC = 0;
                }
                else
                {
                    gUnknown_02002838.unk4 = 1;
                    gUnknown_02002838.unk6 = 0;
                    gUnknown_02002838.unk0 = 7;
                    gUnknown_02002838.unk2 = 11;
                    gUnknown_02002838.unkC = 0;
                }
            }
            if (gMain.newKeys & 2)
            {
                m4aSongNumStart(0x66);
                gMain.subState++;
                gUnknown_02002838.unk16 = 1;
                if (gUnknown_02002838.unk8 == 0)
                {
                    gUnknown_02002838.unk4 = 0;
                    gUnknown_02002838.unk6 = 1;
                    gUnknown_02002838.unk0 = 2;
                    gUnknown_02002838.unk2 = 3;
                    gUnknown_02002838.unkC = 0;
                }
                else
                {
                    gUnknown_02002838.unk4 = 1;
                    gUnknown_02002838.unk6 = 0;
                    gUnknown_02002838.unk0 = 7;
                    gUnknown_02002838.unk2 = 11;
                    gUnknown_02002838.unkC = 0;
                }
            }
            if (gMain.unk4 < 2)
                gMain.unk6 = 0;
            else
                gMain.unk6 = 1;
            break;
        case 2:
            if (gMain.newKeys & 0x30)
            {
                m4aSongNumStart(0x67);
                gUnknown_02002838.unk10 = 1 - gUnknown_02002838.unk10;
            }
            if (gMain.newKeys & 1)
            {
                m4aSongNumStart(0x65);
                gUnknown_02002838.unkE = 0;
                gUnknown_02002838.unkC = 0;
                gMain_saveData.unk142 = gUnknown_02002838.unk10;
                SaveFile_WriteToSram();
                gUnknown_02002838.unkA = 3;
            }
            if (gMain.newKeys & 2)
            {
                m4aSongNumStart(0x66);
                gUnknown_02002838.unk14 = 0;
                gUnknown_02002838.unkA = 0;
            }
            gUnknown_02002838.unkE++;
            if (gUnknown_02002838.unkE > 4)
            {
                gUnknown_02002838.unkE = 0;
                gUnknown_02002838.unk12 = 1 - gUnknown_02002838.unk12;
            }
            break;
        case 1:
            if (gUnknown_02002838.unk8 == 0)
            {
                gUnknown_02002838.unk0 = gUnknown_086A6B14.unk0[4 - gUnknown_02002838.unkC];
                gUnknown_02002838.unk2 = gUnknown_086A6B14.unkA[4 - gUnknown_02002838.unkC];
            }
            else
            {
                gUnknown_02002838.unk0 = gUnknown_086A6B14.unk0[gUnknown_02002838.unkC];
                gUnknown_02002838.unk2 = gUnknown_086A6B14.unkA[gUnknown_02002838.unkC];
            }
            if (!(gMain.unk4C & 1))
            {
                if (gUnknown_02002838.unkC < 4)
                {
                    gUnknown_02002838.unkC++;
                }
                else
                {
                    gUnknown_02002838.unkC = 0;
                    gUnknown_02002838.unkA = 0;
                }
            }
            if (gMain.newKeys & 0x20)
            {
                if (gUnknown_02002838.unk8 == 1)
                {
                    m4aSongNumStart(0x6D);
                    gUnknown_02002838.unk8 = 0;
                    gUnknown_02002838.unk4 = 0;
                    gUnknown_02002838.unk6 = 1;
                    gUnknown_02002838.unk0 = 2;
                    gUnknown_02002838.unk2 = 3;
                    gUnknown_02002838.unkC = 0;
                    gUnknown_02002838.unkA = 0;
                }
            }
            else if (gMain.newKeys & 0x10)
            {
                if (gUnknown_02002838.unk8 == 0)
                {
                    m4aSongNumStart(0x6D);
                    gUnknown_02002838.unk8 = 1;
                    gUnknown_02002838.unk4 = 1;
                    gUnknown_02002838.unk6 = 0;
                    gUnknown_02002838.unk0 = 7;
                    gUnknown_02002838.unk2 = 11;
                    gUnknown_02002838.unkC = 0;
                    gUnknown_02002838.unkA = 0;
                }
            }
            break;
        case 3:
            gUnknown_02002838.unkE++;
            if (gUnknown_02002838.unkE > 3)
            {
                gUnknown_02002838.unkE = 0;
                if (gUnknown_02002838.unk8 == 0)
                    gUnknown_02002838.unk4 = 1 - gUnknown_02002838.unk4;
                else
                    gUnknown_02002838.unk6 = 1 - gUnknown_02002838.unk6;
                gUnknown_02002838.unkC++;
                if (gUnknown_02002838.unkC > 5)
                {
                    gUnknown_02002838.unk16 = 2;
                    gMain.subState++;
                }
            }
            break;
        }
        gMain.unk4 = gUnknown_02002838.unk8;
        gMain.unk5 = gUnknown_02002838.unk8;
    }
}

void sub_8F64(void)
{
    sub_FE04(sub_8F94);
    m4aMPlayAllStop();
    sub_D10();
    gAutoDisplayTitlescreenMenu = 1;
    SetMainGameState(gUnknown_02002838.unk16);
}

extern const struct SpriteSet *const gUnknown_086A6AD4[];
extern struct Coord16 gUnknown_086A6B28[];

void sub_8F94(void)
{
    struct SpriteGroup *r6;
    struct SpriteGroup *r9;
    struct SpriteGroup *sp0;
    struct SpriteGroup *r10;
    struct SpriteGroup *r8;
    const struct SpriteSet *spriteSet;
    int i;

    gMain.blendControl = 0x642;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    r6 = &gMain.spriteGroups[0];
    r9 = &gMain.spriteGroups[1];
    sp0 = &gMain.spriteGroups[gUnknown_02002838.unk0];
    r10 = &gMain.spriteGroups[gUnknown_02002838.unk2];
    r8 = &gMain.spriteGroups[12 + gUnknown_02002838.unk10 * 2 + gUnknown_02002838.unk12];

    r6->available = gUnknown_02002838.unk4;
    r9->available = gUnknown_02002838.unk6;
    sp0->available = 1;
    r10->available = 1;
    r8->available = gUnknown_02002838.unk14;

    LoadSpriteSets(gUnknown_086A6AD4, 16, r6);

    if (gUnknown_02002838.unk4 == 1)
    {
        r6->baseX = 0x25;
        r6->baseY = 0x18;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[r6->oam[i].oamId].x = r6->oam[i].xOffset + r6->baseX;
            gOamBuffer[r6->oam[i].oamId].y = r6->oam[i].yOffset + r6->baseY;
        }
    }

    if (gUnknown_02002838.unk6 == 1)
    {
        r9->baseX = 0x8D;
        r9->baseY = 0x18;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[r9->oam[i].oamId].x = r9->oam[i].xOffset + r9->baseX;
            gOamBuffer[r9->oam[i].oamId].y = r9->oam[i].yOffset + r9->baseY;
        }
    }

    sp0->baseX = 32;
    sp0->baseY = 32;
    spriteSet = gUnknown_086A6AD4[gUnknown_02002838.unk0];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[sp0->oam[i].oamId].objMode = 1;
        gOamBuffer[sp0->oam[i].oamId].x = sp0->oam[i].xOffset + sp0->baseX;
        gOamBuffer[sp0->oam[i].oamId].y = sp0->oam[i].yOffset + sp0->baseY;
    }

    r10->baseX = 0x88;
    r10->baseY = 32;
    spriteSet = gUnknown_086A6AD4[gUnknown_02002838.unk2];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[r10->oam[i].oamId].objMode = 1;
        gOamBuffer[r10->oam[i].oamId].x = r10->oam[i].xOffset + r10->baseX;
        gOamBuffer[r10->oam[i].oamId].y = r10->oam[i].yOffset + r10->baseY;
    }

    if (r8->available == 1)
    {
        r8->baseX = gUnknown_086A6B28[gUnknown_02002838.unk8].x;
        r8->baseY = gUnknown_086A6B28[gUnknown_02002838.unk8].y;
        for (i = 0; i < 5; i++)
        {
            gOamBuffer[r8->oam[i].oamId].objMode = 0;
            gOamBuffer[r8->oam[i].oamId].x = r8->oam[i].xOffset + r8->baseX;
            gOamBuffer[r8->oam[i].oamId].y = r8->oam[i].yOffset + r8->baseY;
        }
    }

    sp0->available = 0;
    r10->available = 0;
    r8->available = 0;
}
