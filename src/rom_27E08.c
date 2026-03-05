#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

extern const u8 gUnknown_081C0064[];
extern const u8 *gEvoItemAppear_GfxList[];
extern const u8 gUnknown_0815C4C4[][0x20];
extern const s16 gUnknown_086AE0E6[];
extern const u16 gUnknown_086B4202[58][15];
extern const struct Vector16 gUnknown_086ACFA0[][8];
extern const s16 gUnknown_08137AB8[];
extern const s16 gUnknown_08137944[];
extern const s16 gUnknown_08055A68[][7];
extern const s16 gUnknown_08137928[];
extern const u16 gUnknown_086B51CE[18][27];
extern const u8 gUnknown_083A8AAC[];
extern const u8 gUnknown_084FA20C[];
extern const u8 gUnknown_083A07CC[];
extern const u8 gUnknown_083A27EC[];
extern const s16 gUnknown_086AE0C0[];
extern const u16 gUnknown_086B50AE[16][18];
extern const u8 gUnknown_083A29EC[];
extern const u8 gUnknown_083A320C[];
extern const u16 gUnknown_086B4F6A[18][18];
extern const u8 gUnknown_083A340C[];
extern const u8 gUnknown_083A542C[];
extern const u8 gUnknown_083A562C[];
extern const u8 gUnknown_083A6E4C[];
extern const s16 gUnknown_086AE0D0[];
extern const u16 gUnknown_086B4E62[22][12];
extern const u8 gUnknown_083A05CC[];
extern const u8 gUnknown_0839DDAC[];
extern const s16 gHatchSequentialTileFramesetData[][2];
extern const u16 gHatchSequentialTileBreakSpritesheetOam[28][18];
extern const s16 gUnknown_086AD52C[28][3];
extern const u8 gUnknown_0202C7A0[][0x120];
extern const struct Vector32 gUnknown_086AD750[];
extern const u16 gUnknown_086AD788[];
extern const struct Vector32 gUnknown_086AD580[][29];
extern const u8 gUnknown_086ACF80[];
extern const u8 gUnknown_081428D4[];
extern const u8 gUnknown_08138014[];
extern const u8 gUnknown_0202D760[];
extern const u16 gUnknown_086B4B0E[48][4][3];
extern const u16 gUnknown_086AE0B4[];
extern const struct Vector16 gUnknown_086AE0A4[];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u16 gUnknown_086B4D4E[40][2][3];
extern const u8 gUnknown_083FFD4C[][0x40];
extern const u8 gUnknown_083FF04C[][0x40];
extern const s16 gUnknown_086ACFE0[];
extern const struct Vector16 gUnknown_086AE088[];
extern const u16 gUnknown_086B4850[14][15];
extern const u8 gUnknown_083A704C[];
extern const u8 gUnknown_083A806C[];
extern const u16 gUnknown_086ADFE2[][2];
extern const u16 gUnknown_086B28A0[82][6][3];
extern const u8 gUnknown_083A808C[];
extern const u8 gUnknown_0848FD8C[];
extern const u16 gUnknown_086B481A[18][3];
extern const u16 gUnknown_086B47DE[4][15];
extern const s16 gUnknown_086ADFC8[];
extern const s16 gUnknown_086ADFD4[];
extern const u8 gUnknown_0847FF0C[][0x300];
extern const u8 gUnknown_08480E0C[][0x40];
extern const s16 gUnknown_086AD456[][7];
extern const u8 gRubyBoardShop_Gfx[][0x500];
extern const u8 gUnknown_083A8A8C[];
extern const struct Vector32 gUnknown_086ADF90[];
extern const u8 gUnknown_084C156C[];

extern u8 gUnknown_020315D0[];

extern struct SongHeader se_unk_84;
extern struct SongHeader se_unk_85;
extern struct SongHeader se_unk_86;


void sub_20EC0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    u16 angle;
    int xx, yy;
    int squaredMagnitude;
    s16 index;

    group = gMain.unk44[41];
    if (gCurrentPinballGame->unk1C0 == 0)
        return;

    if (gCurrentPinballGame->unk1C0 == 800)
    {
        group->available = 1;
        if (gCurrentPinballGame->unk1BE == 1)
        {
            gCurrentPinballGame->unk1FC = 1090;
            gCurrentPinballGame->unk200 = 4680;
            gCurrentPinballGame->unk204 = 0;
        }
        else
        {
            gCurrentPinballGame->unk1FC = 2000;
            gCurrentPinballGame->unk200 = 3820;
            gCurrentPinballGame->unk204 = 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk1C0 == 799)
        {
            if (gCurrentPinballGame->unk1BE != 1)
            {
                DmaCopy16(3, gUnknown_084C07EC, (void *)0x06010600, 0x180);
            }
        }
        tempVec.x = gUnknown_086ADF90[gCurrentPinballGame->unk204].x - 120 - gCurrentPinballGame->unk1FC;
        tempVec.y = gUnknown_086ADF90[gCurrentPinballGame->unk204].y - 160 - gCurrentPinballGame->unk200;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredMagnitude = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle) * 7) / 20000;
        tempVec2.y = (Sin(angle) * -7) / 20000;
        index = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
        gCurrentPinballGame->unk1FC += tempVec2.x;
        gCurrentPinballGame->unk200 += tempVec2.y;
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->unk1FC / 10 - gCurrentPinballGame->unk58;
            group->baseY = gCurrentPinballGame->unk200 / 10 - gCurrentPinballGame->unk5A;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (group->baseY < -30)
                group->baseY = -30;

            DmaCopy16(3, gMonHatchSpriteGroup5_Gfx + (index + 30) * 0x120 , (void *)0x060112A0, 0x120);
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].priority = 1;
                gOamBuffer[oamSimple->oamId].paletteNum = 3;
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        if (squaredMagnitude < 2500)
        {
            gCurrentPinballGame->unk204++;
            if (gCurrentPinballGame->unk1BE == 1)
            {
                if (gCurrentPinballGame->unk204 == 4)
                {
                    DmaCopy16(3, gUnknown_084C156C, (void *)0x06010600, 0x180);
                    gCurrentPinballGame->outLanePikaPosition = 2;
                    gMain.unk44[41]->available = 0;
                    gCurrentPinballGame->unk1C0 = 1;
                    m4aSongNumStart(SE_UNKNOWN_0x75);
                }
            }
            else if (gCurrentPinballGame->unk204 == 7)
            {
                gMain.unk44[41]->available = 0;
                gCurrentPinballGame->unk1C0 = 1;
            }
        }
    }

    gCurrentPinballGame->unk1C0--;
}

void sub_21238(s16 arg0)
{
    if (arg0)
    {
        gCurrentPinballGame->unk714 = 0;
        gCurrentPinballGame->holeIndicators[0] = 0;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    }

    gCurrentPinballGame->unk730 = 0;
    gCurrentPinballGame->unk5F3 = 0;
    if (gCurrentPinballGame->unk16 != 2 || gCurrentPinballGame->unk14 < 3)
    {
        if ((gCurrentPinballGame->unk72 & 0xF) == 0)
        {
            sub_1C7F4(0, 0);
            gCurrentPinballGame->unk6C4 = 0;
        }
    }

    if (gCurrentPinballGame->unk14 == 6 && gCurrentPinballGame->unk16 == 2)
        gCurrentPinballGame->unk2F0 = 0;
}

void sub_21300(void)
{
    gCurrentPinballGame->unk17 = 1;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk6DD = 0;
}

void sub_21320(void)
{
    switch (gCurrentPinballGame->unk17)
    {
    case 1:
        if (gCurrentPinballGame->unk18 < 9)
        {
            gCurrentPinballGame->unk18++;
            if (gCurrentPinballGame->unk18 < 8)
            {
                gCurrentPinballGame->unk730 = 1;
            }
            else if (gCurrentPinballGame->unk18 == 8)
            {
                sub_219A8();
                gCurrentPinballGame->unk730 = 2;
                gCurrentPinballGame->unk708 = 0;
                sub_1C7F4(1, 0);
                gCurrentPinballGame->unk17++;
            }
        }
        break;
    case 2:
        sub_219EC();
        if (gCurrentPinballGame->unk25 == 0)
            sub_1C7F4(1, 0);

        if (gCurrentPinballGame->unk25 == 4)
            gCurrentPinballGame->unk17++;
        break;
    case 3:
        gCurrentPinballGame->unk714 = 0;
        gCurrentPinballGame->holeIndicators[0] = 0;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->unk17++;
        sub_29D9C();
        if (gCurrentPinballGame->unk62D < 99)
            gCurrentPinballGame->unk62D++;
        break;
    case 4:
        if (gCurrentPinballGame->unk28 == 148)
        {
            gCurrentPinballGame->unk28++;
            sub_2A054();
        }
        else if (gCurrentPinballGame->unk28 == 139)
        {
        }
        else if (gCurrentPinballGame->unk28 == 24)
        {
            sub_1C7F4(0, 0);
        }
        else if (gCurrentPinballGame->unk28 == 0)
        {
            gCurrentPinballGame->unk17++;
        }

        if (gCurrentPinballGame->unk6DD)
        {
            sub_2A354();
            if (gCurrentPinballGame->unk6DE < 180)
            {
                gCurrentPinballGame->unk28 = 140;
                if (gCurrentPinballGame->unk6DE == 179)
                    gCurrentPinballGame->unk28 = 30;
            }
        }

        gCurrentPinballGame->unk18 = 0;
        break;
    case 5:
        sub_219EC();
        gMain.unk44[13]->available = 0;
        gCurrentPinballGame->unk17++;
        break;
    case 6:
        sub_21238(1);
        gCurrentPinballGame->unk17++;
        break;
    case 7:
        if (gCurrentPinballGame->unk18)
            gCurrentPinballGame->unk18--;
        else
            sub_19B64(1);
        break;
    }
}

void sub_21514(void)
{
    gCurrentPinballGame->unk730 = 0;
    gCurrentPinballGame->unk5F3 = 0;
    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    gCurrentPinballGame->unk723 = 0;
    gCurrentPinballGame->unk720 = 0;
    gCurrentPinballGame->unk71D[0] = 0;
    gCurrentPinballGame->unk71D[1] = 0;
    gCurrentPinballGame->unk71D[2] = 0;
}

void sub_21578(void)
{
    if (gMain.selectedField == FIELD_RUBY)
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % 5)
        {
        case 0:
        case 2:
            gCurrentPinballGame->unk6EC[0] = 42;
            gCurrentPinballGame->unk284 = FIELD_KECLEON;
            break;
        case 1:
        case 3:
            gCurrentPinballGame->unk6EC[0] = 44;
            gCurrentPinballGame->unk284 = FIELD_GROUDON;
            break;
        case 4:
            gCurrentPinballGame->unk6EC[0] = 45;
            gCurrentPinballGame->unk284 = FIELD_RAYQUAZA;
            break;
        }
    }
    else
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % 5)
        {
        case 0:
        case 2:
            gCurrentPinballGame->unk6EC[0] = 41;
            gCurrentPinballGame->unk284 = FIELD_DUSCLOPS;
            break;
        case 1:
        case 3:
            gCurrentPinballGame->unk6EC[0] = 43;
            gCurrentPinballGame->unk284 = FIELD_KYOGRE;
            break;
        case 4:
            gCurrentPinballGame->unk6EC[0] = 45;
            gCurrentPinballGame->unk284 = FIELD_RAYQUAZA;
            break;
        }
    }

    if (gCurrentPinballGame->unk25 == 4 && gCurrentPinballGame->unk15 == 2)
    {
        gCurrentPinballGame->unk28 = 150;
        gCurrentPinballGame->unk17 = 3;
        gCurrentPinballGame->unk18 = 0;
    }
    else
    {
        gCurrentPinballGame->unk17 = 0;
        gCurrentPinballGame->unk18 = 0;
        gCurrentPinballGame->unk708 = 0;
        sub_1C7F4(7, 0);
    }
}

