#include "global.h"
#include "main.h"


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