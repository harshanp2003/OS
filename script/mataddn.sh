#!/bin/bash
 matrix1=()
 matrix2=()

 read -p "Enter the number of rows: " rows
 read -p "Enter the number of cols: " cols

 echo "Enter the first matrix"
 for((i=0; i<rows; i++))
 do
   for((j=0; j<cols; j++))
   do
    read ele
     matrix1+=($ele)
   done
 done

 echo

 echo "Enter the second matrix"
 for((i=0; i<rows; i++))
 do
   for((j=0; j<cols; j++))
   do
     read ele
     matrix2+=($ele)
   done
 done

 echo

 echo "First matrix"
 for((i=0; i<rows; i++))
 do
   for((j=0; j<cols; j++))
   do
    index=$((i*cols+j))                #We have used this formula coz the elements are stored in linear arrayfashion
      echo -n "${matrix1[index]} "
   done
   echo
 done

 echo "Second matrix"
 for((i=0; i<rows; i++))
 do
   for((j=0; j<cols; j++))
   do
     index=$((i*cols+j))
     echo -n "${matrix2[index]} "
   done
   echo
 done

 k=0
 matrix3=()
 for((i=0; i<rows; i++))
 do
   for((j=0; j<cols; j++))
   do
     index=$((i*cols+j))
     matrix3[k]=$((${matrix1[index]} + ${matrix2[index]}))
     k=$((k+1))
   done
 done

 echo "Addition of two matrix"
 for((i=0; i<rows; i++))
 do
   for((j=0; j<cols; j++))
   do
     index=$((i*cols+j))
     echo -n "${matrix3[index]} "
      done
   echo
 done
