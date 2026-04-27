def ex_product(a, b, c):  # 신발끈
    return ((b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1])) / 2

N = int(input())
points = []
for _ in range(N):
    points.append(tuple(map(int, input().split())))

result = 0
for i in range(1, N - 1):
    # print(points[0], points[i], points[i + 1], ex_product(points[0], points[i], points[i + 1]))
    result += ex_product(points[0], points[i], points[i + 1])

print(abs(round(result, 1)))
