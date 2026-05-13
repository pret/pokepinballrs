#include "global.h"
#include "main.h"


void RubyBoardProcess_0A_50848(void)
{
    s16 i;
    struct SpriteGroup *group;

    for (i = 0; i < 84; i++)
        gMain.spriteGroups[i].active = FALSE;

    gMain.spriteGroups[SG_64].active = TRUE;
    group = &gMain.spriteGroups[SG_48]; // fake match?
    gMain.spriteGroups[SG_70].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_PANEL].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_TOP_BORDER].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_BOTTOM_BORDER].active = TRUE;
    gMain.spriteGroups[SG_28].active = TRUE;
    gMain.spriteGroups[SG_81].active = TRUE;
    gMain.spriteGroups[SG_65].active = TRUE;
    gMain.spriteGroups[SG_71].active = TRUE;
    gMain.spriteGroups[SG_66].active = TRUE;
    gMain.spriteGroups[SG_51].active = TRUE;
    gMain.spriteGroups[SG_61].active = TRUE;
    group->active = TRUE;
    gMain.spriteGroups[SG_52].active = TRUE;
    gMain.spriteGroups[SG_62].active = TRUE;
    LoadSpriteSets(
        gFieldSpriteSets[gMain.selectedField].spriteSets,
        gFieldSpriteSets[gMain.selectedField].numSpriteSets,
        gMain.spriteGroups);
}

void RubyBoardProcess_0B_50918(void)
{
    s16 i;

    gMain.spriteGroups[SG_MAIN_BOARD_LEFT_FLIPPER].active = FALSE;
    gMain.spriteGroups[SG_MAIN_BOARD_RIGHT_FLIPPER].active = FALSE;
    gMain.spriteGroups[SG_48].active = FALSE;
    gMain.spriteGroups[SG_71].active = FALSE;
    for (i = 51; i < 67; i++)
        gMain.spriteGroups[i].active = FALSE;

    gCurrentPinballGame->randomSpriteVariantSeed = gMain.systemFrameCount % 25;
    if (gCurrentPinballGame->cameraYViewport < 110)
    {
        gMain.spriteGroups[SG_65].active = TRUE;
        gMain.spriteGroups[SG_71].active = TRUE;
        gMain.spriteGroups[SG_66].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport < 168)
    {
        gMain.spriteGroups[SG_48].active = TRUE;
        gMain.spriteGroups[SG_52].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport < 220)
    {
        gMain.spriteGroups[SG_51].active = TRUE;
        gMain.spriteGroups[SG_61].active = TRUE;
        gMain.spriteGroups[SG_64].active = TRUE;
        if (gCurrentPinballGame->shouldProcessWhiscash)
            gMain.spriteGroups[SG_63].active = TRUE;
        else
            gMain.spriteGroups[SG_62].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport > 63)
    {
        gMain.spriteGroups[SG_53].active = TRUE;
        gMain.spriteGroups[SG_57].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport > 115)
        gMain.spriteGroups[SG_58].active = TRUE;

    if (gCurrentPinballGame->cameraYViewport > 130)
    {
        gMain.spriteGroups[SG_59].active = TRUE;
        gMain.spriteGroups[SG_60].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport > 216)
    {
        gMain.spriteGroups[SG_56].active = TRUE;
        gMain.spriteGroups[SG_54].active = TRUE;
        gMain.spriteGroups[SG_55].active = TRUE;
        gMain.spriteGroups[SG_MAIN_BOARD_LEFT_FLIPPER].active = TRUE;
        gMain.spriteGroups[SG_MAIN_BOARD_RIGHT_FLIPPER].active = TRUE;
    }

    LoadSpriteSets(
        gFieldSpriteSets[gMain.selectedField].spriteSets,
        gFieldSpriteSets[gMain.selectedField].numSpriteSets,
        gMain.spriteGroups);
}

