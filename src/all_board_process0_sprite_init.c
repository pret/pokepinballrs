#include "global.h"
#include "main.h"


void RubyBoardProcess_0A_50848(void)
{
    s16 i;
    struct SpriteGroup *group;

    for (i = 0; i < 84; i++)
        gMain.spriteGroups[i].active = FALSE;

    gMain.spriteGroups[SG_RUBY_PIKA_CHARGING_SPINNER].active = TRUE;
    group = &gMain.spriteGroups[SG_RUBY_HATCH_EGG]; // fake match?
    gMain.spriteGroups[SG_RUBY_BALL].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_PANEL].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_TOP_BORDER].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_BOTTOM_BORDER].active = TRUE;
    gMain.spriteGroups[SG_RUBY_CHARGE_INDICATOR_DEVICE].active = TRUE;
    gMain.spriteGroups[SG_RUBY_BOARD_RIGHT_EDGE].active = TRUE;
    gMain.spriteGroups[SG_RUBY_MART_DOOR].active = TRUE;
    gMain.spriteGroups[SG_RUBY_NUZLEAF].active = TRUE;
    gMain.spriteGroups[SG_RUBY_RAMP_PRIZE].active = TRUE;
    gMain.spriteGroups[SG_RUBY_CYNDAQUIL].active = TRUE;
    gMain.spriteGroups[SG_RUBY_SHARPEDO].active = TRUE;
    group->active = TRUE;
    gMain.spriteGroups[SG_RUBY_HATCH_CAVE].active = TRUE;
    gMain.spriteGroups[SG_RUBY_BUMPERS].active = TRUE;
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
    gMain.spriteGroups[SG_RUBY_HATCH_EGG].active = FALSE;
    gMain.spriteGroups[SG_RUBY_NUZLEAF].active = FALSE;
    for (i = 51; i < 67; i++)
        gMain.spriteGroups[i].active = FALSE;

    gCurrentPinballGame->randomSpriteVariantSeed = gMain.systemFrameCount % 25;
    if (gCurrentPinballGame->cameraYViewport < 110)
    {
        gMain.spriteGroups[SG_RUBY_MART_DOOR].active = TRUE;
        gMain.spriteGroups[SG_RUBY_NUZLEAF].active = TRUE;
        gMain.spriteGroups[SG_RUBY_RAMP_PRIZE].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport < 168)
    {
        gMain.spriteGroups[SG_RUBY_HATCH_EGG].active = TRUE;
        gMain.spriteGroups[SG_RUBY_HATCH_CAVE].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport < 220)
    {
        gMain.spriteGroups[SG_RUBY_CYNDAQUIL].active = TRUE;
        gMain.spriteGroups[SG_RUBY_SHARPEDO].active = TRUE;
        gMain.spriteGroups[SG_RUBY_PIKA_CHARGING_SPINNER].active = TRUE;
        if (gCurrentPinballGame->shouldProcessWhiscash)
            gMain.spriteGroups[SG_RUBY_WHISCASH].active = TRUE;
        else
            gMain.spriteGroups[SG_RUBY_BUMPERS].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport > 63)
    {
        gMain.spriteGroups[SG_RUBY_CHIKORITA].active = TRUE;
        gMain.spriteGroups[SG_RUBY_GULPIN_STACK].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport > 115)
        gMain.spriteGroups[SG_RUBY_MAKUHITA].active = TRUE;

    if (gCurrentPinballGame->cameraYViewport > 130)
    {
        gMain.spriteGroups[SG_RUBY_LINOONE_LEFT].active = TRUE;
        gMain.spriteGroups[SG_RUBY_LINOONE_RIGHT].active = TRUE;
    }

    if (gCurrentPinballGame->cameraYViewport > 216)
    {
        gMain.spriteGroups[SG_RUBY_SPOINK_LAUNCHER].active = TRUE;
        gMain.spriteGroups[SG_RUBY_PIKACHU_KICKBACK_ENTITY].active = TRUE;
        gMain.spriteGroups[SG_RUBY_PICHU_KICKBACK_ENTITY].active = TRUE;
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

    gMain.spriteGroups[SG_SAPPHIRE_PIKA_CHARGING_SPINNER].active = TRUE;
    gMain.spriteGroups[SG_SAPPHIRE_SHROOMISH_BUMPERS].active = TRUE;
    gMain.spriteGroups[SG_SAPPHIRE_PELIPPER].active = TRUE;
    gMain.spriteGroups[SG_SAPPHIRE_MART_SIGN].active = TRUE;
    gMain.spriteGroups[SG_SAPPHIRE_HATCH_EGG].active = TRUE;
    gMain.spriteGroups[SG_SAPPHIRE_BALL].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_PANEL].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_TOP_BORDER].active = TRUE;
    gMain.spriteGroups[SG_PAUSE_BOTTOM_BORDER].active = TRUE;
    gMain.spriteGroups[SG_SAPPHIRE_CHARGE_INDICATOR_DEVICE].active = TRUE;
    gMain.spriteGroups[SG_SAPPHIRE_BOARD_RIGHT_EDGE].active = TRUE;
    LoadSpriteSets(gFieldSpriteSets[gMain.selectedField].spriteSets,
                   gFieldSpriteSets[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void SapphireBoardProcess_0B_50B80(void)
{
    s16 i;

    for (i = 55; i < 71; i++)
        gMain.spriteGroups[i].active = FALSE;

    gMain.spriteGroups[SG_SAPPHIRE_HATCH_EGG].active = FALSE;
    gMain.spriteGroups[SG_SAPPHIRE_PIKA_CHARGING_SPINNER].active = FALSE;
    gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON].active = FALSE;
    gMain.spriteGroups[SG_SAPPHIRE_HATCH_MACHINE_LOWER_SEGMENT].active = FALSE;
    gMain.spriteGroups[SG_SAPPHIRE_MART_ELECTRICAL_GATE_FX].active = FALSE;
    gMain.spriteGroups[SG_SAPPHIRE_WAILMER].active = FALSE;
    gMain.spriteGroups[SG_MAIN_BOARD_LEFT_FLIPPER].active = FALSE;
    gMain.spriteGroups[SG_MAIN_BOARD_RIGHT_FLIPPER].active = FALSE;
    gCurrentPinballGame->randomSpriteVariantSeed = gMain.systemFrameCount % 25;
    if (gCurrentPinballGame->cameraYViewport < 90)
    {
        gMain.spriteGroups[SG_SAPPHIRE_HATCH_EGG].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_HATCH_MACHINE_LOWER_SEGMENT].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 220)
    {
        gMain.spriteGroups[SG_SAPPHIRE_PIKA_CHARGING_SPINNER].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 150)
    {
        gMain.spriteGroups[SG_SAPPHIRE_PELIPPER].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_MART_SIGN].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 196)
    {
        gMain.spriteGroups[SG_SAPPHIRE_SHROOMISH_BUMPERS].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_WAILMER].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport < 202)
    {
        gMain.spriteGroups[SG_SAPPHIRE_MINUN].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_MINUN_ELECTRICITY_FX].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_PLUSLE].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_PLUSLE_ELECTRICITY_FX].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_MART_ELECTRICAL_GATE_FX].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport > 118)
    {
        gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON_SPEECH_BUBBLE].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_ZIGZAGOON].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_BASKET_BACK].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_BASKET_FRONT].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_ENTITY_0].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_ENTITY_1].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_ENTITY_2].active = TRUE;
    }
    if (gCurrentPinballGame->cameraYViewport > 216)
    {
        gMain.spriteGroups[SG_SAPPHIRE_SPOINK_LAUNCHER].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_PIKACHU_KICKBACK_ENTITY].active = TRUE;
        gMain.spriteGroups[SG_SAPPHIRE_PICHU_KICKBACK_ENTITY].active = TRUE;
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
