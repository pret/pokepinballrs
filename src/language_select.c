#include "global.h"
#include "constants/bg_music.h"
#include "main.h"
#include "m4a.h"
#include "titlescreen.h"

// Language selection screen of the European release.
// It is shown on first boot (when no language has been saved yet) and
// when the player chooses the language option from the title screen.

#ifdef EUROPE

#define BG_CHAR_ADDR(n)   (BG_VRAM + BG_CHAR_SIZE * (n))
#define BG_SCREEN_ADDR(n) (BG_VRAM + BG_SCREEN_SIZE * (n))

extern void CopyPixelCanvasRect(const void *volatile src, void *volatile dest, s16 width, s16 height);

EWRAM_DATA s8 gLanguageSelectCursor;
EWRAM_DATA s8 gLanguageSelectAnimTimer;
EWRAM_DATA s8 gLanguageSelectAnimFrame;
EWRAM_DATA s8 gLanguageSelectAnimTile;

extern EWRAM_DATA s16 gIntroFrameCounter;
extern EWRAM_DATA s8 gIntroSceneIndex;

// Rom_1 data
extern const StateFunc gLanguageSelectStateFuncs[];
extern const u8 gLanguageSelect_Gfx[];
extern const u8 gLanguageSelectBg0_Tilemap[];
extern const u8 gLanguageSelectBg1_Tilemap[];
extern const Palette gLanguageSelectBg_Pals[];
extern const Palette gLanguageSelectSprite_Pals[];
extern const u8 gLanguageSelectSprite_Gfx[];
// Translated titles for French, German, Italian and Spanish (English is in gLanguageSelect_Gfx)
extern const u8 gLanguageSelectTitle_Gfx[];

// Rom_2 data
extern const struct SpriteSet *const gLanguageSelectSpriteSets[7];
// { tile, duration } for each of the 7 frames of the selection arrows' animation
extern const s8 gLanguageSelectArrowAnim[7][2];

void LanguageSelect_Init(void);
void LanguageSelect_RenderSprites(void);

void LanguageSelectMain(void)
{
    gLanguageSelectStateFuncs[gMain.subState]();
}

void LanguageSelect_LoadGraphics(void)
{
    ResetDisplayState();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(0) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;

    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gLanguageSelect_Gfx, BG_CHAR_ADDR(1), 0x2000);
    DmaCopy16(3, gLanguageSelectBg0_Tilemap, BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gLanguageSelectBg1_Tilemap, BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gLanguageSelectBg_Pals, BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gLanguageSelectSprite_Pals, OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gLanguageSelectSprite_Gfx, OBJ_VRAM0, 0x1020);

    EnableVBlankInterrupts();
    LanguageSelect_Init();
    LanguageSelect_RenderSprites();
    FadeInScreen();
    gMain.subState++;
}

void LanguageSelect_Init(void)
{
    if (gMain_saveData.language == LANGUAGE_UNSET)
    {
        gLanguageSelectCursor = LANGUAGE_ENGLISH;
        gIntroFrameCounter = 0;
        gIntroSceneIndex = 0;
        SetMainCallback(IntroVBlankCallback);
    }
    else
    {
        gLanguageSelectCursor = gMain_saveData.language;
    }

    switch (gLanguageSelectCursor)
    {
    case LANGUAGE_FRENCH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_ITALIAN:
    case LANGUAGE_SPANISH:
        CopyBgTilesRect(&gLanguageSelectTitle_Gfx[(gLanguageSelectCursor - 1) * 0x800], (void *)(BG_CHAR_ADDR(1) + 0x140), 22, 2);
        break;
    }

    gLanguageSelectAnimTimer = 0;
    gLanguageSelectAnimFrame = 0;
    gLanguageSelectAnimTile = 0;
}

void LanguageSelect_HandleInput(void)
{
    gLanguageSelectAnimTimer++;
    if (gLanguageSelectAnimTimer >= gLanguageSelectArrowAnim[gLanguageSelectAnimFrame][1])
    {
        gLanguageSelectAnimTimer = 0;
        gLanguageSelectAnimFrame++;
        if (gLanguageSelectAnimFrame > 6)
            gLanguageSelectAnimFrame = 0;
        gLanguageSelectAnimTile = gLanguageSelectArrowAnim[gLanguageSelectAnimFrame][0];
    }

    LanguageSelect_RenderSprites();

    if (JOY_NEW(DPAD_UP))
    {
        if (gLanguageSelectCursor > LANGUAGE_ENGLISH)
        {
            m4aSongNumStart(SE_MENU_MOVE);
            gLanguageSelectCursor--;
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gLanguageSelectCursor < LANGUAGE_SPANISH)
        {
            m4aSongNumStart(SE_MENU_MOVE);
            gLanguageSelectCursor++;
        }
    }

    if (JOY_NEW(A_BUTTON | START_BUTTON))
    {
        m4aSongNumStart(SE_MENU_SELECT);
        gLanguageSelectAnimTimer = 0;
        gLanguageSelectAnimFrame = 0;
        gMain.subState++;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if (gMain.saveData.language != LANGUAGE_UNSET)
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            FadeOutScreen();
            DisableVBlankInterrupts();
            gAutoDisplayTitlescreenMenu = TRUE;
            SetMainGameState(STATE_TITLE);
        }
    }
}

