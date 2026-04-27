from collections import deque

Deque = deque()

N = int(input())
A = list(map(int, input().split()))
A.reverse()

for i in range(N):
    n = A[i]
    i += 1
    if n == 1:
        Deque.appendleft(i)
    elif n == 2:
        Deque.insert(1, i)
    elif n == 3:
        Deque.append(i)

print(*Deque)
