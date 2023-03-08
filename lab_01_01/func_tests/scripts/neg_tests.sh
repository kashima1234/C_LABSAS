
#!/bin/bash

main_func() {
    echo -e "\tNegtive Tests:"
    echo

    green_col=$'\e[32mPASSED\e[0m' # green color
    red_col=$'\e[31mFAILED\e[0m' # red color
        touch ../../func_tests/data/out.txt

    for num in {1..2}; do
        if [[ -e "../data/neg_0${num}_in.txt" ]]; then
            echo "TEST $(printf %02d $num):"

            ../../app.exe < ../data/neg_0${num}_in.txt > ../data/out.txt

            rc=$?

            if diff -Z "../data/neg_0${num}_out.txt" "../data/out.txt" && [ $rc -eq 0 ]; then
                echo "neg_$(printf %02d $num).txt: ${green_col}"
            else
                echo "neg_$(printf %02d $num).txt: ${red_col}"
            fi

        fi
    done
}

main_func
rm ../data/out.txt

