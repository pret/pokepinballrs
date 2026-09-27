#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"
#include "constants/board/sapphire_states.h"
#include "constants/mem_layout/sapphire.h"

extern const u8 gSapphireBoardShopShockWall_Gfx[][0x80];

extern const s16 gShopGuardianAnimFramesetData[][2];
extern const s16 gBumperMosaicValues[];
extern const u8 gSapphireMinun_Gfx[][0x300];
extern const u8 gSapphireMinunHeadElectricity_Gfx[][0x200];
extern const u8 gSapphirePlusle_Gfx[][0x300];
extern const u8 gSapphirePlusleHeadElectricity_Gfx[][0x200];
extern const u8 gShroomishBumperHit_Gfx[][0x200];

void UpdateSapphireShopGateLogic(void)
{
    s16 i;
    u32 mosaicVal;

    for (i = 0; i < 2; i++)
    {
        // Mart gate buttons
        switch (gCurrentPinballGame->shopGuardianState[i])
        {
        case SHOP_GAURDIAN_STATE_PROTECTING:
            if (gShopGuardianAnimFramesetData[gCurrentPinballGame->shopGuardianAnimFrames[i]][1] > gCurrentPinballGame->shopGuardianAnimFrameTimer[i])
            {
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->shopGuardianAnimFrames[i]++;
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
                if (gCurrentPinballGame->shopGuardianAnimFrames[i] > 3)
                    gCurrentPinballGame->shopGuardianAnimFrames[i] = 0;
            }

            if (gCurrentPinballGame->shopGuardianTargetHitFxTimer[i] < 152)
                gCurrentPinballGame->shopGuardianTargetHitFxTimer[i]++;
            else
                gCurrentPinballGame->shopGuardianTargetHitFxTimer[i] = 0;
            break;
        case SHOP_GAURDIAN_STATE_KNOCKED_DOWN:
            if (gShopGuardianAnimFramesetData[gCurrentPinballGame->shopGuardianAnimFrames[i]][1] > gCurrentPinballGame->shopGuardianAnimFrameTimer[i])
            {
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->shopGuardianAnimFrames[i]++;
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
                if (gCurrentPinballGame->shopGuardianAnimFrames[i] == 5)
                {
                    m4aSongNumStart(SE_SAPPHIRE_MART_GATE_TRIGGER);
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_SAPPHIRE_SHOP_GATE_TRIGGER_ACTIVATED;
                }
            }

            if (gCurrentPinballGame->shopGuardianAnimFrames[i] == 6)
            {
                if (gCurrentPinballGame->shopGuardianReadyCountdown)
                {
                    if (gCurrentPinballGame->shopGuardianReadyCountdown == 1)
                    {
                        gCurrentPinballGame->shopGuardianAnimFrames[i] = 7;
                        gCurrentPinballGame->shopGuardianState[i] = SHOP_GAURDIAN_STATE_PREPARING_WALL;
                    }
                }

                gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
            }

            gCurrentPinballGame->shopGuardianTargetHitFxTimer[i] = 20;
            break;
        case SHOP_GAURDIAN_STATE_PREPARING_WALL:
            if (gShopGuardianAnimFramesetData[gCurrentPinballGame->shopGuardianAnimFrames[i]][1] > gCurrentPinballGame->shopGuardianAnimFrameTimer[i])
            {
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->shopGuardianAnimFrames[i]++;
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
                if (gCurrentPinballGame->shopGuardianAnimFrames[i] == 8)
                    m4aSongNumStart(SE_SAPPHIRE_MART_GATE_REPLACED);

                if (gCurrentPinballGame->shopGuardianAnimFrames[i] > 8)
                {
                    gCurrentPinballGame->shopGuardianAnimFrames[i] = 0;
                    gCurrentPinballGame->shopGuardianState[i] = SHOP_GAURDIAN_STATE_PROTECTING;
                }
            }

            gCurrentPinballGame->shopGuardianTargetHitFxTimer[i] = 20;
            break;
        case SHOP_GAURDIAN_STATE_LOWER_WALL_FOR_EVO_MODE:
            gCurrentPinballGame->shopGuardianAnimFrames[i] = 9;
            gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
            gCurrentPinballGame->shopGuardianState[i] = SHOP_GAURDIAN_STATE_CELEBRATING_EVO_AVAILABLE;
            gCurrentPinballGame->shopGuardianTargetHitFxTimer[i] = 20;
            break;
        case SHOP_GAURDIAN_STATE_CELEBRATING_EVO_AVAILABLE:
            if (gShopGuardianAnimFramesetData[gCurrentPinballGame->shopGuardianAnimFrames[i]][1] > gCurrentPinballGame->shopGuardianAnimFrameTimer[i])
            {
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->shopGuardianAnimFrames[i]++;
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
                if (gCurrentPinballGame->shopGuardianAnimFrames[i] > 17)
                {
                    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EVO_MODE)
                    {
                        gCurrentPinballGame->shopGuardianAnimFrames[i] = 0;
                        gCurrentPinballGame->shopGuardianState[i] = SHOP_GAURDIAN_STATE_PROTECTING;
                    }
                    else
                    {
                        gCurrentPinballGame->shopGuardianAnimFrames[i] = 9;
                    }
                }
            }

            gCurrentPinballGame->shopGuardianTargetHitFxTimer[i] = 20;
            break;
        case SHOP_GAURDIAN_STATE_UNREACHABLE:
            if (gShopGuardianAnimFramesetData[gCurrentPinballGame->shopGuardianAnimFrames[i]][1] > gCurrentPinballGame->shopGuardianAnimFrameTimer[i])
            {
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->shopGuardianAnimFrames[i]++;
                gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
                if (gCurrentPinballGame->shopGuardianAnimFrames[i] > 17)
                {
                    gCurrentPinballGame->shopGuardianState[i] = SHOP_GAURDIAN_STATE_PROTECTING;
                    gCurrentPinballGame->shopGuardianAnimFrames[i] = 0;
                }
            }

            gCurrentPinballGame->shopGuardianTargetHitFxTimer[i] = 20;
            break;
        }
    }

    if (gCurrentPinballGame->ballCatchState != TRAP_EVO_SHOP_HOLE)
    {
        if (gCurrentPinballGame->shopGuardianReadyCountdown)
            gCurrentPinballGame->shopGuardianReadyCountdown--;
    }

    if (gCurrentPinballGame->altBallCameraTimer)
    {
        gCurrentPinballGame->altBallCameraTimer--;
        if (gCurrentPinballGame->altBallCameraTimer == 0)
            gCurrentPinballGame->cameraBall = gCurrentPinballGame->ballStates;
    }

    if (gCurrentPinballGame->shockWallHitTimer)
    {
        if (gCurrentPinballGame->shockWallHitTimer == 17)
        {
            m4aSongNumStart(SE_SAPPHIRE_MART_GATE_HIT);
            gCurrentPinballGame->scoreAddedInFrame = SCORE_SAPPHIRE_SHOP_GATE_HIT;
            PlayRumble(13);
        }

        mosaicVal = gBumperMosaicValues[gCurrentPinballGame->shockWallHitTimer / 3];
        REG_MOSAIC = (mosaicVal << 12) | (mosaicVal << 8) | (mosaicVal << 4) | (mosaicVal << 0);
        gCurrentPinballGame->shockWallHitTimer--;
    }

    if (BoardInActivityMode)
    {
        if (gCurrentPinballGame->boardState != MAIN_BOARD_STATE_EVO_MODE)
        {
            for (i = 0; i < 2; i++)
            {
                if (gCurrentPinballGame->shopGuardianState[i] != SHOP_GAURDIAN_STATE_PROTECTING)
                {
                    gCurrentPinballGame->shopGuardianState[i] = SHOP_GAURDIAN_STATE_PROTECTING;
                    gCurrentPinballGame->shopGuardianAnimFrames[i] = 0;
                    gCurrentPinballGame->shopGuardianAnimFrameTimer[i] = 0;
                }
            }
        }
    }
    else if (gCurrentPinballGame->evoArrowProgress > 2)
    {
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->shopGuardianState[MINUN_TARGET_BUTTON_IX] < SHOP_GAURDIAN_STATE_LOWER_WALL_FOR_EVO_MODE)
            {
                gCurrentPinballGame->shopGuardianState[MINUN_TARGET_BUTTON_IX] = SHOP_GAURDIAN_STATE_LOWER_WALL_FOR_EVO_MODE;
                gCurrentPinballGame->shopGuardianState[PLUSLE_TARGET_BUTTON_IX] = SHOP_GAURDIAN_STATE_LOWER_WALL_FOR_EVO_MODE;
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->shopGuardianState[MINUN_TARGET_BUTTON_IX] > SHOP_GAURDIAN_STATE_PREPARING_WALL)
        {
            gCurrentPinballGame->shopGuardianState[MINUN_TARGET_BUTTON_IX] = SHOP_GAURDIAN_STATE_PROTECTING;
            gCurrentPinballGame->shopGuardianAnimFrames[MINUN_TARGET_BUTTON_IX] = 0;
            gCurrentPinballGame->shopGuardianState[PLUSLE_TARGET_BUTTON_IX] = SHOP_GAURDIAN_STATE_PROTECTING;
            gCurrentPinballGame->shopGuardianAnimFrames[PLUSLE_TARGET_BUTTON_IX] = 0;
        }
    }
}

