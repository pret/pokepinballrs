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
extern struct MainUnk44 *gUnknown_086B02CC[][60];
extern struct MainUnk44 *gUnknown_086B04AC[][30];

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
extern const s16 gUnknown_086AD2EE[][4];
extern const s16 gUnknown_086AD456[][7];
extern const u8 gUnknown_084FB68C[][0x480];
extern const u8 gUnknown_083C3C2C[][0x300];
extern const u8 gUnknown_084F5ACC[][0x260];
extern const u8 gUnknown_083C806C[][0x100];
extern const u8 gUnknown_084ED0CC[][0x180];
extern const u8 gUnknown_08449D8C[][0x280];
extern const u8 gUnknown_084F6B0C[][0x500];
extern const u8 gUnknown_08490A4C[][0x440];
extern const s16 gUnknown_086AE5A0[][2];
extern const u8 gUnknown_0813A854[0x2000];
extern const u8 gUnknown_0813C874[0x2000];
extern const u8 gUnknown_0849F1CC[0x2000];
extern const u8 gUnknown_0813E894[0x2000];
extern const u8 gUnknown_083C5A2C[0x2800];
extern const u8 gUnknown_084A856C[0x1C00];
extern const u8 gUnknown_081408B4[0x2000];
extern const u8 gUnknown_084AA18C[0x860];
extern const u8 gUnknown_084B77EC[0x800];

struct Unk86AD000
{
    u8 filler0[0x6];
    u16 unk6;
};