void sub_216FC(void)
{
    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        if (gCurrentPinballGame->unk18 < 60)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk17++;
        }
        break;
    case 1:
        if (gCurrentPinballGame->unk18 < 9)
        {
            gCurrentPinballGame->unk18++;
            if (gCurrentPinballGame->unk18 < 8)
            {
                gCurrentPinballGame->unk730 = 1;
            }
            else if (gCurrentPinballGame->unk18 == 8)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    m4aSongNumStart(MUS_BONUS_CHANCE);
                    break;
                case 1:
                case 3:
                case 4:
                    m4aSongNumStart(MUS_BONUS_CHANCE_LEGENDARY);
                    break;
                }

                sub_219A8();
                gCurrentPinballGame->unk730 = 2;
                gCurrentPinballGame->unk17++;
                gCurrentPinballGame->unk708 = 0;
            }
        }
        break;
    case 2:
        sub_219EC();
        sub_1C7F4(7, 0);
        if (gCurrentPinballGame->unk25 == 4)
            gCurrentPinballGame->unk17++;
        break;
    case 3:
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unk18 = 0;
        gCurrentPinballGame->unk708 = 0;
        gCurrentPinballGame->unk6EC[0] = 46;
        sub_1C7F4(7, 0);
        break;
    case 4:
        if (gCurrentPinballGame->unk28 == 145)
        {
            gCurrentPinballGame->unk28++;
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->unk28 = 144;
                m4aMPlayAllStop();
            }
            else if (JOY_NEW(B_BUTTON))
            {
                m4aMPlayAllStop();
                m4aSongNumStart(SE_MENU_CANCEL);
                gCurrentPinballGame->unk28 = 60;
                gCurrentPinballGame->unk17 = 6;
                if (gCurrentPinballGame->unk714)
                    gCurrentPinballGame->unk6EE = 120;
            }

            gCurrentPinballGame->unk6EC[0] = 46;
            sub_1C7F4(7, 0);
        }

        if (gCurrentPinballGame->unk28 == 130)
        {
            m4aSongNumStart(SE_WARP);
            gCurrentPinballGame->unk18 = 65;
            gMain.blendControl = 0x9F;
        }

        if (gCurrentPinballGame->unk28 == 125)
            gCurrentPinballGame->unk28++;

        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk1100 = 1;
            gCurrentPinballGame->unk18--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->unk18 / 4;
            if (gCurrentPinballGame->unk18 == 0)
                gCurrentPinballGame->unk17++;
        }
        break;
    case 5:
        if (gCurrentPinballGame->unk18 < 30)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk17 = 0;
            gCurrentPinballGame->unk282 = 0;
            sub_1C73C();
        }
        break;
    case 6:
        sub_219EC();
        gMain.unk44[13]->available = 0;
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unk18 = 0;
        break;
    case 7:
        sub_21514();
        gCurrentPinballGame->unk17++;
        break;
    case 8:
        sub_19B64(1);
        break;
    }
}

void sub_219A8(void)
{
    DmaCopy16(3, gMainStageBonusTrap_Gfx[0], (void *)0x060113C0, 0x300);
    gMain.unk44[13]->available = 1;
    gCurrentPinballGame->unk5F3 = 1;
}

void sub_219EC(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.unk44[13];
    gCurrentPinballGame->unk20B = (gCurrentPinballGame->unk290 % 35) / 7;
    if (group->available)
    {
        group->baseX = 120 - gCurrentPinballGame->unk58;
        group->baseY = 280 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        if (gCurrentPinballGame->unk25 == 3)
        {
            group->baseY = 200;
        }
        else
        {
            if (gCurrentPinballGame->unk20B != gCurrentPinballGame->unk20C)
            {
                DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->unk20B], (void *)0x060113C0, 0x300);
                gCurrentPinballGame->unk20C = gCurrentPinballGame->unk20B;
            }
        }

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_21B0C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;
    s16 sp0[3];

    group = gMain.unk44[17];
    memset(sp0, 0, sizeof(sp0));
    if (gCurrentPinballGame->unk1CA != gCurrentPinballGame->unk1CC)
    {
        if (gCurrentPinballGame->unk1CA == 12) {
            if (gCurrentPinballGame->unk1CE)
            {
                gCurrentPinballGame->unk1CE--;
                index = ((gCurrentPinballGame->unk1CE % 20) / 10) + 12;
                if (gCurrentPinballGame->unk1CE < 41)
                {
                    if (gCurrentPinballGame->unk1CE > 2)
                    {
                        gCurrentPinballGame->unk1D4 += 3;
                        gCurrentPinballGame->unk1D6 += 2;
                    }

                    gCurrentPinballGame->unk1D8 = gCurrentPinballGame->unk1DA = ((gCurrentPinballGame->unk1CE * 128) / 40) + 128;
                    sp0[1] =  ((40 - gCurrentPinballGame->unk1CE) * 16) / 40;
                    sp0[0] = -((40 - gCurrentPinballGame->unk1CE) * 16) / 40;
                    sp0[2] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->unk1CC = 13;
                gCurrentPinballGame->unk1CA = 13;
                index = 13;
                gCurrentPinballGame->unk1D0 = 0;
                gCurrentPinballGame->unk1D6 = 120;
                gCurrentPinballGame->unk1DC = 60;
            }

            DmaCopy16(3, gUnknown_084C00EC[index], (void *)0x06010AE0, 0x80);
        }
        else
        {
            DmaCopy16(3, gUnknown_084C00EC[gCurrentPinballGame->unk1CA], (void *)0x06010AE0, 0x80);
            gCurrentPinballGame->unk1CC = gCurrentPinballGame->unk1CA;
        }
    }

    if (gCurrentPinballGame->unk1D0)
    {
        gCurrentPinballGame->unk1D0--;
        group->baseY = 80 + gCurrentPinballGame->unk1D6;
        if (gCurrentPinballGame->unk1D0 < 20)
            gCurrentPinballGame->unk1DA = (gCurrentPinballGame->unk1D0 * 12) + 16;
    }
    else
    {
        group->baseY = 180;
    }

    group->baseX = 119 + gCurrentPinballGame->unk1D4;
    SetMatrixScale(gCurrentPinballGame->unk1D8, gCurrentPinballGame->unk1DA, 1);
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + sp0[i];
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_NORMAL;
        gOamBuffer[oamSimple->oamId].matrixNum = 1;
    }
}

void sub_21D78(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[78];
    if (gCurrentPinballGame->unk1A4 == 0)
    {
        if (gCurrentPinballGame->unk72E > 2)
        {
            if (gCurrentPinballGame->evolvablePartySize > 0 && gCurrentPinballGame->unk1A5 == 0)
            {
                gCurrentPinballGame->unk1A4 = 1;
                gCurrentPinballGame->unk1B4 = 0;
                gCurrentPinballGame->unk1A5 = 1;
            }
        }
        else if (gCurrentPinballGame->unk13 != 6 && gCurrentPinballGame->unk1A5 == 1 && gCurrentPinballGame->unk25 != 4)
        {
            gCurrentPinballGame->unk1A4 = 1;
            gCurrentPinballGame->unk1B4 = 0;
            gCurrentPinballGame->unk1A5 = 0;
        }
    }
    else
    {
        index = gUnknown_086AD456[gCurrentPinballGame->unk1A5][(gCurrentPinballGame->unk1B4 % 42) / 6];
        if (gCurrentPinballGame->unk1B4 == 0)
        {
            group->available = 1;
            DmaCopy16(3, gUnknown_083A8A8C, (void *)0x05000240, 0x20);
        }
        else if (gCurrentPinballGame->unk1B4 == 37)
        {
            m4aSongNumStart(SE_UNKNOWN_0xCA);
        }

        if (gCurrentPinballGame->unk1B4 % 6 == 0)
        {
            DmaCopy16(3, gRubyBoardShop_Gfx[index], (void *)0x06013D00, 0x500);
        }

        group->baseX = 181 - gCurrentPinballGame->unk58;
        group->baseY = 48 - gCurrentPinballGame->unk5A;
        if (group->baseY < -50)
            group->baseY = -50;

        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        gCurrentPinballGame->unk1B4++;
        if (gCurrentPinballGame->unk1B4 > 40)
        {
            sub_4E9F0(gCurrentPinballGame->unk1A5);
            gCurrentPinballGame->unk1A4 = 0;
            gMain.spriteGroups[78].available = 0;
        }
    }
}

