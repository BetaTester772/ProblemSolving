def main():
    while True:
        try:
            N = int(input())
            print(cantoring_along(N))

        except EOFError:
            break


def cantoring_along(N):
    if N == 0:
        return "-"
    else:
        return cantoring_along(N - 1) + " " * (3 ** (N - 1)) + cantoring_along(N - 1)


if __name__ == '__main__':
    main()
