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

extern struct PinballGame gPinballGameState;
extern u16 gTempGfxBuffer[];
extern u16 gBG0TilemapBuffer[];


extern s8 gAutoDisplayTitlescreenMenu;
extern s16 gEReaderReceivedCardId;
extern u16 gPokedexVramBuffer[];
extern s16 gPokedexNumOwned;
extern s16 gPokedexSelectedMon;
extern s8 gLinkExchangeResult;
extern s16 gPokedexNumSeen;
extern s16 gPokedexListPosition;
extern s16 gPokedexAnimatedIconFrame;
extern s16 gPokedexAnimatedIconTimer;
extern s16 gPokedexCursorOffset;
extern s16 gPokedexCursorBlinkOffset;
extern s16 gPokedexBlinkTimer;
extern s16 gPokedexScrollWaitFrames;
extern s8 gPokedexScrollActive;
extern s16 gPokedexSpriteAnimFrame;
extern s16 gPokedexSpriteAnimTimer;
extern s16 gPokedexPageIndicatorTimer;
extern s16 gPokedexShowAnimSprite;
extern s16 gPokedexShowPortrait;
extern s16 gPokedexShowCatchHatch[2];
extern s16 gPokedexDetailFrameCount;
extern s16 gPokedexInfoWindowSlideStep;
extern s8 gPokedexButtonPromptFrame;
extern s8 gPokedexShowButtonPrompt;
extern s16 gPokedexSpriteCategory;
extern s8 gPokedexShowCompletionBadge;
extern s16 gPokedexLinkStateTimer;
extern s8 gPokedexShowPopupWindow;

/****
 *  Yellow confirmation/info window mode
 *  0= Transmession connection prompt, 
 *  1= Transferring in progress?
 *  2= transmission error message
 *  3= transfer complete?
 *  4= delete save data confirmation
 * ****/
extern s8 gPokedexPopupTypeIndex;
extern s8 gPokedex_EraseSaveDataAccessCounter;
extern s8 gPokedex_EraseSaveDataAccessStep;
extern s8 gPokedexDescriptionPage;
extern s8 gPokedexShowPageIndicator;
extern s8 gPokedexPageIndicatorBlink;
extern s8 gPokedexSpriteIndexBase;
extern s16 gPokedexFlags[];
extern s16 gPokedexFlagExchangeBuffer[];
extern s16 gPokedexListEntryCount;

extern u32 gMergedSapphireScoreIndex;
extern u32 gMergedRubyScoreIndex;
extern u16 gPokedexInfoWindowBackupTiles[];

extern u8 gLinkExchangeStep;


extern u32 gLinkStatusResult;
extern s16 gLinkSendBuffer[];
extern u16 gLinkRecvBuffer[][2];
extern u32 gLinkConnectionState;
extern u8 gLinkPlayerCount;
extern u8 gLinkNegotiationFlags;
extern u16 gLinkExchangeFrameCounter;
extern s16 gLinkTimeoutCounter;
extern s8 gPokedexLinkTransferPhase;
extern s8 gEReaderLinkHandshakeStarted;
extern s8 gEReaderLinkDataReceived;
extern s8 gEReaderLinkAckSent;
extern s8 gLinkExchangeSendPhase;
extern s16 gScoreDigitBuffer[];

struct UnkStruct_0202ADA0{
    s16 posX;
    s16 posY;
    s16 velX;
    s16 velY;
    s16 animFrame;
    s16 frameTimer;
};
extern struct UnkStruct_0202ADA0 gIntroBGParams[4];
extern s32 gIntroPalFadeLevel;
extern s32 gIntroScaleY;
extern s8 gIntroScene6ChinchouVelocityIndex;
extern s8 gIntroScene6ChinchouEntitySpawnIndex;
extern s16 gIntroWailmerScaleX;
extern s16 gIntroWailmerScaleY;
extern s8 gIntroObjWhiteFlash;
extern s8 gIntroBGWhiteFlash;
extern u16 gMain_saveData_pokedexFlags_90[10];

// sym_bss
extern u16 gTextTilemapBuffer[];


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
