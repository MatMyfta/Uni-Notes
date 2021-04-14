# example_if_conditionals.sh

# if [ some_test ]
# then
#   <commands>
# else
#   <commands>
# fi

#!/bin/bash

read -p "Insert your name: " name
if [ -z ${name} ]
then
    echo "Name not inserted!"
else
    echo "Hi ${name}"
fi

admin="matmyfta"
read -p "Insert username: " username
# check if the username provided is the admin
if [[ ${username} == ${admin} ]]
then
    echo "welcome admin"
else
    echo "you are not an admin"
fi

# this example checks your current User ID and would
# not allow you to run the script as the root user
# if you put it on top of the script.
if [ $EUID == 0 ];
then
    echo "Please do not run as root"
    exit
fi