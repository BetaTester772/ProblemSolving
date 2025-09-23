def average_(ilist: list[int]):
    return round(sum(ilist) / len(ilist))


def median_(ilist: list[int]):
    ilist.sort()
    return ilist[len(ilist) // 2]


def mode_(ilist: list[int]):
    dic = {}
    for i in ilist:
        dic[i] = 0
    for i in ilist:
        dic[i] += 1

    a = list(dic.items())
    a.sort(key=lambda x: x[1])

    s = list(dic.values())
    s.sort()

    if s.index(a[-1][1]) < len(a) - 1:
        return a[s.index(a[-1][1]) + 1][0]

    return a[-1][0]


def range_(ilist: list[int]):
    return max(ilist) - min(ilist)


def main():
    N = int(input())

    ilist = []
    for _ in range(N):
        ilist.append(int(input()))

    print(average_(ilist))
    print(median_(ilist))
    print(mode_(ilist))
    print(range_(ilist))


main()
