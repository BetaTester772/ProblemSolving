N, M = map(int, input().split())

S = []

A = sorted(list(map(int, input().split())))

B = {}

C = []


def dfs():
    global C
    if len(S) == M:
        if B.get(str(S), False):
            return
        else:
            B[str(S)] = True
        for s in S:
            print(s, end=' ')
        print()
        return

    for i in range(0, N):
        if i in C:
            continue
        S.append(A[i])
        C.append(i)
        dfs()
        S.pop()
        C.pop()


dfs()
