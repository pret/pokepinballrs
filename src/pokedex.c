#include "global.h"
#include "functions.h"
#include "link.h"
#include "m4a.h"
#include "main.h"
#include "types.h"
#include "variables.h"
#include "constants/bg_music.h"
#include "constants/characters.h"

#define DEX_NUM_DIGITS      3
#define SCROLL_WAIT_FRAMES  9
#define ENTRIES_SHOWN_COUNT 5

enum PokedexStates
{
    POKEDEX_STATE_LOAD_GRAPHICS,
    POKEDEX_STATE_HANDLE_LIST_INPUT,
    POKEDEX_STATE_2,
    POKEDEX_STATE_3,
    POKEDEX_STATE_4,
    POKEDEX_STATE_5,
    POKEDEX_STATE_LINK_SETUP,
    POKEDEX_STATE_7,
    POKEDEX_STATE_8,
    POKEDEX_STATE_9,
    POKEDEX_STATE_10,
    POKEDEX_STATE_DELETE_CONFIRMATION,
    POKEDEX_STATE_RETURN_TO_TITLE,
};

void RefreshPokedexListDisplay(void);
static void PokedexListScrollUp(void);
static void PokedexListScrollDown(void);
static void PokedexListScrollUpFast(void);
static void PokedexListScrollDownFast(void);
void Pokedex_CheckDeleteKeyComboPressed(void);
void UpdateMonSpriteVisibility(void);
void RefreshMonPreviewSprite(void);
static s16 Pokedex_ProcessLinkExchange(void);
s16 SendLinkPokedexData(void);
void PrintDexDescription(s16, u32);
void LoadPokedexFlagsFromSave(void);
void RenderPokedexSprites(void);
static void RenderLinkGraphics(void);
static void InitLinkTransferState(void);
int MasterReceivePokedexFlags(void);
static int MasterSendPokedexFlags(void);
static int ClientSendPokedexFlags(void);
static int ClientReceivePokedexFlags(void);
static void PrintSelectedMonDexNum(s16);
static void PrintSeenOwnedTotals(s16, s16);
void BlitGlyphToTileBuffer(int, int, int);
void PrintDexNumbersFromListPosition(s16);
static void PrintCaughtBallFromListPosition(s16);
void LoadMonPortrait(s16);

extern u8 *gMonIconPalettes[];
extern u8 *gCatchSpriteGfxPtrs[];

extern u16 gPokedexLinkSendCounter;
extern u16 gPokedexLinkChunkIndex;
extern s8 gPokedexMasterHandshakeState;
extern s8 gPokedexClientHandshakeState;
extern s8 gPokedexHandshakeRetryCount;
extern u16 gGlyphUpperRowBuffer[];
extern u16 gGlyphLowerRowBuffer[];

extern const struct SpriteSet *const gPokedexSpriteSets[];
extern u16 gPokedexScrollbarY;
extern const u16 gPokedexAnimBaseTileNums[][4];
extern const u16 gPokedexCatchAnimTileOffsets[][20];
extern const s16 gPokedexCatchAnimIndices[];
extern const u16 gPokedexHatchAnimTileOffsets[][51];
extern const s16 gPokedexAnimFrameDurations[][51];
extern const u16 gPokedexAnimTileDeltas[][4];
extern s16 gPokedexListNameVramOffsets[];

enum PokedexPopupType {
    POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT = 0,
    POKEDEX_POPUP_TRANSMITTING_ACTIVE = 1,
    POKEDEX_POPUP_TRANSMISSION_ERROR = 2,
    POKEDEX_POPUP_TRANSMISSION_COMPLETE = 3,
    POKEDEX_POPUP_DELETE_CONFIRMATION_PROMPT = 4
};

// The japanese and english text glyphs are sourced from the same blob of tile graphics, and
// each glyph is two tiles high.
#define ENGLISH_GLYPHS_START 0x2820
extern const u8 gPokedexTextGlyphs_Gfx[];

struct PokedexEntry
{
    /*0x00*/ u16 dexNum[DEX_NUM_DIGITS];
    /*0x06*/ u16 heightWeight[POKEMON_HEIGHT_WEIGHT_TEXT_LENGTH];
    /*0x18*/ s16 name[POKEMON_NAME_LENGTH];
    /*0x2C*/ s16 category[POKEMON_CATEGORY_NAME_LENGTH];
    // The dex description has 2 pages with 3 lines each. Each line
    // is 42 characters long.
    /*0x42*/ s16 description[2 * 3 * POKEMON_DEX_LINE_LENGTH];
}; /* size=0x23C */

extern const struct PokedexEntry gPokedexEntries[];

void PokedexMain(void)
{
    gPokedexStateFuncs[gMain.subState]();
}

void LoadPokedexGraphics(void)
{
    ResetDisplayState();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    REG_BG1CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(0) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG3_ON;

    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gPokedexBgText_Gfx, (void *)BG_CHAR_ADDR(1), 0x4400);
    DmaCopy16(3, gPokedexBg_Gfx, (void *)BG_CHAR_ADDR(3), 0x1400);
    DmaCopy16(3, gPokedexBackground_Pals, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gPokedexBg1_Tilemap, gBG0TilemapBuffer, BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexBg2_Tilemap, gPokedexVramBuffer, BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexBg3_Tilemap, (void *)BG_SCREEN_ADDR(2), BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexSprites_Pals, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gPokedexSprites_Gfx, (void *)OBJ_VRAM0, 0x6C20);

    InitPokedexState();
    PrintSeenOwnedTotals(gPokedexNumSeen, gPokedexNumOwned);
    PrintSelectedMonDexNum(gPokedexSelectedMon);
    PrintDexNumbersFromListPosition(gPokedexListPosition);
    PrintCaughtBallFromListPosition(gPokedexListPosition);
    LoadMonPortrait(gPokedexSelectedMon);
    LoadMonAnimationSprite(gPokedexSelectedMon);
    CheckMonHasAnimation(gPokedexSelectedMon);

    gPokedexVramBuffer[0x134] = 0x59;

    DmaCopy16(3, gBG0TilemapBuffer, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexVramBuffer, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);

    RenderPokedexSprites();
    EnableVBlankInterrupts();
    FadeInScreen();

    gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;

    m4aSongNumStart(MUS_POKEDEX);
}

void InitPokedexState(void)
{
    s32 i;

    gPokedexSelectedMon = 0;
    gPokedexListPosition = 0;
    gPokedexAnimatedIconFrame = 0;
    gPokedexAnimatedIconTimer = 0;
    gPokedexCursorOffset = 0;
    gPokedexCursorBlinkOffset = 0;
    gPokedexBlinkTimer = 0;
    gPokedexScrollWaitFrames = 0;
    gPokedexScrollActive = 0;
    gPokedexSpriteAnimFrame = 0;
    gPokedexSpriteAnimTimer = 0;
    gPokedexDetailFrameCount = 0;
    gPokedexPageIndicatorTimer = 0;
    gPokedexShowAnimSprite = 1;
    gPokedexShowPortrait = 1;

    gPokedexShowCatchHatch[0] = 0;
    gPokedexShowCatchHatch[1] = 0;

    gPokedexSpriteCategory = 0;
    gPokedexInfoWindowSlideStep = 0;
    gPokedexButtonPromptFrame = 0;
    gPokedexShowButtonPrompt = 1;

    LoadPokedexFlagsFromSave();
    if (CheckAllPokemonCaught() == 1)
    {
        gPokedexShowLinkCableIcon = 1;
    }
    else
    {
        gPokedexShowLinkCableIcon = 0;
    }

    gPokedexShowPopupWindow = 0;
    gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT;
    gPokedexLinkStateTimer = 0;
    gPokedex_EraseSaveDataAccessCounter = 0;
    gPokedex_EraseSaveDataAccessStep = 0;
    gPokedexDescriptionPage = 0;
    gPokedexShowPageIndicator = 0;
    gPokedexPageIndicatorBlink = 0;
    gPokedexSpriteIndexBase = 0;

    for (i = 0; i < 0xE1; i++)
    {
        gPokedexFlagExchangeBuffer[i] = gPokedexFlags[i];
    }

    if (gPokedexFlags[SPECIES_AERODACTYL])
        gPokedexListEntryCount = SPECIES_AERODACTYL + 1;
    else if (gPokedexFlags[SPECIES_TOTODILE])
        gPokedexListEntryCount = SPECIES_TOTODILE + 1;
    else if (gPokedexFlags[SPECIES_CYNDAQUIL])
        gPokedexListEntryCount = SPECIES_CYNDAQUIL + 1;
    else if (gPokedexFlags[SPECIES_CHIKORITA])
        gPokedexListEntryCount = SPECIES_CHIKORITA + 1;
    else if (gPokedexFlags[SPECIES_JIRACHI])
        gPokedexListEntryCount = SPECIES_JIRACHI + 1;
    else
        gPokedexListEntryCount = SPECIES_RAYQUAZA + 1;
}

