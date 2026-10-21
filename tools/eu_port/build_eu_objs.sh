#!/bin/bash
T="$(cd "$(dirname "$0")" && pwd)"; R="$(cd "$T/../.." && pwd)"
# Compile all EU objects (no link). -k: keep going on errors.
cd $R
OBJS=$(ls src/*.c src/*.s | sed 's#^src/\(.*\)\.[cs]$#build/pokepinballrs_eu/src/\1.o#')
make REGION=EU NODEP= -k -j2 $OBJS > $R/build/eu_obj.log 2>&1
rc=$?
if [ $rc -ne 0 ]; then grep -E "error|Error [0-9]|warning:" $R/build/eu_obj.log | grep -v -- "-Werror" | head -30; fi
exit $rc
