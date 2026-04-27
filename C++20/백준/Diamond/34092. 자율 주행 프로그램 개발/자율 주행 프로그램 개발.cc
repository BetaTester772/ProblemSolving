#include <bits/stdc++.h>

using namespace std;

const long long P1 = 313, M1 = 1000000007;
const long long P2 = 317, M2 = 1000000009;

long long pw1_arr[200005], pw2_arr[200005];

void precompute_powers() {
    pw1_arr[0] = 1; pw2_arr[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        pw1_arr[i] = (pw1_arr[i - 1] * P1) % M1;
        pw2_arr[i] = (pw2_arr[i - 1] * P2) % M2;
    }
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    int A, B;
    cin >> A >> B;

    vector<int> L(N + 1, 0), R(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> L[i] >> R[i];
    }

    vector<int> parent(N + 1, 0), depth(N + 1, 0), char_from_parent(N + 1, 0);
    vector<long long> h1(N + 1, 0), h2(N + 1, 0);
    vector<pair<long long, long long>> node_hashes;

    queue<int> q;
    q.push(1);
    node_hashes.push_back({0, 0});

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (L[u]) {
            int v = L[u];
            parent[v] = u;
            depth[v] = depth[u] + 1;
            char_from_parent[v] = 1;
            h1[v] = (h1[u] * P1 + 1) % M1;
            h2[v] = (h2[u] * P2 + 1) % M2;
            node_hashes.push_back({h1[v], h2[v]});
            q.push(v);
        }
        if (R[u]) {
            int v = R[u];
            parent[v] = u;
            depth[v] = depth[u] + 1;
            char_from_parent[v] = 2;
            h1[v] = (h1[u] * P1 + 2) % M1;
            h2[v] = (h2[u] * P2 + 2) % M2;
            node_hashes.push_back({h1[v], h2[v]});
            q.push(v);
        }
    }

    sort(node_hashes.begin(), node_hashes.end());

    if (depth[A] % 2 != depth[B] % 2) {
        cout << "ERROR\n";
        return;
    }

    vector<int> pathA_nodes;
    int currA = A;
    while (currA != 0) {
        pathA_nodes.push_back(currA);
        currA = parent[currA];
    }
    reverse(pathA_nodes.begin(), pathA_nodes.end());

    vector<int> pathB_nodes;
    int currB = B;
    while (currB != 0) {
        pathB_nodes.push_back(currB);
        currB = parent[currB];
    }
    reverse(pathB_nodes.begin(), pathB_nodes.end());

    int lca_depth = 0;
    while (lca_depth < pathA_nodes.size() && lca_depth < pathB_nodes.size() && 
           pathA_nodes[lca_depth] == pathB_nodes[lca_depth]) {
        lca_depth++;
    }
    lca_depth--;

    int d_B = pathB_nodes.size() - 1;
    vector<int> B_str;
    for (int i = 1; i <= d_B; ++i) {
        B_str.push_back(char_from_parent[pathB_nodes[i]]);
    }

    vector<long long> prefB1(d_B + 1, 0), prefB2(d_B + 1, 0);
    for (int i = 0; i < d_B; ++i) {
        prefB1[i + 1] = (prefB1[i] * P1 + B_str[i]) % M1;
        prefB2[i + 1] = (prefB2[i] * P2 + B_str[i]) % M2;
    }

    auto get_hash = [&](int l, int r) -> pair<long long, long long> {
        if (l > r) return {0, 0};
        long long res1 = (prefB1[r + 1] - prefB1[l] * pw1_arr[r - l + 1]) % M1;
        if (res1 < 0) res1 += M1;
        long long res2 = (prefB2[r + 1] - prefB2[l] * pw2_arr[r - l + 1]) % M2;
        if (res2 < 0) res2 += M2;
        return {res1, res2};
    };

    auto check_exists = [&](int node, int l, int r) -> bool {
        if (l > r) return true;
        pair<long long, long long> sub_h = get_hash(l, r);
        int len = r - l + 1;
        long long th1 = (h1[node] * pw1_arr[len] + sub_h.first) % M1;
        long long th2 = (h2[node] * pw2_arr[len] + sub_h.second) % M2;
        return binary_search(node_hashes.begin(), node_hashes.end(), make_pair(th1, th2));
    };

    int min_cost = 1e9, best_u = -1, best_S_len = -1;

    for (int i = 0; i <= lca_depth; ++i) {
        int V = pathB_nodes[i];
        int d_V = i;

        // Case 1
        int X1 = V;
        int d_X1 = d_V;
        int u1 = depth[A] - d_X1;
        if (u1 >= 0) {
            int L_X = depth[B] - d_X1;
            if (u1 <= L_X && (L_X + u1) % 2 == 0) {
                int k = (L_X + u1) / 2;
                int len = k - u1;
                bool valid = true;
                if (len > 0) {
                    if (get_hash(d_X1, d_X1 + len - 1) != get_hash(d_B - k, d_B - k + len - 1)) valid = false;
                }
                if (valid && k > 0) {
                    if (!check_exists(X1, d_B - k, d_B - 1)) valid = false;
                }
                if (valid) {
                    if (u1 + k < min_cost) {
                        min_cost = u1 + k;
                        best_u = u1; best_S_len = k;
                    }
                }
            }
        }

        // Case 2
        int Y = V;
        int d_Y = d_V;
        int u2 = (depth[A] + depth[B]) / 2 - d_Y;
        if (u2 >= 0) {
            int S_len = depth[B] - d_Y;
            if (u2 > S_len) {
                int d_X2 = depth[A] - u2;
                if (d_X2 >= 0) {
                    int X2 = pathA_nodes[d_X2];
                    bool valid = true;
                    if (S_len > 0) {
                        if (!check_exists(X2, d_Y, d_B - 1)) valid = false;
                    }
                    if (valid) {
                        if (u2 + S_len < min_cost) {
                            min_cost = u2 + S_len;
                            best_u = u2; best_S_len = S_len;
                        }
                    }
                }
            }
        }
    }

    if (min_cost > 1e8) {
        cout << "ERROR\n";
    } else {
        string ans = "";
        for (int i = 0; i < best_u; ++i) ans += 'B';
        for (int i = d_B - best_S_len; i < d_B; ++i) {
            ans += (B_str[i] == 1 ? 'L' : 'R');
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute_powers();
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}