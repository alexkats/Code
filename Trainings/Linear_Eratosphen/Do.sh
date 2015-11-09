if [ -f linear.out ]
then
    rm linear.out
fi

if g++ -o2 -Wall main.cpp -o main
then
    if ./main
    then
        for ((i = 0; i < 3; i++))
        do
            echo
        done

        echo Input:
        cat linear.in
        echo
        echo Output:
        cat linear.out
        rm linear.out

        for ((i = 0; i < 3; i++))
        do
            echo
        done
    fi

    rm main
else
    echo "Your program hasn't compiled"
fi
