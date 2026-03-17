#include "global.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "main.h"
#include "m4a.h"
#include "titlescreen.h"

static void RenderFieldSelectSprites(void);
static void InitFieldSelectData(void);

enum FieldSelectStates
{
    FIELD_SELECT_STATE_CHOOSE_FIELD,
    FIELD_SELECT_STATE_1,
    FIELD_SELECT_STATE_BALL_SPEED,
    FIELD_SELECT_STATE_3,
};

struct FieldSelectData
{
    u16 rubyFieldSpriteId;
    u16 sapphireFieldSpriteId;
    u16 rubyHighlightVisible;
    u16 sapphireHighlightVisible;
    u16 selectedField;
    u16 state;
    s16 transitionFrame;
    s16 speedBlinkTimer;
    u8 ballSpeed;
    s16 speedBlinkToggle;
    s8 ballSpeedVisible;
    u16 nextMainState;
};

extern struct FieldSelectData gFieldSelectData;

void FieldSelectMain(void)
{
    gFieldSelectStateFuncs[gMain.subState]();
}

void LoadFieldSelectGraphics(void)
{
    ResetDisplayState();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;

    REG_BG0CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(0) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG0_ON;

    REG_BG1CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;

    REG_BG2CNT = BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(2) | BGCNT_PRIORITY(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;

    gMain.dispcntBackup = REG_DISPCNT;

    DmaCopy16(3, gFieldSelectBGPals,             (void *)(PLTT),           0x200);
    DmaCopy16(3, gFieldSelectWindow_Gfx,         (void *)(VRAM + 0x4000),  0x1400);
    DmaCopy16(3, gFieldSelectMiniFields_Gfx,     (void *)(VRAM + 0x8000),  0x3800);
    DmaCopy16(3, gFieldSelectBG0Tilemap,              (void *)(VRAM),           0x800);
    DmaCopy16(3, gFieldSelectFrameShadowTilemap, (void *)(VRAM + 0x800),   0x800);
    DmaCopy16(3, gFieldSelectWindowTilemap,      (void *)(VRAM + 0x1000),  0x800);
    DmaCopy16(3, gFieldSelectSpritePals,         (void *)(PLTT + 0x200),   0x200);
    DmaCopy16(3, gFieldSelectSpriteGfx,          (void *)(VRAM + 0x10000), 0x4020);

    EnableVBlankInterrupts();
    InitFieldSelectData();
    FadeInFromWhite(RenderFieldSelectSprites);
    gMain.subState++;
    m4aSongNumStart(MUS_TABLE_SELECT);
}

static void InitFieldSelectData(void)
{
    gFieldSelectData.rubyFieldSpriteId = 2;
    gFieldSelectData.sapphireFieldSpriteId = 3;
    gFieldSelectData.rubyHighlightVisible = 0;
    gFieldSelectData.sapphireHighlightVisible = 1;
    gFieldSelectData.selectedField = FIELD_RUBY;
    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
    gFieldSelectData.transitionFrame = 0;
    gFieldSelectData.speedBlinkTimer = 0;
    gFieldSelectData.nextMainState = STATE_INTRO;
    gFieldSelectData.speedBlinkToggle = 0;
    gFieldSelectData.ballSpeedVisible = 0;

    gFieldSelectData.ballSpeed = gMain_saveData.ballSpeed;
    gMain.selectedField = FIELD_RUBY;
    gFieldSelectSoftReset = 0;
}

#define RESTART_GAME_BUTTONS (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)

void FieldSelect_State1_8C7C(void)
{
    RenderFieldSelectSprites();
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gFieldSelectSoftReset = 1;
        gFieldSelectData.nextMainState = STATE_INTRO;
        gMain.subState++;
    }
    if (gFieldSelectSoftReset == 0)
    {
        switch (gFieldSelectData.state)
        {
        case FIELD_SELECT_STATE_CHOOSE_FIELD:
            if (JOY_NEW(DPAD_LEFT))
            {
                if (gFieldSelectData.selectedField == FIELD_SAPPHIRE)
                {
                    m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                    gFieldSelectData.selectedField = FIELD_RUBY;
                    gFieldSelectData.rubyHighlightVisible = 0;
                    gFieldSelectData.sapphireHighlightVisible = 1;
                    gFieldSelectData.state = FIELD_SELECT_STATE_1;
                }
            }
            else if (JOY_NEW(DPAD_RIGHT))
            {
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                    gFieldSelectData.selectedField = FIELD_SAPPHIRE;
                    gFieldSelectData.rubyHighlightVisible = 1;
                    gFieldSelectData.sapphireHighlightVisible = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_1;
                }
            }
            if (JOY_NEW(A_BUTTON))
            {
                m4aSongNumStart(SE_MENU_SELECT);
                gFieldSelectData.state = FIELD_SELECT_STATE_BALL_SPEED;
                gFieldSelectData.ballSpeedVisible = 1;
                gFieldSelectData.speedBlinkTimer = 0;
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    gFieldSelectData.rubyHighlightVisible = 0;
                    gFieldSelectData.sapphireHighlightVisible = 1;
                    gFieldSelectData.rubyFieldSpriteId = 2;
                    gFieldSelectData.sapphireFieldSpriteId = 3;
                    gFieldSelectData.transitionFrame = 0;
                }
                else
                {
                    gFieldSelectData.rubyHighlightVisible = 1;
                    gFieldSelectData.sapphireHighlightVisible = 0;
                    gFieldSelectData.rubyFieldSpriteId = 7;
                    gFieldSelectData.sapphireFieldSpriteId = 11;
                    gFieldSelectData.transitionFrame = 0;
                }
            }
            if (JOY_NEW(B_BUTTON))
            {
                m4aSongNumStart(SE_MENU_CANCEL);
                gMain.subState++;
                gFieldSelectData.nextMainState = STATE_TITLE;
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    gFieldSelectData.rubyHighlightVisible = 0;
                    gFieldSelectData.sapphireHighlightVisible = 1;
                    gFieldSelectData.rubyFieldSpriteId = 2;
                    gFieldSelectData.sapphireFieldSpriteId = 3;
                    gFieldSelectData.transitionFrame = 0;
                }
                else
                {
                    gFieldSelectData.rubyHighlightVisible = 1;
                    gFieldSelectData.sapphireHighlightVisible = 0;
                    gFieldSelectData.rubyFieldSpriteId = 7;
                    gFieldSelectData.sapphireFieldSpriteId = 11;
                    gFieldSelectData.transitionFrame = 0;
                }
            }
            if (gMain.selectedField < MAIN_FIELD_COUNT)
                gMain.isBonusField = 0;
            else
                gMain.isBonusField = 1;
            break;
        case FIELD_SELECT_STATE_BALL_SPEED:
            if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
            {
                m4aSongNumStart(SE_MENU_MOVE);
                gFieldSelectData.ballSpeed = 1 - gFieldSelectData.ballSpeed;
            }
            if (JOY_NEW(A_BUTTON))
            {
                m4aSongNumStart(SE_MENU_SELECT);
                gFieldSelectData.speedBlinkTimer = 0;
                gFieldSelectData.transitionFrame = 0;
                gMain_saveData.ballSpeed = gFieldSelectData.ballSpeed;
                SaveFile_WriteToSram();
                gFieldSelectData.state = FIELD_SELECT_STATE_3;
            }
            if (JOY_NEW(B_BUTTON))
            {
                m4aSongNumStart(SE_MENU_CANCEL);
                gFieldSelectData.ballSpeedVisible = 0;
                gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
            }
            gFieldSelectData.speedBlinkTimer++;
            if (gFieldSelectData.speedBlinkTimer > 4)
            {
                gFieldSelectData.speedBlinkTimer = 0;
                gFieldSelectData.speedBlinkToggle = 1 - gFieldSelectData.speedBlinkToggle;
            }
            break;
        case FIELD_SELECT_STATE_1:
            if (gFieldSelectData.selectedField == FIELD_RUBY)
            {
                gFieldSelectData.rubyFieldSpriteId = gFieldTransitionAnimData.rubyTransitionFrames[4 - gFieldSelectData.transitionFrame];
                gFieldSelectData.sapphireFieldSpriteId = gFieldTransitionAnimData.sapphireTransitionFrames[4 - gFieldSelectData.transitionFrame];
            }
            else
            {
                gFieldSelectData.rubyFieldSpriteId = gFieldTransitionAnimData.rubyTransitionFrames[gFieldSelectData.transitionFrame];
                gFieldSelectData.sapphireFieldSpriteId = gFieldTransitionAnimData.sapphireTransitionFrames[gFieldSelectData.transitionFrame];
            }
            if (!(gMain.systemFrameCount & 1))
            {
                if (gFieldSelectData.transitionFrame < 4)
                {
                    gFieldSelectData.transitionFrame++;
                }
                else
                {
                    gFieldSelectData.transitionFrame = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
                }
            }
            if (JOY_NEW(DPAD_LEFT))
            {
                if (gFieldSelectData.selectedField == FIELD_SAPPHIRE)
                {
                    m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                    gFieldSelectData.selectedField = FIELD_RUBY;
                    gFieldSelectData.rubyHighlightVisible = 0;
                    gFieldSelectData.sapphireHighlightVisible = 1;
                    gFieldSelectData.rubyFieldSpriteId = 2;
                    gFieldSelectData.sapphireFieldSpriteId = 3;
                    gFieldSelectData.transitionFrame = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
                }
            }
            else if (JOY_NEW(DPAD_RIGHT))
            {
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                    gFieldSelectData.selectedField = FIELD_SAPPHIRE;
                    gFieldSelectData.rubyHighlightVisible = 1;
                    gFieldSelectData.sapphireHighlightVisible = 0;
                    gFieldSelectData.rubyFieldSpriteId = 7;
                    gFieldSelectData.sapphireFieldSpriteId = 11;
                    gFieldSelectData.transitionFrame = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
                }
            }
            break;
        case FIELD_SELECT_STATE_3:
            gFieldSelectData.speedBlinkTimer++;
            if (gFieldSelectData.speedBlinkTimer > 3)
            {
                gFieldSelectData.speedBlinkTimer = 0;
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                    gFieldSelectData.rubyHighlightVisible = 1 - gFieldSelectData.rubyHighlightVisible;
                else
                    gFieldSelectData.sapphireHighlightVisible = 1 - gFieldSelectData.sapphireHighlightVisible;
                gFieldSelectData.transitionFrame++;
                if (gFieldSelectData.transitionFrame > 5)
                {
                    gFieldSelectData.nextMainState = STATE_GAME_MAIN;
                    gMain.subState++;
                }
            }
            break;
        }
        gMain.selectedField = gFieldSelectData.selectedField;
        gMain.tempField = gFieldSelectData.selectedField;
    }
}

