#include "global.h"
#include "agb_sram.h"
#include "main.h"
#include "m4a.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/ruby_states.h"

extern struct PinballGame gUnknown_02000000;

typedef void (*VoidFunc)(void);

struct Unk20028D8
{
    void (*unk0)(void);
    void (*unk4)(void);
};

extern struct Unk20028D8 CurrentBoardProcPairs_020028D8[9];
extern u8 gUnknown_0200FBB0[];
extern u8 gUnknown_020030A0[];

extern const struct Unk20028D8 BoardProcPairs_086B077C[];
extern const VoidFunc gUnknown_086B085C[];
extern struct SpriteGroup *gMainFieldSpriteGroups[][60];
extern struct SpriteGroup *gBonusFieldSpriteGroups[][30];
extern const u8 gUnknown_08158284[];
extern const u8 gUnknown_083A704C[];
extern const u8 gUnknown_0848FD8C[];
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
extern const u8 gMainBoardBallSave_Gfx[];
extern const u8 gMainBoardEndOfBall_Gfx[];
extern const u8 gSapphireBoardZigzagoonFx_Gfx[];
extern const s16 gUnknown_086ACFE0[];
extern const u16 gUnknown_086AD2DE[];
extern const u8 *gEvoItemAppear_GfxList[];
extern const s16 gUnknown_086AD456[][7];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u8 gUnknown_083C3C2C[][0x300];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const u8 gUnknown_083C806C[][0x100];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardShop_Gfx[][0x500];
extern const u8 gUnknown_08490A4C[][0x440];
extern const s16 gUnknown_086AE5A0[][2];
extern const u8 gKecleonBonusClear_Gfx[0x2000];
extern const u8 gKyogreBonusClear_Gfx[0x2000];
extern const u8 gUnknown_0849F1CC[0x2000];
extern const u8 gGroudonBonusClear_Gfx[0x2000];
extern const u8 gUnknown_083C5A2C[0x2800];
extern const u8 gUnknown_084A856C[0x1C00];
extern const u8 gRayquazaBonusClear_Gfx[0x2000];
extern const u8 gUnknown_084AA18C[0x860];
extern const u8 gUnknown_084B77EC[0x800];

extern const StateFunc gPinballGameStateFuncs[];
extern const u8 gUnknown_084C0C6C[];

void sub_1D4D0(void);
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

void PinballGame_State0_49ED4(void)
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
        loadIntroduction();
        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);

        sub_4A90C();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].unk0();

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
        loadIntroduction();
        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
            DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);

        sub_4A90C();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].unk0();

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
        loadIntroduction();
        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
        sub_4A90C();
        for (i = 0; i < 9; i++)
            CurrentBoardProcPairs_020028D8[i].unk0();

        sub_47110();
        break;
    }

    gUnknown_02031520.unk8 = 0;
    for (j = 0; j < NUM_SPECIES; j++)
    {
        if (gMain_saveData.pokedexFlags[j] > SPECIES_SHARED_AND_SEEN)
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

    gMain.dispcntBackup = REG_DISPCNT;
    REG_MOSAIC = 0;
}

void sub_4A518(void)
{
    gMain.modeChangeFlags = MODE_CHANGE_NONE;
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
            gCurrentPinballGame->outLanePikaPosition = 2;
            gMain.unk44[41]->available = FALSE;
            gCurrentPinballGame->unk1C0 = 1;
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
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

    gCurrentPinballGame->scoreAddStepSize = 40000;
    gCurrentPinballGame->unk1D = 0;
    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
    gCurrentPinballGame->unk1330 = &gCurrentPinballGame->unk1334[0];
    gCurrentPinballGame->unk66 = 0;
}

