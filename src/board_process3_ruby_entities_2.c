#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern struct SongHeader se_whiscash_splashdown;

extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const s16 gSharpedoAnimFrameData[][2];
extern const u16 gSharpedoSpritesheetOam[42][3][3];
extern const u8 gRubyFlashingTiles_Secondary[][0x100];
extern const u8 gChinchouBumperPalettes[];
extern const struct Vector16 gChinchouWaypointPositions[];

extern const s16 gPondBumperTransitionFrames[];
extern const u8 gLotadBumperTiles[][0x100];
extern const u8 gLotadBumperPalettes[];
extern const s16 gLotadBobOffsets[];
extern const s16 gWhiscashFramesetData[][4];
extern const s16 gWhiscashShakeOffsets[];
extern const u8 gWhiscashPalettes[];
extern const u8 gWhiscash_Gfx[][0x480];

extern const u8 gRubyBoardShopDoor_Gfx[][0x180];

extern const s16 gNuzleafAnimFrameData[50][3];
extern const s16 gNuzleafPositions[][2];
extern const u8 gRubyStageNuzleaf_Gfx[][0x280];
extern const u16 gNuzleafOamData[58][6];

#define MIN_POND_SWITCHES_BEFORE_WHISCASH_AVAILABLE 3

void UpdateNuzleafEntity(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 * dst;
    s16 var0;
    s16 var1;

    group = &gMain.spriteGroups[71];
    var0 = 0;
    var1 = 0;
    switch (gCurrentPinballGame->nuzleafAnimState)
    {
    case 0:
        var0 = (gMain.systemFrameCount % 36) / 18;
        var1 = var0;
        break;
    case 1:
        gCurrentPinballGame->nuzleafFrameTimer = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 0;
        gCurrentPinballGame->nuzleafAnimState = 2;
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 50000;
        break;
    case 2:
        if (gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][1] > gCurrentPinballGame->nuzleafFrameTimer)
        {
            gCurrentPinballGame->nuzleafFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->nuzleafFrameTimer = 0;
            gCurrentPinballGame->nuzleafFrameIndex++;
            if (gCurrentPinballGame->nuzleafFrameIndex == 7)
            {
                gCurrentPinballGame->nuzleafAnimState = 0;
                gCurrentPinballGame->nuzleafFrameIndex = 0;
                gCurrentPinballGame->nuzleafPositionIndex = 1;
            }
        }
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    case 3:
        gCurrentPinballGame->nuzleafFrameTimer = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 7;
        gCurrentPinballGame->nuzleafAnimState = 4;
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 100000;
        break;
    case 4:
        if (gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][1] > gCurrentPinballGame->nuzleafFrameTimer)
        {
            gCurrentPinballGame->nuzleafFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->nuzleafFrameTimer = 0;
            gCurrentPinballGame->nuzleafFrameIndex++;
            if (gCurrentPinballGame->nuzleafFrameIndex == 18)
            {
                gCurrentPinballGame->nuzleafAnimState = 5;
                m4aSongNumStart(SE_UNKNOWN_0xD1);
            }
        }

        if (gCurrentPinballGame->nuzleafFrameTimer == 6)
            m4aSongNumStart(SE_UNKNOWN_0xD0);

        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    case 5:
    case 6:
        if (gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][1] > gCurrentPinballGame->nuzleafFrameTimer)
        {
            gCurrentPinballGame->nuzleafFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->nuzleafFrameTimer = 0;
            gCurrentPinballGame->nuzleafFrameIndex++;
            if (gCurrentPinballGame->nuzleafFrameIndex == 24)
                gCurrentPinballGame->nuzleafFrameIndex = 18;
        }

        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    case 7:
        gCurrentPinballGame->nuzleafHitFlag = 0;
        gCurrentPinballGame->nuzleafPositionIndex = 0;
        gCurrentPinballGame->nuzleafFrameTimer = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 0;
        gCurrentPinballGame->nuzleafAnimState = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 24;
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    }

    if (group->available)
    {
        group->baseX = gNuzleafPositions[gCurrentPinballGame->nuzleafPositionIndex][0] - gCurrentPinballGame->cameraXOffset;
        group->baseY = gNuzleafPositions[gCurrentPinballGame->nuzleafPositionIndex][1] - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gRubyStageNuzleaf_Gfx[gCurrentPinballGame->nuzleafGfxTileIndex], (void *)0x06014380, 0x260);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gNuzleafOamData[var1][i * 3 + 0];
            *dst++ = gNuzleafOamData[var1][i * 3 + 1];
            *dst++ = gNuzleafOamData[var1][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gCurrentPinballGame->nuzleafGfxTileIndex = var0;
}

