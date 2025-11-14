#!/bin/sh

set -eu

FILES="specs/spec.c src/alloc.c include/linux/list.h include/prelude.h include/linux/container_of.h include/linux/bitfield.h include/linux/minmax.h include/fulminate.h include/alloc.h src/shim.c"
BANWORDS="HK PS KM RB TODO workaround Hiro peter Peter hiro"

TMPDIR=$(mktemp -d)

OUTDIR="$TMPDIR/supplementary_material"
mkdir -p "$OUTDIR"

for f in $FILES; do
    for w in $BANWORDS; do
        if grep -q "$w" "$f"; then
            echo "ERROR: File '$f' contains banned word: $w"
            exit 1
        fi
    done
done

echo "Using temp dir: $TMPDIR"

for f in $FILES; do
    mkdir -p "$OUTDIR/$(dirname "$f")"
    cp "$f" "$OUTDIR/$f"
done
cp SUPPLEMENTARY_MATERIAL_README.md "$OUTDIR/README.md"

tar czvf supplementary_material.tar.gz -C "$TMPDIR" supplementary_material

#rm -rf "$TMPDIR"
