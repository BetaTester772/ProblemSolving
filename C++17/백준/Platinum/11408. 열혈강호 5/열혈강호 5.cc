#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, capacity, cost, flow;

    Edge(int to, int rev, int capacity, int cost)
        : to(to), rev(rev), capacity(capacity), cost(cost), flow(0) {
    }
};

vector<vector<Edge> > adj;
int V;

void add_edge(int u, int v, int capacity, int cost) {
    adj[u].emplace_back(v, adj[v].size(), capacity, cost);
    adj[v].emplace_back(u, adj[u].size() - 1, 0, -cost);
}

bool spfa(int s, int t, vector<int> &parent, vector<int> &parent_edge, vector<int> &dist) {
    dist.assign(V, INT_MAX);
    parent.assign(V, -1);
    parent_edge.assign(V, -1);
    vector<bool> in_queue(V, false);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    in_queue[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for (int i = 0; i < adj[u].size(); ++i) {
            Edge &e = adj[u][i];
            if (e.capacity > e.flow && dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                parent[e.to] = u;
                parent_edge[e.to] = i;
                if (!in_queue[e.to]) {
                    q.push(e.to);
                    in_queue[e.to] = true;
                }
            }
        }
    }
    return dist[t] != INT_MAX;
}

pair<int, int> apply_flow(int s, int t, vector<int> &parent, vector<int> &parent_edge) {
    int flow = INT_MAX;

    for (int v = t; v != s; v = parent[v]) {
        Edge &e = adj[parent[v]][parent_edge[v]];
        flow = min(flow, e.capacity - e.flow);
    }
    int cost = 0;

    for (int v = t; v != s; v = parent[v]) {
        Edge &e = adj[parent[v]][parent_edge[v]];
        e.flow += flow;
        adj[v][e.rev].flow -= flow;
        cost += flow * e.cost;
    }
    return {flow, cost};
}

pair<int, int> min_cost_max_flow(int s, int t) {
    int total_flow = 0, total_cost = 0;
    vector<int> parent, parent_edge, dist;
    while (spfa(s, t, parent, parent_edge, dist)) {
        auto [f, c] = apply_flow(s, t, parent, parent_edge);
        total_flow += f;
        total_cost += c;
    }
    return {total_flow, total_cost};
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);


    int N, M;
    cin >> N >> M;

    V = N + M + 2;
    int s = 0, t = V - 1;

    adj.assign(V, vector<Edge>());

    for (int i = 1; i <= N; ++i) {
        int person_node = i;
        add_edge(0, person_node, 1, 0);

        int a;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            int b, cost;
            cin >> b >> cost;
            int job_node = b + N;
            add_edge(person_node, job_node, 1, cost);
        }
    }

    for (int j = 1; j <= M; ++j) {
        int job_node = j + N;
        add_edge(job_node, t, 1, 0);
    }

    pair<int, int> result = min_cost_max_flow(s, t);
    cout << result.first << '\n';
    cout << result.second << '\n';
    return 0;
}
