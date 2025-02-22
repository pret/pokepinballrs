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
void sub_70E0(s16, s32);
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

extern u16 gUnknown_0201C180;
extern u16 gUnknown_0202C5B4;
extern s8 gUnknown_0201C1BC;
extern s8 gUnknown_0202C544;
extern s8 gUnknown_0202BECC;
extern u8 gUnknown_0202BE30[];
extern u8 gUnknown_0201B130[];

extern const struct SpriteSet *const gUnknown_086A6148[];
extern u16 gUnknown_0202BF08;
extern const u16 gUnknown_086A5DDA[][4];
extern const u16 gUnknown_086A5DF2[][20];
extern const s16 gUnknown_086A6356[];
extern const u16 gUnknown_086A5EE2[][51];
extern const s16 gUnknown_086A6014[][51];
extern const u16 gUnknown_086A5E12[][4];
extern const u8 gUnknown_08090780[];
extern u8 gUnknown_08092FA0[]; // needs const
extern s16 gUnknown_086A64F0[];
extern u8 *gMonPortraitGroupGfx[];
extern u8 *gMonPortraitGroupPals[];
extern u8 gUnknown_0808F760[];

struct PokedexEntry
{
    u16 dexNum[DEX_NUM_DIGITS];
    u16 heightWeight[POKEMON_HEIGHT_WEIGHT_TEXT_LENGTH];
    s16 name[POKEMON_NAME_LENGTH];
    s16 category[POKEMON_CATEGORY_NAME_LENGTH];
    u8 filler40[0x1FA];
};

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

    DmaCopy16(3, gUnknown_08082720, (void *)BG_CHAR_ADDR(1), 0x4400);
    DmaCopy16(3, gUnknown_08087B40, (void *)BG_CHAR_ADDR(3), 0x1400);
    DmaCopy16(3, gUnknown_08089760, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gUnknown_08081F20, gUnknown_03005C00, BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08087340, gUnknown_02019C40, BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08088F60, (void *)BG_SCREEN_ADDR(2), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_08089960, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gUnknown_08089B60, (void *)OBJ_VRAM0, 0x6C20);

    sub_3FAC();
    PrintSeenOwnedTotals(gUnknown_0202BEB8, gUnknown_0201A514);
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
        gUnknown_0202A390[i] = gUnknown_0202A1C0[i];
    }

    if (gUnknown_0202A1C0[SPECIES_AERODACTYL])
        gPokedexListEntryCount = SPECIES_AERODACTYL + 1;
    else if (gUnknown_0202A1C0[SPECIES_TOTODILE])
        gPokedexListEntryCount = SPECIES_TOTODILE + 1;
    else if (gUnknown_0202A1C0[SPECIES_CYNDAQUIL])
        gPokedexListEntryCount = SPECIES_CYNDAQUIL + 1;
    else if (gUnknown_0202A1C0[SPECIES_CHIKORITA])
        gPokedexListEntryCount = SPECIES_CHIKORITA + 1;
    else if (gUnknown_0202A1C0[SPECIES_JIRACHI])
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

            if (gUnknown_0202A1C0[gPokedexSelectedMon] >= 2)
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

            if (gUnknown_0202A1C0[gPokedexSelectedMon] >= 2)
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
            m4aSongNumStart(SE_UNKNOWN_0x66);
            gMain.subState = POKEDEX_STATE_RETURN_TO_TITLE;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x68);
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
    s32 i;

    for (i = 0; i < 0x20; i++)
    {
        gUnknown_03005C00[0x20*(gUnknown_0202A558 + 10) + i] = gUnknown_0805C840[i];
        gUnknown_02019C40[0x20*(gUnknown_0202A558 + 9) + i] = gUnknown_0805C780[i];
        gUnknown_02019C40[0x20*(gUnknown_0202A558 + 10) + i] = gUnknown_0805C7C0[i];
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
                sub_70E0(gPokedexSelectedMon,gUnknown_0202C794);
                gUnknown_02019C28 = gUnknown_0202C794;
            }
            else
            {
                m4aSongNumStart(SE_UNKNOWN_0x69);
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
        m4aSongNumStart(SE_UNKNOWN_0x69);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        gUnknown_0202C794 = 0;
        gUnknown_0202C5E8 = 0;
        gUnknown_0202BEF4 = gUnknown_0202C5E8;
        gUnknown_0201C1B4 = 0;
        gMain.subState = POKEDEX_STATE_4;
    }

    if (JOY_HELD(SELECT_BUTTON))
    {
        if (gUnknown_0202A1C0[gPokedexSelectedMon] == 4)
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
        gUnknown_02019C40[0x20 * (0x11 - gUnknown_0202A558) + i] = gUnknown_0805C7C0[i];
        gUnknown_02019C40[0x20 * (0x12 - gUnknown_0202A558) + i] = gUnknown_0805C800[i];
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
        m4aSongNumStart(SE_UNKNOWN_0x66);
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
            gUnknown_0202A390[iVar1] = gUnknown_0202A1C0[iVar1];
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
            m4aSongNumStart(SE_UNKNOWN_0x65);
            break;
        case 0xFA:
            gUnknown_0201B120 = 0;
            gUnknown_0202BEC4 = 0;
            gUnknown_0202BEFC = 0;
            gUnknown_0202BF04 = 1;
            gUnknown_0202A588 = 1;
            for(index = 0; index < 0xE1; index++)
            {
                gUnknown_0202A1C0[index] = gUnknown_0202A390[index];
            }
            for(index = 0; index < NUM_SPECIES; index++)
            {
                gMain_saveData.pokedexFlags[index] = gUnknown_0202A1C0[index];
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
        m4aSongNumStart(SE_UNKNOWN_0x65);
        for (i = 0; i < 0xE1; i++)
        {
            gUnknown_0202A390[i] = 0;
            gUnknown_0202A1C0[i] = 0;
        }
        for (i = 0; i < NUM_SPECIES; i++)
        {
            gMain_saveData.pokedexFlags[i] = gUnknown_0202A1C0[i];
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
        m4aSongNumStart(SE_UNKNOWN_0x66);
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
                m4aSongNumStart(SE_SELECT);
            }
        }
        else
        {
            gPokedexListPosition--;
            gPokedexSelectedMon--;
            m4aSongNumStart(SE_SELECT);
        }

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }
    else
    {
        m4aSongNumStart(SE_SELECT);
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
                m4aSongNumStart(SE_SELECT);
            }
        }
        else
        {
            gPokedexListPosition++;
            gPokedexSelectedMon++;
            m4aSongNumStart(SE_SELECT);
        }

        gPokedexScrollWaitFrames = SCROLL_WAIT_FRAMES;
    }
    else
    {
        m4aSongNumStart(SE_SELECT);
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

    m4aSongNumStart(SE_SELECT);
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

    m4aSongNumStart(SE_SELECT);
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
            m4aSongNumStart(SE_UNKNOWN_0x68);
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
    if (gUnknown_0202A1C0[gPokedexSelectedMon] == 4)
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
    if (gUnknown_0202A1C0[gPokedexSelectedMon] == 4 && gUnknown_086A61BC[gPokedexSelectedMon] != -1)
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

    group0 = &gUnknown_0200B3B8[0];
    group1 = &gUnknown_0200B3B8[1];
    group2 = &gUnknown_0200B3B8[2];
    group3 = &gUnknown_0200B3B8[3];
    group4 = &gUnknown_0200B3B8[4];
    group5 = &gUnknown_0200B3B8[5 + gUnknown_0201A448];
    group6 = &gUnknown_0200B3B8[17 + gUnknown_0202BEFC];
    group7 = &gUnknown_0200B3B8[22 + gUnknown_0202BEE0];
    group8 = &gUnknown_0200B3B8[24];
    group9 = &gUnknown_0200B3B8[25 + gUnknown_02019C28 * 2 + gUnknown_0202C5AC];

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

    group0 = &gUnknown_0200B3B8[0];
    group1 = &gUnknown_0200B3B8[1];
    group2 = &gUnknown_0200B3B8[2];
    group3 = &gUnknown_0200B3B8[3];
    group4 = &gUnknown_0200B3B8[4];
    group6 = &gUnknown_0200B3B8[5 + gUnknown_0201A448];
    group7 = &gUnknown_0200B3B8[17 + gUnknown_0202BEFC];
    group5 = &gUnknown_0200B3B8[24];

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
        gUnknown_0202C5F0[1] = gUnknown_0202A1C0[var0] |
                               (gUnknown_0202A1C0[var0 + 1] << 4) |
                               (gUnknown_0202A1C0[var0 + 2] << 8) |
                               (gUnknown_0202A1C0[var0 + 3] << 12);
        gUnknown_0202C5F0[2] =  gUnknown_0202A1C0[var0 + 4] |
                               (gUnknown_0202A1C0[var0 + 5] << 4) |
                               (gUnknown_0202A1C0[var0 + 6] << 8) |
                               (gUnknown_0202A1C0[var0 + 7] << 12);
        gUnknown_0202C5F0[3] =  gUnknown_0202A1C0[var0 + 8] |
                               (gUnknown_0202A1C0[var0 + 9] << 4) |
                               (gUnknown_0202A1C0[var0 + 10] << 8) |
                               (gUnknown_0202A1C0[var0 + 11] << 12);
        gUnknown_0202C5F0[4] =  gUnknown_0202A1C0[var0 + 12] |
                               (gUnknown_0202A1C0[var0 + 13] << 4) |
                               (gUnknown_0202A1C0[var0 + 14] << 8) |
                               (gUnknown_0202A1C0[var0 + 15] << 12);
        gUnknown_0202C5F0[5] =  gUnknown_0202A1C0[var0 + 16] |
                               (gUnknown_0202A1C0[var0 + 17] << 4) |
                               (gUnknown_0202A1C0[var0 + 18] << 8) |
                               (gUnknown_0202A1C0[var0 + 19] << 12);
        gUnknown_0202C5F0[6] =  gUnknown_0202A1C0[var0 + 20] |
                               (gUnknown_0202A1C0[var0 + 21] << 4) |
                               (gUnknown_0202A1C0[var0 + 22] << 8) |
                               (gUnknown_0202A1C0[var0 + 23] << 12);
        gUnknown_0202C5F0[7] =  gUnknown_0202A1C0[var0 + 24] |
                               (gUnknown_0202A1C0[var0 + 25] << 4) |
                               (gUnknown_0202A1C0[var0 + 26] << 8) |
                               (gUnknown_0202A1C0[var0 + 27] << 12);
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
        gUnknown_0202C5F0[1] = gUnknown_0202A1C0[var0] |
                               (gUnknown_0202A1C0[var0 + 1] << 4) |
                               (gUnknown_0202A1C0[var0 + 2] << 8) |
                               (gUnknown_0202A1C0[var0 + 3] << 12);
        gUnknown_0202C5F0[2] =  gUnknown_0202A1C0[var0 + 4] |
                               (gUnknown_0202A1C0[var0 + 5] << 4) |
                               (gUnknown_0202A1C0[var0 + 6] << 8) |
                               (gUnknown_0202A1C0[var0 + 7] << 12);
        gUnknown_0202C5F0[3] =  gUnknown_0202A1C0[var0 + 8] |
                               (gUnknown_0202A1C0[var0 + 9] << 4) |
                               (gUnknown_0202A1C0[var0 + 10] << 8) |
                               (gUnknown_0202A1C0[var0 + 11] << 12);
        gUnknown_0202C5F0[4] =  gUnknown_0202A1C0[var0 + 12] |
                               (gUnknown_0202A1C0[var0 + 13] << 4) |
                               (gUnknown_0202A1C0[var0 + 14] << 8) |
                               (gUnknown_0202A1C0[var0 + 15] << 12);
        gUnknown_0202C5F0[5] =  gUnknown_0202A1C0[var0 + 16] |
                               (gUnknown_0202A1C0[var0 + 17] << 4) |
                               (gUnknown_0202A1C0[var0 + 18] << 8) |
                               (gUnknown_0202A1C0[var0 + 19] << 12);
        gUnknown_0202C5F0[6] =  gUnknown_0202A1C0[var0 + 20] |
                               (gUnknown_0202A1C0[var0 + 21] << 4) |
                               (gUnknown_0202A1C0[var0 + 22] << 8) |
                               (gUnknown_0202A1C0[var0 + 23] << 12);
        gUnknown_0202C5F0[7] =  gUnknown_0202A1C0[var0 + 24] |
                               (gUnknown_0202A1C0[var0 + 25] << 4) |
                               (gUnknown_0202A1C0[var0 + 26] << 8) |
                               (gUnknown_0202A1C0[var0 + 27] << 12);
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
            if (gUnknown_0202A1C0[var0] == 0 && arr0[i] == 4)
                gUnknown_0202A390[var0] = 2;
            else if (gUnknown_0202A1C0[var0] == 1 && arr0[i] == 4)
                gUnknown_0202A390[var0] = 3;
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
            if (gUnknown_0202A1C0[var0] == 0 && arr0[i] == 4)
                gUnknown_0202A390[var0] = 2;
            else if (gUnknown_0202A1C0[var0] == 1 && arr0[i] == 4)
                gUnknown_0202A390[var0] = 3;
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
        if (gUnknown_0202A1C0[SPECIES_JIRACHI] != 0)
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

    if (gUnknown_0202A1C0[species] > 0)
    {
        for (i = 0; i < POKEMON_NAME_LENGTH; i++)
        {
            var1 = gPokedexEntries[species].name[i] & ~0xF;
            var2 = gPokedexEntries[species].name[i] & 0xF;
            if (var2 == 0)
                var2 = 4;

            DmaCopy16(3, &gUnknown_08090780[var1], gUnknown_0202BE30, 0x20);
            DmaCopy16(3, &gUnknown_08090780[var1 + 0x400], gUnknown_0201B130, 0x20);
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
            sub_10708(gUnknown_08092FA0, (void *)0x06004C00 + i * 0x20, 1, 2);
    }

    if (gUnknown_0202A1C0[species] == 1 || gUnknown_0202A1C0[species] > 2)
    {
        for (i = 0; i < POKEMON_CATEGORY_NAME_LENGTH; i++)
        {
            var1 = gPokedexEntries[species].category[i] & ~0xF;
            var2 = gPokedexEntries[species].category[i] & 0xF;
            if (var2 == 0)
                var2 = 6;

            DmaCopy16(3, &gUnknown_08090780[var1], gUnknown_0202BE30, 0x20);
            DmaCopy16(3, &gUnknown_08090780[0x400 + var1], gUnknown_0201B130, 0x20);
            sub_71DC(var2, var0, 0);
            var0 += var2;
        }

        sub_10708(gUnknown_03000000, (void *)0x06004D00, 9, 2);
        DmaFill16(3, 0, gUnknown_03000000, 0x800);
    }
    else
    {
        for (i = 0; i < 9; i++)
            sub_10708(gUnknown_08092FA0, (void *)0x06004D00 + i * 0x20, 1, 2);
    }

    if (gUnknown_0202A1C0[species] == 4)
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
            if (gUnknown_0202A1C0[SPECIES_JIRACHI] != 0)
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
        if (gUnknown_0202A1C0[listPosition + i] > 0)
        {
            for (j = 0; j < POKEMON_NAME_LENGTH; j++)
            {
                // These don't use listPosition for some reason, despite being the only value passed
                var1 = gPokedexEntries[gPokedexListPosition + i].name[j] & ~0xF;
                var2 = gPokedexEntries[gPokedexListPosition + i].name[j] & 0xF;
                if (var2 == 0)
                    var2 = 4;

                DmaCopy16(3, &gUnknown_08090780[var1], gUnknown_0202BE30, 0x20);
                DmaCopy16(3, &gUnknown_08090780[0x400 + var1], gUnknown_0201B130, 0x20);
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
                sub_10708(gUnknown_08092FA0, (void *)0x06000000 + gUnknown_086A64F0[i] + j * 0x20, 1, 2);
        
            sub_10708((void *)gUnknown_08090780, (void *)0x06000000 + gUnknown_086A64F0[i] + j * 0x20, 1, 2);
        }
    }
}

static void PrintCaughtBallFromListPosition(s16 position)
{
    int i;
    int var0;

    for (i = 0; i < ENTRIES_SHOWN_COUNT; i++)
    {
        var0 = gUnknown_0202A1C0[position + i] == 4 ? CHAR_BALL_CAUGHT : CHAR_BALL_NOT_CAUGHT;
        PrintChar(var0, 1, 4, 10 + i * 2, 2, 2);
    }
}

void sub_6F78(s16 species)
{
    s16 var0 = gUnknown_0202A1C0[gPokedexSelectedMon];
    s16 var1 = species / 15;
    s16 var2 = species % 15;
    switch (var0)
    {
        case 0:
            sub_10708(gUnknown_0808F760, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gUnknown_08089960, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
        case 1:
            sub_10708(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gMonPortraitGroupPals[0] + 0x1E0, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
        case 2:
        case 3:
            sub_10708(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            sub_10170(gMonPortraitGroupPals[var1] + var2 * 0x20, (void *)OBJ_PLTT + 0x20, 0x20, 0xE);
            break;
        case 4:
            sub_10708(gMonPortraitGroupGfx[var1] + var2 * 0x300, (void *)0x06013400, 24, 1);
            DmaCopy16(3, gMonPortraitGroupPals[var1] + var2 * 0x20, (void *)OBJ_PLTT + 0x20, 0x20);
            break;
    }
}
