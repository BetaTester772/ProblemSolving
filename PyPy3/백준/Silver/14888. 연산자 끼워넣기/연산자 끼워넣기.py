def 더하기(a, b):
    return a + b


def 빼기(a, b):
    return a - b


def 곱하기(a, b):
    return a * b


def 나누기(a, b):
    if a < 0 < b:
        return -(-a // b)
    else:
        return a // b


N = int(input())
A = list(map(int, input().split()))
덧셈, 뺄셈, 곱셈, 나눗셈 = map(int, input().split())

max_num = -10 ** 9
min_num = 10 ** 9


def dfs(i, num):
    global 덧셈, 뺄셈, 곱셈, 나눗셈, max_num, min_num

    if i == len(A):
        max_num = max(max_num, num)
        min_num = min(min_num, num)
        # print(max_num, min_num)
        return

    if 덧셈 > 0:
        덧셈 -= 1
        dfs(i + 1, 더하기(num, A[i]))
        덧셈 += 1
    if 뺄셈 > 0:
        뺄셈 -= 1
        dfs(i + 1, 빼기(num, A[i]))
        뺄셈 += 1
    if 곱셈 > 0:
        곱셈 -= 1
        dfs(i + 1, 곱하기(num, A[i]))
        곱셈 += 1
    if 나눗셈 > 0:
        나눗셈 -= 1
        dfs(i + 1, 나누기(num, A[i]))
        나눗셈 += 1


dfs(1, A[0])

print(max_num)
print(min_num)
