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

# --- BG sheets rebuilt from assembled screens -------------------------------
# These tile sheets are deduplicated, so the raw sheet is not editable as an
# image at any width. The checked-in source is the assembled screen instead
# (8bpp, pixel = palette bank * 16 + colour index); detilemap folds the screens
# back down through their tilemaps. See tools/scripts/detilemap.py.

PYTHON ?= python3
DETILEMAP := $(PYTHON) tools/scripts/detilemap.py

S1TORCHIC := graphics/intro/scene1torchic
# bg0_tilemap.bin is not listed: its three screens reference only blank tiles of
# this sheet (its artwork lives in the ball buffer, tiles 704-890), so it adds
# no pixels here. Tiles 320-703 are unreferenced and come out as zeroes.
$(S1TORCHIC)/tiles.4bpp: $(S1TORCHIC)/bg3_text_screen.png $(S1TORCHIC)/bg3_text_tilemap.bin \
                         $(S1TORCHIC)/bg1_dividers_screen.png $(S1TORCHIC)/bg1_dividers_tilemap.bin \
                         $(S1TORCHIC)/bg2_dividers_screen.png $(S1TORCHIC)/bg2_dividers_tilemap.bin \
                         tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 704 -o $@ \
		--from $(S1TORCHIC)/bg3_text_screen.png:$(S1TORCHIC)/bg3_text_tilemap.bin:32x32 \
		--from $(S1TORCHIC)/bg1_dividers_screen.png:$(S1TORCHIC)/bg1_dividers_tilemap.bin:32x64 \
		--from $(S1TORCHIC)/bg2_dividers_screen.png:$(S1TORCHIC)/bg2_dividers_tilemap.bin:32x64

# Bonus boards are static: no scroll ring, and all three BG layers read char
# base 2, so the sheet folds straight out of its three 32x32 screens.
# See data/board_data/VRAM_LAYOUT.md.
DUSCLOPS := graphics/stage/dusclops
$(DUSCLOPS)/dusclops_board_bg_tiles.4bpp: \
		$(foreach s,bg0 bg1 bg2,$(DUSCLOPS)/dusclops_board_$(s)_screen.png $(DUSCLOPS)/dusclops_board_$(s)_tilemap.bin) \
		tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(DUSCLOPS)/dusclops_board_bg0_screen.png:$(DUSCLOPS)/dusclops_board_bg0_tilemap.bin:32x32 \
		--from $(DUSCLOPS)/dusclops_board_bg1_screen.png:$(DUSCLOPS)/dusclops_board_bg1_tilemap.bin:32x32 \
		--from $(DUSCLOPS)/dusclops_board_bg2_screen.png:$(DUSCLOPS)/dusclops_board_bg2_tilemap.bin:32x32

KYOGRE := graphics/stage/kyogre
# 32 non-blank tiles (water/bubble art) sit unreferenced in an 8x4 block at rows
# 8-11, cols 4-11 of the 32-wide grid. One 32x4 strip over tiles 256-383 covers
# them; the referenced tiles it also spans agree with the screens.
$(KYOGRE)/kyogre_board_bg_tiles.4bpp: \
		$(foreach s,bg0 bg1,$(KYOGRE)/kyogre_board_$(s)_screen.png $(KYOGRE)/kyogre_board_$(s)_tilemap.bin) \
		$(KYOGRE)/kyogre_board_unmapped.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(KYOGRE)/kyogre_board_bg0_screen.png:$(KYOGRE)/kyogre_board_bg0_tilemap.bin:32x32 \
		--from $(KYOGRE)/kyogre_board_bg1_screen.png:$(KYOGRE)/kyogre_board_bg1_tilemap.bin:32x32 \
		--extra $(KYOGRE)/kyogre_board_unmapped.png@256

KECLEON := graphics/stage/kecleon
# The four kecleon_overlay_* maps are not screens: kecleon_process3.c mines rows
# out of gKecleonBerryOverlayTilemap into gBG0TilemapBuffer as fragments, so they
# render as strips rather than pictures. They are still the only source for tiles
# 640-1023, and all four contribute distinct ones, so all four are needed.
KECLEON_MAPS := kecleon_board_bg0 kecleon_board_bg1 \
                kecleon_overlay_0 kecleon_overlay_1 kecleon_overlay_2 kecleon_overlay_3
$(KECLEON)/kecleon_board_bg_tiles.4bpp: \
		$(foreach s,$(KECLEON_MAPS),$(KECLEON)/$(s)_screen.png $(KECLEON)/$(s)_tilemap.bin) \
		tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		$(foreach s,$(KECLEON_MAPS),--from $(KECLEON)/$(s)_screen.png:$(KECLEON)/$(s)_tilemap.bin:32x32)

