GFX_JSONS := $(shell find graphics -type f -name '*.json')
GFX_RULES_SCRIPT := tools/scripts/generate_graphics_rules.sh
GFX_RULES_GEN := graphics_rules_generated.mk

$(GFX_RULES_GEN): $(GFX_JSONS) $(GFX_RULES_SCRIPT)
	bash $(GFX_RULES_SCRIPT) $(GFX_JSONS) > $@

-include $(GFX_RULES_GEN)

graphics/field_select/sprites.4bpp: graphics/field_select/sprites.png
	$(GFX) $< $@ -num_tiles 513

graphics/options/sprites.4bpp: graphics/options/sprites.png
	$(GFX) $< $@ -num_tiles 257

graphics/pokedex/text_glyphs.4bpp: graphics/pokedex/text_glyphs.png
	$(GFX) $< $@ -num_tiles 513

# Travel-cutscene painter mons. Each frame is 4 OAM pieces that tile into a 6x6
# block, so -oamshape lays the 17 frames out as the sprite instead of the 1D
# tile order the hardware wants.
PAINTER_SHAPE := graphics/stage/main/travel_painter_shape.json
graphics/stage/ruby/travel_volbeat.4bpp: graphics/stage/ruby/travel_volbeat.png $(PAINTER_SHAPE)
	$(GFX) $< $@ -oamshape $(PAINTER_SHAPE) -mwidth 6 -mheight 6

graphics/stage/sapphire/travel_illumise.4bpp: graphics/stage/sapphire/travel_illumise.png $(PAINTER_SHAPE)
	$(GFX) $< $@ -oamshape $(PAINTER_SHAPE) -mwidth 6 -mheight 6

# Sapphire Plusle/Minun bumpers. Each frame is a 32x32 over a 32x16, which tiles
# into a 4x6 block, so -oamshape lays the frames out as the sprite.
BUMPER_SHAPE := graphics/stage/sapphire/bumper_shape.json
graphics/stage/sapphire/bumper_minun.4bpp: graphics/stage/sapphire/bumper_minun.png $(BUMPER_SHAPE)
	$(GFX) $< $@ -oamshape $(BUMPER_SHAPE) -mwidth 4 -mheight 6

graphics/stage/sapphire/bumper_plusle.4bpp: graphics/stage/sapphire/bumper_plusle.png $(BUMPER_SHAPE)
	$(GFX) $< $@ -oamshape $(BUMPER_SHAPE) -mwidth 4 -mheight 6

