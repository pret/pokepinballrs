#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

// This is probably permanently saved data like pokedex and high scores.
struct SaveData
{
    /*0x74*/ u8 pokedexFlags[204];
    /*0x140*/ u8 filler140[1];
    /*0x141*/ u8 unk141;
    /*0x142*/ u8 ballSpeed;
    /*0x143*/ u8 unk143;
    /*0x144*/ u16 unk144[0x65][2];
    /*0x2D8*/ s8 signature[10];
              u16 checksum;
              u32 unk2E4;
};

struct Main
{
    /*0x00*/ u8 filler0[0x2];
    /*0x02*/ u8 mainState;
    /*0x03*/ u8 subState;
    /*0x04*/ u8 unk4;
    /*0x05*/ u8 unk5;
    /*0x06*/ u8 unk6;
    /*0x07*/ s8 unk7;
    /*0x08*/ s8 unk8;
    /*0x09*/ u8 filler9[0x3];
    /*0x0C*/ u8 unkC;
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
    /*0x1E*/ u8 filler1E[0x2];
    /*0x20*/ u16 unk20;
    /*0x22*/ u8 filler22[0x4];
    /*0x26*/ s16 vCount;
    /*0x28*/ s16 unk28;
    /*0x2A*/ s16 unk2A;
    /*0x2C*/ s16 unk2C;
    /*0x2E*/ u8 filler2E[0x2];
    /*0x30*/ u16 unk30;
    /*0x32*/ u8 filler32[0x4];
    /*0x36*/ u8 unk36;
    /*0x38*/ volatile u16 blendControl;
    /*0x3A*/ volatile u16 blendAlpha;
    /*0x3C*/ volatile u16 blendBrightness;
             // may be a sub-struct. possibly for saved game?
    /*0x40*/ int hasSavedGame;
    /*0x44*/ u8 filler44[0x4];
    /*0x48*/ int rngValue;
    /*0x4C*/ int frameCount;
    /*0x50*/ int unk50;
    /*0x54*/ u8 filler54[0x20];

    // This field must be accessed using the following macro to produce matching code.
#define gMain_saveData (*(struct SaveData *)(&gMain.saveData))
    /*0x74*/  struct SaveData saveData;

    /*0x2E8*/ struct MainUnk2E8 unk2E8[4];
    /*0x2F8*/ struct SpriteGroup spriteGroups[NUM_SPRITE_GROUPS];
};


extern struct Main gMain;
extern struct SpriteGroup gUnknown_0200B3B8[];
extern u32 IntrMain_Buffer[0x200];
extern u32 IntrMain[];
extern IntrFunc *gVBlankIntrFuncPtr;
extern IntrFunc *gVCountIntrFuncPtr;
extern int gUnknown_02019BE4;
extern int gUnknown_02019BE8;
extern int gUnknown_02019BEC;
extern u32 gUnknown_02019BF0;
extern int gUnknown_02019BF4;
extern int gUnknown_02019BF8;
extern int gUnknown_02019BFC;
extern int gUnknown_02019C00;
extern int gUnknown_02019C04;
extern int gUnknown_02019C08;
extern int gGameBoyPlayerEnabled;
extern u8 gUnknown_02019C10;
extern u8 gUnknown_02002008[];
#define INTR_COUNT 14
extern IntrFunc gIntrTable[14];
extern void (*gMainCallback)(void);
extern void (*gUnknown_0200FBA0)(void);
extern void (*gUnknown_02017BD0)(void);
extern void (*gUnknown_02017BD4)(void);
extern StateFunc gMainFuncs[];
extern struct OamData gOamBuffer[128];

void sub_24C(void);
void sub_2B4(void);
void ClearGraphicsMemory(void);
void sub_518(void);
void ClearSprites(void);
u32 Random(void);
void VBlankIntr(void);
void VCountIntr(void);
void SerialIntr(void);
void Timer3Intr(void);
void sub_CBC(void);
void sub_D10(void);
void MainLoopIter(void);
void DefaultMainCallback(void);


#endif // GUARD_MAIN_H
