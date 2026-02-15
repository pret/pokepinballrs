#include "global.h"
#include "main.h"
#include "gba/gba.h"
#include "m4a.h"
#include "constants/fields.h"
#include "constants/bg_music.h"

extern const u8 gUnknown_0845A08C[][0x100];
extern const s16 gUnknown_086AE5A0[][2];
extern const s16 gUnknown_086AE58A[][2];
extern const s16 gUnknown_086AE588[][2];
extern const u8 gUnknown_08490A4C[][0x440];
extern struct Vector16 gUnknown_086AE554[];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gUnknown_081BC984[][0x20];
extern const u8 gUnknown_0848108C[][0x480];

void sub_313A0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[69];
    if (group->available)
    {
        group->baseX = 16 - gCurrentPinballGame->unk58;
        group->baseY = 115 - gCurrentPinballGame->unk5A;
        index = gCurrentPinballGame->unk1AD + gCurrentPinballGame->unk6F * 3;
        DmaCopy16(3, gUnknown_081BC984[index], (void *)0x05000300, 0x20);
        DmaCopy16(3, gUnknown_0848108C[gCurrentPinballGame->unk1AC], (void *) 0x06014B20, 0x480);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_31498(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    switch (gCurrentPinballGame->unk346)
    {
    case 0:
        if (gCurrentPinballGame->unk344)
        {
            if (gCurrentPinballGame->unk13 < 3)
            {
                if (gCurrentPinballGame->unk345 < 3)
                {
                    gCurrentPinballGame->unk345++;
                    gCurrentPinballGame->scoreAddedInFrame = 20000;
                    m4aSongNumStart(SE_UNKNOWN_0xDE);
                }
                else
                {
                    gMain.unkF |= 0x1;
                    gCurrentPinballGame->unkEA = 0;
                    gCurrentPinballGame->unkEC = 920;
                    gCurrentPinballGame->unkE8 = 0;
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unkEE = 0;
                    gCurrentPinballGame->unkF2 = 0;
                    gCurrentPinballGame->unkFA = 1;
                    gCurrentPinballGame->unkFB = 0;
                    gCurrentPinballGame->unk346 = 1;
                    gCurrentPinballGame->unk348 = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                    gCurrentPinballGame->scoreAddedInFrame = 200000;
                    m4aSongNumStart(SE_UNKNOWN_0xDF);
                }
            }
            else
            {
                if (gCurrentPinballGame->unk345 < 3)
                {
                    gCurrentPinballGame->unk345++;
                    gCurrentPinballGame->scoreAddedInFrame = 20000;
                    m4aSongNumStart(SE_UNKNOWN_0xDE);
                }
            }

            index = gCurrentPinballGame->unk345;
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
            gCurrentPinballGame->unk344 = 0;
        }
        break;
    case 1:
        if (gCurrentPinballGame->unk348 < 270)
        {
            index = (gCurrentPinballGame->unk348 % 60) / 30 + 4;
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        }
        else
        {
            index = 0;
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
            gCurrentPinballGame->unk346 = 2;
            gCurrentPinballGame->unk345 = 0;
        }

        if (gCurrentPinballGame->unk348 == 60)
        {
            m4aSongNumStart(MUS_EGG_MODE_START);
            gCurrentPinballGame->unk728 = 0;
            gCurrentPinballGame->unk1EC = 5;
            gCurrentPinballGame->unk1ED = 12;
            gCurrentPinballGame->unk1F0 = 0;
        }

        gCurrentPinballGame->unk348++;
        break;
    case 3:
        if (gUnknown_086AE5A0[gCurrentPinballGame->unk345][1] > gCurrentPinballGame->unk348)
        {
            gCurrentPinballGame->unk348++;
        }
        else
        {
            gCurrentPinballGame->unk348 = 0;
            gCurrentPinballGame->unk345++;
            if (gCurrentPinballGame->unk345 == 10)
                gCurrentPinballGame->unk346 = 4;

            if (gCurrentPinballGame->unk345 == 6)
                m4aSongNumStart(SE_UNKNOWN_0xE0);

            index = gUnknown_086AE5A0[gCurrentPinballGame->unk345][0];
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->unk345 < 6)
        {
            gCurrentPinballGame->unk200 = 280;
        }
        else
        {
            gCurrentPinballGame->unk200 += 6;
            if (gCurrentPinballGame->unk346 == 4)
                gCurrentPinballGame->unk200 = gCurrentPinballGame->unk200 + 20;
        }
        break;
    case 4:
        if (gCurrentPinballGame->unk343 && gCurrentPinballGame->unk344)
        {
            gMain.unkF |= 0x1;
            gCurrentPinballGame->unkEA = 0;
            gCurrentPinballGame->unkEC = 160;
            gCurrentPinballGame->unkE8 = 0;
            gCurrentPinballGame->unkE6 = 0;
            gCurrentPinballGame->unkEE = 0;
            gCurrentPinballGame->unkF2 = 0;
            gCurrentPinballGame->unkFA = 1;
            gCurrentPinballGame->unkFB = 0;
            gCurrentPinballGame->unk346 = 5;
            gCurrentPinballGame->unk348 = 0;
            gCurrentPinballGame->unk345 = 10;
            m4aSongNumStart(SE_UNKNOWN_0xE0);
            gCurrentPinballGame->unk1EC = 1;
            gCurrentPinballGame->unk1F4 = 2080;
            gCurrentPinballGame->unk1F6 = 960;
        }

        gCurrentPinballGame->unk344 = 0;
        break;
    case 5:
        if (gUnknown_086AE5A0[gCurrentPinballGame->unk345][1] > gCurrentPinballGame->unk348)
        {
            gCurrentPinballGame->unk348++;
        }
        else
        {
            gCurrentPinballGame->unk348 = 0;
            gCurrentPinballGame->unk345++;
            if (gCurrentPinballGame->unk345 == 15)
                gCurrentPinballGame->unk346 = 6;

            index = gUnknown_086AE5A0[gCurrentPinballGame->unk345][0];
            DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->unk345 == 14 && gCurrentPinballGame->unk348 == 10)
            m4aSongNumStart(SE_UNKNOWN_0xE1);

        if (gCurrentPinballGame->unk1F6 > 700)
            gCurrentPinballGame->unk1F6 -= 5;
        else
            gCurrentPinballGame->unk1F6 = 700;
        break;
    case 6:
        gCurrentPinballGame->unk345 = 0;
        gCurrentPinballGame->unk348 = 0;
        gCurrentPinballGame->unk346 = 0;
        gCurrentPinballGame->unk343 = 0;
        break;
    }

    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[47 + i];
        if (group->available)
        {
            if (gUnknown_086AE58A[gCurrentPinballGame->unk355[i]][0] > gCurrentPinballGame->unk35E[i])
            {
                gCurrentPinballGame->unk35E[i]++;
            }
            else
            {
                gCurrentPinballGame->unk35E[i] = 0;
                gCurrentPinballGame->unk355[i]++;
                if (gCurrentPinballGame->unk355[i] == 6)
                {
                    group->available = 0;
                    gCurrentPinballGame->unk355[i] = 5;
                }
            }

            index = gUnknown_086AE588[gCurrentPinballGame->unk355[i]][0];
            DmaCopy16(3, &gUnknown_0845A08C[index], (void *)0x060140a0 + i * 0x100, 0x100);
            group->baseX = gUnknown_086AE554[gCurrentPinballGame->unk359[i]].x - gCurrentPinballGame->unk58;
            group->baseY = gUnknown_086AE554[gCurrentPinballGame->unk359[i]].y - gCurrentPinballGame->unk5A;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void sub_31B30(void)
{
    s16 i;
    struct SpriteGroup *group;

    if (gMain.selectedField == FIELD_RUBY)
        group = &gMain.spriteGroups[81];
    else
        group = &gMain.spriteGroups[85];

    if (group->available)
    {
        if (gCurrentPinballGame->unk4C < 8)
        {
            group->baseX = gCurrentPinballGame->unk58;
            group->baseX = -8 - group->baseX;
        }
        else
        {
            group->baseX = gCurrentPinballGame->unk58;
            group->baseX = 256 - group->baseX;
        }

        group->baseY = 0;
        for (i = 0; i < 5; i++)
        {
            struct OamDataSimple *oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + i * 0x20;
        }
    }
}

/**
 * Executed when saving or loading from a main field
 * arg0
 *   0 when saving and loading normally
 *   2 when loading into the evo or mart menu
 */
void sub_31BE8(s16 arg0)
{
    if (gCurrentPinballGame->unk70 == 1)
    {
        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[arg0], (void*)OBJ_PLTT, 0x20);
    }

    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[arg0] + 0x40, (void*)OBJ_PLTT + 0x40, 0xC0);
    }
    else
    {
        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[arg0] + 0x40, (void*)OBJ_PLTT + 0x40, 0xE0);
    }

    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[arg0] + 0x140, (void *)OBJ_PLTT + 0x140, 0x20);

    // related to Y position of camera on the field
    if (gCurrentPinballGame->unk68 < 170)
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][arg0 * 2], (void *)OBJ_PLTT + 0x160, 0x20);
    }
    else
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][arg0 * 2 + 1], (void *)OBJ_PLTT + 0x160, 0x20);
    }
}
