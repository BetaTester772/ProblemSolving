from collections import deque

n, m = map(int, input().split())

Map = [list(map(int, input().split())) for _ in range(n)]
Distance = [[-1] * m for _ in range(n)]

start = None


def find_start():
    global start
    for i in range(n):
        for j in range(m):
            if Map[i][j] == 2:
                start = (i, j)
            elif Map[i][j] == 0:
                Distance[i][j] = 0


find_start()


# print(start)


def get_available_path(cdx):
    result = []
    if cdx[0] - 1 >= 0 and Map[cdx[0] - 1][cdx[1]] != 0 and Distance[cdx[0] - 1][cdx[1]] == -1:
        result.append((cdx[0] - 1, cdx[1]))
    if cdx[1] - 1 >= 0 and Map[cdx[0]][cdx[1] - 1] != 0 and Distance[cdx[0]][cdx[1] - 1] == -1:
        result.append((cdx[0], cdx[1] - 1))
    if cdx[0] + 1 < n and Map[cdx[0] + 1][cdx[1]] != 0 and Distance[cdx[0] + 1][cdx[1]] == -1:
        result.append((cdx[0] + 1, cdx[1]))
    if cdx[1] + 1 < m and Map[cdx[0]][cdx[1] + 1] != 0 and Distance[cdx[0]][cdx[1] + 1] == -1:
        result.append((cdx[0], cdx[1] + 1))

    return result


# print(get_available_path((1, 1)))


def bfs():
    global Distance
    current_distance = 0

    Distance[start[0]][start[1]] = current_distance
    current_distance += 1

    E = deque()
    E.extend(get_available_path(start))

    while len(E) != 0:
        tmp = []
        for e in E.copy():
            if -1 < Distance[e[0]][e[1]]:
                E.popleft()
                continue
            Distance[e[0]][e[1]] = current_distance
            E.popleft()
            tmp.extend(get_available_path(e))
        current_distance += 1

        # print(E)
        E.extend(tmp)
    # print(Distance)


bfs()

for i in range(n):
    for j in range(m):
        print(Distance[i][j], end=' ')
    print()
