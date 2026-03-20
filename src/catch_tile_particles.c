#include "global.h"
#include "main.h"

extern const s16 gHatchRevealPieceIndices[][16];
extern const s16 gHatchPieceVelocities[][2];
extern const s16 gHatchPieceAffineModes[];
extern const s16 gHatchPieceMatrixNums[6];
extern const s16 gHatchPieceAnimIndices[][12];
extern const u16 gHatchParticleOamAttributes[][3];
extern const u16 gHatchAnimOamAttributes[][3];

void InitSequentialTileParticles(void)
{
    s16 i;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->tileParticlePos[i].x = 0;
        gCurrentPinballGame->tileParticlePos[i].y = 0;
        gCurrentPinballGame->tileParticleVel[i].x = 200 - (Random() % 400);
        gCurrentPinballGame->tileParticleVel[i].y = 80 - (Random() % 550);
        gCurrentPinballGame->tileParticleGravity[i] = 10 + (Random() % 15);
    }

    gCurrentPinballGame->particleAnimTimer = 0;
    gMain.fieldSpriteGroups[12]->available = 1;
}

void UpdateSequentialTileParticles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    struct Vector16 tempVector;

    group = gMain.fieldSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            var0 = gHatchPieceAnimIndices[i][gCurrentPinballGame->particleAnimTimer / 4];
            gCurrentPinballGame->tileParticleVel[i].y += gCurrentPinballGame->tileParticleGravity[i];
            if (gCurrentPinballGame->tileParticlePos[i].y < 14000)
            {
                gCurrentPinballGame->tileParticlePos[i].x += gCurrentPinballGame->tileParticleVel[i].x;
                gCurrentPinballGame->tileParticlePos[i].y += gCurrentPinballGame->tileParticleVel[i].y;
            }

            tempVector.x = ((gCurrentPinballGame->hatchGridCellIndex % 3) * 16 +  96u - gCurrentPinballGame->cameraXOffset) + (gCurrentPinballGame->tileParticlePos[i].x / 100);
            tempVector.y = ((gCurrentPinballGame->hatchGridCellIndex / 3) * 16 + 300u - gCurrentPinballGame->cameraYOffset) + (gCurrentPinballGame->tileParticlePos[i].y / 100);
            if (tempVector.y >= 200)
                tempVector.y = 200;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchAnimOamAttributes[var0][0];
            *dst++ = gHatchAnimOamAttributes[var0][1];
            *dst++ = gHatchAnimOamAttributes[var0][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
        }
    }

    if (gCurrentPinballGame->particleAnimTimer < 48)
    {
        gCurrentPinballGame->particleAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0x7100;
        gMain.fieldSpriteGroups[12]->available = 0;
    }
}

void InitBurstTileParticles(void)
{
    s16 i;
    const struct Vector16 *var0;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->tileParticlePos[i].x = ((i % 3) * 16 - 24) * 100;
        gCurrentPinballGame->tileParticlePos[i].y = ((i / 3) * 16 - 28) * 100;
        gCurrentPinballGame->tileParticleVel[i].x = gHatchPieceVelocities[i][0] - ((Random() % 200) - 60);
        gCurrentPinballGame->tileParticleVel[i].y = gHatchPieceVelocities[i][1] - ((Random() % 200) - 60);
        gCurrentPinballGame->tileParticleGravity[i] = (Random() % 4) + 1;
    }

    gCurrentPinballGame->tileParticlePos[0].x = -5600;
    gCurrentPinballGame->tileParticlePos[0].y = -6000;
    gCurrentPinballGame->tileParticleGravity[0] = 3;
    gCurrentPinballGame->tileParticlePos[4].x = -4000;
    gCurrentPinballGame->tileParticlePos[4].y = -4400;
    gCurrentPinballGame->tileParticleGravity[4] = 3;
    gCurrentPinballGame->particleAnimTimer = 0;
    gMain.fieldSpriteGroups[12]->available = 1;
}

void UpdateBurstTileParticles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 index;
    struct Vector16 tempVector;
    s16 sp0[6];
    s16 scale;

    group = gMain.fieldSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            index = gCurrentPinballGame->particleAnimTimer / 5;
            sp0[i] = gHatchRevealPieceIndices[i][index];
            if (gCurrentPinballGame->particleAnimTimer > 4)
            {
                gCurrentPinballGame->tileParticleVel[i].y += gCurrentPinballGame->tileParticleGravity[i];
                if (i == 4)
                    gCurrentPinballGame->tileParticleVel[i].x += gCurrentPinballGame->tileParticleGravity[4] * 4;

                gCurrentPinballGame->tileParticlePos[i].x += gCurrentPinballGame->tileParticleVel[i].x;
                gCurrentPinballGame->tileParticlePos[i].y += gCurrentPinballGame->tileParticleVel[i].y;
            }

            tempVector.x = (gCurrentPinballGame->tileParticlePos[i].x / 100) +  96u - gCurrentPinballGame->cameraXOffset;
            tempVector.y = (gCurrentPinballGame->tileParticlePos[i].y / 100) + 304u - gCurrentPinballGame->cameraYOffset;
            if (tempVector.y >= 160)
                tempVector.y = 160;

            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchParticleOamAttributes[sp0[i]][0];
            *dst++ = gHatchParticleOamAttributes[sp0[i]][1];
            *dst++ = gHatchParticleOamAttributes[sp0[i]][2];

            gOamBuffer[oamSimple->oamId].x += tempVector.x;
            gOamBuffer[oamSimple->oamId].y += tempVector.y;
            gOamBuffer[oamSimple->oamId].affineMode = gHatchPieceAffineModes[i];
            gOamBuffer[oamSimple->oamId].matrixNum = gHatchPieceMatrixNums[i];
        }
    }

    scale = ((gCurrentPinballGame->particleAnimTimer * gCurrentPinballGame->particleAnimTimer * 0xD0) / 0x510) + 0x80;
    if (sp0[0] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 2);

    scale = 0x80;
    if (sp0[1] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 3);

    scale = ((gCurrentPinballGame->particleAnimTimer * gCurrentPinballGame->particleAnimTimer * 0x100) / 0x510) + 0x80;
    if (sp0[3] == 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 4);

    scale = ((gCurrentPinballGame->particleAnimTimer * gCurrentPinballGame->particleAnimTimer * 0x1C0) / 0x510) + 0x40;
    if (sp0[4]== 4)
        scale = -scale;
    SetMatrixScale(scale, scale, 5);

    if (gCurrentPinballGame->particleAnimTimer < 47)
    {
        gCurrentPinballGame->particleAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0x7100;
        gMain.fieldSpriteGroups[12]->available = 0;
    }
}
