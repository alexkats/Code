#!/bin/zsh

tests="Start"

while [[ $tests == "Error" ]] || [[ $tests == "Start" ]]
do
    if [[ $tests == "Error" ]]
    then
        echo "Wrong number of tests"
    fi

    cat out_tests | python3 user_strings.py && ./read.sh | python3 check_tests.py > tmp
    read tests < tmp
done

while read line
do
    echo $line >> declaration
done < tmp

rm tmp
