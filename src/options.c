#include "global.h"
#include "m4a.h"
#include "main.h"

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

extern struct OptionsData gUnknown_02002920;

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
    sub_438();

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

extern u8 gUnknown_02031AF0[][10];
extern u8 gUnknown_08527ED6[][10];

void sub_513B8(void)
{
    int i;
    int j;

    gUnknown_02002920.unk0 = 0;
    gUnknown_02002920.unk2 = 0;
    gUnknown_02002920.unk4 = 0;
    gUnknown_02002920.unk6 = 1;
    gUnknown_02002920.unk8 = 0;
    gUnknown_02002920.unkA = 0;
    gUnknown_02002920.unkC = gUnknown_0200B134.unk143;
    gUnknown_02002920.unkE = 0;
    gUnknown_02002920.unk10 = 0;
    gUnknown_02002920.unk12 = 0;
    gUnknown_02002920.unk13 = 0;
    gUnknown_02002920.unk14 = 1;
    gUnknown_02002920.unk15 = 0;
    gUnknown_02002920.unk16 = 0;
    gUnknown_02002920.unk17 = 1;
    gUnknown_02002920.unk18 = 0;
    for (i = 0; i < 6; i++)
        gUnknown_02002920.unk1A[i] = 0;
    gUnknown_02002920.unk20 = 0;
    gUnknown_02002920.unk22 = 0;
    for (i = 0; i < 2; i++)
        gUnknown_02002920.unk24[i] = 10;
    gUnknown_02002920.unk28 = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10; j++)
            gUnknown_02031AF0[i][j] = gUnknown_08527ED6[i][j];
    }
    sub_52528();
    if (gGameBoyPlayerEnabled == 1)
    {
        gUnknown_02002920.unk2A = gUnknown_0200B134.unk141;
        gUnknown_0200B134.unk141 = 1;
    }
    else
    {
        gUnknown_02002920.unk2A = 0;
        gUnknown_0200B134.unk141 = 0;
    }
    gUnknown_02002920.unk2E = 0;
    gUnknown_02002920.unk2B = 0;
    gUnknown_02002920.unk2C = 0;
    gUnknown_02002920.unk2D = 0;
    gUnknown_02002920.unk2F = 0;
    gUnknown_02002920.unk30 = 0;
}

extern u16 gUnknown_08527D22[];
extern u16 gUnknown_086BB910[][4];
extern struct {u8 unk0; s16 unk2;} gUnknown_086BB9B4[];
extern u16 gUnknown_08527D66[];

