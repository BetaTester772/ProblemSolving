#include <stdio.h>

int main() {
    int N, a = 0;
    int b = 0, s = 0;
    scanf("%d", &N);
    char S[N * 8 + 1];
    scanf("%s", S);
    for (int i = 0; i < N; ++i) {
//        printf("%c\n", S[a]);
        if (S[a] == 'b') {
            a += 7;
            b += 1;
        } else {
            a += 8;
            s += 1;
        }
    }
//    printf("%d %d", b, s);
    if (b>=s){
        printf("bigdata? ");
    }    if (b<=s){
        printf("security!");
    }
}