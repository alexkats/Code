#!/bin/zsh

time="Start"

while [[ $time == "Error" ]] || [[ $time == "Start" ]]
do
    if [[ $time == "Error" ]]
    then
        echo "Wrong option"
    fi

    cat out_time | python3 user_strings.py && ./read.sh | python3 check_time.py > tmp
    read time < tmp
done

while read line
do
    echo $line >> declaration
done < tmp

rm tmp
