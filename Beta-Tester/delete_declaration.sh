#!/bin/zsh

cd Data\ Collection
read s < delete_declaration

if [[ $s == "n" ]]
then
    s="y"
else
    s="n"
fi

echo $s > delete_declaration
cd ..
