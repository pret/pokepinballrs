#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"

extern void RenderBannerSlideAnimation(void);

void ProcessBannerCameraTransition(void)
{
    if ((gMain.modeChangeFlags & MODE_CHANGE_BANNER) != 0)
    {
        gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
        if (gCurrentPinballGame->bannerActive)
        {
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_FROZEN;
            gCurrentPinballGame->cameraLocked = TRUE;
            if (gCurrentPinballGame->bannerDelayTimer != 0)
            {
                gCurrentPinballGame->bannerDelayTimer--;
            }
            else if (gCurrentPinballGame->cameraYScrollSpeed == 0)
            {
                if (gCurrentPinballGame->bannerDisplayTimer != 0)
                {
                    gCurrentPinballGame->bannerDisplayTimer--;
                }
                else
                {
                    gCurrentPinballGame->bannerActive = FALSE;
                }
            }
            else
            {
                if (gCurrentPinballGame->cameraYViewport + gCurrentPinballGame->cameraYScrollSpeed <= gCurrentPinballGame->cameraYScrollTarget)
                {
                    gCurrentPinballGame->cameraYAdjust += gCurrentPinballGame->cameraYScrollSpeed;
                }
                else if (gCurrentPinballGame->cameraYViewport - gCurrentPinballGame->cameraYScrollSpeed >= gCurrentPinballGame->cameraYScrollTarget)
                {
                    gCurrentPinballGame->cameraYAdjust -= gCurrentPinballGame->cameraYScrollSpeed;
                }
                else if (gCurrentPinballGame->bannerDisplayTimer != 0)
                {
                    gCurrentPinballGame->bannerDisplayTimer--;
                }
                else
                {
                    gCurrentPinballGame->bannerActive = FALSE;
                }
            }

            if (gCurrentPinballGame->bannerGfxIndex != BANNER_MODE_NONE)
            {
                RenderBannerSlideAnimation();
            }
        }
        else
        {
            if (gCurrentPinballGame->cameraYScrollSpeed == 0 || gCurrentPinballGame->cameraYAdjust == 0)
            {
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;

                if (!gCurrentPinballGame->holdCameraLockAfterBanner)
                {
                    gCurrentPinballGame->cameraLocked = FALSE;
                }
            }

            if (gCurrentPinballGame->cameraYAdjust > 0)
            {
                gCurrentPinballGame->cameraYAdjust -= gCurrentPinballGame->cameraYScrollSpeed;
                if (gCurrentPinballGame->cameraYAdjust > 0)
                {
                    return;
                }

                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;

                if (!gCurrentPinballGame->holdCameraLockAfterBanner)
                {
                    gCurrentPinballGame->cameraLocked = FALSE;
                }
            }

            if (gCurrentPinballGame->cameraYAdjust <= -1)
            {
                gCurrentPinballGame->cameraYAdjust += gCurrentPinballGame->cameraYScrollSpeed;
                if (gCurrentPinballGame->cameraYAdjust >= 0)
                {
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                    gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                    gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;

                    if (!gCurrentPinballGame->holdCameraLockAfterBanner)
                    {
                        gCurrentPinballGame->cameraLocked = FALSE;
                    }
                }
            }
        }
    }
}

