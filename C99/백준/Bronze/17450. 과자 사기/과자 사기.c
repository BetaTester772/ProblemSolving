#include <stdio.h>

int main() {
    float gasungbi[3];
    int a, b;
    for (int i = 0; i < 3; ++i) {
        scanf("%d %d", &a, &b);
        if (a * 10 >= 5000) {
            gasungbi[i] = b * 10 / (float) (a * 10 - 500);
        } else {

            gasungbi[i] = b * 10 / (float) (a * 10);
        }
    }
    int max_i;
    float max = 0;
    char snu[3] = {'S', 'N', 'U'};
    for (int i = 0; i < 3; ++i) {
        if (gasungbi[i] > max) {
            max = gasungbi[i];
            max_i = i;
        }
    }
    printf("%c", snu[max_i]);
}