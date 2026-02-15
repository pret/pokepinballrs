#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u16 gUnknown_086B4D4E[40][2][3];
extern const u16 gUnknown_086AE54A[];
extern const u8 gSapphireStageBasket_Gfx[][0x280];
extern const u8 gSapphireBoardSeedot_Gfx[][0x180];
extern const u16 gUnknown_086AE544[];
extern const u16 gSapphireBoardSeedotSpritesheetOam[6][6][2][3];
extern const u16 gUnknown_08137D06[][14];
extern const u16 gUnknown_08137CF6[][4];
extern const u16 gUnknown_08137CE2[][5];


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

void sub_308DC(void)
{
    s16 i;
    s16 var0;

    if (gCurrentPinballGame->unk328)
    {
        if (gCurrentPinballGame->unk13 != 7)
        {
            if (gCurrentPinballGame->unk13 < 3)
            {
                if (gCurrentPinballGame->unk6BD < 3)
                {
                    gCurrentPinballGame->unk33C[gCurrentPinballGame->unk6BD] = -100;
                    gCurrentPinballGame->unk332[gCurrentPinballGame->unk6BD] = 0;
                    gCurrentPinballGame->unk336[gCurrentPinballGame->unk6BD] = 0;
                    gCurrentPinballGame->unk32C[gCurrentPinballGame->unk6BD] = 1;
                    gCurrentPinballGame->unk336[gCurrentPinballGame->unk6BD] = 0;
                    gCurrentPinballGame->unk6BD++;
                    gCurrentPinballGame->unk32A = 1800;
                    if (gCurrentPinballGame->unk6BD == 3)
                        gCurrentPinballGame->unk6C2 = 1;
                }
            }
            else
            {
                if (gCurrentPinballGame->unk6BD < 2)
                {
                    gCurrentPinballGame->unk33C[gCurrentPinballGame->unk6BD] = -100;
                    gCurrentPinballGame->unk332[gCurrentPinballGame->unk6BD] = 0;
                    gCurrentPinballGame->unk336[gCurrentPinballGame->unk6BD] = 0;
                    gCurrentPinballGame->unk32C[gCurrentPinballGame->unk6BD] = 1;
                    gCurrentPinballGame->unk336[gCurrentPinballGame->unk6BD] = 0;
                    gCurrentPinballGame->unk32A = 1800;
                    gCurrentPinballGame->unk6BD++;
                }
            }
        }

        gCurrentPinballGame->unk328 = 0;
        gCurrentPinballGame->scoreAddedInFrame = 3000;
    }

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->unk32C[i])
        {
        case 0:
            gCurrentPinballGame->unk33C[i] = -100;
            gCurrentPinballGame->unk332[i] = 0;
            gCurrentPinballGame->unk336[i] = 0;
            break;
        case 1:
            if (gCurrentPinballGame->unk336[i] < 33)
            {
                if (gCurrentPinballGame->unk336[i] == 0)
                    m4aSongNumStart(SE_UNKNOWN_0xE9);

                if (gCurrentPinballGame->unk336[i] == 26)
                    m4aSongNumStart(SE_UNKNOWN_0xEA);

                gCurrentPinballGame->unk336[i]++;
                if (gCurrentPinballGame->unk336[i] < 21)
                {
                    gCurrentPinballGame->unk32F[i] = 0;
                    gCurrentPinballGame->unk33C[i] = gCurrentPinballGame->unk336[i] * 4 - 80;
                    if (gCurrentPinballGame->unk336[i] == 20)
                        gCurrentPinballGame->unk326 = 23;
                }
                else if (gCurrentPinballGame->unk336[i] < 25)
                {
                    gCurrentPinballGame->unk32F[i] = 1;
                }
                else
                {
                    gCurrentPinballGame->unk32F[i] = 2;
                }
            }
            else
            {
                gCurrentPinballGame->unk32C[i] = 2;
                gCurrentPinballGame->unk336[i] = 0;
                if (i == 2)
                    sub_19B64(7);
            }
            break;
        case 2:
            gCurrentPinballGame->unk32F[i] = (((gCurrentPinballGame->unk290 % 32) / 16) * 2) + 1;
            if (gCurrentPinballGame->unk32F[i] == 1)
                gCurrentPinballGame->unk33C[i] = -2;
            else
                gCurrentPinballGame->unk33C[i] = 0;
            break;
        case 3:
            var0 = gCurrentPinballGame->unk336[i];
            if (var0 < 32)
            {
                gCurrentPinballGame->unk32F[i] = var0 / 16 + 4;
                gCurrentPinballGame->unk332[i] = var0 / 16 + 1;
            }
            else if (var0 < 38)
            {
                if (var0 == 32 && (gMain.unkF & 0x20) == 0)
                    m4aSongNumStart(SE_UNKNOWN_0xEB);

                gCurrentPinballGame->unk32F[i] = 6;
                gCurrentPinballGame->unk332[i] = 3;
            }
            else if (var0 < 46)
            {
                gCurrentPinballGame->unk332[i] = 4;
            }
            else if (var0 < 54)
            {
                gCurrentPinballGame->unk332[i] = 5;
            }
            else
            {
                gCurrentPinballGame->unk32C[i] = 0;
            }

            gCurrentPinballGame->unk336[i]++;
            break;
        }
    }

    if (gCurrentPinballGame->unk326)
    {
        gCurrentPinballGame->unk324 = gUnknown_086AE54A[gCurrentPinballGame->unk326 / 6];
        gCurrentPinballGame->unk326--;
    }

    if (gCurrentPinballGame->unk6C2)
    {
        gCurrentPinballGame->unk6C2--;
        if (gCurrentPinballGame->unk6C2 == 0)
        {
            if (gCurrentPinballGame->unkE4)
                gCurrentPinballGame->unk6C2 = 1;
            else
                gCurrentPinballGame->unkE4 = 4;

            if (gCurrentPinballGame->unk6C2 == 0)
            {
                gMain.unkF |= 1;
                gCurrentPinballGame->unkEA = 70;
                gCurrentPinballGame->unkEC = 160;
                gCurrentPinballGame->unkE8 = 0;
                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unkEE = 0;
                gCurrentPinballGame->unkF2 = 4;
                gCurrentPinballGame->unkFA = 1;
                gCurrentPinballGame->unkFB = 0;
                gCurrentPinballGame->unkF4 = 120;
                gCurrentPinballGame->unkF6 = 0;
                gCurrentPinballGame->unkF0 = 50;
                gCurrentPinballGame->unkF8 = 0;
                DmaCopy16(3, gUnknown_086ACEF8[4], (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_086ACF18[4], (void *)0x050003C0, 0x20);
                gMain.blendControl = 0xCE;
            }
        }
    }
    if (gCurrentPinballGame->unk6BE)
    {
        var0 = gCurrentPinballGame->unk6C0++;
        if (var0 <= 60)
        {
            if (var0 % 30 == 0)
            {
                if (gCurrentPinballGame->unk32C[var0 / 30] == 2)
                {
                    gCurrentPinballGame->unk32C[var0 / 30] = 3;
                    gCurrentPinballGame->unk336[var0 / 30] = 0;
                }
            }
        }
        else
        {
            gCurrentPinballGame->unk6BE = 0;
            gCurrentPinballGame->unk6C0 = 0;
        }
    }

    if (gCurrentPinballGame->unk32A)
    {
        gCurrentPinballGame->unk32A--;
        if (gCurrentPinballGame->unk32A == 0)
        {
            if (gCurrentPinballGame->unk6BD == 1 || gCurrentPinballGame->unk6BD == 2)
            {
                gCurrentPinballGame->unk6BD--;
                gCurrentPinballGame->unk32C[gCurrentPinballGame->unk6BD] = 3;
                gCurrentPinballGame->unk336[gCurrentPinballGame->unk6BD] = 0;
                gCurrentPinballGame->unk32A = 1800;
            }
        }
    }
}

