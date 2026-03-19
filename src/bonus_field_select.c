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

EWRAM_DATA s8 gBallSpeedSubmenuVisible = 0;
EWRAM_DATA u8 gSelectedBallSpeed = 0;
EWRAM_DATA s16 gBallSpeedDisplayToggle = 0;
EWRAM_DATA s8 gSelectedBonusField = 0;
EWRAM_DATA s16 gBonusFieldSelectTimer = 0;
EWRAM_DATA s16 gBonusFieldLoadingCounter = 0;
EWRAM_DATA s8 gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD;
EWRAM_DATA s8 gBonusFieldSelectNextMainState = STATE_INTRO;
EWRAM_DATA u8 gBonusFieldHighlightPalette = 0;

extern void (*const gBonusFieldSelectStateFuncs[])(void);

extern const struct SpriteSet *const gBonusFieldSelectSpriteSets[16];
extern const struct VectorU16 gBonusFieldStageIconPositions[];
extern const struct VectorU16 gBonusFieldSpeedIndicatorPositions[];
extern const u8 gBonusFieldMenuSelectionToField[];

extern const u8 gBonusFieldSelectBg0_Tilemap[];
extern const u8 gBonusFieldSelectBg1_Tilemap[];
extern const u8 gBonusFieldSelectBg2_Tilemap[];
extern const u16 gBonusFieldSelectStages_Pals[];
extern const u8 gBonusFieldSelectStages_Gfx[];

void InitBonusFieldSelectState(void);
void RenderBonusFieldSelectSprites(void);

void BonusFieldSelectMain(void)
{
    gBonusFieldSelectStateFuncs[gMain.subState]();
}

void LoadBonusFieldSelectGraphics(void)
{
    ResetDisplayState();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(2) | BGCNT_PRIORITY(3) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;

    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gBonusFieldSelectStages_Pals, (void *)PLTT, 0x200);
    DmaCopy16(3, gFieldSelectWindow_Gfx, (void *)(VRAM + 0x4000), 0x4000);
    DmaCopy16(3, gBonusFieldSelectStages_Gfx, (void *)(VRAM + 0x8000), 0x1800);
    DmaCopy16(3, gBonusFieldSelectBg0_Tilemap, (void *)VRAM, 0x800);
    DmaCopy16(3, gBonusFieldSelectBg1_Tilemap, (void *)(VRAM + 0x800), 0x800);
    DmaCopy16(3, gBonusFieldSelectBg2_Tilemap, (void *)(VRAM + 0x1000), 0x800);
    DmaCopy16(3, gFieldSelectSpritePals, (void *)(PLTT + 0x200), 0x60);
    DmaCopy16(3, gFieldSelectSpriteGfx, (void *)(VRAM + 0x10000), 0x4020);

    EnableVBlankInterrupts();
    InitBonusFieldSelectState();
    FadeInFromWhite(RenderBonusFieldSelectSprites);
    m4aSongNumStart(MUS_TABLE_SELECT);

    gMain.subState++;
}

void InitBonusFieldSelectState(void)
{
    gSelectedBonusField = FIELD_SELECT_DUSCLOPS;
    gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD;
    gBonusFieldSelectTimer = 0;
    gBonusFieldLoadingCounter = 0;
    gBonusFieldHighlightPalette = 0;
    gBallSpeedDisplayToggle = 0;
    gBallSpeedSubmenuVisible = 0;
    gBonusFieldSelectNextMainState = STATE_INTRO;
    gSelectedBallSpeed = gMain_saveData.ballSpeed;
}

