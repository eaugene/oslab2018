if [ $2 = '+' ];then
	s=$(( $1 + $3 ));
	echo $s
elif [ $2 = '-' ];then
	s=$(( $1 - $3 ));
	echo $s;
fi
