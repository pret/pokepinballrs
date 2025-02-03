#include "global.h"
#include "constants/bg_music.h"
#include "functions.h"
#include "link.h"
#include "m4a.h"
#include "main.h"
#include "types.h"
#include "variables.h"

void sub_5174(void);
static void sub_4D74(void);
static void sub_4E34(void);
static void sub_4EF0(void);
void sub_4F50(void);
void sub_4FC8(void);
void sub_5064(void);
void sub_51CC(void);
s16 sub_5EA4(void); // TODO Pretty sure it's s16, but could be u16
void sub_5EC8(void);
void sub_70E0(s16, s32);
void sub_88E4(void);
void sub_51FC(void);

extern const struct SpriteSet *const gUnknown_086A6148[];
extern u16 gUnknown_0202BF08;
extern const u16 gUnknown_086A5DDA[][4];
extern const u16 gUnknown_086A5DF2[][20];
extern const s16 gUnknown_086A6356[];
extern const u16 gUnknown_086A5EE2[][51];
extern const s16 gUnknown_086A6014[][51];

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
    sub_6BEC(gUnknown_0202BEB8, gUnknown_0201A514);
    sub_681C(gUnknown_0202ADE0);
    sub_6CA0(gUnknown_0202C5B0);
    sub_6F30(gUnknown_0202C5B0);
    sub_6F78(gUnknown_0202ADE0);
    sub_8974(gUnknown_0202ADE0);
    sub_8A78(gUnknown_0202ADE0);

    gUnknown_02019C40[0x134] = 0x59;

    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gUnknown_02019C40, (void *)BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);

    sub_51FC();
    sub_0CBC();
    sub_024C();

    // Must be `= 1` to match, cannot be `++`
    gMain.subState = 1;

    m4aSongNumStart(MUS_POKEDEX);
}

void sub_3FAC(void)
{
    s32 i;

    gUnknown_0202ADE0 = 0;
    gUnknown_0202C5B0 = 0;
    gUnknown_0201A448 = 0;
    gUnknown_0202BF00 = 0;
    gUnknown_0202A57C = 0;
    gUnknown_0201A4F0 = 0;
    gUnknown_0202BE20 = 0;
    gUnknown_0202C58C = 0;
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
    {
        gUnknown_0202A574 = SPECIES_AERODACTYL + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_TOTODILE])
    {
        gUnknown_0202A574 = SPECIES_TOTODILE + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_CYNDAQUIL])
    {
        gUnknown_0202A574 = SPECIES_CYNDAQUIL + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_CHIKORITA])
    {
        gUnknown_0202A574 = SPECIES_CHIKORITA + 1;
    }
    else if (gUnknown_0202A1C0[SPECIES_JIRACHI])
    {
        gUnknown_0202A574 = SPECIES_JIRACHI + 1;
    }
    else
    {
        gUnknown_0202A574 = SPECIES_RAYQUAZA + 1;
    }
}

void sub_4150(void)
{
    if (JOY_HELD(SELECT_BUTTON))
    {
        gUnknown_0202BF04 = 0;

        if (JOY_HELD(DPAD_UP))
        {
            sub_4D74();
            sub_5064();
            sub_51CC();
            gMain.subState = 2;
        }
        else if (JOY_HELD(DPAD_DOWN))
        {
            sub_4E34();
            sub_5064();
            sub_51CC();
            gMain.subState = 2;
        }
        else if (JOY_HELD(DPAD_LEFT))
        {
            sub_4EF0();
            sub_5064();
            sub_51CC();
            gMain.subState = 2;
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            sub_4F50();
            sub_5064();
            sub_51CC();
            gMain.subState = 2;
        }
        else
        {
            gUnknown_02019C24 = 0;
            sub_5064();
        }

        if (JOY_NEW(A_BUTTON))
        {
            gUnknown_0202C5E8 = 0;

            if (gUnknown_0202A1C0[gUnknown_0202ADE0] >= 2)
            {
                gUnknown_0202BF04 = 0;
                DmaCopy16(3, 0x6000280, (void *)gUnknown_0202A590, 0x200);
                gMain.subState = 3;
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
            sub_4D74();
            sub_5174();
        }
        else if (JOY_HELD(DPAD_DOWN))
        {
            sub_4E34();
            sub_5174();
        }
        else if (JOY_HELD(DPAD_LEFT))
        {
            sub_4EF0();
            sub_5174();
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            sub_4F50();
            sub_5174();
        }
        else
        {
            gUnknown_02019C24 = 0;
        }

        if (sub_8A78(gUnknown_0202ADE0) == 1)
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

            if (gUnknown_0202A1C0[gUnknown_0202ADE0] >= 2)
            {
                gUnknown_0202BF04 = 0;
                DmaCopy16(3, 0x6000280, (void *)gUnknown_0202A590, 0x200);
                gMain.subState = 3;
            }
            else
            {
                m4aSongNumStart(SE_FAILURE);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x66);
            gMain.subState = 12;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x68);
            gUnknown_0202BEC4 = 1;
            gUnknown_0202BEFC = 0;
            gUnknown_0202BF04 = 0;
            gUnknown_0202A588 = 0;
            gMain.subState = 6;
        }

        sub_4FC8();
    }

    if (gUnknown_0202C58C > 0)
    {
        gUnknown_0202C58C--;
    }

    sub_51FC();
    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
}

