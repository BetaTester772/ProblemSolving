#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels(N);
    for (int i = 0; i < N; ++i) {
        ll m, v;
        cin >> m >> v;
        jewels[i] = {m, v}; // {무게, 가격}
    }

    vector<int> bags(K);
    for (int i = 0; i < K; ++i) {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    ll result = 0;
    priority_queue<int> pq; // 가격
    int jewel_idx = 0;

    for (int i = 0; i < K; ++i) {
        while (jewel_idx < N && jewels[jewel_idx].first <= bags[i]) {
            pq.push(jewels[jewel_idx].second); // 가격을 힙에 추가
            jewel_idx++;
        }

        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
}