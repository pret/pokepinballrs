#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern const u16 gUnknown_08254B10[];
extern const u16 gUnknown_08257390[];
extern const u16 gUnknown_08259C10[];

extern struct SongHeader se_unk_99;
extern u16 gUnknown_086ACE70[];


s16 COLLISION_CHECK_RUBY_14E08(struct Vector16 *arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 unk0;
    s32 unk1;
    s32 unk2;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    unk1 = vec1.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    vec1.y %= 64;

    unk0 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
    sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];

    sub_15054(arg0, &sp00, &sp02);

    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum-1) {
    case 0:
    case 3:
    case 5:
        gCurrentPinballGame->unk23 = (switch_enum - 1);
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;

        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gUnknown_02031520.unk14.unk26 - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk14.unk28 - 8)
            {

                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 0x28;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = 0xFFD8;
                        gCurrentPinballGame->ball->unk6 = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 1:
    case 2:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;

        break;
    case 4:
        gCurrentPinballGame->unk2A2 = 2;
        gCurrentPinballGame->unk1F = 1;
        some_enum = 0;
        break;
    }
    sub_153CC((s32) some_enum, &return_val, arg1);

    return return_val;
}


void sub_15054(struct Vector16* arg0, u16* arg1, u8* arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    s32 ix;

    maskedResult = 0;
    lowerNibble = 0;
    ix = 0;

    if (gCurrentPinballGame->unk5B2 == 0)
    {
        if (gCurrentPinballGame->unk24 != 0)
            return;

        if (gCurrentPinballGame->unk2A4 != 0)
        {
            if (gCurrentPinballGame->unk2A3 == 0)
                return;

            deltaX = arg0->x + gCurrentPinballGame->unk184[0].x;
            deltaY = arg0->y + gCurrentPinballGame->unk184[0].y;

            if (deltaX > 79U)
                return;

            if (deltaY > 87U)
                return;

            maskedResult = 0xFFF0 & gUnknown_08259C10[(deltaY * 80) + deltaX];
            lowerNibble = 0xF & gUnknown_08259C10[(deltaY * 80) + deltaX];

            if (lowerNibble == 0)
                return;

            *arg1 = maskedResult;

            if (gCurrentPinballGame->unk2A2 <= 1)
            {
                *arg2 = lowerNibble;
                gCurrentPinballGame->unk2A2 = 7;
                return;
            }

            *arg2 = 1;
            return;
        }

        if (0xF & *arg2)
            return;

        deltaX = arg0->x + (u16) gCurrentPinballGame->unk184[0].x;
        deltaY = arg0->y + (u16) gCurrentPinballGame->unk184[0].y;

        if (deltaX <= 63U && deltaY <= 63U)
        {
            maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
            lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];

            if (lowerNibble != 0)
                ix = 0;
        }

        if (lowerNibble == 0)
        {
            deltaX = gCurrentPinballGame->unk184[1].x + arg0->x;
            deltaY = gCurrentPinballGame->unk184[1].y + arg0->y;

            if (deltaX <= 63U && deltaY <= 63U)
            {
                maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                if (lowerNibble != 0)
                    ix = 1;
            }

            if (lowerNibble == 0)
            {
                deltaX = gCurrentPinballGame->unk184[2].x + arg0->x;
                deltaY = gCurrentPinballGame->unk184[2].y + arg0->y;

                if (deltaX <= 63U && deltaY <= 63U)
                {
                    maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];

                    if (lowerNibble == 0)
                        return;

                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }

        if (gCurrentPinballGame->unk16F == 0)
            gCurrentPinballGame->unk170[ix] = 107;

        *arg1 = maskedResult;
        *arg2 = lowerNibble;

        if (gCurrentPinballGame->unk624 > 0)
            return;

        gCurrentPinballGame->unk624 = 2;
    }
    else
    {
        if ((*arg2 & 0xF) == 0)
        {
            if (gCurrentPinballGame->unk2E5[0] > 0)
            {
                s16 deltaY_alt;
                deltaX = 2 * (-24 -gCurrentPinballGame->unk2EC[0]) + arg0->x;
                deltaY_alt = arg0->y -580;

                if (deltaX <= 71U && deltaY_alt <= 71U)
                {
                    *arg1 = 0xFFF0 & gUnknown_08254B10[(deltaY_alt * 72) + deltaX];
                    *arg2 = 0xF & gUnknown_08254B10[(deltaY_alt * 72) + deltaX];

                    if (*arg2 & 1)
                    {
                        gCurrentPinballGame->unk2E2 = 1;
                        *arg2 = 6;
                    }
                }
            }

            if (gCurrentPinballGame->unk2E5[1] > 0)
            {
                deltaX = ((gCurrentPinballGame->unk2EC[1] - 180) * 2) + arg0->x;
                deltaY = arg0->y -580;

                if (deltaX <= 71U && deltaY <= 71U)
                {
                    *arg1 = 0xFFF0 & gUnknown_08257390[(deltaY * 72) + deltaX];
                    *arg2 = 0xF & gUnknown_08257390[(deltaY * 72) + deltaX];

                    if (*arg2 & 1)
                    {
                        gCurrentPinballGame->unk2E2 = 2;
                        *arg2 = 6;
                        return;
                    }
                }
            }
        }
    }
}

