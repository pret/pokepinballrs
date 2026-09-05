#include "global.h"
#include "constants/bg_music.h"
#include "constants/ereader.h"
#include "functions.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "titlescreen.h"
#include "variables.h"

extern StateFunc gEReaderStateFuncs[11];
extern s8 gEReaderTextCharIndex;
extern s8 gEReaderTextAnimDelay;
extern s8 gEReaderTextBlinkToggle;
extern s8 gEReaderTextPageIndex;

extern s8 gEReaderStatusAnimSpriteGroup;
extern s8 gEReaderStatusSpriteVisible;
extern s8 gEReaderHeaderAnimSpriteGroup;
extern s8 gEReaderTransitionStep;
extern s16 gEReaderTransitionTimer;
extern s16 gEReaderGeneralTimer;
extern u8 gEReaderUnused1;
extern u8 gEReaderUnused2;
extern s8 gEReaderExitTargetState;
extern u8 gLinkExchangeStep;
extern u32 gLinkStatusResult;
extern s16 gLinkSendBuffer[];
extern u16 gLinkRecvBuffer[][2];
extern u32 gLinkConnectionState;
extern u8 gLinkPlayerCount;
extern u8 gLinkNegotiationFlags;
extern s16 gEReaderCardIndex;
extern s16 gLinkTimeoutCounter;

extern s8 gEReaderTextLengths[10];
extern s8 gEReaderTextHasNextPage[10];
extern u8 gEReaderCardStartPages[NUM_EREADER_CARDS + 1];
extern u8 gPokedexSprites_Gfx[];
extern const Palette gEReaderBackground_Pals[];
extern u8 gEReaderText_Tilemap[];
// extern u8 gUnknown_0807D000[]; // dead declaration, never referenced
extern u16 gTempGfxBuffer[];
extern u8 gEReaderBackground_Gfx[];
extern u8 gEReaderOverlay_Tilemap[];
extern s16 gEReaderTransitionStepDurations[];

enum EReaderState{
    EREADER_STATE_LOAD_GRAPHICS = 0,
    EREADER_STATE_SHOW_INSTRUCTIONS = 1,
    EREADER_STATE_ANIMATE_LINK_CABLE = 2,
    EREADER_STATE_COMMUNICATION = 3,
    EREADER_STATE_LINK_TIMEOUT = 4,
    EREADER_STATE_LINK_SUCCESS_CLOSING = 5,
    EREADER_STATE_SUCCESS_POPUP = 6,
    EREADER_STATE_PRIZE_TEXT = 7,
    EREADER_STATE_RETURN_TO_MENU = 8,
};

void EReaderMain(void)
{
    gEReaderStateFuncs[gMain.subState]();
}

void LoadEReaderGraphics(void)
{
    ResetDisplayState();
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK;
    REG_BG0CNT = BGCNT_CHARBASE(1);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;

    gMain.bgOffsets[0].xOffset = 0xffe8;
    gMain.bgOffsets[0].yOffset = (0xffe8 - 0x48);
    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gEReaderBackground_Pals,    BG_PLTT_SLOT(PAL_IX_0), 2*PLTT_SLOT_SIZE);
    DmaCopy16(3, gPokedexBackground_Pals[4], BG_PLTT_SLOT(PAL_IX_2), PLTT_SLOT_SIZE);
    DmaCopy16(3, gEReaderBackground_Gfx,   gTempGfxBuffer,         6*BG_SCREEN_SIZE);
    DmaCopy16(3, gEReaderText_Tilemap,    BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gEReaderOverlay_Tilemap, BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexSprites_Pals,  OBJ_PLTT_SLOT(PAL_IX_0), 6*PLTT_SLOT_SIZE);
    DmaCopy16(3, gPokedexSprites_Gfx,   OBJ_VRAM0,         0x6C20);

    InitEReaderTextState();
    gEReaderTextCharIndex = 0;
    gEReaderTextAnimDelay = 0;
    gEReaderTextBlinkToggle = 0;
    gEReaderTextPageIndex = 0;
    ClearEReaderTextRows();

    DmaCopy16(3, gTempGfxBuffer, BG_CHAR_ADDR(1), 6*BG_SCREEN_SIZE);

    UpdateEReaderSprites();
    m4aSongNumStart(MUS_EREADER);
    EnableVBlankInterrupts();
    FadeInScreen();
    gMain.subState = EREADER_STATE_SHOW_INSTRUCTIONS;
}

