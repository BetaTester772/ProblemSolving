N = int(input())
B = list(map(int, input().split()))
R = list(map(int, input().split()))
B.sort()
R.sort()
score = 0
end_score = (N + 1) / 2

min_B = min(B)
while len(R) > 0 and R[0] <= min_B:
    R.pop(0)
i = 0
j_offset = 0
while score < end_score and i < len(B) and j_offset < len(R):
    for j in range(j_offset, len(R)):
        if B[i] < R[j]:
            score += 1
            # print("clear: " + str(B[0]) + " " + str(R[j]))
            j_offset = j + 1
            break
    i += 1
    # print(B, R)
if score >= end_score:
    print("YES")
else:
    print("NO")
