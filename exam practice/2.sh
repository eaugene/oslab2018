read -a arr
read f
l=${#arr[@]}
s=0
e=$l
while [ $s -le $l ]
do
	m=`expr ($l + $s)`
	m=`expr $m / 2`
	if [ ${arr[$m]} = $f ];
	then
		echo $m
		break
	fi
	if [ ${arr[$m]} -lt $f ];
	then
		s=`expr $m + 1`
	else
		l=`expr $m - 1`
	fi
done
echo 'size'
echo $e
