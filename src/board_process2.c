#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

void AllBoardProcess_2A_4D6C4(void)
{
    s16 var0;
    s16 var1;

    var0 = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        var1 = 0;
    }
    else if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        var1 = -24;
    }
    else
    {
        var1 = 0;
        var0 = 8;
    }

    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        gCurrentPinballGame->unk5FC = var1 - 244;
        gCurrentPinballGame->unk5FE = 0;
        gCurrentPinballGame->unk5FB = 0;
        gCurrentPinballGame->unk4C = gUnknown_02031520.unk14.unk14;
        gCurrentPinballGame->unk4E = gUnknown_02031520.unk14.unk16;
        gCurrentPinballGame->unk54 = gUnknown_02031520.unk14.unk16 << 8;
        gCurrentPinballGame->unk58 = gCurrentPinballGame->unk4C;
        gCurrentPinballGame->unk5A = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk5FC;
        gMain.bgOffsets[2].xOffset = gCurrentPinballGame->unk4C + var0;
        gMain.bgOffsets[2].yOffset = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk5FC;
        gMain.bgOffsets[3].xOffset = gCurrentPinballGame->unk4C + var0;
        gMain.bgOffsets[3].yOffset = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk5FC;
        gMain.bgOffsets[1].xOffset = gCurrentPinballGame->unk4C + var0;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk5FC;
        if (gMain.selectedField == FIELD_RUBY)
        {
            if ((gCurrentPinballGame->numCompletedBonusStages / 5) % 2 == 0)
                m4aSongNumStart(MUS_FIELD_RUBY);
            else
                m4aSongNumStart(MUS_FIELD_RUBY2);
        }
        else
        {
            if ((gCurrentPinballGame->numCompletedBonusStages / 5) % 2 == 0)
                m4aSongNumStart(MUS_FIELD_SAPPHIRE);
            else
                m4aSongNumStart(MUS_FIELD_SAPPHIRE2);
        }
    }
    else
    {
        gCurrentPinballGame->unk5FC = 0;
        gCurrentPinballGame->unk5FE = 0;
        gCurrentPinballGame->unk5FB = 0;
        if (gMain.selectedField <= FIELD_KECLEON)
            gCurrentPinballGame->unkE6 = -24;
        else if (gMain.selectedField == FIELD_RAYQUAZA)
            gCurrentPinballGame->unkE6 = -88;
        else
            gCurrentPinballGame->unkE6 = -64;

        gCurrentPinballGame->unk4C = gUnknown_02031520.unk14.unk14;
        gCurrentPinballGame->unk4E = gUnknown_02031520.unk14.unk16 + gCurrentPinballGame->unkE6;
        gCurrentPinballGame->unk54 = gUnknown_02031520.unk14.unk16 << 8;
        gCurrentPinballGame->unk58 = gCurrentPinballGame->unk4C;
        gCurrentPinballGame->unk5A = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk5FC;
        gMain.bgOffsets[2].xOffset = gCurrentPinballGame->unk4C + var0;
        gMain.bgOffsets[2].yOffset = gCurrentPinballGame->unk4E;
        gMain.bgOffsets[3].xOffset = gCurrentPinballGame->unk4C + var0;
        gMain.bgOffsets[3].yOffset = gCurrentPinballGame->unk4E;
        gMain.bgOffsets[1].xOffset = gCurrentPinballGame->unk4C + var0;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->unk4E / 2;
        if (gMain.selectedField == FIELD_KECLEON)
            gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset + (gCurrentPinballGame->unk290 & 0x7FF) / 8;
    }

    gMain.bgOffsets[0].yOffset = 80;
    gCurrentPinballGame->unkCC = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->unkCA = gCurrentPinballGame->unkCC;
    gCurrentPinballGame->unk2C = 0x1000;
}

