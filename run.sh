#!/bin/sh
# Run the fastest-primes entry. Prefers the prebuilt static binary; if it
# cannot execute (e.g. wrong architecture), compiles from source and runs.
D=$(dirname "$0")
"$D/primes" || { cc -O3 -o "$D/primes" "$D/primes.c" && "$D/primes"; }
