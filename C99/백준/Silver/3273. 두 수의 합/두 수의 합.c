//
// Created by 안호성 on 2025. 5. 30..
//
#include <stdio.h>
#include <math.h>

void insertionSort(int *A, int n) {
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int partition(int *A, int n) {
    int pivot = A[n / 2];
    int left = 0, right = n - 1;
    while (left <= right) {
        while (A[left] < pivot) left++;
        while (A[right] > pivot) right--;
        if (left <= right) {
            int tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;
            left++;
            right--;
        }
    }
    return left;
}

void heapify(int *A, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && A[l] > A[largest]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;
    if (largest != i) {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        heapify(A, n, largest);
    }
}

void heapSort(int *A, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (int i = n - 1; i > 0; i--) {
        int tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        heapify(A, i, 0);
    }
}

void introSortUtil(int *A, int n, int depthLimit) {
    if (n < 16) {
        insertionSort(A, n);
        return;
    }
    if (depthLimit == 0) {
        heapSort(A, n);
        return;
    }
    int p = partition(A, n);
    introSortUtil(A, p, depthLimit - 1);
    introSortUtil(A + p, n - p, depthLimit - 1);
}

void introSort(int *A, int n) {
    int depthLimit = 2 * (int) log2(n);
    introSortUtil(A, n, depthLimit);
}

int main() {
    int n, x, result = 0;
    scanf("%d", &n);
    int A[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    introSort(A, n);
    scanf("%d", &x);

    int left = 0, right = n - 1;
    while (left < right) {
        if (A[left] + A[right] == x) {
            result++;
            right--;
        } else if (A[left] + A[right] < x) left++;
        else right--;
    }
    printf("%d", result);
}