void InitEReaderTextState(void)
{
    gEReaderStatusAnimSpriteGroup = SG_EREADER_START_TRANSMISSION_POPUP;
    gEReaderStatusSpriteVisible = FALSE;
    gEReaderHeaderAnimSpriteGroup = SG_EREADER_GBA_LINK_BASE;
    gEReaderTransitionStep = 0;
    gEReaderTransitionTimer = 0;
    gEReaderGeneralTimer = 0;
    gEReaderExitTargetState = STATE_INTRO;
    gEReaderUnused1 = 0;
    gEReaderUnused2 = 0;
}

void Ereader_ShowInstructions(void)
{
    if (gEReaderTextCharIndex <= gEReaderTextLengths[gEReaderTextPageIndex]) {
        gEReaderTextAnimDelay++;
        if (2 < gEReaderTextAnimDelay) {
            gEReaderTextAnimDelay = 0;
            DrawEReaderTextCharacter(gEReaderTextPageIndex,gEReaderTextCharIndex);
            gEReaderTextCharIndex++;
        }
    }
    else {
        gEReaderTextAnimDelay++;
        if (6 < gEReaderTextAnimDelay) {
            gEReaderTextAnimDelay = 0;
            if (gEReaderTextBlinkToggle == 0) {
                BlinkEReaderTextCursor(gEReaderTextLengths[gEReaderTextPageIndex],0x3a80);
            }
            else {
                BlinkEReaderTextCursor(gEReaderTextLengths[gEReaderTextPageIndex],0);
            }
            gEReaderTextBlinkToggle = 1 - gEReaderTextBlinkToggle;
        }
    }
    if (JOY_NEW(A_BUTTON)) {
        if (gEReaderTextCharIndex <= gEReaderTextLengths[gEReaderTextPageIndex]) {
            DrawEReaderTextPage(gEReaderTextPageIndex);
            gEReaderTextCharIndex = gEReaderTextLengths[gEReaderTextPageIndex] + 1;
        }
        else if (gEReaderTextHasNextPage[gEReaderTextPageIndex] == 0) {
            gMain.subState = EREADER_STATE_ANIMATE_LINK_CABLE;
        }
        else {
            ClearEReaderTextRows();
            gEReaderTextCharIndex = 0;
            gEReaderTextAnimDelay = 0;
            gEReaderTextBlinkToggle = 0;
            gEReaderTextPageIndex++;
        }
    }
    else if (JOY_NEW(B_BUTTON)) {
        m4aSongNumStart(SE_MENU_CANCEL);
        gEReaderExitTargetState = STATE_TITLE;
        gMain.subState = EREADER_STATE_RETURN_TO_MENU;
    }
    UpdateEReaderSprites();
    DmaCopy16(3, gTempGfxBuffer, BG_CHAR_ADDR(1), 6*BG_SCREEN_SIZE);
}

void Ereader_AnimateLinkCable(void)
{
    gEReaderTransitionTimer++;
    if (gEReaderTransitionTimer > gEReaderTransitionStepDurations[gEReaderTransitionStep]) {
        gEReaderTransitionTimer = 0;
        gEReaderTransitionStep++;
        if (gEReaderTransitionStep == 6) {
            InitLinkHardware();
            InitEReaderLinkBuffers();
            gLinkExchangeStep = 0;
            gEReaderStatusSpriteVisible = TRUE;
            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
            gMain.subState = EREADER_STATE_COMMUNICATION;
        }
    }
    gEReaderStatusAnimSpriteGroup = SG_EREADER_START_TRANSMISSION_POPUP;
    gEReaderHeaderAnimSpriteGroup = SG_EREADER_GBA_LINK_BASE + gEReaderTransitionStep;
    UpdateEReaderSpritesViaOam();
}

