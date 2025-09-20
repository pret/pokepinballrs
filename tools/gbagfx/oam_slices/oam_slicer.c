#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../gfx.h"
#include "oam_slicer.h"


// Define the available OAM shapes.
// Ordered by the width, then height.
const struct OamShape oamShapes[] = {
    {8, 8, OAM_SIZE_3, OAM_SQUARE}, {8, 4, OAM_SIZE_3, OAM_H_RECTANGLE}, {4, 8, OAM_SIZE_3, OAM_V_RECTANGLE},
    {4, 4, OAM_SIZE_2, OAM_SQUARE}, {4, 2, OAM_SIZE_2, OAM_H_RECTANGLE}, {4, 1, OAM_SIZE_1, OAM_H_RECTANGLE},
    {2, 4, OAM_SIZE_2, OAM_V_RECTANGLE}, {2, 2, OAM_SIZE_1, OAM_SQUARE}, {2, 1, OAM_SIZE_0, OAM_H_RECTANGLE},
    {1, 4, OAM_SIZE_1, OAM_V_RECTANGLE}, {1, 2, OAM_SIZE_0, OAM_V_RECTANGLE}, {1, 1, OAM_SIZE_0, OAM_SQUARE},
};

// Define manual overrides for specific sprite dimentions, which were observed using a different sequencing 
// than the standard algorithm would produce. 
const struct OamOverride oamShapeOverrides[] = {
    { 13, 8, 5, (const struct OamOverrideSegment[]) { //2 8x4 segments, rather than a single 8x8
        {0, 0, 8, 4}, {0, 4, 8, 4}, {8, 0, 4, 8}, {12, 0, 1, 4}, {12, 4, 1, 4}
    }},
    { 6, 3, 4, (const struct OamOverrideSegment[]) { //ordering of middle 2 segments
        {0,0,4,2}, {0,2,4,1}, {4,0,2,2}, {4,2,2,1}
    }},
};

// Function to check if a shape fits at position (x, y)
static bool check_oam_shape_fits(int x, int y, int width, int height, int shapeW, int shapeH) {
    return (x + shapeW <= width && y + shapeH <= height);
}

// Helper to allocate new segment
static struct OamSegment *new_oam_segment(int x, int y, int w, int h) {
    struct OamSegment *seg = malloc(sizeof(struct OamSegment));
    seg->offX = x;
    seg->offY = y;
    seg->width = w;
    seg->height = h;
    seg->next = NULL;
    return seg;
}

static struct OamSegment *check_oam_manual_override(int width, int height) {
    for (int i = 0; i < sizeof(oamShapeOverrides)/sizeof(oamShapeOverrides[0]); ++i) {
        const struct OamOverride *ovr = &oamShapeOverrides[i];
        if (ovr->width == width && ovr->height == height) {
            struct OamSegment *head = NULL, **tail = &head;
            for (int j = 0; j < ovr->numSegments; ++j) {
                const struct OamOverrideSegment *seg = &ovr->segments[j];
                *tail = new_oam_segment(seg->offX, seg->offY, seg->width, seg->height);
                tail = &((*tail)->next);
            }
            return head;
        }
    }
    return NULL;
}

static OamSegment *slice_sprite_to_oam(int width, int height) {
    struct OamSegment *head = NULL;
    struct OamSegment **tail = &head;

    // Tilemap to track used space 
    bool used[MAX_OAM_TILE_SIDE_LENGTH][MAX_OAM_TILE_SIDE_LENGTH];
    for (int i = 0; i < MAX_OAM_TILE_SIDE_LENGTH; ++i)
        for (int j = 0; j < MAX_OAM_TILE_SIDE_LENGTH; ++j)
            used[i][j] = false;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (used[y][x])
                continue;

            // Try each shape in order
            for (int i = 0; i < sizeof(oamShapes)/sizeof(oamShapes[0]); ++i) {
                struct OamShape shape = oamShapes[i];
                if (check_oam_shape_fits(x, y, width, height, shape.width, shape.height)) {
                    // Check if region is free
                    bool collision = false;
                    for (int dy = 0; dy < shape.height && !collision; ++dy)
                        for (int dx = 0; dx < shape.width && !collision; ++dx)
                            if (used[y + dy][x + dx])
                                collision = true;

                    if (!collision) {
                        // Mark region used
                        for (int dy = 0; dy < shape.height; ++dy)
                            for (int dx = 0; dx < shape.width; ++dx)
                                used[y + dy][x + dx] = true;

                        // Add segment
                        *tail = new_oam_segment(x, y, shape.width, shape.height);
                        tail = &((*tail)->next);
                        break;
                    }
                }
            }
        }
    }

    return head;
}

void print_oam_segments(struct OamSegment *segList) {
    printf("OAM Segments: ");
    while (segList) {
        printf("{%d,%d,%dx%d}", segList->offX, segList->offY, segList->width, segList->height);
        segList = segList->next;
        if (segList) printf(", ");
    }
    printf("\n");
}

int getOamTileIndex(int width, int height, TileCoord *tileCoordinates) {
    int tileIndex = 0;
    int tileCount = width * height;
    
    struct OamSegment *segments;
    segments = check_oam_manual_override(width, height);
    if (segments == NULL) {
        segments = slice_sprite_to_oam(width, height);
    }

    struct OamSegment *segment = segments;
    while (segment) {
        for (int y = 0; y < segment->height; ++y) {
            for (int x = 0; x < segment->width; ++x) {
                tileCoordinates[tileIndex].x = segment->offX + x;
                tileCoordinates[tileIndex].y = segment->offY + y;
                ++tileIndex;
            }
        }
        segment = segment->next;
    }

    free_oam_segments(segments);
    return tileCount;
}

void free_oam_segments(struct OamSegment *segList) {
    while (segList) {
        struct OamSegment *next = segList->next;
        free(segList);
        segList = next;
    }
}

void PrintTileCoords(TileCoord *tileSequence, int tile_count)
{ 
	printf("Generated oamTileSequence (total: %d):\n", tile_count);
    for (int i = 0; i < tile_count; i++) {
        printf("Tile %d: (%d, %d)\n", i, tileSequence[i].x, tileSequence[i].y);
    }
}