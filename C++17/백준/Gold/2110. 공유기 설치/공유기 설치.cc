#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int N, C;
    cin >> N >> C;
    vector<int> A;
    A.reserve(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    int first = 1, last = A[N - 1] - A[0], result = -1;
    while (first <= last) {
        int mid = (last + first) / 2;

        int cur = A[0], cnt = 1;
        for (int i = 1; i < N; ++i) {
            if (A[i] - cur >= mid) {
                cnt++;
                cur = A[i];
            }
        }

        if (cnt >= C) {
            first = mid + 1;
            if (mid > result)
                result = mid;
        } else {
            last = mid - 1;
        }
    }
    cout << result;
}
