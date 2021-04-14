# example_arrays.sh

#!/bin/bash

# you can initialize an array by assigninf values di-
# vided by space and enclosed in ().
# to access elements in the array, you need to refer-
# ence them by their numeric index
my_array=("value1" "value2" "value3" "value4")
echo ${my_array[1]}         # value2
echo ${my_array[-1]}        # value4
echo ${my_array[@]}         # all arguments
echo ${#my_array[@]}        # 4

