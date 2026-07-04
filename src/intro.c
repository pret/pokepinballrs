#include "global.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"
#include "titlescreen.h"
#include "constants/bg_music.h"

void IntroScene3_InitVars(void);
void IntroScene3_RenderPokeball(void);
void IntroScene4_InitVars(void);
void IntroScene5_InitVars(void);
extern void IntroScene5_RenderAllSprites(void);
void IntroScene6_InitVars(void);
void IntroScene6_RenderStarSprites(void);
void IntroScene7_InitVars(void);
void IntroScene7_RenderWailmer(void);
void IntroScene8a_InitVars(void);
void IntroScene8a_RenderAllSprites(void);
void IntroScene8b_InitVars(void);
void IntroScene8b_RenderBallAndCloud(void);

extern StateFunc gIntroStateFuncs[15];
extern u8 gIntroCopyright_Tilemap[];

extern u8 gIntroCopyright_Gfx[];
extern u8 gIntroCopyright_Pal[];
extern u8 gIntroScene1Sprites_Gfx[];
extern u8 gIntroScene1Sprites_Pals[];

extern u8 gIntroScene1_BG0Tilemap[];
extern u8 gIntroScene1_BG1Tilemap[];
extern u8 gIntroScene1_BG2Tilemap[];
extern u8 gIntroScene1_BG3Tilemap[];
extern u8 gIntroScene1Text_Gfx[];
extern u8 gIntroScene1Ball_Gfx[];
extern s16 gIntroScene1_TileOffsets[0x8];

extern u16 gIntroTileBuffer[];
extern s16 gIntroBGParams[];
extern s16 gIntroFrameCounter;
extern u8 gIntroBlendSrc;
extern u8 gIntroBlendDst;
extern s16 gIntroOverlayFadeStep;
extern s32 gIntroScaleX;
extern s32 gIntroScaleY;
extern s16 gIntroAnimStep;
extern s32 gIntroPalFadeLevel;
extern s8 gIntroJingleVariant;
extern s8 gIntroSceneIndex;
extern u8 gIntroPalSwapBuffer[];

extern u8 gIntroScene2_BG3Tilemap[];
extern u8 gIntroScene2Sprites_Gfx[];
extern u8 gIntroScene2_Pal[];
extern u8 gIntroScene2_BG0Tiles[];
extern u8 gIntroScene2_BG1Tiles[];

extern u8 gIntroScene3_AltBG1TilemapBuffer[];

extern u8 gIntroScene3_Pal[];
extern u8 gIntroScene3_BG0Tilemap[];
extern u8 gIntroScene3_BG1Tilemap[];
extern u8 gIntroScene3_BG2Tilemap[];
extern u8 gIntroScene3_BG3Tilemap[];
extern u8 gIntroScene3Sprites_Gfx[];
extern u8 gIntroScene3_BG1TilemapA[];
extern u8 gIntroScene3_BG1TilemapB[];
extern u8 gIntroScene3Treecko_Gfx[];
extern const struct SpriteSet *const gIntroScene8b_SpriteSets[];

typedef void (*IntroFunc)(void);
extern const IntroFunc gIntroSceneFuncs[];

struct UnkStruct_0201A450
{
    u16 posX;
    s16 posY;
    u16 velX;
    s16 velY;
    s16 animFrame;
    s16 frameTimer;
    s8 visible;
}; // 0x10 size in memory
extern struct UnkStruct_0201A450 gIntroSpriteEntities[6];

extern struct Vector16 gIntroScene1_BGAnimTiming[0x8];
extern struct Vector16 gIntroScene1_ScaleOffsets[0x4];
extern struct Vector16 gIntroScene5_BGAnimTiming[];
extern struct Vector16 gIntroScene7_WailmerQuadOffsets[0x4];

struct IntroAnimVelocity {
    s8 velocityX;
    s8 velocityY;
    s8 frameDuration;
    s8 spawnFrame;
};

extern struct IntroAnimVelocity gIntroScene6_ScrollVelocity[];
extern struct IntroAnimVelocity gIntroScene6_EntityMovement[];

extern const struct SpriteSet *const gIntroScene8a_SpriteSets[];

struct IntroDebrisMovement
{
    u8 earlyVelX;
    u8 earlyVelY;
    u8 lateVelX;
    u8 lateVelY;
    u8 filler4;
    u8 oamPriority;
}; // 0x8 size in memory
extern const struct IntroDebrisMovement gIntroScene8a_DebrisMovement[];

void IntroMain(void)
{
     gIntroStateFuncs[gMain.subState]();
}

