N, M = map(int, input().split())
alist = list(map(int, input().split()))

A = 0
result = 0

for i in range(N):
    A += alist[i]
    if A < 0:
        A = 0
    if A >= M:
        result += 1

print(result)
