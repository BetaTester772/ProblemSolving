N, M = map(int, input().split())
X, Y = map(int, input().split())


def fac(x):
    if x <= 1:
        return 1
    return x * fac(x - 1)


숫자는알아 = 0
숫자도몰라 = N - M

for _ in range(M):
    a, b = map(int, input().split())
    if a == 0:
        숫자는알아 += 1

# print(숫자는알아, 숫자도몰라)

입력횟수 = 1
if 숫자는알아 > 0:
    # 남은자리(숫자는 알어 + 숫자도 몰라) P (숫자도 몰라)
    입력횟수 *= fac(숫자는알아 + 숫자도몰라) // fac(숫자도몰라)
if 숫자도몰라 > 0:
    # 9-M P 숫자도 몰러
    입력횟수 *= fac(9 - M) // fac((9 - M) - 숫자도몰라)

# print(입력횟수)

if 입력횟수 > 3:
    print(입력횟수 * X + ((입력횟수 - 1) // 3) * Y)
else:
    print(입력횟수 * X)
