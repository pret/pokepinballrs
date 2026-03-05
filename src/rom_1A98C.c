#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

void sub_1AAA0(void);
void sub_1AA38(void);
void sub_1ADF4(void);
void sub_1AF84(void);
void sub_1AFD4(void);
void sub_1C560(void);
void sub_1C5AC(void);
void sub_19B64(u8);
void sub_22A30(void);
void sub_22C6C(void);
void sub_22D54(void);


void sub_1A98C(void)
{
    if (gMain.modeChangeFlags != MODE_CHANGE_NONE)
        return;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_1AA38();
        break;
    case 2:
        sub_1AD84();
        break;
    case 3:
        sub_1AF84();
        break;
    case 4:
        sub_1C560();
        break;
    }

    gCurrentPinballGame->unk26 = 60;
}

void sub_1A9E8(void)
{
    if (gCurrentPinballGame->unk26 > 0)
        gCurrentPinballGame->unk26--;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_1AAA0(); // Catch hole
        break;
    case 2:
        sub_1ADF4(); //Hatch hole
        break;
    case 3:
        sub_1AFD4(); //Mart / Evo hole
        break;
    case 4:
        sub_1C5AC(); //Center Hole
        break;
    }
}

void sub_1AA38(void)
{
    if (gCurrentPinballGame->unk72F > 1)
    {
        sub_19B64(4);
    }

    gCurrentPinballGame->unk5FC = 0;
    gCurrentPinballGame->unk5FB = 0;
    gCurrentPinballGame->unk5FE = 0;
    gCurrentPinballGame->unk28 = 113;

    m4aSongNumStart(SE_UNKNOWN_0xCE);
    gCurrentPinballGame->scoreAddedInFrame = 50000;

    PlayRumble(8);
}

/*
* Ruby board Sharpedo; during the initation of the catch mode
* Echoes sub_32BE4, which is the equivalent 'catch hole' on the sapphire board.
*
* Note: this *does not* affect the start of the catch mode itself.
* When this function is nulled out at sub_1A9E8, the banner *doesn't* show, and
* the ball bounces off the sharpedo. However, the grid still shows a picked mon,
* and the mode otherwise works mostly normally, with the exception of affecting
* the 'tilt' behavior, and the collision with the cyndaquil pushback.
*/
void sub_1AAA0(void)
{
    if (gCurrentPinballGame->unk28) //Countdown timer; ball grabbed/held while banner shows
    {
        gCurrentPinballGame->unk28--;
        if (gCurrentPinballGame->unk28 > 100)
        {
            gCurrentPinballGame->unk5F7 = 1;
            gCurrentPinballGame->unk1F = 1;

            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->unk6 = 0;

            if (gCurrentPinballGame->unk28 > 108)
            {
                gCurrentPinballGame->unk5FA = 1;

                if (gCurrentPinballGame->unk28 > 110)
                {
                    gCurrentPinballGame->ball->positionQ0.x = 195;
                    gCurrentPinballGame->ball->positionQ0.y = 222;
                }
                else
                {
                    gCurrentPinballGame->ball->positionQ0.x = 196;
                    gCurrentPinballGame->ball->positionQ0.y = 221;
                }
                //Presumed controling either the message board 'state'/'tile'
                // or the sharpedo animation 'state'/tile.
                gCurrentPinballGame->unk2F4 =6;
            }
            else if (gCurrentPinballGame->unk28 > 104)
            {
                gCurrentPinballGame->ball->positionQ0.x = 197;
                gCurrentPinballGame->ball->positionQ0.y = 219;
                gCurrentPinballGame->unk2F4 = 7;
            }
            else
            {
                gCurrentPinballGame->ball->unk0 = 1;
                gCurrentPinballGame->unk2F4 = 8;
            }
        }
        else if (gCurrentPinballGame->unk28 > 20)
        {
            if (gCurrentPinballGame->unk28 > 77)
            {
                gCurrentPinballGame->unk2F4 = 9;

                if (gCurrentPinballGame->unk28 < 80)
                {
                    if (gCurrentPinballGame->unk2F6 != 0)
                    {
                        gCurrentPinballGame->unk2F6--;
                        gCurrentPinballGame->unk28++;
                    }
                }
            }
            else if (gCurrentPinballGame->unk28 > 72)
            {
                gCurrentPinballGame->unk2F4 = 10;
            }
            else if (gCurrentPinballGame->unk28 > 67)
            {
                gCurrentPinballGame->unk2F4 = 11;
            }
            else if (gCurrentPinballGame->unk28 > 44)
            {
                gCurrentPinballGame->unk2F4 = 12;
            }
            else if (gCurrentPinballGame->unk28 > 38)
            {
                gCurrentPinballGame->unk2F4 = 13;
            }
            else if (gCurrentPinballGame->unk28 > 28)
            {
                gCurrentPinballGame->unk2F4 = 14;
            }
            else if (gCurrentPinballGame->unk28 > 23)
            {
                gCurrentPinballGame->unk2F4 = 15;
            }
            else {
                gCurrentPinballGame->unk2F4 = 16;
            }
        }
        else if (gCurrentPinballGame->unk28 > 18)
        {
            gCurrentPinballGame->ball->positionQ0.x = 193;
            gCurrentPinballGame->ball->positionQ0.y = 226;
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk2F4 = 17;
        }
        else if (gCurrentPinballGame->unk28 > 16)
        {
            gCurrentPinballGame->unk1F = 0;
            gCurrentPinballGame->unk5FE = 0;
            gCurrentPinballGame->unk5FB = 1;
            gCurrentPinballGame->unk5FA = 0;
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->ball->velocity.x = 0xFF56;
            gCurrentPinballGame->ball->velocity.y = 220;
            gCurrentPinballGame->ball->positionQ0.x = 190;
            gCurrentPinballGame->ball->positionQ0.y = 232;
            gCurrentPinballGame->unk2F4 = 18;
            if (gCurrentPinballGame->unk28 == 18)
            {
                m4aSongNumStart(194);
                PlayRumble(7);
            }
        }
        else if (gCurrentPinballGame->unk28 > 12)
        {
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->unk2F4 = 19;
        }
        else if (gCurrentPinballGame->unk28 > 8)
        {
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->unk2F4 = 20;
        }
        else if (gCurrentPinballGame->unk28 > 4)
        {
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->unk2F4 = 21;
        }
        else
        {
            gCurrentPinballGame->unk2F4 = 22;
        }
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->ball->positionQ8.x= gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;

    }
    else
    {
        gCurrentPinballGame->unk26 = 30;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->unk25 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->unk2F4 = 0;
    }
}


