#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
vector<int> distance;
vector<vector<int> > graph;
vector<int> isWall;
int M, N;

void do_input() {
    cin >> M >> N;
    graph.resize(N * M);
    ::distance.resize(N * M, inf);
    isWall.resize(N * M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int u = i * M + j;
            char c;
            cin >> c;
            isWall[u] = (c == '1') ? 1 : 0;
            if (i > 0) graph[u].push_back(u - M); // Up
            if (i < N - 1) graph[u].push_back(u + M); // Down
            if (j > 0) graph[u].push_back(u - 1); // Left
            if (j < M - 1) graph[u].push_back(u + 1); // Right
        }
    }
}

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int start = 0;
    ::distance[start] = 0;
    pq.push({0, start});
    while (pq.size()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > ::distance[u]) continue;
        for (int v: graph[u]) {
            int newDist = isWall[v] + dist;
            if (newDist < ::distance[v]) {
                ::distance[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    do_input();
    solve();
    int end = (N - 1) * M + (M - 1);
    cout << (::distance[end] == inf ? -1 : ::distance[end]) << endl;
}
