import sys

N, K = map(int, input().split())
A = []

for _ in range(N):
    A.append(int(sys.stdin.readline()))

num = 0
rst = 0

while num != K:
    for i in range(N - 1, -1, -1):
        if A[i] <= K - num:
            num += A[i]
            rst += 1
            break

print(rst)
