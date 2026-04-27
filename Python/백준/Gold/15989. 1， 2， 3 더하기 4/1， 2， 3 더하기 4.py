T = int(input())
A = []
for _ in range(T):
    A.append(int(input()))

dp = [[1, 0, 0], [1, 1, 0], [1, 1, 1]]
for i in range(3, max(A)):
    dp.append([dp[i - 1][0], dp[i - 2][0] + dp[i - 2][1], dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2]])

for a in A:
    print(sum(dp[a - 1]))
