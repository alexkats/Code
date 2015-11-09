time = input().split()

if (len(time) == 0 or len(time) > 1):
    print('Error')
else:
    time = time[0]

    for i in range(len(time)):
        if (time[i] == ' '):
            time = time[:i]
            break

    time = time.lower()

    if (time[0] == 'y'):
        if (time == 'y' or time == 'yes'):
            print('yes')
        else:
            print('Error')
    elif (time[0] == 'n'):
        if (time == 'n' or time == 'no'):
            print('no')
        else:
            print('Error')
    else:
        print('Error')
