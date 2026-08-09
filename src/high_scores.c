#include "global.h"
#include "functions.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "constants/sprite_groups.h"
#include "constants/score.h"

extern StateFunc gHighScoresStateFuncs[15];
extern StateFunc gIdleHighScoresStateFuncs[3];
extern u8 gHighScoreBG_Pals[];
extern u8 gHighScoreBallWatermark_Tilemap[];
extern u8 gHighScoreText_Gfx[];
extern s16 gHighScoreEntrySource;
extern s8 gCompletionBannerDone;
extern s8 gCompletionBannerVisible;
extern s16 gCompletionBannerY;
extern s8 gCompletionBannerPhase;
extern s8 gCompletionBannerSpriteGroup;
extern s8 gHighScoreShowPopupFlag;
extern u8 gHighScorePopupType;
extern u16 gLinkExchangeCommand;
extern u16 gLinkPacketCounter;
extern s8 gLinkExchangeSendPhase;
extern s8 gLinkExchangeRecvPhase;
extern s8 gLinkExchangeTimeout;

extern s16 gScrollDirection;
extern s16 gScrollXOffset;
extern s8 gResetComboTimer;
extern s8 gResetComboCount;

struct HighScoreScreenState
{
    u32 newScoreHi;
    u32 newScoreLo;
    s16 displayTimer;
    u8 nextSubState;
    u8 mainField;
    s32 highScoreIndex;
    s16 currentNameCharIndex;
    s16 nameFlashVariant; // Toggles between variant 0 and 1
    s16 flashFrameCounter;
    s16 currentNameChar; //0-25="A"-"Z", 26-35="0"-"9" 41=" "
    s16 flashDuration;
    s16 flashElapsedFrames; // also used for page arrow blink toggle
    s16 paletteAnimPhase;
    s16 paletteAnimTimer;
    s16 inputRepeatDelay;
    s16 linkWaitTimer;
    s8 nextIdleState;
    s8 pressStartBlinkToggle; // press start blink toggle
    s8 displayModeVisible;
};

enum HighScoreStates{
    HIGH_SCORE_STATE_INIT = 0,
    HIGH_SCORE_STATE_SHOW_COMPLETION_BANNER = 1,
    HIGH_SCORE_STATE_FLASH_NEW_SCORE_POSITION = 2,
    HIGH_SCORE_STATE_BROWSE_SCORES = 3,
    HIGH_SCORE_STATE_NAME_ENTRY = 4,
    HIGH_SCORE_STATE_INIT_LINK_EXCHANGE = 5,
    HIGH_SCORE_STATE_LINK_EXCHANGE_LOOP = 6,
    HIGH_SCORE_STATE_LINK_ERROR = 7,
    HIGH_SCORE_STATE_LINK_SUCCESS = 8,
    HIGH_SCORE_STATE_LINK_RETRY_WAIT = 9,
    HIGH_SCORE_STATE_RESET_CONFIRMATION = 10,
    HIGH_SCORE_STATE_EXIT_TO_TITLE = 11,
    HIGH_SCORE_STATE_RELOAD_AFTER_LINK = 12,
    HIGH_SCORE_STATE_SHOW_MERGED_SCORES = 13,
    HIGH_SCORE_STATE_RETURN_TO_MAIN = 14
};

enum IdleHighScoreStates{
    IDLE_HIGH_SCORE_STATE_INIT = 0,
    IDLE_HIGH_SCORE_STATE_AUTOSCROLL = 1,
    IDLE_HIGH_SCORE_STATE_EXIT = 2
};

struct HighScoreScreenState gHighScoreScreenState;

extern struct HighScoreEntry gWorkingHighScores[MAIN_FIELD_COUNT][NUM_HIGH_SCORES];
extern struct HighScoreEntry gRemoteTopScores[2];
extern u8 gHighScoreBallWatermark_Gfx[];
extern u8 gHighScoreScoreTable_Tilemap[];
extern u8 gHighScoreSprite_Pals[];
extern u8 gHighScoreDialogs_Gfx[];
extern u32 gHighScoreNameRowTilemapOffsets[8];
extern const struct HighScoreEntry gDefaultHighScores[2][8];

enum HighScorePopupType {
    HIGH_SCORE_POPUP_DEFAULT = 0,
    HIGH_SCORE_POPUP_TRANSMISSION_CONNECT_PROMPT = 0,
    HIGH_SCORE_POPUP_TRANSMITTING_ACTIVE = 1,
    HIGH_SCORE_POPUP_TRANSMISSION_ERROR = 2,
    HIGH_SCORE_POPUP_TRANSMISSION_COMPLETE = 3,
    HIGH_SCORE_POPUP_DELETE_CONFIRMATION_PROMPT = 4
};

void HighScoresMain(void)
{
    gHighScoresStateFuncs[gMain.subState]();
}

void IdleHighScoresMain(void)
{
    gIdleHighScoresStateFuncs[gMain.subState]();
}

void LoadHighScoreGraphics(void)
{
  ResetDisplayState();
  REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_FORCED_BLANK;
  REG_BG2CNT = 0x4006;
  REG_DISPCNT |= DISPCNT_BG2_ON;
  REG_BG3CNT = 0x420f;
  REG_DISPCNT |= DISPCNT_BG3_ON;
  gMain.dispcntBackup = REG_DISPCNT;

  DmaCopy16(3, gHighScoreBG_Pals, (void*) PLTT, 0x200);
  DmaCopy16(3, gHighScoreText_Gfx, (void*) BG_VRAM + 0x4000, 0x4800);
  DmaCopy16(3, gHighScoreBallWatermark_Gfx, (void *)BG_VRAM + 0xC000, 0x2C00);
  DmaCopy16(3, gHighScoreScoreTable_Tilemap, gBG0TilemapBuffer, 0x1000);
  DmaCopy16(3, gHighScoreBallWatermark_Tilemap, (void *)BG_SCREEN_ADDR(2), 0x1000);
  DmaCopy16(3, gHighScoreSprite_Pals, (void *)OBJ_PLTT, 0x100);
  DmaCopy16(3, gHighScoreDialogs_Gfx, (void *)OBJ_VRAM0, 0x4420);
  InitHighScoreData();
  DrawAllHighScoreText();
  DmaCopy16(3, gBG0TilemapBuffer,0x6000000, 0x1000);
  if(gHighScoreEntrySource == 0)
      m4aSongNumStart(MUS_HIGH_SCORE);

  gHighScoreEntrySource = 0;
  EnableVBlankInterrupts();
  FadeInScreen();
  gMain.subState = gHighScoreScreenState.nextSubState;
}

