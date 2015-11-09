#!/bin/zsh

cd Data\ Collection
read s < adding_tests

if [[ $s == "n" ]]
then
    s="y"
else
    s="n"
fi

echo $s > adding_tests
cd ..
