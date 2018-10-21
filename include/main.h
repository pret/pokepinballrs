#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

#define NUM_SPRITE_GROUPS 100
#define MAX_SPRITES_IN_GROUP 22

typedef void (*StateFunc)(void);

struct MainUnk2E8
{
    u16 unk0;
    u16 unk2;
};

struct SpriteSet
{
    u16 count;
    u8 oamData[0];
};

struct OamDataSimple
{
    u16 oamId;
    s16 xOffset;
    s16 yOffset;
};

struct SpriteGroup
{
    u16 available;
    s16 baseX;
    s16 baseY;
    struct OamDataSimple oam[MAX_SPRITES_IN_GROUP];
};
// size: 0xB8

struct Main
{
    /*0x00*/ u8 filler0[0x2];
    /*0x02*/ u8 mainState;
    /*0x03*/ u8 subState;
    /*0x04*/ u8 filler4[0x9];
    /*0x0D*/ u8 unkD;
    /*0x0E*/ u8 fillerE[0x1];
    /*0x0F*/ u8 unkF;
    /*0x10*/ u8 unk10;
    /*0x11*/ u8 unk11;
    /*0x12*/ s16 unk12;
    /*0x14*/ s16 unk14;
    /*0x16*/ u16 unk16;
    /*0x18*/ u16 newKeys;
    /*0x1A*/ u16 releasedKeys;
    /*0x1C*/ u16 heldKeys;
    /*0x1E*/ u8 filler1E[0x8];
    /*0x26*/ u16 unk26;
    /*0x28*/ u16 unk28;
    /*0x2A*/ u16 unk2A;
    /*0x2C*/ u16 unk2C;
    /*0x2E*/ u8 filler2E[0x8];
    /*0x36*/ u8 unk36;
    /*0x38*/ volatile u16 unk38;
    /*0x3A*/ volatile u16 unk3A;
    /*0x3C*/ volatile u16 unk3C;
    /*0x40*/ int unk40;
    /*0x44*/ u8 filler44[0xC];
    /*0x50*/ int unk50;
    /*0x54*/ u8 filler54[0x294];
    /*0x2E8*/ struct MainUnk2E8 unk2E8[4];
    /*0x2F8*/ struct SpriteGroup spriteGroups[NUM_SPRITE_GROUPS];
};

extern struct Main gMain;
extern struct SpriteGroup gUnknown_0200B3B8[];
extern StateFunc gMainFuncs[];
extern struct OamData gOamBuffer[128];
extern u16 gUnknown_03005C00[0x600];

void SetMainGameState(u16);
void sub_24C(void);
void sub_2B4(void);
void sub_490(void);
void sub_518(void);
void sub_578(void);
void sub_D74(void);
s16 LoadSpriteSets(const struct SpriteSet* const*, u16, struct SpriteGroup*);

#endif // GUARD_MAIN_H
