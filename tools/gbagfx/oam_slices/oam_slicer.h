#ifndef GUARD_OAM_SLICER_H
#define GUARD_OAM_SLICER_H
#include "../gfx.h"

enum OamShapeEnum {
    OAM_SQUARE = 0,
    OAM_H_RECTANGLE = 1,
    OAM_V_RECTANGLE = 2
};

enum OamSizeEnum {
    OAM_SIZE_3 = 3,
    OAM_SIZE_2 = 2,
    OAM_SIZE_1 = 1,
    OAM_SIZE_0 = 0
};

typedef struct OamShape {
    unsigned short width;
    unsigned short height;
    enum OamSizeEnum oamSize;
    enum OamShapeEnum mode;
} OamShape;

typedef struct OamOverrideSegment {
    unsigned short offX;
    unsigned short offY;
    unsigned short width;
    unsigned short height;
} OamOverrideSegment;

typedef struct OamOverride {
    unsigned short width;
    unsigned short height;
    unsigned short numSegments;
    const struct OamOverrideSegment *segments;
} OamOverride;

typedef struct OamSegment {
    struct OamSegment *next;
    short offX;
    short offY;
    unsigned short width;  // in tiles
    unsigned short height; // in tiles
} OamSegment;

void print_oam_segments(struct OamSegment *segList);
void free_oam_segments(struct OamSegment *segList);
int getOamTileIndex(int width, int height, TileCoord *tileCoordinates);
void PrintTileCoords(TileCoord *tileSequence, int tile_count);

#endif // GUARD_OAM_SLICER_H