A = []
for _ in range(3):
    A.append(list(map(int, input().split())))

if (A[1][1] - A[0][1]) * (A[2][0] - A[1][0]) == (A[2][1] - A[1][1]) * (A[1][0] - A[0][0]):
    print("WHERE IS MY CHICKEN?")
else:
    print("WINNER WINNER CHICKEN DINNER!")
