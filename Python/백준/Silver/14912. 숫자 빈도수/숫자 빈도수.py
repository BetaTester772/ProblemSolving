n, d = map(int, input().split())

N = 0

for i in range(1, n + 1):
    if i >= 100000 and i // 100000 == d:
        N += 1
    if i >= 10000 and i // 10000 - i // 100000 * 10 == d:
        N += 1
    if i >= 1000 and i // 1000 - i // 10000 * 10 == d:
        N += 1
    if i >= 100 and i // 100 - i // 1000 * 10 == d:
        N += 1
    if i >= 10 and i // 10 - i // 100 * 10 == d:
        N += 1
    if i >= 1 and i // 1 - i // 10 * 10 == d:
        N += 1

print(N)
