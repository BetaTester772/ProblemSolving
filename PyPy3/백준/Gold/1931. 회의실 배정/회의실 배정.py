import sys

N = int(input())
A = []

input = sys.stdin.readline

for _ in range(N):
    A.append(list(map(int, input().split())))

A.sort(key=lambda x: (x[1], x[0]))

# print(A)

rst = 1
last_end_time = A[0][1]
for i in range(1, N):
    if A[i][0] >= last_end_time:
        rst += 1
        last_end_time = A[i][1]

print(rst)
