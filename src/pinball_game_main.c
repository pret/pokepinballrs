#include "global.h"
#include "agb_sram.h"
#include "main.h"
#include "m4a.h"
#include "constants/ereader.h"
#include "constants/fields.h"

extern struct PinballGame gUnknown_02000000;

typedef void (*VoidFunc)(void);

struct Unk20028D8
{
    void (*unk0)(void);
    void (*unk4)(void);
};

extern struct Unk20028D8 gUnknown_020028D8[9];
extern u8 gUnknown_0200FBB0[][0x400];
extern u8 gUnknown_020030A0[][0x400];

extern const struct Unk20028D8 gUnknown_086B077C[];
extern const VoidFunc gUnknown_086B085C[];
extern const struct MainUnk44 gUnknown_086B02CC[];
extern const struct MainUnk44 gUnknown_086B03BC[];

extern const u8 gUnknown_08158284[];
extern const u8 gUnknown_08395A4C[];
extern const u8 gUnknown_08397E6C[];
extern const u8 gUnknown_083A704C[];
extern const u8 gUnknown_0848FD8C[];
extern const u8 *const gUnknown_086ACEF8[];
extern const u8 gUnknown_081428D4[];
extern const u8 gUnknown_081BCAA4[];
extern const u8 gUnknown_081BE2C4[];
extern const u8 gUnknown_081BE4C4[];
extern const u8 gUnknown_081BFCE4[];
extern const u8 gUnknown_0839C78C[];
extern const u8 gUnknown_0839DDAC[];
extern const u8 gUnknown_083A07CC[];
extern const u8 gUnknown_083A29EC[];
extern const u8 gUnknown_083A340C[];
extern const u8 gUnknown_083A562C[];
extern const u8 gUnknown_083FF04C[][0x40];
extern const u8 gUnknown_083FFD4C[0x40];
extern const u8 gUnknown_08480E0C[][0x40];
extern const u8 gUnknown_084F61EC[];
extern const u8 gUnknown_084FA20C[];
extern const u8 gUnknown_0850100C[];
extern const u8 gUnknown_0850398C[];
extern const u8 gUnknown_08526DCC[];
extern const s16 gUnknown_086ACFE0[];
extern const u16 gUnknown_086AD2DE[];
extern const u8 *gUnknown_086AD474[];

struct Unk86AD000
{
    u8 filler0[0x6];
    u16 unk6;
};

extern const struct Unk86AD000 gUnknown_086AD000[];

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gUnknown_084C0C6C[];

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
void sub_4B280(void);
void sub_4B334(void);
void sub_4B408(s16);
void sub_4B654(void);
void sub_4B678(u16);
void sub_4BC34(void);
void sub_4C290(void);
void sub_4C808(void);
void sub_4CA18(void);
void nullsub_18(void);
void sub_4CAE8(void);
void sub_4CB0C(void);
void sub_4CB30(void);
void sub_4CBB4(void);
void sub_4CC58(void);
void sub_4CD60(void);


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
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
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
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
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
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
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
            *gMain.unk44[1].unk2C = 0;
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
        gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

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