void InitHighScoreData(void)
{
    int i, j, k;
    for(i = 0; i < MAIN_FIELD_COUNT; i++)
    {
        for(j = 0; j < NUM_HIGH_SCORES; j++)
        {
            for(k = 0; k < HIGH_SCORE_NAME_LENGTH + 2; k++) // ? use an array count instead?
                gWorkingHighScores[i][j].data.raw[k] = gMain_saveData.highScores[i][j].data.raw[k];
        }
    }
    for(i = 0; i < MAIN_FIELD_COUNT; i++)
    {
        for(j = 0; j <  HIGH_SCORE_NAME_LENGTH + 2; j++)
        {
            gRemoteTopScores[i].data.raw[j] = gWorkingHighScores[i][0].data.raw[j];
        }
    }
    gHighScoreScreenState.currentNameCharIndex = 0;
    gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_0;
    gHighScoreScreenState.flashFrameCounter = 0;
    gHighScoreScreenState.flashDuration = 0;
    gHighScoreScreenState.flashElapsedFrames = 0;
    gHighScoreScreenState.paletteAnimTimer = 0;
    gHighScoreScreenState.paletteAnimPhase = 0;
    gHighScoreScreenState.inputRepeatDelay = 0;
    gHighScoreScreenState.linkWaitTimer = 0;
    gHighScoreScreenState.pressStartBlinkToggle = 0;
    gHighScoreScreenState.displayModeVisible = 1;
    gHighScoreShowPopupFlag = FALSE;
    gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMITTING_ACTIVE;
    gCompletionBannerVisible = FALSE;
    gResetComboTimer = 0;
    gResetComboCount = 0;
    if(gHighScoreEntrySource == 1)
    {
        gHighScoreScreenState.newScoreHi = gMain.finalScoreHi;
        gHighScoreScreenState.newScoreLo = gMain.finalScoreLo;
        if(gMain.selectedField == FIELD_SAPPHIRE)
        {
            gHighScoreScreenState.mainField = FIELD_SAPPHIRE;
            gScrollXOffset = 0xF0;
            gScrollDirection = 1;
        }
        else
        {
            gHighScoreScreenState.mainField = FIELD_RUBY;
            gScrollXOffset = 0;
            gScrollDirection = -1;
        }
        gHighScoreScreenState.highScoreIndex = GetNewHighScoreIndex(gHighScoreScreenState.newScoreHi, gHighScoreScreenState.newScoreLo, gHighScoreScreenState.mainField);
        if(gHighScoreScreenState.highScoreIndex != -1)
        {
            InsertNewHighScore(gHighScoreScreenState.newScoreHi, gHighScoreScreenState.newScoreLo, gHighScoreScreenState.mainField, gHighScoreScreenState.highScoreIndex);
            for(i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
            {
                gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[i] = gHighScoreNameEntry[i];
            }
            gHighScoreScreenState.currentNameChar = gHighScoreNameEntry[0];
        }
        if(CheckAllPokemonCaught() == TRUE)
        {
            if(!gCompletionBannerDone)
            {
                gCompletionBannerVisible = TRUE;
                gCompletionBannerY = 0xB8;
                gCompletionBannerSpriteGroup = SG_HIGH_SCORE_COMPLETION_BANNER_LOOP_START;
                gCompletionBannerPhase = 0;
                gHighScoreScreenState.nextSubState = HIGH_SCORE_STATE_SHOW_COMPLETION_BANNER;
            }
            else
            {
                gCompletionBannerVisible = FALSE;
                gHighScoreScreenState.nextSubState = HIGH_SCORE_STATE_FLASH_NEW_SCORE_POSITION;
            }
        }
        else
        {
            gCompletionBannerDone = FALSE;
            gHighScoreScreenState.nextSubState = HIGH_SCORE_STATE_FLASH_NEW_SCORE_POSITION;
        }
    }
    else
    {
        gHighScoreScreenState.mainField = 0;
        gScrollXOffset = 0;
        gScrollDirection = -1;
        RenderHighScoreSprites();
        gHighScoreScreenState.nextSubState = HIGH_SCORE_STATE_BROWSE_SCORES;
    }
    gMain.bgOffsets[3].xOffset = gScrollXOffset;
    gMain.bgOffsets[2].xOffset = gScrollXOffset;
}

void HighScore_ShowCompletionBanner(void)
{
    u16 temp;
    switch(gCompletionBannerPhase)
    {
        case 0:
            if(gHighScoreScreenState.flashDuration == 3)
            {
                m4aSongNumStart(MUS_SUCCESS);
                gCompletionBannerPhase++;
            }
            break;
        case 1:
            gCompletionBannerY--;

            // TODO: FAKEMATCH - Seth
            temp = gHighScoreScreenState.flashDuration;
            if((gHighScoreScreenState.flashDuration & 3) == 0)
            {
                gCompletionBannerSpriteGroup++;
                if(gCompletionBannerSpriteGroup > SG_HIGH_SCORE_COMPLETION_BANNER_LOOP_END)
                {
                    gCompletionBannerSpriteGroup = SG_HIGH_SCORE_COMPLETION_BANNER_LOOP_START;
                }
            }
            if(gCompletionBannerY == 0x50)
            {
                gCompletionBannerSpriteGroup = SG_HIGH_SCORE_COMPLETION_BANNER_LOOP_START;
                gCompletionBannerPhase++;
            }
            break;
        case 2:
            if(JOY_NEW(A_BUTTON | B_BUTTON))
            {
                gCompletionBannerSpriteGroup = SG_HIGH_SCORE_COMPLETION_BANNER_LOOP_START;
                gCompletionBannerPhase++;
            }
            break;
        case 3:
            gCompletionBannerY -= 4;
            if(gCompletionBannerY < -0x18)
            {
                gHighScoreScreenState.flashDuration = 0;
                gCompletionBannerDone = TRUE;
                gCompletionBannerVisible = FALSE;
                gMain.subState = HIGH_SCORE_STATE_FLASH_NEW_SCORE_POSITION;
            }
            break;
    }

    gHighScoreScreenState.flashDuration++;
    RenderCompletionBanner();
}

void HighScore_FlashNewEntry(void)
{
    if(!gHighScoreScreenState.flashElapsedFrames)
    {
        if(gHighScoreScreenState.highScoreIndex == 0)
        {
            m4aSongNumStart(SE_HIGHEST_SCORE_EARNED);
            gHighScoreScreenState.flashDuration = 0xA0;
        }
        else if(gHighScoreScreenState.highScoreIndex == -1)
        {
            gHighScoreScreenState.flashDuration = 999;
            gHighScoreScreenState.flashElapsedFrames = 0;
            m4aSongNumStart(MUS_HIGH_SCORE);
            gMain.subState = HIGH_SCORE_STATE_BROWSE_SCORES;
        }
        else
        {
            m4aSongNumStart(SE_HIGH_SCORE_EARNED);
            gHighScoreScreenState.flashDuration = 0x5A;
        }
    }
    gHighScoreScreenState.flashFrameCounter++;
    if(gHighScoreScreenState.flashFrameCounter > 8)
    {
        gHighScoreScreenState.flashFrameCounter = 0;

        if(gHighScoreScreenState.nameFlashVariant == SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_0)
        {
            gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_1;
            CopyString(6 - (gHighScoreScreenState.mainField << 1), gHighScoreNameRowTilemapOffsets[gHighScoreScreenState.highScoreIndex] + (gHighScoreScreenState.mainField << 5), 0, 0x15, 4, 2);
            CopyString(0, 0x17, 6 - (gHighScoreScreenState.mainField << 1), gHighScoreNameRowTilemapOffsets[gHighScoreScreenState.highScoreIndex] + (gHighScoreScreenState.mainField << 5), 4, 2);
        }
        else
        {
            gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_0;
            CopyString(0, 0x15, 6 - (gHighScoreScreenState.mainField << 1), gHighScoreNameRowTilemapOffsets[gHighScoreScreenState.highScoreIndex] + (gHighScoreScreenState.mainField << 5), 4, 2);
        }
    }
    gHighScoreScreenState.paletteAnimTimer++;
    if(gHighScoreScreenState.paletteAnimTimer > 8)
    {
        gHighScoreScreenState.paletteAnimTimer = 0;
        AnimateScoreTilemapPalette(gHighScoreScreenState.mainField, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.paletteAnimPhase);
        gHighScoreScreenState.paletteAnimPhase++;
        if( gHighScoreScreenState.paletteAnimPhase > 2)
        {
            gHighScoreScreenState.paletteAnimPhase = 0;
        }
    }

    gHighScoreScreenState.flashElapsedFrames++;
    if(gHighScoreScreenState.flashElapsedFrames > gHighScoreScreenState.flashDuration)
    {
        gHighScoreScreenState.flashElapsedFrames = 0;
        if(gHighScoreScreenState.nameFlashVariant == SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_1)
        {
            gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_0;
            gHighScoreScreenState.flashFrameCounter = 0;
            CopyString(0, 0x15, 6 - (gHighScoreScreenState.mainField << 1), gHighScoreNameRowTilemapOffsets[gHighScoreScreenState.highScoreIndex] +(gHighScoreScreenState.mainField << 5), 4, 2);
        }
        m4aSongNumStart(MUS_HIGH_SCORE);
        gMain.subState = HIGH_SCORE_STATE_NAME_ENTRY;
    }

    DmaCopy16(3, gBG0TilemapBuffer, 0x6000000, 0x1000);
}

void HighScore_BrowseScores(void)
{
    RenderHighScoreSprites();
    if(!(gMain.systemFrameCount % 0xC))
    {
        gHighScoreScreenState.flashElapsedFrames = 1 - gHighScoreScreenState.flashElapsedFrames;
        gHighScoreScreenState.pressStartBlinkToggle = 1 - gHighScoreScreenState.pressStartBlinkToggle;
    }
    if(JOY_NEW(DPAD_LEFT))
    {
         if(gScrollDirection != -1)
         {
             gScrollDirection = -1;
         }
    }
    else if(JOY_NEW(DPAD_RIGHT))
    {
        if(gScrollDirection != 1)
         {
             gScrollDirection = 1;
         }
    }
    if(gScrollDirection > 0)
    {
        if(gScrollXOffset < 0xF0)
            gScrollXOffset += 8;
    }
    else if(gScrollDirection < 0)
    {
        if(gScrollXOffset > 0)
            gScrollXOffset -= 8;
    }
    if(JOY_NEW(A_BUTTON | B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gMain.subState = HIGH_SCORE_STATE_EXIT_TO_TITLE;
    }
    if(JOY_NEW(START_BUTTON))
    {
        if(gScrollXOffset == 0 || (gScrollXOffset == 0xF0))
        {
            m4aSongNumStart(SE_MENU_POPUP_OPEN);
            gHighScoreShowPopupFlag = TRUE;
            gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMISSION_CONNECT_PROMPT;
            gMain.subState = HIGH_SCORE_STATE_INIT_LINK_EXCHANGE;
        }
    }

    if(JOY_HELD(L_BUTTON | DPAD_LEFT) == (L_BUTTON | DPAD_LEFT))
    {
        if(JOY_NEW(R_BUTTON))
        {
            if(gScrollXOffset == 0 || gScrollXOffset == 0xF0)
            {
                gResetComboTimer = 0x28;
                gResetComboCount++;
                if(gResetComboCount == 3)
                {
                    gResetComboCount = 0;
                    gResetComboTimer = 0;
                    m4aSongNumStart(SE_MENU_POPUP_OPEN);
                    gHighScoreShowPopupFlag = TRUE;
                    gHighScorePopupType = HIGH_SCORE_POPUP_DELETE_CONFIRMATION_PROMPT;
                    gMain.subState = HIGH_SCORE_STATE_RESET_CONFIRMATION;
                }
            }
            if(gResetComboTimer > 0)
            {
                gResetComboTimer--;
                if(gResetComboTimer <= 0)
                {
                    gResetComboTimer = 0;
                    gResetComboCount = 0;
                }
            }
        }
    }
    else if(gResetComboTimer > 0)
    {
        gResetComboTimer--;
        if(gResetComboTimer <= 0)
        {
            gResetComboTimer = 0;
            gResetComboCount = 0;
        }
    }

    gMain.bgOffsets[3].xOffset = gScrollXOffset;
    gMain.bgOffsets[2].xOffset = gScrollXOffset;
}

void HighScore_NameEntry(void)
{
    int i, j, k;

    UpdateNameEntryCursor();
    if (++gHighScoreScreenState.flashFrameCounter > 12)
    {
        gHighScoreScreenState.flashFrameCounter = 0;
        gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_1 - gHighScoreScreenState.nameFlashVariant;
    }

    if (++gHighScoreScreenState.paletteAnimTimer > 8)
    {
        gHighScoreScreenState.paletteAnimTimer = 0;
        AnimateScoreTilemapPalette(gHighScoreScreenState.mainField, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.paletteAnimPhase);
        if (++gHighScoreScreenState.paletteAnimPhase > 2)
            gHighScoreScreenState.paletteAnimPhase = 0;
    }

    if (JOY_HELD(DPAD_DOWN))
    {
        if (gHighScoreScreenState.inputRepeatDelay == 0)
        {
            m4aSongNumStart(SE_SCORE_ENTRY_LETTER_CHANGE);
            if (--gHighScoreScreenState.currentNameChar < 0)
                gHighScoreScreenState.currentNameChar = 41;

            PrintHighScoreNameChar(gHighScoreScreenState.currentNameChar, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.currentNameCharIndex, gHighScoreScreenState.mainField);
            gHighScoreScreenState.inputRepeatDelay = 9;
        }
    }
    else if (JOY_HELD(DPAD_UP))
    {
        if (gHighScoreScreenState.inputRepeatDelay == 0)
        {
            m4aSongNumStart(SE_SCORE_ENTRY_LETTER_CHANGE);
            if (++gHighScoreScreenState.currentNameChar > 41)
                gHighScoreScreenState.currentNameChar = 0;

            PrintHighScoreNameChar(gHighScoreScreenState.currentNameChar, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.currentNameCharIndex, gHighScoreScreenState.mainField);
            gHighScoreScreenState.inputRepeatDelay = 9;
        }
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (gHighScoreScreenState.currentNameCharIndex == HIGH_SCORE_NAME_LENGTH - 1)
        {
            m4aSongNumStart(SE_FAILURE);
        }
        else
        {
            m4aSongNumStart(SE_MENU_MOVE);
            gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_1;
            PrintHighScoreNameChar(gHighScoreScreenState.currentNameChar, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.currentNameCharIndex, gHighScoreScreenState.mainField);
            gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex] = gHighScoreScreenState.currentNameChar;
            gHighScoreScreenState.currentNameCharIndex++;
            gHighScoreScreenState.currentNameChar = gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex];
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gHighScoreScreenState.currentNameCharIndex == 0)
        {
            m4aSongNumStart(SE_FAILURE);
        }
        else
        {
            m4aSongNumStart(SE_MENU_MOVE);
            gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_1;
            PrintHighScoreNameChar(gHighScoreScreenState.currentNameChar, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.currentNameCharIndex, gHighScoreScreenState.mainField);
            gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex] = gHighScoreScreenState.currentNameChar;
            gHighScoreScreenState.currentNameCharIndex--;
            gHighScoreScreenState.currentNameChar = gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex];
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_1;
        PrintHighScoreNameChar(gHighScoreScreenState.currentNameChar, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.currentNameCharIndex, gHighScoreScreenState.mainField);
        gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex] = gHighScoreScreenState.currentNameChar;
        if (gHighScoreScreenState.currentNameCharIndex == HIGH_SCORE_NAME_LENGTH - 1)
        {
            m4aSongNumStart(SE_MENU_SELECT);
            ResetScoreTilemapPalette(gHighScoreScreenState.mainField, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.paletteAnimPhase);
            for (i = 0; i < HIGH_SCORE_NAME_LENGTH; i++)
                gHighScoreNameEntry[i] = gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[i];

            for (i = 0; i < MAIN_FIELD_COUNT; i++)
            {
                for (j = 0; j < NUM_HIGH_SCORES; j++)
                {
                    for (k = 0; k < 6; k++)
                        gMain_saveData.highScores[i][j].data.raw[k] = gWorkingHighScores[i][j].data.raw[k];
                }
            }

            SaveFile_WriteToSram();
            gMain.subState = HIGH_SCORE_STATE_BROWSE_SCORES;
        }
        else
        {
            m4aSongNumStart(SE_SCORE_ENTRY_A_B_MOVE);
            gHighScoreScreenState.currentNameCharIndex++;
            gHighScoreScreenState.currentNameChar = gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex];
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if (gHighScoreScreenState.currentNameCharIndex == 0)
        {
            m4aSongNumStart(SE_FAILURE);
        }
        else
        {
            m4aSongNumStart(SE_SCORE_ENTRY_A_B_MOVE);
            gHighScoreScreenState.nameFlashVariant = SG_HIGH_SCORE_ENTRY_CURSOR_ARROW_1;
            PrintHighScoreNameChar(gHighScoreScreenState.currentNameChar, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.currentNameCharIndex, gHighScoreScreenState.mainField);
            gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex] = gHighScoreScreenState.currentNameChar;
            gHighScoreScreenState.currentNameCharIndex--;
            gHighScoreScreenState.currentNameChar = gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex];
        }
    }

    DmaCopy16(3, gBG0TilemapBuffer, 0x6000000, 0x1000);
    if (gHighScoreScreenState.inputRepeatDelay > 0)
        gHighScoreScreenState.inputRepeatDelay--;
}

