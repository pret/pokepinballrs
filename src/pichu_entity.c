#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SongHeader se_pika_no_kickback;
extern struct SongHeader se_pichu_kickback;
extern struct SongHeader se_pikachu_kickback;

extern s16 gPikaSaverAnimFrameTable[100];
extern s16 gOutlaneCenterXPositions[3];
extern u16 gCatchOverlayAnimData[][2];
extern s16 gCatchOverlayOamData[28][12];
extern const struct Vector32 gPikaSaverWaypoints[];
extern const u16 gAngleToDirectionTable[];
extern const u8 gPikachuSaverTilesGfx[];

void UpdateKickbackLogic(void)
{
    s16 outlaneChuteIx;
    s16 j;
    s16 r5;
    s16 oamIx;
    s16 tempY;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    PichuArrivalSequence();

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
        gCurrentPinballGame->kickbackOccupied[0] = 1;
        gCurrentPinballGame->kickbackOccupied[1] = 1;
    }
    else
    {
        gCurrentPinballGame->kickbackOccupied[0 + gCurrentPinballGame->outLanePikaPosition] = 1;
        gCurrentPinballGame->kickbackOccupied[1 - gCurrentPinballGame->outLanePikaPosition] = 0;
    }

    if (gCurrentPinballGame->pikaKickbackTimer != 0)
    {
        if (gCurrentPinballGame->pikaKickbackTimer == 120)
        {
            // gCurrentPinballGame->outLaneSide + gCurrentPinballGame->outLanePikaPosition
            // Note: this can be && chained off of the previous if, once we have this line deciphered.
            if (gCurrentPinballGame->kickbackOccupied[gCurrentPinballGame->outLaneSide - 1] != 0)
            {
                if (gCurrentPinballGame->pikaChargeTarget > 167)
                {
                    gCurrentPinballGame->ballFrozenState = 1;
                    gCurrentPinballGame->kickbackFiring = 1;
                    gCurrentPinballGame->kickbackAnimProgress = 120;
                    gCurrentPinballGame->kickbackAnimDuration = 120;
                    gCurrentPinballGame->kickbackLaunchTimer = gCurrentPinballGame->kickbackAnimProgress;
                    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
                    gCurrentPinballGame->kickbackAnimFrameTimer = 0;
                    gCurrentPinballGame->kickbackFrameId = 0;

                    if (gCurrentPinballGame->outLanePikaPosition != 2)
                    {
                        gCurrentPinballGame->pikaChargeTarget = 0;
                        gCurrentPinballGame->pikaChargeProgress = 0;
                        gCurrentPinballGame->prevChargeFillValue = 0;
                        gCurrentPinballGame->chargeFillValue = 0;
                        gCurrentPinballGame->chargeIndicatorXOffset = 0;
                        gCurrentPinballGame->chargeIndicatorYOffset = -4;
                        gCurrentPinballGame->chargeIndicatorScaleX = 256;
                        gCurrentPinballGame->chargeIndicatorScaleY = 256;
                        gCurrentPinballGame->chargeFillAnimTimer = 0;
                        gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                    }

                    gCurrentPinballGame->kickbackBallHoverPos = gCurrentPinballGame->ball->positionQ1;
                    gCurrentPinballGame->scoreAddedInFrame = 30000;

                    if (gCurrentPinballGame->bonusPikaSaverCount <= 98)
                        gCurrentPinballGame->bonusPikaSaverCount++;
                }
                else
                {
                    gCurrentPinballGame->pikaKickbackTimer = 60;
                    MPlayStart(&gMPlayInfo_SE1, &se_pika_no_kickback);
                }

                outlaneChuteIx = gCurrentPinballGame->outLaneSide - 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2)
                    gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = (outlaneChuteIx) * 7 + 2;
                else
                    gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = 2;

                DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] * 0x180), 0x06010480 + ((outlaneChuteIx) * 0x180), 0x180);
            }
        }

        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
        else
            gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = 2;

        gCurrentPinballGame->pikaKickbackTimer--;
    }

    if (gCurrentPinballGame->kickbackFiring != 0)
    {
        if (gCurrentPinballGame->kickbackLaunchTimer > 1)
        {
            r5 = (gCurrentPinballGame->kickbackAnimProgress * 0x10000) / 10;
            gCurrentPinballGame->kickbackLaunchTimer--;
            if (gCurrentPinballGame->kickbackAnimProgress != 0)
            {
                gCurrentPinballGame->kickbackAnimProgress--;
                if (gCurrentPinballGame->kickbackAnimProgress == 40 && gCurrentPinballGame->kickbackLaunchTimer > 40)
                {
                    gCurrentPinballGame->kickbackAnimProgress = 60;
                }
            }
            if (gCurrentPinballGame->kickbackLaunchTimer == 116)
            {
                if (gCurrentPinballGame->activePortraitType)
                    gCurrentPinballGame->kickbackLaunchTimer = 120;
                else
                {
                    gCurrentPinballGame->activePortraitType = 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                    {
                        if (gCurrentPinballGame->outLaneSide == 1)
                            MPlayStart(&gMPlayInfo_SE1, &se_pikachu_kickback);
                        else
                            MPlayStart(&gMPlayInfo_SE1, &se_pichu_kickback);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                    else
                    {
                        MPlayStart(&gMPlayInfo_SE1, &se_pikachu_kickback);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                }
            }
            if (gCurrentPinballGame->kickbackLaunchTimer == 115 && gCurrentPinballGame->activePortraitType == 1)
                m4aMPlayVolumeControl(&gMPlayInfo_SE1, 0xFFFF, 0x200);

            // used for the horizontal 'floaty' movement when electric builds pre-launch.
            gCurrentPinballGame->ball->positionQ1.x =
                gCurrentPinballGame->kickbackBallHoverPos.x + ((Sin(r5) * 6) / 20000) +
                ((gOutlaneCenterXPositions[gCurrentPinballGame->outLaneSide - 1] * 2 - gCurrentPinballGame->kickbackBallHoverPos.x) * (gCurrentPinballGame->kickbackAnimDuration - gCurrentPinballGame->kickbackAnimProgress)) / gCurrentPinballGame->kickbackAnimDuration;

            tempY = ((gCurrentPinballGame->kickbackAnimDuration - gCurrentPinballGame->kickbackAnimProgress) * 40) / gCurrentPinballGame->kickbackAnimDuration;
            gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->kickbackBallHoverPos.y - tempY;

            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
        }
        else if (gCurrentPinballGame->kickbackLaunchTimer == 1)
        {
            gCurrentPinballGame->ball->positionQ1.x = gOutlaneCenterXPositions[gCurrentPinballGame->outLaneSide - 1] * 2;
            gCurrentPinballGame->ball->positionQ1.y = 702;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
            gCurrentPinballGame->ball->velocity.x = 0;
            // fly me to the moon
            gCurrentPinballGame->ball->velocity.y = -300;
            m4aSongNumStart(SE_KICKBACK_THUNDERWAVE);
            gCurrentPinballGame->kickbackLaunchTimer = 0;
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

        if (gCurrentPinballGame->kickbackLaunchTimer >= 100)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
            else
                gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = 2;

            if (gCurrentPinballGame->kickbackLaunchTimer == 100)
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
            if (gCatchOverlayAnimData[gCurrentPinballGame->kickbackFrameId][1] > gCurrentPinballGame->kickbackAnimFrameTimer)
                gCurrentPinballGame->kickbackAnimFrameTimer++;
            else
            {
                gCurrentPinballGame->kickbackAnimFrameTimer = 0;
                gCurrentPinballGame->kickbackFrameId++;

                if (gCurrentPinballGame->kickbackFrameId == 23)
                {
                    m4aSongNumStop(SE_KICKBACK_THUNDERWAVE);
                    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
                }

                if (gCurrentPinballGame->kickbackFrameId > 25)
                {
                    gCurrentPinballGame->kickbackFrameId = 25;
                    gCurrentPinballGame->kickbackFiring = 0;
                    gMain.fieldSpriteGroups[38]->available = 0;
                    gCurrentPinballGame->activePortraitType = 0;

                    outlaneChuteIx = gCurrentPinballGame->outLaneSide - 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                        gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = outlaneChuteIx * 9;
                    else
                        gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = 0;

                    DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] * 0x180), 0x06010480 + (outlaneChuteIx * 0x180), 0x180);
                }
            }

            if (gCurrentPinballGame->kickbackFrameId >= 17 && gCurrentPinballGame->kickbackFrameId <= 23)
            {
                if ((gMain.systemFrameCount & 3) >> 1)
                    gCurrentPinballGame->cameraBaseX = -3;
                else
                    gCurrentPinballGame->cameraBaseX = 3;
            }

            oamIx = gCatchOverlayAnimData[gCurrentPinballGame->kickbackFrameId][0];
            outlaneChuteIx = gCurrentPinballGame->outLaneSide - 1;

            spriteGroup = gMain.fieldSpriteGroups[38];
            spriteGroup->baseX = (outlaneChuteIx * 177) - (gCurrentPinballGame->cameraXOffset - 16);
            if (gCurrentPinballGame->kickbackFiring)
            {
                spriteGroup->baseY = 380 - gCurrentPinballGame->cameraYOffset;
                gCurrentPinballGame->kickbackOccupied[outlaneChuteIx] = 0;
            }
            else
            {
                spriteGroup->baseY = 180;
                gCurrentPinballGame->kickbackOccupied[outlaneChuteIx] = 1;
            }

            for (j = 0; j < 4; j++)
            {
                oamSimple = &spriteGroup->oam[j];
                dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                *dst++ = gCatchOverlayOamData[oamIx][j * 3 + 0];
                *dst++ = gCatchOverlayOamData[oamIx][j * 3 + 1];
                *dst++ = gCatchOverlayOamData[oamIx][j * 3 + 2];

                gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            }
        }
    }
    spriteGroup = gMain.fieldSpriteGroups[29];

    if (spriteGroup->available)
    {
        for (outlaneChuteIx = 0; outlaneChuteIx <= 1; outlaneChuteIx++)
        {
            spriteGroup = gMain.fieldSpriteGroups[29 + outlaneChuteIx];
            spriteGroup->baseX = (outlaneChuteIx * 177) - (gCurrentPinballGame->cameraXOffset - 16);
            if (gCurrentPinballGame->kickbackOccupied[outlaneChuteIx])
            {
                if ((gMain.fieldFrameCount % 5) == 0)
                {
                    DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] * 0x180), 0x06010480 + (outlaneChuteIx * 0x180), 0x180);
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

void PichuArrivalSequence(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    u16 angle;
    int xx, yy;
    int squaredMagnitude;
    s16 index;

    group = gMain.fieldSpriteGroups[41];
    if (gCurrentPinballGame->pichuEntranceTimer == 0)
        return;

    if (gCurrentPinballGame->pichuEntranceTimer == 800)
    {
        group->available = 1;
        if (gCurrentPinballGame->pichuWalkMode == 1)
        {
            //Start entrance
            gCurrentPinballGame->walkMonXPos = 1090;
            gCurrentPinballGame->walkMonYPos = 4680;
            gCurrentPinballGame->creatureWaypointIndex = 0;
        }
        else
        {
            //Start exit
            gCurrentPinballGame->walkMonXPos = 2000;
            gCurrentPinballGame->walkMonYPos = 3820;
            gCurrentPinballGame->creatureWaypointIndex = 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->pichuEntranceTimer == 799)
        {
            if (gCurrentPinballGame->pichuWalkMode != 1)
            {
                DmaCopy16(3, gPikaSaverTilesGfx, (void *)0x06010600, 0x180);
            }
        }
        tempVec.x = gPikaSaverWaypoints[gCurrentPinballGame->creatureWaypointIndex].x - 120 - gCurrentPinballGame->walkMonXPos;
        tempVec.y = gPikaSaverWaypoints[gCurrentPinballGame->creatureWaypointIndex].y - 160 - gCurrentPinballGame->walkMonYPos;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredMagnitude = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle) * 7) / 20000;
        tempVec2.y = (Sin(angle) * -7) / 20000;
        index = gAngleToDirectionTable[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
        gCurrentPinballGame->walkMonXPos += tempVec2.x;
        gCurrentPinballGame->walkMonYPos += tempVec2.y;
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
            group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (group->baseY < -30)
                group->baseY = -30;

            DmaCopy16(3, gMonHatchSpriteGroup5_Gfx + (index + 30) * 0x120 , (void *)0x060112A0, 0x120);
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].priority = 1;
                gOamBuffer[oamSimple->oamId].paletteNum = 3;
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        if (squaredMagnitude < 2500)
        {
            gCurrentPinballGame->creatureWaypointIndex++;
            if (gCurrentPinballGame->pichuWalkMode == 1)
            {
                if (gCurrentPinballGame->creatureWaypointIndex == 4)
                {
                    DmaCopy16(3, gPikachuSaverTilesGfx, (void *)0x06010600, 0x180);
                    gCurrentPinballGame->outLanePikaPosition = 2;
                    gMain.fieldSpriteGroups[41]->available = 0;
                    gCurrentPinballGame->pichuEntranceTimer = 1;
                    m4aSongNumStart(SE_PICHU_IN_POSITION_CHIRP);
                }
            }
            else if (gCurrentPinballGame->creatureWaypointIndex == 7)
            {
                gMain.fieldSpriteGroups[41]->available = 0;
                gCurrentPinballGame->pichuEntranceTimer = 1;
            }
        }
    }

    gCurrentPinballGame->pichuEntranceTimer--;
}
