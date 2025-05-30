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

extern void sub_18A4C(u16, u16, u8);

void sub_187F4(s16* inp1, u32 inp2) {
	u16 stack_0;
	u8 stack_2[2];
	u16 stack_4 = 0;
	u16 stack_6;

	s16 val_x, val_y;
	u32 tile_xy;
	s16 remainder_x, remainder_y;
	u32 subtile_xy;


	u16 frac_x;
	u16 frac_y;
	s32 v_index;
	s32 h_index;
	s8 unk24;
	u32 tileIndexX;
	u32 tileIndexY;
	u32 tileIndex;
	u32 gUnknownOffset;
	s32 tileId;

	gCurrentPinballGame->unk132c->unk4 = 0;

	if (inp1[2] <= 0x1FF) {
		val_x = inp1[0];
		if (val_x < 0) {
			val_x += 7;
		}
		val_x /= 8;
		tile_xy &= 0xFFFF0000;
		tile_xy |= val_x;

		val_y = inp1[2];
		if (val_y < 0) {
			val_y += 7;
		}
		val_y /= 8;
		tile_xy &= 0x0000FFFF;
		tile_xy |= val_y << 16;

		remainder_x = inp1[0] - (val_x * 8);

		subtile_xy &= 0xFFFF0000;
		subtile_xy |= remainder_x;

		remainder_y = inp1[2] - (val_y * 8);
		subtile_xy &= 0x0000FFFF;
		subtile_xy |= remainder_y << 16;

		r5 |= y;//not sure what this is about

		v_index = y << 16;
		if (v_index < 0) {
			v_index += 63;
		}
		v_index = v_index / 64;
		unk24 = gCurrentPinballGame->unk24;
		tileIndexX = (v_index - (v_index * 64)) << 16;
		r5 &= 0x0000FFFF;
		r5 |= tileIndexX;

		gUnknownOffset = gUnknown_02031520.unk38 + ((unk24 + v_index) * 4);

		tileIndexY = (((r5 >> 16) & 0x0000FFFF) >> 10);
		tileIndex = tileIndexX + tileIndexY;
		
		tileId = gUnknownOffset[tileIndex];

		gUnknownOffset[tileIndex] = 0;//nonsense but now you need to write


	}
	else {
		//_080188FC:
		u16 r3 = stack_0;
	}
	//_0801890A:
	sub_18A4C(inp1, stack_0, stack_2[0]);
	u8 loadr4 = stack_2[0] & 0xF;
	u32 r6 = stack_2[0] / 16;
	switch (loadr4) {
		case 0:
		case 3:
		case 5:
			//_0801894C
			break;
		case 1:
		case 2:
			//_080189F8
			break;
		case 4:
			//_08018A28
			break;
	}
	sub_18AE0(r6);
}