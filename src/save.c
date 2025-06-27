#include "global.h"
#include "m4a.h"
#include "agb_sram.h"
#include "main.h"
#include "constants/species_rs.h"

static bool16 LoadSaveDataFromSram(void);

void SaveFile_LoadGameData(void)
{
    SetSramFastFunc();
    gMain.unkC = 0;
    if (LoadSaveDataFromSram() == FALSE)
    {
        ResetSaveFile();
        SaveFile_WriteToSram();
        if (LoadSaveDataFromSram() == FALSE)
        {
            gMain.unkC = 1;
            ResetSaveFile();
        }
    }
    else
    {
        SetButtonConfigInputs(gMain_saveData.buttonConfigType);
    }
}

extern u8 gSaveFileSignature[];

static bool16 LoadSaveDataFromSram(void)
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

void ResetSaveFile(void)
{
    s16 i;

    for (i = 0; i < 10; i++)
        gMain_saveData.signature[i] = gSaveFileSignature[i];

    gMain_saveData.unk2E4 = 0;
    gMain_saveData.rumbleEnabled = FALSE;
    gMain_saveData.ballSpeed = 0;
    SetButtonConfigInputs(BUTTON_CONFIG_RESET);
    SetDefaultHighScores();
    ResetPokedex();
    gMain_saveData.buttonConfigType = BUTTON_CONFIG_TYPE_A;
}
