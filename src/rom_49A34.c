#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const struct Vector16 gUnknown_08137D78[];
extern const u16 gUnknown_08137DA4[];
extern const u8 gUnknown_08510CAC[][0x20];

extern const u8 gUnknown_0850558C[][0x20];
extern const s8 gUnknown_086B0128[][3][20];
extern const u8 gUnknown_0850100C[];
extern const u8 gUnknown_085028CC[];
extern const u8 gUnknown_085038CC[];
extern const u8 gUnknown_08514F4C[];
extern const u8 gUnknown_08514F6C[];
extern const u8 gUnknown_08521FAC[];
extern const u8 gUnknown_08521FCC[];
extern const u8 gUnknown_0850398C[];
extern const u8 gUnknown_08509F4C[];
extern const u8 gUnknown_08137DBE[];
extern const u8 gUnknown_08137DE8[];
extern u8 gUnknown_08137E00[];

extern const s16 gUnknown_086B0010[][4];

extern s16 gUnknown_02030750[];
extern s16 gUnknown_02031500[];
extern s16 gUnknown_020306C0[];
extern u8 gUnknown_0200FBB0[];
extern u8 gUnknown_020030A0[];


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

void sub_47100(void)
{
    gCurrentPinballGame->unkFC = 128;
}

void sub_47110(void)
{
    s16 i;

    for (i = 0; i < 0x800; i++)
        gUnknown_03005C00[i] = 0x1FF;

    DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x1000);
}

void sub_47160(void)
{
    if (JOY_NEW(START_BUTTON) && gMain.mainState != STATE_GAME_IDLE && gCurrentPinballGame->unk1100 == 0)
    {
        if (gMain.unkF & 0x2)
        {
            gMain.unkF &= ~0x2;
            sub_497BC();
        }
        else if ((gMain.unkF & 0x20) == 0)
        {
            gMain.unkF |= 0x2;
            sub_495A0();
        }
    }

    if (gMain.unkF & 0x2)
    {
        if (JOY_NEW(DPAD_UP))
        {
            gCurrentPinballGame->unk1104 ^= 1;
            m4aSongNumStart(SE_UNKNOWN_0xA3);
        }

        if (JOY_NEW(DPAD_DOWN))
        {
            gCurrentPinballGame->unk1104 ^= 1;
            m4aSongNumStart(SE_UNKNOWN_0xA3);
        }

        if (JOY_NEW(A_BUTTON) && !JOY_HELD(B_BUTTON | SELECT_BUTTON | START_BUTTON))
        {
            if (gCurrentPinballGame->unk1104 == 0)
            {
                gMain.unkE = 2;
                sub_49850();
            }

            gMain.unkF &= ~0x2;
            sub_497BC();
            gMain.newKeys &= ~A_BUTTON;
        }

        if (JOY_NEW(B_BUTTON))
        {
            gMain.unkF &= ~0x2;
            sub_497BC();
            gMain.newKeys &= ~B_BUTTON;
        }

        if (gMain.unkF & 0x2)
            sub_49A34();
    }

    if (gMain.unkF == 0x0)
    {
        gCurrentPinballGame->unk740 = 0;
        if (gMain.unk14 != 0)
        {
            gMain.unk14--;
            if (gMain.unk14 == 1)
            {
                if (gCurrentPinballGame->unkE4)
                    gMain.unk14 = 10;
                else if (gMain.unk11 == 0x8)
                    gCurrentPinballGame->unkE4 = 19;
                else
                    gCurrentPinballGame->unkE4 = 20;
            }

            if (gMain.unk14 == 0)
                gMain.unkF = gMain.unk11;
        }
    }
}

// Handle debug system flags
void sub_472E4(void)
{
    if (gMain.unkF == 0x0)
        return;

    if (gMain.unkF & 0x8)
    {
        // instantly reset ball
        sub_478D8();
        return;
    }

    if (gMain.unkF & 0x10)
    {
        // lose life, and reset ball
        sub_47670();
        return;
    }

    if (gMain.unkF & 0x20)
    {
        // end game
        sub_474F4();
        return;
    }

    if (gMain.unkF & 0x4)
    {
        // debug tool (move ball position, and change ball speed)
        sub_47344();
        gCurrentPinballGame->unk740 = gMain.unk10 + 1;
        return;
    }
}

