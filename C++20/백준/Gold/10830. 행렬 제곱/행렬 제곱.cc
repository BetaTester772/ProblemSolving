#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll> > matrixMultiply(vector<vector<ll> > &A, vector<vector<ll> > &B) {
    ll n = A.size();
    vector<vector<ll> > C(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k < n; ++k) {
                C[i][j] = (ll) (C[i][j] + ((ll) A[i][k] * B[k][j]) % 1000) % 1000;
            }
        }
    }
    return C;
}

void solve(vector<vector<ll> > A, ll n, vector<vector<ll> > &result) {
    while (n > 0) {
        if (n % 2 == 1) result = matrixMultiply(result, A); // n
        A = matrixMultiply(A, A); // a = a^2
        n /= 2;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, B;
    cin >> N >> B;

    vector<vector<ll> > A(N, vector<ll>(N, 0));

    for (auto &row: A) {
        for (auto &a: row) {
            cin >> a;
            a %= 1000;
        }
    }

    vector<vector<ll> > result(N, vector<ll>(N, 0));
    for (ll i = 0; i < N; ++i) {
        result[i][i] = 1;
    }

    solve(A, B, result);

    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            cout << result[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << "\n";
    }
}
