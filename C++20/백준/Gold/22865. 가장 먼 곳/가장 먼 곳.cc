#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > adj;
int N, A, B, C, M;

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto edge: adj[u]) {
            int v = edge.first;
            int w = edge.second;
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
    
    cin >> N;
    adj.resize(N + 1);
    cin >> A >> B >> C;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int D, E, L;
        cin >> D >> E >> L;
        adj[D].push_back({E, L});
        adj[E].push_back({D, L});
    }
    vector<int> distA = dijkstra(A);
    vector<int> distB = dijkstra(B);
    vector<int> distC = dijkstra(C);

    // vector<int> result(N + 1);
    int max_dist = INT_MIN, max_vertex = 0;
    for (int i = 1; i <= N; i++) {
        if (i == A || i == B || i == C) {
            // result[i] = INT_MIN;
            continue;
        }
        // cout << i << ' ' << distA[i] << ' ' << distB[i] << ' ' << distC[i] << endl;
        // result[i] = min(distA[i], min(distB[i], distC[i]));
        int temp = min(distA[i], min(distB[i], distC[i]));
        if (temp > max_dist) {
            max_dist = temp;
            max_vertex = i;
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << result[i] << ' ';
    // }
    // cout << endl;

    cout << max_vertex;
}
