#include "global.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "variables.h"
#include "titlescreen.h"
#include "constants/bg_music.h"

/* Scene list (based on graphic loads)
  1: Title text letter bounce + Torchic
  2: Pika Pair
  3: Treecko Flipper And Ball
  4: Plusle/Minun
  5: Mudkip and ball
  6: Chinchou bumpers
  7: Parade (Makuhita Wailmer Pelipper and Spoink)
  8: Wailmer ball eject
  9: Flying ball
*/


void IntroScene3Treecko_InitVars(void);
void IntroScene3Treecko_RenderPokeball(void);
void IntroScene4PlussleMinun_InitVars(void);
void IntroScene5Mudkip_InitVars(void);
extern void IntroScene5Mudkip_RenderAllSprites(void);
void IntroScene6Chinchou_InitVars(void);
void IntroScene6Chinchou_RenderStarSprites(void);
void IntroScene7Parade_InitVars(void);
void IntroScene7Parade_RenderWailmer(void);
void IntroScene8WailmerLaunch_InitVars(void);
void IntroScene8WailmerLaunch_RenderAllSprites(void);
void IntroScene9BallFlight_InitVars(void);
void IntroScene9BallFlight_RenderBallAndCloud(void);

extern StateFunc gIntroStateFuncs[15];
extern u8 gIntroCopyright_Tilemap[];

extern u8 gIntroCopyright_Gfx[];
extern const Palette gIntroCopyright_Pal[];
extern u8 gIntroScene1TorchicSprites_Gfx[];
extern const Palette gIntroScene1TorchicSprites_Pals[];

extern u8 gIntroScene1Torchic_BG0Tilemap[];
extern u8 gIntroScene1Torchic_BG1Tilemap[];
extern u8 gIntroScene1Torchic_BG2Tilemap[];
extern u8 gIntroScene1Torchic_BG3Tilemap[];
extern u8 gIntroScene1TorchicText_Gfx[];
extern u8 gIntroScene1TorchicBall_Gfx[];
extern s16 gIntroScene1Torchic_TileOffsets[0x8];

extern u16 gIntroTileBuffer[];

extern struct UnkStruct_0202ADA0 gIntroBGParams[4];

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

extern u8 gIntroScene2Pikas_BG3Tilemap[];
extern u8 gIntroScene2PikasSprites_Gfx[];
extern const Palette gIntroScene2Pikas_Pal[];
extern u8 gIntroScene2Pikas_BG0Tiles[];
extern u8 gIntroScene2Pikas_BG1Tiles[];

extern u8 gIntroScene3Treecko_AltBG1TilemapBuffer[];

extern const Palette gIntroScene3Treecko_Pal[];
extern u8 gIntroScene3Treecko_BG0Tilemap[];
extern u8 gIntroScene3Treecko_BG1Tilemap[];
extern u8 gIntroScene3Treecko_BG2Tilemap[];
extern u8 gIntroScene3Treecko_BG3Tilemap[];
extern u8 gIntroScene3TreeckoSprites_Gfx[];
extern u8 gIntroScene3Treecko_BG1TilemapA[];
extern u8 gIntroScene3Treecko_BG1TilemapB[];
extern u8 gIntroScene3TreeckoTreecko_Gfx[];
extern const struct SpriteSet *const gIntroScene9BallFlight_SpriteSets[];

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

extern struct Vector16 gIntroScene1Torchic_BGAnimTiming[0x8];
extern struct Vector16 gIntroScene1Torchic_ScaleOffsets[0x4];
extern struct Vector16 gIntroScene5Mudkip_BGAnimTiming[];
extern struct Vector16 gIntroScene7Parade_WailmerQuadOffsets[0x4];

struct IntroAnimVelocity {
    s8 velocityX;
    s8 velocityY;
    s8 frameDuration;
    s8 spawnFrame;
};

extern struct IntroAnimVelocity gIntroScene6Chinchou_ScrollVelocity[];
extern struct IntroAnimVelocity gIntroScene6Chinchou_EntityMovement[];

extern const struct SpriteSet *const gIntroScene8WailmerLaunch_SpriteSets[];

struct IntroDebrisMovement
{
    u8 earlyVelX;
    u8 earlyVelY;
    u8 lateVelX;
    u8 lateVelY;
    u8 filler4;
    u8 oamPriority;
}; // 0x8 size in memory
extern const struct IntroDebrisMovement gIntroScene8WailmerLaunch_DebrisMovement[];

void IntroMain(void)
{
     gIntroStateFuncs[gMain.subState]();
}

