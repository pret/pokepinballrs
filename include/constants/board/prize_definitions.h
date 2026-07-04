#ifndef PRIZE_DEFINITIONS_H
#define PRIZE_DEFINITIONS_H

//Values used for both Roulette and shop

#define    PRIZE_30_SEC_BALL_SAVER 0
#define    PRIZE_60_SEC_BALL_SAVER 1
#define    PRIZE_90_SEC_BALL_SAVER 2
#define    PRIZE_PICHU_SAVER 3
#define    PRIZE_EXTRA_BALL 4
#define    PRIZE_SMALL_POINT_BONUS 5
#define    PRIZE_BIG_POINT_BONUS 6
#define    PRIZE_RANDOM_BONUS_MULTIPLIER 7
#define    PRIZE_START_CATCH_MODE 8
#define    PRIZE_START_EVO_MODE 9

//Note: A/B/C ball upgrades are equivalent upgrade 1 level
#define    PRIZE_BALL_UPGRADE_BASE 10
#define    PRIZE_BALL_UPGRADE_A 10
#define    PRIZE_BALL_UPGRADE_B 11
#define    PRIZE_BALL_UPGRADE_C 12
#define    PRIZE_BALL_UPGRADE_TO_MASTER 13

//Note Prize 14-16 unused in shop/roulette; Ix referenced from 'gShopItemData' array.
#define    START_SLOT_CARD 14 // 'Start Slot' graphic
#define    GOTO_NEXT_CARD 15 // Goto next graphic (up arrow)
#define    TRAVEL_RAMP_INDICATOR_CARD 16 // Travel ramp indicator graphic

#define    PRIZE_10_COINS 17
#define    PRIZE_30_COINS 18
#define    PRIZE_50_COINS 19
#define    PRIZE_30_SEC_EXTRA_BONUS_STAGE_TIME 20
#define    PRIZE_JIRACHI_CATCH_MODE 21
#define    PRIZE_WISCASH_ACTIVE_SPHEAL_OPPORTUNITY 22
#define    PRIZE_PELIPPER_ACTIVE_SPHEAL_OPPORTUNITY 23
#define    PRIZE_1M_POINTS 24
#define    PRIZE_2M_POINTS 25
#define    PRIZE_3M_POINTS 26
#define    PRIZE_4M_POINTS 27
#define    PRIZE_5M_POINTS 28
#define    PRIZE_6M_POINTS 29
#define    PRIZE_7M_POINTS 30
#define    PRIZE_8M_POINTS 31
#define    PRIZE_9M_POINTS 32
#define    PRIZE_100_POINTS 33
#define    PRIZE_500_POINTS 34
#define    PRIZE_900_POINTS 35

#define    PRIZE_BONUS_MULT_PLUS_BASE 36
#define    PRIZE_BONUS_MULT_PLUS_1 36
#define    PRIZE_BONUS_MULT_PLUS_2 37
#define    PRIZE_BONUS_MULT_PLUS_3 38
#define    PRIZE_BONUS_MULT_PLUS_4 39
#define    PRIZE_BONUS_MULT_PLUS_5 40

// Note: 41-45 all start the currently available mode.
// This controls Dusclops/Kecleon/Kyogre/Groudon/Rayquaza
#define    PRIZE_START_BONUS_MODE_ANY 41
#define    PRIZE_START_BONUS_MODE_DUSKULL 41
#define    PRIZE_START_BONUS_MODE_KECLEON 42
#define    PRIZE_START_BONUS_MODE_KYOGRE 43
#define    PRIZE_START_BONUS_MODE_GROUDON 44
#define    PRIZE_START_BONUS_MODE_RAYQUAZA 45

// Confirmation panels not used for prize wheel; Ix referenced from 'gShopItemData' array.
#define    CONFIRM_BONUS_GAME_START 46
#define    CONFIRM_TRAVEL_MOVE 47

#endif // PRIZE_DEFINITIONS_H