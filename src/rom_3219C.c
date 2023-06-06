#include "global.h"
#include "main.h"
#include "constants/species.h"

extern const u16 gWildMonLocations[][2][8];

static inline u32 GetTimeAdjustedRandom()
{
    return Random() + (gMain.systemFrameCount + gMain.fieldFrameCount);
}

void sub_3219C(void)
{
    s16 i;
    u32 rand;
    u16 specialMons[6];

    if (gMain.unk7)
    {
        gMain.unk7 = 0;
        rand = GetTimeAdjustedRandom();
        rand %= 4;
        for (i = 0; i < 4; i++)
        {
            if (gMain_saveData.pokedexFlags[BONUS_SPECIES_START + ((i + rand) % 4)] < 4)
                break;
            else
                continue;
        }

        gUnknown_020314E0->catchModeSpecies = BONUS_SPECIES_START + ((i + rand) % 4);
    }
    else
    {
        rand = GetTimeAdjustedRandom();
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
            if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL])
            {
                specialMons[numSpecialMons++] = SPECIES_AERODACTYL;
                if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_AERODACTYL;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA])
            {
                specialMons[numSpecialMons++] = SPECIES_CHIKORITA;
                if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_CHIKORITA;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE])
            {
                specialMons[numSpecialMons++] = SPECIES_TOTODILE;
                if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_TOTODILE;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL])
            {
                specialMons[numSpecialMons++] = SPECIES_CYNDAQUIL;
                if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_CYNDAQUIL;
            }

            if (gMain.unk4 == 0)
            {
                specialMons[numSpecialMons++] = SPECIES_LATIOS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIOS] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_LATIOS;
            }
            else
            {
                specialMons[numSpecialMons++] = SPECIES_LATIAS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIAS] < 4)
                    gUnknown_020314E0->catchModeSpecies = SPECIES_LATIAS;
            }

            if (!gUnknown_020314E0->catchModeSpecies)
            {
                rand = GetTimeAdjustedRandom();
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

            rand = GetTimeAdjustedRandom();
            rand %= gUnknown_020314E0->unk12E;
            for (i = 0; i < 8 && gUnknown_020314E0->unk130[i] <= rand; i++) {}

            gUnknown_020314E0->catchModeSpecies = gWildMonLocations[gUnknown_020314E0->area][rareMons][i];
        }
    }

    gUnknown_020314E0->unk59C = gUnknown_020314E0->catchModeSpecies;
}
