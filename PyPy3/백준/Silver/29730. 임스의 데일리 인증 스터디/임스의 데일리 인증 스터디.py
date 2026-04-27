N = int(input())

etc_history = []
boj_history = []

for _ in range(N):
    a = input()
    if a[:7] == 'boj.kr/':
        boj_history.append(a)
    else:
        etc_history.append(a)

etc_history.sort()
etc_history.sort(key=lambda x: len(x))
boj_history.sort(key=lambda x: int(x[7:]))

for i in etc_history + boj_history:
    print(i)
