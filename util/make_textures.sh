#!/bin/sh

cd res
rm -f *.c #*.h
for dir in */; do
    dir=${dir%*/}
    dir=${dir##*/}
    touch textures_$dir.c
    cd $dir
    for f in *.png; do
        xxd -i $f >> ../textures_$dir.c
    done
    cd ..
    sed -i -e 's/unsigned/const unsigned/g' textures_$dir.c
done
cd ..
