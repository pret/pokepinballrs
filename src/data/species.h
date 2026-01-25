const struct PokemonSpecies gSpeciesInfo[NUM_SPECIES] = {
    [SPECIES_TREECKO] = {
        .mainSeriesIndexNumber = 277,
        .nameJapanese = __("キモリ　　"),
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
        .nameJapanese = __("ジュプトル"),
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
        .nameJapanese = __("ジュカイン"),
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
        .nameJapanese = __("アチャモ　"),
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
        .nameJapanese = __("ワカシャモ"),
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
        .nameJapanese = __("バシャーモ"),
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
        .nameJapanese = __("ミズゴロウ"),
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
        .nameJapanese = __("ヌマクロー"),
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
        .nameJapanese = __("ラグラージ"),
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
        .nameJapanese = __("ポチエナ　"),
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
        .nameJapanese = __("グラエナ　"),
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
        .nameJapanese = __("ジグザグマ"),
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
        .nameJapanese = __("マッスグマ"),
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
        .nameJapanese = __("ケムッソ　"),
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
        .nameJapanese = __("カラサリス"),
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
        .nameJapanese = __("アゲハント"),
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
        .nameJapanese = __("マユルド　"),
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
        .nameJapanese = __("ドクケイル"),
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
        .nameJapanese = __("ハスボー　"),
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
        .nameJapanese = __("ハスブレロ"),
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
        .nameJapanese = __("ルンパッパ"),
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
        .nameJapanese = __("タネボー　"),
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
        .nameJapanese = __("コノハナ　"),
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
        .nameJapanese = __("ダーテング"),
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
        .nameJapanese = __("スバメ　　"),
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
        .nameJapanese = __("オオスバメ"),
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
        .nameJapanese = __("キャモメ　"),
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
        .nameJapanese = __("ペリッパー"),
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
        .nameJapanese = __("ラルトス　"),
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
        .nameJapanese = __("キルリア　"),
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
        .nameJapanese = __("サーナイト"),
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
        .nameJapanese = __("アメタマ　"),
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
        .nameJapanese = __("アメモース"),
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
        .nameJapanese = __("キノココ　"),
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
        .nameJapanese = __("キノガッサ"),
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
        .nameJapanese = __("ナマケロ　"),
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
        .nameJapanese = __("ヤルキモノ"),
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
        .nameJapanese = __("ケッキング"),
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
        .nameJapanese = __("ケーシィ　"),
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
        .nameJapanese = __("ユンゲラー"),
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
        .nameJapanese = __("フーディン"),
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
        .nameJapanese = __("ツチニン　"),
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
        .nameJapanese = __("テッカニン"),
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
        .nameJapanese = __("ヌケニン　"),
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
        .nameJapanese = __("ゴニョニョ"),
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
        .nameJapanese = __("ドゴーム　"),
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
        .nameJapanese = __("バクオング"),
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
        .nameJapanese = __("マクノシタ"),
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
        .nameJapanese = __("ハリテヤマ"),
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
        .nameJapanese = __("トサキント"),
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
        .nameJapanese = __("アズマオウ"),
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
        .nameJapanese = __("コイキング"),
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
        .nameJapanese = __("ギャラドス"),
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
        .nameJapanese = __("ルリリ　　"),
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
        .nameJapanese = __("マリル　　"),
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
        .nameJapanese = __("マリルリ　"),
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
        .nameJapanese = __("イシツブテ"),
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
        .nameJapanese = __("ゴローン　"),
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
        .nameJapanese = __("ゴローニャ"),
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
        .nameJapanese = __("ノズパス　"),
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
        .nameJapanese = __("エネコ　　"),
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
        .nameJapanese = __("エネコロロ"),
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
        .nameJapanese = __("ズバット　"),
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
        .nameJapanese = __("ゴルバット"),
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
        .nameJapanese = __("クロバット"),
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
        .nameJapanese = __("メノクラゲ"),
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
        .nameJapanese = __("ドククラゲ"),
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
        .nameJapanese = __("ヤミラミ　"),
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
        .nameJapanese = __("クチート　"),
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
        .nameJapanese = __("ココドラ　"),
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
        .nameJapanese = __("コドラ　　"),
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
        .nameJapanese = __("ボスゴドラ"),
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
        .nameJapanese = __("ワンリキー"),
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
        .nameJapanese = __("ゴーリキー"),
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
        .nameJapanese = __("カイリキー"),
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
        .nameJapanese = __("アサナン　"),
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
        .nameJapanese = __("チャーレム"),
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
        .nameJapanese = __("ラクライ　"),
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
        .nameJapanese = __("ライボルト"),
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
        .nameJapanese = __("プラスル　"),
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
        .nameJapanese = __("マイナン　"),
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
        .nameJapanese = __("コイル　　"),
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
        .nameJapanese = __("レアコイル"),
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
        .nameJapanese = __("ビリリダマ"),
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
        .nameJapanese = __("マルマイン"),
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
        .nameJapanese = __("バルビート"),
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
        .nameJapanese = __("イルミーゼ"),
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
        .nameJapanese = __("ナゾノクサ"),
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
        .nameJapanese = __("クサイハナ"),
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
        .nameJapanese = __("ラフレシア"),
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
        .nameJapanese = __("キレイハナ"),
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
        .nameJapanese = __("ドードー　"),
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
        .nameJapanese = __("ドードリオ"),
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
        .nameJapanese = __("ロゼリア　"),
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
        .nameJapanese = __("ゴクリン　"),
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
        .nameJapanese = __("マルノーム"),
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
        .nameJapanese = __("キバニア　"),
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
        .nameJapanese = __("サメハダー"),
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
        .nameJapanese = __("ホエルコ　"),
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
        .nameJapanese = __("ホエルオー"),
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
        .nameJapanese = __("ドンメル　"),
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
        .nameJapanese = __("バクーダ　"),
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
        .nameJapanese = __("マグマッグ"),
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
        .nameJapanese = __("マグカルゴ"),
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
        .nameJapanese = __("コータス　"),
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
        .nameJapanese = __("ベトベター"),
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
        .nameJapanese = __("ベトベトン"),
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
        .nameJapanese = __("ドガース　"),
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
        .nameJapanese = __("マタドガス"),
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
        .nameJapanese = __("バネブー　"),
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
        .nameJapanese = __("ブーピッグ"),
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
        .nameJapanese = __("サンド　　"),
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
        .nameJapanese = __("サンドパン"),
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
        .nameJapanese = __("パッチール"),
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
        .nameJapanese = __("エアームド"),
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
        .nameJapanese = __("ナックラー"),
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
        .nameJapanese = __("ビブラーバ"),
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
        .nameJapanese = __("フライゴン"),
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
        .nameJapanese = __("サボネア　"),
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
        .nameJapanese = __("ノクタス　"),
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
        .nameJapanese = __("チルット　"),
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
        .nameJapanese = __("チルタリス"),
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
        .nameJapanese = __("ザングース"),
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
        .nameJapanese = __("ハブネーク"),
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
        .nameJapanese = __("ルナトーン"),
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
        .nameJapanese = __("ソルロック"),
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
        .nameJapanese = __("ドジョッチ"),
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
        .nameJapanese = __("ナマズン　"),
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
        .nameJapanese = __("ヘイガニ　"),
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
        .nameJapanese = __("シザリガー"),
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
        .nameJapanese = __("ヤジロン　"),
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
        .nameJapanese = __("ネンドール"),
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
        .nameJapanese = __("リリーラ　"),
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
        .nameJapanese = __("ユレイドル"),
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
        .nameJapanese = __("アノプス　"),
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
        .nameJapanese = __("アーマルド"),
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
        .nameJapanese = __("ププリン　"),
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
        .nameJapanese = __("プリン　　"),
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
        .nameJapanese = __("プクリン　"),
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
        .nameJapanese = __("ヒンバス　"),
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
        .nameJapanese = __("ミロカロス"),
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
        .nameJapanese = __("ポワルン　"),
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
        .nameJapanese = __("ヒトデマン"),
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
        .nameJapanese = __("スターミー"),
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
        .nameJapanese = __("カクレオン"),
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
        .nameJapanese = __("カゲボウズ"),
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
        .nameJapanese = __("ジュペッタ"),
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
        .nameJapanese = __("ヨマワル　"),
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
        .nameJapanese = __("サマヨール"),
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
        .nameJapanese = __("トロピウス"),
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
        .nameJapanese = __("チリーン　"),
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
        .nameJapanese = __("アブソル　"),
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
        .nameJapanese = __("ロコン　　"),
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
        .nameJapanese = __("キュウコン"),
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
        .nameJapanese = __("ピチュー　"),
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
        .nameJapanese = __("ピカチュウ"),
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
        .nameJapanese = __("ライチュウ"),
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
        .nameJapanese = __("コダック　"),
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
        .nameJapanese = __("ゴルダック"),
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
        .nameJapanese = __("ソーナノ　"),
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
        .nameJapanese = __("ソーナンス"),
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
        .nameJapanese = __("ネイティ　"),
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
        .nameJapanese = __("ネイティオ"),
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
        .nameJapanese = __("キリンリキ"),
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
        .nameJapanese = __("ゴマゾウ　"),
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
        .nameJapanese = __("ドンファン"),
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
        .nameJapanese = __("カイロス　"),
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
        .nameJapanese = __("ヘラクロス"),
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
        .nameJapanese = __("サイホーン"),
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
        .nameJapanese = __("サイドン　"),
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
        .nameJapanese = __("ユキワラシ"),
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
        .nameJapanese = __("オニゴーリ"),
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
        .nameJapanese = __("タマザラシ"),
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
        .nameJapanese = __("トドグラー"),
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
        .nameJapanese = __("トドゼルガ"),
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
        .nameJapanese = __("パールル　"),
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
        .nameJapanese = __("ハンテール"),
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
        .nameJapanese = __("サクラビス"),
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
        .nameJapanese = __("ジーランス"),
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
        .nameJapanese = __("サニーゴ　"),
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
        .nameJapanese = __("チョンチー"),
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
        .nameJapanese = __("ランターン"),
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
        .nameJapanese = __("ラブカス　"),
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
        .nameJapanese = __("タッツー　"),
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
        .nameJapanese = __("シードラ　"),
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
        .nameJapanese = __("キングドラ"),
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
        .nameJapanese = __("タツベイ　"),
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
        .nameJapanese = __("コモルー　"),
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
        .nameJapanese = __("ボーマンダ"),
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
        .nameJapanese = __("ダンバル　"),
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
        .nameJapanese = __("メタング　"),
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
        .nameJapanese = __("メタグロス"),
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
        .nameJapanese = __("レジロック"),
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
        .nameJapanese = __("レジアイス"),
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
        .nameJapanese = __("レジスチル"),
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
        .nameJapanese = __("ラティアス"),
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
        .nameJapanese = __("ラティオス"),
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
        .nameJapanese = __("カイオーガ"),
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
        .nameJapanese = __("グラードン"),
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
        .nameJapanese = __("レックウザ"),
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
        .nameJapanese = __("ジラーチ　"),
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
        .nameJapanese = __("チコリータ"),
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
        .nameJapanese = __("ヒノアラシ"),
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
        .nameJapanese = __("ワニノコ　"),
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
        .nameJapanese = __("プテラ　　"),
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
