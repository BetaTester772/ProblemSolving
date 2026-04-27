N, M = map(int, input().split())
A = sorted(list(map(int, input().split())))

S = list()
B = dict()


def dfs(start):
    global S
    global B

    if len(S) == M:
        if str(S) in B:
            return
        else:
            B[str(S)] = True
        for s in S:
            print(s, end=' ')
        print()
        return

    for i in range(start, N):
        S.append(A[i])
        dfs(i)
        S.pop()


dfs(0)
