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
    /*0x00*/ s8 isGrabbed;
    /*0x01*/ s8 oamPriority;
    /*0x02*/ u8 filler2[0x2];
    /*0x04*/ u16 spinImpulse;
    /*0x06*/ s16 spin;
    /*0x08*/ s16 angleBias;
    /*0x0A*/ u16 rotation;
    /*0x0C*/ u16 prevRotation;
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
    /*0x02*/ s8 collisionFrame;
    /*0x03*/ s8 prevMoveDir;
    /*0x04*/ s8 collisionProcessed;
    /*0x05*/ s8 collisionTileIndex;
    /*0x06*/ s8 active;
    /*0x07*/ u8 stallTicks;
    /*0x08*/ s8 ballSide;
    /*0x09*/ u8 filler9[0x3];
};

struct PinballGame
{
    /*0x000*/ u32 hasSavedState; // 0=no saved state, 1=has saved state in SRAM
    /*0x004*/ u8 newButtonActions[5]; // e.g. player pressing the appropriate buttons to trigger the left flipper action, etc.
    /*0x009*/ u8 releasedButtonActions[5];
    /*0x00E*/ u8 heldButtonActions[5];
    /*0x013*/ s8 boardState; // Board state machine index. Drives field-specific logic via function tables.
    /*0x014*/ s8 nextBoardState; // State to transition to when boardTransitionPhase reaches 2
    /*0x015*/ s8 prevBoardState; // Previous board state, used for music selection
    /*0x016*/ s8 boardTransitionPhase; // 0=run init, 1=run update, 2=do transition
    /*0x017*/ s8 boardSubState; // Sub-state within the current board state
    /*0x018*/ u16 stageTimer; // General-purpose frame counter for board process stages
    /*0x01A*/ s8 fieldEntryInProgress;
    /*0x01B*/ u8 unk1B;
    /*0x01C*/ bool8 scoreCounterAnimationEnabled;
    /*0x01D*/ u8 gamePhase; // 0=init, 1=running, 2=waiting for transition
    /*0x01E*/ u8 currentProcessPass; // 0-3 iteration index for per-frame board process passes
    /*0x01F*/ u8 ballLockState; // 0=free, 1=locked/launching, 2=special lock
    /*0x020*/ u8 tiltDetected;
    /*0x021*/ u8 tiltButtonHeld;
    /*0x022*/ s8 collisionType; // 1=wall, 2=slope (from collision check routines)
    /*0x023*/ u8 collisionSubType; // Collision category from lower nibble of collision data
    /*0x024*/ s8 collisionMapIndex; // Selects which collision tilemap to use
    /*0x025*/ s8 boardEntryMode; // How ball enters the board (4=plunger launch)
    /*0x026*/ u16 entryAnimTimer;
    /*0x028*/ u16 sequenceTimer; // General-purpose countdown timer for board process animation sequences
    /*0x02A*/ u16 unk2A;
    /*0x02C*/ int cameraFollowOffsetQ8;
    /*0x030*/ s8 numLives;
    /*0x031*/ u8 ballSpeed;
    /*0x032*/ s8 areaRotationIndex;
    /*0x033*/ s8 nextAreaIndex;
    /*0x034*/ s8 nextNextAreaIndex;
    /*0x035*/ s8 area;
    /*0x036*/ s8 areaRotationCount;
    /*0x038*/ u32 scoreAddStepSize; //score to add every frame until scoreAddedInFrame score has been added to player's total
    /*0x03C*/ u32 scoreAddedInFrame; //score to add in a bonus field or mode (by completion or other ways, like hitting Duskulls)
    /*0x040*/ u32 scoreAdditionAccumulator; //score left to be counted up on the score registers
    /*0x044*/ u32 scoreLo; //counts score until 99_999_999, overflows into scoreHi
    /*0x048*/ u32 scoreHi; //counts score until 9_999, then freezes total score to 999_999_999_999!
    /*0x04C*/ s16 cameraScrollX; // BG scroll X offset for field viewport
    /*0x04E*/ s16 cameraScrollY; // BG scroll Y offset for field viewport
    /*0x050*/ u8 filler50[0x4];
    /*0x054*/ u32 cameraScrollYQ8; // Q24.8 fixed-point version of cameraScrollY
    /*0x058*/ u16 bgScrollXCopy; // Copy of cameraScrollX for DMA transfer
    /*0x05A*/ u16 bgScrollYWithOffset; // cameraScrollY + verticalScrollOffset
    /*0x05C*/ s16 flipperBounceReady;
    /*0x05E*/ u8 filler5E[0x2];
    /*0x060*/ struct Vector16 flipperBounceVelocity;
    /*0x064*/ s16 tilemapRowIndex; // cameraScrollY / 8, for streaming tilemap rows
    /*0x066*/ u16 activeBallIndex; // Which ball instance (0 or 1) is currently active
    /*0x068*/ s16 viewportBottomY; // Bottom edge of visible area in world coordinates
    /*0x06A*/ s16 viewportBottomYPrev; // Previous frame's viewportBottomY
    /*0x06C*/ u16 timerBonus; //Additional time to be added to next timed event (Only for bonus fields or all timers?)
    /*0x06E*/ s8 ballUpgradeGfxFrame;
    /*0x06F*/ s8 paletteCycleIndex;
    /*0x070*/ s8 fieldScrollState;
    /*0x071*/ s8 ballTrailRenderFlag;
    /*0x072*/ s8 hatchModeFlags;
    /*0x073*/ s8 jirachiWaypointIndex;
    /*0x074*/ u16 starParticleTimers[4];
    /*0x07C*/ u16 jirachiWaypointTimer;
    /*0x07E*/ u16 sphealBallDeliveryActive;
    /*0x080*/ s16 jirachiPosX;
    /*0x082*/ s16 jirachiPosY;
    /*0x084*/ struct Vector16 starParticlePositions[4];
    /*0x094*/ u8 filler94[0x28];
    /*0x0BC*/ s16 jirachiTargetX;
    /*0x0BE*/ s16 jirachiTargetY;
    /*0x0C0*/ s16 jirachiRenderX;
    /*0x0C2*/ s16 jirachiRenderY;
    /*0x0C4*/ u16 jirachiSpriteX;
    /*0x0C6*/ u16 jirachiSpriteY;
    /*0x0C8*/ u8 fillerC8[0x2];
    /*0x0CA*/ s16 bgSmoothScrollY; // BG2 Y offset that gradually approaches bgTargetScrollY
    /*0x0CC*/ s16 bgTargetScrollY; // Target Y scroll for BG layers (base + all offsets)
    /*0x0CE*/ u16 unkCE;
    /*0x0D0*/ struct Vector16 ballTrailPositions[5];
    /*0x0E4*/ u8 bannerType; // Which banner/text overlay is active (0=none, 1-22=various banners)
    /*0x0E6*/ s16 fieldScrollOffsetY; // Vertical camera offset for bonus/special fields
    /*0x0E8*/ s16 scrollTargetBottomY;
    /*0x0EA*/ u16 scrollDelayFrames;
    /*0x0EC*/ u16 scrollHoldFrames;
    /*0x0EE*/ s16 fieldScrollSpeed; // Step size for fieldScrollOffsetY adjustment per frame
    /*0x0F0*/ u16 bannerAnimPhase;
    /*0x0F2*/ s8 bannerGfxVariant;
    /*0x0F3*/ u8 unkF3;
    /*0x0F4*/ s16 fieldEntryAnimTimer;
    /*0x0F6*/ s16 bannerScrollPosQ10;
    /*0x0F8*/ s16 bannerScrollVelocity;
    /*0x0FA*/ s8 scrollOverrideActive;
    /*0x0FB*/ s8 scrollFromBottom;
    /*0x0FC*/ s16 bonusPanelOffsetY;
    /*0x0FE*/ s16 bonusBallBaseY;
    /*0x100*/ s32 bonusBallPosX;
    /*0x104*/ s32 bonusBallPosY;
    /*0x108*/ s16 bonusBallVelX;
    /*0x10A*/ s16 bonusBallVelY;
    /*0x10C*/ s16 bonusBallDropVelX;
    /*0x10E*/ s16 bonusBallDropVelY;
    /*0x110*/ s32 bonusBallDropPosX;
    /*0x114*/ s32 bonusBallDropPosY;
    /*0x118*/ s8 boardShakeTimers[4];
    /*0x11C*/ s8 boardShakeDirections[4];
    /*0x120*/ s8 shakeOffsetX; // Screen shake X component
    /*0x121*/ s8 shakeOffsetY; // Screen shake Y component
    /*0x122*/ s8 shakePeakX; // Peak shake X tracker
    /*0x123*/ s8 shakePeakY; // Peak shake Y tracker
    /*0x124*/ s8 shakeCollisionDeltaX;
    /*0x125*/ s8 shakeCollisionDeltaY;
    /*0x126*/ s8 shakeApplied;
    /*0x127*/ s8 shakeVelocityDirection;
    /*0x128*/ u8 bumperShakeTimer;
    /*0x129*/ s8 bumperShakeAxis;
    /*0x12A*/ u8 shakeCooldown;
    /*0x12B*/ s8 forceSpecialMons;  // When on, force next catch mode species to be special mons
    /*0x12C*/ s8 forcePichuEgg;     // When on, force next egg mode species to be Pichu
    /*0x12D*/ u8 filler12D;
    /*0x12E*/ s16 totalWeight;       // Added weight of all possible mons in area
    /*0x130*/ s16 speciesWeights[25]; // Weight of each species
    /*0x162*/ s8 forcePondToWhiscash;
    /*0x163*/ s8 peliAnimState;
    /*0x164*/ s8 peliAnimFrame;
    /*0x165*/ s8 hitFlashActive; // Triggers ball hit visual flicker
    /*0x166*/ u16 hitFlashOffsetY; // Sprite Y jitter during hit flash
    /*0x168*/ u16 peliAnimSubTimer;
    /*0x16A*/ s16 fieldBannerSpriteX;
    /*0x16C*/ s8 rubyPondState;
    /*0x16D*/ u8 filler16D[0x1];
    /*0x16E*/ s8 chinchouRandomTarget;
    /*0x16F*/ s8 rubyPondContentsChanging;
    /*0x170*/ s8 pondBumperAnimState[3];
    /*0x173*/ u8 unk173;
    /*0x174*/ u16 rubyPondChangeTimer;
    /*0x176*/ u8 bumperHitCount;
    /*0x177*/ u8 filler177[0x1];
    /*0x178*/ struct Vector16 rubyBumperLogicPosition[3]; //chinchou or lotad
    /*0x184*/ struct Vector16 rubyBumperCollisionPosition[3]; //chinchou or lotad
    /*0x190*/ s16 chinchouOrbitRadius;
    /*0x192*/ u8 coins;
    /*0x193*/ s8 coinsCollected;
    /*0x194*/ s8 coinsTotalToCollect;
    /*0x195*/ s8 coinCollectBonusInput;
    /*0x196*/ u16 coinAnimFrameCounter;
    /*0x198*/ s16 coinSpriteTimers[2];
    /*0x19C*/ struct Vector16 coinSpritePositions[2];
    /*0x1A4*/ s8 trapDoorAnimActive;
    /*0x1A5*/ s8 trapDisplayState;
    /*0x1A6*/ s8 upgradeMenuCursor;
    /*0x1A7*/ s8 upgradeMenuItemId;
    /*0x1A8*/ s8 upgradeMenuScrollDirection;
    /*0x1A9*/ u8 upgradeMenuScrollFrame;
    /*0x1AA*/ s8 pikaChargeFull;
    /*0x1AB*/ s8 holeEntryState;
    /*0x1AC*/ s8 pondSpriteFrame;
    /*0x1AD*/ s8 pondPaletteVariant;
    /*0x1AE*/ u8 plungerLoopCount;
    /*0x1AF*/ u8 bonusStagePurchased;
    /*0x1B0*/ s8 evoSelectionActive;
    /*0x1B1*/ u8 filler1B1[0x1];
    /*0x1B2*/ u16 evoStepCounter;
    /*0x1B4*/ u16 slotReelFrame; // Animation frame counter for species slot reel display
    /*0x1B6*/ u16 bannerScrollOffset;
    /*0x1B8*/ s16 bannerAnimTimer;
    /*0x1BA*/ u16 entrySequenceTimer;
    /*0x1BC*/ u16 spriteUpdateSlot;
    /*0x1BE*/ s8 pikaSaverLossType;
    /*0x1BF*/ u8 filler1BF[0x1];
    /*0x1C0*/ u16 pikaSaverAnimTimer;
    /*0x1C2*/ s8 outLaneSide;
    /*0x1C3*/ u8 filler1C3[0x1];
    /*0x1C4*/ u16 outLaneSaverTimer;
    /*0x1C6*/ s16 pikaChargeTarget;
    /*0x1C8*/ s16 pikaChargeDisplay;
    /*0x1CA*/ s16 pikaChargeSegment;
    /*0x1CC*/ s16 pikaChargeSegmentPrev;
    /*0x1CE*/ u16 pikaChargeFlashTimer;
    /*0x1D0*/ u16 pikaChargeAnimDuration;
    /*0x1D2*/ u16 unk1D2;
    /*0x1D4*/ u16 pikaChargeSpriteOffsetX;
    /*0x1D6*/ u16 pikaChargeSpriteY;
    /*0x1D8*/ u16 pikaChargeSpriteScaleX;
    /*0x1DA*/ u16 pikaChargeSpriteScaleY;
    /*0x1DC*/ u16 pikaChargeFullFlashTimer;
    /*0x1DE*/ u16 outLaneSaverAnimProgress;
    /*0x1E0*/ u16 outLaneSaverAnimTotal;
    /*0x1E2*/ s8 outLanePikaPosition; //Pikachu coverage. 0= left lane, 1=right lane, 2 = both
    /*0x1E3*/ s8 outLanePikaActive[2];
    /*0x1E5*/ s8 pikaSpinnerFrame;
    /*0x1E6*/ s8 pikaSpinnerFramePrev;
    /*0x1E7*/ u8 filler1E7[0x1];
    /*0x1E8*/ s16 hatchCaveSpriteBaseX;
    /*0x1EA*/ s16 hatchCaveSpriteBaseY;
    /*0x1EC*/ s8 pondAnimState;
    /*0x1ED*/ s8 pondAnimIndex; // Index into pond/slot animation sequence table
    /*0x1EE*/ s8 pondAnimIndexPrev;
    /*0x1EF*/ u8 unk1EF;
    /*0x1F0*/ u16 pondAnimSubFrame;
    /*0x1F2*/ u8 unk1F2;
    /*0x1F3*/ u8 unk1F3;
    /*0x1F4*/ s16 pondSpriteXQ10;
    /*0x1F6*/ s16 pondSpriteYQ10;
    /*0x1F8*/ s16 unk1F8;
    /*0x1FA*/ s16 unk1FA;
    /*0x1FC*/ s32 unk1FC;
    /*0x200*/ s32 bonusSpriteYQ10;
    /*0x204*/ s8 bonusTargetIndex;
    /*0x205*/ u8 filler205[0x1];
    /*0x206*/ u16 nameRevealAnimFrame;
    /*0x208*/ u16 outLanePikaAnimSubFrame;
    /*0x20A*/ s8 outLanePikaAnimKeyframe;
    /*0x20B*/ s8 trapSpriteAnimFrame;
    /*0x20C*/ s8 trapSpritePrevFrame;
    /*0x20D*/ u8 filler20D[0x1];
    /*0x20E*/ s16 speciesNamePixelOffset;
    /*0x210*/ u16 nameRevealScrollProgress;
    /*0x212*/ u16 nameLetterStaggerDelay[10];
    /*0x228*/ struct Vector16 nameLetterSlidePos[10];
    /*0x250*/ u16 evoItemRound;
    /*0x252*/ u16 menuDismissTimer;
    /*0x254*/ u8 filler254[0x4];
    /*0x258*/ s16 evoItemPosX;
    /*0x25A*/ s16 evoItemPosY;
    /*0x25C*/ s8 evoStageSelection;
    /*0x25D*/ s8 maxEvoStages;
    /*0x25E*/ s8 evoItemTargetIndex;
    /*0x25F*/ s8 evoItemType;
    /*0x260*/ s8 evoItemShuffledSlots[3];
    /*0x263*/ s8 evoItemCandidatePool[8];
    /*0x26B*/ s8 evoItemHitCount;
    /*0x26C*/ s8 evoItemResetFlag;
    /*0x26D*/ u8 filler26D[0x1];
    /*0x26E*/ u16 evoItemAppearTimer;
    /*0x270*/ u8 evolvablePartySpecies[MAX_EVOLVABLE_PARTY_SIZE];
    /*0x280*/ s8 evolvingPartyIndex;
    /*0x281*/ s8 evolvablePartySize;
    /*0x282*/ s8 ballReturnMode; // 0=plunger, 1=whiscash return from bonus, 2=pelipper delivery
    /*0x283*/ u8 numCompletedBonusStages;
    /*0x284*/ s8 pendingBonusFieldId; // Bonus Field to transition to?
    /*0x285*/ u8 filler285[0x1];
    /*0x286*/ u16 extraLifeAnimTimer;
    /*0x288*/ s16 entityCenterX;
    /*0x28A*/ s16 entityCenterY;
    /*0x28C*/ u8 filler28C[0x4];
    /*0x290*/ u32 gameFrameCount; // Frames of actual gameplay (not counting paused frames)
    /*0x294*/ s8 entityActivePhase; // Entity lifecycle: 0=inactive, 1=appearing, 2=active, 3=defeated
    /*0x295*/ u8 unk295;
    /*0x296*/ u16 eventTimer; //Timer for events (Only bonus fields or all events?)
    /*0x298*/ u16 blendScanlineWidth;
    /*0x29A*/ u16 catchModeAttemptCount;
    /*0x29C*/ u16 bgmVolumeRestoreTimer; // Countdown to restore BGM volume after event
    /*0x29E*/ u8 rubyAbsorbZoneActive; // Flag for Ruby field absorb zone state
    /*0x29F*/ s8 rampPrizeType;
    /*0x2A0*/ u16 rampPrizeCooldown;
    /*0x2A2*/ s8 whiscashState;
    /*0x2A3*/ s8 whiscashVulnerable; //Whiscash alternating invuln timer?
    /*0x2A4*/ s8 shouldProcessWhiscash;
    /*0x2A5*/ s8 whiscashFrameIx;
    /*0x2A6*/ u16 whiscashStateTimer;
    /*0x2A8*/ u16 pondSwitchesSinceLastWhiscash;
    /*0x2AA*/ u16 bossShakeOffsetX; // Screen shake X from boss battles (Rayquaza/Whiscash)
    /*0x2AC*/ s16 bossShakeOffsetY; // Screen shake Y from boss battles (Rayquaza/Groudon)
    /*0x2AE*/ u8 filler2AE[0x2];
    /*0x2B0*/ u16 coinAnimFrame;
    /*0x2B2*/ s8 coinAnimActive;
    /*0x2B3*/ u8 filler2B3[0x1];
    /*0x2B4*/ s16 coinBounceX;
    /*0x2B6*/ s16 coinBounceY;
    /*0x2B8*/ u16 coinBounceVelX;
    /*0x2BA*/ u16 coinBounceVelY;
    /*0x2BC*/ u16 coinBounceTimer;
    /*0x2BE*/ s8 rubyPondCurrentStage;
    /*0x2C0*/ u16 rubyPondSubframeTimer;
    /*0x2C2*/ s8 rubyPondAnimFrame;
    /*0x2C3*/ s8 lotadCelebKeyframeIndex;
    /*0x2C4*/ u16 lotadCelebSubFrame;
    /*0x2C6*/ u16 holeCelebAnimFrame;
    /*0x2C8*/ s16 holeCelebSpriteXQ20;
    /*0x2CA*/ s16 holeCelebSpriteYQ20;
    /*0x2CC*/ s16 holeCelebVelX;
    /*0x2CE*/ s16 holeCelebVelY;
    /*0x2D0*/ s8 hatchCaveCompletionFlag;
    /*0x2D1*/ u8 filler2D1[3];
    /*0x2D4*/ u16 cyndaquilSpriteX;
    /*0x2D6*/ u16 cyndaquilSpriteY;
    /*0x2D8*/ s8 hatchCaveCollisionReady;
    /*0x2D9*/ s8 hatchCaveHitPending;
    /*0x2DA*/ s8 hatchCaveState;
    /*0x2DB*/ u8 filler2DB[0x3];
    /*0x2DE*/ u16 cyndaquilRiseTimer;
    /*0x2E0*/ u16 cyndaquilRiseHoldTimer;
    /*0x2E2*/ s8 pondGateHitSide;
    /*0x2E3*/ s8 pondGateCycleCount[2];
    /*0x2E5*/ s8 pondGateAnimPhase[2];
    /*0x2E7*/ u8 filler2E7[0x1];
    /*0x2E8*/ u16 pondGateAnimSubFrame[2];
    /*0x2EC*/ s16 pondGateSpriteOffset[2];
    /*0x2F0*/ u8 shopDoorTargetFrame;
    /*0x2F1*/ u8 shopDoorCurrentFrame;
    /*0x2F2*/ u16 shopDoorTransitionDelay;
    /*0x2F4*/ s8 pokemonActionFrame; //Sharpedo/Wailmer Oam Ix
    /*0x2F5*/ s8 sharpedoGfxVariant; //Sharpedo tile variant Ix
    /*0x2F6*/ u16 sharpedoHoldTimer;
    /*0x2F8*/ s8 rampUpgradeFromPrize;
    /*0x2F9*/ s8 nuzleafPositionIndex;
    /*0x2FA*/ s8 nuzleafHitPhase;
    /*0x2FB*/ s8 nuzleafAnimState;
    /*0x2FC*/ s8 nuzleafGfxFrame;
    /*0x2FD*/ s8 nuzleafKeyframeIndex;
    /*0x2FE*/ u16 nuzleafKeyframeSubFrame;
    /*0x300*/ s8 rampPrizeAnimState;
    /*0x301*/ s8 rampPrizeHitPending;
    /*0x302*/ s8 rampPrizeHitCooldown;
    /*0x303*/ s8 unk303;
    /*0x304*/ u16 rampPrizeAnimFrame;
    /*0x306*/ s8 pelipperState;
    /*0x307*/ s8 pelipperAnimKeyframe;
    /*0x308*/ u16 bumperHitsSinceReset;
    /*0x30A*/ u16 pelipperAnimSubframe;
    /*0x30C*/ u16 entityMovementTimer; // Movement/animation timer for field entity
    /*0x30E*/ s16 pelipperBobOffsetY;
    /*0x310*/ s16 pelipperFlapsoundTimer;
    /*0x312*/ u8 filler312[0x2];
    /*0x314*/ s16 pelipperDropVelX;
    /*0x316*/ s16 pelipperDropVelY;
    /*0x318*/ s16 pelipperDropBallPosX;
    /*0x31A*/ s16 pelipperDropBallPosY;
    /*0x31C*/ s16 pelipperVelX;
    /*0x31E*/ s16 pelipperVelY;
    /*0x320*/ s16 pelipperPosXQ10;
    /*0x322*/ s16 pelipperPosYQ10;
    /*0x324*/ s8 basketSpriteFrame;
    /*0x325*/ u8 filler325[0x1];
    /*0x326*/ u16 basketShakeTimer;
    /*0x328*/ s8 seedotHitFlag;
    /*0x329*/ u8 filler329[0x1];
    /*0x32A*/ u16 seedotDecayTimer;
    /*0x32C*/ s8 seedotAnimPhase[3];
    /*0x32F*/ s8 seedotSpriteFrame[3];
    /*0x332*/ s8 seedotOamFrame[3];
    /*0x335*/ u8 filler335[0x1];
    /*0x336*/ u16 seedotAnimTimer[3];
    /*0x33C*/ u16 seedotOffsetY[3];
    /*0x342*/ s8 edgeBallSideFlag;
    /*0x343*/ s8 cyndaquilCatchReady;
    /*0x344*/ s8 cyndaquilHitPending;
    /*0x345*/ s8 cyndaquilAnimFrame;
    /*0x346*/ s8 cyndaquilAnimPhase;
    /*0x347*/ u8 filler347[0x1];
    /*0x348*/ u16 cyndaquilSubframeTimer;
    /*0x34A*/ s8 edgeTargetHitIndex;
    /*0x34B*/ s8 edgeTargetFlashTimers[10];
    /*0x355*/ s8 edgeHitFxAnimFrame[4];
    /*0x359*/ s8 edgeHitFxTargetIndex[4];
    /*0x35D*/ u8 filler35D[0x1];
    /*0x35E*/ u16 edgeHitFxSubframe[4];
    /*0x366*/ s8 trapDoorGfxState;
    /*0x367*/ s8 catchModeForceOpen;
    /*0x368*/ u16 mosaicShakeTimer;
    /*0x36A*/ s8 targetAnimPhase[2];
    /*0x36C*/ s8 targetHitCountdown[2];
    /*0x36E*/ u16 targetAnimSubframe[2];
    /*0x372*/ u16 targetBounceTimer[2];
    /*0x376*/ u16 evoTargetCooldown;
    /*0x378*/ s8 zigzagoonKickState;
    /*0x379*/ s8 zigzagoonBodyFrame;
    /*0x37A*/ s8 zigzagoonHeadFrame;
    /*0x37B*/ s8 zigzagoonFxFrame;
    /*0x37C*/ s8 zigzagoonKickReady;
    /*0x37D*/ s8 zigzagoonKickKeyframe;
    /*0x37E*/ u16 zigzagoonKickSubframe;
    /*0x380*/ u16 zigzagoonBaseOffsetY;
    /*0x382*/ s8 bossBgPaletteIndex;
    /*0x383*/ s8 bossGrabbedBall;
    /*0x384*/ s8 legendaryHitsRequired;
    /*0x385*/ s8 bonusModeHitCount;
    /*0x386*/ s8 returnToMainBoardFlag;
    /*0x387*/ s8 boardEntityCollisionMode;
    /*0x388*/ s8 bonusCaptureState;
    /*0x389*/ s8 bossHitPaletteState;
    /*0x38A*/ s16 rayquazaSegmentVelocity;
    /*0x38C*/ s16 rayquazaSegmentAltitude;
    /*0x38E*/ s16 bossFieldScrollQ10;
    /*0x390*/ u16 bossCryCountdown;
    /*0x392*/ u16 bonusSequenceTimer;
    /*0x394*/ s16 bonusScrollOffsetY;
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
    /*0x3DC*/ s8 entityState; // State machine for boss/entity behavior (uses _ENTITY_STATE_ constants)
    /*0x3DD*/ s8 entityReturnState;
    /*0x3DE*/ s8 entityDirection; // Entity facing direction from angle lookup
    /*0x3DF*/ s8 entitySpriteFrame;
    /*0x3E0*/ s8 entityWalkCycleCount;
    /*0x3E1*/ s8 entitySubPhase; // Sub-phase counter within entity state
    /*0x3E2*/ s16 entityAnimIndex; // Index into entity animation lookup tables
    /*0x3E4*/ u16 entityAnimTimer; // Sub-frame counter for entity animation step
    /*0x3E6*/ s16 entityAppearDissolveTimer;
    /*0x3E8*/ s16 entityPosXQ10; // Entity X position (divide by 10 for screen coords)
    /*0x3EA*/ s16 entityPosYQ10; // Entity Y position (divide by 10 for screen coords)
    /*0x3EC*/ s16 entityTargetPosX;
    /*0x3EE*/ s16 entityTargetPosY;
    /*0x3F0*/ u16 entityCollisionOriginX;
    /*0x3F2*/ u16 entityCollisionOriginY;
    /*0x3F4*/ s8 kecleonWaypointIndex;
    /*0x3F5*/ s8 kecleonHasAppeared;
    /*0x3F6*/ s8 kecleonFacingRight;
    /*0x3F7*/ s8 kecleonSpriteVisible;
    /*0x3F8*/ s8 kecleonAttackFxSlot;
    /*0x3F9*/ u8 filler3F9[0x1];
    /*0x3FA*/ s16 kecleonBlendAlpha;
    /*0x3FC*/ s16 kecleonAttackFxTimer;
    /*0x3FE*/ u8 filler3FE[0x2];
    /*0x400*/ struct Vector16 kecleonScreenPos;
    /*0x404*/ s8 kecleonScopeDropActive;
    /*0x405*/ s8 kecleonDropSlotIndex;
    /*0x406*/ s8 kecleonScopeHitFlag;
    /*0x407*/ u8 filler407[0x1];
    /*0x408*/ u16 kecleonScopeAnimTimer;
    /*0x40A*/ u16 kecleonScopeDropTimer;
    /*0x40C*/ u16 kecleonBallHitFlashTimer;
    /*0x40E*/ u16 kecleonInvisBlend;
    /*0x410*/ s16 kecleonTileAnimFrame;
    /*0x412*/ s16 kecleonWallAnimFrame;
    /*0x414*/ struct Vector16 scopeVelocity;
    /*0x418*/ struct Vector16 scopePositionQ10;
    /*0x41C*/ s8 kecleonBumperHitTimers[4];
    /*0x420*/ s8 hitFlashTimers[10]; // Per-bumper/target hit flash countdown timers
    /*0x42A*/ s8 kecleonTargetHitTimers[7];
    /*0x431*/ u8 filler431[0x3];
    /*0x434*/ struct Vector16 kecleonPrevBallHitPos[3];
    /*0x440*/ s8 kyogreWhirlpoolActive;
    /*0x441*/ s8 bossSegmentState[2];
    /*0x443*/ s8 segmentMoveTargetIndex[2];
    /*0x445*/ s8 kyogreBodyAnimState;
    /*0x446*/ s8 kyogreBodyAnimEndFrame;
    /*0x447*/ s8 kyogreBodyNextState;
    /*0x448*/ s8 kyogreBodyAnimFrame;
    /*0x449*/ s8 kyogreBodyLoopStartFrame;
    /*0x44A*/ s8 kyogreBodyLoopCount;
    /*0x44B*/ u8 filler44B[0x1];
    /*0x44C*/ u16 kyogreWaterAnimFrame;
    /*0x44E*/ s16 kyogreRotationOffset;
    /*0x450*/ u16 kyogreBgAnimFrame;
    /*0x452*/ u16 bossHitReactionTimer;
    /*0x454*/ u16 bossAttackSubFrame;
    /*0x456*/ u16 bossVortexScaleTimer;
    /*0x458*/ u16 segmentAnimTimers[2]; // Per-segment animation frame counters
    /*0x45C*/ struct Vector16 legendarySegmentPos[2];
    /*0x464*/ struct Vector16 segmentTargetPos[2];
    /*0x46C*/ struct Vector16 rockSpriteScaleOffset[4];
    /*0x47C*/ s8 groudonAttackCycleCount;
    /*0x47D*/ s8 groudonAttackColumn;
    /*0x47E*/ s8 groudonAttackFeedbackTimer;
    /*0x47F*/ s8 bossFlipperEscapeTimer;
    /*0x480*/ u16 bossHitFlashTimer;
    /*0x482*/ u16 groudonFireballChaseTimer;
    /*0x484*/ u16 groudonFireballAngle;
    /*0x486*/ s16 bossGrabDurationTimer;
    /*0x488*/ struct Vector16 groudonFireballPosQ10;
    /*0x48C*/ s8 rockAnimState[4];
    /*0x490*/ s8 rockAnimEndFrame[4];
    /*0x494*/ s8 rockNextState[4];
    /*0x498*/ s8 rockAnimCurrentFrame[4];
    /*0x49C*/ s8 rockAnimLoopStart[4];
    /*0x4A0*/ s8 rockAnimLoopCount[4];
    /*0x4A4*/ s8 rockHitReactionTimer[4];
    /*0x4A8*/ s8 rockDoubleHitCounter[4];
    /*0x4AC*/ u16 rockFrameDelayCounter[4];
    /*0x4B4*/ struct Vector16 rockCollisionPos[4];
    /*0x4C4*/ u16 rockSpawnSequenceTimer;
    /*0x4C6*/ u16 groudonFallAcceleration;
    /*0x4C8*/ s8 bossImpactShakeTimer;
    /*0x4C9*/ u8 groudonQuakeIntensity;
    /*0x4CA*/ u16 groudonQuakeSubTimer;
    /*0x4CC*/ s8 fireRockSpawnSlot[3];
    /*0x4CF*/ s8 fireRockPhase[3];
    /*0x4D2*/ s8 fireRockSpriteFrame[3];
    /*0x4D5*/ s8 fireRockBallHitFlag[3];
    /*0x4D8*/ u16 fireRockPhaseSubFrame[3];
    /*0x4DE*/ s16 fireRockFallSpeed[3];
    /*0x4E4*/ s16 fireRockAltitudeQ10[3];
    /*0x4EA*/ u8 filler4EA[0x2];
    /*0x4EC*/ struct Vector16 fireRockLogicPosQ10[3];
    /*0x4F8*/ struct Vector16 fireRockCollisionPos[3];
    /*0x504*/ u8 rayquazaWindCycleCount;
    /*0x505*/ s8 rayquazaGrabbedSegmentId;
    /*0x506*/ s8 rayquazaCloudPhase;
    /*0x507*/ s8 rayquazaAttackState;
    /*0x508*/ s16 rayquazaDiveFlashTimer;
    /*0x50A*/ s16 rayquazaBrightnessFade;
    /*0x50C*/ u16 rayquazaHitCooldown;
    /*0x50E*/ u16 rayquazaDefeatAnimFrame;
    /*0x510*/ u16 bossPhaseFrame;
    /*0x512*/ u16 rayquazaSwayAngle;
    /*0x514*/ u16 rayquazaWindAnimSubFrame;
    /*0x516*/ u16 rayquazaPhaseTimer; // Phase timer for Rayquaza boss behavior
    /*0x518*/ s16 rayquazaBgScrollSpeed;
    /*0x51A*/ s16 rayquazaScreenY;
    /*0x51C*/ struct Vector16 rayquazaDiveTargetPos;
    /*0x520*/ struct Vector16 segmentGrabRenderPos;
    /*0x524*/ struct Vector16 rayquazaWindOffset;
    /*0x528*/ struct Vector16 minionPositionQ10;
    /*0x52C*/ s8 sealBounceHitCount[2];
    /*0x52E*/ s8 sealBounceDisplayCount[2];
    /*0x530*/ s8 sealBounceActiveSide[3];
    /*0x533*/ s8 sealBounceSubCount[3];
    /*0x536*/ s8 sealBounceAnimState[3];
    /*0x539*/ u8 filler539[0x1];
    /*0x53A*/ u16 sealStageProgressTimer;
    /*0x53C*/ u16 sealBounceInvulnTimer[3];
    /*0x542*/ u16 sealSplashTimer;
    /*0x544*/ u32 sealBonusScoreValue;
    /*0x548*/ s8 sealHitStunTimer[2];
    /*0x54A*/ s8 unk54A;
    /*0x54B*/ s8 entityReturnedFlag[2];
    /*0x54D*/ s8 entityHitCooldown[2];
    /*0x54F*/ s8 entityMovePhase[2];
    /*0x551*/ s8 entitySideChoice[2];
    /*0x553*/ s8 entityAIState[2];
    /*0x555*/ s8 entitySpriteBaseFrame[2];
    /*0x557*/ s8 entitySpawnLane[2];
    /*0x559*/ s8 entityPathWaypointIndex[2];
    /*0x55B*/ s8 entityActionIndex[2];
    /*0x55D*/ s8 entityOamOffsetX[2];
    /*0x55F*/ s8 entityOamOffsetY[2];
    /*0x561*/ u8 filler561[0x1];
    /*0x562*/ u16 entityActionTimer[2];
    /*0x566*/ s16 entityScreenY[2];
    /*0x56A*/ s16 entityScreenX[2];
    /*0x56E*/ u8 filler56E[0x2];
    /*0x570*/ struct Vector16 entityLogicPos[2];
    /*0x578*/ struct Vector16 entityCollisionPos[2];
    /*0x580*/ struct Vector32 entitySpawnPositions[2]; // Q8.8 spawn positions for field entities
    /*0x590*/ s8 unk590;
    /*0x591*/ s8 sealSplashAnimIndex;
    /*0x592*/ u16 sealSplashSubTimer;
    /*0x594*/ u16 unk594;
    /*0x596*/ u16 unk596;
    /*0x598*/ u16 currentSpecies; // Current catch/hatch mode species? Is it evo mode as well?
    /*0x59A*/ u16 evoTargetSpecies;
    /*0x59C*/ u16 lastCatchSpecies; // Previous catch mode species?
    /*0x59E*/ u16 lastEggSpecies; // Previous hatch/evo mode species?
    /*0x5A0*/ u16 lastEvolvedSpecies;
    /*0x5A2*/ u16 savedHatchSpecies;
    /*0x5A4*/ u8 catchModeHitPhase;
    /*0x5A5*/ u8 catchModeHitCount;
    /*0x5A6*/ u16 entityCaptureTimer; // Animation timer for entity capture/defeat sequence
    /*0x5A8*/ s8 captureSequencePhase;
    /*0x5A9*/ u8 catchHitReactionTimer;
    /*0x5AA*/ u16 catchHitInvulnTimer;
    /*0x5AC*/ s32 captureArcRadius;
    /*0x5B0*/ u16 captureArcAngle;
    /*0x5B2*/ s8 ballCollisionDisabled; // Suppresses ball collision reactions when set
    /*0x5B3*/ u8 filler5B3[0x6];
    /*0x5B9*/ s8 hatchShardGravity[6];
    /*0x5BF*/ u8 filler5BF[0x1];
    /*0x5C0*/ struct Vector16 hatchShardPosition[6];
    /*0x5D8*/ struct Vector16 hatchShardVelocity[6];
    /*0x5F0*/ u16 caughtMonCount; // Number of mons caught in this game
    /*0x5F2*/ s8 catchCollisionActive;
    /*0x5F3*/ s8 centerHoleAttractionActive;
    /*0x5F4*/ u16 centerHoleCaptureProgress;
    /*0x5F6*/ s8 ballUpgradeType;
    /*0x5F7*/ u8 ballLocked;
    /*0x5F8*/ u16 ballUpgradeCounter;
    /*0x5FA*/ s8 bossActive; // Flag: boss entity is active, locks viewport behavior
    /*0x5FB*/ s8 scrollNudgeActive; // Flag enabling gradual scroll nudge
    /*0x5FC*/ s16 scrollNudgeY; // Current smooth scroll Y nudge offset
    /*0x5FE*/ s16 scrollNudgeTargetY; // Target value for scrollNudgeY
    /*0x600*/ u16 triggerButtonCooldown;
    /*0x602*/ s8 hatchTileAnimPhase;
    /*0x603*/ s8 hatchRevealKeyframe;
    /*0x604*/ u16 hatchTileAnimTimer;
    /*0x606*/ u16 hatchParticleFrame;
    /*0x608*/ u16 travelIntroSubFrame;
    /*0x60A*/ s8 travelIntroSegmentIndex;
    /*0x60B*/ s8 unk60B;
    /*0x60C*/ s16 travelSpriteX;
    /*0x60E*/ s16 travelSpriteY;
    /*0x610*/ u16 travelSpriteVelX;
    /*0x612*/ u16 travelSpriteVelY;
    /*0x614*/ s16 lastBallImpactVelocityY;
    /*0x616*/ u16 impactVelocitySampleCooldown;
    /*0x618*/ u16 pikachuChargeFrame;
    /*0x61A*/ s16 pikachuChargeCycleLength;
    /*0x61C*/ s8 inputLockActive;
    /*0x61D*/ u8 filler61D;
    /*0x61E*/ u16 captureLockdownTimer;
    /*0x620*/ struct Vector16 captureOriginPosition;
    /*0x624*/ s8 bumperHitCountdown; // 2 when Hit, one frame of ignored collision, then ready to hit again
    /*0x625*/ s8 hatchTilesBumperAcknowledged;
    /*0x626*/ s8 evoItemAnimKeyframe;
    /*0x627*/ u8 filler627[0x1];
    /*0x628*/ u16 evoItemAnimSubFrame;
    /*0x62A*/ u8 hatchCompletionCount;
    /*0x62B*/ u8 catchCompletionCount;
    /*0x62C*/ u8 evolutionCompletionCount;
    /*0x62D*/ u8 bonusStageEntryCount;
    /*0x62E*/ u8 pondBonusHitCount;
    /*0x62F*/ u8 savedBonusMultiplier;
    /*0x630*/ u32 endBallBonusScoreLo;
    /*0x634*/ u32 endBallBonusScoreHi;
    /*0x638*/ s8 tallyReelPhase;
    /*0x639*/ s8 tallyCalculationDone;
    /*0x63A*/ u16 tallyScrollPosition;
    /*0x63C*/ s8 tallyRowDirtyFlags[3][20];
    /*0x678*/ s8 tallyRowTileIds[3][20];
    /*0x6B4*/ u32 pendingBonusScoreLo;
    /*0x6B8*/ u32 pendingBonusScoreHi;
    /*0x6BC*/ s8 travelModeProgress;
    /*0x6BD*/ s8 rubyPondStage;
    /*0x6BE*/ s8 pondStageTransitionActive;
    /*0x6BF*/ u8 filler6BF[0x1];
    /*0x6C0*/ u16 pondTransitionFrame;
    /*0x6C2*/ u16 pondBannerTriggerDelay;
    /*0x6C4*/ s8 hatchRevealState;
    /*0x6C5*/ s8 hatchTileRevealState;
    /*0x6C6*/ s8 hatchTilesBoardAcknowledged;
    /*0x6C7*/ s8 hatchSequentialTilesRevealed;
    /*0x6C8*/ s8 selectedHatchTileIndex;
    /*0x6C9*/ s8 remainingHatchTileCount;
    /*0x6CA*/ u16 hatchSequentialTileRevealFrameAnimTimer;
    /*0x6CC*/ s8 hatchFrameId;
    /*0x6CD*/ u8 hatchTileShuffleOrder[6];
    /*0x6D3*/ u8 pondEntityPaletteIds[6];
    /*0x6D9*/ s8 portraitAreaLookupIds[2];
    /*0x6DB*/ u8 spriteLayerPriority;
    /*0x6DC*/ u8 slotReelResult;
    /*0x6DD*/ s8 slotReelConfirmed;
    /*0x6DE*/ u16 plungerAnimFrame;
    /*0x6E0*/ s16 slotReelVisualFrame;
    /*0x6E2*/ u8 filler6E2[0x2];
    /*0x6E4*/ struct Vector16 bossGroupBasePosition;
    /*0x6E8*/ s8 slotReelHalted;
    /*0x6E9*/ s8 slotReelRound;
    /*0x6EA*/ s8 slotReelEntryPoolSize;
    /*0x6EB*/ s8 slotReelCurrentEntryIndex;
    /*0x6EC*/ s8 slotReelResultPair[2];
    /*0x6EE*/ u16 allHolesCompleteCooldown;
    /*0x6F0*/ u16 slotReelSpinPosition;
    /*0x6F2*/ u16 slotReelFramesPerCycle;
    /*0x6F4*/ u16 slotReelDecelerationTimer;
    /*0x6F6*/ u16 slotReelDecelerationTotal;
    /*0x6F8*/ u16 slotReelEntries[6];
    /*0x704*/ u16 slotReelStartPosition;
    /*0x706*/ u8 filler706[0x2];
    /*0x708*/ u32 portraitAnimCounter;
    /*0x70C*/ u16 renderAnimCounter;
    /*0x70E*/ s8 bonusMultiplier;
    /*0x70F*/ s8 unk70F;
    /*0x710*/ s8 holeIndicators[4]; // 'HOLE' light indicators in Ruby/Sapphire field
    /*0x714*/ s8 allHolesCompleted;
    /*0x715*/ u8 holeCompletionFlashTimer;
    /*0x716*/ u8 slingshotHitAnimTimer;
    /*0x717*/ u8 slingshotSide;
    /*0x718*/ s8 ballPowerUpLight[3];
    /*0x71B*/ s8 ballUpgradeTriggered;
    /*0x71C*/ u8 ballUpgradeAnimTimer;
    /*0x71D*/ s8 bumperHitTimers[3]; // Per-bumper collision reaction timers
    /*0x720*/ u8 bumperFlashAnimTimer;
    /*0x721*/ s8 bumperFlashTargetA;
    /*0x722*/ s8 bumperFlashTargetB;
    /*0x723*/ s8 activatedBumperCount;
    /*0x724*/ u16 modeTimerFrames;
    /*0x726*/ s8 timerIndicatorVisible;
    /*0x727*/ u8 filler727[0x1];
    /*0x728*/ s8 catchModeBlinkActive;
    /*0x729*/ s8 hatchModeBlinkActive;
    /*0x72A*/ s8 trapDisplayBlinkActive;
    /*0x72B*/ s8 scoreMultiplierLevel;
    /*0x72C*/ u16 scoreMultiplierDecayTimer;
    /*0x72E*/ s8 savedEvoHitCount;
    /*0x72F*/ s8 savedCatchArrows;
    /*0x730*/ s8 ballSpriteVariant; // Ball sprite graphics variant (0=normal, 1/2=alternate)
    /*0x731*/ s8 catchArrowIndicatorBlink;
    /*0x732*/ s8 boardTargetState; // Collision target state tracking for board interactions
    /*0x733*/ u8 filler733[0x1];
    /*0x734*/ s16 spriteToggleFrame; // Alternates 0/1 for sprite animation toggle
    /*0x736*/ s8 catchArrowGfxState[3];
    /*0x739*/ s8 prevCatchArrowGfxState[3];
    /*0x73C*/ u8 activeEvoHitCount; // TODO: unknown type
    /*0x73D*/ s8 catchModeArrows;   // Affects which encounter table is used per area
    /*0x73E*/ u8 filler73E[0x2];
    /*0x740*/ u8 debugMenuSelection;
    /*0x741*/ u8 filler741[0x3];
    /*0x744*/ u8 pondEntitySpriteFrame[2];
    /*0x746*/ u8 cyndaquilGfxFrame; // Cyndaquil sprite frame index on Ruby stage
    /*0x747*/ u8 portraitRenderMode[2];
    /*0x749*/ u8 portraitSpeciesId[2];
    /*0x74B*/ u8 filler74B[0x1];
    /*0x74C*/ volatile u8 savedObjPalette[2][OBJ_PLTT_SIZE];
    /*0xB4C*/ volatile u8 savedBgPalette[2][BG_PLTT_SIZE];
    /*0xF4C*/ struct SongHeader *savedBgmSongHeader;
    /*0xF50*/ u8 fillerF50[0x8];
    /*0xF58*/ struct BgOffsets bgOffsets0;
    /*0xF5C*/ struct BgOffsets bgOffsets1;
    /*0xF60*/ struct BgOffsets bgOffsets2;
    /*0xF64*/ struct BgOffsets bgOffsets3;
    /*0xF68*/ u16 savedSpriteGroupAvailable[2][100];
    /*0x10F8*/u8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x10FD*/u8 field;
    /*0x10FE*/u8 savedCurrentField;
    /*0x10FF*/u8 savedIsBonusField;
    /*0x1100*/u8 pauseInputLocked;
    /*0x1101*/u8 savedModeChangeFlags;
    /*0x1102*/u8 savedDebugOption;
    /*0x1103*/u8 savedPendingModeChangeFlags;
    /*0x1104*/s8 pauseMenuCursorIndex; //Pause Menu Pointer index
    /*0x1105*/u8 filler1105[0x1];
    /*0x1106*/volatile u16 savedBlendControl;
    /*0x1108*/volatile u16 savedBlendAlpha;
    /*0x110A*/volatile u16 savedBlendBrightness;
    /*0x110C*/u16 savedBlendScanlineEnabled;
    /*0x110E*/u16 savedVCount;
    /*0x1110*/volatile u16 savedBlendControlForRestore;
    /*0x1112*/volatile u16 savedBlendAlphaForRestore;
    /*0x1114*/volatile u16 savedBlendBrightnessForRestore;
    /*0x1116*/u16 savedBlendScanlineEnabledForRestore;
    /*0x1118*/u16 savedVCountForRestore;
    /*0x111A*/u16 savedObjPaletteForPause[OBJ_PLTT_SIZE / 0x20][0x10];
    /*0x131A*/u8 filler131A[0x2];
    /*0x131C*/u32 pauseMenuAnimFrame; //Time since paused
    /*0x1320*/s16 unk1320;
    /*0x1322*/s16 unk1322;
    /*0x1324*/s16 unk1324;
    /*0x1326*/s16 unk1326;
    /*0x1328*/u16 unk1328;
    /*0x132A*/u8 filler132A[0x2];
    /*0x132C*/struct BallState *ball;
    /*0x1330*/struct BallState *ballInstancesBase;
    /*0x1334*/struct BallState ballInstances[2];
    /*0x13BC*/struct FlipperState flipper[2];
    /*0x13D4*/u16 unk13D4[10];
    /*0x13E8*/struct Vector16 unk13E8[10];
} /* size=0x1410 */;

