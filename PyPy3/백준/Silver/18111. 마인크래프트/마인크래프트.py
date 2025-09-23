import sys

input = sys.stdin.readline

N, M, B = map(int, input().split())

min_h = 256
max_h = 0

chunk = []
time_result = []

for _ in range(N):
    data = list(map(int, input().split()))
    min_h = min(min_h, min(data))
    max_h = max(max_h, max(data))
    chunk.append(data)

res_time = 1e9
res_h = 0


def get_time(h):
    time = 0
    block = B
    for i in range(N):
        for j in range(M):
            if chunk[i][j] > h:
                time += (chunk[i][j] - h) * 2
                block += (chunk[i][j] - h)
            else:
                time += (h - chunk[i][j])
                block -= (h - chunk[i][j])
    if block < 0:
        return -1
    return time


for h in range(min_h, max_h + 1):
    time = get_time(h)
    if time == -1:
        continue
    if time < res_time:
        res_time = time
        res_h = h
    elif time == res_time:
        res_h = max(res_h, h)

print(res_time, res_h)