SPHEAL := graphics/stage/spheal
# Only two of its layers have a static tilemap; BG1's is built at runtime.
# 32 non-blank tiles sit unreferenced in an 8x4 block at rows 17-20, cols 4-11,
# so one 32x4 strip over tiles 544-671 carries them.
$(SPHEAL)/spheal_board_bg_tiles.4bpp: \
		$(SPHEAL)/spheal_board_bgwater_screen.png $(SPHEAL)/spheal_board_bgwater_tilemap.bin \
		$(SPHEAL)/spheal_board_bg_screen.png $(SPHEAL)/spheal_board_bg_tilemap.bin \
		$(SPHEAL)/spheal_board_unmapped.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(SPHEAL)/spheal_board_bgwater_screen.png:$(SPHEAL)/spheal_board_bgwater_tilemap.bin:32x32 \
		--from $(SPHEAL)/spheal_board_bg_screen.png:$(SPHEAL)/spheal_board_bg_tilemap.bin:32x32 \
		--extra $(SPHEAL)/spheal_board_unmapped.png@544

RAYQUAZA := graphics/stage/rayquaza
# Three 32x64 layers, all on char base 2. Tiles 301 and 335 are non-blank but
# referenced by no tilemap.
RAYQUAZA_MAPS := bg0 bg1 scroll
$(RAYQUAZA)/rayquaza_board_bg_tiles.4bpp: \
		$(foreach s,$(RAYQUAZA_MAPS),$(RAYQUAZA)/rayquaza_board_$(s)_screen.png $(RAYQUAZA)/rayquaza_board_$(s)_tilemap.bin) \
		$(RAYQUAZA)/rayquaza_board_unmapped_a.png $(RAYQUAZA)/rayquaza_board_unmapped_b.png \
		tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		$(foreach s,$(RAYQUAZA_MAPS),--from $(RAYQUAZA)/rayquaza_board_$(s)_screen.png:$(RAYQUAZA)/rayquaza_board_$(s)_tilemap.bin:32x64) \
		--extra $(RAYQUAZA)/rayquaza_board_unmapped_a.png@301 \
		--extra $(RAYQUAZA)/rayquaza_board_unmapped_b.png@335

GROUDON := graphics/stage/groudon
$(GROUDON)/groudon_board_bg_tiles.4bpp: \
		$(foreach s,bg0 bg1,$(GROUDON)/groudon_board_$(s)_screen.png $(GROUDON)/groudon_board_$(s)_tilemap.bin) \
		tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(GROUDON)/groudon_board_bg0_screen.png:$(GROUDON)/groudon_board_bg0_tilemap.bin:32x32 \
		--from $(GROUDON)/groudon_board_bg1_screen.png:$(GROUDON)/groudon_board_bg1_tilemap.bin:32x32

# Sapphire shares Ruby's BG configuration and scroll ring exactly.
SAPPHIRE := graphics/stage/sapphire
$(SAPPHIRE)/sapphire_board_strip.4bpp: $(SAPPHIRE)/sapphire_board_screen.png \
                                       $(SAPPHIRE)/sapphire_board_bg0_tilemap.bin \
                                       tools/scripts/detilemap.py
	$(DETILEMAP) extract --row-chunk 32 -n 2048 -o $@ \
		--from $(SAPPHIRE)/sapphire_board_screen.png:$(SAPPHIRE)/sapphire_board_bg0_tilemap.bin:32x64

$(SAPPHIRE)/sapphire_board_bgtop_tiles.4bpp: $(SAPPHIRE)/sapphire_board_strip.4bpp
	head -c 32768 $< > $@

$(SAPPHIRE)/sapphire_board_bgbottom_tiles.4bpp: $(SAPPHIRE)/sapphire_board_strip.4bpp
	tail -c 32768 $< > $@

# Same BG0 runtime-tilemap region as Ruby: tiles 256-318 and 416-510 are
# unreachable statically.
$(SAPPHIRE)/sapphire_board_bgramp_tiles.4bpp: $(SAPPHIRE)/sapphire_board_ramp_screen.png \
		$(SAPPHIRE)/sapphire_board_bgramp_tilemap.bin \
		$(SAPPHIRE)/sapphire_board_ramp_unmapped_a.png \
		$(SAPPHIRE)/sapphire_board_ramp_unmapped_b.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(SAPPHIRE)/sapphire_board_ramp_screen.png:$(SAPPHIRE)/sapphire_board_bgramp_tilemap.bin:32x64 \
		--extra $(SAPPHIRE)/sapphire_board_ramp_unmapped_a.png@256 \
		--extra $(SAPPHIRE)/sapphire_board_ramp_unmapped_b.png@416

