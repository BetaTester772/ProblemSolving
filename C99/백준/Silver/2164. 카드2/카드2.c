#include "stdio.h"

int start = 0, pointer = 0, queue[1000000] = {0,};

int main() {
    int N;
    scanf("%d", &N);
    pointer = N;
    for (int i = 0; i < N; ++i) {
        queue[i] = i + 1;
    }
    while (start != pointer - 1) {
        queue[start] = 0;
        start++;
        queue[pointer] = queue[start];
        pointer++;
        queue[start] = 0;
        start++;
    }
    printf("%d", queue[start]);
}