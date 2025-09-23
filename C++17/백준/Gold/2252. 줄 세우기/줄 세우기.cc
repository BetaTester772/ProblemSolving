#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int> > adj(V + 1);
    vector<int> indegree(V + 1, 0);

    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;
    for (int i = 1; i < V + 1; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (q.size()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v: adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }

    for (int v: result) {
        cout << v << ' ';
    }
}
