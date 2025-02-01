#include "global.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"

extern const u16 gWildMonLocations[][2][8];
extern const u16 gUnknown_086A4A38[2][26];

static inline u32 GetTimeAdjustedRandom()
{
    return Random() + (gMain.systemFrameCount + gMain.fieldFrameCount);
}

void sub_31F6C(void)
{
    s16 threeArrows;
    s16 i;
    s16 j;
    s16 weight;
    s16 currentSpecies;
    s16 evolutionWeight;

    gUnknown_020314E0->unk12E = 0;
    if (gUnknown_020314E0->unk73D == 3)
        threeArrows = 1;
    else
        threeArrows = 0;

    for (i = 0; i < 8; i++)
    {
        currentSpecies = gWildMonLocations[gUnknown_020314E0->area][threeArrows][i];
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
                if (gMain.eReaderBonus[EREADER_ENCOUNTER_RATE_UP_CARD])
                {
                    if (gMain_saveData.pokedexFlags[currentSpecies] < 2)
                        weight = 2;
                    else
                        weight = 4;
                }
                else
                {
                    if (gMain_saveData.pokedexFlags[currentSpecies] < 2)
                        weight = 1;
                    else
                        weight = 2;
                }

                if (gUnknown_020314E0->unk5F0 == 0)
                    weight = 0;
                break;
            
            case SPECIES_CLAMPERL:
                weight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_CLAMPERL]];
                evolutionWeight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_HUNTAIL]];
                if (weight < evolutionWeight)
                {
                    weight = evolutionWeight;
                }
                evolutionWeight = gCommonAndEggWeights[gMain_saveData.pokedexFlags[SPECIES_GOREBYSS]];
                if (weight < evolutionWeight)
                {
                    weight = evolutionWeight;
                }

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
                currentSpecies = gWildMonLocations[gUnknown_020314E0->area][threeArrows][i];
                if (gUnknown_020314E0->unk5F0 == 0 && gSpeciesInfo[currentSpecies].evolutionTarget >= SPECIES_NONE)
                {
                    weight = 0;
                }
                break;
        }

        if (gUnknown_020314E0->unk59C == currentSpecies)
        {
            weight = 0;
        }
        gUnknown_020314E0->unk12E += weight;
        gUnknown_020314E0->unk130[i] = gUnknown_020314E0->unk12E;
    }
}

void sub_3219C(void)
{
    s16 i;
    u32 rand;
    u16 specialMons[6];

    if (gMain.eReaderBonus[EREADER_SPECIAL_GUESTS_CARD])
    {
        gMain.eReaderBonus[EREADER_SPECIAL_GUESTS_CARD] = 0;
        rand = GetTimeAdjustedRandom();
        rand %= NUM_BONUS_SPECIES;
        for (i = 0; i < NUM_BONUS_SPECIES; i++)
        {
            if (gMain_saveData.pokedexFlags[BONUS_SPECIES_START + ((i + rand) % NUM_BONUS_SPECIES)] < 4)
                break;
        }

        gUnknown_020314E0->unk598 = BONUS_SPECIES_START + ((i + rand) % NUM_BONUS_SPECIES);
    }
    else
    {
        rand = GetTimeAdjustedRandom();
        if (gMain.eReaderBonus[EREADER_ENCOUNTER_RATE_UP_CARD])
            rand %= 50;
        else
            rand %= 100;

        if (gUnknown_02031520.unk8 < 100)
            rand = 1;

        if ((rand == 0 && gUnknown_020314E0->unk5F0 >= 5) || gUnknown_020314E0->unk12B)
        {
            s16 numSpecialMons = 0;
            gUnknown_020314E0->unk598 = 0;
            if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL])
            {
                specialMons[numSpecialMons++] = SPECIES_AERODACTYL;
                if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL] < 4)
                    gUnknown_020314E0->unk598 = SPECIES_AERODACTYL;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA])
            {
                specialMons[numSpecialMons++] = SPECIES_CHIKORITA;
                if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA] < 4)
                    gUnknown_020314E0->unk598 = SPECIES_CHIKORITA;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE])
            {
                specialMons[numSpecialMons++] = SPECIES_TOTODILE;
                if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE] < 4)
                    gUnknown_020314E0->unk598 = SPECIES_TOTODILE;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL])
            {
                specialMons[numSpecialMons++] = SPECIES_CYNDAQUIL;
                if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL] < 4)
                    gUnknown_020314E0->unk598 = SPECIES_CYNDAQUIL;
            }

            if (gMain.selectedField == FIELD_RUBY)
            {
                specialMons[numSpecialMons++] = SPECIES_LATIOS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIOS] < 4)
                    gUnknown_020314E0->unk598 = SPECIES_LATIOS;
            }
            else
            {
                specialMons[numSpecialMons++] = SPECIES_LATIAS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIAS] < 4)
                    gUnknown_020314E0->unk598 = SPECIES_LATIAS;
            }

            if (!gUnknown_020314E0->unk598)
            {
                rand = GetTimeAdjustedRandom();
                rand %= numSpecialMons;
                gUnknown_020314E0->unk598 = specialMons[rand];
            }
        }
        else
        {
            s16 threeArrows;
            if (gUnknown_020314E0->unk73D == 3)
                threeArrows = 1;
            else
                threeArrows = 0;

            rand = GetTimeAdjustedRandom();
            rand %= gUnknown_020314E0->unk12E;
            for (i = 0; i < 8 && gUnknown_020314E0->unk130[i] <= rand; i++);

            gUnknown_020314E0->unk598 = gWildMonLocations[gUnknown_020314E0->area][threeArrows][i];
        }
    }

    gUnknown_020314E0->unk59C = gUnknown_020314E0->unk598;
}

