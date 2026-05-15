#ifndef GUARD_TITLESCREEN_H
#define GUARD_TITLESCREEN_H

struct TitlescreenStruct
{
    /*0x00*/ s8 menuCursorIndex;
    /*0x02*/ s16 animPhase;
    /*0x04*/ s16 animTimer;
    /*0x06*/ s8 menuAction;
    /*0x07*/ u8 hasSavedGame;
    /*0x08*/ s8 pressStartAnimSpriteGroupId;
    /*0x09*/ s8 pressStartAndFlippersVisible;
    /*0x0A*/ s8 menuSpriteGroupId;
    /*0x0B*/ s8 menuVisible;
    /*0x0C*/ s8 titleScreenLeftFlipperSpriteGroup;
    /*0x0D*/ s8 leftFlipperCursorVisible;
    /*0x0E*/ s8 titleScreenRightFlipperSpriteGroup;
    /*0x0F*/ s8 rightFlipperCursorVisible;
    /*0x10*/ s8 deleteSaveSpriteGroupId;
    /*0x11*/ s8 deleteSaveWindowVisible;
    /*0x12*/ s16 idleFadeoutCounter;
    /*0x14*/ s16 idleFramesCounter;
};

extern struct TitlescreenStruct gTitlescreen;
extern s8 gAutoDisplayTitlescreenMenu;
extern u8 gTitleReturnedFromMenu;
extern u16 gHighScoreEntrySource;
extern s8 gEraseSaveDataAccessStep;
extern s8 gEraseSaveDataAccessCounter;
extern s8 gEReaderAccessStep;
extern s8 gEReaderAccessCounter;
extern s8 gTitleTransitionActive;
extern s8 gTitleRestartDebounce;
extern const u8 *gTitleNoSaveMenuSpriteSets[];
extern const u8 *gTitleSavedMenuSpriteSets[];

#endif // GUARD_TITLESCREEN_H
