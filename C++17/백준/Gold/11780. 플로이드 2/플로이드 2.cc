#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<vector<vector<int> > > paths;

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, vector<int>(n + 1, INT_MAX));
    paths.assign(n + 1, vector<vector<int> >(n + 1));


    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                    if (adj[i][j] > adj[i][k] + adj[k][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];

                        if (paths[i][k].empty() && paths[k][j].empty()) {
                            paths[i][j] = {k};
                        } else if (paths[i][k].empty()) {
                            paths[i][j] = paths[k][j];
                            paths[i][j].insert(paths[i][j].begin(), k);
                        } else if (paths[k][j].empty()) {
                            paths[i][j] = paths[i][k];
                            paths[i][j].push_back(k);
                        } else {
                            paths[i][j].clear();
                            paths[i][j].insert(paths[i][j].end(), paths[i][k].begin(), paths[i][k].end());
                            paths[i][j].push_back(k);
                            paths[i][j].insert(paths[i][j].end(), paths[k][j].begin(), paths[k][j].end());
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                cout << "0 ";
            else
                cout << (adj[i][j] == INT_MAX ? 0 : adj[i][j]) << " ";
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adj[i][j] != INT_MAX && i != j) {
                cout << paths[i][j].size() + 2 << " ";
                cout << i << " ";
                for (const auto &p: paths[i][j]) {
                    cout << p << " ";
                }
                if (adj[i][j] != INT_MAX) {
                    cout << j;
                }
            } else {
                cout << "0 ";
            }

            cout << '\n';
        }
    }
}
