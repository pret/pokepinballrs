#!/bin/bash
T="$(cd "$(dirname "$0")" && pwd)"; R="$(cd "$T/../.." && pwd)"
# Rebuild EU objects, compare given objects (verbose), and verify the US ROM still matches.
$T/build_eu_objs.sh > /dev/null
python3 -I $T/cmp_eu.py "$@" -v | grep -v anchor | grep -v " ok "
cd $R && make compare 2>&1 | tail -1