void Intro_State0_929C(void)
{
  ResetDisplayState();
  REG_DISPCNT = 0x80;
  REG_BG1CNT = 5;
  REG_DISPCNT |= DISPCNT_BG1_ON;

  DmaCopy16(3, gIntroCopyright_Tilemap, BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
  DmaCopy16(3, gIntroCopyright_Gfx, BG_CHAR_ADDR(1), BG_SCREEN_SIZE);
  DmaCopy16(3, gIntroCopyright_Pal, BG_PLTT, BG_PLTT_SIZE);

  gMain.dispcntBackup = REG_DISPCNT;
  gIntroFrameCounter = 0;
  gIntroSceneIndex = 0;

  SetMainCallback(IntroVBlankCallback + 1);
  EnableVBlankInterrupts();
  FadeInScreen();
  gMain.subState++;
}

void Intro_State1_9348(void)
{
    gIntroFrameCounter++;
    if (gIntroFrameCounter > 0x78)
    {
        gIntroFrameCounter = 0;
        gMain.subState++;
    }
}

void Intro_State2_9370(void)
{
    FadeOutToBlack(NULL);
    DisableVBlankInterrupts();
    gMain.subState++;
}

void Intro_State3_938C(void)
{
    gIntroSceneFuncs[gIntroSceneIndex]();
    gIntroFrameCounter++;
    if (JOY_NEW(A_BUTTON | START_BUTTON))
        gMain.subState = 4;
}

void Intro_State4_93D0(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    ResetMainCallback();
    gAutoDisplayTitlescreenMenu = FALSE;
    SetMainGameState(STATE_TITLE);
}


// ? Main callback for intro state?
void IntroVBlankCallback(void)
{
    if (REG_DISPSTAT & DISPSTAT_VBLANK_INTR)
    {
        m4aSoundMain();
        VBlankIntrWait();
        DmaCopy32(3, gOamBuffer, (void *)OAM, OAM_SIZE);
        REG_DISPCNT = gMain.dispcntBackup;
        REG_BG0HOFS = gMain.bgOffsets[0].xOffset;
        REG_BG0VOFS = gMain.bgOffsets[0].yOffset;
        REG_BG1HOFS = gMain.bgOffsets[1].xOffset;
        REG_BG1VOFS = gMain.bgOffsets[1].yOffset;
        REG_BG2HOFS = gMain.bgOffsets[2].xOffset;
        REG_BG2VOFS = gMain.bgOffsets[2].yOffset;
        REG_BG3HOFS = gMain.bgOffsets[3].xOffset;
        REG_BG3VOFS = gMain.bgOffsets[3].yOffset;
    }
}

void IntroScene1_LoadGraphics(void)
{
    ClearGraphicsMemory();
    ClearBgTilemapAndOffsets();
    ClearSprites();

    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = 0xD0 << 5;
    REG_DISPCNT |= (DISPCNT_BG0_ON);
    REG_BG1CNT = 0x5B01;
    REG_DISPCNT |= (DISPCNT_BG1_ON);
    REG_BG2CNT = 0x5d02;
    REG_DISPCNT |= (DISPCNT_BG2_ON);
    REG_BG3CNT = 0x1f03;
    REG_DISPCNT |= (DISPCNT_BG3_ON);

    DmaCopy16(3, gIntroScene1_BG0Tilemap, 0x0600d000, BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene1_BG1Tilemap, 0x0600d800, 0x1000);
    DmaCopy16(3, gIntroScene1_BG2Tilemap, 0x0600e800 , 0x1000);
    DmaCopy16(3, gIntroScene1_BG3Tilemap, 0x0600f800 , BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene1Text_Gfx, BG_CHAR_ADDR(0), 0x5800);
    DmaCopy16(3, gIntroScene1Ball_Gfx, gIntroTileBuffer, 0x6800);
    DarkenPalette(gIntroScene1Sprites_Pals, (void*)BG_PLTT, BG_PLTT_SIZE, 0x20);
    DmaCopy16(3, gIntroScene1Sprites_Gfx, BG_CHAR_ADDR(4), 0x8000);
    DmaCopy16(3, gIntroScene1Sprites_Pals, 0x05000200, BG_PLTT_SIZE);
    IntroScene1_InitVars();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[18];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[19];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[6];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[13];
    EnableVBlankInterrupts();
    FadeInWithCustomPalettes((void*)BG_PLTT, gIntroScene1Sprites_Pals, NULL);
    DmaCopy16(3, gIntroScene1Sprites_Pals, 0x05000200, BG_PLTT_SIZE);
    DmaCopy16(3, 0, 0x05000200, 0x20);
    gIntroSceneIndex++;
}

void IntroScene1_InitVars(void)
{
    gIntroSpriteEntities[1].posX = 0x78;
    gIntroSpriteEntities[1].posY = 0x50;
    gIntroSpriteEntities[1].animFrame = 0;
    gIntroSpriteEntities[1].visible = 1;
    gIntroSpriteEntities[3].posX = 0x9c;
    gIntroSpriteEntities[3].posY = 0x92;
    gIntroSpriteEntities[3].visible = 0;
    gIntroSpriteEntities[3].frameTimer = 0;
    gIntroSpriteEntities[2].posX = 0x9d;
    gIntroSpriteEntities[2].posY = 0x93;
    gIntroSpriteEntities[2].visible = 0;
    gIntroSpriteEntities[4].posX = 0x80;
    gIntroSpriteEntities[4].posY = 0x80;
    gIntroSpriteEntities[4].visible = 1;
    gIntroBGParams[0] = 0xffa8;
    gIntroBGParams[1] = 0xffca;
    gIntroBGParams[4] = 0;
    gIntroBGParams[5] = 0;
    gIntroBGParams[6] = 0x100;
    gIntroBGParams[7] = 0;
    gIntroBGParams[10] = 0;
    gIntroBGParams[18] = 0xfb;
    gIntroBGParams[19] = 0;
    gIntroBGParams[22] = 0;
    gIntroBGParams[12] = 0;
    gIntroBGParams[13] = 0;
    gIntroSpriteEntities[0].posX = 0x78;
    gIntroSpriteEntities[0].posY = 0x50;
    gIntroSpriteEntities[0].animFrame = 0;
    gIntroSpriteEntities[0].frameTimer = 0;
    gIntroSpriteEntities[0].visible = 1;
    gIntroBlendSrc = 0;
    gIntroBlendDst = 0x10;
    gIntroOverlayFadeStep = 0;
    gIntroScaleX = 0x100;
    gIntroScaleY = 0x100;
    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
    gIntroPalFadeLevel = 0x20;
    gIntroJingleVariant = 8;
}

void IntroScene1_AnimateTitleReveal(void)
{
    IntroScene1_RenderTitleSprite();
    if (gIntroSpriteEntities[0].animFrame == 0x24)
    {
        if (++gIntroSpriteEntities[0].frameTimer > 27)
        {
            gIntroSpriteEntities[0].frameTimer = 0;
            gIntroAnimStep = 0;
            gIntroSceneIndex++;
        }
    }
    else
    {
        if (++gIntroSpriteEntities[0].frameTimer > 1)
        {
            gIntroSpriteEntities[0].frameTimer = 0;
            gIntroSpriteEntities[0].animFrame++;
        }

        if (gIntroFrameCounter >= gTitleRevealJingle[gIntroJingleVariant][gIntroAnimStep][1])
        {
            m4aSongNumStart(gTitleRevealJingle[gIntroJingleVariant][gIntroAnimStep][0]);
            gIntroAnimStep++;
        }
    }
}

void IntroScene1_ZoomOutTitle(void)
{
    gIntroScaleX -= 0x10;
    gIntroScaleY -= 0x10;
    gIntroSpriteEntities[0].posX--;

    if (gIntroScaleX < 0x20)
    {
        gIntroSpriteEntities[0].frameTimer = 0;
        gIntroSpriteEntities[0].animFrame = 0x25;
        gIntroSceneIndex++;
    }

    IntroScene1_RenderScaledTitle();
}

void IntroScene1_ResetAfterZoom(void)
{
    if (++gIntroSpriteEntities[0].frameTimer > 3)
    {
        gIntroSpriteEntities[0].frameTimer = 0;
        gIntroSpriteEntities[0].posX = 0x78;
        gIntroSpriteEntities[0].posY = 0x58;
        gIntroSpriteEntities[0].visible = 1;
        m4aSongNumStart(SE_RAMP_PRIZE_COLLECTED);
        gIntroSceneIndex++;
    }
}

void IntroScene1_AnimateSecondReveal(void)
{
    if (gIntroSpriteEntities[0].animFrame == 43)
    {
        if (++gIntroSpriteEntities[0].frameTimer > 1)
        {
            gIntroSpriteEntities[0].visible = 0;
            DarkenPalette(&gIntroScene1Sprites_Pals[0x1C0], (void*)BG_PLTT + 0xE0, 0x20, 0);
            m4aSongNumStart(MUS_OPENING);
            gIntroSceneIndex++;
        }
    }
    else
    {
        if (++gIntroSpriteEntities[0].frameTimer > 1)
        {
            gIntroSpriteEntities[0].frameTimer = 0;
            gIntroSpriteEntities[0].animFrame++;
        }
    }

    IntroScene1_RenderTitleSprite();
}

void IntroScene1_FadeInOverlay(void)
{
    int remainder;

    remainder = gIntroFrameCounter % 3;
    if (remainder == 0)
    {
        if (gIntroOverlayFadeStep < 8)
        {
            gIntroOverlayFadeStep++;
            gIntroBlendSrc++;
            gIntroBlendDst--;
        }
        else
        {
            CopyBgTilesRect(&gIntroTileBuffer, (void *)0x60036e0, 8, 8);
            gIntroSceneIndex++;
        }

        gIntroSpriteEntities[1].animFrame = 1 - gIntroSpriteEntities[1].animFrame;
    }

    IntroScene1_RenderAllSprites();
}

void IntroScene1_ScrollAndFade(void)
{
    if (gIntroPalFadeLevel > 0)
    {
        gIntroPalFadeLevel -= 2;
        if (gIntroPalFadeLevel < 1)
        {
            gIntroPalFadeLevel = 0;
        }
        DarkenPalette(gIntroScene1Sprites_Pals, (void*)BG_PLTT, 0x200, gIntroPalFadeLevel);
        DarkenPalette(gIntroScene1Sprites_Pals, (void*)OBJ_PLTT, 0x20, gIntroPalFadeLevel);
    }

    if (gIntroFrameCounter % 3 == 0)
        gIntroSpriteEntities[1].animFrame = 1 - gIntroSpriteEntities[1].animFrame;

    gIntroBGParams[0]--;

    if (gIntroFrameCounter % 2 == 0)
        gIntroBGParams[1]--;

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[1];
    if (++gIntroBGParams[5] > gIntroScene1_BGAnimTiming[gIntroBGParams[4]].y)
    {
        CopyBgTilesRect(&gIntroTileBuffer[gIntroScene1_TileOffsets[gIntroBGParams[4]]], (void *)0x60036E0, 8, 8);
        if (++gIntroBGParams[4] > 3)
        {
            gIntroSpriteEntities[3].visible = 1;
            gIntroSpriteEntities[2].visible = 1;
            gIntroSpriteEntities[1].visible = 0;
            gIntroBGParams[10] = 0;
            gIntroSceneIndex++;
        }
    }

    IntroScene1_RenderAllSprites();
}

void IntroScene1_ParallaxScroll(void)
{
    gIntroSpriteEntities[3].posX -= 0xE;
    gIntroSpriteEntities[3].posY -= 0xD;

    gIntroBGParams[0x12] -= 0x10;
    gIntroBGParams[0x13]++;
    gIntroBGParams[0x6]  -= 0x10;

    gIntroSpriteEntities[2].posX -= 0xE;
    gIntroSpriteEntities[2].posY -= 0xD;
    gIntroSpriteEntities[4].posX += 0xB;
    gIntroSpriteEntities[4].posY -= 0x2;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0x0]--;
        gIntroBGParams[0x1]--;
    }

    if (++gIntroBGParams[5] > gIntroScene1_BGAnimTiming[gIntroBGParams[4]].y)
    {
        if (gIntroBGParams[4] < 7)
            CopyBgTilesRect(&gIntroTileBuffer[gIntroScene1_TileOffsets[gIntroBGParams[0x4]]], (void *)0x60036e0, 8, 8);
        else
            CopyBgTilesRect(&gIntroTileBuffer[gIntroScene1_TileOffsets[gIntroBGParams[0x4]]], (void *)0x60032c0, 10, 10);

        gIntroBGParams[0x4]++;
    }

    gIntroBGParams[0xA]++;
    if (gIntroBGParams[0xA] > 9)
    {
        gIntroBGParams[0xA] = 0;
        gIntroSceneIndex += 2;
    }

    IntroScene1_RenderAllSprites();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x13];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0x7];
}

void nullsub_4(void)
{
}

void IntroScene1_FinalScroll(void)
{
    gIntroBGParams[0xC]++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroSpriteEntities[3].posX--;
        gIntroSpriteEntities[3].posY--;
        gIntroSpriteEntities[2].posX -= 2;
        gIntroSpriteEntities[2].posY -= 2;
    }

    IntroScene1_RenderAllSprites();

    gMain.bgOffsets[3].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0xD];
    gIntroSpriteEntities[3].frameTimer++;

    if (gIntroSpriteEntities[3].frameTimer > 0x14)
    {
        gIntroSpriteEntities[3].frameTimer = 0;
        gIntroSceneIndex += 3;
    }
}

void nullsub_5(void)
{
}

void nullsub_17(void)
{
}

