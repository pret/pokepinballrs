#include "global.h"
#include "functions.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"
#include "constants/bg_music.h"
#include "constants/fields.h"

extern StateFunc gHighScoresStateFuncs[15];
extern StateFunc gIdleHighScoresStateFuncs[15];
extern u8 gHighScoreBG_Pals[];
extern u8 gHighScoreBallWatermark_Tilemap[];
extern u8 gHighScoreText_Gfx[];
extern s16 gHighScoreEntrySource;
extern s8 gCompletionBannerDone;
extern s8 gCompletionBannerVisible;
extern s16 gCompletionBannerY;
extern s8 gCompletionBannerPhase;
extern s8 gCompletionBannerFrame;
extern s8 gShowDialogFlag;
extern u8 gDialogType;
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
    s16 nameFlashToggle;
    s16 flashFrameCounter;
    s16 currentNameChar;
    s16 flashDuration;
    s16 flashElapsedFrames;
    s16 paletteAnimPhase;
    s16 paletteAnimTimer;
    s16 inputRepeatDelay;
    s16 linkWaitTimer;
    s8 nextIdleState;
    u8 arrowBlinkToggle;
    s8 displayModeVisible;
};

enum HighScoreStates{
    HIGH_SCORE_STATE_0 = 0,
    HIGH_SCORE_STATE_1 = 1,
    HIGH_SCORE_STATE_2 = 2,
    HIGH_SCORE_STATE_3 = 3,
    HIGH_SCORE_STATE_4 = 4,
    HIGH_SCORE_STATE_5 = 5,
    HIGH_SCORE_STATE_6 = 6,
    HIGH_SCORE_STATE_7 = 7,
    HIGH_SCORE_STATE_8 = 8,
    HIGH_SCORE_STATE_9 = 9,
    HIGH_SCORE_STATE_10 = 10,
    HIGH_SCORE_STATE_11 = 11,
    HIGH_SCORE_STATE_12 = 12,
    HIGH_SCORE_STATE_13 = 13,
    HIGH_SCORE_STATE_14 = 14
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
    gHighScoreScreenState.nameFlashToggle = 0;
    gHighScoreScreenState.flashFrameCounter = 0;
    gHighScoreScreenState.flashDuration = 0;
    gHighScoreScreenState.flashElapsedFrames = 0;
    gHighScoreScreenState.paletteAnimTimer = 0;
    gHighScoreScreenState.paletteAnimPhase = 0;
    gHighScoreScreenState.inputRepeatDelay = 0;
    gHighScoreScreenState.linkWaitTimer = 0;
    gHighScoreScreenState.arrowBlinkToggle = 0;
    gHighScoreScreenState.displayModeVisible = 1;
    gShowDialogFlag = 0;
    gDialogType = 1;
    gCompletionBannerVisible = 0;
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
        if(CheckAllPokemonCaught() == 1)
        {
            if(gCompletionBannerDone == 0)
            {
                gCompletionBannerVisible = 1;
                gCompletionBannerY = 0xB8;
                gCompletionBannerFrame = 0;
                gCompletionBannerPhase = 0;
                gHighScoreScreenState.nextSubState = 1;
            }
            else
            {
                gCompletionBannerVisible = 0;
                gHighScoreScreenState.nextSubState = 2;
            }
        }
        else
        {
            gCompletionBannerDone = 0;
            gHighScoreScreenState.nextSubState = 2;
        }
    }
    else
    {
        gHighScoreScreenState.mainField = 0;
        gScrollXOffset = 0;
        gScrollDirection = -1;
        RenderHighScoreSprites();
        gHighScoreScreenState.nextSubState = 3;
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
                gCompletionBannerFrame++;
                if(gCompletionBannerFrame > 4)
                {
                    gCompletionBannerFrame = 0;
                }
            }
            if(gCompletionBannerY == 0x50)
            {
                gCompletionBannerFrame = 0;
                gCompletionBannerPhase++;
            }
            break;
        case 2:
            if(JOY_NEW(A_BUTTON | B_BUTTON))
            {
                gCompletionBannerFrame = 0;
                gCompletionBannerPhase++;
            }
            break;
        case 3:
            gCompletionBannerY -= 4;
            if(gCompletionBannerY < -0x18)
            {
                gHighScoreScreenState.flashDuration = 0;
                gCompletionBannerDone = 1;
                gCompletionBannerVisible = 0;
                gMain.subState = HIGH_SCORE_STATE_2;
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
            m4aSongNumStart(SE_HIGH_SCORE_EARNED);
            gHighScoreScreenState.flashDuration = 0xA0;
        }
        else if(gHighScoreScreenState.highScoreIndex == -1)
        {
            gHighScoreScreenState.flashDuration = 999;
            gHighScoreScreenState.flashElapsedFrames = 0;
            m4aSongNumStart(MUS_HIGH_SCORE);
            gMain.subState = HIGH_SCORE_STATE_3;
        }
        else
        {
            m4aSongNumStart(SE_UNKNOWN_0x14B);
            gHighScoreScreenState.flashDuration = 0x5A;
        }
    }
    gHighScoreScreenState.flashFrameCounter++;
    if(gHighScoreScreenState.flashFrameCounter > 8)
    {
        gHighScoreScreenState.flashFrameCounter = 0;
        if(!gHighScoreScreenState.nameFlashToggle)
        {
            gHighScoreScreenState.nameFlashToggle = 1;
            CopyString(6 - (gHighScoreScreenState.mainField << 1), gHighScoreNameRowTilemapOffsets[gHighScoreScreenState.highScoreIndex] + (gHighScoreScreenState.mainField << 5), 0, 0x15, 4, 2);
            CopyString(0, 0x17, 6 - (gHighScoreScreenState.mainField << 1), gHighScoreNameRowTilemapOffsets[gHighScoreScreenState.highScoreIndex] + (gHighScoreScreenState.mainField << 5), 4, 2);
        }
        else
        {
            gHighScoreScreenState.nameFlashToggle = 0;
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
        if(gHighScoreScreenState.nameFlashToggle == 1)
        {
            gHighScoreScreenState.nameFlashToggle = 0;
            gHighScoreScreenState.flashFrameCounter = 0;
            CopyString(0, 0x15, 6 - (gHighScoreScreenState.mainField << 1), gHighScoreNameRowTilemapOffsets[gHighScoreScreenState.highScoreIndex] +(gHighScoreScreenState.mainField << 5), 4, 2);
        }
        m4aSongNumStart(MUS_HIGH_SCORE);
        gMain.subState = HIGH_SCORE_STATE_4;
    }

    DmaCopy16(3, gBG0TilemapBuffer, 0x6000000, 0x1000);
}

