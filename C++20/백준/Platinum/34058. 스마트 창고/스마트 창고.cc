#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int> > A;
vector<vector<int> > sum_table;
vector<vector<vector<int> > > V;
vector<vector<vector<int> > > dp;

int query_sum(int x1, int y1, int x2, int y2) {
    return sum_table[x2][y2] - sum_table[x1 - 1][y2] - sum_table[x2][y1 - 1] + sum_table[x1 - 1][y1 - 1];
}

void solve() {
    for (int c1 = 1; c1 <= M; ++c1) {
        for (int c2 = c1; c2 <= M; ++c2) {
            vector<int> B(N + 1, 0);
            for (int r = 1; r <= N; ++r) {
                B[r] = query_sum(r, c1, r, c2);
            }

            vector<int> left_max(N + 1, numeric_limits<int>::min());
            vector<int> right_max(N + 1, numeric_limits<int>::min());
            int cur = numeric_limits<int>::min();
            for (int r = 1; r <= N; ++r) {
                if (r == 1)
                    cur = B[r];
                else
                    cur = max(B[r], cur + B[r]);
                left_max[r] = cur;
            }

            cur = numeric_limits<int>::min();
            for (int r = N; r >= 1; --r) {
                if (r == N)
                    cur = B[r];
                else
                    cur = max(B[r], cur + B[r]);
                right_max[r] = cur;
            }

            for (int r = 1; r <= N; ++r) {
                V[r][c1][c2] = left_max[r] + right_max[r] - B[r];
            }
        }
    }

    for (int r = 1; r <= N; ++r) {
        for (int c1 = 1; c1 <= M; ++c1) {
            for (int c2 = M; c2 >= 1; --c2) {
                dp[r][c1][c2] = max({
                    (c1 > 1 ? dp[r][c1 - 1][c2] : numeric_limits<int>::min()),
                    (c2 < M ? dp[r][c1][c2 + 1] : numeric_limits<int>::min()),
                    V[r][c1][c2]
                });
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    A.assign(N, vector<int>(M));
    sum_table.assign(N + 1, vector<int>(M + 1, 0));
    V.assign(N + 2, vector<vector<int> >(M + 1, vector<int>(M + 1, 0)));
    dp.assign(N + 1, vector<vector<int> >(M + 2, vector<int>(M + 2, numeric_limits<int>::min())));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            sum_table[i][j] = A[i - 1][j - 1] + sum_table[i - 1][j] + sum_table[i][j - 1] - sum_table[i - 1][j - 1];

    solve();

    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= M; ++c) {
            cout << dp[r][c][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}
