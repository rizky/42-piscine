echo "# $FT_NBR1 + $FT_NBR2" | tr "'" '0' | tr '\\"?!' '1234' | tr 'mrdoc' '01234' | sed 's/#/obase=13\;ibase=5\;/' 
