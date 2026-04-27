#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
vector<vector<pair<ll, ll> > > edges;
vector<vector<ll> > result;


vector<ll> dijkstra(ll start) {
    vector<ll> dist(N + 1, LLONG_MAX);
    dist[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w]: edges[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});

                result[v][start] = u;
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    edges.resize(N + 1);
    result.resize(N + 1, vector<ll>(N + 1, 0));

    for (ll i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    for (ll i = 1; i <= N; i++) {
        dijkstra(i);
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            if (i == j) cout << "- ";
            else cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}
