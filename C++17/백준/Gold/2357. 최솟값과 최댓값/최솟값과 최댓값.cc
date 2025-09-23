#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
vector<pair<int, int> > T;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = {A[tl], A[tl]};
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        T[v] = {
            min(T[2 * v].first, T[2 * v + 1].first),
            max(T[2 * v].second, T[2 * v + 1].second)
        };
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) return {INT_MAX, INT_MIN};
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;
    auto [lf, ls] = query(2 * v, tl, tm, l, min(r, tm));
    auto [rf, rs] = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return {
        min(lf, rf),
        max(ls, rs)
    };
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    A.resize(N);
    T.resize(N * 4);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    build(1, 0, N - 1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        auto [c, d] = query(1, 0, N - 1, a - 1, b - 1);
        cout << c << ' ' << d << '\n';
    }
}