$(SAPPHIRE)/sapphire_board_bg_tiles.4bpp: $(SAPPHIRE)/sapphire_board_bg_screen.png \
		$(SAPPHIRE)/sapphire_board_bg_tilemap.bin \
		$(SAPPHIRE)/sapphire_board_bg_unmapped_a.png \
		$(SAPPHIRE)/sapphire_board_bg_unmapped_b.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(SAPPHIRE)/sapphire_board_bg_screen.png:$(SAPPHIRE)/sapphire_board_bg_tilemap.bin:32x64 \
		--extra $(SAPPHIRE)/sapphire_board_bg_unmapped_a.png@705 \
		--extra $(SAPPHIRE)/sapphire_board_bg_unmapped_b.png@880

RUBY := graphics/stage/ruby

# The board art itself. Ruby scrolls, so char base 2 holds a 22-slot ring over a
# 64-chunk virtual strip (bgtop then bgbottom) and tilemap row R draws chunk R --
# hence --row-chunk 32. One screen therefore reconstructs both sheets, which are
# split back apart below. See data/board_data/VRAM_LAYOUT.md.
$(RUBY)/ruby_board_strip.4bpp: $(RUBY)/ruby_board_screen.png $(RUBY)/ruby_board_bg0_tilemap.bin \
                               tools/scripts/detilemap.py
	$(DETILEMAP) extract --row-chunk 32 -n 2048 -o $@ \
		--from $(RUBY)/ruby_board_screen.png:$(RUBY)/ruby_board_bg0_tilemap.bin:32x64

$(RUBY)/ruby_board_bgtop_tiles.4bpp: $(RUBY)/ruby_board_strip.4bpp
	head -c 32768 $< > $@

$(RUBY)/ruby_board_bgbottom_tiles.4bpp: $(RUBY)/ruby_board_strip.4bpp
	tail -c 32768 $< > $@

# The ramp sheet sits at char base 1, which BG0 also reads -- but BG0's tilemap
# is built at runtime, so tiles 256-318 and 416-510 are unreachable statically
# and ride along as strips.
$(RUBY)/ruby_board_bgramp_tiles.4bpp: $(RUBY)/ruby_board_ramp_screen.png \
                                      $(RUBY)/ruby_board_ramp_tilemap.bin \
                                      $(RUBY)/ruby_board_ramp_unmapped_a.png \
                                      $(RUBY)/ruby_board_ramp_unmapped_b.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(RUBY)/ruby_board_ramp_screen.png:$(RUBY)/ruby_board_ramp_tilemap.bin:32x64 \
		--extra $(RUBY)/ruby_board_ramp_unmapped_a.png@256 \
		--extra $(RUBY)/ruby_board_ramp_unmapped_b.png@416

# tile 834 is non-blank but referenced by no tilemap.
$(RUBY)/ruby_board_bg_tiles.4bpp: $(RUBY)/ruby_board_bg_screen.png $(RUBY)/ruby_board_bg_tilemap.bin \
                                  $(RUBY)/ruby_board_bg_unmapped.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 1024 -o $@ \
		--from $(RUBY)/ruby_board_bg_screen.png:$(RUBY)/ruby_board_bg_tilemap.bin:32x64 \
		--extra $(RUBY)/ruby_board_bg_unmapped.png@834

S9BALL := graphics/intro/scene9ballflight
$(S9BALL)/cloud_tiles.4bpp: $(S9BALL)/bg3_clouds_screen.png $(S9BALL)/bg3_clouds_tilemap.bin \
                            tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 288 -o $@ \
		--from $(S9BALL)/bg3_clouds_screen.png:$(S9BALL)/bg3_clouds_tilemap.bin:32x32

S8WAIL := graphics/intro/scene8wailmerlaunch
# tiles 376-394 are non-blank; only 383 of them is reachable through the tilemap,
# so the whole run rides along as a strip (383 agrees with the screen).
$(S8WAIL)/explosion_tiles.4bpp: $(S8WAIL)/bg2_explosion_screen.png $(S8WAIL)/bg2_explosion_tilemap.bin \
                               $(S8WAIL)/tiles_unmapped.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 416 -o $@ \
		--from $(S8WAIL)/bg2_explosion_screen.png:$(S8WAIL)/bg2_explosion_tilemap.bin:32x32 \
		--extra $(S8WAIL)/tiles_unmapped.png@376

