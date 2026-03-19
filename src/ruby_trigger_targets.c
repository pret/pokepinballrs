#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const u8 gSideBumperGfx[][0x100];
extern const s16 gSideBumperGfxFrameIndices[][2];
extern const u16 gSideBumperAnimDurations[][2];

extern const s16 gGulpinAnimData[][5];
extern const u16 gGulpinOamData[146][18];
extern const u8 gRubyStageGulpin_Gfx[][0x180];

extern const s16 gChikoritaFlashFrameIndices[];
extern const u8 gChikoritaExplosionTiles[][0x100];
extern const u8 gChikoritaProjectileTiles[][0x80];
extern const u8 gRubyFlashingDecorationTiles[][0x300];

//ruby
void UpdateChikoritaAttackAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;
    s16 var0;

    index = 0;
    group = &gMain.spriteGroups[14];
    if (gCurrentPinballGame->chikoritaProjectileTimer < 60)
    {
        if (gCurrentPinballGame->chikoritaProjectileTimer >= 27 && gCurrentPinballGame->chikoritaProjectileTimer < 47)
        {
            index = (gCurrentPinballGame->chikoritaProjectileTimer - 27) / 5;
            DmaCopy16(3, gChikoritaExplosionTiles[index], (void *)0x06014280, 0x100);
            group->baseX = 176 - gCurrentPinballGame->cameraXOffset;
        }
        else
        {
            group->available = 0;
            group->baseX = 176 - gCurrentPinballGame->cameraXOffset;
        }
    }
    else
    {
        if (gCurrentPinballGame->chikoritaProjectileTimer >= 100 && gCurrentPinballGame->chikoritaProjectileTimer < 120)
        {
            index = (gCurrentPinballGame->chikoritaProjectileTimer - 100) / 5;
            DmaCopy16(3, gChikoritaExplosionTiles[index], (void *)0x06014280, 0x100);
            group->baseX = 32 - gCurrentPinballGame->cameraXOffset;
        }
        else
        {
            group->available = 0;
            group->baseX = 32 - gCurrentPinballGame->cameraXOffset;
        }

    }

    if (group->available)
    {
        group->baseY = 296 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 180)
            group->baseY = 180;

        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[13];
    if (group->available)
    {
        if (gCurrentPinballGame->chikoritaProjectileTimer < 120)
        {
            if (gCurrentPinballGame->chikoritaProjectileTimer % 8 == 0)
                m4aSongNumStart(SE_UNKNOWN_0xC6);

            index = (gCurrentPinballGame->chikoritaProjectileTimer % 16) / 4;
            DmaCopy16(3, gChikoritaProjectileTiles[index], (void *)0x06014200, 0x80);
            var0 = (gCurrentPinballGame->chikoritaProjectileTimer << 0x10) / 90;
            gCurrentPinballGame->chikoritaProjectileVelX -= 2;
            gCurrentPinballGame->chikoritaProjectileX += gCurrentPinballGame->chikoritaProjectileVelX;
            if (gCurrentPinballGame->chikoritaProjectileTimer < 30)
                gCurrentPinballGame->chikoritaProjectileY = gCurrentPinballGame->chikoritaProjectileTimer + (Sin(var0) * 24) / 20000;
            else
                gCurrentPinballGame->chikoritaProjectileY = 30 + (Sin(var0) * 24) / 20000;

            gCurrentPinballGame->chikoritaProjectileTimer++;
            if (gCurrentPinballGame->chikoritaProjectileTimer == 27)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->sideBumperBounceCount[1] > 0)
                {
                    gCurrentPinballGame->sideBumperBounceCount[1]++;
                }
                else
                {
                    gCurrentPinballGame->sideBumperBounceCount[1] = 2;
                    gCurrentPinballGame->sideBumperAnimTimer[1] = 190;
                }
            }

            if (gCurrentPinballGame->chikoritaProjectileTimer == 100)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->sideBumperBounceCount[0] > 0)
                {
                    gCurrentPinballGame->sideBumperBounceCount[0]++;
                }
                else
                {
                    gCurrentPinballGame->sideBumperBounceCount[0] = 2;
                    gCurrentPinballGame->sideBumperAnimTimer[0] = 190;
                }
            }
        }
        else
        {
            gCurrentPinballGame->chikoritaProjectileTimer = 0;
            gCurrentPinballGame->chikoritaProjectileX = 0;
            gCurrentPinballGame->chikoritaProjectileY = 190;
            gCurrentPinballGame->chikoritaProjectileVelX = 100;
            gCurrentPinballGame->chikoritaProjectileUnused = 0;
            group->available = 0;
        }

        group->baseX = (gCurrentPinballGame->chikoritaProjectileX / 20) + 71u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->chikoritaProjectileY + 248u - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 190)
            group->baseY = 190;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void AnimateChikoritaSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[53];
    if (gCurrentPinballGame->chikoritaFlashActive)
    {
        index = gChikoritaFlashFrameIndices[gCurrentPinballGame->chikoritaFlashTimer / 5];
        if (gCurrentPinballGame->chikoritaFlashTimer == 40)
        {
            gCurrentPinballGame->chikoritaProjectileTimer = 0;
            gCurrentPinballGame->chikoritaProjectileX = 0;
            gCurrentPinballGame->chikoritaProjectileY = 0;
            gCurrentPinballGame->chikoritaProjectileVelX = 100;
            gCurrentPinballGame->chikoritaProjectileUnused = 0;
            gMain.spriteGroups[13].available = 1;
        }

        if (gCurrentPinballGame->chikoritaFlashTimer < 54)
            gCurrentPinballGame->chikoritaFlashTimer++;
        else
            gCurrentPinballGame->chikoritaFlashActive = 0;

        DmaCopy16(3, gRubyFlashingDecorationTiles[index], (void *)0x06012720, 0x300);
    }
    else
    {
        index = (gMain.systemFrameCount % 50) / 25;
        if (gCurrentPinballGame->randomSpriteVariantSeed == 1)
        {
            DmaCopy16(3, gRubyFlashingDecorationTiles[index], (void *)0x06012720, 0x300);
        }
    }

    group->baseX = 55 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 221 - gCurrentPinballGame->cameraYOffset;
    i = 0;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateGulpinBossState(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const s16 *var0;
    s16 index;

    var0 = gGulpinAnimData[gCurrentPinballGame->gulpinAnimFrameIndex];
    group = &gMain.spriteGroups[57];
    group->baseX = 9 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 288 - gCurrentPinballGame->cameraYOffset;
    if (gCurrentPinballGame->gulpinCurrentLevel > gCurrentPinballGame->seedotCount)
    {
        if (gCurrentPinballGame->seedotExitSequenceActive)
        {
            if (gCurrentPinballGame->seedotExitSequenceTimer == 0)
            {
                gCurrentPinballGame->gulpinAnimFrameIndex = 59;
                gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                gCurrentPinballGame->seedotExitSequenceTimer++;
            }

            if (var0[1] > gCurrentPinballGame->gulpinAnimFrameTimer)
            {
                gCurrentPinballGame->gulpinAnimFrameTimer++;
            }
            else
            {
                gCurrentPinballGame->gulpinAnimFrameTimer = 1;
                gCurrentPinballGame->gulpinAnimFrameIndex++;
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 84)
                {
                    gCurrentPinballGame->gulpinAnimFrameIndex = 0;
                    gCurrentPinballGame->seedotExitSequenceActive = 0;
                    gCurrentPinballGame->seedotExitSequenceTimer = 0;
                    gCurrentPinballGame->gulpinCurrentLevel = 0;
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 60 || gCurrentPinballGame->gulpinAnimFrameIndex == 69 || gCurrentPinballGame->gulpinAnimFrameIndex == 78)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
    }
    else if (gCurrentPinballGame->gulpinCurrentLevel < gCurrentPinballGame->seedotCount)
    {
        if (var0[1] <= gCurrentPinballGame->gulpinAnimFrameTimer)
        {
            gCurrentPinballGame->gulpinAnimFrameTimer = 1;
            gCurrentPinballGame->gulpinAnimFrameIndex++;
            if (gCurrentPinballGame->seedotCount == 1)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 9)
                {
                    gCurrentPinballGame->gulpinCurrentLevel = 1;
                    gCurrentPinballGame->gulpinAnimFrameIndex = 84;
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 6)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->seedotCount == 2)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 23)
                {
                    gCurrentPinballGame->gulpinCurrentLevel = 2;
                    gCurrentPinballGame->gulpinAnimFrameIndex = 95;
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 20)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->seedotCount == 3)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 35)
                {
                    gCurrentPinballGame->gulpinCurrentLevel = 3;
                    gCurrentPinballGame->gulpinAnimFrameIndex = 35;
                    RequestBoardStateTransition(7);
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 32)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
        else
        {
            gCurrentPinballGame->gulpinAnimFrameTimer++;
        }
    }
    else if (gCurrentPinballGame->seedotCount)
    {
        if (var0[1] > gCurrentPinballGame->gulpinAnimFrameTimer)
        {
            gCurrentPinballGame->gulpinAnimFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->gulpinAnimFrameTimer = 1;
            gCurrentPinballGame->gulpinAnimFrameIndex++;
            if (gCurrentPinballGame->seedotCount == 1)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 95)
                    gCurrentPinballGame->gulpinAnimFrameIndex = 84;
            }
            else if (gCurrentPinballGame->seedotCount == 2)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 109)
                    gCurrentPinballGame->gulpinAnimFrameIndex = 95;
            }
            else if (gCurrentPinballGame->seedotCount == 3)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 60)
                    gCurrentPinballGame->gulpinAnimFrameIndex = 35;
            }
        }
    }

    index = var0[0];
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[2]], (void *)0x06013B80, 0x180);
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[3]], (void *)0x06013A00, 0x180);
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[4]], (void *)0x06013880, 0x180);
    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gGulpinOamData[index][i * 3 + 0];
        *dst++ = gGulpinOamData[index][i * 3 + 1];
        *dst++ = gGulpinOamData[index][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void UpdateRubySideBumperAnimation(void)
{
    s16 i;

    for (i = 0; i < 2; i++)
    {
        if (gCurrentPinballGame->sideBumperBounceCount[i] > 0)
        {
            if (gSideBumperAnimDurations[gCurrentPinballGame->sideBumperAnimPhase[i]][0] > gCurrentPinballGame->sideBumperAnimTimer[i])
            {
                gCurrentPinballGame->sideBumperAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sideBumperAnimTimer[i] = 0;
                gCurrentPinballGame->sideBumperAnimPhase[i]++;
                if (gCurrentPinballGame->sideBumperAnimPhase[i] > 11)
                {
                    gCurrentPinballGame->sideBumperAnimPhase[i] = 0;
                    gCurrentPinballGame->sideBumperBounceCount[i]--;
                }
            }

            if (gCurrentPinballGame->sideBumperAnimPhase[i] == 1)
                gCurrentPinballGame->sideBumperShakeOffset[i] = gCurrentPinballGame->sideBumperAnimTimer[i] / 2;

            if (gCurrentPinballGame->sideBumperAnimPhase[i] == 11)
                gCurrentPinballGame->sideBumperShakeOffset[i] = 14 - gCurrentPinballGame->sideBumperAnimTimer[i] / 2;

            if (gCurrentPinballGame->sideBumperShakeOffset[i] < 3)
                gCurrentPinballGame->sideBumperShakeOffset[i] = 3;
        }
    }

    if (gCurrentPinballGame->sideBumperHitFlag)
    {
        if (gCurrentPinballGame->sideBumperHitFlag == 1)
        {
            if (gCurrentPinballGame->boardState != 7)
            {
                if (gCurrentPinballGame->boardState < 3) {
                    if (gCurrentPinballGame->seedotCount < 3)
                    {
                        gCurrentPinballGame->seedotCount++;
                        if (gCurrentPinballGame->seedotCount == 1)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 0;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                        else if (gCurrentPinballGame->seedotCount == 2)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 12;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                        else if (gCurrentPinballGame->seedotCount == 3)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 24;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                            gCurrentPinballGame->seedotModeStartDelay = 1;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->seedotCount < 2)
                    {
                        gCurrentPinballGame->seedotCount++;
                        if (gCurrentPinballGame->seedotCount == 1)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 0;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                        else if (gCurrentPinballGame->seedotCount == 2)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 12;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                    }
                }
            }
        }
        else
        {
            if (gCurrentPinballGame->rampGateState == 0)
                gCurrentPinballGame->rampGateState = 1;
            else
                gCurrentPinballGame->rampGateState = 0;
        }

        gCurrentPinballGame->sideBumperBounceCount[0] = 0;
        gCurrentPinballGame->sideBumperBounceCount[1] = 0;
        gCurrentPinballGame->sideBumperHitFlag = 0;
        PlayRumble(7);
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->scoreAddedInFrame = 3000;
        gCurrentPinballGame->sideBumperAnimPhase[0] = 0;
        gCurrentPinballGame->sideBumperAnimPhase[1] = 0;
        gCurrentPinballGame->sideBumperAnimTimer[0] = 0;
        gCurrentPinballGame->sideBumperAnimTimer[1] = 0;
        gCurrentPinballGame->sideBumperShakeOffset[0] = 3;
        gCurrentPinballGame->sideBumperShakeOffset[1] = 3;
    }
}

void DrawRubySideBumperSprites(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    for (i = 0; i < 2; i++)
    {
        index = gSideBumperGfxFrameIndices[gCurrentPinballGame->sideBumperAnimPhase[i]][0];
        DmaCopy16(3, gSideBumperGfx[index], (void *)0x06012A20 + i * 0x100, 0x100);
        group = &gMain.spriteGroups[59 + i];
        if (group->available)
        {
            int var0 = i * 120 - (gCurrentPinballGame->cameraXOffset - 48);
            group->baseX = var0 + ((1 - (i * 2)) * (gCurrentPinballGame->sideBumperShakeOffset[i] - 14));
            group->baseY = 301 - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }

    if (gCurrentPinballGame->seedotModeStartDelay)
    {
        gCurrentPinballGame->seedotModeStartDelay--;
        if (gCurrentPinballGame->seedotModeStartDelay == 0)
        {
            if (gCurrentPinballGame->activePortraitType)
                gCurrentPinballGame->seedotModeStartDelay = 1;
            else
                gCurrentPinballGame->activePortraitType = 4;

            if (gCurrentPinballGame->seedotModeStartDelay == 0)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 70;
                gCurrentPinballGame->bannerDisplayTimer = 160;
                gCurrentPinballGame->cameraYScrollTarget = 0;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxIndex = 4;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                gCurrentPinballGame->bannerDisplayDuration = 120;
                gCurrentPinballGame->bannerSlidePosition = 0;
                gCurrentPinballGame->bannerSlideTimer = 50;
                gCurrentPinballGame->bannerSlideVelocity = 0;
                DmaCopy16(3, gModeBannerTilemaps[4], (void *)0x06015800, 0x2400);
                DmaCopy16(3, gModeBannerPalettes[4], (void *)0x050003C0, 0x20);
                gMain.blendControl = 0xCE;
            }
        }
    }
}

