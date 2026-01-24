const struct PokemonSpecies gSpeciesInfo[NUM_SPECIES] = {
    [SPECIES_TREECKO] = {
        .mainSeriesIndexNumber = 277,
        .unk2 = {
            6, 34, 39, 83, 83
        },
        .name = {
            'T', 'R', 'E', 'E', 'C', 'K', 'O', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GROVYLE
    },
    [SPECIES_GROVYLE] = {
        .mainSeriesIndexNumber = 278,
        .unk2 = {
            53, 79, 69, 19, 40
        },
        .name = {
            'G', 'R', 'O', 'V', 'Y', 'L', 'E', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SCEPTILE
    },
    [SPECIES_SCEPTILE] = {
        .mainSeriesIndexNumber = 279,
        .unk2 = {
            53, 79, 5, 1, 45
        },
        .name = {
            'S', 'C', 'E', 'P', 'T', 'I', 'L', 'E', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORCHIC] = {
        .mainSeriesIndexNumber = 280,
        .unk2 = {
            0, 16, 78, 34, 83
        },
        .name = {
            'T', 'O', 'R', 'C', 'H', 'I', 'C', ' ', ' ', ' '
        },
        .catchIndex = 1,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_COMBUSKEN
    },
    [SPECIES_COMBUSKEN] = {
        .mainSeriesIndexNumber = 281,
        .unk2 = {
            43, 5, 11, 78, 34
        },
        .name = {
            'C', 'O', 'M', 'B', 'U', 'S', 'K', 'E', 'N', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BLAZIKEN
    },
    [SPECIES_BLAZIKEN] = {
        .mainSeriesIndexNumber = 282,
        .unk2 = {
            62, 11, 78, 81, 34
        },
        .name = {
            'B', 'L', 'A', 'Z', 'I', 'K', 'E', 'N', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MUDKIP] = {
        .mainSeriesIndexNumber = 283,
        .unk2 = {
            31, 54, 51, 42, 2
        },
        .name = {
            'M', 'U', 'D', 'K', 'I', 'P', ' ', ' ', ' ', ' '
        },
        .catchIndex = 2,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MARSHTOMP
    },
    [SPECIES_MARSHTOMP] = {
        .mainSeriesIndexNumber = 284,
        .unk2 = {
            22, 30, 7, 42, 81
        },
        .name = {
            'M', 'A', 'R', 'S', 'H', 'T', 'O', 'M', 'P', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWAMPERT
    },
    [SPECIES_SWAMPERT] = {
        .mainSeriesIndexNumber = 285,
        .unk2 = {
            38, 49, 38, 81, 53
        },
        .name = {
            'S', 'W', 'A', 'M', 'P', 'E', 'R', 'T', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_POOCHYENA] = {
        .mainSeriesIndexNumber = 286,
        .unk2 = {
            71, 16, 3, 20, 83
        },
        .name = {
            'P', 'O', 'O', 'C', 'H', 'Y', 'E', 'N', 'A', ' '
        },
        .catchIndex = 3,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MIGHTYENA
    },
    [SPECIES_MIGHTYENA] = {
        .mainSeriesIndexNumber = 287,
        .unk2 = {
            49, 38, 3, 20, 83
        },
        .name = {
            'M', 'I', 'G', 'H', 'T', 'Y', 'E', 'N', 'A', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZIGZAGOON] = {
        .mainSeriesIndexNumber = 288,
        .unk2 = {
            53, 49, 52, 49, 30
        },
        .name = {
            'Z', 'I', 'G', 'Z', 'A', 'G', 'O', 'O', 'N', ' '
        },
        .catchIndex = 4,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LINOONE
    },
    [SPECIES_LINOONE] = {
        .mainSeriesIndexNumber = 289,
        .unk2 = {
            30, 77, 12, 49, 30
        },
        .name = {
            'L', 'I', 'N', 'O', 'O', 'N', 'E', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WURMPLE] = {
        .mainSeriesIndexNumber = 290,
        .unk2 = {
            8, 32, 77, 14, 83
        },
        .name = {
            'W', 'U', 'R', 'M', 'P', 'L', 'E', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_SILCOON
    },
    [SPECIES_SILCOON] = {
        .mainSeriesIndexNumber = 291,
        .unk2 = {
            5, 38, 10, 39, 12
        },
        .name = {
            'S', 'I', 'L', 'C', 'O', 'O', 'N', ' ', ' ', ' '
        },
        .catchIndex = 5,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BEAUTIFLY
    },
    [SPECIES_BEAUTIFLY] = {
        .mainSeriesIndexNumber = 292,
        .unk2 = {
            0, 50, 25, 45, 19
        },
        .name = {
            'B', 'E', 'A', 'U', 'T', 'I', 'F', 'L', 'Y', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASCOON] = {
        .mainSeriesIndexNumber = 293,
        .unk2 = {
            30, 36, 40, 61, 83
        },
        .name = {
            'C', 'A', 'S', 'C', 'O', 'O', 'N', ' ', ' ', ' '
        },
        .catchIndex = 6,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSTOX
    },
    [SPECIES_DUSTOX] = {
        .mainSeriesIndexNumber = 294,
        .unk2 = {
            61, 7, 8, 1, 40
        },
        .name = {
            'D', 'U', 'S', 'T', 'O', 'X', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LOTAD] = {
        .mainSeriesIndexNumber = 295,
        .unk2 = {
            25, 12, 66, 81, 83
        },
        .name = {
            'L', 'O', 'T', 'A', 'D', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 1,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOMBRE
    },
    [SPECIES_LOMBRE] = {
        .mainSeriesIndexNumber = 296,
        .unk2 = {
            25, 12, 64, 41, 42
        },
        .name = {
            'L', 'O', 'M', 'B', 'R', 'E', ' ', ' ', ' ', ' '
        },
        .catchIndex = 7,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_LUDICOLO
    },
    [SPECIES_LUDICOLO] = {
        .mainSeriesIndexNumber = 297,
        .unk2 = {
            40, 45, 67, 77, 67
        },
        .name = {
            'L', 'U', 'D', 'I', 'C', 'O', 'L', 'O', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEEDOT] = {
        .mainSeriesIndexNumber = 298,
        .unk2 = {
            15, 23, 66, 81, 83
        },
        .name = {
            'S', 'E', 'E', 'D', 'O', 'T', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 2,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NUZLEAF
    },
    [SPECIES_NUZLEAF] = {
        .mainSeriesIndexNumber = 299,
        .unk2 = {
            9, 24, 25, 20, 83
        },
        .name = {
            'N', 'U', 'Z', 'L', 'E', 'A', 'F', ' ', ' ', ' '
        },
        .catchIndex = 8,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 2,
        .evolutionTarget = SPECIES_SHIFTRY
    },
    [SPECIES_SHIFTRY] = {
        .mainSeriesIndexNumber = 300,
        .unk2 = {
            57, 81, 18, 45, 49
        },
        .name = {
            'S', 'H', 'I', 'F', 'T', 'R', 'Y', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TAILLOW] = {
        .mainSeriesIndexNumber = 304,
        .unk2 = {
            12, 62, 33, 83, 83
        },
        .name = {
            'T', 'A', 'I', 'L', 'L', 'O', 'W', ' ', ' ', ' '
        },
        .catchIndex = 9,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWELLOW
    },
    [SPECIES_SWELLOW] = {
        .mainSeriesIndexNumber = 305,
        .unk2 = {
            4, 4, 12, 62, 33
        },
        .name = {
            'S', 'W', 'E', 'L', 'L', 'O', 'W', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WINGULL] = {
        .mainSeriesIndexNumber = 309,
        .unk2 = {
            6, 78, 34, 33, 83
        },
        .name = {
            'W', 'I', 'N', 'G', 'U', 'L', 'L', ' ', ' ', ' '
        },
        .catchIndex = 10,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PELIPPER
    },
    [SPECIES_PELIPPER] = {
        .mainSeriesIndexNumber = 310,
        .unk2 = {
            70, 39, 77, 67, 81
        },
        .name = {
            'P', 'E', 'L', 'I', 'P', 'P', 'E', 'R', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RALTS] = {
        .mainSeriesIndexNumber = 392,
        .unk2 = {
            38, 40, 19, 12, 83
        },
        .name = {
            'R', 'A', 'L', 'T', 'S', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 3,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KIRLIA
    },
    [SPECIES_KIRLIA] = {
        .mainSeriesIndexNumber = 393,
        .unk2 = {
            6, 40, 39, 0, 83
        },
        .name = {
            'K', 'I', 'R', 'L', 'I', 'A', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GARDEVOIR
    },
    [SPECIES_GARDEVOIR] = {
        .mainSeriesIndexNumber = 394,
        .unk2 = {
            10, 81, 20, 1, 19
        },
        .name = {
            'G', 'A', 'R', 'D', 'E', 'V', 'O', 'I', 'R', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SURSKIT] = {
        .mainSeriesIndexNumber = 311,
        .unk2 = {
            0, 33, 15, 30, 83
        },
        .name = {
            'S', 'U', 'R', 'S', 'K', 'I', 'T', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 4,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MASQUERAIN
    },
    [SPECIES_MASQUERAIN] = {
        .mainSeriesIndexNumber = 312,
        .unk2 = {
            0, 33, 34, 81, 12
        },
        .name = {
            'M', 'A', 'S', 'Q', 'U', 'E', 'R', 'A', 'I', 'N'
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHROOMISH] = {
        .mainSeriesIndexNumber = 306,
        .unk2 = {
            6, 24, 9, 9, 83
        },
        .name = {
            'S', 'H', 'R', 'O', 'O', 'M', 'I', 'S', 'H', ' '
        },
        .catchIndex = 0,
        .eggIndex = 5,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BRELOOM
    },
    [SPECIES_BRELOOM] = {
        .mainSeriesIndexNumber = 307,
        .unk2 = {
            6, 24, 47, 77, 10
        },
        .name = {
            'B', 'R', 'E', 'L', 'O', 'O', 'M', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLAKOTH] = {
        .mainSeriesIndexNumber = 364,
        .unk2 = {
            20, 30, 8, 42, 83
        },
        .name = {
            'S', 'L', 'A', 'K', 'O', 'T', 'H', ' ', ' ', ' '
        },
        .catchIndex = 11,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIGOROTH
    },
    [SPECIES_VIGOROTH] = {
        .mainSeriesIndexNumber = 365,
        .unk2 = {
            35, 40, 6, 34, 24
        },
        .name = {
            'V', 'I', 'G', 'O', 'R', 'O', 'T', 'H', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SLAKING
    },
    [SPECIES_SLAKING] = {
        .mainSeriesIndexNumber = 366,
        .unk2 = {
            8, 77, 6, 45, 49
        },
        .name = {
            'S', 'L', 'A', 'K', 'I', 'N', 'G', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABRA] = {
        .mainSeriesIndexNumber = 63,
        .unk2 = {
            8, 81, 11, 73, 83
        },
        .name = {
            'A', 'B', 'R', 'A', ' ', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 12,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KADABRA
    },
    [SPECIES_KADABRA] = {
        .mainSeriesIndexNumber = 64,
        .unk2 = {
            36, 45, 50, 38, 81
        },
        .name = {
            'K', 'A', 'D', 'A', 'B', 'R', 'A', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_ALAKAZAM
    },
    [SPECIES_ALAKAZAM] = {
        .mainSeriesIndexNumber = 65,
        .unk2 = {
            27, 81, 60, 73, 45
        },
        .name = {
            'A', 'L', 'A', 'K', 'A', 'Z', 'A', 'M', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NINCADA] = {
        .mainSeriesIndexNumber = 301,
        .unk2 = {
            17, 16, 21, 45, 83
        },
        .name = {
            'N', 'I', 'N', 'C', 'A', 'D', 'A', ' ', ' ', ' '
        },
        .catchIndex = 13,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NINJASK
    },
    [SPECIES_NINJASK] = {
        .mainSeriesIndexNumber = 302,
        .unk2 = {
            18, 77, 5, 21, 45
        },
        .name = {
            'N', 'I', 'N', 'J', 'A', 'S', 'K', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHEDINJA] = {
        .mainSeriesIndexNumber = 303,
        .unk2 = {
            22, 8, 21, 45, 83
        },
        .name = {
            'S', 'H', 'E', 'D', 'I', 'N', 'J', 'A', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WHISMUR] = {
        .mainSeriesIndexNumber = 370,
        .unk2 = {
            51, 21, 80, 21, 80
        },
        .name = {
            'W', 'H', 'I', 'S', 'M', 'U', 'R', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 6,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOUDRED
    },
    [SPECIES_LOUDRED] = {
        .mainSeriesIndexNumber = 371,
        .unk2 = {
            61, 51, 81, 32, 83
        },
        .name = {
            'L', 'O', 'U', 'D', 'R', 'E', 'D', ' ', ' ', ' '
        },
        .catchIndex = 14,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_EXPLOUD
    },
    [SPECIES_EXPLOUD] = {
        .mainSeriesIndexNumber = 372,
        .unk2 = {
            62, 7, 4, 45, 49
        },
        .name = {
            'E', 'X', 'P', 'L', 'O', 'U', 'D', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAKUHITA] = {
        .mainSeriesIndexNumber = 335,
        .unk2 = {
            30, 7, 24, 11, 15
        },
        .name = {
            'M', 'A', 'K', 'U', 'H', 'I', 'T', 'A', ' ', ' '
        },
        .catchIndex = 15,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HARIYAMA
    },
    [SPECIES_HARIYAMA] = {
        .mainSeriesIndexNumber = 336,
        .unk2 = {
            25, 39, 18, 35, 30
        },
        .name = {
            'H', 'A', 'R', 'I', 'Y', 'A', 'M', 'A', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOLDEEN] = {
        .mainSeriesIndexNumber = 118,
        .unk2 = {
            19, 10, 6, 45, 19
        },
        .name = {
            'G', 'O', 'L', 'D', 'E', 'E', 'N', ' ', ' ', ' '
        },
        .catchIndex = 16,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEAKING
    },
    [SPECIES_SEAKING] = {
        .mainSeriesIndexNumber = 119,
        .unk2 = {
            0, 54, 30, 4, 2
        },
        .name = {
            'S', 'E', 'A', 'K', 'I', 'N', 'G', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGIKARP] = {
        .mainSeriesIndexNumber = 129,
        .unk2 = {
            9, 1, 6, 45, 49
        },
        .name = {
            'M', 'A', 'G', 'I', 'K', 'A', 'R', 'P', ' ', ' '
        },
        .catchIndex = 17,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GYARADOS
    },
    [SPECIES_GYARADOS] = {
        .mainSeriesIndexNumber = 130,
        .unk2 = {
            48, 78, 38, 61, 12
        },
        .name = {
            'G', 'Y', 'A', 'R', 'A', 'D', 'O', 'S', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AZURILL] = {
        .mainSeriesIndexNumber = 350,
        .unk2 = {
            40, 39, 39, 83, 83
        },
        .name = {
            'A', 'Z', 'U', 'R', 'I', 'L', 'L', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 7,
        .unk13 = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_MARILL
    },
    [SPECIES_MARILL] = {
        .mainSeriesIndexNumber = 183,
        .unk2 = {
            30, 39, 40, 83, 83
        },
        .name = {
            'M', 'A', 'R', 'I', 'L', 'L', ' ', ' ', ' ', ' '
        },
        .catchIndex = 18,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AZUMARILL
    },
    [SPECIES_AZUMARILL] = {
        .mainSeriesIndexNumber = 184,
        .unk2 = {
            30, 39, 40, 39, 83
        },
        .name = {
            'A', 'Z', 'U', 'M', 'A', 'R', 'I', 'L', 'L', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GEODUDE] = {
        .mainSeriesIndexNumber = 74,
        .unk2 = {
            1, 11, 17, 64, 18
        },
        .name = {
            'G', 'E', 'O', 'D', 'U', 'D', 'E', ' ', ' ', ' '
        },
        .catchIndex = 19,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRAVELER
    },
    [SPECIES_GRAVELER] = {
        .mainSeriesIndexNumber = 75,
        .unk2 = {
            51, 42, 81, 45, 83
        },
        .name = {
            'G', 'R', 'A', 'V', 'E', 'L', 'E', 'R', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_GOLEM
    },
    [SPECIES_GOLEM] = {
        .mainSeriesIndexNumber = 76,
        .unk2 = {
            51, 42, 81, 21, 78
        },
        .name = {
            'G', 'O', 'L', 'E', 'M', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NOSEPASS] = {
        .mainSeriesIndexNumber = 320,
        .unk2 = {
            24, 54, 67, 12, 83
        },
        .name = {
            'N', 'O', 'S', 'E', 'P', 'A', 'S', 'S', ' ', ' '
        },
        .catchIndex = 20,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKITTY] = {
        .mainSeriesIndexNumber = 315,
        .unk2 = {
            3, 23, 9, 83, 83
        },
        .name = {
            'S', 'K', 'I', 'T', 'T', 'Y', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 8,
        .unk13 = 1,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_DELCATTY
    },
    [SPECIES_DELCATTY] = {
        .mainSeriesIndexNumber = 316,
        .unk2 = {
            3, 23, 9, 42, 42
        },
        .name = {
            'D', 'E', 'L', 'C', 'A', 'T', 'T', 'Y', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZUBAT] = {
        .mainSeriesIndexNumber = 41,
        .unk2 = {
            54, 62, 77, 19, 83
        },
        .name = {
            'Z', 'U', 'B', 'A', 'T', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 9,
        .unk13 = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLBAT
    },
    [SPECIES_GOLBAT] = {
        .mainSeriesIndexNumber = 42,
        .unk2 = {
            51, 40, 62, 77, 19
        },
        .name = {
            'G', 'O', 'L', 'B', 'A', 'T', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_CROBAT
    },
    [SPECIES_CROBAT] = {
        .mainSeriesIndexNumber = 169,
        .unk2 = {
            7, 42, 62, 77, 19
        },
        .name = {
            'C', 'R', 'O', 'B', 'A', 'T', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TENTACOOL] = {
        .mainSeriesIndexNumber = 72,
        .unk2 = {
            33, 24, 7, 38, 50
        },
        .name = {
            'T', 'E', 'N', 'T', 'A', 'C', 'O', 'O', 'L', ' '
        },
        .catchIndex = 21,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TENTACRUEL
    },
    [SPECIES_TENTACRUEL] = {
        .mainSeriesIndexNumber = 73,
        .unk2 = {
            61, 7, 7, 38, 50
        },
        .name = {
            'T', 'E', 'N', 'T', 'A', 'C', 'R', 'U', 'E', 'L'
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SABLEYE] = {
        .mainSeriesIndexNumber = 322,
        .unk2 = {
            35, 31, 38, 31, 83
        },
        .name = {
            'S', 'A', 'B', 'L', 'E', 'Y', 'E', ' ', ' ', ' '
        },
        .catchIndex = 22,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAWILE] = {
        .mainSeriesIndexNumber = 355,
        .unk2 = {
            7, 16, 81, 19, 83
        },
        .name = {
            'M', 'A', 'W', 'I', 'L', 'E', ' ', ' ', ' ', ' '
        },
        .catchIndex = 23,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ARON] = {
        .mainSeriesIndexNumber = 382,
        .unk2 = {
            9, 9, 61, 38, 83
        },
        .name = {
            'A', 'R', 'O', 'N', ' ', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 10,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LAIRON
    },
    [SPECIES_LAIRON] = {
        .mainSeriesIndexNumber = 383,
        .unk2 = {
            9, 61, 38, 83, 83
        },
        .name = {
            'L', 'A', 'I', 'R', 'O', 'N', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AGGRON
    },
    [SPECIES_AGGRON] = {
        .mainSeriesIndexNumber = 384,
        .unk2 = {
            66, 12, 51, 61, 38
        },
        .name = {
            'A', 'G', 'G', 'R', 'O', 'N', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MACHOP] = {
        .mainSeriesIndexNumber = 66,
        .unk2 = {
            43, 45, 39, 6, 81
        },
        .name = {
            'M', 'A', 'C', 'H', 'O', 'P', ' ', ' ', ' ', ' '
        },
        .catchIndex = 24,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MACHOKE
    },
    [SPECIES_MACHOKE] = {
        .mainSeriesIndexNumber = 67,
        .unk2 = {
            51, 81, 39, 6, 81
        },
        .name = {
            'M', 'A', 'C', 'H', 'O', 'K', 'E', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_MACHAMP
    },
    [SPECIES_MACHAMP] = {
        .mainSeriesIndexNumber = 68,
        .unk2 = {
            5, 1, 39, 6, 81
        },
        .name = {
            'M', 'A', 'C', 'H', 'A', 'M', 'P', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEDITITE] = {
        .mainSeriesIndexNumber = 356,
        .unk2 = {
            0, 10, 20, 45, 83
        },
        .name = {
            'M', 'E', 'D', 'I', 'T', 'I', 'T', 'E', ' ', ' '
        },
        .catchIndex = 25,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MEDICHAM
    },
    [SPECIES_MEDICHAM] = {
        .mainSeriesIndexNumber = 357,
        .unk2 = {
            16, 78, 81, 41, 32
        },
        .name = {
            'M', 'E', 'D', 'I', 'C', 'H', 'A', 'M', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ELECTRIKE] = {
        .mainSeriesIndexNumber = 337,
        .unk2 = {
            38, 7, 38, 1, 83
        },
        .name = {
            'E', 'L', 'E', 'C', 'T', 'R', 'I', 'K', 'E', ' '
        },
        .catchIndex = 26,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MANECTRIC
    },
    [SPECIES_MANECTRIC] = {
        .mainSeriesIndexNumber = 338,
        .unk2 = {
            38, 1, 66, 40, 19
        },
        .name = {
            'M', 'A', 'N', 'E', 'C', 'T', 'R', 'I', 'C', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PLUSLE] = {
        .mainSeriesIndexNumber = 353,
        .unk2 = {
            69, 38, 12, 40, 83
        },
        .name = {
            'P', 'L', 'U', 'S', 'L', 'E', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 11,
        .unk13 = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MINUN] = {
        .mainSeriesIndexNumber = 354,
        .unk2 = {
            30, 1, 20, 45, 83
        },
        .name = {
            'M', 'I', 'N', 'U', 'N', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 12,
        .unk13 = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGNEMITE] = {
        .mainSeriesIndexNumber = 81,
        .unk2 = {
            9, 1, 40, 83, 83
        },
        .name = {
            'M', 'A', 'G', 'N', 'E', 'M', 'I', 'T', 'E', ' '
        },
        .catchIndex = 27,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGNETON
    },
    [SPECIES_MAGNETON] = {
        .mainSeriesIndexNumber = 82,
        .unk2 = {
            41, 0, 9, 1, 40
        },
        .name = {
            'M', 'A', 'G', 'N', 'E', 'T', 'O', 'N', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLTORB] = {
        .mainSeriesIndexNumber = 100,
        .unk2 = {
            63, 39, 39, 57, 30
        },
        .name = {
            'V', 'O', 'L', 'T', 'O', 'R', 'B', ' ', ' ', ' '
        },
        .catchIndex = 28,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ELECTRODE
    },
    [SPECIES_ELECTRODE] = {
        .mainSeriesIndexNumber = 101,
        .unk2 = {
            30, 40, 30, 1, 45
        },
        .name = {
            'E', 'L', 'E', 'C', 'T', 'R', 'O', 'D', 'E', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLBEAT] = {
        .mainSeriesIndexNumber = 386,
        .unk2 = {
            62, 40, 63, 81, 19
        },
        .name = {
            'V', 'O', 'L', 'B', 'E', 'A', 'T', ' ', ' ', ' '
        },
        .catchIndex = 29,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ILLUMISE] = {
        .mainSeriesIndexNumber = 387,
        .unk2 = {
            1, 40, 31, 81, 55
        },
        .name = {
            'I', 'L', 'L', 'U', 'M', 'I', 'S', 'E', ' ', ' '
        },
        .catchIndex = 30,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ODDISH] = {
        .mainSeriesIndexNumber = 43,
        .unk2 = {
            20, 56, 24, 7, 10
        },
        .name = {
            'O', 'D', 'D', 'I', 'S', 'H', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 13,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLOOM
    },
    [SPECIES_GLOOM] = {
        .mainSeriesIndexNumber = 44,
        .unk2 = {
            7, 10, 1, 25, 20
        },
        .name = {
            'G', 'L', 'O', 'O', 'M', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_VILEPLUME
    },
    [SPECIES_VILEPLUME] = {
        .mainSeriesIndexNumber = 45,
        .unk2 = {
            38, 27, 41, 11, 0
        },
        .name = {
            'V', 'I', 'L', 'E', 'P', 'L', 'U', 'M', 'E', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELLOSSOM] = {
        .mainSeriesIndexNumber = 182,
        .unk2 = {
            6, 41, 1, 25, 20
        },
        .name = {
            'B', 'E', 'L', 'L', 'O', 'S', 'S', 'O', 'M', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DODUO] = {
        .mainSeriesIndexNumber = 84,
        .unk2 = {
            61, 81, 61, 81, 83
        },
        .name = {
            'D', 'O', 'D', 'U', 'O', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 31,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DODRIO
    },
    [SPECIES_DODRIO] = {
        .mainSeriesIndexNumber = 85,
        .unk2 = {
            61, 81, 61, 39, 4
        },
        .name = {
            'D', 'O', 'D', 'R', 'I', 'O', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ROSELIA] = {
        .mainSeriesIndexNumber = 363,
        .unk2 = {
            42, 55, 39, 0, 83
        },
        .name = {
            'R', 'O', 'S', 'E', 'L', 'I', 'A', ' ', ' ', ' '
        },
        .catchIndex = 32,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GULPIN] = {
        .mainSeriesIndexNumber = 367,
        .unk2 = {
            51, 7, 39, 45, 83
        },
        .name = {
            'G', 'U', 'L', 'P', 'I', 'N', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 14,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWALOT
    },
    [SPECIES_SWALOT] = {
        .mainSeriesIndexNumber = 368,
        .unk2 = {
            30, 40, 24, 81, 32
        },
        .name = {
            'S', 'W', 'A', 'L', 'O', 'T', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CARVANHA] = {
        .mainSeriesIndexNumber = 330,
        .unk2 = {
            6, 62, 21, 0, 83
        },
        .name = {
            'C', 'A', 'R', 'V', 'A', 'N', 'H', 'A', ' ', ' '
        },
        .catchIndex = 33,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHARPEDO
    },
    [SPECIES_SHARPEDO] = {
        .mainSeriesIndexNumber = 331,
        .unk2 = {
            10, 33, 25, 57, 81
        },
        .name = {
            'S', 'H', 'A', 'R', 'P', 'E', 'D', 'O', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WAILMER] = {
        .mainSeriesIndexNumber = 313,
        .unk2 = {
            29, 3, 40, 9, 83
        },
        .name = {
            'W', 'A', 'I', 'L', 'M', 'E', 'R', ' ', ' ', ' '
        },
        .catchIndex = 34,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WAILORD
    },
    [SPECIES_WAILORD] = {
        .mainSeriesIndexNumber = 314,
        .unk2 = {
            29, 3, 40, 4, 81
        },
        .name = {
            'W', 'A', 'I', 'L', 'O', 'R', 'D', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NUMEL] = {
        .mainSeriesIndexNumber = 339,
        .unk2 = {
            61, 45, 33, 40, 83
        },
        .name = {
            'N', 'U', 'M', 'E', 'L', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 35,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CAMERUPT
    },
    [SPECIES_CAMERUPT] = {
        .mainSeriesIndexNumber = 340,
        .unk2 = {
            62, 7, 81, 57, 83
        },
        .name = {
            'C', 'A', 'M', 'E', 'R', 'U', 'P', 'T', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLUGMA] = {
        .mainSeriesIndexNumber = 218,
        .unk2 = {
            30, 49, 30, 77, 49
        },
        .name = {
            'S', 'L', 'U', 'G', 'M', 'A', ' ', ' ', ' ', ' '
        },
        .catchIndex = 36,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGCARGO
    },
    [SPECIES_MAGCARGO] = {
        .mainSeriesIndexNumber = 219,
        .unk2 = {
            30, 49, 5, 40, 51
        },
        .name = {
            'M', 'A', 'G', 'C', 'A', 'R', 'G', 'O', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORKOAL] = {
        .mainSeriesIndexNumber = 321,
        .unk2 = {
            9, 81, 15, 12, 83
        },
        .name = {
            'T', 'O', 'R', 'K', 'O', 'A', 'L', ' ', ' ', ' '
        },
        .catchIndex = 37,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GRIMER] = {
        .mainSeriesIndexNumber = 88,
        .unk2 = {
            65, 19, 65, 15, 81
        },
        .name = {
            'G', 'R', 'I', 'M', 'E', 'R', ' ', ' ', ' ', ' '
        },
        .catchIndex = 38,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MUK
    },
    [SPECIES_MUK] = {
        .mainSeriesIndexNumber = 89,
        .unk2 = {
            65, 19, 65, 19, 45
        },
        .name = {
            'M', 'U', 'K', ' ', ' ', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KOFFING] = {
        .mainSeriesIndexNumber = 109,
        .unk2 = {
            61, 47, 81, 12, 83
        },
        .name = {
            'K', 'O', 'F', 'F', 'I', 'N', 'G', ' ', ' ', ' '
        },
        .catchIndex = 39,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WEEZING
    },
    [SPECIES_WEEZING] = {
        .mainSeriesIndexNumber = 110,
        .unk2 = {
            30, 15, 61, 47, 12
        },
        .name = {
            'W', 'E', 'E', 'Z', 'I', 'N', 'G', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPOINK] = {
        .mainSeriesIndexNumber = 351,
        .unk2 = {
            62, 23, 64, 81, 83
        },
        .name = {
            'S', 'P', 'O', 'I', 'N', 'K', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 15,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRUMPIG
    },
    [SPECIES_GRUMPIG] = {
        .mainSeriesIndexNumber = 352,
        .unk2 = {
            64, 81, 68, 77, 49
        },
        .name = {
            'G', 'R', 'U', 'M', 'P', 'I', 'G', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SANDSHREW] = {
        .mainSeriesIndexNumber = 27,
        .unk2 = {
            10, 45, 61, 83, 83
        },
        .name = {
            'S', 'A', 'N', 'D', 'S', 'H', 'R', 'E', 'W', ' '
        },
        .catchIndex = 0,
        .eggIndex = 16,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SANDSLASH
    },
    [SPECIES_SANDSLASH] = {
        .mainSeriesIndexNumber = 28,
        .unk2 = {
            10, 45, 61, 67, 45
        },
        .name = {
            'S', 'A', 'N', 'D', 'S', 'L', 'A', 'S', 'H', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPINDA] = {
        .mainSeriesIndexNumber = 308,
        .unk2 = {
            67, 77, 16, 81, 40
        },
        .name = {
            'S', 'P', 'I', 'N', 'D', 'A', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 17,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKARMORY] = {
        .mainSeriesIndexNumber = 227,
        .unk2 = {
            3, 0, 81, 32, 61
        },
        .name = {
            'S', 'K', 'A', 'R', 'M', 'O', 'R', 'Y', ' ', ' '
        },
        .catchIndex = 40,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TRAPINCH] = {
        .mainSeriesIndexNumber = 332,
        .unk2 = {
            20, 77, 7, 38, 81
        },
        .name = {
            'T', 'R', 'A', 'P', 'I', 'N', 'C', 'H', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 18,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIBRAVA
    },
    [SPECIES_VIBRAVA] = {
        .mainSeriesIndexNumber = 333,
        .unk2 = {
            63, 64, 38, 81, 62
        },
        .name = {
            'V', 'I', 'B', 'R', 'A', 'V', 'A', ' ', ' ', ' '
        },
        .catchIndex = 41,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FLYGON
    },
    [SPECIES_FLYGON] = {
        .mainSeriesIndexNumber = 334,
        .unk2 = {
            27, 38, 1, 51, 45
        },
        .name = {
            'F', 'L', 'Y', 'G', 'O', 'N', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CACNEA] = {
        .mainSeriesIndexNumber = 344,
        .unk2 = {
            10, 66, 23, 0, 83
        },
        .name = {
            'C', 'A', 'C', 'N', 'E', 'A', ' ', ' ', ' ', ' '
        },
        .catchIndex = 42,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CACTURNE
    },
    [SPECIES_CACTURNE] = {
        .mainSeriesIndexNumber = 345,
        .unk2 = {
            24, 7, 15, 12, 83
        },
        .name = {
            'C', 'A', 'C', 'T', 'U', 'R', 'N', 'E', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SWABLU] = {
        .mainSeriesIndexNumber = 358,
        .unk2 = {
            16, 40, 77, 19, 83
        },
        .name = {
            'S', 'W', 'A', 'B', 'L', 'U', ' ', ' ', ' ', ' '
        },
        .catchIndex = 43,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ALTARIA
    },
    [SPECIES_ALTARIA] = {
        .mainSeriesIndexNumber = 359,
        .unk2 = {
            16, 40, 15, 39, 12
        },
        .name = {
            'A', 'L', 'T', 'A', 'R', 'I', 'A', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZANGOOSE] = {
        .mainSeriesIndexNumber = 380,
        .unk2 = {
            52, 45, 49, 81, 12
        },
        .name = {
            'Z', 'A', 'N', 'G', 'O', 'O', 'S', 'E', ' ', ' '
        },
        .catchIndex = 44,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEVIPER] = {
        .mainSeriesIndexNumber = 379,
        .unk2 = {
            25, 64, 23, 81, 7
        },
        .name = {
            'S', 'E', 'V', 'I', 'P', 'E', 'R', ' ', ' ', ' '
        },
        .catchIndex = 45,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUNATONE] = {
        .mainSeriesIndexNumber = 348,
        .unk2 = {
            40, 20, 19, 81, 45
        },
        .name = {
            'L', 'U', 'N', 'A', 'T', 'O', 'N', 'E', ' ', ' '
        },
        .catchIndex = 46,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SOLROCK] = {
        .mainSeriesIndexNumber = 349,
        .unk2 = {
            14, 40, 42, 77, 7
        },
        .name = {
            'S', 'O', 'L', 'R', 'O', 'C', 'K', ' ', ' ', ' '
        },
        .catchIndex = 47,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BARBOACH] = {
        .mainSeriesIndexNumber = 323,
        .unk2 = {
            61, 53, 80, 77, 16
        },
        .name = {
            'B', 'A', 'R', 'B', 'O', 'A', 'C', 'H', ' ', ' '
        },
        .catchIndex = 48,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WHISCASH
    },
    [SPECIES_WHISCASH] = {
        .mainSeriesIndexNumber = 324,
        .unk2 = {
            20, 30, 54, 45, 83
        },
        .name = {
            'W', 'H', 'I', 'S', 'C', 'A', 'S', 'H', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORPHISH] = {
        .mainSeriesIndexNumber = 326,
        .unk2 = {
            28, 1, 47, 21, 83
        },
        .name = {
            'C', 'O', 'R', 'P', 'H', 'I', 'S', 'H', ' ', ' '
        },
        .catchIndex = 49,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRAWDAUNT
    },
    [SPECIES_CRAWDAUNT] = {
        .mainSeriesIndexNumber = 327,
        .unk2 = {
            11, 52, 39, 47, 81
        },
        .name = {
            'C', 'R', 'A', 'W', 'D', 'A', 'U', 'N', 'T', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BALTOY] = {
        .mainSeriesIndexNumber = 318,
        .unk2 = {
            35, 53, 42, 45, 83
        },
        .name = {
            'B', 'A', 'L', 'T', 'O', 'Y', ' ', ' ', ' ', ' '
        },
        .catchIndex = 50,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CLAYDOL
    },
    [SPECIES_CLAYDOL] = {
        .mainSeriesIndexNumber = 319,
        .unk2 = {
            23, 45, 61, 81, 40
        },
        .name = {
            'C', 'L', 'A', 'Y', 'D', 'O', 'L', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LILEEP] = {
        .mainSeriesIndexNumber = 388,
        .unk2 = {
            39, 39, 81, 38, 83
        },
        .name = {
            'L', 'I', 'L', 'E', 'E', 'P', ' ', ' ', ' ', ' '
        },
        .catchIndex = 51,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRADILY
    },
    [SPECIES_CRADILY] = {
        .mainSeriesIndexNumber = 389,
        .unk2 = {
            36, 41, 1, 61, 40
        },
        .name = {
            'C', 'R', 'A', 'D', 'I', 'L', 'Y', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ANORITH] = {
        .mainSeriesIndexNumber = 390,
        .unk2 = {
            0, 24, 69, 12, 83
        },
        .name = {
            'A', 'N', 'O', 'R', 'I', 'T', 'H', ' ', ' ', ' '
        },
        .catchIndex = 52,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ARMALDO
    },
    [SPECIES_ARMALDO] = {
        .mainSeriesIndexNumber = 391,
        .unk2 = {
            0, 81, 30, 40, 61
        },
        .name = {
            'A', 'R', 'M', 'A', 'L', 'D', 'O', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_IGGLYBUFF] = {
        .mainSeriesIndexNumber = 174,
        .unk2 = {
            69, 69, 39, 45, 83
        },
        .name = {
            'I', 'G', 'G', 'L', 'Y', 'B', 'U', 'F', 'F', ' '
        },
        .catchIndex = 0,
        .eggIndex = 19,
        .unk13 = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_JIGGLYPUFF
    },
    [SPECIES_JIGGLYPUFF] = {
        .mainSeriesIndexNumber = 39,
        .unk2 = {
            69, 39, 45, 83, 83
        },
        .name = {
            'J', 'I', 'G', 'G', 'L', 'Y', 'P', 'U', 'F', 'F'
        },
        .catchIndex = 53,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_WIGGLYTUFF
    },
    [SPECIES_WIGGLYTUFF] = {
        .mainSeriesIndexNumber = 40,
        .unk2 = {
            69, 7, 39, 45, 83
        },
        .name = {
            'W', 'I', 'G', 'G', 'L', 'Y', 'T', 'U', 'F', 'F'
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FEEBAS] = {
        .mainSeriesIndexNumber = 328,
        .unk2 = {
            26, 45, 62, 12, 83
        },
        .name = {
            'F', 'E', 'E', 'B', 'A', 'S', ' ', ' ', ' ', ' '
        },
        .catchIndex = 54,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 10,
        .evolutionTarget = SPECIES_MILOTIC
    },
    [SPECIES_MILOTIC] = {
        .mainSeriesIndexNumber = 329,
        .unk2 = {
            31, 42, 5, 42, 12
        },
        .name = {
            'M', 'I', 'L', 'O', 'T', 'I', 'C', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASTFORM] = {
        .mainSeriesIndexNumber = 385,
        .unk2 = {
            71, 43, 40, 45, 83
        },
        .name = {
            'C', 'A', 'S', 'T', 'F', 'O', 'R', 'M', ' ', ' '
        },
        .catchIndex = 55,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_STARYU] = {
        .mainSeriesIndexNumber = 120,
        .unk2 = {
            26, 19, 60, 30, 45
        },
        .name = {
            'S', 'T', 'A', 'R', 'Y', 'U', ' ', ' ', ' ', ' '
        },
        .catchIndex = 56,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_STARMIE
    },
    [SPECIES_STARMIE] = {
        .mainSeriesIndexNumber = 121,
        .unk2 = {
            12, 15, 81, 31, 81
        },
        .name = {
            'S', 'T', 'A', 'R', 'M', 'I', 'E', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KECLEON] = {
        .mainSeriesIndexNumber = 317,
        .unk2 = {
            5, 7, 41, 4, 45
        },
        .name = {
            'K', 'E', 'C', 'L', 'E', 'O', 'N', ' ', ' ', ' '
        },
        .catchIndex = 57,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHUPPET] = {
        .mainSeriesIndexNumber = 377,
        .unk2 = {
            5, 50, 66, 2, 54
        },
        .name = {
            'S', 'H', 'U', 'P', 'P', 'E', 'T', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 20,
        .unk13 = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BANETTE
    },
    [SPECIES_BANETTE] = {
        .mainSeriesIndexNumber = 378,
        .unk2 = {
            53, 79, 70, 77, 15
        },
        .name = {
            'B', 'A', 'N', 'E', 'T', 'T', 'E', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DUSKULL] = {
        .mainSeriesIndexNumber = 361,
        .unk2 = {
            37, 30, 43, 40, 83
        },
        .name = {
            'D', 'U', 'S', 'K', 'U', 'L', 'L', ' ', ' ', ' '
        },
        .catchIndex = 58,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSCLOPS
    },
    [SPECIES_DUSCLOPS] = {
        .mainSeriesIndexNumber = 362,
        .unk2 = {
            10, 30, 37, 81, 40
        },
        .name = {
            'D', 'U', 'S', 'C', 'L', 'O', 'P', 'S', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TROPIUS] = {
        .mainSeriesIndexNumber = 369,
        .unk2 = {
            19, 42, 68, 2, 12
        },
        .name = {
            'T', 'R', 'O', 'P', 'I', 'U', 'S', ' ', ' ', ' '
        },
        .catchIndex = 59,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIMECHO] = {
        .mainSeriesIndexNumber = 411,
        .unk2 = {
            16, 39, 81, 45, 83
        },
        .name = {
            'C', 'H', 'I', 'M', 'E', 'C', 'H', 'O', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 21,
        .unk13 = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABSOL] = {
        .mainSeriesIndexNumber = 376,
        .unk2 = {
            0, 64, 14, 40, 83
        },
        .name = {
            'A', 'B', 'S', 'O', 'L', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 60,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VULPIX] = {
        .mainSeriesIndexNumber = 37,
        .unk2 = {
            42, 9, 45, 83, 83
        },
        .name = {
            'V', 'U', 'L', 'P', 'I', 'X', ' ', ' ', ' ', ' '
        },
        .catchIndex = 61,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 3,
        .evolutionTarget = SPECIES_NINETALES
    },
    [SPECIES_NINETALES] = {
        .mainSeriesIndexNumber = 38,
        .unk2 = {
            6, 79, 2, 9, 45
        },
        .name = {
            'N', 'I', 'N', 'E', 'T', 'A', 'L', 'E', 'S', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PICHU] = {
        .mainSeriesIndexNumber = 172,
        .unk2 = {
            68, 16, 79, 81, 83
        },
        .name = {
            'P', 'I', 'C', 'H', 'U', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 22,
        .unk13 = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_PIKACHU
    },
    [SPECIES_PIKACHU] = {
        .mainSeriesIndexNumber = 25,
        .unk2 = {
            68, 5, 16, 79, 2
        },
        .name = {
            'P', 'I', 'K', 'A', 'C', 'H', 'U', ' ', ' ', ' '
        },
        .catchIndex = 62,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 7,
        .evolutionTarget = SPECIES_RAICHU
    },
    [SPECIES_RAICHU] = {
        .mainSeriesIndexNumber = 26,
        .unk2 = {
            38, 1, 16, 79, 2
        },
        .name = {
            'R', 'A', 'I', 'C', 'H', 'U', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PSYDUCK] = {
        .mainSeriesIndexNumber = 54,
        .unk2 = {
            9, 57, 77, 7, 83
        },
        .name = {
            'P', 'S', 'Y', 'D', 'U', 'C', 'K', ' ', ' ', ' '
        },
        .catchIndex = 63,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLDUCK
    },
    [SPECIES_GOLDUCK] = {
        .mainSeriesIndexNumber = 55,
        .unk2 = {
            51, 40, 57, 77, 7
        },
        .name = {
            'G', 'O', 'L', 'D', 'U', 'C', 'K', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WYNAUT] = {
        .mainSeriesIndexNumber = 360,
        .unk2 = {
            14, 81, 20, 24, 83
        },
        .name = {
            'W', 'Y', 'N', 'A', 'U', 'T', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 23,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WOBBUFFET
    },
    [SPECIES_WOBBUFFET] = {
        .mainSeriesIndexNumber = 202,
        .unk2 = {
            14, 81, 20, 45, 12
        },
        .name = {
            'W', 'O', 'B', 'B', 'U', 'F', 'F', 'E', 'T', ' '
        },
        .catchIndex = 64,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NATU] = {
        .mainSeriesIndexNumber = 177,
        .unk2 = {
            23, 1, 18, 73, 83
        },
        .name = {
            'N', 'A', 'T', 'U', ' ', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 24,
        .unk13 = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_XATU
    },
    [SPECIES_XATU] = {
        .mainSeriesIndexNumber = 178,
        .unk2 = {
            23, 1, 18, 73, 4
        },
        .name = {
            'X', 'A', 'T', 'U', ' ', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GIRAFARIG] = {
        .mainSeriesIndexNumber = 203,
        .unk2 = {
            6, 39, 45, 39, 6
        },
        .name = {
            'G', 'I', 'R', 'A', 'F', 'A', 'R', 'I', 'G', ' '
        },
        .catchIndex = 65,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PHANPY] = {
        .mainSeriesIndexNumber = 231,
        .unk2 = {
            51, 30, 56, 2, 83
        },
        .name = {
            'P', 'H', 'A', 'N', 'P', 'Y', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 25,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DONPHAN
    },
    [SPECIES_DONPHAN] = {
        .mainSeriesIndexNumber = 232,
        .unk2 = {
            61, 45, 27, 72, 45
        },
        .name = {
            'D', 'O', 'N', 'P', 'H', 'A', 'N', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PINSIR] = {
        .mainSeriesIndexNumber = 127,
        .unk2 = {
            5, 1, 42, 12, 83
        },
        .name = {
            'P', 'I', 'N', 'S', 'I', 'R', ' ', ' ', ' ', ' '
        },
        .catchIndex = 66,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HERACROSS] = {
        .mainSeriesIndexNumber = 214,
        .unk2 = {
            28, 38, 7, 42, 12
        },
        .name = {
            'H', 'E', 'R', 'A', 'C', 'R', 'O', 'S', 'S', ' '
        },
        .catchIndex = 67,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RHYHORN] = {
        .mainSeriesIndexNumber = 111,
        .unk2 = {
            10, 1, 29, 81, 45
        },
        .name = {
            'R', 'H', 'Y', 'H', 'O', 'R', 'N', ' ', ' ', ' '
        },
        .catchIndex = 68,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RHYDON
    },
    [SPECIES_RHYDON] = {
        .mainSeriesIndexNumber = 112,
        .unk2 = {
            10, 1, 61, 45, 83
        },
        .name = {
            'R', 'H', 'Y', 'D', 'O', 'N', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SNORUNT] = {
        .mainSeriesIndexNumber = 346,
        .unk2 = {
            36, 6, 43, 38, 11
        },
        .name = {
            'S', 'N', 'O', 'R', 'U', 'N', 'T', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 26,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLALIE
    },
    [SPECIES_GLALIE] = {
        .mainSeriesIndexNumber = 347,
        .unk2 = {
            4, 21, 51, 81, 39
        },
        .name = {
            'G', 'L', 'A', 'L', 'I', 'E', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPHEAL] = {
        .mainSeriesIndexNumber = 341,
        .unk2 = {
            15, 30, 52, 38, 11
        },
        .name = {
            'S', 'P', 'H', 'E', 'A', 'L', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 27,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEALEO
    },
    [SPECIES_SEALEO] = {
        .mainSeriesIndexNumber = 342,
        .unk2 = {
            19, 61, 49, 38, 81
        },
        .name = {
            'S', 'E', 'A', 'L', 'E', 'O', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WALREIN
    },
    [SPECIES_WALREIN] = {
        .mainSeriesIndexNumber = 343,
        .unk2 = {
            19, 61, 55, 40, 47
        },
        .name = {
            'W', 'A', 'L', 'R', 'E', 'I', 'N', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CLAMPERL] = {
        .mainSeriesIndexNumber = 373,
        .unk2 = {
            67, 81, 40, 40, 83
        },
        .name = {
            'C', 'L', 'A', 'M', 'P', 'E', 'R', 'L', ' ', ' '
        },
        .catchIndex = 69,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_HUNTAIL
    },
    [SPECIES_HUNTAIL] = {
        .mainSeriesIndexNumber = 374,
        .unk2 = {
            25, 45, 18, 81, 40
        },
        .name = {
            'H', 'U', 'N', 'T', 'A', 'I', 'L', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOREBYSS] = {
        .mainSeriesIndexNumber = 375,
        .unk2 = {
            10, 7, 38, 63, 12
        },
        .name = {
            'G', 'O', 'R', 'E', 'B', 'Y', 'S', 'S', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RELICANTH] = {
        .mainSeriesIndexNumber = 381,
        .unk2 = {
            53, 81, 38, 45, 12
        },
        .name = {
            'R', 'E', 'L', 'I', 'C', 'A', 'N', 'T', 'H', ' '
        },
        .catchIndex = 70,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORSOLA] = {
        .mainSeriesIndexNumber = 222,
        .unk2 = {
            10, 21, 81, 51, 83
        },
        .name = {
            'C', 'O', 'R', 'S', 'O', 'L', 'A', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 28,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHINCHOU] = {
        .mainSeriesIndexNumber = 170,
        .unk2 = {
            16, 80, 45, 16, 81
        },
        .name = {
            'C', 'H', 'I', 'N', 'C', 'H', 'O', 'U', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 29,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LANTURN
    },
    [SPECIES_LANTURN] = {
        .mainSeriesIndexNumber = 171,
        .unk2 = {
            38, 45, 15, 81, 45
        },
        .name = {
            'L', 'A', 'N', 'T', 'U', 'R', 'N', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUVDISC] = {
        .mainSeriesIndexNumber = 325,
        .unk2 = {
            38, 64, 5, 12, 83
        },
        .name = {
            'L', 'U', 'V', 'D', 'I', 'S', 'C', ' ', ' ', ' '
        },
        .catchIndex = 71,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HORSEA] = {
        .mainSeriesIndexNumber = 116,
        .unk2 = {
            15, 77, 17, 81, 83
        },
        .name = {
            'H', 'O', 'R', 'S', 'E', 'A', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 30,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEADRA
    },
    [SPECIES_SEADRA] = {
        .mainSeriesIndexNumber = 117,
        .unk2 = {
            11, 81, 61, 38, 83
        },
        .name = {
            'S', 'E', 'A', 'D', 'R', 'A', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_KINGDRA
    },
    [SPECIES_KINGDRA] = {
        .mainSeriesIndexNumber = 230,
        .unk2 = {
            6, 45, 49, 61, 38
        },
        .name = {
            'K', 'I', 'N', 'G', 'D', 'R', 'A', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BAGON] = {
        .mainSeriesIndexNumber = 395,
        .unk2 = {
            15, 17, 65, 1, 83
        },
        .name = {
            'B', 'A', 'G', 'O', 'N', ' ', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 31,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHELGON
    },
    [SPECIES_SHELGON] = {
        .mainSeriesIndexNumber = 396,
        .unk2 = {
            9, 34, 40, 81, 83
        },
        .name = {
            'S', 'H', 'E', 'L', 'G', 'O', 'N', ' ', ' ', ' '
        },
        .catchIndex = 72,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SALAMENCE
    },
    [SPECIES_SALAMENCE] = {
        .mainSeriesIndexNumber = 397,
        .unk2 = {
            66, 81, 30, 45, 57
        },
        .name = {
            'S', 'A', 'L', 'A', 'M', 'E', 'N', 'C', 'E', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELDUM] = {
        .mainSeriesIndexNumber = 398,
        .unk2 = {
            57, 45, 62, 40, 83
        },
        .name = {
            'B', 'E', 'L', 'D', 'U', 'M', ' ', ' ', ' ', ' '
        },
        .catchIndex = 73,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METANG
    },
    [SPECIES_METANG] = {
        .mainSeriesIndexNumber = 399,
        .unk2 = {
            33, 15, 45, 49, 83
        },
        .name = {
            'M', 'E', 'T', 'A', 'N', 'G', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METAGROSS
    },
    [SPECIES_METAGROSS] = {
        .mainSeriesIndexNumber = 400,
        .unk2 = {
            33, 15, 49, 42, 12
        },
        .name = {
            'M', 'E', 'T', 'A', 'G', 'R', 'O', 'S', 'S', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGIROCK] = {
        .mainSeriesIndexNumber = 401,
        .unk2 = {
            41, 53, 42, 77, 7
        },
        .name = {
            'R', 'E', 'G', 'I', 'R', 'O', 'C', 'K', ' ', ' '
        },
        .catchIndex = 74,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGICE] = {
        .mainSeriesIndexNumber = 402,
        .unk2 = {
            41, 53, 0, 1, 12
        },
        .name = {
            'R', 'E', 'G', 'I', 'C', 'E', ' ', ' ', ' ', ' '
        },
        .catchIndex = 75,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGISTEEL] = {
        .mainSeriesIndexNumber = 403,
        .unk2 = {
            41, 53, 12, 16, 40
        },
        .name = {
            'R', 'E', 'G', 'I', 'S', 'T', 'E', 'E', 'L', ' '
        },
        .catchIndex = 76,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIAS] = {
        .mainSeriesIndexNumber = 407,
        .unk2 = {
            38, 18, 73, 0, 12
        },
        .name = {
            'L', 'A', 'T', 'I', 'A', 'S', ' ', ' ', ' ', ' '
        },
        .catchIndex = 77,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIOS] = {
        .mainSeriesIndexNumber = 408,
        .unk2 = {
            38, 18, 73, 4, 12
        },
        .name = {
            'L', 'A', 'T', 'I', 'O', 'S', ' ', ' ', ' ', ' '
        },
        .catchIndex = 78,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KYOGRE] = {
        .mainSeriesIndexNumber = 404,
        .unk2 = {
            5, 1, 4, 81, 47
        },
        .name = {
            'K', 'Y', 'O', 'G', 'R', 'E', ' ', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GROUDON] = {
        .mainSeriesIndexNumber = 405,
        .unk2 = {
            49, 38, 81, 61, 45
        },
        .name = {
            'G', 'R', 'O', 'U', 'D', 'O', 'N', ' ', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RAYQUAZA] = {
        .mainSeriesIndexNumber = 406,
        .unk2 = {
            41, 77, 7, 2, 52
        },
        .name = {
            'R', 'A', 'Y', 'Q', 'U', 'A', 'Z', 'A', ' ', ' '
        },
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_JIRACHI] = {
        .mainSeriesIndexNumber = 409,
        .unk2 = {
            53, 38, 81, 16, 83
        },
        .name = {
            'J', 'I', 'R', 'A', 'C', 'H', 'I', ' ', ' ', ' '
        },
        .catchIndex = 79,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIKORITA] = {
        .mainSeriesIndexNumber = 152,
        .unk2 = {
            16, 9, 39, 81, 15
        },
        .name = {
            'C', 'H', 'I', 'K', 'O', 'R', 'I', 'T', 'A', ' '
        },
        .catchIndex = 80,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CYNDAQUIL] = {
        .mainSeriesIndexNumber = 155,
        .unk2 = {
            26, 24, 0, 38, 11
        },
        .name = {
            'C', 'Y', 'N', 'D', 'A', 'Q', 'U', 'I', 'L', ' '
        },
        .catchIndex = 81,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TOTODILE] = {
        .mainSeriesIndexNumber = 158,
        .unk2 = {
            43, 21, 24, 9, 83
        },
        .name = {
            'T', 'O', 'T', 'O', 'D', 'I', 'L', 'E', ' ', ' '
        },
        .catchIndex = 82,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AERODACTYL] = {
        .mainSeriesIndexNumber = 142,
        .unk2 = {
            69, 18, 38, 83, 83
        },
        .name = {
            'A', 'E', 'R', 'O', 'D', 'A', 'C', 'T', 'Y', 'L'
        },
        .catchIndex = 83,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
};

/*
    [SPECIES_] = {
        .mainSeriesIndexNumber = ,
        .unk2 = {
            , , , , 
        },
        .name = {
            '', '', '', '', '', '', '', '', '', ''
        },
        .catchIndex = ,
        .eggIndex = ,
        .unk13 = ,
        .evolutionMethod = ,
        .evolutionTarget = SPECIES_
    },
*/
