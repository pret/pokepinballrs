#ifndef GUARD_GBPLAYER_H
#define GUARD_GBPLAYER_H

#include "global.h"

void InitGameBoyPlayer(void);
u32 EncodeGbPlayerPacket(u32 arg1, u32 arg2);
u32 VerifyGbPlayerChecksum(void);
u32 ShiftRumbleByCommandState(u32 arg1);

#endif // GUARD_GBPLAYER_H
