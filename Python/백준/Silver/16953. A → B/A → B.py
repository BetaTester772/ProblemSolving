A, B = map(int, input().split())
depth = 0

Tree = []
Tree.append(A)


def bfs():
    global Tree
    global depth
    while len(Tree) > 0:
        tmp = []
        for i in range(len(Tree)):
            n, m = Tree[i] * 2, Tree[i] * 10 + 1
            if n == B or m == B:
                print(depth + 2)
                exit()
            if n < B:
                tmp.append(n)
            if m < B:
                tmp.append(m)
        Tree = tmp.copy()

        # print(Tree)
        depth += 1
    print(-1)


bfs()
