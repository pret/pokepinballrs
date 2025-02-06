#include "constants/bg_music.h"
#include "main.h"
#include "global.h"

void sub_11C14(s32);
void sub_12524(void);
void sub_12BF8(void);

void sub_11B9C(void)
{
    s16 i;
    if (gMain.unk6 == 0)
    {
        gCurrentPinballGame->unk132c = gCurrentPinballGame->unk1334[0];
        sub_11C14(0);
        sub_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->unk132c = gCurrentPinballGame->unk1334[i];
            sub_11C14(i);
        }
        sub_12BF8();
    }
}
#include "constants/bg_music.h"
#include "main.h"
#include "global.h"

void sub_11C14(s16);
void sub_12524(void);
void sub_12BF8(void);

void sub_11B9C(void)
{
    s16 i;
    if (gMain.unk6 == 0)
    {
        gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
        sub_11C14(0);
        sub_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[i];
            sub_11C14(i);
        }
        sub_12BF8();
    }
}

void sub_11C14(s16 index){
    struct unk_struct *unks = &gCurrentPinballGame->unk1334[index];
    unks->unk10.x = gUnknown_02031520.unk26;
    unks->unk10.y = gUnknown_02031520.unk28;

	unks->unk34.x = Q_24_8(unks->unk10.x);
    unks->unk34.y = Q_24_8(unks->unk10.y);
    
	unks->unk28.x = gUnknown_02031520.unk26 * 2;
    unks->unk28.y = gUnknown_02031520.unk28 * 2;

	unks->unk0E = 0x100;
    
	unks->unk30.x = 0;
	unks->unk30.y = 0;


	if (gMain.selectedField == 0)
	{
		unks->unk1 = 3; 
	}
	else
	{
		unks->unk1 = 1;
	}

	unks->unk6  = 0;
	gCurrentPinballGame->unk5B2 = 1;
}
