N, M = map(int, input().split())  # 헛간, 길

Edge = [[] for _ in range(N + 1)]
distance = [float('inf')] * (N + 1)
for _ in range(M):
    A, B, C = map(int, input().split())
    Edge[A].append((B, C))
    Edge[B].append((A, C))


def dajikstra(start, distance):
    import heapq
    heap = []

    heapq.heappush(heap, (0, start))
    while heap:
        W_c, R = heapq.heappop(heap)

        if distance[R] < W_c:
            continue

        for v, w in Edge[R]:
            if distance[v] > w + W_c:
                distance[v] = w + W_c
                heapq.heappush(heap, (W_c + w, v))


dajikstra(1, distance)

print(distance[-1])
