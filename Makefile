TOOLCHAIN := $(DEVKITARM)
ifneq (,$(TOOLCHAIN))
ifneq ($(wildcard $(TOOLCHAIN)/bin),)
export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif
endif

COMPARE ?= 0

ifeq (compare,$(MAKECMDGOALS))
  COMPARE := 1
endif

PREFIX := arm-none-eabi-
OBJCOPY := $(PREFIX)objcopy
AS := $(PREFIX)as

export CPP := $(PREFIX)cpp
export LD := $(PREFIX)ld

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

TITLE       := POKEPIN R/S
GAME_CODE   := BPPE
MAKER_CODE  := 01
REVISION    := 0

HOSTCC = $(CC)
HOSTCXX = $(CXX)
HOSTCFLAGS = $(CFLAGS)
HOSTCXXFLAGS = $(CXXFLAGS)
HOST_VARS := CC=$(HOSTCC) CXX=$(HOSTCXX) CFLAGS='$(HOSTCFLAGS)' CXXFLAGS='$(HOSTCXXFLAGS)'

SHELL := /bin/bash -o pipefail

ROM := pokepinballrs.gba
OBJ_DIR := build/pokepinballrs

ELF = $(ROM:.gba=.elf)
MAP = $(ROM:.gba=.map)

C_SUBDIR = src
ASM_SUBDIR = asm
DATA_ASM_SUBDIR = data

C_BUILDDIR = $(OBJ_DIR)/$(C_SUBDIR)
ASM_BUILDDIR = $(OBJ_DIR)/$(ASM_SUBDIR)
DATA_ASM_BUILDDIR = $(OBJ_DIR)/$(DATA_ASM_SUBDIR)

ASFLAGS := -mcpu=arm7tdmi

CC1             := tools/agbcc/bin/agbcc$(EXE)
override CFLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm -fprologue-bugfix

CPPFLAGS := -I tools/agbcc/include -I tools/agbcc -iquote include -nostdinc -undef

LDFLAGS = -Map ../../$(MAP)

LIB := -L ../../tools/agbcc/lib -lgcc -lc

GFX       := tools/gbagfx/gbagfx$(EXE)
WAV2AGB   := tools/wav2agb/wav2agb$(EXE)
SCANINC   := tools/scaninc/scaninc$(EXE)
PREPROC   := tools/preproc/preproc$(EXE)
RAMSCRGEN := tools/ramscrgen/ramscrgen$(EXE)
FIX       := tools/gbafix/gbafix$(EXE)

SHA1 := $(shell { command -v sha1sum || command -v shasum; } 2>/dev/null) -c