void Pokedex_HandleListInput(void)
{
    if (JOY_HELD(SELECT_BUTTON))
    {
        gPokedexShowButtonPrompt = 0;

        if (JOY_HELD(DPAD_UP))
        {
            PokedexListScrollUp();
            UpdateMonSpriteVisibility();
            RefreshMonPreviewSprite();
            gMain.subState = POKEDEX_STATE_2;
        }
        else if (JOY_HELD(DPAD_DOWN))
        {
            PokedexListScrollDown();
            UpdateMonSpriteVisibility();
            RefreshMonPreviewSprite();
            gMain.subState = POKEDEX_STATE_2;
        }
        else if (JOY_HELD(DPAD_LEFT))
        {
            PokedexListScrollUpFast();
            UpdateMonSpriteVisibility();
            RefreshMonPreviewSprite();
            gMain.subState = POKEDEX_STATE_2;
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            PokedexListScrollDownFast();
            UpdateMonSpriteVisibility();
            RefreshMonPreviewSprite();
            gMain.subState = POKEDEX_STATE_2;
        }
        else
        {
            gPokedexScrollActive = 0;
            UpdateMonSpriteVisibility();
        }

        if (JOY_NEW(A_BUTTON))
        {
            gPokedexDetailFrameCount = 0;

            if (gPokedexFlags[gPokedexSelectedMon] >= 2)
            {
                gPokedexShowButtonPrompt = 0;
                DmaCopy16(3, 0x6000280, (void *)gPokedexInfoWindowBackupTiles, 0x200);
                gMain.subState = POKEDEX_STATE_3;
            }
            else
            {
                m4aSongNumStart(SE_FAILURE);
            }
        }
    }
    else
    {
        gPokedexShowButtonPrompt = 1;

        if (JOY_HELD(DPAD_UP))
        {
            PokedexListScrollUp();
            RefreshPokedexListDisplay();
        }
        else if (JOY_HELD(DPAD_DOWN))
        {
            PokedexListScrollDown();
            RefreshPokedexListDisplay();
        }
        else if (JOY_HELD(DPAD_LEFT))
        {
            PokedexListScrollUpFast();
            RefreshPokedexListDisplay();
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            PokedexListScrollDownFast();
            RefreshPokedexListDisplay();
        }
        else
        {
            gPokedexScrollActive = 0;
        }

        if (CheckMonHasAnimation(gPokedexSelectedMon) == 1)
            gPokedexShowAnimSprite = 1;
        else
            gPokedexShowAnimSprite = 0;

        gPokedexShowPortrait = 1;
        gPokedexShowCatchHatch[0] = 0;
        gPokedexShowCatchHatch[1] = 0;
        gPokedexSpriteAnimTimer = 0;
        gPokedexSpriteAnimFrame = 0;

        if (JOY_NEW(A_BUTTON))
        {
            gPokedexDetailFrameCount = 0;

            if (gPokedexFlags[gPokedexSelectedMon] >= SPECIES_SHARED)
            {
                gPokedexShowButtonPrompt = 0;
                DmaCopy16(3, 0x6000280, (void *)gPokedexInfoWindowBackupTiles, 0x200);
                gMain.subState = POKEDEX_STATE_3;
            }
            else
            {
                m4aSongNumStart(SE_FAILURE);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gMain.subState = POKEDEX_STATE_RETURN_TO_TITLE;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            m4aSongNumStart(SE_MENU_POPUP_OPEN);
            gPokedexShowPopupWindow = 1;
            gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT;
            gPokedexShowButtonPrompt = 0;
            gPokedexShowAnimSprite = 0;
            gMain.subState = POKEDEX_STATE_LINK_SETUP;
        }

        Pokedex_CheckDeleteKeyComboPressed();
    }

    if (gPokedexScrollWaitFrames > 0)
        gPokedexScrollWaitFrames--;

    RenderPokedexSprites();
    DmaCopy16(3, gBG0TilemapBuffer, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
}

void Pokedex_PostScrollRefresh(void)
{
    RefreshPokedexListDisplay();
    gPokedexShowAnimSprite = 0;

    if (gPokedexScrollWaitFrames > 0)
        gPokedexScrollWaitFrames--;

    RenderPokedexSprites();
    DmaCopy16(3, gBG0TilemapBuffer, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;
}

void Pokedex_InfoWindowSlideIn(void)
{
    int i;

    for (i = 0; i < 0x20; i++)
    {
        gBG0TilemapBuffer[0x20*(gPokedexInfoWindowSlideStep + 10) + i] = gDexInfoWindowEmptyTextRowTiles[i];
        gPokedexVramBuffer[0x20*(gPokedexInfoWindowSlideStep + 9) + i] = gDexInfoWindowMiddleRowTiles[i];
        gPokedexVramBuffer[0x20*(gPokedexInfoWindowSlideStep + 10) + i] = gDexInfoWindowBottomRowTiles[i];
    }

    gPokedexInfoWindowSlideStep++;
    gPokedexVramBuffer[0x134] = 0x59;
    DmaCopy16(3, gBG0TilemapBuffer, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexVramBuffer, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);

    if (gPokedexInfoWindowSlideStep > 7)
    {
        gPokedexInfoWindowSlideStep = 0;
        gPokedexDetailFrameCount = 0;
        gPokedexPageIndicatorTimer = 0;
        gPokedexSpriteIndexBase = 0;
        gPokedexPageIndicatorBlink = 0;

        if (gPokedexSelectedMon < BONUS_SPECIES_START)
            gPokedexShowPageIndicator = 1;

        DmaCopy16(3, gPokedexInfoWindowTiles, (void *)0x6000280, 2*0xE0);
        PrintDexDescription(gPokedexSelectedMon, gPokedexDescriptionPage);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x40);
        PlayCry_NormalNoDucking(gSpeciesInfo[gPokedexSelectedMon].speciesIdRS, 0, 127, 10);
        gMain.subState = POKEDEX_STATE_5;
    }

}

void Pokedex_DetailViewInput(void)
{
    u16 var0;

    if (gPokedexDetailFrameCount < 0x51)
    {
        gPokedexDetailFrameCount++;
        if (gPokedexDetailFrameCount == 0x50)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        }
    }
    gPokedexPageIndicatorTimer++;
    if (0x1e < gPokedexPageIndicatorTimer)
    {
        gPokedexPageIndicatorTimer = 0;
        gPokedexPageIndicatorBlink = 1 - gPokedexPageIndicatorBlink;
    }
    gPokedexBlinkTimer = 0;

    if (JOY_NEW(DPAD_UP))
    {
        if ((gPokedexSelectedMon < BONUS_SPECIES_START) && (gPokedexDescriptionPage == 1))
        {
            m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
            gPokedexDescriptionPage = 0;
            PrintDexDescription(gPokedexSelectedMon, 0);
            gPokedexSpriteIndexBase = gPokedexDescriptionPage;
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if ((gPokedexSelectedMon < BONUS_SPECIES_START) && (gPokedexDescriptionPage == 0))
        {
            m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
            gPokedexDescriptionPage = 1;
            PrintDexDescription(gPokedexSelectedMon, 1);
            gPokedexSpriteIndexBase = gPokedexDescriptionPage;
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        if (gPokedexSelectedMon < BONUS_SPECIES_START)
        {
            if (!gPokedexDescriptionPage)
            {
                m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                gPokedexDescriptionPage = 1 - gPokedexDescriptionPage;
                PrintDexDescription(gPokedexSelectedMon, gPokedexDescriptionPage);
                gPokedexSpriteIndexBase = gPokedexDescriptionPage;
            }
            else
            {
                m4aSongNumStart(SE_MENU_POPUP_CLOSE);
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
                gPokedexDescriptionPage = 0;
                gPokedexDetailFrameCount = 0;
                gPokedexPageIndicatorTimer = gPokedexDetailFrameCount;
                gPokedexShowPageIndicator = 0;
                gMain.subState = POKEDEX_STATE_4;
            }
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_POPUP_CLOSE);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        gPokedexDescriptionPage = 0;
        gPokedexDetailFrameCount = 0;
        gPokedexPageIndicatorTimer = gPokedexDetailFrameCount;
        gPokedexShowPageIndicator = 0;
        gMain.subState = POKEDEX_STATE_4;
    }

    if (JOY_HELD(SELECT_BUTTON))
    {
        if (gPokedexFlags[gPokedexSelectedMon] == SPECIES_CAUGHT)
        {
            if (gDexAnimationIx[gPokedexSelectedMon] == -1)
            {
                gPokedexShowAnimSprite = 0;
                gPokedexShowPortrait = 1;
                gPokedexShowCatchHatch[0] = 0;
                gPokedexShowCatchHatch[1] = 0;
                gPokedexSpriteAnimTimer = 0;
                gPokedexSpriteAnimFrame = 0;
            }
            else
            {
                if (gDexAnimationIx[gPokedexSelectedMon] < 100)
                {
                    gPokedexShowAnimSprite = 0;
                    gPokedexShowPortrait = 0;
                    gPokedexShowCatchHatch[0] = 1;
                    gPokedexShowCatchHatch[1] = 0;
                }
                else
                {
                    gPokedexShowAnimSprite = 0;
                    gPokedexShowPortrait = 0;
                    gPokedexShowCatchHatch[0] = 0;
                    gPokedexShowCatchHatch[1] = 1;
                }
            }
        }
        else
        {
            gPokedexShowAnimSprite = 0;
            gPokedexShowPortrait = 1;
            gPokedexShowCatchHatch[0] = 0;
            gPokedexShowCatchHatch[1] = 0;
        }
    }
    else
    {
        if (CheckMonHasAnimation(gPokedexSelectedMon) == 1)
            gPokedexShowAnimSprite = 1;
        else
            gPokedexShowAnimSprite = 0;

        gPokedexShowPortrait = 1;
        gPokedexShowCatchHatch[0] = 0;
        gPokedexShowCatchHatch[1] = 0;
        gPokedexSpriteAnimTimer = 0;
        gPokedexSpriteAnimFrame = 0;
    }

    RenderPokedexSprites();
}

void Pokedex_InfoWindowSlideOut(void)
{
    s32 i;

    for (i = 0; i < 0x20; i++)
    {
        gPokedexVramBuffer[0x20 * (0x11 - gPokedexInfoWindowSlideStep) + i] = gDexInfoWindowBottomRowTiles[i];
        gPokedexVramBuffer[0x20 * (0x12 - gPokedexInfoWindowSlideStep) + i] = gDexInfoWindowEmptyRowTiles[i];
    }

    if (gPokedexInfoWindowSlideStep < 8)
    {
        for (i = 0; i < 0x20; i++)
        {
            gBG0TilemapBuffer[0x20 * (0x11 - gPokedexInfoWindowSlideStep) + i] = gPokedexInfoWindowBackupTiles[0x20 * (0x7 - gPokedexInfoWindowSlideStep) + i];
        }
    }
    gPokedexInfoWindowSlideStep++;

    gPokedexVramBuffer[0x134] = 0x59;
    DmaCopy16(3, gPokedexVramBuffer, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gBG0TilemapBuffer, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);

    if (gPokedexInfoWindowSlideStep > 8)
    {
        gPokedexInfoWindowSlideStep = 0;
        gPokedexShowAnimSprite = 0;
        gPokedexShowButtonPrompt = 1;

        DmaFill16(3, 0, (void *)gTempGfxBuffer, 0x1800);
        DmaFill16(3, 0, (void *)0x6005C00, 0x1800);
        gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;
    }
}

void Pokedex_LinkSetup(void)
{
    InitLinkHardware();
    InitLinkTransferState();
    gLinkExchangeStep = 0;
    RenderLinkGraphics();
    gMain.subState = POKEDEX_STATE_7;
}

void Pokedex_LinkTransferLoop(void)
{
    s16 var0;

    RenderLinkGraphics();

    if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gPokedexShowPopupWindow = 0;
        gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT;
        gPokedexShowButtonPrompt = 1;
        gPokedexShowAnimSprite = 1;
        ResetSerialAndInterrupts();
        gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;
    }
    else
    {
        gLinkStatusResult = LinkMain1(&gLinkAdvanceState, gLinkSendBuffer, gLinkRecvBuffer);
        gLinkConnectionState = gLinkStatusResult & 3;
        gLinkPlayerCount = (gLinkStatusResult & 0x1C) >> 2;
        gLinkNegotiationFlags = (gLinkStatusResult & 0xe00) >> 9;

        if ((gLinkStatusResult & 0x40) && (gLinkConnectionState < 2))
        {
            SendLinkPokedexData();

            if (!(gLinkStatusResult & 0x100))
            {
                var0 = Pokedex_ProcessLinkExchange();
                if (var0 == -1)
                {
                    gMain.subState = POKEDEX_STATE_9;
                }
                else if (var0 == 1)
                {
                    gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_ERROR;
                    gMain.subState = POKEDEX_STATE_8;
                    m4aSongNumStart(SE_FAILURE);
                }
            }

            gLinkExchangeFrameCounter++;

            if ((gLinkStatusResult & 0x7f0000) && gPokedexLinkTransferPhase == -1)
            {
                gLinkTimeoutCounter++;
                if (0xB4 < gLinkTimeoutCounter)
                {
                    gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_ERROR;
                    gMain.subState = POKEDEX_STATE_8;
                    m4aSongNumStart(SE_FAILURE);
                }
            }
        }
    }
}

void Pokedex_LinkRetryDelay(void)
{
    gLinkTimeoutCounter++;

    if (2 < gLinkTimeoutCounter) {
        gLinkTimeoutCounter = 0;
        gMain.subState = POKEDEX_STATE_LINK_SETUP;
    }
}

void Pokedex_LinkErrorTimeout(void)
{
    s32 iVar1;

    RenderLinkGraphics();
    gPokedexLinkStateTimer++;

    if (0x5A < gPokedexLinkStateTimer)
    {
        gPokedexLinkStateTimer = 0;
        gPokedexShowPopupWindow = 0;
        gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT;
        gPokedexShowButtonPrompt = 1;
        gPokedexShowAnimSprite = 1;

        ResetSerialAndInterrupts();
        DisableSerial();

        for(iVar1 = 0; iVar1 < 0xE1; iVar1++)
        {
            gPokedexFlagExchangeBuffer[iVar1] = gPokedexFlags[iVar1];
        }

        FadeOutScreen();
        m4aMPlayAllStop();
        DisableVBlankInterrupts();
        gMain.subState = POKEDEX_STATE_LOAD_GRAPHICS;
    }
}

void Pokedex_LinkSuccessSequence(void)
{
    s32 index;

    RenderLinkGraphics();
    switch(gPokedexLinkStateTimer)
    {
        case 0x4:
            ResetSerialAndInterrupts();
            DisableSerial();
            break;
        case 0x82:
            gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_COMPLETE;
            m4aSongNumStart(SE_MENU_SELECT);
            break;
        case 0xFA:
            gPokedexLinkStateTimer = 0;
            gPokedexShowPopupWindow = 0;
            gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT;
            gPokedexShowButtonPrompt = 1;
            gPokedexShowAnimSprite = 1;
            for(index = 0; index < 0xE1; index++)
            {
                gPokedexFlags[index] = gPokedexFlagExchangeBuffer[index];
            }
            for(index = 0; index < NUM_SPECIES; index++)
            {
                gMain_saveData.pokedexFlags[index] = gPokedexFlags[index];
            }
            SaveFile_WriteToSram();
            FadeOutScreen();
            m4aMPlayAllStop();
            DisableVBlankInterrupts();
            gMain.subState = POKEDEX_STATE_LOAD_GRAPHICS;
            break;
    }
    gPokedexLinkStateTimer++;
}

void Pokedex_DeleteConfirmation(void)
{
    s32 i;

    RenderPokedexSprites();

    if (JOY_NEW(A_BUTTON))
    {
        m4aSongNumStart(SE_MENU_SELECT);
        for (i = 0; i < 0xE1; i++)
        {
            gPokedexFlagExchangeBuffer[i] = 0;
            gPokedexFlags[i] = 0;
        }
        for (i = 0; i < NUM_SPECIES; i++)
        {
            gMain_saveData.pokedexFlags[i] = gPokedexFlags[i];
        }

        gPokedexShowPopupWindow = 0;
        gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT;
        gPokedexShowButtonPrompt = 1;
        gPokedexShowAnimSprite = 1;

        SaveFile_WriteToSram();
        FadeOutScreen();
        m4aMPlayAllStop();
        DisableVBlankInterrupts();
        gMain.subState = POKEDEX_STATE_LOAD_GRAPHICS;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gPokedexShowPopupWindow = 0;
        gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT;
        gPokedexShowButtonPrompt = 1;
        gPokedexShowAnimSprite = 1;
        gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;


    }
}

void Pokedex_ReturnToTitle(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();

    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(STATE_TITLE);
}

static void PokedexListScrollUp(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gPokedexSpriteAnimTimer = 0;
    gPokedexSpriteAnimFrame = 0;

    if (gPokedexCursorOffset == 0)
    {
        if (gPokedexListPosition == 0)
        {
            if (gPokedexScrollActive == 0)
            {
                gPokedexListPosition = gPokedexListEntryCount - NUM_BONUS_SPECIES - 1;
                gPokedexSelectedMon = gPokedexListEntryCount - 1;
                gPokedexCursorOffset = 4;
                m4aSongNumStart(SE_MENU_MOVE);
            }
        }
        else
        {
            gPokedexListPosition--;
            gPokedexSelectedMon--;
            m4aSongNumStart(SE_MENU_MOVE);
        }

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }
    else
    {
        m4aSongNumStart(SE_MENU_MOVE);
        gPokedexCursorOffset--;
        gPokedexSelectedMon--;

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }

    gPokedexScrollActive = 1;
}

static void PokedexListScrollDown(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gPokedexSpriteAnimTimer = 0;
    gPokedexSpriteAnimFrame = 0;
    if (gPokedexCursorOffset == 4)
    {
        if (gPokedexListPosition == gPokedexListEntryCount - NUM_BONUS_SPECIES - 1)
        {
            if (gPokedexScrollActive == 0)
            {
                gPokedexListPosition = 0;
                gPokedexSelectedMon = 0;
                gPokedexCursorOffset = 0;
                m4aSongNumStart(SE_MENU_MOVE);
            }
        }
        else
        {
            gPokedexListPosition++;
            gPokedexSelectedMon++;
            m4aSongNumStart(SE_MENU_MOVE);
        }

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }
    else
    {
        m4aSongNumStart(SE_MENU_MOVE);
        gPokedexCursorOffset++;
        gPokedexSelectedMon++;
        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }

    gPokedexScrollActive = 1;
}

static void PokedexListScrollUpFast(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gPokedexSpriteAnimTimer = 0;
    gPokedexSpriteAnimFrame = 0;
    if (gPokedexListPosition == 0)
        return;

    m4aSongNumStart(SE_MENU_MOVE);
    gPokedexListPosition -= ENTRIES_SHOWN_COUNT;
    if (gPokedexListPosition < 0)
        gPokedexListPosition = 0;

    gPokedexSelectedMon = gPokedexListPosition + gPokedexCursorOffset;
    gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
}

static void PokedexListScrollDownFast(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gPokedexSpriteAnimTimer = 0;
    gPokedexSpriteAnimFrame = 0;
    if (gPokedexListPosition == gPokedexListEntryCount - NUM_BONUS_SPECIES - 1)
        return;

    m4aSongNumStart(SE_MENU_MOVE);
    gPokedexListPosition += ENTRIES_SHOWN_COUNT;
    if (gPokedexListPosition > gPokedexListEntryCount - NUM_BONUS_SPECIES - 1)
        gPokedexListPosition = gPokedexListEntryCount - NUM_BONUS_SPECIES - 1;

    gPokedexSelectedMon = gPokedexListPosition + gPokedexCursorOffset;
    gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
}

void Pokedex_CheckDeleteKeyComboPressed(void)
{
     // To delete save file, press R_BUTTON 3 times while holding L_BUTTON And DPAD_LEFT.
    if (JOY_HELD(L_BUTTON | DPAD_LEFT) == (L_BUTTON | DPAD_LEFT) && JOY_NEW(R_BUTTON))
    {
        gPokedex_EraseSaveDataAccessCounter = 40;
        if (++gPokedex_EraseSaveDataAccessStep == 3)
        {
            gPokedex_EraseSaveDataAccessStep = 0;
            gPokedex_EraseSaveDataAccessCounter = 0;
            m4aSongNumStart(SE_MENU_POPUP_OPEN);
            gPokedexShowPopupWindow = 1;
            gPokedexPopupTypeIndex = POKEDEX_POPUP_DELETE_CONFIRMATION_PROMPT;
            gPokedexShowButtonPrompt = 0;
            gPokedexShowAnimSprite = 0;
            gMain.subState = POKEDEX_STATE_DELETE_CONFIRMATION;
        }
    }

    if (gPokedex_EraseSaveDataAccessCounter > 0)
    {
        if (--gPokedex_EraseSaveDataAccessCounter <= 0)
        {
            gPokedex_EraseSaveDataAccessCounter = 0;
            gPokedex_EraseSaveDataAccessStep = 0;
        }
    }
}

void UpdateMonSpriteVisibility(void)
{
    if (gPokedexFlags[gPokedexSelectedMon] == SPECIES_CAUGHT)
    {
        if (gDexAnimationIx[gPokedexSelectedMon] == -1)
        {
            gPokedexShowAnimSprite = 0;
            gPokedexShowPortrait = 1;
            gPokedexShowCatchHatch[0] = 0;
            gPokedexShowCatchHatch[1] = 0;
            gPokedexSpriteAnimTimer = 0;
            gPokedexSpriteAnimFrame = 0;
        }
        else if (gDexAnimationIx[gPokedexSelectedMon] < 100)
        {
            gPokedexShowAnimSprite = 0;
            gPokedexShowPortrait = 0;
            gPokedexShowCatchHatch[0] = 1;
            gPokedexShowCatchHatch[1] = 0;
        }
        else
        {
            gPokedexShowAnimSprite = 0;
            gPokedexShowPortrait = 0;
            gPokedexShowCatchHatch[0] = 0;
            gPokedexShowCatchHatch[1] = 1;
        }
    }
    else
    {
        gPokedexShowAnimSprite = 0;
        gPokedexShowPortrait = 1;
        gPokedexShowCatchHatch[0] = 0;
        gPokedexShowCatchHatch[1] = 0;
    }
}

u8 GetSelectedMonSpriteType(void)
{
    if (gPokedexFlags[gPokedexSelectedMon] == SPECIES_CAUGHT && gDexAnimationIx[gPokedexSelectedMon] != -1)
    {
        if (gDexAnimationIx[gPokedexSelectedMon] < 100)
            return 1;

        return 2;
    }

    return 0;
}

void RefreshPokedexListDisplay(void)
{
    PrintDexNumbersFromListPosition(gPokedexListPosition);
    PrintCaughtBallFromListPosition(gPokedexListPosition);
    PrintSelectedMonDexNum(gPokedexSelectedMon);
    LoadMonPortrait(gPokedexSelectedMon);
    LoadMonAnimationSprite(gPokedexSelectedMon);
    CheckMonHasAnimation(gPokedexSelectedMon);
    gPokedexAnimatedIconTimer = 0;
    gPokedexAnimatedIconFrame = 0;
}

void RefreshMonPreviewSprite(void)
{
    if (GetSelectedMonSpriteType() == 0)
        LoadMonPortrait(gPokedexSelectedMon);
    else
        LoadMonAnimationSprite(gPokedexSelectedMon);
}

void RenderPokedexSprites(void)
{
    int i;
    struct SpriteGroup *group0;
    struct SpriteGroup *group1;
    struct SpriteGroup *group2;
    struct SpriteGroup *group3;
    struct SpriteGroup *group4;
    struct SpriteGroup *group5;
    struct SpriteGroup *group6;
    struct SpriteGroup *group7;
    struct SpriteGroup *group8;
    struct SpriteGroup *group9;
    struct OamDataSimple *groupOam;
    const struct SpriteSet *spriteSet;
    int var0, var1;

    group0 = &gMain_spriteGroups[0];
    group1 = &gMain_spriteGroups[1];
    group2 = &gMain_spriteGroups[2];
    group3 = &gMain_spriteGroups[3];
    group4 = &gMain_spriteGroups[4];
    group5 = &gMain_spriteGroups[5 + gPokedexAnimatedIconFrame];
    group6 = &gMain_spriteGroups[17 + gPokedexPopupTypeIndex];
    group7 = &gMain_spriteGroups[22 + gPokedexButtonPromptFrame];
    group8 = &gMain_spriteGroups[24];
    group9 = &gMain_spriteGroups[25 + gPokedexSpriteIndexBase * 2 + gPokedexPageIndicatorBlink];

    group0->available = TRUE;
    group1->available = TRUE;
    group2->available = gPokedexShowPortrait;
    group3->available = gPokedexShowCatchHatch[0];
    group4->available = gPokedexShowCatchHatch[1];
    group5->available = gPokedexShowAnimSprite;
    group6->available = gPokedexShowPopupWindow;
    group7->available = gPokedexShowButtonPrompt;
    group8->available = gPokedexShowLinkCableIcon;
    group9->available = gPokedexShowPageIndicator;
    LoadSpriteSets(gPokedexSpriteSets, 29, group0);

    group0->baseX = 20 + gPokedexCursorBlinkOffset;
    group0->baseY = 84 + gPokedexCursorOffset * 16;
    groupOam = &group0->oam[0];
    gOamBuffer[groupOam->oamId].priority = 3;
    gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group0->baseX;
    gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group0->baseY;

    if (gPokedexSelectedMon < 200)
        gPokedexScrollbarY = 86 + gPokedexSelectedMon / 3;
    else
        gPokedexScrollbarY = 152;

    group1->baseX = 13;
    group1->baseY = gPokedexScrollbarY;
    groupOam = &group1->oam[0];
    gOamBuffer[groupOam->oamId].priority = 3;
    gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group1->baseX;
    gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group1->baseY;

    if (group2->available == 1)
    {
        group2->baseX = 36;
        group2->baseY = 36;
        for (i = 0; i < 6; i++)
        {
            groupOam = &group2->oam[i];
            gOamBuffer[groupOam->oamId].priority = 1;
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group2->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group2->baseY;
        }
    }

    if (group3->available == 1)
    {
        group3->baseX = 36;
        group3->baseY = 28;
        for (i = 0; i < 4; i++)
        {
            groupOam = &group3->oam[i];
            gOamBuffer[groupOam->oamId].priority = 1;
            gOamBuffer[groupOam->oamId].tileNum = gPokedexAnimBaseTileNums[gPokedexSpriteCategory][i] +
                                                  gPokedexCatchAnimTileOffsets[gPokedexSpriteCategory][gPokedexSpriteAnimFrame];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group3->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group3->baseY;
        }

        if (++gPokedexSpriteAnimTimer > 14)
        {
            gPokedexSpriteAnimTimer = 0;
            if (++gPokedexSpriteAnimFrame > 8)
                gPokedexSpriteAnimFrame = 0;
        }
    }

    if (group4->available == 1)
    {
        if (gPokedexCatchAnimIndices[gPokedexSelectedMon] == -1)
        {
            var0 = 1;
            var1 = 36;
        }
        else
        {
            var0 = 2;
            var1 = 48;
        }

        group4->baseX = 48;
        group4->baseY = 40;
        for (i = 0; i < 4; i++)
        {
            groupOam = &group4->oam[i];
            gOamBuffer[groupOam->oamId].priority = 1;
            gOamBuffer[groupOam->oamId].tileNum = gPokedexAnimBaseTileNums[var0][i] + gPokedexHatchAnimTileOffsets[var0][gPokedexSpriteAnimFrame];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group4->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group4->baseY;
        }

        if (++gPokedexSpriteAnimTimer > gPokedexAnimFrameDurations[var0][gPokedexSpriteAnimFrame])
        {
            gPokedexSpriteAnimTimer = 0;
            if (++gPokedexSpriteAnimFrame > var1)
                gPokedexSpriteAnimFrame = 0;
        }
    }

    if (group5->available == 1)
    {
        group5->baseX = 36;
        group5->baseY = 64;
        spriteSet = gPokedexSpriteSets[5 + gPokedexAnimatedIconFrame];
        for (i = 0; i < spriteSet->count; i++)
        {
            groupOam = &group5->oam[i];
            gOamBuffer[groupOam->oamId].priority = 1;
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group5->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group5->baseY;
        }

        if (++gPokedexAnimatedIconTimer > 8)
        {
            gPokedexAnimatedIconTimer = 0;
            if (++gPokedexAnimatedIconFrame > 11)
                gPokedexAnimatedIconFrame = 0;
        }
    }

    if (group6->available == 1)
    {
        if (gPokedexPopupTypeIndex == POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT ||
            gPokedexPopupTypeIndex == POKEDEX_POPUP_DELETE_CONFIRMATION_PROMPT)
        {
            group6->baseX = 120;
            group6->baseY = 100;
        }
        else
        {
            group6->baseX = 120;
            group6->baseY = 80;
        }

        spriteSet = gPokedexSpriteSets[17 + gPokedexPopupTypeIndex];
        for (i = 0; i < spriteSet->count; i++)
        {
            groupOam = &group6->oam[i];
            gOamBuffer[groupOam->oamId].priority = 0;
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group6->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group6->baseY;
        }
    }

    if (group7->available == 1)
    {
        group7->baseX = 158;
        group7->baseY = 148;
        spriteSet = gPokedexSpriteSets[22 + gPokedexButtonPromptFrame];
        for (i = 0; i < spriteSet->count; i++)
        {
            groupOam = &group7->oam[i];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group7->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group7->baseY;
        }
    }

    if (group8->available == 1)
    {
        group8->baseX = 168;
        group8->baseY = 84;
        for (i = 0; i < 3; i++)
        {
            groupOam = &group8->oam[i];
            gOamBuffer[groupOam->oamId].priority = 3;
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group8->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group8->baseY;
        }
    }

    if (group9->available == 1)
    {
        group9->baseX = 120;
        group9->baseY = 132;
        groupOam = &group9->oam[0];
        gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group9->baseX;
        gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group9->baseY;
    }

    if (++gPokedexBlinkTimer > 12)
    {
        gPokedexBlinkTimer = 0;
        gPokedexCursorBlinkOffset = 1 - gPokedexCursorBlinkOffset;
        gPokedexButtonPromptFrame = 1 - gPokedexButtonPromptFrame;
    }

    group5->available = FALSE;
    group6->available = FALSE;
    group7->available = FALSE;
    group9->available = FALSE;
}

static void RenderLinkGraphics(void)
{
    int i;
    struct SpriteGroup *group0;
    struct SpriteGroup *group1;
    struct SpriteGroup *group2;
    struct SpriteGroup *group3;
    struct SpriteGroup *group4;
    struct SpriteGroup *group5;
    struct SpriteGroup *group6;
    struct SpriteGroup *group7;
    struct OamDataSimple *groupOam;
    const struct SpriteSet *spriteSet;

    group0 = &gMain_spriteGroups[0];
    group1 = &gMain_spriteGroups[1];
    group2 = &gMain_spriteGroups[2];
    group3 = &gMain_spriteGroups[3];
    group4 = &gMain_spriteGroups[4];
    group6 = &gMain_spriteGroups[5 + gPokedexAnimatedIconFrame];
    group7 = &gMain_spriteGroups[17 + gPokedexPopupTypeIndex];
    group5 = &gMain_spriteGroups[24];

    group0->available = TRUE;
    group1->available = TRUE;
    group2->available = gPokedexShowPortrait;
    group3->available = gPokedexShowCatchHatch[0];
    group4->available = gPokedexShowCatchHatch[1];
    group6->available = FALSE;
    group7->available = gPokedexShowPopupWindow;
    group5->available = gPokedexShowLinkCableIcon;
    LoadSpriteSetsWithCpuCopy(gPokedexSpriteSets, 29, group0);

    group0->baseX = 20 + gPokedexCursorBlinkOffset;
    group0->baseY = 84 + gPokedexCursorOffset * 16;
    groupOam = &group0->oam[0];
    gOamBuffer[groupOam->oamId].priority = 2;
    gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group0->baseX;
    gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group0->baseY;

    gPokedexScrollbarY = 86 + gPokedexSelectedMon / 3;
    group1->baseX = 13;
    group1->baseY = gPokedexScrollbarY;
    groupOam = &group1->oam[0];
    gOamBuffer[groupOam->oamId].priority = 2;
    gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group1->baseX;
    gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group1->baseY;

    if (group2->available == 1)
    {
        group2->baseX = 36;
        group2->baseY = 36;
        for (i = 0; i < 6; i++)
        {
            groupOam = &group2->oam[i];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group2->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group2->baseY;
        }
    }

    if (group3->available == 1)
    {
        group3->baseX = 36;
        group3->baseY = 28;
        for (i = 0; i < 4; i++)
        {
            groupOam = &group3->oam[i];
            gOamBuffer[groupOam->oamId].tileNum = gPokedexAnimBaseTileNums[gPokedexSpriteCategory][i] +
                                                  gPokedexCatchAnimTileOffsets[gPokedexSpriteCategory][gPokedexSpriteAnimFrame];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group3->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group3->baseY;
        }
    }

    if (group4->available == 1)
    {
        group4->baseX = 48;
        group4->baseY = 40;
        for (i = 0; i < 4; i++)
        {
            groupOam = &group4->oam[i];
            gOamBuffer[groupOam->oamId].tileNum = gPokedexAnimBaseTileNums[1][i] +
                                                  gPokedexAnimTileDeltas[1][gPokedexSpriteAnimFrame];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group4->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group4->baseY;
        }
    }

    if (group6->available == 1)
    {
        group6->baseX = 36;
        group6->baseY = 64;
        spriteSet = gPokedexSpriteSets[5 + gPokedexAnimatedIconFrame];
        for (i = 0; i < spriteSet->count; i++)
        {
            groupOam = &group6->oam[i];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group6->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group6->baseY;
        }
    }

    if (group7->available == 1)
    {
        if (gPokedexPopupTypeIndex == POKEDEX_POPUP_TRANSMISSION_CONNECT_PROMPT ||
            gPokedexPopupTypeIndex == POKEDEX_POPUP_DELETE_CONFIRMATION_PROMPT)
        {
            group7->baseX = 120;
            group7->baseY = 100;
        }
        else
        {
            group7->baseX = 120;
            group7->baseY = 80;
        }

        spriteSet = gPokedexSpriteSets[17 + gPokedexPopupTypeIndex];
        for (i = 0; i < spriteSet->count; i++)
        {
            groupOam = &group7->oam[i];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group7->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group7->baseY;
        }
    }

    if (group5->available == 1)
    {
        group5->baseX = 168;
        group5->baseY = 84;
        for (i = 0; i < 3; i++)
        {
            groupOam = &group5->oam[i];
            gOamBuffer[groupOam->oamId].priority = 3;
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group5->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group5->baseY;
        }
    }

    group7->available = FALSE;
}

static void InitLinkTransferState(void)
{
    gLinkSendBuffer[0] = 0xDDDD;
    gPokedexLinkChunkIndex = 1;
    gPokedexLinkSendCounter = 1;
    gPokedexLinkTransferPhase = 0;
    gPokedexMasterHandshakeState = 0;
    gPokedexClientHandshakeState = 0;
    gPokedexHandshakeRetryCount = 0;
}

static s16 Pokedex_ProcessLinkExchange(void)
{
    s16 result;

    if (gLink.isMaster)
        result = MasterReceivePokedexFlags();
    else
        result = ClientReceivePokedexFlags();

    return result;
}

s16 SendLinkPokedexData(void)
{
    s16 result;

    if (gLink.isMaster)
        result = MasterSendPokedexFlags();
    else
        result = ClientSendPokedexFlags();

    return result;
}

static int MasterSendPokedexFlags(void)
{
    int i;
    u16 var0;

    if (gPokedexLinkTransferPhase == 0)
    {
        switch (gPokedexMasterHandshakeState)
        {
            case 0:
                if (JOY_NEW(A_BUTTON))
                {
                    gLinkSendBuffer[0] = 0xFEFE;
                }
                else
                {
                    for (i = 0; i < 8; i++)
                        gLinkSendBuffer[i] = 0;
                }
                return 0;
            case 1:
                gLinkSendBuffer[0] = 0xECEC;
                return 0;
        }
        return 0;
    }
    else if (gPokedexLinkSendCounter < 8)
    {
        for (i = 0; i < 8; i++)
            gLinkSendBuffer[i] = 0xDDDD;
    }
    else if (gPokedexLinkSendCounter < 16)
    {
        var0 = (gPokedexLinkSendCounter - 8) * 28;
        gLinkSendBuffer[0] = gPokedexLinkSendCounter;
        gLinkSendBuffer[1] = gPokedexFlags[var0] |
                               (gPokedexFlags[var0 + 1] << 4) |
                               (gPokedexFlags[var0 + 2] << 8) |
                               (gPokedexFlags[var0 + 3] << 12);
        gLinkSendBuffer[2] =  gPokedexFlags[var0 + 4] |
                               (gPokedexFlags[var0 + 5] << 4) |
                               (gPokedexFlags[var0 + 6] << 8) |
                               (gPokedexFlags[var0 + 7] << 12);
        gLinkSendBuffer[3] =  gPokedexFlags[var0 + 8] |
                               (gPokedexFlags[var0 + 9] << 4) |
                               (gPokedexFlags[var0 + 10] << 8) |
                               (gPokedexFlags[var0 + 11] << 12);
        gLinkSendBuffer[4] =  gPokedexFlags[var0 + 12] |
                               (gPokedexFlags[var0 + 13] << 4) |
                               (gPokedexFlags[var0 + 14] << 8) |
                               (gPokedexFlags[var0 + 15] << 12);
        gLinkSendBuffer[5] =  gPokedexFlags[var0 + 16] |
                               (gPokedexFlags[var0 + 17] << 4) |
                               (gPokedexFlags[var0 + 18] << 8) |
                               (gPokedexFlags[var0 + 19] << 12);
        gLinkSendBuffer[6] =  gPokedexFlags[var0 + 20] |
                               (gPokedexFlags[var0 + 21] << 4) |
                               (gPokedexFlags[var0 + 22] << 8) |
                               (gPokedexFlags[var0 + 23] << 12);
        gLinkSendBuffer[7] =  gPokedexFlags[var0 + 24] |
                               (gPokedexFlags[var0 + 25] << 4) |
                               (gPokedexFlags[var0 + 26] << 8) |
                               (gPokedexFlags[var0 + 27] << 12);
    }
    else
    {
        for (i = 0; i < 8; i++)
            gLinkSendBuffer[i] = 0;
    }

    gPokedexLinkSendCounter++;
    return 0;
}

static int ClientSendPokedexFlags(void)
{
    int i;
    u16 var0;

    if (gPokedexLinkTransferPhase == 0)
    {
        switch (gPokedexClientHandshakeState)
        {
            case 0:
                if (JOY_NEW(A_BUTTON))
                {
                    gLinkSendBuffer[0] = 0xFEFE;
                }
                else
                {
                    for (i = 0; i < 8; i++)
                        gLinkSendBuffer[i] = 0;
                }
                return 0;
            case 1:
                gLinkSendBuffer[0] = 0xECEC;
                return 0;
        }
        return 0;
    }
    else if (gPokedexLinkSendCounter < 8)
    {
        for (i = 0; i < 8; i++)
            gLinkSendBuffer[i] = 0xDDDD;
    }
    else if (gPokedexLinkSendCounter < 16)
    {
        var0 = (gPokedexLinkSendCounter - 8) * 28;
        gLinkSendBuffer[0] = gPokedexLinkSendCounter;
        gLinkSendBuffer[1] = gPokedexFlags[var0] |
                               (gPokedexFlags[var0 + 1] << 4) |
                               (gPokedexFlags[var0 + 2] << 8) |
                               (gPokedexFlags[var0 + 3] << 12);
        gLinkSendBuffer[2] =  gPokedexFlags[var0 + 4] |
                               (gPokedexFlags[var0 + 5] << 4) |
                               (gPokedexFlags[var0 + 6] << 8) |
                               (gPokedexFlags[var0 + 7] << 12);
        gLinkSendBuffer[3] =  gPokedexFlags[var0 + 8] |
                               (gPokedexFlags[var0 + 9] << 4) |
                               (gPokedexFlags[var0 + 10] << 8) |
                               (gPokedexFlags[var0 + 11] << 12);
        gLinkSendBuffer[4] =  gPokedexFlags[var0 + 12] |
                               (gPokedexFlags[var0 + 13] << 4) |
                               (gPokedexFlags[var0 + 14] << 8) |
                               (gPokedexFlags[var0 + 15] << 12);
        gLinkSendBuffer[5] =  gPokedexFlags[var0 + 16] |
                               (gPokedexFlags[var0 + 17] << 4) |
                               (gPokedexFlags[var0 + 18] << 8) |
                               (gPokedexFlags[var0 + 19] << 12);
        gLinkSendBuffer[6] =  gPokedexFlags[var0 + 20] |
                               (gPokedexFlags[var0 + 21] << 4) |
                               (gPokedexFlags[var0 + 22] << 8) |
                               (gPokedexFlags[var0 + 23] << 12);
        gLinkSendBuffer[7] =  gPokedexFlags[var0 + 24] |
                               (gPokedexFlags[var0 + 25] << 4) |
                               (gPokedexFlags[var0 + 26] << 8) |
                               (gPokedexFlags[var0 + 27] << 12);
    }
    else
    {
        for (i = 0; i < 8; i++)
            gLinkSendBuffer[i] = 0;
    }

    gPokedexLinkSendCounter++;
    return 0;
}

//Link transfer as host (See ClientReceivePokedexFlags for client)
int MasterReceivePokedexFlags(void)
{
    int i, j;
    u16 var0;
    u16 arr0[28];

    if (gPokedexLinkTransferPhase == 0)
    {
        switch (gPokedexMasterHandshakeState)
        {
            case 0:
                if (gLinkRecvBuffer[0][0] == 0xFEFE || gLinkRecvBuffer[0][1] == 0xFEFE)
                {
                    gPokedexMasterHandshakeState = 1;
                }
                break;
            case 1:
                if (gLinkRecvBuffer[0][0] == 0xECEC && gLinkRecvBuffer[0][1] == 0xECEC)
                {
                    gPokedexLinkTransferPhase = -1;
                    gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMITTING_ACTIVE;
                    gPokedexLinkSendCounter = 1;
                }
                else if (++gPokedexHandshakeRetryCount > 10)
                {
                    return 1;
                }
                break;
        }
    }
    else
    {
        u16 var1 = gLinkRecvBuffer[0][1] - 8;
         if (var1 > 7)
            return 0;

        gPokedexLinkChunkIndex = gLinkRecvBuffer[0][1];
        arr0[0]  =  gLinkRecvBuffer[0][3]  & 0xF;
        arr0[1]  = (gLinkRecvBuffer[0][3]  & 0xF0)   >> 4;
        arr0[2]  = (gLinkRecvBuffer[0][3]  & 0xF00)  >> 8;
        arr0[3]  = (gLinkRecvBuffer[0][3]  & 0xF000) >> 12;
        arr0[4]  =  gLinkRecvBuffer[0][5]  & 0xF;
        arr0[5]  = (gLinkRecvBuffer[0][5]  & 0xF0)   >> 4;
        arr0[6]  = (gLinkRecvBuffer[0][5]  & 0xF00)  >> 8;
        arr0[7]  = (gLinkRecvBuffer[0][5]  & 0xF000) >> 12;
        arr0[8]  =  gLinkRecvBuffer[0][7]  & 0xF;
        arr0[9]  = (gLinkRecvBuffer[0][7]  & 0xF0)   >> 4;
        arr0[10] = (gLinkRecvBuffer[0][7]  & 0xF00)  >> 8;
        arr0[11] = (gLinkRecvBuffer[0][7]  & 0xF000) >> 12;
        arr0[12] =  gLinkRecvBuffer[0][9]  & 0xF;
        arr0[13] = (gLinkRecvBuffer[0][9]  & 0xF0)   >> 4;
        arr0[14] = (gLinkRecvBuffer[0][9]  & 0xF00)  >> 8;
        arr0[15] = (gLinkRecvBuffer[0][9]  & 0xF000) >> 12;
        arr0[16] =  gLinkRecvBuffer[0][11] & 0xF;
        arr0[17] = (gLinkRecvBuffer[0][11] & 0xF0)   >> 4;
        arr0[18] = (gLinkRecvBuffer[0][11] & 0xF00)  >> 8;
        arr0[19] = (gLinkRecvBuffer[0][11] & 0xF000) >> 12;
        arr0[20] =  gLinkRecvBuffer[0][13] & 0xF;
        arr0[21] = (gLinkRecvBuffer[0][13] & 0xF0)   >> 4;
        arr0[22] = (gLinkRecvBuffer[0][13] & 0xF00)  >> 8;
        arr0[23] = (gLinkRecvBuffer[0][13] & 0xF000) >> 12;
        arr0[24] =  gLinkRecvBuffer[0][15] & 0xF;
        arr0[25] = (gLinkRecvBuffer[0][15] & 0xF0)   >> 4;
        arr0[26] = (gLinkRecvBuffer[0][15] & 0xF00)  >> 8;
        arr0[27] = (gLinkRecvBuffer[0][15] & 0xF000) >> 12;

        for (i = 0; i < 28; i++)
        {
            var0 = (gPokedexLinkChunkIndex - 8) * 28 + i;
            if (gPokedexFlags[var0] == SPECIES_UNSEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED;
            else if (gPokedexFlags[var0] == SPECIES_SEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED_AND_SEEN;
        }

        if (gPokedexLinkChunkIndex == 15)
            return -1;
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 2; j++)
            gLinkRecvBuffer[i][j] = 0;
    }

    return 0;
}

//Link transfer as client (See MasterReceivePokedexFlags for host)
static int ClientReceivePokedexFlags(void)
{
    int i, j;
    u16 var0;
    u16 arr0[28];

    if (gPokedexLinkTransferPhase == 0)
    {
        switch (gPokedexClientHandshakeState)
        {
            case 0:
                if (gLinkRecvBuffer[0][0] == 0xFEFE || gLinkRecvBuffer[0][1] == 0xFEFE)
                {
                    gPokedexClientHandshakeState = 1;
                }
                break;
            case 1:
                if (gLinkRecvBuffer[0][0] == 0xECEC && gLinkRecvBuffer[0][1] == 0xECEC)
                {
                    gPokedexLinkTransferPhase = -1;
                    gPokedexPopupTypeIndex = POKEDEX_POPUP_TRANSMITTING_ACTIVE;
                    gPokedexLinkSendCounter = 1;
                }
                else if (++gPokedexHandshakeRetryCount > 10)
                {
                    return 1;
                }
                break;
        }
    }
    else
    {
        u16 var1 = gLinkRecvBuffer[0][0] - 8;
         if (var1 > 7)
            return 0;

        gPokedexLinkChunkIndex = gLinkRecvBuffer[0][0];
        arr0[0]  =  gLinkRecvBuffer[0][2]  & 0xF;
        arr0[1]  = (gLinkRecvBuffer[0][2]  & 0xF0)   >> 4;
        arr0[2]  = (gLinkRecvBuffer[0][2]  & 0xF00)  >> 8;
        arr0[3]  = (gLinkRecvBuffer[0][2]  & 0xF000) >> 12;
        arr0[4]  =  gLinkRecvBuffer[0][4]  & 0xF;
        arr0[5]  = (gLinkRecvBuffer[0][4]  & 0xF0)   >> 4;
        arr0[6]  = (gLinkRecvBuffer[0][4]  & 0xF00)  >> 8;
        arr0[7]  = (gLinkRecvBuffer[0][4]  & 0xF000) >> 12;
        arr0[8]  =  gLinkRecvBuffer[0][6]  & 0xF;
        arr0[9]  = (gLinkRecvBuffer[0][6]  & 0xF0)   >> 4;
        arr0[10] = (gLinkRecvBuffer[0][6]  & 0xF00)  >> 8;
        arr0[11] = (gLinkRecvBuffer[0][6]  & 0xF000) >> 12;
        arr0[12] =  gLinkRecvBuffer[0][8]  & 0xF;
        arr0[13] = (gLinkRecvBuffer[0][8]  & 0xF0)   >> 4;
        arr0[14] = (gLinkRecvBuffer[0][8]  & 0xF00)  >> 8;
        arr0[15] = (gLinkRecvBuffer[0][8]  & 0xF000) >> 12;
        arr0[16] =  gLinkRecvBuffer[0][10] & 0xF;
        arr0[17] = (gLinkRecvBuffer[0][10] & 0xF0)   >> 4;
        arr0[18] = (gLinkRecvBuffer[0][10] & 0xF00)  >> 8;
        arr0[19] = (gLinkRecvBuffer[0][10] & 0xF000) >> 12;
        arr0[20] =  gLinkRecvBuffer[0][12] & 0xF;
        arr0[21] = (gLinkRecvBuffer[0][12] & 0xF0)   >> 4;
        arr0[22] = (gLinkRecvBuffer[0][12] & 0xF00)  >> 8;
        arr0[23] = (gLinkRecvBuffer[0][12] & 0xF000) >> 12;
        arr0[24] =  gLinkRecvBuffer[0][14] & 0xF;
        arr0[25] = (gLinkRecvBuffer[0][14] & 0xF0)   >> 4;
        arr0[26] = (gLinkRecvBuffer[0][14] & 0xF00)  >> 8;
        arr0[27] = (gLinkRecvBuffer[0][14] & 0xF000) >> 12;

        for (i = 0; i < 28; i++)
        {
            var0 = (gPokedexLinkChunkIndex - 8) * 28 + i;
            if (gPokedexFlags[var0] == SPECIES_UNSEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED;
            else if (gPokedexFlags[var0] == SPECIES_SEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED_AND_SEEN;
        }

        if (gPokedexLinkChunkIndex == 15)
            return -1;
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 2; j++)
            gLinkRecvBuffer[i][j] = 0;
    }

    return 0;
}

static void PrintSelectedMonDexNum(s16 species)
{
    int i;
    int var0;
    u16 var1;
    u16 var2;

    DmaFill16(3, 0, gTempGfxBuffer, 0x800);
    var0 = 0;
    if (species == SPECIES_JIRACHI)
    {
        if (gPokedexFlags[SPECIES_JIRACHI] != SPECIES_UNSEEN)
        {
            PrintString(CHAR_2_FONT_1, 1, 5, 2, 1, 2);
            PrintString(CHAR_0_FONT_1, 1, 6, 2, 1, 2);
            PrintString(CHAR_1_FONT_1, 1, 7, 2, 1, 2);
        }
        else
        {
            PrintString(CHAR_SPACE_FONT_1, 1, 5, 2, 1, 2);
            PrintString(CHAR_SPACE_FONT_1, 1, 6, 2, 1, 2);
            PrintString(CHAR_SPACE_FONT_1, 1, 7, 2, 1, 2);
        }
    }
    else
    {
        // Dex number of the selected species
        for (i = 0; i < DEX_NUM_DIGITS; i++)
            PrintString(gPokedexEntries[species].dexNum[i] + 32, 1, i + 5, 2, 1, 2);
    }

    if (gPokedexFlags[species] > SPECIES_UNSEEN)
    {
        for (i = 0; i < POKEMON_NAME_LENGTH; i++)
        {
            var1 = gPokedexEntries[species].name[i] & ~0xF;
            var2 = gPokedexEntries[species].name[i] & 0xF;
            if (var2 == 0)
                var2 = 4;

            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gGlyphUpperRowBuffer, 0x20);
            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1 + 0x400], gGlyphLowerRowBuffer, 0x20);
            BlitGlyphToTileBuffer(var2, var0, 0);
            var0 += var2;
        }

        CopyBgTilesRect(gTempGfxBuffer, (void *)0x06004C00, 8, 2);
        DmaFill16(3, 0, gTempGfxBuffer, 0x800);
        var0 = 0;
    }
    else
    {
        for (i = 0; i < 10; i++)
            CopyBgTilesRect((void *)&gPokedexTextGlyphs_Gfx[ENGLISH_GLYPHS_START], (void *)0x06004C00 + i * 0x20, 1, 2);
    }

    if (gPokedexFlags[species] == SPECIES_SEEN || gPokedexFlags[species] > SPECIES_SHARED)
    {
        for (i = 0; i < POKEMON_CATEGORY_NAME_LENGTH; i++)
        {
            var1 = gPokedexEntries[species].category[i] & ~0xF;
            var2 = gPokedexEntries[species].category[i] & 0xF;
            if (var2 == 0)
                var2 = 6;

            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gGlyphUpperRowBuffer, 0x20);
            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[0x400 + var1], gGlyphLowerRowBuffer, 0x20);
            BlitGlyphToTileBuffer(var2, var0, 0);
            var0 += var2;
        }

        CopyBgTilesRect(gTempGfxBuffer, (void *)0x06004D00, 9, 2);
        DmaFill16(3, 0, gTempGfxBuffer, 0x800);
    }
    else
    {
        for (i = 0; i < 9; i++)
            CopyBgTilesRect((void *)&gPokedexTextGlyphs_Gfx[ENGLISH_GLYPHS_START], (void *)0x06004D00 + i * 0x20, 1, 2);
    }

    if (gPokedexFlags[species] == SPECIES_CAUGHT)
    {
        PrintString(gPokedexEntries[species].heightWeight[0] + 32, 1, 16, 6, 1, 2);
        PrintString(gPokedexEntries[species].heightWeight[1] + 32, 1, 17, 6, 1, 2);
        PrintString(gPokedexEntries[species].heightWeight[2] + 32, 1, 19, 6, 1, 2);
        PrintString(gPokedexEntries[species].heightWeight[3] + 32, 1, 20, 6, 1, 2);
        for (i = 0; i < POKEMON_HEIGHT_WEIGHT_TEXT_LENGTH - 4; i++)
            PrintString(gPokedexEntries[species].heightWeight[4 + i], 1, i + 16, 8, 1, 1);
    }
    else
    {
        PrintString(CHAR_DASH_FONT_1, 1, 16, 6, 1, 2);
        PrintString(CHAR_DASH_FONT_1, 1, 17, 6, 1, 2);
        PrintString(CHAR_DASH_FONT_1, 1, 19, 6, 1, 2);
        PrintString(CHAR_DASH_FONT_1, 1, 20, 6, 1, 2);
        for (i = 0; i < POKEMON_HEIGHT_WEIGHT_TEXT_LENGTH - 4; i++)
            PrintString(CHAR_DASH_FONT_0, 1, i + 16, 8, 1, 1);
    }
}

