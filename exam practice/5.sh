read -a arr
read f
l=${#arr[@]}
s=0
while [ $s -lt $l ]
do
	m=$(( $s + $l ))
	m=$(( $m / 2))
	if [ ${arr[$m]} = $f ];then
		echo $m
		break
	elif [ ${arr[$m]} -lt $f ];then
		s=$(( $m + 1 ))
	else
		l=$(( $m - 1 ))
	fi
done

