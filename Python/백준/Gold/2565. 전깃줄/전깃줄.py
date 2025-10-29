N = int(input())

A = []

for _ in range(N):
    a, b = map(int, input().split())
    A.append((a, b))

A.sort()
dp = [1] * N

for i in range(N):
    for j in range(i):
        if A[i][1] > A[j][1]:
            dp[i] = max(dp[i], dp[j] + 1)

print(N - max(dp))
