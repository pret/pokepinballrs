#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include "gba/gba.h"

#define NUM_SPRITE_GROUPS 100
#define MAX_SPRITES_IN_GROUP 22

#include "types.h"
#include "functions.h"
#include "variables.h"
#include "constants/global.h"

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
#define JOY_NEW_EXACT(button) TEST_BUTTON_EXACT(gMain.newKeys,  button)
#define JOY_HELD_EXACT(button)  TEST_BUTTON_EXACT(gMain.heldKeys, button)

struct unk_struct{
	/*0x00*/ u8 unk0;
	/*0x01*/ u8 unk1;
	/*0x02*/ u8 filler2[0x4];
	/*0x06*/ u16 unk6;
	/*0x08*/ u8 filler7[0x6];
	/*0x0E*/ u16 unk0E;
	/*0x10*/ struct sCoord16 unk10;
	/*0x14*/ u8 filler14[0x14];
	/*0x28*/ struct sCoord16 unk28;
	/*0x2C*/ u8 filler2A[0x04];
	/*0x30*/ struct sCoord16 unk30;
	/*0x34*/ struct sCoord32 unk34;
	/*0x3B*/ u8 filler3B[0x08];
};

struct PinballGame
{
	/*0x000*/ u8 filler0[0x13];
	/*0x013*/ s8 unk13;
	/*0x014*/ s8 unk14;
	/*0x015*/ u8 filler15[0x10];
	/*0x025*/ s8 unk25;
	/*0x026*/ u16 unk26;
	/*0x028*/ u16 unk28;
	/*0x02A*/ u8 filler2A[0xB];
	/*0x035*/ s8 area;
	/*0x036*/ u8 filler36[0x6];
	/*0x03C*/ u32 unk3C;
	/*0x040*/ u8 filler40[0x28];
	/*0x068*/ s16 unk68;
	/*0x06A*/ u8 filler6A[0xC1];
	/*0x12B*/ s8 forceSpecialMons;  // When on, force next catch mode species to be special mons
	/*0x12C*/ s8 forcePichuEgg;     // When on, force next egg mode species to be Pichu
	/*0x12D*/ u8 filler12D;
	/*0x12E*/ s16 unk12E;
	/*0x130*/ s16 unk130[8];
	/*0x140*/ u8 filler140[0x54];
	/*0x194*/ s8 unk194;
	/*0x195*/ u8 filler195[0x25];
	/*0x1BA*/ u16 unk1BA;
	/*0x1BC*/ u8 filler1BC[0x1C];
	/*0x1D8*/ u16 unk1D8;
	/*0x1DA*/ u16 unk1DA;
	/*0x1DC*/ u8 filler1DC[0x9];
	/*0x1E5*/ u8 unk1E5;
	/*0x1E6*/ u8 unk1E6;
	/*0x1E7*/ u8 filler1E7[0xB5];
	/*0x29C*/ u16 unk29C;
	/*0x29E*/ u8 filler29E[0xA6];
	/*0x344*/ u32 unk344;
	/*0x348*/ u8 filler348[0x250];
	/*0x598*/ u16 unk598; // Current catch/hatch mode species? Is it evo mode as well?
	/*0x59A*/ u8 filler59A[0x2];
	/*0x59C*/ u16 unk59C; // Previous catch mode species?
	/*0x59E*/ u16 unk59E; // Previous hatch/evo mode species?
	/*0x5A0*/ u8 filler5A0[0x12];
	/*0x5B2*/ u8 unk5B2;
	/*0x5B3*/ u8 filler5B3[0x3D];
	/*0x5F0*/ u16 caughtMonCount; // Number of mons caught in this game
	/*0x5F2*/ u8 filler5F2[0x5];
	/*0x5F7*/ u8 unk5F7;
	/*0x5F8*/ u8 filler5F8[0x8];
	/*0x600*/ u16 unk600;
	/*0x602*/ u8 filler602[0x126];
	/*0x728*/ u8 unk728; // TODO: unknown type
	/*0x729*/ u8 filler729[0x5];
	/*0x72E*/ u8 unk72E; // TODO: unknown type
	/*0x72F*/ u8 unk72F; // TODO: unknown type
	/*0x730*/ u8 filler730[0xC];
	/*0x73C*/ u8 unk73C; // TODO: unknown type
	/*0x73D*/ s8 catchModeArrows;   // Affects which encounter table is used per area
	/*0x73E*/ u8 filler73E[0xBEE];
	/*0x132C*/struct unk_struct *unk132c;
	/*0x1330*/u8 filler1330[4];
	/*0x1334*/struct unk_struct unk1334[2];
};

struct Unk02031520
{
	/*0x00*/ u8 filler0[0x8];
	/*0x08*/ s16 unk8;
	/*0x0A*/ u8  unk10[0x1C]; 
	/*0x26*/ s16 unk26;
	/*0x28*/ s16 unk28;
};

extern struct PinballGame *gCurrentPinballGame;
extern struct Unk02031520 gUnknown_02031520;

#endif // GUARD_GLOBAL_H
