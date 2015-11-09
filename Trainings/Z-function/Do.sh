if [ -f zfunc.out ]
then
    rm zfunc.out
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
        cat zfunc.in
        echo
        echo Output:
        cat zfunc.out
        rm zfunc.out

        for ((i = 0; i < 3; i++))
        do
            echo
        done
    fi

    rm main
else
    echo "Your program hasn't compiled"
fi
