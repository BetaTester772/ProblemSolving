from decimal import Decimal

T = int(input())

for i in range(T):
    n, m = map(int, input().split())
    avg = Decimal(m + n) / 2

    print(f"Scenario #{i + 1}:")
    print(int(avg * (m - n + 1)))
    print()