void sub_4A6A0(void)
{
    switch (gCurrentPinballGame->unk282)
    {
    case 0:
        gCurrentPinballGame->ball->positionQ0.x = 119;
        gCurrentPinballGame->ball->positionQ0.y = 279;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->unk0 = 1;
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
        gCurrentPinballGame->ball->positionQ0.x = 140;
        gCurrentPinballGame->ball->positionQ0.y = 183;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk730 = 0;
        gCurrentPinballGame->whiscashState = WHISCASH_STATE_INIT_RETURN_FROM_BONUS;
        gCurrentPinballGame->unk4C = 0;
        gCurrentPinballGame->unk4E = 118;
        break;
    case 2:
        gCurrentPinballGame->ball->positionQ0.x = -28;
        gCurrentPinballGame->ball->positionQ0.y = -10;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->scale = 0x80;
        gCurrentPinballGame->ball->unk0 = 1;
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
    CurrentBoardProcPairs_020028D8[1] = BoardProcPairs_086B077C[0];
    CurrentBoardProcPairs_020028D8[8] = BoardProcPairs_086B077C[18];
    CurrentBoardProcPairs_020028D8[6] = BoardProcPairs_086B077C[15];
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[3];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[16];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[19];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[11];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[1];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[13];
        gMain.unk44 = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_SAPPHIRE:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[4];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[16];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[20];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[11];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[1];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[13];
        gMain.unk44 = gMainFieldSpriteGroups[gMain.selectedField];
        break;
    case FIELD_DUSCLOPS:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[5];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[21];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.unk44 = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KECLEON:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[6];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[22];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.unk44 = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_KYOGRE:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[7];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[23];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.unk44 = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_GROUDON:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[8];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[24];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.unk44 = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_RAYQUAZA:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[9];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[25];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.unk44 = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    case FIELD_SPHEAL:
        CurrentBoardProcPairs_020028D8[3] = BoardProcPairs_086B077C[10];
        CurrentBoardProcPairs_020028D8[7] = BoardProcPairs_086B077C[17];
        CurrentBoardProcPairs_020028D8[0] = BoardProcPairs_086B077C[26];
        CurrentBoardProcPairs_020028D8[4] = BoardProcPairs_086B077C[12];
        CurrentBoardProcPairs_020028D8[2] = BoardProcPairs_086B077C[2];
        CurrentBoardProcPairs_020028D8[5] = BoardProcPairs_086B077C[14];
        gMain.unk44 = gBonusFieldSpriteGroups[gMain.selectedField - FIELD_DUSCLOPS];
        break;
    }
}

void PinballGame_State1_4AAD8(void)
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

            if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
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

//Note: Used by both the main game mode and the idle game mode
//gMain.subState = 2 in both.
void PinballGame_State2_4ABC8(void)
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
    CurrentBoardProcPairs_020028D8[1].unk4();
    if (gMain.unkE == 0 && !(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[2].unk4();
        CurrentBoardProcPairs_020028D8[0].unk4();
        CurrentBoardProcPairs_020028D8[3].unk4();
        CurrentBoardProcPairs_020028D8[4].unk4();
        if (gMain.modeChangeFlags)
        {
            if (!gCurrentPinballGame->unk1F)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    CurrentBoardProcPairs_020028D8[6].unk4();
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
                        CurrentBoardProcPairs_020028D8[5].unk4();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    CurrentBoardProcPairs_020028D8[5].unk4();
                    CurrentBoardProcPairs_020028D8[6].unk4();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].unk4();
        CurrentBoardProcPairs_020028D8[8].unk4();
    }

    sub_47030();
}

