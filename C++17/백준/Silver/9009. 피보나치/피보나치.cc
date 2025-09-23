#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> A(T);
    int max_n = -1;

    for (int &a: A) {
        cin >> a;
        max_n = max(a, max_n);
    }

    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    while (dp[dp.size() - 1] < max_n) {
        dp.push_back(dp[dp.size() - 2] + dp[dp.size() - 1]);
    }

    vector<int> result;

    for (int a: A) {
        int t = 0, i = dp.size() - 1;
        while (t < a) {
            if (dp[i] <= a - t) {
                t += dp[i];
                result.push_back(dp[i]);
            };
            i--;
        }
        reverse(result.begin(), result.end());
        for (int r: result) {
            cout << r << ' ';
        }
        result.clear();
        cout << '\n';
    }
}
