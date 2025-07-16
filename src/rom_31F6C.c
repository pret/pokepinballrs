#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/pinball_game.h"

void sub_32DF8(void);

extern const u16 gWildMonLocations[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gEggLocations[MAIN_FIELD_COUNT][26];

extern struct SongHeader gUnknown_086A1588;
extern s16 gUnknown_086AE5EC[][3];

#define BONUS_DUSKULL_TIME 7200 //2 minutes, 60FPS
#define BONUS_DUSKULL_COMPLETE_POINTS 30000000

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

void sub_326F4(void)
{
    gCurrentPinballGame->catchModeArrows = 2;
    gCurrentPinballGame->unk1E5 = 0;
    gCurrentPinballGame->unk1E6 = 1;

    sub_1F2A4();
    sub_21B0C();
    sub_1F59C();
    sub_300D8();
    sub_30178();

    gCurrentPinballGame->unk1D8 = 0x100;
    gCurrentPinballGame->unk1DA = 0x100;

    sub_30480();
    sub_304C8();
    sub_31144();
    sub_313A0();
    sub_2E6AC();
    sub_31B30();
}

void sub_3276C(void)
{
    sub_19B90();
    sub_327C0();

    if (!gMain.unkF)
        sub_328C8();

    sub_32DF8();

    if (gCurrentPinballGame->unk29C)
    {
        gCurrentPinballGame->unk29C--;
        if (!gCurrentPinballGame->unk29C)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void sub_327C0(void)
{
    s32 temp;

    sub_4F814();
    sub_1A0F4();
    sub_2CA9C();

    if (gCurrentPinballGame->unk68 < 0x5a)
    {
        sub_304C8();
        sub_31498();
    }

    if (gCurrentPinballGame->unk13 < 3)
    {
        if (gCurrentPinballGame->unk345 == 3 && gCurrentPinballGame->unk346 == 0)
        {
            gCurrentPinballGame->unk728 = 1;
        }
        else
        {
            gCurrentPinballGame->unk728 = 0;
        }
    }
    else
    {
        gCurrentPinballGame->unk728 = 0;
    }

    if (gCurrentPinballGame->unk68 < 0x96)
    {
        sub_2E6AC();
        sub_313A0();
    }
    if (gCurrentPinballGame->unk68 < 0xC4)
    {
        sub_30178();
        sub_2F140();
    }
    if (gCurrentPinballGame->unk68 < 0xCA)
    {
        sub_2FCD0();
    }
    if (gCurrentPinballGame->unk68 < 0xDC)
    {
        sub_1F59C();
    }

    sub_308DC();

    if (0x76 < gCurrentPinballGame->unk68)
    {
        sub_2F504();
        sub_30EB4();
    }

    sub_2CE80();

    if (0xA8 < gCurrentPinballGame->unk68)
        sub_2D104();

    sub_203CC();
    sub_21B0C();
    sub_1D128();
    sub_31B30();

    if (gCurrentPinballGame->unk194)
        sub_225F0();

    sub_472E4();
}

void sub_328C8(void)
{
    sub_300D8();
    sub_32968();
    sub_1F2A4();

    if (gCurrentPinballGame->unk600)
        gCurrentPinballGame->unk600--;

    sub_2F26C();
    sub_2E67C();
    sub_31144();

    if (!(gMain.unkF & 0x20))
        sub_2F79C();
}

void sub_32914(void)
{
    if (gMain.unkF != 0)
        return;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_32B74();
        break;
    case 3:
        sub_329B0();
        break;
    case 4:
        sub_1C560();
        break;
    }

    gCurrentPinballGame->unk26 = 60;
}

void sub_32968(void)
{
    if (gCurrentPinballGame->unk26)
        gCurrentPinballGame->unk26--;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_32BE4();
        break;
    case 3:
        sub_329F4();
        break;
    case 4:
        sub_1C5AC();
        break;
    }
}

void sub_329B0(void)
{
    gCurrentPinballGame->unk28 = 0xB4;
    gCurrentPinballGame->unk1BA = 0xB4;
    gCurrentPinballGame->unk3C = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->unk5F7 = 1;
}

void sub_329F4(void)
{
    s16 i;

    if (gCurrentPinballGame->unk28 > 0x18)
    {
        gCurrentPinballGame->ball->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 58;
        gCurrentPinballGame->ball->positionQ0.y = 178;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;

        if (gCurrentPinballGame->unk28 <= 0x31)
        {
            gCurrentPinballGame->unk28++;
        }

        sub_1B140(gCurrentPinballGame->unk1A5);

        if (gCurrentPinballGame->unk1A5)
        {
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->unk36C[i] = 10;
                gCurrentPinballGame->unk36E[i] = 0;
                gCurrentPinballGame->unk36A[i] = 4;
            }
        }
    }
    else if (gCurrentPinballGame->unk28 > 0)
    {
        gCurrentPinballGame->unk28--;
    }
    else
    {
        gCurrentPinballGame->ball->unk0 = 0;
        gCurrentPinballGame->unk1F = 0;
        gCurrentPinballGame->unk26 = 0x3C;
        gCurrentPinballGame->ball->velocity.x = 0x60;
        gCurrentPinballGame->ball->velocity.y = 0xC0;
        gCurrentPinballGame->ball->positionQ0.x = 0x3C;
        gCurrentPinballGame->ball->positionQ0.y = 0xB4;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->unk25 = 0;

        m4aSongNumStart(SE_UNKNOWN_0xC3);

        if (gCurrentPinballGame->unk72E > 2 && gCurrentPinballGame->evolvablePartySize > 0) {
            sub_19B64(6);
        }
    }
}

void sub_32B74(void)
{
    if (gCurrentPinballGame->unk72F > 1)
        sub_19B64(4);

    gCurrentPinballGame->unk28 = 100;
    gCurrentPinballGame->unk2F4 = 2;
    gCurrentPinballGame->unk5FC = 0;
    gCurrentPinballGame->unk5FE = 30;
    gCurrentPinballGame->unk5FB = 0;
    gCurrentPinballGame->unk3C = 50000;

    m4aSongNumStart(SE_UNKNOWN_0xD5);
    sub_11B0(8);
}

