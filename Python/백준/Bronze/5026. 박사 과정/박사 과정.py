N = int(input())

for _ in range(N):
    s = input()
    if s != "P=NP":
        print(sum(map(int, s.split('+'))))
    else:
        print("skipped")
