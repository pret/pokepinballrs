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
    POKEDEX_STATE_11,
    POKEDEX_STATE_RETURN_TO_TITLE,
};

void sub_5174(void);
static void PokedexListScrollUp(void);
static void PokedexListScrollDown(void);
static void PokedexListScrollUpFast(void);
static void PokedexListScrollDownFast(void);
void sub_4FC8(void);
void sub_5064(void);
void sub_51CC(void);
static s16 sub_5EA4(void);
s16 sub_5EC8(void);
void sub_70E0(s16, u32);
void sub_88E4(void);
void sub_51FC(void);
static void RenderLinkGraphics(void);
static void sub_5E60(void);
int sub_639C(void);
static int sub_5EEC(void);
static int sub_6144(void);
static int sub_65DC(void);
static void PrintSelectedMonDexNum(s16);
static void PrintSeenOwnedTotals(s16, s16);
void sub_71DC(int, int, int);
void PrintDexNumbersFromListPosition(s16);
static void PrintCaughtBallFromListPosition(s16);
void sub_6F78(s16);

extern u8 *gUnknown_086B15B4[];
extern u8 *gUnknown_086BB6F4[];
extern u8 *gMonHatchSpriteGroupGfx[];
extern u8 *gMonHatchSpriteGroupPals[];

extern u16 gUnknown_0201C180;
extern u16 gUnknown_0202C5B4;
extern s8 gUnknown_0201C1BC;
extern s8 gUnknown_0202C544;
extern s8 gUnknown_0202BECC;
extern u16 gUnknown_0202BE30[];
extern u16 gUnknown_0201B130[];

extern const struct SpriteSet *const gUnknown_086A6148[];
extern u16 gUnknown_0202BF08;
extern const u16 gUnknown_086A5DDA[][4];
extern const u16 gUnknown_086A5DF2[][20];
extern const s16 gUnknown_086A6356[];
extern const u16 gUnknown_086A5EE2[][51];
extern const s16 gUnknown_086A6014[][51];
extern const u16 gUnknown_086A5E12[][4];
extern s16 gUnknown_086A64F0[];
extern u8 *gMonPortraitGroupGfx[];
extern u8 *gMonPortraitGroupPals[];

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
    ResetSomeGraphicsRelatedStuff();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    REG_BG1CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(0) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG3_ON;

    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gPokedexBgText_Gfx, (void *)BG_CHAR_ADDR(1), 0x4400);
    DmaCopy16(3, gPokedexBg_Gfx, (void *)BG_CHAR_ADDR(3), 0x1400);
    DmaCopy16(3, gPokedexBackground_Pals, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gPokedexBg1_Tilemap, gUnknown_03005C00, BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexBg2_Tilemap, gUnknown_02019C40, BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexBg3_Tilemap, (void *)BG_SCREEN_ADDR(2), BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexSprites_Pals, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gPokedexSprites_Gfx, (void *)OBJ_VRAM0, 0x6C20);

    sub_3FAC();
    PrintSeenOwnedTotals(gPokedexNumSeen, gPokedexNumOwned);
    PrintSelectedMonDexNum(gPokedexSelectedMon);
    PrintDexNumbersFromListPosition(gPokedexListPosition);
    PrintCaughtBallFromListPosition(gPokedexListPosition);
    sub_6F78(gPokedexSelectedMon);
    sub_8974(gPokedexSelectedMon);
    sub_8A78(gPokedexSelectedMon);

    gUnknown_02019C40[0x134] = 0x59;

    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_02019C40, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);

    sub_51FC();
    sub_0CBC();
    sub_024C();

    gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;

    m4aSongNumStart(MUS_POKEDEX);
}

void sub_3FAC(void)
{
    s32 i;

    gPokedexSelectedMon = 0;
    gPokedexListPosition = 0;
    gUnknown_0201A448 = 0;
    gUnknown_0202BF00 = 0;
    gUnknown_0202A57C = 0;
    gUnknown_0201A4F0 = 0;
    gUnknown_0202BE20 = 0;
    gPokedexScrollWaitFrames = 0;
    gUnknown_02019C24 = 0;
    gUnknown_0202BF0C = 0;
    gUnknown_0201A440 = 0;
    gUnknown_0202C5E8 = 0;
    gUnknown_0202BEF4 = 0;
    gUnknown_0202A588 = 1;
    gUnknown_0202A55C = 1;

    gUnknown_0202A568[0] = 0;
    gUnknown_0202A568[1] = 0;

    gUnknown_0202BF14 = 0;
    gUnknown_0202A558 = 0;
    gUnknown_0202BEE0 = 0;
    gUnknown_0202BF04 = 1;

    sub_88E4();
    if (sub_FD20() == 1)
    {
        gUnknown_0202C590 = 1;
    }
    else
    {
        gUnknown_0202C590 = 0;
    }

    gUnknown_0202BEC4 = 0;
    gUnknown_0202BEFC = 0;
    gUnknown_0201B120 = 0;
    gUnknown_02002830 = 0;
    gUnknown_02002831 = 0;
    gUnknown_0202C794 = 0;
    gUnknown_0201C1B4 = 0;
    gUnknown_0202C5AC = 0;
    gUnknown_02019C28 = 0;

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
        gUnknown_0202BF04 = 0;

        if (JOY_HELD(DPAD_UP))
        {
            PokedexListScrollUp();
            sub_5064();
            sub_51CC();
            gMain.subState = POKEDEX_STATE_2;
        }
        else if (JOY_HELD(DPAD_DOWN))
        {
            PokedexListScrollDown();
            sub_5064();
            sub_51CC();
            gMain.subState = POKEDEX_STATE_2;
        }
        else if (JOY_HELD(DPAD_LEFT))
        {
            PokedexListScrollUpFast();
            sub_5064();
            sub_51CC();
            gMain.subState = POKEDEX_STATE_2;
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            PokedexListScrollDownFast();
            sub_5064();
            sub_51CC();
            gMain.subState = POKEDEX_STATE_2;
        }
        else
        {
            gUnknown_02019C24 = 0;
            sub_5064();
        }

        if (JOY_NEW(A_BUTTON))
        {
            gUnknown_0202C5E8 = 0;

            if (gPokedexFlags[gPokedexSelectedMon] >= 2)
            {
                gUnknown_0202BF04 = 0;
                DmaCopy16(3, 0x6000280, (void *)gUnknown_0202A590, 0x200);
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
        gUnknown_0202BF04 = 1;

        if (JOY_HELD(DPAD_UP))
        {
            PokedexListScrollUp();
            sub_5174();
        }
        else if (JOY_HELD(DPAD_DOWN))
        {
            PokedexListScrollDown();
            sub_5174();
        }
        else if (JOY_HELD(DPAD_LEFT))
        {
            PokedexListScrollUpFast();
            sub_5174();
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            PokedexListScrollDownFast();
            sub_5174();
        }
        else
        {
            gUnknown_02019C24 = 0;
        }

        if (sub_8A78(gPokedexSelectedMon) == 1)
            gUnknown_0202A588 = 1;
        else
            gUnknown_0202A588 = 0;

        gUnknown_0202A55C = 1;
        gUnknown_0202A568[0] = 0;
        gUnknown_0202A568[1] = 0;
        gUnknown_0201A440 = 0;
        gUnknown_0202BF0C = 0;

        if (JOY_NEW(A_BUTTON))
        {
            gUnknown_0202C5E8 = 0;

            if (gPokedexFlags[gPokedexSelectedMon] >= SPECIES_SHARED)
            {
                gUnknown_0202BF04 = 0;
                DmaCopy16(3, 0x6000280, (void *)gUnknown_0202A590, 0x200);
                gMain.subState = POKEDEX_STATE_3;
            }
            else
            {
                m4aSongNumStart(SE_FAILURE);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL_0x66);
            gMain.subState = POKEDEX_STATE_RETURN_TO_TITLE;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            m4aSongNumStart(SE_MENU_POPUP_OPEN_0x68);
            gUnknown_0202BEC4 = 1;
            gUnknown_0202BEFC = 0;
            gUnknown_0202BF04 = 0;
            gUnknown_0202A588 = 0;
            gMain.subState = POKEDEX_STATE_LINK_SETUP;
        }

        sub_4FC8();
    }

    if (gPokedexScrollWaitFrames > 0)
        gPokedexScrollWaitFrames--;

    sub_51FC();
    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
}

void sub_43D4(void)
{
    sub_5174();
    gUnknown_0202A588 = 0;

    if (gPokedexScrollWaitFrames > 0)
        gPokedexScrollWaitFrames--;

    sub_51FC();
    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;
}

void sub_4428(void)
{
    int i;

    for (i = 0; i < 0x20; i++)
    {
        gUnknown_03005C00[0x20*(gUnknown_0202A558 + 10) + i] = gDexInfoWindowEmptyTextRowTiles[i];
        gUnknown_02019C40[0x20*(gUnknown_0202A558 + 9) + i] = gDexInfoWindowMiddleRowTiles[i];
        gUnknown_02019C40[0x20*(gUnknown_0202A558 + 10) + i] = gDexInfoWindowBottomRowTiles[i];
    }

    gUnknown_0202A558++;
    gUnknown_02019C40[0x134] = 0x59;
    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_02019C40, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);

    if (gUnknown_0202A558 > 7)
    {
        gUnknown_0202A558 = 0;
        gUnknown_0202C5E8 = 0;
        gUnknown_0202BEF4 = 0;
        gUnknown_02019C28 = 0;
        gUnknown_0202C5AC = 0;

        if (gPokedexSelectedMon < BONUS_SPECIES_START)
            gUnknown_0201C1B4 = 1;

        DmaCopy16(3, gUnknown_08086B40, (void *)0x6000280, 2*0xE0);
        sub_70E0(gPokedexSelectedMon, gUnknown_0202C794);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x40);
        PlayCry_NormalNoDucking(gSpeciesInfo[gPokedexSelectedMon].mainSeriesIndexNumber, 0, 127, 10);
        gMain.subState = POKEDEX_STATE_5;
    }

}

