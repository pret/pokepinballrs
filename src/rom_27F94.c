#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern u8 gUnknown_0202C7A0[];
extern u8 gUnknown_020306D0[];
extern u8 gUnknown_02030760[];
extern u8 gUnknown_020315D0[];
extern u8 gUnknown_02031060[];

extern const u8 gUnknown_0839C78C[];
extern const u8 gUnknown_0839DBAC[];
extern const u8 gUnknown_086ACF80[];
extern const u8 gUnknown_081C0064[];
extern const struct Vector16 gUnknown_086AE124[];
extern const u8 (*gUnknown_086BB6F4[])[0x480];
extern const u8 (*gUnknown_086B15B4[])[0x20];
extern const u8 gUnknown_0844AA0C[][0x480];
extern const u16 gUnknown_086B263C[][3][3];
extern const u16 gUnknown_086AE154[][10];
extern const s16 gUnknown_086AD436[][2];
extern const u16 gUnknown_086B55DC[][18];
extern const s16 gUnknown_086AE1A4[][12];
extern const u16 gUnknown_086B53B4[][3];
extern const s16 gUnknown_086AE2F4[][2];

extern struct SongHeader gUnknown_0869F58C;


void sub_27F94(void)
{
    s16 i;

    if (gCurrentPinballGame->unk294 && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->unk17 < 10)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->unk18 = 200;
        gCurrentPinballGame->unk17 = 10;
    }

    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        BuildSpeciesWeightsForCatchEmMode();
        gCurrentPinballGame->unk17++;
        break;
    case 1:
        PickSpeciesForCatchEmMode();
        if (gMain.mainState != 3)
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);

        gCurrentPinballGame->unk17++;
        break;
    case 2:
        sub_28AE0();
        gCurrentPinballGame->catchModeArrows = 0;
        gCurrentPinballGame->unk17++;
        break;
    case 3:
        sub_1C7F4(3, 0);
        gCurrentPinballGame->unk6C5 = 0;
        gCurrentPinballGame->unk602 = 0;
        gCurrentPinballGame->unk17++;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->unk6D3[i] = 15;
        break;
    case 4:
        if (gMain.unkF == 0)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->unk28 == 94)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->unk28 == 93)
                {
                    gMain.unkF |= 1;
                    gCurrentPinballGame->unkEA = 0;
                    gCurrentPinballGame->unkEC = 120;
                    gCurrentPinballGame->unkE8 = 0;
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unkEE = 0;
                    gCurrentPinballGame->unkF2 = 2;
                    gCurrentPinballGame->unkFA = 1;
                    gCurrentPinballGame->unkFB = 1;
                    gCurrentPinballGame->unkF4 = 80;
                    gCurrentPinballGame->unkF6 = -2500;
                    gCurrentPinballGame->unkF0 = 50;
                    gCurrentPinballGame->unkF8 = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->unk28 == 73)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE);
                }
                else if (gCurrentPinballGame->unk28 < 17)
                {
                    gCurrentPinballGame->unk294 = 2;
                    gCurrentPinballGame->unk17++;
                }
            }
            else
            {
                if (gCurrentPinballGame->unk28 == 68)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->unk28 == 67)
                {
                    gMain.unkF |= 1;
                    gCurrentPinballGame->unkEA = 0;
                    gCurrentPinballGame->unkEC = 120;
                    gCurrentPinballGame->unkE8 = 0;
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unkEE = 0;
                    gCurrentPinballGame->unkF2 = 2;
                    gCurrentPinballGame->unkFA = 1;
                    gCurrentPinballGame->unkFB = 1;
                    gCurrentPinballGame->unkF4 = 80;
                    gCurrentPinballGame->unkF6 = -2500;
                    gCurrentPinballGame->unkF0 = 50;
                    gCurrentPinballGame->unkF8 = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[2], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[2], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->unk28 == 47)
                {
                    m4aSongNumStart(MUS_CATCH_EM_MODE2);
                }
                else if (gCurrentPinballGame->unk28 == 0)
                {
                    gCurrentPinballGame->unk294 = 2;
                    gCurrentPinballGame->unk17++;
                }
            }
        }

        sub_29334();
        return;
    case 5:
        gCurrentPinballGame->unk729 = 1;
        sub_29334();
        gCurrentPinballGame->unk18 = 0;
        return;
    case 6:
        gCurrentPinballGame->unk729 = 0;
        if (gCurrentPinballGame->unk18 == 0)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unkE4 = 10;
            DmaCopy16(3, gUnknown_0839C78C, (void *)0x06015800, 0x1400);
            DmaCopy16(3, gUnknown_0839DBAC, (void *)0x050003C0, 0x20);
            m4aSongNumStart(SE_UNKNOWN_0xA7);
            gCurrentPinballGame->unk17++;
            gCurrentPinballGame->unk18 = 0;
        }
        break;
    case 7:
        sub_293D8();
        return;
    case 8:
        sub_29624();
        DmaCopy16(3, gUnknown_086ACF80, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gUnknown_020306D0, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->unk288 = 118;
        gCurrentPinballGame->unk28A = 264;
        gCurrentPinballGame->unk720 = 0;
        gCurrentPinballGame->unk71D[0] = 2;
        gCurrentPinballGame->unk71D[1] = 2;
        gCurrentPinballGame->unk71D[2] = 2;
        sub_28C90();
        gCurrentPinballGame->unk5F2 = 1;
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unk29C = 140;
        PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].mainSeriesIndexNumber, 0);
        gCurrentPinballGame->unk18 = 0;
        return;
    case 9:
        if (gCurrentPinballGame->unk18 == 0)
        {
            gCurrentPinballGame->unkEC = 0;
            gCurrentPinballGame->unk18++;
        }
        sub_28C90();
        if (gCurrentPinballGame->unk5AA)
            gCurrentPinballGame->unk5AA--;
        break;
    case 10:
        sub_28E2C();
        sub_2530C();
        gCurrentPinballGame->unk17++;
        break;
    case 11:
        sub_27D44();
        gCurrentPinballGame->unk17++;
        break;
    case 12:
        gCurrentPinballGame->unk729 = 0;
        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk18--;
        }
        else
        {
            if (gCurrentPinballGame->unk71D[2] == 1)
                sub_19B64(3);
            else
                sub_19B64(1);

            gCurrentPinballGame->unk17 = 0;
        }
        break;
    }
}

