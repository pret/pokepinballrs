#include "global.h"
#include "m4a.h"
#include "main.h"
#include "titlescreen.h"
#include "constants/bg_music.h"

#define BGM_COUNT   34
#define SE_COUNT    184

enum OptionsState
{
    OPTIONS_STATE_MAIN,
    OPTIONS_STATE_BGM_SELECT,
    OPTIONS_STATE_SE_MENU_MOVE_0x67,
    OPTIONS_STATE_BUTTON_CONFIG_SELECT,
    OPTIONS_STATE_BUTTON_CONFIG_INPUT,
};

enum CursorPositions
{
    CURSOR_POS_BGM,
    CURSOR_POS_SE,
    CURSOR_POS_BUTTON_CONFIG_TYPE_A,
    CURSOR_POS_BUTTON_CONFIG_TYPE_B,
    CURSOR_POS_BUTTON_CONFIG_TYPE_C,
    CURSOR_POS_BUTTON_CONFIG_TYPE_D,
    CURSOR_POS_BUTTON_CONFIG_EDIT,
    CURSOR_POS_LEFT_FLIPPER,
    CURSOR_POS_RIGHT_FLIPPER,
    CURSOR_POS_TILT_LEFT,
    CURSOR_POS_TILT_RIGHT,
    CURSOR_POS_TILT_UP,
    CURSOR_POS_RUMBLE_ON = 13,
    CURSOR_POS_RUMBLE_OFF,
};

struct OptionsData
{
    s16 stateMain;
    u16 cursorBlinkToggle;
    s16 soundTestBlinkToggle;
    s16 buttonFlashVisible;
    s16 buttonFlashTimer;
    s16 cursorPosition;
    s16 buttonConfigType;
    s16 selectedBGM;
    s16 selectedSE;
    u8 digitsBGM[3];
    u8 digitsSE[3];
    s16 scollWaitFrames;
    u8 buttonEditFlags[6];
    s16 captureFramesRemaining;
    s16 capturedKeysMask;
    s16 capturedButtonSlots[2];
    s16 capturedButtonCount;
    bool8 rumbleEnabled;
    s8 torchicAnimTimer;
    s8 torchicAnimFrame;
    s8 torchicAnimTileId;
    s8 torchicHeadShakeAnimActive;
    s8 noteSizeBlinkState;
    s8 soundTestActive;
};

extern struct OptionsData gOptionsData;
extern s16 gMain_saveData_customButtonConfig[][2];
extern u8 gCustomButtonConfigTileIds[];

extern const Palette gOptionsBackground_Pals[];
extern const u8 gOptionsText_Gfx[];
extern const u8 gOptionsBackground_Gfx[];
extern const u8 gOptionsText_Tilemap[];
extern const u8 gOptionsBackground_Tilemap[];


extern u8 gOptionsButtonConfigEditFlags[];
extern const struct Vector16 gOptionsCursorPositionTable[];
extern const u16 gOptionsBGMSelectorYPositions[];
extern const struct SpriteSet *const gOptionsSpriteSets[];

void Options_Main(void)
{
    gOptionsStateFuncs[gMain.subState]();
}

void Options_LoadGraphics(void)
{
    ResetDisplayState();

    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_FORCED_BLANK;
    REG_BG0CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(0) | BGCNT_CHARBASE(1);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(2);
    REG_DISPCNT |= DISPCNT_BG1_ON;

    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gOptionsBackground_Pals, BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gOptionsText_Gfx,        BG_CHAR_ADDR(1), 0x1800);
    DmaCopy16(3, gOptionsBackground_Gfx,  BG_CHAR_ADDR(2), 0xC00);
    DmaCopy16(3, gOptionsText_Tilemap,    gBG0TilemapBuffer, BG_SCREEN_SIZE);
    DmaCopy16(3, gBG0TilemapBuffer,       BG_CHAR_ADDR(0), BG_SCREEN_SIZE);

    if (gGameBoyPlayerEnabled != TRUE)
    {
        SetStringPalette(18, 4, 2, 1, 2);
        SetStringPalette(18, 5, 3, 2, 2);
    }

    DmaCopy16(3, gBG0TilemapBuffer,          BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gOptionsBackground_Tilemap, BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gGBAButtonIcons_Pals,       OBJ_PLTT_SLOT(0), 3*PLTT_SLOT_SIZE);
    DmaCopy16(3, gOptionsSprites_Gfx,        OBJ_VRAM0, 0x2020);
    Options_InitStates();
    UpdateOptionsSpritePositions();
    m4aMPlayAllStop();
    EnableVBlankInterrupts();
    FadeInScreen();
    EnableGbPlayerRumble();

    gMain.subState++;
}