void RenderBannerSlideAnimation(void)
{
    s16 i;
    s16 bannerTypeIx;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *simple;
    u32 frameCount;

    bannerTypeIx = gCurrentPinballGame->bannerGfxIndex - 1;
    spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_MAIN_MODE_START_BANNER];
    frameCount = ((gMain.systemFrameCount & 7) / 4);

    if (spriteGroup->active)
    {
        spriteGroup->baseX = 0;
        spriteGroup->baseY = 200;
        if (gCurrentPinballGame->bannerGfxIndex == BANNER_MODE_TRAVEL)
        {
            if (gCurrentPinballGame->bannerDelayTimer != 0)
            {
                spriteGroup->baseX = 370;
                spriteGroup->baseY = 44;
            }
            else
            {
                gCurrentPinballGame->activePortraitType = 4;
                DmaCopy16(3, gModeBannerTilemaps[gCurrentPinballGame->bannerGfxIndex], (void *)OBJ_TILE_ADDR(TILE_INDEX(0, 22, 32)), 0x25E0);
                AnimateBannerSlide();
                if (gCurrentPinballGame->bannerDisplayDuration > 0)
                {
                    gCurrentPinballGame->bannerDisplayDuration--;
                    if (gCurrentPinballGame->bannerDisplayDuration == 0x77)
                    {
                        m4aMPlayAllStop();
                        m4aSongNumStart(MUS_TRAVEL_MODE_START);
                    }
                    gCurrentPinballGame->bannerSlidePosition -= 0x28;
                    spriteGroup->baseX = (gCurrentPinballGame->bannerSlidePosition / 10) + 370;
                    spriteGroup->baseY = 44;
                }
                else
                {
                    spriteGroup->baseX = -110;
                    spriteGroup->baseY = 44;
                    gMain.fieldSpriteGroups[FIELD_SG_MAIN_MODE_START_BANNER]->active = FALSE; // direct index required here
                    gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_NONE;
                    gCurrentPinballGame->activePortraitType = 0;
                }
            }
        }
        else
        {
            gCurrentPinballGame->activePortraitType = 4;
            // i = framecount ???
            DmaCopy16(3, gModeBannerTilemaps[gCurrentPinballGame->bannerGfxIndex] + ((i = frameCount) * 0x21C0), (void *)OBJ_TILE_ADDR(TILE_INDEX(0, 22, 32)), 0x21C0);
            if (gCurrentPinballGame->bannerDisplayDuration > 0)
            {
                gCurrentPinballGame->bannerDisplayDuration--;
                if (gCurrentPinballGame->bannerSlideTimer != 0)
                {
                    if (gCurrentPinballGame->bannerSlideTimer == 0x28)
                    {
                        MPlayStart(&gMPlayInfo_SE1, &se_catch_evo_banner);
                    }
                    gCurrentPinballGame->bannerSlideTimer--;
                    if (gCurrentPinballGame->bannerSlideTimer <= 0xF)
                    {
                        gCurrentPinballGame->bannerSlidePosition += 0xA0;
                    }
                    if (gCurrentPinballGame->bannerSlideTimer > 32 && gCurrentPinballGame->bannerSlideTimer <= 40)
                    {
                        if (gCurrentPinballGame->bannerSlideTimer <= 36)
                        {
                            gMain.blendBrightness = 7;
                            if (gCurrentPinballGame->bannerSlideTimer < 36)
                            {

                                if ((gCurrentPinballGame->ballCatchState == TRAP_EVO_SHOP_HOLE
                                        && gCurrentPinballGame->evolutionShopActive == TRUE) ||
                                    (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE
                                        && gCurrentPinballGame->prizeId == PRIZE_START_EVO_MODE))
                                {
                                    gCurrentPinballGame->paletteSwapActive = FALSE;
                                }
                                else
                                {
                                    gCurrentPinballGame->paletteSwapActive = TRUE;
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2][0], OBJ_PLTT_SLOT(0), PLTT_SLOT_SIZE);
                                }
                                if (gMain.selectedField == FIELD_SAPPHIRE)
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2][2], OBJ_PLTT_SLOT(2), 6*PLTT_SLOT_SIZE);
                                }
                                else
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2][2], OBJ_PLTT_SLOT(2), 7*PLTT_SLOT_SIZE);
                                }
                                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2][10], OBJ_PLTT_SLOT(10), 3*PLTT_SLOT_SIZE);
                                gCurrentPinballGame->activePaletteIndex = 2;
                            }
                        }
                        else if (gCurrentPinballGame->bannerSlideTimer > 0x24)
                        {
                            gMain.blendBrightness = 4;
                            if (gCurrentPinballGame->bannerSlideTimer <= 0x27)
                            {
                                if ((gCurrentPinballGame->ballCatchState == TRAP_EVO_SHOP_HOLE
                                        && gCurrentPinballGame->evolutionShopActive == TRUE) ||
                                    (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE
                                        && gCurrentPinballGame->prizeId == PRIZE_START_EVO_MODE))
                                {
                                    gCurrentPinballGame->paletteSwapActive = FALSE;
                                }
                                else
                                {
                                    gCurrentPinballGame->paletteSwapActive = TRUE;
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][0], OBJ_PLTT_SLOT(0), PLTT_SLOT_SIZE);
                                }
                                if (gMain.selectedField == FIELD_SAPPHIRE)
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][2], OBJ_PLTT_SLOT(2), 6*PLTT_SLOT_SIZE);
                                }
                                else
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][2], OBJ_PLTT_SLOT(2), 7*PLTT_SLOT_SIZE);
                                }
                                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][10], OBJ_PLTT_SLOT(10), 3*PLTT_SLOT_SIZE);
                                gCurrentPinballGame->activePaletteIndex = 1;
                            }
                        }
                    }
                    if (gCurrentPinballGame->bannerSlideTimer == 0)
                    {
                        gCurrentPinballGame->bannerSlidePosition = 0;
                        gCurrentPinballGame->bannerSlideVelocity = 0x3C;
                    }
                }
                spriteGroup->baseX = (gCurrentPinballGame->bannerSlidePosition / 10) + 127;
                spriteGroup->baseY = 44;
            }
            else if (gCurrentPinballGame->bannerSlideTimer < 30)
            {
                gCurrentPinballGame->bannerSlidePosition += gCurrentPinballGame->bannerSlideVelocity;
                spriteGroup->baseX = (gCurrentPinballGame->bannerSlidePosition / 10) + 127;
                spriteGroup->baseY = 44;

                gCurrentPinballGame->bannerSlideTimer++;
                gCurrentPinballGame->bannerSlideVelocity -= 0xA;
                if (gCurrentPinballGame->bannerSlideTimer > 0x18 &&
                    (gCurrentPinballGame->ballCatchState != TRAP_EVO_SHOP_HOLE
                        || gCurrentPinballGame->evolutionShopActive != TRUE)
                    && (gCurrentPinballGame->ballCatchState != TRAP_CENTER_HOLE
                        || gCurrentPinballGame->prizeId != PRIZE_START_EVO_MODE))
                {
                    gMain.blendBrightness = 4;
                    if (gCurrentPinballGame->bannerSlideTimer > 0x19)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][0], OBJ_PLTT_SLOT(0), PLTT_SLOT_SIZE);
                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][2], OBJ_PLTT_SLOT(2), 6*PLTT_SLOT_SIZE);
                        }
                        else
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][2], OBJ_PLTT_SLOT(2), 7*PLTT_SLOT_SIZE);
                        }
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1][10], OBJ_PLTT_SLOT(10), 3*PLTT_SLOT_SIZE);
                        gCurrentPinballGame->activePaletteIndex = 1;
                        gCurrentPinballGame->paletteSwapActive = TRUE;
                    }
                    if (gCurrentPinballGame->bannerSlideTimer == 0x1D)
                    {
                        gMain.blendBrightness = 0;
                    }
                }
                if (gCurrentPinballGame->bannerSlideTimer == 0x1E)
                {
                    gMain.fieldSpriteGroups[FIELD_SG_MAIN_MODE_START_BANNER]->active = FALSE;
                    gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_NONE;
                    gCurrentPinballGame->activePortraitType = 0;
                    if ((gCurrentPinballGame->ballCatchState != TRAP_EVO_SHOP_HOLE
                            || gCurrentPinballGame->evolutionShopActive != TRUE)
                        && (gCurrentPinballGame->ballCatchState != TRAP_CENTER_HOLE
                            || gCurrentPinballGame->prizeId != PRIZE_START_EVO_MODE))
                    {
                        gMain.blendBrightness = 0;
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0][0], OBJ_PLTT_SLOT(0), PLTT_SLOT_SIZE);
                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0][2], OBJ_PLTT_SLOT(2), 6*PLTT_SLOT_SIZE);
                        }
                        else
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0][2], OBJ_PLTT_SLOT(2), 7*PLTT_SLOT_SIZE);
                        }
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0][10], OBJ_PLTT_SLOT(10), 3*PLTT_SLOT_SIZE);
                        gCurrentPinballGame->activePaletteIndex = 0;
                        gCurrentPinballGame->paletteSwapActive = TRUE;
                    }
                }

            }

        }

        for (i = 0; i < 15; i++)
        {
            u16 *src;
            u16 *dst;
            simple = &spriteGroup->oam[i];
            dst = (u16 *)&gOamBuffer[simple->oamId];
            *dst++ = gModeBannerOamAttributes[bannerTypeIx][i * 3 + 0];
            *dst++ = gModeBannerOamAttributes[bannerTypeIx][i * 3 + 1];
            *dst++ = gModeBannerOamAttributes[bannerTypeIx][i * 3 + 2];

            gOamBuffer[simple->oamId].x = gOamBuffer[simple->oamId].x + spriteGroup->baseX;
            gOamBuffer[simple->oamId].y = gOamBuffer[simple->oamId].y + spriteGroup->baseY;
        }
        return;
    }
    spriteGroup->active = TRUE;
    return;
}
