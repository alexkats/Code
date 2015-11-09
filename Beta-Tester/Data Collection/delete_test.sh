#!/bin/zsh

for ((i = 0; i < 3; i++))
do
    echo
done

./get_delete_test.sh
declare -i number
read number < deleting
rm deleting

for ((i = 0; i < 3; i++))
do
    read all
done < declaration

if ((number > all)) || ((number < 1))
then
    echo "Wrong number of deleting test"
    
    for ((i = 0; i < 3; i++))
    do
        echo
    done

    exit
fi

cd Tests

rm $number".in"
rm $number".out"

for ((i = number; i < all; i++))
do
    ((j = i + 1))
    mv $j".in" $i".in"
    mv $j".out" $i".out"
done

cd ..

for ((i = 0; i < 2; i++))
do
    read t
    echo $t >> tmp
done < declaration

((all--))
echo $all >> tmp

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

echo "Test #$number was successfully deleted!"

for ((i = 0; i < 3; i++))
do
    echo
done
