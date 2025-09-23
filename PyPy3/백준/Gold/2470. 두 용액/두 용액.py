N = int(input())
A = list(map(int, input().split()))
A.sort()
# print(A)

min_y = float('inf')
result = None

left = 0
right = N - 1
while left < right:
    tmp = A[left] + A[right]
    # print(A[left:right + 1])
    if abs(tmp) < min_y:
        min_y = abs(tmp)
        result = (A[left], A[right])

    if tmp > 0:
        right -= 1
    elif tmp < 0:
        left += 1
    else:
        break

print(*result)
