#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int i = X, n = 1;
    while (i > n) {
        i -= n++;
        // printf("%d, %d\n", i, n);
    }
    // printf("%d, %d\n", i, n); //n이 줄, i가 번째

    if (n % 2 == 0)
        printf("%d/%d", i, n + 1 - i);
    else
        printf("%d/%d", n + 1 - i, i);
}
