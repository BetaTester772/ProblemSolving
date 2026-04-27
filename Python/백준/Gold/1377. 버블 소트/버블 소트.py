import sys

N = int(input())
A = []
input = sys.stdin.readline
for i in range(N):
    A.append((int(input()), i))

A.sort(key=lambda x: x[0])

result = 0
for i in range(N):
    # print(A[i][1] - i)
    result = max(result, A[i][1] - i)

print(result + 1)
