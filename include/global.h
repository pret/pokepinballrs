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
    /*0x00*/ s8 unk0;
    /*0x01*/ s8 oamPriority;
    /*0x02*/ u8 filler2[0x2];
    /*0x04*/ u16 unk4;
    /*0x06*/ s16 unk6;
    /*0x08*/ s16 unk8;
    /*0x0A*/ u16 unkA;
    /*0x0C*/ u16 unkC;
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
    /*0x02*/ s8 unk2;
    /*0x03*/ s8 unk3;
    /*0x04*/ s8 unk4;
    /*0x05*/ s8 unk5;
    /*0x06*/ s8 active;
    /*0x07*/ u8 stallTicks;
    /*0x08*/ s8 unk8;
    /*0x09*/ u8 filler9[0x3];
};

struct PinballGame
{
    /*0x000*/ u32 unk0;
    /*0x004*/ u8 newButtonActions[5]; // e.g. player pressing the appropriate buttons to trigger the left flipper action, etc.
    /*0x009*/ u8 releasedButtonActions[5];
    /*0x00E*/ u8 heldButtonActions[5];
    /*0x013*/ s8 unk13; // Current field state. In main fields seems to be related to the 3 Pokeballs that unlock bonus fields, in bonus fields acts as a field state
    /*0x014*/ s8 unk14;
    /*0x015*/ s8 unk15;
    /*0x016*/ s8 unk16;
    /*0x017*/ s8 unk17;
    /*0x018*/ u16 unk18;
    /*0x01A*/ s8 unk1A;
    /*0x01B*/ u8 unk1B;
    /*0x01C*/ bool8 scoreCounterAnimationEnabled;
    /*0x01D*/ u8 unk1D;
    /*0x01E*/ u8 unk1E;
    /*0x01F*/ u8 unk1F;
    /*0x020*/ u8 unk20;
    /*0x021*/ u8 unk21;
    /*0x022*/ s8 unk22;
    /*0x023*/ u8 unk23; // Holds the value of some enum state
    /*0x024*/ s8 unk24;
    /*0x025*/ s8 unk25;
    /*0x026*/ u16 unk26;
    /*0x028*/ u16 unk28;
    /*0x02A*/ u16 unk2A;
    /*0x02C*/ int unk2C;
    /*0x030*/ s8 numLives;
    /*0x031*/ u8 ballSpeed;
    /*0x032*/ s8 unk32;
    /*0x033*/ s8 unk33;
    /*0x034*/ s8 unk34;
    /*0x035*/ s8 area;
    /*0x036*/ s8 unk36;
    /*0x038*/ u32 scoreAddStepSize; //score to add every frame until scoreAddedInFrame score has been added to player's total
    /*0x03C*/ u32 scoreAddedInFrame; //score to add in a bonus field or mode (by completion or other ways, like hitting Duskulls)
    /*0x040*/ u32 scoreAdditionAccumulator; //score left to be counted up on the score registers
    /*0x044*/ u32 scoreLo; //counts score until 99_999_999, overflows into scoreHi
    /*0x048*/ u32 scoreHi; //counts score until 9_999, then freezes total score to 999_999_999_999!
    /*0x04C*/ s16 unk4C;
    /*0x04E*/ s16 unk4E;
    /*0x050*/ u8 filler50[0x4];
    /*0x054*/ u32 unk54;
    /*0x058*/ u16 unk58;
    /*0x05A*/ u16 unk5A;
    /*0x05C*/ s16 unk5C;
    /*0x05E*/ u8 filler5E[0x2];
    /*0x060*/ struct Vector16 unk60;
    /*0x064*/ s16 unk64;
    /*0x066*/ u16 unk66;
    /*0x068*/ s16 unk68;
    /*0x06A*/ s16 unk6A;
    /*0x06C*/ u16 timerBonus; //Additional time to be added to next timed event (Only for bonus fields or all timers?)
    /*0x06E*/ s8 unk6E;
    /*0x06F*/ s8 unk6F;
    /*0x070*/ s8 unk70;
    /*0x071*/ s8 unk71;
    /*0x072*/ s8 unk72;
    /*0x073*/ s8 unk73;
    /*0x074*/ u16 unk74[4];
    /*0x07C*/ u16 unk7C;
    /*0x07E*/ u16 unk7E;
    /*0x080*/ s16 unk80;
    /*0x082*/ s16 unk82;
    /*0x084*/ struct Vector16 unk84[4];
    /*0x094*/ u8 filler94[0x28];
    /*0x0BC*/ s16 unkBC;
    /*0x0BE*/ s16 unkBE;
    /*0x0C0*/ s16 unkC0;
    /*0x0C2*/ s16 unkC2;
    /*0x0C4*/ u16 unkC4;
    /*0x0C6*/ u16 unkC6;
    /*0x0C8*/ u8 fillerC8[0x2];
    /*0x0CA*/ s16 unkCA;
    /*0x0CC*/ s16 unkCC;
    /*0x0CE*/ u16 unkCE;
    /*0x0D0*/ struct Vector16 unkD0[5];
    /*0x0E4*/ u8 unkE4;
    /*0x0E6*/ s16 unkE6;
    /*0x0E8*/ s16 unkE8;
    /*0x0EA*/ u16 unkEA;
    /*0x0EC*/ u16 unkEC;
    /*0x0EE*/ s16 unkEE;
    /*0x0F0*/ u16 unkF0;
    /*0x0F2*/ s8 unkF2;
    /*0x0F3*/ u8 unkF3;
    /*0x0F4*/ s16 unkF4;
    /*0x0F6*/ s16 unkF6;
    /*0x0F8*/ s16 unkF8;
    /*0x0FA*/ s8 unkFA;
    /*0x0FB*/ s8 unkFB;
    /*0x0FC*/ s16 unkFC;
    /*0x0FE*/ s16 unkFE;
    /*0x100*/ s32 unk100;
    /*0x104*/ s32 unk104;
    /*0x108*/ s16 unk108;
    /*0x10A*/ s16 unk10A;
    /*0x10C*/ s16 unk10C;
    /*0x10E*/ s16 unk10E;
    /*0x110*/ s32 unk110;
    /*0x114*/ s32 unk114;
    /*0x118*/ s8 unk118[4];
    /*0x11C*/ s8 unk11C[4];
    /*0x120*/ s8 unk120;
    /*0x121*/ s8 unk121;
    /*0x122*/ s8 unk122;
    /*0x123*/ s8 unk123;
    /*0x124*/ s8 unk124;
    /*0x125*/ s8 unk125;
    /*0x126*/ s8 unk126;
    /*0x127*/ s8 unk127;
    /*0x128*/ u8 unk128;
    /*0x129*/ s8 unk129;
    /*0x12A*/ u8 unk12A;
    /*0x12B*/ s8 forceSpecialMons;  // When on, force next catch mode species to be special mons
    /*0x12C*/ s8 forcePichuEgg;     // When on, force next egg mode species to be Pichu
    /*0x12D*/ u8 filler12D;
    /*0x12E*/ s16 totalWeight;       // Added weight of all possible mons in area
    /*0x130*/ s16 speciesWeights[25]; // Weight of each species
    /*0x162*/ s8 forcePondToWhiscash;
    /*0x163*/ s8 unk163;
    /*0x164*/ s8 unk164;
    /*0x165*/ s8 unk165;
    /*0x166*/ u16 unk166;
    /*0x168*/ u16 unk168;
    /*0x16A*/ s16 unk16A;
    /*0x16C*/ s8 rubyPondState;
    /*0x16D*/ u8 filler16D[0x1];
    /*0x16E*/ s8 unk16E;
    /*0x16F*/ s8 rubyPondContentsChanging;
    /*0x170*/ s8 unk170[3];
    /*0x173*/ u8 unk173;
    /*0x174*/ u16 rubyPondChangeTimer;
    /*0x176*/ u8 unk176;
    /*0x177*/ u8 filler177[0x1];
    /*0x178*/ struct Vector16 rubyBumperLogicPosition[3]; //chinchou or lotad
    /*0x184*/ struct Vector16 rubyBumperCollisionPosition[3]; //chinchou or lotad
    /*0x190*/ s16 unk190;
    /*0x192*/ u8 coins;
    /*0x193*/ s8 unk193;
    /*0x194*/ s8 unk194;
    /*0x195*/ s8 unk195;
    /*0x196*/ u16 unk196;
    /*0x198*/ s16 unk198[2];
    /*0x19C*/ struct Vector16 unk19C[2];
    /*0x1A4*/ s8 unk1A4;
    /*0x1A5*/ s8 unk1A5;
    /*0x1A6*/ s8 unk1A6;
    /*0x1A7*/ s8 unk1A7;
    /*0x1A8*/ s8 unk1A8;
    /*0x1A9*/ u8 unk1A9;
    /*0x1AA*/ s8 unk1AA;
    /*0x1AB*/ s8 unk1AB;
    /*0x1AC*/ s8 unk1AC;
    /*0x1AD*/ s8 unk1AD;
    /*0x1AE*/ u8 unk1AE;
    /*0x1AF*/ u8 unk1AF;
    /*0x1B0*/ s8 unk1B0;
    /*0x1B1*/ u8 filler1B1[0x1];
    /*0x1B2*/ u16 unk1B2;
    /*0x1B4*/ u16 unk1B4;
    /*0x1B6*/ u16 unk1B6;
    /*0x1B8*/ s16 unk1B8;
    /*0x1BA*/ u16 unk1BA;
    /*0x1BC*/ u16 unk1BC;
    /*0x1BE*/ s8 unk1BE;
    /*0x1BF*/ u8 filler1BF[0x1];
    /*0x1C0*/ u16 unk1C0;
    /*0x1C2*/ s8 unk1C2;
    /*0x1C3*/ u8 filler1C3[0x1];
    /*0x1C4*/ u16 unk1C4;
    /*0x1C6*/ s16 unk1C6;
    /*0x1C8*/ s16 unk1C8;
    /*0x1CA*/ s16 unk1CA;
    /*0x1CC*/ s16 unk1CC;
    /*0x1CE*/ u16 unk1CE;
    /*0x1D0*/ u16 unk1D0;
    /*0x1D2*/ u16 unk1D2;
    /*0x1D4*/ u16 unk1D4;
    /*0x1D6*/ u16 unk1D6;
    /*0x1D8*/ u16 unk1D8;
    /*0x1DA*/ u16 unk1DA;
    /*0x1DC*/ u16 unk1DC;
    /*0x1DE*/ u16 unk1DE;
    /*0x1E0*/ u16 unk1E0;
    /*0x1E2*/ s8 outLanePikaPosition; //Pikachu coverage. 0= left lane, 1=right lane, 2 = both
    /*0x1E3*/ s8 unk1E3[2];
    /*0x1E5*/ s8 unk1E5;
    /*0x1E6*/ s8 unk1E6;
    /*0x1E7*/ u8 filler1E7[0x1];
    /*0x1E8*/ s16 unk1E8;
    /*0x1EA*/ s16 unk1EA;
    /*0x1EC*/ s8 unk1EC;
    /*0x1ED*/ s8 unk1ED;
    /*0x1EE*/ s8 unk1EE;
    /*0x1EF*/ u8 unk1EF;
    /*0x1F0*/ u16 unk1F0;
    /*0x1F2*/ u8 unk1F2;
    /*0x1F3*/ u8 unk1F3;
    /*0x1F4*/ s16 unk1F4;
    /*0x1F6*/ s16 unk1F6;
    /*0x1F8*/ s16 unk1F8;
    /*0x1FA*/ s16 unk1FA;
    /*0x1FC*/ s32 unk1FC;
    /*0x200*/ s32 unk200;
    /*0x204*/ s8 unk204;
    /*0x205*/ u8 filler205[0x1];
    /*0x206*/ u16 unk206;
    /*0x208*/ u16 unk208;
    /*0x20A*/ s8 unk20A;
    /*0x20B*/ s8 unk20B;
    /*0x20C*/ s8 unk20C;
    /*0x20D*/ u8 filler20D[0x1];
    /*0x20E*/ s16 unk20E;
    /*0x210*/ u16 unk210;
    /*0x212*/ u16 unk212[10];
    /*0x228*/ struct Vector16 unk228[10];
    /*0x250*/ u16 unk250;
    /*0x252*/ u16 unk252;
    /*0x254*/ u8 filler254[0x4];
    /*0x258*/ s16 unk258;
    /*0x25A*/ s16 unk25A;
    /*0x25C*/ s8 unk25C;
    /*0x25D*/ s8 unk25D;
    /*0x25E*/ s8 unk25E;
    /*0x25F*/ s8 unk25F;
    /*0x260*/ s8 unk260[3];
    /*0x263*/ s8 unk263[8];
    /*0x26B*/ s8 unk26B;
    /*0x26C*/ s8 unk26C;
    /*0x26D*/ u8 filler26D[0x1];
    /*0x26E*/ u16 unk26E;
    /*0x270*/ u8 evolvablePartySpecies[MAX_EVOLVABLE_PARTY_SIZE];
    /*0x280*/ s8 evolvingPartyIndex;
    /*0x281*/ s8 evolvablePartySize;
    /*0x282*/ s8 unk282;
    /*0x283*/ u8 numCompletedBonusStages;
    /*0x284*/ s8 unk284; // Bonus Field to transition to?
    /*0x285*/ u8 filler285[0x1];
    /*0x286*/ u16 unk286;
    /*0x288*/ s16 unk288;
    /*0x28A*/ s16 unk28A;
    /*0x28C*/ u8 filler28C[0x4];
    /*0x290*/ u32 unk290;
    /*0x294*/ s8 unk294;
    /*0x295*/ u8 unk295;
    /*0x296*/ u16 eventTimer; //Timer for events (Only bonus fields or all events?)
    /*0x298*/ u16 unk298;
    /*0x29A*/ u16 unk29A;
    /*0x29C*/ u16 unk29C;
    /*0x29E*/ u8 unk29E;
    /*0x29F*/ s8 unk29F;
    /*0x2A0*/ u16 unk2A0;
    /*0x2A2*/ s8 whiscashState;
    /*0x2A3*/ s8 unk2A3; //Whiscash alternating invuln timer?
    /*0x2A4*/ s8 shouldProcessWhiscash;
    /*0x2A5*/ s8 whiscashFrameIx;
    /*0x2A6*/ u16 whiscashStateTimer;
    /*0x2A8*/ u16 pondSwitchesSinceLastWhiscash;
    /*0x2AA*/ u16 unk2AA;
    /*0x2AC*/ s16 unk2AC;
    /*0x2AE*/ u8 filler2AE[0x2];
    /*0x2B0*/ u16 unk2B0;
    /*0x2B2*/ s8 unk2B2;
    /*0x2B3*/ u8 filler2B3[0x1];
    /*0x2B4*/ s16 unk2B4;
    /*0x2B6*/ s16 unk2B6;
    /*0x2B8*/ u16 unk2B8;
    /*0x2BA*/ u16 unk2BA;
    /*0x2BC*/ u16 unk2BC;
    /*0x2BE*/ s8 unk2BE;
    /*0x2C0*/ u16 unk2C0;
    /*0x2C2*/ s8 unk2C2;
    /*0x2C3*/ s8 unk2C3;
    /*0x2C4*/ u16 unk2C4;
    /*0x2C6*/ u16 unk2C6;
    /*0x2C8*/ s16 unk2C8;
    /*0x2CA*/ s16 unk2CA;
    /*0x2CC*/ s16 unk2CC;
    /*0x2CE*/ s16 unk2CE;
    /*0x2D0*/ s8 unk2D0;
    /*0x2D1*/ u8 filler2D1[3];
    /*0x2D4*/ u16 unk2D4;
    /*0x2D6*/ u16 unk2D6;
    /*0x2D8*/ s8 unk2D8;
    /*0x2D9*/ s8 unk2D9;
    /*0x2DA*/ s8 unk2DA;
    /*0x2DB*/ u8 filler2DB[0x3];
    /*0x2DE*/ u16 unk2DE;
    /*0x2E0*/ u16 unk2E0;
    /*0x2E2*/ s8 unk2E2;
    /*0x2E3*/ s8 unk2E3[2];
    /*0x2E5*/ s8 unk2E5[2];
    /*0x2E7*/ u8 filler2E7[0x1];
    /*0x2E8*/ u16 unk2E8[2];
    /*0x2EC*/ s16 unk2EC[2];
    /*0x2F0*/ u8 unk2F0;
    /*0x2F1*/ u8 unk2F1;
    /*0x2F2*/ u16 unk2F2;
    /*0x2F4*/ s8 unk2F4; //Sharpedo/Wailmer Oam Ix
    /*0x2F5*/ s8 unk2F5; //Sharpedo tile variant Ix
    /*0x2F6*/ u16 unk2F6;
    /*0x2F8*/ s8 unk2F8;
    /*0x2F9*/ s8 unk2F9;
    /*0x2FA*/ s8 unk2FA;
    /*0x2FB*/ s8 unk2FB;
    /*0x2FC*/ s8 unk2FC;
    /*0x2FD*/ s8 unk2FD;
    /*0x2FE*/ u16 unk2FE;
    /*0x300*/ s8 unk300;
    /*0x301*/ s8 unk301;
    /*0x302*/ s8 unk302;
    /*0x303*/ s8 unk303;
    /*0x304*/ u16 unk304;
    /*0x306*/ s8 unk306;
    /*0x307*/ s8 unk307;
    /*0x308*/ u16 bumperHitsSinceReset;
    /*0x30A*/ u16 unk30A;
    /*0x30C*/ u16 unk30C;
    /*0x30E*/ s16 unk30E;
    /*0x310*/ s16 unk310;
    /*0x312*/ u8 filler312[0x2];
    /*0x314*/ s16 unk314;
    /*0x316*/ s16 unk316;
    /*0x318*/ s16 unk318;
    /*0x31A*/ s16 unk31A;
    /*0x31C*/ s16 unk31C;
    /*0x31E*/ s16 unk31E;
    /*0x320*/ s16 unk320;
    /*0x322*/ s16 unk322;
    /*0x324*/ s8 unk324;
    /*0x325*/ u8 filler325[0x1];
    /*0x326*/ u16 unk326;
    /*0x328*/ s8 unk328;
    /*0x329*/ u8 filler329[0x1];
    /*0x32A*/ u16 unk32A;
    /*0x32C*/ s8 unk32C[3];
    /*0x32F*/ s8 unk32F[3];
    /*0x332*/ s8 unk332[3];
    /*0x335*/ u8 filler335[0x1];
    /*0x336*/ u16 unk336[3];
    /*0x33C*/ u16 unk33C[3];
    /*0x342*/ s8 unk342;
    /*0x343*/ s8 unk343;
    /*0x344*/ s8 unk344;
    /*0x345*/ s8 unk345;
    /*0x346*/ s8 unk346;
    /*0x347*/ u8 filler347[0x1];
    /*0x348*/ u16 unk348;
    /*0x34A*/ s8 unk34A;
    /*0x34B*/ s8 unk34B[10];
    /*0x355*/ s8 unk355[4];
    /*0x359*/ s8 unk359[4];
    /*0x35D*/ u8 filler35D[0x1];
    /*0x35E*/ u16 unk35E[4];
    /*0x366*/ s8 unk366;
    /*0x367*/ s8 unk367;
    /*0x368*/ u16 unk368;
    /*0x36A*/ s8 unk36A[2];
    /*0x36C*/ s8 unk36C[2];
    /*0x36E*/ u16 unk36E[2];
    /*0x372*/ u16 unk372[2];
    /*0x376*/ u16 unk376;
    /*0x378*/ s8 unk378;
    /*0x379*/ s8 unk379;
    /*0x37A*/ s8 unk37A;
    /*0x37B*/ s8 unk37B;
    /*0x37C*/ s8 unk37C;
    /*0x37D*/ s8 unk37D;
    /*0x37E*/ u16 unk37E;
    /*0x380*/ u16 unk380;
    /*0x382*/ s8 unk382;
    /*0x383*/ s8 unk383;
    /*0x384*/ s8 legendaryHitsRequired;
    /*0x385*/ s8 bonusModeHitCount;
    /*0x386*/ s8 returnToMainBoardFlag;
    /*0x387*/ s8 boardEntityCollisionMode;
    /*0x388*/ s8 unk388;
    /*0x389*/ s8 unk389;
    /*0x38A*/ s16 unk38A;
    /*0x38C*/ s16 unk38C;
    /*0x38E*/ s16 unk38E;
    /*0x390*/ u16 unk390;
    /*0x392*/ u16 unk392;
    /*0x394*/ s16 unk394;
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
    /*0x3DC*/ s8 unk3DC;
    /*0x3DD*/ s8 unk3DD;
    /*0x3DE*/ s8 unk3DE;
    /*0x3DF*/ s8 unk3DF;
    /*0x3E0*/ s8 unk3E0;
    /*0x3E1*/ s8 unk3E1;
    /*0x3E2*/ s16 unk3E2;
    /*0x3E4*/ u16 unk3E4;
    /*0x3E6*/ s16 unk3E6;
    /*0x3E8*/ s16 unk3E8;
    /*0x3EA*/ s16 unk3EA;
    /*0x3EC*/ s16 unk3EC;
    /*0x3EE*/ s16 unk3EE;
    /*0x3F0*/ u16 unk3F0;
    /*0x3F2*/ u16 unk3F2;
    /*0x3F4*/ s8 unk3F4;
    /*0x3F5*/ s8 unk3F5;
    /*0x3F6*/ s8 unk3F6;
    /*0x3F7*/ s8 unk3F7;
    /*0x3F8*/ s8 unk3F8;
    /*0x3F9*/ u8 filler3F9[0x1];
    /*0x3FA*/ s16 unk3FA;
    /*0x3FC*/ s16 unk3FC;
    /*0x3FE*/ u8 filler3FE[0x2];
    /*0x400*/ struct Vector16 unk400;
    /*0x404*/ s8 unk404;
    /*0x405*/ s8 unk405;
    /*0x406*/ s8 unk406;
    /*0x407*/ u8 filler407[0x1];
    /*0x408*/ u16 unk408;
    /*0x40A*/ u16 unk40A;
    /*0x40C*/ u16 unk40C;
    /*0x40E*/ u16 unk40E;
    /*0x410*/ s16 unk410;
    /*0x412*/ s16 unk412;
    /*0x414*/ struct Vector16 unk414;
    /*0x418*/ struct Vector16 unk418;
    /*0x41C*/ s8 unk41C[4];
    /*0x420*/ s8 unk420[10];
    /*0x42A*/ s8 unk42A[7];
    /*0x431*/ u8 filler431[0x3];
    /*0x434*/ struct Vector16 unk434[3];
    /*0x440*/ s8 unk440;
    /*0x441*/ s8 unk441[2];
    /*0x443*/ s8 unk443[2];
    /*0x445*/ s8 unk445;
    /*0x446*/ s8 unk446;
    /*0x447*/ s8 unk447;
    /*0x448*/ s8 unk448;
    /*0x449*/ s8 unk449;
    /*0x44A*/ s8 unk44A;
    /*0x44B*/ u8 filler44B[0x1];
    /*0x44C*/ u16 unk44C;
    /*0x44E*/ s16 unk44E;
    /*0x450*/ u16 unk450;
    /*0x452*/ u16 unk452;
    /*0x454*/ u16 unk454;
    /*0x456*/ u16 unk456;
    /*0x458*/ u16 unk458[2];
    /*0x45C*/ struct Vector16 unk45C[2];
    /*0x464*/ struct Vector16 unk464[2];
    /*0x46C*/ struct Vector16 unk46C[4];
    /*0x47C*/ s8 unk47C;
    /*0x47D*/ s8 unk47D;
    /*0x47E*/ s8 unk47E;
    /*0x47F*/ s8 unk47F;
    /*0x480*/ u16 unk480;
    /*0x482*/ u16 unk482;
    /*0x484*/ u16 unk484;
    /*0x486*/ s16 unk486;
    /*0x488*/ struct Vector16 unk488;
    /*0x48C*/ s8 unk48C[4];
    /*0x490*/ s8 unk490[4];
    /*0x494*/ s8 unk494[4];
    /*0x498*/ s8 unk498[4];
    /*0x49C*/ s8 unk49C[4];
    /*0x4A0*/ s8 unk4A0[4];
    /*0x4A4*/ s8 unk4A4[4];
    /*0x4A8*/ s8 unk4A8[4];
    /*0x4AC*/ u16 unk4AC[4];
    /*0x4B4*/ struct Vector16 unk4B4[4];
    /*0x4C4*/ u16 unk4C4;
    /*0x4C6*/ u16 unk4C6;
    /*0x4C8*/ s8 unk4C8;
    /*0x4C9*/ u8 unk4C9;
    /*0x4CA*/ u16 unk4CA;
    /*0x4CC*/ s8 unk4CC[3];
    /*0x4CF*/ s8 unk4CF[3];
    /*0x4D2*/ s8 unk4D2[3];
    /*0x4D5*/ s8 unk4D5[3];
    /*0x4D8*/ u16 unk4D8[3];
    /*0x4DE*/ s16 unk4DE[3];
    /*0x4E4*/ s16 unk4E4[3];
    /*0x4EA*/ u8 filler4EA[0x2];
    /*0x4EC*/ struct Vector16 unk4EC[3];
    /*0x4F8*/ struct Vector16 unk4F8[3];
    /*0x504*/ u8 unk504;
    /*0x505*/ s8 unk505;
    /*0x506*/ s8 unk506;
    /*0x507*/ s8 unk507;
    /*0x508*/ s16 unk508;
    /*0x50A*/ s16 unk50A;
    /*0x50C*/ u16 unk50C;
    /*0x50E*/ u16 unk50E;
    /*0x510*/ u16 unk510;
    /*0x512*/ u16 unk512;
    /*0x514*/ u16 unk514;
    /*0x516*/ u16 unk516;
    /*0x518*/ s16 unk518;
    /*0x51A*/ s16 unk51A;
    /*0x51C*/ struct Vector16 unk51C;
    /*0x520*/ struct Vector16 unk520;
    /*0x524*/ struct Vector16 unk524;
    /*0x528*/ struct Vector16 unk528;
    /*0x52C*/ s8 unk52C[2];
    /*0x52E*/ s8 unk52E[2];
    /*0x530*/ s8 unk530[3];
    /*0x533*/ s8 unk533[3];
    /*0x536*/ s8 unk536[3];
    /*0x539*/ u8 filler539[0x1];
    /*0x53A*/ u16 unk53A;
    /*0x53C*/ u16 unk53C[3];
    /*0x542*/ u16 unk542;
    /*0x544*/ u32 unk544;
    /*0x548*/ s8 unk548[2];
    /*0x54A*/ s8 unk54A;
    /*0x54B*/ s8 unk54B[2];
    /*0x54D*/ s8 unk54D[2];
    /*0x54F*/ s8 unk54F[2];
    /*0x551*/ s8 unk551[2];
    /*0x553*/ s8 unk553[2];
    /*0x555*/ s8 unk555[2];
    /*0x557*/ s8 unk557[2];
    /*0x559*/ s8 unk559[2];
    /*0x55B*/ s8 unk55B[2];
    /*0x55D*/ s8 unk55D[2];
    /*0x55F*/ s8 unk55F[2];
    /*0x561*/ u8 filler561[0x1];
    /*0x562*/ u16 unk562[2];
    /*0x566*/ s16 unk566[2];
    /*0x56A*/ s16 unk56A[2];
    /*0x56E*/ u8 filler56E[0x2];
    /*0x570*/ struct Vector16 unk570[2];
    /*0x578*/ struct Vector16 unk578[2];
    /*0x580*/ struct Vector32 unk580[2];
    /*0x590*/ s8 unk590;
    /*0x591*/ s8 unk591;
    /*0x592*/ u16 unk592;
    /*0x594*/ u16 unk594;
    /*0x596*/ u16 unk596;
    /*0x598*/ u16 currentSpecies; // Current catch/hatch mode species? Is it evo mode as well?
    /*0x59A*/ u16 unk59A;
    /*0x59C*/ u16 lastCatchSpecies; // Previous catch mode species?
    /*0x59E*/ u16 lastEggSpecies; // Previous hatch/evo mode species?
    /*0x5A0*/ u16 unk5A0;
    /*0x5A2*/ u16 unk5A2;
    /*0x5A4*/ u8 unk5A4;
    /*0x5A5*/ u8 unk5A5;
    /*0x5A6*/ u16 unk5A6;
    /*0x5A8*/ s8 unk5A8;
    /*0x5A9*/ u8 unk5A9;
    /*0x5AA*/ u16 unk5AA;
    /*0x5AC*/ s32 unk5AC;
    /*0x5B0*/ u16 unk5B0;
    /*0x5B2*/ s8 unk5B2;
    /*0x5B3*/ u8 filler5B3[0x6];
    /*0x5B9*/ s8 unk5B9[6];
    /*0x5BF*/ u8 filler5BF[0x1];
    /*0x5C0*/ struct Vector16 unk5C0[6];
    /*0x5D8*/ struct Vector16 unk5D8[6];
    /*0x5F0*/ u16 caughtMonCount; // Number of mons caught in this game
    /*0x5F2*/ s8 unk5F2;
    /*0x5F3*/ s8 unk5F3;
    /*0x5F4*/ u16 unk5F4;
    /*0x5F6*/ s8 ballUpgradeType;
    /*0x5F7*/ u8 unk5F7;
    /*0x5F8*/ u16 ballUpgradeCounter;
    /*0x5FA*/ s8 unk5FA;
    /*0x5FB*/ s8 unk5FB;
    /*0x5FC*/ s16 unk5FC;
    /*0x5FE*/ s16 unk5FE;
    /*0x600*/ u16 unk600;
    /*0x602*/ s8 unk602;
    /*0x603*/ s8 unk603;
    /*0x604*/ u16 unk604;
    /*0x606*/ u16 unk606;
    /*0x608*/ u16 unk608;
    /*0x60A*/ s8 unk60A;
    /*0x60B*/ s8 unk60B;
    /*0x60C*/ s16 unk60C;
    /*0x60E*/ s16 unk60E;
    /*0x610*/ u16 unk610;
    /*0x612*/ u16 unk612;
    /*0x614*/ s16 unk614;
    /*0x616*/ u16 unk616;
    /*0x618*/ u16 unk618;
    /*0x61A*/ s16 unk61A;
    /*0x61C*/ s8 unk61C;
    /*0x61D*/ u8 filler61D;
    /*0x61E*/ u16 unk61E;
    /*0x620*/ struct Vector16 unk620;
    /*0x624*/ s8 bumperHitCountdown; // 2 when Hit, one frame of ignored collision, then ready to hit again
    /*0x625*/ s8 hatchTilesBumperAcknowledged;
    /*0x626*/ s8 unk626;
    /*0x627*/ u8 filler627[0x1];
    /*0x628*/ u16 unk628;
    /*0x62A*/ u8 unk62A;
    /*0x62B*/ u8 unk62B;
    /*0x62C*/ u8 unk62C;
    /*0x62D*/ u8 unk62D;
    /*0x62E*/ u8 unk62E;
    /*0x62F*/ u8 unk62F;
    /*0x630*/ u32 unk630;
    /*0x634*/ u32 unk634;
    /*0x638*/ s8 unk638;
    /*0x639*/ s8 unk639;
    /*0x63A*/ u16 unk63A;
    /*0x63C*/ s8 unk63C[3][20];
    /*0x678*/ s8 unk678[3][20];
    /*0x6B4*/ u32 unk6B4;
    /*0x6B8*/ u32 unk6B8;
    /*0x6BC*/ s8 unk6BC;
    /*0x6BD*/ s8 unk6BD;
    /*0x6BE*/ s8 unk6BE;
    /*0x6BF*/ u8 filler6BF[0x1];
    /*0x6C0*/ u16 unk6C0;
    /*0x6C2*/ u16 unk6C2;
    /*0x6C4*/ s8 unk6C4;
    /*0x6C5*/ s8 hatchTileRevealState;
    /*0x6C6*/ s8 hatchTilesBoardAcknowledged;
    /*0x6C7*/ s8 hatchSequentialTilesRevealed;
    /*0x6C8*/ s8 unk6C8;
    /*0x6C9*/ s8 unk6C9;
    /*0x6CA*/ u16 hatchSequentialTileRevealFrameAnimTimer;
    /*0x6CC*/ s8 hatchFrameId;
    /*0x6CD*/ u8 unk6CD[6];
    /*0x6D3*/ u8 unk6D3[6];
    /*0x6D9*/ s8 unk6D9[2];
    /*0x6DB*/ u8 unk6DB;
    /*0x6DC*/ u8 unk6DC;
    /*0x6DD*/ s8 unk6DD;
    /*0x6DE*/ u16 unk6DE;
    /*0x6E0*/ s16 unk6E0;
    /*0x6E2*/ u8 filler6E2[0x2];
    /*0x6E4*/ struct Vector16 unk6E4;
    /*0x6E8*/ s8 unk6E8;
    /*0x6E9*/ s8 unk6E9;
    /*0x6EA*/ s8 unk6EA;
    /*0x6EB*/ s8 unk6EB;
    /*0x6EC*/ s8 unk6EC[2];
    /*0x6EE*/ u16 unk6EE;
    /*0x6F0*/ u16 unk6F0;
    /*0x6F2*/ u16 unk6F2;
    /*0x6F4*/ u16 unk6F4;
    /*0x6F6*/ u16 unk6F6;
    /*0x6F8*/ u16 unk6F8[6];
    /*0x704*/ u16 unk704;
    /*0x706*/ u8 filler706[0x2];
    /*0x708*/ u32 unk708;
    /*0x70C*/ u16 unk70C;
    /*0x70E*/ s8 unk70E;
    /*0x70F*/ s8 unk70F;
    /*0x710*/ s8 holeIndicators[4]; // 'HOLE' light indicators in Ruby/Sapphire field
    /*0x714*/ s8 unk714;
    /*0x715*/ u8 unk715;
    /*0x716*/ u8 unk716;
    /*0x717*/ u8 unk717;
    /*0x718*/ s8 ballPowerUpLight[3];
    /*0x71B*/ s8 unk71B;
    /*0x71C*/ u8 unk71C;
    /*0x71D*/ s8 unk71D[3];
    /*0x720*/ u8 unk720;
    /*0x721*/ s8 unk721;
    /*0x722*/ s8 unk722;
    /*0x723*/ s8 unk723;
    /*0x724*/ u16 unk724;
    /*0x726*/ s8 unk726;
    /*0x727*/ u8 filler727[0x1];
    /*0x728*/ s8 unk728;
    /*0x729*/ s8 unk729;
    /*0x72A*/ s8 unk72A;
    /*0x72B*/ s8 unk72B;
    /*0x72C*/ u16 unk72C;
    /*0x72E*/ s8 unk72E;
    /*0x72F*/ s8 unk72F;
    /*0x730*/ s8 unk730;
    /*0x731*/ s8 unk731;
    /*0x732*/ s8 unk732;
    /*0x733*/ u8 filler733[0x1];
    /*0x734*/ s16 unk734;
    /*0x736*/ s8 unk736[3];
    /*0x739*/ s8 unk739[3];
    /*0x73C*/ u8 unk73C; // TODO: unknown type
    /*0x73D*/ s8 catchModeArrows;   // Affects which encounter table is used per area
    /*0x73E*/ u8 filler73E[0x2];
    /*0x740*/ u8 unk740;
    /*0x741*/ u8 filler741[0x3];
    /*0x744*/ u8 unk744[2];
    /*0x746*/ u8 unk746;
    /*0x747*/ u8 unk747[2];
    /*0x749*/ u8 unk749[2];
    /*0x74B*/ u8 filler74B[0x1];
    /*0x74C*/ volatile u8 unk74C[2][OBJ_PLTT_SIZE];
    /*0xB4C*/ volatile u8 unkB4C[2][BG_PLTT_SIZE];
    /*0xF4C*/ struct SongHeader *unkF4C;
    /*0xF50*/ u8 fillerF50[0x8];
    /*0xF58*/ struct BgOffsets bgOffsets0;
    /*0xF5C*/ struct BgOffsets bgOffsets1;
    /*0xF60*/ struct BgOffsets bgOffsets2;
    /*0xF64*/ struct BgOffsets bgOffsets3;
    /*0xF68*/ u16 unkF68[2][100];
    /*0x10F8*/u8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x10FD*/u8 field;
    /*0x10FE*/u8 unk10FE;
    /*0x10FF*/u8 unk10FF;
    /*0x1100*/u8 unk1100;
    /*0x1101*/u8 unk1101;
    /*0x1102*/u8 unk1102;
    /*0x1103*/u8 unk1103;
    /*0x1104*/s8 unk1104; //Pause Menu Pointer index
    /*0x1105*/u8 filler1105[0x1];
    /*0x1106*/volatile u16 unk1106;
    /*0x1108*/volatile u16 unk1108;
    /*0x110A*/volatile u16 unk110A;
    /*0x110C*/u16 unk110C;
    /*0x110E*/u16 unk110E;
    /*0x1110*/volatile u16 unk1110;
    /*0x1112*/volatile u16 unk1112;
    /*0x1114*/volatile u16 unk1114;
    /*0x1116*/u16 unk1116;
    /*0x1118*/u16 unk1118;
    /*0x111A*/u16 unk111A[OBJ_PLTT_SIZE / 0x20][0x10];
    /*0x131A*/u8 filler131A[0x2];
    /*0x131C*/u32 unk131C; //Time since paused
    /*0x1320*/s16 unk1320;
    /*0x1322*/s16 unk1322;
    /*0x1324*/s16 unk1324;
    /*0x1326*/s16 unk1326;
    /*0x1328*/u16 unk1328;
    /*0x132A*/u8 filler132A[0x2];
    /*0x132C*/struct BallState *ball;
    /*0x1330*/struct BallState *unk1330;
    /*0x1334*/struct BallState unk1334[2];
    /*0x13BC*/struct FlipperState flipper[2];
    /*0x13D4*/u16 unk13D4[10];
    /*0x13E8*/struct Vector16 unk13E8[10];
} /* size=0x1410 */;

