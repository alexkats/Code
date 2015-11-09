#!/bin/zsh

number="Start"

while [[ $number == "Error" ]] || [[ $number == "Start" ]]
do
    if [[ $number == "Error" ]]
    then
        echo "Wrong number of deleting test"
    fi

    cat out_delete_test | python3 user_strings.py && ./read.sh | python3 check_delete_test.py > tmp
    read number < tmp
done

while read line
do
    echo $line > deleting
done < tmp

rm tmp
