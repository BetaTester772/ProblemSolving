#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];

    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        int isPrime = 1;
        if (A[i] == 1)
            continue;
        for (int j = 2; j <= (int) sqrt(A[i]); ++j) {
            if (A[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            cnt++;
    }
    printf("%d", cnt);
}