void HighScore_InitLinkExchange(void)
{
    InitLinkHardware();
    InitLinkExchangeBuffers();
    gLinkExchangeStep = 0;
    RenderHighScoreSprites();
    gMain.subState = HIGH_SCORE_STATE_LINK_EXCHANGE_LOOP;
}

void HighScore_LinkExchangeLoop(void)
{
    RenderHighScoreSprites();
    if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gHighScoreShowPopupFlag = FALSE;
        gHighScorePopupType = HIGH_SCORE_POPUP_DEFAULT;
        ResetSerialAndInterrupts();
        gMain.subState = HIGH_SCORE_STATE_BROWSE_SCORES;
    }
    else
    {
        gLinkStatusResult = LinkMain1(&gLinkAdvanceState, gLinkSendBuffer, gLinkRecvBuffer);
        gLinkConnectionState = gLinkStatusResult & 3;
        gLinkPlayerCount = (gLinkStatusResult & 0x1c) >> 2;
        gLinkNegotiationFlags = (gLinkStatusResult & 0xe00) >> 9;
        if (((gLinkStatusResult & 0x40) != 0) && gLinkConnectionState < 2)
        {
            ProcessLinkSendData();
            if ((gLinkStatusResult & 0x100) == 0)
            {
                s16 linkErrorFlag = HighScore_ProcessLinkExchange();
                if (linkErrorFlag == -1)
                {
                    gMain.subState = HIGH_SCORE_STATE_LINK_SUCCESS;
                }
                else if (linkErrorFlag == 1)
                {
                    gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMISSION_ERROR;
                    gMain.subState = HIGH_SCORE_STATE_LINK_ERROR;
                    m4aSongNumStart(SE_FAILURE);
                }
            }

            gLinkExchangeFrameCounter++;
            if ((gLinkStatusResult & 0x7f0000) != 0 && gLinkExchangeResult == -1 && ++gLinkTimeoutCounter > 180)
            {
                gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMISSION_ERROR;
                gMain.subState = HIGH_SCORE_STATE_LINK_ERROR;
                m4aSongNumStart(SE_FAILURE);
            }
        }
    }
}

void HighScore_LinkRetryWait(void)
{
    if (++gLinkTimeoutCounter > 2)
    {
        gLinkTimeoutCounter = 0;
        gMain.subState = HIGH_SCORE_STATE_INIT_LINK_EXCHANGE;
    }
}

