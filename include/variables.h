#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

#include "gba/gba.h"
#include "gba/m4a_internal.h"
#include "types.h"
#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/high_scores.h"
#include "constants/pinball_game.h"

#define SPECIES_DEX_UNSEEN 0
#define SPECIES_DEX_SEEN 1
#define SPECIES_DEX_SHARED 2
#define SPECIES_DEX_SHARED_AND_SEEN 3
#define SPECIES_DEX_CAUGHT 4

// sym_ewram

extern EWRAM_DATA struct PinballGame gPinballGameState;
extern EWRAM_DATA s8 gAutoDisplayTitlescreenMenu;


extern EWRAM_DATA u8 gLinkExchangeStep;


extern EWRAM_DATA u32 gLinkStatusResult;
extern EWRAM_DATA s16 gLinkSendBuffer[0xA];
extern EWRAM_DATA u16 gLinkRecvBuffer[0x8][2];
extern EWRAM_DATA u32 gLinkConnectionState;
extern EWRAM_DATA u8 gLinkPlayerCount;
extern EWRAM_DATA u8 gLinkNegotiationFlags;
extern EWRAM_DATA u16 gLinkExchangeFrameCounter;
extern EWRAM_DATA s16 gLinkTimeoutCounter;




extern EWRAM_DATA u16 gMain_saveData_pokedexFlags_90[10];


// Rom_2
extern u8 (*gMonHatchSpriteGroupGfx[])[0x10E0];
extern const Palette *gMonHatchSpriteGroupPals[];
extern const u16 gHighScoreCharToTileMap[];
extern struct Vector16 gIntroScene1Torchic_BGAnimTiming[0x8];
extern s16 gIntroScene1Torchic_TileOffsets[0x8];
extern const struct SpriteSet *const gIntroScene1Torchic_SpriteSets[];
extern struct Vector16 gIntroScene1Torchic_ScaleOffsets[0x4];
extern const struct SpriteSet *const gIntroScene3Treecko_SpriteSets[];
extern const struct SpriteSet *const gIntroScene5Mudkip_SpriteSets[];
extern s16 gIntroScene5Mudkip_TileOffsets[];

extern u8 gIntroScene6Chinchou_BounceFlags[];
extern const struct SpriteSet *const gIntroScene6Chinchou_SpriteSets[];

extern const struct SpriteSet *const gIntroScene7Parade_SpriteSets[];
extern s8 gIntroScene9BallFlight_BallXFrameAdjustTable[];

extern const struct SpriteSetTableEntry gFieldSpriteSets[];
extern u16 gCommonAndEggWeights[];

/*
    Note: gMain lives at gUnknown_0200B0C0 in running memory.
    anything from there to gUnknown_0200FAE0 is part of that object.
*/

#endif  // GUARD_VARIABLES_H
