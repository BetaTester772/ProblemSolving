#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int> > > adj(V + 1);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); // next, weight
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq; // weight, vertex

    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1);
    dist[start] = 0;
    pq.push({0, start});
    parent[start] = start;

    while (pq.size()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [next, weight]: adj[now]) {
            if (dist[next] > cost + weight) {
                dist[next] = cost + weight;
                parent[next] = now;
                pq.push({cost + weight, next});
            }
        }
    }

    cout << dist[end] << '\n';

    // for (auto d: dist) {
    //     if (d == INFINITY) cout << "INF ";
    //     else cout << d << ' ';
    // }
    // cout << '\n';
    //
    // for (auto p: parent) {
    //     cout << p << ' ';
    // }
    // cout << '\n';

    vector<int> path;
    int cur_parent = end;
    path.push_back(cur_parent);
    while (cur_parent != start) {
        cur_parent = parent[cur_parent];
        path.push_back(cur_parent);
    }

    cout << path.size() << '\n';

    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        cout << *it << ' ';
    }
}