void sub_4ACF0(void)
{
    s16 i;

    sub_4B334();
    CurrentBoardProcPairs_020028D8[1].unk4();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[2].unk4();
        CurrentBoardProcPairs_020028D8[0].unk4();
        CurrentBoardProcPairs_020028D8[3].unk4();
        CurrentBoardProcPairs_020028D8[4].unk4();
        if (gMain.modeChangeFlags)
        {
            if (!gCurrentPinballGame->unk1F)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    CurrentBoardProcPairs_020028D8[6].unk4();
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
                        CurrentBoardProcPairs_020028D8[5].unk4();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk1E = i;
                    CurrentBoardProcPairs_020028D8[5].unk4();
                    CurrentBoardProcPairs_020028D8[6].unk4();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].unk4();
        CurrentBoardProcPairs_020028D8[8].unk4();
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
    CurrentBoardProcPairs_020028D8[1].unk4();
    if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
        return;

    CurrentBoardProcPairs_020028D8[0].unk4();
    CurrentBoardProcPairs_020028D8[2].unk4();
    CurrentBoardProcPairs_020028D8[3].unk4();
    CurrentBoardProcPairs_020028D8[4].unk4();
    if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
    {
        if (!gCurrentPinballGame->unk1F)
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->unk66 = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                gCurrentPinballGame->unk1E = i;
                CurrentBoardProcPairs_020028D8[6].unk4();
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
                gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                gCurrentPinballGame->unk1E = 0;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk66 = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = i;
                    CurrentBoardProcPairs_020028D8[5].unk4();
                }
            }
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                gCurrentPinballGame->unk66 = 0;
                gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                gCurrentPinballGame->unk1E = i;
                CurrentBoardProcPairs_020028D8[5].unk4();
                CurrentBoardProcPairs_020028D8[6].unk4();
            }
        }
    }

    CurrentBoardProcPairs_020028D8[7].unk4();
    CurrentBoardProcPairs_020028D8[8].unk4();
}

void sub_4B000(void)
{
    s16 i;

    sub_4B334();
    if (!(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
    {
        CurrentBoardProcPairs_020028D8[0].unk4();
        CurrentBoardProcPairs_020028D8[2].unk4();
        CurrentBoardProcPairs_020028D8[3].unk4();
        CurrentBoardProcPairs_020028D8[4].unk4();
        if (gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS)
        {
            if (!gCurrentPinballGame->unk1F)
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk66 = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = i;
                    CurrentBoardProcPairs_020028D8[6].unk4();
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
                    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = 0;
                }
                else
                {
                    for (i = 0; i < 4; i++)
                    {
                        gCurrentPinballGame->unk66 = 0;
                        gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                        gCurrentPinballGame->unk1E = i;
                        CurrentBoardProcPairs_020028D8[5].unk4();
                    }
                }
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    gCurrentPinballGame->unk66 = 0;
                    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
                    gCurrentPinballGame->unk1E = i;
                    CurrentBoardProcPairs_020028D8[5].unk4();
                    CurrentBoardProcPairs_020028D8[6].unk4();
                }
            }
        }

        CurrentBoardProcPairs_020028D8[7].unk4();
        CurrentBoardProcPairs_020028D8[8].unk4();
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

void PinballGame_State3_4B20C(void)
{
    gMain.unk36 = 0;
    sub_02B4();
    m4aMPlayAllStop();
    sub_0D10();
    gMain.finalScoreLo = gCurrentPinballGame->scoreLo;
    gMain.finalScoreHi = gCurrentPinballGame->scoreHi;
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

    if (gMain.modeChangeFlags)
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

    if (gMain.modeChangeFlags)
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
    gCurrentPinballGame->unk1101 = gMain.modeChangeFlags;
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
        gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
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
        gMain.modeChangeFlags = gCurrentPinballGame->unk1101;
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
    loadIntroduction();
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
                DmaCopy16(3, &gUnknown_0200FBB0[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
            }
            else
            {
                var0 -= 32;
                DmaCopy16(3, &gUnknown_020030A0[var0 * 0x400], (void *)0x6008000 + var1 * 0x400, 0x400);
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
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    sub_4BC34();
    switch (gMain.selectedField)
    {
    case FIELD_RUBY:
        RubyBoardProcess_0A_50848();
        sub_4E9F0(gCurrentPinballGame->unk1A5);
        break;
    case FIELD_SAPPHIRE:
        SapphireBoardProcess_0A_50AD4();
        break;
    case FIELD_DUSCLOPS:
        DusclopsBoardProcess_0A_50D48();
        break;
    case FIELD_KECLEON:
        KecleonBoardProcess_0A_50DE0();
        break;
    case FIELD_KYOGRE:
        KyogreBoardProcess_0A_50F04();
        break;
    case FIELD_GROUDON:
        GroudonBoardProcess_0A_50FD4();
        break;
    case FIELD_RAYQUAZA:
        RayquazaBoardProcess_0A_51090();
        break;
    case FIELD_SPHEAL:
        SphealBoardProcess_0A_51150();
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
    const u16 *var1;
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
        if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->unk1C2 == 2)
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
        DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->unk25F], (void *)0x6015800, 0x1C00);
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
            var1 = gUnknown_086AD000[gUnknown_086AD2DE[gCurrentPinballGame->unk1A6]];
            var2 = var1[3] / 10;
            DmaCopy16(3, gUnknown_08480E0C[var2], (void *)0x6015DA0, 0x40);
            var3 = var1[3] % 10;
            DmaCopy16(3, gUnknown_08480E0C[var3], (void *)0x6015E60, 0x40);
        }
        break;
    case 18:
        DmaCopy16(3, gMainBoardBallSave_Gfx, (void *)0x6015800, 0x2400);
        break;
    case 19:
        DmaCopy16(3, gMainBoardEndOfBall_Gfx, (void *)0x6015800, 0x2800);
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
        DmaCopy16(3, gSapphireBoardZigzagoonFx_Gfx, (void *)0x6015800, 0xC00);
        break;
    }
}

