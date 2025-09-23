import sys
from collections import deque

sys.setrecursionlimit(10 ** 5)

n = int(input())
E = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    E[a].append([b, c])
    E[b].append([a, c])

S = deque()
distance = dict()


def dfs(v):
    global S
    global distance

    if len(S) > n:
        return

    for i in range(len(E[v])):
        S.append(E[v][i][1])
        if E[v][i][0] not in distance:
            distance[E[v][i][0]] = sum(S)
            dfs(E[v][i][0])
        S.pop()


distance[1] = 0
dfs(1)

v, _ = max(distance.items(), key=lambda x: x[1])
distance = dict()
distance[v] = 0
dfs(v)

_, result = max(distance.items(), key=lambda x: x[1])
print(result)
