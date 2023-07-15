#!/bin/bash
echo "Enter the number"
read n
n1=$n
rev=0
while [[ "$n" -gt 0 ]]
do
  rem=$((n%10))
  rev1=$((rev*10))
  rev=$((rev1+rem))
  n=$((n/10))
done
echo "$rev is the number"

if [[ "$n1" = "$rev" ]];then
  echo "The number is palindrome"
else
  echo "The number is not a palindrome"
fi
