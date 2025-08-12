#include "global.h"
#include "main.h"
#include "gbplayer.h"
#include "link.h"
#include "m4a.h"

static void InitGame(void);
static void sub_0B8C(void);
static void InitIntrHandlers(void);
static void ReadKeys(void);

void AgbMain(void)
{
    RegisterRamReset(0xFF);
    InitIntrHandlers();
    DmaCopy32(3, IntrMain, IntrMain_Buffer, sizeof(IntrMain_Buffer));
    INTR_VECTOR = IntrMain_Buffer;
    InitGame();
    InitGameBoyPlayer();
    while (1)
    {
        ReadKeys();
        gMainFuncs[gMain.mainState]();
        MainLoopIter();
    }
}

void Main_09BC(void)
{
    switch (gMain.subState)
    {
    case 0:
        sub_0CBC();
        sub_024C();
        gMain.subState++;
        break;
    case 1:
        if (JOY_NEW(KEYS_MASK))
            gMain.subState = 2;
        break;
    default:
        sub_02B4();
        sub_0D10();
        SetMainGameState(STATE_TITLE);
        break;
    }
}

void VBlankIntr(void)
{
    m4aSoundVSync();
    INTR_CHECK |= INTR_FLAG_VBLANK;
}

void VCountIntr(void)
{
    INTR_CHECK |= INTR_FLAG_VCOUNT;
    while (!(REG_DISPSTAT & DISPSTAT_HBLANK));
    if (gMain.mainState == STATE_GAME_MAIN)
    {
        REG_BG0HOFS = 0;
        if (gMain.unk28)
        {
            if (gMain.vCount == 72)
            {
                REG_BG0VOFS = gMain.unk2A * 4 + 88;
                gMain.vCount = 144;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
            else
            {
                REG_BG0VOFS = 352;
                gMain.vCount = 72;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
        }
        else if (gMain.unk2C)
        {
            if (gMain.vCount == 40)
            {
                gMain.blendControl = BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3
                            | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG0;
                gMain.blendAlpha = 0xA06;
                REG_BLDCNT = gMain.blendControl;
                REG_BLDALPHA = gMain.blendAlpha;
                gMain.vCount = 144;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
            else
            {
                gMain.blendControl = BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3
                            | BLDCNT_EFFECT_NONE | BLDCNT_TGT1_BG0;
                gMain.blendAlpha = 0;
                REG_BLDCNT = gMain.blendControl;
                REG_BLDALPHA = gMain.blendAlpha;
                REG_BG0VOFS = 352;
                gMain.vCount = 40;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
        }
        else
        {
            REG_BG0VOFS = 352;
        }
    }
}

void SerialIntr(void)
{
    SerialCB();
}

void Timer3Intr(void)
{
    Timer3Init();
}

void IntrDummy(void)
{
}

static void InitGame(void)
{
    REG_WAITCNT = WAITCNT_AGB
                | WAITCNT_PREFETCH_ENABLE
                | WAITCNT_PHI_OUT_NONE
                | WAITCNT_WS2_S_1
                | WAITCNT_WS2_N_3
                | WAITCNT_WS1_S_1
                | WAITCNT_WS1_N_3
                | WAITCNT_WS0_S_1
                | WAITCNT_WS0_N_3
                | WAITCNT_SRAM_2;
    REG_IE = INTR_FLAG_GAMEPAK;
    REG_IME = INTR_FLAG_VBLANK;
    sub_0B8C();
    m4aSoundInit();
    m4aSoundVSyncOff();
    SaveFile_LoadGameData();
}

static void sub_0B8C(void)
{
    gMain.mainState = STATE_INTRO;
    gMain.subState = 0;
    gMain.unk16 = 0;
    gMain.heldKeys = 0;
    gMain.newKeys = 0;
    gMain.unk20 = 0;
    gMain.rngValue = 0;
    gMain.systemFrameCount = 0;
    gMain.unk30 = 0;
    gMain.vCount = 144;
    gMain.unk2C = 0;
    ClearSomeArray();
    ResetSomeGraphicsRelatedStuff();
}

static void InitIntrHandlers(void)
{
    int i;

    for (i = 0; i < INTR_COUNT; i++)
        gIntrTable[i] = gIntrTableTemplate[i];

    gVBlankIntrFuncPtr = &gIntrTable[2];
    gVCountIntrFuncPtr = &gIntrTable[4];
    ResetMainCallback();
    ResetVBlankIntrFunc();
    ResetVCountIntrFunc();
}

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.
u32 Random(void)
{
    gMain.rngValue = 1103515245 * gMain.rngValue + 12345;
    return gMain.rngValue & 0xFFFF;
}

s16 Sin(u16 arg0)
{
    u16 index = arg0 / 4;
    s16 var0 = 1;
    if (index > 0x1FFF)
    {
        index -= 0x2000;
        var0 = -1;
    }

    if (index > 0xFFF)
        index = 0x2000 - index;

    return gSineTable[index] * var0;
}

s16 Cos(u16 arg0)
{
    return Sin(arg0 + 0x4000);
}

static void ReadKeys(void)
{
    u16 keyInput = ~REG_KEYINPUT;
    gMain.newKeys = keyInput & (keyInput ^ gMain.heldKeys);
    gMain.releasedKeys = JOY_HELD(keyInput ^ gMain.heldKeys);
    gMain.heldKeys = keyInput;
}

void sub_0CBC(void)
{
    if (!(REG_IE & INTR_FLAG_VBLANK))
    {
        REG_IF |= INTR_FLAG_VCOUNT | INTR_FLAG_VBLANK;
        REG_IE &= INTR_FLAG_VBLANK
                | INTR_FLAG_HBLANK
                | INTR_FLAG_VCOUNT
                | INTR_FLAG_TIMER0
                | INTR_FLAG_TIMER1
                | INTR_FLAG_TIMER2
                | INTR_FLAG_TIMER3
                | INTR_FLAG_SERIAL
                | INTR_FLAG_DMA0
                | INTR_FLAG_DMA1
                | INTR_FLAG_DMA2
                | INTR_FLAG_DMA3
                | INTR_FLAG_KEYPAD
                | INTR_FLAG_GAMEPAK;
        REG_IME = INTR_FLAG_VBLANK;
        REG_IE |= INTR_FLAG_VCOUNT | INTR_FLAG_VBLANK;
        REG_DISPSTAT |= DISPSTAT_VBLANK_INTR;
        m4aSoundVSyncOn();
    }
}

void sub_0D10(void)
{
    REG_DISPSTAT &= ~DISPSTAT_VBLANK_INTR;
    REG_DISPSTAT &= ~DISPSTAT_VCOUNT_INTR;
    REG_IE &= INTR_FLAG_VBLANK
            | INTR_FLAG_HBLANK
            | INTR_FLAG_VCOUNT
            | INTR_FLAG_TIMER0
            | INTR_FLAG_TIMER1
            | INTR_FLAG_TIMER2
            | INTR_FLAG_TIMER3
            | INTR_FLAG_SERIAL
            | INTR_FLAG_DMA0
            | INTR_FLAG_DMA1
            | INTR_FLAG_DMA2
            | INTR_FLAG_DMA3
            | INTR_FLAG_KEYPAD
            | INTR_FLAG_GAMEPAK;
    REG_IE &= INTR_FLAG_HBLANK
            | INTR_FLAG_VCOUNT
            | INTR_FLAG_TIMER0
            | INTR_FLAG_TIMER1
            | INTR_FLAG_TIMER2
            | INTR_FLAG_TIMER3
            | INTR_FLAG_SERIAL
            | INTR_FLAG_DMA0
            | INTR_FLAG_DMA1
            | INTR_FLAG_DMA2
            | INTR_FLAG_DMA3
            | INTR_FLAG_KEYPAD
            | INTR_FLAG_GAMEPAK;
    if (!REG_IE)
        REG_IME = 0;

    REG_IF |= INTR_FLAG_VBLANK;
    m4aSoundVSyncOff();
}

void MainLoopIter(void)
{
    gMainCallback = gUnknown_02017BD4;
    *gVBlankIntrFuncPtr = gUnknown_02017BD0;
    *gVCountIntrFuncPtr = gUnknown_0200FBA0;
    if (gMainCallback)
        gMainCallback();

    gMain.systemFrameCount++;
}

void DefaultMainCallback(void)
{
    if (REG_DISPSTAT & DISPSTAT_VBLANK_INTR)
    {
        VBlankIntrWait();
        DmaCopy32(3, gOamBuffer, (void *)OAM, OAM_SIZE);
        REG_DISPCNT = gMain.unk16;
        REG_BG0HOFS = gMain.bgOffsets[0].xOffset;
        REG_BG0VOFS = gMain.bgOffsets[0].yOffset;
        REG_BG1HOFS = gMain.bgOffsets[1].xOffset;
        REG_BG1VOFS = gMain.bgOffsets[1].yOffset;
        REG_BG2HOFS = gMain.bgOffsets[2].xOffset;
        REG_BG2VOFS = gMain.bgOffsets[2].yOffset;
        REG_BG3HOFS = gMain.bgOffsets[3].xOffset;
        REG_BG3VOFS = gMain.bgOffsets[3].yOffset;
        if (gMain.unk36)
        {
            REG_BLDCNT = gMain.blendControl;
            REG_BLDALPHA = gMain.blendAlpha;
            REG_BLDY = gMain.blendBrightness;
        }

        REG_DISPSTAT &= 0xFF;
        REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
        m4aSoundMain();
    }
}
