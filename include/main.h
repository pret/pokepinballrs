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
}; // size: 0x18

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
    /*0x05*/ u8 unk5; // tempField (?)
    /*0x06*/ u8 unk6; // isBonusField (?)
    /*0x07*/ s8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x0C*/ u8 unkC;
    /*0x0D*/ u8 unkD;
    /*0x0E*/ u8 unkE;

    // UnkF hold a Bitmask for the following:
    // x1 mode start banner Evo/Catch/Travel, 
    // x2 paused,
    // x4 debug mode,
    // x8 Reset Ball (ball saver)
    // x10 End of ball (lose life reset Ball),
    // x20 end of game,
    // x40 End of bonus with expired timer,
    // x80 Bonus Score banner
    // Most cause a board state transition once conditions are met.
    /*0x0F*/ u8 unkF;   
    /*0x10*/ u8 unk10;
    /*0x11*/ u8 unk11;
    /*0x12*/ u16 unk12;
    /*0x14*/ u16 unk14;
    /*0x16*/ u16 dispcntBackup;
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
    /*0x2E*/ s16 unk2E;
    /*0x30*/ u16 unk30;
    /*0x32*/ u8 filler32[0x4];
    /*0x36*/ u8 unk36;
    /*0x38*/ volatile u16 blendControl;
    /*0x3A*/ volatile u16 blendAlpha;
    /*0x3C*/ volatile u16 blendBrightness;
             // may be a sub-struct. possibly for saved game?
    /*0x40*/ int hasSavedGame;
    /*0x44*/ struct SpriteGroup **unk44;
    /*0x48*/ int rngValue;
    /*0x4C*/ u32 systemFrameCount;
    /*0x50*/ u32 fieldFrameCount;
    /*0x54*/ u32 unk54;
    /*0x58*/ u32 finalScoreLo;
    /*0x5C*/ u32 finalScoreHi;

    /***
     * First index = 'Action'
     * 0:left flipper, 1:right flipper, 2:tilt left, 3:tilt right, 4=tilt up
     * 
     * Second index
     * An action can be triggered by pressing 2 buttons simultaneously
     *   Each data element holds a mask for the button it looks for.
     ***/
    /*0x60*/ u16 buttonConfigs[5][2]; 

    // This field must be accessed using the following macro to produce matching code.
#define gMain_saveData (*(struct SaveData *)(&gMain.saveData))
    /*0x74*/  struct SaveData saveData;

    /*0x2E8*/ struct BgOffsets bgOffsets[4];

    /*0x2F8*/ struct SpriteGroup spriteGroups[NUM_SPRITE_GROUPS];
    /*Note: spriteGroups is 100 groups of size B8. Extends to 4AD7.

           0     1     2     3     4     5     6     7     8     9
    00   2F8,  3B0,  468,  520,  5D8,  690,  748,  800,  8B8,  970,
    10   A28,  AE0,  B98,  C50,  D08,  DC0,  E78,  F30,  FE8, 10A0,
    20  1158, 1210, 12C8, 1380, 1438, 14F0, 15A8, 1660, 1718, 17D0,
    30  1888, 1940, 19F8, 1AB0, 1B68, 1C20, 1CD8, 1D90, 1E48, 1F00,
    40  1FB8, 2070, 2128, 21E0, 2298, 2350, 2408, 24C0, 2578, 2630,
    50  26E8, 27A0, 2858, 2910, 29C8, 2A80, 2B38, 2BF0, 2CA8, 2D60,
    60  2E18, 2ED0, 2F88, 3040, 30F8, 31B0, 3268, 3320, 33D8, 3490,
    70  3548, 3600, 36B8, 3770, 3828, 38E0, 3998, 3A50, 3B08, 3BC0,
    80  3C78, 3D30, 3DE8, 3EA0, 3F58, 4010, 40C8, 4180, 4238, 42F0,
    90  43A8, 4460, 4518, 45D0, 4688, 4740, 47F8, 48B0, 4968, 4A20*/
    
};

extern struct Main gMain;
extern struct SpriteGroup gMain_spriteGroups[];
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
extern u8 gGbPlayerTilemapBuffer[];
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
