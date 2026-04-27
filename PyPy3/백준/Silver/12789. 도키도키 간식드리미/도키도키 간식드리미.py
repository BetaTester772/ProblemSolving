N = int(input())

students = list(map(int, input().split()))
queue = []

for i in range(1, N + 1):
    while True:
        if students and students[0] == i:
            students.pop(0)
            break
        elif queue and queue[-1] == i:
            queue.pop(-1)
            break
        elif students:
            queue.append(students.pop(0))
        else:
            print("Sad")
            exit()

if students or queue:
    print("Sad")
else:
    print("Nice")
