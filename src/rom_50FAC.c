#include "global.h"
#include "main.h"

void sub_50FAC(void)
{
    const struct SpriteSetTableEntry *table = gUnknown_086B155C;
    const struct SpriteSetTableEntry *entry = &table[gMain.selectedField];
    LoadSpriteSets(entry->spriteSets, entry->numSpriteSets, gMain.spriteGroups);
}

void sub_50FD4(void)
{
    s16 i;

    // Initialize first 32 sprite groups
    for (i = 0; i < 32; i++) {
        if (i <= 4) {
            gMain.spriteGroups[i].available = 1;
        } else {
            gMain.spriteGroups[i].available = 0;
        }
    }

    // Set specific sprite groups as available
    (*gMain.unk44)->available = 1;              // gMain + 0x44 -> pointer -> available

    // Direct calculations without storing offset in variable
    *(u16*)((u8*)&gMain + (0xae << 4)) = 1;
    *(u16*)((u8*)&gMain + (0xae << 4) + 0xb8) = 1;
    *(u16*)((u8*)&gMain + (0xae << 4) + 0xb8 + 0xb8) = 1;
    *(u16*)((u8*)&gMain + (0xae << 4) + 0xb8 + 0xb8 + 0xb8) = 1;

    *(u16*)((u8*)&gMain + 0x17d0) = 1;          // gMain + 0x17d0

    // Load sprite sets for current field
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_51068(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                          gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                          gMain.spriteGroups);
}

void sub_51090(void)
{
    s16 i;

    for (i = 0; i <= 45; i++)
    {
        if (i <= 4)
            gMain.spriteGroups[i].available = 1;
        else
            gMain.spriteGroups[i].available = 0;
    }

    (*gMain.unk44)->available = 1;
    gMain.spriteGroups[42].available = 1;
    gMain.spriteGroups[11].available = 1;
    gMain.spriteGroups[12].available = 1;
    gMain.spriteGroups[13].available = 1;
    gMain.spriteGroups[21].available = 1;

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_51128(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_51150(void)
{
    s16 i;

    for (i = 0; i <= 22; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].available = 1;
        else
            gMain.spriteGroups[i].available = 0;
    }

    (*gMain.unk44)->available = 1;
    *(u16 *)((u8 *)&gMain + 0xFE8) = 1;
    *(u16 *)((u8 *)&gMain + 0x1210) = 1;
    *(u16 *)((u8 *)&gMain + 0x12C8) = 1;
    *(u16 *)((u8 *)&gMain + 0xD08) = 1;
    *(u16 *)((u8 *)&gMain + 0xDC0) = 1;
    *(u16 *)((u8 *)&gMain + 0xE78) = 1;
    *(u16 *)((u8 *)&gMain + 0xF30) = 1;

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                             gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                             gMain.spriteGroups);
}

void sub_511F8(void) {
    const struct SpriteSetTableEntry *table = gUnknown_086B155C;
    const struct SpriteSetTableEntry *entry = &table[gMain.selectedField];
    LoadSpriteSets(entry->spriteSets, entry->numSpriteSets, gMain.spriteGroups);
}
