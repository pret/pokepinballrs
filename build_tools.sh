#!/bin/sh
make -C tools/gbafix CXX=${1:-g++}
make -C tools/scaninc CXX=${1:-g++}
