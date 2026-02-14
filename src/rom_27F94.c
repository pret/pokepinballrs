#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern u8 gUnknown_0202C7A0[];
extern u8 gUnknown_020306D0[];
extern u8 gUnknown_020306F0;
extern u8 gUnknown_02030710;
extern u8 gUnknown_02030730;
extern struct Unk02031520 gUnknown_02031520;
extern u8 gUnknown_020315D0[];


extern const u8 gUnknown_0839C78C[];
extern const u8 gUnknown_0839DBAC[];
extern const u8 gUnknown_08137F14;
extern const u8 gUnknown_08138014[];
extern const u8 gUnknown_081428D4[];
extern const u16 gUnknown_081B0FE4[][0x30];
extern const u8 gUnknown_081C0064[];
extern const u8 gUnknown_0844AA0C[][0x480];
extern const u8 gUnknown_084C156C[];
extern const s16 gUnknown_086ACF38[36];
extern const u8 gUnknown_086ACF80[];
extern const s8 gUnknown_086ACFF4[];
extern u16 gUnknown_086AD180[][7];
extern const s16 gUnknown_086AD436[8][2];
extern const struct Vector16 gUnknown_086AE124[];
extern const s16 gUnknown_086AE1A4[][12];
extern const u16 gUnknown_086AE154[][10];
extern const s16 gUnknown_086AE234[][16];
extern const s16 gUnknown_086AE2F4[][2];
extern const s16 gUnknown_086AE30C[];
extern const s16 gUnknown_086AE318[6];
extern const u8 (*gUnknown_086B15B4[])[0x20];
extern const u16 gUnknown_086B263C[68][3][3];
extern const u16 gUnknown_086B4E3E[][3];
extern const u16 gUnknown_086B53B4[][3];
extern const u16 gUnknown_086B55DC[14][18];
extern const u8 (*gUnknown_086BB6F4[])[0x480];

extern struct SongHeader se_unk_84;
extern struct SongHeader se_unk_81;
extern struct SongHeader se_unk_87;
extern struct SongHeader se_unk_9a;




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
        if (gMain.mainState != STATE_GAME_IDLE)
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
        m4aSongNumStart(SE_JIRACHI_MOVE);
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

                    m4aSongNumStart(SE_JIRACHI_MOVE);
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
            MPlayStart(&gMPlayInfo_SE1, &se_unk_84);
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
                gCurrentPinballGame->scoreAddedInFrame = 300000;
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

void sub_29A6C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 index;
    struct Vector16 tempVector;
    s16 sp0[6];
    s16 scale;

    group = gMain.unk44[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            index = gCurrentPinballGame->unk606 / 5;
            sp0[i] = gUnknown_086AE234[i][index];
            if (gCurrentPinballGame->unk606 > 4)
            {
                gCurrentPinballGame->unk5D8[i].y += gCurrentPinballGame->unk5B9[i];
                if (i == 4)
                    gCurrentPinballGame->unk5D8[i].x += gCurrentPinballGame->unk5B9[4] * 4;

                gCurrentPinballGame->unk5C0[i].x += gCurrentPinballGame->unk5D8[i].x;
                gCurrentPinballGame->unk5C0[i].y += gCurrentPinballGame->unk5D8[i].y;
            }

            tempVector.x = (gCurrentPinballGame->unk5C0[i].x / 100) +  96u - gCurrentPinballGame->unk58;
            tempVector.y = (gCurrentPinballGame->unk5C0[i].y / 100) + 304u - gCurrentPinballGame->unk5A;
            if (tempVector.y >= 160)
                tempVector.y = 160;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4E3E[sp0[i]][0];
            *dst++ = gUnknown_086B4E3E[sp0[i]][1];
            *dst++ = gUnknown_086B4E3E[sp0[i]][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
            gOamBuffer[oamSimple->oamId].affineMode = gUnknown_086AE30C[i];
            gOamBuffer[oamSimple->oamId].matrixNum = gUnknown_086AE318[i];
        }
    }

    scale = ((gCurrentPinballGame->unk606 * gCurrentPinballGame->unk606 * 0xD0) / 0x510) + 0x80;
    if (sp0[0] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 2);

    scale = 0x80;
    if (sp0[1] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 3);

    scale = ((gCurrentPinballGame->unk606 * gCurrentPinballGame->unk606 * 0x100) / 0x510) + 0x80;
    if (sp0[3] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 4);

    scale = ((gCurrentPinballGame->unk606 * gCurrentPinballGame->unk606 * 0x1C0) / 0x510) + 0x40;
    if (sp0[4]== 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 5);

    if (gCurrentPinballGame->unk606 < 47)
    {
        gCurrentPinballGame->unk606++;
    }
    else
    {
        gCurrentPinballGame->unk6CA = 0x7100;
        gMain.unk44[12]->available = 0;
    }
}

