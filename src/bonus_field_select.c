#include "global.h"
#include "constants/bg_music.h"
#include "m4a.h"
#include "main.h"
#include "functions.h"
#include "titlescreen.h"

enum BonusFieldSelectStates
{
    BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD,
    BONUS_FIELD_SELECT_STATE_BALL_SPEED,
    BONUS_FIELD_SELECT_STATE_LOAD_FIELD,
};

enum BonusFieldSelection
{
    FIELD_SELECT_DUSCLOPS,
    FIELD_SELECT_KECLEON,
    FIELD_SELECT_SPHEAL,
    FIELD_SELECT_GROUDON,
    FIELD_SELECT_KYOGRE,
    FIELD_SELECT_RAYQUAZA,
};

EWRAM_DATA s8 gUnknown_0201A4B0 = 0;
EWRAM_DATA u8 gUnknown_0201A4C0 = 0;
EWRAM_DATA s16 gUnknown_0201A4F4 = 0;
EWRAM_DATA s8 gSelectedBonusField = 0;
EWRAM_DATA s16 gBonusFieldSelectTimer = 0;
EWRAM_DATA s16 gUnknown_0202BE1C = 0;
EWRAM_DATA s8 gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD;
EWRAM_DATA s8 gBonusFieldSelectNextMainState = STATE_INTRO;
EWRAM_DATA u8 gUnknown_0202BEE8 = 0;

extern void (*const gBonusFieldSelectStateFuncs[])(void);

extern const struct SpriteSet *const gUnknown_086A4C80[16];
extern const struct VectorU16 gUnknown_086A4CC0[];
extern const struct VectorU16 gUnknown_086A4CD8[];
extern const u8 gBonusFieldMenuSelectionToField[];

extern const u8 gUnknown_0807AAE0[];
extern const u8 gUnknown_0807B2E0[];
extern const u8 gUnknown_0807BAE0[];
extern const u16 gUnknown_0807C2E0[];
extern const u8 gUnknown_0807C4E0[];

void sub_2710(void);
void sub_29C8(void);

void BonusFieldSelectMain(void)
{
    gBonusFieldSelectStateFuncs[gMain.subState]();
}

void LoadBonusFieldSelectGraphics(void)
{
    ResetSomeGraphicsRelatedStuff();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(2) | BGCNT_PRIORITY(3) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;

    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gUnknown_0807C2E0, (void *)PLTT, 0x200);
    DmaCopy16(3, gFieldSelectWindow_Gfx, (void *)(VRAM + 0x4000), 0x4000);
    DmaCopy16(3, gUnknown_0807C4E0, (void *)(VRAM + 0x8000), 0x1800);
    DmaCopy16(3, gUnknown_0807AAE0, (void *)VRAM, 0x800);
    DmaCopy16(3, gUnknown_0807B2E0, (void *)(VRAM + 0x800), 0x800);
    DmaCopy16(3, gUnknown_0807BAE0, (void *)(VRAM + 0x1000), 0x800);
    DmaCopy16(3, gFieldSelectSpritePals, (void *)(PLTT + 0x200), 0x60);
    DmaCopy16(3, gFieldSelectSpriteGfx, (void *)(VRAM + 0x10000), 0x4020);

    sub_0CBC();
    sub_2710();
    sub_FD5C(sub_29C8);
    m4aSongNumStart(MUS_TABLE_SELECT);

    gMain.subState++;
}

void sub_2710(void)
{
    gSelectedBonusField = FIELD_SELECT_DUSCLOPS;
    gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD;
    gBonusFieldSelectTimer = 0;
    gUnknown_0202BE1C = 0;
    gUnknown_0202BEE8 = 0;
    gUnknown_0201A4F4 = 0;
    gUnknown_0201A4B0 = 0;
    gBonusFieldSelectNextMainState = STATE_INTRO;
    gUnknown_0201A4C0 = gMain_saveData.ballSpeed;
}

