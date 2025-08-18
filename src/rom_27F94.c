#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern u8 gUnknown_0202C7A0[];
extern u8 gUnknown_020306D0[];
extern u8 gUnknown_02030760[];
extern u8 gUnknown_020315D0[];

extern const u8 gUnknown_0839C78C[];
extern const u8 gUnknown_0839DBAC[];
extern const u8 gUnknown_086ACF80[];
extern const u8 gUnknown_081C0064[];
extern const struct Vector16 gUnknown_086AE124[];
extern const u8 *gMonHatchSpriteGroupGfx[];
extern const u8 *gMonHatchSpriteGroupPals[];

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
    gCurrentPinballGame->unk74 = 0;
    gCurrentPinballGame->unk76 = 10;
    gCurrentPinballGame->unk78 = 20;
    gCurrentPinballGame->unk7A = 30;
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

extern const u8 *gUnknown_086BB6F4[];
extern const u8 *gUnknown_086B15B4[];

extern u8 gUnknown_02030730[];

#ifdef NONMATCHING
void sub_28AE0(void)
{
    s16 i;
    const u8 *sp0[3];
    const u8 *spC[3];
    s16 var0;
    int var1;
    s16 var2;
    const struct PokemonSpecies *speciesInfo;
    const u8 *src0;
    const u8 *src1;
    int catchIndex;

    catchIndex = gSpeciesInfo[gCurrentPinballGame->currentSpecies].catchIndex;
    for (i = 0; i < 3; i++)
    {
        var2 = catchIndex;
        var0 = var2 / 5;
        var1 = var2 % 5;
        sp0[i] = gUnknown_086BB6F4[var0] + (var1 * 3 + i) * 0x480;
        spC[i] = gUnknown_086B15B4[var0] + (var1 + i * 5) * 0x20;
    }

    for (i = 0; i < 3; i++)
    {
        do {
            DmaCopy16(3, sp0[i], &gUnknown_02030760[i * 0x480], 0x480);
            DmaCopy16(3, spC[i], &gUnknown_020306D0[i * 0x20], 0x20);
        } while (0);
    }

    DmaCopy16(3, gUnknown_086B15B4[0] + (15 * 0x20), gUnknown_02030730, 0x20);
}
#else
NAKED
void sub_28AE0(void)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x18\n\
	ldr r2, _08028BD4 @ =gSpeciesInfo\n\
	ldr r0, _08028BD8 @ =gCurrentPinballGame\n\
	ldr r0, [r0]\n\
	movs r1, #0xb3\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r2\n\
	movs r7, #0\n\
	ldr r6, _08028BDC @ =gUnknown_086BB6F4\n\
	add r3, sp, #0xc\n\
	mov r8, r3\n\
	ldr r4, _08028BE0 @ =gUnknown_02030760\n\
	mov sl, r4\n\
	ldr r1, _08028BE4 @ =gUnknown_020306D0\n\
	mov sb, r1\n\
	ldrb r5, [r0, #0x11]\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __divsi3\n\
	adds r4, r0, #0\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __modsi3\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0xe\n\
	adds r6, r4, r6\n\
	lsls r0, r0, #0x10\n\
	asrs r5, r0, #0x10\n\
	ldr r6, [r6]\n\
	mov ip, r6\n\
	ldr r3, _08028BE8 @ =gUnknown_086B15B4\n\
	adds r4, r4, r3\n\
	ldr r6, [r4]\n\
_08028B3A:\n\
	lsls r3, r7, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r2, r3, #2\n\
	mov r0, sp\n\
	adds r4, r0, r2\n\
	lsls r1, r5, #1\n\
	adds r1, r1, r5\n\
	adds r1, r3, r1\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	add r0, ip\n\
	str r0, [r4]\n\
	mov r1, r8\n\
	adds r0, r1, r2\n\
	adds r2, r2, r3\n\
	adds r2, r2, r5\n\
	lsls r2, r2, #5\n\
	adds r2, r6, r2\n\
	str r2, [r0]\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r7, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	cmp r3, #2\n\
	ble _08028B3A\n\
	movs r7, #0\n\
	ldr r3, _08028BEC @ =0x040000D4\n\
_08028B72:\n\
	lsls r1, r7, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r2, r1, #2\n\
	mov r4, sp\n\
	adds r0, r4, r2\n\
	ldr r0, [r0]\n\
	str r0, [r3]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	add r0, sl\n\
	str r0, [r3, #4]\n\
	ldr r0, _08028BF0 @ =0x80000240\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	add r2, r8\n\
	ldr r0, [r2]\n\
	str r0, [r3]\n\
	lsls r0, r1, #5\n\
	add r0, sb\n\
	str r0, [r3, #4]\n\
	ldr r2, _08028BF4 @ =0x80000010\n\
	str r2, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	adds r1, #1\n\
	lsls r1, r1, #0x10\n\
	lsrs r7, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	cmp r1, #2\n\
	ble _08028B72\n\
	ldr r0, _08028BEC @ =0x040000D4\n\
	ldr r3, _08028BE8 @ =gUnknown_086B15B4\n\
	ldr r1, [r3]\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #1\n\
	adds r1, r1, r4\n\
	str r1, [r0]\n\
	ldr r1, _08028BF8 @ =gUnknown_02030730\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	add sp, #0x18\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08028BD4: .4byte gSpeciesInfo\n\
_08028BD8: .4byte gCurrentPinballGame\n\
_08028BDC: .4byte gUnknown_086BB6F4\n\
_08028BE0: .4byte gUnknown_02030760\n\
_08028BE4: .4byte gUnknown_020306D0\n\
_08028BE8: .4byte gUnknown_086B15B4\n\
_08028BEC: .4byte 0x040000D4\n\
_08028BF0: .4byte 0x80000240\n\
_08028BF4: .4byte 0x80000010\n\
_08028BF8: .4byte gUnknown_02030730\n\
    ");
}
#endif

void sub_28BFC(void)
{
    s16 eggIndex;
    const u8 *src0;
    const u8 *src1;

    eggIndex= gSpeciesInfo[gCurrentPinballGame->currentSpecies].eggIndex;
    src0 = gMonHatchSpriteGroupGfx[eggIndex / 6] + (eggIndex % 6) * 0x10E0;
    src1 = gMonHatchSpriteGroupPals[eggIndex / 6] + (eggIndex % 6) * 0x20;
    DmaCopy16(3, src0, gUnknown_0202C7A0, 0x10E0);
    DmaCopy16(3, src1, gUnknown_020315D0, 0x20);
}
