#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, M;
vector<ll> A;
vector<ll> T;

void update(int idx, ll num) {
    for (int i = idx; i <= N; i += (i & -i)) {
        T[i] += num;
    }
}

ll quary(int idx) {
    ll result = 0;

    for (int i = idx; i > 0; i -= (i & -i)) {
        result += T[i];
    }

    return result;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // build
    T.resize(N * 4 + 1);
    for (int i = 1; i <= N; ++i) {
        update(i, A[i] - A[i - 1]);
    }

    cin >> M;

    while (M--) {
        int q;
        cin >> q;
        if (q == 1) {
            int i, j, k;
            cin >> i >> j >> k;

            update(i, k);
            update(j + 1, -k);
        } else {
            int x;
            cin >> x;

            cout << quary(x) << '\n';
        }
    }
}