void sub_21FBC(s16 arg0)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const u16 *var1;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 sp0[2];
    s16 sp4[2];

    group = gMain.unk44[7];
    var1 = gUnknown_086AD000[gUnknown_086AD2DE[gCurrentPinballGame->unk1A6]];
    if (arg0)
    {
        index = var1[3] / 10;
        DmaCopy16(3, gUnknown_08480E0C[index], (void *)0x06015DA0, 0x40);
        index = var1[3] % 10;
        DmaCopy16(3, gUnknown_08480E0C[index], (void *)0x06015E60, 0x40);
    }

    if (group->available)
    {
        group->baseX = 156 + gCurrentPinballGame->unk1B6;
        group->baseY = 96;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = gMain.unk44[8];
    index = gCurrentPinballGame->unk1A5 != 0 ? 1 : 0;
    if (group->available)
    {
        group->baseX = (gCurrentPinballGame->unk1B6 + 136);
        group->baseY = 88;
        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B47DE[index][i * 3 + 0];
            *dst++ = gUnknown_086B47DE[index][i * 3 + 1];
            *dst++ = gUnknown_086B47DE[index][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = gMain.unk44[6];
    if (group->available)
    {
        if (gMain.unk2A < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        sp0[0] = -gUnknown_086ADFC8[(gMain.systemFrameCount % 30) / 5];
        sp0[1] = gUnknown_086ADFC8[(gMain.systemFrameCount % 30) / 5];
        sp4[0] = sp0[0];
        sp4[1] = sp0[1];
        if (gCurrentPinballGame->unk1A5 == 0)
        {
            for (i = 0; i < 4; i++)
            {
                s16 i2 = i / 2;
                group->baseX = i2 * 24 + 36 + sp0[i2];
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        else if (gCurrentPinballGame->evolvablePartySize > 1)
        {
            for (i = 0; i < 4; i++)
            {
                group->baseX = (i / 2) * 24 + 36 + sp0[i / 2];
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = 0;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
        }

        if (gCurrentPinballGame->unk1A5 == 0)
            group->baseY = 180;
        else if (gMain.unk2A < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        group->baseX = 48;
        if (gCurrentPinballGame->unk25C < gCurrentPinballGame->unk25D)
        {
            oamSimple = &group->oam[4];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + sp4[0];
        }
        else
        {
            oamSimple = &group->oam[4];
            gOamBuffer[oamSimple->oamId].x = 0;
            gOamBuffer[oamSimple->oamId].y = 180;
        }

        if (gCurrentPinballGame->unk25C > 0)
        {
            oamSimple = &group->oam[5];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + sp4[1];
        }
        else
        {
            oamSimple = &group->oam[5];
            gOamBuffer[oamSimple->oamId].x = 0;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    group = gMain.unk44[9];
    if (group->available)
    {
        group->baseX = 48;
        if (gMain.unk2A < 20)
            group->baseY = 180;
        else
            group->baseY = 88;

        if (gUnknown_086AD2DE[gCurrentPinballGame->unk1A6] == 4)
        {
            if (gCurrentPinballGame->unk1AF && gCurrentPinballGame->unk1B8 / 5 == 0)
                index = 4;
            else
                index = gUnknown_086ADFD4[gCurrentPinballGame->unk1B8 / 5];
        }
        else if (gUnknown_086AD2DE[gCurrentPinballGame->unk1A6] == 3)
        {
            if (gCurrentPinballGame->unk1AA && gCurrentPinballGame->unk1B8 / 5 == 0)
                index = 4;
            else
                index = gUnknown_086ADFD4[gCurrentPinballGame->unk1B8 / 5];
        }
        else
        {
            index = gUnknown_086ADFD4[gCurrentPinballGame->unk1B8 / 5];
        }

        DmaCopy16(3, gUnknown_0847FF0C[index], (void *)0x06016220, 0x300);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_225F0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    int var1;
    s16 var2;

    group = gMain.unk44[39];
    if (gCurrentPinballGame->unk196 < ((gCurrentPinballGame->unk194 - 1) * 9) + 19)
    {
        if (gCurrentPinballGame->unk196 == 0)
        {
            group->available = 1;
            gCurrentPinballGame->unk193 = 0;
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->unk198[i] = 0;
                gCurrentPinballGame->unk19C[i].x = 70;
                gCurrentPinballGame->unk19C[i].y = 180;
            }

            gCurrentPinballGame->unk195 = 0;
        }
        else
        {
            if (gCurrentPinballGame->unk25 == 4 && (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON)))
                gCurrentPinballGame->unk195 = 1;

            if (gCurrentPinballGame->unk193 < gCurrentPinballGame->unk194)
            {
                var1 = gCurrentPinballGame->unk196 - 1;
                if (var1 % 9 == 0)
                {
                    if (gCurrentPinballGame->unk195)
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->unk198[var2] = 17;
                        gCurrentPinballGame->unk19C[var2].x = 188;
                        gCurrentPinballGame->unk19C[var2].y = 140;
                        m4aSongNumStart(SE_UNKNOWN_0x7E);
                        gCurrentPinballGame->coins += gCurrentPinballGame->unk194 - gCurrentPinballGame->unk193;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->unk194 - gCurrentPinballGame->unk193) * 100;
                        gCurrentPinballGame->unk196 = (gCurrentPinballGame->unk194 * 9) + 1;
                        gCurrentPinballGame->unk193 = gCurrentPinballGame->unk194;
                    }
                    else
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->unk198[var2] = 17;
                        gCurrentPinballGame->unk19C[var2].x = 188;
                        gCurrentPinballGame->unk19C[var2].y = 140;
                        gCurrentPinballGame->unk193++;
                        m4aSongNumStart(SE_UNKNOWN_0x7E);
                        gCurrentPinballGame->coins++;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = 100;
                    }
                }
            }

            for (i = 0; i < 2; i++)
            {
                group->baseX = gCurrentPinballGame->unk19C[i].x;
                group->baseY = gCurrentPinballGame->unk19C[i].y;
                if (gCurrentPinballGame->unk19C[i].y > 160)
                    var0 = 0;
                else
                    var0 = (17 - gCurrentPinballGame->unk198[i]) / 2;

                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B481A[var0];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;

                if (gCurrentPinballGame->unk198[i] > 0)
                {
                    gCurrentPinballGame->unk198[i]--;
                    if (gCurrentPinballGame->unk198[i] == 0)
                    {
                        gCurrentPinballGame->unk19C[i].x = 70;
                        gCurrentPinballGame->unk19C[i].y = 180;
                    }
                }
            }
        }

        gCurrentPinballGame->unk196++;
        if (gCurrentPinballGame->unk196 == ((gCurrentPinballGame->unk194 - 1) * 9) + 19)
        {
            gMain.unk44[39]->available = 0;
            gCurrentPinballGame->unk194 = 0;
            if (gCurrentPinballGame->unk25 == 4)
                gCurrentPinballGame->unk6DE = 170;
        }
    }
}

void sub_22978(void)
{
    gCurrentPinballGame->unk2C8 = 1600;
    gCurrentPinballGame->unk2CA = 2080;
    gCurrentPinballGame->unk2C3 = 0;
    gCurrentPinballGame->unk2C4 = 0;
    gMain.spriteGroups[82].available = 1;
    gCurrentPinballGame->unk1EC = 1;
    gCurrentPinballGame->unk1F4 = 240;
    gCurrentPinballGame->unk1F6 = 160;
    gCurrentPinballGame->unkE4 = 3;
    DmaCopy16(3, gUnknown_083A808C, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gUnknown_0848FD8C, (void *)0x06015800, 0xCA0);
}

void sub_22A30(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;

    var0 = 0;
    group = &gMain.spriteGroups[82];
    if (gUnknown_086ADFE2[gCurrentPinballGame->unk2C3][1] > gCurrentPinballGame->unk2C4)
    {
        gCurrentPinballGame->unk2C4++;
    }
    else
    {
        gCurrentPinballGame->unk2C3++;
        gCurrentPinballGame->unk2C4 = 0;
        if (gCurrentPinballGame->unk2C3 == 41)
        {
            gCurrentPinballGame->unk2C3 = 40;
            group->available = 0;
            gCurrentPinballGame->unk2D0 = 2;
            gCurrentPinballGame->unkE4 = 0;
        }

        if (gCurrentPinballGame->unk2C3 == 1)
            m4aSongNumStart(SE_UNKNOWN_0x146);

        if (gCurrentPinballGame->unk2C3 == 7)
            m4aSongNumStart(SE_UNKNOWN_0x147);

        if (gCurrentPinballGame->unk2C3 == 13)
            m4aSongNumStart(SE_UNKNOWN_0x148);

        if (gCurrentPinballGame->unk2C3 == 39)
        {
            gCurrentPinballGame->unk1F4 = 0;
            gCurrentPinballGame->unk1F6 = 0;
            DmaCopy16(3, gUnknown_084FD18C[0], (void *)0x06011CE0, 0x200);
        }

        if (gCurrentPinballGame->unk2C3 == 14)
            gCurrentPinballGame->scoreAddedInFrame = 2000000;
    }

    if (gCurrentPinballGame->unk2C3 >= 14 && gCurrentPinballGame->unk2C3 < 38 && gCurrentPinballGame->unk290 % 7 == 0)
        m4aSongNumStart(SE_UNKNOWN_0x149);

    group->baseX = gCurrentPinballGame->unk2C8 / 20 - gCurrentPinballGame->unk58;
    group->baseY = gCurrentPinballGame->unk2CA / 20 - gCurrentPinballGame->unk5A;
    var0 = gUnknown_086ADFE2[gCurrentPinballGame->unk2C3][0];
    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B28A0[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void sub_22C6C(void)
{
    gCurrentPinballGame->unk2C6 = 0;
    gCurrentPinballGame->unk2C8 = 3600;
    gCurrentPinballGame->unk2CA = -40;
    gCurrentPinballGame->unk2CC = -36;
    gCurrentPinballGame->unk2CE = 60;
    gMain.spriteGroups[12].available = 1;
    gCurrentPinballGame->unk1EC = 1;
    gCurrentPinballGame->unk1F4 = gCurrentPinballGame->unk2C8 / 20 - gUnknown_086AE088[0].x;
    gCurrentPinballGame->unk1F6 = gCurrentPinballGame->unk2CA / 20 - gUnknown_086AE088[0].y;
    gCurrentPinballGame->unkE4 = 2;
    DmaCopy16(3, gUnknown_083A806C, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gUnknown_083A704C, (void *)0x06015800, 0x1000);
}

void sub_22D54(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    var0 = (gCurrentPinballGame->unk2C6 % 56) / 8;
    group = &gMain.spriteGroups[12];
    if (gCurrentPinballGame->unk2C6 < 130)
    {
        if (gCurrentPinballGame->unk2C6 % 36U == 0)
            m4aSongNumStart(SE_UNKNOWN_0xB8);

        gCurrentPinballGame->unk2C6++;
        gCurrentPinballGame->unk2C8 += gCurrentPinballGame->unk2CC;
        gCurrentPinballGame->unk2CA += gCurrentPinballGame->unk2CE;
        if (gCurrentPinballGame->unk2CE > 7 || gMain.systemFrameCount % 3 == 0)
            gCurrentPinballGame->unk2CE--;

        if (gCurrentPinballGame->unk2C6 < 78)
        {
            gCurrentPinballGame->unk1F4 = gCurrentPinballGame->unk2C8 / 20 - gUnknown_086AE088[var0].x;
            gCurrentPinballGame->unk1F6 = gCurrentPinballGame->unk2CA / 20 - gUnknown_086AE088[var0].y;
        }
        else
        {
            gCurrentPinballGame->unk1F4 = 0;
            gCurrentPinballGame->unk1F6 = 0;
        }

        if (gCurrentPinballGame->unk2C6 == 78)
            gCurrentPinballGame->scoreAddedInFrame = 100000;

        DmaCopy16(3, gUnknown_084FD18C[0], (void *)0x06011CE0, 0x200);
    }
    else
    {
        group->available = 0;
        do {} while (0); // needed to match, there was probably some dead code
        gCurrentPinballGame->unk2D0 = 2;
        gCurrentPinballGame->unkE4 = 0;
    }

    group->baseX = gCurrentPinballGame->unk2C8 / 20 - gCurrentPinballGame->unk58;
    group->baseY = gCurrentPinballGame->unk2CA / 20 - gCurrentPinballGame->unk5A;
    for (i = 0; i < 5; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gUnknown_086B4850[var0][i * 3 + 0];
        *dst++ = gUnknown_086B4850[var0][i * 3 + 1];
        *dst++ = gUnknown_086B4850[var0][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void sub_22FA4(void)
{
    s16 i;
    int index;

    gCurrentPinballGame->unk20E = 0;
    sub_1C7F4(9, 0);
    gCurrentPinballGame->unkE4 = 14;
    gMain.unk44[4]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == 0x20)
        {
            DmaCopy16(3, gUnknown_083FFD4C[0], (void *)0x06015800 + i * 0x40, 0x40);
            gCurrentPinballGame->unk20E += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 0x41;
            DmaCopy16(3, gUnknown_083FF04C[index], (void *)0x06015800 + i * 0x40, 0x40);
        }
    }
}

void sub_23070(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.unk44[4];
    for (i = 0; i < 10; i++)
    {
        group->baseX = i * 8 + (gCurrentPinballGame->unk20E + 152) + gCurrentPinballGame->unk1B6;
        group->baseY = 96;
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_2310C(void)
{
    gMain.unk44[4]->available = 0;
    gCurrentPinballGame->unkE4 = 0;
}

void sub_2312C(void)
{
    s16 i;
    u8 letter;
    int index;
    const u8 *dest;

    gCurrentPinballGame->unk20E = 0;
    gCurrentPinballGame->unk6DB = 0;
    gCurrentPinballGame->unk210 = 0;
    sub_1C7F4(3, 0);
    gCurrentPinballGame->unkE4 = 13;
    gMain.unk44[4]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == 0x20)
        {
            DmaCopy16(3, gUnknown_083FFD4C[0], (void *)0x06015800 + i * 0x40, 0x40);
            gCurrentPinballGame->unk20E += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 0x41;
            DmaCopy16(3, gUnknown_083FF04C[index], (void *)0x06015800 + i * 0x40, 0x40);
        }
    }

    gMain.unk44[5]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gUnknown_086ACFE0[i] == 0x20)
        {
            DmaCopy16(3, gUnknown_083FFD4C[0], (void *)0x06015800 + (i + 10) * 0x40, 0x40);
        }
        else
        {
            index = gUnknown_086ACFE0[i] - 0x41;
            DmaCopy16(3, gUnknown_083FF04C[index], (void *)0x06015800 + (i + 10) * 0x40, 0x40);
        }
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->unk212[i] = i * 2;
        gCurrentPinballGame->unk228[i].x = 0;
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->unk13D4[i] = (i + 10) * 2;
        gCurrentPinballGame->unk13E8[i].x = 0;
    }
}

void sub_23300(void)
{
    s16 i, j, k;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u32 var0;

    gCurrentPinballGame->unk6C4 = 0;
    if (gCurrentPinballGame->unk210 == 0)
    {
        gCurrentPinballGame->unk210++;
        group = gMain.unk44[4];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.unk44[5];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
    else if (gCurrentPinballGame->unk210 < 195)
    {
        gCurrentPinballGame->unk210++;
        if (gCurrentPinballGame->unk210 < 156)
        {

            group = gMain.unk44[4];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->unk212[i])
                {
                    gCurrentPinballGame->unk212[i]--;
                }
                else
                {
                    gCurrentPinballGame->unk228[i].x += ((1600 - gCurrentPinballGame->unk228[i].x) * 12) / 100;
                    if (gCurrentPinballGame->unk228[i].x >= 1592)
                        gCurrentPinballGame->unk228[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->unk58 - (gCurrentPinballGame->unk228[i].x / 10 - var0) + gCurrentPinballGame->unk20E;;
                group->baseY = gCurrentPinballGame->unk6E4.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.unk44[5];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->unk13D4[i])
                {
                    gCurrentPinballGame->unk13D4[i]--;
                }
                else
                {
                    gCurrentPinballGame->unk13E8[i].x += ((1600 - gCurrentPinballGame->unk13E8[i].x) * 12) / 100;
                    if (gCurrentPinballGame->unk13E8[i].x >= 1592)
                        gCurrentPinballGame->unk13E8[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->unk58 - (gCurrentPinballGame->unk13E8[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->unk6E4.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->unk210 == 155)
            {
                for (j = 0; j < 10; j++)
                {
                    gCurrentPinballGame->unk212[j] = j * 2;
                    gCurrentPinballGame->unk228[j].x = 0;
                }

                for (k = 0; k < 10; k++)
                {
                    gCurrentPinballGame->unk13D4[k] = (k + 10) * 2;
                    gCurrentPinballGame->unk13E8[k].x = 0;
                }
            }
        }
        else
        {
            group = gMain.unk44[4];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->unk212[i])
                    gCurrentPinballGame->unk212[i]--;
                else
                    gCurrentPinballGame->unk228[i].x += ((2000 - gCurrentPinballGame->unk228[i].x) * 12) / 100;

                var0 = i * 8 + 80;
                group->baseX = var0 - gCurrentPinballGame->unk58 - gCurrentPinballGame->unk228[i].x / 10 + gCurrentPinballGame->unk20E;
                group->baseY = gCurrentPinballGame->unk6E4.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.unk44[5];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->unk13D4[i])
                    gCurrentPinballGame->unk13D4[i]--;
                else
                    gCurrentPinballGame->unk13E8[i].x += ((2000 - gCurrentPinballGame->unk13E8[i].x) * 12) / 100;

                var0 = 0;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->unk58 - (gCurrentPinballGame->unk13E8[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->unk6E4.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
    else
    {
        group = gMain.unk44[4];
        if (group->available)
        {
            group->baseX = 0;
            group->baseY = 180;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        group = gMain.unk44[5];
        if (group->available)
        {
            group->baseX = 0;
            group->baseY = 180;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        gMain.unk44[4]->available = 0;
        gMain.unk44[5]->available = 0;
        gCurrentPinballGame->unkE4 = 0;
    }
}

void sub_23954(void)
{
    gCurrentPinballGame->unk1EC = 1;
    gCurrentPinballGame->unk1EE = 0;
    gCurrentPinballGame->unk1ED = 0;
    gCurrentPinballGame->unk1F0 = 0;
    gCurrentPinballGame->unk2DA = 0;
    gCurrentPinballGame->unk2D9 = 0;
}

void sub_239A4(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    s16 var1;
    s16 var2;
    s16 var3;
    s16 priority;
    s16 index;

    priority = 1;
    var0 = 0;
    var1 = 0;
    var2 = 0;
    group = &gMain.spriteGroups[48];
    var3 = 0;
    switch (gCurrentPinballGame->unk1EC)
    {
    case 0:
    case 1:
        break;
    case 2:
        var0 = 4;
        var1 = 4;
        var2 = 3;
        break;
    case 3:
        var0 = 8;
        var1 = 4;
        var2 = 3;
        break;
    case 4:
        var0 = 12;
        var1 = 12;
        var2 = 5;
        break;
    case 5:
        var0 = 33;
        var1 = 0;
        var2 = 0;
        break;
    }

    if (gCurrentPinballGame->unk1EE != gCurrentPinballGame->unk1ED)
    {
        index = gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][2];
        DmaCopy16(3, gRubyBoardHatchCave_Gfx[index], (void *)0x060122A0, 0x480);
        index = gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][3];
        DmaCopy16(3, gUnknown_084FD18C[index], (void *)0x06011CE0, 0x200);
        gCurrentPinballGame->unk1EE = gCurrentPinballGame->unk1ED;
    }

    if (gCurrentPinballGame->unk1EC > 1)
    {
        if (gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][1] > gCurrentPinballGame->unk1F0)
        {
            gCurrentPinballGame->unk1F0++;
        }
        else
        {
            gCurrentPinballGame->unk1ED++;
            gCurrentPinballGame->unk1F0 = 0;
            if (gCurrentPinballGame->unk1ED >= var0)
            {
                gCurrentPinballGame->unk1ED = var1;
                gCurrentPinballGame->unk1EC = var2;
            }

            if (gCurrentPinballGame->unk1ED == 18)
                BuildSpeciesWeightsForEggMode();

            if (gCurrentPinballGame->unk1ED == 19)
            {
                PickSpeciesForEggMode();
                if (gMain.mainState != STATE_GAME_IDLE)
                    SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);
            }

            if (gCurrentPinballGame->unk1ED == 20)
                sub_28BFC();

            if ((gCurrentPinballGame->unk1ED == 8 || gCurrentPinballGame->unk1ED == 27) && gCurrentPinballGame->unk1F0 == 0)
                m4aMPlayAllStop();

            if (gCurrentPinballGame->unk1ED == 12 && gCurrentPinballGame->unk1F0 == 0)
                m4aSongNumStart(MUS_EGG_MODE_START);

            if (gCurrentPinballGame->unk1ED == 29)
                sub_19B64(5);

            if (gCurrentPinballGame->unk1ED == 28)
                m4aSongNumStart(SE_UNKNOWN_0x92);
        }

        var3 = gUnknown_086AD2EE[gCurrentPinballGame->unk1ED][0];
    }

    gCurrentPinballGame->unk1E8 = 88 - gCurrentPinballGame->unk58;
    gCurrentPinballGame->unk1EA = 144 - gCurrentPinballGame->unk5A;
    group->baseX = gCurrentPinballGame->unk1E8 + gCurrentPinballGame->unk1F4;
    if (gCurrentPinballGame->unk1EC > 0)
    {
        if (gCurrentPinballGame->unk1ED == 32 && gCurrentPinballGame->unk1F0 > 208)
        {
            s16 varZ = (0x100 - gCurrentPinballGame->unk1F0) / 16 + 1;
            if (gMain.systemFrameCount & (varZ << 1))
                group->baseY = gCurrentPinballGame->unk1EA + gCurrentPinballGame->unk1F6;
            else
                group->baseY = 200;
        }
        else
        {
            group->baseY = gCurrentPinballGame->unk1EA + gCurrentPinballGame->unk1F6;
        }
    }
    else
    {
        group->baseY = 200;
    }

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B4D4E[var3][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[52];
    group->baseX = gCurrentPinballGame->unk1E8;
    group->baseY = gCurrentPinballGame->unk1EA;
    for (i = 0; i < 4; i++)
    {
        oamSimple = &gMain.spriteGroups[52].oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_23E18(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 var0;

    priority = 1;
    group = &gMain.spriteGroups[51];
    var0 = gMain.systemFrameCount % 36;
    gCurrentPinballGame->unk746 = 0;
    gCurrentPinballGame->unk2D8 = 1;
    if (gCurrentPinballGame->unk2DA < 3)
    {
        gCurrentPinballGame->unk746 = gUnknown_086AE0B4[var0 / 6];
        gCurrentPinballGame->unk2D4 = gUnknown_086AE0A4[gCurrentPinballGame->unk2DA].x;
        gCurrentPinballGame->unk2D6 = gUnknown_086AE0A4[gCurrentPinballGame->unk2DA].y;
        group->baseX = gCurrentPinballGame->unk2D4 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk2D6 - gCurrentPinballGame->unk5A;
        if (var0 % 6 == 0)
        {
            DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->unk746], (void *)0x06013300, 0x280);
        }
    }
    else if (gCurrentPinballGame->unk2DA == 3)
    {
        if (gCurrentPinballGame->unk2D0 != 2)
        {
            if (gCurrentPinballGame->unk1EC == 1)
            {
                gCurrentPinballGame->unk1EC = 2;
                gCurrentPinballGame->unk746 = 1;
                DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->unk746], (void *)0x06013300, 0x280);
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->unkEA = 0;
                gCurrentPinballGame->unkEC = 60;
                gCurrentPinballGame->unkE8 = 72;
                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unkEE = 2;
                gCurrentPinballGame->unkF2 = 0;
                gCurrentPinballGame->unkFA = 1;
                gCurrentPinballGame->unkFB = 0;
                gCurrentPinballGame->unk2DE = 48;
            }

            if (gCurrentPinballGame->unk2D9)
            {
                gCurrentPinballGame->unk2D9 = 0;
                gCurrentPinballGame->unk2DE = 48;
            }
        }
        else
        {
            if (gCurrentPinballGame->unk2DE == 0)
            {
                if (gCurrentPinballGame->unk2E0 == 30)
                {
                    gCurrentPinballGame->unk1F = 0;
                    gCurrentPinballGame->unk26 = 60;
                    gCurrentPinballGame->ball->velocity.x = 20;
                    gCurrentPinballGame->ball->velocity.y = 200;
                    gCurrentPinballGame->ball->positionQ0.x = 88;
                    gCurrentPinballGame->ball->positionQ0.y = 163;
                    gCurrentPinballGame->ball->unk6 = 0;
                    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                    m4aSongNumStart(SE_UNKNOWN_0xB9);
                    gCurrentPinballGame->unk5FA = 0;
                }

                if (gCurrentPinballGame->unk2E0)
                {
                    gCurrentPinballGame->unk2E0--;
                }
                else
                {
                    sub_23954();
                    gCurrentPinballGame->unk2DA = 0;
                    gCurrentPinballGame->unk2D0 = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->positionQ0.x = 88;
                gCurrentPinballGame->ball->positionQ0.y = 163 - gCurrentPinballGame->unk2DE / 3;
                gCurrentPinballGame->ball->unk6 = 0;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
                gCurrentPinballGame->unk5FA = 1;
            }
        }

        gCurrentPinballGame->unk2D4 = gUnknown_086AE0A4[gCurrentPinballGame->unk2DA].x;
        gCurrentPinballGame->unk2D6 = gUnknown_086AE0A4[gCurrentPinballGame->unk2DA].y - gCurrentPinballGame->unk2DE / 3;
        group->baseX = gCurrentPinballGame->unk2D4 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk2D6 - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk13 < 3)
        {
            if (gCurrentPinballGame->unk2DA == 3 && gCurrentPinballGame->unk2D0 != 2)
                gCurrentPinballGame->unk728 = 1;
            else
                gCurrentPinballGame->unk728 = 0;
        }
        else
        {
            gCurrentPinballGame->unk728 = 0;
        }

        if (gCurrentPinballGame->unk2DE)
        {
            gCurrentPinballGame->unk2DE--;
            priority = 2;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk1EC == 3)
        {
            gCurrentPinballGame->unk728 = 0;
            gCurrentPinballGame->unk1EC = 4;
            gCurrentPinballGame->unk1ED = 8;
            gCurrentPinballGame->unk1F0 = 0;
        }

        gCurrentPinballGame->unk2D4 = 0;
        gCurrentPinballGame->unk2D6 = 0;
        group->baseX = 0;
        group->baseY = 160;
    }

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_242B4(void)
{
    s16 i;

    if (gMain.selectedField == FIELD_RUBY)
        gCurrentPinballGame->unk2D0 = 1;
    else
        gCurrentPinballGame->unk343 = 1;

    gCurrentPinballGame->unk5A5 = 0;
    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->unk723)
            gCurrentPinballGame->unk71D[i] = 1;
        else
            gCurrentPinballGame->unk71D[i] = 0;
    }
}

void sub_24350(void)
{
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk724 = 1800;
    gCurrentPinballGame->unk5A5 = 0;
    gCurrentPinballGame->unk1F8 = 0;
    gCurrentPinballGame->unk1FA = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->unk1FC = 750;
        gCurrentPinballGame->unk200 = 1040;
    }
    else
    {
        gCurrentPinballGame->unk1FC = 1960;
        gCurrentPinballGame->unk200 = 300;
    }

    gCurrentPinballGame->unk204 = 0;
    gCurrentPinballGame->unk206 = 0;
    gCurrentPinballGame->unk1F8 = 0;
    gCurrentPinballGame->unk1FA = 0;
    gCurrentPinballGame->unk5AA = 0;
    gCurrentPinballGame->unk5A9 = 0;
}

void sub_24408(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    s16 var1;
    int priority;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    u16 angle;
    u16 angle2;
    int xx, yy;
    int squaredMagnitude;

    group = gMain.unk44[41];
    priority = 1;
    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        gCurrentPinballGame->unk6C4 = 3;
        gMain.unk44[41]->available = 1;
        gCurrentPinballGame->unk17++;
        break;
    case 1:
        if (gUnknown_086AD52C[gCurrentPinballGame->unk204][1] > gCurrentPinballGame->unk206)
        {
            gCurrentPinballGame->unk206++;
        }
        else
        {
            gCurrentPinballGame->unk204++;
            gCurrentPinballGame->unk206 = 0;
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->unk204 > 13)
                {
                    gCurrentPinballGame->unk204 = 0;
                    gCurrentPinballGame->unk17 = 3;
                    gCurrentPinballGame->unk1F8 = 0;
                    gCurrentPinballGame->unk1FA = 0;
                }

                if (gCurrentPinballGame->unk204 == 12)
                {
                    if (gCurrentPinballGame->unk206 == 0)
                        m4aSongNumStart(MUS_EGG_MODE);
                }

                if (gCurrentPinballGame->unk204 == 10)
                {
                    gCurrentPinballGame->unk29C = 140;
                    PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].mainSeriesIndexNumber, 0);
                }

                if (gCurrentPinballGame->unk204 == 12)
                {
                    gCurrentPinballGame->unk1F8 = -8;
                    gCurrentPinballGame->unk1FA = -30;
                }
                else
                {
                    gCurrentPinballGame->unk1F8 = 0;
                    gCurrentPinballGame->unk1FA = 0;
                }
            }
            else
            {
                if (gCurrentPinballGame->unk204 > 9)
                {
                    gCurrentPinballGame->unk206 = 0;
                    gCurrentPinballGame->unk204 = 10;
                    gCurrentPinballGame->unk17 = 2;
                    gCurrentPinballGame->unk1F8 = 0;
                    gCurrentPinballGame->unk1FA = 0;
                }
            }
        }

        var0 = gUnknown_086AD52C[gCurrentPinballGame->unk204][0];
        var1 = gUnknown_086AD52C[gCurrentPinballGame->unk204][2];
        if (gCurrentPinballGame->unk204 == 12)
        {
            gCurrentPinballGame->unk1FA += 2;
            gCurrentPinballGame->unk1FC += gCurrentPinballGame->unk1F8;
            gCurrentPinballGame->unk200 += gCurrentPinballGame->unk1FA;
        }

        group->baseX = gCurrentPinballGame->unk1FC / 10 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk200 / 10 - gCurrentPinballGame->unk5A;
        DmaCopy16(3, gUnknown_0202C7A0[var0], (void *)0x060112A0, 0x120);
        DmaCopy16(3, gUnknown_020315D0, (void *)0x050003A0, 0x20);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B4B0E[var1][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
            gOamBuffer[oamSimple->oamId].priority = priority;
        }
        break;
    case 2:
        if (gCurrentPinballGame->unk206 < 240)
        {
            priority = 1;
            if (gCurrentPinballGame->unk206 == 0)
            {
                gCurrentPinballGame->unk346 = 3;
                m4aSongNumStart(SE_UNKNOWN_0xDD);
            }
            var0 = 0;
        }
        else if (gCurrentPinballGame->unk206 == 240)
        {
            gCurrentPinballGame->unk1FC = 2260;
            gCurrentPinballGame->unk200 = 740;
            gCurrentPinballGame->unk204 = 0;
            priority = 2;
            var0 = 0;
            m4aSongNumStart(MUS_EGG_MODE);
        }
        else
        {
            tempVec.x = gUnknown_086AD750[gCurrentPinballGame->unk204].x - 120 - gCurrentPinballGame->unk1FC;
            tempVec.y = gUnknown_086AD750[gCurrentPinballGame->unk204].y - 160 - gCurrentPinballGame->unk200;
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredMagnitude = xx + yy;
            angle = ArcTan2(tempVec.x,-tempVec.y);
            if (gCurrentPinballGame->unk206 < 324)
                priority = 2;
            else
                priority = 1;

            if (gCurrentPinballGame->unk204 < 4)
            {
                var0 = 0;
                tempVec2.x = (Cos(angle) * 14) / 20000;
                tempVec2.y = -(Sin(angle) * 14) / 20000;
            }
            else
            {
                var0 = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
                tempVec2.x = (Cos(angle) * 7) / 20000;
                tempVec2.y = -(Sin(angle) * 7) / 20000;
            }

            gCurrentPinballGame->unk1FC += tempVec2.x;
            gCurrentPinballGame->unk200 += tempVec2.y;
            if (squaredMagnitude < 2500)
            {
                if (gCurrentPinballGame->unk204 < 6)
                {
                    gCurrentPinballGame->unk204++;
                }
                else
                {
                    gCurrentPinballGame->unk204 = 3;
                    gCurrentPinballGame->unk17 = 3;
                    gCurrentPinballGame->unk1F8 = 0;
                    gCurrentPinballGame->unk1FA = 0;
                }
            }

            if (gCurrentPinballGame->unk206 < 380)
            {
                gCurrentPinballGame->unkE6++;
            }
            else if (gCurrentPinballGame->unk206 >= 400)
            {
                if (gCurrentPinballGame->unkE6 > 0)
                    gCurrentPinballGame->unkE6--;
            }
        }

        DmaCopy16(3, gUnknown_0202C7A0[var0], (void *)0x060112A0, 0x120);
        gCurrentPinballGame->unk206++;
        group->baseX = gCurrentPinballGame->unk1FC / 10 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk200 / 10 - gCurrentPinballGame->unk5A;
        if (group->baseY > 180)
            group->baseY = 180;
        else if (group->baseY < -30)
            group->baseY = -30;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = priority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
        break;
    case 3:
        tempVec.x = gUnknown_086AD580[gMain.selectedField][gCurrentPinballGame->unk204].x - 120 - gCurrentPinballGame->unk1FC;
        tempVec.y = gUnknown_086AD580[gMain.selectedField][gCurrentPinballGame->unk204].y - 160 - gCurrentPinballGame->unk200;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredMagnitude = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle) * 7) / 20000;
        tempVec2.y = -(Sin(angle) * 7) / 20000;
        if (gCurrentPinballGame->unk5A9)
        {
            gCurrentPinballGame->unk5A9--;
            var0 = 14;
        }
        else
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].unk13)
            {
                var0 = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
            }
            else
            {
                var0 = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 32) / 8 - ((gMain.systemFrameCount % 32) / 24) * 2;
            }

            gCurrentPinballGame->unk1FC += tempVec2.x;
            gCurrentPinballGame->unk200 += tempVec2.y;
        }

        if (squaredMagnitude < 2500)
        {
            if (gCurrentPinballGame->unk204 < 28)
            {
                gCurrentPinballGame->unk204++;
            }
            else
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL);
                gCurrentPinballGame->unk18 = 200;
                gCurrentPinballGame->unk17 = 6;
            }
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->unk204 > 26)
                priority = 2;
            else
                priority = 1;
        }
        else if (gCurrentPinballGame->unk204 > 27)
        {
            priority = 3;
            gCurrentPinballGame->unk367 = 1;
        }
        else
        {
            priority = 1;
        }

        group->baseX = gCurrentPinballGame->unk1FC / 10 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk200 / 10 - gCurrentPinballGame->unk5A;;
        if (group->baseY > 180)
            group->baseY = 180;
        else if (group->baseY < -30)
            group->baseY = -30;

        DmaCopy16(3, gUnknown_0202C7A0[var0], (void *)0x060112A0, 0x120);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = priority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->unk5AA)
        {
            gCurrentPinballGame->unk5AA--;
        }
        else
        {
            tempVec.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->unk1FC / 10 + 12);
            tempVec.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->unk200 / 10 + 14);
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredMagnitude = xx + yy;
            if (squaredMagnitude < 82)
            {
                gCurrentPinballGame->unk5A5++;
                gCurrentPinballGame->unk5AA = 4;
                gCurrentPinballGame->unk5A9 = 20;
                if (gCurrentPinballGame->unk5A5 > 1)
                    gCurrentPinballGame->unk17 = 4;

                m4aSongNumStart(SE_UNKNOWN_0x75);
                angle2 = ArcTan2(-gCurrentPinballGame->ball->velocity.x, gCurrentPinballGame->ball->velocity.y);
                if (gCurrentPinballGame->unk5A5 > 1)
                {
                    gCurrentPinballGame->ball->velocity.x = (Cos(angle2) * 400) / 20000;
                    gCurrentPinballGame->ball->velocity.y = -(Sin(angle2) * 400) / 20000;
                }
                else
                {
                    gCurrentPinballGame->ball->velocity.x = (Cos(angle2) * 160) / 20000;
                    gCurrentPinballGame->ball->velocity.y = -(Sin(angle2) * 160) / 20000;
                }

                PlayRumble(7);
            }
        }
        break;
    case 4:
        gCurrentPinballGame->unkE4 = 9;
        DmaCopy16(3, gUnknown_086ACF80, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gUnknown_081428D4, (void *)0x06015800, 0x1C00);
        DmaCopy16(3, &gUnknown_08138014[gCurrentPinballGame->ballUpgradeType * 0x200], (void *)0x060164C0, 0x80);
        DmaCopy16(3, &gUnknown_08138014[(gCurrentPinballGame->ballUpgradeType * 8 + 4) * 0x40], (void *)0x06016760, 0x80);
        gCurrentPinballGame->unk5A6 = 0;
        gCurrentPinballGame->unk5A4 = 2;
        gCurrentPinballGame->unk288 = gCurrentPinballGame->unk1FC / 10 + 8;
        gCurrentPinballGame->unk28A = gCurrentPinballGame->unk200 / 10 - 31;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->unk6D3[i] = 13;

        gCurrentPinballGame->unk17++;
        group->baseX = gCurrentPinballGame->unk1FC / 10 - gCurrentPinballGame->unk58;
        group->baseY = gCurrentPinballGame->unk200 / 10 - gCurrentPinballGame->unk5A;
        if (group->baseY > 180)
            group->baseY = 180;

        DmaCopy16(3, gUnknown_0202D760, (void *)0x060112A0, 0x120);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = 2;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        gCurrentPinballGame->unk18 = 0;
        break;
    case 5:
        if (gCurrentPinballGame->unk5A8 < 17)
            priority = 2;
        else
            priority = 0;

        if (group->available)
        {
            group->baseX = gCurrentPinballGame->unk1FC / 10 - gCurrentPinballGame->unk58;
            group->baseY = gCurrentPinballGame->unk200 / 10 - gCurrentPinballGame->unk5A;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].priority = priority;
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            DmaCopy16(3, gUnknown_0202D760, (void *)0x060112A0, 0x120);
            if (gCurrentPinballGame->unk5A8 == 23)
                gMain.unk44[41]->available = 0;
        }
        break;
    case 6:
        if (group->available)
        {
            group->baseX = 0;
            group->baseY = 200;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        gMain.unk44[41]->available = 0;
        gCurrentPinballGame->unk17++;
        break;
    case 7:
        sub_242B4();
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unk367 = 0;
        break;
    case 8:
        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk18--;
        }
        else
        {
            if (gCurrentPinballGame->unk71D[2] == 1)
                sub_19B64(3);
            else
                sub_19B64(1);

            gCurrentPinballGame->unk17 = 0;
        }
        break;
    }
}