void Ereader_Communicating(void)
{
    s32 index;

    UpdateEReaderSpritesViaOam();
    if (JOY_NEW(B_BUTTON)) {
        ResetSerialAndInterrupts();
        DisableSerial();
        FadeOutScreen();
        m4aMPlayAllStop();
        DisableVBlankInterrupts();
        gMain.subState = 0;
    }
    gLinkStatusResult = LinkMain1(&gLinkAdvanceState, gLinkSendBuffer, gLinkRecvBuffer);
    gLinkConnectionState = gLinkStatusResult & 3;
    gLinkPlayerCount = ((gLinkStatusResult & 0x1c) >> 2);
    gLinkNegotiationFlags = ((gLinkStatusResult & 0xe00) >> 9);
    if (((gLinkStatusResult & 0x40) != 0) && (gLinkConnectionState < 2)) {
        PrepareEReaderLinkSendCmd();
        if (((gLinkStatusResult & 0x100) == 0) && (ProcessEReaderLinkReceive() == -1)) {
            gEReaderCardIndex = GetEReaderCardIndex();
            if ((gEReaderCardIndex != -1) && (NUM_EREADER_CARDS > gEReaderCardIndex)) {
                for(index = 0; index < NUM_EREADER_CARDS; index++)
                {
                    gMain.eReaderBonuses[index] = FALSE;
                }
                gMain.eReaderBonuses[gEReaderCardIndex] = TRUE;
                gEReaderGeneralTimer = 0;
                gMain.subState = EREADER_STATE_LINK_SUCCESS_CLOSING;
            }
            else {
                gEReaderGeneralTimer = 0;
                gEReaderStatusAnimSpriteGroup = SG_EREADER_TRANSMIT_ERROR;
                gEReaderHeaderAnimSpriteGroup = SG_EREADER_GBA_LINK_CONNECTED;
                gEReaderTextCharIndex = 0;
                gEReaderTextBlinkToggle = 0;
                gEReaderTextPageIndex = 13;
                ClearEReaderTextRows();
                gMain.subState = EREADER_STATE_LINK_TIMEOUT;
                m4aSongNumStart(SE_FAILURE);
            }
        }
        if (gEReaderStatusAnimSpriteGroup == SG_EREADER_TRANSMITTING) {
            gEReaderGeneralTimer++;
            if (gEReaderGeneralTimer % 8 == 0) {
                gEReaderHeaderAnimSpriteGroup = SG_21 - gEReaderHeaderAnimSpriteGroup;
            }
            if (((gLinkStatusResult & 0x7f0000) != 0) &&
                (gLinkTimeoutCounter++, 0xb4 < gLinkTimeoutCounter)) {
                gEReaderGeneralTimer = 0;
                gEReaderStatusAnimSpriteGroup = SG_EREADER_TRANSMIT_ERROR;
                gEReaderHeaderAnimSpriteGroup = SG_EREADER_GBA_LINK_CONNECTED;
                gEReaderTextCharIndex = 0;
                gEReaderTextBlinkToggle = 0;
                gEReaderTextPageIndex = 13;
                ClearEReaderTextRows();
                gMain.subState = EREADER_STATE_LINK_TIMEOUT;
                m4aSongNumStart(SE_FAILURE);
            }
        }
    }
}

