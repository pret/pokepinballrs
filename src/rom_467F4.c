#include "global.h"
#include "main.h"

extern const s16 gUnknown_086B0010[][4];

struct Unk_86AFCB0
{
    const s16 *unk0;
    u8 filler4[0xC];
    const u16 *unk10;
    u8 filler14[0xC];
    const u8 *unk20;
    u8 filler24[0xC];
};
extern const struct Unk_86AFCB0 gUnknown_086AFCB0[][2];

extern u8 gUnknown_020030A0[];
extern u8 gUnknown_0200FBB0[];

extern const u16 gUnknown_0816C3E4[];
extern const u8 gUnknown_081C08E4[];
extern const u8 gUnknown_081BFEE4[];
extern const u8 gUnknown_0822E424[];
extern const u8 gUnknown_0824C1E4[];
extern const u8 gUnknown_0824DD60[];
extern const u8 gUnknown_08250934[];
extern const u8 gUnknown_08265C10[];
extern const u8 gUnknown_0826DC10[];
extern const u8 gUnknown_0826EC10[];
extern const u8 gUnknown_0826EE10[];
extern const u8 gUnknown_082AE6D0[];
extern const u8 gUnknown_082D34D0[];
extern const u8 gUnknown_082E4EE0[];
extern const u8 gUnknown_082D523C[];
extern const u8 gUnknown_082D8998[];
extern const u8 gUnknown_082ECEE0[];
extern const u8 gUnknown_082EDEE0[];
extern const u8 gUnknown_082EE4C0[];


extern const u8 gUnknown_08301700[];
extern const u8 gUnknown_08301F00[];
extern const u8 gUnknown_08302700[];
extern const u8 gUnknown_08303928[];
extern const u8 gUnknown_0830CBD4[];
extern const u8 gUnknown_0830CDD4[];
extern const u16 gUnknown_08327994[];
extern const u8 gUnknown_08329994[];
extern const u8 gUnknown_0832A194[];
extern const u8 gUnknown_08332E04[];
extern const u16 gUnknown_08333004[];
extern const u8 gUnknown_0833D844[];
extern const u8 gUnknown_0833E044[];
extern const u8 gUnknown_08352BD8[];
extern const u8 gUnknown_08352DD8[];
extern const u8 gUnknown_083535D8[];
extern const u8 gUnknown_08353DD8[];
extern const u8 gUnknown_08363EC8[];
extern const u8 gUnknown_083640C8[];
extern const u8 gUnknown_0836E808[];
extern const u8 gUnknown_0836F808[];
extern const u8 gUnknown_08370808[];
extern const u8 gUnknown_0837A2E8[];
extern const u16 gUnknown_0837A4E8[];
extern const u8 gUnknown_0838E028[];
extern const u8 gUnknown_0838E828[];
extern const u8 gUnknown_083A826C[];
extern const u8 gUnknown_083A8ACC[];

extern const u8 gRubyIntroSprites_Gfx[];
extern const u8 gSapphireIntroSprites_Gfx[];
extern const u8 gDusclopsIntroSprite_Gfx[];
extern const u8 gKecleonIntroSprite_Gfx[];
extern const u8 gKyogreIntroSprite_Gfx[];
extern const u8 gGroudonIntroSprite_Gfx[];
extern const u8 gRayquazaIntroSprite_Gfx[];
extern const u8 gUnknown_084779EC[];

extern const struct Unk02031520_unk14 gUnknown_086AFD70[];

