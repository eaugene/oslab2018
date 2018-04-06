#!/bin/bash

echo "Enter a number to get summing"
read n

d=0
s=1

while [ $d -le $n ]
do
  s=$(expr $s + $d)
  echo $s
  d=$(expr $d + 1)
done
