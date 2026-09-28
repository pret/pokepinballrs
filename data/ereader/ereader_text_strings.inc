gEReaderTextGlyphTable:: @ 0x086A4CF8
@ 14 pages of 3 rows x 24 columns of u16, one entry per character cell.
@ Entry = (byte offset of the glyph within gEReaderText_Gfx) | (advance width in px).
@ A glyph is 1 tile wide and 2 tall; 0x0000 is a blank cell.
@ DrawEReaderTextPage masks the width off with & 0xFFF0 and nothing ever reads it:
@ Glyph spacing mostly matches the char spacing in the dex, but there's a few characters
@ that are increased to 6 px for the char. n has some using 5px, some using 6???

	.ereaderText "Transmit data with the"
	.ereaderText "e-Reader!"
    .ereaderText ""

	.ereaderText "Press the A Button"
	.ereaderText "when you#re ready."
	.ereaderText ""

	.ereaderText "Transmission successful."
	.ereaderText ""
    .ereaderText "When you activate"

	.ereaderText "CATCH `EM MODE, there is"
	.ereaderText "a special appearance of"
	.ereaderText "rare Pokémon."

	.ereaderText "Transmission successful."
	.ereaderText ""
    .ereaderText ""

	.ereaderText "The Pokémon which rarely"
	.ereaderText "appear are now easier to"
	.ereaderText "find iņ CATCH `EM MODE."

	.ereaderText "Transmission successful."
	.ereaderText ""
    .ereaderText ""

	.ereaderText "Start with nine Balls."
	.ereaderText "Start with Master Ball."
	.ereaderText ""

	.ereaderText "Start with 99 Coins."
	.ereaderText "Pichu Saver stays oņ."
	.ereaderText ""

	.ereaderText "Transmission successful."
	.ereaderText ""
    .ereaderText ""

	.ereaderText "Start iņ the Ruin Area."
	.ereaderText "First bonus stage will"
	.ereaderText "be the RAYQUAZA stage."

	.ereaderText "Transmission successful."
	.ereaderText ""
    .ereaderText ""

	.ereaderText "You can select the"
	.ereaderText "bonus stage."
	.ereaderText ""

	.ereaderText "Transmission failure."
	.ereaderText "Check the connection"
	.ereaderText "and try once again."
