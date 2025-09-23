#include <stdio.h>

int main() {
    int temp, N=0;
    int min1=999, min2=999;
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &temp);
        if (temp < min1) {
            min1 = temp;
        }
        N += temp;
    }
    for (int i = 0; i < 2; ++i) {
        scanf("%d", &temp);
        if (temp < min2) {
            min2 = temp;
        }
        N += temp;
    }
    printf("%d", N - min1 - min2);
}