void MainBoardProcess_2B_4D960(void)
{
    int var0;
    int var1;
    int var2;
    s16 var3;
    int var4;

    var0 = 0x1000;
    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        sub_4E2F8();

    if (gCurrentPinballGame->unk5FB)
    {
        if (gCurrentPinballGame->unk5FC != gCurrentPinballGame->unk5FE)
        {
            if (gCurrentPinballGame->unk5FC > gCurrentPinballGame->unk5FE)
                gCurrentPinballGame->unk5FC--;
            else
                gCurrentPinballGame->unk5FC++;
        }
        else
        {
            gCurrentPinballGame->unk5FB = 0;
        }
    }

    if (gCurrentPinballGame->unk1F == 0)
        var0 = (gCurrentPinballGame->unk1330->velocity.y * 40) + 0x1000;

    gCurrentPinballGame->unk2C += (var0 - gCurrentPinballGame->unk2C) / 10;
    var1 = gCurrentPinballGame->unk1330->positionQ8.y + gCurrentPinballGame->unk2C;
    if (var1 > gUnknown_02031520.unk14.unk18 << 8)
        var1 = gUnknown_02031520.unk14.unk18 << 8;
    else if (var1 < gUnknown_02031520.unk14.unk1A << 8)
        var1 = gUnknown_02031520.unk14.unk1A << 8;

    var1 -= 0x5000;
    var4 = gCurrentPinballGame->unk54;
    var2 = (var1 - var4) / 12;
    if (var2 > 0)
    {
        if (var2 < 80)
            var2 = 0;
    }
    else
    {
        if (var2 > -80)
            var2 = 0;
    }

    var4 += var2;
    if (gCurrentPinballGame->unk5FA == 0)
    {
        gCurrentPinballGame->unk54 = var4;
        gCurrentPinballGame->unk4E = var4 / 0x100;
        if (gCurrentPinballGame->unk1330->positionQ0.x >= 230)
            gCurrentPinballGame->unk4C++;
        else
            gCurrentPinballGame->unk4C--;

        if (gCurrentPinballGame->unk4C > 16)
            gCurrentPinballGame->unk4C = 16;
        else if (gCurrentPinballGame->unk4C < 0)
            gCurrentPinballGame->unk4C = 0;
    }

    sub_4DFA0();
    gMain.bgOffsets[3].xOffset = gCurrentPinballGame->unk4C + gCurrentPinballGame->unk120 + gCurrentPinballGame->unk2AA;
    gCurrentPinballGame->unkCC = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk121 + gCurrentPinballGame->unk5FC + gCurrentPinballGame->unkE6;
    var3 = gMain.bgOffsets[3].yOffset - gCurrentPinballGame->unkCC;
    if (var3 > 8)
        var3 = 8;
    else if (var3 < -8)
        var3 = -8;

    if (var3)
        gMain.bgOffsets[3].yOffset -= var3;

    gMain.bgOffsets[2].xOffset = gMain.bgOffsets[3].xOffset;
    gMain.bgOffsets[2].yOffset = gMain.bgOffsets[3].yOffset;
    gMain.bgOffsets[1].xOffset = gMain.bgOffsets[3].xOffset;
    gMain.bgOffsets[1].yOffset = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->unk58 = gCurrentPinballGame->unk4C + gCurrentPinballGame->unk120 + gCurrentPinballGame->unk2AA;
    gCurrentPinballGame->unk5A = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk121 + gCurrentPinballGame->unk5FC + gCurrentPinballGame->unkE6;
    gCurrentPinballGame->unk6A = gCurrentPinballGame->unk68;
    gCurrentPinballGame->unk68 = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk121 + gCurrentPinballGame->unk5FC + gCurrentPinballGame->unkE6;
}

