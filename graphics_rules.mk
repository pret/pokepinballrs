MON_PORTRAITS_DIR := graphics/mon_portraits
MON_HATCH_SPRITES_DIR := graphics/mon_hatch_sprites

# 1. Preprocess JSON files into a lookup table
GFX_JSONS := $(shell find graphics -type f -name '*.json')

graphics/graphic_cnvt_attrs.txt: $(GFX_JSONS)
	@echo "# path mwidth mheight oam align segments" > $@
	@for json in $^; do \
		if jq -e '.kind == "gfx-config"' "$$json" > /dev/null; then \
			dir=$$(dirname "$$json"); \
			jq -r --arg dir "$$dir" '.defaults as $$d | .files[]? | (.f // .palette // "") as $$f | "file=graphics/" + ($$dir | sub("^graphics/";"")) + "/" + $$f + " mwidth=" + ((.mwidth // $$d.mwidth // "" )|tostring) + " mheight=" + ((.mheight // $$d.mheight // "" )|tostring) + " oam=" + ((.oam // $$d.oam // "" )|tostring) + " align=" + ((.align // $$d.align // "" )|tostring) + (if .segments then " segments=" + (.segments|tojson) else "" end)' "$$json" >> "$@"; \
		fi; \
	done


# 2. Pattern rule for .4bpp files using params.txt
# Convert *.png -> *.4bpp using optional parameters from graphics/params.txt
# - If no params line is found, call $(GFX) with no extra flags.
# - If params exist:
#     * If segments=[...] present: build each $*_SEG.png and concat
#     * Else: build whole image
# - Only pass -mwidth/-mheight/-oam when non-blank and non-zero
# - Apply final alignment padding if align=N is present
%.4bpp: %.png graphics/graphic_cnvt_attrs.txt
	@set -e; \
	params="$$(grep -m1 -E '^(file)=$*([[:space:]]|$$)' graphics/graphic_cnvt_attrs.txt || true)"; \
	if [ -z "$$params" ]; then \
		$(GFX) $*.png $@; \
		exit 0; \
	fi; \
	segs=$$(printf '%s' "$$params" | sed -n 's/.*segments=\(\[.*\]\).*/\1/p'); \
	align_global=$$(printf '%s' "$$params" | sed -n 's/.*[[:space:]]align=\([0-9]\+\).*/\1/p'); \
	\
	if [ -n "$$segs" ]; then \
		seglist=$$(printf '%s' "$$segs" | jq -r '.[].seg'); \
		segfiles=""; \
		for seg in $$seglist; do \
			mw=$$(printf '%s' "$$segs" | jq -r ".[] | select(.seg==\"$$seg\") | (.mwidth // \"\")"); \
			mh=$$(printf '%s' "$$segs" | jq -r ".[] | select(.seg==\"$$seg\") | (.mheight // \"\")"); \
			oam=$$(printf '%s' "$$segs" | jq -r ".[] | select(.seg==\"$$seg\") | (.oam // \"\")"); \
			mw_arg=""; mh_arg=""; oam_arg=""; \
			if [ -n "$$mw" ] && [ "$$mw" != 0 ]; then mw_arg="-mwidth $$mw"; fi; \
			if [ -n "$$mh" ] && [ "$$mh" != 0 ]; then mh_arg="-mheight $$mh"; fi; \
			if [ "$$oam" = true ]; then oam_arg="-oam"; fi; \
			echo -e "Processing segment $$seg: $(GFX) $*_$$seg.png $*_$$seg.4bpp $$mw_arg $$mh_arg $$oam_arg; \n"; \
			$(GFX) $*_$$seg.png $*_$$seg.4bpp $$mw_arg $$mh_arg $$oam_arg; \
			segfiles="$$segfiles $*_$$seg.4bpp"; \
		done; \
		echo -e "catting segments: $$segfiles -> $@ \n"; \
		cat $$segfiles > $@; \
	else \
		mw=$$(printf '%s' "$$params" | sed -n 's/.*[[:space:]]mwidth=\([0-9]\+\).*/\1/p'); \
		mh=$$(printf '%s' "$$params" | sed -n 's/.*[[:space:]]mheight=\([0-9]\+\).*/\1/p'); \
		oam=$$(printf '%s' "$$params" | sed -n 's/.*[[:space:]]oam=\(true\|false\).*/\1/p'); \
		mw_arg=""; mh_arg=""; oam_arg=""; \
		if [ -n "$$mw" ] && [ "$$mw" != 0 ]; then mw_arg="-mwidth $$mw"; fi; \
		if [ -n "$$mh" ] && [ "$$mh" != 0 ]; then mh_arg="-mheight $$mh"; fi; \
		if [ "$$oam" = true ]; then oam_arg="-oam"; fi; \
		echo -e "Processing whole image: $(GFX) $*.png $@ $$mw_arg $$mh_arg $$oam_arg; \n"; \
		$(GFX) $*.png $@ $$mw_arg $$mh_arg $$oam_arg; \
	fi; \
	if [ -n "$$align_global" ]; then \
		dd if=/dev/zero bs=32 count=$$align_global >> $@; \
	fi;

# 3. Pattern rule for .gbapal files (if needed)
#graphics/%/%.gbapal: graphics/%/%.pal graphics/params.txt
#	@params="$$(grep -E "^file=$*" graphics/params.txt | head -n1)"; \
#	mw=$$(echo $$params | sed -n 's/.*mwidth=\([0-9]*\).*/\1/p'); \
#	mh=$$(echo $$params | sed -n 's/.*mheight=\([0-9]*\).*/\1/p'); \
#	oam=$$(echo $$params | grep -q 'oam=true' && echo "-oam"); \
#	$(GFX) $< $@ -mwidth $$mw -mheight $$mh $$oam


graphics/field_select/sprites.4bpp: graphics/field_select/sprites.png
	$(GFX) $< $@ -num_tiles 513

graphics/options/sprites.4bpp: graphics/options/sprites.png
	$(GFX) $< $@ -num_tiles 257

$(MON_PORTRAITS_DIR)/%.4bpp: $(MON_PORTRAITS_DIR)/%.png
	$(GFX) $< $@ -mwidth 2 -mheight 2

#$(MON_HATCH_SPRITES_DIR)/%.4bpp: $(MON_HATCH_SPRITES_DIR)/%.png
#	$(GFX) $< $@ -pinball-hatch-sprite

graphics/pokedex/text_glyphs.4bpp: graphics/pokedex/text_glyphs.png
	$(GFX) $< $@ -num_tiles 513