static void PrintSeenOwnedTotals(s16 seen, s16 owned)
{
    int i;
    int temp;
    int seenDigits[DEX_NUM_DIGITS];
    int ownedDigits[DEX_NUM_DIGITS];

    temp = seen;
    seenDigits[0] = temp / 100;
    temp %= 100;
    seenDigits[1] = temp / 10;
    seenDigits[2] = temp % 10;

    temp = owned;
    ownedDigits[0] = temp / 100;
    temp %= 100;
    ownedDigits[1] = temp / 10;
    ownedDigits[2] = temp % 10;

    for (i = 0; i < DEX_NUM_DIGITS; i++)
    {
        PrintString(seenDigits[i], 2, i + 25, 15, 1, 1);
        PrintString(ownedDigits[i] + 32, 2, i + 25, 16, 1, 2);
    }
}

void PrintDexNumbersFromListPosition(s16 listPosition)
{
    int i, j;
    int var0;
    u16 var1;
    u16 var2;

    DmaFill16(3, 0, gTempGfxBuffer, 0x800);
    var0 = 0;
    for (i = 0; i < ENTRIES_SHOWN_COUNT; i++)
    {
        if (listPosition + i == SPECIES_JIRACHI)
        {
            if (gPokedexFlags[SPECIES_JIRACHI] != SPECIES_UNSEEN)
            {
                PrintString(CHAR_2_FONT_1, 2, 8, i * 2 + 10, 1, 2);
                PrintString(CHAR_0_FONT_1, 2, 9, i * 2 + 10, 1, 2);
                PrintString(CHAR_1_FONT_1, 2, 10, i * 2 + 10, 1, 2);
            }
            else
            {
                PrintString(CHAR_SPACE_FONT_1, 2, 8, i * 2 + 10, 1, 2);
                PrintString(CHAR_SPACE_FONT_1, 2, 9, i * 2 + 10, 1, 2);
                PrintString(CHAR_SPACE_FONT_1, 2, 10, i * 2 + 10, 1, 2);
            }
        }
        else
        {
            // Doesn't use listPosition for some reason, despite being the only value passed
            for (j = 0; j < DEX_NUM_DIGITS; j++)
                PrintString(gPokedexEntries[gPokedexListPosition + i].dexNum[j] + 32, 2, j + 8, i * 2 + 10, 1, 2);
        }
    }

    for (i = 0; i < ENTRIES_SHOWN_COUNT; i++)
    {
        if (gPokedexFlags[listPosition + i] > SPECIES_UNSEEN)
        {
			//This manually builds the tiles needed, for kerning reasons.
			//First 3 bytes point to a tile glyph pair (with an upper and lower half) and
			//the 4th byte is the width needed for that glyph, with the 'space between' included.
			//The 'space' character is 4 px wide.
            for (j = 0; j < POKEMON_NAME_LENGTH; j++)
            {
                // These don't use listPosition for some reason, despite being the only value passed
                var1 = gPokedexEntries[gPokedexListPosition + i].name[j] & ~0xF;
                var2 = gPokedexEntries[gPokedexListPosition + i].name[j] & 0xF;
                if (var2 == 0)
                    var2 = 4;

                DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gGlyphUpperRowBuffer, 0x20);
                DmaCopy16(3, &gPokedexTextGlyphs_Gfx[0x400 + var1], gGlyphLowerRowBuffer, 0x20);
                BlitGlyphToTileBuffer(var2, var0, 0);
                var0 += var2;
            }

            CopyBgTilesRect(gTempGfxBuffer, (void *)0x06000000 + gPokedexListNameVramOffsets[i], 8, 2);
            DmaFill16(3, 0, gTempGfxBuffer, 0x800);
            var0 = 0;
        }
        else
        {
            for (j = 0; j < 7; j++)
                CopyBgTilesRect((void *)&gPokedexTextGlyphs_Gfx[ENGLISH_GLYPHS_START], (void *)0x06000000 + gPokedexListNameVramOffsets[i] + j * 0x20, 1, 2);

            CopyBgTilesRect((void *)gPokedexTextGlyphs_Gfx, (void *)0x06000000 + gPokedexListNameVramOffsets[i] + j * 0x20, 1, 2);
        }
    }
}