void sub_45A4(void)
{
    u16 var0;

    if (gUnknown_0202C5E8 < 0x51)
    {
        gUnknown_0202C5E8++;
        if (gUnknown_0202C5E8 == 0x50)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        }
    }
    gUnknown_0202BEF4 = gUnknown_0202BEF4 + 1;
    if (0x1e < gUnknown_0202BEF4)
    {
        gUnknown_0202BEF4 = 0;
        gUnknown_0202C5AC = 1 - gUnknown_0202C5AC;
    }
    gUnknown_0202BE20 = 0;

    if (JOY_NEW(DPAD_UP))
    {
        if ((gPokedexSelectedMon < BONUS_SPECIES_START) && (gUnknown_0202C794 == 1))
        {
            m4aSongNumStart(SE_UNKNOWN_0x6D);
            gUnknown_0202C794 = 0;
            sub_70E0(gPokedexSelectedMon, 0);
            gUnknown_02019C28 = gUnknown_0202C794;
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if ((gPokedexSelectedMon < BONUS_SPECIES_START) && (gUnknown_0202C794 == 0))
        {
            m4aSongNumStart(SE_UNKNOWN_0x6D);
            gUnknown_0202C794 = 1;
            sub_70E0(gPokedexSelectedMon, 1);
            gUnknown_02019C28 = gUnknown_0202C794;
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        if (gPokedexSelectedMon < BONUS_SPECIES_START)
        {
            if (!gUnknown_0202C794)
            {
                m4aSongNumStart(SE_UNKNOWN_0x6D);
                gUnknown_0202C794 = 1 - gUnknown_0202C794;
                sub_70E0(gPokedexSelectedMon, gUnknown_0202C794);
                gUnknown_02019C28 = gUnknown_0202C794;
            }
            else
            {
                m4aSongNumStart(SE_MENU_POPUP_CLOSE_0x69);
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
                gUnknown_0202C794 = 0;
                gUnknown_0202C5E8 = 0;
                gUnknown_0202BEF4 = gUnknown_0202C5E8;
                gUnknown_0201C1B4 = 0;
                gMain.subState = POKEDEX_STATE_4;
            }
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_POPUP_CLOSE_0x69);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        gUnknown_0202C794 = 0;
        gUnknown_0202C5E8 = 0;
        gUnknown_0202BEF4 = gUnknown_0202C5E8;
        gUnknown_0201C1B4 = 0;
        gMain.subState = POKEDEX_STATE_4;
    }

    if (JOY_HELD(SELECT_BUTTON))
    {
        if (gPokedexFlags[gPokedexSelectedMon] == SPECIES_CAUGHT)
        {
            if (gUnknown_086A61BC[gPokedexSelectedMon] == -1)
            {
                gUnknown_0202A588 = 0;
                gUnknown_0202A55C = 1;
                gUnknown_0202A568[0] = 0;
                gUnknown_0202A568[1] = 0;
                gUnknown_0201A440 = 0;
                gUnknown_0202BF0C = 0;
            }
            else
            {
                if (gUnknown_086A61BC[gPokedexSelectedMon] < 100)
                {
                    gUnknown_0202A588 = 0;
                    gUnknown_0202A55C = 0;
                    gUnknown_0202A568[0] = 1;
                    gUnknown_0202A568[1] = 0;
                }
                else
                {
                    gUnknown_0202A588 = 0;
                    gUnknown_0202A55C = 0;
                    gUnknown_0202A568[0] = 0;
                    gUnknown_0202A568[1] = 1;
                }
            }
        }
        else
        {
            gUnknown_0202A588 = 0;
            gUnknown_0202A55C = 1;
            gUnknown_0202A568[0] = 0;
            gUnknown_0202A568[1] = 0;
        }
    }
    else
    {
        if (sub_8A78(gPokedexSelectedMon) == 1)
            gUnknown_0202A588 = 1;
        else
            gUnknown_0202A588 = 0;

        gUnknown_0202A55C = 1;
        gUnknown_0202A568[0] = 0;
        gUnknown_0202A568[1] = 0;
        gUnknown_0201A440 = 0;
        gUnknown_0202BF0C = 0;
    }

    sub_51FC();
}

void sub_4860(void)
{
    s32 i;

    for (i = 0; i < 0x20; i++)
    {
        gUnknown_02019C40[0x20 * (0x11 - gUnknown_0202A558) + i] = gDexInfoWindowBottomRowTiles[i];
        gUnknown_02019C40[0x20 * (0x12 - gUnknown_0202A558) + i] = gDexInfoWindowEmptyRowTiles[i];
    }

    if (gUnknown_0202A558 < 8)
    {
        for (i = 0; i < 0x20; i++)
        {
            gUnknown_03005C00[0x20 * (0x11 - gUnknown_0202A558) + i] = gUnknown_0202A590[0x20 * (0x7 - gUnknown_0202A558) + i];
        }
    }
    gUnknown_0202A558++;

    gUnknown_02019C40[0x134] = 0x59;
    DmaCopy16(3, gUnknown_02019C40, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);

    if (gUnknown_0202A558 > 8)
    {
        gUnknown_0202A558 = 0;
        gUnknown_0202A588 = 0;
        gUnknown_0202BF04 = 1;

        DmaFill16(3, 0, (void *)gUnknown_03000000, 0x1800);
        DmaFill16(3, 0, (void *)0x6005C00, 0x1800);
        gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;
    }
}

void Pokedex_LinkSetup(void)
{
    sub_19B4();
    sub_5E60();
    gUnknown_0201B124 = 0;
    RenderLinkGraphics();
    gMain.subState = POKEDEX_STATE_7;
}

void sub_49D0(void)
{
    s16 var0;

    RenderLinkGraphics();

    if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL_0x66);
        gUnknown_0202BEC4 = 0;
        gUnknown_0202BEFC = 0;
        gUnknown_0202BF04 = 1;
        gUnknown_0202A588 = 1;
        sub_2568();
        gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;
    }
    else
    {
        gUnknown_0202ADD0 = LinkMain1(&gUnknown_0202BEC8, gUnknown_0202C5F0, gUnknown_0201A4D0);
        gUnknown_0202BDF0 = gUnknown_0202ADD0 & 3;
        gUnknown_0201C1AC = (gUnknown_0202ADD0 & 0x1C) >> 2;
        gUnknown_0202ADDC = (gUnknown_0202ADD0 & 0xe00) >> 9;

        if ((gUnknown_0202ADD0 & 0x40) && (gUnknown_0202BDF0 < 2))
        {
            sub_5EC8();

            if (!(gUnknown_0202ADD0 & 0x100))
            {
                var0 = sub_5EA4();
                if (var0 == -1)
                {
                    gMain.subState = POKEDEX_STATE_9;
                }
                else if (var0 == 1)
                {
                    gUnknown_0202BEFC = 2;
                    gMain.subState = POKEDEX_STATE_8;
                    m4aSongNumStart(SE_FAILURE);
                }
            }

            gUnknown_0201A510++;

            if ((gUnknown_0202ADD0 & 0x7f0000) && gUnknown_0201B128 == -1)
            {
                gUnknown_0201A444++;
                if (0xB4 < gUnknown_0201A444)
                {
                    gUnknown_0202BEFC = 2;
                    gMain.subState = POKEDEX_STATE_8;
                    m4aSongNumStart(SE_FAILURE);
                }
            }
        }
    }
}

void sub_4B10(void)
{
    gUnknown_0201A444++;

    if (2 < gUnknown_0201A444) {
        gUnknown_0201A444 = 0;
        gMain.subState = POKEDEX_STATE_LINK_SETUP;
    }
}

void sub_4B34(void)
{
    s32 iVar1;

    RenderLinkGraphics();
    gUnknown_0201B120++;

    if (0x5A < gUnknown_0201B120)
    {
        gUnknown_0201B120 = 0;
        gUnknown_0202BEC4 = 0;
        gUnknown_0202BEFC = 0;
        gUnknown_0202BF04 = 1;
        gUnknown_0202A588 = 1;

        sub_2568();
        DisableSerial();

        for(iVar1 = 0; iVar1 < 0xE1; iVar1++)
        {
            gPokedexFlagExchangeBuffer[iVar1] = gPokedexFlags[iVar1];
        }

        sub_02B4();
        m4aMPlayAllStop();
        sub_0D10();
        gMain.subState = POKEDEX_STATE_LOAD_GRAPHICS;
    }
}

void sub_4BB4(void)
{
    s32 index;

    RenderLinkGraphics();
    switch(gUnknown_0201B120)
    {
        case 0x4:
            sub_2568();
            DisableSerial();
            break;
        case 0x82:
            gUnknown_0202BEFC = 3;
            m4aSongNumStart(SE_MENU_SELECT_0x65);
            break;
        case 0xFA:
            gUnknown_0201B120 = 0;
            gUnknown_0202BEC4 = 0;
            gUnknown_0202BEFC = 0;
            gUnknown_0202BF04 = 1;
            gUnknown_0202A588 = 1;
            for(index = 0; index < 0xE1; index++)
            {
                gPokedexFlags[index] = gPokedexFlagExchangeBuffer[index];
            }
            for(index = 0; index < NUM_SPECIES; index++)
            {
                gMain_saveData.pokedexFlags[index] = gPokedexFlags[index];
            }
            SaveFile_WriteToSram();
            sub_02B4();
            m4aMPlayAllStop();
            sub_0D10();
            gMain.subState = POKEDEX_STATE_LOAD_GRAPHICS;
            break;
    }
    gUnknown_0201B120 += 1;
}

void sub_4C80(void)
{
    s32 i;

    sub_51FC();

    if (JOY_NEW(A_BUTTON))
    {
        m4aSongNumStart(SE_MENU_SELECT_0x65);
        for (i = 0; i < 0xE1; i++)
        {
            gPokedexFlagExchangeBuffer[i] = 0;
            gPokedexFlags[i] = 0;
        }
        for (i = 0; i < NUM_SPECIES; i++)
        {
            gMain_saveData.pokedexFlags[i] = gPokedexFlags[i];
        }

        gUnknown_0202BEC4 = 0;
        gUnknown_0202BEFC = 0;
        gUnknown_0202BF04 = 1;
        gUnknown_0202A588 = 1;

        SaveFile_WriteToSram();
        sub_02B4();
        m4aMPlayAllStop();
        sub_0D10();
        gMain.subState = POKEDEX_STATE_LOAD_GRAPHICS;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL_0x66);
        gUnknown_0202BEC4 = 0;
        gUnknown_0202BEFC = 0;
        gUnknown_0202BF04 = 1;
        gUnknown_0202A588 = 1;
        gMain.subState = POKEDEX_STATE_HANDLE_LIST_INPUT;


    }
}

void Pokedex_ReturnToTitle(void)
{
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();

    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(STATE_TITLE);
}

static void PokedexListScrollUp(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;

    if (gUnknown_0202A57C == 0)
    {
        if (gPokedexListPosition == 0)
        {
            if (gUnknown_02019C24 == 0)
            {
                gPokedexListPosition = gPokedexListEntryCount - NUM_BONUS_SPECIES - 1;
                gPokedexSelectedMon = gPokedexListEntryCount - 1;
                gUnknown_0202A57C = 4;
                m4aSongNumStart(SE_MENU_MOVE_0x67);
            }
        }
        else
        {
            gPokedexListPosition--;
            gPokedexSelectedMon--;
            m4aSongNumStart(SE_MENU_MOVE_0x67);
        }

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }
    else
    {
        m4aSongNumStart(SE_MENU_MOVE_0x67);
        gUnknown_0202A57C--;
        gPokedexSelectedMon--;

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }

    gUnknown_02019C24 = 1;
}

static void PokedexListScrollDown(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;
    if (gUnknown_0202A57C == 4)
    {
        if (gPokedexListPosition == gPokedexListEntryCount - NUM_BONUS_SPECIES - 1)
        {
            if (gUnknown_02019C24 == 0)
            {
                gPokedexListPosition = 0;
                gPokedexSelectedMon = 0;
                gUnknown_0202A57C = 0;
                m4aSongNumStart(SE_MENU_MOVE_0x67);
            }
        }
        else
        {
            gPokedexListPosition++;
            gPokedexSelectedMon++;
            m4aSongNumStart(SE_MENU_MOVE_0x67);
        }

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }
    else
    {
        m4aSongNumStart(SE_MENU_MOVE_0x67);
        gUnknown_0202A57C++;
        gPokedexSelectedMon++;
        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }

    gUnknown_02019C24 = 1;
}

static void PokedexListScrollUpFast(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;
    if (gPokedexListPosition == 0)
        return;

    m4aSongNumStart(SE_MENU_MOVE_0x67);
    gPokedexListPosition -= ENTRIES_SHOWN_COUNT;
    if (gPokedexListPosition < 0)
        gPokedexListPosition = 0;

    gPokedexSelectedMon = gPokedexListPosition + gUnknown_0202A57C;
    gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
}

