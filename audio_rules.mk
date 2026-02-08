# This file contains rules for making assemblies for most music in the game.

CRY_SUBDIR := sound/direct_sound_samples/cries

CRY_BIN_DIR := $(CRY_SUBDIR)
SOUND_BIN_DIR := sound

SPECIAL_OUTDIRS := $(CRY_BIN_DIR) 
SPECIAL_OUTDIRS += $(SOUND_BIN_DIR) $(SOUND_BIN_DIR)/direct_sound_samples/cries
$(shell mkdir -p $(SPECIAL_OUTDIRS) )

# Compressed cries
 $(CRY_BIN_DIR)/%.bin: $(CRY_SUBDIR)/%.wav
# NOTE: If using ipatix's High Quality Audio Mixer, remove "--no-pad" below.
	$(WAV2AGB) -b -c -l 1 --no-pad $< $@

# Uncompressed sounds
$(SOUND_BIN_DIR)/%.bin: sound/%.wav 
	$(WAV2AGB) -b $< $@