void sub_28404(void)
{
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 1800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk5A5 = 0;
    gCurrentPinballGame->unk5AA = 0;
    gCurrentPinballGame->unk5A9 = 0;
    gCurrentPinballGame->unk7C = 0;
    gCurrentPinballGame->unk80 = 900;
    gCurrentPinballGame->unk82 = -1400;
    gCurrentPinballGame->unk73 = 0;
    gCurrentPinballGame->unkBC = 0;
    gCurrentPinballGame->unkBE = 0;
    gCurrentPinballGame->unkC0 = 0;
    gCurrentPinballGame->unkC2 = 0;
    gCurrentPinballGame->unkC4 = 0;
    gCurrentPinballGame->unkC6 = 0;
    gCurrentPinballGame->unk72F = 0;
    gCurrentPinballGame->unk731 = 0;
    gCurrentPinballGame->unk74[0] = 0;
    gCurrentPinballGame->unk74[1] = 10;
    gCurrentPinballGame->unk74[2] = 20;
    gCurrentPinballGame->unk74[3] = 30;
    gCurrentPinballGame->unk724 = 3240;
    gCurrentPinballGame->unk714 = 0;
    gCurrentPinballGame->holeIndicators[0] = 0;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
}

void sub_28544(void)
{
    struct Vector32 tempVec;
    struct Vector32 deltaVec;
    u16 angle;
    int xx, yy;
    int deltaMagSquared;
    u16 var0;

    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        gCurrentPinballGame->currentSpecies = SPECIES_JIRACHI;
        sub_28AE0();
        gCurrentPinballGame->unk17++;
        return;
    case 1:
        if (gMain.unkF == 0)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->unk28 == 94)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->unk28 == 93)
                {
                    gMain.unkF |= 1;
                    gCurrentPinballGame->unkEA = 0;
                    gCurrentPinballGame->unkEC = 120;
                    gCurrentPinballGame->unkE8 = 0;
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unkEE = 0;
                    gCurrentPinballGame->unkF2 = 5;
                    gCurrentPinballGame->unkFA = 1;
                    gCurrentPinballGame->unkFB = 1;
                    gCurrentPinballGame->unkF4 = 80;
                    gCurrentPinballGame->unkF6 = -2500;
                    gCurrentPinballGame->unkF0 = 50;
                    gCurrentPinballGame->unkF8 = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[5], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[5], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                }
                else if (gCurrentPinballGame->unk28 == 73)
                {
                    m4aSongNumStart(MUS_JIRACHI);
                }
                else if (gCurrentPinballGame->unk28 == 40)
                {
                    gCurrentPinballGame->unk17++;
                }
            }
            else
            {
                if (gCurrentPinballGame->unk28 == 68)
                {
                    m4aMPlayAllStop();
                }
                else if (gCurrentPinballGame->unk28 == 67)
                {
                    gMain.unkF |= 1;
                    gCurrentPinballGame->unkEA = 0;
                    gCurrentPinballGame->unkEC = 120;
                    gCurrentPinballGame->unkE8 = 0;
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unkEE = 0;
                    gCurrentPinballGame->unkF2 = 5;
                    gCurrentPinballGame->unkFA = 1;
                    gCurrentPinballGame->unkFB = 1;
                    gCurrentPinballGame->unkF4 = 80;
                    gCurrentPinballGame->unkF6 = -2500;
                    gCurrentPinballGame->unkF0 = 50;
                    gCurrentPinballGame->unkF8 = 0;
                    DmaCopy16(3, gUnknown_086ACEF8[5], (void *)0x06015800, 0x2400);
                    DmaCopy16(3, gUnknown_086ACF18[5], (void *)0x050003C0, 0x20);
                    gMain.blendControl = 0xCE;
                    return;
                }
                else if (gCurrentPinballGame->unk28 == 47)
                {
                    m4aSongNumStart(MUS_JIRACHI);
                    return;
                }
                else if (gCurrentPinballGame->unk28 == 40)
                {
                    gCurrentPinballGame->unk17++;
                }
            }
        }
        else if ((gMain.unkF & 0x1) && gCurrentPinballGame->unkF0 == 1)
        {
            gCurrentPinballGame->unk6C4 = 3;
            return;
        }
        break;
    case 2:
        DmaCopy16(3, gUnknown_086ACF80, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gUnknown_020306D0, (void *)0x050003A0, 0x20);
        gCurrentPinballGame->unk720 = 0;
        gCurrentPinballGame->unk71D[0] = 2;
        gCurrentPinballGame->unk71D[1] = 2;
        gCurrentPinballGame->unk71D[2] = 2;
        gCurrentPinballGame->unk5F2 = 1;
        gMain.unk44[33]->available = 1;
        DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
        gCurrentPinballGame->unk28 = 40;
        gCurrentPinballGame->unk80 = 900;
        gCurrentPinballGame->unk82 = -1400;
        gCurrentPinballGame->unk73 = 0;
        gCurrentPinballGame->unkBC = gUnknown_086AE124[gCurrentPinballGame->unk73].x;
        gCurrentPinballGame->unkBE = gUnknown_086AE124[gCurrentPinballGame->unk73].y;
        gCurrentPinballGame->unk18 = 0;
        m4aSongNumStart(SE_UNKNOWN_0x144);
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unkC0 = gCurrentPinballGame->unk80;
        gCurrentPinballGame->unkC2 = gCurrentPinballGame->unk82;
        return;
    case 3:
        if (gCurrentPinballGame->unk5A4 == 2)
        {
            gCurrentPinballGame->unk288 = gCurrentPinballGame->unkC0 / 10 + 118;
            gCurrentPinballGame->unk28A = gCurrentPinballGame->unkC2 / 10 + 272;
        }
        else
        {
            deltaVec.x = gCurrentPinballGame->unkBC - gCurrentPinballGame->unk80;
            deltaVec.y = gCurrentPinballGame->unkBE - gCurrentPinballGame->unk82;
            xx = deltaVec.x * deltaVec.x;
            yy = deltaVec.y * deltaVec.y;
            deltaMagSquared = xx + yy;
            angle = ArcTan2(deltaVec.x, -deltaVec.y);
            if (deltaMagSquared < 2500)
            {
                tempVec.x = 0;
                tempVec.y = 0;
                if (gCurrentPinballGame->unk7C < 200)
                {
                    gCurrentPinballGame->unk7C++;
                }
                else
                {
                    gCurrentPinballGame->unk7C = 0;
                    if (gCurrentPinballGame->unk73 < 11)
                        gCurrentPinballGame->unk73++;
                    else
                        gCurrentPinballGame->unk73 = 0;

                    m4aSongNumStart(SE_UNKNOWN_0x144);
                    gCurrentPinballGame->unkBC = gUnknown_086AE124[gCurrentPinballGame->unk73].x;
                    gCurrentPinballGame->unkBE = gUnknown_086AE124[gCurrentPinballGame->unk73].y;
                }
            }
            else
            {
                tempVec.x = (Cos(angle) *  7) / 20000;
                tempVec.y = (Sin(angle) * -7) / 20000;
            }

            gCurrentPinballGame->unk80 += tempVec.x;
            gCurrentPinballGame->unk82 += tempVec.y;
            var0 = ((gCurrentPinballGame->unk18 % 80) << 0x10) / 80;
            gCurrentPinballGame->unkC0 = gCurrentPinballGame->unk80;
            gCurrentPinballGame->unkC2 = gCurrentPinballGame->unk82 + (Sin(var0) * 60) / 20000;
        }

        if (gCurrentPinballGame->unk18 < 500)
        {
            gCurrentPinballGame->unk28 = 40;
            if (gCurrentPinballGame->unk18 == 499)
                gCurrentPinballGame->unk294 = 2;
        }

        gCurrentPinballGame->unk18++;
        sub_28EA0();
        if (gCurrentPinballGame->unk5AA)
            gCurrentPinballGame->unk5AA--;

        if (gCurrentPinballGame->unk294 && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->unk17 < 5)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_END_OF_BALL2);
            gCurrentPinballGame->unk17 = 4;
            gCurrentPinballGame->unk18 = 150;
            gCurrentPinballGame->unk5F2 = 0;
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F58C);
        }
        return;
    case 4:
        if (gCurrentPinballGame->unk18)
            gCurrentPinballGame->unk18--;
        else
            gCurrentPinballGame->unk17 = 5;

        sub_28EA0();
        if (gCurrentPinballGame->unk5AA)
            gCurrentPinballGame->unk5AA--;
        break;
    case 5:
        sub_28EA0();
        sub_292A0();
        sub_27D44();
        gCurrentPinballGame->unk72 = 240;
        gCurrentPinballGame->unk17 = 6;
        gCurrentPinballGame->unk18 = 0;
        return;
    case 6:
        gCurrentPinballGame->unk729 = 0;
        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk18--;
        }
        else
        {
            if (gCurrentPinballGame->unk71D[2] == 1)
                sub_19B64(3);
            else
                sub_19B64(1);

            gCurrentPinballGame->unk17 = 0;
        }
    }
}

