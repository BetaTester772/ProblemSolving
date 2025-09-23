n, m = map(int, input().split())

A = []

for _ in range(n):
    S = input().split()
    a = []
    for s in S:
        a.append(s.count('9'))
    A.append(a)

max_count = 0
total_count = 0
for i in range(n):
    for j in range(m):
        total_count += A[i][j]
        count = 0
        for k in range(n):
            count += A[k][j]
        max_count = max(max_count, count)

        count = 0
        for k in range(m):
            count += A[i][k]
        max_count = max(max_count, count)

print(total_count - max_count)