void HighScore_LinkError(void)
{
    int i, j;

    RenderHighScoreSprites();
    if (++gHighScoreScreenState.linkWaitTimer > 90)
    {
        gHighScoreScreenState.linkWaitTimer = 0;
        gHighScoreShowPopupFlag = FALSE;
        gHighScorePopupType = HIGH_SCORE_POPUP_DEFAULT;
        ResetSerialAndInterrupts();
        DisableSerial();
        for (i = 0; i < MAIN_FIELD_COUNT; i++)
        {
            for (j = 0; j < 6; j++)
            {
                gRemoteTopScores[i].data.raw[j] = gWorkingHighScores[i][0].data.raw[j];
            }
        }
        FadeOutScreen();
        m4aMPlayAllStop();
        DisableVBlankInterrupts();
        gMain.subState = HIGH_SCORE_STATE_INIT;
    }
}

void HighScore_LinkSuccess(void)
{
    int i, j, k;

    RenderHighScoreSprites();
    switch (gHighScoreScreenState.linkWaitTimer)
    {
    case 4:
        ResetSerialAndInterrupts();
        DisableSerial();
        break;
    case 130:
        gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMISSION_COMPLETE;
        m4aSongNumStart(SE_MENU_SELECT);
        break;
    case 250:
        gHighScoreScreenState.linkWaitTimer = 0;
        gHighScoreShowPopupFlag = FALSE;
        gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMISSION_CONNECT_PROMPT;
        gMergedRubyScoreIndex = MergeReceivedTopScore(0);
        gMergedSapphireScoreIndex = MergeReceivedTopScore(1);
        for (i = 0; i < MAIN_FIELD_COUNT; i++)
        {
            for (j = 0; j < NUM_HIGH_SCORES; j++)
            {
                for (k = 0; k < 6; k++)
                {
                    gMain_saveData.highScores[i][j].data.raw[k] = gWorkingHighScores[i][j].data.raw[k];
                }
            }
        }
        SaveFile_WriteToSram();
        FadeOutScreen();
        m4aMPlayAllStop();
        DisableVBlankInterrupts();
        gMain.subState = HIGH_SCORE_STATE_RELOAD_AFTER_LINK;
        break;
    }

    gHighScoreScreenState.linkWaitTimer++;
}

void HighScore_ResetConfirmation(void)
{
    RenderHighScoreSprites();
    if (JOY_NEW(A_BUTTON))
    {
        m4aSongNumStart(SE_MENU_SELECT);
        SetDefaultHighScores();
        SaveFile_WriteToSram();
        FadeOutScreen();
        m4aMPlayAllStop();
        DisableVBlankInterrupts();
        gMain.subState = HIGH_SCORE_STATE_INIT;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gHighScoreShowPopupFlag = FALSE;
        gHighScorePopupType = HIGH_SCORE_POPUP_DEFAULT;
        gMain.subState = HIGH_SCORE_STATE_BROWSE_SCORES;
    }
}

void HighScore_ExitToTitle(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(STATE_TITLE);
}

void IdleHighScore_LoadGraphics(void)
{
    ResetDisplayState();
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_FORCED_BLANK;
    REG_BG2CNT = 0x4006;
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = 0x420F;
    REG_DISPCNT |= DISPCNT_BG3_ON;
    gMain.dispcntBackup = REG_DISPCNT;
    DmaCopy16(3, gHighScoreBG_Pals, (void*) PLTT, 0x200);
    DmaCopy16(3, gHighScoreText_Gfx, (void*) BG_VRAM + 0x4000, 0x4800);
    DmaCopy16(3, gHighScoreBallWatermark_Gfx, (void *)BG_VRAM + 0xC000, 0x2C00);
    DmaCopy16(3, gHighScoreScoreTable_Tilemap, gBG0TilemapBuffer, 0x1000);
    DmaCopy16(3, gHighScoreBallWatermark_Tilemap, (void *)BG_SCREEN_ADDR(2), 0x1000);
    DmaCopy16(3, gHighScoreSprite_Pals, (void *)OBJ_PLTT, 0x20);
    DmaCopy16(3, gHighScoreDialogs_Gfx, (void *)OBJ_VRAM0, 0x4420);
    InitIdleHighScoreData();
    DrawAllHighScoreText();
    DmaCopy16(3, gBG0TilemapBuffer,0x6000000, 0x1000);
    m4aSongNumStart(MUS_HIGH_SCORE);
    EnableVBlankInterrupts();
    FadeInScreen();
    gMain.subState++;
}

void InitIdleHighScoreData(void)
{
    int i, j, k;

    for (i = 0; i < MAIN_FIELD_COUNT; i++)
    {
        for (j = 0; j < NUM_HIGH_SCORES; j++)
        {
            for (k = 0; k < 6; k++)
            {
                gWorkingHighScores[i][j].data.raw[k] = gMain_saveData.highScores[i][j].data.raw[k];
            }
        }
    }

    gHighScoreScreenState.displayTimer = 0;
    gHighScoreScreenState.paletteAnimTimer = 0;
    gHighScoreScreenState.paletteAnimPhase = 0;
    gHighScoreScreenState.mainField = 0;
    gScrollXOffset = 0;
    gScrollDirection = -1;
    gHighScoreScreenState.nextIdleState = STATE_INTRO;
    gHighScoreScreenState.nextSubState = 0;
    gMain.bgOffsets[3].xOffset = gScrollXOffset;
    gMain.bgOffsets[2].xOffset = gScrollXOffset;
}