void BonusBoardProcess_2B_4DBFC(void)
{
    int var0;
    int var1;
    int var2;
    s16 var3;
    int var4;

    var0 = 0x1000;
    if ((gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS) == 0)
        sub_4E468();

    if (gCurrentPinballGame->unk5FB)
    {
        if (gCurrentPinballGame->unk5FC != gCurrentPinballGame->unk5FE)
        {
            if (gCurrentPinballGame->unk5FC > gCurrentPinballGame->unk5FE)
                gCurrentPinballGame->unk5FC--;
            else
                gCurrentPinballGame->unk5FC++;
        }
        else
        {
            gCurrentPinballGame->unk5FB = 0;
        }
    }

    if (gCurrentPinballGame->unk1F == 0)
        var0 = gCurrentPinballGame->unk1330->velocity.y * 40 + 0x1000;

    gCurrentPinballGame->unk2C += (var0 - gCurrentPinballGame->unk2C) / 10;
    var1 = gCurrentPinballGame->unk1330->positionQ8.y + gCurrentPinballGame->unk2C;
    if (var1 > gUnknown_02031520.unk14.unk18 << 8)
        var1 = gUnknown_02031520.unk14.unk18 << 8;
    else if (var1 < gUnknown_02031520.unk14.unk1A << 8)
        var1 = gUnknown_02031520.unk14.unk1A << 8;

    var1 -= 0x5000;
    var4 = gCurrentPinballGame->unk54;
    var2 = (var1 - var4) / 12;
    if (var2 > 0)
    {
        if (var2 < 80)
            var2 = 0;
    }
    else
    {
        if (var2 > -80)
            var2 = 0;
    }

    var4 += var2;
    if (gCurrentPinballGame->unk5FA == 0)
    {
        gCurrentPinballGame->unk54 = var4;
        gCurrentPinballGame->unk4E = var4 / 0x100;
    }

    sub_4DFA0();
    gMain.bgOffsets[2].xOffset = gCurrentPinballGame->unk4C + gCurrentPinballGame->unk120 + 8 + gCurrentPinballGame->unk2AA;
    gCurrentPinballGame->unkCC = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk121 + gCurrentPinballGame->unk5FC + gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk2AC;
    var3 = gCurrentPinballGame->unkCA - gCurrentPinballGame->unkCC;
    if (var3 > 8)
        var3 = 8;
    else if (var3 < -8)
        var3 = -8;

    if (var3)
        gCurrentPinballGame->unkCA -= var3;

    gMain.bgOffsets[2].yOffset = gCurrentPinballGame->unkCA;

    switch (gMain.selectedField)
    {
    case 2:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->unkCA / 2;
        break;
    case 3:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset + (gCurrentPinballGame->unk290 & 0x7FF) / 8;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = 0;
        break;
    case 4:
    case 5:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    case 6:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset / 4;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    case 7:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    }

    gCurrentPinballGame->unk58 = gCurrentPinballGame->unk4C + gCurrentPinballGame->unk120 + gCurrentPinballGame->unk2AA;
    gCurrentPinballGame->unk5A = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk121 + gCurrentPinballGame->unk5FC + gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk2AC;
    gCurrentPinballGame->unk68 = gCurrentPinballGame->unk4E + gCurrentPinballGame->unk121 + gCurrentPinballGame->unk5FC + gCurrentPinballGame->unkE6;
}

