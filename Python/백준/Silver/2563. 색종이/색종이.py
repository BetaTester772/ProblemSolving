T = int(input())
fig = [[0] * 101 for _ in range(102)]
nlist = []

for _ in range(T):
    nlist.append(tuple(map(int, input().split())))

for x, y in nlist:
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            fig[i][j] = 1

n = 0
for i in range(101):
    for j in range(101):
        n += fig[i][j]

print(n)
