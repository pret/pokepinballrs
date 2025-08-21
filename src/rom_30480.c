#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gUnknown_084FD18C[][0x200];
extern const u16 gUnknown_086AD2EE[][4];
extern const u16 gUnknown_086B4D4E[][2][3];


void sub_30480(void)
{
    gCurrentPinballGame->unk1EC = 1;
    gCurrentPinballGame->unk1EE = 0;
    gCurrentPinballGame->unk1ED = 0;
    gCurrentPinballGame->unk1F0 = 0;
    gCurrentPinballGame->unk1F4 = 2080;
    gCurrentPinballGame->unk1F6 = 700;
}

void sub_304C8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 sp0;
    s16 index;
    s16 var1;
    s16 var2;
    s16 var3;
    int var0;

    var3 = 0;
    var1 = 0;
    var2 = 0;
    group = &gMain.spriteGroups[52];
    sp0 = 0;
    switch (gCurrentPinballGame->unk1EC)
    {
    case 0:
    case 1:
        break;
    case 2:
        var3 = 4;
        var1 = 4;
        var2 = 3;
        break;
    case 3:
        var3 = 8;
        var1 = 4;
        var2 = 3;
        break;
    case 4:
        var3 = 12;
        var1 = 12;
        var2 = 5;
        break;
    case 5:
        var3 = 33;
        var1 = 0;
        var2 = 0;
        break;
    }

    if (gCurrentPinballGame->unk1EE != gCurrentPinballGame->unk1ED)
    {
        index = gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][3];
        DmaCopy16(3, &gUnknown_084FD18C[index], (void *)0x06011CE0, 0x200);
        gCurrentPinballGame->unk1EE = gCurrentPinballGame->unk1ED;
    }

    if (gCurrentPinballGame->unk1EC > 1)
    {
        if (gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][1] > gCurrentPinballGame->unk1F0)
        {
            gCurrentPinballGame->unk1F0++;
        }
        else
        {
            gCurrentPinballGame->unk1ED++;
            gCurrentPinballGame->unk1F0 = 0;
            if (gCurrentPinballGame->unk1ED >= var3)
            {
                gCurrentPinballGame->unk1ED = var1;
                gCurrentPinballGame->unk1EC = var2;
            }

            if (gCurrentPinballGame->unk1ED == 18)
                BuildSpeciesWeightsForEggMode();

            if (gCurrentPinballGame->unk1ED == 19)
            {
                PickSpeciesForEggMode();
                if (gMain.mainState != STATE_GAME_IDLE)
                    SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);
            }

            if (gCurrentPinballGame->unk1ED == 20)
                sub_28BFC();

            if ((gCurrentPinballGame->unk1ED == 8 || gCurrentPinballGame->unk1ED == 27) && gCurrentPinballGame->unk1F0 == 0)
                m4aMPlayAllStop();

            if (gCurrentPinballGame->unk1ED == 12 && gCurrentPinballGame->unk1F0 == 0)
                m4aSongNumStart(MUS_EGG_MODE_START);

            if (gCurrentPinballGame->unk1ED == 29)
                sub_19B64(5);

            if (gCurrentPinballGame->unk1ED == 28)
                m4aSongNumStart(SE_UNKNOWN_0x92);
        }

        sp0 = gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][0];
    }

    group->baseX = gCurrentPinballGame->unk1F4 / 10 - gCurrentPinballGame->unk58;
    if (gCurrentPinballGame->unk1EC > 0)
    {
        if (gCurrentPinballGame->unk1ED == 32 && gCurrentPinballGame->unk1F0 > 208)
        {
            var0 = (0x100 - gCurrentPinballGame->unk1F0) / 16;
            if (gMain.systemFrameCount & ((var0 + 1) * 2))
                group->baseY = gCurrentPinballGame->unk1F6 / 10 - gCurrentPinballGame->unk5A;
            else
                group->baseY = 200;
        }
        else
        {
            group->baseY = gCurrentPinballGame->unk1F6 / 10 - gCurrentPinballGame->unk5A;
        }
    }
    else
    {
        group->baseY = 200;
    }

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B4D4E[sp0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[51];
    if (group->available)
    {
        group->baseX = 192 - gCurrentPinballGame->unk58;
        if (gCurrentPinballGame->unk346 > 2 && gMain.unkF)
            group->baseY = 56 - gCurrentPinballGame->unk5A;
        else
            group->baseY = 200;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}
