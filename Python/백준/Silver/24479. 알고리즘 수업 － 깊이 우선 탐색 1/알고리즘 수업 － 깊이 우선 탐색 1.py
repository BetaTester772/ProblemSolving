import sys

sys.setrecursionlimit(10 ** 6)


def input():
    return sys.stdin.readline().rstrip()


N, M, R = map(int, input().split())

E = [[] for _ in range(N)]

for _ in range(M):
    u, v = map(int, input().split())
    E[u - 1].append(v - 1)
    E[v - 1].append(u - 1)

for i in range(N):
    E[i].sort()

V = [i for i in range(N)]
visited = [0 for _ in range(N)]

idx = 1


def dfs(V: list, E: list, R: int):
    global visited
    global idx
    visited[R] = idx
    idx += 1

    for x in E[R]:
        if visited[x] == 0:
            dfs(V, E, x)


dfs(V, E, R - 1)

for v in visited:
    print(v)
