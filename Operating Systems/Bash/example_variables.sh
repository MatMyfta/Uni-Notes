# example_variables.sh

#!/bin/bash

# there are not types, and variables can contain strings a-
# nd numbers.
# to assign a value to a variable only the = sign is needed
name="string"

# to access the variable, $ sign is needed to reference to
# it
echo $name              # reference to name variable
echo ${name}            # brackets are a good practice
echo "name: ${name}"    # reference in a string

