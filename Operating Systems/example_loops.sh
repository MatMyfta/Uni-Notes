# example_loops.sh

#!/bin/bash

# for var in ${list}
# do
#     <commands>
# done

# this may work even if users was defined as
# users=("mat" "myfta" "matmyfta")
users="mat myfta matmyfta"
for user in ${users}
do
    echo "${user}"
done

# you can also use for to process series of numbers
for num in {1..10}
do
    echo ${num}
done

# while [ condition ]
# do 
#     <commands>
# done

counter=1
while [[ $counter -le 10 ]] # while counter <= 10
do
    echo $counter           # print the counter
    (( counter++ ))         # increment the counter
done

# until [ condition ]
# do
#    <commands>
# done

# the difference between until and while loops is that
# until loop will run the commands within the loop
# until the condition becomes true

count=1
until [ $count -gt 10 ]
do
    echo $count
    (( count++ ))
done