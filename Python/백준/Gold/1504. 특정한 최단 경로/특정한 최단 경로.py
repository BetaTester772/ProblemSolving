import sys

input = sys.stdin.readline

N, M = map(int, input().split())

edge = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    edge[a].append((b, c))
    edge[b].append((a, c))

# print(edge)

v1, v2 = map(int, input().split())


def dijk(start, end):
    cdx = start

    gradient = [float('inf')] * (N + 1)
    visited = [0] * (N + 1)
    visited[0] = 1

    gradient[start] = 0

    while visited[end] == 0:
        visited[cdx] = 1
        for i in range(len(edge[cdx])):
            gradient[edge[cdx][i][0]] = min(gradient[edge[cdx][i][0]], gradient[cdx] + edge[cdx][i][1])

        tmp = 0
        for i in range(1, N + 1):
            if visited[i] == 0 and gradient[tmp] > gradient[i]:
                tmp = i
        if tmp == cdx:
            print(-1)
            exit()
        else:
            cdx = tmp

        # print(cdx)
    return gradient[end]


path1 = dijk(1, v1) + dijk(v1, v2) + dijk(v2, N)
path2 = dijk(1, v2) + dijk(v2, v1) + dijk(v1, N)

print(min(path1, path2))