void Options_InitStates(void)
{
    int i;
    int j;

    gOptionsData.stateMain = OPTIONS_STATE_MAIN;
    gOptionsData.cursorBlinkToggle = 0;
    gOptionsData.soundTestBlinkToggle = 0;
    gOptionsData.buttonFlashVisible = 1;
    gOptionsData.buttonFlashTimer = 0;
    gOptionsData.cursorPosition = CURSOR_POS_BGM;
    gOptionsData.buttonConfigType = gMain_saveData.buttonConfigType;
    gOptionsData.selectedBGM = 0;
    gOptionsData.selectedSE = 0;
    gOptionsData.digitsBGM[0] = 0;
    gOptionsData.digitsBGM[1] = 0;
    gOptionsData.digitsBGM[2] = 1;
    gOptionsData.digitsSE[0] = 0;
    gOptionsData.digitsSE[1] = 0;
    gOptionsData.digitsSE[2] = 1;
    gOptionsData.scollWaitFrames = 0;
    for (i = 0; i < 6; i++)
        gOptionsData.buttonEditFlags[i] = 0;
    gOptionsData.captureFramesRemaining = 0;
    gOptionsData.capturedKeysMask = 0;
    for (i = 0; i < 2; i++)
        gOptionsData.capturedButtonSlots[i] = 10;
    gOptionsData.capturedButtonCount = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10; j++)
            gCustomButtonConfigs[i][j] = gDefaultButtonConfigs[i][j];
    }
    InitCustomButtonConfigDisplay();
    if (gGameBoyPlayerEnabled == TRUE)
    {
        gOptionsData.rumbleEnabled = gMain_saveData.rumbleEnabled;
        gMain_saveData.rumbleEnabled = TRUE;
    }
    else
    {
        gOptionsData.rumbleEnabled = FALSE;
        gMain_saveData.rumbleEnabled = FALSE;
    }
    gOptionsData.torchicHeadShakeAnimActive = FALSE;
    gOptionsData.torchicAnimTimer = 0;
    gOptionsData.torchicAnimFrame = 0;
    gOptionsData.torchicAnimTileId = 0;
    gOptionsData.noteSizeBlinkState = 0;
    gOptionsData.soundTestActive = FALSE;
}