void sub_32BE4(void)
{
    if (gCurrentPinballGame->unk28)
    {
        gCurrentPinballGame->unk5F7 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->unk6 = 0;
        if (gCurrentPinballGame->unk28 > 97)
        {
            gCurrentPinballGame->unk5FA = 1;
            gCurrentPinballGame->unk2F4 = 2;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else if (gCurrentPinballGame->unk28 > 94)
        {
            gCurrentPinballGame->unk2F4 = 3;
            gCurrentPinballGame->ball->positionQ0.x = 0xb8;
            gCurrentPinballGame->ball->positionQ0.y = 0xbb;
        }
        else if (gCurrentPinballGame->unk28 > 91)
        {
            gCurrentPinballGame->ball->unk0 = 1;
            gCurrentPinballGame->unk2F4 = 4;
        }
        else if (gCurrentPinballGame->unk28 > 83)
        {
            gCurrentPinballGame->unk2F4 = 5;
        }
        else if (gCurrentPinballGame->unk28 > 34)
        {
            gCurrentPinballGame->unk2F4 = 6;

        }
        else if (gCurrentPinballGame->unk28 > 26)
        {
            gCurrentPinballGame->unk2F4 = 7;

        }
        else if (gCurrentPinballGame->unk28 > 18)
        {
            gCurrentPinballGame->unk2F4 = 8;

        }
        else if (gCurrentPinballGame->unk28 > 10)
        {
            gCurrentPinballGame->unk2F4 = 9;

        }
        else if (gCurrentPinballGame->unk28 > 4)
        {
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk2F4 = 10;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else
        {
            gCurrentPinballGame->unk2F4 = 11;
            gCurrentPinballGame->ball->positionQ0.x = 0xb0;
            gCurrentPinballGame->ball->positionQ0.y = 0xca;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
    }
    else
    {
        gCurrentPinballGame->unk2F4 = 0;
        gCurrentPinballGame->unk1F = 0;
        gCurrentPinballGame->unk26 = 60;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->velocity.x = -0x66;
        gCurrentPinballGame->ball->velocity.y = 0xC8;
        sub_11B0(7);
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xAB;
        gCurrentPinballGame->ball->positionQ0.y = 0xD4;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->unk25 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        m4aSongNumStart(SE_UNKNOWN_0xD6);
        gCurrentPinballGame->unk5FE = 0;
        gCurrentPinballGame->unk5FB = 1;
        gCurrentPinballGame->unk5FA = 0;
    }
}

void sub_32DF8(void)
{
    int tmp;

    if (gCurrentPinballGame->newButtonActions[0])
    {
        if (gCurrentPinballGame->unk1C4 == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->unk1C0 == 0 && gCurrentPinballGame->unk61C == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 0;
        }

        tmp = gCurrentPinballGame->hLight;
        gCurrentPinballGame->hLight = gCurrentPinballGame->oLight;
        gCurrentPinballGame->oLight = gCurrentPinballGame->lLight;
        gCurrentPinballGame->lLight = gCurrentPinballGame->eLight;
        gCurrentPinballGame->eLight = tmp;

        tmp = gCurrentPinballGame->leftBallPowerUpLight;
        gCurrentPinballGame->leftBallPowerUpLight = gCurrentPinballGame->centerBallPowerUpLight;
        gCurrentPinballGame->centerBallPowerUpLight = gCurrentPinballGame->rightBallPowerUpLight;
        gCurrentPinballGame->rightBallPowerUpLight = tmp;
    }

    if (gCurrentPinballGame->newButtonActions[1])
    {
        if (gCurrentPinballGame->unk1C4 == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->unk1C0 == 0 && gCurrentPinballGame->unk61C == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 1;
        }

        tmp = gCurrentPinballGame->eLight;
        gCurrentPinballGame->eLight = gCurrentPinballGame->lLight;
        gCurrentPinballGame->lLight = gCurrentPinballGame->oLight;
        gCurrentPinballGame->oLight = gCurrentPinballGame->hLight;
        gCurrentPinballGame->hLight = tmp;

        tmp = gCurrentPinballGame->rightBallPowerUpLight;
        gCurrentPinballGame->rightBallPowerUpLight = gCurrentPinballGame->centerBallPowerUpLight;
        gCurrentPinballGame->centerBallPowerUpLight = gCurrentPinballGame->leftBallPowerUpLight;
        gCurrentPinballGame->leftBallPowerUpLight = tmp;
    }
}

void DuskullBonus_Setup(void)
{
    s16 i;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_DUSKULL_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk388 = 3;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unk385 = 0;
    gCurrentPinballGame->unk386 = 0;
    gCurrentPinballGame->unk387 = 0;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->unk394 = 0;
    gCurrentPinballGame->unk396 = 0;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->unk397[i] = 0;
        gCurrentPinballGame->unk39A[i] = 0;
        gCurrentPinballGame->unk39D[i] = 0;
        gCurrentPinballGame->unk3A0[i] = 0;
        gCurrentPinballGame->unk3A3[i] = 0;
        gCurrentPinballGame->unk3A6[i] = 0;
        gCurrentPinballGame->unk3A9[i] = 0;
        gCurrentPinballGame->unk3AC[i] = 0;
        gCurrentPinballGame->unk3B0[i] = 0;
        gCurrentPinballGame->unk3B6[i] = 0;
        gCurrentPinballGame->unk3BC[i] = 0;
        gCurrentPinballGame->unk3C4[i].x = 0;
        gCurrentPinballGame->unk3C4[i].y = 0;
        gCurrentPinballGame->unk3D0[i].x = 0;
        gCurrentPinballGame->unk3D0[i].y = 0;
    }

    gCurrentPinballGame->unk3DC = 0;
    gCurrentPinballGame->unk3DE = 0;
    gCurrentPinballGame->unk3DF = 0;
    gCurrentPinballGame->unk3E0 = 0;
    gCurrentPinballGame->unk3E2 = 0;
    gCurrentPinballGame->unk3E4 = 0;
    gCurrentPinballGame->unk3E6 = 0;
    gCurrentPinballGame->unk3E8 = 0;
    gCurrentPinballGame->unk3EA = 0;
    gCurrentPinballGame->unk3EC = 0;
    gCurrentPinballGame->unk3EE = 0;
    gCurrentPinballGame->unk3F0 = 0;
    gCurrentPinballGame->unk3F2 = 0;
    gCurrentPinballGame->unk1A = 0;

    sub_336E0();
    sub_340EC();

    m4aSongNumStart(MUS_BONUS_FIELD_DUSKULL);

    DmaCopy16(3, (void *)gUnknown_081B36A4, (void *)0x05000320, 32);
}

void sub_33130(void)
{
    s16 temp;
    switch (gCurrentPinballGame->unk13)
    {
        case 0:
            gCurrentPinballGame->unk5F7 = 1;
            if (gCurrentPinballGame->unk18 < 120)
            {
                temp = gCurrentPinballGame->unk18 / 24;
                DmaCopy16(3, gUnknown_082EE0E0 + temp * 40, 0x05000000, 160);

                gCurrentPinballGame->unkE6 = gCurrentPinballGame->unk18 / 5 + 0xFFE8;
                gCurrentPinballGame->unk18++;
            }
            else
            {
                gCurrentPinballGame->unkE6 = 0;
                gMain.spriteGroups[7].available = 1;
                gMain.spriteGroups[8].available = 1;
                gMain.spriteGroups[9].available = 1;
                gCurrentPinballGame->unk13 = 1;
                gCurrentPinballGame->unk18 = 0;
            }

            break;
        case 1:
            if (!gCurrentPinballGame->unk386)
            {
                gMain.blendControl = 0x1C10;
                gMain.blendAlpha = 0x30D;
            }
            gCurrentPinballGame->unk387 = 1;
            sub_336E0();
            sub_340EC();
            break;
        case 2:
            gCurrentPinballGame->unk13 = 3;
            gMain.spriteGroups[13].available = 1;
            gMain.spriteGroups[14].available = 1;
            gMain.spriteGroups[12].available = 1;
            gCurrentPinballGame->unk387 = 0;
            gCurrentPinballGame->unk385 = 0;
            m4aSongNumStart(MUS_BONUS_FIELD_DUSCLOPS);
            break;
        case 3:
            if (!gCurrentPinballGame->unk386)
            {
                gMain.blendControl = 0x1C10;
                gMain.blendAlpha = 0x1000;
            }
            sub_34450();
            break;
        case 4:
            if (gCurrentPinballGame->unk18 < 120)
            {
                gCurrentPinballGame->unk18++;
            }
            else
            {
                gCurrentPinballGame->unk13 = 5;
                gCurrentPinballGame->unk18 = 0;
                gMain.spriteGroups[6].available = 1;
                gMain.spriteGroups[5].available = 1;
                DmaCopy16(3, gUnknown_08138834, OBJ_VRAM1+0x1800, 8192);
                gCurrentPinballGame->unk394 = 136;
            }
            break;
        case 5:
            sub_351A8();
            if (gCurrentPinballGame->unk1C)
            {
                gCurrentPinballGame->unk18 = 181;
            }
            if (gCurrentPinballGame->unk18 == 180)
            {
                gCurrentPinballGame->unk1C = 1;
                gCurrentPinballGame->unk38 = 400000;
                gCurrentPinballGame->unk3C = BONUS_DUSKULL_COMPLETE_POINTS;
            }
            if (gCurrentPinballGame->unk18 < 240)
            {
                if (gCurrentPinballGame->unk18 == 20)
                {
                    m4aMPlayAllStop();
                    m4aSongNumStart(MUS_SUCCESS3);
                }
                gCurrentPinballGame->unk18++;
            }
            else
            {
                gCurrentPinballGame->unk18 = 0;
                gCurrentPinballGame->unk13 = 6;
                gCurrentPinballGame->numCompletedBonusStages++;
            }

            break;
        case 6:
            sub_351A8();
            gCurrentPinballGame->unk386 = 1;
            break;
    }

    if (gCurrentPinballGame->unk294)
    {
        if (gCurrentPinballGame->eventTimer < 2)
        {
            if (!gMain.unkF)
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL3);
                gMain.unkF = gMain.unkF | 0x40;
            }
        }
    }

    if (gCurrentPinballGame->unk386)
        sub_350F0();

    sub_472E4();
}

