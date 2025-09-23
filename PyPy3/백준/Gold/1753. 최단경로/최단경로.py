import sys
import heapq

input = sys.stdin.readline
print = sys.stdout.write

V, E = map(int, input().split())
start = int(input())

edge = [[] for _ in range(V + 1)]

for _ in range(E):
    a, b, c = map(int, input().split())
    edge[a].append((b, c))

gradient = [float('INF')] * (V + 1)
gradient[start] = 0

heap = []
heapq.heappush(heap, (0, start))  # 첫번째 기준 정렬 -> 거리, 정점

while heap:
    g, cdx = heapq.heappop(heap)

    if gradient[cdx] < g:
        continue

    for v, w in edge[cdx]:
        if g + w < gradient[v]:
            gradient[v] = g + w
            heapq.heappush(heap, (g + w, v))

# print(gradient)
for i in range(1, len(gradient)):
    print(str(gradient[i]).upper() + '\n')
