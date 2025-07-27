#include "global.h"
#include "m4a.h"
#include "agb_sram.h"
#include "main.h"
#include "constants/species_rs.h"

extern const u16 gSpeciesRSToCryId[];

static void PlayCryInternal(u16, s8, s8, u8, int);

int SpeciesRSToCryId(u16 speciesRS)
{
    if (speciesRS <= SPECIES_RS_CELEBI - 1)
        return speciesRS;
    if (speciesRS < SPECIES_RS_TREECKO - 1)
        return SPECIES_RS_UNOWN - 1;
    return gSpeciesRSToCryId[speciesRS - (SPECIES_RS_TREECKO - 1)];
}

void PlayCry_Normal(u16 speciesRS, s8 pan)
{
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 153);
    PlayCryInternal(speciesRS, pan, 125, 10, 0);
}

void PlayCry_NormalNoDucking(u16 speciesRS, s8 pan, s8 volume, u8 priority)
{
    PlayCryInternal(speciesRS, pan, volume, priority, 0);
}

// Probably was ported from RS minus the cry mode section.
static void PlayCryInternal(u16 speciesRS, s8 pan, s8 volume, u8 priority, int unused)
{
    u32 release;
    u32 length;
    u32 pitch;
    u32 var;
    u32 index;
    u8 table;

    speciesRS--;

    length = 140;
    release = 0;
    pitch = 15360;

    SetPokemonCryVolume(volume);
    SetPokemonCryPanpot(pan);
    SetPokemonCryPitch(pitch);
    SetPokemonCryLength(length);
    SetPokemonCryProgress(0);
    SetPokemonCryRelease(release);
    SetPokemonCryChorus(0);
    SetPokemonCryPriority(priority);
    var = SpeciesRSToCryId(speciesRS);
    index = var & 0x7F;
    table = var >> 7;
    switch (table)
    {
    case 0:
        SetPokemonCryTone(&gUnknown_08532D6C[index]);
        break;
    case 1:
        SetPokemonCryTone(&gUnknown_08533360[index]);
        break;
    case 2:
        SetPokemonCryTone(&gUnknown_08533960[index]);
        break;
    case 3:
        SetPokemonCryTone(&gUnknown_08533F60[index]);
        break;
    }
}
