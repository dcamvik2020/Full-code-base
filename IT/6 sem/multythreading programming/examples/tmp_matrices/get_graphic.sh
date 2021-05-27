#!/bin/bash

echo "empty file" >> result_graphic.txt
rm result_graphic.txt

N=$1
#echo "Size of matrices : " $N >> result_graphic.txt
#echo "threads       threads, s        usual, s        speedup" >> result_graphic.txt

output=""
for ((threads=1; threads < 12; threads++))
do
  ./ex $N $threads >> ./result_graphic.txt
  #output=$(./ex $N $threads)
  #echo $output
done

cat ./result_graphic.txt
