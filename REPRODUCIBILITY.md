# Reproducibility record

The manuscript treats the lower bounds as finite computer-assisted proofs. The
mathematical reduction, finite state spaces, closure rules, symmetry actions,
and certificate conditions are specified in `docs/PROOF_SPEC.md` and proved in
`paper/wsat_q3.tex`.

## Theorem-bearing computations

- `n9_exact_verifier.cpp`: checks the n=9 certificate, excludes all 10,626 four-edge seeds, and scans the 42,504 five-edge seeds.
- `n9_independent_lower.go`: independently recomputes the n=9 four-edge exclusion using explicit edge lists and queue-indexed rules.
- `n9_graph_level_check.py`: enumerates all 7,560 labelled cube copies and checks the n=9 certificate.
- `n10_lower_orbit_search.cpp`: enumerates the complete six-edge layer, canonicalizes under the marked-cube stabilizer, and checks all 146,131 orbit representatives.
- `n11_lower_orbit7.cpp`: generates the complete seven-edge orbit layer from the six-edge layer and checks all 1,498,208 representatives.
- `n11_burnside.py`: independently verifies the n=11 orbit counts by Burnside's lemma.
- `n10_upper_verifier.{cpp,py}` and `n11_upper_verifier.{cpp,py}`: independent certificate checks using separate code paths.
- `verify_witness_tables.py`: checks the machine-readable witness tables, including injectivity, target equality, dependency indices, and final completeness.
- `reference_closure.cpp`: a structurally different closure implementation using antecedent counters and reverse incidence lists. It audits the stored complete representative layers in `n10_reps6.bin` and `n11_reps7.bin`.

## Reported finite counts

The execution records distributed with the package give:

- n=9: 7,560 labelled cubes; 7,122 distinct outside masks; 10,626 four-edge seeds; 0 percolating; maximum closure 16; 42,504 five-edge seeds; 6,864 percolating.
- n=10: 37,800 labelled cubes; 36,506 distinct outside masks; 1,107,568 six-edge seeds; 146,131 orbit representatives; 0 percolating; maximum closure 25.
- n=11: 138,600 labelled cubes; 135,650 distinct outside masks; 300,563 six-edge orbit representatives; 11,120,831 seven-edge children before deduplication; 1,498,208 seven-edge representatives; 0 percolating; maximum closure 33.

The closure distributions used in the manuscript are in
`results/closure_histograms.txt`.

## Build

Run `./build_paper.sh` from the repository root. The script performs two
LaTeX passes and copies the resulting PDF to the repository root.

## Archive integrity

`SHA256SUMS.txt` is generated from paths relative to the repository root so
that verification does not depend on the machine on which the package was
built.
