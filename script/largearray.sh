#!/bin/bash
echo "Enter the number of elements"
read n
echo "Enter the elements"
a=()
for ((i=0;i<$n;i++))
do
    read ele
    a+=($ele)
done
large=${a[0]}
#echo "$large"
for ((i=1;i<$n;i++))

do
    if [[ ${a[i]} -gt  $large ]]
    then
       large=${a[i]}
    fi

done
echo "$large is the biggest element"
