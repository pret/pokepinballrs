#ifndef GUARD_CONSTANTS_BG_MUSIC_H
#define GUARD_CONSTANTS_BG_MUSIC_H

#define MUS_TITLE                   0x01  // BGM 1
#define MUS_EMPTY_0x02              0x02  // No sound
#define MUS_TABLE_SELECT            0x03  // BGM 2
#define MUS_EMPTY_0x04              0x04  // No sound
#define MUS_EREADER                 0x05  // BGM 3
#define MUS_UNKNOWN_0x6             0x06  // Unused Credits theme? (starts like a subdued pokedex theme)
#define MUS_OPENING                 0x08  // BGM 4
#define MUS_HIGH_SCORE              0x09  // BGM 5
#define MUS_EMPTY_0x0A              0x0A  // No sound
#define MUS_SHOP                    0x0B  // BGM 7
#define MUS_SLOTS_PRIZE             0x0C  // BGM 8
#define MUS_END_OF_BALL             0x0D  // BGM 9
#define MUS_BONUS_CHANCE            0x0E  // BGM 10
#define MUS_BONUS_CHANCE_LEGENDARY  0x0F  // BGM 11
#define MUS_TRAVEL_MODE_START       0x10  // BGM 12 RS: TM/HM Obtained
#define MUS_SUCCESS                 0x11  // BGM 13
#define MUS_SUCCESS2                0x12  // Copy of MUS_SUCCESS?
#define MUS_END_OF_BALL2            0x13  // Copy of MUS_END_OF_BALL?
#define MUS_PRIZE_AWARDED           0x14  // BGM 14 Purchase/roulette prize; RS: Item Obtained
#define MUS_EGG_MODE                0x15  // BGM 15 RS: Encounter! (Twins)
#define MUS_EGG_MODE_START          0x16  // BGM 16 RS: Trick House
#define MUS_TRAVEL_MODE             0x17  // BGM 17
#define MUS_UNKNOWN_0x18            0x18  // RS: Battle! (Elite Four)
#define MUS_HURRY_UP                0x19  // BGM 18 RS: Prof. Birch in trouble
#define MUS_EVOLUTION               0x1A  // BGM 19
#define MUS_EMPTY_0x1B              0x1B  // No sound
#define MUS_FIELD_RUBY              0x1C  // BGM 20
#define MUS_CATCH_EM_MODE           0x1D  // BGM 21
#define MUS_EVO_MODE                0x1E  // BGM 22 (31) RS: Encounter! (Champion Steven)
#define MUS_EMPTY_0x1F              0x1F  // No sound
#define MUS_FIELD_SAPPHIRE          0x20  // BGM 24
#define MUS_CATCH_EM_MODE2          0x21  // BGM 25
#define MUS_EVO_MODE2               0x22
#define MUS_EMPTY_0x23              0x23  // No sound
#define MUS_BONUS_FIELD_KECLEON     0x24  // BGM 27
#define MUS_BONUS_FIELD_DUSKULL     0x25  // BGM 28
#define MUS_BONUS_FIELD_DUSCLOPS    0x26  // BGM 29
#define MUS_BONUS_FIELD_SPHEAL      0x27  // BGM 30
#define MUS_BONUS_FIELD_GROUDON     0x28  // BGM 31
#define MUS_BONUS_FIELD_KYOGRE      0x29  // BGM 32
#define MUS_BONUS_FIELD_RAYQUAZA    0x2A  // BGM 33
#define MUS_SUCCESS3                0x2B  // Copy of MUS_SUCCESS? (used in bonus fields)
#define MUS_END_OF_BALL3            0x2C  // Copy of MUS_END_OF_BALL? (used in bonus fields)
#define MUS_EMPTY_0x2D              0x2D  // No sound
#define MUS_POKEDEX                 0x2E  // BGM 6 RS: Evergrande City
#define MUS_JIRACHI                 0x2F  // BGM 34 RS: Hall of Fame

