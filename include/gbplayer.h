#ifndef GUARD_GBPLAYER_H
#define GUARD_GBPLAYER_H

#include "global.h"

void InitGameBoyPlayer(void);
#ifdef FEATURE_OMEGA_DE_RUMBLE
void InitCartridgeRumble(void);
#endif
u32 Sio32EncodePacket(u32 arg1, u32 arg2);
u32 Sio32VerifyChecksum(void);
u32 EncodeRumbleCommand(u32 arg1);

#endif // GUARD_GBPLAYER_H
