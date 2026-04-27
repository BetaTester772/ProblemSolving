#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int num = 2;
    while (N != 1) {
        if (N % num == 0) {
            // printf("%d ", N);
            printf("%d\n", num);
            N /= num;
            num = 2;
        } else {
            num++;
        }

    }
}