void sub_153CC(s32 arg0, s16* arg1, u16* arg2)
{
    s16 absVelY;

    switch ((u8)arg0 - 1)
    {
    case 0:
        if (gCurrentPinballGame->unk26 == 0)
        {
            if (gCurrentPinballGame->ball->positionQ1.x > 359)
            {
                if (gCurrentPinballGame->ball->positionQ1.y > 199)
                    gCurrentPinballGame->unk25 = 1;
                else
                    gCurrentPinballGame->unk25 = 3;
            }
            else
                gCurrentPinballGame->unk25= 2;

            sub_1A98C();
            gCurrentPinballGame->unk22 = 7;
            *arg1 = 1;
            return;
        }
    default:
        return;
    case 1:
        if (gCurrentPinballGame->unk24 == 0)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->unk24 = 2;
            break;
        }

        if (gCurrentPinballGame->unk24 == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->unk24 = 3;
        }

        break;
    case 2:
        if (gCurrentPinballGame->unk24 == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 3;
            gCurrentPinballGame->unk24 = 0;
        }
        else if (gCurrentPinballGame->unk24 == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->unk24 = 2;
        }

        if (gCurrentPinballGame->unk2FB == 6)
            gCurrentPinballGame->unk2FB = 7;

        if (gCurrentPinballGame->unk2F0 & 0xF0 )
            gCurrentPinballGame->unk2F0 = 0;

        if (gCurrentPinballGame->unk1AB & 0xF0)
            gCurrentPinballGame->unk1AB = 0;

        break;
    case 3:
        if (gCurrentPinballGame->unk600 == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 131)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;

                if (gCurrentPinballGame->unk70E <= 98)
                    gCurrentPinballGame->unk70E++;
            }
            else if (gCurrentPinballGame->ball->positionQ0.x > 91)
            {
                gCurrentPinballGame->scoreAddedInFrame = 2000;
                gCurrentPinballGame->unk174 = 0;
                gCurrentPinballGame->unk16F = 1;
            }
            else
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;

                if (gCurrentPinballGame->unk2B2 == 0)
                {
                    gCurrentPinballGame->unk2B2 = 1;
                    gCurrentPinballGame->unk2B0 = 0;
                }
            }
            gCurrentPinballGame->unk600 = 45;

            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
        }
        break;
    case 4:
        gCurrentPinballGame->unk20 = 1;
        gCurrentPinballGame->unk165 = 1;
        gCurrentPinballGame->unk732 = 0;
        return;
    case 5:
        if (gCurrentPinballGame->unk5B2 == 0)
        {
            sub_46FD4(1);
            gCurrentPinballGame->unk29E = 1;
        }
        break;
    case 6:
        if (gCurrentPinballGame->ball->positionQ0.x < 50)
        {
            if (gCurrentPinballGame->unk2FA == 0)
            {
                gCurrentPinballGame->unk2FA = 1;
                gCurrentPinballGame->unk2FB = 1;
                gCurrentPinballGame->unk23 = 0;
                gCurrentPinballGame->unk22 = 2;
                *arg2 = 0xB000;
                *arg1 = 1;
            }
        }
        else if (gCurrentPinballGame->unk2FA == 1)
        {
            gCurrentPinballGame->unk2FA = 2;
            gCurrentPinballGame->unk2FB = 3;
            gCurrentPinballGame->unk23 = 0;
            gCurrentPinballGame->unk22 = 2;
            *arg2 = 0xA000;
            *arg1 = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;

            memcpy(&gCurrentPinballGame->unk1334[1], gCurrentPinballGame->unk1334, 0x44U);

            gCurrentPinballGame->unk1330 = &gCurrentPinballGame->unk1334[1];
            gCurrentPinballGame->unk1328 = 120;
        }

        gCurrentPinballGame->unk732 = 14;
        return;
    case 7:
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            if (gCurrentPinballGame->unk732 == 8)
            {
                if (gCurrentPinballGame->unk13 <= 2 && gCurrentPinballGame->unk72E <= 2)
                {
                    if (gCurrentPinballGame->unk72E == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->unk72E == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->unk72E++;

                    m4aSongNumStart(SE_UNKNOWN_0x99);
                }

                gCurrentPinballGame->unk6BC = 1;
            }
            gCurrentPinballGame->unk732 = 2;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            if (gCurrentPinballGame->unk732 == 7)
            {
                gCurrentPinballGame->unk194 = 10;

                if(gCurrentPinballGame->unk72B <= 2)
                {
                    if(gCurrentPinballGame->unk72B == 0)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                        gCurrentPinballGame->unk194 = 1;
                    }
                    else if(gCurrentPinballGame->unk72B == 1)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                        gCurrentPinballGame->unk194 = 5;
                    }
                    else
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 10000;
                        gCurrentPinballGame->unk194 = 10;
                    }
                    gCurrentPinballGame->unk72B++;
                }

                gCurrentPinballGame->unk196 = 0;
                gCurrentPinballGame->unk72C = 0;
            }

            gCurrentPinballGame->unk732 = 1;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 126)
        {
            if (gCurrentPinballGame->ballPowerUpLight[0] == 0)
                gCurrentPinballGame->scoreAddedInFrame = 1000;

            gCurrentPinballGame->ballPowerUpLight[0] = 1;
            gCurrentPinballGame->unk732 = 3;

            if (gCurrentPinballGame->unk71B == 0)
            {
                if (!(gCurrentPinballGame->ballPowerUpLight[1] &
                      gCurrentPinballGame->ballPowerUpLight[2]))
                    return;

                gCurrentPinballGame->unk71B = 1;
                gCurrentPinballGame->unk71C = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }
        }
        else
        {
            if (gCurrentPinballGame->ball->positionQ0.x <= 148)
            {
                if (gCurrentPinballGame->ballPowerUpLight[1] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;

                gCurrentPinballGame->ballPowerUpLight[1] = 1;
                gCurrentPinballGame->unk732 = 4;

                if (gCurrentPinballGame->unk71B != 0)
                    return;

                if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                      gCurrentPinballGame->ballPowerUpLight[2]))
                    return;

                gCurrentPinballGame->unk71B = 1;
                gCurrentPinballGame->unk71C = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }

            if (gCurrentPinballGame->ball->positionQ0.x <= 172)
            {
                if (gCurrentPinballGame->ballPowerUpLight[2] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;

                gCurrentPinballGame->ballPowerUpLight[2] = 1;
                gCurrentPinballGame->unk732 = 5;

                if (gCurrentPinballGame->unk71B != 0)
                    return;

                if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                      gCurrentPinballGame->ballPowerUpLight[1]))
                    return;

                gCurrentPinballGame->unk71B = 1;
                gCurrentPinballGame->unk71C = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }

            if (gCurrentPinballGame->unk732 == 9)
            {
                if (gCurrentPinballGame->unk13 <= 2 && gCurrentPinballGame->unk72F <= 2)
                {
                    if (gCurrentPinballGame->unk72F == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->unk72F == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->unk72F++;

                    MPlayStart(&gMPlayInfo_SE1, &se_unk_99);

                    if (gCurrentPinballGame->unk72F > 1)
                        gCurrentPinballGame->unk731 = 1;
                }

                gCurrentPinballGame->unk6BC = 2;
            }

            gCurrentPinballGame->unk732 = 6;
            return;
        }
        break;
    case 8:
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            gCurrentPinballGame->unk732 = 8;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            gCurrentPinballGame->unk732 = 7;
            return;
        }

        gCurrentPinballGame->unk732 = 9;
        return;
    case 9:
        if (gCurrentPinballGame->ball->positionQ0.x <= 46)
        {
            gCurrentPinballGame->unk732 = 10;

            if (gCurrentPinballGame->holeIndicators[0] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[0] = 1;

            if (gCurrentPinballGame->unk714 != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->unk714 = 1;
            gCurrentPinballGame->unk715 = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 120)
        {
            gCurrentPinballGame->unk732 = 11;

            if (gCurrentPinballGame->holeIndicators[1] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[1] = 1;

            if (gCurrentPinballGame->unk714 != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->unk714 = 1;
            gCurrentPinballGame->unk715 = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        if (gCurrentPinballGame->ball->positionQ0.x <= 193)
        {
            gCurrentPinballGame->unk732 = 12;

            if (gCurrentPinballGame->holeIndicators[2] != 0)
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[2] = 1;

            if (gCurrentPinballGame->unk714 != 0)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->unk714 = 1;
            gCurrentPinballGame->unk715 = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }

        gCurrentPinballGame->unk732 = 13;

        if (gCurrentPinballGame->holeIndicators[3] != 0)
            return;

        gCurrentPinballGame->scoreAddedInFrame = 1000;
        gCurrentPinballGame->holeIndicators[3] = 1;

        if (gCurrentPinballGame->unk714 != 0)
            return;

        if (!(gCurrentPinballGame->holeIndicators[0] &
              gCurrentPinballGame->holeIndicators[1] &
              gCurrentPinballGame->holeIndicators[2]))
            return;

        gCurrentPinballGame->unk714 = 1;
        gCurrentPinballGame->unk715 = 126;
        gCurrentPinballGame->scoreAddedInFrame = 4000;
        return;
    case 10:
        if (gCurrentPinballGame->unk5B2 == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 170)
            {
                if (gCurrentPinballGame->unk2F0 > 2U)
                    return;

                gCurrentPinballGame->unk23 = 0;
                gCurrentPinballGame->unk22 = 2;
                *arg2 = 0xB000;
                *arg1 = 1;

                if (gCurrentPinballGame->unk13 <= 2 && gCurrentPinballGame->unk1AB <= 2)
                {
                    gCurrentPinballGame->unk1AB = 3;
                    gCurrentPinballGame->unk2F2 = 5;
                }

                gCurrentPinballGame->scoreAddedInFrame = 50000;
                return;
            }

            if (gCurrentPinballGame->unk2FB <= 4)
            {
                gCurrentPinballGame->unk23 = 0;
                gCurrentPinballGame->unk22 = 2;
                *arg2 = 0xF800;
                *arg1 = 1;
            }

            if (gCurrentPinballGame->unk2FB == 5)
                gCurrentPinballGame->unk2FB = 6;

            if (gCurrentPinballGame->unk29F == 0)
                return;

            if (gCurrentPinballGame->unk29F == 1)
                gCurrentPinballGame->unk286 = 90;
            else
            {
                gCurrentPinballGame->unk2F8 = 1;
                gCurrentPinballGame->unk71B = 1;
                gCurrentPinballGame->unk71C = 60;
                m4aSongNumStart(SE_UNKNOWN_0xD8);
            }

            gCurrentPinballGame->unk29F = 0;
            gCurrentPinballGame->unk2A0 = 600;
            return;
        }

        if (gCurrentPinballGame->unk1C4 != 0)
            return;

        if (gCurrentPinballGame->ball->positionQ0.x <= 120)
            gCurrentPinballGame->unk1C2 = 1;
        else
            gCurrentPinballGame->unk1C2 = 2;

        if (gCurrentPinballGame->outLanePikaPosition <= 1)
        {
            if (gCurrentPinballGame->outLanePikaPosition != gCurrentPinballGame->unk1C2 - 1)
                return;
            else
                gCurrentPinballGame->unk1C4 = 120;
            return;
        }

        gCurrentPinballGame->unk1C4 = 120;
        return;

    case 11:
        if (gCurrentPinballGame->unk616 != 0)
            return;

        absVelY = gCurrentPinballGame->ball->velocity.y;
        gCurrentPinballGame->unk614 = gCurrentPinballGame->ball->velocity.y;

        if (absVelY < 0) {
            absVelY = -absVelY;
        }

        gCurrentPinballGame->unk1C6 += (absVelY) / 3;

        if (gCurrentPinballGame->unk1C6 > 168)
            gCurrentPinballGame->unk1C6 = 168;

        gCurrentPinballGame->unk616 = 20;
        return;
    case 12:
        if (gCurrentPinballGame->unk2D8 == 0)
            return;

        if (gCurrentPinballGame->unk26 != 0)
            return;

        if (gCurrentPinballGame->unk2DA != 0)
            return;

        gCurrentPinballGame->unk2DA++;

        gCurrentPinballGame->unk2D8 = 0;
        gCurrentPinballGame->unk23 = 0;
        gCurrentPinballGame->unk22 = 2;

        *arg2 = 0xD000;
        *arg1 = 1;
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        sub_11B0(7);
        return;
    case 13:
        if (gCurrentPinballGame->unk2D8 == 0)
            return;

        if (gCurrentPinballGame->unk26 != 0)
            return;

        if (gCurrentPinballGame->unk2DA != 1)
            return;

        gCurrentPinballGame->unk2DA++;
        gCurrentPinballGame->unk2D8 = 0;
        gCurrentPinballGame->unk23 = 0;
        gCurrentPinballGame->unk22 = 2;
        *arg2 = 0xCC00;
        *arg1 = 1;

        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        sub_11B0(7);
        return;
    case 14:
        if ((gCurrentPinballGame->unk13 > 2) && (gCurrentPinballGame->unk13 != 5))
        {
            if (gCurrentPinballGame->unk2E0 == 0)
            {
                if (gCurrentPinballGame->unk2DA == 2)
                {
                    gCurrentPinballGame->unk23 = 0;
                    gCurrentPinballGame->unk22 = 2;
                    *arg2 = 0xC800;
                    *arg1 = 1;
                    gCurrentPinballGame->unk2DA++;

                    m4aSongNumStart(SE_UNKNOWN_0xB7);
                    gCurrentPinballGame->scoreAddedInFrame = 5000;
                    sub_11B0(7);
                    return;
                }
                else if (gCurrentPinballGame->unk2DA == 3)
                {
                    gCurrentPinballGame->unk23 = 0;
                    gCurrentPinballGame->unk22 = 2;
                    *arg2 = 0xC800;
                    *arg1 = 1;

                    m4aSongNumStart(SE_UNKNOWN_0xB7);
                    gCurrentPinballGame->unk2D9 = 1;
                    sub_11B0(7);
                    return;
                }
            }
        }
        else if (gCurrentPinballGame->unk2D8 != 0 && gCurrentPinballGame->unk2DA == 2)
        {
            gCurrentPinballGame->unk2DA++;
            gCurrentPinballGame->unk2D8 = 0;
            gCurrentPinballGame->unk23 = 0;
            gCurrentPinballGame->unk22 = 2;
            *arg2 = 0xC800;
            *arg1 = 1;

            m4aSongNumStart(SE_UNKNOWN_0xB7);
            gCurrentPinballGame->scoreAddedInFrame = 5000;
            sub_11B0(7);
        }

        break;
    }
}


s16 COLLISION_CHECK_SAPPHIRE_16090(struct Vector16 *arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 unk0;
    s32 unk1;
    s32 unk2;

    u32 some_enum;
    u8 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    unk1 = vec1.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    vec1.y %= 64;

    unk0 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
    sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];

    sub_162B8(arg0, &sp00, &sp02);

    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gUnknown_02031520.unk14.unk26 - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk14.unk28 - 8)
            {

                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 0x28;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = 0xFFD8;
                        gCurrentPinballGame->ball->unk6 = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }

            }
        }
        return_val = 1;
        break;
    case 3:
    case 2:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    }

    sub_1642C((s32) some_enum, &return_val, arg1);
    return return_val;
}

