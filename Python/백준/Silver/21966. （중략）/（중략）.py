N = int(input())
S = input()

if len(S) <= 25:
    print(S)
    exit()


def find_all(string: str, char: str):
    return [i for i, letter in enumerate(string) if letter == char]


A = find_all(S, '.')

for a in A:
    if 11 < a < len(S) - 12:
        print(S[:9] + '......' + S[-10:])

        exit()

print(S[:11] + '...' + S[-11:])
