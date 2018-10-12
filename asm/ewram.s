	.include "asm/macros.inc"

    .section ewram

.space 0x2958

ds gUnknown_02002958 @ 0x2002958

.space 0x708

ds gIntrTable @ 0x2003060

.space 0x8060

ds gUnknown_0200B0C0 @ 0x200B0C0

.space 0x26A70

ds gSoundInfo @ 0x2031B30

.space 0x1020

ds gPokemonCryMusicPlayers @ 0x2032B50

.space 0x80

ds gMPlayJumpTable @ 0x2032BD0

.space 0x90

ds gCgbChans @ 0x2032C60

.space 0x100

ds gPokemonCryTracks @ 0x2032D60

.space 0x140

ds gPokemonCrySong @ 0x2032EA0

.space 0x100

ds gMPlayMemAccArea @ 0x2032FA0
