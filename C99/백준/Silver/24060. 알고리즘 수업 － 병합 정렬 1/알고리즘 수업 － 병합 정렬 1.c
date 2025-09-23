#include <stdio.h>
#include <stdlib.h>

int A[10000000], A_len = 0;

void merge(int arr[], int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    int temp[10000000];

    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[t++] = arr[i++];
        } else {
            temp[t++] = arr[j++];
        }
    }

    while (i <= q) {
        temp[t++] = arr[i++];
    }

    while (j <= r) {
        temp[t++] = arr[j++];
    }

    for (i = p, t = 0; i <= r; i++, t++) {
        arr[i] = temp[t];
        A[A_len++] = arr[i];
    }
}

void merge_sort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[10000000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, N - 1);

    if (A_len < K) {
        printf("-1\n");
    } else {
        printf("%d\n", A[K - 1]);
    }

    return 0;
}