void sub_3342C(s16 index1, s16 index2)
{
    u8 temp397, temp39A, temp39D, temp3A0, temp3A3, temp3A6, temp3A9, temp3AC;
    u16 temp3B0, temp3B6, temp3BC;
    struct Vector16 temp3C4, temp3D0;

    temp397 = gCurrentPinballGame->unk397[index1];
    temp39A = gCurrentPinballGame->unk39A[index1];
    temp39D = gCurrentPinballGame->unk39D[index1];
    temp3A0 = gCurrentPinballGame->unk3A0[index1];
    temp3A3 = gCurrentPinballGame->unk3A3[index1];
    temp3A6 = gCurrentPinballGame->unk3A6[index1];
    temp3A9 = gCurrentPinballGame->unk3A9[index1];
    temp3AC = gCurrentPinballGame->unk3AC[index1];
    temp3B0 = gCurrentPinballGame->unk3B0[index1];
    temp3B6 = gCurrentPinballGame->unk3B6[index1];
    temp3BC = gCurrentPinballGame->unk3BC[index1];
    temp3C4.x = gCurrentPinballGame->unk3C4[index1].x;
    temp3C4.y = gCurrentPinballGame->unk3C4[index1].y;
    temp3D0.x = gCurrentPinballGame->unk3D0[index1].x;
    temp3D0.y = gCurrentPinballGame->unk3D0[index1].y;

    gCurrentPinballGame->unk397[index1] = gCurrentPinballGame->unk397[index2];
    gCurrentPinballGame->unk39A[index1] = gCurrentPinballGame->unk39A[index2];
    gCurrentPinballGame->unk39D[index1] = gCurrentPinballGame->unk39D[index2];
    gCurrentPinballGame->unk3A0[index1] = gCurrentPinballGame->unk3A0[index2];
    gCurrentPinballGame->unk3A3[index1] = gCurrentPinballGame->unk3A3[index2];
    gCurrentPinballGame->unk3A6[index1] = gCurrentPinballGame->unk3A6[index2];
    gCurrentPinballGame->unk3A9[index1] = gCurrentPinballGame->unk3A9[index2];
    gCurrentPinballGame->unk3AC[index1] = gCurrentPinballGame->unk3AC[index2];
    gCurrentPinballGame->unk3B0[index1] = gCurrentPinballGame->unk3B0[index2];
    gCurrentPinballGame->unk3B6[index1] = gCurrentPinballGame->unk3B6[index2];
    gCurrentPinballGame->unk3BC[index1] = gCurrentPinballGame->unk3BC[index2];
    gCurrentPinballGame->unk3C4[index1].x = gCurrentPinballGame->unk3C4[index2].x;
    gCurrentPinballGame->unk3C4[index1].y = gCurrentPinballGame->unk3C4[index2].y;
    gCurrentPinballGame->unk3D0[index1].x = gCurrentPinballGame->unk3D0[index2].x;
    gCurrentPinballGame->unk3D0[index1].y = gCurrentPinballGame->unk3D0[index2].y;

    gCurrentPinballGame->unk397[index2] = temp397;
    gCurrentPinballGame->unk39A[index2] = temp39A;
    gCurrentPinballGame->unk39D[index2] = temp39D;
    gCurrentPinballGame->unk3A0[index2] = temp3A0;
    gCurrentPinballGame->unk3A3[index2] = temp3A3;
    gCurrentPinballGame->unk3A6[index2] = temp3A6;
    gCurrentPinballGame->unk3A9[index2] = temp3A9;
    gCurrentPinballGame->unk3AC[index2] = temp3AC;
    gCurrentPinballGame->unk3B0[index2] = temp3B0;
    gCurrentPinballGame->unk3B6[index2] = temp3B6;
    gCurrentPinballGame->unk3BC[index2] = temp3BC;
    gCurrentPinballGame->unk3C4[index2].x = temp3C4.x;
    gCurrentPinballGame->unk3C4[index2].y = temp3C4.y;
    gCurrentPinballGame->unk3D0[index2].x = temp3D0.x;
    gCurrentPinballGame->unk3D0[index2].y = temp3D0.y;
}