void sub_2530C(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.unk44[18];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.unk44[18]->available = 0;
    group = gMain.unk44[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.unk44[12]->available = 0;
    gCurrentPinballGame->unkE4 = 0;
}

void RevealSequentialHatchTiles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;
    int var1;

    var1 = 1;
    gMain.unk44[18]->available = 1;
    if (gCurrentPinballGame->hatchFrameId > 0)
        sub_2971C();

    if (gCurrentPinballGame->hatchSequentialTilesRevealed < gCurrentPinballGame->hatchTilesBoardAcknowledged)
    {
        if (gCurrentPinballGame->hatchFrameId == 0 && gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer == 0)
        {
            gCurrentPinballGame->unkE4 = 11;
            DmaCopy16(3, gUnknown_083A05CC, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gUnknown_0839DDAC, (void *)0x06015800, 0x2800);
        }

        if (gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][1] > gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer)
        {
            gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
            gCurrentPinballGame->hatchFrameId++;
            if (gCurrentPinballGame->hatchFrameId > 12)
            {
                gCurrentPinballGame->hatchSequentialTilesRevealed++;
                gCurrentPinballGame->hatchFrameId = 0;
                var1 = 0;
                gCurrentPinballGame->unk6C9--;
                if (gCurrentPinballGame->hatchSequentialTilesRevealed == gCurrentPinballGame->hatchTilesBoardAcknowledged)
                {
                    if (gCurrentPinballGame->unk6C9 >= 0)
                        gCurrentPinballGame->unkE4 = 0;
                }

                if (gCurrentPinballGame->unk6C9 < 0)
                {
                    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                    for (i = 0; i < 6; i++)
                        gCurrentPinballGame->unk6CD[i] = i;

                    var0 = gMain.systemFrameCount % 6;
                    gCurrentPinballGame->unk6C9 = 5;
                    gCurrentPinballGame->unk17++;
                    gMain.unk44[18]->available = 0;
                }
                else if (gCurrentPinballGame->unk6C9 == 0)
                {
                    var0 = 0;
                }
                else
                {
                    var0 = gMain.systemFrameCount % gCurrentPinballGame->unk6C9;
                }

                gCurrentPinballGame->unk6C8 = gCurrentPinballGame->unk6CD[var0];
                for (i = var0; i < gCurrentPinballGame->unk6C9; i++)
                    gCurrentPinballGame->unk6CD[i] = gCurrentPinballGame->unk6CD[i + 1];
            }
            else
            {
                if (gCurrentPinballGame->hatchFrameId == 1)
                    gCurrentPinballGame->unk6D3[gCurrentPinballGame->unk6C8] = 13;
            }
        }
    }
    else
    {
        var1 = 0;
    }

    if (gCurrentPinballGame->hatchFrameId == 1)
    {
        m4aSongNumStart(SE_UNKNOWN_0x8C);
        sub_29664();
    }

    if (gCurrentPinballGame->hatchFrameId == 12)
        var1 = 0;

    group = gMain.unk44[18];
    if (var1)
    {
        group->baseX = (gCurrentPinballGame->unk6C8 % 3) * 16 - (gCurrentPinballGame->unk58 - 96);
        group->baseY = (gCurrentPinballGame->unk6C8 / 3) * 16 - (gCurrentPinballGame->unk5A - 300);
    }
    else
    {
        group->baseY = 200;
    }

    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 0];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 1];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].priority = 3;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void RevealAllHatchTilesAtOnce(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    switch (gCurrentPinballGame->unk602)
    {
    case 0:
        if (gCurrentPinballGame->unk604 < 60)
        {
            gCurrentPinballGame->unk604++;
        }
        else
        {
            gCurrentPinballGame->unk602++;
            gCurrentPinballGame->unk604 = 0;
        }
        gMain.blendControl = 0xCE;
        break;
    case 1:
        gCurrentPinballGame->unkE4 = 5;
        DmaCopy16(3, gUnknown_083A07CC, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gUnknown_083A27EC, (void *)0x050003C0, 0x20);
        gMain.unk44[35]->available = 1;
        m4aSongNumStart(SE_UNKNOWN_0x8D);
        gCurrentPinballGame->unk602++;
        gCurrentPinballGame->unk604 = 0;
        gCurrentPinballGame->unk603 = 0;
        break;
    case 2:
        if (gUnknown_086AE0C0[gCurrentPinballGame->unk603] > gCurrentPinballGame->unk604)
        {
            gCurrentPinballGame->unk604++;
        }
        else
        {
            gCurrentPinballGame->unk604 = 0;
            gCurrentPinballGame->unk603++;
            if (gCurrentPinballGame->unk603 > 7)
            {
                gCurrentPinballGame->unk603 = 7;
                gCurrentPinballGame->unk602++;
                gMain.unk44[35]->available = 0;
            }
        }

        var0 = gCurrentPinballGame->unk603;
        group = gMain.unk44[35];
        group->baseX = 124 - gCurrentPinballGame->unk58;
        group->baseY = 244 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B50AE[var0][i * 3 + 0];
            *dst++ = gUnknown_086B50AE[var0][i * 3 + 1];
            *dst++ = gUnknown_086B50AE[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 3:
        gCurrentPinballGame->unkE4 = 6;
        DmaCopy16(3, gUnknown_083A29EC, (void *)0x06015800, 0x800);
        DmaCopy16(3, gUnknown_083A320C, (void *)0x050003C0, 0x20);
        gMain.unk44[36]->available = 1;
        gCurrentPinballGame->unk602++;
        gCurrentPinballGame->unk604 = 0;
        gCurrentPinballGame->unk1100 = 1;
        break;
    case 4:
        var0 = gCurrentPinballGame->unk604 / 2;
        if (gCurrentPinballGame->unk604 < 15)
        {
            gCurrentPinballGame->unk604++;
        }
        else
        {
            gMain.unk44[36]->available = 0;
            gCurrentPinballGame->unk602++;
            gCurrentPinballGame->unk604 = 0;
            gCurrentPinballGame->unk603 = 0;
        }

        group = gMain.unk44[36];
        group->baseX = 96 - gCurrentPinballGame->unk58;
        group->baseY = 300 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4F6A[var0][i * 3 + 0];
            *dst++ = gUnknown_086B4F6A[var0][i * 3 + 1];
            *dst++ = gUnknown_086B4F6A[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 5:
        gCurrentPinballGame->unkE4 = 7;
        DmaCopy16(3, gUnknown_083A340C, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gUnknown_083A542C, (void *)0x050003C0, 0x20);
        gCurrentPinballGame->unk602++;
        sub_29924();
        m4aSongNumStart(SE_UNKNOWN_0x8E);
        break;
    case 6:
        gMain.blendBrightness = 0;
        gMain.blendControl = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8) | 0xA0;
        if (gCurrentPinballGame->unk604 < 73)
        {
            s16 var1;
            if (gCurrentPinballGame->unk604 < 8)
            {
                gMain.blendBrightness = 16;
            }
            else
            {
                for (i = 0; i < 6; i++)
                    gCurrentPinballGame->unk6D3[i] = 13;

                gMain.blendBrightness = ((8 - gCurrentPinballGame->unk604) / 4) + 16;
            }
        }

        if (gCurrentPinballGame->unk604 < 72)
        {
            gCurrentPinballGame->unk604++;
        }
        else
        {
            gCurrentPinballGame->unk602++;
            gCurrentPinballGame->unk604 = 0;
            gCurrentPinballGame->unk603 = 0;
        }

        if (gCurrentPinballGame->unk604 > 8U)
        {
            if (gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer < 0x7000)
                sub_29A6C();
        }
        break;
    case 7:
        gCurrentPinballGame->unkE4 = 8;
        DmaCopy16(3, gUnknown_083A562C, (void *)0x06015800, 0x1800);
        DmaCopy16(3, gUnknown_083A6E4C, (void *)0x050003C0, 0x20);
        gMain.unk44[37]->available = 1;
        gCurrentPinballGame->unk602++;
        gCurrentPinballGame->unk1100 = 0;
        break;
    case 8:
        if (gUnknown_086AE0D0[gCurrentPinballGame->unk603] > gCurrentPinballGame->unk604)
        {
            gCurrentPinballGame->unk604++;
        }
        else
        {
            gCurrentPinballGame->unk604 = 0;
            gCurrentPinballGame->unk603++;
            if (gCurrentPinballGame->unk603 > 10)
            {
                gCurrentPinballGame->unk17++;
                gMain.unk44[37]->available = 0;
                gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                gMain.blendControl = 0xCE;
                gMain.blendBrightness = 0;
                gMain.unk44[37]->available = 0;
                gCurrentPinballGame->unk603 = 10;
                gCurrentPinballGame->unkE4 = 0;
            }
        }

        var0 = gCurrentPinballGame->unk603;
        group = gMain.unk44[37];
        group->baseX = 96 - gCurrentPinballGame->unk58;
        group->baseY = 300 - gCurrentPinballGame->unk5A;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4E62[var0][i * 3 + 0];
            *dst++ = gUnknown_086B4E62[var0][i * 3 + 1];
            *dst++ = gUnknown_086B4E62[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    }
}

void sub_25F64(void)
{
    s16 i;

    gCurrentPinballGame->unk17 = 1;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk6DB = 3;
    gCurrentPinballGame->unk36 = 0;
    gCurrentPinballGame->unk32 = (Random() + gMain.systemFrameCount) % 6;
    gCurrentPinballGame->area = gUnknown_08055A68[gMain.selectedField][gCurrentPinballGame->unk32];
    gCurrentPinballGame->unk6D9[1] = gUnknown_08137928[gCurrentPinballGame->area];
    gCurrentPinballGame->area = gUnknown_08055A68[gMain.selectedField][(gCurrentPinballGame->unk32 + 1) % 6];
    gCurrentPinballGame->unk6D9[0] = gUnknown_08137928[gCurrentPinballGame->area];
    sub_1C7F4(0, 0);
    sub_1C7F4(0, 1);
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->unk6D3[i] = 13;

    DmaCopy16(3, gUnknown_083A8AAC, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gUnknown_084FA20C, (void *)0x06015800, 0x280);
    gCurrentPinballGame->unkE4 = 12;
}

void sub_260B8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    switch (gCurrentPinballGame->unk17)
    {
    case 1:
        gMain.blendControl = 0x1C10;
        gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unk6E0 = 0;
        gCurrentPinballGame->unk5FE = 0;
        gCurrentPinballGame->unk5FB = 1;
        gMain.unk44[20]->available = 1;
        gMain.unk44[21]->available = 1;
        gMain.unk44[23]->available = 1;
        gMain.unk44[22]->available = 1;
        gMain.unk44[19]->available = 1;
        gCurrentPinballGame->unk6F0 = 30;
        gCurrentPinballGame->unk6F2 = 30;
        gCurrentPinballGame->unk6F4 = 0;
        if (gMain.selectedField == FIELD_RUBY)
        {
            gCurrentPinballGame->unk170[0] = 10;
            gCurrentPinballGame->unk170[1] = 10;
            gCurrentPinballGame->unk170[2] = 10;
        }
        else
        {
            gCurrentPinballGame->unk170[0] = 0;
            gCurrentPinballGame->unk170[1] = 0;
            gCurrentPinballGame->unk170[2] = 0;
        }
        gCurrentPinballGame->rubyPondChangeTimer = 0;
        break;
    case 2:
        if (gCurrentPinballGame->unk5FC == 0)
        {
            gCurrentPinballGame->unk17++;
            gCurrentPinballGame->unk18 = 0;
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 143)
                gCurrentPinballGame->unk170[0] = gUnknown_08137944[gCurrentPinballGame->rubyPondChangeTimer / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 18 && gCurrentPinballGame->rubyPondChangeTimer < 161)
                gCurrentPinballGame->unk170[2] = gUnknown_08137944[(gCurrentPinballGame->rubyPondChangeTimer - 18) / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 36 && gCurrentPinballGame->rubyPondChangeTimer < 179)
                gCurrentPinballGame->unk170[1] = gUnknown_08137944[(gCurrentPinballGame->rubyPondChangeTimer - 36) / 8];

            gCurrentPinballGame->rubyPondChangeTimer++;
        }

        gCurrentPinballGame->unk6E0 = (gCurrentPinballGame->unk6F0 * 32) / gCurrentPinballGame->unk6F2;
        gCurrentPinballGame->unk6C4 = 1;
        gCurrentPinballGame->unk18++;
        sub_26778();
        break;
    case 3:
        if (gCurrentPinballGame->unk18 < 15)
        {
            gCurrentPinballGame->unk18++;
            if (gCurrentPinballGame->unk18 == 15)
            {
                gCurrentPinballGame->unk17++;
                gCurrentPinballGame->unk6F2 = 6;
                gCurrentPinballGame->unk6F4 = 0;
            }
        }
        sub_26820(0);
        /* fallthrough */
    case 4:
    case 5:
        if (gCurrentPinballGame->unk17 == 3)
        {
            gCurrentPinballGame->unk6F0--;
            gCurrentPinballGame->unk6F0 %= gCurrentPinballGame->unk6F2;
        }
        else if (gCurrentPinballGame->unk17 == 4)
        {
            gCurrentPinballGame->unk6F0++;
            if (gCurrentPinballGame->newButtonActions[1] && gCurrentPinballGame->unk17 == 4)
            {
                if (gCurrentPinballGame->unk6F4 == 0)
                {
                    if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
                        gCurrentPinballGame->unk6F4 = 48;
                    else
                        gCurrentPinballGame->unk6F4 = 1;

                    gCurrentPinballGame->unk6F6 = gCurrentPinballGame->unk6F4;
                    gCurrentPinballGame->unk163 = 1;
                    gCurrentPinballGame->unk21 = 1;
                    gCurrentPinballGame->unk724 = 3600;
                    gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE;
                }
            }

            if (gCurrentPinballGame->unk6F4)
            {
                gCurrentPinballGame->unk6F4--;
                if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
                {
                    gCurrentPinballGame->numCompletedBonusStages = 4;
                    if (gCurrentPinballGame->unk6F4 < 24)
                    {
                        gCurrentPinballGame->unk6F4 = 24;
                        if (gCurrentPinballGame->unk32 == 6)
                            gCurrentPinballGame->unk6F4 = 0;
                    }
                }

                if (gCurrentPinballGame->unk6F4 == 0)
                {
                    gCurrentPinballGame->unk17 = 5;
                }
                else
                {
                    if (gCurrentPinballGame->unk6F0 == gCurrentPinballGame->unk6F2)
                    {
                        gCurrentPinballGame->unk6F2 = 40 - (gCurrentPinballGame->unk6F4 * 30) / gCurrentPinballGame->unk6F6;
                        gCurrentPinballGame->unk6F0 = 0;
                    }
                }
            }

            gCurrentPinballGame->unk6F0 %= gCurrentPinballGame->unk6F2;
        }
        else
        {
            gCurrentPinballGame->unk6F0++;
            gCurrentPinballGame->unk6F0 %= gCurrentPinballGame->unk6F2;
            if (gCurrentPinballGame->unk6F0 == 0)
            {
                gCurrentPinballGame->unk18 = 0;
                gCurrentPinballGame->unk17++;
                gMain.unk44[23]->available = 0;
                gMain.unk44[20]->available = 0;
                gMain.unk44[21]->available = 0;
                gMain.unk44[34]->available = 1;
                m4aSongNumStart(SE_UNKNOWN_0x93);
            }
        }

        gCurrentPinballGame->unk6E0 = (gCurrentPinballGame->unk6F0 * 32) / gCurrentPinballGame->unk6F2;
        if (gCurrentPinballGame->unk6F0 == 0)
        {
            gCurrentPinballGame->unk6D9[0] = gCurrentPinballGame->unk6D9[1];
            sub_1C7F4(0, 0);
        }

        if (gCurrentPinballGame->unk6F0 == 1)
        {
            if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
            {
                gCurrentPinballGame->unk32 = (gCurrentPinballGame->unk32 + 1) % 7;
                gCurrentPinballGame->unk33 = 0;
                gCurrentPinballGame->unk34 = 1;
            }
            else
            {
                gCurrentPinballGame->unk32 = (gCurrentPinballGame->unk32 + 1) % 6;
                gCurrentPinballGame->unk33 = (gCurrentPinballGame->unk32 + 1) % 6;
                gCurrentPinballGame->unk34 = (gCurrentPinballGame->unk32 + 2) % 6;
            }

            gCurrentPinballGame->area = gUnknown_08055A68[gMain.selectedField][gCurrentPinballGame->unk32];
            gCurrentPinballGame->unk6D9[1] = gUnknown_08137928[gCurrentPinballGame->area];
            sub_1C7F4(0, 1);
            m4aSongNumStart(SE_UNKNOWN_0x81);
        }
        break;
    case 6:
        if (gCurrentPinballGame->unk18 < 50)
        {
            gCurrentPinballGame->unk18++;
            if (gCurrentPinballGame->unk18 == 50)
            {
                gCurrentPinballGame->unk17 = 0;
                sub_19B64(1);
            }
        }

        if (gCurrentPinballGame->unk18 < 29)
        {
            if (gCurrentPinballGame->unk18 < 8)
                var0 = gCurrentPinballGame->unk18 / 4;
            else
                var0 = ((gCurrentPinballGame->unk18 - 8) / 3) + 2;

            group = gMain.unk44[34];
            if (group->available)
            {
                group->baseX = 96u - gCurrentPinballGame->unk58;
                group->baseY = gCurrentPinballGame->unk6E0 + 300u - gCurrentPinballGame->unk5A;
                if (group->baseY >= 200)
                    group->baseY = 200;

                for (i = 0; i < 9; i++)
                {
                    oamSimple = &group->oam[i];
                    dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_086B51CE[var0][i * 3 + 0];
                    *dst++ = gUnknown_086B51CE[var0][i * 3 + 1];
                    *dst++ = gUnknown_086B51CE[var0][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                    gOamBuffer[oamSimple->oamId].y += group->baseY;
                }
            }

            if (gCurrentPinballGame->unk18 == 0x1C) {
                gMain.unk44[34]->available = 0;
                gCurrentPinballGame->unkE4 = 0;
            }
        }

        gCurrentPinballGame->unk6C4 = 0;
        break;
    }
}

void sub_26778(void)
{
    s16 index;

    index = (gMain.systemFrameCount % 100) / 10;
    gCurrentPinballGame->unk70C = 0;
    gCurrentPinballGame->unk72F = gUnknown_08137AB8[index];
    gCurrentPinballGame->unk72E = gUnknown_08137AB8[index];
    gCurrentPinballGame->unk72B = gUnknown_08137AB8[index];
    if (index == 7 || index == 9)
    {
        gCurrentPinballGame->unk728 = 1;
        gCurrentPinballGame->unk72A = 1;
        gCurrentPinballGame->unk729 = 1;
    }
    else
    {
        gCurrentPinballGame->unk728 = 0;
        gCurrentPinballGame->unk72A = 0;
        gCurrentPinballGame->unk729 = 0;
    }
}

void sub_26820(s16 arg0)
{
    if (arg0)
    {
        gCurrentPinballGame->unk72A = 1;
        gCurrentPinballGame->unk728 = 1;
        gCurrentPinballGame->unk731 = 1;
        gCurrentPinballGame->unk72E = 3;
        gCurrentPinballGame->unk72B = 3;
        gCurrentPinballGame->unk72F = 3;
        gCurrentPinballGame->unk729 = 1;
    }
    else
    {
        gCurrentPinballGame->unk729 = 0;
        gCurrentPinballGame->unk72A = 0;
        gCurrentPinballGame->unk728 = 0;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72B = 0;
        gCurrentPinballGame->unk72F = 2;
    }

    gCurrentPinballGame->unk70E = 1;
}

void sub_268CC(void)
{
    gCurrentPinballGame->unk6BC = 0;
    gCurrentPinballGame->unk6BD = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->unk2BE = 0;
        gCurrentPinballGame->unk2C2 = 0;
        gCurrentPinballGame->unk2C0 = 0;
    }

    gCurrentPinballGame->unk6BE = 1;
    gCurrentPinballGame->unk6C0 = 0;
    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    gMain.unk44[13]->available = 0;
    gCurrentPinballGame->unk730 = 0;
    gCurrentPinballGame->unk5F3 = 0;
    gCurrentPinballGame->unk739[0] = gCurrentPinballGame->unk736[0] = 0;
    gCurrentPinballGame->unk739[1] = gCurrentPinballGame->unk736[1] = 0;
    gCurrentPinballGame->unk739[2] = gCurrentPinballGame->unk736[2] = 0;
    sub_4D648();
}