void sub_514B8(void)
{
    s16 r4;

    sub_51C9C();
    switch (gUnknown_02002920.unk0)
    {
    case 0:
        if (gMain.newKeys & 0x40)
        {
            if (gUnknown_02002920.unkA != 0xD)
            {
                if (gUnknown_02002920.unkA == 0xE)
                {
                    m4aSongNumStart(0x67);
                    gUnknown_02002920.unkA = 0xD;
                }
                else if (gUnknown_02002920.unkA > 0)
                {
                    m4aSongNumStart(0x67);
                    gUnknown_02002920.unkA--;
                }
            }
        }
        //_0805152C
        else if (gMain.newKeys & 0x80)
        {
            if (gUnknown_02002920.unkA < 6)
            {
                m4aSongNumStart(0x67);
                gUnknown_02002920.unkA++;
            }
            else if (gUnknown_02002920.unkA == 0xD)
            {
                m4aSongNumStart(0x67);
                gUnknown_02002920.unkA = 0xE;
            }
            //_0805155E
            else if (gUnknown_02002920.unkA == 0xE)
            {
                m4aSongNumStart(0x67);
                gUnknown_02002920.unkA = 2;
            }
            // _0805156A 
        }
        //_0805156C
        if ((gMain.newKeys & 0x10) && gGameBoyPlayerEnabled == 1 && (u16)gUnknown_02002920.unkA < 2)
        {
            m4aSongNumStart(0x67);
            gUnknown_02002920.unkA += 0xD;
        }
        if ((gMain.newKeys & 0x20) && gGameBoyPlayerEnabled == 1 && (u16)(gUnknown_02002920.unkA - 13) < 2)
        {
            m4aSongNumStart(0x67);
            gUnknown_02002920.unkA -= 0xD;
        }
        //_080515C2
        if (gMain.newKeys & 1)
        {
            switch (gUnknown_02002920.unkA)
            {
            case 0:
                m4aSongNumStart(0x65);
                gUnknown_02002920.unk0 = 1;
                gUnknown_02002920.unk18 = 0;
                gUnknown_02002920.unk30 = 1;
                if (gUnknown_02002920.unk2E == 1)
                {
                    gUnknown_02002920.unk2B = 0;
                    gUnknown_02002920.unk2D = 0;
                    gUnknown_02002920.unk2C = 0;
                    gUnknown_02002920.unk2E = 0;
                }
                break;
            case 1:
                m4aSongNumStart(0x65);
                gUnknown_02002920.unk0 = 2;
                gUnknown_02002920.unk18 = 0;
                gUnknown_02002920.unk30 = 1;
                if (gUnknown_02002920.unk2E == 1)
                {
                    gUnknown_02002920.unk2B = 0;
                    gUnknown_02002920.unk2D = 0;
                    gUnknown_02002920.unk2C = 0;
                    gUnknown_02002920.unk2E = 0;
                }
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                m4aSongNumStart(0x65);
                gUnknown_02002920.unkC = gUnknown_02002920.unkA - 2;
                gUnknown_0200B134.unk143 = gUnknown_02002920.unkC; 
                break;
            case 6:
                m4aSongNumStart(0x65);
                gUnknown_02002920.unkC = gUnknown_02002920.unkA - 2;
                gUnknown_0200B134.unk143 = gUnknown_02002920.unkC; 
                gUnknown_02002920.unkA = 7;
                gUnknown_02002920.unk0 = 3;
                break;
            case 14:
                if (gGameBoyPlayerEnabled == 1)
                {
                    m4aSongNumStart(0x65);
                    gUnknown_02002920.unk2D = 0;
                    if (gUnknown_02002920.unk2E == 1)
                        gUnknown_02002920.unk2E = 0;
                    gUnknown_02002920.unk2B = 0; 
                    gUnknown_02002920.unk2C = 0; 
                    gUnknown_02002920.unk2A = 0; 
                }
                break;
            case 13:
                if (gGameBoyPlayerEnabled == 1)
                {
                    m4aSongNumStart(0x65);
                    sub_11B0(11);
                    if (gUnknown_02002920.unk2E == 0)
                        gUnknown_02002920.unk2E = 1;

                    gUnknown_02002920.unk2B = 0; 
                    gUnknown_02002920.unk2C = 0; 
                    gUnknown_02002920.unk2A = 1; 
                }
                break;
            }
        }
        //_0805177C
        else if (gMain.newKeys & 2)
        {
            m4aSongNumStart(0x66);
            gMain.subState++;
            sub_525CC(gMain.saveData.unk143);

        }
        if (!(gMain.unk4C & 7))
            gUnknown_02002920.unk2 = 1 - gUnknown_02002920.unk2;
        break;
    case 1:  // _080517A8
        if (gMain.heldKeys & 0x20)
        {
            if (gUnknown_02002920.unk18 == 0)
            {
                gUnknown_02002920.unkE--;
                gUnknown_02002920.unk18 = 10;
            }
        }
        else if (gMain.heldKeys & 0x10)
        {
            if (gUnknown_02002920.unk18 == 0)
            {
                gUnknown_02002920.unkE++;
                gUnknown_02002920.unk18 = 10;
            }
        }
        if (gMain.newKeys & 0x40)
            gUnknown_02002920.unkE += 10;
        else if (gMain.newKeys & 0x80)
            gUnknown_02002920.unkE -= 10;
        if (gUnknown_02002920.unkE < 0)
            gUnknown_02002920.unkE = 33;
        if (gUnknown_02002920.unkE > 33)
            gUnknown_02002920.unkE = 0;

        r4 = gUnknown_02002920.unkE + 1;
        gUnknown_02002920.unk12 = r4 / 100;
        r4 %= 100;
        gUnknown_02002920.unk13 = r4 / 10;
        gUnknown_02002920.unk14 = r4 % 10;
        if (gMain.newKeys & 1)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(gUnknown_08527D22[gUnknown_02002920.unkE]);
        }
        else if (gMain.newKeys & 2)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(0x66);
            gUnknown_02002920.unk4 = 0;
            gUnknown_02002920.unk30 = 0;
            gUnknown_02002920.unk0 = 0;
        }
        //_080518AA
        if (!(gMain.unk4C & 7))
            gUnknown_02002920.unk4 = 1 - gUnknown_02002920.unk4;
        if (gUnknown_02002920.unk18 > 0)
            gUnknown_02002920.unk18--;
        break;
    case 2:
        if (gMain.heldKeys & 0x20)
        {
            if (gUnknown_02002920.unk18 == 0)
            {
                gUnknown_02002920.unk10--;
                gUnknown_02002920.unk18 = 10;
            }
        }
        else if (gMain.heldKeys & 0x10)
        {
            if (gUnknown_02002920.unk18 == 0)
            {
                gUnknown_02002920.unk10++;
                gUnknown_02002920.unk18 = 10;
            }
        }
        //_08051918
        if (gMain.newKeys & 0x40)
            gUnknown_02002920.unk10 += 10;
        else if (gMain.newKeys & 0x80)
            gUnknown_02002920.unk10 -= 10;
        if (gUnknown_02002920.unk10 < 0)
            gUnknown_02002920.unk10 = 0xB7;
        if (gUnknown_02002920.unk10 > 0xB7)
            gUnknown_02002920.unk10 = 0;

        r4 = gUnknown_02002920.unk10 + 1;
        gUnknown_02002920.unk15 = r4 / 100;
        r4 %= 100;
        gUnknown_02002920.unk16 = r4 / 10;
        gUnknown_02002920.unk17 = r4 % 10;
        if (gMain.newKeys & 0x1)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(gUnknown_08527D66[gUnknown_02002920.unk10]);
        }
        else if (gMain.newKeys & 0x2)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(0x66);
            gUnknown_02002920.unk4 = 0;
            gUnknown_02002920.unk30 = 0;
            gUnknown_02002920.unk0 = 0;
        }
        if (!(gMain.unk4C & 7))
            gUnknown_02002920.unk4 = 1 - gUnknown_02002920.unk4;
        if (gUnknown_02002920.unk18 > 0)
            gUnknown_02002920.unk18--;
        break;
    case 3:  //_08051A08
        if (gMain.newKeys & 0x40)
        {
            if (gUnknown_02002920.unkA > 7)
            {
                m4aSongNumStart(0x67);
                gUnknown_02002920.unkA--;
            }
        }
        //_08051A34
        else if (gMain.newKeys & 0x80)
        {
            if (gUnknown_02002920.unkA <= 10)
            {
                m4aSongNumStart(0x67);
                gUnknown_02002920.unkA++;
            }
        }
        //_08051A52
        if (gMain.newKeys & 1)
        {
            m4aSongNumStart(0x65);
            gUnknown_02002920.unk0 = 4;
            gUnknown_02002920.unk1A[gUnknown_02002920.unkA - 7] = 1;
        }
        //_08051A80
        else if (gMain.newKeys & 2)
        {
            m4aSongNumStart(0x66);
            gUnknown_02002920.unkA = 6;
            gUnknown_02002920.unk0 = 0;
        }
        //_08051A96 
        if (!(gMain.unk4C & 7))
            gUnknown_02002920.unk2 = 1 - gUnknown_02002920.unk2;
        break;
    case 4:
        gUnknown_02002920.unk8++;
        if (gUnknown_02002920.unk8 > 24)
        {
            gUnknown_02002920.unk8 = 0;
            gUnknown_02002920.unk6 = 1 - gUnknown_02002920.unk6;
        }
        if (gMain.newKeys & 0x3F7)
        {
            s16 i;

            m4aSongNumStart(0x65);
            gUnknown_02002920.unk20 = 10;
            gUnknown_02002920.unk22 = 0;
            for (i = 0; i < 2; i++)
                gUnknown_02002920.unk24[i] = 10;
            gUnknown_02002920.unk28 = 0;
        }
        //_08051B0E
        if (gUnknown_02002920.unk20 > 0)
        {
            sub_524BC();
            gUnknown_02002920.unk20--;
            if (gUnknown_02002920.unk20 == 0)
            {
                gUnknown_02031AF0[4][(gUnknown_02002920.unkA - 7) * 2 + 0] = gUnknown_02002920.unk24[0];
                gUnknown_02031AF0[4][(gUnknown_02002920.unkA - 7) * 2 + 1] = gUnknown_02002920.unk24[1];
                gUnknown_0200B134.unk144[(gUnknown_02002920.unkA - 7)][0] = gUnknown_086BB910[gUnknown_02002920.unk24[0]][0];
                gUnknown_0200B134.unk144[(gUnknown_02002920.unkA - 7)][1] = gUnknown_086BB910[gUnknown_02002920.unk24[1]][0];
                gUnknown_02002920.unk0 = 3;
                gUnknown_02002920.unk1A[gUnknown_02002920.unkA - 7] = 0;
                gUnknown_02002920.unk8 = 0;
                gUnknown_02002920.unk6 = 1;
            }
        }
        break;
    }
    //_08051B98
    if (gUnknown_02002920.unk2E == 1)
    {
        //gUnknown_02002920.unk2B++;
        if (++gUnknown_02002920.unk2B > gUnknown_086BB9B4[gUnknown_02002920.unk2C].unk2)
        {
            gUnknown_02002920.unk2B = 0;
            gUnknown_02002920.unk2C++;
            if (gUnknown_02002920.unk2C > 12)
            {
                gUnknown_02002920.unk2C = 0;
                gUnknown_02002920.unk2D = 0;
                gUnknown_02002920.unk2E = 0;
            }
            //_08051BE8
            gUnknown_02002920.unk2D = gUnknown_086BB9B4[gUnknown_02002920.unk2C].unk0;
        }
        // _08051C30
    }
    else
    //_08051C10
    {
        gUnknown_02002920.unk2B++;
        if (gUnknown_02002920.unk2B > 18)
        {
            gUnknown_02002920.unk2B = 0;
            gUnknown_02002920.unk2D = 1 - gUnknown_02002920.unk2D;
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
