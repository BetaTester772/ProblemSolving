N = int(input())
A = list(map(int, input().split()))
S = [0]

for i in range(N):
    S.append(S[i] + A[i])

M = int(input())
for _ in range(M):
    i, j = map(int, input().split())
    print(S[j] - S[i - 1])