void IntroScene1_BeginFadeOut(void)
{
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene1_RenderTitleSprite(void)
{
    s32 i;
    struct OamDataSimple *test2;
    struct SpriteGroup *puVar4;
    const struct SpriteSet *puVar6;

    puVar4 = &gMain.spriteGroups[4 + gIntroSpriteEntities[0].animFrame];
    puVar4->active = gIntroSpriteEntities[0].visible;
    LoadSpriteSets(gIntroScene1_SpriteSets, 0x31, gMain.spriteGroups);

    if (puVar4->active == TRUE)
    {
        puVar4->baseX = gIntroSpriteEntities[0].posX;
        puVar4->baseY = gIntroSpriteEntities[0].posY;

        puVar6 = gIntroScene1_SpriteSets[gIntroSpriteEntities[0].animFrame + 4];
        for (i = 0; i < puVar6->count; i++)
        {
            test2 = &puVar4->oam[i];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar4->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar4->baseY;
        }
    }

    puVar4->active = FALSE;
}

void IntroScene1_RenderScaledTitle(void)
{
    s32 i;
    struct SpriteGroup *puVar4;
    struct OamDataSimple *puVar2;

    puVar4 = &gMain.spriteGroups[40];
    puVar4->active = gIntroSpriteEntities[0].visible;
    LoadSpriteSets(gIntroScene1_SpriteSets, 0x31, gMain.spriteGroups);

    if (puVar4->active == TRUE)
    {
        SetMatrixScale(gIntroScaleX, gIntroScaleY, 0);
        puVar4->baseX = gIntroSpriteEntities[0].posX;
        puVar4->baseY = gIntroSpriteEntities[0].posY;

        for (i = 0; i < 4; i++)
        {
            puVar2 = &puVar4->oam[i];
            gOamBuffer[puVar2->oamId].x = gIntroScene1_ScaleOffsets[i].x * gIntroScaleX / 0x100 + puVar4->baseX;
            gOamBuffer[puVar2->oamId].y = gIntroScene1_ScaleOffsets[i].y * gIntroScaleY / 0x100 + puVar4->baseY;

            gOamBuffer[puVar2->oamId].affineMode = 1;
            gOamBuffer[puVar2->oamId].matrixNum = 0;
        }
    }
    puVar4->active = FALSE;
}

void IntroScene1_RenderAllSprites(void)
{
    struct OamDataSimple *puVar5;
    struct SpriteGroup *puVar1;
    struct SpriteGroup *mainSg3;
    struct SpriteGroup *mainSg2;
    struct SpriteGroup *otherSg;
    int i;
    const u16 *p; // TODO Fakematch

    gMain.blendControl = 0xF10;
    gMain.blendAlpha = gIntroBlendSrc | (gIntroBlendDst << 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    puVar1 = &gMain.spriteGroups[gIntroSpriteEntities[1].animFrame];
    mainSg3 = &gMain.spriteGroups[3];
    mainSg2 = &gMain.spriteGroups[2];
    otherSg = &gMain_spriteGroups_48;

    puVar1->active = gIntroSpriteEntities[1].visible;
    mainSg3->active = gIntroSpriteEntities[2].visible;
    mainSg2->active = gIntroSpriteEntities[3].visible;
    otherSg->active = gIntroSpriteEntities[4].visible;
    LoadSpriteSets(gIntroScene1_SpriteSets, 0x31, gMain.spriteGroups);

    if (puVar1->active == TRUE)
    {
        puVar1->baseX = gIntroSpriteEntities[1].posX;
        puVar1->baseY = gIntroSpriteEntities[1].posY;
        p = &gIntroScene1_SpriteSets[gIntroSpriteEntities[1].animFrame]->count;

        for (i = 0;
            i < *p;
            i++)
        {
            puVar5 = &puVar1->oam[i];
            gOamBuffer[puVar5->oamId].objMode = 1;
            gOamBuffer[puVar5->oamId].x = puVar1->oam[i].xOffset + puVar1->baseX;
            gOamBuffer[puVar5->oamId].y = puVar1->oam[i].yOffset + puVar1->baseY;
        }
    }
    if (mainSg3->active == TRUE)
    {
        mainSg3->baseX = gIntroSpriteEntities[2].posX;
        mainSg3->baseY = gIntroSpriteEntities[2].posY;

        for (i = 0; i < 4; i++)
        {
            puVar5 = &mainSg3->oam[i];
            gOamBuffer[puVar5->oamId].objMode = 1;
            gOamBuffer[puVar5->oamId].priority = 1;
            gOamBuffer[puVar5->oamId].x = mainSg3->oam[i].xOffset + mainSg3->baseX;
            gOamBuffer[puVar5->oamId].y = mainSg3->oam[i].yOffset + mainSg3->baseY;
        }
    }
    if (mainSg2->active == TRUE)
    {
        mainSg2->baseX = gIntroSpriteEntities[3].posX;
        mainSg2->baseY = gIntroSpriteEntities[3].posY;

        for (i = 0; i < 4; i++)
        {
            puVar5 = &mainSg2->oam[i];
            gOamBuffer[puVar5->oamId].objMode = 0;
            gOamBuffer[puVar5->oamId].priority = 1;
            gOamBuffer[puVar5->oamId].x = mainSg2->oam[i].xOffset + mainSg2->baseX;
            gOamBuffer[puVar5->oamId].y = mainSg2->oam[i].yOffset + mainSg2->baseY;
        }
    }
    if (otherSg->active == TRUE)
    {
        otherSg->baseX = gIntroSpriteEntities[4].posX;
        otherSg->baseY = gIntroSpriteEntities[4].posY;

        for (i = 0; i < 8; i++)
        {
            puVar5 = &otherSg->oam[i];
            gOamBuffer[puVar5->oamId].priority = 2;
            gOamBuffer[puVar5->oamId].x = otherSg->oam[i].xOffset + otherSg->baseX;
            gOamBuffer[puVar5->oamId].y = otherSg->oam[i].yOffset + otherSg->baseY;
        }
    }

    puVar1->active = FALSE;
    mainSg3->active = FALSE;
    mainSg2->active = FALSE;
    otherSg->active = FALSE; // TODO Possible Bug?
}

void IntroScene1_ClearGraphics(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene2_LoadGraphics(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0;
    REG_BG0CNT = 0xCC00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0xDA01;
    REG_DISPCNT |= 0x200;
    REG_BG3CNT = 0x1E03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gIntroScene2_BG0Tiles, (void*) 0x06006000, 0x2000);
    DmaCopy16(3, gIntroScene2_BG1Tiles, (void*) 0x0600D000, 0x2000);
    DmaCopy16(3, gIntroScene2_BG3Tilemap, (void*) 0x0600F000, 0x800);
    DmaCopy16(3, gIntroScene2Sprites_Gfx, (void*) 0x06000000, 0x3C00);
    DmaCopy16(3, gIntroScene2_Pal, (void*) PLTT, 0x80);
    IntroScene2_InitVars();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0xD];
    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex += 2;
}

void IntroScene2_InitVars(void)
{
    gIntroBGParams[0x0] = 0x1C;
    gIntroBGParams[0x1] = 0xFF2C;
    gIntroBGParams[0x2] = 0;
    gIntroBGParams[0x3] = 0xE;
    gIntroBGParams[0x6] = 0xFF5C;
    gIntroBGParams[0x7] = 0xFF08;
    gIntroBGParams[0x8] = 0;
    gIntroBGParams[0x9] = 0x10;
    gIntroBGParams[0xC] = 0;
    gIntroBGParams[0xD] = 0;
    gIntroBGParams[0x10] = 0;
    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void nullsub_6(void)
{
}

void IntroScene2_ScrollBGs(void)
{
    gIntroBGParams[0x1] += gIntroBGParams[0x3];
    gIntroBGParams[0x7] += gIntroBGParams[0x9];
    gIntroBGParams[0xC]--;
    gIntroBGParams[0xD]--;
    gIntroBGParams[0x0]--;
    gIntroBGParams[0x6]++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0x3]--;
        gIntroBGParams[0x9]--;
    }

    // TODO same as IntroScene2_LoadGraphics - possible inline function?
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0xD];

    gIntroBGParams[0x10]++;
    if (gIntroBGParams[0x10] > 0x27)
    {
        gIntroBGParams[0x10] = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_7(void)
{
}

void IntroScene2_FinalScrollAndFade(void)
{
    gIntroBGParams[0x1]++;
    gIntroBGParams[0x7]++;
    gIntroBGParams[0xC]--;
    gIntroBGParams[0xD]--;
    gIntroBGParams[0x0]--;
    gIntroBGParams[0x6]++;

    // TODO same as IntroScene2_ScrollBGs - possible inline function?
    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0x3]--;
        gIntroBGParams[0x9]--;
    }

    // TODO same as IntroScene2_LoadGraphics - possible inline function?
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0xD];

    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene2_ClearGraphics(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene3_LoadGraphics(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0x1000;
    REG_BG0CNT = 0x5A00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0x1C01;
    REG_DISPCNT |= 0x200;
    REG_BG2CNT = 0x5D02;
    REG_DISPCNT |= 0x400;
    REG_BG3CNT = 0x1F03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gIntroScene3_BG0Tilemap, (void*) 0x0600D000, 0x1000);
    DmaCopy16(3, gIntroScene3_BG1Tilemap, (void*) 0x0600E000, 0x800);
    DmaCopy16(3, gIntroScene3_BG2Tilemap, (void*) 0x0600E800, 0x1000);
    DmaCopy16(3, gIntroScene3_BG3Tilemap, (void*) 0x0600F800, 0x800);
    DmaCopy16(3, gIntroScene3_BG1TilemapA, gBG0TilemapBuffer, 0x800);
    DmaCopy16(3, gIntroScene3_BG1TilemapB, gIntroScene3_AltBG1TilemapBuffer, 0x800);
    DmaCopy16(3, gIntroScene3Sprites_Gfx, (void*) 0x06000000, 0x6C00);
    DmaCopy16(3, gIntroScene3_Pal, (void*) PLTT, 0xE0);
    DmaCopy16(3, gIntroScene3Treecko_Gfx, (void*) 0x06010000, 0x2000);
    DmaCopy16(3, gIntroScene3_Pal, (void*) OBJ_PLTT, 0xE0);

    IntroScene3_InitVars();
    IntroScene3_RenderPokeball();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene3_InitVars(void)
{
    gIntroBGParams[0x0] = 0x2C;
    gIntroBGParams[0x1] = 0xFF8E;

    gIntroSpriteEntities[0].posX = 0xFFD4;
    gIntroSpriteEntities[0].posY = 0x72;

    gIntroBGParams[0x6] = 0xFFCE;
    gIntroBGParams[0x7] = 0x1E;
    gIntroBGParams[0xC] = 0;
    gIntroBGParams[0xD] = 0;
    gIntroBGParams[0x10] = 0;
    gIntroBGParams[0x12] = 0;
    gIntroBGParams[0x13] = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void IntroScene3_ScrollIn(void)
{
    gIntroBGParams[0x0] -= 0x11;
    gIntroBGParams[0x1] += 0xA;

    gIntroSpriteEntities[0].posX += 0x11;
    gIntroSpriteEntities[0].posY -= 0xA;

    gIntroBGParams[0xC] += 0x10;
    gIntroBGParams[0x6] += 0x4;
    gIntroBGParams[0x7] -= 0x8;
    gIntroBGParams[0x10]++;

    if (gIntroBGParams[0x10] > 9)
    {
        gIntroBGParams[0x10] = 0;
        gIntroSceneIndex++;
    }

    IntroScene3_RenderPokeball();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
}

void IntroScene3_AnimateAndSwapBG(void)
{
    gIntroBGParams[0x12]--;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0x0]--;
        gIntroBGParams[0x1]++;
        gIntroSpriteEntities[0].posX += 2;
        gIntroSpriteEntities[0].posY -= 2;
    }
    if (gIntroFrameCounter % 3 == 0)
    {
        DmaCopy16(3, (void *) 0x05000000, gIntroPalSwapBuffer, 0x20);
        DmaCopy16(3, (void *) 0x05000040, 0x05000000, 0x20);
        DmaCopy16(3, (void *) gIntroPalSwapBuffer, 0x05000040, 0x20);
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];
    IntroScene3_RenderPokeball();

    if (gIntroBGParams[0x10] == 2)
    {
        DmaCopy16(3, gBG0TilemapBuffer, (void*) 0x0600E000, 0x800);
        gIntroBGParams[0x6] = 0;
        gIntroBGParams[0x7] = 0;
        gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
        gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    }
    else if (gIntroBGParams[0x10] == 4)
    {
        DmaCopy16(3, gIntroScene3_AltBG1TilemapBuffer, (void*) 0x0600E000, 0x800);
        gIntroBGParams[0x6] = 0;
        gIntroBGParams[0x7] = 0;
        gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
        gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    }

    gIntroBGParams[0x10]++;
    if (gIntroBGParams[0x10] > 0x1D)
    {
        gIntroBGParams[0x10] = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_8(void)
{
}

void IntroScene3_BeginFadeOut(void)
{
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene3_RenderPokeball(void)
{
    s32 i;
    struct SpriteGroup *puVar4;
    struct OamDataSimple *puVar2;

    gMain.blendControl = 0x1F50;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    puVar4 = &gMain.spriteGroups[0];
    puVar4->active = TRUE;
    LoadSpriteSets(gIntroScene3_SpriteSets, 0x1, puVar4);

    if (puVar4->active == TRUE)
    {
        puVar4->baseX = gIntroSpriteEntities[0].posX;
        puVar4->baseY = gIntroSpriteEntities[0].posY;

        for (i = 0; i < 4; i++)
        {
            puVar2 = &puVar4->oam[i];
            gOamBuffer[puVar2->oamId].priority = 1;
            gOamBuffer[puVar2->oamId].x = puVar2->xOffset + puVar4->baseX;
            gOamBuffer[puVar2->oamId].y = puVar2->yOffset + puVar4->baseY;
        }
    }
    puVar4->active = FALSE;
}

void IntroScene3_ClearGraphics(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene4_LoadGraphics(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0;
    REG_BG0CNT = 0xCC00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0xDA01;
    REG_DISPCNT |= 0x200;
    REG_BG3CNT = 0x1E03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gIntroScene4_BG0Tiles, (void *) 0x6006000, 0x2000);
    DmaCopy16(3, gIntroScene4_BG1Tiles, (void *) 0x600D000, 0x2000);
    DmaCopy16(3, gIntroScene4_BG3Tilemap, (void *) 0x600F000, 0x800);
    DmaCopy16(3, gIntroScene4Sprites_Gfx, (void *) 0x6000000, 0x4000);
    DmaCopy16(3, gIntroScene4_Pal, PLTT, 0x60);
    gMain.dispcntBackup = REG_DISPCNT;

    IntroScene4_InitVars();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0xD];

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex += 2;
}

void IntroScene4_InitVars(void)
{
    gIntroBGParams[0x0] = 0x1C;
    gIntroBGParams[0x1] = 0xFF20;
    gIntroBGParams[0x2] = 0;
    gIntroBGParams[0x3] = 0xF;
    gIntroBGParams[0x6] = 0xFF64;
    gIntroBGParams[0x7] = 0xE0;
    gIntroBGParams[0x8] = 0;
    gIntroBGParams[0x9] = 0xFFF1;
    gIntroBGParams[0xC] = 0;
    gIntroBGParams[0xD] = 0;
    gIntroBGParams[0x10] = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void nullsub_9(void)
{
}

void IntroScene4_ScrollBGs(void)
{
    gIntroBGParams[0x1] += gIntroBGParams[0x3];
    gIntroBGParams[0x7] += gIntroBGParams[0x9];
    gIntroBGParams[0xC]--;
    gIntroBGParams[0x0]--;
    gIntroBGParams[0x6]++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0x3]--;
        gIntroBGParams[0x9]++;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0xC];

    gIntroBGParams[0x10]++;
    if (0x27 < gIntroBGParams[0x10])
    {
        gIntroBGParams[0x10] = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_10(void)
{
}

void IntroScene4_FinalScrollAndFade(void)
{
    // TODO Near duplicate of IntroScene4_ScrollBGs
    gIntroBGParams[0x1] += gIntroBGParams[0x3];
    gIntroBGParams[0x7] += gIntroBGParams[0x9];
    gIntroBGParams[0xC]--;
    gIntroBGParams[0x0]--;
    gIntroBGParams[0x6]++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0x3]--;
        gIntroBGParams[0x9]++;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0xC];

    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene4_ClearGraphics(void)
{
    // TODO Duplicate of IntroScene3_ClearGraphics?
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene5_LoadGraphics(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = 0x1000;
    REG_BG0CNT = 0xC00;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0x4E01;
    REG_DISPCNT |= 0x200;
    REG_BG2CNT = 0x5C02;
    REG_DISPCNT |= 0x400;
    REG_BG3CNT = 0x1E03;
    REG_DISPCNT |= 0x800;

    DmaCopy16(3, gIntroScene5_BG0Tiles, (void *) 0x6006000, 0x800);
    DmaCopy16(3, gIntroScene5_BG1Tiles, (void *) 0x6007000, 0x1000);
    DmaCopy16(3, gIntroScene5_BG2Tilemap, (void *) 0x600E000, 0x1000);
    DmaCopy16(3, gIntroScene5_BG3Tilemap, (void *) 0x600F000, 0x800);
    DmaCopy16(3, gIntroScene5Text_Gfx, (void *) 0x6000000, 0x2800);
    DmaCopy16(3, gIntroScene1Ball_Gfx, gTempGfxBuffer, 0x4000);
    DmaCopy16(3, gIntroScene5_Pal, (void *) 0x5000000, 0x180);
    DmaCopy16(3, gIntroScene5Sprites_Gfx, (void *) 0x6010000, 0x3000);
    DmaCopy16(3, gIntroScene5_Pal, OBJ_PLTT, 0x180);

    IntroScene5_InitVars();
    IntroScene5_RenderAllSprites();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene5_InitVars(void)
{
    gIntroSpriteEntities[1].posX = 0xB4;
    gIntroSpriteEntities[1].posY = 0xFFBC;
    gIntroSpriteEntities[0].posX = 0xB4;
    gIntroSpriteEntities[0].posY = 0xFFBC;
    gIntroSpriteEntities[2].posX = 0x80;
    gIntroSpriteEntities[2].posY = 0x88;

    gIntroBGParams[0x0] = 0xFF58;
    gIntroBGParams[0x1] = 0xFF98;
    gIntroBGParams[0x4] = 0;
    gIntroBGParams[0x5] = 0;
    gIntroBGParams[0x2] = 0;

    CopyBgTilesRect(&gTextTilemapBuffer, (void *) 0x6002ee0, 8, 8);

    gIntroBGParams[0x6] = 0xA5;
    gIntroBGParams[0x7] = 0;
    gIntroBGParams[0xA] = 0;
    gIntroBGParams[0xC] = 0xA0;
    gIntroBGParams[0xD] = 0;
    gIntroBGParams[0x10] = 0;
    gIntroBGParams[0x12] = 0;
    gIntroBGParams[0x13] = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void IntroScene5_ScrollIn(void)
{
    gIntroSpriteEntities[1].posX -= 0x10;
    gIntroSpriteEntities[1].posY += 0xA;
    gIntroSpriteEntities[0].posX -= 0x10;
    gIntroSpriteEntities[0].posY += 0xA;
    gIntroSpriteEntities[2].posX += 0x5;
    gIntroSpriteEntities[2].posY -= 0x3;

    gIntroBGParams[0x6] -= 0x10;
    gIntroBGParams[0x7]++;
    gIntroBGParams[0xC] -= 0x10;
    gIntroBGParams[0x0] += gIntroBGParams[0x2];
    gIntroBGParams[0x1] += 0x9;
    gIntroBGParams[0x2]++;
    gIntroBGParams[0x5]++;

    if (gIntroBGParams[0x5] > gIntroScene5_BGAnimTiming[gIntroBGParams[4]].y)
    {
        gIntroBGParams[4]++;
        CopyBgTilesRect(&gTempGfxBuffer[gIntroScene5_TileOffsets[gIntroBGParams[4]]], (void *) 0x6002EE0, 8, 8);
    }

    IntroScene5_RenderAllSprites();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];

    if (++gIntroBGParams[0x10] > 9)
    {
        gIntroBGParams[0x10] = 0;
        gIntroSceneIndex++;
    }
}

void IntroScene5_AnimateEntities(void)
{
    if (++gIntroBGParams[0x5] > gIntroScene5_BGAnimTiming[gIntroBGParams[0x4]].y)
    {
        if (gIntroBGParams[0x04] < 7)
        {
            gIntroBGParams[0x4]++;
            CopyBgTilesRect(&gTempGfxBuffer[gIntroScene5_TileOffsets[gIntroBGParams[0x4]]], (void *) 0x6002EE0, 8, 8);
        }
    }

    IntroScene5_RenderAllSprites();
    gIntroBGParams[0x12]++;
    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroSpriteEntities[1].posX--;
        gIntroSpriteEntities[1].posY++;
        gIntroSpriteEntities[0].posX -= 2;
        gIntroSpriteEntities[0].posY += 2;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    if (++gIntroBGParams[0x16] > 29)
    {
        gIntroBGParams[0x16] = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_11(void)
{
}

void IntroScene5_FadeOutAndClearOAM(void)
{
    FlashWhiteTransitionOut();
    ClearSprites();
    DmaFill32(3, 0, OAM, 0x400);
    DmaFill16(3, 0, OBJ_VRAM0, 0x5000);
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene5_RenderAllSprites(void)
{
    int i;
    struct OamDataSimple *oamData;
    struct SpriteGroup *mainSg1;
    struct SpriteGroup *mainSg0;
    struct SpriteGroup *mainSg2;

    gMain.blendControl = 0xF10;
    gMain.blendAlpha = BLDALPHA_BLEND(8, 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    mainSg1 = &gMain.spriteGroups[1];
    mainSg0 = &gMain.spriteGroups[0];
    mainSg2 = &gMain.spriteGroups[2];

    mainSg1->active = TRUE;
    mainSg0->active = TRUE;
    mainSg2->active = TRUE;
    LoadSpriteSets(gIntroScene5_SpriteSets, 3, gMain.spriteGroups);

    if (mainSg1->active == TRUE)
    {
        mainSg1->baseX = gIntroSpriteEntities[0].posX;
        mainSg1->baseY = gIntroSpriteEntities[0].posY;
        for (i = 0; i < 4; i++)
        {
            oamData = &mainSg1->oam[i];
            gOamBuffer[oamData->oamId].objMode = 1;
            gOamBuffer[oamData->oamId].priority = 1;
            gOamBuffer[oamData->oamId].x = mainSg1->oam[i].xOffset + mainSg1->baseX;
            gOamBuffer[oamData->oamId].y = mainSg1->oam[i].yOffset + mainSg1->baseY;
        }
    }

    if (mainSg0->active == TRUE)
    {
        mainSg0->baseX = gIntroSpriteEntities[1].posX;
        mainSg0->baseY = gIntroSpriteEntities[1].posY;
        for (i = 0; i < 4; i++)
        {
            oamData = &mainSg0->oam[i];
            gOamBuffer[oamData->oamId].objMode = 0;
            gOamBuffer[oamData->oamId].priority = 1;
            gOamBuffer[oamData->oamId].x = mainSg0->oam[i].xOffset + mainSg0->baseX;
            gOamBuffer[oamData->oamId].y = mainSg0->oam[i].yOffset + mainSg0->baseY;
        }
    }

    if (mainSg2->active == TRUE)
    {
        mainSg2->baseX = gIntroSpriteEntities[2].posX;
        mainSg2->baseY = gIntroSpriteEntities[2].posY;
        for (i = 0; i < 8; i++)
        {
            oamData = &mainSg2->oam[i];
            gOamBuffer[oamData->oamId].priority = 2;
            gOamBuffer[oamData->oamId].x = mainSg2->oam[i].xOffset + mainSg2->baseX;
            gOamBuffer[oamData->oamId].y = mainSg2->oam[i].yOffset + mainSg2->baseY;
        }
    }

    mainSg1->active = FALSE;
    mainSg0->active = FALSE;
    mainSg2->active = FALSE;
}

void IntroScene5_ClearGraphics(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene6_LoadGraphics(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = 0xF00;
    REG_DISPCNT |= (DISPCNT_BG0_ON);
    REG_BG1CNT = 0xDA01;
    REG_DISPCNT |= (DISPCNT_BG1_ON);
    REG_BG2CNT = 0x1E02;
    REG_DISPCNT |= (DISPCNT_BG2_ON);
    REG_BG3CNT = 0x1f03;
    REG_DISPCNT |= (DISPCNT_BG3_ON);

    DmaCopy16(3, gIntroScene6_BG0Tilemap, 0x06007800, 0x800);
    DmaCopy16(3, gIntroScene6_BG1Tiles, 0x0600D000, 0x2000);
    DmaCopy16(3, gIntroScene6_BG2Tilemap, 0x0600F000, 0x800);
    DmaCopy16(3, gIntroScene6_BG3Tilemap, 0x0600F800, 0x800);
    DmaCopy16(3, gIntroScene6Sprites_Gfx, 0x06000000, 0x6400);
    DmaCopy16(3, gIntroScene6_Pal, 0x05000000, 0x80);
    DmaCopy16(3, gIntroScene6Stars_Gfx, 0x06010000, 0x1000);
    DmaCopy16(3, gIntroScene6_Pal, 0x05000200, 0x80);

    IntroScene6_InitVars();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene6_InitVars(void)
{
    int i;

    gIntroBGParams[0x6] = 0x1E;
    gIntroBGParams[0x7] = 0xFF6A;
    gIntroBGParams[0xA] = 0x1;
    gIntroBGParams[0x0] = 0xFFFE;
    gIntroBGParams[0x1] = 0xFFFB;
    gIntroBGParams[0x2] = 0x0;
    gIntroBGParams[0x3] = 0x8;
    gIntroBGParams[0xC] = 0xFF90;
    gIntroBGParams[0xD] = 0xFFD4;
    gIntroBGParams[0xE] = 0x8;
    gIntroBGParams[0xF] = 0x0;
    gIntroBGParams[0x12] = 0x0;
    gIntroBGParams[0x13] = 0x0;

    gIntroSpriteEntities[0].posX = 0x32;
    gIntroSpriteEntities[0].posY = 0x3C;
    gIntroSpriteEntities[1].posX = 0x50;
    gIntroSpriteEntities[1].posY = 0x3C;
    gIntroSpriteEntities[2].posX = 0x8C;
    gIntroSpriteEntities[2].posY = 0x64;
    gIntroSpriteEntities[3].posX = 0xC8;
    gIntroSpriteEntities[3].posY = 0x5A;
    gIntroSpriteEntities[4].posX = 0x3C;
    gIntroSpriteEntities[4].posY = 0x1E;
    gIntroSpriteEntities[5].posX = 0x96;
    gIntroSpriteEntities[5].posY = 0x64;

    for (i = 0; i < 6; i++)
    {
        gIntroSpriteEntities[i].animFrame = 0;
        gIntroSpriteEntities[i].frameTimer = 0;
        gIntroSpriteEntities[i].visible = 0;
    }

    gIntroScene6VelocityIndex = 0;
    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
    gIntroScene6EntitySpawnIndex = 0;
}

void IntroScene6_AnimateStarsScrollIn(void)
{
    gIntroBGParams[0x6] += gIntroScene6_ScrollVelocity[gIntroScene6VelocityIndex].velocityX;
    gIntroBGParams[0x7] += gIntroScene6_ScrollVelocity[gIntroScene6VelocityIndex].velocityY;

    if (gIntroScene6_BounceFlags[gIntroFrameCounter] & 0x10)
    {
        gIntroBGParams[0x1] += gIntroBGParams[0x3];
        gIntroBGParams[0x3] -= 2;
        if (gIntroBGParams[0x3] <= -0xA)
            gIntroBGParams[0x3] = 0x8;
    }

    if (gIntroScene6_BounceFlags[gIntroFrameCounter] & 0x1)
    {
        gIntroBGParams[0xC] += gIntroBGParams[0xE];
        gIntroBGParams[0xE] -= 2;
        if (gIntroBGParams[0xE] <= -10)
            gIntroBGParams[0xE] = 8;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];

    if (gIntroFrameCounter == gIntroScene6_EntityMovement[gIntroScene6EntitySpawnIndex].frameDuration)
    {
        gIntroSpriteEntities[gIntroScene6EntitySpawnIndex].visible = 1;
        gIntroScene6EntitySpawnIndex++;
    }

    IntroScene6_RenderStarSprites();
    if (++gIntroAnimStep > gIntroScene6_ScrollVelocity[gIntroScene6VelocityIndex].frameDuration)
    {
        gIntroAnimStep = 0;
        if (++gIntroScene6VelocityIndex > 8)
            gIntroSceneIndex++;
    }
}

void IntroScene6_ContinueBounce(void)
{
    if (gIntroScene6_BounceFlags[gIntroFrameCounter] & 0x10)
    {
        gIntroBGParams[0x1] += gIntroBGParams[0x3];
        gIntroBGParams[0x3] -= 2;
        if (gIntroBGParams[0x3] <= -10)
            gIntroBGParams[0x3] = 8;
    }

    if (gIntroScene6_BounceFlags[gIntroFrameCounter] & 0x1)
    {
        gIntroBGParams[0xC] += gIntroBGParams[0xE];
        gIntroBGParams[0xE] -= 2;
        if (gIntroBGParams[0xE] <= -10)
            gIntroBGParams[0xE] = 8;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];

    IntroScene6_RenderStarSprites();
    if (++gIntroAnimStep > 16)
    {
        gIntroAnimStep = 0;
        gIntroSceneIndex++;
    }
}

void IntroScene6_FadeOutAndClearOAM(void)
{
    ClearSprites();
    DmaFill32(3, 0, OAM, 0x400);
    DmaFill16(3, 0, OBJ_VRAM0, 0x5000);
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene6_RenderStarSprites(void)
{
    s32 i;
    s32 j;
    const struct SpriteSet *p;
    struct SpriteGroup *spriteGroups[6];

    spriteGroups[0] = &gMain.spriteGroups[6 * gIntroSpriteEntities[0].animFrame];
    spriteGroups[1] = &gMain.spriteGroups[6 * gIntroSpriteEntities[1].animFrame + 1];
    spriteGroups[2] = &gMain.spriteGroups[6 * gIntroSpriteEntities[2].animFrame + 2];
    spriteGroups[3] = &gMain.spriteGroups[6 * gIntroSpriteEntities[3].animFrame + 3];
    spriteGroups[4] = &gMain.spriteGroups[6 * gIntroSpriteEntities[4].animFrame + 4];
    spriteGroups[5] = &gMain.spriteGroups[6 * gIntroSpriteEntities[5].animFrame + 5];

    spriteGroups[0]->active = gIntroSpriteEntities[0].visible;
    spriteGroups[1]->active = gIntroSpriteEntities[1].visible;
    spriteGroups[2]->active = gIntroSpriteEntities[2].visible;
    spriteGroups[3]->active = gIntroSpriteEntities[3].visible;
    spriteGroups[4]->active = gIntroSpriteEntities[4].visible;
    spriteGroups[5]->active = gIntroSpriteEntities[5].visible;

    LoadSpriteSets(gIntroScene6_SpriteSets, 0x12, &gMain.spriteGroups[0]);
    for (i = 0; i < 6; i++)
    {
        if (spriteGroups[i]->active != TRUE)
            continue;

        gIntroSpriteEntities[i].posX += gIntroScene6_EntityMovement[i].velocityX;
        gIntroSpriteEntities[i].posY += gIntroScene6_EntityMovement[i].velocityY;
        spriteGroups[i]->baseX = gIntroSpriteEntities[i].posX;
        spriteGroups[i]->baseY = gIntroSpriteEntities[i].posY;

        p = gIntroScene6_SpriteSets[i + gIntroSpriteEntities[i].animFrame * 6];
        for (j = 0; j < p->count; j++)
        {
            struct OamDataSimple *ods = &spriteGroups[i]->oam[j];
            gOamBuffer[ods->oamId].x = ods->xOffset + spriteGroups[i]->baseX;
            gOamBuffer[ods->oamId].y = ods->yOffset + spriteGroups[i]->baseY;
        }

        if (++gIntroSpriteEntities[i].frameTimer > 4)
        {
            gIntroSpriteEntities[i].frameTimer = 0;
            if (gIntroSpriteEntities[i].animFrame < 2)
                gIntroSpriteEntities[i].animFrame++;
        }

        if (gIntroFrameCounter == gIntroScene6_EntityMovement[i].spawnFrame)
            gIntroSpriteEntities[i].visible = 0;
    }

    spriteGroups[0]->active = FALSE;
    spriteGroups[1]->active = FALSE;
    spriteGroups[2]->active = FALSE;
    spriteGroups[3]->active = FALSE;
    spriteGroups[4]->active = FALSE;
    spriteGroups[5]->active = FALSE;
}

void IntroScene6_AdvanceIndex(void)
{
    gIntroSceneIndex++;
}

void IntroScene7_LoadGraphics(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = 0xD400;
    REG_DISPCNT |= (DISPCNT_BG0_ON);
    REG_BG1CNT = 0xD801;
    REG_DISPCNT |= (DISPCNT_BG1_ON);
    REG_BG2CNT = 0xDC02;
    REG_DISPCNT |= (DISPCNT_BG2_ON);
    REG_BG3CNT = 0xf03;
    REG_DISPCNT |= (DISPCNT_BG3_ON);

    DmaCopy16(3, gIntroScene7_BG0Tiles, 0x0600A000, 0x2000);
    DmaCopy16(3, gIntroScene7_BG1Tiles, 0x0600C000, 0x2000);
    DmaCopy16(3, gIntroScene7_BG2Tiles, 0x0600E000, 0x2000);
    DmaCopy16(3, gIntroScene7_BG3Tilemap, 0x06007800, 0x800);
    DmaCopy16(3, gIntroScene7Sprites_Gfx, 0x06000000, 0x5000);
    DmaCopy16(3, gIntroScene7_Pal, 0x05000000, 0x160);
    DmaCopy16(3, gIntroScene7Wailmer_Gfx, 0x06010000, 0x2000);
    DmaCopy16(3, gIntroScene7_Pal, 0x05000200, 0x160);

    gMain.dispcntBackup = REG_DISPCNT;
    IntroScene7_InitVars();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene7_InitVars(void)
{
    gIntroBGParams[0x0] = 0xFEFC;
    gIntroBGParams[0x1] = 0x46;
    gIntroBGParams[0x3] = 0;
    gIntroBGParams[0x6] = 0xFEE8;
    gIntroBGParams[0x7] = 0x5A;
    gIntroBGParams[0x9] = 0;
    gIntroBGParams[0xC] = 0xFF10;
    gIntroBGParams[0xD] = 0xFFCE;
    gIntroBGParams[0xF] = 0xFFFD;
    gIntroBGParams[0x12] = 0;
    gIntroBGParams[0x13] = 0;

    gIntroSpriteEntities[0].posX = 0x128;
    gIntroSpriteEntities[0].posY = 0x2C;
    gIntroSpriteEntities[0].velX = 0;
    gIntroSpriteEntities[0].velY = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
    gIntroWailmerScaleX = 0x100;
    gIntroWailmerScaleY = 0x100;
}

void IntroScene7_ScrollWaves1(void)
{
    gIntroBGParams[0xC] += 2;
    gIntroBGParams[0xD] -= gIntroBGParams[0xF];
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[0xF] > 4)
            gIntroBGParams[0xF] = -3;
    }

    gIntroBGParams[0x12]--;
    gIntroBGParams[0x13]--;

    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    if (gIntroFrameCounter > 32)
        gIntroSceneIndex++;
}

void IntroScene7_ScrollWaves2(void)
{
    gIntroBGParams[0xC] += 2;
    gIntroBGParams[0xD] -= gIntroBGParams[0xF];
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[0xF] > 4)
            gIntroBGParams[0xF] = -3;
    }

    gIntroBGParams[0x6] += 3;
    gIntroBGParams[0x7] -= gIntroBGParams[0x9];
    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroBGParams[0x9] > 7)
            gIntroBGParams[0x9] = -6;
    }

    gIntroBGParams[0x12]--;
    gIntroBGParams[0x13]--;

    // TODO rearrangement like this suggests one inline function per pair of statements, but see IntroScene1_LoadGraphics
    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    if (gIntroFrameCounter > 80)
        gIntroSceneIndex++;
}

void IntroScene7_ScrollWaves3(void)
{
    gIntroBGParams[0xC] += 2;
    gIntroBGParams[0xD] -= gIntroBGParams[0xF];
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[0xF] > 4)
            gIntroBGParams[0xF] = -3;
    }

    gIntroBGParams[0x6] += 3;
    gIntroBGParams[0x7] -= gIntroBGParams[0x9];
    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroBGParams[0x9] > 7)
            gIntroBGParams[0x9] = -6;
    }

    gIntroBGParams[0x0] += 4;
    gIntroBGParams[0x1] -= gIntroBGParams[0x3];
    if (gIntroFrameCounter % 4 == 0)
    {
        if (++gIntroBGParams[0x3] > 7)
            gIntroBGParams[0x3] = -3;
    }

    gIntroBGParams[0x12]--;
    gIntroBGParams[0x13]--;

    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    if (gIntroFrameCounter > 100)
        gIntroSceneIndex++;
}

void IntroScene7_WailmerAndAllWaves(void)
{
    gIntroBGParams[0xC] += 2;
    gIntroBGParams[0xD] -= gIntroBGParams[0xF];
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[0xF] > 4)
            gIntroBGParams[0xF] = -3;
    }

    gIntroBGParams[0x6] += 3;
    gIntroBGParams[0x7] -= gIntroBGParams[0x9];
    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroBGParams[0x9] > 7)
            gIntroBGParams[0x9] = -6;
    }

    gIntroBGParams[0x0] += 4;
    gIntroBGParams[0x1] -= gIntroBGParams[0x3];
    if (gIntroFrameCounter % 4 == 0)
    {
        if (++gIntroBGParams[0x3] > 7)
            gIntroBGParams[0x3] = -3;
    }

    gIntroSpriteEntities[0].posX -= 2;
    gIntroSpriteEntities[0].posY += gIntroSpriteEntities[0].velY;
    if (gIntroFrameCounter % 4 == 0)
    {
        if (++gIntroSpriteEntities[0].velY > 4)
            gIntroSpriteEntities[0].velY = -4;
    }

    gIntroBGParams[0x12]--;
    gIntroBGParams[0x13]--;

    gMain.bgOffsets[2].xOffset = gIntroBGParams[0xC];
    gMain.bgOffsets[2].yOffset = gIntroBGParams[0xD];
    gMain.bgOffsets[1].xOffset = gIntroBGParams[0x6];
    gMain.bgOffsets[1].yOffset = gIntroBGParams[0x7];
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0x1];
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    IntroScene7_RenderWailmer();
    if (gIntroFrameCounter > 192)
        gIntroSceneIndex++;
}