void IdleHighScore_AutoScroll(void)
{
    switch (gHighScoreScreenState.nextSubState)
    {
    case IDLE_HIGH_SCORE_STATE_INIT:
        if (++gHighScoreScreenState.paletteAnimTimer > 8)
        {
            gHighScoreScreenState.paletteAnimTimer = 0;
            AnimateScoreTilemapPalette(0, 0, gHighScoreScreenState.paletteAnimPhase);
            if (++gHighScoreScreenState.paletteAnimPhase > 2)
                gHighScoreScreenState.paletteAnimPhase = 0;
        }
        if (gHighScoreScreenState.displayTimer > 600)
        {
            gHighScoreScreenState.displayTimer = 0;
            gHighScoreScreenState.paletteAnimTimer = 0;
            gHighScoreScreenState.paletteAnimPhase = 0;
            gHighScoreScreenState.nextSubState = IDLE_HIGH_SCORE_STATE_AUTOSCROLL;
        }
        break;
    case IDLE_HIGH_SCORE_STATE_AUTOSCROLL:
        gScrollXOffset += 8;
        if (gScrollXOffset >= 240)
        {
            gHighScoreScreenState.displayTimer = 0;
            gHighScoreScreenState.nextSubState = IDLE_HIGH_SCORE_STATE_EXIT;
        }
        gMain.bgOffsets[3].xOffset = gScrollXOffset;
        gMain.bgOffsets[2].xOffset = gScrollXOffset;
        break;
    case IDLE_HIGH_SCORE_STATE_EXIT:
        if (++gHighScoreScreenState.paletteAnimTimer > 8)
        {
            gHighScoreScreenState.paletteAnimTimer = 0;
            AnimateScoreTilemapPalette(1, 0, gHighScoreScreenState.paletteAnimPhase);
            if (++gHighScoreScreenState.paletteAnimPhase > 2)
                gHighScoreScreenState.paletteAnimPhase = 0;
        }
        if (gHighScoreScreenState.displayTimer > 600)
        {
            gHighScoreScreenState.displayTimer = 0;
            gHighScoreScreenState.nextIdleState = STATE_INTRO;
            gMain.subState++;
        }
        break;
    }

    gHighScoreScreenState.displayTimer++;
    DmaCopy16(3, gBG0TilemapBuffer, 0x6000000, 0x1000);

    if (JOY_NEW(START_BUTTON | A_BUTTON | B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gHighScoreScreenState.nextIdleState = STATE_TITLE;
        gMain.subState++;
    }
}

void IdleHighScore_Exit(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    SetMainGameState(gHighScoreScreenState.nextIdleState);
}

void HighScore_ReloadAfterLink(void)
{
    ResetDisplayState();
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_FORCED_BLANK;
    REG_BG2CNT = 0x4006;
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = 0x420f;
    REG_DISPCNT |= DISPCNT_BG3_ON;
    gMain.dispcntBackup = REG_DISPCNT;
    DmaCopy16(3, gHighScoreBG_Pals, (void*) PLTT, 0x200);
    DmaCopy16(3, gHighScoreText_Gfx, (void*) BG_VRAM + 0x4000, 0x4800);
    DmaCopy16(3, gHighScoreBallWatermark_Gfx, (void *)BG_VRAM + 0xC000, 0x2C00);
    DmaCopy16(3, gHighScoreScoreTable_Tilemap, gBG0TilemapBuffer, 0x1000);
    DmaCopy16(3, gHighScoreBallWatermark_Tilemap, (void *)BG_SCREEN_ADDR(2), 0x1000);
    DmaCopy16(3, gHighScoreSprite_Pals, (void *)OBJ_PLTT, 0x20);
    DmaCopy16(3, gHighScoreDialogs_Gfx, (void *)OBJ_VRAM0, 0x4420);
    InitIdleHighScoreData();
    DrawAllHighScoreText();
    DmaCopy16(3, gBG0TilemapBuffer,0x6000000, 0x1000);
    m4aSongNumStart(MUS_HIGH_SCORE);
    EnableVBlankInterrupts();
    FadeInScreen();
    gMain.subState++;
}

void HighScore_ShowMergedScores(void)
{
    switch (gHighScoreScreenState.nextSubState)
    {
    case 0:
        if (gMergedRubyScoreIndex != -1)
        {
            if (++gHighScoreScreenState.paletteAnimTimer > 8)
            {
                gHighScoreScreenState.paletteAnimTimer = 0;
                AnimateScoreTilemapPalette(0, gMergedRubyScoreIndex, gHighScoreScreenState.paletteAnimPhase);
                if (++gHighScoreScreenState.paletteAnimPhase > 2)
                    gHighScoreScreenState.paletteAnimPhase = 0;
            }
        }
        if (gHighScoreScreenState.displayTimer > 120)
        {
            gHighScoreScreenState.displayTimer = 0;
            gHighScoreScreenState.paletteAnimTimer = 0;
            gHighScoreScreenState.paletteAnimPhase = 0;
            gHighScoreScreenState.nextSubState = 1;
        }
        break;
    case 1:
        gScrollXOffset += 8;
        if (gScrollXOffset >= 240)
        {
            gHighScoreScreenState.displayTimer = 0;
            gHighScoreScreenState.nextSubState = 2;
        }
        gMain.bgOffsets[3].xOffset = gScrollXOffset;
        gMain.bgOffsets[2].xOffset = gScrollXOffset;
        break;
    case 2:
        if (gMergedSapphireScoreIndex != -1)
        {
            if (++gHighScoreScreenState.paletteAnimTimer > 8)
            {
                gHighScoreScreenState.paletteAnimTimer = 0;
                AnimateScoreTilemapPalette(1, gMergedSapphireScoreIndex, gHighScoreScreenState.paletteAnimPhase);
                if (++gHighScoreScreenState.paletteAnimPhase > 2)
                    gHighScoreScreenState.paletteAnimPhase = 0;
            }
        }
        if (gHighScoreScreenState.displayTimer > 120)
        {
            gHighScoreScreenState.displayTimer = 0;
            gMain.subState++;
        }
        break;
    }

    gHighScoreScreenState.displayTimer++;
    DmaCopy16(3, gBG0TilemapBuffer, 0x6000000, 0x1000);

    if (JOY_NEW(START_BUTTON | A_BUTTON | B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gMain.subState++;
    }
}

void HighScore_ReturnToMain(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    SetMainGameState(STATE_SCORES_MAIN);
}

void UpdateNameEntryCursor(void)
{
    int i;
    struct SpriteGroup *spriteGroup;

    //Arrow swaps between 2 variants, and then clones/positions both from the same base position
    spriteGroup = &gMain.spriteGroups[gHighScoreScreenState.nameFlashVariant];
    spriteGroup->active = TRUE;
    LoadSpriteSets(gNameEntryCursorSpriteSets, 2, gMain.spriteGroups);

    spriteGroup->baseX = gHighScoreNamePixelPositions[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].x + gHighScoreScreenState.currentNameCharIndex * 8;
    spriteGroup->baseY = gHighScoreNamePixelPositions[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].y;
    for (i = 0; i < 2; i++)
    {
        gOamBuffer[spriteGroup->oam[i].oamId].x = spriteGroup->oam[i].xOffset + spriteGroup->baseX;
        gOamBuffer[spriteGroup->oam[i].oamId].y = spriteGroup->oam[i].yOffset + spriteGroup->baseY;
    }

    spriteGroup->active = FALSE;
}

// The target keeps two redundant pointer copies alive in the entry block --
// spriteGroup1_ in r4 and spriteGroup2_ in r5 -- which agbcc otherwise deletes
// in cse1, again in loop and again in combine. Two constructs keep them:
// the r4 pin on spriteGroup1_, and the empty asm("") barriers below (they emit
// no instructions and the "r" constraint accepts any register; they only stop
// the alias pointers being coalesced with the pointers they duplicate, and stop
// the OAM pointers being re-folded into base+displacement addressing).
// spriteGroup2_ cannot also be pinned -- the target reuses r5 as a scratch
// register once the alias dies, and a pin would reserve it for the whole
// function. Three barriers is the floor; their exact placement is required for
// a byte-identical match, so do not move or remove them.
void RenderHighScoreSprites(void)
{
    int i;
    struct SpriteGroup *spriteGroup1;
    register struct SpriteGroup *spriteGroup1_ asm("r4");
    struct SpriteGroup *spriteGroup2;
    struct SpriteGroup *spriteGroup2_;
    struct SpriteGroup *spriteGroup3;
    struct SpriteGroup *spriteGroup4;
    struct OamDataSimple *oamData;
    const struct SpriteSet *spriteSet;
    const struct SpriteSet * const *spriteSets = gHighScoreScreenSpriteSets;
    spriteGroup1 = &gMain.spriteGroups[SG_HIGH_SCORE_PAGE_RIGHT_ARROW];
    spriteGroup1_ = spriteGroup1;
    spriteGroup2 = &gMain.spriteGroups[SG_HIGH_SCORE_PAGE_LEFT_ARROW];
    spriteGroup2_ = spriteGroup2;
    asm("" : "=r"(spriteGroup2_) : "0"(spriteGroup2_));
    spriteGroup3 = &gMain.spriteGroups[(s8)gHighScorePopupType + SG_HIGH_SCORE_POPUP_LIST_BASE];
    spriteGroup4 = &gMain.spriteGroups[gHighScoreScreenState.pressStartBlinkToggle + SG_HIGH_SCORE_PRESS_START_0];

    if (gScrollXOffset == 0)
    {
        spriteGroup1->active = TRUE;
        spriteGroup2_->active = FALSE;
        spriteGroup3->active = gHighScoreShowPopupFlag;
        spriteGroup4->active = gHighScoreScreenState.displayModeVisible;
        asm("" : : "r"(spriteGroup1_), "r"(spriteGroup2_));

        LoadSpriteSets(spriteSets, 9, spriteGroup1);
        {
            spriteGroup1->baseX = 220;
            spriteGroup1->baseY = 144;
            oamData = &spriteGroup1_->oam[0];
            gOamBuffer[oamData->oamId].tileNum = gHighScoreScreenState.flashElapsedFrames * 2 + 2;
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup1->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup1->baseY;

        }

        if (spriteGroup4->active == TRUE)
        {
            spriteGroup4->baseX = 84;
            spriteGroup4->baseY = 150;
            spriteSet = gHighScoreScreenSpriteSets[gHighScoreScreenState.pressStartBlinkToggle + SG_HIGH_SCORE_PRESS_START_0];
            for (i = 0; i < spriteSet->count; i++)
            {
                oamData = &spriteGroup4->oam[i];
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup4->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup4->baseY;
            }
        }
        if (spriteGroup3->active == TRUE)
        {
            switch ((s8)gHighScorePopupType)
            {
            case HIGH_SCORE_POPUP_TRANSMISSION_CONNECT_PROMPT:
            case HIGH_SCORE_POPUP_DELETE_CONFIRMATION_PROMPT:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 100;
                break;
            default:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 80;
                break;
            }
            spriteSet = gHighScoreScreenSpriteSets[(s8)gHighScorePopupType + SG_HIGH_SCORE_POPUP_LIST_BASE];
            for (i = 0; i < spriteSet->count; i++)
            {
                oamData = &spriteGroup3->oam[i];
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup3->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup3->baseY;
            }
        }
    }
    else if (gScrollXOffset == 240)
    {
        spriteGroup1->active = FALSE;
        spriteGroup2->active = TRUE;
        spriteGroup3->active = gHighScoreShowPopupFlag;
        spriteGroup4->active = gHighScoreScreenState.displayModeVisible;
        LoadSpriteSets(spriteSets, 9, spriteGroup1);
        {
            spriteGroup2->baseX = 4;
            spriteGroup2->baseY = 144;
            oamData = &spriteGroup2_->oam[0];
            asm("" : "=r"(spriteGroup2_) : "0"(spriteGroup2_));

            gOamBuffer[oamData->oamId].tileNum = gHighScoreScreenState.flashElapsedFrames * 2 + 2;
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup2->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup2->baseY;

        }

        if (spriteGroup4->active == TRUE)
        {
            spriteGroup4->baseX = 84;
            spriteGroup4->baseY = 150;
            spriteSet = gHighScoreScreenSpriteSets[gHighScoreScreenState.pressStartBlinkToggle + SG_HIGH_SCORE_PRESS_START_0];
            for (i = 0; i < spriteSet->count; i++)
            {
                oamData = &spriteGroup4->oam[i];
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup4->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup4->baseY;
            }
        }
        if (spriteGroup3->active == TRUE)
        {
            switch ((s8)gHighScorePopupType)
            {
            case HIGH_SCORE_POPUP_TRANSMISSION_CONNECT_PROMPT:
            case HIGH_SCORE_POPUP_DELETE_CONFIRMATION_PROMPT:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 100;
                break;
            default:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 80;
                break;
            }
            spriteSet = gHighScoreScreenSpriteSets[(s8)gHighScorePopupType + SG_HIGH_SCORE_POPUP_LIST_BASE];
            for (i = 0; i < spriteSet->count; i++)
            {
                oamData = &spriteGroup3->oam[i];
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup3->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup3->baseY;
            }
        }
    }
    else
    {
        spriteGroup1->active = FALSE;
        spriteGroup2->active = FALSE;
        LoadSpriteSets(spriteSets, 9, spriteGroup1);
    }

    spriteGroup3->active = FALSE;
    spriteGroup4->active = FALSE;
}


void RenderCompletionBanner(void)
{
    int i;
    struct SpriteGroup *spriteGroup;

    spriteGroup = &gMain.spriteGroups[gCompletionBannerSpriteGroup];
    spriteGroup->active = gCompletionBannerVisible;
    LoadSpriteSets(gCompletionBannerSpriteSets, 5, gMain.spriteGroups);
    if (spriteGroup->active == TRUE)
    {
        spriteGroup->baseX = 120;
        spriteGroup->baseY = gCompletionBannerY;
        for (i = 0; i < 4; i++)
        {
            gOamBuffer[spriteGroup->oam[i].oamId].x = spriteGroup->oam[i].xOffset + spriteGroup->baseX;
            gOamBuffer[spriteGroup->oam[i].oamId].y = spriteGroup->oam[i].yOffset + spriteGroup->baseY;
        }
    }

    spriteGroup->active = FALSE;
}

void InitLinkExchangeBuffers(void)
{
    gLinkSendBuffer[0] = 0xCFCF;
    gLinkExchangeCommand = 1;
    gLinkPacketCounter = 1;
    gLinkExchangeResult = 0;
    gLinkExchangeSendPhase = 0;
    gLinkExchangeRecvPhase = 0;
    gLinkExchangeTimeout = 0;
}

s16 HighScore_ProcessLinkExchange(void)
{
    s16 result;
    if (gLink.isMaster)
        result = MasterReceiveHighScores();
    else
        result = SlaveReceiveHighScores();

    return result;
}

s16 ProcessLinkSendData(void)
{
    s16 result;
    if (gLink.isMaster)
        result = MasterSendHighScores();
    else
        result = SlaveSendHighScores();

    return result;
}

s16 MasterSendHighScores(void)
{
    int i;
    struct HighScoreEntry *topScore;

    if (gLinkExchangeResult == 0)
    {
        switch (gLinkExchangeSendPhase)
        {
        case 0:
            if (JOY_NEW(A_BUTTON))
            {
                gLinkSendBuffer[0] = 0xDEDE;
            }
            else
            {
                for (i = 0; i < 8; i++)
                    gLinkSendBuffer[i] = 0;
            }
            break;
        case 1:
            gLinkSendBuffer[0] = 0xEDED;
            break;
        }
    }
    else
    {
        if (gLinkPacketCounter < 8)
        {
            for (i = 0; i < 8; i++)
                gLinkSendBuffer[i] = 0xCFCF;
        }
        else if (gLinkPacketCounter < 10)
        {
            u16 field = gLinkPacketCounter - 8;
            gLinkSendBuffer[0] = gLinkPacketCounter;
            gLinkSendBuffer[1] = (gWorkingHighScores[field][0].data.parts.name[0] << 8) |
                                    gWorkingHighScores[field][0].data.parts.name[1];
            gLinkSendBuffer[2] = (gWorkingHighScores[field][0].data.parts.name[2] << 8) |
                                    gWorkingHighScores[field][0].data.parts.name[3];
            gLinkSendBuffer[3] = gWorkingHighScores[field][0].data.parts.scoreHi >> 16;
            gLinkSendBuffer[4] = gWorkingHighScores[field][0].data.parts.scoreHi;
            gLinkSendBuffer[5] = gWorkingHighScores[field][0].data.parts.scoreLo >> 16;
            gLinkSendBuffer[6] = gWorkingHighScores[field][0].data.parts.scoreLo;
            gLinkSendBuffer[7] = 0;
        }
        else
        {
            for (i = 0; i < 8; i++)
                gLinkSendBuffer[i] = 0;
        }

        gLinkPacketCounter++;
    }

    return 0;
}

s16 SlaveSendHighScores(void)
{
    int i;
    struct HighScoreEntry *topScore;

    if (gLinkExchangeResult == 0)
    {
        switch (gLinkExchangeRecvPhase)
        {
        case 0:
            if (JOY_NEW(A_BUTTON))
            {
                gLinkSendBuffer[0] = 0xDEDE;
            }
            else
            {
                for (i = 0; i < 8; i++)
                    gLinkSendBuffer[i] = 0;
            }
            break;
        case 1:
            gLinkSendBuffer[0] = 0xEDED;
            break;
        }
    }
    else
    {
        if (gLinkPacketCounter < 8)
        {
            for (i = 0; i < 8; i++)
                gLinkSendBuffer[i] = 0xCFCF;
        }
        else if (gLinkPacketCounter < 10)
        {
            u16 field = gLinkPacketCounter - 8;
            gLinkSendBuffer[0] = gLinkPacketCounter;
            gLinkSendBuffer[1] = (gWorkingHighScores[field][0].data.parts.name[0] << 8) |
                                    gWorkingHighScores[field][0].data.parts.name[1];
            gLinkSendBuffer[2] = (gWorkingHighScores[field][0].data.parts.name[2] << 8) |
                                    gWorkingHighScores[field][0].data.parts.name[3];
            gLinkSendBuffer[3] = gWorkingHighScores[field][0].data.parts.scoreHi >> 16;
            gLinkSendBuffer[4] = gWorkingHighScores[field][0].data.parts.scoreHi;
            gLinkSendBuffer[5] = gWorkingHighScores[field][0].data.parts.scoreLo >> 16;
            gLinkSendBuffer[6] = gWorkingHighScores[field][0].data.parts.scoreLo;
            gLinkSendBuffer[7] = 0;
        }
        else
        {
            for (i = 0; i < 8; i++)
                gLinkSendBuffer[i] = 0;
        }

        gLinkPacketCounter++;
    }

    return 0;
}

s16 MasterReceiveHighScores(void)
{
    int i, j;
    struct HighScoreEntry *topScore;
    u16 field;

    if (gLinkExchangeResult == 0)
    {
        switch (gLinkExchangeSendPhase)
        {
        case 0:
            if (gLinkRecvBuffer[0][0] == 0xDEDE || gLinkRecvBuffer[0][1] == 0xDEDE)
                gLinkExchangeSendPhase = 1;
            break;
        case 1:
            if (gLinkRecvBuffer[0][0] == 0xEDED && gLinkRecvBuffer[0][1] == 0xEDED)
            {
                gLinkExchangeResult = -1;
                gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMITTING_ACTIVE;
                gLinkPacketCounter = 1;
            }
            else
            {
                if (++gLinkExchangeTimeout > 10)
                    return 1;
            }
            break;
        }
    }
    else
    {
        field = gLinkRecvBuffer[0][1] - 8;
        if (field > 1)
            return 0;

        gLinkExchangeCommand = gLinkRecvBuffer[0][1];
        gRemoteTopScores[field].data.parts.name[0] = (gLinkRecvBuffer[1][1] >> 8) & 0xFF;
        gRemoteTopScores[field].data.parts.name[1] = gLinkRecvBuffer[1][1] & 0xFF;
        gRemoteTopScores[field].data.parts.name[2] = (gLinkRecvBuffer[2][1] >> 8) & 0xFF;
        gRemoteTopScores[field].data.parts.name[3] = gLinkRecvBuffer[2][1] & 0xFF;
        gRemoteTopScores[field].data.parts.scoreHi = (gLinkRecvBuffer[3][1] << 16) |
                                                        gLinkRecvBuffer[4][1];
        gRemoteTopScores[field].data.parts.scoreLo = (gLinkRecvBuffer[5][1] << 16) |
                                                                gLinkRecvBuffer[6][1];
        if (gLinkExchangeCommand == 9)
            return -1;
    }

    for (i = 0; i < 8; i++)
        for (j = 0; j < 2; j++)
            gLinkRecvBuffer[i][j] = 0;

    return 0;
}

s16 SlaveReceiveHighScores(void)
{
    int i, j;
    struct HighScoreEntry *topScore;
    u16 field;

    if (gLinkExchangeResult == 0)
    {
        switch (gLinkExchangeRecvPhase)
        {
        case 0:
            if (gLinkRecvBuffer[0][0] == 0xDEDE || gLinkRecvBuffer[0][1] == 0xDEDE)
                gLinkExchangeRecvPhase = 1;
            break;
        case 1:
            if (gLinkRecvBuffer[0][0] == 0xEDED && gLinkRecvBuffer[0][1] == 0xEDED)
            {
                gLinkExchangeResult = -1;
                gHighScorePopupType = HIGH_SCORE_POPUP_TRANSMITTING_ACTIVE;
                gLinkPacketCounter = 1;
            }
            else
            {
                if (++gLinkExchangeTimeout > 10)
                    return 1;
            }
            break;
        }
    }
    else
    {
        field = gLinkRecvBuffer[0][0] - 8;
        if (field > 1)
            return 0;

        gLinkExchangeCommand = gLinkRecvBuffer[0][0];
        gRemoteTopScores[field].data.parts.name[0] = (gLinkRecvBuffer[1][0] >> 8) & 0xFF;
        gRemoteTopScores[field].data.parts.name[1] = gLinkRecvBuffer[1][0] & 0xFF;
        gRemoteTopScores[field].data.parts.name[2] = (gLinkRecvBuffer[2][0] >> 8) & 0xFF;
        gRemoteTopScores[field].data.parts.name[3] = gLinkRecvBuffer[2][0] & 0xFF;
        gRemoteTopScores[field].data.parts.scoreHi = (gLinkRecvBuffer[3][0] << 16) |
                                                        gLinkRecvBuffer[4][0];
        gRemoteTopScores[field].data.parts.scoreLo = (gLinkRecvBuffer[5][0] << 16) |
                                                                gLinkRecvBuffer[6][0];
        if (gLinkExchangeCommand == 9)
            return -1;
    }

    for (i = 0; i < 8; i++)
        for (j = 0; j < 2; j++)
            gLinkRecvBuffer[i][j] = 0;

    return 0;
}

void DrawAllHighScoreText(void)
{
    int i, j;

    // Ruby Field Top name
    for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
    {
        PrintString(gHighScoreCharToTileMap[gWorkingHighScores[FIELD_RUBY][0].data.parts.name[j]] + 0x80, 8, j + 6, 3, 1, 1);
    }

    // Ruby Field 2nd-8th names
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
        {
            PrintString(gHighScoreCharToTileMap[gWorkingHighScores[FIELD_RUBY][i].data.parts.name[j]] + 0xA0, 8, j + 6, i * 2 + 3, 1, 2);
        }
    }

    // Ruby Field Top score
    FormatScoreDigits(gWorkingHighScores[FIELD_RUBY][0].data.parts.scoreHi, gWorkingHighScores[FIELD_RUBY][0].data.parts.scoreLo);
    for (j = 0; j < 14; j++)
    {
        if ((j + 1) % 3 == 0)
            PrintString(gScoreDigitBuffer[j] + 0x120, 9, j + 12, 2, 1, 2); // Thousands separator?
        else
            PrintString(gScoreDigitBuffer[j] + 0xE0, 9, j + 12, 2, 1, 2);
    }
    PrintString(gScoreDigitBuffer[14] + 0xE0, 9, 26, 2, 1, 2);
    // Ruby Field 2nd-8th scores
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        FormatScoreDigits(gWorkingHighScores[FIELD_RUBY][i].data.parts.scoreHi, gWorkingHighScores[FIELD_RUBY][i].data.parts.scoreLo);
        for (j = 0; j < 14; j++)
        {
            if ((j + 1) % 3 == 0)
                PrintString(gScoreDigitBuffer[j] + 0x1A0, 9, j + 12, i * 2 + 3, 1, 2); // Thousands separator?
            else
                PrintString(gScoreDigitBuffer[j] + 0x160, 9, j + 12, i * 2 + 3, 1, 2);
        }

        PrintString(gScoreDigitBuffer[14] + 0x160, 9, 26, 3 + i * 2, 1, 2);
    }

    // Sapphire Field Top name
    for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
    {
        PrintString(gHighScoreCharToTileMap[gWorkingHighScores[FIELD_SAPPHIRE][0].data.parts.name[j]] + 0x80, 8, j + 4, 35, 1, 1);
    }

    // Sapphire Field 2nd-8th names
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        for (j = 0; j < HIGH_SCORE_NAME_LENGTH; j++)
        {
            PrintString(gHighScoreCharToTileMap[gWorkingHighScores[FIELD_SAPPHIRE][i].data.parts.name[j]] + 0xA0, 8, j + 4, i * 2 + 35, 1, 2);
        }
    }
    FormatScoreDigits(gWorkingHighScores[FIELD_SAPPHIRE][0].data.parts.scoreHi, gWorkingHighScores[FIELD_SAPPHIRE][0].data.parts.scoreLo);
    // Sapphire Field Top score
    for (j = 0; j < 14; j++)
    {
        if ((j + 1) % 3 == 0)
            PrintString(gScoreDigitBuffer[j] + 0x120, 9, j + 10, 34, 1, 2); // Thousands separator?
        else
            PrintString(gScoreDigitBuffer[j] + 0xE0, 9, j + 10, 34, 1, 2);
    }

    PrintString(gScoreDigitBuffer[j] + 0xE0, 9, 24, 34, 1, 2);
    // Sapphire Field 2nd-8th scores
    for (i = 1; i < NUM_HIGH_SCORES; i++)
    {
        FormatScoreDigits(gWorkingHighScores[FIELD_SAPPHIRE][i].data.parts.scoreHi, gWorkingHighScores[FIELD_SAPPHIRE][i].data.parts.scoreLo);
        for (j = 0; j < 14; j++)
        {
            if ((j + 1) % 3 == 0)
                PrintString(gScoreDigitBuffer[j] + 0x1A0, 9, j + 10, i * 2 + 35, 1, 2); // Thousands separator?s
            else
                PrintString(gScoreDigitBuffer[j] + 0x160, 9, j + 10, i * 2 + 35, 1, 2);
        }

        PrintString(gScoreDigitBuffer[j] + 0x160, 9, 24, i * 2 + 35, 1, 2);
    }
}

