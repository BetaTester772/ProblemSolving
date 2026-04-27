T = int(input())


def make_palindrome(N):
    if N == 1:
        return "0"
    else:
        S = "0" * (((N // 2) - 1) * 2)

    if N % 4 == 1:
        S = S[:len(S) // 2] + "9" + S[len(S) // 2:]
    elif N % 4 == 3:
        S = S[:len(S) // 2] + "2" + S[len(S) // 2:]

    return "1" + S + "1"


for _ in range(T):
    N = int(input())

    print(make_palindrome(N))
