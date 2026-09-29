#include "global.h"
#include "m4a.h"
#include "agb_sram.h"
#include "main.h"
#include "constants/species_rs.h"

extern const u16 gSpeciesRSToCryId[];
extern struct ToneData gPokemonCryToneBank0[];
extern struct ToneData gPokemonCryToneBank1[];
extern struct ToneData gPokemonCryToneBank2[];
extern struct ToneData gPokemonCryToneBank3[];

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
        SetPokemonCryTone(&gPokemonCryToneBank0[index]);
        break;
    case 1:
        SetPokemonCryTone(&gPokemonCryToneBank1[index]);
        break;
    case 2:
        SetPokemonCryTone(&gPokemonCryToneBank2[index]);
        break;
    case 3:
        SetPokemonCryTone(&gPokemonCryToneBank3[index]);
        break;
    }
}