void sub_2768(void)
{
    sub_29C8();
    switch (gBonusFieldSelectState)
    {
    case BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD:
        if (JOY_NEW(DPAD_LEFT))
        {
            if (gSelectedBonusField != FIELD_SELECT_DUSCLOPS && gSelectedBonusField != FIELD_SELECT_GROUDON)
            {
                m4aSongNumStart(SE_UNKNOWN_0x6D);
                gSelectedBonusField--;
            }
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (gSelectedBonusField != FIELD_SELECT_SPHEAL && gSelectedBonusField != FIELD_SELECT_RAYQUAZA)
            {
                m4aSongNumStart(SE_UNKNOWN_0x6D);
                gSelectedBonusField++;
            }
        }
        if (JOY_NEW(DPAD_UP))
        {
            if (gSelectedBonusField > FIELD_SELECT_SPHEAL)
            {
                m4aSongNumStart(SE_UNKNOWN_0x6D);
                gSelectedBonusField -= 3;
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (gSelectedBonusField < FIELD_SELECT_GROUDON)
            {
                m4aSongNumStart(SE_UNKNOWN_0x6D);
                gSelectedBonusField += 3;
            }
        }
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x65);
            gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_BALL_SPEED;
            gUnknown_0201A4B0 = 1;
            gBonusFieldSelectTimer = 0;
        }
        if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x66);
            gBonusFieldSelectNextMainState = STATE_TITLE;
            gMain.subState++;
        }
        break;
    case BONUS_FIELD_SELECT_STATE_BALL_SPEED:
        if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        {
            m4aSongNumStart(SE_SELECT);
            gUnknown_0201A4C0 = 1 - gUnknown_0201A4C0;
        }
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x65);
            gBonusFieldSelectTimer = 0;
            gUnknown_0202BE1C = 0;
            gMain.saveData.ballSpeed = gUnknown_0201A4C0;
            SaveFile_WriteToSram();
            gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_LOAD_FIELD;
        }
        if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_UNKNOWN_0x66);
            gUnknown_0201A4B0 = 0;
            gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD;
        }
        gBonusFieldSelectTimer++;
        if (gBonusFieldSelectTimer > 4)
        {
            gBonusFieldSelectTimer = 0;
            gUnknown_0201A4F4 = 1 - gUnknown_0201A4F4;
        }
        break;
    case BONUS_FIELD_SELECT_STATE_LOAD_FIELD:
        gBonusFieldSelectTimer++;
        if (gBonusFieldSelectTimer > 5)
        {
            gBonusFieldSelectTimer = 0;
            gUnknown_0202BEE8 = 2 - gUnknown_0202BEE8;
            gUnknown_0202BE1C++;
            if (gUnknown_0202BE1C > 5)
            {
                gMain.unkD = 0;
                gMain.unk5 = gMain.selectedField = gBonusFieldMenuSelectionToField[gSelectedBonusField];
                gMain.unk6 = 1;
                gBonusFieldSelectNextMainState = STATE_GAME_MAIN;
                gMain.subState++;
            }
        }
        break;
    }
}

void sub_2990(void)
{
    sub_FE04(sub_29C8);
    m4aMPlayAllStop();
    sub_0D10();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(gBonusFieldSelectNextMainState);
}

void sub_29C8(void)
{
    struct SpriteGroup * sgptrs[6];
    struct SpriteGroup * r8;
    struct SpriteGroup * r10;
    struct OamDataSimple * simple;
    s32 i;
    s32 j;

    gMain.blendControl = BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_NONE | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3;
    gMain.blendAlpha = BLDALPHA_BLEND(8, 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;
    for (i = 0; i < 6; i++)
    {
        sgptrs[i] = &gMain.spriteGroups[i];
    }
    r10 = &gMain.spriteGroups[6 + gSelectedBonusField];
    r8 = &gMain.spriteGroups[12 + gUnknown_0201A4C0 * 2 + gUnknown_0201A4F4];
    for (j = 0; j < 6; j++)
    {
        sgptrs[j]->available = TRUE;
    }
    sgptrs[gSelectedBonusField]->available = FALSE;
    r10->available = TRUE;
    r8->available = gUnknown_0201A4B0;
    LoadSpriteSets(gUnknown_086A4C80, 16, gUnknown_0200B3B8);
    for (i = 0; i < 6; i++)
    {
        if (sgptrs[i]->available == 1)
        {
            sgptrs[i]->baseX = gUnknown_086A4CC0[i].x;
            sgptrs[i]->baseY = gUnknown_086A4CC0[i].y;
            for (j = 0; j < 4; j++)
            {
                simple = &sgptrs[i]->oam[j];
                gOamBuffer[simple->oamId].objMode = ST_OAM_OBJ_BLEND;
                gOamBuffer[simple->oamId].x = simple->xOffset + sgptrs[i]->baseX;
                gOamBuffer[simple->oamId].y = simple->yOffset + sgptrs[i]->baseY;
            }
        }
    }
    r10->baseX = 0x58;
    r10->baseY = 0x85;
    for (j = 0; j < 2; j++)
    {
        simple = &r10->oam[j];
        gOamBuffer[simple->oamId].objMode = ST_OAM_OBJ_NORMAL;
        gOamBuffer[simple->oamId].paletteNum = gUnknown_0202BEE8;
        gOamBuffer[simple->oamId].x = simple->xOffset + r10->baseX;
        gOamBuffer[simple->oamId].y = simple->yOffset + r10->baseY;
    }
    if (r8->available == 1)
    {
        r8->baseX = gUnknown_086A4CD8[gSelectedBonusField].x;
        r8->baseY = gUnknown_086A4CD8[gSelectedBonusField].y;
        for (j = 0; j < 5; j++)
        {
            simple = &r8->oam[j];
            gOamBuffer[simple->oamId].objMode = ST_OAM_OBJ_NORMAL;
            gOamBuffer[simple->oamId].x = simple->xOffset + r8->baseX;
            gOamBuffer[simple->oamId].y = simple->yOffset + r8->baseY;
        }
    }
    for (j = 0; j < 6; j++)
    {
        sgptrs[j]->available = FALSE;
    }
    r10->available = FALSE;
    r8->available = FALSE;
}
