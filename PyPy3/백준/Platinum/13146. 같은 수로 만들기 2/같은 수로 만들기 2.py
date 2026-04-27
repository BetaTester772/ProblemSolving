N = int(input())
A=[int(input())]
for _ in range(N-1):
    a = int(input())
    if a != A[-1]:
        A.append(a)

res = 0
t = A[0]
for i in range(1, len(A)):
    if t < A[i]:
        res += A[i] - t
    t = A[i]

res += max(A) - t

print(res)