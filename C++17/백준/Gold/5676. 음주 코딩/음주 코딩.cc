#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
vector<int> T;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (A[tl] < 0) {
            T[v] = -1;
        } else if (A[tl] > 0) {
            T[v] = 1;
        } else {
            T[v] = 0;
        }
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        T[v] = T[2 * v] * T[2 * v + 1];
    }
}

void update(int v, int tl, int tr, int pose, int new_val) {
    if (tl == tr) {
        if (new_val < 0) {
            T[v] = -1;
        } else if (new_val > 0) {
            T[v] = 1;
        } else {
            T[v] = 0;
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose, new_val);
        }
        T[v] = T[2 * v] * T[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 1; // not 0
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(r, tm)) *
           query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    while (cin >> N >> K) {
        A.resize(N);
        T.resize(N * 4);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        build(1, 0, N - 1);

        for (int i = 0; i < K; ++i) {
            char a;
            int b, c;
            cin >> a >> b >> c;
            if (a == 'C') {
                update(1, 0, N - 1, b - 1, c);
            } else {
                int q = query(1, 0, N - 1, b - 1, c - 1);
                char r;
                if (q > 0) r = '+';
                else if (q < 0) r = '-';
                else r = '0';
                cout << r;
            }
        }
        cout << '\n';
    }
}
