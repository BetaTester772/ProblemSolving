n1, n2 = map(int, input().split())

x1, y1, x2, y2 = (n1 - 1) // 4 + 1, (n1 - 1) % 4 + 1, (n2 - 1) // 4 + 1, (n2 - 1) % 4 + 1
# print(x1, y1, x2, y2)
print(abs(x1 - x2) + abs(y1 - y2))
