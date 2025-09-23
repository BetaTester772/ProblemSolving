#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > edges;
int N, M, X, Y, Z;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    edges.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].emplace_back(v, w);
    }
    cin >> X >> Y >> Z;

    vector<int> dist1(N + 1, INT_MAX);
    dist1[X] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.emplace(0, X);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist1[u]) continue;
        if (u == Y) continue;

        for (auto [v, w]: edges[u]) {
            if (dist1[v] > dist1[u] + w) {
                dist1[v] = dist1[u] + w;
                pq.emplace(dist1[v], v);
            }
        }
    }

    vector<int> dist2(N + 1, INT_MAX);
    dist2[Y] = 0;
    pq.emplace(0, Y);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist2[u]) continue;

        for (auto [v, w]: edges[u]) {
            if (dist2[v] > dist2[u] + w) {
                dist2[v] = dist2[u] + w;
                pq.emplace(dist2[v], v);
            }
        }
    }

    if (dist1[Y] == INT_MAX || dist2[Z] == INT_MAX) {
        cout << -1;
    } else {
        cout << dist1[Y] + dist2[Z];
    }
    cout << ' ';

    if (dist1[Z] == INT_MAX) {
        cout << -1;
    } else {
        cout << dist1[Z];
    }
}
