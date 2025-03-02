#include "global.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "main.h"
#include "m4a.h"
#include "titlescreen.h"

static void sub_8F94(void);
static void sub_8C38(void);

enum FieldSelectStates
{
    FIELD_SELECT_STATE_CHOOSE_FIELD,
    FIELD_SELECT_STATE_1,
    FIELD_SELECT_STATE_BALL_SPEED,
    FIELD_SELECT_STATE_3,
};

struct FieldSelectData
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 selectedField;
    u16 state;
    s16 unkC;
    s16 unkE;
    u8 ballSpeed;
    s16 unk12;
    s8 unk14;
    u16 nextMainState;
};

extern struct FieldSelectData gFieldSelectData;

void FieldSelectMain(void)
{
    gFieldSelectStateFuncs[gMain.subState]();
}

void LoadFieldSelectGraphics(void)
{
    ResetSomeGraphicsRelatedStuff();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;

    REG_BG0CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(0) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG0_ON;

    REG_BG1CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG1_ON;

    REG_BG2CNT = BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(2) | BGCNT_PRIORITY(2) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG2_ON;

    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gFieldSelectBGPals,             (void *)(PLTT),           0x200);
    DmaCopy16(3, gFieldSelectWindow_Gfx,         (void *)(VRAM + 0x4000),  0x1400);
    DmaCopy16(3, gFieldSelectMiniFields_Gfx,     (void *)(VRAM + 0x8000),  0x3800);
    DmaCopy16(3, gUnknown_080A2400,              (void *)(VRAM),           0x800);
    DmaCopy16(3, gFieldSelectFrameShadowTilemap, (void *)(VRAM + 0x800),   0x800);
    DmaCopy16(3, gFieldSelectWindowTilemap,      (void *)(VRAM + 0x1000),  0x800);
    DmaCopy16(3, gFieldSelectSpritePals,         (void *)(PLTT + 0x200),   0x200);
    DmaCopy16(3, gFieldSelectSpriteGfx,          (void *)(VRAM + 0x10000), 0x4020);

    sub_0CBC();
    sub_8C38();
    sub_FD5C(sub_8F94);
    gMain.subState++;
    m4aSongNumStart(MUS_TABLE_SELECT);
}

static void sub_8C38(void)
{
    gFieldSelectData.unk0 = 2;
    gFieldSelectData.unk2 = 3;
    gFieldSelectData.unk4 = 0;
    gFieldSelectData.unk6 = 1;
    gFieldSelectData.selectedField = FIELD_RUBY;
    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
    gFieldSelectData.unkC = 0;
    gFieldSelectData.unkE = 0;
    gFieldSelectData.nextMainState = STATE_INTRO;
    gFieldSelectData.unk12 = 0;
    gFieldSelectData.unk14 = 0;

    gFieldSelectData.ballSpeed = gMain_saveData.ballSpeed;
    gMain.selectedField = FIELD_RUBY;
    gUnknown_02002850 = 0;
}

#define RESTART_GAME_BUTTONS (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)

