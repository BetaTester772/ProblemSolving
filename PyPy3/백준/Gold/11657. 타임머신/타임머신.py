N, M = map(int, input().split())

INF = float('inf')
Edge = []

for _ in range(M):
    A, B, C = map(int, input().split())
    Edge.append((A, B, C))


def bellman_ford(start, Edge, distance):
    distance[start] = 0

    for i in range(1, N + 1):
        for j in range(M):
            r, v, w = Edge[j]

            if distance[r] != INF and distance[v] > distance[r] + w:
                distance[v] = distance[r] + w
                if i == N:
                    return False
    return True


distance = [INF] * (N + 1)

if bellman_ford(1, Edge, distance):
    for i in range(2, N + 1):
        print(distance[i] if distance[i] != INF else -1)
else:
    print(-1)
