#include "global.h"
#include "main.h"
#include "gba/gba.h"
#include "constants/fields.h"

/**
 * Executed when saving or loading from a main field
 * arg0
 *   0 when saving and loading normally
 *   2 when loading into the evo or mart menu
 */
void sub_31BE8(s16 arg0)
{
    // intermediate variable for matching
    u32 temp;

    if (gCurrentPinballGame->unk70 == 1)
    {
        DmaCopy16(3, gUnknown_02031520.unk2C[arg0], (void*)OBJ_PLTT, 0x20);
    }

    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        DmaCopy16(3, gUnknown_02031520.unk2C[arg0] + 0x10, (void*)OBJ_PLTT + 0x40, 0xC0);
    }
    else
    {
        DmaCopy16(3, gUnknown_02031520.unk2C[arg0] + 0x10, (void*)OBJ_PLTT + 0x40, 0xE0);
    }

    DmaCopy16(3, gUnknown_02031520.unk2C[arg0] + 0x50, (void *)OBJ_PLTT + 0x140, 0x20);

    // related to Y position of camera on the field
    if (gCurrentPinballGame->unk68 < 170)
    {
        DmaCopy16(3, (gMain.selectedField * 3 * 64) + (u32) &gUnknown_08137B3C + (arg0 * 64), (void *)OBJ_PLTT + 0x160, 0x20);
    }
    else
    {
        temp = ((u32) &gUnknown_08137B5C + (gMain.selectedField * 3 * 64));
        DmaCopy16(3, temp + (arg0 * 64), (void *)OBJ_PLTT + 0x160, 0x20);
    }
}