static void PokedexListScrollDownFast(void)
{
    if (gPokedexScrollWaitFrames != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;
    if (gPokedexListPosition == gPokedexListEntryCount - NUM_BONUS_SPECIES - 1)
        return;

    m4aSongNumStart(SE_MENU_MOVE_0x67);
    gPokedexListPosition += ENTRIES_SHOWN_COUNT;
    if (gPokedexListPosition > gPokedexListEntryCount - NUM_BONUS_SPECIES - 1)
        gPokedexListPosition = gPokedexListEntryCount - NUM_BONUS_SPECIES - 1;

    gPokedexSelectedMon = gPokedexListPosition + gUnknown_0202A57C;
    gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
}

void sub_4FC8(void)
{
    if (JOY_HELD(L_BUTTON | DPAD_LEFT) == (L_BUTTON | DPAD_LEFT) && JOY_NEW(R_BUTTON))
    {
        gUnknown_02002830 = 40;
        if (++gUnknown_02002831 == 3)
        {
            gUnknown_02002831 = 0;
            gUnknown_02002830 = 0;
            m4aSongNumStart(SE_MENU_POPUP_OPEN_0x68);
            gUnknown_0202BEC4 = 1;
            gUnknown_0202BEFC = 4;
            gUnknown_0202BF04 = 0;
            gUnknown_0202A588 = 0;
            gMain.subState = POKEDEX_STATE_11;
        }
    }

    if (gUnknown_02002830 > 0)
    {
        gUnknown_02002830--;
        if (gUnknown_02002830 <= 0)
        {
            gUnknown_02002830 = 0;
            gUnknown_02002831 = 0;
        }
    }
}

void sub_5064(void)
{
    if (gPokedexFlags[gPokedexSelectedMon] == SPECIES_CAUGHT)
    {
        if (gUnknown_086A61BC[gPokedexSelectedMon] == -1)
        {
            gUnknown_0202A588 = 0;
            gUnknown_0202A55C = 1;
            gUnknown_0202A568[0] = 0;
            gUnknown_0202A568[1] = 0;
            gUnknown_0201A440 = 0;
            gUnknown_0202BF0C = 0;
        }
        else if (gUnknown_086A61BC[gPokedexSelectedMon] < 100)
        {
            gUnknown_0202A588 = 0;
            gUnknown_0202A55C = 0;
            gUnknown_0202A568[0] = 1;
            gUnknown_0202A568[1] = 0;
        }
        else
        {
            gUnknown_0202A588 = 0;
            gUnknown_0202A55C = 0;
            gUnknown_0202A568[0] = 0;
            gUnknown_0202A568[1] = 1;
        }
    }
    else
    {
        gUnknown_0202A588 = 0;
        gUnknown_0202A55C = 1;
        gUnknown_0202A568[0] = 0;
        gUnknown_0202A568[1] = 0;
    }
}

u8 sub_5134(void)
{
    if (gPokedexFlags[gPokedexSelectedMon] == SPECIES_CAUGHT && gUnknown_086A61BC[gPokedexSelectedMon] != -1)
    {
        if (gUnknown_086A61BC[gPokedexSelectedMon] < 100)
            return 1;

        return 2;
    }

    return 0;
}

void sub_5174(void)
{
    PrintDexNumbersFromListPosition(gPokedexListPosition);
    PrintCaughtBallFromListPosition(gPokedexListPosition);
    PrintSelectedMonDexNum(gPokedexSelectedMon);
    sub_6F78(gPokedexSelectedMon);
    sub_8974(gPokedexSelectedMon);
    sub_8A78(gPokedexSelectedMon);
    gUnknown_0202BF00 = 0;
    gUnknown_0201A448 = 0;
}

void sub_51CC(void)
{
    if (sub_5134() == 0)
        sub_6F78(gPokedexSelectedMon);
    else
        sub_8974(gPokedexSelectedMon);
}

void sub_51FC(void)
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
    group5 = &gMain_spriteGroups[5 + gUnknown_0201A448];
    group6 = &gMain_spriteGroups[17 + gUnknown_0202BEFC];
    group7 = &gMain_spriteGroups[22 + gUnknown_0202BEE0];
    group8 = &gMain_spriteGroups[24];
    group9 = &gMain_spriteGroups[25 + gUnknown_02019C28 * 2 + gUnknown_0202C5AC];

    group0->available = TRUE;
    group1->available = TRUE;
    group2->available = gUnknown_0202A55C;
    group3->available = gUnknown_0202A568[0];
    group4->available = gUnknown_0202A568[1];
    group5->available = gUnknown_0202A588;
    group6->available = gUnknown_0202BEC4;
    group7->available = gUnknown_0202BF04;
    group8->available = gUnknown_0202C590;
    group9->available = gUnknown_0201C1B4;
    LoadSpriteSets(gUnknown_086A6148, 29, group0);

    group0->baseX = 20 + gUnknown_0201A4F0;
    group0->baseY = 84 + gUnknown_0202A57C * 16;
    groupOam = &group0->oam[0];
    gOamBuffer[groupOam->oamId].priority = 3;
    gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group0->baseX;
    gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group0->baseY;

    if (gPokedexSelectedMon < 200)
        gUnknown_0202BF08 = 86 + gPokedexSelectedMon / 3;
    else
        gUnknown_0202BF08 = 152;

    group1->baseX = 13;
    group1->baseY = gUnknown_0202BF08;
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
            gOamBuffer[groupOam->oamId].tileNum = gUnknown_086A5DDA[gUnknown_0202BF14][i] +
                                                  gUnknown_086A5DF2[gUnknown_0202BF14][gUnknown_0202BF0C];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group3->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group3->baseY;
        }

        if (++gUnknown_0201A440 > 14)
        {
            gUnknown_0201A440 = 0;
            if (++gUnknown_0202BF0C > 8)
                gUnknown_0202BF0C = 0;
        }
    }

    if (group4->available == 1)
    {
        if (gUnknown_086A6356[gPokedexSelectedMon] == -1)
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
            gOamBuffer[groupOam->oamId].tileNum = gUnknown_086A5DDA[var0][i] + gUnknown_086A5EE2[var0][gUnknown_0202BF0C];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group4->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group4->baseY;
        }

        if (++gUnknown_0201A440 > gUnknown_086A6014[var0][gUnknown_0202BF0C])
        {
            gUnknown_0201A440 = 0;
            if (++gUnknown_0202BF0C > var1)
                gUnknown_0202BF0C = 0;
        }
    }

    if (group5->available == 1)
    {
        group5->baseX = 36;
        group5->baseY = 64;
        spriteSet = gUnknown_086A6148[5 + gUnknown_0201A448];
        for (i = 0; i < spriteSet->count; i++)
        {
            groupOam = &group5->oam[i];
            gOamBuffer[groupOam->oamId].priority = 1;
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group5->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group5->baseY;
        }

        if (++gUnknown_0202BF00 > 8)
        {
            gUnknown_0202BF00 = 0;
            if (++gUnknown_0201A448 > 11)
                gUnknown_0201A448 = 0;
        }
    }

    if (group6->available == 1)
    {
        if (gUnknown_0202BEFC == 0 || gUnknown_0202BEFC == 4)
        {
            group6->baseX = 120;
            group6->baseY = 100;
        }
        else
        {
            group6->baseX = 120;
            group6->baseY = 80;
        }

        spriteSet = gUnknown_086A6148[17 + gUnknown_0202BEFC];
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
        spriteSet = gUnknown_086A6148[22 + gUnknown_0202BEE0];
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

    if (++gUnknown_0202BE20 > 12)
    {
        gUnknown_0202BE20 = 0;
        gUnknown_0201A4F0 = 1 - gUnknown_0201A4F0;
        gUnknown_0202BEE0 = 1 - gUnknown_0202BEE0;
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
    group6 = &gMain_spriteGroups[5 + gUnknown_0201A448];
    group7 = &gMain_spriteGroups[17 + gUnknown_0202BEFC];
    group5 = &gMain_spriteGroups[24];

    group0->available = TRUE;
    group1->available = TRUE;
    group2->available = gUnknown_0202A55C;
    group3->available = gUnknown_0202A568[0];
    group4->available = gUnknown_0202A568[1];
    group6->available = FALSE;
    group7->available = gUnknown_0202BEC4;
    group5->available = gUnknown_0202C590;
    sub_2414(gUnknown_086A6148, 29, group0);

    group0->baseX = 20 + gUnknown_0201A4F0;
    group0->baseY = 84 + gUnknown_0202A57C * 16;
    groupOam = &group0->oam[0];
    gOamBuffer[groupOam->oamId].priority = 2;
    gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group0->baseX;
    gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group0->baseY;

    gUnknown_0202BF08 = 86 + gPokedexSelectedMon / 3;
    group1->baseX = 13;
    group1->baseY = gUnknown_0202BF08;
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
            gOamBuffer[groupOam->oamId].tileNum = gUnknown_086A5DDA[gUnknown_0202BF14][i] +
                                                  gUnknown_086A5DF2[gUnknown_0202BF14][gUnknown_0202BF0C];
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
            gOamBuffer[groupOam->oamId].tileNum = gUnknown_086A5DDA[1][i] +
                                                  gUnknown_086A5E12[1][gUnknown_0202BF0C];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group4->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group4->baseY;
        }
    }

    if (group6->available == 1)
    {
        group6->baseX = 36;
        group6->baseY = 64;
        spriteSet = gUnknown_086A6148[5 + gUnknown_0201A448];
        for (i = 0; i < spriteSet->count; i++)
        {
            groupOam = &group6->oam[i];
            gOamBuffer[groupOam->oamId].x = groupOam->xOffset + group6->baseX;
            gOamBuffer[groupOam->oamId].y = groupOam->yOffset + group6->baseY;
        }
    }

    if (group7->available == 1)
    {
        if (gUnknown_0202BEFC == 0 || gUnknown_0202BEFC == 4)
        {
            group7->baseX = 120;
            group7->baseY = 100;
        }
        else
        {
            group7->baseX = 120;
            group7->baseY = 80;
        }

        spriteSet = gUnknown_086A6148[17 + gUnknown_0202BEFC];
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

static void sub_5E60(void)
{
    gUnknown_0202C5F0[0] = 0xDDDD;
    gUnknown_0202C5B4 = 1;
    gUnknown_0201C180 = 1;
    gUnknown_0201B128 = 0;
    gUnknown_0201C1BC = 0;
    gUnknown_0202C544 = 0;
    gUnknown_0202BECC = 0;
}

static s16 sub_5EA4(void)
{
    s16 result;

    if (gLink.isMaster)
        result = sub_639C();
    else
        result = sub_65DC();

    return result;
}

s16 sub_5EC8(void)
{
    s16 result;

    if (gLink.isMaster)
        result = sub_5EEC();
    else
        result = sub_6144();

    return result;
}

static int sub_5EEC(void)
{
    int i;
    u16 var0;

    if (gUnknown_0201B128 == 0)
    {
        switch (gUnknown_0201C1BC)
        {
            case 0:
                if (JOY_NEW(A_BUTTON))
                {
                    gUnknown_0202C5F0[0] = 0xFEFE;
                }
                else
                {
                    for (i = 0; i < 8; i++)
                        gUnknown_0202C5F0[i] = 0;
                }
                return 0;
            case 1:
                gUnknown_0202C5F0[0] = 0xECEC;
                return 0;
        }
        return 0;
    }
    else if (gUnknown_0201C180 < 8)
    {
        for (i = 0; i < 8; i++)
            gUnknown_0202C5F0[i] = 0xDDDD;
    }
    else if (gUnknown_0201C180 < 16)
    {
        var0 = (gUnknown_0201C180 - 8) * 28;
        gUnknown_0202C5F0[0] = gUnknown_0201C180;
        gUnknown_0202C5F0[1] = gPokedexFlags[var0] |
                               (gPokedexFlags[var0 + 1] << 4) |
                               (gPokedexFlags[var0 + 2] << 8) |
                               (gPokedexFlags[var0 + 3] << 12);
        gUnknown_0202C5F0[2] =  gPokedexFlags[var0 + 4] |
                               (gPokedexFlags[var0 + 5] << 4) |
                               (gPokedexFlags[var0 + 6] << 8) |
                               (gPokedexFlags[var0 + 7] << 12);
        gUnknown_0202C5F0[3] =  gPokedexFlags[var0 + 8] |
                               (gPokedexFlags[var0 + 9] << 4) |
                               (gPokedexFlags[var0 + 10] << 8) |
                               (gPokedexFlags[var0 + 11] << 12);
        gUnknown_0202C5F0[4] =  gPokedexFlags[var0 + 12] |
                               (gPokedexFlags[var0 + 13] << 4) |
                               (gPokedexFlags[var0 + 14] << 8) |
                               (gPokedexFlags[var0 + 15] << 12);
        gUnknown_0202C5F0[5] =  gPokedexFlags[var0 + 16] |
                               (gPokedexFlags[var0 + 17] << 4) |
                               (gPokedexFlags[var0 + 18] << 8) |
                               (gPokedexFlags[var0 + 19] << 12);
        gUnknown_0202C5F0[6] =  gPokedexFlags[var0 + 20] |
                               (gPokedexFlags[var0 + 21] << 4) |
                               (gPokedexFlags[var0 + 22] << 8) |
                               (gPokedexFlags[var0 + 23] << 12);
        gUnknown_0202C5F0[7] =  gPokedexFlags[var0 + 24] |
                               (gPokedexFlags[var0 + 25] << 4) |
                               (gPokedexFlags[var0 + 26] << 8) |
                               (gPokedexFlags[var0 + 27] << 12);
    }
    else
    {
        for (i = 0; i < 8; i++)
            gUnknown_0202C5F0[i] = 0;
    }

    gUnknown_0201C180++;
    return 0;
}

static int sub_6144(void)
{
    int i;
    u16 var0;

    if (gUnknown_0201B128 == 0)
    {
        switch (gUnknown_0202C544)
        {
            case 0:
                if (JOY_NEW(A_BUTTON))
                {
                    gUnknown_0202C5F0[0] = 0xFEFE;
                }
                else
                {
                    for (i = 0; i < 8; i++)
                        gUnknown_0202C5F0[i] = 0;
                }
                return 0;
            case 1:
                gUnknown_0202C5F0[0] = 0xECEC;
                return 0;
        }
        return 0;
    }
    else if (gUnknown_0201C180 < 8)
    {
        for (i = 0; i < 8; i++)
            gUnknown_0202C5F0[i] = 0xDDDD;
    }
    else if (gUnknown_0201C180 < 16)
    {
        var0 = (gUnknown_0201C180 - 8) * 28;
        gUnknown_0202C5F0[0] = gUnknown_0201C180;
        gUnknown_0202C5F0[1] = gPokedexFlags[var0] |
                               (gPokedexFlags[var0 + 1] << 4) |
                               (gPokedexFlags[var0 + 2] << 8) |
                               (gPokedexFlags[var0 + 3] << 12);
        gUnknown_0202C5F0[2] =  gPokedexFlags[var0 + 4] |
                               (gPokedexFlags[var0 + 5] << 4) |
                               (gPokedexFlags[var0 + 6] << 8) |
                               (gPokedexFlags[var0 + 7] << 12);
        gUnknown_0202C5F0[3] =  gPokedexFlags[var0 + 8] |
                               (gPokedexFlags[var0 + 9] << 4) |
                               (gPokedexFlags[var0 + 10] << 8) |
                               (gPokedexFlags[var0 + 11] << 12);
        gUnknown_0202C5F0[4] =  gPokedexFlags[var0 + 12] |
                               (gPokedexFlags[var0 + 13] << 4) |
                               (gPokedexFlags[var0 + 14] << 8) |
                               (gPokedexFlags[var0 + 15] << 12);
        gUnknown_0202C5F0[5] =  gPokedexFlags[var0 + 16] |
                               (gPokedexFlags[var0 + 17] << 4) |
                               (gPokedexFlags[var0 + 18] << 8) |
                               (gPokedexFlags[var0 + 19] << 12);
        gUnknown_0202C5F0[6] =  gPokedexFlags[var0 + 20] |
                               (gPokedexFlags[var0 + 21] << 4) |
                               (gPokedexFlags[var0 + 22] << 8) |
                               (gPokedexFlags[var0 + 23] << 12);
        gUnknown_0202C5F0[7] =  gPokedexFlags[var0 + 24] |
                               (gPokedexFlags[var0 + 25] << 4) |
                               (gPokedexFlags[var0 + 26] << 8) |
                               (gPokedexFlags[var0 + 27] << 12);
    }
    else
    {
        for (i = 0; i < 8; i++)
            gUnknown_0202C5F0[i] = 0;
    }

    gUnknown_0201C180++;
    return 0;
}

int sub_639C(void)
{
    int i, j;
    u16 var0;
    u16 arr0[28];

    if (gUnknown_0201B128 == 0)
    {
        switch (gUnknown_0201C1BC)
        {
            case 0:
                if (gUnknown_0201A4D0[0][0] == 0xFEFE || gUnknown_0201A4D0[0][1] == 0xFEFE)
                {
                    gUnknown_0201C1BC = 1;
                }
                break;
            case 1:
                if (gUnknown_0201A4D0[0][0] == 0xECEC && gUnknown_0201A4D0[0][1] == 0xECEC)
                {
                    gUnknown_0201B128 = -1;
                    gUnknown_0202BEFC = 1;
                    gUnknown_0201C180 = 1;
                }
                else if (++gUnknown_0202BECC > 10)
                {
                    return 1;
                }
                break;
        }
    }
    else
    {
        u16 var1 = gUnknown_0201A4D0[0][1] - 8;
         if (var1 > 7)
            return 0;

        gUnknown_0202C5B4 = gUnknown_0201A4D0[0][1];
        arr0[0]  =  gUnknown_0201A4D0[0][3]  & 0xF;
        arr0[1]  = (gUnknown_0201A4D0[0][3]  & 0xF0)   >> 4;
        arr0[2]  = (gUnknown_0201A4D0[0][3]  & 0xF00)  >> 8;
        arr0[3]  = (gUnknown_0201A4D0[0][3]  & 0xF000) >> 12;
        arr0[4]  =  gUnknown_0201A4D0[0][5]  & 0xF;
        arr0[5]  = (gUnknown_0201A4D0[0][5]  & 0xF0)   >> 4;
        arr0[6]  = (gUnknown_0201A4D0[0][5]  & 0xF00)  >> 8;
        arr0[7]  = (gUnknown_0201A4D0[0][5]  & 0xF000) >> 12;
        arr0[8]  =  gUnknown_0201A4D0[0][7]  & 0xF;
        arr0[9]  = (gUnknown_0201A4D0[0][7]  & 0xF0)   >> 4;
        arr0[10] = (gUnknown_0201A4D0[0][7]  & 0xF00)  >> 8;
        arr0[11] = (gUnknown_0201A4D0[0][7]  & 0xF000) >> 12;
        arr0[12] =  gUnknown_0201A4D0[0][9]  & 0xF;
        arr0[13] = (gUnknown_0201A4D0[0][9]  & 0xF0)   >> 4;
        arr0[14] = (gUnknown_0201A4D0[0][9]  & 0xF00)  >> 8;
        arr0[15] = (gUnknown_0201A4D0[0][9]  & 0xF000) >> 12;
        arr0[16] =  gUnknown_0201A4D0[0][11] & 0xF;
        arr0[17] = (gUnknown_0201A4D0[0][11] & 0xF0)   >> 4;
        arr0[18] = (gUnknown_0201A4D0[0][11] & 0xF00)  >> 8;
        arr0[19] = (gUnknown_0201A4D0[0][11] & 0xF000) >> 12;
        arr0[20] =  gUnknown_0201A4D0[0][13] & 0xF;
        arr0[21] = (gUnknown_0201A4D0[0][13] & 0xF0)   >> 4;
        arr0[22] = (gUnknown_0201A4D0[0][13] & 0xF00)  >> 8;
        arr0[23] = (gUnknown_0201A4D0[0][13] & 0xF000) >> 12;
        arr0[24] =  gUnknown_0201A4D0[0][15] & 0xF;
        arr0[25] = (gUnknown_0201A4D0[0][15] & 0xF0)   >> 4;
        arr0[26] = (gUnknown_0201A4D0[0][15] & 0xF00)  >> 8;
        arr0[27] = (gUnknown_0201A4D0[0][15] & 0xF000) >> 12;

        for (i = 0; i < 28; i++)
        {
            var0 = (gUnknown_0202C5B4 - 8) * 28 + i;
            if (gPokedexFlags[var0] == SPECIES_UNSEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED;
            else if (gPokedexFlags[var0] == SPECIES_SEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED_AND_SEEN;
        }

        if (gUnknown_0202C5B4 == 15)
            return -1;
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 2; j++)
            gUnknown_0201A4D0[i][j] = 0;
    }

    return 0;
}

static int sub_65DC(void)
{
    int i, j;
    u16 var0;
    u16 arr0[28];

    if (gUnknown_0201B128 == 0)
    {
        switch (gUnknown_0202C544)
        {
            case 0:
                if (gUnknown_0201A4D0[0][0] == 0xFEFE || gUnknown_0201A4D0[0][1] == 0xFEFE)
                {
                    gUnknown_0202C544 = 1;
                }
                break;
            case 1:
                if (gUnknown_0201A4D0[0][0] == 0xECEC && gUnknown_0201A4D0[0][1] == 0xECEC)
                {
                    gUnknown_0201B128 = -1;
                    gUnknown_0202BEFC = 1;
                    gUnknown_0201C180 = 1;
                }
                else if (++gUnknown_0202BECC > 10)
                {
                    return 1;
                }
                break;
        }
    }
    else
    {
        u16 var1 = gUnknown_0201A4D0[0][0] - 8;
         if (var1 > 7)
            return 0;

        gUnknown_0202C5B4 = gUnknown_0201A4D0[0][0];
        arr0[0]  =  gUnknown_0201A4D0[0][2]  & 0xF;
        arr0[1]  = (gUnknown_0201A4D0[0][2]  & 0xF0)   >> 4;
        arr0[2]  = (gUnknown_0201A4D0[0][2]  & 0xF00)  >> 8;
        arr0[3]  = (gUnknown_0201A4D0[0][2]  & 0xF000) >> 12;
        arr0[4]  =  gUnknown_0201A4D0[0][4]  & 0xF;
        arr0[5]  = (gUnknown_0201A4D0[0][4]  & 0xF0)   >> 4;
        arr0[6]  = (gUnknown_0201A4D0[0][4]  & 0xF00)  >> 8;
        arr0[7]  = (gUnknown_0201A4D0[0][4]  & 0xF000) >> 12;
        arr0[8]  =  gUnknown_0201A4D0[0][6]  & 0xF;
        arr0[9]  = (gUnknown_0201A4D0[0][6]  & 0xF0)   >> 4;
        arr0[10] = (gUnknown_0201A4D0[0][6]  & 0xF00)  >> 8;
        arr0[11] = (gUnknown_0201A4D0[0][6]  & 0xF000) >> 12;
        arr0[12] =  gUnknown_0201A4D0[0][8]  & 0xF;
        arr0[13] = (gUnknown_0201A4D0[0][8]  & 0xF0)   >> 4;
        arr0[14] = (gUnknown_0201A4D0[0][8]  & 0xF00)  >> 8;
        arr0[15] = (gUnknown_0201A4D0[0][8]  & 0xF000) >> 12;
        arr0[16] =  gUnknown_0201A4D0[0][10] & 0xF;
        arr0[17] = (gUnknown_0201A4D0[0][10] & 0xF0)   >> 4;
        arr0[18] = (gUnknown_0201A4D0[0][10] & 0xF00)  >> 8;
        arr0[19] = (gUnknown_0201A4D0[0][10] & 0xF000) >> 12;
        arr0[20] =  gUnknown_0201A4D0[0][12] & 0xF;
        arr0[21] = (gUnknown_0201A4D0[0][12] & 0xF0)   >> 4;
        arr0[22] = (gUnknown_0201A4D0[0][12] & 0xF00)  >> 8;
        arr0[23] = (gUnknown_0201A4D0[0][12] & 0xF000) >> 12;
        arr0[24] =  gUnknown_0201A4D0[0][14] & 0xF;
        arr0[25] = (gUnknown_0201A4D0[0][14] & 0xF0)   >> 4;
        arr0[26] = (gUnknown_0201A4D0[0][14] & 0xF00)  >> 8;
        arr0[27] = (gUnknown_0201A4D0[0][14] & 0xF000) >> 12;

        for (i = 0; i < 28; i++)
        {
            var0 = (gUnknown_0202C5B4 - 8) * 28 + i;
            if (gPokedexFlags[var0] == SPECIES_UNSEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED;
            else if (gPokedexFlags[var0] == SPECIES_SEEN && arr0[i] == 4)
                gPokedexFlagExchangeBuffer[var0] = SPECIES_SHARED_AND_SEEN;
        }

        if (gUnknown_0202C5B4 == 15)
            return -1;
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 2; j++)
            gUnknown_0201A4D0[i][j] = 0;
    }

    return 0;
}

static void PrintSelectedMonDexNum(s16 species)
{
    int i;
    int var0;
    u16 var1;
    u16 var2;

    DmaFill16(3, 0, gUnknown_03000000, 0x800);
    var0 = 0;
    if (species == SPECIES_JIRACHI)
    {
        if (gPokedexFlags[SPECIES_JIRACHI] != SPECIES_UNSEEN)
        {
            PrintChar(CHAR_2_FONT_1, 1, 5, 2, 1, 2);
            PrintChar(CHAR_0_FONT_1, 1, 6, 2, 1, 2);
            PrintChar(CHAR_1_FONT_1, 1, 7, 2, 1, 2);
        }
        else
        {
            PrintChar(CHAR_SPACE_FONT_1, 1, 5, 2, 1, 2);
            PrintChar(CHAR_SPACE_FONT_1, 1, 6, 2, 1, 2);
            PrintChar(CHAR_SPACE_FONT_1, 1, 7, 2, 1, 2);
        }
    }
    else
    {
        // Dex number of the selected species
        for (i = 0; i < DEX_NUM_DIGITS; i++)
            PrintChar(gPokedexEntries[species].dexNum[i] + 32, 1, i + 5, 2, 1, 2);
    }

    if (gPokedexFlags[species] > SPECIES_UNSEEN)
    {
        for (i = 0; i < POKEMON_NAME_LENGTH; i++)
        {
            var1 = gPokedexEntries[species].name[i] & ~0xF;
            var2 = gPokedexEntries[species].name[i] & 0xF;
            if (var2 == 0)
                var2 = 4;

            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gUnknown_0202BE30, 0x20);
            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1 + 0x400], gUnknown_0201B130, 0x20);
            sub_71DC(var2, var0, 0);
            var0 += var2;
        }

        sub_10708(gUnknown_03000000, (void *)0x06004C00, 8, 2);
        DmaFill16(3, 0, gUnknown_03000000, 0x800);
        var0 = 0;
    }
    else
    {
        for (i = 0; i < 10; i++)
            sub_10708((void *)&gPokedexTextGlyphs_Gfx[ENGLISH_GLYPHS_START], (void *)0x06004C00 + i * 0x20, 1, 2);
    }

    if (gPokedexFlags[species] == SPECIES_SEEN || gPokedexFlags[species] > SPECIES_SHARED)
    {
        for (i = 0; i < POKEMON_CATEGORY_NAME_LENGTH; i++)
        {
            var1 = gPokedexEntries[species].category[i] & ~0xF;
            var2 = gPokedexEntries[species].category[i] & 0xF;
            if (var2 == 0)
                var2 = 6;

            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gUnknown_0202BE30, 0x20);
            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[0x400 + var1], gUnknown_0201B130, 0x20);
            sub_71DC(var2, var0, 0);
            var0 += var2;
        }

        sub_10708(gUnknown_03000000, (void *)0x06004D00, 9, 2);
        DmaFill16(3, 0, gUnknown_03000000, 0x800);
    }
    else
    {
        for (i = 0; i < 9; i++)
            sub_10708((void *)&gPokedexTextGlyphs_Gfx[ENGLISH_GLYPHS_START], (void *)0x06004D00 + i * 0x20, 1, 2);
    }

    if (gPokedexFlags[species] == SPECIES_CAUGHT)
    {
        PrintChar(gPokedexEntries[species].heightWeight[0] + 32, 1, 16, 6, 1, 2);
        PrintChar(gPokedexEntries[species].heightWeight[1] + 32, 1, 17, 6, 1, 2);
        PrintChar(gPokedexEntries[species].heightWeight[2] + 32, 1, 19, 6, 1, 2);
        PrintChar(gPokedexEntries[species].heightWeight[3] + 32, 1, 20, 6, 1, 2);
        for (i = 0; i < POKEMON_HEIGHT_WEIGHT_TEXT_LENGTH - 4; i++)
            PrintChar(gPokedexEntries[species].heightWeight[4 + i], 1, i + 16, 8, 1, 1);
    }
    else
    {
        PrintChar(CHAR_DASH_FONT_1, 1, 16, 6, 1, 2);
        PrintChar(CHAR_DASH_FONT_1, 1, 17, 6, 1, 2);
        PrintChar(CHAR_DASH_FONT_1, 1, 19, 6, 1, 2);
        PrintChar(CHAR_DASH_FONT_1, 1, 20, 6, 1, 2);
        for (i = 0; i < POKEMON_HEIGHT_WEIGHT_TEXT_LENGTH - 4; i++)
            PrintChar(CHAR_DASH_FONT_0, 1, i + 16, 8, 1, 1);
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
        PrintChar(seenDigits[i], 2, i + 25, 15, 1, 1);
        PrintChar(ownedDigits[i] + 32, 2, i + 25, 16, 1, 2);
    }
}

