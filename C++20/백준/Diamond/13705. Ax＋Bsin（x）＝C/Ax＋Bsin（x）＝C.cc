#include <bits/stdc++.h>
using namespace std;

using f128 = __float128;
using i128 = __int128;
using f80 = long double;
const f128 PI = 3.1415926535897932384626Q;

f128 sin_f128(f128 a) {
    a -= i128(a / (PI * 2)) * (PI * 2);
    f128 r = a, x = a, f = -a * a;
    for (f128 d = 2; d <= 100; d += 2)
        r += x *= f / (d * (d + 1));
    return r;
}

int main() {
    f80 a, b, c;
    cin >> a >> b >> c;
    f128 A, B, C, l, r, x;
    A = a, B = b, C = c;

    l = (C - B) / A;
    r = (C + B) / A;

    int t = 100;
    while (t--) {
        x = (l + r) / 2;
        f128 V = A * x + B * sin_f128(x);
        if (V < C) {
            l = x;
        } else {
            r = x;
        }
    }

    f128 U = 1000000, D = 0.5;
    printf("%Lf\n", f80(i128(U * r + D) / U));
}
