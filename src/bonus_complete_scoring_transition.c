#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"
#include "constants/board/groudon_states.h"
#include "constants/board/dusclops_states.h"
#include "constants/board/kecleon_states.h"
#include "constants/board/kyogre_states.h"
#include "constants/board/rayquaza_states.h"

extern const u8 gKecleonBonusClear_Gfx[];
extern const u8 gKyogreBonusClear_Gfx[];
extern const u8 gGroudonBonusClear_Gfx[];
extern const u8 gRayquazaBonusClear_Gfx[];

void FadeToMainBoard(void)
{
    gCurrentPinballGame->startButtonDisabled = TRUE;
    switch (gCurrentPinballGame->boardSubState)
    {
    case BONUS_BOARD_SUBSTATE_ACTIVE:
        gCurrentPinballGame->stageTimer = 65;
        gCurrentPinballGame->boardSubState = BONUS_BOARD_SUBSTATE_FADETRANSITION;
        gMain.blendControl = 0x9F;
        break;
    case BONUS_BOARD_SUBSTATE_FADETRANSITION:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->stageTimer / 4;
            if (gCurrentPinballGame->stageTimer == 0)
                gCurrentPinballGame->boardSubState++;
        }
        break;
    case BONUS_BOARD_SUBSTATE_TRANSFER_TO_MAIN_BOARD:
        if (gCurrentPinballGame->stageTimer < 30)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
            gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER].active = FALSE;
            gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER_SCORE].active = FALSE;
            if (gMain.tempField != gMain.selectedField)
            {
                TransitionFromBonusToMainBoard();
            }
            else
            {
                ResetDisplayState();
                gCurrentPinballGame->fadeSubState = 2;
            }
        }
        break;
    }
}

void ProcessBonusBannerAndScoring(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    int var1;
    s16 sp0[8];
    s16 var2;

    var0 = 8;
    var1 = 0;
    group = &gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER];
    if (gCurrentPinballGame->bannerSlideYOffset > 0)
    {
        gCurrentPinballGame->bannerSlideYOffset -= 6;
        if (gCurrentPinballGame->bannerSlideYOffset < 0)
            gCurrentPinballGame->bannerSlideYOffset = 0;
    }

    switch (gMain.selectedField)
    {
    case FIELD_DUSCLOPS:
        if (gCurrentPinballGame->boardState == DUSCLOPS_BOARD_STATE_SCORE_PHASE
            && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = SCORE_DUSCLOPS_BONUS_COMPLETE;
        break;
    case FIELD_KECLEON:
        if (gCurrentPinballGame->boardState == KECLEON_BOARD_STATE_SCORING && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = SCORE_KECLEON_BONUS_COMPLETE;
        break;
    case FIELD_KYOGRE:
        if (gCurrentPinballGame->boardState == LEGENDARY_BOARD_STATE_SUCCESS_SCORING && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = SCORE_KYOGRE_BONUS_COMPLETE;
        break;
    case FIELD_GROUDON:
        if (gCurrentPinballGame->boardState == LEGENDARY_BOARD_STATE_SUCCESS_SCORING
            && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = SCORE_GROUDON_BONUS_COMPLETE;
        break;
    case FIELD_RAYQUAZA:
        if (gCurrentPinballGame->boardState == LEGENDARY_BOARD_STATE_SUCCESS_SCORING && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = SCORE_RAYQUAZA_BONUS_COMPLETE;
        break;
    }

    DmaCopy16(3,
        gBoardConfig.fieldLayout.objPaletteSets[LIGHTING_PAL_IX_NORMAL][var0],
        OBJ_PLTT_SLOT(PAL_IX_8),
        PLTT_SLOT_SIZE);

    if (group->active)
    {
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->bannerSlideYOffset + 50;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER_SCORE];
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->bannerSlideYOffset + 50;
        for (i = 0; i < 18; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    sp0[0] = LEAD_DIGIT_10M(var1);
    sp0[1] = DIGIT_1M(var1);
    sp0[2] = DIGIT_100K(var1);
    sp0[3] = DIGIT_10K(var1);
    sp0[4] = DIGIT_1K(var1);
    sp0[5] = DIGIT_100S(var1);
    sp0[6] = DIGIT_10S(var1);
    sp0[7] = DIGIT_1S(var1);;

    switch (gMain.selectedField)
    {
    case FIELD_DUSCLOPS:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gDusclopsBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gDusclopsBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_KECLEON:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gKecleonBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gKecleonBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_KYOGRE:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gKyogreBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gKyogreBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_GROUDON:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gGroudonBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gGroudonBonusClear_Gfx[var2* 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_RAYQUAZA:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gRayquazaBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gRayquazaBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    }
}

void HideDusclopsSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[SG_DUSCLOPS_ENTITY];
    switch (gCurrentPinballGame->bossEntityState)
    {
    case DUSCLOPS_ENTITY_STATE_INIT:
    case DUSCLOPS_ENTITY_STATE_INTRO_APPEARANCE:
    case DUSCLOPS_ENTITY_STATE_VANISH:
        if (!group->active)
            break;

        group->baseX = 240;
        group->baseY = 160;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case DUSCLOPS_ENTITY_STATE_GUARD_READY:
        if (gCurrentPinballGame->bossAnimLoopCount <= 0)
            break;

        if (!group->active)
            break;

        group->baseX = 240;
        group->baseY = 160;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case DUSCLOPS_ENTITY_STATE_WALKING:
    case DUSCLOPS_ENTITY_STATE_HIT:
    case DUSCLOPS_ENTITY_STATE_HIT_STUN:
    case DUSCLOPS_ENTITY_STATE_HIT_ABSORB_ZONE:
    case DUSCLOPS_ENTITY_STATE_ABSORBED_BALL:
        break;
    }

    group = &gMain.spriteGroups[SG_DUSCLOPS_PHASING_FX];
    if (!group->active)
        return;

    group->baseX = 240;
    group->baseY = 160;

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void TransitionFromBonusToMainBoard(void)
{
    u8 temp;

    m4aMPlayAllStop();
    DisableVBlankInterrupts();

    temp = gMain.tempField;
    gMain.tempField = gMain.selectedField;
    gMain.selectedField = temp;
    gMain.isBonusField = FALSE;
    gMain.modeChangeFlags = MODE_CHANGE_NONE;
    gCurrentPinballGame->eventTimer = 0;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_NONE;
    if (gCurrentPinballGame->numCompletedBonusStages > 4)
        gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD] = TRUE;

    gMain.subState = 0;
    gCurrentPinballGame->prevBoardState = MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE;
    gCurrentPinballGame->boardState = MAIN_BOARD_STATE_DEFAULT;
    gCurrentPinballGame->boardTransitionPhase = BOARD_STATE_DISPATCHER_STATE_INIT;
    gCurrentPinballGame->cameraLocked = FALSE;
    gCurrentPinballGame->cameraYAdjust = 0;
    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION,
        PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
    if (gCurrentPinballGame->allHolesLit)
        gCurrentPinballGame->allHolesLitDelayTimer = 120;
}
