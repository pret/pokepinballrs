#ifndef GUARD_TYPES_H
#define GUARD_TYPES_H

#include "gba/gba.h"
#define NUM_SPRITE_GROUPS 100
#define MAX_SPRITES_IN_GROUP 22

// Place all discovered types (structs, unions, etc.) in this file.

typedef void (*StateFunc)(void);
typedef void (*IntrFunc)(void);

struct SpriteSet
{
    u16 count;
    u8 oamData[0];
};

struct OamDataSimple
{
    /*0x00*/ u16 oamId;
    /*0x02*/ s16 xOffset;
    /*0x04*/ s16 yOffset;
};
// size: 0x8

struct SpriteGroup
{
    /*0x00*/ u16 available;
    /*0x02*/ s16 baseX;
    /*0x04*/ s16 baseY;
    /*0x08*/ struct OamDataSimple oam[MAX_SPRITES_IN_GROUP];
    /*Note: oam is 22 groups of size 0x8. Extends to B7.

           0   1   2   3   4   5   6   7   8   9
    00     8, 10, 18, 20, 28, 30, 38, 40, 48, 50,
    10    58, 60, 68, 70, 78, 80, 88, 90, 98, A0,
    20    A8, B0
    */
};
// size: 0xB8

struct SpriteSetTableEntry
{
    /*0x00*/ const struct SpriteSet *const *spriteSets;
    /*0x04*/ u16 numSpriteSets;
    /*0x06*/ u16 padding;
}; // size: 0x8

struct Vector16
{
    s16 x;
    s16 y;
};

struct VectorU16
{
    u16 x;
    u16 y;
};

struct Vector32
{
    s32 x;
    s32 y;
};

struct VectorU32
{
    u32 x;
    u32 y;
};

struct PokemonSpecies {
    /*0x00*/ u16 mainSeriesIndexNumber; // Refers to the generation three internal index number; e.g. Treecko is 0x115 (decimal 227).
    /*0x02*/ u8 nameJapanese[5];
    /*0x07*/ u8 name[10]; // Space-padded ASCII
    /*0x11*/ u8 catchIndex; // Non-zero for all catch pokemon other than Treecko, zero for Treecko and all non-catch pokemon
    /*0x12*/ u8 eggIndex; // Non-zero for all hatch pokemon other than Wurmple, zero for Wurmple and all non-hatch pokemon
    /*0x13*/ u8 unk13; // Something egg related; only hatch pokemon have this set to 1, but not all do, and there is no other pattern
    // unk13 list: Azurill, Skitty, Zubat, Plusle, Minun, Igglybuff, Shuppet, Chimecho, Pichu, Natu
    /*0x14*/ s8 evolutionMethod; // Exp, Stone, etc.
    /*0x15*/ u8 evolutionTarget; // Uses the standard index numbers; e.g. Treecko is 0x00 (SPECIES_TREECKO)
};

#endif  // GUARD_TYPES_H
