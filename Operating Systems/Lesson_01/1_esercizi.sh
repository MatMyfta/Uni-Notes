#!/usr/bin/env bash

# Stampa “T” (per True) o “F” (per False) a seconda che il valore rappresenti un file o cartella esistente

alias isfile='read objectname ; if [[ -f ${objectname} ]] ; then echo "T" ; elif [[ -d ${objectname} ]] ; then echo "F" ; fi'

# Stampa “file”, “cartella” o “?” a seconda che il valore rappresenti un file (esistente), una cartella (esistente) o una voce non presente nel file-system

alias defineobject='read objectname ; if [[ -f ${objectname} ]] ; then echo "file" ; elif [[ -d ${objectname} ]] ; then echo "cartella" ; elif [[ ! -a ${objectname} ]] ; then  echo "?" ; fi'

# Stampa il risultato di una semplice operazione aritmetica contenuta nel file indicato dal valore oppure “?” se il file non esiste

alias evaluate='read filename ; if [ -f ${filename} ] ; then echo $(( $(<${filename}) )) ; else echo "?" ; fi'

# echo $(( $(<${filename}) )) equivalente a echo $(( $(cat ${filename}) ))
# alias evaluate='read filename ; if [ -f ${filename} ] ; then testo=$(<${filename}) ; echo $(( ${testo} )) ; else echo "?" ; fi'
