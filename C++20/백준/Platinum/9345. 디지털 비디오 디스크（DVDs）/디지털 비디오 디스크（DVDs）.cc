#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > T;
vector<int> A;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = {tl, tl};
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        T[v] = {
            min(T[2 * v].first, T[2 * v + 1].first),
            max(T[2 * v].second, T[2 * v + 1].second)
        };
    };
}


void update(int v, int tl, int tr, int pose, int val) {
    if (tl == tr) {
        T[v] = {val, val};
    } else {
        int tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose, val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose, val);
        }
        T[v] = {
            min(T[2 * v].first, T[2 * v + 1].first),
            max(T[2 * v].second, T[2 * v + 1].second)
        };
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return {INT_MAX, INT_MIN};
    }
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;

    pair<int, int> q1 = query(2 * v, tl, tm, l, min(r, tm)),
            q2 = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);

    return {min(q1.first, q2.first), max(q1.second, q2.second)};
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    ::T.resize(100000 * 4);
    ::A.resize(100000);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            A[i] = i;
        }
        build(1, 0, N - 1);


        for (int i = 0; i < K; ++i) {
            int Q, A, B;
            cin >> Q >> A >> B;
            if (Q == 0) {
                swap(::A[A], ::A[B]);
                update(1, 0, N - 1, A, ::A[A]);
                update(1, 0, N - 1, B, ::A[B]);
            } else {
                cout << ((query(1, 0, N - 1, A, B) == make_pair(A, B)) ? "YES" : "NO") << '\n';
            }
        }
    }
}