void Options_HandleInput(void)
{
    s16 r4;

    UpdateOptionsSpritePositions();
    switch (gOptionsData.stateMain)
    {
    case OPTIONS_STATE_MAIN:
        if (JOY_NEW(DPAD_UP))
        {
            if (gOptionsData.cursorPosition != CURSOR_POS_RUMBLE_ON)
            {
                if (gOptionsData.cursorPosition == CURSOR_POS_RUMBLE_OFF)
                {
                    m4aSongNumStart(SE_MENU_MOVE);
                    gOptionsData.cursorPosition = CURSOR_POS_RUMBLE_ON;
                }
                else if (gOptionsData.cursorPosition > CURSOR_POS_BGM)
                {
                    m4aSongNumStart(SE_MENU_MOVE);
                    gOptionsData.cursorPosition--;
                }
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (gOptionsData.cursorPosition < CURSOR_POS_BUTTON_CONFIG_EDIT)
            {
                m4aSongNumStart(SE_MENU_MOVE);
                gOptionsData.cursorPosition++;
            }
            else if (gOptionsData.cursorPosition == CURSOR_POS_RUMBLE_ON)
            {
                m4aSongNumStart(SE_MENU_MOVE);
                gOptionsData.cursorPosition = CURSOR_POS_RUMBLE_OFF;
            }
            else if (gOptionsData.cursorPosition == CURSOR_POS_RUMBLE_OFF)
            {
                m4aSongNumStart(SE_MENU_MOVE);
                gOptionsData.cursorPosition = CURSOR_POS_BUTTON_CONFIG_TYPE_A;
            }
        }
        if ((JOY_NEW(DPAD_RIGHT)) && gGameBoyPlayerEnabled == TRUE && (u16)gOptionsData.cursorPosition < CURSOR_POS_BUTTON_CONFIG_TYPE_A)
        {
            m4aSongNumStart(SE_MENU_MOVE);
            gOptionsData.cursorPosition += CURSOR_POS_RUMBLE_ON;
        }
        if ((JOY_NEW(DPAD_LEFT)) && gGameBoyPlayerEnabled == TRUE && (u16)(gOptionsData.cursorPosition - CURSOR_POS_RUMBLE_ON) < 2)
        {
            m4aSongNumStart(SE_MENU_MOVE);
            gOptionsData.cursorPosition -= CURSOR_POS_RUMBLE_ON;
        }
        if (JOY_NEW(A_BUTTON))
        {
            switch (gOptionsData.cursorPosition)
            {
            case CURSOR_POS_BGM:
                m4aSongNumStart(SE_MENU_SELECT);
                gOptionsData.stateMain = OPTIONS_STATE_BGM_SELECT,
                gOptionsData.scollWaitFrames = 0;
                gOptionsData.soundTestActive = TRUE;
                if (gOptionsData.torchicHeadShakeAnimActive == TRUE)
                {
                    gOptionsData.torchicAnimTimer = 0;
                    gOptionsData.torchicAnimTileId = 0;
                    gOptionsData.torchicAnimFrame = 0;
                    gOptionsData.torchicHeadShakeAnimActive = FALSE;
                }
                break;
            case CURSOR_POS_SE:
                m4aSongNumStart(SE_MENU_SELECT);
                gOptionsData.stateMain = OPTIONS_STATE_SE_MENU_MOVE_0x67,
                gOptionsData.scollWaitFrames = 0;
                gOptionsData.soundTestActive = TRUE;
                if (gOptionsData.torchicHeadShakeAnimActive == TRUE)
                {
                    gOptionsData.torchicAnimTimer = 0;
                    gOptionsData.torchicAnimTileId = 0;
                    gOptionsData.torchicAnimFrame = 0;
                    gOptionsData.torchicHeadShakeAnimActive = FALSE;
                }
                break;
            case CURSOR_POS_BUTTON_CONFIG_TYPE_A:
            case CURSOR_POS_BUTTON_CONFIG_TYPE_B:
            case CURSOR_POS_BUTTON_CONFIG_TYPE_C:
            case CURSOR_POS_BUTTON_CONFIG_TYPE_D:
                m4aSongNumStart(SE_MENU_SELECT);
                gOptionsData.buttonConfigType = gOptionsData.cursorPosition - CURSOR_POS_BUTTON_CONFIG_TYPE_A;
                gMain_saveData.buttonConfigType = gOptionsData.buttonConfigType;
                break;
            case CURSOR_POS_BUTTON_CONFIG_EDIT:
                m4aSongNumStart(SE_MENU_SELECT);
                gOptionsData.buttonConfigType = gOptionsData.cursorPosition - CURSOR_POS_BUTTON_CONFIG_TYPE_A;
                gMain_saveData.buttonConfigType = gOptionsData.buttonConfigType;
                gOptionsData.cursorPosition = CURSOR_POS_LEFT_FLIPPER;
                gOptionsData.stateMain = OPTIONS_STATE_BUTTON_CONFIG_SELECT;
                break;
            case CURSOR_POS_RUMBLE_OFF:
                if (gGameBoyPlayerEnabled == TRUE)
                {
                    m4aSongNumStart(SE_MENU_SELECT);
                    gOptionsData.torchicAnimTileId = 0;
                    if (gOptionsData.torchicHeadShakeAnimActive == TRUE)
                        gOptionsData.torchicHeadShakeAnimActive = FALSE;
                    gOptionsData.torchicAnimTimer = 0;
                    gOptionsData.torchicAnimFrame = 0;
                    gOptionsData.rumbleEnabled = FALSE;
                }
                break;
            case CURSOR_POS_RUMBLE_ON:
                if (gGameBoyPlayerEnabled == TRUE)
                {
                    m4aSongNumStart(SE_MENU_SELECT);
                    PlayRumble(11);
                    if (!gOptionsData.torchicHeadShakeAnimActive)
                        gOptionsData.torchicHeadShakeAnimActive = TRUE;

                    gOptionsData.torchicAnimTimer = 0;
                    gOptionsData.torchicAnimFrame = 0;
                    gOptionsData.rumbleEnabled = TRUE;
                }
                break;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gMain.subState++;
            SetButtonConfigInputs(gMain_saveData.buttonConfigType);
        }
        if (!(gMain.systemFrameCount & 7))
            gOptionsData.cursorBlinkToggle = 1 - gOptionsData.cursorBlinkToggle;
        break;
    case OPTIONS_STATE_BGM_SELECT:
        if (JOY_HELD(DPAD_LEFT))
        {
            if (gOptionsData.scollWaitFrames == 0)
            {
                gOptionsData.selectedBGM--;
                gOptionsData.scollWaitFrames = 10;
            }
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            if (gOptionsData.scollWaitFrames == 0)
            {
                gOptionsData.selectedBGM++;
                gOptionsData.scollWaitFrames = 10;
            }
        }

        if (JOY_NEW(DPAD_UP))
            gOptionsData.selectedBGM += 10;
        else if (JOY_NEW(DPAD_DOWN))
            gOptionsData.selectedBGM -= 10;

        if (gOptionsData.selectedBGM < 0)
            gOptionsData.selectedBGM = BGM_COUNT - 1;
        if (gOptionsData.selectedBGM >= BGM_COUNT)
            gOptionsData.selectedBGM = 0;

        r4 = gOptionsData.selectedBGM + 1;
        gOptionsData.digitsBGM[0] = LEAD_DIGIT_100S(r4);
        r4 %= 100;
        gOptionsData.digitsBGM[1] = LEAD_DIGIT_10S(r4);
        gOptionsData.digitsBGM[2] = DIGIT_1S(r4);
        if (JOY_NEW(A_BUTTON))
        {
            m4aMPlayAllStop();
            m4aSongNumStart(gOptionsBGMList[gOptionsData.selectedBGM]);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aMPlayAllStop();
            m4aSongNumStart(SE_MENU_CANCEL);
            gOptionsData.soundTestBlinkToggle = 0;
            gOptionsData.soundTestActive = FALSE;
            gOptionsData.stateMain = OPTIONS_STATE_MAIN;
        }
        if (!(gMain.systemFrameCount & 7))
            gOptionsData.soundTestBlinkToggle = 1 - gOptionsData.soundTestBlinkToggle;
        if (gOptionsData.scollWaitFrames > 0)
            gOptionsData.scollWaitFrames--;
        break;
    case OPTIONS_STATE_SE_MENU_MOVE_0x67:
        if (JOY_HELD(DPAD_LEFT))
        {
            if (gOptionsData.scollWaitFrames == 0)
            {
                gOptionsData.selectedSE--;
                gOptionsData.scollWaitFrames = 10;
            }
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            if (gOptionsData.scollWaitFrames == 0)
            {
                gOptionsData.selectedSE++;
                gOptionsData.scollWaitFrames = 10;
            }
        }

        if (JOY_NEW(DPAD_UP))
            gOptionsData.selectedSE += 10;
        else if (JOY_NEW(DPAD_DOWN))
            gOptionsData.selectedSE -= 10;

        if (gOptionsData.selectedSE < 0)
            gOptionsData.selectedSE = SE_COUNT - 1;
        if (gOptionsData.selectedSE >= SE_COUNT)
            gOptionsData.selectedSE = 0;

        r4 = gOptionsData.selectedSE + 1;
        gOptionsData.digitsSE[0] = LEAD_DIGIT_100S(r4);
        r4 %= 100;
        gOptionsData.digitsSE[1] = LEAD_DIGIT_10S(r4);
        gOptionsData.digitsSE[2] = DIGIT_1S(r4);
        if (JOY_NEW(A_BUTTON))
        {
            m4aMPlayAllStop();
            m4aSongNumStart(gOptionsSEList[gOptionsData.selectedSE]);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aMPlayAllStop();
            m4aSongNumStart(SE_MENU_CANCEL);
            gOptionsData.soundTestBlinkToggle = 0;
            gOptionsData.soundTestActive = FALSE;
            gOptionsData.stateMain = OPTIONS_STATE_MAIN;
        }
        if (!(gMain.systemFrameCount & 7))
            gOptionsData.soundTestBlinkToggle = 1 - gOptionsData.soundTestBlinkToggle;
        if (gOptionsData.scollWaitFrames > 0)
            gOptionsData.scollWaitFrames--;
        break;
    case OPTIONS_STATE_BUTTON_CONFIG_SELECT:
        if (JOY_NEW(DPAD_UP))
        {
            if (gOptionsData.cursorPosition > CURSOR_POS_LEFT_FLIPPER)
            {
                m4aSongNumStart(SE_MENU_MOVE);
                gOptionsData.cursorPosition--;
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (gOptionsData.cursorPosition < CURSOR_POS_TILT_UP)
            {
                m4aSongNumStart(SE_MENU_MOVE);
                gOptionsData.cursorPosition++;
            }
        }
        if (JOY_NEW(A_BUTTON))
        {
            m4aSongNumStart(SE_MENU_SELECT);
            gOptionsData.stateMain = OPTIONS_STATE_BUTTON_CONFIG_INPUT,
            gOptionsData.buttonEditFlags[gOptionsData.cursorPosition - CURSOR_POS_LEFT_FLIPPER] = 1;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            m4aSongNumStart(SE_MENU_CANCEL);
            gOptionsData.cursorPosition = CURSOR_POS_BUTTON_CONFIG_EDIT;
            gOptionsData.stateMain = OPTIONS_STATE_MAIN;
        }
        if (!(gMain.systemFrameCount & 7))
            gOptionsData.cursorBlinkToggle = 1 - gOptionsData.cursorBlinkToggle;
        break;
    case OPTIONS_STATE_BUTTON_CONFIG_INPUT:
        gOptionsData.buttonFlashTimer++;
        if (gOptionsData.buttonFlashTimer > 24)
        {
            gOptionsData.buttonFlashTimer = 0;
            gOptionsData.buttonFlashVisible = 1 - gOptionsData.buttonFlashVisible;
        }
        if (JOY_NEW(KEYS_MASK ^ START_BUTTON))
        {
            s16 i;

            m4aSongNumStart(SE_MENU_SELECT);
            gOptionsData.captureFramesRemaining = 10;
            gOptionsData.capturedKeysMask = 0;
            for (i = 0; i < 2; i++)
                gOptionsData.capturedButtonSlots[i] = 10;
            gOptionsData.capturedButtonCount = 0;
        }
        if (gOptionsData.captureFramesRemaining > 0)
        {
            CaptureButtonConfigInput();
            gOptionsData.captureFramesRemaining--;
            if (gOptionsData.captureFramesRemaining == 0)
            {
                gCustomButtonConfigs[4][(gOptionsData.cursorPosition - CURSOR_POS_LEFT_FLIPPER) * 2 + 0] = gOptionsData.capturedButtonSlots[0];
                gCustomButtonConfigs[4][(gOptionsData.cursorPosition - CURSOR_POS_LEFT_FLIPPER) * 2 + 1] = gOptionsData.capturedButtonSlots[1];
                gMain_saveData.customButtonConfig[(gOptionsData.cursorPosition - CURSOR_POS_LEFT_FLIPPER)][0] = gButtonInfoTable[gOptionsData.capturedButtonSlots[0]].buttonName;
                gMain_saveData.customButtonConfig[(gOptionsData.cursorPosition - CURSOR_POS_LEFT_FLIPPER)][1] = gButtonInfoTable[gOptionsData.capturedButtonSlots[1]].buttonName;
                gOptionsData.stateMain = OPTIONS_STATE_BUTTON_CONFIG_SELECT,
                gOptionsData.buttonEditFlags[gOptionsData.cursorPosition - CURSOR_POS_LEFT_FLIPPER] = 0;
                gOptionsData.buttonFlashTimer = 0;
                gOptionsData.buttonFlashVisible = 1;
            }
        }
        break;
    }
    if (gOptionsData.torchicHeadShakeAnimActive == TRUE)
    {
        if (++gOptionsData.torchicAnimTimer > gButtonAnimData[gOptionsData.torchicAnimFrame].frameDuration)
        {
            gOptionsData.torchicAnimTimer = 0;
            gOptionsData.torchicAnimFrame++;
            if (gOptionsData.torchicAnimFrame > 12)
            {
                gOptionsData.torchicAnimFrame = 0;
                gOptionsData.torchicAnimTileId = 0;
                gOptionsData.torchicHeadShakeAnimActive = FALSE;
            }
            gOptionsData.torchicAnimTileId = gButtonAnimData[gOptionsData.torchicAnimFrame].tileId;
        }
    }
    else
    {
        gOptionsData.torchicAnimTimer++;
        if (gOptionsData.torchicAnimTimer > 18)
        {
            gOptionsData.torchicAnimTimer = 0;
            gOptionsData.torchicAnimTileId = 1 - gOptionsData.torchicAnimTileId;
        }
    }
    ProcessRumbleFrame();
}

void Options_State2_51C3C(void)
{
    DisableGbPlayerRumble();
    if (IsGbPlayerReady())
    {
        RestoreDefaultInterrupts();
        gMain.subState++;
    }
}

void Options_State3_51C60(void)
{
    gMain_saveData.rumbleEnabled = gOptionsData.rumbleEnabled;
    SaveFile_WriteToSram();
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(STATE_TITLE);
}


// Associated with fakematch in UpdateOptionsSpritePositions. Leaving here.
extern struct SpriteGroup gMain_spriteGroups_10;

void UpdateOptionsSpritePositions(void)
{
    struct SpriteGroup *numberBGM[3];
    struct SpriteGroup *numberSE[3];
    struct SpriteGroup *buttonConfig[6][3];
    struct SpriteGroup *handPointer = &gMain.spriteGroups[0];
    struct SpriteGroup *torchic = &gMain.spriteGroups[30];
    struct SpriteGroup *noteBalloon = &gMain.spriteGroups[31];
    struct SpriteGroup *buttonArrow = &gMain.spriteGroups[8];
    struct SpriteGroup *soundSelectArrow;
    struct SpriteGroup *rumbleArrowMain = &gMain.spriteGroups[29];
    struct SpriteGroup *rumbleArrow;
    struct OamDataSimple *oam;
    int i = 0;
    int j = 0;

    soundSelectArrow =
        &gMain.spriteGroups[(20 * gOptionsData.soundTestBlinkToggle) + 7];

    for (i = 0; i < 3; i++)
    {
        numberBGM[i] = &gMain.spriteGroups[1 + i];
        numberSE[i] = &gMain.spriteGroups[4 + i];
    }

    //TODO: FAKEMATCH
    for (i = 0; i < 6; i++)
    {
        struct SpriteGroup *buttonBase = &gMain_spriteGroups_10;

        do
        {
            if ((gOptionsButtonConfigEditFlags[i] == TRUE)
                && (gOptionsData.buttonFlashVisible == TRUE))
            {
                buttonConfig[i][0] = &gMain.spriteGroups[28];
            }
            else
            {
                do
                {
                    struct SpriteGroup *normalButton = buttonBase + (3 * i);
                    buttonConfig[i][0] = --normalButton;
                } while (0);
            }
        } while (0);

        buttonConfig[i][1] = buttonBase + (3 * i);
        buttonConfig[i][2] = buttonBase + (3 * i) + 1;
    }

    rumbleArrow = rumbleArrowMain;
    handPointer->active = TRUE;
    for (i = 0; i < 3; i++)
        numberBGM[i]->active = TRUE;

    for (i = 0; i < 3; i++)
        numberSE[i]->active = TRUE;

    soundSelectArrow->active = TRUE;
    buttonArrow->active = TRUE;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 3; j++)
            buttonConfig[i][j]->active = TRUE;
    }

    rumbleArrow->active = TRUE;
    torchic->active = TRUE;
    noteBalloon->active = gOptionsData.soundTestActive;
    LoadSpriteSets(gOptionsSpriteSets, 32, gMain.spriteGroups);

    handPointer->baseX =
        gOptionsCursorPositionTable[gOptionsData.cursorPosition].x
        + gOptionsData.cursorBlinkToggle;
    handPointer->baseY = gOptionsCursorPositionTable[gOptionsData.cursorPosition].y;

    oam = &handPointer->oam[0];
    gOamBuffer[oam->oamId].x = oam->xOffset + handPointer->baseX;
    gOamBuffer[oam->oamId].y = oam->yOffset + handPointer->baseY;

    for (i = 0; i < 3; i++)
    {
        numberBGM[i]->baseX = 72 + (i * 7);
        numberBGM[i]->baseY = 32;
        oam = &numberBGM[i]->oam[0];
        gOamBuffer[oam->oamId].tileNum = gOptionsData.digitsBGM[i] + 0x16;
        gOamBuffer[oam->oamId].x = oam->xOffset + numberBGM[i]->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + numberBGM[i]->baseY;
    }

    for (i = 0; i < 3; i++)
    {
        numberSE[i]->baseX = 72 + (i * 7);
        numberSE[i]->baseY = 44;
        oam = &numberSE[i]->oam[0];
        gOamBuffer[oam->oamId].tileNum = gOptionsData.digitsSE[i] + 0x16;
        gOamBuffer[oam->oamId].x = oam->xOffset + numberSE[i]->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + numberSE[i]->baseY;
    }

    soundSelectArrow->baseX = 72;
    if (gOptionsData.cursorPosition == 0)
        soundSelectArrow->baseY = 32;
    else if (gOptionsData.cursorPosition == 1)
        soundSelectArrow->baseY = 44;

    for (i = 0; i < 2; i++)
    {
        oam = &soundSelectArrow->oam[i];
        gOamBuffer[oam->oamId].x = oam->xOffset + soundSelectArrow->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + soundSelectArrow->baseY;
    }

    buttonArrow->baseX = 72;
    buttonArrow->baseY = gOptionsBGMSelectorYPositions[gOptionsData.buttonConfigType];

    oam = &buttonArrow->oam[0];
    gOamBuffer[oam->oamId].x = oam->xOffset + buttonArrow->baseX;
    gOamBuffer[oam->oamId].y = oam->yOffset + buttonArrow->baseY;

    for (i = 0; i < 5; i++)
    {
        if (gOptionsData.buttonEditFlags[i] == TRUE)
        {
            buttonConfig[i][0]->baseX = 156;
            buttonConfig[i][0]->baseY = 84 + (12 * i);

            for (j = 0; j < (gOptionsData.buttonFlashVisible + 1); j++)
            {
                oam = &buttonConfig[i][0]->oam[j];
                gOamBuffer[oam->oamId].x = oam->xOffset + buttonConfig[i][0]->baseX;
                gOamBuffer[oam->oamId].y = oam->yOffset + buttonConfig[i][0]->baseY;
            }
        }
        else
        {
            u8 btn1Ix = 0;
            u8 btn2Ix = 0;

            buttonConfig[i][0]->baseX = 156;
            buttonConfig[i][0]->baseY = 84 + (12 * i);
            oam = &buttonConfig[i][0]->oam[0];

            btn1Ix = gCustomButtonConfigs[gOptionsData.buttonConfigType][2 * i];
            gOamBuffer[oam->oamId].tileNum = gButtonInfoTable[btn1Ix].tileNum;
            gOamBuffer[oam->oamId].shape = gButtonInfoTable[btn1Ix].shape;
            gOamBuffer[oam->oamId].size = gButtonInfoTable[btn1Ix].size;
            gOamBuffer[oam->oamId].x = oam->xOffset + buttonConfig[i][0]->baseX;
            gOamBuffer[oam->oamId].y = oam->yOffset + buttonConfig[i][0]->baseY;

            btn2Ix = gCustomButtonConfigs[gOptionsData.buttonConfigType][(2 * i) + 1];
            if (btn2Ix != 0xa)
            {
                buttonConfig[i][1]->baseX = gButtonInfoTable[btn1Ix].x + buttonConfig[i][0]->baseX;
                buttonConfig[i][1]->baseY = buttonConfig[i][0]->baseY;
                oam = &buttonConfig[i][1]->oam[0];

                gOamBuffer[oam->oamId].tileNum = 0x2a;
                gOamBuffer[oam->oamId].shape = ST_OAM_SQUARE;
                gOamBuffer[oam->oamId].size = 0;
                gOamBuffer[oam->oamId].x = oam->xOffset + buttonConfig[i][1]->baseX;
                gOamBuffer[oam->oamId].y = oam->yOffset + buttonConfig[i][1]->baseY;

                buttonConfig[i][2]->baseX = 8 + buttonConfig[i][1]->baseX;
                buttonConfig[i][2]->baseY = buttonConfig[i][0]->baseY;
                oam = &buttonConfig[i][2]->oam[0];

                gOamBuffer[oam->oamId].tileNum = gButtonInfoTable[btn2Ix].tileNum;
                gOamBuffer[oam->oamId].shape = gButtonInfoTable[btn2Ix].shape;
                gOamBuffer[oam->oamId].size = gButtonInfoTable[btn2Ix].size;
                gOamBuffer[oam->oamId].x = oam->xOffset + buttonConfig[i][2]->baseX;
                gOamBuffer[oam->oamId].y = oam->yOffset + buttonConfig[i][2]->baseY;
            }
        }
    }

    rumbleArrow->baseX = 170;
    rumbleArrow->baseY = 44 - (gOptionsData.rumbleEnabled * 12);
    oam = &rumbleArrow->oam[0];
    gOamBuffer[oam->oamId].x = oam->xOffset + rumbleArrow->baseX;
    gOamBuffer[oam->oamId].y = oam->yOffset + rumbleArrow->baseY;

    torchic->baseX = 192;
    torchic->baseY = 8;
    for (i = 0; i < 2; i++)
    {
        oam = &torchic->oam[i];
        gOamBuffer[oam->oamId].tileNum =
            (0x40 + (i * 0x80)) + (gOptionsData.torchicAnimTileId * 4);
        gOamBuffer[oam->oamId].x = oam->xOffset + torchic->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + torchic->baseY;
    }

    if (noteBalloon->active == TRUE)
    {
        noteBalloon->baseX = 176;
        noteBalloon->baseY = 8;
        oam = &noteBalloon->oam[0];
        gOamBuffer[oam->oamId].tileNum = (gOptionsData.noteSizeBlinkState * 0x40) + 0x54;
        gOamBuffer[oam->oamId].x = oam->xOffset + noteBalloon->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + noteBalloon->baseY;

        if ((gMain.systemFrameCount % 18) == 0)
        {
            gOptionsData.noteSizeBlinkState = 1 - gOptionsData.noteSizeBlinkState;
        }
    }

    soundSelectArrow->active = FALSE;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 3; j++)
            buttonConfig[i][j]->active = FALSE;
    }
}

