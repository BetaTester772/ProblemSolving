N = int(input())
R = list(map(int, input().split()))
G = list(map(int, input().split()))

rst = 0
stationary_row = max(G)
for i in range(N - 1):
    if G[i] < stationary_row:
        stationary_row = G[i]
    # print(R[i] * stationary_row)
    rst += R[i] * stationary_row
print(rst)
