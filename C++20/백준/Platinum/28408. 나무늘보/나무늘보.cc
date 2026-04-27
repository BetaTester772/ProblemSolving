#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 N, a[500001], b[500001];

void do_input() {
    cin >> N;
    for (i64 i=0; i<N; i++) cin >> a[i];
    for (i64 i=0; i<N; i++) {
        i64 u; cin >> u;
        b[u] = i+1;
    }
    for (i64 i=0; i<N; i++) a[i] = b[a[i]];
}

i64 R = 1, MOD = 998244353;

i64 ub(i64 l, i64 r, i64 x) {
    while (l < r) {
        i64 m = l + (r - l) / 2;
        if (a[m] <= x) l = m+1;
        else r = m;
    }
    return l;
}

void f(i64 l, i64 r, i64 offset) {
    if (a[l] != offset+r-l) {
        R = 0;
        return;
    }
    if (r-l == 1) return;

    i64 t = a[l+1];
    i64 q = ub(l, r, t);
    if (q == r) {
        R = (R << 1) % MOD;
        f(l+1, r, offset);
    } else {
        f(l+1, q, offset);
        f(q, r, offset+q-l-1);
    }
}

int main() {
    do_input();
    f(0, N, 0);
    cout << R << '\n';
}