N = int(input())

# print(N * 1 + 1)
# print(N * 2 + 2)

n = 0

for i in range(1, N):
    # print(N * i + i)
    n += N * i + i

print(n)
