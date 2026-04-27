#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
vector<pair<int, int> > T;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (A[tl] % 2 == 0) {
            T[v] = {1, 0}; // 짝수의 개수, 홀수의 개수
        } else {
            T[v] = {0, 1}; // 짝수의 개수, 홀수의 개수
        }
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        T[v] = {T[2 * v].first + T[2 * v + 1].first, T[2 * v].second + T[2 * v + 1].second};
    }
}

void update(int v, int tl, int tr, int pose, int new_val) {
    if (tl == tr) {
        if (new_val % 2 == 0) {
            T[v] = {1, 0}; // 짝수의 개수, 홀수의 개수
        } else {
            T[v] = {0, 1}; // 짝수의 개수, 홀수의 개수
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose, new_val);
        }
        T[v] = {T[2 * v].first + T[2 * v + 1].first, T[2 * v].second + T[2 * v + 1].second};
    }
}

int query_even(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return T[v].first;
    }
    int tm = (tl + tr) / 2;
    return query_even(2 * v, tl, tm, l, min(r, tm)) +
           query_even(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int query_odd(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return T[v].second;
    }
    int tm = (tl + tr) / 2;
    return query_odd(2 * v, tl, tm, l, min(r, tm)) +
           query_odd(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    T.resize(N * 4);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    build(1, 0, N - 1);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N - 1, b - 1, c);
        } else if (a == 2) {
            cout << query_even(1, 0, N - 1, b - 1, c - 1) << '\n';
        } else if (a == 3) {
            cout << query_odd(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}