// Debug menu that lets you move the ball's position and change ball speed.
// However, the menu text rendering is only half-implemented--the second
// menu item is for changing the ball's speed (toggling between fast and slow),
// but there is no indication of happening on-screen.
void sub_47344(void)
{
    int i;
    u8 str0[42];
    u8 str1[24];

    memcpy(str0, gUnknown_08137DBE, 42);
    memcpy(str1, gUnknown_08137DE8, 24);

    for (i = 0x340; i < 0x380; i++)
        gUnknown_03005C00[i] = 0;

    sub_06CC(gCurrentPinballGame->ball->positionQ0.x, &str1[1], 3, 1);
    sub_06CC(gCurrentPinballGame->ball->positionQ0.y, &str1[5], 3, 1);
    sub_0678(&str1[0], 26, 9);
    sub_06CC(gCurrentPinballGame->unk68, &str1[13], 3, 1);
    sub_0678(&str1[12], 26, 18);
    sub_0678(str0, 26, 0);

    if (JOY_HELD(B_BUTTON))
    {
        if (gMain.systemFrameCount & 0x8)
            sub_0678(gUnknown_08137E00, gMain.unk10 + 26, 0);

        if (JOY_NEW(DPAD_UP) && gMain.unk10 != 0)
            gMain.unk10--;

        if (JOY_NEW(DPAD_DOWN) && gMain.unk10 == 0)
            gMain.unk10++;

        if (gCurrentPinballGame->unk740 == 2)
            sub_48124();
    }
    else
    {
        switch (gCurrentPinballGame->unk740)
        {
        case 1:
            sub_47FF8();
            break;
        case 2:
            sub_48124();
            break;
        }

        sub_0678(gUnknown_08137E00, gMain.unk10 + 26, 0);
    }

    for (i = 0x340; i < 0x380; i++)
        gUnknown_03005C00[i] += 0xC100;

    DmaCopy16(3, gUnknown_03005C00, (void *)0x06002000, 0x800);
    if (JOY_HELD(A_BUTTON))
        sub_47FBC();
}

void sub_474F4(void)
{
    int i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 var0;

    group = gMain.unk44[42];
    if (group->available)
    {
        group->baseX = 63;
        group->baseY = 52;
        for (i = 0; i < 8; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    var0 = gMain.systemFrameCount * 0x1000;
    for (i = 0; i < 8; i++)
    {
        gUnknown_02031500[i] = (gUnknown_02030750[i] * Cos(var0)) / 200;
        if ((gMain.systemFrameCount & 1) == 0)
        {
            gUnknown_02030750[i]++;
            if (gUnknown_02030750[i] >= 0)
                gUnknown_02030750[i] = 0;
        }
    }

    if (gMain.unk12 == 3600)
    {
        DmaCopy16(3, gUnknown_08509F4C, (void *)0x06015800, 0x400);
        gMain.unk44[42]->available = 1;
        for (i = 0; i < 8; i++)
        {
            gUnknown_02031500[i] = 0xE0C0;
            gUnknown_020306C0[i] = 0;
            gUnknown_02030750[i] = (Random() % 30) + 0xFFCE;
        }
    }

    if (gMain.unk12)
    {
        gMain.unk12--;
        if (gMain.unk12 == 0)
            gCurrentPinballGame->unk1D = 2;
    }

    if (JOY_NEW(A_BUTTON))
        gCurrentPinballGame->unk1D = 2;
}

void sub_47670(void)
{
    s16 i, j;
    u8 var0;

    if (gMain.unk12)
    {
        if (gMain.unk12 < 21)
        {
            if (gMain.unk12 == 20)
                m4aSongNumStart(SE_UNKNOWN_0xA4);

            if (gCurrentPinballGame->unkFC < 128)
                gCurrentPinballGame->unkFC += 8;
        }
        else
        {
            if (gCurrentPinballGame->unkFC > 0)
                gCurrentPinballGame->unkFC -= 8;
        }

        sub_48190();
        gMain.unk12--;
        if (gMain.unk12 == 199)
        {
            gCurrentPinballGame->unkFC = 128;
            gMain.spriteGroups[9].available = 1;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[7].available = 1;
            gMain.spriteGroups[8].available = 1;
            DmaCopy16(3, gUnknown_0850398C, (void *)0x6015800, 0x2800);
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gUnknown_08521FAC, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_08521FCC, (void *)0x050003C0, 0x20);
            }

            m4aSongNumStart(SE_UNKNOWN_0xA4);
            for (i = 0; i < 3; i++)
                for (j = 0; j < 20; j++)
                    gCurrentPinballGame->unk63C[i][j] = 0;            
        }
        else if (gMain.unk12 == 1)
        {
            gMain.spriteGroups[9].available = 0;
            gMain.spriteGroups[6].available = 0;
            gMain.spriteGroups[7].available = 0;
            gMain.spriteGroups[8].available = 0;
        }
    }
    else
    {
        gMain.unkF &= 0xEF;
        sub_47FBC();
        if (gCurrentPinballGame->numLives > 0)
        {
            gCurrentPinballGame->unk724 = 1800;
            gCurrentPinballGame->numLives--;
            gCurrentPinballGame->unk26 = 60;
            gCurrentPinballGame->unk62A = 0;
            gCurrentPinballGame->unk62B = 0;
            gCurrentPinballGame->unk62C = 0;
            gCurrentPinballGame->unk62D = 0;
            gCurrentPinballGame->unk62E = 0;
            gCurrentPinballGame->unk62F = 0;
            sub_11C14(0);
            sub_46FD4(0);
            gCurrentPinballGame->unk29E = 0;
            if (gCurrentPinballGame->unk13 == 3)
            {
                var0 = gCurrentPinballGame->numCompletedBonusStages % 5;
                switch (var0)
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
            }
            else
            {
                sub_19B64(1);
            }

            gCurrentPinballGame->unkE4 = 0;
        }
        else
        {
            gMain.unkF |= 0x20;
            gMain.unk12 = 3600;
            m4aSongNumStart(MUS_GAME_OVER);
        }
    }
}

