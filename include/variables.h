#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

#include "gba/gba.h"
#include "gba/m4a_internal.h"
#include "types.h"
#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/high_scores.h"
#include "constants/pinball_game.h"

#define SPECIES_UNSEEN 0
#define SPECIES_SEEN 1
#define SPECIES_SHARED 2
#define SPECIES_SHARED_AND_SEEN 3
#define SPECIES_CAUGHT 4

// Place all external variable declarations in this file

extern struct {u16 rubyTransitionFrames[5]; u16 sapphireTransitionFrames[5];} gFieldTransitionAnimData;
extern s8 gFieldSelectSoftReset;
extern struct ToneData gPokemonCryToneBank0[];
extern struct ToneData gPokemonCryToneBank1[];
extern struct ToneData gPokemonCryToneBank2[];
extern struct ToneData gPokemonCryToneBank3[];
extern u16 gOptionsBGMList[];

/*** 
* button information: input mask, tile, ?, width
* 
* First index associations:
*   0 : A button 
*   1 : B button
*   2 : Select button
*   3 : Start button
*   4 : Right arrow
*   5 : Left arrow
*   6 : Up arrow
*   7 : Down arrow
*   8 : R button
*   9 : L button
*   10 : Combiner sprite
* 
* Second index:
*   0 : button input mask
*   1 : tile number
*   2 : unknown
*   3 : px wide
***/
extern u16 gButtonInfoTable[11][4];
extern struct {u8 tileId; s16 frameDuration;} gButtonAnimData[];
extern u16 gOptionsSEList[];
extern u8 gCustomButtonConfigs[][10];
extern u8 gDefaultButtonConfigs[4][10];
extern void (*const gOptionsStateFuncs[])(void);
extern u32 gHighScoreNameEntry[HIGH_SCORE_NAME_LENGTH];
extern u16 gPaletteFadeBuffers[3][BG_PLTT_SIZE];
extern u16 gTempGfxBuffer[];
extern u8 gEReaderTextTileBuffer[3][0x800];
//extern ? gOamBuffer;
//extern ? IntrMain_Buffer;
extern u16 gBG0TilemapBuffer[];
//extern ? SoundMainRAM_Buffer;
extern u16 sGbPlayerCurKeys;
extern u16 sGbPlayerPrevKeys;
struct RfuSIO32Id {
    u8 MS_mode; //either 0 or 1
    u16 count;
    u16 send_id;
    u16 recv_id;
    u8 filler[0xA-0x8];
    u16 lastId;
    // size 0xC
};
extern struct RfuSIO32Id gSio32Id;
extern u32 gSio32ReceivedData;
extern u32 gSio32RemoteDeviceId;
//extern ? gTitlescreen;
//extern ? gEraseSaveDataAccessStep;
//extern ? gEraseSaveDataAccessCounter;
//extern ? gEReaderAccessStep;
//extern ? gEReaderAccessCounter;
//extern ? gTitleTransitionActive;
//extern ? gTitleRestartDebounce;
//extern ? gDpcmSampleBuffer;
//extern ? gIntrTable;
//extern ? gMain;
//extern ? gVBlankIntrFuncPtr;
//extern ? gMainCallback;
//extern ? gUnknown_0200FBA0;
//extern ? gUnknown_02017BD0;
//extern ? gUnknown_02017BD4;
//extern ? gUnknown_02017BE0;
//extern ? gVCountIntrFuncPtr;
//extern ? gRumbleLoopCounter;
//extern ? gRumbleFrameCounter;
//extern ? gRumbleMotorMode;
//extern ? gSio32ReconnectTimer;
//extern ? gSio32SerialEnabled;
//extern ? gRumblePatternIndex;
//extern ? gRumblePatternPosition;
//extern ? gRumbleCommand;
//extern ? gRumblePaused;
//extern ? gRumbleSpeedMode;
//extern ? gGameBoyPlayerEnabled;
//extern ? gSio32CommState;
extern s8 gAutoDisplayTitlescreenMenu;
//extern ? gTitleNoSaveMenuSpriteSets;
//extern ? gTitleSavedMenuSpriteSets;
//extern ? gTitleReturnedFromMenu;
extern s16 gEReaderReceivedCardId;
//extern ? gHighScoreEntrySource;
//extern ? gCurrentPinballGame;
//extern ? gBoardConfig;
//extern ? gSoundInfo;
//extern ? gPokemonCryMusicPlayers;
//extern ? gMPlayJumpTable;
//extern ? gCgbChans;
//extern ? gPokemonCryTracks;
//extern ? gPokemonCrySong;
//extern ? gMPlayInfo_BGM;
//extern ? gMPlayMemAccArea;
extern const u16 gWildMonLocations[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const s16 gSineTable[];
extern const struct OamData gEmptyOamData[128];
extern const u8 gGbPlayerPalettes[];
extern const u8 gGbPlayerGfx[];
extern const u8 gGbPlayerTilemap[];
extern StateFunc gTitlescreenStateFuncs[];
//extern ? gIntroCopyright_Gfx;
//extern ? gIntroCopyright_Pal;
//extern ? gIntroScene1Sprites_Pals;
//extern ? gIntroScene1Sprites_Gfx;
extern const u8 gGBAButtonIcons_Pals[];
extern const u8 gOptionsSprites_Gfx[];
extern const IntrFunc gIntrTableTemplate[14];
//extern ? gRumblePattern0;
//extern ? gRumblePattern1;
//extern ? gRumblePattern2;
//extern ? gRumblePattern3;
//extern ? gRumblePattern4;
//extern ? gRumblePattern5;
//extern ? gRumblePattern6;
//extern ? gRumblePattern7;
//extern ? gRumblePattern8;
//extern ? gRumblePattern9;
//extern ? gRumblePattern10;
//extern ? gRumblePattern11;
//extern ? gRumblePattern12;
//extern ? gRumblePattern13;
//extern ? gRumblePattern14;
extern const int *gRumblePatterns[];
extern const u16 gEReaderTextGlyphTable[][3*0x18];
extern const s8 gScorePaletteAnimOffsets[3]; //Sized based on call using gHighScoreScreenState.paletteAnimPhase + data
extern const s8 gScorePaletteResetOffsets[3]; //Same as above
extern const s16 gTitleMenuStateTable[11];
extern const s8 gTitlePressStartAnimDurations[4];
extern const s8 gTitleMenuSlideInAnimData[6][2];
extern const s8 gTitleMenuSlideOutAnimData[9][2];
extern const u16 gTitleNoSaveMenuActions[4];
extern const u16 gTitleSavedMenuActions[];
extern const struct SpriteSet *const gTitlePressStartSpriteSets[];
extern const u8 *const gTitleNoSaveDefaultSprites[7];
extern const u8 *const gTitleNoSaveAnimSprites[];
extern const s8 gTitleMenuRetractDurations[];
extern const u8 *const gTitleSavedDefaultSprites[7];
extern const u8 *const gTitleSavedAnimSprites[];
extern const s16 gEReaderAccessButtonSequence[];
//extern ? gMonPortraitGroupPals;
//extern ? gMonPortraitGroupGfx;
//extern ? gMonHatchSpriteGroup0_Gfx;
//extern ? gMonHatchSpriteGroup1_Gfx;
//extern ? gMonHatchSpriteGroup2_Gfx;
//extern ? gMonHatchSpriteGroup3_Gfx;
//extern ? gMonHatchSpriteGroup4_Gfx;
extern const u8 gMonHatchSpriteGroup5_Gfx[];
extern struct VectorU16 gFieldSelectBallSpeedPositions[];
extern const struct SpriteSet *const gFieldSelectSpriteSets[];
extern const struct SpriteSet *const gNameEntryCursorSpriteSets[];
extern const struct SpriteSet *const gHighScoreScreenSpriteSets[];
extern const struct SpriteSet *const gCompletionBannerSpriteSets[];
extern void (*gFieldSelectStateFuncs[])(void);
extern u8 gFieldSelectBG0Tilemap[];
extern u8 gFieldSelectWindow_Gfx[];
//extern ? gUnknown_080A4000;
extern u8 gFieldSelectFrameShadowTilemap[];
extern u8 gFieldSelectMiniFields_Gfx[];
//extern ? gUnknown_080A8020;
extern u8 gFieldSelectWindowTilemap[];
extern u16 gFieldSelectBGPals[];
extern u16 gFieldSelectSpritePals[];
extern u8 gFieldSelectSpriteGfx[];
extern u8 gEReaderText_Gfx[];
extern const u8 gTitlescreenBgTilemap[];
extern const u16 gTitlescreenBg_Pals[];
extern const u8 gTitlescreenBg_Gfx[];
extern const u8 gTitlescreenSpritesNoSavedGame_Gfx[];
//extern ? gUnknown_081306C0;
extern const u8 gTitlescreenSpritesSavedGame_Gfx[];
//extern ? gUnknown_081376E0;
extern const u16 gTitlescreenSprites_Pals[];
//extern ? gMonHatchSpriteGroup0_Pals;
//extern ? gMonHatchSpriteGroup1_Pals;
//extern ? gMonHatchSpriteGroup2_Pals;
//extern ? gMonHatchSpriteGroup3_Pals;
//extern ? gMonHatchSpriteGroup4_Pals;
//extern ? gMonHatchSpriteGroup5_Pals;
//extern ? gMonPortraitsGroup0_Gfx;
//extern ? gMonPortraitsGroup1_Gfx;
//extern ? gMonPortraitsGroup2_Gfx;
//extern ? gMonPortraitsGroup3_Gfx;
//extern ? gMonPortraitsGroup4_Gfx;
//extern ? gMonPortraitsGroup5_Gfx;
//extern ? gMonPortraitsGroup6_Gfx;
//extern ? gMonPortraitsGroup7_Gfx;
//extern ? gMonPortraitsGroup8_Gfx;
//extern ? gMonPortraitsGroup9_Gfx;
//extern ? gMonPortraitsGroup10_Gfx;
//extern ? gMonPortraitsGroup11_Gfx;
//extern ? gMonPortraitsGroup12_Gfx;
//extern ? gMonPortraitsGroup13_Gfx;
//extern ? gMonPortraitsGroup0_Pals;
//extern ? gMonPortraitsGroup1_Pals;
//extern ? gMonPortraitsGroup2_Pals;
//extern ? gMonPortraitsGroup3_Pals;
//extern ? gMonPortraitsGroup4_Pals;
//extern ? gMonPortraitsGroup5_Pals;
//extern ? gMonPortraitsGroup6_Pals;
//extern ? gMonPortraitsGroup7_Pals;
//extern ? gMonPortraitsGroup8_Pals;
//extern ? gMonPortraitsGroup9_Pals;
//extern ? gMonPortraitsGroup10_Pals;
//extern ? gMonPortraitsGroup11_Pals;
//extern ? gMonPortraitsGroup12_Pals;
//extern ? gMonPortraitsGroup13_Pals;
extern struct VectorU16 gTitleNoSaveArrowPositions[4];
extern struct VectorU16 gTitleNoSaveSelectorPositions[4];
extern struct VectorU16 gTitleSavedArrowPositions[5];
extern struct VectorU16 gTitleSavedSelectorPositions[5];
extern const struct VectorU32 gHighScoreNamePixelPositions[2][8];

struct CollisionCorrectionEntry
{
    s8 correctionX;
    s8 correctionY;
    u16 angleThreshold;
};
extern struct CollisionCorrectionEntry gWallCollisionPositionCorrection[8];
extern struct CollisionCorrectionEntry gFlipperCollisionAngleCorrection[3];

extern u16 gPokedexVramBuffer[];
extern s16 gPokedexNumOwned;
extern s16 gPokedexSelectedMon;
extern s8 gLinkExchangeResult;
extern s16 gPokedexNumSeen;
extern s16 gPokedexListPosition;

extern StateFunc gPokedexStateFuncs[];
extern u16 gPokedexBg1_Tilemap[];
extern u16 gPokedexBgText_Gfx[];
extern u16 gPokedexBg2_Tilemap[];
extern u16 gPokedexBg_Gfx[];
extern u16 gPokedexBg3_Tilemap[];
extern u8 gPokedexBackground_Pals[];
extern u8 gPokedexSprites_Pals[];
extern u8 gPokedexSprites_Gfx[];

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
extern s8 gPokedexShowLinkCableIcon;
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

extern u16 gDexInfoWindowEmptyTextRowTiles[];
extern u16 gDexInfoWindowMiddleRowTiles[];
extern u16 gDexInfoWindowBottomRowTiles[];
extern u16 gDexInfoWindowEmptyRowTiles[];
extern u16 gPokedexInfoWindowBackupTiles[];
extern u16 gPokedexInfoWindowTiles[];
extern u16 gRayquazaBodyCollisionMap[0x4000];
extern s16 gDexAnimationIx[];
extern s16 gTitleRevealJingle[][10][2];
extern u8 gLinkExchangeStep;

extern const struct PokemonSpecies gSpeciesInfo[];
extern const struct SpriteSet * const gCatchHatchSpriteSets[13];
extern u8 (*gMonHatchSpriteGroupGfx[])[0x10E0];
extern u8 (*gMonHatchSpriteGroupPals[])[0x20];

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

extern const u16 gHighScoreCharToTileMap[];
extern s16 gScoreDigitBuffer[];

struct HighScoreNamePosition
{
    u32 yBaseOffset;
    u32 yPixelPosition;
    u32 fieldWidth;
};
extern const struct HighScoreNamePosition gHighScoreNamePositions[][8];

extern struct Vector16 gIntroScene1_BGAnimTiming[0x8];
extern s16 gIntroScene1_TileOffsets[0x8];
extern s16 gIntroBGParams[];
extern s32 gIntroPalFadeLevel;
extern const struct SpriteSet *const gIntroScene1_SpriteSets[];
extern struct SpriteGroup gMain_spriteGroups_40[];
extern struct SpriteGroup gMain_spriteGroups_48;
extern struct Vector16 gIntroScene1_ScaleOffsets[0x4];
extern s32 gIntroScaleY;

extern const struct SpriteSet *const gIntroScene3_SpriteSets[];
extern const struct SpriteSet *const gIntroScene5_SpriteSets[];
extern u8 gIntroScene4_Pal[];
extern u8 gIntroScene4_BG3Tilemap[];
extern u8 gIntroScene4Sprites_Gfx[];
extern u8 gIntroScene4_BG0Tiles[];
extern u8 gIntroScene4_BG1Tiles[];

extern u16 gTextTilemapBuffer[];

extern u8 gIntroScene5_Pal[];
extern u8 gIntroScene5_BG2Tilemap[];
extern u8 gIntroScene5_BG1Tiles[];
extern u8 gIntroScene5_BG3Tilemap[];
extern u8 gIntroScene5Text_Gfx[];
extern u8 gIntroScene5_BG0Tiles[];
extern u8 gIntroScene5Sprites_Gfx[];
extern s16 gIntroScene5_TileOffsets[];

extern s8 gIntroScene6VelocityIndex;
extern s8 gIntroScene6EntitySpawnIndex;

extern u8 gIntroScene6_Pal[];
extern u8 gIntroScene6_BG3Tilemap[];
extern u8 gIntroScene6Sprites_Gfx[];
extern u8 gIntroScene6_BG2Tilemap[];
extern u8 gIntroScene6_BG0Tilemap[];
extern u8 gIntroScene6_BG1Tiles[];
extern u8 gIntroScene6Stars_Gfx[];

extern u8 gIntroScene6_BounceFlags[];
extern const struct SpriteSet *const gIntroScene6_SpriteSets[];

extern s16 gIntroWailmerScaleX;
extern s16 gIntroWailmerScaleY;
extern const struct SpriteSet *const gIntroScene7_SpriteSets[];
extern const struct SpriteSetTableEntry gFieldSpriteSets[];
extern u8 gIntroScene7_Pal[];
extern u8 gIntroScene7_BG3Tilemap[];
extern u8 gIntroScene7Sprites_Gfx[];
extern u8 gIntroScene7_BG2Tiles[];
extern u8 gIntroScene7_BG0Tiles[];
extern u8 gIntroScene7_BG1Tiles[];
extern u8 gIntroScene7Wailmer_Gfx[];

extern s8 gLinkExchangeSendPhase;

extern u8 gIntroScene8a_Pal[];
extern u8 gIntroScene8a_BG2Tilemap[];
extern u8 gIntroScene7Explosion_Gfx[];
extern u8 gIntroScene7WailmerLaunch_Gfx[];

extern s8 gIntroScene8b_BallDecelTable[];
extern s8 gIntroObjWhiteFlash;
extern s8 gIntroBGWhiteFlash;

extern u8 gIntroScene8b_Pal[];
extern u8 gIntroScene8b_BG3Tilemap[];
extern u8 gIntroScene8Clouds_Gfx[];
extern u8 gIntroScene8Ball_Gfx[];

extern u16 gCommonAndEggWeights[];
extern u16 gMain_saveData_pokedexFlags_90[10];
extern u16 Sio32ConnectionData[4]; 
extern u32 gSio32SendData;

/*
    Note: gMain lives at gUnknown_0200B0C0 in running memory.
    anything from there to gUnknown_0200FAE0 is part of that object.
*/
#endif  // GUARD_VARIABLES_H
