A, B = map(int, input().split())
K, X = map(int, input().split())

result = B - A + 1

row = (K - X) - A
if row > 0:
    result -= row

high = B - (K + X)
if high > 0:
    result -= high
# 
# print(row)
# print(high)

if result <= 0:
    print('IMPOSSIBLE')
else:
    print(result)
