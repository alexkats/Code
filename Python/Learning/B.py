a = [4, 6, 1, 2, 5, 3]
b = [int(i) for i in input().split()]

def lcs(x, y):
    ans = [[0 for j in range(len(x))] for i in range(len(y))]

    for i in range(len(x)):
        for j in range(len(y)):
            if (x[i] == y[j]):
                if (i == 0 or j == 0):
                    ans[i][j] = 1
                else:
                    ans[i][j] = ans[i - 1][j - 1] + 1
            else:
                if (i == 0 and j == 0):
                    ans[i][j] = 0
                else:
                    if (i == 0):
                        ans[i][j] = ans[i][j - 1]
                    elif (j == 0):
                        ans[i][j] = ans[i - 1][j]
                    else:
                        ans[i][j] = max(ans[i - 1][j], ans[i][j - 1])

    return ans[len(x) - 1][len(y) - 1]

print(lcs(a, b))
