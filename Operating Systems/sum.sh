# insert a set of number until an empty value is inserted
# then compute the average value

#!/bin/bash

alias sum='(var="."; datas=0;
while [[ ! -z "$var" ]]; do
echo "insert number (empty to finish): "; read var; 
$datas = "$datas+$var";
done;
echo "sum is: $(( $datas )) )'