void PrintDexNumbersFromListPosition(s16 listPosition)
{
    int i, j;
    int var0;
    u16 var1;
    u16 var2;

    DmaFill16(3, 0, gUnknown_03000000, 0x800);
    var0 = 0;
    for (i = 0; i < ENTRIES_SHOWN_COUNT; i++)
    {
        if (listPosition + i == SPECIES_JIRACHI)
        {
            if (gPokedexFlags[SPECIES_JIRACHI] != SPECIES_UNSEEN)
            {
                PrintChar(CHAR_2_FONT_1, 2, 8, i * 2 + 10, 1, 2);
                PrintChar(CHAR_0_FONT_1, 2, 9, i * 2 + 10, 1, 2);
                PrintChar(CHAR_1_FONT_1, 2, 10, i * 2 + 10, 1, 2);
            }
            else
            {
                PrintChar(CHAR_SPACE_FONT_1, 2, 8, i * 2 + 10, 1, 2);
                PrintChar(CHAR_SPACE_FONT_1, 2, 9, i * 2 + 10, 1, 2);
                PrintChar(CHAR_SPACE_FONT_1, 2, 10, i * 2 + 10, 1, 2);
            }
        }
        else
        {
            // Doesn't use listPosition for some reason, despite being the only value passed
            for (j = 0; j < DEX_NUM_DIGITS; j++)
                PrintChar(gPokedexEntries[gPokedexListPosition + i].dexNum[j] + 32, 2, j + 8, i * 2 + 10, 1, 2);
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

                DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gUnknown_0202BE30, 0x20);
                DmaCopy16(3, &gPokedexTextGlyphs_Gfx[0x400 + var1], gUnknown_0201B130, 0x20);
                sub_71DC(var2, var0, 0);
                var0 += var2;
            }

            sub_10708(gUnknown_03000000, (void *)0x06000000 + gUnknown_086A64F0[i], 8, 2);
            DmaFill16(3, 0, gUnknown_03000000, 0x800);
            var0 = 0;
        }
        else
        {
            for (j = 0; j < 7; j++)
                sub_10708((void *)&gPokedexTextGlyphs_Gfx[ENGLISH_GLYPHS_START], (void *)0x06000000 + gUnknown_086A64F0[i] + j * 0x20, 1, 2);
        
            sub_10708((void *)gPokedexTextGlyphs_Gfx, (void *)0x06000000 + gUnknown_086A64F0[i] + j * 0x20, 1, 2);
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
        PrintChar(var0, 1, 4, 10 + i * 2, 2, 2);
    }
}