void sub_8C7C(void)
{
    sub_8F94();
    if (JOY_HELD(RESTART_GAME_BUTTONS) == RESTART_GAME_BUTTONS)
    {
        gUnknown_02002850 = 1;
        gFieldSelectData.nextMainState = STATE_INTRO;
        gMain.subState++;
    }
    if (gUnknown_02002850 == 0)
    {
        switch (gFieldSelectData.state)
        {
        case FIELD_SELECT_STATE_CHOOSE_FIELD:
            if (JOY_NEW(DPAD_LEFT))
            {
                if (gFieldSelectData.selectedField == FIELD_SAPPHIRE)
                {
                    m4aSongNumStart(SE_UNKNOWN_0x6D);
                    gFieldSelectData.selectedField = FIELD_RUBY;
                    gFieldSelectData.unk4 = 0;
                    gFieldSelectData.unk6 = 1;
                    gFieldSelectData.state = FIELD_SELECT_STATE_1;
                }
            }
            else if (JOY_NEW(DPAD_RIGHT))
            {
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    m4aSongNumStart(SE_UNKNOWN_0x6D);
                    gFieldSelectData.selectedField = FIELD_SAPPHIRE;
                    gFieldSelectData.unk4 = 1;
                    gFieldSelectData.unk6 = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_1;
                }
            }
            if (JOY_NEW(A_BUTTON))
            {
                m4aSongNumStart(SE_UNKNOWN_0x65);
                gFieldSelectData.state = FIELD_SELECT_STATE_BALL_SPEED;
                gFieldSelectData.unk14 = 1;
                gFieldSelectData.unkE = 0;
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    gFieldSelectData.unk4 = 0;
                    gFieldSelectData.unk6 = 1;
                    gFieldSelectData.unk0 = 2;
                    gFieldSelectData.unk2 = 3;
                    gFieldSelectData.unkC = 0;
                }
                else
                {
                    gFieldSelectData.unk4 = 1;
                    gFieldSelectData.unk6 = 0;
                    gFieldSelectData.unk0 = 7;
                    gFieldSelectData.unk2 = 11;
                    gFieldSelectData.unkC = 0;
                }
            }
            if (JOY_NEW(B_BUTTON))
            {
                m4aSongNumStart(SE_UNKNOWN_0x66);
                gMain.subState++;
                gFieldSelectData.nextMainState = STATE_TITLE;
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    gFieldSelectData.unk4 = 0;
                    gFieldSelectData.unk6 = 1;
                    gFieldSelectData.unk0 = 2;
                    gFieldSelectData.unk2 = 3;
                    gFieldSelectData.unkC = 0;
                }
                else
                {
                    gFieldSelectData.unk4 = 1;
                    gFieldSelectData.unk6 = 0;
                    gFieldSelectData.unk0 = 7;
                    gFieldSelectData.unk2 = 11;
                    gFieldSelectData.unkC = 0;
                }
            }
            if (gMain.selectedField < MAIN_FIELD_COUNT)
                gMain.unk6 = 0;
            else
                gMain.unk6 = 1;
            break;
        case FIELD_SELECT_STATE_BALL_SPEED:
            if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
            {
                m4aSongNumStart(SE_SELECT);
                gFieldSelectData.ballSpeed = 1 - gFieldSelectData.ballSpeed;
            }
            if (JOY_NEW(A_BUTTON))
            {
                m4aSongNumStart(SE_UNKNOWN_0x65);
                gFieldSelectData.unkE = 0;
                gFieldSelectData.unkC = 0;
                gMain_saveData.ballSpeed = gFieldSelectData.ballSpeed;
                SaveFile_WriteToSram();
                gFieldSelectData.state = FIELD_SELECT_STATE_3;
            }
            if (JOY_NEW(B_BUTTON))
            {
                m4aSongNumStart(SE_UNKNOWN_0x66);
                gFieldSelectData.unk14 = 0;
                gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
            }
            gFieldSelectData.unkE++;
            if (gFieldSelectData.unkE > 4)
            {
                gFieldSelectData.unkE = 0;
                gFieldSelectData.unk12 = 1 - gFieldSelectData.unk12;
            }
            break;
        case FIELD_SELECT_STATE_1:
            if (gFieldSelectData.selectedField == FIELD_RUBY)
            {
                gFieldSelectData.unk0 = gUnknown_086A6B14.unk0[4 - gFieldSelectData.unkC];
                gFieldSelectData.unk2 = gUnknown_086A6B14.unkA[4 - gFieldSelectData.unkC];
            }
            else
            {
                gFieldSelectData.unk0 = gUnknown_086A6B14.unk0[gFieldSelectData.unkC];
                gFieldSelectData.unk2 = gUnknown_086A6B14.unkA[gFieldSelectData.unkC];
            }
            if (!(gMain.systemFrameCount & 1))
            {
                if (gFieldSelectData.unkC < 4)
                {
                    gFieldSelectData.unkC++;
                }
                else
                {
                    gFieldSelectData.unkC = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
                }
            }
            if (JOY_NEW(DPAD_LEFT))
            {
                if (gFieldSelectData.selectedField == FIELD_SAPPHIRE)
                {
                    m4aSongNumStart(SE_UNKNOWN_0x6D);
                    gFieldSelectData.selectedField = FIELD_RUBY;
                    gFieldSelectData.unk4 = 0;
                    gFieldSelectData.unk6 = 1;
                    gFieldSelectData.unk0 = 2;
                    gFieldSelectData.unk2 = 3;
                    gFieldSelectData.unkC = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
                }
            }
            else if (JOY_NEW(DPAD_RIGHT))
            {
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                {
                    m4aSongNumStart(SE_UNKNOWN_0x6D);
                    gFieldSelectData.selectedField = FIELD_SAPPHIRE;
                    gFieldSelectData.unk4 = 1;
                    gFieldSelectData.unk6 = 0;
                    gFieldSelectData.unk0 = 7;
                    gFieldSelectData.unk2 = 11;
                    gFieldSelectData.unkC = 0;
                    gFieldSelectData.state = FIELD_SELECT_STATE_CHOOSE_FIELD;
                }
            }
            break;
        case FIELD_SELECT_STATE_3:
            gFieldSelectData.unkE++;
            if (gFieldSelectData.unkE > 3)
            {
                gFieldSelectData.unkE = 0;
                if (gFieldSelectData.selectedField == FIELD_RUBY)
                    gFieldSelectData.unk4 = 1 - gFieldSelectData.unk4;
                else
                    gFieldSelectData.unk6 = 1 - gFieldSelectData.unk6;
                gFieldSelectData.unkC++;
                if (gFieldSelectData.unkC > 5)
                {
                    gFieldSelectData.nextMainState = STATE_GAME_MAIN;
                    gMain.subState++;
                }
            }
            break;
        }
        gMain.selectedField = gFieldSelectData.selectedField;
        gMain.unk5 = gFieldSelectData.selectedField;
    }
}

