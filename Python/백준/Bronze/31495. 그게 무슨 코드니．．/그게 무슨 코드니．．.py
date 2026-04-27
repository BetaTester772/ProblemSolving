S = input()

S = S.strip()

if S[0] == "\"" and S[-1] == "\"":
    print(S[1:-1] if len(S[1:-1]) != 0 else "CE")
else:
    print("CE")
