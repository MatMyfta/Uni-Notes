# example_conditional_expressions.sh

#!/bin/bash

# conditional expressions are used by the [[ ]] comma-
# nd, and the built-in commands to test file attribut-
# es and perform string and arithmetic comparisons.

# -- File expressions
# return false if file does not exist
[[ -a ${file} ]]        # true if file exists
[[ -b ${file} ]]        # true if is a block special file
[[ -c ${file} ]]        # true if is a character special file
[[ -d ${file} ]]        # true if directory exists
[[ -e ${file} ]]        # true if file exists
[[ -f ${file} ]]        # true if is a regular file
[[ -h ${file} ]]        # true if is a symbolic link
[[ -r ${file} ]]        # true if is a readable file
[[ -s ${file} ]]        # true if has a size > 0
[[ -w ${file} ]]        # true if is writable
[[ -x ${file} ]]        # true if is executable
[[ -L ${file} ]]        # true if is a symbolic link

# -- String expressions
[[ -v ${varname} ]]     # true if shell variable name is set
[[ -z ${string} ]]      # true if length == 0
[[ -n ${string} ]]      # true if length != 0
[[ ${s1} == ${s2} ]]    # true if strings are equal
[[ ${s1} < ${s2} ]]     # true if s1 sorts before s2
[[ ${s1} > ${s2} ]]     # true if s2 sorts before s1

# -- Arithmetic operators
[[ ${arg1} -eq ${arg2} ]]   # true if numbers are equal
[[ ${arg1} -ne ${arg2} ]]   # true if are not equal
[[ ${arg1} -lt ${arg2} ]]   # true if arg1 < arg2
[[ ${arg1} -le ${arg2} ]]   # true if arg1 <= arg2
[[ ${arg1} -gt ${arg2} ]]   # true if arg1 > arg2
[[ ${arg1} -ge ${arg2} ]]   # true if arg1 >= arg2

# it is possible to use AND & OR conditions
[[ test_case_1 ]] && [[ test_case_2]]   # and
[[ test_case_1 ]] || [[ test_case_2]]   # or