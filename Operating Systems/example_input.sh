# example_input.sh

#!/bin/bash

echo "Insert your name"
read name

echo "Hi ${name}"

# to reduce the code we can use the -p flag to the read
# statement
read -p "Insert your name: " name
echo "Hi ${name}"