void sub_4A90C(void)
{
    gUnknown_020028D8[1] = gUnknown_086B077C[0];
    gUnknown_020028D8[8] = gUnknown_086B077C[18];
    gUnknown_020028D8[6] = gUnknown_086B077C[15];
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        gUnknown_020028D8[3] = gUnknown_086B077C[3];
        gUnknown_020028D8[7] = gUnknown_086B077C[16];
        gUnknown_020028D8[0] = gUnknown_086B077C[19];
        gUnknown_020028D8[4] = gUnknown_086B077C[11];
        gUnknown_020028D8[2] = gUnknown_086B077C[1];
        gUnknown_020028D8[5] = gUnknown_086B077C[13];
        gMain.unk44 = &gUnknown_086B02CC[gMain.selectedField * 2];
        break;
    case FIELD_SAPPHIRE:
        gUnknown_020028D8[3] = gUnknown_086B077C[4];
        gUnknown_020028D8[7] = gUnknown_086B077C[16];
        gUnknown_020028D8[0] = gUnknown_086B077C[20];
        gUnknown_020028D8[4] = gUnknown_086B077C[11];
        gUnknown_020028D8[2] = gUnknown_086B077C[1];
        gUnknown_020028D8[5] = gUnknown_086B077C[13];
        gMain.unk44 = &gUnknown_086B02CC[gMain.selectedField * 2];
        break;
    case FIELD_2:
        gUnknown_020028D8[3] = gUnknown_086B077C[5];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[21];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = &gUnknown_086B03BC[gMain.selectedField];
        break;
    case FIELD_3:
        gUnknown_020028D8[3] = gUnknown_086B077C[6];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[22];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = &gUnknown_086B03BC[gMain.selectedField];
        break;
    case FIELD_4:
        gUnknown_020028D8[3] = gUnknown_086B077C[7];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[23];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = &gUnknown_086B03BC[gMain.selectedField];
        break;
    case FIELD_5:
        gUnknown_020028D8[3] = gUnknown_086B077C[8];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[24];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = &gUnknown_086B03BC[gMain.selectedField];
        break;
    case FIELD_6:
        gUnknown_020028D8[3] = gUnknown_086B077C[9];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[25];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = &gUnknown_086B03BC[gMain.selectedField];
        break;
    case FIELD_7:
        gUnknown_020028D8[3] = gUnknown_086B077C[10];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[26];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = &gUnknown_086B03BC[gMain.selectedField];
        break;
    }
}

void sub_4AAD8(void)
{
    switch (gCurrentPinballGame->unk1D)
    {
    case 0:
        gCurrentPinballGame->unk1D = 1;
        gMain.unkE = 0;
        break;
    case 1:
        gUnknown_086B085C[gMain.unk6]();
        if (JOY_HELD(A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON) == (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON))
            gMain.unkE = 1;

        if (gMain.unkE)
        {
            if (gMain.selectedField <= FIELD_SAPPHIRE)
            {
                sub_1D4D0();
                sub_31BE8(0);
            }
            else if (gMain.selectedField == FIELD_2)
            {
                sub_356A0();
            }
            else if (gMain.selectedField == FIELD_4)
            {
                sub_3ADA0();
            }
            else if (gMain.selectedField == FIELD_5)
            {
                sub_3E5D0();
            }

            if (gMain.unkF & 0x2)
                DmaCopy16(3, gCurrentPinballGame->unk111A, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);

            gCurrentPinballGame->unk1D = 2;
            if (gMain.unkE == 2)
                sub_4B408(1);
        }
        break;
    case 2:
        gMain.subState++;
        break;
    }

    sub_11FC();
}

void sub_4ABC8(void)
{
    sub_111C();
    if (sub_1170())
    {
        sub_1198();
        gMain.subState++;
    }
}

void sub_4ABEC(void)
{
    s16 i;

    sub_4B280();
    gUnknown_020028D8[1].unk4();
    if (gMain.unkE == 0 && !(gMain.unkF & 0x2))
    {
        gUnknown_020028D8[2].unk4();
        gUnknown_020028D8[0].unk4();
        gUnknown_020028D8[3].unk4();
        gUnknown_020028D8[4].unk4();
        if (gMain.unkF)
        {
            if (!gCurrentPinballGame->unk1F)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    gUnknown_020028D8[6].unk4();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->unk290++;
            if (gCurrentPinballGame->unk1F)
            {
                if (gCurrentPinballGame->unk1F != 2)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->unk1E = i;
                        gUnknown_020028D8[5].unk4();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    gUnknown_020028D8[5].unk4();
                    gUnknown_020028D8[6].unk4();
                }
            }
        }

        gUnknown_020028D8[7].unk4();
        gUnknown_020028D8[8].unk4();
    }

    sub_47030();
}

