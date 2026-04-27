#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
vector<pair<int, int> > E;
vector<int> B_c;
vector<int> T;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        T[v] += val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        T[v] = T[v * 2] + T[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return T[v];
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    E.resize(M);
    vector<int> B;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        E[i] = {a, b};
        B.push_back(b);
    }

    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for (auto &edge: E) {
        edge.second = lower_bound(B.begin(), B.end(), edge.second) - B.begin();
    }

    // A 기준 정렬
    sort(E.begin(), E.end());

    int B_size = B.size();
    T.resize(B_size * 4);
    ll res = 0;

    for (auto [a, b]: E) {
        res += query(1, 0, B_size - 1, b + 1, B_size - 1);
        update(1, 0, B_size - 1, b, 1);
    }

    cout << res;
}
