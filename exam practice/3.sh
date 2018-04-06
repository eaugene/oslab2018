read str
l=${#str}
carr=()
for ((w=0;w<26;w++));
do
	carr[$w]=0
done
declare -p carr
i=0
while [ $i -lt $l ]
do
	s=${str:$i:1}
	i=$(( i + 1 ))
	v=$(echo $s|od -N 1 -i|head -1|tr -s ' '|cut -d ' ' -f 2)
	v=$(( v - 97 ))
	w=${carr[$v]}
	w=$(( w + 1 ))
	carr[$v]=$w
done
for((w=0;w<26;w++));
do
	if [ ${carr[$w]} -gt 0 ];then
		e=$(( w + 97 ))
		g=$(echo $e | awk '{ printf("%c",$0); }')
		echo $g "---" ${carr[$w]}
	fi
done
