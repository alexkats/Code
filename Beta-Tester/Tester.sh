#!/bin/zsh

good_string="MacBook-Pro-Aleksej% "

for ((i = 0; i < 3; i++))
do
    echo
done

cd Data\ Collection

if [[ -f delete_declaration ]]
then
    read delete_declaration < delete_declaration
else
    delete_declaration="n"
fi

if [[ $delete_declaration == "y" ]]
then
    rm declaration
fi

if ! [[ -f declaration ]]
then
    echo "n" > adding_tests
    echo "n" > own_checker
    echo "n" > delete_declaration
    echo "Collecting data:"
    ./get_name.sh
    ./get_tests.sh
    ./get_limit.sh
    ./get_errors.sh
    ./get_time.sh
    echo "Data collected successfully!"
    sleep 1.3
    clear
    echo $good_string

    for ((i = 0; i < 3; i++))
    do
        echo
    done
fi

read par < ../adding

if ! [[ -d Tests ]] || [[ $par == "y" ]]
then
    echo "Adding tests:"
    ./add_tests.sh
    echo "All tests added successfully!"
    sleep 1.3
    clear
    echo $good_string

    for ((i = 0; i < 3; i++))
    do
        echo
    done
fi

exit

name=""
language=""
declare -i tests
limit=""
declare -i ignore
declare -i time

for ((i = 0; i < 6; i++))
do
    read x

    if ((i == 0))
    then
        name=$x
        continue
    fi

    if ((i == 1))
    then
        language=$x
        continue
    fi

    if ((i == 2))
    then
        tests=$x
        continue
    fi

    if ((i == 3))
    then
        limit=$x
        continue
    fi

    if ((i == 4))
    then
        if [[ $x == "yes" ]]
        then
            ((ignore = 1))
        else
            ((ignore = 0))
        fi
    
        continue
    fi

    if ((i == 5))
    then
        if [[ $x == "yes" ]]
        then
            ((time = 1))
        else
            ((time = 0))
        fi

        continue
    fi
done < declaration

if [[ -f error ]]
then
    rm error
fi

if [[ $language == "C++" ]]
then
    if ! [[ g++ -o2 -Wall -std=c++11 $name".cpp" -o $name ]]
    then
        clear
        echo $good_string

        for ((i = 0; i < 3; i++))
        do
            echo
        done

        g++ -o2 -Wall -std=c++11 $name".cpp" -o $name 2>error
        echo "Your program hasn't compiled!"

        for ((i = 0; i < 3; i++))
        do
            echo
        done
        
        exit
    fi
fi

if [[ $language == "Java" ]]
then
    if ! [[ javac $name".java" ]]
    then
        clear
        echo $good_string

        for ((i = 0; i < 3; i++))
        do
            echo
        done

        javac $name".java" 2>error
        echo "Your program hasn't compiled!"

        for ((i = 0; i < 3; i++))
        do
            echo
        done

        exit
    fi
fi

echo "Good program! It has compiled! (Or it's just a python)"
sleep 0.8
clear
echo $good_string

for ((i = 0; i < 3; i++))
do
    echo
done

read own_checker < Data\ Collection/own_checker

if [[ $language == "C++" ]]
then
    cd Data\ Collection/Tests

    for ((num = 1; num <= tests; num++))
    do
        cp $num".in" ../../$name".in"

        if ! [[ ./$name ]]
        then
            if ((ignore == 1))
            then
                verdicts[num]="RE"
            else
                clear
                echo $good_string

                for ((i = 0; i < 3; i++))
                do
                    echo
                done

                ./$name  2>error
                echo "Runtime error on test #$num!"

                for ((i = 0; i < 3; i++))
                do
                    echo
                done

                exit
            fi
        fi
    done

    cd ../..
fi

if [[ $language == "Java" ]]
then
    cd Data\ Collection/Tests

    for ((num = 1; num <= tests; num++))
    do
        cp $num".in" ../../$name".in"

        if ! [[ java $name ]]
        then
            if ((ignore == 1))
            then
                verdicts[num]="RE"
            else
                clear
                echo $good_string

                for ((i = 0; i < 3; i++))
                do
                    echo
                done

                java $name 2>error
                echo "Runtime error on test #$num!"

                for ((i = 0; i < 3; i++))
                do
                    echo
                done

                exit
            fi
        fi
    done

    cd ../..
fi

if [[ $language == "Python" ]]
then
    cd Data\ Collection/Tests

    for ((num = 1; num <= tests; num++))
    do
        cp $num".in" ../../$name".in"

        if ! [[ python3 $name".py" ]]
        then
            if ((ignore == 1))
            then
                verdicts[num]="RE"
            else
                clear
                echo $good_string

                for ((i = 0; i < 3; i++))
                do
                    echo
                done

                python3 $name".py" 2>error
                echo "Runtime error on test #$num!"

                for ((i = 0; i < 3; i++))
                do
                    echo
                done

                exit
            fi
        fi
    done

    cd ../..
fi

if [[ own == "n" ]]
then
    cat aaa | python3 standart_checker.py | read verdict

    if [[ verdict == "OK" ]]
    then
        echo "OK"
        exit
    fi
fi
