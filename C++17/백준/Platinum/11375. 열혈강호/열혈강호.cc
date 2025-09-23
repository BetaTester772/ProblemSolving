#include <bits/stdc++.h>
using namespace std;

int V;
vector<vector<int> > adj;
vector<vector<int> > capacity;


int dfs(int u, int t, vector<bool> &visited, int flow) {
    if (u == t) return flow;
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v] && capacity[u][v] > 0) {
            int min_cap = min(flow, capacity[u][v]);
            int pushed = dfs(v, t, visited, min_cap);
            if (pushed > 0) {
                capacity[u][v] -= pushed;
                capacity[v][u] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int ford_fulkerson(int s, int t) {
    int max_flow = 0;
    while (true) {
        vector<bool> visited(V, false);
        int flow = dfs(s, t, visited, INT_MAX);
        if (flow == 0) break;
        max_flow += flow;
    }
    return max_flow;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    
    int N, M;
    cin >> N >> M;

    V = N + M + 2;
    int s = 0, t = V - 1;

    adj.assign(V, vector<int>());
    capacity.assign(V, vector<int>(V, 0));

    for (int i = 1; i <= N; ++i) {
        int person_node = i;
        adj[s].push_back(person_node);
        adj[person_node].push_back(s);
        capacity[s][person_node] = 1;

        int a;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            int b;
            cin >> b;
            int job_node = b + N;
            adj[person_node].push_back(job_node);
            adj[job_node].push_back(person_node);
            capacity[person_node][job_node] = 1;
        }
    }

    for (int j = 1; j <= M; ++j) {
        int job_node = j + N;
        adj[job_node].push_back(t);
        adj[t].push_back(job_node);
        capacity[job_node][t] = 1;
    }

    cout << ford_fulkerson(s, t) << '\n';
}