void sub_4DFA0(void)
{
    int i;
    s16 sp0[4];

    if (gCurrentPinballGame->unk25 == 0 && gCurrentPinballGame->unk5A4 != 2 && gCurrentPinballGame->unk61C == 0)
    {
        if (gCurrentPinballGame->newButtonActions[2])
        {
            if (gCurrentPinballGame->unk12A == 0)
            {
                gCurrentPinballGame->unk129 = 0;
                if (gCurrentPinballGame->unk128 == 0)
                {
                    gCurrentPinballGame->unk128 = 4;
                    m4aSongNumStart(SE_TILT_TRIGGERED);
                    PlayRumble(8);
                }
            }
        }

        if (gCurrentPinballGame->newButtonActions[3] && gCurrentPinballGame->unk12A == 0)
        {
            gCurrentPinballGame->unk129 = 1;
            if (gCurrentPinballGame->unk128 == 0)
            {
                gCurrentPinballGame->unk128 = 4;
                m4aSongNumStart(SE_TILT_TRIGGERED);
                PlayRumble(8);
            }
        }

        if (gCurrentPinballGame->newButtonActions[4] && gCurrentPinballGame->unk12A == 0)
        {
            gCurrentPinballGame->unk129 = 2;
            if (gCurrentPinballGame->unk128 == 0)
            {
                gCurrentPinballGame->unk128 = 4;
                m4aSongNumStart(SE_TILT_TRIGGERED);
                PlayRumble(8);
            }
        }
    }

    if (gCurrentPinballGame->unk128)
    {
        gCurrentPinballGame->unk128--;
        if (gCurrentPinballGame->unk128 == 0)
        {
            switch (gCurrentPinballGame->unk129)
            {
            case 0:
                gCurrentPinballGame->unk118[0] = 6;
                gCurrentPinballGame->unk11C[0] = -1;
                gCurrentPinballGame->unk118[2] = 6;
                gCurrentPinballGame->unk11C[2] = 1;
                break;
            case 1:
                gCurrentPinballGame->unk118[1] = 6;
                gCurrentPinballGame->unk11C[1] = 1;
                gCurrentPinballGame->unk118[3] = 6;
                gCurrentPinballGame->unk11C[3] = 1;
                break;
            case 2:
                gCurrentPinballGame->unk118[2] = 6;
                gCurrentPinballGame->unk11C[2] = 1;
                gCurrentPinballGame->unk118[3] = 0;
                gCurrentPinballGame->unk11C[3] = 1;
                break;
            }

            gCurrentPinballGame->unk12A = 24;
        }
    }

    if (gCurrentPinballGame->unk12A)
        gCurrentPinballGame->unk12A--;

    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->unk118[i] > 0)
            gCurrentPinballGame->unk118[i]--;

        if (gCurrentPinballGame->unk118[i] < 3)
            sp0[i] = gCurrentPinballGame->unk11C[i] * gCurrentPinballGame->unk118[i];
        else
            sp0[i] = gCurrentPinballGame->unk11C[i] * (6 - gCurrentPinballGame->unk118[i]);
    }

    gCurrentPinballGame->unk120 = sp0[0] + sp0[1];
    gCurrentPinballGame->unk121 = sp0[2] + sp0[3];

    if (gCurrentPinballGame->unk120 == 0 && gCurrentPinballGame->unk121 == 0)
    {
        gCurrentPinballGame->unk126 = 0;
        gCurrentPinballGame->unk127 = 0;
    }

    if (gCurrentPinballGame->unk120 > 0)
    {
        if (gCurrentPinballGame->unk120 < gCurrentPinballGame->unk122)
            gCurrentPinballGame->unk122--;
    }
    else if (gCurrentPinballGame->unk120 < 0)
    {
        if (gCurrentPinballGame->unk120 > gCurrentPinballGame->unk122)
            gCurrentPinballGame->unk122++;
    }

    if (gCurrentPinballGame->unk121 > 0)
    {
        if (gCurrentPinballGame->unk121 < gCurrentPinballGame->unk123)
            gCurrentPinballGame->unk123--;
    }
    else if (gCurrentPinballGame->unk121 < 0)
    {
        if (gCurrentPinballGame->unk121 > gCurrentPinballGame->unk123)
            gCurrentPinballGame->unk123++;
    }

    if (gCurrentPinballGame->unk126 == 0)
    {
        gCurrentPinballGame->unk122 = gCurrentPinballGame->unk120;
        gCurrentPinballGame->unk123 = gCurrentPinballGame->unk121;
    }
}

void sub_4E2F8(void)
{
    struct BallState *unk1334;

    if (gCurrentPinballGame->unk13 && gCurrentPinballGame->newButtonActions[1] && gCurrentPinballGame->unk20)
    {
        gCurrentPinballGame->unk21 = 1;
        gCurrentPinballGame->unk163 = 1;
    }

    if (gCurrentPinballGame->unk21 && gCurrentPinballGame->releasedButtonActions[1])
    {
        gCurrentPinballGame->unk163 = 3;
        if (gCurrentPinballGame->unk20)
        {
            PlayRumble(7);
            gCurrentPinballGame->ball->velocity.y = -590;
            gCurrentPinballGame->ball->velocity.x = 0;
            m4aSongNumStart(SE_UNKNOWN_0xCD);
        }

        gCurrentPinballGame->unk21 = 0;
    }

    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
    unk1334 = &gCurrentPinballGame->unk1334[0];

    if (unk1334->positionQ0.y >= gUnknown_02031520.unk14.unk2A)
    {
        unk1334->positionQ0.y = gUnknown_02031520.unk14.unk2A;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        if (gMain.unk14 == 0)
        {
            if (gCurrentPinballGame->unk724)
            {
                gMain.unk14 = 4;
                gMain.unk11 = 8;
                gMain.unk12 = 204;
            }
            else
            {
                gMain.unk14 = 80;
                gMain.unk11 = 16;
                gMain.unk12 = 200;
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL);
                sub_4E598();
                if (gCurrentPinballGame->outLanePikaPosition == 2 && gMain.eReaderBonuses[EREADER_DX_MODE_CARD] == 0)
                {
                    gCurrentPinballGame->unk1BE = 2;
                    gCurrentPinballGame->unk1C0 = 800;
                    gCurrentPinballGame->outLanePikaPosition = 0;
                }
            }
        }
    }

    gCurrentPinballGame->unk20 = 0;
}

