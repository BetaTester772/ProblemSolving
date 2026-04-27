#include <bits/stdc++.h>

#define PB push_back
#define ll long long
#define MP make_pair

using namespace std;
using i64 = int64_t;

i64 N, S, x[1000001], h[1000001];

void do_input() {
    cin >> N >> S;
    for (i64 i=1; i<=N; i++) {
        cin >> x[i];
    }
    for (i64 i=1; i<=N; i++) {
        cin >> h[i];
    }
}

pair<i64, i64> do_solve() {
    pair<i64, i64> ans = MP(S, S);
    i64 l = S-1, r = S+1;
    queue<i64> Q;

    Q.push(S);
    while (!Q.empty()) {
        i64 i = Q.front(); Q.pop();
        ans.first = min(ans.first, i);
        ans.second = max(ans.second, i);
        while (l > 0 && x[l] >= x[i]-h[i]) {
            Q.push(l--);
        }
        while (r <= N && x[r] <= x[i]+h[i]) {
            Q.push(r++);
        }
    }

    return ans;
}

void do_print(i64 p, i64 q) {
    while (p <= q) {
        cout << p++ << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    do_input();
    auto [p, q] = do_solve();
    do_print(p, q);
    return 0;
}
