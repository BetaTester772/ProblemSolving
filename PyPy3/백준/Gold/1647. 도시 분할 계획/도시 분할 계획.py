# Prim
V, E = map(int, input().split())

Edge = [[] for _ in range(V + 1)]
for _ in range(E):
    v1, v2, w = map(int, input().split())
    Edge[v1].append((v2, w))
    Edge[v2].append((v1, w))

visited = [0] * (V + 1)

max_weight = 0


def Prim(start):
    import heapq
    global max_weight

    heap = []
    heapq.heappush(heap, (0, start))
    result = 0
    while heap:
        W, R = heapq.heappop(heap)
        if visited[R] == 1:
            continue
        visited[R] = 1
        # print(R, W, visited)
        max_weight = max(W, max_weight)
        result += W

        for V, W_c in Edge[R]:
            heapq.heappush(heap, (W_c, V))

    print(result - max_weight)


for i in range(1, V + 1):
    if Edge[i]:
        Prim(i)
        break
