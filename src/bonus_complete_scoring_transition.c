#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SpriteGroup gMain_spriteGroups_12;
extern struct SpriteGroup gMain_spriteGroups_14;

extern const u8 gKecleonBonusClear_Gfx[];
extern const u8 gKyogreBonusClear_Gfx[];
extern const u8 gGroudonBonusClear_Gfx[];
extern const u8 gRayquazaBonusClear_Gfx[];

void FadeToMainBoard(void)
{
    gCurrentPinballGame->startButtonDisabled = 1;
    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        gCurrentPinballGame->stageTimer = 65;
        gCurrentPinballGame->boardSubState = 1;
        gMain.blendControl = 0x9F;
        break;
    case 1:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->stageTimer / 4;
            if (gCurrentPinballGame->stageTimer == 0)
                gCurrentPinballGame->boardSubState++;
        }
        break;
    case 2:
        if (gCurrentPinballGame->stageTimer < 30)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardSubState = 0;
            gMain.spriteGroups[6].available = 0;
            gMain.spriteGroups[5].available = 0;
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
    group = &gMain.spriteGroups[6];
    if (gCurrentPinballGame->bannerSlideYOffset > 0)
    {
        gCurrentPinballGame->bannerSlideYOffset -= 6;
        if (gCurrentPinballGame->bannerSlideYOffset < 0)
            gCurrentPinballGame->bannerSlideYOffset = 0;
    }

    switch (gMain.selectedField)
    {
    case FIELD_DUSCLOPS:
        if (gCurrentPinballGame->boardState == 5 && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = 30000000;
        break;
    case FIELD_KECLEON:
        if (gCurrentPinballGame->boardState == 3 && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = 30000000;
        break;
    case FIELD_KYOGRE:
        if (gCurrentPinballGame->boardState == 3 && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = 50000000;
        break;
    case FIELD_GROUDON:
        if (gCurrentPinballGame->boardState == 3 && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = 50000000;
        break;
    case FIELD_RAYQUAZA:
        if (gCurrentPinballGame->boardState == 3 && gCurrentPinballGame->stageTimer < 180)
            var0 = (gCurrentPinballGame->stageTimer % 24) / 12 + 8;
        var1 = 99999999;
        break;
    }

    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + var0 * 0x20, (void *)0x05000300, 0x20);

    if (group->available)
    {
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->bannerSlideYOffset + 50;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[5];
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->bannerSlideYOffset + 50;
        for (i = 0; i < 18; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    sp0[0] = (var1 / 10000000);
    sp0[1] = (var1 % 10000000) / 1000000;
    sp0[2] = (var1 % 1000000) / 100000;
    sp0[3] = (var1 % 100000) / 10000;
    sp0[4] = (var1 % 10000) / 1000;
    sp0[5] = (var1 % 1000) / 100;
    sp0[6] = (var1 % 100) / 10;
    sp0[7] = (var1 % 10);

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

void RenderBonusStageOverlaySprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain_spriteGroups_14;
    switch (gCurrentPinballGame->bossEntityState)
    {
    case 0:
    case 1:
    case 8:
        if (!group->available)
            break;

        group->baseX = 240;
        group->baseY = 160;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 240;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case 2:
        if (gCurrentPinballGame->bossAnimLoopCount <= 0)
            break;

        if (!group->available)
            break;

        group->baseX = 240;
        group->baseY = 160;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 240;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }

    group = &gMain_spriteGroups_12;
    if (!group->available)
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
    gMain.isBonusField = 0;
    gMain.modeChangeFlags = MODE_CHANGE_NONE;
    gCurrentPinballGame->eventTimer = 0;
    gCurrentPinballGame->boardModeType = 0;
    if (gCurrentPinballGame->numCompletedBonusStages > 4)
        gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD] = 1;

    gMain.subState = 0;
    gCurrentPinballGame->prevBoardState = 3;
    gCurrentPinballGame->boardState = 1;
    gCurrentPinballGame->boardTransitionPhase = 0;
    gCurrentPinballGame->boardEntityActive = 0;
    gCurrentPinballGame->cameraYAdjust = 0;
    LoadPortraitGraphics(0, 0);
    gCurrentPinballGame->portraitDisplayState = 0;
    if (gCurrentPinballGame->allHolesLit)
        gCurrentPinballGame->allHolesLitDelayTimer = 120;
}
