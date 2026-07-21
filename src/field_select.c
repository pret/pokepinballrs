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
    u16 rubyFieldSpriteGroup;
    u16 sapphireFieldSpriteGroup;
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
    gFieldSelectData.rubyFieldSpriteGroup = SG_FIELD_SELECT_RUBY_FULL_HIGHLIGHT;
    gFieldSelectData.sapphireFieldSpriteGroup = SG_FIELD_SELECT_SAPPHIRE_FULL_SHADOW;
    gFieldSelectData.rubyHighlightVisible = FALSE;
    gFieldSelectData.sapphireHighlightVisible = TRUE;
    gFieldSelectData.selectedField = FIELD_RUBY;
    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
    gFieldSelectData.transitionFrame = 0;
    gFieldSelectData.speedBlinkTimer = 0;
    gFieldSelectData.nextMainState = STATE_INTRO;
    gFieldSelectData.speedBlinkToggle = 0;
    gFieldSelectData.ballSpeedVisible = FALSE;

    gFieldSelectData.ballSpeed = gMain_saveData.ballSpeed;
    gMain.selectedField = FIELD_RUBY;
    gFieldSelectSoftReset = FALSE;
}

#define RESTART_GAME_BUTTONS (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)

void FieldSelect_State1_8C7C(void)
{
    RenderFieldSelectSprites();
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gFieldSelectSoftReset = TRUE;
        gFieldSelectData.nextMainState = STATE_INTRO;
        gMain.subState++;
    }

    if (!gFieldSelectSoftReset)
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
                    gFieldSelectData.rubyHighlightVisible = FALSE;
                    gFieldSelectData.sapphireHighlightVisible = TRUE;
                    gFieldSelectData.state = FIELD_SELECT_STATE_1;
                }
            }
            else if (JOY_NEW(DPAD_RIGHT))
            {
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
                    gFieldSelectData.selectedField = FIELD_SAPPHIRE;
                    gFieldSelectData.rubyHighlightVisible = TRUE;
                    gFieldSelectData.sapphireHighlightVisible = FALSE;
                    gFieldSelectData.state = FIELD_SELECT_STATE_1;
                }
            }
            if (JOY_NEW(A_BUTTON))
            {
                m4aSongNumStart(SE_MENU_SELECT);
                gFieldSelectData.state = FIELD_SELECT_STATE_BALL_SPEED;
                gFieldSelectData.ballSpeedVisible = TRUE;
                gFieldSelectData.speedBlinkTimer = 0;
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    gFieldSelectData.rubyHighlightVisible = FALSE;
                    gFieldSelectData.sapphireHighlightVisible = TRUE;
                    gFieldSelectData.rubyFieldSpriteGroup = SG_FIELD_SELECT_RUBY_FULL_HIGHLIGHT;
                    gFieldSelectData.sapphireFieldSpriteGroup = SG_FIELD_SELECT_SAPPHIRE_FULL_SHADOW;
                    gFieldSelectData.transitionFrame = 0;
                }
                else
                {
                    gFieldSelectData.rubyHighlightVisible = TRUE;
                    gFieldSelectData.sapphireHighlightVisible = FALSE;
                    gFieldSelectData.rubyFieldSpriteGroup = SG_FIELD_SELECT_RUBY_FULL_SHADOW;
                    gFieldSelectData.sapphireFieldSpriteGroup = SG_FIELD_SELECT_SAPPHIRE_FULL_HIGHLIGHT;
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
                    gFieldSelectData.rubyHighlightVisible = FALSE;
                    gFieldSelectData.sapphireHighlightVisible = TRUE;
                    gFieldSelectData.rubyFieldSpriteGroup = SG_FIELD_SELECT_RUBY_FULL_HIGHLIGHT;
                    gFieldSelectData.sapphireFieldSpriteGroup = SG_FIELD_SELECT_SAPPHIRE_FULL_SHADOW;
                    gFieldSelectData.transitionFrame = 0;
                }
                else
                {
                    gFieldSelectData.rubyHighlightVisible = TRUE;
                    gFieldSelectData.sapphireHighlightVisible = FALSE;
                    gFieldSelectData.rubyFieldSpriteGroup = SG_FIELD_SELECT_RUBY_FULL_SHADOW;
                    gFieldSelectData.sapphireFieldSpriteGroup = SG_FIELD_SELECT_SAPPHIRE_FULL_HIGHLIGHT;
                    gFieldSelectData.transitionFrame = 0;
                }
            }
            if (gMain.selectedField < MAIN_FIELD_COUNT)
                gMain.isBonusField = FALSE;
            else
                gMain.isBonusField = TRUE;
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
                gFieldSelectData.ballSpeedVisible = FALSE;
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
                gFieldSelectData.rubyFieldSpriteGroup = gFieldTransitionAnimData.rubyTransitionFrames[4 - gFieldSelectData.transitionFrame];
                gFieldSelectData.sapphireFieldSpriteGroup = gFieldTransitionAnimData.sapphireTransitionFrames[4 - gFieldSelectData.transitionFrame];
            }
            else
            {
                gFieldSelectData.rubyFieldSpriteGroup = gFieldTransitionAnimData.rubyTransitionFrames[gFieldSelectData.transitionFrame];
                gFieldSelectData.sapphireFieldSpriteGroup = gFieldTransitionAnimData.sapphireTransitionFrames[gFieldSelectData.transitionFrame];
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
                    gFieldSelectData.rubyHighlightVisible = FALSE;
                    gFieldSelectData.sapphireHighlightVisible = TRUE;
                    gFieldSelectData.rubyFieldSpriteGroup = SG_FIELD_SELECT_RUBY_FULL_HIGHLIGHT;
                    gFieldSelectData.sapphireFieldSpriteGroup = SG_FIELD_SELECT_SAPPHIRE_FULL_SHADOW;
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
                    gFieldSelectData.rubyHighlightVisible = TRUE;
                    gFieldSelectData.sapphireHighlightVisible = FALSE;
                    gFieldSelectData.rubyFieldSpriteGroup = SG_FIELD_SELECT_RUBY_FULL_SHADOW;
                    gFieldSelectData.sapphireFieldSpriteGroup = SG_FIELD_SELECT_SAPPHIRE_FULL_HIGHLIGHT;
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

    r6 = &gMain.spriteGroups[SG_FIELD_SELECT_RUBY_BOARD_NAME_HIGHLIGHT];
    r9 = &gMain.spriteGroups[SG_FIELD_SELECT_SAPPHIRE_BOARD_NAME_HIGHLIGHT];
    sp0 = &gMain.spriteGroups[gFieldSelectData.rubyFieldSpriteGroup];
    r10 = &gMain.spriteGroups[gFieldSelectData.sapphireFieldSpriteGroup];
    r8 = &gMain.spriteGroups[SG_FIELD_SELECT_BALL_SPEED_SELECT_BASE + gFieldSelectData.ballSpeed * 2 + gFieldSelectData.speedBlinkToggle];

    r6->active = gFieldSelectData.rubyHighlightVisible;
    r9->active = gFieldSelectData.sapphireHighlightVisible;
    sp0->active = TRUE;
    r10->active = TRUE;
    r8->active = gFieldSelectData.ballSpeedVisible;

    LoadSpriteSets(gFieldSelectSpriteSets, 16, r6);

    if (gFieldSelectData.rubyHighlightVisible == TRUE)
    {
        r6->baseX = 0x25;
        r6->baseY = 0x18;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[r6->oam[i].oamId].x = r6->oam[i].xOffset + r6->baseX;
            gOamBuffer[r6->oam[i].oamId].y = r6->oam[i].yOffset + r6->baseY;
        }
    }

    if (gFieldSelectData.sapphireHighlightVisible == TRUE)
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
    spriteSet = gFieldSelectSpriteSets[gFieldSelectData.rubyFieldSpriteGroup];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[sp0->oam[i].oamId].objMode = ST_OAM_OBJ_BLEND;
        gOamBuffer[sp0->oam[i].oamId].x = sp0->oam[i].xOffset + sp0->baseX;
        gOamBuffer[sp0->oam[i].oamId].y = sp0->oam[i].yOffset + sp0->baseY;
    }

    r10->baseX = 0x88;
    r10->baseY = 32;
    spriteSet = gFieldSelectSpriteSets[gFieldSelectData.sapphireFieldSpriteGroup];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[r10->oam[i].oamId].objMode = ST_OAM_OBJ_BLEND;
        gOamBuffer[r10->oam[i].oamId].x = r10->oam[i].xOffset + r10->baseX;
        gOamBuffer[r10->oam[i].oamId].y = r10->oam[i].yOffset + r10->baseY;
    }

    if (r8->active == TRUE)
    {
        r8->baseX = gFieldSelectBallSpeedPositions[gFieldSelectData.selectedField].x;
        r8->baseY = gFieldSelectBallSpeedPositions[gFieldSelectData.selectedField].y;
        for (i = 0; i < 5; i++)
        {
            gOamBuffer[r8->oam[i].oamId].objMode = ST_OAM_OBJ_NORMAL;
            gOamBuffer[r8->oam[i].oamId].x = r8->oam[i].xOffset + r8->baseX;
            gOamBuffer[r8->oam[i].oamId].y = r8->oam[i].yOffset + r8->baseY;
        }
    }

    sp0->active = FALSE;
    r10->active = FALSE;
    r8->active = FALSE;
}