void sub_6F78(s16 species)
{
    s16 state = gPokedexFlags[gPokedexSelectedMon];
    s16 var1 = species / 15;
    s16 var2 = species % 15;
    switch (state)
    {
        case SPECIES_UNSEEN:
            sub_10708(gPokedexSprites_Gfx + 0x5C00, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gPokedexSprites_Pals, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
        case SPECIES_SEEN:
            sub_10708(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gMonPortraitGroupPals[0] + 0x1E0, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
        case SPECIES_SHARED:
        case SPECIES_SHARED_AND_SEEN:
            sub_10708(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            sub_10170(gMonPortraitGroupPals[var1] + var2 * 0x20, (void *)OBJ_PLTT + 0x20, 0x20, 0xE);
            break;
        case SPECIES_CAUGHT:
            sub_10708(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gMonPortraitGroupPals[var1] + var2 * 0x20, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
    }
}

void sub_70E0(s16 species, u32 page)
{
    int i, j;
    int var0;
    u16 var1;
    u16 var2;

    var0 = 0;
    DmaFill16(3, 0, gUnknown_03000000, 0x1800);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 42; j++)
        {
            var1 = gPokedexEntries[species].description[page * 126 + i * 42 + j] & ~0xF;
            var2 = gPokedexEntries[species].description[page * 126 + i * 42 + j] & 0xF;
            if (var2 == 0)
                var2 = 4;

            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[var1], gUnknown_0202BE30, 0x20);
            DmaCopy16(3, &gPokedexTextGlyphs_Gfx[0x400 + var1], gUnknown_0201B130, 0x20);
            sub_71DC(var2, var0, i);
            var0 += var2;
        }

        var0 = 0;
    }

    DmaCopy16(3, gUnknown_03000000, (void *)VRAM + 0x5C00, 0x1800);
}

// void sub_71DC(int arg0, int arg1, int arg2)
// {
//     int i;
//     int var0;
//     int var1;

//     var0 = arg1;
//     if (var0 < 0)
//         var0 += 7;
    
//     var1 = (var0 / 8) * 16 + (arg2 * 0x400);
//     switch (arg0)
//     {
//     case 6:
//         // _08007228
//         var0 = arg1;
//         if (arg1 < 0)
//             var0 += 7;
        
//         var0 = arg1 - (var0 / 8) * 8;

//         // _0800723E
//         switch (var0)
//         {
//         case 0:
//             for (i = 0; i < 8; i++)
//             {
//                 gUnknown_03000000[i * 2 + var1 + 0x000] |= gUnknown_0202BE30[i * 2];
//                 gUnknown_03000000[i * 2 + var1 + 0x001] |= gUnknown_0202BE30[i * 2 + 1] & 0xFF;
//                 gUnknown_03000000[i * 2 + var1 + 0x200] |= gUnknown_0201B130[i * 2];
//                 gUnknown_03000000[i * 2 + var1 + 0x201] |= gUnknown_0201B130[i * 2 + 1] & 0xFF;
//             }
//             break;
//         case 1:
//             for (i = 0; i < 8; i++)
//             {
//                 gUnknown_03000000[i * 2 + var1 + 0x000] |= (gUnknown_0202BE30[i * 2] & 0xFFF) << 4;
//                 // gUnknown_03000000[i * 2 + var1 + 0x001] |= (u8)gUnknown_0202BE30[i * 2 + 1];
//                 // gUnknown_03000000[i * 2 + var1 + 0x200] |=     gUnknown_0201B130[i * 2];
//                 // gUnknown_03000000[i * 2 + var1 + 0x201] |= (u8)gUnknown_0201B130[i * 2 + 1];
//             }
//             break;
//         case 2:
//             break;
//         case 3:
//             break;
//         case 4:
//             break;
//         case 5:
//             break;
//         case 6:
//             break;
//         case 7:
//             break;
//         }
//         break;
//     case 5:
//         break;
//     case 4:
//         break;
//     case 3:
//         break;
//     case 2:
//         break;
//     }
// }

NAKED
void sub_71DC(int arg0, int arg1, int arg2)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x14\n\
	adds r4, r0, #0\n\
	adds r3, r1, #0\n\
	adds r0, r3, #0\n\
	cmp r3, #0\n\
	bge _080071F4\n\
	adds r0, r3, #7\n\
_080071F4:\n\
	asrs r0, r0, #3\n\
	lsls r0, r0, #4\n\
	lsls r1, r2, #0xa\n\
	adds r2, r0, r1\n\
	subs r0, r4, #2\n\
	cmp r0, #4\n\
	bls _08007206\n\
	bl _080088C8\n\
_08007206:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08007210 @ =_08007214\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08007210: .4byte _08007214\n\
_08007214: @ jump table\n\
	.4byte _08008580 @ case 0\n\
	.4byte _0800819C @ case 1\n\
	.4byte _08007D50 @ case 2\n\
	.4byte _0800780C @ case 3\n\
	.4byte _08007228 @ case 4\n\
_08007228:\n\
	adds r0, r3, #0\n\
	cmp r3, #0\n\
	bge _08007230\n\
	adds r0, r3, #7\n\
_08007230:\n\
	asrs r0, r0, #3\n\
	lsls r0, r0, #3\n\
	subs r0, r3, r0\n\
	cmp r0, #7\n\
	bls _0800723E\n\
	bl _080088C8\n\
_0800723E:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08007248 @ =_0800724C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08007248: .4byte _0800724C\n\
_0800724C: @ jump table\n\
	.4byte _0800726C @ case 0\n\
	.4byte _080072EC @ case 1\n\
	.4byte _08007398 @ case 2\n\
	.4byte _0800744C @ case 3\n\
	.4byte _08007548 @ case 4\n\
	.4byte _080075C0 @ case 5\n\
	.4byte _0800766C @ case 6\n\
	.4byte _08007714 @ case 7\n\
_0800726C:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	ldr r1, _080072E0 @ =gUnknown_03000000\n\
	mov sb, r1\n\
	movs r0, #0xff\n\
	mov sl, r0\n\
	ldr r1, _080072E4 @ =gUnknown_0201B130\n\
	mov r8, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r5, r0, r2\n\
	ldr r6, _080072E8 @ =gUnknown_0202BE30\n\
	lsls r1, r1, #1\n\
	adds r4, r1, r2\n\
_08007290:\n\
	lsls r3, r7, #1\n\
	ldrh r0, [r5]\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	ldrh r1, [r6, #2]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldrh r0, [r4]\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r3, r3, r0\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r2, #2]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r1, #4\n\
	add r8, r1\n\
	adds r4, #4\n\
	adds r5, #4\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007290\n\
	bl _080088C8\n\
	.align 2, 0\n\
_080072E0: .4byte gUnknown_03000000\n\
_080072E4: .4byte gUnknown_0201B130\n\
_080072E8: .4byte gUnknown_0202BE30\n\
_080072EC:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	ldr r1, _08007388 @ =gUnknown_03000000\n\
	mov sl, r1\n\
	ldr r0, _0800738C @ =gUnknown_0201B130\n\
	mov sb, r0\n\
	ldr r1, _08007390 @ =gUnknown_0202BE30\n\
	mov r8, r1\n\
	lsls r0, r2, #1\n\
	mov r2, sl\n\
	adds r6, r0, r2\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	adds r5, r0, r2\n\
_0800730C:\n\
	lsls r4, r7, #1\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	ldr r0, _08007394 @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r4, ip\n\
	lsls r3, r4, #1\n\
	add r3, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r3]\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	mov r0, sb\n\
	ldrh r1, [r0]\n\
	ldr r0, _08007394 @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #1\n\
	add r4, sl\n\
	mov r2, sb\n\
	ldrh r0, [r2]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r0, #4\n\
	add sb, r0\n\
	add r8, r0\n\
	adds r6, #4\n\
	adds r5, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800730C\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007388: .4byte gUnknown_03000000\n\
_0800738C: .4byte gUnknown_0201B130\n\
_08007390: .4byte gUnknown_0202BE30\n\
_08007394: .4byte 0x00000FFF\n\
_08007398:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	movs r0, #0xff\n\
	mov sl, r0\n\
	ldr r1, _08007440 @ =gUnknown_0201B130\n\
	mov sb, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08007444 @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r0, r2, #1\n\
	ldr r2, _08007448 @ =gUnknown_03000000\n\
	adds r6, r0, r2\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_080073BA:\n\
	lsls r4, r7, #1\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r4, ip\n\
	lsls r3, r4, #1\n\
	ldr r1, _08007448 @ =gUnknown_03000000\n\
	adds r3, r3, r1\n\
	mov r2, r8\n\
	ldrh r0, [r2]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	ldrh r2, [r2, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r3]\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	mov r0, sb\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #1\n\
	ldr r2, _08007448 @ =gUnknown_03000000\n\
	adds r4, r4, r2\n\
	mov r1, sb\n\
	ldrh r0, [r1]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	mov r0, sb\n\
	ldrh r2, [r0, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r1, #4\n\
	add sb, r1\n\
	adds r5, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080073BA\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007440: .4byte gUnknown_0201B130\n\
_08007444: .4byte gUnknown_0202BE30\n\
_08007448: .4byte gUnknown_03000000\n\
_0800744C:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	movs r1, #0x10\n\
	adds r1, r1, r2\n\
	mov sb, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #2\n\
	str r0, [sp, #8]\n\
	ldr r0, _08007538 @ =gUnknown_0202BE30\n\
	mov sl, r0\n\
	lsls r0, r2, #1\n\
	ldr r2, _0800753C @ =gUnknown_03000000\n\
	adds r0, r0, r2\n\
	mov r8, r0\n\
	ldr r0, _08007540 @ =gUnknown_0201B130\n\
	str r0, [sp, #0x10]\n\
	lsls r1, r1, #1\n\
	adds r6, r1, r2\n\
_08007476:\n\
	lsls r5, r7, #1\n\
	mov r2, sl\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	mov r0, ip\n\
	adds r4, r5, r0\n\
	lsls r3, r4, #1\n\
	ldr r1, _0800753C @ =gUnknown_03000000\n\
	adds r3, r3, r1\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	ldr r1, _08007544 @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r3]\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	add r5, sb\n\
	lsls r2, r5, #1\n\
	ldr r0, _0800753C @ =gUnknown_03000000\n\
	adds r2, r2, r0\n\
	mov r0, sl\n\
	ldrh r1, [r0, #2]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, [sp, #0x10]\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #1\n\
	ldr r1, _0800753C @ =gUnknown_03000000\n\
	adds r4, r4, r1\n\
	ldrh r0, [r2]\n\
	ldr r1, _08007544 @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	ldr r2, [sp, #8]\n\
	ldr r0, _08007540 @ =gUnknown_0201B130\n\
	adds r3, r2, r0\n\
	ldrh r2, [r3]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r5, r5, r1\n\
	lsls r5, r5, #1\n\
	ldr r2, _0800753C @ =gUnknown_03000000\n\
	adds r5, r5, r2\n\
	ldrh r1, [r3]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	adds r6, #4\n\
	ldr r0, [sp, #8]\n\
	adds r0, #4\n\
	str r0, [sp, #8]\n\
	movs r1, #4\n\
	add sl, r1\n\
	add r8, r1\n\
	ldr r2, [sp, #0x10]\n\
	adds r2, #4\n\
	str r2, [sp, #0x10]\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007476\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007538: .4byte gUnknown_0202BE30\n\
_0800753C: .4byte gUnknown_03000000\n\
_08007540: .4byte gUnknown_0201B130\n\
_08007544: .4byte 0x0000FFF0\n\
_08007548:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _080075B4 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _080075B8 @ =gUnknown_0201B130\n\
	ldr r5, _080075BC @ =gUnknown_0202BE30\n\
_08007560:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	ldrh r0, [r2]\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r5, #2]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldrh r0, [r3]\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r6, #2]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r5, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007560\n\
	bl _080088C8\n\
	.align 2, 0\n\
_080075B4: .4byte gUnknown_03000000\n\
_080075B8: .4byte gUnknown_0201B130\n\
_080075BC: .4byte gUnknown_0202BE30\n\
_080075C0:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r2, _0800765C @ =gUnknown_03000000\n\
	mov sl, r2\n\
	ldr r0, _08007660 @ =gUnknown_0201B130\n\
	mov r8, r0\n\
	ldr r6, _08007664 @ =gUnknown_0202BE30\n\
_080075D4:\n\
	lsls r5, r7, #1\n\
	mov r1, ip\n\
	adds r3, r5, r1\n\
	lsls r2, r3, #1\n\
	add r2, sl\n\
	ldrh r1, [r6]\n\
	ldr r0, _08007668 @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r5, sb\n\
	lsls r4, r5, #1\n\
	add r4, sl\n\
	ldrh r0, [r6]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	ldrh r2, [r6, #2]\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sl\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	ldr r0, _08007668 @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, r5, r2\n\
	lsls r5, r5, #1\n\
	add r5, sl\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	mov r0, r8\n\
	ldrh r2, [r0, #2]\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r5]\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	movs r1, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080075D4\n\
	bl _080088C8\n\
	.align 2, 0\n\
_0800765C: .4byte gUnknown_03000000\n\
_08007660: .4byte gUnknown_0201B130\n\
_08007664: .4byte gUnknown_0202BE30\n\
_08007668: .4byte 0x00000FFF\n\
_0800766C:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _08007708 @ =gUnknown_03000000\n\
	mov sl, r1\n\
	ldr r2, _0800770C @ =gUnknown_0201B130\n\
	mov r8, r2\n\
	ldr r6, _08007710 @ =gUnknown_0202BE30\n\
_08007680:\n\
	lsls r5, r7, #1\n\
	mov r0, ip\n\
	adds r3, r5, r0\n\
	lsls r2, r3, #1\n\
	add r2, sl\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r5, sb\n\
	lsls r4, r5, #1\n\
	add r4, sl\n\
	ldrh r0, [r6]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	ldrh r2, [r6, #2]\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r3, r3, r1\n\
	lsls r3, r3, #1\n\
	add r3, sl\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r5, r5, r0\n\
	lsls r5, r5, #1\n\
	add r5, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r5]\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	movs r1, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007680\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007708: .4byte gUnknown_03000000\n\
_0800770C: .4byte gUnknown_0201B130\n\
_08007710: .4byte gUnknown_0202BE30\n\
_08007714:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	movs r1, #0x10\n\
	adds r1, r1, r2\n\
	mov sb, r1\n\
	adds r2, #0x11\n\
	str r2, [sp]\n\
	ldr r2, _080077FC @ =gUnknown_03000000\n\
	mov sl, r2\n\
	movs r0, #2\n\
	str r0, [sp, #4]\n\
	ldr r1, _08007800 @ =gUnknown_0202BE30\n\
	mov r8, r1\n\
	ldr r2, _08007804 @ =gUnknown_0201B130\n\
	str r2, [sp, #0xc]\n\
_08007734:\n\
	lsls r6, r7, #1\n\
	mov r0, ip\n\
	adds r4, r6, r0\n\
	lsls r2, r4, #1\n\
	add r2, sl\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	mov r1, sb\n\
	adds r5, r6, r1\n\
	lsls r3, r5, #1\n\
	add r3, sl\n\
	mov r2, r8\n\
	ldrh r0, [r2]\n\
	ldr r1, _08007808 @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r3]\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	ldr r0, [sp]\n\
	adds r6, r6, r0\n\
	lsls r2, r6, #1\n\
	add r2, sl\n\
	mov r0, r8\n\
	ldrh r1, [r0, #2]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #1\n\
	add r4, sl\n\
	ldr r2, [sp, #0xc]\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r5, r5, r0\n\
	lsls r5, r5, #1\n\
	add r5, sl\n\
	ldrh r0, [r2]\n\
	ldr r1, _08007808 @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	ldr r2, [sp, #4]\n\
	ldr r0, _08007804 @ =gUnknown_0201B130\n\
	adds r3, r2, r0\n\
	ldrh r2, [r3]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r5]\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r6, r6, r1\n\
	lsls r6, r6, #1\n\
	add r6, sl\n\
	ldrh r1, [r3]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	ldr r2, [sp, #4]\n\
	adds r2, #4\n\
	str r2, [sp, #4]\n\
	movs r0, #4\n\
	add r8, r0\n\
	ldr r1, [sp, #0xc]\n\
	adds r1, #4\n\
	str r1, [sp, #0xc]\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007734\n\
	bl _080088C8\n\
	.align 2, 0\n\
_080077FC: .4byte gUnknown_03000000\n\
_08007800: .4byte gUnknown_0202BE30\n\
_08007804: .4byte gUnknown_0201B130\n\
_08007808: .4byte 0x0000FFF0\n\
_0800780C:\n\
	adds r0, r3, #0\n\
	cmp r3, #0\n\
	bge _08007814\n\
	adds r0, r3, #7\n\
_08007814:\n\
	asrs r0, r0, #3\n\
	lsls r0, r0, #3\n\
	subs r0, r3, r0\n\
	cmp r0, #7\n\
	bls _08007822\n\
	bl _080088C8\n\
_08007822:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0800782C @ =_08007830\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0800782C: .4byte _08007830\n\
_08007830: @ jump table\n\
	.4byte _08007850 @ case 0\n\
	.4byte _080078D0 @ case 1\n\
	.4byte _0800797C @ case 2\n\
	.4byte _08007A28 @ case 3\n\
	.4byte _08007ADC @ case 4\n\
	.4byte _08007B54 @ case 5\n\
	.4byte _08007C00 @ case 6\n\
	.4byte _08007CA8 @ case 7\n\
_08007850:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	ldr r1, _080078C4 @ =gUnknown_03000000\n\
	mov sb, r1\n\
	movs r0, #0xf\n\
	mov sl, r0\n\
	ldr r1, _080078C8 @ =gUnknown_0201B130\n\
	mov r8, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r5, r0, r2\n\
	ldr r6, _080078CC @ =gUnknown_0202BE30\n\
	lsls r1, r1, #1\n\
	adds r4, r1, r2\n\
_08007874:\n\
	lsls r3, r7, #1\n\
	ldrh r0, [r5]\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	ldrh r1, [r6, #2]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldrh r0, [r4]\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r3, r3, r0\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r2, #2]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r1, #4\n\
	add r8, r1\n\
	adds r4, #4\n\
	adds r5, #4\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007874\n\
	bl _080088C8\n\
	.align 2, 0\n\
_080078C4: .4byte gUnknown_03000000\n\
_080078C8: .4byte gUnknown_0201B130\n\
_080078CC: .4byte gUnknown_0202BE30\n\
_080078D0:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	ldr r1, _0800796C @ =gUnknown_03000000\n\
	mov sl, r1\n\
	ldr r0, _08007970 @ =gUnknown_0201B130\n\
	mov sb, r0\n\
	ldr r1, _08007974 @ =gUnknown_0202BE30\n\
	mov r8, r1\n\
	lsls r0, r2, #1\n\
	mov r2, sl\n\
	adds r6, r0, r2\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	adds r5, r0, r2\n\
_080078F0:\n\
	lsls r4, r7, #1\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	ldr r0, _08007978 @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r4, ip\n\
	lsls r3, r4, #1\n\
	add r3, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r3]\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	mov r0, sb\n\
	ldrh r1, [r0]\n\
	ldr r0, _08007978 @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #1\n\
	add r4, sl\n\
	mov r2, sb\n\
	ldrh r0, [r2]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r0, #4\n\
	add sb, r0\n\
	add r8, r0\n\
	adds r6, #4\n\
	adds r5, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080078F0\n\
	bl _080088C8\n\
	.align 2, 0\n\
_0800796C: .4byte gUnknown_03000000\n\
_08007970: .4byte gUnknown_0201B130\n\
_08007974: .4byte gUnknown_0202BE30\n\
_08007978: .4byte 0x00000FFF\n\
_0800797C:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	ldr r0, _08007A1C @ =gUnknown_03000000\n\
	mov sl, r0\n\
	ldr r1, _08007A20 @ =gUnknown_0201B130\n\
	mov sb, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08007A24 @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sl\n\
	adds r6, r0, r2\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_0800799E:\n\
	lsls r4, r7, #1\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r4, ip\n\
	lsls r3, r4, #1\n\
	add r3, sl\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	mov r0, r8\n\
	ldrh r2, [r0, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r3]\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	mov r2, sb\n\
	ldrh r1, [r2]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #1\n\
	add r4, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r1, #4\n\
	add sb, r1\n\
	adds r5, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800799E\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007A1C: .4byte gUnknown_03000000\n\
_08007A20: .4byte gUnknown_0201B130\n\
_08007A24: .4byte gUnknown_0202BE30\n\
_08007A28:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	movs r1, #0xf\n\
	mov sl, r1\n\
	ldr r0, _08007ACC @ =gUnknown_0201B130\n\
	mov sb, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08007AD0 @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r0, r2, #1\n\
	ldr r2, _08007AD4 @ =gUnknown_03000000\n\
	adds r6, r0, r2\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_08007A4A:\n\
	lsls r4, r7, #1\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r4, ip\n\
	lsls r3, r4, #1\n\
	ldr r1, _08007AD4 @ =gUnknown_03000000\n\
	adds r3, r3, r1\n\
	mov r2, r8\n\
	ldrh r0, [r2]\n\
	ldr r1, _08007AD8 @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	ldrh r2, [r2, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r3]\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	mov r0, sb\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #1\n\
	ldr r2, _08007AD4 @ =gUnknown_03000000\n\
	adds r4, r4, r2\n\
	mov r1, sb\n\
	ldrh r0, [r1]\n\
	ldr r1, _08007AD8 @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	mov r0, sb\n\
	ldrh r2, [r0, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r1, #4\n\
	add sb, r1\n\
	adds r5, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007A4A\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007ACC: .4byte gUnknown_0201B130\n\
_08007AD0: .4byte gUnknown_0202BE30\n\
_08007AD4: .4byte gUnknown_03000000\n\
_08007AD8: .4byte 0x0000FFF0\n\
_08007ADC:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _08007B48 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _08007B4C @ =gUnknown_0201B130\n\
	ldr r5, _08007B50 @ =gUnknown_0202BE30\n\
_08007AF4:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	ldrh r0, [r2]\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r5, #2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldrh r0, [r3]\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r6, #2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r5, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007AF4\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007B48: .4byte gUnknown_03000000\n\
_08007B4C: .4byte gUnknown_0201B130\n\
_08007B50: .4byte gUnknown_0202BE30\n\
_08007B54:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r2, _08007BF0 @ =gUnknown_03000000\n\
	mov sl, r2\n\
	ldr r0, _08007BF4 @ =gUnknown_0201B130\n\
	mov r8, r0\n\
	ldr r6, _08007BF8 @ =gUnknown_0202BE30\n\
_08007B68:\n\
	lsls r5, r7, #1\n\
	mov r1, ip\n\
	adds r3, r5, r1\n\
	lsls r2, r3, #1\n\
	add r2, sl\n\
	ldrh r1, [r6]\n\
	ldr r0, _08007BFC @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r5, sb\n\
	lsls r4, r5, #1\n\
	add r4, sl\n\
	ldrh r0, [r6]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	ldrh r2, [r6, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sl\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	ldr r0, _08007BFC @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, r5, r2\n\
	lsls r5, r5, #1\n\
	add r5, sl\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #0xc\n\
	mov r0, r8\n\
	ldrh r2, [r0, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	ldrh r0, [r5]\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	movs r1, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007B68\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007BF0: .4byte gUnknown_03000000\n\
_08007BF4: .4byte gUnknown_0201B130\n\
_08007BF8: .4byte gUnknown_0202BE30\n\
_08007BFC: .4byte 0x00000FFF\n\
_08007C00:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _08007C9C @ =gUnknown_03000000\n\
	mov sl, r1\n\
	ldr r2, _08007CA0 @ =gUnknown_0201B130\n\
	mov r8, r2\n\
	ldr r6, _08007CA4 @ =gUnknown_0202BE30\n\
_08007C14:\n\
	lsls r5, r7, #1\n\
	mov r0, ip\n\
	adds r3, r5, r0\n\
	lsls r2, r3, #1\n\
	add r2, sl\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r5, sb\n\
	lsls r4, r5, #1\n\
	add r4, sl\n\
	ldrh r0, [r6]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	ldrh r2, [r6, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r3, r3, r1\n\
	lsls r3, r3, #1\n\
	add r3, sl\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r5, r5, r0\n\
	lsls r5, r5, #1\n\
	add r5, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	lsrs r1, r1, #8\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	ldrh r0, [r5]\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	movs r1, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007C14\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007C9C: .4byte gUnknown_03000000\n\
_08007CA0: .4byte gUnknown_0201B130\n\
_08007CA4: .4byte gUnknown_0202BE30\n\
_08007CA8:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _08007D40 @ =gUnknown_03000000\n\
	mov sl, r1\n\
	ldr r2, _08007D44 @ =gUnknown_0201B130\n\
	mov r8, r2\n\
	ldr r6, _08007D48 @ =gUnknown_0202BE30\n\
_08007CBC:\n\
	lsls r5, r7, #1\n\
	mov r0, ip\n\
	adds r3, r5, r0\n\
	lsls r2, r3, #1\n\
	add r2, sl\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r5, sb\n\
	lsls r4, r5, #1\n\
	add r4, sl\n\
	ldrh r0, [r6]\n\
	ldr r1, _08007D4C @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	ldrh r2, [r6, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r4]\n\
	orrs r1, r0\n\
	strh r1, [r4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r3, r3, r1\n\
	lsls r3, r3, #1\n\
	add r3, sl\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r5, r5, r0\n\
	lsls r5, r5, #1\n\
	add r5, sl\n\
	ldrh r0, [r2]\n\
	ldr r1, _08007D4C @ =0x0000FFF0\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	ldrh r2, [r2, #2]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #0xc\n\
	orrs r1, r0\n\
	ldrh r0, [r5]\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	movs r1, #4\n\
	add r8, r1\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007CBC\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007D40: .4byte gUnknown_03000000\n\
_08007D44: .4byte gUnknown_0201B130\n\
_08007D48: .4byte gUnknown_0202BE30\n\
_08007D4C: .4byte 0x0000FFF0\n\
_08007D50:\n\
	adds r0, r3, #0\n\
	cmp r3, #0\n\
	bge _08007D58\n\
	adds r0, r3, #7\n\
_08007D58:\n\
	asrs r0, r0, #3\n\
	lsls r0, r0, #3\n\
	subs r0, r3, r0\n\
	cmp r0, #7\n\
	bls _08007D66\n\
	bl _080088C8\n\
_08007D66:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08007D70 @ =_08007D74\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08007D70: .4byte _08007D74\n\
_08007D74: @ jump table\n\
	.4byte _08007D94 @ case 0\n\
	.4byte _08007DD8 @ case 1\n\
	.4byte _08007E74 @ case 2\n\
	.4byte _08007F0C @ case 3\n\
	.4byte _08007FA4 @ case 4\n\
	.4byte _08007FF4 @ case 5\n\
	.4byte _08008084 @ case 6\n\
	.4byte _08008110 @ case 7\n\
_08007D94:\n\
	movs r7, #0\n\
	ldr r1, _08007DCC @ =gUnknown_03000000\n\
	lsls r0, r2, #1\n\
	adds r3, r0, r1\n\
	ldr r5, _08007DD0 @ =gUnknown_0202BE30\n\
	ldr r4, _08007DD4 @ =gUnknown_0201B130\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	adds r2, r0, r1\n\
_08007DA8:\n\
	ldrh r0, [r3]\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	ldrh r0, [r2]\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r3, #4\n\
	adds r5, #4\n\
	adds r2, #4\n\
	adds r4, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007DA8\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007DCC: .4byte gUnknown_03000000\n\
_08007DD0: .4byte gUnknown_0202BE30\n\
_08007DD4: .4byte gUnknown_0201B130\n\
_08007DD8:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	ldr r1, _08007E64 @ =gUnknown_03000000\n\
	mov sb, r1\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #8\n\
	mov sl, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r6, r0, r2\n\
	ldr r0, _08007E68 @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_08007DFC:\n\
	lsls r3, r7, #1\n\
	lsls r4, r7, #2\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	ldr r0, _08007E6C @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08007E70 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	ldr r0, _08007E6C @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r4]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0xc\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, #4\n\
	adds r6, #4\n\
	movs r0, #4\n\
	add r8, r0\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007DFC\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007E64: .4byte gUnknown_03000000\n\
_08007E68: .4byte gUnknown_0202BE30\n\
_08007E6C: .4byte 0x00000FFF\n\
_08007E70: .4byte gUnknown_0201B130\n\
_08007E74:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	ldr r0, _08007F00 @ =gUnknown_03000000\n\
	mov sb, r0\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	mov sl, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r6, r0, r2\n\
	ldr r0, _08007F04 @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_08007E98:\n\
	lsls r3, r7, #1\n\
	lsls r4, r7, #2\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08007F08 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r4]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, #4\n\
	adds r6, #4\n\
	movs r0, #4\n\
	add r8, r0\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007E98\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007F00: .4byte gUnknown_03000000\n\
_08007F04: .4byte gUnknown_0202BE30\n\
_08007F08: .4byte gUnknown_0201B130\n\
_08007F0C:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	ldr r0, _08007F94 @ =gUnknown_03000000\n\
	mov sb, r0\n\
	ldr r1, _08007F98 @ =0x0000FFF0\n\
	mov sl, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r6, r0, r2\n\
	ldr r0, _08007F9C @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_08007F2E:\n\
	lsls r3, r7, #1\n\
	lsls r4, r7, #2\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08007FA0 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r4]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, #4\n\
	adds r6, #4\n\
	movs r0, #4\n\
	add r8, r0\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007F2E\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007F94: .4byte gUnknown_03000000\n\
_08007F98: .4byte 0x0000FFF0\n\
_08007F9C: .4byte gUnknown_0202BE30\n\
_08007FA0: .4byte gUnknown_0201B130\n\
_08007FA4:\n\
	movs r7, #0\n\
	adds r2, #1\n\
	mov ip, r2\n\
	ldr r1, _08007FE8 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	ldr r6, _08007FEC @ =gUnknown_0202BE30\n\
	lsls r0, r2, #1\n\
	adds r4, r0, r1\n\
	mov r5, ip\n\
_08007FB6:\n\
	lsls r3, r7, #2\n\
	ldrh r0, [r4]\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r2, r5, r0\n\
	lsls r2, r2, #1\n\
	add r2, r8\n\
	ldr r1, _08007FF0 @ =gUnknown_0201B130\n\
	adds r3, r3, r1\n\
	ldrh r0, [r2]\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r6, #4\n\
	adds r4, #4\n\
	adds r5, #2\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08007FB6\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08007FE8: .4byte gUnknown_03000000\n\
_08007FEC: .4byte gUnknown_0202BE30\n\
_08007FF0: .4byte gUnknown_0201B130\n\
_08007FF4:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _08008074 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _08008078 @ =gUnknown_0202BE30\n\
_0800800A:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	lsls r5, r7, #2\n\
	ldrh r1, [r6]\n\
	ldr r0, _0800807C @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	lsrs r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldr r1, _08008080 @ =gUnknown_0201B130\n\
	adds r5, r5, r1\n\
	ldrh r1, [r5]\n\
	ldr r0, _0800807C @ =0x00000FFF\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r5]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	lsrs r0, r0, #0xc\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800800A\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08008074: .4byte gUnknown_03000000\n\
_08008078: .4byte gUnknown_0202BE30\n\
_0800807C: .4byte 0x00000FFF\n\
_08008080: .4byte gUnknown_0201B130\n\
_08008084:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _08008104 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _08008108 @ =gUnknown_0202BE30\n\
_0800809A:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	lsls r5, r7, #2\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldr r1, _0800810C @ =gUnknown_0201B130\n\
	adds r5, r5, r1\n\
	ldrh r1, [r5]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r5]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800809A\n\
	bl _080088C8\n\
	.align 2, 0\n\
_08008104: .4byte gUnknown_03000000\n\
_08008108: .4byte gUnknown_0202BE30\n\
_0800810C: .4byte gUnknown_0201B130\n\
_08008110:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _0800818C @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _08008190 @ =gUnknown_0202BE30\n\
_08008126:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	lsls r5, r7, #2\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r6]\n\
	ldr r0, _08008194 @ =0x0000FFF0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldr r1, _08008198 @ =gUnknown_0201B130\n\
	adds r5, r5, r1\n\
	ldrh r1, [r5]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r5]\n\
	ldr r0, _08008194 @ =0x0000FFF0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08008126\n\
	b _080088C8\n\
	.align 2, 0\n\
_0800818C: .4byte gUnknown_03000000\n\
_08008190: .4byte gUnknown_0202BE30\n\
_08008194: .4byte 0x0000FFF0\n\
_08008198: .4byte gUnknown_0201B130\n\
_0800819C:\n\
	adds r0, r3, #0\n\
	cmp r3, #0\n\
	bge _080081A4\n\
	adds r0, r3, #7\n\
_080081A4:\n\
	asrs r0, r0, #3\n\
	lsls r0, r0, #3\n\
	subs r0, r3, r0\n\
	cmp r0, #7\n\
	bls _080081B0\n\
	b _080088C8\n\
_080081B0:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080081BC @ =_080081C0\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080081BC: .4byte _080081C0\n\
_080081C0: @ jump table\n\
	.4byte _080081E0 @ case 0\n\
	.4byte _08008230 @ case 1\n\
	.4byte _08008284 @ case 2\n\
	.4byte _08008318 @ case 3\n\
	.4byte _080083AC @ case 4\n\
	.4byte _0800840C @ case 5\n\
	.4byte _08008468 @ case 6\n\
	.4byte _080084F4 @ case 7\n\
_080081E0:\n\
	movs r7, #0\n\
	ldr r1, _08008220 @ =gUnknown_03000000\n\
	ldr r6, _08008224 @ =0x00000FFF\n\
	lsls r0, r2, #1\n\
	adds r4, r0, r1\n\
	ldr r5, _08008228 @ =gUnknown_0202BE30\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	adds r3, r0, r1\n\
_080081F4:\n\
	lsls r2, r7, #2\n\
	ldrh r1, [r5]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r0, _0800822C @ =gUnknown_0201B130\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r4, #4\n\
	adds r5, #4\n\
	adds r3, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080081F4\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008220: .4byte gUnknown_03000000\n\
_08008224: .4byte 0x00000FFF\n\
_08008228: .4byte gUnknown_0202BE30\n\
_0800822C: .4byte gUnknown_0201B130\n\
_08008230:\n\
	movs r7, #0\n\
	ldr r1, _08008274 @ =gUnknown_03000000\n\
	ldr r6, _08008278 @ =0x00000FFF\n\
	lsls r0, r2, #1\n\
	adds r4, r0, r1\n\
	ldr r5, _0800827C @ =gUnknown_0202BE30\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	adds r3, r0, r1\n\
_08008244:\n\
	lsls r2, r7, #2\n\
	ldrh r1, [r5]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r0, _08008280 @ =gUnknown_0201B130\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r4, #4\n\
	adds r5, #4\n\
	adds r3, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08008244\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008274: .4byte gUnknown_03000000\n\
_08008278: .4byte 0x00000FFF\n\
_0800827C: .4byte gUnknown_0202BE30\n\
_08008280: .4byte gUnknown_0201B130\n\
_08008284:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	ldr r0, _0800830C @ =gUnknown_03000000\n\
	mov sb, r0\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #4\n\
	mov sl, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r6, r0, r2\n\
	ldr r0, _08008310 @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_080082A8:\n\
	lsls r3, r7, #1\n\
	lsls r4, r7, #2\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08008314 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r4]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, #4\n\
	adds r6, #4\n\
	movs r0, #4\n\
	add r8, r0\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080082A8\n\
	b _080088C8\n\
	.align 2, 0\n\
_0800830C: .4byte gUnknown_03000000\n\
_08008310: .4byte gUnknown_0202BE30\n\
_08008314: .4byte gUnknown_0201B130\n\
_08008318:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	ldr r0, _080083A0 @ =gUnknown_03000000\n\
	mov sb, r0\n\
	movs r1, #0xff\n\
	lsls r1, r1, #4\n\
	mov sl, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r6, r0, r2\n\
	ldr r0, _080083A4 @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_0800833C:\n\
	lsls r3, r7, #1\n\
	lsls r4, r7, #2\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _080083A8 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r4]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, #4\n\
	adds r6, #4\n\
	movs r0, #4\n\
	add r8, r0\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800833C\n\
	b _080088C8\n\
	.align 2, 0\n\
_080083A0: .4byte gUnknown_03000000\n\
_080083A4: .4byte gUnknown_0202BE30\n\
_080083A8: .4byte gUnknown_0201B130\n\
_080083AC:\n\
	movs r7, #0\n\
	adds r2, #1\n\
	mov ip, r2\n\
	ldr r1, _080083FC @ =gUnknown_03000000\n\
	mov sb, r1\n\
	ldr r2, _08008400 @ =0x00000FFF\n\
	mov r8, r2\n\
	ldr r6, _08008404 @ =gUnknown_0202BE30\n\
	mov r1, ip\n\
	lsls r0, r1, #1\n\
	mov r2, sb\n\
	adds r4, r0, r2\n\
	mov r5, ip\n\
_080083C6:\n\
	lsls r3, r7, #2\n\
	ldrh r1, [r6]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r2, r5, r0\n\
	lsls r2, r2, #1\n\
	add r2, sb\n\
	ldr r1, _08008408 @ =gUnknown_0201B130\n\
	adds r3, r3, r1\n\
	ldrh r1, [r3]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r6, #4\n\
	adds r4, #4\n\
	adds r5, #2\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080083C6\n\
	b _080088C8\n\
	.align 2, 0\n\
_080083FC: .4byte gUnknown_03000000\n\
_08008400: .4byte 0x00000FFF\n\
_08008404: .4byte gUnknown_0202BE30\n\
_08008408: .4byte gUnknown_0201B130\n\
_0800840C:\n\
	movs r7, #0\n\
	adds r2, #1\n\
	mov ip, r2\n\
	ldr r6, _08008458 @ =gUnknown_03000000\n\
	ldr r2, _0800845C @ =0x00000FFF\n\
	mov r8, r2\n\
	ldr r5, _08008460 @ =gUnknown_0202BE30\n\
_0800841A:\n\
	lsls r2, r7, #1\n\
	add r2, ip\n\
	lsls r3, r2, #1\n\
	adds r3, r3, r6\n\
	lsls r4, r7, #2\n\
	ldrh r1, [r5]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #1\n\
	adds r2, r2, r6\n\
	ldr r1, _08008464 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r5, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800841A\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008458: .4byte gUnknown_03000000\n\
_0800845C: .4byte 0x00000FFF\n\
_08008460: .4byte gUnknown_0202BE30\n\
_08008464: .4byte gUnknown_0201B130\n\
_08008468:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _080084E8 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _080084EC @ =gUnknown_0202BE30\n\
_0800847E:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	lsls r5, r7, #2\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldr r1, _080084F0 @ =gUnknown_0201B130\n\
	adds r5, r5, r1\n\
	ldrh r1, [r5]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r5]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800847E\n\
	b _080088C8\n\
	.align 2, 0\n\
_080084E8: .4byte gUnknown_03000000\n\
_080084EC: .4byte gUnknown_0202BE30\n\
_080084F0: .4byte gUnknown_0201B130\n\
_080084F4:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _08008574 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _08008578 @ =gUnknown_0202BE30\n\
_0800850A:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	lsls r5, r7, #2\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldr r1, _0800857C @ =gUnknown_0201B130\n\
	adds r5, r5, r1\n\
	ldrh r1, [r5]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r5]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800850A\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008574: .4byte gUnknown_03000000\n\
_08008578: .4byte gUnknown_0202BE30\n\
_0800857C: .4byte gUnknown_0201B130\n\
_08008580:\n\
	adds r0, r3, #0\n\
	cmp r3, #0\n\
	bge _08008588\n\
	adds r0, r3, #7\n\
_08008588:\n\
	asrs r0, r0, #3\n\
	lsls r0, r0, #3\n\
	subs r0, r3, r0\n\
	cmp r0, #7\n\
	bls _08008594\n\
	b _080088C8\n\
_08008594:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080085A0 @ =_080085A4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080085A0: .4byte _080085A4\n\
_080085A4: @ jump table\n\
	.4byte _080085C4 @ case 0\n\
	.4byte _08008610 @ case 1\n\
	.4byte _08008660 @ case 2\n\
	.4byte _080086B0 @ case 3\n\
	.4byte _08008744 @ case 4\n\
	.4byte _080087A0 @ case 5\n\
	.4byte _080087F8 @ case 6\n\
	.4byte _08008850 @ case 7\n\
_080085C4:\n\
	movs r7, #0\n\
	ldr r1, _08008604 @ =gUnknown_03000000\n\
	movs r6, #0xff\n\
	lsls r0, r2, #1\n\
	adds r4, r0, r1\n\
	ldr r5, _08008608 @ =gUnknown_0202BE30\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	adds r3, r0, r1\n\
_080085D8:\n\
	lsls r2, r7, #2\n\
	ldrh r1, [r5]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r0, _0800860C @ =gUnknown_0201B130\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r4, #4\n\
	adds r5, #4\n\
	adds r3, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080085D8\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008604: .4byte gUnknown_03000000\n\
_08008608: .4byte gUnknown_0202BE30\n\
_0800860C: .4byte gUnknown_0201B130\n\
_08008610:\n\
	movs r7, #0\n\
	ldr r1, _08008654 @ =gUnknown_03000000\n\
	movs r6, #0xff\n\
	lsls r0, r2, #1\n\
	adds r4, r0, r1\n\
	ldr r5, _08008658 @ =gUnknown_0202BE30\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	adds r3, r0, r1\n\
_08008624:\n\
	lsls r2, r7, #2\n\
	ldrh r1, [r5]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r0, _0800865C @ =gUnknown_0201B130\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r4, #4\n\
	adds r5, #4\n\
	adds r3, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08008624\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008654: .4byte gUnknown_03000000\n\
_08008658: .4byte gUnknown_0202BE30\n\
_0800865C: .4byte gUnknown_0201B130\n\
_08008660:\n\
	movs r7, #0\n\
	ldr r1, _080086A4 @ =gUnknown_03000000\n\
	movs r6, #0xff\n\
	lsls r0, r2, #1\n\
	adds r4, r0, r1\n\
	ldr r5, _080086A8 @ =gUnknown_0202BE30\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	adds r3, r0, r1\n\
_08008674:\n\
	lsls r2, r7, #2\n\
	ldrh r1, [r5]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r0, _080086AC @ =gUnknown_0201B130\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r4, #4\n\
	adds r5, #4\n\
	adds r3, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08008674\n\
	b _080088C8\n\
	.align 2, 0\n\
_080086A4: .4byte gUnknown_03000000\n\
_080086A8: .4byte gUnknown_0202BE30\n\
_080086AC: .4byte gUnknown_0201B130\n\
_080086B0:\n\
	movs r7, #0\n\
	adds r1, r2, #1\n\
	mov ip, r1\n\
	ldr r0, _08008738 @ =gUnknown_03000000\n\
	mov sb, r0\n\
	movs r1, #0xf0\n\
	mov sl, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	lsls r0, r2, #1\n\
	mov r2, sb\n\
	adds r6, r0, r2\n\
	ldr r0, _0800873C @ =gUnknown_0202BE30\n\
	mov r8, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r2\n\
_080086D2:\n\
	lsls r3, r7, #1\n\
	lsls r4, r7, #2\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r6]\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	add r3, ip\n\
	lsls r2, r3, #1\n\
	add r2, sb\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08008740 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r5]\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r3, r3, #1\n\
	add r3, sb\n\
	ldrh r1, [r4]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r5, #4\n\
	adds r6, #4\n\
	movs r0, #4\n\
	add r8, r0\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080086D2\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008738: .4byte gUnknown_03000000\n\
_0800873C: .4byte gUnknown_0202BE30\n\
_08008740: .4byte gUnknown_0201B130\n\
_08008744:\n\
	movs r7, #0\n\
	adds r2, #1\n\
	mov ip, r2\n\
	ldr r1, _08008794 @ =gUnknown_03000000\n\
	mov sb, r1\n\
	movs r2, #0xff\n\
	mov r8, r2\n\
	ldr r6, _08008798 @ =gUnknown_0202BE30\n\
	mov r1, ip\n\
	lsls r0, r1, #1\n\
	mov r2, sb\n\
	adds r4, r0, r2\n\
	mov r5, ip\n\
_0800875E:\n\
	lsls r3, r7, #2\n\
	ldrh r1, [r6]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r2, r5, r0\n\
	lsls r2, r2, #1\n\
	add r2, sb\n\
	ldr r1, _0800879C @ =gUnknown_0201B130\n\
	adds r3, r3, r1\n\
	ldrh r1, [r3]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r6, #4\n\
	adds r4, #4\n\
	adds r5, #2\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _0800875E\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008794: .4byte gUnknown_03000000\n\
_08008798: .4byte gUnknown_0202BE30\n\
_0800879C: .4byte gUnknown_0201B130\n\
_080087A0:\n\
	movs r7, #0\n\
	adds r2, #1\n\
	mov ip, r2\n\
	ldr r6, _080087EC @ =gUnknown_03000000\n\
	movs r2, #0xff\n\
	mov r8, r2\n\
	ldr r5, _080087F0 @ =gUnknown_0202BE30\n\
_080087AE:\n\
	lsls r2, r7, #1\n\
	add r2, ip\n\
	lsls r3, r2, #1\n\
	adds r3, r3, r6\n\
	lsls r4, r7, #2\n\
	ldrh r1, [r5]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #1\n\
	adds r2, r2, r6\n\
	ldr r1, _080087F4 @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r5, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _080087AE\n\
	b _080088C8\n\
	.align 2, 0\n\
_080087EC: .4byte gUnknown_03000000\n\
_080087F0: .4byte gUnknown_0202BE30\n\
_080087F4: .4byte gUnknown_0201B130\n\
_080087F8:\n\
	movs r7, #0\n\
	adds r2, #1\n\
	mov ip, r2\n\
	ldr r6, _08008844 @ =gUnknown_03000000\n\
	movs r2, #0xff\n\
	mov r8, r2\n\
	ldr r5, _08008848 @ =gUnknown_0202BE30\n\
_08008806:\n\
	lsls r2, r7, #1\n\
	add r2, ip\n\
	lsls r3, r2, #1\n\
	adds r3, r3, r6\n\
	lsls r4, r7, #2\n\
	ldrh r1, [r5]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #1\n\
	adds r2, r2, r6\n\
	ldr r1, _0800884C @ =gUnknown_0201B130\n\
	adds r4, r4, r1\n\
	ldrh r1, [r4]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r5, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08008806\n\
	b _080088C8\n\
	.align 2, 0\n\
_08008844: .4byte gUnknown_03000000\n\
_08008848: .4byte gUnknown_0202BE30\n\
_0800884C: .4byte gUnknown_0201B130\n\
_08008850:\n\
	movs r7, #0\n\
	adds r0, r2, #1\n\
	mov ip, r0\n\
	adds r2, #0x10\n\
	mov sb, r2\n\
	ldr r1, _080088D8 @ =gUnknown_03000000\n\
	mov r8, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	ldr r6, _080088DC @ =gUnknown_0202BE30\n\
_08008866:\n\
	lsls r4, r7, #1\n\
	mov r0, ip\n\
	adds r3, r4, r0\n\
	lsls r2, r3, #1\n\
	add r2, r8\n\
	lsls r5, r7, #2\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r4, sb\n\
	lsls r2, r4, #1\n\
	add r2, r8\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	add r3, sl\n\
	lsls r3, r3, #1\n\
	add r3, r8\n\
	ldr r1, _080088E0 @ =gUnknown_0201B130\n\
	adds r5, r5, r1\n\
	ldrh r1, [r5]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	add r4, sl\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrh r1, [r5]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r6, #4\n\
	adds r7, #1\n\
	cmp r7, #7\n\
	ble _08008866\n\
_080088C8:\n\
	add sp, #0x14\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080088D8: .4byte gUnknown_03000000\n\
_080088DC: .4byte gUnknown_0202BE30\n\
_080088E0: .4byte gUnknown_0201B130\n\
    ");
}

void sub_88E4(void)
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

void sub_8974(s16 species)
{
    int var0;
    s16 quotient;
    s16 remainder;
    s16 var1;

    var0 = gUnknown_086A61BC[species];
    if (var0 == -1)
        return;

    if (var0 < 100)
    {
        gUnknown_0202BF14 = 0;
        quotient = var0 / 5;
        remainder = var0 % 5;

        sub_10708(gUnknown_086BB6F4[quotient] + remainder * 0xD80, (void *)(OBJ_VRAM0 + 0x3800), 108, 1);
        DmaCopy16(3, gUnknown_086B15B4[quotient] + remainder * 0x20, (void *)OBJ_PLTT + 0x40, 0x20);
    }
    else
    {
        gUnknown_0202BF14 = 1;
        quotient = (var0 - 100) / 6;
        remainder = (var0 - 100) % 6;

        sub_10708(gMonHatchSpriteGroupGfx[quotient] + remainder * 0x10E0, (void *)(OBJ_VRAM0 + 0x4800), 135, 1);
        DmaCopy16(3, gMonHatchSpriteGroupPals[quotient] + remainder * 0x20, (void *)OBJ_PLTT + 0x60, 0x20);
    }
}

s16 sub_8A78(s16 species)
{
    if (gPokedexFlags[species] == 4 && gUnknown_086A61BC[species] != -1)
        gUnknown_0202A588 = 1;
    else
        gUnknown_0202A588 = 0;

    return gUnknown_0202A588;
}

void ResetPokedex(void)
{
    int i;

    for (i = 0; i < NUM_SPECIES; i++)
        gMain_saveData.pokedexFlags[i] = SPECIES_UNSEEN;
}
