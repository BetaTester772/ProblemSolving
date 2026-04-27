# 정답 비율 = (문제를 맞은 사람의 수) / ((문제를 맞은 사람의 수) + (문제를 맞은 각 사람이 그 문제를 맞기 전까지 틀린 횟수의 총 합)) × 100

history = {}
solver = set()

N = int(input())
for _ in range(N):
    체점번호, 유저아이디, 채점결과, 메모리, 시간, 언어, 길이 = input().split()
    if 채점결과 == '4':
        solver.add(유저아이디)
    elif history.get(유저아이디, False) and 유저아이디 not in solver:
        history[유저아이디] += 1
    elif 유저아이디 not in solver:
        history[유저아이디] = 1

num = 0
if 'megalusion' in solver:
    solver.remove('megalusion')

for s in solver:
    num += history.get(s, 0)

if len(solver) > 0:
    result = len(solver) / (len(solver) + num) * 100
else:
    result = 0

print("%0.10f" % result)
