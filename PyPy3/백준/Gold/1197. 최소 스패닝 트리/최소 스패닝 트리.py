# Prim
V, E = map(int, input().split())

Edge = [[] for _ in range(V + 1)]
for _ in range(E):
    v1, v2, w = map(int, input().split())
    Edge[v1].append((v2, w))
    Edge[v2].append((v1, w))

tree = {}  # 노드: [부모, [자식 정점 list]]]
for i in range(1, V + 1):
    tree[i] = [-1, []]

visited = [0] * (V + 1)


def Prim(start):
    import heapq

    heap = []
    heapq.heappush(heap, (0, start))
    tree[start][0] = start
    result = 0
    while heap:
        W, R = heapq.heappop(heap)
        if visited[R] == 1:
            continue
        visited[R] = 1
        # print(R, W, visited)

        result += W


        for V, W_c in Edge[R]:
            heapq.heappush(heap, (W_c, V))
            tree[R][1].append(V)
            tree[V][0] = R

    print(result)


for i in range(1, V + 1):
    if Edge[i]:
        Prim(i)
        break

# print(tree)
# print(visited)
# print(result)
