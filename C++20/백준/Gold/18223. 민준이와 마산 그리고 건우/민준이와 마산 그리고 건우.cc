#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > > edges;
int V, E, P;

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

    cin >> V >> E >> P;
    edges.resize(V + 1);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    vector<int> dist_from_1 = dijkstra(1);
    vector<int> dist_from_P = dijkstra(P);


    if (dist_from_1[V] == INT_MAX || dist_from_P[V] == INT_MAX) {
        cout << "GOOD BYE";
    } else {
        if (dist_from_1[P] + dist_from_P[V] <= dist_from_1[V]) {
            cout << "SAVE HIM";
        } else {
            cout << "GOOD BYE";
        }
    }
}
