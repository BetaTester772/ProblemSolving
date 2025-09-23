from collections import deque

N, M = map(int, input().split())

E = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    a, b, w = map(int, input().split())
    E[a].append((b, w))
    E[b].append((a, w))


def bfs(start, end):
    queue = deque()
    queue.append((start, 0))
    visited = [False] * (N + 1)
    visited[start] = True

    while queue:
        v, d = queue.popleft()

        if v == end:
            return d

        for v_c, d_c in E[v]:
            if not visited[v_c]:
                visited[v_c] = True
                queue.append((v_c, d_c + d))


for _ in range(M):
    a, b = map(int, input().split())
    print(bfs(a, b))
