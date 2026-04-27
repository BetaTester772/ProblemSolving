import sys
import heapq


input = sys.stdin.readline


def sinbal(a, b, c):
    return (a[0] * b[1] + b[0] * c[1] + c[0] * a[1]) - (a[1] * b[0] + b[1] * c[0] + c[1] * a[0])


def ccw(a, b):
    fx = a[0:2]
    fy = a[2:]
    sx = b[0:2]
    sy = b[2:]
    first = sinbal(fx, fy, sx) * sinbal(fx, fy, sy)
    second = sinbal(sx, sy, fx) * sinbal(sx, sy, fy)
    if first == 0 and second == 0:
        if fx > fy:
            fx, fy = fy, fx
        if sx > sy:
            sx, sy = sy, sx
        if fx <= sy and sx <= fy:
            return True
        else:
            return False
    else:
        if first <= 0 and second <= 0:
            return True
        else:
            return False


N = int(input())
A = []
B = [[0] * N for _ in range(N)]
weight = []
visited = [False] * N

for _ in range(N):
    t = list(map(int, input().split()))
    A.append(t[:4])
    weight.append(t[4])

for i in range(N):
    for j in range(N):
        B[i][j] = ccw(A[i], A[j])

heap = []
for i in range(len(weight)):
    heap.append((weight[i], i))

heapq.heapify(heap)

result = 0

while heap:
    w, u = heapq.heappop(heap)
    visited[u] = True
    cnt = 0
    for i in range(N):
        if B[u][i] and visited[i] == False:
            cnt += 1

    # print(w, u, cnt)

    result += (cnt + 1) * w

print(result)
