#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/main_board.h"

extern const u8 gSapphireBoardShopShockWall_Gfx[][0x80];

extern const s16 gSapphireBumperAnimFrames[][2];
extern const s16 gBumperMosaicValues[];
extern const u8 gSapphireBumperLeft_Gfx[][0x300];
extern const u8 gSapphireBumperLeftHit_Gfx[][0x200];
extern const u8 gSapphireBumperRight_Gfx[][0x300];
extern const u8 gSapphireBumperRightHit_Gfx[][0x200];
extern const u8 gPondBumper_Gfx[][0x200];

void UpdateSapphireBumperLogic(void)
{
    s16 i;
    u32 mosaicVal;

    for (i = 0; i < 2; i++)
    {
        switch (gCurrentPinballGame->sapphireBumperState[i])
        {
        case 0:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 3)
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
            }

            if (gCurrentPinballGame->sapphireBumperHitFxTimer[i] < 152)
                gCurrentPinballGame->sapphireBumperHitFxTimer[i]++;
            else
                gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 0;
            break;
        case 1:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] == 5)
                {
                    m4aSongNumStart(SE_UNKNOWN_0xE6);
                    gCurrentPinballGame->scoreAddedInFrame = 2000;
                }
            }

            if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] == 6)
            {
                if (gCurrentPinballGame->sapphireBumperLitCountdown)
                {
                    if (gCurrentPinballGame->sapphireBumperLitCountdown == 1)
                    {
                        gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 7;
                        gCurrentPinballGame->sapphireBumperState[i] = 2;
                    }
                }

                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 2:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] == 8)
                    m4aSongNumStart(SE_UNKNOWN_0xE7);

                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 8)
                {
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                    gCurrentPinballGame->sapphireBumperState[i] = 0;
                }
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 3:
            gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 9;
            gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
            gCurrentPinballGame->sapphireBumperState[i] = 4;
            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 4:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 17)
                {
                    if (gCurrentPinballGame->boardState == 6)
                    {
                        gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                        gCurrentPinballGame->sapphireBumperState[i] = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 9;
                    }
                }
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        case 5:
            if (gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[i]][1] > gCurrentPinballGame->sapphireBumperAnimSubTimer[i])
            {
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i]++;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                if (gCurrentPinballGame->sapphireBumperAnimKeyframe[i] > 17)
                {
                    gCurrentPinballGame->sapphireBumperState[i] = 0;
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                }
            }

            gCurrentPinballGame->sapphireBumperHitFxTimer[i] = 20;
            break;
        }
    }

    if (gCurrentPinballGame->ballCatchState != TRAP_EVO_SHOP_HOLE)
    {
        if (gCurrentPinballGame->sapphireBumperLitCountdown)
            gCurrentPinballGame->sapphireBumperLitCountdown--;
    }

    if (gCurrentPinballGame->ballLaunchTimer)
    {
        gCurrentPinballGame->ballLaunchTimer--;
        if (gCurrentPinballGame->ballLaunchTimer == 0)
            gCurrentPinballGame->secondaryBall = gCurrentPinballGame->ballStates;
    }

    if (gCurrentPinballGame->shopBumperHitTimer)
    {
        if (gCurrentPinballGame->shopBumperHitTimer == 17)
        {
            m4aSongNumStart(SE_UNKNOWN_0xE8);
            gCurrentPinballGame->scoreAddedInFrame = 10;
            PlayRumble(13);
        }

        mosaicVal = gBumperMosaicValues[gCurrentPinballGame->shopBumperHitTimer / 3];
        REG_MOSAIC = (mosaicVal << 12) | (mosaicVal << 8) | (mosaicVal << 4) | (mosaicVal << 0);
        gCurrentPinballGame->shopBumperHitTimer--;
    }

    if (gCurrentPinballGame->boardState > 2)
    {
        if (gCurrentPinballGame->boardState != 6)
        {
            for (i = 0; i < 2; i++)
            {
                if (gCurrentPinballGame->sapphireBumperState[i])
                {
                    gCurrentPinballGame->sapphireBumperState[i] = 0;
                    gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 0;
                    gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                }
            }
        }
    }
    else if (gCurrentPinballGame->evoArrowProgress > 2)
    {
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->sapphireBumperState[0] < 3)
            {
                gCurrentPinballGame->sapphireBumperState[0] = 3;
                gCurrentPinballGame->sapphireBumperState[1] = 3;
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->sapphireBumperState[0] > 2)
        {
            gCurrentPinballGame->sapphireBumperState[0] = 0;
            gCurrentPinballGame->sapphireBumperAnimKeyframe[0] = 0;
            gCurrentPinballGame->sapphireBumperState[1] = 0;
            gCurrentPinballGame->sapphireBumperAnimKeyframe[1] = 0;
        }
    }
}

void DrawSapphireBumperSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[61];
    if (!group->available)
        return;

    group->baseX = 68 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 144 - gCurrentPinballGame->cameraYOffset;
    index = gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[0]][0];
    DmaCopy16(3, &gSapphireBumperLeft_Gfx[index], (void *)0x06012DA0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[58];
    group->baseX = 68 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->sapphireBumperHitFxTimer[0] < 14)
    {
        group->baseY = 144 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->sapphireBumperHitFxTimer[0] / 2;
        DmaCopy16(3, &gSapphireBumperLeftHit_Gfx[index], (void *)0x06014720, 0x180);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[62];
    group->baseX = 36 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 163 - gCurrentPinballGame->cameraYOffset;
    index = gSapphireBumperAnimFrames[gCurrentPinballGame->sapphireBumperAnimKeyframe[1]][0];
    DmaCopy16(3, &gSapphireBumperRight_Gfx[index], (void *)0x060130A0, 0x280);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[59];
    group->baseX = 36 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->sapphireBumperHitFxTimer[1] < 14)
    {
        group->baseY = 163 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->sapphireBumperHitFxTimer[1] / 2;
        DmaCopy16(3, &gSapphireBumperRightHit_Gfx[index], (void *)0x06014920, 0x180);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[76];
    group->baseX = 61 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 186 - gCurrentPinballGame->cameraYOffset;
    if (gCurrentPinballGame->eggHatchShockWallOverride)
    {
        gCurrentPinballGame->shopShockWallAnimState = 3;
    }
    else if (gCurrentPinballGame->sapphireBumperState[0])
    {
        if (gCurrentPinballGame->sapphireBumperState[1])
            gCurrentPinballGame->shopShockWallAnimState = 3;
        else
            gCurrentPinballGame->shopShockWallAnimState = 2;
    }
    else if (gCurrentPinballGame->sapphireBumperState[1])
    {
        gCurrentPinballGame->shopShockWallAnimState = 1;
    }
    else
    {
        gCurrentPinballGame->shopShockWallAnimState = 0;
    }

    if (gCurrentPinballGame->shopShockWallAnimState < 3)
        index = gCurrentPinballGame->shopShockWallAnimState * 3 + (gCurrentPinballGame->globalAnimFrameCounter % 30) / 10;
    else
        index = 9;

    DmaCopy16(3, &gSapphireBoardShopShockWall_Gfx[index], (void *)0x060146A0, 0x80);
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
}

void CalculateRubyBumperBounce(void)
{
    gCurrentPinballGame->rubyBumperLogicPosition[0].x = 920;
    gCurrentPinballGame->rubyBumperLogicPosition[0].y = (133 - (gCurrentPinballGame->globalAnimFrameCounter % 60) / 30) * 10;
    gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1260;
    gCurrentPinballGame->rubyBumperLogicPosition[1].y = (131 - ((gCurrentPinballGame->globalAnimFrameCounter + 10) % 60) / 30) * 10;
    gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1080;
    gCurrentPinballGame->rubyBumperLogicPosition[2].y = (161 - ((gCurrentPinballGame->globalAnimFrameCounter + 20) % 60) / 30) * 10;
}

void HandleRubyBumperHit(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[63];
    if (gCurrentPinballGame->bumperHitCountdown > 0)
    {
        if (gCurrentPinballGame->bumperHitCountdown == 2)
        {
            gCurrentPinballGame->scoreAddedInFrame = 500;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 5)
            {
                if (gCurrentPinballGame->hatchTilesBumperAcknowledged < 6)
                {
                    if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 0)
                        gCurrentPinballGame->hatchTilesBumperAcknowledged = 1;
                    else if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 1)
                        gCurrentPinballGame->hatchTilesBumperAcknowledged = 3;
                    else
                        gCurrentPinballGame->hatchTilesBumperAcknowledged = 6;

                    if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 6)
                    {
                        if (gCurrentPinballGame->hatchTilesBoardAcknowledged == 0)
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->bannerDelayTimer = 50;
                            gCurrentPinballGame->bannerDisplayTimer = 600;
                            gCurrentPinballGame->cameraYScrollTarget = 0xEC;
                            gCurrentPinballGame->cameraYAdjust = 0;
                            gCurrentPinballGame->cameraYScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxIndex = 7;
                            gCurrentPinballGame->bannerActive = 1;
                            gCurrentPinballGame->bannerPreserveBallState = 0;
                            gCurrentPinballGame->bannerDisplayDuration = 80;
                            gCurrentPinballGame->bannerSlidePosition = -2500;
                            gCurrentPinballGame->bannerSlideTimer = 50;
                            gCurrentPinballGame->bannerSlideVelocity = 0;
                            DmaCopy16(3, gModeBannerTilemaps[7], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gModeBannerPalettes[7], (void *)0x050003C0, 0x20);
                            gMain.blendControl = 0xCE;
                        }
                    }
                }
            }

            gCurrentPinballGame->pondEntitySpriteFlag++;
            gCurrentPinballGame->bumperHitsSinceReset++;
            if (gCurrentPinballGame->bumperHitsSinceReset == 100)
                gCurrentPinballGame->scoreAddedInFrame = 50000;
        }

        gCurrentPinballGame->bumperHitCountdown--;
    }

    if (group->available)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperStates[i] > 0)
            {
                if (gCurrentPinballGame->pondBumperStates[i] < 0)
                    gCurrentPinballGame->pondBumperStates[i] += 3;

                index = gCurrentPinballGame->pondBumperStates[i] / 4 + 2;
                gCurrentPinballGame->pondBumperStates[i]--;
            }
            else
            {
                index = ((gCurrentPinballGame->globalAnimFrameCounter + (i * 10)) % 30) / 15;
            }

            DmaCopy16(3, &gPondBumper_Gfx[index], (void *)0x060133A0 + i * 0x200, 0x200);

            group->baseX = gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10 - gCurrentPinballGame->cameraXOffset - 8;
            group->baseY = gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10 - gCurrentPinballGame->cameraYOffset - 10;
            gCurrentPinballGame->rubyBumperCollisionPosition[i].x = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10) + 8) * 2;
            gCurrentPinballGame->rubyBumperCollisionPosition[i].y = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10) + 3) * 2;

            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}
