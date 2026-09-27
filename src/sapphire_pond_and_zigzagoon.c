#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"
#include "constants/board/sapphire_states.h"
#include "constants/mem_layout/sapphire.h"

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

extern struct SongHeader se_pelipper_wing_flap;

void DecrementPelipperTimer(void)
{
    if (gCurrentPinballGame->pelipperState == PELIPPER_STATE_WATCHING_RAMP)
    {
        if (gCurrentPinballGame->pelipperFrameTimer)
            gCurrentPinballGame->pelipperFrameTimer--;
        else
            gCurrentPinballGame->pelipperState = PELIPPER_STATE_NORMAL;
    }
}

void UpdatePelipperPondEntity(void)
{
    s16 i;
    struct SpriteGroup *group = &gMain.spriteGroups[SG_SAPPHIRE_PELIPPER];
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 frameId;
    s16 framesetIx;
    s16 index;

    frameId = 0;
    framesetIx = 0;
    switch (gCurrentPinballGame->pelipperState)
    {
    case PELIPPER_STATE_NORMAL:
        gCurrentPinballGame->pelipperYBobOffset = 0;
        frameId = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
        gCurrentPinballGame->pelipperPosX = 0;
        gCurrentPinballGame->pelipperPosY = 0;
        break;
    case PELIPPER_STATE_WATCHING_RAMP:
        frameId = gPelipperIdleFrameIndices[(gCurrentPinballGame->globalAnimFrameCounter % 40) / 10];
        gCurrentPinballGame->pelipperPosX = 0;
        gCurrentPinballGame->pelipperPosY = 0;
        gCurrentPinballGame->pelipperSwallowAnimIndex = 0;
        gCurrentPinballGame->pelipperSwallowSubTimer = 0;
        if (BoardInActivityMode)
        {
            gCurrentPinballGame->pelipperState = PELIPPER_STATE_NORMAL;
            frameId = 0;
        }
        break;
    case PELIPPER_STATE_OPENED_MOUTH:
        frameId = 4;
        break;
    case PELIPPER_STATE_CLOSING_MOUTH:
        if (gCurrentPinballGame->pelipperFrameTimer < 3)
        {
            if (gCurrentPinballGame->pelipperFrameTimer == 0)
            {
                gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
                gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
                gCurrentPinballGame->ball->spinSpeed = 0;
                m4aSongNumStart(SE_PELIPPER_BALL_GRAB);
                PlayRumble(7);
                gCurrentPinballGame->scoreAddedInFrame = SCORE_PELIPPER_BALL_GRAB;
            }

            gCurrentPinballGame->ball->positionQ0.x = 156;
            gCurrentPinballGame->ball->positionQ0.y = 121 + gCurrentPinballGame->pelipperFrameTimer * 2;
            frameId = 4;
        }
        else if (gCurrentPinballGame->pelipperFrameTimer < 23)
        {
            gCurrentPinballGame->ball->positionQ0.x = 157;
            gCurrentPinballGame->ball->positionQ0.y = 134;
            gCurrentPinballGame->ball->ballHidden = TRUE;
            frameId = 5;
        }
        else
        {
            gCurrentPinballGame->pelipperState = PELIPPER_STATE_TAKEOFF;
            gCurrentPinballGame->pelipperFrameTimer = 0;
            frameId = 2;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->pelipperFrameTimer++;
        gCurrentPinballGame->pelipperSfxTimer = 0;
        break;
    case PELIPPER_STATE_TAKEOFF:
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
                gCurrentPinballGame->pelipperState = PELIPPER_STATE_FLY_OFF_BOARD;
                gCurrentPinballGame->pelipperFrameTimer = 0;
            }

            if (gCurrentPinballGame->pelipperSwallowAnimIndex == 1)
                m4aSongNumStart(SE_PELIPPER_WING_FLAP);
        }

        framesetIx = gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][0];
        frameId = gPelipperSwallowAnimData[gCurrentPinballGame->pelipperSwallowAnimIndex][1];
        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            m4aSongNumStart(SE_PELIPPER_WING_FLAP);
        break;
    case PELIPPER_STATE_FLY_OFF_BOARD:
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
        {
            gCurrentPinballGame->pelipperPosX = -360;
            gCurrentPinballGame->pelipperPosY = -200;
        }

        index = (gCurrentPinballGame->pelipperFrameTimer % 26) / 2;
        frameId = gPelipperFlyAnimTable[index][0];
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
                gCurrentPinballGame->pelipperState = PELIPPER_STATE_WARP_TO_SPHEAL_BOARD;
                gCurrentPinballGame->pelipperFrameTimer = 65;
                m4aMPlayAllStop();
            }
            else
            {
                gCurrentPinballGame->pelipperFrameTimer = 0;
                gCurrentPinballGame->pelipperState = PELIPPER_STATE_SET_SWOOP_FROM_TOP_LEFT;
            }
        }

        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            m4aSongNumStart(SE_PELIPPER_WING_FLAP);
        break;
    case PELIPPER_STATE_WARP_TO_SPHEAL_BOARD:
        gCurrentPinballGame->startButtonDisabled = TRUE;
        frameId = gPelipperFlyAnimTable[0][0];
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
                gCurrentPinballGame->bonusReturnState = BONUS_RETURN_LOCATION_PELIPPER;
                gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
                gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
                TransitionToBonusField();
            }
        }
        break;
    case PELIPPER_STATE_SET_SWOOP_FROM_TOP_LEFT:
        gCurrentPinballGame->pelipperPosX = -1880;
        gCurrentPinballGame->pelipperPosY = -800;
        gCurrentPinballGame->pelipperFlyVelX = 82;
        gCurrentPinballGame->pelipperFlyVelY = 0;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        gCurrentPinballGame->pelipperState = PELIPPER_STATE_SWOOP;
        frameId = 13;
        framesetIx = 9;
        break;
    case PELIPPER_STATE_SWOOP:
        frameId = (gCurrentPinballGame->pelipperFrameTimer % 24) / 6 + 13;
        gCurrentPinballGame->pelipperYBobOffset = MulSin(240, gCurrentPinballGame->pelipperFrameTimer * 0x400);
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
            m4aSongNumStart(SE_PELIPPER_SWOOSH);

        if (gCurrentPinballGame->pelipperFrameTimer < 40)
        {
            gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
            gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        }
        else if (gCurrentPinballGame->pelipperFrameTimer >= 70)
        {
            gCurrentPinballGame->pelipperFrameTimer = 0;
            gCurrentPinballGame->pelipperState = PELIPPER_STATE_FLY_IN_FROM_RIGHT;
            gCurrentPinballGame->pelipperPosX = 1200;
            gCurrentPinballGame->pelipperPosY = -1000;
            m4aSongNumStart(SE_PELIPPER_WING_FLAP);
            gCurrentPinballGame->pelipperSfxTimer = 0;
        }

        if (gCurrentPinballGame->pelipperFrameTimer == 13)
        {
            gCurrentPinballGame->ball->ballHidden = FALSE;
            gCurrentPinballGame->pelipperBallDropVelX = 5;
            gCurrentPinballGame->pelipperBallDropVelY = -25;
            gCurrentPinballGame->pelipperBallDropPosX = (gCurrentPinballGame->pelipperPosX / 10 + 157) * 10;
            gCurrentPinballGame->pelipperBallDropPosY = (gCurrentPinballGame->pelipperPosY / 10 + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_NORMAL)
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
                    gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;
                    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                    gCurrentPinballGame->ball->velocity.x = 128;
                    gCurrentPinballGame->ball->velocity.y = 256;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->boardLayerDepth = 0;
                    m4aSongNumStart(SE_PELIPPER_BALL_DROP_LANDS);
                    PlayRumble(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        framesetIx = 9;
        gCurrentPinballGame->pelipperFrameTimer++;
        break;
    case PELIPPER_STATE_FLY_IN_FROM_RIGHT:
        index = (gCurrentPinballGame->pelipperFrameTimer % 26) / 2;
        frameId = gPelipperFlyAnimTable[index][0] + 4;
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
            gCurrentPinballGame->pelipperState = PELIPPER_STATE_RETURN_TO_NORMAL;
            MPlayStart(&gMPlayInfo_SE1, &se_pelipper_wing_flap);
        }

        if (gCurrentPinballGame->pelipperSfxTimer++ % 35 == 34)
            MPlayStart(&gMPlayInfo_SE1, &se_pelipper_wing_flap);

        gCurrentPinballGame->pelipperFrameTimer++;
        break;
    case PELIPPER_STATE_RETURN_TO_NORMAL:
        gCurrentPinballGame->pelipperYBobOffset = 0;
        gCurrentPinballGame->pelipperState = PELIPPER_STATE_NORMAL;
        gCurrentPinballGame->pelipperFrameTimer = 0;
        frameId = 0;
        break;
    }

    if (group->active)
    {
        DmaCopy16(3, gPelipper_Gfx[frameId], OBJ_VRAM_ADDR_PELIPPER_ENTITY_TILES, SIZE_OF_PELIPPER_ENTTIY_TILES);
        group->baseX = gCurrentPinballGame->pelipperPosX / 10 + 146 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->pelipperPosY / 10 + 110 - gCurrentPinballGame->cameraYOffset + gCurrentPinballGame->pelipperYBobOffset / 10;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gPelipperPondSpritesheetOam[framesetIx][i];
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
    s16 oamIx;

    index = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 16;
    group = &gMain.spriteGroups[SG_SAPPHIRE_WAILMER];
    if (gCurrentPinballGame->catchHoleAnimFrame)
        index = gCurrentPinballGame->catchHoleAnimFrame;

    oamIx = gWailmerAnimFrameMap[index][0];
    index = gWailmerAnimFrameMap[index][1];
    group->baseX = 164 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 166 - gCurrentPinballGame->cameraYOffset;
    DmaCopy16(3, gSapphireBoardWailmer_Gfx[index], OBJ_VRAM_ADDR_WAILMER_ENTITY_TILES, SIZE_OF_WAILMER_ENTTIY_TILES);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gWailmerSpritesheetOam[oamIx][i];
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
    case ZIGZAGOON_STATE_SITTING:
        gCurrentPinballGame->zigzagoonGfxFrame = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25 + 2;
        gCurrentPinballGame->zigzagoonOamFrame = gCurrentPinballGame->zigzagoonGfxFrame + 1;
        gCurrentPinballGame->zigzagoonShockWallActive = FALSE;
        break;
    case ZIGZAGOON_STATE_PRIMED:
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
            gCurrentPinballGame->zigzagoonShockWallActive = FALSE;
        break;
    case ZIGZAGOON_STATE_SIGNALED:
        gCurrentPinballGame->zigzagoonShockWallActive = FALSE;
        gCurrentPinballGame->zigzagoonAnimKeyframeIndex = 0;
        gCurrentPinballGame->sapphireBumperAnimFrame = 0;
        gCurrentPinballGame->zigzagoonState = ZIGZAGOON_STATE_LEAPING;
        gCurrentPinballGame->zigzagoonFxFrame = 0;
        gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON_TRAIL_FX].active = TRUE;
        gCurrentPinballGame->activeFxType = FX_ZIGZAGOON_ROULETTE_STOP;
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_ZIGZAGZOON_ROULETTE_STOP_TILES);
        m4aSongNumStart(SE_ZIGZAGOON_ROULETTE_STOP);
        gCurrentPinballGame->scoreAddedInFrame = SCORE_ZIGZAGOON_ROULETTE_STOP;
        break;
    case ZIGZAGOON_STATE_LEAPING:
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
                gCurrentPinballGame->zigzagoonState = ZIGZAGOON_STATE_RETURN_TO_NORMAL;
            }
        }

        gCurrentPinballGame->zigzagoonOamFrame = gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][0];
        gCurrentPinballGame->zigzagoonGfxFrame = gZigzagoonAnimKeyframes[gCurrentPinballGame->zigzagoonAnimKeyframeIndex][2];
        if (gCurrentPinballGame->zigzagoonAnimKeyframeIndex < 6)
            gCurrentPinballGame->zigzagoonFxFrame = gCurrentPinballGame->zigzagoonAnimKeyframeIndex + 1;
        else
            gCurrentPinballGame->zigzagoonFxFrame = 0;
        break;
    case ZIGZAGOON_STATE_RETURN_TO_NORMAL:
        gCurrentPinballGame->activeFxType = FX_NONE;
        gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON_TRAIL_FX].active = FALSE;
        gCurrentPinballGame->zigzagoonState = ZIGZAGOON_STATE_SITTING;
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

    group = &gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON];
    if (group->active)
    {
        group->baseX = 198 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->sapphireBumperTimer + 284 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->zigzagoonGfxFrame;
        DmaCopy16(3, gSapphireBoardZigzagoon_Gfx[index], OBJ_VRAM_ADDR_ZIGZAGOON_ENTITY_TILES, SIZE_OF_ZIGZAGOON_ENTTIY_TILES);
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

    group = &gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON_TRAIL_FX];
    if (group->active)
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

    group = &gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON_SPEECH_BUBBLE];
    if (group->active)
    {
        group->baseX = 206 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->zigzagoonShockWallActive)
        {
            group->baseY = 260 - gCurrentPinballGame->cameraYOffset;
            index = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
            DmaCopy16(3, &gZigzagoonShockWallIndicator_Gfx[index], OBJ_VRAM_ADDR_ZIGZAGOON_SPEECH_BUBBLE_TILES, SIZE_OF_ZIGZAGOON_SPEECH_BUBBLE_TILES);
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