void sub_32484(void)
{
    s16 i;
    s16 currentSpecies;
    s16 weight;
    s16 j;
    s16 evolutionWeight;

    gUnknown_020314E0->unk12E = 0;

    for (i = 0; i < 0x19; i++)
    {   
        currentSpecies = gUnknown_086A4A38[gMain.selectedField][i];

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
            
            currentSpecies = gUnknown_086A4A38[gMain.selectedField][i];
            if (gUnknown_020314E0->unk5F0 == 0)
            {
                if (gSpeciesInfo[currentSpecies].evolutionTarget >= SPECIES_NONE)
                {
                    weight = 0;
                }
            }
        }

        if (gUnknown_020314E0->unk59E == currentSpecies)
        {
            weight = 0;
        }

        gUnknown_020314E0->unk12E += weight;
        gUnknown_020314E0->unk130[i] = gUnknown_020314E0->unk12E;
    }
}

void sub_325E0(void)
{
    s16 i;
    u32 rand;
    
    rand = GetTimeAdjustedRandom();
    if (gMain.eReaderBonus[EREADER_ENCOUNTER_RATE_UP_CARD])
        rand %= 100;
    else
        rand %= 50;
    
    if (gUnknown_020314E0->unk59E == SPECIES_PICHU)
        rand = 1;
    
    if ((rand == 0 && gUnknown_020314E0->unk5F0 >= 5) || gUnknown_020314E0->unk12C)
    {
        gUnknown_020314E0->unk598 = SPECIES_PICHU;
    }
    else
    {
        rand = GetTimeAdjustedRandom();
        rand %= gUnknown_020314E0->unk12E;
        
        for (i = 0; i < 25 && gUnknown_020314E0->unk130[i] <= rand; i++);
        
        gUnknown_020314E0->unk598 = gUnknown_086A4A38[gMain.selectedField][i];
    }
    
    gUnknown_020314E0->unk59E = gUnknown_020314E0->unk598;
}

void sub_326F4(void)
{
    gUnknown_020314E0->unk73D = 2;
    gUnknown_020314E0->unk1E5 = 0;
    gUnknown_020314E0->unk1E6 = 1;
    
    sub_1F2A4();
    sub_21B0C();
    sub_1F59C();
    sub_300D8();
    sub_30178();
    
    gUnknown_020314E0->unk1D8 = 0x100;
    gUnknown_020314E0->unk1DA = 0x100;
    
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
    
    if (gUnknown_020314E0->unk29C)
    {
        gUnknown_020314E0->unk29C--;
        if (!gUnknown_020314E0->unk29C)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM,0xffff,0x100);
    }
}

void sub_327C0(void)
{
    s32 temp;
    
    sub_4F814();
    sub_1A0F4();
    sub_2CA9C();
    
    if (gUnknown_020314E0->unk68 < 0x5a)
    {
        sub_304C8();
        sub_31498();
    }
    
    if (gUnknown_020314E0->unk13 < 3)
    {
        if ((gUnknown_020314E0->unk344 & 0xFFFF00) == 0x300)
        {
            gUnknown_020314E0->unk728 = 1;
        }
        else
        {
            gUnknown_020314E0->unk728 = 0;
        }
    }
    else
    {
        gUnknown_020314E0->unk728 = 0;
    }
    
    if (gUnknown_020314E0->unk68 < 0x96)
    {
        sub_2E6AC();
        sub_313A0();
    }
    if (gUnknown_020314E0->unk68 < 0xC4)
    {
        sub_30178();
        sub_2F140();
    }
    if (gUnknown_020314E0->unk68 < 0xCA)
    {
        sub_2FCD0();
    }
    if (gUnknown_020314E0->unk68 < 0xDC)
    {
        sub_1F59C();
    }
    
    sub_308DC();
    
    if (0x76 < gUnknown_020314E0->unk68)
    {
        sub_2F504();
        sub_30EB4();
    }
    
    sub_2CE80();
    
    if (0xA8 < gUnknown_020314E0->unk68)
        sub_2D104();
    
    sub_203CC();
    sub_21B0C();
    sub_1D128();
    sub_31B30();
    
    if (gUnknown_020314E0->unk194)
        sub_225F0();
    
    sub_472E4();
}

void sub_328C8(void)
{
    sub_300D8();
    sub_32968();
    sub_1F2A4();
    
    if (gUnknown_020314E0->unk600)
        gUnknown_020314E0->unk600--;
    
    sub_2F26C();
    sub_2E67C();
    sub_31144();
    
    if (!(gMain.unkF & 0x20))
        sub_2F79C();
}

void sub_32914(void)
{
    if (!gMain.unkF)
    {
        switch (gUnknown_020314E0->unk25)
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
        
        gUnknown_020314E0->unk26 = 0x3C;
    }
}

void sub_32968(void)
{
    if (gUnknown_020314E0->unk26)
        gUnknown_020314E0->unk26--;
    
    switch (gUnknown_020314E0->unk25)
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
    gUnknown_020314E0->unk28 = 0xB4;
    gUnknown_020314E0->unk1BA = 0xB4;
    gUnknown_020314E0->unk3C = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gUnknown_020314E0->unk5F7 = 1;
}
