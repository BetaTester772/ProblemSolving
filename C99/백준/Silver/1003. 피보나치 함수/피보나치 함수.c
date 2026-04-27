#include "stdio.h"


int main() {
    int n, T;
    scanf("%d", &T);

    int zero[41] = {1, 0,}, one[41] = {0, 1,};

    for (int i = 2; i < 41; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d %d\n", zero[n], one[n]);
    }
}