void sub_4E468(void)
{
    struct BallState *unk1334;

    gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
    unk1334 = &gCurrentPinballGame->unk1334[0];

    if (unk1334->positionQ0.y >= gUnknown_02031520.unk14.unk2A)
    {
        unk1334->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        if (gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS)
        {
            gCurrentPinballGame->returnToMainBoardFlag = 1;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ball->positionQ0.y = gUnknown_02031520.unk14.unk2A - 10;
        }
        else
        {
            gCurrentPinballGame->ball->unk0 = 1;
            gCurrentPinballGame->unk388 = 1;
            gCurrentPinballGame->unk392 = 0;
            gCurrentPinballGame->ball->positionQ0.x = gUnknown_02031520.unk14.unk26;
            gCurrentPinballGame->ball->positionQ0.y = gUnknown_02031520.unk14.unk28;
            if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                gCurrentPinballGame->ballUpgradeType--;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
    }
}

void sub_4E598(void)
{
    gCurrentPinballGame->unk18 = 10199;

    if (gCurrentPinballGame->unk13 == 2)
        gCurrentPinballGame->unk17 = 5;
    if (gCurrentPinballGame->unk13 == 7)
        gCurrentPinballGame->unk17 = 6;
    if (gCurrentPinballGame->unk13 == 4)
        gCurrentPinballGame->unk17 = 10;
    if (gCurrentPinballGame->unk13 == 5)
        gCurrentPinballGame->unk17 = 6;
    if (gCurrentPinballGame->unk13 == 6)
        gCurrentPinballGame->unk17 = 8;

    gCurrentPinballGame->unk714 = 0;
    gCurrentPinballGame->holeIndicators[0] = 0;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->unk614 = 0;
    gCurrentPinballGame->unk208 = 0;
    gCurrentPinballGame->unk20A = 0;
    if (gCurrentPinballGame->outLanePikaPosition != 2 || !gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->unk1C6 = 0;
        gCurrentPinballGame->unk1C8 = 0;
        gCurrentPinballGame->unk1CC = 0;
        gCurrentPinballGame->unk1CA = 0;
        gCurrentPinballGame->unk1D4 = 0;
        gCurrentPinballGame->unk1D6 = -4;
        gCurrentPinballGame->unk1D8 = 0x100;
        gCurrentPinballGame->unk1DA = 0x100;
        gCurrentPinballGame->unk1CE = 0;
        gCurrentPinballGame->unk1D0 = 0;
    }

    gCurrentPinballGame->ballPowerUpLight[0] = 0;
    gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
    gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
    gCurrentPinballGame->bumperHitsSinceReset = 0;
    if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
        gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
        DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    }
    else
    {
        gCurrentPinballGame->ballUpgradeType = 0;
        gCurrentPinballGame->ballUpgradeCounter = 0;
    }

    gCurrentPinballGame->unk5F7 = 0;
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    gCurrentPinballGame->unk62F = gCurrentPinballGame->unk70E;
    gCurrentPinballGame->unk70E = 1;
    if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT)
    {
        gCurrentPinballGame->shouldProcessWhiscash = FALSE;
        gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
        gCurrentPinballGame->whiscashStateTimer = 0;
        gCurrentPinballGame->rubyPondContentsChanging = TRUE;
        gCurrentPinballGame->rubyPondChangeTimer = 0x40;
        gCurrentPinballGame->unk2AA = 0;

    }

    gCurrentPinballGame->unk300 = 0;
}
