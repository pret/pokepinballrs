#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"

extern const u8 gRubyMakuhitaGfx[][0x300];
extern const u8 gRubyBoardRampPrize_Gfx[][0x80];


void UpdateMakuhitaEntity(void)
{
    s16 i;
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    int x, y;
    int squaredDistance;
    s16 index;

    index = 0;
    switch (gCurrentPinballGame->makuhitaPunchState)
    {
    case 0:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18;
        gCurrentPinballGame->makuhitaAnimCounter++;
        gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        break;
    case 1:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaPunchTriggeredFlag)
        {
            gCurrentPinballGame->makuhitaPunchState = 2;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }
        gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        break;
    case 2:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 9) / 3 + 4;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter == 9)
        {
             gCurrentPinballGame->makuhitaPunchState = 3;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }
        break;
    case 3:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter > 65)
        {
            gCurrentPinballGame->makuhitaPunchState = 1;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }

        if (gCurrentPinballGame->makuhitaAnimCounter > 6 && gCurrentPinballGame->makuhitaPunchTriggeredFlag)
        {
            gCurrentPinballGame->makuhitaPunchState = 4;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
            gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        }
        break;
    case 4:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 9) / 3 + 7;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter == 9)
        {
            gCurrentPinballGame->makuhitaPunchState = 5;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }
        break;
    case 5:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter > 65)
        {
            gCurrentPinballGame->makuhitaPunchState = 1;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }

        if (gCurrentPinballGame->makuhitaAnimCounter > 6 && gCurrentPinballGame->makuhitaPunchTriggeredFlag)
        {
            gCurrentPinballGame->makuhitaPunchState = 2;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
            gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        }
        break;
    }

    group = &gMain.spriteGroups[SG_RUBY_MAKUHITA_PUNCH_CONTACT_FX];
    if (group->active)
    {
        if (gCurrentPinballGame->makuhitaPunchState < 3)
        {
            group->baseX = 188 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 281 - gCurrentPinballGame->cameraYOffset;
        }
        else
        {
            group->baseX = 192 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 278 - gCurrentPinballGame->cameraYOffset;
        }

        if (gCurrentPinballGame->makuhitaHitAnimationTimer > 0)
        {
            gCurrentPinballGame->makuhitaHitAnimationTimer--;
            if (gCurrentPinballGame->makuhitaHitAnimationTimer == 0)
                gMain.spriteGroups[SG_RUBY_MAKUHITA_PUNCH_CONTACT_FX].active = FALSE;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->makuhitaPunchState == 4 || gCurrentPinballGame->makuhitaPunchState == 2)
    {
        x = gCurrentPinballGame->ball->positionQ0.x - 190;
        y = gCurrentPinballGame->ball->positionQ0.y - 285;
        squaredDistance = (x * x) + (y * y);
        if(squaredDistance >= 0 && squaredDistance <= 140)
        {
            if (gCurrentPinballGame->makuhitaHitAnimationTimer <= 0)
            {
                m4aSongNumStart(SE_MAKUHITA_PUNCH);
                gCurrentPinballGame->scoreAddedInFrame = SCORE_MAKUHITA_HIT_BALL;
                gCurrentPinballGame->ball->velocity.x = -600;
                gCurrentPinballGame->ball->velocity.y = -300;
                gCurrentPinballGame->ball->spinSpeed = 0;
                gMain.spriteGroups[SG_RUBY_MAKUHITA_PUNCH_CONTACT_FX].active = TRUE;
                gCurrentPinballGame->makuhitaHitAnimationTimer = 6;
                PlayRumble(8);
            }
        }
    }

    group = &gMain.spriteGroups[SG_RUBY_MAKUHITA];
    if (group->active)
    {
        group->baseX = 184 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 277 - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gRubyMakuhitaGfx[index], (void*) 0x06013580, 0x300);
        for (i = 0; i < 3;i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void DrawRubyRampPrize(void)
{
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    s16 index;

    group = &gMain.spriteGroups[SG_RUBY_RAMP_PRIZE];
    if (group->active)
    {
        if (gCurrentPinballGame->rampPrizeType)
            group->baseY = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 8 - (gCurrentPinballGame->cameraYOffset - 52);
        else
            group->baseY = 180;

        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->rampPrizeType == 1) //1Up
            index = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 8 + 4;
        else
            index = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 8;

        DmaCopy16(3, gRubyBoardRampPrize_Gfx[index], (void *) 0x06014B00, 0x80);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x =  oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y =  oamSimple->yOffset + group->baseY;
    }
}