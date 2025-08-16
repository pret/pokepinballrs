#include "global.h"
#include "functions.h"
#include "main.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/pinball_game.h"

extern const u16 gWildMonLocations[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gEggLocations[MAIN_FIELD_COUNT][26];

static inline u32 GetTimeAdjustedRandom()
{
    return Random() + (gMain.systemFrameCount + gMain.fieldFrameCount);
}

/*
BuildSpeciesWeightsForX constructs two key objects:

speciesWeights[] - A cumulative weight array where each entry represents the total weight of all species up to that index.
                   Species weights are influenced by factors such as whether the Pokémon has already been caught and if it has
                   an evolution needed for the Pokédex. This ensures rarer or more desirable species have appropriate weighting.

totalWeight - The final cumulative weight value, equal to the last value in speciesWeights[]. This is used as the upper bound
              for random selection.

PickSpeciesForX determines a species as follows:

1. Applies special conditions (e.g., forced rare selection if applicable).
2. Rolls a random number % totalWeight.
3. Iterates through speciesWeights[] and selects the first species whose cumulative weight meets or exceeds the rolled number.

*/

void BuildSpeciesWeightsForCatchEmMode(void)
{
    s16 threeArrows;
    s16 i;
    s16 j;
    s16 weight;
    s16 currentSpecies;
    s16 evolutionWeight;

    gCurrentPinballGame->totalWeight = 0;
    if (gCurrentPinballGame->catchModeArrows == 3)
        threeArrows = 1;
    else
        threeArrows = 0;

    for (i = 0; i < WILD_MON_LOCATION_COUNT; i++)
    {
        currentSpecies = gWildMonLocations[gCurrentPinballGame->area][threeArrows][i];
        switch (currentSpecies)
        {
            // Rare pokemon
            case SPECIES_NOSEPASS:
            case SPECIES_SKARMORY:
            case SPECIES_LILEEP:
            case SPECIES_ANORITH:
            case SPECIES_FEEBAS:
            case SPECIES_CASTFORM:
            case SPECIES_KECLEON:
            case SPECIES_ABSOL:
            case SPECIES_WOBBUFFET:
                if (gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD])
                {
                    if (gMain_saveData.pokedexFlags[currentSpecies] < SPECIES_SHARED)
                        weight = 2;
                    else
                        weight = 4;
                }
                else
                {
                    if (gMain_saveData.pokedexFlags[currentSpecies] < SPECIES_SHARED)
                        weight = 1;
                    else
                        weight = 2;
                }

                if (gCurrentPinballGame->caughtMonCount == 0)
                    weight = 0;
                break;

            case SPECIES_CLAMPERL:
                weight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_CLAMPERL]];
                evolutionWeight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_HUNTAIL]];
                if (weight < evolutionWeight)
                    weight = evolutionWeight;
                evolutionWeight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_GOREBYSS]];
                if (weight < evolutionWeight)
                    weight = evolutionWeight;
                break;
            case SPECIES_NONE:
                weight = 0;
                break;
            default:
                weight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[currentSpecies]];
                for (j = 0; j < 2; j++)
                {
                    currentSpecies = gSpeciesInfo[currentSpecies].evolutionTarget;
                    if (currentSpecies < SPECIES_NONE)
                    {
                        evolutionWeight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[currentSpecies]];
                        if (weight < evolutionWeight)
                        {
                            weight = evolutionWeight;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                currentSpecies = gWildMonLocations[gCurrentPinballGame->area][threeArrows][i];
                if (gCurrentPinballGame->caughtMonCount == 0 && gSpeciesInfo[currentSpecies].evolutionTarget >= SPECIES_NONE)
                {
                    weight = 0;
                }
                break;
        }

        if (gCurrentPinballGame->lastCatchSpecies == currentSpecies)
        {
            weight = 0;
        }
        gCurrentPinballGame->totalWeight += weight;
        gCurrentPinballGame->speciesWeights[i] = gCurrentPinballGame->totalWeight;
    }
}

