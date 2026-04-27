#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> T;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = 1;
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

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


    int N, K;
    cin >> N >> K;

    T.resize(N * 4);

    build(1, 0, N - 1);
    int size = N, i = 0;
    cout << '<';
    while (size) {
        i = (i + K - 1) % size;
        cout << query(1, 0, N - 1, i + 1) << (size > 1 ? ", " : "");
        size--;
    }
    cout << ">";
}