S7PARADE := graphics/intro/scene7parade
# tile 590 is non-blank but referenced by no tilemap.
S7SCREENS := bg3_text bg0_pelipper bg1_spoink bg2_makuhita
$(S7PARADE)/tiles.4bpp: $(foreach s,$(S7SCREENS),$(S7PARADE)/$(s)_screen.png $(S7PARADE)/$(s)_tilemap.bin) \
                        $(S7PARADE)/tiles_unmapped.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 640 -o $@ \
		--from $(S7PARADE)/bg3_text_screen.png:$(S7PARADE)/bg3_text_tilemap.bin:32x32 \
		--from $(S7PARADE)/bg0_pelipper_screen.png:$(S7PARADE)/bg0_pelipper_tilemap.bin:64x64 \
		--from $(S7PARADE)/bg1_spoink_screen.png:$(S7PARADE)/bg1_spoink_tilemap.bin:64x64 \
		--from $(S7PARADE)/bg2_makuhita_screen.png:$(S7PARADE)/bg2_makuhita_tilemap.bin:64x64 \
		--extra $(S7PARADE)/tiles_unmapped.png@590

S6CHIN := graphics/intro/scene6chinchou
# tiles 376-394 are non-blank but referenced by no tilemap, so they ride along
# as a 19-tile strip rather than being zeroed.
S6SCREENS := bg3_burst bg0_chinchou bg2_chinchou bg1_ball
$(S6CHIN)/tiles.4bpp: $(foreach s,$(S6SCREENS),$(S6CHIN)/$(s)_screen.png $(S6CHIN)/$(s)_tilemap.bin) \
                      $(S6CHIN)/tiles_unmapped.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 800 -o $@ \
		--from $(S6CHIN)/bg3_burst_screen.png:$(S6CHIN)/bg3_burst_tilemap.bin:32x32 \
		--from $(S6CHIN)/bg0_chinchou_screen.png:$(S6CHIN)/bg0_chinchou_tilemap.bin:32x32 \
		--from $(S6CHIN)/bg2_chinchou_screen.png:$(S6CHIN)/bg2_chinchou_tilemap.bin:32x32 \
		--from $(S6CHIN)/bg1_ball_screen.png:$(S6CHIN)/bg1_ball_tilemap.bin:64x64 \
		--extra $(S6CHIN)/tiles_unmapped.png@376

S5MUDKIP := graphics/intro/scene5mudkip
S5SCREENS := bg3_text bg0 bg1_1sections bg2_2sections
$(S5MUDKIP)/text_tiles.4bpp: $(foreach s,$(S5SCREENS),$(S5MUDKIP)/$(s)_screen.png $(S5MUDKIP)/$(s)_tilemap.bin) \
                             tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 640 -o $@ \
		--from $(S5MUDKIP)/bg3_text_screen.png:$(S5MUDKIP)/bg3_text_tilemap.bin:32x32 \
		--from $(S5MUDKIP)/bg0_screen.png:$(S5MUDKIP)/bg0_tilemap.bin:32x32 \
		--from $(S5MUDKIP)/bg1_1sections_screen.png:$(S5MUDKIP)/bg1_1sections_tilemap.bin:32x64 \
		--from $(S5MUDKIP)/bg2_2sections_screen.png:$(S5MUDKIP)/bg2_2sections_tilemap.bin:32x64

S4PLUSMIN := graphics/intro/scene4plussleminun
# 513 tiles, not 512: the old segmented rule appended one blank tile via
# "align": 1, and tile 512 is that padding.
$(S4PLUSMIN)/tiles.4bpp: $(S4PLUSMIN)/bg3_text_screen.png $(S4PLUSMIN)/bg3_text_tilemap.bin \
                         $(S4PLUSMIN)/bg0_minun_screen.png $(S4PLUSMIN)/bg0_minun_tilemap.bin \
                         $(S4PLUSMIN)/bg1_plussle_screen.png $(S4PLUSMIN)/bg1_plussle_tilemap.bin \
                         tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 513 -o $@ \
		--from $(S4PLUSMIN)/bg3_text_screen.png:$(S4PLUSMIN)/bg3_text_tilemap.bin:32x32 \
		--from $(S4PLUSMIN)/bg0_minun_screen.png:$(S4PLUSMIN)/bg0_minun_tilemap.bin:64x64 \
		--from $(S4PLUSMIN)/bg1_plussle_screen.png:$(S4PLUSMIN)/bg1_plussle_tilemap.bin:64x64