void FormatScoreDigits(u32 scoreHi, u32 scoreLo)
{
    int i;
    u32 var0;
    u32 var1;
    u16 *arr;

    if (scoreHi == 0 && scoreLo == 0)
    {
        for (i = 0; i < 14; i++)
            gScoreDigitBuffer[i] = 10;

        gScoreDigitBuffer[14] = 0;
    }
    else
    {
        if (scoreHi > SCORE_HIGH_MAX_DISPLAY)
        {
            scoreHi = SCORE_HIGH_MAX_DISPLAY;
            scoreLo = SCORE_LO_MAX;
        }
        else if (scoreLo > SCORE_LO_MAX)
        {
            scoreLo = SCORE_LO_MAX;
        }

        arr = gScoreDigitBuffer;

        var0 = LEAD_DIGIT_1M(scoreHi);
        arr[0] = var0;
        arr[1] = DIGIT_100K_SCALEDOWN(scoreHi);
        arr[2] = DIGIT_10K_SCALEDOWN(scoreHi);
        arr[3] = DIGIT_1K_SCALEDOWN(scoreHi);
        arr[4] = DIGIT_100S_SCALEDOWN(scoreHi);
        arr[5] = DIGIT_10S_SCALEDOWN(scoreHi);
        arr[6] = DIGIT_1S(scoreHi);

        var1 = scoreLo;
        arr[7] = LEAD_DIGIT_10M(var1);
        arr[8] = DIGIT_1M_SCALEDOWN(var1);
        arr[9] = DIGIT_100K_SCALEDOWN(var1);
        arr[10] = DIGIT_10K_SCALEDOWN(var1);
        arr[11] = DIGIT_1K_SCALEDOWN(var1);
        arr[12] = DIGIT_100S_SCALEDOWN(var1);
        arr[13] = DIGIT_10S_SCALEDOWN(var1);
        arr[14] = DIGIT_1S(var1);

        if ((s16)var0 == 0)
        {
            for (i = 0; i < 15 && gScoreDigitBuffer[i] == 0; i++)
                gScoreDigitBuffer[i] = 10;
        }
    }
}

