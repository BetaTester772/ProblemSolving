import sys


def input():
    return sys.stdin.readline().strip()


N = int(input())

n = 0
for _ in range(N):
    n += int(input())

print(n - N + 1)
