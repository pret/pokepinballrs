#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/ereader.h"
#include "constants/fields.h"

extern struct PinballGame gUnknown_02000000;

struct Unk20028D8
{
    void (*unk0)(void);
    u8 filler4[0x4];
};

extern const struct Unk20028D8 gUnknown_020028D8[];
typedef void (*VoidFunc)(void);
extern const VoidFunc gUnknown_086B085C[];

void sub_1D4D0(void);
void sub_356A0(void);
void sub_3ADA0(void);
void sub_3E5D0(void);
void sub_467F4(void);
void sub_4A6A0(void);
void sub_47110(void);
void sub_4A270(void);
void sub_4A518(void);
void sub_4A90C(void);
void sub_4B678(u16);

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gUnknown_08137E14[][0x20];

void PinballGameMain(void)
{
    gPinballGameStateFuncs[gMain.subState]();
}

void sub_49ED4(void)
{
    s16 i, j;
    s16 numRngAdvances;
    s16 var0;

    numRngAdvances = gMain.systemFrameCount % 16;
    for (i = 0; i < numRngAdvances; i++)
        Random();

    sub_10C0();
    gCurrentPinballGame = &gUnknown_02000000;
    ResetSomeGraphicsRelatedStuff();
    gMain.unkE = 0;
    if (gMain.unkD)
        var0 = 0;
    else if (gMain.unk5 == gMain.selectedField)
        var0 = 1;
    else if (gMain.selectedField <= FIELD_SAPPHIRE)
        var0 = 2;
    else
        var0 = 3;

    switch (var0)
    {
    case 0:
        sub_4A270();
        sub_4A518();
        sub_467F4();
        DmaCopy16(3, gUnknown_02031520.unk2C, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonus[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)OBJ_PLTT + 0x20, 0x20);

        sub_4A90C();
        for (i = 0; i < 9; i++)
            gUnknown_020028D8[i].unk0();

        m4aMPlayAllStop();
        sub_47110();
        sub_4A518();
        if (gMain.mainState == STATE_GAME_IDLE)
            sub_4B678(2);
        else
            sub_4B678(1);

        sub_4A270();
        sub_4A90C();
        gUnknown_086B085C[gMain.unk6]();
        if (gMain.selectedField == FIELD_RUBY || gMain.selectedField == FIELD_SAPPHIRE)
            sub_1D4D0();
        else if (gMain.selectedField == FIELD_2)
            sub_356A0();
        else if (gMain.selectedField == FIELD_4)
            sub_3ADA0();
        else if (gMain.selectedField == FIELD_5)
            sub_3E5D0();
        break;
    case 1:
        sub_4A270();
        sub_4A518();
        sub_467F4();
        DmaCopy16(3, gUnknown_02031520.unk2C, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonus[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)OBJ_PLTT + 0x20, 0x20);

        sub_4A90C();
        for (i = 0; i < 9; i++)
            gUnknown_020028D8[i].unk0();

        sub_47110();
        break;
    case 2:
        sub_4A270();
        sub_4A6A0();
        sub_4B678(0);
        sub_4A90C();
        gUnknown_086B085C[gMain.unk6]();
        if (gMain.selectedField == FIELD_RUBY)
            sub_46FD4(1);

        sub_1C7F4(0, 0);
        gCurrentPinballGame->unk6C4 = 0;
        break;
    case 3:
        sub_4A270();
        sub_4A518();
        sub_467F4();
        DmaCopy16(3, gUnknown_02031520.unk2C, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        sub_4A90C();
        for (i = 0; i < 9; i++)
            gUnknown_020028D8[i].unk0();

        sub_47110();
        break;
    }

    gUnknown_02031520.unk8 = 0;
    for (j = 0; j < NUM_SPECIES; j++)
    {
        if (gMain_saveData.pokedexFlags[j] > 3)
            gUnknown_02031520.unk8++;
    }

    sub_0CBC();
    sub_024C();
    gCurrentPinballGame->unk1100 = 0;
    gMain.unk36 = 1;

    switch (var0)
    {
    case 0:
        if (gMain.mainState != STATE_GAME_IDLE && gCurrentPinballGame->unkF4C && gMPlayInfo_BGM.status < 0)
            MPlayStart(&gMPlayInfo_BGM, gCurrentPinballGame->unkF4C);
        if (gMain.selectedField <= FIELD_SAPPHIRE)
            sub_31BE8(gCurrentPinballGame->unk6F);
        break;
    case 1:
    case 2:
        gMain.blendControl = 0xCE;
        gMain.blendBrightness = 0;
        break;
    case 3:
        break;
    }

    gMain.subState++;
}