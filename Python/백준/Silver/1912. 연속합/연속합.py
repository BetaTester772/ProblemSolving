n = int(input())
A = list(map(int, input().split()))

dp = [A[0]]
for i in range(1, len(A)):
    dp.append(max(A[i], A[i] + dp[i - 1]))

print(max(dp))
