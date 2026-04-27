# 플로이드-워셜

n, m, r = map(int, input().split())
items = list(map(int, input().split()))
distance = [[float('inf')] * (n + 1) for _ in range(n + 1)]

for _ in range(r):
    a, b, c = map(int, input().split())
    distance[a][b] = c
    distance[b][a] = c

for i in range(1, n + 1):
    distance[i][i] = 0


def floyd_washall():
    for mid in range(1, n + 1):
        for s in range(1, n + 1):
            for e in range(1, n + 1):
                if distance[s][e] > distance[s][mid] + distance[mid][e]:
                    distance[s][e] = distance[s][mid] + distance[mid][e]


floyd_washall()

result = 0
for i in range(1, n + 1):
    tmp = 0
    for j in range(1, n + 1):
        if distance[i][j] <= m:
            tmp += items[j - 1]
    result = max(tmp, result)

print(result)
