N, X = input().split()

# score dict
score_dict = {
        "A+": 450,
        "A0": 400,
        "B+": 350,
        "B0": 300,
        "C+": 250,
        "C0": 200,
        "D+": 150,
        "D0": 100,
        "F" : 0
}

학점합 = 0
평점합 = 0

for _ in range(int(N)-1):
    a, b = input().split()

    학점합 += int(a) * score_dict[b]
    평점합 += int(a)

    # print(학점합, 평점합)

last = int(input())
평점합 += last

# print(학점합,평점합)
# print(학점합//평점합)
# print(학점합 / 평점합 + last * 450 / 평점합)


X = int(round(float(X) * 100))
# print(X)

for i in ["F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"]:
    # print((학점합 + last * score_dict[i]) // 평점합, X)
    if (학점합 + last * score_dict[i]) // 평점합 > X:
        print(i)
        exit()
print('impossible')