void BonusFieldSelect_State1_2768(void)
{
    RenderBonusFieldSelectSprites();
    switch (gBonusFieldSelectState)
    {
    case BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD:
        if (JOY_NEW(DPAD_LEFT))
        {
            if (gSelectedBonusField != FIELD_SELECT_DUSCLOPS && gSelectedBonusField != FIELD_SELECT_GROUDON)
            {
                m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                gSelectedBonusField--;
            }
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (gSelectedBonusField != FIELD_SELECT_SPHEAL && gSelectedBonusField != FIELD_SELECT_RAYQUAZA)
            {
                m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                gSelectedBonusField++;
            }
        }
        if (JOY_NEW(DPAD_UP))
        {
            if (gSelectedBonusField > FIELD_SELECT_SPHEAL)
            {
                m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                gSelectedBonusField -= 3;
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (gSelectedBonusField < FIELD_SELECT_GROUDON)
            {
                m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                gSelectedBonusField += 3;
            }
        }
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_BALL_SPEED;
            gBallSpeedSubmenuVisible = 1;
            gBonusFieldSelectTimer = 0;
        }
        if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gBonusFieldSelectNextMainState = STATE_TITLE;
            gMain.subState++;
        }
        break;
    case BONUS_FIELD_SELECT_STATE_BALL_SPEED:
        if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        {
            m4aSongNumStart(SE_MENU_MOVE);
            gSelectedBallSpeed = 1 - gSelectedBallSpeed;
        }
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            gBonusFieldSelectTimer = 0;
            gBonusFieldLoadingCounter = 0;
            gMain.saveData.ballSpeed = gSelectedBallSpeed;
            SaveFile_WriteToSram();
            gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_LOAD_FIELD;
        }
        if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gBallSpeedSubmenuVisible = 0;
            gBonusFieldSelectState = BONUS_FIELD_SELECT_STATE_CHOOSE_FIELD;
        }
        gBonusFieldSelectTimer++;
        if (gBonusFieldSelectTimer > 4)
        {
            gBonusFieldSelectTimer = 0;
            gBallSpeedDisplayToggle = 1 - gBallSpeedDisplayToggle;
        }
        break;
    case BONUS_FIELD_SELECT_STATE_LOAD_FIELD:
        gBonusFieldSelectTimer++;
        if (gBonusFieldSelectTimer > 5)
        {
            gBonusFieldSelectTimer = 0;
            gBonusFieldHighlightPalette = 2 - gBonusFieldHighlightPalette;
            gBonusFieldLoadingCounter++;
            if (gBonusFieldLoadingCounter > 5)
            {
                gMain.continueFromSave = 0;
                gMain.tempField = gMain.selectedField = gBonusFieldMenuSelectionToField[gSelectedBonusField];
                gMain.isBonusField = 1;
                gBonusFieldSelectNextMainState = STATE_GAME_MAIN;
                gMain.subState++;
            }
        }
        break;
    }
}

void BonusFieldSelect_State2_2990(void)
{
    FadeOutToWhite(RenderBonusFieldSelectSprites);
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(gBonusFieldSelectNextMainState);
}

void RenderBonusFieldSelectSprites(void)
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
    r8 = &gMain.spriteGroups[12 + gSelectedBallSpeed * 2 + gBallSpeedDisplayToggle];
    for (j = 0; j < 6; j++)
    {
        sgptrs[j]->available = TRUE;
    }
    sgptrs[gSelectedBonusField]->available = FALSE;
    r10->available = TRUE;
    r8->available = gBallSpeedSubmenuVisible;
    LoadSpriteSets(gBonusFieldSelectSpriteSets, 16, gMain_spriteGroups);
    for (i = 0; i < 6; i++)
    {
        if (sgptrs[i]->available == 1)
        {
            sgptrs[i]->baseX = gBonusFieldStageIconPositions[i].x;
            sgptrs[i]->baseY = gBonusFieldStageIconPositions[i].y;
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
        gOamBuffer[simple->oamId].paletteNum = gBonusFieldHighlightPalette;
        gOamBuffer[simple->oamId].x = simple->xOffset + r10->baseX;
        gOamBuffer[simple->oamId].y = simple->yOffset + r10->baseY;
    }
    if (r8->available == 1)
    {
        r8->baseX = gBonusFieldSpeedIndicatorPositions[gSelectedBonusField].x;
        r8->baseY = gBonusFieldSpeedIndicatorPositions[gSelectedBonusField].y;
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
