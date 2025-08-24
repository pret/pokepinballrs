#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

extern const u8 gUnknown_081C0064[];
extern const u8 *gUnknown_086AD474[];
extern const u8 gUnknown_0815C4C4[][0x20];
extern const s16 gUnknown_086AE0E6[];
extern const u16 gUnknown_086B4202[][15];
extern const u8 *gUnknown_086AD49C[];
extern const struct Vector16 gUnknown_086ACFA0[][8];
extern const s16 gUnknown_08137AB8[];
extern const s16 gUnknown_08137944[];
extern const s16 gUnknown_08055A68[][7];
extern const s16 gUnknown_08137928[];
extern const u16 gUnknown_086B51CE[][27];

extern struct SongHeader gUnknown_0869F58C;
extern struct SongHeader gUnknown_0869F5C8;
extern struct SongHeader gUnknown_0869F618;

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
        gCurrentPinballGame->unk174 = 0;
        break;
    case 2:
        if (gCurrentPinballGame->unk5FC == 0)
        {
            gCurrentPinballGame->unk17++;
            gCurrentPinballGame->unk18 = 0;
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->unk174 < 143)
                gCurrentPinballGame->unk170[0] = gUnknown_08137944[gCurrentPinballGame->unk174 / 8];

            if (gCurrentPinballGame->unk174 >= 18 && gCurrentPinballGame->unk174 < 161)
                gCurrentPinballGame->unk170[2] = gUnknown_08137944[(gCurrentPinballGame->unk174 - 18) / 8];

            if (gCurrentPinballGame->unk174 >= 36 && gCurrentPinballGame->unk174 < 179)
                gCurrentPinballGame->unk170[1] = gUnknown_08137944[(gCurrentPinballGame->unk174 - 36) / 8];

            gCurrentPinballGame->unk174++;
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
                    gCurrentPinballGame->unk16C = 2;
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
            gCurrentPinballGame->unk6D9 = gCurrentPinballGame->unk6DA;
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
            gCurrentPinballGame->unk6DA = gUnknown_08137928[gCurrentPinballGame->area];
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
        if (gMain.unkF == 0)
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
        gCurrentPinballGame->unk6EC = 47;
        sub_1C7F4(7, 0);
        break;
    case 5:
        if (gCurrentPinballGame->unk28 == 145)
        {
            gCurrentPinballGame->unk28++;
            gCurrentPinballGame->unk6EC = 47;
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
                m4aSongNumStart(SE_UNKNOWN_0x66);
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
                if (gCurrentPinballGame->unk1C && gCurrentPinballGame->unk18 >= 428)
                    gCurrentPinballGame->unk18 = 428;

                if (gCurrentPinballGame->unk18 == 394)
                {
                    gCurrentPinballGame->unk1C = 1;
                    gCurrentPinballGame->unk3C = 500000;
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

                    if (gCurrentPinballGame->unk1C)
                        gCurrentPinballGame->unk18 = 181;

                    if (gCurrentPinballGame->unk18 == 180) {
                        gCurrentPinballGame->unk1C = 1;
                        gCurrentPinballGame->unk3C = 5000000;
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
            DmaCopy16(3, gUnknown_086AD474[gCurrentPinballGame->unk25F], (void *)0x06015800, 0x1C00);
            DmaCopy16(3, &gUnknown_0815C4C4[gCurrentPinballGame->unk25F], (void *)0x050003E0, 0x20);
            gCurrentPinballGame->unk626 = 0;
            gCurrentPinballGame->unk628 = 0;
        }

        if (gCurrentPinballGame->unk26E == 60)
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F58C);

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
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F5C8);
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
            gCurrentPinballGame->unk3C = 10000;
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F618);
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
    gCurrentPinballGame->unk6C6 = 0;
    gCurrentPinballGame->unk6C7 = 0;
    gCurrentPinballGame->unk625 = 0;
    gCurrentPinballGame->unk6CA = 0;
    gCurrentPinballGame->unk6CC = 0;
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
    gCurrentPinballGame->unk29A += 1;

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
