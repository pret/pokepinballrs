#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const struct Vector16 gUnknown_08137D78[];
extern const u16 gUnknown_08137DA4[];
extern const u8 gUnknown_08510CAC[][0x20];

extern const u8 gUnknown_0850558C[][0x20];
extern const s8 gUnknown_086B0128[][3][20];

void sub_47FBC(void)
{
    int i;
    for (i = 0x340; i < 0x340 + 0x40; i++)
        gUnknown_03005C00[i] = 0x1FF;

    DmaCopy16(3, gUnknown_03005C00, (void *)0x6002000, 0x800);
}

void sub_47FF8(void)
{
    int newX, newY;

    if (JOY_HELD(A_BUTTON))
    {
        if (JOY_HELD(DPAD_UP))
            gCurrentPinballGame->ball->positionQ8.y -= 0x80;
        if (JOY_HELD(DPAD_DOWN))
            gCurrentPinballGame->ball->positionQ8.y += 0x80;
        if (JOY_HELD(DPAD_LEFT))
            gCurrentPinballGame->ball->positionQ8.x -= 0x80;
        if (JOY_HELD(DPAD_RIGHT))
            gCurrentPinballGame->ball->positionQ8.x += 0x80;
    }
    else
    {
        if (JOY_HELD(DPAD_UP))
            gCurrentPinballGame->ball->positionQ8.y -= 0x200;
        if (JOY_HELD(DPAD_DOWN))
            gCurrentPinballGame->ball->positionQ8.y += 0x200;
        if (JOY_HELD(DPAD_LEFT))
            gCurrentPinballGame->ball->positionQ8.x -= 0x200;
        if (JOY_HELD(DPAD_RIGHT))
            gCurrentPinballGame->ball->positionQ8.x += 0x200;
    }

    gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
    newX = gCurrentPinballGame->ball->positionQ8.x;
    if (newX < 0)
        newX += 0x7F;
    gCurrentPinballGame->ball->positionQ1.x = newX >> 7;

    newY = gCurrentPinballGame->ball->positionQ8.y;
    if (newY < 0)
        newY += 0x7F;
    gCurrentPinballGame->ball->positionQ1.y = newY >> 7;

    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
}

void sub_48124(void)
{
    if (JOY_NEW(DPAD_UP))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_DOWN))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_RIGHT))
        gCurrentPinballGame->ballSpeed^= 1;
    if (JOY_NEW(DPAD_LEFT))
        gCurrentPinballGame->ballSpeed^= 1;
}

