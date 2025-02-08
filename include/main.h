#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"
#include "constants/ereader.h"
#include "constants/high_scores.h"
#include "constants/pinball_inputs.h"
#include "constants/species.h"

struct HighScoreEntry
{
    union {
        struct {
            u32 name[HIGH_SCORE_NAME_LENGTH];
            u32 scoreHi;
            u32 scoreLo;
        } parts;
        u32 raw[HIGH_SCORE_NAME_LENGTH + 2];
    } data;
};

// This is probably permanently saved data like pokedex and high scores.
struct SaveData
{
    /*0x74*/ u8 pokedexFlags[NUM_SPECIES];
    /*0x141*/ bool8 rumbleEnabled;
    /*0x142*/ u8 ballSpeed;
    /*0x143*/ u8 buttonConfigType;
    /*0x144*/ u16 customButtonConfig[NUM_PINBALL_INPUTS][2];
    /*0x158*/ struct HighScoreEntry highScores[2][NUM_HIGH_SCORES];
    /*0x2D8*/ s8 signature[10];
              u16 checksum;
              u32 unk2E4;
};

struct Main
{
    /*0x00*/ u8 filler0[0x2];
    /*0x02*/ u8 mainState;
    /*0x03*/ u8 subState;
    /*0x04*/ u8 selectedField;
    /*0x05*/ u8 unk5;
    /*0x06*/ u8 unk6;
    /*0x07*/ s8 eReaderBonus[NUM_EREADER_CARDS];
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
    /*0x44*/ struct MainUnk44 *unk44;
    /*0x48*/ int rngValue;
    /*0x4C*/ u32 systemFrameCount;
    /*0x50*/ int fieldFrameCount;
    /*0x54*/ u8 filler54[0xC];
    /*0x60*/ u16 unk60;
    /*0x62*/ u16 unk62;
    /*0x64*/ u16 unk64;
    /*0x66*/ u16 unk66;
    /*0x68*/ u16 unk68;
    /*0x6A*/ u16 unk6A;
    /*0x6C*/ u16 unk6C;
    /*0x6E*/ u16 unk6E;
    /*0x70*/ u16 unk70;
    /*0x72*/ u16 unk72;

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

void sub_024C(void);
void sub_02B4(void);
void ClearGraphicsMemory(void);
void sub_0518(void);
void ClearSprites(void);
u32 Random(void);
void VBlankIntr(void);
void VCountIntr(void);
void SerialIntr(void);
void Timer3Intr(void);
void sub_0CBC(void);
void sub_0D10(void);
void MainLoopIter(void);
void DefaultMainCallback(void);


#endif // GUARD_MAIN_H
