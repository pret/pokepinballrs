#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
extern const u16 gUnknown_0847DF0C[];
extern s8 gUnknown_084FEF0C[][0x80];

void sub_2C538(void) {
    s16 i;
    s32 x;
    s32 y;
    s32 distSquared;
    s16 var_sb;
    struct OamDataSimple *oamSimple;

    struct SpriteGroup *group;

    var_sb = 0;
    switch (gCurrentPinballGame->unk300) {
    case 0:
        var_sb = (gCurrentPinballGame->unk304 % 36) / 18;
        gCurrentPinballGame->unk304++;
        gCurrentPinballGame->unk301 = 0;
        break;
    case 1:
        var_sb = (gCurrentPinballGame->unk304 % 36) / 18 + 2;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk301 != 0) {
            gCurrentPinballGame->unk300 = 2;
            gCurrentPinballGame->unk304 = 0;
        }
        gCurrentPinballGame->unk301 = 0;
        break;
    case 2:
        var_sb = (gCurrentPinballGame->unk304 % 9) / 3 + 4;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 == 9) {
             gCurrentPinballGame->unk300 = 3;  
            gCurrentPinballGame->unk304 = 0;
        }
        break;
    case 3:
        var_sb = (gCurrentPinballGame->unk304 % 36) / 18 + 2;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 > 0x41) {
            gCurrentPinballGame->unk300 = 1;
            gCurrentPinballGame->unk304 = 0;
        }
        if (gCurrentPinballGame->unk304 > 6 && gCurrentPinballGame->unk301 != 0) {
            gCurrentPinballGame->unk300 = 4;
            gCurrentPinballGame->unk304 = 0;
            gCurrentPinballGame->unk301 = 0;
        }
        break;
    case 4:
        var_sb = (gCurrentPinballGame->unk304 % 9) / 3 + 7;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 == 9) {
             gCurrentPinballGame->unk300 = 5;
            gCurrentPinballGame->unk304 = 0;
        }
        break;
    case 5:
        var_sb = (gCurrentPinballGame->unk304 % 36) / 18 + 2;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 > 0x41U) {
            gCurrentPinballGame->unk300 = 1;
            gCurrentPinballGame->unk304 = 0;
        }
        if (gCurrentPinballGame->unk304 > 6 && gCurrentPinballGame->unk301 != 0) {
            gCurrentPinballGame->unk300 = 2;
            gCurrentPinballGame->unk304 = 0;
            gCurrentPinballGame->unk301 = 0;
        }
        break;
    }
    group = &gMain.spriteGroups[68];
    if ( group->available != 0) {
        if ( gCurrentPinballGame->unk300 <= 2) {
            group->baseX = 0xBC - gCurrentPinballGame->unk58;
            group->baseY = 0x119 - gCurrentPinballGame->unk5A;
        } else {
            group->baseX = 0xC0 - gCurrentPinballGame->unk58;
            group->baseY = 0x116 - gCurrentPinballGame->unk5A;
        }
        
        if (gCurrentPinballGame->unk302 > 0) {
            gCurrentPinballGame->unk302--;
            if (gCurrentPinballGame->unk302 == 0) {
                gMain.spriteGroups[68].available = 0;
            }
        }
       
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
    if ((gCurrentPinballGame->unk300 == 4) || (gCurrentPinballGame->unk300 == 2)) {
        x = gCurrentPinballGame->ball->positionQ0.x - 0xBE;
        y = gCurrentPinballGame->ball->positionQ0.y - 0x11D;
        distSquared = (x * x) + (y * y);
        if(distSquared >= 0 && distSquared <= 0x8C) {
            if (gCurrentPinballGame->unk302 <= 0) {
                m4aSongNumStart(0xC5);
                gCurrentPinballGame->unk3C = 0x2710;
                gCurrentPinballGame->ball->velocity.x = -0x258;
                gCurrentPinballGame->ball->velocity.y = -0x12C;
                gCurrentPinballGame->ball->unk6 = 0;
                gMain.spriteGroups[68].available = 1;
                gCurrentPinballGame->unk302 = 6;
                sub_11B0(8);
            }
        }
    }
    group = &gMain.spriteGroups[58];
    if ( group->available != 0) {
        group->baseX = 0xB8 - gCurrentPinballGame->unk58;        
        group->baseY = 0x115 - gCurrentPinballGame->unk5A;
        DmaCopy16(3, &gUnknown_0847DF0C[var_sb * 0x180], (void*) 0x06013580, 0x300);
        for(i=0; i<=2;i++) {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset+ group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset+group->baseY;

        }
    }
}


void sub_2C9A4(void) {
    struct OamDataSimple *oamSimple;
    s32 var_r0;
    struct OamData *oamData;
    struct SpriteGroup *group = &gMain.spriteGroups[66];

    if (group->available != 0) {
        if ((s8) gCurrentPinballGame->unk29F != 0) {
            group->baseY = ((u32) (gCurrentPinballGame->unk290 & 0x1F) >> 3) - (gCurrentPinballGame->unk5A - 0x34);
        } else {
            group->baseY = 0xB4;
        }
        group->baseX = 0x78 - gCurrentPinballGame->unk58;
        if ((s8) gCurrentPinballGame->unk29F == 1) {
            var_r0 = ((u32) (gCurrentPinballGame->unk290 & 0x1F) >> 3) + 4;
        } else {
            var_r0 = (s32) ((u32) (gCurrentPinballGame->unk290 & 0x1F) >> 3);
        }
        DmaCopy16(3, gUnknown_084FEF0C[var_r0], (void *) 0x06014B00, 0x80);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x =  oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y =  oamSimple->yOffset + group->baseY;
    }
}