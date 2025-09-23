#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int N, M;
vector<ll> A;
vector<ll> T;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = A[tl] % mod;
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        T[v] = (T[2 * v] * T[2 * v + 1]) % mod;
    }
}

void update(int v, int tl, int tr, int pose, int new_val) {
    if (tl == tr) {
        T[v] = new_val % mod;
    } else {
        int tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose, new_val);
        }
        T[v] = (T[2 * v] * T[2 * v + 1]) % mod;
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 1; // not 0
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) *
            query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)) % mod;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;
    A.resize(N);
    T.resize(N * 4);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    build(1, 0, N - 1);

    for (int i = 0; i < M + K; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N - 1, b - 1, c);
        } else {
            cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}
