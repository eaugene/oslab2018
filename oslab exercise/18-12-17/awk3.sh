echo "December has christmas">test7.txt
echo "January has new year">>test7.txt
awk '{print} /christmas/{print "on 25th"}' test7.txt
