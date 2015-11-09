name = input()
name = name.split('.')

if (len(name) == 1 or len(name) == 0 or len(name) > 2):
    print('Error')
else:
    name, extension = name[0], name[1]

    for i in range(len(extension)):
        if (extension[i] == ' '):
            extension = extension[:i]
            break

    if (extension != 'cpp' and extension != 'java' and extension != 'py'):
        print('Error')
    else:
        print(name)

        if (extension == 'cpp'):
            print('C++')
        elif (extension == 'java'):
            print('Java')
        else:
            print('Python')
