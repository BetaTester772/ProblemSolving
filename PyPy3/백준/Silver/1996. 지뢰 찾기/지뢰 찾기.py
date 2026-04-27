N = int(input())

A = []
for i in range(N):
    A.append(list(input()))

B = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if A[i][j].isdigit():
            a = int(A[i][j])
            B[i][j] = '*'
            if i - 1 >= 0 and B[i - 1][j] != '*':
                B[i - 1][j] += a
            if i + 1 < N and B[i + 1][j] != '*':
                B[i + 1][j] += a
            if j - 1 >= 0 and B[i][j - 1] != '*':
                B[i][j - 1] += a
            if j + 1 < N and B[i][j + 1] != '*':
                B[i][j + 1] += a
            if i - 1 >= 0 and j - 1 >= 0 and B[i - 1][j - 1] != '*':
                B[i - 1][j - 1] += a
            if i - 1 >= 0 and j + 1 < N and B[i - 1][j + 1] != '*':
                B[i - 1][j + 1] += a
            if i + 1 < N and j - 1 >= 0 and B[i + 1][j - 1] != '*':
                B[i + 1][j - 1] += a
            if i + 1 < N and j + 1 < N and B[i + 1][j + 1] != '*':
                B[i + 1][j + 1] += a

for i in range(N):
    for j in range(N):
        if B[i][j] != '*' and B[i][j] >= 10:
            print('M', end='')
        else:
            print(B[i][j], end='')
    print()
