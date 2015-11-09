#!/bin/zsh

errors="Start"

while [[ $errors == "Error" ]] || [[ $errors == "Start" ]]
do
    if [[ $errors == "Error" ]]
    then
        echo "Wrong option"
    fi

    cat out_errors | python3 user_strings.py && ./read.sh | python3 check_errors.py > tmp
    read errors < tmp
done

while read line
do
    echo $line >> declaration
done < tmp

rm tmp