void sub_4ACF0(void)
{
    s16 i;

    sub_4B334();
    gUnknown_020028D8[1].unk4();
    if (!(gMain.unkF & 0x2))
    {
        gUnknown_020028D8[2].unk4();
        gUnknown_020028D8[0].unk4();
        gUnknown_020028D8[3].unk4();
        gUnknown_020028D8[4].unk4();
        if (gMain.unkF)
        {
            if (!gCurrentPinballGame->unk1F)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    gUnknown_020028D8[6].unk4();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->unk290++;
            if (gCurrentPinballGame->unk1F)
            {
                if (gCurrentPinballGame->unk1F != 2)
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->unk1E = i;
                        gUnknown_020028D8[5].unk4();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    gUnknown_020028D8[5].unk4();
                    gUnknown_020028D8[6].unk4();
                }
            }
        }

        gUnknown_020028D8[7].unk4();
        gUnknown_020028D8[8].unk4();
    }

    sub_47030();
    if ((gMain.systemFrameCount % 32) / 16 > 0)
    {
        for (i = 0; i < 10; i++)
            gUnknown_03005C00[0x34A + i] = 0xC156 + i;
    }
    else
    {
        for (i = 0; i < 10; i++)
            gUnknown_03005C00[0x34A + i] = 0x1FF;
    }

    DmaCopy16(3, &gUnknown_03005C00[0x340], (void *)0x6002680, 0x40);
}

void sub_4AE8C(void)
{
    s16 i;

    sub_4B280();
    gUnknown_020028D8[1].unk4();
    if (gMain.unkF & 0x2)
        return;

    gUnknown_020028D8[0].unk4();
    gUnknown_020028D8[2].unk4();
    gUnknown_020028D8[3].unk4();
    gUnknown_020028D8[4].unk4();
    if (gMain.unkF & ~0x40)
    {
        if (!gCurrentPinballGame->unk1F)
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->unk66 = 0;
                gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                gCurrentPinballGame->unk1E = i;
                gUnknown_020028D8[6].unk4();
            }
        }
    }
    else
    {
        gMain.fieldFrameCount++;
        gCurrentPinballGame->unk290++;
        if (gCurrentPinballGame->unk1F)
        {
            if (gCurrentPinballGame->unk1F == 2)
            {
                gCurrentPinballGame->unk66 = 0;
                gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                gCurrentPinballGame->unk1E = 0;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk66 = 0;
                    gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = i;
                    gUnknown_020028D8[5].unk4();
                }
            }
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->unk66 = 0;
                gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                gCurrentPinballGame->unk1E = i;
                gUnknown_020028D8[5].unk4();
                gUnknown_020028D8[6].unk4();
            }
        }
    }

    gUnknown_020028D8[7].unk4();
    gUnknown_020028D8[8].unk4();
}

void sub_4B000(void)
{
    s16 i;

    sub_4B334();
    if (!(gMain.unkF & 0x2))
    {
        gUnknown_020028D8[0].unk4();
        gUnknown_020028D8[2].unk4();
        gUnknown_020028D8[3].unk4();
        gUnknown_020028D8[4].unk4();
        if (gMain.unkF & ~0x40)
        {
            if (!gCurrentPinballGame->unk1F)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk66 = 0;
                    gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = i;
                    gUnknown_020028D8[6].unk4();
                }
            }
        }
        else
        {
            gMain.fieldFrameCount++;
            gCurrentPinballGame->unk290++;
            if (gCurrentPinballGame->unk1F)
            {
                if (gCurrentPinballGame->unk1F == 2)
                {
                    gCurrentPinballGame->unk66 = 0;
                    gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = 0;
                }
                else
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->unk66 = 0;
                        gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                        gCurrentPinballGame->unk1E = i;
                        gUnknown_020028D8[5].unk4();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk66 = 0;
                    gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = i;
                    gUnknown_020028D8[5].unk4();
                    gUnknown_020028D8[6].unk4();
                }
            }
        }

        gUnknown_020028D8[7].unk4();
        gUnknown_020028D8[8].unk4();
    }

    if ((gMain.systemFrameCount % 32) / 16 > 0)
    {
        for (i = 0; i < 9; i++)
            gUnknown_03005C00[0x32B + i] = 0xC156 + i;
    }
    else
    {
        for (i = 0; i < 9; i++)
            gUnknown_03005C00[0x32B + i] = 0x1FF;
    }

    DmaCopy16(3, &gUnknown_03005C00[0x320], (void *)0x6002640, 0x40);
}