void IntroScene7_WailmerShakeAndShrink(void)
{
    int remainder;

    gIntroBGParams[0x12]--;
    gIntroBGParams[0x13]--;

    remainder = gIntroFrameCounter % 6;
    if (remainder == 0)
        gIntroSpriteEntities[0].posX -= 3;
    else if (remainder == 3)
        gIntroSpriteEntities[0].posX += 3;

    if (gIntroFrameCounter > 202)
    {
        gIntroWailmerScaleX--;
        gIntroWailmerScaleY--;
    }

    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x12];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x13];

    IntroScene7_RenderWailmer();
    if (gIntroFrameCounter > 222)
        gIntroSceneIndex++;
}

void IntroScene7_BeginFadeOut(void)
{
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene7_RenderWailmer(void)
{
    s32 i;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamData;

    spriteGroup = &gMain.spriteGroups[0];
    spriteGroup->active = TRUE;
    LoadSpriteSets(gIntroScene7_SpriteSets, 0x1, gMain.spriteGroups);
    if (spriteGroup->active == TRUE)
    {
        SetMatrixScale(gIntroWailmerScaleX, gIntroWailmerScaleY, 0);
        spriteGroup->baseX = gIntroSpriteEntities[0].posX;
        spriteGroup->baseY = gIntroSpriteEntities[0].posY;
        for (i = 0; i < 4; i++)
        {
            oamData = &spriteGroup->oam[i];
            gOamBuffer[oamData->oamId].priority = 1;
            gOamBuffer[oamData->oamId].x = gIntroScene7_WailmerQuadOffsets[i].x * gIntroWailmerScaleX / 0x100 + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = gIntroScene7_WailmerQuadOffsets[i].y * gIntroWailmerScaleY / 0x100 + spriteGroup->baseY;
            gOamBuffer[oamData->oamId].affineMode = 1;
            gOamBuffer[oamData->oamId].matrixNum = 0;
        }
    }

    spriteGroup->active = FALSE;
}

void IntroScene7_ClearGraphics(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene8a_LoadGraphics(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG2CNT = 0x7;
    REG_DISPCNT |= (DISPCNT_BG2_ON);

    DmaCopy16(3, gIntroScene8a_BG2Tilemap, 0x06000000, 0x800);
    DmaCopy16(3, gIntroScene7Explosion_Gfx, 0x06004000, 0x3400);
    DmaCopy16(3, gIntroScene8a_Pal, 0x05000000, 0x140);
    DmaCopy16(3, gIntroScene7WailmerLaunch_Gfx, 0x06010000, 0x2C00);
    DmaCopy16(3, gIntroScene8a_Pal, 0x05000200, 0x140);

    gMain.dispcntBackup = REG_DISPCNT;
    IntroScene8a_InitVars();
    IntroScene8a_RenderAllSprites();
    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene8a_InitVars(void)
{
    gIntroSpriteEntities[1].posX = 0x78;
    gIntroSpriteEntities[1].posY = 0x50;
    gIntroSpriteEntities[1].velX = 0x4;
    gIntroSpriteEntities[1].velY = 0x4;
    gIntroSpriteEntities[1].animFrame = 0;

    gIntroSpriteEntities[0].posX = 0x78;
    gIntroSpriteEntities[0].posY = 0x50;
    gIntroSpriteEntities[0].visible = 0;

    gIntroSpriteEntities[2].posX = 0x80;
    gIntroSpriteEntities[2].posY = 0x58;
    gIntroSpriteEntities[2].animFrame = 0;
    gIntroSpriteEntities[2].frameTimer = 0;
    gIntroSpriteEntities[2].visible = 0;

    gIntroSpriteEntities[3].posX = 0x80;
    gIntroSpriteEntities[3].posY = 0x48;
    gIntroSpriteEntities[3].animFrame = 0;
    gIntroSpriteEntities[3].frameTimer = 0;
    gIntroSpriteEntities[3].visible = 0;

    gIntroSpriteEntities[4].posX = 0x70;
    gIntroSpriteEntities[4].posY = 0x58;
    gIntroSpriteEntities[4].animFrame = 0;
    gIntroSpriteEntities[4].frameTimer = 0;
    gIntroSpriteEntities[4].visible = 0;

    gIntroSpriteEntities[5].posX = 0x78;
    gIntroSpriteEntities[5].posY = 0x58;
    gIntroSpriteEntities[5].animFrame = 0;
    gIntroSpriteEntities[5].frameTimer = 0;
    gIntroSpriteEntities[5].visible = 0;

    // TODO FIXME overlapping symbols (gAutoDisplayTitlescreenMenu)
    gIntroSpriteEntities[6].posX = 0x70;
    gIntroSpriteEntities[6].posY = 0x48;
    gIntroSpriteEntities[6].animFrame = 0;
    gIntroSpriteEntities[6].frameTimer = 0;
    gIntroSpriteEntities[6].visible = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void IntroScene8a_WaitForExplosion(void)
{
    IntroScene8a_RenderAllSprites();

    if (gIntroFrameCounter > 1)
    {
        gIntroSpriteEntities[0].visible = 1;
        gIntroSpriteEntities[2].visible = 1;
        gIntroSpriteEntities[3].visible = 1;
        gIntroSpriteEntities[4].visible = 1;
        gIntroSpriteEntities[5].visible = 1;
        gIntroSpriteEntities[6].visible = 1; // TODO FIXME overlapping symbols (gAutoDisplayTitlescreenMenu)
        gIntroSceneIndex++;
    }
}

void IntroScene8a_ExplodeAndLaunch(void)
{
    gIntroSpriteEntities[0].posX -= 9;
    gIntroSpriteEntities[0].posY -= 6;
    gIntroSpriteEntities[1].animFrame++;

    if (gIntroSpriteEntities[1].animFrame < 4)
    {
        gIntroSpriteEntities[1].posX += gIntroSpriteEntities[1].velX;
        gIntroSpriteEntities[1].posY += gIntroSpriteEntities[1].velY;
        gIntroSpriteEntities[1].velX--;
        gIntroSpriteEntities[1].velY--;
    }
    else if (gIntroFrameCounter % 2 == 0)
    {
        gIntroSpriteEntities[1].posX++;
        gIntroSpriteEntities[1].posY++;
    }

    IntroScene8a_RenderAllSprites();
    if (gIntroSpriteEntities[0].posY < -32)
        gIntroSceneIndex++;
}

void IntroScene8a_DriftAndFade(void)
{
    IntroScene8a_RenderAllSprites();

    if ((gIntroFrameCounter % 2) == 0)
    {
        gIntroSpriteEntities[1].posX++;
        gIntroSpriteEntities[1].posY++;
    }

    if (gIntroFrameCounter > 20)
        gIntroSceneIndex += 3;
}

void nullsub_12(void)
{
}

void nullsub_13(void)
{
}

void IntroScene8a_FadeOutAndClearOAM(void)
{
    FlashWhiteTransitionOut();
    ClearSprites();
    DmaFill32(3, 0, OAM, 0x400);
    DmaFill16(3, 0, OBJ_VRAM0, 0x5000);
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene8a_RenderAllSprites(void)
{
    struct SpriteGroup *sg0;
    struct SpriteGroup *sg1;
    struct SpriteGroup *spriteGroups[5];
    struct OamDataSimple *oamData;
    const struct SpriteSet *p;
    s32 i;
    s32 j;
    s8 cVar1;
    s8 cVar2;


    sg0 = &gMain.spriteGroups[0];
    sg1 = &gMain.spriteGroups[1];

    spriteGroups[0] = &gMain.spriteGroups[2 + (5 * gIntroSpriteEntities[2].animFrame)];
    spriteGroups[1] = &gMain.spriteGroups[3 + (5 * gIntroSpriteEntities[3].animFrame)];
    spriteGroups[2] = &gMain.spriteGroups[4 + (5 * gIntroSpriteEntities[4].animFrame)];
    spriteGroups[3] = &gMain.spriteGroups[5 + (5 * gIntroSpriteEntities[5].animFrame)];
    spriteGroups[4] = &gMain.spriteGroups[6 + (5 * gIntroSpriteEntities[6].animFrame)];


    sg0->active = gIntroSpriteEntities[0].visible;
    sg1->active = TRUE;

    spriteGroups[0]->active = gIntroSpriteEntities[2].visible;
    spriteGroups[1]->active = gIntroSpriteEntities[3].visible;
    spriteGroups[2]->active = gIntroSpriteEntities[4].visible;
    spriteGroups[3]->active = gIntroSpriteEntities[5].visible;
    spriteGroups[4]->active = gIntroSpriteEntities[6].visible;

    LoadSpriteSets(gIntroScene8a_SpriteSets, 0x11, gMain.spriteGroups);

    if (sg0->active == TRUE)
    {
        sg0->baseX = gIntroSpriteEntities[0].posX;
        sg0->baseY = gIntroSpriteEntities[0].posY;
        oamData = &sg0->oam[0];
        gOamBuffer[oamData->oamId].priority = 0;
        gOamBuffer[oamData->oamId].x = oamData->xOffset + sg0->baseX;
        gOamBuffer[oamData->oamId].y = oamData->yOffset + sg0->baseY;
    }

    for (i = 0; i < 5; i++)
    {
        if (spriteGroups[i]->active == TRUE)
        {
            gIntroAnimStep++;
            if (gIntroAnimStep > 5)
            {
                cVar1 = gIntroScene8a_DebrisMovement[i].lateVelX;
                cVar2 = gIntroScene8a_DebrisMovement[i].lateVelY;
            }
            else
            {
                cVar1 = gIntroScene8a_DebrisMovement[i].earlyVelX;
                cVar2 = gIntroScene8a_DebrisMovement[i].earlyVelY;
            }

            gIntroSpriteEntities[2 + i].posX += cVar1;
            gIntroSpriteEntities[2 + i].posY += cVar2;
            spriteGroups[i]->baseX = gIntroSpriteEntities[2 + i].posX;
            spriteGroups[i]->baseY = gIntroSpriteEntities[2 + i].posY;

            p = gIntroScene8a_SpriteSets[( 2 + i) + (5 * gIntroSpriteEntities[2 + i].animFrame)];

            for (j = 0; j < p->count; j++)
            {
                oamData = &spriteGroups[i]->oam[j];
                gOamBuffer[oamData->oamId].priority = (&gIntroScene8a_DebrisMovement[i])->oamPriority;
                gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroups[i]->baseX;
                gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroups[i]->baseY;
            }

            gIntroSpriteEntities[2 + i].frameTimer++;

            if (gIntroSpriteEntities[2 + i].frameTimer > 0x4)
            {
                gIntroSpriteEntities[2 + i].frameTimer = 0;
                if (gIntroSpriteEntities[2 + i].animFrame < 0x2)
                {
                    gIntroSpriteEntities[2 + i].animFrame++;
                }
            }
        }
    }

    if (sg1->active == TRUE)
    {
        sg1->baseX = gIntroSpriteEntities[1].posX;
        sg1->baseY = gIntroSpriteEntities[1].posY;

        for (j = 0; j < 4; j++)
        {
            oamData = &sg1->oam[j];
            gOamBuffer[oamData->oamId].priority = 3;
            gOamBuffer[oamData->oamId].x = oamData->xOffset + sg1->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + sg1->baseY;
        }

    }

    sg1->active = FALSE;
    sg0->active = FALSE;

    spriteGroups[0]->active = FALSE;
    spriteGroups[1]->active = FALSE;
    spriteGroups[2]->active = FALSE;
    spriteGroups[3]->active = FALSE;
    spriteGroups[4]->active = FALSE;
}
void IntroScene8a_ClearAndResetOAM(void)
{
    u16 i;
    u16 j;

    ClearBgTilemapAndOffsets();
    DmaFill32(3, 0, OAM, 0x400);
    for (i = 0; i < 20; i++)
    {
        gMain.spriteGroups[i].active = FALSE;
        gMain.spriteGroups[i].baseX = 0;
        gMain.spriteGroups[i].baseY = 0;
        for (j = 0; j < 0x16; j++)
        {
            gMain.spriteGroups[i].oam[j].oamId = 0;
            gMain.spriteGroups[i].oam[j].xOffset = 0;
            gMain.spriteGroups[i].oam[j].yOffset = 0;
        }
    }

    for (i = 0; i < 20; i++)
    {
        gOamBuffer[i].y = -12;
        gOamBuffer[i].affineMode = 0;
        gOamBuffer[i].objMode = 0;
        gOamBuffer[i].mosaic = 0;
        gOamBuffer[i].bpp = 0x0;
        gOamBuffer[i].shape = 0;
        gOamBuffer[i].x = -12;
        gOamBuffer[i].matrixNum = 0;
        gOamBuffer[i].hFlip = 0;
        gOamBuffer[i].vFlip = 0;
        gOamBuffer[i].size = 0;
        gOamBuffer[i].tileNum = 0;
        gOamBuffer[i].priority = 0;
        gOamBuffer[i].paletteNum = 0;
        gOamBuffer[i].affineParam = 0;
    }

    gIntroSceneIndex++;
}

void IntroScene8b_LoadGraphics(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG3CNT = 0x7;
    REG_DISPCNT |= (DISPCNT_BG3_ON);

    DmaCopy16(3, gIntroScene8b_BG3Tilemap, 0x06000000, 0x800);
    DmaCopy16(3, gIntroScene8Clouds_Gfx, 0x06004000, 0x2400);
    DmaCopy16(3, gIntroScene8b_Pal, 0x05000000, 0x40);
    DmaCopy16(3, gIntroScene8Ball_Gfx, 0x06010000, 0x7000);
    DmaCopy16(3, gIntroScene8b_Pal, 0x05000200, 0x40);

    gMain.dispcntBackup = REG_DISPCNT;
    IntroScene8b_InitVars();
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x0];
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0x1];
    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene8b_InitVars(void)
{
    gIntroBGParams[0x0] = 0;
    gIntroBGParams[0x1] = 0;

    gIntroSpriteEntities[0].posX = 0xF0;
    gIntroSpriteEntities[0].posY = 0x1E;
    gIntroSpriteEntities[0].velX = 0xE;
    gIntroSpriteEntities[0].animFrame = 0x1;
    gIntroSpriteEntities[0].visible = 0x1;

    gIntroSpriteEntities[1].posX = 0x108;
    gIntroSpriteEntities[1].posY = 0x50;
    gIntroSpriteEntities[1].velX = 0x6;
    gIntroSpriteEntities[1].visible = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
    gIntroWailmerScaleX = 0x100;
    gIntroWailmerScaleY = 0x100;
    gIntroObjWhiteFlash = 0;
    gIntroBGWhiteFlash = 0;
}

void IntroScene8b_BallFlyIn(void)
{
    gIntroBGParams[0x0] -= 0x24;
    gIntroSpriteEntities[0].posX -= gIntroScene8b_BallDecelTable[gIntroAnimStep];
    gIntroAnimStep++;

    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroSpriteEntities[0].animFrame > 10)
            gIntroSpriteEntities[0].animFrame = 1;
    }

    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x0];
    IntroScene8b_RenderBallAndCloud();

    if (gIntroFrameCounter > 40)
    {
        gIntroWailmerScaleX += 6;
        gIntroWailmerScaleY += 6;
        if (gIntroFrameCounter % 2 == 0)
            gIntroSpriteEntities[0].posY++;
    }

    if (gIntroFrameCounter > 90)
    {
        gIntroSpriteEntities[0].visible = 0;
        gIntroSpriteEntities[1].visible = 1;
        gIntroSceneIndex++;
    }
}

void IntroScene8b_ScrollClouds(void)
{
    gIntroBGParams[0] -= 0x24;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0];
    if (gIntroFrameCounter > 120)
        gIntroSceneIndex++;
}