void sub_336E0(void) {
    s16 i, j;
    bool32 r4 = TRUE;
    u16 sp0 = 0;
    u16 r7 = 0;

    if (gCurrentPinballGame->unk385 > 18)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->unk3A6[i])
                r4 = FALSE;
        }
        if (r4)
        {
            gCurrentPinballGame->unk13 = 2; // Transition to next phase of bonus game?
            gMain.spriteGroups[7].available = 0;
            gMain.spriteGroups[8].available = 0;
            gMain.spriteGroups[9].available = 0;
        }
    }

    for (i = 0; i < 3; i++)
    {
        switch(gCurrentPinballGame->unk3A0[i]) // duskull lifecycle state
        {
        case 0:
            if (gCurrentPinballGame->unk385 <= 18 && gCurrentPinballGame->unk396 < 2)
            {
                gCurrentPinballGame->unk396++; //Number of active duskull
                gCurrentPinballGame->unk3A0[i] = 1; //duskull lifecycle state
                gCurrentPinballGame->unk3A3[i] = 0; //unknown
                gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                gCurrentPinballGame->unk3C4[i].x = (Random() % 1400) - 700; //Sprite x pos
                gCurrentPinballGame->unk3C4[i].y = (Random() % 9) * 80; // sprite y pos
                gCurrentPinballGame->unk3BC[i] = (Random() % 1000) + 200; //Time before escaping
                gCurrentPinballGame->unk3A6[i] = 0; // = r7 //unknown
                gCurrentPinballGame->unk3A9[i] = 0; // = r7
                sp0 = 4;
                r7 = 4;
                gCurrentPinballGame->unk3B6[i] = 0; //Time alive
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A1588);
                for (j = 2; j > 0; j--)
                {
                    if (gCurrentPinballGame->unk3C4[j].y > gCurrentPinballGame->unk3C4[j-1].y)
                    {
                        sub_3342C(j, j - 1);
                        j = 3;
                    }
                }
            }
            else
            {
                gCurrentPinballGame->unk3C4[i].x = 0;
                gCurrentPinballGame->unk3C4[i].y = 120;
                gCurrentPinballGame->unk3A6[i] = 0;
                Random();
            }
            break;
        case 1: //Spawn in, Wait and initial movement decision
            if (gCurrentPinballGame->unk3B0[i] < 20) //Time since last decision
            {
                gCurrentPinballGame->unk3B0[i]++; //Time since last decision
                gCurrentPinballGame->unk3A6[i] = (gCurrentPinballGame->unk3B0[i] % 4) / 2;
                sp0 = 4;
                r7 = 4;
                break;
            }
            else
            {
                if (gMain.systemFrameCount % 2)
                {
                    gCurrentPinballGame->unk3A0[i] = 2; //duskull lifecycle state. Move Left
                    gCurrentPinballGame->unk3A3[i] = 0; //Sprite = move left sprite
                }
                else
                {
                    gCurrentPinballGame->unk3A0[i] = 3; //duskull lifecycle state. Move Right
                    gCurrentPinballGame->unk3A3[i] = 7; //Sprite = move right sprite
                }

                gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                gCurrentPinballGame->unk3A6[i] = 1;
                gCurrentPinballGame->unk3A9[i] = 1;
                sp0 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][0];
                r7 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][2];
            }
            break;
        case 2: // Move Left state
            gCurrentPinballGame->unk3B6[i]++; //Time Alive
            if (gCurrentPinballGame->unk3C4[i].x > -800) //Dusclops x pos
            {
                gCurrentPinballGame->unk3C4[i].x -= 3; //Move left
                if (gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][1] > gCurrentPinballGame->unk3B0[i])
                {
                    gCurrentPinballGame->unk3B0[i]++; //Time since last decision
                }
                else
                {
                    gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                    gCurrentPinballGame->unk3A3[i]++; //Animation frame advance
                    if (gCurrentPinballGame->unk3A3[i] > 3) //Animation frame reset
                        gCurrentPinballGame->unk3A3[i] = 0;
                }
            }
            else
            {
                if (gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][1] > gCurrentPinballGame->unk3B0[i])
                {
                    gCurrentPinballGame->unk3B0[i]++; //Time since last decision
                }
                else
                {
                    gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                    gCurrentPinballGame->unk3A3[i]++; //Animation frame advance 'move left to neutral state'
                    if (gCurrentPinballGame->unk3A3[i] > 6) //Animation frame at neutral forward, continue with move right 
                    {
                        gCurrentPinballGame->unk3A3[i] = 7;
                        gCurrentPinballGame->unk3A0[i] = 3; //duskull lifecycle state. Move Right
                    }
                }
            }
            sp0 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][0];
            r7 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][2];
            break;
        case 3: //Move Right state 
            gCurrentPinballGame->unk3B6[i]++; //Time Alive
            if (gCurrentPinballGame->unk3C4[i].x < 800) //Dusclops x pos
            {
                gCurrentPinballGame->unk3C4[i].x += 3;
                gCurrentPinballGame->unk3C4[i].y += 0; // ! Dead code needed for matching
                if (gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][1] > gCurrentPinballGame->unk3B0[i])
                {
                    gCurrentPinballGame->unk3B0[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                    gCurrentPinballGame->unk3A3[i]++; //Animation frame advance 
                    if (gCurrentPinballGame->unk3A3[i] > 10)
                        gCurrentPinballGame->unk3A3[i] = 7;
                }
            }
            else
            {
                if (gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][1] > gCurrentPinballGame->unk3B0[i])
                {
                    gCurrentPinballGame->unk3B0[i]++; //Time since last decision
                }
                else
                {
                    gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                    gCurrentPinballGame->unk3A3[i]++; //Animation frame advance
                    if (gCurrentPinballGame->unk3A3[i] > 13)
                    {
                        gCurrentPinballGame->unk3A3[i] = 0; //Animation frame set
                        gCurrentPinballGame->unk3A0[i] = 2; //duskull lifecycle state. Move Left
                    }
                }
            }
            sp0 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][0];
            r7 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][2];
            break;
        case 4: //Duskull Hit
            sp0 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][0];
            r7 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][2];
            gCurrentPinballGame->unk3A3[i] = 14; //Animation frame
            gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
            gCurrentPinballGame->unk3A0[i] = 5; //duskull lifecycle state. Death animation?
            gCurrentPinballGame->unk3AC[i] = 0;
            gCurrentPinballGame->unk3A9[i] = 0;
            if (gCurrentPinballGame->unk396 > 0)
                gCurrentPinballGame->unk396--; //Number of active duskull
            gCurrentPinballGame->unk3C = 100000;
            gCurrentPinballGame->unk385++; // Number hit
            m4aSongNumStart(SE_UNKNOWN_0xF2); //Duskull Death cry
            sub_11B0(7);
            break;
        case 5: //Duskull Dying Animation
            if (gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][1] > gCurrentPinballGame->unk3B0[i])
            {
                gCurrentPinballGame->unk3B0[i]++; //Time since last decision
            }
            else
            {
                gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                gCurrentPinballGame->unk3A3[i]++; //Animation frame advance
                if (gCurrentPinballGame->unk3A3[i] > 15) //Animation frame
                {
                    gCurrentPinballGame->unk3A3[i] = 15; //Animation frame
                    gCurrentPinballGame->unk3A0[i] = 9; //duskull lifecycle state. Despawn?
                    gCurrentPinballGame->unk3A6[i] = 0;
                }
            }
            if (gCurrentPinballGame->unk3A3[i] == 15) //Animation frame
                gCurrentPinballGame->unk3AC[i]++;
            sp0 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][0];
            r7 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][2];
            break;
        case 6: //Escape while in walk left state, turn to face center
            if (gCurrentPinballGame->unk3B0[i] < 6) //Time since last decision
            {
                gCurrentPinballGame->unk3B0[i]++; //Time since last decision
                sp0 = 3;
                r7 = 3;
            }
            else
            {
                gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                gCurrentPinballGame->unk3A3[i] = 18; //Animation frame
                gCurrentPinballGame->unk3A0[i] = 8; //duskull lifecycle state. Departure Animation
                gCurrentPinballGame->unk3A9[i] = 0;
                if (gCurrentPinballGame->unk396 > 0)
                    gCurrentPinballGame->unk396--; //Number of active duskull
                sp0 = 3;
                r7 = 3;
                m4aSongNumStart(SE_UNKNOWN_0xF3); //Duskull departs, not killed
            }
            break;
        case 7: //Escape while not in walk left state, turn to face
            if (gCurrentPinballGame->unk3B0[i] < 6)
            {
                gCurrentPinballGame->unk3B0[i]++; //Time since last decision
                sp0 = 9;
                r7 = 3;
            }
            else
            {
                gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                gCurrentPinballGame->unk3A3[i] = 18; //Animation frame
                gCurrentPinballGame->unk3A0[i] = 8; //duskull lifecycle state. Departure Animation?
                gCurrentPinballGame->unk3A9[i] = 0;
                if (gCurrentPinballGame->unk396 > 0)
                    gCurrentPinballGame->unk396--; //Number of active duskull
                m4aSongNumStart(SE_UNKNOWN_0xF3); //Duskull departs, not killed
                sp0 = 9;
                r7 = 3;
            }
            break;
        case 8: //Escape animation
            if (gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][1] > gCurrentPinballGame->unk3B0[i])
            {
                gCurrentPinballGame->unk3B0[i]++; //Time since last decision
            }
            else
            {
                gCurrentPinballGame->unk3B0[i] = 0; //Time since last decision
                gCurrentPinballGame->unk3A3[i]++; //Animation frame Advance
                if (gCurrentPinballGame->unk3A3[i] > 25) //Animation frame
                {
                    gCurrentPinballGame->unk3A3[i] = 25; //Animation frame
                    gCurrentPinballGame->unk3A0[i] = 9; //duskull lifecycle state. Despawn?
                }
            }
            sp0 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][0];
            r7 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][2];
            break;
        case 9: // Cleanup sprite
            gCurrentPinballGame->unk3A6[i] = 0;
            gCurrentPinballGame->unk3A9[i] = 0;
            gCurrentPinballGame->unk3A0[i] = 0; //duskull lifecycle state. Ready to respawn
            sp0 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][0];
            r7 = gUnknown_086AE5EC[gCurrentPinballGame->unk3A3[i]][2];
            break;
        }

        if (gCurrentPinballGame->unk3B6[i] > gCurrentPinballGame->unk3BC[i] // Time alive > time before escape, && number hit < 18
         && gCurrentPinballGame->unk385 <= 18)
        {
            gCurrentPinballGame->unk3B6[i] = 0;
            if (gCurrentPinballGame->unk3A0[i] == 2)
                gCurrentPinballGame->unk3A0[i] = 6; //Escape after moving left
            else
                gCurrentPinballGame->unk3A0[i] = 7; //Escape after moving right

            gCurrentPinballGame->unk3B0[i] = 0;
        }

        gCurrentPinballGame->unk397[i] = gCurrentPinballGame->unk39A[i];
        gCurrentPinballGame->unk39A[i] = r7;
        gCurrentPinballGame->unk39D[i] = sp0;
        gCurrentPinballGame->unk3D0[i].x = (gCurrentPinballGame->unk3C4[i].x / 10) * 2 + 208;
        gCurrentPinballGame->unk3D0[i].y = (gCurrentPinballGame->unk3C4[i].y / 10) * 2 + 66;
    }
}