void sub_269A4(void)
{
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk294 = 2;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 3600;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk724 = 1800;
    DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
}

void sub_26A10(void)
{
    s16 var0;

    if (gCurrentPinballGame->unk294 && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->unk17 < 6)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->unk18 = 200;
        gCurrentPinballGame->unk17 = 6;
    }

    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            gCurrentPinballGame->unk17++;
            gCurrentPinballGame->unk708 = 0;
        }
        gCurrentPinballGame->unk6BC = 0;
        break;
    case 1:
        sub_1C7F4(4, 0);
        if (gCurrentPinballGame->unk18 == 35)
            m4aSongNumStart(MUS_TRAVEL_MODE);

        if (gCurrentPinballGame->unk6BC)
        {
            gCurrentPinballGame->unk17++;
            if (gCurrentPinballGame->unk18 < 35)
                m4aSongNumStart(MUS_TRAVEL_MODE);

            gCurrentPinballGame->unk6BD = 0;
            gCurrentPinballGame->unk6BE = 1;
            gCurrentPinballGame->unk6C0 = 0;
        }

        var0 = (gCurrentPinballGame->unk18 % 40) / 10;
        gCurrentPinballGame->unk18++;
        if (var0 == 0)
        {
            gCurrentPinballGame->unk736[0] = 0;
            gCurrentPinballGame->unk736[1] = 0;
            gCurrentPinballGame->unk736[2] = 0;
        }
        else if (var0 == 1)
        {
            gCurrentPinballGame->unk736[0] = 3;
            gCurrentPinballGame->unk736[1] = 1;
            gCurrentPinballGame->unk736[2] = 0;
        }
        else if (var0 == 2)
        {
            gCurrentPinballGame->unk736[0] = 3;
            gCurrentPinballGame->unk736[1] = 3;
            gCurrentPinballGame->unk736[2] = 2;
        }
        else
        {
            gCurrentPinballGame->unk736[0] = 3;
            gCurrentPinballGame->unk736[1] = 3;
            gCurrentPinballGame->unk736[2] = 3;
        }

        gCurrentPinballGame->unk739[0] = gCurrentPinballGame->unk736[0];
        gCurrentPinballGame->unk739[1] = gCurrentPinballGame->unk736[1];
        gCurrentPinballGame->unk739[2] = gCurrentPinballGame->unk736[2];
        break;
    case 2:
        sub_219A8();
        gCurrentPinballGame->unk730 = 2;
        sub_1C7F4(0, 0);
        gCurrentPinballGame->unk739[0] = gCurrentPinballGame->unk736[0] = 0;
        gCurrentPinballGame->unk739[1] = gCurrentPinballGame->unk736[1] = 0;
        gCurrentPinballGame->unk739[2] = gCurrentPinballGame->unk736[2] = 0;
        gCurrentPinballGame->unk17++;
        break;
    case 3:
        sub_219EC();
        if (gCurrentPinballGame->unk25 == 4)
            gCurrentPinballGame->unk17++;
        break;
    case 4:
        gCurrentPinballGame->unk294 = 3;
        gCurrentPinballGame->unk17++;
        gCurrentPinballGame->unk18 = 0;
        gCurrentPinballGame->unk708 = 0;
        gCurrentPinballGame->unk6EC[0] = 47;
        sub_1C7F4(7, 0);
        break;
    case 5:
        if (gCurrentPinballGame->unk28 == 145)
        {
            gCurrentPinballGame->unk28++;
            gCurrentPinballGame->unk6EC[0] = 47;
            sub_1C7F4(7, 0);
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->unk28 = 144;
                m4aMPlayAllStop();
                sub_1C7F4(0, 0);
                if (gCurrentPinballGame->unk36 < 5)
                {
                    var0 = gCurrentPinballGame->unk34;
                    if (gCurrentPinballGame->unk6BC == 1)
                        gCurrentPinballGame->unk32 = gCurrentPinballGame->unk33;
                    else
                        gCurrentPinballGame->unk32 = gCurrentPinballGame->unk34;

                    gCurrentPinballGame->unk33 = (var0 + 1) % 6;
                    gCurrentPinballGame->unk34 = (var0 + 2) % 6;
                    gCurrentPinballGame->unk36++;
                }
                else
                {
                    gCurrentPinballGame->unk32 = 6;
                    gCurrentPinballGame->unk36 = 0;
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                m4aMPlayAllStop();
                m4aSongNumStart(SE_MENU_CANCEL);
                gCurrentPinballGame->unk28 = 60;
                gCurrentPinballGame->unk17 = 6;
                if (gCurrentPinballGame->unk714)
                    gCurrentPinballGame->unk6EE = 120;
            }
        }

        if (gCurrentPinballGame->unk28 == 130)
        {
            gCurrentPinballGame->unk28++;
            if (gCurrentPinballGame->unk18 < 490)
            {
                sub_2E094();
                if (gCurrentPinballGame->scoreCounterAnimationEnabled && gCurrentPinballGame->unk18 >= 428)
                    gCurrentPinballGame->unk18 = 428;

                if (gCurrentPinballGame->unk18 == 394)
                {
                    gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                    gCurrentPinballGame->scoreAddedInFrame = 500000;
                }
            }
            else
            {
                gCurrentPinballGame->unk28 = 120;
            }

            gCurrentPinballGame->unk18++;
        }
        else if (gCurrentPinballGame->unk28 == 0)
        {
            gCurrentPinballGame->unk17++;
            gCurrentPinballGame->unk18 = 0;
            if (gCurrentPinballGame->unk62C < 99)
                gCurrentPinballGame->unk62C++;
        }
        break;
    case 6:
        sub_219EC();
        gMain.unk44[13]->available = 0;
        sub_268CC();
        gCurrentPinballGame->unk17++;
        break;
    case 7:
        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk18--;
        }
        else
        {
            sub_19B64(1);
            gCurrentPinballGame->unk17 = 0;
        }
        break;
    }
}

