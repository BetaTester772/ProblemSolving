import sys


def input():
    return sys.stdin.readline().rstrip()


N = int(input())

arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))
    arr[i].append(i)

for i in range(N):
    n = 1
    for j in range(N):
        if j == i:
            continue

        if arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]:
            n += 1
    arr[i].append(n)

# print(arr)

arr.sort(key=lambda x: x[2])
for i in range(N):
    print(arr[i][3], end=' ')
