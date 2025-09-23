import sys
from collections import deque

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
    E[i].sort(reverse=True)

V = [i for i in range(N)]
visited = [0 for _ in range(N)]

idx = 1


def BFS(V: list, E: list, R: int):
    global visited
    global idx
    visited[R] = idx
    idx += 1

    Q = deque()
    Q.append(R)

    while len(Q) != 0:
        u = Q.popleft()
        for v in E[u]:
            if visited[v] == 0:
                visited[v] = idx
                idx += 1
                Q.append(v)


BFS(V, E, R - 1)

for i in range(N):
    print(visited[i])