TOOLS_DIR = tools
TOOLDIRS = $(filter-out $(TOOLS_DIR)/agbcc $(TOOLS_DIR)/m2ctx.py $(TOOLS_DIR)/scripts,$(wildcard $(TOOLS_DIR)/*))

infoshell = $(foreach line, $(shell $1 | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))

# Build tools when building the rom
# Disable dependency scanning for clean/tidy/tools
ifeq (,$(filter-out all compare,$(MAKECMDGOALS)))
$(call infoshell, $(HOST_VARS) $(MAKE) tools)
else
NODEP := 1
endif

# Clear the default suffixes
.SUFFIXES:
# Don't delete intermediate files
.SECONDARY:
# Delete files that weren't built properly
.DELETE_ON_ERROR:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PHONY: rom clean compare tidy tools clean-tools $(TOOLDIRS)

$(shell mkdir -p $(C_BUILDDIR) $(ASM_BUILDDIR) $(DATA_ASM_BUILDDIR))

C_SRCS := $(wildcard $(C_SUBDIR)/*.c)
C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))

C_ASM_SRCS += $(wildcard $(C_SUBDIR)/*.s)
C_ASM_OBJS := $(patsubst $(C_SUBDIR)/%.s,$(C_BUILDDIR)/%.o,$(C_ASM_SRCS))

ASM_SRCS := $(wildcard $(ASM_SUBDIR)/*.s)
ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(ASM_BUILDDIR)/%.o,$(ASM_SRCS))

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_SUBDIR)/*.s)
DATA_ASM_OBJS := $(patsubst $(DATA_ASM_SUBDIR)/%.s,$(DATA_ASM_BUILDDIR)/%.o,$(DATA_ASM_SRCS))

OBJS := $(C_OBJS) $(C_ASM_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)
OBJS_REL := $(patsubst $(OBJ_DIR)/%,%,$(OBJS))

MAKEFLAGS += --no-print-directory

rom: $(ROM)
ifeq ($(COMPARE),1)
	@$(SHA1) pokepinballrs.sha1
endif

# For contributors to make sure a change didn't affect the contents of the ROM.
compare: rom

clean: tidy clean-tools
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +
	rm -f graphics_rules_generated.mk
	find sound -iname '*.bin' -exec rm {} +

tidy:
	rm -f $(ROM) $(ELF) $(MAP)
	rm -r build/*

tools: $(TOOLDIRS)

$(TOOLDIRS):
	@$(HOST_VARS) $(MAKE) -C $@

clean-tools:
	$(foreach tool,$(TOOLDIRS),$(MAKE) clean -C $(tool);)

include graphics_rules.mk
include audio_rules.mk

%.s: ;
%.png: ;
%.pal: ;
%.aif: ;

%.1bpp: %.png  ; $(GFX) $< $@
%.4bpp: %.png  ; $(GFX) $< $@
%.8bpp: %.png  ; $(GFX) $< $@
%.gbapal: %.pal ; $(GFX) $< $@
%.gbapal: %.png ; $(GFX) $< $@
%.lz: % ; $(GFX) $< $@
%.rl: % ; $(GFX) $< $@

$(C_BUILDDIR)/m4a.o: CFLAGS := -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm
$(C_BUILDDIR)/m4a.o: CC1 := tools/agbcc/bin/old_agbcc

$(C_BUILDDIR)/agb_sram.o: CFLAGS := -mthumb-interwork -Wimplicit -Wparentheses -Werror -O1
$(C_BUILDDIR)/agb_sram.o: CC1 := tools/agbcc/bin/old_agbcc

ifeq ($(NODEP),)
$(C_BUILDDIR)/%.o: c_dep = $(shell $(SCANINC) -I include $(C_SUBDIR)/$*.c)
$(C_BUILDDIR)/%.o: c_asm_dep = $(shell $(SCANINC) -I include $(C_SUBDIR)/$*.c)
else
$(C_BUILDDIR)/%.o: c_dep :=
$(C_BUILDDIR)/%.o: c_asm_dep :=
endif

$(C_BUILDDIR)/%.o: $(C_SUBDIR)/%.s $$(c_asm_dep)
	$(AS) $(ASFLAGS) -o $@ $< #$(C_BUILDDIR)/$*.s

$(C_BUILDDIR)/%.o : $(C_SUBDIR)/%.c $$(c_dep)
	$(CPP) $(CPPFLAGS) $< -o $(C_BUILDDIR)/$*.i
	$(PREPROC) $(C_BUILDDIR)/$*.i charmap.txt | $(CC1) $(CFLAGS) -o $(C_BUILDDIR)/$*.s
	echo -e ".text\n\t.align\t2, 0\n" >> $(C_BUILDDIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(C_BUILDDIR)/$*.s

ifeq ($(NODEP),)
$(ASM_BUILDDIR)/%.o: asm_dep = $(shell $(SCANINC) $(ASM_SUBDIR)/$*.s)
else
$(ASM_BUILDDIR)/%.o: asm_dep :=
endif

$(ASM_BUILDDIR)/%.o: $(ASM_SUBDIR)/%.s $$(asm_dep)
	$(CPP) $(CPPFLAGS) $< -I include | $(AS) $(ASFLAGS) -o $@

build/pokepinballrs/asm/start.o: asm/start.s
	$(AS) $(ASFLAGS) -o $@ $<

ifeq ($(NODEP),)
$(DATA_ASM_BUILDDIR)/%.o: data_dep = $(shell $(SCANINC) $(DATA_ASM_SUBDIR)/$*.s)
else
$(DATA_ASM_BUILDDIR)/%.o: data_dep :=
endif

$(DATA_ASM_BUILDDIR)/%.o: $(DATA_ASM_SUBDIR)/%.s $$(data_dep)
	$(PREPROC) $< charmap.txt | $(CPP) -I include | $(AS) $(ASFLAGS) -o $@

$(OBJ_DIR)/sym_bss.ld: sym_bss.txt
	$(RAMSCRGEN) .bss $< ENGLISH > $@

$(OBJ_DIR)/sym_common.ld: sym_common.txt $(C_OBJS) $(wildcard common_syms/*.txt)
	$(RAMSCRGEN) COMMON $< ENGLISH -c $(C_BUILDDIR),common_syms > $@

$(OBJ_DIR)/sym_ewram.ld: sym_ewram.txt
	$(RAMSCRGEN) ewram_data $< ENGLISH > $@

$(OBJ_DIR)/ld_script.ld: ld_script.txt $(OBJ_DIR)/sym_bss.ld $(OBJ_DIR)/sym_common.ld $(OBJ_DIR)/sym_ewram.ld
	cd $(OBJ_DIR) && sed -f ../../ld_script.sed ../../$< | sed "s#tools/#../../tools/#g" > ld_script.ld

$(ELF): $(OBJ_DIR)/ld_script.ld $(OBJS)
	cd $(OBJ_DIR) && $(LD) $(LDFLAGS) -T ld_script.ld -o ../../$@ $(OBJS_REL) $(LIB)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@
	$(FIX) $@ -p -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent
