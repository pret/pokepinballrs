#include "global.h"
#include "m4a.h"
#include "agb_sram.h"
#include "main.h"

extern const u16 gUnknown_08527F18[];

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

void sub_52940(u16, s8, s8, u8, int);

void sub_528DC(u16 a, s8 b)
{
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x99);
    sub_52940(a, b, 0x7D, 10, 0);
}

void sub_5291C(u16 a, s8 b, s8 c, u8 d)
{
    sub_52940(a, b, c, d, 0);
}

extern struct ToneData gUnknown_08532D6C[];
extern struct ToneData gUnknown_08533360[];
extern struct ToneData gUnknown_08533960[];
extern struct ToneData gUnknown_08533F60[];

void sub_52940(u16 a, s8 b, s8 c, u8 d, int unused)
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

extern u16 sub_52A68(void);
extern void sub_525CC(s8);

void sub_52A18(void)
{
    SetSramFastFunc();
    gMain.unkC = 0;
    if (sub_52A68() == 0)
    {
        sub_52C64();
        sub_52B30();
        if (sub_52A68() == 0)
        {
            gMain.unkC = 1;
            sub_52C64();
        }
    }
    else
    {
        sub_525CC(gMain.saveData.unk143);
    }
}

extern struct Main2 gMain_;
extern u8 gSaveFileSignature[];

u16 sub_52A68(void)
{
    u16 r8 = 0;
    u16 fileNum;
    u16 i;
    u32 checksum;

    // Looks like there are two copies of the save data, one used as a backup?
    for (fileNum = 0; fileNum < 2; fileNum++)
    {
        u16 *saveData = (u16 *)&gMain.saveData;
        u32 size = 0x274;

        ReadSramFast((u8 *)0x0E000004 + fileNum * 672, (u8 *)saveData, size);

        // Verify signature
        for (i = 0; i < 10; i++)
        {
            if (gMain.saveData.signature[i] != gSaveFileSignature[i])
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
            r8 = 1;
            break;
        }
    }
    return r8;
}

// I really think gUnknown_0200B134_ is part of gMain, but the code doesn't
// match if I do that.
#ifdef NONMATCHING
#define gUnknown_0200B134_ gMain.saveData
#else
extern struct SaveData gUnknown_0200B134_;  // gMain.saveData
asm(".set gUnknown_0200B134_, gMain+0x74");
#endif

void sub_52B30(void)
{
    u32 checksum;
    u16 *saveData = (u16 *)&gUnknown_0200B134_;
    u32 size = 0x274;

    gUnknown_0200B134_.unk2E4++;
    gUnknown_0200B134_.unk2E2 = 0;

    checksum = 0;
    while (size > 1)
    {
	checksum += *saveData++;
	size -= 2;
    }
    if (size != 0)  // never happens (size is even)
	checksum += *saveData & 0xFF00;
    checksum = (checksum & 0xFFFF) + (checksum >> 16);
    gUnknown_0200B134_.unk2E2 = ~((checksum >> 16) + checksum);

    WriteAndVerifySramFast((u8 *)&gUnknown_0200B134_, (u8 *)0x0E000004, 0x274);
    WriteAndVerifySramFast((u8 *)&gUnknown_0200B134_, (u8 *)0x0E0002A4, 0x274);
}

void sub_52BB0(s16 a, u8 b)
{
    u16 *saveData = (u16 *)&gUnknown_0200B134_;
    u32 size = 0x274;
    u32 checksum;

    if (gUnknown_0200B134_.pokedexFlags[a] < b)
    {
	u16 r1;

	gUnknown_0200B134_.unk2E4++;
	r1 = 0;
	gUnknown_0200B134_.pokedexFlags[a] = b;
	gUnknown_0200B134_.unk2E2 = r1;

	checksum = 0;
	while (size > 1)
	{
	    checksum += *saveData++;
	    size -= 2;
	}
	if (size != 0)  // never happens (size is even)
	    checksum += *saveData & 0xFF00;
	checksum = (checksum & 0xFFFF) + (checksum >> 16);
	gUnknown_0200B134_.unk2E2 = ~((checksum >> 16) + checksum);

	WriteAndVerifySramFast((u8 *)&gUnknown_0200B134_, (u8 *)0x0E000004, 0x274);
	WriteAndVerifySramFast((u8 *)&gUnknown_0200B134_, (u8 *)0x0E0002A4, 0x274);
    }
}

void sub_52C44(void)
{
    ReadSramFast((u8 *)0x0E000544, (u8 *)&gMain.hasSavedGame, sizeof(gMain.hasSavedGame));
}

void sub_52C64(void)
{
    s16 r1;

    for (r1 = 0; r1 < 10; r1++)
	gUnknown_0200B134_.signature[r1] = gSaveFileSignature[r1];
    gUnknown_0200B134_.unk2E4 = 0;
    gUnknown_0200B134_.unk141 = 0;
    gUnknown_0200B134_.unk142 = 0;
    sub_525CC(-1);
    sub_F6E0();
    sub_8ABC();
    gUnknown_0200B134_.unk143 = 0;
}