void sub_26EA4(void)
{
    s16 i;

    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->unk723)
            gCurrentPinballGame->unk71D[i] = 1;
        else
            gCurrentPinballGame->unk71D[i] = 0;
    }

    gMain.unk44[13]->available = 0;
    gCurrentPinballGame->unk730 = 0;
    gCurrentPinballGame->unk5F3 = 0;
    sub_4D648();
}

void sub_26F38(void)
{
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk294 = 2;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 7200;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk724 = 3600;
    if (gCurrentPinballGame->currentSpecies == SPECIES_WURMPLE)
    {
        gCurrentPinballGame->unk25F = 0;
    }
    else if (gCurrentPinballGame->currentSpecies == SPECIES_GLOOM)
    {
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->unk25F = 1;
        else
            gCurrentPinballGame->unk25F = 7;
    }
    else if (gCurrentPinballGame->currentSpecies == SPECIES_CLAMPERL)
    {
        gCurrentPinballGame->unk25F = 3;
    }
    else
    {
        gCurrentPinballGame->unk25F = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionMethod - 1;
        if (gCurrentPinballGame->unk25F < 0)
            gCurrentPinballGame->unk25F = 0;
    }

    DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
    gCurrentPinballGame->unk72E = 0;
    gCurrentPinballGame->unk72A = 0;
    gCurrentPinballGame->unk252 = 0;
    gCurrentPinballGame->unk25E = 0;
    gCurrentPinballGame->unk26B = 0;
    gCurrentPinballGame->unk26C = 0;
    gCurrentPinballGame->unk26E = 0;
    sub_1C7F4(3, 0);
}

