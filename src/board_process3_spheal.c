#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

struct Unk_086AFAC0
{
    struct Vector16 *unk0;
    s16 unk4;
};
extern const struct Unk_086AFAC0 gUnknown_086AFAC0[];

extern const s16 gUnknown_086AFC16[][4];
extern struct SongHeader se_unk_137;
extern struct SongHeader se_unk_138;
extern struct SongHeader se_unk_139;
extern struct SongHeader se_unk_13b;
extern struct SongHeader se_unk_13c;
extern struct SongHeader se_unk_13d;

extern const s8 gUnknown_08137D60[];
extern const u16 gUnknown_0837A4E8[];
extern const u8 gUnknown_084AF9EC[][0x200];
extern const u8 gUnknown_084AFFEC[][0x180];
extern const u8 gUnknown_084B046C[][0x120];
extern const u8 gUnknown_084B47EC[][0x800];
extern const u8 gUnknown_084B77EC[];
extern const u8 gWhiscash_Gfx[][0x480];
extern const u8 gPelliper_Gfx[][0x480];
extern const s16 gUnknown_086AEED6[];
extern const u16 gUnknown_086AFAE0[][2];
extern const u16 gUnknown_086AFAE2[][2];
extern const u16 gUnknown_086AFB2C[][3];
extern const u16 gUnknown_086B56D8[126][4][3];


void SphealBoardProcess_3A_42E48(void)
{
    s16 i;
    s16 frame;

    frame = gMain.systemFrameCount % 16;
    for (i = 0; i < frame; i++)
        Random();

    gMain.rngValue = gMain.systemFrameCount;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 7200;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk388 = 0;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unk1F = 1;
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->unk6 = 0;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->unk53A = 0;
    gCurrentPinballGame->unk542 = 0;
    gCurrentPinballGame->unk544 = 0;
    gCurrentPinballGame->unk54A = 0;
    gCurrentPinballGame->unk394 = 0;
    gCurrentPinballGame->unk590 = 0;
    gCurrentPinballGame->unk591 = 0;
    gCurrentPinballGame->unk592 = 0;
    gCurrentPinballGame->unk594 = 0;
    gCurrentPinballGame->unk596 = 0;
    gCurrentPinballGame->unk7E = 1;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->minionState[i] = 0;
        gCurrentPinballGame->minionFramesetIx[i] = 0;
        gCurrentPinballGame->minionStateTimer[i] = 0;
    }

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->unk530[i] = 0;
        gCurrentPinballGame->unk533[i] = 0;
        gCurrentPinballGame->unk536[i] = 0;
        gCurrentPinballGame->unk53C[i] = 0;
    }

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->unk52C[i] = 0;
        gCurrentPinballGame->unk52E[i] = 0;
        gCurrentPinballGame->unk548[i] = 0;
        gCurrentPinballGame->unk54B[i] = 0;
        gCurrentPinballGame->unk54D[i] = 0;
        gCurrentPinballGame->unk54F[i] = 0;
        gCurrentPinballGame->unk551[i] = 0;
        gCurrentPinballGame->unk553[i] = 0;
        gCurrentPinballGame->unk555[i] = 0;
        gCurrentPinballGame->unk557[i] = 0;
        gCurrentPinballGame->unk559[i] = 0;
        gCurrentPinballGame->unk55B[i] = 0;
        gCurrentPinballGame->unk55D[i] = 0;
        gCurrentPinballGame->unk55F[i] = 0;
        gCurrentPinballGame->unk562[i] = 0;
        gCurrentPinballGame->unk566[i] = 0;
        gCurrentPinballGame->unk56A[i] = 0;
        gCurrentPinballGame->unk570[i].x = 0;
        gCurrentPinballGame->unk570[i].y = 0;
        gCurrentPinballGame->unk578[i].x = 0;
        gCurrentPinballGame->unk578[i].y = 0;
        gCurrentPinballGame->unk580[i].x = 0;
        gCurrentPinballGame->unk580[i].y = 0;
    }

    gCurrentPinballGame->unk1A = 0;
    sub_4387C();
    sub_43500();
    sub_44D58();
    sub_45E08();

    for (i = 0; i < 0x800; i++)
        gUnknown_03005C00[0x400 + i] = 0x200;

    DmaCopy16(3, &gUnknown_03005C00[0x400], (void *)0x06001000, 0x1000);

    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        u16 var0 = i - ((i / 0x20) * 0x20) - 2;
        if (var0 < 28)
           gUnknown_03005C00[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gUnknown_03005C00[0x800], (void *)0x06001140, 0x280);
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
    m4aSongNumStart(MUS_BONUS_FIELD_SPHEAL);
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void SphealBoardProcess_3B_43228(void)
{
    switch (gCurrentPinballGame->unk13)
    {
    case 0:
        gCurrentPinballGame->unk5F7 = 1;
        if (gCurrentPinballGame->unk18 < 340)
        {
            if (gCurrentPinballGame->unk18 < 321)
                gCurrentPinballGame->unkE6 = (gCurrentPinballGame->unk18 / 5) + 0xFFC0;

            if (gCurrentPinballGame->unk18 == 325)
                gCurrentPinballGame->unk294 = 2;

            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unkE6 = 0;
            gCurrentPinballGame->unk13 = 1;
            gCurrentPinballGame->unk18 = 0;
        }
        break;
    case 1:
        if (gCurrentPinballGame->eventTimer == 0)
        {
            gCurrentPinballGame->unk294 = 3;
            if (gCurrentPinballGame->unk18 == 0)
            {
                m4aMPlayAllStop();
                MPlayStart(&gMPlayInfo_SE1, &se_unk_13b);
                gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
                gCurrentPinballGame->unk388 = 2;
                gCurrentPinballGame->unk392 = 0;
            }

            if (gCurrentPinballGame->unk18 < 60)
            {
                gCurrentPinballGame->unk18++;
            }
            else
            {
                gCurrentPinballGame->unk13 = 2;
                gCurrentPinballGame->unk18 = 0;
            }
        }
        break;
    case 2:
        if (gCurrentPinballGame->unk18 == 0)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_SUCCESS3);
        }

        if (gCurrentPinballGame->unk18 < 20)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk13 = 3;
            gCurrentPinballGame->unk18 = 0;
            gMain.spriteGroups[7].available = 1;
            gMain.spriteGroups[8].available = 1;
            gMain.spriteGroups[9].available = 1;
            gMain.spriteGroups[10].available = 1;
            DmaCopy16(3, gUnknown_084B77EC, (void *)0x06015800, 0x800);
            gCurrentPinballGame->unk394 = -126;
            gCurrentPinballGame->unk5FA = 1;
        }
        break;
    case 3:
        sub_45E90();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->unk18 = 181;

        if (gCurrentPinballGame->unk18 == 180 && gCurrentPinballGame->unk544 != 0)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = gCurrentPinballGame->unk544;
        }

        if (gCurrentPinballGame->unk18 > 189 && JOY_NEW(A_BUTTON))
            gCurrentPinballGame->unk18 = 540;

        if (gCurrentPinballGame->unk18 < 540)
        {
            if (gCurrentPinballGame->unk18 == 4)
                m4aSongNumStart(SE_UNKNOWN_0xA4);

            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk13 = 4;
        }

        gCurrentPinballGame->unk5FA = 1;
        break;
    case 4:
        sub_45E90();
        if (gCurrentPinballGame->unk18 < 30)
        {
            gCurrentPinballGame->unk18++;
            if (gCurrentPinballGame->unk18 == 2)
                m4aSongNumStart(SE_UNKNOWN_0xA4);
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk13 = 5;
        }
        break;
    case 5:
        sub_45E90();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        gCurrentPinballGame->unk5FA = 1;
        break;
    }

    sub_4387C();
    sub_43500();
    sub_44D58();
    sub_45E08();
    if (gCurrentPinballGame->returnToMainBoardFlag)
    {
        gCurrentPinballGame->unk5FA = 1;
        FadeToMainBoard();
    }

    BonusStage_HandleModeChangeFlags();
}