void Ereader_ShowLinkTimeout(void)
{
    gEReaderGeneralTimer++;
    if (8 < gEReaderGeneralTimer) {
        gEReaderGeneralTimer = 0;
        gEReaderHeaderAnimSpriteGroup = SG_22 - gEReaderHeaderAnimSpriteGroup;
    }
    if (gEReaderTextCharIndex <= gEReaderTextLengths[gEReaderTextPageIndex]) {
        gEReaderTextAnimDelay++;
        if (2 < gEReaderTextAnimDelay) {
            gEReaderTextAnimDelay = 0;
            DrawEReaderTextCharacter(gEReaderTextPageIndex,gEReaderTextCharIndex);
            gEReaderTextCharIndex++;
        }
    }
    else {
        gEReaderTextAnimDelay++;
        if (6 < gEReaderTextAnimDelay) {
            gEReaderTextAnimDelay = 0;
            if (gEReaderTextBlinkToggle == 0) {
                BlinkEReaderTextCursor(gEReaderTextLengths[gEReaderTextPageIndex],0x3a80);
            }
            else {
                BlinkEReaderTextCursor(gEReaderTextLengths[gEReaderTextPageIndex],0);
            }
            gEReaderTextBlinkToggle = 1 - gEReaderTextBlinkToggle;
        }
    }
    if (JOY_NEW(A_BUTTON)) {
        if (gEReaderTextCharIndex <= gEReaderTextLengths[gEReaderTextPageIndex]) {
            DrawEReaderTextPage(gEReaderTextPageIndex);
            gEReaderTextCharIndex = gEReaderTextLengths[gEReaderTextPageIndex] + 1;
        }
        else if (gEReaderTextHasNextPage[gEReaderTextPageIndex] == 0) {
            ResetSerialAndInterrupts();
            DisableSerial();
            FadeOutScreen();
            m4aMPlayAllStop();
            DisableVBlankInterrupts();
            gMain.subState = 0;
        }
        else {
            ClearEReaderTextRows();
            gEReaderTextCharIndex = 0;
            gEReaderTextAnimDelay = 0;
            gEReaderTextBlinkToggle = 0;
            gEReaderTextPageIndex++;
        }
    }
    UpdateEReaderSprites();
    DmaCopy16(3, gTempGfxBuffer, BG_CHAR_ADDR(1), 6*BG_SCREEN_SIZE);
}

void Ereader_CloseSuccessfulTransmission(void)
{
    u16 temp;
    UpdateEReaderSpritesViaOam();

    switch (gEReaderGeneralTimer)
    {
        case 4:
            ResetSerialAndInterrupts();
            DisableSerial();
            break;
        case 0x96:
            gEReaderStatusAnimSpriteGroup = SG_EREADER_TRANSMISSION_COMPLETE;
            m4aSongNumStart(SE_MENU_SELECT);
            break;
        case 0x10e:
            gEReaderGeneralTimer = 0;
            FadeOutScreen();
            m4aMPlayAllStop();
            DisableVBlankInterrupts();
            gMain.subState = EREADER_STATE_SUCCESS_POPUP;
            break;
    }

    if ((gEReaderStatusAnimSpriteGroup == SG_EREADER_TRANSMITTING) && ((temp = gEReaderGeneralTimer, gEReaderGeneralTimer & 7) == 0)) {
        gEReaderHeaderAnimSpriteGroup = SG_21 - gEReaderHeaderAnimSpriteGroup;
    }
    gEReaderGeneralTimer++;
}

