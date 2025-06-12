#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include "gba/gba.h"

#include "types.h"
#include "functions.h"
#include "variables.h"
#include "constants/global.h"
#include "constants/ereader.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")
#define NAKED __attribute__((naked))

// IDE support
#if defined (__APPLE__) || defined (__CYGWIN__) || defined (_MSC_VER)
#define _(x) x
#define __(x) x
#define INCBIN_U8 {0}
#define INCBIN_U16 {0}
#define INCBIN_U32 {0}
#define INCBIN_S8 {0}
#define INCBIN_S16 {0}
#define INCBIN_S32 {0}
#endif // IDE support

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) * 256))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((int)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((int)((n) / 4096))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((int)((n) >> 8))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

// Macros for checking the joypad
#define TEST_BUTTON(field, button) ((field) & (button))
#define TEST_BUTTON_EXACT(field, button) (((field) & (button)) == (button))
#define JOY_NEW(button) TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button)  TEST_BUTTON(gMain.heldKeys, button)

struct BgOffsets
{
    u16 xOffset;
    u16 yOffset;
};

// This struct holds data about the ball's velocity, position, etc.
struct BallState
{
    /*0x00*/ s8 unk0;
    /*0x01*/ s8 unk1; // oam data priority
    /*0x02*/ u8 filler2[0x2];
    /*0x04*/ u16 unk4;
    /*0x06*/ s16 unk6;
    /*0x08*/ u16 unk8;
    /*0x0A*/ u16 unkA;
    /*0x0C*/ u16 unkC;
    /*0x0E*/ u16 unkE;
    /*0x10*/ struct Vector16 unk10;
    /*0x14*/ u8 filler14[0xB];
    /*0x1F*/ u8 unk1F;
    /*0x20*/ u8 filler20[0x4];
    /*0x24*/ u16 unk24;
    /*0x26*/ u16 unk26;
    /*0x28*/ struct Vector16 unk28;
    /*0x2C*/ struct Vector16 unk2C;
    /*0x30*/ struct Vector16 velocity;
    /*0x34*/ struct Vector32 position; // fixed-point Q_24_8 values
    /*0x3C*/ struct Vector32 prevPosition;
};

struct UnkPinballGame13BC
{
    /*0x00*/ u8 filler0[0x4];
    /*0x04*/ s8 unk4;
    /*0x05*/ u8 filler5[0x7];
};

struct PinballGame
{
    /*0x000*/ u32 unk0;
    /*0x004*/ u8 newButtonActions[5]; // e.g. player pressing the appropriate buttons to trigger the left flipper action, etc.
    /*0x009*/ u8 releasedButtonActions[5];
    /*0x00E*/ u8 heldButtonActions[5];
    /*0x013*/ s8 unk13; // Current field state. In main fields seems to be related to the 3 Pokeballs that unlock bonus fields, in bonus fields acts as a field state
    /*0x014*/ s8 unk14;
    /*0x015*/ s8 unk15;
    /*0x016*/ s8 unk16;
    /*0x017*/ u8 unk17;
    /*0x018*/ u16 unk18;
    /*0x01A*/ u8 unk1A;
    /*0x01B*/ u8 unk1B;
    /*0x01C*/ u8 unk1C;
    /*0x01D*/ u8 unk1D;
    /*0x01E*/ u8 unk1E;
    /*0x01F*/ u8 unk1F;
    /*0x020*/ u8 filler20[0x2];
    /*0x022*/ s8 unk22;
    /*0x023*/ u8 unk23; // Holds the value of some enum state
    /*0x024*/ s8 unk24;
    /*0x025*/ s8 unk25;
    /*0x026*/ u16 unk26;
    /*0x028*/ u16 unk28;
    /*0x02A*/ u8 filler2A[0x6];
    /*0x030*/ u8 numLives;
    /*0x031*/ u8 ballSpeed;
    /*0x032*/ u8 filler32[0x3];
    /*0x035*/ s8 area;
    /*0x036*/ u8 filler36[0x2];
    /*0x038*/ u32 unk38; //score to add every frame until unk3C score has been added to player's total
    /*0x03C*/ u32 unk3C; //score to add when a bonus field or mode is complete
    /*0x040*/ u8 filler40[0x4];
    /*0x044*/ u32 unk44;
    /*0x048*/ u32 unk48;
    /*0x04C*/ s16 unk4C;
    /*0x04E*/ s16 unk4E;
    /*0x050*/ u8 filler50[0x4];
    /*0x054*/ u32 unk54;
    /*0x058*/ u16 unk58;
    /*0x05A*/ u16 unk5A;
    /*0x05C*/ u8 filler5C[0x8];
    /*0x064*/ s16 unk64;
    /*0x066*/ u16 unk66;
    /*0x068*/ s16 unk68;
    /*0x06A*/ s16 unk6A;
    /*0x06C*/ u16 timerBonus; //Additional time to be added to next timed event (Only for bonus fields or all timers?)
    /*0x06E*/ s8 unk6E;
    /*0x06F*/ s8 unk6F;
    /*0x070*/ s8 unk70;
    /*0x071*/ s8 unk71;
    /*0x072*/ u8 filler72[0x5A];
    /*0x0CC*/ u16 unkCC;
    /*0x0CE*/ u8 fillerCE[0x2];
    /*0x0D0*/ struct Vector16 unkD0[5];
    /*0x0E4*/ u8 unkE4;
    /*0x0E6*/ s16 unkE6;
    /*0x0E8*/ s16 unkE8;
    /*0x0EA*/ u16 unkEA;
    /*0x0EC*/ u16 unkEC;
    /*0x0EE*/ s16 unkEE;
    /*0x0EF*/ u8 fillerF0[0x2];
    /*0x0F2*/ s8 unkF2;
    /*0x0F3*/ u8 fillerF3[0x7];
    /*0x0FA*/ s8 unkFA;
    /*0x0FB*/ s8 unkFB;
    /*0x0FC*/ u8 fillerFC[0x25];
    /*0x121*/ s8 unk121;
    /*0x122*/ s8 unk122;
    /*0x123*/ s8 unk123;
    /*0x124*/ s8 unk124;
    /*0x125*/ s8 unk125;
    /*0x126*/ s8 unk126;
    /*0x127*/ s8 unk127;
    /*0x128*/ u8 filler128[0x3];
    /*0x12B*/ s8 forceSpecialMons;  // When on, force next catch mode species to be special mons
    /*0x12C*/ s8 forcePichuEgg;     // When on, force next egg mode species to be Pichu
    /*0x12D*/ u8 filler12D;
    /*0x12E*/ s16 totalWeight;       // Added weight of all possible mons in area
    /*0x130*/ s16 speciesWeights[25]; // Weight of each species
    /*0x162*/ u8 filler162[0x4];
    /*0x166*/ u16 unk166;
    /*0x168*/ u8 filler168[0x4];
    /*0x16C*/ u8 unk16C;
    /*0x16D*/ u8 filler16D[0x2];
    /*0x16F*/ u8 unk16F;
    /*0x170*/ u8 unk170;
    /*0x171*/ u8 unk171;
    /*0x172*/ u8 unk172;
    /*0x173*/ u8 unk173;
    /*0x174*/ u16 unk174;
    /*0x176*/ u8 unk176;
    /*0x177*/ u8 filler177[0x1B];
    /*0x192*/ u8 coins;
    /*0x193*/ u8 filler193[0x1];
    /*0x194*/ s8 unk194;
    /*0x195*/ u8 filler195[0x10];
    /*0x1A5*/ s8 unk1A5;
    /*0x1A6*/ s8 unk1A6;
    /*0x1A7*/ u8 filler1A7[0xD];
    /*0x1B4*/ u16 unk1B4;
    /*0x1B6*/ u8 filler1B6[0x4];
    /*0x1BA*/ u16 unk1BA;
    /*0x1BC*/ u8 filler1BC[0x4];
    /*0x1C0*/ u16 unk1C0;
    /*0x1C2*/ s8 unk1C2;
    /*0x1C3*/ u8 filler1C3[0x1];
    /*0x1C4*/ u16 unk1C4;
    /*0x1C6*/ u16 unk1C6;
    /*0x1C8*/ u16 unk1C8;
    /*0x1CA*/ u16 unk1CA;
    /*0x1CC*/ u16 unk1CC;
    /*0x1CE*/ u16 unk1CE;
    /*0x1D0*/ u16 unk1D0;
    /*0x1D2*/ u16 unk1D2;
    /*0x1D4*/ u16 unk1D4;
    /*0x1D6*/ u16 unk1D6;
    /*0x1D8*/ u16 unk1D8;
    /*0x1DA*/ u16 unk1DA;
    /*0x1DC*/ u16 unk1DC;
    /*0x1DE*/ u8 filler1DE[0x4];
    /*0x1E2*/ s8 unk1E2;
    /*0x1E3*/ u8 filler1E3[0x2];
    /*0x1E5*/ u8 unk1E5;
    /*0x1E6*/ u8 unk1E6;
    /*0x1E7*/ u8 filler1E7[0x6];
    /*0x1ED*/ s8 unk1ED;
    /*0x1EE*/ u8 filler1EE[0x1a];
    /*0x208*/ u16 unk208;
    /*0x20A*/ u8 unk20A;
    /*0x20B*/ u8 filler20B[0x54];
    /*0x25F*/ s8 unk25F;
    /*0x260*/ u8 filler260[0x10];
    /*0x270*/ s8 evolvablePartySpecies[MAX_EVOLVABLE_PARTY_SIZE];
    /*0x280*/ s8 evolvingPartyIndex;
    /*0x281*/ s8 evolvablePartySize;
    /*0x282*/ s8 unk282;
    /*0x283*/ u8 bonusFieldsComplete; //how many bonus fields have been completed
    /*0x284*/ u8 filler284[0xC];
    /*0x290*/ u32 unk290;
    /*0x294*/ s8 unk294;
    /*0x295*/ u8 unk295;
    /*0x296*/ u16 eventTimer; //Timer for events (Only bonus fields or all events?)
    /*0x298*/ u16 unk298;
    /*0x29A*/ u16 unk29A;
    /*0x29C*/ u16 unk29C;
    /*0x29E*/ u8 unk29E;
    /*0x29F*/ u8 unk29F;
    /*0x2A0*/ u16 unk2A0;
    /*0x2A2*/ u8 unk2A2;
    /*0x2A3*/ u8 filler2A3[0x1];
    /*0x2A4*/ s8 unk2A4;
    /*0x2A5*/ s8 unk2A5;
    /*0x2A6*/ u16 unk2A6;
    /*0x2A8*/ u8 filler2A8[0x2];
    /*0x2AA*/ u16 unk2AA;
    /*0x2AC*/ s16 unk2AC;
    /*0x2AE*/ u8 filler2AE[0x26];
    /*0x2D4*/ u16 unk2D4;
    /*0x2D6*/ u16 unk2D6;
    /*0x2D8*/ u8 filler2D8[0x2];
    /*0x2DA*/ s8 unk2DA;
    /*0x2DB*/ u8 filler2DB[0x10];
    /*0x2EC*/ u16 unk2EC;
    /*0x2EE*/ u16 unk2EE;
    /*0x2F0*/ u8 filler2F0[0x1];
    /*0x2F1*/ u8 unk2F1;
    /*0x2F2*/ u8 filler2F2[0x2];
    /*0x2F4*/ u8 unk2F4;
    /*0x2F5*/ s8 unk2F5;
    /*0x2F6*/ u8 filler2F6[0xA];
    /*0x300*/ u8 unk300;
    /*0x301*/ u8 unk301;
    /*0x302*/ u8 filler302[0x4];
    /*0x306*/ s8 unk306;
    /*0x307*/ u8 filler307[0x1];
    /*0x308*/ u16 unk308;
    /*0x30A*/ u16 unk30A;
    /*0x30C*/ u16 unk30C;
    /*0x30E*/ u8 filler30E[0x2];
    /*0x310*/ u16 unk310;
    /*0x312*/ u8 filler312[0x33];
    /*0x345*/ s8 unk345;
    /*0x346*/ s8 unk346;
    /*0x347*/ u8 filler347[0x23];
    /*0x36A*/ u8 unk36A[0x2];
    /*0x36C*/ u8 unk36C[0x2];
    /*0x36E*/ u16 unk36E[0x2];
    /*0x372*/ u8 filler372[0x11];
    /*0x383*/ s8 unk383;
    /*0x384*/ u8 unk384;
    /*0x385*/ s8 unk385;
    /*0x386*/ s8 unk386;
    /*0x387*/ s8 unk387;
    /*0x388*/ s8 unk388;
    /*0x389*/ u8 filler389[0x3];
    /*0x38C*/ s16 unk38C;
    /*0x38E*/ u8 filler38E[0x4];
    /*0x392*/ u16 unk392;
    /*0x394*/ u16 unk394;
    /*0x396*/ s8 unk396;
    /*0x397*/ s8 unk397[3];
    /*0x39A*/ u8 unk39A[3];
    /*0x39D*/ s8 unk39D[3];
    /*0x3A0*/ s8 unk3A0[3];
    /*0x3A3*/ s8 unk3A3[3];
    /*0x3A6*/ s8 unk3A6[3];
    /*0x3A9*/ u8 unk3A9[3];
    /*0x3AC*/ s8 unk3AC[3];
    /*0x3B0*/ u16 unk3B0[3];
    /*0x3B6*/ u16 unk3B6[3];
    /*0x3BC*/ u16 unk3BC[3];
    /*0x3C2*/ u8 filler3C2[0x2];
    /*0x3C4*/ struct Vector16 unk3C4[3];
    /*0x3D0*/ struct Vector16 unk3D0[3];
    /*0x3DC*/ s8 unk3DC;
    /*0x3DD*/ u8 unk3DD;
    /*0x3DE*/ u8 unk3DE;
    /*0x3DF*/ u8 unk3DF;
    /*0x3E0*/ u8 unk3E0;
    /*0x3E1*/ u8 unk3E1;
    /*0x3E2*/ u16 unk3E2;
    /*0x3E4*/ u16 unk3E4;
    /*0x3E6*/ u16 unk3E6;
    /*0x3E8*/ u16 unk3E8;
    /*0x3EA*/ u16 unk3EA;
    /*0x3EC*/ u16 unk3EC;
    /*0x3EE*/ u16 unk3EE;
    /*0x3F0*/ u16 unk3F0;
    /*0x3F2*/ u16 unk3F2;
    /*0x3F4*/ u16 unk3F4;
    /*0x3F6*/ u8 filler3F6[0x2];
    /*0x3F8*/ s16 unk3F8;
    /*0x3FA*/ u8 filler3FA[0x2];
    /*0x3FC*/ s16 unk3FC;
    /*0x3FE*/ u8 filler3FE[0x2];
    /*0x400*/ s16 unk400;
    /*0x402*/ u8 filler402[0x2];
    /*0x404*/ s16 unk404;
    /*0x406*/ u8 filler406[0x2];
    /*0x408*/ s16 unk408;
    /*0x40A*/ u8 filler40A[0x2];
    /*0x40C*/ s16 unk40C;
    /*0x40E*/ u8 filler40E[0x2];
    /*0x410*/ s16 unk410;
    /*0x412*/ u8 filler412[0x2];
    /*0x414*/ s8 unk414;
    /*0x415*/ u8 filler415[0x3D];
    /*0x452*/ u16 unk452;
    /*0x454*/ u8 filler454[0xF4];
    /*0x548*/ u8 unk548;
    /*0x549*/ u8 unk549;
    /*0x54A*/ u8 filler54A[3];
    /*0x54D*/ u8 unk54D[2]; //Sized by use in sub_18DAC //TODO verify
    /*0x54F*/ s8 unk54F[2]; //Sized by use in sub_18DAC //TODO verify
    /*0x551*/ u8 filler551[2];
    /*0x553*/ u8 unk553[2]; //Sized by use in sub_18DAC //TODO verify
    /*0x555*/ u8 filler555[0x1B];
    /*0x570*/ struct Vector16 unk570[2]; //Sized by use in sub_18DAC //TODO verify
    /*0x578*/ u8 filler578[0x20];
    /*0x598*/ u16 currentSpecies; // Current catch/hatch mode species? Is it evo mode as well?
    /*0x59A*/ u8 filler59A[0x2];
    /*0x59C*/ u16 lastCatchSpecies; // Previous catch mode species?
    /*0x59E*/ u16 lastEggSpecies; // Previous hatch/evo mode species?
    /*0x5A0*/ u8 filler5A0[0x4];
    /*0x5A4*/ u8 unk5A4;
    /*0x5A5*/ u8 unk5A5;
    /*0x5A6*/ u8 filler5A6[0x3];
    /*0x5A9*/ u8 unk5A9;
    /*0x5AA*/ u16 unk5AA;
    /*0x5AC*/ u8 filler5AC[0x6];
    /*0x5B2*/ u8 unk5B2;
    /*0x5B3*/ u8 filler5B3[0x3D];
    /*0x5F0*/ u16 caughtMonCount; // Number of mons caught in this game
    /*0x5F2*/ u8 filler5F2[0x1];
    /*0x5F3*/ s8 unk5F3;
    /*0x5F4*/ u8 filler5F4[0x2];
    /*0x5F6*/ s8 unk5F6;
    /*0x5F7*/ u8 unk5F7;
    /*0x5F8*/ u16 unk5F8;
    /*0x5FA*/ u8 unk5FA;
    /*0x5FB*/ u8 unk5FB;
    /*0x5FC*/ s16 unk5FC;
    /*0x5FE*/ u16 unk5FE;
    /*0x600*/ u16 unk600;
    /*0x602*/ u8 filler602[0x12];
    /*0x614*/ u16 unk614;
    /*0x616*/ u8 filler616[0x6];
    /*0x61C*/ s8 unk61C;
    /*0x61D*/ u8 filler61D[0x8];
    /*0x625*/ u8 unk625;
    /*0x626*/ u8 filler626[0x9];
    /*0x62F*/ u8 unk62F;
    /*0x630*/ u8 filler630[0x7];
    /*0x637*/ u8 unk637;
    /*0x638*/ u8 filler638[0x8C];
    /*0x6C4*/ u8 unk6C4;
    /*0x6C5*/ u8 unk6C5; // TODO: unknown type
    /*0x6C6*/ u8 unk6C6;
    /*0x6C7*/ u8 unk6C7;
    /*0x6C8*/ s8 unk6C8;
    /*0x6C9*/ s8 unk6C9;
    /*0x6CA*/ u16 unk6CA;
    /*0x6CC*/ u8 unk6CC;
    /*0x6CD*/ u8 unk6CD[6];
    /*0x6D3*/ u8 filler6D3[0x1B];
    /*0x6EE*/ u16 unk6EE;
    /*0x6F0*/ u8 filler6F0[0x1E];
    /*0x70E*/ s8 unk70E;
    /*0x70F*/ s8 unk70F;
    /*0x710*/ s8 unk710;
    /*0x711*/ s8 unk711;
    /*0x712*/ s8 unk712;
    /*0x713*/ s8 unk713;
    /*0x714*/ s8 unk714;
    /*0x715*/ u8 filler715[0x1];
    /*0x716*/ s8 unk716;
    /*0x717*/ u8 filler717[0x1];
    /*0x718*/ s8 unk718;
    /*0x719*/ s8 unk719;
    /*0x71A*/ s8 unk71A;
    /*0x71B*/ u8 unk71B;
    /*0x71C*/ u8 unk71C;
    /*0x71D*/ u8 filler71D[0x7];
    /*0x724*/ u16 unk724;
    /*0x726*/ u8 filler726[0x2];
    /*0x728*/ u8 unk728; // TODO: unknown type
    /*0x729*/ u8 filler729[0x5];
    /*0x72E*/ s8 unk72E;
    /*0x72F*/ s8 unk72F;
    /*0x730*/ u8 unk730;
    /*0x731*/ u8 unk731;
    /*0x732*/ u8 filler732[0xA];
    /*0x73C*/ u8 unk73C; // TODO: unknown type
    /*0x73D*/ s8 catchModeArrows;   // Affects which encounter table is used per area
    /*0x73E*/ u8 filler73E[0x8];
    /*0x746*/ u8 unk746;
    /*0x747*/ u8 filler747[0x2];
    /*0x749*/ u8 unk749;
    /*0x74A*/ u8 filler74A[0x2];
    /*0x74C*/ volatile u8 unk74C[2][OBJ_PLTT_SIZE];
    /*0xB4C*/ volatile u8 unkB4C[2][BG_PLTT_SIZE];
    /*0xF4C*/ struct SongHeader *unkF4C;
    /*0xF50*/ u8 fillerF50[0x8];
    /*0xF58*/ struct BgOffsets bgOffsets0;
    /*0xF5C*/ struct BgOffsets bgOffsets1;
    /*0xF60*/ struct BgOffsets bgOffsets2;
    /*0xF64*/ struct BgOffsets bgOffsets3;
    /*0xF68*/ u16 unkF68[2][100];
    /*0x10F8*/u8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x10FD*/u8 field;
    /*0x10FE*/u8 unk10FE;
    /*0x10FF*/u8 unk10FF;
    /*0x1100*/u8 unk1100;
    /*0x1101*/u8 unk1101;
    /*0x1102*/u8 unk1102;
    /*0x1103*/u8 unk1103;
    /*0x1104*/u8 filler1104[0x2];
    /*0x1106*/u16 unk1106;
    /*0x1108*/u16 unk1108;
    /*0x110A*/u16 unk110A;
    /*0x110C*/u16 unk110C;
    /*0x110E*/u16 unk110E;
    /*0x1110*/volatile u16 unk1110;
    /*0x1112*/volatile u16 unk1112;
    /*0x1114*/volatile u16 unk1114;
    /*0x1116*/u16 unk1116;
    /*0x1118*/u16 unk1118;
    /*0x111A*/u8 unk111A[OBJ_PLTT_SIZE];
    /*0x131A*/u8 filler131A[0x6];
    /*0x1320*/s16 unk1320;
    /*0x1322*/s16 unk1322;
    /*0x1324*/s16 unk1324;
    /*0x1326*/s16 unk1326;
    /*0x1328*/u16 unk1328;
    /*0x132A*/u8 filler132A[0x2];
    /*0x132C*/struct BallState *unk132c;
    /*0x1330*/struct BallState *unk1330;
    /*0x1334*/struct BallState unk1334[2];
    /*0x13BC*/struct UnkPinballGame13BC unk13BC[2];
    /*0x13D4*/u8 filler13D4[0x3C];
} /* size=0x1410 */;

struct Unk02031520_unk10
{
    /*0x0*/ u8 unk0;
    /*0x1*/ u8 unk1;
    /*0x2*/ u8 unk2;
};

struct Unk02031520
{
    /*0x00*/ u8 filler0[0x8];
    /*0x08*/ s16 unk8;
    /*0x0A*/ u8 fillerA[0x2];
    /*0x0C*/ struct PinballGame *unkC;
    /*0x10*/ struct Unk02031520_unk10 *unk10;
    /*0x14*/ u8 filler14[0xc];
    /*0x20*/ s16 unk20;
    /*0x22*/ s16 unk22;
    /*0x24*/ s16 unk24;
    /*0x26*/ s16 unk26;
    /*0x28*/ s16 unk28;
    /*0x2C*/ u32 *unk2C[3];
    /*0x38*/ s16 *unk38[4];
    /*0x48*/ u16 *unk48[4];
    /*0x58*/ u8 *unk58[4];
};

struct Unk02031590
{
    u8 filler[0x16];
    u8 unk16;
};

extern struct PinballGame *gCurrentPinballGame;
extern u32 gUnknown_02031510;
extern struct Unk02031520 gUnknown_02031520;
extern struct Unk02031590 gUnknown_02031590;
extern u16 gUnknown_08137B3C[][6][16];
extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gUnknown_08138834[0x2000];
extern s32 gUnknown_081B36A4[64];
extern s32 gUnknown_082EE0E0[0x3E0];
extern const u16 gUnknown_08391A4C[0x1000];
extern const u16 gUnknown_08393A4C[0x1000];

#endif // GUARD_GLOBAL_H
