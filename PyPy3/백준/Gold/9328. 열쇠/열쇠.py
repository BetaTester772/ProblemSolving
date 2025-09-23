from collections import deque
import sys

input = sys.stdin.readline

T = int(input().strip())
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
for _ in range(T):
    h, w = map(int, input().split())
    grid = [input().strip() for _ in range(h)]
    key_set = set(list(input().strip()))
    if key_set == {'0'}:
        key_set = set()
    queue = deque()

    visited = [[False] * w for _ in range(h)]
    door_map = {}
    result = 0
    for i in range(h):
        for j in range(w):
            if len(queue) == 0 and grid[i][j] != '*' and (i == 0 or i == h - 1 or j == 0 or j == w - 1):
                if grid[i][j].isupper() and grid[i][j].lower() not in key_set:
                    pass
                else:
                    queue.append((i, j))
            if grid[i][j].isupper():
                if grid[i][j] not in door_map:
                    door_map[grid[i][j]] = []
                door_map[grid[i][j]].append((i, j))

    while queue:
        x, y = queue.popleft()
        # print(f"Visiting: ({x}, {y}), Key set: {key_set}, Queue: {list(queue)}")
        if grid[x][y] == '*' or visited[x][y] or (grid[x][y].isupper() and grid[x][y].lower() not in key_set):
            continue
        visited[x][y] = True

        if x == 0 or x == h - 1 or y == 0 or y == w - 1:
            for i in range(h):
                for j in range(w):
                    if not visited[i][j] and grid[i][j] != '*' and (i == 0 or i == h - 1 or j == 0 or j == w - 1):
                        if grid[i][j].isupper() and grid[i][j].lower() not in key_set:
                            continue
                        queue.append((i, j))

        if grid[x][y] == '$':
            result += 1
        elif grid[x][y].islower():
            key_set.add(grid[x][y])
            # print(door_map.get(grid[x][y].upper(), []))
            for door_x, door_y in door_map.get(grid[x][y].upper(), []):
                if visited[door_x][door_y]:
                    continue
                if door_x == 0 or door_x == h - 1 or door_y == 0 or door_y == w - 1:
                    queue.append((door_x, door_y))
                    continue
                temp = []
                for d in range(4):
                    nx, ny = door_x + dx[d], door_y + dy[d]
                    temp.append(0 <= nx < h and 0 <= ny < w and visited[nx][ny])
                if True in temp:
                    queue.append((door_x, door_y))

        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < h and 0 <= ny < w and not visited[nx][ny]:
                if grid[nx][ny] == '*':
                    continue
                queue.append((nx, ny))

        if len(queue) == 0:
            for door_x in range(h):
                for door_y in range(w):
                    if visited[door_x][door_y]:
                        continue
                    if door_x == 0 or door_x == h - 1 or door_y == 0 or door_y == w - 1:
                        queue.append((door_x, door_y))
                        continue
                    temp = []
                    for d in range(4):
                        nx, ny = door_x + dx[d], door_y + dy[d]
                        temp.append(0 <= nx < h and 0 <= ny < w and visited[nx][ny])
                    if True in temp:
                        queue.append((door_x, door_y))

    print(result)
