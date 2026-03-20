#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include "gba/gba.h"

#include "types.h"
#include "functions.h"
#include "variables.h"
#include "constants/global.h"
#include "constants/ereader.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")
#define NAKED __attribute__((naked))

// IDE support
#if defined (__APPLE__) || defined (__CYGWIN__) || defined (_MSC_VER)
#define _(x) x
#define __(x) x
#define INCBIN_U8 {0}
#define INCBIN_U16 {0}
#define INCBIN_U32 {0}
#define INCBIN_S8 {0}
#define INCBIN_S16 {0}
#define INCBIN_S32 {0}
#endif // IDE support

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) * 256))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((int)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((int)((n) / 4096))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((int)((n) >> 8))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

// TODO: define RGB(r, g, b) macro
#define RGB_WHITE 0x7FFF

// Macros for checking the joypad
#define TEST_BUTTON(field, button) ((field) & (button))
#define TEST_BUTTON_EXACT(field, button) (((field) & (button)) == (button))
#define JOY_NEW(button) TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button)  TEST_BUTTON(gMain.heldKeys, button)

#define MODE_CHANGE_NONE 0 // Used for If checks
#define MODE_CHANGE_BANNER        0x1  //2^0
#define MODE_CHANGE_PAUSE         0x2  //2^1
#define MODE_CHANGE_DEBUG         0x4  //2^2
#define MODE_CHANGE_BALL_SAVER    0x8  //2^3
#define MODE_CHANGE_END_OF_BALL   0x10 //2^4
#define MODE_CHANGE_END_OF_GAME   0x20 //2^5
#define MODE_CHANGE_EXPIRED_BONUS 0x40 //2^6
#define MODE_CHANGE_BONUS_BANNER  0x80 //2^7
#define MODE_CHANGE_EXPIRED_BONUS_BANNER 0xC0 // 2^6 + 2^7


struct BgOffsets
{
    u16 xOffset;
    u16 yOffset;
};

// This struct holds data about the ball's velocity, position, etc.
struct BallState
{
    /*0x00*/ s8 ballHidden;
    /*0x01*/ s8 oamPriority;
    /*0x02*/ u8 filler2[0x2];
    /*0x04*/ u16 spinAcceleration;
    /*0x06*/ s16 spinSpeed;
    /*0x08*/ s16 prevSpinSpeed;
    /*0x0A*/ u16 spinAngle;
    /*0x0C*/ u16 prevSpinAngle;
    /*0x0E*/ u16 scale;
    /*0x10*/ struct Vector16 positionQ0;
    /*0x14*/ struct Vector16 prevPositionsQ0[4];
    /*0x24*/ struct Vector16 screenPosition;
    /*0x28*/ struct Vector16 positionQ1;
    /*0x2C*/ struct Vector16 prevPositionQ1;
    /*0x30*/ struct Vector16 velocity;
    /*0x34*/ struct Vector32 positionQ8; // fixed-point Q_24_8 values
    /*0x3C*/ struct Vector32 prevPositionQ8;
};

// Position rises in steps of 2 from 0 to 10.
// Releasing the button continues rising till it reaches 10, and stalls for 3 frames before falling
struct FlipperState
{
    /*0x00*/ s8 position;
    /*0x01*/ s8 prevPosition;
    /*0x02*/ s8 collisionFrameIndex;
    /*0x03*/ s8 movementDirection;
    /*0x04*/ s8 bounceApplied;
    /*0x05*/ s8 collisionMapFrame;
    /*0x06*/ s8 active;
    /*0x07*/ u8 stallTicks;
    /*0x08*/ s8 ballSide;
    /*0x09*/ u8 filler9[0x3];
};

struct PinballGame
{
    /*0x000*/ u32 saveDataValid;
    /*0x004*/ u8 newButtonActions[5]; // e.g. player pressing the appropriate buttons to trigger the left flipper action, etc.
    /*0x009*/ u8 releasedButtonActions[5];
    /*0x00E*/ u8 heldButtonActions[5];
    /*0x013*/ s8 boardState; // Indexes into gBoardStateInitFuncs/gBoardStateUpdateFuncs dispatch tables (9 states)
    /*0x014*/ s8 nextBoardState; // Target state set by RequestBoardStateTransition
    /*0x015*/ s8 prevBoardState; // Previous state saved during dispatcher teardown
    /*0x016*/ s8 boardTransitionPhase; // 0=init, 1=update, 2=transition
    /*0x017*/ s8 boardSubState; // Sub-state switch variable within each board state handler
    /*0x018*/ u16 stageTimer; // Frame counter used across all board processes
    /*0x01A*/ s8 flippersDisabled;
    /*0x01B*/ u8 unk1B;
    /*0x01C*/ bool8 scoreCounterAnimationEnabled;
    /*0x01D*/ u8 fadeSubState;
    /*0x01E*/ u8 gravityStrengthIndex;
    /*0x01F*/ u8 ballFrozenState;
    /*0x020*/ u8 ballInLaunchChute;
    /*0x021*/ u8 launcherCharging;
    /*0x022*/ s8 collisionResponseType;
    /*0x023*/ u8 collisionSurfaceType; // Holds the value of some enum state
    /*0x024*/ s8 boardLayerDepth;
    /*0x025*/ s8 ballCatchState; // 0=Not caught, 1=Catch mode hole, 2=Egg Hatch Hole, 3=Evo Shop hole, 4=Center hole
    /*0x026*/ u16 collisionCooldownTimer;
    /*0x028*/ u16 modeAnimTimer;
    /*0x02A*/ u16 unk2A;
    /*0x02C*/ int cameraLookAhead;
    /*0x030*/ s8 numLives;
    /*0x031*/ u8 ballSpeed;
    /*0x032*/ s8 areaRouletteSlotIndex;
    /*0x033*/ s8 areaRouletteNextSlot;
    /*0x034*/ s8 areaRouletteFarSlot;
    /*0x035*/ s8 area;
    /*0x036*/ s8 areaVisitCount;
    /*0x038*/ u32 scoreAddStepSize; //score to add every frame until scoreAddedInFrame score has been added to player's total
    /*0x03C*/ u32 scoreAddedInFrame; //score to add in a bonus field or mode (by completion or other ways, like hitting Duskulls)
    /*0x040*/ u32 scoreAdditionAccumulator; //score left to be counted up on the score registers
    /*0x044*/ u32 scoreLo; //counts score until 99_999_999, overflows into scoreHi
    /*0x048*/ u32 scoreHi; //counts score until 9_999, then freezes total score to 999_999_999_999!
    /*0x04C*/ s16 cameraBaseX;
    /*0x04E*/ s16 cameraBaseY;
    /*0x050*/ u8 filler50[0x4];
    /*0x054*/ u32 cameraYQ8;
    /*0x058*/ u16 cameraXOffset;
    /*0x05A*/ u16 cameraYOffset;
    /*0x05C*/ s16 flipperLaunchPending;
    /*0x05E*/ u8 filler5E[0x2];
    /*0x060*/ struct Vector16 flipperLaunchVelocity;
    /*0x064*/ s16 ballLaunchSpeed;
    /*0x066*/ u16 activeBallIndex;
    /*0x068*/ s16 cameraYViewport;
    /*0x06A*/ s16 hudSpriteBaseY;
    /*0x06C*/ u16 timerBonus; //Additional time to be added to next timed event (Only for bonus fields or all timers?)
    /*0x06E*/ s8 ballShadowTileIndex;
    /*0x06F*/ s8 activePaletteIndex;
    /*0x070*/ s8 paletteSwapActive;
    /*0x071*/ s8 ballTrailEnabled;
    /*0x072*/ s8 jirachiActivationFlags;
    /*0x073*/ s8 jirachiWaypoint;
    /*0x074*/ u16 jirachiTagTimer[4];
    /*0x07C*/ u16 jirachiWaypointTimer;
    /*0x07E*/ u16 ballDeliveryActive;
    /*0x080*/ s16 jirachiLogicX;
    /*0x082*/ s16 jirachiLogicY;
    /*0x084*/ struct Vector16 jirachiStarTagPos[4];
    /*0x094*/ u8 filler94[0x28];
    /*0x0BC*/ s16 jirachiTargetX;
    /*0x0BE*/ s16 jirachiTargetY;
    /*0x0C0*/ s16 jirachiDisplayX;
    /*0x0C2*/ s16 jirachiDisplayY;
    /*0x0C4*/ u16 jirachiCenterX;
    /*0x0C6*/ u16 jirachiCenterY;
    /*0x0C8*/ u8 fillerC8[0x2];
    /*0x0CA*/ s16 scrollEffectX;
    /*0x0CC*/ s16 scrollEffectY;
    /*0x0CE*/ u16 unkCE;
    /*0x0D0*/ struct Vector16 ballTrailPosition[5];
    /*0x0E4*/ u8 activePortraitType;
    /*0x0E6*/ s16 cameraYAdjust;
    /*0x0E8*/ s16 cameraYScrollTarget;
    /*0x0EA*/ u16 bannerDelayTimer;
    /*0x0EC*/ u16 bannerDisplayTimer;
    /*0x0EE*/ s16 cameraYScrollSpeed;
    /*0x0F0*/ u16 bannerSlideTimer;
    /*0x0F2*/ s8 bannerGfxIndex;
    /*0x0F3*/ u8 unkF3;
    /*0x0F4*/ s16 bannerDisplayDuration;
    /*0x0F6*/ s16 bannerSlidePosition;
    /*0x0F8*/ s16 bannerSlideVelocity;
    /*0x0FA*/ s8 bannerActive;
    /*0x0FB*/ s8 bannerPreserveBallState;
    /*0x0FC*/ s16 bonusSummarySlideY;
    /*0x0FE*/ s16 ballSaverSlideY;
    /*0x100*/ s32 ballSaverPosX;
    /*0x104*/ s32 ballSaverPosY;
    /*0x108*/ s16 ballSaverVelX;
    /*0x10A*/ s16 ballSaverVelY;
    /*0x10C*/ s16 ballSaverBallVelX;
    /*0x10E*/ s16 ballSaverBallVelY;
    /*0x110*/ s32 ballSaverBallPosX;
    /*0x114*/ s32 ballSaverBallPosY;
    /*0x118*/ s8 tiltShakeAmplitude[4];
    /*0x11C*/ s8 tiltShakeVelocity[4];
    /*0x120*/ s8 tiltXOffset;
    /*0x121*/ s8 tiltYOffset;
    /*0x122*/ s8 tiltTargetXOffset;
    /*0x123*/ s8 tiltTargetYOffset;
    /*0x124*/ s8 tiltInputCounterX;
    /*0x125*/ s8 tiltInputCounterY;
    /*0x126*/ s8 tiltLockoutTimer;
    /*0x127*/ s8 tiltLockoutActive;
    /*0x128*/ u8 boardShakeIntensity;
    /*0x129*/ s8 boardShakeDirection;
    /*0x12A*/ u8 boardShakeTimer;
    /*0x12B*/ s8 forceSpecialMons;  // When on, force next catch mode species to be special mons
    /*0x12C*/ s8 forcePichuEgg;     // When on, force next egg mode species to be Pichu
    /*0x12D*/ u8 filler12D;
    /*0x12E*/ s16 totalWeight;       // Added weight of all possible mons in area
    /*0x130*/ s16 speciesWeights[25]; // Weight of each species
    /*0x162*/ s8 forcePondToWhiscash;
    /*0x163*/ s8 spoinkEntityState;
    /*0x164*/ s8 spoinkAnimFrameIx;
    /*0x165*/ s8 ballTouchingSpoink;
    /*0x166*/ u16 spoinkPullbackYDistance;
    /*0x168*/ u16 spoinkAnimFrameTimer;
    /*0x16A*/ s16 bannerSlideX;
    /*0x16C*/ s8 rubyPondState;
    /*0x16D*/ u8 filler16D[0x1];
    /*0x16E*/ s8 chinchouWaypointTarget;
    /*0x16F*/ s8 rubyPondContentsChanging;
    /*0x170*/ s8 pondBumperStates[3];
    /*0x173*/ u8 unk173;
    /*0x174*/ u16 rubyPondChangeTimer;
    /*0x176*/ u8 pondEntitySpriteFlag;
    /*0x177*/ u8 filler177[0x1];
    /*0x178*/ struct Vector16 rubyBumperLogicPosition[3]; //chinchou or lotad
    /*0x184*/ struct Vector16 rubyBumperCollisionPosition[3]; //chinchou or lotad
    /*0x190*/ s16 bumperOrbitRadius;
    /*0x192*/ u8 coins;
    /*0x193*/ s8 coinsAwarded;
    /*0x194*/ s8 coinRewardAmount;
    /*0x195*/ s8 coinRewardFastPayout;
    /*0x196*/ u16 coinRewardTimer;
    /*0x198*/ s16 coinBounceTimer[2];
    /*0x19C*/ struct Vector16 coinSpritePos[2];
    /*0x1A4*/ s8 shopTransitionActive;
    /*0x1A5*/ s8 evolutionShopActive;
    /*0x1A6*/ s8 shopItemCursor;
    /*0x1A7*/ s8 shopSelectedItemId;
    /*0x1A8*/ s8 shopSlideDirection;
    /*0x1A9*/ u8 shopBgAnimFrame;
    /*0x1AA*/ s8 shopPikaSaverMaxed;
    /*0x1AB*/ s8 shopDoorOpenLevel;
    /*0x1AC*/ s8 shopSignFrame;
    /*0x1AD*/ s8 shopSignPaletteIndex;
    /*0x1AE*/ u8 shopOutcomeRepeatCount;
    /*0x1AF*/ u8 shopBonusStageAlreadyBought;
    /*0x1B0*/ s8 evoNameSlideOnly;
    /*0x1B1*/ u8 filler1B1[0x1];
    /*0x1B2*/ u16 evoFormAlternateTimer;
    /*0x1B4*/ u16 shopAnimTimer;
    /*0x1B6*/ u16 shopUISlideOffset;
    /*0x1B8*/ s16 shopAnimSlideTimer;
    /*0x1BA*/ u16 shopEntryTimer;
    /*0x1BC*/ u16 randomSpriteVariantSeed;
    /*0x1BE*/ s8 pichuWalkMode; //1=entrance, 2=exit
    /*0x1BF*/ u8 filler1BF[0x1];
    /*0x1C0*/ u16 pichuEntranceTimer;
    /*0x1C2*/ s8 outLaneSide; // 1=Left; 2=Right
    /*0x1C3*/ u8 filler1C3[0x1];
    /*0x1C4*/ u16 pikaKickbackTimer;
    /*0x1C6*/ s16 pikaChargeTarget;
    /*0x1C8*/ s16 pikaChargeProgress;
    /*0x1CA*/ s16 chargeFillValue;
    /*0x1CC*/ s16 prevChargeFillValue;
    /*0x1CE*/ u16 chargeFillAnimTimer;
    /*0x1D0*/ u16 fullChargeSlideAnimTimer;
    /*0x1D2*/ u16 unk1D2;
    /*0x1D4*/ u16 chargeIndicatorXOffset;
    /*0x1D6*/ u16 chargeIndicatorYOffset;
    /*0x1D8*/ u16 chargeIndicatorScaleX;
    /*0x1DA*/ u16 chargeIndicatorScaleY;
    /*0x1DC*/ u16 fullChargeIndicatorBlinkTimer;
    /*0x1DE*/ u16 kickbackAnimProgress;
    /*0x1E0*/ u16 kickbackAnimDuration;
    /*0x1E2*/ s8 outLanePikaPosition; //Pikachu coverage. 0= left lane, 1=right lane, 2 = both
    /*0x1E3*/ s8 kickbackOccupied[2];
    /*0x1E5*/ s8 pikachuSpinFrame;
    /*0x1E6*/ s8 pikachuSpinPrevFrame;
    /*0x1E7*/ u8 filler1E7[0x1];
    /*0x1E8*/ s16 eggBasePosX;
    /*0x1EA*/ s16 eggBasePosY;
    /*0x1EC*/ s8 eggAnimationPhase;
    /*0x1ED*/ s8 eggAnimFrameIndex;
    /*0x1EE*/ s8 prevEggAnimFrame;
    /*0x1EF*/ u8 unk1EF;
    /*0x1F0*/ u16 eggFrameTimer;
    /*0x1F2*/ u8 unk1F2;
    /*0x1F3*/ u8 unk1F3;
    /*0x1F4*/ s16 portraitOffsetX;
    /*0x1F6*/ s16 portraitOffsetY;
    /*0x1F8*/ s16 walkMonXVelocity;
    /*0x1FA*/ s16 walkMonYVelocity;
    /*0x1FC*/ s32 walkMonXPos; // Used for both hatch mons, and for pichu kickback walk
    /*0x200*/ s32 walkMonYPos; // Used for both hatch mons, and for pichu kickback walk
    /*0x204*/ s8 creatureWaypointIndex; // Used for both hatch mons, and for pichu kickback walk
    /*0x205*/ u8 filler205[0x1];
    /*0x206*/ u16 waypointSubTimer;
    /*0x208*/ u16 kickbackAnimFrameTimer;
    /*0x20A*/ s8 kickbackFrameId;
    /*0x20B*/ s8 bonusTrapAnimFrame;
    /*0x20C*/ s8 prevBonusTrapFrame;
    /*0x20D*/ u8 filler20D[0x1];
    /*0x20E*/ s16 nameSpacingOffset;
    /*0x210*/ u16 nameRevealAnimFrame;
    /*0x212*/ u16 nameRevealDelays[10];
    /*0x228*/ struct Vector16 nameSlideRow1[10];
    /*0x250*/ u16 evoModeShuffleRound;
    /*0x252*/ u16 catchModeEventTimer;
    /*0x254*/ u8 filler254[0x4];
    /*0x258*/ s16 evoItemPosX;
    /*0x25A*/ s16 evoItemPosY;
    /*0x25C*/ s8 evoChainPosition;
    /*0x25D*/ s8 evoChainMaxStage;
    /*0x25E*/ s8 evoItemSlotIndex;
    /*0x25F*/ s8 evoItemGfxIndex;
    /*0x260*/ s8 evoShuffledSlots[3];
    /*0x263*/ s8 evoItemShufflePool[8];
    /*0x26B*/ s8 evoItemsCaught;
    /*0x26C*/ s8 evoModeResetFlag;
    /*0x26D*/ u8 filler26D[0x1];
    /*0x26E*/ u16 evoItemAppearTimer;
    /*0x270*/ u8 evolvablePartySpecies[MAX_EVOLVABLE_PARTY_SIZE];
    /*0x280*/ s8 evolvingPartyIndex;
    /*0x281*/ s8 evolvablePartySize;
    /*0x282*/ s8 bonusReturnState;
    /*0x283*/ u8 numCompletedBonusStages;
    /*0x284*/ s8 nextBonusField; // Bonus Field to transition to?
    /*0x285*/ u8 filler285[0x1];
    /*0x286*/ u16 oneUpAnimTimer;
    /*0x288*/ s16 catchTargetX;
    /*0x28A*/ s16 catchTargetY;
    /*0x28C*/ u8 filler28C[0x4];
    /*0x290*/ u32 globalAnimFrameCounter;
    /*0x294*/ s8 boardModeType;
    /*0x295*/ u8 unk295;
    /*0x296*/ u16 eventTimer; //Timer for events (Only bonus fields or all events?)
    /*0x298*/ u16 cutsceneTilemapColumn;
    /*0x29A*/ u16 catchEmModeStartCount;
    /*0x29C*/ u16 bgmFadeTimer;
    /*0x29E*/ u8 boardCollisionConfigChanged;
    /*0x29F*/ s8 rampPrizeType;
    /*0x2A0*/ u16 rampPrizeRespawnTimer;
    /*0x2A2*/ s8 whiscashState;
    /*0x2A3*/ s8 whiscashInvulnerable;
    /*0x2A4*/ s8 shouldProcessWhiscash;
    /*0x2A5*/ s8 whiscashFrameIx;
    /*0x2A6*/ u16 whiscashStateTimer;
    /*0x2A8*/ u16 pondSwitchesSinceLastWhiscash;
    /*0x2AA*/ u16 screenShakeX;
    /*0x2AC*/ s16 screenShakeY;
    /*0x2AE*/ u8 filler2AE[0x2];
    /*0x2B0*/ u16 chikoritaFlashTimer;
    /*0x2B2*/ s8 chikoritaFlashActive;
    /*0x2B3*/ u8 filler2B3[0x1];
    /*0x2B4*/ s16 chikoritaProjectileX;
    /*0x2B6*/ s16 chikoritaProjectileY;
    /*0x2B8*/ u16 chikoritaProjectileVelX;
    /*0x2BA*/ u16 chikoritaProjectileUnused;
    /*0x2BC*/ u16 chikoritaProjectileTimer;
    /*0x2BE*/ s8 gulpinCurrentLevel;
    /*0x2C0*/ u16 gulpinAnimFrameTimer;
    /*0x2C2*/ s8 gulpinAnimFrameIndex;
    /*0x2C3*/ s8 totodileDeliveryFrame;
    /*0x2C4*/ u16 totodileDeliveryTimer;
    /*0x2C6*/ u16 eggDropTimer;
    /*0x2C8*/ s16 eggDeliveryX;
    /*0x2CA*/ s16 eggDeliveryY;
    /*0x2CC*/ s16 eggDeliveryVelX;
    /*0x2CE*/ s16 eggDeliveryVelY;
    /*0x2D0*/ s8 rubyEggDeliveryState;
    /*0x2D1*/ u8 filler2D1[3];
    /*0x2D4*/ u16 cyndaquilCaveSpriteX;
    /*0x2D6*/ u16 cyndaquilCaveSpriteY;
    /*0x2D8*/ s8 cyndaquilCollisionEnabled;
    /*0x2D9*/ s8 eggCaveReEntryFlag;
    /*0x2DA*/ s8 eggCaveState;
    /*0x2DB*/ u8 filler2DB[0x3];
    /*0x2DE*/ u16 eggCaveLiftTimer;
    /*0x2E0*/ u16 eggCaveExitDelayTimer;
    /*0x2E2*/ s8 sideBumperHitFlag;
    /*0x2E3*/ s8 sideBumperBounceCount[2];
    /*0x2E5*/ s8 sideBumperAnimPhase[2];
    /*0x2E7*/ u8 filler2E7[0x1];
    /*0x2E8*/ u16 sideBumperAnimTimer[2];
    /*0x2EC*/ s16 sideBumperShakeOffset[2];
    /*0x2F0*/ u8 shopDoorTargetFrame;
    /*0x2F1*/ u8 shopDoorCurrentFrame;
    /*0x2F2*/ u16 shopDoorAnimDelay;
    /*0x2F4*/ s8 catchHoleAnimFrame; //Sharpedo/Wailmer Oam Ix
    /*0x2F5*/ s8 catchHoleTileVariant; //Sharpedo tile variant Ix
    /*0x2F6*/ u16 catchHolePauseTimer;
    /*0x2F8*/ s8 ballPowerUpOverride;
    /*0x2F9*/ s8 nuzleafPositionIndex;
    /*0x2FA*/ s8 nuzleafHitFlag;
    /*0x2FB*/ s8 nuzleafAnimState;
    /*0x2FC*/ s8 nuzleafGfxTileIndex;
    /*0x2FD*/ s8 nuzleafFrameIndex;
    /*0x2FE*/ u16 nuzleafFrameTimer;
    /*0x300*/ s8 rampGateState;
    /*0x301*/ s8 rampGateHitFlag;
    /*0x302*/ s8 rampPrizeVisibilityTimer;
    /*0x303*/ s8 unk303;
    /*0x304*/ u16 rampGateAnimCounter;
    /*0x306*/ s8 pelipperState;
    /*0x307*/ s8 pelipperSwallowAnimIndex;
    /*0x308*/ u16 bumperHitsSinceReset;
    /*0x30A*/ u16 pelipperSwallowSubTimer;
    /*0x30C*/ u16 pelipperFrameTimer;
    /*0x30E*/ s16 pelipperYBobOffset;
    /*0x310*/ s16 pelipperSfxTimer;
    /*0x312*/ u8 filler312[0x2];
    /*0x314*/ s16 pelipperBallDropVelX;
    /*0x316*/ s16 pelipperBallDropVelY;
    /*0x318*/ s16 pelipperBallDropPosX;
    /*0x31A*/ s16 pelipperBallDropPosY;
    /*0x31C*/ s16 pelipperFlyVelX;
    /*0x31E*/ s16 pelipperFlyVelY;
    /*0x320*/ s16 pelipperPosX;
    /*0x322*/ s16 pelipperPosY;
    /*0x324*/ s8 basketBounceFrame;
    /*0x325*/ u8 filler325[0x1];
    /*0x326*/ u16 basketBounceTimer;
    /*0x328*/ s8 seedotCollisionTrigger;
    /*0x329*/ u8 filler329[0x1];
    /*0x32A*/ u16 seedotDecayTimer;
    /*0x32C*/ s8 seedotState[3];
    /*0x32F*/ s8 seedotSpriteFrame[3];
    /*0x332*/ s8 seedotOamFramesetIndex[3];
    /*0x335*/ u8 filler335[0x1];
    /*0x336*/ u16 seedotAnimTimer[3];
    /*0x33C*/ u16 seedotYOffset[3];
    /*0x342*/ s8 hatchMachineActive; // Turns off while launching, Reenabled when ball touches ramp
    /*0x343*/ s8 sapphirerubyEggDeliveryState;
    /*0x344*/ s8 hatchMachineNewHit;
    /*0x345*/ s8 sapphireHatchMachineFrameIx;
    /*0x346*/ s8 sapphireHatchMachineState; // 0-6
    /*0x347*/ u8 filler347[0x1];
    /*0x348*/ u16 holeAnimFrameCounter;
    /*0x34A*/ s8 targetBumperHitCounter;
    /*0x34B*/ s8 targetBumperAnimTimers[10];
    /*0x355*/ s8 splashEffectFrameIndex[4];
    /*0x359*/ s8 splashEffectPositionIndex[4];
    /*0x35D*/ u8 filler35D[0x1];
    /*0x35E*/ u16 splashEffectFrameTimer[4];
    /*0x366*/ s8 shopShockWallAnimState;
    /*0x367*/ s8 eggHatchShockWallOverride;
    /*0x368*/ u16 shopBumperHitTimer;
    /*0x36A*/ s8 sapphireBumperState[2];
    /*0x36C*/ s8 sapphireBumperAnimKeyframe[2];
    /*0x36E*/ u16 sapphireBumperAnimSubTimer[2];
    /*0x372*/ u16 sapphireBumperHitFxTimer[2];
    /*0x376*/ u16 sapphireBumperLitCountdown;
    /*0x378*/ s8 zigzagoonState;
    /*0x379*/ s8 zigzagoonGfxFrame;
    /*0x37A*/ s8 zigzagoonOamFrame;
    /*0x37B*/ s8 zigzagoonFxFrame;
    /*0x37C*/ s8 zigzagoonShockWallActive;
    /*0x37D*/ s8 zigzagoonAnimKeyframeIndex;
    /*0x37E*/ u16 sapphireBumperAnimFrame;
    /*0x380*/ u16 sapphireBumperTimer;
    /*0x382*/ s8 bossPhaseCounter;
    /*0x383*/ s8 ballGrabbed;
    /*0x384*/ s8 legendaryHitsRequired;
    /*0x385*/ s8 bonusModeHitCount;
    /*0x386*/ s8 returnToMainBoardFlag;
    /*0x387*/ s8 boardEntityCollisionMode;
    /*0x388*/ s8 ballRespawnState;
    /*0x389*/ s8 legendaryFlashState;
    /*0x38A*/ s16 rayquazaOrbAngle;
    /*0x38C*/ s16 bossRenderOffsetY;
    /*0x38E*/ s16 bossAttackTimer;
    /*0x390*/ u16 bossRoarTimer;
    /*0x392*/ u16 ballRespawnTimer;
    /*0x394*/ s16 bannerSlideYOffset;
    /*0x396*/ s8 minionActiveCount;
    /*0x397*/ s8 minionSpriteVariant[3];
    /*0x39A*/ u8 minionNextSpriteVariant[3];
    /*0x39D*/ s8 minionOamIx[3];
    /*0x3A0*/ s8 minionState[3];
    /*0x3A3*/ s8 minionFramesetIx[3];
    /*0x3A6*/ s8 minionDrawInFrame[3];
    /*0x3A9*/ s8 minionCanCollide[3];
    /*0x3AC*/ s8 minionDeathTimer[3];
    /*0x3B0*/ u16 minionStateTimer[3];
    /*0x3B6*/ u16 minionTimeAlive[3];
    /*0x3BC*/ u16 minionEscapeAtTime[3];
    /*0x3C2*/ u8 filler3C2[0x2];
    /*0x3C4*/ struct Vector16 minionLogicPosition[3];
    /*0x3D0*/ struct Vector16 minionCollisionPosition[3];
    /*0x3DC*/ s8 bossEntityState;
    /*0x3DD*/ s8 bossAttackPhase;
    /*0x3DE*/ s8 kecleonFramesetBase;
    /*0x3DF*/ s8 bossVulnerable;
    /*0x3E0*/ s8 dusclopsWalkFootIndex;
    /*0x3E1*/ s8 bossMovementPhase;
    /*0x3E2*/ s16 bossFramesetIndex;
    /*0x3E4*/ u16 bossFrameTimer;
    /*0x3E6*/ s16 bossAnimLoopCount;
    /*0x3E8*/ s16 bossPositionX;
    /*0x3EA*/ s16 bossPositionY;
    /*0x3EC*/ s16 bossVelocityX;
    /*0x3EE*/ s16 bossVelocityY;
    /*0x3F0*/ u16 bossCollisionX;
    /*0x3F2*/ u16 bossCollisionY;
    /*0x3F4*/ s8 kecleonTargetState;
    /*0x3F5*/ s8 kecleonTargetFrameIndex;
    /*0x3F6*/ s8 kecleonTargetColorMatch;
    /*0x3F7*/ s8 kecleonTargetVisible;
    /*0x3F8*/ s8 kecleonCollisionEnabled;
    /*0x3F9*/ u8 filler3F9[0x1];
    /*0x3FA*/ s16 kecleonTargetX;
    /*0x3FC*/ s16 kecleonTargetY;
    /*0x3FE*/ u8 filler3FE[0x2];
    /*0x400*/ struct Vector16 kecleonCollisionPos;
    /*0x404*/ s8 kecleonBoardHitState;
    /*0x405*/ s8 kecleonHitFrameIndex;
    /*0x406*/ s8 kecleonTargetActive;
    /*0x407*/ u8 filler407[0x1];
    /*0x408*/ u16 kecleonAnimTimer;
    /*0x40A*/ u16 kecleonCollisionX;
    /*0x40C*/ u16 kecleonCollisionY;
    /*0x40E*/ u16 kecleonFrameTimer;
    /*0x410*/ s16 kecleonHitboxX;
    /*0x412*/ s16 kecleonHitboxY;
    /*0x414*/ struct Vector16 orbLogicPosition;
    /*0x418*/ struct Vector16 orbCollisionPosition;
    /*0x41C*/ s8 kecleonBerryLargeFlashTimer[4];
    /*0x420*/ s8 kecleonBerrySmallFlashTimer[10];
    /*0x42A*/ s8 kecleonHitSparkTimer[7];
    /*0x431*/ u8 filler431[0x3];
    /*0x434*/ struct Vector16 kecleonBerryHitPosition[3];
    /*0x440*/ s8 shockwaveAlreadyHit;
    /*0x441*/ s8 orbEntityState[2];
    /*0x443*/ s8 orbTargetWaypointIndex[2];
    /*0x445*/ s8 whirlpoolTrapPhase;
    /*0x446*/ s8 whirlpoolTrapAnimEndFrame;
    /*0x447*/ s8 whirlpoolTrapNextPhase;
    /*0x448*/ s8 whirlpoolTrapAnimFrame;
    /*0x449*/ s8 whirlpoolTrapAnimLoopStart;
    /*0x44A*/ s8 whirlpoolTrapLoopCount;
    /*0x44B*/ u8 filler44B[0x1];
    /*0x44C*/ u16 kyogreBgAnimTimer;
    /*0x44E*/ s16 whirlpoolTrapPauseTimer;
    /*0x450*/ u16 kyogreWaveTimer;
    /*0x452*/ u16 bossHitFlashTimer;
    /*0x454*/ u16 whirlpoolTrapFrameTimer;
    /*0x456*/ u16 shockwaveAnimTimer;
    /*0x458*/ u16 orbAnimTimer[2];
    /*0x45C*/ struct Vector16 orbScreenPosition[2];
    /*0x464*/ struct Vector16 orbOrbitCenter[2];
    /*0x46C*/ struct Vector16 shockwaveQuadrantOffset[4];
    /*0x47C*/ s8 projectileAttackCount;
    /*0x47D*/ s8 projectileDirection;
    /*0x47E*/ s8 projectileAttackAnimTimer;
    /*0x47F*/ s8 ballGrabShakeTimer;
    /*0x480*/ u16 ballGrabFlashTimer;
    /*0x482*/ u16 projectileFlightTimer;
    /*0x484*/ u16 projectileAngle;
    /*0x486*/ s16 ballGrabTimer;
    /*0x488*/ struct Vector16 projectilePosition;
    /*0x48C*/ s8 firePillarState[4];
    /*0x490*/ s8 firePillarAnimEndFrame[4];
    /*0x494*/ s8 firePillarNextState[4];
    /*0x498*/ s8 firePillarAnimFrame[4];
    /*0x49C*/ s8 firePillarAnimStartFrame[4];
    /*0x4A0*/ s8 firePillarAnimLoopCount[4];
    /*0x4A4*/ s8 firePillarHitTimer[4];
    /*0x4A8*/ s8 firePillarExtraHitCount[4];
    /*0x4AC*/ u16 firePillarFrameTimer[4];
    /*0x4B4*/ struct Vector16 firePillarCollisionPos[4];
    /*0x4C4*/ u16 firePillarSpawnSfxTimer;
    /*0x4C6*/ u16 bossDropVelocity;
    /*0x4C8*/ s8 impactShakeTimer;
    /*0x4C9*/ u8 footstepShakePattern;
    /*0x4CA*/ u16 footstepShakeTimer;
    /*0x4CC*/ s8 boulderPositionIndex[3];
    /*0x4CF*/ s8 boulderState[3];
    /*0x4D2*/ s8 boulderSpriteFrame[3];
    /*0x4D5*/ s8 boulderHitFlag[3];
    /*0x4D8*/ u16 boulderAnimTimer[3];
    /*0x4DE*/ s16 boulderFallVelocity[3];
    /*0x4E4*/ s16 boulderFallHeight[3];
    /*0x4EA*/ u8 filler4EA[0x2];
    /*0x4EC*/ struct Vector16 boulderGroundPosition[3];
    /*0x4F8*/ struct Vector16 boulderCollisionPos[3];
    /*0x504*/ u8 windAttackCount;
    /*0x505*/ s8 orbHitIndex;
    /*0x506*/ s8 introSequencePhase;
    /*0x507*/ s8 swoopAttackState;
    /*0x508*/ s16 horizontalShakeTimer;
    /*0x50A*/ s16 roarBrightnessFlashTimer;
    /*0x50C*/ u16 bossInvulnTimer;
    /*0x50E*/ u16 hitBurstAnimFrame;
    /*0x510*/ u16 swoopAttackAnimFrame;
    /*0x512*/ u16 bossSineAngle;
    /*0x514*/ u16 windCloudSpawnTimer;
    /*0x516*/ u16 introFrameCounter;
    /*0x518*/ s16 bgScrollSpeed;
    /*0x51A*/ s16 bossHeadScreenY;
    /*0x51C*/ struct Vector16 swoopTargetPosition;
    /*0x520*/ struct Vector16 orbHitPosition;
    /*0x524*/ struct Vector16 windEntityPosition;
    /*0x528*/ struct Vector16 windCloudPosition;
    /*0x52C*/ s8 sphealKnockdownCount[2];
    /*0x52E*/ s8 sphealKnockdownDisplayCount[2];
    /*0x530*/ s8 knockdownTargetIndex[3];
    /*0x533*/ s8 knockdownBounceCount[3];
    /*0x536*/ s8 knockdownPhase[3];
    /*0x539*/ u8 filler539[0x1];
    /*0x53A*/ u16 resultsAnimTimer;
    /*0x53C*/ u16 knockdownStunTimer[3];
    /*0x542*/ u16 scoreCountdownTimer;
    /*0x544*/ u32 totalBonusScore;
    /*0x548*/ s8 minionHitFlashTimer[2];
    /*0x54A*/ s8 unk54A;
    /*0x54B*/ s8 flyingEnemySinkSpeed[2];
    /*0x54D*/ s8 flyingEnemyHitCooldown[2];
    /*0x54F*/ s8 flyingEnemyCollisionType[2];
    /*0x551*/ s8 flyingEnemyDirection[2];
    /*0x553*/ s8 flyingEnemyState[2];
    /*0x555*/ s8 flyingEnemyPrevSpriteIndex[2];
    /*0x557*/ s8 flyingEnemySpawnVariant[2];
    /*0x559*/ s8 flyingEnemyPathIndex[2];
    /*0x55B*/ s8 flyingEnemyFramesetIndex[2];
    /*0x55D*/ s8 flyingEnemyOamXOffset[2];
    /*0x55F*/ s8 flyingEnemyOamYOffset[2];
    /*0x561*/ u8 filler561[0x1];
    /*0x562*/ u16 flyingEnemyAnimTimer[2];
    /*0x566*/ s16 flyingEnemyScreenY[2];
    /*0x56A*/ s16 flyingEnemyFlyTimer[2];
    /*0x56E*/ u8 filler56E[0x2];
    /*0x570*/ struct Vector16 flyingEnemyCollisionPos[2];
    /*0x578*/ struct Vector16 flyingEnemyVelocity[2];
    /*0x580*/ struct Vector32 flyingEnemyPositionQ8[2];
    /*0x590*/ s8 unk590;
    /*0x591*/ s8 deliveryAnimFrameIndex;
    /*0x592*/ u16 deliveryAnimTimer;
    /*0x594*/ u16 unk594;
    /*0x596*/ u16 unk596;
    /*0x598*/ u16 currentSpecies; // Current catch/hatch mode species? Is it evo mode as well?
    /*0x59A*/ u16 evoTargetSpecies;
    /*0x59C*/ u16 lastCatchSpecies; // Previous catch mode species?
    /*0x59E*/ u16 lastEggSpecies; // Previous hatch/evo mode species?
    /*0x5A0*/ u16 preEvoSpecies;
    /*0x5A2*/ u16 postEvoSpecies;
    /*0x5A4*/ u8 captureState;
    /*0x5A5*/ u8 creatureHitCount;
    /*0x5A6*/ u16 captureSequenceFrame;
    /*0x5A8*/ s8 captureSequenceTimer;
    /*0x5A9*/ u8 captureFlashTimer;
    /*0x5AA*/ u16 creatureHitCooldown;
    /*0x5AC*/ s32 trapSpinRadius;
    /*0x5B0*/ u16 trapAngleQ16;
    /*0x5B2*/ s8 ballInLowerHalf;
    /*0x5B3*/ u8 filler5B3[0x6];
    /*0x5B9*/ s8 tileParticleGravity[6];
    /*0x5BF*/ u8 filler5BF[0x1];
    /*0x5C0*/ struct Vector16 tileParticlePos[6];
    /*0x5D8*/ struct Vector16 tileParticleVel[6];
    /*0x5F0*/ u16 caughtMonCount; // Number of mons caught in this game
    /*0x5F2*/ s8 jirachiCollisionEnabled;
    /*0x5F3*/ s8 bonusTrapEnabled;
    /*0x5F4*/ u16 collisionMapScrollY;
    /*0x5F6*/ s8 ballUpgradeType;
    /*0x5F7*/ u8 ballUpgradeTimerFrozen;
    /*0x5F8*/ u16 ballUpgradeCounter;
    /*0x5FA*/ s8 boardEntityActive;
    /*0x5FB*/ s8 cameraScrollEnabled;
    /*0x5FC*/ s16 cameraScrollOffset;
    /*0x5FE*/ s16 cameraScrollTarget;
    /*0x600*/ u16 mainBoardCountdownTimer;
    /*0x602*/ s8 hatchRevealPhase;
    /*0x603*/ s8 revealFramesetIndex;
    /*0x604*/ u16 revealAnimFrameCounter;
    /*0x606*/ u16 particleAnimTimer;
    /*0x608*/ u16 travelAnimSubTimer;
    /*0x60A*/ s8 travelAnimKeyframeIndex;
    /*0x60B*/ s8 unk60B;
    /*0x60C*/ s16 travelPainterPosX;
    /*0x60E*/ s16 travelPainterPosY;
    /*0x610*/ u16 travelPainterVelX;
    /*0x612*/ u16 travelPainterVelY;
    /*0x614*/ s16 pikaSpinMomentum;
    /*0x616*/ u16 pikaSpinCooldownTimer;
    /*0x618*/ u16 pikaSpinFrameCounter;
    /*0x61A*/ s16 pikaSpinPeriod;
    /*0x61C*/ s8 kickbackFiring;
    /*0x61D*/ u8 filler61D;
    /*0x61E*/ u16 kickbackLaunchTimer;
    /*0x620*/ struct Vector16 kickbackBallHoverPos;
    /*0x624*/ s8 bumperHitCountdown; // 2 when Hit, one frame of ignored collision, then ready to hit again
    /*0x625*/ s8 hatchTilesBumperAcknowledged;
    /*0x626*/ s8 evoItemAnimFrame;
    /*0x627*/ u8 filler627[0x1];
    /*0x628*/ u16 evoItemAnimFrameTimer;
    /*0x62A*/ u8 bonusCatchCount;
    /*0x62B*/ u8 bonusMonCatchCount;
    /*0x62C*/ u8 travelModeCompletionCount;
    /*0x62D*/ u8 catchTriggerCompletionCount;
    /*0x62E*/ u8 bonusPikaSaverCount;
    /*0x62F*/ u8 bonusMultiplier;
    /*0x630*/ u32 bonusSubtotal;
    /*0x634*/ u32 bonusCategoryScore;
    /*0x638*/ s8 bonusSummaryPhase;
    /*0x639*/ s8 bonusSummaryComplete;
    /*0x63A*/ u16 bonusSummaryTimer;
    /*0x63C*/ s8 bonusTextRevealMask[3][20];
    /*0x678*/ s8 bonusTextContent[3][20];
    /*0x6B4*/ u32 bonusTotalScoreLo;
    /*0x6B8*/ u32 bonusTotalScoreHi;
    /*0x6BC*/ s8 travelRouletteSlotHitType;
    /*0x6BD*/ s8 seedotCount;
    /*0x6BE*/ s8 seedotExitSequenceActive;
    /*0x6BF*/ u8 filler6BF[0x1];
    /*0x6C0*/ u16 seedotExitSequenceTimer;
    /*0x6C2*/ u16 seedotModeStartDelay;
    /*0x6C4*/ s8 portraitDisplayState;
    /*0x6C5*/ s8 hatchTileRevealState;
    /*0x6C6*/ s8 hatchTilesBoardAcknowledged;
    /*0x6C7*/ s8 hatchSequentialTilesRevealed;
    /*0x6C8*/ s8 hatchGridCellIndex;
    /*0x6C9*/ s8 hatchTilesRemaining;
    /*0x6CA*/ u16 hatchSequentialTileRevealFrameAnimTimer;
    /*0x6CC*/ s8 hatchFrameId;
    /*0x6CD*/ u8 hatchTileShufflePool[6];
    /*0x6D3*/ u8 hatchTilePalette[6];
    /*0x6D9*/ s8 rouletteAreaIndex[2];
    /*0x6DB*/ u8 creatureOamPriority;
    /*0x6DC*/ u8 rouletteOutcomeId;
    /*0x6DD*/ s8 shopPurchaseConfirmed;
    /*0x6DE*/ u16 outcomeFrameCounter;
    /*0x6E0*/ s16 rouletteSubOffset;
    /*0x6E2*/ u8 filler6E2[0x2];
    /*0x6E4*/ struct Vector16 rouletteBasePos;
    /*0x6E8*/ s8 rouletteStopRequested;
    /*0x6E9*/ s8 rouletteLevel;
    /*0x6EA*/ s8 rouletteSlotCount;
    /*0x6EB*/ s8 rouletteSlotCursor;
    /*0x6EC*/ s8 modeOutcomeValues[2];
    /*0x6EE*/ u16 allHolesLitDelayTimer;
    /*0x6F0*/ u16 rouletteFrameIndex;
    /*0x6F2*/ u16 rouletteRotationPeriod;
    /*0x6F4*/ u16 rouletteSpinSpeed;
    /*0x6F6*/ u16 rouletteInitialSpeed;
    /*0x6F8*/ u16 rouletteSlotValues[6];
    /*0x704*/ u16 roulettePortraitId;
    /*0x706*/ u8 filler706[0x2];
    /*0x708*/ u32 portraitCycleFrame;
    /*0x70C*/ u16 hudAnimFrameCounter;
    /*0x70E*/ s8 progressLevel; // Becomes bonusMultiplier at end-of-ball; displayed on the blue bonus sign
    /*0x70F*/ s8 unk70F;
    /*0x710*/ s8 holeIndicators[4]; // 'HOLE' light indicators in Ruby/Sapphire field
    /*0x714*/ s8 allHolesLit;
    /*0x715*/ u8 allHolesLitBlinkTimer;
    /*0x716*/ u8 slingshotHitAnimTimer;
    /*0x717*/ u8 slingshotSideIndex;
    /*0x718*/ s8 ballPowerUpLight[3];
    /*0x71B*/ s8 ballPowerUpAnimActive;
    /*0x71C*/ u8 ballShadowTimer;
    /*0x71D*/ s8 catchLights[3];
    /*0x720*/ u8 evoBlinkTimer;
    /*0x721*/ s8 evoCatchLightSlot1;
    /*0x722*/ s8 evoCatchLightSlot2;
    /*0x723*/ s8 evoItemCount;
    /*0x724*/ u16 saverTimeRemaining;
    /*0x726*/ s8 saverLit;
    /*0x727*/ u8 filler727[0x1];
    /*0x728*/ s8 catchArrowPaletteActive;
    /*0x729*/ s8 evoArrowPaletteActive;
    /*0x72A*/ s8 rouletteSlotActive;
    /*0x72B*/ s8 coinRewardLevel;
    /*0x72C*/ u16 coinRewardLevelTimer;
    /*0x72E*/ s8 evoArrowProgress;
    /*0x72F*/ s8 catchArrowProgress;
    /*0x730*/ s8 trapAnimState;
    /*0x731*/ s8 catchProgressFlashing;
    /*0x732*/ s8 ballCollisionZone;
    /*0x733*/ u8 filler733[0x1];
    /*0x734*/ s16 hudBlinkPhase;
    /*0x736*/ s8 travelArrowTiles[3];
    /*0x739*/ s8 prevTravelArrowTiles[3];
    /*0x73C*/ u8 arrowProgressPreserved; // TODO: unknown type
    /*0x73D*/ s8 catchModeArrows;   // Affects which encounter table is used per area
    /*0x73E*/ u8 filler73E[0x2];
    /*0x740*/ u8 debugMenuSelection;
    /*0x741*/ u8 filler741[0x3];
    /*0x744*/ u8 pikaSaverTileIndex[2];
    /*0x746*/ u8 cyndaquilFrame;
    /*0x747*/ u8 portraitRenderMode[2];
    /*0x749*/ u8 portraitGfxIndex[2];
    /*0x74B*/ u8 filler74B[0x1];
    /*0x74C*/ volatile u8 savedObjPalette[2][OBJ_PLTT_SIZE];
    /*0xB4C*/ volatile u8 savedBgPalette[2][BG_PLTT_SIZE];
    /*0xF4C*/ struct SongHeader *savedBgmSongHeader;
    /*0xF50*/ u8 fillerF50[0x8];
    /*0xF58*/ struct BgOffsets bgOffsets0;
    /*0xF5C*/ struct BgOffsets bgOffsets1;
    /*0xF60*/ struct BgOffsets bgOffsets2;
    /*0xF64*/ struct BgOffsets bgOffsets3;
    /*0xF68*/ u16 savedSpriteAvailability[2][100];
    /*0x10F8*/u8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x10FD*/u8 savedField;
    /*0x10FE*/u8 savedTempField;
    /*0x10FF*/u8 savedIsBonusField;
    /*0x1100*/u8 startButtonDisabled;
    /*0x1101*/u8 savedModeChangeFlags;
    /*0x1102*/u8 savedDebugMenuCursorIndex;
    /*0x1103*/u8 savedPendingModeChangeType;
    /*0x1104*/s8 pauseMenuCursorIndex; //Pause Menu Pointer index
    /*0x1105*/u8 filler1105[0x1];
    // Values applied by the pause process (set when pausing)
    /*0x1106*/volatile u16 pauseBlendControl;
    /*0x1108*/volatile u16 pauseBlendAlpha;
    /*0x110A*/volatile u16 pauseBlendBrightness;
    /*0x110C*/u16 pauseScoreOverlayActive;
    /*0x110E*/u16 pauseVCount;
    // Values preserved from before pause (restored when unpausing)
    /*0x1110*/volatile u16 savedBlendControl;
    /*0x1112*/volatile u16 savedBlendAlpha;
    /*0x1114*/volatile u16 savedBlendBrightness;
    /*0x1116*/u16 savedScoreOverlayActive;
    /*0x1118*/u16 savedVCount;
    /*0x111A*/u16 pauseObjPalette[OBJ_PLTT_SIZE / 0x20][0x10];
    /*0x131A*/u8 filler131A[0x2];
    /*0x131C*/u32 pauseAnimTimer; //Time since paused
    /*0x1320*/s16 savedAnimationTimer;
    /*0x1322*/s16 savedModeChangeDelayTimer;
    /*0x1324*/s16 savedShopPanelActive;
    /*0x1326*/s16 savedShopPanelSlideOffset;
    /*0x1328*/u16 ballLaunchTimer; // Countdown to activate secondaryBall (multiball)
    /*0x132A*/u8 filler132A[0x2];
    /*0x132C*/struct BallState *ball;
    /*0x1330*/struct BallState *secondaryBall;
    /*0x1334*/struct BallState ballStates[2];
    /*0x13BC*/struct FlipperState flipper[2];
    /*0x13D4*/u16 nameRevealDelaysRow2[10];
    /*0x13E8*/struct Vector16 nameSlideRow2[10];
} /* size=0x1410 */;

struct ReplayInputFrame
{
    /*0x0*/ u8 newButtonBits;
    /*0x1*/ u8 releasedButtonBits;
    /*0x2*/ u8 heldButtonBits;
};

struct FieldBoardLayout
{
    /* These field offsets are intentionally kept as relative to
       struct BoardConfig to make decompiling easier. This struct
       is basically always accessed relative to struct BoardConfig. */
    /*0x14*/ s16 cameraStartX;
    /*0x16*/ s16 cameraStartY;
    /*0x18*/ s16 cameraScrollMaxY;
    /*0x1A*/ s16 cameraScrollMinY;
    /*0x1C*/ u16 flipperBaseY;
    /*0x1E*/ u8 filler1E[0x2];
    /*0x20*/ s16 flipperOriginY;
    /*0x22*/ s16 leftFlipperOriginX;
    /*0x24*/ s16 rightFlipperOriginX;
    /*0x26*/ s16 ballSpawnX;
    /*0x28*/ s16 ballSpawnY;
    /*0x2A*/ s16 ballDrainY;
    /*0x2C*/ u8 *objPaletteSets[3];
    /*0x38*/ const s16 *collisionTileMap[4];
    /*0x48*/ const u16 *collisionAngleMap[4];
    /*0x58*/ const u8 *collisionTypeMap[4];
};

struct BoardConfig
{
    /*0x00*/ u8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x05*/ bool8 rumbleEnabled;
    /*0x06*/ s16 idleDemoDuration;
    /*0x08*/ s16 caughtSpeciesCount;
    /*0x0A*/ u8 fillerA[0x2];
    /*0x0C*/ struct PinballGame *pinballGame;
    /*0x10*/ struct ReplayInputFrame *replayInputData;
    /*0x14*/ struct FieldBoardLayout fieldLayout;
    /*0x68*/ const u16 *flipperCollisionData;
};

struct FlipperLineSegment
{
    u16 x1;
    u16 y1;
    u16 x2;
    u16 y2;
};

extern struct PinballGame *gCurrentPinballGame;
extern const StateFunc gIdlePinballGameStateFuncs[];
extern u32 gReplayFrameCounter;
extern struct BoardConfig gBoardConfig;
extern u8 gKecleonSpriteOrderMap[];
extern u16 gFieldPaletteVariants[][6][16];
extern u16 gDusclopsBossAnimFrames[]; 
extern const u8 gBallPalettes[][0x20];
extern const u8 gDusclopsBonusClear_Gfx[];
extern struct ReplayInputFrame gIdleBoardConfig0;
extern struct ReplayInputFrame gIdleBoardConfig2;
extern struct ReplayInputFrame gIdleBoardConfig3;
extern struct ReplayInputFrame gIdleBoardConfig1;
extern struct PinballGame gIdleBoardGameState0;
extern struct PinballGame gIdleBoardGameState2;
extern struct PinballGame gIdleBoardGameState3;
extern struct PinballGame gIdleBoardGameState1;
extern s32 gBonusStageObjPal[64];
extern s32 gDusclopsAnimPalettes[0x3E0];
extern u16 gKecleonTongueCollisionMap[0x1600];
extern u16 gKecleonBodyCollisionMap[0x1600];
extern u16 gKyogreForm1CollisionMap[];
extern u16 gKyogreForm2CollisionMap[];
extern u16 gKyogreForm3CollisionMap[];
extern u16 gGroudonBodyCollisionMap[0x3800];
extern u16 gGroudonProjectileCollisionMap[0x2A80];
extern const u16 gSphealCrackedIceCollisionMap[0x1000];
extern const u16 gSphealFrozenIceCollisionMap[0x1000];
extern u8 gFlipperTileGraphics[][0x200];
extern u16 gDusclopsBoardDusclopsAppearFx_Gfx[]; 
extern u16 gDusclopsBoardDusclops_Gfx[]; 
extern u8 gDusclopsBoardDusclopsBallGrabSwirl_Gfx[];
extern struct SongHeader se_catch_evo_banner;
extern struct SongHeader se_dusclops_appear;
extern const s16 gBounceBackForceMagnitudes[9]; //Possibly only 4, with a gap?
extern const s16 gBounceBackForceMagnitudes[9];
typedef s16 (*Unk86ACE0C)(struct Vector16*, u16*);
extern Unk86ACE0C BoardCollisionFuncts_086ACE0C[8];
extern struct Vector16 gWallEscapeOffsets[4];
extern struct FlipperLineSegment gFlipperLineGeometry[13];
extern u16 gFlipperBaseXPositions[2];
extern const u8 *const gModeBannerTilemaps[];
extern const u8 *const gModeBannerPalettes[];
extern s16 DuclopsFramesetData[][2];
extern u16 gModeBannerOamAttributes[14][45];
extern const u8 gPokemonNameDisplayGfx[]; 
extern u8 gShopNameDisplay_Pals[]; 
extern const u16 gShopCursorToItemMap[];
extern u8 gShopModeBG_Gfx[];
extern u8 gShopEvoUI_Pals[];
extern u8 gEvoNameDisplay_Pals[];
extern u8 gEvoModeBG_Gfx[];
extern const u16 gShopItemData[][4];
extern u32 gShopEvoBGAnimFrames[];

extern const u16 gSharedBumperCollisionMap[];
extern const u16 gDusclopsBodyCollisionMap[];


extern u8 *gMonPortraitGroupGfx[];
extern u8 *gMonPortraitGroupPals[];
extern u8 gCatchSpriteGfxBuffer[];
extern u8 gCatchSpriteFlashGfx[];
extern const u8 gPikaSaverFullCoverageGfx[];
extern const u8 gPikaSaverPartialCoverageGfx[];
extern const u8 gPortraitAnimFrameGraphics[][0x300];
extern const u8 gBallRotationTileGraphics[][0x80];
extern const u8 gBallShadowTileGraphics[][0x200];
extern const u8 gMainStageBonusTrap_Gfx[][0x300];
extern const u8 gPortraitGenericGraphics[][0x300];
extern const u8 gChargeFillIndicator_Gfx[][0x80];
extern const u8 gPikaSaverTilesGfx[];
extern const u8 gMainBoardPikaSpinner_Gfx[][0x120];
extern const u8 gEggFrameTilesGfx[][0x200];
extern const u8 *gEvoItemTilesGfxPtrs[];
extern const u16 gEggAnimationFrameData[][4];

#endif // GUARD_GLOBAL_H