static void PrintCaughtBallFromListPosition(s16 position)
{
    int i;
    int var0;

    for (i = 0; i < ENTRIES_SHOWN_COUNT; i++)
    {
        var0 = gPokedexFlags[position + i] == SPECIES_CAUGHT ? CHAR_BALL_CAUGHT : CHAR_BALL_NOT_CAUGHT;
        PrintString(var0, 1, 4, 10 + i * 2, 2, 2);
    }
}

void LoadMonPortrait(s16 species)
{
    s16 state = gPokedexFlags[gPokedexSelectedMon];
    s16 var1 = species / 15;
    s16 var2 = species % 15;
    switch (state)
    {
        case SPECIES_UNSEEN:
            CopyBgTilesRect(gPokedexSprites_Gfx + 0x5C00, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gPokedexSprites_Pals, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
        case SPECIES_SEEN:
            CopyBgTilesRect(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gMonPortraitGroupPals[0] + 0x1E0, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
        case SPECIES_SHARED:
        case SPECIES_SHARED_AND_SEEN:
            CopyBgTilesRect(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            DarkenPalette(gMonPortraitGroupPals[var1] + var2 * 0x20, (void *)OBJ_PLTT + 0x20, 0x20, 0xE);
            break;
        case SPECIES_CAUGHT:
            CopyBgTilesRect(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gMonPortraitGroupPals[var1] + var2 * 0x20, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
    }
}

void PrintDexDescription(s16 species, u32 page)
{
    int i, j;
    int var0;
    u16 var1;
    u16 var2;

    var0 = 0;
    DmaFill16(3, 0, gTempGfxBuffer, 0x1800);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 42; j++)
        {
            var1 = gPokedexEntries[species].description[page * 126 + i * 42 + j] & ~0xF;
            var2 = gPokedexEntries[species].description[page * 126 + i * 42 + j] & 0xF;
            if (var2 == 0)
                var2 = 4;

            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gGlyphUpperRowBuffer, 0x20);
            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[0x400 + var1], gGlyphLowerRowBuffer, 0x20);
            BlitGlyphToTileBuffer(var2, var0, i);
            var0 += var2;
        }

        var0 = 0;
    }

    DmaCopy16(3, gTempGfxBuffer, (void *)VRAM + 0x5C00, 0x1800);
}

