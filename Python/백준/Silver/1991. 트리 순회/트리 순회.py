N = int(input())

tree = dict()

for _ in range(N):
    a, b, c = input().split()
    tree[a] = (b, c)

S = []


def print_S():
    for s in S:
        print(s, end='')
    print()
    S.clear()


def VLR(V):
    S.append(V)
    if tree[V][0] != '.' and tree[V][0] not in S:
        VLR(tree[V][0])
    if tree[V][1] != '.' and tree[V][1] not in S:
        VLR(tree[V][1])


def LVR(V):
    if tree[V][0] != '.' and tree[V][0] not in S:
        LVR(tree[V][0])
    S.append(V)
    if tree[V][1] != '.' and tree[V][1] not in S:
        LVR(tree[V][1])


def LRV(V):
    if tree[V][0] != '.' and tree[V][0] not in S:
        LRV(tree[V][0])
    if tree[V][1] != '.' and tree[V][1] not in S:
        LRV(tree[V][1])
    S.append(V)


VLR('A')
print_S()

LVR('A')
print_S()

LRV('A')
print_S()
