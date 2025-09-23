import sys

N, M = map(int, input().split())


def input():
    return sys.stdin.readline().rstrip()


def print(value, end='\n'):
    sys.stdout.write(str(value) + end)


A = {}

for _ in range(N):
    site, pw = input().split()
    A[site] = pw

for _ in range(M):
    site = input()
    print(A[site])
