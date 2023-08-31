#ifndef GUARD_TYPES_H
#define GUARD_TYPES_H

// Place all discovered types (structs, unions, etc.) in this file.

typedef void (*StateFunc)(void);
typedef void (*IntrFunc)(void);

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

struct Coord16
{
    u16 x;
    u16 y;
};

struct PokemonSpecies {
    u16 mainSeriesIndexNumber; // Refers to the generation three internal index number; e.g. Treecko is 0x115 (decimal 227).
    u8 unk2[0x5];
    u8 name[10];
    u8 unk11[0x4];
    u8 evolutionTarget; // Uses the standard index numbers; e.g. Treecko is 0x00 (SPECIES_TREECKO)
    u8 unk16[0x2];
};

#endif  // GUARD_TYPES_H
