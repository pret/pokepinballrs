#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/main_board.h"

extern const s16 gPelipperIdleFrameIndices[];
extern const s16 gPelipperSwallowAnimData[][3];
extern const s8 gPelipperFlyAnimTable[][2];
extern const u8 gPelipper_Gfx[][0x480];
extern const u16 gPelipperPondSpritesheetOam[20][4][3];
extern const s16 gWailmerAnimFrameMap[][2];
extern const u8 gSapphireBoardWailmer_Gfx[][0x300];
extern const u16 gWailmerSpritesheetOam[26][2][3];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];
extern const s16 gZigzagoonAnimKeyframes[][3];
extern const u8 gSapphireBoardZigzagoon_Gfx[][0x380];
extern const u16 gSapphireBoardZigzagoonSpritesheetOam[42][3][3];
extern const u16 gZigzagoonFxSpritesheetOam[14][7][3];
extern const u8 gZigzagoonShockWallIndicator_Gfx[][0x200];

extern struct SongHeader se_unk_e3;

void DecrementPelipperTimer(void)
{
    if (gCurrentPinballGame->pelipperState == 1)
    {
        if (gCurrentPinballGame->pelipperFrameTimer)
            gCurrentPinballGame->pelipperFrameTimer--;
        else
            gCurrentPinballGame->pelipperState = 0;
    }
}

