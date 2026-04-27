T = int(input())

for _ in range(T):
    h, l = map(int, input().split())

    dictionary = {}

    pos = [0] * h

    for i in range(h):
        C = list(map(int, input().split()))

        # pos.append(C.index(max(C)))

        for j in range(l):
            if C[j] != -1:
                dictionary[C[j]] = [i, j]

    result = 0
    for key in sorted(dictionary.keys()):
        # print(key, dictionary[key])
        car = dictionary[key]
        result += car[0] * 20  # height
        result += min(abs(car[1] - pos[car[0]]), l - abs((car[1] - pos[car[0]]))) * 5  # convey
        # print(abs(car[1] - pos[car[0]]), l - abs((car[1] - pos[car[0]])))
        pos[car[0]] = car[1]

    print(result)
