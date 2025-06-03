//
// Created by Delta on 6/3/25.
//
#include "global.h"
#include "main.h"

void sub_50FAC(void)
{
    const struct SpriteSetTableEntry *table = gUnknown_086B155C;
    const struct SpriteSetTableEntry *entry = &table[gMain.selectedField];
    LoadSpriteSets(entry->spriteSets, entry->numSpriteSets, gMain.spriteGroups);
}