void Intro_State0_929C(void)
{
  ResetDisplayState();
  REG_DISPCNT = DISPCNT_FORCED_BLANK;
  REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(1);
  REG_DISPCNT |= DISPCNT_BG1_ON;

  DmaCopy16(3, gIntroCopyright_Tilemap, BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
  DmaCopy16(3, gIntroCopyright_Gfx, BG_CHAR_ADDR(1), BG_SCREEN_SIZE);
  DmaCopy16(3, gIntroCopyright_Pal, BG_PLTT, BG_PLTT_SIZE);

  gMain.dispcntBackup = REG_DISPCNT;
  gIntroFrameCounter = 0;
  gIntroSceneIndex = 0;

  SetMainCallback( IntroVBlankCallback );
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

void IntroScene1_00_LoadTitleLettersAndTorchicScene(void)
{
    ClearGraphicsMemory();
    ClearBgTilemapAndOffsets();
    ClearSprites();

    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(26) | BGCNT_PRIORITY(0);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_TXT512x256 | BGCNT_SCREENBASE(27) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_TXT512x256 | BGCNT_SCREENBASE(29) | BGCNT_PRIORITY(2);
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(31) | BGCNT_PRIORITY(3);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene1Torchic_BG0Tilemap, BG_CHAR_SCREEN_ADDR(3,2), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene1Torchic_BG1Tilemap, BG_CHAR_SCREEN_ADDR(3,3), 2*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene1Torchic_BG2Tilemap, BG_CHAR_SCREEN_ADDR(3,5), 2*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene1Torchic_BG3Tilemap, BG_CHAR_SCREEN_ADDR(3,7), BG_SCREEN_SIZE);

    DmaCopy16(3, gIntroScene1TorchicText_Gfx, BG_CHAR_ADDR(0), 0x5800);
    DmaCopy16(3, gIntroScene1TorchicBall_Gfx, gIntroTileBuffer, 0x6800);
    DarkenPalette(gIntroScene1TorchicSprites_Pals, (void*)BG_PLTT, BG_PLTT_SIZE, 0x20);
    DmaCopy16(3, gIntroScene1TorchicSprites_Gfx, BG_CHAR_ADDR(4), 0x8000);
    DmaCopy16(3, gIntroScene1TorchicSprites_Pals, OBJ_PLTT, OBJ_PLTT_SIZE);
    IntroScene1Torchic_InitVars();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[3].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[2].posY;
    EnableVBlankInterrupts();
    FadeInWithCustomPalettes((void*)BG_PLTT, (u8 * )gIntroScene1TorchicSprites_Pals, NULL);
    DmaCopy16(3, gIntroScene1TorchicSprites_Pals, OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, 0, OBJ_PLTT_SLOT(0), PLTT_SLOT_SIZE);
    gIntroSceneIndex++;
}

void IntroScene1Torchic_InitVars(void)
{
    gIntroSpriteEntities[1].posX = 0x78;
    gIntroSpriteEntities[1].posY = 0x50;
    gIntroSpriteEntities[1].animFrame = 0;
    gIntroSpriteEntities[1].visible = TRUE;
    gIntroSpriteEntities[3].posX = 0x9c;
    gIntroSpriteEntities[3].posY = 0x92;
    gIntroSpriteEntities[3].visible = FALSE;
    gIntroSpriteEntities[3].frameTimer = 0;
    gIntroSpriteEntities[2].posX = 0x9d;
    gIntroSpriteEntities[2].posY = 0x93;
    gIntroSpriteEntities[2].visible = FALSE;
    gIntroSpriteEntities[4].posX = 0x80;
    gIntroSpriteEntities[4].posY = 0x80;
    gIntroSpriteEntities[4].visible = TRUE;
    gIntroBGParams[0].posX = 0xffa8;
    gIntroBGParams[0].posY = 0xffca;
    gIntroBGParams[0].animFrame = 0;
    gIntroBGParams[0].frameTimer = 0;
    gIntroBGParams[1].posX = 0x100;
    gIntroBGParams[1].posY = 0;
    gIntroBGParams[1].animFrame = 0;
    gIntroBGParams[3].posX = 0xfb;
    gIntroBGParams[3].posY = 0;
    gIntroBGParams[3].animFrame = 0;
    gIntroBGParams[2].posX = 0;
    gIntroBGParams[2].posY = 0;
    gIntroSpriteEntities[0].posX = 0x78;
    gIntroSpriteEntities[0].posY = 0x50;
    gIntroSpriteEntities[0].animFrame = 0;
    gIntroSpriteEntities[0].frameTimer = 0;
    gIntroSpriteEntities[0].visible = TRUE;
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

void IntroScene1TitleText_01_TitleLetterBounceReveal(void)
{
    IntroScene1Torchic_RenderTitleSprite();
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

void IntroScene1TitleText_02_TitleRecedeToBackground(void)
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

    IntroScene1Torchic_RenderScaledTitle();
}

void IntroScene1TitleText_03_1PxText(void)
{
    if (++gIntroSpriteEntities[0].frameTimer > 3)
    {
        gIntroSpriteEntities[0].frameTimer = 0;
        gIntroSpriteEntities[0].posX = 0x78;
        gIntroSpriteEntities[0].posY = 0x58;
        gIntroSpriteEntities[0].visible = TRUE;
        m4aSongNumStart(SE_RAMP_PRIZE_COLLECTED);
        gIntroSceneIndex++;
    }
}

void IntroScene1Torchic_04_LargeSparkle(void)
{
    if (gIntroSpriteEntities[0].animFrame == 43)
    {
        if (++gIntroSpriteEntities[0].frameTimer > 1)
        {
            gIntroSpriteEntities[0].visible = FALSE;
            DarkenPalette(&gIntroScene1TorchicSprites_Pals[14], (void*)BG_PLTT_SLOT(7), 0x20, 0);
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

    IntroScene1Torchic_RenderTitleSprite();
}

void IntroScene1Torchic_05_SpeedLineFadeIn(void)
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

    IntroScene1Torchic_RenderAllSprites();
}

void IntroScene1Torchic_06_BrightenPokeballFlyTowardsScreen(void)
{
    if (gIntroPalFadeLevel > 0)
    {
        gIntroPalFadeLevel -= 2;
        if (gIntroPalFadeLevel < 1)
        {
            gIntroPalFadeLevel = 0;
        }
        DarkenPalette(gIntroScene1TorchicSprites_Pals, (void*)BG_PLTT, 0x200, gIntroPalFadeLevel);
        DarkenPalette(gIntroScene1TorchicSprites_Pals, (void*)OBJ_PLTT, 0x20, gIntroPalFadeLevel);
    }

    if (gIntroFrameCounter % 3 == 0)
        gIntroSpriteEntities[1].animFrame = 1 - gIntroSpriteEntities[1].animFrame;

    gIntroBGParams[0].posX--;

    if (gIntroFrameCounter % 2 == 0)
        gIntroBGParams[0].posY--;

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    if (++gIntroBGParams[0].frameTimer > gIntroScene1Torchic_BGAnimTiming[gIntroBGParams[0].animFrame].y)
    {
        CopyBgTilesRect(&gIntroTileBuffer[gIntroScene1Torchic_TileOffsets[gIntroBGParams[0].animFrame]], (void *)0x60036E0, 8, 8);
        if (++gIntroBGParams[0].animFrame > 3)
        {
            gIntroSpriteEntities[3].visible = TRUE;
            gIntroSpriteEntities[2].visible = TRUE;
            gIntroSpriteEntities[1].visible = FALSE;
            gIntroBGParams[1].animFrame = 0;
            gIntroSceneIndex++;
        }
    }

    IntroScene1Torchic_RenderAllSprites();
}

void IntroScene1Torchic_07_TorchicRiseAndBGSplit(void)
{
    gIntroSpriteEntities[3].posX -= 0xE;
    gIntroSpriteEntities[3].posY -= 0xD;

    gIntroBGParams[3].posX -= 0x10;
    gIntroBGParams[3].posY++;
    gIntroBGParams[1].posX  -= 0x10;

    gIntroSpriteEntities[2].posX -= 0xE;
    gIntroSpriteEntities[2].posY -= 0xD;
    gIntroSpriteEntities[4].posX += 0xB;
    gIntroSpriteEntities[4].posY -= 0x2;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0].posX--;
        gIntroBGParams[0].posY--;
    }

    if (++gIntroBGParams[0].frameTimer > gIntroScene1Torchic_BGAnimTiming[gIntroBGParams[0].animFrame].y)
    {
        if (gIntroBGParams[0].animFrame < 7)
            CopyBgTilesRect(&gIntroTileBuffer[gIntroScene1Torchic_TileOffsets[gIntroBGParams[0].animFrame]], (void *)0x60036e0, 8, 8);
        else
            CopyBgTilesRect(&gIntroTileBuffer[gIntroScene1Torchic_TileOffsets[gIntroBGParams[0].animFrame]], (void *)0x60032c0, 10, 10);

        gIntroBGParams[0].animFrame++;
    }

    gIntroBGParams[1].animFrame++;
    if (gIntroBGParams[1].animFrame > 9)
    {
        gIntroBGParams[1].animFrame = 0;
        gIntroSceneIndex += 2;
    }

    IntroScene1Torchic_RenderAllSprites();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[3].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[1].posY;
}

void nullsub_4(void)
{
}

void IntroScene1Torchic_09_OrangeTextScrolls(void)
{
    gIntroBGParams[2].posX++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroSpriteEntities[3].posX--;
        gIntroSpriteEntities[3].posY--;
        gIntroSpriteEntities[2].posX -= 2;
        gIntroSpriteEntities[2].posY -= 2;
    }

    IntroScene1Torchic_RenderAllSprites();

    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[2].posY;
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

void IntroScene1Torchic_12_FlashWhite(void)
{
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene1Torchic_RenderTitleSprite(void)
{
    s32 i;
    struct OamDataSimple *test2;
    struct SpriteGroup *puVar4;
    const struct SpriteSet *puVar6;

    puVar4 = &gMain.spriteGroups[SG_4 + gIntroSpriteEntities[0].animFrame];
    puVar4->active = gIntroSpriteEntities[0].visible;
    LoadSpriteSets(gIntroScene1Torchic_SpriteSets, 0x31, gMain.spriteGroups);

    if (puVar4->active == TRUE)
    {
        puVar4->baseX = gIntroSpriteEntities[0].posX;
        puVar4->baseY = gIntroSpriteEntities[0].posY;

        puVar6 = gIntroScene1Torchic_SpriteSets[gIntroSpriteEntities[0].animFrame + 4];
        for (i = 0; i < puVar6->count; i++)
        {
            test2 = &puVar4->oam[i];
            gOamBuffer[test2->oamId].x = test2->xOffset + puVar4->baseX;
            gOamBuffer[test2->oamId].y = test2->yOffset + puVar4->baseY;
        }
    }

    puVar4->active = FALSE;
}

void IntroScene1Torchic_RenderScaledTitle(void)
{
    s32 i;
    struct SpriteGroup *puVar4;
    struct OamDataSimple *puVar2;

    puVar4 = &gMain.spriteGroups[SG_40];
    puVar4->active = gIntroSpriteEntities[0].visible;
    LoadSpriteSets(gIntroScene1Torchic_SpriteSets, 0x31, gMain.spriteGroups);

    if (puVar4->active == TRUE)
    {
        SetMatrixScale(gIntroScaleX, gIntroScaleY, 0);
        puVar4->baseX = gIntroSpriteEntities[0].posX;
        puVar4->baseY = gIntroSpriteEntities[0].posY;

        for (i = 0; i < 4; i++)
        {
            puVar2 = &puVar4->oam[i];
            gOamBuffer[puVar2->oamId].x = gIntroScene1Torchic_ScaleOffsets[i].x * gIntroScaleX / 0x100 + puVar4->baseX;
            gOamBuffer[puVar2->oamId].y = gIntroScene1Torchic_ScaleOffsets[i].y * gIntroScaleY / 0x100 + puVar4->baseY;

            gOamBuffer[puVar2->oamId].affineMode = ST_OAM_AFFINE_NORMAL;
            gOamBuffer[puVar2->oamId].matrixNum = 0;
        }
    }
    puVar4->active = FALSE;
}

void IntroScene1Torchic_RenderAllSprites(void)
{
    struct OamDataSimple *puVar5;
    struct SpriteGroup *puVar1;
    struct SpriteGroup *mainSg3;
    struct SpriteGroup *mainSg2;
    struct SpriteGroup *otherSg;
    int i;

    gMain.blendControl = 0xF10;
    gMain.blendAlpha = gIntroBlendSrc | (gIntroBlendDst << 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    puVar1 = &gMain.spriteGroups[SG_0 + gIntroSpriteEntities[1].animFrame];
    mainSg3 = &gMain.spriteGroups[SG_3];
    mainSg2 = &gMain.spriteGroups[SG_2];
    otherSg = &gMain.spriteGroups[SG_48];

    puVar1->active = gIntroSpriteEntities[1].visible;
    mainSg3->active = gIntroSpriteEntities[2].visible;
    mainSg2->active = gIntroSpriteEntities[3].visible;
    otherSg->active = gIntroSpriteEntities[4].visible;
    LoadSpriteSets(gIntroScene1Torchic_SpriteSets, 0x31, gMain.spriteGroups);

    if (puVar1->active == TRUE)
    {
        const struct SpriteSet *introScene1;
        puVar1->baseX = gIntroSpriteEntities[1].posX;
        puVar1->baseY = gIntroSpriteEntities[1].posY;

        introScene1 = gIntroScene1Torchic_SpriteSets[gIntroSpriteEntities[1].animFrame];

        for (i = 0; i < introScene1->count; i++)
        {
            puVar5 = &puVar1->oam[i];
            gOamBuffer[puVar5->oamId].objMode = ST_OAM_OBJ_BLEND;
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
            gOamBuffer[puVar5->oamId].objMode = ST_OAM_OBJ_BLEND;
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
            gOamBuffer[puVar5->oamId].objMode = ST_OAM_OBJ_NORMAL;
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

void IntroScene1Torchic_13_ResetTilemap(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene2Pikas_14_LoadPinkYellowBackground(void)
{
    REG_DISPCNT = DISPCNT_MODE_0;
    REG_BG0CNT = BGCNT_AFF1024x1024 | BGCNT_SCREENBASE(12) | BGCNT_PRIORITY(0);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_AFF1024x1024 | BGCNT_SCREENBASE(26) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(30) | BGCNT_PRIORITY(3);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene2Pikas_BG0Tiles, BG_CHAR_SCREEN_ADDR(1,4), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene2Pikas_BG1Tiles, BG_CHAR_SCREEN_ADDR(3,2), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene2Pikas_BG3Tilemap, BG_CHAR_SCREEN_ADDR(3,6), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene2PikasSprites_Gfx, BG_CHAR_SCREEN_ADDR(0,0), 7*BG_SCREEN_SIZE + 0x400);
    DmaCopy16(3, gIntroScene2Pikas_Pal, BG_PLTT_SLOT(0), 4*PLTT_SLOT_SIZE);
    IntroScene2Pikas_InitVars();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[2].posY;
    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex += 2;
}

void IntroScene2Pikas_InitVars(void)
{
    gIntroBGParams[0].posX = 0x1C;
    gIntroBGParams[0].posY = 0xFF2C;
    gIntroBGParams[0].velX = 0;
    gIntroBGParams[0].velY = 0xE;
    gIntroBGParams[1].posX = 0xFF5C;
    gIntroBGParams[1].posY = 0xFF08;
    gIntroBGParams[1].velX = 0;
    gIntroBGParams[1].velY = 0x10;
    gIntroBGParams[2].posX = 0;
    gIntroBGParams[2].posY = 0;
    gIntroBGParams[2].animFrame = 0;
    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void nullsub_6(void)
{
}

void IntroScene2Pikas_16_PikaPairRising(void)
{
    gIntroBGParams[0].posY += gIntroBGParams[0].velY;
    gIntroBGParams[1].posY += gIntroBGParams[1].velY;
    gIntroBGParams[2].posX--;
    gIntroBGParams[2].posY--;
    gIntroBGParams[0].posX--;
    gIntroBGParams[1].posX++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0].velY--;
        gIntroBGParams[1].velY--;
    }

    // TODO same as IntroScene2Pikas_14_LoadPinkYellowBackground - possible inline function?
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[2].posY;

    gIntroBGParams[2].animFrame++;
    if (gIntroBGParams[2].animFrame > 0x27)
    {
        gIntroBGParams[2].animFrame = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_7(void)
{
}

void IntroScene2Pikas_18_FlashWhite(void)
{
    gIntroBGParams[0].posY++;
    gIntroBGParams[1].posY++;
    gIntroBGParams[2].posX--;
    gIntroBGParams[2].posY--;
    gIntroBGParams[0].posX--;
    gIntroBGParams[1].posX++;

    // TODO same as IntroScene2Pikas_16_PikaPairRising - possible inline function?
    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0].velY--;
        gIntroBGParams[1].velY--;
    }

    // TODO same as IntroScene2Pikas_14_LoadPinkYellowBackground - possible inline function?
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[2].posY;

    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene2Pikas_19_ResetTilemap(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene3Treecko_20_LoadTreeckoFlipperBall(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_TXT512x256 | BGCNT_SCREENBASE(26) | BGCNT_PRIORITY(0);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(28) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_TXT512x256 | BGCNT_SCREENBASE(29) | BGCNT_PRIORITY(2);
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(31) | BGCNT_PRIORITY(3);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene3Treecko_BG0Tilemap, BG_CHAR_SCREEN_ADDR(3,2), 2*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene3Treecko_BG1Tilemap, BG_CHAR_SCREEN_ADDR(3,4), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene3Treecko_BG2Tilemap, BG_CHAR_SCREEN_ADDR(3,5), 2*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene3Treecko_BG3Tilemap, BG_CHAR_SCREEN_ADDR(3,7), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene3Treecko_BG1TilemapA, gBG0TilemapBuffer, BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene3Treecko_BG1TilemapB, gIntroScene3Treecko_AltBG1TilemapBuffer, BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene3TreeckoSprites_Gfx, BG_VRAM, 0x6C00);
    DmaCopy16(3, gIntroScene3Treecko_Pal, BG_PLTT_SLOT(0), 7*PLTT_SLOT_SIZE);
    DmaCopy16(3, gIntroScene3TreeckoTreecko_Gfx, OBJ_VRAM0, 0x2000);
    DmaCopy16(3, gIntroScene3Treecko_Pal, OBJ_PLTT_SLOT(0), 7*PLTT_SLOT_SIZE);

    IntroScene3Treecko_InitVars();
    IntroScene3Treecko_RenderPokeball();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene3Treecko_InitVars(void)
{
    gIntroBGParams[0].posX = 0x2C;
    gIntroBGParams[0].posY = 0xFF8E;

    gIntroSpriteEntities[0].posX = 0xFFD4;
    gIntroSpriteEntities[0].posY = 0x72;

    gIntroBGParams[1].posX = 0xFFCE;
    gIntroBGParams[1].posY = 0x1E;
    gIntroBGParams[2].posX = 0;
    gIntroBGParams[2].posY = 0;
    gIntroBGParams[2].animFrame = 0;
    gIntroBGParams[3].posX = 0;
    gIntroBGParams[3].posY = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void IntroScene3Treecko_21_MoveTreeckoFlipperBallAndSplit(void)
{
    gIntroBGParams[0].posX -= 0x11;
    gIntroBGParams[0].posY += 0xA;

    gIntroSpriteEntities[0].posX += 0x11;
    gIntroSpriteEntities[0].posY -= 0xA;

    gIntroBGParams[2].posX += 0x10;
    gIntroBGParams[1].posX += 0x4;
    gIntroBGParams[1].posY -= 0x8;
    gIntroBGParams[2].animFrame++;

    if (gIntroBGParams[2].animFrame > 9)
    {
        gIntroBGParams[2].animFrame = 0;
        gIntroSceneIndex++;
    }

    IntroScene3Treecko_RenderPokeball();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
}

void IntroScene3Treecko_22_FlipperHitTextScroll(void)
{
    gIntroBGParams[3].posX--;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0].posX--;
        gIntroBGParams[0].posY++;
        gIntroSpriteEntities[0].posX += 2;
        gIntroSpriteEntities[0].posY -= 2;
    }
    if (gIntroFrameCounter % 3 == 0)
    {
        DmaCopy16(3, BG_PLTT_SLOT(0), gIntroPalSwapBuffer, PLTT_SLOT_SIZE);
        DmaCopy16(3, BG_PLTT_SLOT(2), PLTT, PLTT_SLOT_SIZE);
        DmaCopy16(3, gIntroPalSwapBuffer, BG_PLTT_SLOT(2), PLTT_SLOT_SIZE);
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;
    IntroScene3Treecko_RenderPokeball();

    if (gIntroBGParams[2].animFrame == 2)
    {
        DmaCopy16(3, gBG0TilemapBuffer, BG_CHAR_SCREEN_ADDR(3,4), BG_SCREEN_SIZE);
        gIntroBGParams[1].posX = 0;
        gIntroBGParams[1].posY = 0;
        gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
        gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    }
    else if (gIntroBGParams[2].animFrame == 4)
    {
        DmaCopy16(3, gIntroScene3Treecko_AltBG1TilemapBuffer, BG_CHAR_SCREEN_ADDR(3,4), BG_SCREEN_SIZE);
        gIntroBGParams[1].posX = 0;
        gIntroBGParams[1].posY = 0;
        gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
        gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    }

    gIntroBGParams[2].animFrame++;
    if (gIntroBGParams[2].animFrame > 0x1D)
    {
        gIntroBGParams[2].animFrame = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_8(void)
{
}

void IntroScene3Treecko_24_FlashWhite(void)
{
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene3Treecko_RenderPokeball(void)
{
    s32 i;
    struct SpriteGroup *puVar4;
    struct OamDataSimple *puVar2;

    gMain.blendControl = 0x1F50;
    gMain.blendAlpha = 0x808;
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    puVar4 = &gMain.spriteGroups[SG_0];
    puVar4->active = TRUE;
    LoadSpriteSets(gIntroScene3Treecko_SpriteSets, 0x1, puVar4);

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

void IntroScene3Treecko_25_ResetTilemap(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene4PlussleMinun_26_LoadTealWhiteBackground(void)
{
    REG_DISPCNT = DISPCNT_MODE_0;
    REG_BG0CNT = BGCNT_TXT512x512 | BGCNT_SCREENBASE(12) | BGCNT_PRIORITY(0);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_TXT512x512 | BGCNT_SCREENBASE(26) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(30) | BGCNT_PRIORITY(3);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene4PlussleMinun_BG0Tiles, BG_CHAR_SCREEN_ADDR(1,4), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene4PlussleMinun_BG1Tiles, BG_CHAR_SCREEN_ADDR(3,2), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene4PlussleMinun_BG3Tilemap, BG_CHAR_SCREEN_ADDR(3,6), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene4PlussleMinunSprites_Gfx, BG_CHAR_ADDR(0), BG_CHAR_SIZE);
    DmaCopy16(3, gIntroScene4PlussleMinun_Pal, BG_PLTT_SLOT(0), 3*PLTT_SLOT_SIZE);
    gMain.dispcntBackup = REG_DISPCNT;

    IntroScene4PlussleMinun_InitVars();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[2].posY;

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex += 2;
}

void IntroScene4PlussleMinun_InitVars(void)
{
    gIntroBGParams[0].posX = 0x1C;
    gIntroBGParams[0].posY = 0xFF20;
    gIntroBGParams[0].velX = 0;
    gIntroBGParams[0].velY = 0xF;
    gIntroBGParams[1].posX = 0xFF64;
    gIntroBGParams[1].posY = 0xE0;
    gIntroBGParams[1].velX = 0;
    gIntroBGParams[1].velY = 0xFFF1;
    gIntroBGParams[2].posX = 0;
    gIntroBGParams[2].posY = 0;
    gIntroBGParams[2].animFrame = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void nullsub_9(void)
{
}

void IntroScene4PlussleMinun_28_PlusleMinunTextScroll(void)
{
    gIntroBGParams[0].posY += gIntroBGParams[0].velY;
    gIntroBGParams[1].posY += gIntroBGParams[1].velY;
    gIntroBGParams[2].posX--;
    gIntroBGParams[0].posX--;
    gIntroBGParams[1].posX++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0].velY--;
        gIntroBGParams[1].velY++;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;

    gIntroBGParams[2].animFrame++;
    if (0x27 < gIntroBGParams[2].animFrame)
    {
        gIntroBGParams[2].animFrame = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_10(void)
{
}

void IntroScene4PlussleMinun_30_FlashWhite(void)
{
    // TODO Near duplicate of IntroScene4PlussleMinun_28_PlusleMinunTextScroll
    gIntroBGParams[0].posY += gIntroBGParams[0].velY;
    gIntroBGParams[1].posY += gIntroBGParams[1].velY;
    gIntroBGParams[2].posX--;
    gIntroBGParams[0].posX--;
    gIntroBGParams[1].posX++;

    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroBGParams[0].velY--;
        gIntroBGParams[1].velY++;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[2].posX;

    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene4PlussleMinun_31_ResetTilemap(void)
{
    // TODO Duplicate of IntroScene3Treecko_25_ResetTilemap?
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene5Mudkip_32_LoadMudkipBallScene(void)
{
    // TODO use proper constants - see LoadEReaderGraphics?
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(12) | BGCNT_PRIORITY(0);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_TXT512x256 | BGCNT_SCREENBASE(14) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_TXT512x256 | BGCNT_SCREENBASE(28) | BGCNT_PRIORITY(2);
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(30) | BGCNT_PRIORITY(3);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene5Mudkip_BG0Tiles, BG_CHAR_SCREEN_ADDR(1,4), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene5Mudkip_BG1Tiles, BG_CHAR_SCREEN_ADDR(1,6), 2*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene5Mudkip_BG2Tilemap, BG_CHAR_SCREEN_ADDR(3,4), 2*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene5Mudkip_BG3Tilemap, BG_CHAR_SCREEN_ADDR(3,6), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene5MudkipText_Gfx, BG_CHAR_ADDR(0), 5*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene1TorchicBall_Gfx, gTempGfxBuffer, BG_CHAR_SIZE);
    DmaCopy16(3, gIntroScene5Mudkip_Pal, BG_PLTT_SLOT(0), 12*PLTT_SLOT_SIZE);
    DmaCopy16(3, gIntroScene5MudkipSprites_Gfx, OBJ_VRAM0, 6*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene5Mudkip_Pal, OBJ_PLTT_SLOT(0), 12*PLTT_SLOT_SIZE);

    IntroScene5Mudkip_InitVars();
    IntroScene5Mudkip_RenderAllSprites();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene5Mudkip_InitVars(void)
{
    gIntroSpriteEntities[1].posX = 0xB4;
    gIntroSpriteEntities[1].posY = 0xFFBC;
    gIntroSpriteEntities[0].posX = 0xB4;
    gIntroSpriteEntities[0].posY = 0xFFBC;
    gIntroSpriteEntities[2].posX = 0x80;
    gIntroSpriteEntities[2].posY = 0x88;

    gIntroBGParams[0].posX = 0xFF58;
    gIntroBGParams[0].posY = 0xFF98;
    gIntroBGParams[0].animFrame = 0;
    gIntroBGParams[0].frameTimer = 0;
    gIntroBGParams[0].velX = 0;

    CopyBgTilesRect(&gTextTilemapBuffer, (void *) 0x6002ee0, 8, 8);

    gIntroBGParams[1].posX = 0xA5;
    gIntroBGParams[1].posY = 0;
    gIntroBGParams[1].animFrame = 0;
    gIntroBGParams[2].posX = 0xA0;
    gIntroBGParams[2].posY = 0;
    gIntroBGParams[2].animFrame = 0;
    gIntroBGParams[3].posX = 0;
    gIntroBGParams[3].posY = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void IntroScene5Mudkip_33_MoveMudkipBallSplit(void)
{
    gIntroSpriteEntities[1].posX -= 0x10;
    gIntroSpriteEntities[1].posY += 0xA;
    gIntroSpriteEntities[0].posX -= 0x10;
    gIntroSpriteEntities[0].posY += 0xA;
    gIntroSpriteEntities[2].posX += 0x5;
    gIntroSpriteEntities[2].posY -= 0x3;

    gIntroBGParams[1].posX -= 0x10;
    gIntroBGParams[1].posY++;
    gIntroBGParams[2].posX -= 0x10;
    gIntroBGParams[0].posX += gIntroBGParams[0].velX;
    gIntroBGParams[0].posY += 0x9;
    gIntroBGParams[0].velX++;
    gIntroBGParams[0].frameTimer++;

    if (gIntroBGParams[0].frameTimer > gIntroScene5Mudkip_BGAnimTiming[gIntroBGParams[0].animFrame].y)
    {
        gIntroBGParams[0].animFrame++;
        CopyBgTilesRect(&gTempGfxBuffer[gIntroScene5Mudkip_TileOffsets[gIntroBGParams[0].animFrame]], (void *) 0x6002EE0, 8, 8);
    }

    IntroScene5Mudkip_RenderAllSprites();
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;

    if (++gIntroBGParams[2].animFrame > 9)
    {
        gIntroBGParams[2].animFrame = 0;
        gIntroSceneIndex++;
    }
}

void IntroScene5Mudkip_34_MoveMudkipBallTextScroll(void)
{
    if (++gIntroBGParams[0].frameTimer > gIntroScene5Mudkip_BGAnimTiming[gIntroBGParams[0].animFrame].y)
    {
        if (gIntroBGParams[0].animFrame < 7)
        {
            gIntroBGParams[0].animFrame++;
            CopyBgTilesRect(&gTempGfxBuffer[gIntroScene5Mudkip_TileOffsets[gIntroBGParams[0].animFrame]], (void *) 0x6002EE0, 8, 8);
        }
    }

    IntroScene5Mudkip_RenderAllSprites();
    gIntroBGParams[3].posX++;
    if (gIntroFrameCounter % 2 == 0)
    {
        gIntroSpriteEntities[1].posX--;
        gIntroSpriteEntities[1].posY++;
        gIntroSpriteEntities[0].posX -= 2;
        gIntroSpriteEntities[0].posY += 2;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    if (++gIntroBGParams[3].animFrame > 29)
    {
        gIntroBGParams[3].animFrame = 0;
        gIntroSceneIndex += 2;
    }
}

void nullsub_11(void)
{
}

void IntroScene5Mudkip_36_FlashWhite(void)
{
    FlashWhiteTransitionOut();
    ClearSprites();
    DmaFill32(3, 0, OAM, 0x400);
    DmaFill16(3, 0, OBJ_VRAM0, 0x5000);
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene5Mudkip_RenderAllSprites(void)
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

    mainSg1 = &gMain.spriteGroups[SG_1];
    mainSg0 = &gMain.spriteGroups[SG_0];
    mainSg2 = &gMain.spriteGroups[SG_2];

    mainSg1->active = TRUE;
    mainSg0->active = TRUE;
    mainSg2->active = TRUE;
    LoadSpriteSets(gIntroScene5Mudkip_SpriteSets, 3, gMain.spriteGroups);

    if (mainSg1->active == TRUE)
    {
        mainSg1->baseX = gIntroSpriteEntities[0].posX;
        mainSg1->baseY = gIntroSpriteEntities[0].posY;
        for (i = 0; i < 4; i++)
        {
            oamData = &mainSg1->oam[i];
            gOamBuffer[oamData->oamId].objMode = ST_OAM_OBJ_BLEND;
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
            gOamBuffer[oamData->oamId].objMode = ST_OAM_OBJ_NORMAL;
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

void IntroScene5Mudkip_37_ResetTilemap(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene6Chinchou_38_LoadChinchou(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(15) | BGCNT_PRIORITY(0);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_TXT512x512 | BGCNT_SCREENBASE(26) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(30) | BGCNT_PRIORITY(2);
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(31) | BGCNT_PRIORITY(3);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene6Chinchou_BG0Tilemap, BG_CHAR_SCREEN_ADDR(1,7), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene6Chinchou_BG1Tiles, BG_CHAR_SCREEN_ADDR(3,2), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene6Chinchou_BG2Tilemap, BG_CHAR_SCREEN_ADDR(3,6), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene6Chinchou_BG3Tilemap, BG_CHAR_SCREEN_ADDR(3,7), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene6ChinchouSprites_Gfx, BG_VRAM, 0x6400);
    DmaCopy16(3, gIntroScene6Chinchou_Pal, BG_PLTT_SLOT(0), 4*PLTT_SLOT_SIZE);
    DmaCopy16(3, gIntroScene6ChinchouStars_Gfx, OBJ_VRAM0, 0x1000);
    DmaCopy16(3, gIntroScene6Chinchou_Pal, OBJ_PLTT_SLOT(0), 4*PLTT_SLOT_SIZE);

    IntroScene6Chinchou_InitVars();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene6Chinchou_InitVars(void)
{
    int i;

    gIntroBGParams[1].posX = 0x1E;
    gIntroBGParams[1].posY = 0xFF6A;
    gIntroBGParams[1].animFrame = 0x1;
    gIntroBGParams[0].posX = 0xFFFE;
    gIntroBGParams[0].posY = 0xFFFB;
    gIntroBGParams[0].velX = 0x0;
    gIntroBGParams[0].velY = 0x8;
    gIntroBGParams[2].posX = 0xFF90;
    gIntroBGParams[2].posY = 0xFFD4;
    gIntroBGParams[2].velX = 0x8;
    gIntroBGParams[2].velY = 0x0;
    gIntroBGParams[3].posX = 0x0;
    gIntroBGParams[3].posY = 0x0;

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
        gIntroSpriteEntities[i].visible = FALSE;
    }

    gIntroScene6ChinchouVelocityIndex = 0;
    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
    gIntroScene6ChinchouEntitySpawnIndex = 0;
}

void IntroScene6Chinchou_39_MoveChinchouBallAndStars(void)
{
    gIntroBGParams[1].posX += gIntroScene6Chinchou_ScrollVelocity[gIntroScene6ChinchouVelocityIndex].velocityX;
    gIntroBGParams[1].posY += gIntroScene6Chinchou_ScrollVelocity[gIntroScene6ChinchouVelocityIndex].velocityY;

    if (gIntroScene6Chinchou_BounceFlags[gIntroFrameCounter] & 0x10)
    {
        gIntroBGParams[0].posY += gIntroBGParams[0].velY;
        gIntroBGParams[0].velY -= 2;
        if (gIntroBGParams[0].velY <= -0xA)
            gIntroBGParams[0].velY = 0x8;
    }

    if (gIntroScene6Chinchou_BounceFlags[gIntroFrameCounter] & 0x1)
    {
        gIntroBGParams[2].posX += gIntroBGParams[2].velX;
        gIntroBGParams[2].velX -= 2;
        if (gIntroBGParams[2].velX <= -10)
            gIntroBGParams[2].velX = 8;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;

    if (gIntroFrameCounter == gIntroScene6Chinchou_EntityMovement[gIntroScene6ChinchouEntitySpawnIndex].frameDuration)
    {
        gIntroSpriteEntities[gIntroScene6ChinchouEntitySpawnIndex].visible = TRUE;
        gIntroScene6ChinchouEntitySpawnIndex++;
    }

    IntroScene6Chinchou_RenderStarSprites();
    if (++gIntroAnimStep > gIntroScene6Chinchou_ScrollVelocity[gIntroScene6ChinchouVelocityIndex].frameDuration)
    {
        gIntroAnimStep = 0;
        if (++gIntroScene6ChinchouVelocityIndex > 8)
            gIntroSceneIndex++;
    }
}

void IntroScene6Chinchou_40_MoveChinchouAndStars(void)
{
    if (gIntroScene6Chinchou_BounceFlags[gIntroFrameCounter] & 0x10)
    {
        gIntroBGParams[0].posY += gIntroBGParams[0].velY;
        gIntroBGParams[0].velY -= 2;
        if (gIntroBGParams[0].velY <= -10)
            gIntroBGParams[0].velY = 8;
    }

    if (gIntroScene6Chinchou_BounceFlags[gIntroFrameCounter] & 0x1)
    {
        gIntroBGParams[2].posX += gIntroBGParams[2].velX;
        gIntroBGParams[2].velX -= 2;
        if (gIntroBGParams[2].velX <= -10)
            gIntroBGParams[2].velX = 8;
    }

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;

    IntroScene6Chinchou_RenderStarSprites();
    if (++gIntroAnimStep > 16)
    {
        gIntroAnimStep = 0;
        gIntroSceneIndex++;
    }
}

void IntroScene6Chinchou_41_FlashWhiteClearSprites(void)
{
    ClearSprites();
    DmaFill32(3, 0, OAM, 0x400);
    DmaFill16(3, 0, OBJ_VRAM0, 0x5000);
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene6Chinchou_RenderStarSprites(void)
{
    s32 i;
    s32 j;
    const struct SpriteSet *p;
    struct SpriteGroup *spriteGroups[6];

    spriteGroups[0] = &gMain.spriteGroups[SG_0 + (6 * gIntroSpriteEntities[0].animFrame)];
    spriteGroups[1] = &gMain.spriteGroups[SG_1 + (6 * gIntroSpriteEntities[1].animFrame)];
    spriteGroups[2] = &gMain.spriteGroups[SG_2 + (6 * gIntroSpriteEntities[2].animFrame)];
    spriteGroups[3] = &gMain.spriteGroups[SG_3 + (6 * gIntroSpriteEntities[3].animFrame)];
    spriteGroups[4] = &gMain.spriteGroups[SG_4 + (6 * gIntroSpriteEntities[4].animFrame)];
    spriteGroups[5] = &gMain.spriteGroups[SG_5 + (6 * gIntroSpriteEntities[5].animFrame)];

    spriteGroups[0]->active = gIntroSpriteEntities[0].visible;
    spriteGroups[1]->active = gIntroSpriteEntities[1].visible;
    spriteGroups[2]->active = gIntroSpriteEntities[2].visible;
    spriteGroups[3]->active = gIntroSpriteEntities[3].visible;
    spriteGroups[4]->active = gIntroSpriteEntities[4].visible;
    spriteGroups[5]->active = gIntroSpriteEntities[5].visible;

    LoadSpriteSets(gIntroScene6Chinchou_SpriteSets, 0x12, &gMain.spriteGroups[SG_0]);
    for (i = 0; i < 6; i++)
    {
        if (spriteGroups[i]->active != TRUE)
            continue;

        gIntroSpriteEntities[i].posX += gIntroScene6Chinchou_EntityMovement[i].velocityX;
        gIntroSpriteEntities[i].posY += gIntroScene6Chinchou_EntityMovement[i].velocityY;
        spriteGroups[i]->baseX = gIntroSpriteEntities[i].posX;
        spriteGroups[i]->baseY = gIntroSpriteEntities[i].posY;

        p = gIntroScene6Chinchou_SpriteSets[i + gIntroSpriteEntities[i].animFrame * 6];
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

        if (gIntroFrameCounter == gIntroScene6Chinchou_EntityMovement[i].spawnFrame)
            gIntroSpriteEntities[i].visible = FALSE;
    }

    spriteGroups[0]->active = FALSE;
    spriteGroups[1]->active = FALSE;
    spriteGroups[2]->active = FALSE;
    spriteGroups[3]->active = FALSE;
    spriteGroups[4]->active = FALSE;
    spriteGroups[5]->active = FALSE;
}

void IntroScene6Chinchou_42_FrameAdvance(void)
{
    gIntroSceneIndex++;
}

void IntroScene7Parade_43_LoadPinkYellowBackground(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG0CNT = BGCNT_TXT512x512 | BGCNT_SCREENBASE(20) | BGCNT_PRIORITY(0);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    REG_BG1CNT = BGCNT_TXT512x512 | BGCNT_SCREENBASE(24) | BGCNT_PRIORITY(1);
    REG_DISPCNT |= DISPCNT_BG1_ON;
    REG_BG2CNT = BGCNT_TXT512x512 | BGCNT_SCREENBASE(28) | BGCNT_PRIORITY(2);
    REG_DISPCNT |= DISPCNT_BG2_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(15) | BGCNT_PRIORITY(3);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene7Parade_BG0Tiles, BG_CHAR_SCREEN_ADDR(2,4), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene7Parade_BG1Tiles, BG_CHAR_SCREEN_ADDR(3,0), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene7Parade_BG2Tiles, BG_CHAR_SCREEN_ADDR(3,4), 4*BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene7Parade_BG3Tilemap, BG_CHAR_SCREEN_ADDR(1,7), BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene7ParadeSprites_Gfx, BG_VRAM, 0x5000);
    DmaCopy16(3, gIntroScene7Parade_Pal, BG_PLTT_SLOT(0), 11*PLTT_SLOT_SIZE);
    DmaCopy16(3, gIntroScene7ParadeWailmer_Gfx, OBJ_VRAM0, 0x2000);
    DmaCopy16(3, gIntroScene7Parade_Pal, OBJ_PLTT_SLOT(0), 11*PLTT_SLOT_SIZE);

    gMain.dispcntBackup = REG_DISPCNT;
    IntroScene7Parade_InitVars();

    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene7Parade_InitVars(void)
{
    gIntroBGParams[0].posX = 0xFEFC;
    gIntroBGParams[0].posY = 0x46;
    gIntroBGParams[0].velY = 0;
    gIntroBGParams[1].posX = 0xFEE8;
    gIntroBGParams[1].posY = 0x5A;
    gIntroBGParams[1].velY = 0;
    gIntroBGParams[2].posX = 0xFF10;
    gIntroBGParams[2].posY = 0xFFCE;
    gIntroBGParams[2].velY = 0xFFFD;
    gIntroBGParams[3].posX = 0;
    gIntroBGParams[3].posY = 0;

    gIntroSpriteEntities[0].posX = 0x128;
    gIntroSpriteEntities[0].posY = 0x2C;
    gIntroSpriteEntities[0].velX = 0;
    gIntroSpriteEntities[0].velY = 0;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
    gIntroWailmerScaleX = 0x100;
    gIntroWailmerScaleY = 0x100;
}

void IntroScene7Parade_44_MoveMakuhita(void)
{
    gIntroBGParams[2].posX += 2;
    gIntroBGParams[2].posY -= gIntroBGParams[2].velY;
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[2].velY > 4)
            gIntroBGParams[2].velY = -3;
    }

    gIntroBGParams[3].posX--;
    gIntroBGParams[3].posY--;

    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    if (gIntroFrameCounter > 32)
        gIntroSceneIndex++;
}

void IntroScene7Parade_45_MoveMakuhitaAndSpoink(void)
{
    gIntroBGParams[2].posX += 2;
    gIntroBGParams[2].posY -= gIntroBGParams[2].velY;
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[2].velY > 4)
            gIntroBGParams[2].velY = -3;
    }

    gIntroBGParams[1].posX += 3;
    gIntroBGParams[1].posY -= gIntroBGParams[1].velY;
    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroBGParams[1].velY > 7)
            gIntroBGParams[1].velY = -6;
    }

    gIntroBGParams[3].posX--;
    gIntroBGParams[3].posY--;

    // TODO rearrangement like this suggests one inline function per pair of statements, but see IntroScene1_00_LoadTitleLettersAndTorchicScene
    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    if (gIntroFrameCounter > 80)
        gIntroSceneIndex++;
}

void IntroScene7Parade_46_MoveMakuhitaPelipperAndSpoink(void)
{
    gIntroBGParams[2].posX += 2;
    gIntroBGParams[2].posY -= gIntroBGParams[2].velY;
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[2].velY > 4)
            gIntroBGParams[2].velY = -3;
    }

    gIntroBGParams[1].posX += 3;
    gIntroBGParams[1].posY -= gIntroBGParams[1].velY;
    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroBGParams[1].velY > 7)
            gIntroBGParams[1].velY = -6;
    }

    gIntroBGParams[0].posX += 4;
    gIntroBGParams[0].posY -= gIntroBGParams[0].velY;
    if (gIntroFrameCounter % 4 == 0)
    {
        if (++gIntroBGParams[0].velY > 7)
            gIntroBGParams[0].velY = -3;
    }

    gIntroBGParams[3].posX--;
    gIntroBGParams[3].posY--;

    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    if (gIntroFrameCounter > 100)
        gIntroSceneIndex++;
}

void IntroScene7Parade_47_MoveMakuhitaPelipperWailmerAndSpoink(void)
{
    gIntroBGParams[2].posX += 2;
    gIntroBGParams[2].posY -= gIntroBGParams[2].velY;
    if (gIntroFrameCounter % 3 == 0)
    {
        if (++gIntroBGParams[2].velY > 4)
            gIntroBGParams[2].velY = -3;
    }

    gIntroBGParams[1].posX += 3;
    gIntroBGParams[1].posY -= gIntroBGParams[1].velY;
    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroBGParams[1].velY > 7)
            gIntroBGParams[1].velY = -6;
    }

    gIntroBGParams[0].posX += 4;
    gIntroBGParams[0].posY -= gIntroBGParams[0].velY;
    if (gIntroFrameCounter % 4 == 0)
    {
        if (++gIntroBGParams[0].velY > 7)
            gIntroBGParams[0].velY = -3;
    }

    gIntroSpriteEntities[0].posX -= 2;
    gIntroSpriteEntities[0].posY += gIntroSpriteEntities[0].velY;
    if (gIntroFrameCounter % 4 == 0)
    {
        if (++gIntroSpriteEntities[0].velY > 4)
            gIntroSpriteEntities[0].velY = -4;
    }

    gIntroBGParams[3].posX--;
    gIntroBGParams[3].posY--;

    gMain.bgOffsets[2].xOffset = gIntroBGParams[2].posX;
    gMain.bgOffsets[2].yOffset = gIntroBGParams[2].posY;
    gMain.bgOffsets[1].xOffset = gIntroBGParams[1].posX;
    gMain.bgOffsets[1].yOffset = gIntroBGParams[1].posY;
    gMain.bgOffsets[0].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[0].yOffset = gIntroBGParams[0].posY;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    IntroScene7Parade_RenderWailmer();
    if (gIntroFrameCounter > 192)
        gIntroSceneIndex++;
}

void IntroScene7Parade_48_MoveWailmerShake(void)
{
    int remainder;

    gIntroBGParams[3].posX--;
    gIntroBGParams[3].posY--;

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

    gMain.bgOffsets[3].xOffset = gIntroBGParams[3].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[3].posY;

    IntroScene7Parade_RenderWailmer();
    if (gIntroFrameCounter > 222)
        gIntroSceneIndex++;
}

void IntroScene7Parade_49_FlashWhite(void)
{
    FlashWhiteTransitionOut();
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene7Parade_RenderWailmer(void)
{
    s32 i;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamData;

    spriteGroup = &gMain.spriteGroups[SG_0];
    spriteGroup->active = TRUE;
    LoadSpriteSets(gIntroScene7Parade_SpriteSets, 0x1, gMain.spriteGroups);
    if (spriteGroup->active == TRUE)
    {
        SetMatrixScale(gIntroWailmerScaleX, gIntroWailmerScaleY, 0);
        spriteGroup->baseX = gIntroSpriteEntities[0].posX;
        spriteGroup->baseY = gIntroSpriteEntities[0].posY;
        for (i = 0; i < 4; i++)
        {
            oamData = &spriteGroup->oam[i];
            gOamBuffer[oamData->oamId].priority = 1;
            gOamBuffer[oamData->oamId].x = gIntroScene7Parade_WailmerQuadOffsets[i].x * gIntroWailmerScaleX / 0x100 + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = gIntroScene7Parade_WailmerQuadOffsets[i].y * gIntroWailmerScaleY / 0x100 + spriteGroup->baseY;
            gOamBuffer[oamData->oamId].affineMode = ST_OAM_AFFINE_NORMAL;
            gOamBuffer[oamData->oamId].matrixNum = 0;
        }
    }

    spriteGroup->active = FALSE;
}

void IntroScene7Parade_50_ResetTilemap(void)
{
    ClearBgTilemapAndOffsets();
    gIntroSceneIndex++;
}

void IntroScene8WailmerLaunch_51_LoadWailmerBlastBackground(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(3) | BGCNT_CHARBASE(1);
    REG_DISPCNT |= DISPCNT_BG2_ON;

    DmaCopy16(3, gIntroScene8WailmerLaunch_BG2Tilemap, BG_VRAM, BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene8WailmerLaunchExplosion_Gfx, BG_CHAR_SCREEN_ADDR(1,0), 0x3400);
    DmaCopy16(3, gIntroScene8WailmerLaunch_Pal, BG_PLTT_SLOT(0), 10*PLTT_SLOT_SIZE);
    DmaCopy16(3, gIntroScene8WailmerLaunch_Gfx, OBJ_VRAM0, 0x2C00);
    DmaCopy16(3, gIntroScene8WailmerLaunch_Pal, OBJ_PLTT_SLOT(0), 10*PLTT_SLOT_SIZE);

    gMain.dispcntBackup = REG_DISPCNT;
    IntroScene8WailmerLaunch_InitVars();
    IntroScene8WailmerLaunch_RenderAllSprites();
    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene8WailmerLaunch_InitVars(void)
{
    gIntroSpriteEntities[1].posX = 0x78;
    gIntroSpriteEntities[1].posY = 0x50;
    gIntroSpriteEntities[1].velX = 0x4;
    gIntroSpriteEntities[1].velY = 0x4;
    gIntroSpriteEntities[1].animFrame = 0;

    gIntroSpriteEntities[0].posX = 0x78;
    gIntroSpriteEntities[0].posY = 0x50;
    gIntroSpriteEntities[0].visible = FALSE;

    gIntroSpriteEntities[2].posX = 0x80;
    gIntroSpriteEntities[2].posY = 0x58;
    gIntroSpriteEntities[2].animFrame = 0;
    gIntroSpriteEntities[2].frameTimer = 0;
    gIntroSpriteEntities[2].visible = FALSE;

    gIntroSpriteEntities[3].posX = 0x80;
    gIntroSpriteEntities[3].posY = 0x48;
    gIntroSpriteEntities[3].animFrame = 0;
    gIntroSpriteEntities[3].frameTimer = 0;
    gIntroSpriteEntities[3].visible = FALSE;

    gIntroSpriteEntities[4].posX = 0x70;
    gIntroSpriteEntities[4].posY = 0x58;
    gIntroSpriteEntities[4].animFrame = 0;
    gIntroSpriteEntities[4].frameTimer = 0;
    gIntroSpriteEntities[4].visible = FALSE;

    gIntroSpriteEntities[5].posX = 0x78;
    gIntroSpriteEntities[5].posY = 0x58;
    gIntroSpriteEntities[5].animFrame = 0;
    gIntroSpriteEntities[5].frameTimer = 0;
    gIntroSpriteEntities[5].visible = FALSE;

    // TODO FIXME overlapping symbols (gAutoDisplayTitlescreenMenu)
    gIntroSpriteEntities[6].posX = 0x70;
    gIntroSpriteEntities[6].posY = 0x48;
    gIntroSpriteEntities[6].animFrame = 0;
    gIntroSpriteEntities[6].frameTimer = 0;
    gIntroSpriteEntities[6].visible = FALSE;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
}

void IntroScene8WailmerLaunch_52_BallAppearTimer(void)
{
    IntroScene8WailmerLaunch_RenderAllSprites();

    if (gIntroFrameCounter > 1)
    {
        gIntroSpriteEntities[0].visible = TRUE;
        gIntroSpriteEntities[2].visible = TRUE;
        gIntroSpriteEntities[3].visible = TRUE;
        gIntroSpriteEntities[4].visible = TRUE;
        gIntroSpriteEntities[5].visible = TRUE;
        gIntroSpriteEntities[6].visible = TRUE; // TODO FIXME overlapping symbols (gAutoDisplayTitlescreenMenu)
        gIntroSceneIndex++;
    }
}

void IntroScene8WailmerLaunch_53_MoveBallStarsAndWailmer(void)
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

    IntroScene8WailmerLaunch_RenderAllSprites();
    if (gIntroSpriteEntities[0].posY < -32)
        gIntroSceneIndex++;
}

void IntroScene8WailmerLaunch_54_MoveStarsAndWailmer(void)
{
    IntroScene8WailmerLaunch_RenderAllSprites();

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

void IntroScene8WailmerLaunch_57_FlashWhiteClearSprites(void)
{
    FlashWhiteTransitionOut();
    ClearSprites();
    DmaFill32(3, 0, OAM, 0x400);
    DmaFill16(3, 0, OBJ_VRAM0, 0x5000);
    DisableDisplayInterrupts();
    gIntroSceneIndex++;
}

void IntroScene8WailmerLaunch_RenderAllSprites(void)
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


    sg0 = &gMain.spriteGroups[SG_0];
    sg1 = &gMain.spriteGroups[SG_1];

    spriteGroups[0] = &gMain.spriteGroups[SG_2 + (5 * gIntroSpriteEntities[2].animFrame)];
    spriteGroups[1] = &gMain.spriteGroups[SG_3 + (5 * gIntroSpriteEntities[3].animFrame)];
    spriteGroups[2] = &gMain.spriteGroups[SG_4 + (5 * gIntroSpriteEntities[4].animFrame)];
    spriteGroups[3] = &gMain.spriteGroups[SG_5 + (5 * gIntroSpriteEntities[5].animFrame)];
    spriteGroups[4] = &gMain.spriteGroups[SG_6 + (5 * gIntroSpriteEntities[6].animFrame)];


    sg0->active = gIntroSpriteEntities[0].visible;
    sg1->active = TRUE;

    spriteGroups[0]->active = gIntroSpriteEntities[2].visible;
    spriteGroups[1]->active = gIntroSpriteEntities[3].visible;
    spriteGroups[2]->active = gIntroSpriteEntities[4].visible;
    spriteGroups[3]->active = gIntroSpriteEntities[5].visible;
    spriteGroups[4]->active = gIntroSpriteEntities[6].visible;

    LoadSpriteSets(gIntroScene8WailmerLaunch_SpriteSets, 0x11, gMain.spriteGroups);

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
                cVar1 = gIntroScene8WailmerLaunch_DebrisMovement[i].lateVelX;
                cVar2 = gIntroScene8WailmerLaunch_DebrisMovement[i].lateVelY;
            }
            else
            {
                cVar1 = gIntroScene8WailmerLaunch_DebrisMovement[i].earlyVelX;
                cVar2 = gIntroScene8WailmerLaunch_DebrisMovement[i].earlyVelY;
            }

            gIntroSpriteEntities[2 + i].posX += cVar1;
            gIntroSpriteEntities[2 + i].posY += cVar2;
            spriteGroups[i]->baseX = gIntroSpriteEntities[2 + i].posX;
            spriteGroups[i]->baseY = gIntroSpriteEntities[2 + i].posY;

            p = gIntroScene8WailmerLaunch_SpriteSets[( 2 + i) + (5 * gIntroSpriteEntities[2 + i].animFrame)];

            for (j = 0; j < p->count; j++)
            {
                oamData = &spriteGroups[i]->oam[j];
                gOamBuffer[oamData->oamId].priority = (&gIntroScene8WailmerLaunch_DebrisMovement[i])->oamPriority;
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
void IntroScene8WailmerLaunch_58_ResetTilemap(void)
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
        gOamBuffer[i].affineMode = ST_OAM_AFFINE_OFF;
        gOamBuffer[i].objMode = ST_OAM_OBJ_NORMAL;
        gOamBuffer[i].mosaic = 0;
        gOamBuffer[i].bpp = 0x0;
        gOamBuffer[i].shape = 0;
        gOamBuffer[i].x = -12;
        gOamBuffer[i].matrixNum = 0;
        gOamBuffer[i].hFlip = FALSE;
        gOamBuffer[i].vFlip = FALSE;
        gOamBuffer[i].size = 0;
        gOamBuffer[i].tileNum = 0;
        gOamBuffer[i].priority = 0;
        gOamBuffer[i].paletteNum = 0;
        gOamBuffer[i].affineParam = 0;
    }

    gIntroSceneIndex++;
}

void IntroScene9BallFlight_59_LoadSkySpeedOrbs(void)
{
    REG_DISPCNT = DISPCNT_OBJ_ON;
    REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(3) | BGCNT_CHARBASE(1);
    REG_DISPCNT |= DISPCNT_BG3_ON;

    DmaCopy16(3, gIntroScene9BallFlight_BG3Tilemap, BG_VRAM, BG_SCREEN_SIZE);
    DmaCopy16(3, gIntroScene9BallFlightClouds_Gfx, BG_CHAR_SCREEN_ADDR(1,0), 0x2400);
    DmaCopy16(3, gIntroScene9BallFlight_Pal, BG_PLTT_SLOT(0), 2*PLTT_SLOT_SIZE);
    DmaCopy16(3, gIntroScene9BallFlightall_Gfx, OBJ_VRAM0, 0x7000);
    DmaCopy16(3, gIntroScene9BallFlight_Pal, OBJ_PLTT_SLOT(0), 2*PLTT_SLOT_SIZE);

    gMain.dispcntBackup = REG_DISPCNT;
    IntroScene9BallFlight_InitVars();
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0].posX;
    gMain.bgOffsets[3].yOffset = gIntroBGParams[0].posY;
    EnableVBlankInterrupts();
    FlashWhiteTransitionIn();
    gIntroSceneIndex++;
}

void IntroScene9BallFlight_InitVars(void)
{
    gIntroBGParams[0].posX = 0;
    gIntroBGParams[0].posY = 0;

    gIntroSpriteEntities[0].posX = 0xF0;
    gIntroSpriteEntities[0].posY = 0x1E;
    gIntroSpriteEntities[0].velX = 0xE;
    gIntroSpriteEntities[0].animFrame = 0x1;
    gIntroSpriteEntities[0].visible = TRUE;

    gIntroSpriteEntities[1].posX = 0x108;
    gIntroSpriteEntities[1].posY = 0x50;
    gIntroSpriteEntities[1].velX = 0x6;
    gIntroSpriteEntities[1].visible = FALSE;

    gIntroFrameCounter = 0;
    gIntroAnimStep = 0;
    gIntroWailmerScaleX = 0x100;
    gIntroWailmerScaleY = 0x100;
    gIntroObjWhiteFlash = 0;
    gIntroBGWhiteFlash = 0;
}

void IntroScene9BallFlight_60_MoveBallAndSky(void)
{
    gIntroBGParams[0].posX -= 0x24;
    gIntroSpriteEntities[0].posX -= gIntroScene9BallFlight_BallXFrameAdjustTable[gIntroAnimStep];
    gIntroAnimStep++;

    if (gIntroFrameCounter % 5 == 0)
    {
        if (++gIntroSpriteEntities[0].animFrame > 10)
            gIntroSpriteEntities[0].animFrame = 1;
    }

    gMain.bgOffsets[3].xOffset = gIntroBGParams[0].posX;
    IntroScene9BallFlight_RenderBallAndCloud();

    if (gIntroFrameCounter > 40)
    {
        gIntroWailmerScaleX += 6;
        gIntroWailmerScaleY += 6;
        if (gIntroFrameCounter % 2 == 0)
            gIntroSpriteEntities[0].posY++;
    }

    if (gIntroFrameCounter > 90)
    {
        gIntroSpriteEntities[0].visible = FALSE;
        gIntroSpriteEntities[1].visible = TRUE;
        gIntroSceneIndex++;
    }
}

void IntroScene9BallFlight_61_MoveSky(void)
{
    gIntroBGParams[0].posX -= 0x24;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0].posX;
    if (gIntroFrameCounter > 120)
        gIntroSceneIndex++;
}

void IntroScene9BallFlight_62_MoveBallSkyFadeWhite(void)
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

    BrightenPalette(gIntroScene9BallFlight_Pal, (u8 *)OBJ_PLTT_SLOT(0), 0x20, gIntroObjWhiteFlash);
    if (gIntroFrameCounter > 136)
    {
        gIntroBGWhiteFlash += 2;
        if (gIntroBGWhiteFlash > 32)
            gIntroBGWhiteFlash = 0x20;

        BrightenPalette(gIntroScene9BallFlight_Pal, (u8 *)BG_PLTT_SLOT(0), 0x40, gIntroBGWhiteFlash);
    }

    gIntroBGParams[0].posX -= 0x24;
    gMain.bgOffsets[3].xOffset = gIntroBGParams[0].posX;
    IntroScene9BallFlight_RenderBallAndCloud();

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

void IntroSceneX_64_HoldWhitescreen(void)
{
    if (gIntroFrameCounter % 10 == 0)
    {
        gIntroAnimStep++;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, (0x100 / gIntroAnimStep));
    }

    if (gIntroFrameCounter > 45)
        gIntroSceneIndex++;
}

void IntroSceneX_64_EndIntro(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gMain.subState++;
}

void IntroScene9BallFlight_RenderBallAndCloud(void)
{
    int i;
    struct SpriteGroup *spriteGroup0;
    struct SpriteGroup *spriteGroup1;
    struct OamDataSimple *oamData;

    spriteGroup0 = &gMain.spriteGroups[SG_0 + gIntroSpriteEntities[0].animFrame];
    spriteGroup1 = &gMain.spriteGroups[SG_0];
    spriteGroup0->active = gIntroSpriteEntities[0].visible;
    spriteGroup1->active = gIntroSpriteEntities[1].visible;
    LoadSpriteSets(gIntroScene9BallFlight_SpriteSets, 11, gMain.spriteGroups);
    if (spriteGroup0->active == TRUE)
    {
        SetMatrixScale(gIntroWailmerScaleX, gIntroWailmerScaleY, 0);
        spriteGroup0->baseX = gIntroSpriteEntities[0].posX;
        spriteGroup0->baseY = gIntroSpriteEntities[0].posY;
        oamData = &spriteGroup0->oam[0];
        gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup0->baseX;
        gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup0->baseY;
        gOamBuffer[oamData->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
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
