read i
n=0
sum=0
while [ $n -le $i ]
do
	sum=`expr $sum + $n`
	n=`expr $n + 1`
done
echo $sum
