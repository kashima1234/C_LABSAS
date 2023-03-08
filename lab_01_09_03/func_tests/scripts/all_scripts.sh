
echo
echo -e "\t\t##### Tests have been completed #####"

#!/bin/bash

echo "##### Welcome to the testing system #####"
echo

if [ -f ./pos_tests.sh ]; then
    ./pos_tests.sh
fi

if [ -f ./neg_tests.sh ]; then
    ./neg_tests.sh
fi

echo
echo "##### Tests have been completed #####"
