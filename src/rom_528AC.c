#include "global.h"
#include "m4a.h"
#include "agb_sram.h"
#include "main.h"
#include "constants/species_rs.h"

extern const u16 gSpeciesRSToCryId[];

static void PlayCryInternal(u16, s8, s8, u8, int);
static u16 LoadSaveDataFromSram(void);

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

void SaveFile_LoadGameData(void)
{
    SetSramFastFunc();
    gMain.unkC = 0;
    if (LoadSaveDataFromSram() == 0)
    {
        sub_52C64();
        SaveFile_WriteToSram();
        if (LoadSaveDataFromSram() == 0)
        {
            gMain.unkC = 1;
            sub_52C64();
        }
    }
    else
    {
        sub_525CC(gMain_saveData.buttonConfigType);
    }
}

extern u8 gSaveFileSignature[];

static u16 LoadSaveDataFromSram(void)
{
    u16 isOk = FALSE;
    u16 fileNum;
    u16 i;
    u32 checksum;

    // Looks like there are two copies of the save data, one used as a backup?
    for (fileNum = 0; fileNum < 2; fileNum++)
    {
        u16 *saveData = (u16 *)&gMain_saveData;
        size_t size = sizeof(gMain_saveData);

        ReadSramFast((void *)(SRAM + 0x4 + fileNum * 672), (u8 *)saveData, size);

        // Verify signature
        for (i = 0; i < 10; i++)
        {
            if (gMain_saveData.signature[i] != gSaveFileSignature[i])
                break;
        }
        if (i != 10)
            continue;

        // Verify checksum
        checksum = 0;
        while (size > 1)
        {
            checksum += *saveData++;
            size -= 2;
        }
        if (size != 0)  // never happens (size is even)
            checksum += *saveData & 0xFF00;
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
        if (checksum == 0xFFFF)
        {
            isOk = TRUE;
            break;
        }
    }
    return isOk;
}

void SaveFile_WriteToSram(void)
{
    u32 checksum;
    u16 *saveData = (u16 *)&gMain_saveData;
    size_t size = sizeof(gMain_saveData);

    gMain_saveData.unk2E4++;
    gMain_saveData.checksum = 0;

    checksum = 0;
    while (size > 1)
    {
        checksum += *saveData++;
        size -= 2;
    }
    if (size != 0)  // never happens (size is even)
        checksum += *saveData & 0xFF00;
    checksum = (checksum & 0xFFFF) + (checksum >> 16);
    gMain_saveData.checksum = ~((checksum >> 16) + checksum);

    WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x4),   sizeof(gMain_saveData));
    WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x2A4), sizeof(gMain_saveData));
}

void SaveFile_SetPokedexFlags(s16 species, u8 flag)
{
    u16 *saveData = (u16 *)&gMain_saveData;
    size_t size = sizeof(gMain_saveData);
    u32 checksum;

    if (gMain_saveData.pokedexFlags[species] < flag)
    {
        gMain_saveData.unk2E4++;
        gMain_saveData.pokedexFlags[species] = flag;
        gMain_saveData.checksum = 0;

        checksum = 0;
        while (size > 1)
        {
            checksum += *saveData++;
            size -= 2;
        }
        if (size != 0)  // never happens (size is even)
            checksum += *saveData & 0xFF00;
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
        gMain_saveData.checksum = ~((checksum >> 16) + checksum);

        WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x4),   sizeof(gMain_saveData));
        WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x2A4), sizeof(gMain_saveData));
    }
}

void SaveFile_ReadSavedGamePresent(void)
{
    ReadSramFast((void *)(SRAM + 0x544), (u8 *)&gMain.hasSavedGame, sizeof(gMain.hasSavedGame));
}

void sub_52C64(void)
{
    s16 i;

    for (i = 0; i < 10; i++)
        gMain_saveData.signature[i] = gSaveFileSignature[i];

    gMain_saveData.unk2E4 = 0;
    gMain_saveData.rumbleEnabled = FALSE;
    gMain_saveData.ballSpeed = 0;
    sub_525CC(BUTTON_CONFIG_RESET);
    SetDefaultHighScores();
    ResetPokedex();
    gMain_saveData.buttonConfigType = BUTTON_CONFIG_TYPE_A;
}
