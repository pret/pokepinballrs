#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern void RenderBannerScrollSprites(void);


void UpdateBannerScrolling(void)
{
    if ((gMain.modeChangeFlags & MODE_CHANGE_BANNER) != 0)
    {
        gCurrentPinballGame->ballLocked = 1;
        if (gCurrentPinballGame->scrollOverrideActive != 0)
        {
            gCurrentPinballGame->ballLockState = 2;
            gCurrentPinballGame->bossActive = 1;
            if (gCurrentPinballGame->scrollDelayFrames != 0)
            {
                gCurrentPinballGame->scrollDelayFrames--;
            }
            else if (gCurrentPinballGame->fieldScrollSpeed == 0)
            {
                if (gCurrentPinballGame->scrollHoldFrames != 0)
                {
                    gCurrentPinballGame->scrollHoldFrames--;
                }
                else
                {
                    gCurrentPinballGame->scrollOverrideActive = 0;
                }
            }
            else
            {
                if (gCurrentPinballGame->viewportBottomY + gCurrentPinballGame->fieldScrollSpeed <= gCurrentPinballGame->scrollTargetBottomY)
                {
                    gCurrentPinballGame->fieldScrollOffsetY += gCurrentPinballGame->fieldScrollSpeed;
                }
                else if (gCurrentPinballGame->viewportBottomY - gCurrentPinballGame->fieldScrollSpeed >= gCurrentPinballGame->scrollTargetBottomY)
                {
                    gCurrentPinballGame->fieldScrollOffsetY -= gCurrentPinballGame->fieldScrollSpeed;
                }
                else if (gCurrentPinballGame->scrollHoldFrames != 0)
                {
                    gCurrentPinballGame->scrollHoldFrames--;
                }
                else
                {
                    gCurrentPinballGame->scrollOverrideActive = 0;
                }
            }

            if (gCurrentPinballGame->bannerGfxVariant != 0)
            {
                RenderBannerScrollSprites();
            }
        }
        else
        {
            if (gCurrentPinballGame->fieldScrollSpeed == 0 || gCurrentPinballGame->fieldScrollOffsetY == 0)
            {
                gCurrentPinballGame->fieldScrollOffsetY = 0;
                gCurrentPinballGame->ballLockState = 0;
                gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                gCurrentPinballGame->ballLocked = 0;

                if (gCurrentPinballGame->scrollFromBottom == 0)
                {
                    gCurrentPinballGame->bossActive = 0;
                }
            }

            if (gCurrentPinballGame->fieldScrollOffsetY > 0)
            {
                gCurrentPinballGame->fieldScrollOffsetY -= gCurrentPinballGame->fieldScrollSpeed;
                if (gCurrentPinballGame->fieldScrollOffsetY > 0)
                {
                    return;
                }

                gCurrentPinballGame->fieldScrollOffsetY = 0;
                gCurrentPinballGame->ballLockState = 0;
                gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                gCurrentPinballGame->ballLocked = 0;

                if (gCurrentPinballGame->scrollFromBottom == 0)
                {
                    gCurrentPinballGame->bossActive = 0;
                }
            }

            if (gCurrentPinballGame->fieldScrollOffsetY <= -1)
            {
                gCurrentPinballGame->fieldScrollOffsetY += gCurrentPinballGame->fieldScrollSpeed;
                if (gCurrentPinballGame->fieldScrollOffsetY >= 0)
                {
                    gCurrentPinballGame->fieldScrollOffsetY = 0;
                    gCurrentPinballGame->ballLockState = 0;
                    gMain.modeChangeFlags &= ~MODE_CHANGE_BANNER;
                    gCurrentPinballGame->ballLocked = 0;

                    if (gCurrentPinballGame->scrollFromBottom == 0)
                    {
                        gCurrentPinballGame->bossActive = 0;
                    }
                }
            }
        }
    }
}