void BlitGlyphToTileBuffer(s32 arg0, s32 arg1, s32 arg2) {
    int i;
    s32 temp_r2;

    temp_r2 = ((arg1 / 8) * 0x10) + (arg2 * 0x400);

    switch (arg0) {
    case 6:
        switch (arg1 % 8) {
        case 0:
            for(i = 0; i < 8; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= gGlyphUpperRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= gGlyphUpperRowBuffer[i * 2 + 1] & 0xFF;
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2 + 1] & 0xFF;
            }
            return;
        case 1:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xFF) << 4);
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xFF) << 4);
            }
            return;
        case 2:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFF00) >> 8) | (gGlyphUpperRowBuffer[i * 2 + 1] & 0xFF) << 8;
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFF00) >> 8) | (gGlyphLowerRowBuffer[i * 2 + 1] & 0xFF) << 8;
            }
            return;
        case 3:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFFF0) >> 0x4) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 0xC);
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2 + 1] & 0xF0) >> 0x4;

                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFFF0) >> 0x4) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 0xC);
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2 + 1] & 0xF0) >> 0x4;
            }
            return;
        case 4:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= gGlyphUpperRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= gGlyphUpperRowBuffer[i * 2 + 1] & 0xFF;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2 + 1] & 0xFF;
            }
            return;
        case 5:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xFF) << 4);
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xFF) << 4);

            }
            return;
        case 6:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFF00) >> 0x8) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xFF) << 8);
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFF00) >> 0x8) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xFF) << 8);
            }
            return;
        case 7:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFFF0) >> 0x4) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 0xC);
                gTempGfxBuffer[(i * 2 + 0x11) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2 + 1] & 0xF0) >> 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFFF0) >> 0x4) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 0xC);
                gTempGfxBuffer[(i * 2 + 0x11) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2 + 1] & 0xF0) >> 4;

            }
            return;
        default:
            return;
        }
        break;
    case 5:
        switch (arg1 % 8) {
        case 0:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= gGlyphUpperRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= gGlyphUpperRowBuffer[i * 2 + 1] & 0xF;
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2 + 1] & 0xF;

            }
            return;
        case 1:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 4);
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 4);

            }
            return;
        case 2:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFF00) >> 0x8) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 8);
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFF00) >> 0x8) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 8);

            }
            return;
        case 3:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFFF0) >> 0x4) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 0xC);
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFFF0) >> 0x4) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 0xC);

            }
            return;
        case 4:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= gGlyphUpperRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= gGlyphUpperRowBuffer[i * 2 + 1] & 0xF;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2 + 1] & 0xF;

            }
            return;
        case 5:
           for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 4);
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xF000) >> 0xC) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 4);

            }
            return;
        case 6:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFF00) >> 8) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 8);
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFF00) >> 0x8) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 8);

            }
            return;
        case 7:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= ((gGlyphUpperRowBuffer[i * 2] & 0xFFF0) >> 4) | ((gGlyphUpperRowBuffer[i * 2 + 1] & 0xF) << 0xC);
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= ((gGlyphLowerRowBuffer[i * 2] & 0xFFF0) >> 4) | ((gGlyphLowerRowBuffer[i * 2 + 1] & 0xF) << 0xC);

            }
            return;
        }
        break;
    case 4:
        switch (arg1 % 8) {
        case 0:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= gGlyphUpperRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2];
            }
            return;
        case 1:
           for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF000) >> 0xC;
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF000) >> 0xC;
            }
            return;
        case 2:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF00) >> 8;
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF00) >> 8;
            }
            return;
        case 3:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF0) >> 4;
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF0) >> 4;
            }
            return;
        case 4:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= gGlyphUpperRowBuffer[i * 2];
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= gGlyphLowerRowBuffer[i * 2];
            }
            return;
        case 5:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF000) >> 0xC;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF000) >> 0xC;
            }
            return;
        case 6:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF00) >> 8;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF00) >> 8;
            }
            return;
        case 7:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF0) >> 4;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF0) >> 4;
            }
            return;
        }
        break;
    case 3:
        switch (arg1 % 8) {
        case 0:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF);
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF);
            }
            return;
        case 1:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
            }
            return;
        case 2:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF00) >> 8;
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF00) >> 8;
            }
            return;
        case 3:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF0) >> 4;
                gTempGfxBuffer[(i * 2) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF0) >> 4;
            }
            return;
        case 4:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF);
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF);
            }
            return;
        case 5:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFFF) << 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFFF) << 4;
            }
            return;
        case 6:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF00) >> 8;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF00) >> 8;
            }
            return;
        case 7:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF0) >> 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF0) >> 4;
            }
            return;
        }
        break;
    case 2:
        switch (arg1 % 8) {
        case 0:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF);
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF);
            }
            return;
        case 1:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 4;
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 4;
            }
            return;
        case 2:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 8;
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 8;
            }
            return;
        case 3:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[i * 2 + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF0) >> 4;
                gTempGfxBuffer[i * 2 + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF0) >> 4;
            }
            return;
        case 4:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF);
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF);
            }
            return;
        case 5:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 0x4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 0x4;
            }
            return;
        case 6:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xFF) << 0x8;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xFF) << 0x8;
            }
            return;
        case 7:
            for(i = 0; i <=7; i++)
            {
                gTempGfxBuffer[(i * 2 + 1) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2] |= (gGlyphUpperRowBuffer[i * 2] & 0xF0) >> 4;
                gTempGfxBuffer[(i * 2 + 1) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF) << 0xC;
                gTempGfxBuffer[(i * 2 + 0x10) + temp_r2 + 0x200] |= (gGlyphLowerRowBuffer[i * 2] & 0xF0) >> 4;
            }
            break;
        }
        break;
    }
}


