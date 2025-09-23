n = int(input())
m = int(input())
INF = float('inf')
distance = [[INF for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    distance[a][b] = min(distance[a][b], c)


def floid_warshall():
    for m in range(1, n + 1):
        for s in range(1, n + 1):
            for e in range(1, n + 1):
                distance[s][e] = min(distance[s][e], distance[s][m] + distance[m][e])


floid_warshall()

for i in range(1, n + 1):
    for j in range(1, n + 1):
        print(distance[i][j] if distance[i][j] != INF else 0, end=' ')
    print()