void sub_43D4(void)
{
    sub_5174();
    gUnknown_0202A588 = 0;

    if (gUnknown_0202C58C > 0)
    {
        gUnknown_0202C58C--;
    }

    sub_51FC();
    DmaCopy16(3, gUnknown_03005C00, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    gMain.subState = 1;
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

        if (gUnknown_0202ADE0 < BONUS_SPECIES_START)
            gUnknown_0201C1B4 = 1;

        DmaCopy16(3, gUnknown_08086B40, (void *)0x6000280, 2*0xE0);
        sub_70E0(gUnknown_0202ADE0, gUnknown_0202C794);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x40);
        PlayCry_NormalNoDucking(gSpeciesInfo[gUnknown_0202ADE0].mainSeriesIndexNumber, 0, 127, 10);
        gMain.subState = 5;
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
        if ((gUnknown_0202ADE0 < BONUS_SPECIES_START) && (gUnknown_0202C794 == 1))
        {
            m4aSongNumStart(SE_UNKNOWN_0x6D);
            gUnknown_0202C794 = 0;
            sub_70E0(gUnknown_0202ADE0, 0);
            gUnknown_02019C28 = gUnknown_0202C794;
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if ((gUnknown_0202ADE0 < BONUS_SPECIES_START) && (gUnknown_0202C794 == 0))
        {
            m4aSongNumStart(SE_UNKNOWN_0x6D);
            gUnknown_0202C794 = 1;
            sub_70E0(gUnknown_0202ADE0, 1);
            gUnknown_02019C28 = gUnknown_0202C794;
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        if (gUnknown_0202ADE0 < BONUS_SPECIES_START)
        {
            if (!gUnknown_0202C794)
            {
                m4aSongNumStart(SE_UNKNOWN_0x6D);
                gUnknown_0202C794 = 1 - gUnknown_0202C794;
                sub_70E0(gUnknown_0202ADE0,gUnknown_0202C794);
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
                gMain.subState = 4;
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
        gMain.subState = 4;
    }

    if (JOY_HELD(SELECT_BUTTON))
    {
        if (gUnknown_0202A1C0[gUnknown_0202ADE0] == 4)
        {
            if (gUnknown_086A61BC[gUnknown_0202ADE0] == -1)
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
                if (gUnknown_086A61BC[gUnknown_0202ADE0] < 100)
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
        if (sub_8A78(gUnknown_0202ADE0) == 1)
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
        gMain.subState = 1;
    }
}

void sub_49A8(void)
{
    sub_19B4();
    sub_5E60();
    gUnknown_0201B124 = 0;
    sub_599C();
    gMain.subState = 7;
}

void sub_49D0(void)
{
    s16 var0;

    sub_599C();

    if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x66);
        gUnknown_0202BEC4 = 0;
        gUnknown_0202BEFC = 0;
        gUnknown_0202BF04 = 1;
        gUnknown_0202A588 = 1;
        sub_2568();
        gMain.subState = 1;
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
                    gMain.subState = 9;
                }
                else if (var0 == 1)
                {
                    gUnknown_0202BEFC = 2;
                    gMain.subState = 8;
                    m4aSongNumStart(SE_FAILURE);
                }
            }

            gUnknown_0201A510++;

            if ((gUnknown_0202ADD0 & 0x7f0000) && (gUnknown_0201B128 == -1))
            {
                gUnknown_0201A444++;
                if (0xB4 < gUnknown_0201A444)
                {
                    gUnknown_0202BEFC = 2;
                    gMain.subState = 8;
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
        gMain.subState = 6;
    }
}

void sub_4B34(void)
{
    s32 iVar1;

    sub_599C();
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
        gMain.subState = 0;
    }
}

void sub_4BB4(void)
{
    s32 index;

    sub_599C();
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
            gMain.subState = 0;
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
        gMain.subState = 0;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_UNKNOWN_0x66);
        gUnknown_0202BEC4 = 0;
        gUnknown_0202BEFC = 0;
        gUnknown_0202BF04 = 1;
        gUnknown_0202A588 = 1;
        gMain.subState = 1;


    }
}

void sub_4D50(void)
{
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();

    gAutoDisplayTitlescreenMenu = 1;
    SetMainGameState(STATE_TITLE);
}

