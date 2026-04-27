def solve(S):
    for c in S:
        if c == ']':
            if len(stack) > 0 and stack[-1] == '[':
                stack.pop(-1)
            else:
                print('no')
                return
        elif c == ')':
            if len(stack) > 0 and stack[-1] == '(':
                stack.pop(-1)
            else:
                print('no')
                return
        elif c in ['(', '[']:
            stack.append(c)
    if len(stack) == 0:
        print('yes')
    else:
        print('no')


while True:
    S = input()
    stack = []
    if S == '.':
        break
    solve(S)
