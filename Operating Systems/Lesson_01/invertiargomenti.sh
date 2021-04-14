#!/usr/bin/env bash
nargs=$#
args=("$@")
((nargs-=1))
while [ ${nargs} -ge 0 ]
do
    echo ${args[${nargs}]};
    ((nargs-=1))
done

# Scrivere uno script che dato un qualunque numero di argomenti li restituisca in output in ordine inverso
