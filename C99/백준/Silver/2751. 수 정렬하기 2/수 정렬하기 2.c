#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int *ar = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    qsort(ar, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        printf("%d\n", ar[i]);
    }

    free(ar);
    return 0;
}