void CaptureButtonConfigInput(void)
{
    int i, pressedKeys;
    if (gOptionsData.capturedButtonCount >= 2)
        return;

    pressedKeys = JOY_HELD(KEYS_MASK ^ START_BUTTON);
    if (!pressedKeys)
        return;

    for (i = 0; i < 10; i++)
    {
        int key = pressedKeys & (1 << i);
        if (key && !(gOptionsData.capturedKeysMask & key))
        {
            gOptionsData.capturedKeysMask |= key;
            gOptionsData.capturedButtonSlots[gOptionsData.capturedButtonCount] = i;
            if (++gOptionsData.capturedButtonCount == 2)
                return;
        }
    }
}

void InitCustomButtonConfigDisplay(void)
{
    int i, j;
    u8 var0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 2; j++)
        {
            switch (gMain_saveData_customButtonConfig[i][j])
            {
            case 0x1:
                var0 = 0;
                break;
            case 0x2:
                var0 = 1;
                break;
            case 0x4:
                var0 = 2;
                break;
            case 0x10:
                var0 = 4;
                break;
            case 0x20:
                var0 = 5;
                break;
            case 0x40:
                var0 = 6;
                break;
            case 0x80:
                var0 = 7;
                break;
            case 0x100:
                var0 = 8;
                break;
            case 0x200:
                var0 = 9;
                break;
            case 0x8:
            default:
                var0 = 10;
                break;
            }
            gCustomButtonConfigTileIds[i * 2 + j] = var0;
        }
    }
}

