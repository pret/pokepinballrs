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
