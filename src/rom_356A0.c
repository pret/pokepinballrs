#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SpriteGroup gMain_spriteGroups_12;
extern struct SpriteGroup gMain_spriteGroups_14;

extern const u8 gKecleonBonusClear_Gfx[];
extern const u8 gKyogreBonusClear_Gfx[];
extern const u8 gGroudonBonusClear_Gfx[];
extern const u8 gRayquazaBonusClear_Gfx[];

void sub_350F0(void)
{
    gCurrentPinballGame->unk1100 = 1;
    switch (gCurrentPinballGame->unk17)
    {
    case 0:
        gCurrentPinballGame->unk18 = 65;
        gCurrentPinballGame->unk17 = 1;
        gMain.blendControl = 0x9F;
        break;
    case 1:
        if (gCurrentPinballGame->unk18)
        {
            gCurrentPinballGame->unk18--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->unk18 / 4;
            if (gCurrentPinballGame->unk18 == 0)
                gCurrentPinballGame->unk17++;
        }
        break;
    case 2:
        if (gCurrentPinballGame->unk18 < 30)
        {
            gCurrentPinballGame->unk18++;
        }
        else
        {
            gCurrentPinballGame->unk18 = 0;
            gCurrentPinballGame->unk17 = 0;
            gMain.spriteGroups[6].available = 0;
            gMain.spriteGroups[5].available = 0;
            if (gMain.unk5 != gMain.selectedField)
            {
                sub_357B8();
            }
            else
            {
                ResetSomeGraphicsRelatedStuff();
                gCurrentPinballGame->unk1D = 2;
            }
        }
        break;
    }
}

void sub_351A8(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    int var1;
    s16 sp0[8];
    s16 var2;

    var0 = 8;
    var1 = 0;
    group = &gMain.spriteGroups[6];
    if (gCurrentPinballGame->unk394 > 0)
    {
        gCurrentPinballGame->unk394 -= 6;
        if (gCurrentPinballGame->unk394 < 0)
            gCurrentPinballGame->unk394 = 0;
    }

    switch (gMain.selectedField)
    {
    case FIELD_DUSCLOPS:
        if (gCurrentPinballGame->unk13 == 5 && gCurrentPinballGame->unk18 < 180)
            var0 = (gCurrentPinballGame->unk18 % 24) / 12 + 8;
        var1 = 30000000;
        break;
    case FIELD_KECLEON:
        if (gCurrentPinballGame->unk13 == 3 && gCurrentPinballGame->unk18 < 180)
            var0 = (gCurrentPinballGame->unk18 % 24) / 12 + 8;
        var1 = 30000000;
        break;
    case FIELD_KYOGRE:
        if (gCurrentPinballGame->unk13 == 3 && gCurrentPinballGame->unk18 < 180)
            var0 = (gCurrentPinballGame->unk18 % 24) / 12 + 8;
        var1 = 50000000;
        break;
    case FIELD_GROUDON:
        if (gCurrentPinballGame->unk13 == 3 && gCurrentPinballGame->unk18 < 180)
            var0 = (gCurrentPinballGame->unk18 % 24) / 12 + 8;
        var1 = 50000000;
        break;
    case FIELD_RAYQUAZA:
        if (gCurrentPinballGame->unk13 == 3 && gCurrentPinballGame->unk18 < 180)
            var0 = (gCurrentPinballGame->unk18 % 24) / 12 + 8;
        var1 = 99999999;
        break;
    }

    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + var0 * 0x20, (void *)0x05000300, 0x20);

    if (group->available)
    {
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->unk394 + 50;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[5];
        group->baseX = 120;
        group->baseY = gCurrentPinballGame->unk394 + 50;
        for (i = 0; i < 18; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    sp0[0] = (var1 / 10000000);
    sp0[1] = (var1 % 10000000) / 1000000;
    sp0[2] = (var1 % 1000000) / 100000;
    sp0[3] = (var1 % 100000) / 10000;
    sp0[4] = (var1 % 10000) / 1000;
    sp0[5] = (var1 % 1000) / 100;
    sp0[6] = (var1 % 100) / 10;
    sp0[7] = (var1 % 10);

    switch (gMain.selectedField)
    {
    case FIELD_DUSCLOPS:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gDusclopsBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gDusclopsBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_KECLEON:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gKecleonBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gKecleonBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_KYOGRE:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gKyogreBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gKyogreBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_GROUDON:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gGroudonBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gGroudonBonusClear_Gfx[var2* 0x40], (void *)0x06017380, 0x40);
        break;
    case FIELD_RAYQUAZA:
        for (i = 0; i < 8; i++)
        {
            DmaCopy16(3, &gRayquazaBonusClear_Gfx[(sp0[i] + 0x70) * 0x40], (void *)0x06017000 + ((i * 2) + 12) * 0x20, 0x40);
        }
        var2 = gCurrentPinballGame->ballUpgradeType + 0x71;
        DmaCopy16(3, &gRayquazaBonusClear_Gfx[var2 * 0x40], (void *)0x06017380, 0x40);
        break;
    }
}

void sub_356A0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain_spriteGroups_14;
    switch (gCurrentPinballGame->unk3DC)
    {
    case 0:
    case 1:
    case 8:
        if (!group->available)
            break;

        group->baseX = 240;
        group->baseY = 160;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 240;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case 2:
        if (gCurrentPinballGame->unk3E6 <= 0)
            break;

        if (!group->available)
            break;

        group->baseX = 240;
        group->baseY = 160;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + 240;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }

    group = &gMain_spriteGroups_12;
    if (!group->available)
        return;

    group->baseX = 240;
    group->baseY = 160;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_357B8(void)
{
    u8 temp;

    m4aMPlayAllStop();
    sub_0D10();

    temp = gMain.unk5;
    gMain.unk5 = gMain.selectedField;
    gMain.selectedField = temp;
    gMain.unk6 = 0;
    gMain.unkF = 0;
    gCurrentPinballGame->eventTimer = 0;
    gCurrentPinballGame->unk294 = 0;
    if (gCurrentPinballGame->numCompletedBonusStages > 4)
        gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD] = 1;

    gMain.subState = 0;
    gCurrentPinballGame->unk15 = 3;
    gCurrentPinballGame->unk13 = 1;
    gCurrentPinballGame->unk16 = 0;
    gCurrentPinballGame->unk5FA = 0;
    gCurrentPinballGame->unkE6 = 0;
    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    if (gCurrentPinballGame->unk714)
        gCurrentPinballGame->unk6EE = 120;
}
