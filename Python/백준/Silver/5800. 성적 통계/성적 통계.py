import sys

input = sys.stdin.readline

T = int(input())

for j in range(T):
    A = list(map(int, input().split()))[1:]
    A.sort()
    max_ = max(A)
    min_ = min(A)
    Largest_gap = 0
    for i in range(1, len(A)):
        Largest_gap = max(A[i] - A[i - 1], Largest_gap)
    print(f"Class {j+1}\nMax {max_}, Min {min_}, Largest gap {Largest_gap}")
