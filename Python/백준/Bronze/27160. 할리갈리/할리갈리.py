import sys


def input():
    return sys.stdin.readline().strip()


N = int(input())

cards = {}

for _ in range(N):
    card, count = input().split()
    if cards.get(card) is None:
        cards[card] = int(count)
    else:
        cards[card] += int(count)
if 5 in cards.values():
    print("YES")
else:
    print("NO")
