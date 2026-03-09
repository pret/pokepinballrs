#ifndef GUARD_TITLESCREEN_H
#define GUARD_TITLESCREEN_H

struct TitlescreenStruct
{
    /*0x00*/ s8 menuCursorIndex;
    /*0x02*/ s16 animKeyframe;
    /*0x04*/ s16 animTimer;
    /*0x06*/ s8 menuSelectionIndex;
    /*0x07*/ u8 useSavedGameSprites;
    /*0x08*/ s8 pressStartAnimFrame;
    /*0x09*/ s8 pressStartAndFlippersVisible;
    /*0x0A*/ s8 menuOptionsSpriteIndex;
    /*0x0B*/ s8 menuVisible;
    /*0x0C*/ s8 cursorSpriteIndexA;
    /*0x0D*/ s8 cursorVisibleA;
    /*0x0E*/ s8 cursorSpriteIndexB;
    /*0x0F*/ s8 cursorVisibleB;
    /*0x10*/ s8 deleteSaveSpriteIndex;
    /*0x11*/ s8 deleteSaveWindowVisible;
    /*0x12*/ s16 idleFadeoutCounter;
    /*0x14*/ s16 idleFramesCounter;
};

extern struct TitlescreenStruct gTitlescreen;
extern s8 gAutoDisplayTitlescreenMenu;
extern u8 gUnknown_202BE24;
extern u16 gUnknown_0202C588;
extern s8 gEraseSaveDataAccessStep;
extern s8 gEraseSaveDataAccessCounter;
extern s8 gEReaderAccessStep;
extern s8 gEReaderAccessCounter;
extern s8 gUnknown_020028A4;
extern s8 gUnknown_020028A5;
extern const u8 *gUnknown_0201C190[];
extern const u8 *gUnknown_0202BE00[];

#endif // GUARD_TITLESCREEN_H