void sub_162B8(struct Vector16 *arg0, s16 *arg1, u8 *arg2) {

    s16 deltaX;
    s16 deltaY;
    u16 maskedResult = 0;
    u8 lowerNibble = 0;
    s32 ix = 0;

    if (gCurrentPinballGame->unk5B2 == 0)
    {
        if (gCurrentPinballGame->unk24 != 0)
            return;

        deltaX = arg0->x + gCurrentPinballGame->unk184[0].x;
        deltaY = arg0->y + gCurrentPinballGame->unk184[0].y;

        if (deltaX <= 63U && deltaY <= 63U)
        {
            maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
            lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
            ix = 0;
        }
         if (lowerNibble == 0)
        {
            deltaX = gCurrentPinballGame->unk184[1].x + arg0->x;
            deltaY = gCurrentPinballGame->unk184[1].y + arg0->y;

            if (deltaX <= 63U && deltaY <= 63U)
            {
                maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                ix = 1;
            }

            if (lowerNibble == 0)
            {
                deltaX = gCurrentPinballGame->unk184[2].x + arg0->x;
                deltaY = gCurrentPinballGame->unk184[2].y + arg0->y;

                if (deltaX <= 63U && deltaY <= 63U)
                {
                    maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }
        gCurrentPinballGame->unk170[ix] = 6;

        *arg1 = maskedResult;
        *arg2 = lowerNibble;

        if (gCurrentPinballGame->unk624 <= 0)
            gCurrentPinballGame->unk624 = 2;
    }
}


void sub_1642C(u8 arg0, u16* arg1, u16* arg2)
{
    s16 absVelY;
    s16 x0Position;
    s16 modRes;
    s16 index;
    u16 angle;
    int squaredMagnitude;

    switch (arg0)
    {
    case 1:
        if (gCurrentPinballGame->unk26 == 0)
        {
            if (gCurrentPinballGame->ball->positionQ1.x >= 200)
                gCurrentPinballGame->unk25 = 1;
            else
                gCurrentPinballGame->unk25 = 3;

            sub_32914();
            gCurrentPinballGame->unk22 = 7;
            *arg1 = 1;
        }
        break;
    case 2:
        if (gCurrentPinballGame->unk24 == 0)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->unk24 = 2;
        }
        else if (gCurrentPinballGame->unk24 == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->unk24 = 3;
        }
        else if (gCurrentPinballGame->unk24 == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 1;
        }
        break;
    case 3:
        if (gCurrentPinballGame->unk24 == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 3;
            gCurrentPinballGame->unk24 = 0;
        }
        else if (gCurrentPinballGame->unk24 == 3)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->unk24 = 2;
        }
        break;
    case 4:
        if (gCurrentPinballGame->unk600 == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.y < 260)
            {
                if (gCurrentPinballGame->ball->positionQ0.x < 74)
                {
                    if (gCurrentPinballGame->unk13 < 3 && gCurrentPinballGame->unk36A[1] < 3)
                    {
                        if (gCurrentPinballGame->unk36A[1] == 1)
                            gCurrentPinballGame->unk36C[1] = 6;
                        else
                            gCurrentPinballGame->unk36C[1] = 4;

                        gCurrentPinballGame->unk36E[1] = 0;
                        gCurrentPinballGame->unk36A[1] = 1;
                        sub_11B0(7);

                        gCurrentPinballGame->ball->velocity.x /= 2;
                        gCurrentPinballGame->ball->velocity.y /= 2;

                        memcpy(&gCurrentPinballGame->unk1334[1], &gCurrentPinballGame->unk1334[0], sizeof(*gCurrentPinballGame->unk1334));

                        gCurrentPinballGame->unk1330 = &gCurrentPinballGame->unk1334[1];
                        gCurrentPinballGame->unk1328 = 25;
                    }
                }
                else if (gCurrentPinballGame->ball->positionQ0.x < 116)
                {
                    if (gCurrentPinballGame->unk13 < 3 && gCurrentPinballGame->unk36A[0] < 3)
                    {
                        if (gCurrentPinballGame->unk36A[0] == 1)
                            gCurrentPinballGame->unk36C[0] = 6;
                        else
                            gCurrentPinballGame->unk36C[0] = 4;

                        gCurrentPinballGame->unk36E[0] = 0;
                        gCurrentPinballGame->unk36A[0] = 1;

                        sub_11B0(7);

                        gCurrentPinballGame->ball->velocity.x /= 2;
                        gCurrentPinballGame->ball->velocity.y /= 2;

                        memcpy(&gCurrentPinballGame->unk1334[1], &gCurrentPinballGame->unk1334[0], sizeof(*gCurrentPinballGame->unk1334));

                        gCurrentPinballGame->unk1330 = &gCurrentPinballGame->unk1334[1];
                        gCurrentPinballGame->unk1328 = 25;
                    }
                }
                else
                {
                    gCurrentPinballGame->unk30C = 1800;
                    gCurrentPinballGame->unk306 = 1;

                    if (gCurrentPinballGame->unk70E < 99)
                        gCurrentPinballGame->unk70E++;

                    gCurrentPinballGame->scoreAddedInFrame = 5000;
                }
            }
            else
            {
                if (gCurrentPinballGame->ball->positionQ0.x < 110)
                {
                    gCurrentPinballGame->unk328 = 1;
                    gCurrentPinballGame->ball->velocity.y /= 2;
                }
                else
                {
                    if (gCurrentPinballGame->unk378 == 0)
                        gCurrentPinballGame->unk378 = 1;
                    else
                        gCurrentPinballGame->unk378 = 0;

                    gCurrentPinballGame->ball->velocity.y /=2;
                    gCurrentPinballGame->scoreAddedInFrame = 3000;
                }
            }

            gCurrentPinballGame->unk600 = 45;
            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
        }
        break;
    case 5:
        gCurrentPinballGame->unk165 = 1;
        gCurrentPinballGame->unk20 = 1;
        gCurrentPinballGame->unk732 = 0;
        gCurrentPinballGame->unk342 = 0;
        break;
    case 6:
        if (gCurrentPinballGame->ball->positionQ0.x < 120)
        {
            if (gCurrentPinballGame->ball->velocity.y > 0)
            {
                angle = 0xDA00;
                squaredMagnitude =
                    gCurrentPinballGame->ball->velocity.x * gCurrentPinballGame->ball->velocity.x +
                    gCurrentPinballGame->ball->velocity.y * gCurrentPinballGame->ball->velocity.y;

                squaredMagnitude = Sqrt(squaredMagnitude * 4) / 2;
                gCurrentPinballGame->ball->velocity.x = squaredMagnitude * Cos(angle) / 20000;
                gCurrentPinballGame->ball->velocity.y = -squaredMagnitude * Sin(angle) / 20000;
            }
        }
        else
            gCurrentPinballGame->unk342 = 1;
        break;
    case 7:
        if (gCurrentPinballGame->unk366 != 3)
        {
            gCurrentPinballGame->unk368 = 17;
            gCurrentPinballGame->unk23 = 0;
            gCurrentPinballGame->unk22 = 2;
            *arg2 = 0xD800;
            *arg1 = 1;
        }
        break;
    case 8:
        x0Position = gCurrentPinballGame->ball->positionQ0.x;
        if (gCurrentPinballGame->unk24 > 0)
        {
            if (gCurrentPinballGame->unk732 == 7)
            {
                gCurrentPinballGame->unk194 = 10;
                if (gCurrentPinballGame->unk72B < 3)
                {
                    if (gCurrentPinballGame->unk72B == 0)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                        gCurrentPinballGame->unk194 = 1;
                    }
                    else if (gCurrentPinballGame->unk72B == 1)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                        gCurrentPinballGame->unk194 = 5;
                    }
                    else
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 10000;
                        gCurrentPinballGame->unk194 = 10;
                    }

                    gCurrentPinballGame->unk72B++;
                }

                gCurrentPinballGame->unk196 = 0;
                gCurrentPinballGame->unk72C = 0;
            }

            gCurrentPinballGame->unk732 = 1;
        }
        else
        {
            if (x0Position <= 72)
            {
                if (gCurrentPinballGame->unk732 == 8)
                {
                    if (gCurrentPinballGame->unk13 < 3 && gCurrentPinballGame->unk72E < 3)
                    {
                        if (gCurrentPinballGame->unk72E == 0)
                            gCurrentPinballGame->scoreAddedInFrame = 2000;
                        else if (gCurrentPinballGame->unk72E == 1)
                            gCurrentPinballGame->scoreAddedInFrame = 5000;
                        else
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        
                        gCurrentPinballGame->unk72E++;
                        m4aSongNumStart(SE_UNKNOWN_0x99);
                    }

                    gCurrentPinballGame->unk6BC = 1;
                }

                gCurrentPinballGame->unk732 = 2;
            }
            else if (x0Position <= 98)
            {
                if (gCurrentPinballGame->ballPowerUpLight[0] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[0] = 1;
                gCurrentPinballGame->unk732 = 3;

                if (gCurrentPinballGame->unk71B == 0 && (gCurrentPinballGame->ballPowerUpLight[1] & gCurrentPinballGame->ballPowerUpLight[2]))
                {
                    gCurrentPinballGame->unk71B = 1;
                    gCurrentPinballGame->unk71C = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else if (x0Position <= 118)
            {
                if (gCurrentPinballGame->ballPowerUpLight[1] == 0) 
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[1] = 1;
                gCurrentPinballGame->unk732 = 4;

                if (gCurrentPinballGame->unk71B == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[2]))
                {
                    gCurrentPinballGame->unk71B = 1;
                    gCurrentPinballGame->unk71C = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else if (x0Position <= 146)
            {
                if (gCurrentPinballGame->ballPowerUpLight[2] == 0)
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                
                gCurrentPinballGame->ballPowerUpLight[2] = 1;
                gCurrentPinballGame->unk732 = 5;

                if (gCurrentPinballGame->unk71B == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[1]))
                {
                    gCurrentPinballGame->unk71B = 1;
                    gCurrentPinballGame->unk71C = 60;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
            else
            {
                if (gCurrentPinballGame->unk732 == 9)
                {
                    if (gCurrentPinballGame->unk13 <= 2 && gCurrentPinballGame->unk72F < 3)
                    {
                        if (gCurrentPinballGame->unk72F == 0)
                            gCurrentPinballGame->scoreAddedInFrame = 2000;
                        else if (gCurrentPinballGame->unk72F == 1)
                            gCurrentPinballGame->scoreAddedInFrame = 5000;
                        else
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        
                        gCurrentPinballGame->unk72F++;

                        if (gCurrentPinballGame->unk1CA == 13)
                            m4aSongNumStart(SE_UNKNOWN_0x99);

                        if (gCurrentPinballGame->unk72F > 1)
                            gCurrentPinballGame->unk731 = 1;
                    }

                    gCurrentPinballGame->unk6BC = 2;
                }

                gCurrentPinballGame->unk732 = 6;
            }
        }
        break;
    case 9:
        x0Position = gCurrentPinballGame->ball->positionQ0.x;
        if (gCurrentPinballGame->unk24 > 0)
            gCurrentPinballGame->unk732 = 7;
        else if (x0Position <= 50)
            gCurrentPinballGame->unk732 = 8;
        else
            gCurrentPinballGame->unk732 = 9;
        break;
    case 10:
        if (gCurrentPinballGame->ball->positionQ0.x <= 46)
        {
            gCurrentPinballGame->unk732 = 10;
            if (gCurrentPinballGame->holeIndicators[0] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[0] = 1;
                if (gCurrentPinballGame->unk714 == 0 && (
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[2] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->unk714 = 1;
                    gCurrentPinballGame->unk715 = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 120)
        {
            gCurrentPinballGame->unk732 = 11;

            if (gCurrentPinballGame->holeIndicators[1] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[1] = 1; 
                if (gCurrentPinballGame->unk714 == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[2] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->unk714 = 1;
                    gCurrentPinballGame->unk715 = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 193)
        {
            gCurrentPinballGame->unk732 = 12;
            if (gCurrentPinballGame->holeIndicators[2] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[2] = 1;

                if (gCurrentPinballGame->unk714 == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[3]))
                {
                    gCurrentPinballGame->unk714 = 1;
                    gCurrentPinballGame->unk715 = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        else
        {
            gCurrentPinballGame->unk732 = 13;
            if (gCurrentPinballGame->holeIndicators[3] == 0)
            {
                gCurrentPinballGame->scoreAddedInFrame = 1000;
                gCurrentPinballGame->holeIndicators[3] = 1;
                if (gCurrentPinballGame->unk714 == 0 && (
                    gCurrentPinballGame->holeIndicators[0] &
                    gCurrentPinballGame->holeIndicators[1] &
                    gCurrentPinballGame->holeIndicators[2]))
                {
                    gCurrentPinballGame->unk714 = 1;
                    gCurrentPinballGame->unk715 = 126;
                    gCurrentPinballGame->scoreAddedInFrame = 4000;
                }
            }
        }
        break;
    case 11:
        if (gCurrentPinballGame->unk1C4 == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x <= 120)
                gCurrentPinballGame->unk1C2 = 1;
            else
                gCurrentPinballGame->unk1C2 = 2;

            if (gCurrentPinballGame->outLanePikaPosition < 2)
            {
                if (gCurrentPinballGame->outLanePikaPosition == gCurrentPinballGame->unk1C2 - 1)
                    gCurrentPinballGame->unk1C4 = 120;
            }
            else
            {
                gCurrentPinballGame->unk1C4 = 120;
            }
        }
        break;
    case 12:
        if (gCurrentPinballGame->unk616 == 0)
        {
            absVelY = gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->unk614 = absVelY;
            if (absVelY < 0)
                absVelY = -absVelY;

            gCurrentPinballGame->unk1C6 = gCurrentPinballGame->unk1C6 + (absVelY / 3);
            if (gCurrentPinballGame->unk1C6 > 168)
                gCurrentPinballGame->unk1C6 = 168;

            gCurrentPinballGame->unk616 = 20;
        }
        break;
    case 13:
        if (gCurrentPinballGame->unk732 != 14)
        {
            gCurrentPinballGame->unk732 = 14;
            index = gUnknown_086ACE70[gCurrentPinballGame->unk34A];
            gCurrentPinballGame->unk34B[index] = 10;
            gCurrentPinballGame->unk34A++;
            if (gCurrentPinballGame->unk34A == 3)
            {
                memcpy(&gCurrentPinballGame->unk1334[1], &gCurrentPinballGame->unk1334[0], sizeof(*gCurrentPinballGame->unk1334));
                gCurrentPinballGame->unk1330 = &gCurrentPinballGame->unk1334[1];
                if (gCurrentPinballGame->unk342)
                    gCurrentPinballGame->unk344 = 1;
            }

            if (gCurrentPinballGame->unk34A == 11)
                gCurrentPinballGame->unk1330 = gCurrentPinballGame->unk1334;

            modRes = (gCurrentPinballGame->unk34A - 1) % 4;
            gMain.spriteGroups[modRes + 47].available = 1;
            gCurrentPinballGame->unk355[modRes] = 0;
            gCurrentPinballGame->unk35E[modRes] = 0;
            gCurrentPinballGame->unk359[modRes] = gCurrentPinballGame->unk34A - 1;

            if (gCurrentPinballGame->unk34A > 12)
                gCurrentPinballGame->unk34A = 0;

            if (index == 0 && gCurrentPinballGame->ball->velocity.y > -120)
                gCurrentPinballGame->ball->velocity.y = -120;

            if (index == 2 && gCurrentPinballGame->ball->velocity.y > -180)
                gCurrentPinballGame->ball->velocity.y = -180;
        }
        break;
    case 14:
        if (gCurrentPinballGame->unk732 != 15)
        {
            gCurrentPinballGame->unk732 = 15;
            index = gUnknown_086ACE70[gCurrentPinballGame->unk34A];
            gCurrentPinballGame->unk34B[index] = 10;
            gCurrentPinballGame->unk34A++;

            modRes = (gCurrentPinballGame->unk34A -1) % 4;
            gMain.spriteGroups[modRes + 47].available = 1;
            gCurrentPinballGame->unk355[modRes] = 0;
            gCurrentPinballGame->unk35E[modRes] = 0;
            gCurrentPinballGame->unk359[modRes] = gCurrentPinballGame->unk34A - 1;
            if (index == 1 && gCurrentPinballGame->ball->velocity.y > -150)
                gCurrentPinballGame->ball->velocity.y = -150;
        }
        break;
    case 15:
        if (gCurrentPinballGame->ball->positionQ0.y < 80)
        {
            if (gCurrentPinballGame->unk306 == 1)
                gCurrentPinballGame->unk306 = 2;
        }
        else
        {
            if (gCurrentPinballGame->unk306 == 2)
            {
                gCurrentPinballGame->unk306 = 3;
                gCurrentPinballGame->unk30C = 0;
            }
        }

        break;
    }
}

s16 COLLISION_CHECK_DUSCLOPS_171C8(struct Vector16* arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 unk0;
    s32 unk1;
    s32 unk2;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    unk1 = vec1.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    vec1.y %= 64;
    unk0 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
    sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];

    sub_173FC(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gUnknown_02031520.unk14.unk26 - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk14.unk28 - 8)
            {

                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 0x28;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = 0xFFD8;
                        gCurrentPinballGame->ball->unk6 = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }

            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    sub_17634(some_enum, &return_val, arg1);
    return return_val;
}

void sub_173FC(struct Vector16 *arg0, s16* arg1, u8* arg2) {
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    u8 temp;

    maskedResult = 0;
    lowerNibble = 0;

    if(gCurrentPinballGame->unk387 == 2)
    {
        if (*arg2 != 0)
            return;

        deltaX = arg0->x -gCurrentPinballGame->unk3F0;
        deltaY = arg0->y -gCurrentPinballGame->unk3F2;

        if (deltaX > 95U || deltaY > 119U)
            return;

        maskedResult = 0xFFF0 & gUnknown_083071D4[(deltaY * 96 ) + deltaX];
        lowerNibble = 0xF & gUnknown_083071D4[(deltaY * 96 ) + deltaX];

        if (lowerNibble == 0)
            return;

        temp = gCurrentPinballGame->unk3DC -3;
        if (temp <= 1U)
            *arg2 = 1;
        else
            *arg2 = lowerNibble;

        gCurrentPinballGame->unk3DC = 4;
        *arg1 = maskedResult;

        return;
    }

    if(gCurrentPinballGame->unk387 == 1)
    {
        if (*arg2 != 0)
            return;

        if (gCurrentPinballGame->unk3A9[0] != 0)
        {
            deltaX = arg0->x - gCurrentPinballGame->unk3D0[0].x;
            deltaY = arg0->y - gCurrentPinballGame->unk3D0[0].y;

            if (deltaX < 64U && deltaY < 64U)
            {
                maskedResult = 0xFFF0 & gUnknown_08252B10[deltaY * 64 + deltaX];
                lowerNibble = 0xF & gUnknown_08252B10[deltaY * 64 + deltaX];

                if (lowerNibble != 0)
                    gCurrentPinballGame->unk3A0[0] = 4;
            }
        }

        if (lowerNibble == 0)
        {
            if (gCurrentPinballGame->unk3A9[1] != 0)
            {
                deltaX = arg0->x - gCurrentPinballGame->unk3D0[1].x;
                deltaY = arg0->y - gCurrentPinballGame->unk3D0[1].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = 0xFFF0 & gUnknown_08252B10[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                        gCurrentPinballGame->unk3A0[1] = 4;
                }
            }
        }

        if (lowerNibble == 0)
        {
            if ( gCurrentPinballGame->unk3A9[2] != 0)
            {
                deltaX = arg0->x - gCurrentPinballGame->unk3D0[2].x;
                deltaY = arg0->y - gCurrentPinballGame->unk3D0[2].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = 0xFFF0 & gUnknown_08252B10[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                    {
                        gCurrentPinballGame->unk3A0[2] = 4;
                    }
                }
            }
        }

        if (lowerNibble != 0)
        {
            *arg1 = maskedResult;
            *arg2 = 6;
        }
        return;
    }
}


void sub_17634(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->unk3DC = 6;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk387 = 0;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

s16 COLLISION_CHECK_KECLEON_176B0(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 unk0;
    s32 unk1;
    s32 unk2;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    unk1 = vec1.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    vec1.y %= 64;
    unk0 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
    sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];

    sub_17898(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = 0;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        if (gCurrentPinballGame->unk404 == 0)
        {
            s32 unk3 = gCurrentPinballGame->unk406;
            if (unk3 == 0)
            {
                gCurrentPinballGame->unk404 = 1;
                gCurrentPinballGame->unk40A = unk3;
            }
        }
        gCurrentPinballGame->unk40C = 40;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    sub_179D0(some_enum, &return_val, arg1);
    return return_val;
}

void sub_17898(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;

    if (gCurrentPinballGame->unk387 == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->unk3F0;
        deltaY = arg0->y - gCurrentPinballGame->unk3F2;

        if ((deltaX < 0 || deltaX > 0x3F) || (deltaY < 0 || deltaY > 0x57))
            return;

        arrayValue = (u8)(gUnknown_0832D604[(deltaY * 0x40) + deltaX]) & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->unk0 != 0)
            return;
        if (gCurrentPinballGame->unk3DC > 8)
            return;

        gCurrentPinballGame->unk3DC = 9;
    }
    else if (gCurrentPinballGame->unk387 == 2)
    {
        u16 maskedResult;

        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->unk3F0;
        deltaY = arg0->y - gCurrentPinballGame->unk3F2;

        if ((deltaX < 0 || deltaX > 0x57) || (deltaY < 0 || deltaY > 0x3F))
            return;

        maskedResult = gUnknown_08330204[(deltaY * 0x58) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_08330204[(deltaY * 0x58) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->unk0 != 0)
            return;
        if (gCurrentPinballGame->unk3DC == 12)
            return;

        gCurrentPinballGame->unk3DC = 11;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void sub_179D0(u8 arg0, u16 *arg1, u16 *arg2)
{
    s16 x, y;
    x = gCurrentPinballGame->ball->positionQ0.x;
    y = gCurrentPinballGame->ball->positionQ0.y;

    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 13:
    case 14:
    case 15:
        return;
    case 8:
        if (x <= 0x72)
        {
            if (y <= 0x38)
            {
                if (gCurrentPinballGame->unk41C[0] <= 0)
                    gCurrentPinballGame->unk41C[0] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk41C[1] <= 0)
                    gCurrentPinballGame->unk41C[1] = 0x18;
            }
        }
        else if (y <= 0x63)
        {
            if (gCurrentPinballGame->unk41C[3] <= 0)
                gCurrentPinballGame->unk41C[3] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk41C[2] <= 0)
                gCurrentPinballGame->unk41C[2] = 0x18;
        }
        break;
    case 9:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->unk420[7] <= 0)
                    gCurrentPinballGame->unk420[7] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk420[5] <= 0)
                    gCurrentPinballGame->unk420[5] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->unk420[8] <= 0)
                gCurrentPinballGame->unk420[8] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[0] <= 0)
                gCurrentPinballGame->unk420[0] = 0x18;
        }
        break;
    case 10:
        if (gCurrentPinballGame->unk410 == 0)
        {
            gCurrentPinballGame->unk42A[0] = 0xB;
            gCurrentPinballGame->unkD0[0].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[0].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->unk410 == 3)
        {
            gCurrentPinballGame->unk42A[1] = 0xB;
            gCurrentPinballGame->unkD0[1].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[1].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->unk410 == 6)
        {
            gCurrentPinballGame->unk42A[2] = 0xB;
            gCurrentPinballGame->unkD0[2].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[2].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        else if (gCurrentPinballGame->unk410 == 9)
        {
            gCurrentPinballGame->unk42A[3] = 0xB;
            gCurrentPinballGame->unkD0[3].x = gCurrentPinballGame->ball->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[3].y = gCurrentPinballGame->ball->positionQ0.y - 7;
        }
        break;
    case 11:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->unk420[9] <= 0)
                    gCurrentPinballGame->unk420[9] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk420[2] <= 0)
                    gCurrentPinballGame->unk420[2] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->unk420[6] <= 0)
                gCurrentPinballGame->unk420[6] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[1] <= 0)
                gCurrentPinballGame->unk420[1] = 0x18;
        }
        break;
    case 12:
        if (x <= 0x72)
        {
            if (gCurrentPinballGame->unk420[4] <= 0)
                gCurrentPinballGame->unk420[4] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[3] <= 0)
                gCurrentPinballGame->unk420[3] = 0x18;
        }
        break;
    }
}