int CompareScores(u32 scoreHiA, u32 scoreLoA, u32 scoreHiB, u32 scoreLoB)
{
    if (scoreHiA > scoreHiB)
        return 1;
    if (scoreHiA < scoreHiB)
        return -1;
    if (scoreLoA > scoreLoB)
        return 1;
    if (scoreLoA < scoreLoB)
        return -1;

    return 0;
}

int GetNewHighScoreIndex(u32 scoreHi, u32 scoreLo, u32 field)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        int comparisonResult = CompareScores(
            scoreHi,
            scoreLo,
            gWorkingHighScores[field][i].data.parts.scoreHi,
            gWorkingHighScores[field][i].data.parts.scoreLo
        );
        if (comparisonResult >= 0)
            return i;
    }

    return -1;
}

void InsertNewHighScore(u32 scoreHi, u32 scoreLo, u32 field, int newHighScoreIndex)
{
    int i;

    for (i = 7; i > newHighScoreIndex; i--)
    {
        gWorkingHighScores[field][i].data.parts.name[0] = gWorkingHighScores[field][i-1].data.parts.name[0];
        gWorkingHighScores[field][i].data.parts.name[1] = gWorkingHighScores[field][i-1].data.parts.name[1];
        gWorkingHighScores[field][i].data.parts.name[2] = gWorkingHighScores[field][i-1].data.parts.name[2];
        gWorkingHighScores[field][i].data.parts.name[3] = gWorkingHighScores[field][i-1].data.parts.name[3];
        gWorkingHighScores[field][i].data.parts.scoreHi = gWorkingHighScores[field][i-1].data.parts.scoreHi;
        gWorkingHighScores[field][i].data.parts.scoreLo = gWorkingHighScores[field][i-1].data.parts.scoreLo;
    }

    gWorkingHighScores[field][i].data.parts.name[0] = 0;
    gWorkingHighScores[field][i].data.parts.name[1] = 0;
    gWorkingHighScores[field][i].data.parts.name[2] = 0;
    gWorkingHighScores[field][i].data.parts.name[3] = 0;
    gWorkingHighScores[field][i].data.parts.scoreHi = scoreHi;
    gWorkingHighScores[field][i].data.parts.scoreLo = scoreLo;
}

