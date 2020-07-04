#!/bin/bash

for i in {1..100}
do
    OUT=
    if (( i % 3 == 0 )); then
        OUT=fizz
    fi
    if (( i % 5 == 0 )); then
        OUT=${OUT}buzz
    fi

    if [ -z $OUT ]; then
        echo $i
    else
        echo $OUT
    fi
done
