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

extern struct {u16 unk0[5]; u16 unkA[5];} gUnknown_086A6B14;
extern s8 gUnknown_02002850;
extern struct ToneData gUnknown_08532D6C[];
extern struct ToneData gUnknown_08533360[];
extern struct ToneData gUnknown_08533960[];
extern struct ToneData gUnknown_08533F60[];
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
extern u16 gUnknown_086BB910[11][4];
extern struct {u8 unk0; s16 unk2;} gUnknown_086BB9B4[];
extern u16 gOptionsSEList[];
extern u8 gUnknown_02031AF0[][10];
extern u8 gUnknown_08527ED6[4][10];
extern void (*const gOptionsStateFuncs[])(void);
extern u32 gHighScoreNameEntry[HIGH_SCORE_NAME_LENGTH];
extern u16 gUnknown_0201A520[3][BG_PLTT_SIZE];
extern u16 gUnknown_03000000[];
extern u8 gUnknown_03001800[3][0x800];
//extern ? gOamBuffer;
//extern ? IntrMain_Buffer;
extern u16 gUnknown_03005C00[];
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
extern struct RfuSIO32Id gUnknown_02002808;
extern u32 gUnknown_02002818;
extern u32 gUnknown_0200281C;
//extern ? gTitlescreen;
//extern ? gEraseSaveDataAccessStep;
//extern ? gEraseSaveDataAccessCounter;
//extern ? gEReaderAccessStep;
//extern ? gEReaderAccessCounter;
//extern ? gUnknown_020028A4;
//extern ? gUnknown_020028A5;
//extern ? gUnknown_02002958;
//extern ? gIntrTable;
//extern ? gMain;
//extern ? gVBlankIntrFuncPtr;
//extern ? gMainCallback;
//extern ? gUnknown_0200FBA0;
//extern ? gUnknown_02017BD0;
//extern ? gUnknown_02017BD4;
//extern ? gUnknown_02017BE0;
//extern ? gVCountIntrFuncPtr;
//extern ? gUnknown_02019BE4;
//extern ? gUnknown_02019BE8;
//extern ? gUnknown_02019BEC;
//extern ? gUnknown_02019BF0;
//extern ? gUnknown_02019BF4;
//extern ? gUnknown_02019BF8;
//extern ? gUnknown_02019BFC;
//extern ? gUnknown_02019C00;
//extern ? gUnknown_02019C04;
//extern ? gUnknown_02019C08;
//extern ? gGameBoyPlayerEnabled;
//extern ? gUnknown_02019C10;
extern s8 gAutoDisplayTitlescreenMenu;
//extern ? gUnknown_0201C190;
//extern ? gUnknown_0202BE00;
//extern ? gUnknown_202BE24;
extern s16 gUnknown_0202BEEC;
//extern ? gUnknown_0202C588;
//extern ? gCurrentPinballGame;
//extern ? gUnknown_02031520;
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
//extern ? gUnknown_086A4B08;
//extern ? gUnknown_086A4B14;
//extern ? gUnknown_086A4B20;
//extern ? gUnknown_086A4B30;
//extern ? gUnknown_086A4B40;
//extern ? gUnknown_086A4B54;
//extern ? gUnknown_086A4B70;
//extern ? gUnknown_086A4B80;
//extern ? gUnknown_086A4B94;
//extern ? gUnknown_086A4BAC;
//extern ? gUnknown_086A4BC8;
//extern ? gUnknown_086A4BE8;
//extern ? gUnknown_086A4BFC;
//extern ? gUnknown_086A4C18;
//extern ? gUnknown_086A4C2C;
extern const int *gUnknown_086A4C44[];
extern const u16 gUnknown_086A4CF8[][3*0x18];
extern const s8 gUnknown_086A7FA4[3]; //Sized based on call using gUnknown_02002858.unk1C + data
extern const s8 gUnknown_086A7FA8[3]; //Same as above
extern const s16 gUnknown_086A964C[11];
extern const s8 gUnknown_086A9662[4];
extern const s8 gUnknown_086A9666[6][2];
extern const s8 gUnknown_086A9672[9][2];
extern const u16 gUnknown_086A96A4[4];
extern const u16 gUnknown_086A96D4[];
extern const struct SpriteSet *const gUnknown_086A96E4[];
extern const u8 *const gUnknown_086A96F8[7];
extern const u8 *const gUnknown_086A9714[];
extern const s8 gUnknown_086A9748[];
extern const u8 *const gUnknown_086A975C[7];
extern const u8 *const gUnknown_086A9778[];
extern const s16 gEReaderAccessButtonSequence[];
//extern ? gMonPortraitGroupPals;
//extern ? gMonPortraitGroupGfx;
//extern ? gMonHatchSpriteGroup0_Gfx;
//extern ? gMonHatchSpriteGroup1_Gfx;
//extern ? gMonHatchSpriteGroup2_Gfx;
//extern ? gMonHatchSpriteGroup3_Gfx;
//extern ? gMonHatchSpriteGroup4_Gfx;
extern const u8 gMonHatchSpriteGroup5_Gfx[];
extern struct VectorU16 gUnknown_086A6B28[];
extern const struct SpriteSet *const gUnknown_086A6AD4[];
extern const struct SpriteSet *const gUnknown_086A7DA8[];
extern const struct SpriteSet *const gUnknown_086A7DB0[];
extern const struct SpriteSet *const gUnknown_086A7DD4[];
extern void (*gFieldSelectStateFuncs[])(void);
extern u8 gUnknown_080A2400[];
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
extern struct VectorU16 gUnknown_086A9684[4];
extern struct VectorU16 gUnknown_086A9694[4];
extern struct VectorU16 gUnknown_086A96AC[5];
extern struct VectorU16 gUnknown_086A96C0[5];
extern const struct VectorU32 gUnknown_080797F0[2][8];

