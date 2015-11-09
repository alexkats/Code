tests = input().split()
num = '0123456789'

if (len(tests) == 0 or len(tests) > 1):
    print('Error')
else:
    good = True
    tests = tests[0]

    for i in range(len(tests)):
        if (tests[i] == ' '):
            tests = tests[:i]
            break

    for symbol in tests:
        if (num.find(symbol) == -1):
            good = False
            break

    if (not good):
        print('Error')
    else:
        tests = int(tests)
        print(tests)
