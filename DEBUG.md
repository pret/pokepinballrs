# Debugging pokepinballrs

## Requirements

- [mGBA](https://mgba.io/)
- [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug) VS Code extension
- `arm-none-eabi-gdb` — (GDB 17.1)

## Build with debug info

The Makefile compiles with `-g` and the linker script preserves DWARF sections. A normal build produces a debug-enabled ELF:

```sh
make
```

The ELF at `pokepinballrs.elf` will contain `.debug_info`, `.debug_line`, etc. The `.gba` ROM is unaffected (debug sections are stripped by `objcopy`).

## Start the GDB server in mGBA

1. Open `pokepinballrs.gba` in mGBA
2. **Tools → Start GDB Server...**
3. Set port to `2345`, click **OK**

mGBA will pause emulation and wait for a GDB connection.

## Attach in VS Code

1. Open the `pret` workspace in VS Code
2. Go to **Run and Debug**
3. Select **GBA Debug** from the dropdown
4. Press **F5**

The launch sequence will:
- Set architecture to `armv4t`
- Load symbols from `pokepinballrs.elf`
- Push the ROM binary to mGBA via `load`
- Set a temporary breakpoint at `AgbMain`
- Run until `AgbMain` is hit

## VS Code launch.json

Create `.vscode/launch.json` in the `pret` workspace root with:

```json
{
    "configurations": [
        {
            "name": "GBA Debug",
            "type": "cortex-debug",
            "request": "launch",
            "servertype": "external",
            "gdbTarget": "localhost:2345",
            "executable": "${workspaceFolder}/pokepinballrs/pokepinballrs.elf",
            "cwd": "${workspaceFolder}/pokepinballrs",
            "overrideLaunchCommands": [
                "set architecture armv4t",
                "file ${workspaceFolder}/pokepinballrs/pokepinballrs.elf",
                "load",
                "thbreak AgbMain",
                "continue"
            ]
        }
    ]
}
```

`servertype: external` means VS Code connects to an already-running GDB server (mGBA) rather than launching one itself. The `overrideLaunchCommands` replaces cortex-debug's default launch sequence — do not add `target remote` here, cortex-debug handles the connection via `gdbTarget`.

## GDB tips for GBA

```gdb
# Print a value in hex
p/x gMain.spriteGroups

# Inspect a struct
p *gMain

# Disassemble current function (ARM/Thumb aware)
disassemble

# Set a breakpoint by source line
break high_scores.c:42

# Hardware breakpoint (required for ROM — software breakpoints write to flash)
hbreak AgbMain

# Watch a memory location for writes
watch gUnknown_0202BEBC

# Print 16 words of EWRAM starting at address
x/16xw 0x02000000
```

## Troubleshooting

**"A program is being debugged already"** — mGBA only accepts one GDB connection. Close any existing GDB session before launching again.

**`0x000001f4 in ?? ()`** — Normal. The CPU is halted inside the GBA BIOS when you first connect. `load` + `continue` will move it to ROM.

**Breakpoint on ROM address not working** — Use `hbreak` (hardware breakpoint) instead of `break`. Software breakpoints require writing to the target address, which fails for ROM.

**Symbols not resolving** — Rebuild the ELF after any source changes. The `.elf` and `.gba` are separate: mGBA runs the `.gba` but GDB reads symbols from the `.elf`.
