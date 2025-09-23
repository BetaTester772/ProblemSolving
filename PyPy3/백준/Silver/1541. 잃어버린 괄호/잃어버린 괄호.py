import re

S = re.split(r'([+-])', input())

m = 0
p = 0

for i in range(len(S)):
    if S[i] == "-":
        j = i + 1
        while j < len(S) and S[j] != "-":
            if S[j].isdigit():
                m += int(S[j])
                S[j] = "="
            j += 1
    elif S[i].isdigit():
        p += int(S[i])
        S[i] = "="

print(p - m)
