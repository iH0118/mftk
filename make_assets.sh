#!/bin/sh

cd assets
rm -f *.c *.h
for dir in */; do
    dir=${dir%*/}
    dir=${dir##*/}
    touch assets_$dir.c assets_$dir.h
    echo "#ifndef INCLUDE_ASSETS_$(echo $dir | tr '[:lower:]' '[:upper:]')_H" >> assets_$dir.h
    echo "#define INCLUDE_ASSETS_$(echo $dir | tr '[:lower:]' '[:upper:]')_H" >> assets_$dir.h
    echo "#include \"assets_$dir.h\"" >> assets_$dir.c
    cd $dir
    for f in *.png; do
        name_noext="${f%.*}"
        name_noext="${name_noext##*/}"
        echo "extern unsigned char $name_noext""_png[];" >> ../assets_$dir.h
        echo "extern unsigned int $name_noext""_png_len;" >> ../assets_$dir.h
        xxd -i $f >> ../assets_$dir.c
    done
    cd ..
    echo "#endif" >> assets_$dir.h
done
cd ..