S3TRECK := graphics/intro/scene3treecko
# tile 303 sits in the gap between bg3's range (ends 302) and bg2's (starts 304)
# and is referenced by no tilemap, so it is carried as a one-tile strip.
S3SCREENS := bg3_text bg2 bg0_treecko bg1_ball bg1_ballandflipper bg1_ballflipperhit
$(S3TRECK)/tiles.4bpp: $(foreach s,$(S3SCREENS),$(S3TRECK)/$(s)_screen.png $(S3TRECK)/$(s)_tilemap.bin) \
                       $(S3TRECK)/tiles_unmapped.png tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 864 -o $@ \
		--from $(S3TRECK)/bg3_text_screen.png:$(S3TRECK)/bg3_text_tilemap.bin:32x32 \
		--from $(S3TRECK)/bg2_screen.png:$(S3TRECK)/bg2_tilemap.bin:32x64 \
		--from $(S3TRECK)/bg0_treecko_screen.png:$(S3TRECK)/bg0_treecko_tilemap.bin:32x64 \
		--from $(S3TRECK)/bg1_ball_screen.png:$(S3TRECK)/bg1_ball_tilemap.bin:32x32 \
		--from $(S3TRECK)/bg1_ballandflipper_screen.png:$(S3TRECK)/bg1_ballandflipper_tilemap.bin:32x32 \
		--from $(S3TRECK)/bg1_ballflipperhit_screen.png:$(S3TRECK)/bg1_ballflipperhit_tilemap.bin:32x32 \
		--extra $(S3TRECK)/tiles_unmapped.png@303

S2PIKAS := graphics/intro/scene2pikas
$(S2PIKAS)/tiles.4bpp: $(S2PIKAS)/bg3_text_screen.png $(S2PIKAS)/bg3_text_tilemap.bin \
                       $(S2PIKAS)/bg0_pichu_screen.png $(S2PIKAS)/bg0_pichu_tilemap.bin \
                       $(S2PIKAS)/bg1_pikachu_screen.png $(S2PIKAS)/bg1_pikachu_tilemap.bin \
                       tools/scripts/detilemap.py
	$(DETILEMAP) extract -n 512 -o $@ \
		--from $(S2PIKAS)/bg3_text_screen.png:$(S2PIKAS)/bg3_text_tilemap.bin:32x32 \
		--from $(S2PIKAS)/bg0_pichu_screen.png:$(S2PIKAS)/bg0_pichu_tilemap.bin:64x64 \
		--from $(S2PIKAS)/bg1_pikachu_screen.png:$(S2PIKAS)/bg1_pikachu_tilemap.bin:64x64

# Sheets built by detilemap have no .png source, so the Makefile's
# SECONDARY_ASSETS list -- which is derived from png/pal/wav sources -- does not
# cover them or their .lz derivatives, and make deletes those as intermediates
# after every build. .SECONDARY accumulates, so listing them here is enough.
DETILEMAP_SHEETS := \
	$(S1TORCHIC)/tiles.4bpp \
	$(S2PIKAS)/tiles.4bpp \
	$(S3TRECK)/tiles.4bpp \
	$(S4PLUSMIN)/tiles.4bpp \
	$(S5MUDKIP)/text_tiles.4bpp \
	$(S6CHIN)/tiles.4bpp \
	$(S7PARADE)/tiles.4bpp \
	$(S8WAIL)/explosion_tiles.4bpp \
	$(S9BALL)/cloud_tiles.4bpp \
	$(RUBY)/ruby_board_bg_tiles.4bpp \
	$(DUSCLOPS)/dusclops_board_bg_tiles.4bpp \
	$(GROUDON)/groudon_board_bg_tiles.4bpp \
	$(KECLEON)/kecleon_board_bg_tiles.4bpp \
	$(KYOGRE)/kyogre_board_bg_tiles.4bpp \
	$(RUBY)/ruby_board_strip.4bpp \
	$(RUBY)/ruby_board_bgtop_tiles.4bpp \
	$(RUBY)/ruby_board_bgbottom_tiles.4bpp \
	$(RUBY)/ruby_board_bgramp_tiles.4bpp \
	$(SAPPHIRE)/sapphire_board_strip.4bpp \
	$(SAPPHIRE)/sapphire_board_bgtop_tiles.4bpp \
	$(SAPPHIRE)/sapphire_board_bgbottom_tiles.4bpp \
	$(SAPPHIRE)/sapphire_board_bgramp_tiles.4bpp \
	$(SAPPHIRE)/sapphire_board_bg_tiles.4bpp \
	$(RAYQUAZA)/rayquaza_board_bg_tiles.4bpp \
	$(SPHEAL)/spheal_board_bg_tiles.4bpp

.SECONDARY: $(DETILEMAP_SHEETS) $(addsuffix .lz,$(DETILEMAP_SHEETS))
