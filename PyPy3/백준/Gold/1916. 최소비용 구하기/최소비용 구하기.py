import sys

input = sys.stdin.readline

N = int(input())
M = int(input())

edge = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    edge[a].append((b, c))

# print(edge)

start, end = map(int, input().split())

gradient = [float('inf')] * (N + 1)
visited = [0] * (N + 1)
visited[0] = 1

gradient[start] = 0

cdx = start

while visited[end] == 0:
    visited[cdx] = 1
    for i in range(len(edge[cdx])):
        gradient[edge[cdx][i][0]] = min(gradient[edge[cdx][i][0]], gradient[cdx] + edge[cdx][i][1])

    tmp = 0
    for i in range(1, N + 1):
        if visited[i] == 0 and gradient[tmp] > gradient[i]:
            tmp = i
    cdx = tmp

    # print(cdx)

print(gradient[end])
