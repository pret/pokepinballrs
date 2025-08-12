#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"

void MainBoardProcess_7B_12524(void);
void BonusBoardProcess_7B_12BF8(void);
void sub_2AADC(void);

extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gUnknown_083BB16C[][0x80];
extern const u8 gUnknown_083BD36C[][0x200];
extern const u32 gUnknown_083BDF6C[][0x80];
extern const u32 gUnknown_083BF16C[][0x80];

void AllBoardProcess_5A_11B9C(void)
{
    s16 i;
    if (gMain.unk6 == 0)
    {
        gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
        sub_11C14(0);
        MainBoardProcess_7B_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[i];
            sub_11C14(i);
        }
        BonusBoardProcess_7B_12BF8();
    }
}

void sub_11C14(s16 arg0)
{
    struct BallState *var0 = &gCurrentPinballGame->unk1334[arg0];
    var0->positionQ0.x = gUnknown_02031520.unk14.unk26;
    var0->positionQ0.y = gUnknown_02031520.unk14.unk28;
    var0->positionQ8.x = Q_24_8(var0->positionQ0.x);
    var0->positionQ8.y = Q_24_8(var0->positionQ0.y);
    var0->positionQ1.x = gUnknown_02031520.unk14.unk26 * 2;
    var0->positionQ1.y = gUnknown_02031520.unk14.unk28 * 2;
    var0->unkE = 0x100;
    var0->velocity.x = 0;
    var0->velocity.y = 0;
    if (gMain.selectedField == FIELD_RUBY)
        var0->unk1 = 3;
    else
        var0->unk1 = 1;

    var0->unk6 = 0;
    gCurrentPinballGame->unk5B2 = 1;
}

extern const u16 gGravityDeltas_Strong[4];
extern const u16 gGravityDeltas_Medium[4];
extern const u16 gGravityDeltas_Light[4];


// Before updating the ball's position, cap the ball's velocity
// vector to a maximum speed.
#define UPDATE_BALL_POSITION(max_speed, angle)           \
{                                                        \
    maxSpeed = (max_speed);                              \
    if (squaredMagnitude > maxSpeed * maxSpeed)          \
    {                                                    \
        velocity.x =  (maxSpeed * Cos((angle))) / 20000; \
        velocity.y = (-maxSpeed * Sin((angle))) / 20000; \
    }                                                    \
    else                                                 \
    {                                                    \
        velocity.x = unk132c->velocity.x;                \
        velocity.y = unk132c->velocity.y;                \
    }                                                    \
    unk132c->positionQ8.x += velocity.x;                   \
    unk132c->positionQ8.y += velocity.y;                   \
}

