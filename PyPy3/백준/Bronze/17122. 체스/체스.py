import sys


def input():
    return sys.stdin.readline().rstrip()


T = int(input())


def get_color_method1(A: str):
    alphabet = A[0]
    num = int(A[1])

    # print(ord(alphabet) % 2)
    # print(num % 2)
    # print(ord(alphabet) % 2 == 1 and num % 2 == 1)
    if ord(alphabet) % 2 == num % 2:
        return "b"
    else:
        return 'w'


def get_color_method2(B: int):
    # print(B % 8, B % 8 % 2)
    # print(B // 8, (B // 8)% 2)

    if B % 8 == 0:
        if B // 8 % 2:
            return 'w'
        else:
            return 'b'

    if B % 8 % 2 == 1 and (B // 8) % 2 == 0:
        return 'b'
    elif B % 8 % 2 == 0 and (B // 8) % 2 == 1:
        return 'b'
    elif B % 8 % 2 == 1 and (B // 8) % 2 == 1:
        return 'w'
    elif B % 8 % 2 == 0 and (B // 8) % 2 == 0:
        return 'w'


# for i in range(1, 65):
#     print(i, get_color_method2(i))
#     print()

for _ in range(T):
    a, b = input().split()
    # print(a, b)
    # print(get_color_method1(a), get_color_method2(int(b)))
    if get_color_method1(a) == get_color_method2(int(b)):
        print("YES")
    else:
        print("NO")
