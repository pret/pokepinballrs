#include "global.h"
#include "variables.h"
#include "types.h"
#include "main.h"

//Presumed duplicate of sub_18AE0?
void sub_18784(u8 unknown_enum) {
	// input presumed to be an enum due to this switch case below
	// something told the compiler to make 15 cases not 0 based
	switch (unknown_enum) {
	case 4:
		gCurrentPinballGame->unk3DC = 6;
		gCurrentPinballGame->unk1F = 1;
		break;
	case 1:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		break;
	}
}

//One known callsite is 080145D2 during the rayquaza bonus stage
s16 sub_187F4(struct Vector16* inp1, u16* inp2) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;
    return_val = 0;
    gCurrentPinballGame->unk132c->unk4 = 0;

    if (inp1->y <= 0x1FF) {
        s16 r2;
        s32 unk1;
        s32 unk2;
        vec1.x = inp1->x / 8;
        vec1.y = inp1->y / 8;
        vec2.x = inp1->x % 8;
        vec2.y = inp1->y % 8;
        unk1 = vec1.y / 64;
        unk2 = gCurrentPinballGame->unk24;
        vec1.y %= 64;
        r2 = gUnknown_02031520.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
        sp00 = gUnknown_02031520.unk48[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gUnknown_02031520.unk58[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else {
        sp00 = 0;
        sp02 = 0;
    }

    sub_18A4C(inp1, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4; //what is up with this?

    switch (switch_enum) {
    case 1:
    case 4:
    case 6:
        //_0801894C
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *inp2 = sp00;
        if (*inp2 >= 0x3FF0 && *inp2 <= 0x4010) {
            if (gCurrentPinballGame->unk132c->unk10.x < (gUnknown_02031520.unk26 - 8) || gCurrentPinballGame->unk132c->unk10.y < gUnknown_02031520.unk28 - 8) {
                if (gCurrentPinballGame->unk132c->unk6 > 0)
                    *inp2 = 0x3E00;
                else if (gCurrentPinballGame->unk132c->unk6 != 0)
                    *inp2 = 0x4100;
                else if (gCurrentPinballGame->unk132c->unk6 == 0) {
                    if ((gMain.systemFrameCount & 1)) {
                        gCurrentPinballGame->unk132c->unk4 = 40;
                        gCurrentPinballGame->unk132c->unk6 = 1;
                        *inp2 = 0x3E00;
                    }
                    else {
                        gCurrentPinballGame->unk132c->unk4 = -40;
                        gCurrentPinballGame->unk132c->unk6 = -1;
                        *inp2 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *inp2 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }
    sub_18AE0(some_enum, &return_val, inp2);
    return return_val;
}