void sub_28AE0(void)
{
    s16 i;
    s16 catchIndex;
    const u8 *sp0[3];
    const u8 *spC[3];

    catchIndex = gSpeciesInfo[gCurrentPinballGame->currentSpecies].catchIndex;
    for (i = 0; i < 3; i++)
    {
        sp0[i] = gUnknown_086BB6F4[catchIndex / 5][(i + (catchIndex % 5) * 3)];
        spC[i] = gUnknown_086B15B4[catchIndex / 5][i * 5 + catchIndex % 5];
    }

    for (i = 0; i < 3; i++)
    {
        DmaCopy16(3, sp0[i], &gUnknown_02030760[i * 0x480], 0x480);
        DmaCopy16(3, spC[i], &gUnknown_020306D0[i * 0x20], 0x20);
    }

    DmaCopy16(3, gUnknown_086B15B4[0][15], &gUnknown_020306D0[0x60], 0x20);
}

void sub_28BFC(void)
{
    s16 eggIndex;
    const u8 *src0;
    const u8 *src1;

    eggIndex= gSpeciesInfo[gCurrentPinballGame->currentSpecies].eggIndex;
    src0 = gMonHatchSpriteGroupGfx[eggIndex / 6][eggIndex % 6];
    src1 = gMonHatchSpriteGroupPals[eggIndex / 6][eggIndex % 6];
    DmaCopy16(3, src0, gUnknown_0202C7A0, 0x10E0);
    DmaCopy16(3, src1, gUnknown_020315D0, 0x20);
}

