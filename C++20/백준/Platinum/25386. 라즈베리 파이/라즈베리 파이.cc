#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 N, M;
pair<i64, i64> arr[300000];

void do_input() {
    cin >> N >> M;
    for (i64 i=0; i<M; i++) cin >> arr[i].first;
    for (i64 i=0; i<M; i++) cin >> arr[i].second;
}

i64 do_full_case() {
    for (i64 i=0; i<N; i++) if (arr[i].first != arr[i].second) return -1;
    return 0;
}

i64 do_solve() {
    if (N == M) return do_full_case();

    sort(arr, arr+M, [](auto a, auto b) {
        return a.second < b.second;
    });
    for (i64 i=1; i<M; i++) {
        if (arr[i-1].second == arr[i].second) return -1;
    }

    i64 cnt = 0, p = -1;
    for (i64 i=1; i<M; i++) {
        if (arr[i-1].first > arr[i].first) cnt++, p = i;
    }

    if (cnt >= 2) return -1;
    if (cnt == 1) for (i64 i=p; i<M; i++) arr[i].first += N;

    if (arr[M-1].first - arr[0].first >= N) return -1;

    bool flag = false;
    for (i64 i=0; i<M; i++) if (arr[i].first < arr[i].second) flag = true;
    if (flag) for (i64 i=0; i<M; i++) arr[i].first += N;

    i64 res = 0;
    for (i64 i=0; i<M; i++) res += arr[i].first - arr[i].second;

    return res;
}

int main() {
    do_input();
    cout << do_solve() << '\n';
}