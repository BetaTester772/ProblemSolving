import sys


def input():
    return sys.stdin.readline().rstrip()


def left():
    current = A[0]
    count = 1
    for i in range(1, N):
        if current < A[i]:
            current = A[i]
            count += 1
    return count


def right():
    current = A[-1]
    count = 1
    for i in range(N - 2, -1, -1):
        if current < A[i]:
            current = A[i]
            count += 1
    return count


N = int(input())

A = []
for _ in range(N):
    A.append(int(input()))

print(left())
print(right())
