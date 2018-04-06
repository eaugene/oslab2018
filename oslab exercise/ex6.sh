#!/bin/bash

echo "enter the elements of array"
read -a ar
echo "${#ar[@]}"

m=${ar[0]}
l=${ar[0]}

for e in ${ar[@]};
do
  if [ $e -gt $m ]
     then
m=$e
fi
if [ $e -lt $l ]
then
l=$e
fi
done
echo "minimum: " $l
echo "maxinum: " $m
