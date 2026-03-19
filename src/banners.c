#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/main_board.h"

extern void RenderBannerSlideAnimation(void);

void ProcessBannerCameraTransition(void)
{
    if ((gMain.modeChangeFlags & MODE_CHANGE_BANNER) != 0)
    {
        gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
        if (gCurrentPinballGame->bannerActive != 0)
        {
            gCurrentPinballGame->ballFrozenState = 2;
            gCurrentPinballGame->boardEntityActive = 1;
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
                    gCurrentPinballGame->bannerActive = 0;
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
                    gCurrentPinballGame->bannerActive = 0;
                }
            }

            if (gCurrentPinballGame->bannerGfxIndex != 0)
            {
                RenderBannerSlideAnimation();
            }
        }
        else
        {
            if (gCurrentPinballGame->cameraYScrollSpeed == 0 || gCurrentPinballGame->cameraYAdjust == 0)
            {
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->ballFrozenState = 0;
                gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                gCurrentPinballGame->ballUpgradeTimerFrozen = 0;

                if (gCurrentPinballGame->bannerPreserveBallState == 0)
                {
                    gCurrentPinballGame->boardEntityActive = 0;
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
                gCurrentPinballGame->ballFrozenState = 0;
                gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                gCurrentPinballGame->ballUpgradeTimerFrozen = 0;

                if (gCurrentPinballGame->bannerPreserveBallState == 0)
                {
                    gCurrentPinballGame->boardEntityActive = 0;
                }
            }

            if (gCurrentPinballGame->cameraYAdjust <= -1)
            {
                gCurrentPinballGame->cameraYAdjust += gCurrentPinballGame->cameraYScrollSpeed;
                if (gCurrentPinballGame->cameraYAdjust >= 0)
                {
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->ballFrozenState = 0;
                    gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                    gCurrentPinballGame->ballUpgradeTimerFrozen = 0;

                    if (gCurrentPinballGame->bannerPreserveBallState == 0)
                    {
                        gCurrentPinballGame->boardEntityActive = 0;
                    }
                }
            }
        }
    }
}

void RenderBannerSlideAnimation(void)
{
    s16 i;
    s16 sp00;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *simple;
    u32 frameCount;

    sp00 = gCurrentPinballGame->bannerGfxIndex - 1;
    spriteGroup = gMain.fieldSpriteGroups[11];
    frameCount = ((gMain.systemFrameCount & 7) / 4);

    if (spriteGroup->available != 0)
    {
        spriteGroup->baseX = 0;
        spriteGroup->baseY = 200;
        if (gCurrentPinballGame->bannerGfxIndex == 4)
        {
            if (gCurrentPinballGame->bannerDelayTimer != 0)
            {
                spriteGroup->baseX = 370;
                spriteGroup->baseY = 44;
            }
            else
            {
                gCurrentPinballGame->activePortraitType = 4;
                DmaCopy16(3, gModeBannerTilemaps[gCurrentPinballGame->bannerGfxIndex], (void *)(VRAM + 0x15800), 0x25E0);
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
                    gMain.fieldSpriteGroups[11]->available = 0; // direct index required here
                    gCurrentPinballGame->bannerGfxIndex = 0;
                    gCurrentPinballGame->activePortraitType = 0;
                }
            }
        }
        else
        {
            gCurrentPinballGame->activePortraitType = 4;
            // i = framecount ???
            DmaCopy16(3, gModeBannerTilemaps[gCurrentPinballGame->bannerGfxIndex] + ((i = frameCount) * 0x21C0), (void *)(VRAM + 0x15800), 0x21C0);
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

                                if ((gCurrentPinballGame->ballCatchState == TRAP_EVO_SHOP_HOLE && gCurrentPinballGame->evolutionShopActive == 1) ||
                                    (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE && gCurrentPinballGame->rouletteOutcomeId == 9))
                                {
                                    gCurrentPinballGame->paletteSwapActive = 0;
                                }
                                else
                                {
                                    gCurrentPinballGame->paletteSwapActive = 1;
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2], (void *)(OBJ_PLTT), 0x20);
                                }
                                if (gMain.selectedField == FIELD_SAPPHIRE)
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                                }
                                else
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                                }
                                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                                gCurrentPinballGame->activePaletteIndex = 2;
                            }
                        }
                        else if (gCurrentPinballGame->bannerSlideTimer > 0x24)
                        {
                            gMain.blendBrightness = 4;
                            if (gCurrentPinballGame->bannerSlideTimer <= 0x27)
                            {
                                if ((gCurrentPinballGame->ballCatchState == TRAP_EVO_SHOP_HOLE && gCurrentPinballGame->evolutionShopActive == 1) ||
                                    (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE && gCurrentPinballGame->rouletteOutcomeId == 9))
                                {
                                    gCurrentPinballGame->paletteSwapActive = 0;
                                }
                                else
                                {
                                    gCurrentPinballGame->paletteSwapActive = 1;
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], (void *)(OBJ_PLTT), 0x20);
                                }
                                if (gMain.selectedField == FIELD_SAPPHIRE)
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                                }
                                else
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                                }
                                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
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
                    (gCurrentPinballGame->ballCatchState != TRAP_EVO_SHOP_HOLE || gCurrentPinballGame->evolutionShopActive != 1) &&
                    (gCurrentPinballGame->ballCatchState != TRAP_CENTER_HOLE || gCurrentPinballGame->rouletteOutcomeId != 9))
                {
                    gMain.blendBrightness = 4;
                    if (gCurrentPinballGame->bannerSlideTimer > 0x19)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], (void *)(OBJ_PLTT), 0x20);
                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                        }
                        else
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                        }
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                        gCurrentPinballGame->activePaletteIndex = 1;
                        gCurrentPinballGame->paletteSwapActive = 1;
                    }
                    if (gCurrentPinballGame->bannerSlideTimer == 0x1D)
                    {
                        gMain.blendBrightness = 0;
                    }
                }
                if (gCurrentPinballGame->bannerSlideTimer == 0x1E)
                {
                    gMain.fieldSpriteGroups[11]->available = 0;
                    gCurrentPinballGame->bannerGfxIndex = 0;
                    gCurrentPinballGame->activePortraitType = 0;
                    if ((gCurrentPinballGame->ballCatchState != TRAP_EVO_SHOP_HOLE || gCurrentPinballGame->evolutionShopActive != 1) &&
                        (gCurrentPinballGame->ballCatchState != TRAP_CENTER_HOLE || gCurrentPinballGame->rouletteOutcomeId != 9))
                    {
                        gMain.blendBrightness = 0;
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], (void *)(OBJ_PLTT), 0x20);
                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                        }
                        else
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                        }
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                        gCurrentPinballGame->activePaletteIndex = 0;
                        gCurrentPinballGame->paletteSwapActive = 1;
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
            *dst++ = gModeBannerOamAttributes[sp00][i * 3 + 0];
            *dst++ = gModeBannerOamAttributes[sp00][i * 3 + 1];
            *dst++ = gModeBannerOamAttributes[sp00][i * 3 + 2];

            gOamBuffer[simple->oamId].x = gOamBuffer[simple->oamId].x + spriteGroup->baseX;
            gOamBuffer[simple->oamId].y = gOamBuffer[simple->oamId].y + spriteGroup->baseY;
        }
        return;
    }
    spriteGroup->available = 1;
    return;
}