void sub_478D8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int newX, newY;
    s16 mat3Scale;
    s16 mat4Scale;

    if (gMain.unk12)
    {
        group = &gMain.spriteGroups[5];
        if (group->available)
        {
            group->baseX = 88;
            group->baseY = 20 + gCurrentPinballGame->unkFE;
            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 3;
            }
        }

        group = &gMain.spriteGroups[4];
        if (group->available)
        {
            group->baseX = 24 + gCurrentPinballGame->unk100 / 100;
            group->baseY = gCurrentPinballGame->unkFE + 20 + gCurrentPinballGame->unk104 / 100;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
            gOamBuffer[oamSimple->oamId].matrixNum = 4;
        }

        group = &gMain.spriteGroups[3];
        if (group->available)
        {
            group->baseX = 56 + gCurrentPinballGame->unk100 / 100;
            group->baseY = gCurrentPinballGame->unkFE + 52 + gCurrentPinballGame->unk104 / 100;
            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        gMain.unk12--;
        if (gMain.unk12 > 70)
        {
            int var0 = (gMain.unk12 + 20) % 0x40;
            gCurrentPinballGame->unk104 = (Sin(var0 * 0x400) * 500) / 20000;
            gCurrentPinballGame->unk108 = 10;
            gCurrentPinballGame->unk10A = 400;
        }
        else
        {
            gCurrentPinballGame->unk108 = 400;
            gCurrentPinballGame->unk10A -= 35;
            gCurrentPinballGame->unk100 += gCurrentPinballGame->unk108;
            gCurrentPinballGame->unk104 += gCurrentPinballGame->unk10A;
        }

        if (gMain.unk12 >= 30 && gMain.unk12 < 60)
        {
            mat4Scale = (60 - gMain.unk12) * 0x100 / 30 + 0x100;
        }
        else
        {
            mat4Scale = 0x100;
            if (gMain.unk12 < 30)
                gMain.spriteGroups[4].available = 0;
        }

        if (gMain.unk12 < 31)
        {
            if (gMain.unk12 > 10)
            {
                mat3Scale = ((gMain.unk12 - 10) * 248) / 20 + 8;
            }
            else
            {
                mat3Scale = 8;
                gMain.spriteGroups[5].available = 0;
            }
        }
        else
        {
            if (gCurrentPinballGame->unkFE > 0)
            {
                gCurrentPinballGame->unkFE -= 8;
                if (gCurrentPinballGame->unkFE < 0)
                    gCurrentPinballGame->unkFE = 0;
            }

            mat3Scale = 0x100;
        }

        if (gMain.unk12 < 203)
        {
            if (gMain.unk12 > 55)
            {
                gCurrentPinballGame->unk10C = gCurrentPinballGame->unk108;
                gCurrentPinballGame->unk10E = gCurrentPinballGame->unk10A - 90;
                gCurrentPinballGame->unk110 = gCurrentPinballGame->unk100;
                gCurrentPinballGame->unk114 = gCurrentPinballGame->unk104;
                if (gMain.unk12 == 56)
                    m4aSongNumStart(SE_UNKNOWN_0x95);

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->unk110 / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unkFE + 372 + gCurrentPinballGame->unk114 / 100) << 8;
            }
            else if (gMain.unk12 > 31)
            {
                gCurrentPinballGame->unk10E += 6;
                gCurrentPinballGame->unk110 += gCurrentPinballGame->unk10C;
                gCurrentPinballGame->unk114 += gCurrentPinballGame->unk10E;
                gMain.spriteGroups[3].available = 0;
                if (gMain.unk12 == 32)
                {
                    gCurrentPinballGame->unk5FA = 0;
                    m4aSongNumStart(SE_UNKNOWN_0x96);
                    sub_11B0(6);
                }

                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->unk110 / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unkFE + 372 + gCurrentPinballGame->unk114 / 100) << 8;
            }
            else
            {
                gCurrentPinballGame->unk10C = 0;
                gCurrentPinballGame->unk10E += 20;
                gCurrentPinballGame->unk110 += gCurrentPinballGame->unk10C;
                gCurrentPinballGame->unk114 += gCurrentPinballGame->unk10E;
                gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->unk110 / 100 + 86) << 8;
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->unkFE + 372 + gCurrentPinballGame->unk114 / 100) << 8;
                if (gCurrentPinballGame->ball->positionQ8.y > 0x17100)
                    gCurrentPinballGame->ball->positionQ8.y = 0x17100;
            }

            gCurrentPinballGame->ball->unk1 = 0;
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

        SetMatrixScale(0x100, mat3Scale, 3);
        SetMatrixScale(mat4Scale, mat4Scale, 4);

        if (gMain.unk12 == 203)
        {
            gCurrentPinballGame->unk100 = 0;
            gCurrentPinballGame->unk104 = 0;
            gCurrentPinballGame->unk108 = 0;
            gCurrentPinballGame->unk10A = 0;
            gCurrentPinballGame->unkFE = 100;
            gMain.spriteGroups[5].available = 1;
            gMain.spriteGroups[4].available = 1;
            gMain.spriteGroups[3].available = 1;
            if (gMain.selectedField == FIELD_RUBY)
            {
                DmaCopy16(3, gUnknown_0850100C, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_085028CC, (void *)0x06016800, 0x800);
                DmaCopy16(3, gUnknown_085038CC, (void *)0x06017000, 0xC0);
                DmaCopy16(3, gUnknown_08514F4C, (void *)0x050003C0, 0x20);
            }
            else
            {
                DmaCopy16(3, gUnknown_0850100C, (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_08514F6C, (void *)0x050003C0, 0x20);
            }

            gCurrentPinballGame->unk1F = 2;
            gCurrentPinballGame->unk5FA = 1;
            gCurrentPinballGame->unk5F7 = 1;
            gCurrentPinballGame->unk1100 = 1;
            m4aSongNumStart(SE_UNKNOWN_0x94);
        }
        else if (gMain.unk12 == 0)
        {
            gMain.spriteGroups[5].available = 0;
            gMain.spriteGroups[4].available = 0;
        }
    }
    else
    {
        gMain.unkF &= 0xF7;
        gCurrentPinballGame->unk26 = 60;
        sub_11C14(0);
        gCurrentPinballGame->unk1F = 0;
        sub_46FD4(0);
        gCurrentPinballGame->unk29E = 0;
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->ball->unk1 = 3;
        else
            gCurrentPinballGame->ball->unk1 = 1;

        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->unkE4 = 0;
        gCurrentPinballGame->unk1100 = 0;
    }
}

void sub_47FBC(void)
{
    int i;
    for (i = 0x340; i < 0x380; i++)
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
