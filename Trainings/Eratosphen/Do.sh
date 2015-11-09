if [ -f eratosphen.out ]
then
    rm eratosphen.out
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
        cat eratosphen.in
        echo
        echo Output:
        cat eratosphen.out
        rm eratosphen.out

        for ((i = 0; i < 3; i++))
        do
            echo
        done
    fi

    rm main
else
    echo "Your program hasn't compiled"
fi