void sub_4B20C(void)
{
    gMain.unk36 = 0;
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    gMain.unk58 = gCurrentPinballGame->unk44;
    gMain.unk5C = gCurrentPinballGame->unk48;
    if (gMain.unkE == 2)
        sub_4B654();

    if (gMain.unkE == 0)
    {
        if (gMain.selectedField > FIELD_SAPPHIRE)
        {
            SetMainGameState(STATE_BONUS_FIELD_SELECT);
            return;
        }
        else if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD] || gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
        {
            SetMainGameState(STATE_INTRO);
            return;
        }
    }
    else
    {
        SetMainGameState(STATE_INTRO);
        return;
    }

    SetMainGameState(STATE_SCORES_MAIN);
}

void nullsub_19(void)
{
}

void sub_4B280(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gCurrentPinballGame->unk4[i] = 0;
        gCurrentPinballGame->unk9[i] = 0;
    }

    if (gMain.unkF)
        return;

    for (i =  0; i < 5; i++)
    {
        int buttonConfigKeyMask = (gMain.buttonConfigs[i][0] | gMain.buttonConfigs[i][1]) & KEYS_MASK;
        if (buttonConfigKeyMask == JOY_HELD(buttonConfigKeyMask))
        {
            if (gCurrentPinballGame->unkE[i] == 0)
                gCurrentPinballGame->unk4[i] = 1;

            gCurrentPinballGame->unkE[i] = 1;
        }
        else
        {
            if (gCurrentPinballGame->unkE[i])
                gCurrentPinballGame->unk9[i] = 1;

            gCurrentPinballGame->unkE[i] = 0;
        }
    }
}

void sub_4B334(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gCurrentPinballGame->unk4[i] = 0;
        gCurrentPinballGame->unk9[i] = 0;
    }

    if (gMain.unkF)
        return;

    if (gUnknown_02031510 < 60 * 60)
    {
        for (i =  0; i < 5; i++)
        {
            gCurrentPinballGame->unk4[i] = (gUnknown_02031520.unk10[gUnknown_02031510].unk0 >> i) & 0x1;
            gCurrentPinballGame->unk9[i] = (gUnknown_02031520.unk10[gUnknown_02031510].unk1 >> i) & 0x1;
            gCurrentPinballGame->unkE[i] = (gUnknown_02031520.unk10[gUnknown_02031510].unk2 >> i) & 0x1;
        }

        gUnknown_02031510++;
    }

    if (gCurrentPinballGame->unk4[1])
        gMain.newKeys = A_BUTTON;
}

void sub_4B408(s16 arg0)
{
    s16 i;
    u16 *var0;

    if (gMPlayInfo_BGM.status >= 0)
    {
        gCurrentPinballGame->unkF4C = gMPlayInfo_BGM.songHeader;
        m4aMPlayStop(&gMPlayInfo_BGM);
    }
    else
    {
        gCurrentPinballGame->unkF4C = NULL;
    }

    for (i = 0; i < 100; i++)
        gCurrentPinballGame->unkF68[gMain.unk6][i] = gMain.spriteGroups[i].available;

    DmaCopy16(3, (void *)OBJ_PLTT, gCurrentPinballGame->unk74C[gMain.unk6], OBJ_PLTT_SIZE);
    DmaCopy16(3, (void *)BG_PLTT, gCurrentPinballGame->unkB4C[gMain.unk6], BG_PLTT_SIZE);
    if (!arg0)
        return;

    gCurrentPinballGame->bgOffsets0 = gMain.bgOffsets[0];
    gCurrentPinballGame->bgOffsets1 = gMain.bgOffsets[1];
    gCurrentPinballGame->bgOffsets2 = gMain.bgOffsets[2];
    gCurrentPinballGame->bgOffsets3 = gMain.bgOffsets[3];
    gCurrentPinballGame->field = gMain.selectedField;
    gCurrentPinballGame->unk10FE = gMain.unk5;
    gCurrentPinballGame->unk10FF = gMain.unk6;
    gCurrentPinballGame->unk1101 = gMain.unkF;
    gCurrentPinballGame->unk1102 = gMain.unk10;
    gCurrentPinballGame->unk1103 = gMain.unk11;
    gCurrentPinballGame->unk1320 = gMain.unk12;
    gCurrentPinballGame->unk1322 = gMain.unk14;
    gCurrentPinballGame->unk1324 = gMain.unk28;
    gCurrentPinballGame->unk1326 = gMain.unk2A;
    gCurrentPinballGame->unk1110 = gCurrentPinballGame->unk1106;
    gCurrentPinballGame->unk1112 = gCurrentPinballGame->unk1108;
    gCurrentPinballGame->unk1114 = gCurrentPinballGame->unk110A;
    gCurrentPinballGame->unk1116 = gCurrentPinballGame->unk110C;
    gCurrentPinballGame->unk1118 = gCurrentPinballGame->unk110E;
    gCurrentPinballGame->ballSpeed = gMain_saveData.ballSpeed;

    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gCurrentPinballGame->eReaderBonuses[i] = gMain.eReaderBonuses[i];
}

