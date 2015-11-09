if [ -f 455.out ]
then
    rm 455.out
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
        cat 455.in
        echo
        echo Output:
        cat 455.out
        rm 455.out

        for ((i = 0; i < 3; i++))
        do
            echo
        done
    fi

    rm main
else
    echo "Your program hasn't compiled"
fi
