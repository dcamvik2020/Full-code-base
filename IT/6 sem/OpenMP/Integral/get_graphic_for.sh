#!/bin/bash

echo "empty file" >> FOR_result_graphic.txt
rm FOR_result_graphic.txt

N=2'000'000'000'

echo "threads        time        "
for ((threads=1; threads < 5; threads++))
do
echo $threads
time ./FOR $threads $N
done

#cat ./FOR_result_graphic.txt
