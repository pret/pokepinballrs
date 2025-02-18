#include "global.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/bg_music.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"

extern const u16 gWildMonLocations[][2][8];
extern const u16 gEggLocations[2][26];

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

    gCurrentPinballGame->unk12E = 0;
    if (gCurrentPinballGame->catchModeArrows == 3)
        threeArrows = 1;
    else
        threeArrows = 0;

    for (i = 0; i < 8; i++)
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
        gCurrentPinballGame->unk12E += weight;
        gCurrentPinballGame->unk130[i] = gCurrentPinballGame->unk12E;
    }
}

void sub_3219C(void)
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
            if (gMain_saveData.pokedexFlags[BONUS_SPECIES_START + ((i + rand) % NUM_BONUS_SPECIES)] < 4)
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
                if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL] < 4)
                    gCurrentPinballGame->currentSpecies = SPECIES_AERODACTYL;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA])
            {
                specialMons[numSpecialMons++] = SPECIES_CHIKORITA;
                if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA] < 4)
                    gCurrentPinballGame->currentSpecies = SPECIES_CHIKORITA;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE])
            {
                specialMons[numSpecialMons++] = SPECIES_TOTODILE;
                if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE] < 4)
                    gCurrentPinballGame->currentSpecies = SPECIES_TOTODILE;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL])
            {
                specialMons[numSpecialMons++] = SPECIES_CYNDAQUIL;
                if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL] < 4)
                    gCurrentPinballGame->currentSpecies = SPECIES_CYNDAQUIL;
            }

            if (gMain.selectedField == FIELD_RUBY)
            {
                specialMons[numSpecialMons++] = SPECIES_LATIOS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIOS] < 4)
                    gCurrentPinballGame->currentSpecies = SPECIES_LATIOS;
            }
            else
            {
                specialMons[numSpecialMons++] = SPECIES_LATIAS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIAS] < 4)
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
            rand %= gCurrentPinballGame->unk12E;
            for (i = 0; i < 8 && gCurrentPinballGame->unk130[i] <= rand; i++);

            gCurrentPinballGame->currentSpecies = gWildMonLocations[gCurrentPinballGame->area][threeArrows][i];
        }
    }

    gCurrentPinballGame->lastCatchSpecies = gCurrentPinballGame->currentSpecies;
}

void sub_32484(void)
{
    s16 i;
    s16 currentSpecies;
    s16 weight;
    s16 j;
    s16 evolutionWeight;

    gCurrentPinballGame->unk12E = 0;

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

        gCurrentPinballGame->unk12E += weight;
        gCurrentPinballGame->unk130[i] = gCurrentPinballGame->unk12E;
    }
}