void LanguageSelect_BlinkSelection(void)
{
    if (gLanguageSelectAnimTimer % 4 == 0)
    {
        if (gLanguageSelectAnimFrame == 0)
        {
            gLanguageSelectAnimFrame = 1;
            CopyPixelCanvasRect((void *)(BG_SCREEN_ADDR(0) + 0x256 + gLanguageSelectCursor * 0x80), gBG0TilemapBuffer, 9, 2);
            CopyPixelCanvasRect((void *)BG_SCREEN_ADDR(0), (void *)(BG_SCREEN_ADDR(0) + 0x256 + gLanguageSelectCursor * 0x80), 9, 2);
        }
        else
        {
            gLanguageSelectAnimFrame = 0;
            CopyPixelCanvasRect(gBG0TilemapBuffer, (void *)(BG_SCREEN_ADDR(0) + 0x256 + gLanguageSelectCursor * 0x80), 9, 2);
        }
    }

    if (gLanguageSelectAnimTimer > 20)
        gMain.subState++;

    gLanguageSelectAnimTimer++;
}

void LanguageSelect_Exit(void)
{
    if (gMain_saveData.language == LANGUAGE_UNSET)
    {
        FadeOutToBlack(NULL);
        m4aMPlayAllStop();
        DisableVBlankInterrupts();
        gAutoDisplayTitlescreenMenu = FALSE;
        SetMainGameState(STATE_INTRO);
        gMain.subState = 3;
    }
    else
    {
        FadeOutScreen();
        DisableVBlankInterrupts();
        gAutoDisplayTitlescreenMenu = TRUE;
        SetMainGameState(STATE_TITLE);
    }

    gMain_saveData.language = gLanguageSelectCursor;
    SaveFile_WriteToSram();
}

void LanguageSelect_RenderSprites(void)
{
    struct SpriteGroup *titleGroup;
    struct SpriteGroup *leftArrowGroup;
    struct SpriteGroup *rightArrowGroup;
    struct OamDataSimple *oam;
    s32 i;

    titleGroup = &gMain.spriteGroups[gLanguageSelectCursor];
    leftArrowGroup = &gMain.spriteGroups[5];
    rightArrowGroup = &gMain.spriteGroups[6];

    titleGroup->active = TRUE;
    leftArrowGroup->active = TRUE;
    rightArrowGroup->active = TRUE;
    LoadSpriteSets(gLanguageSelectSpriteSets, 7, gMain.spriteGroups);

    titleGroup->baseX = 100;
    titleGroup->baseY = 24;
    for (i = 0; i < 2; i++)
    {
        oam = &titleGroup->oam[i];
        gOamBuffer[oam->oamId].x = oam->xOffset + titleGroup->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + titleGroup->baseY;
    }

    leftArrowGroup->baseX = 78;
    leftArrowGroup->baseY = gLanguageSelectCursor * 16 + 74;
    oam = &leftArrowGroup->oam[0];
    gOamBuffer[oam->oamId].tileNum = gLanguageSelectAnimTile * 2 + 25;
    gOamBuffer[oam->oamId].x = oam->xOffset + leftArrowGroup->baseX;
    gOamBuffer[oam->oamId].y = oam->yOffset + leftArrowGroup->baseY;

    rightArrowGroup->baseX = 144;
    rightArrowGroup->baseY = gLanguageSelectCursor * 16 + 74;
    oam = &rightArrowGroup->oam[0];
    gOamBuffer[oam->oamId].tileNum = gLanguageSelectAnimTile * 2 + 25;
    gOamBuffer[oam->oamId].hFlip = TRUE;
    gOamBuffer[oam->oamId].x = oam->xOffset + rightArrowGroup->baseX;
    gOamBuffer[oam->oamId].y = oam->yOffset + rightArrowGroup->baseY;

    titleGroup->active = FALSE;
    leftArrowGroup->active = FALSE;
    rightArrowGroup->active = FALSE;
}

#endif // EUROPE
