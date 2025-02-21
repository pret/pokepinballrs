#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"

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

void sub_11C14(s16 arg0)
{
    struct UnkPinballGame1334 *var0 = &gCurrentPinballGame->unk1334[arg0];
    var0->unk10.x = gUnknown_02031520.unk26;
    var0->unk10.y = gUnknown_02031520.unk28;
    var0->position.x = Q_24_8(var0->unk10.x);
    var0->position.y = Q_24_8(var0->unk10.y);
    var0->unk28.x = gUnknown_02031520.unk26 * 2;
    var0->unk28.y = gUnknown_02031520.unk28 * 2;
    var0->unkE = 0x100;
    var0->velocity.x = 0;
    var0->velocity.y = 0;
    if (gMain.selectedField == FIELD_RUBY)
        var0->unk1 = 3; 
    else
        var0->unk1 = 1;

    var0->unk6 = 0;
    gCurrentPinballGame->unk5B2 = 1;
}
