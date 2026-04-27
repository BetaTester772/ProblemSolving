N = int(input())
A = list(map(int, input().split()))

LIS = [A[0]]
real = [(A[0], 0)]

for i in range(1, len(A)):
    if A[i] > LIS[-1]:
        LIS.append(A[i])
        real.append((A[i], len(LIS) - 1))
    elif A[i] < LIS[-1]:
        low = 0
        high = len(LIS) - 1
        while low < high:
            mid = (low + high) // 2
            if LIS[mid] >= A[i]:
                high = mid
            else:
                low = mid + 1
        LIS[high] = A[i]
        real.append((A[i], high))

    # print("LIS:", LIS)
    # print("real:", real)
    # print(LIS)
# print(history)
print(len(LIS))
pre = len(LIS)
answer = []
for i in range(len(real) - 1, -1, -1):
    if pre - 1 == real[i][1]:
        answer.append(real[i][0])
        pre -= 1
print(*reversed(answer))
