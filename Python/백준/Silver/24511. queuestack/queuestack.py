from collections import deque
import sys

input = sys.stdin.readline

N = int(input())
A = deque(map(int, input().split()))
B = deque(map(int, input().split()))
M = int(input())
C = deque(map(int, input().split()))

queue = deque()

for i in range(N):
    if A[i] == 0:
        queue.append(B[i])

for i in range(M):
    queue.appendleft(C[i])
    print(queue.pop(), end=' ')
