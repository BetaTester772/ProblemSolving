#include <stdio.h>

int main() {
    int n, result = 0, tmp1, tmp2;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &tmp1, &tmp2);
        result += (tmp1) * tmp2;
    }
    printf("%d", result);
}
