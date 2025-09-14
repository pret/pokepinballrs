#include "global.h"
#include "variables.h"
#include "types.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

void AllBoardProcess_4A_19304(void)
{
    if (gMain.selectedField >= FIELD_BONUS_START)
        BonusBoardProcess_4B_19734();
}

void sub_1931C(struct Vector16 arg0)
{
    s16 check;
    struct Unk086ACE8C *line;
    struct Vector16 point1, point2;

    line = &gUnknown_086ACE8C[gCurrentPinballGame->unk13BC[0].unk0];
    point1.x = line->unk0 + 0x53;
    point1.y = line->unk2 + gUnknown_02031520.unk14.unk1C;

    point2.x = line->unk4 + 0x53;
    point2.y = line->unk6 + gUnknown_02031520.unk14.unk1C;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->unk13BC[0].unk8 = 1;
    else
        gCurrentPinballGame->unk13BC[0].unk8 = -1;

    line = &gUnknown_086ACE8C[gCurrentPinballGame->unk13BC[1].unk0];

    point1.x = 0x9C - line->unk0;
    point1.y = line->unk2 + gUnknown_02031520.unk14.unk1C;

    point2.x = 0x9C - line->unk4;
    point2.y = line->unk6 + gUnknown_02031520.unk14.unk1C;

    check = (point2.y - point1.y) * (arg0.x - point1.x) * 30 / (point2.x - point1.x) + (point1.y - arg0.y) * 30;

    if (check >= 0)
        gCurrentPinballGame->unk13BC[1].unk8 = 1;
    else
        gCurrentPinballGame->unk13BC[1].unk8 = -1;
}

void MainBoardProcess_4B_19490(void)
{
    s16 i;

    if ((gMain.unkF & 1) == 0)
        sub_195C4();

    for (i = 0; i < 2; i++)
    {
        struct SpriteGroup *spriteGroup;

        if (gCurrentPinballGame->unk13BC[i].unk0 > 10)
            gCurrentPinballGame->unk13BC[i].unk0 = 10;
        else if (gCurrentPinballGame->unk13BC[i].unk0 < 0)
            gCurrentPinballGame->unk13BC[i].unk0 = 0;

        spriteGroup = &gMain.spriteGroups[10 + i];
        if (spriteGroup->available)
        {
            s8 unk0;
            struct OamDataSimple *oamData;

            unk0 = gCurrentPinballGame->unk13BC[i].unk0 / 2;
            spriteGroup->baseX = gUnknown_086ACEF4[i] - gCurrentPinballGame->unk58;
            spriteGroup->baseY = gUnknown_02031520.unk14.unk1C - gCurrentPinballGame->unk5A;

            DmaCopy16(3, gUnknown_083FE44C[unk0], OBJ_VRAM0 + i * 0x200, 0x200);

            oamData = &spriteGroup->oam[0];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
        }
    }
}

