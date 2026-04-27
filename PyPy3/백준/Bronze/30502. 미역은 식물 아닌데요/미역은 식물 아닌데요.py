n, m = map(int, input().split())

P = [None for _ in range(n)]
M = [None for _ in range(n)]

for _ in range(m):
    a, b, c = input().split()
    a = int(a) - 1
    if c == '1':
        c = True
    else:
        c = False

    if b == 'P':
        P[a] = c
    else:
        M[a] = c

# print(P)
# print(M)

Min = 0
Max = 0

for i in range(n):
    p, m = P[i], M[i]
    if p == True and m is None:
        Max += 1
    elif p == False and m is None:
        pass
    elif p is None and m == True:
        pass
    elif p is None and m == False:
        Max += 1
    elif p is None and m is False:
        Max += 1
    elif p == True and m == True:
        pass
    elif p == False and m == True:
        pass
    elif p == False and m == False:
        pass
    elif p == True and m == False:
        Max += 1
        Min += 1
    elif p is None and m is None:
        Max += 1
    else:
        raise ValueError

print(Min, Max)
