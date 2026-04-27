#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, T, M, L;
    cin >> N >> T >> M >> L;

    vector<vector<pair<int, pair<int, int> > > > adj(N + 1);
    for (int i = 0; i < L; ++i) {
        int u, v, time, cost;
        cin >> u >> v >> time >> cost;
        adj[u].push_back({v, {time, cost}});
        adj[v].push_back({u, {time, cost}});
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

    vector<vector<int> > dist(N + 1, vector<int>(M + 1, INT_MAX));
    dist[1][0] = 0;
    pq.push({0, 0, 1}); // {시간, 비용, 노드}

    while (!pq.empty()) {
        auto [t, c, v] = pq.top();
        pq.pop();

        if (t > dist[v][c]) {
            continue;
        }

        for (auto &[u, edge]: adj[v]) {
            auto [u_t, u_c] = edge;

            if (c + u_c <= M && t + u_t < dist[u][c + u_c]) {
                dist[u][c + u_c] = t + u_t;
                pq.push({dist[u][c + u_c], c + u_c, u});
            }
        }
    }
    int min_cost = INT_MAX;
    for (int i = 0; i <= M; ++i) {
        if (dist[N][i] <= T) {
            min_cost = min(min_cost, i);
        }
    }
    if (min_cost == INT_MAX) {
        cout << -1;
    } else {
        cout << min_cost;
    }
}