void DrawSapphireShopGuards(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[SG_SAPPHIRE_MINUN];
    if (!group->active)
        return;

    group->baseX = 68 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 144 - gCurrentPinballGame->cameraYOffset;
    index = gShopGuardianAnimFramesetData[gCurrentPinballGame->shopGuardianAnimFrames[MINUN_TARGET_BUTTON_IX]][0];
    DmaCopy16(3, &gSapphireMinun_Gfx[index], OBJ_VRAM_ADDR_MINUN_ENTITY_TILES, SIZE_OF_MINUN_ENTTIY_TILES);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[SG_SAPPHIRE_MINUN_ELECTRICITY_FX];
    group->baseX = 68 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->shopGuardianTargetHitFxTimer[MINUN_TARGET_BUTTON_IX] < 14)
    {
        group->baseY = 144 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->shopGuardianTargetHitFxTimer[MINUN_TARGET_BUTTON_IX] / 2;
        DmaCopy16(3, &gSapphireMinunHeadElectricity_Gfx[index], OBJ_VRAM_ADDR_MINUN_ELECTRICTY_FX_TILES, SIZE_OF_MINUN_ELECTRICTY_FX_TILES);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[SG_SAPPHIRE_PLUSLE];
    group->baseX = 36 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 163 - gCurrentPinballGame->cameraYOffset;
    index = gShopGuardianAnimFramesetData[gCurrentPinballGame->shopGuardianAnimFrames[PLUSLE_TARGET_BUTTON_IX]][0];
    DmaCopy16(3, &gSapphirePlusle_Gfx[index], OBJ_VRAM_ADDR_PLUSLE_ENTITY_TILES, SIZE_OF_PLUSLE_ENTTIY_TILES);
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[SG_SAPPHIRE_PLUSLE_ELECTRICITY_FX];
    group->baseX = 36 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->shopGuardianTargetHitFxTimer[PLUSLE_TARGET_BUTTON_IX] < 14)
    {
        group->baseY = 163 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->shopGuardianTargetHitFxTimer[PLUSLE_TARGET_BUTTON_IX] / 2;
        DmaCopy16(3, &gSapphirePlusleHeadElectricity_Gfx[index], OBJ_VRAM_ADDR_PLUSLE_ELECTRICTY_FX_TILES, SIZE_OF_PLUSLE_ELECTRICTY_FX_TILES);
    }
    else
    {
        group->baseY = 200;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[SG_SAPPHIRE_MART_ELECTRICAL_GATE_FX];
    group->baseX = 61 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 186 - gCurrentPinballGame->cameraYOffset;
    if (gCurrentPinballGame->eggHatchShockWallOverride)
    {
        gCurrentPinballGame->shopShockWallAnimState = SHOCK_WALL_ANIM_STATE_NONE;
    }
    else if (gCurrentPinballGame->shopGuardianState[MINUN_TARGET_BUTTON_IX] != SHOP_GAURDIAN_STATE_PROTECTING)
    {
        if (gCurrentPinballGame->shopGuardianState[PLUSLE_TARGET_BUTTON_IX] != SHOP_GAURDIAN_STATE_PROTECTING)
            gCurrentPinballGame->shopShockWallAnimState = SHOCK_WALL_ANIM_STATE_NONE;
        else
            gCurrentPinballGame->shopShockWallAnimState = SHOCK_WALL_ANIM_STATE_MINUN_GATE;
    }
    else if (gCurrentPinballGame->shopGuardianState[PLUSLE_TARGET_BUTTON_IX] != SHOP_GAURDIAN_STATE_PROTECTING)
    {
        gCurrentPinballGame->shopShockWallAnimState = SHOCK_WALL_ANIM_STATE_PLUSLE_GATE;
    }
    else
    {
        gCurrentPinballGame->shopShockWallAnimState = SHOCK_WALL_ANIM_STATE_FULL_GATE;
    }

    if (gCurrentPinballGame->shopShockWallAnimState < SHOCK_WALL_ANIM_STATE_NONE)
        index = gCurrentPinballGame->shopShockWallAnimState * 3 + (gCurrentPinballGame->globalAnimFrameCounter % 30) / 10;
    else
        index = 9;

    DmaCopy16(3, &gSapphireBoardShopShockWall_Gfx[index], OBJ_VRAM_ADDR_SAPPHIRE_MART_ELECTRIC_GATE_TILES, SIZE_OF_SAPPHIRE_MART_ELECTRIC_GATE_TILES);
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

void HandleSapphireBumperHit(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[SG_SAPPHIRE_SHROOMISH_BUMPERS];
    if (gCurrentPinballGame->bumperHitCountdown > 0)
    {
        if (gCurrentPinballGame->bumperHitCountdown == 2)
        {
            gCurrentPinballGame->scoreAddedInFrame = SCORE_BUMPER_HIT;
            m4aSongNumStart(SE_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
                && gCurrentPinballGame->boardSubState == CATCH_EM_SUBSTATE_AWAITING_BUMPER_HITS)
            {
                if (gCurrentPinballGame->catchTilesBumperAcknowledgedCount < 6)
                {
                    if (gCurrentPinballGame->catchTilesBumperAcknowledgedCount == 0)
                        gCurrentPinballGame->catchTilesBumperAcknowledgedCount = 1;
                    else if (gCurrentPinballGame->catchTilesBumperAcknowledgedCount == 1)
                        gCurrentPinballGame->catchTilesBumperAcknowledgedCount = 3;
                    else
                        gCurrentPinballGame->catchTilesBumperAcknowledgedCount = 6;

                    if (gCurrentPinballGame->catchTilesBumperAcknowledgedCount == 6)
                    {
                        if (gCurrentPinballGame->catchTilesBoardAcknowledged == 0)
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->bannerDelayTimer = 50;
                            gCurrentPinballGame->bannerDisplayTimer = 600;
                            gCurrentPinballGame->cameraYScrollTarget = 0xEC;
                            gCurrentPinballGame->cameraYAdjust = 0;
                            gCurrentPinballGame->cameraYScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_SHROOMISH_CATCH_BURST;
                            gCurrentPinballGame->bannerActive = TRUE;
                            gCurrentPinballGame->holdCameraLockAfterBanner = FALSE;
                            gCurrentPinballGame->bannerDisplayDuration = 80;
                            gCurrentPinballGame->bannerSlidePosition = -2500;
                            gCurrentPinballGame->bannerSlideTimer = 50;
                            gCurrentPinballGame->bannerSlideVelocity = 0;
                            DmaCopy16(3, gModeBannerTilemaps[7], OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_MODE_BANNER_LOAD_TILES);
                            DmaCopy16(3, gModeBanner_Pals[7], OBJ_PLTT_SLOT(PAL_IX_BANNER), PLTT_SLOT_SIZE);
                            gMain.blendControl = 0xCE;
                        }
                    }
                }
            }

            gCurrentPinballGame->pondEntitySpriteFlag++;
            gCurrentPinballGame->bumperHitsSinceReset++;
            if (gCurrentPinballGame->bumperHitsSinceReset == 100)
                gCurrentPinballGame->scoreAddedInFrame = SCORE_BUMPER_BONUS_HIT;
        }

        gCurrentPinballGame->bumperHitCountdown--;
    }

    if (group->active)
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

            DmaCopy16(3, &gShroomishBumperHit_Gfx[index], OBJ_VRAM_ADDR_SHROOMISH_BUMPER_TILES + i * SIZE_OF_SHROOMISH_BUMPER_TILES, SIZE_OF_SHROOMISH_BUMPER_TILES);

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
