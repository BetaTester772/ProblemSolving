T = int(input())

A = []
for _ in range(T):
    A.append(int(input()))

dp = [1, 2, 4]

for i in range(3, max(A) + 1):
    dp.append((dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009)

# print(dp)
for a in A:
    print(dp[a - 1])