struct CollisionTableConfig
{
    /*0x0*/ u8 newPresses;
    /*0x1*/ u8 releases;
    /*0x2*/ u8 held;
};

struct FieldLayout
{
    /* These field offsets are intentionally kept as relative to
       struct BoardConfig to make decompiling easier. This struct
       is basically always accessed relative to struct BoardConfig. */
    /*0x14*/ s16 initialScrollX;
    /*0x16*/ s16 initialScrollY;
    /*0x18*/ s16 cameraScrollMaxY;
    /*0x1A*/ s16 cameraScrollMinY;
    /*0x1C*/ u16 flipperYOffset;
    /*0x1E*/ u8 filler1E[0x2];
    /*0x20*/ s16 flipperRegionCenterY;
    /*0x22*/ s16 leftFlipperOriginX;
    /*0x24*/ s16 rightFlipperOriginX;
    /*0x26*/ s16 ballStartX;
    /*0x28*/ s16 ballStartY;
    /*0x2A*/ s16 ballLossY;
    /*0x2C*/ u8 *objPaletteData[3];
    /*0x38*/ const s16 *collisionTileMap[4];
    /*0x48*/ const u16 *collisionPropertyMap[4];
    /*0x58*/ const u8 *collisionSubtypeMap[4];
};

struct BoardConfig
{
    /*0x00*/ u8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x05*/ bool8 rumbleEnabled;
    /*0x06*/ s16 idleTimeoutFrames; // Max frames before idle demo starts
    /*0x08*/ s16 demoFrameCount; // Frames elapsed in current demo
    /*0x0A*/ u8 fillerA[0x2];
    /*0x0C*/ struct PinballGame *initialGameState; // Template game state for field
    /*0x10*/ struct CollisionTableConfig *demoInputData; // Demo input replay data
    /*0x14*/ struct FieldLayout fieldLayout;
    /*0x68*/ const u16 *flipperCollisionData; // Flipper collision lookup table
};