void sub_4B654(void)
{
    gCurrentPinballGame->unk0 = 1;
    WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(*gCurrentPinballGame));
}

void sub_4B678(u16 arg0)
{
    s16 i, j;
    s16 var0, var1;
    int var2;

    if (arg0 == 1)
    {
        ReadSramFast((void *)SRAM + 0x544, (u8 *)gCurrentPinballGame, sizeof(*gCurrentPinballGame));
    }
    else if (arg0 == 2)
    {
        DmaCopy16(3, gUnknown_02031520.unkC, gCurrentPinballGame, sizeof(*gCurrentPinballGame));
        gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
        gCurrentPinballGame->unk1330 = &gCurrentPinballGame->unk1334[0];
        var2 = gMain.unk30;
        if ((var2 & 0x3) == 1)
        {
            gCurrentPinballGame->unk614 = 0;
            gCurrentPinballGame->unk208 = 0;
            gCurrentPinballGame->unk20A = 0;
            gCurrentPinballGame->unk1C6 = 0;
            gCurrentPinballGame->unk1C8 = 0;
            gCurrentPinballGame->unk1CC = 0;
            gCurrentPinballGame->unk1CA = 0;
            gCurrentPinballGame->unk1D4 = 0;
            gCurrentPinballGame->unk1D6 = -4;
            gCurrentPinballGame->unk1D8 = 256;
            gCurrentPinballGame->unk1DA = 256;
            gCurrentPinballGame->unk1CE = 0;
            gCurrentPinballGame->unk1D0 = 0;
        }
    }

    if (arg0 != 0)
    {
        gMain.selectedField = gCurrentPinballGame->field;
        gMain.unk5 = gCurrentPinballGame->unk10FE;
        gMain.unk6 = gCurrentPinballGame->unk10FF;
        gMain.unkF = gCurrentPinballGame->unk1101;
        gMain.unk10 = gCurrentPinballGame->unk1102;
        gMain.unk11 = gCurrentPinballGame->unk1103;
        gMain.unk12 = gCurrentPinballGame->unk1320;
        gMain.unk14 = gCurrentPinballGame->unk1322;
        gMain.unk28 = gCurrentPinballGame->unk1324;
        gMain.unk2A = gCurrentPinballGame->unk1326;
        gMain.blendControl = gCurrentPinballGame->unk1110;
        gMain.blendAlpha = gCurrentPinballGame->unk1112;
        gMain.blendBrightness = gCurrentPinballGame->unk1114;
        gMain.unk2C = gCurrentPinballGame->unk1116;
        gMain.vCount = gCurrentPinballGame->unk1118;
        gMain.bgOffsets[0] = gCurrentPinballGame->bgOffsets0;
        gMain.bgOffsets[1] = gCurrentPinballGame->bgOffsets1;
        gMain.bgOffsets[2] = gCurrentPinballGame->bgOffsets2;
        gMain.bgOffsets[3] = gCurrentPinballGame->bgOffsets3;
        for (i = 0; i < NUM_EREADER_CARDS; i++)
            gMain.eReaderBonuses[i] = gCurrentPinballGame->eReaderBonuses[i];

        gCurrentPinballGame->unk1100 = 1;
        if (arg0 == 1 && gMain.selectedField <= FIELD_SAPPHIRE)
        {
            gCurrentPinballGame->unk68 = gCurrentPinballGame->unk4E +
                                         gCurrentPinballGame->unk121 +
                                         gCurrentPinballGame->unk5FC +
                                         gCurrentPinballGame->unkE6;
        }
    }
    else
    {
        gCurrentPinballGame->unk68 = gCurrentPinballGame->unk6A;
    }

    gCurrentPinballGame->unk1D = 0;
    gMain.unkD = 0;
    sub_467F4();
    if (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->unk29E)
        sub_46FD4(1);

    if (gMain.selectedField <= FIELD_SAPPHIRE)
    {
        for (i = 0; i < 22; i++)
        {
            var0 = i + gCurrentPinballGame->unk64;
            var1 = (i + 10 + gCurrentPinballGame->unk64) % 22;
            if (var0 < 32)
            {
                DmaCopy16(3, &gUnknown_0200FBB0[var0], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
            else
            {
                var0 -= 32;
                DmaCopy16(3, &gUnknown_020030A0[var0], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
        }
    }

    for (i = 0; i < 0x800; i++)
        gUnknown_03005C00[i] = 0x1FF;

    DmaCopy16(3, gUnknown_03005C00, (void *)0x6002000, 0x1000);
    if (gMain.unk2C)
    {
        if (gCurrentPinballGame->progressForBonus == 6)
        {
            for (j = 0; j <= gCurrentPinballGame->unk298; j++)
            {
                for (i = 2; i < 12; i++)
                    gUnknown_03005C00[(i + 15) * 0x20 + j] = 0xC100;
            }
        }
        else
        {
            for (j = 0; j <= gCurrentPinballGame->unk298; j++)
            {
                for (i = 1; i < 11; i++)
                    gUnknown_03005C00[(i + 15) * 0x20 + j] = 0xC100;
            }
        }

        DmaCopy16(3, gUnknown_03005C00, (void *)0x6002000, 0x800);
    }

    DmaCopy16(3, gCurrentPinballGame->unk74C[gMain.unk6], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    DmaCopy16(3, gCurrentPinballGame->unkB4C[gMain.unk6], (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)OBJ_PLTT + 0x20, 0x20);
    sub_4BC34();
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        sub_50848();
        sub_4E9F0(gCurrentPinballGame->unk1A5);
        break;
    case FIELD_SAPPHIRE:
        sub_50AD4();
        break;
    case FIELD_2:
        sub_50D48();
        break;
    case FIELD_3:
        sub_50DE0();
        break;
    case FIELD_4:
        sub_50F04();
        break;
    case FIELD_5:
        sub_50FD4();
        break;
    case FIELD_6:
        sub_51090();
        break;
    case FIELD_7:
        sub_51150();
        break;
    }

    for (i = 0; i < 100; i++)
        gMain.spriteGroups[i].available = gCurrentPinballGame->unkF68[gMain.unk6][i];

    if (arg0 == 1)
    {
        gCurrentPinballGame->unk0 = 0;
        WriteAndVerifySramFast((const u8 *)gCurrentPinballGame, (void *)SRAM + 0x544, sizeof(gCurrentPinballGame->unk0));
    }
}

void sub_4BC34(void)
{
    s16 i;
    struct PokemonSpecies *species;
    const struct Unk86AD000 *var1;
    s16 var2, var3;

    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        sub_4C290();
        sub_4C808();
        break;
    case FIELD_SAPPHIRE:
        sub_4C290();
        sub_4CA18();
        break;
    case FIELD_2:
        nullsub_18();
        sub_4CAE8();
        break;
    case FIELD_3:
        nullsub_18();
        sub_4CB0C();
        break;
    case FIELD_4:
        nullsub_18();
        sub_4CB30();
        break;
    case FIELD_5:
        nullsub_18();
        sub_4CBB4();
        break;
    case FIELD_6:
        nullsub_18();
        sub_4CC58();
        break;
    case FIELD_7:
        nullsub_18();
        sub_4CD60();
        break;
    }

    switch (gCurrentPinballGame->unkE4 - 1)
    {
    case 0:
        if (gCurrentPinballGame->unk1E2 == 2 && gCurrentPinballGame->unk1C2 == 2)
        {
            DmaCopy16(3, gUnknown_08395A4C, (void *)0x6015800, 0x2400);
        }
        else
        {
            DmaCopy16(3, gUnknown_08397E6C, (void *)0x6015800, 0x2400);
        }
        break;
    case 1:
        DmaCopy16(3, gUnknown_083A704C, (void *)0x6015800, 0x1000);
        break;
    case 2:
        DmaCopy16(3, gUnknown_0848FD8C, (void *)0x6015800, 0xCA0);
        break;
    case 3:
        DmaCopy16(3, gUnknown_086ACEF8[gCurrentPinballGame->unkF2], (void *)0x6015800, 0x25E0);
        break;
    case 4:
        DmaCopy16(3, gUnknown_083A07CC, (void *)0x6015800, 0x2000);
        break;
    case 5:
        DmaCopy16(3, gUnknown_083A29EC, (void *)0x6015800, 0x800);
        break;
    case 6:
        DmaCopy16(3, gUnknown_083A340C, (void *)0x6015800, 0x2000);
        break;
    case 7:
        DmaCopy16(3, gUnknown_083A562C, (void *)0x6015800, 0x1800);
        break;
    case 8:
        DmaCopy16(3, gUnknown_081428D4, (void *)0x6015800, 0x1C00);
        break;
    case 9:
        DmaCopy16(3, gUnknown_0839C78C, (void *)0x6015800, 0x1400);
        break;
    case 10:
        DmaCopy16(3, gUnknown_0839DDAC, (void *)0x6015800, 0x2800);
        break;
    case 11:
        DmaCopy16(3, gUnknown_084FA20C, (void *)0x6015800, 0x280);
        break;
    case 13:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gUnknown_083FFD4C, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gUnknown_083FF04C[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }
        DmaCopy16(3, gUnknown_084F61EC, (void *)0x6015C00, 0x940);
        break;
    case 12:
        for (i = 0; i < 10; i++)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
            {
                DmaCopy16(3, gUnknown_083FFD4C, (void *)0x6015800 + i * 0x40, 0x40);
            }
            else
            {
                int var0 = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
                DmaCopy16(3, gUnknown_083FF04C[var0], (void *)0x6015800 + i * 0x40, 0x40);
            }
        }

        for (i = 0; i < 10; i++)
        {
            if (gUnknown_086ACFE0[i] == ' ')
            {
                DmaCopy16(3, gUnknown_083FFD4C, (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
            else
            {
                int var0 = gUnknown_086ACFE0[i] - 'A';
                DmaCopy16(3, gUnknown_083FF04C[var0], (void *)0x6015800 + (i + 10) * 0x40, 0x40);
            }
        }
        break;
    case 14:
        DmaCopy16(3, gUnknown_086AD474[gCurrentPinballGame->unk25F], (void *)0x6015800, 0x1C00);
        break;
    case 15:
        DmaCopy16(3, gUnknown_08158284, (void *)0x6015800, 0x2400);
        break;
    case 16:
        DmaCopy16(3, gUnknown_083A562C, (void *)0x6015800, 0x1800);
        break;
    case 17:
        DmaCopy16(3, gUnknown_084F61EC, (void *)0x6015C00, 0x940);
        if (gCurrentPinballGame->unk1A5 == 0)
        {
            var1 = &gUnknown_086AD000[gUnknown_086AD2DE[gCurrentPinballGame->unk1A6]];
            var2 = var1->unk6 / 10;
            DmaCopy16(3, gUnknown_08480E0C[var2], (void *)0x6015DA0, 0x40);
            var3 = var1->unk6 % 10;
            DmaCopy16(3, gUnknown_08480E0C[var3], (void *)0x6015E60, 0x40);
        }
        break;
    case 18:
        DmaCopy16(3, gUnknown_0850100C, (void *)0x6015800, 0x2400);
        break;
    case 19:
        DmaCopy16(3, gUnknown_0850398C, (void *)0x6015800, 0x2800);
        break;
    case 20:
        if (gMain.selectedField == FIELD_RUBY)
        {
            DmaCopy16(3, gUnknown_081BCAA4, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gUnknown_081BE2C4, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        else
        {
            DmaCopy16(3, gUnknown_081BE4C4, (void *)0x6015800, 0x1800);
            DmaCopy16(3, gUnknown_081BFCE4, (void *)OBJ_PLTT + 0x1C0, 0x20);
        }
        break;
    case 21:
        DmaCopy16(3, gUnknown_08526DCC, (void *)0x6015800, 0xC00);
        break;
    }
}
