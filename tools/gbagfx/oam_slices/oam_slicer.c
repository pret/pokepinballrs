#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../gfx.h"
#include "oam_slicer.h"
#include "../util.h"


// Load oam sequence file.
// JSON matching the schema provided by the user.
// Returns number of segments, 0 if none, or -1 on IO/error.
int oam_sequence_load_from_file(const char *path, OamSequence **outSeq) {
    if (path == NULL) return 0;
    int fileSize;
    unsigned char *buf = ReadWholeFile((char*)path, &fileSize);
    if (buf == NULL) return -1;

    // skip leading whitespace
    char *p = (char*)buf;
    char *end = (char*)buf + fileSize;
    while (p < end && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) ++p;

    // If JSON (starts with '{'), parse JSON-ish format for our schema
    if (p < end && *p == '{') {
        int tilecount = -1;

        // find "tilecount"
        char *tok = strstr(p, "\"tilecount\"");
        if (tok) {
            char *col = strchr(tok, ':');
            if (col) tilecount = atoi(col + 1);
        }

        // find "pngsize"
        tok = strstr(p, "\"pngsize\"");
        int png_w = -1, png_h = -1;
        int png_tiles = 0;
        if (tok) {
            char *col = strchr(tok, ':');
            if (col) {
                char *quote1 = strchr(col, '"');
                if (quote1) {
                    char *quote2 = strchr(quote1 + 1, '"');
                    if (quote2) {
                        int a, b;
                        if (sscanf(quote1 + 1, "%d x %d", &a, &b) == 2 || sscanf(quote1 + 1, "%dx%d", &a, &b) == 2) {
                            png_w = a;
                            png_h = b;
                            png_tiles = png_w * png_h;
                        }
                    }
                }
            }
        }

        // find pieces array
        tok = strstr(p, "\"pieces\"");
        if (!tok) {
            free(buf);
            *outSeq = NULL;
            return -1;
        }

        char *arrstart = strchr(tok, '[');
        if (!arrstart) { free(buf); *outSeq = NULL; return -1; }

        int maxSegments = 0;
        for (char *q = arrstart; q < end; ++q) if (*q == '{') ++maxSegments;
        if (maxSegments == 0) { free(buf); *outSeq = NULL; return 0; }

        struct OamOverrideSegment *arr = malloc(sizeof(struct OamOverrideSegment) * maxSegments);
        int idx = 0;

        char *q = arrstart;
        while (q < end) {
            char *obj = strchr(q, '{');
            if (!obj) break;
            char *objend = strchr(obj, '}');
            if (!objend) break;

            int offX = 0, offY = 0, w = 0, h = 0;
            int spacer = 0;
            char *posTok = strstr(obj, "\"pos\"");
            if (posTok && posTok < objend) {
                char *col = strchr(posTok, ':');
                if (col) {
                    char *q1 = strchr(col, '"');
                    if (q1 && q1 < objend) {
                        char *q2 = strchr(q1 + 1, '"');
                        if (q2 && q2 < objend) {
                            sscanf(q1 + 1, "%d,%d", &offX, &offY);
                        }
                    }
                }
            }

            char *sizeTok = strstr(obj, "\"size\"");
            if (sizeTok && sizeTok < objend) {
                char *col = strchr(sizeTok, ':');
                if (col) {
                    char *q1 = strchr(col, '"');
                    if (q1 && q1 < objend) {
                        char *q2 = strchr(q1 + 1, '"');
                        if (q2 && q2 < objend) {
                            if (sscanf(q1 + 1, "%d x %d", &w, &h) != 2) {
                                sscanf(q1 + 1, "%dx%d", &w, &h);
                            }
                        }
                    }
                }
            }

            char *spTok = strstr(obj, "\"spacer\"");
            if (spTok && spTok < objend) {
                char *col = strchr(spTok, ':');
                if (col) {
                    if (strstr(col, "true") != NULL) spacer = 1;
                    else spacer = atoi(col + 1);
                }
            }

            if (!spacer) {
                if (!is_valid_oam_shape(w, h)) {
                    free(arr);
                    free(buf);
                    *outSeq = NULL;
                    return -1;
                }
            }

            arr[idx].offX = (unsigned short)offX;
            arr[idx].offY = (unsigned short)offY;
            arr[idx].width = (unsigned short)w;
            arr[idx].height = (unsigned short)h;
            arr[idx].spacer = spacer ? true : false;
            ++idx;

            q = objend + 1;
        }

        if (tilecount < 0) {
            int sum = 0;
            for (int i = 0; i < idx; ++i) if (!arr[i].spacer) sum += arr[i].width * arr[i].height;
            tilecount = sum;
        }

        OamSequence *seq = malloc(sizeof(OamSequence));
        seq->segments = arr;
        seq->numSegments = idx;
        seq->tilecount = tilecount;
        seq->png_tiles = png_tiles;
        seq->png_width = png_w;
        seq->png_height = png_h;

        free(buf);
        if (idx == 0) { free(arr); free(seq); *outSeq = NULL; return 0; }
        *outSeq = seq;
        return idx;
    }

    free(buf);
    *outSeq = NULL;
    return -1;
}