void sub_28C90(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 index;

    index = (gMain.fieldFrameCount % 50) / 25;
    group = gMain.unk44[33];
    if (!group->available)
        return;

    gCurrentPinballGame->unkC4 = 96;
    gCurrentPinballGame->unkC6 = 288;
    group->baseX =  96 - gCurrentPinballGame->unk58;
    group->baseY = 288 - gCurrentPinballGame->unk5A;
    if (gCurrentPinballGame->unk5A9 > 4)
    {
        if (gCurrentPinballGame->unk5A9 == 20 || gCurrentPinballGame->unk5A9 == 200)
        {
            DmaCopy16(3, gUnknown_02031060, (void *)0x06010CA0, 0x480);
        }

        if (gCurrentPinballGame->unk5A9 == 24)
        {
            DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
        }

        gCurrentPinballGame->unk5A9--;;
    }
    else if (gCurrentPinballGame->unk1BC == 5)
    {
        DmaCopy16(3, &gUnknown_02030760[index * 0x480], (void *)0x06010CA0, 0x480);
    }

    if (gCurrentPinballGame->unk5A8 < 13)
        priority = 2;
    else
        priority = 1;

    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 4; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].priority = priority;
    }
}

void sub_28E2C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.unk44[33];
    if (group->available)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.unk44[33]->available = 0;
}

