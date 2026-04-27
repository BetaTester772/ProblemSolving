#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<pair<int, int> > > edges;
vector<int> H;
int N, V, E;
int A, B;

vector<int> dijkstra(int start) {
    vector<int> dist(V + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (auto &edge: edges[cur]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > dist[cur] + weight) {
                dist[next] = dist[cur] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> V >> E;
    cin >> A >> B;
    H.resize(N);
    edges.resize(V + 1);

    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        vector<int> dist = dijkstra(H[i]);
        if (dist[A] == INT_MAX) {
            dist[A] = -1;
        }
        if (dist[B] == INT_MAX) {
            dist[B] = -1;
        }
        ans += dist[A] + dist[B];
    }
    cout << ans;
}
