import sys

input = sys.stdin.readline

from collections import deque

sys.setrecursionlimit(10 ** 5)

V = int(input())
E = [[] for _ in range(V + 1)]
for _ in range(V):
    S = list(map(int, input().split()))
    for i in range(1, len(S) - 1, 2):
        E[S[0]].append(S[i:i + 2])

distance = dict()
tmp_distance = 0


def dfs(v):
    global distance
    global tmp_distance

    for i in range(len(E[v])):
        tmp_distance += E[v][i][1]
        if E[v][i][0] not in distance:
            distance[E[v][i][0]] = tmp_distance
            dfs(E[v][i][0])
        tmp_distance -= E[v][i][1]


distance[1] = 0
dfs(1)

v, _ = max(distance.items(), key=lambda x: x[1])
distance = dict()
distance[v] = 0
dfs(v)

_, result = max(distance.items(), key=lambda x: x[1])
print(result)