void IntroScene8b_CloudSpriteAndWhiteFlash(void)
{
    if (gIntroFrameCounter < 135)
        gIntroSpriteEntities[1].posX -= 12;
    else
        gIntroSpriteEntities[1].posX--;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroObjWhiteFlash += 3;
        if (gIntroObjWhiteFlash > 32)
            gIntroObjWhiteFlash = 32;
    }

    BrightenPalette(gIntroScene8b_Pal, (void *) OBJ_PLTT, 0x20, gIntroObjWhiteFlash);
    if (gIntroFrameCounter > 136)
    {
        gIntroBGWhiteFlash += 2;
        if (gIntroBGWhiteFlash > 32)
            gIntroBGWhiteFlash = 0x20;

        BrightenPalette(gIntroScene8b_Pal, (void *) PLTT, 0x40, gIntroBGWhiteFlash);
    }

    gIntroBGParams[0x0] -= 0x24;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0x0];
    IntroScene8b_RenderBallAndCloud();

    if (gIntroFrameCounter > 152)
    {
        gIntroFrameCounter = 0;
        gIntroAnimStep = 1;
        gIntroSceneIndex += 2;
    }
}

void nullsub_14(void)
{
}

void IntroScene8b_FadeOutMusic(void)
{
    if (gIntroFrameCounter % 10 == 0)
    {
        gIntroAnimStep++;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, (0x100 / gIntroAnimStep));
    }

    if (gIntroFrameCounter > 45)
        gIntroSceneIndex++;
}