void sub_325E0(void)
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
        rand %= gCurrentPinballGame->unk12E;

        for (i = 0; i < 25 && gCurrentPinballGame->unk130[i] <= rand; i++);

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

    if (gCurrentPinballGame->progressForBonus < 3)
    {
        if ((gCurrentPinballGame->unk344 & 0xFFFF00) == 0x300)
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
        gCurrentPinballGame->unk132c->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->unk132c->unk30 = 0;
        gCurrentPinballGame->unk132c->unk32 = 0;
        gCurrentPinballGame->unk132c->unk10 = 58;
        gCurrentPinballGame->unk132c->unk12 = 178;
        gCurrentPinballGame->unk132c->unk28 = gCurrentPinballGame->unk132c->unk10 * 2;
        gCurrentPinballGame->unk132c->unk2A = gCurrentPinballGame->unk132c->unk12 * 2;
        gCurrentPinballGame->unk132c->unk34 = gCurrentPinballGame->unk132c->unk10 * 256;
        gCurrentPinballGame->unk132c->unk38 = gCurrentPinballGame->unk132c->unk12 * 256;
        
        if (gCurrentPinballGame->unk28 <= 0x31)
        {
            gCurrentPinballGame->unk28++;
        }

        sub_1B140(gCurrentPinballGame->unk1A5);

        if(gCurrentPinballGame->unk1A5)
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
        gCurrentPinballGame->unk132c->unk0 = 0;
        gCurrentPinballGame->unk1F = 0;
        gCurrentPinballGame->unk26 = 0x3C;
        gCurrentPinballGame->unk132c->unk30 = 0x60;
        gCurrentPinballGame->unk132c->unk32 = 0xC0;
        gCurrentPinballGame->unk132c->unk10 = 0x3C;
        gCurrentPinballGame->unk132c->unk12 = 0xB4;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->unk132c->unk28 = gCurrentPinballGame->unk132c->unk10 * 2;
        gCurrentPinballGame->unk132c->unk2A = gCurrentPinballGame->unk132c->unk12 * 2;
        gCurrentPinballGame->unk25 = 0;

        m4aSongNumStart(SE_UNKNOWN_0xC3);
        
        if (gCurrentPinballGame->unk72E > 2 && gCurrentPinballGame->unk281 > 0) {
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
    if(gCurrentPinballGame->unk28)
    {
        gCurrentPinballGame->unk5F7 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->unk132c->unk30 = 0;
        gCurrentPinballGame->unk132c->unk32 = 0;
        gCurrentPinballGame->unk132c->unk6 = 0;
        if(gCurrentPinballGame->unk28 > 0x61)
        {
            gCurrentPinballGame->unk5FA = 1;
            gCurrentPinballGame->unk2F4 = 2;
            gCurrentPinballGame->unk132c->unk10 = 0xb5;
            gCurrentPinballGame->unk132c->unk12 = 0xc3;
        }
        else if(gCurrentPinballGame->unk28 > 0x5e)
        {
            gCurrentPinballGame->unk2F4 = 3;
            gCurrentPinballGame->unk132c->unk10 = 0xb8;
            gCurrentPinballGame->unk132c->unk12 = 0xbb;
        }
        else if(gCurrentPinballGame->unk28 > 0x5b)
        {
            gCurrentPinballGame->unk132c->unk0 = 1;
            gCurrentPinballGame->unk2F4 = 4;
        }
        else if(gCurrentPinballGame->unk28 > 0x53)
        {
            gCurrentPinballGame->unk2F4 = 5;
        }
        else if(gCurrentPinballGame->unk28 > 0x22)
        {
            gCurrentPinballGame->unk2F4 = 6;

        }
        else if(gCurrentPinballGame->unk28 > 0x1a)
        {
            gCurrentPinballGame->unk2F4 = 7;

        }
        else if(gCurrentPinballGame->unk28 > 0x12)
        {
            gCurrentPinballGame->unk2F4 = 8;

        }
        else if(gCurrentPinballGame->unk28 > 0xa)
        {
            gCurrentPinballGame->unk2F4 = 9;
            
        }
        else if(gCurrentPinballGame->unk28 > 0x4)
        {
            gCurrentPinballGame->unk132c->unk0 = 0;
            gCurrentPinballGame->unk2F4 = 10;
            gCurrentPinballGame->unk132c->unk10 = 0xb5;
            gCurrentPinballGame->unk132c->unk12 = 0xc3;
        }
        else
        {
            gCurrentPinballGame->unk2F4 = 11;
            gCurrentPinballGame->unk132c->unk10 = 0xb0;
            gCurrentPinballGame->unk132c->unk12 = 0xca;
        }

        gCurrentPinballGame->unk132c->unk28 = gCurrentPinballGame->unk132c->unk10 * 2;
        gCurrentPinballGame->unk132c->unk2A = gCurrentPinballGame->unk132c->unk12 * 2;
        gCurrentPinballGame->unk132c->unk34 = gCurrentPinballGame->unk132c->unk10 * 256;
        gCurrentPinballGame->unk132c->unk38 = gCurrentPinballGame->unk132c->unk12 * 256;
    }
    else
    {
        gCurrentPinballGame->unk2F4 = 0;
        gCurrentPinballGame->unk1F = 0;
        gCurrentPinballGame->unk26 = 0x3C;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->unk30 = 0xFF9A;
        gCurrentPinballGame->unk132c->unk32 = 0xC8;
        sub_11B0(7);
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->unk10 = 0xAB;
        gCurrentPinballGame->unk132c->unk12 = 0xD4;
        gCurrentPinballGame->unk132c->unk28 = gCurrentPinballGame->unk132c->unk10 * 2;
        gCurrentPinballGame->unk132c->unk2A = gCurrentPinballGame->unk132c->unk12 * 2;
        gCurrentPinballGame->unk132c->unk2C = *(u32*)&gCurrentPinballGame->unk132c->unk28;
        gCurrentPinballGame->unk25 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        m4aSongNumStart(SE_UNKNOWN_0xD6);
        gCurrentPinballGame->unk5FE = 0;
        gCurrentPinballGame->unk5FB = 1;
        gCurrentPinballGame->unk5FA = 0;
    }
}