void SelectRubyShopDoorState(void)
{
    if (gCurrentPinballGame->ballCatchState != 3)
    {
        if (gCurrentPinballGame->boardState < 3)
        {
            if (gCurrentPinballGame->evolutionShopActive == 0)
                gCurrentPinballGame->shopDoorTargetFrame = gCurrentPinballGame->shopDoorOpenLevel & 0xF;
            else
                gCurrentPinballGame->shopDoorTargetFrame = 3;
        }
        else if (gCurrentPinballGame->boardState != 6)
        {
            gCurrentPinballGame->shopDoorTargetFrame = 0;
        }
    }
}

void AnimateRubyShopDoor(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;

    group = &gMain.spriteGroups[65];
    if ((gCurrentPinballGame->shopDoorTargetFrame & 0xF) != gCurrentPinballGame->shopDoorCurrentFrame)
    {
        if (gCurrentPinballGame->shopDoorAnimDelay)
        {
            if (gCurrentPinballGame->shopDoorAnimDelay == 5)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 0;
                gCurrentPinballGame->bannerDisplayTimer = 3;
                gCurrentPinballGame->cameraYScrollTarget = 0;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxIndex = 0;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                m4aSongNumStart(SE_UNKNOWN_0xBD);
            }

            gCurrentPinballGame->shopDoorAnimDelay--;
        }
        else
        {
            if (gCurrentPinballGame->shopDoorCurrentFrame > (gCurrentPinballGame->shopDoorTargetFrame & 0xF))
            {
                gCurrentPinballGame->shopDoorCurrentFrame--;
                gCurrentPinballGame->shopDoorAnimDelay = 4;
            }
            else
            {
                gCurrentPinballGame->shopDoorCurrentFrame++;
                gCurrentPinballGame->shopDoorAnimDelay = 4;
            }

            DmaCopy16(3, gRubyBoardShopDoor_Gfx[gCurrentPinballGame->shopDoorCurrentFrame], (void *)0x06013180, 0x180);
        }
    }

    if (gCurrentPinballGame->shopDoorCurrentFrame < 3)
        priority = 3;
    else
        priority = 2;

    group->baseX = 208 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 80 - gCurrentPinballGame->cameraYOffset;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &gMain.spriteGroups[65].oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void DrawWhiscash(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    const s16 *var1;

    group = &gMain.spriteGroups[63];
    var1 = gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx];
    if (group->available)
    {
        var0 = var1[0];
        DmaCopy16(3, gWhiscashPalettes + gCurrentPinballGame->activePaletteIndex * 0x60, (void *)0x05000320, 0x20);
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06014680, 0x460);
        gCurrentPinballGame->rubyBumperCollisionPosition[0].x = -248;
        gCurrentPinballGame->rubyBumperCollisionPosition[0].y = -316;
        group->baseX = var1[2] + 124u - gCurrentPinballGame->cameraXOffset;
        group->baseY = var1[3] + 150u - gCurrentPinballGame->cameraYOffset;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (var0 == 4 || var0 == 10)
            gCurrentPinballGame->whiscashInvulnerable = 0;
        else
            gCurrentPinballGame->whiscashInvulnerable = 1;
    }
}

