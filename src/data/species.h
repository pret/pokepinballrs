#include "constants/species.h"
#include "types.h"

// The European version stores three spellings of each name:
// English (also used for Italian and Spanish), French and German.
#ifdef EUROPE
#define SPECIES_NAME(en, fr, de) { en, fr, de }
#else
#define SPECIES_NAME(en, fr, de) en
#endif

const struct PokemonSpecies gSpeciesInfo[NUM_SPECIES] = {
    [SPECIES_TREECKO] = {
        .speciesIdRS = 277,
        .nameJapanese = __("キモリ　　"),
        .name = SPECIES_NAME("TREECKO   ", "ARCKO     ", "GECKARBOR "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GROVYLE
    },
    [SPECIES_GROVYLE] = {
        .speciesIdRS = 278,
        .nameJapanese = __("ジュプトル"),
        .name = SPECIES_NAME("GROVYLE   ", "MASSKO    ", "REPTAIN   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SCEPTILE
    },
    [SPECIES_SCEPTILE] = {
        .speciesIdRS = 279,
        .nameJapanese = __("ジュカイン"),
        .name = SPECIES_NAME("SCEPTILE  ", "JUNGKO    ", "GEWALDRO  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORCHIC] = {
        .speciesIdRS = 280,
        .nameJapanese = __("アチャモ　"),
        .name = SPECIES_NAME("TORCHIC   ", "POUSSIFEU ", "FLEMMLI   "),
        .catchIndex = 1,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_COMBUSKEN
    },
    [SPECIES_COMBUSKEN] = {
        .speciesIdRS = 281,
        .nameJapanese = __("ワカシャモ"),
        .name = SPECIES_NAME("COMBUSKEN ", "GALIFEU   ", "JUNGGLUT  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BLAZIKEN
    },
    [SPECIES_BLAZIKEN] = {
        .speciesIdRS = 282,
        .nameJapanese = __("バシャーモ"),
        .name = SPECIES_NAME("BLAZIKEN  ", "BRASEGALI ", "LOHGOCK   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MUDKIP] = {
        .speciesIdRS = 283,
        .nameJapanese = __("ミズゴロウ"),
        .name = SPECIES_NAME("MUDKIP    ", "GOBOU     ", "HYDROPI   "),
        .catchIndex = 2,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MARSHTOMP
    },
    [SPECIES_MARSHTOMP] = {
        .speciesIdRS = 284,
        .nameJapanese = __("ヌマクロー"),
        .name = SPECIES_NAME("MARSHTOMP ", "FLOBIO    ", "MOORABBEL "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWAMPERT
    },
    [SPECIES_SWAMPERT] = {
        .speciesIdRS = 285,
        .nameJapanese = __("ラグラージ"),
        .name = SPECIES_NAME("SWAMPERT  ", "LAGGRON   ", "SUMPEX    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_POOCHYENA] = {
        .speciesIdRS = 286,
        .nameJapanese = __("ポチエナ　"),
        .name = SPECIES_NAME("POOCHYENA ", "MEDHYENA  ", "FIFFYEN   "),
        .catchIndex = 3,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MIGHTYENA
    },
    [SPECIES_MIGHTYENA] = {
        .speciesIdRS = 287,
        .nameJapanese = __("グラエナ　"),
        .name = SPECIES_NAME("MIGHTYENA ", "GRAHYENA  ", "MAGNAYEN  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZIGZAGOON] = {
        .speciesIdRS = 288,
        .nameJapanese = __("ジグザグマ"),
        .name = SPECIES_NAME("ZIGZAGOON ", "ZIGZATON  ", "ZIGZACHS  "),
        .catchIndex = 4,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LINOONE
    },
    [SPECIES_LINOONE] = {
        .speciesIdRS = 289,
        .nameJapanese = __("マッスグマ"),
        .name = SPECIES_NAME("LINOONE   ", "LINEON    ", "GERADAKS  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WURMPLE] = {
        .speciesIdRS = 290,
        .nameJapanese = __("ケムッソ　"),
        .name = SPECIES_NAME("WURMPLE   ", "CHENIPOTTE", "WAUMPEL   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_SILCOON
    },
    [SPECIES_SILCOON] = {
        .speciesIdRS = 291,
        .nameJapanese = __("カラサリス"),
        .name = SPECIES_NAME("SILCOON   ", "ARMULYS   ", "SCHALOKO  "),
        .catchIndex = 5,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BEAUTIFLY
    },
    [SPECIES_BEAUTIFLY] = {
        .speciesIdRS = 292,
        .nameJapanese = __("アゲハント"),
        .name = SPECIES_NAME("BEAUTIFLY ", "CHARMILLON", "PAPINELLA "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASCOON] = {
        .speciesIdRS = 293,
        .nameJapanese = __("マユルド　"),
        .name = SPECIES_NAME("CASCOON   ", "BLINDALYS ", "PANEKON   "),
        .catchIndex = 6,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSTOX
    },
    [SPECIES_DUSTOX] = {
        .speciesIdRS = 294,
        .nameJapanese = __("ドクケイル"),
        .name = SPECIES_NAME("DUSTOX    ", "PAPINOX   ", "PUDOX     "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LOTAD] = {
        .speciesIdRS = 295,
        .nameJapanese = __("ハスボー　"),
        .name = SPECIES_NAME("LOTAD     ", "NENUPIOT  ", "LOTURZEL  "),
        .catchIndex = 0,
        .eggIndex = 1,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOMBRE
    },
    [SPECIES_LOMBRE] = {
        .speciesIdRS = 296,
        .nameJapanese = __("ハスブレロ"),
        .name = SPECIES_NAME("LOMBRE    ", "LOMBRE    ", "LOMBRERO  "),
        .catchIndex = 7,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_LUDICOLO
    },
    [SPECIES_LUDICOLO] = {
        .speciesIdRS = 297,
        .nameJapanese = __("ルンパッパ"),
        .name = SPECIES_NAME("LUDICOLO  ", "LUDICOLO  ", "KAPPALORES"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEEDOT] = {
        .speciesIdRS = 298,
        .nameJapanese = __("タネボー　"),
        .name = SPECIES_NAME("SEEDOT    ", "GRAINIPIOT", "SAMURZEL  "),
        .catchIndex = 0,
        .eggIndex = 2,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NUZLEAF
    },
    [SPECIES_NUZLEAF] = {
        .speciesIdRS = 299,
        .nameJapanese = __("コノハナ　"),
        .name = SPECIES_NAME("NUZLEAF   ", "PIFEUIL   ", "BLANAS    "),
        .catchIndex = 8,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 2,
        .evolutionTarget = SPECIES_SHIFTRY
    },
    [SPECIES_SHIFTRY] = {
        .speciesIdRS = 300,
        .nameJapanese = __("ダーテング"),
        .name = SPECIES_NAME("SHIFTRY   ", "TENGALICE ", "TENGULIST "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TAILLOW] = {
        .speciesIdRS = 304,
        .nameJapanese = __("スバメ　　"),
        .name = SPECIES_NAME("TAILLOW   ", "NIRONDELLE", "SCHWALBINI"),
        .catchIndex = 9,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWELLOW
    },
    [SPECIES_SWELLOW] = {
        .speciesIdRS = 305,
        .nameJapanese = __("オオスバメ"),
        .name = SPECIES_NAME("SWELLOW   ", "HELEDELLE ", "SCHWALBOSS"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WINGULL] = {
        .speciesIdRS = 309,
        .nameJapanese = __("キャモメ　"),
        .name = SPECIES_NAME("WINGULL   ", "GOELISE   ", "WINGULL   "),
        .catchIndex = 10,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PELIPPER
    },
    [SPECIES_PELIPPER] = {
        .speciesIdRS = 310,
        .nameJapanese = __("ペリッパー"),
        .name = SPECIES_NAME("PELIPPER  ", "BEKIPAN   ", "PELIPPER  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RALTS] = {
        .speciesIdRS = 392,
        .nameJapanese = __("ラルトス　"),
        .name = SPECIES_NAME("RALTS     ", "TARSAL    ", "TRASLA    "),
        .catchIndex = 0,
        .eggIndex = 3,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KIRLIA
    },
    [SPECIES_KIRLIA] = {
        .speciesIdRS = 393,
        .nameJapanese = __("キルリア　"),
        .name = SPECIES_NAME("KIRLIA    ", "KIRLIA    ", "KIRLIA    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GARDEVOIR
    },
    [SPECIES_GARDEVOIR] = {
        .speciesIdRS = 394,
        .nameJapanese = __("サーナイト"),
        .name = SPECIES_NAME("GARDEVOIR ", "GARDEVOIR ", "GUARDEVOIR"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SURSKIT] = {
        .speciesIdRS = 311,
        .nameJapanese = __("アメタマ　"),
        .name = SPECIES_NAME("SURSKIT   ", "ARAKDO    ", "GEHWEIHER "),
        .catchIndex = 0,
        .eggIndex = 4,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MASQUERAIN
    },
    [SPECIES_MASQUERAIN] = {
        .speciesIdRS = 312,
        .nameJapanese = __("アメモース"),
        .name = SPECIES_NAME("MASQUERAIN", "MASKADRA  ", "MASKEREGEN"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHROOMISH] = {
        .speciesIdRS = 306,
        .nameJapanese = __("キノココ　"),
        .name = SPECIES_NAME("SHROOMISH ", "BALIGNON  ", "KNILZ     "),
        .catchIndex = 0,
        .eggIndex = 5,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BRELOOM
    },
    [SPECIES_BRELOOM] = {
        .speciesIdRS = 307,
        .nameJapanese = __("キノガッサ"),
        .name = SPECIES_NAME("BRELOOM   ", "CHAPIGNON ", "KAPILZ    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLAKOTH] = {
        .speciesIdRS = 364,
        .nameJapanese = __("ナマケロ　"),
        .name = SPECIES_NAME("SLAKOTH   ", "PARECOOL  ", "BUMMELZ   "),
        .catchIndex = 11,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIGOROTH
    },
    [SPECIES_VIGOROTH] = {
        .speciesIdRS = 365,
        .nameJapanese = __("ヤルキモノ"),
        .name = SPECIES_NAME("VIGOROTH  ", "VIGOROTH  ", "MUNTIER   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SLAKING
    },
    [SPECIES_SLAKING] = {
        .speciesIdRS = 366,
        .nameJapanese = __("ケッキング"),
        .name = SPECIES_NAME("SLAKING   ", "MONAFLEMIT", "LETARKING "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABRA] = {
        .speciesIdRS = 63,
        .nameJapanese = __("ケーシィ　"),
        .name = SPECIES_NAME("ABRA      ", "ABRA      ", "ABRA      "),
        .catchIndex = 12,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KADABRA
    },
    [SPECIES_KADABRA] = {
        .speciesIdRS = 64,
        .nameJapanese = __("ユンゲラー"),
        .name = SPECIES_NAME("KADABRA   ", "KADABRA   ", "KADABRA   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_ALAKAZAM
    },
    [SPECIES_ALAKAZAM] = {
        .speciesIdRS = 65,
        .nameJapanese = __("フーディン"),
        .name = SPECIES_NAME("ALAKAZAM  ", "ALAKAZAM  ", "SIMSALA   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NINCADA] = {
        .speciesIdRS = 301,
        .nameJapanese = __("ツチニン　"),
        .name = SPECIES_NAME("NINCADA   ", "NINGALE   ", "NINCADA   "),
        .catchIndex = 13,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NINJASK
    },
    [SPECIES_NINJASK] = {
        .speciesIdRS = 302,
        .nameJapanese = __("テッカニン"),
        .name = SPECIES_NAME("NINJASK   ", "NINJASK   ", "NINJASK   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHEDINJA] = {
        .speciesIdRS = 303,
        .nameJapanese = __("ヌケニン　"),
        .name = SPECIES_NAME("SHEDINJA  ", "MUNJA     ", "NINJATOM  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WHISMUR] = {
        .speciesIdRS = 370,
        .nameJapanese = __("ゴニョニョ"),
        .name = SPECIES_NAME("WHISMUR   ", "CHUCHMUR  ", "FLURMEL   "),
        .catchIndex = 0,
        .eggIndex = 6,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOUDRED
    },
    [SPECIES_LOUDRED] = {
        .speciesIdRS = 371,
        .nameJapanese = __("ドゴーム　"),
        .name = SPECIES_NAME("LOUDRED   ", "RAMBOUM   ", "KRAKEELO  "),
        .catchIndex = 14,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_EXPLOUD
    },
    [SPECIES_EXPLOUD] = {
        .speciesIdRS = 372,
        .nameJapanese = __("バクオング"),
        .name = SPECIES_NAME("EXPLOUD   ", "BROUHABAM ", "KRAWUMMS  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAKUHITA] = {
        .speciesIdRS = 335,
        .nameJapanese = __("マクノシタ"),
        .name = SPECIES_NAME("MAKUHITA  ", "MAKUHITA  ", "MAKUHITA  "),
        .catchIndex = 15,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HARIYAMA
    },
    [SPECIES_HARIYAMA] = {
        .speciesIdRS = 336,
        .nameJapanese = __("ハリテヤマ"),
        .name = SPECIES_NAME("HARIYAMA  ", "HARIYAMA  ", "HARIYAMA  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOLDEEN] = {
        .speciesIdRS = 118,
        .nameJapanese = __("トサキント"),
        .name = SPECIES_NAME("GOLDEEN   ", "POISSIRENE", "GOLDINI   "),
        .catchIndex = 16,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEAKING
    },
    [SPECIES_SEAKING] = {
        .speciesIdRS = 119,
        .nameJapanese = __("アズマオウ"),
        .name = SPECIES_NAME("SEAKING   ", "POISSOROY ", "GOLKING   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGIKARP] = {
        .speciesIdRS = 129,
        .nameJapanese = __("コイキング"),
        .name = SPECIES_NAME("MAGIKARP  ", "MAGICARPE ", "KARPADOR  "),
        .catchIndex = 17,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GYARADOS
    },
    [SPECIES_GYARADOS] = {
        .speciesIdRS = 130,
        .nameJapanese = __("ギャラドス"),
        .name = SPECIES_NAME("GYARADOS  ", "LEVIATOR  ", "GARADOS   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AZURILL] = {
        .speciesIdRS = 350,
        .nameJapanese = __("ルリリ　　"),
        .name = SPECIES_NAME("AZURILL   ", "AZURILL   ", "AZURILL   "),
        .catchIndex = 0,
        .eggIndex = 7,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_MARILL
    },
    [SPECIES_MARILL] = {
        .speciesIdRS = 183,
        .nameJapanese = __("マリル　　"),
        .name = SPECIES_NAME("MARILL    ", "MARILL    ", "MARILL    "),
        .catchIndex = 18,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AZUMARILL
    },
    [SPECIES_AZUMARILL] = {
        .speciesIdRS = 184,
        .nameJapanese = __("マリルリ　"),
        .name = SPECIES_NAME("AZUMARILL ", "AZUMARILL ", "AZUMARILL "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GEODUDE] = {
        .speciesIdRS = 74,
        .nameJapanese = __("イシツブテ"),
        .name = SPECIES_NAME("GEODUDE   ", "RACAILLOU ", "KLEINSTEIN"),
        .catchIndex = 19,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRAVELER
    },
    [SPECIES_GRAVELER] = {
        .speciesIdRS = 75,
        .nameJapanese = __("ゴローン　"),
        .name = SPECIES_NAME("GRAVELER  ", "GRAVALANCH", "GEOROK    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_GOLEM
    },
    [SPECIES_GOLEM] = {
        .speciesIdRS = 76,
        .nameJapanese = __("ゴローニャ"),
        .name = SPECIES_NAME("GOLEM     ", "GROLEM    ", "GEOWAZ    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NOSEPASS] = {
        .speciesIdRS = 320,
        .nameJapanese = __("ノズパス　"),
        .name = SPECIES_NAME("NOSEPASS  ", "TARINOR   ", "NASGNET   "),
        .catchIndex = 20,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKITTY] = {
        .speciesIdRS = 315,
        .nameJapanese = __("エネコ　　"),
        .name = SPECIES_NAME("SKITTY    ", "SKITTY    ", "ENECO     "),
        .catchIndex = 0,
        .eggIndex = 8,
        .specialEggFlag = 1,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_DELCATTY
    },
    [SPECIES_DELCATTY] = {
        .speciesIdRS = 316,
        .nameJapanese = __("エネコロロ"),
        .name = SPECIES_NAME("DELCATTY  ", "DELCATTY  ", "ENEKORO   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZUBAT] = {
        .speciesIdRS = 41,
        .nameJapanese = __("ズバット　"),
        .name = SPECIES_NAME("ZUBAT     ", "NOSFERAPTI", "ZUBAT     "),
        .catchIndex = 0,
        .eggIndex = 9,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLBAT
    },
    [SPECIES_GOLBAT] = {
        .speciesIdRS = 42,
        .nameJapanese = __("ゴルバット"),
        .name = SPECIES_NAME("GOLBAT    ", "NOSFERALTO", "GOLBAT    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_CROBAT
    },
    [SPECIES_CROBAT] = {
        .speciesIdRS = 169,
        .nameJapanese = __("クロバット"),
        .name = SPECIES_NAME("CROBAT    ", "NOSTENFER ", "IKSBAT    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TENTACOOL] = {
        .speciesIdRS = 72,
        .nameJapanese = __("メノクラゲ"),
        .name = SPECIES_NAME("TENTACOOL ", "TENTACOOL ", "TENTACHA  "),
        .catchIndex = 21,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TENTACRUEL
    },
    [SPECIES_TENTACRUEL] = {
        .speciesIdRS = 73,
        .nameJapanese = __("ドククラゲ"),
        .name = SPECIES_NAME("TENTACRUEL", "TENTACRUEL", "TENTOXA   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SABLEYE] = {
        .speciesIdRS = 322,
        .nameJapanese = __("ヤミラミ　"),
        .name = SPECIES_NAME("SABLEYE   ", "TENEFIX   ", "ZOBIRIS   "),
        .catchIndex = 22,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAWILE] = {
        .speciesIdRS = 355,
        .nameJapanese = __("クチート　"),
        .name = SPECIES_NAME("MAWILE    ", "MYSDIBULE ", "FLUNKIFER "),
        .catchIndex = 23,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ARON] = {
        .speciesIdRS = 382,
        .nameJapanese = __("ココドラ　"),
        .name = SPECIES_NAME("ARON      ", "GALEKID   ", "STOLLUNIOR"),
        .catchIndex = 0,
        .eggIndex = 10,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LAIRON
    },
    [SPECIES_LAIRON] = {
        .speciesIdRS = 383,
        .nameJapanese = __("コドラ　　"),
        .name = SPECIES_NAME("LAIRON    ", "GALEGON   ", "STOLLRAK  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AGGRON
    },
    [SPECIES_AGGRON] = {
        .speciesIdRS = 384,
        .nameJapanese = __("ボスゴドラ"),
        .name = SPECIES_NAME("AGGRON    ", "GALEKING  ", "STOLLOSS  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MACHOP] = {
        .speciesIdRS = 66,
        .nameJapanese = __("ワンリキー"),
        .name = SPECIES_NAME("MACHOP    ", "MACHOC    ", "MACHOLLO  "),
        .catchIndex = 24,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MACHOKE
    },
    [SPECIES_MACHOKE] = {
        .speciesIdRS = 67,
        .nameJapanese = __("ゴーリキー"),
        .name = SPECIES_NAME("MACHOKE   ", "MACHOPEUR ", "MASCHOCK  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_MACHAMP
    },
    [SPECIES_MACHAMP] = {
        .speciesIdRS = 68,
        .nameJapanese = __("カイリキー"),
        .name = SPECIES_NAME("MACHAMP   ", "MACKOGNEUR", "MACHOMEI  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEDITITE] = {
        .speciesIdRS = 356,
        .nameJapanese = __("アサナン　"),
        .name = SPECIES_NAME("MEDITITE  ", "MEDITIKKA ", "MEDITIE   "),
        .catchIndex = 25,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MEDICHAM
    },
    [SPECIES_MEDICHAM] = {
        .speciesIdRS = 357,
        .nameJapanese = __("チャーレム"),
        .name = SPECIES_NAME("MEDICHAM  ", "CHARMINA  ", "MEDITALIS "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ELECTRIKE] = {
        .speciesIdRS = 337,
        .nameJapanese = __("ラクライ　"),
        .name = SPECIES_NAME("ELECTRIKE ", "DYNAVOLT  ", "FRIZELBLIZ"),
        .catchIndex = 26,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MANECTRIC
    },
    [SPECIES_MANECTRIC] = {
        .speciesIdRS = 338,
        .nameJapanese = __("ライボルト"),
        .name = SPECIES_NAME("MANECTRIC ", "ELECSPRINT", "VOLTENSO  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PLUSLE] = {
        .speciesIdRS = 353,
        .nameJapanese = __("プラスル　"),
        .name = SPECIES_NAME("PLUSLE    ", "POSIPI    ", "PLUSLE    "),
        .catchIndex = 0,
        .eggIndex = 11,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MINUN] = {
        .speciesIdRS = 354,
        .nameJapanese = __("マイナン　"),
        .name = SPECIES_NAME("MINUN     ", "NEGAPI    ", "MINUN     "),
        .catchIndex = 0,
        .eggIndex = 12,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGNEMITE] = {
        .speciesIdRS = 81,
        .nameJapanese = __("コイル　　"),
        .name = SPECIES_NAME("MAGNEMITE ", "MAGNETI   ", "MAGNETILO "),
        .catchIndex = 27,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGNETON
    },
    [SPECIES_MAGNETON] = {
        .speciesIdRS = 82,
        .nameJapanese = __("レアコイル"),
        .name = SPECIES_NAME("MAGNETON  ", "MAGNETON  ", "MAGNETON  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLTORB] = {
        .speciesIdRS = 100,
        .nameJapanese = __("ビリリダマ"),
        .name = SPECIES_NAME("VOLTORB   ", "VOLTORBE  ", "VOLTOBAL  "),
        .catchIndex = 28,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ELECTRODE
    },
    [SPECIES_ELECTRODE] = {
        .speciesIdRS = 101,
        .nameJapanese = __("マルマイン"),
        .name = SPECIES_NAME("ELECTRODE ", "ELECTRODE ", "LEKTROBAL "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLBEAT] = {
        .speciesIdRS = 386,
        .nameJapanese = __("バルビート"),
        .name = SPECIES_NAME("VOLBEAT   ", "MUCIOLE   ", "VOLBEAT   "),
        .catchIndex = 29,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ILLUMISE] = {
        .speciesIdRS = 387,
        .nameJapanese = __("イルミーゼ"),
        .name = SPECIES_NAME("ILLUMISE  ", "LUMIVOLE  ", "ILLUMISE  "),
        .catchIndex = 30,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ODDISH] = {
        .speciesIdRS = 43,
        .nameJapanese = __("ナゾノクサ"),
        .name = SPECIES_NAME("ODDISH    ", "MYSTHERBE ", "MYRAPLA   "),
        .catchIndex = 0,
        .eggIndex = 13,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLOOM
    },
    [SPECIES_GLOOM] = {
        .speciesIdRS = 44,
        .nameJapanese = __("クサイハナ"),
        .name = SPECIES_NAME("GLOOM     ", "ORTIDE    ", "DUFLOR    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_VILEPLUME
    },
    [SPECIES_VILEPLUME] = {
        .speciesIdRS = 45,
        .nameJapanese = __("ラフレシア"),
        .name = SPECIES_NAME("VILEPLUME ", "RAFFLESIA ", "GIFLOR    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELLOSSOM] = {
        .speciesIdRS = 182,
        .nameJapanese = __("キレイハナ"),
        .name = SPECIES_NAME("BELLOSSOM ", "JOLIFLOR  ", "BLUBELLA  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DODUO] = {
        .speciesIdRS = 84,
        .nameJapanese = __("ドードー　"),
        .name = SPECIES_NAME("DODUO     ", "DODUO     ", "DODU      "),
        .catchIndex = 31,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DODRIO
    },
    [SPECIES_DODRIO] = {
        .speciesIdRS = 85,
        .nameJapanese = __("ドードリオ"),
        .name = SPECIES_NAME("DODRIO    ", "DODRIO    ", "DODRI     "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ROSELIA] = {
        .speciesIdRS = 363,
        .nameJapanese = __("ロゼリア　"),
        .name = SPECIES_NAME("ROSELIA   ", "ROSELIA   ", "ROSELIA   "),
        .catchIndex = 32,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GULPIN] = {
        .speciesIdRS = 367,
        .nameJapanese = __("ゴクリン　"),
        .name = SPECIES_NAME("GULPIN    ", "GLOUPTI   ", "SCHLUPPUCK"),
        .catchIndex = 0,
        .eggIndex = 14,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWALOT
    },
    [SPECIES_SWALOT] = {
        .speciesIdRS = 368,
        .nameJapanese = __("マルノーム"),
        .name = SPECIES_NAME("SWALOT    ", "AVALTOUT  ", "SCHLUKWECH"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CARVANHA] = {
        .speciesIdRS = 330,
        .nameJapanese = __("キバニア　"),
        .name = SPECIES_NAME("CARVANHA  ", "CARVANHA  ", "KANIVANHA "),
        .catchIndex = 33,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHARPEDO
    },
    [SPECIES_SHARPEDO] = {
        .speciesIdRS = 331,
        .nameJapanese = __("サメハダー"),
        .name = SPECIES_NAME("SHARPEDO  ", "SHARPEDO  ", "TOHAIDO   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WAILMER] = {
        .speciesIdRS = 313,
        .nameJapanese = __("ホエルコ　"),
        .name = SPECIES_NAME("WAILMER   ", "WAILMER   ", "WAILMER   "),
        .catchIndex = 34,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WAILORD
    },
    [SPECIES_WAILORD] = {
        .speciesIdRS = 314,
        .nameJapanese = __("ホエルオー"),
        .name = SPECIES_NAME("WAILORD   ", "WAILORD   ", "WAILORD   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NUMEL] = {
        .speciesIdRS = 339,
        .nameJapanese = __("ドンメル　"),
        .name = SPECIES_NAME("NUMEL     ", "CHAMALLOT ", "CAMAUB    "),
        .catchIndex = 35,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CAMERUPT
    },
    [SPECIES_CAMERUPT] = {
        .speciesIdRS = 340,
        .nameJapanese = __("バクーダ　"),
        .name = SPECIES_NAME("CAMERUPT  ", "CAMERUPT  ", "CAMERUPT  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLUGMA] = {
        .speciesIdRS = 218,
        .nameJapanese = __("マグマッグ"),
        .name = SPECIES_NAME("SLUGMA    ", "LIMAGMA   ", "SCHNECKMAG"),
        .catchIndex = 36,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGCARGO
    },
    [SPECIES_MAGCARGO] = {
        .speciesIdRS = 219,
        .nameJapanese = __("マグカルゴ"),
        .name = SPECIES_NAME("MAGCARGO  ", "VOLCAROPOD", "MAGCARGO  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORKOAL] = {
        .speciesIdRS = 321,
        .nameJapanese = __("コータス　"),
        .name = SPECIES_NAME("TORKOAL   ", "CHARTOR   ", "QURTEL    "),
        .catchIndex = 37,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GRIMER] = {
        .speciesIdRS = 88,
        .nameJapanese = __("ベトベター"),
        .name = SPECIES_NAME("GRIMER    ", "TADMORV   ", "SLEIMA    "),
        .catchIndex = 38,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MUK
    },
    [SPECIES_MUK] = {
        .speciesIdRS = 89,
        .nameJapanese = __("ベトベトン"),
        .name = SPECIES_NAME("MUK       ", "GROTADMORV", "SLEIMOK   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KOFFING] = {
        .speciesIdRS = 109,
        .nameJapanese = __("ドガース　"),
        .name = SPECIES_NAME("KOFFING   ", "SMOGO     ", "SMOGON    "),
        .catchIndex = 39,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WEEZING
    },
    [SPECIES_WEEZING] = {
        .speciesIdRS = 110,
        .nameJapanese = __("マタドガス"),
        .name = SPECIES_NAME("WEEZING   ", "SMOGOGO   ", "SMOGMOG   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPOINK] = {
        .speciesIdRS = 351,
        .nameJapanese = __("バネブー　"),
        .name = SPECIES_NAME("SPOINK    ", "SPOINK    ", "SPOINK    "),
        .catchIndex = 0,
        .eggIndex = 15,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRUMPIG
    },
    [SPECIES_GRUMPIG] = {
        .speciesIdRS = 352,
        .nameJapanese = __("ブーピッグ"),
        .name = SPECIES_NAME("GRUMPIG   ", "GRORET    ", "GROINK    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SANDSHREW] = {
        .speciesIdRS = 27,
        .nameJapanese = __("サンド　　"),
        .name = SPECIES_NAME("SANDSHREW ", "SABELETTE ", "SANDAN    "),
        .catchIndex = 0,
        .eggIndex = 16,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SANDSLASH
    },
    [SPECIES_SANDSLASH] = {
        .speciesIdRS = 28,
        .nameJapanese = __("サンドパン"),
        .name = SPECIES_NAME("SANDSLASH ", "SABLAIREAU", "SANDAMER  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPINDA] = {
        .speciesIdRS = 308,
        .nameJapanese = __("パッチール"),
        .name = SPECIES_NAME("SPINDA    ", "SPINDA    ", "PANDIR    "),
        .catchIndex = 0,
        .eggIndex = 17,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKARMORY] = {
        .speciesIdRS = 227,
        .nameJapanese = __("エアームド"),
        .name = SPECIES_NAME("SKARMORY  ", "AIRMURE   ", "PANZAERON "),
        .catchIndex = 40,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TRAPINCH] = {
        .speciesIdRS = 332,
        .nameJapanese = __("ナックラー"),
        .name = SPECIES_NAME("TRAPINCH  ", "KRAKNOIX  ", "KNACKLION "),
        .catchIndex = 0,
        .eggIndex = 18,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIBRAVA
    },
    [SPECIES_VIBRAVA] = {
        .speciesIdRS = 333,
        .nameJapanese = __("ビブラーバ"),
        .name = SPECIES_NAME("VIBRAVA   ", "VIBRANINF ", "VIBRAVA   "),
        .catchIndex = 41,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FLYGON
    },
    [SPECIES_FLYGON] = {
        .speciesIdRS = 334,
        .nameJapanese = __("フライゴン"),
        .name = SPECIES_NAME("FLYGON    ", "LIBEGON   ", "LIBELLDRA "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CACNEA] = {
        .speciesIdRS = 344,
        .nameJapanese = __("サボネア　"),
        .name = SPECIES_NAME("CACNEA    ", "CACNEA    ", "TUSKA     "),
        .catchIndex = 42,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CACTURNE
    },
    [SPECIES_CACTURNE] = {
        .speciesIdRS = 345,
        .nameJapanese = __("ノクタス　"),
        .name = SPECIES_NAME("CACTURNE  ", "CACTURNE  ", "NOKTUSKA  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SWABLU] = {
        .speciesIdRS = 358,
        .nameJapanese = __("チルット　"),
        .name = SPECIES_NAME("SWABLU    ", "TYLTON    ", "WABLU     "),
        .catchIndex = 43,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ALTARIA
    },
    [SPECIES_ALTARIA] = {
        .speciesIdRS = 359,
        .nameJapanese = __("チルタリス"),
        .name = SPECIES_NAME("ALTARIA   ", "ALTARIA   ", "ALTARIA   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZANGOOSE] = {
        .speciesIdRS = 380,
        .nameJapanese = __("ザングース"),
        .name = SPECIES_NAME("ZANGOOSE  ", "MANGRIFF  ", "SENGO     "),
        .catchIndex = 44,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEVIPER] = {
        .speciesIdRS = 379,
        .nameJapanese = __("ハブネーク"),
        .name = SPECIES_NAME("SEVIPER   ", "SEVIPER   ", "VIPITIS   "),
        .catchIndex = 45,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUNATONE] = {
        .speciesIdRS = 348,
        .nameJapanese = __("ルナトーン"),
        .name = SPECIES_NAME("LUNATONE  ", "SELEROC   ", "LUNASTEIN "),
        .catchIndex = 46,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SOLROCK] = {
        .speciesIdRS = 349,
        .nameJapanese = __("ソルロック"),
        .name = SPECIES_NAME("SOLROCK   ", "SOLAROC   ", "SONNFEL   "),
        .catchIndex = 47,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BARBOACH] = {
        .speciesIdRS = 323,
        .nameJapanese = __("ドジョッチ"),
        .name = SPECIES_NAME("BARBOACH  ", "BARLOCHE  ", "SCHMERBE  "),
        .catchIndex = 48,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WHISCASH
    },
    [SPECIES_WHISCASH] = {
        .speciesIdRS = 324,
        .nameJapanese = __("ナマズン　"),
        .name = SPECIES_NAME("WHISCASH  ", "BARBICHA  ", "WELSAR    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORPHISH] = {
        .speciesIdRS = 326,
        .nameJapanese = __("ヘイガニ　"),
        .name = SPECIES_NAME("CORPHISH  ", "ECRAPINCE ", "KREBSCORPS"),
        .catchIndex = 49,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRAWDAUNT
    },
    [SPECIES_CRAWDAUNT] = {
        .speciesIdRS = 327,
        .nameJapanese = __("シザリガー"),
        .name = SPECIES_NAME("CRAWDAUNT ", "COLHOMARD ", "KREBUTACK "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BALTOY] = {
        .speciesIdRS = 318,
        .nameJapanese = __("ヤジロン　"),
        .name = SPECIES_NAME("BALTOY    ", "BALBUTO   ", "PUPPANCE  "),
        .catchIndex = 50,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CLAYDOL
    },
    [SPECIES_CLAYDOL] = {
        .speciesIdRS = 319,
        .nameJapanese = __("ネンドール"),
        .name = SPECIES_NAME("CLAYDOL   ", "KAORINE   ", "LEPUMENTAS"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LILEEP] = {
        .speciesIdRS = 388,
        .nameJapanese = __("リリーラ　"),
        .name = SPECIES_NAME("LILEEP    ", "LILIA     ", "LILIEP    "),
        .catchIndex = 51,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRADILY
    },
    [SPECIES_CRADILY] = {
        .speciesIdRS = 389,
        .nameJapanese = __("ユレイドル"),
        .name = SPECIES_NAME("CRADILY   ", "VACILYS   ", "WIELIE    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ANORITH] = {
        .speciesIdRS = 390,
        .nameJapanese = __("アノプス　"),
        .name = SPECIES_NAME("ANORITH   ", "ANORITH   ", "ANORITH   "),
        .catchIndex = 52,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ARMALDO
    },
    [SPECIES_ARMALDO] = {
        .speciesIdRS = 391,
        .nameJapanese = __("アーマルド"),
        .name = SPECIES_NAME("ARMALDO   ", "ARMALDO   ", "ARMALDO   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_IGGLYBUFF] = {
        .speciesIdRS = 174,
        .nameJapanese = __("ププリン　"),
        .name = SPECIES_NAME("IGGLYBUFF ", "TOUDOUDOU ", "FLUFFELUFF"),
        .catchIndex = 0,
        .eggIndex = 19,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_JIGGLYPUFF
    },
    [SPECIES_JIGGLYPUFF] = {
        .speciesIdRS = 39,
        .nameJapanese = __("プリン　　"),
        .name = SPECIES_NAME("JIGGLYPUFF", "RONDOUDOU ", "PUMMELUFF "),
        .catchIndex = 53,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_WIGGLYTUFF
    },
    [SPECIES_WIGGLYTUFF] = {
        .speciesIdRS = 40,
        .nameJapanese = __("プクリン　"),
        .name = SPECIES_NAME("WIGGLYTUFF", "GRODOUDOU ", "KNUDDELUFF"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FEEBAS] = {
        .speciesIdRS = 328,
        .nameJapanese = __("ヒンバス　"),
        .name = SPECIES_NAME("FEEBAS    ", "BARPAU    ", "BARSCHWA  "),
        .catchIndex = 54,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 10,
        .evolutionTarget = SPECIES_MILOTIC
    },
    [SPECIES_MILOTIC] = {
        .speciesIdRS = 329,
        .nameJapanese = __("ミロカロス"),
        .name = SPECIES_NAME("MILOTIC   ", "MILOBELLUS", "MILOTIC   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASTFORM] = {
        .speciesIdRS = 385,
        .nameJapanese = __("ポワルン　"),
        .name = SPECIES_NAME("CASTFORM  ", "MORPHEO   ", "FORMEO    "),
        .catchIndex = 55,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_STARYU] = {
        .speciesIdRS = 120,
        .nameJapanese = __("ヒトデマン"),
        .name = SPECIES_NAME("STARYU    ", "STARI     ", "STERNDU   "),
        .catchIndex = 56,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_STARMIE
    },
    [SPECIES_STARMIE] = {
        .speciesIdRS = 121,
        .nameJapanese = __("スターミー"),
        .name = SPECIES_NAME("STARMIE   ", "STAROSS   ", "STARMIE   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KECLEON] = {
        .speciesIdRS = 317,
        .nameJapanese = __("カクレオン"),
        .name = SPECIES_NAME("KECLEON   ", "KECLEON   ", "KECLEON   "),
        .catchIndex = 57,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHUPPET] = {
        .speciesIdRS = 377,
        .nameJapanese = __("カゲボウズ"),
        .name = SPECIES_NAME("SHUPPET   ", "POLICHOMBR", "SHUPPET   "),
        .catchIndex = 0,
        .eggIndex = 20,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BANETTE
    },
    [SPECIES_BANETTE] = {
        .speciesIdRS = 378,
        .nameJapanese = __("ジュペッタ"),
        .name = SPECIES_NAME("BANETTE   ", "BRANETTE  ", "BANETTE   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DUSKULL] = {
        .speciesIdRS = 361,
        .nameJapanese = __("ヨマワル　"),
        .name = SPECIES_NAME("DUSKULL   ", "SKELENOX  ", "ZWIRRLICHT"),
        .catchIndex = 58,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSCLOPS
    },
    [SPECIES_DUSCLOPS] = {
        .speciesIdRS = 362,
        .nameJapanese = __("サマヨール"),
        .name = SPECIES_NAME("DUSCLOPS  ", "TERACLOPE ", "ZWIRRKLOP "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TROPIUS] = {
        .speciesIdRS = 369,
        .nameJapanese = __("トロピウス"),
        .name = SPECIES_NAME("TROPIUS   ", "TROPIUS   ", "TROPIUS   "),
        .catchIndex = 59,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIMECHO] = {
        .speciesIdRS = 411,
        .nameJapanese = __("チリーン　"),
        .name = SPECIES_NAME("CHIMECHO  ", "EOKO      ", "PALIMPALIM"),
        .catchIndex = 0,
        .eggIndex = 21,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABSOL] = {
        .speciesIdRS = 376,
        .nameJapanese = __("アブソル　"),
        .name = SPECIES_NAME("ABSOL     ", "ABSOL     ", "ABSOL     "),
        .catchIndex = 60,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VULPIX] = {
        .speciesIdRS = 37,
        .nameJapanese = __("ロコン　　"),
        .name = SPECIES_NAME("VULPIX    ", "GOUPIX    ", "VULPIX    "),
        .catchIndex = 61,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 3,
        .evolutionTarget = SPECIES_NINETALES
    },
    [SPECIES_NINETALES] = {
        .speciesIdRS = 38,
        .nameJapanese = __("キュウコン"),
        .name = SPECIES_NAME("NINETALES ", "FEUNARD   ", "VULNONA   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PICHU] = {
        .speciesIdRS = 172,
        .nameJapanese = __("ピチュー　"),
        .name = SPECIES_NAME("PICHU     ", "PICHU     ", "PICHU     "),
        .catchIndex = 0,
        .eggIndex = 22,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_PIKACHU
    },
    [SPECIES_PIKACHU] = {
        .speciesIdRS = 25,
        .nameJapanese = __("ピカチュウ"),
        .name = SPECIES_NAME("PIKACHU   ", "PIKACHU   ", "PIKACHU   "),
        .catchIndex = 62,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 7,
        .evolutionTarget = SPECIES_RAICHU
    },
    [SPECIES_RAICHU] = {
        .speciesIdRS = 26,
        .nameJapanese = __("ライチュウ"),
        .name = SPECIES_NAME("RAICHU    ", "RAICHU    ", "RAICHU    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PSYDUCK] = {
        .speciesIdRS = 54,
        .nameJapanese = __("コダック　"),
        .name = SPECIES_NAME("PSYDUCK   ", "PSYKOKWAK ", "ENTON     "),
        .catchIndex = 63,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLDUCK
    },
    [SPECIES_GOLDUCK] = {
        .speciesIdRS = 55,
        .nameJapanese = __("ゴルダック"),
        .name = SPECIES_NAME("GOLDUCK   ", "AKWAKWAK  ", "ENTORON   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WYNAUT] = {
        .speciesIdRS = 360,
        .nameJapanese = __("ソーナノ　"),
        .name = SPECIES_NAME("WYNAUT    ", "OKEOKE    ", "ISSO      "),
        .catchIndex = 0,
        .eggIndex = 23,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WOBBUFFET
    },
    [SPECIES_WOBBUFFET] = {
        .speciesIdRS = 202,
        .nameJapanese = __("ソーナンス"),
        .name = SPECIES_NAME("WOBBUFFET ", "QULBUTOKE ", "WOINGENAU "),
        .catchIndex = 64,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NATU] = {
        .speciesIdRS = 177,
        .nameJapanese = __("ネイティ　"),
        .name = SPECIES_NAME("NATU      ", "NATU      ", "NATU      "),
        .catchIndex = 0,
        .eggIndex = 24,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_XATU
    },
    [SPECIES_XATU] = {
        .speciesIdRS = 178,
        .nameJapanese = __("ネイティオ"),
        .name = SPECIES_NAME("XATU      ", "XATU      ", "XATU      "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GIRAFARIG] = {
        .speciesIdRS = 203,
        .nameJapanese = __("キリンリキ"),
        .name = SPECIES_NAME("GIRAFARIG ", "GIRAFARIG ", "GIRAFARIG "),
        .catchIndex = 65,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PHANPY] = {
        .speciesIdRS = 231,
        .nameJapanese = __("ゴマゾウ　"),
        .name = SPECIES_NAME("PHANPY    ", "PHANPY    ", "PHANPY    "),
        .catchIndex = 0,
        .eggIndex = 25,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DONPHAN
    },
    [SPECIES_DONPHAN] = {
        .speciesIdRS = 232,
        .nameJapanese = __("ドンファン"),
        .name = SPECIES_NAME("DONPHAN   ", "DONPHAN   ", "DONPHAN   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PINSIR] = {
        .speciesIdRS = 127,
        .nameJapanese = __("カイロス　"),
        .name = SPECIES_NAME("PINSIR    ", "SCARABRUTE", "PINSIR    "),
        .catchIndex = 66,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HERACROSS] = {
        .speciesIdRS = 214,
        .nameJapanese = __("ヘラクロス"),
        .name = SPECIES_NAME("HERACROSS ", "SCARHINO  ", "SKARABORN "),
        .catchIndex = 67,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RHYHORN] = {
        .speciesIdRS = 111,
        .nameJapanese = __("サイホーン"),
        .name = SPECIES_NAME("RHYHORN   ", "RHINOCORNE", "RIHORN    "),
        .catchIndex = 68,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RHYDON
    },
    [SPECIES_RHYDON] = {
        .speciesIdRS = 112,
        .nameJapanese = __("サイドン　"),
        .name = SPECIES_NAME("RHYDON    ", "RHINOFEROS", "RIZEROS   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SNORUNT] = {
        .speciesIdRS = 346,
        .nameJapanese = __("ユキワラシ"),
        .name = SPECIES_NAME("SNORUNT   ", "STALGAMIN ", "SCHNEPPKE "),
        .catchIndex = 0,
        .eggIndex = 26,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLALIE
    },
    [SPECIES_GLALIE] = {
        .speciesIdRS = 347,
        .nameJapanese = __("オニゴーリ"),
        .name = SPECIES_NAME("GLALIE    ", "ONIGLALI  ", "FIRNONTOR "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPHEAL] = {
        .speciesIdRS = 341,
        .nameJapanese = __("タマザラシ"),
        .name = SPECIES_NAME("SPHEAL    ", "OBALIE    ", "SEEMOPS   "),
        .catchIndex = 0,
        .eggIndex = 27,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEALEO
    },
    [SPECIES_SEALEO] = {
        .speciesIdRS = 342,
        .nameJapanese = __("トドグラー"),
        .name = SPECIES_NAME("SEALEO    ", "PHOGLEUR  ", "SEEJONG   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WALREIN
    },
    [SPECIES_WALREIN] = {
        .speciesIdRS = 343,
        .nameJapanese = __("トドゼルガ"),
        .name = SPECIES_NAME("WALREIN   ", "KAIMORSE  ", "WALRAISA  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CLAMPERL] = {
        .speciesIdRS = 373,
        .nameJapanese = __("パールル　"),
        .name = SPECIES_NAME("CLAMPERL  ", "COQUIPERL ", "PERLU     "),
        .catchIndex = 69,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_HUNTAIL
    },
    [SPECIES_HUNTAIL] = {
        .speciesIdRS = 374,
        .nameJapanese = __("ハンテール"),
        .name = SPECIES_NAME("HUNTAIL   ", "SERPANG   ", "AALABYSS  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOREBYSS] = {
        .speciesIdRS = 375,
        .nameJapanese = __("サクラビス"),
        .name = SPECIES_NAME("GOREBYSS  ", "ROSABYSS  ", "SAGANABYSS"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RELICANTH] = {
        .speciesIdRS = 381,
        .nameJapanese = __("ジーランス"),
        .name = SPECIES_NAME("RELICANTH ", "RELICANTH ", "RELICANTH "),
        .catchIndex = 70,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORSOLA] = {
        .speciesIdRS = 222,
        .nameJapanese = __("サニーゴ　"),
        .name = SPECIES_NAME("CORSOLA   ", "CORAYON   ", "CORASONN  "),
        .catchIndex = 0,
        .eggIndex = 28,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHINCHOU] = {
        .speciesIdRS = 170,
        .nameJapanese = __("チョンチー"),
        .name = SPECIES_NAME("CHINCHOU  ", "LOUPIO    ", "LAMPI     "),
        .catchIndex = 0,
        .eggIndex = 29,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LANTURN
    },
    [SPECIES_LANTURN] = {
        .speciesIdRS = 171,
        .nameJapanese = __("ランターン"),
        .name = SPECIES_NAME("LANTURN   ", "LANTURN   ", "LANTURN   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUVDISC] = {
        .speciesIdRS = 325,
        .nameJapanese = __("ラブカス　"),
        .name = SPECIES_NAME("LUVDISC   ", "LOVDISC   ", "LIEBISKUS "),
        .catchIndex = 71,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HORSEA] = {
        .speciesIdRS = 116,
        .nameJapanese = __("タッツー　"),
        .name = SPECIES_NAME("HORSEA    ", "HYPOTREMPE", "SEEPER    "),
        .catchIndex = 0,
        .eggIndex = 30,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEADRA
    },
    [SPECIES_SEADRA] = {
        .speciesIdRS = 117,
        .nameJapanese = __("シードラ　"),
        .name = SPECIES_NAME("SEADRA    ", "HYPOCEAN  ", "SEEMON    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_KINGDRA
    },
    [SPECIES_KINGDRA] = {
        .speciesIdRS = 230,
        .nameJapanese = __("キングドラ"),
        .name = SPECIES_NAME("KINGDRA   ", "HYPOROI   ", "SEEDRAKING"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BAGON] = {
        .speciesIdRS = 395,
        .nameJapanese = __("タツベイ　"),
        .name = SPECIES_NAME("BAGON     ", "DRABY     ", "KINDWURM  "),
        .catchIndex = 0,
        .eggIndex = 31,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHELGON
    },
    [SPECIES_SHELGON] = {
        .speciesIdRS = 396,
        .nameJapanese = __("コモルー　"),
        .name = SPECIES_NAME("SHELGON   ", "DRACKHAUS ", "DRASCHEL  "),
        .catchIndex = 72,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SALAMENCE
    },
    [SPECIES_SALAMENCE] = {
        .speciesIdRS = 397,
        .nameJapanese = __("ボーマンダ"),
        .name = SPECIES_NAME("SALAMENCE ", "DRATTAK   ", "BRUTALANDA"),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELDUM] = {
        .speciesIdRS = 398,
        .nameJapanese = __("ダンバル　"),
        .name = SPECIES_NAME("BELDUM    ", "TERHAL    ", "TANHEL    "),
        .catchIndex = 73,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METANG
    },
    [SPECIES_METANG] = {
        .speciesIdRS = 399,
        .nameJapanese = __("メタング　"),
        .name = SPECIES_NAME("METANG    ", "METANG    ", "METANG    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METAGROSS
    },
    [SPECIES_METAGROSS] = {
        .speciesIdRS = 400,
        .nameJapanese = __("メタグロス"),
        .name = SPECIES_NAME("METAGROSS ", "METALOSSE ", "METAGROSS "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGIROCK] = {
        .speciesIdRS = 401,
        .nameJapanese = __("レジロック"),
        .name = SPECIES_NAME("REGIROCK  ", "REGIROCK  ", "REGIROCK  "),
        .catchIndex = 74,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGICE] = {
        .speciesIdRS = 402,
        .nameJapanese = __("レジアイス"),
        .name = SPECIES_NAME("REGICE    ", "REGICE    ", "REGICE    "),
        .catchIndex = 75,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGISTEEL] = {
        .speciesIdRS = 403,
        .nameJapanese = __("レジスチル"),
        .name = SPECIES_NAME("REGISTEEL ", "REGISTEEL ", "REGISTEEL "),
        .catchIndex = 76,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIAS] = {
        .speciesIdRS = 407,
        .nameJapanese = __("ラティアス"),
        .name = SPECIES_NAME("LATIAS    ", "LATIAS    ", "LATIAS    "),
        .catchIndex = 77,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIOS] = {
        .speciesIdRS = 408,
        .nameJapanese = __("ラティオス"),
        .name = SPECIES_NAME("LATIOS    ", "LATIOS    ", "LATIOS    "),
        .catchIndex = 78,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KYOGRE] = {
        .speciesIdRS = 404,
        .nameJapanese = __("カイオーガ"),
        .name = SPECIES_NAME("KYOGRE    ", "KYOGRE    ", "KYOGRE    "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GROUDON] = {
        .speciesIdRS = 405,
        .nameJapanese = __("グラードン"),
        .name = SPECIES_NAME("GROUDON   ", "GROUDON   ", "GROUDON   "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RAYQUAZA] = {
        .speciesIdRS = 406,
        .nameJapanese = __("レックウザ"),
        .name = SPECIES_NAME("RAYQUAZA  ", "RAYQUAZA  ", "RAYQUAZA  "),
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_JIRACHI] = {
        .speciesIdRS = 409,
        .nameJapanese = __("ジラーチ　"),
        .name = SPECIES_NAME("JIRACHI   ", "JIRACHI   ", "JIRACHI   "),
        .catchIndex = 79,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIKORITA] = {
        .speciesIdRS = 152,
        .nameJapanese = __("チコリータ"),
        .name = SPECIES_NAME("CHIKORITA ", "GERMIGNON ", "ENDIVIE   "),
        .catchIndex = 80,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CYNDAQUIL] = {
        .speciesIdRS = 155,
        .nameJapanese = __("ヒノアラシ"),
        .name = SPECIES_NAME("CYNDAQUIL ", "HERICENRE ", "FEURIGEL  "),
        .catchIndex = 81,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TOTODILE] = {
        .speciesIdRS = 158,
        .nameJapanese = __("ワニノコ　"),
        .name = SPECIES_NAME("TOTODILE  ", "KAIMINUS  ", "KARNIMANI "),
        .catchIndex = 82,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AERODACTYL] = {
        .speciesIdRS = 142,
        .nameJapanese = __("プテラ　　"),
        .name = SPECIES_NAME("AERODACTYL", "PTERA     ", "AERODACTYL"),
        .catchIndex = 83,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
};
