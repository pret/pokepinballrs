#include "global.h"
#include "m4a.h"
#include "agb_sram.h"
#include "main.h"

extern const u16 gUnknown_08527F18[];

static void sub_52940(u16, s8, s8, u8, int);
static u16 LoadSaveDataFromSram(void);

#ifdef NONMATCHING
// Like sub_C24, it matches except for that damn 'push {lr}/pop {lr}'
int sub_528AC(u16 a)
{
    if (a <= 0xFA)
        return a;
    if (a <= 0x113)
        return 0xC8;
    return gUnknown_08527F18[a - 0x114];
}
#else
NAKED
int sub_528AC(u16 a)
{
    asm_unified("\n\
        lsls r0, r0, #0x10\n\
        lsrs r0, r0, #0x10\n\
        adds r1, r0, #0\n\
        cmp r0, #0xfa\n\
        bls _080528DA\n\
        ldr r0, _080528CC @ =0x00000113\n\
        cmp r1, r0\n\
        bls _080528D8\n\
        ldr r0, _080528D0 @ =gUnknown_08527F18\n\
        ldr r2, _080528D4 @ =0xFFFFFEEC\n\
        adds r1, r1, r2\n\
        lsls r1, r1, #1\n\
        adds r1, r1, r0\n\
        ldrh r0, [r1]\n\
        b _080528DA\n\
        .align 2, 0\n\
_080528CC: .4byte 0x00000113\n\
_080528D0: .4byte gUnknown_08527F18\n\
_080528D4: .4byte 0xFFFFFEEC\n\
_080528D8:\n\
        movs r0, #0xc8\n\
_080528DA:\n\
        bx lr");
}
#endif

void sub_528DC(u16 a, s8 b)
{
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x99);
    sub_52940(a, b, 0x7D, 10, 0);
}

void sub_5291C(u16 a, s8 b, s8 c, u8 d)
{
    sub_52940(a, b, c, d, 0);
}

static void sub_52940(u16 a, s8 b, s8 c, u8 d, int unused)
{
    u16 r5 = a - 1;
    u32 pitch = 0x3C00;
    u32 var;
    u32 r1;
    u8 r0;

    SetPokemonCryVolume(c);
    SetPokemonCryPanpot(b);
    SetPokemonCryPitch(pitch);
    SetPokemonCryLength(0x8C);
    SetPokemonCryProgress(0);
    SetPokemonCryRelease(0);
    SetPokemonCryChorus(0);
    SetPokemonCryPriority(d);
    var = sub_528AC(r5);
    r1 = var & 0x7F;
    r0 = var >> 7;
    switch (r0)
    {
    case 0:
        SetPokemonCryTone(&gUnknown_08532D6C[r1]);
        break;
    case 1:
        SetPokemonCryTone(&gUnknown_08533360[r1]);
        break;
    case 2:
        SetPokemonCryTone(&gUnknown_08533960[r1]);
        break;
    case 3:
        SetPokemonCryTone(&gUnknown_08533F60[r1]);
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
        sub_525CC(gMain_saveData.unk143);
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

void SaveFile_SetPokedexFlags(s16 a, u8 b)
{
    u16 *saveData = (u16 *)&gMain_saveData;
    size_t size = sizeof(gMain_saveData);
    u32 checksum;

    if (gMain_saveData.pokedexFlags[a] < b)
    {
        gMain_saveData.unk2E4++;
        gMain_saveData.pokedexFlags[a] = b;
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
    gMain_saveData.unk141 = 0;
    gMain_saveData.ballSpeed = 0;
    sub_525CC(-1);
    sub_F6E0();
    sub_8ABC();
    gMain_saveData.unk143 = 0;
}
