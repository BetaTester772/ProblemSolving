#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a: A) {
        cin >> a;
    }
    sort(A.begin(), A.end(), greater<>());

    int result = 0;
    for (int j = 0; j < N; ++j) {
        result = max(A[j] * (j + 1), result);
    }
    cout << result;
}