void sub_4C290(void)
{
    s16 i;
    s16 var0;

    sub_28AE0();
    sub_28BFC();

    for (i = 0; i <= 1; i++)
    {
        var0 = gCurrentPinballGame->flipper[i].position / 2;
        DmaCopy16(3, gUnknown_083FE44C[var0], ((i * 0x200) + 0x06010000), 0x200);
    }

    var0 = gCurrentPinballGame->ball->unkA / 0x1000;
    DmaCopy16(3, gUnknown_083BB16C[var0], 0x06010400, 0x80);

    for (i = 0; i <= 1; i++)
    {
        DmaCopy16(3, gUnknown_084C07EC + ((var0 =gCurrentPinballGame->unk744[i]) * 0x180), 0x06010480 + (i * 0x180), 0x180);
    }

    var0 = gCurrentPinballGame->unk1E5;
    DmaCopy16(3, gMainBoardPikaSpinner_Gfx[var0 = gCurrentPinballGame->unk1E5], 0x06010780, 0x120);
    var0 = gCurrentPinballGame->unk1CA;
    DmaCopy16(3, gUnknown_084C00EC[var0], 0x06010AE0, 0x80);

    for (i = 0; i <= 1; i++)
    {
        switch (gCurrentPinballGame->unk747[i])
        {
        case 0:
            DmaCopy16(3, gUnknown_0848D68C[gCurrentPinballGame->unk749[i]], 0x06010CA0 + (i * 0x300), 0x300);
            gCurrentPinballGame->ball += 0; //TODO: Dumb match is still a match...
            break;
        case 9:
            if (gCurrentPinballGame->unk25C > 0)
            {
                if (gMain_saveData.pokedexFlags[gCurrentPinballGame->unk59A] == 0)
                {
                    gCurrentPinballGame->unk749[i] = 205;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->unk749[i] / 15] + (gCurrentPinballGame->unk749[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
                else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->unk59A] <= 3)
                {
                    gCurrentPinballGame->unk749[i] = gCurrentPinballGame->unk59A;
                    DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, 0x050003A0, 0x20);
                }
                else
                {
                    gCurrentPinballGame->unk749[i] = gCurrentPinballGame->unk59A;
                    DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->unk749[i] / 15] + (gCurrentPinballGame->unk749[i] % 15) * 0x20, 0x050003A0, 0x20);
                }
            }
            else
            {
                gCurrentPinballGame->unk749[i] = gCurrentPinballGame->currentSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[gCurrentPinballGame->unk749[i] / 15] + ((gCurrentPinballGame->unk749[i] % 15) * 0x20), 0x050003A0, 0x20);
            }
        case 3:
            DmaCopy16(3, gMonPortraitGroupGfx[gCurrentPinballGame->unk749[i] / 15] + (gCurrentPinballGame->unk749[i] % 15) * 0x300, 0x06010CA0 + (i * 0x18), 0x300);
            break;
        case 1:
        case 2:
        case 4:
        case 6:
        case 7:
        case 8:
            DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->unk749[i]], 0x06010CA0 + (i * 0x300), 0x300);
            break;
        }
    }

    if (gCurrentPinballGame->unk13 == 4)
    {
        switch (gCurrentPinballGame->unk17)
        {
        case 7:
        case 8:
            if ((u32) gCurrentPinballGame->unk5A9 > 4)
            {
                DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
            }
            break;
        case 9:
            if (gCurrentPinballGame->unk5A8 <= 31)
            {
                if (gCurrentPinballGame->unk5A9 > 4)
                {
                    DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
                }
            }
            break;
        }
    }

    if (gCurrentPinballGame->unk13 == 8)
    {
        switch (gCurrentPinballGame->unk17)
        {
        case 2:
            if (gCurrentPinballGame->unk5A9 > 4U)
            {
                DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
            }
            else
            {
                DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
            }
            break;
        case 3:
            if (gCurrentPinballGame->unk5A8 <= 31)
            {
                if (gCurrentPinballGame->unk5A9 > 4U)
                {
                    DmaCopy16(3, gUnknown_02031060, 0x06010CA0, 0x480);
                }
                else
                {
                    DmaCopy16(3, gUnknown_02030760, 0x06010CA0, 0x480);
                }
            }
            break;
        }
    }

    DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->unk20B], 0x060113C0, 0x300);
    DmaCopy16(3, gUnknown_086AD49C[gCurrentPinballGame->unk25F] +  var0 * 0x200, 0x060116C0, 0x200);
    DmaCopy16(3, gUnknown_084FD18C[(s16)gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][3]], 0x06011CE0, 0x200);
    DmaCopy16(3, gUnknown_083BD36C[gCurrentPinballGame->unk6E], 0x06011EE0, 0x200);
    return;
}


