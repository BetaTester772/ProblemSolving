start_hour, start_minute = map(int, input().split())
end_hour, end_minute = map(int, input().split())
N = input()


def fill_zero(n):
    if n < 10:
        return "0" + str(n)
    return str(n)


result = 0

idx_hour, idx_minute = start_hour, start_minute

while True:
    if (N in fill_zero(idx_hour)) or (N in fill_zero(idx_minute)):
        result += 1

    if (idx_hour == end_hour) and (idx_minute == end_minute):
        break

    idx_minute += 1

    if 59 < idx_minute:
        idx_hour += 1
        idx_minute = 0

    if 23 < idx_hour:
        break

print(result)
