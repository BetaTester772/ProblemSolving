#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> T;


void update(int v, int tl, int tr, int pose) {
    if (tl == tr) {
        T[v] += 1;
    } else {
        int tm = (tl + tr) / 2;
        if (pose <= tm) {
            update(v * 2, tl, tm, pose);
        } else {
            update(v * 2 + 1, tm + 1, tr, pose);
        }
        T[v] = (T[2 * v] + T[2 * v + 1]);
    }
}

ll query(int v, int tl, int tr, int k) {
    if (tl == tr) {
        T[v]--;
        return tl + 1; // 1-base
    }
    int tm = (tl + tr) / 2;
    int res;
    if (k <= T[2 * v]) {
        res = query(2 * v, tl, tm, k);
    } else {
        res = query(2 * v + 1, tm + 1, tr, k - T[2 * v]);
    }
    T[v] = T[2 * v] + T[2 * v + 1];
    return res;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    T.resize(2000000 * 4);

    int N;
    cin >> N;
    while (N--) {
        int T, X;
        cin >> T >> X;

        if (T == 1) {
            update(1, 0, 2000000 - 1, X - 1);
        } else {
            cout << query(1, 0, 2000000 - 1, X) << '\n';
        }
    }
}
