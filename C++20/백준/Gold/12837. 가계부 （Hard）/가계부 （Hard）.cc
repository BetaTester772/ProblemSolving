#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> T;


void update(ll v, ll tl, ll tr, ll pose, ll diff) {
    if (tl == tr) {
        T[v] += diff;
    } else {
        ll tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose, diff);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose, diff);
        }

        T[v] = T[2 * v] + T[2 * v + 1];
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return T[v];
    }
    ll tm = (tl + tr) / 2;
    auto left = query(2 * v, tl, tm, l, min(r, tm));
    auto right = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return left + right;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N;
    T.resize(N * 4);

    cin >> M;
    while (M--) {
        ll c, i, j;
        cin >> c >> i >> j;
        if (c == 2) {
            cout << query(1, 0, N - 1, i - 1, j - 1) << '\n';
        } else {
            update(1, 0, N - 1, i - 1, j);
        }
    }
}
