import sys

input = sys.stdin.readline

T = int(input())


def solve(S: str):
    result = None
    if '0' in S:
        n = S.find('0')
        a = n
        b = len(S) - n - 2

        # print(a, b)

        if b > 0:
            result = '1'
        else:
            result = '0'

        # print(result)

        if a % 2 == 1:
            if result == '0':
                result = '1'
            else:
                result = '0'

        # print(result)
    else:
        n = S.find('1')
        a = n
        b = len(S) - n - 1

        result = '1'

        if a % 2 == 1:
            if result == '1':
                result = '0'
            else:
                result = '1'
    return result


for _ in range(T):
    print(solve(input()))