void UpdatePelipperPondEntity(void)
{
    s16 i;
    struct SpriteGroup *group = &gMain.spriteGroups[60];
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var_sl;
    s16 sp0;
    s16 index;

    var_sl = 0;
    sp0 = 0;
    switch (gCurrentPinballGame->pelipperState)
    {
    case 0:
        gCurrentPinballGame->pelipperYBobOffset = 0;
        var_sl = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
        gCurrentPinballGame->pelipperPosX = 0;
        gCurrentPinballGame->pelipperPosY = 0;
        break;
    case 1:
        var_sl = gPelipperIdleFrameIndices[(gCurrentPinballGame->globalAnimFrameCounter % 40) / 10];
        gCurrentPinballGame->pelipperPosX = 0;
        gCurrentPinballGame->pelipperPosY = 0;
        gCurrentPinballGame->pelipperSwallowAnimIndex = 0;
        gCurrentPinballGame->pelipperSwallowSubTimer = 0;
        if (gCurrentPinballGame->boardState > 2)
        {
            gCurrentPinballGame->pelipperState = 0;
            var_sl = 0;
        }
        break;
    case 2:
        var_sl = 4;
        break;
    case 3:
        if (gCurrentPinballGame->pelipperFrameTimer < 3)
        {
            if (gCurrentPinballGame->pelipperFrameTimer == 0)
            {
                gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
                gCurrentPinballGame->ballFrozenState = 1;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
                gCurrentPinballGame->ball->spinSpeed = 0;
                m4aSongNumStart(SE_UNKNOWN_0xE2);
                PlayRumble(7);
                gCurrentPinballGame->scoreAddedInFrame = 100000;
            }

            gCurrentPinballGame->ball->positionQ0.x = 156;
            gCurrentPinballGame->ball->positionQ0.y = 121 + gCurrentPinballGame->pelipperFrameTimer * 2;
            var_sl = 4;
        }
        else if (gCurrentPinballGame->pelipperFrameTimer < 23)
        {
            gCurrentPinballGame->ball->positionQ0.x = 157;
            gCurrentPinballGame->ball->positionQ0.y = 134;
            gCurrentPinballGame->ball->ballHidden = 1;
            var_sl = 5;
        }
        else
        {
            gCurrentPinballGame->pelipperState = 4;
            gCurrentPinballGame->pelipperFrameTimer = 0;
            var_sl = 2;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->pelipperFrameTimer++;
        gCurrentPinballGame->pelipperSfxTimer = 0;
        break;
    case 4:
        if (gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][2] > gCurrentPinballGame->pelipperSwallowSubTimer)
        {
            gCurrentPinballGame->pelipperSwallowSubTimer++;
        }
        else
        {
            gCurrentPinballGame->pelipperSwallowSubTimer = 0;
            gCurrentPinballGame->pelipperSwallowAnimIndex++;
            if (gCurrentPinballGame->pelipperSwallowAnimIndex == 21)
            {
                gCurrentPinballGame->pelipperSwallowAnimIndex = 20;
                gCurrentPinballGame->pelipperState = 5;
                gCurrentPinballGame->pelipperFrameTimer = 0;
            }

            if (gCurrentPinballGame->pelipperSwallowAnimIndex == 1)
                m4aSongNumStart(SE_UNKNOWN_0xE3);
        }

        sp0 = gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][0];
        var_sl = gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][1];
        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 5:
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
        {
            gCurrentPinballGame->pelipperPosX = -360;
            gCurrentPinballGame->pelipperPosY = -200;
        }

        index = (gCurrentPinballGame->pelipperFrameTimer % 26) / 2;
        var_sl = gPelipperFlyAnimTable[index][0];
        gCurrentPinballGame->pelipperYBobOffset = gPelipperFlyAnimTable[index][1] * 10;
        gCurrentPinballGame->pelipperFlyVelX = -12;
        gCurrentPinballGame->pelipperFlyVelY = -10;
        gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
        gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperPosX / 10 + 157;
        gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperPosY / 10 + 134;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->pelipperFrameTimer++;
        if (gCurrentPinballGame->ball->positionQ0.y < -12)
        {
            if (gCurrentPinballGame->bumperHitsSinceReset > 99)
            {
                gCurrentPinballGame->bumperHitsSinceReset = 0;
                gCurrentPinballGame->pelipperState = 6;
                gCurrentPinballGame->pelipperFrameTimer = 65;
                m4aMPlayAllStop();
            }
            else
            {
                gCurrentPinballGame->pelipperFrameTimer = 0;
                gCurrentPinballGame->pelipperState = 7;
            }
        }

        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            m4aSongNumStart(SE_UNKNOWN_0xE3);
        break;
    case 6:
        gCurrentPinballGame->startButtonDisabled = 1;
        var_sl = gPelipperFlyAnimTable[0][0];
        if (gCurrentPinballGame->pelipperFrameTimer == 65)
        {
            m4aSongNumStart(SE_WARP);
            gMain.blendControl = 0x9E;
        }

        if (gCurrentPinballGame->pelipperFrameTimer)
        {
            gCurrentPinballGame->pelipperFrameTimer--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->pelipperFrameTimer / 4;
            if (gCurrentPinballGame->pelipperFrameTimer == 0)
            {
                gCurrentPinballGame->nextBonusField = FIELD_SPHEAL;
                gCurrentPinballGame->bonusReturnState = 2;
                gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
                gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
                TransitionToBonusField();
            }
        }
        break;
    case 7:
        gCurrentPinballGame->pelipperPosX = -1880;
        gCurrentPinballGame->pelipperPosY = -800;
        gCurrentPinballGame->pelipperFlyVelX = 82;
        gCurrentPinballGame->pelipperFlyVelY = 0;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        gCurrentPinballGame->pelipperState = 8;
        var_sl = 13;
        sp0 = 9;
        break;
    case 8:
        var_sl = (gCurrentPinballGame->pelipperFrameTimer % 24) / 6 + 13;
        gCurrentPinballGame->pelipperYBobOffset = (Sin(gCurrentPinballGame->pelipperFrameTimer * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->pelipperFrameTimer < 40)
        {
            gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
            gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        }
        else if (gCurrentPinballGame->pelipperFrameTimer >= 70)
        {
            gCurrentPinballGame->pelipperFrameTimer = 0;
            gCurrentPinballGame->pelipperState = 9;
            gCurrentPinballGame->pelipperPosX = 1200;
            gCurrentPinballGame->pelipperPosY = -1000;
            m4aSongNumStart(SE_UNKNOWN_0xE3);
            gCurrentPinballGame->pelipperSfxTimer = 0;
        }

        if (gCurrentPinballGame->pelipperFrameTimer == 13)
        {
            gCurrentPinballGame->ball->ballHidden = 0;
            gCurrentPinballGame->pelipperBallDropVelX = 5;
            gCurrentPinballGame->pelipperBallDropVelY = -25;
            gCurrentPinballGame->pelipperBallDropPosX = (gCurrentPinballGame->pelipperPosX / 10 + 157) * 10;
            gCurrentPinballGame->pelipperBallDropPosY = (gCurrentPinballGame->pelipperPosY / 10 + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->ballFrozenState)
        {
            if (gCurrentPinballGame->pelipperFrameTimer < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperPosX / 10 + 157;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperPosY / 10 + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->pelipperBallDropVelY += 2;
                gCurrentPinballGame->pelipperBallDropPosX += gCurrentPinballGame->pelipperBallDropVelX;
                gCurrentPinballGame->pelipperBallDropPosY += gCurrentPinballGame->pelipperBallDropVelY;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperBallDropPosX / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperBallDropPosY / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 91)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 91;
                    gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
                    gCurrentPinballGame->ballFrozenState = 0;
                    gCurrentPinballGame->ball->velocity.x = 128;
                    gCurrentPinballGame->ball->velocity.y = 256;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->boardLayerDepth = 0;
                    m4aSongNumStart(SE_UNKNOWN_0xE5);
                    PlayRumble(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        sp0 = 9;
        gCurrentPinballGame->pelipperFrameTimer++;
        break;
    case 9:
        index = (gCurrentPinballGame->pelipperFrameTimer % 26) / 2;
        var_sl = gPelipperFlyAnimTable[index][0] + 4;
        gCurrentPinballGame->pelipperYBobOffset = gPelipperFlyAnimTable[index][1];
        gCurrentPinballGame->pelipperFlyVelX = -12;
        gCurrentPinballGame->pelipperFlyVelY = 10;
        if (gCurrentPinballGame->pelipperFrameTimer < 100)
        {
            gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
            gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        }
        else
        {
            gCurrentPinballGame->pelipperFrameTimer = 0;
            gCurrentPinballGame->pelipperState = 10;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);
        }

        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_e3);

        gCurrentPinballGame->pelipperFrameTimer++;
        break;
    case 10:
        gCurrentPinballGame->pelipperYBobOffset = 0;
        gCurrentPinballGame->pelipperState = 0;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        var_sl = 0;
        break;
    }

    if (group->available)
    {
        DmaCopy16(3, gPelipper_Gfx[var_sl], (void *)0x060122A0, 0x480);
        group->baseX = gCurrentPinballGame->pelipperPosX / 10 + 146 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->pelipperPosY / 10 + 110 - gCurrentPinballGame->cameraYOffset + gCurrentPinballGame->pelipperYBobOffset / 10;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gPelipperPondSpritesheetOam[sp0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }
}

void AnimateWailmerEntity(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 var0;

    index = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 16;
    group = &gMain.spriteGroups[75];
    if (gCurrentPinballGame->catchHoleAnimFrame)
        index = gCurrentPinballGame->catchHoleAnimFrame;

    var0 = gWailmerAnimFrameMap[index][0];
    index = gWailmerAnimFrameMap[index][1];
    group->baseX = 164 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 166 - gCurrentPinballGame->cameraYOffset;
    DmaCopy16(3, gSapphireBoardWailmer_Gfx[index], (void *)0x06012720, 0x300);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gWailmerSpritesheetOam[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void UpdateZigzagoonEntity(void)
{
    s16 var0;

    switch (gCurrentPinballGame->zigzagoonState)
    {
    case 0:
        gCurrentPinballGame->zigzagoonGfxFrame = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25 + 2;
        gCurrentPinballGame->zigzagoonOamFrame = gCurrentPinballGame->zigzagoonGfxFrame + 1;
        gCurrentPinballGame->zigzagoonShockWallActive = 0;
        break;
    case 1:
        var0 = gCurrentPinballGame->globalAnimFrameCounter % 33;
        if (var0 < 13)
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 0;
            gCurrentPinballGame->zigzagoonOamFrame = 0;
        }
        else if (var0 < 20)
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 9;
            gCurrentPinballGame->zigzagoonOamFrame = 1;
        }
        else if (var0 < 26)
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 1;
            gCurrentPinballGame->zigzagoonOamFrame = 2;
        }
        else
        {
            gCurrentPinballGame->zigzagoonGfxFrame = 9;
            gCurrentPinballGame->zigzagoonOamFrame = 1;
        }

        if (gCurrentPinballGame->ballCatchState != TRAP_CENTER_HOLE)
            gCurrentPinballGame->zigzagoonShockWallActive = 0;
        break;
    case 2:
        gCurrentPinballGame->zigzagoonShockWallActive = 0;
        gCurrentPinballGame->zigzagoonAnimKeyframeIndex = 0;
        gCurrentPinballGame->sapphireBumperAnimFrame = 0;
        gCurrentPinballGame->zigzagoonState = 3;
        gCurrentPinballGame->zigzagoonFxFrame = 0;
        gMain.spriteGroups[27].available = 1;
        gCurrentPinballGame->activePortraitType = 22;
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x06015800, 0xC00);
        m4aSongNumStart(SE_UNKNOWN_0xEC);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        break;
    case 3:
        if (gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][1] > gCurrentPinballGame->sapphireBumperAnimFrame)
        {
            gCurrentPinballGame->sapphireBumperAnimFrame++;
        }
        else
        {
            gCurrentPinballGame->zigzagoonAnimKeyframeIndex++;
            gCurrentPinballGame->sapphireBumperAnimFrame = 0;
            if (gCurrentPinballGame->zigzagoonAnimKeyframeIndex > 16)
            {
                gCurrentPinballGame->zigzagoonAnimKeyframeIndex = 16;
                gCurrentPinballGame->zigzagoonState = 4;
            }
        }

        gCurrentPinballGame->zigzagoonOamFrame = gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][0];
        gCurrentPinballGame->zigzagoonGfxFrame = gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][2];
        if (gCurrentPinballGame->zigzagoonAnimKeyframeIndex < 6)
            gCurrentPinballGame->zigzagoonFxFrame = gCurrentPinballGame->zigzagoonAnimKeyframeIndex + 1;
        else
            gCurrentPinballGame->zigzagoonFxFrame = 0;
        break;
    case 4:
        gCurrentPinballGame->activePortraitType = 0;
        gMain.spriteGroups[27].available = 0;
        gCurrentPinballGame->zigzagoonState = 0;
        break;
    }
}

void DrawZigzagoonAndRouletteStopPrompt(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;

    group = &gMain.spriteGroups[26];
    if (group->available)
    {
        group->baseX = 198 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->sapphireBumperTimer + 284 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->zigzagoonGfxFrame;
        DmaCopy16(3, gSapphireBoardZigzagoon_Gfx[index], (void *)0x06012A20, 0x380);
        index = gCurrentPinballGame->zigzagoonOamFrame;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gSapphireBoardZigzagoonSpritesheetOam[index][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = &gMain.spriteGroups[27];
    if (group->available)
    {
        group->baseX = 198 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 284 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->zigzagoonFxFrame;
        for (i = 0; i < 7; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gZigzagoonFxSpritesheetOam[index][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = &gMain.spriteGroups[70];
    if (group->available)
    {
        group->baseX = 206 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->zigzagoonShockWallActive)
        {
            group->baseY = 260 - gCurrentPinballGame->cameraYOffset;
            index = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
            DmaCopy16(3, &gZigzagoonShockWallIndicator_Gfx[index], (void *)0x06014FA0, 0x200);
        }
        else
        {
            group->baseY = 200;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}
