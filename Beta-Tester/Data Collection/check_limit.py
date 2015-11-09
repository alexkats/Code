time = input().split()
num = '0123456789.'

if (len(time) == 0 or len(time) > 1):
    print('Error')
else:
    good = True
    time = time[0]

    for i in range(len(time)):
        if (time[i] == ' '):
            time = time[:i]
            break

    for symbol in time:
        if (num.find(symbol) == -1):
            good = False
            break

    q = 0

    for symbol in time:
        if (symbol == '.'):
            q += 1

        if (q > 1):
            good = False
            break

    if (not good):
        print('Error')
    else:
        time = float(time)
        print(time)