void RenderBannerScrollSprites(void)
{
    s16 i;
    s16 sp00;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *simple;
    u32 frameCount;

    sp00 = gCurrentPinballGame->bannerGfxVariant - 1;
    spriteGroup = gMain.boardSpriteGroups[11];
    frameCount = ((gMain.systemFrameCount & 7) / 4);

    if (spriteGroup->available != 0)
    {
        spriteGroup->baseX = 0;
        spriteGroup->baseY = 200;
        if (gCurrentPinballGame->bannerGfxVariant == 4)
        {
            if (gCurrentPinballGame->scrollDelayFrames != 0)
            {
                spriteGroup->baseX = 370;
                spriteGroup->baseY = 44;
            }
            else
            {
                gCurrentPinballGame->bannerType = 4;
                DmaCopy16(3, gUnknown_086ACEF8[gCurrentPinballGame->bannerGfxVariant], (void *)(VRAM + 0x15800), 0x25E0);
                UpdateSapphireBannerSlideSprite();
                if (gCurrentPinballGame->fieldEntryAnimTimer > 0)
                {
                    gCurrentPinballGame->fieldEntryAnimTimer--;
                    if (gCurrentPinballGame->fieldEntryAnimTimer == 0x77)
                    {
                        m4aMPlayAllStop();
                        m4aSongNumStart(MUS_TRAVEL_MODE_START);
                    }
                    gCurrentPinballGame->bannerScrollPosQ10 -= 0x28;
                    spriteGroup->baseX = (gCurrentPinballGame->bannerScrollPosQ10 / 10) + 370;
                    spriteGroup->baseY = 44;
                }
                else
                {
                    spriteGroup->baseX = -110;
                    spriteGroup->baseY = 44;
                    gMain.boardSpriteGroups[11]->available = 0; // direct index required here
                    gCurrentPinballGame->bannerGfxVariant = 0;
                    gCurrentPinballGame->bannerType = 0;
                }
            }
        }
        else
        {
            gCurrentPinballGame->bannerType = 4;
            // i = framecount ???
            DmaCopy16(3, gUnknown_086ACEF8[gCurrentPinballGame->bannerGfxVariant] + ((i = frameCount) * 0x21C0), (void *)(VRAM + 0x15800), 0x21C0);
            if (gCurrentPinballGame->fieldEntryAnimTimer > 0)
            {
                gCurrentPinballGame->fieldEntryAnimTimer--;
                if (gCurrentPinballGame->bannerAnimPhase != 0)
                {
                    if (gCurrentPinballGame->bannerAnimPhase == 0x28)
                    {
                        MPlayStart(&gMPlayInfo_SE1, &se_unk_8b);
                    }
                    gCurrentPinballGame->bannerAnimPhase--;
                    if (gCurrentPinballGame->bannerAnimPhase <= 0xF)
                    {
                        gCurrentPinballGame->bannerScrollPosQ10 += 0xA0;
                    }
                    if (gCurrentPinballGame->bannerAnimPhase > 32 && gCurrentPinballGame->bannerAnimPhase <= 40)
                    {
                        if (gCurrentPinballGame->bannerAnimPhase <= 36)
                        {
                            gMain.blendBrightness = 7;
                            if (gCurrentPinballGame->bannerAnimPhase < 36)
                            {

                                if ((gCurrentPinballGame->boardEntryMode == 3 && gCurrentPinballGame->trapDisplayState == 1) ||
                                    (gCurrentPinballGame->boardEntryMode == 4 && gCurrentPinballGame->slotReelResult == 9))
                                {
                                    gCurrentPinballGame->fieldScrollState = 0;
                                }
                                else
                                {
                                    gCurrentPinballGame->fieldScrollState = 1;
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2], (void *)(OBJ_PLTT), 0x20);
                                }
                                if (gMain.selectedField == FIELD_SAPPHIRE)
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                                }
                                else
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                                }
                                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                                gCurrentPinballGame->paletteCycleIndex = 2;
                            }
                        }
                        else if (gCurrentPinballGame->bannerAnimPhase > 0x24)
                        {
                            gMain.blendBrightness = 4;
                            if (gCurrentPinballGame->bannerAnimPhase <= 0x27)
                            {
                                if ((gCurrentPinballGame->boardEntryMode == 3 && gCurrentPinballGame->trapDisplayState == 1) ||
                                    (gCurrentPinballGame->boardEntryMode == 4 && gCurrentPinballGame->slotReelResult == 9))
                                {
                                    gCurrentPinballGame->fieldScrollState = 0;
                                }
                                else
                                {
                                    gCurrentPinballGame->fieldScrollState = 1;
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1], (void *)(OBJ_PLTT), 0x20);
                                }
                                if (gMain.selectedField == FIELD_SAPPHIRE)
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                                }
                                else
                                {
                                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                                }
                                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                                gCurrentPinballGame->paletteCycleIndex = 1;
                            }
                        }
                    }
                    if (gCurrentPinballGame->bannerAnimPhase == 0)
                    {
                        gCurrentPinballGame->bannerScrollPosQ10 = 0;
                        gCurrentPinballGame->bannerScrollVelocity = 0x3C;
                    }
                }
                spriteGroup->baseX = (gCurrentPinballGame->bannerScrollPosQ10 / 10) + 127;
                spriteGroup->baseY = 44;
            }
            else if (gCurrentPinballGame->bannerAnimPhase < 30)
            {
                gCurrentPinballGame->bannerScrollPosQ10 += gCurrentPinballGame->bannerScrollVelocity;
                spriteGroup->baseX = (gCurrentPinballGame->bannerScrollPosQ10 / 10) + 127;
                spriteGroup->baseY = 44;

                gCurrentPinballGame->bannerAnimPhase++;
                gCurrentPinballGame->bannerScrollVelocity -= 0xA;
                if (gCurrentPinballGame->bannerAnimPhase > 0x18 &&
                    (gCurrentPinballGame->boardEntryMode != 3 || gCurrentPinballGame->trapDisplayState != 1) &&
                    (gCurrentPinballGame->boardEntryMode != 4 || gCurrentPinballGame->slotReelResult != 9))
                {
                    gMain.blendBrightness = 4;
                    if (gCurrentPinballGame->bannerAnimPhase > 0x19)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1], (void *)(OBJ_PLTT), 0x20);
                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                        }
                        else
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                        }
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                        gCurrentPinballGame->paletteCycleIndex = 1;
                        gCurrentPinballGame->fieldScrollState = 1;
                    }
                    if (gCurrentPinballGame->bannerAnimPhase == 0x1D)
                    {
                        gMain.blendBrightness = 0;
                    }
                }
                if (gCurrentPinballGame->bannerAnimPhase == 0x1E)
                {
                    gMain.boardSpriteGroups[11]->available = 0;
                    gCurrentPinballGame->bannerGfxVariant = 0;
                    gCurrentPinballGame->bannerType = 0;
                    if ((gCurrentPinballGame->boardEntryMode != 3 || gCurrentPinballGame->trapDisplayState != 1) &&
                        (gCurrentPinballGame->boardEntryMode != 4 || gCurrentPinballGame->slotReelResult != 9))
                    {
                        gMain.blendBrightness = 0;
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0], (void *)(OBJ_PLTT), 0x20);
                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xC0);
                        }
                        else
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);
                        }
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                        gCurrentPinballGame->paletteCycleIndex = 0;
                        gCurrentPinballGame->fieldScrollState = 1;
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
            *dst++ = gUnknown_086B4568[sp00][i * 3 + 0];
            *dst++ = gUnknown_086B4568[sp00][i * 3 + 1];
            *dst++ = gUnknown_086B4568[sp00][i * 3 + 2];

            gOamBuffer[simple->oamId].x = gOamBuffer[simple->oamId].x + spriteGroup->baseX;
            gOamBuffer[simple->oamId].y = gOamBuffer[simple->oamId].y + spriteGroup->baseY;
        }
        return;
    }
    spriteGroup->available = 1;
    return;
}