void loadIntroduction(void)
{
    struct Unk02031520 *dest = &gUnknown_02031520;
    const struct Unk02031520_unk14 *src = gUnknown_086AFD70;
    memcpy(&dest->unk14, &src[gMain.selectedField], sizeof(dest->unk14));

    switch (gMain.selectedField)
    {
	case FIELD_RUBY:
        DmaCopy16(3, gUnknown_081BFEE4, (void *)BG_PLTT, BG_PLTT_SIZE);
        DmaCopy16(3, gUnknown_08265C10, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_0826DC10, (void *)0x06003000, 0x1000);
        LZ77UnCompWram(gUnknown_0824C1E4, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0824DD60, gUnknown_0200FBB0);
        LZ77UnCompWram(gUnknown_08250934, gUnknown_020030A0);
        DmaCopy16(3, &gUnknown_0200FBB0[0xC00], (void *)0x0600B400, 0x2400);
        DmaCopy16(3, &gUnknown_0200FBB0[0x3000], (void *)0x06008000, 0x3400);
        DmaCopy16(3, gUnknown_081C08E4, (void *)BG_VRAM, 0x1000);
        DmaCopy16(3, gUnknown_0822E424, (void *)0x06001000, 0x1000);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gRubyIntroSprites_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_SAPPHIRE:
        DmaCopy16(3, gUnknown_0826EC10, (void *)BG_PLTT, BG_PLTT_SIZE);
        DmaCopy16(3, gUnknown_082E4EE0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_082ECEE0, (void *)0x06003000, 0x1000);
        LZ77UnCompWram(gUnknown_082D34D0, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_082D523C, gUnknown_0200FBB0);
        LZ77UnCompWram(gUnknown_082D8998, gUnknown_020030A0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x0600A800, 0x3000);
        DmaCopy16(3, &gUnknown_0200FBB0[0x3000], (void *)0x06008000, 0x2800);
        DmaCopy16(3, gUnknown_0826EE10, (void *)BG_VRAM, 0x1000);
        DmaCopy16(3, gUnknown_082AE6D0, (void *)0x06001000, 0x1000);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gSapphireIntroSprites_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_DUSCLOPS:
        DmaCopy16(3, gUnknown_082EDEE0, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_08303928, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_082EE4C0, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_08301700, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_08301F00, (void *)0x06001000, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gDusclopsIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_KECLEON:
        DmaCopy16(3, gUnknown_0830CBD4, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0832A194, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_08329994, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_0830CDD4, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_08327994, (void *)0x06001000, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gKecleonIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_KYOGRE:
        DmaCopy16(3, gUnknown_08332E04, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0833E044, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_08333004, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_0833D844, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gKyogreIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_GROUDON:
        DmaCopy16(3, gUnknown_08352BD8, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_08353DD8, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_08352DD8, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_083535D8, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gGroudonIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_RAYQUAZA:
        DmaCopy16(3, gUnknown_08363EC8, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_08370808, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_083640C8, (void *)0x06000000, 0x1000);
        DmaCopy16(3, gUnknown_0836F808, (void *)0x06001000, 0x1000);
        DmaCopy16(3, gUnknown_0836E808, (void *)0x06003000, 0x1000);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gRayquazaIntroSprite_Gfx, (void *)0x06010000, 0x8000);
        break;
	case FIELD_SPHEAL:
        DmaCopy16(3, gUnknown_0837A2E8, (void *)BG_PLTT, BG_PLTT_SIZE);
        LZ77UnCompWram(gUnknown_08302700, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06004000, 0x4000);
        LZ77UnCompWram(gUnknown_0838E828, gUnknown_0200FBB0);
        DmaCopy16(3, gUnknown_0200FBB0, (void *)0x06008000, 0x8000);
        DmaCopy16(3, gUnknown_0837A4E8, (void *)0x06000000, 0x800);
        DmaCopy16(3, gUnknown_0838E028, (void *)0x06000800, 0x800);
        DmaCopy16(3, gUnknown_083A8ACC, (void *)0x06006800, 0x400);
        DmaCopy16(3, gUnknown_083A826C, (void *)0x06006C00, 0x800);
        DmaCopy16(3, gUnknown_084779EC, (void *)0x06010000, 0x8000);
        break;
    }

    gUnknown_02031520.unk68 = gUnknown_0816C3E4;
}

void sub_46FD4(s16 arg0)
{
    gUnknown_02031520.unk14.unk38[0] = gUnknown_086AFCB0[gMain.selectedField][arg0].unk0;
    gUnknown_02031520.unk14.unk48[0] = gUnknown_086AFCB0[gMain.selectedField][arg0].unk10;
    gUnknown_02031520.unk14.unk58[0] = gUnknown_086AFCB0[gMain.selectedField][arg0].unk20;
}

void sub_47030(void)
{
    s16 r4;
    const s16 *r3;

    r4 = gMain.bgOffsets[3].yOffset / 8;
    r3 = gUnknown_086B0010[r4];
    if (r4 == gCurrentPinballGame->unk64)
        return;

    if (r4 > gCurrentPinballGame->unk64)
    {
        if (r3[0] > 31)
        {
            DmaCopy16(3, &gUnknown_020030A0[(r3[0] - 32) * 0x400], (void *)0x06008000 + r3[1] * 0x400, 0x400);
        }
        else
        {
            DmaCopy16(3, &gUnknown_0200FBB0[r3[0] * 0x400], (void *)0x06008000 + r3[1] * 0x400, 0x400);
        }
    }
    else
    {
        if (r3[2] > 31)
        {
            DmaCopy16(3, &gUnknown_020030A0[(r3[2] - 32) * 0x400], (void *)0x06008000 + r3[3] * 0x400, 0x400);
        }
        else
        {
            DmaCopy16(3, &gUnknown_0200FBB0[r3[2] * 0x400], (void *)0x06008000 + r3[3] * 0x400, 0x400);
        }
    }

    gCurrentPinballGame->unk64 = r4;
}


