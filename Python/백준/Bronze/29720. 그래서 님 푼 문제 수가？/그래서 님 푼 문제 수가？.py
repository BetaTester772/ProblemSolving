N, M, K = map(int, input().split())

A = N - M * K

if A < 0:
    print(0, A + M - 1)
else:
    print(A, A + M - 1)
