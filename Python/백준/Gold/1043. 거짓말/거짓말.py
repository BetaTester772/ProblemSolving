N, M = map(int, input().split())

know = list(map(int, input().split()))[1:]


def find_root(v):
    root = v
    while tree[root] != root:
        root = tree[root]
    return root


def merge_group(a, b):
    A = find_root(a)
    B = find_root(b)
    tree[B] = A


tree = [0] * (N + 1)
parties = []
for _ in range(M):
    S = list(map(int, input().split()))[1:]
    parties.append(S)

    for i in range(len(S)):
        if tree[S[i]] == 0:
            tree[S[i]] = S[0]
        else:
            merge_group(S[0], S[i])

for i in range(len(know)):
    know.append(tree[find_root(know[i])])

res = 0
for i in range(M):
    if find_root(parties[i][0]) not in know:
        res += 1
print(res)
