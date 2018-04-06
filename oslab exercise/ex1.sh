#!bin/bash
# second

if [ $2 = "+" ];
then
 s=$(expr $1 + $3)
 echo $s
elif [ $2 = "-" ]
then
 s=$(expr $1 - $3)
 echo $s
elif [ $2 = "x" ]
then
 s=$(expr $1 \* $3)
 echo $s
elif [ $2 = "/" ]
then
 s=$(expr $1 / $3)
 echo $s
else
 echo "wrong option"
fi
