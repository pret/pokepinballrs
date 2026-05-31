#include "constants/species.h"
#include "types.h"

const struct PokemonSpecies gSpeciesInfo[NUM_SPECIES] = {
    [SPECIES_TREECKO] = {
        .speciesIdRS = 277,
        .nameJapanese = __("キモリ　　"),
        .name = "TREECKO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GROVYLE
    },
    [SPECIES_GROVYLE] = {
        .speciesIdRS = 278,
        .nameJapanese = __("ジュプトル"),
        .name = "GROVYLE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SCEPTILE
    },
    [SPECIES_SCEPTILE] = {
        .speciesIdRS = 279,
        .nameJapanese = __("ジュカイン"),
        .name = "SCEPTILE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORCHIC] = {
        .speciesIdRS = 280,
        .nameJapanese = __("アチャモ　"),
        .name = "TORCHIC   ",
        .catchIndex = 1,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_COMBUSKEN
    },
    [SPECIES_COMBUSKEN] = {
        .speciesIdRS = 281,
        .nameJapanese = __("ワカシャモ"),
        .name = "COMBUSKEN ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BLAZIKEN
    },
    [SPECIES_BLAZIKEN] = {
        .speciesIdRS = 282,
        .nameJapanese = __("バシャーモ"),
        .name = "BLAZIKEN  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MUDKIP] = {
        .speciesIdRS = 283,
        .nameJapanese = __("ミズゴロウ"),
        .name = "MUDKIP    ",
        .catchIndex = 2,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MARSHTOMP
    },
    [SPECIES_MARSHTOMP] = {
        .speciesIdRS = 284,
        .nameJapanese = __("ヌマクロー"),
        .name = "MARSHTOMP ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWAMPERT
    },
    [SPECIES_SWAMPERT] = {
        .speciesIdRS = 285,
        .nameJapanese = __("ラグラージ"),
        .name = "SWAMPERT  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_POOCHYENA] = {
        .speciesIdRS = 286,
        .nameJapanese = __("ポチエナ　"),
        .name = "POOCHYENA ",
        .catchIndex = 3,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MIGHTYENA
    },
    [SPECIES_MIGHTYENA] = {
        .speciesIdRS = 287,
        .nameJapanese = __("グラエナ　"),
        .name = "MIGHTYENA ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZIGZAGOON] = {
        .speciesIdRS = 288,
        .nameJapanese = __("ジグザグマ"),
        .name = "ZIGZAGOON ",
        .catchIndex = 4,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LINOONE
    },
    [SPECIES_LINOONE] = {
        .speciesIdRS = 289,
        .nameJapanese = __("マッスグマ"),
        .name = "LINOONE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WURMPLE] = {
        .speciesIdRS = 290,
        .nameJapanese = __("ケムッソ　"),
        .name = "WURMPLE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_SILCOON
    },
    [SPECIES_SILCOON] = {
        .speciesIdRS = 291,
        .nameJapanese = __("カラサリス"),
        .name = "SILCOON   ",
        .catchIndex = 5,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BEAUTIFLY
    },
    [SPECIES_BEAUTIFLY] = {
        .speciesIdRS = 292,
        .nameJapanese = __("アゲハント"),
        .name = "BEAUTIFLY ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASCOON] = {
        .speciesIdRS = 293,
        .nameJapanese = __("マユルド　"),
        .name = "CASCOON   ",
        .catchIndex = 6,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSTOX
    },
    [SPECIES_DUSTOX] = {
        .speciesIdRS = 294,
        .nameJapanese = __("ドクケイル"),
        .name = "DUSTOX    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LOTAD] = {
        .speciesIdRS = 295,
        .nameJapanese = __("ハスボー　"),
        .name = "LOTAD     ",
        .catchIndex = 0,
        .eggIndex = 1,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOMBRE
    },
    [SPECIES_LOMBRE] = {
        .speciesIdRS = 296,
        .nameJapanese = __("ハスブレロ"),
        .name = "LOMBRE    ",
        .catchIndex = 7,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_LUDICOLO
    },
    [SPECIES_LUDICOLO] = {
        .speciesIdRS = 297,
        .nameJapanese = __("ルンパッパ"),
        .name = "LUDICOLO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEEDOT] = {
        .speciesIdRS = 298,
        .nameJapanese = __("タネボー　"),
        .name = "SEEDOT    ",
        .catchIndex = 0,
        .eggIndex = 2,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NUZLEAF
    },
    [SPECIES_NUZLEAF] = {
        .speciesIdRS = 299,
        .nameJapanese = __("コノハナ　"),
        .name = "NUZLEAF   ",
        .catchIndex = 8,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 2,
        .evolutionTarget = SPECIES_SHIFTRY
    },
    [SPECIES_SHIFTRY] = {
        .speciesIdRS = 300,
        .nameJapanese = __("ダーテング"),
        .name = "SHIFTRY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TAILLOW] = {
        .speciesIdRS = 304,
        .nameJapanese = __("スバメ　　"),
        .name = "TAILLOW   ",
        .catchIndex = 9,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWELLOW
    },
    [SPECIES_SWELLOW] = {
        .speciesIdRS = 305,
        .nameJapanese = __("オオスバメ"),
        .name = "SWELLOW   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WINGULL] = {
        .speciesIdRS = 309,
        .nameJapanese = __("キャモメ　"),
        .name = "WINGULL   ",
        .catchIndex = 10,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PELIPPER
    },
    [SPECIES_PELIPPER] = {
        .speciesIdRS = 310,
        .nameJapanese = __("ペリッパー"),
        .name = "PELIPPER  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RALTS] = {
        .speciesIdRS = 392,
        .nameJapanese = __("ラルトス　"),
        .name = "RALTS     ",
        .catchIndex = 0,
        .eggIndex = 3,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KIRLIA
    },
    [SPECIES_KIRLIA] = {
        .speciesIdRS = 393,
        .nameJapanese = __("キルリア　"),
        .name = "KIRLIA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GARDEVOIR
    },
    [SPECIES_GARDEVOIR] = {
        .speciesIdRS = 394,
        .nameJapanese = __("サーナイト"),
        .name = "GARDEVOIR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SURSKIT] = {
        .speciesIdRS = 311,
        .nameJapanese = __("アメタマ　"),
        .name = "SURSKIT   ",
        .catchIndex = 0,
        .eggIndex = 4,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MASQUERAIN
    },
    [SPECIES_MASQUERAIN] = {
        .speciesIdRS = 312,
        .nameJapanese = __("アメモース"),
        .name = "MASQUERAIN",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHROOMISH] = {
        .speciesIdRS = 306,
        .nameJapanese = __("キノココ　"),
        .name = "SHROOMISH ",
        .catchIndex = 0,
        .eggIndex = 5,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BRELOOM
    },
    [SPECIES_BRELOOM] = {
        .speciesIdRS = 307,
        .nameJapanese = __("キノガッサ"),
        .name = "BRELOOM   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLAKOTH] = {
        .speciesIdRS = 364,
        .nameJapanese = __("ナマケロ　"),
        .name = "SLAKOTH   ",
        .catchIndex = 11,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIGOROTH
    },
    [SPECIES_VIGOROTH] = {
        .speciesIdRS = 365,
        .nameJapanese = __("ヤルキモノ"),
        .name = "VIGOROTH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SLAKING
    },
    [SPECIES_SLAKING] = {
        .speciesIdRS = 366,
        .nameJapanese = __("ケッキング"),
        .name = "SLAKING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABRA] = {
        .speciesIdRS = 63,
        .nameJapanese = __("ケーシィ　"),
        .name = "ABRA      ",
        .catchIndex = 12,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KADABRA
    },
    [SPECIES_KADABRA] = {
        .speciesIdRS = 64,
        .nameJapanese = __("ユンゲラー"),
        .name = "KADABRA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_ALAKAZAM
    },
    [SPECIES_ALAKAZAM] = {
        .speciesIdRS = 65,
        .nameJapanese = __("フーディン"),
        .name = "ALAKAZAM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NINCADA] = {
        .speciesIdRS = 301,
        .nameJapanese = __("ツチニン　"),
        .name = "NINCADA   ",
        .catchIndex = 13,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NINJASK
    },
    [SPECIES_NINJASK] = {
        .speciesIdRS = 302,
        .nameJapanese = __("テッカニン"),
        .name = "NINJASK   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHEDINJA] = {
        .speciesIdRS = 303,
        .nameJapanese = __("ヌケニン　"),
        .name = "SHEDINJA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WHISMUR] = {
        .speciesIdRS = 370,
        .nameJapanese = __("ゴニョニョ"),
        .name = "WHISMUR   ",
        .catchIndex = 0,
        .eggIndex = 6,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOUDRED
    },
    [SPECIES_LOUDRED] = {
        .speciesIdRS = 371,
        .nameJapanese = __("ドゴーム　"),
        .name = "LOUDRED   ",
        .catchIndex = 14,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_EXPLOUD
    },
    [SPECIES_EXPLOUD] = {
        .speciesIdRS = 372,
        .nameJapanese = __("バクオング"),
        .name = "EXPLOUD   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAKUHITA] = {
        .speciesIdRS = 335,
        .nameJapanese = __("マクノシタ"),
        .name = "MAKUHITA  ",
        .catchIndex = 15,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HARIYAMA
    },
    [SPECIES_HARIYAMA] = {
        .speciesIdRS = 336,
        .nameJapanese = __("ハリテヤマ"),
        .name = "HARIYAMA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOLDEEN] = {
        .speciesIdRS = 118,
        .nameJapanese = __("トサキント"),
        .name = "GOLDEEN   ",
        .catchIndex = 16,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEAKING
    },
    [SPECIES_SEAKING] = {
        .speciesIdRS = 119,
        .nameJapanese = __("アズマオウ"),
        .name = "SEAKING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGIKARP] = {
        .speciesIdRS = 129,
        .nameJapanese = __("コイキング"),
        .name = "MAGIKARP  ",
        .catchIndex = 17,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GYARADOS
    },
    [SPECIES_GYARADOS] = {
        .speciesIdRS = 130,
        .nameJapanese = __("ギャラドス"),
        .name = "GYARADOS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AZURILL] = {
        .speciesIdRS = 350,
        .nameJapanese = __("ルリリ　　"),
        .name = "AZURILL   ",
        .catchIndex = 0,
        .eggIndex = 7,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_MARILL
    },
    [SPECIES_MARILL] = {
        .speciesIdRS = 183,
        .nameJapanese = __("マリル　　"),
        .name = "MARILL    ",
        .catchIndex = 18,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AZUMARILL
    },
    [SPECIES_AZUMARILL] = {
        .speciesIdRS = 184,
        .nameJapanese = __("マリルリ　"),
        .name = "AZUMARILL ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GEODUDE] = {
        .speciesIdRS = 74,
        .nameJapanese = __("イシツブテ"),
        .name = "GEODUDE   ",
        .catchIndex = 19,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRAVELER
    },
    [SPECIES_GRAVELER] = {
        .speciesIdRS = 75,
        .nameJapanese = __("ゴローン　"),
        .name = "GRAVELER  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_GOLEM
    },
    [SPECIES_GOLEM] = {
        .speciesIdRS = 76,
        .nameJapanese = __("ゴローニャ"),
        .name = "GOLEM     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NOSEPASS] = {
        .speciesIdRS = 320,
        .nameJapanese = __("ノズパス　"),
        .name = "NOSEPASS  ",
        .catchIndex = 20,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKITTY] = {
        .speciesIdRS = 315,
        .nameJapanese = __("エネコ　　"),
        .name = "SKITTY    ",
        .catchIndex = 0,
        .eggIndex = 8,
        .specialEggFlag = 1,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_DELCATTY
    },
    [SPECIES_DELCATTY] = {
        .speciesIdRS = 316,
        .nameJapanese = __("エネコロロ"),
        .name = "DELCATTY  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZUBAT] = {
        .speciesIdRS = 41,
        .nameJapanese = __("ズバット　"),
        .name = "ZUBAT     ",
        .catchIndex = 0,
        .eggIndex = 9,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLBAT
    },
    [SPECIES_GOLBAT] = {
        .speciesIdRS = 42,
        .nameJapanese = __("ゴルバット"),
        .name = "GOLBAT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_CROBAT
    },
    [SPECIES_CROBAT] = {
        .speciesIdRS = 169,
        .nameJapanese = __("クロバット"),
        .name = "CROBAT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TENTACOOL] = {
        .speciesIdRS = 72,
        .nameJapanese = __("メノクラゲ"),
        .name = "TENTACOOL ",
        .catchIndex = 21,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TENTACRUEL
    },
    [SPECIES_TENTACRUEL] = {
        .speciesIdRS = 73,
        .nameJapanese = __("ドククラゲ"),
        .name = "TENTACRUEL",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SABLEYE] = {
        .speciesIdRS = 322,
        .nameJapanese = __("ヤミラミ　"),
        .name = "SABLEYE   ",
        .catchIndex = 22,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAWILE] = {
        .speciesIdRS = 355,
        .nameJapanese = __("クチート　"),
        .name = "MAWILE    ",
        .catchIndex = 23,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ARON] = {
        .speciesIdRS = 382,
        .nameJapanese = __("ココドラ　"),
        .name = "ARON      ",
        .catchIndex = 0,
        .eggIndex = 10,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LAIRON
    },
    [SPECIES_LAIRON] = {
        .speciesIdRS = 383,
        .nameJapanese = __("コドラ　　"),
        .name = "LAIRON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AGGRON
    },
    [SPECIES_AGGRON] = {
        .speciesIdRS = 384,
        .nameJapanese = __("ボスゴドラ"),
        .name = "AGGRON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MACHOP] = {
        .speciesIdRS = 66,
        .nameJapanese = __("ワンリキー"),
        .name = "MACHOP    ",
        .catchIndex = 24,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MACHOKE
    },
    [SPECIES_MACHOKE] = {
        .speciesIdRS = 67,
        .nameJapanese = __("ゴーリキー"),
        .name = "MACHOKE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_MACHAMP
    },
    [SPECIES_MACHAMP] = {
        .speciesIdRS = 68,
        .nameJapanese = __("カイリキー"),
        .name = "MACHAMP   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEDITITE] = {
        .speciesIdRS = 356,
        .nameJapanese = __("アサナン　"),
        .name = "MEDITITE  ",
        .catchIndex = 25,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MEDICHAM
    },
    [SPECIES_MEDICHAM] = {
        .speciesIdRS = 357,
        .nameJapanese = __("チャーレム"),
        .name = "MEDICHAM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ELECTRIKE] = {
        .speciesIdRS = 337,
        .nameJapanese = __("ラクライ　"),
        .name = "ELECTRIKE ",
        .catchIndex = 26,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MANECTRIC
    },
    [SPECIES_MANECTRIC] = {
        .speciesIdRS = 338,
        .nameJapanese = __("ライボルト"),
        .name = "MANECTRIC ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PLUSLE] = {
        .speciesIdRS = 353,
        .nameJapanese = __("プラスル　"),
        .name = "PLUSLE    ",
        .catchIndex = 0,
        .eggIndex = 11,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MINUN] = {
        .speciesIdRS = 354,
        .nameJapanese = __("マイナン　"),
        .name = "MINUN     ",
        .catchIndex = 0,
        .eggIndex = 12,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGNEMITE] = {
        .speciesIdRS = 81,
        .nameJapanese = __("コイル　　"),
        .name = "MAGNEMITE ",
        .catchIndex = 27,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGNETON
    },
    [SPECIES_MAGNETON] = {
        .speciesIdRS = 82,
        .nameJapanese = __("レアコイル"),
        .name = "MAGNETON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLTORB] = {
        .speciesIdRS = 100,
        .nameJapanese = __("ビリリダマ"),
        .name = "VOLTORB   ",
        .catchIndex = 28,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ELECTRODE
    },
    [SPECIES_ELECTRODE] = {
        .speciesIdRS = 101,
        .nameJapanese = __("マルマイン"),
        .name = "ELECTRODE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLBEAT] = {
        .speciesIdRS = 386,
        .nameJapanese = __("バルビート"),
        .name = "VOLBEAT   ",
        .catchIndex = 29,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ILLUMISE] = {
        .speciesIdRS = 387,
        .nameJapanese = __("イルミーゼ"),
        .name = "ILLUMISE  ",
        .catchIndex = 30,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ODDISH] = {
        .speciesIdRS = 43,
        .nameJapanese = __("ナゾノクサ"),
        .name = "ODDISH    ",
        .catchIndex = 0,
        .eggIndex = 13,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLOOM
    },
    [SPECIES_GLOOM] = {
        .speciesIdRS = 44,
        .nameJapanese = __("クサイハナ"),
        .name = "GLOOM     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_VILEPLUME
    },
    [SPECIES_VILEPLUME] = {
        .speciesIdRS = 45,
        .nameJapanese = __("ラフレシア"),
        .name = "VILEPLUME ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELLOSSOM] = {
        .speciesIdRS = 182,
        .nameJapanese = __("キレイハナ"),
        .name = "BELLOSSOM ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DODUO] = {
        .speciesIdRS = 84,
        .nameJapanese = __("ドードー　"),
        .name = "DODUO     ",
        .catchIndex = 31,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DODRIO
    },
    [SPECIES_DODRIO] = {
        .speciesIdRS = 85,
        .nameJapanese = __("ドードリオ"),
        .name = "DODRIO    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ROSELIA] = {
        .speciesIdRS = 363,
        .nameJapanese = __("ロゼリア　"),
        .name = "ROSELIA   ",
        .catchIndex = 32,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GULPIN] = {
        .speciesIdRS = 367,
        .nameJapanese = __("ゴクリン　"),
        .name = "GULPIN    ",
        .catchIndex = 0,
        .eggIndex = 14,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWALOT
    },
    [SPECIES_SWALOT] = {
        .speciesIdRS = 368,
        .nameJapanese = __("マルノーム"),
        .name = "SWALOT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CARVANHA] = {
        .speciesIdRS = 330,
        .nameJapanese = __("キバニア　"),
        .name = "CARVANHA  ",
        .catchIndex = 33,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHARPEDO
    },
    [SPECIES_SHARPEDO] = {
        .speciesIdRS = 331,
        .nameJapanese = __("サメハダー"),
        .name = "SHARPEDO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WAILMER] = {
        .speciesIdRS = 313,
        .nameJapanese = __("ホエルコ　"),
        .name = "WAILMER   ",
        .catchIndex = 34,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WAILORD
    },
    [SPECIES_WAILORD] = {
        .speciesIdRS = 314,
        .nameJapanese = __("ホエルオー"),
        .name = "WAILORD   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NUMEL] = {
        .speciesIdRS = 339,
        .nameJapanese = __("ドンメル　"),
        .name = "NUMEL     ",
        .catchIndex = 35,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CAMERUPT
    },
    [SPECIES_CAMERUPT] = {
        .speciesIdRS = 340,
        .nameJapanese = __("バクーダ　"),
        .name = "CAMERUPT  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLUGMA] = {
        .speciesIdRS = 218,
        .nameJapanese = __("マグマッグ"),
        .name = "SLUGMA    ",
        .catchIndex = 36,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGCARGO
    },
    [SPECIES_MAGCARGO] = {
        .speciesIdRS = 219,
        .nameJapanese = __("マグカルゴ"),
        .name = "MAGCARGO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORKOAL] = {
        .speciesIdRS = 321,
        .nameJapanese = __("コータス　"),
        .name = "TORKOAL   ",
        .catchIndex = 37,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GRIMER] = {
        .speciesIdRS = 88,
        .nameJapanese = __("ベトベター"),
        .name = "GRIMER    ",
        .catchIndex = 38,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MUK
    },
    [SPECIES_MUK] = {
        .speciesIdRS = 89,
        .nameJapanese = __("ベトベトン"),
        .name = "MUK       ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KOFFING] = {
        .speciesIdRS = 109,
        .nameJapanese = __("ドガース　"),
        .name = "KOFFING   ",
        .catchIndex = 39,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WEEZING
    },
    [SPECIES_WEEZING] = {
        .speciesIdRS = 110,
        .nameJapanese = __("マタドガス"),
        .name = "WEEZING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPOINK] = {
        .speciesIdRS = 351,
        .nameJapanese = __("バネブー　"),
        .name = "SPOINK    ",
        .catchIndex = 0,
        .eggIndex = 15,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRUMPIG
    },
    [SPECIES_GRUMPIG] = {
        .speciesIdRS = 352,
        .nameJapanese = __("ブーピッグ"),
        .name = "GRUMPIG   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SANDSHREW] = {
        .speciesIdRS = 27,
        .nameJapanese = __("サンド　　"),
        .name = "SANDSHREW ",
        .catchIndex = 0,
        .eggIndex = 16,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SANDSLASH
    },
    [SPECIES_SANDSLASH] = {
        .speciesIdRS = 28,
        .nameJapanese = __("サンドパン"),
        .name = "SANDSLASH ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPINDA] = {
        .speciesIdRS = 308,
        .nameJapanese = __("パッチール"),
        .name = "SPINDA    ",
        .catchIndex = 0,
        .eggIndex = 17,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKARMORY] = {
        .speciesIdRS = 227,
        .nameJapanese = __("エアームド"),
        .name = "SKARMORY  ",
        .catchIndex = 40,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TRAPINCH] = {
        .speciesIdRS = 332,
        .nameJapanese = __("ナックラー"),
        .name = "TRAPINCH  ",
        .catchIndex = 0,
        .eggIndex = 18,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIBRAVA
    },
    [SPECIES_VIBRAVA] = {
        .speciesIdRS = 333,
        .nameJapanese = __("ビブラーバ"),
        .name = "VIBRAVA   ",
        .catchIndex = 41,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FLYGON
    },
    [SPECIES_FLYGON] = {
        .speciesIdRS = 334,
        .nameJapanese = __("フライゴン"),
        .name = "FLYGON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CACNEA] = {
        .speciesIdRS = 344,
        .nameJapanese = __("サボネア　"),
        .name = "CACNEA    ",
        .catchIndex = 42,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CACTURNE
    },
    [SPECIES_CACTURNE] = {
        .speciesIdRS = 345,
        .nameJapanese = __("ノクタス　"),
        .name = "CACTURNE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SWABLU] = {
        .speciesIdRS = 358,
        .nameJapanese = __("チルット　"),
        .name = "SWABLU    ",
        .catchIndex = 43,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ALTARIA
    },
    [SPECIES_ALTARIA] = {
        .speciesIdRS = 359,
        .nameJapanese = __("チルタリス"),
        .name = "ALTARIA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZANGOOSE] = {
        .speciesIdRS = 380,
        .nameJapanese = __("ザングース"),
        .name = "ZANGOOSE  ",
        .catchIndex = 44,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEVIPER] = {
        .speciesIdRS = 379,
        .nameJapanese = __("ハブネーク"),
        .name = "SEVIPER   ",
        .catchIndex = 45,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUNATONE] = {
        .speciesIdRS = 348,
        .nameJapanese = __("ルナトーン"),
        .name = "LUNATONE  ",
        .catchIndex = 46,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SOLROCK] = {
        .speciesIdRS = 349,
        .nameJapanese = __("ソルロック"),
        .name = "SOLROCK   ",
        .catchIndex = 47,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BARBOACH] = {
        .speciesIdRS = 323,
        .nameJapanese = __("ドジョッチ"),
        .name = "BARBOACH  ",
        .catchIndex = 48,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WHISCASH
    },
    [SPECIES_WHISCASH] = {
        .speciesIdRS = 324,
        .nameJapanese = __("ナマズン　"),
        .name = "WHISCASH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORPHISH] = {
        .speciesIdRS = 326,
        .nameJapanese = __("ヘイガニ　"),
        .name = "CORPHISH  ",
        .catchIndex = 49,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRAWDAUNT
    },
    [SPECIES_CRAWDAUNT] = {
        .speciesIdRS = 327,
        .nameJapanese = __("シザリガー"),
        .name = "CRAWDAUNT ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BALTOY] = {
        .speciesIdRS = 318,
        .nameJapanese = __("ヤジロン　"),
        .name = "BALTOY    ",
        .catchIndex = 50,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CLAYDOL
    },
    [SPECIES_CLAYDOL] = {
        .speciesIdRS = 319,
        .nameJapanese = __("ネンドール"),
        .name = "CLAYDOL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LILEEP] = {
        .speciesIdRS = 388,
        .nameJapanese = __("リリーラ　"),
        .name = "LILEEP    ",
        .catchIndex = 51,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRADILY
    },
    [SPECIES_CRADILY] = {
        .speciesIdRS = 389,
        .nameJapanese = __("ユレイドル"),
        .name = "CRADILY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ANORITH] = {
        .speciesIdRS = 390,
        .nameJapanese = __("アノプス　"),
        .name = "ANORITH   ",
        .catchIndex = 52,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ARMALDO
    },
    [SPECIES_ARMALDO] = {
        .speciesIdRS = 391,
        .nameJapanese = __("アーマルド"),
        .name = "ARMALDO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_IGGLYBUFF] = {
        .speciesIdRS = 174,
        .nameJapanese = __("ププリン　"),
        .name = "IGGLYBUFF ",
        .catchIndex = 0,
        .eggIndex = 19,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_JIGGLYPUFF
    },
    [SPECIES_JIGGLYPUFF] = {
        .speciesIdRS = 39,
        .nameJapanese = __("プリン　　"),
        .name = "JIGGLYPUFF",
        .catchIndex = 53,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_WIGGLYTUFF
    },
    [SPECIES_WIGGLYTUFF] = {
        .speciesIdRS = 40,
        .nameJapanese = __("プクリン　"),
        .name = "WIGGLYTUFF",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FEEBAS] = {
        .speciesIdRS = 328,
        .nameJapanese = __("ヒンバス　"),
        .name = "FEEBAS    ",
        .catchIndex = 54,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 10,
        .evolutionTarget = SPECIES_MILOTIC
    },
    [SPECIES_MILOTIC] = {
        .speciesIdRS = 329,
        .nameJapanese = __("ミロカロス"),
        .name = "MILOTIC   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASTFORM] = {
        .speciesIdRS = 385,
        .nameJapanese = __("ポワルン　"),
        .name = "CASTFORM  ",
        .catchIndex = 55,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_STARYU] = {
        .speciesIdRS = 120,
        .nameJapanese = __("ヒトデマン"),
        .name = "STARYU    ",
        .catchIndex = 56,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_STARMIE
    },
    [SPECIES_STARMIE] = {
        .speciesIdRS = 121,
        .nameJapanese = __("スターミー"),
        .name = "STARMIE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KECLEON] = {
        .speciesIdRS = 317,
        .nameJapanese = __("カクレオン"),
        .name = "KECLEON   ",
        .catchIndex = 57,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHUPPET] = {
        .speciesIdRS = 377,
        .nameJapanese = __("カゲボウズ"),
        .name = "SHUPPET   ",
        .catchIndex = 0,
        .eggIndex = 20,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BANETTE
    },
    [SPECIES_BANETTE] = {
        .speciesIdRS = 378,
        .nameJapanese = __("ジュペッタ"),
        .name = "BANETTE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DUSKULL] = {
        .speciesIdRS = 361,
        .nameJapanese = __("ヨマワル　"),
        .name = "DUSKULL   ",
        .catchIndex = 58,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSCLOPS
    },
    [SPECIES_DUSCLOPS] = {
        .speciesIdRS = 362,
        .nameJapanese = __("サマヨール"),
        .name = "DUSCLOPS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TROPIUS] = {
        .speciesIdRS = 369,
        .nameJapanese = __("トロピウス"),
        .name = "TROPIUS   ",
        .catchIndex = 59,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIMECHO] = {
        .speciesIdRS = 411,
        .nameJapanese = __("チリーン　"),
        .name = "CHIMECHO  ",
        .catchIndex = 0,
        .eggIndex = 21,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABSOL] = {
        .speciesIdRS = 376,
        .nameJapanese = __("アブソル　"),
        .name = "ABSOL     ",
        .catchIndex = 60,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VULPIX] = {
        .speciesIdRS = 37,
        .nameJapanese = __("ロコン　　"),
        .name = "VULPIX    ",
        .catchIndex = 61,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 3,
        .evolutionTarget = SPECIES_NINETALES
    },
    [SPECIES_NINETALES] = {
        .speciesIdRS = 38,
        .nameJapanese = __("キュウコン"),
        .name = "NINETALES ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PICHU] = {
        .speciesIdRS = 172,
        .nameJapanese = __("ピチュー　"),
        .name = "PICHU     ",
        .catchIndex = 0,
        .eggIndex = 22,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_PIKACHU
    },
    [SPECIES_PIKACHU] = {
        .speciesIdRS = 25,
        .nameJapanese = __("ピカチュウ"),
        .name = "PIKACHU   ",
        .catchIndex = 62,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 7,
        .evolutionTarget = SPECIES_RAICHU
    },
    [SPECIES_RAICHU] = {
        .speciesIdRS = 26,
        .nameJapanese = __("ライチュウ"),
        .name = "RAICHU    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PSYDUCK] = {
        .speciesIdRS = 54,
        .nameJapanese = __("コダック　"),
        .name = "PSYDUCK   ",
        .catchIndex = 63,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLDUCK
    },
    [SPECIES_GOLDUCK] = {
        .speciesIdRS = 55,
        .nameJapanese = __("ゴルダック"),
        .name = "GOLDUCK   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WYNAUT] = {
        .speciesIdRS = 360,
        .nameJapanese = __("ソーナノ　"),
        .name = "WYNAUT    ",
        .catchIndex = 0,
        .eggIndex = 23,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WOBBUFFET
    },
    [SPECIES_WOBBUFFET] = {
        .speciesIdRS = 202,
        .nameJapanese = __("ソーナンス"),
        .name = "WOBBUFFET ",
        .catchIndex = 64,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NATU] = {
        .speciesIdRS = 177,
        .nameJapanese = __("ネイティ　"),
        .name = "NATU      ",
        .catchIndex = 0,
        .eggIndex = 24,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_XATU
    },
    [SPECIES_XATU] = {
        .speciesIdRS = 178,
        .nameJapanese = __("ネイティオ"),
        .name = "XATU      ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GIRAFARIG] = {
        .speciesIdRS = 203,
        .nameJapanese = __("キリンリキ"),
        .name = "GIRAFARIG ",
        .catchIndex = 65,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PHANPY] = {
        .speciesIdRS = 231,
        .nameJapanese = __("ゴマゾウ　"),
        .name = "PHANPY    ",
        .catchIndex = 0,
        .eggIndex = 25,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DONPHAN
    },
    [SPECIES_DONPHAN] = {
        .speciesIdRS = 232,
        .nameJapanese = __("ドンファン"),
        .name = "DONPHAN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PINSIR] = {
        .speciesIdRS = 127,
        .nameJapanese = __("カイロス　"),
        .name = "PINSIR    ",
        .catchIndex = 66,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HERACROSS] = {
        .speciesIdRS = 214,
        .nameJapanese = __("ヘラクロス"),
        .name = "HERACROSS ",
        .catchIndex = 67,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RHYHORN] = {
        .speciesIdRS = 111,
        .nameJapanese = __("サイホーン"),
        .name = "RHYHORN   ",
        .catchIndex = 68,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RHYDON
    },
    [SPECIES_RHYDON] = {
        .speciesIdRS = 112,
        .nameJapanese = __("サイドン　"),
        .name = "RHYDON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SNORUNT] = {
        .speciesIdRS = 346,
        .nameJapanese = __("ユキワラシ"),
        .name = "SNORUNT   ",
        .catchIndex = 0,
        .eggIndex = 26,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLALIE
    },
    [SPECIES_GLALIE] = {
        .speciesIdRS = 347,
        .nameJapanese = __("オニゴーリ"),
        .name = "GLALIE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPHEAL] = {
        .speciesIdRS = 341,
        .nameJapanese = __("タマザラシ"),
        .name = "SPHEAL    ",
        .catchIndex = 0,
        .eggIndex = 27,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEALEO
    },
    [SPECIES_SEALEO] = {
        .speciesIdRS = 342,
        .nameJapanese = __("トドグラー"),
        .name = "SEALEO    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WALREIN
    },
    [SPECIES_WALREIN] = {
        .speciesIdRS = 343,
        .nameJapanese = __("トドゼルガ"),
        .name = "WALREIN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CLAMPERL] = {
        .speciesIdRS = 373,
        .nameJapanese = __("パールル　"),
        .name = "CLAMPERL  ",
        .catchIndex = 69,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_HUNTAIL
    },
    [SPECIES_HUNTAIL] = {
        .speciesIdRS = 374,
        .nameJapanese = __("ハンテール"),
        .name = "HUNTAIL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOREBYSS] = {
        .speciesIdRS = 375,
        .nameJapanese = __("サクラビス"),
        .name = "GOREBYSS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RELICANTH] = {
        .speciesIdRS = 381,
        .nameJapanese = __("ジーランス"),
        .name = "RELICANTH ",
        .catchIndex = 70,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORSOLA] = {
        .speciesIdRS = 222,
        .nameJapanese = __("サニーゴ　"),
        .name = "CORSOLA   ",
        .catchIndex = 0,
        .eggIndex = 28,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHINCHOU] = {
        .speciesIdRS = 170,
        .nameJapanese = __("チョンチー"),
        .name = "CHINCHOU  ",
        .catchIndex = 0,
        .eggIndex = 29,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LANTURN
    },
    [SPECIES_LANTURN] = {
        .speciesIdRS = 171,
        .nameJapanese = __("ランターン"),
        .name = "LANTURN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUVDISC] = {
        .speciesIdRS = 325,
        .nameJapanese = __("ラブカス　"),
        .name = "LUVDISC   ",
        .catchIndex = 71,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HORSEA] = {
        .speciesIdRS = 116,
        .nameJapanese = __("タッツー　"),
        .name = "HORSEA    ",
        .catchIndex = 0,
        .eggIndex = 30,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEADRA
    },
    [SPECIES_SEADRA] = {
        .speciesIdRS = 117,
        .nameJapanese = __("シードラ　"),
        .name = "SEADRA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_KINGDRA
    },
    [SPECIES_KINGDRA] = {
        .speciesIdRS = 230,
        .nameJapanese = __("キングドラ"),
        .name = "KINGDRA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BAGON] = {
        .speciesIdRS = 395,
        .nameJapanese = __("タツベイ　"),
        .name = "BAGON     ",
        .catchIndex = 0,
        .eggIndex = 31,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHELGON
    },
    [SPECIES_SHELGON] = {
        .speciesIdRS = 396,
        .nameJapanese = __("コモルー　"),
        .name = "SHELGON   ",
        .catchIndex = 72,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SALAMENCE
    },
    [SPECIES_SALAMENCE] = {
        .speciesIdRS = 397,
        .nameJapanese = __("ボーマンダ"),
        .name = "SALAMENCE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELDUM] = {
        .speciesIdRS = 398,
        .nameJapanese = __("ダンバル　"),
        .name = "BELDUM    ",
        .catchIndex = 73,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METANG
    },
    [SPECIES_METANG] = {
        .speciesIdRS = 399,
        .nameJapanese = __("メタング　"),
        .name = "METANG    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METAGROSS
    },
    [SPECIES_METAGROSS] = {
        .speciesIdRS = 400,
        .nameJapanese = __("メタグロス"),
        .name = "METAGROSS ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGIROCK] = {
        .speciesIdRS = 401,
        .nameJapanese = __("レジロック"),
        .name = "REGIROCK  ",
        .catchIndex = 74,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGICE] = {
        .speciesIdRS = 402,
        .nameJapanese = __("レジアイス"),
        .name = "REGICE    ",
        .catchIndex = 75,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGISTEEL] = {
        .speciesIdRS = 403,
        .nameJapanese = __("レジスチル"),
        .name = "REGISTEEL ",
        .catchIndex = 76,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIAS] = {
        .speciesIdRS = 407,
        .nameJapanese = __("ラティアス"),
        .name = "LATIAS    ",
        .catchIndex = 77,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIOS] = {
        .speciesIdRS = 408,
        .nameJapanese = __("ラティオス"),
        .name = "LATIOS    ",
        .catchIndex = 78,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KYOGRE] = {
        .speciesIdRS = 404,
        .nameJapanese = __("カイオーガ"),
        .name = "KYOGRE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GROUDON] = {
        .speciesIdRS = 405,
        .nameJapanese = __("グラードン"),
        .name = "GROUDON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RAYQUAZA] = {
        .speciesIdRS = 406,
        .nameJapanese = __("レックウザ"),
        .name = "RAYQUAZA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_JIRACHI] = {
        .speciesIdRS = 409,
        .nameJapanese = __("ジラーチ　"),
        .name = "JIRACHI   ",
        .catchIndex = 79,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIKORITA] = {
        .speciesIdRS = 152,
        .nameJapanese = __("チコリータ"),
        .name = "CHIKORITA ",
        .catchIndex = 80,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CYNDAQUIL] = {
        .speciesIdRS = 155,
        .nameJapanese = __("ヒノアラシ"),
        .name = "CYNDAQUIL ",
        .catchIndex = 81,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TOTODILE] = {
        .speciesIdRS = 158,
        .nameJapanese = __("ワニノコ　"),
        .name = "TOTODILE  ",
        .catchIndex = 82,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AERODACTYL] = {
        .speciesIdRS = 142,
        .nameJapanese = __("プテラ　　"),
        .name = "AERODACTYL",
        .catchIndex = 83,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
};
