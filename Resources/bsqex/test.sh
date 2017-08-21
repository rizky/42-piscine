make re
x=$(( ( RANDOM % 10 )  + 100 ))
y=$(( ( RANDOM % 10 )  + 100 ))
perl create_map.perl $x $y 2 > test
echo LA MAP GENEREE
cat test
echo LE RESULT
./bsq test