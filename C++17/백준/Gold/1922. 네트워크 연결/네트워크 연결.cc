#include <bits/stdc++.h>

using namespace std;

//크루스칼

int find(int v, vector<int> &union_set) {
    if (union_set[v] != v) {
        union_set[v] = find(union_set[v], union_set);
    }
    return union_set[v];
}

int main() {
    int V, E;
    cin >> V >> E;

    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<> > pq;
    vector<int> union_set(V + 1);
    for (int i = 0; i < V + 1; ++i) {
        union_set[i] = i;
    }

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }

    int result = 0;
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        int w = top.first;
        int r_v1 = find(top.second.first, union_set);
        int r_v2 = find(top.second.second, union_set);

        if (r_v1 == r_v2) {
            continue;
        } else {
            union_set[r_v1] = r_v2;
            result += w;
        }
    }
    cout << result;
}
