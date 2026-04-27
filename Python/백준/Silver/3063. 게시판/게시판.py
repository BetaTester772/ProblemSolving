T = int(input())
for _ in range(T):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
    a = 0
    b = 0
    if x1 <= x3 <= x2:
        if x4 > x2:
            a = x2 - x3
        else:
            a = x4 - x3
    elif x1 <= x4 <= x2:
        if x3 < x1:
            a = x4 - x1
        else:
            a = x4 - x3
    elif x3 <= x1 and x2 <= x4:
        a = x2 - x1

    if y1 <= y3 <= y2:
        if y4 > y2:
            b = y2 - y3
        else:
            b = y4 - y3
    elif y1 <= y4 <= y2:
        if y3 < y1:
            b = y4 - y1
        else:
            b = y4 - y3
    elif y3 <= y1 and y2 <= y4:
        b = y2 - y1

    # print(a, b)
    print(((x2 - x1) * (y2 - y1) - a * b))
