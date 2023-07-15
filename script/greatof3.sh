#!/bin/bash
echo "Enter 3 numbers a,b,c"
read a b c
if [[ "$a" -gt "$b" && "$a" -gt "$c" ]];then
     echo "$a is greatest"
elif [[ "$b" -gt "$c" && "$b" -gt "$a" ]];then
     echo "$b is greatest"
elif [[ "$c" -gt "$b"  && "$c" -gt "$a" ]];then
      echo "$c  is greatest"
else
   echo "all are equal"
fi