void FieldSelect_State2_8F64(void)
{
    FadeOutToWhite(RenderFieldSelectSprites);
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(gFieldSelectData.nextMainState);
}

static void RenderFieldSelectSprites(void)
{
    struct SpriteGroup *r6;
    struct SpriteGroup *r9;
    struct SpriteGroup *sp0;
    struct SpriteGroup *r10;
    struct SpriteGroup *r8;
    const struct SpriteSet *spriteSet;
    int i;

    gMain.blendControl = BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2;
    gMain.blendAlpha = BLDALPHA_BLEND(8, 8);
    REG_BLDCNT = gMain.blendControl;
    REG_BLDALPHA = gMain.blendAlpha;

    r6 = &gMain.spriteGroups[0];
    r9 = &gMain.spriteGroups[1];
    sp0 = &gMain.spriteGroups[gFieldSelectData.rubyFieldSpriteId];
    r10 = &gMain.spriteGroups[gFieldSelectData.sapphireFieldSpriteId];
    r8 = &gMain.spriteGroups[12 + gFieldSelectData.ballSpeed * 2 + gFieldSelectData.speedBlinkToggle];

    r6->available = gFieldSelectData.rubyHighlightVisible;
    r9->available = gFieldSelectData.sapphireHighlightVisible;
    sp0->available = TRUE;
    r10->available = TRUE;
    r8->available = gFieldSelectData.ballSpeedVisible;

    LoadSpriteSets(gFieldSelectSpriteSets, 16, r6);

    if (gFieldSelectData.rubyHighlightVisible == 1)
    {
        r6->baseX = 0x25;
        r6->baseY = 0x18;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[r6->oam[i].oamId].x = r6->oam[i].xOffset + r6->baseX;
            gOamBuffer[r6->oam[i].oamId].y = r6->oam[i].yOffset + r6->baseY;
        }
    }

    if (gFieldSelectData.sapphireHighlightVisible == 1)
    {
        r9->baseX = 0x8D;
        r9->baseY = 0x18;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[r9->oam[i].oamId].x = r9->oam[i].xOffset + r9->baseX;
            gOamBuffer[r9->oam[i].oamId].y = r9->oam[i].yOffset + r9->baseY;
        }
    }

    sp0->baseX = 32;
    sp0->baseY = 32;
    spriteSet = gFieldSelectSpriteSets[gFieldSelectData.rubyFieldSpriteId];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[sp0->oam[i].oamId].objMode = 1;
        gOamBuffer[sp0->oam[i].oamId].x = sp0->oam[i].xOffset + sp0->baseX;
        gOamBuffer[sp0->oam[i].oamId].y = sp0->oam[i].yOffset + sp0->baseY;
    }

    r10->baseX = 0x88;
    r10->baseY = 32;
    spriteSet = gFieldSelectSpriteSets[gFieldSelectData.sapphireFieldSpriteId];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[r10->oam[i].oamId].objMode = 1;
        gOamBuffer[r10->oam[i].oamId].x = r10->oam[i].xOffset + r10->baseX;
        gOamBuffer[r10->oam[i].oamId].y = r10->oam[i].yOffset + r10->baseY;
    }

    if (r8->available == 1)
    {
        r8->baseX = gFieldSelectBallSpeedPositions[gFieldSelectData.selectedField].x;
        r8->baseY = gFieldSelectBallSpeedPositions[gFieldSelectData.selectedField].y;
        for (i = 0; i < 5; i++)
        {
            gOamBuffer[r8->oam[i].oamId].objMode = 0;
            gOamBuffer[r8->oam[i].oamId].x = r8->oam[i].xOffset + r8->baseX;
            gOamBuffer[r8->oam[i].oamId].y = r8->oam[i].yOffset + r8->baseY;
        }
    }

    sp0->available = FALSE;
    r10->available = FALSE;
    r8->available = FALSE;
}
