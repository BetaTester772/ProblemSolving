a = int(input())
j = 1

while a > 1:
    j *= a
    a -= 1
j = str(j)
A = 0

for i in range(len(j) - 1, -1, -1):
    if j[i] != '0':
        break
    else:
        A += 1

print(A)