//Ruby Pond
void RubyPond_EntityLogic(void)
{
    s16 i;
    u16 angle;
    u16 angle2;
    s16 var1;
    s16 frameDecidedNextPondState;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    int squaredMagnitude;

    if (gCurrentPinballGame->shouldProcessWhiscash)
    {
        // If board is currently in one of the modes (catch/etc) force reset to the 3 chinchou
        if (gCurrentPinballGame->boardState > 2)
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;

        // Don't immediately force change state if Wishcash is actively doing something
        if (gCurrentPinballGame->rubyPondContentsChanging)
        {
            if (gCurrentPinballGame->whiscashState < WHISCASH_STATE_ABSORB_ZONE_HIT)
            {
                gCurrentPinballGame->whiscashState = WHISCASH_STATE_LEAVING;
                gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_LEAVING-1;
                gCurrentPinballGame->whiscashStateTimer = 0;
            }

            gCurrentPinballGame->rubyPondContentsChanging = FALSE;
        }

        switch (gCurrentPinballGame->whiscashState)
        {
        case WHISCASH_STATE_ARRIVAL:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SITTING)
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_SITTING;

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPLASH)
                    m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);
            }
            break;
        case WHISCASH_STATE_SITTING:
            // Alternates between frame 4 and 5
            gCurrentPinballGame->whiscashFrameIx = (gCurrentPinballGame->whiscashStateTimer % 44) / 22 + 4;
            gCurrentPinballGame->whiscashStateTimer++;
            break;
        case WHISCASH_STATE_ABSORB_ZONE_HIT:
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_ABSORB_BALL_START;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ABSORBING;
            gCurrentPinballGame->ball->oamPriority = 0;
            gCurrentPinballGame->scoreAddedInFrame = 5000;
            m4aSongNumStart(SE_WHISCASH_CATCH_BALL);
            PlayRumble(7);
            break;
        case WHISCASH_STATE_ABSORBING:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_BALL_HELD_SUNK+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_BALL_HELD_SUNK;
                    gCurrentPinballGame->whiscashStateTimer = 65;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_TO_SPHEAL_BOARD;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START)
            {
                gCurrentPinballGame->ball->spinAngle += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8900;
                gCurrentPinballGame->ball->positionQ8.y = 0xBD00;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+1)
            {
                gCurrentPinballGame->ball->spinAngle += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8C00;
                gCurrentPinballGame->ball->positionQ8.y = 0xB700;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+2)
                gCurrentPinballGame->ball->ballHidden = 1;
            break;
        case WHISCASH_STATE_TO_SPHEAL_BOARD:
            gCurrentPinballGame->startButtonDisabled = 1;
            if (gCurrentPinballGame->whiscashStateTimer == 65)
            {
                m4aSongNumStart(SE_WARP);
                gMain.blendControl = 0x9E;
            }

            if (gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer--;
                gMain.blendBrightness = 16 - gCurrentPinballGame->whiscashStateTimer / 4;
                if (gCurrentPinballGame->whiscashStateTimer == 0)
                {
                    gCurrentPinballGame->nextBonusField = FIELD_SPHEAL;
                    gCurrentPinballGame->bonusReturnState = 1;
                    gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
                    gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
                    TransitionToBonusField();
                }
            }
            break;
        case WHISCASH_STATE_INIT_RETURN_FROM_BONUS: //from board initialization
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_DELIVER_BALL_START;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_RISE_SPIT_LEAVE;
            gCurrentPinballGame->ball->oamPriority = 0;
            break;
        case WHISCASH_STATE_RISE_SPIT_LEAVE:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_DELIVER_BALL_END+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL + 1)
                {
                    gCurrentPinballGame->ball->spinAngle -= 64;
                    gCurrentPinballGame->ball->positionQ8.x = 0x8300;
                    gCurrentPinballGame->ball->positionQ8.y = 0xC700;
                    gCurrentPinballGame->ball->velocity.x = -120;
                    gCurrentPinballGame->ball->velocity.y = 210;
                    gCurrentPinballGame->ball->oamPriority = 3;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_EMERGING)
                    m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL + 7) {
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
                }
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL)
                {
                    m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
                }
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL)
            {
                gCurrentPinballGame->ball->ballHidden = 0;
                gCurrentPinballGame->ball->spinAngle -= 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8500;
                gCurrentPinballGame->ball->positionQ8.y = 0xC000;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL+2)
                gCurrentPinballGame->ballFrozenState = 0;
            break;
        case WHISCASH_STATE_HIT:
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_HIT;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ANGRY;
            gCurrentPinballGame->scoreAddedInFrame = 10;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->saverTimeRemaining)
                gCurrentPinballGame->saverTimeRemaining = 1;
            break;
        case WHISCASH_STATE_ANGRY:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING_AFTER_HIT)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_HIT+2)
                    m4aSongNumStart(SE_WHISCASH_EARTHQUAKE);
            }

            // Heavy shaking starts
            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT)
            {
                gCurrentPinballGame->screenShakeX = gWhiscashShakeOffsets[gCurrentPinballGame->whiscashStateTimer % 8];
                if (gCurrentPinballGame->whiscashStateTimer % 4 == 0)
                    MPlayStart(&gMPlayInfo_SE3, &se_whiscash_splashdown);

                if (gCurrentPinballGame->whiscashStateTimer % 10 == 0)
                    PlayRumble(12);
            }
            break;
        case WHISCASH_STATE_LEAVING: //Early Exit (mode started)
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_BALL_HELD_SUNK+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
            }
            break;
        case WHISCASH_STATE_CLEANUP:
            gCurrentPinballGame->shouldProcessWhiscash = FALSE;
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            gCurrentPinballGame->rubyPondChangeTimer = 64;
            gCurrentPinballGame->screenShakeX = 0;
            break;
        }
    }
    else
    {
        if (gCurrentPinballGame->rubyPondContentsChanging)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 144)
            {
                gCurrentPinballGame->pondBumperStates[0] = gPondBumperTransitionFrames[gCurrentPinballGame->rubyPondChangeTimer / 8];
                gCurrentPinballGame->pondBumperStates[1] = gCurrentPinballGame->pondBumperStates[0];
                gCurrentPinballGame->pondBumperStates[2] = gCurrentPinballGame->pondBumperStates[0];
            }
            else
            {
                gCurrentPinballGame->rubyPondContentsChanging = FALSE;
            }

            if (gCurrentPinballGame->pondBumperStates[0] == 10)
            {
                if (gCurrentPinballGame->rubyPondChangeTimer % 8 == 0 && gCurrentPinballGame->rubyPondChangeTimer / 8 == 8)
                {
                    // Can't switch to Whiscash if in a catch/hatch/etc state, or if it hasn't yet hit a threshold
                    // of pond states first.
                    gCurrentPinballGame->pondSwitchesSinceLastWhiscash++;
                    if (gCurrentPinballGame->pondSwitchesSinceLastWhiscash < MIN_POND_SWITCHES_BEFORE_WHISCASH_AVAILABLE ||
                        gCurrentPinballGame->boardState > 2)
                    {
                        frameDecidedNextPondState = (gMain.systemFrameCount % 5) + 1;
                        if (gCurrentPinballGame->rubyPondState == frameDecidedNextPondState)
                            gCurrentPinballGame->rubyPondState = ((gMain.systemFrameCount + 1) % 5) + 1;
                        else
                            gCurrentPinballGame->rubyPondState = frameDecidedNextPondState;
                    }
                    else
                    {
                        frameDecidedNextPondState = (gMain.systemFrameCount % 6) + 1;
                        if (gCurrentPinballGame->rubyPondState == frameDecidedNextPondState)
                            gCurrentPinballGame->rubyPondState = ((gMain.systemFrameCount + 1) % 6) + 1;
                        else
                            gCurrentPinballGame->rubyPondState = frameDecidedNextPondState;
                    }

                    if (gCurrentPinballGame->forcePondToWhiscash)
                    {
                        gCurrentPinballGame->forcePondToWhiscash = FALSE;
                        gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_WHISCASH;
                    }

                    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_WHISCASH)
                    {
                        gCurrentPinballGame->shouldProcessWhiscash = TRUE;
                        gCurrentPinballGame->whiscashState = WHISCASH_STATE_ARRIVAL;
                        gCurrentPinballGame->whiscashStateTimer = 0;
                        gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                        gCurrentPinballGame->rubyPondContentsChanging = FALSE;
                        gCurrentPinballGame->pondSwitchesSinceLastWhiscash = 0;
                    }

                    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE)
                    {
                        gCurrentPinballGame->rubyBumperLogicPosition[0].x = gChinchouWaypointPositions[0].x * 10;
                        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gChinchouWaypointPositions[0].y * 10;
                    }
                }
            }

            gCurrentPinballGame->rubyPondChangeTimer++;
            if (gCurrentPinballGame->rubyPondChangeTimer == 32)
                m4aSongNumStart(SE_RUBY_BUMPER_LEAVES);

            switch (gCurrentPinballGame->rubyPondState)
            {
            case RUBY_POND_STATE_CHINCHOU_STAGGERED:
            case RUBY_POND_STATE_CHINCHOU_CLOCKWISE:
            case RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE:
            case RUBY_POND_STATE_CHINCHOU_ROWS:
                if (gCurrentPinballGame->rubyPondChangeTimer == 102)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 116)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 130)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            case RUBY_POND_STATE_LOTAD:
                if (gCurrentPinballGame->rubyPondChangeTimer == 102)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 118)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 134)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            case RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE:
                if (gCurrentPinballGame->rubyPondChangeTimer == 104)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            }
        }
    }

    switch (gCurrentPinballGame->rubyPondState)
    {
    case RUBY_POND_STATE_CHINCHOU_STAGGERED:
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1250;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = 1270;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1600;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = 1360;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = 1610;
        break;
    case RUBY_POND_STATE_CHINCHOU_CLOCKWISE:
        for (i = 0; i < 3; i++)
        {
            angle = (gCurrentPinballGame->globalAnimFrameCounter & 0x7F) * 0x200 + i * 0x5555;
            var1 = (gCurrentPinballGame->globalAnimFrameCounter % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->bumperOrbitRadius = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->bumperOrbitRadius * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->bumperOrbitRadius * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE:
        for (i = 0; i < 3; i++)
        {
            angle = 10000 - ((gCurrentPinballGame->globalAnimFrameCounter & 0x7F) * 0x200 + i * 0x5555);
            var1 = (gCurrentPinballGame->globalAnimFrameCounter % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->bumperOrbitRadius = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->bumperOrbitRadius * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->bumperOrbitRadius * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_ROWS:
        for (i = 0; i < 2; i++)
        {
            var1 = 23 - (gCurrentPinballGame->globalAnimFrameCounter % 46);
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].x = (i * 33 + 121) * 10;
            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].y = var1 * 5 + 1340;
        }

        var1 = 23 - (gCurrentPinballGame->globalAnimFrameCounter + 23) % 46;
        if (var1 < 0)
            var1 = 0-var1;

        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = var1 * 5 + 1620;
        break;
    case RUBY_POND_STATE_LOTAD:
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1210;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gLotadBobOffsets[(gCurrentPinballGame->globalAnimFrameCounter % 60) / 10] + 1300;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1600;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = gLotadBobOffsets[((gCurrentPinballGame->globalAnimFrameCounter + 20) % 60) / 10] + 1410;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = gLotadBobOffsets[((gCurrentPinballGame->globalAnimFrameCounter + 40) % 60) / 10] + 1660;
        break;
    case RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE:
        tempVec.x = gChinchouWaypointPositions[gCurrentPinballGame->chinchouWaypointTarget].x * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].x;
        tempVec.y = gChinchouWaypointPositions[gCurrentPinballGame->chinchouWaypointTarget].y * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].y;
        squaredMagnitude = (tempVec.x * tempVec.x) + (tempVec.y * tempVec.y);
        angle2 = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle2) * 7) / 20000;
        tempVec2.y = (Sin(angle2) * -7) / 20000;
        gCurrentPinballGame->rubyBumperLogicPosition[0].x += tempVec2.x;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y += tempVec2.y;
        if (squaredMagnitude < 2500)
            gCurrentPinballGame->chinchouWaypointTarget = Random() % 4;

        // moved off screen
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = -300;
        break;
    case RUBY_POND_STATE_WHISCASH:
        // moved off screen
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = -300;
        break;
    }
}

