#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const struct Vector16 gUnknown_08137D78[];
extern const u16 gUnknown_08137DA4[];
extern const u8 gUnknown_08510CAC[][0x20];

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