void sub_4C808(void)
{
    s16 i;
    s16 var0;

    var0 = gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][2];
    DmaCopy16(3, gRubyBoardHatchCave_Gfx[var0], (void *)0x60122A0, 0x480);
    var0 = (gMain.systemFrameCount % 50) / 25;
    DmaCopy16(3, gUnknown_083C3C2C[var0], (void *)0x6012720, 0x300);
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->unk2F5], (void *)0x6012C20, 0x260);
    for (i = 0; i < 2; i++)
        DmaCopy16(3, gUnknown_083C806C[var0], (void *)0x6010000 + (0x174 + i * 8) * 0x20, 0x100);

    var0 = gCurrentPinballGame->unk2F1 & 0xF;
    DmaCopy16(3, gRubyBoardShopDoor_Gfx[var0], (void *)0x6013180, 0x180);
    if (gCurrentPinballGame->unk2DA < 3)
        gCurrentPinballGame->unk746 = 0;
    else
        gCurrentPinballGame->unk746 = 1;

    DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->unk746], (void *)0x6013300, 0x280);
    var0 = gUnknown_086AD456[gCurrentPinballGame->unk1A5][(gCurrentPinballGame->unk1B4 % 42) / 6];
    DmaCopy16(3, gRubyBoardShop_Gfx[var0], (void *)0x6013D00, 0x500);
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
    DmaCopy16(3, gDusclopsBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void sub_4CB0C(void)
{
    DmaCopy16(3, gKecleonBonusClear_Gfx, (void *)0x6015800, 0x2000);
}

void sub_4CB30(void)
{
    DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x6015800, 0x2000);
    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->unk749[0] / 15] + (gCurrentPinballGame->unk749[0] % 15) * 0x300,
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
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->unk749[0] / 15] + (gCurrentPinballGame->unk749[0] % 15) * 0x300,
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
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x6015800, 0x2000);
    }

    var0 = gCurrentPinballGame->unk3DC - 2;
    if (var0 > 9)
    {
        DmaCopy16(3, gUnknown_084AA18C, (void *)0x6011620, 0x860);
    }

    DmaCopy16(
        3,
        gMonPortraitGroupGfx[gCurrentPinballGame->unk749[0] / 15] + (gCurrentPinballGame->unk749[0] % 15) * 0x300,
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
