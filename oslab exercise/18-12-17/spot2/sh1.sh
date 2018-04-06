awk 'BEGIN{print "sum " "dif " "mul"} {print $1+$2 " " $1-$2 " " $1*$2 }' smple.txt>out.txt
