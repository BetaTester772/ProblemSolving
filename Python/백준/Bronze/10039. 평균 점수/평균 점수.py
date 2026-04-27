s = 0
for _ in range(5):
    t = int(input())
    s += t if t > 40 else 40

print(s // 5)
