N, K = map(int, input().split())
M = K * (K + 1) // 2
# print(M)

if N < M:
    print(-1)
    exit()

A = []
for i in range(K, 0, -1):
    A.append(i)
# print(A)

L = N - sum(A)
# print(L)
while L > 0:
    for i in range(K):
        L -= 1
        A[i] += 1
        # print(A)
        if L == 0:
            break

print(A[0] - A[-1])