void sub_43500(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->unk13 < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        sub_455D0();

    if (gCurrentPinballGame->unk13 < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            if (gCurrentPinballGame->unk548[i] == 23)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_13c);
                gCurrentPinballGame->scoreAddedInFrame = 5000;
                PlayRumble(8);
            }

            switch (gCurrentPinballGame->minionState[i])
            {
            case 0:
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionFramesetIx[i] = 4;
                gCurrentPinballGame->minionState[i] = 1;
                break;
            case 1:
                if (gCurrentPinballGame->unk548[i] > 0)
                {
                    gCurrentPinballGame->unk548[i]--;
                }
                else
                {
                    if (gUnknown_086AFAE2[gCurrentPinballGame->minionFramesetIx[i]][0] > gCurrentPinballGame->minionStateTimer[i])
                    {
                        gCurrentPinballGame->minionStateTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->minionStateTimer[i] = 0;
                        gCurrentPinballGame->minionFramesetIx[i]++;
                        if (gCurrentPinballGame->minionFramesetIx[i] == 6)
                            gCurrentPinballGame->minionFramesetIx[i] = 4;
                    }
                }
                break;
            case 2:
                if (gCurrentPinballGame->unk548[i] > 0)
                {
                    gCurrentPinballGame->unk548[i]--;
                }
                else
                {
                    if (gCurrentPinballGame->minionStateTimer[i] != 0)
                    {
                        gCurrentPinballGame->minionStateTimer[i]--;
                        gCurrentPinballGame->minionFramesetIx[i] = 8;
                    }
                    else
                    {
                        gCurrentPinballGame->minionFramesetIx[i] = 7;
                    }
                }
                break;
            case 3:
                if (gCurrentPinballGame->unk548[i] > 0)
                {
                    gCurrentPinballGame->unk548[i]--;
                }
                else
                {
                    if (gUnknown_086AFAE2[gCurrentPinballGame->minionFramesetIx[i]][0] > gCurrentPinballGame->minionStateTimer[i])
                    {
                        gCurrentPinballGame->minionStateTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->minionStateTimer[i] = 0;
                        gCurrentPinballGame->minionFramesetIx[i]++;
                        if (gCurrentPinballGame->minionFramesetIx[i] > 14)
                        {
                            gCurrentPinballGame->minionFramesetIx[i] = 4;
                            gCurrentPinballGame->minionState[i] = 1;
                        }
                    }
                }
                break;
            }
        }
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        group->baseX = 100 - gCurrentPinballGame->unk58;
        group->baseY = 94 - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk548[0] > 0)
            var0 = 0;
        else
            var0 = gUnknown_086AFAE0[gCurrentPinballGame->minionFramesetIx[0]][0];

        DmaCopy16(3, gUnknown_084B47EC[var0], (void *)0x060114A0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[21];
    if (group->available)
    {
        group->baseX = 140 - gCurrentPinballGame->unk58;
        group->baseY = 94 - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk548[1] > 0)
            var0 = 0;
        else
            var0 = gUnknown_086AFAE0[gCurrentPinballGame->minionFramesetIx[1]][0];

        DmaCopy16(3, gUnknown_084B47EC[var0], (void *)0x06010CA0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_4387C(void)
{
    s16 i;
    s16 j;
    s16 var1;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 sp4;
    s16 var2;
    u16 *dst;
    const u16 *src;
    int var3;
    s16 var4;
    const struct Unk_086AFAC0 *var5;

    if (gCurrentPinballGame->unk13 == 1 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            switch (gCurrentPinballGame->unk553[i])
            {
            case 0:
                gCurrentPinballGame->unk553[i] = 1;
                gCurrentPinballGame->unk55B[i] = 0;
                gCurrentPinballGame->unk562[i] = 0;
                gCurrentPinballGame->unk54F[i] = 0;
                gCurrentPinballGame->unk557[i] = -1;
                break;
            case 1:
                if (gCurrentPinballGame->unk562[i] < i * 30 + 120)
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    u16 var0 = gMain.systemFrameCount + Random();
                    gCurrentPinballGame->unk557[i] = var0 % 6;
                    if (gCurrentPinballGame->unk557[0] == gCurrentPinballGame->unk557[1])
                        gCurrentPinballGame->unk557[i] = (gCurrentPinballGame->unk557[i] + 2) % 6;

                    if (gCurrentPinballGame->unk557[i] < 2)
                    {
                        if (gCurrentPinballGame->unk557[i] == 0)
                        {
                            gCurrentPinballGame->unk580[i].x = 0x4900;
                            gCurrentPinballGame->unk580[i].y = 0xAB00;
                            gCurrentPinballGame->unk551[i] = 0;
                        }
                        else
                        {
                            gCurrentPinballGame->unk580[i].x = 0xA700;
                            gCurrentPinballGame->unk580[i].y = 0xAC00;
                            gCurrentPinballGame->unk551[i] = 1;
                        }

                        gCurrentPinballGame->unk55B[i] = 9;
                        gCurrentPinballGame->unk553[i] = 7;
                    }
                    else
                    {
                        gCurrentPinballGame->unk551[i] = (gMain.systemFrameCount + Random()) % 2;
                        if (gCurrentPinballGame->unk551[i])
                        {
                            if (gCurrentPinballGame->unk557[i] == 5)
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 5) + 80) << 8;
                            else
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 2) + 50) << 8;
                        }
                        else
                        {
                            if (gCurrentPinballGame->unk557[i] == 5)
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 5) + 140) << 8;
                            else
                                gCurrentPinballGame->unk580[i].x = (((Random() % 101) / 2) + 140) << 8;
                        }

                        gCurrentPinballGame->unk580[i].y = 0xAF00 + ((gCurrentPinballGame->unk557[i] - 2) * 0xA00);

                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk553[i] = 2;
                    }

                    gCurrentPinballGame->unk562[i] = 0;
                }

                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 2:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 3)
                    {
                        gCurrentPinballGame->unk55B[i] = 3;
                        gCurrentPinballGame->unk553[i] = 3;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 1)
                        m4aSongNumStart(SE_UNKNOWN_0x134);
                }

                gCurrentPinballGame->unk56A[i] = 0;
                gCurrentPinballGame->unk54F[i] = 1;
                break;
            case 3:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 5)
                        gCurrentPinballGame->unk55B[i] = 3;
                }

                if (gCurrentPinballGame->unk56A[i] < 400)
                {
                    gCurrentPinballGame->unk56A[i]++;
                    if (gCurrentPinballGame->unk551[i])
                        gCurrentPinballGame->unk580[i].x += 35;
                    else
                        gCurrentPinballGame->unk580[i].x -= 35;
                }
                else
                {
                    gCurrentPinballGame->unk55B[i] = 6;
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk553[i] = 6;
                }

                gCurrentPinballGame->unk54F[i] = 1;
                break;
            case 4:
                MPlayStart(&gMPlayInfo_SE1, &se_unk_137);
                if (gCurrentPinballGame->unk54F[i] == 1)
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i] = 5;
                    gCurrentPinballGame->unk553[i] = 5;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].y + (gCurrentPinballGame->unk55F[i] << 8) < gCurrentPinballGame->ball->positionQ8.y)
                    {
                        gCurrentPinballGame->unk553[i] = 10;
                    }
                    else
                    {
                        gCurrentPinballGame->unk562[i] = 0xAC - (gCurrentPinballGame->unk562[i] * 12) / 0xA0;
                        gCurrentPinballGame->unk553[i] = 8;
                    }
                }

                PlayRumble(7);
                gCurrentPinballGame->unk54F[i] = 0;
                gCurrentPinballGame->scoreAddedInFrame = 3000;
                break;
            case 5:
                if (gCurrentPinballGame->unk562[i] < 10)
                {
                    gCurrentPinballGame->unk562[i]++;
                    gCurrentPinballGame->unk55B[i] = 5;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk553[i] = 6;
                }
                break;
            case 6:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 9)
                    {
                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk553[i] = 0;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 7)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }

                gCurrentPinballGame->unk54F[i] = 0;

                break;
            case 7:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 14)
                    {
                        gCurrentPinballGame->unk553[i] = 8;
                        gCurrentPinballGame->unk580[i].x += gCurrentPinballGame->unk55D[i] << 8;
                        gCurrentPinballGame->unk580[i].y += gCurrentPinballGame->unk55F[i] << 8;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 10)
                        m4aSongNumStart(SE_UNKNOWN_0x140);

                }
                gCurrentPinballGame->unk54F[i] = 2;

                break;
            case 8:
                if (gCurrentPinballGame->unk562[i] < 184)
                {
                    if (gCurrentPinballGame->unk562[i] < 160)
                    {
                        if (gCurrentPinballGame->unk551[i] == 0)
                            gCurrentPinballGame->unk580[i].x -= 0x10;
                        else
                            gCurrentPinballGame->unk580[i].x += 0x10;

                        if (gCurrentPinballGame->unk562[i] & 1)
                            gCurrentPinballGame->unk580[i].y -= 0x10;
                        else
                            gCurrentPinballGame->unk580[i].y -= 0x20;

                        if (gCurrentPinballGame->unk562[i] % 19 < 10)
                            gCurrentPinballGame->unk55B[i] = 14;
                        else
                            gCurrentPinballGame->unk55B[i] = 15;
                    }
                    else
                    {
                        if (gCurrentPinballGame->unk551[i] == 0)
                            gCurrentPinballGame->unk580[i].x += 0x140;
                        else
                            gCurrentPinballGame->unk580[i].x -= 0x140;

                        if (gCurrentPinballGame->unk562[i] & 1)
                            gCurrentPinballGame->unk580[i].y += 0x140;
                        else
                            gCurrentPinballGame->unk580[i].y += 0x1E0;

                        gCurrentPinballGame->unk55B[i] = 15;
                    }

                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk553[i] = 9;
                    gCurrentPinballGame->unk55B[i] = 16;
                    gCurrentPinballGame->unk562[i] = 0;
                    if (gCurrentPinballGame->unk551[i] == 0)
                        gCurrentPinballGame->unk580[i].x += 0xF0;
                    else
                        gCurrentPinballGame->unk580[i].x -= 0xF0;
                }
                break;
            case 9:
                if (gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][1] > gCurrentPinballGame->unk562[i])
                {
                    gCurrentPinballGame->unk562[i]++;
                }
                else
                {
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk55B[i]++;
                    if (gCurrentPinballGame->unk55B[i] == 20)
                    {
                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk553[i] = 0;
                    }

                    if (gCurrentPinballGame->unk55B[i] == 17)
                        m4aSongNumStart(SE_UNKNOWN_0x135);
                }
                break;
            case 10: {
                s16 len;
                if (gCurrentPinballGame->unk551[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                len = gUnknown_086AFAC0[var1].unk4;
                for (j = 0; j < len; j++)
                {
                    if (gUnknown_086AFAC0[var1].unk0[j].y <= gCurrentPinballGame->unk566[i])
                        break;
                }

                gCurrentPinballGame->unk559[i] = j;
                gCurrentPinballGame->unk553[i] = 11;
                gCurrentPinballGame->unk55B[i] = 29;
                gCurrentPinballGame->unk562[i] = 0;

                gCurrentPinballGame->unk580[i].x = gUnknown_086AFAC0[var1].unk0[gCurrentPinballGame->unk559[i]].x << 8;
                gCurrentPinballGame->unk580[i].y = gUnknown_086AFAC0[var1].unk0[gCurrentPinballGame->unk559[i]].y << 8;

                gCurrentPinballGame->unk559[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            }
            case 11:
                if (gCurrentPinballGame->unk551[i] == 0)
                    var1 = 3;
                else
                    var1 = 0;

                var4 = gCurrentPinballGame->unk559[i];
                var5 = gUnknown_086AFAC0;
                if (var4 < var5[var1].unk4)
                {
                    gCurrentPinballGame->unk580[i].x = var5[var1].unk0[gCurrentPinballGame->unk559[i]].x << 8;
                    gCurrentPinballGame->unk580[i].y = var5[var1].unk0[gCurrentPinballGame->unk559[i]].y << 8;
                    gCurrentPinballGame->unk559[i]++;
                    if (gCurrentPinballGame->unk559[i] == var5[var1].unk4)
                    {
                        gCurrentPinballGame->unk553[i] = 12;
                        gCurrentPinballGame->unk530[i] = gCurrentPinballGame->unk551[i];
                        gCurrentPinballGame->unk536[i] = 2;
                        if (gCurrentPinballGame->unk551[i] == 0)
                            gCurrentPinballGame->unk578[i].x = 0x140;
                        else
                            gCurrentPinballGame->unk578[i].x = -0x140;

                        gCurrentPinballGame->unk578[i].y = 0x1D0;
                    }
                }

                gCurrentPinballGame->unk55B[i] = ((gCurrentPinballGame->unk562[i] % 32) / 4) + 30;
                gCurrentPinballGame->unk562[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 12:
                gCurrentPinballGame->unk580[i].x += gCurrentPinballGame->unk578[i].x;
                gCurrentPinballGame->unk580[i].y += gCurrentPinballGame->unk578[i].y;
                gCurrentPinballGame->unk55B[i] = ((gCurrentPinballGame->unk562[i] % 32) / 4) + 30;
                gCurrentPinballGame->unk562[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 13:
                gCurrentPinballGame->unk580[i].x += gCurrentPinballGame->unk578[i].x;
                gCurrentPinballGame->unk580[i].y += gCurrentPinballGame->unk578[i].y;
                gCurrentPinballGame->unk55B[i] = ((gCurrentPinballGame->unk562[i] % 32) / 8) + 26;
                gCurrentPinballGame->unk562[i]++;
                gCurrentPinballGame->unk54F[i] = 0;
                break;
            case 14:
                gCurrentPinballGame->unk557[i] = -1;
                if (gCurrentPinballGame->unk54D[i] > 0)
                {
                    gCurrentPinballGame->unk54D[i]--;
                    gCurrentPinballGame->unk55B[i] = 38;
                    gCurrentPinballGame->unk54B[i] = 1;
                }
                else
                {
                    if (gCurrentPinballGame->unk562[i] < 334)
                    {
                        if (gCurrentPinballGame->unk562[i] < 16)
                        {
                            gCurrentPinballGame->unk55B[i] = 21;
                            if (gCurrentPinballGame->unk562[i] == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x13E);

                            gCurrentPinballGame->unk54F[i] = 3;
                        }
                        else if (gCurrentPinballGame->unk562[i] < 316)
                        {
                            if (gCurrentPinballGame->unk54B[i] == 0)
                            {
                                gCurrentPinballGame->unk580[i].y += 0x40;
                                if (gCurrentPinballGame->unk562[i] % 19 < 10)
                                    gCurrentPinballGame->unk55B[i] = 22;
                                else
                                    gCurrentPinballGame->unk55B[i] = 23;
                            }
                            else
                            {
                                gCurrentPinballGame->unk580[i].y += 0x80;
                                if (gCurrentPinballGame->unk562[i] % 10 < 5)
                                    gCurrentPinballGame->unk55B[i] = 22;
                                else
                                    gCurrentPinballGame->unk55B[i] = 23;
                            }

                            if (gCurrentPinballGame->unk580[i].y > 0xAC00)
                                gCurrentPinballGame->unk562[i] = 316;

                            gCurrentPinballGame->unk54F[i] = 3;
                        }
                        else
                        {
                            s16 var20;
                            gCurrentPinballGame->unk580[i].y += 0x30;
                            var20 = gCurrentPinballGame->unk562[i] - 316;
                            if (var20 < 10)
                                gCurrentPinballGame->unk55B[i] = 24;
                            else
                                gCurrentPinballGame->unk55B[i] = 25;

                            if (var20 == 1)
                                m4aSongNumStart(SE_UNKNOWN_0x136);

                            gCurrentPinballGame->unk54F[i] = 0;
                        }

                        gCurrentPinballGame->unk562[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->unk553[i] = 0;
                        gCurrentPinballGame->unk55B[i] = 0;
                        gCurrentPinballGame->unk562[i] = 0;
                    }
                }
                break;
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[14 + i];
        if (group->available)
        {
            sp4 = gCurrentPinballGame->unk555[i];
            gCurrentPinballGame->unk555[i] = gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][2] + (1 - gCurrentPinballGame->unk551[i]) * 30 ;
            var2 = gUnknown_086AFB2C[gCurrentPinballGame->unk55B[i]][0];

            group->baseX = (gCurrentPinballGame->unk580[i].x / 256) - (gCurrentPinballGame->unk58 + 12);
            group->baseY = (gCurrentPinballGame->unk580[i].y / 256) - (gCurrentPinballGame->unk5A + 14);

            DmaCopy16(3, gUnknown_084B046C[sp4], (void *)0x06011CA0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B56D8[var2][j];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                if (gCurrentPinballGame->unk551[i] == 0)
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->unk55D[i] = -gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->unk55F[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX + gCurrentPinballGame->unk55D[i] * 2;
                }
                else
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->unk55D[i] = gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->unk55F[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                }

                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum += i * 9;
            }

            var3 = 0x10;
            gCurrentPinballGame->unk570[i].x = ((gCurrentPinballGame->unk580[i].x / 256) + (gCurrentPinballGame->unk55D[i] - var3)) * 2;

            var3 = 0x12;
            gCurrentPinballGame->unk570[i].y = ((gCurrentPinballGame->unk580[i].y / 256) + (gCurrentPinballGame->unk55F[i] - var3)) * 2;

            gCurrentPinballGame->unk566[i] = gCurrentPinballGame->unk580[i].y / 256 + gCurrentPinballGame->unk55F[i];

            group = &gMain.spriteGroups[16 + i];
            if (sp4 == 12 || sp4 == 42)
            {
                if (gCurrentPinballGame->unk55B[i] == 11)
                    sp4 = 8;
                else
                    sp4 = 9;
            }
            else
            {
                sp4 = 0;
            }

            group->baseX = (gCurrentPinballGame->unk580[i].x / 256) - (gCurrentPinballGame->unk58 + 12);
            group->baseY = (gCurrentPinballGame->unk580[i].y / 256) - (gCurrentPinballGame->unk5A + 14);

            DmaCopy16(3, gUnknown_084B046C[sp4], (void *)0x06011EE0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void sub_44D58(void)
{
    s16 i;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = 0;
    group = &gMain.spriteGroups[18];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->unk58;
        group->baseY = 86 - gCurrentPinballGame->unk5A;
        if (gCurrentPinballGame->unk542 < 22)
            var0 = gUnknown_08137D60[gCurrentPinballGame->unk542];

        DmaCopy16(3, gUnknown_084AF9EC[var0], (void *)0x06010920, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[11];
    if (group->available)
    {
        group->baseX = 104 - gCurrentPinballGame->unk58;
        group->baseY = 94 - gCurrentPinballGame->unk5A;
        DmaCopy16(3, gUnknown_084AFFEC[var0], (void *)0x06010B20, 0x180);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->unk13 == 1)
        gMain.spriteGroups[11].available = 1;

    if (gCurrentPinballGame->unk13 < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->unk542)
    {
        if (gCurrentPinballGame->unk542 == 21)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_138);

        gCurrentPinballGame->unk542--;
        if (gCurrentPinballGame->unk542 == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_139);
    }

    if (gCurrentPinballGame->unk7E)
    {
        if (gMain.unk5 == FIELD_RUBY)
            SphealBoard_WhiscashDeliversBall();
        else
            SphealBoard_PelliperDeliversBall();
    }
}

void SphealBoard_WhiscashDeliversBall(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const u16 *offsets;
    s16 var0;

    group = &gMain.spriteGroups[19];
    if (group->available)
    {
        offsets = gUnknown_086AFC16[gCurrentPinballGame->unk591];
        group->baseX = 134 + offsets[2] - gCurrentPinballGame->unk58;
        group->baseY = 154 + offsets[3] - gCurrentPinballGame->unk5A;
        var0 = offsets[0];
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06012120, 0x460);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gUnknown_086AFC16[gCurrentPinballGame->unk591][1] > gCurrentPinballGame->unk592)
    {
        gCurrentPinballGame->unk592++;
    }
    else
    {
        gCurrentPinballGame->unk592 = 0;
        gCurrentPinballGame->unk591++;
        if (gCurrentPinballGame->unk591 == 1)
            gMain.spriteGroups[19].available = 1;

        if (gCurrentPinballGame->unk591 == 19)
        {
            gCurrentPinballGame->unk591 = 18;
            gMain.spriteGroups[19].available = 0;
            gCurrentPinballGame->unk7E = 0;
        }

        if (gCurrentPinballGame->unk591 == 9)
        {
            gCurrentPinballGame->ball->unkA -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8D00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC800;
            gCurrentPinballGame->ball->velocity.x = -0x60;
            gCurrentPinballGame->ball->velocity.y = 0x54;
            gCurrentPinballGame->ball->oamPriority = 3;
            PlayRumble(7);
        }

        if (gCurrentPinballGame->unk591 == 2)
            m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);

        if (gCurrentPinballGame->unk591 == 15)
            m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);

        if (gCurrentPinballGame->unk591 == 8)
        {
            m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->ball->unkA -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8F00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC300;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        if (gCurrentPinballGame->unk591 == 10)
            gCurrentPinballGame->unk1F = 0;
    }
}

void SphealBoard_PelliperDeliversBall(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[20];
    if (group->available)
    {
        group->baseX = (gCurrentPinballGame->unk320 / 10) - (gCurrentPinballGame->unk58 - 146);
        group->baseY = (gCurrentPinballGame->unk322 / 10) - (gCurrentPinballGame->unk5A - 110) + (gCurrentPinballGame->unk30E / 10);
        index = gCurrentPinballGame->unk591;
        DmaCopy16(3, gPelliper_Gfx[index], (void *)0x060125A0, 0x480);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->unk592 <= 250)
    {
        if (gCurrentPinballGame->unk592 == 250)
        {
            gCurrentPinballGame->unk320 = 920;
            gCurrentPinballGame->unk322 = -100;
            gCurrentPinballGame->unk31C = -82;
            gCurrentPinballGame->unk31E = 0;
            gCurrentPinballGame->unk30C = 0;
            gCurrentPinballGame->unk306 = 8;
            gCurrentPinballGame->unk591 = 13;
            gMain.spriteGroups[20].available = 1;
            gCurrentPinballGame->unk5FA = 1;
        }
    }
    else
    {
        gCurrentPinballGame->unk591 = (gCurrentPinballGame->unk30C % 24) / 6 + 13;
        gCurrentPinballGame->unk30E = (Sin(gCurrentPinballGame->unk30C * 0x400) * 240) / 20000;
        if (gCurrentPinballGame->unk30C == 0)
            m4aSongNumStart(SE_UNKNOWN_0xE4);

        if (gCurrentPinballGame->unk30C < 40)
        {
            gCurrentPinballGame->unk320 += gCurrentPinballGame->unk31C;
            gCurrentPinballGame->unk322 += gCurrentPinballGame->unk31E;
        }
        else
        {
            gMain.spriteGroups[20].available = 0;
        }

        if (gCurrentPinballGame->unk30C == 13)
        {
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk314 = -10;
            gCurrentPinballGame->unk316 = -25;
            gCurrentPinballGame->unk318 = ((gCurrentPinballGame->unk320 / 10) + 157) * 10;
            gCurrentPinballGame->unk31A = ((gCurrentPinballGame->unk322 / 10) + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->unk1F)
        {
            if (gCurrentPinballGame->unk30C < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = (gCurrentPinballGame->unk320 / 10) + 157;
                gCurrentPinballGame->ball->positionQ0.y = (gCurrentPinballGame->unk322 / 10) + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->unk316 += 2;
                gCurrentPinballGame->unk318 += gCurrentPinballGame->unk314;
                gCurrentPinballGame->unk31A += gCurrentPinballGame->unk316;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->unk318 / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->unk31A / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 181)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 181;
                    gCurrentPinballGame->unk5F7 = 0;
                    gCurrentPinballGame->unk1F = 0;
                    gCurrentPinballGame->ball->velocity.x = -10;
                    gCurrentPinballGame->ball->velocity.y = 0;
                    gCurrentPinballGame->unk5FA = 0;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->unk24 = 0;
                    gCurrentPinballGame->unk7E = 0;
                    m4aSongNumStart(SE_UNKNOWN_0xE5);
                    PlayRumble(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        gCurrentPinballGame->unk30C++;
    }

    gCurrentPinballGame->unk592++;
}

void sub_455D0(void)
{
    s16 i;
    s16 var0;

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->unk536[i])
        {
        case 0:
            gCurrentPinballGame->unk530[i] = 0;
            break;
        case 1:
            var0 = gCurrentPinballGame->unk530[i];
            gCurrentPinballGame->minionState[var0] = 2;
            gCurrentPinballGame->minionStateTimer[var0] = 0;
            gCurrentPinballGame->minionFramesetIx[var0] = 7;
            if (gCurrentPinballGame->unk53C[i])
            {
                gCurrentPinballGame->unk53C[i]--;
                if (gCurrentPinballGame->unk53C[i] == 0)
                {
                    gCurrentPinballGame->unk536[i] = 0;
                    gCurrentPinballGame->minionState[var0] = 1;
                    gCurrentPinballGame->minionStateTimer[var0] = 0;
                    gCurrentPinballGame->minionFramesetIx[var0] = 4;
                }
            }
            break;
        case 2:
            var0 = gCurrentPinballGame->unk530[i];
            if (i == 2)
            {
                gCurrentPinballGame->unk1F = 1;
                gCurrentPinballGame->ball->velocity.x += 5 - var0 * 10;
            }

            gCurrentPinballGame->unk536[i] = 3;
            gCurrentPinballGame->unk533[i] = 0;
            gCurrentPinballGame->minionState[var0] = 2;
            gCurrentPinballGame->minionStateTimer[var0] = 0;
            gCurrentPinballGame->minionFramesetIx[var0] = 7;
            break;
        case 3:
            var0 = gCurrentPinballGame->unk530[i];
            if (i < 2)
            {
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->unk580[i].x >= 0x5600)
                        gCurrentPinballGame->unk578[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].x <= 0x9C00)
                        gCurrentPinballGame->unk578[i].x = 0;

                }

                gCurrentPinballGame->unk578[i].y += 12;
                if (gCurrentPinballGame->unk548[var0] > 0)
                {
                    if (gCurrentPinballGame->unk580[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->unk533[i] = 0;
                        gCurrentPinballGame->unk536[i] = 5;
                        gCurrentPinballGame->minionState[var0] = 3;
                        gCurrentPinballGame->minionFramesetIx[var0] = 15;
                        gCurrentPinballGame->minionStateTimer[var0] = 0;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->unk533[i]++;
                        MPlayStart(&gMPlayInfo_SE1, &se_unk_13d);
                        if (gCurrentPinballGame->unk533[i] < 3)
                        {
                            gCurrentPinballGame->unk580[i].y = 0x6600;
                            gCurrentPinballGame->unk578[i].y = 0xFED4;
                            gCurrentPinballGame->unk553[i] = 13;
                            gCurrentPinballGame->minionState[var0] = 2;
                            gCurrentPinballGame->minionFramesetIx[var0] = 8;
                            gCurrentPinballGame->minionStateTimer[var0] = 12;
                        }
                        else
                        {
                            gCurrentPinballGame->unk578[i].x = (30 - var0 * 60) * 4;
                            gCurrentPinballGame->unk578[i].y = 0xFE70;
                            gCurrentPinballGame->unk533[i] = 0;
                            gCurrentPinballGame->unk536[i] = 4;
                            gCurrentPinballGame->minionState[var0] = 3;
                            gCurrentPinballGame->minionFramesetIx[var0] = 11;
                            gCurrentPinballGame->minionStateTimer[var0] = 0;
                            gCurrentPinballGame->unk542 = 100;
                            gCurrentPinballGame->unk52C[0]++;
                        }
                    }
                }
            }
            else
            {
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x5600)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x9C00)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                gCurrentPinballGame->ball->velocity.y += 3;
                if (gCurrentPinballGame->ball->positionQ8.y >= 0x6500)
                {
                    gCurrentPinballGame->unk533[i]++;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_13d);
                    PlayRumble(7);
                    if (gCurrentPinballGame->unk533[i] < 3)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x6500;
                        gCurrentPinballGame->ball->velocity.y = -0x5A;
                        gCurrentPinballGame->minionState[var0] = 2;
                        gCurrentPinballGame->minionFramesetIx[var0] = 8;
                        gCurrentPinballGame->minionStateTimer[var0] = 12;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.x = 28 - var0 * 56;
                        gCurrentPinballGame->ball->velocity.y = -0x78;
                        gCurrentPinballGame->unk533[i] = 0;
                        gCurrentPinballGame->unk536[i] = 4;
                        gCurrentPinballGame->minionState[var0] = 3;
                        gCurrentPinballGame->minionFramesetIx[var0] = 11;
                        gCurrentPinballGame->minionStateTimer[var0] = 0;
                        gCurrentPinballGame->unk542 = 106;
                        gCurrentPinballGame->unk52C[1]++;
                    }
                }
            }
            break;
        case 4:
            var0 = gCurrentPinballGame->unk530[i];
            if (i < 2)
            {
                gCurrentPinballGame->unk578[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->unk580[i].x >= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].x <= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }

                if (gCurrentPinballGame->unk580[i].y >= 0x8400)
                {
                    gCurrentPinballGame->unk536[i] = 0;
                    gCurrentPinballGame->unk553[i] = 14;
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk54B[i] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->velocity.y += 3;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8400)
                {
                    gCurrentPinballGame->unk533[i]++;
                    if (gCurrentPinballGame->unk533[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8400;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                        if (gCurrentPinballGame->unk533[i] == 1)
                            PlayRumble(7);
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->unk1F = 0;
                        gCurrentPinballGame->unk536[i] = 0;
                    }
                }
            }
            break;
        case 5:
            var0 = gCurrentPinballGame->unk530[i];
            if (i < 2)
            {
                gCurrentPinballGame->unk578[i].y += 12;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->unk580[i].x >= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->unk580[i].x <= 0x7800)
                        gCurrentPinballGame->unk578[i].x = 0;
                }

                if (gCurrentPinballGame->unk580[i].y >= 0x8E00)
                {
                    gCurrentPinballGame->unk536[i] = 0;
                    gCurrentPinballGame->unk553[i] = 14;
                    gCurrentPinballGame->unk562[i] = 0;
                    gCurrentPinballGame->unk54B[i] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->velocity.y += 3;
                if (var0 == 0)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8E00)
                {
                    gCurrentPinballGame->unk533[i]++;
                    if (gCurrentPinballGame->unk533[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8E00;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - var0 * 10;
                        gCurrentPinballGame->unk1F = 0;
                        gCurrentPinballGame->unk536[i] = 0;
                    }
                }
            }
            break;
        }
    }
}

