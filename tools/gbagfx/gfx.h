// Copyright (c) 2015 YamaArashi

#ifndef GFX_H
#define GFX_H

#include <stdint.h>
#include <stdbool.h>

struct Color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

struct Palette {
	struct Color colors[256];
	int numColors;
};

struct NonAffineTile {
    unsigned short index:10;
    unsigned short hflip:1;
    unsigned short vflip:1;
    unsigned short palno:4;
} __attribute__((packed));

struct Tilemap {
    union {
        struct NonAffineTile *non_affine;
        unsigned char *affine;
    } data;
    int size;
};

struct Image {
	int width;
	int height;
	int bitDepth;
	unsigned char *pixels;
	bool hasPalette;
	struct Palette palette;
	int paletteMapSize;
	unsigned char *paletteMap;
	bool hasTransparency;
	struct Tilemap tilemap;
	bool isAffine;
};

enum NumTilesMode {
    NUM_TILES_IGNORE,
    NUM_TILES_WARN,
    NUM_TILES_ERROR,
};

typedef struct {
    int x;
    int y;
} TileCoord;

#define MAX_OAM_TILE_SIDE_LENGTH 32
#define MAX_OAM_TILE_SIDE_LENGTH_SQUARED MAX_OAM_TILE_SIDE_LENGTH * MAX_OAM_TILE_SIDE_LENGTH

void ReadTileImage(char *path, int tilesWidth, int metatileWidth, int metatileHeight, struct Image *image, bool invertColors, bool optomized_2n_map, char *oamSequenceFilePath);
void WriteTileImage(char *path, enum NumTilesMode numTilesMode, int numTiles, int metatileWidth, int metatileHeight, struct Image *image, bool invertColors, bool optomized_2n_map, char *oamSequenceFilePath);
void ReadPlainImage(char *path, int dataWidth, struct Image *image, bool invertColors);
void WritePlainImage(char *path, int dataWidth, struct Image *image, bool invertColors);
void FreeImage(struct Image *image);
void ReadGbaPalette(char *path, struct Palette *palette);
void WriteGbaPalette(char *path, struct Palette *palette);
void Convert4BppImageWithPaletteMap(struct Image *image);

#endif // GFX_H
