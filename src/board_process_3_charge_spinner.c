#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SongHeader se_unk_7a;
extern struct SongHeader se_unk_79;

void UpdatePikachuChargeCounter(void)
{
    if (gCurrentPinballGame->pikaChargeTarget != gCurrentPinballGame->pikaChargeProgress)
    {
        gCurrentPinballGame->pikaChargeProgress += 2;
        gCurrentPinballGame->catchCounterValue = gCurrentPinballGame->pikaChargeProgress / 14;
        gCurrentPinballGame->catchCounterSlideTimer = 80;
        gCurrentPinballGame->catchCounterAnimState = 256;
        gCurrentPinballGame->catchCounterScaleY = 256;
        if (gCurrentPinballGame->catchCounterValue == 11)
            gCurrentPinballGame->pikachuAnimTimer = 120;

        if (gCurrentPinballGame->catchCounterValue > 11)
        {
            gCurrentPinballGame->catchCounterValue = 12;
            gCurrentPinballGame->catchCounterSlideTimer = 120;
            gCurrentPinballGame->catchCounterAnimState = 256;
            gCurrentPinballGame->catchCounterScaleY = 256;
        }

        if (gCurrentPinballGame->pikaChargeProgress < 168 && gCurrentPinballGame->pikaChargeProgress % 8 == 0)
        {
            s8 offset = gCurrentPinballGame->pikaChargeProgress / 21;
            m4aSongNumStart(SE_PIKA_CHARGE_DO + offset);
        }

        if (gCurrentPinballGame->pikaChargeTarget <= gCurrentPinballGame->pikaChargeProgress)
        {
            gCurrentPinballGame->pikaChargeProgress = gCurrentPinballGame->pikaChargeTarget;
            if (gCurrentPinballGame->pikaChargeProgress >= 168)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_7a);
                gCurrentPinballGame->scoreAddedInFrame = 3000;
            }
        }
    }

    if (gCurrentPinballGame->pikaSpinCooldownTimer)
        gCurrentPinballGame->pikaSpinCooldownTimer--;

    if (gCurrentPinballGame->pikaSpinMomentum > 0)
    {
        gCurrentPinballGame->pikaSpinMomentum -= 3;
        if (gCurrentPinballGame->pikaSpinMomentum < 0)
            gCurrentPinballGame->pikaSpinMomentum = 0;

        if (gCurrentPinballGame->pikaSpinFrameCounter < gCurrentPinballGame->pikaSpinPeriod - 1)
        {
            gCurrentPinballGame->pikaSpinFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->pikaSpinFrameCounter = 0;
            MPlayStart(&gMPlayInfo_SE3, &se_unk_79);
            gCurrentPinballGame->scoreAddedInFrame = 100;
            if (gCurrentPinballGame->catchCounterValue < 12 && gCurrentPinballGame->entityOverlayCollisionState == 0)
            {
                gCurrentPinballGame->catchCounterSlideTimer = 80;
                gCurrentPinballGame->catchCounterAnimState = 256;
                gCurrentPinballGame->catchCounterScaleY = 256;
            }
        }

        gCurrentPinballGame->pikaSpinPeriod = (450 - gCurrentPinballGame->pikaSpinMomentum) / 10;
        if (gCurrentPinballGame->pikaSpinPeriod < 5)
            gCurrentPinballGame->pikaSpinPeriod = 5;

        gCurrentPinballGame->pikachuSpinFrame = (gCurrentPinballGame->pikaSpinFrameCounter * 16) / gCurrentPinballGame->pikaSpinPeriod;
    }
    else
    {
        if (gCurrentPinballGame->pikaSpinMomentum < 0)
        {
            gCurrentPinballGame->pikaSpinMomentum += 3;
            if (gCurrentPinballGame->pikaSpinMomentum > 0)
                gCurrentPinballGame->pikaSpinMomentum = 0;

            if (gCurrentPinballGame->pikaSpinFrameCounter < gCurrentPinballGame->pikaSpinPeriod - 1)
            {
                gCurrentPinballGame->pikaSpinFrameCounter++;
            }
            else
            {
                gCurrentPinballGame->pikaSpinFrameCounter = 0;
                MPlayStart(&gMPlayInfo_SE3, &se_unk_79);
                gCurrentPinballGame->scoreAddedInFrame = 100;
                if (gCurrentPinballGame->catchCounterValue < 12 && gCurrentPinballGame->entityOverlayCollisionState == 0)
                {
                    gCurrentPinballGame->catchCounterSlideTimer = 80;
                    gCurrentPinballGame->catchCounterAnimState = 256;
                    gCurrentPinballGame->catchCounterScaleY = 256;
                }
            }

            gCurrentPinballGame->pikaSpinPeriod = (450 + gCurrentPinballGame->pikaSpinMomentum) / 10;
            if (gCurrentPinballGame->pikaSpinPeriod < 5)
                gCurrentPinballGame->pikaSpinPeriod = 5;

            gCurrentPinballGame->pikachuSpinFrame = (gCurrentPinballGame->pikaSpinFrameCounter * 16) / gCurrentPinballGame->pikaSpinPeriod;
        }
        else
        {
            if (gCurrentPinballGame->pikachuSpinFrame > 0)
            {
                gCurrentPinballGame->pikaSpinFrameCounter++;
                gCurrentPinballGame->pikaSpinFrameCounter %= 40;
                gCurrentPinballGame->pikachuSpinFrame = (gCurrentPinballGame->pikaSpinFrameCounter * 16) / 40;
            }
        }
    }
}

void DrawPikachuSpinner(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    index = gCurrentPinballGame->pikachuSpinFrame;
    group = gMain.fieldSpriteGroups[31];
    group->baseX = 206 - gCurrentPinballGame->cameraXOffset;
    if (gMain.selectedField == FIELD_RUBY)
        group->baseY = 174 - gCurrentPinballGame->cameraYOffset;
    else
        group->baseY = 154 - gCurrentPinballGame->cameraYOffset;

    if (gCurrentPinballGame->pikachuSpinFrame != gCurrentPinballGame->pikachuSpinPrevFrame)
    {
        gCurrentPinballGame->pikachuSpinPrevFrame = gCurrentPinballGame->pikachuSpinFrame;
        DmaCopy16(3, gMainBoardPikaSpinner_Gfx[index], (void *)0x06010780, 0x120);
    }

    for (i = 0; i < 4; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}
