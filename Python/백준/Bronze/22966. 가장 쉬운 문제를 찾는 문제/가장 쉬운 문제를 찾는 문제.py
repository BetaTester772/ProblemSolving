N = int(input())

A = {}

for _ in range(N):
    a, b = input().split()
    A[int(b)] = a

print(A[min(A.keys())])
