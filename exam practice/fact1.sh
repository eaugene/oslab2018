fact()

{

	i=$1
	if [ $i -eq 0 -o $i -eq 1 ]
	then
		echo 1
	else
		f=`expr $i \- 1`
		f=$(fact $f)
		f=`expr $i \* $f`
		echo $f
	fi
}

read -p "Enter the number : " n

if [ $n -lt 0 ]

then

	echo "ERROR"

else

	echo "THE FACTORIAL OF $n : $(fact $n) "
fi

