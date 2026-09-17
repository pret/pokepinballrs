#ifndef GUARD_GBA_C_DEFINES
#define GUARD_GBA_C_DEFINES

#include <stddef.h>

#define IWRAM_DATA __attribute__((section("iwram_data")))
#define EWRAM_DATA __attribute__((section("ewram_data")))

#define ALIGNED(n) __attribute__((aligned(n)))

#define SOUND_INFO_PTR (*(struct SoundInfo **)0x3007FF0)
#define INTR_CHECK     (*(u16 *)0x3007FF8)
#define INTR_VECTOR    (*(void **)0x3007FFC)

#endif