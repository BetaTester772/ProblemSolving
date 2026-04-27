#include <bits/stdc++.h>

using namespace std;

// 크루스칼

int find(int v, vector<int> &union_set) {
    if (union_set[v] != v) {
        union_set[v] = find(union_set[v], union_set); // 부모 업데이트
    }
    return union_set[v];
}

double get_distance(pair<double, double> &a, pair<double, double> &b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    int V;
    cin >> V;

    priority_queue<pair<double, pair<int, int> >, vector<pair<double, pair<int, int> > >, greater<> > pq;
    vector<int> union_set(V + 1);
    for (int i = 0; i < V + 1; ++i) {
        union_set[i] = i;
    }
    vector<pair<int, pair<double, double> > > A;
    for (int i = 1; i <= V; ++i) {
        double a, b;
        cin >> a >> b;
        A.push_back({i, {a, b}});
    }

    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            double dist = get_distance(A[i].second, A[j].second);
            pq.push({dist, {A[i].first, A[j].first}});
        }
    }

    double result = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        double w = top.first;
        int r_v1 = find(top.second.first, union_set);
        int r_v2 = find(top.second.second, union_set);

        if (r_v1 == r_v2) {
            continue;
        } else {
            union_set[r_v1] = r_v2;
            result += w;
        }
    }
    cout << fixed << setprecision(2) << result;
}
