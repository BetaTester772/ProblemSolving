N = int(input())

T = [[0] * 8 for _ in range(N)] # index starts from 0
T[0][3] = 1
T[0][6] = 1
T[0][0] = 1

for i in range(1, N):
    T[i][0] = T[i - 1][7]
    T[i][1] = T[i - 1][6]
    T[i][2] = T[i - 1][5]
    T[i][3] = T[i - 1][4] + T[i - 1][7]
    T[i][4] = T[i - 1][3]
    T[i][5] = T[i - 1][2]
    T[i][6] = T[i - 1][1] + T[i - 1][7]
    T[i][7] = T[i - 1][0] + T[i - 1][3] + T[i - 1][6]

print(T[N - 1][7] if N % 2 == 0 else 0)
