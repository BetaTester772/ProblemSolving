#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int K;
        cin >> K;
        vector<int> D(K);
        for (int &d: D) {
            cin >> d;
        }
        vector<vector<int> > T(K, vector<int>(K, 0));
        for (int i = 0; i < K - 1; ++i) {
            T[i][i + 1] = D[i] + D[i + 1];
        }

        for (int i = K - 1; i > -1; --i) {
            for (int j = i + 2; j < K; ++j) {
                int min_ = 1e9;
                for (int k = i; k < j; ++k) {
                    min_ = min(min_, T[i][k] + T[k + 1][j]);
                }
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += D[k];
                }
                T[i][j] = min_ + sum;
            }
        }

        // for (auto &row: T) {
        //     for (int &x: row) {
        //         cout << x << ' ';
        //     }
        //     cout << '\n';
        // }

        cout << T[0][K - 1] << '\n';
    }
}