void HighScore_BrowseScores(void)
{
    RenderHighScoreSprites();
    if(!(gMain.systemFrameCount % 0xC))
    {
        gHighScoreScreenState.flashElapsedFrames = 1 - gHighScoreScreenState.flashElapsedFrames;
        gHighScoreScreenState.arrowBlinkToggle = 1 - gHighScoreScreenState.arrowBlinkToggle;
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
        gMain.subState = HIGH_SCORE_STATE_11;
    }
    if(JOY_NEW(START_BUTTON))
    {
        if(gScrollXOffset == 0 || (gScrollXOffset == 0xF0))
        {
            m4aSongNumStart(SE_MENU_POPUP_OPEN);
            gShowDialogFlag = 1;
            gDialogType = 0;
            gMain.subState = HIGH_SCORE_STATE_5;
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
                    gShowDialogFlag = 1;
                    gDialogType = 4;
                    gMain.subState = HIGH_SCORE_STATE_10;
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
        gHighScoreScreenState.nameFlashToggle = 1 - gHighScoreScreenState.nameFlashToggle;
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
            gHighScoreScreenState.nameFlashToggle = 1;
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
            gHighScoreScreenState.nameFlashToggle = 1;
            PrintHighScoreNameChar(gHighScoreScreenState.currentNameChar, gHighScoreScreenState.highScoreIndex, gHighScoreScreenState.currentNameCharIndex, gHighScoreScreenState.mainField);
            gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex] = gHighScoreScreenState.currentNameChar;
            gHighScoreScreenState.currentNameCharIndex--;
            gHighScoreScreenState.currentNameChar = gWorkingHighScores[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].data.parts.name[gHighScoreScreenState.currentNameCharIndex];
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        gHighScoreScreenState.nameFlashToggle = 1;
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
            gMain.subState = HIGH_SCORE_STATE_3;
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
            gHighScoreScreenState.nameFlashToggle = 1;
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
    gMain.subState = HIGH_SCORE_STATE_6;
}

void HighScore_LinkExchangeLoop(void)
{
    RenderHighScoreSprites();
    if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gShowDialogFlag = 0;
        gDialogType = 0;
        ResetSerialAndInterrupts();
        gMain.subState = HIGH_SCORE_STATE_3;
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
                s16 var0 = HighScore_ProcessLinkExchange();
                if (var0 == -1)
                {
                    gMain.subState = HIGH_SCORE_STATE_8;
                }
                else if (var0 == 1)
                {
                    gDialogType = 2;
                    gMain.subState = HIGH_SCORE_STATE_7;
                    m4aSongNumStart(SE_FAILURE);
                }
            }

            gLinkExchangeFrameCounter++;
            if ((gLinkStatusResult & 0x7f0000) != 0 && gLinkExchangeResult == -1 && ++gLinkTimeoutCounter > 180)
            {
                gDialogType = 2;
                gMain.subState = HIGH_SCORE_STATE_7;
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
        gMain.subState = HIGH_SCORE_STATE_5;
    }
}