void sub_1AD84(void)
{
    gCurrentPinballGame->scoreAddedInFrame = 100000;
    if (gCurrentPinballGame->unk2DA == 3)
    {
        gCurrentPinballGame->unk2DA = 4;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        PlayRumble(7);
        gCurrentPinballGame->unk28 = 500;
    }
    else if (gCurrentPinballGame->unk2D0 !=0)
    {
        gCurrentPinballGame->unk28 = 300;
    }
    else
    {
        gCurrentPinballGame->unk28 = 120;
    }

    gCurrentPinballGame->unk5F7 = 1;
}

void sub_1ADF4(void)
{
    u16 unk28 = gCurrentPinballGame->unk28;

    if (unk28 != 0)
    {
        gCurrentPinballGame->ball->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;

        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0x94;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        if (gCurrentPinballGame->unk2D0 != 1)
            return;
        if (gCurrentPinballGame->unk28 > 0xC8)
            return;

        if (gCurrentPinballGame->unk28 == 0xC8)
        {
            if (gCurrentPinballGame->unkE4 != 0)
                gCurrentPinballGame->unk28++;
            else
            {
                if (gCurrentPinballGame->scoreHi != 0 && gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                    sub_22978();
                else
                    sub_22C6C();
            }
        }
        else
        {
            if (gCurrentPinballGame->scoreHi != 0 && gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                sub_22A30();
            else
                sub_22D54();
        }
        if (gCurrentPinballGame->unk28 <= 9)
            gCurrentPinballGame->unk28++;
    }
    else
    {
        gCurrentPinballGame->ball->unk0 = unk28;
        gCurrentPinballGame->unk25 = unk28;

        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0xA2;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->unk5F7 = 0;

        if (gCurrentPinballGame->unk2D0 == 2)
        {
            gCurrentPinballGame->unk2DA = 3;
            gCurrentPinballGame->unk2DE = 0x30;
            gCurrentPinballGame->unk2E0 = 0x1E;
        }
        else
        {
            gCurrentPinballGame->unk1F = 0;
            gCurrentPinballGame->unk26 = 0x3C;
            gCurrentPinballGame->ball->velocity.x = 0x14;
            gCurrentPinballGame->ball->velocity.y = 0xC8;
        }
    }
}

void sub_1AF84(void)
{
    gCurrentPinballGame->unk1B8 = 0;
    gCurrentPinballGame->unk1B6 = 0;
    gCurrentPinballGame->unk28 = 0xB4;
    gCurrentPinballGame->unk1BA = 0xB4;
    gCurrentPinballGame->scoreAddedInFrame = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->unk5F7 = 1;
}

void sub_1AFD4(void)
{

    if (gCurrentPinballGame->unk28 > 0x18)
    {
        gCurrentPinballGame->ball->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xDC;
        gCurrentPinballGame->ball->positionQ0.y = 0x62;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x * 256;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y * 256;

        if (gCurrentPinballGame->unk28 > 0x9B)
            gCurrentPinballGame->unk2F0 = (gCurrentPinballGame->unk28 - 0x9C) / 8;
        if (gCurrentPinballGame->unk28 <= 0x31)
            gCurrentPinballGame->unk28++;

        sub_1B140(gCurrentPinballGame->unk1A5);
        return;
    }

    if (gCurrentPinballGame->unk28 > 0)
    {
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->unk2F0 = (0x18 - gCurrentPinballGame->unk28) / 8;
        return;
    }

    gCurrentPinballGame->ball->unk0 = 0;
    gCurrentPinballGame->unk1F = 0;
    gCurrentPinballGame->unk26 = 0x3C;

    gCurrentPinballGame->ball->velocity.x = 0x60;
    gCurrentPinballGame->ball->velocity.y = 0xC0;
    gCurrentPinballGame->ball->positionQ0.x = 0xDF;
    gCurrentPinballGame->ball->positionQ0.y = 0x63;

    gCurrentPinballGame->ball->unk6 = 0;
    gCurrentPinballGame->unk5F7 = 0;
    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
    gCurrentPinballGame->unk25 = 0;
    gCurrentPinballGame->unk2F0 = 0x13;

    m4aSongNumStart(SE_UNKNOWN_0xC3);

    if (gCurrentPinballGame->unk72E > 2 && gCurrentPinballGame->evolvablePartySize > 0)
    {
        sub_19B64(6);
    }
}

void sub_1B140(s16 arg0)
{
    int var_r7 = 0;

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->unk1BA != 0)
        gCurrentPinballGame->unk1BA--;

    if (arg0 == 0)
    {
        if (gCurrentPinballGame->unk1BA == 149)
        {
            m4aMPlayAllStop();
            gCurrentPinballGame->unk6DE = 0;
            gCurrentPinballGame->unk6DD = 0;
            gCurrentPinballGame->unk1AE = 0;
            gCurrentPinballGame->unk252 = 0;
            gMain.blendControl = 206;
            gMain.blendBrightness = 0;
        }

        if (gCurrentPinballGame->unk1BA == 146)
        {
            gCurrentPinballGame->unkE4 = 18;

            DmaCopy16(3, &gUnknown_084F61EC, OBJ_VRAM1 + 0x1C00, 0x940);
            DmaCopy16(3, &gUnknown_081B45A4, BG_PLTT + 0x180, 0x20);
        }

        if (gCurrentPinballGame->unk1BA >= 145 && gCurrentPinballGame->unk1BA < 150)
        {
            if (gCurrentPinballGame->unk1BA > 146)
            {
                gMain.blendBrightness = 4;

                if (gCurrentPinballGame->unk1BA <= 148)
                {
                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->unk6F = 1;
                    gCurrentPinballGame->unk70 = 0;
                }
            }
            else
            {
                gMain.blendBrightness = 7;

                if (gCurrentPinballGame->unk1BA <= 145)
                {
                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[2] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[2] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[2] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->unk6F = 2;
                    gCurrentPinballGame->unk70 = 0;
                }
            }
        }

        if (gCurrentPinballGame->unk1BA == 145)
        {
            m4aSongNumStart(MUS_SHOP);

            gCurrentPinballGame->unk1A6 = 0;
            gCurrentPinballGame->unk1A8 = 0;
            gCurrentPinballGame->unk1A7 = gUnknown_086AD2DE[gCurrentPinballGame->unk1A6];

            sub_1C7F4(6, 0);
            sub_21FBC(1);

            gMain.unk44[7]->available = 1;
            gMain.unk44[8]->available = 1;
            gMain.unk44[6]->available = 1;
            gMain.unk44[9]->available = 1;

            DmaCopy16(3, gUnknown_081B8784, OBJ_PLTT + 0x1C0, 0x20);
            DmaCopy16(3, gUnknown_081B8984, BG_VRAM + 0x2000, 0xC40);

            gMain.bgOffsets[0].yOffset = 80;
            gMain.unk2A = 0;
            gCurrentPinballGame->unk1B8 = 15;
            gMain.unk28 = 1;

            m4aSongNumStart(SE_UNKNOWN_0x8F);

            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->unk1AA = 1;
            else
                gCurrentPinballGame->unk1AA = 0;
        }

        if (gCurrentPinballGame->unk1BA <= 144)
        {
            gCurrentPinballGame->unk6E0 = 0;
            gCurrentPinballGame->unk6C4 = 2;
            gCurrentPinballGame->unk6DB = 0;
            var_r7 = 0;

            if (gCurrentPinballGame->unk1B8 > 0)
            {
                if (--gCurrentPinballGame->unk1B8 > 14)
                {
                    gCurrentPinballGame->unk1B6 = (30 - gCurrentPinballGame->unk1B8) * 7;

                    if (gCurrentPinballGame->unk1B8 == 15)
                    {
                        if (gCurrentPinballGame->unk1A6 == 3)
                        {
                            if (gCurrentPinballGame->ballUpgradeType <= BALL_UPGRADE_TYPE_ULTRA_BALL)
                                gCurrentPinballGame->unk1A7 = gCurrentPinballGame->ballUpgradeType + 10;
                            else
                                gCurrentPinballGame->unk1A7 = 12;
                        }
                        else if (gCurrentPinballGame->unk1A6 == 6)
                        {
                            if (gMain.selectedField == FIELD_RUBY)
                                gCurrentPinballGame->unk1A7 = 22;
                            else
                                gCurrentPinballGame->unk1A7 = 23;
                        }
                        else
                            gCurrentPinballGame->unk1A7 = gUnknown_086AD2DE[gCurrentPinballGame->unk1A6];

                        sub_1C7F4(6, 0);
                        var_r7 = 1;
                    }
                }
                else
                    gCurrentPinballGame->unk1B6 = gCurrentPinballGame->unk1B8 * 7;
            }
            else
            {
                if (JOY_NEW(DPAD_LEFT) && gCurrentPinballGame->unk6DD == 0)
                {
                    m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                    if (gCurrentPinballGame->unk1A6 > 0)
                        gCurrentPinballGame->unk1A6--;
                    else
                        gCurrentPinballGame->unk1A6 = 7;

                    gCurrentPinballGame->unk1A8 = 1;
                    gCurrentPinballGame->unk1B8 = 30;
                }

                if (JOY_NEW(DPAD_RIGHT))
                {
                    if (gCurrentPinballGame->unk6DD == 0)
                    {
                        m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                        if (gCurrentPinballGame->unk1A6 <= 6)
                            gCurrentPinballGame->unk1A6++;
                        else
                            gCurrentPinballGame->unk1A6 = 0;

                        gCurrentPinballGame->unk1A8 = 0;
                        gCurrentPinballGame->unk1B8 = 30;
                    }
                }
            }

            sub_21FBC(var_r7);

            if (gCurrentPinballGame->unk1A8 != 0)
            {
                if (gCurrentPinballGame->unk1A9 != 0)
                    gCurrentPinballGame->unk1A9--;
                else
                    gCurrentPinballGame->unk1A9 = 7;
            }
            else if (gCurrentPinballGame->unk1A9 < 7)
                gCurrentPinballGame->unk1A9++;
            else
                gCurrentPinballGame->unk1A9 = 0;

            DmaCopy16(3, gUnknown_086AD50C[gCurrentPinballGame->unk1A9 / 2], BG_VRAM + 0x2000, 0xC40);
            gMain.bgOffsets[0].yOffset = 80 - (4 * gMain.unk2A);

            if (gCurrentPinballGame->unk252 != 0)
            {
                if (gMain.unk2A > 0 && --gMain.unk2A == 0)
                {
                    gMain.unk28 = 0;
                    gMain.vCount = 144;
                }
            }
            else if (gMain.unk2A < 20)
                gMain.unk2A++;
        }

        if (gCurrentPinballGame->unk1B8 <= 0 && gMain.unk2A > 19)
        {
            if (JOY_NEW(A_BUTTON) && gCurrentPinballGame->unk6DD == 0)
            {
                s16 var_r3;
                const u16 *arr = gUnknown_086AD000[gCurrentPinballGame->unk1A7];

                if (gUnknown_086AD2DE[gCurrentPinballGame->unk1A6] == 3 && gCurrentPinballGame->outLanePikaPosition == 2)
                    var_r3 = 999;
                else if (gUnknown_086AD2DE[gCurrentPinballGame->unk1A6] == 4 && gCurrentPinballGame->unk1AF)
                    var_r3 = 999;
                else
                    var_r3 = arr[3];

                if (gCurrentPinballGame->coins >= var_r3)
                {
                    gCurrentPinballGame->unk6DD = 1;
                    gCurrentPinballGame->unk6DC = gCurrentPinballGame->unk1A7;
                    gCurrentPinballGame->coins -= var_r3;

                    m4aMPlayAllStop();
                    m4aSongNumStart(SE_EVO_SELECTION_CONFIRM);

                    gCurrentPinballGame->unk1AB = 19;
                    gCurrentPinballGame->unk376 = 30;
                }
                else
                    m4aSongNumStart(SE_FAILURE);
            }
            else if (JOY_NEW(B_BUTTON) && gCurrentPinballGame->unk6DD == 0)
            {
                gCurrentPinballGame->unk252 = 30;
                gCurrentPinballGame->unk1B8 = 30;
                m4aSongNumStart(SE_MENU_CANCEL);
            }
        }

        if (gCurrentPinballGame->unk6DD != 0)
        {
            sub_2A354();

            if (gCurrentPinballGame->unk6DE == 179)
            {
                gCurrentPinballGame->unk252 = 30;
                gCurrentPinballGame->unk1B8 = 30;

                if (gUnknown_086AD2DE[gCurrentPinballGame->unk1A6] == 4)
                    gCurrentPinballGame->unk1AF = 1;
            }
        }

        if (gCurrentPinballGame->unk252 != 0)
        {
            gCurrentPinballGame->unk252--;

            if (gCurrentPinballGame->unk1B8 <= 14)
                gCurrentPinballGame->unk1B8 = 15;

            if (gCurrentPinballGame->unk252 < 5)
            {
                if (gCurrentPinballGame->unk252 > 1)
                {
                    gMain.blendBrightness = 4;

                    if (gCurrentPinballGame->unk252 <= 3)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                        gCurrentPinballGame->unk6F = 1;
                        gCurrentPinballGame->unk70 = 1;
                    }
                }
                else
                {
                    gMain.blendBrightness = 0;

                    if (gCurrentPinballGame->unk252 == 0)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                        gCurrentPinballGame->unk6F = 0;
                        gCurrentPinballGame->unk70 = 1;
                    }
                }
            }

            if (gCurrentPinballGame->unk252 == 0)
            {
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

                if (gCurrentPinballGame->unk25 == 4)
                    gCurrentPinballGame->unk6DE = 170;
                else
                    gCurrentPinballGame->unk28 = 24;

                if (gCurrentPinballGame->unk13 == 2)
                    sub_1C7F4(1, 0);
                else
                    sub_1C7F4(0, 0);

                gCurrentPinballGame->unk6C4 = 0;
                gCurrentPinballGame->unk6DB = 3;
                gCurrentPinballGame->unk6DD = 0;

                gMain.unk44[7]->available = 0;
                gMain.unk44[8]->available = 0;
                gMain.unk44[6]->available = 0;
                gMain.unk44[9]->available = 0;

                gCurrentPinballGame->unkE4 = 0;
            }
        }
    }
    else
    {
        s16 evoTarget = 0;

        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->unk1BA == 149)
            {
                m4aMPlayAllStop();

                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->unkEA = 0;
                gCurrentPinballGame->unkEC = 120;
                gCurrentPinballGame->unkE8 = 0;
                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unkEE = 0;
                gCurrentPinballGame->unkF2 = 3;
                gCurrentPinballGame->unkFA = 1;
                gCurrentPinballGame->unkFB = 0;
                gCurrentPinballGame->unkF4 = 80;
                gCurrentPinballGame->unkF6 = 0xF63C; //-2500
                gCurrentPinballGame->unkF0 = 50;
                gCurrentPinballGame->unkF8 = 0;

                DmaCopy16(3, gUnknown_086ACEF8[3], OBJ_VRAM1 + 0x1800, 0x2400);
                DmaCopy16(3, gUnknown_086ACF18[3], OBJ_PLTT + 0x1C0, 0x20);

                gMain.blendControl = 206;
                gCurrentPinballGame->unk1BA = 148;
                gCurrentPinballGame->evolvingPartyIndex = 0;
                gCurrentPinballGame->unk1A6 = 0;
                gCurrentPinballGame->unk25C = 0;
                gCurrentPinballGame->unk1B0 = 0;
                gCurrentPinballGame->unk1B2 = 0;
            }

            if (gCurrentPinballGame->unk1BA == 146)
            {
                gCurrentPinballGame->unkE4 = 18;

                DmaCopy16(3, &gUnknown_084F61EC, OBJ_VRAM1 + 0x1C00, 0x940);
                DmaCopy16(3, &gUnknown_081B4584, PLTT + 0x180, 0x20);
            }

            if (gCurrentPinballGame->unk1BA == 145)
            {
                int stage1Evo;
                int stage2Evo;
                gCurrentPinballGame->unk1A8 = 0;
                gCurrentPinballGame->currentSpecies = gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvingPartyIndex];
                gCurrentPinballGame->unk25D = 0;
                stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                if (stage1Evo < SPECIES_NONE)
                {
                    gCurrentPinballGame->unk25D++;
                    stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;
                    if (stage2Evo < SPECIES_NONE)
                        gCurrentPinballGame->unk25D++;

                }

                sub_22FA4();

                if (gMain.selectedField == FIELD_RUBY)
                    m4aSongNumStart(MUS_EVO_MODE);
                else
                    m4aSongNumStart(MUS_EVO_MODE2);

                sub_21FBC(var_r7);

                gMain.unk44[8]->available = 1;
                gMain.unk44[9]->available = 1;
                gMain.unk44[6]->available = 1;

                DmaCopy16(3, &gUnknown_081B8784, PLTT + 0x3C0, 0x20);

                gMain.bgOffsets[0].yOffset = 80;
                gMain.unk2A = 0;
                gCurrentPinballGame->unk1B8 = 15;
                gMain.unk28 = 1;

                DmaCopy16(3, &gUnknown_081B4784, VRAM + 0x2000, 0xC40);
            }

            if (gCurrentPinballGame->unk1BA <= 144)
            {
                gCurrentPinballGame->unk6E0 = 0;
                gCurrentPinballGame->unk6C4 = 2;
                gCurrentPinballGame->unk6DB = 0;

                if (gCurrentPinballGame->unk1B8 > 0)
                {
                    gCurrentPinballGame->unk1B8--;

                    if (gCurrentPinballGame->unk1B0 != 0)
                    {
                        if (gCurrentPinballGame->unk1B8 == 15)
                            sub_22FA4();
                    }
                    else
                    {
                        if (gCurrentPinballGame->unk1B8 > 14)
                        {
                            gCurrentPinballGame->unk1B6 = (30 - gCurrentPinballGame->unk1B8) * 7;

                            if (gCurrentPinballGame->unk1B8 == 15)
                                sub_22FA4();
                        }
                        else
                            gCurrentPinballGame->unk1B6 = gCurrentPinballGame->unk1B8 * 7;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->evolvablePartySize > 1)
                    {
                        if (JOY_NEW(DPAD_LEFT))
                        {
                            int stage1Evo;
                            int stage2Evo;

                            m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                            if (gCurrentPinballGame->evolvingPartyIndex > 0)
                                gCurrentPinballGame->evolvingPartyIndex--;
                            else
                                gCurrentPinballGame->evolvingPartyIndex = gCurrentPinballGame->evolvablePartySize - 1;

                            gCurrentPinballGame->currentSpecies = gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvingPartyIndex];
                            gCurrentPinballGame->unk1A8 = 1;
                            gCurrentPinballGame->unk1B8 = 30;
                            gCurrentPinballGame->unk25C = 0;
                            gCurrentPinballGame->unk1B0 = 0;
                            gCurrentPinballGame->unk25D = 0;
                            stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (stage1Evo < SPECIES_NONE)
                            {
                                gCurrentPinballGame->unk25D++;
                                stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;

                                if (stage2Evo < SPECIES_NONE)
                                    gCurrentPinballGame->unk25D++;
                            }
                        }
                        else if (JOY_NEW(DPAD_RIGHT))
                        {
                            int stage1Evo;
                            int stage2Evo;

                            m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                            if (gCurrentPinballGame->evolvingPartyIndex < gCurrentPinballGame->evolvablePartySize - 1)
                                gCurrentPinballGame->evolvingPartyIndex++;
                            else
                                gCurrentPinballGame->evolvingPartyIndex = 0;

                            gCurrentPinballGame->currentSpecies = gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvingPartyIndex];
                            gCurrentPinballGame->unk1A8 = 0;
                            gCurrentPinballGame->unk1B8 = 30;
                            gCurrentPinballGame->unk25C = 0;
                            gCurrentPinballGame->unk1B0 = 0;
                            gCurrentPinballGame->unk25D = 0;
                            stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (stage1Evo < SPECIES_NONE)
                            {
                                gCurrentPinballGame->unk25D++;
                                stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;

                                if (stage2Evo < SPECIES_NONE)
                                    gCurrentPinballGame->unk25D++;
                            }
                        }
                    }

                    if (JOY_NEW(DPAD_UP))
                    {
                        if (gCurrentPinballGame->unk25C == 0)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->unk59A = evoTarget;
                                gCurrentPinballGame->unk1B8 = 30;
                                gCurrentPinballGame->unk1B0 = 1;
                                gCurrentPinballGame->unk25C++;
                            }
                        }
                        else if (gCurrentPinballGame->unk25C == 1)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->unk59A].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->unk59A = evoTarget;
                                gCurrentPinballGame->unk1B8 = 30;
                                gCurrentPinballGame->unk1B0 = 1;
                                gCurrentPinballGame->unk25C++;
                            }
                        }

                        gCurrentPinballGame->unk1B2 = 0;
                    }
                    else if (JOY_NEW(DPAD_DOWN))
                    {
                        if (gCurrentPinballGame->unk25C == 1)
                        {
                            evoTarget = gCurrentPinballGame->currentSpecies;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->unk59A = evoTarget;
                                gCurrentPinballGame->unk1B8 = 30;
                                gCurrentPinballGame->unk1B0 = 1;
                                gCurrentPinballGame->unk25C--;
                            }
                        }
                        else if (gCurrentPinballGame->unk25C == 2)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->unk59A = evoTarget;
                                gCurrentPinballGame->unk1B8 = 30;
                                gCurrentPinballGame->unk1B0 = 1;
                                gCurrentPinballGame->unk25C--;
                            }
                        }

                        gCurrentPinballGame->unk1B2 = 0;
                    }

                    if (gCurrentPinballGame->unk25C > 0)
                    {
                        switch (gCurrentPinballGame->unk59A)
                        {
                        case 14:
                            if (gCurrentPinballGame->unk1B2 == 50)
                            {
                                gCurrentPinballGame->unk1B2 = 0;
                                gCurrentPinballGame->unk59A = 16;
                                sub_22FA4();
                            }
                            break;
                        case 16:
                            if (gCurrentPinballGame->unk1B2 == 50)
                            {
                                gCurrentPinballGame->unk1B2 = 0;
                                gCurrentPinballGame->unk59A = 14;
                                sub_22FA4();
                            }
                            break;
                        case 89:
                            if (gCurrentPinballGame->unk1B2 == 50)
                            {
                                gCurrentPinballGame->unk1B2 = 0;
                                gCurrentPinballGame->unk59A = 90;
                                sub_22FA4();
                            }
                            break;
                        case 90:
                            if (gCurrentPinballGame->unk1B2 == 50)
                            {
                                gCurrentPinballGame->unk1B2 = 0;
                                gCurrentPinballGame->unk59A = 89;
                                sub_22FA4();
                            }
                            break;
                        case 176:
                            if (gCurrentPinballGame->unk1B2 == 50)
                            {
                                gCurrentPinballGame->unk1B2 = 0;
                                gCurrentPinballGame->unk59A = 177;
                                sub_22FA4();
                            }
                            break;
                        case 177:
                            if (gCurrentPinballGame->unk1B2 == 50)
                            {
                                gCurrentPinballGame->unk1B2 = 0;
                                gCurrentPinballGame->unk59A = 176;
                                sub_22FA4();
                            }
                            break;
                        }

                        gCurrentPinballGame->unk1B2++;
                    }
                }

                sub_23070();

                if (gCurrentPinballGame->unk1A8 != 0)
                {
                    if (gCurrentPinballGame->unk1A9 != 0)
                        gCurrentPinballGame->unk1A9--;
                    else
                        gCurrentPinballGame->unk1A9 = 7;
                }
                else
                {
                    if (gCurrentPinballGame->unk1A9 <= 6)
                        gCurrentPinballGame->unk1A9++;
                    else
                        gCurrentPinballGame->unk1A9 = 0;
                }

                DmaCopy16(3, gUnknown_086AD50C[gCurrentPinballGame->unk1A9 / 2 + 4], VRAM + 0x2000, 0xC40);
                gMain.bgOffsets[0].yOffset = 80 - (gMain.unk2A * 4);

                if (gCurrentPinballGame->unk252 != 0)
                {
                    if (gMain.unk2A > 0 && --gMain.unk2A == 0)
                    {
                        gMain.unk28 = 0;
                        gMain.vCount = 144;
                    }
                }
                else if (gMain.unk2A <= 19)
                    gMain.unk2A++;

                sub_21FBC(0);
            }

            if (gCurrentPinballGame->unk1B8 <= 0 && gMain.unk2A > 19 && JOY_NEW(A_BUTTON) == A_BUTTON)
            {
                gCurrentPinballGame->unk252 = 30;
                gCurrentPinballGame->unk1B0 = 0;
                gCurrentPinballGame->unk1B8 = 30;
                m4aSongNumStart(SE_EVO_SELECTION_CONFIRM);
            }

            if (gCurrentPinballGame->unk252 == 0)
                return;

            gCurrentPinballGame->unk252--;

            if (gCurrentPinballGame->unk1B8 <= 14)
                gCurrentPinballGame->unk1B8 = 15;

            if (gCurrentPinballGame->unk252 <= 4)
            {
                if (gCurrentPinballGame->unk252 > 1)
                {
                    gMain.blendBrightness = 4;

                    if (gCurrentPinballGame->unk252 <= 3)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                        gCurrentPinballGame->unk6F = 1;
                        gCurrentPinballGame->unk70 = 1;
                    }
                }
                else
                {
                    gMain.blendBrightness = 0;

                    if (gCurrentPinballGame->unk252 != 0)
                        return;

                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0], OBJ_PLTT, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gUnknown_02031520.unk14.unk2C[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->unk6F = 0;
                    gCurrentPinballGame->unk70 = 1;
                }
            }

            if (gCurrentPinballGame->unk252 == 0)
            {
                if (gCurrentPinballGame->unk25 == 4)
                    gCurrentPinballGame->unk6DE = 170;
                else
                    gCurrentPinballGame->unk28 = 24;

                gCurrentPinballGame->unk6C4 = 0;
                gCurrentPinballGame->unk6DB = 3;

                gMain.unk44[8]->available = 0;
                gMain.unk44[6]->available = 0;
                gMain.unk44[9]->available = 0;

                gCurrentPinballGame->unk720 = 0;
                gCurrentPinballGame->unk71D[0] = 4;
                gCurrentPinballGame->unk71D[1] = 4;
                gCurrentPinballGame->unk71D[2] = 4;

                sub_2310C();
                gCurrentPinballGame->unkE4 = 0;
            }
        }
        else if (gCurrentPinballGame->unk1BA == 50)
            gCurrentPinballGame->unk28 = 24;

    }
}

