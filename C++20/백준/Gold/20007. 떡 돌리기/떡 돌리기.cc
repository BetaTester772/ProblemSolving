#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M, X, Y;
vector<vector<pair<ll, ll>>> edges;

vector<ll> dijkstra(ll start) {
    vector<ll> dist(N, LLONG_MAX);
    dist[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : edges[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> X >> Y;
    edges.resize(N + 1);

    for (ll i = 0; i < M; i++) {
        ll A, B, C;
        cin >> A >> B >> C;
        edges[A].emplace_back(B, C);
        edges[B].emplace_back(A, C);
    }

    auto dist_from_Y = dijkstra(Y);
    vector<pair<ll, ll>> dist;
    for (ll i = 0; i < N; i++) {
        if (i == Y) continue;
        dist.emplace_back(dist_from_Y[i], i);
    }
    sort(dist.begin(), dist.end());
    ll result = 0;
    ll today = 0;
    for (ll i = 0; i < (ll)dist.size(); i++) {
        if (today + (dist[i].first * 2) <= X) {
            today += dist[i].first * 2;
        } else {
            today = 0;
            result++;
            if (dist[i].first * 2 <= X) {
                today += dist[i].first * 2;
            } else {
                result = -1;
                break;
            }
        }
    }
    if (today > 0) result++;
    cout << result;
}