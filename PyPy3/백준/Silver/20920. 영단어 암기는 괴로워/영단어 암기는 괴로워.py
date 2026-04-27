import sys

N, M = map(int, input().split())


def input() -> str:
    return sys.stdin.readline().rstrip()


word_dict: dict = {}

for _ in range(N):
    S = input()
    if len(S) >= M:
        if S not in word_dict:
            word_dict[S] = 1
        else:
            word_dict[S] += 1

word_list = []

for key in word_dict.keys():
    word_list.append([key, word_dict[key]])

word_list.sort(key=lambda x: (-x[1], -len(x[0]), x[0]))

for word, num in word_list:
    print(word)
