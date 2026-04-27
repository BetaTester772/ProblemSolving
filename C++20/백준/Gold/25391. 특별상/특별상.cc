#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 N, M, K;
pair<i64, i64> arr[200001];

void do_input() {
    cin >> N >> M >> K;
    for (i64 i=0; i<N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
}

i64 do_solve() {
    sort(arr, arr+N, [](auto a, auto b) {
        return a.second > b.second;
    });
    sort(arr+K, arr+N, [](auto a, auto b) {
        return a.first > b.first;
    });
    i64 S = 0;
    for (i64 i=0; i<M+K; i++) S+=arr[i].first;
    return S;
}

int main() {
    do_input();
    cout << do_solve() << '\n';
    return 0;
}