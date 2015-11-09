n = int(input())
i = 0
j = 0
curr = 1
fin = n * n
k = 0

a = [[0 for j in range(n)] for i in range(n)]

while 1:
    if (curr > fin):
        break

    a[i][j] = curr
    curr += 1

    if (k == 0 and j < (n - 1) and a[i][j + 1] == 0):
        j += 1
        continue
    elif (k == 0):
        i += 1

    if (k == 1 and i < (n - 1) and a[i + 1][j] == 0):
        i += 1
        continue
    elif (k == 1):
        j -= 1

    if (k == 2 and j > 0 and a[i][j - 1] == 0):
        j -= 1
        continue
    elif (k == 2):
        i -= 1

    if (k == 3 and i > 0 and a[i - 1][j] == 0):
        i -= 1
        continue
    elif (k == 3):
        j += 1

    k += 1
    k %= 4

for i in range(n):
    for j in range(n):
        print(a[i][j], end = ' ')

    print()
