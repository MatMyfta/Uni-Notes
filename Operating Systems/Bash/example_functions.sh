# example_functions.sh

#!/bin/bash

# function function_name() {
#     <commands>
# }
# or
# function_name() {
#     <commands>
# }

function hello() {
    echo "Hello world function!"
}

hello           # calls the function
# you should not add the parenthesis when you
# call the function

# passing arguments work in the same way as passing
# arguments to a script
function hello1() {
    echo "Hello $1!"
}
hello matmyfta          # Hello matmyfta!

