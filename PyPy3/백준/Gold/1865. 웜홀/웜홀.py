TC = int(input())
INF = 1 ** 5


def belman_ford(Edge, distacne):
    for i in range(N):
        for j in range(M * 2 + W):
            r, v, w = Edge[j]
            if distacne[v] > distacne[r] + w:
                distacne[v] = distacne[r] + w
                if i == N - 1:
                    return False
    return True


for _ in range(TC):
    N, M, W = map(int, input().split())

    Edge = []

    for _ in range(M):
        S, E, T = map(int, input().split())
        Edge.append((S, E, T))
        Edge.append((E, S, T))

    for _ in range(W):
        S, E, T = map(int, input().split())
        Edge.append((S, E, -T))

    distance = [INF] * (N + 1)
    if not belman_ford(Edge, distance):
        print("YES")
    else:
        print("NO")
    # print(Edge)
    # print(distance)
