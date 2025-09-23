#include "stdio.h"

void quickSort(int *arr, int left, int right) {
    int pivot = arr[left];
    int i = left, j = right;
    int temp;
    if (left < right) {
        while (i < j) {
            while (arr[j] > pivot) j--;
            while (i < j && arr[i] <= pivot) i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        arr[left] = arr[i];
        arr[i] = pivot;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

int main() {
    int n, arr[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d ", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("%d\n", arr[0] * arr[n - 1]);
}