void sub_17C1C(struct Vector16 *arg0)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    s16 x, y;
    u16 sp00;
    u8 sp02;
    s16 unk0;
    s32 unk1;
    s32 unk2;
    u32 some_enum;

    gCurrentPinballGame->unk3F8 = 1;
    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    unk1 = vec1.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    vec1.y %= 64;
    unk0 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
    sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];

    some_enum = (sp02 >> 2) >> 2;

    x = gCurrentPinballGame->unk400.x;
    y = gCurrentPinballGame->unk400.y;

    switch (some_enum)
    {
    case 8:
        if (x <= 0x72)
        {
            if (y <= 0x38)
            {
                if (gCurrentPinballGame->unk41C[0] <= 0)
                    gCurrentPinballGame->unk41C[0] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk41C[1] <= 0)
                    gCurrentPinballGame->unk41C[1] = 0x18;
            }
        }
        else if (y <= 0x63)
        {
            if (gCurrentPinballGame->unk41C[3] <= 0)
                gCurrentPinballGame->unk41C[3] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk41C[2] <= 0)
                gCurrentPinballGame->unk41C[2] = 0x18;
        }
        break;
    case 9:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->unk420[7] <= 0)
                    gCurrentPinballGame->unk420[7] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk420[5] <= 0)
                    gCurrentPinballGame->unk420[5] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->unk420[8] <= 0)
                gCurrentPinballGame->unk420[8] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[0] <= 0)
                gCurrentPinballGame->unk420[0] = 0x18;
        }
        break;
    case 10:
        gCurrentPinballGame->unk3F8 = 0;
        if (gCurrentPinballGame->unk412 == 0)
        {
            if (gCurrentPinballGame->unk400.x != gCurrentPinballGame->unk434[0].x || gCurrentPinballGame->unk400.y != gCurrentPinballGame->unk434[0].y)
            {
                gCurrentPinballGame->unk42A[4] = 0x11;
                gCurrentPinballGame->unk434[0].x = gCurrentPinballGame->unk400.x;
                gCurrentPinballGame->unk434[0].y = gCurrentPinballGame->unk400.y;
            }
        }
        else if (gCurrentPinballGame->unk412 == 8)
        {
            if (gCurrentPinballGame->unk400.x != gCurrentPinballGame->unk434[1].x || gCurrentPinballGame->unk400.y != gCurrentPinballGame->unk434[1].y)
            {
                gCurrentPinballGame->unk42A[5] = 0x11;
                gCurrentPinballGame->unk434[1].x = gCurrentPinballGame->unk400.x;
                gCurrentPinballGame->unk434[1].y = gCurrentPinballGame->unk400.y;
            }
        }
        else if (gCurrentPinballGame->unk412 == 16)
        {
            if (gCurrentPinballGame->unk400.x != gCurrentPinballGame->unk434[2].x || gCurrentPinballGame->unk400.y != gCurrentPinballGame->unk434[2].y)
            {
                gCurrentPinballGame->unk42A[6] = 0x11;
                gCurrentPinballGame->unk434[2].x = gCurrentPinballGame->unk400.x;
                gCurrentPinballGame->unk434[2].y = gCurrentPinballGame->unk400.y;
            }
        }
        break;
    case 11:
        if (x <= 0x72)
        {
            if (y <= 0x45)
            {
                if (gCurrentPinballGame->unk420[9] <= 0)
                    gCurrentPinballGame->unk420[9] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->unk420[2] <= 0)
                    gCurrentPinballGame->unk420[2] = 0x18;
            }
        }
        else if (y <= 0x45)
        {
            if (gCurrentPinballGame->unk420[6] <= 0)
                gCurrentPinballGame->unk420[6] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[1] <= 0)
                gCurrentPinballGame->unk420[1] = 0x18;
        }
        break;
    case 12:
        if (x <= 0x72)
        {
            if (gCurrentPinballGame->unk420[4] <= 0)
                gCurrentPinballGame->unk420[4] = 0x18;
        }
        else
        {
            if (gCurrentPinballGame->unk420[3] <= 0)
                gCurrentPinballGame->unk420[3] = 0x18;
        }
        break;
    }
}

