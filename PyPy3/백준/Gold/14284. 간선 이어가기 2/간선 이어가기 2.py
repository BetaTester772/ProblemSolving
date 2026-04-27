n, m = map(int, input().split())
Edge = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    Edge[a].append((b, c))
    Edge[b].append((a, c))

s, t = map(int, input().split())


def dajikstra(start, distance):
    import heapq
    heap = []

    heapq.heappush(heap, (0, start))
    distance[start] = 0

    while heap:
        W, R = heapq.heappop(heap)

        if distance[R] < W:
            continue

        for v, w_c in Edge[R]:
            if distance[v] > W + w_c:
                distance[v] = W + w_c
                heapq.heappush(heap, (W + w_c, v))


distance = [float('inf')] * (n + 1)

dajikstra(s, distance)
print(distance[t])