void Ereader_ShowSuccessPopup(void)
{
    ResetDisplayState();
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK;
    REG_BG0CNT = BGCNT_CHARBASE(1);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;

    gMain.bgOffsets[0].xOffset = 0xffe8;
    gMain.bgOffsets[0].yOffset = (0xffe8 - 0x48);
    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gEReaderBackground_Pals,    BG_PLTT_SLOT(PAL_IX_0),   2*PLTT_SLOT_SIZE);
    DmaCopy16(3, gPokedexBackground_Pals[4], BG_PLTT_SLOT(PAL_IX_2),   PLTT_SLOT_SIZE);
    DmaCopy16(3, gEReaderBackground_Gfx,     gTempGfxBuffer,    6*BG_SCREEN_SIZE);
    DmaCopy16(3, gEReaderText_Tilemap,       BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    DmaCopy16(3, gEReaderOverlay_Tilemap,    BG_SCREEN_ADDR(1), BG_SCREEN_SIZE);
    DmaCopy16(3, gPokedexSprites_Pals,       OBJ_PLTT_SLOT(PAL_IX_0),  6*PLTT_SLOT_SIZE);
    DmaCopy16(3, gPokedexSprites_Gfx,        OBJ_VRAM0,         0x6C20);

    InitEReaderTextState();
    gEReaderTextCharIndex = 0;
    gEReaderTextAnimDelay = 0;
    gEReaderTextBlinkToggle = 0;
    gEReaderTextPageIndex = gEReaderCardStartPages[gEReaderCardIndex];
    ClearEReaderTextRows();

    DmaCopy16(3, gTempGfxBuffer, BG_CHAR_ADDR(1), 6*BG_SCREEN_SIZE);

    UpdateEReaderSprites();
    m4aSongNumStart(MUS_EREADER);
    EnableVBlankInterrupts();
    FadeInScreen();
    gMain.subState = EREADER_STATE_PRIZE_TEXT;
}

void Ereader_ShowPrizeText(void)
{
    if (gEReaderTextCharIndex <= gEReaderTextLengths[gEReaderTextPageIndex]) {
        gEReaderTextAnimDelay++;
        if (2 < gEReaderTextAnimDelay) {
            gEReaderTextAnimDelay = 0;
            DrawEReaderTextCharacter(gEReaderTextPageIndex, gEReaderTextCharIndex);
            gEReaderTextCharIndex++;
        }
    }
    else {
        gEReaderTextAnimDelay++;
        if (6 < gEReaderTextAnimDelay) {
            gEReaderTextAnimDelay = 0;
            if (gEReaderTextBlinkToggle == 0) {
                BlinkEReaderTextCursor(gEReaderTextLengths[gEReaderTextPageIndex], 0x3a80);
            }
            else {
                BlinkEReaderTextCursor(gEReaderTextLengths[gEReaderTextPageIndex], 0);
            }
            gEReaderTextBlinkToggle = 1 - gEReaderTextBlinkToggle;
        }
    }
    if (JOY_NEW(A_BUTTON)) {
        if (gEReaderTextCharIndex <= gEReaderTextLengths[gEReaderTextPageIndex]) {
            DrawEReaderTextPage(gEReaderTextPageIndex);
            gEReaderTextCharIndex = gEReaderTextLengths[gEReaderTextPageIndex] + 1;
        }
        else if (gEReaderTextHasNextPage[gEReaderTextPageIndex] == 0) {
            if (gEReaderCardIndex == EREADER_BONUS_STAGE_CARD) {
                gEReaderExitTargetState = STATE_BONUS_FIELD_SELECT;
            }
            else {
                gEReaderExitTargetState = STATE_TITLE;
            }
            gMain.subState = EREADER_STATE_RETURN_TO_MENU;
        }
        else {
            ClearEReaderTextRows();
            gEReaderTextCharIndex = 0;
            gEReaderTextAnimDelay = 0;
            gEReaderTextBlinkToggle = 0;
            gEReaderTextPageIndex++;
        }
    }
    UpdateEReaderSprites();
    DmaCopy16(3, gTempGfxBuffer, BG_CHAR_ADDR(1), 6*BG_SCREEN_SIZE);
}

void Ereader_FadeScreenToMenu(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(gEReaderExitTargetState);
}

void ClearEReaderTextRows(void)
{
    s32 iVar2;
    s32 iVar4;

    for(iVar2 = 0; iVar2 < 3; iVar2++)
    {
        for(iVar4 = 0; iVar4 < 0x18; iVar4++)
        {
            CopyBgTilesRect(gEReaderText_Gfx, &gEReaderTextTileBuffer[iVar2][iVar4*0x20], 1, 2);
        }
    }
}

