number = input().split()
num = '0123456789'

if (len(number) == 0 or len(number) > 1):
    print('Error')
else:
    good = True
    number = number[0]

    for i in range(len(number)):
        if (number[i] == ' '):
            number = number[:i]
            break

    for symbol in number:
        if (num.find(symbol) == -1):
            good = False
            break

    if (not good):
        print('Error')
    else:
        number = int(number)
        print(number)
