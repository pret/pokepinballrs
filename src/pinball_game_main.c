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
static void sub_4A270(void);
void sub_4A518(void);
void sub_4A90C(void);
void sub_4B678(u16);

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gUnknown_084C0C6C[];


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

static void sub_4A270(void)
{
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK | DISPCNT_OBJ_ON;
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        REG_BG3CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(6) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0); 
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_SAPPHIRE:
        REG_BG3CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_MOSAIC | BGCNT_SCREENBASE(6) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_2:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_3:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_4:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_5:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_6:
        REG_BG3CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(6) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_7:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    }

    gMain.unk16 = REG_DISPCNT;
    REG_MOSAIC = 0;
}

void sub_4A518(void)
{
    gMain.unkF = 0;
    gMain.unk10 = 0;
    gMain.fieldFrameCount = 0;
    gMain.unk11 = 0;
    gMain.unk12 = 0;
    gMain.unk14 = 0;
    gMain.vCount = 144;
    gMain.unk28 = 0;
    gMain.unk2A = 0;
    gMain.unk36 = 0;
    gMain.blendControl = 0;
    gMain.blendAlpha = 0;
    gMain.blendBrightness = 0;
    if (gMain.unk5 == gMain.selectedField)
    {
        DmaFill16(3, 0, gCurrentPinballGame, sizeof(struct PinballGame));
        if (gMain.eReaderBonus[EREADER_DX_MODE_CARD])
        {
            gCurrentPinballGame->unk1C6 = 168;
            gCurrentPinballGame->unk1C8 = 168;
            gCurrentPinballGame->unk1CC = 13;
            gCurrentPinballGame->unk1CA = 13;
            gCurrentPinballGame->unk1D0 = 0;
            gCurrentPinballGame->unk1D4 = 0;
            gCurrentPinballGame->unk1D6 = 120;
            gCurrentPinballGame->unk1DC = 60;
            DmaCopy16(3, gUnknown_084C0C6C, (void *)OBJ_VRAM0 + 0x600, 0x180);
            gCurrentPinballGame->unk1E2 = 2;
            *gMain.unk44->unkA4 = 0;
            gCurrentPinballGame->unk1C0 = 1;
            gCurrentPinballGame->unk5F6 = 3;
            gCurrentPinballGame->unk5F8 = 60 * 60;
            gCurrentPinballGame->numLives = 9;
            gCurrentPinballGame->coins = 99;
        }
        else
        {
            gCurrentPinballGame->unk1D4 = 0;
            gCurrentPinballGame->unk1D6 = -4;
            gCurrentPinballGame->numLives = 2;
            gCurrentPinballGame->coins = 10;
        }
    }

    if (gMain.mainState != STATE_GAME_IDLE)
        gCurrentPinballGame->unk31 = gMain_saveData.ballSpeed;

    gCurrentPinballGame->unk38 = 40000;
    gCurrentPinballGame->unk1D = 0;
    gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
    gCurrentPinballGame->unk1330 = &gCurrentPinballGame->unk1334[0];
    gCurrentPinballGame->unk66 = 0;
}

void sub_4A6A0(void)
{
    switch (gCurrentPinballGame->unk282)
    {
    case 0:
        gCurrentPinballGame->unk132c->unk10 = 119;
        gCurrentPinballGame->unk132c->unk12 = 279;
        gCurrentPinballGame->unk132c->unk30 = 0;
        gCurrentPinballGame->unk132c->unk32 = 0;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->unk34 = gCurrentPinballGame->unk132c->unk10 << 8;
        gCurrentPinballGame->unk132c->unk38 = gCurrentPinballGame->unk132c->unk12 << 8;
        gCurrentPinballGame->unk132c->unkE = 128;
        gCurrentPinballGame->unk132c->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk730 = 0;
        gCurrentPinballGame->unk28 = 120;
        gCurrentPinballGame->unk25 = 4;
        if (gMain.selectedField == FIELD_RUBY)
            sub_1A9E8();
        else
            sub_32968();

        gCurrentPinballGame->unk4C = 0;
        gCurrentPinballGame->unk4E = 215;
        break;
    case 1:
        gCurrentPinballGame->unk132c->unk10 = 140;
        gCurrentPinballGame->unk132c->unk12 = 183;
        gCurrentPinballGame->unk132c->unk30 = 0;
        gCurrentPinballGame->unk132c->unk32 = 0;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->unk34 = gCurrentPinballGame->unk132c->unk10 << 8;
        gCurrentPinballGame->unk132c->unk38 = gCurrentPinballGame->unk132c->unk12 << 8;
        gCurrentPinballGame->unk132c->unkE = 128;
        gCurrentPinballGame->unk132c->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk730 = 0;
        gCurrentPinballGame->unk2A2 = 5;
        gCurrentPinballGame->unk4C = 0;
        gCurrentPinballGame->unk4E = 118;
        break;
    case 2:
        gCurrentPinballGame->unk132c->unk10 = -28;
        gCurrentPinballGame->unk132c->unk12 = -10;
        gCurrentPinballGame->unk132c->unk30 = 0;
        gCurrentPinballGame->unk132c->unk32 = 0;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->unk34 = gCurrentPinballGame->unk132c->unk10 << 8;
        gCurrentPinballGame->unk132c->unk38 = gCurrentPinballGame->unk132c->unk12 << 8;
        gCurrentPinballGame->unk132c->unkE = 128;
        gCurrentPinballGame->unk132c->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk730 = 0;
        gCurrentPinballGame->unk30C = 0;
        gCurrentPinballGame->unk306 = 7;
        gCurrentPinballGame->unk4C = 0;
        gCurrentPinballGame->unk4E = 0;
        break;
    }

    gCurrentPinballGame->unk5FC = 0;
    gCurrentPinballGame->unk5FE = 0;
    gCurrentPinballGame->unk5FB = 0;
    gCurrentPinballGame->unk54 = gCurrentPinballGame->unk4E << 8;
    gCurrentPinballGame->unk58 = gCurrentPinballGame->unk4C;
    gCurrentPinballGame->unk5A = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk5FC;

    gMain.bgOffsets[2].xOffset = gCurrentPinballGame->unk4C;
    gMain.bgOffsets[2].yOffset = gCurrentPinballGame->unk4E;
    gMain.bgOffsets[3].xOffset = gCurrentPinballGame->unk4C;
    gMain.bgOffsets[3].yOffset = gCurrentPinballGame->unk4E;
    gMain.bgOffsets[1].xOffset = gCurrentPinballGame->unk4C;
    gMain.bgOffsets[1].yOffset = gCurrentPinballGame->unk4E;
    gMain.bgOffsets[0].yOffset = 80;

    gCurrentPinballGame->unkCC = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->unk64 = gMain.bgOffsets[3].yOffset / 8;
}
