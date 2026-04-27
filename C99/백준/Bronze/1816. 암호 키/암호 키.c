#include "stdio.h"

int isSafePrime(long long S) {
    if (S == 1) {
        return 0;
    }
    for (int i = 2; i * i < S && i <= 1000000; i++) {
        if (S % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    long long S;

    scanf("%d", &N);

    for (int i; i < N; i++) {
        scanf("%lld", &S);
        if (isSafePrime(S))
        {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}