#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > T;
vector<int> A;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = {A[tl], tl};
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        if (T[2 * v].first == T[2 * v + 1].first) {
            T[v] = {T[2 * v].first, min(T[2 * v].second, T[2 * v + 1].second)};
        } else if (T[2 * v].first < T[2 * v + 1].first) {
            T[v] = T[2 * v];
        } else {
            T[v] = T[2 * v + 1];
        }
    }
}

void update(int v, int tl, int tr, int pose, int val) {
    if (tl == tr) {
        T[v] = {val, tl};
    } else {
        int tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose, val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose, val);
        }

        if (T[2 * v].first == T[2 * v + 1].first) {
            T[v] = {T[2 * v].first, min(T[2 * v].second, T[2 * v + 1].second)};
        } else if (T[2 * v].first < T[2 * v + 1].first) {
            T[v] = T[2 * v];
        } else {
            T[v] = T[2 * v + 1];
        }
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return {INT_MAX, -1};
    }
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;
    auto left = query(2 * v, tl, tm, l, min(r, tm));
    auto right = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    if (left.first == right.first) {
        return {left.first, min(left.second, right.second)};
    } else if (left.first < right.first) {
        return left;
    } else {
        return right;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    T.resize(N * 4);
    build(1, 0, N - 1);

    cin >> M;
    while (M--) {
        int c, i, j;
        cin >> c >> i >> j;
        if (c == 2) {
            cout << query(1, 0, N - 1, i - 1, j - 1).second + 1 << '\n';
        } else {
            update(1, 0, N - 1, i - 1, j);
        }
    }
}
