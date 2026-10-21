#!/bin/bash
T="$(cd "$(dirname "$0")" && pwd)"; R="$(cd "$T/../.." && pwd)"
# Rebuild EU data sources: symbols from code -> alignment -> RAM layout -> data/eu/*.s
set -e
cd $R
python3 $T/codesyms.py | tail -1
python3 $T/hard_syms.py > $R/build/hard_syms.log
python3 $T/align_data.py | tail -2
python3 $T/gen_ram.py | tail -1
rm -rf data/eu/bin/rom_1_* data/eu/bin/rom_2_* data/eu/bin/sound*
python3 $T/gen_eu_data.py 2>&1 | grep -v "^data/\|^src/\|written" || true
