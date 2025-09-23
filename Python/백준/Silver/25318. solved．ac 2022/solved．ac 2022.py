import math
from datetime import datetime, timedelta
from decimal import Decimal


def round(x):
    t = x - int(x)
    if t >= 0.5:
        return int(x) + 1
    else:
        return int(x)


N = int(input())

if N == 0:
    print(0)
    exit()

times = []
levels = []

for _ in range(N):
    A = input().split()
    time, level = A[0] + ' ' + A[1], int(A[2])
    time = datetime.strptime(time, "%Y/%m/%d %H:%M:%S")
    # print(time)
    times.append(time)
    levels.append(level)

# print(table)

P = []
P_l = []

for i in range(len(times)):
    delta: float = (times[-1] - times[i]).total_seconds() / (24 * 60 * 60)
    P.append(max((0.5) ** (delta / 365), (0.9) ** (N - i - 1)) * 10 ** 20)
    P_l.append(P[i] * levels[i])

#rint((math.fsum(P_l) / math.fsum(P)))
# print(math.fsum(P_l))
# print(math.fsum(P))
print(round(math.fsum(P_l) / math.fsum(P)))
