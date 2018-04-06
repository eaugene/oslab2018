#!/bin/bash

for e in `ls`
do
  echo `wc $e`
done
