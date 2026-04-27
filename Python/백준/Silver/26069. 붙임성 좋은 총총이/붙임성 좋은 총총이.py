import sys


def input():
    return sys.stdin.readline().rstrip()


N = int(input())
meet = ["ChongChong"]

for _ in range(N):
    A, B = input().split()
    if A in meet or B in meet:
        meet.extend([A, B])

print(len(set(meet)))
