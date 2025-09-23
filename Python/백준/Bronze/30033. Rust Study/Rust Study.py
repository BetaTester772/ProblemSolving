N = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

result = 0

for i in range(N):
    if A[i] <= B[i]:
        result += 1

print(result)