struct FlipperLineSegment
{
    u16 startX;
    u16 startY;
    u16 endX;
    u16 endY;
};

extern struct PinballGame *gCurrentPinballGame;
extern const StateFunc gIdlePinballGameStateFuncs[];
extern u32 gDemoPlaybackFrame;
extern struct BoardConfig gBoardConfig;
extern u8 gSpriteSlotMap[];
extern u16 gUnknown_08137B3C[][6][16];
extern u16 gUnknown_08137D40[]; 
extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gDusclopsBonusClear_Gfx[];
extern struct CollisionTableConfig gDemoInputData0;
extern struct CollisionTableConfig gDemoInputData2;
extern struct CollisionTableConfig gDemoInputData3;
extern struct CollisionTableConfig gDemoInputData1;
extern struct PinballGame gDemoInitState0;
extern struct PinballGame gDemoInitState2;
extern struct PinballGame gDemoInitState3;
extern struct PinballGame gDemoInitState1;
extern s32 gUnknown_081B36A4[64];
extern s32 gUnknown_082EE0E0[0x3E0];
extern u16 gUnknown_0832D604[0x1600];
extern u16 gUnknown_08330204[0x1600];
extern u16 gUnknown_08340B58[];
extern u16 gUnknown_083499D8[];
extern u16 gUnknown_0834DBD8[];
extern u16 gUnknown_083579C8[0x3800];
extern u16 gUnknown_0835E9C8[0x2A80];
extern const u16 gUnknown_08391A4C[0x1000];
extern const u16 gUnknown_08393A4C[0x1000];
extern u8 gUnknown_083FE44C[][0x200];
extern u16 gDusclopsBoardDusclopsAppearFx_Gfx[]; 
extern u16 gDusclopsBoardDusclops_Gfx[]; 
extern u8 gDusclopsBoardDusclopsBallGrabSwirl_Gfx[];
extern struct SongHeader se_unk_8b;
extern struct SongHeader se_dusclops_appear;
extern const s16 gUnknown_086ACDF4[9]; //Possibly only 4, with a gap?
extern const s16 gUnknown_086ACDF4[9];
typedef s16 (*Unk86ACE0C)(struct Vector16*, u16*);
extern Unk86ACE0C BoardCollisionFuncts_086ACE0C[8];
extern struct Vector16 gUnknown_086ACE60[4];
extern struct FlipperLineSegment gUnknown_086ACE8C[13];
extern u16 gUnknown_086ACEF4[2];
extern const u8 *const gUnknown_086ACEF8[];
extern const u8 *const gUnknown_086ACF18[];
extern s16 DuclopsFramesetData[][2];
extern u16 gUnknown_086B4568[14][45];
extern const u8 gUnknown_084F61EC[]; 
extern u8 gUnknown_081B45A4[]; 
extern const u16 gUnknown_086AD2DE[];
extern u8 gUnknown_081B8984[];
extern u8 gUnknown_081B8784[];
extern u8 gUnknown_081B4584[];
extern u8 gUnknown_081B4784[];
extern const u16 gUnknown_086AD000[][4];
extern u32 gUnknown_086AD50C[];

extern const u16 gUnknown_08252B10[];
extern const u16 gUnknown_083071D4[];


extern u8 *gMonPortraitGroupGfx[];
extern u8 *gMonPortraitGroupPals[];
extern u8 gUnknown_02030760[];
extern u8 gUnknown_02031060[];
extern const u8 gUnknown_08395A4C[];
extern const u8 gUnknown_08397E6C[];
extern const u8 gUnknown_083A8EEC[][0x300];
extern const u8 gUnknown_083BB16C[][0x80];
extern const u8 gUnknown_083BD36C[][0x200];
extern const u8 gMainStageBonusTrap_Gfx[][0x300];
extern const u8 gUnknown_0848D68C[][0x300];
extern const u8 gUnknown_084C00EC[][0x80];
extern const u8 gUnknown_084C07EC[];
extern const u8 gMainBoardPikaSpinner_Gfx[][0x120];
extern const u8 gUnknown_084FD18C[][0x200];
extern const u8 *gUnknown_086AD49C[];
extern const u16 gUnknown_086AD2EE[][4];

#endif // GUARD_GLOBAL_H