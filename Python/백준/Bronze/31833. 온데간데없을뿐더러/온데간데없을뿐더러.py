N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

X = int("".join([str(A[i]) for i in range(N)]))
Y = int("".join([str(B[i]) for i in range(N)]))

if X < Y:
    print(X)
else:
    print(Y)
