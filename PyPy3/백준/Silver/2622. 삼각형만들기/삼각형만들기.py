N = int(input())
result = 0
# A = []
for i in range(1, N + 1):
    for j in range(i, N + 1):
        k = N - i - j
        if i + j + k == N:
            if j > k:
                break
            if i + j > k:
                # print(i, j, k)
                result += 1

            # A.append([i, j, k])

# for a in A:
#     if a[0] + a[1] > a[2]:
#         result += 1

print(result)
