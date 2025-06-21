#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SpriteGroup gUnknown_0200BDC8;
extern struct SpriteGroup gUnknown_0200BC58;

extern void sub_35D54(void);
extern void sub_36CB4(void);
extern void sub_372B4(void);
extern void sub_3751C(void);
extern void sub_37850(void);
extern void sub_38218(void);

void sub_356A0(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gUnknown_0200BDC8;
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

    group = &gUnknown_0200BC58;
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
    if (gCurrentPinballGame->bonusFieldsComplete > 4)
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

void sub_35860(void)
{
    s16 i;

    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk13 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 120 * 60; // 120 seconds
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk383 = 0;
    gCurrentPinballGame->unk388 = 3;
    gCurrentPinballGame->unk392 = 0;
    gCurrentPinballGame->ball->unk0 = 1;
    gCurrentPinballGame->unk386 = 0;
    gCurrentPinballGame->unk3F7 = 1;
    gCurrentPinballGame->unk3DC = 0;
    gCurrentPinballGame->unk3E8 = 750;
    gCurrentPinballGame->unk3EA = 360;
    gCurrentPinballGame->unk3DF = 3;
    gCurrentPinballGame->unk385 = 0;
    gCurrentPinballGame->unk387 = 0;
    gCurrentPinballGame->unk394 = 0;
    gCurrentPinballGame->unk3DE = 0;
    gCurrentPinballGame->unk3E0 = 0;
    gCurrentPinballGame->unk3E2 = 0;
    gCurrentPinballGame->unk3E4 = 0;
    gCurrentPinballGame->unk3F4 = 0;
    gCurrentPinballGame->unk3F5 = 0;
    gCurrentPinballGame->unk3F6 = 0;
    gCurrentPinballGame->unk3F8 = 0;
    gCurrentPinballGame->unk3FA = 0;
    gCurrentPinballGame->unk3FC = 0;
    gCurrentPinballGame->unk404 = 0;
    gCurrentPinballGame->unk405 = 0;
    gCurrentPinballGame->unk406 = 0;
    gCurrentPinballGame->unk408 = 0;
    gCurrentPinballGame->unk40A = 0;
    gCurrentPinballGame->unk40C = 0;
    gCurrentPinballGame->unk40E = 0;
    gCurrentPinballGame->unk410 = 0;
    gCurrentPinballGame->unk412 = 0;
    for (i = 0; i < 4; i++)
        gCurrentPinballGame->unk41C[i] = 0;

    for (i = 0; i < 10; i++)
        gCurrentPinballGame->unk420[i] = 0;

    for (i = 0; i < 7; i++)
        gCurrentPinballGame->unk42A[i] = 0;

    gCurrentPinballGame->unk1A = 0;
    gCurrentPinballGame->unk402 = gCurrentPinballGame->unk3EA / 10 + 58;
    sub_38218();
    gCurrentPinballGame->unk387 = 1;
    sub_35D54();
    sub_36CB4();
    m4aSongNumStart(MUS_BONUS_FIELD_KECLEON);
    sub_372B4();
    sub_3751C();
    sub_37850();
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}
