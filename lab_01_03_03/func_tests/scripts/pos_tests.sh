
#!/bin/bash

main_func() {
    echo -e "\tPositive Tests:"
    echo

    green_col=$'\e[32mPASSED\e[0m' # green color
    red_col=$'\e[31mFAILED\e[0m' # red color
	touch ../../func_tests/data/out.txt

    for num in {1..5}; do
        if [[ -e "../data/pos_0${num}_in.txt" ]]; then
            echo "TEST $(printf %02d $num):"

            ../../a.out< ../data/pos_0${num}_in.txt > ../data/out.txt

            rc=$?

            if diff -Z "../data/pos_0${num}_out.txt" "../data/out.txt" && [ $rc -eq 0 ]; then 
                echo "pos_$(printf %02d $num).txt: ${green_col}"
            else
                echo "pos_$(printf %02d $num).txt: ${red_col}"
            fi

        fi
    done
}

main_func
rm ../data/out.txt
