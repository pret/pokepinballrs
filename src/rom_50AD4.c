#include "global.h"
#include "main.h"

void sub_50AD4(void) {
    s16 i;
    for(i = 0; i <= 86; i++){
        gMain.spriteGroups[i].available = 0;
    }
    gMain.spriteGroups[72].available = 1;
    gMain.spriteGroups[63].available = 1;
    gMain.spriteGroups[60].available = 1;
    gMain.spriteGroups[69].available = 1;
    gMain.spriteGroups[52].available = 1;
    gMain.spriteGroups[74].available = 1;
    gMain.spriteGroups[0].available = 1;
    gMain.spriteGroups[1].available = 1;
    gMain.spriteGroups[2].available = 1;
    gMain.spriteGroups[25].available = 1;
    gMain.spriteGroups[85].available = 1;
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}