extern const u8 gUnknown_08510E4C[];
extern const u16 gUnknown_086BA0A0[][2][3];
void sub_340EC() {
    s16 i, j;
    s16 sb;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple * oamData;
    u16 * dst;
    const u16 * src;

    for (i = 0; i < 3; i++)
    {
        s16 r8 = gCurrentPinballGame->unk397[i];
        DmaCopy16(3, gUnknown_08510E4C + r8 * 0x280, OBJ_VRAM0 + 0x920 + i * 0x280, 0x280);
        sb = gCurrentPinballGame->unk39D[i];
        spriteGroup = &gUnknown_0200B3B8[7 + i];
        if (gCurrentPinballGame->unk3A6[i]) {
            s32 x = 0; // Scrub C to get the compiler to add before subtracting
            spriteGroup->baseX = gCurrentPinballGame->unk3C4[i].x / 10 + 108 + x - gCurrentPinballGame->unk58;
            spriteGroup->baseY = gCurrentPinballGame->unk3C4[i].y / 10 + 28 + x - gCurrentPinballGame->unk5A;
        } else {
            spriteGroup->baseX = 240;
            spriteGroup->baseY = 180;
        }

        if (r8 == 6)
        {
            u16 scaleX;
            u16 scaleY;
            if (gCurrentPinballGame->unk3AC[i] <= 6) {
                scaleX = (gCurrentPinballGame->unk3AC[i] * 0x80) / 6 + 0x100;
                scaleY = ((6-gCurrentPinballGame->unk3AC[i]) * 0x80) / 6 + 0x80;
            } else {
                scaleX = ((24-gCurrentPinballGame->unk3AC[i]) * 0x170) / 18 + 0x10;
                scaleY = ((gCurrentPinballGame->unk3AC[i]-6) * 0x1C0) / 18 + 0x80;
            }
            SetMatrixScale(scaleX, scaleY, i + 2);
            spriteGroup->baseX -= 16;
            spriteGroup->baseY -= 16;
            for (j = 0; j < 2; j++)
            {
                oamData = &spriteGroup->oam[j];

                dst = (u16*)&gOamBuffer[oamData->oamId];
                src = gUnknown_086BA0A0[sb][j];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamData->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamData->oamId].y += spriteGroup->baseY;
                gOamBuffer[oamData->oamId].tileNum += i * 20;
                gOamBuffer[oamData->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamData->oamId].matrixNum = i + 2;
            }
        }
        else
        {
            for (j = 0; j < 2; j++) 
            {
                oamData = &spriteGroup->oam[j];

                dst = (u16*)&gOamBuffer[oamData->oamId];
                src = gUnknown_086BA0A0[sb][j];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamData->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamData->oamId].y += spriteGroup->baseY;
                gOamBuffer[oamData->oamId].tileNum += i * 20;
            }
        }
    }
}