void sub_28EA0(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 priority;
    s16 var1;

    index = (gMain.fieldFrameCount % 50) / 25;
    group = gMain.unk44[33];
    if (group->available)
    {
        gCurrentPinballGame->unkC4 = gCurrentPinballGame->unkC0 / 10 + 96;
        gCurrentPinballGame->unkC6 = gCurrentPinballGame->unkC2 / 10 + 288;
        group->baseX = gCurrentPinballGame->unkC0 / 10 + 96u - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unkC2 / 10 + 288u - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk17 > 3)
        {
            if (gCurrentPinballGame->unk18 >= 90)
            {
                index = (150 - gCurrentPinballGame->unk18) / 4;
                DmaCopy16(3, &gUnknown_0844AA0C[index], (void *)0x06010CA0, 0x480);
            }
            else
            {
                group->baseY = 190;
            }
        }
        else if (gCurrentPinballGame->unk5A9 > 4)
        {
            if (gCurrentPinballGame->unk5A9 == 20 || gCurrentPinballGame->unk5A9 == 200)
            {
                DmaCopy16(3, gUnknown_02031060, (void *)0x06010CA0, 0x480);
            }

            if (gCurrentPinballGame->unk5A9 == 24)
            {
                DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
            }

            gCurrentPinballGame->unk5A9--;
        }
        else if (gCurrentPinballGame->unk1BC == 5)
        {
            DmaCopy16(3, &gUnknown_02030760[index * 0x480], (void *)0x06010CA0, 0x480);
        }

        if (gCurrentPinballGame->unk5A4 != 2)
        {
            priority = 1;
        }
        else
        {
            if (gCurrentPinballGame->unk5A8 < 13)
                priority = 2;
            else
                priority = 1;
        }

        if (group->baseY >= 200)
            group->baseY = 200;
        else if (group->baseY < -60)
            group->baseY = -60;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].priority = priority;
        }
    }

    for (j = 0; j < 4; j++)
    {

        group = gMain.unk44[45 + j];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->unk84[j].x - gCurrentPinballGame->unk58;
            group->baseY = gCurrentPinballGame->unk84[j].y - gCurrentPinballGame->unk5A;
            var1 = gUnknown_086AE154[j][9 - gCurrentPinballGame->unk74[j] / 4];
            if (group->baseY >= 200)
                group->baseY = 200;
            else if (group->baseY < -60)
                group->baseY = -60;

            for (i = 0; i < 3; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B263C[var1][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->unk5A4 != 2 &&  gCurrentPinballGame->unk17 < 4)
        {
            if (gCurrentPinballGame->unk74[j] == 0)
            {
                gCurrentPinballGame->unk74[j] = 40;
                gCurrentPinballGame->unk84[j].x = gCurrentPinballGame->unkC4;
                gCurrentPinballGame->unk84[j].y = gCurrentPinballGame->unkC6 + 16;
                gMain.unk44[45 + j]->available = 1;
            }
        }

        if (gCurrentPinballGame->unk74[j])
        {
            gCurrentPinballGame->unk74[j]--;
            if (gCurrentPinballGame->unk74[j] == 0)
                gMain.unk44[45 + j]->available = 0;
        }
    }
}