extern const struct Unk86AD000 gUnknown_086AD000[];

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gUnknown_084C0C6C[];
extern u8 *gMonPortraitGroupGfx[];

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
void UpdateButtonActionsFromJoy(void);
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
    else if (gMain.selectedField < MAIN_FIELD_COUNT)
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
        else if (gMain.selectedField == FIELD_DUSCLOPS)
            sub_356A0();
        else if (gMain.selectedField == FIELD_KYOGRE)
            sub_3ADA0();
        else if (gMain.selectedField == FIELD_GROUDON)
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
        if (gMain.selectedField < MAIN_FIELD_COUNT)
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
    case FIELD_DUSCLOPS:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_KECLEON:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_KYOGRE:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_GROUDON:
        REG_BG3CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x256 | BGCNT_SCREENBASE(1) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_RAYQUAZA:
        REG_BG3CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(0) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
        REG_DISPCNT |= DISPCNT_BG3_ON;
        REG_BG2CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(2) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(2);
        REG_DISPCNT |= DISPCNT_BG2_ON;
        REG_BG1CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(6) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(1);
        REG_DISPCNT |= DISPCNT_BG1_ON;
        REG_BG0CNT = BGCNT_TXT256x512 | BGCNT_SCREENBASE(4) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(0);
        REG_DISPCNT |= DISPCNT_BG0_ON;
        break;
    case FIELD_SPHEAL:
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
            gMain.unk44[41]->a.unk0 = 0;
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
        gCurrentPinballGame->unk132c->unk10.x = 119;
        gCurrentPinballGame->unk132c->unk10.y = 279;
        gCurrentPinballGame->unk132c->velocity.x = 0;
        gCurrentPinballGame->unk132c->velocity.y = 0;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->position.x = gCurrentPinballGame->unk132c->unk10.x << 8;
        gCurrentPinballGame->unk132c->position.y = gCurrentPinballGame->unk132c->unk10.y << 8;
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
        gCurrentPinballGame->unk132c->unk10.x = 140;
        gCurrentPinballGame->unk132c->unk10.y = 183;
        gCurrentPinballGame->unk132c->velocity.x = 0;
        gCurrentPinballGame->unk132c->velocity.y = 0;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->position.x = gCurrentPinballGame->unk132c->unk10.x << 8;
        gCurrentPinballGame->unk132c->position.y = gCurrentPinballGame->unk132c->unk10.y << 8;
        gCurrentPinballGame->unk132c->unkE = 128;
        gCurrentPinballGame->unk132c->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk730 = 0;
        gCurrentPinballGame->unk2A2 = 5;
        gCurrentPinballGame->unk4C = 0;
        gCurrentPinballGame->unk4E = 118;
        break;
    case 2:
        gCurrentPinballGame->unk132c->unk10.x = -28;
        gCurrentPinballGame->unk132c->unk10.y = -10;
        gCurrentPinballGame->unk132c->velocity.x = 0;
        gCurrentPinballGame->unk132c->velocity.y = 0;
        gCurrentPinballGame->unk132c->unk6 = 0;
        gCurrentPinballGame->unk132c->position.x = gCurrentPinballGame->unk132c->unk10.x << 8;
        gCurrentPinballGame->unk132c->position.y = gCurrentPinballGame->unk132c->unk10.y << 8;
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
        gMain.unk44 = gUnknown_086B02CC[gMain.selectedField];
        break;
    case FIELD_SAPPHIRE:
        gUnknown_020028D8[3] = gUnknown_086B077C[4];
        gUnknown_020028D8[7] = gUnknown_086B077C[16];
        gUnknown_020028D8[0] = gUnknown_086B077C[20];
        gUnknown_020028D8[4] = gUnknown_086B077C[11];
        gUnknown_020028D8[2] = gUnknown_086B077C[1];
        gUnknown_020028D8[5] = gUnknown_086B077C[13];
        gMain.unk44 = gUnknown_086B02CC[gMain.selectedField];
        break;
    case FIELD_DUSCLOPS:
        gUnknown_020028D8[3] = gUnknown_086B077C[5];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[21];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = gUnknown_086B04AC[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KECLEON:
        gUnknown_020028D8[3] = gUnknown_086B077C[6];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[22];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = gUnknown_086B04AC[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KYOGRE:
        gUnknown_020028D8[3] = gUnknown_086B077C[7];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[23];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = gUnknown_086B04AC[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_GROUDON:
        gUnknown_020028D8[3] = gUnknown_086B077C[8];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[24];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = gUnknown_086B04AC[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_RAYQUAZA:
        gUnknown_020028D8[3] = gUnknown_086B077C[9];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[25];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = gUnknown_086B04AC[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_SPHEAL:
        gUnknown_020028D8[3] = gUnknown_086B077C[10];
        gUnknown_020028D8[7] = gUnknown_086B077C[17];
        gUnknown_020028D8[0] = gUnknown_086B077C[26];
        gUnknown_020028D8[4] = gUnknown_086B077C[12];
        gUnknown_020028D8[2] = gUnknown_086B077C[2];
        gUnknown_020028D8[5] = gUnknown_086B077C[14];
        gMain.unk44 = gUnknown_086B04AC[gMain.selectedField - FIELD_DUSCLOPS];
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
            if (gMain.selectedField < MAIN_FIELD_COUNT)
            {
                sub_1D4D0();
                sub_31BE8(0);
            }
            else if (gMain.selectedField == FIELD_DUSCLOPS)
            {
                sub_356A0();
            }
            else if (gMain.selectedField == FIELD_KYOGRE)
            {
                sub_3ADA0();
            }
            else if (gMain.selectedField == FIELD_GROUDON)
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

    UpdateButtonActionsFromJoy();
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

    UpdateButtonActionsFromJoy();
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
        if (gMain.selectedField >= MAIN_FIELD_COUNT)
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

void UpdateButtonActionsFromJoy(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gCurrentPinballGame->newButtonActions[i] = 0;
        gCurrentPinballGame->releasedButtonActions[i] = 0;
    }

    if (gMain.unkF)
        return;

    for (i =  0; i < 5; i++)
    {
        int buttonConfigKeyMask = (gMain.buttonConfigs[i][0] | gMain.buttonConfigs[i][1]) & KEYS_MASK;
        if (buttonConfigKeyMask == JOY_HELD(buttonConfigKeyMask))
        {
            if (gCurrentPinballGame->heldButtonActions[i] == 0)
                gCurrentPinballGame->newButtonActions[i] = 1;

            gCurrentPinballGame->heldButtonActions[i] = 1;
        }
        else
        {
            if (gCurrentPinballGame->heldButtonActions[i])
                gCurrentPinballGame->releasedButtonActions[i] = 1;

            gCurrentPinballGame->heldButtonActions[i] = 0;
        }
    }
}

void sub_4B334(void)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        gCurrentPinballGame->newButtonActions[i] = 0;
        gCurrentPinballGame->releasedButtonActions[i] = 0;
    }

    if (gMain.unkF)
        return;

    if (gUnknown_02031510 < 60 * 60)
    {
        for (i =  0; i < 5; i++)
        {
            gCurrentPinballGame->newButtonActions[i] = (gUnknown_02031520.unk10[gUnknown_02031510].unk0 >> i) & 0x1;
            gCurrentPinballGame->releasedButtonActions[i] = (gUnknown_02031520.unk10[gUnknown_02031510].unk1 >> i) & 0x1;
            gCurrentPinballGame->heldButtonActions[i] = (gUnknown_02031520.unk10[gUnknown_02031510].unk2 >> i) & 0x1;
        }

        gUnknown_02031510++;
    }

    if (gCurrentPinballGame->newButtonActions[1])
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
        if (arg0 == 1 && gMain.selectedField < MAIN_FIELD_COUNT)
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

    if (gMain.selectedField < MAIN_FIELD_COUNT)
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
        if (gCurrentPinballGame->unk13 == 6)
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
    case FIELD_DUSCLOPS:
        sub_50D48();
        break;
    case FIELD_KECLEON:
        sub_50DE0();
        break;
    case FIELD_KYOGRE:
        sub_50F04();
        break;
    case FIELD_GROUDON:
        sub_50FD4();
        break;
    case FIELD_RAYQUAZA:
        sub_51090();
        break;
    case FIELD_SPHEAL:
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
    case FIELD_DUSCLOPS:
        nullsub_18();
        sub_4CAE8();
        break;
    case FIELD_KECLEON:
        nullsub_18();
        sub_4CB0C();
        break;
    case FIELD_KYOGRE:
        nullsub_18();
        sub_4CB30();
        break;
    case FIELD_GROUDON:
        nullsub_18();
        sub_4CBB4();
        break;
    case FIELD_RAYQUAZA:
        nullsub_18();
        sub_4CC58();
        break;
    case FIELD_SPHEAL:
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

NAKED
void sub_4C290(void)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	bl sub_28AE0\n\
	bl sub_28BFC\n\
	movs r1, #0\n\
	ldr r0, _0804C3B8 @ =gCurrentPinballGame\n\
	ldr r4, [r0]\n\
	ldr r3, _0804C3BC @ =0x040000D4\n\
	mov sb, r0\n\
_0804C2AE:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r0, r4, r0\n\
	ldr r1, _0804C3C0 @ =0x000013BC\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsrs r1, r0, #0x1f\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #1\n\
	lsls r0, r0, #9\n\
	ldr r1, _0804C3C4 @ =gUnknown_083FE44C\n\
	adds r0, r0, r1\n\
	str r0, [r3]\n\
	lsls r0, r2, #9\n\
	ldr r5, _0804C3C8 @ =0x06010000\n\
	adds r0, r0, r5\n\
	str r0, [r3, #4]\n\
	ldr r0, _0804C3CC @ =0x80000100\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _0804C2AE\n\
	mov r1, sb\n\
	ldr r0, [r1]\n\
	ldr r2, _0804C3D0 @ =0x0000132C\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	ldrh r0, [r0, #0xa]\n\
	ldr r2, _0804C3BC @ =0x040000D4\n\
	lsrs r0, r0, #0xc\n\
	lsls r0, r0, #7\n\
	ldr r1, _0804C3D4 @ =gUnknown_083BB16C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0804C3D8 @ =0x06010400\n\
	str r0, [r2, #4]\n\
	ldr r0, _0804C3DC @ =0x80000040\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	movs r1, #0\n\
	ldr r5, _0804C3E0 @ =gUnknown_084C07EC\n\
	ldr r6, _0804C3E4 @ =gUnknown_084FA48C\n\
	ldr r7, _0804C3E8 @ =gUnknown_084C00EC\n\
	adds r3, r2, #0\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	ldr r2, _0804C3EC @ =0x00000744\n\
	adds r4, r0, r2\n\
_0804C320:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r4, r2\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	adds r0, r0, r5\n\
	str r0, [r3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #7\n\
	ldr r1, _0804C3F0 @ =0x06010480\n\
	adds r0, r0, r1\n\
	str r0, [r3, #4]\n\
	ldr r0, _0804C3F4 @ =0x800000C0\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _0804C320\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	ldr r3, _0804C3F8 @ =0x000001E5\n\
	adds r0, r0, r3\n\
	ldr r2, _0804C3BC @ =0x040000D4\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #5\n\
	adds r0, r0, r6\n\
	str r0, [r2]\n\
	ldr r0, _0804C3FC @ =0x06010780\n\
	str r0, [r2, #4]\n\
	ldr r0, _0804C400 @ =0x80000090\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	mov r5, sb\n\
	ldr r0, [r5]\n\
	movs r1, #0xe5\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r3, [r0]\n\
	mov sl, r3\n\
	movs r5, #0\n\
	ldrsh r0, [r0, r5]\n\
	lsls r0, r0, #7\n\
	adds r0, r0, r7\n\
	str r0, [r2]\n\
	ldr r0, _0804C404 @ =0x06010AE0\n\
	str r0, [r2, #4]\n\
	ldr r0, _0804C3DC @ =0x80000040\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	movs r1, #0\n\
_0804C396:\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	lsls r2, r1, #0x10\n\
	asrs r1, r2, #0x10\n\
	ldr r3, _0804C408 @ =0x00000747\n\
	adds r0, r0, r3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	adds r7, r2, #0\n\
	cmp r0, #9\n\
	bls _0804C3AE\n\
	b _0804C602\n\
_0804C3AE:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0804C40C @ =_0804C410\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0804C3B8: .4byte gCurrentPinballGame\n\
_0804C3BC: .4byte 0x040000D4\n\
_0804C3C0: .4byte 0x000013BC\n\
_0804C3C4: .4byte gUnknown_083FE44C\n\
_0804C3C8: .4byte 0x06010000\n\
_0804C3CC: .4byte 0x80000100\n\
_0804C3D0: .4byte 0x0000132C\n\
_0804C3D4: .4byte gUnknown_083BB16C\n\
_0804C3D8: .4byte 0x06010400\n\
_0804C3DC: .4byte 0x80000040\n\
_0804C3E0: .4byte gUnknown_084C07EC\n\
_0804C3E4: .4byte gUnknown_084FA48C\n\
_0804C3E8: .4byte gUnknown_084C00EC\n\
_0804C3EC: .4byte 0x00000744\n\
_0804C3F0: .4byte 0x06010480\n\
_0804C3F4: .4byte 0x800000C0\n\
_0804C3F8: .4byte 0x000001E5\n\
_0804C3FC: .4byte 0x06010780\n\
_0804C400: .4byte 0x80000090\n\
_0804C404: .4byte 0x06010AE0\n\
_0804C408: .4byte 0x00000747\n\
_0804C40C: .4byte _0804C410\n\
_0804C410: @ jump table\n\
	.4byte _0804C438 @ case 0\n\
	.4byte _0804C5D4 @ case 1\n\
	.4byte _0804C5D4 @ case 2\n\
	.4byte _0804C55E @ case 3\n\
	.4byte _0804C5D4 @ case 4\n\
	.4byte _0804C602 @ case 5\n\
	.4byte _0804C5D4 @ case 6\n\
	.4byte _0804C5D4 @ case 7\n\
	.4byte _0804C5D4 @ case 8\n\
	.4byte _0804C460 @ case 9\n\
_0804C438:\n\
	ldr r3, _0804C454 @ =0x040000D4\n\
	mov r5, sb\n\
	ldr r0, [r5]\n\
	asrs r2, r7, #0x10\n\
	ldr r1, _0804C458 @ =0x00000749\n\
	adds r0, r0, r1\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r1, _0804C45C @ =gUnknown_0848D68C\n\
	b _0804C5EC\n\
	.align 2, 0\n\
_0804C454: .4byte 0x040000D4\n\
_0804C458: .4byte 0x00000749\n\
_0804C45C: .4byte gUnknown_0848D68C\n\
_0804C460:\n\
	mov r5, sb\n\
	ldr r4, [r5]\n\
	movs r1, #0x97\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	ble _0804C510\n\
	ldr r1, _0804C498 @ =gMain+0x74\n\
	ldr r2, _0804C49C @ =0x0000059A\n\
	adds r0, r4, r2\n\
	ldrh r3, [r0]\n\
	adds r1, r3, r1\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _0804C4AC\n\
	asrs r3, r7, #0x10\n\
	ldr r2, _0804C4A0 @ =0x00000749\n\
	adds r0, r4, r2\n\
	adds r0, r0, r3\n\
	movs r1, #0xcd\n\
	strb r1, [r0]\n\
	ldr r6, _0804C4A4 @ =0x040000D4\n\
	ldr r5, _0804C4A8 @ =gMonPortraitGroupPals\n\
	mov r8, r5\n\
	b _0804C528\n\
	.align 2, 0\n\
_0804C498: .4byte gMain+0x74\n\
_0804C49C: .4byte 0x0000059A\n\
_0804C4A0: .4byte 0x00000749\n\
_0804C4A4: .4byte 0x040000D4\n\
_0804C4A8: .4byte gMonPortraitGroupPals\n\
_0804C4AC:\n\
	cmp r0, #3\n\
	bhi _0804C4E8\n\
	asrs r1, r7, #0x10\n\
	ldr r2, _0804C4D4 @ =0x00000749\n\
	adds r0, r4, r2\n\
	adds r0, r0, r1\n\
	strb r3, [r0]\n\
	ldr r1, _0804C4D8 @ =0x040000D4\n\
	ldr r0, _0804C4DC @ =gMonPortraitGroupPals\n\
	ldr r0, [r0]\n\
	movs r3, #0xf0\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	str r0, [r1]\n\
	ldr r0, _0804C4E0 @ =0x050003A0\n\
	str r0, [r1, #4]\n\
	ldr r0, _0804C4E4 @ =0x80000010\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _0804C55E\n\
	.align 2, 0\n\
_0804C4D4: .4byte 0x00000749\n\
_0804C4D8: .4byte 0x040000D4\n\
_0804C4DC: .4byte gMonPortraitGroupPals\n\
_0804C4E0: .4byte 0x050003A0\n\
_0804C4E4: .4byte 0x80000010\n\
_0804C4E8:\n\
	asrs r2, r7, #0x10\n\
	ldr r1, _0804C504 @ =0x00000749\n\
	adds r0, r4, r1\n\
	adds r0, r0, r2\n\
	strb r3, [r0]\n\
	ldr r6, _0804C508 @ =0x040000D4\n\
	ldr r5, _0804C50C @ =gMonPortraitGroupPals\n\
	mov r8, r5\n\
	mov r3, sb\n\
	ldr r0, [r3]\n\
	adds r0, r0, r1\n\
	adds r0, r0, r2\n\
	b _0804C530\n\
	.align 2, 0\n\
_0804C504: .4byte 0x00000749\n\
_0804C508: .4byte 0x040000D4\n\
_0804C50C: .4byte gMonPortraitGroupPals\n\
_0804C510:\n\
	asrs r3, r7, #0x10\n\
	ldr r2, _0804C5B4 @ =0x00000749\n\
	adds r1, r4, r2\n\
	adds r1, r1, r3\n\
	movs r5, #0xb3\n\
	lsls r5, r5, #3\n\
	adds r0, r4, r5\n\
	ldrh r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r6, _0804C5B8 @ =0x040000D4\n\
	ldr r0, _0804C5BC @ =gMonPortraitGroupPals\n\
	mov r8, r0\n\
_0804C528:\n\
	mov r1, sb\n\
	ldr r0, [r1]\n\
	adds r0, r0, r2\n\
	adds r0, r0, r3\n\
_0804C530:\n\
	ldrb r5, [r0]\n\
	adds r0, r5, #0\n\
	movs r1, #0xf\n\
	bl __udivsi3\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x16\n\
	add r4, r8\n\
	adds r0, r5, #0\n\
	movs r1, #0xf\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x13\n\
	ldr r1, [r4]\n\
	adds r1, r1, r0\n\
	str r1, [r6]\n\
	ldr r0, _0804C5C0 @ =0x050003A0\n\
	str r0, [r6, #4]\n\
	ldr r0, _0804C5C4 @ =0x80000010\n\
	str r0, [r6, #8]\n\
	ldr r0, [r6, #8]\n\
_0804C55E:\n\
	ldr r2, _0804C5B8 @ =0x040000D4\n\
	ldr r3, _0804C5C8 @ =gMonPortraitGroupGfx\n\
	mov r8, r3\n\
	mov r5, sb\n\
	ldr r0, [r5]\n\
	asrs r6, r7, #0x10\n\
	ldr r1, _0804C5B4 @ =0x00000749\n\
	adds r0, r0, r1\n\
	adds r0, r0, r6\n\
	ldrb r5, [r0]\n\
	adds r0, r5, #0\n\
	movs r1, #0xf\n\
	str r2, [sp]\n\
	bl __udivsi3\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x16\n\
	add r4, r8\n\
	adds r0, r5, #0\n\
	movs r1, #0xf\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #8\n\
	ldr r0, [r4]\n\
	adds r0, r0, r1\n\
	ldr r2, [sp]\n\
	str r0, [r2]\n\
	lsls r0, r6, #1\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #3\n\
	ldr r3, _0804C5CC @ =0x06010CA0\n\
	adds r0, r0, r3\n\
	str r0, [r2, #4]\n\
	ldr r0, _0804C5D0 @ =0x80000180\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	b _0804C602\n\
	.align 2, 0\n\
_0804C5B4: .4byte 0x00000749\n\
_0804C5B8: .4byte 0x040000D4\n\
_0804C5BC: .4byte gMonPortraitGroupPals\n\
_0804C5C0: .4byte 0x050003A0\n\
_0804C5C4: .4byte 0x80000010\n\
_0804C5C8: .4byte gMonPortraitGroupGfx\n\
_0804C5CC: .4byte 0x06010CA0\n\
_0804C5D0: .4byte 0x80000180\n\
_0804C5D4:\n\
	ldr r3, _0804C630 @ =0x040000D4\n\
	mov r5, sb\n\
	ldr r0, [r5]\n\
	asrs r2, r7, #0x10\n\
	ldr r1, _0804C634 @ =0x00000749\n\
	adds r0, r0, r1\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r1, _0804C638 @ =gUnknown_083A8EEC\n\
_0804C5EC:\n\
	adds r0, r0, r1\n\
	str r0, [r3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #8\n\
	ldr r2, _0804C63C @ =0x06010CA0\n\
	adds r0, r0, r2\n\
	str r0, [r3, #4]\n\
	ldr r0, _0804C640 @ =0x80000180\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
_0804C602:\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r0, r7, r3\n\
	lsrs r1, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bgt _0804C612\n\
	b _0804C396\n\
_0804C612:\n\
	mov r5, sb\n\
	ldr r1, [r5]\n\
	movs r0, #0x13\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #4\n\
	bne _0804C69C\n\
	movs r0, #0x17\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #7\n\
	blt _0804C69C\n\
	cmp r0, #8\n\
	ble _0804C644\n\
	cmp r0, #9\n\
	beq _0804C660\n\
	b _0804C69C\n\
	.align 2, 0\n\
_0804C630: .4byte 0x040000D4\n\
_0804C634: .4byte 0x00000749\n\
_0804C638: .4byte gUnknown_083A8EEC\n\
_0804C63C: .4byte 0x06010CA0\n\
_0804C640: .4byte 0x80000180\n\
_0804C644:\n\
	ldr r2, _0804C654 @ =0x000005A9\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bls _0804C68C\n\
	ldr r1, _0804C658 @ =0x040000D4\n\
	ldr r0, _0804C65C @ =gUnknown_02031060\n\
	b _0804C690\n\
	.align 2, 0\n\
_0804C654: .4byte 0x000005A9\n\
_0804C658: .4byte 0x040000D4\n\
_0804C65C: .4byte gUnknown_02031060\n\
_0804C660:\n\
	movs r3, #0xb5\n\
	lsls r3, r3, #3\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0x1f\n\
	bgt _0804C69C\n\
	ldr r5, _0804C680 @ =0x000005A9\n\
	adds r0, r1, r5\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bls _0804C68C\n\
	ldr r1, _0804C684 @ =0x040000D4\n\
	ldr r0, _0804C688 @ =gUnknown_02031060\n\
	b _0804C690\n\
	.align 2, 0\n\
_0804C680: .4byte 0x000005A9\n\
_0804C684: .4byte 0x040000D4\n\
_0804C688: .4byte gUnknown_02031060\n\
_0804C68C:\n\
	ldr r1, _0804C6B8 @ =0x040000D4\n\
	ldr r0, _0804C6BC @ =gUnknown_02030760\n\
_0804C690:\n\
	str r0, [r1]\n\
	ldr r0, _0804C6C0 @ =0x06010CA0\n\
	str r0, [r1, #4]\n\
	ldr r0, _0804C6C4 @ =0x80000240\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
_0804C69C:\n\
	mov r0, sb\n\
	ldr r1, [r0]\n\
	movs r0, #0x13\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #8\n\
	bne _0804C720\n\
	movs r0, #0x17\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #2\n\
	beq _0804C6C8\n\
	cmp r0, #3\n\
	beq _0804C6E4\n\
	b _0804C720\n\
	.align 2, 0\n\
_0804C6B8: .4byte 0x040000D4\n\
_0804C6BC: .4byte gUnknown_02030760\n\
_0804C6C0: .4byte 0x06010CA0\n\
_0804C6C4: .4byte 0x80000240\n\
_0804C6C8:\n\
	ldr r2, _0804C6D8 @ =0x000005A9\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bls _0804C710\n\
	ldr r1, _0804C6DC @ =0x040000D4\n\
	ldr r0, _0804C6E0 @ =gUnknown_02031060\n\
	b _0804C714\n\
	.align 2, 0\n\
_0804C6D8: .4byte 0x000005A9\n\
_0804C6DC: .4byte 0x040000D4\n\
_0804C6E0: .4byte gUnknown_02031060\n\
_0804C6E4:\n\
	movs r3, #0xb5\n\
	lsls r3, r3, #3\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0x1f\n\
	bgt _0804C720\n\
	ldr r5, _0804C704 @ =0x000005A9\n\
	adds r0, r1, r5\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bls _0804C710\n\
	ldr r1, _0804C708 @ =0x040000D4\n\
	ldr r0, _0804C70C @ =gUnknown_02031060\n\
	b _0804C714\n\
	.align 2, 0\n\
_0804C704: .4byte 0x000005A9\n\
_0804C708: .4byte 0x040000D4\n\
_0804C70C: .4byte gUnknown_02031060\n\
_0804C710:\n\
	ldr r1, _0804C7C4 @ =0x040000D4\n\
	ldr r0, _0804C7C8 @ =gUnknown_02030760\n\
_0804C714:\n\
	str r0, [r1]\n\
	ldr r0, _0804C7CC @ =0x06010CA0\n\
	str r0, [r1, #4]\n\
	ldr r0, _0804C7D0 @ =0x80000240\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
_0804C720:\n\
	ldr r2, _0804C7C4 @ =0x040000D4\n\
	mov r1, sb\n\
	ldr r0, [r1]\n\
	ldr r3, _0804C7D4 @ =0x0000020B\n\
	adds r0, r0, r3\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r5, _0804C7D8 @ =gUnknown_0844838C\n\
	adds r0, r0, r5\n\
	str r0, [r2]\n\
	ldr r0, _0804C7DC @ =0x060113C0\n\
	str r0, [r2, #4]\n\
	ldr r0, _0804C7E0 @ =0x80000180\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	mov r1, sb\n\
	ldr r0, [r1]\n\
	adds r3, #0x54\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	ldr r5, _0804C7E4 @ =gUnknown_086AD49C\n\
	adds r0, r0, r5\n\
	mov r3, sl\n\
	lsls r1, r3, #0x10\n\
	asrs r1, r1, #7\n\
	ldr r0, [r0]\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0804C7E8 @ =0x060116C0\n\
	str r0, [r2, #4]\n\
	ldr r3, _0804C7EC @ =0x80000100\n\
	str r3, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	mov r5, sb\n\
	ldr r0, [r5]\n\
	ldr r1, _0804C7F0 @ =0x000001ED\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #3\n\
	ldr r1, _0804C7F4 @ =gUnknown_086AD2EE\n\
	adds r1, #6\n\
	adds r0, r0, r1\n\
	movs r5, #0\n\
	ldrsh r0, [r0, r5]\n\
	lsls r0, r0, #9\n\
	ldr r1, _0804C7F8 @ =gUnknown_084FD18C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0804C7FC @ =0x06011CE0\n\
	str r0, [r2, #4]\n\
	str r3, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	mov r5, sb\n\
	ldr r0, [r5]\n\
	adds r0, #0x6e\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #9\n\
	ldr r1, _0804C800 @ =gUnknown_083BD36C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0804C804 @ =0x06011EE0\n\
	str r0, [r2, #4]\n\
	str r3, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0804C7C4: .4byte 0x040000D4\n\
_0804C7C8: .4byte gUnknown_02030760\n\
_0804C7CC: .4byte 0x06010CA0\n\
_0804C7D0: .4byte 0x80000240\n\
_0804C7D4: .4byte 0x0000020B\n\
_0804C7D8: .4byte gUnknown_0844838C\n\
_0804C7DC: .4byte 0x060113C0\n\
_0804C7E0: .4byte 0x80000180\n\
_0804C7E4: .4byte gUnknown_086AD49C\n\
_0804C7E8: .4byte 0x060116C0\n\
_0804C7EC: .4byte 0x80000100\n\
_0804C7F0: .4byte 0x000001ED\n\
_0804C7F4: .4byte gUnknown_086AD2EE\n\
_0804C7F8: .4byte gUnknown_084FD18C\n\
_0804C7FC: .4byte 0x06011CE0\n\
_0804C800: .4byte gUnknown_083BD36C\n\
_0804C804: .4byte 0x06011EE0\n\
    ");
}

void sub_4C808(void)
{
    s16 i;
    s16 var0;

    var0 = gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][2];
    DmaCopy16(3, gUnknown_084FB68C[var0], (void *)0x60122A0, 0x480);
    var0 = (gMain.systemFrameCount % 50) / 25;
    DmaCopy16(3, gUnknown_083C3C2C[var0], (void *)0x6012720, 0x300);
    DmaCopy16(3, gUnknown_084F5ACC[gCurrentPinballGame->unk2F5], (void *)0x6012C20, 0x260);
    for (i = 0; i < 2; i++)
        DmaCopy16(3, gUnknown_083C806C[var0], (void *)0x6010000 + (0x174 + i * 8) * 0x20, 0x100);

    var0 = gCurrentPinballGame->unk2F1 & 0xF;
    DmaCopy16(3, gUnknown_084ED0CC[var0], (void *)0x6013180, 0x180);
    if (gCurrentPinballGame->unk2DA < 3)
        gCurrentPinballGame->unk746 = 0;
    else
        gCurrentPinballGame->unk746 = 1;

    DmaCopy16(3, gUnknown_08449D8C[gCurrentPinballGame->unk746], (void *)0x6013300, 0x280);
    var0 = gUnknown_086AD456[gCurrentPinballGame->unk1A5][(gCurrentPinballGame->unk1B4 % 42) / 6];
    DmaCopy16(3, gUnknown_084F6B0C[var0], (void *)0x6013D00, 0x500);
}

void sub_4CA18(void)
{
    s16 index;

    switch (gCurrentPinballGame->unk346)
    {
    case 0:
    case 1:
    case 2:
        index = gCurrentPinballGame->unk345;
        DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        break;
    case 3:
    case 4:
        index = 15;
        DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        break;
    case 5:
        index = gUnknown_086AE5A0[gCurrentPinballGame->unk345][0];
        DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        break;
    case 6:
        break;
    }
}

void sub_4CAE8(void)
{
    DmaCopy16(3, gUnknown_08138834, (void *)0x6015800, 0x2000);
}

void sub_4CB0C(void)
{
    DmaCopy16(3, gUnknown_0813A854, (void *)0x6015800, 0x2000);
}

void sub_4CB30(void)
{
    DmaCopy16(3, gUnknown_0813C874, (void *)0x6015800, 0x2000);
    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->unk749 / 15] + (gCurrentPinballGame->unk749 % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void sub_4CBB4(void)
{
    if (gCurrentPinballGame->unk13 < 2)
    {
        DmaCopy16(3, gUnknown_0849F1CC, (void *)0x6015800, 0x2000);
    }
    else
    {
        DmaCopy16(3, gUnknown_0813E894, (void *)0x6015800, 0x2000);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->unk749 / 15] + (gCurrentPinballGame->unk749 % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void sub_4CC58(void)
{
    u8 var0;

    if (gCurrentPinballGame->unk13 == 0)
    {
        DmaCopy16(3, gUnknown_083C5A2C, (void *)0x6015800, 0x2800);
    }
    else if (gCurrentPinballGame->unk13 == 1)
    {
        DmaCopy16(3, gUnknown_084A856C, (void *)0x6015800, 0x1C00);
    }
    else
    {
        DmaCopy16(3, gUnknown_081408B4, (void *)0x6015800, 0x2000);
    }

    var0 = gCurrentPinballGame->unk3DC - 2;
    if (var0 > 9)
    {
        DmaCopy16(3, gUnknown_084AA18C, (void *)0x6011620, 0x860);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->unk749 / 15] + (gCurrentPinballGame->unk749 % 15) * 0x300,
        (void *)0x6010CA0,
        0x300
    );
}

void sub_4CD60(void)
{
    s16 i;
    int var0;
    u16 var1;

    for (i = 0; i < 0x800; i++)
        gUnknown_03005C00[0x400 + i] = 0x200;

    DmaCopy16(3, &gUnknown_03005C00[0x400], (void *)0x6001000, 0x1000);
    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        var0 = i;
        if (i < 0)
            var0 += 31;

        var0 = (var0 >> 5) << 5;
        var1 = i - var0 - 2;
        if (var1 < 28)
            gUnknown_03005C00[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].xOffset = 8;
    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gUnknown_03005C00[0x800], (void *)0x6001140, 0x280);
    for (i = 0; i < 0x800; i++)
        gUnknown_03005C00[i] = 0x1FF;

    DmaCopy16(3, gUnknown_084B77EC, (void *)0x6015800, 0x800);
}

void nullsub_18(void)
{
}
