#include <bits/stdc++.h>

using namespace std;
const int inf = INT_MAX;

vector<vector<pair<int, int> > > adj;
vector<int> distance;
int n, d, c;


void do_input() {
    cin >> n >> d >> c;
    adj.clear();
    adj.resize(n + 1);
    ::distance.clear();
    ::distance.resize(n + 1, inf);
    for (int i = 0; i < d; ++i) {
        int a, b, s;
        cin >> a >> b >> s;
        adj[b].emplace_back(a, s);
    }
}

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.push({0, c});
    ::distance[c] = 0;

    while (!pq.empty()) {
        auto [dist, r] = pq.top();
        pq.pop();

        if (dist > ::distance[r]) continue;

        for (auto [v, w]: adj[r]) {
            if (::distance[v] > dist + w) {
                ::distance[v] = dist + w;
                pq.push({dist + w, v});
            }
        }
    }
}

void do_print() {
    int count = 0;
    int max_dist = 0;
    for (int i = 1; i <= n; ++i) {
        if (::distance[i] != inf) {
            count++;
            max_dist = max(max_dist, ::distance[i]);
        }
    }
    cout << count << " " << max_dist << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        do_input();
        solve();
        do_print();
    }
}
