N, M, X = map(int, input().split())

Edge1 = [[] for _ in range(N + 1)]
Edge2 = [[] for _ in range(N + 1)]
Distance1 = [float('inf')] * (N + 1)
Distance2 = [float('inf')] * (N + 1)
for _ in range(M):
    s, e, t = map(int, input().split())
    Edge1[s].append((e, t))
    Edge2[e].append((s, t))


def dijkstra(start, edge, distance):
    import heapq
    heap = []
    heapq.heappush(heap, (0, start))
    distance[start] = 0
    while heap:
        w, r = heapq.heappop(heap)

        if distance[r] > w:
            continue

        for v, w_c in edge[r]:
            if distance[v] > w + w_c:
                distance[v] = w + w_c
                heapq.heappush(heap, (w + w_c, v))


dijkstra(X, Edge1, Distance1)
dijkstra(X, Edge2, Distance2)

# print(Distance1)
# print(Distance2)

result = 0
for i in range(1, N + 1):
    result = max(Distance1[i] + Distance2[i], result)

print(result)