void sub_30EB4(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    int var0;

    group = &gMain.spriteGroups[64];
    if (!group->available)
        return;

    group->baseX = 10 - gCurrentPinballGame->unk58;
    group->baseY = 298 - gCurrentPinballGame->unk5A;
    index = gCurrentPinballGame->unk324;
    DmaCopy16(3, gSapphireStageBasket_Gfx[index], (void *)0x060139A0, 0x280);

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[68];
    group->baseX = 10 - gCurrentPinballGame->unk58;
    group->baseY = 298 - gCurrentPinballGame->unk5A;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    for (j = 0; j < 3; j++)
    {
        group = &gMain.spriteGroups[65 + j];

        var0 = gUnknown_086AE544[j] - j;
        group->baseX = var0 - gCurrentPinballGame->unk58;
        if (gCurrentPinballGame->unk32C[j] > 0)
            group->baseY = gCurrentPinballGame->unk33C[j] + 292 - gCurrentPinballGame->unk5A;
        else
            group->baseY = 200;

        DmaCopy16(3, gSapphireBoardSeedot_Gfx[gCurrentPinballGame->unk32F[j]], (void *)0x06013C20 + j * 0x180, 0x160);
        index = gCurrentPinballGame->unk332[j];
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gSapphireBoardSeedotSpritesheetOam[j][index][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }
}

void sub_31144(void)
{
    if (gCurrentPinballGame->unk1A4 == 0)
    {
        if (gCurrentPinballGame->unk1A5 == 1)
        {
            if (gCurrentPinballGame->unk1B4 < 96)
            {
                if (gCurrentPinballGame->unk1B4 < 8)
                    gCurrentPinballGame->unk1AC = gUnknown_08137CF6[1][gCurrentPinballGame->unk1B4 / 2];
                else
                    gCurrentPinballGame->unk1AC = gUnknown_08137CE2[1][(gCurrentPinballGame->unk1B4 % 32) / 8];

                gCurrentPinballGame->unk1B4++;
            }
            else
            {
                gCurrentPinballGame->unk1B4 = 0;
            }

            gCurrentPinballGame->unk1AD = 2;
        }
        else
        {
            if (gCurrentPinballGame->unk1B4 < 120)
            {
                if (gCurrentPinballGame->unk1B4 < 8)
                    gCurrentPinballGame->unk1AC = gUnknown_08137CF6[0][gCurrentPinballGame->unk1B4 / 2];
                else
                    gCurrentPinballGame->unk1AC = gUnknown_08137CE2[0][(gCurrentPinballGame->unk1B4 % 40) / 8];

                gCurrentPinballGame->unk1B4++;
            }
            else
            {
                gCurrentPinballGame->unk1B4 = 0;
            }

            gCurrentPinballGame->unk1AD = 0;
        }

        if (gCurrentPinballGame->unk72E > 2)
        {
            if (gCurrentPinballGame->evolvablePartySize > 0 && gCurrentPinballGame->unk1A5 == 0)
            {
                gCurrentPinballGame->unk1A4 = 1;
                gCurrentPinballGame->unk1B4 = 0;
                gCurrentPinballGame->unk1A5 = 1;
            }
        }
        else
        {
            if (gCurrentPinballGame->unk13 != 6 && gCurrentPinballGame->unk1A5 == 1)
            {
                gCurrentPinballGame->unk1A4 = 1;
                gCurrentPinballGame->unk1B4 = 0;
                gCurrentPinballGame->unk1A5 = 0;
            }
        }
    }
    else
    {
        gCurrentPinballGame->unk1AC = gUnknown_08137D06[gCurrentPinballGame->unk1A5][gCurrentPinballGame->unk1B4 / 3];
        if (gCurrentPinballGame->unk1AC >= 4 && gCurrentPinballGame->unk1AC < 6)
        {
            gCurrentPinballGame->unk1AD = 1;
        }
        else
        {
            if (gCurrentPinballGame->unk1A5 == 1)
            {
                if (gCurrentPinballGame->unk1B4 < 15)
                    gCurrentPinballGame->unk1AD = 0;
                else
                    gCurrentPinballGame->unk1AD = 2;
            }
            else
            {
                if (gCurrentPinballGame->unk1B4 < 15)
                    gCurrentPinballGame->unk1AD = 2;
                else
                    gCurrentPinballGame->unk1AD = 0;
            }
        }

        gCurrentPinballGame->unk1B4++;
        if (gCurrentPinballGame->unk1B4 == 42)
        {
            gCurrentPinballGame->unk1A4 = 0;
            gCurrentPinballGame->unk1B4 = 0;
        }
    }
}