void sub_8F64(void)
{
    sub_FE04(sub_8F94);
    m4aMPlayAllStop();
    sub_0D10();
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(gFieldSelectData.nextMainState);
}

static void sub_8F94(void)
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
    sp0 = &gMain.spriteGroups[gFieldSelectData.unk0];
    r10 = &gMain.spriteGroups[gFieldSelectData.unk2];
    r8 = &gMain.spriteGroups[12 + gFieldSelectData.ballSpeed * 2 + gFieldSelectData.unk12];

    r6->available = gFieldSelectData.unk4;
    r9->available = gFieldSelectData.unk6;
    sp0->available = TRUE;
    r10->available = TRUE;
    r8->available = gFieldSelectData.unk14;

    LoadSpriteSets(gUnknown_086A6AD4, 16, r6);

    if (gFieldSelectData.unk4 == 1)
    {
        r6->baseX = 0x25;
        r6->baseY = 0x18;
        for (i = 0; i < 2; i++)
        {
            gOamBuffer[r6->oam[i].oamId].x = r6->oam[i].xOffset + r6->baseX;
            gOamBuffer[r6->oam[i].oamId].y = r6->oam[i].yOffset + r6->baseY;
        }
    }

    if (gFieldSelectData.unk6 == 1)
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
    spriteSet = gUnknown_086A6AD4[gFieldSelectData.unk0];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[sp0->oam[i].oamId].objMode = 1;
        gOamBuffer[sp0->oam[i].oamId].x = sp0->oam[i].xOffset + sp0->baseX;
        gOamBuffer[sp0->oam[i].oamId].y = sp0->oam[i].yOffset + sp0->baseY;
    }

    r10->baseX = 0x88;
    r10->baseY = 32;
    spriteSet = gUnknown_086A6AD4[gFieldSelectData.unk2];
    for (i = 0; i < spriteSet->count; i++)
    {
        gOamBuffer[r10->oam[i].oamId].objMode = 1;
        gOamBuffer[r10->oam[i].oamId].x = r10->oam[i].xOffset + r10->baseX;
        gOamBuffer[r10->oam[i].oamId].y = r10->oam[i].yOffset + r10->baseY;
    }

    if (r8->available == 1)
    {
        r8->baseX = gUnknown_086A6B28[gFieldSelectData.selectedField].x;
        r8->baseY = gUnknown_086A6B28[gFieldSelectData.selectedField].y;
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