void LoadPokedexFlagsFromSave(void)
{
    int i;

    for (i = 0; i < NUM_SPECIES; i++)
        gPokedexFlags[i] = gMain_saveData.pokedexFlags[i];

	// It's unclear what these trailing 20 entries are...
    for (i = NUM_SPECIES; i < NUM_SPECIES + 20; i++)
        gPokedexFlags[i] = 0;

    gPokedexNumOwned = 0;
    gPokedexNumSeen = 0;
    for (i = 0; i < NUM_SPECIES; i++)
    {
        switch (gPokedexFlags[i])
        {
        case SPECIES_CAUGHT:
            gPokedexNumOwned++;
        case SPECIES_SEEN:
        case SPECIES_SHARED_AND_SEEN:
            gPokedexNumSeen++;
            break;
        case SPECIES_UNSEEN:
        case SPECIES_SHARED:
            break;
        }
    }
}

void LoadMonAnimationSprite(s16 species)
{
    int var0;
    s16 quotient;
    s16 remainder;
    s16 var1;

    var0 = gDexAnimationIx[species];
    if (var0 == -1)
        return;

    if (var0 < 100)
    {
        gPokedexSpriteCategory = 0;
        quotient = var0 / 5;
        remainder = var0 % 5;

        CopyBgTilesRect(gCatchSpriteGfxPtrs[quotient] + remainder * 0xD80, (void *)(OBJ_VRAM0 + 0x3800), 108, 1);
        DmaCopy16(3, gMonIconPalettes[quotient] + remainder * 0x20, (void *)OBJ_PLTT + 0x40, 0x20);
    }
    else
    {
        gPokedexSpriteCategory = 1;
        quotient = (var0 - 100) / 6;
        remainder = (var0 - 100) % 6;

        CopyBgTilesRect(gMonHatchSpriteGroupGfx[quotient][remainder], (void *)(OBJ_VRAM0 + 0x4800), 135, 1);
        DmaCopy16(3, gMonHatchSpriteGroupPals[quotient][remainder], (void *)OBJ_PLTT + 0x60, 0x20);
    }
}

s16 CheckMonHasAnimation(s16 species)
{
    if (gPokedexFlags[species] == 4 && gDexAnimationIx[species] != -1)
        gPokedexShowAnimSprite = 1;
    else
        gPokedexShowAnimSprite = 0;

    return gPokedexShowAnimSprite;
}

void ResetPokedex(void)
{
    int i;

    for (i = 0; i < NUM_SPECIES; i++)
        gMain_saveData.pokedexFlags[i] = SPECIES_UNSEEN;
}
