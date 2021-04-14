# example_arguments.sh

#!/bin/bash

# !usage: ./example_arguments.sh arg1 arg2 arg3

echo "argument 1: $1"
echo "argument 2: $2"
echo "argument 3: $3"
# !example: ./example_arguments.sh bird cat dog
# argument 1: bird
# argument 2: cat
# argument 3: dog

# to reference all arguments, you can use $@
# to count all the arguments, you can use $#
echo "there are $# arguments: $@"
# !example: ./example_arguments.sh bird cat dog
# arguments: bird cat dog