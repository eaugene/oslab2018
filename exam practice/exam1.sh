wc -l $1
wc -w $1
wc -c $1
grep -o -n '[a,e,i,o,u]' $1 | wc -l
grep -o -n '[^a,e,i,o,u]' $1 | wc -l
grep -o -n '[0-9]' $1 | wc -l
grep -o -n '[^a-zA-Z0-9 ]' $1|wc -l