void sub_45E08(void)
{
    s16 i;
    s16 var0;

    var0 = gUnknown_086AEED6[(gMain.systemFrameCount % 96) / 24];
    for (i = 0x100; i < 0x400; i++)
        gUnknown_03005C00[0x800 + i] = gUnknown_0837A4E8[i] + var0 * 4;

    DmaCopy16(3, &gUnknown_03005C00[0x800], (void *)0x06000000, 0x800);
}

void sub_45E90(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int value;
    s16 sp0[12];
    s16 sp18[12];

    if (gCurrentPinballGame->unk13 > 3)
    {
        if (gCurrentPinballGame->unk394 > -126)
        {
            gCurrentPinballGame->unk394 -= 6;
            gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->unk394 + 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->unk394 < 0)
        {
            gCurrentPinballGame->unk394 += 6;
            if (gCurrentPinballGame->unk394 > 0)
                gCurrentPinballGame->unk394 = 0;
        }

        gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->unk394 + 4;
    }

    if (gCurrentPinballGame->unk13 < 5)
    {
        gMain.blendControl = 0x1C42;
        gMain.blendAlpha = 0xC04;
    }

    if (gCurrentPinballGame->unk13 == 3)
    {
        if (gCurrentPinballGame->unk18)
            gCurrentPinballGame->unk18 += 0;
    }

    if (gCurrentPinballGame->unk53A > 100 && gCurrentPinballGame->unk53A < 450)
    {
        if (gCurrentPinballGame->unk52E[0] != gCurrentPinballGame->unk52C[0])
        {
            if ((gCurrentPinballGame->unk53A % 3) == 0)
            {
                gCurrentPinballGame->unk52E[0]++;
                m4aSongNumStart(SE_UNKNOWN_0x91);
            }
        }
        else
        {
            gCurrentPinballGame->unk53A = 490;
        }
    }

    if (gCurrentPinballGame->unk53A > 500 && gCurrentPinballGame->unk53A < 800)
    {
        if (gCurrentPinballGame->unk52E[1] != gCurrentPinballGame->unk52C[1])
        {
            if ((gCurrentPinballGame->unk53A % 3) == 0)
            {
                gCurrentPinballGame->unk52E[1]++;
                m4aSongNumStart(SE_UNKNOWN_0x91);
            }
        }
        else
        {
            gCurrentPinballGame->unk53A = 800;
        }
    }

    if (gCurrentPinballGame->unk53A < 800 && gCurrentPinballGame->unk18 > 160)
        gCurrentPinballGame->unk18 = 160;

    gCurrentPinballGame->unk53A++;

    group = &gMain.spriteGroups[7];
    if (!group->available)
        return;

    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 22; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    value = gCurrentPinballGame->unk52E[0] * 5000000;
    sp0[0] = value / 10000000;
    sp0[1] = (value % 10000000) / 1000000;
    sp0[2] = 10;
    sp0[3] = (value % 1000000) / 100000;
    sp0[4] = (value % 100000) / 10000;
    sp0[5] = (value % 10000) / 1000;
    sp0[6] = 10;
    sp0[7] = (value % 1000) / 100;
    sp0[8] = (value % 100) / 10;
    sp0[9] = value % 10;
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->unk52E[0];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[8];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->unk52E[1] * 1000000;
    sp0[0] = value / 10000000;
    sp0[1] = (value % 10000000) / 1000000;
    sp0[2] = 10;
    sp0[3] = (value % 1000000) / 100000;
    sp0[4] = (value % 100000) / 10000;
    sp0[5] = (value % 10000) / 1000;
    sp0[6] = 10;
    sp0[7] = (value % 1000) / 100;
    sp0[8] = (value % 100) / 10;
    sp0[9] = value % 10;
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->unk52E[1];
    sp0[0] = value / 10;
    sp0[1] = value % 10;
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[9];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->unk52E[0] * 5000000
          + gCurrentPinballGame->unk52E[1] * 1000000;
    gCurrentPinballGame->unk544 = value;
    sp0[0] = value / 100000000;
    sp0[1] = (value % 100000000) / 10000000;
    sp0[2] = (value % 10000000) / 1000000;
    sp0[3] = 10;
    sp0[4] = (value % 1000000) / 100000;
    sp0[5] = (value % 100000) / 10000;
    sp0[6] = (value % 10000) / 1000;
    sp0[7] = 10;
    sp0[8] = (value % 1000) / 100;
    sp0[9] = (value % 100) / 10;
    sp0[10] = value % 10;
    for (i = 0; i < 10; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;
    sp18[10] = sp0[10] * 2 + 0x2D0;
    value = gCurrentPinballGame->ballUpgradeType + 1;
    sp0[0] = value;
    sp18[11] = sp0[0] * 2 + 0x2D0;

    group = &gMain.spriteGroups[10];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->unk394;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }
}