extern const u8 gDefaultCustomButtonConfigTileIds[];

void SetButtonConfigInputs(s8 buttonConfigType)
{
    int i;
    switch (buttonConfigType)
    {
    case BUTTON_CONFIG_RESET:
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][0] = gButtonInfoTable[5].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][0] = gButtonInfoTable[0].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][0] = gButtonInfoTable[9].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][0] = gButtonInfoTable[8].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][0] = gButtonInfoTable[9].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][1] = gButtonInfoTable[8].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_LEFT_FLIPPER][0]  = gButtonInfoTable[1].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_LEFT_FLIPPER][1]  = gButtonInfoTable[10].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_RIGHT_FLIPPER][0] = gButtonInfoTable[0].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_RIGHT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_LEFT][0]     = gButtonInfoTable[5].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_LEFT][1]     = gButtonInfoTable[10].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_RIGHT][0]    = gButtonInfoTable[4].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_RIGHT][1]    = gButtonInfoTable[10].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_UP][0]       = gButtonInfoTable[6].buttonName;
        gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_UP][1]       = gButtonInfoTable[10].buttonName;
        for (i = 0; i < 10; i++)
            gCustomButtonConfigTileIds[i] = gDefaultCustomButtonConfigTileIds[i];
        break;
    case BUTTON_CONFIG_TYPE_A:
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][0] = gButtonInfoTable[5].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][0] = gButtonInfoTable[0].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][0] = gButtonInfoTable[9].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][0] = gButtonInfoTable[8].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][0] = gButtonInfoTable[9].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][1] = gButtonInfoTable[8].buttonName;
        break;
    case BUTTON_CONFIG_TYPE_B:
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][0] = gButtonInfoTable[5].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][0] = gButtonInfoTable[0].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][0] = gButtonInfoTable[9].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][0] = gButtonInfoTable[8].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][0] = gButtonInfoTable[1].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][1] = gButtonInfoTable[10].buttonName;
        break;
    case BUTTON_CONFIG_TYPE_C:
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][0] = gButtonInfoTable[9].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][0] = gButtonInfoTable[8].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][0] = gButtonInfoTable[5].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][0] = gButtonInfoTable[0].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][0] = gButtonInfoTable[5].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][1] = gButtonInfoTable[0].buttonName;
        break;
    case BUTTON_CONFIG_TYPE_D:
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][0] = gButtonInfoTable[9].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][0] = gButtonInfoTable[8].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][0] = gButtonInfoTable[5].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][0] = gButtonInfoTable[4].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][1] = gButtonInfoTable[10].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][0] = gButtonInfoTable[6].buttonName;
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][1] = gButtonInfoTable[10].buttonName;
        break;
    case BUTTON_CONFIG_TYPE_EDIT:
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][0]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_LEFT_FLIPPER][0];
        gMain.buttonConfigs[PINBALL_INPUT_LEFT_FLIPPER][1]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_LEFT_FLIPPER][1];
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][0]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_RIGHT_FLIPPER][0];
        gMain.buttonConfigs[PINBALL_INPUT_RIGHT_FLIPPER][1]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_RIGHT_FLIPPER][1];
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][0]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_LEFT][0];
        gMain.buttonConfigs[PINBALL_INPUT_TILT_LEFT][1]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_LEFT][1];
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][0]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_RIGHT][0];
        gMain.buttonConfigs[PINBALL_INPUT_TILT_RIGHT][1]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_RIGHT][1];
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][0]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_UP][0];
        gMain.buttonConfigs[PINBALL_INPUT_TILT_UP][1]
            = gMain_saveData.customButtonConfig[PINBALL_INPUT_TILT_UP][1];
        break;
    }
}