void sub_292A0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.unk44[33];
    if (group->available)
    {
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    gMain.unk44[33]->available = 0;
    for (i = 0; i < 4; i++)
        gMain.unk44[45 + i]->available = 0;
}

void sub_29334(void)
{
    if (gCurrentPinballGame->unk68 > 138)
    {
        if (gCurrentPinballGame->unk6C5 == 0 && gCurrentPinballGame->unk625 > 0)
        {
            if (gCurrentPinballGame->unk6C6 + 6 == gCurrentPinballGame->unk625)
            {
                gCurrentPinballGame->unk6C5 = 2;
                gCurrentPinballGame->unk3C = 300000;
            }
            else
            {
                gCurrentPinballGame->unk6C5 = 1;
            }
        }

        gCurrentPinballGame->unk6C6 = gCurrentPinballGame->unk625;
    }

    if (gCurrentPinballGame->unk6C5 == 2)
        sub_25808();
    else if (gCurrentPinballGame->unk6C5 == 1)
        sub_253E0();
}

void sub_293D8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;

    if (gUnknown_086AD436[gCurrentPinballGame->unk6CC][1] > gCurrentPinballGame->unk6CA)
    {
        gCurrentPinballGame->unk6CA++;
    }
    else
    {
        gCurrentPinballGame->unk6CA = 0;
        gCurrentPinballGame->unk6CC++;
    }

    if (gCurrentPinballGame->unk6CC == 2 && gCurrentPinballGame->unk6CA > 3)
    {
        gCurrentPinballGame->unk6C4 = 3;
        gMain.unk44[33]->available = 1;
    }

    if (gCurrentPinballGame->unk6CC > 2)
    {
        DmaCopy16(3, gUnknown_020306D0, (void *)0x050003A0, 0x20);
        DmaCopy16(3, gUnknown_02030760, (void *)0x06010CA0, 0x480);
        sub_28C90();
    }

    group = gMain.unk44[18];
    if (group->available)
    {
        group->baseX = 96 - gCurrentPinballGame->unk58;
        group->baseY = 296 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B55DC[gUnknown_086AD436[gCurrentPinballGame->unk6CC][0]][i*3+0];
            *dst++ = gUnknown_086B55DC[gUnknown_086AD436[gCurrentPinballGame->unk6CC][0]][i*3+1];
            *dst++ = gUnknown_086B55DC[gUnknown_086AD436[gCurrentPinballGame->unk6CC][0]][i*3+2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gMain.unk44[18]->available = 1;
    if (gCurrentPinballGame->unk6CC > 6)
    {
        gCurrentPinballGame->unk17++;
        gMain.unk44[18]->available = 0;
        gCurrentPinballGame->unkE4 = 0;
    }
}

void sub_29624(void)
{
    s16 i;

    gCurrentPinballGame->unk6CC = 0;
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->unk6D3[i] = 13;
}

void sub_29664(void)
{
    s16 i;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->unk5C0[i].x = 0;
        gCurrentPinballGame->unk5C0[i].y = 0;
        gCurrentPinballGame->unk5D8[i].x = 200 - (Random() % 400);
        gCurrentPinballGame->unk5D8[i].y = 80 - (Random() % 550);
        gCurrentPinballGame->unk5B9[i] = 10 + (Random() % 15);
    }

    gCurrentPinballGame->unk606 = 0;
    gMain.unk44[12]->available = 1;
}