void sub_34450(void) 
{    
    s16 r9;
    u16 available;
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *spriteGroup;
    
    r9 = 0;
    spriteGroup = &gMain.spriteGroups[14];
    switch(gCurrentPinballGame->unk3DC)
    {
    case 0:
    {
        gCurrentPinballGame->unk3E8 = 880;  
        gCurrentPinballGame->unk3EA = 300;
        gCurrentPinballGame->unk3DC = 1;
        gCurrentPinballGame->unk3E6 = 184;
        gCurrentPinballGame->unk3E2 = 21;
        r9 = 0;
        gCurrentPinballGame->unk294 = 1;
        break;
    }
        
    case 1:
    {
        if (gUnknown_086AE68E[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
            gCurrentPinballGame->unk3E4++; 
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;

            if (gCurrentPinballGame->unk3E2 > 28)
            {
                gCurrentPinballGame->unk3E2 = 21;
            
                if (gCurrentPinballGame->unk3E0 <= 0)
                    gCurrentPinballGame->unk3E0++;
                else
                {
                    gCurrentPinballGame->unk3E0 = 0;
                    gCurrentPinballGame->unk3DC = 2;
                }
            }
            
            if (gCurrentPinballGame->unk3E2 == 23)
            {
                gCurrentPinballGame->unk129 = 0;
                gCurrentPinballGame->unk128 = 1;
                m4aSongNumStart(SE_UNKNOWN_0xF4); //Dusclops entry; footstops
                sub_11B0(8);                    
            }
            
            if (gCurrentPinballGame->unk3E2 == 27)
            {
                gCurrentPinballGame->unk129 = 1;
                gCurrentPinballGame->unk128 = 1;
                m4aSongNumStart(SE_UNKNOWN_0xF4); //Dusclops entry; footstops
                sub_11B0(8);

            }
        }
        
        r9 = 0;    
        break;
    }
    case 2:
    {
        if (gCurrentPinballGame->unk3E4 <= 255)
        {
            r9 = gUnknown_08137D40[(gCurrentPinballGame->unk3E4 % 0x40) / 16];
            gCurrentPinballGame->unk3E4++;
            
            if (gCurrentPinballGame->unk3E4 == 256)
            {
                gCurrentPinballGame->unk3DC = 3;
                gCurrentPinballGame->unk3E4 = 0;
                
                if (gCurrentPinballGame->unk3E0 > 3)
                    gCurrentPinballGame->unk3E0 = 0;
                if (gCurrentPinballGame->unk3E0 <= 1)
                    gCurrentPinballGame->unk3E2 = 0;
                else
                    gCurrentPinballGame->unk3E2 = 7;
            }
        }
        
        if (gCurrentPinballGame->unk3E6 > 0)
        {
            if (gCurrentPinballGame->unk3E6 > 64)
                gCurrentPinballGame->unk3E6 -= 1;
            else
                gCurrentPinballGame->unk3E6 -= 2;

            if (gCurrentPinballGame->unk3E6 == 154)
                m4aSongNumStart(SE_UNKNOWN_0xF5); //Dusclops Appears
        }
        else
        {
            gCurrentPinballGame->unk387 = 2;
            gCurrentPinballGame->unk294 = 2;
        }
        
        break;
    }
    case 3:
    {
        if (gUnknown_086AE68E[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
        {    
            gCurrentPinballGame->unk3E4++; 
        }
        else 
        {
            gCurrentPinballGame->unk3E4 = 0;

            if (gCurrentPinballGame->unk3E0 <= 1)
            {
                gCurrentPinballGame->unk3E2++;

                if (gCurrentPinballGame->unk3E2 > 7)
                {
                    gCurrentPinballGame->unk3E2 = 0;
                    gCurrentPinballGame->unk3E0++;
              
                    if ((gCurrentPinballGame->unk3E0 & 1) == 0)
                    {
                        gCurrentPinballGame->unk3DC = 2;
                        gCurrentPinballGame->unk3E4 = 0;
                    }
                }
            }
            else if (--gCurrentPinballGame->unk3E2 < 0)
            {                
                gCurrentPinballGame->unk3E0++;
                
                if ((gCurrentPinballGame->unk3E0 & 1) == 0)
                {
                    gCurrentPinballGame->unk3DC = 2;
                    gCurrentPinballGame->unk3E4 = 0;
                    gCurrentPinballGame->unk3E2 = 0;
                }
                else
                    gCurrentPinballGame->unk3E2 = 7;
            }

            if (gCurrentPinballGame->unk3E2 == 2)
            {
                gCurrentPinballGame->unk129 = 0;
                gCurrentPinballGame->unk128 = 1; 
                m4aSongNumStart(SE_UNKNOWN_0xF4); //Dusclops entry; footstops
                sub_11B0(8);    
            }
            
            if (gCurrentPinballGame->unk3E2 == 6)
            {
                gCurrentPinballGame->unk129 = 1;                
                gCurrentPinballGame->unk128 = 1; 
                m4aSongNumStart(SE_UNKNOWN_0xF4); //Dusclops entry; footstops
                sub_11B0(8);
            }
        }

        r9 = gUnknown_086AE68E[gCurrentPinballGame->unk3E2][0];
        
        if((gCurrentPinballGame->unk3E2  == 0) || (gCurrentPinballGame->unk3E2 == 4))
        {
            break;
        }
        
        if (gCurrentPinballGame->unk3E0 <= 1)
        {
            if (gCurrentPinballGame->unk3EA <= 583)
            {
                gCurrentPinballGame->unk3EA++;
                break;
            }

            if ((gCurrentPinballGame->unk3E2 % 4) != 0)
                break;
            
            gCurrentPinballGame->unk3DC = 2;
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2 = 0;
            gCurrentPinballGame->unk3E0 = 2;
            break;
        }

        if (gCurrentPinballGame->unk3EA > 300)
        {
            gCurrentPinballGame->unk3EA--;
            break;
        }
        
        if ((gCurrentPinballGame->unk3E2 % 4) != 0)
            break;
        
        gCurrentPinballGame->unk3DC = 2;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3E2 = 0;
        gCurrentPinballGame->unk3E0 = 4;
    
        break;
    }
    case 4:
    {
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3E2 = 0;
        gCurrentPinballGame->unk3DC = 5;
        r9 = 7;
        
        m4aSongNumStart(SE_UNKNOWN_0xF6); //Dusclops hit
        gCurrentPinballGame->unk387 = 0;
        sub_11B0(7);
        break;
    }
    case 5:
    {
        if (gCurrentPinballGame->unk3E4 <= 27)
        {
            r9 = 7;
            gCurrentPinballGame->unk3E4++;
            break;
        }

        if (gCurrentPinballGame->unk385 <= 3)
        {
            gCurrentPinballGame->unk3E4 = 128;
            gCurrentPinballGame->unk3E2 = 0;
            gCurrentPinballGame->unk3DC = 2;
            gCurrentPinballGame->unk387 = 0;
            r9 = 7;
        }
        else
        {
            gCurrentPinballGame->unk3DC = 8;
            r9 = 7;
        }
        
        gCurrentPinballGame->unk385++;
        gCurrentPinballGame->unk3C = 300000;
        
        break;
    }
    case 6:
    {
        struct Vector16 tempVector;
        
        gCurrentPinballGame->unk3E2 = 9;
        gCurrentPinballGame->unk3E4 = 0;
        gCurrentPinballGame->unk3DC = 7;
        gCurrentPinballGame->unk5A6 = 0;
        r9 = 8;
        
        m4aSongNumStart(SE_UNKNOWN_0xF7); //Dusclops absorbs ball
        gCurrentPinballGame->unk288 = (gCurrentPinballGame->unk3E8 / 10) + 32;
        gCurrentPinballGame->unk28A = (gCurrentPinballGame->unk3EA / 10) + 36;
        
        tempVector.x = (gCurrentPinballGame->unk288 << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->unk28A << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->unk5AC = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
        gCurrentPinballGame->unk5AC = Sqrt(gCurrentPinballGame->unk5AC * 4) / 2;
        gCurrentPinballGame->unk5B0 = ArcTan2(-tempVector.x, tempVector.y);
        
        sub_11B0(13);
        break;
    }
    case 7:
    {
        if (gUnknown_086AE68E[gCurrentPinballGame->unk3E2][1] > gCurrentPinballGame->unk3E4)
            gCurrentPinballGame->unk3E4++;
        else
        {
            gCurrentPinballGame->unk3E4 = 0;
            gCurrentPinballGame->unk3E2++;
            
            if (gCurrentPinballGame->unk3E2 == 15)
            {
                gCurrentPinballGame->ball->velocity.x = (gMain.systemFrameCount % 2 * 300) + 65386; 
                gCurrentPinballGame->ball->velocity.y = 300;
                gCurrentPinballGame->ball->unk0 = 0;
                m4aSongNumStart(SE_UNKNOWN_0xF8); //Dusclops launch ball
                sub_11B0(8);
            }
            
            if (gCurrentPinballGame->unk3E2 == 16)
                gCurrentPinballGame->unk1F = 0;
            
            if (gCurrentPinballGame->unk3E2 > 16)
            {
                gCurrentPinballGame->unk3E4 = 128;
                gCurrentPinballGame->unk3E2 = 0;
                gCurrentPinballGame->unk3DC = 2;
            }
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            if ((gCurrentPinballGame->unk3E2 == 16) && (gCurrentPinballGame->unk3E4 > 4))
                gCurrentPinballGame->unk387 = 2;
        }
        else
        {
            if ((gCurrentPinballGame->unk3E2 == 16) && (gCurrentPinballGame->unk3E4 != 0))
                gCurrentPinballGame->unk387 = 2;
        }

        if (gCurrentPinballGame->unk5A6 <= 29)
        {
            s16 tr4 = 29 - gCurrentPinballGame->unk5A6;
            s32 sl;
            
            gCurrentPinballGame->unk5B0 -= ((tr4 * 8192) / 30) - 8192;
            gCurrentPinballGame->ball->unkA = gCurrentPinballGame->ball->unkA - 8192;
            
            sl = (gCurrentPinballGame->unk5AC * tr4) / 30;
            
            gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->unk288 * 256) + ((Cos(gCurrentPinballGame->unk5B0) * sl) / 20000);
            
            gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unk28A * 256) - ((Sin(gCurrentPinballGame->unk5B0) * sl) / 20000);
            
            gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
            gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        }

        if (gCurrentPinballGame->unk5A6 == 40)
        {
            gCurrentPinballGame->ball->unk0 = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        gCurrentPinballGame->unk5A6++;
        r9 = gUnknown_086AE68E[gCurrentPinballGame->unk3E2][0];
        
        break;
    }
    case 8:
    {
        gCurrentPinballGame->unk294 = 3;
        gMain.unkF = 128;

        if (gCurrentPinballGame->unk3E6 == 0)
        {
            gCurrentPinballGame->unk388 = 2;
            gCurrentPinballGame->unk392 = 0;
        }
        
        r9 = 15;

        if (gCurrentPinballGame->unk3E6 <= 183)
        {
            if (gCurrentPinballGame->unk3E6 <= 63)
                gCurrentPinballGame->unk3E6++;
            else
                gCurrentPinballGame->unk3E6 += 2;

            if (gCurrentPinballGame->unk3E6 == 30)
            {
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_086A17D8);
            }
            break;
        }
        
        gMain.spriteGroups[13].available = 0;
        gMain.spriteGroups[14].available = 0;
        gMain.spriteGroups[12].available = 0;
        gCurrentPinballGame->unk13 = 4;
        gCurrentPinballGame->unk18 = 0;
        break;
    } 
    default:
        break;
    } //End switch
    
    DmaCopy16(3 , gUnknown_084EDACC + r9 * 1024,(void *)OBJ_VRAM0+0x10a0, BG_SCREEN_SIZE);

    gCurrentPinballGame->unk3F0 = ((gCurrentPinballGame->unk3E8 / 10) * 2) + 16;
    gCurrentPinballGame->unk3F2 = ((gCurrentPinballGame->unk3EA / 10) * 2) + 16;

    if(spriteGroup->available != 0)
    {
        struct OamDataSimple *new_var;
        spriteGroup->baseX = (-gCurrentPinballGame->unk58) + (gCurrentPinballGame->unk3E8 / 10);
        spriteGroup->baseY = (-gCurrentPinballGame->unk5A) + (gCurrentPinballGame->unk3EA / 10);

        oamSimple = spriteGroup->oam;
        if (r9 == 7)
        {
            if (gCurrentPinballGame->unk3E4 <= 5)
                gOamBuffer[oamSimple->oamId].paletteNum = 4;
            else
                gOamBuffer[oamSimple->oamId].paletteNum = 3;
        }
        else
            gOamBuffer[oamSimple->oamId].paletteNum = 3;
        
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
    }

    spriteGroup = &gMain.spriteGroups[12];
    if (spriteGroup->available != 0)
    {
        if (gCurrentPinballGame->unk386 == 0)
        {
            u32 offY = 92;
            
            spriteGroup->baseX = -gCurrentPinballGame->unk58 + (gCurrentPinballGame->unk3E8 / 10);
            spriteGroup->baseY = -gCurrentPinballGame->unk5A + (gCurrentPinballGame->unk3EA / 10) 
                + ((gCurrentPinballGame->unk3E6 / 2) - offY);
        }
        else
        {
            spriteGroup->baseX = 240;
            spriteGroup->baseY = 160;
        }
     
        {         
            s16 i;
            u8 r1;
            r1 = gMain.systemFrameCount % 4;
            DmaCopy16(3 , gUnknown_08494E4C + r1 / 2 * 0x600, (void *)OBJ_VRAM0 + 0x1aa0, 0xc00);

            for (i = 0; i < 2; i++)
            {
                oamSimple = &spriteGroup->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
            }            
        }
    }

    spriteGroup = &gMain.spriteGroups[13];

    if (spriteGroup->available != 0)
    {
        s32 offX = 16;
        s32 offY = 20;
        spriteGroup->baseX = gCurrentPinballGame->unk3E8 / 10 + offX - gCurrentPinballGame->unk58;
        if (gCurrentPinballGame->unk3E2 >= 10 && gCurrentPinballGame->unk3E2 <= 12)
        {
            s16 r0;
            spriteGroup->baseY = ((gCurrentPinballGame->unk3EA / 10) + offY) - gCurrentPinballGame->unk5A;
            r0 = gCurrentPinballGame->unk5A6 % 24;
            if(r0 <= 10)
                r9 = 0;
            else if (r0 <= 17)
                r9 = 1;
            else
                r9 = 2;
            
            DmaCopy16(3 , gUnknown_084FF30C + r9 * 0x200,(void *)OBJ_VRAM0+0x18a0, 0x200);
        }
        else
        {
            spriteGroup->baseY = 180;
        }

        oamSimple = spriteGroup->oam;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
    }
}
