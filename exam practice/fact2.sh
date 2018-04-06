fact()
{
	if [ $1 -le 0 ];then
		echo 1
	else
		f=$(( $1 - 1 ))
		f=$( fact $f )
		f=$(( $1 * $f ))
		echo $f
	fi
}
ens=$( fact $1 )
echo $ens
