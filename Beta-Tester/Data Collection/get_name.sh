#!/bin/zsh

name="Start"

while [[ $name == "Error" ]] || [[ $name == "Start" ]]
do
    if [[ $name == "Error" ]]
    then
        echo "Wrong extension of your program"
    fi

    cat out_name | python3 user_strings.py && ./read.sh | python3 check_name.py > tmp
    read name < tmp
done

if [[ -f declaration ]]
then
    rm declaration
fi

while read line
do
    echo $line >> declaration
done < tmp

rm tmp
