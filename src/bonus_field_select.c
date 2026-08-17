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

EWRAM_DATA s8 gBallSpeedSubmenuVisible = FALSE;
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
extern const Palette gBonusFieldSelectStages_Pals[];
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

    DmaCopy16(3, gBonusFieldSelectStages_Pals, BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gFieldSelectWindow_Gfx, BG_CHAR_ADDR(1), BG_CHAR_SIZE);
    DmaCopy16(3, gBonusFieldSelectStages_Gfx, BG_CHAR_ADDR(2), 3*BG_SCREEN_SIZE);
    DmaCopy16(3, gBonusFieldSelectBg0_Tilemap, BG_CHAR_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gBonusFieldSelectBg1_Tilemap, BG_CHAR_SCREEN_ADDR(0,1), BG_SCREEN_SIZE);
    DmaCopy16(3, gBonusFieldSelectBg2_Tilemap, BG_CHAR_SCREEN_ADDR(0,2), BG_SCREEN_SIZE);
    DmaCopy16(3, gFieldSelectSpritePals, OBJ_PLTT_SLOT(0), 3*PLTT_SLOT_SIZE);
    DmaCopy16(3, gFieldSelectSpriteGfx, OBJ_VRAM0, 0x4020);

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
    gBallSpeedSubmenuVisible = FALSE;
    gBonusFieldSelectNextMainState = STATE_INTRO;
    gSelectedBallSpeed = gMain_saveData.ballSpeed;
}

void BonusFieldSelect_Menu(void)
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
            gBallSpeedSubmenuVisible = TRUE;
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
            gBallSpeedSubmenuVisible = FALSE;
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
                gMain.continueFromSave = FALSE;
                gMain.tempField = gMain.selectedField = gBonusFieldMenuSelectionToField[gSelectedBonusField];
                gMain.isBonusField = TRUE;
                gBonusFieldSelectNextMainState = STATE_GAME_MAIN;
                gMain.subState++;
            }
        }
        break;
    }
}

void BonusFieldSelect_FadeToSelection(void)
{
    FadeOutToWhite(RenderBonusFieldSelectSprites);
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(gBonusFieldSelectNextMainState);
}

void RenderBonusFieldSelectSprites(void)
{
    struct SpriteGroup * boardDimmerPaneSGs[6];
    struct SpriteGroup * ballSpeedSG;
    struct SpriteGroup * boardTitleSG;
    struct OamDataSimple * simple;
    s32 i;
    s32 j;

    gMain.blendControl = BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_NONE | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3;
    gMain.blendAlpha = BLDALPHA_BLEND(8, 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;
    for (i = 0; i < 6; i++)
    {
        boardDimmerPaneSGs[i] = &gMain.spriteGroups[i];
    }

    boardTitleSG = &gMain.spriteGroups[SG_BONUS_FIELD_SELECT_BOARD_TITLE_BASE + gSelectedBonusField];
    ballSpeedSG = &gMain.spriteGroups[SG_FIELD_SELECT_BALL_SPEED_SELECT_BASE + gSelectedBallSpeed * 2 + gBallSpeedDisplayToggle];
    for (j = 0; j < 6; j++)
    {
        boardDimmerPaneSGs[j]->active = TRUE;
    }
    boardDimmerPaneSGs[gSelectedBonusField]->active = FALSE;
    boardTitleSG->active = TRUE;
    ballSpeedSG->active = gBallSpeedSubmenuVisible;
    LoadSpriteSets(gBonusFieldSelectSpriteSets, 16, gMain.spriteGroups);
    for (i = 0; i < 6; i++) // bonus field count
    {
        if (boardDimmerPaneSGs[i]->active == TRUE)
        {
            boardDimmerPaneSGs[i]->baseX = gBonusFieldStageIconPositions[i].x;
            boardDimmerPaneSGs[i]->baseY = gBonusFieldStageIconPositions[i].y;
            for (j = 0; j < 4; j++)
            {
                simple = &boardDimmerPaneSGs[i]->oam[j];
                gOamBuffer[simple->oamId].objMode = ST_OAM_OBJ_BLEND;
                gOamBuffer[simple->oamId].x = simple->xOffset + boardDimmerPaneSGs[i]->baseX;
                gOamBuffer[simple->oamId].y = simple->yOffset + boardDimmerPaneSGs[i]->baseY;
            }
        }
    }
    boardTitleSG->baseX = 0x58;
    boardTitleSG->baseY = 0x85;
    for (j = 0; j < 2; j++)
    {
        simple = &boardTitleSG->oam[j];
        gOamBuffer[simple->oamId].objMode = ST_OAM_OBJ_NORMAL;
        gOamBuffer[simple->oamId].paletteNum = gBonusFieldHighlightPalette;
        gOamBuffer[simple->oamId].x = simple->xOffset + boardTitleSG->baseX;
        gOamBuffer[simple->oamId].y = simple->yOffset + boardTitleSG->baseY;
    }
    if (ballSpeedSG->active == TRUE)
    {
        ballSpeedSG->baseX = gBonusFieldSpeedIndicatorPositions[gSelectedBonusField].x;
        ballSpeedSG->baseY = gBonusFieldSpeedIndicatorPositions[gSelectedBonusField].y;
        for (j = 0; j < 5; j++)
        {
            simple = &ballSpeedSG->oam[j];
            gOamBuffer[simple->oamId].objMode = ST_OAM_OBJ_NORMAL;
            gOamBuffer[simple->oamId].x = simple->xOffset + ballSpeedSG->baseX;
            gOamBuffer[simple->oamId].y = simple->yOffset + ballSpeedSG->baseY;
        }
    }
    for (j = 0; j < 6; j++)
    {
        boardDimmerPaneSGs[j]->active = FALSE;
    }
    boardTitleSG->active = FALSE;
    ballSpeedSG->active = FALSE;
}
