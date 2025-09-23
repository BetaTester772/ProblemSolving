#include <bits/stdc++.h>
using namespace std;
int N, M;
#define ll long long
vector<ll> A;
vector<ll> T;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = A[tl];
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        T[v] = (T[2 * v] + T[2 * v + 1]);
    }
}

void update(int v, int tl, int tr, int pose, int new_val) {
    if (tl == tr) {
        T[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose, new_val);
        }
        T[v] = (T[2 * v] + T[2 * v + 1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) +
            query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    A.resize(N);
    T.resize(N * 4);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    build(1, 0, N - 1);

    for (int i = 0; i < Q; ++i) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << query(1, 0, N - 1, x - 1, y - 1) << '\n';
        update(1, 0, N - 1, a - 1, b);
    }
}
