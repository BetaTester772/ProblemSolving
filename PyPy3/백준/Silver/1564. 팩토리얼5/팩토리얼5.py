n = int(input())

f = 1
for i in range(2, n + 1):
    f *= i
    while f % 10 == 0:
        f //= 10
    f %= 10 ** 12

f_s = str(f)
while len(f_s) < 5:
    f_s = '0' + f_s

print(f_s[-5:])