void sub_29D9C(void)
{
    s16 i;

    gMain.unk44[23]->available = 1;
    gMain.unk44[20]->available = 1;
    gMain.unk44[21]->available = 1;
    gMain.blendControl = 0x1C10;
    gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
    gCurrentPinballGame->unk6E8 = 0;
    gCurrentPinballGame->unk6F2 = 8;
    gCurrentPinballGame->unk6F4 = 0;
    gCurrentPinballGame->unk6E0 = 0;
    if (gCurrentPinballGame->unk6E9 == 25)
        gCurrentPinballGame->unk6E9 = 10;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->unk6F8[i] = gUnknown_086AD180[gCurrentPinballGame->unk6E9][i];
        if (gCurrentPinballGame->unk6F8[i] == 41)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->unk6F8[i] = 42;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->unk6F8[i] = 44;
                    break;
                case 4:
                    gCurrentPinballGame->unk6F8[i] = 45;
                    break;
                }
            }
            else
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->unk6F8[i] = 41;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->unk6F8[i] = 43;
                    break;
                case 4:
                    gCurrentPinballGame->unk6F8[i] = 45;
                    break;
                }
            }
        }
        else if (gCurrentPinballGame->unk6F8[i] == 10)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->unk6F8[i] = gCurrentPinballGame->ballUpgradeType + 10;
            else
                gCurrentPinballGame->unk6F8[i] = 12;
        }
        else if (gCurrentPinballGame->unk6F8[i] == 3)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
            {
                if (gMain.systemFrameCount & 1)
                {
                    if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                        gCurrentPinballGame->unk6F8[i] = gCurrentPinballGame->ballUpgradeType + 10;
                    else
                        gCurrentPinballGame->unk6F8[i] = 12;
                }
                else
                {
                    gCurrentPinballGame->unk6F8[i] = 1;
                }
            }
        }
        else if (gCurrentPinballGame->unk6F8[i] == 9)
        {
            if (gCurrentPinballGame->evolvablePartySize <= 0)
                gCurrentPinballGame->unk6F8[i] = 8;
        }
    }

    gCurrentPinballGame->unk704 = 21;
    if (gCurrentPinballGame->unk6E9 < 25)
        gCurrentPinballGame->unk6E9++;

    gCurrentPinballGame->unk6EA = 5;
    if ((gCurrentPinballGame->unk72 & 0xF0) == 0 && gCurrentPinballGame->area > AREA_WILDERNESS)
        gCurrentPinballGame->unk6EA++;

    gCurrentPinballGame->unk6EB = 1;
    gCurrentPinballGame->unk6EC[0] = gCurrentPinballGame->unk6F8[0];
    gCurrentPinballGame->unk6EC[1] = gCurrentPinballGame->unk6F8[1];
    sub_1C7F4(2, 0);
    sub_1C7F4(2, 1);
}

void sub_2A054(void)
{
    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        if (gCurrentPinballGame->unk6E8 == 0)
        {
            if ((gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON)) && gCurrentPinballGame->unk37C)
            {
                gCurrentPinballGame->unk378 = 2;
                if (gCurrentPinballGame->unk6E0 < 17)
                    gCurrentPinballGame->unk6EC[1] = gCurrentPinballGame->unk6EC[0];

                gCurrentPinballGame->unk6E8 = 1;
                gCurrentPinballGame->unk6F2 = 40;
                gCurrentPinballGame->unk6F0 = 39;
            }
        }
    }

    if (gCurrentPinballGame->unk6E8 == 0)
    {
        gCurrentPinballGame->unk6C4 = 1;
        gCurrentPinballGame->unk6F0++;
        if (gCurrentPinballGame->unk6F4)
        {
            gCurrentPinballGame->unk6F4--;
            if (gCurrentPinballGame->unk6F4 == 0)
            {
                gCurrentPinballGame->unk6E8 = 1;
            }
            else
            {
                if (gCurrentPinballGame->unk6F0 == gCurrentPinballGame->unk6F2)
                {
                    gCurrentPinballGame->unk6F2 = 40 - (gCurrentPinballGame->unk6F4 * 34) / gCurrentPinballGame->unk6F6;
                    gCurrentPinballGame->unk6F0 = 0;
                }
            }
        }
        else if (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON))
        {
            gCurrentPinballGame->unk6F4 = (Random() % 200) + 100;
            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                if (gCurrentPinballGame->unk378 == 1)
                {
                    gCurrentPinballGame->unk6F4 = 320;
                    gCurrentPinballGame->unk37C = 1;
                }
            }

            gCurrentPinballGame->unk6F6 = gCurrentPinballGame->unk6F4;
        }

        gCurrentPinballGame->unk6F0 %= gCurrentPinballGame->unk6F2;
        gCurrentPinballGame->unk6E0 = (gCurrentPinballGame->unk6F0 * 32) / gCurrentPinballGame->unk6F2;
    }
    else
    {
        gCurrentPinballGame->unk6F0++;
        gCurrentPinballGame->unk6F0 %= gCurrentPinballGame->unk6F2;
        gCurrentPinballGame->unk6E0 = (gCurrentPinballGame->unk6F0 * 32) / gCurrentPinballGame->unk6F2;
        if (gCurrentPinballGame->unk6F0 == 0)
        {
            gCurrentPinballGame->unk28 = 140;
            gMain.unk44[23]->available = 0;
            gMain.unk44[20]->available = 0;
            gMain.unk44[21]->available = 0;
            gCurrentPinballGame->unk6E0 = 0;
            gCurrentPinballGame->unk6C4 = 0;
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->unk6DD = 1;
            gCurrentPinballGame->unk6DE = 0;
        }
    }

    if (gCurrentPinballGame->unk6F0 == 0)
    {
        gCurrentPinballGame->unk6EC[0] = gCurrentPinballGame->unk6EC[1];
        sub_1C7F4(2, 0);
        gCurrentPinballGame->unk6DC = gCurrentPinballGame->unk6EC[0];
    }

    if (gCurrentPinballGame->unk6F0 == 1)
    {
        if (gCurrentPinballGame->unk6EB < gCurrentPinballGame->unk6EA)
            gCurrentPinballGame->unk6EB++;
        else
            gCurrentPinballGame->unk6EB = 0;

        gCurrentPinballGame->unk6EC[1] = gCurrentPinballGame->unk6F8[gCurrentPinballGame->unk6EB];
        sub_1C7F4(2, 1);
        MPlayStart(&gMPlayInfo_SE1, &se_unk_81);
    }
}