void sub_27080(void)
{
    s16 i, j;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    if (gCurrentPinballGame->unk294 && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->unk17 < 8)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->unk18 = 200;
        gCurrentPinballGame->unk17 = 8;
    }

    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        if (gCurrentPinballGame->unk250 < 2)
        {
            for (i = 0; i < 8; i++)
                gCurrentPinballGame->unk263[i] = i;

            index = (Random() + gMain.systemFrameCount) % 5;
            gCurrentPinballGame->unk260[0] = gCurrentPinballGame->unk263[index];
            for (i = index; i < 7; i++)
                gCurrentPinballGame->unk263[i] = gCurrentPinballGame->unk263[i + 1];

            index = (Random() + gMain.systemFrameCount) % 4;
            gCurrentPinballGame->unk260[1] = gCurrentPinballGame->unk263[index];
            for (i = index; i < 6; i++)
                gCurrentPinballGame->unk263[i] = gCurrentPinballGame->unk263[i + 1];

            index = (Random() + gMain.systemFrameCount) % 3;
            gCurrentPinballGame->unk260[2] = gCurrentPinballGame->unk263[index];
        }
        else
        {
            for (i = 0; i < 8; i++)
                gCurrentPinballGame->unk263[i] = i;

            index = (Random() + gMain.systemFrameCount) % 6;
            gCurrentPinballGame->unk260[0] = gCurrentPinballGame->unk263[index];
            for (i = index; i < 7; i++)
                gCurrentPinballGame->unk263[i] = gCurrentPinballGame->unk263[i + 1];

            index = (Random() + gMain.systemFrameCount) % 7;
            gCurrentPinballGame->unk260[1] = gCurrentPinballGame->unk263[index];
            for (i = index; i < 6; i++)
                gCurrentPinballGame->unk263[i] = gCurrentPinballGame->unk263[i + 1];

            index = (Random() + gMain.systemFrameCount) % 6;
            gCurrentPinballGame->unk260[2] = gCurrentPinballGame->unk263[index];
            for (i = index; i < 5; i++)
                gCurrentPinballGame->unk263[i] = gCurrentPinballGame->unk263[i + 1];

            if (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->numCompletedBonusStages < 5)
            {
                for (i = 0; i < 3; i++)
                {
                    if (gCurrentPinballGame->unk260[i] == 5)
                    {
                        index = (Random() + gMain.systemFrameCount) % 5;
                        gCurrentPinballGame->unk260[i] = gCurrentPinballGame->unk263[index];
                    }
                }
            }
        }

        gCurrentPinballGame->unk250++;
        gCurrentPinballGame->unk17++;
        break;
    case 1:
        gCurrentPinballGame->unk25E = gCurrentPinballGame->unk260[gCurrentPinballGame->unk26B];
        gCurrentPinballGame->unk258 = gUnknown_086ACFA0[gMain.selectedField][gCurrentPinballGame->unk25E].x;
        gCurrentPinballGame->unk25A = gUnknown_086ACFA0[gMain.selectedField][gCurrentPinballGame->unk25E].y;
        gCurrentPinballGame->unk26E = 80;
        gMain.unk44[40]->available = 1;
        gCurrentPinballGame->unk17++;
        break;
    case 2:
        sub_278F4();
        gCurrentPinballGame->unk18 = 0;
        break;
    case 3:
        gCurrentPinballGame->unk730 = 1;
        if (gCurrentPinballGame->unk18 < 8)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            sub_219A8();
            gCurrentPinballGame->unk730 = 2;
            gCurrentPinballGame->unk17++;
        }
        break;
    case 4:
        sub_219EC();
        if (gCurrentPinballGame->unk25 == 4)
            gCurrentPinballGame->unk17++;
        break;
    case 5:
        gCurrentPinballGame->unk294 = 3;
        gCurrentPinballGame->unk5A0 = gCurrentPinballGame->currentSpecies;
        sub_31CF8(1);
        gCurrentPinballGame->unk5A2 = gCurrentPinballGame->currentSpecies;
        gCurrentPinballGame->unk18 = 0;
        gCurrentPinballGame->unk17++;
        break;
    case 6:
        if (gCurrentPinballGame->unk28 == 148)
        {
            gCurrentPinballGame->unk28++;
            if (gMain.spriteGroups[13].available)
            {
                if (gCurrentPinballGame->unk2BC >= 80)
                {
                    sub_2D204();
                    if (gCurrentPinballGame->unk17 == 6)
                        gCurrentPinballGame->unk18++;
                }
            }
            else
            {
                sub_2D204();
                if (gCurrentPinballGame->unk17 == 6)
                    gCurrentPinballGame->unk18++;
            }
        }
        break;
    case 7:
        if (gCurrentPinballGame->unk28 == 148)
        {
            gCurrentPinballGame->unk28++;
            if (gCurrentPinballGame->unk18 < 280)
            {
                if (gCurrentPinballGame->unk18 == 0)
                {
                    sub_2312C();
                    m4aSongNumStart(MUS_SUCCESS2);
                }
                else
                {
                    sub_23300();
                    if (gCurrentPinballGame->unk18 < 230)
                    {
                        if (gCurrentPinballGame->unk210 == 150)
                            gCurrentPinballGame->unk210--;
                    }

                    if (gCurrentPinballGame->unk18 == 270)
                    {
                        sub_1C7F4(0, 0);
                        gCurrentPinballGame->unk6C4 = 0;
                    }

                    if (gCurrentPinballGame->scoreCounterAnimationEnabled)
                        gCurrentPinballGame->unk18 = 181;

                    if (gCurrentPinballGame->unk18 == 180) {
                        gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                        gCurrentPinballGame->scoreAddedInFrame = 5000000;
                    }
                }

                if (gCurrentPinballGame->unk18 < 30)
                {
                    gMain.unk2C = 1;
                    var0 = gCurrentPinballGame->unk18;
                    gCurrentPinballGame->unk298 = gCurrentPinballGame->unk18;
                    for (i = 0; i <= var0; i++)
                    {
                        for (j = 2; j < 12; j++)
                            gUnknown_03005C00[((j + 15) * 0x20) + i] = 0xC100;
                    }

                    DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x800);
                }

                if (gCurrentPinballGame->unk18 >= 240 && gCurrentPinballGame->unk18 < 270)
                {
                    var0 = gCurrentPinballGame->unk18 - 240;
                    for (i = 0; i <= var0; i ++)
                    {
                        for (j = 2; j < 12; j++)
                            gUnknown_03005C00[((j + 15) << 5) + i] = 0x1FF;
                    }

                    DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x800);
                    if (gCurrentPinballGame->unk18 == 269)
                    {
                        gMain.unk2C = 0;
                        gMain.blendControl = 0;
                        gMain.blendBrightness = 0;
                        gMain.blendAlpha = 0;
                    }
                }

                gCurrentPinballGame->unk18++;
            }
            else
            {
                gCurrentPinballGame->unk28 = 40;
            }
        }
        else if (gCurrentPinballGame->unk28 == 24)
        {
            if (gCurrentPinballGame->unk723 < 3)
            {
                gCurrentPinballGame->unk721 = gCurrentPinballGame->unk723;
                gCurrentPinballGame->unk722 = gCurrentPinballGame->unk723;
                gCurrentPinballGame->unk71D[gCurrentPinballGame->unk721] = 1;
                gCurrentPinballGame->unk720 = 120;
                gCurrentPinballGame->unk723++;
                if (gCurrentPinballGame->unk723 < 3)
                {
                    gCurrentPinballGame->unk722 = gCurrentPinballGame->unk723;
                    gCurrentPinballGame->unk71D[gCurrentPinballGame->unk722] = 1;
                    gCurrentPinballGame->unk720 = 120;
                    gCurrentPinballGame->unk723++;
                }
            }

            if (gCurrentPinballGame->currentSpecies == SPECIES_NINJASK)
            {
                gCurrentPinballGame->caughtMonCount++;
                if (gCurrentPinballGame->unk62B < 99)
                    gCurrentPinballGame->unk62B++;

                if (gCurrentPinballGame->caughtMonCount == 15)
                    gCurrentPinballGame->unk286 = 92;
            }

            gCurrentPinballGame->caughtMonCount++;
            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->unk286 = 92;

            if (gCurrentPinballGame->unk62B < 99)
                gCurrentPinballGame->unk62B++;

            gCurrentPinballGame->unk17++;
            gCurrentPinballGame->unk18 = 0;
        }
        break;
    case 8:
        group = gMain.unk44[32];
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset - 56;

        gMain.unk44[32]->available = 0;
        sub_278F4();
        gMain.unk44[40]->available = 0;
        gCurrentPinballGame->unkE4 = 0;
        sub_219EC();
        gMain.unk44[13]->available = 0;
        gCurrentPinballGame->unk1A4 = 1;
        gCurrentPinballGame->unk1B4 = 0;
        gCurrentPinballGame->unk1A5 = 0;
        gCurrentPinballGame->unk17++;
        if (gCurrentPinballGame->unk714)
            gCurrentPinballGame->unk6EE = 120;
        break;
    case 9:
        sub_26EA4();
        gCurrentPinballGame->unk17++;
        break;
    case 10:
        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk18--;
        }
        else
        {
            if (gCurrentPinballGame->unk71D[2] == 1)
                sub_19B64(3);
            else
                sub_19B64(1);

            gCurrentPinballGame->unk17 = 0;
        }
        break;
    }
}

