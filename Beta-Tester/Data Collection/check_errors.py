errors = input().split()

if (len(errors) == 0 or len(errors) > 1):
    print('Error')
else:
    errors = errors[0]

    for i in range(len(errors)):
        if (errors[i] == ' '):
            errors = errors[:i]
            break

    errors = errors.lower()

    if (errors[0] == 'y'):
        if (errors == 'y' or errors == 'yes'):
            print('yes')
        else:
            print('Error')
    elif (errors[0] == 'n'):
        if (errors == 'n' or errors == 'no'):
            print('no')
        else:
            print('Error')
    else:
        print('Error')
