#include "global.h"
#include "functions.h"
#include "main.h"
#include "variables.h"

extern u32 gUnknown_0202ADD0;
extern s16 gUnknown_0201A444;
extern u32 gUnknown_0202BDF0;
extern u8 gUnknown_0201C1AC;
extern u8 gUnknown_0202ADDC;

s16 sub_2414(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups)
{
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *simple;
    u16 *oamData;
    u16 i;
    u16 j;
    u16 pos;
    u16 numSpritesInGroup;

    oamData = (u16 *)gOamBuffer;
    pos = 0;
    CpuCopy16(gEmptyOamData, oamData, sizeof(gOamBuffer));

    for (i = 0; i < numSpriteSets; i++) {
        spriteGroup = &spriteGroups[i];
        if (!spriteGroup->available) {
            continue;
        }
        numSpritesInGroup = spriteSets[i]->count;
        CpuCopy16(spriteSets[i]->oamData, &gOamBuffer[pos], numSpritesInGroup * sizeof(struct OamData));
        for (j = 0; j < numSpritesInGroup; j++) {
            oamData = (u16 *)&gOamBuffer[pos];
            simple = &spriteGroup->oam[j];

            simple->oamId = pos++;
            simple->xOffset = oamData[1] & 0x1FF;
            simple->yOffset = oamData[0] & 0xFF;
        }
    }
    return pos;
}

void nullsub_16(void)
{
}

void sub_24DC(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = 0;

    REG_SIOMLT_SEND = 0;
    REG_SIOMULTI0 = 0;
    REG_SIOMLT_SEND = 0;
    REG_SIOMULTI0 = 0;

    REG_SIOMULTI0 = 0;
    REG_SIOMULTI1 = 0;
    REG_SIOMULTI2 = 0;
    REG_SIOMULTI3 = 0;
}

void sub_250C(void)
{
    REG_IME = 0;
    REG_IE = INTR_FLAG_GAMEPAK | INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
}

void sub_2538(void)
{
    gUnknown_0202ADD0 = 0;
    gUnknown_0201A444 = 0;
    gUnknown_0202BDF0 = 0;
    gUnknown_0201C1AC = 0;
    gUnknown_0202ADDC = 0;
}

void sub_2568(void)
{
    sub_24DC();
    REG_IME = 0;
    ResetMainCallback();
    ResetVBlankIntrFunc();
    REG_IE = INTR_FLAG_GAMEPAK | INTR_FLAG_VCOUNT | INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_VCOUNT_INTR  | DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
}

