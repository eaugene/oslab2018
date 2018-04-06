#!/bin/bash

hr=`date +%H`

if [ $hr -ge 5 ] && [ $hr -lt 12 ];
then
  echo "Good morning $USER"
elif [ $hr -ge 12 ] && [ $hr -lt 16 ];
then
  echo "Good Afternoon $USER"
elif [ $hr -ge 16 ] && [ $hr -lt 20 ];
then
  echo "Good Evening $USER"
elif [ $hr -ge 20 ] && [ $hr -lt 5 ];
then
  echo "Good Night $USER"
else
  echo "Wrong Time"
fi
