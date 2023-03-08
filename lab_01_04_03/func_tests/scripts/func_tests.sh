#!/bin/bash

echo
echo "NEGATIVE TESTS"
echo
    touch ../../func_tests/data/out.txt

for file in neg_??_in.txt
do
    ./neg_tests.sh "$file"
done

echo 
echo "POSITIVE TESTS"
echo 

for file in pos_??_in.txt
do
    ./pos_tests.sh "$file"
done