static void sub_4D74(void)
{
    if (gUnknown_0202C58C != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;

    if (gUnknown_0202A57C == 0)
    {
        if (gUnknown_0202C5B0 == 0)
        {
            if (gUnknown_02019C24 == 0)
            {
                gUnknown_0202C5B0 = gUnknown_0202A574 - 5;
                gUnknown_0202ADE0 = gUnknown_0202A574 - 1;
                gUnknown_0202A57C = 4;
                m4aSongNumStart(SE_SELECT);
            }
        }
        else
        {
            gUnknown_0202C5B0--;
            gUnknown_0202ADE0--;
            m4aSongNumStart(SE_SELECT);
        }

        gUnknown_0202C58C = 9;
    }
    else
    {
        m4aSongNumStart(SE_SELECT);
        gUnknown_0202A57C--;
        gUnknown_0202ADE0--;

        gUnknown_0202C58C = 9;
    }

    gUnknown_02019C24 = 1;
}

static void sub_4E34(void)
{
    if (gUnknown_0202C58C != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;
    if (gUnknown_0202A57C == 4)
    {
        if (gUnknown_0202C5B0 == gUnknown_0202A574 - 5)
        {
            if (gUnknown_02019C24 == 0)
            {
                gUnknown_0202C5B0 = 0;
                gUnknown_0202ADE0 = 0;
                gUnknown_0202A57C = 0;
                m4aSongNumStart(SE_SELECT);
            }
        }
        else
        {
            gUnknown_0202C5B0++;
            gUnknown_0202ADE0++;
            m4aSongNumStart(SE_SELECT);
        }

        gUnknown_0202C58C = 9;
    }
    else
    {
        m4aSongNumStart(SE_SELECT);
        gUnknown_0202A57C++;
        gUnknown_0202ADE0++;
        gUnknown_0202C58C = 9;
    }

    gUnknown_02019C24 = 1;
}

static void sub_4EF0(void)
{
    if (gUnknown_0202C58C != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;
    if (gUnknown_0202C5B0 == 0)
        return;

    m4aSongNumStart(SE_SELECT);
    gUnknown_0202C5B0 -= 5;
    if (gUnknown_0202C5B0 < 0)
        gUnknown_0202C5B0 = 0;

    gUnknown_0202ADE0 = gUnknown_0202C5B0 + gUnknown_0202A57C;
    gUnknown_0202C58C = 9;
}

void sub_4F50(void)
{
    if (gUnknown_0202C58C != 0)
        return;

    gUnknown_0201A440 = 0;
    gUnknown_0202BF0C = 0;
    if (gUnknown_0202C5B0 == gUnknown_0202A574 - 5)
        return;

    m4aSongNumStart(SE_SELECT);
    gUnknown_0202C5B0 += 5;
    if (gUnknown_0202C5B0 > gUnknown_0202A574 - 5)
        gUnknown_0202C5B0 = gUnknown_0202A574 - 5;

    gUnknown_0202ADE0 = gUnknown_0202C5B0 + gUnknown_0202A57C;
    gUnknown_0202C58C = 9;
}

void sub_4FC8(void)
{
    if (JOY_HELD_EXACT(L_BUTTON | DPAD_LEFT) && JOY_NEW(R_BUTTON))
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
            gMain.subState = 11;
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
    if (gUnknown_0202A1C0[gUnknown_0202ADE0] == 4)
    {
        if (gUnknown_086A61BC[gUnknown_0202ADE0] == -1)
        {
            gUnknown_0202A588 = 0;
            gUnknown_0202A55C = 1;
            gUnknown_0202A568[0] = 0;
            gUnknown_0202A568[1] = 0;
            gUnknown_0201A440 = 0;
            gUnknown_0202BF0C = 0;
        }
        else if (gUnknown_086A61BC[gUnknown_0202ADE0] < 100)
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
    if (gUnknown_0202A1C0[gUnknown_0202ADE0] == 4 && gUnknown_086A61BC[gUnknown_0202ADE0] != -1)
    {
        if (gUnknown_086A61BC[gUnknown_0202ADE0] < 100)
            return 1;

        return 2;
    }

    return 0;
}

void sub_5174(void)
{
    sub_6CA0(gUnknown_0202C5B0);
    sub_6F30(gUnknown_0202C5B0);
    sub_681C(gUnknown_0202ADE0);
    sub_6F78(gUnknown_0202ADE0);
    sub_8974(gUnknown_0202ADE0);
    sub_8A78(gUnknown_0202ADE0);
    gUnknown_0202BF00 = 0;
    gUnknown_0201A448 = 0;
}

void sub_51CC(void)
{
    if (sub_5134() == 0)
        sub_6F78(gUnknown_0202ADE0);
    else
        sub_8974(gUnknown_0202ADE0);
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

    group0->available = 1;
    group1->available = 1;
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

    if (gUnknown_0202ADE0 < 200)
        gUnknown_0202BF08 = 86 + gUnknown_0202ADE0 / 3;
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
            gOamBuffer[group2->oam[i].oamId].priority = 1;
            gOamBuffer[group2->oam[i].oamId].x = groupOam->xOffset + group2->baseX;
            gOamBuffer[group2->oam[i].oamId].y = groupOam->yOffset + group2->baseY;
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
                                                   ;
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
        if (gUnknown_086A6356[gUnknown_0202ADE0] == -1)
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
        int sp10, spC;
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

    group5->available = 0;
    group6->available = 0;
    group7->available = 0;
    group9->available = 0;
}
