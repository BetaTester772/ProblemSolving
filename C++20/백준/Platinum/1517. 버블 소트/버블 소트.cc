#include <bits/stdc++.h>
using namespace std;
int N, M;
#define ll long long
vector<ll> A;
vector<ll> T;
vector<pair<ll, int> > B;

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

ll query(int v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return T[v];
    }
    ll tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) +
            query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    A.resize(N);
    B.resize(N);
    T.resize(N * 4);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        B[i] = {A[i], i};
    }

    sort(B.begin(), B.end());
    ll res = 0;
    for (auto b: B) {
        res += query(1, 0, N - 1, b.second + 1, N - 1);
        update(1, 0, N - 1, b.second, 1);
    }
    cout << res << '\n';
}