void HighScore_LinkError(void)
{
    int i, j;

    RenderHighScoreSprites();
    if (++gHighScoreScreenState.linkWaitTimer > 90)
    {
        gHighScoreScreenState.linkWaitTimer = 0;
        gShowDialogFlag = 0;
        gDialogType = 0;
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
        gMain.subState = HIGH_SCORE_STATE_0;
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
        gDialogType = 3;
        m4aSongNumStart(SE_MENU_SELECT);
        break;
    case 250:
        gHighScoreScreenState.linkWaitTimer = 0;
        gShowDialogFlag = 0;
        gDialogType = 0;
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
        gMain.subState = HIGH_SCORE_STATE_12;
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
        gMain.subState = HIGH_SCORE_STATE_0;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aSongNumStart(SE_MENU_CANCEL);
        gShowDialogFlag = 0;
        gDialogType = 0;
        gMain.subState = HIGH_SCORE_STATE_3;
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
    case 0:
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

    spriteGroup = &gMain_spriteGroups[gHighScoreScreenState.nameFlashToggle];
    spriteGroup->available = TRUE;
    LoadSpriteSets(gNameEntryCursorSpriteSets, 2, gMain_spriteGroups);

    spriteGroup->baseX = gHighScoreNamePixelPositions[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].x + gHighScoreScreenState.currentNameCharIndex * 8;
    spriteGroup->baseY = gHighScoreNamePixelPositions[gHighScoreScreenState.mainField][gHighScoreScreenState.highScoreIndex].y;
    for (i = 0; i < 2; i++)
    {
        gOamBuffer[spriteGroup->oam[i].oamId].x = spriteGroup->oam[i].xOffset + spriteGroup->baseX;
        gOamBuffer[spriteGroup->oam[i].oamId].y = spriteGroup->oam[i].yOffset + spriteGroup->baseY;
    }

    spriteGroup->available = FALSE;
}

extern s8 gHighScoreDisplayMode;


#ifdef NONMATCHING
static inline void RenderHighScoreSprites_HELPER(int x, struct SpriteGroup *spriteGroup, struct SpriteGroup *spriteGroup4, struct SpriteGroup *spriteGroup3)
{
    int i;
    const struct SpriteSet *spriteSet;
    register struct OamDataSimple *oamData asm("r4");
    spriteGroup->baseX = x;
    spriteGroup->baseY = 144;
    oamData = &spriteGroup->oam[0];
    gOamBuffer[oamData->oamId].tileNum = gHighScoreScreenState.flashElapsedFrames * 2 + 2;
    gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
    gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
}

// This one is tough. I think there might be an inline function used for the shared logic
// of the two main if statements.
void RenderHighScoreSprites(void)
{
    int i;
    int count;
    register struct SpriteGroup *spriteGroups asm("r6");
    register struct SpriteGroup *spriteGroup1 asm("r4");
    struct SpriteGroup *spriteGroup2;
    struct SpriteGroup *spriteGroup3;
    struct SpriteGroup *spriteGroup4;
    struct SpriteGroup *spriteGroup5;
    register struct HighScoreScreenState *var1_02002858 asm("r9");
    const struct SpriteSet *spriteSet;
    struct OamDataSimple *oamData;

    spriteGroups = gMain_spriteGroups;
    spriteGroup1 = spriteGroups;
    spriteGroup2 = &spriteGroups[1];
    spriteGroup3 = &spriteGroups[(s8)gDialogType + 2];
    var1_02002858 = &gHighScoreScreenState;
    spriteGroup4 = &spriteGroups[gHighScoreDisplayMode + 7];

    if (gScrollXOffset == 0)
    {
        spriteGroups->available = TRUE;
        spriteGroup2->available = FALSE;
        spriteGroup3->available = gShowDialogFlag;
        spriteGroup4->available = var1_02002858->collisionCooldownTimer;
        LoadSpriteSets(gHighScoreScreenSpriteSets, 9, spriteGroups);
        RenderHighScoreSprites_HELPER(220, spriteGroup1, spriteGroup4, spriteGroup3);
        if (spriteGroup4->available == 1)
        {
            spriteGroup4->baseX = 84;
            spriteGroup4->baseY = 150;
            spriteSet = gHighScoreScreenSpriteSets[gHighScoreDisplayMode + 7];
            for (i = 0; i < spriteSet->count; i++)
            {
                oamData = &spriteGroup4->oam[i];
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup4->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup4->baseY;
            }
        }
        if (spriteGroup3->available == 1)
        {
            switch ((s8)gDialogType)
            {
            case 0:
            case 4:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 100;
                break;
            default:
                spriteGroup3->baseX = 120;
                spriteGroup3->baseY = 80;
                break;
            }
            spriteSet = gHighScoreScreenSpriteSets[(s8)gDialogType + 2];
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
        spriteGroup1->available = FALSE;
        spriteGroup2->available = TRUE;
        spriteGroup3->available = gShowDialogFlag;
        spriteGroup4->available = var1_02002858->collisionCooldownTimer;
        LoadSpriteSets(gHighScoreScreenSpriteSets, 2, gMain_spriteGroups);
        RenderHighScoreSprites_HELPER(4, spriteGroup2, spriteGroup4, spriteGroup3);
        if (spriteGroup4->available == 1)
    {
        spriteGroup4->baseX = 84;
        spriteGroup4->baseY = 150;
        spriteSet = gHighScoreScreenSpriteSets[gHighScoreDisplayMode + 7];
        for (i = 0; i < spriteSet->count; i++)
        {
            oamData = &spriteGroup4->oam[i];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup4->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup4->baseY;
        }
    }
    if (spriteGroup3->available == 1)
    {
        switch ((s8)gDialogType)
        {
        case 0:
        case 4:
            spriteGroup3->baseX = 120;
            spriteGroup3->baseY = 100;
            break;
        default:
            spriteGroup3->baseX = 120;
            spriteGroup3->baseY = 80;
            break;
        }
        spriteSet = gHighScoreScreenSpriteSets[(s8)gDialogType + 2];
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
        spriteGroup1->available = FALSE;
        spriteGroup2->available = FALSE;
        LoadSpriteSets(gHighScoreScreenSpriteSets, 9, gMain_spriteGroups);
    }

    spriteGroup3->available = FALSE;
    spriteGroup4->available = FALSE;
}
#else
NAKED
//sub_E464
void RenderHighScoreSprites(void)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r6, _0800E5CC @ =gMain_spriteGroups\n\
	adds r4, r6, #0\n\
	movs r0, #0xb8\n\
	adds r0, r0, r6\n\
	mov sl, r0\n\
	mov r5, sl\n\
	ldr r0, _0800E5D0 @ =gDialogType\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	movs r2, #0xb8\n\
	adds r1, r0, #0\n\
	muls r1, r2, r1\n\
	movs r3, #0xb8\n\
	lsls r3, r3, #1\n\
	adds r0, r6, r3\n\
	adds r7, r1, r0\n\
	ldr r0, _0800E5D4 @ =gHighScoreScreenState\n\
	mov sb, r0\n\
	ldr r1, _0800E5D8 @ =gHighScoreDisplayMode\n\
	movs r0, #0\n\
	ldrsb r0, [r1, r0]\n\
	adds r1, r0, #0\n\
	muls r1, r2, r1\n\
	movs r2, #0xa1\n\
	lsls r2, r2, #3\n\
	adds r0, r6, r2\n\
	adds r1, r1, r0\n\
	mov r8, r1\n\
	ldr r0, _0800E5DC @ =gScrollXOffset\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	cmp r1, #0\n\
	beq _0800E4B4\n\
	b _0800E674\n\
_0800E4B4:\n\
	movs r0, #1\n\
	strh r0, [r6]\n\
	strh r1, [r5]\n\
	ldr r0, _0800E5E0 @ =gShowDialogFlag\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	strh r0, [r7]\n\
	mov r0, sb\n\
	adds r0, #0x26\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
	ldr r0, _0800E5E4 @ =gHighScoreScreenSpriteSets\n\
	movs r1, #9\n\
	adds r2, r6, #0\n\
	bl LoadSpriteSets\n\
	movs r0, #0xdc\n\
	strh r0, [r6, #2]\n\
	movs r0, #0x90\n\
	strh r0, [r6, #4]\n\
	adds r4, #8\n\
	ldr r2, _0800E5E8 @ =gOamBuffer\n\
	mov sl, r2\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, sl\n\
	mov r3, sb\n\
	movs r5, #0x1a\n\
	ldrsh r1, [r3, r5]\n\
	lsls r1, r1, #1\n\
	adds r1, #2\n\
	ldr r3, _0800E5EC @ =0x000003FF\n\
	adds r0, r3, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #4]\n\
	ldr r0, _0800E5F0 @ =0xFFFFFC00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #4]\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, sl\n\
	movs r5, #2\n\
	ldrsh r1, [r4, r5]\n\
	movs r3, #2\n\
	ldrsh r0, [r6, r3]\n\
	adds r1, r1, r0\n\
	ldr r5, _0800E5F4 @ =0x000001FF\n\
	adds r0, r5, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #2]\n\
	ldr r0, _0800E5F8 @ =0xFFFFFE00\n\
	mov ip, r0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sl\n\
	ldrb r0, [r6, #4]\n\
	ldrb r4, [r4, #4]\n\
	adds r0, r0, r4\n\
	strb r0, [r1]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _0800E5AA\n\
	movs r0, #0x54\n\
	strh r0, [r1, #2]\n\
	movs r0, #0x96\n\
	strh r0, [r1, #4]\n\
	ldr r2, _0800E5D8 @ =gHighScoreDisplayMode\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #7\n\
	lsls r0, r0, #2\n\
	ldr r3, _0800E5E4 @ =gHighScoreScreenSpriteSets\n\
	adds r0, r0, r3\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	bge _0800E5AA\n\
	mov sb, sl\n\
	mov sl, ip\n\
	mov r4, r8\n\
	adds r4, #8\n\
_0800E56A:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r2, #2\n\
	ldrsh r1, [r4, r2]\n\
	mov ip, r1\n\
	mov r1, r8\n\
	movs r2, #2\n\
	ldrsh r0, [r1, r2]\n\
	mov r2, ip\n\
	adds r1, r2, r0\n\
	ldr r2, _0800E5F4 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	mov r3, r8\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r3, [r6]\n\
	cmp r5, r3\n\
	blt _0800E56A\n\
_0800E5AA:\n\
	ldrh r0, [r7]\n\
	cmp r0, #1\n\
	beq _0800E5B2\n\
	b _0800E846\n\
_0800E5B2:\n\
	ldr r0, _0800E5D0 @ =gDialogType\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	adds r2, r0, #0\n\
	cmp r1, #0\n\
	beq _0800E5C2\n\
	cmp r1, #4\n\
	bne _0800E5FC\n\
_0800E5C2:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x64\n\
	b _0800E602\n\
	.align 2, 0\n\
_0800E5CC: .4byte gMain_spriteGroups\n\
_0800E5D0: .4byte gDialogType\n\
_0800E5D4: .4byte gHighScoreScreenState\n\
_0800E5D8: .4byte gHighScoreDisplayMode\n\
_0800E5DC: .4byte gScrollXOffset\n\
_0800E5E0: .4byte gShowDialogFlag\n\
_0800E5E4: .4byte gHighScoreScreenSpriteSets\n\
_0800E5E8: .4byte gOamBuffer\n\
_0800E5EC: .4byte 0x000003FF\n\
_0800E5F0: .4byte 0xFFFFFC00\n\
_0800E5F4: .4byte 0x000001FF\n\
_0800E5F8: .4byte 0xFFFFFE00\n\
_0800E5FC:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x50\n\
_0800E602:\n\
	strh r0, [r7, #4]\n\
	ldr r1, _0800E664 @ =gHighScoreScreenSpriteSets\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #2\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	blt _0800E61C\n\
	b _0800E846\n\
_0800E61C:\n\
	ldr r1, _0800E668 @ =gOamBuffer\n\
	mov sb, r1\n\
	ldr r2, _0800E66C @ =0xFFFFFE00\n\
	mov sl, r2\n\
	adds r4, r7, #0\n\
	adds r4, #8\n\
_0800E628:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	movs r2, #2\n\
	ldrsh r0, [r7, r2]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800E670 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	ldrb r0, [r7, #4]\n\
	ldrb r3, [r4, #4]\n\
	adds r0, r0, r3\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	blt _0800E628\n\
	b _0800E846\n\
	.align 2, 0\n\
_0800E664: .4byte gHighScoreScreenSpriteSets\n\
_0800E668: .4byte gOamBuffer\n\
_0800E66C: .4byte 0xFFFFFE00\n\
_0800E670: .4byte 0x000001FF\n\
_0800E674:\n\
	cmp r1, #0xf0\n\
	beq _0800E67A\n\
	b _0800E834\n\
_0800E67A:\n\
	movs r0, #0\n\
	strh r0, [r6]\n\
	movs r0, #1\n\
	mov r1, sl\n\
	strh r0, [r1]\n\
	ldr r0, _0800E79C @ =gShowDialogFlag\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	strh r0, [r7]\n\
	mov r0, sb\n\
	adds r0, #0x26\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	ldr r0, _0800E7A0 @ =gHighScoreScreenSpriteSets\n\
	movs r1, #9\n\
	adds r2, r6, #0\n\
	bl LoadSpriteSets\n\
	movs r0, #4\n\
	mov r3, sl\n\
	strh r0, [r3, #2]\n\
	movs r0, #0x90\n\
	strh r0, [r3, #4]\n\
	adds r4, r5, #0\n\
	adds r4, #8\n\
	ldr r5, _0800E7A4 @ =gOamBuffer\n\
	mov ip, r5\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, ip\n\
	mov r0, sb\n\
	movs r3, #0x1a\n\
	ldrsh r1, [r0, r3]\n\
	lsls r1, r1, #1\n\
	adds r1, #2\n\
	ldr r5, _0800E7A8 @ =0x000003FF\n\
	adds r0, r5, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #4]\n\
	ldr r0, _0800E7AC @ =0xFFFFFC00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #4]\n\
	ldrh r2, [r4]\n\
	lsls r2, r2, #3\n\
	add r2, ip\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	mov r3, sl\n\
	movs r5, #2\n\
	ldrsh r0, [r3, r5]\n\
	adds r1, r1, r0\n\
	ldr r3, _0800E7B0 @ =0x000001FF\n\
	adds r0, r3, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #2]\n\
	ldr r0, _0800E7B4 @ =0xFFFFFE00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, ip\n\
	mov r5, sl\n\
	ldrb r0, [r5, #4]\n\
	ldrb r4, [r4, #4]\n\
	adds r0, r0, r4\n\
	strb r0, [r1]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _0800E77C\n\
	movs r0, #0x54\n\
	strh r0, [r1, #2]\n\
	movs r0, #0x96\n\
	strh r0, [r1, #4]\n\
	ldr r2, _0800E7B8 @ =gHighScoreDisplayMode\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #7\n\
	lsls r0, r0, #2\n\
	ldr r3, _0800E7A0 @ =gHighScoreScreenSpriteSets\n\
	adds r0, r0, r3\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	bge _0800E77C\n\
	mov sb, ip\n\
	ldr r1, _0800E7B4 @ =0xFFFFFE00\n\
	mov sl, r1\n\
	mov r4, r8\n\
	adds r4, #8\n\
_0800E73C:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r0, #2\n\
	ldrsh r2, [r4, r0]\n\
	mov ip, r2\n\
	mov r1, r8\n\
	movs r2, #2\n\
	ldrsh r0, [r1, r2]\n\
	mov r2, ip\n\
	adds r1, r2, r0\n\
	ldr r2, _0800E7B0 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	mov r3, r8\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r4, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r3, [r6]\n\
	cmp r5, r3\n\
	blt _0800E73C\n\
_0800E77C:\n\
	ldrh r0, [r7]\n\
	cmp r0, #1\n\
	bne _0800E846\n\
	ldr r0, _0800E7BC @ =gDialogType\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	adds r2, r0, #0\n\
	cmp r1, #0\n\
	beq _0800E792\n\
	cmp r1, #4\n\
	bne _0800E7C0\n\
_0800E792:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x64\n\
	b _0800E7C6\n\
	.align 2, 0\n\
_0800E79C: .4byte gShowDialogFlag\n\
_0800E7A0: .4byte gHighScoreScreenSpriteSets\n\
_0800E7A4: .4byte gOamBuffer\n\
_0800E7A8: .4byte 0x000003FF\n\
_0800E7AC: .4byte 0xFFFFFC00\n\
_0800E7B0: .4byte 0x000001FF\n\
_0800E7B4: .4byte 0xFFFFFE00\n\
_0800E7B8: .4byte gHighScoreDisplayMode\n\
_0800E7BC: .4byte gDialogType\n\
_0800E7C0:\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	movs r0, #0x50\n\
_0800E7C6:\n\
	strh r0, [r7, #4]\n\
	ldr r1, _0800E824 @ =gHighScoreScreenSpriteSets\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	adds r0, #2\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	movs r5, #0\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	bge _0800E846\n\
	ldr r1, _0800E828 @ =gOamBuffer\n\
	mov sb, r1\n\
	ldr r2, _0800E82C @ =0xFFFFFE00\n\
	mov sl, r2\n\
	adds r4, r7, #0\n\
	adds r4, #8\n\
_0800E7EA:\n\
	ldrh r3, [r4]\n\
	lsls r3, r3, #3\n\
	add r3, sb\n\
	movs r0, #2\n\
	ldrsh r1, [r4, r0]\n\
	movs r2, #2\n\
	ldrsh r0, [r7, r2]\n\
	adds r1, r1, r0\n\
	ldr r2, _0800E830 @ =0x000001FF\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	ldrh r2, [r3, #2]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #2]\n\
	ldrh r1, [r4]\n\
	lsls r1, r1, #3\n\
	add r1, sb\n\
	ldrb r0, [r7, #4]\n\
	ldrb r3, [r4, #4]\n\
	adds r0, r0, r3\n\
	strb r0, [r1]\n\
	adds r4, #8\n\
	adds r5, #1\n\
	ldrh r0, [r6]\n\
	cmp r5, r0\n\
	blt _0800E7EA\n\
	b _0800E846\n\
	.align 2, 0\n\
_0800E824: .4byte gHighScoreScreenSpriteSets\n\
_0800E828: .4byte gOamBuffer\n\
_0800E82C: .4byte 0xFFFFFE00\n\
_0800E830: .4byte 0x000001FF\n\
_0800E834:\n\
	movs r0, #0\n\
	strh r0, [r6]\n\
	mov r1, sl\n\
	strh r0, [r1]\n\
	ldr r0, _0800E85C @ =gHighScoreScreenSpriteSets\n\
	movs r1, #9\n\
	adds r2, r6, #0\n\
	bl LoadSpriteSets\n\
_0800E846:\n\
	movs r0, #0\n\
	strh r0, [r7]\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800E85C: .4byte gHighScoreScreenSpriteSets\n\
    ");
}
#endif

void RenderCompletionBanner(void)
{
    int i;
    struct SpriteGroup *spriteGroup;

    spriteGroup = &gMain_spriteGroups[gCompletionBannerFrame];
    spriteGroup->available = gCompletionBannerVisible;
    LoadSpriteSets(gCompletionBannerSpriteSets, 5, gMain_spriteGroups);
    if (spriteGroup->available == 1)
    {
        spriteGroup->baseX = 120;
        spriteGroup->baseY = gCompletionBannerY;
        for (i = 0; i < 4; i++)
        {
            gOamBuffer[spriteGroup->oam[i].oamId].x = spriteGroup->oam[i].xOffset + spriteGroup->baseX;
            gOamBuffer[spriteGroup->oam[i].oamId].y = spriteGroup->oam[i].yOffset + spriteGroup->baseY;
        }
    }

    spriteGroup->available = FALSE;
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
                gDialogType = 1;
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
                gDialogType = 1;
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
        if (scoreHi > 9999999)
        {
            scoreHi = 9999999;
            scoreLo = 99999999;
        }
        else if (scoreLo > 99999999)
        {
            scoreLo = 99999999;
        }

        arr = gScoreDigitBuffer;

        var0 = scoreHi / 1000000;
        arr[0] = var0;
        scoreHi %= 1000000;
        arr[1] = scoreHi / 100000;
        scoreHi %= 100000;
        arr[2] = scoreHi / 10000;
        scoreHi %= 10000;
        arr[3] = scoreHi / 1000;
        scoreHi %= 1000;
        arr[4] = scoreHi / 100;
        scoreHi %= 100;
        arr[5] = scoreHi / 10;
        arr[6] = scoreHi %= 10;

        arr[7] = scoreLo / 10000000;
        var1 = scoreLo % 10000000;
        arr[8] = var1 / 1000000;
        var1 %= 1000000;
        arr[9] = var1 / 100000;
        var1 %= 100000;
        arr[10] = var1 / 10000;
        var1 %= 10000;
        arr[11] = var1 / 1000;
        var1 %= 1000;
        arr[12] = var1 / 100;
        var1 %= 100;
        arr[13] = var1 / 10;
        arr[14] = var1 %= 10;

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

    gCompletionBannerDone = 0;
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

