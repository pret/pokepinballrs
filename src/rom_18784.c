#include "global.h"

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