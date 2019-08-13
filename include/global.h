#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include "gba/gba.h"

#define NUM_SPRITE_GROUPS 100
#define MAX_SPRITES_IN_GROUP 22

#include "types.h"
#include "functions.h"
#include "variables.h"

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

enum
{
    STATE_INTRO,
    STATE_TITLE,
    STATE_GAME_MAIN,
    STATE_GAME_IDLE,
    STATE_OPTIONS,
    STATE_POKEDEX,
    STATE_UNKNOWN6,
    STATE_EREADER,
    STATE_SCORES_MAIN,
    STATE_SCORES_IDLE,
    STATE_FIELD_SELECT,
    STATE_BONUS_FIELD_SELECT,
};

struct PinballGame
{
	/*0x000*/ u8 filler0[0x35];
	/*0x035*/ s8 area;
	/*0x036*/ u8 filler36[0xF5];
	/*0x12B*/ s8 unk12B;
	/*0x12C*/ u8 filler12C[0x2];
	/*0x12E*/ s16 unk12E;
	/*0x130*/ s16 unk130[8];
	/*0x140*/ u8 filler140[0x458];
	/*0x598*/ u16 catchModeSpecies;
	/*0x59A*/ u8 filler59A[0x2];
	/*0x59C*/ u16 unk59C;
	/*0x59E*/ u8 filler59E[0x52];
	/*0x5F0*/ u16 unk5F0;
	/*0x5F2*/ u8 filler5F2[0x14B];
	/*0x73D*/ s8 unk73D;
};

struct Unk02031520
{
	/*0x0*/ u8 filler0[0x8];
	/*0x8*/ s16 unk8;
};

extern struct PinballGame *gUnknown_020314E0;
extern struct Unk02031520 gUnknown_02031520;

#endif // GUARD_GLOBAL_H