void sub_278F4(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    struct Vector32 tempVector;
    int xx, yy;
    int squaredMagnitude;
    s16 index;

    index = (gMain.systemFrameCount % 75) / 3;
    group = gMain.unk44[32];
    if (gCurrentPinballGame->unk26E)
    {
        group = gMain.unk44[40];
        if (gCurrentPinballGame->unk26E == 80)
        {
            gCurrentPinballGame->unkE4 = 15;
            DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->unk25F], (void *)0x06015800, 0x1C00);
            DmaCopy16(3, &gUnknown_0815C4C4[gCurrentPinballGame->unk25F], (void *)0x050003E0, 0x20);
            gCurrentPinballGame->unk626 = 0;
            gCurrentPinballGame->unk628 = 0;
        }

        if (gCurrentPinballGame->unk26E == 60)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_84);

        if (gUnknown_086AE0E6[gCurrentPinballGame->unk626] > gCurrentPinballGame->unk628)
        {
            gCurrentPinballGame->unk628++;
        }
        else
        {
            gCurrentPinballGame->unk628 = 1;
            gCurrentPinballGame->unk626++;
            if (gCurrentPinballGame->unk626 == 29)
            {
                gCurrentPinballGame->unk626 = 28;
                gCurrentPinballGame->unk26E = 1;
                gMain.unk44[40]->available = 0;
                gMain.unk44[32]->available = 1;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_85);
                gCurrentPinballGame->unkE4 = 0;
            }
        }

        group->baseX = gCurrentPinballGame->unk258 - gCurrentPinballGame->unk58 + 8;
        group->baseY = gCurrentPinballGame->unk25A - gCurrentPinballGame->unk5A + 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->unk626][i * 3 + 0];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->unk626][i * 3 + 1];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->unk626][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        gCurrentPinballGame->unk26E--;
    }
    else
    {
        tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->unk258 + 8);
        tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->unk25A + 8);
        xx = tempVector.x * tempVector.x;
        yy = tempVector.y * tempVector.y;
        squaredMagnitude = xx + yy;
        if (squaredMagnitude < 82 &&
            ((gCurrentPinballGame->unk24 == 0 && gCurrentPinballGame->unk25E <= 5) || (gCurrentPinballGame->unk24 == 2 && gCurrentPinballGame->unk25E > 5)) &&
            gCurrentPinballGame->unk26B < 3)
        {
            gCurrentPinballGame->scoreAddedInFrame = 10000;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_86);
            gCurrentPinballGame->unk17 = 1;
            gCurrentPinballGame->unk71D[gCurrentPinballGame->unk26B] = 5;
            gCurrentPinballGame->unk26B++;
            gMain.unk44[32]->available = 0;
            if (gCurrentPinballGame->unk26B == 3)
            {
                gCurrentPinballGame->unk26B = 0;
                gCurrentPinballGame->unk17 = 3;
            }
        }

        group->baseX = gCurrentPinballGame->unk258 - gCurrentPinballGame->unk58 - 8;
        group->baseY = gCurrentPinballGame->unk25A - gCurrentPinballGame->unk5A - 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        if (index > 14)
            index = 14;

        DmaCopy16(3, gUnknown_086AD49C[gCurrentPinballGame->unk25F] + index * 0x200, (void *)0x060116C0, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_27D44(void)
{
    s16 i;

    gCurrentPinballGame->unk5A5 = 0;
    gCurrentPinballGame->unk5A9 = 0;
    gMain.unk44[18]->available = 0;
    gMain.unk44[12]->available = 0;
    gCurrentPinballGame->unk5F2 = 0;
    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    sub_4D648();
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->unk6D3[i] = 13;

    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->unk723)
            gCurrentPinballGame->unk71D[i] = 1;
        else
            gCurrentPinballGame->unk71D[i] = 0;
    }
}

void sub_27E08(void)
{
    s16 i, j;

    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_CATCH_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk5A5 = 0;
    gCurrentPinballGame->unk5AA = 0;
    gCurrentPinballGame->unk5A9 = 0;
    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
    gCurrentPinballGame->hatchFrameId = 0;
    gCurrentPinballGame->unk72F = 0;
    gCurrentPinballGame->unk731 = 0;

    if (gCurrentPinballGame->unk29A == 0)
    {
        gCurrentPinballGame->unk724 = 6000;
    }
    else
    {
        gCurrentPinballGame->unk724 = 4200;
    }
    gCurrentPinballGame->unk29A++;

    DmaCopy16(3, gUnknown_081C0064, (void *)PLTT + 0x180, 0x20);

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->unk6CD[i] = i;
    }

    gCurrentPinballGame->unk6C8 = gMain.systemFrameCount % 6;
    gCurrentPinballGame->unk6C9 = 5;

    for (j = gCurrentPinballGame->unk6C8; j < gCurrentPinballGame->unk6C9; j++)
    {
        gCurrentPinballGame->unk6CD[j] = gCurrentPinballGame->unk6CD[j+1];
    }
}
