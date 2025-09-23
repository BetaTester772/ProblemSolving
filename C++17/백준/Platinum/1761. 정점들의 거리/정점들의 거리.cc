#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<pair<ll, ll> > > adj;
ll timer;
vector<ll> tin, tout, height;
vector<vector<ll> > up;


ll n, l; // 정점 수, 트리 높이

void dfs(ll v, ll p) // {현재, 부모, 거리}
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto [u, w]: adj[v]) {
        if (height[u] == -1) {
            // 방문하지 않은 정점
            height[u] = height[v] + w;
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

void preprocess(ll root) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    height.assign(n + 1, -1);
    height[root] = 1;
    timer = 0;
    l = ceil(log2(n));
    up.assign(n + 1, vector<ll>(l + 1));
    dfs(root, root);
}

bool is_ancestor(ll u, ll v) // u가 v의 조상인가
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) // 공통 조상 직전까지
        {
            u = up[u][i];
        }
    }
    return up[u][0]; //공통 조상 직전에서 하나 위에꺼 == 공통 조상
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    adj.resize(n + 1);

    for (ll i = 0; i < n - 1; ++i) {
        ll u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    preprocess(1);

    // 거리 = a의 높이 + b의 높이 - (lca(a, b)의 높이 * 2)
    ll m;
    cin >> m;

    for (ll i = 0; i < m; ++i) {
        ll A, B;
        cin >> A >> B;

        cout << height[A] + height[B] - height[lca(A, B)] * 2 << '\n';
    }
}
