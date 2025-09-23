N, M = map(int, input().split())
A = list(map(int, input().split()))

Edge = [[] for _ in range(N)]

for _ in range(M):
    a, b, t = map(int, input().split())
    if not (a != N - 1 and A[a] == 1) and not (b != N - 1 and A[b] == 1):
        Edge[a].append((b, t))
        Edge[b].append((a, t))

distacne = [float('inf')] * N


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


dajikstra(0, distacne)

print(distacne[-1] if distacne[-1] != float('inf') else -1)
