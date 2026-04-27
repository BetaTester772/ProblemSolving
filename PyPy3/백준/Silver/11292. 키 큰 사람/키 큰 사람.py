def main():
    N = int(input())

    while N != 0:
        solve(N)
        N = int(input())


def solve(N):
    dic: dict[float, list[str]] = {}

    for i in range(1, N + 1):
        name, num = input().split()
        if num not in dic:
            dic[num] = [name]
        else:
            dic[num].append(name)

    max_num = max(dic.keys())

    for i in dic[max_num]:
        print(i, end=' ')
    print()


main()