#define MUS_FIELD_RUBY2             0x5B  // BGM 23  Ruby Field background music after beating (not catching) Rayquaza
#define MUS_FIELD_SAPPHIRE2         0x5C  // BGM 26 Sapphire Field background music after beating (not catching) Rayquaza
#define MUS_UNKNOWN_0x5D            0x5D  // Unused bonus/boss fight? (Deoxys?)

#define SE_MENU_SELECT              0x65 // SE 1 Menu Selection; RS: PokéNav turn on
#define SE_MENU_CANCEL              0x66 // SE 2 Menu Cancel; RS: PokéNav turn off
#define SE_MENU_MOVE                0x67 // SE 3 Menu Momevent
#define SE_MENU_POPUP_OPEN          0x68 // SE 4; Yellow window popup appears (eg: pokedox transfer confirmation)
#define SE_MENU_POPUP_CLOSE         0x69 // SE 5; Yellow window popup disappears (eg: pokedox transfer confirmation)
#define SE_SCORE_ENTRY_A_B_MOVE     0x6A // SE 6; Drum?
#define SE_SCORE_ENTRY_LETTER_CHANGE 0x6B // SE 7; RS: Pokédex scroll
#define SE_UNUSED_0x6C              0x6C // Unused: RS: Bike hop
#define SE_DEX_INFO_FIELD_SELECT_MOVE 0x6D // SE 8; bonus/normal field selection, dex info page
#define SE_UNUSED_0x6E              0x6E // Unused: same as SE1
#define SE_UNUSED_0x6F              0x6F // Unused: same as SE2
#define SE_EMPTY_0x70               0x70 // No Sound
#define SE_UNKNOWN_0x71             0x71 // SE 180, Otherwise unused. Duplicated of SE 70 *thwip*
#define SE_FLIPPER_PRESSED          0x72 // SE9 Flipper
#define SE_SLINGSHOT_HIT            0x73 // SE10 Triangle bumper hit
#define SE_POKEMON_CATCH_HIT        0x74 // SE11 Pokemon Catch hit
#define SE_PICHU_IN_POSITION_CHIRP  0x75 // SE12 *high chirp*
#define SE_TRIGGER_BUTTON_HIT       0x76 // SE13 Trigger button hit
#define SE_WALL_HIT                 0x77 // SE14 ball hits wall
#define SE_TILT_TRIGGERED           0x78 // SE15 *metal gate bounce?*
#define SE_PIKA_SPINNER_CLACK       0x79 // SE16 *ball flat clack*
#define SE_PIKA_FULL_CHARGE_1_UP    0x7A // SE17 *high trill - radar*
#define SE_UNKNOWN_0x7B             0x7B // SE18 Otherwise unused. Sustained machine noise. - Same as 95
#define SE_KICKBACK_THUNDERWAVE     0x7C // SE19 *extended stable electric tone* (SE153 has a short form)
#define SE_UNUSED_0x7D              0x7D // ?? *Kerplunk* ??
#define SE_COIN_COLLECTED           0x7E // SE20 Same as SE1
#define SE_UNUSED_0x7F              0x7F // ?? Questioning Cry??
#define SE_CENTER_HOLE_EJECT        0x80 // SE21 *flying slash*
#define SE_ROULETTE_TICK            0x81 // SE22 *Pokeball hit ground; low pitched related to SE47*
#define SE_EVO_SELECTION_MOVE       0x82 // SE23 Evo Selection list move
#define SE_EVO_SELECTION_CONFIRM    0x83 // SE24 Evo Selection confirmed
#define SE_EVO_ITEM_APPEAR          0x84 // SE25 Evo Symbol Spawned; Ball Respawn - Bonus board
#define SE_EVO_ITEM_FINISH_APPEAR   0x85 // SE26 Evo Symbol finished spawning (Same as SE43)
#define SE_EVO_ITEM_COLLECTED       0x86 // SE27 Evo Symbol collected
#define SE_BALL_UPGRADE             0x87 // *SE28 *Pokeball/power upgrade? *
#define SE_UNUSED_0x88              0x88 // ?? *Downward compliment to SE28* ??
#define SE_UNUSED_0x89              0x89 // ?? *Coin collect*??
#define SE_FAILURE                  0x8A // SE29 Denied. ('Unable to select' in pokedex)
#define SE_CATCH_EVO_BANNER         0x8B // SE30 Evo/Catch mode initiated
#define SE_CATCH_TILE_REVEAL        0x8C // SE31 Catch Tile Revealed (Same as 114, 129, 139, 151)
#define SE_CATCH_ALL_REVEAL_LIGHTNING 0x8D // SE32 *Descending roar*
#define SE_CATCH_ALL_REVEAL_SHATTER 0x8E // SE33 *Vibrating ting*
#define SE_SHOP_LIST_REVEAL         0x8F // SE34 *drum brush*
#define SE_EMPTY_0x90               0x90 // No Sound
#define SE_BONUS_SCORE_TALLIED      0x91 // SE35 Bonus point tally finished; RS: Pokédex page change
#define SE_HATCH_FLOURISH           0x92 // SE36 Egg hatched flourish*
#define SE_AREA_ROULETTE_SELECTED   0x93 // SE37 Duplicate of SE1 Menu Selection; RS: PokéNav turn on
#define SE_BALL_SAVED               0x94 // SE38 Ball Sunk sound *Pokemon leaves ball/escape?* Same as SE163
#define SE_LATI_DELIVERY            0x95 // SE39 Latias/Latios delivers ball to plunger
#define SE_SAVER_PLUNGER_DROP       0x96 // SE40 Launcher catches ball
#define SE_TRAVEL_PAINTER_FLIGHT    0x97 // SE41 Volbeat/Illumise flight
#define SE_TRAVEL_PAINTER_PAINTS    0x98 // SE42 Volbeat/Illumise painting new travel board
#define SE_EVO_GET_ARROW_EARNED     0x99 // *SE43 Evo/Get Arrow earned - Duplicate of SE26S
#define SE_MON_CATCH_BALL_WOOSH     0x9A // *SE44 Pokemon being absorbed into ball (when catching)
#define SE_MON_CATCH_ENERGY_BEAM    0x9B // SE45 *gusty wind landing*
#define SE_MON_CATCH_BALL_CLOSE     0x9C // SE46 Pokemon entered Pokeball (when catching)
#define SE_MON_CATCH_BALL_HIT_GROUND 0x9D // SE47 Pokeball hit ground; High pitched related to 22
#define SE_MON_CATCH_BALL_SHAKE     0x9E // SE48 Pokeball shake, During catch confirmation
#define SE_WARP                     0x9F // SE49 *Up warp?*
#define SE_UNUSED_0xA0              0xA0 // ?? *Downward complement to SE49* ??
#define SE_BALL_SUMMARY_TEXT_PROGRESS 0xA1 // SE50 *hit clack*
#define SE_BALL_SUMMARY_PAGE_SWIPE  0xA2 // SE51 *Brush*
#define SE_PAUSE_CURSOR_MOVE        0xA3 // SE52 Duplicate of SE3; Coins collected?
#define SE_BONUS_PANEL_SLIDE        0xA4 // SE53 Duplicate of SE41
#define SE_PAUSING                  0xA5 // SE54 Duplicate of SE01; Menu Selection
#define SE_UNPAUSING                0xA6 // SE55 Duplicate of SE02; Menu Cancel
#define SE_CATCH_MON_ENTITY_APPEARS 0xA7 // SE56 *Pokeball Escape? *
#define SE_PIKA_CHARGE_DO           0xA8 // SE57 Do (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_PIKA_CHARGE_RE           0xA9 // SE58 Re (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_PIKA_CHARGE_MI           0xAA // SE59 Mi (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_PIKA_CHARGE_FA           0xAB // SE60 Fa (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_PIKA_CHARGE_SO           0xAC // SE61 So (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_PIKA_CHARGE_LA           0xAD // SE62 La (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_PIKA_CHARGE_TI           0xAE // SE63 Ti (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_PIKA_CHARGE_HIGH_DO      0xAF // SE64 Do (Title pokemon pinball logo tones / ramp spin pikachu charger)
#define SE_EVO_CUTSCENE_MON_PORTRAIT_CHANGE 0xB0 // SE65 *extended flight takeoff*
#define SE_PIKACHU_KICKBACK         0xB1 // SE181 Pi~Ka CHU!
#define SE_PICHU_KICKBACK_ENABLED   0xB2 // SE182 Pika - pika - pi-ka
#define SE_PICHU_KICKBACK           0xB3 // SE183 Pi~ Chu!
#define SE_UNUSED_0xB4              0xB4 // ?? Duplicate of SE49; Unused
#define SE_EMPTY_0xB5               0xB5 // No Sound
#define SE_RUBY_BUMPER_HIT          0xB6 // SE66 *Puddle slap* (Hit lotad/chinchou/whiscash)
#define SE_CYNDAQUIL_EGG_GUARD_HIT  0xB7 // SE67 *Spring Gate Bounce*
#define SE_AERODACTYL_EGG_FLIGHT    0xB8 // SE68 *Slap*
#define SE_CYNDAQUIL_BALL_EJECT_AFTER_EGG_ARRIVAL 0xB9 // SE69 *Fall into water*
#define SE_UNUSED_0xBA              0xBA // *Ground thud*
#define SE_UNUSED_0xBB              0xBB // *Landing*
#define SE_UNUSED_0xBC              0xBC // *Dumpster lid*
#define SE_RUBY_MART_GATE_OPEN      0xBD // SE 70 Ruby board Pokemart gate open
#define SE_UNUSED_0xBE              0xBE // *5 note rise*
#define SE_UNUSED_0xBF              0xBF // *5 note fall*
#define SE_UNUSED_0xC0              0xC0 // *Duplicate of SE66*
#define SE_UNUSED_0xC1              0xC1 // *Duplicate of SE88*
#define SE_SHARPEDO_BALL_EJECT      0xC2 // SE71 Ruby board Sharpedo spit ball
#define SE_SHOP_EJECT               0xC3 // SE72 Duplicate of SE70?
#define SE_UNUSED_0xC4              0xC4 // *Explosive at water surface*
#define SE_MAKUHITA_PUNCH           0xC5 // SE73 *Jump off tin clatter*
#define SE_CHIKORITA_LEAF_BLADE     0xC6 // SE74 Chikorita leaf blades
#define SE_ZIGZAGOON_EMERGE         0xC7 // SE75 Zigzagoon emerge
#define SE_RUBY_BUMPER_EMERGES      0xC8 // SE76 Ruby Pond Contents change; Duplicate of 66
#define SE_RUBY_BUMPER_LEAVES       0xC9 // SE77 Ruby Pond Chinchou leave
#define SE_RUBY_MART_SIGN_CHANGED   0xCA // SE78 *flipper 2?*
#define SE_UNUSED_0xCB              0xCB // Duplicate of SE70/SE72; Unused
#define SE_SPOINK_LAUNCHER_CHARGED  0xCC // SE79 *tong vwii vwii vwii*
#define SE_SPOINK_LAUNCHER_FIRED    0xCD // SE80 *Metal coin gate*
#define SE_SHARPEDO_BITE            0xCE // SE81 *Springy landing thud*
#define SE_NUZLEAF_HIT              0xCF // SE82 Duplicate of SE66
#define SE_NUZLEAF_TEETERING        0xD0 // SE83 *Chirp*
#define SE_NUZLEAF_FORMS_BRIDGE     0xD1 // SE84 *Flat board hit ground*
#define SE_GULPIN_LANDS_OR_LEAVES   0xD2 // SE85 Shroomish hit; Duplicate of SE66
#define SE_WHISCASH_EMERGE_SPLASH   0xD3 // SE86 *Wave shot*
#define SE_WHISCASH_LEAVE_BURBLE    0xD4 // SE87 *Swamp frog bubbling*
#define SE_WHISCASH_CATCH_BALL      0xD5 // SE88 *Smaller puddle slap* // Also used for *something* in the sapphire board
#define SE_WHISCASH_SPIT_BALL       0xD6 // SE89 *Juicy slash* // Also used for *something* in the sapphire board
#define SE_WHISCASH_SPLASHDOWN      0xD7 // SE90 *Explosive splash* (mostly buried under earthquake)
#define SE_RAMP_PRIZE_COLLECTED     0xD8 // SE91 *Ti-ring* RS: Exp. Bar filled up
#define SE_EMPTY_0xD9               0xD9 // No Sound
#define SE_EMPTY_0xDA               0xDA // No Sound
#define SE_EMPTY_0xDB               0xDB // No Sound
#define SE_HATCH_MACHINE_SPINNER_TRIGGER 0xDC // SE92 Sapphire Hatch Machine Spinner
#define SE_MON_LANDS_ON_HATCH_MACHINE_TOP 0xDD // SE93 Sapphire Hatched Pokemon Lands
#define SE_HATCH_MACHINE_STAGE_ADVANCE 0xDE // SE94 Sapphire Hatch machine Power up stage?
#define SE_HATCH_MACHINE_EGG_HATCH  0xDF // SE95 Sapphire board Hatch machine
#define SE_HATCH_MACHINE_ELEVATOR   0xE0 // SE96 Sapphire Lower Hatched Pokemon
#define SE_HATCH_MACHINE_ELEVATOR_TOP 0xE1 // SE97 *Close tailgate*
#define SE_PELIPPER_BALL_GRAB       0xE2 // *SE98 *Water 3*
#define SE_PELIPPER_WING_FLAP       0xE3 // SE99 Duplicate of SE68
#define SE_PELIPPER_SWOOSH          0xE4 // SE100 *Bird Cry*
#define SE_PELIPPER_BALL_DROP_LANDS 0xE5 // SE101 Duplicate of SE70
#define SE_SAPPHIRE_MART_GATE_TRIGGER 0xE6 // SE102 *Footstep on wood floor*
#define SE_SAPPHIRE_MART_GATE_REPLACED 0xE7 // SE103 *Sh-ting*
#define SE_SAPPHIRE_MART_GATE_HIT   0xE8 // SE104 Sapphire electric gate *short stable electric buzz Higher pictched than SE 153*
#define SE_SEEDOT_FALLING           0xE9 // SE105 Seedot drops into basket
#define SE_SEEDOT_LANDS             0xEA // SE106 Seedot lands in basket
#define SE_SEEDOT_LEAVES            0xEB // SE107 *Rubber Mallet Thwack*
#define SE_ZIGZAGOON_ROULETTE_STOP             0xEC // SE108 Duplicate of SE80
#define SE_EMPTY_0xED               0xED // No Sound
#define SE_EMPTY_0xEE               0xEE // No Sound
#define SE_EMPTY_0xEF               0xEF // No Sound
#define SE_EPMTY_0xF0               0xF0 // No Sound
#define SE_DUSKULL_APPEAR           0xF1 // SE109 Dusclops stage start, and Duskull hit (same as 119)
#define SE_DUSKULL_DEATH_CRY        0xF2 // SE110 Duskull death cry
#define SE_DUSCLOPS_DEPART_INCOMPLETE  0xF3 // SE111 Duskull leaves, unhit
#define SE_DUSCLOPS_MOVE            0xF4 // SE112 Dusclops entry, footsteps
#define SE_DUSCLOPS_APPEAR          0xF5 // SE113 Dusclops appears
#define SE_DUSCLOPS_HIT             0xF6 // SE114 Dusclops Hit (same as 31, 129, 139, 151)
#define SE_DUSCLOPS_BALL_ABSORB     0xF7 // SE115 Dusclops absorbs ball
#define SE_DUSCLOPS_BALL_LAUNCH     0xF8 // SE116 Dusclops launch absorbed ball
#define SE_BONUS_BOARD_BALL_SPAWN   0xF9 // SE117
#define SE_UNUSED_0xFA             0xFA // *Muted Triangle tripple tap*
#define SE_EMPTY_0xFB               0xFB // No Sound
#define SE_KECLEON_SIDE_LOOK        0xFC // *SE118 Kecleon looks side (same as SE84) // also with collecting 1 up
#define SE_KECLEON_VANISH           0xFD // *SE119 Kecleon Vanish (same as 109)
#define SE_KECLEON_STARTLED         0xFE // *SE120 Kecleon found exclamation
#define SE_KECLEON_RUNNING          0xFF // *SE121 Kecleon walk
#define SE_KECLEON_KNOCKED_OVER     0x100 // *SE122 Kecleon trip
#define SE_KECLEON_HIT_DAMAGED      0x101 // *SE123 Kecleon hit
#define SE_KECLEON_HITS_GROUND_DEFEATED 0x102 // *SE124 Kecleon hits ground; Duplicate of 97
#define SE_KECLEON_SEEING_STARS     0x103 // *SE125 Kecleon surrenders
#define SE_KECLEON_TREE_HIT         0x104 // SE126 Kecleon tree hit
#define SE_KECLEON_SCOPE_FALL       0x105 // SE127 Package falls from tree; Duplicate of 105
#define SE_KECLEON_SCOPE_ACTIVATED  0x106 // SE128 Scope initiates
#define SE_EMPTY_0x107              0x107 // No Sound
#define SE_EMPTY_0x108              0x108 // No Sound
#define SE_EMPTY_0x109              0x109 // No Sound
#define SE_KYOGRE_HIT               0x10A // *SE129 Kyogre Hit
#define SE_KYOGRE_BREACH_SURFACE    0x10B // *SE130 Kyogre Emerges / 'jumps'
#define SE_KYOGRE_DIVE              0x10C // *SE131 Kyogre Dives / jump landing
#define SE_KYOGRE_SPAWN_WHIRLPOOL   0x10D // *SE132 Kyogre Create Whirlpool
#define SE_KYOGRE_FREEZE_RING       0x10E // *SE133 Kyogre Ice Breath ring
#define SE_KYOGRE_DEPARTS           0x10F // *SE134
#define SE_KYOGRE_FREEZE_HITS_BALL  0x110 // SE135 Kyrogre freezes ball
#define SE_KYOGRE_FREEZE_CRACK      0x111 // SE136 Freeze escape hit
#define SE_KYOGRE_FREEZE_ESCAPED    0x112 // SE137 
#define SE_KYOGRE_WHIRLPOOL_GRABS_BALL 0x113 // SE138 Whirlpool catches ball
#define SE_EMPTY_0x114              0x114 // No Sound
#define SE_EMPTY_0x115              0x115 // No Sound
#define SE_EMPTY_0x116              0x116 // No Sound
#define SE_EMPTY_0x117              0x117 // No Sound
#define SE_GROUDON_HIT              0x118 // *SE139 Groudon Hit (Same as 31, 114, 129, 151)
#define SE_GROUDON_STEP             0x119 // SE140 Groudon Step
#define SE_GROUDON_INTRO_LEAP       0x11A // SE141 (plays after 3 steps, last sound before he lands in the arena)
#define SE_GROUDON_LANDS            0x11B // *SE142 Groudon Lands
#define SE_GROUDON_SPITS_FIRE       0x11C // *SE143 *??Lava Splash?*
#define SE_GROUDON_FIRE_RING        0x11D // *SE144 Groudon Fire Ring
#define SE_GROUDON_FIRE_GRAB_RESIST 0x11E // SE145 (Escape hit from the fire grab... doesn't *sound*/behave like a hit?)
#define SE_GROUDON_FIRE_GRAB        0x11F // *SE146 Plays with SE 147 when fireball hits pinball - burn sound
#define SE_GROUDON_FIREBALL_CONNECTS 0x120 // SE147 Plays with SE 146 when fireball hits pinball - hit sound
#define SE_GROUDON_BOULDER_LAND     0x121 // SE148 Groudon Boulders Land/Hit
#define SE_GROUDON_DUSTORM_LIFT     0x122 // SE149 *Ground duststorm lift*
#define SE_GROUDON_BALL_HIT_FIRE    0x123 // SE150 Ball hit Groudon Fire
#define SE_EMPTY_0x124              0x124 // No Sound
#define SE_EMPTY_0x125              0x125 // No Sound
#define SE_RAYQUAZA_HIT             0x126 // SE151 Rayquaza Hit (Same as 31, 114, 129, 139)
#define SE_RAYQUAZA_WIND            0x127 // SE152 *Wind noise*
#define SE_RAYQUAZA_LIGHTNING_CHARGE 0x128 // SE153 *Short stable electric tone* (SE19 has long form)
#define SE_RAYQUAZA_FLYBY           0x129 // SE154 Rayquaza flyby
#define SE_RAYQUAZA_LIGHTNING_TRAP  0x12A // SE155 Initial hit and Escape hit from ball trapped by lightning
#define SE_RAYQUAZA_WHIRLWIND_BALL_LAUNCH 0x12B // SE156 Ball Launched by Rayquaza Tornado
#define SE_RAYQUAZA_WHIRLWIND_BALL_LAND 0x12C // SE157 Ball Lands after launch
#define SE_RAYQUAZA_SONIC_BOOM      0x12D // SE158 *Wall crashes after flyby?*
#define SE_RAYQUAZA_STAGE_WIND      0x12E // SE159 Stage wind for Rayquaza bonus stage.
#define SE_EMPTY_0x12F              0x12F // No Sound
#define SE_EMPTY_0x130              0x130 // No Sound
#define SE_EMPTY_0x131              0x131 // No Sound
#define SE_EMPTY_0x132              0x132 // No Sound
#define SE_EMPTY_0x133              0x133 // No Sound
#define SE_SPHEAL_SURFACING         0x134 // SE160 *splash?*
#define SE_SPHEAL_SUBMERGING        0x135 // SE161 *deeper splash*
#define SE_SPHEAL_SUBMERGE_AFTER_SCORING 0x136 // SE162 *water engulf*
#define SE_SPHEAL_HIT               0x137 // *SE163 *Pokemon leaves ball/escape?* Same as 38
#define SE_SPHEAL_NET_SWOOSH        0x138 // *SE164 *Snare brush*
#define SE_SPHEAL_CROWD_CHEER       0x139 // *SE165 *Crowd cheer*
#define SE_EMPTY_0x13A              0x13A // No Sound
#define SE_SPHEAL_END_WHISTLE       0x13B // *SE166 *Traffic whistle two blast*
#define SE_SEALEO_HIT_THUD          0x13C // *SE167 Hit Sealeo in bonus game *Thud*
#define SE_SEALEO_NOSE_BOUNCE       0x13D // *SE168 Sealeo nose bounce in bonus game (Same as 169)
#define SE_SPHEAL_LAND_UNDER_NET    0x13E // SE169 Sealeo nose bounce in bonus game (Same as 168)
#define SE_UNUSED_0x13F            0x13F // unused: *coin*
#define SE_SPHEAL_SURFACE_AT_RAMP   0x140 // SE170 Spheal emerges from water
#define SE_EMPTY_0x141              0x141 // No Sound
#define SE_PIKA_NO_KICKBACK         0x142 // *SE184 Pika!
#define SE_EMPTY_0x143              0x143 // No Sound
#define SE_JIRACHI_MOVE             0x144 // SE171 *Chime*
#define SE_JIRACHI_HIT              0x145 // SE172 *Rising success whistle*
#define SE_TOTODILE_LOWERS_ROPE     0x146 // SE173 Totodile egg delivery, lowers rope
#define SE_TOTODILE_SLIDES_DOWN     0x147 // SE174 Totodile egg delivery, slides down rope (Same as SE39)
#define SE_TOTODILE_PLACES_EGG      0x148 // SE175 Totodile egg delivery, places egg
#define SE_TOTODILE_CLIMBS_ROPE     0x149 // SE176 Totodile egg delivery, climbs rope
#define SE_HIGHEST_SCORE_EARNED     0x14A // SE178 High Score Earned (#1)
#define SE_HIGH_SCORE_EARNED        0x14B // SE179 High Score Earned (#2 -#8) Duplicate of 36 
#define SE_WHISCASH_EARTHQUAKE      0x14C // SE177 *rumble*

#endif // GUARD_CONSTANTS_BG_MUSIC_H