// Ruby pond bumpers Handle Hit and draw
void RubyPondTriBumperHandleHitAndDraw(void)
{
    s16 i;
    s16 j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->bumperHitCountdown > 0)
    {
        if (gCurrentPinballGame->bumperHitCountdown == 2)
        {
            gCurrentPinballGame->scoreAddedInFrame = 500;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 5 && gCurrentPinballGame->hatchTilesBumperAcknowledged < 6)
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
                        if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->bannerDelayTimer = 50;
                            gCurrentPinballGame->bannerDisplayTimer = 600;
                            gCurrentPinballGame->cameraYScrollTarget = 236;
                            gCurrentPinballGame->cameraYAdjust = 0;
                            gCurrentPinballGame->cameraYScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxIndex = 6;
                            gCurrentPinballGame->bannerActive = 1;
                            gCurrentPinballGame->bannerPreserveBallState = 0;
                            gCurrentPinballGame->bannerDisplayDuration = 80;
                            gCurrentPinballGame->bannerSlidePosition = -2500;
                            gCurrentPinballGame->bannerSlideTimer = 50;
                            gCurrentPinballGame->bannerSlideVelocity = 0;
                            DmaCopy16(3, gModeBannerTilemaps[6], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gModeBannerPalettes[6], (void *)0x050003C0, 0x20);
                        }
                        else
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->bannerDelayTimer = 50;
                            gCurrentPinballGame->bannerDisplayTimer = 600;
                            gCurrentPinballGame->cameraYScrollTarget = 236;
                            gCurrentPinballGame->cameraYAdjust = 0;
                            gCurrentPinballGame->cameraYScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxIndex = 1;
                            gCurrentPinballGame->bannerActive = 1;
                            gCurrentPinballGame->bannerPreserveBallState = 0;
                            gCurrentPinballGame->bannerDisplayDuration = 80;
                            gCurrentPinballGame->bannerSlidePosition = -2500;
                            gCurrentPinballGame->bannerSlideTimer = 50;
                            gCurrentPinballGame->bannerSlideVelocity = 0;
                            DmaCopy16(3, gModeBannerTilemaps[1], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gModeBannerPalettes[1], (void *)0x050003C0, 0x20);
                        }

                        gMain.blendControl = 0xCE;
                    }
                }
            }

            gCurrentPinballGame->pondEntitySpriteFlag++;
            gCurrentPinballGame->bumperHitsSinceReset++;
        }

        gCurrentPinballGame->bumperHitCountdown--;
    }

    group = &gMain.spriteGroups[62];
    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperStates[i])
            {
                if (gCurrentPinballGame->pondBumperStates[i] > 100)
                {
                    gCurrentPinballGame->pondBumperStates[i]--;
                    if (gCurrentPinballGame->pondBumperStates[i] == 100)
                        gCurrentPinballGame->pondBumperStates[i] = 0;

                    var0 = 8;
                }
                else
                {
                    var0 = gCurrentPinballGame->pondBumperStates[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
            }

            DmaCopy16(3, gLotadBumperTiles[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gLotadBumperPalettes + gCurrentPinballGame->activePaletteIndex * 0x60, (void *)0x05000320, 0x20);
    }
    else // chinchou
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperStates[i])
            {
                if (gCurrentPinballGame->pondBumperStates[i] > 100)
                {
                    var0 = 9 - gCurrentPinballGame->pondBumperStates[i] / 105;
                    gCurrentPinballGame->pondBumperStates[i]--;
                    if (gCurrentPinballGame->pondBumperStates[i] == 100)
                        gCurrentPinballGame->pondBumperStates[i] = 0;
                }
                else
                {
                    var0 = gCurrentPinballGame->pondBumperStates[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
            }

            DmaCopy16(3, gRubyFlashingTiles_Secondary[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gChinchouBumperPalettes + gCurrentPinballGame->activePaletteIndex * 0x60, (void *)0x05000320, 0x20);
    }

    // Draw Bumpers: Lotad/chinchou
    for (i = 0; i < 3; i++)
    {
        group->baseX = gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10 - gCurrentPinballGame->cameraXOffset - 8;
        group->baseY = gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10 - gCurrentPinballGame->cameraYOffset - 4;
        gCurrentPinballGame->rubyBumperCollisionPosition[i].x = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10) + 8) * 2;
        gCurrentPinballGame->rubyBumperCollisionPosition[i].y = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10) + 7) * 2;
        if (group->baseY < -40)
            group->baseY = -40;

        //sprites have a left/right half.
        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j + i * 2];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void AnimateSharpedoEntity(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 * dst;
    const u16 * src;
    s16 index;
    s16 var0;

    index = (gMain.systemFrameCount % 55) / 11;
    group = &gMain.spriteGroups[61];
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->catchHoleTileVariant], (void *)0x06012C20, 0x260);
    if (gCurrentPinballGame->catchHoleAnimFrame)
        index = gCurrentPinballGame->catchHoleAnimFrame;

    var0 = gSharpedoAnimFrameData[index][0];
    gCurrentPinballGame->catchHoleTileVariant = gSharpedoAnimFrameData[index][1];
    group->baseX = 179 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 174 - gCurrentPinballGame->cameraYOffset;
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gSharpedoSpritesheetOam[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}