void sub_2A354(void)
{
    if (gCurrentPinballGame->unk6DE < 180)
    {
        if (gCurrentPinballGame->unk6DE == 4)
            m4aSongNumStart(MUS_UNKNOWN_0x14);

        if (gCurrentPinballGame->unk6DC == 3)
        {
            if (gCurrentPinballGame->unk6DE == 120)
                m4aSongNumStart(SE_UNKNOWN_0xB2);
        }

        gCurrentPinballGame->unk6DE++;
        if (gCurrentPinballGame->unk6DE < 80)
            sub_1C7F4(8, 0);
    }

    switch (gCurrentPinballGame->unk6DC)
    {
    case 0:
    case 1:
    case 2:
        gCurrentPinballGame->unk724 = (gCurrentPinballGame->unk6DC + 1) * 1800;
        break;
    case 3:
        if (gCurrentPinballGame->unk25 == 3)
        {
            if (gCurrentPinballGame->unk6DE > 124)
            {
                if (gCurrentPinballGame->unk1AE < 100)
                {
                    gCurrentPinballGame->unk1AE++;
                    gCurrentPinballGame->unk6DE = 124;
                }
            }

            if (gCurrentPinballGame->unk6DE == 4)
            {
                gCurrentPinballGame->unk1C6 = 168;
                gCurrentPinballGame->unk1C8 = 168;
                gCurrentPinballGame->unk1CC = 13;
                gCurrentPinballGame->unk1CA = 13;
                gCurrentPinballGame->unk1D0 = 0;
                gCurrentPinballGame->unk1D6 = 120;
                gCurrentPinballGame->unk1DC = 60;
                DmaCopy16(3, gUnknown_084C156C, (void *)0x06010600, 0x180);
                gCurrentPinballGame->outLanePikaPosition = 2;
                gMain.unk44[41]->available = 0;
                gCurrentPinballGame->unk1C0 = 1;
            }
        }
        else
        {
            if (gCurrentPinballGame->unk6DE == 120)
            {
                gMain.unkF |= 1;
                gCurrentPinballGame->unkEA = 0;
                gCurrentPinballGame->unkEC = 250;
                gCurrentPinballGame->unkE8 = 272;
                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unkEE = 2;
                gCurrentPinballGame->unkF2 = 0;
                gCurrentPinballGame->unkFA = 1;
                gCurrentPinballGame->unkFB = 0;
                gCurrentPinballGame->unk1BE = 1;
                gCurrentPinballGame->unk1C0 = 800;
                gCurrentPinballGame->outLanePikaPosition = 0;
                gCurrentPinballGame->unk1C6 = 168;
                gCurrentPinballGame->unk1C8 = 168;
                gCurrentPinballGame->unk1CC = 13;
                gCurrentPinballGame->unk1CA = 13;
                gCurrentPinballGame->unk1D0 = 0;
                gCurrentPinballGame->unk1D6 = 120;
                gCurrentPinballGame->unk1DC = 60;
            }

            if (gCurrentPinballGame->unk1C0)
            {
                if (gCurrentPinballGame->unk6DE >= 176)
                    gCurrentPinballGame->unk6DE = 176;
            }
        }
        break;
    case 4:
        if (gCurrentPinballGame->unk6DE == 130)
            gCurrentPinballGame->unk286 = 90;
        break;
    case 5:
        if (gCurrentPinballGame->unk6DE == 95)
        {
            gCurrentPinballGame->unk6DE = 12;
            gCurrentPinballGame->unk6DC = (gMain.systemFrameCount % 3) + 33;
        }
        break;
    case 6:
        if (gCurrentPinballGame->unk6DE == 95)
        {
            gCurrentPinballGame->unk6DE = 12;
            if (gCurrentPinballGame->unk6E9 < 6)
                gCurrentPinballGame->unk6DC = (gMain.systemFrameCount % 3) + 24;
            else if ((s32) gCurrentPinballGame->unk6E9 <= 0xA)
                gCurrentPinballGame->unk6DC = (gMain.systemFrameCount % 5) + 24;
            else if (gCurrentPinballGame->unk6E9 % 5 == 0)
                gCurrentPinballGame->unk6DC = (gMain.systemFrameCount % 5) + 28;
            else
                gCurrentPinballGame->unk6DC = (gMain.systemFrameCount % 7) + 24;
        }
        break;
    case 7:
        if (gCurrentPinballGame->unk6DE == 95)
        {
            gCurrentPinballGame->unk6DE = 12;
            if (gCurrentPinballGame->unk6E9 < 10)
                gCurrentPinballGame->unk6DC = (gMain.systemFrameCount % 3) + 36;
            else
                gCurrentPinballGame->unk6DC = (gMain.systemFrameCount % 5) + 36;
        }
        break;
    case 8:
        if (gCurrentPinballGame->unk6DE == 150)
        {
            sub_19B64(4);
            gCurrentPinballGame->unk28 = 100;
        }
        break;
    case 9:
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->unk6DE == 149)
            {
                gCurrentPinballGame->unk1BA = 180;
                gCurrentPinballGame->unk6C4 = 3;
            }

            if (gCurrentPinballGame->unk6DE == 150)
            {
                gCurrentPinballGame->unk6DE = 149;
                gCurrentPinballGame->unk1A5 = 1;
                sub_1B140(1);
                gCurrentPinballGame->unk36A[0] = 3;
                gCurrentPinballGame->unk36A[1] = 3;
            }

            if (gCurrentPinballGame->unk6DE == 170)
            {
                gCurrentPinballGame->unk2F0 = 0;
                gCurrentPinballGame->unk1A5 = 0;
                sub_19B64(6);
            }
        }
        break;
    case 10:
    case 11:
    case 12:
        if (gCurrentPinballGame->unk6DE == 130)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_87);
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 13:
        if (gCurrentPinballGame->unk6DE == 130)
        {
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_87);
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 17:
    case 18:
    case 19:
        if (gCurrentPinballGame->unk6DE == 130)
        {
            gCurrentPinballGame->unk72B = 1;
            gCurrentPinballGame->unk194 = (gCurrentPinballGame->unk6DC - 17) * 20 + 10;
            gCurrentPinballGame->unk196 = 0;
        }

        if (gCurrentPinballGame->unk6DE == 140)
            gCurrentPinballGame->unk6DE = 139;
        break;
    case 20:
        if (gCurrentPinballGame->unk6DE == 130)
            gCurrentPinballGame->timerBonus = 1800;
        break;
    case 21:
        if (gCurrentPinballGame->unk6DE == 150)
        {
            gCurrentPinballGame->unk28 = 100;
            gCurrentPinballGame->unk72 = 15;
            sub_19B64(8);
        }
        break;
    case 22:
        if (gCurrentPinballGame->unk6DE == 150 && gCurrentPinballGame->unk2A4 == 0)
        {
            gCurrentPinballGame->unk174 = 0;
            gCurrentPinballGame->unk16F = 1;
            gCurrentPinballGame->unk162 = 1;
        }
        break;
    case 23:
        if (gCurrentPinballGame->unk6DE == 150)
        {
            gCurrentPinballGame->unk308 = 100;
            gCurrentPinballGame->unk30C = 1800;
            gCurrentPinballGame->unk306 = 1;
        }
        break;
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->unk6DE = 81;

        if (gCurrentPinballGame->unk6DE == 70)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->unk6DC - 23) * 1000000;
        }
        break;
    case 33:
        if (gCurrentPinballGame->unk6DE == 70)
        {
            m4aSongNumStart(SE_UNKNOWN_0x91);
            gCurrentPinballGame->scoreAddedInFrame = 100;
        }
        break;
    case 34:
        if (gCurrentPinballGame->unk6DE == 70) {
            m4aSongNumStart(SE_UNKNOWN_0x91);
            gCurrentPinballGame->scoreAddedInFrame = 500;
        }
        break;
    case 35:
        if (gCurrentPinballGame->unk6DE == 70) {
            m4aSongNumStart(SE_UNKNOWN_0x91);
            gCurrentPinballGame->scoreAddedInFrame = 900;
        }
        break;
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
        if (gCurrentPinballGame->unk6DE == 70)
        {
            gCurrentPinballGame->unk70E += gCurrentPinballGame->unk6DC + 221;
            if (gCurrentPinballGame->unk70E > 99)
                gCurrentPinballGame->unk70E = 99;
        }
        break;
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
        if (gCurrentPinballGame->unk6DE == 150)
            sub_19B64(3);
        break;
    }
}