u32 MergeReceivedTopScore(u32 field)
{
    int i, j;
    int newHighScoreIndex;
    int comparisonResult;

    newHighScoreIndex = GetNewHighScoreIndex(gRemoteTopScores[field].data.parts.scoreHi, gRemoteTopScores[field].data.parts.scoreLo, field);
    comparisonResult = CompareScores(
        gWorkingHighScores[field][newHighScoreIndex].data.parts.scoreHi,
        gWorkingHighScores[field][newHighScoreIndex].data.parts.scoreLo,
        gRemoteTopScores[field].data.parts.scoreHi,
        gRemoteTopScores[field].data.parts.scoreLo
    );
    if (comparisonResult == 0 &&
        gWorkingHighScores[field][newHighScoreIndex].data.parts.name[0] == gRemoteTopScores[field].data.parts.name[0] &&
        gWorkingHighScores[field][newHighScoreIndex].data.parts.name[1] == gRemoteTopScores[field].data.parts.name[1] &&
        gWorkingHighScores[field][newHighScoreIndex].data.parts.name[2] == gRemoteTopScores[field].data.parts.name[2] &&
        gWorkingHighScores[field][newHighScoreIndex].data.parts.name[3] == gRemoteTopScores[field].data.parts.name[3])
    {
        return newHighScoreIndex;
    }

    if (newHighScoreIndex == -1)
    {
        return -1;
    }

    for (i = 7; i > newHighScoreIndex; i--)
    {
        for (j = 0; j < 6; j++)
        {
            gWorkingHighScores[field][i].data.raw[j] = gWorkingHighScores[field][i-1].data.raw[j];
        }
    }

    gWorkingHighScores[field][i].data.parts.name[0] = gRemoteTopScores[field].data.parts.name[0];
    gWorkingHighScores[field][i].data.parts.name[1] = gRemoteTopScores[field].data.parts.name[1];
    gWorkingHighScores[field][i].data.parts.name[2] = gRemoteTopScores[field].data.parts.name[2];
    gWorkingHighScores[field][i].data.parts.name[3] = gRemoteTopScores[field].data.parts.name[3];
    gWorkingHighScores[field][i].data.parts.scoreHi = gRemoteTopScores[field].data.parts.scoreHi;
    gWorkingHighScores[field][i].data.parts.scoreLo = gRemoteTopScores[field].data.parts.scoreLo;
    return newHighScoreIndex;
}

void PrintHighScoreNameChar(u32 currNameChar, u32 hsIndex, s16 currNameCharIndex, u32 mainField)
{
    currNameChar = gHighScoreCharToTileMap[currNameChar];
    PrintString(
        gHighScoreNamePositions[mainField][hsIndex].fieldWidth * 32 + 0x80 + currNameChar,
        8,
        gHighScoreNamePositions[mainField][hsIndex].yBaseOffset + currNameCharIndex,
        gHighScoreNamePositions[mainField][hsIndex].yPixelPosition,
        1,
        gHighScoreNamePositions[mainField][hsIndex].fieldWidth + 1
    );
}

void SetDefaultHighScores(void)
{
    int field, highScoreIndex, i;

    gCompletionBannerDone = FALSE;
    for (field = 0; field < 2; field++)
        for (highScoreIndex = 0; highScoreIndex < 8; highScoreIndex++)
            for (i = 0; i < 6; i++)
                gMain_saveData.highScores[field][highScoreIndex].data.raw[i] = gDefaultHighScores[field][highScoreIndex].data.raw[i];
}

void GenerateRandomHighScores(void)
{
    int field, highScoreIndex, k;
    u8 letter;
    u32 scoreHi, scoreLo;

    for (field = 0; field < MAIN_FIELD_COUNT; field++)
    {
        letter = Random() % 42;
        gMain_saveData.highScores[field][0].data.parts.name[0] = letter;
        for (k = 1; k < 4; k++)
        {
            if ((u8)(Random() % 10) < 8)
                letter = Random() % 42;

            gMain_saveData.highScores[field][0].data.parts.name[k] = letter;
        }

        scoreHi = Random();
        scoreLo = Random();
        gMain_saveData.highScores[field][0].data.parts.scoreHi = scoreHi;
        gMain_saveData.highScores[field][0].data.parts.scoreLo = scoreLo;
        for (highScoreIndex = 1; highScoreIndex < 8; highScoreIndex++)
        {
            letter = Random() % 42;
            gMain_saveData.highScores[field][highScoreIndex].data.parts.name[0] = letter;
            for (k = 1; k < 4; k++)
            {
                if ((u8)(Random() % 10) < 8)
                    letter = Random() % 42;

                gMain_saveData.highScores[field][highScoreIndex].data.parts.name[k] = letter;
            }

            scoreHi = Random() % scoreHi;
            if (scoreHi != 0)
                scoreLo = Random();
            else
                scoreLo = Random() % scoreLo;

            gMain_saveData.highScores[field][highScoreIndex].data.parts.scoreHi = scoreHi;
            gMain_saveData.highScores[field][highScoreIndex].data.parts.scoreLo = scoreLo;
        }
    }
}

void AnimateScoreTilemapPalette(u32 arg0, u32 arg1, s16 arg2)
{
    int i;
    u32 r3;
    if(arg0 == 0)
    {
        if(arg1 == 0)
        {
            r3 = (0 * 2 + 2) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x90EA && gBG0TilemapBuffer[r3 + i] != 0x912A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x910A && gBG0TilemapBuffer[r3 + i] != 0x914A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x916A && gBG0TilemapBuffer[r3 + i] != 0x91AA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x918A && gBG0TilemapBuffer[r3 + i] != 0x91CA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
        }
    }
    else
    {
        if(arg1 == 0)
        {
            r3 = (0 * 2 + 2) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x90EA && gBG0TilemapBuffer[r3 + i] != 0x912A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x910A && gBG0TilemapBuffer[r3 + i] != 0x914A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x916A && gBG0TilemapBuffer[r3 + i] != 0x91AA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x918A && gBG0TilemapBuffer[r3 + i] != 0x91CA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteAnimOffsets[arg2];
                }
            }
        }
    }
}

void ResetScoreTilemapPalette(u32 arg0, u32 arg1, s16 arg2)
{
    int i;
    u32 r3;
    if(arg0 == 0)
    {
        if(arg1 == 0)
        {
            r3 = (0 * 2 + 2) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x90EA && gBG0TilemapBuffer[r3 + i] != 0x912A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x910A && gBG0TilemapBuffer[r3 + i] != 0x914A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x916A && gBG0TilemapBuffer[r3 + i] != 0x91AA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 12;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x918A && gBG0TilemapBuffer[r3 + i] != 0x91CA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
        }
    }
    else
    {
        if(arg1 == 0)
        {
            r3 = (0 * 2 + 2) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x90EA && gBG0TilemapBuffer[r3 + i] != 0x912A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
            r3 = (0 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x910A && gBG0TilemapBuffer[r3 + i] != 0x914A)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
        }
        else
        {
            r3 = (arg1 * 2 + 3) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x916A && gBG0TilemapBuffer[r3 + i] != 0x91AA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
            r3 = (arg1 * 2 + 4) * 32 + 32 * 32 + 10;
            for(i = 0; i < 15; i++)
            {
                if(gBG0TilemapBuffer[r3 + i] != 0x918A && gBG0TilemapBuffer[r3 + i] != 0x91CA)
                {
                    gBG0TilemapBuffer[r3 + i] += gScorePaletteResetOffsets[arg2];
                }
            }
        }
    }
}

s8 CheckAllPokemonCaught(void)
{
    int i;
    s16 sp0[NUM_SPECIES];

    for(i = 0; i < NUM_SPECIES; i++)
        sp0[i] = gMain_saveData.pokedexFlags[i];

    for(i = 0; i < BONUS_SPECIES_START; i++) // TODO: add a proper count for non bonus
    {
        if(sp0[i] != 4)
            return 0;
    }
    return 1;
}

