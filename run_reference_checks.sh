#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname "$0")")
cd "$ROOT"
g++ -O3 -std=c++17 supplement/programs/reference_closure.cpp -o /tmp/wsat_q3_reference_closure
/tmp/wsat_q3_reference_closure 10 supplement/n10_reps6.bin
/tmp/wsat_q3_reference_closure 11 supplement/n11_reps7.bin
