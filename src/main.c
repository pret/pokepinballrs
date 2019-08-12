#include "global.h"
#include "main.h"
#include "gbplayer.h"
#include "m4a.h"

static void InitGame(void);
static void sub_B8C(void);
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

void sub_9BC_Main(void)
{
    switch (gMain.subState)
    {
    case 0:
        sub_CBC();
        sub_24C();
        gMain.subState++;
        break;
    case 1:
        if (gMain.newKeys & KEYS_MASK)
            gMain.subState = 2;
        break;
    default:
        sub_2B4();
        sub_D10();
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
    sub_1F5C();
}

void Timer3Intr(void)
{
    sub_1F4C();
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
    sub_B8C();
    m4aSoundInit();
    m4aSoundVSyncOff();
    SaveFile_LoadGameData();
}

static void sub_B8C(void)
{
    gMain.mainState = STATE_INTRO;
    gMain.subState = 0;
    gMain.unk16 = 0;
    gMain.heldKeys = 0;
    gMain.newKeys = 0;
    gMain.unk20 = 0;
    gMain.rngValue = 0;
    gMain.frameCount = 0;
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

#ifdef NONMATCHING
s16 sub_C24(u16 arg0)
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
    
    return gUnknown_08055C44[index] * var0;
}
#else
NAKED
s16 sub_C24(u16 arg0)
{
    asm_unified("\n\
    lsls r0, r0, #0x10\n\
    lsrs r2, r0, #0x12\n\
    movs r3, #1\n\
    ldr r0, _08000C60 @ =0x00001FFF\n\
    cmp r2, r0\n\
    bls _08000C3A\n\
    ldr r1, _08000C64 @ =0xFFFFE000\n\
    adds r0, r2, r1\n\
    lsls r0, r0, #0x10\n\
    lsrs r2, r0, #0x10\n\
    ldr r3, _08000C68 @ =0x0000FFFF\n\
_08000C3A:\n\
    ldr r0, _08000C6C @ =0x00000FFF\n\
    cmp r2, r0\n\
    bls _08000C4C\n\
    movs r1, #0x80\n\
    lsls r1, r1, #6\n\
    adds r0, r1, #0\n\
    subs r0, r0, r2\n\
    lsls r0, r0, #0x10\n\
    lsrs r2, r0, #0x10\n\
_08000C4C:\n\
    ldr r1, _08000C70 @ =0x08055C44\n\
    lsls r0, r2, #1\n\
    adds r0, r0, r1\n\
    ldrh r1, [r0]\n\
    lsls r0, r3, #0x10\n\
    asrs r0, r0, #0x10\n\
    muls r0, r1, r0\n\
    lsls r0, r0, #0x10\n\
    asrs r0, r0, #0x10\n\
    bx lr\n\
    .align 2, 0\n\
_08000C60: .4byte 0x00001FFF\n\
_08000C64: .4byte 0xFFFFE000\n\
_08000C68: .4byte 0x0000FFFF\n\
_08000C6C: .4byte 0x00000FFF\n\
_08000C70: .4byte 0x08055C44");
}
#endif // NONMATCHING

s16 sub_C74(u16 arg0)
{   
    return sub_C24(arg0 + 0x4000);
}

static void ReadKeys(void)
{
    u16 keyInput = ~REG_KEYINPUT;
    gMain.newKeys = keyInput & (keyInput ^ gMain.heldKeys);
    gMain.releasedKeys = gMain.heldKeys & (keyInput ^ gMain.heldKeys);
    gMain.heldKeys = keyInput;
}

void sub_CBC(void)
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

void sub_D10(void)
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

    gMain.frameCount++;
}

void DefaultMainCallback(void)
{
    if (REG_DISPSTAT & DISPSTAT_VBLANK_INTR)
    {
        VBlankIntrWait();
        DmaCopy32(3, gOamBuffer, (void *)OAM, OAM_SIZE);
        REG_DISPCNT = gMain.unk16;
        REG_BG0HOFS = gMain.unk2E8[0].unk0;
        REG_BG0VOFS = gMain.unk2E8[0].unk2;
        REG_BG1HOFS = gMain.unk2E8[1].unk0;
        REG_BG1VOFS = gMain.unk2E8[1].unk2;
        REG_BG2HOFS = gMain.unk2E8[2].unk0;
        REG_BG2VOFS = gMain.unk2E8[2].unk2;
        REG_BG3HOFS = gMain.unk2E8[3].unk0;
        REG_BG3VOFS = gMain.unk2E8[3].unk2;
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
