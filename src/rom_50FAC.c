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
