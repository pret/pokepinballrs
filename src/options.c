#include "global.h"
#include "m4a.h"
#include "main.h"
#include "titlescreen.h"

struct OptionsData
{
    s16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s16 unk8;
    s16 unkA;
    u16 unkC;
    s16 unkE;
    s16 unk10;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    s16 unk18;
    u8 unk1A[6];
    s16 unk20;
    u16 unk22;
    s16 unk24[2];
    u16 unk28;
    u8 unk2A;
    s8 unk2B;
    s8 unk2C;
    u8 unk2D;
    s8 unk2E;
    u8 unk2F;
    u8 unk30;
};

extern struct OptionsData gOptionsData;

void OptionsMain(void)
{
    gUnknown_08527F08[gMain.subState]();
}

extern const u16 gUnknown_0852B468[];
extern const u8 gUnknown_08528828[];
extern const u8 gUnknown_0852A848[];
extern const u8 gUnknown_08528028[];
extern const u8 gUnknown_0852A048[];

void sub_51240(void)
{
    ResetSomeGraphicsRelatedStuff();

    REG_DISPCNT = 0x1080;
    REG_BG0CNT = 4;
    REG_DISPCNT |= 0x100;
    REG_BG1CNT = 0x109;
    REG_DISPCNT |= 0x200;

    gMain.unk16 = REG_DISPCNT;

    DmaCopy16(3, gUnknown_0852B468, (void *)PLTT, 0x200);
    DmaCopy16(3, gUnknown_08528828, (void *)(VRAM + 0x4000), 0x1800);
    DmaCopy16(3, gUnknown_0852A848, (void *)(VRAM + 0x8000), 0xC00);
    DmaCopy16(3, gUnknown_08528028, gUnknown_03005C00, 0x800);
    DmaCopy16(3, gUnknown_03005C00, (void *)VRAM, 0x800);

    if (gGameBoyPlayerEnabled != 1)
    {
         sub_1068C(0x12, 4, 2, 1, 2);
         sub_1068C(0x12, 5, 3, 2, 2);
    }

    DmaCopy16(3, gUnknown_03005C00, (void *)VRAM, 0x800);
    DmaCopy16(3, gUnknown_0852A048, (void *)(VRAM + 0x800), 0x800);
    DmaCopy16(3, gGBAButtonIcons_Pals, (void *)(PLTT + 0x200), 0x60);
    DmaCopy16(3, gOptionsSprites_Gfx, (void *)(VRAM + 0x10000), 0x2020);
	sub_513B8();
	sub_51C9C();
	m4aMPlayAllStop();
	sub_CBC();
	sub_24C();
	sub_10C0();

    gMain.subState++;
}

void sub_513B8(void)
{
    int i;
    int j;

    gOptionsData.unk0 = 0;
    gOptionsData.unk2 = 0;
    gOptionsData.unk4 = 0;
    gOptionsData.unk6 = 1;
    gOptionsData.unk8 = 0;
    gOptionsData.unkA = 0;
    gOptionsData.unkC = gMain_saveData.unk143;
    gOptionsData.unkE = 0;
    gOptionsData.unk10 = 0;
    gOptionsData.unk12 = 0;
    gOptionsData.unk13 = 0;
    gOptionsData.unk14 = 1;
    gOptionsData.unk15 = 0;
    gOptionsData.unk16 = 0;
    gOptionsData.unk17 = 1;
    gOptionsData.unk18 = 0;
    for (i = 0; i < 6; i++)
        gOptionsData.unk1A[i] = 0;
    gOptionsData.unk20 = 0;
    gOptionsData.unk22 = 0;
    for (i = 0; i < 2; i++)
        gOptionsData.unk24[i] = 10;
    gOptionsData.unk28 = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10; j++)
            gUnknown_02031AF0[i][j] = gUnknown_08527ED6[i][j];
    }
    sub_52528();
    if (gGameBoyPlayerEnabled == 1)
    {
        gOptionsData.unk2A = gMain_saveData.unk141;
        gMain_saveData.unk141 = 1;
    }
    else
    {
        gOptionsData.unk2A = 0;
        gMain_saveData.unk141 = 0;
    }
    gOptionsData.unk2E = 0;
    gOptionsData.unk2B = 0;
    gOptionsData.unk2C = 0;
    gOptionsData.unk2D = 0;
    gOptionsData.unk2F = 0;
    gOptionsData.unk30 = 0;
}

