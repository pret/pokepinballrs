const struct PokemonSpecies gSpeciesInfo[NUM_SPECIES] = {
    [SPECIES_TREECKO] = {
        .mainSeriesIndexNumber = 277,
        .nameJapanese = __("キモリ　　"),
        .name = "TREECKO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GROVYLE
    },
    [SPECIES_GROVYLE] = {
        .mainSeriesIndexNumber = 278,
        .nameJapanese = __("ジュプトル"),
        .name = "GROVYLE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SCEPTILE
    },
    [SPECIES_SCEPTILE] = {
        .mainSeriesIndexNumber = 279,
        .nameJapanese = __("ジュカイン"),
        .name = "SCEPTILE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORCHIC] = {
        .mainSeriesIndexNumber = 280,
        .nameJapanese = __("アチャモ　"),
        .name = "TORCHIC   ",
        .catchIndex = 1,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_COMBUSKEN
    },
    [SPECIES_COMBUSKEN] = {
        .mainSeriesIndexNumber = 281,
        .nameJapanese = __("ワカシャモ"),
        .name = "COMBUSKEN ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BLAZIKEN
    },
    [SPECIES_BLAZIKEN] = {
        .mainSeriesIndexNumber = 282,
        .nameJapanese = __("バシャーモ"),
        .name = "BLAZIKEN  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MUDKIP] = {
        .mainSeriesIndexNumber = 283,
        .nameJapanese = __("ミズゴロウ"),
        .name = "MUDKIP    ",
        .catchIndex = 2,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MARSHTOMP
    },
    [SPECIES_MARSHTOMP] = {
        .mainSeriesIndexNumber = 284,
        .nameJapanese = __("ヌマクロー"),
        .name = "MARSHTOMP ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWAMPERT
    },
    [SPECIES_SWAMPERT] = {
        .mainSeriesIndexNumber = 285,
        .nameJapanese = __("ラグラージ"),
        .name = "SWAMPERT  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_POOCHYENA] = {
        .mainSeriesIndexNumber = 286,
        .nameJapanese = __("ポチエナ　"),
        .name = "POOCHYENA ",
        .catchIndex = 3,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MIGHTYENA
    },
    [SPECIES_MIGHTYENA] = {
        .mainSeriesIndexNumber = 287,
        .nameJapanese = __("グラエナ　"),
        .name = "MIGHTYENA ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZIGZAGOON] = {
        .mainSeriesIndexNumber = 288,
        .nameJapanese = __("ジグザグマ"),
        .name = "ZIGZAGOON ",
        .catchIndex = 4,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LINOONE
    },
    [SPECIES_LINOONE] = {
        .mainSeriesIndexNumber = 289,
        .nameJapanese = __("マッスグマ"),
        .name = "LINOONE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WURMPLE] = {
        .mainSeriesIndexNumber = 290,
        .nameJapanese = __("ケムッソ　"),
        .name = "WURMPLE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_SILCOON
    },
    [SPECIES_SILCOON] = {
        .mainSeriesIndexNumber = 291,
        .nameJapanese = __("カラサリス"),
        .name = "SILCOON   ",
        .catchIndex = 5,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BEAUTIFLY
    },
    [SPECIES_BEAUTIFLY] = {
        .mainSeriesIndexNumber = 292,
        .nameJapanese = __("アゲハント"),
        .name = "BEAUTIFLY ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASCOON] = {
        .mainSeriesIndexNumber = 293,
        .nameJapanese = __("マユルド　"),
        .name = "CASCOON   ",
        .catchIndex = 6,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSTOX
    },
    [SPECIES_DUSTOX] = {
        .mainSeriesIndexNumber = 294,
        .nameJapanese = __("ドクケイル"),
        .name = "DUSTOX    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LOTAD] = {
        .mainSeriesIndexNumber = 295,
        .nameJapanese = __("ハスボー　"),
        .name = "LOTAD     ",
        .catchIndex = 0,
        .eggIndex = 1,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOMBRE
    },
    [SPECIES_LOMBRE] = {
        .mainSeriesIndexNumber = 296,
        .nameJapanese = __("ハスブレロ"),
        .name = "LOMBRE    ",
        .catchIndex = 7,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_LUDICOLO
    },
    [SPECIES_LUDICOLO] = {
        .mainSeriesIndexNumber = 297,
        .nameJapanese = __("ルンパッパ"),
        .name = "LUDICOLO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEEDOT] = {
        .mainSeriesIndexNumber = 298,
        .nameJapanese = __("タネボー　"),
        .name = "SEEDOT    ",
        .catchIndex = 0,
        .eggIndex = 2,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NUZLEAF
    },
    [SPECIES_NUZLEAF] = {
        .mainSeriesIndexNumber = 299,
        .nameJapanese = __("コノハナ　"),
        .name = "NUZLEAF   ",
        .catchIndex = 8,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 2,
        .evolutionTarget = SPECIES_SHIFTRY
    },
    [SPECIES_SHIFTRY] = {
        .mainSeriesIndexNumber = 300,
        .nameJapanese = __("ダーテング"),
        .name = "SHIFTRY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TAILLOW] = {
        .mainSeriesIndexNumber = 304,
        .nameJapanese = __("スバメ　　"),
        .name = "TAILLOW   ",
        .catchIndex = 9,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWELLOW
    },
    [SPECIES_SWELLOW] = {
        .mainSeriesIndexNumber = 305,
        .nameJapanese = __("オオスバメ"),
        .name = "SWELLOW   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WINGULL] = {
        .mainSeriesIndexNumber = 309,
        .nameJapanese = __("キャモメ　"),
        .name = "WINGULL   ",
        .catchIndex = 10,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PELIPPER
    },
    [SPECIES_PELIPPER] = {
        .mainSeriesIndexNumber = 310,
        .nameJapanese = __("ペリッパー"),
        .name = "PELIPPER  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RALTS] = {
        .mainSeriesIndexNumber = 392,
        .nameJapanese = __("ラルトス　"),
        .name = "RALTS     ",
        .catchIndex = 0,
        .eggIndex = 3,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KIRLIA
    },
    [SPECIES_KIRLIA] = {
        .mainSeriesIndexNumber = 393,
        .nameJapanese = __("キルリア　"),
        .name = "KIRLIA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GARDEVOIR
    },
    [SPECIES_GARDEVOIR] = {
        .mainSeriesIndexNumber = 394,
        .nameJapanese = __("サーナイト"),
        .name = "GARDEVOIR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SURSKIT] = {
        .mainSeriesIndexNumber = 311,
        .nameJapanese = __("アメタマ　"),
        .name = "SURSKIT   ",
        .catchIndex = 0,
        .eggIndex = 4,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MASQUERAIN
    },
    [SPECIES_MASQUERAIN] = {
        .mainSeriesIndexNumber = 312,
        .nameJapanese = __("アメモース"),
        .name = "MASQUERAIN",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHROOMISH] = {
        .mainSeriesIndexNumber = 306,
        .nameJapanese = __("キノココ　"),
        .name = "SHROOMISH ",
        .catchIndex = 0,
        .eggIndex = 5,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BRELOOM
    },
    [SPECIES_BRELOOM] = {
        .mainSeriesIndexNumber = 307,
        .nameJapanese = __("キノガッサ"),
        .name = "BRELOOM   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLAKOTH] = {
        .mainSeriesIndexNumber = 364,
        .nameJapanese = __("ナマケロ　"),
        .name = "SLAKOTH   ",
        .catchIndex = 11,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIGOROTH
    },
    [SPECIES_VIGOROTH] = {
        .mainSeriesIndexNumber = 365,
        .nameJapanese = __("ヤルキモノ"),
        .name = "VIGOROTH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SLAKING
    },
    [SPECIES_SLAKING] = {
        .mainSeriesIndexNumber = 366,
        .nameJapanese = __("ケッキング"),
        .name = "SLAKING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABRA] = {
        .mainSeriesIndexNumber = 63,
        .nameJapanese = __("ケーシィ　"),
        .name = "ABRA      ",
        .catchIndex = 12,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KADABRA
    },
    [SPECIES_KADABRA] = {
        .mainSeriesIndexNumber = 64,
        .nameJapanese = __("ユンゲラー"),
        .name = "KADABRA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_ALAKAZAM
    },
    [SPECIES_ALAKAZAM] = {
        .mainSeriesIndexNumber = 65,
        .nameJapanese = __("フーディン"),
        .name = "ALAKAZAM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NINCADA] = {
        .mainSeriesIndexNumber = 301,
        .nameJapanese = __("ツチニン　"),
        .name = "NINCADA   ",
        .catchIndex = 13,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NINJASK
    },
    [SPECIES_NINJASK] = {
        .mainSeriesIndexNumber = 302,
        .nameJapanese = __("テッカニン"),
        .name = "NINJASK   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHEDINJA] = {
        .mainSeriesIndexNumber = 303,
        .nameJapanese = __("ヌケニン　"),
        .name = "SHEDINJA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WHISMUR] = {
        .mainSeriesIndexNumber = 370,
        .nameJapanese = __("ゴニョニョ"),
        .name = "WHISMUR   ",
        .catchIndex = 0,
        .eggIndex = 6,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOUDRED
    },
    [SPECIES_LOUDRED] = {
        .mainSeriesIndexNumber = 371,
        .nameJapanese = __("ドゴーム　"),
        .name = "LOUDRED   ",
        .catchIndex = 14,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_EXPLOUD
    },
    [SPECIES_EXPLOUD] = {
        .mainSeriesIndexNumber = 372,
        .nameJapanese = __("バクオング"),
        .name = "EXPLOUD   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAKUHITA] = {
        .mainSeriesIndexNumber = 335,
        .nameJapanese = __("マクノシタ"),
        .name = "MAKUHITA  ",
        .catchIndex = 15,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HARIYAMA
    },
    [SPECIES_HARIYAMA] = {
        .mainSeriesIndexNumber = 336,
        .nameJapanese = __("ハリテヤマ"),
        .name = "HARIYAMA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOLDEEN] = {
        .mainSeriesIndexNumber = 118,
        .nameJapanese = __("トサキント"),
        .name = "GOLDEEN   ",
        .catchIndex = 16,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEAKING
    },
    [SPECIES_SEAKING] = {
        .mainSeriesIndexNumber = 119,
        .nameJapanese = __("アズマオウ"),
        .name = "SEAKING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGIKARP] = {
        .mainSeriesIndexNumber = 129,
        .nameJapanese = __("コイキング"),
        .name = "MAGIKARP  ",
        .catchIndex = 17,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GYARADOS
    },
    [SPECIES_GYARADOS] = {
        .mainSeriesIndexNumber = 130,
        .nameJapanese = __("ギャラドス"),
        .name = "GYARADOS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AZURILL] = {
        .mainSeriesIndexNumber = 350,
        .nameJapanese = __("ルリリ　　"),
        .name = "AZURILL   ",
        .catchIndex = 0,
        .eggIndex = 7,
        .unk13 = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_MARILL
    },
    [SPECIES_MARILL] = {
        .mainSeriesIndexNumber = 183,
        .nameJapanese = __("マリル　　"),
        .name = "MARILL    ",
        .catchIndex = 18,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AZUMARILL
    },
    [SPECIES_AZUMARILL] = {
        .mainSeriesIndexNumber = 184,
        .nameJapanese = __("マリルリ　"),
        .name = "AZUMARILL ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GEODUDE] = {
        .mainSeriesIndexNumber = 74,
        .nameJapanese = __("イシツブテ"),
        .name = "GEODUDE   ",
        .catchIndex = 19,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRAVELER
    },
    [SPECIES_GRAVELER] = {
        .mainSeriesIndexNumber = 75,
        .nameJapanese = __("ゴローン　"),
        .name = "GRAVELER  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_GOLEM
    },
    [SPECIES_GOLEM] = {
        .mainSeriesIndexNumber = 76,
        .nameJapanese = __("ゴローニャ"),
        .name = "GOLEM     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NOSEPASS] = {
        .mainSeriesIndexNumber = 320,
        .nameJapanese = __("ノズパス　"),
        .name = "NOSEPASS  ",
        .catchIndex = 20,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKITTY] = {
        .mainSeriesIndexNumber = 315,
        .nameJapanese = __("エネコ　　"),
        .name = "SKITTY    ",
        .catchIndex = 0,
        .eggIndex = 8,
        .unk13 = 1,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_DELCATTY
    },
    [SPECIES_DELCATTY] = {
        .mainSeriesIndexNumber = 316,
        .nameJapanese = __("エネコロロ"),
        .name = "DELCATTY  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZUBAT] = {
        .mainSeriesIndexNumber = 41,
        .nameJapanese = __("ズバット　"),
        .name = "ZUBAT     ",
        .catchIndex = 0,
        .eggIndex = 9,
        .unk13 = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLBAT
    },
    [SPECIES_GOLBAT] = {
        .mainSeriesIndexNumber = 42,
        .nameJapanese = __("ゴルバット"),
        .name = "GOLBAT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_CROBAT
    },
    [SPECIES_CROBAT] = {
        .mainSeriesIndexNumber = 169,
        .nameJapanese = __("クロバット"),
        .name = "CROBAT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TENTACOOL] = {
        .mainSeriesIndexNumber = 72,
        .nameJapanese = __("メノクラゲ"),
        .name = "TENTACOOL ",
        .catchIndex = 21,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TENTACRUEL
    },
    [SPECIES_TENTACRUEL] = {
        .mainSeriesIndexNumber = 73,
        .nameJapanese = __("ドククラゲ"),
        .name = "TENTACRUEL",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SABLEYE] = {
        .mainSeriesIndexNumber = 322,
        .nameJapanese = __("ヤミラミ　"),
        .name = "SABLEYE   ",
        .catchIndex = 22,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAWILE] = {
        .mainSeriesIndexNumber = 355,
        .nameJapanese = __("クチート　"),
        .name = "MAWILE    ",
        .catchIndex = 23,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ARON] = {
        .mainSeriesIndexNumber = 382,
        .nameJapanese = __("ココドラ　"),
        .name = "ARON      ",
        .catchIndex = 0,
        .eggIndex = 10,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LAIRON
    },
    [SPECIES_LAIRON] = {
        .mainSeriesIndexNumber = 383,
        .nameJapanese = __("コドラ　　"),
        .name = "LAIRON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AGGRON
    },
    [SPECIES_AGGRON] = {
        .mainSeriesIndexNumber = 384,
        .nameJapanese = __("ボスゴドラ"),
        .name = "AGGRON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MACHOP] = {
        .mainSeriesIndexNumber = 66,
        .nameJapanese = __("ワンリキー"),
        .name = "MACHOP    ",
        .catchIndex = 24,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MACHOKE
    },
    [SPECIES_MACHOKE] = {
        .mainSeriesIndexNumber = 67,
        .nameJapanese = __("ゴーリキー"),
        .name = "MACHOKE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_MACHAMP
    },
    [SPECIES_MACHAMP] = {
        .mainSeriesIndexNumber = 68,
        .nameJapanese = __("カイリキー"),
        .name = "MACHAMP   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEDITITE] = {
        .mainSeriesIndexNumber = 356,
        .nameJapanese = __("アサナン　"),
        .name = "MEDITITE  ",
        .catchIndex = 25,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MEDICHAM
    },
    [SPECIES_MEDICHAM] = {
        .mainSeriesIndexNumber = 357,
        .nameJapanese = __("チャーレム"),
        .name = "MEDICHAM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ELECTRIKE] = {
        .mainSeriesIndexNumber = 337,
        .nameJapanese = __("ラクライ　"),
        .name = "ELECTRIKE ",
        .catchIndex = 26,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MANECTRIC
    },
    [SPECIES_MANECTRIC] = {
        .mainSeriesIndexNumber = 338,
        .nameJapanese = __("ライボルト"),
        .name = "MANECTRIC ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PLUSLE] = {
        .mainSeriesIndexNumber = 353,
        .nameJapanese = __("プラスル　"),
        .name = "PLUSLE    ",
        .catchIndex = 0,
        .eggIndex = 11,
        .unk13 = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MINUN] = {
        .mainSeriesIndexNumber = 354,
        .nameJapanese = __("マイナン　"),
        .name = "MINUN     ",
        .catchIndex = 0,
        .eggIndex = 12,
        .unk13 = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGNEMITE] = {
        .mainSeriesIndexNumber = 81,
        .nameJapanese = __("コイル　　"),
        .name = "MAGNEMITE ",
        .catchIndex = 27,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGNETON
    },
    [SPECIES_MAGNETON] = {
        .mainSeriesIndexNumber = 82,
        .nameJapanese = __("レアコイル"),
        .name = "MAGNETON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLTORB] = {
        .mainSeriesIndexNumber = 100,
        .nameJapanese = __("ビリリダマ"),
        .name = "VOLTORB   ",
        .catchIndex = 28,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ELECTRODE
    },
    [SPECIES_ELECTRODE] = {
        .mainSeriesIndexNumber = 101,
        .nameJapanese = __("マルマイン"),
        .name = "ELECTRODE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLBEAT] = {
        .mainSeriesIndexNumber = 386,
        .nameJapanese = __("バルビート"),
        .name = "VOLBEAT   ",
        .catchIndex = 29,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ILLUMISE] = {
        .mainSeriesIndexNumber = 387,
        .nameJapanese = __("イルミーゼ"),
        .name = "ILLUMISE  ",
        .catchIndex = 30,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ODDISH] = {
        .mainSeriesIndexNumber = 43,
        .nameJapanese = __("ナゾノクサ"),
        .name = "ODDISH    ",
        .catchIndex = 0,
        .eggIndex = 13,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLOOM
    },
    [SPECIES_GLOOM] = {
        .mainSeriesIndexNumber = 44,
        .nameJapanese = __("クサイハナ"),
        .name = "GLOOM     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_VILEPLUME
    },
    [SPECIES_VILEPLUME] = {
        .mainSeriesIndexNumber = 45,
        .nameJapanese = __("ラフレシア"),
        .name = "VILEPLUME ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELLOSSOM] = {
        .mainSeriesIndexNumber = 182,
        .nameJapanese = __("キレイハナ"),
        .name = "BELLOSSOM ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DODUO] = {
        .mainSeriesIndexNumber = 84,
        .nameJapanese = __("ドードー　"),
        .name = "DODUO     ",
        .catchIndex = 31,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DODRIO
    },
    [SPECIES_DODRIO] = {
        .mainSeriesIndexNumber = 85,
        .nameJapanese = __("ドードリオ"),
        .name = "DODRIO    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ROSELIA] = {
        .mainSeriesIndexNumber = 363,
        .nameJapanese = __("ロゼリア　"),
        .name = "ROSELIA   ",
        .catchIndex = 32,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GULPIN] = {
        .mainSeriesIndexNumber = 367,
        .nameJapanese = __("ゴクリン　"),
        .name = "GULPIN    ",
        .catchIndex = 0,
        .eggIndex = 14,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWALOT
    },
    [SPECIES_SWALOT] = {
        .mainSeriesIndexNumber = 368,
        .nameJapanese = __("マルノーム"),
        .name = "SWALOT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CARVANHA] = {
        .mainSeriesIndexNumber = 330,
        .nameJapanese = __("キバニア　"),
        .name = "CARVANHA  ",
        .catchIndex = 33,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHARPEDO
    },
    [SPECIES_SHARPEDO] = {
        .mainSeriesIndexNumber = 331,
        .nameJapanese = __("サメハダー"),
        .name = "SHARPEDO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WAILMER] = {
        .mainSeriesIndexNumber = 313,
        .nameJapanese = __("ホエルコ　"),
        .name = "WAILMER   ",
        .catchIndex = 34,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WAILORD
    },
    [SPECIES_WAILORD] = {
        .mainSeriesIndexNumber = 314,
        .nameJapanese = __("ホエルオー"),
        .name = "WAILORD   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NUMEL] = {
        .mainSeriesIndexNumber = 339,
        .nameJapanese = __("ドンメル　"),
        .name = "NUMEL     ",
        .catchIndex = 35,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CAMERUPT
    },
    [SPECIES_CAMERUPT] = {
        .mainSeriesIndexNumber = 340,
        .nameJapanese = __("バクーダ　"),
        .name = "CAMERUPT  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLUGMA] = {
        .mainSeriesIndexNumber = 218,
        .nameJapanese = __("マグマッグ"),
        .name = "SLUGMA    ",
        .catchIndex = 36,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGCARGO
    },
    [SPECIES_MAGCARGO] = {
        .mainSeriesIndexNumber = 219,
        .nameJapanese = __("マグカルゴ"),
        .name = "MAGCARGO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORKOAL] = {
        .mainSeriesIndexNumber = 321,
        .nameJapanese = __("コータス　"),
        .name = "TORKOAL   ",
        .catchIndex = 37,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GRIMER] = {
        .mainSeriesIndexNumber = 88,
        .nameJapanese = __("ベトベター"),
        .name = "GRIMER    ",
        .catchIndex = 38,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MUK
    },
    [SPECIES_MUK] = {
        .mainSeriesIndexNumber = 89,
        .nameJapanese = __("ベトベトン"),
        .name = "MUK       ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KOFFING] = {
        .mainSeriesIndexNumber = 109,
        .nameJapanese = __("ドガース　"),
        .name = "KOFFING   ",
        .catchIndex = 39,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WEEZING
    },
    [SPECIES_WEEZING] = {
        .mainSeriesIndexNumber = 110,
        .nameJapanese = __("マタドガス"),
        .name = "WEEZING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPOINK] = {
        .mainSeriesIndexNumber = 351,
        .nameJapanese = __("バネブー　"),
        .name = "SPOINK    ",
        .catchIndex = 0,
        .eggIndex = 15,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRUMPIG
    },
    [SPECIES_GRUMPIG] = {
        .mainSeriesIndexNumber = 352,
        .nameJapanese = __("ブーピッグ"),
        .name = "GRUMPIG   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SANDSHREW] = {
        .mainSeriesIndexNumber = 27,
        .nameJapanese = __("サンド　　"),
        .name = "SANDSHREW ",
        .catchIndex = 0,
        .eggIndex = 16,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SANDSLASH
    },
    [SPECIES_SANDSLASH] = {
        .mainSeriesIndexNumber = 28,
        .nameJapanese = __("サンドパン"),
        .name = "SANDSLASH ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPINDA] = {
        .mainSeriesIndexNumber = 308,
        .nameJapanese = __("パッチール"),
        .name = "SPINDA    ",
        .catchIndex = 0,
        .eggIndex = 17,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKARMORY] = {
        .mainSeriesIndexNumber = 227,
        .nameJapanese = __("エアームド"),
        .name = "SKARMORY  ",
        .catchIndex = 40,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TRAPINCH] = {
        .mainSeriesIndexNumber = 332,
        .nameJapanese = __("ナックラー"),
        .name = "TRAPINCH  ",
        .catchIndex = 0,
        .eggIndex = 18,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIBRAVA
    },
    [SPECIES_VIBRAVA] = {
        .mainSeriesIndexNumber = 333,
        .nameJapanese = __("ビブラーバ"),
        .name = "VIBRAVA   ",
        .catchIndex = 41,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FLYGON
    },
    [SPECIES_FLYGON] = {
        .mainSeriesIndexNumber = 334,
        .nameJapanese = __("フライゴン"),
        .name = "FLYGON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CACNEA] = {
        .mainSeriesIndexNumber = 344,
        .nameJapanese = __("サボネア　"),
        .name = "CACNEA    ",
        .catchIndex = 42,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CACTURNE
    },
    [SPECIES_CACTURNE] = {
        .mainSeriesIndexNumber = 345,
        .nameJapanese = __("ノクタス　"),
        .name = "CACTURNE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SWABLU] = {
        .mainSeriesIndexNumber = 358,
        .nameJapanese = __("チルット　"),
        .name = "SWABLU    ",
        .catchIndex = 43,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ALTARIA
    },
    [SPECIES_ALTARIA] = {
        .mainSeriesIndexNumber = 359,
        .nameJapanese = __("チルタリス"),
        .name = "ALTARIA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZANGOOSE] = {
        .mainSeriesIndexNumber = 380,
        .nameJapanese = __("ザングース"),
        .name = "ZANGOOSE  ",
        .catchIndex = 44,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEVIPER] = {
        .mainSeriesIndexNumber = 379,
        .nameJapanese = __("ハブネーク"),
        .name = "SEVIPER   ",
        .catchIndex = 45,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUNATONE] = {
        .mainSeriesIndexNumber = 348,
        .nameJapanese = __("ルナトーン"),
        .name = "LUNATONE  ",
        .catchIndex = 46,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SOLROCK] = {
        .mainSeriesIndexNumber = 349,
        .nameJapanese = __("ソルロック"),
        .name = "SOLROCK   ",
        .catchIndex = 47,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BARBOACH] = {
        .mainSeriesIndexNumber = 323,
        .nameJapanese = __("ドジョッチ"),
        .name = "BARBOACH  ",
        .catchIndex = 48,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WHISCASH
    },
    [SPECIES_WHISCASH] = {
        .mainSeriesIndexNumber = 324,
        .nameJapanese = __("ナマズン　"),
        .name = "WHISCASH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORPHISH] = {
        .mainSeriesIndexNumber = 326,
        .nameJapanese = __("ヘイガニ　"),
        .name = "CORPHISH  ",
        .catchIndex = 49,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRAWDAUNT
    },
    [SPECIES_CRAWDAUNT] = {
        .mainSeriesIndexNumber = 327,
        .nameJapanese = __("シザリガー"),
        .name = "CRAWDAUNT ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BALTOY] = {
        .mainSeriesIndexNumber = 318,
        .nameJapanese = __("ヤジロン　"),
        .name = "BALTOY    ",
        .catchIndex = 50,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CLAYDOL
    },
    [SPECIES_CLAYDOL] = {
        .mainSeriesIndexNumber = 319,
        .nameJapanese = __("ネンドール"),
        .name = "CLAYDOL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LILEEP] = {
        .mainSeriesIndexNumber = 388,
        .nameJapanese = __("リリーラ　"),
        .name = "LILEEP    ",
        .catchIndex = 51,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRADILY
    },
    [SPECIES_CRADILY] = {
        .mainSeriesIndexNumber = 389,
        .nameJapanese = __("ユレイドル"),
        .name = "CRADILY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ANORITH] = {
        .mainSeriesIndexNumber = 390,
        .nameJapanese = __("アノプス　"),
        .name = "ANORITH   ",
        .catchIndex = 52,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ARMALDO
    },
    [SPECIES_ARMALDO] = {
        .mainSeriesIndexNumber = 391,
        .nameJapanese = __("アーマルド"),
        .name = "ARMALDO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_IGGLYBUFF] = {
        .mainSeriesIndexNumber = 174,
        .nameJapanese = __("ププリン　"),
        .name = "IGGLYBUFF ",
        .catchIndex = 0,
        .eggIndex = 19,
        .unk13 = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_JIGGLYPUFF
    },
    [SPECIES_JIGGLYPUFF] = {
        .mainSeriesIndexNumber = 39,
        .nameJapanese = __("プリン　　"),
        .name = "JIGGLYPUFF",
        .catchIndex = 53,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_WIGGLYTUFF
    },
    [SPECIES_WIGGLYTUFF] = {
        .mainSeriesIndexNumber = 40,
        .nameJapanese = __("プクリン　"),
        .name = "WIGGLYTUFF",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FEEBAS] = {
        .mainSeriesIndexNumber = 328,
        .nameJapanese = __("ヒンバス　"),
        .name = "FEEBAS    ",
        .catchIndex = 54,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 10,
        .evolutionTarget = SPECIES_MILOTIC
    },
    [SPECIES_MILOTIC] = {
        .mainSeriesIndexNumber = 329,
        .nameJapanese = __("ミロカロス"),
        .name = "MILOTIC   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASTFORM] = {
        .mainSeriesIndexNumber = 385,
        .nameJapanese = __("ポワルン　"),
        .name = "CASTFORM  ",
        .catchIndex = 55,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_STARYU] = {
        .mainSeriesIndexNumber = 120,
        .nameJapanese = __("ヒトデマン"),
        .name = "STARYU    ",
        .catchIndex = 56,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_STARMIE
    },
    [SPECIES_STARMIE] = {
        .mainSeriesIndexNumber = 121,
        .nameJapanese = __("スターミー"),
        .name = "STARMIE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KECLEON] = {
        .mainSeriesIndexNumber = 317,
        .nameJapanese = __("カクレオン"),
        .name = "KECLEON   ",
        .catchIndex = 57,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHUPPET] = {
        .mainSeriesIndexNumber = 377,
        .nameJapanese = __("カゲボウズ"),
        .name = "SHUPPET   ",
        .catchIndex = 0,
        .eggIndex = 20,
        .unk13 = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BANETTE
    },
    [SPECIES_BANETTE] = {
        .mainSeriesIndexNumber = 378,
        .nameJapanese = __("ジュペッタ"),
        .name = "BANETTE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DUSKULL] = {
        .mainSeriesIndexNumber = 361,
        .nameJapanese = __("ヨマワル　"),
        .name = "DUSKULL   ",
        .catchIndex = 58,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSCLOPS
    },
    [SPECIES_DUSCLOPS] = {
        .mainSeriesIndexNumber = 362,
        .nameJapanese = __("サマヨール"),
        .name = "DUSCLOPS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TROPIUS] = {
        .mainSeriesIndexNumber = 369,
        .nameJapanese = __("トロピウス"),
        .name = "TROPIUS   ",
        .catchIndex = 59,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIMECHO] = {
        .mainSeriesIndexNumber = 411,
        .nameJapanese = __("チリーン　"),
        .name = "CHIMECHO  ",
        .catchIndex = 0,
        .eggIndex = 21,
        .unk13 = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABSOL] = {
        .mainSeriesIndexNumber = 376,
        .nameJapanese = __("アブソル　"),
        .name = "ABSOL     ",
        .catchIndex = 60,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VULPIX] = {
        .mainSeriesIndexNumber = 37,
        .nameJapanese = __("ロコン　　"),
        .name = "VULPIX    ",
        .catchIndex = 61,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 3,
        .evolutionTarget = SPECIES_NINETALES
    },
    [SPECIES_NINETALES] = {
        .mainSeriesIndexNumber = 38,
        .nameJapanese = __("キュウコン"),
        .name = "NINETALES ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PICHU] = {
        .mainSeriesIndexNumber = 172,
        .nameJapanese = __("ピチュー　"),
        .name = "PICHU     ",
        .catchIndex = 0,
        .eggIndex = 22,
        .unk13 = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_PIKACHU
    },
    [SPECIES_PIKACHU] = {
        .mainSeriesIndexNumber = 25,
        .nameJapanese = __("ピカチュウ"),
        .name = "PIKACHU   ",
        .catchIndex = 62,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 7,
        .evolutionTarget = SPECIES_RAICHU
    },
    [SPECIES_RAICHU] = {
        .mainSeriesIndexNumber = 26,
        .nameJapanese = __("ライチュウ"),
        .name = "RAICHU    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PSYDUCK] = {
        .mainSeriesIndexNumber = 54,
        .nameJapanese = __("コダック　"),
        .name = "PSYDUCK   ",
        .catchIndex = 63,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLDUCK
    },
    [SPECIES_GOLDUCK] = {
        .mainSeriesIndexNumber = 55,
        .nameJapanese = __("ゴルダック"),
        .name = "GOLDUCK   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WYNAUT] = {
        .mainSeriesIndexNumber = 360,
        .nameJapanese = __("ソーナノ　"),
        .name = "WYNAUT    ",
        .catchIndex = 0,
        .eggIndex = 23,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WOBBUFFET
    },
    [SPECIES_WOBBUFFET] = {
        .mainSeriesIndexNumber = 202,
        .nameJapanese = __("ソーナンス"),
        .name = "WOBBUFFET ",
        .catchIndex = 64,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NATU] = {
        .mainSeriesIndexNumber = 177,
        .nameJapanese = __("ネイティ　"),
        .name = "NATU      ",
        .catchIndex = 0,
        .eggIndex = 24,
        .unk13 = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_XATU
    },
    [SPECIES_XATU] = {
        .mainSeriesIndexNumber = 178,
        .nameJapanese = __("ネイティオ"),
        .name = "XATU      ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GIRAFARIG] = {
        .mainSeriesIndexNumber = 203,
        .nameJapanese = __("キリンリキ"),
        .name = "GIRAFARIG ",
        .catchIndex = 65,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PHANPY] = {
        .mainSeriesIndexNumber = 231,
        .nameJapanese = __("ゴマゾウ　"),
        .name = "PHANPY    ",
        .catchIndex = 0,
        .eggIndex = 25,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DONPHAN
    },
    [SPECIES_DONPHAN] = {
        .mainSeriesIndexNumber = 232,
        .nameJapanese = __("ドンファン"),
        .name = "DONPHAN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PINSIR] = {
        .mainSeriesIndexNumber = 127,
        .nameJapanese = __("カイロス　"),
        .name = "PINSIR    ",
        .catchIndex = 66,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HERACROSS] = {
        .mainSeriesIndexNumber = 214,
        .nameJapanese = __("ヘラクロス"),
        .name = "HERACROSS ",
        .catchIndex = 67,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RHYHORN] = {
        .mainSeriesIndexNumber = 111,
        .nameJapanese = __("サイホーン"),
        .name = "RHYHORN   ",
        .catchIndex = 68,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RHYDON
    },
    [SPECIES_RHYDON] = {
        .mainSeriesIndexNumber = 112,
        .nameJapanese = __("サイドン　"),
        .name = "RHYDON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SNORUNT] = {
        .mainSeriesIndexNumber = 346,
        .nameJapanese = __("ユキワラシ"),
        .name = "SNORUNT   ",
        .catchIndex = 0,
        .eggIndex = 26,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLALIE
    },
    [SPECIES_GLALIE] = {
        .mainSeriesIndexNumber = 347,
        .nameJapanese = __("オニゴーリ"),
        .name = "GLALIE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPHEAL] = {
        .mainSeriesIndexNumber = 341,
        .nameJapanese = __("タマザラシ"),
        .name = "SPHEAL    ",
        .catchIndex = 0,
        .eggIndex = 27,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEALEO
    },
    [SPECIES_SEALEO] = {
        .mainSeriesIndexNumber = 342,
        .nameJapanese = __("トドグラー"),
        .name = "SEALEO    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WALREIN
    },
    [SPECIES_WALREIN] = {
        .mainSeriesIndexNumber = 343,
        .nameJapanese = __("トドゼルガ"),
        .name = "WALREIN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CLAMPERL] = {
        .mainSeriesIndexNumber = 373,
        .nameJapanese = __("パールル　"),
        .name = "CLAMPERL  ",
        .catchIndex = 69,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_HUNTAIL
    },
    [SPECIES_HUNTAIL] = {
        .mainSeriesIndexNumber = 374,
        .nameJapanese = __("ハンテール"),
        .name = "HUNTAIL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOREBYSS] = {
        .mainSeriesIndexNumber = 375,
        .nameJapanese = __("サクラビス"),
        .name = "GOREBYSS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RELICANTH] = {
        .mainSeriesIndexNumber = 381,
        .nameJapanese = __("ジーランス"),
        .name = "RELICANTH ",
        .catchIndex = 70,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORSOLA] = {
        .mainSeriesIndexNumber = 222,
        .nameJapanese = __("サニーゴ　"),
        .name = "CORSOLA   ",
        .catchIndex = 0,
        .eggIndex = 28,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHINCHOU] = {
        .mainSeriesIndexNumber = 170,
        .nameJapanese = __("チョンチー"),
        .name = "CHINCHOU  ",
        .catchIndex = 0,
        .eggIndex = 29,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LANTURN
    },
    [SPECIES_LANTURN] = {
        .mainSeriesIndexNumber = 171,
        .nameJapanese = __("ランターン"),
        .name = "LANTURN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUVDISC] = {
        .mainSeriesIndexNumber = 325,
        .nameJapanese = __("ラブカス　"),
        .name = "LUVDISC   ",
        .catchIndex = 71,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HORSEA] = {
        .mainSeriesIndexNumber = 116,
        .nameJapanese = __("タッツー　"),
        .name = "HORSEA    ",
        .catchIndex = 0,
        .eggIndex = 30,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEADRA
    },
    [SPECIES_SEADRA] = {
        .mainSeriesIndexNumber = 117,
        .nameJapanese = __("シードラ　"),
        .name = "SEADRA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_KINGDRA
    },
    [SPECIES_KINGDRA] = {
        .mainSeriesIndexNumber = 230,
        .nameJapanese = __("キングドラ"),
        .name = "KINGDRA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BAGON] = {
        .mainSeriesIndexNumber = 395,
        .nameJapanese = __("タツベイ　"),
        .name = "BAGON     ",
        .catchIndex = 0,
        .eggIndex = 31,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHELGON
    },
    [SPECIES_SHELGON] = {
        .mainSeriesIndexNumber = 396,
        .nameJapanese = __("コモルー　"),
        .name = "SHELGON   ",
        .catchIndex = 72,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SALAMENCE
    },
    [SPECIES_SALAMENCE] = {
        .mainSeriesIndexNumber = 397,
        .nameJapanese = __("ボーマンダ"),
        .name = "SALAMENCE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELDUM] = {
        .mainSeriesIndexNumber = 398,
        .nameJapanese = __("ダンバル　"),
        .name = "BELDUM    ",
        .catchIndex = 73,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METANG
    },
    [SPECIES_METANG] = {
        .mainSeriesIndexNumber = 399,
        .nameJapanese = __("メタング　"),
        .name = "METANG    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METAGROSS
    },
    [SPECIES_METAGROSS] = {
        .mainSeriesIndexNumber = 400,
        .nameJapanese = __("メタグロス"),
        .name = "METAGROSS ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGIROCK] = {
        .mainSeriesIndexNumber = 401,
        .nameJapanese = __("レジロック"),
        .name = "REGIROCK  ",
        .catchIndex = 74,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGICE] = {
        .mainSeriesIndexNumber = 402,
        .nameJapanese = __("レジアイス"),
        .name = "REGICE    ",
        .catchIndex = 75,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGISTEEL] = {
        .mainSeriesIndexNumber = 403,
        .nameJapanese = __("レジスチル"),
        .name = "REGISTEEL ",
        .catchIndex = 76,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIAS] = {
        .mainSeriesIndexNumber = 407,
        .nameJapanese = __("ラティアス"),
        .name = "LATIAS    ",
        .catchIndex = 77,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIOS] = {
        .mainSeriesIndexNumber = 408,
        .nameJapanese = __("ラティオス"),
        .name = "LATIOS    ",
        .catchIndex = 78,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KYOGRE] = {
        .mainSeriesIndexNumber = 404,
        .nameJapanese = __("カイオーガ"),
        .name = "KYOGRE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GROUDON] = {
        .mainSeriesIndexNumber = 405,
        .nameJapanese = __("グラードン"),
        .name = "GROUDON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RAYQUAZA] = {
        .mainSeriesIndexNumber = 406,
        .nameJapanese = __("レックウザ"),
        .name = "RAYQUAZA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_JIRACHI] = {
        .mainSeriesIndexNumber = 409,
        .nameJapanese = __("ジラーチ　"),
        .name = "JIRACHI   ",
        .catchIndex = 79,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIKORITA] = {
        .mainSeriesIndexNumber = 152,
        .nameJapanese = __("チコリータ"),
        .name = "CHIKORITA ",
        .catchIndex = 80,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CYNDAQUIL] = {
        .mainSeriesIndexNumber = 155,
        .nameJapanese = __("ヒノアラシ"),
        .name = "CYNDAQUIL ",
        .catchIndex = 81,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TOTODILE] = {
        .mainSeriesIndexNumber = 158,
        .nameJapanese = __("ワニノコ　"),
        .name = "TOTODILE  ",
        .catchIndex = 82,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AERODACTYL] = {
        .mainSeriesIndexNumber = 142,
        .nameJapanese = __("プテラ　　"),
        .name = "AERODACTYL",
        .catchIndex = 83,
        .eggIndex = 0,
        .unk13 = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
};
