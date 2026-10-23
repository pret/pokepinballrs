# Pokémon Pinball R/S — versione europea (BPPP)

Questo ramo (`europe`) estende la decompilazione pret/pokepinballrs (USA, BPPE) alla ROM
europea multilingua (inglese, francese, tedesco, italiano, spagnolo).

## Stato

- `make compare_eu` ricostruisce la ROM EU **identica byte per byte**
  (SHA1 `b8b7881eaa9856b5ada99078ad1053d31cb79827`).
- `make compare` (USA) resta identica: ogni modifica EU è dentro `#ifdef EUROPE`.
- Codice: 848/848 funzioni corrispondenti, tutte in C (nessuna usa più l'assembly originale).
  Le ultime risolte, oltre al port in C del codice EU:
  `EndOfBallBonusSummary` (logica EU riscritta: indice lingua, glifi, tabelle),
  `Draw{Ruby,Sapphire}ModeTimerDisplay` (dimensione per lingua del 3° blocco di tile "saver"),
  `UpdateSapphireHatchMachine` (in EU il setup del banner è in un `do { } while (0)`, che chiude
  il blocco CSE: macro `BANNER_SETUP_BEGIN/END`), `LoadTitlescreenGraphics` (le copie DMA comuni
  sono ripetute in entrambi i rami del test sul salvataggio, come in USA, e il compilatore le
  fonde: la ripetizione cambia l'allocazione dei registri), `RestoreMainFieldDynamicGraphics`
  (indice dell'uovo in `var0` prima della DMA; in fondo al caso ROULETTE_WHEEL un fake match
  `game->evoChainPosition += 0`, come il `ball += 0` USA: reload lo elimina dopo aver fatto
  avanzare la rotazione dei registri di reload, `last_spill_reg` in reload1.c, del caso dopo).
  Le ultime due trovate con decomp-permuter (vedi sotto).
- Dati: `data/eu/*.s` sono **generati** dai sorgenti dati USA allineati alla ROM EU.
  I dati solo-EU sono in forma sorgente dove possibile:
  - `data/eu/src/pokedex_entries.inc`: Pokédex EU (205 voci, 5 lingue) con `.dexLang`;
  - `data/eu/src/bonus_summary_templates.inc`: testi del riepilogo bonus FR/IT/DE/ES;
  - `data/eu/src/{high_score_tables,pause_menu_sprite_offsets,idle_press_start_tiles}.inc`:
    tabelle (scritte da `dump_tables_eu.py`);
  - `data/eu/src/ereader_text*.inc`: testi dell'e-Reader in 5 lingue (`dump_ereader_eu.py`);
  - `data/eu/src/orphaned_se_tracks.inc`: altre tracce orfane dopo `broken_se_6A36D4`;
  - grafica per lingua: 1257 blob convertiti in `graphics/**/<file USA>_<lingua>.png/.pal/.bin`
    (suffisso minuscolo del gruppo di lingue, `_eu` se il simbolo non ha suffisso), più la
    grafica solo-EU (`graphics/language_select/`, testi intro, ordinali dei record, testi e-Reader,
    etichette del cartello del negozio Ruby, la lettera "!" dell'alfabeto del tabellone);
    i fogli sprite del Pokédex FR/DE/ES hanno segmenti propri in
    `graphics/pokedex/pokedex_gfx_eu.json`;
  - copie non usate dal codice dei dati inglesi (frecce EVO/monete FR/IT/ES di Ruby e Sapphire)
    scritte con i file USA;
  - sprite set solo-EU di rom_2 scritti con `packed_sprite_oam(l)` come in USA; tabelle solo-EU
    di rom_2 con il tipo degli elementi della dichiarazione C (`.byte`/`.2byte`/`.4byte`).
  Nessun dato EU resta come blob binario (`data/eu/bin/` è vuota) né come righe `.byte` anonime:
  le righe `.byte` rimaste sono tabelle con etichetta e tipo della dichiarazione C o USA.
  La coda della ROM (0x08FE0000, 16 KB, mai referenziata) è disassemblata in
  `data/eu/rom_tail.s` da `disasm_rom_tail.py`: uno strumento di sviluppo (probabilmente un
  debug monitor) con una parte residente (primi 4 KB) collegata a 0x09FE2000 e tre overlay
  (le pagine da 4 KB successive) collegati tutti a 0x09FE3000, ognuno con una tabella di punti
  d'ingresso all'inizio; i puntatori 0x09FE3xxx di un overlay puntano all'overlay stesso.
  Le copie per lingua dei dati sprite non usati (regioni `gSpriteSetRawDup_`
  USA, mai referenziate dal codice) sono scritte come sprite set seguiti da animazioni: contatore
  e coppie (fotogramma, durata). In USA la stessa struttura è scritta, a torto, come sprite set
  (`gPackedOamDup_*`, `gUnusedSpriteSets_*`).
  Nelle tabelle solo-EU di rom_2 i puntatori sono simbolici; le etichette nuove sono
  `gUnknown_<indirizzo EU>` o, dove ricavabile, `<nome USA>_<Lingua>`; nomi aggiunti a mano
  in `tools/eu_port/data/extra_names.json` (es. pezzi del cartello del negozio Ruby).

## Build

Toolchain come da INSTALL.md (agbcc in `tools/agbcc`, binutils arm-none-eabi, `jq`).

    make compare_eu -j8     # ROM europea
    make compare -j8        # ROM americana (regressione)

La build non richiede la ROM originale. Gli strumenti di porting sì: copiare la ROM EU
in `baserom_eu.gba` nella radice del repo (ignorata da git) o impostare `BASEROM_EU`.
Su Windows (MSYS2) usare il `jq` di msys, non quello mingw (scrive CRLF e rompe
`graphics_rules_generated.mk`), e Python in modalità UTF-8 (`python -X utf8`).

## Convenzioni EU nel codice

- Lingua corrente: `gMain_saveData.language` (gMain+0x141). EN 0, FR 1, DE 2, IT 3, ES 4, 99 = non impostata.
- Macro in `include/global.h`: `LANG5_SWITCH`, `DMA_LANG5`, `DMA_LANG5_AT`, `EXTERN_LANG5`,
  `DMA_LANG4_ENFR`, `LANG4_SWITCH_ENDE`, ecc. Simboli per lingua con suffissi
  `_En/_Fr/_De/_It/_Es` o gruppi (`_EnFr`, `_EnDe`, `_EnDeItEs`, …).
- I raggruppamenti di lingue cambiano da asset ad asset: copiare quello della ROM.
- Alcune tabelle sono indicizzate in un altro ordine (es. testi del riepilogo bonus: En, Fr, It, De, Es).
- `struct SaveData` ha `language` in più (customButtonConfig +2, highScores +4, il resto di gMain +4).
- `struct PokemonSpecies.name` è `[3][10]` (EN, FR, DE), vedi `src/data/species.h` (`SPECIES_NAME`).
- RAM EU: `sym_ewram_eu.txt` (generato da `gen_ram.py`), `sym_bss_eu.txt`, `sym_common_eu.txt`.

## Testi del Pokédex (tools/preproc)

- `.dexLang EN|FR|DE|IT|ES` sceglie la codifica europea dei glifi (US = quella americana, default);
  le tabelle sono in `ApplyEuropeanDexEncoding` (asm_file.cpp): glifi accentati, ß, „ « », `œ`
  (2 glifi), larghezze diverse di k, z, 1, `, é, “ a seconda della lingua.
- `{XXXX}` nelle stringhe dex scrive un codice glifo grezzo (8 casi in tutto il Pokédex EU).
- `.dexCategoryLeftAligned`: categoria allineata a sinistra (FR/DE/IT/ES; in EN è a destra come in USA).
- Testi e-Reader: con una lingua `.dexLang` attiva `.ereaderText` scrive righe di 25 celle (24 in
  USA) con larghezze fisse e i glifi europei; `.ereaderDexText` usa le larghezze del Pokédex della
  lingua. Le righe EU usano l'una o l'altra (il gioco ignora la larghezza); 8 caratteri sono `{XXXX}`.

## Strumenti (`tools/eu_port/`, Python 3 + pyelftools + capstone)

- `check.sh [oggetto]`: compila gli oggetti EU, confronta con la ROM EU per funzione, poi `make compare` USA.
- `fdiff.py src/X.o Funzione 0xEUADDR [SIZE]`: diff istruzione per istruzione di una funzione.
- `nonmatching.sh FILE.c`: compila per EU con `-DNONMATCHING` in `build/nm/src/FILE.o`
  (poi `fdiff.py ../nm/src/FILE.o Funzione 0xEUADDR SIZE`).
- `lcm_sim.py`: simula la PRE/LCM di agbcc su un dump `-dG` per capire perché un'espressione
  (es. l'indirizzo di un globale) viene ricaricata o riusata.
- `eudis.py ADDR SIZE`, `langsw.py ADDR SIZE`, `xref.py ADDR`: disassembly EU, tabelle switch per lingua, riferimenti.
- `try_variants.py`: prova varianti di sorgente (attenzione: tocca codice condiviso, ricontrollare USA).
- `fn2asm.py` + `wrap_asm.py FILE.c Funzione START END`: sostituisce in EU una funzione con l'asm originale.
- `regen.sh`: rigenera i dati EU: simboli dal codice (`codesyms.py`) → allineamento dati USA/EU
  (`align_data.py`) → layout RAM (`gen_ram.py`) → `data/eu/*.s` (`gen_eu_data.py`).
  Va rieseguito dopo modifiche al C che cambiano riferimenti ai dati; poi `make compare_eu`.
  `gen_eu_data.py` include al posto dei byte: i file `data/eu/src/*.inc` con una riga
  `@ eu_range INIZIO FINE` (possono definire etichette interne con `::` o `.set`), e la grafica
  elencata in `tools/eu_port/data/eu_graphics.json`. Scrive anche gli sprite set di rom_2 con le
  macro (anche sequenze di set e set seguiti da animazioni, fino al primo puntatore), le tabelle
  solo-EU con un tipo scalare nella dichiarazione C (`C_TYPES`), gli indirizzi VRAM con
  l'espressione della tabella USA omonima (`BG_ADDR_FOR_BOARD_WRAP(y, x)`) o una costante
  `BG_/OBJ_VRAM_ADDR_`, `.space` per gli intervalli nulli senza etichetta, e l'elenco dei blob in
  `data/eu_blobs.json` (generato, ignorato da git). Una voce di `eu_graphics.json` che contiene
  un'etichetta aggiunta dopo viene scartata (il blob torna a `gfx_eu.py`). `UNALIGNED`: elementi
  USA da non allineare perché in EU sono più lunghi anche in inglese (diventano blob interi).
  Un intervallo senza etichetta continua l'elemento prima (stesso tipo; i valori delle espressioni
  non simboliche delle tabelle USA sono valutati assemblando ognuna dopo una propria etichetta, e
  un valore che manca in USA usa la costante della stessa famiglia, `NUM_DEFINES`); parole nulle
  delle tabelle di puntatori come `.4byte 0`, padding finale come `.align 2, 0`; sprite set
  seguiti da meno di 8 byte nulli; tabelle di puntatori a funzioni Thumb di rom_1 per nome.
  Il Makefile passa `-DEUROPE` (`REGION_DEFS`) anche al cpp dei file dati EU.
- `gfx_eu.py` (dopo `regen.sh`, perché legge `eu_blobs.json`; poi di nuovo `regen.sh`): converte
  i blob di grafica in copie per lingua dei file USA con gbagfx e verifica il giro inverso. Abbina
  un blob all'elemento USA con lo stesso nome senza suffisso di lingua (e agli elementi USA
  successivi se in EU mancano le etichette intermedie); gestisce LZ, `.fill/.align`, segmenti
  dei JSON gfx-config, immagini con più o meno tile (`-num_tiles`), padding con dati, una serie
  di elementi che finisce con un "filler" più lungo (solo se gli elementi inglesi sono consecutivi
  anche nella ROM EU). Un file EU con segmenti propri (altre dimensioni, più segmenti) è descritto
  da una voce di un JSON gfx-config (es. `graphics/pokedex/pokedex_gfx_eu.json`, con `height` in
  tile per i segmenti da scrivere): lo script scrive i PNG mancanti e controlla gli altri. Gli
  alias (`ALIASES`), le copie non usate dei dati inglesi (`UNUSED_COPIES`) e la grafica solo-EU
  (`EXTRA`: file, larghezza, palette) sono descritti nello script. Non abbina mai per sola
  dimensione: sceglierebbe file sbagliati. Scrive `tools/eu_port/data/eu_graphics.json` e
  `graphics_rules_eu.mk`.
  Dopo una modifica alle regole cancellare i `.4bpp` generati: make non li ricostruisce se
  cambiano solo le opzioni. Se si filtra l'output (`| tail`) usare `set -o pipefail`: con un
  `regen.sh` fallito `gfx_eu.py` lavorerebbe su un `eu_blobs.json` incompleto e riscriverebbe
  molti PNG. Dopo una modifica a `gfx_eu.py` controllare il diff di `eu_graphics.json` voce per
  voce: anche un abbinamento sbagliato supera il giro inverso e il confronto della ROM.
- `dump_dex_eu.py`, `dump_ereader_eu.py`, `dump_tables_eu.py`: riscrivono dalla ROM EU il Pokédex,
  i testi e-Reader e le tabelle in `data/eu/src/`.
- `disasm_rom_tail.py`: riscrive `data/eu/rom_tail.s` (discesa ricorsiva ARM/Thumb con capstone,
  etichette col nome dell'indirizzo di esecuzione, indirizzi come `label - RES/OV1/OV2/OV3`) e
  lo verifica riassemblandolo come il Makefile (preproc, cpp, as); un'istruzione che as codifica
  diversamente diventerebbe `.inst` (oggi nessuna). Il codice non raggiunto è in `EXTRA_CODE`;
  `-l INIZIO FINE` stampa la classificazione. Richiede binutils e cpp arm-none-eabi nel PATH.
- `romdiff.py`, `worddiff.py`: dove differisce la ROM costruita e di quanto sono spostati i puntatori.
- `data/`: dati di riferimento (inizi oggetti EU, nomi, nomi extra, `eu_graphics.json`);
  i JSON generati dall'allineamento sono ignorati da git.

Attenzione: `data/eu/*.s` sono generati; modificarli a mano va bene solo se poi non si rilancia
`regen.sh` (oppure portare la modifica nel generatore o in `data/eu/src/`).

## Prossimi passi possibili

1. Sostituire il fake match di `RestoreMainFieldDynamicGraphics` con il costrutto originale,
   se si trova. decomp-permuter (github.com/simonlindholm/decomp-permuter) si usa con una
   cartella per funzione: `base.c` preprocessato con `-DEUROPE -DNONMATCHING` (prima di togliere
   il C da `NONMATCHING`, o direttamente), `target.o` assemblato dal codice originale della
   funzione (etichette locali `.L`, padding come `.align 2, 0`), `compile.sh` con i flag di
   agbcc della build. Conviene randomizzare solo la zona interessata (`PERM_RANDOMIZE`); i suoi
   match vanno poi riletti per trovare il costrutto naturale equivalente.
2. Riscrivere anche nel sorgente USA le regioni `Dup` come sprite set + animazioni (byte
   identici; oggi sono scritte come sprite set fittizi).
3. Dare nomi significativi a funzioni e dati dello strumento in `data/eu/rom_tail.s` (oggi hanno
   il nome dell'indirizzo di esecuzione): andrebbero in una tabella del generatore.