void sub_514B8(void)
{
    s16 r4;

    sub_51C9C();
    switch (gOptionsData.unk0)
    {
    case 0:
        if (gMain.newKeys & 0x40)
        {
            if (gOptionsData.unkA != 0xD)
            {
                if (gOptionsData.unkA == 0xE)
                {
                    m4aSongNumStart(0x67);
                    gOptionsData.unkA = 0xD;
                }
                else if (gOptionsData.unkA > 0)
                {
                    m4aSongNumStart(0x67);
                    gOptionsData.unkA--;
                }
            }
        }
        else if (gMain.newKeys & 0x80)
        {
            if (gOptionsData.unkA < 6)
            {
                m4aSongNumStart(0x67);
                gOptionsData.unkA++;
            }
            else if (gOptionsData.unkA == 0xD)
            {
                m4aSongNumStart(0x67);
                gOptionsData.unkA = 0xE;
            }
            else if (gOptionsData.unkA == 0xE)
            {
                m4aSongNumStart(0x67);
                gOptionsData.unkA = 2;
            }
        }
        if ((gMain.newKeys & 0x10) && gGameBoyPlayerEnabled == 1 && (u16)gOptionsData.unkA < 2)
        {
            m4aSongNumStart(0x67);
            gOptionsData.unkA += 0xD;
        }
        if ((gMain.newKeys & 0x20) && gGameBoyPlayerEnabled == 1 && (u16)(gOptionsData.unkA - 13) < 2)
        {
            m4aSongNumStart(0x67);
            gOptionsData.unkA -= 0xD;
        }
        if (gMain.newKeys & 1)
        {
            switch (gOptionsData.unkA)
            {
            case 0:
                m4aSongNumStart(0x65);
                gOptionsData.unk0 = 1;
                gOptionsData.unk18 = 0;
                gOptionsData.unk30 = 1;
                if (gOptionsData.unk2E == 1)
                {
                    gOptionsData.unk2B = 0;
                    gOptionsData.unk2D = 0;
                    gOptionsData.unk2C = 0;
                    gOptionsData.unk2E = 0;
                }
                break;
            case 1:
                m4aSongNumStart(0x65);
                gOptionsData.unk0 = 2;
                gOptionsData.unk18 = 0;
                gOptionsData.unk30 = 1;
                if (gOptionsData.unk2E == 1)
                {
                    gOptionsData.unk2B = 0;
                    gOptionsData.unk2D = 0;
                    gOptionsData.unk2C = 0;
                    gOptionsData.unk2E = 0;
                }
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                m4aSongNumStart(0x65);
                gOptionsData.unkC = gOptionsData.unkA - 2;
                gMain_saveData.unk143 = gOptionsData.unkC;
                break;
            case 6:
                m4aSongNumStart(0x65);
                gOptionsData.unkC = gOptionsData.unkA - 2;
                gMain_saveData.unk143 = gOptionsData.unkC;
                gOptionsData.unkA = 7;
                gOptionsData.unk0 = 3;
                break;
            case 14:
                if (gGameBoyPlayerEnabled == 1)
                {
                    m4aSongNumStart(0x65);
                    gOptionsData.unk2D = 0;
                    if (gOptionsData.unk2E == 1)
                        gOptionsData.unk2E = 0;
                    gOptionsData.unk2B = 0;
                    gOptionsData.unk2C = 0;
                    gOptionsData.unk2A = 0;
                }
                break;
            case 13:
                if (gGameBoyPlayerEnabled == 1)
                {
                    m4aSongNumStart(0x65);
                    sub_11B0(11);
                    if (gOptionsData.unk2E == 0)
                        gOptionsData.unk2E = 1;

                    gOptionsData.unk2B = 0;
                    gOptionsData.unk2C = 0;
                    gOptionsData.unk2A = 1;
                }
                break;
            }
        }
        else if (gMain.newKeys & 2)
        {
            m4aSongNumStart(0x66);
            gMain.subState++;
            sub_525CC(gMain_saveData.unk143);

        }
        if (!(gMain.frameCount & 7))
            gOptionsData.unk2 = 1 - gOptionsData.unk2;
        break;
    case 1:
        if (gMain.heldKeys & 0x20)
        {
            if (gOptionsData.unk18 == 0)
            {
                gOptionsData.unkE--;
                gOptionsData.unk18 = 10;
            }
        }
        else if (gMain.heldKeys & 0x10)
        {
            if (gOptionsData.unk18 == 0)
            {
                gOptionsData.unkE++;
                gOptionsData.unk18 = 10;
            }
        }
        if (gMain.newKeys & 0x40)
            gOptionsData.unkE += 10;
        else if (gMain.newKeys & 0x80)
            gOptionsData.unkE -= 10;
        if (gOptionsData.unkE < 0)
            gOptionsData.unkE = 33;
        if (gOptionsData.unkE > 33)
            gOptionsData.unkE = 0;

        r4 = gOptionsData.unkE + 1;
        gOptionsData.unk12 = r4 / 100;
        r4 %= 100;
        gOptionsData.unk13 = r4 / 10;
        gOptionsData.unk14 = r4 % 10;
        if (gMain.newKeys & 1)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(gUnknown_08527D22[gOptionsData.unkE]);
        }
        else if (gMain.newKeys & 2)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(0x66);
            gOptionsData.unk4 = 0;
            gOptionsData.unk30 = 0;
            gOptionsData.unk0 = 0;
        }
        if (!(gMain.frameCount & 7))
            gOptionsData.unk4 = 1 - gOptionsData.unk4;
        if (gOptionsData.unk18 > 0)
            gOptionsData.unk18--;
        break;
    case 2:
        if (gMain.heldKeys & 0x20)
        {
            if (gOptionsData.unk18 == 0)
            {
                gOptionsData.unk10--;
                gOptionsData.unk18 = 10;
            }
        }
        else if (gMain.heldKeys & 0x10)
        {
            if (gOptionsData.unk18 == 0)
            {
                gOptionsData.unk10++;
                gOptionsData.unk18 = 10;
            }
        }
        if (gMain.newKeys & 0x40)
            gOptionsData.unk10 += 10;
        else if (gMain.newKeys & 0x80)
            gOptionsData.unk10 -= 10;
        if (gOptionsData.unk10 < 0)
            gOptionsData.unk10 = 0xB7;
        if (gOptionsData.unk10 > 0xB7)
            gOptionsData.unk10 = 0;

        r4 = gOptionsData.unk10 + 1;
        gOptionsData.unk15 = r4 / 100;
        r4 %= 100;
        gOptionsData.unk16 = r4 / 10;
        gOptionsData.unk17 = r4 % 10;
        if (gMain.newKeys & 0x1)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(gUnknown_08527D66[gOptionsData.unk10]);
        }
        else if (gMain.newKeys & 0x2)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(0x66);
            gOptionsData.unk4 = 0;
            gOptionsData.unk30 = 0;
            gOptionsData.unk0 = 0;
        }
        if (!(gMain.frameCount & 7))
            gOptionsData.unk4 = 1 - gOptionsData.unk4;
        if (gOptionsData.unk18 > 0)
            gOptionsData.unk18--;
        break;
    case 3:
        if (gMain.newKeys & 0x40)
        {
            if (gOptionsData.unkA > 7)
            {
                m4aSongNumStart(0x67);
                gOptionsData.unkA--;
            }
        }
        else if (gMain.newKeys & 0x80)
        {
            if (gOptionsData.unkA <= 10)
            {
                m4aSongNumStart(0x67);
                gOptionsData.unkA++;
            }
        }
        if (gMain.newKeys & 1)
        {
            m4aSongNumStart(0x65);
            gOptionsData.unk0 = 4;
            gOptionsData.unk1A[gOptionsData.unkA - 7] = 1;
        }
        else if (gMain.newKeys & 2)
        {
            m4aSongNumStart(0x66);
            gOptionsData.unkA = 6;
            gOptionsData.unk0 = 0;
        }
        if (!(gMain.frameCount & 7))
            gOptionsData.unk2 = 1 - gOptionsData.unk2;
        break;
    case 4:
        gOptionsData.unk8++;
        if (gOptionsData.unk8 > 24)
        {
            gOptionsData.unk8 = 0;
            gOptionsData.unk6 = 1 - gOptionsData.unk6;
        }
        if (gMain.newKeys & 0x3F7)
        {
            s16 i;

            m4aSongNumStart(0x65);
            gOptionsData.unk20 = 10;
            gOptionsData.unk22 = 0;
            for (i = 0; i < 2; i++)
                gOptionsData.unk24[i] = 10;
            gOptionsData.unk28 = 0;
        }
        //_08051B0E
        if (gOptionsData.unk20 > 0)
        {
            sub_524BC();
            gOptionsData.unk20--;
            if (gOptionsData.unk20 == 0)
            {
                gUnknown_02031AF0[4][(gOptionsData.unkA - 7) * 2 + 0] = gOptionsData.unk24[0];
                gUnknown_02031AF0[4][(gOptionsData.unkA - 7) * 2 + 1] = gOptionsData.unk24[1];
                gMain_saveData.unk144[(gOptionsData.unkA - 7)][0] = gUnknown_086BB910[gOptionsData.unk24[0]][0];
                gMain_saveData.unk144[(gOptionsData.unkA - 7)][1] = gUnknown_086BB910[gOptionsData.unk24[1]][0];
                gOptionsData.unk0 = 3;
                gOptionsData.unk1A[gOptionsData.unkA - 7] = 0;
                gOptionsData.unk8 = 0;
                gOptionsData.unk6 = 1;
            }
        }
        break;
    }
    //_08051B98
    if (gOptionsData.unk2E == 1)
    {
        //gOptionsData.unk2B++;
        if (++gOptionsData.unk2B > gUnknown_086BB9B4[gOptionsData.unk2C].unk2)
        {
            gOptionsData.unk2B = 0;
            gOptionsData.unk2C++;
            if (gOptionsData.unk2C > 12)
            {
                gOptionsData.unk2C = 0;
                gOptionsData.unk2D = 0;
                gOptionsData.unk2E = 0;
            }
            //_08051BE8
            gOptionsData.unk2D = gUnknown_086BB9B4[gOptionsData.unk2C].unk0;
        }
        // _08051C30
    }
    else
    //_08051C10
    {
        gOptionsData.unk2B++;
        if (gOptionsData.unk2B > 18)
        {
            gOptionsData.unk2B = 0;
            gOptionsData.unk2D = 1 - gOptionsData.unk2D;
        }
    }
    sub_11FC();
}

void sub_51C3C(void)
{
    sub_111C();
    if (sub_1170() != 0)
    {
        sub_1198();
        gMain.subState++;
    }
}

void sub_51C60(void)
{
    gMain_saveData.unk141 = gOptionsData.unk2A;
    SaveFile_WriteToSram();
    sub_2B4();
    m4aMPlayAllStop();
    sub_D10();
    gAutoDisplayTitlescreenMenu = 1;
    SetMainGameState(STATE_TITLE);
}

/*
void sub_51C9C(void)
{

}
*/