void oam_sequence_free(OamSequence *seq) {
    if (!seq) return;
    if (seq->segments) free(seq->segments);
    free(seq);
}

// Define the available OAM shapes.
// Ordered by the width, then height.
const struct OamShape oamShapes[] = {
    {8, 8, OAM_SIZE_3, OAM_SQUARE}, {8, 4, OAM_SIZE_3, OAM_H_RECTANGLE}, {4, 8, OAM_SIZE_3, OAM_V_RECTANGLE},
    {4, 4, OAM_SIZE_2, OAM_SQUARE}, {4, 2, OAM_SIZE_2, OAM_H_RECTANGLE}, {4, 1, OAM_SIZE_1, OAM_H_RECTANGLE},
    {2, 4, OAM_SIZE_2, OAM_V_RECTANGLE}, {2, 2, OAM_SIZE_1, OAM_SQUARE}, {2, 1, OAM_SIZE_0, OAM_H_RECTANGLE},
    {1, 4, OAM_SIZE_1, OAM_V_RECTANGLE}, {1, 2, OAM_SIZE_0, OAM_V_RECTANGLE}, {1, 1, OAM_SIZE_0, OAM_SQUARE},
};

bool is_valid_oam_shape(int width, int height) {
    for (int i = 0; i < sizeof(oamShapes)/sizeof(oamShapes[0]); ++i) {
        if (oamShapes[i].width == width && oamShapes[i].height == height)
            return true;
    }
    return false;
}

// Define manual overrides for specific sprite dimentions, which were observed using a different sequencing
// than the standard algorithm would produce.
const struct OamOverride oamShapeOverrides[] = {
    { 13, 8, 5, (const struct OamOverrideSegment[]) { //2 8x4 segments, rather than a single 8x8
        {0, 0, 8, 4, false}, {0, 4, 8, 4, false}, {8, 0, 4, 8, false}, {12, 0, 1, 4, false}, {12, 4, 1, 4, false}
    }},
    { 6, 3, 4, (const struct OamOverrideSegment[]) { //ordering of middle 2 segments
        {0,0,4,2,false}, {0,2,4,1,false}, {4,0,2,2,false}, {4,2,2,1,false}
    }},
};

// Function to check if a shape fits at position (x, y)
static bool check_oam_shape_fits(int x, int y, int width, int height, int shapeW, int shapeH) {
    return (x + shapeW <= width && y + shapeH <= height);
}

// Helper to allocate new segment (spacer marks a region that has no tile data)
static struct OamSegment *new_oam_segment(int x, int y, int w, int h, bool spacer) {
    struct OamSegment *seg = malloc(sizeof(struct OamSegment));
    seg->offX = x;
    seg->offY = y;
    seg->width = w;
    seg->height = h;
    seg->spacer = spacer;
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
                *tail = new_oam_segment(seg->offX, seg->offY, seg->width, seg->height, seg->spacer);
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
                        *tail = new_oam_segment(x, y, shape.width, shape.height, false);
                        tail = &((*tail)->next);
                        break;
                    }
                }
            }
        }
    }

    return head;
}

int getOamTileIndexEx(int width, int height, TileCoord *tileCoordinates, const struct OamOverrideSegment *sequence, int numSequenceSegments, struct OamSegment **outSegments) {
    int tileIndex = 0;

    struct OamSegment *segments = NULL;

    if (sequence != NULL && numSequenceSegments > 0) {
        struct OamSegment *head = NULL, **tail = &head;
        for (int j = 0; j < numSequenceSegments; ++j) {
            const struct OamOverrideSegment *seg = &sequence[j];
            *tail = new_oam_segment(seg->offX, seg->offY, seg->width, seg->height, seg->spacer);
            tail = &((*tail)->next);
        }
        segments = head;
    } else {
        segments = check_oam_manual_override(width, height);
        if (segments == NULL) {
            segments = slice_sprite_to_oam(width, height);
        }
    }

    struct OamSegment *segment = segments;
    while (segment) {
        if (!segment->spacer) {
            for (int y = 0; y < segment->height; ++y) {
                for (int x = 0; x < segment->width; ++x) {
                    tileCoordinates[tileIndex].x = segment->offX + x;
                    tileCoordinates[tileIndex].y = segment->offY + y;
                    ++tileIndex;
                }
            }
        }
        segment = segment->next;
    }

    if (outSegments)
        *outSegments = segments;
    else
        free_oam_segments(segments);

    return tileIndex;
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
    // legacy wrapper: no custom sequence provided
    return getOamTileIndexEx(width, height, tileCoordinates, NULL, 0, NULL);
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