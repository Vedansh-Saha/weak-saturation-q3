#!/bin/sh
set -eu
cd "$(dirname "$0")/paper"
pdflatex -interaction=nonstopmode -halt-on-error wsat_q3.tex >/dev/null
pdflatex -interaction=nonstopmode -halt-on-error wsat_q3.tex >/dev/null
cp wsat_q3.pdf ../wsat_q3.pdf
