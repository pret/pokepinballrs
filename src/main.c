#include "global.h"

struct UnkStruct_200B0C0
{
	u8 filler0[0x2];
	u8 unk2;
	u8 unk3;
};

extern struct UnkStruct_200B0C0 gUnknown_0200B0C0;

void sub_23C(u8 arg0)
{
	gUnknown_0200B0C0.unk2 = arg0;
	gUnknown_0200B0C0.unk3 = 0;
}
