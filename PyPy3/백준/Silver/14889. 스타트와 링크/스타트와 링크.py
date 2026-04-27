from itertools import combinations

N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]

result = 1e9

comb = list(combinations(range(N), N // 2))
for c in comb[:len(comb) // 2]:
    A = list(c)
    B = list(set(range(N)).difference(set(c)))

    a = 0
    for i in A:
        for j in A:
            a += S[i][j]

    b = 0
    for i in B:
        for j in B:
            b += S[i][j]

    result = min(result, abs(a - b))

print(result)
