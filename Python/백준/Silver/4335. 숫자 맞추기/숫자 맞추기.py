high = []
low = []

while True:
    num = int(input())
    if num == 0:
        break
    s = input()

    if s == "too high":
        high.append(num)
    elif s == "too low":
        low.append(num)
    elif s == "right on":
        if len(high) > 0 and min(high) <= num:
            print("Stan is dishonest")
        elif len(low) > 0 and max(low) >= num:
            print("Stan is dishonest")
        else:
            print("Stan may be honest")
        high = []
        low = []
