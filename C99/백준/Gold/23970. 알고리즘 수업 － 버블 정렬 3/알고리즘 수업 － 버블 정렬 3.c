#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool arrays_equal(int* A, int* B, int N) {
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int solve(int* A, int* B, int N) {
    if (arrays_equal(A, B, N)) return 1;

    for (int last = N - 1; last > 0; last--) {
        bool swapped = false;
        for (int i = 0; i < last; i++) {
            if (A[i] > A[i + 1]) {
                swap(&A[i], &A[i + 1]);
                swapped = true;
                if (A[i] == B[i] && arrays_equal(A, B, N)) return 1;
            }
        }
        if (!swapped) break;
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N], B[N];

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);

    int result = solve(A, B, N);
    printf("%d\n", result);
    return 0;
}