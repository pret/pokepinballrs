# GBP + Omega DE Cartridge Rumble Patch Site Mapping

This documents the source-level implementation of the 15 public patch sites for
cartridge-rumble support on non-Game Boy Player hardware.

Real GBP behavior is preserved when `gGameBoyPlayerEnabled == TRUE`; all Omega DE
register accesses happen only on the non-GBP path.

## Build

The Omega DE rumble code is gated by the Makefile variable `OMEGA_DE_RUMBLE`.

- Default (vanilla): `make rom` produces `pokepinballrs.gba`.
- Feature build: `make OMEGA_DE_RUMBLE=1 rom` produces
  `pokepinballrs_omega_de_rumble.gba` in the repository root and keeps its
  intermediate objects under `build/pokepinballrs_omega_de_rumble/`.

When disabled (the default), the source compiles back to the original upstream
behavior, `src/omegade_rumble.s` is excluded from the object list, and the
generated linker script matches the original object order. When enabled, all
15 patch sites below are active and the Omega DE helper text is linked
immediately after `src/gbplayer.o(.text)`.

## Reference and acknowledgement

The cartridge-rumble behavior and patch-site mapping in this implementation were
developed with reference to the Pokémon Pinball: Ruby & Sapphire rumble patch
published as [Romhacking.net Hack #6256](https://www.romhacking.net/hacks/6256/).

| Site | Semantic target | Source location | Implementation |
|------|-----------------|-----------------|----------------|
| 0 | `EnableGbPlayerRumble` always runs setup | `src/gbplayer.c` `EnableGbPlayerRumble` | Removed the `gGameBoyPlayerEnabled == 1` guard around interrupt/SIO setup and `InitSio32Hardware()` |
| 1 | `DisableGbPlayerRumble` stops cartridge rumble | `src/gbplayer.c` `DisableGbPlayerRumble` | `SetRumbleCommand(0)` then explicit `StopCartridgeRumble()` when `!GBP` |
| 2 | `DisableGbPlayerRumble` prologue/return support | same as site 1 | Handled by the same stop hook at the top of the function |
| 3 | `ProcessRumbleFrame` runs without the GBP gate | `src/gbplayer.c` `ProcessRumbleFrame` | Removed the outer `if (gGameBoyPlayerEnabled == 1)` wrapper |
| 4 | Replace `gRumbleCommand = var0` with output helper | `src/gbplayer.c` `ProcessRumbleFrame` | `SetRumbleCommand(var0)` stores the command and emits the Omega DE pulse when `!GBP && command == 2` |
| 5 | Inactive pattern stores command 0 and stops cartridge rumble | `src/gbplayer.c` `ProcessRumbleFrame` | The inactive-pattern branch stores command 0 and calls `StopCartridgeRumble()` when `!GBP` |
| 6 | `InitSio32Hardware` initial state | `src/gbplayer.c` `InitSio32Hardware` | `gSio32CommState = 0` for GBP, `4` for non-GBP |
| 7 | Timeout/reconnect state assignment | `src/gbplayer.c` `Sio32TimeoutIntr` | `gSio32CommState = 5` for GBP, `4` for non-GBP |
| 8 | Initialize Omega DE/cart control for non-GBP | `src/titlescreen.c` `InitTitlescreenStates` | `InitCartridgeRumble()` called immediately after setting `pressStartAndFlippersVisible` and `deleteSaveWindowVisible`, matching the IPS hook order |
| 9 | Do not gray rumble UI for non-GBP | `src/options.c` `Options_LoadGraphics` | Removed the `SetStringPalette` graying block entirely |
| 10 | Load saved rumble state regardless of GBP | `src/options.c` `Options_InitStates` | `gOptionsData.rumbleEnabled = gMain_saveData.rumbleEnabled` unconditionally |
| 11 | `DPAD_RIGHT` rumble cursor works for non-GBP | `src/options.c` `Options_HandleInput` | Removed `gGameBoyPlayerEnabled == TRUE` check |
| 12 | `DPAD_LEFT` rumble cursor works for non-GBP | `src/options.c` `Options_HandleInput` | Removed `gGameBoyPlayerEnabled == TRUE` check |
| 13 | `RUMBLE_OFF` selection works for non-GBP | `src/options.c` `Options_HandleInput` | Removed the GBP-only guard |
| 14 | `RUMBLE_ON` selection works for non-GBP | `src/options.c` `Options_HandleInput` | Removed the GBP-only guard |

## Helper functions

- `EmitOmegaDEPulse()` (`src/omegade_rumble.s`) - Thumb assembly routine that
  performs the exact 16-bit and 8-bit writes documented for the Omega DE pulse,
  followed by exactly four `nop` instructions. Implemented in assembly so the
  instruction sequence and timing match the known-working IPS payload.
- `StopCartridgeRumble()` (`src/gbplayer.c`) - writes volatile byte `0` to
  `0x080000C4`.
- `InitCartridgeRumble()` (`src/omegade_rumble.s`) - Thumb assembly routine that
  writes `1` to `0x080000C8` and `8` to `0x080000C6`. It is a no-op when
  `gGameBoyPlayerEnabled == TRUE` so the real GBP path is unaffected.
- `SetRumbleCommand(command)` (`src/gbplayer.c`) - stores `command` into
  `gRumbleCommand` and emits the Omega DE pulse only when `!GBP && command == 2`.
  It never stops the cartridge rumble; stop is handled by the explicit stop hooks.

## Important invariants

- `gGameBoyPlayerEnabled` is never forced to `TRUE`; it remains the result of
  `CheckGameBoyPlayer()`.
- All `0x08xxxxxx` and `0x09xxxxxx` accesses in the helpers are `volatile` and
  use the exact width (`vu8` / `vu16`) specified by the reference patch.
- `StopCartridgeRumble()` (the only write to `0x080000C4`) is reached from
  `DisableGbPlayerRumble` and the inactive-pattern branch of
  `ProcessRumbleFrame`. The odd-frame speed-mode command-zero transition does
  not produce a physical stop write.
