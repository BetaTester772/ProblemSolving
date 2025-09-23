N = int(input())
A = list(map(int, input().split()))

left, right = 0, N - 1
a, b = left, right
num = float('inf')
while 0 <= left < right <= N - 1:
    tmp = A[left] + A[right]
    if abs(tmp) < num:
        a, b = left, right
        num = abs(tmp)

    if tmp < 0:
        left += 1
    elif tmp > 0:
        right -= 1
    else:
        break

print(A[a], A[b])
