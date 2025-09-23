#include <bits/stdc++.h>

#define PB push_back
#define ll long long
#define MP make_pair

using namespace std;
using i64 = int64_t;

set<i64> lf[1'000'001], rf[1'000'001];

void do_input() {
    i64 N; cin >> N;
    while (N--) {
        i64 u, v; cin >> u >> v;
        lf[u].insert(v);
        rf[v].insert(-u);
    }
}

i64 do_query(i64 u, i64 v) {
    auto it1 = lf[u].lower_bound(v);
    if (it1 == lf[u].end()) return -1;
    if (*it1 == v) return 1;
    auto it2 = rf[v].lower_bound(-u);
    if (it2 == rf[v].end()) return -1;
    return 2;
}

void do_solve() {
    i64 Q; cin >> Q;
    while (Q--) {
        i64 u, v; cin >> u >> v;
        cout << do_query(u, v) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    do_input();
    do_solve();
}