void DrawEReaderTextPage(s8 arg0)
{
    s32 iVar4;
    s32 iVar3;

    for (iVar4 = 0; iVar4 < 3; iVar4++)
    {
        for (iVar3 = 0; iVar3 < 0x18; iVar3++)
        {
            CopyBgTilesRect(gEReaderText_Gfx + (gEReaderTextGlyphTable[arg0][iVar4*0x18 + iVar3] & 0xFFF0), &gEReaderTextTileBuffer[iVar4][iVar3*0x20], 1, 2);
        }
    }
}

void DrawEReaderTextCharacter(s8 arg0, s8 arg1)
{
    s32 quotient = arg1 / 0x18;
    s32 remainder = arg1 % 0x18;

    CopyBgTilesRect(gEReaderText_Gfx + (gEReaderTextGlyphTable[arg0][quotient*0x18 + remainder] & 0xFFF0), &gEReaderTextTileBuffer[quotient][remainder*0x20], 1, 2);
}

void BlinkEReaderTextCursor(s8 arg0, u16 arg1)
{
    s32 quotient = arg0 / 0x18;
    s32 remainder = arg0 % 0x18;

    CopyBgTilesRect(gEReaderText_Gfx + arg1, &gEReaderTextTileBuffer[quotient][remainder*0x20], 1, 2);
}

s16 GetEReaderCardIndex(void)
{
    s32 uVar1;

    if (gEReaderReceivedCardId == 0x1f52)
    {
        return EREADER_SPECIAL_GUESTS_CARD;
    }
    else if (gEReaderReceivedCardId == 0x3e1a)
    {
        return EREADER_ENCOUNTER_RATE_UP_CARD;
    }
    else if (gEReaderReceivedCardId == 0x25af)
    {
        return EREADER_DX_MODE_CARD;
    }
    else if (gEReaderReceivedCardId == 0x4a09)
    {
        return EREADER_RUIN_AREA_CARD;
    }
    else if (gEReaderReceivedCardId == 0x6b12)
    {
        return EREADER_BONUS_STAGE_CARD;
    }
    else
    {
        return -1;
    }
}

void UpdateEReaderSprites(void)
{
    struct SpriteGroup *puVar9;
    struct SpriteGroup *puVar5;
    s32 iVar7;
    const struct SpriteSet *puVar8;
    struct OamDataSimple *test2;

    puVar9 = &gMain.spriteGroups[gEReaderStatusAnimSpriteGroup];
    puVar5 = &gMain.spriteGroups[gEReaderHeaderAnimSpriteGroup];
    puVar9->active = gEReaderStatusSpriteVisible;
    puVar5->active = TRUE;
    LoadSpriteSets(gEReaderSpriteSets, 13, gMain.spriteGroups);

    if (puVar9->active == TRUE)
    {
        if (gEReaderStatusAnimSpriteGroup == SG_EREADER_START_TRANSMISSION_POPUP)
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 100;
        }
        else
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 0x50;
        }

        puVar8 = gEReaderSpriteSets[gEReaderStatusAnimSpriteGroup];

        for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
        {
            test2 = &puVar9->oam[iVar7];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar9->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar9->baseY;
        }
    }

    puVar5->baseX = 0x78;
    puVar5->baseY = 0x18;
    puVar8 = gEReaderSpriteSets[gEReaderHeaderAnimSpriteGroup];

    for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
    {
        test2 = &puVar5->oam[iVar7];
        gOamBuffer[test2->oamId].x = test2->xOffset + puVar5->baseX;
        gOamBuffer[test2->oamId].y = test2->yOffset + puVar5->baseY;
    }

    puVar9->active = FALSE;
    puVar5->active = FALSE;
}

