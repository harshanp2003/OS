#!/bin/bash
echo "Enter the value of n1 and n2"
read n1 n2
flag=0
echo "The prime numbers in the given range are"
if [[ "$n1" -gt 1 ]];then
for ((i=$n1;i<=$n2;i++))
do
    for ((j=2;j<=$((i/2));j++))
    do
       if [[ $((i%j)) == 0 ]]
       then
            flag=1
       break
       fi
    done
   if [[ "$flag" = 0 ]]
   then
    echo "$i"
   fi
   flag=0
done
else
   echo "No printing because n1 is 1"
fi
