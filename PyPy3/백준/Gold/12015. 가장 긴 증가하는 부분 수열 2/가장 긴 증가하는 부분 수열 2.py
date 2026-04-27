N = int(input())
A = list(map(int, input().split()))

LIS = [A[0]]

for i in range(1, len(A)):
    if A[i] > LIS[-1]:
        LIS.append(A[i])
    elif A[i] < LIS[-1]:
        low = 0
        high = len(LIS)-1
        while low < high:
            mid = (low + high) // 2
            if LIS[mid] >= A[i]:
                high = mid
            else:
                low = mid + 1
        LIS[high] = A[i]
    # print(LIS)


print(len(LIS))
