MON_PORTRAITS_DIR := graphics/mon_portraits
MON_HATCH_SPRITES_DIR := graphics/mon_hatch_sprites

graphics/field_select/sprites.4bpp: graphics/field_select/sprites.png
	$(GFX) $< $@ -num_tiles 513

graphics/options/sprites.4bpp: graphics/options/sprites.png
	$(GFX) $< $@ -num_tiles 257

$(MON_PORTRAITS_DIR)/%.4bpp: $(MON_PORTRAITS_DIR)/%.png
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(MON_HATCH_SPRITES_DIR)/%.4bpp: $(MON_HATCH_SPRITES_DIR)/%.png
	$(GFX) $< $@ -pinball-hatch-sprite