struct Unk086ACD50
{
    s8 unk0;
    s8 unk1;
    u16 unk2;
};
extern struct Unk086ACD50 gUnknown_086ACD50[8];
extern struct Unk086ACD50 gUnknown_086ACD74[3];

extern u16 gUnknown_02019C40[];
extern s16 gPokedexNumOwned;
extern s16 gPokedexSelectedMon;
extern s8 gUnknown_0202ADE4;
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

extern s16 gUnknown_0201A448;
extern s16 gUnknown_0202BF00;
extern s16 gUnknown_0202A57C;
extern s16 gUnknown_0201A4F0;
extern s16 gUnknown_0202BE20;
extern s16 gPokedexScrollWaitFrames;
extern s8 gUnknown_02019C24;
extern s16 gUnknown_0202BF0C;
extern s16 gUnknown_0201A440;
extern s16 gUnknown_0202BEF4;
extern s16 gUnknown_0202A588;
extern s16 gUnknown_0202A55C;
extern s16 gUnknown_0202A568[2];
extern s16 gUnknown_0202C5E8;
extern s16 gUnknown_0202A558;
extern s8 gUnknown_0202BEE0;
extern s8 gUnknown_0202BF04;
extern s16 gUnknown_0202BF14;
extern s8 gUnknown_0202C590;
extern s16 gUnknown_0201B120;
extern s8 gUnknown_0202BEC4;
extern s8 gUnknown_0202BEFC;
extern s8 gUnknown_02002830;
extern s8 gUnknown_02002831;
extern s8 gUnknown_0202C794;
extern s8 gUnknown_0201C1B4;
extern s8 gUnknown_0202C5AC;
extern s8 gUnknown_02019C28;
extern s16 gPokedexFlags[];
extern s16 gPokedexFlagExchangeBuffer[];
extern s16 gPokedexListEntryCount;

extern u32 gUnknown_0201B170;
extern u32 gUnknown_0202BED8;

extern u16 gDexInfoWindowEmptyTextRowTiles[];
extern u16 gDexInfoWindowMiddleRowTiles[];
extern u16 gDexInfoWindowBottomRowTiles[];
extern u16 gDexInfoWindowEmptyRowTiles[];
extern u16 gUnknown_0202A590[];
extern u16 gUnknown_08086B40[];
extern u16 gUnknown_083722E8[0x4000];
extern s16 gUnknown_086A61BC[];
extern s16 gUnknown_086A77A8[][10][2];
extern u8 gUnknown_0201B124;

extern const struct PokemonSpecies gSpeciesInfo[];
extern const struct SpriteSet * const gUnknown_086A54D8[13];
extern u8 (*gMonHatchSpriteGroupGfx[])[0x10E0];
extern u8 (*gMonHatchSpriteGroupPals[])[0x20];

extern u32 gUnknown_0202ADD0;
extern s16 gUnknown_0202C5F0[];
extern u16 gUnknown_0201A4D0[][2];
extern u32 gUnknown_0202BDF0;
extern u8 gUnknown_0201C1AC;
extern u8 gUnknown_0202ADDC;
extern u16 gUnknown_0201A510;
extern s16 gUnknown_0201A444;
extern s8 gUnknown_0201B128;
extern s8 gUnknown_0202A564;
extern s8 gUnknown_02019C20;
extern s8 gUnknown_0202ADE8;

extern const u16 gUnknown_086A7FAC[];
extern s16 gUnknown_0202C5C0[];

struct unkStruct_8079730
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};
extern const struct unkStruct_8079730 gUnknown_08079730[][8];

struct UnkStruct_086A7768 {
    s16 unk0;
    s16 unk2;
};

extern struct UnkStruct_086A7768 gUnknown_086A7768[0x8];
extern s16 gUnknown_086A7788[0x8];
extern s16 gUnknown_0202ADA0[];
extern s32 gUnknown_0202BEF0;
extern const struct SpriteSet *const gUnknown_086A769C[];
extern struct SpriteGroup gMain_spriteGroups_40[];
extern struct SpriteGroup gMain_spriteGroups_48;
extern struct UnkStruct_086A7768 gUnknown_086A7798[0x4];
extern s32 gUnknown_0201C188;

extern const struct SpriteSet *const gUnknown_086A795C[];
extern const struct SpriteSet *const gUnknown_086A79EC[];
extern u8 gUnknown_080E1540[];
extern u8 gUnknown_080E1740[];
extern u8 gIntroScene4Sprites_Gfx[];
extern u8 gUnknown_080E5F60[];
extern u8 gUnknown_080E7F60[];

extern u16 gUnknown_03002300[];

extern u8 gUnknown_080E9F60[];
extern u8 gUnknown_080EA160[];
extern u8 gUnknown_080EB160[];
extern u8 gUnknown_080EC160[];
extern u8 gUnknown_080EC960[];
extern u8 gUnknown_080F1980[];
extern u8 gUnknown_080F2180[];
extern s16 gUnknown_086A7A1C[];

extern s8 gUnknown_0202C548;
extern s8 gUnknown_0202BEB4;

extern u8 gUnknown_080F61A0[];
extern u8 gUnknown_080F63A0[];
extern u8 gUnknown_080F6BA0[];
extern u8 gUnknown_080FCFC0[];
extern u8 gUnknown_080FD7C0[];
extern u8 gUnknown_080FDFC0[];
extern u8 gUnknown_080FFFC0[];

extern u8 gUnknown_086A7AE4[];
extern const struct SpriteSet *const gUnknown_086A7A78[];

extern s16 gUnknown_0202C5E4;
extern s16 gUnknown_0202ADD8;
extern const struct SpriteSet *const gUnknown_086A7B74[];
extern const struct SpriteSetTableEntry gUnknown_086B155C[];
extern u8 gUnknown_08100FE0[];
extern u8 gUnknown_081011E0[];
extern u8 gUnknown_081019E0[];
extern u8 gUnknown_08106A00[];
extern u8 gUnknown_08108A00[];
extern u8 gUnknown_0810AA00[];
extern u8 gUnknown_0810CA00[];

extern s8 gUnknown_0201A4BC;

extern u8 gUnknown_0810EA20[];
extern u8 gUnknown_0810EC20[];
extern u8 gUnknown_0810F420[];
extern u8 gUnknown_08112840[];

extern s8 gUnknown_086A7D4C[];
extern s8 gUnknown_0202BEDC;
extern s8 gUnknown_0202A56C;

extern u8 gUnknown_08115860[];
extern u8 gUnknown_08115A60[];
extern u8 gUnknown_08116260[];
extern u8 gUnknown_08118680[];

extern u16 gCommonAndEggWeights[];
extern u16 gMain_saveData_pokedexFlags_90[10];
extern u16 Sio32ConnectionData[4]; 
extern u32 gUnknown_02002814;

/*
    Note: gMain lives at gUnknown_0200B0C0 in running memory.
    anything from there to gUnknown_0200FAE0 is part of that object.
*/
#endif  // GUARD_VARIABLES_H
