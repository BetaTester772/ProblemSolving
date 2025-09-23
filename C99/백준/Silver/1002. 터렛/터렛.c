#include <stdio.h>
#include <math.h>

int abs(int a) {
    return a < 0 ? -a : a;
}


int main() {
    int T, x1, y1, r1, x2, y2, r2, d_square, r1_square, r2_square;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        d_square = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

        if (d_square == 0) {
            if (r1 == r2) {
                printf("-1\n");
            } else {
                printf("0\n");
            }
        } else {

            if (d_square > (r1 + r2) * (r1 + r2)) {
                printf("0\n");
            } else if (d_square < abs(r1 - r2) * abs(r1 - r2)) {
                printf("0\n");
            } else if (d_square == (r1 + r2) * (r1 + r2)) {
                printf("1\n");
            } else if (d_square == abs(r1 - r2) * abs(r1 - r2)) {
                printf("1\n");
            } else {
                printf("2\n");
            }
        }
    }
}
