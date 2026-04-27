#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
constexpr i64 INF = INT64_MAX >> 1;

i64 N, M, K, state[200001];
vector<pair<i64, i64>> adj[200001];
set<pair<i64, i64>> bad_edges;

void do_input() {
    cin >> N >> M >> K;
    while (M--) {
        i64 u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    while (K--) {
        i64 L, prv; cin >> L >> prv;
        state[prv] = 1;
        for (i64 i=1; i<L; i++) {
            i64 v; cin >> v;
            bad_edges.insert({prv, v});
            prv = v;
        }
        state[prv] = -1;
    }
}

i64 dist[200001][2];

void dijkstra(i64 src) {
    for (i64 i=1; i<=N; i++) {
        dist[i][0] = dist[i][1] = INF;
    }
    dist[src][0] = 0;

    using T = pair<i64, pair<i64, bool>>;
    priority_queue<T, vector<T>, greater<>> pq;
    pq.push({0, {src, 0}});

    while (!pq.empty()) {
        auto [d, vf] = pq.top();
        auto [v, f] = vf; pq.pop();

        // cout << "d: " << d << " (v, f): " << v << ' ' << f << '\n';

        if (d > dist[v][f]) continue;

        for (auto [u, cost]: adj[v]) {
            if (bad_edges.contains({v, u})) {
                if (f) {
                    if (state[u] != -1) {
                        if (dist[u][1] > d + cost) {
                            dist[u][1] = d + cost;
                            pq.push({dist[u][1], {u, 1}});
                        }
                    }
                } else {
                    if (state[v] == 1) {
                        if (state[u] != -1) {
                            if (dist[u][1] > d + cost) {
                                dist[u][1] = d + cost;
                                pq.push({dist[u][1], {u, 1}});
                            }
                        }
                    } else {
                        if (dist[u][0] > d + cost) {
                            dist[u][0] = d + cost;
                            pq.push({dist[u][0], {u, 0}});
                        }
                    }
                }
            } else {
                if (dist[u][0] > d + cost) {
                    dist[u][0] = d + cost;
                    pq.push({dist[u][0], {u, 0}});
                }
            }
        }
    }
}

void do_print() {
    for (i64 i=1; i<=N; i++) {
        i64 t = min(dist[i][0], dist[i][1]);
        cout << (t == INF ? -1 : t) << ' ';
    }
    cout << '\n';
}

int main() {
    do_input();
    dijkstra(1);
    do_print();
}
