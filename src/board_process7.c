#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"

extern const u32 gUnknown_083BF16C[][0x80];
extern const u32 gUnknown_083BDF6C[][0x80];

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

    if (!gCurrentPinballGame->unk5F7 && gCurrentPinballGame->ballUpgradeCounter > 0)
    {
        if (--gCurrentPinballGame->ballUpgradeCounter == 0)
        {
            if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
            {
                gCurrentPinballGame->ballUpgradeType--;

                if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                    gCurrentPinballGame->ballUpgradeCounter = 3600;
            }

            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
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
        SetMatrixScale(currentBallState->scale, currentBallState->scale, 0);

        spriteGroup->baseX = -(gCurrentPinballGame->unk4C + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->unk2AA;
        spriteGroup->baseY = -(gCurrentPinballGame->unk4E + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->unk5FC - gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk166;

        currentBallState->screenPosition.x = spriteGroup->baseX;
        currentBallState->screenPosition.y = spriteGroup->baseY;

        oam = &spriteGroup->oam[0];
        oamData = &gOamBuffer[oam->oamId];

        if (currentBallState->oamPriority == 3)
        {
            if (currentBallState->positionQ0.y > 248)
                oamData->priority = 2;
            else
                oamData->priority = 3;
        }
        else
            oamData->priority = currentBallState->oamPriority;

        r8 = r8; // this fools the compiler into thinking r8 holds something that could need sign extending/truncation
        DmaCopy16(3, gUnknown_083BB16C[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)0x6010400, 0x80);

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
        SetMatrixScale(currentBallState->scale, currentBallState->scale, 0);

        spriteGroup->baseX = -(gCurrentPinballGame->unk4C + 7) + currentBallState->positionQ0.x - gCurrentPinballGame->unk2AA;
        spriteGroup->baseY = -(gCurrentPinballGame->unk4E + 7) + currentBallState->positionQ0.y - gCurrentPinballGame->unk5FC - gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk166;

        currentBallState->screenPosition.x = spriteGroup->baseX;
        currentBallState->screenPosition.y = spriteGroup->baseY;

        oam = &spriteGroup->oam[0];
        oamData = &gOamBuffer[oam->oamId];

        if (currentBallState->oamPriority == 3)
        {
            if (currentBallState->positionQ0.y > 248)
                oamData->priority = 2;
            else
                oamData->priority = 3;
        }
        else
            oamData->priority = currentBallState->oamPriority;

        DmaCopy16(3, gUnknown_083BB16C[r8 + gCurrentPinballGame->ballUpgradeType * 17], (void *)0x6010400, 0x80);

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

                oamData->priority = currentBallState->oamPriority;
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

                oamData->priority = currentBallState->oamPriority;
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

        gOamBuffer[oam->oamId].priority = currentBallState->oamPriority;

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
        unk1334_0->oamPriority = 2;
        spriteGroup = &gMain_spriteGroups[gUnknown_02031590[22]];
        break;
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
    case FIELD_SPHEAL:
        unk1334_0->oamPriority = 1;
        spriteGroup = gMain.unk44[0];
        break;
    case FIELD_RAYQUAZA:
        if (unk1334_0->oamPriority > 2)
            unk1334_0->oamPriority = 2;
        spriteGroup = gMain.unk44[0];
        break;
    default:
        unk1334_0->oamPriority = 3;
        spriteGroup = gMain.unk44[0];
        break;
    }

    r5 = gCurrentPinballGame->ball->unkA >> 12;
    DmaCopy16(3, &gUnknown_083BB16C[r5 + gCurrentPinballGame->ballUpgradeType * 17], (void *)VRAM + 0x10400, 0x80);

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

    unk1334_0->screenPosition.x = spriteGroup->baseX;
    unk1334_0->screenPosition.y = spriteGroup->baseY;

    oam = &spriteGroup->oam[0];
    oamData = &gOamBuffer[oam->oamId];
    oamData->priority = unk1334_0->oamPriority;
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
            spriteGroup->baseX = unk1334_0->screenPosition.x - 8;
            spriteGroup->baseY = unk1334_0->screenPosition.y - 8;
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
                    DmaCopy16(3, &gUnknown_08137E14[(s16) (gCurrentPinballGame->ballUpgradeType + 4)], (void *)PLTT + 0x220, 0x20);
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
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
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
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
            }
        }
    }
    else
    {
        if (gCurrentPinballGame->unk5F7 == 0 && gCurrentPinballGame->ballUpgradeCounter != 0)
        {
            gCurrentPinballGame->ballUpgradeCounter--;
            if (gCurrentPinballGame->ballUpgradeCounter == 0)
            {
                if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                {
                    gCurrentPinballGame->ballUpgradeType--;
                    if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                    {
                        gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
                    }
                }
                DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)PLTT + 0x220, 0x20);
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
                    oamData->priority = unk1334_0->oamPriority;
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
                    oamData->priority = unk1334_0->oamPriority;
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