void sub_1C560(void)
{
    gCurrentPinballGame->unk28 = 0x96;
    gMain.unk44[13]->available = 0;
    gCurrentPinballGame->unk5F3 = 0;
    gCurrentPinballGame->scoreAddedInFrame = 10000;
    gCurrentPinballGame->unk5F7 = 1;
    PlayRumble(8);
}

void sub_1C5AC(void)
{
    if (gCurrentPinballGame->unk28)
    {
        gCurrentPinballGame->unk28--;
        if (gCurrentPinballGame->unk28 > 148)
        {
            gCurrentPinballGame->ball->unk0 = 1;
            gCurrentPinballGame->unk1F = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->positionQ0.x = 119;
            gCurrentPinballGame->ball->positionQ0.y = 279;
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            gCurrentPinballGame->unk730 = 1;
        }
        else if (gCurrentPinballGame->unk28 == 148)
        {
            gCurrentPinballGame->unk1F = 1;
            gCurrentPinballGame->unk730 = 0;
        }
        else if (gCurrentPinballGame->unk28 > 36)
        {
            gCurrentPinballGame->unk1F = 1;
            gCurrentPinballGame->unk730 = 0;
        }
        else if (gCurrentPinballGame->unk28 > 24)
        {
            gCurrentPinballGame->unk1F = 1;
            gCurrentPinballGame->unk730 = 1;
        }
        else if (gCurrentPinballGame->unk28 == 24)
        {
            m4aSongNumStart(SE_UNKNOWN_0x80);
            gCurrentPinballGame->unk730 = 2;
            gCurrentPinballGame->ball->velocity.x = 73;
            gCurrentPinballGame->ball->velocity.y = 236;
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk1F = 0;
            gCurrentPinballGame->unk5FA = 0;
            gCurrentPinballGame->ball->scale = 0x88;
            gCurrentPinballGame->unk5F7 = 0;
        }
        else if (gCurrentPinballGame->unk28 > 12)
        {
            gCurrentPinballGame->unk730 = 2;
            if (gCurrentPinballGame->unk28 > 21)
                gCurrentPinballGame->ball->scale = ((24 - gCurrentPinballGame->unk28) * 0x70 / 3) + 0x90;
            else
                gCurrentPinballGame->ball->scale = 0x100;
        }
        else
        {
            gCurrentPinballGame->unk730 = 1;
        }
        if (gCurrentPinballGame->unk28 <= 40)
        {
            if (gCurrentPinballGame->unkE6 > 0)
            {
                gCurrentPinballGame->unkE6--;
            }
        }
    }
    else
    {
        gCurrentPinballGame->unk730 = 0;
        gCurrentPinballGame->unk25 = 0;
    }
}

void sub_1C73C(void)
{
    gMain.unk44[13]->available = 0;
    sub_4B408(0);
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->unk0 = 0;
    gCurrentPinballGame->unk1F = 0;
    gCurrentPinballGame->ball->scale = 0x100;
    gCurrentPinballGame->unk730 = 0;
    gCurrentPinballGame->unk25 = 0;
    if (gCurrentPinballGame->unk282 == 0)
    {
        gCurrentPinballGame->unk723 = 0;
        gCurrentPinballGame->unk720 = 0;
        gCurrentPinballGame->unk71D[0] = 0;
        gCurrentPinballGame->unk71D[1] = 0;
        gCurrentPinballGame->unk71D[2] = 0;
    }
    m4aMPlayAllStop();
    sub_0D10();
    gMain.unk5 = gMain.selectedField;
    gMain.selectedField = gCurrentPinballGame->unk284;
    gMain.unk6 = 1;
    gMain.subState = 0;
}