void PickSpeciesForCatchEmMode(void)
{
    s16 i;
    u32 rand;
    u16 specialMons[6];

    if (gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD])
    {
        gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD] = 0;
        rand = GetTimeAdjustedRandom();
        rand %= NUM_BONUS_SPECIES;
        for (i = 0; i < NUM_BONUS_SPECIES; i++)
        {
            if (gMain_saveData.pokedexFlags[BONUS_SPECIES_START + ((i + rand) % NUM_BONUS_SPECIES)] < SPECIES_CAUGHT)
                break;
        }

        gCurrentPinballGame->currentSpecies = BONUS_SPECIES_START + ((i + rand) % NUM_BONUS_SPECIES);
    }
    else
    {
        rand = GetTimeAdjustedRandom();
        if (gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD])
            rand %= 50;
        else
            rand %= 100;

        if (gUnknown_02031520.unk8 < 100)
            rand = 1;

        if ((rand == 0 && gCurrentPinballGame->caughtMonCount >= 5) || gCurrentPinballGame->forceSpecialMons)
        {
            s16 numSpecialMons = 0;
            gCurrentPinballGame->currentSpecies = 0;
            if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL])
            {
                specialMons[numSpecialMons++] = SPECIES_AERODACTYL;
                if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_AERODACTYL;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA])
            {
                specialMons[numSpecialMons++] = SPECIES_CHIKORITA;
                if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_CHIKORITA;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE])
            {
                specialMons[numSpecialMons++] = SPECIES_TOTODILE;
                if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_TOTODILE;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL])
            {
                specialMons[numSpecialMons++] = SPECIES_CYNDAQUIL;
                if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_CYNDAQUIL;
            }

            if (gMain.selectedField == FIELD_RUBY)
            {
                specialMons[numSpecialMons++] = SPECIES_LATIOS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIOS] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_LATIOS;
            }
            else
            {
                specialMons[numSpecialMons++] = SPECIES_LATIAS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIAS] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_LATIAS;
            }

            if (gCurrentPinballGame->currentSpecies == 0)
            {
                rand = GetTimeAdjustedRandom();
                rand %= numSpecialMons;
                gCurrentPinballGame->currentSpecies = specialMons[rand];
            }
        }
        else
        {
            s16 threeArrows;
            if (gCurrentPinballGame->catchModeArrows == 3)
                threeArrows = 1;
            else
                threeArrows = 0;

            rand = GetTimeAdjustedRandom();
            rand %= gCurrentPinballGame->totalWeight;
            for (i = 0; i < WILD_MON_LOCATION_COUNT && gCurrentPinballGame->speciesWeights[i] <= rand; i++);

            gCurrentPinballGame->currentSpecies = gWildMonLocations[gCurrentPinballGame->area][threeArrows][i];
        }
    }

    gCurrentPinballGame->lastCatchSpecies = gCurrentPinballGame->currentSpecies;
}

void BuildSpeciesWeightsForEggMode(void)
{
    s16 i;
    s16 currentSpecies;
    s16 weight;
    s16 j;
    s16 evolutionWeight;

    gCurrentPinballGame->totalWeight = 0;

    for (i = 0; i < 25; i++)
    {
        currentSpecies = gEggLocations[gMain.selectedField][i];

        if (currentSpecies == SPECIES_ODDISH)
        {
            if (gMain.selectedField == FIELD_RUBY)
                weight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_VILEPLUME]];
            else
                weight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_BELLOSSOM]];
        }
        else
        {
            weight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[currentSpecies]];

            for (j = 0; j < 2; j++)
            {
                currentSpecies = gSpeciesInfo[currentSpecies].evolutionTarget;
                if (currentSpecies < SPECIES_NONE)
                {
                    evolutionWeight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[currentSpecies]];
                    if (weight < evolutionWeight)
                        weight = evolutionWeight;
                }
                else
                {
                    break;
                }
            }

            currentSpecies = gEggLocations[gMain.selectedField][i];
            if (gCurrentPinballGame->caughtMonCount == 0)
            {
                if (gSpeciesInfo[currentSpecies].evolutionTarget >= SPECIES_NONE)
                {
                    weight = 0;
                }
            }
        }

        if (gCurrentPinballGame->lastEggSpecies == currentSpecies)
        {
            weight = 0;
        }

        gCurrentPinballGame->totalWeight += weight;
        gCurrentPinballGame->speciesWeights[i] = gCurrentPinballGame->totalWeight;
    }
}

void PickSpeciesForEggMode(void)
{
    s16 i;
    u32 rand;

    rand = GetTimeAdjustedRandom();
    if (gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD])
        rand %= 100;
    else
        rand %= 50;

    if (gCurrentPinballGame->lastEggSpecies == SPECIES_PICHU)
        rand = 1;

    if ((rand == 0 && gCurrentPinballGame->caughtMonCount >= 5) || gCurrentPinballGame->forcePichuEgg)
    {
        gCurrentPinballGame->currentSpecies = SPECIES_PICHU;
    }
    else
    {
        rand = GetTimeAdjustedRandom();
        rand %= gCurrentPinballGame->totalWeight;

        for (i = 0; i < 25 && gCurrentPinballGame->speciesWeights[i] <= rand; i++);

        gCurrentPinballGame->currentSpecies = gEggLocations[gMain.selectedField][i];
    }

    gCurrentPinballGame->lastEggSpecies = gCurrentPinballGame->currentSpecies;
}
