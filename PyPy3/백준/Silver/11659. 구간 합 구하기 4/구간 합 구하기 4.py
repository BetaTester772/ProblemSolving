import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
S = [0]

for i in range(N):
    S.append(S[i] + A[i])

# print(A)
# print(S)
for _ in range(M):
    i, j = map(int, input().split())
    print(S[j] - S[i - 1])
