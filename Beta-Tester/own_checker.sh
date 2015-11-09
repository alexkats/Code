#!/bin/zsh

cd Data\ Collection
read s < own_checker

if [[ $s == "n" ]]
then
    s="y"
else
    s="n"
fi

echo $s > own_checker
cd ..
