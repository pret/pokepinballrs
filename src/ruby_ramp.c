#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"
#include "constants/mem_layout/ruby.h"

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
    switch (gCurrentPinballGame->makuhitaState)
    {
    case MAKUHITA_STATE_INACTIVE:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18;
        gCurrentPinballGame->makuhitaAnimCounter++;
        gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        break;
    case MAKUHITA_STATE_NEUTRAL_READY:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaPunchTriggeredFlag)
        {
            gCurrentPinballGame->makuhitaState = MAKUHITA_STATE_LEFT_PUNCH;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }
        gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        break;
    case MAKUHITA_STATE_LEFT_PUNCH:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 9) / 3 + 4;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter == 9)
        {
             gCurrentPinballGame->makuhitaState = MAKUHITA_STATE_READY_FOR_RIGHT_PUNCH;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }
        break;
    case MAKUHITA_STATE_READY_FOR_RIGHT_PUNCH:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter > 65)
        {
            gCurrentPinballGame->makuhitaState = MAKUHITA_STATE_NEUTRAL_READY;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }

        if (gCurrentPinballGame->makuhitaAnimCounter > 6 && gCurrentPinballGame->makuhitaPunchTriggeredFlag)
        {
            gCurrentPinballGame->makuhitaState = MAKUHITA_STATE_RIGHT_PUNCH;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
            gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        }
        break;
    case MAKUHITA_STATE_RIGHT_PUNCH:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 9) / 3 + 7;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter == 9)
        {
            gCurrentPinballGame->makuhitaState = MAKUHITA_STATE_READY_FOR_LEFT_PUNCH;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }
        break;
    case MAKUHITA_STATE_READY_FOR_LEFT_PUNCH:
        index = (gCurrentPinballGame->makuhitaAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->makuhitaAnimCounter++;
        if (gCurrentPinballGame->makuhitaAnimCounter > 65)
        {
            gCurrentPinballGame->makuhitaState = MAKUHITA_STATE_NEUTRAL_READY;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
        }

        if (gCurrentPinballGame->makuhitaAnimCounter > 6 && gCurrentPinballGame->makuhitaPunchTriggeredFlag)
        {
            gCurrentPinballGame->makuhitaState = MAKUHITA_STATE_LEFT_PUNCH;
            gCurrentPinballGame->makuhitaAnimCounter = 0;
            gCurrentPinballGame->makuhitaPunchTriggeredFlag = FALSE;
        }
        break;
    }

    group = &gMain.spriteGroups[SG_RUBY_MAKUHITA_PUNCH_CONTACT_FX];
    if (group->active)
    {
        if (gCurrentPinballGame->makuhitaState < MAKUHITA_STATE_READY_FOR_RIGHT_PUNCH)
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

    if (gCurrentPinballGame->makuhitaState == MAKUHITA_STATE_RIGHT_PUNCH || gCurrentPinballGame->makuhitaState == MAKUHITA_STATE_LEFT_PUNCH)
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
        DmaCopy16(3, gRubyMakuhitaGfx[index], OBJ_VRAM_ADDR_MAKUHITA_TILES, SIZE_OF_VRAM_MAKUHITA_TILES);
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

        DmaCopy16(3, gRubyBoardRampPrize_Gfx[index], OBJ_VRAM_ADDR_RAMP_PRIZE_TILES, SIZE_OF_VRAM_RAMP_PRIZE_TILES);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x =  oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y =  oamSimple->yOffset + group->baseY;
    }
}