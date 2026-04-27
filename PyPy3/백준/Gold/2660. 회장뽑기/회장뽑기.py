N = int(input())

edge = [[] for _ in range(N + 1)]

a, b = map(int, input().split())
while not (a == b == -1):
    edge[a].append((b, 1))
    edge[b].append((a, 1))
    a, b = map(int, input().split())

result = []


def dijkstra(start):
    import heapq
    distance = [float('inf')] * (N + 1)
    heap = []

    heapq.heappush(heap, (0, start))
    distance[start] = 0

    while heap:
        w, v = heapq.heappop(heap)

        if w > distance[v]:
            continue

        for v_c, w_c in edge[v]:
            if w_c + w < distance[v_c]:
                distance[v_c] = w_c + w
                heapq.heappush(heap, (w_c + w, v_c))
                # print(heap, distance)

    return distance[1:]



for i in range(1, N + 1):
    result.append(max(dijkstra(i)))
    # print()

# print(result)

r_score = min(result)
print(r_score, result.count(r_score))

for i in range(N):
    if result[i] == r_score:
        print(i + 1, end=' ')