void IntroScene8b_EndIntro(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gMain.subState++;
}

void IntroScene8b_RenderBallAndCloud(void)
{
    int i;
    struct SpriteGroup *spriteGroup0;
    struct SpriteGroup *spriteGroup1;
    struct OamDataSimple *oamData;

    spriteGroup0 = &gMain.spriteGroups[gIntroSpriteEntities[0].animFrame];
    spriteGroup1 = &gMain.spriteGroups[0];
    spriteGroup0->active = gIntroSpriteEntities[0].visible;
    spriteGroup1->active = gIntroSpriteEntities[1].visible;
    LoadSpriteSets(gIntroScene8b_SpriteSets, 11, gMain.spriteGroups);
    if (spriteGroup0->active == TRUE)
    {
        SetMatrixScale(gIntroWailmerScaleX, gIntroWailmerScaleY, 0);
        spriteGroup0->baseX = gIntroSpriteEntities[0].posX;
        spriteGroup0->baseY = gIntroSpriteEntities[0].posY;
        oamData = &spriteGroup0->oam[0];
        gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup0->baseX;
        gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup0->baseY;
        gOamBuffer[oamData->oamId].affineMode = 3;
        gOamBuffer[oamData->oamId].matrixNum = 0;
    }

    if (spriteGroup1->active == TRUE)
    {
        spriteGroup1->baseX = gIntroSpriteEntities[1].posX;
        spriteGroup1->baseY = gIntroSpriteEntities[1].posY;
        for (i = 0; i < 4; i++)
        {
            oamData = &spriteGroup1->oam[i];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup1->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup1->baseY;
        }
    }

    spriteGroup0->active = FALSE;
    spriteGroup1->active = FALSE;
}
