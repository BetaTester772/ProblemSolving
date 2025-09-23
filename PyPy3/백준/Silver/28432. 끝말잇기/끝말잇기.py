S = []
A = []

N = int(input())
for _ in range(N):
    S.append(input())

M = int(input())
for _ in range(M):
    A.append(input())

index = S.index('?')

for a in A:
    if a in S:
        continue
    if len(S) == 1:
        print(a)
        exit()
    if index == 0 and len(S) > 1:
        if a[-1] == S[index + 1][0]:
            print(a)
            exit()
    elif index == N - 1:
        if a[0] == S[index - 1][-1]:
            print(a)
            exit()
    elif 0 < index < N - 1:
        if a[0] == S[index - 1][-1] and a[-1] == S[index + 1][0]:
            print(a)
            exit()
