#ifndef GUARD_CONSTANTS_ANGLE_MATH_H
#define GUARD_CONSTANTS_ANGLE_MATH_H

#define ANGLE_45 0x2000
#define ANGLE_90 0x4000
#define ANGLE_180 0x8000
#define ANGLE_360 0x10000

// Converts from degrees to Binary Angular Measurement
// Expects 2 decimal places of precision
#define DEG_TO_BAM(deg) ((uint16_t)(((deg) * 65536.0/360.0) +0.5))

#endif //GUARD_CONSTANTS_ANGLE_MATH_H