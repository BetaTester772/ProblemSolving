#include <bits/stdc++.h>

using namespace std;

using f128 = long double;

using i128 = __int128;

using f80 = long double;

constexpr f128 PI = 3.1415926535897932384626433832795028841971693993751058209749445923Q;

f128 sin(f128 a) {

    a -= i128(a / (PI * 2)) * (PI * 2);

    f128 r = a, x = a, f = -a * a;

    for (f128 d = 2; d <= 30; d += 2)

        r += x *= f / (d * (d + 1));

    return r;

}

f128 round(f128 x, i128 n) {

    f128 d = 1;

    while (n--) d *= 10;

    return f128(i128(x * d + 0.5Q) / d);

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

        f128 V = A * x + B * ::sin(x);

        if (V < C) {

            l = x;

        } else {

            r = x;

        }

    }

    

    printf("%.9Lf\n", f80(r));

}