struct Unk02031520_unk10
{
    /*0x0*/ u8 unk0;
    /*0x1*/ u8 unk1;
    /*0x2*/ u8 unk2;
};

struct Unk02031520_unk14
{
    /* These field offsets are intentionally kept as relative to
       struct Unk02031520 to make decompiling easier. This struct
       is basically always accessed relative to struct Unk02031520. */
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
    /*0x18*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ u16 unk1C;
    /*0x1E*/ u8 filler1E[0x2];
    /*0x20*/ s16 unk20;
    /*0x22*/ s16 unk22;
    /*0x24*/ s16 unk24;
    /*0x26*/ s16 unk26;
    /*0x28*/ s16 unk28;
    /*0x2A*/ s16 unk2A;
    /*0x2C*/ u8 *unk2C[3];
    /*0x38*/ const s16 *unk38[4];
    /*0x48*/ const u16 *unk48[4];
    /*0x58*/ const u8 *unk58[4];
};

struct Unk02031520
{
    /*0x00*/ u8 eReaderBonuses[NUM_EREADER_CARDS];
    /*0x05*/ bool8 rumbleEnabled;
    /*0x06*/ s16 unk6;
    /*0x08*/ s16 unk8;
    /*0x0A*/ u8 fillerA[0x2];
    /*0x0C*/ struct PinballGame *unkC;
    /*0x10*/ struct Unk02031520_unk10 *unk10;
    /*0x14*/ struct Unk02031520_unk14 unk14;
    /*0x68*/ const u16 *unk68;
};

struct Unk086ACE8C
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

extern struct PinballGame *gCurrentPinballGame;
extern const StateFunc gIdlePinballGameStateFuncs[];
extern u32 gUnknown_02031510;
extern struct Unk02031520 gUnknown_02031520;
extern u8 gUnknown_02031590[];
extern u16 gUnknown_08137B3C[][6][16];
extern u16 gUnknown_08137D40[]; 
extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gDusclopsBonusClear_Gfx[];
extern struct Unk02031520_unk10 gUnknown_081450F4;
extern struct Unk02031520_unk10 gUnknown_08148934;
extern struct Unk02031520_unk10 gUnknown_0814C174;
extern struct Unk02031520_unk10 gUnknown_0814F9B4;
extern struct PinballGame gUnknown_081531F4;
extern struct PinballGame gUnknown_08154618;
extern struct PinballGame gUnknown_08155A3C;
extern struct PinballGame gUnknown_08156E60;
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
extern struct Unk086ACE8C gUnknown_086ACE8C[13];
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