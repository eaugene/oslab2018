read str
l=${#str}
for(( i=0;i<l;i++ ))
do
	v=${str:$i:1}
	echo $v
	echo " "
done