// This function updates/draws the "End of Ball Bonus" summary
void sub_48190(void)
{
    int i, j;
    s16 var0;
    int var2;
    int value;
    int var4;
    int multiplier;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s8 sp0[16];
    s16 sp10;
    s16 sp14;
    s16 sp18;

    var0 = 212 - gCurrentPinballGame->unk63A;
    sp10 = 0;
    sp14 = 0;
    sp18 = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            s16 var1 = gCurrentPinballGame->unk678[i][j];
            if (var1 == 95)
                var1 = 48;
            else if (var1 == 94)
                var1 = 47;
            else if (var1 > 46)
                var1 -= 65;

            if (gCurrentPinballGame->unk63C[i][j])
            {
                DmaCopy16(3, gUnknown_0850558C[var1], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_0850558C[48], (void *)0x06016000 + (j + i * 22 + 0xA0) * 0x20, 0x20);
            }
        }
    }

    if (gMain.unk12 < 180)
    {
        if (gMain.unk12 > 50 && JOY_NEW(A_BUTTON))
        {
            if (gCurrentPinballGame->unk639 == 0)
            {
                gCurrentPinballGame->unk63A = 100;
                var0 = 100;
                gCurrentPinballGame->unk638 = 6;
                gCurrentPinballGame->unk630 =
                    gCurrentPinballGame->unk62A * 500000 +
                    gCurrentPinballGame->unk62B * 750000 +
                    gCurrentPinballGame->unk62C * 500000 +
                    gCurrentPinballGame->unk62D * 100000 +
                    gCurrentPinballGame->unk62E * 100000;
                
                gCurrentPinballGame->unk634 = 0;
                gMain.unk12 = 150;
    
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[1][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[2][j] = 1;
    
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
    
                sp14 = 1;
            }
            else
            {
                gCurrentPinballGame->unk63A = 1;
                gMain.unk12 = 51;
                var0 = 100;
                if (gCurrentPinballGame->unk6B4 || gCurrentPinballGame->unk6B8)
                {
                    gCurrentPinballGame->unk44 += gCurrentPinballGame->unk6B4;
                    gCurrentPinballGame->unk48 += gCurrentPinballGame->unk6B8;
                    gCurrentPinballGame->unk6B4 = 0;
                    gCurrentPinballGame->unk6B8 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

        }
    }

    if (gMain.unk12 == 185)
    {
        gCurrentPinballGame->unk639 = 0;
        gCurrentPinballGame->unk63A = 212;
        gCurrentPinballGame->unk638 = 0;
        gCurrentPinballGame->unk630 = 0;
        gCurrentPinballGame->unk634 = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
    }

    if (gCurrentPinballGame->unk63A != 0)
    {
        if (gMain.unk12 < 150)
            gMain.unk12++;

        if (gCurrentPinballGame->unk638 < 5)
        {
            if (var0 < 89)
            {
                var2 = var0 / 24;
                if (var2 > 2)
                    var2 = 2;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    if (gCurrentPinballGame->unk638 == 0 || i != 2)
                    {
                        if (gCurrentPinballGame->unk63C[i][j] == 0 && gCurrentPinballGame->unk678[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->unk63C[i][j] = 1;
                }
            }
            else if (var0 >= 148)
            {
                var0 = var0 - 148;
                var2 = var0 / 24;
                if (var2 > 1)
                    var2 = 1;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    gCurrentPinballGame->unk63C[i][j] = 0;
                }
            }

            if (gCurrentPinballGame->unk63A == 1)
            {
                gCurrentPinballGame->unk63A = 212;
                gCurrentPinballGame->unk638++;
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
            }
        }
        else if (gCurrentPinballGame->unk638 == 5)
        {
            if (var0 < 17)
            {
                sp10 = -var0 * 2;
                if (var0 == 2)
                    m4aSongNumStart(SE_UNKNOWN_0xA2);
            }
            else
            {
                sp10 = 0;
                gCurrentPinballGame->unk63A = 212;
                gCurrentPinballGame->unk638++;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[0][j] = 1;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[1][j] = 0;
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[2][j] = 0;

                for (i = 0; i < 3; i++)
                    for (j = 0; j < 20; j++)
                        gCurrentPinballGame->unk678[i][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][i][j];
            }
        }
        else
        {
            if (var0 < 89)
            {
                var2 = var0 / 24;
                if (var2 > 2)
                    var2 = 2;

                for (i = 0; i <= var2; i++)
                {
                    j = ((var0 - i * 24) % 40) / 2;
                    if (i != 0)
                    {
                        if (gCurrentPinballGame->unk63C[i][j] == 0 && gCurrentPinballGame->unk678[i][j] != 95)
                            sp18 = 1;
                    }

                    gCurrentPinballGame->unk63C[i][j] = 1;
                }
            }
        }

        if (sp18)
            m4aSongNumStart(SE_UNKNOWN_0xA1);
    }

    value = 0;
    multiplier = 0;
    if (gCurrentPinballGame->unk63A == 212 || sp14 != 0)
    {   
        switch (gCurrentPinballGame->unk638)
        {
        case 0:
            value = gCurrentPinballGame->unk62A;
            multiplier = 500000;
            break;
        case 1:
            value = gCurrentPinballGame->unk62B;
            multiplier = 750000;
            break;
        case 2:
            value = gCurrentPinballGame->unk62C;
            multiplier = 500000;
            break;
        case 3:
            value = gCurrentPinballGame->unk62D;
            multiplier = 100000;
            break;
        case 4:
            value = gCurrentPinballGame->unk62E;
            multiplier = 100000;
            break;
        case 5:
            value = 0;
            multiplier = 0;
            break;
        case 6:
            break;
        }

        if (gCurrentPinballGame->unk638 < 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            sp0[2] = value / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 2; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = value * multiplier;
            gCurrentPinballGame->unk634 = value;
            sp0[7] = value / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 7; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->unk638 == 5)
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
        else
        {
            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[0][19 - j] = sp0[j] + 27;

            for (i = 0; i < 10; i++)
                sp0[i] = 0;
            value = gCurrentPinballGame->unk62F;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 5; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[1][19 - j] = sp0[j] + 27;

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            value = 0;
            var4 = 0;
            while (gCurrentPinballGame->unk62F != 0)
            {
                value += gCurrentPinballGame->unk630;
                if (value / 200000000 > 0)
                {
                    value -= 200000000;
                    var4 += 2;
                }
                gCurrentPinballGame->unk62F--;
            }

            if (value / 100000000 > 0)
            {
                value -= 100000000;
                var4 += 1;
            }

            gCurrentPinballGame->unk6B8 = var4;
            gCurrentPinballGame->unk6B4 = value;
            sp0[10] = (var4 % 1000) / 100;
            sp0[9] = ((var4 % 100) / 10) + 10;
            sp0[8] = var4 % 10;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 10; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
    }

    if (var0 >= 90 && var0 <= 140)
    {
        if (gCurrentPinballGame->unk638 < 5)
        {
            if (gCurrentPinballGame->unk634 != 0)
                gCurrentPinballGame->unk63A = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->unk634 >= 200000)
                {
                    gCurrentPinballGame->unk634 -= 200000;
                    gCurrentPinballGame->unk630 += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->unk634 != 0)
                {
                    gCurrentPinballGame->unk630 += gCurrentPinballGame->unk634;
                    gCurrentPinballGame->unk634 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

            value = gCurrentPinballGame->unk630;
            sp0[8] = value / 100000000;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 8; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
        else if (gCurrentPinballGame->unk638 == 6)
        {
            gCurrentPinballGame->unk639 = 1;
            if (gCurrentPinballGame->unk6B4 || gCurrentPinballGame->unk6B8)
                gCurrentPinballGame->unk63A = 100;

            if ((gMain.systemFrameCount & 1) == 0)
            {
                if (gCurrentPinballGame->unk6B4 >= 200000)
                {
                    gCurrentPinballGame->unk6B4 -= 200000;
                    gCurrentPinballGame->unk44 += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->unk6B8 != 0)
                {
                    gCurrentPinballGame->unk6B8--;
                    gCurrentPinballGame->unk6B4 += 99800000;
                    gCurrentPinballGame->unk44 += 200000;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
                else if (gCurrentPinballGame->unk6B4 != 0)
                {
                    gCurrentPinballGame->unk44 += gCurrentPinballGame->unk6B4;
                    gCurrentPinballGame->unk6B4 = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x91);
                }
            }

            for (i = 0; i < 11; i++)
                sp0[i] = 0;
            for (j = 0; j < 20; j++)
                gCurrentPinballGame->unk678[2][j] = gUnknown_086B0128[gCurrentPinballGame->unk638][2][j];
            
            var4 = gCurrentPinballGame->unk6B8;
            value = gCurrentPinballGame->unk6B4;
            sp0[10] = (var4 % 1000) / 100;
            sp0[9] = ((var4 % 100) / 10) + 10;
            sp0[8] = var4 % 10;
            sp0[7] = (value % 100000000) / 10000000;
            sp0[6] = ((value % 10000000) / 1000000) + 10;
            sp0[5] = (value % 1000000) / 100000;
            sp0[4] = (value % 100000) / 10000;
            sp0[3] = ((value % 10000) / 1000) + 10;
            sp0[2] = (value % 1000) / 100;
            sp0[1] = (value % 100) / 10;
            sp0[0] = value % 10;
            for (i = 10; i > 0 && (sp0[i] <= 0 || sp0[i] == 10); i--) {}
            for (j = 0; j <= i; j++)
                gCurrentPinballGame->unk678[2][19 - j] = sp0[j] + 27;
        }
    }

    if (gCurrentPinballGame->unk63A)
        gCurrentPinballGame->unk63A--;

    group = &gMain.spriteGroups[9];
    if (group->available)
    {
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->unkFC + 38;
        for (j = 0; j < 14; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        for (i = 0; i < 3; i++)
        {
            group = &gMain.spriteGroups[6 + i];
            group->baseX = 104;
            group->baseY = 64 + i * 16 + gCurrentPinballGame->unkFC + sp10;
            for (j = 0; j < 5; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void sub_495A0(void)
{
    s16 i, j;
    u16 objPalettes[OBJ_PLTT_SIZE / 0x20][0x10];
    u8 rgb[3];

    gCurrentPinballGame->unk1104 = 1;
    gCurrentPinballGame->unk131C = 0;
    if (gMPlayInfo_BGM.status >= 0)
    {
        gCurrentPinballGame->unkF4C = gMPlayInfo_BGM.songHeader;
        m4aMPlayStop(&gMPlayInfo_BGM);
    }
    else
    {
        gCurrentPinballGame->unkF4C = NULL;
    }

    m4aMPlayAllStop();
    m4aSongNumStart(SE_UNKNOWN_0xA5);
    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        gCurrentPinballGame->unk6A = gCurrentPinballGame->unk68;
        if (gMain.selectedField == FIELD_RUBY)
            sub_4E814();
        else if (gMain.selectedField == FIELD_SAPPHIRE)
            sub_4F814();
    }

    gCurrentPinballGame->unk1106 = gMain.blendControl;
    gCurrentPinballGame->unk1108 = gMain.blendAlpha;
    gCurrentPinballGame->unk110A = gMain.blendBrightness;
    gCurrentPinballGame->unk110C = gMain.unk2C;
    gCurrentPinballGame->unk110E = gMain.vCount;
    DmaCopy16(3, (void *)OBJ_PLTT, gCurrentPinballGame->unk111A, OBJ_PLTT_SIZE);
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
        {
            if (i != 9 || j != 12)
            {
                rgb[0] = (((gCurrentPinballGame->unk111A[i][j] & 0x001F) >>  0) * 2) / 5;
                rgb[1] = (((gCurrentPinballGame->unk111A[i][j] & 0x03E0) >>  5) * 2) / 5;
                rgb[2] = (((gCurrentPinballGame->unk111A[i][j] & 0x7C00) >> 10) * 2) / 5;
                objPalettes[i][j] = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
            }
            else
            {
                objPalettes[i][j] = 0x7FFF;
            }
        }
    }

    DmaCopy16(3, objPalettes, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gMain.selectedField < MAIN_FIELD_COUNT)
        sub_1D4D0();
    else if (gMain.selectedField == FIELD_DUSCLOPS)
        sub_356A0();
    else if (gMain.selectedField == FIELD_KYOGRE)
        sub_3ADA0();
    else if (gMain.selectedField == FIELD_GROUDON)
        sub_3E5D0();

    sub_11F0(1);
}

void sub_497BC(void)
{
    gMain.blendControl = gCurrentPinballGame->unk1106;
    gMain.blendAlpha = gCurrentPinballGame->unk1108;
    gMain.blendBrightness = gCurrentPinballGame->unk110A;
    gMain.unk2C = gCurrentPinballGame->unk110C;
    gMain.vCount = gCurrentPinballGame->unk110E;
    DmaCopy16(3, gCurrentPinballGame->unk111A, (void *)OBJ_PLTT, OBJ_PLTT_SIZE);
    if (gCurrentPinballGame->unkF4C)
        m4aMPlayContinue(&gMPlayInfo_BGM);

    m4aSongNumStart(SE_UNKNOWN_0xA6);
    sub_11F0(0);
}

void sub_49850(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[0];
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
    gOamBuffer[oamSimple->oamId].matrixNum = 0;

    for (i = 1; i < 5; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
        gOamBuffer[oamSimple->oamId].matrixNum = 0;
    }

    for (i = 5; i < 11; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_OFF;
        gOamBuffer[oamSimple->oamId].matrixNum = 0;
    }

    group = &gMain.spriteGroups[1];
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    }

    group = &gMain.spriteGroups[2];
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset;
    }
}

void sub_49A34(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const struct Vector16 *offsets;
    s16 xOffset;
    s16 yOffset;
    s16 var0;
    s16 sb;
    s16 yScale = 8;

    if (gCurrentPinballGame->unk131C == 0)
    {
        gMain.blendControl = 0xCF;
        gMain.blendBrightness = 0xA;
        gMain.unk2C = 0;
        gMain.vCount = 144;
    }

    if (gCurrentPinballGame->unk131C < 16)
    {
        xOffset = 160 - gCurrentPinballGame->unk131C * 10;
        yOffset = 24;
        var0 = -1;
        sb = -1;
        yScale = 16;
    }
    else if (gCurrentPinballGame->unk131C < 24)
    {
        xOffset = 0;
        yOffset = 24 - (gCurrentPinballGame->unk131C - 15) * 3;
        if (gCurrentPinballGame->unk131C < 18)
        {
            var0 = -1;
            sb = -1;
            yScale = 8;
        }
        else if (gCurrentPinballGame->unk131C == 18)
        {
            var0 = 9;
            sb = -10;
            yScale = 16;
        }
        else if (gCurrentPinballGame->unk131C == 19)
        {
            var0 = 9;
            sb = -9;
            yScale = 128;
        }
        else if (gCurrentPinballGame->unk131C == 20)
        {
            var0 = 7;
            sb = -8;
            yScale = 160;
        }
        else if (gCurrentPinballGame->unk131C == 21)
        {
            var0 = 6;
            sb = -7;
            yScale = 192;
        }
        else if (gCurrentPinballGame->unk131C == 22)
        {
            var0 = 4;
            sb = -5;
            yScale = 224;
        }
        else
        {
            var0 = 4;
            sb = -4;
            yScale = 256;
        }
    }
    else
    {
        xOffset = 0;
        yOffset = 0;
        var0 = 4;
        sb = -4;
        yScale = 256;
    }

    group = &gMain.spriteGroups[0];
    if (var0 >= 0)
    {
        s16 index;

        group->baseX = 100;
        group->baseY = 80 + var0;
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gUnknown_08137D78[0].x;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gUnknown_08137D78[0].y + gCurrentPinballGame->unk1104 * 12;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
        gOamBuffer[oamSimple->oamId].matrixNum = 5;

        index = gUnknown_08137DA4[(gMain.systemFrameCount % 65) / 5];
        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            DmaCopy16(3, gUnknown_08510CAC[index], (void *)0x060118C0, 0x20);
        }
        else
        {
            DmaCopy16(3, gUnknown_08510CAC[index], (void *)0x06010480, 0x20);
        }

        offsets = gUnknown_08137D78;
        group->baseX = 100;
        group->baseY = 80 + var0;
        for (i = 1; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }

        group->baseX = 100;
        group->baseY = 88 + sb;
        for (i = 5; i < 11; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + offsets[i].x;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + offsets[i].y;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 5;
        }
    }

    SetMatrixScale(0x100, yScale, 5);

    group = &gMain.spriteGroups[1];
    group->baseX = 100 - xOffset;
    group->baseY = 80 + yOffset;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[2];
    group->baseX = 68 + xOffset;
    group->baseY = 108 - yOffset;
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    gCurrentPinballGame->unk131C++;
}
