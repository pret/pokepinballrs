#include "global.h"
#include "main.h"
#include "constants/species.h"

extern const u16 gWildMonLocations[][2][8];

#ifdef NONMATCHING // can't get the loop in the first if condition
void sub_3219C(void)
{
    s16 i;
    u32 rand;
    u16 specialMons[6];

    if (gMain.unk7)
    {

        gMain.unk7 = 0;
        rand = gMain.unk4C + gMain.unk50 + Random();
        rand %= 4;
        i = 0;
        while (i < 4)
        {
            if (gMain.pokedexFlags[BONUS_SPECIES_START + ((i + rand) % 4)] < 4)
                i++;
            else
                break;
        }

        gUnknown_020314E0->catchModeSpecies = BONUS_SPECIES_START + ((i + rand) % 4);
    }
    else
    {
        rand = gMain.unk4C + gMain.unk50 + Random();
        if (gMain.unk8)
            rand %= 50;
        else
            rand %= 100;

        if (gUnknown_02031520.unk8 < 100)
            rand = 1;

        if ((rand == 0 && gUnknown_020314E0->unk5F0 > 4) || gUnknown_020314E0->unk12B)
        {
            s16 numSpecialMons = 0;
            gUnknown_020314E0->catchModeSpecies = 0;
            if (gMain+0x74[SPECIES_AERODACTYL])
            {
                specialMons[numSpecialMons++] = SPECIES_AERODACTYL;
                if (gMain+0x74[SPECIES_AERODACTYL] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_AERODACTYL;
            }

            if (gMain+0x74[SPECIES_CHIKORITA])
            {
                specialMons[numSpecialMons++] = SPECIES_CHIKORITA;
                if (gMain+0x74[SPECIES_CHIKORITA] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_CHIKORITA;
            }

            if (gMain+0x74[SPECIES_TOTODILE])
            {
                specialMons[numSpecialMons++] = SPECIES_TOTODILE;
                if (gMain+0x74[SPECIES_TOTODILE] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_TOTODILE;
            }

            if (gMain+0x74[SPECIES_CYNDAQUIL])
            {
                specialMons[numSpecialMons++] = SPECIES_CYNDAQUIL;
                if (gMain+0x74[SPECIES_CYNDAQUIL] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_CYNDAQUIL;
            }

            if (gMain.unk4 == 0)
            {
                specialMons[numSpecialMons++] = SPECIES_LATIOS;
                if (gMain.pokedexFlags[SPECIES_LATIOS] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_LATIOS;
            }
            else
            {
                specialMons[numSpecialMons++] = SPECIES_LATIAS;
                if (gMain.pokedexFlags[SPECIES_LATIAS] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_LATIAS;
            }

            if (!gUnknown_020314E0->catchModeSpecies)
            {
                rand = gMain.unk4C + gMain.unk50 + Random();
                rand %= numSpecialMons;
                gUnknown_020314E0->catchModeSpecies = specialMons[rand];
            }
        }
        else
        {
            s16 rareMons;
            if (gUnknown_020314E0->unk73D == 3)
                rareMons = 1;
            else
                rareMons = 0;

            rand = gMain.unk4C + gMain.unk50 + Random();
            rand %= gUnknown_020314E0->unk12E;
            for (i = 0; i < 8 && gUnknown_020314E0->unk130[i] <= rand; i++) {}

            gUnknown_020314E0->catchModeSpecies = gWildMonLocations[gUnknown_020314E0->area][rareMons][i];
        }
    }

    gUnknown_020314E0->unk59C = gUnknown_020314E0->catchModeSpecies;
}
#else
NAKED
void sub_3219C(void)
{
    asm_unified("\n\
    push {r4, r5, r6, r7, lr}\n\
    sub sp, #0xc\n\
    ldr r4, _080321C8 @ =gMain\n\
    movs r0, #7\n\
    ldrsb r0, [r4, r0]\n\
    cmp r0, #0\n\
    beq _08032208\n\
    movs r0, #0\n\
    strb r0, [r4, #7]\n\
    bl Random\n\
    ldr r1, [r4, #0x4c]\n\
    ldr r2, [r4, #0x50]\n\
    adds r1, r1, r2\n\
    adds r3, r0, r1\n\
    movs r1, #3\n\
    ands r3, r1\n\
    movs r5, #0\n\
    adds r2, r4, #0\n\
    adds r2, #0x74\n\
    adds r0, r3, #0\n\
    b _080321DE\n\
    .align 2, 0\n\
_080321C8: .4byte gMain\n\
_080321CC:\n\
    lsls r0, r5, #0x10\n\
    movs r4, #0x80\n\
    lsls r4, r4, #9\n\
    adds r0, r0, r4\n\
    lsrs r5, r0, #0x10\n\
    asrs r0, r0, #0x10\n\
    cmp r0, #3\n\
    bgt _080321EA\n\
    adds r0, r0, r3\n\
_080321DE:\n\
    ands r0, r1\n\
    adds r0, #0xc9\n\
    adds r0, r0, r2\n\
    ldrb r0, [r0]\n\
    cmp r0, #3\n\
    bhi _080321CC\n\
_080321EA:\n\
    ldr r0, _08032204 @ =gUnknown_020314E0\n\
    ldr r2, [r0]\n\
    lsls r0, r5, #0x10\n\
    asrs r0, r0, #0x10\n\
    adds r0, r0, r3\n\
    movs r1, #3\n\
    ands r0, r1\n\
    adds r0, #0xc9\n\
    movs r1, #0xb3\n\
    lsls r1, r1, #3\n\
    adds r2, r2, r1\n\
    b _08032452\n\
    .align 2, 0\n\
_08032204: .4byte gUnknown_020314E0\n\
_08032208:\n\
    bl Random\n\
    ldr r1, [r4, #0x4c]\n\
    ldr r2, [r4, #0x50]\n\
    adds r1, r1, r2\n\
    adds r3, r0, r1\n\
    movs r0, #8\n\
    ldrsb r0, [r4, r0]\n\
    cmp r0, #0\n\
    beq _08032222\n\
    adds r0, r3, #0\n\
    movs r1, #0x32\n\
    b _08032226\n\
_08032222:\n\
    adds r0, r3, #0\n\
    movs r1, #0x64\n\
_08032226:\n\
    bl __umodsi3\n\
    adds r3, r0, #0\n\
    ldr r0, _08032338 @ =gUnknown_02031520\n\
    movs r2, #8\n\
    ldrsh r0, [r0, r2]\n\
    cmp r0, #0x63\n\
    bgt _08032238\n\
    movs r3, #1\n\
_08032238:\n\
    ldr r7, _0803233C @ =gUnknown_020314E0\n\
    cmp r3, #0\n\
    bne _0803224C\n\
    ldr r0, [r7]\n\
    movs r3, #0xbe\n\
    lsls r3, r3, #3\n\
    adds r0, r0, r3\n\
    ldrh r0, [r0]\n\
    cmp r0, #4\n\
    bhi _0803225E\n\
_0803224C:\n\
    ldr r1, [r7]\n\
    ldr r4, _08032340 @ =0x0000012B\n\
    adds r0, r1, r4\n\
    ldrb r0, [r0]\n\
    lsls r0, r0, #0x18\n\
    asrs r0, r0, #0x18\n\
    cmp r0, #0\n\
    bne _0803225E\n\
    b _080323C0\n\
_0803225E:\n\
    movs r4, #0\n\
    ldr r0, [r7]\n\
    movs r1, #0xb3\n\
    lsls r1, r1, #3\n\
    adds r3, r0, r1\n\
    strh r4, [r3]\n\
    ldr r1, _08032344 @ =0x0200B134\n\
    adds r0, r1, #0\n\
    adds r0, #0xcc\n\
    ldrb r2, [r0]\n\
    adds r5, r1, #0\n\
    cmp r2, #0\n\
    beq _08032286\n\
    movs r4, #1\n\
    mov r0, sp\n\
    movs r1, #0xcc\n\
    strh r1, [r0]\n\
    cmp r2, #3\n\
    bhi _08032286\n\
    strh r1, [r3]\n\
_08032286:\n\
    adds r0, r5, #0\n\
    adds r0, #0xc9\n\
    ldrb r2, [r0]\n\
    cmp r2, #0\n\
    beq _080322B4\n\
    adds r0, r4, #0\n\
    lsls r1, r0, #0x10\n\
    movs r3, #0x80\n\
    lsls r3, r3, #9\n\
    adds r1, r1, r3\n\
    lsrs r4, r1, #0x10\n\
    lsls r0, r0, #0x10\n\
    asrs r0, r0, #0xf\n\
    add r0, sp\n\
    movs r1, #0xc9\n\
    strh r1, [r0]\n\
    cmp r2, #3\n\
    bhi _080322B4\n\
    ldr r0, [r7]\n\
    movs r2, #0xb3\n\
    lsls r2, r2, #3\n\
    adds r0, r0, r2\n\
    strh r1, [r0]\n\
_080322B4:\n\
    adds r0, r5, #0\n\
    adds r0, #0xcb\n\
    ldrb r2, [r0]\n\
    cmp r2, #0\n\
    beq _080322E2\n\
    adds r0, r4, #0\n\
    lsls r1, r0, #0x10\n\
    movs r3, #0x80\n\
    lsls r3, r3, #9\n\
    adds r1, r1, r3\n\
    lsrs r4, r1, #0x10\n\
    lsls r0, r0, #0x10\n\
    asrs r0, r0, #0xf\n\
    add r0, sp\n\
    movs r1, #0xcb\n\
    strh r1, [r0]\n\
    cmp r2, #3\n\
    bhi _080322E2\n\
    ldr r0, [r7]\n\
    movs r2, #0xb3\n\
    lsls r2, r2, #3\n\
    adds r0, r0, r2\n\
    strh r1, [r0]\n\
_080322E2:\n\
    adds r0, r5, #0\n\
    adds r0, #0xca\n\
    ldrb r2, [r0]\n\
    cmp r2, #0\n\
    beq _08032310\n\
    adds r0, r4, #0\n\
    lsls r1, r0, #0x10\n\
    movs r3, #0x80\n\
    lsls r3, r3, #9\n\
    adds r1, r1, r3\n\
    lsrs r4, r1, #0x10\n\
    lsls r0, r0, #0x10\n\
    asrs r0, r0, #0xf\n\
    add r0, sp\n\
    movs r1, #0xca\n\
    strh r1, [r0]\n\
    cmp r2, #3\n\
    bhi _08032310\n\
    ldr r0, [r7]\n\
    movs r2, #0xb3\n\
    lsls r2, r2, #3\n\
    adds r0, r0, r2\n\
    strh r1, [r0]\n\
_08032310:\n\
    ldr r2, _08032348 @ =gMain\n\
    ldrb r0, [r2, #4]\n\
    cmp r0, #0\n\
    bne _0803234C\n\
    adds r1, r4, #0\n\
    lsls r0, r1, #0x10\n\
    movs r3, #0x80\n\
    lsls r3, r3, #9\n\
    adds r0, r0, r3\n\
    lsrs r4, r0, #0x10\n\
    lsls r1, r1, #0x10\n\
    asrs r1, r1, #0xf\n\
    mov r3, sp\n\
    adds r0, r3, r1\n\
    movs r1, #0xc4\n\
    strh r1, [r0]\n\
    movs r3, #0x9c\n\
    lsls r3, r3, #1\n\
    b _08032366\n\
    .align 2, 0\n\
_08032338: .4byte gUnknown_02031520\n\
_0803233C: .4byte gUnknown_020314E0\n\
_08032340: .4byte 0x0000012B\n\
_08032344: .4byte 0x0200B134\n\
_08032348: .4byte gMain\n\
_0803234C:\n\
    adds r1, r4, #0\n\
    lsls r0, r1, #0x10\n\
    movs r3, #0x80\n\
    lsls r3, r3, #9\n\
    adds r0, r0, r3\n\
    lsrs r4, r0, #0x10\n\
    lsls r1, r1, #0x10\n\
    asrs r1, r1, #0xf\n\
    mov r3, sp\n\
    adds r0, r3, r1\n\
    movs r1, #0xc3\n\
    strh r1, [r0]\n\
    ldr r3, _080323B4 @ =0x00000137\n\
_08032366:\n\
    adds r0, r2, r3\n\
    ldrb r0, [r0]\n\
    cmp r0, #3\n\
    bhi _08032378\n\
    ldr r0, [r7]\n\
    movs r2, #0xb3\n\
    lsls r2, r2, #3\n\
    adds r0, r0, r2\n\
    strh r1, [r0]\n\
_08032378:\n\
    ldr r5, _080323B8 @ =gUnknown_020314E0\n\
    ldr r0, [r5]\n\
    movs r3, #0xb3\n\
    lsls r3, r3, #3\n\
    adds r0, r0, r3\n\
    ldrh r0, [r0]\n\
    cmp r0, #0\n\
    bne _08032454\n\
    bl Random\n\
    ldr r2, _080323BC @ =gMain\n\
    ldr r1, [r2, #0x4c]\n\
    ldr r2, [r2, #0x50]\n\
    adds r1, r1, r2\n\
    adds r3, r0, r1\n\
    lsls r1, r4, #0x10\n\
    asrs r1, r1, #0x10\n\
    adds r0, r3, #0\n\
    bl __umodsi3\n\
    adds r3, r0, #0\n\
    ldr r1, [r5]\n\
    lsls r0, r3, #1\n\
    add r0, sp\n\
    ldrh r0, [r0]\n\
    movs r4, #0xb3\n\
    lsls r4, r4, #3\n\
    adds r1, r1, r4\n\
    strh r0, [r1]\n\
    b _08032454\n\
    .align 2, 0\n\
_080323B4: .4byte 0x00000137\n\
_080323B8: .4byte gUnknown_020314E0\n\
_080323BC: .4byte gMain\n\
_080323C0:\n\
    ldr r2, _08032470 @ =0x0000073D\n\
    adds r0, r1, r2\n\
    ldrb r0, [r0]\n\
    lsls r0, r0, #0x18\n\
    asrs r0, r0, #0x18\n\
    movs r6, #0\n\
    cmp r0, #3\n\
    bne _080323D2\n\
    movs r6, #1\n\
_080323D2:\n\
    bl Random\n\
    ldr r2, _08032474 @ =gMain\n\
    ldr r1, [r2, #0x4c]\n\
    ldr r2, [r2, #0x50]\n\
    adds r1, r1, r2\n\
    adds r3, r0, r1\n\
    ldr r4, [r7]\n\
    movs r1, #0x97\n\
    lsls r1, r1, #1\n\
    adds r0, r4, r1\n\
    movs r2, #0\n\
    ldrsh r1, [r0, r2]\n\
    adds r0, r3, #0\n\
    bl __umodsi3\n\
    adds r3, r0, #0\n\
    movs r5, #0\n\
    movs r1, #0x98\n\
    lsls r1, r1, #1\n\
    adds r0, r4, r1\n\
    movs r2, #0\n\
    ldrsh r0, [r0, r2]\n\
    lsls r6, r6, #0x10\n\
    cmp r0, r3\n\
    bhi _0803242A\n\
    adds r4, r7, #0\n\
    adds r2, r1, #0\n\
_0803240A:\n\
    lsls r0, r5, #0x10\n\
    movs r1, #0x80\n\
    lsls r1, r1, #9\n\
    adds r0, r0, r1\n\
    lsrs r5, r0, #0x10\n\
    asrs r1, r0, #0x10\n\
    cmp r1, #7\n\
    bgt _0803242A\n\
    ldr r0, [r4]\n\
    lsls r1, r1, #1\n\
    adds r0, r0, r2\n\
    adds r0, r0, r1\n\
    movs r1, #0\n\
    ldrsh r0, [r0, r1]\n\
    cmp r0, r3\n\
    bls _0803240A\n\
_0803242A:\n\
    ldr r0, _08032478 @ =gUnknown_020314E0\n\
    ldr r2, [r0]\n\
    ldr r3, _0803247C @ =gWildMonLocations\n\
    lsls r1, r5, #0x10\n\
    asrs r1, r1, #0xf  @ r1 = i * 2\n\
    asrs r0, r6, #0x10\n\
    lsls r0, r0, #4    @ r0 = rareMons * 16\n\
    adds r1, r1, r0    @ r1 = [rareMons][i]\n\
    adds r0, r2, #0\n\
    adds r0, #0x35\n\
    ldrb r0, [r0]\n\
    lsls r0, r0, #0x18\n\
    asrs r0, r0, #0x18\n\
    lsls r0, r0, #5\n\
    adds r1, r1, r0\n\
    adds r1, r1, r3\n\
    ldrh r0, [r1]\n\
    movs r3, #0xb3\n\
    lsls r3, r3, #3\n\
    adds r2, r2, r3\n\
_08032452:\n\
    strh r0, [r2]\n\
_08032454:\n\
    ldr r0, _08032478 @ =gUnknown_020314E0\n\
    ldr r0, [r0]\n\
    movs r4, #0xb3\n\
    lsls r4, r4, #3\n\
    adds r1, r0, r4\n\
    ldrh r1, [r1]\n\
    ldr r2, _08032480 @ =0x0000059C\n\
    adds r0, r0, r2\n\
    strh r1, [r0]\n\
    add sp, #0xc\n\
    pop {r4, r5, r6, r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_08032470: .4byte 0x0000073D\n\
_08032474: .4byte gMain\n\
_08032478: .4byte gUnknown_020314E0\n\
_0803247C: .4byte gWildMonLocations\n\
_08032480: .4byte 0x0000059C");
}
#endif // NONMATCHING