s16 COLLISION_CHECK_KYOGRE_17F28(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 unk0;
    s32 unk1;
    s32 unk2;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;
    if (arg0->y < 0x200)
    {
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        unk1 = vec1.y / 64;
        unk2 = gCurrentPinballGame->unk24;
        vec1.y %= 64;
        unk0 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
        sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    sub_18180(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gUnknown_02031520.unk14.unk26 - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk14.unk28 - 8)
            {

                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 0x28;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = 0xFFD8;
                        gCurrentPinballGame->ball->unk6 = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }

            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    sub_182B4(some_enum, &return_val, arg1);
    return return_val;
}

void sub_18180(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;
    u16 maskedResult;

    if (gCurrentPinballGame->unk387 == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->unk3F0;
        deltaY = arg0->y - gCurrentPinballGame->unk3F2;

        if ((deltaX < 0 || deltaX >= 0x78) || (deltaY < 0 || deltaY >= 0x98))
            return;

        maskedResult = gUnknown_08340B58[(deltaY * 0x78) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_08340B58[(deltaY * 0x78) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->unk452 = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->unk387 == 2)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->unk3F0;
        deltaY = arg0->y - gCurrentPinballGame->unk3F2;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x58))
            return;

        maskedResult = gUnknown_083499D8[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_083499D8[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->unk452 = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->unk387 == 3)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->unk3F0;
        deltaY = arg0->y - gCurrentPinballGame->unk3F2;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x68))
            return;

        maskedResult = gUnknown_0834DBD8[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gUnknown_0834DBD8[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->unk452 = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void sub_182B4(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->unk3DC = 6;
        gCurrentPinballGame->unk1F = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

s16 COLLISION_CHECK_GROUDON_18324(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 unk1;
        s32 unk2;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        unk1 = vec1.y / 64;
        unk2 = gCurrentPinballGame->unk24;
        vec1.y %= 64;
        r2 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
        sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    sub_1857C(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gUnknown_02031520.unk14.unk26 - 8) || gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk14.unk28 - 8)
            {
                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 40;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = -40;
                        gCurrentPinballGame->ball->unk6 = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    sub_18784(some_enum, &return_val, arg1);
    return return_val;
}

void sub_1857C(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 resultFromArray;
    u16 maskedResult;
    u16 lowerNibble;
    s16 i;

    if (gCurrentPinballGame->unk387 == 1)
    {
        if ((*arg2 & 0xF) == 0)
        {
            deltaX = arg0->x - gCurrentPinballGame->unk3F0;
            deltaY = arg0->y - gCurrentPinballGame->unk3F2;

            if ((deltaX >= 0 && deltaX < 0x70) && (deltaY >= 0 && deltaY < 0x80))
            {
                resultFromArray = gUnknown_083579C8[(deltaY * 0x70) + deltaX];
                maskedResult = resultFromArray & 0xFFF0;
                lowerNibble = resultFromArray & 0xF;
                if (lowerNibble != 0)
                {
                    if (gCurrentPinballGame->unk452 == 0)
                        gCurrentPinballGame->unk452 = 0x27;

                    *arg1 = maskedResult;
                    *arg2 = lowerNibble;
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->unk4F8[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->unk4F8[i].x;
        deltaY = arg0->y - gCurrentPinballGame->unk4F8[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->unk4D5[i] = 1;
    }
    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->unk4B4[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->unk4B4[i].x;
        deltaY = arg0->y - gCurrentPinballGame->unk4B4[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gUnknown_0835E9C8[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->unk4A4[i] = 8;
    }
}

void sub_18784(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->unk3DC = 6;
        gCurrentPinballGame->unk1F = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

//One known callsite is 080145D2 during the rayquaza bonus stage
s16 COLLISION_CHECK_RAYQUAZA_187F4(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 unk1;
        s32 unk2;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        unk1 = vec1.y / 64;
        unk2 = gCurrentPinballGame->unk24;
        vec1.y %= 64;
        r2 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
        sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    sub_18A4C(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gUnknown_02031520.unk14.unk26 - 8) || gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk14.unk28 - 8)
            {
                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 40;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = -40;
                        gCurrentPinballGame->ball->unk6 = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    sub_18AE0(some_enum, &return_val, arg1);
    return return_val;
}

void sub_18A4C(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u16 lowerNibble;

    if (gCurrentPinballGame->unk387 != 1)
        return;
    if (*arg2 & 0xF)
        return;

    deltaX = arg0->x - gCurrentPinballGame->unk3F0;
    deltaY = arg0->y - gCurrentPinballGame->unk3F2;

    if ((deltaX < 0 || deltaX >= 0x80) || (deltaY < 0 || deltaY >= 0x80))
        return;

    maskedResult = gUnknown_083722E8[(deltaY * 0x80) + deltaX] & 0xFFF0;
    lowerNibble = gUnknown_083722E8[(deltaY * 0x80) + deltaX] & 0xF;

    if (lowerNibble == 0)
        return;

    gCurrentPinballGame->unk452 = 9;
    *arg1 = maskedResult;
    *arg2 = lowerNibble;
}

void sub_18AE0(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->unk3DC = 6;
        gCurrentPinballGame->unk1F = 1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}

s16 COLLISION_CHECK_SPHEAL_18B50(struct Vector16 *arg0, u16 *arg1)
{
    u16 sp0;
    u8 sp2;
    u16 sp4_return;

    struct Vector16 div_result;
    struct Vector16 div_remainder;
    s32 unk1;
    s32 unk2;
    s16 unk3;
    u8 enum1, enum2;

    sp4_return = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    div_result.x = arg0->x / 8;
    div_result.y = arg0->y / 8;
    div_remainder.x = arg0->x % 8;
    div_remainder.y = arg0->y % 8;
    unk1 = div_result.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    div_result.y %= 64;

    unk3 = gUnknown_02031520.unk14.unk38[unk2 + unk1][div_result.y * 64 + div_result.x];
    sp0 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk3 * 64 + div_remainder.y * 8 + div_remainder.x];
    sp2 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk3 * 64 + div_remainder.y * 8 + div_remainder.x];

    sub_18DAC(arg0, &sp0, &sp2);

    enum1 = sp2 & 0xF;
    enum2 = sp2 >> 4;
    switch (enum1)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->unk23 = enum1 - 1;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp0;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gUnknown_02031520.unk14.unk26 - 8) ||
                gCurrentPinballGame->ball->positionQ0.y < (gUnknown_02031520.unk14.unk28 - 8))
            {
                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 40;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = -40;
                        gCurrentPinballGame->ball->unk6 = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        sp4_return = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->unk23 = 0;
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp0 & 0x0000FFF0;

        if (gCurrentPinballGame->ball->positionQ0.x < 120)
            gCurrentPinballGame->unk548[0] = 24;
        else
            gCurrentPinballGame->unk548[1] = 24;

        sp4_return = 1;
        break;
    case 5:
        enum2 = 4;
        break;
    }

    sub_18F38(enum2, &sp4_return, arg1);
    return sp4_return;
}

void sub_18DAC(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 i;
    s16 deltaX, deltaY;
    u16 lowerReadFromRom;
    u16 upperReadFromRom;
    for (i = 0; i < 2; i++)
    {

        if (gCurrentPinballGame->unk54F[i] == 1)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->unk570[i].x;
            deltaY = arg0->y - gCurrentPinballGame->unk570[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gUnknown_08393A4C[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gUnknown_08393A4C[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            if (gCurrentPinballGame->unk388 != 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            gCurrentPinballGame->unk553[i] = 4;
        }
        else if (gCurrentPinballGame->unk54F[i] != 0)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->unk570[i].x;
            deltaY = arg0->y - gCurrentPinballGame->unk570[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gUnknown_08391A4C[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gUnknown_08391A4C[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            if (gCurrentPinballGame->unk54F[i] == 2)
            {
                gCurrentPinballGame->unk553[i] = 4;
            }
            else
            {
                gCurrentPinballGame->unk54D[i] = 24;
            }
        }
    }
}

void sub_18F38(u8 arg0_enum, u16 *arg1, u16 *arg2)
{
    switch (arg0_enum)
    {
    case 2:
        gCurrentPinballGame->unk530[2] = 0;
        gCurrentPinballGame->unk536[2] = 2;
        break;
    case 3:
        gCurrentPinballGame->unk530[2] = 1;
        gCurrentPinballGame->unk536[2] = 2;
        break;
    case 8:
        gCurrentPinballGame->unk530[2] = 0;
        gCurrentPinballGame->unk536[2] = 1;
        gCurrentPinballGame->unk53C[2] = 100;
        break;
    case 9:
        gCurrentPinballGame->unk530[2] = 1;
        gCurrentPinballGame->unk536[2] = 1;
        gCurrentPinballGame->unk53C[2] = 100;
        break;
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}