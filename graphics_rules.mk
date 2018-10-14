MON_PORTRAITS_DIR := graphics/mon_portraits

$(MON_PORTRAITS_DIR)/%.4bpp: $(MON_PORTRAITS_DIR)/%.png
	$(GFX) $< $@ -mwidth 2 -mheight 2