void sub_2971C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    struct Vector16 tempVector;

    group = gMain.unk44[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            var0 = gUnknown_086AE1A4[i][gCurrentPinballGame->unk606 / 4];
            gCurrentPinballGame->unk5D8[i].y += gCurrentPinballGame->unk5B9[i];
            if (gCurrentPinballGame->unk5C0[i].y < 14000)
            {
                gCurrentPinballGame->unk5C0[i].x += gCurrentPinballGame->unk5D8[i].x;
                gCurrentPinballGame->unk5C0[i].y += gCurrentPinballGame->unk5D8[i].y;
            }

            tempVector.x = ((gCurrentPinballGame->unk6C8 % 3) * 16 +  96u - gCurrentPinballGame->unk58) + (gCurrentPinballGame->unk5C0[i].x / 100);
            tempVector.y = ((gCurrentPinballGame->unk6C8 / 3) * 16 + 300u - gCurrentPinballGame->unk5A) + (gCurrentPinballGame->unk5C0[i].y / 100);
            if (tempVector.y >= 200)
                tempVector.y = 200;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B53B4[var0][0];
            *dst++ = gUnknown_086B53B4[var0][1];
            *dst++ = gUnknown_086B53B4[var0][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
        }
    }

    if (gCurrentPinballGame->unk606 < 48)
    {
        gCurrentPinballGame->unk606++;
    }
    else
    {
        gCurrentPinballGame->unk6CA = 0x7100;
        gMain.unk44[12]->available = 0;
    }
}

void sub_29924(void)
{
    s16 i;
    const struct Vector16 *var0;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->unk5C0[i].x = ((i % 3) * 16 - 24) * 100;
        gCurrentPinballGame->unk5C0[i].y = ((i / 3) * 16 - 28) * 100;
        gCurrentPinballGame->unk5D8[i].x = gUnknown_086AE2F4[i][0] - ((Random() % 200) - 60);
        gCurrentPinballGame->unk5D8[i].y = gUnknown_086AE2F4[i][1] - ((Random() % 200) - 60);
        gCurrentPinballGame->unk5B9[i] = (Random() % 4) + 1;
    }

    gCurrentPinballGame->unk5C0[0].x = -5600;
    gCurrentPinballGame->unk5C0[0].y = -6000;
    gCurrentPinballGame->unk5B9[0] = 3;
    gCurrentPinballGame->unk5C0[4].x = -4000;
    gCurrentPinballGame->unk5C0[4].y = -4400;
    gCurrentPinballGame->unk5B9[4] = 3;
    gCurrentPinballGame->unk606 = 0;
    gMain.unk44[12]->available = 1;
}
