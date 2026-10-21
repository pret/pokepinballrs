# Pokémon Pinball R/S — versione europea (BPPP)

Questo ramo (`europe`) estende la decompilazione pret/pokepinballrs (USA, BPPE) alla ROM
europea multilingua (inglese, francese, tedesco, italiano, spagnolo).

## Stato

- `make compare_eu` ricostruisce la ROM EU **identica byte per byte**
  (SHA1 `b8b7881eaa9856b5ada99078ad1053d31cb79827`).
- `make compare` (USA) resta identica: ogni modifica EU è dentro `#ifdef EUROPE`.
- Codice: 848/848 funzioni corrispondenti. 842 in C, 6 usano l'assembly originale nella
  build EU (C conservato sotto `NONMATCHING`):
  - `LoadTitlescreenGraphics` (titlescreen.c): scambio di registri
  - `UpdateSapphireHatchMachine` (sapphire_seedot_egg_shop.c): un reload di r5 in più
  - `EndOfBallBonusSummary` (all_board_mode_change_and_debug_menu.c): riscritta in EU,
    il C attuale è ancora la logica USA (set di caratteri per lingua, tabelle 0x894BFFC)
  - `RestoreMainFieldDynamicGraphics` (save_and_restore_game.c): cross-jump diverso
  - `DrawRubyModeTimerDisplay` / `DrawSapphireModeTimerDisplay`: caso EnDe non fuso
- Dati: `data/eu/*.s` sono **generati** dai sorgenti dati USA allineati alla ROM EU.
  I dati presenti solo in EU (varianti per lingua) sono ancora blob in `data/eu/bin/`
  (~3 MB: grafica per lingua, testi Pokédex in 5 lingue = `gPokedexEntries`, 560 KB).
  Nelle tabelle solo-EU di rom_2 i puntatori sono simbolici; le etichette nuove sono
  `gUnknown_<indirizzo EU>` o, dove ricavabile, `<nome USA>_<Lingua>`.

## Build

Toolchain come da INSTALL.md (agbcc in `tools/agbcc`, binutils arm-none-eabi).

    make compare_eu -j8     # ROM europea
    make compare -j8        # ROM americana (regressione)

La build non richiede la ROM originale. Gli strumenti di porting sì: copiare la ROM EU
in `baserom_eu.gba` nella radice del repo (ignorata da git) o impostare `BASEROM_EU`.

## Convenzioni EU nel codice

- Lingua corrente: `gMain_saveData.language` (gMain+0x141). EN 0, FR 1, DE 2, IT 3, ES 4, 99 = non impostata.
- Macro in `include/global.h`: `LANG5_SWITCH`, `DMA_LANG5`, `DMA_LANG5_AT`, `EXTERN_LANG5`,
  `DMA_LANG4_ENFR`, `LANG4_SWITCH_ENDE`, ecc. Simboli per lingua con suffissi
  `_En/_Fr/_De/_It/_Es` o gruppi (`_EnFr`, `_EnDe`, `_EnDeItEs`, …).
- I raggruppamenti di lingue cambiano da asset ad asset: copiare quello della ROM.
- `struct SaveData` ha `language` in più (customButtonConfig +2, highScores +4, il resto di gMain +4).
- `struct PokemonSpecies.name` è `[3][10]` (EN, FR, DE), vedi `src/data/species.h` (`SPECIES_NAME`).
- RAM EU: `sym_ewram_eu.txt` (generato da `gen_ram.py`), `sym_bss_eu.txt`, `sym_common_eu.txt`.

## Strumenti (`tools/eu_port/`, Python 3 + pyelftools + capstone)

- `check.sh [oggetto]`: compila gli oggetti EU, confronta con la ROM EU per funzione, poi `make compare` USA.
- `fdiff.py src/X.o Funzione 0xEUADDR [SIZE]`: diff istruzione per istruzione di una funzione.
- `eudis.py ADDR SIZE`, `langsw.py ADDR SIZE`, `xref.py ADDR`: disassembly EU, tabelle switch per lingua, riferimenti.
- `try_variants.py`: prova varianti di sorgente (attenzione: tocca codice condiviso, ricontrollare USA).
- `fn2asm.py` + `wrap_asm.py FILE.c Funzione START END`: sostituisce in EU una funzione con l'asm originale.
- `regen.sh`: rigenera i dati EU: simboli dal codice (`codesyms.py`) → allineamento dati USA/EU
  (`align_data.py`) → layout RAM (`gen_ram.py`) → `data/eu/*.s` (`gen_eu_data.py`).
  Va rieseguito dopo modifiche al C che cambiano riferimenti ai dati; poi `make compare_eu`.
- `romdiff.py`, `worddiff.py`: dove differisce la ROM costruita e di quanto sono spostati i puntatori.
- `data/`: dati di riferimento (inizi oggetti EU, nomi, nomi extra); i JSON generati sono ignorati da git.

Attenzione: `data/eu/*.s` sono generati; modificarli a mano va bene solo se poi non si rilancia
`regen.sh` (oppure portare la modifica nel generatore).

## Prossimi passi possibili

1. Testi Pokédex EU (`gPokedexEntries`, struct `PokedexEntry` EU 0xAAC byte in pokedex.c) in forma
   leggibile: estendere la tabella `.dexText` di tools/preproc con i glifi accentati EU.
2. Grafica per lingua da `data/eu/bin` a PNG (stesse dimensioni/palette delle controparti USA)
   con regole in graphics_rules.mk.
3. Riprovare in C le 6 funzioni in asm.
4. Sprite set solo-EU di rom_2 da `.byte` alle macro `packed_sprite_oaml` come in USA.