void SapphireBoardProcess_0A_50AD4(void)
{
    s16 i;

    for (i = 0; i < 87; i++)
        gMain.spriteGroups[i].active = FALSE;

    gMain.spriteGroups[SG_72].active = TRUE;
    gMain.spriteGroups[SG_63].active = TRUE;
    gMain.spriteGroups[SG_60].active = TRUE;
    gMain.spriteGroups[SG_69].active = TRUE;
    gMain.spriteGroups[SG_52].active = TRUE;
    gMain.spriteGroups[SG_74].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_PANEL].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_TOP_BORDER].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_BOTTOM_BORDER].active = TRUE;
    gMain.spriteGroups[SG_25].active = TRUE;
    gMain.spriteGroups[SG_85].active = TRUE;
    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void SapphireBoardProcess_0B_50B80(void)
{
    s16 i;

    for (i = 55; i < 71; i++)
        gMain.spriteGroups[i].active = FALSE;

    gMain.spriteGroups[SG_52].active = FALSE;
    gMain.spriteGroups[SG_72].active = FALSE;
    gMain.spriteGroups[SG_26].active = FALSE;
    gMain.spriteGroups[SG_51].active = FALSE;
    gMain.spriteGroups[SG_76].active = FALSE;
    gMain.spriteGroups[SG_75].active = FALSE;
    gMain.spriteGroups[SG_MAIN_BOARD_LEFT_FLIPPER].active = FALSE;
    gMain.spriteGroups[SG_MAIN_BOARD_RIGHT_FLIPPER].active = FALSE;
    gCurrentPinballGame->randomSpriteVariantSeed = gMain.systemFrameCount % 25;
    if (gCurrentPinballGame->cameraYViewport < 90)
    {
        gMain.spriteGroups[SG_52].active = TRUE;
        gMain.spriteGroups[SG_51].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 220)
    {
        gMain.spriteGroups[SG_72].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 150)
    {
        gMain.spriteGroups[SG_60].active = TRUE;
        gMain.spriteGroups[SG_69].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 196)
    {
        gMain.spriteGroups[SG_63].active = TRUE;
        gMain.spriteGroups[SG_75].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 202)
    {
        gMain.spriteGroups[SG_61].active = TRUE;
        gMain.spriteGroups[SG_58].active = TRUE;
        gMain.spriteGroups[SG_62].active = TRUE;
        gMain.spriteGroups[SG_59].active = TRUE;
        gMain.spriteGroups[SG_76].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport > 118)
    {
        gMain.spriteGroups[SG_70].active = TRUE;
        gMain.spriteGroups[SG_26].active = TRUE;
        gMain.spriteGroups[SG_64].active = TRUE;
        gMain.spriteGroups[SG_68].active = TRUE;
        gMain.spriteGroups[SG_65].active = TRUE;
        gMain.spriteGroups[SG_66].active = TRUE;
        gMain.spriteGroups[SG_67].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport > 216)
    {
        gMain.spriteGroups[SG_57].active = TRUE;
        gMain.spriteGroups[SG_55].active = TRUE;
        gMain.spriteGroups[SG_56].active = TRUE;
        gMain.spriteGroups[SG_MAIN_BOARD_LEFT_FLIPPER].active = TRUE;
        gMain.spriteGroups[SG_MAIN_BOARD_RIGHT_FLIPPER].active = TRUE;
    }

    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets, gFieldSpriteSets[gMain.selectedField].numSpriteSets, gMain.spriteGroups);
}

void DusclopsBoardProcess_0A_50D48(void)
{
    s16 i;

    for (i = 0; i < 15; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].active = TRUE;
        else
            gMain.spriteGroups[i].active = FALSE;
    }

    gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = TRUE;

    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void DusclopsBoardProcess_0B_50DB8(void)
{
    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void KecleonBoardProcess_0A_50DE0(void)
{
    s16 i;

    for (i = 0; i < 33; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].active = TRUE;
        else
            gMain.spriteGroups[i].active = FALSE;
    }

    gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +13].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DUST_FX].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_SCOPE_ITEM].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +6].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +7].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_TREE_LEAVES].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +0].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +1].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +2].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +3].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +4].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +5].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +8].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +9].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +10].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_DRAW_ORDER_SPRITES_BASE +11].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_FLOWER_BY_TREE].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_FLOWER_PAIR_LEFT].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_FLOWER_PAIR_BOTTOM_RIGHT].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_FLOWER_TRIPLE_RIGHT].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_REFLECTION_HEAD].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_REFLECTION_BALL].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_BALL_RIPPLE_FX].active = TRUE;
    gMain.spriteGroups[SG_KECLEON_STEP_RIPPLE_FX].active = TRUE;

    LoadSpriteSets(
        gFieldSpriteSets[gMain.selectedField].spriteSets,
        gFieldSpriteSets[gMain.selectedField].numSpriteSets,
        gMain.spriteGroups
    );
}

