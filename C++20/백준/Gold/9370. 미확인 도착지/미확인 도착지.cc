#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int n, m, t, s, g, h;
vector<vector<pair<int,int>>> adj;  // (to, weight)
vector<int> candidates;
int wgh;

vector<ll> dijkstra(int start) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void do_input() {
    cin >> n >> m >> t;
    adj.assign(n + 1, {});
    candidates.resize(t);
    cin >> s >> g >> h;

    for (int i = 0; i < m; i++) {
        int a, b, d; cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
        if ((a == g && b == h) || (a == h && b == g)) {
            wgh = d;
        }
    }
    for (int i = 0; i < t; i++) cin >> candidates[i];
}

void solve() {
    auto ds = dijkstra(s);
    auto dg = dijkstra(g);
    auto dh = dijkstra(h);

    vector<int> ans;
    for (int dest : candidates) {
        if (ds[dest] == INF) continue;
        // s->g->h->dest 또는 s->h->g->dest
        long long via_gh = ds[g] + wgh + dh[dest];
        long long via_hg = ds[h] + wgh + dg[dest];
        long long best = ds[dest];
        if (via_gh == best || via_hg == best) ans.push_back(dest);
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        do_input();
        solve();
    }
}