void sub_2AADC(void)
{
    s16 i;
    s16 j;
    s16 temp_r0;
    s16 temp_r3;
    struct Vector16 tempVector;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    if (gCurrentPinballGame->unk1E != 0)
        return;

    // Handle counter increment logic
    if (gCurrentPinballGame->unk5A6 < gUnknown_086ACF38[gCurrentPinballGame->unk5A8])
    {
        gCurrentPinballGame->unk5A6++;

        if (gCurrentPinballGame->unk5A6 >= gUnknown_086ACF38[gCurrentPinballGame->unk5A8])
        {
            gCurrentPinballGame->unk5A6 = 0;

            if (gCurrentPinballGame->unk5A8 <= 34)
                gCurrentPinballGame->unk5A8++;
        }
    }

    switch (gCurrentPinballGame->unk5A8)
    {
    case 0:
        gMain.blendControl = 0xCE;

        if (gMain.selectedField < MAIN_FIELD_COUNT && (gCurrentPinballGame->unk13 == 4 || gCurrentPinballGame->unk13 == 8))
            gCurrentPinballGame->unk294 = 1;

        gCurrentPinballGame->unk1F = 1;

        gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
        gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        gCurrentPinballGame->unkE4 = 9;
        DmaCopy16(3, gUnknown_081428D4, 0x06015800, 0x1C00);
        DmaCopy16(3, &gUnknown_08138014[gCurrentPinballGame->ballUpgradeType << 9], 0x060164C0, 0x80);
        DmaCopy16(3, &gUnknown_08138014[((gCurrentPinballGame->ballUpgradeType * 8 + 4) << 6)], 0x06016760, 0x80);

        gCurrentPinballGame->unk5F7 = 1;

        if (gCurrentPinballGame->unk5A6 == 1)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->unk71 = 1;
        }

        break;

    case 1:
        if (gCurrentPinballGame->unk13 == 4)
        {
            gCurrentPinballGame->unk720 = 0;
            gCurrentPinballGame->unk71D[0] = 2;
            gCurrentPinballGame->unk71D[1] = 2;
            gCurrentPinballGame->unk71D[2] = 2;
        }

        gCurrentPinballGame->ball->oamPriority = 0;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        if (gCurrentPinballGame->unk5A6 == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_9a);

        break;

    case 2:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gUnknown_08137E14[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gMain.blendBrightness = 4;

        if (gCurrentPinballGame->unk5A6 > 1)
        {
            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->unk6F = 1;
            gCurrentPinballGame->unk70 = 1;
        }
        break;

    case 3:
        gMain.blendBrightness = 7;

        if (gCurrentPinballGame->unk5A6 > 1)
        {
            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[2], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gUnknown_02031520.unk14.unk2C[2] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gUnknown_02031520.unk14.unk2C[2] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[2] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->unk6F = 2;
            gCurrentPinballGame->unk70 = 1;
        }

        DmaCopy16(3, &gUnknown_08137F14, 0x05000220, 0x20);
        break;

    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        temp_r3 = gCurrentPinballGame->unk5A8 - 4;

        if (temp_r3 == 0 || temp_r3 == 6)
        {
            if (gMain.selectedField <= 3 &&
                (
                    (gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 9) ||
                    (gCurrentPinballGame->unk13 == 8 && gCurrentPinballGame->unk17 == 3)
                ))
            {
                DmaCopy16(3, &gUnknown_02030710, 0x050003A0, 0x20);
            }

            DmaCopy16(3, &gUnknown_08137F14, 0x05000220, 0x20);
            gMain.blendBrightness = 6;
        }
        else
        {
            //TODO: fakematch; unused i. Here for the +4 to parse correctly;
            DmaCopy16(3, gUnknown_08137E14[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
            gMain.blendBrightness = 7;
        }

        spriteGroup = gMain.unk44[3];

        if (spriteGroup->available != 0)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            if (gCurrentPinballGame->unk13 == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        gMain.unk44[3]->available = 1;

        if (gCurrentPinballGame->unk5A8 == 10 && gCurrentPinballGame->unk5A6 == 3)
            gMain.unk44[3]->available = 0;
        break;
    case 11:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gUnknown_08137E14[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);

        tempVector.x = (gCurrentPinballGame->unk288 << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->unk28A << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->unk5AC = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);

        gCurrentPinballGame->unk5AC = Sqrt(gCurrentPinballGame->unk5AC * 4) / 2;
        gCurrentPinballGame->unk5B0 = ArcTan2(-tempVector.x, tempVector.y);

        if (gMain.selectedField > 3)
        {
            gCurrentPinballGame->unk389 = 0;
        }
        else if ((gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 9) ||
                 (gCurrentPinballGame->unk13 == 8 && gCurrentPinballGame->unk17 == 3))
        {
            DmaCopy16(3, &gUnknown_020306D0, 0x050003A0, 0x20);
        }

        for (i = 0; i < 4; i++)
        {
            gCurrentPinballGame->ball->prevPositionsQ0[i].x = gCurrentPinballGame->ball->positionQ0.x;
            gCurrentPinballGame->ball->prevPositionsQ0[i].y = gCurrentPinballGame->ball->positionQ0.y;
        }
        break;
    case 12:
        temp_r0 = 99 - gCurrentPinballGame->unk5A6;
        gCurrentPinballGame->unk5B0 -= (temp_r0 * 0x2000) / 100 - 0x2000;
        gCurrentPinballGame->ball->unkA -= 0x2000;

        temp_r0 -= 20;

        if (temp_r0 < 0)
        {
            temp_r0 = 0;
            gCurrentPinballGame->ball->unk0 = 0;
        }

        {
            s32 var_3 = (gCurrentPinballGame->unk5AC * temp_r0) / 80;

            gCurrentPinballGame->ball->positionQ8.x =
                (gCurrentPinballGame->unk288 << 8) + Cos(gCurrentPinballGame->unk5B0) * var_3 / 20000;
            gCurrentPinballGame->ball->positionQ8.y =
                (gCurrentPinballGame->unk28A << 8) - Sin(gCurrentPinballGame->unk5B0) * var_3 / 20000;
        }
        break;

    case 13:
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->unk71 = 0;
        gCurrentPinballGame->ball->unkA -= 0x2000;
        break;

    case 14:
        DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->unkA -= 0x2000;
        break;

    case 15:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gUnknown_08137E14[i= gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gCurrentPinballGame->ball->unkA -= 0x2000;
        break;

    case 16:
        if (gCurrentPinballGame->unk5A6 == 0)
            m4aSongNumStart(0x9B);

        DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->unkA = 0x7000;
        break;

    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
        spriteGroup = gMain.unk44[3];

        if (spriteGroup->available != 0)
        {
            gCurrentPinballGame->ball->unk0 = 1;
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;
            temp_r3 = gUnknown_086ACFF4[gCurrentPinballGame->unk5A8 - 17] + 7;

            if (gCurrentPinballGame->unk13 == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }
        gMain.unk44[3]->available = 1;

        if (gCurrentPinballGame->unk5A8 == 18 || gCurrentPinballGame->unk5A8 == 20 || gCurrentPinballGame->unk5A8 == 21)
        {
            gCurrentPinballGame->unk5A9 = 200;

            if (gMain.selectedField > 3)
                gCurrentPinballGame->unk389 = 1;
            else if ((gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 9) ||
                    (gCurrentPinballGame->unk13 == 8 && gCurrentPinballGame->unk17 == 3))
                DmaCopy16(3, &gUnknown_020306F0, 0x050003A0, 0x20);
        }
        else if (gCurrentPinballGame->unk5A8 == 19 || gCurrentPinballGame->unk5A8 == 22)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->unk389 = 3;
            else if ((gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 9) ||
                    (gCurrentPinballGame->unk13 == 8 && gCurrentPinballGame->unk17 == 3))
                DmaCopy16(3, &gUnknown_02030730, 0x050003A0, 0x20);
        }

        if (gCurrentPinballGame->unk5A8 == 23)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->unk389 = 10;
            else
            {
                if (gCurrentPinballGame->unk13 == 4 && gCurrentPinballGame->unk17 == 9)
                {
                    sub_28E2C();
                    gCurrentPinballGame->unk5F2 = 0;
                    m4aMPlayAllStop();
                }

                if (gCurrentPinballGame->unk13 == 8 && gCurrentPinballGame->unk17 == 3)
                {
                    sub_292A0();
                    gCurrentPinballGame->unk5F2 = 0;
                    m4aMPlayAllStop();
                }
            }
        }

        if (gCurrentPinballGame->unk5A8 == 28)
        {
            if (gCurrentPinballGame->unk5A6 == 0)
            {
                m4aMPlayAllStop();
                sub_11B0(8);
            }

            if (gCurrentPinballGame->unk5A6 == 2)
                m4aSongNumStart(0x9C);
        }
        break;

    case 26:
        spriteGroup = gMain.unk44[3];

        if (spriteGroup->available != 0)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            temp_r3 = gUnknown_086ACFF4[gCurrentPinballGame->unk5A8 - 17] + 7;

            if (gCurrentPinballGame->unk13 == 5)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 0];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 1];
                    *dst++ = gUnknown_081B0FE4[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        break;

    case 29:
        gMain.blendBrightness = 4;
        DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);

        spriteGroup = gMain.unk44[3];

        if (spriteGroup->available != 0)
        {
            for (i = 0; i <= 21; i++)
            {
                oamSimple = &spriteGroup->oam[i];
                gOamBuffer[oamSimple->oamId].y = 190;
            }
        }

        gMain.unk44[3]->available = 0;
        gCurrentPinballGame->ball->unk0 = 0;
        gCurrentPinballGame->ball->velocity.y = -256;
        gCurrentPinballGame->ball->velocity.x = 40;
        gCurrentPinballGame->ball->unk6 = 256;

        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->unkE4 = 0;

        break;

    case 30:
        if (gCurrentPinballGame->unk5A6 <= 7)
        {
            if (gCurrentPinballGame->unk5A6 <= 3)
            {
                if (gCurrentPinballGame->unk5A6 == 0)
                {
                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x140, 0x05000340, 0x60);
                    gCurrentPinballGame->unk6F = 1;
                    gCurrentPinballGame->unk70 = 1;
                }
            }
            else
            {
                gMain.blendBrightness = 0;

                if (gCurrentPinballGame->unk5A6 > 4)
                {
                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x140, 0x05000340, 0x60);

                    gCurrentPinballGame->unk6F = 0;
                    gCurrentPinballGame->unk70 = 1;
                }
            }
        }

        if (gCurrentPinballGame->unk13 == 5 || gCurrentPinballGame->unk13 == 8)
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += ((118 << 8) - gCurrentPinballGame->ball->positionQ8.x) / 30;

            if (gCurrentPinballGame->ball->positionQ8.y >= 314 << 8)
            {
                if (gCurrentPinballGame->ball->velocity.y > 49)
                    m4aSongNumStart(0x9D);

                if (gCurrentPinballGame->ball->velocity.y <= -50)
                    m4aSongNumStart(0x9D);

                gCurrentPinballGame->ball->positionQ8.y = 314 << 8;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * -45) / 100;
                gCurrentPinballGame->ball->unk6 = (gCurrentPinballGame->ball->unk6 * 7) / 10;

                if (gCurrentPinballGame->ball->unk6 > 0)
                    gCurrentPinballGame->ball->unk6 = -gCurrentPinballGame->ball->unk6;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }

            {
                s16 var_4 = gCurrentPinballGame->ball->velocity.y;

                if (var_4 < 0)
                    var_4 = -var_4;

                if (var_4 > 256)
                    gCurrentPinballGame->unk5A6--;
            }
        }
        else
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;

            if (gCurrentPinballGame->ball->positionQ8.y >= (gCurrentPinballGame->unk28A + 50) << 8)
            {
                m4aSongNumStart(0x9D);
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unk28A + 50) << 8;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * -45) / 100;
                gCurrentPinballGame->ball->unk6 = (gCurrentPinballGame->ball->unk6 * 7) / 10;

                if (gCurrentPinballGame->ball->unk6 > 0)
                    gCurrentPinballGame->ball->unk6 = -gCurrentPinballGame->ball->unk6;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }
        }

        gCurrentPinballGame->unk5B0 = 0;
        break;

    case 31:
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->unk6 = 0;
        break;

    case 32:
        temp_r0 = 237 - gCurrentPinballGame->unk5A6;

        if (temp_r0 <= 191)
        {
            if (temp_r0 > 183)
            {
                if (temp_r0 == 185)
                    sub_11B0(6);

                if (temp_r0 == 184)
                    m4aSongNumStart(158);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->unkA -= 0x400;
            }
            else if (temp_r0 > 175)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->unkA += 0x400;
            }
            else if (temp_r0 > 167)
            {
                if (temp_r0 == 169)
                    sub_11B0(6);

                if (temp_r0 == 168)
                    m4aSongNumStart(0x9E);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->unkA -= 0x400;
            }
            else if (temp_r0 > 159)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->unkA += 0x400;
            }
            else if (temp_r0 <= 123)
            {
                if (temp_r0 > 115)
                {
                    if (temp_r0 == 117)
                        sub_11B0(6);

                    if (temp_r0 == 116)
                        m4aSongNumStart(0x9E);

                    gCurrentPinballGame->ball->positionQ8.x -= 96;
                    gCurrentPinballGame->ball->unkA -= 0x400;
                }
                else if (temp_r0 > 107)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->unkA += 0x400;
                }
                else if (temp_r0 > 99)
                {
                    if (temp_r0 == 101)
                        sub_11B0(6);

                    if (temp_r0 == 100)
                        m4aSongNumStart(0x9E);

                    gCurrentPinballGame->ball->positionQ8.x -= 96;
                    gCurrentPinballGame->ball->unkA -= 0x400;
                }
                else if (temp_r0 > 91)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->unkA += 0x400;
                }
            }
        }

        if (temp_r0 == 0)
        {
            m4aSongNumStart(0x11);
            sub_2312C();
        }

        break;

    case 33:
        gCurrentPinballGame->ball->oamPriority = 3;
        sub_23300();

        if (gCurrentPinballGame->unk5A6 <= 229 && gCurrentPinballGame->unk210 == 150)
            gCurrentPinballGame->unk210--;

        if (gCurrentPinballGame->unk5A6 == 270 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            sub_1C7F4(0, 0);
            gCurrentPinballGame->unk6C4 = 0;
        }

        if (gCurrentPinballGame->unk5A6 <= 29)
        {
            gMain.unk2C = 1;
            temp_r0 = gCurrentPinballGame->unk5A6;
            gCurrentPinballGame->unk298 = temp_r0;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gUnknown_03005C00[(i + 15) * 32 + j] = 0xC100;
                }
            }

            DmaCopy16(3, &gUnknown_03005C00, 0x06002000, 0x800);
        }

        if (gCurrentPinballGame->unk5A6 >= 240 && gCurrentPinballGame->unk5A6 <= 269)
        {
            temp_r0 = gCurrentPinballGame->unk5A6 - 240;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gUnknown_03005C00[(i + 15) * 32 + j] = 511;
                }
            }

            DmaCopy16(3, &gUnknown_03005C00, 0x06002000, 0x800);

            if (gCurrentPinballGame->unk5A6 == 269)
            {
                gMain.unk2C = 0;

                if (gMain.selectedField < MAIN_FIELD_COUNT)
                {
                    gMain.blendControl = 0;
                    gMain.blendBrightness = 0;
                    gMain.blendAlpha = 0;
                }
            }
        }
        
        if (gCurrentPinballGame->scoreCounterAnimationEnabled) 
            gCurrentPinballGame->unk5A6 = 181;

        if (gCurrentPinballGame->unk5A6 == 180)
        {
            if (gCurrentPinballGame->unk13 == 4 || gCurrentPinballGame->unk13 == 8)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                
                switch (gCurrentPinballGame->currentSpecies) 
                {
                case 59:
                case 114:
                case 132:
                case 134:
                case 139:
                case 141:
                case 144:
                case 151:
                case 160:
                    gCurrentPinballGame->scoreAddStepSize = 80000;
                    gCurrentPinballGame->scoreAddedInFrame = 5000000;
                    break;
                case 195:
                case 196:
                    gCurrentPinballGame->scoreAddStepSize = 140000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                    break;
                default:
                    gCurrentPinballGame->scoreAddedInFrame = 1000000;
                    break;
                }
            }

            if (gCurrentPinballGame->unk13 == 5)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            
                if (gCurrentPinballGame->currentSpecies == SPECIES_PICHU)
                {
                    gCurrentPinballGame->scoreAddStepSize = 140000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                }
                else
                    gCurrentPinballGame->scoreAddedInFrame = 3000000;
            }

            if (gMain.selectedField > MAIN_FIELD_COUNT)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                
                if (gMain.selectedField == FIELD_RAYQUAZA)
                {
                    gCurrentPinballGame->scoreAddStepSize = 400000;
                    gCurrentPinballGame->scoreAddedInFrame = 30000000;
                }
                else
                {
                    gCurrentPinballGame->scoreAddStepSize = 400000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                }
            }
        }

        break;

    case 34:
        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->ball->oamPriority = 3;
        gCurrentPinballGame->unk5A4 = 0;
        gCurrentPinballGame->unk5A6 = 0;
        gCurrentPinballGame->unk5A8 = 0;

        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->unk1F = 0;
            gCurrentPinballGame->ball->velocity.y = -10;
            gCurrentPinballGame->ball->velocity.x = 20;

            for (i = 0; i <= 2; i++)
            {
                if (i < gCurrentPinballGame->unk723)
                    gCurrentPinballGame->unk71D[i] = 1;
                else
                    gCurrentPinballGame->unk71D[i] = 0;
            }

            if (gCurrentPinballGame->unk723 <= 2)
            {
                gCurrentPinballGame->unk721 = gCurrentPinballGame->unk723;
                gCurrentPinballGame->unk722 = gCurrentPinballGame->unk723;
                gCurrentPinballGame->unk71D[gCurrentPinballGame->unk721] = 1;
                gCurrentPinballGame->unk720 = 120;
                gCurrentPinballGame->unk723++;
            }

            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->unk286 = 90;

            if (gCurrentPinballGame->unk62A <= 98)
                gCurrentPinballGame->unk62A++;

            if (gCurrentPinballGame->unk13 == 4)
                gCurrentPinballGame->unk17 = 10;

            if (gCurrentPinballGame->unk13 == 8)
                gCurrentPinballGame->unk17 = 5;

            if (gCurrentPinballGame->unk13 == 5)
                gCurrentPinballGame->unk17 = 6;

        }
        else
        {
            gCurrentPinballGame->unk1F = 1;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->unk6C4 = 3;
            gCurrentPinballGame->unk13 = 4;
            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->unk286 = 91;
        }
        sub_31CF8(0);
        break;
    }

    gCurrentPinballGame->ball->prevPositionsQ0[0].x = gCurrentPinballGame->ball->positionQ0.x;
    gCurrentPinballGame->ball->prevPositionsQ0[0].y = gCurrentPinballGame->ball->positionQ0.y;

    for (i = 2; i >= 0; i--)
    {
        gCurrentPinballGame->ball->prevPositionsQ0[i + 1].x = gCurrentPinballGame->ball->prevPositionsQ0[i].x;
        gCurrentPinballGame->ball->prevPositionsQ0[i + 1].y = gCurrentPinballGame->ball->prevPositionsQ0[i].y;
    }
}
