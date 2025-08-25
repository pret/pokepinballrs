# 1. Preprocess JSON files into a lookup table
GFX_JSONS := $(shell find graphics -type f -name '*.json')

graphics/graphic_cnvt_attrs.txt: $(GFX_JSONS)
	@echo "# path mwidth mheight oam align segments" > $@
	@for json in $^; do \
		if jq -e '.kind == "gfx-config"' "$$json" > /dev/null; then \
			dir=$$(dirname "$$json"); \
			jq -r --arg dir "$$dir" '.defaults as $$d | .files[]? | (.gfx_filename // .palette // "") as $$gfx_filename | "file=graphics/" + ($$dir | sub("^graphics/";"")) + "/" + $$gfx_filename + " mwidth=" + ((.mwidth // $$d.mwidth // "" )|tostring) + " mheight=" + ((.mheight // $$d.mheight // "" )|tostring) + " oam=" + ((.oam // $$d.oam // "" )|tostring) + " align=" + ((.align // $$d.align // "" )|tostring) + (if .segments then " segments=" + (.segments|tojson) else "" end)' "$$json" >> "$@"; \
		fi; \
	done


# 2. Pattern rule for .4bpp files using graphic_cnvt_attrs.txt
# Convert *.png -> *.4bpp using optional parameters from graphics/graphic_cnvt_attrs.txt
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
		seglist=$$(printf '%s' "$$segs" | jq -r '.[].segfile'); \
		segfiles=""; \
		for segfile in $$seglist; do \
			mw=$$(printf '%s' "$$segs" | jq -r ".[] | select(.segfile==\"$$segfile\") | (.mwidth // \"\")"); \
			mh=$$(printf '%s' "$$segs" | jq -r ".[] | select(.segfile==\"$$segfile\") | (.mheight // \"\")"); \
			oam=$$(printf '%s' "$$segs" | jq -r ".[] | select(.segfile==\"$$segfile\") | (.oam // \"\")"); \
			mw_arg=""; mh_arg=""; oam_arg=""; \
			if [ -n "$$mw" ] && [ "$$mw" != 0 ]; then mw_arg="-mwidth $$mw"; fi; \
			if [ -n "$$mh" ] && [ "$$mh" != 0 ]; then mh_arg="-mheight $$mh"; fi; \
			if [ "$$oam" = true ]; then oam_arg="-oam"; fi; \
#			echo -e "Processing segment $$segfile: $(GFX) $(dir $*)$$segfile.png $*_$$segfile.4bpp $$mw_arg $$mh_arg $$oam_arg; \n"; \
			$(GFX) $(dir $*)$$segfile.png $*_$$segfile.4bpp $$mw_arg $$mh_arg $$oam_arg; \
			segfiles="$$segfiles $*_$$segfile.4bpp"; \
		done; \
#		echo -e "catting segments: $$segfiles -> $@ \n"; \
		cat $$segfiles > $@; \
	else \
		mw=$$(printf '%s' "$$params" | sed -n 's/.*[[:space:]]mwidth=\([0-9]\+\).*/\1/p'); \
		mh=$$(printf '%s' "$$params" | sed -n 's/.*[[:space:]]mheight=\([0-9]\+\).*/\1/p'); \
		oam=$$(printf '%s' "$$params" | sed -n 's/.*[[:space:]]oam=\(true\|false\).*/\1/p'); \
		mw_arg=""; mh_arg=""; oam_arg=""; \
		if [ -n "$$mw" ] && [ "$$mw" != 0 ]; then mw_arg="-mwidth $$mw"; fi; \
		if [ -n "$$mh" ] && [ "$$mh" != 0 ]; then mh_arg="-mheight $$mh"; fi; \
		if [ "$$oam" = true ]; then oam_arg="-oam"; fi; \
#		echo -e "Processing whole image: $(GFX) $*.png $@ $$mw_arg $$mh_arg $$oam_arg; \n"; \
		$(GFX) $*.png $@ $$mw_arg $$mh_arg $$oam_arg; \
	fi; \
	if [ -n "$$align_global" ]; then \
		dd if=/dev/zero bs=32 count=$$align_global >> $@; \
	fi;


graphics/field_select/sprites.4bpp: graphics/field_select/sprites.png
	$(GFX) $< $@ -num_tiles 513

graphics/options/sprites.4bpp: graphics/options/sprites.png
	$(GFX) $< $@ -num_tiles 257

graphics/pokedex/text_glyphs.4bpp: graphics/pokedex/text_glyphs.png
	$(GFX) $< $@ -num_tiles 513
