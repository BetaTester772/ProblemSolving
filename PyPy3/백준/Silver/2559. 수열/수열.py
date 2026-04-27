import sys

input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))
S = [0]

for i in range(N):
    S.append(S[i] + A[i])

sums = []

for i in range(N - K + 1):
    # print(S[i+K]-S[i])
    sums.append(S[i + K] - S[i])

print(max(sums))
