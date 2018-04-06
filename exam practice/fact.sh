read n
 fact()
 {
	 
	 if [ $1 = 1 ];
	 then
		 echo 1
	 else
		 f=`expr $1 \- 1`
		 f=$(fact $f)
		 f=`expr $1 \* $f`
		 echo $f
	 fi
 }

 ans=$(fact $n)
 echo $ans
		 