void UpdateEReaderSpritesViaOam(void) {
    struct SpriteGroup *puVar9;
    struct SpriteGroup *puVar5;
    s32 iVar7;
    const struct SpriteSet *puVar8;
    struct OamDataSimple *test2;

    puVar9 = &gMain.spriteGroups[gEReaderStatusAnimSpriteGroup];
    puVar5 = &gMain.spriteGroups[gEReaderHeaderAnimSpriteGroup];
    puVar9->active = gEReaderStatusSpriteVisible;
    puVar5->active = TRUE;
    LoadSpriteSetsWithCpuCopy(gEReaderSpriteSets, 13, gMain.spriteGroups);

    if (puVar9->active == TRUE)
    {
        if (gEReaderStatusAnimSpriteGroup == SG_EREADER_START_TRANSMISSION_POPUP)
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 100;
        }
        else
        {
            puVar9->baseX = 0x78;
            puVar9->baseY = 0x50;
        }

        puVar8 = gEReaderSpriteSets[gEReaderStatusAnimSpriteGroup];

        for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
        {
            test2 = &puVar9->oam[iVar7];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar9->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar9->baseY;
        }
    }

    puVar5->baseX = 0x78;
    puVar5->baseY = 0x18;
    puVar8 = gEReaderSpriteSets[gEReaderHeaderAnimSpriteGroup];

    for (iVar7 = 0; iVar7 < puVar8->count; iVar7++)
    {
        test2 = &puVar5->oam[iVar7];
        gOamBuffer[test2->oamId].x = test2->xOffset + puVar5->baseX;
        gOamBuffer[test2->oamId].y = test2->yOffset + puVar5->baseY;
    }

    puVar9->active = FALSE;
    puVar5->active = FALSE;
}

void InitEReaderLinkBuffers(void)
{
    s32 i;
    s32 j;

    gEReaderLinkHandshakeStarted = 0;
    gEReaderLinkDataReceived = 0;
    gEReaderLinkAckSent = 0;

    for (i = 0; i < 0x8; i++)
    {
        gLinkSendBuffer[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 8; j++)
        {
            gLinkRecvBuffer[j][i] = 0;
        }
    }
}

s32 PrepareEReaderLinkSendCmd(void)
{
    s32 i;

    if (gEReaderLinkDataReceived)
    {
        gLinkSendBuffer[0] = 0xDFDF;
    }
    else
    {
        if (gEReaderLinkAckSent == -1)
        {
            gLinkSendBuffer[0] = 0xCDFE;
            gEReaderLinkAckSent = 0;
        }
        else
        {
            for (i = 0; i < 8; i++)
            {
                gLinkSendBuffer[i] = 0;
            }
        }
    }

    return 0;
}

s16 ProcessEReaderLinkReceive(void)
{
    s32 i;
    s32 j;

    if ((JOY_NEW(A_BUTTON)))
    {
        if (gEReaderLinkHandshakeStarted == 0)
        {
            gEReaderLinkHandshakeStarted = -1;
            gEReaderLinkAckSent = -1;
            gEReaderStatusAnimSpriteGroup = SG_EREADER_TRANSMITTING;
        }
    }

    if (gEReaderLinkHandshakeStarted != 0)
    {
        if (gEReaderLinkDataReceived == 0)
        {
            if (gLinkRecvBuffer[0][0] == 0xFEDC)
            {
                gEReaderReceivedCardId = gLinkRecvBuffer[1][0];
                gEReaderLinkDataReceived = -1;
            }
            else if (gLinkRecvBuffer[0][1] == 0xFEDC)
            {
                gEReaderReceivedCardId = gLinkRecvBuffer[1][1];
                gEReaderLinkDataReceived = -1;
            }
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                if (gLinkRecvBuffer[0][i] == 0xDFDF)
                {
                    return -1;
                }
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 8; j++)
        {
            gLinkRecvBuffer[j][i] = 0;
        }
    }
    return 0;
}

