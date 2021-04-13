!/usr/bin/env bash
stringa=$( ls )
dim=${#stringa}
i=0
j=1
start=0
lista=()
((dim-=1))
while [ ${i} -le ${dim} ]
do
    if [ -z ${stringa:${i}:1} ] || [ ${i} -eq ${dim} ] ;
    then
        lista+=(${stringa:${start}:((${i}-${start}))})
        j=0 ;
    elif [ ${j} -eq 0 ] ;
    then
        start=${i} ;
        j=1;
    fi
    ((i+=1))
done
nargs=${#lista[@]}
((nargs-=1))
stringa=""
while [ ${nargs} -ge 0 ] ;
do
    stringa+=${lista[${nargs}]} ;
    stringa+=" " ;
    ((nargs-=1))
done
echo ${stringa}

# Scrivere uno script che mostri il contenuto della cartella corrente in ordine inverso rispetto all’output generato da “ls” (che si può usare ma senza opzioni)
