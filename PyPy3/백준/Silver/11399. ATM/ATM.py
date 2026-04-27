N = int(input())

P = list(map(int, input().split()))

P.sort()

S = [0]

for i in range(N):
    S.append(S[i] + P[i])

print(sum(S))