void nullsub_20(void)
{}

void KyogreBoardProcess_0A_50F04()
{
    s16 i;

    for (i = 0; i < 27; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].active = TRUE;
        else
            gMain.spriteGroups[i].active = FALSE;
    }

    gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_CRYSTAL_TOP_RIGHT].active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_CRYSTAL_TOP_LEFT].active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_CRYSTAL_BOTTOM_RIGHT].active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_CRYSTAL_BOTTOM_LEFT].active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_ENTITY].active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_WHIRLPOOL_0].active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_WHIRLPOOL_1].active = TRUE;
    gMain.spriteGroups[SG_KYOGRE_INTRO_CRYSTAL_GROUND].active = TRUE;

    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void KyogreBoardProcess_0B_50FAC(void)
{
    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void GroudonBoardProcess_0A_50FD4(void)
{
    s16 i;

    for (i = 0; i < 32; i++)
    {
        if (i < 5) {
            gMain.spriteGroups[i].active = TRUE;
        } else {
            gMain.spriteGroups[i].active = FALSE;
        }
    }

    gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = TRUE;
    gMain.spriteGroups[SG_GROUDON_CRYSTAL_TOP_RIGHT].active = TRUE;
    gMain.spriteGroups[SG_GROUDON_CRYSTAL_BOTTOM_RIGHT].active = TRUE;
    gMain.spriteGroups[SG_GROUDON_CRYSTAL_TOP_LEFT].active = TRUE;
    gMain.spriteGroups[SG_GROUDON_CRYSTAL_BOTTOM_LEFT].active = TRUE;
    gMain.spriteGroups[SG_GROUDON_ENTITY].active = TRUE;

    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void GroudonBoardProcess_0B_51068(void)
{
    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void RayquazaBoardProcess_0A_51090(void)
{
    s16 i;

    for (i = 0; i < 46; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].active = TRUE;
        else
            gMain.spriteGroups[i].active = FALSE;
    }

    gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = TRUE;
    gMain.spriteGroups[SG_RAYQUAZA_ENTITY_BACKGROUND_FLY_UP].active = TRUE;
    gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_0].active = TRUE;
    gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_1].active = TRUE;
    gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_2].active = TRUE;
    gMain.spriteGroups[SG_RAYQUAZA_ENTITY_ROAR_HEAD_EXTENSION].active = TRUE;

    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void RayquazaBoardProcess_0B_51128(void)
{
    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void SphealBoardProcess_0A_51150(void)
{
    s16 i;

    for (i = 0; i < 23; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].active = TRUE;
        else
            gMain.spriteGroups[i].active = FALSE;
    }

    gMain.fieldSpriteGroups[FIELD_SG_BALL]->active = TRUE;
    gMain.spriteGroups[SG_SPHEAL_NET].active = TRUE;
    gMain.spriteGroups[SG_SPHEAL_LEFT_SEALEO_ENTITY].active = TRUE;
    gMain.spriteGroups[SG_SPHEAL_RIGHT_SEALEO_ENTITY].active = TRUE;
    gMain.spriteGroups[SG_SPHEAL_ENTITY_0].active = TRUE;
    gMain.spriteGroups[SG_SPHEAL_ENTITY_1].active = TRUE;
    gMain.spriteGroups[SG_SPHEAL_ENTITY_REFLECTION_0].active = TRUE;
    gMain.spriteGroups[SG_SPHEAL_ENTITY_REFLECTION_1].active = TRUE;

    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void SphealBoardProcess_0B_511F8(void)
{
    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}
