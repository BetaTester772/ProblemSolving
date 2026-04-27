#include <stdio.h>

int abs(int a) {
    if (a > 0) {
        return a;
    }
    return -a;
}

int main() {
    int A, Sum = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &A);
        if (abs(100 - (Sum + A)) > abs(100 - Sum)) {
            printf("%d", Sum);
            return 0;
        }
        Sum += A;
    }
    printf("%d", Sum);
}
