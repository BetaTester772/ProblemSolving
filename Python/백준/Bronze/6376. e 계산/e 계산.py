from math import factorial

print("""n e
- -----------""")
for n in range(0, 10):
    e = 0
    for i in range(0, n + 1):
        e += 1 / factorial(i)
    if n == 0 or n == 1:
        print(f"{n} {int(e)}")
    elif n == 2:
        print(f"{n} {e:.1f}")
    else:
        print(f"{n} {e:.9f}")