void sub_195C4(void)
{
    s16 i;

    sub_1931C(gCurrentPinballGame->ball->positionQ0);

    for (i = 0; i < 2; i++)
    {
        s16 dir;
        struct UnkPinballGame13BC *unk13BC;
        unk13BC = &gCurrentPinballGame->unk13BC[i];

        unk13BC->unk1 = unk13BC->unk0;
        unk13BC->unk2 = 0;

        if (gCurrentPinballGame->heldButtonActions[i])
        {
            if (unk13BC->unk6 == 0 && gCurrentPinballGame->unk25 == 0)
                m4aSongNumStart(SE_FLIPPER_PRESSED);

            unk13BC->unk6 = 1;
            unk13BC->unk7 = 0;
        }
        else
        {
            if (unk13BC->unk0 == 10)
            {
                if (unk13BC->unk7 > 2)
                    unk13BC->unk6 = 0;
                unk13BC->unk7++;
            }
        }

        dir = 0;
        if (unk13BC->unk6 != 0)
        {
            if (unk13BC->unk0 != 10)
            {
                dir = 1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk2 = unk13BC->unk0 / 2 + 1;
            unk13BC->unk0 += 4;
        }
        else
        {
            if (unk13BC->unk0 != 0)
            {
                unk13BC->unk2 = unk13BC->unk0 / 2 + 6;
                dir = -1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk0 -= 2;
        }
        unk13BC->unk3 = unk13BC->unk3 * dir;
        if (unk13BC->unk3 <= 0)
            unk13BC->unk4 = 0;
        unk13BC->unk3 = dir;
    }
}

void BonusBoardProcess_4B_19734(void)
{
    s16 i;
    s16 priority = 1;

    if ((gMain.unkF & 1) == 0)
    {
        sub_19894();
        gMain.unkF = gMain.unkF;
    }
    for (i = 0; i < 2; i++)
    {
        struct SpriteGroup *spriteGroup;

        if (gCurrentPinballGame->unk13BC[i].unk0 > 10)
            gCurrentPinballGame->unk13BC[i].unk0 = 10;
        else if (gCurrentPinballGame->unk13BC[i].unk0 < 0)
            gCurrentPinballGame->unk13BC[i].unk0 = 0;

        spriteGroup = &gMain.spriteGroups[3 + i];
        if (spriteGroup->available)
        {
            s8 unk0;
            struct OamDataSimple *oamData;

            unk0 = gCurrentPinballGame->unk13BC[i].unk0 / 2;
            spriteGroup->baseX = gUnknown_086ACEF4[i] - gCurrentPinballGame->unk58;
            spriteGroup->baseY = gUnknown_02031520.unk14.unk1C - gCurrentPinballGame->unk5A;

            DmaCopy16(3, gUnknown_083FE44C[unk0], OBJ_VRAM0 + i * 0x200, 0x200);

            if (spriteGroup->baseY > 180)
                spriteGroup->baseY = 180;

            oamData = &spriteGroup->oam[0];
            gOamBuffer[oamData->oamId].x = oamData->xOffset + spriteGroup->baseX;
            gOamBuffer[oamData->oamId].y = oamData->yOffset + spriteGroup->baseY;
            gOamBuffer[oamData->oamId].priority = priority;
        }
    }
}

void sub_19894(void)
{
    s16 i;

    sub_1931C(gCurrentPinballGame->ball->positionQ0);

    for (i = 0; i < 2; i++)
    {
        s16 dir;
        struct UnkPinballGame13BC *unk13BC;
        unk13BC = &gCurrentPinballGame->unk13BC[i];

        unk13BC->unk1 = unk13BC->unk0;
        unk13BC->unk2 = 0;

        if (gCurrentPinballGame->heldButtonActions[i] && gMain.unkF == 0)
        {
            if (unk13BC->unk6 == 0 && gCurrentPinballGame->unk25 == 0 && gCurrentPinballGame->unk1A == 0)
            {
                m4aSongNumStart(SE_FLIPPER_PRESSED);
            }
            unk13BC->unk6 = 1;
            unk13BC->unk7 = 0;
        }
        else
        {
            if (unk13BC->unk0 == 10)
            {
                if (unk13BC->unk7 > 2)
                    unk13BC->unk6 = 0;
                unk13BC->unk7++;
            }
        }

        dir = 0;
        if (unk13BC->unk6 != 0)
        {
            if (unk13BC->unk0 != 10)
            {
                dir = 1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk2 = unk13BC->unk0 / 2 + 1;
            unk13BC->unk0 += 4;
        }
        else
        {
            if (unk13BC->unk0 != 0)
            {
                unk13BC->unk2 = unk13BC->unk0 / 2 + 6;
                dir = -1;
            }
            else if (gCurrentPinballGame->unk5C != 0)
            {
                gCurrentPinballGame->unk1334[0].velocity.x = gCurrentPinballGame->unk60.x;
                gCurrentPinballGame->unk1334[0].velocity.y = gCurrentPinballGame->unk60.y;
                gCurrentPinballGame->unk5C = 0;
                sub_11B0(7);
            }
            unk13BC->unk0 -= 2;
        }
        unk13BC->unk3 = unk13BC->unk3 * dir;
        if (unk13BC->unk3 <= 0)
            unk13BC->unk4 = 0;
        unk13BC->unk3 = dir;
    }
}
