#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > X;
vector<pair<int, int> > Y;
vector<pair<int, int> > Z;
int N;

int find(int u, vector<int> &parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    X.resize(N);
    Y.resize(N);
    Z.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X[i] = {x, i};
        Y[i] = {y, i};
        Z[i] = {z, i};
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    // 바로 인접 리스트
    vector<pair<int, pair<int, int> > > edges; // (weight, (node1, node2))
    edges.reserve(max(0, 3 * (N - 1)));

    for (int i = 0; i < N - 1; i++) {
        int x1 = X[i].first, idx1 = X[i].second;
        int x2 = X[i + 1].first, idx2 = X[i + 1].second;
        edges.push_back({abs(x1 - x2), {idx1, idx2}});

        int y1 = Y[i].first, idx3 = Y[i].second;
        int y2 = Y[i + 1].first, idx4 = Y[i + 1].second;
        edges.push_back({abs(y1 - y2), {idx3, idx4}});

        int z1 = Z[i].first, idx5 = Z[i].second;
        int z2 = Z[i + 1].first, idx6 = Z[i + 1].second;
        edges.push_back({abs(z1 - z2), {idx5, idx6}});
    }

    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    int mst_cost = 0;
    for (auto &edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu != pv) {
            mst_cost += w;
            parent[pu] = pv;
        }
    }

    cout << mst_cost;
}
