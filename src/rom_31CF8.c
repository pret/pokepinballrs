#include "global.h"
#include "main.h"
#include "constants/species.h"

/**
 *   0 if captured via ball
 *   1 if evolved
*/
void sub_31CF8(s16 evolved)
{
    s16 i;

    if (!evolved)
    {
        if (gMain.mainState != STATE_GAME_IDLE)
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, SPECIES_CAUGHT);

        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionMethod != 0)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget < SPECIES_NONE)
            {
                if (gCurrentPinballGame->evolvablePartySize < MAX_EVOLVABLE_PARTY_SIZE)
                {
                    gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvablePartySize] =
                        gCurrentPinballGame->currentSpecies;

                    gCurrentPinballGame->evolvablePartySize++;
                }
                else
                {
                    for (i = 0; i < MAX_EVOLVABLE_PARTY_SIZE; i++)
                        gCurrentPinballGame->evolvablePartySpecies[i] = gCurrentPinballGame->evolvablePartySpecies[i + 1];

                    gCurrentPinballGame->evolvablePartySpecies[MAX_EVOLVABLE_PARTY_SIZE - 1] = gCurrentPinballGame->currentSpecies;
                }
            }
        }
    }
    else
    {
        gCurrentPinballGame->evolvablePartySize--;

        for (i = gCurrentPinballGame->evolvingPartyIndex; i < gCurrentPinballGame->evolvablePartySize; i++)
            gCurrentPinballGame->evolvablePartySpecies[i] = gCurrentPinballGame->evolvablePartySpecies[i + 1];

        if (gCurrentPinballGame->currentSpecies == SPECIES_WURMPLE)
        {
            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gMain_saveData.pokedexFlags[SPECIES_SILCOON] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_SILCOON;
                else
                    gCurrentPinballGame->currentSpecies = SPECIES_CASCOON;
            }
            else
            {
                if (gMain_saveData.pokedexFlags[SPECIES_CASCOON] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_CASCOON;
                else
                    gCurrentPinballGame->currentSpecies = SPECIES_SILCOON;
            }
        }
        else if (gCurrentPinballGame->currentSpecies == SPECIES_GLOOM)
        {
            if (gMain.selectedField == FIELD_RUBY)
                gCurrentPinballGame->currentSpecies = SPECIES_VILEPLUME;
            else
                gCurrentPinballGame->currentSpecies = SPECIES_BELLOSSOM;
        }
        else if (gCurrentPinballGame->currentSpecies == SPECIES_CLAMPERL)
        {
            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gMain_saveData.pokedexFlags[SPECIES_HUNTAIL] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_HUNTAIL;
                else
                    gCurrentPinballGame->currentSpecies = SPECIES_GOREBYSS;
            }
            else
            {
                if (gMain_saveData.pokedexFlags[SPECIES_GOREBYSS] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_GOREBYSS;
                else
                    gCurrentPinballGame->currentSpecies = SPECIES_HUNTAIL;
            }
        }
        else if (gCurrentPinballGame->currentSpecies == SPECIES_NINCADA)
        {
            gCurrentPinballGame->currentSpecies = SPECIES_SHEDINJA;
            if (gMain.mainState != STATE_GAME_IDLE)
                SaveFile_SetPokedexFlags(SPECIES_SHEDINJA, SPECIES_CAUGHT);

            gCurrentPinballGame->currentSpecies = SPECIES_NINJASK;
        }
        else
        {
            gCurrentPinballGame->currentSpecies =
              gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;
        }

        if (gMain.mainState != STATE_GAME_IDLE)
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, SPECIES_CAUGHT);

        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionMethod != 0)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget < SPECIES_NONE)
            {
                if (gCurrentPinballGame->evolvablePartySize < MAX_EVOLVABLE_PARTY_SIZE)
                {
                    gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvablePartySize] =
                        gCurrentPinballGame->currentSpecies;
                    gCurrentPinballGame->evolvablePartySize++;
                }
                else
                {
                    for (i = 0; i < MAX_EVOLVABLE_PARTY_SIZE; i++)
                        gCurrentPinballGame->evolvablePartySpecies[i] = gCurrentPinballGame->evolvablePartySpecies[i + 1];

                    gCurrentPinballGame->evolvablePartySpecies[MAX_EVOLVABLE_PARTY_SIZE - 1] = gCurrentPinballGame->currentSpecies;
                }
            }
        }
    }
}
