q1 = int(input())
s1 = []

for i in range(q1):
    s1.append(input())

q2 = int(input())
s2 = []

for i in range(q2):
    s2.append(input())

if (q1 != q2):
    print('WA')
else:
    for i in range(q1):
        s = s1[i]
        t = s2[i]

        if (t != s):
            print('WA')
            break
    else:
        print('OK')
