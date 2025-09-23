def main():
    N, M = map(int, input().split())

    print((M ** N - (M - 1) ** N) % 1000000007)


main()