void MainBoardProcess_5B_11C98(void)
{
    struct Vector16 velocity;
    struct BallState *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->ball;
    unk132c->prevPositionQ8 = unk132c->positionQ8;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 160)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 80)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }

            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (unk132c->positionQ0.y < 380)
            {
                UPDATE_BALL_POSITION(272, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
        else
        {
            u16 angle;

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 200)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 100)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }

            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (unk132c->positionQ0.y < 380)
            {
                UPDATE_BALL_POSITION(336, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
    }
    else
    {
        sub_2AADC();
    }

    unk132c->prevPositionQ1 = unk132c->positionQ1;
    unk132c->positionQ1.x = (unk132c->positionQ8.x + 64) / 128;
    unk132c->positionQ1.y = (unk132c->positionQ8.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}

void BonusBoardProcess_5B_11F88(void)
{
    struct Vector16 velocity;
    struct BallState *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->ball;
    unk132c->prevPositionQ8 = unk132c->positionQ8;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (!gCurrentPinballGame->unk1F && !gCurrentPinballGame->unk383)
        {
            // Gravity is applied at different strengths, depending on fast the ball is
            // currently moving downwards.
            if (unk132c->velocity.y > 150)
                unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
            else if (unk132c->velocity.y > 75)
                unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
            else
                unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->positionQ0.y < 150)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (unk132c->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (unk132c->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
        else
        {
            u16 angle;
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->positionQ0.y < 150)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (unk132c->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (unk132c->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
    }
    else
    {
        sub_2AADC();
    }

    unk132c->prevPositionQ1 = unk132c->positionQ1;
    unk132c->positionQ1.x = (unk132c->positionQ8.x + 64) / 128;
    unk132c->positionQ1.y = (unk132c->positionQ8.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}

void MainBoardProcess_7B_12524(void)
{
    s16 i;
    struct OamDataSimple *oam;
    struct OamData *oamData;
    struct BallState *currentBallState;
    struct SpriteGroup *spriteGroup;
    s16 r8;
    
    currentBallState = gCurrentPinballGame->ball;
    r8 = currentBallState->unkA >> 12;
    
    if (currentBallState->positionQ0.y == 340 && (currentBallState->positionQ0.x == 90 || currentBallState->positionQ0.x == 149))
        currentBallState->unkA = currentBallState->unkC;

    currentBallState->unkC = currentBallState->unkA;
    
    if (!gCurrentPinballGame->unk5F7 && gCurrentPinballGame->unk5F8 > 0)
    {
        if (--gCurrentPinballGame->unk5F8 == 0)
        {
            if (gCurrentPinballGame->unk5F6 > 0)
            {
                gCurrentPinballGame->unk5F6--;
                
                if (gCurrentPinballGame->unk5F6 > 0)
                    gCurrentPinballGame->unk5F8 = 3600;
            }
            
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)OBJ_PLTT + 0x20, 0x20);
        }
    }

    if (currentBallState->positionQ0.y >= 244)
    {
        gCurrentPinballGame->unk5B2 = 1;
        gCurrentPinballGame->unk176 = 0;
    }
    else
        gCurrentPinballGame->unk5B2 = 0;

    currentBallState->positionQ0.x = currentBallState->positionQ1.x / 2;
    currentBallState->positionQ0.y = currentBallState->positionQ1.y / 2;
    
    spriteGroup = gMain.unk44[0];
    
    if (spriteGroup->available)
    {
        SetMatrixScale(currentBallState->unkE, currentBallState->unkE, 0);
        
        spriteGroup->baseX = -(gCurrentPinballGame->unk4C + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->unk2AA;
        spriteGroup->baseY = -(gCurrentPinballGame->unk4E + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->unk5FC - gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk166;
        
        currentBallState->unk24 = spriteGroup->baseX;
        currentBallState->unk26 = spriteGroup->baseY;
        
        oam = &spriteGroup->oam[0];
        oamData = &gOamBuffer[oam->oamId];
        
        if (currentBallState->unk1 == 3)
        {
            if (currentBallState->positionQ0.y > 248)
                oamData->priority = 2;
            else
                oamData->priority = 3;
        }
        else
            oamData->priority = currentBallState->unk1;

        r8 = r8; // this fools the compiler into thinking r8 holds something that could need sign extending/truncation
        DmaCopy16(3, gUnknown_083BB16C[r8 + gCurrentPinballGame->unk5F6 * 17], (void *)0x6010400, 0x80);

        if (spriteGroup->baseY > 200)
            spriteGroup->baseY = 200;
        
        if (spriteGroup->baseY < -20)
            spriteGroup->baseY = -20;

        oamData->x = oam->xOffset + spriteGroup->baseX;
        
        if (currentBallState->unk0)
            oamData->y = 200;
        else
            oamData->y = oam->yOffset + spriteGroup->baseY;
    }

    spriteGroup = gMain.unk44[49];

    if (spriteGroup->available)
    {
        SetMatrixScale(currentBallState->unkE, currentBallState->unkE, 0);
        
        spriteGroup->baseX = -(gCurrentPinballGame->unk4C + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->unk2AA;
        spriteGroup->baseY = -(gCurrentPinballGame->unk4E + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->unk5FC - gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk166;
        
        currentBallState->unk24 = spriteGroup->baseX;
        currentBallState->unk26 = spriteGroup->baseY;
        
        oam = &spriteGroup->oam[0];
        oamData = &gOamBuffer[oam->oamId];
    
        if (currentBallState->unk1 == 3)
        {
            if (currentBallState->positionQ0.y > 248)
                oamData->priority = 2;
            else
                oamData->priority = 3;
        }
        else
            oamData->priority = currentBallState->unk1;
        
        DmaCopy16(3, gUnknown_083BB16C[r8 + gCurrentPinballGame->unk5F6 * 17], (void *)0x6010400, 0x80);

        if (spriteGroup->baseY > 200)
            spriteGroup->baseY = 200;
        
        if (spriteGroup->baseY < -20)
            spriteGroup->baseY = -20;

        oamData->x = oam->xOffset + spriteGroup->baseX;

        if (currentBallState->unk0)
            oamData->y = 200;
        else
            oamData->y = oam->yOffset + spriteGroup->baseY;
    }

    for (i = 4; i > 0; i--)
    {
        gCurrentPinballGame->unkD0[i].x = gCurrentPinballGame->unkD0[(i - 1)].x;
        gCurrentPinballGame->unkD0[i].y = gCurrentPinballGame->unkD0[(i - 1)].y;
    }

    gCurrentPinballGame->unkD0[0].x = currentBallState->positionQ0.x - 7;
    gCurrentPinballGame->unkD0[0].y = currentBallState->positionQ0.y - 7;
    
    if (gCurrentPinballGame->unk71)
    {
        for (i = 0; i < 2; i++)
        {
            spriteGroup = gMain.unk44[i + 1];
            
            if (spriteGroup->available)
            {
                oam = &spriteGroup->oam[0];
                oamData = &gOamBuffer[oam->oamId];
                
                oamData->priority = currentBallState->unk1;
                oamData->x = oam->xOffset + (gCurrentPinballGame->unkD0[(i + 1) * 2].x - gCurrentPinballGame->unk4C);
                
                if (i == 0)
                    oamData->y = gCurrentPinballGame->unkD0[2].y - gCurrentPinballGame->unk4E + oam->yOffset;
                else if (i == 1)
                {
                    if (gMain.systemFrameCount % 2 == 0)
                        oamData->y = gCurrentPinballGame->unkD0[4].y - gCurrentPinballGame->unk4E + oam->yOffset;
                    else
                        oamData->y = 200;
                }
            }
        }

        gMain.unk44[1]->available = 1;
        gMain.unk44[2]->available = 1;
        gMain.unk44[49]->available = 1;
        gMain.unk44[0]->available = 0;
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            spriteGroup = gMain.unk44[i + 1];
     
            if (spriteGroup->available)
            {
                oam = &spriteGroup->oam[0];
                oamData = &gOamBuffer[oam->oamId];
                
                oamData->priority = currentBallState->unk1;
                oamData->x = oam->xOffset + (gCurrentPinballGame->unkD0[(i + 1) * 2].x - gCurrentPinballGame->unk4C);
                oamData->y = 200;
            }
        }

        gMain.unk44[1]->available = 0;
        gMain.unk44[2]->available = 0;
        gMain.unk44[49]->available = 0;
        gMain.unk44[0]->available = 1;
    }

    spriteGroup = gMain.unk44[43];
    
    if (spriteGroup->available)
    {
        s8 newIx;
        if (gCurrentPinballGame->unk71C < 59)
        {
            spriteGroup->baseX = gMain.unk44[0]->baseX - 8;
            spriteGroup->baseY = gMain.unk44[0]->baseY - 8;
        }
        else
        {
            spriteGroup->baseX = 0;
            spriteGroup->baseY = 180;
        }

        newIx = gCurrentPinballGame->unk6E;
        DmaCopy16(3, gUnknown_083BD36C[newIx], (void *)0x6011EE0, 0x200);
        
        oam = &spriteGroup->oam[0];
        
        gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
        gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;
        
        gOamBuffer[oam->oamId].priority = currentBallState->unk1;
        
        if (gCurrentPinballGame->unk71C < 14)
            gMain.unk44[43]->available = 0;
    }
}

void BonusBoardProcess_7B_12BF8()
{
    s16 i;
    s16 r5;
    struct SpriteGroup *spriteGroup;
    struct OamData *oamData;
    struct OamDataSimple *oam;
    struct BallState *unk1334_0;

    gCurrentPinballGame->unk1330 = gCurrentPinballGame->unk1334;
    gCurrentPinballGame->ball = gCurrentPinballGame->unk1334;

    unk1334_0 = &gCurrentPinballGame->unk1334[0];

    switch (gMain.selectedField)
    {
    case FIELD_KECLEON:
        unk1334_0->unk1 = 2;
        spriteGroup = &gMain_spriteGroups[gUnknown_02031590.unk16];
        break;
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_SPHEAL:
        unk1334_0->unk1 = 1;
        spriteGroup = gMain.unk44[0];
        break;
    case FIELD_RAYQUAZA:
        if (unk1334_0->unk1 > 2) {
            unk1334_0->unk1 = 2;
        }
        spriteGroup = gMain.unk44[0];
        break;
    default:
        unk1334_0->unk1 = 3;
        spriteGroup = gMain.unk44[0];
        break;
    }

    r5 = gCurrentPinballGame->ball->unkA >> 12;
    DmaCopy16(3, &gUnknown_083BB16C[r5 + gCurrentPinballGame->unk5F6 * 17], (void *)VRAM + 0x10400, 0x80);

    unk1334_0->positionQ0.x = unk1334_0->positionQ1.x / 2;
    unk1334_0->positionQ0.y = unk1334_0->positionQ1.y / 2;

    spriteGroup->baseX = unk1334_0->positionQ0.x
        - (gCurrentPinballGame->unk4C + 7)
        - gCurrentPinballGame->unk2AA;
    spriteGroup->baseY = unk1334_0->positionQ0.y
        - 7
        - gCurrentPinballGame->unk4E
        - gCurrentPinballGame->unk5FC
        - gCurrentPinballGame->unkE6
        - gCurrentPinballGame->unk2AC
        - (gCurrentPinballGame->unk38C / 10);

    if (spriteGroup->baseY < -60)
        spriteGroup->baseY = -60;

    if (spriteGroup->baseY > 180)
        spriteGroup->baseY = 180;

    unk1334_0->unk24 = spriteGroup->baseX;
    unk1334_0->unk26 = spriteGroup->baseY;

    oam = &spriteGroup->oam[0];
    oamData = &gOamBuffer[oam->oamId];
    oamData->priority = unk1334_0->unk1;
    oamData->x = oam->xOffset + spriteGroup->baseX;

    if (unk1334_0->unk0)
        oamData->y = 200;
    else
        oamData->y = oam->yOffset + spriteGroup->baseY;

    if (gCurrentPinballGame->unk388)
    {
        spriteGroup = gMain.unk44[1];
        if (spriteGroup->available)
        {
            spriteGroup->baseX = unk1334_0->unk24 - 8;
            spriteGroup->baseY = unk1334_0->unk26 - 8;
            oam = &spriteGroup->oam[0];
            gOamBuffer[oam->oamId].x = oam->xOffset + spriteGroup->baseX;
            gOamBuffer[oam->oamId].y = oam->yOffset + spriteGroup->baseY;
        }

        if (gCurrentPinballGame->unk388 == 1 || gCurrentPinballGame->unk388 == 3)
        {
            if (gCurrentPinballGame->unk392 == 0)
            {
                gCurrentPinballGame->unk1F = 1;
                unk1334_0->velocity.x = 0;
                unk1334_0->velocity.y = 0;
                unk1334_0->unk6 = 0;
            }

            if (gCurrentPinballGame->unk392 == 150)
                spriteGroup->available = TRUE;

            if (gCurrentPinballGame->unk392 == 154)
                m4aSongNumStart(SE_UNKNOWN_0xF9);

            if (gCurrentPinballGame->unk392 > 149)
            {
                r5 = ((gCurrentPinballGame->unk392 - 150) % 66) / 6;
                DmaCopy16(3, &gUnknown_083BF16C[r5], (void *)VRAM + 0x10720, 0x200);
                unk1334_0->unk6 -= 40;
            }

            if ((gMain.unkF & -0x41) == 0) // 1011 1111
            {
                gCurrentPinballGame->unk392++;
                if (r5 >= 7 && r5 <= 10)
                {
                    DmaCopy16(3, &gUnknown_08137E14[(s16) (gCurrentPinballGame->unk5F6 + 4)], (void *)PLTT + 0x220, 0x20);
                }
            }

            if (gCurrentPinballGame->unk392 == 186)
                unk1334_0->unk0 = 0;

            if (gCurrentPinballGame->unk392 > 215)
            {
                if (gCurrentPinballGame->unk388 == 3)
                    gCurrentPinballGame->unk294 = 2;

                gCurrentPinballGame->unk388 = 0;
                spriteGroup->available = FALSE;
                gCurrentPinballGame->unk1F = 0;
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)PLTT + 0x220, 0x20);
            }
        }
        else
        {
            if (gCurrentPinballGame->unk392 == 0)
            {
                gCurrentPinballGame->unk1F = 1;
                unk1334_0->velocity.x = 0;
                unk1334_0->velocity.y = 0;
                unk1334_0->unk6 = 0;
            }

            if (gCurrentPinballGame->unk392 == 5)
                spriteGroup->available = TRUE;

            if (gCurrentPinballGame->unk392 > 4)
            {
                r5 = ((gCurrentPinballGame->unk392 - 5) % 63 / 7);
                DmaCopy16(3, &gUnknown_083BDF6C[r5], (void *)VRAM + 0x10720, 0x200);
                unk1334_0->unk6 -= 20;
            }

            if ((gMain.unkF & -0x81) == 0) // 0111 1111
                gCurrentPinballGame->unk392++;

            if (gCurrentPinballGame->unk392 == 23)
                m4aSongNumStart(SE_UNKNOWN_0xF9);

            if (gCurrentPinballGame->unk392 == 20)
                unk1334_0->unk0 = 1;

            if (gCurrentPinballGame->unk392 > 67)
            {
                gCurrentPinballGame->unk388 = 0;
                spriteGroup->available = FALSE;
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)PLTT + 0x220, 0x20);
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->unk5F7 == 0 && gCurrentPinballGame->unk5F8 != 0)
        {
            gCurrentPinballGame->unk5F8 -= 1;
            if (gCurrentPinballGame->unk5F8 == 0)
            {
                if (gCurrentPinballGame->unk5F6 > 0)
                {
                    gCurrentPinballGame->unk5F6 -= 1;
                    if (gCurrentPinballGame->unk5F6 > 0)
                    {
                        gCurrentPinballGame->unk5F8 = 60 * 60;
                    }
                }
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)PLTT + 0x220, 0x20);
            }
        }
    }

    switch (gMain.selectedField) {
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_RAYQUAZA:
        if (gCurrentPinballGame->unk71)
        {
            for (i = 4; i > 0; i--)
            {
                gCurrentPinballGame->unkD0[i].x = gCurrentPinballGame->unkD0[i - 1].x;
                gCurrentPinballGame->unkD0[i].y = gCurrentPinballGame->unkD0[i - 1].y;
            }
            gCurrentPinballGame->unkD0[0].x = unk1334_0->positionQ0.x - 7;
            gCurrentPinballGame->unkD0[0].y = unk1334_0->positionQ0.y - 7;

            for (i = 0; i < 2; i++)
            {
                spriteGroup = gMain.unk44[i + 6];
                if (spriteGroup->available)
                {
                    oam = &spriteGroup->oam[0];
                    oamData = &gOamBuffer[oam->oamId];
                    oamData->priority = unk1334_0->unk1;
                    oamData->x = oam->xOffset
                        + (gCurrentPinballGame->unkD0[(i + 1) * 2].x
                        - gCurrentPinballGame->unk4C);

                    if (i == 0)
                    {
                        oamData->y = oam->yOffset
                            + (gCurrentPinballGame->unkD0[2].y
                            - gCurrentPinballGame->unk4E
                            - gCurrentPinballGame->unkE6);
                    }
                    else if (i == 1)
                    {
                        if ((gMain.systemFrameCount & i) == 0)
                        {
                            oamData->y = oam->yOffset
                                + (gCurrentPinballGame->unkD0[4].y
                                - gCurrentPinballGame->unk4E
                                - gCurrentPinballGame->unkE6);
                        }
                        else
                        {
                            oamData->y = 200;
                        }
                    }
                }
            }
            gMain.unk44[6]->available = TRUE;
            gMain.unk44[7]->available = TRUE;
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                spriteGroup = gMain.unk44[i + 6];
                if (spriteGroup->available)
                {
                    oam = &spriteGroup->oam[0];
                    oamData = &gOamBuffer[oam->oamId];
                    oamData->priority = unk1334_0->unk1;
                    oamData->x = oam->xOffset
                        + (gCurrentPinballGame->unkD0[(i + 1) * 2].x - gCurrentPinballGame->unk4C);
                    oamData->y = 200;
                }
            }
            gMain.unk44[6]->available = FALSE;
            gMain.unk44[7]->available = FALSE;
        }
    }
}
