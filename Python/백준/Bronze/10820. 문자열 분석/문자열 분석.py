while True:
    try:
        s = input()
        소문자, 대문자, 숫자, 공백 = 0, 0, 0, 0
        for c in s:
            if c.islower():
                소문자 += 1
            elif c.isupper():
                대문자 += 1
            elif c.isdigit():
                숫자 += 1
            elif c.isspace():
                공백 += 1
        print(소문자, 대문자, 숫자, 공백)
    except EOFError:
        break
