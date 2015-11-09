#!/bin/zsh

for ((i = 0; i < 3; i++))
do
    echo
done

declare -i tests

if [[ -d Tests ]]
then
    echo -n "How many tests would you like to add: "
    read tests

    for ((i = 0; i < 3; i++))
    do
        read first_test
    done < declaration
else
    ((first_test = 0))

    for ((i = 0; i < 3; i++))
    do
        read tests
    done < declaration

    mkdir Tests
fi

declare -a test_lines
declare -a test_output
declare -i first_test

for ((i = first_test + 1; i <= tests + first_test; i++))
do
    echo -n "How many lines will there be in Test #"$i": "
    declare -i x
    read x
    ((size = 0))

    for ((j = 0; j < x; j++))
    do
        read line
        test_lines[size+1]=$line
        ((size++))
    done

    for ((j = 0; j < size; j++))
    do
        echo ${test_lines[j+1]}
    done > Tests/$i".in"

    echo -n "How many lines will there be in correct answer for Test #"$i": "
    declare -i x
    read x
    ((size = 0))

    for ((j = 0; j < x; j++))
    do
        read line
        test_output[size+1]=$line
        ((size++))
    done

    for ((j = 0; j < size; j++))
    do
        echo ${test_output[j+1]}
    done > Tests/$i".out"
done

if ((first_test == 0))
then
    exit
fi

for ((i = 0; i < 2; i++))
do
    read t
    echo $t >> tmp
done < declaration

((tests = tests + first_test))
echo $tests >> tmp

for ((i = 0; i < 6; i++))
do
    read t

    if ((i > 2))
    then
        echo $t >> tmp
    fi
done < declaration

rm declaration

while read line
do
    echo $line >> declaration
done < tmp

rm tmp
