import sys


def input():
    return sys.stdin.readline().rstrip()


N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))


def check():
    for i in range(len(A) - 1):
        if not A[i] < A[i + 1]:
            return False
    return True


result = 0

while check() == False:
    for i in range(len(A) - 1):
        if not A[i] < A[i + 1]:
            result += A[i] - A[i + 1] + 1
            A[i] = A[i + 1] - 1
            # print(A)

print(result)
