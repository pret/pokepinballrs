#!/bin/bash
T="$(cd "$(dirname "$0")" && pwd)"; R="$(cd "$T/../.." && pwd)"
# Compile src/FILE.c for EU with -DNONMATCHING (the C version of functions kept in asm) into
# build/nm/src/FILE.o, to compare it with: fdiff.py ../nm/src/FILE.o Function 0xEUADDR SIZE
# usage: nonmatching.sh FILE.c [extra cpp flags...]   (extra flags: e.g. -DSOMETHING)
set -e
cd $R
b=$(basename "$1" .c); shift
mkdir -p build/nm/src
arm-none-eabi-cpp -I tools/agbcc/include -I tools/agbcc -iquote include -nostdinc -undef -DEUROPE -DNONMATCHING "$@" src/$b.c -o build/nm/$b.i
tools/preproc/preproc build/nm/$b.i charmap.txt | tools/agbcc/bin/agbcc -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm -fprologue-bugfix -g -o build/nm/$b.s
echo -e ".text\n\t.align\t2, 0\n" >> build/nm/$b.s
arm-none-eabi-as -mcpu=arm7tdmi --defsym EUROPE=1 -o build/nm/src/$b.o build/nm/$b.s
echo build/nm/src/$b.o
