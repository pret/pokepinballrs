#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SongHeader se_unk_142;
extern struct SongHeader se_unk_b1;
extern struct SongHeader se_unk_b3;

extern s16 gPikaSaverAnimFrameTable[100];
extern s16 gCatchHoleXPositions[3];
extern u16 gCatchOverlayAnimData[][2];
extern s16 gCatchOverlayOamData[28][12];

//Both
void UpdateCatchModeLogic(void)
{
    s16 i;
    s16 j;
    s16 r5;
    s16 tempY;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    AnimateCreatureApproach();

    if (gCurrentPinballGame->pikaChargeTarget > 167)
    {
        gCurrentPinballGame->pikaSaverTileIndex[0] = gPikaSaverAnimFrameTable[(gMain.fieldFrameCount % 160) / 5];
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0] + 6;
        else
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0];
    }
    else
    {
        gCurrentPinballGame->pikaSaverTileIndex[0] = (gMain.fieldFrameCount % 50) / 25;
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0] + 9;
        else
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0];
    }

    if (gCurrentPinballGame->outLanePikaPosition == 2)
    {
        gCurrentPinballGame->catchHoleOccupied[0] = 1;
        gCurrentPinballGame->catchHoleOccupied[1] = 1;
    }
    else
    {
        gCurrentPinballGame->catchHoleOccupied[0 + gCurrentPinballGame->outLanePikaPosition] = 1;
        gCurrentPinballGame->catchHoleOccupied[1 - gCurrentPinballGame->outLanePikaPosition] = 0;
    }

    if (gCurrentPinballGame->pikaKickbackTimer != 0)
    {
        if (gCurrentPinballGame->pikaKickbackTimer == 120)
        {
            // gCurrentPinballGame->outLaneSide + gCurrentPinballGame->outLanePikaPosition
            // Note: this can be && chained off of the previous if, once we have this line deciphered.
            if (gCurrentPinballGame->catchHoleOccupied[gCurrentPinballGame->outLaneSide - 1] != 0)
            {
                if (gCurrentPinballGame->pikaChargeTarget > 167)
                {
                    gCurrentPinballGame->ballFrozenState = 1;
                    gCurrentPinballGame->entityOverlayCollisionState = 1;
                    gCurrentPinballGame->catchAnimProgress = 120;
                    gCurrentPinballGame->catchAnimDuration = 120;
                    gCurrentPinballGame->catchOverlayTimer = gCurrentPinballGame->catchAnimProgress;
                    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
                    gCurrentPinballGame->catchOverlayFrameTimer = 0;
                    gCurrentPinballGame->catchOverlayKeyframeIndex = 0;

                    if (gCurrentPinballGame->outLanePikaPosition != 2)
                    {
                        gCurrentPinballGame->pikaChargeTarget = 0;
                        gCurrentPinballGame->pikaChargeProgress = 0;
                        gCurrentPinballGame->prevCatchCounterValue = 0;
                        gCurrentPinballGame->catchCounterValue = 0;
                        gCurrentPinballGame->catchCounterXShift = 0;
                        gCurrentPinballGame->catchCounterSlideOffsetY = -4;
                        gCurrentPinballGame->catchCounterAnimState = 256;
                        gCurrentPinballGame->catchCounterScaleY = 256;
                        gCurrentPinballGame->pikachuAnimTimer = 0;
                        gCurrentPinballGame->catchCounterSlideTimer = 0;
                    }

                    gCurrentPinballGame->catchBallStartPos = gCurrentPinballGame->ball->positionQ1;
                    gCurrentPinballGame->scoreAddedInFrame = 30000;

                    if (gCurrentPinballGame->bonusPikaSaverCount <= 98)
                        gCurrentPinballGame->bonusPikaSaverCount++;
                }
                else
                {
                    gCurrentPinballGame->pikaKickbackTimer = 60;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_142);
                }

                i = gCurrentPinballGame->outLaneSide - 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2)
                    gCurrentPinballGame->pikaSaverTileIndex[i] = (i) * 7 + 2;
                else
                    gCurrentPinballGame->pikaSaverTileIndex[i] = 2;

                DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[i] * 0x180), 0x06010480 + ((i) * 0x180), 0x180);
            }
        }

        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
        else
            gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = 2;

        gCurrentPinballGame->pikaKickbackTimer--;
    }

    if (gCurrentPinballGame->entityOverlayCollisionState != 0)
    {
        if (gCurrentPinballGame->catchOverlayTimer > 1)
        {
            r5 = (gCurrentPinballGame->catchAnimProgress * 0x10000) / 10;
            gCurrentPinballGame->catchOverlayTimer--;
            if (gCurrentPinballGame->catchAnimProgress != 0)
            {
                gCurrentPinballGame->catchAnimProgress--;
                if (gCurrentPinballGame->catchAnimProgress == 40 && gCurrentPinballGame->catchOverlayTimer > 40)
                {
                    gCurrentPinballGame->catchAnimProgress = 60;
                }
            }
            if (gCurrentPinballGame->catchOverlayTimer == 116)
            {
                if (gCurrentPinballGame->activePortraitType)
                    gCurrentPinballGame->catchOverlayTimer = 120;
                else
                {
                    gCurrentPinballGame->activePortraitType = 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                    {
                        if (gCurrentPinballGame->outLaneSide == 1)
                            MPlayStart(&gMPlayInfo_SE1, &se_unk_b1);
                        else
                            MPlayStart(&gMPlayInfo_SE1, &se_unk_b3);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                    else
                    {
                        MPlayStart(&gMPlayInfo_SE1, &se_unk_b1);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                }
            }
            if (gCurrentPinballGame->catchOverlayTimer == 115 && gCurrentPinballGame->activePortraitType == 1)
                m4aMPlayVolumeControl(&gMPlayInfo_SE1, 0xFFFF, 0x200);

            gCurrentPinballGame->ball->positionQ1.x =
                gCurrentPinballGame->catchBallStartPos.x + ((Sin(r5) * 6) / 20000) +
                ((gCatchHoleXPositions[gCurrentPinballGame->outLaneSide - 1] * 2 - gCurrentPinballGame->catchBallStartPos.x) * (gCurrentPinballGame->catchAnimDuration - gCurrentPinballGame->catchAnimProgress)) / gCurrentPinballGame->catchAnimDuration;

            tempY = ((gCurrentPinballGame->catchAnimDuration - gCurrentPinballGame->catchAnimProgress) * 40) / gCurrentPinballGame->catchAnimDuration;
            gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->catchBallStartPos.y - tempY;

            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
        }
        else if (gCurrentPinballGame->catchOverlayTimer == 1)
        {
            gCurrentPinballGame->ball->positionQ1.x = gCatchHoleXPositions[gCurrentPinballGame->outLaneSide - 1] * 2;
            gCurrentPinballGame->ball->positionQ1.y = 702;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
            gCurrentPinballGame->ball->velocity.x = 0;
            // fly me to the moon
            gCurrentPinballGame->ball->velocity.y = -300;
            m4aSongNumStart(SE_UNKNOWN_0x7C);
            gCurrentPinballGame->catchOverlayTimer = 0;
            gCurrentPinballGame->ballFrozenState = 0;
            gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
            gCurrentPinballGame->holeIndicators[(gCurrentPinballGame->outLaneSide - 1) * 3] = 1;

            if (gCurrentPinballGame->allHolesLit == 0 &&
                (gCurrentPinballGame->holeIndicators[0] &
                 gCurrentPinballGame->holeIndicators[1] &
                 gCurrentPinballGame->holeIndicators[2] &
                 gCurrentPinballGame->holeIndicators[3]))
            {
                gCurrentPinballGame->allHolesLit = 1;
                gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
            }

            PlayRumble(11);
        }

        if (gCurrentPinballGame->catchOverlayTimer >= 100)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
            else
                gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = 2;

            if (gCurrentPinballGame->catchOverlayTimer == 100)
            {
                gMain.fieldSpriteGroups[38]->available = 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->outLaneSide == 2)
                {
                    DmaCopy16(3, gPikaSaverFullCoverageGfx, 0x06015800, 0x2400);
                }
                else
                {
                    DmaCopy16(3, gPikaSaverPartialCoverageGfx, 0x06015800, 0x2400);
                }
            }
        }
        else
        {
            if (gCatchOverlayAnimData[gCurrentPinballGame->catchOverlayKeyframeIndex][1] > gCurrentPinballGame->catchOverlayFrameTimer)
                gCurrentPinballGame->catchOverlayFrameTimer++;
            else
            {
                gCurrentPinballGame->catchOverlayFrameTimer = 0;
                gCurrentPinballGame->catchOverlayKeyframeIndex++;

                if (gCurrentPinballGame->catchOverlayKeyframeIndex == 23)
                {
                    m4aSongNumStop(SE_UNKNOWN_0x7C);
                    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
                }

                if (gCurrentPinballGame->catchOverlayKeyframeIndex > 25)
                {
                    gCurrentPinballGame->catchOverlayKeyframeIndex = 25;
                    gCurrentPinballGame->entityOverlayCollisionState = 0;
                    gMain.fieldSpriteGroups[38]->available = 0;
                    gCurrentPinballGame->activePortraitType = 0;

                    i = gCurrentPinballGame->outLaneSide - 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                        gCurrentPinballGame->pikaSaverTileIndex[i] = i * 9;
                    else
                        gCurrentPinballGame->pikaSaverTileIndex[i] = 0;

                    DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[i] * 0x180), 0x06010480 + (i * 0x180), 0x180);
                }
            }

            if (gCurrentPinballGame->catchOverlayKeyframeIndex >= 17 && gCurrentPinballGame->catchOverlayKeyframeIndex <= 23)
            {
                if ((gMain.systemFrameCount & 3) >> 1)
                    gCurrentPinballGame->cameraBaseX = -3;
                else
                    gCurrentPinballGame->cameraBaseX = 3;
            }

            r5 = gCatchOverlayAnimData[gCurrentPinballGame->catchOverlayKeyframeIndex][0];
            i = gCurrentPinballGame->outLaneSide - 1;

            spriteGroup = gMain.fieldSpriteGroups[38];
            spriteGroup->baseX = (i * 177) - (gCurrentPinballGame->cameraXOffset - 16);
            if (gCurrentPinballGame->entityOverlayCollisionState)
            {
                spriteGroup->baseY = 380 - gCurrentPinballGame->cameraYOffset;
                gCurrentPinballGame->catchHoleOccupied[i] = 0;
            }
            else
            {
                spriteGroup->baseY = 180;
                gCurrentPinballGame->catchHoleOccupied[i] = 1;
            }

            for (j = 0; j < 4; j++)
            {
                oamSimple = &spriteGroup->oam[j];
                dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                *dst++ = gCatchOverlayOamData[r5][j * 3 + 0];
                *dst++ = gCatchOverlayOamData[r5][j * 3 + 1];
                *dst++ = gCatchOverlayOamData[r5][j * 3 + 2];

                gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            }
        }
    }
    spriteGroup = gMain.fieldSpriteGroups[29];

    if (spriteGroup->available)
    {
        for (i = 0; i <= 1; i++)
        {
            spriteGroup = gMain.fieldSpriteGroups[29 + i];
            spriteGroup->baseX = (i * 177) - (gCurrentPinballGame->cameraXOffset - 16);
            if (gCurrentPinballGame->catchHoleOccupied[i])
            {
                if ((gMain.fieldFrameCount % 5) == 0)
                {
                    DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[i] * 0x180), 0x06010480 + (i * 0x180), 0x180);
                }

                tempY = 380 - gCurrentPinballGame->cameraYOffset;
                spriteGroup->baseY = tempY;
            }
            else
                spriteGroup->baseY = 200;

            for (j = 0; j <= 1; j++)
            {
                oamSimple = &spriteGroup->oam[j];

                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
            }
        }
    }
}
