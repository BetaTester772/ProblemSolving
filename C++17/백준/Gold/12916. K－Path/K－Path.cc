#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > matrixMultiply(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size();
    vector<vector<int> > C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] = (int) (C[i][j] + ((long long) A[i][k] * B[k][j]) % 1000000007) % 1000000007;
            }
        }
    }
    return C;
}

void solve(vector<vector<int> > A, int n, vector<vector<int> > &result) {
    while (n > 0) {
        if (n % 2 == 1) result = matrixMultiply(result, A); // n
        A = matrixMultiply(A, A); // a = a^2
        n /= 2;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<vector<int> > A(N, vector<int>(N, 0));

    for (auto &row: A) {
        for (auto &a: row) {
            cin >> a;
        }
    }

    vector<vector<int> > result(N, vector<int>(N, 0)); // 항등행렬로
    for (int i = 0; i < N; ++i) {
        result[i][i] = 1;
    }
    solve(A, K, result);

    int count = 0;
    for (auto &row: result) {
        for (auto &a: row)
            count = (count + a) % 1000000007;
    }
    cout << count;
}
